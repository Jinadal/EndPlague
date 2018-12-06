#include "CollisionManager.h"
#include "MovementComponent.h"
#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include "StorageComponent.h"
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
    for(std::size_t i = 0; i<components.size() && components[i]->getGameObject()->getComponent<MovementComponent>(); i++)
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

                ProjectileComponent* i_projectil = components[i]->getGameObject()->getComponent<ProjectileComponent>();
                ProjectileComponent* j_projectil = components[j]->getGameObject()->getComponent<ProjectileComponent>();

                LifeComponent* i_life = components[i]->getGameObject()->getComponent<LifeComponent>();
                LifeComponent* j_life = components[j]->getGameObject()->getComponent<LifeComponent>();

                if(i_projectil)
                    i_projectil->dealDamage(j_life);
                if(j_projectil)
                    j_projectil->dealDamage(i_life);


                //En el caso de que lo que colisione sea un item
                ItemComponent* i_item = components[i]->getGameObject()->getComponent<ItemComponent>(); //EL PRIMER COMPONENTE DE LA COLISION ES UN ITEM
                ItemComponent* j_item = components[j]->getGameObject()->getComponent<ItemComponent>(); //EL SEGUNDO COMPONENTE DE LA COLISION ES UN ITEM

                StorageComponent* i_storage = components[i]->getGameObject()->getComponent<StorageComponent>();
                StorageComponent* j_storage = components[j]->getGameObject()->getComponent<StorageComponent>();

                if(i_item) //Si i es un item
                    j_storage->itemCatch(i_item);
        
                if(j_item) //Si i es un item
                    i_storage->itemCatch(j_item);

            }
        }
        
       
    }

}