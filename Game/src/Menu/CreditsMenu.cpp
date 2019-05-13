#include "CreditsMenu.h"

CreditsMenu::CreditsMenu() : Menu()
{
    //Background
    setBackground((char*)"res/sprites/menus/C/C_B.png");
    
    //Buttons
    Button* button = new Button(1, (char*)"res/sprites/menus/C/C_V_S.png", 
                                        (char*)"res/sprites/menus/C/C_V_S.png",1581, 963);
    buttons.push_back(button);
    


    buttons[focus]->focus();

}
