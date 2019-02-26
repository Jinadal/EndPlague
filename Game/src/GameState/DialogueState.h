#pragma once
#include "IGameState.h"
#include <stack>

class DialogueState : public IGameState 
{
    private:
        DialogueState(){}
    public:

    static DialogueState* getInstance(){
        static DialogueState only_instance;
        return &only_instance;
    }
        

    ~DialogueState() {}
    void initState();
    void update(float dt);
    void clear(){};
};