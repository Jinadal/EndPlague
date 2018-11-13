#pragma once
//Headers
#include "Component.h"

class ItemComponent : public Component{
    public:
        //Constructor
        ItemComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};