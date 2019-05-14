#include "InputComponent.h"
#include "ShootComponent.h"
#include "GameObject.h"
#include "BPhysicComponent.h"
#include "CameraComponent.h"
#include <SFML/Window.hpp>
#include "GameValues.h"
#include "KATRender.h"
#include "TCamera.h"
#include <iostream>
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

  /**  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
   *     libre = !libre;
   */
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(gameObject->getComponent<ShootComponent>())
        gameObject->getComponent<ShootComponent>()->shoot();
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
        if(gameObject->getComponent<CameraComponent>())
        gameObject->getComponent<CameraComponent>()->setZoom(gv::CAMERA_ZOOM_VEL);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        if(gameObject->getComponent<CameraComponent>())
        gameObject->getComponent<CameraComponent>()->setZoom(-gv::CAMERA_ZOOM_VEL);
    }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        if(press>4)
        {
            if(gameObject->getComponent<CameraComponent>())
            gameObject->getComponent<CameraComponent>()->setOrtho();
            proyec = !proyec;
            ((TCamera*)((KATRender*)Render::getInstance()->getRender())->getKatana()->getNodeCamera()->getEntity())->switchProyection(proyec);
            press = 0;
        }
        press++;
        std::cout<<press << "\n";

    }
/*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
        if(gameObject->getComponent<CameraComponent>())
        gameObject->getComponent<CameraComponent>()->setOrtho();
    }
*/
    if(gameObject->getComponent<BPhysicComponent>()!=nullptr){
      //  if(!libre){
            gameObject->getComponent<BPhysicComponent>()->moveObject(enX ,enY, 0.f, cursorX, cursorY);

   /*     }else{
    *       gameObject->getComponent<CameraComponent>()->moveObject(enX ,enY, 0.f, cursorX, cursorY);
    *    }
    */ 
    }
}
