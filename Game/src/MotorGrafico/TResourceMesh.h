
#include "TResource.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/ext.hpp>

class TResourceMesh : public TResource
{
private:
    std::vector<TResourceMesh*> meshes;
    

    //VBO Buffer handler
    GLuint* VBO;
    //IBO Buffer handler
    GLuint IBO;
public:
    TResourceMesh() = default;
    ~TResourceMesh() = default;

    void loadMesh(aiMesh* m);
    bool loadResource();
    void draw(){};
};
