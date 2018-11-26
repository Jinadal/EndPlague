#include <iostream>
#include "RenderManager.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"


int main()
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();


    //ADDING A MAP
    GameObject* map = new GameObject(0, 0, 0, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rc = new RenderComponent(map, render, "res/Mapy.obj");//Creates a render Componen
    rc->setTexture("res/green.bmp");
    rendermanager->addComponent(rc);
    map->addComponent(rc);

    //ADDING A PLAYER
    GameObject* player = new GameObject(-250.f, -150.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderComponent* pc = new RenderComponent(player, render, "res/Playery.obj");//Creates a render Component
    pc->setTexture("res/red.bmp");
    rendermanager->addComponent(pc);
    player->addComponent(pc);

    //ADDING A BOX1
    GameObject* box1 = new GameObject(-200.f, 200.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderComponent* b1c = new RenderComponent(box1, render, "res/Blocky.obj");//Creates a render Component
    b1c->setTexture("res/red.bmp");
    rendermanager->addComponent(b1c);
    box1->addComponent(b1c);

    //ADDING A BOX2
    GameObject* box2 = new GameObject(100.f, -100.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderComponent* b2c = new RenderComponent(box2, render, "res/Blocky.obj");//Creates a render Component
    b2c->setTexture("res/red.bmp");
    rendermanager->addComponent(b2c);
    box2->addComponent(b2c);

    //ADDING A ENEMY
    GameObject* enemy = new GameObject(150.f, 150.f, -10.f, 0.f);//Creates a new GO on x, y, z, rz
    RenderComponent* ec = new RenderComponent(enemy, render, "res/Enemyy.obj");//Creates a render Component
    ec->setTexture("res/red.bmp");
    rendermanager->addComponent(ec);
    enemy->addComponent(ec);

    while(render->run())
    {
        rendermanager->updateAll();
        render->drawAll();

    }

    render->drop();


    return 0;
}
