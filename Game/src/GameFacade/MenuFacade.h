#pragma once
#include "RenderIrrlicht.h"
#include "RenderManager.h"

class MenuFacade
{
    private:
    static MenuFacade* only_instance;
    IGUIEnvironment* guienv;
    IGUIImage* img;
    public:

    static MenuFacade *getInstance(){
        if(only_instance == NULL)
            only_instance = new MenuFacade();
            
        return only_instance;
    };


    virtual ~MenuFacade() {}
    virtual void setMenuBackground();
    virtual void setButton(){};
    virtual void clearBackground();
};