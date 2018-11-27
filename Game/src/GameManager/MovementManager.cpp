
#include "MovementManager.h"

//Adds A New Render Component to components
void MovementManager::addComponent(MovementComponent* rc){
    components.push_back(rc);
}


//Updates all the components
void MovementManager::updateAll(float dt){
    for(auto* c : components){
        c->update(dt);
    }
}