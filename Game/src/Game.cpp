#include <iostream>
#include "RenderManager.h"
#include "RenderComponent.h"
#include "GameObject.h"

#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"


int main()
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();
    


    GameObject* map = new GameObject(0, 0, 0, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rc = new RenderComponent(map, render, "res/Map.obj");//Creates a render Component

    rendermanager->addComponent(rc);
    map->addComponent(rc);


    GameObject* box = new GameObject(10000, 10000, 10000, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rb = new RenderComponent(box, render, "res/Block.obj");//Creates a render Component

    rendermanager->addComponent(rb);
    box->addComponent(rb);
    


    while(render->run())
    {

        rendermanager->updateAll();
        render->drawAll();

    }


    render->drop();

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
