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


using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


int main()
{
   InputFacade*     interface       = new InputFacade();
   RenderIrrlicht*  render          = new RenderIrrlicht(interface);
   RenderManager*   rendermanager   = new RenderManager();
   MovementManager* movementmanager = new MovementManager();
   CollisionManager* collisionmanager = new CollisionManager();

     //ADDING A BOX
    GameObject* box1 = new GameObject(200.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    
    //Add a Render

    rendermanager->createComponent(box1, render, "res/Blocky.obj");
    box1->getComponent<RenderComponent>()->setTexture("res/green.bmp");
 


    //Add Collisions
    collisionmanager -> createComponent(box1,200,200,true);









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
    

 

    while(render->run())
    {
        box->getComponent<InputComponent>()->pulseInput(interface);

        movementmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->update();
        rendermanager->updateAll();
        render->drawAll();

    }

    render->drop();

    
    
    //collisionmanager->removecomponent(box->getComponent<CollisionComponent>()); // aqui peta por segment Sara, Atentemente yo mismo
    collisionmanager->removecomponent(box1->getComponent<CollisionComponent>());

    movementmanager->removecomponent(box->getComponent<MovementComponent>());

    rendermanager->removecomponent(box->getComponent<RenderComponent>());
    rendermanager->removecomponent(box1->getComponent<RenderComponent>());


    delete input;

    delete collisionmanager;
    delete interface;
   
    delete rendermanager;
    delete movementmanager;

    delete box;
    delete box1;

    delete render;
    return 0;
}
