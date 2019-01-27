#include "SpawnComponent.h"
#define PI 3.14159

void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed>cadencia)
    {
        elapsed = 0.f;

        float x = gameObject->getX() -cos(-PI/2 + gameObject->getRZ()*PI/180)*distance;
        float y = gameObject->getY() -sin(-PI/2 + gameObject->getRZ()*PI/180)*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        ((SpawnManager*)manager)->createEnemy(x, y, z, rz, type);
    }
}

