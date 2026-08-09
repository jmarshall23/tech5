#pragma once

#include "soundemitter.h"

class idDeclDuck;
class idFile;
class idRenderWorld;
class idSnapShot;

enum soundEnvType_t : int {
	SET_DEFAULT = 0,
	SET_INDOOR_SMALL_ROOM = 0x001,
	SET_INDOOR_MID_ROOM = 0x101,
	SET_INDOOR_LARGE_ROOM = 0x201,
	SET_INDOOR_LARGE_HALL = 0x301,
	SET_INDOOR_CORIDOR = 0x801,
	SET_OUTDOOR_OPEN_SPACE = 0x002,
	SET_OUTDOOR_COURT_YARD = 0x202,
	SET_OUTDOOR_SINGLE_WALL = 0x302
};

struct soundEnvironment_t {
	float DryGain;
	float RoomGain;
	float RoomHFGain;
	int DecayTime;
	int DecayHFTime;
	float ReflectionsGain;
	float ReverbGain;
	int ReflectionsDelay;
	int ReverbDelay;
	float Diffusion;
	float Density;
	float HFReference;
	soundEnvType_t SoundEnvType;
	float currentVolume;
	float desiredVolume;
};

class idSoundWorld {
public:
	virtual ~idSoundWorld() {}
	virtual void StopAllSounds() = 0;
	virtual idSoundEmitter * AllocSoundEmitter() = 0;
	virtual int NumEmitters() = 0;
	virtual idSoundEmitter * EmitterForIndex( int index ) = 0;
	virtual void PlaceListener( const idVec3 * origin, const idMat3 * axis,
		const idVec3 * velocity, int listenerId ) = 0;
	virtual void SetNumListeners( int count ) = 0;
	virtual int FindEnvironment( const idVec3 * origin ) = 0;
	virtual bool SetEnvironmentParams( int index, const soundEnvironment_t * environment ) = 0;
	virtual bool GetEnvironmentParams( int index, soundEnvironment_t * environment ) = 0;
	virtual void OverrideEnvironmentParams( const soundEnvironment_t * environment,
		int listenerId ) = 0;
	virtual void BlendEnvironmentParams( const soundEnvironment_t * environment,
		float alpha, int listenerId ) = 0;
	virtual int FindDoor( const idVec3 * origin ) = 0;
	virtual void SetDoor( int doorNum, float value ) = 0;
	virtual float CurrentShakeAmplitude( int listenerId ) = 0;
	virtual int PlayPositionedShaderDirectly( const idSoundShader * shader,
		const idVec3 * origin, const idMat3 * axis, float volume ) = 0;
	virtual int PlayGlobalShaderDirectly( const idSoundShader * shader,
		soundChannel_t channel, float volume ) = 0;
	virtual void Fade( soundShaderGroups_t group, float to, int length ) = 0;
	virtual void Duck( const idDeclDuck * declaration, int fadeIn,
		int hold, int fadeOut ) = 0;
	virtual void DuckBlend( const idDeclDuck * declaration, float alpha ) = 0;
	virtual void DrawDebug( idRenderWorld * renderWorld ) = 0;
	virtual void SaveGame( idFile * file ) = 0;
	virtual bool LoadGame( idFile * file ) = 0;
	virtual void WriteToSnapshot( idSnapShot * snapshot, const idSnapShot * base ) = 0;
	virtual void ReadFromSnapshot( idSnapShot * snapshot, const idSnapShot * base ) = 0;
	virtual bool Trace( const idVec3 * start, const idVec3 * end ) = 0;
	virtual void Pause() = 0;
	virtual void UnPause() = 0;
	virtual int GetSoundTime() = 0;
};
