#include <cstddef>
#include "PauseState.h"
#include <iostream>
#include <SFML/Window.hpp>

PauseState* PauseState::only_instance = NULL;

void PauseState::update()
{
    std::cout<<"PAUSE"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        std::cout<<"PAUSE"<<std::endl;
    
}