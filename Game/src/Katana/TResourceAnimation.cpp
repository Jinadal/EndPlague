#include "TResourceAnimation.h"
#include "GameValues.h"

TResourceAnimation::TResourceAnimation(int f)
{
    numFrames = f;
}
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
    bool ret = true;
    std::string path;
    std::string o(".obj");
    TResourceOBJ* obj;
    for(int i = 1; i<=numFrames; i++)
    {
        obj = new TResourceOBJ(true);
    
        path = name + std::to_string(i) + o;

        obj->setName(path.c_str());
        if(obj->loadResource())
        {
            frame.push_back(obj);
        }else{ret = false;}
    }
    //Assimp::Importer importer;
    //const aiScene* scene = importer.ReadFile(name,0);
    //if(scene)
    //{
    //    for(unsigned int i = 1; i<scene->mNumMaterials; i++)
    //    {
    //        TResourceMaterial* mat = new TResourceMaterial();
    //        mat->loadResource(scene->mMaterials[i]);
    //        for(unsigned int j = 0; j < frame.size(); j++)
    //        {
    //            frame[j]->setMaterial(mat);
    //        }
    //    }
    //}
    return ret;
}

void TResourceAnimation::draw()
{

    dt += 0.1f;
    if(dt>1/gv::FRAMES_PER_SECOND)
    {
        frameToRender++;

        if(frameToRender>=frame.size())
            frameToRender = 0;
    }
    //
    //for(unsigned int i = 0; i < frame.size(); i++)
    //{
        //if(texture != NULL)
        //{
        //    texture->draw();
        //}
        frame[frameToRender]->draw();
    //}
}