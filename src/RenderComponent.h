#pragma once
//Headers
#include "Component.h"

class RenderComponent : public Component{
    public:
        //Constructor
        RenderComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};
