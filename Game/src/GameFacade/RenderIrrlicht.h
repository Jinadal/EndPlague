#pragma once
#include <irrlicht.h>

//Temporal
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class RenderIrrlicht{
    private:
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
        
        static RenderIrrlicht* getInstance(){
            static RenderIrrlicht only_instance;
            return &only_instance;
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
        void drawPoint(float x, float y, float z);
};