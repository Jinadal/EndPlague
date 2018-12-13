
#include "RenderIrrlicht.h"
#include <iostream>

RenderIrrlicht* RenderIrrlicht::only_instance=NULL;

RenderIrrlicht::RenderIrrlicht(){
    device = createDevice( video::EDT_OPENGL, dimension2d<u32>(1920, 1080), 16,
    false, false, false, InputFacade::getInstance());

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");


    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    //smgr->addLightSceneNode();


    then = device->getTimer()->getTime();
}


void RenderIrrlicht::drawAll()
{
    // Work out a frame delta time.
    const u32 now = device->getTimer()->getTime();
    frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
    then = now;

    driver->beginScene(true, true, SColor(255,100,100,100));

    smgr->drawAll();
    //
    guienv->drawAll();

    driver->endScene();
}

bool RenderIrrlicht::run()
{
    return device->run();
}

void RenderIrrlicht::drop()
{
    device->drop();
}

float RenderIrrlicht::getFrameDeltaTime()
{
    return frameDeltaTime;
}