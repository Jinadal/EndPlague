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
    rendermanager->createComponent(box, render, "res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture("res/red.bmp");//Path de bmp

    //Add Movement
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(1000.f);

    //Add Input
    InputComponent* in = new InputComponent(box);
    box->addComponent(in);

    //Add Collisions
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    
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
        rendermanager->updateAll();


        render->drawAll();
    }

    render->drop();

    
    
    collisionmanager->removeAll();
    delete collisionmanager;
    movementmanager->removeAll();
    delete movementmanager;
    rendermanager->removeAll();
    delete rendermanager;
    shootmanager->removeAll();
    delete shootmanager;
    lifemanager->removeAll();
    delete shootmanager;
    projectilemanager->removeAll();
    delete projectilemanager;



    delete interface;
    delete box;
    delete render;


    return 0;
}