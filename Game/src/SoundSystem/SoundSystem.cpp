#include "SoundSystem.h"


SoundSystem* SoundSystem::only_instance = nullptr;

SoundSystem::SoundSystem()
{
    
}



void SoundSystem::init(const char* filename)
{
    FMOD_STUDIO_SYSTEM* system = nullptr;

    FMOD_Studio_System_Initialize(system, 
                                    2,
                                    FMOD_STUDIO_INIT_NORMAL,
                                    FMOD_INIT_NORMAL,
                                    0);
    /*
    result = fmod->createSound(this->filename.c_str(), FMOD_DEFAULT, 0, &(this->sound));
	if (result != FMOD_OK) {
		return false;
	}
	return true;
    */
}

void SoundSystem::play(float volume)
{

}

void SoundSystem::pause()
{

}