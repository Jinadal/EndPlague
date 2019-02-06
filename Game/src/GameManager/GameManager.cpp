#include "GameManager.h"

//---------------------------------
//        INCLUDE AL DE MANAGERS
//---------------------------------
#include "BPhysicManager.h"
#include "BucketManager.h"
#include "CameraManager.h"
#include "DropperManager.h"
#include "IAManager.h"
#include "InputManager.h"
#include "ItemManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "RenderManager.h"
#include "ScoreManager.h"
#include "ShootManager.h"
#include "SpawnManager.h"
#include "StorageManager.h"
#include "WellManager.h"
#include "WoodManager.h"

#include "GameResource.h"
#include "RenderIrrlicht.h"


GameManager* GameManager::only_instance = nullptr;

void GameManager::initAll()
{
    GameResource::getInstance();

    BPhysicManager::getInstance();
    BucketManager::getInstance();
    CameraManager::getInstance();
    DropperManager::getInstance();
    IAManager::getInstance();
    InputManager::getInstance();
    ItemManager::getInstance();
    LifeManager::getInstance();
    ProjectileManager::getInstance();
    RenderManager::getInstance();
    ScoreManager::getInstance();
    ShootManager::getInstance();
    SpawnManager::getInstance();
    StorageManager::getInstance();
    WellManager::getInstance();
    WoodManager::getInstance();
}

void GameManager::deleteAll()
{
    delete GameResource::getInstance();

    delete BPhysicManager::getInstance();
    delete BucketManager::getInstance();
    delete CameraManager::getInstance();
    delete DropperManager::getInstance();
    delete IAManager::getInstance();
    delete InputManager::getInstance();
    delete ItemManager::getInstance();
    delete LifeManager::getInstance();
    delete ProjectileManager::getInstance();
    delete RenderManager::getInstance();
    delete ScoreManager::getInstance();
    delete ShootManager::getInstance();
    delete SpawnManager::getInstance();
    delete StorageManager::getInstance();
    delete WellManager::getInstance();
    delete WoodManager::getInstance();

}

void GameManager::updateAll(float dt)
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


    //USELESS
    //BucketManager::getInstance()->updateAll(dt);
    //DropperManager::getInstance()->updateAll(dt);
    //ItemManager::getInstance()->updateAll(dt);
    //ProjectileManager::getInstance()->updateAll(dt);
    //ScoreManager::getInstance()->updateAll(dt);
    //StorageManager::getInstance()->updateAll(dt);
    //WellManager::getInstance()->updateAll(dt);
}