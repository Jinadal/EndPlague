#include "Manager.h"

class GameObject;
class DropperManager : public Manager
{
    private:
        DropperManager():Manager(){};
        static DropperManager* only_instance;

    public:
        static DropperManager* getInstance()
        {
            if(!only_instance)
                only_instance = new DropperManager();
            
            return only_instance;
        }

        ~DropperManager(){
            only_instance = NULL;
        };

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};