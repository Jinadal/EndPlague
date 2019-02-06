#include "Manager.h"

class GameObject;
class DropperManager : public Manager
{
    private:
        DropperManager():Manager(){};
        static DropperManager* only_instance;

    public:
        ~DropperManager(){only_instance = NULL;}
        static DropperManager* getInstance()
        {
            if(!only_instance)
                only_instance = new DropperManager();
            
            return only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};