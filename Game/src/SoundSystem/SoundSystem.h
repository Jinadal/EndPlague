#include <fmod_studio.h>


class SoundSystem 
{
    private:
        static SoundSystem* only_instance;
        SoundSystem();
    public:
        static SoundSystem* getInstance()
        {
            if(!only_instance) only_instance = new SoundSystem();

            return only_instance;
        }

        ~SoundSystem(){only_instance = nullptr;}


        void init(const char* filename);
        void play(float volume);
        void pause();
};