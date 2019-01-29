#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "LifeComponent.h"
#include "InputManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "RenderIrrlicht.h"
#include "GameResource.h"
#include "StorageManager.h"
#include "WoodManager.h"
#include "LifeManager.h"
#include "FabricVillage.h"
#include "TestFabric.h"
#include "ScoreManager.h"
#include "GameObject.h"


PlayState* PlayState::only_instance = NULL;

void PlayState::initState()
{
    type = IGameState::PLAY;
    switch (level)
    {
        case LEVEL_TEST:
            fabric = new TestFabric();
            break;
        case LEVEL_VILLAGE:
            fabric = new FabricVillage();
            break;
        default:
            fabric = new FabricVillage();
            break;
    }

    if(!loaded)
    {
        loaded=true;
        fabric->loadLevel();
    }
}


void PlayState::update(float dt)
{
    InputManager::getInstance()->setCursorPosition(RenderIrrlicht::getInstance()->getCursorX(), RenderIrrlicht::getInstance()->getCursorY());
    GameResource::getInstance()->updateAll();
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    WoodManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    LifeManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);
    
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
    delete SpawnManager::getInstance();
    delete IAManager::getInstance();
    delete BPhysicManager::getInstance();
    delete ShootManager::getInstance();
    delete CameraManager::getInstance();
    delete RenderManager::getInstance();
    delete GameResource::getInstance();




    delete fabric;

    loaded=false;

}