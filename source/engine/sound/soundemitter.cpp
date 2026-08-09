#include "sound_local.h"

namespace {
float RandomRange( idRandom2 & random, const randomValue_t & range ) {
	float value = range.min + ( range.max - range.min ) * random.RandomFloat();
	if ( range.granularity > 0.0f ) value = std::floor( value / range.granularity ) * range.granularity;
	return value;
}

bool ChannelMatches( const idSoundChannel * channel, soundChannel_t logical ) {
	return channel != NULL && ( logical == SND_CHANNEL_ANY || channel->logicalChannel == logical );
}
}

idSoundFade::idSoundFade() { Clear(); }

void idSoundFade::Clear() {
	fadeStartTime = fadeEndTime = 0;
	fadeStartVolume = fadeEndVolume = 0.0f;
}

void idSoundFade::SetVolume( float to ) {
	fadeStartTime = fadeEndTime = 0;
	fadeStartVolume = fadeEndVolume = to;
}

float idSoundFade::GetVolume( int soundTime ) const {
	if ( fadeEndTime <= fadeStartTime || soundTime >= fadeEndTime ) return fadeEndVolume;
	if ( soundTime <= fadeStartTime ) return fadeStartVolume;
	const float fraction = static_cast< float >( soundTime - fadeStartTime ) /
		static_cast< float >( fadeEndTime - fadeStartTime );
	return fadeStartVolume + fraction * ( fadeEndVolume - fadeStartVolume );
}

void idSoundFade::Fade( float to, int length, int soundTime, int delay ) {
	const int start = soundTime + delay;
	const int end = start + ( std::max )( length, 0 );
	if ( fadeEndTime == end && fadeEndVolume == to ) return;
	fadeStartVolume = GetVolume( soundTime );
	fadeEndVolume = to;
	fadeStartTime = start;
	fadeEndTime = end;
}

idSoundEmitterLocal::idSoundEmitterLocal() : soundWorld( NULL ), index( 0 ), canFree( true ),
	volumeAdjustment( 0.0f ), areaNum( -1 ), origin(), axis( 1.0f ), velocity(), emitterId( 0 ),
	distance( 0.0f ), occludedDistance( 0.0f ), occludedDirection(), occlusion( 1.0f ),
	occlusionParms( new soundOcclusionParms_t() ), debugName( "<UNINITIALIZED>" ),
	occlusionValidLastUpdate( false ) {
	memset( occlusionParms, 0, sizeof( *occlusionParms ) );
}

idSoundEmitterLocal::~idSoundEmitterLocal() {
	Reset();
	delete occlusionParms;
	occlusionParms = NULL;
}

void idSoundEmitterLocal::Init( int emitterIndex, idSoundWorldLocal * world ) {
	soundWorld = world;
	index = emitterIndex;
	Reset();
}

void idSoundEmitterLocal::Reset() {
	while ( channels.Num() > 0 ) {
		idSoundChannel * channel = channels[ channels.Num() - 1 ];
		channels.RemoveIndexFast( channels.Num() - 1 );
		if ( soundWorld != NULL ) soundWorld->FreeSoundChannel( channel );
	}
	canFree = false;
	volumeAdjustment = 0.0f;
	origin.Set( 0.0f, 0.0f, 0.0f );
	axis = idMat3( 1.0f );
	velocity.Set( 0.0f, 0.0f, 0.0f );
	emitterId = 0;
	distance = occludedDistance = 0.0f;
	occludedDirection.Set( 0.0f, 0.0f, 0.0f );
	occlusion = 1.0f;
	if ( occlusionParms != NULL ) memset( occlusionParms, 0, sizeof( *occlusionParms ) );
	occlusionValidLastUpdate = false;
	areaNum = -1;
	debugName = "sounds";
}

int idSoundEmitterLocal::CheckForCompletion( int currentTime ) {
	for ( int i = channels.Num() - 1; i >= 0; --i ) {
		idSoundChannel * channel = channels[ i ];
		if ( !channel->CheckForCompletion( currentTime ) ) continue;
		channels.RemoveIndexFast( i );
		const idSoundShader * post = channel->soundShader != NULL ? channel->soundShader->postSound : NULL;
		const soundChannel_t logical = channel->logicalChannel;
		soundWorld->FreeSoundChannel( channel );
		if ( post != NULL ) StartSound( logical, post, &post->parms );
	}
	return canFree && channels.Num() == 0;
}

