#include "MenuFacade.h"

void MenuFacade::setMenuBackground()
{
    env = RenderIrrlicht::getInstance()->getGUIEnv();
    ITexture* texture = RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Fondo.png");
    dimension2d<u32> original = texture->getOriginalSize();
    

    
    float screenWidth = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)RenderIrrlicht::getInstance()->getDriver()->getScreenSize().Height;
    

    float sx = (float)(screenWidth / (float)original.Width);
    float sy = (float)(screenHeight / (float)original.Height);

    img = env->addImage(texture ,position2d<int>(0,0));
    img->setScaleImage(true);
    img->setMaxSize(irr::core::dimension2du(screenWidth, screenHeight));
    img->setMinSize(irr::core::dimension2du(screenWidth, screenHeight));
    //IGUIButton* button = env->addButton(rect<s32>(10,210,100,240), 0, 101, L"New Game");
	//IGUIButton* button1 = env->addButton(rect<s32>(10,250,100,290), 0, 102, L"Options");
	//IGUIButton* button2 = env->addButton(rect<s32>(10,300,100,340), 0, 103, L"Exit");
    
    //env->getSkin()->setColor(gui::EGDC_BUTTON_TEXT, video::SColor(255,0,0,0));

    //button->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    //button1->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    //button2->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));


}
IGUIButton* MenuFacade::createButton(int x,int y,int xx,int xy, int id){
    IGUIButton* button = env->addButton(rect<s32>(x,y,xx,xy), 0, id,  L"New Game");
    button->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    return button;
}
void MenuFacade::clearBackground()
{
    env->clear();
}
//void MenuFacade::update()
//{
//		if (event.EventType == EET_GUI_EVENT)
//		{
//			s32 id = event.GUIEvent.Caller->getID();
//			//IGUIEnvironment* env = RenderIrrlicht::getInstance()->getGUIEnv();
////
//			//switch(event.GUIEvent.EventType)
//			//{
//            //    case EGET_BUTTON_CLICKED:
////
//				if (id == 101)
//				{
//                    std::cout<<"holis"<<std::endl;
//			//		RenderIrrlicht::getInstance()->getDevice()->closeDevice();
//			    }
//
//			//}
//		}
//            
//        
//}