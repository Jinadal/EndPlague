#include  "RenderComponent.h"




void add2DSprite(String s){
    video::ITexture* sprint = driver->getTexture("Art/life.png");
    driver->makeColorKeyTexture(sprite, core::position2d<s32>(0,0));
}

void update(){
    driver->draw2DImage(s_Castle, 
                        core::position2d<s32>(sprite->getX(), castle1->getY()), 
                        core::rect<s32>(0,0,200,200), 
                        0,
                        video::SColor(255,255,255,225), true);
}