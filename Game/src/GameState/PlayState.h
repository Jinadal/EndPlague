#pragma once
#include "IGameState.h"

class Fabric;

class PlayState : public IGameState 
{
    private:
        bool loaded;
        static PlayState* only_instance;  
        PlayState(){}         
        Fabric* fabric;
    public:

        static PlayState *getInstance(){
            if(only_instance == NULL)
                only_instance = new PlayState();
                
            return only_instance;
        };


        virtual ~PlayState() {}
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};