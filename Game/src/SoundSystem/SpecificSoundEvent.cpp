#include "SpecificSoundEvent.h"

SoundEvent* ShootSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    ShootSoundEvent* sse = new ShootSoundEvent(ei);

    return sse;
}


AmbientSoundEvent* AmbientSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    AmbientSoundEvent* sse = new AmbientSoundEvent(ei);

    return sse;
}

void AmbientSoundEvent::setAttackParameter(float val)
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("ataque", &pParameter));
    SoundSystem::ErrorCheck(pParameter->setValue(val));
}