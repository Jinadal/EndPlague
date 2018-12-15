#pragma once
#include "GameResource.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "CollisionManager.h"
#include "IAManager.h"
#include "LifeManager.h"

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
                ENEMY_2,
                (char*)"res/Enemyy.obj",
                (char*)"res/red.bmp",
                50.f,
                400.f
            },
            {
                ENEMY_1,
                (char*)"res/Enemyy.obj",
                (char*)"res/geen.bmp",
                80.f,
                600.f
            },
        };
        GameResource*       gameresource        = GameResource::getInstance();
        RenderManager*      rendermanager       = RenderManager::getInstance();
        MovementManager*    movementmanager     = MovementManager::getInstance();
        CollisionManager*   collisionmanager    = CollisionManager::getInstance();
        IAManager*          iamanager           = IAManager::getInstance();
        LifeManager*        lifemanager         = LifeManager::getInstance();

    public:
        EnemyFabric(){}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
};