#include "CollisionManager.h"
#include "MovementComponent.h"
#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include <cmath>
#include <iostream>


CollisionManager* CollisionManager::only_instance = NULL;

void CollisionManager::removecomponent(Component *c)
{

    std::vector<CollisionComponent *>::iterator iter;


    for(iter=components.begin(); iter!=components.end(); iter++)
    {
        if((*iter)==c)
        {
            delete (*iter);

            components.erase(iter);

            return;
        }
    }


}


void CollisionManager::createComponent(GameObject *owner ,float width, float height, bool solid)
{

    if(owner->getComponent<MovementComponent>())
    {
        components.insert(components.begin(),new CollisionComponent(owner,width,height,solid));
        conMove ++;
    }else{
        components.push_back(new CollisionComponent(owner,width,height,solid));
    }
    
    owner->addComponent(components[components.size()-1]);
}




void CollisionManager::update()
{

    //std::vector<CollisionComponent *>::iterator iter1;

    for(int i = 0; i<conMove; i++)
    {
        for(int j = i+1; j < components.size(); j++)
        {
            std::cout<<"Collision\n";
            if(components[i]->testCollision(components[j])){
                
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackX();
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackY();
                

                //Comprobamos si hay projectiles y/o lifes
                LifeComponent* l;
                ProjectileComponent* p;
                if(p = components[i]->getGameObject()->getComponent<ProjectileComponent>()){
                    if(l = components[j]->getGameObject()->getComponent<LifeComponent>()){
                        if(p->dealDamage(l)){
                            //Los dos se han destruido
                            std::cout<<"Los dos se han destruido\n";
                        }else{
                            //Solo se ha destruido el projectil
                            std::cout<<"solo se ha destruido el projectil A\n";
                        }
                    }else{
                        //Solo se destuye el projectil
                        p->kill();
                        std::cout<<"solo se ha destruido el projectil B\n";
                    }
                }else if(p = components[j]->getGameObject()->getComponent<ProjectileComponent>()){
                    if(l = components[i]->getGameObject()->getComponent<LifeComponent>()){
                        if(p->dealDamage(l)){
                            //Los dos se han destruido
                            std::cout<<"Los dos se han destruido\n";
                        }else{
                            //Solo se ha destruido el projectil
                            std::cout<<"solo se ha destruido el projectil A\n";
                            
                        }
                    }else{
                        //Solo se destuye el projectil
                        std::cout<<"solo se ha destruido el projectil B\n";
                        p->kill();
                    }
                }
            }
        }
        
       
    }

}