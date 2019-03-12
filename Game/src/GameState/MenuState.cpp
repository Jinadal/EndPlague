#include <cstddef>
#include "MenuState.h"
#include "Render.h"
#include "FMenu.h"
#include "Game.h"
#include <SFML/Window.hpp>

void MenuState::initState()
{
    type = IGameState::MENU;
    Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Menu.png");
}

void MenuState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        clear();
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
};

void MenuState::clear()
{
    Render::getInstance()->getMenu()->clearBackground();
};