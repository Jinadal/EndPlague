#include <cstddef>
#include "PauseState.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "Game.h"

PauseState* PauseState::only_instance = NULL;
void PauseState::initState()
{
    type = IGameState::PAUSE;
}
void PauseState::update(float dt)
{
    std::cout<<"PAUSE"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
    
}