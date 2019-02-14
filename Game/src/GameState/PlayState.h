#pragma once
#include "IGameState.h"

class Fabric;

class PlayState : public IGameState 
{
    private:
        bool loaded; 
        PlayState(){}         
        Fabric* fabric;
    public:

         static PlayState* getInstance(){
            static PlayState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};