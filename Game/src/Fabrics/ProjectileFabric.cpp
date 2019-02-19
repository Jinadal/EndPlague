#include "ProjectileFabric.h"
#include "BPhysicComponent.h"
#include "RenderManager.h"
#include "GameResource.h"
#include "GameObject.h"
#include "BPhysicManager.h"
#include "ProjectileManager.h"
#include "GameObject.h"

#define PI 3.14159265

GameObject* ProjectileFabric::createProjectile(float x, float y, float rz, ProjectileType type)
{
    GameObject* r =  GameResource::getInstance()->createGameObject(x, y, -1.f, rz);

   // float fx = projectile_types[type].velocity*(-cos(rz*PI/180 - PI/2));
   // float fy = projectile_types[type].velocity*(-sin(rz*PI/180 - PI/2));
   // float fz = 0.f;
    BPhysicManager::getInstance()->createComponent(r, .7f, .2f, .2f, 10.f, 0);
    r->getComponent<BPhysicComponent>()->setvMax(projectile_types[type].velocity);
    r->getComponent<BPhysicComponent>()->setVelocity(rz);
    r->getComponent<BPhysicComponent>()->setGravity(0.f,0.f,0.f);
    RenderManager::getInstance()->createComponent(r, projectile_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(projectile_types[type].texture);
    ProjectileManager::getInstance()->createComponent(r, projectile_types[type].damage);

    return r;
}