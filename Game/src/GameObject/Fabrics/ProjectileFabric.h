#pragma once
#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "CollisionManager.h"
#include "ProjectileManager.h"


enum ProjectileType
{
    PROJECTILE_1,
    PROJECTILE_2
};

struct PType{
    ProjectileType type;
    char* mesh;
    char* texture;
    float vMax;
    float damage;
};


class ProjectileFabric
{
    private:
        GameResource*       gameresource        = GameResource::getInstance();
        MovementManager*    movementmanager     = MovementManager::getInstance();
        RenderManager*      rendermanager       = RenderManager::getInstance();
        CollisionManager*   collisionmanager    = CollisionManager::getInstance();
        ProjectileManager*  projectilemanager   = ProjectileManager::getInstance();



        PType projectile_types[2] = 
        {
            {
                PROJECTILE_1,
                (char*)"res/FLECHA.obj",
                (char*)"res/green.bmp",
                20.f,
                10.f
            },
            {
                PROJECTILE_2,
                (char*)"res/HACHA.obj",
                (char*)"res/green.bmp",
                20.f,
                50.f
            }
        };

    public:
        ProjectileFabric(){}
        virtual ~ProjectileFabric(){}

        GameObject* createProjectile(float x, float y, float rz, ProjectileType type);
};