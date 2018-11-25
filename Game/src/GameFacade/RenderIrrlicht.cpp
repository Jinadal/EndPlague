#include "RenderIrrlicht.h"

RenderIrrlicht::RenderIrrlicht(){
    device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
    false, false, false, 0);

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");


    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();


    smgr->addCameraSceneNode(0, vector3df(0,0,100), vector3df(0,0,0));
}


void RenderIrrlicht::drawAll(){
    driver->beginScene(true, true, SColor(255,100,101,140));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
}

bool RenderIrrlicht::run(){
    return device->run();
}

void RenderIrrlicht::drop(){
    device->drop();
}