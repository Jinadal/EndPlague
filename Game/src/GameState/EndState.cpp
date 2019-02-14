#include <cstddef>
#include "EndState.h"
#include "Game.h"
#include <SFML/Window.hpp>

void EndState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        Game::getInstance()->setState(IGameState::stateType::MENU);
    
}