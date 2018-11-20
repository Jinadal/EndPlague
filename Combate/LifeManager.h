#pragma once
//Headers
#include "LifeComponent.h"
#include <vector>


class LifeManager{
  public:
    //Destructor
    ~LifeManager();

    //Constructor
    static LifeManager *getInstance(){
        if(only_instance == NULL)
            only_instance = new LifeManager();
        
        return only_instance;
    }    
    //Update
    void update();
    
    //Methods
    void addLifeComponent(LifeComponent* c){
        components.push_back(c);
    }

private:
    LifeManager(void);
    static LifeManager* only_instance;
    std::vector<LifeComponent*> components;
};