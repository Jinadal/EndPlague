#pragma once
#include "Component.h"
#include "PhysicBullet.h"
#include "GameObject.h"

class BPhysicComponent : public Component 
{
    private:
        btRigidBody* rbody;
        float tx = 0.f, ty = 0.f;
        float vMax=10.f;
    public:
        ~BPhysicComponent(){PhysicBullet::getInstance()->removeRigidBody(rbody);};
        BPhysicComponent(GameObject* owner, Manager* manager, float xsize, float ysize, float zsize, float mass, int physicType) : Component(owner, manager)
        {
            btVector3 position = btVector3(owner->getX(), owner->getY(), owner->getZ());
            btVector3 size = btVector3(xsize, ysize, zsize);

            rbody = PhysicBullet::getInstance()->createRigidBody(position, size, mass, physicType);
            
            rbody->applyTorque(btVector3(0, 0, owner->getRZ()));

            rbody->setUserPointer((void *)(gameObject));
        }

        void update();
        void moveObject(float x, float y, float z, float tx, float ty);
        void setvMax(float v){vMax = v;};
        void setVelocity(float x, float y, float z);
        void setGravity(float x,float y,float z){rbody->setGravity(btVector3(x, y, z));};
};