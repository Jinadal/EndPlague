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
        ~Manager(){}


        void removeComponent(Component *c){
            /*std::vector<Component *>::iterator iter;
            for(iter=components.begin(); iter!=components.end(); iter++){
                if((*iter)==c){
                    delete (*iter);
                    components.erase(iter);
                    return;
                }
            }*/
        }

        void removeAll(){
            /*for(int i=components.size()-1; i>=0; i--)
                delete components[i];*/
        }
};