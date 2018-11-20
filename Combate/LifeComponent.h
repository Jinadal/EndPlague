#pragma once
//Headers
#include <iostream>
#include "Component.h"

class LifeComponent : public Component{
    public:
        //Constructor
        LifeComponent(GameObject* g):Component(g){
            this->life = 5;            
        }
        //Update
        void update();

        //Setter&Getters
        int getLife()       { return life;  };
        void setLife(int l) {  life = l;     };


        //Methods
        void looseLife(int d);

    private:
        int life;
};
