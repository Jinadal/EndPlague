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
    for(int i = 0; i < frames; i++)
    {
        std::string path = name;
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
    return ret;
}
