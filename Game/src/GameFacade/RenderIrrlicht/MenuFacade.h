#pragma once
#include "IRRRender.h"

class MenuFacade
{
    private:
        irr::gui::IGUIEnvironment* env;
        irr::gui::IGUIImage* img;
        MenuFacade(){};
    public:
    static MenuFacade* getInstance(){
        static MenuFacade only_instance;
        return &only_instance;
    }
    


    virtual ~MenuFacade() {}
    virtual void setMenuBackground();
    virtual irr::gui::IGUIButton* createButton(int x,int y,int xx,int xy, int id);
    virtual void clearBackground();
    virtual void update(){}
};