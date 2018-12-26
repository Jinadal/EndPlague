#include <stdlib.h>
#include <stdio.h>
#include "GameResource.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"

#include "PhysicBullet.h"

bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2)
{
    std::cout<<"Colision\n";

    std::cout<<obj1->getCollisionObject()->getUserPointer()<<std::endl;
    std::cout<<obj2->getCollisionObject()->getUserPointer()<<std::endl;

    return false;
}


int main()
{
    GameResource*           gameresource        = GameResource::getInstance();
    RenderIrrlicht*         render              = RenderIrrlicht::getInstance();
    RenderManager*          rendermanager       = RenderManager::getInstance();
    ShootManager*           shootmanager        = ShootManager::getInstance();
    LifeManager*            lifemanager         = LifeManager::getInstance();
    ProjectileManager*      projectilemanager   = ProjectileManager::getInstance();
    InputManager*           inputmanager        = InputManager::getInstance();
    CameraManager*          cameramanager       = CameraManager::getInstance();
    IAManager*              iamanager           = IAManager::getInstance();
    ItemManager*            itemmanager         = ItemManager::getInstance();
    StorageManager*         storagemanager      = StorageManager::getInstance();
    SpawnManager*           spawnmanager        = SpawnManager::getInstance();
    BPhysicManager*         bphysicmanager      = BPhysicManager::getInstance();
    PhysicBullet*           physicbullet        = PhysicBullet::getInstance();
    
    gContactAddedCallback = bphysicmanager->callbackFunc;

    //ADDING A MAP 700 x 700 x 1
    GameObject* map = gameresource->createGameObject(0.f, 0.f, 0.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/SUELO.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   
    bphysicmanager->createComponent(map, 700.f, 700.f, .5f, 100000.f, 1);

    //ADDING A PLAYER 1 x 1 x 2
    GameObject* player = gameresource->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    bphysicmanager->createComponent(player, .5f, .5f, 1.f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(7.f);
    inputmanager->createComponent(player);
    shootmanager->createComponent(player, .5f, 2.f, PROJECTILE_1);//Cadencia y Tipo
    cameramanager->createComponent(player);
    storagemanager->createComponent(player);
    iamanager->setPlayer(player);

    

    //ADDING A SPAWN //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn = gameresource->createGameObject(10.f, -10.f, -1.f, 0.f);
    rendermanager->createComponent(spawn, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    spawnmanager->createComponent(spawn, 2.5f, ENEMY_1);
    lifemanager->createComponent(spawn, 400.f);
    bphysicmanager->createComponent(spawn, 2.f, 2.f, 2.f, 1000000.f, 1);


    //Adding an ITEM1 //EL MESH MIDE .5 x .5 x .5
    GameObject* item1 = gameresource->createGameObject(0.f, 3.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item1, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    bphysicmanager->createComponent(item1, .5f, .5f, .5f, 1.f, 1);
    itemmanager->createComponent(item1, ITEM_CADENCE);
    
    
    //Adding an ITEM2
    GameObject* item2 = gameresource->createGameObject(0.f, 6.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item2, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    bphysicmanager->createComponent(item2, .5f, .5f, .5f, 1.f, 1);
    itemmanager->createComponent(item2, ITEM_LIFE);
    

    //Adding an ITEM3
    GameObject* item3 = gameresource->createGameObject(0.f, 9.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item3, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    bphysicmanager->createComponent(item3, .5f, .5f, .5f, 1.f, 1);    
    itemmanager->createComponent(item3, ITEM_THROWABLE);


    while(render->run())
    {
        inputmanager->setCursorPosition(render->getCursorX(), render->getCursorY());
        physicbullet->iteration(render->getFrameDeltaTime());
        inputmanager->updateAll();
        spawnmanager->updateAll(render->getFrameDeltaTime());
        iamanager->updateAll();
        bphysicmanager->updateAll();
        shootmanager->updateAll(render->getFrameDeltaTime());
        cameramanager->updateAll(render->getFrameDeltaTime());
        gameresource->updateAll();
        rendermanager->updateAll();


        render->drawAll();
    }


    delete gameresource;
    delete rendermanager;
    delete shootmanager;
    delete lifemanager;
    delete projectilemanager;
    delete inputmanager;
    delete itemmanager;
    delete storagemanager;
    delete spawnmanager;
    delete render;

    return 0;
}