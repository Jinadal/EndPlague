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
#include "CameraManager.h"
#include "bullet/btBulletCollisionCommon.h"
#include "bullet/btBulletDynamicsCommon.h"
#include "Nodo.h"
#include "IAManager.h"



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
   CameraManager*       cameramanager       = CameraManager::getInstance();

   IAManager*        iamanager        = IAManager::getInstance();


   //ITEM MANAGER
   //STORAGE MANAGER


    //ADDING A BOX
    GameObject* box = gameresource->createGameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    GameObject* primero = gameresource->createGameObject(200.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    
    //Add a Render
    rendermanager->createComponent(box, render, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmpç

    //Add a Render for Item 1
    rendermanager->createComponent(item1, render, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp

    //Add a Render for Item 2
    rendermanager->createComponent(item2, render, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp

    //Add a Render to primero
    rendermanager->createComponent(primero, render, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture((char*) "res/red.bmp");//Path de bmp


    //Add Movement
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(1000.f);

     //Add Movement to primero
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(50.f);

    //Add Input
    inputmanager->createComponent(box);

    //Add Collisions
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(primero, 100, 100, true); //Ancho, alto y si es solido

    //Add IA

    iamanager->createComponent(primero);

    primero->getComponent<IAComponent>()->Initialice();
    
    //Add Life
    lifemanager->createComponent(box, 40.f);//Vida

    //Add Shoot
    shootmanager->createComponent(box, 1.f, 1);//Cadencia y Tipo

    //Add Camera
    std::cout<<"Creando Camara\n";
    cameramanager->createComponent(box);
    std::cout<<"Camara Creada\n";

    GameObject* map = gameresource->createGameObject(0.f, 0.f, 20.f, 0.f);
    rendermanager->createComponent(map, render, (char*)"res/Mapy.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp    


    while(render->run())
    {   
        //std::cout<<"Uptate Input: \n";
        box->getComponent<InputComponent>()->pulseInput(interface);
        //std::cout<<"Uptate Movemnet: \n";
        movementmanager->updateAll(render->getFrameDeltaTime());
        //std::cout<<"Uptate Shoot: \n";
        shootmanager->updateAll(render->getFrameDeltaTime());
        iamanager->updateAll();
        
        collisionmanager->updateAll();

        gameresource->updateAll();
        //std::cout<<"Uptate Render: \n";
        cameramanager->updateAll(render->getFrameDeltaTime());

        rendermanager->updateAll();
        //std::cout<<"Todo OK\n";

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

    delete gameresource;

    delete render;
    delete interface;
    


    return 0;
}