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
      std::cout<<"Creando: "<<this<<"\n";
    }

    //Destructor
    virtual ~Component(){
      manager->removeComponent(this);
      std::cout<<"Borrando: "<<this<<"\n";
    }

    //Getter
    GameObject* getGameObject() {
        return gameObject;
    }

    protected:
      GameObject* gameObject;
      Manager* manager;
};
