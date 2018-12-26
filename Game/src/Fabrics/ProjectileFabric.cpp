#include "ProjectileFabric.h"

#define PI 3.14159265

GameObject* ProjectileFabric::createProjectile(float x, float y, float rz, ProjectileType type)
{
    GameObject* r =  gameresource->createGameObject(x, y, -1.f, rz);

    float fx = projectile_types[type].velocity*(-cos(rz*PI/180 - PI/2));
    float fy = projectile_types[type].velocity*(-sin(rz*PI/180 - PI/2));
    float fz = 0.f;
    bphysicmanager->createComponent(r, .7f, .2f, .2f, 10.f, 0);
    r->getComponent<BPhysicComponent>()->setVelocity(fx, fy, fz);
    r->getComponent<BPhysicComponent>()->setGravity(0.f,0.f,0.f);
    rendermanager->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    projectilemanager->createComponent(r, projectile_types[type].damage);

    return r;
}