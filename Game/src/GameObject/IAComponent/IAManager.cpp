#include "IAManager.h"
#include "IAComponent.h"
#include "GameObject.h"
#include "Waypoint.h"


void IAManager::createComponent(GameObject *owner)
{
    components.push_back(new IAComponent(owner,this, player, nivel));
    owner->addComponent(components[components.size()-1]);
  
}

void IAManager::updateAll(float dt)
{
    if(player)
    {
        std::vector<Component*>::iterator iter;
        for(iter = components.begin(); iter!=components.end(); iter ++)
        {
            ((IAComponent*)(*iter))->run();
        }
    }
 
}


void IAManager::init(int lv)
{
    gps = new GPS();
    gps->Initialice(lv);
    nivel = lv;
     AmbientSoundEvent* s = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("ambiente"));
     s->start();
     s->setAttackParameter()
}

void IAManager::clear()
{
    components.clear();
    delete gps;
  
}