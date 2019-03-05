#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "InputManager.h"
#include "IAManager.h"
#include "SpawnManager.h"
#include "GameObject.h"
#include "GameManager.h"



void PlayState::initState()
{
    type = IGameState::PLAY;

    if(!loaded)
    {
        loaded=true;

        if(level>=fabrics.size())
            level = 0;

        fabrics[level]->loadLevel();

        GameManager::getInstance()->initAll();
    }
}


void PlayState::update(float dt)
{
    GameManager::getInstance()->updateAll(dt);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);
    
    if(IAManager::getInstance()->getPlayer() && IAManager::getInstance()->getPlayer()->getKill())
    {
        clear();
        Game::getInstance()->setState(IGameState::stateType::END);
    }else if(SpawnManager::getInstance()->getNumSpawns()<=0)
    {
        clear();
        if(level<fabrics.size())
        {
            initState();
        }else
        {
            level = 0;
            Game::getInstance()->setState(IGameState::stateType::END);
        }
    }
}

void PlayState::clear(){
    GameManager::getInstance()->clear();
    level++;
    loaded=false;

}