#pragma once
//Headers
#include "Component.h"

class InputComponent : public Component{
    public:
        //Constructor
        InputComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};