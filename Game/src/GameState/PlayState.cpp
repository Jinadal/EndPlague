#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "GameManager.h"
#include "IAManager.h"
#include "FabricVillage.h"
#include "GameObject.h"


PlayState* PlayState::only_instance = NULL;

void PlayState::initState()
{
    type = IGameState::PLAY;
    

    if(!loaded)
    {
        fabric = new FabricVillage();
        loaded=true;
        fabric->loadLevel();
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
    }
}

void PlayState::clear(){
    //delete inputmanager;
    delete GameManager::getInstance();

    delete fabric;
    loaded=false;
}