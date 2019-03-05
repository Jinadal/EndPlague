#pragma once
#include <irrlicht.h>
#include "FRender.h"

class IRRRender : public FRender{
    private:
        IRRRender();

        irr::IrrlichtDevice* device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* guienv;

        irr::scene::ICameraSceneNode* camera;
        irr::scene::IMeshSceneNode* map;
    public:
        
        static IRRRender* getInstance(){
            static IRRRender only_instance;
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
        FMesh* createMesh(char* s);
        FCamera* createCamera();
        FHUD* getHUD();
        FMenu* getMenu();

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - SPECIFIC FUNCTIONS - - - - - - - - - --------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------  

        irr::video::ITexture* getTexture(char* s);
        irr::video::IVideoDriver* getDriver(){return driver;}
        irr::gui::IGUIEnvironment* getGUIEnv(){return guienv;}
        //Sets the map
        void isMap(irr::scene::IMeshSceneNode* node){map=node;}
};