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

    GameObject* getGameObject()
    {
        return gameobject;

    }
    //void kill();
    private:
      GameObject* gameobject;

    
};