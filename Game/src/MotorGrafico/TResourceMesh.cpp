#include "TResourceMesh.h"

bool TResourceMesh::loadResource()
{
    bool ret = false;
    Assimp::Importer importer;

    //Assimp uses an aiScene object to represent the loaded mesh.
    const aiScene* pScene = importer.ReadFile(name, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices);
    
    if (pScene)
    {
        for(unsigned int i = 0; i < pScene->mNumMeshes; i++)
        {
            aiMesh* m = pScene->mMeshes[i];
            loadMesh(m);
        }
    }

    return ret;
} 

void TResourceMesh::loadMesh(aiMesh* m)
{   
    TResourceMesh* mesh = new TResourceMesh();
    glGenBuffers(3, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m->mVertices), m->mVertices, GL_STATIC_DRAW);    

    if(m->HasNormals())
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m->mNormals), m->mNormals, GL_STATIC_DRAW);    
    }

    if(m->HasTextureCoords(0))
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m->mTextureCoords[0]), m->mTextureCoords[0], GL_STATIC_DRAW);    
    }



    meshes.push_back(mesh);
}