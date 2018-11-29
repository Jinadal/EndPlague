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
    GameObject* map = new GameObject(0.f,0.f, 0.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(map, render, "res/Mapy.obj");
    map->getComponent<RenderComponent>()->setTexture("res/green.bmp");

    

    //ADDING A BOX
    GameObject* box = new GameObject(-200.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    //Add a Render
    rendermanager->createComponent(box, render, "res/Blocky.obj");
    box->getComponent<RenderComponent>()->setTexture("res/red.bmp");

    //Add an Input
    InputComponent* input = new InputComponent(box);
    box->addComponent(input);

    //Add a Movement
    movementmanager->createComponent(box);

    //Add Collisions
    collisionmanager -> createComponent(box,200,200,true);
    
    //Add Shoot
    ShootComponent* sc = new ShootComponent(box, 1.0f, 1);
    shootmanager->addComponent(sc);
    box->addComponent(sc);
 

    while(render->run())
    {
        box->getComponent<InputComponent>()->pulseInput(interface);
        box->getComponent<MovementComponent>()->setvMax(1000.f);
        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->update();
        rendermanager->updateAll();
        render->drawAll();

    }

    render->drop();

    
    
    collisionmanager->removecomponent(box->getComponent<CollisionComponent>()); // aqui peta por segment Sara, Atentemente yo mismo

    movementmanager->removecomponent(box->getComponent<MovementComponent>());

    rendermanager->removecomponent(box->getComponent<RenderComponent>());


    delete input;

    delete collisionmanager;
    delete interface;
   
    delete rendermanager;
    delete movementmanager;

    delete box;

    delete render;
    return 0;
}
