#include "KATHUD.h"
#include "KATRender.h"
#include "GameValues.h"
#include <iostream>

void KATHUD::init()
{
    //////////////////////////////////////////////////
    //===============   GET SCALE   ==================
    //////////////////////////////////////////////////
    int screenWidth, screenHeight;
    KATRender::getInstance()->getKatana()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);

//    background = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/FondoHUD.png");
//
//    float width = background->getWidth() * sw * 1.f;
//    float height = background->getHeight() * sh * 1.f;
//
//    float x = sw * -6;
//    float y = sh * 830.f;
//
//    background->position = glm::vec2(x, y);
//    background->size = glm::vec2(width, height);

    //////////////////////////////////////////////////
    //===============   GET HUD LIFE   ===============
    //////////////////////////////////////////////////

    life = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/VidaHUD.png");

    float width   = life->getWidth() * sw * 1.f;
    float height  = life->getHeight() * sh * 1.f;
    float x = sw * 477.f;
    float y = sh * 961.f;

    life->position = glm::vec2(x, y);
    life->size = glm::vec2(width, height);
}

void KATHUD::clear()
{
    KATRender::getInstance()->getKatana()->removeSprite(background);
    KATRender::getInstance()->getKatana()->removeSprite(life);

}

void KATHUD::updateValues(float life, float shield, float fps, int score, int spawns, int weapon)
{
    int screenWidth, screenHeight;
    KATRender::getInstance()->getKatana()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);


//    float width     = (float)background->getWidth() * sw;
//    float height    = (float)background->getHeight() * sh;
//    float x = sw * -6;
//    float y = sh * 830.f;
//    background->position = glm::vec2(x, y);
//    background->size = glm::vec2(width, height);


    float width = (float)(this->life->getWidth() * sw)*(life/gv::PLAYER_LIFE);
    float height = (float)this->life->getHeight() * sh;
    float x = sw * 477.f;
    float y = sh * 961.f;

    this->life->position = glm::vec2(x, y);
    this->life->size = glm::vec2(width, height);


    //std::cout<<"========= H U D ==========\n";
    //std::cout<<"  Life: "<<life<<"\n";
    //std::cout<<"  Score: "<<score<<"\n";
    //std::cout<<"  Spawns: "<<spawns<<"\n";
    //std::cout<<"  FPS: "<<fps<<"\n";
    //std::cout<<"==========================\n";
}