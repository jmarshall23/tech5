#include "sound_local.h"

namespace {
soundEnvironment_t StateDefaultEnvironment() {
	soundEnvironment_t environment;
	memset( &environment, 0, sizeof( environment ) );
	environment.SoundEnvType = SET_DEFAULT;
	environment.currentVolume = environment.desiredVolume = 1.0f;
	return environment;
}

bool WriteExact( idFile * file, const void * data, unsigned int bytes ) {
	return file != NULL && file->Write( data, bytes ) == bytes;
}
bool ReadExactState( idFile * file, void * data, unsigned int bytes ) {
	return file != NULL && file->Read( data, bytes ) == bytes;
}

void SaveParms( idFile * file, const soundShaderParms_t & p ) {
	WriteExact( file, &p.minDistance, 4 ); WriteExact( file, &p.maxDistance, 4 );
	WriteExact( file, &p.distanceFactor, 4 ); WriteExact( file, &p.wetMinDistanceOffset, 4 );
	WriteExact( file, &p.wetMaxDistanceOffset, 4 ); WriteExact( file, &p.coneAttenuation.innerAngle, 4 );
	WriteExact( file, &p.coneAttenuation.outerAngle, 4 ); WriteExact( file, &p.coneAttenuation.outerVolume, 4 );
	WriteExact( file, &p.volume.min, 4 ); WriteExact( file, &p.volume.max, 4 );
	WriteExact( file, &p.volume.granularity, 4 ); WriteExact( file, &p.wetVolume, 4 );
	WriteExact( file, &p.pitch.min, 4 ); WriteExact( file, &p.pitch.max, 4 );
	WriteExact( file, &p.pitch.granularity, 4 ); WriteExact( file, &p.loopFadeInDuration, 4 );
	WriteExact( file, &p.loopFadeOutDuration, 4 ); WriteExact( file, &p.dopplerMultiplier, 4 );
	WriteExact( file, &p.shakes, 4 ); WriteExact( file, &p.groups, 4 );
	WriteExact( file, &p.soundChannel, 4 ); WriteExact( file, &p.soundShaderFlags, 4 );
	WriteExact( file, &p.lowPassMinDistance, 4 ); WriteExact( file, &p.lowPassStrength, 4 );
	WriteExact( file, &p.lfeVolume, 4 ); WriteExact( file, &p.centerChannel, 4 );
	WriteExact( file, &p.headroom, 4 );
}

bool LoadParms( idFile * file, soundShaderParms_t & p ) {
	memset( &p, 0, sizeof( p ) );
	return ReadExactState( file, &p.minDistance, 4 ) && ReadExactState( file, &p.maxDistance, 4 ) &&
		ReadExactState( file, &p.distanceFactor, 4 ) && ReadExactState( file, &p.wetMinDistanceOffset, 4 ) &&
		ReadExactState( file, &p.wetMaxDistanceOffset, 4 ) && ReadExactState( file, &p.coneAttenuation.innerAngle, 4 ) &&
		ReadExactState( file, &p.coneAttenuation.outerAngle, 4 ) && ReadExactState( file, &p.coneAttenuation.outerVolume, 4 ) &&
		ReadExactState( file, &p.volume.min, 4 ) && ReadExactState( file, &p.volume.max, 4 ) &&
		ReadExactState( file, &p.volume.granularity, 4 ) && ReadExactState( file, &p.wetVolume, 4 ) &&
		ReadExactState( file, &p.pitch.min, 4 ) && ReadExactState( file, &p.pitch.max, 4 ) &&
		ReadExactState( file, &p.pitch.granularity, 4 ) && ReadExactState( file, &p.loopFadeInDuration, 4 ) &&
		ReadExactState( file, &p.loopFadeOutDuration, 4 ) && ReadExactState( file, &p.dopplerMultiplier, 4 ) &&
		ReadExactState( file, &p.shakes, 4 ) && ReadExactState( file, &p.groups, 4 ) &&
		ReadExactState( file, &p.soundChannel, 4 ) && ReadExactState( file, &p.soundShaderFlags, 4 ) &&
		ReadExactState( file, &p.lowPassMinDistance, 4 ) && ReadExactState( file, &p.lowPassStrength, 4 ) &&
		ReadExactState( file, &p.lfeVolume, 4 ) && ReadExactState( file, &p.centerChannel, 4 ) &&
		ReadExactState( file, &p.headroom, 4 );
}

bool LoadFade( idFile * file, idSoundFade & fade ) {
	return ReadExactState( file, &fade.fadeStartTime, 4 ) && ReadExactState( file, &fade.fadeEndTime, 4 ) &&
		ReadExactState( file, &fade.fadeStartVolume, 4 ) && ReadExactState( file, &fade.fadeEndVolume, 4 );
}
}

