#include <cstddef>
#include "PauseState.h"
#include <SFML/Window.hpp>
#include "Game.h"

PauseState* PauseState::only_instance = NULL;
void PauseState::initState()
{
    type = IGameState::PAUSE;
}
void PauseState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
    
}