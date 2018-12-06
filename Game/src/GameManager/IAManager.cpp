#include "IAManager.h"


IAManager* IAManager::only_instance = NULL;



void IAManager::createComponent(GameObject *owner, GameObject *personaje )
{

   
   
        components.push_back(new IAComponent(owner,this, personaje));
   
    
    owner->addComponent(components[components.size()-1]);
}

void IAManager::updateAll(){

 std::vector<Component*>::iterator iter;

    for(iter = components.begin(); iter!=components.end(); iter ++){

        ((IAComponent*)(*iter))->run();
    }
    
}
