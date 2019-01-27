#pragma once
#include "Component.h"

class GameObject;
class InputComponent : public Component
{

    public:

    //Constructor
    InputComponent(GameObject *owner, Manager* m): Component(owner, m) {}
    
    ~InputComponent(){}

    void update(float cursorX, float cursorY);
};