#pragma once
#include "Component.h"
#include "GameObject.h"
#include "EnemyFabric.h"
#include "SpawnManager.h"
#include <cmath>


class SpawnComponent : public Component{
    private:
        float distance;
        float cadencia = 2.f;
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

