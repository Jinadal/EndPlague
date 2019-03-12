#include "LevelLoader.h"
#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "RenderComponent.h"
#include "BPhysicManager.h"
#include "BPhysicComponent.h"
#include "SpawnManager.h"
#include "WoodManager.h"
#include "WellManager.h"
#include "InputManager.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "CameraManager.h"
#include "StorageManager.h"
#include "IAManager.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include "Village.h"

bool LevelLoader::hasNext()
{
    if(next<gv::LEVELS_LIST.size())
        return true;

    return false;
}


void LevelLoader::loadLevel()
{
    if(next>=gv::LEVELS_LIST.size())
        next = 0;
    
    /*
        Load LEVELS_LIST[next] here
    */    
    std::ifstream input_file(gv::LEVELS_LIST[next], std::ios::binary);
    Level level;
    input_file.read((char*)&level, sizeof(level));
    
    createMap(level.map_obj, level.map_bmp, level.map_bullet);
    createPlayer(level.pla_x,level.pla_y,level.pla_z);
    createSpawn(level.spawns[0]._x,level.spawns[0]._y,level.spawns[0]._rz,level.spawns[0]._t);
    createWell(level.wells[0]._x,level.wells[0]._y,level.wells[0]._rz);
   
    std::cout<<"Mapa: "<<level.map_obj<<" Text:"<<level.map_bmp<<" Bullet: "<<level.map_bullet<<"\n";

    next++;
}







void LevelLoader::createMap(char* obj, char* bmp, char* bullet)
{
    //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, obj);//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)bmp);//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, (char*)bullet);
    //BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 100000.f, 1);
}
void LevelLoader::createPlayer(float x, float y, float z)
{
    //ADDING A PLAYER 1 x 1 x 2
    player = GameResource::getInstance()->createPlayer(x, y, z, 0.f);//Creates a new GO on x, y, z, rz
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

}


void LevelLoader::createSpawn(float x, float y, float rz, bool type)
{
    GameObject* spawn = GameResource::getInstance()->createGameObject(x, y, -2.58f, -rz);
    
    if(type){
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/obj/CUARTEL.obj");
        spawn->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Cuartel_Color.bmp");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_1);
    }else{
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/obj/CASA.obj");
        spawn->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Casa_Color.bmp");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_2);
    }
    WoodManager::getInstance()->createComponent(spawn, gv::SPAWN_LIFE);
    BPhysicManager::getInstance()->createComponent(spawn, 3.5f, 3.5f, 3.f, 0.f, 0);
}


void LevelLoader::createWell(float x, float y, float rz)
{
    GameObject* well = GameResource::getInstance()->createGameObject(x, y, -1.f, rz);
    RenderManager::getInstance()->createComponent(well, (char*)"res/obj/POZO.obj");//Fachada de render y path de obj
    well->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Pozo_Color.bmp");//Path de bmp
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, .5f, .5f, .5f, 0.f, 1);   
}



void LevelLoader::writeFile()
{
    Level level = {
        "MapaOBJ",
        "MapaBMP",
        "Mapabull",

        0.f,
        1.f,
        2.f,

        {},
        {}
    };
    std::ofstream output_file("data/1.data", std::ios::binary);
    output_file.write((char*)&village, sizeof(village));
    output_file.close();
}