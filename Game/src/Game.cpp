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

   //ITEM MANAGER
   //STORAGE MANAGER


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
    item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp

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

    while(render->run())
    {   
        box->getComponent<InputComponent>()->pulseInput(interface);

        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->updateAll();
        gameresource->updateAll();
        rendermanager->updateAll();


        render->drawAll();
<<<<<<< HEAD

        t+=render->getFrameDeltaTime();
        if(t>10.f){
            t=0.f;
            GameObject* b = new GameObject(0.f, -200.f, -10.f, 0.f);

            //Add Render
            rendermanager->createComponent(b, render, "res/Bullety.obj");

          
            //Add Projectile
            projectilemanager->createComponent(b, 10.f);

            //Add Movement
            movementmanager->createComponent(b);
            b->getComponent<MovementComponent>()->setvY(100.f);

              //Add Collision
            collisionmanager->createComponent(b,50,50,true);


            bullets.push_back(b);
        }
=======
>>>>>>> 3465e45313c06c64fe28333155569bd09391c71f
    }

    render->drop();

    
    
    delete rendermanager;
    delete movementmanager;
    delete collisionmanager;   
    delete shootmanager;    
    delete lifemanager;
    delete projectilemanager;
    delete inputmanager;

    delete gameresource;

    delete render;
    delete interface;
    


    return 0;
}