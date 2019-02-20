#include "RenderIrrlicht.h"
class HUDFacade
{
    private:
        //IRRLICHT VALUES
        IGUIImage* layer;
        IGUIImage* life;
        IGUIImage* score;
        IGUIImage* enemys;

        
        
        RenderIrrlicht::getInstance()->getDevice()->getGUIEnvironment()->addImage(driver->getTexture("../../media/irrlichtlogoalpha2.tga"),core::position2d<s32>(10,20));


    public:
        HUDFacade(){}
        ~HUDFacade(){}


}