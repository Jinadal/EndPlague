#pragma once
//Headers
#include "Component.h"

class SpawnComponent : public Component{
    public:
        //Constructor
        SpawnComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};
