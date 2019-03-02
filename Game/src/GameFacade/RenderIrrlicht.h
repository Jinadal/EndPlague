#pragma once
#include <irrlicht.h>
#include "IRender.h"
//Temporal
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MeshNode;
class CameraNode;
class RenderIrrlicht : public IRender{
    private:
        RenderIrrlicht();

        IrrlichtDevice* device;
        IVideoDriver* driver;
        ISceneManager* smgr;
        IGUIEnvironment* guienv;

        ICameraSceneNode* camera;
        IMeshSceneNode* map;
    public:
        
        static RenderIrrlicht* getInstance(){
            static RenderIrrlicht only_instance;
            return &only_instance;
        }
        

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - COMMON FUNCTIONS - - - - - - - - - ----------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------          

        //Draws all the scene, better at the end of loop
        void drawAll();

        //Returns true if cotinues the loop
        bool run();

        //Closes the device
        void drop();

        //Returns the position x, y of the cursor
        float getCursorX();
        float getCursorY();

        //Creates mesh and camera
        MeshNode* createMesh(char* s);
        CameraNode* createCamera();


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - SPECIFIC FUNCTIONS - - - - - - - - - --------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------  

        ITexture* getTexture(char* s);
        IVideoDriver* getDriver(){return driver;}
        IGUIEnvironment* getGUIEnv(){return guienv;}
        //Sets the map
        void isMap(IMeshSceneNode* node){map=node;}
};