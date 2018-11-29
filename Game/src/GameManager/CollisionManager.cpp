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
    for(int i = 0; i<conMove; i++)
    {
        for(int j = i+1; j < components.size(); j++)
        {
            if(((CollisionComponent*)components[i])->testCollision(((CollisionComponent*)components[j]))){
                
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackX();
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackY();
                
                
                //Comprobamos si hay projectiles y/o lifes
                LifeComponent* l;
                ProjectileComponent* p;
                if(p = components[i]->getGameObject()->getComponent<ProjectileComponent>()){
                    if(components[j]->getGameObject()==nullptr)
                        std::cout<<"Holiiiiissss Soy nulptr\n";

                    if(components[j]->getGameObject()==NULL)
                        std::cout<<"Holiiiiissss Soy NULL\n";

                    
                    std::cout<<"No soy null\n";

                    if(l = components[j]->getGameObject()->getComponent<LifeComponent>()){
                        std::cout<<"Hola\n";
                        if(p->dealDamage(l)){
                            //Los dos se han destruido
                            std::cout<<"Los dos se han destruido\n";
                        }else{
                            std::cout<<"Hola\n";
                            //Solo se ha destruido el projectil
                            std::cout<<"solo se ha destruido el projectil A\n";
                            p->crush();
                        }
                        conMove--;
                    }else{
                        //Solo se destuye el projectil
                        p->crush();
                        std::cout<<"solo se ha destruido el projectil B\n";
                        conMove--;
                    }
                }else if(p = components[j]->getGameObject()->getComponent<ProjectileComponent>()){
                    if(l = components[i]->getGameObject()->getComponent<LifeComponent>()){
                        if(p->dealDamage(l)){
                            //Los dos se han destruido
                            std::cout<<"Los dos se han destruido\n";
                            p->crush();
                        }else{
                            //Solo se ha destruido el projectil
                            std::cout<<"solo se ha destruido el projectil A\n";
                            p->crush();
                        }
                        conMove--;
                    }else{
                        //Solo se destuye el projectil
                        std::cout<<"solo se ha destruido el projectil B\n";
                        p->crush();
                        conMove--;
                    }
                }
            }
        }
        
       
    }

}