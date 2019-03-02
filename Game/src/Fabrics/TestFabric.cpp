#include "TestFabric.h"
#include "InputManager.h"
#include "ItemManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "StorageManager.h"
#include "GameResource.h"
#include "BucketManager.h"
#include "WellManager.h"
#include "WoodManager.h"
#include "BPhysicComponent.h"
#include "LifeManager.h"
#include "GameValues.h"


void TestFabric::loadLevel()
{


     //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, (char*)"res/SUELO.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 0.f, 1);



    //ADDING A PLAYER 1 x 1 x 2
    GameObject* player = GameResource::getInstance()->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(gv::PLAYER_VELOCITY);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, gv::PLAYER_STRT_CADENCE, 2.f, (ProjectileType)gv::PLAYER_STRT_WEAPON);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, gv::PLAYER_LIFE, 2, true);
    BucketManager::getInstance()->createComponent(player);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    
    
    //ADDING A SPAWN //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn = GameResource::getInstance()->createGameObject(0.f, -10.f, -1.f, 0.f);
    RenderManager::getInstance()->createComponent(spawn, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    BPhysicManager::getInstance()->createComponent(spawn, 2.f, 2.f, 2.f, 0.f, 1);
    WoodManager::getInstance()->createComponent(spawn, gv::SPAWN_LIFE);


    //ADDING A WELL //EL MESH MIDE 4 x 4 x 4
    GameObject* well = GameResource::getInstance()->createGameObject(0.f, 10.f, -1.f, 0.f);
    RenderManager::getInstance()->createComponent(well, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    //well->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    BPhysicManager::getInstance()->createComponent(well, 2.f, 2.f, 2.f, 0.f, 1);
    WellManager::getInstance()->createComponent(well);



}