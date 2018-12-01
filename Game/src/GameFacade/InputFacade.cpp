#include "InputFacade.h"


InputFacade* InputFacade::only_instance = NULL;
 
bool InputFacade::OnEvent(const irr::SEvent &event) {  //Recieve event Keyboard - Mouse
    
    if(event.EventType == irr::EET_KEY_INPUT_EVENT){    //If Keyboard
        
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
    if(event.EventType == irr::EET_MOUSE_INPUT_EVENT)   //If Mouse
        {
            switch(event.MouseInput.Event)
            {
            case irr::EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LeftButtonDown = true;
                break;

            case irr::EMIE_LMOUSE_LEFT_UP:
                MouseState.LeftButtonDown = false;
                break;

            case irr::EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;

            default:
                // We won't use the wheel
                break;
            }
        }
    return false; 
}

