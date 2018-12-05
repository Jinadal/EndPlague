#pragma once
#include "Manager.h"
#include <iostream>
class GameObject;
class Component{

  public:
    //Constructor
    Component(GameObject* g, Manager* m)  {
      manager = m;
      gameObject = g;
    }

    //Destructor
    virtual ~Component(){
      manager->removeComponent(this);
    }

    //Getter
    GameObject* getGameObject() {
        return gameObject;
    }

    protected:
      GameObject* gameObject;
      Manager* manager;
};
