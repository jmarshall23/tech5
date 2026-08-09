#pragma once

class idDecl;
class idRenderWorld;
class idSoundWorld;

class idSoundSystem {
public:
	virtual ~idSoundSystem() {}
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	virtual idSoundWorld * AllocSoundWorld( const char * name, idRenderWorld * renderWorld ) = 0;
	virtual void FreeSoundWorld( idSoundWorld * soundWorld ) = 0;
	virtual void SetPlayingSoundWorld( idSoundWorld * soundWorld ) = 0;
	virtual idSoundWorld * GetPlayingSoundWorld() = 0;
	virtual void SetEditorSoundWorld( idSoundWorld * soundWorld ) = 0;
	virtual idSoundWorld * GetEditorSoundWorld() = 0;
	virtual void Render( bool threaded ) = 0;
	virtual void WaitForSoundThread() = 0;
	virtual void MuteBackgroundMusic( bool mute ) = 0;
	virtual void SetMute( bool mute ) = 0;
	virtual bool IsMuted() = 0;
	virtual void OnReloadSound( const idDecl * sound ) = 0;
	virtual void StopAllSounds() = 0;
	virtual void InitStreamBuffers() = 0;
	virtual void FreeStreamBuffers() = 0;
	virtual void * GetIXAudio2() = 0;
	virtual int GetNumSpeakers() = 0;
	virtual int GetSpeakerMask() = 0;
};

extern idSoundSystem * soundSystem;
