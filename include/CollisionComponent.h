#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"
#include <iostream>



class CollisionComponent : public Component
{

    public:

    //Constructor
    CollisionComponent(GameObject *owner, float width, float height, bool solid): Component(owner) , width_(width), height_(height), solid_(solid){}
    
    ~CollisionComponent() override { 
        std::cout << "Hola soy un mierda y me destruyo \n";
    }

    float width_, height_;

    bool solid_;

    
};