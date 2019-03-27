#include <cstddef>
#include "IntroState.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "GameValues.h"
#include "SpecificSoundEvent.h"

void IntroState::initState(){
    //RenderIrrlicht::getInstance()->loadIntro();
    AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("musica"));
    m->start();
    SoundSystem::getInstance()->saveEvent(m,"musica");
};

void IntroState::clear(){
    //RenderIrrlicht::getInstance()->closeIntro();
};

void IntroState::update(float dt){
    delta+=dt;
    if(delta>gv::INTRO_DURATION)
    {
        delta = 0;
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        delta = 0;
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }
    
}