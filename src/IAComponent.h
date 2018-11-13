#pragma once
//Headers
#include "Component.h"

class IAComponent : public Component
{
  public:
    //Constructor
    IAComponent(GameObject* g):Component(g){}
    //Update
    void update();
    
    //Destructor
    virtual ~IAComponent() {}
    protected:
      GameObject* gameobject;
};