#pragma once
//Headers
#include "ShootComponent.h"
#include <vector>

class Manager;
class ShootManager : public Manager{
    private:
        ShootManager():Manager(){}
        static ShootManager* only_instance;

    public:
    
        static ShootManager *getInstance(){         //Pattern Singleton
            if(only_instance == NULL)
                only_instance = new ShootManager();
            
            return only_instance;
        }

        ~ShootManager(){}
        void kill();
        void updateAll(float dt);
        void createBullet(float x, float y, float rz, int k);
        void createComponent(GameObject *owner, float cadencia, int tipo);
};