#include "TMesh.h"

void TMesh::beginDraw()
{
    if(mesh)
    {
        glm::mat4 pm = projectionMatrix();
        glm::mat4 vm = viewMatrix();
        glm::mat4 mm = modelMatrix();

        glm::mat4 mvp = pm * vm * mm;
        glUniformMatrix4fv(getMVPID(),1,GL_FALSE,&mvp[0][0]);
        mesh->draw();
    }
}