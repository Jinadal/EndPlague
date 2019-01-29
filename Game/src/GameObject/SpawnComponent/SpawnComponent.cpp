#include "SpawnComponent.h"
#include <iostream>

void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed>cadencia)
    {
        elapsed = 0.f;
        cadencia = 2000.f;

        float x = gameObject->getX() + sin(gameObject->getRZ())*distance;
        float y = gameObject->getY() + cos(gameObject->getRZ())*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        ((SpawnManager*)manager)->createEnemy(x, y, z, rz, type);
    }
}

