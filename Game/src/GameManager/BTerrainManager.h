#pragma once
#include "BTerrainComponent.h"

class Manager;
class BTerrainManager : public Manager
{
    private:
        BTerrainManager(){}
        static BTerrainManager* only_instance;
    
    public:
        ~BTerrainManager(){delete only_instance;}
        static BTerrainManager* getInstance()
        {
            if(!only_instance)
                only_instance = new BTerrainManager();

            return only_instance;
        }

        void updateAll(float dt);
        void createComponent(GameObject* owner, char* mesh);
};