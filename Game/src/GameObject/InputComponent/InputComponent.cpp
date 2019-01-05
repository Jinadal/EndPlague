#include "InputComponent.h"
//#include "InputFacade.h"
#include "ShootComponent.h"
//#include <irrlicht.h>

void InputComponent::update(float cursorX, float cursorY)
{
    //InputFacade* interface = InputFacade::getInstance();

    int enX = 0, enY = 0;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        enY+=1;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        enX-=1;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        enY-=1;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        enX+=1;



    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(gameObject->getComponent<ShootComponent>()!=nullptr)
        gameObject->getComponent<ShootComponent>()->shoot();
    }

    if(gameObject->getComponent<BPhysicComponent>()!=nullptr){
        gameObject->getComponent<BPhysicComponent>()->moveObject(enX ,enY, 0.f, cursorX, cursorY);
    }


    /*
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
    */
}
