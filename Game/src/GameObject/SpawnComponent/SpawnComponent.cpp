#include "SpawnComponent.h"
#include "GameObject.h"
#include <cmath>
#define PI 3.1416

void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed>SPAWN_CADENCIA)
    {
        elapsed = 0.f;
      

        float x = gameObject->getX() - cos(gameObject->getRZ()*PI/180 - PI/2)*distance;
        float y = gameObject->getY() - sin(gameObject->getRZ()*PI/180 - PI/2)*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        EnemyFabric* f = new EnemyFabric();
        f->createEnemy(x, y, z, rz, type);
        delete f;
    } 
}

