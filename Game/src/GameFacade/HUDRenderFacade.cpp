#include "HUDRenderFacade.h"
#include "GameValues.h"
#include <iostream>


void HUDRenderFacade::init()
{
    //////////////////////////////////////////////////
    //============== GET ENVOIRMERNT =================
    //////////////////////////////////////////////////
    env = RenderIrrlicht::getInstance()->getGUIEnv();

    //////////////////////////////////////////////////
    //===============   GET SCALE   ==================
    //////////////////////////////////////////////////

    float screenWidth = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Height;
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);

    //////////////////////////////////////////////////
    //============= GET HUD BACKGROUND ===============
    //////////////////////////////////////////////////

    ITexture* texture = RenderIrrlicht::getInstance()->getDriver()->getTexture("res/sprites/FondoHUD.png");
    dimension2d<u32> original = texture->getOriginalSize();

    float width = (float)original.Width * sw;
    float height = (float)original.Height * sh;

    float x = sw * -6;
    float y = sh * 830.f;

    background = env->addImage(texture ,position2d<int>(x,y));
    background->setScaleImage(true);
    background->setMaxSize(irr::core::dimension2du(width, height));
    background->setMinSize(irr::core::dimension2du(width, height));




    //////////////////////////////////////////////////
    //===============   GET HUD LIFE   ===============
    //////////////////////////////////////////////////

    texture = RenderIrrlicht::getInstance()->getDriver()->getTexture("res/sprites/VidaHUD.png");
    original = texture->getOriginalSize();
    width = (float)original.Width * sw;
    height = (float)original.Height * sh;
    x = sw * 477.f;
    y = sh * 961.f;
    life = env->addImage(texture ,position2d<int>(x, y));
    life->setScaleImage(true);
    life->setMaxSize(irr::core::dimension2du(width, height));
    life->setMinSize(irr::core::dimension2du(width, height));


    //////////////////////////////////////////////////
    //==============   GET HUD SHIELD  ===============
    //////////////////////////////////////////////////

    texture = RenderIrrlicht::getInstance()->getDriver()->getTexture("res/sprites/EscudoHUD.png");
    original = texture->getOriginalSize();

    width = (float)original.Width * sw;
    height = (float)original.Height * sh;

    x = sw * 600.f;
    y = sh * 905.f;

    shield = env->addImage(texture ,position2d<int>(x, y));
    shield->setScaleImage(true);
    shield->setMaxSize(irr::core::dimension2du(width, height));
    shield->setMinSize(irr::core::dimension2du(width, height));
}


void HUDRenderFacade::updateValues(float life, float shield, float fps, int score, int spawns, int weapon)
{

    float screenWidth = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Height;
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);


    dimension2d<u32> original = background->getImage()->getOriginalSize();
    float width = (float)original.Width * sw;
    float height = (float)original.Height * sh;
    float x = sw * -6;
    float y = sh * 830.f;
    background->setRelativePosition(core::rect<s32>(x, y, width+x, height+y));
    background->setMaxSize(irr::core::dimension2du(width, height));
    background->setMinSize(irr::core::dimension2du(width, height));



    original = this->life->getImage()->getOriginalSize();
    width = (float)(original.Width * sw)*(life/gv::PLAYER_LIFE);
    height = (float)original.Height * sh;
    x = sw * 477.f;
    y = sh * 961.f;
    this->life->setRelativePosition(core::rect<s32>(x, y, width+x, height+y));
    this->life->setMaxSize(irr::core::dimension2du(width, height));
    this->life->setMinSize(irr::core::dimension2du(width, height));


    original = this->shield->getImage()->getOriginalSize();
    width = (float)(original.Width * sw)*(shield/gv::SHIELD_VALUE);
    height = (float)original.Height * sh;
    x = sw * 600.f;
    y = sh * 905.f;
    this->shield->setRelativePosition(core::rect<s32>(x, y, width+x, height+y));
    this->shield->setMaxSize(irr::core::dimension2du(width, height));
    this->shield->setMinSize(irr::core::dimension2du(width, height));



    std::cout<<"========= H U D ==========\n";
    std::cout<<"  Life: "<<life<<"\n";
    std::cout<<"  Score: "<<score<<"\n";
    std::cout<<"  Spawns: "<<spawns<<"\n";
    std::cout<<"  FPS: "<<fps<<"\n";
    std::cout<<"==========================\n";
}


void HUDRenderFacade::clear()
{
    env->clear();
}