#include <vector>
#include "LifeComponent.h"

class Manager;
class LifeManager : public Manager{
    private:
        LifeManager():Manager(){}
        static LifeManager *only_instance;
        
    public:
        //Constructor Singletone
        static LifeManager *getInstance(){
            if(only_instance == NULL){only_instance = new LifeManager();}
            return only_instance;
        }

        ~LifeManager(){}
        void createComponent(GameObject* owner, float l);
};