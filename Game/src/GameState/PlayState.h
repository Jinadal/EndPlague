#pragma once
#include "IGameState.h"
#include <vector>
#include "FabricVillage.h"
#include "FabricMine.h"


class Fabric;

class PlayState : public IGameState 
{
    private:
        std::vector<Fabric*> fabrics = {new FabricMine(), new FabricVillage()};
        std::size_t level = 0;
        bool loaded; 
        PlayState(){}         
        Fabric* fabric;
    public:

         static PlayState* getInstance(){
            static PlayState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};