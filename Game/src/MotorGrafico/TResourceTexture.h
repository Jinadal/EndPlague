#include <GL/glew.h>
#include <SFML/Graphics.hpp>

class TResource;
class TResourceTexture : public TResource
{
private:
    GLuint textureID;

public:
    TResourceTexture(/* args */) = default;
    ~TResourceTexture() = default;

    bool loadResource(); 
    void draw(){};
};
