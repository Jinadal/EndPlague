#include "IRRCamera.h"
#include "RenderIrrlicht.h"


void IRRCamera::update(float x, float y, float z, float rx, float ry, float rz)
{
    node->setPosition(irr::core::vector3d<irr::f32>(x, y, z));
    node->setTarget(irr::core::vector3d<irr::f32>(rx, ry, rz));
}

void IRRCamera::setFOV(float fov)
{
    node->setFOV(fov);
}
