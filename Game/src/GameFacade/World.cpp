#include "World.h"

World* World::only_instance = NULL;

void World::initWorldPhysics(){
    //Initialize the scene where the physics take part. It defines how collision are going to take part and resolved.

    //btDbvtBroadphase = uses a fast dynamic bounding volume hierarchy based on AABB tree
    //Collision has 2 phases: 1º broad that discards all objects that cannot collide and 
    //2º narrow that creates a list with all the objects that can collide (this method is 
    //slower). 
    _broadphase = new btDbvtBroadphase();

    _collisionConfiguration = new btDefaultCollisionConfiguration();
    _dispatcher = new btCollisionDispatcher(_collisionConfiguration);

    _solver = new btSequentialImpulseConstraintSolver();

    _world = new btDiscreteDynamicsWorld(_dispatcher, _broadphase, _solver, _collisionConfiguration);

    _world->setGravity(btVector3(0,-9.8,0));
}