#include "ProjectileFabric.h"



GameObject* ProjectileFabric::createProjectile(float x, float y, float z, float rz, ProjectileType type)
{
    GameObject* r =  gameresource->createGameObject(x, y, x, rz);
    movementmanager->createComponent(r);
    r->getComponent<MovementComponent>()->setvMax(projectile_types[type].vMax);

    r->getComponent<MovementComponent>()->setvX(cos(rz));
    r->getComponent<MovementComponent>()->setvY(sin(rz));
    rendermanager->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    collisionmanager->createComponent(r, 30.f, 30.f, true);
    projectilemanager->createComponent(r, projectile_types[type].damage);

    return r;
}