#include "btBulletDynamicsCommon.h"

class World{
    private:
    statitc World* only_instace;

    World();

    btBroadphaseInterface*                  _broadphase;
    btDefaultCollisionConfiguration*        _collisionConfiguration;
    btCollisionDispatcher*                  _dispatcher;
    btSequentialImpulseConstraintSolver*    _solver;
    btDiscreteDynamicsWorld*                _world;

    public:
    
    virtual ~World(){ only_instance = NULL};

    static RenderIrrlicht* getInstance()
    {   
        if(only_instance==NULL)
        {
            only_instance = new RenderIrrlicht();
        }
        return only_instance;
    }

}