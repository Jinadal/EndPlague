#pragma once
//Headers
#include "Component.h"

class PhysicComponent : public Component{
    public:
        //Constructor
        PhysicComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};