float idSoundEmitterLocal::Update( listener_t * listener, int currentTime ) {
	if ( listener == NULL || !listener->valid ) return -60.0f;
	const float dx = origin.x - listener->pos.x;
	const float dy = origin.y - listener->pos.y;
	const float dz = origin.z - listener->pos.z;
	distance = std::sqrt( dx * dx + dy * dy + dz * dz );
	occludedDirection.Set( dx, dy, dz );
	occludedDistance = distance;
	occlusion = 0.0f;

	if ( soundWorld != NULL && areaNum > 0 && listener->area > 0 &&
		areaNum != listener->area && occlusionParms != NULL ) {
		memset( occlusionParms, 0, sizeof( *occlusionParms ) );
		occlusionParms->flatBSP = soundWorld->sbspFile.flatBSP;
		occlusionParms->listenerRoute = listener->route.Ptr();
		occlusionParms->numAreas = soundWorld->sbspFile.areas.Num();
		occlusionParms->doors = soundWorld->doors.Ptr();
		occlusionParms->numDoors = soundWorld->doors.Num();
		occlusionParms->listenerAreaNum = listener->area;
		occlusionParms->listenerOrigin = listener->pos;
		occlusionParms->soundAreaNum = areaNum;
		occlusionParms->soundOrigin = origin;
		occlusionParms->maxDistance = 0.0f;
		SoundOcclusionJob( *occlusionParms );
		if ( occlusionParms->result.valid ) {
			occludedDirection = occlusionParms->result.virtualSoundOrigin;
			occludedDirection.x -= listener->pos.x;
			occludedDirection.y -= listener->pos.y;
			occludedDirection.z -= listener->pos.z;
			occludedDistance = occlusionParms->result.occludedDistance;
			occlusion = occludedDistance > distance + 1.0f ? 1.0f : 0.0f;
			occlusionValidLastUpdate = true;
		}
	}

	float maximum = -60.0f;
	for ( int i = 0; i < channels.Num(); ++i ) {
		channels[ i ]->UpdateHardware( 0.0f, currentTime, listener->id );
		maximum = ( std::max )( maximum, channels[ i ]->volumeDB );
	}
	return maximum;
}

void idSoundEmitterLocal::UpdateEmitter( const idVec3 * newOrigin, const idMat3 * newAxis,
	const idVec3 * newVelocity, int newEmitterId ) {
	if ( newOrigin != NULL ) {
		if ( newOrigin->x != origin.x || newOrigin->y != origin.y || newOrigin->z != origin.z || areaNum < 0 ) {
			origin = *newOrigin;
			areaNum = soundWorld != NULL ? soundWorld->sbspFile.PointAreaNum( origin ) : 0;
		}
	}
	if ( newAxis != NULL ) axis = *newAxis;
	if ( newVelocity != NULL ) velocity = *newVelocity;
	emitterId = newEmitterId;
}

void idSoundEmitterLocal::OnReloadSound( const idSoundShader * declaration ) {
	if ( declaration == NULL ) return;
	for ( int i = channels.Num() - 1; i >= 0; --i ) {
		idSoundChannel * channel = channels[ i ];
		if ( channel->soundShader != declaration ) continue;
		if ( declaration->entries.Num() == 0 ) {
			channels.RemoveIndexFast( i ); soundWorld->FreeSoundChannel( channel ); continue;
		}
		channel->parms = declaration->parms;
		if ( declaration->entries.FindIndex( channel->sample ) < 0 ) {
			channel->sample = declaration->entries[ soundSystemLocal.random.RandomInt( declaration->entries.Num() ) ];
		}
	}
}

