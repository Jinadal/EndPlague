#include <cstddef>
#include "PlayState.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "Game.h"


PlayState* PlayState::only_instance = NULL;
void PlayState::initState()
{
    type = IGameState::PLAY;
    render              = RenderIrrlicht::getInstance();
    fabric              = new FabricVillage();
    inputmanager        = InputManager::getInstance();
    spawnmanager        = SpawnManager::getInstance();
    iamanager           = IAManager::getInstance();
    bphysicmanager      = BPhysicManager::getInstance();
    shootmanager        = ShootManager::getInstance();
    cameramanager       = CameraManager::getInstance();
    rendermanager       = RenderManager::getInstance();
    storagemanager      = StorageManager::getInstance();
    gameresource        = GameResource::getInstance();
    if(!loaded)
    {
        loaded=true;
        fabric->loadLevel();
    }
}
void PlayState::update(float dt)
{
    InputManager::getInstance()->setCursorPosition(render->getCursorX(), render->getCursorY());
    GameResource::getInstance()->updateAll();
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);

    std::cout<<"PLAY"<<std::endl;
 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);
    
    if(IAManager::getInstance()->getPlayer()->getKill())
    {
        clear();
        Game::getInstance()->setState(IGameState::stateType::END);
    }
}

void PlayState::clear(){
    //delete inputmanager;
    delete spawnmanager;
    delete iamanager;
    delete bphysicmanager;
    delete shootmanager;
    delete cameramanager;
    delete rendermanager;
    delete gameresource; 
       
    delete fabric;
    //delete render;

    loaded=false;

}