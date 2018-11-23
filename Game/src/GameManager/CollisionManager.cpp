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

//
//
//
//void CollisionManager::update()
//{
//
//    std::vector<CollisionComponent *>::iterator iter1;
//
//    for(iter1 = components.begin(); iter1 != components.end(); iter1++)
//    {
//
//        std::vector<CollisionComponent *>::iterator iter2;
//
//        for(iter2 = components.begin(); iter2 != components.end(); iter2++)  
//        {
//            
//            if((*iter1) != (*iter2))
//            {
//
//                if(testCollision(*iter1, *iter2))
//                {
//
//                    //Colisionan
//                    
//                    //GameObject *obj1 = iter1->getGameObject();
////
//                    //GameObject *obj2 = iter2->getGameObject();
//                    //
//                    //if(obj2->getComponent<ItemComponent>())
//                    //{
////
//                    //    //Item
//                    //}
////
////
//                    //if(obj2->getComponent<CombatComponent>())
//                    //{
////
//                    //    //Enemigo
//                    //}
////
////
//                    //if(obj2->getComponent<BulletComponent>())
//                    //{
////
//                    //    //Bala
//                    //}     
//
//                    std::cout<< "collision" << std::endl;
//
//                }
//            }
//        }      
//    }
//
//}