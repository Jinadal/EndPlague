#pragma once
#include "Menu.h"

class ToNextMenu : public Menu
{
    public:
        ToNextMenu():Menu(){}
        ~ToNextMenu(){}

        void init();
        int click();
        void update();
};