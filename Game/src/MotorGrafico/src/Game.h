#pragma once
#include <cstddef>


class Game
{
    private:;
        static Game* only_instance;  

    public:

        static Game* getInstance(){
            if(only_instance == NULL)
                only_instance = new Game();
            
            return only_instance;
        }

        ~Game()
        {
            only_instance = NULL;
        }
        void run();

};