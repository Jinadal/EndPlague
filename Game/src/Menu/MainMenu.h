#pragma once
#include "Menu.h"

class MainMenu : public Menu
{
    public:
        MainMenu():Menu(){}
        ~MainMenu(){}

        void init();
        int click();
        void update();
};