#pragma once
#include <vector>
#include "ProjectileComponent.h"
#include "GameObject.h"


class GameObject;
class Manager;
class ProjectileManager : public Manager{
    private:
        ProjectileManager():Manager(){}
        static ProjectileManager* only_instance;

    public:
        //Constructor
        static ProjectileManager *getInstance(){
            if(only_instance == NULL)
                only_instance = new ProjectileManager();
            
            return only_instance;
        }

        virtual ~ProjectileManager(){only_instance=NULL;}
        void createComponent(GameObject* owner, float damage);
        void createBullet();
};