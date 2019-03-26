#include "SoundSystem.h"


class ShootSoundEvent : public SoundEvent
{
    public:

    ShootSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~ShootSoundEvent() {};

    protected:

    virtual SoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};
