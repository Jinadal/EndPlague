
#include "MovementComponent.h"
#include <vector>

class MovementManager{
    private:
        MovementManager(){}
        static MovementManager *only_instance;
        std::vector<MovementComponent*> components;
    public:
        static MovementManager* getInstance(){
            if(only_instance == NULL)
                only_instance = new MovementManager();
            
            return only_instance;
        } 

        ~MovementManager(){}

        void addComponent(MovementComponent* rc);
        void updateAll(float dt);

    void removecomponent(Component* c);    
    void createComponent(GameObject *owner);
};