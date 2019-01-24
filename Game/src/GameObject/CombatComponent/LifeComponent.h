#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"

class LifeComponent : public Component{
     private:
        float life;
        float shield;

    public:
        //Constructor
        LifeComponent(GameObject* g, Manager* m, float f):Component(g, m){
            this->life = f;
            this->shield = 0.f; //El escudo, es n valor entre 0-1 que determina que porcentaje de daño se reduce
        }
        ~LifeComponent(){}

        //Setter&Getters
        float getLife() {return life;}
        void setLife(float l) {life = l;}
        float getShield(){return shield;}
        void setShield(float s){shield=s;}


        //Methods
        void looseLife(float d);  //Gets by parametre a int damage from the attacker
        void addLife(float l);
   
};
