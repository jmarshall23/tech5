#pragma once

#include "soundshader.h"
#include "../../shared/idlib/typesafenumber.h"

class idSoundEmitter;
class idSoundSample;
class idMat3;
class idVec3;
class idStr;
enum millisecondUnique_t : int;
using millisecond_t = idTypesafeNumber< int, millisecondUnique_t >;

struct soundDebugInfo_t {
	const idSoundEmitter * emitter;
	bool hardwareVoice;
	bool playing;
	bool looping;
	float volume;
	float voiceVolume;
	float voiceDryVolume;
	float voiceWetVolume;
	float distance;
	float pitch;
	const idSoundShader * shader;
	int channel;
	idStr sample;
	bool isdefault;
	bool iscompressed;
	bool isstereo;
	int startTime;
};

class idSoundEmitter {
public:
	virtual int Index() = 0;
	virtual void Free( bool immediate ) = 0;
	virtual void Reset() = 0;
	virtual void UpdateEmitter( const idVec3 * origin, const idMat3 * axis,
		const idVec3 * velocity, int emitterId ) = 0;
	virtual int StartSound( soundChannel_t channel, const idSoundShader * shader,
		const soundShaderParms_t * parms = NULL ) = 0;
	virtual void ModifySound( soundChannel_t channel, const idSoundShader * shader,
		const soundShaderParms_t * parms ) = 0;
	virtual void StopSound( soundChannel_t channel ) = 0;
	virtual void SetVolume( soundChannel_t channel, float volume ) = 0;
	virtual void SetPitch( soundChannel_t channel, float pitch ) = 0;
	virtual void FadeSound( soundChannel_t channel, float to, float over,
		float delay = 0.0f, bool stopWhenDone = false ) = 0;
	virtual void FadePitch( soundChannel_t channel, float to, float over,
		float delay = 0.0f ) = 0;
	virtual bool IsCurrentlyPlaying( soundChannel_t channel ) = 0;
	virtual void SetVolumeAdjustment( float volume ) = 0;
	virtual void ClearVolumeAdjustment() = 0;
	virtual float GetVolumeAdjustment() = 0;
	virtual const idSoundShader * GetCurrentSoundShader( soundChannel_t channel ) = 0;
	virtual idSoundSample * GetCurrentSample( soundChannel_t channel ) = 0;
	virtual millisecond_t GetCurrentSampleTime( soundChannel_t channel ) = 0;
	virtual millisecond_t GetRemainingSampleTime( soundChannel_t channel ) = 0;
	virtual bool GetDebugInfo( int channel, soundDebugInfo_t * info ) = 0;
	virtual void SetDebugName( const char * name ) = 0;
	virtual const char * GetDebugName() = 0;
	virtual const idVec3 * GetPosition() = 0;
	virtual ~idSoundEmitter() {}
};
