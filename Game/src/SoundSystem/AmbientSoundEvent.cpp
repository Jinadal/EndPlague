#include "AmbientSoundEvent.h"


AmbientSoundEvent* AmbientSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    AmbientSoundEvent* sse = new AmbientSoundEvent(ei);

    return sse;
}

void AmbientSoundEvent::setAttackParameter(bool bol)
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("ataque", &pParameter));
    //float val = bol? 1.f : 0.f;
    SoundSystem::ErrorCheck(pParameter->setValue(bol));
}