#include "TResourceManager.h"
#include <string.h>

TResourceMesh* TResourceManager::getResourceMesh(const char* name)
{
    TResourceMesh* res = NULL;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<mesh.size() && found==false; i++)
    {
        if(strcmp(name,mesh[i]->getName())==0)
        {
            found = true;
            res = mesh[i];
        }
        if(res == NULL)
        {
        res = new TResourceMesh();
            res->setName(name);
            if(res->loadResource())
            {
                mesh.push_back(res);
            }
        }
    }
    return res;
}