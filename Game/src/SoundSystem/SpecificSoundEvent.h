#include "SoundSystem.h"


class ShootSoundEvent : public SoundEvent
{
    public:

    ShootSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~ShootSoundEvent() {};
    void setVoice();

    protected:

    virtual ShootSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};


class AmbientSoundEvent : public SoundEvent
{
    public:

    AmbientSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~AmbientSoundEvent() {};

    void setAttackParameter(bool bol);
    protected:

    virtual AmbientSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};

class FireSoundEvent : public SoundEvent
{
    public:

    FireSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~FireSoundEvent() {};

    protected:

    virtual FireSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};

class HitSoundEvent : public SoundEvent
{
    public:

    HitSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~HitSoundEvent() {};

    protected:

    virtual HitSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};