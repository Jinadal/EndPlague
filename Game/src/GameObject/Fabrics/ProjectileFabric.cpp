#include "ProjectileFabric.h"

#define PI 3.14159265

GameObject* ProjectileFabric::createProjectile(float x, float y, float rz, ProjectileType type)
{
    GameObject* r =  gameresource->createGameObject(x, y, -1.f, rz);
    movementmanager->createComponent(r);
    r->getComponent<MovementComponent>()->setvMax(projectile_types[type].vMax);

    r->getComponent<MovementComponent>()->setvX(-cos(rz*PI/180 - PI/2));
    r->getComponent<MovementComponent>()->setvY(-sin(rz*PI/180 - PI/2));
    rendermanager->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    collisionmanager->createComponent(r, .7f, .2f, true);
    projectilemanager->createComponent(r, projectile_types[type].damage);

    return r;
}