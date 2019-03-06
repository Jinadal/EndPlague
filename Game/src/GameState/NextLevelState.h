#pragma once
#include "IGameState.h"

class NextLevelState : public IGameState 
{
    private:
        NextLevelState(){}

    public:

    static NextLevelState* getInstance(){
        static NextLevelState only_instance;
        return &only_instance;
    }
        

    ~NextLevelState() {}
    void initState();
    void update(float dt);
    void clear(){};
};