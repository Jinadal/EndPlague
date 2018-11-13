#pragma once
//Headers
#include "IAComponent.h"

class BraveryIAComponent : public IAComponent{
    public:
        //Constructor
        BraveryIAComponent(GameObject* g):IAComponent(g){}
        //Update
        void update();

    private:
};
