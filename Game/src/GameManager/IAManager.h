#include <vector>
#include "IAComponent.h"

class Manager;
class IAManager : public Manager{
    private:
        IAManager():Manager(){}
        static IAManager *only_instance;
        
    public:
        virtual ~IAManager(){only_instance=NULL;}
        //Constructor Singletone
        static IAManager *getInstance(){
            if(only_instance == NULL){only_instance = new IAManager();}
            return only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll();

};