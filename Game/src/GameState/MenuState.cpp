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
    menu = new MainMenu();

    AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("musica"));
    m->start();
    SoundSystem::getInstance()->saveEvent(m,"musica");
    
}

void MenuState::update(float dt)
{
    //Render::getInstance()->getMenu()->update();
    menu->update();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (menu->click())
        {
            case 1:
                /* Inicio */
                    delete menu; 
                    Game::getInstance()->setState(IGameState::stateType::PLAY);
                break;
            case 2:
                /* Opciones */
                break;
            case 3:
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
    Render::getInstance()->getMenu()->clearBackground();
};