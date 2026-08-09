/*
===========================================================================
Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

Windows XAudio2 voice implementation adapted from Doom 3 BFG Edition.
===========================================================================
*/
#include "../sound_local.h"

idSoundVoice_XAudio2::idSoundVoice_XAudio2() : pSourceVoice( NULL ), sample( NULL ),
	readPin( 0 ), paused( true ), formatTag( 0 ), numChannels( 0 ), sourceVoiceRate( 0 ),
	sampleRate( 0 ), bitsPerSample( 0 ), currentStreamBlock( 0 ), currentStreamRemaining( 0 ),
	hasVUMeter( false ), hasReverb( false ), startFlags( 0 ) {
	memset( pins, 0, sizeof( pins ) );
}

idSoundVoice_XAudio2::~idSoundVoice_XAudio2() { DestroyInternal(); }

bool idSoundVoice_XAudio2::CompatibleFormat( idSoundSample_XAudio2 * soundSample ) const {
	return soundSample != NULL && ( pSourceVoice == NULL ||
		( formatTag == soundSample->format.basic.formatTag && numChannels == soundSample->format.basic.numChannels &&
		bitsPerSample == soundSample->format.basic.bitsPerSample ) );
}

void idSoundVoice_XAudio2::Create( const idSoundSample * leadin, const idSoundSample * looping ) {
	Stop(); FlushSourceBuffers();
	idSoundSample_XAudio2 * newSample = const_cast< idSoundSample * >( leadin );
	if ( newSample == NULL || soundSystemLocal.hardware.pXAudio2 == NULL ) return;
	if ( !CompatibleFormat( newSample ) ) DestroyInternal();
	samples.Clear();
	if ( leadin != NULL ) samples.Append( const_cast< idSoundSample * >( leadin ) );
	if ( looping != NULL && looping != leadin ) samples.Append( const_cast< idSoundSample * >( looping ) );
	sample = newSample;
	formatTag = sample->format.basic.formatTag;
	numChannels = sample->format.basic.numChannels;
	sampleRate = sourceVoiceRate = sample->format.basic.samplesPerSec;
	bitsPerSample = sample->format.basic.bitsPerSample;
	if ( pSourceVoice == NULL ) {
		const WAVEFORMATEX * waveFormat = reinterpret_cast< const WAVEFORMATEX * >( &sample->format );
		XAUDIO2_SEND_DESCRIPTOR descriptors[ 2 ];
		XAUDIO2_VOICE_SENDS sends;
		XAUDIO2_VOICE_SENDS * sendList = NULL;
		if ( soundSystemLocal.hardware.pSubmixVoice != NULL ) {
			descriptors[ 0 ].Flags = 0; descriptors[ 0 ].pOutputVoice = soundSystemLocal.hardware.pMasterVoice;
			descriptors[ 1 ].Flags = 0; descriptors[ 1 ].pOutputVoice = soundSystemLocal.hardware.pSubmixVoice;
			sends.SendCount = 2; sends.pSends = descriptors; sendList = &sends;
		}
		if ( FAILED( soundSystemLocal.hardware.pXAudio2->CreateSourceVoice( &pSourceVoice, waveFormat,
			XAUDIO2_VOICE_USEFILTER, XAUDIO2_MAX_FREQ_RATIO, NULL, sendList, NULL ) ) ) pSourceVoice = NULL;
	}
	if ( pSourceVoice != NULL ) {
		pSourceVoice->SetSourceSampleRate( sampleRate );
		pSourceVoice->SetVolume( 0.0f );
	}
	paused = true;
}

void idSoundVoice_XAudio2::DestroyInternal() {
	if ( pSourceVoice != NULL ) { pSourceVoice->DestroyVoice(); pSourceVoice = NULL; }
	sample = NULL; samples.Clear(); hasVUMeter = false; hasReverb = false; paused = true;
}

int idSoundVoice_XAudio2::RestartAt( int offsetSamples ) {
	if ( pSourceVoice == NULL || samples.Num() == 0 ) return 0;
	idSoundSample_XAudio2 * selected = samples[ 0 ];
	bool looping = ( startFlags & ( SSF_LOOPING | SSF_RANDOM_LOOPING ) ) != 0;
	if ( offsetSamples >= selected->NumSamples() ) {
		if ( samples.Num() > 1 ) { offsetSamples -= selected->NumSamples(); selected = samples[ 1 ]; looping = true; }
		else if ( looping && selected->NumSamples() > 0 ) offsetSamples %= selected->NumSamples();
		else return 0;
	}
	sample = selected;
	XAUDIO2_BUFFER buffer; memset( &buffer, 0, sizeof( buffer ) );
	buffer.AudioBytes = selected->staticBufferSize;
	buffer.pAudioData = reinterpret_cast< const BYTE * >( selected->staticBuffer );
	buffer.PlayBegin = selected->firstValidSample + offsetSamples;
	buffer.PlayLength = ( std::max )( 0, selected->lastValidSample - static_cast< int >( buffer.PlayBegin ) );
	if ( looping ) {
		buffer.LoopBegin = selected->loopBegin;
		buffer.LoopLength = ( std::max )( 0, selected->loopEnd - selected->loopBegin );
		buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
	} else buffer.Flags = XAUDIO2_END_OF_STREAM;
	if ( FAILED( pSourceVoice->SubmitSourceBuffer( &buffer ) ) ) return 0;
	return buffer.AudioBytes;
}

