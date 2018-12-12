#pragma once
#include "ShootComponent.h"
#include <vector>
#include "ProjectileFabric.h"

class Manager;
class ShootManager : public Manager{
    private:
        ShootManager():Manager(){fabric = new ProjectileFabric();}
        static ShootManager* only_instance;
        ProjectileFabric* fabric;

    public:
    
        static ShootManager *getInstance(){         //Pattern Singleton
            if(only_instance == NULL)
                only_instance = new ShootManager();
            
            return only_instance;
        }

        ~ShootManager(){delete fabric; only_instance=NULL;}
        void updateAll(float dt);
        void createProjectile(float x, float y, float rz, ProjectileType tipo);
        void createComponent(GameObject *owner, float cadencia, float distance, ProjectileType tipo);
};