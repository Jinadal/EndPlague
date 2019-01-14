
#include "RenderIrrlicht.h"

RenderIrrlicht* RenderIrrlicht::only_instance=NULL;

RenderIrrlicht::RenderIrrlicht(){
    device = createDevice( video::EDT_OPENGL, dimension2d<u32>(1920, 1080), 16,
    false, false, false, 0);

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");


    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    smgr->addLightSceneNode(0, core::vector3df(10,0,-100),
    video::SColorf(1.0f,1.0f,1.0f,1.0f), 1000.0f);

 



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


float RenderIrrlicht::getCursorX()
{
    ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    core::vector3df     outCollisionPoint;
    core::triangle3df   outTriangle;
    ISceneNode*         outNode=nullptr;

    ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    return outCollisionPoint.X;
}

float RenderIrrlicht::getCursorY()
{
     ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    core::vector3df     outCollisionPoint;
    core::triangle3df   outTriangle;
    ISceneNode*         outNode=nullptr;

    ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    return outCollisionPoint.Y;
}