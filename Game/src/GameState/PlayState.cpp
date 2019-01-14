#include <cstddef>
#include "PlayState.h"
#include <iostream>
#include <SFML/Window.hpp>

PlayState* PlayState::only_instance = NULL;

void PlayState::update(float dt)
{
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);
    GameResource::getInstance()->updateAll();

    std::cout<<"PLAY"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        std::cout<<"PLAY"<<std::endl;
    
    
}

void PlayState::clear(){
    delete inputmanager;
    delete spawnmanager;
    delete iamanager;
    delete bphysicmanager;
    delete shootmanager;
    delete cameramanager;
    delete rendermanager;
    delete gameresource; 
}