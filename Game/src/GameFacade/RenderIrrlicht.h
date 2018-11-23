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
    public:
        RenderIrrlicht(){
            device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

            if (!device)
                return;

            device->setWindowCaption(L"Screams In Goblin");


            driver = device->getVideoDriver();
            smgr = device->getSceneManager();
            guienv = device->getGUIEnvironment();


            smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
        }

        ~RenderIrrlicht(){}

        IrrlichtDevice* getDevice(){return device;}
        IVideoDriver* getDriver(){return driver;}
        ISceneManager* getSMgr(){return smgr;}
        IGUIEnvironment* getGUIEnv(){return guienv;}


        void drawAll(){

            driver->beginScene(true, true, SColor(255,100,101,140));

            smgr->drawAll();
            guienv->drawAll();

            driver->endScene();
        }

        bool run(){
            return device->run();
        }

        void drop(){
            device->drop();
        }
};