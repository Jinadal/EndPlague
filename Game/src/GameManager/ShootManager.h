#pragma once
#include "ProjectileFabric.h"
#include "Manager.h"

class ShootManager : public Manager{
    private:
        ShootManager():Manager(){fabric = new ProjectileFabric();}
        static ShootManager* only_instance;
        ProjectileFabric* fabric;

    public:
        ~ShootManager(){delete fabric; only_instance=NULL;}
        static ShootManager *getInstance(){         //Pattern Singleton
            if(!only_instance)
                only_instance = new ShootManager();
            
            return only_instance;
        }

        void updateAll(float dt);
        void createProjectile(float x, float y, float rz, ProjectileType tipo);
        void createComponent(GameObject *owner, float cadencia, float distance, ProjectileType tipo);
};