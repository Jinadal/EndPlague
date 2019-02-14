#include "Manager.h"

class GameObject;
class DropperManager : public Manager
{
    private:
        DropperManager():Manager(){};

    public:
        ~DropperManager(){}
        static DropperManager* getInstance(){
            static DropperManager only_instance;
            return &only_instance;
        }
        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};