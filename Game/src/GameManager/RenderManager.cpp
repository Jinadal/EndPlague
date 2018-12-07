#include "RenderManager.h"

RenderManager* RenderManager::only_instance = NULL;

//Updates all the components
void RenderManager::updateAll(){
    for(auto* c : components){
        ((RenderComponent*)c)->update();
    }
}


void RenderManager::createComponent(GameObject *owner, char path[]){
    components.push_back(new RenderComponent(owner, this, path));
    owner->addComponent(components[components.size()-1]);
}