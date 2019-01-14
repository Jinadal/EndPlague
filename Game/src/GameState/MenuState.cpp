#include <cstddef>
#include "MenuState.h"
#include "Game.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "RenderIrrlicht.h"
#include "RenderManager.h"
//#include "CGUITexturedSkin.h"

MenuState* MenuState::only_instance = NULL;
 IGUIImage* img;
void MenuState::initState()
{
    type = IGameState::MENU;
    IGUIEnvironment* guienv = RenderIrrlicht::getInstance()->getGUIEnv();
    //IVideoDriver::draw2DImage ("../../res/menu-background.jpg", position2d<int>(0,0), position2d<int>(0,0), const rect<s32>, SColor, bool), 
    IGUIImage* img = guienv->addImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"),position2d<int>(0,0));
}
void MenuState::update(float dt)
{

    //std::cout<<"MENU"<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        Game::getInstance()->setState(IGameState::stateType::PLAY);

};

void MenuState::clear()
{

};