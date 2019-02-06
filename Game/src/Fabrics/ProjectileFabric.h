#pragma once

class GameObject;

enum ProjectileType
{
    PARROW,
    PAXE,
    PPEAK
};

struct PType{
    ProjectileType type;
    char* mesh;
    char* texture;
    float velocity;
    float damage;
};


class ProjectileFabric
{
    private:
        PType projectile_types[3] = 
        {
            {
                PARROW,
                (char*)"res/FLECHA.obj",
                (char*)"res/green.bmp",
                10.f,
                10.f
            },
            {
                PAXE,
                (char*)"res/HACHA.obj",
                (char*)"res/green.bmp",
                10.f,
                50.f
            },
            {
                PPEAK,
                (char*)"res/HACHA.obj",
                (char*)"res/green.bmp",
                10.f,
                50.f
            }
        };

    public:
        ProjectileFabric(){}
        virtual ~ProjectileFabric(){}

        GameObject* createProjectile(float x, float y, float rz, ProjectileType type);
};