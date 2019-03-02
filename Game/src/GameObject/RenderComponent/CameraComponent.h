#pragma once
#include "CameraNode.h"
#include "RenderIrrlicht.h"
#include "Component.h"
#include "GameObject.h"

class GameObject;
class CameraComponent : public Component{
    private:
        CameraNode* node;
        float x, y, z;
        float rz;
        float zoom = 1.f;
    public:
        CameraComponent(GameObject* parent, Manager* m) : Component(parent, m)
        {
            node = RenderIrrlicht::getInstance()->createCamera();
            x = parent->getX();
            y = parent->getY();
            z = parent->getZ();
            rz = 0.f;
        }

        ~CameraComponent()
        {
            delete node;
        }

        void update(float dt);
        void setFOV(f32 fov);
        void setZoom(float dt);

};