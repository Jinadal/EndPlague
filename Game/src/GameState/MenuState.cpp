#include <cstddef>
#include "MenuState.h"
#include "MenuFacade.h"
#include "Game.h"
#include <iostream>
#include <SFML/Window.hpp>
//#include "CGUITexturedSkin.h"

MenuState* MenuState::only_instance = NULL;
void MenuState::initState()
{
    type = IGameState::MENU;
    MenuFacade::getInstance()->setMenuBackground();
    MenuFacade::getInstance()->createButton(0,210,100,240,101);
}
void MenuState::update(float dt)
{
    //std::cout<<"MENU"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        clear();
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
};

void MenuState::clear()
{
    MenuFacade::getInstance()->clearBackground();
};