void idSoundWorldLocal::SaveGame( idFile * file ) {
	if ( file == NULL ) return;
	WriteExact( file, &soundSystemLocal.soundTime, 4 );
	WriteExact( file, &pausedTime, 4 ); WriteExact( file, &accumulatedPauseTime, 4 );
	WriteExact( file, &isPaused, 1 );
	for ( int i = 0; i < 2; ++i ) {
		listener_t & listener = listeners[ i ];
		WriteExact( file, &listener.valid, 1 ); WriteExact( file, &listener.axis, sizeof( listener.axis ) );
		WriteExact( file, &listener.pos, sizeof( listener.pos ) ); WriteExact( file, &listener.vel, sizeof( listener.vel ) );
		WriteExact( file, &listener.id, 4 ); WriteExact( file, &listener.maxDB, 4 );
	}
	const int emitterCount = emitters.Num(); WriteExact( file, &emitterCount, 4 );
	for ( int e = 0; e < emitterCount; ++e ) {
		idSoundEmitterLocal * emitter = emitters[ e ];
		idVec3 savedOrigin = emitter->canFree ? idVec3( FLT_MAX, FLT_MAX, FLT_MAX ) : emitter->origin;
		WriteExact( file, &savedOrigin, sizeof( savedOrigin ) );
		if ( emitter->canFree ) continue;
		WriteExact( file, &emitter->areaNum, 4 ); WriteExact( file, &emitter->velocity, sizeof( emitter->velocity ) );
		WriteExact( file, &emitter->emitterId, 4 ); WriteExact( file, &emitter->occludedDistance, 4 );
		WriteExact( file, &emitter->occludedDirection, sizeof( emitter->occludedDirection ) );
		WriteExact( file, &emitter->occlusion, 4 );
		const int channelCount = emitter->channels.Num(); WriteExact( file, &channelCount, 4 );
		for ( int c = 0; c < channelCount; ++c ) {
			idSoundChannel * channel = emitter->channels[ c ];
			WriteExact( file, &channel->startTime, 4 ); WriteExact( file, &channel->logicalChannel, 4 );
			SaveParms( file, channel->parms );
			file->WriteString( channel->soundShader != NULL ? channel->soundShader->GetName() : "" );
			file->WriteString( channel->sample != NULL ? channel->sample->GetName() : "" );
			WriteExact( file, &channel->randomVolume, 4 ); WriteExact( file, &channel->randomPitch, 4 );
			WriteExact( file, &channel->volumeFade, sizeof( channel->volumeFade ) );
			WriteExact( file, &channel->pitchFade, sizeof( channel->pitchFade ) );
		}
	}
	const int environmentCount = environments.Num(); WriteExact( file, &environmentCount, 4 );
	for ( int i = 0; i < environmentCount; ++i ) {
		WriteExact( file, &environments[ i ], 12 * sizeof( float ) );
	}
}

