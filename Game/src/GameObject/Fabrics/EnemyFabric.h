#pragma once
#include "GameResource.h"

enum EnemyType
{
    ENEMY_1,
    ENEMY_2
};

struct Type{
    EnemyType type;
    char* mesh;
    char* texture;
};

Type enemytypes [2] = 
{
    {
        ENEMY_2,
        (char*)"res/Enemyy.obj",
        (char*)"res/red.bmp"
    },
    {
        ENEMY_1,
        (char*)"res/Enemyy.obj",
        (char*)"res/geen.bmp"
    },
};

class EnemyFabric
{
    private:
    public:
        EnemyFabric(){}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
};