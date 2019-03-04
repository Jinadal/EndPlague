#include <vector>
#include <iostream>
#include <GL/glew.h>

class TResource;
class TResourceMesh;
class TResourceMaterial;
class TResourceTexture;
class TResourceShader;
class TResourceManager
{
private:
    std::vector<TResourceMesh*> mesh;
    std::vector<TResourceMaterial*> material;
    std::vector<TResourceTexture*> texture;
    std::vector<TResourceShader*> shader;


public:
    TResourceManager(/* args */){}
    ~TResourceManager();

    TResourceMesh* getResourceMesh(const char* name);
    TResourceMaterial* getResourceMaterial(const char* name);
    TResourceTexture* getResourceTexture(const char* name);
    TResourceShader* getResourceShader(const char* name, GLenum type);
};
