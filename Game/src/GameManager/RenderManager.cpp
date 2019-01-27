#include "RenderManager.h"
#include "GameObject.h"

RenderManager* RenderManager::only_instance = NULL;

//Updates all the components
void RenderManager::updateAll(float dt){
    for(std::size_t i = 0; i<components.size(); i++)
        ((RenderComponent*)components[i])->update();
}

void RenderManager::createComponent(GameObject *owner, char path[]){
    components.push_back(new RenderComponent(owner, this, path));
    owner->addComponent(components[components.size()-1]);
}