#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "GameResource.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "MovementManager.h"
#include "InputFacade.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "SpawnManager.h"
#include "bullet/btBulletCollisionCommon.h"
#include "bullet/btBulletDynamicsCommon.h"
#include "Nodo.h"
#include "IAManager.h"





int main()
{
   GameResource*        gameresource        = GameResource::getInstance();
   RenderIrrlicht*      render              = RenderIrrlicht::getInstance();
   RenderManager*       rendermanager       = RenderManager::getInstance();
   MovementManager*     movementmanager     = MovementManager::getInstance();
   CollisionManager*    collisionmanager    = CollisionManager::getInstance();
   ShootManager*        shootmanager        = ShootManager::getInstance();
   LifeManager*         lifemanager         = LifeManager::getInstance();
   ProjectileManager*   projectilemanager   = ProjectileManager::getInstance();
   InputManager*        inputmanager        = InputManager::getInstance();
   CameraManager*       cameramanager       = CameraManager::getInstance();
   IAManager*           iamanager           = IAManager::getInstance();
   ItemManager*         itemmanager         = ItemManager::getInstance();
   StorageManager*      storagemanager      = StorageManager::getInstance();
   SpawnManager*        spawnmanager        = SpawnManager::getInstance();


    //ADDING A MAP
    GameObject* map = gameresource->createGameObject(0.f, 0.f, 20.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/Mapy.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp   

    //ADDING A PLAYER
    GameObject* player = gameresource->createGameObject(0.f, 200.f, -10.f, 180.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(player, (char*)"res/Playery.obj");//Fachada de render y path de obj
    player->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    movementmanager->createComponent(player);
    player->getComponent<MovementComponent>()->setvMax(700.f);
    inputmanager->createComponent(player);
    collisionmanager->createComponent(player, 25, 50, true); //Ancho, alto y si es solido
    shootmanager->createComponent(player, .2f, 115.f, PROJECTILE_1);//Cadencia y Tipo
    cameramanager->createComponent(player);
    storagemanager->createComponent(player);
    iamanager->setPlayer(player);
    

    //ADDING A SPAWN
    GameObject* spawn = gameresource->createGameObject(250.f, -200.f, -10.f, 0.f);
    rendermanager->createComponent(spawn, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    collisionmanager->createComponent(spawn, 200, 200, true); //Ancho, alto y si es solido
    spawnmanager->createComponent(spawn, 135.f, ENEMY_1);
    lifemanager->createComponent(spawn, 300.f);


    //Adding an ITEM1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item1, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item1, ITEM_CADENCE);
    
    /*
    //Adding an ITEM2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item2, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item2, ITEM_LIFE);
    */

    //ADDING A ENEMY
    GameObject* primero = gameresource->createGameObject(-200.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(primero, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture((char*) "res/red.bmp");//Path de bmp
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(200.f);
    collisionmanager->createComponent(primero, 55, 55, true); //Ancho, alto y si es solido
    iamanager->createComponent(primero);
    primero->getComponent<IAComponent>()->Initialice();
    lifemanager->createComponent(primero, 100.f);//Vida

    while(render->run())
    {

        inputmanager->updateAll();
        spawnmanager->updateAll(render->getFrameDeltaTime());
        iamanager->updateAll();
        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->updateAll();
        cameramanager->updateAll(render->getFrameDeltaTime());
        gameresource->updateAll();
        rendermanager->updateAll();


        render->drawAll();
    }


    delete gameresource;
    delete rendermanager;
    delete movementmanager;
    delete collisionmanager;
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