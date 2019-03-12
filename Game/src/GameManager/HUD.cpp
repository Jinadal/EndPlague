#include "HUD.h"
#include "GameResource.h"
#include "GameObject.h"
#include "LifeComponent.h"
#include "SpawnManager.h"
#include "ScoreManager.h"
#include "Area.h"
#include "IAManager.h"
#include "IAComponent.h"
#include "Waypoint.h"
#include <iostream>
#include <SFML/Window.hpp>



void HUD::update(float dt)
{
    float shield=0.f;
    GameObject* p = GameResource::getInstance()->getPlayer();
    if(p && p->getComponent<LifeComponent>()){
        life = p->getComponent<LifeComponent>()->getLife();
        shield = p->getComponent<LifeComponent>()->getShield();
    }
    
    score = ScoreManager::getInstance()->getScore();
    numSpawns = SpawnManager::getInstance()->getNumSpawns();

    float pox = p->getX();
    float poy = p->getY();



     std::vector<Area*> Areas = IAManager::getInstance()->getGPS()->getAreas();
    

    int ai=0; 
    for (std::size_t i = 0; i< Areas.size(); i++)
    {
        if(Areas[i]->checkinArea(pox,poy))
        {
            ai = i;
        }
    }


    float dtt = high;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){

        if(1/dt >high)
            high = 1/dt;

    }
  
    std::cout<<"========= H U D ==========\n";
    std::cout<<"  X: "<<pox<<"\n";
    std::cout<<"  Y: "<<poy<<"\n";
    std::cout<<"  Area: "<<ai<<"\n";
    std::cout<<"  Life: "<<life<<"\n";
    std::cout<<"  Score: "<<score<<"\n";
    std::cout<<"  Spawns: "<<numSpawns<<"\n";
    std::cout<<"  FPS: "<<dtt<<"\n";
    std::cout<<"==========================\n";

    Render::getInstance()->getHUD()->updateValues(life, shield,1/dt, score, numSpawns, 1);
}
