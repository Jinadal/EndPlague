#include <irrlicht.h>


//Temporal
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class RenderIrrlicht {
    private:
        IrrlichtDevice* device;
        IVideoDriver* driver;
        ISceneManager* smgr;
        IGUIEnvironment* guienv;

        int lastFPS;
        u32 then;
        f32 frameDeltaTime;
    public:
        RenderIrrlicht();

        ~RenderIrrlicht(){}

        //Geters
        IrrlichtDevice* getDevice(){return device;}
        IVideoDriver* getDriver(){return driver;}
        ISceneManager* getSMgr(){return smgr;}
        IGUIEnvironment* getGUIEnv(){return guienv;}

        //Draws all the scene, better at the end of loop
        void drawAll();
        //Returns true if cotinues the loo
        bool run();
        //Closes the device
        void drop();
        //Returns the time betwen las loop and now
        float getFrameDeltaTime();

};