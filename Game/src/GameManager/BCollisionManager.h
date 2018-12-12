#pragma once
#include "BCollisionComponent.h"

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

        void createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass);
        void updateAll();
};