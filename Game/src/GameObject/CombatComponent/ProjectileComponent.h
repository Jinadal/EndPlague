#pragma once
//Headers
#include "Component.h"

class ProjectileComponent : public Component{
     private:
        float damage;
    public:
        //Constructor
        ProjectileComponent(GameObject* g, float damage):Component(g){
            this->damage = damage;
        }
        ~ProjectileComponent(){};

        //Setter&Getter
        int getDamage()         {return damage;}
        void setDamage(int d)   {damage = d;}

        //Methods
        bool dealDamage(LifeComponent* l);
        void kill();
};
