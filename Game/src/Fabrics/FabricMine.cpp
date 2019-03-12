#include "FabricMine.h"
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
#include <iostream>


namespace mine{
std::vector<Position> loc_wells{
    {0.f, 7.f, 0.f, true},
};
std::vector<Position> loc_spawns{
    {0.f, -10.f, 0.f, false},
};

}



void FabricMine::loadLevel()
{


     //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, (char*)"res/MiniMapa.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    //BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 0.f, 1);
    BPhysicManager::getInstance()->createComponent(map, (char*)"res/MiniMapa.bullet");



    //ADDING A PLAYER 1 x 1 x 2
    player = GameResource::getInstance()->createPlayer(0.f, 0.f, -2.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(gv::PLAYER_VELOCITY);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, gv::PLAYER_STRT_CADENCE, 2.f, (ProjectileType)gv::PLAYER_STRT_WEAPON, 2);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, gv::PLAYER_LIFE, 2, true);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    IAManager::getInstance()->init(0);
    
    
    for(size_t i = 0; i<mine::loc_wells.size(); i++)
        well(mine::loc_wells[i]._x, mine::loc_wells[i]._y, mine::loc_wells[i]._rz, mine::loc_wells[i].type);


    for(size_t i = 0; i<mine::loc_spawns.size(); i++)
        spawn(mine::loc_spawns[i]._x, mine::loc_spawns[i]._y, mine::loc_spawns[i]._rz, mine::loc_spawns[i].type);
    

    std::cout<<"MineLoaded!\n";

}



void FabricMine::spawn(float x, float y, float rz, bool type)
{
    GameObject* spawn = GameResource::getInstance()->createGameObject(x, y, -3.f, -rz);
    
    if(type){
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/CUARTEL.obj");
        spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_1);
    }else{
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/CASA.obj");
        spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_2);
    }
    WoodManager::getInstance()->createComponent(spawn, gv::SPAWN_LIFE);
    BPhysicManager::getInstance()->createComponent(spawn, 2.f, 2.f, 2.f, 0.f, 0);
   
}

void FabricMine::well(float x, float y, float rz, bool type)
{
    GameObject* well = GameResource::getInstance()->createGameObject(x, y, -2.f, rz);
    RenderManager::getInstance()->createComponent(well, (char*)"res/WELL.obj");//Fachada de render y path de obj
    well->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");//Path de bmp
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, .5f, .5f, .5f, 0.f, 1);
    
}