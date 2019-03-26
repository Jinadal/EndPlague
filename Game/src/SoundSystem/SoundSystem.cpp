#include "SoundSystem.h"
#include "CameraManager.h"
#include <iostream>

SoundSystem* SoundSystem::only_instance = nullptr; 


  

SoundEngineData::SoundEngineData() {
    mpStudioSystem = NULL;
    SoundSystem::ErrorCheck(FMOD::Studio::System::create(&mpStudioSystem));
    SoundSystem::ErrorCheck(mpStudioSystem->initialize(32, FMOD_STUDIO_INIT_LIVEUPDATE, FMOD_INIT_PROFILE_ENABLE, NULL));

    mpSystem = NULL;
    SoundSystem::ErrorCheck(mpStudioSystem->getLowLevelSystem(&mpSystem));
}


SoundEngineData::~SoundEngineData() {
    SoundSystem::ErrorCheck(mpStudioSystem->unloadAll());
    SoundSystem::ErrorCheck(mpStudioSystem->release());
}


void SoundEngineData::Update() {
    std::vector<ChannelMap::iterator> pStoppedChannels;
    for (auto it = mChannels.begin(), itEnd = mChannels.end(); it != itEnd; ++it)
    {
        bool bIsPlaying = false;
        it->second->isPlaying(&bIsPlaying);
        if (!bIsPlaying)
        {
             pStoppedChannels.push_back(it);
        }
    }
    for (auto& it : pStoppedChannels)
    {
         mChannels.erase(it);
    }
    SoundSystem::ErrorCheck(mpStudioSystem->update());
}




void SoundSystem::Init()
{
    SoundSystem::LoadBank("res/media/Master Bank.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Master Bank.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);

    SoundSystem::LoadBank("res/media/Shoot.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
  
    
    SoundSystem::LoadEvent("event:/hacha", "hacha");
    SoundSystem::LoadEvent("event:/pico", "pico");
    SoundSystem::LoadEvent("event:/balleste", "ballesta");



}
void SoundSystem::Update() {
    CameraManager* ca = CameraManager::getInstance();
    Vector3 v3 = {ca->getCX(),ca->getCY(),ca->getCZ()};
    SoundSystem::Set3dListener( v3);
    soundEngineData->Update();

}


void SoundSystem::LoadSound(const std::string& strSoundName, bool b3d, bool bLooping, bool bStream)
{
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt != soundEngineData->mSounds.end())
        return;

    FMOD_MODE eMode = FMOD_DEFAULT;
    eMode |= b3d ? FMOD_3D : FMOD_2D;
    eMode |= bLooping ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
    eMode |= bStream ? FMOD_CREATESTREAM : FMOD_CREATECOMPRESSEDSAMPLE;

    FMOD::Sound* pSound = nullptr;
    SoundSystem::ErrorCheck(soundEngineData->mpSystem->createSound(strSoundName.c_str(), eMode, nullptr, &pSound));
    if (pSound){
        soundEngineData->mSounds[strSoundName] = pSound;
    }

}  



void SoundSystem::UnLoadSound(const std::string& strSoundName)
{
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt == soundEngineData->mSounds.end())
        return;

    SoundSystem::ErrorCheck(tFoundIt->second->release());
    soundEngineData->mSounds.erase(tFoundIt);
}


int SoundSystem::PlaySounds(const std::string& strSoundName, const Vector3& vPosition, float fVolumedB)
{
    int nChannelId = soundEngineData->mnNextChannelId++;
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt == soundEngineData->mSounds.end())
    {
        LoadSound(strSoundName);
        tFoundIt = soundEngineData->mSounds.find(strSoundName);
        if (tFoundIt == soundEngineData->mSounds.end())
        {
            return nChannelId;
        }
    }
    FMOD::Channel* pChannel = nullptr;
    SoundSystem::ErrorCheck(soundEngineData->mpSystem->playSound(tFoundIt->second, nullptr, true, &pChannel));
    if (pChannel)
    {
        FMOD_MODE currMode;
        tFoundIt->second->getMode(&currMode);
        if (currMode & FMOD_3D){
            FMOD_VECTOR position = VectorToFmod(vPosition);
            SoundSystem::ErrorCheck(pChannel->set3DAttributes(&position, nullptr));
        }
        SoundSystem::ErrorCheck(pChannel->setVolume(dbToVolume(fVolumedB)));
        SoundSystem::ErrorCheck(pChannel->setPaused(false));
        soundEngineData->mChannels[nChannelId] = pChannel;
    }
    return nChannelId;
}


