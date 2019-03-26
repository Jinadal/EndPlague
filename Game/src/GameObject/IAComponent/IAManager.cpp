#include "IAManager.h"
#include "IAComponent.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "GameValues.h"

void IAManager::createComponent(GameObject *owner)
{
    components.push_back(new IAComponent(owner,this, player, nivel));
    owner->addComponent(components[components.size()-1]);
  
}

void IAManager::updateAll(float dt)
{
    onAttack = 0;
    if(player)
    {
        std::vector<Component*>::iterator iter;
        for(iter = components.begin(); iter!=components.end(); iter ++)
        {
            ((IAComponent*)(*iter))->run();
        }
    }
    if(onAttack > gv::MIN_ENEMIES_FOR_ACTION)
    {
        if(actionTime)
        {
            actionTime = true;
            //Cambia sondio
        }
    }else
    {
        if(!actionTime)
        {
            actionTime = false;
            //Cambia Sonido
        }
    }
}


void IAManager::init(int lv)
{
    gps = new GPS();
    gps->Initialice(lv);
    nivel = lv;
}

void IAManager::clear()
{
    components.clear();
    delete gps;
  
}