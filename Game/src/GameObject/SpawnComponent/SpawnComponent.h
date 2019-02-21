#pragma once
#include "Component.h"
#include "EnemyFabric.h"
#include <cstdlib>


#define SPAWN_CADENCIA 10.f

class GameObject;
class SpawnComponent : public Component{
    private:
        float distance;
        float elapsed;
        EnemyType type;
    public:
        SpawnComponent(GameObject* owner, Manager* m, float d, EnemyType type) : Component(owner, m)
        {
            elapsed = static_cast <float> (rand()) / static_cast <float> (SPAWN_CADENCIA);
            distance = d;
            this->type = type;
        }
        ~SpawnComponent(){};

        void update(float elapsedTime);
};

