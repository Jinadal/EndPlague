#pragma once
#include "IGameState.h"

class MenuState : public IGameState 
{
    private:
        MenuState(){}
    public:

        static MenuState* getInstance(){
            static MenuState only_instance;
            return &only_instance;
        }
        
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};