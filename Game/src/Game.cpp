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
   RenderManager*       rendermanager       = new RenderManager();
   MovementManager*     movementmanager     = new MovementManager();
   CollisionManager*    collisionmanager    = new CollisionManager();
   ShootManager*        shootmanager        = ShootManager::getInstance();
   


    //ADDING A BOX
    GameObject* box = new GameObject(-200.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    //Add a Render
    RenderComponent* bc = new RenderComponent(box, render, "res/Blocky.obj");//Creates a render Component
    bc->setTexture("res/red.bmp");
    rendermanager->addComponent(bc);
    box->addComponent(bc);

    //Add an Input
    InputComponent* input = new InputComponent(box);
    box->addComponent(input);

    //Add a Movement
    MovementComponent* move = new MovementComponent(box);
    movementmanager->addComponent(move);
    box->addComponent(move);

    //Add Collisions
    collisionmanager -> createComponent(box,200,200,true);
    
    //Add Shoot
    ShootComponent* sc = new ShootComponent(box, 1.0f, 1);
 

    while(render->run())
    {
        box->getComponent<InputComponent>()->pulseInput(interface);
        //box->getComponent<ShootComponent>()->shoot();

        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->update();
        rendermanager->updateAll();
        render->drawAll();

    }

    render->drop();
    
    //collisionmanager->removecomponent(box->getComponent<CollisionComponent>());
    //collisionmanager->removecomponent(box1->getComponent<CollisionComponent>());

   // movementmanager->removecomponent(box->getComponent<MovementComponent>());

//
    //delete collisionmanager;
    //delete interface;
    //delete render;
    //delete rendermanager;
    //delete movementmanager;
//

    return 0;
}
