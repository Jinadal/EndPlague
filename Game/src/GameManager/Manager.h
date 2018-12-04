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


        void removeComponent(Component* c)//TODO-----No funciona
        {
            std::cout<<"Borrando Componente\n";
            std::cout<<components.size()<<"\n";
            for(std::vector<Component*>::iterator it = components.begin(); it!=components.end(); it++)
            {
                if((*it)==c)
                {    
                    components.erase(it);
                    break;
                }
            }
            std::cout<<components.size()<<"\n";
        }
};