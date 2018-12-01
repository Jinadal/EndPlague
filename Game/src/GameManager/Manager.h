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


        virtual void removeComponent(Component* c){//TODO-----No funciona
            for(std::vector<Component*>::iterator it = components.begin(); it!=components.end(); it++){
                Component* co = *it;
                if(co==c){
                    components.erase(it);
                    return;
                }
            }
            
        }
};