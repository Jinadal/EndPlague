
#include "MovementManager.h"

MovementManager* MovementManager::only_instance = NULL;

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

void MovementManager::removecomponent(Component *c)
{

    std::vector<MovementComponent *>::iterator iter;


    for(iter=components.begin(); iter!=components.end(); iter++)
    {
        if((*iter)==c)
        {
            delete (*iter);

            components.erase(iter);

            return;
        }
    }


}


void MovementManager::createComponent(GameObject *owner)
{

    components.push_back(new MovementComponent(owner));

    owner->addComponent(components[components.size()-1]);
}