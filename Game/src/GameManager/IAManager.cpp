#include "IAManager.h"
#include "IAComponent.h"
#include "GameObject.h"

IAManager* IAManager::only_instance = NULL;



void IAManager::createComponent(GameObject *owner)
{
    components.push_back(new IAComponent(owner,this, player));
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
