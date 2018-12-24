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
    bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2);

    btDynamicsWorld* initWorldPhysics();
    btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass);
    void iteration(float d);
    void move(btRigidBody* body,int m);
};