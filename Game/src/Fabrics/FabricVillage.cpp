#include "FabricVillage.h"


void FabricVillage::loadLevel()
{


     //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, (char*)"res/TERRAIN.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, 700.f, 700.f, .5f, 100000.f, 1);
    //BPhysicManager::getInstance()->createComponent(map, (char*)"res/TERRAIN.obj");


    //ADDING A PLAYER 1 x 1 x 2
    GameObject* player = GameResource::getInstance()->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(7.f);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, .5f, 2.f, PROJECTILE_1);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, 100.f);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);

    

    //ADDING A SPAWN //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn = GameResource::getInstance()->createGameObject(10.f, -10.f, -1.f, 0.f);
    RenderManager::getInstance()->createComponent(spawn, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    //SpawnManager::getInstance()->createComponent(spawn, 2.5f, ENEMY_1);
    LifeManager::getInstance()->createComponent(spawn, 400.f);
    BPhysicManager::getInstance()->createComponent(spawn, 2.f, 2.f, 2.f, 1000000.f, 1);

    /*
    //Adding an ITEM1 //EL MESH MIDE .5 x .5 x .5
    GameObject* item1 = GameResource::getInstance()->createGameObject(0.f, 3.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item1, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item1, .5f, .5f, .5f, 1.f, 1);
    itemmanager->createComponent(item1, ITEM_CADENCE);
    
    
    //Adding an ITEM2
    GameObject* item2 = GameResource::getInstance()->createGameObject(0.f, 6.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item2, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item2, .5f, .5f, .5f, 1.f, 1);
    itemmanager->createComponent(item2, ITEM_LIFE);
    

    //Adding an ITEM3
    GameObject* item3 = GameResource::getInstance()->createGameObject(0.f, 9.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(item3, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    BPhysicManager::getInstance()->createComponent(item3, .5f, .5f, .5f, 1.f, 1);    
    itemmanager->createComponent(item3, ITEM_THROWABLE);
    */



}