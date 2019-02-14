#pragma once
#include "Manager.h"

class GameObject;
class LifeManager : public Manager{
    private:
        LifeManager():Manager(){}
        
    public:
        virtual ~LifeManager(){}
        static LifeManager* getInstance(){
            static LifeManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner, float life, bool decreases = false);
        void updateAll(float dt);
};