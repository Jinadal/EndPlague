#pragma once
//Headers
#include "ItemComponent.h"
#include <vector>


class ItemManager{
  public:
    //Constructor
    ItemManager(){}

    void addItemComponent(ItemComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<ItemComponent*> components;
};
