#pragma once
#include "IGameState.h"
#include <cstddef>
//#include "GameManager.h"
#include "FabricVillage.h"
#include "InputManager.h"
#include "RenderIrrlicht.h"
class Game
{
    private:
        RenderIrrlicht*         render;              
        FabricVillage*          fabric;  
        IGameState* state;
        static Game* only_instance;
                   
        //GameManager*            gameManager;         

    public:

        static Game* getInstance(){
            if(only_instance == NULL)
                only_instance = new Game();
            
            return only_instance;
        }

        ~Game()
        {
            only_instance = NULL;
        }
        void run();
        void setState(IGameState::stateType type);
        void initGame();
};