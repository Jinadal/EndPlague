/*
#pragma once
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Implementation {
	Implementation();
	~Implementation();

	void Update();
	
	FMOD::Studio::System* mpStudioSystem;
	FMOD::System* mpSystem;

	int mnNextChannelId;

	typedef map<char*, FMOD::Sound*> SoundMap;
	typedef map<int, FMOD::Channel*> ChannelMap;
	typedef map<char*, FMOD::Studio::EventInstance*> EventMap;
	typedef map<char*, FMOD::Studio::Bank*> BankMap;
	BankMap mBanks;
	EventMap mEvents;
	SoundMap mSounds;
	ChannelMap mChannels;
};

class CAudioEngine {
public:
	static void Init();
	static void Update();
	static void Shutdown();
	static int ErrorCheck(FMOD_RESULT result);

	void LoadBank(const char* strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
	void LoadEvent(const char* strEventName);
	void LoadSound(const char* strSoundName, bool b3d = true, bool bLooping = false, bool bStream = false);
	void UnLoadSound(const char* strSoundName);
	void Set3dListenerAndOrientation(const Vector3& vPosition, const Vector3& vLook, const Vector3& vUp);
	int PlaySounds(const char* strSoundName, const Vector3& vPos = Vector3{ 0, 0, 0 }, float fVolumedB = 0.0f);
	void PlayEvent(const char* strEventName);
	void StopChannel(int nChannelId);
	void StopEvent(const char* strEventName, bool bImmediate = false);
	void GetEventParameter(const char* strEventName, const char* strEventParameter, float* parameter);
	void SetEventParameter(const char* strEventName, const char* strParameterName, float fValue);
	void StopAllChannels();
	void SetChannel3dPosition(int nChannelId, const Vector3& vPosition);
	void SetChannelVolume(int nChannelId, float fVolumedB);
	bool IsPlaying(int nChannelId) const;
	bool IsEventPlaying(const char* strEventName) const;
	float dbToVolume(float dB);
	float VolumeTodB(float volume);
	FMOD_VECTOR VectorToFmod(const Vector3& vPosition);
};

*/