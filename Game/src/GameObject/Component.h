#pragma once
//Headers
class GameObject;

class Component{

  public:
    //Constructor
    Component(GameObject* g) : gameObject(g) {}

    //Destructor
    virtual ~Component(){};

    //Getter
    GameObject* getGameObject() {

        return gameObject;

    }

    //Init
    //void init(float dt) = 0;

    //Update
    //void update(void) = 0;

    protected:
      GameObject* gameObject;

};