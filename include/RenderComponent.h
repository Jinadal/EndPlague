#pragma once

#include "Component.h"
#include <RenderFacade.h>

class RenderComponent : public Component{
    private:

    public:
        //Constructor
        RenderComponent(GameObject* g):Component(g){}
        
};
