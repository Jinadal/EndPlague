#pragma once
#include "IGameState.h"

class EndState : public IGameState 
{
    private:
    static EndState* only_instance;

    public:

    static EndState *getInstance(){
            if(only_instance == NULL)
                only_instance = new EndState();
            
            return only_instance;
        }
;

    virtual ~EndState() {}
    virtual void initState(){ type = IGameState::END; };
    virtual void update(float dt);
    virtual void clear(){};
};