#pragma once 
#include <btBulletDynamicsCommon.h>



class PhysicBullet{
    private:
    static PhysicBullet* only_instance;
    PhysicBullet(){initWorldPhysics();};

    btBroadphaseInterface*                      _broadphase;
    btDefaultCollisionConfiguration*            _collisionConfiguration;
    btCollisionDispatcher*                      _dispatcher;
    btSequentialImpulseConstraintSolver*        _solver;
    btDynamicsWorld*                            _world;
    btAlignedObjectArray<btCollisionShape*>     _collisionShapes;
    
    public:
    
    virtual ~PhysicBullet();

    static PhysicBullet* getInstance()
    {   
        if(only_instance==NULL)
        {
            only_instance = new PhysicBullet();
        }
        return only_instance;
    }

    void removeRigidBody(btRigidBody* rigidbody);

    btDynamicsWorld* initWorldPhysics();
    btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass, int physicType);
    btRigidBody* createTerrain(btScalar mass, btVector3 position, btConvexTriangleMeshShape* shape);
    void iteration(float d);
    void move(btRigidBody* body,int m);
};
