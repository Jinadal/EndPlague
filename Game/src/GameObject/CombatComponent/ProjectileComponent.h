#pragma once
//Headers
#include "Component.h"

class GameObject;
class LifeComponent;
class ProjectileComponent : public Component{
     private:
        float damage;
    public:
        //Constructor
        ProjectileComponent(GameObject* g, Manager* m, float damage):Component(g, m){
            this->damage = damage;
        }
        virtual ~ProjectileComponent(){};

        //Setter&Getter
        int getDamage()         {return damage;}
        void setDamage(int d)   {damage = d;}

        //Methods
        bool dealDamage(LifeComponent* l);
        void crush();
};
