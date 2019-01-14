#include "MenuFacade.h"

MenuFacade* MenuFacade::only_instance = NULL;

void MenuFacade::setMenuBackground(){
    env = RenderIrrlicht::getInstance()->getGUIEnv();
    img = env->addImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"),position2d<int>(0,0));
    IGUIButton* button = env->addButton(rect<s32>(10,210,100,240), 0, 101, L"New Game");
	IGUIButton* button1 = env->addButton(rect<s32>(10,250,100,290), 0, 102, L"Options");
	IGUIButton* button2 = env->addButton(rect<s32>(10,300,100,340), 0, 103, L"Exit");
    button->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"));
    button1->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"));
    button2->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/menu-background.jpg"));


}
void MenuFacade::clearBackground()
{
    env->clear();
}