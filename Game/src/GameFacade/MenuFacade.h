#pragma once
#include "RenderIrrlicht.h"

class MenuFacade
{
    private:
        IGUIEnvironment* env;
        IGUIImage* img;
        MenuFacade(){};
    public:
    static MenuFacade* getInstance(){
        static MenuFacade only_instance;
        return &only_instance;
    }
    


    virtual ~MenuFacade() {}
    virtual void setMenuBackground();
    virtual IGUIButton* createButton(int x,int y,int xx,int xy, int id);
    virtual void clearBackground();
    virtual void update(){}
};