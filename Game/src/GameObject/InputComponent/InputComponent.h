#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"
#include "InputFacade.h"
#include <iostream>



class InputComponent : public Component
{

    public:

    //Constructor
    InputComponent(GameObject *owner): Component(owner) {}
    
    ~InputComponent() override {}




    void pulseInput(InputFacade *interface);



    int w_ = 87, a_ = 65, s_ = 83, d_ = 68;

    

     
  
    
};