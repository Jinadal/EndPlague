
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
 
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
    


    _world = physic->initWorldPhysics();

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

 
void CreateStartScene()
{
    ClearObjects();
    CreateBox(btVector3(0.0f,0.0f,0.0f), vector3df(10.0f,0.5f,10.0f),0.0f);
    CreateBox(btVector3(.5,0.5,.5), vector3df(0.5f,0.5f,.5f),1.0f);

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
}