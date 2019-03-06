#include "LOTRender.h"
#include "LOTMesh.h"
#include "LOTCamera.h"
#include "LOTHUD.h"
#include "LOTMenu.h"

LOTRender::LOTRender()
{
    //window = render.initWindow();
}
void LOTRender::drawAll()
{

}

bool LOTRender::run()
{
    return true;
    //return render.openWindow(window);
}

void LOTRender::drop()
{

}

float LOTRender::getCursorX()
{
    return 0.f;
}

float LOTRender::getCursorY()
{
    return 0.f;
}

FMesh* LOTRender::createMesh(char* s)
{
    return new LOTMesh();
}

FCamera* LOTRender::createCamera()
{
    return new LOTCamera();
}

FHUD* LOTRender::getHUD()
{
    return LOTHUD::getInstance();
}

FMenu* LOTRender::getMenu()
{
    return LOTMenu::getInstance();
}