void SoundSystem::SetChannel3dPosition(int nChannelId, const Vector3& vPosition)
{
    auto tFoundIt = soundEngineData->mChannels.find(nChannelId);
    if (tFoundIt == soundEngineData->mChannels.end())
        return;

    FMOD_VECTOR position = VectorToFmod(vPosition);
    SoundSystem::ErrorCheck(tFoundIt->second->set3DAttributes(&position, NULL));
}

void SoundSystem::SetChannelVolume(int nChannelId, float fVolumedB)
{
    auto tFoundIt = soundEngineData->mChannels.find(nChannelId);
    if (tFoundIt == soundEngineData->mChannels.end())
        return;

    SoundSystem::ErrorCheck(tFoundIt->second->setVolume(dbToVolume(fVolumedB)));
}


void SoundSystem::LoadBank(const std::string& strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags) {
    auto tFoundIt = soundEngineData->mBanks.find(strBankName);
    if (tFoundIt != soundEngineData->mBanks.end())
        return;
    FMOD::Studio::Bank* pBank;
    SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->loadBankFile(strBankName.c_str(), flags, &pBank));
    if (pBank) {
        soundEngineData->mBanks[strBankName] = pBank;
            // std::cout << "good bank \n";

    }
}



void SoundSystem::LoadEvent(const std::string& strEventName, std::string strSearchName) {
    auto tFoundit = soundEngineData->mEvents.find(strSearchName);
    if (tFoundit != soundEngineData->mEvents.end())
        return;
            // std::cout << "good 1 \n";

    FMOD::Studio::EventDescription* pEventDescription = NULL;
    SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->getEvent(strEventName.c_str(), &pEventDescription));
    if (pEventDescription){
            // std::cout << "good 2 \n";

        FMOD::Studio::EventInstance* pEventInstance = NULL;
        SoundSystem::ErrorCheck(pEventDescription->createInstance(&pEventInstance));
        if (pEventInstance){
            soundEngineData->mEvents[strSearchName] = pEventInstance;
           

           //  std::cout << "good 3 \n";

        }
    }
}


void SoundSystem::PlayEvent(const std::string &strEventName) {
    auto tFoundit = soundEngineData->mEvents.find(strEventName);
    if (tFoundit == soundEngineData->mEvents.end()){
        LoadEvent("event:/" + strEventName, strEventName);
        tFoundit = soundEngineData->mEvents.find(strEventName);
        if (tFoundit == soundEngineData->mEvents.end())
            return;
    }
    tFoundit->second->start();
    //std::cout << "PLAY \n";
}


void SoundSystem::StopEvent(const std::string &strEventName, bool bImmediate) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD_STUDIO_STOP_MODE eMode;
    eMode = bImmediate ? FMOD_STUDIO_STOP_IMMEDIATE : FMOD_STUDIO_STOP_ALLOWFADEOUT;
    SoundSystem::ErrorCheck(tFoundIt->second->stop(eMode));
}

bool SoundSystem::IsEventPlaying(const std::string &strEventName) const {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return false;

    FMOD_STUDIO_PLAYBACK_STATE* state = NULL;
    tFoundIt->second->getPlaybackState(state);
    if ( *state == FMOD_STUDIO_PLAYBACK_PLAYING) {
        return true;
    }
    return false;
}


void SoundSystem::GetEventParameter(const std::string &strEventName, const std::string &strParameterName, float* parameter) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(tFoundIt->second->getParameter(strParameterName.c_str(), &pParameter));
    SoundSystem::ErrorCheck(pParameter->getValue(parameter));
}

