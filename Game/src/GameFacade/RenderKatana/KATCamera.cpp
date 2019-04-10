#include "KATCamera.h"
#include "KATRender.h"
#include "TNode.h"
#include "TCamera.h"

void KATCamera::update(float x, float y, float z, float rx, float ry, float rz)
{
    TTransform* matrix = (TTransform*)camera->getFather()->getEntity();
    matrix->identity();
    matrix->translate(-x, y, z);


   //KATRender::getInstance()->setCamera(-x, y, z, -rx, ry, rz);
}

void KATCamera::setFOV(float fov)
{
    
}