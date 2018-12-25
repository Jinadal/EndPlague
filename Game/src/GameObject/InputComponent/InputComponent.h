#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"
#include "InputFacade.h"
#include "BPhysicComponent.h"
#include <iostream>


class InputComponent : public Component
{

    public:

    //Constructor
    InputComponent(GameObject *owner, Manager* m): Component(owner, m) {}
    
    ~InputComponent(){}




    void pulseInput(float cursorX, float cursorY);



    int w_ = 87, a_ = 65, s_ = 83, d_ = 68, space_=32;
};