#pragma once
#include "Component.h"
#include "GameObject.h"
#include "EnemyFabric.h"
#include "SpawnManager.h"
#include <cmath>

#define cadencia 10.f

class SpawnComponent : public Component{
    private:
        float distance;
        float elapsed = 0.f;
        EnemyType type = ENEMY_1;
    public:
        SpawnComponent(GameObject* owner, Manager* m, float d, EnemyType type) : Component(owner, m)
        {
            distance = d;
            this->type = type;
        }
        ~SpawnComponent(){};

        void update(float elapsedTime);
};

