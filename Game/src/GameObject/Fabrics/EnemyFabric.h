#pragma once
#include "GameResource.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "CollisionManager.h"
#include "IAManager.h"
#include "LifeManager.h"
#include "ShootManager.h"

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
                (char*)"res/green.bmp",
                50.f,
                1.4f  //Velocidad media andando
            },
            {
                ENEMY_2,
                (char*)"res/DOOMIE.obj",
                (char*)"res/green.bmp",
                100.f,
                2.f
            },
        };
        GameResource*       gameresource        = GameResource::getInstance();
        RenderManager*      rendermanager       = RenderManager::getInstance();
        MovementManager*    movementmanager     = MovementManager::getInstance();
        CollisionManager*   collisionmanager    = CollisionManager::getInstance();
        IAManager*          iamanager           = IAManager::getInstance();
        LifeManager*        lifemanager         = LifeManager::getInstance();
        ShootManager*       shootmanager        = ShootManager::getInstance();
        ProjectileManager*  proyectilemanager   = ProjectileManager::getInstance();


    public:
        EnemyFabric(){}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
};