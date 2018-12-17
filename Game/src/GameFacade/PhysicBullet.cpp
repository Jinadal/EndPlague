 
#include "PhysicBullet.h"
#include <iostream>


PhysicBullet* PhysicBullet::only_instance = NULL;

PhysicBullet::~PhysicBullet()
{
    int i;
	for (i=_world->getNumCollisionObjects()-1; i>=0 ;i--)
	{
		btCollisionObject* obj = _world->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{

			while (body->getNumConstraintRefs())
			{
				btTypedConstraint* constraint = body->getConstraintRef(0);
				_world->removeConstraint(constraint);
				delete constraint;
			}
			delete body->getMotionState();
			_world->removeRigidBody(body);
		} else
		{
			_world->removeCollisionObject( obj );
		}
		delete obj;
	}

	//delete collision shapes
	for (int j=0;j<_collisionShapes.size();j++)
	{
		btCollisionShape* shape = _collisionShapes[j];
		delete shape;
	}
	_collisionShapes.clear();
    delete _broadphase;
    delete _collisionConfiguration;
    delete _dispatcher;
    delete _solver;
    delete _world;;
}

void PhysicBullet::removeRigidBody(btRigidBody* rigidbody)
{
    if(rigidbody && rigidbody->getMotionState())
    {
        delete rigidbody->getMotionState();
    }
    for(int i=0; i<_collisionShapes.size();i++)
    {
        if(rigidbody->getCollisionShape()==_collisionShapes[i])
        {
            _collisionShapes.removeAtIndex(i);
            break;
        }
    }
    delete rigidbody->getCollisionShape();
    _world->removeRigidBody(rigidbody);
    delete rigidbody;
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
    
    //Makes a rigidbody inot kinematic so we can control it
    body->setCollisionFlags(body->getCollisionFlags()|btCollisionObject::CF_KINEMATIC_OBJECT);
    body->setActivationState( DISABLE_DEACTIVATION );
    
    //Allows to use the pointer and the callback with this object
    //body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
    
    //Array of shapes in the world
	//Better re-use collision shapes than rigidbodies
    _collisionShapes.push_back(boxyBox);

    //Pointer to the last shape added to de array
    //body->setUserPointer(_collisionShapes[_collisionShapes.size()-1]);
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
bool PhysicBullet::callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2)
{
    
    std::cout<<obj1->getCollisionObject()->getUserPointer()<<std::endl;
    std::cout<<obj2->getCollisionObject()->getUserPointer()<<std::endl;

    return false;
}