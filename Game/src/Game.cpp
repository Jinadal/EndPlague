#include <stdlib.h>
#include <stdio.h>
#include "GameManager.h"
#include "FabricVillage.h"
#include "InputManager.h"


int main()
{
    RenderIrrlicht*         render              = RenderIrrlicht::getInstance();
    FabricVillage*          fabric              = new FabricVillage();
    GameManager*            gameManager         = new GameManager();

    fabric->loadLevel();
   
    while(render->run())
    {
        InputManager::getInstance()->setCursorPosition(render->getCursorX(), render->getCursorY());
        gameManager->update(render->getFrameDeltaTime());


        render->drawAll();
    }

    delete fabric;
    delete gameManager;
    delete render;

    return 0;
}