#include <vector>
#include "LifeComponent.h"


class LifeManager{
    private:
        std::vector<LifeComponent*> components;
        static LifeManager *only_instance;
        LifeManager(){}
        
    public:
        //Constructor Singletone
        static LifeManager *getInstance(){
            if(only_instance == NULL){only_instance = new LifeManager();}
            return only_instance;
        }

        ~LifeManager(){}
        void createComponent(GameObject* owner, float l);
};