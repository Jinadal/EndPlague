#include "FabricVillage.h"
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
#include "LifeComponent.h"
#include "WellManager.h"
#include "WoodManager.h"
#include "BucketManager.h"
#include "BPhysicComponent.h"
#include "LifeManager.h"

BuildtRecord* BuildtRecord::only_instance = nullptr;

void FabricVillage::loadLevel()
{


    //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, (char*)"res/Mapa_2.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, (char*)"res/Mapa_2.bullet");
    //BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 100000.f, 1);


    //ADDING A PLAYER 1 x 1 x 2
    player = GameResource::getInstance()->createGameObject(-40.f, -46.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(7.f);
    BucketManager::getInstance()->createComponent(player);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, .5f, 2.f, PPEAK);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, 1000.f, true);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    


    for(size_t i = 0; i<wells.size(); i++)
        well(wells[i]._x, wells[i]._y, wells[i]._rz, wells[i].type);


    for(size_t i = 0; i<spawns.size(); i++)
        spawn(spawns[i]._x, spawns[i]._y, spawns[i]._rz, spawns[i].type);
    
}



void FabricVillage::spawn(float x, float y, float rz, bool type)
{
    GameObject* spawn = GameResource::getInstance()->createGameObject(x, y, -1.f, -rz);
    RenderManager::getInstance()->createComponent(spawn, (char*)"res/SPAWN.obj");
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");
    if(type){
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_1);
    }else{
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_2);
    }
    WoodManager::getInstance()->createComponent(spawn, 400.f);
    BPhysicManager::getInstance()->createComponent(spawn, 2.f, 2.f, 2.f, 0.f, 0);
    BuildtRecord::getInstance()->addSpawn(spawn);
}

void FabricVillage::well(float x, float y, float rz, bool type)
{
    GameObject* well = GameResource::getInstance()->createGameObject(x, y, -1.f, rz);
    RenderManager::getInstance()->createComponent(well, (char*)"res/WELL.obj");//Fachada de render y path de obj
    well->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");//Path de bmp
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, .5f, .5f, .5f, 0.f, 1);
    BuildtRecord::getInstance()->addPozo(well);
}
