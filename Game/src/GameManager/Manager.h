//Abstract Manager Class
#include <vector>

class Component;
class Manager{
    protected:
        std::vector<Component*> components;
    public:
        //Constructor
        Manager(){}

        //Destructor
        virtual ~Manager(){components.clear();}


        virtual void removeComponent(Component *c){//TODO-----No funciona
            //components.erase(std::remove(components.begin(), components.end(), c), components.end());
        }
};