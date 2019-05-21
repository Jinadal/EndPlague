#pragma once
#include "Component.h"

class GameObject;
class InputComponent : public Component
{
    private:
        bool walking = false;
    public:
    bool proyec = false;
    //Constructor
    InputComponent(GameObject *owner, Manager* m): Component(owner, m) {}
    
    ~InputComponent(){}

   //->cambio bool libre = false;
    void update(float cursorX, float cursorY);
};