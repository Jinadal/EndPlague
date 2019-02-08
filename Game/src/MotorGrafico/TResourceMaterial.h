
class TResource;
class TResourceMaterial : public TResource
{
private:
    /* data */
public:
    TResourceMaterial() = default;
    ~TResourceMaterial() = default;

    bool loadResource(){return false;}; 
    void draw(){};
};
