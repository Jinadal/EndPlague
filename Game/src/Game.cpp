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

    while(render->run())
    {
        box->getComponent<InputComponent>()->pulseInput(interface);

        movementmanager->updateAll(render->getFrameDeltaTime());
        rendermanager->updateAll();
        render->drawAll();

    }

    render->drop();


    return 0;
}
