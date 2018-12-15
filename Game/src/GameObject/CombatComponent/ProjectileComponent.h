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
        ~ProjectileComponent(){}

        //Setter&Getter
        float getDamage()         {return damage;}
        void setDamage(float d)   {damage = d;}

        //Methods
        void dealDamage(LifeComponent* l);
};
