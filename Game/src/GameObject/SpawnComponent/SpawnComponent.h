#pragma once
#include "Component.h"
#include "EnemyFabric.h"


#define SPAWN_CADENCIA 10.f

class GameObject;
class SpawnComponent : public Component{
    private:
        float distance;
        float elapsed = 0.f;
        EnemyType type;
    public:
        SpawnComponent(GameObject* owner, Manager* m, float d, EnemyType type) : Component(owner, m)
        {
            distance = d;
            this->type = type;
        }
        ~SpawnComponent(){};

        void update(float elapsedTime);
};

