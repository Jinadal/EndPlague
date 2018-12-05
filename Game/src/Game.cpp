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


    //ADDING A BOX
    GameObject* box = gameresource->createGameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    rendermanager->createComponent(box, render, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(1000.f);
    inputmanager->createComponent(box);
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    lifemanager->createComponent(box, 400.f);//Vida
    shootmanager->createComponent(box, 1.f, 1);//Cadencia y Tipo

    


    float elapsedTime = 10.f;
    while(render->run())
    {
        //if(box!=nullptr){
        //    box->getComponent<InputComponent>()->pulseInput(interface);
        //}
        std::cout<<"Vuelta: ";
        movementmanager->updateAll(render->getFrameDeltaTime());
        std::cout<<"1";
        shootmanager->updateAll(render->getFrameDeltaTime());
        std::cout<<"2";
        collisionmanager->updateAll();
        std::cout<<"3";
        gameresource->updateAll();
        std::cout<<"4";
        rendermanager->updateAll();
        std::cout<<"5";

        
        elapsedTime += render->getFrameDeltaTime();
        if(elapsedTime>5.f){
            elapsedTime=0.f;
            GameObject* b = gameresource->createGameObject(0.f, -200.f, 0.f, 0.f);
            movementmanager->createComponent(b);
            b->getComponent<MovementComponent>()->setvMax(200.f);
            b->getComponent<MovementComponent>()->setvY(1);
            rendermanager->createComponent(b, render, (char*)"res/Bullety.obj");
            collisionmanager->createComponent(b, 30.f, 30.f, true);
            projectilemanager->createComponent(b, 10.f);
        }
        std::cout<<"6";
        render->drawAll();
        std::cout<<"7\n";
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