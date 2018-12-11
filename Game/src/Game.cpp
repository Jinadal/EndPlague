#include <iostream>
#include <vector>

#include "GameResource.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "MovementManager.h"
#include "InputFacade.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "ProjectileFabric.h"
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
    
    rendermanager->createComponent(box, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(1000.f);
    inputmanager->createComponent(box);
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    lifemanager->createComponent(box, 40.f);//Vida
    shootmanager->createComponent(box, .2f, 115.f, PROJECTILE_1);//Cadencia y Tipo

    

    while(render->run())
    {
        if(box!=nullptr){
            box->getComponent<InputComponent>()->pulseInput(interface);
        }
        
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

    delete gameresource;

    delete render;
    delete interface;
    


    return 0;
}