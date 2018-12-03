#include <btBulletDynamicsCommon.h>

class World{
    private:
    static World* only_instance;

    World();

    btBroadphaseInterface*                      _broadphase;
    btDefaultCollisionConfiguration*            _collisionConfiguration;
    btCollisionDispatcher*                      _dispatcher;
    btSequentialImpulseConstraintSolver*        _solver;
    btDynamicsWorld*                            _world;
    btAlignedObjectArray<btCollisionShape*>    _collisionShapes;
    
    public:
    
    virtual ~World();

    static World* getInstance()
    {   
        if(only_instance==NULL)
        {
            only_instance = new World();
        }
        return only_instance;
    }

    void initWorldPhysics();
    void createRigidBody();
    void iteration();
};