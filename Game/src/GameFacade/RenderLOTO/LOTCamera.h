#pragma once
#include "FCamera.h"

class LOTCamera : public FCamera
{
    public:
        LOTCamera(){};
        ~LOTCamera(){};
        void update(float x, float y, float z, float rx, float ry, float rz);
        void setFOV(float fov);
};