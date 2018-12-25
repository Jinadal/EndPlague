#include "ProjectileFabric.h"

#define PI 3.14159265

GameObject* ProjectileFabric::createProjectile(float x, float y, float rz, ProjectileType type)
{
    GameObject* r =  gameresource->createGameObject(x, y, -1.f, rz);
    bphysicmanager->createComponent(r, .7f, .2f, .2f, 10.f, 1);
    //r->getComponent<BPhysicComponent>()->applyForce(  projectile_types[type]outputforce*(-cos(rz*PI/180 - PI/2)), 
    //                                                    projectile_types[type]outputforce*(-sin(rz*PI/180 - PI/2))
    //                                                        10.f);


    rendermanager->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    projectilemanager->createComponent(r, projectile_types[type].damage);

    return r;
}