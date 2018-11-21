#include <RenderManager.h>


void RenderManager::addComponent(RenderComponent* c){
    components->push_back(c);
}

void RenderManager::update(){
    renderfacade->update();

    for(size_t i=0; i<components.size(); i++){
        components[i]->update();
    }
}
