#pragma once
//Headers
#include "Component.h"

class CombatComponent : public Component
{
  public:
    //Constructor
    CombatComponent(GameObject* g):Component(g){}
    
    void update();

    //Destructor
    virtual ~CombatComponent() {}
    protected:
      GameObject* gameobject;
};