 
#include <btBulletDynamicsCommon.h>

class PhysicBullet{
    private:
    static PhysicBullet* only_instance;

    btBroadphaseInterface*                      _broadphase;
    btDefaultCollisionConfiguration*            _collisionConfiguration;
    btCollisionDispatcher*                      _dispatcher;
    btSequentialImpulseConstraintSolver*        _solver;
    btDiscreteDynamicsWorld*                            _world;
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

    btDiscreteDynamicsWorld* initWorldPhysics();
    btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass);
    void iteration(float d);
    btDynamicsWorld* getWorld(){ return _world; }
};