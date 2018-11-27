#include "ShootComponent.h"

void ShootComponent::shoot(){   //An entity shoots a proyectile
    if(lastShoot>cadencia){
        lastShoot = 0.f;
    }  
}

void ShootComponent::update(float dt){
    lastShoot+=dt;
}


GameObject* createProjectile(){
    GameObject* proyectile = new GameObject(10,10);

    //Add Collision
    CollisionComponent* cc = new CollisionComponent(bullet);
    //Add Render
    RenderComponent* rc = new RenderComponent(bullet);
    //Add Movement
    MovementComponent* mc = new MovementComponent(bullet);
    //Add Collision

    //ProjectileCompoment
    ProjectileComponent* pc = new ProjectileComponent(bullet);
	bullet->addComponent(pc);
    ProjectileManager::getInstance()->addProjectileComponent(pc);   //Introduce ProjectileComponent in ProjectileManager.
    delete bullet;
    delete pc;
}