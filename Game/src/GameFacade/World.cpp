#include "World.h"

World* World::only_instance = NULL;

void World::initWorldPhysics(){
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
}