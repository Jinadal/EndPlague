class GameManager
{
    private:
    
        GameManager(){initAll();}
    
    public:
        ~GameManager(){clear();}
        static GameManager* getInstance(){
            static GameManager only_instance;
            return &only_instance;
        }
        void initAll();
        void clear();
        void updateAll(float dt);
};