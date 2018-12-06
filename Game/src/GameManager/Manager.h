//Abstract Manager Class
#include <vector>
#include <iostream>

class Component;
class Manager{
    protected:
        std::vector<Component*> components;
    public:
        //Constructor
        Manager(){}

        //Destructor
        virtual ~Manager(){components.clear();}


        void removeComponent(Component* c)
        {
            for(std::vector<Component*>::iterator it = components.begin(); it!=components.end(); it++){
                components.erase(it);
                break;
            }
        }
};