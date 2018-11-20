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

    components.push_back(new CollisionComponent(owner,width,height,solid));
    
    owner->addComponent(components[components.size()-1]);
}


bool CollisionManager::testCollision(CollisionComponent *com1, CollisionComponent *com2)
{
    GameObject *obj1 = com1->getGameObject();
    GameObject *obj2 = com2->getGameObject();

    //Diferencia entre los dos objetos en sus posiciones
    float dx = obj2->getX() - obj1->getX();
    float dy = obj2->getY() - obj1->getY();

    if(fabs(dx) < (com1->width_/2 + com2->width_/2) && fabs(dy) < (com1->height_/2 + com2->height_/2))

    {

        //Interserctan

        
        return true;

    }

    return false;
}

void CollisionManager::update()
{

    std::vector<CollisionComponent *>::iterator iter1;

    for(iter1 = components.begin(); iter1 != components.end(); iter1++)
    {

        std::vector<CollisionComponent *>::iterator iter2;

        for(iter2 = components.begin(); iter2 != components.end(); iter2++)  
        {
            
            if((*iter1) != (*iter2))
            {

                if(testCollision(*iter1, *iter2))
                {

                    //Colisionan
                    
                    //GameObject *obj1 = iter1->getGameObject();
//
                    //GameObject *obj2 = iter2->getGameObject();
                    //
                    //if(obj2->getComponent<ItemComponent>())
                    //{
//
                    //    //Item
                    //}
//
//
                    //if(obj2->getComponent<CombatComponent>())
                    //{
//
                    //    //Enemigo
                    //}
//
//
                    //if(obj2->getComponent<BulletComponent>())
                    //{
//
                    //    //Bala
                    //}     

                    std::cout<< "collision" << std::endl;

                }
            }
        }      
    }

}