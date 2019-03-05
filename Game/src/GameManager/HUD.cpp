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

void HUD::update(float dt)
{
    GameObject* p = GameResource::getInstance()->getPlayer();
    if(p && p->getComponent<LifeComponent>())
        life = p->getComponent<LifeComponent>()->getLife();
    
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

    std::cout<<"========= H U D ==========\n";
    std::cout<<"  X: "<<pox<<"\n";
    std::cout<<"  Y: "<<poy<<"\n";
    std::cout<<"  Area: "<<ai<<"\n";
    std::cout<<"  Life: "<<life<<"\n";
    std::cout<<"  Score: "<<score<<"\n";
    std::cout<<"  Spawns: "<<numSpawns<<"\n";
    std::cout<<"  FPS: "<<1/dt<<"\n";
    std::cout<<"==========================\n";
}
