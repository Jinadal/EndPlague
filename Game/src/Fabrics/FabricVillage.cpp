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


void FabricVillage::loadLevel()
{


     //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, (char*)"res/SUELO.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 100000.f, 1);



    //ADDING A PLAYER 1 x 1 x 2
    player = GameResource::getInstance()->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(7.f);
    BucketManager::getInstance()->createComponent(player);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, .5f, 2.f, PROJECTILE_1);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, 100.f);
    player->getComponent<LifeComponent>()->setDecreases(true);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    

    //ADDING A WELL //EL MESH MIDE 1 x 1 x 2
    GameObject* well = GameResource::getInstance()->createGameObject(0.f, -3.f, -1.f, 90.f);
    RenderManager::getInstance()->createComponent(well, (char*)"res/WELL.obj");//Fachada de render y path de obj
    well->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");//Path de bmp
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, 1.f, 1.f, 2.f, 0.f, 1);

    

    //ADDING A SPAWN //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn = GameResource::getInstance()->createGameObject(10.f, -10.f, -1.f, 90.f);
    RenderManager::getInstance()->createComponent(spawn, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_1);
    WoodManager::getInstance()->createComponent(spawn, 400.f);
    BPhysicManager::getInstance()->createComponent(spawn, 2.f, 2.f, 2.f, 0.f, 1);




    //ADDING A SPAWN2 //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn2 = GameResource::getInstance()->createGameObject(-20.f, -10.f, -1.f, -90.f);
    RenderManager::getInstance()->createComponent(spawn2, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn2->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    SpawnManager::getInstance()->createComponent(spawn2, 4.f, ENEMY_2);
    //LifeManager::getInstance()->createComponent(spawn2, 10000.f);
    BPhysicManager::getInstance()->createComponent(spawn2, 2.f, 2.f, 2.f, 0.f, 1);
    std::cout<<"Rotacion:"<<spawn2->getRZ()<<"\n";

      //ADDING A SPAW3 //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn3 = GameResource::getInstance()->createGameObject(10.f, 0.f, -1.f, 180.f);
    RenderManager::getInstance()->createComponent(spawn3, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn3->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    SpawnManager::getInstance()->createComponent(spawn3, 4.f, ENEMY_1);
    LifeManager::getInstance()->createComponent(spawn3, 400.f);
    BPhysicManager::getInstance()->createComponent(spawn3, 2.f, 2.f, 2.f, 0.f, 1);


    //ADDING A SPAWN4 //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn4 = GameResource::getInstance()->createGameObject(-10.f, 0.f, -1.f, -135.f);
    RenderManager::getInstance()->createComponent(spawn4, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn4->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    SpawnManager::getInstance()->createComponent(spawn4, 4.f, ENEMY_2);
    LifeManager::getInstance()->createComponent(spawn4, 10000.f);
    BPhysicManager::getInstance()->createComponent(spawn4, 2.f, 2.f, 2.f, 0.f, 1);



    
    //Adding an ITEM1 //EL MESH MIDE .5 x .5 x .5
    GameObject* item1 = GameResource::getInstance()->createGameObject(0.f, 3.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item1, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item1, .5f, .5f, .5f, 1.f, 1);
    ItemManager::getInstance()->createComponent(item1, ITEM_1);
    
    
    //Adding an ITEM2
    GameObject* item2 = GameResource::getInstance()->createGameObject(0.f, 6.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item2, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item2, .5f, .5f, .5f, 1.f, 1);
    ItemManager::getInstance()->createComponent(item2, ITEM_2);
    

    //Adding an ITEM3
    GameObject* item3 = GameResource::getInstance()->createGameObject(0.f, 9.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item3, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item3, .5f, .5f, .5f, 1.f, 1);    
    ItemManager::getInstance()->createComponent(item3, ITEM_3);
    



}