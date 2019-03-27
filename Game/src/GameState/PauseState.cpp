#include <cstddef>
#include "PauseState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "SpecificSoundEvent.h"


void PauseState::initState()
{
    type = IGameState::PAUSE;

    AmbientSoundEvent* s = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("ambiente");

    s->pause();
}
void PauseState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        AmbientSoundEvent* s = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("ambiente");

        s->start();
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
    
}