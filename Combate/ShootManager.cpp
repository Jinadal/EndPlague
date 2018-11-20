#include <iostream>
#include <ShootManager.h>
#include <ShootComponent.h>
#include <ProjectileComponent.h>
#include <ProjectileManager.h>
#include <GameObject.h>

ShootManager* ShootManager::only_instance = NULL;

ShootManager::ShootManager(void){}
ShootManager::~ShootManager(void){}

void ShootManager::update(){
    bool bbullet = false;
    for(size_t i=0; i < components.size(); i++){
        bbullet = components[i]->getShooted();
        if (bbullet){
            std::cout<<"Recibo el disparo y dispongo a crear bala"<<std::endl;
            createBullet();
            components[i]->setShooted(false);
        }
    }
}
void ShootManager::createBullet(){
    std::cout<<"Creo bala"<<std::endl;
    GameObject* bullet = new GameObject(10,10);
    ProjectileComponent* pc = new ProjectileComponent(bullet);
	bullet->addComponent(pc);
    ProjectileManager::getInstance()->addProjectileComponent(pc);
}