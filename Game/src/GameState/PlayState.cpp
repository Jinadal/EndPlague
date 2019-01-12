#include <cstddef>
#include "PlayState.h"
#include <iostream>
#include <SFML/Window.hpp>

PlayState* PlayState::only_instance = NULL;

void PlayState::update(float dt)
{
    std::cout<<"PLAY"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        std::cout<<"PLAY"<<std::endl;
    
}