#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "InputManager.h"
#include "IAManager.h"
#include "RenderIrrlicht.h"
#include "FabricVillage.h"
#include "GameObject.h"

#include "GameManager.h"

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
    GameManager::getInstance()->clear();


    delete fabric;

    loaded=false;

}