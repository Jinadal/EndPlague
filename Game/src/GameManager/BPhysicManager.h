#pragma once
#include "PhysicBullet.h"
#include "Manager.h"

class GameObject;
class BPhysicManager : public Manager
{
    private:
        static BPhysicManager* only_instance;
        BPhysicManager(){PhysicBullet::getInstance();  gContactAddedCallback = this->callbackFunc;}
    public:
        ~BPhysicManager(){only_instance = NULL;}
        static BPhysicManager* getInstance(){
            if(only_instance==NULL) only_instance = new BPhysicManager();

            return only_instance;
        }
        static bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2);
        void createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass, int physicType);
        void updateAll(float dt);
};