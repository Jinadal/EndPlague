#pragma once
#include "IGameState.h"

class PauseState : public IGameState 
{
    private:
    static PauseState* only_instance;

    public:

    static PauseState *getInstance(){
            if(only_instance == NULL)
                only_instance = new PauseState();
            
            return only_instance;
        }
;

    virtual ~PauseState() {}
    virtual void initState(){ type = IGameState::PAUSE; };
    virtual void update(float dt);
};