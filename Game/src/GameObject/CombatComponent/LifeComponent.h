#pragma once
//Headers
#include "Component.h"

class LifeComponent : public Component{
     private:
        float life;

    public:
        //Constructor
        LifeComponent(GameObject* g, float f):Component(g){
            this->life = f;            
        }

        //Setter&Getters
        float getLife()       {return life;};
        void setLife(float l) {life = l;};


        //Methods
        bool looseLife(float d);  //Gets by parametre a int damage from the attacker

   
};
