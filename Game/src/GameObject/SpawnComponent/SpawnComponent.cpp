#include "SpawnComponent.h"

void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed<cadencia)
    {
        elapsed = 0.f;

        float x = gameObject->getX() + cos(gameObject->getRZ())*distance;
        float y = gameObject->getY() + sin(gameObject->getRZ())*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        ((SpawnManager*)manager)->createEnemy(x, y, z, rz, type);
    }
}

