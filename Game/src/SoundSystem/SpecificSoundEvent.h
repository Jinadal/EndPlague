#include "SoundSystem.h"


class ShootSoundEvent : public SoundEvent
{
    public:

    ShootSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~ShootSoundEvent() {};

    protected:

    virtual ShootSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};


class AmbientSoundEvent : public SoundEvent
{
    public:

    AmbientSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~AmbientSoundEvent() {};

    void setAttackParameter(float val);
    protected:

    virtual AmbientSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};