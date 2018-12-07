#include <iostream>

#include "GameResource.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "MovementManager.h"
#include "InputFacade.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "bullet/btBulletCollisionCommon.h"
#include "bullet/btBulletDynamicsCommon.h"


using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


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
   ItemManager*         itemManager         = ItemManager::getInstance();
   StorageManager*      storageManager      = StorageManager::getInstance();



    //ADDING A BOX
    GameObject* box = gameresource->createGameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    //Add a Render
    rendermanager->createComponent(box, render, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmpç

    //Add a Render for Item 1
    rendermanager->createComponent(item1, render, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp

    //Add a Render for Item 2
    rendermanager->createComponent(item2, render, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp

    //Add Movement
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(1000.f);

    //Add Input
    inputmanager->createComponent(box);

    //Add Collisions
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    
    //Add Life
    lifemanager->createComponent(box, 100.f);//Vida

    //Add Shoot
    shootmanager->createComponent(box, 1.f, 1);//Cadencia y Tipo

    itemManager->createComponent(item1, ITEM_CADENCE);
    itemManager->createComponent(item2, ITEM_LIFE);

    storageManager->createComponent(box, 0);


    while(render->run())
    {   
        box->getComponent<InputComponent>()->pulseInput(interface);

        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->updateAll();
        gameresource->updateAll();
        rendermanager->updateAll();


        render->drawAll();
    }

    render->drop();



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