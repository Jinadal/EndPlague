#pragma once
#include "RenderIrrlicht.h"

class MenuFacade
{
    private:
    static MenuFacade* only_instance;
    IGUIEnvironment* env;
    IGUIImage* img;
    public:

    static MenuFacade *getInstance(){
        if(!only_instance)
            only_instance = new MenuFacade();
            
        return only_instance;
    };


    virtual ~MenuFacade() {}
    virtual void setMenuBackground();
    virtual IGUIButton* createButton(int x,int y,int xx,int xy, int id);
    virtual void clearBackground();
    virtual void update(){}
};