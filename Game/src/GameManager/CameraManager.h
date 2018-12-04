
#include "CameraComponent.h"

class Manager;
class GameObject;
class CameraManager : public Manager{
    private:
        CameraManager(){}
        static CameraManager* only_instance;
    public:
        CameraManager* getInstance(){
            if(only_instance = NULL)
                only_instance = new CameraManager();
            
            return only_instance;
        }

        ~CameraManager(){
            only_instance = NULL;
        }

        void createComponent(GameObject* go);
        void updateAll();
};