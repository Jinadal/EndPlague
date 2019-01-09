#include <cstddef>
#include "MenuState.h"
#include "Game.h"
#include <iostream>
#include <SFML/Window.hpp>

MenuState* MenuState::only_instance = NULL;

void MenuState::update()
{
    std::cout<<"MENU"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);

};