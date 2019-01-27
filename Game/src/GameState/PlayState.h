#pragma once
#include "IGameState.h"

enum Levels
{
    LEVEL_VILLAGE,
    LEVEL_TEST
};


class Fabric;

class PlayState : public IGameState 
{
    private:
        bool loaded;
        static PlayState* only_instance;            
        Fabric* fabric;
        Levels level = LEVEL_VILLAGE;

    public:

        static PlayState *getInstance(){
            if(!only_instance)
                only_instance = new PlayState();
                
            return only_instance;
        };


        virtual ~PlayState() {}
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        void setLevel(Levels l){level = l;};
};