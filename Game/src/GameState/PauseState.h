#pragma once
#include "IGameState.h"

class PauseState : public IGameState 
{
    private:
    static PauseState* only_instance;
    

    public:

    static PauseState *getInstance(){
            if(!only_instance)
                only_instance = new PauseState();
            
            return only_instance;
        }
;

    virtual ~PauseState() {}
    virtual void initState();
    virtual void update(float dt);
    virtual void clear(){};
};