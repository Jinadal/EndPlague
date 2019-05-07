#include <cstddef>
#include "MenuState.h"
#include "Render.h"
#include "FMenu.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "SpecificSoundEvent.h"

void MenuState::initState()
{
    type = IGameState::MENU;
    Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Initial.png");

    AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("menumusica"));
    m->start();
    SoundSystem::getInstance()->saveEvent(m,"menumusica");
    
}

void MenuState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        clear();
        
        Game::getInstance()->setState(IGameState::stateType::PLAY);
       SoundEvent* amb = SoundSystem::getInstance()->getEvent("menumusica");
       amb->stop();
       SoundSystem::getInstance()->deleteEvent(amb,"menumusica");
    }
    SoundSystem::getInstance()->Update();

};

void MenuState::clear()
{
    Render::getInstance()->getMenu()->clearBackground();
};