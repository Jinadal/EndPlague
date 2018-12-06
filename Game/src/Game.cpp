
#include <stdlib.h>
#include <stdio.h>
 
#include <irrlicht.h>
 
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
static void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass);
static void UpdatePhysics(u32 TDeltaTime);
static void UpdateRender(btRigidBody* TObject);
static void ClearObjects();
static int GetRandInt(int TMax) { return rand() % TMax; }
 

static bool Done = false;
static btDiscreteDynamicsWorld* dynamicsWorld;
static IrrlichtDevice* Device;
static IVideoDriver* Driver;
static ISceneManager* Smgr;
static IGUIEnvironment* Env;
static ITimer* Timer;
 
static list <btRigidBody*> Objects;
 
int ran = rand() % 10 + 1;
int ran2 = rand() % 5 + 3;
 
class MainEvent : public IEventReceiver
{
    public:
        virtual bool OnEvent(const SEvent& event)
        {
            if(event.EventType == EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
            {
                switch(event.KeyInput.Key)
                {
                    case KEY_ESCAPE:
                        Done = true;
                        break;
                        
                    case KEY_KEY_A:
                        CreateBox(btVector3(ran,ran2,ran), vector3df(0.5f,0.5f,.5f),1.0f);
                        break;
                    case KEY_KEY_S:
					    CreateSphere(btVector3(GetRandInt(10) - 5.0f, 7.0f, GetRandInt(10) - 5.0f), GetRandInt(5) / 5.0f + 0.2f, 1.0f);
				    break;
                    case KEY_KEY_X:
                        CreateStartScene();
                        break;
                        
                    default:
                        return false;
                }
                
                return true;
            }
            
            return false;
        }
};
 
int main(int argc, char* argv[])
{
    MainEvent receiver;
    
    Device = createDevice(EDT_OPENGL, dimension2d<u32>(800,600),32,false,false,false,&receiver);
    Driver = Device->getVideoDriver();
    Smgr = Device->getSceneManager();
    Env = Device->getGUIEnvironment();
    Timer = Device->getTimer();
    
    btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
    btBroadphaseInterface* broadphase = new btAxisSweep3(btVector3(-1000,-1000,-1000), btVector3(1000,1000,1000));
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
    
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
        
        UpdatePhysics(DeltaTime);
        
        Driver->beginScene(true, true, SColor(255,20,0,0));
        Smgr->drawAll();
        Env->drawAll();
        Driver->endScene();
        
        Device->run();
    }
    
    ClearObjects();
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete broadphase;
    delete collisionConfiguration;
    
    Device->drop();
    
    return 0;
}
 
void UpdatePhysics(u32 TDeltaTime)
{
    dynamicsWorld->stepSimulation(TDeltaTime * 0.001f, 60);         //ACTUALIZAR BULLET
    
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
    
    btTransform Transform;                                                                  //
    Transform.setIdentity();                                                                //
    Transform.setOrigin(TPosition);                                                         //
                                                                                            //
    btDefaultMotionState* MotionState = new btDefaultMotionState(Transform);                //    
                                                                                            //
    btVector3 HalfExtents(TScale.X * 0.5f, TScale.Y * 0.5f, TScale.Z * 0.5f);               //
    btCollisionShape* Shape = new btBoxShape(HalfExtents);                                  //
                                                                                            //        
    btVector3 LocalInertia;                                                                 // METODO BULLET AÑADIR CUBO
    Shape->calculateLocalInertia(TMass, LocalInertia);                                      //
                                                                                            //
    btRigidBody* RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);      //
                                                                                            //
    RigidBody->setUserPointer((void*)(Node));                                               //
                                                                                            //    
    dynamicsWorld->addRigidBody(RigidBody);                                                 //
    Objects.push_back(RigidBody);                                                           //
}
void CreateSphere(const btVector3 &TPosition, btScalar TRadius, btScalar TMass) {
	
	ISceneNode *Node = Smgr->addSphereSceneNode(TRadius, 32);
    Node->setMaterialFlag(EMF_LIGHTING,1);
    Node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
    Node->setMaterialTexture(0,Driver->getTexture("ice0.jpg"));
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

	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));

	// Add it to the world
	dynamicsWorld->addRigidBody(RigidBody);
	Objects.push_back(RigidBody);
}
 
void CreateStartScene()
{
    ClearObjects();
    CreateBox(btVector3(0.0f,0.0f,0.0f), vector3df(10.0f,0.5f,10.0f),0.0f);
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
        
        dynamicsWorld->removeRigidBody(Object);
        
        delete Object->getMotionState();
        delete Object->getCollisionShape();
        delete Object;
    }
    
    Objects.clear();
}