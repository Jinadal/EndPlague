#include <stdlib.h>
#include <stdio.h>

#include "GameResource.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "MovementManager.h"
#include "InputFacade.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "SpawnManager.h"
#include "Nodo.h"
#include "IAManager.h"

#include "PhysicBullet.h"


#include "SoundSystem.h"


int main()
{
   GameResource*        gameresource        = GameResource::getInstance();
   RenderIrrlicht*      render              = RenderIrrlicht::getInstance();
   RenderManager*       rendermanager       = RenderManager::getInstance();
   MovementManager*     movementmanager     = MovementManager::getInstance();
   CollisionManager*    collisionmanager    = CollisionManager::getInstance();
   ShootManager*        shootmanager        = ShootManager::getInstance();
   LifeManager*         lifemanager         = LifeManager::getInstance();
   ProjectileManager*   projectilemanager   = ProjectileManager::getInstance();
   InputManager*        inputmanager        = InputManager::getInstance();
   CameraManager*       cameramanager       = CameraManager::getInstance();
   IAManager*           iamanager           = IAManager::getInstance();
   ItemManager*         itemmanager         = ItemManager::getInstance();
   StorageManager*      storagemanager      = StorageManager::getInstance();
   SpawnManager*        spawnmanager        = SpawnManager::getInstance();


    //ADDING A MAP 700 x 700 x 1
    GameObject* map = gameresource->createGameObject(0.f, 0.f, 0.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/SUELO.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/SUELO.bmp");//Path de bmp   

    //ADDING A PLAYER 1 x 1 x 2
    GameObject* player = gameresource->createGameObject(0.f, 0.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(player, (char*)"res/DOOMIE.obj");//Fachada de render y path de obj
    //player->getComponent<RenderComponent>()->setTexture((char*)"res/PLAYER.bmp");//Path de bmp
    movementmanager->createComponent(player);
    player->getComponent<MovementComponent>()->setvMax(7.f);
    inputmanager->createComponent(player);
    collisionmanager->createComponent(player, 1, 1, true); //Ancho, alto y si es solido
    shootmanager->createComponent(player, .2f, 1.f, PROJECTILE_1);//Cadencia y Tipo
    cameramanager->createComponent(player);
    storagemanager->createComponent(player);
    iamanager->setPlayer(player);

    

    //ADDING A SPAWN //EL MESH MIDE 4 x 4 x 4
    GameObject* spawn = gameresource->createGameObject(10.f, -10.f, -1.f, 0.f);
    rendermanager->createComponent(spawn, (char*)"res/SPAWN.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/SPAWN.bmp");//Path de bmp
    collisionmanager->createComponent(spawn, 4, 4, true); //Ancho, alto y si es solido
    spawnmanager->createComponent(spawn, 2.5f, ENEMY_1);
    lifemanager->createComponent(spawn, 400.f);


    //Adding an ITEM1 //EL MESH MIDE .5 x .5 x .5
    GameObject* item1 = gameresource->createGameObject(0.f, 3.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item1, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    collisionmanager->createComponent(item1, .5, .5, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item1, ITEM_CADENCE);
    
    
    //Adding an ITEM2
    GameObject* item2 = gameresource->createGameObject(0.f, 6.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item2, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    collisionmanager->createComponent(item2, .5, .5, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item2, ITEM_LIFE);
    

    //Adding an ITEM3
    GameObject* item3 = gameresource->createGameObject(0.f, 9.f, -1.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item3, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    collisionmanager->createComponent(item3, .5, .5, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item3, ITEM_THROWABLE);


    while(render->run())
    {


        inputmanager->setCursorPosition(render->getCursorX(), render->getCursorY());
        inputmanager->updateAll();
        spawnmanager->updateAll(render->getFrameDeltaTime());
        iamanager->updateAll();
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