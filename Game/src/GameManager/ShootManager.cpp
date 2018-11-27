#include <iostream>
#include <ShootManager.h>
#include <ShootComponent.h>

ShootManager* ShootManager::only_instance = NULL;

ShootManager::ShootManager(void){}
ShootManager::~ShootManager(void){}

void ShootManager::update(float dt){                            //Checks which component has SHOOTED getting the boolean shooted, if true, creates a projectile and 
    for(size_t i=0; i < components.size(); i++){                //Check vector of ShootComponent
        shooter = components[i];                                //get Component
        if (shooter->update(dt)){                               //Create gameObject Bullet.
            createBullet(shooter->getDamage(),
                            shooter->getVelocity()
                            shooter->getProjectileMesh()
                            shooter->getProjectileTexture()
                            shooter->getX(),
                            shooter->getY());
        }
    }
}

void ShootManager::createBullet(float damage, float velocity, char mesh[], char texture[], float x, float y){  
    //Here we may create a bullet

    std::cout<<"Bala creada!:\n"<<"  damage: "<<damage<<"\n  velocity: "<<velocity<<"\n  x:"<<x<<"\n  y: "<<y<<"\n";
}