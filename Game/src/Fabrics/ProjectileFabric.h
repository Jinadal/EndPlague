#pragma once

class GameObject;

enum ProjectileType
{
    PROJECTILE_1,
    PROJECTILE_2
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
        PType projectile_types[2] = 
        {
            {
                PROJECTILE_1,
                (char*)"res/FLECHA.obj",
                (char*)"res/green.bmp",
                10.f,
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