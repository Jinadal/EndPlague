#include <iostream>
#include <irrlicht.h>
#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"


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


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(){

	RenderFacade* renderfacade =new RenderFacade(1); //1 = Irrlicht
	RenderManager* rendermanager= new RenderManager(renderfacade);

	rendermanager->init();

	
	IrrlichtDevice *device = createDevice(EDT_OPENGL,
		core::dimension2d<u32>(1136, 640));

		GameObject *bola = new GameObject(100,100);

	if (device == 0)
		return 1; // could not create selected driver.



		CollisionManager *collision = new CollisionManager();

		collision->createComponent(bola,40.f,40.f,false);


	GameObject* background =new GameObject(0, 0);
	RenderComponent* rc = new RenderComponent(background);
	background->addComponent(rc);
	rendermanager->addComponent(rc);

	
	while(rendermanager->run())

	video::IVideoDriver* driver = device->getVideoDriver();
    

	driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
	driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;

	
	while(device->run() && driver)

	{
		rendermanager.update();
		if (device->isWindowActive())
		{
			u32 time = device->getTimer()->getTime();

			driver->beginScene(true, true, video::SColor(255,120,102,136));

	
			driver->draw2DImage(images, core::position2d<s32>(0,0),core::rect<s32>(0,0,1136,640), 0,
			video::SColor(255,255,255,255), true);
			


			
			
			
			//driver->draw2DImage(ball, core::position2d<s32>(arrow->x,arrow->y),core::rect<s32>(0,0,30,30), 0,
			//video::SColor(255,255,255,255), true);
			// draw some text
			driver->draw2DRectangle(video::SColor(100,255,255,255), core::rect<s32>(bola->getX()-20,bola->getY()-20,bola->getX()+20,bola->getY()+20 ));

			core::position2d<s32> m = device->getCursorControl()->getPosition();
			driver->draw2DRectangle(video::SColor(100,255,255,255),
				core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20));



			collision->update();

			driver->endScene();
	
		}
	}
    std::cin.get();

	collision->removecomponent(bola->getComponent<CollisionComponent>());

	//delete driver;
    //delete device;
	delete collision;
	delete bola;
}