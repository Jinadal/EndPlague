#pragma once
#include "PhysicBullet.h"
#include "GameObject.h"
#include <iostream>

class BPhysicComponent : public Component 
{
    private:
        btRigidBody* rbody;
    public:
        ~BPhysicComponent(){};
        BPhysicComponent(GameObject* owner, Manager* manager, float xsize, float ysize, float zsize, float mass) : Component(owner, manager)
        {
            btVector3 position = btVector3(owner->getX(), owner->getY(), owner->getZ());
            btVector3 size = btVector3(xsize, ysize, zsize);
            rbody = PhysicBullet::getInstance()->createRigidBody(position, size, mass);
            rbody->setUserPointer((void *)(gameObject));
        }

        void update();
        void setVelocity(float x, float y, float z);
};