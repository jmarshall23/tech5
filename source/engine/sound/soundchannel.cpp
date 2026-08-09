#include "sound_local.h"

idSoundChannel::idSoundChannel() : emitter( NULL ), startTime( 0 ), endTime( 0 ),
	logicalChannel( SND_CHANNEL_ANY ), soundShader( NULL ), sample( NULL ), randomVolume( 0.0f ),
	randomPitch( 0.0f ), dopplerPitch( 0.0f ), volumeDB( 0.0f ), currentAmplitude( 0.0f ),
	currentShakeAmplitude( 0.0f ), hardwareVoice( NULL ), channelNode( this ),
	voiceVolumeOffsetDB( 0.0f ), dryVolumeDB( 0.0f ), wetVolumeDB( 0.0f ) {
	memset( &parms, 0, sizeof( parms ) );
}

idSoundChannel::~idSoundChannel() {
	Mute();
	channelNode.Remove();
}

bool idSoundChannel::CanMute() const { return ( parms.groups & 0x1F00000 ) == 0; }

void idSoundChannel::Mute() {
	if ( hardwareVoice != NULL ) { soundSystemLocal.FreeVoice( hardwareVoice ); hardwareVoice = NULL; }
}

bool idSoundChannel::IsLooping() const {
	return ( parms.soundShaderFlags & ( SSF_LOOPING | SSF_RANDOM_LOOPING ) ) != 0;
}

bool idSoundChannel::CheckForCompletion( int currentTime ) const {
	return sample == NULL || ( endTime > 0 && endTime < currentTime );
}

void idSoundChannel::SetSilent() {
	volumeDB = dryVolumeDB = wetVolumeDB = -60.0f;
	voiceVolumeOffsetDB = 0.0f;
	currentAmplitude = currentShakeAmplitude = 0.0f;
}

void idSoundChannel::UpdateVolume( float volumeAdd, int currentTime ) {
	SetSilent();
	if ( sample == NULL || currentTime < startTime || ( endTime > 0 && currentTime > endTime ) ) return;
	float volume = randomVolume + volumeFade.GetVolume( currentTime ) + volumeAdd;
	if ( emitter != NULL ) {
		volume += emitter->volumeAdjustment;
		idSoundWorldLocal * world = emitter->soundWorld;
		if ( world != NULL ) {
			volume += world->volumeFade.GetVolume( currentTime ) + world->pauseFade.GetVolume( currentTime );
			int mask = 1;
			for ( int group = 0; group < 25; ++group, mask <<= 1 ) {
				if ( ( static_cast< int >( parms.groups ) & mask ) == 0 ) continue;
				volume += world->groupFade[ group ].GetVolume( currentTime );
				for ( int d = 0; d < world->ducks.Num(); ++d ) {
					const idSoundWorldLocal::idDuckLayer & duck = world->ducks[ d ];
					if ( duck.decl == NULL ) continue;
					float alpha = duck.blendAlpha;
					if ( currentTime < duck.startFadeEnd && duck.startFadeEnd > duck.startFadeStart )
						alpha *= SoundClamp( static_cast< float >( currentTime - duck.startFadeStart ) /
							( duck.startFadeEnd - duck.startFadeStart ), 0.0f, 1.0f );
					if ( duck.endFadeStart >= 0 && currentTime >= duck.endFadeStart ) {
						if ( duck.endFadeEnd <= duck.endFadeStart ) alpha = 0.0f;
						else alpha *= 1.0f - SoundClamp( static_cast< float >( currentTime - duck.endFadeStart ) /
							( duck.endFadeEnd - duck.endFadeStart ), 0.0f, 1.0f );
					}
					volume += duck.decl->groupVolume[ group ] * alpha;
				}
			}
			if ( soundSystemLocal.musicMuted && ( static_cast< int >( parms.groups ) &
				( SSG_MUSIC_MENU | SSG_MUSIC_INGAME ) ) != 0 ) volume = -60.0f;
		}
	}
	float distanceFraction = 0.0f;
	if ( emitter != NULL && ( parms.soundShaderFlags & SSF_GLOBAL ) == 0 ) {
		const float minimum = parms.minDistance * parms.distanceFactor;
		const float maximum = parms.maxDistance * parms.distanceFactor;
		if ( maximum > minimum ) distanceFraction = SoundClamp( ( emitter->occludedDistance - minimum ) /
			( maximum - minimum ), 0.0f, 1.0f );
		volume += ( -60.0f - volume ) * distanceFraction;
	}
	volumeDB = volume;
	dryVolumeDB = volume;
	wetVolumeDB = parms.wetVolume + volume;
}

millisecond_t idSoundChannel::GetCurrentSampleTime( int currentTime ) const {
	return millisecond_t( sample != NULL ? ( std::max )( 0, currentTime - startTime ) : 0 );
}

void idSoundChannel::UpdateHardware( float volumeAdd, int currentTime, int ) {
	UpdateVolume( volumeAdd, currentTime );
	if ( volumeDB <= -60.0f || sample == NULL ) { if ( CanMute() ) Mute(); return; }
	if ( hardwareVoice == NULL ) {
		hardwareVoice = soundSystemLocal.AllocateVoice( sample, IsLooping() ? sample : NULL );
		if ( hardwareVoice == NULL ) return;
		hardwareVoice->Start( ( std::max )( 0, currentTime - startTime ), parms.soundShaderFlags );
	}
	hardwareVoice->gain = SoundDbToScale( volumeDB + voiceVolumeOffsetDB );
	hardwareVoice->dryGain = SoundDbToScale( dryVolumeDB - volumeDB );
	hardwareVoice->wetGain = SoundDbToScale( wetVolumeDB - volumeDB );
	hardwareVoice->gainLFE = SoundDbToScale( parms.lfeVolume );
	hardwareVoice->centerChannel = parms.centerChannel;
	hardwareVoice->pitch = SoundClamp( randomPitch + pitchFade.GetVolume( currentTime ) + dopplerPitch,
		0.01f, 4.0f );
	if ( emitter != NULL ) {
		hardwareVoice->position = emitter->occludedDirection;
		hardwareVoice->velocity = emitter->velocity;
		hardwareVoice->axis = emitter->axis;
		hardwareVoice->occlusion = emitter->occlusion;
	}
	hardwareVoice->Update();
	currentAmplitude = hardwareVoice->GetAmplitude();
	if ( emitter != NULL && parms.shakes != 0.0f ) {
		float shake = 1.0f;
		if ( parms.maxShakeDistance > parms.minShakeDistance ) shake = 1.0f - SoundClamp(
			( emitter->occludedDistance - parms.minShakeDistance ) /
			( parms.maxShakeDistance - parms.minShakeDistance ), 0.0f, 1.0f );
		currentShakeAmplitude = currentAmplitude * parms.shakes * shake;
	}
}
