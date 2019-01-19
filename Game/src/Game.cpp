#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "GameManager.h"
#include "FabricVillage.h"
#include "InputManager.h"
#include "BPhysicManager.h"
#include "MenuState.h"
#include "PauseState.h"
#include "EndState.h"
#include "Waypoint.h"

Game* Game::only_instance = NULL;

void Game::run()
{
    RenderIrrlicht*         render              = RenderIrrlicht::getInstance();
    FabricVillage*          fabric              = new FabricVillage();
    GameManager*            gameManager         = new GameManager();

    initGame();
    fabric->loadLevel();
   
    while(render->run())
    {
        InputManager::getInstance()->setCursorPosition(render->getCursorX(), render->getCursorY());
        gameManager->update(render->getFrameDeltaTime());

        state->update();
        render->drawAll();
    }

    delete fabric;
    delete gameManager;
    delete render;

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
        case IGameState::stateType::PAUSE:
            state = PauseState::getInstance();
            break;
        case IGameState::stateType::END:
            state = EndState::getInstance();
            break;
    }
    state->initState();
}
