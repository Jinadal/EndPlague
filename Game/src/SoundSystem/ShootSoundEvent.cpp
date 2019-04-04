#include "ShootSoundEvent.h" 
#include <ctime>

ShootSoundEvent* ShootSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    ShootSoundEvent* sse = new ShootSoundEvent(ei);

    return sse;
}

void ShootSoundEvent::setVoice()
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("voice", &pParameter));
    std::srand((unsigned) time(0));
    int i = (rand()%3)+1;
    float val = i;
    SoundSystem::ErrorCheck(pParameter->setValue(val));
}

