class TEntity
{
    private:
        /* data */
    public:
        TEntity();
        ~TEntity();

        virtual void beginDraw() = 0;
        virtual void endDraw() = 0;
};