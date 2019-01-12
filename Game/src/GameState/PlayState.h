#pragma once
#include "IGameState.h"

class PlayState : public IGameState 
{
    private:
    static PlayState* only_instance;

    public:

    static PlayState *getInstance(){
        if(only_instance == NULL)
            only_instance = new PlayState();
            
        return only_instance;
    };


    virtual ~PlayState() {}
    virtual void initState(){ type = IGameState::PLAY; };
    virtual void update(float dt);
};