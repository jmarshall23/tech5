/*
===========================================================================
Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

Windows XAudio2 adaptation; see the corresponding source file.
===========================================================================
*/
#pragma once

#include "../soundvoice.h"

class idSoundHardware_XAudio2;

class idSoundEngineCallback : public IXAudio2EngineCallback {
public:
	idSoundEngineCallback() : hardware( NULL ) {}
	void STDMETHODCALLTYPE OnProcessingPassStart() override {}
	void STDMETHODCALLTYPE OnProcessingPassEnd() override {}
	void STDMETHODCALLTYPE OnCriticalError( HRESULT error ) override;
	idSoundHardware_XAudio2 * hardware;
};

class idSoundHardware_XAudio2 {
public:
	idSoundHardware_XAudio2();
	void Init();
	void Shutdown();
	void Update();
	void SetReverb( const void * environment );
	idSoundVoice * AllocateVoice( const idSoundSample * leadin, const idSoundSample * looping );
	void FreeVoice( idSoundVoice * voice );
	IXAudio2 * GetIXAudio2() const { return pXAudio2; }
	int GetNumSpeakers() const { return outputChannels; }
	int GetSpeakerMask() const { return channelMask; }

	IXAudio2 * pXAudio2;
	IXAudio2MasteringVoice * pMasterVoice;
	IXAudio2SubmixVoice * pSubmixVoice;
	idSoundEngineCallback soundEngineCallback;
	float dryGain;
	int outputChannels;
	int channelMask;
	class idDebugGraph * vuMeterRMS;
	class idDebugGraph * vuMeterPeak;
	int vuMeterPeakTimes[ 8 ];
	idStaticList< idSoundVoice_XAudio2, 96 > voices;
	idStaticList< idSoundVoice_XAudio2 *, 96 > zombieVoices;
	idStaticList< idSoundVoice_XAudio2 *, 96 > freeVoices;
};

class idSoundHardware : public idSoundHardware_XAudio2 {};
