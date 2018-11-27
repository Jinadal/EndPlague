#pragma once
//Headers
#include "CollisionComponent.h"
#include <vector>


class CollisionManager
{

  public:

    //Constructor
  CollisionManager(){}

  virtual ~CollisionManager(){}

  void createComponent(GameObject *owner, float width, float height,bool solid);

  void removecomponent(Component* c);    
  
  void update();

  int conMove = 0;
        
  
  private:

  std::vector<CollisionComponent*> components;

  //bool testCollision(CollisionComponent *com1, CollisionComponent *com2 );

};