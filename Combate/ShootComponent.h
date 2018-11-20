#pragma once
//Headers
#include "Component.h"

class ShootComponent : public Component{
    public:
        //Constructor
        ShootComponent(GameObject* g):Component(g){}

        //Setter&Getters
        bool getShooted()       {  return shooted;}
        void setShooted(bool s) {  shooted = s;}
        //Methods
        void Shoot();



    private:
    bool shooted = false;
};
