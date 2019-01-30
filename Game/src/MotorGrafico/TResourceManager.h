#include "TResource.h"
#include "TResourceMesh.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"
#include <vector>

class TResourceManager
{
private:
    std::vector<TResourceMesh*> mesh;
    std::vector<TResourceMaterial*> material;
    std::vector<TResourceTexture*> texture;


public:
    TResourceManager(/* args */);
    ~TResourceManager();

    TResourceMesh* getResourceMesh(const char* name);
    TResource* getResourceMaterial(char* name);
    TResource* getResourceTexture(char* name);
};
