#include "ProjectileFabric.h"



GameObject* ProjectileFabric::createProjectile(float x, float y, float rz, ProjectileType type)
{
    GameObject* r =  gameresource->createGameObject(x, y, 10.f, rz);
    movementmanager->createComponent(r);
    r->getComponent<MovementComponent>()->setvMax(projectile_types[type].vMax);

    r->getComponent<MovementComponent>()->setvX(sin(rz));
    r->getComponent<MovementComponent>()->setvY(cos(rz));
    rendermanager->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    collisionmanager->createComponent(r, 30.f, 30.f, true);
    projectilemanager->createComponent(r, projectile_types[type].damage);

    return r;
}