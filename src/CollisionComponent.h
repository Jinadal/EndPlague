#pragma once
//Headers
#include "Component.h"

class CollisionComponent : public Component{
    public:
        //Constructor
        CollisionComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};