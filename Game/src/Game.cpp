#include <iostream>

#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"


int main()
{
    std::cout<<"Bienvenido a *Screams in Goblin*\n";

    GameObject *bola1 = new GameObject(10,10);
    GameObject *bola2 = new GameObject(25,25);
    


    CollisionManager *collisionmanager = new CollisionManager();

    collisionmanager -> createComponent(bola1, 10 , 10 , true);
    collisionmanager -> createComponent(bola2, 10 , 10 , true);


    std::cout<<"Bola 1 x=" << bola1->getX()<< "y= "<<bola1->getY() <<"\n";
    std::cout<<"Bola 2 x=" << bola2->getX()<< "y= "<<bola2->getY() <<"\n";

    bola1->getComponent<CollisionComponent>()->checkCollision(bola2);






    return 0;
}
