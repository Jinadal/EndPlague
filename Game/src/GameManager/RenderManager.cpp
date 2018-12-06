
#include "RenderManager.h"

RenderManager* RenderManager::only_instance = NULL;

//Updates all the components
void RenderManager::updateAll(){
    for(std::size_t i = 0; i<components.size(); i++)
        ((RenderComponent*)components[i])->update();
}


void RenderManager::createComponent(GameObject *owner, char path[]){
    components.push_back(new RenderComponent(owner, this, RenderIrrlicht::getInstance(), path));
    owner->addComponent(components[components.size()-1]);
}