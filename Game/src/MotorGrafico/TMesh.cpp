#include "TMesh.h"

void TMesh::beginDraw()
{
    if(mesh)
    {
        
        glUniformMatrix4fv(TEntity::modelID, 1, GL_FALSE, &modelMatrix()[0][0]);
        glUniformMatrix4fv(TEntity::viewID, 1, GL_FALSE, &viewMatrix()[0][0]);
        glUniformMatrix4fv(TEntity::projectionID, 1, GL_FALSE, &projectionMatrix()[0][0]);

        mesh->draw();
    }
}