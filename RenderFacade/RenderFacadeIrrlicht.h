#include <RendenderFacade.h>

class RenderFacadeIrrlicht : public RendenderFacadeI
{
    private:
        IrrlichtDevice* device;
        video::IVideoDriver* driver;
        scene::ISceneManager* smgr;
    public:
        RenderFacadeIrrlicht(){
            device = createDevice(driverType,
			core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

            if (device == 0)
                return 1; // could not create selected driver.

            driver = device->getVideoDriver();
            smgr = device->getSceneManager();
        }

        int addSceneNode():

        IrrlichtDevice* getDevice(){retrun device;}
        video::IVideoDriver* getDriver(){return driver;}
        scene::ISceneManager* getSceneManager(){return smgr;}
};