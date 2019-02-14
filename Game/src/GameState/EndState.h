#pragma once
#include "IGameState.h"

class EndState : public IGameState 
{
    private:
        EndState(){}

    public:

    static EndState* getInstance(){
        static EndState only_instance;
        return &only_instance;
    }
        

    virtual ~EndState() {}
    virtual void initState(){ type = IGameState::END; };
    virtual void update(float dt);
    virtual void clear(){};
};