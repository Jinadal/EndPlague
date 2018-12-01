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
        virtual ~Manager(){}


        virtual void removeComponent(Component *c){//TODO-----No funciona
            /*std::vector<Component *>::iterator iter;
            for(iter=components.begin(); iter!=components.end(); iter++){
                if((*iter)==c){
                    delete (*iter);
                    components.erase(iter);
                    return;
                }
            }
            */
        }

        virtual void removeAll(){
            components.clear();
        }
};