#pragma once
//Headers
#include "Component.h"

class ProjectileComponent : public Component{
    public:
        //Constructor
        ProjectileComponent(GameObject* g):Component(g){
            damage = 1;
        }
        //Update
        void update();

        //Setter&Getter
        int getDamage()         {   return damage   ;}
        void setDamager(int d)  {   damage = d      ;}

        //Methods
        void dealDamage(GameObject* v);
    private:
    int damage;
    
};