bool idSoundWorldLocal::LoadGame( idFile * file ) {
	if ( file == NULL ) return false;
	int savedSoundTime = 0;
	if ( !ReadExactState( file, &savedSoundTime, 4 ) || !ReadExactState( file, &pausedTime, 4 ) ||
		!ReadExactState( file, &accumulatedPauseTime, 4 ) || !ReadExactState( file, &isPaused, 1 ) ) return false;
	const int timeOffset = soundSystemLocal.soundTime - savedSoundTime;
	pausedTime += timeOffset; accumulatedPauseTime += timeOffset;
	for ( int i = 0; i < 2; ++i ) {
		listener_t & listener = listeners[ i ];
		if ( !ReadExactState( file, &listener.valid, 1 ) || !ReadExactState( file, &listener.axis, sizeof( listener.axis ) ) ||
			!ReadExactState( file, &listener.pos, sizeof( listener.pos ) ) || !ReadExactState( file, &listener.vel, sizeof( listener.vel ) ) ||
			!ReadExactState( file, &listener.id, 4 ) || !ReadExactState( file, &listener.maxDB, 4 ) ) return false;
	}
	int emitterCount = 0;
	if ( !ReadExactState( file, &emitterCount, 4 ) || emitterCount < 0 || emitterCount > 65536 ) return false;
	while ( emitters.Num() < emitterCount ) {
		idSoundEmitterLocal * emitter = emitterAllocator.Alloc(); if ( emitter == NULL ) return false;
		emitter->Init( emitters.Append( emitter ), this );
	}
	for ( int e = 0; e < emitterCount; ++e ) {
		idSoundEmitterLocal * emitter = emitters[ e ]; emitter->Reset();
		idVec3 savedOrigin;
		if ( !ReadExactState( file, &savedOrigin, sizeof( savedOrigin ) ) ) return false;
		if ( savedOrigin.x == FLT_MAX && savedOrigin.y == FLT_MAX && savedOrigin.z == FLT_MAX ) { emitter->canFree = true; continue; }
		emitter->origin = savedOrigin; emitter->canFree = false;
		if ( !ReadExactState( file, &emitter->areaNum, 4 ) || !ReadExactState( file, &emitter->velocity, sizeof( emitter->velocity ) ) ||
			!ReadExactState( file, &emitter->emitterId, 4 ) || !ReadExactState( file, &emitter->occludedDistance, 4 ) ||
			!ReadExactState( file, &emitter->occludedDirection, sizeof( emitter->occludedDirection ) ) ||
			!ReadExactState( file, &emitter->occlusion, 4 ) ) return false;
		int channelCount = 0;
		if ( !ReadExactState( file, &channelCount, 4 ) || channelCount < 0 || channelCount > 16 ) return false;
		for ( int c = 0; c < channelCount; ++c ) {
			idSoundChannel * channel = channelAllocator.Alloc(); if ( channel == NULL ) return false;
			channel->emitter = emitter; emitter->channels.Append( channel );
			if ( !ReadExactState( file, &channel->startTime, 4 ) || !ReadExactState( file, &channel->logicalChannel, 4 ) ||
				!LoadParms( file, channel->parms ) ) return false;
			channel->startTime += timeOffset;
			idStr shaderName, sampleName;
			if ( file->ReadString( shaderName ) == 0 || file->ReadString( sampleName ) == 0 ) return false;
			channel->soundShader = shaderName.Length() == 0 ? NULL : static_cast< const idSoundShader * >(
				idSoundShader::resourceList.FindWithInheritance( shaderName.c_str(), true ) );
			channel->sample = sampleName.Length() == 0 ? NULL : static_cast< idSoundSample * >(
				idSoundSample::resourceList.Load( sampleName.c_str(), true ) );
			if ( !ReadExactState( file, &channel->randomVolume, 4 ) || !ReadExactState( file, &channel->randomPitch, 4 ) ||
				!LoadFade( file, channel->volumeFade ) || !LoadFade( file, channel->pitchFade ) ) return false;
			if ( channel->sample != NULL ) channel->endTime = channel->IsLooping() ? 0 :
				channel->startTime + channel->sample->LengthInMsec() + 100;
			if ( channel->soundShader != NULL ) const_cast< idSoundShader * >( channel->soundShader )->playingChannels.AddToEnd( channel->channelNode );
		}
	}
	int environmentCount = 0;
	if ( !ReadExactState( file, &environmentCount, 4 ) || environmentCount < 0 || environmentCount > 65536 ||
		!environments.SetNum( environmentCount ) ) return false;
	for ( int i = 0; i < environmentCount; ++i ) {
		environments[ i ] = StateDefaultEnvironment();
		if ( !ReadExactState( file, &environments[ i ], 12 * sizeof( float ) ) ) return false;
	}
	return true;
}
