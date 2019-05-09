#include "Render.h"
#include "KATRender.h"
#include "IRRRender.h"
#include "NORender.h"
#include "GameValues.h"

Render::Render(){
    if(gv::RENDER_ENGINE == 1)
    {
        render = KATRender::getInstance();
    }else if(gv::RENDER_ENGINE == 2)
    {
        render = IRRRender::getInstance();
    }else{
        render = NORender::getInstance();
    }
}

void Render::drawAll(){render->drawAll();}

bool Render::run(){return render->run();}

void Render::drop(){render->drop();}

float Render::getCursorX(){return render->getCursorX();}
float Render::getCursorY(){return render->getCursorY();}

FMesh* Render::createMesh(char* s){return render->createMesh(s);}
FCamera* Render::createCamera(){return render->createCamera();}
FHUD* Render::getHUD(){return render->getHUD();}
FMenu* Render::getMenu(){return render->getMenu();}
FSprite* Render::getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b){return render->getSprite(texture, x, y, sx, sy, rot, r, g, b);}