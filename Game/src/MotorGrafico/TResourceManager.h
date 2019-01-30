#include <vector>
#include "TResource.h"

class TResourceManager
{
private:
    std::vector<TResource*> resource;

public:
    TResourceManager(/* args */);
    ~TResourceManager();

    TResource* getResource(char* name);
};
