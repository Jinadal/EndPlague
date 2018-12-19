#include <fmod_studio.h>

/*
FMOD_RESULT result;
FMOD_STUDIO_SYSTEM *fmod;

class SoundSystem 
{
    private:
	    FMOD_SOUND *sound;
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

*/