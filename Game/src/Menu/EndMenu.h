#pragma once
#include "Menu.h"

class EndMenu : public Menu
{
    public:
        EndMenu():Menu(){}
        ~EndMenu(){}

        void init();
        void click();
        void update();
};