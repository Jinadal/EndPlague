#pragma once
//Headers
#include "Component.h"

class CollisionComponent : public Component{
    public:
        //Constructor
        CollisionComponent(GameObject* g, float width, float height, bool solid):Component(g) , width_(width), height_(height), solid_(solid){}
        //Update
        void update();


        float width_, height_;

        bool solid_;

    
};