#include "IAManager.h"
#include "IAComponent.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "GameResource.h"

void IAManager::createComponent(GameObject *owner)
{
    components.push_back(new IAComponent(owner,this, GameResource::getInstance()->getPlayer()));
    owner->addComponent(components[components.size()-1]);
  
}

void IAManager::updateAll(float dt)
{
    if(GameResource::getInstance()->getPlayer())
    {
        std::vector<Component*>::iterator iter;
        for(iter = components.begin(); iter!=components.end(); iter ++)
        {
            ((IAComponent*)(*iter))->run();
        }
    }
 
}


void IAManager::init()
{
    gps = new GPS();
    gps->Initialice();
}

void IAManager::clear()
{
    components.clear();
    delete gps;
  
}