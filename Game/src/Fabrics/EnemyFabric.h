#pragma once
#include "GameValues.h"

class GameObject;


enum EnemyType
{
    ENEMY_1,
    ENEMY_2
};

struct EType{
    EnemyType type;
    char* mesh;
    char* texture;
    float life;
    float vMax;
};

class EnemyFabric
{
    private:
        EType enemytypes [2] = 
        {
            {
                ENEMY_1,
                (char*)"res/DOOMIE.obj",
                (char*)"res/red.bmp",
                gv::ENEMY_1_LIFE,
                gv::ENEMY_1_VELOCITY
            },
            {
                ENEMY_2,
                (char*)"res/DOOMIE.obj",
                (char*)"res/green.bmp",
                gv::ENEMY_2_LIFE,
                gv::ENEMY_2_VELOCITY
            },
        };

    public:
        EnemyFabric(){}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
};