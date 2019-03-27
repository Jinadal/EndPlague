#include <vector>
#include <iostream>
#include <../../lib/GL/glew.h>

class TResource;
class TResourceMesh;
class TResourceOBJ;
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
    std::vector<TResourceOBJ*> obj;


public:
    TResourceManager(){}
    ~TResourceManager();
    std::vector<std::string> split(std::string str,std::string sep);

    TResourceMesh* getResourceMesh(const char* name);
    TResourceOBJ* getResourceOBJ(const char* name);
    TResourceMaterial* getResourceMaterial(const char* name);
    TResourceTexture* getResourceTexture(const char* name);
    TResourceShader* getResourceShader(const char* name, GLenum type);
};
