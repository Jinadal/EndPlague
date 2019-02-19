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




std::vector<Position> loc_wells{
    {13.f, 1.7f, 0.f, true},
    {19.3f, 29.8f, 0.f, true},
    {-3.6f, -27.5f, 0.f, true},
    {-17.5f, -44.5f, 0.f, true},
    {-19.5f, -18.5f, 0.f, true},
    {31.2f, -20.7f, 0.f, true},
    {29.8f, -37.5f, 0.f, true},
    {45.8f, -7.5f, 0.f, true},
    {39.1f, 17.3f, 0.f, true},
    {26.9f, 33.4f, 0.f, true},
    {46.7f, 34.3f, 0.f, true},
    {37.9f, 46.4f, 0.f, true},
};
std::vector<Position> loc_spawns{
    {-24.7f, -46.1f, 0.f, false},
    {-1.1f, -45.7f, 90.f, true},
    {45.8f, -46.0f, 270.f, true},
    {14.9f, -39.0f, 180.f, false},
    {-10.5f, -34.7f, 0.f, true},
    {14.8f, -31.4f, 0.f, true},
    {31.3f, -26.f, 270.f, true},
    {-32.f, -22.6f, 270.f, true},
    {-24.f, -14.2f, 180.f, false},
    {-17.6f, -14.f, 90.f, true},
    {15.1f, -13.7f, 180.f, true},
    {45.7f, -14.2f, 270.f, true},
    {-0.9f, -5.6f, 270.f, true},
    {8.2f, -4.6f, 0.f, true},
    {27.6f, -5.7f, 90.f, true},
    {-45.6f, 4.f, 90.f, true},
    {-0.4f, 8.4f, 270.f, false},
    {19.7f, 16.f, 270.f, false},
    {27.9f, 16.7f, 90.f, true},
    {28.2f, 23.8f, 0.f, true},
    {38.f, 23.5f, 90.f, true},
    {-4.7f, 30.7f, 270.f, true},
    {-32.f, 45.5f, 180.f, true},
    {-24.f, 45.f, 180.f, false},
    {20.3f, 44.6f, 270.f, true},
    {27.6f, 45.6f, 180.f, true},
    {45.6f, 45.9f, 180.f, true}
};


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
    ShootManager::getInstance()->createComponent(player, .5f, 2.f, PPEAK, 2);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, 1000.f, 2, false);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    


    for(size_t i = 0; i<loc_wells.size(); i++)
        well(loc_wells[i]._x, loc_wells[i]._y, loc_wells[i]._rz, loc_wells[i].type);


    for(size_t i = 0; i<loc_spawns.size(); i++)
        spawn(loc_spawns[i]._x, loc_spawns[i]._y, loc_spawns[i]._rz, loc_spawns[i].type);
    
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
   
}

void FabricVillage::well(float x, float y, float rz, bool type)
{
    GameObject* well = GameResource::getInstance()->createGameObject(x, y, -1.f, rz);
    RenderManager::getInstance()->createComponent(well, (char*)"res/WELL.obj");//Fachada de render y path de obj
    well->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");//Path de bmp
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, .5f, .5f, .5f, 0.f, 1);
    
}
