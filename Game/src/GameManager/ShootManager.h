#pragma once
//Headers
#include "ShootComponent.h"
#include <vector>


class ShootManager{
    private:
        ShootManager(){}
        static ShootManager* only_instance;
        std::vector<ShootComponent*> components;
    public:
        //Destructor
        ~ShootManager(){}

        static ShootManager *getInstance(){         //Pattern Singleton
            if(only_instance == NULL)
                only_instance = new ShootManager();
            
            return only_instance;
        }
        void addComponent(ShootComponent* c);
        void updateAll(float dt);
        void createBullet(float x, float y, float rz, int k);
        void createComponent(GameObject *owner, float cadencia, int tipo);
};