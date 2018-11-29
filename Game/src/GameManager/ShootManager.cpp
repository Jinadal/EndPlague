#include <iostream>
#include <ShootManager.h>
#include <ShootComponent.h>

ShootManager* ShootManager::only_instance = NULL;

void ShootManager::updateAll(float dt){                         //Checks which component has SHOOTED getting the boolean shooted, if true, creates a projectile and 
    for(size_t i=0; i < components.size(); i++){                //Check vector of ShootComponent
        ShootComponent* shooter = components[i];                //get Component
        if (shooter->update(dt)){                               //Create gameObject Bullet.
            createBullet(shooter->getX(), shooter->getY(), shooter->getRZ(), shooter->getBulletKind());
        }
    }
}

void ShootManager::addComponent(ShootComponent* c){
    components.push_back(c);
}

void ShootManager::createBullet(float x, float y, float rz, int k){  
    //Here we may create a bullet

    std::cout<<"Bala creada!:\n"<<"  x: "<<x<<"\n  y: "<<y<<"\n  rz:"<<rz<<"\n  k: "<<k<<"\n";
}


void ShootManager::createComponent(GameObject *owner, float cadencia, int tipo)
{
    components.push_back(new ShootComponent(owner, cadencia, tipo));

    owner->addComponent(components[components.size()-1]);
}