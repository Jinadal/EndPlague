#pragma once
#include "Component.h"
#include <vector>

//Init
	void init();

	//Update
	void update();

	//Close
	void close();

	//Add component
    void GameObject::addComponent(Component* c);

}