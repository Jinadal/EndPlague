#pragma once
#include "IGameState.h"
#include <cstddef>

class Game
{
    private:;
        IGameState* state;
        static Game* only_instance;  

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