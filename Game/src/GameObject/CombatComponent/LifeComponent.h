#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"

class LifeComponent : public Component{
     private:
        float life;

    public:
        //Constructor
        LifeComponent(GameObject* g, Manager* m, float f):Component(g, m){
            this->life = f;            
        }
        ~LifeComponent(){}

        //Setter&Getters
        float getLife()       {return life;};
        void setLife(float l) {life = l;};


        //Methods
        void looseLife(float d);  //Gets by parametre a int damage from the attacker

   
};
