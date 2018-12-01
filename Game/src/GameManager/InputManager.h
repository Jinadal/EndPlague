#include <vector>
#include "InputComponent.h"

class Manager;
class InputManager : public Manager{
    private:
        InputManager():Manager(){}
        static InputManager *only_instance;
        
    public:
        virtual ~InputManager(){only_instance=NULL;}
        //Constructor Singletone
        static InputManager *getInstance(){
            if(only_instance == NULL){only_instance = new InputManager();}
            return only_instance;
        }

        void createComponent(GameObject* owner);
};