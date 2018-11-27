#include "CollisionManager.h"

#include <cmath>

#include <iostream>


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
        components.push(new CollisionComponent(owner,width,height,solid));
        conMove ++;
    }else{
        components.push_back(new CollisionComponent(owner,width,height,solid));
    }
    
    owner->addComponent(components[components.size()-1]);
}




void CollisionManager::update()
{

    //std::vector<CollisionComponent *>::iterator iter1;

    for(int i = 0, i<conMove; i++)
    {
        for(int j = i+1, j < components.size(), j++)
        {
            if(components[i]->testCollision(components[j])){

                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackX();
                components[i]->getGameObject()->getComponent<MovementComponent>()->goBackY();

            }
        }
        
       
    }

}