void idSoundEmitterLocal::ModifySound( soundChannel_t logical, const idSoundShader * shader,
	const soundShaderParms_t * overrideParms ) {
	bool found = false;
	bool needStart = false;
	for ( int i = channels.Num() - 1; i >= 0; --i ) {
		idSoundChannel * channel = channels[ i ];
		if ( !ChannelMatches( channel, logical ) ) continue;
		found = true;
		if ( channel->soundShader == shader && shader != NULL ) {
			channel->parms = overrideParms != NULL ? *overrideParms : shader->parms;
			channel->randomVolume = SoundClamp( channel->randomVolume,
				channel->parms.volume.min, channel->parms.volume.max );
			channel->randomPitch = SoundClamp( channel->randomPitch,
				channel->parms.pitch.min, channel->parms.pitch.max );
		} else {
			channels.RemoveIndexFast( i ); soundWorld->FreeSoundChannel( channel );
			needStart = true;
		}
	}
	if ( !found || needStart ) StartSound( logical, shader, overrideParms );
}

bool idSoundEmitterLocal::IsCurrentlyPlaying( soundChannel_t logical ) {
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) return true;
	return false;
}

const idSoundShader * idSoundEmitterLocal::GetCurrentSoundShader( soundChannel_t logical ) {
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) return channels[ i ]->soundShader;
	return NULL;
}

idSoundSample * idSoundEmitterLocal::GetCurrentSample( soundChannel_t logical ) {
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) return channels[ i ]->sample;
	return NULL;
}

millisecond_t idSoundEmitterLocal::GetCurrentSampleTime( soundChannel_t logical ) {
	const int now = soundWorld != NULL ? soundWorld->GetSoundTime() : 0;
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) return channels[ i ]->GetCurrentSampleTime( now );
	return millisecond_t( 0 );
}

millisecond_t idSoundEmitterLocal::GetRemainingSampleTime( soundChannel_t logical ) {
	const int now = soundWorld != NULL ? soundWorld->GetSoundTime() : 0;
	int remaining = 0;
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) {
		if ( channels[ i ]->endTime <= 0 ) return millisecond_t( 0 );
		remaining = ( std::max )( remaining, channels[ i ]->endTime - now );
	}
	return millisecond_t( ( std::max )( remaining, 0 ) );
}

bool idSoundEmitterLocal::GetDebugInfo( int channelIndex, soundDebugInfo_t * info ) {
	if ( info == NULL || channelIndex < 0 || channelIndex >= channels.Num() ) return false;
	const idSoundChannel * channel = channels[ channelIndex ];
	memset( info, 0, sizeof( *info ) );
	info->emitter = this;
	info->hardwareVoice = channel->hardwareVoice != NULL;
	info->playing = !channel->CheckForCompletion( soundWorld != NULL ? soundWorld->GetSoundTime() : 0 );
	info->looping = channel->IsLooping();
	info->volume = channel->volumeDB;
	info->voiceVolume = channel->voiceVolumeOffsetDB;
	info->voiceDryVolume = channel->dryVolumeDB;
	info->voiceWetVolume = channel->wetVolumeDB;
	info->distance = distance;
	info->pitch = channel->randomPitch;
	info->shader = channel->soundShader;
	info->channel = channel->logicalChannel;
	info->startTime = channel->startTime;
	if ( channel->sample != NULL ) {
		info->sample = channel->sample->GetName();
		info->isdefault = channel->sample->timestamp == 0;
		info->iscompressed = channel->sample->IsCompressed();
		info->isstereo = channel->sample->NumChannels() == 2;
	} else {
		info->sample = "<NULL>"; info->isdefault = true;
	}
	return true;
}

void idSoundEmitterLocal::Free( bool immediate ) {
	if ( immediate ) Reset();
	canFree = true;
}

void idSoundEmitterLocal::StopSound( soundChannel_t logical ) {
	const int now = soundWorld != NULL ? soundWorld->GetSoundTime() : 0;
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) {
		idSoundChannel * channel = channels[ i ];
		if ( channel->IsLooping() && ( channel->parms.soundShaderFlags & SSF_LOOP_FADE_OUT ) &&
			channel->parms.loopFadeOutDuration > 0.0f ) {
			const int duration = SEC2MS( channel->parms.loopFadeOutDuration );
			channel->volumeFade.Fade( -60.0f, duration, now ); channel->endTime = now + duration;
		} else channel->endTime = 1;
	}
}

void idSoundEmitterLocal::SetVolume( soundChannel_t logical, float volume ) {
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) channels[ i ]->volumeFade.SetVolume( volume );
}

void idSoundEmitterLocal::SetPitch( soundChannel_t logical, float pitchValue ) {
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) channels[ i ]->pitchFade.SetVolume( pitchValue );
}

