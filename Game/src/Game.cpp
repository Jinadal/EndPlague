#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "Render.h"
#include "Clock.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"
#include "IntroState.h"
#include "DialogueState.h"
#include "NextLevelState.h"
#include "SoundSystem.h"

void Game::run()
{
    initGame();

    Clock clock;
    while(Render::getInstance()->run())
    {
        if(clock.canContinue())
        {
            state->update(clock.getElapsedTime());
            Render::getInstance()->drawAll();
        }
    }
}

void Game::initGame()
{  
    SoundSystem::getInstance()->Init();

    setState(IGameState::stateType::INTRO);
}

void Game::setState(IGameState::stateType type)
{
    switch(type)
    {
        case IGameState::stateType::MENU:
            state = MenuState::getInstance();
            break;
        case IGameState::stateType::PLAY:
            state = PlayState::getInstance();
            break;
        case IGameState::stateType::PAUSE:
            state = PauseState::getInstance();
            break;
        case IGameState::stateType::END:
            state = EndState::getInstance();
            break;
        case IGameState::stateType::INTRO:
            state = IntroState::getInstance();
            break;
        case IGameState::stateType::DIALOGUE:
            state = DialogueState::getInstance();
            break;
        case IGameState::stateType::NEXTLEVEL:
            state = NextLevelState::getInstance();
            break;
    }
    state->initState();
}
