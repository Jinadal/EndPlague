#include <cstddef>
#include "ToNextState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "PlayState.h"
#include "LevelLoader.h"
#include "Render.h"
#include "FMenu.h"
#include "SpecificSoundEvent.h"
#include "ToNextMenu.h"

void ToNextState::initState()
{
    type = IGameState::TONEXT;
    SoundSystem::getInstance()->Init();
    
    Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Next.png");
}
void ToNextState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        clear();
        AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("musica"));
        m->start();
        SoundSystem::getInstance()->saveEvent(m,"musica");
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        LevelLoader::getInstance()->resetNext();
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }
}

void ToNextState::clear()
{
    Render::getInstance()->getMenu()->clearBackground();
}