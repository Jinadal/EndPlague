#pragma once
#include "IGameState.h"

class ToNextState : public IGameState 
{
    private:
        ToNextState(){}

    public:

    static ToNextState* getInstance(){
        static ToNextState only_instance;
        return &only_instance;
    }
        

    ~ToNextState() {}
    void initState();
    void update(float dt);
    void clear(){};
};