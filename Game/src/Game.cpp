#include <stdlib.h>
#include <stdio.h>
#include "Game.h"

#include "BPhysicManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"

Game* Game::only_instance = NULL;

void Game::run()
{
    initGame();
    fabric->loadLevel();
   
    while(render->run())
    {
        InputManager::getInstance()->setCursorPosition(render->getCursorX(), render->getCursorY());
        //gameManager->update(render->getFrameDeltaTime());

        state->update(render->getFrameDeltaTime());
        render->drawAll();
    }

    delete fabric;
    //delete gameManager;
    delete render;

}

void Game::initGame()
{  
    render              = RenderIrrlicht::getInstance();
    fabric              = new FabricVillage();
    //gameManager         = new GameManager();

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
