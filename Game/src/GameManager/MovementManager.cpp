
#include "MovementManager.h"

MovementManager* MovementManager::only_instance = NULL;


//Updates all the components
void MovementManager::updateAll(float dt){
    for(auto* c : components){
        ((MovementComponent*)c)->update(dt);
    }
}

void MovementManager::createComponent(GameObject *owner)
{

    components.push_back(new MovementComponent(owner, this));

    owner->addComponent(components[components.size()-1]);
}
