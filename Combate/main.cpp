#include <iostream>
//#include <irrlicht.h>
#include "GameObject.h"
#include "Component.h"
#include "ShootComponent.h"
#include "ShootManager.h"
#include "ProjectileComponent.h"
#include "ProjectileManager.h"
#include "LifeComponent.h"
#include "LifeManager.h"
#include <ncurses.h>

using namespace std;

//using namespace irr;

/*
There are 5 sub namespaces in the Irrlicht Engine. Take a look at them, you can
read a detailed description of them in the documentation by clicking on the top
menu item 'Namespace List' or by using this link:
http://irrlicht.sourceforge.net/docu/namespaces.html
Like the irr namespace, we do not want these 5 sub namespaces now, to keep this
example simple. Hence, we tell the compiler again that we do not want always to
write their names.
*/
//using namespace core;
//using namespace scene;
//using namespace video;
//using namespace io;
//using namespace gui;

int main(){
	GameObject* 	enemy = new GameObject(10,10);
	ShootComponent*  	s = new ShootComponent(enemy);
	LifeComponent* 	 	l = new LifeComponent(enemy);
	GameObject* character = new GameObject(20,20);
	ShootComponent*    cs = new ShootComponent(character);
	LifeComponent* 	   cl = new LifeComponent(character);
	ShootManager* 	   sm = ShootManager::getInstance();
	LifeManager*	   lm = LifeManager::getInstance();
	ProjectileManager* pm = ProjectileManager::getInstance();
	enemy->addComponent(s);
	enemy->addComponent(l);
	character->addComponent(cs);
	character->addComponent(cl);
	sm->addShootComponent(s);
	lm->addLifeComponent(l);
	sm->addShootComponent(cs);
	lm->addLifeComponent(cl);

	//int asd = enemy->getComponent<LifeComponent*>()->getLife();
	//std::cout<<asd<<std::endl;
	//l->looseLife(1);
	//s->Shoot();
	//sm->update();
	//ProjectileComponent* projectile;
	//projectile = pm->getVectorPC()[0];
	//int coas = projectile->getDamage();
	//std::cout<<"Los damages: "<<coas<<std::endl;
	//l->update();
	//int com = enemy->getComponent<LifeComponent*>()->getLife();
	//std::cout<<com<<std::endl;
	//projectile->dealDamage(enemy);
}