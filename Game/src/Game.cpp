#include <iostream>
#include "GameObject.h"
#include "RenderManager.h"
#include "RenderComponent.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"
#include "InputComponent.h"
#include "MovementManager.h"
#include "MovementComponent.h"
#include "InputFacade.h"
#include "ShootManager.h"
#include "ShootComponent.h"
#include "LifeManager.h"
#include "LifeComponent.h"
#include "ProjectileManager.h"


using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


int main()
{
   InputFacade*         interface           = new InputFacade();
   RenderIrrlicht*      render              = new RenderIrrlicht(interface);
   RenderManager*       rendermanager       = RenderManager::getInstance();
   MovementManager*     movementmanager     = MovementManager::getInstance();
   CollisionManager*    collisionmanager    = CollisionManager::getInstance();
   ShootManager*        shootmanager        = ShootManager::getInstance();
   LifeManager*         lifemanager         = LifeManager::getInstance();
   ProjectileManager*   projectilemanager   = ProjectileManager::getInstance();    

    //ADDING A BOX
    GameObject* box = new GameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    //Add a Render
    rendermanager->createComponent(box, render, "res/Blocky.obj");
    box->getComponent<RenderComponent>()->setTexture("res/red.bmp");

    //Add Collisions
    collisionmanager->createComponent(box,200,200,true);
    
    //Add Life
    lifemanager->createComponent(box, 50.f);


    std::vector<GameObject*> bullets;
    float t = 10.f;
    while(render->run())
    {
        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->update();
        rendermanager->updateAll();


        render->drawAll();

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
    }

    render->drop();

    
    
    collisionmanager->removecomponent(box->getComponent<CollisionComponent>());
    movementmanager->removecomponent(box->getComponent<MovementComponent>());
    rendermanager->removecomponent(box->getComponent<RenderComponent>());


    delete collisionmanager;
    delete interface;
   
    delete rendermanager;
    delete movementmanager;

    delete box;

    delete render;
    return 0;
}