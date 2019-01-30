class TEntity
{
    private:
        /* data */
    public:
        TEntity();
        virtual ~TEntity();

        virtual void beginDraw() = 0;
        virtual void endDraw() = 0;
};