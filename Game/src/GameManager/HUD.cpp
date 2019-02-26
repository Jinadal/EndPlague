#include "HUD.h"
#include "GameResource.h"
#include "GameObject.h"
#include "LifeComponent.h"
#include "SpawnManager.h"
#include "ScoreManager.h"
#include <iostream>

void HUD::update(float dt)
{
    GameObject* p = GameResource::getInstance()->getPlayer();
    if(p && p->getComponent<LifeComponent>())
        life = p->getComponent<LifeComponent>()->getLife();
    
    score = ScoreManager::getInstance()->getScore();
    numSpawns = SpawnManager::getInstance()->getNumSpawns();
    std::cout<<"========= H U D ==========\n";
    std::cout<<"  Life: "<<life<<"\n";
    std::cout<<"  Score: "<<score<<"\n";
    std::cout<<"  Spawns: "<<numSpawns<<"\n";
    std::cout<<"  FPS: "<<1/dt<<"\n";
    std::cout<<"==========================\n";
}
