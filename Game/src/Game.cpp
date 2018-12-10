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
    //inputmanager->createComponent(box);
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    lifemanager->createComponent(box, 40.f);//Vida
    shootmanager->createComponent(box, 1.f, 1);//Cadencia y Tipo

    

    std::vector<GameObject*> projectiles;
    float elapsedTime = 10.f;
    while(render->run())
    {
        //if(box!=nullptr){
        //    box->getComponent<InputComponent>()->pulseInput(interface);
        //}
        
        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->updateAll();
        rendermanager->updateAll();
        gameresource->updateAll();

        
        elapsedTime += render->getFrameDeltaTime();
        if(elapsedTime>5.f){
            elapsedTime=0.f;

            std::cout<<"Disparando.\n";
            projectiles.push_back(gameresource->createGameObject(0.f, -200.f, 0.f, 0.f));
            movementmanager->createComponent(projectiles[projectiles.size()-1]);
            projectiles[projectiles.size()-1]->getComponent<MovementComponent>()->setvMax(200.f);
            projectiles[projectiles.size()-1]->getComponent<MovementComponent>()->setvY(1);
            rendermanager->createComponent(projectiles[projectiles.size()-1], (char*)"res/Bullety.obj");
            collisionmanager->createComponent(projectiles[projectiles.size()-1], 30.f, 30.f, true);
            projectilemanager->createComponent(projectiles[projectiles.size()-1], 10.f);
        }
        
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