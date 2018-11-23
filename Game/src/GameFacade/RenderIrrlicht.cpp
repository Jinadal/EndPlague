#include "RenderIrrlicht.h"

void RenderIrrlicht::drawAll(){

    driver->beginScene(true, true, SColor(255,100,101,140));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
}