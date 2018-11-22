#pragma once
//Headers
class GameObject;

class Component{

  public:
    //Constructor
    Component(GameObject& g) : gameObject(g) {}

    //Destructor
    virtual ~Component() = default;

    //Getter
    GameObject& getGameObject() {

        return gameObject;

    }

    //Initializer
    void init();

    //Update
    void update();

    private:
      GameObject& gameObject;

};