void SoundSystem::SetEventParameter(const std::string &strEventName, const std::string &strParameterName, float fValue) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(tFoundIt->second->getParameter(strParameterName.c_str(), &pParameter));
    SoundSystem::ErrorCheck(pParameter->setValue(fValue));
}


FMOD_VECTOR SoundSystem::VectorToFmod(const Vector3& vPosition){
    FMOD_VECTOR fVec;
    fVec.x = vPosition.x;
    fVec.y = vPosition.y;
    fVec.z = vPosition.z;
    return fVec;
}

float  SoundSystem::dbToVolume(float dB)
{
    return powf(10.0f, 0.05f * dB);
}

float  SoundSystem::VolumeTodB(float volume)
{
    return 20.0f * log10f(volume);
}


int SoundSystem::ErrorCheck(FMOD_RESULT result) {
    if (result != FMOD_OK){
        //std::cout << "FMOD ERROR " << result << std::endl;
        return 1;
    }
    //std::cout << "FMOD all good" << std::endl;
    return 0;
}

void SoundSystem::Shutdown() {
    delete soundEngineData;
} 

void SoundSystem::setVolume(float vol)
{
  //  SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->setVolume(vol);

  //no encuentro una forma de hacerlo
}

void SoundSystem::Set3dListener(const Vector3& Pos)
{
   

    FMOD_VECTOR pos = VectorToFmod(Pos);
    FMOD_VECTOR vel = VectorToFmod({0,0,0});
    FMOD_VECTOR forw = VectorToFmod({0,0,0});
    FMOD_VECTOR up = VectorToFmod({0,0,0});

        FMOD_3D_ATTRIBUTES att = {pos, vel, forw, up} ;
     
        
        soundEngineData->mpStudioSystem->setListenerAttributes(0,&att);
}

FMOD::Studio::EventInstance* SoundSystem::getEventInstanceFromName(std::string eventName)
{
    auto tFoundIt = soundEngineData->mEvents.find(eventName);
   // if (!tFoundIt == soundEngineData->mEvents.end())


   
        return tFoundIt->second;
    
}

///////////////////////SOUND EVENT///////////////////////////////


SoundEvent::SoundEvent(FMOD::Studio::EventInstance* eventInstance)
{
    soundInstance = eventInstance;
}


void SoundEvent::start()
{
    SoundSystem::ErrorCheck(soundInstance->start());
}

void SoundEvent::stop()
{
    SoundSystem::ErrorCheck(soundInstance->stop(FMOD_STUDIO_STOP_IMMEDIATE) ); //FMOD_STUDIO_STOP_ALLOWFADEOUT
}

void SoundEvent::pause()
{
    SoundSystem::ErrorCheck(soundInstance->setPaused(true) );
}

void SoundEvent::setVolume(float vol)
{
    SoundSystem::ErrorCheck(soundInstance->setVolume(vol) );

}

void SoundEvent::setGain(float gain)
{
    float vol = 0.f;
    SoundSystem::ErrorCheck(soundInstance->getVolume(&vol));
    vol = vol * gain;
    SoundSystem::ErrorCheck(soundInstance->setVolume(vol));
}

void SoundEvent::setPosition(Vector3 pos)
{
    FMOD_3D_ATTRIBUTES atrib;

       atrib.position =  SoundSystem::getInstance()->VectorToFmod(pos);
       atrib.velocity = SoundSystem::getInstance()->VectorToFmod({0,0,0});
       atrib.forward = SoundSystem::getInstance()->VectorToFmod({0,0,0});
       atrib.up = SoundSystem::getInstance()->VectorToFmod({0,0,0});

    

    SoundSystem::ErrorCheck(soundInstance->set3DAttributes(&atrib));
}

bool SoundEvent::isPlaying()
{
    bool res = false;
    FMOD_STUDIO_PLAYBACK_STATE* state = NULL;
   
    SoundSystem::ErrorCheck(soundInstance->getPlaybackState(state));

    if (*state == FMOD_STUDIO_PLAYBACK_PLAYING) res = true;

    return res;
}