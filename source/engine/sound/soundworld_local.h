#pragma once

#include "soundworld.h"
#include "soundemitter_local.h"
#include "soundbspfile.h"
#include "occlusion/soundrouting.h"

struct listener_t {
	bool valid;
	bool environmentValid;
	idMat3 axis;
	idVec3 pos;
	idVec3 vel;
	int id;
	int area;
	float maxDB;
	float maxDBFrame;
	float shakeAmp;
	float tinnitus;
	soundEnvironment_t environment;
	soundEnvironment_t currentEnv;
	idList< int, 38 > route;
	soundRoutingParms_t * routingParms;
	float envBlendAlpha;
};

class alignas(4) idSoundWorldLocal : public idSoundWorld {
public:
	struct idDuckLayer {
		idArray< float, 25 > fromVolumes;
		const idDeclDuck * decl;
		int startFadeStart, startFadeEnd;
		int endFadeStart, endFadeEnd;
		float blendAlpha;
	};

	idSoundWorldLocal();
	~idSoundWorldLocal() override;
	void StopAllSounds() override;
	idSoundEmitter * AllocSoundEmitter() override;
	int NumEmitters() override;
	idSoundEmitter * EmitterForIndex( int index ) override;
	void PlaceListener( const idVec3 * origin, const idMat3 * axis,
		const idVec3 * velocity, int listenerId ) override;
	void SetNumListeners( int count ) override;
	int FindEnvironment( const idVec3 * origin ) override;
	bool SetEnvironmentParams( int index, const soundEnvironment_t * environment ) override;
	bool GetEnvironmentParams( int index, soundEnvironment_t * environment ) override;
	void OverrideEnvironmentParams( const soundEnvironment_t * environment, int listenerId ) override;
	void BlendEnvironmentParams( const soundEnvironment_t * environment, float alpha,
		int listenerId ) override;
	int FindDoor( const idVec3 * origin ) override;
	void SetDoor( int doorNum, float value ) override;
	float CurrentShakeAmplitude( int listenerId ) override;
	int PlayPositionedShaderDirectly( const idSoundShader * shader,
		const idVec3 * origin, const idMat3 * axis, float volume ) override;
	int PlayGlobalShaderDirectly( const idSoundShader * shader,
		soundChannel_t channel, float volume ) override;
	void Fade( soundShaderGroups_t group, float to, int length ) override;
	void Duck( const idDeclDuck * declaration, int fadeIn, int hold, int fadeOut ) override;
	void DuckBlend( const idDeclDuck * declaration, float alpha ) override;
	void DrawDebug( idRenderWorld * renderWorld ) override;
	void SaveGame( idFile * file ) override;
	bool LoadGame( idFile * file ) override;
	void WriteToSnapshot( idSnapShot *, const idSnapShot * ) override {}
	void ReadFromSnapshot( idSnapShot *, const idSnapShot * ) override {}
	bool Trace( const idVec3 * start, const idVec3 * end ) override;
	void Pause() override;
	void UnPause() override;
	int GetSoundTime() override;

	bool LoadMap( const char * mapName );
	void Update();
	void UpdateForListener( listener_t * listener );
	void OnReloadSound( const idSoundShader * shader );
	void FreeSoundChannel( idSoundChannel * channel );
	void AllocRouting( listener_t * listener );
	void BlendEnv( soundEnvironment_t & result, const soundEnvironment_t & from,
		const soundEnvironment_t & to, float alpha ) const;

	idSoundFade volumeFade;
	idArray< idSoundFade, 25 > groupFade;
	idStaticList< idDuckLayer, 4 > ducks;
	idRenderWorld * renderWorld;
	idSoundBSPFile sbspFile;
	idList< soundEnvironment_t, 38 > environments;
	idList< float, 38 > doors;
	idArray< listener_t, 2 > listeners;
	int listenerIndex;
	int numListeners;
	float currentCushionDB;
	idList< idSoundEmitterLocal *, 38 > emitters;
	idSoundEmitter * localSound;
	idSoundEmitter * tinnitusEmitter;
	idSoundEmitter * positionedEmitters[ 32 ];
	idBlockAlloc< idSoundEmitterLocal, 16, 38 > emitterAllocator;
	idBlockAlloc< idSoundChannel, 16, 38 > channelAllocator;
	idSoundFade pauseFade;
	int pausedTime;
	int accumulatedPauseTime;
	bool isPaused;
};
