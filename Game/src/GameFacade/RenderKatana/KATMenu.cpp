#include "KATMenu.h"
#include "KATRender.h"
#include "TSprite.h"

void KATMenu::setMenuBackground(char* t)
{
    background = KATRender::getInstance()->getKatana()->createSprite(t);
}

void KATMenu::clearBackground()
{
    KATRender::getInstance()->getKatana()->removeSprite(background);
}