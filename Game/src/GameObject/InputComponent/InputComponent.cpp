#include "InputComponent.h"
#include "ShootComponent.h"

void InputComponent::update(float cursorX, float cursorY)
{
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
}
