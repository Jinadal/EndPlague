#include <btBulletDynamicsCommon.h>

class World{
    private:
    static World* only_instance;

    World();

    btBroadphaseInterface*                  _broadphase;
    btDefaultCollisionConfiguration*        _collisionConfiguration;
    btCollisionDispatcher*                  _dispatcher;
    btSequentialImpulseConstraintSolver*    _solver;
    btDynamicsWorld*                        _world;

    public:
    
    virtual ~World(){ only_instance = NULL; }

    static World* getInstance()
    {   
        if(only_instance==NULL)
        {
            only_instance = new World();
        }
        return only_instance;
    }

    void initWorldPhysics();

};