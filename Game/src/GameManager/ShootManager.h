#pragma once
//Headers
#include "ShootComponent.h"
#include <vector>


class ShootManager{
  public:
    //Constructor
    ~ShootManager(void);

    static ShootManager *getInstance(){         //Pattern Singleton
        if(only_instance == NULL)
            only_instance = new ShootManager();
        
        return only_instance;
    }
    void addShootComponent(ShootComponent* c){
        components.push_back(c);
    }
    void update();
    void createBullet();
private:
    ShootManager(void);
    static ShootManager* only_instance;
    std::vector<ShootComponent*> components;
};