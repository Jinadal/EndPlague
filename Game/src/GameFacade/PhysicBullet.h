 
#include <btBulletDynamicsCommon.h>

class PhysicBullet{
    private:
    static PhysicBullet* only_instance;
    PhysicBullet(){};

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

    btDynamicsWorld* initWorldPhysics();
    btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass);
    //void MoveRigidBody();
    void iteration(float d);
    //btDynamicsWorld* getWorld(){ return _world; }
    void move(btRigidBody* body,int m);
};