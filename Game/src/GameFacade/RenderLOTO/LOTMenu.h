#pragma once
#include "FMenu.h"

class LOTMenu : public FMenu
{
    private:
        LOTMenu() : FMenu(){};
    public:

        static LOTMenu* getInstance(){
            static LOTMenu only_instance;
            return &only_instance;
        }
        


        ~LOTMenu() {}
        void setMenuBackground(char* t);
        void clearBackground();
        void update(){}
};