#include <cstddef>
#include "MenuState.h"
#include "Render.h"
#include "FMenu.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "SpecificSoundEvent.h"
#include <chrono>
#include <thread>
#include "MainMenu.h"


void MenuState::initState()
{
    type = IGameState::MENU;
    menu = new MainMenu();

    AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("menumusica"));
    m->start();
    SoundSystem::getInstance()->saveEvent(m,"menumusica");
    
}

void MenuState::update(float dt)
{
    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        SoundEvent* amb;
        switch (menu->click())
        {
            case 1:
                    /* Inicio */
                    amb = SoundSystem::getInstance()->getEvent("menumusica");
                    amb->stop();
                    SoundSystem::getInstance()->deleteEvent(amb,"menumusica");

                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    delete menu;
                    Game::getInstance()->setState(IGameState::stateType::PLAY);
                break;
            case 2:
                /* Opciones */
                break;
            case 3:
                amb = SoundSystem::getInstance()->getEvent("menumusica");
                amb->stop();
                SoundSystem::getInstance()->deleteEvent(amb,"menumusica");
                delete menu;
                Game::getInstance()->setState(IGameState::stateType::CREDITS);
                break;
            case 4:
                amb = SoundSystem::getInstance()->getEvent("menumusica");
                amb->stop();
                SoundSystem::getInstance()->deleteEvent(amb,"menumusica");
                delete menu;
                Render::getInstance()->close();
                break;
            default:
                break;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        menu->up();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        menu->down();

    SoundSystem::getInstance()->Update();

};

void MenuState::clear()
{
    delete menu;
};