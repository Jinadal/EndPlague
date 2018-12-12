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
#include "bullet/btBulletCollisionCommon.h"
#include "bullet/btBulletDynamicsCommon.h"
#include "Nodo.h"
#include "IAManager.h"





int main()
{
   GameResource*        gameresource        = GameResource::getInstance();
   InputFacade*         interface           = InputFacade::getInstance();
   RenderIrrlicht*      render              = RenderIrrlicht::getInstance();
   RenderManager*       rendermanager       = RenderManager::getInstance();
   MovementManager*     movementmanager     = MovementManager::getInstance();
   CollisionManager*    collisionmanager    = CollisionManager::getInstance();
   ShootManager*        shootmanager        = ShootManager::getInstance();
   LifeManager*         lifemanager         = LifeManager::getInstance();
   ProjectileManager*   projectilemanager   = ProjectileManager::getInstance();
   InputManager*        inputmanager        = InputManager::getInstance();
   CameraManager*       cameramanager       = CameraManager::getInstance();

   IAManager*        iamanager        = IAManager::getInstance();

   ItemManager*         itemManager         = ItemManager::getInstance();
   StorageManager*      storageManager      = StorageManager::getInstance();



    //ADDING A BOX
    GameObject* box = gameresource->createGameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    GameObject* primero = gameresource->createGameObject(200.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    
    //Add a Render
    rendermanager->createComponent(box, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmpç

    //Add a Render for Item 1
    rendermanager->createComponent(item1, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp

    //Add a Render for Item 2
    rendermanager->createComponent(item2, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp

    //Add a Render to primero
    rendermanager->createComponent(primero, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture((char*) "res/red.bmp");//Path de bmp


    //Add Movement
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(700.f);

     //Add Movement to primero
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(200.f);

    _world = physic->initWorldPhysics();

    //Add Collisions
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(primero, 55, 55, true); //Ancho, alto y si es solido

    //Add IA
    iamanager->createComponent(primero,box);

    primero->getComponent<IAComponent>()->Initialice();
    
    //Add Life
    lifemanager->createComponent(primero, 100.f);//Vida
    shootmanager->createComponent(box, .2f, 115.f, PROJECTILE_1);//Cadencia y Tipo

    //Add Camera
    cameramanager->createComponent(box);


    GameObject* map = gameresource->createGameObject(0.f, 0.f, 20.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/Mapy.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp    
    itemManager->createComponent(item1, ITEM_CADENCE);
    itemManager->createComponent(item2, ITEM_LIFE);

    storageManager->createComponent(box, 0);


    while(render->run())
    {   
       

        box->getComponent<InputComponent>()->pulseInput(interface);
        iamanager->updateAll();


        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        
        collisionmanager->updateAll();
        cameramanager->updateAll(render->getFrameDeltaTime());
        gameresource->updateAll();
        rendermanager->updateAll();

        render->drawAll();





    }

 
void CreateStartScene()
{
    ClearObjects();
    CreateBox(btVector3(0.0f,0.0f,0.0f), vector3df(10.0f,0.5f,10.0f),0.0f);
    CreateBox(btVector3(.5,0.5,.5), vector3df(0.5f,0.5f,.5f),1.0f);



    delete rendermanager;
    delete movementmanager;
    delete collisionmanager;   
    delete shootmanager;    
    delete lifemanager;
    delete projectilemanager;
    delete inputmanager;
    delete itemManager;

    delete gameresource;

    delete render;
    delete interface;
    
    

    return 0;
}