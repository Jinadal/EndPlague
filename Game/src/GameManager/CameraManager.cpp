
#include "CameraManager.h"

CameraManager* CameraManager::only_instance = NULL;


//Updates all the components
void CameraManager::updateAll(){
    for(auto* c : components){
        ((CameraComponent*)c)->update();
    }
}

void CameraManager::createComponent(GameObject *owner)
{

    components.push_back(new CameraComponent(owner, this));

    owner->addComponent(components[components.size()-1]);
}
