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


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(){
	RenderFacade* renderfacade =new RenderFacade(1); //1 = Irrlicht
	RenderManager* rendermanager= new RenderManager(renderfacade);

	rendermanager->init();

	GameObject* background =new GameObject(0, 0);
	RenderComponent* rc = new RenderComponent(background);
	background->addComponent(rc);
	rendermanager->addComponent(rc);

	rc->add2DSprite("../sprites/background.png");


	
	while(rendermanager->run())
	{
		rendermanager.update();
		if (device->isWindowActive())
		{
			u32 time = device->getTimer()->getTime();

			driver->beginScene(true, true, video::SColor(255,120,102,136));
	
			driver->draw2DImage(images, core::position2d<s32>(0,0),core::rect<s32>(0,0,1136,640), 0,
			video::SColor(255,255,255,255), true);
			
			core::position2d<s32> m = device->getCursorControl()->getPosition();
			driver->draw2DRectangle(video::SColor(100,255,255,255),
				core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20));

			driver->endScene();
	
		}
	}
    std::cin.get();

    delete device;
}