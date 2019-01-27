#include "SpawnComponent.h"
#include "GameObject.h"
#include <cmath>


void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed>SPAWN_CADENCIA)
    {
        elapsed = 0.f;

        float x = gameObject->getX() - sin(gameObject->getRZ())*distance;
        float y = gameObject->getY() + cos(gameObject->getRZ())*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        EnemyFabric* f = new EnemyFabric();
        f->createEnemy(x, y, z, rz, type);
        delete f;
    }
}

