#pragma once
//Headers
#include "CollisionComponent.h"
#include <vector>


class CollisionManager{
  public:
    //Constructor
    CollisionManager(){}

    void createComponent(Component* c, float width, float height,bool solid);

    void removecomponent(Component* c);    
    void update();
        
  }
private:
  std::vector<CollisionComponent*> components;

  bool testCollision(CollisionComponent *obj1, CollisionComponent *obj2 );
};