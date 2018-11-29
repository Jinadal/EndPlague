#pragma once
#include "Manager.h"


class GameObject;
class Component{

  public:
    //Constructor
    Component(GameObject* g, Manager* m)  {
      manager = m;
      gameObject = g;
    }

    //Destructor
    virtual ~Component(){};

    //Getter
    GameObject* getGameObject() {

        return gameObject;

    }
    
    void kill(){
      manager->removeComponent(this);
    }

    protected:
      GameObject* gameObject;
      Manager* manager;

};