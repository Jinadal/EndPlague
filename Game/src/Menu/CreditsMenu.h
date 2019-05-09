#pragma once
#include "Menu.h"

class CreditsMenu : public Menu
{
    public:
        CreditsMenu():Menu(){}
        ~CreditsMenu(){}

        void init();
        void click();
        void update();
};