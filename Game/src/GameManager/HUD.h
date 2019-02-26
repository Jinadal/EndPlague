class HUD
{
    private:
        float life;
        int numSpawns;
        int score;
        bool terror;
        bool berserk;
        float fps;
        HUD(){};
    public:
        static HUD* getInstance()
        {
            static HUD only_instance;
            return &only_instance;
        }

        void update(float dt);
        int getScore(){return score;}
};