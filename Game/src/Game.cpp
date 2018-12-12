#include <stdlib.h>
#include <stdio.h>
#include <iostream>
<<<<<<< HEAD
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
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "bullet/btBulletCollisionCommon.h"
#include "bullet/btBulletDynamicsCommon.h"
#include "Nodo.h"
#include "IAManager.h"





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
   CameraManager*       cameramanager       = CameraManager::getInstance();

   IAManager*        iamanager        = IAManager::getInstance();

   ItemManager*         itemManager         = ItemManager::getInstance();
   StorageManager*      storageManager      = StorageManager::getInstance();



    //ADDING A BOX
    GameObject* box = gameresource->createGameObject(0.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    //Adding an Item2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    GameObject* primero = gameresource->createGameObject(200.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz

    
    //Add a Render
    rendermanager->createComponent(box, (char*)"res/Blocky.obj");//Fachada de render y path de obj
    box->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmpç

    //Add a Render for Item 1
    rendermanager->createComponent(item1, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp

    //Add a Render for Item 2
    rendermanager->createComponent(item2, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp

    //Add a Render to primero
    rendermanager->createComponent(primero, (char*)"res/Enemyy.obj");//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture((char*) "res/red.bmp");//Path de bmp


    //Add Movement
    movementmanager->createComponent(box);
    box->getComponent<MovementComponent>()->setvMax(700.f);

     //Add Movement to primero
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(200.f);
=======
 
#include <irrlicht.h>
#include "PhysicBullet.h"
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>
 
using namespace std;
 
using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace io;
using namespace gui;    

static void CreateStartScene();
static void CreateBox(const btVector3 &TPosition, const vector3df &TScale, btScalar TMass);
static void UpdatePhysics(u32 TDeltaTime);
static void UpdateRender(btRigidBody* TObject);
static void ClearObjects();
static int GetRandInt(int TMax) { return rand() % TMax; }
PhysicBullet* physic = PhysicBullet::getInstance();
btDynamicsWorld* _world;
static bool Done = false;
static btDiscreteDynamicsWorld* dynamicsWorld;
static IrrlichtDevice* Device;
static IVideoDriver* Driver;
static ISceneManager* Smgr;
static IGUIEnvironment* Env;
static ITimer* Timer;
btRigidBody* rbody;
 
static list <btRigidBody*> Objects;
 


int main(int argc, char* argv[])
{

    
    Device = createDevice(EDT_OPENGL, dimension2d<u32>(800,600),32,false,false,false, NULL);
    Driver = Device->getVideoDriver();
    Smgr = Device->getSceneManager();
    Env = Device->getGUIEnvironment();
    Timer = Device->getTimer();
    

>>>>>>> c78246e39299733e23c2f0488b7287cabb453819

    _world = physic->initWorldPhysics();

<<<<<<< HEAD
    //Add Collisions
    collisionmanager->createComponent(box, 200, 200, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    collisionmanager->createComponent(primero, 55, 55, true); //Ancho, alto y si es solido

    //Add IA
    iamanager->createComponent(primero,box);

    primero->getComponent<IAComponent>()->Initialice();
    
    //Add Life
    lifemanager->createComponent(primero, 100.f);//Vida
    shootmanager->createComponent(box, .2f, 115.f, PROJECTILE_1);//Cadencia y Tipo

    //Add Camera
    cameramanager->createComponent(box);


    GameObject* map = gameresource->createGameObject(0.f, 0.f, 20.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/Mapy.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp    
    itemManager->createComponent(item1, ITEM_CADENCE);
    itemManager->createComponent(item2, ITEM_LIFE);

    storageManager->createComponent(box, 0);


    while(render->run())
    {   
       

        box->getComponent<InputComponent>()->pulseInput(interface);
        iamanager->updateAll();


        movementmanager->updateAll(render->getFrameDeltaTime());
        shootmanager->updateAll(render->getFrameDeltaTime());
        
        collisionmanager->updateAll();
        cameramanager->updateAll(render->getFrameDeltaTime());
        gameresource->updateAll();
        rendermanager->updateAll();

        render->drawAll();





    }
=======
    ICameraSceneNode* Camera = Smgr->addCameraSceneNode(0,vector3df(0,0,0),vector3df(0,0,100));
    Camera->setPosition(vector3df(0,5,-10));
    Camera->setTarget(vector3df(0,0,0));
    
    Driver->getTexture("ice0.jpg");
    
    Smgr->addLightSceneNode(0,vector3df(2,5,-2),SColorf(4,4,4,1));
    CreateStartScene();
    
    u32 TimeStamp = Timer->getTime(), DeltaTime = 0;
    while(!Done)
    {
        DeltaTime = Timer->getTime() - TimeStamp;
        TimeStamp = Timer->getTime();
        ///rbody->activate();
        UpdatePhysics(DeltaTime);
        
        Driver->beginScene(true, true, SColor(255,20,0,0));
        Smgr->drawAll();
        Env->drawAll();
        Driver->endScene();
        
        Device->run();
    }
    
    ClearObjects();
    delete physic;
    
    
    Device->drop();
    
    return 0;
}
 
void UpdatePhysics(u32 TDeltaTime)
{
    physic->iteration(TDeltaTime );         //ACTUALIZAR BULLET

    for(list<btRigidBody*>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator)
    {
        UpdateRender(*Iterator);                                    //ACTUALIZAR CADA OBJETO EN IRRLICHT
    }
}
 
void CreateBox(const btVector3 &TPosition, const vector3df &TScale, btScalar TMass)
{
    ISceneNode* Node = Smgr->addCubeSceneNode(1.0f);                //
    Node->setScale(TScale);                                         //
    Node->setMaterialFlag(EMF_LIGHTING,1);                          //METODO IRRLICHT AÑADIR CUBO    
    Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);             //    
    Node->setMaterialTexture(0,Driver->getTexture("ice0.jpg"));     //    

    btVector3 v = btVector3(TScale.X * 0.5f, TScale.Y * 0.5f, TScale.Z * 0.5f);
    
    rbody = physic->createRigidBody(TPosition, v, TMass);


    rbody->setUserPointer((void*)(Node));                                               //
                                                                                            //    
    _world->addRigidBody(rbody);                                                 //
    Objects.push_back(rbody);                                                          
}
>>>>>>> c78246e39299733e23c2f0488b7287cabb453819

 
void CreateStartScene()
{
    ClearObjects();
    CreateBox(btVector3(0.0f,0.0f,0.0f), vector3df(10.0f,0.5f,10.0f),0.0f);
    CreateBox(btVector3(.5,0.5,.5), vector3df(0.5f,0.5f,.5f),1.0f);

<<<<<<< HEAD


    delete rendermanager;
    delete movementmanager;
    delete collisionmanager;   
    delete shootmanager;    
    delete lifemanager;
    delete projectilemanager;
    delete inputmanager;
    delete itemManager;

    delete gameresource;

    delete render;
    delete interface;
    
    

    return 0;
=======
}
 
void UpdateRender(btRigidBody* TObject)
{
    ISceneNode* Node = static_cast<ISceneNode*>(TObject->getUserPointer());
    
    btVector3 Point = TObject->getCenterOfMassPosition();
    Node->setPosition(vector3df((f32)Point[0],(f32)Point[1],(f32)Point[2]));
    
    vector3df Euler;
    const btQuaternion& TQuat = TObject->getOrientation();
    quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
    q.toEuler(Euler);
    Euler *= RADTODEG;
    Node->setRotation(Euler);
}
 
void ClearObjects()
{
    for(list<btRigidBody*>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator)
    {
        btRigidBody* Object = *Iterator;
        
        ISceneNode *Node = static_cast<ISceneNode*>(Object->getUserPointer());
        Node->remove();
        
        _world->removeRigidBody(Object);
        
        delete Object->getMotionState();
        delete Object->getCollisionShape();
        delete Object;
    }
    
    Objects.clear();
>>>>>>> c78246e39299733e23c2f0488b7287cabb453819
}