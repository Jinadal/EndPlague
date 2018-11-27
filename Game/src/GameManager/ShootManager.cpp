#include <iostream>
#include <ShootManager.h>
#include <ShootComponent.h>
#include <ProjectileComponent.h>
#include <ProjectileManager.h>
#include <GameObject.h>

ShootManager* ShootManager::only_instance = NULL;

ShootManager::ShootManager(void){}
ShootManager::~ShootManager(void){}

void ShootManager::update(){                        //Checks which component has SHOOTED getting the boolean shooted, if true, creates a projectile and 
    bool bbullet = false;                           //turns it to false.
    for(size_t i=0; i < components.size(); i++){    //Check vector of ShootComponent
        bbullet = components[i]->getShooted();      //get boolean shooted;
        if (bbullet){
            createBullet();                         //Create gameObject Bullet.
            components[i]->setShooted(false);       //shooted = false, we can shoot again
        }
    }
}
void ShootManager::createBullet(){  
    GameObject* bullet = new GameObject(10,10);     
    ProjectileComponent* pc = new ProjectileComponent(bullet);
	bullet->addComponent(pc);
    ProjectileManager::getInstance()->addProjectileComponent(pc);   //Introduce ProjectileComponent in ProjectileManager.
    delete bullet;
    delete pc;
}