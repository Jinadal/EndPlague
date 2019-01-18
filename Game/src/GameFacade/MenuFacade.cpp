#include "MenuFacade.h"

MenuFacade* MenuFacade::only_instance = NULL;

void MenuFacade::setMenuBackground()
{
    env = RenderIrrlicht::getInstance()->getGUIEnv();
    img = env->addImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Fondo.png"),position2d<int>(0,0));
    
    //IGUIButton* button = env->addButton(rect<s32>(10,210,100,240), 0, 101, L"New Game");
	IGUIButton* button1 = env->addButton(rect<s32>(10,250,100,290), 0, 102, L"Options");
	IGUIButton* button2 = env->addButton(rect<s32>(10,300,100,340), 0, 103, L"Exit");
    
    env->getSkin()->setColor(gui::EGDC_BUTTON_TEXT, video::SColor(255,0,0,0));

    //button->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    button1->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    button2->setImage(RenderIrrlicht::getInstance()->getDriver()->getTexture("res/Inicio.png"));


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