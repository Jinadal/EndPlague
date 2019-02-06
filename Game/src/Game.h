#pragma once
#include "IGameState.h"

class Game
{
    private:;
        IGameState* state;
        static Game* only_instance;  

    public:

        static Game* getInstance(){
            if(!only_instance)
                only_instance = new Game();
            
            return only_instance;
        }

        ~Game()
        {
            only_instance = nullptr;
        }
        void run();
        void setState(IGameState::stateType type);
        void initGame();
};