#include "KATMenu.h"
#include "KATRender.h"

void KATMenu::setMenuBackground(char* t)
{
    background = KATRender::getInstance()->createBillboard(t, 0, -0.5, -0.01);
}

void KATMenu::clearBackground()
{

}