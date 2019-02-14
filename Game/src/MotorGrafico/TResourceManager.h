#include <vector>
#include <iostream>
class TResource;
class TResourceMesh;
class TResourceMaterial;
class TResourceTexture;
class TResourceManager
{
private:
    std::vector<TResourceMesh*> mesh;
    std::vector<TResourceMaterial*> material;
    std::vector<TResourceTexture*> texture;


public:
    TResourceManager(/* args */){}
    ~TResourceManager();

    TResourceMesh* getResourceMesh(const char* name);
    TResourceMaterial* getResourceMaterial(const char* name);
    TResourceTexture* getResourceTexture(const char* name);
};
