#include "TResourceManager.h"
#include "TResourceMesh.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"
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

TResourceMaterial* TResourceManager::getResourceMaterial(const char* name)
{
    TResourceMaterial* res = NULL;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<material.size() && found==false; i++)
    {
        if(strcmp(name,material[i]->getName())==0)  // 0 = we've found a coincidence
        {
            found = true;
            res = material[i];
        }
    }
    //No res coincidence loaded before
    if(res == NULL)                             
    {
        res = new TResourceMaterial();
        res->setName(name);
        if(res->loadResource())
        {
            //Load in vector for futures researches
            material.push_back(res);
        }
    }
    return res;
}

TResourceTexture* TResourceManager::getResourceTexture(const char* name)
{
    TResourceTexture* res = NULL;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<texture.size() && found==false; i++)
    {
        if(strcmp(name,texture[i]->getName())==0)
        {
            found = true;
            res = texture[i];
        }
        if(res == NULL)
        {
        res = new TResourceTexture();
            res->setName(name);
            if(res->loadResource())
            {
                texture.push_back(res);
            }
        }
    }
    return res;
}