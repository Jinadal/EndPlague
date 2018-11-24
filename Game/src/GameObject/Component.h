#pragma once
//Headers
class GameObject;

class Component{

  public:
    //Constructor
    Component(GameObject* g)  {

      gameObject = g;
    }

    //Destructor
    virtual ~Component(){};

    //Getter
    GameObject* getGameObject() {

        return gameObject;

    }

   
  

    protected:
      GameObject* gameObject;

};