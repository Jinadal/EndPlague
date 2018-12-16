#pragma once
#include "EnemyFabric.h"
#include "SpawnComponent.h"

class Manager;
class SpawnManager : public Manager
{
    private:
        SpawnManager(){};
        static SpawnManager* only_instance;
        EnemyFabric* fabric = new EnemyFabric();
    public:
        ~SpawnManager(){delete fabric; only_instance = NULL;};
        static SpawnManager* getInstance()
        {
            if(only_instance==NULL)
                only_instance = new SpawnManager();

            return only_instance;
        }


        void createComponent(GameObject* owner, float distance, EnemyType type);
        void createEnemy(float x, float y, float z, float rz, EnemyType type);
        void updateAll(float dt);
};