void idSoundEmitterLocal::FadeSound( soundChannel_t logical, float to, float over, float delay,
	bool stopWhenDone ) {
	const int now = soundWorld != NULL ? soundWorld->GetSoundTime() : 0;
	const int length = SEC2MS( over ), delayMS = SEC2MS( delay );
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) ) {
		channels[ i ]->volumeFade.Fade( to - channels[ i ]->randomVolume, length, now, delayMS );
		if ( stopWhenDone ) channels[ i ]->endTime = now + delayMS + length;
	}
}

void idSoundEmitterLocal::FadePitch( soundChannel_t logical, float to, float over, float delay ) {
	const int now = soundWorld != NULL ? soundWorld->GetSoundTime() : 0;
	for ( int i = 0; i < channels.Num(); ++i ) if ( ChannelMatches( channels[ i ], logical ) )
		channels[ i ]->pitchFade.Fade( to, SEC2MS( over ), now, SEC2MS( delay ) );
}

void idSoundEmitterLocal::DrawDebugInfo( idRenderWorld * ) {}

int idSoundEmitterLocal::StartSound( soundChannel_t logical, const idSoundShader * shader,
	const soundShaderParms_t * overrideParms ) {
	if ( shader == NULL || soundWorld == NULL || shader->entries.Num() == 0 ) return 0;
	const int now = soundWorld->GetSoundTime();
	soundShaderParms_t effective = overrideParms != NULL ? *overrideParms : shader->parms;
	if ( effective.soundChannel != SND_CHANNEL_ANY ) logical = effective.soundChannel;
	if ( effective.soundShaderFlags & SSF_PLAY_ONCE ) {
		for ( int i = 0; i < channels.Num(); ++i ) if ( channels[ i ]->soundShader == shader &&
			!channels[ i ]->CheckForCompletion( now ) ) return 0;
	}
	for ( int i = channels.Num() - 1; logical != SND_CHANNEL_ANY && i >= 0; --i ) {
		if ( channels[ i ]->logicalChannel == logical ) {
			idSoundChannel * old = channels[ i ]; channels.RemoveIndexFast( i ); soundWorld->FreeSoundChannel( old );
		}
	}
	idSoundSample * sample = const_cast< idSoundShader * >( shader )->GetNextEntry( true );
	if ( sample == NULL ) return 0;
	if ( !sample->IsLoaded() ) sample->LoadResource();
	if ( !sample->IsLoaded() ) return 0;
	if ( channels.Num() >= 16 ) CheckForCompletion( now );
	if ( channels.Num() >= 16 ) return 0;
	idSoundChannel * channel = soundWorld->channelAllocator.Alloc();
	if ( channel == NULL ) return 0;
	channel->emitter = this;
	channel->logicalChannel = logical;
	channel->parms = effective;
	channel->soundShader = shader;
	channel->sample = sample;
	channel->randomVolume = volumeAdjustment + RandomRange( soundSystemLocal.random, effective.volume );
	channel->randomPitch = RandomRange( soundSystemLocal.random, effective.pitch );
	channel->pitchFade.SetVolume( 0.0f );
	channel->startTime = now;
	const int length = sample->LengthInMsec();
	if ( channel->IsLooping() && ( effective.soundShaderFlags & SSF_NO_RANDOM_OFFSET ) == 0 && length > 0 ) {
		channel->startTime -= soundSystemLocal.random.RandomInt( length );
	}
	channel->endTime = channel->IsLooping() ? 0 : channel->startTime + length + 100;
	channels.Append( channel );
	const_cast< idSoundShader * >( shader )->playingChannels.AddToEnd( channel->channelNode );
	if ( shader->preSound != NULL ) channel->startTime += StartSound( SND_CHANNEL_ANY, shader->preSound, overrideParms );
	if ( channel->IsLooping() && ( effective.soundShaderFlags & SSF_LOOP_FADE_IN ) &&
		effective.loopFadeInDuration > 0.0f ) {
		channel->volumeFade.SetVolume( -60.0f - channel->randomVolume );
		channel->volumeFade.Fade( 0.0f, SEC2MS( effective.loopFadeInDuration ), now );
	}
	return length;
}