void idSoundVoice_XAudio2::Start( int offsetMS, int soundShaderFlags ) {
	if ( pSourceVoice == NULL || sample == NULL ) return;
	startFlags = soundShaderFlags;
	Stop(); FlushSourceBuffers();
	const bool wantMeter = ( soundShaderFlags & SSF_FLICKER ) != 0;
	if ( wantMeter != hasVUMeter ) {
		hasVUMeter = wantMeter;
		if ( wantMeter ) {
			IUnknown * meter = NULL;
			if ( SUCCEEDED( XAudio2CreateVolumeMeter( &meter, 0 ) ) ) {
				XAUDIO2_EFFECT_DESCRIPTOR descriptor = { meter, TRUE, static_cast< UINT32 >( sample->NumChannels() ) };
				XAUDIO2_EFFECT_CHAIN chain = { 1, &descriptor };
				pSourceVoice->SetEffectChain( &chain ); meter->Release();
			}
		} else pSourceVoice->SetEffectChain( NULL );
	}
	const int offsetSamples = sample->SampleRate() > 0 ? static_cast< int >(
		static_cast< __int64 >( ( std::max )( offsetMS, 0 ) ) * sample->SampleRate() / 1000 ) : 0;
	if ( RestartAt( offsetSamples ) == 0 ) return;
	Update(); UnPause();
}

bool idSoundVoice_XAudio2::Update() {
	if ( pSourceVoice == NULL || sample == NULL ) return false;
	const int sourceChannels = sample->NumChannels();
	const int destinationChannels = ( std::max )( 1, soundSystemLocal.hardware.outputChannels );
	float matrix[ idWaveFile::CHANNEL_INDEX_MAX * idWaveFile::CHANNEL_INDEX_MAX ];
	memset( matrix, 0, sizeof( matrix ) );
	CalculateSurround( sourceChannels, destinationChannels, matrix );
	float dryMatrix[ idWaveFile::CHANNEL_INDEX_MAX * idWaveFile::CHANNEL_INDEX_MAX ];
	float wetMatrix[ idWaveFile::CHANNEL_INDEX_MAX * idWaveFile::CHANNEL_INDEX_MAX ];
	for ( int i = 0; i < sourceChannels * destinationChannels; ++i ) {
		dryMatrix[ i ] = matrix[ i ] * dryGain;
		wetMatrix[ i ] = matrix[ i ] * wetGain;
	}
	pSourceVoice->SetOutputMatrix( soundSystemLocal.hardware.pMasterVoice, sourceChannels,
		destinationChannels, dryMatrix );
	if ( soundSystemLocal.hardware.pSubmixVoice != NULL ) pSourceVoice->SetOutputMatrix(
		soundSystemLocal.hardware.pSubmixVoice, sourceChannels, destinationChannels, wetMatrix );
	pSourceVoice->SetVolume( SoundClamp( gain, -XAUDIO2_MAX_VOLUME_LEVEL, XAUDIO2_MAX_VOLUME_LEVEL ) );
	const float ratio = SoundClamp( pitch * static_cast< float >( sampleRate ) /
		( std::max )( 1.0f, static_cast< float >( sourceVoiceRate ) ), XAUDIO2_MIN_FREQ_RATIO, XAUDIO2_MAX_FREQ_RATIO );
	pSourceVoice->SetFrequencyRatio( ratio );
	XAUDIO2_FILTER_PARAMETERS filter;
	filter.Type = LowPassFilter;
	filter.OneOverQ = 1.0f;
	filter.Frequency = SoundClamp( 1.0f - 0.75f * occlusion, 0.05f, XAUDIO2_MAX_FILTER_FREQUENCY );
	pSourceVoice->SetFilterParameters( &filter );
	return true;
}

bool idSoundVoice_XAudio2::IsPlaying() const {
	if ( pSourceVoice == NULL ) return false;
	XAUDIO2_VOICE_STATE state; pSourceVoice->GetState( &state, XAUDIO2_VOICE_NOSAMPLESPLAYED );
	return state.BuffersQueued != 0;
}

void idSoundVoice_XAudio2::FlushSourceBuffers() { if ( pSourceVoice != NULL ) pSourceVoice->FlushSourceBuffers(); }
void idSoundVoice_XAudio2::Pause() { if ( pSourceVoice != NULL && !paused ) { pSourceVoice->Stop(); paused = true; } }
void idSoundVoice_XAudio2::UnPause() { if ( pSourceVoice != NULL && paused ) { pSourceVoice->Start(); paused = false; } }
void idSoundVoice_XAudio2::Stop() { Pause(); }

float idSoundVoice_XAudio2::GetAmplitude() {
	if ( !hasVUMeter || pSourceVoice == NULL || sample == NULL ) return IsPlaying() ? 1.0f : 0.0f;
	float peak[ idWaveFile::CHANNEL_INDEX_MAX ] = { 0 };
	float rms[ idWaveFile::CHANNEL_INDEX_MAX ] = { 0 };
	XAUDIO2FX_VOLUMEMETER_LEVELS levels = { peak, rms, static_cast< UINT32 >(
		( std::min )( sample->NumChannels(), static_cast< int >( idWaveFile::CHANNEL_INDEX_MAX ) ) ) };
	if ( FAILED( pSourceVoice->GetEffectParameters( 0, &levels, sizeof( levels ) ) ) ) return 0.0f;
	float result = 0.0f;
	for ( UINT32 i = 0; i < levels.ChannelCount; ++i ) result += rms[ i ];
	return levels.ChannelCount > 0 ? result / levels.ChannelCount : 0.0f;
}
