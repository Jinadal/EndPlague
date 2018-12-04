#pragma once
#include "CameraNode.h"
#include "Component.h"
#include "GameObject.h"


class CameraComponent : public Component{
    private:
        CameraNode* node;
        float x, y, z, dMAX=10.f; 
    public:
        CameraComponent(GameObject* parent, Manager* m) : Component(parent, m)
        {
            node = new CameraNode();
            dMAX = 0.f;
            x = parent->getX();
            y = parent->getY();
            z = parent->getZ();
        }

        ~CameraComponent()
        {
            delete node;
        }

        void update();
        void setFOV(f32 fov);

};