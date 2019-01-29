#pragma once
#include "Manager.h"

class GameObject;
class WellManager : public Manager{
    private:
        WellManager():Manager(){}

        static WellManager* only_instance;
    
    public:
        static WellManager* getInstance()
        {
            if(!only_instance)only_instance=new WellManager();

            return only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};