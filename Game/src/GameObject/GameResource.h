#include "GameObject.h"
#include <vector>

class GameResource{
    private:
        GameResource(){}
        static GameResource* only_instance;
        std::vector<GameObject*> gameobjects;
    public:
        ~GameResource();//Destructor calls the destructor of all the GameObjects
        static GameResource* getInstance(){//Singletone getInsatnce
            if(only_instance == NULL)
                only_instance = new GameResource();

            return only_instance;
        }

        GameObject* createGameObject(float x, float y, float z, float rz);//Returns new GameObject

        void updateAll(); //Calls the destructor of all the Game Objects wich toKill()
};