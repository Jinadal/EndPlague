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

        const char* getName(){ return name;};
        void setName(const char* n){ name = n;};
};
