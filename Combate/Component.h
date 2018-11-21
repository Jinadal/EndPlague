#pragma once
//Headers
class GameObject;

class Component
{
  public:
    //Constructor
    Component(GameObject* g)
    {
      gameobject=g;
    }
    //Destructor
    virtual ~Component() {}
    protected:
      GameObject* gameobject;
};