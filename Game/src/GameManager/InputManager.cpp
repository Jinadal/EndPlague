#include "InputManager.h"


InputManager* InputManager::only_instance = NULL;


void InputManager::createComponent(GameObject *owner)
{
    components.push_back(new InputComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}