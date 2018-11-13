#pragma once
//Headers
#include "Component.h"

class AudioComponent : public Component{
    public:
        //Constructor
        AudioComponent(GameObject* g):Component(g){}
        //Update
        void update();

    private:
};