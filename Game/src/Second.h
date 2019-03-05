#pragma once
#include <cstddef>


class Second
{
    private:;
        static Second* only_instance;  
        bool open = true;
    public:

        static Second* getInstance(){
            if(only_instance == NULL)
                only_instance = new Second();
            
            return only_instance;
        }

        ~Second()
        {
            only_instance = NULL;
        }
        int run();

};