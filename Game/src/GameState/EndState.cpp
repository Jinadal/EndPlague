#include <cstddef>
#include "EndState.h"
#include "Game.h"
#include <iostream>
#include <SFML/Window.hpp>

EndState* EndState::only_instance = NULL;

void EndState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        Game::getInstance()->setState(IGameState::stateType::MENU);
    
}