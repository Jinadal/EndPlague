#include "MenuFacade.h"

MenuFacade* MenuFacade::only_instance = NULL;

void MenuFacade::setMenuBackground(){
    guienv = RenderIrrlicht::getInstance()->getGUIEnv();
    img = guienv->addImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"),position2d<int>(0,0));
}
void MenuFacade::clearBackground()
{
    guienv->clear();
}