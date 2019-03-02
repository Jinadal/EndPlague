#pragma once
#include "RenderIrrlicht.h"

class CameraNode{
    private:
        ICameraSceneNode* node;
    public:
        CameraNode(ICameraSceneNode* node){this->node = node;}

        ~CameraNode()
        {
            //delete node;
        }

        void update(float x, float y, float z, float rx, float ry, float rz);
        void setFOV(float fov);

};
