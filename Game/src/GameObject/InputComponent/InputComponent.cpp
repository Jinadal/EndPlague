#include "InputComponent.h"
#include "InputFacade.h"
#include "ShootComponent.h"
#include <irrlicht.h>

void InputComponent::pulseInput(float cursorX, float cursorY)
{
    InputFacade* interface = InputFacade::getInstance();

    int enX = 0, enY = 0;

    if(interface->IsKeyDown((irr::EKEY_CODE)w_)){
        enY+=1;
    }    
    if(interface->IsKeyDown((irr::EKEY_CODE)a_)){
        enX-=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)s_)){
        enY-=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)d_)){
        enX+=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)d_)){
        enX+=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)space_)){
        if(gameObject->getComponent<ShootComponent>()!=nullptr)
        gameObject->getComponent<ShootComponent>()->shoot();
    }

    if(gameObject->getComponent<BPhysicComponent>()!=nullptr){
        gameObject->getComponent<BPhysicComponent>()->moveObject(enX ,enY, 0.f, cursorX, cursorY);
    }
}
