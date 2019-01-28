#include "EnemyFabric.h"
#include "BPhysicComponent.h"
//#include "IAComponent.h"

GameObject* EnemyFabric::createEnemy(float x, float y, float z, float rz, EnemyType type)
{
    if(scoremanager->getEnemies()>MAX_ENEMIES)
        return NULL;

    
    //ADDING A ENEMY
    GameObject* primero = gameresource->createGameObject(x, y, z, rz);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(primero, enemytypes[type].mesh);//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture(enemytypes[type].texture);//Path de bmp
    bphysicmanager->createComponent(primero, .5f, .5f, 1.f, 100.f, 0);
    primero->getComponent<BPhysicComponent>()->setvMax(enemytypes[type].vMax);
    scoremanager->createComponent(primero, 10);
    iamanager->createComponent(primero);
    primero->getComponent<IAComponent>()->Initialice();
    lifemanager->createComponent(primero, enemytypes[type].life);//Vida
    shootmanager->createComponent(primero, .9f, 2.f, PROJECTILE_1);//Cadencia y Tipo

    return primero;
}