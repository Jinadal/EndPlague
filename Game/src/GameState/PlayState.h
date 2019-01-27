#pragma once
#include "IGameState.h"

class Fabric;

enum Levels
{
    LEVEL_VILLAGE,
    LEVEL_TEST
};

class PlayState : public IGameState 
{
    private:
        bool loaded;
        static PlayState* only_instance;  
        PlayState(){level = LEVEL_VILLAGE;}         
        Fabric* fabric;  
        Levels level;
    public:

        static PlayState *getInstance(){
            if(only_instance == NULL)
                only_instance = new PlayState();
                
            return only_instance;
        };


        virtual ~PlayState() {}
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        void setLevel(Levels l){level = l;}
};