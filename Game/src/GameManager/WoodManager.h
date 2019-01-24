#pragma once
#include "Manager.h"

class GameObject;
class Manager;
class WoodManager : public Manager{
    private:
        WoodManager():Manager(){}

        static WoodManager* only_instance;
    
    public:
        static WoodManager* getInstance()
        {
            if(!only_instance)only_instance=new WoodManager();

            return only_instance;
        }

        void createComponent(GameObject* owner, float life);
        void updateAll(float dt);
};