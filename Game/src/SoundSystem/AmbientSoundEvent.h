 #include "SoundSystem.h"

class AmbientSoundEvent : public SoundEvent
{
    public:

    AmbientSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~AmbientSoundEvent() {};

    void setAttackParameter(bool bol);
    void setTensionParameter(bool ten);
    protected:

    virtual AmbientSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};