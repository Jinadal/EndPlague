#pragma once
#include "Menu.h"

class PauseMenu : public Menu
{
    public:
        PauseMenu():Menu(){}
        ~PauseMenu(){}

        void init();
        void click();
        void update();
};