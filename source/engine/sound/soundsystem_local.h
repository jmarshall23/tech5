#pragma once

#include "soundsystem.h"
#include "soundworld_local.h"
#include "xaudio2/xa2_soundhardware.h"

class idSoundThread : public idSysThread {
public:
	idSoundThread();
	int Run() override;
	void Render();
	bool initialized;
};

class idSoundSystemLocal : public idSoundSystem {
public:
	struct bufferContext_t {
		idSoundVoice_XAudio2 * voice;
		void * buffer;
		unsigned int sampleRate;
	};

	idSoundSystemLocal();
	~idSoundSystemLocal() override;
	void Init() override;
	void Shutdown() override;
	idSoundWorld * AllocSoundWorld( const char * name, idRenderWorld * renderWorld ) override;
	void FreeSoundWorld( idSoundWorld * soundWorld ) override;
	void SetPlayingSoundWorld( idSoundWorld * soundWorld ) override;
	idSoundWorld * GetPlayingSoundWorld() override { return currentSoundWorld; }
	void SetEditorSoundWorld( idSoundWorld * soundWorld ) override;
	idSoundWorld * GetEditorSoundWorld() override { return editorSoundWorld; }
	void Render( bool threaded ) override;
	void WaitForSoundThread() override;
	void MuteBackgroundMusic( bool mute ) override { musicMuted = mute; }
	void SetMute( bool mute ) override { muted = mute; }
	bool IsMuted() override { return muted; }
	void OnReloadSound( const idDecl * sound ) override;
	void StopAllSounds() override;
	void InitStreamBuffers() override;
	void FreeStreamBuffers() override;
	void * GetIXAudio2() override { return hardware.GetIXAudio2(); }
	int GetNumSpeakers() override { return hardware.GetNumSpeakers(); }
	int GetSpeakerMask() override { return hardware.GetSpeakerMask(); }

	void Restart();
	idSoundVoice * AllocateVoice( const idSoundSample * leadin, const idSoundSample * looping );
	void FreeVoice( idSoundVoice * voice );
	void StopVoicesWithSample( const idSoundSample * sample );
	bufferContext_t * ObtainStreamBufferContext();
	void ReleaseStreamBufferContext( bufferContext_t * context );

	idSysMutex streamBufferMutex;
	int soundTime;
	idSoundWorldLocal * editorSoundWorld;
	idSoundWorldLocal * currentSoundWorld;
	idStaticList< idSoundWorldLocal *, 32 > soundWorlds;
	idSoundHardware hardware;
	idStaticList< bufferContext_t *, 144 > freeStreamBufferContexts;
	idStaticList< bufferContext_t *, 144 > activeStreamBufferContexts;
	idStaticList< bufferContext_t, 144 > bufferContexts;
	idRandom2 random;
	bool muted;
	bool musicMuted;
	bool needsRestart;
	bool soundThreadRunning;
	idSoundThread * soundThread;
	idParallelJobList * parallelJobList;
};

extern idSoundSystemLocal soundSystemLocal;
