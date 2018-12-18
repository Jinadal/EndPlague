#include "EnemyFabric.h"

GameObject* EnemyFabric::createEnemy(float x, float y, float z, float rz, EnemyType type)
{
    
    //ADDING A ENEMY
    GameObject* primero = gameresource->createGameObject(x, y, z, rz);//Creates a new GO on x, y, z, rz
    rendermanager->createComponent(primero, enemytypes[type].mesh);//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setTexture(enemytypes[type].texture);//Path de bmp
    movementmanager->createComponent(primero);
    primero->getComponent<MovementComponent>()->setvMax(enemytypes[type].vMax);
    collisionmanager->createComponent(primero, 1, 1, true); //Ancho, alto y si es solido
    iamanager->createComponent(primero);
    primero->getComponent<IAComponent>()->Initialice();
    lifemanager->createComponent(primero, enemytypes[type].life);//Vida
    shootmanager->createComponent(primero, .4f, 1.f, PROJECTILE_1);//Cadencia y Tipo


    return primero;
}