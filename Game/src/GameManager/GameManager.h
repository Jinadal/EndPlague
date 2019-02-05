class GameManager
{
    private:
        static GameManager* only_instance;
        GameManager(){initAll();}
    
    public:
        ~GameManager(){deleteAll();}
        static GameManager* getInstance()
        {
            if(!only_instance)
                only_instance = new GameManager();

            return only_instance;
        }
        void initAll();
        void deleteAll();
        void updateAll(float dt);
};