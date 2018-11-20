#pragma once
//Headers
#include "ProjectileComponent.h"
#include <vector>


class ProjectileManager{
  public:
    //Constructor
    ~ProjectileManager();

    static ProjectileManager *getInstance(){
        if(only_instance == NULL)
            only_instance = new ProjectileManager();
        
        return only_instance;
    }    
    //Update
    void update();
    //Getter&Setter
    std::vector<ProjectileComponent*> getVectorPC(){
        return components;
    }

    void addProjectileComponent(ProjectileComponent* c){
        components.push_back(c);
    }
    void createBullet();
private:
    ProjectileManager(void);
    static ProjectileManager* only_instance;
    std::vector<ProjectileComponent*> components;
};