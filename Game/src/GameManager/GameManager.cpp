#include "GameManager.h"

void GameManager::update(float dt)
{
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);
    GameResource::getInstance()->updateAll();
}

GameManager::~GameManager()
{
    delete inputmanager;
    delete spawnmanager;
    delete iamanager;
    delete bphysicmanager;
    delete shootmanager;
    delete cameramanager;
    delete rendermanager;
    delete gameresource; 
}