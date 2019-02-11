#include "TResource.h"

class TResource;
class TResourceTexture : public TResource
{
private:
    /* data */
public:
    TResourceTexture(/* args */) = default;
    ~TResourceTexture() = default;

    bool loadResource(){return false;}; 
    void draw(){};
};
