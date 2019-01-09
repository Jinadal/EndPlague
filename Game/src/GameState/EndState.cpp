#include <cstddef>
#include "EndState.h"
#include <iostream>
#include <SFML/Window.hpp>

EndState* EndState::only_instance = NULL;

void EndState::update()
{
    std::cout<<"END"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        std::cout<<"END"<<std::endl;
    
}