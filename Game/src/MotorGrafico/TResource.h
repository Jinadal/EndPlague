class TResource
{
    protected:
        const char* name;
    public:
        TResource(){};
        ~TResource();

        const char* getName(){ return name;};
        void setNombre(char* n){ name = n;};
};