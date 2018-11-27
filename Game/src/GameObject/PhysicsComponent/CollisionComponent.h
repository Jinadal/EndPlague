#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"


class CollisionComponent : public Component
{

    public:

    //Constructor
    CollisionComponent(GameObject *owner, float width, float height, bool solid): Component(owner) , width_(width), height_(height), solid_(solid){}
    
    ~CollisionComponent() override {}




    bool testCollision(CollisionComponent *com1);

    void checkCollision(GameObject *obj);

    

    float width_, height_;

    bool solid_;
  
    
};