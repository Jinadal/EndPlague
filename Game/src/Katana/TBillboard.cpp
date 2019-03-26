#include "TBillboard.h"

TBillboard::TBillboard(TResourceTexture* t, glm::vec3 p)
{
    texture = t;
    position = p;
    glGenBuffers(1, &buffer);
}

void TBillboard::beginDraw()
{
     if(texture != nullptr)
    {
        texture->draw();
        
        GLuint VertexArrayID;
	    glGenVertexArrays(1, &VertexArrayID);
	    glBindVertexArray(VertexArrayID);

        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(position), &position[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_POINTS, 0, 1);
        glDisableVertexAttribArray(0);
    }
}