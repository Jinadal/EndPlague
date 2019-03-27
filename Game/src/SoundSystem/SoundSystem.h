#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <string>
#include <map>
#include <vector>
#include <math.h>



struct Vector3 {
    float x;
    float y;
    float z;
};

class SoundEvent;

struct SoundEngineData {
    SoundEngineData();
    ~SoundEngineData();

    void Update();

    FMOD::Studio::System* mpStudioSystem;
    FMOD::System* mpSystem;

    int mnNextChannelId;

    typedef std::map<std::string, FMOD::Sound*> SoundMap;
    typedef std::map<int, FMOD::Channel*> ChannelMap;
    typedef std::map<std::string, FMOD::Studio::EventInstance*> EventMap;
    typedef std::map<std::string, FMOD::Studio::Bank*> BankMap;
    typedef std::map<std::string, FMOD::Studio::EventDescription* > EventDescMap;
    typedef std::map<std::string, SoundEvent* > SoundEventMap;

    EventDescMap mEventsDescriptions;
    BankMap mBanks;
    EventMap mEvents;
    SoundMap mSounds;
    ChannelMap mChannels;
    SoundEventMap mSoundEvents;
};

class SoundEvent;

class SoundSystem {

 private:
         SoundEngineData* soundEngineData;
	  
        static SoundSystem* only_instance;
        SoundSystem(){soundEngineData = new SoundEngineData();}
 public:
        static SoundSystem* getInstance()
        {
            if(!only_instance) only_instance = new SoundSystem();

            return only_instance;
        }

    ~SoundSystem(){only_instance = nullptr; Shutdown();}
    
    
    void Update();
    void Shutdown();
   static int ErrorCheck(FMOD_RESULT result);
    void Init();
    void LoadBank(const std::string& strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
    void LoadEvent(const std::string& strEventName, std::string strSearchName);
    void LoadSound(const std::string& strSoundName, bool b3d = true, bool bLooping = false, bool bStream = false);
    void UnLoadSound(const std::string& strSoundName);
    void Set3dListener(const Vector3& Pos);
    int PlaySounds(const std::string& strSoundName, const Vector3& vPos = Vector3{ 0, 0, 0 }, float fVolumedB = 0.0f);
    void PlayEvent(const std::string& strEventName);
    void StopChannel(int nChannelId);
    void StopEvent(const std::string& strEventName, bool bImmediate = false);
    void GetEventParameter(const std::string& strEventName, const std::string& strEventParameter, float* parameter);
    void SetEventParameter(const std::string& strEventName, const std::string& strParameterName, float fValue);
    void StopAllChannels();
    void SetChannel3dPosition(int nChannelId, const Vector3& vPosition);
    void SetChannelVolume(int nChannelId, float fVolumedB);
    bool IsPlaying(int nChannelId) const;
    bool IsEventPlaying(const std::string& strEventName) const;
    float dbToVolume(float db);
    float VolumeTodB(float volume);
    void setVolume(float vol);
    FMOD_VECTOR VectorToFmod(const Vector3& vPosition);
    void saveEvent(SoundEvent* s, const std::string& strEventName);
    SoundEvent* getEvent(const std::string& strEventName);
    FMOD::Studio::EventInstance* getEventInstanceFromName(std::string eventName);
}; 

class SoundEvent {
public:
    SoundEvent(FMOD::Studio::EventInstance* eventInstance);
    virtual ~SoundEvent() {}; 
    
    virtual void start();
 
    void stop();
    void pause();
    void setVolume(float vol);
    void setGain(float gain);
    void setPosition(Vector3 pos);
    bool isPlaying();

    FMOD::Studio::EventInstance* getSoundInstance(){return soundInstance;}
    
protected:
    FMOD::Studio::EventInstance* soundInstance;
  
    virtual SoundEvent* newSoundEvent(FMOD::Studio::EventInstance*) = 0;
};





//SEGUIR IMPLEMENTANDO LOS SOUNDEVENTS, CAMBIAR NOMBRE A LOS OTROS EVENTOS, Y HACER EL TRANSPASO DE SOUNDSYSTEM2