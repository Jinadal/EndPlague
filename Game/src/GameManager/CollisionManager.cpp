#include "CollisionManager.h"
#include "MovementComponent.h"
#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include <cmath>
#include <iostream>


CollisionManager* CollisionManager::only_instance = NULL;



void CollisionManager::createComponent(GameObject *owner ,float width, float height, bool solid)
{

    if(owner->getComponent<MovementComponent>())
    {
        components.insert(components.begin(),new CollisionComponent(owner, this, width, height, solid));
        conMove ++;
    }else{
        components.push_back(new CollisionComponent(owner, this, width, height, solid));
    }
    
    owner->addComponent(components[components.size()-1]);
}




void CollisionManager::updateAll()
{
    //std::vector<CollisionComponent *>::iterator iter1;
    for(std::size_t i = 0; i<conMove; i++)
    {
        for(std::size_t j = i+1; j < components.size(); j++)
        {
            if(((CollisionComponent*)components[i])->testCollision(((CollisionComponent*)components[j]))){
                
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackX();
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackY();
                
                /*
                -------------------------------------------------------------
                                    OPCIONES DE COLISION
                -------------------------------------------------------------
                    I=Proyectil
                    J=Vida

                    I=Proyectil
                    J=!Vida

                    I=Vida
                    J=Proyectil

                    I=!Vida
                    J=Proyectil
    
                */
                std::cout<<"Colision: "<<components[i]->getGameObject()<<"  Y  "<<components[j]->getGameObject()<<"\n";

                ProjectileComponent* i_projectil = components[i]->getGameObject()->getComponent<ProjectileComponent>();
                ProjectileComponent* j_projectil = components[j]->getGameObject()->getComponent<ProjectileComponent>();

                LifeComponent* i_life = components[i]->getGameObject()->getComponent<LifeComponent>();
                LifeComponent* j_life = components[j]->getGameObject()->getComponent<LifeComponent>();
                

                if(i_projectil)
                    i_projectil->dealDamage(j_life);
                if(j_projectil)
                    j_projectil->dealDamage(i_life);
            }
        }
        
       
    }

}