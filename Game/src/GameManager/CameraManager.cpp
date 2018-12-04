#include "CameraManager.h"


CameraManager* CameraManager::only_instance = NULL;

void CameraManager::createComponent(GameObject* go)
{
    components.push_back(new CameraComponent(go, this));

    go->addComponent(components[components.size()-1]);
}

void CameraManager::updateAll()
{
    for(auto* c : components)
    {
       ((CameraComponent*)c)->update();
    }   
}