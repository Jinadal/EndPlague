#pragma once
#include <irrlicht.h>
#include "InputFacade.h"

//Temporal
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class RenderIrrlicht{
    private:
        static RenderIrrlicht* only_instance;

        RenderIrrlicht();

        IrrlichtDevice* device;
        IVideoDriver* driver;
        ISceneManager* smgr;
        IGUIEnvironment* guienv;

        ICameraSceneNode* camera;
        IMeshSceneNode* map;

        u32 then;
        f32 frameDeltaTime;
    public:
        
        virtual ~RenderIrrlicht(){only_instance=NULL;}
        static RenderIrrlicht* getInstance(){
            if(only_instance==NULL){
                only_instance = new RenderIrrlicht();
            }
            return only_instance;
        }

        //Geters
        IrrlichtDevice* getDevice(){return device;}
        IVideoDriver* getDriver(){return driver;}
        ISceneManager* getSMgr(){return smgr;}
        IGUIEnvironment* getGUIEnv(){return guienv;}
        void setCamera(ICameraSceneNode* node){camera=node;}

        //Draws all the scene, better at the end of loop
        void drawAll();
        //Returns true if cotinues the loo
        bool run();
        //Closes the device
        void drop();
        //Returns the time betwen las loop and now
        float getFrameDeltaTime();
        float getCursorX();
        float getCursorY();
        void isMap(IMeshSceneNode* node){map=node;}
};