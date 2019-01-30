#include "TResourceManager.h"

TResource* TResourceManager::getResource(char* name)
{
    TResource* rec;
    for(unsigned int i=0; i<resource.size(); i++)
    {
        if(name == resource[i]->getName())
        {
            rec=resource[i];
        }
        if(rec == nullptr)
        {
            //Y AQUI NO SE QUE VA AÚN
        }
    }
    return rec;
}