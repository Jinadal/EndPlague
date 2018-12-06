#include "StorageComponent.h"
#include <iostream>


void StorageComponent::itemCatch(ItemComponent* item){
    itemDrop();
    this->item = item;
    std::cout<<"He cogido el item\n";

}

void StorageComponent::itemDrop(){
    std::cout<<"He tirado el objeto que tenia\n";
}

