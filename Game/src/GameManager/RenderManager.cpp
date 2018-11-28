
#include "RenderManager.h"

//Adds A New Render Component to components
void RenderManager::addComponent(RenderComponent* rc){
    components.push_back(rc);
}


//Updates all the components
void RenderManager::updateAll(){
    for(auto* c : components){
        c->update();
    }
}

void RenderManager::removecomponent(Component *c)
{

    std::vector<RenderComponent *>::iterator iter;


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
