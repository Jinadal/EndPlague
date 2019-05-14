#include "TResourceAnimation.h"

TResourceAnimation::~TResourceAnimation()
{
    for(unsigned int i = 0; i < frame.size(); i++)
    {
        delete frame[i];
    }
    frame.clear();
}

bool TResourceAnimation::loadResource()
{
    bool ret = false;
    std::string path = name;
    for(int i = 1; i < frames; i++)
    {
        if(i < 10)
        {  
            path += "00";
        }
        else if(i <100)
        {
            path+= "0";
        }
        path += std::to_string(i) + ".obj";
        TResourceOBJ* obj = new TResourceOBJ(true);
        obj->setName(path.c_str());
        obj->loadResource();
        frame.push_back(obj);
        ret = true;
    }
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(name,0);
    if(scene)
    {
        for(unsigned int i = 1; i<scene->mNumMaterials; i++)
        {
            TResourceMaterial* mat = new TResourceMaterial();
            mat->loadResource(scene->mMaterials[i]);
            for(unsigned int j = 0; j < frame.size(); j++)
            {
                frame[j]->setMaterial(mat);
            }
        }
    }
    return ret;
}
