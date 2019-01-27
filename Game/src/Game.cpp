#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "RenderIrrlicht.h"

#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"


Game* Game::only_instance = NULL;

void Game::run()
{
    initGame();
   
    while(RenderIrrlicht::getInstance()->run())
    {
        state->update(RenderIrrlicht::getInstance()->getFrameDeltaTime());
        RenderIrrlicht::getInstance()->drawAll();
    }
    delete RenderIrrlicht::getInstance();
}

void Game::initGame()
{  
    setState(IGameState::stateType::MENU);
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
    }
    state->initState();
}
