#pragma once
#include "PhysicBullet.h"
#include "BPhysicComponent.h"
#include "BTerrainComponent.h"
#include "IAComponent.h"
#include "ProjectileComponent.h"
#include "LifeComponent.h"
//#include "StorageComponent.h"
//#include "ItemComponent.h"
#include "InputComponent.h"
#include "GameObject.h"

class Manager;
//class StorageComponent;
//class ItemComponent;

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
        void createComponent(GameObject* owner,char* mesh);
        void updateAll(float dt);
};