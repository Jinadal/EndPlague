#include "NORender.h"
#include "NOMesh.h"
#include "NOCamera.h"
#include "NOHUD.h"
#include "NOMenu.h"


NORender::NORender()
{
}

void NORender::drawAll()
{
}

bool NORender::run()
{
    if(loops>200)
        return false;

    return true;
}

void NORender::drop()
{
}

float NORender::getCursorX()
{
    return 0.f;
}

float NORender::getCursorY()
{
    return 0.f;
}

FMesh* NORender::createMesh(char* s)
{
    return new NOMesh();
}

FCamera* NORender::createCamera()
{
    return new NOCamera();
}

FHUD* NORender::getHUD()
{

    return NOHUD::getInstance();
}

FMenu* NORender::getMenu()
{
    return NOMenu::getInstance();
}