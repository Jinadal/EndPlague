#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"


class CollisionComponent : public Component
{

    public:

    //Constructor
    CollisionComponent(GameObject *owner, Manager* m, float width, float height, bool solid): Component(owner, m) , width_(width), height_(height), solid_(solid){}
    
    virtual ~CollisionComponent(){}




    bool testCollision(CollisionComponent *com1);

    void checkCollision(GameObject *obj);

    

    float width_, height_;

    bool solid_;
  
    
};