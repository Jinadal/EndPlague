
#include "TResource.h"
#include <iostream>
#include <vector>


class TResourceMesh : public TResource
{
private:
    std::vector<TResourceMesh*> meshes;

    GLuint *buffer, *faces, *meshbuffer;
    GLuint  VAO;
    GLfloat* textures;
    int meshbuffersize;

public:
    TResourceMesh(){};
    ~TResourceMesh();

    void loadMesh(aiMesh* m, int n);
    bool loadResource();
    void draw();
};

