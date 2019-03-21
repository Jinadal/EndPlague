#include "KATMesh.h"
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL 
#include "TEntity.h"
#include "TTransform.h"
void KATMesh::setPosition(float x, float y, float z)
{
    std::cout<<"Posicion: "<<x<<" - "<<y<<"\n";
    TTransform* matrix = (TTransform*)mesh->getFather()->getEntity();
    glm::mat4 actual = mesh->getEntity()->modelMatrix();
    matrix->translate(x, y, z);
}

void KATMesh::setRotation(float x, float y, float z)
{

}

void KATMesh::setVisible(bool b)
{

}

void KATMesh::setTexture(char* s)
{

}

void KATMesh::isMap()
{

}