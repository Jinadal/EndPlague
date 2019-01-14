#pragma once
#include "IGameState.h"

class MenuState : public IGameState 
{
    private:
    static MenuState* only_instance;

    public:

    static MenuState *getInstance(){
        if(only_instance == NULL)
            only_instance = new MenuState();
            
        return only_instance;
    };


    virtual ~MenuState() {}
    virtual void initState();
    virtual void update(float dt);
    virtual void clear();
};