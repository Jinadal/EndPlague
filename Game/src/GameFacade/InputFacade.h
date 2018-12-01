#pragma once

#include <irrlicht.h>
#include "IInputFacade.h"

struct SMouseState
{
    irr::core::position2di Position;
    bool LeftButtonDown;
};

class InputFacade: public IInputFacade, public irr::IEventReceiver {
private:
    // We use this array to store the current state of each key
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
    SMouseState MouseState;
    static InputFacade* only_instance;
    InputFacade(){
        for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
        KeyIsDown[i] = 0;  
    }
public:

    //DESTRUCTOR
    virtual ~InputFacade(){only_instance=NULL;}
    
    static InputFacade* getInstance(){
        if(only_instance==NULL){
            only_instance = new InputFacade();
        }
        return only_instance;
    }

    
    //************************
    //IRRLICHT RELATED METHODS
    //************************

    bool OnEvent(const irr::SEvent& event);
    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const{
        return KeyIsDown[keyCode];
    }
};