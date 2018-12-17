#pragma once
#include "BCollisionComponent.h"
#include <iostream>

class GameObject;
class Manager;
class BCollisionManager : public Manager
{
    private:
        static BCollisionManager* only_instance;
        BCollisionManager(){}
    public:
        ~BCollisionManager(){only_instance = NULL;}
        static BCollisionManager* getInstance(){
            if(only_instance==NULL) only_instance = new BCollisionManager();

            return only_instance;
        }
        static bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2);
        void createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass);
        void updateAll();
};