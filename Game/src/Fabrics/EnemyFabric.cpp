#include "EnemyFabric.h"

#include "GameResource.h"
#include "RenderManager.h"
#include "BPhysicManager.h"
#include "IAManager.h"
#include "LifeManager.h"
#include "ShootManager.h"
#include "ScoreManager.h"

GameObject* EnemyFabric::createEnemy(float x, float y, float z, float rz, EnemyType type)
{
    if(ScoreManager::getInstance()->getEnemies()>MAX_ENEMIES)
        return NULL;

    
    //ADDING A ENEMY
    GameObject* primero = GameResource::getInstance()->createGameObject(x, y, z, rz);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(primero, enemytypes[type].mesh);//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture(enemytypes[type].texture);//Path de bmp
    BPhysicManager::getInstance()->createComponent(primero, .5f, .5f, 1.f, 100.f, 0);
    primero->getComponent<BPhysicComponent>()->setvMax(enemytypes[type].vMax);
    ScoreManager::getInstance()->createComponent(primero, 10);
    IAManager::getInstance()->createComponent(primero);
    primero->getComponent<IAComponent>()->Initialice();
    LifeManager::getInstance()->createComponent(primero, enemytypes[type].life);//Vida
    ShootManager::getInstance()->createComponent(primero, .9f, 2.f, PROJECTILE_1);//Cadencia y Tipo

    return primero;
}