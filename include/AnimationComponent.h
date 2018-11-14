#pragma once
//Headers
#include "Component.h"

class AnimationComponent : public Component{
    public:
        //Constructor
        AnimationComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};