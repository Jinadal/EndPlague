#include <vector>
#include "ProjectileComponent.h"
#include "GameObject.h"

class GameObject;

class ProjectileManager{
    private:
        ProjectileManager(){}
        static ProjectileManager* only_instance;
        std::vector<ProjectileComponent*> components;
    public:
        //Constructor
        static ProjectileManager *getInstance(){
            if(only_instance == NULL)
                only_instance = new ProjectileManager();
            
            return only_instance;
        }

        ~ProjectileManager();
        void createComponent(GameObject* owner, float damage);
        void createBullet();
};