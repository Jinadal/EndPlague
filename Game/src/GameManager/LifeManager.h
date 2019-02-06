#pragma once
#include "Manager.h"

class GameObject;
class LifeManager : public Manager{
    private:
        LifeManager():Manager(){}
        static LifeManager *only_instance;
        
    public:
        virtual ~LifeManager(){only_instance=nullptr;}
        static LifeManager *getInstance(){
            if(!only_instance)
                only_instance = new LifeManager();

            return only_instance;
        }

        void createComponent(GameObject* owner, float life, bool decreases = false);
        void updateAll(float dt);
};