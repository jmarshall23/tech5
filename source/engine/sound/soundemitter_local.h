#pragma once

#include "soundemitter.h"
#include "soundvoice.h"
#include "occlusion/soundocclusion.h"

class idSoundWorldLocal;
class idRenderWorld;

class idSoundFade {
public:
	idSoundFade();
	void Clear();
	void SetVolume( float to );
	float GetVolume( int soundTime ) const;
	void Fade( float to, int length, int soundTime, int delay = 0 );
	int fadeStartTime;
	int fadeEndTime;
	float fadeStartVolume;
	float fadeEndVolume;
};

class idSoundEmitterLocal;

class idSoundChannel {
public:
	idSoundChannel();
	~idSoundChannel();
	bool CanMute() const;
	void Mute();
	bool IsLooping() const;
	bool CheckForCompletion( int currentTime ) const;
	void SetSilent();
	void UpdateVolume( float volumeAdd, int currentTime );
	void UpdateHardware( float volumeAdd, int currentTime, int listenerId );
	millisecond_t GetCurrentSampleTime( int currentTime ) const;

	idSoundEmitterLocal * emitter;
	int startTime;
	int endTime;
	soundChannel_t logicalChannel;
	soundShaderParms_t parms;
	const idSoundShader * soundShader;
	idSoundSample * sample;
	idSoundFade volumeFade;
	idSoundFade pitchFade;
	float randomVolume;
	float randomPitch;
	float dopplerPitch;
	float volumeDB;
	float currentAmplitude;
	float currentShakeAmplitude;
	idSoundVoice * hardwareVoice;
	idLinkList< idSoundChannel > channelNode;
	float voiceVolumeOffsetDB;
	float dryVolumeDB;
	float wetVolumeDB;
};

class alignas(4) idSoundEmitterLocal : public idSoundEmitter {
public:
	idSoundEmitterLocal();
	~idSoundEmitterLocal() override;
	void Init( int emitterIndex, idSoundWorldLocal * world );
	int CheckForCompletion( int currentTime );
	float Update( struct listener_t * listener, int currentTime );
	void OnReloadSound( const idSoundShader * declaration );
	void DrawDebugInfo( idRenderWorld * renderWorld );

	int Index() override { return index; }
	void Free( bool immediate ) override;
	void Reset() override;
	void UpdateEmitter( const idVec3 * newOrigin, const idMat3 * newAxis,
		const idVec3 * newVelocity, int newEmitterId ) override;
	int StartSound( soundChannel_t channel, const idSoundShader * shader,
		const soundShaderParms_t * overrideParms = NULL ) override;
	void ModifySound( soundChannel_t channel, const idSoundShader * shader,
		const soundShaderParms_t * overrideParms ) override;
	void StopSound( soundChannel_t channel ) override;
	void SetVolume( soundChannel_t channel, float volume ) override;
	void SetPitch( soundChannel_t channel, float pitch ) override;
	void FadeSound( soundChannel_t channel, float to, float over, float delay,
		bool stopWhenDone ) override;
	void FadePitch( soundChannel_t channel, float to, float over, float delay ) override;
	bool IsCurrentlyPlaying( soundChannel_t channel ) override;
	void SetVolumeAdjustment( float volume ) override { volumeAdjustment = volume; }
	void ClearVolumeAdjustment() override { volumeAdjustment = 0.0f; }
	float GetVolumeAdjustment() override { return volumeAdjustment; }
	const idSoundShader * GetCurrentSoundShader( soundChannel_t channel ) override;
	idSoundSample * GetCurrentSample( soundChannel_t channel ) override;
	millisecond_t GetCurrentSampleTime( soundChannel_t channel ) override;
	millisecond_t GetRemainingSampleTime( soundChannel_t channel ) override;
	bool GetDebugInfo( int channel, soundDebugInfo_t * info ) override;
	void SetDebugName( const char * name ) override { debugName = name; }
	const char * GetDebugName() override { return debugName != NULL ? debugName : ""; }
	const idVec3 * GetPosition() override { return &origin; }

	idSoundWorldLocal * soundWorld;
	int index;
	bool canFree;
	float volumeAdjustment;
	idStaticList< idSoundChannel *, 16 > channels;
	int areaNum;
	idVec3 origin;
	idMat3 axis;
	idVec3 velocity;
	int emitterId;
	float distance;
	float occludedDistance;
	idVec3 occludedDirection;
	float occlusion;
	soundOcclusionParms_t * occlusionParms;
	const char * debugName;
	bool occlusionValidLastUpdate;
};
