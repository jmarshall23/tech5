#include "sound_local.h"

idSoundVoice_Base::idSoundVoice_Base() : invListenerAxis( 1.0f ), axis( 1.0f ),
	position(), velocity(), gain( 1.0f ), dryGain( 1.0f ), wetGain( 0.0f ), gainLFE( 0.0f ),
	centerChannel( 0.0f ), pitch( 1.0f ), innerRadius( 0.0f ), occlusion( 0.0f ),
	channelMask( 0 ), innerSampleRangeSqr( 0.0f ), outerSampleRangeSqr( 0.0f ) {}

void idSoundVoice_Base::InitSurround( unsigned int, int outputChannelMask ) {
	channelMask = static_cast< unsigned int >( outputChannelMask );
}

void idSoundVoice_Base::CalculateChannelSurrond( int srcChannel, float * matrix,
	int matrixChannels ) const {
	if ( matrix == NULL || matrixChannels <= 0 ) return;
	for ( int i = 0; i < matrixChannels; ++i ) matrix[ i ] = 0.0f;
	if ( matrixChannels == 1 ) { matrix[ 0 ] = 1.0f; return; }
	if ( srcChannel == 0 ) { matrix[ 0 ] = 1.0f; return; }
	if ( srcChannel == 1 ) { matrix[ 1 ] = 1.0f; return; }
	const float x = position.x * invListenerAxis[ 0 ].x + position.y * invListenerAxis[ 0 ].y + position.z * invListenerAxis[ 0 ].z;
	const float y = position.x * invListenerAxis[ 1 ].x + position.y * invListenerAxis[ 1 ].y + position.z * invListenerAxis[ 1 ].z;
	const float angle = std::atan2( y, x );
	const float pan = SoundClamp( 0.5f + 0.5f * std::sin( angle ), 0.0f, 1.0f );
	matrix[ 0 ] = std::sqrt( 1.0f - pan ); matrix[ 1 ] = std::sqrt( pan );
	if ( matrixChannels > 2 ) matrix[ 2 ] = centerChannel * ( 1.0f - std::fabs( 2.0f * pan - 1.0f ) );
	if ( matrixChannels > 3 ) matrix[ 3 ] = gainLFE;
}

void idSoundVoice_Base::CalculateSurround( int srcChannels, int dstChannels, float * matrix ) const {
	if ( matrix == NULL || srcChannels <= 0 || dstChannels <= 0 ) return;
	for ( int source = 0; source < srcChannels; ++source ) {
		CalculateChannelSurrond( source, matrix + source * dstChannels, dstChannels );
	}
}

idSoundSample * idSoundVoice_Base::SelectSample( int timeMS ) const {
	int cursor = timeMS;
	for ( int i = 0; i < samples.Num(); ++i ) {
		idSoundSample * current = samples[ i ];
		if ( current == NULL ) continue;
		const int length = current->LengthInMsec();
		if ( cursor < length || i == samples.Num() - 1 ) return current;
		cursor -= length;
	}
	return NULL;
}

