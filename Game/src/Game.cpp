#include <stdlib.h>
#include <stdio.h>
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
#include "CameraManager.h"
#include "ItemManager.h"
#include "StorageManager.h"
#include "SpawnManager.h"
#include "Nodo.h"
#include "IAManager.h"
 
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
void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass);
static void UpdatePhysics(u32 TDeltaTime);
static void UpdateRender(btRigidBody* TObject);
static void ClearObjects();
static int GetRandInt(int TMax) { return rand() % TMax; }
PhysicBullet* physic = PhysicBullet::getInstance();
btDynamicsWorld* _world;
static bool Done = false;
static IrrlichtDevice* Device;
static IVideoDriver* Driver;
static ISceneManager* Smgr;
static IGUIEnvironment* Env;
static ITimer* Timer;
btRigidBody* rbody;
 
static list <btRigidBody*> Objects;


// Event receiver
class EventReceiverClass : public IEventReceiver  {

public:

	virtual bool OnEvent(const SEvent &TEvent) {

		if(TEvent.EventType == EET_KEY_INPUT_EVENT && !TEvent.KeyInput.PressedDown) {
			switch(TEvent.KeyInput.Key) {
				case KEY_ESCAPE:
					Done = true;
				break;
                case KEY_KEY_A:
                        physic->move(rbody,1);
				break;
                case KEY_KEY_D:
                        physic->move(rbody,2);
				break;
                case KEY_KEY_S:
                        physic->move(rbody,3);
				break;
                case KEY_KEY_W:
                        physic->move(rbody,4);
				break;
				case KEY_KEY_P:
					CreateSphere(btVector3(GetRandInt(10) - 5.0f, 7.0f, GetRandInt(10) - 5.0f), GetRandInt(5) / 5.0f + 0.2f, 1.0f);
				break;
				case KEY_KEY_X:
					CreateStartScene();
				break;
				default:
					return false;
				break;
			}

			return true;
		}

		return false;
	}
};

int main(int argc, char* argv[])
{
    //Allows to make a callback in another directory
    gContactAddedCallback = physic->callbackFunc;


	EventReceiverClass Receiver;
    Device = createDevice(EDT_OPENGL, dimension2d<u32>(800,600),32,false,false,false, &Receiver);
    Driver = Device->getVideoDriver();
    Smgr = Device->getSceneManager();
    Env = Device->getGUIEnvironment();
    Timer = Device->getTimer();
    



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
        rbody->activate();
        UpdatePhysics(DeltaTime);
        rbody->setCollisionFlags(rbody->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
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


    //ADDING A MAP
    GameObject* map = gameresource->createGameObject(0.f, 0.f, 20.f, 0.f);
    rendermanager->createComponent(map, (char*)"res/Mapy.obj");//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp   

    //ADDING A PLAYER
    GameObject* player = gameresource->createGameObject(0.f, 200.f, -10.f, 180.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(player, (char*)"res/DOMMIEZ.obj");//Fachada de render y path de obj
    player->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    movementmanager->createComponent(player);
    player->getComponent<MovementComponent>()->setvMax(700.f);
    inputmanager->createComponent(player);
    collisionmanager->createComponent(player, 25, 50, true); //Ancho, alto y si es solido
    shootmanager->createComponent(player, .2f, 115.f, PROJECTILE_1);//Cadencia y Tipo
    cameramanager->createComponent(player);
    storagemanager->createComponent(player);
    iamanager->setPlayer(player);
    

    //ADDING A SPAWN
    GameObject* spawn = gameresource->createGameObject(250.f, -200.f, -10.f, 0.f);
    rendermanager->createComponent(spawn, (char*)"res/SPAWNz.obj");//Fachada de render y path de obj
    spawn->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");//Path de bmp
    collisionmanager->createComponent(spawn, 200, 200, true); //Ancho, alto y si es solido
    spawnmanager->createComponent(spawn, 135.f, ENEMY_1);
    lifemanager->createComponent(spawn, 300.f);
 
void CreateStartScene()
{
    ClearObjects();
    CreateBox(btVector3(0.0f,0.0f,0.0f), vector3df(10.0f,0.5f,10.0f),0.0f);
    CreateBox(btVector3(.5,1.5,.5), vector3df(0.5f,0.5f,.5f),1.0f);


    //Adding an ITEM1
    GameObject* item1 = gameresource->createGameObject(0.f, 30.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item1, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item1->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");//Path de bmp
    collisionmanager->createComponent(item1, 50, 50, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item1, ITEM_CADENCE);
    
    
    //Adding an ITEM2
    GameObject* item2 = gameresource->createGameObject(0.f, -200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item2, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    collisionmanager->createComponent(item2, 50, 50, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item2, ITEM_LIFE);
    

    //Adding an ITEM3
    GameObject* item3 = gameresource->createGameObject(0.f, -500.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(item3, (char*)"res/ITEM.obj");//Fachada de render y path de obj
    //item2->getComponent<RenderComponent>()->setTexture((char*) "");//Path de bmp
    collisionmanager->createComponent(item3, 50, 50, true); //Ancho, alto y si es solido
    itemmanager->createComponent(item3, ITEM_THROWABLE);

    //ADDING A ENEMY
    GameObject* primero = gameresource->createGameObject(-200.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(primero, (char*)"res/DOMMIEZ.obj");//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture((char*) "res/red.bmp");//Path de bmp
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(200.f);
    collisionmanager->createComponent(primero, 55, 55, true); //Ancho, alto y si es solido
    iamanager->createComponent(primero);
    primero->getComponent<IAComponent>()->Initialice();
    lifemanager->createComponent(primero, 100.f);//Vida

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
    
    Objects.clear();
}

void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass) {
	
	ISceneNode *Node = Smgr->addSphereSceneNode(TRadius, 32);
	Node->setMaterialFlag(EMF_LIGHTING, 1);
	Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
	Node->setMaterialTexture(0, Driver->getTexture("ice0.jpg"));

	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(TPosition);

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);

	// Create the shape
	btCollisionShape *Shape = new btSphereShape(TRadius);

	// Add mass
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(TMass, LocalInertia);

	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);
    RigidBody->setCollisionFlags(RigidBody->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);

	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));

	// Add it to the world
	_world->addRigidBody(RigidBody);
	Objects.push_back(RigidBody);
}