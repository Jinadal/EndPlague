#pragma once
#include "IGameState.h"

class PauseState : public IGameState 
{
    private:
    static PauseState* only_instance;
    PauseState():IGameState(){};

    public:

    static PauseState *getInstance(){
            if(only_instance == NULL)
                only_instance = new PauseState();
            
            return only_instance;
        }
;

    virtual ~PauseState() {}
    virtual void initState();
    virtual void update(float dt);
    virtual void clear(){};
};