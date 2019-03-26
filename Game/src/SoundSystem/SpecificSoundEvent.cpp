#include "SpecificSoundEvent.h"

SoundEvent* ShootSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    ShootSoundEvent* sse = new ShootSoundEvent(ei);

    return sse;
}