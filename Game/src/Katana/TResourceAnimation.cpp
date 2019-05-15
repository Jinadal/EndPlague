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

    TResourceOBJ* obj = new TResourceOBJ(true);
    obj->setName(path.c_str());
    if(obj->loadResource())
    {
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

void TResourceAnimation::draw()
{
    for(unsigned int i = 0; i < frame.size(); i++)
    {
        if(texture != NULL)
        {
            texture->draw();
        }
        frame[i]->draw();
    }
}