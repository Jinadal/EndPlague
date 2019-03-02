#pragma once
#include "RenderIrrlicht.h"
#include "FCamera.h"

class IRRCamera : public FCamera{
    private:
        irr::scene::ICameraSceneNode* node;
    public:
        IRRCamera(irr::scene::ICameraSceneNode* node){this->node = node;}

        ~IRRCamera(){}

        void update(float x, float y, float z, float rx, float ry, float rz);
        void setFOV(float fov);

};
