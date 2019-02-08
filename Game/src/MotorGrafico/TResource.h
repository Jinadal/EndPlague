#pragma once
class TResource
{
    protected:
        const char* name;
    public:
        TResource(){};
        ~TResource();

        virtual bool loadResource() = 0;
        virtual void draw() = 0;

        virtual const char* getName(){ return name;};
        virtual void setName(const char* n){ name = n;};
};
