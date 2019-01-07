#include "Menus.h"


int Menus::loadStartMenu()
{
    RenderIrrlicht::getInstance()->getGUIEnv()->addButton(rect<s32>(10,240,110,240 + 32), 0, GUI_PLAY_BUTTON,
            L"Play", L"Plays the Game");
    
    return 1;
}