#pragma once

#include <iostream>
#include "../GameObject/InputComponent.h"

class InputManager{

    //Constructor
    InputManager() {}

    //Destructor
    ~InputManager() {}

    //Init
    void init();

    //Update
    void update();

    //Close
    void close();

    private:

    Component::Pointer inputComponent;

}