#pragma once
#include <vector>
#include "Manager.h"

class GameObject;
class ProjectileManager : public Manager{
    private:
        ProjectileManager():Manager(){}
        static ProjectileManager* only_instance;

    public:
        ~ProjectileManager(){only_instance=nullptr;}
        static ProjectileManager *getInstance(){
            if(!only_instance)
                only_instance = new ProjectileManager();
            
            return only_instance;
        }

        void createComponent(GameObject* owner, float damage);
        void updateAll(float dt);
};