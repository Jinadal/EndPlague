#pragma once
#include "CollisionComponent.h"
#include <vector>

class Manager;
class LifeComponent;
class ProjectileComponent;
class CollisionManager : public Manager{
   private:
    //Constructor
    CollisionManager():Manager(){}
    static CollisionManager* only_instance;

  public:

    static CollisionManager *getInstance(){         //Pattern Singleton
        if(only_instance == NULL){
            only_instance = new CollisionManager();
        }
        
        return only_instance;
    }
  

    virtual ~CollisionManager(){only_instance=NULL;}
    void createComponent(GameObject* owner, float width, float height,bool solid); 
    void updateAll();

};