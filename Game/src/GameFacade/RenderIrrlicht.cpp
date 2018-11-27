#include "RenderIrrlicht.h"
#include <iostream>
RenderIrrlicht::RenderIrrlicht(InputFacade* interface){
    device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
    false, false, false, interface);

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");


    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();


    smgr->addCameraSceneNode(0, vector3df(0,0,-600), vector3df(0,0,0));
    smgr->addLightSceneNode();


    
    then = device->getTimer()->getTime();
}


void RenderIrrlicht::drawAll(){
    // Work out a frame delta time.
    const u32 now = device->getTimer()->getTime();
    frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
    then = now;

    driver->beginScene(true, true, SColor(255,100,100,100));

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

float RenderIrrlicht::getFrameDeltaTime(){
    return frameDeltaTime;
}