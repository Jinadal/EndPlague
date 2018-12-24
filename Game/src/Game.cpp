#include <stdlib.h>
#include <stdio.h>
#include "GameResource.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "MovementManager.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"

#include "PhysicBullet.h"


int main()
{
    GameResource*           gameresource        = GameResource::getInstance();
    RenderIrrlicht*         render              = RenderIrrlicht::getInstance();
    RenderManager*          rendermanager       = RenderManager::getInstance();
    MovementManager*        movementmanager     = MovementManager::getInstance();
    CollisionManager*       collisionmanager    = CollisionManager::getInstance();
    ShootManager*           shootmanager        = ShootManager::getInstance();
    LifeManager*            lifemanager         = LifeManager::getInstance();
    ProjectileManager*      projectilemanager   = ProjectileManager::getInstance();
    InputManager*           inputmanager        = InputManager::getInstance();
    CameraManager*          cameramanager       = CameraManager::getInstance();
    IAManager*              iamanager           = IAManager::getInstance();
    ItemManager*            itemmanager         = ItemManager::getInstance();
    StorageManager*         storagemanager      = StorageManager::getInstance();
    SpawnManager*           spawnmanager        = SpawnManager::getInstance();
    BPhysicManager*         bphysicmanager      = BPhysicManager::getInstance();
    PhysicBullet*           physicbullet        = PhysicBullet::getInstance();


    //ADDING A MAP 700 x 700 x 1
    GameObject* map = gameresource->createGameObject(0.f, 0.f, 0.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/SUELO.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp

    //ADDING A PLAYER 1 x 1 x 2
    GameObject* player = gameresource->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    inputmanager->createComponent(player);
    cameramanager->createComponent(player);
    bphysicmanager->createComponent(player, 1.f, 1.f, 2.f, 1.f);
    //player->getComponent<BPhysicComponent>()->setVelocity(0, 5.f, 0);

    while(render->run())
    {
        inputmanager->setCursorPosition(render->getCursorX(), render->getCursorY());
        physicbullet->iteration(render->getFrameDeltaTime());
        inputmanager->updateAll();
        spawnmanager->updateAll(render->getFrameDeltaTime());
        iamanager->updateAll();
        bphysicmanager->updateAll();
        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        collisionmanager->updateAll();
        cameramanager->updateAll(render->getFrameDeltaTime());
        gameresource->updateAll();
        rendermanager->updateAll();


        render->drawAll();
    }


    delete gameresource;
    delete rendermanager;
    delete movementmanager;
    delete collisionmanager;
    delete shootmanager;
    delete lifemanager;
    delete projectilemanager;
    delete inputmanager;
    delete itemmanager;
    delete storagemanager;
    delete spawnmanager;
    delete render;

    return 0;
}