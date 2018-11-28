
#include "MovementComponent.h"
#include <vector>

class MovementManager{
    private:
        std::vector<MovementComponent*> components;
    public:
        MovementManager(){}

        ~MovementManager(){}

        void addComponent(MovementComponent* rc);
        void updateAll(float dt);

    void removecomponent(Component* c);    
    void createComponent(GameObject *owner);
};