
#include "TResource.h"

class TResourceMesh : public TResource
{
private:
    float* vertex, normals, texture;
    float* vertTriangles, normTriangles, textTriangles;
    long nTriangles;
public:
    TResourceMesh() = default;
    ~TResourceMesh() = default;

    bool loadResource(){return false;}; 
    void draw(){};
};
