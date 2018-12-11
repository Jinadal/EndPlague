 
#include "PhysicBullet.h"
#include <iostream>

using namespace std;


PhysicBullet* PhysicBullet::only_instance = NULL;

PhysicBullet::~PhysicBullet()
{

    //Deleting motionstate/rigidbodies/shapes
    for(int i=0; i < _world->getNumCollisionObjects() - 1 ; i--)
    {
        btCollisionObject*  delShape    = _world->getCollisionObjectArray()[i];
        btRigidBody*        delbody     = btRigidBody::upcast(delShape);
        if(delbody && delbody->getMotionState())
        {
            delete delbody->getMotionState();
        }
        _world->removeCollisionObject(delShape);
        delete delShape;
    }
	for (int i = 0; i < _collisionShapes.size(); i++)
	{
		btCollisionShape* delShape = _collisionShapes[i];
		_collisionShapes[i] = 0;
		delete delShape;
	}
    delete _broadphase;
    delete _collisionConfiguration;
    delete _dispatcher;
    delete _solver;
    delete _world;
    only_instance = NULL;
}

btDynamicsWorld* PhysicBullet::initWorldPhysics()
{
    //Initialize the scene where the physics take part. It defines how collision are going to take part and resolved.

    //btDbvtBroadphase = uses a fast dynamic bounding volume hierarchy based on AABB tree
    //Collision has 2 phases: 1º broad that discards all objects that cannot collide and 
    //2º narrow that creates a list with all the objects that can collide (this method is 
    //slower). DbvtBroadphase is specially used for AABB tree implementation.
    _broadphase = new btDbvtBroadphase();


    //Responsable of the collision management and detection. Contains default setup for memory, collision setup.
    _collisionConfiguration = new btDefaultCollisionConfiguration();
    _dispatcher = new btCollisionDispatcher(_collisionConfiguration);

    //Responsable of the correct interaction, taking into account gravity,
    //game logic supplied forces, collisions, and hinge constraints.
    _solver = new btSequentialImpulseConstraintSolver();

    //Creation of the world and input the configurations
    _world = new btDiscreteDynamicsWorld(_dispatcher, _broadphase, _solver, _collisionConfiguration);

    //Set gravity to physics in y=-9,8
    _world->setGravity(btVector3(0,-9.8,0));


    //We create the floor of our world
    //createRigidBody(btVector3(0.0f,0.0f,0.0f), btVector3(100.0f,0.5f,100.0f),0.0f);

    return _world;
}

btRigidBody* PhysicBullet::createRigidBody(const btVector3 &initPos, const btVector3 &scale, btScalar mass)
{
    //Matrix 4x4 for position and rotation
    btTransform transform;
	transform.setIdentity();
	transform.setOrigin(initPos);

    //Used for locate position and rotation of every object in each iteration
    btDefaultMotionState*  motionState = new btDefaultMotionState(transform);

    //We create a collision with box shape with sides 100. Each parametre starts from the center of the shape
    //Afterwards we create a RigidBody that wont modifate its shape after collision. 
    //Body parametres = (mass,motionstate,collisionshape,)
    btCollisionShape*   boxyBox = new btBoxShape(scale);

    btVector3 LocalInertia;                                                                 
    boxyBox->calculateLocalInertia(mass, LocalInertia);

    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, boxyBox,LocalInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
    
    body->setCollisionFlags(body->getCollisionFlags()|btCollisionObject::CF_KINEMATIC_OBJECT);
    body->setActivationState( DISABLE_DEACTIVATION );

    //Array of shapes in the world
	//Better re-use collision shapes than rigidbodies
    _collisionShapes.push_back(boxyBox);

    //We add the body to the world so it can interactuate
    _world->addRigidBody(body);
    
    return body;
}

void PhysicBullet::iteration(float delta)
{
    //Update the objects in the world based on the step parametres of time
    //Parametres = stepSimulation(btScalar timeStep,int maxSubSteps=1,btScalar fixedTimeStep=btScalar(1.)/btScalar(60.));
    //timeStep is the time passed after last simulation.
    _world->stepSimulation(delta*0.001f,60);

}
void PhysicBullet::move(btRigidBody* body,int m)
{
    
    btTransform newTrans;
    body->getMotionState()->getWorldTransform(newTrans);
        if(m==1)newTrans.getOrigin() += (btVector3(-0.1f, 0, 0));
        if(m==2)newTrans.getOrigin() += (btVector3(0.1f, 0, 0));
        if(m==3)newTrans.getOrigin() += (btVector3(0, 0, -0.1f));
        if(m==4)newTrans.getOrigin() += (btVector3(0, 0, 0.1f));
    body->getMotionState()->setWorldTransform(newTrans);
}