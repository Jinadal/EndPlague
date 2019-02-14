#pragma once
#include "Component.h"
#include "PhysicBullet.h"
#include "GameObject.h"
#define PI 3.14159265

class BPhysicComponent : public Component 
{
    private:
        btRigidBody* rbody;
        float tx = 0.f, ty = 0.f;
        float vMax=10.f;
    public:
        ~BPhysicComponent(){PhysicBullet::getInstance()->removeRigidBody(rbody);};
        BPhysicComponent(GameObject* owner, 
                            Manager* manager, 
                            float xsize, 
                            float ysize, 
                            float zsize, 
                            float mass, 
                            int physicType);
        BPhysicComponent(GameObject* owner, Manager* manager, char* filename);
        void update();
        void moveObject(float x, float y, float z, float tx, float ty);
        void setvMax(float v){vMax = v;};
        void setVelocity(float x, float y, float z);
        void setGravity(float x,float y,float z){rbody->setGravity(btVector3(x, y, z));};
};