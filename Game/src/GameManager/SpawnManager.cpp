#include "SpawnManager.h"


SpawnManager* SpawnManager::only_instance = NULL;

void SpawnManager::createComponent(GameObject* owner, float distance, EnemyType type)
{
    components.push_back(new SpawnComponent(owner, this, distance, type));
    owner->addComponent(components[components.size() - 1]);
}

void SpawnManager::createEnemy(float x, float y, float z, float rz, EnemyType type)
{
    fabric->createEnemy(x, y, z, rz, type);
}


void SpawnManager::updateAll(float dt)
{
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((SpawnComponent*)components[i])->update(dt);
    }
}


bool SpawnManager::canCreate()
{
    std::cout<<"Emenigos: "<<fabric->getNumEnemies()<< " MaxEnemigos: "<<MAX_ENEMIES<<"\n";
    if(fabric->getNumEnemies()<MAX_ENEMIES)
        return true;


    return false;

}