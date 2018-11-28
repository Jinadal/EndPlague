
#include "RenderManager.h"



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

void RenderManager::createComponent(GameObject *owner, RenderIrrlicht *render, char path[])
{
    components.push_back(new RenderComponent(owner,render,path));

    owner->addComponent(components[components.size()-1]);
}