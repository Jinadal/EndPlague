#include "TResourceMesh.h"
#include <iostream>

TResourceMesh::~TResourceMesh()
{
    //glDeleteBuffers(1,&faces);
    //glDeleteBuffers(bsize,b);    
    //glDeleteVertexArrays(1,&VAO);
    //delete textures;
}

bool TResourceMesh::loadResource()
{
    bool ret = false;
    Assimp::Importer importer;

    //Assimp uses an aiScene object to represent the loaded mesh.
    const aiScene* scene = importer.ReadFile(name, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout<< "Error: " << importer.GetErrorString() << std::endl;
    }   
    
    if (scene)
    {
         std::cout<<name<<std::endl;
        bsize = scene->mNumMeshes;
        for(unsigned int i = 0; i < scene->mNumMeshes; i++)
        {

            b = (unsigned int *)malloc(sizeof(unsigned int) * scene->mNumMeshes * 4);
            aiMesh* m = scene->mMeshes[i];
            loadMesh(m,i);
            ret = true;
        }
    }

    return ret;
} 

void TResourceMesh::loadMesh(aiMesh* m, int n)
{   
    faces = (unsigned int *)malloc(sizeof(unsigned int) * m->mNumFaces * 3);   
    int j = 0;
    for(unsigned int i = 0; i < m->mNumFaces; i++)
    {
        const aiFace* f = &m->mFaces[i];
        memcpy(&faces[j], f->mIndices,sizeof(unsigned int) * 3);    
        j+=3; 
    }
  
    buffer = (unsigned int *)malloc(sizeof(unsigned int) * 4);
    glGenBuffers(4, buffer);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m->mNumFaces * 3, faces, GL_STATIC_DRAW);

    if(m->HasPositions())
    {
        glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * m->mNumVertices * 3, m->mVertices, GL_STATIC_DRAW);    
        glEnableVertexAttribArray(1);
    }

    if(m->HasNormals())
    {
        glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * m->mNumVertices * 3, m->mNormals, GL_STATIC_DRAW);    
        glEnableVertexAttribArray(2);
    }

    if(m->HasTextureCoords(0))
    {
        textures=(float *)malloc(sizeof(float) * 2 * m->mNumVertices);
        for(unsigned int k = 0; k < m->mNumVertices;k++)
        {
            textures[k*2] = m->mTextureCoords[0][k].x;
            textures[k*2+1] = m->mTextureCoords[0][k].y;
        }
        glBindBuffer(GL_ARRAY_BUFFER, buffer[3]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * 2 * m->mNumVertices, textures , GL_STATIC_DRAW);    
        glEnableVertexAttribArray(3);
    }    

    //Detach elements
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    b[n*4]=buffer[0];
    b[n*4+1]=buffer[1];
    b[n*4+2]=buffer[2];
    b[n*4+3]=buffer[3];
}

void TResourceMesh::draw()
{
    for(int i = 0; i < bsize; i++)
    {
         //BIND VAO
        glBindVertexArray(VAO);
        //==============================================  


        //Bind and pass to OpenGL the fourth array (vertex indices)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b[i*4]);

        //Bind and pass to OpenGL the first array (vertex coordinates)
        glBindBuffer(GL_ARRAY_BUFFER, b[i*4+1]);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(i*4+1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

        //Bind and pass to OpenGL the second array (vertex normals)
        glBindBuffer(GL_ARRAY_BUFFER, b[i*4+2]);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(i*4+2, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

        //Bind and pass to OpenGL the third array (vertex texture coordinates)
        glBindBuffer(GL_ARRAY_BUFFER, b[i*4+3]);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(i*4+3, 2, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

        //We order to draw here
        glDrawElements(GL_TRIANGLES, bsize, GL_UNSIGNED_INT, 0);


        //==============================================    
        //Detach elements
        glDisableVertexAttribArray(i*4+3);
        glDisableVertexAttribArray(i*4+2);
        glDisableVertexAttribArray(i*4+1);
        glBindVertexArray(i*4);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}