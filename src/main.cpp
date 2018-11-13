#include <iostream>
#include <irrlicht.h>
#include "GameObject.h"
#include "AnimationComponent.h"
#include "AnimationManager.h"
#include "AudioComponent.h"
#include "AudioManager.h"
#include "BehaviourIAComponent.h"
#include "BraveryIAComponent.h"
#include "CombatComponent.h"
#include "CombatManager.h"
#include "Component.h"
#include "IAComponent.h"
#include "IAManager.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "ItemComponent.h"
#include "ItemManager.h"
#include "MeleeCombatComponent.h"
#include "PhysicComponent.h"
#include "PhysicManager.h"
#include "RangeCombatComponent.h"
#include "RenderComponent.h"
#include "RenderManager.h"
#include "SpawnComponent.h"
#include "SpawnManager.h"

using namespace std;

using namespace irr;

/*
There are 5 sub namespaces in the Irrlicht Engine. Take a look at them, you can
read a detailed description of them in the documentation by clicking on the top
menu item 'Namespace List' or by using this link:
http://irrlicht.sourceforge.net/docu/namespaces.html
Like the irr namespace, we do not want these 5 sub namespaces now, to keep this
example simple. Hence, we tell the compiler again that we do not want always to
write their names.
*/
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(){
	//GameObject* arrow = new GameObject(10,10,2);
	//MovementComponent* m = new MovementComponent(arrow);
	//ManagerMovement* mc = new ManagerMovement();
	//arrow->addComponent(m);
	//mc->addComponentMovement(m);

	/*
	The most important function of the engine is the createDevice()
	function. The IrrlichtDevice is created by it, which is the root
	object for doing anything with the engine. createDevice() has 7
	parameters:

	- deviceType: Type of the device. This can currently be the Null-device,
	   one of the two software renderers, D3D8, D3D9, or OpenGL. In this
	   example we use EDT_SOFTWARE, but to try out, you might want to
	   change it to EDT_BURNINGSVIDEO, EDT_NULL, EDT_DIRECT3D8,
	   EDT_DIRECT3D9, or EDT_OPENGL.

	- windowSize: Size of the Window or screen in FullScreenMode to be
	   created. In this example we use 640x480.

	- bits: Amount of color bits per pixel. This should be 16 or 32. The
	   parameter is often ignored when running in windowed mode.

	- fullscreen: Specifies if we want the device to run in fullscreen mode
	   or not.

	- stencilbuffer: Specifies if we want to use the stencil buffer (for
	   drawing shadows).

	- vsync: Specifies if we want to have vsync enabled, this is only useful
	   in fullscreen mode.

	- eventReceiver: An object to receive events. We do not want to use this
	   parameter here, and set it to 0.

	Always check the return value to cope with unsupported drivers,
	dimensions, etc.
	*/
	IrrlichtDevice *device = createDevice(EDT_OPENGL,
		core::dimension2d<u32>(1136, 640));

	if (device == 0)
		return 1; // could not create selected driver.

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	video::IVideoDriver* driver = device->getVideoDriver();
    
	/*
	Set the caption of the window to some nice text. Note that there is an
	'L' in front of the string. The Irrlicht Engine uses wide character
	strings when displaying text.
	*/

	/*
	All 2d graphics in this example are put together into one texture,
	2ddemo.png. Because we want to draw colorkey based sprites, we need to
	load this texture and tell the engine, which part of it should be
	transparent based on a colorkey.

	In this example, we don't tell it the color directly, we just say "Hey
	Irrlicht Engine, you'll find the color I want at position (0,0) on the
	texture.". Instead, it would be also possible to call
	driver->makeColorKeyTexture(images, video::SColor(0,0,0,0)), to make
	e.g. all black pixels transparent. Please note that
	makeColorKeyTexture just creates an alpha channel based on the color.
	*/
	video::ITexture* images = driver->getTexture("Art/background-hd.png");
	driver->makeColorKeyTexture(images, core::position2d<s32>(0,0));

	video::ITexture* ball = driver->getTexture("Art/ball.jpg");
	driver->makeColorKeyTexture(ball, core::position2d<s32>(0,0));
	/*
	Prepare a nicely filtering 2d render mode for special cases.
	*/
	driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
	driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;

	/*
	Everything is prepared, now we can draw everything in the draw loop,
	between the begin scene and end scene calls. In this example, we are
	just doing 2d graphics, but it would be no problem to mix them with 3d
	graphics. Just try it out, and draw some 3d vertices or set up a scene
	with the scene manager and draw it.
	*/
	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{
			u32 time = device->getTimer()->getTime();

			driver->beginScene(true, true, video::SColor(255,120,102,136));

			//mc->update();
			/*
			First, we draw 3 sprites, using the alpha channel we
			created with makeColorKeyTexture. The last parameter
			specifies that the drawing method should use this alpha
			channel. The last-but-one parameter specifies a
			color, with which the sprite should be colored.
			(255,255,255,255) is full white, so the sprite will
			look like the original. The third sprite is drawn
			with the red channel modulated based on the time.
			*/

			// draw fire & dragons background world
			driver->draw2DImage(images, core::position2d<s32>(0,0),core::rect<s32>(0,0,1136,640), 0,
			video::SColor(255,255,255,255), true);
			
			//driver->draw2DImage(ball, core::position2d<s32>(arrow->x,arrow->y),core::rect<s32>(0,0,30,30), 0,
			//video::SColor(255,255,255,255), true);
			// draw some text

			core::position2d<s32> m = device->getCursorControl()->getPosition();
			driver->draw2DRectangle(video::SColor(100,255,255,255),
				core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20));

			driver->endScene();
	
		}
	

	}
    std::cin.get();

    delete device;
}