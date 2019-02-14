#pragma once 
#include <btBulletDynamicsCommon.h>

class PhysicBullet{
    private:
        PhysicBullet(){init();};

        btBroadphaseInterface*                      _broadphase;
        btDefaultCollisionConfiguration*            _collisionConfiguration;
        btCollisionDispatcher*                      _dispatcher;
        btSequentialImpulseConstraintSolver*        _solver;
        btDynamicsWorld*                            _world;
        btAlignedObjectArray<btCollisionShape*>     _collisionShapes;
        
    public:
    
        virtual ~PhysicBullet(){clear();};

        static PhysicBullet* getInstance(){
            static PhysicBullet only_instance;
            return &only_instance;
        }
    

        void removeRigidBody(btRigidBody* rigidbody);

        
        btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass, int physicType);
        btRigidBody* createFromFile(char* filename);
        void iteration(float d);
        void* rayTest(float x, float y, float z, float rz);
        void init();
        void clear();
};
