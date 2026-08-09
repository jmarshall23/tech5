/*
===========================================================================
Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

Windows XAudio2 hardware implementation adapted from Doom 3 BFG Edition for
the current Windows SDK.  The 96-voice pool is the recovered idTech 5 layout.
===========================================================================
*/
#include "../sound_local.h"

idSoundHardware_XAudio2::idSoundHardware_XAudio2() : pXAudio2( NULL ),
	pMasterVoice( NULL ), pSubmixVoice( NULL ), dryGain( 1.0f ), outputChannels( 0 ),
	channelMask( 0 ), vuMeterRMS( NULL ), vuMeterPeak( NULL ) {
	soundEngineCallback.hardware = this;
	memset( vuMeterPeakTimes, 0, sizeof( vuMeterPeakTimes ) );
}

void idSoundEngineCallback::OnCriticalError( HRESULT ) {
	if ( hardware != NULL ) soundSystemLocal.needsRestart = true;
}

void idSoundHardware_XAudio2::Init() {
	if ( pXAudio2 != NULL ) return;
	UINT32 flags = 0;
	if ( FAILED( XAudio2Create( &pXAudio2, flags, XAUDIO2_DEFAULT_PROCESSOR ) ) ) {
		pXAudio2 = NULL; idLib::Warning( "Failed to create XAudio2 engine" ); return;
	}
	pXAudio2->RegisterForCallbacks( &soundEngineCallback );
	if ( FAILED( pXAudio2->CreateMasteringVoice( &pMasterVoice, XAUDIO2_DEFAULT_CHANNELS,
		44100, 0, NULL, NULL, AudioCategory_GameEffects ) ) ) {
		pXAudio2->UnregisterForCallbacks( &soundEngineCallback ); pXAudio2->Release(); pXAudio2 = NULL;
		idLib::Warning( "Failed to create XAudio2 mastering voice" ); return;
	}
	XAUDIO2_VOICE_DETAILS details; pMasterVoice->GetVoiceDetails( &details );
	outputChannels = details.InputChannels;
	if ( FAILED( pMasterVoice->GetChannelMask( reinterpret_cast< DWORD * >( &channelMask ) ) ) )
		channelMask = outputChannels == 1 ? SPEAKER_FRONT_CENTER : SPEAKER_STEREO;
	if ( FAILED( pXAudio2->CreateSubmixVoice( &pSubmixVoice, outputChannels, 44100 ) ) ) pSubmixVoice = NULL;
	if ( pSubmixVoice != NULL ) {
		IUnknown * reverb = NULL;
		if ( SUCCEEDED( XAudio2CreateReverb( &reverb, 0 ) ) ) {
			XAUDIO2_EFFECT_DESCRIPTOR descriptor = { reverb, TRUE, static_cast< UINT32 >( outputChannels ) };
			XAUDIO2_EFFECT_CHAIN chain = { 1, &descriptor };
			pSubmixVoice->SetEffectChain( &chain ); reverb->Release();
		}
	}
	voices.SetNum( 96 );
	freeVoices.Clear(); zombieVoices.Clear();
	for ( int i = 0; i < voices.Num(); ++i ) {
		voices[ i ].InitSurround( outputChannels, channelMask ); freeVoices.Append( &voices[ i ] );
	}
}

void idSoundHardware_XAudio2::Shutdown() {
	for ( int i = 0; i < voices.Num(); ++i ) voices[ i ].DestroyInternal();
	voices.Clear(); freeVoices.Clear(); zombieVoices.Clear();
	if ( pSubmixVoice != NULL ) { pSubmixVoice->SetEffectChain( NULL ); pSubmixVoice->DestroyVoice(); pSubmixVoice = NULL; }
	if ( pMasterVoice != NULL ) { pMasterVoice->DestroyVoice(); pMasterVoice = NULL; }
	if ( pXAudio2 != NULL ) {
		pXAudio2->UnregisterForCallbacks( &soundEngineCallback ); pXAudio2->Release(); pXAudio2 = NULL;
	}
	outputChannels = channelMask = 0;
}

idSoundVoice * idSoundHardware_XAudio2::AllocateVoice( const idSoundSample * leadin,
	const idSoundSample * looping ) {
	if ( leadin == NULL || pXAudio2 == NULL ) return NULL;
	if ( looping != NULL && ( leadin->format.basic.formatTag != looping->format.basic.formatTag ||
		leadin->format.basic.numChannels != looping->format.basic.numChannels ) ) looping = NULL;
	idSoundVoice_XAudio2 * selected = NULL;
	for ( int i = 0; i < freeVoices.Num(); ++i ) {
		if ( freeVoices[ i ]->IsPlaying() ) continue;
		selected = freeVoices[ i ];
		if ( selected->CompatibleFormat( const_cast< idSoundSample * >( leadin ) ) ) break;
	}
	if ( selected == NULL ) return NULL;
	freeVoices.Remove( selected );
	selected->Create( leadin, looping );
	return reinterpret_cast< idSoundVoice * >( selected );
}

void idSoundHardware_XAudio2::FreeVoice( idSoundVoice * voice ) {
	if ( voice == NULL ) return;
	idSoundVoice_XAudio2 * xaVoice = reinterpret_cast< idSoundVoice_XAudio2 * >( voice );
	if ( zombieVoices.FindIndex( xaVoice ) >= 0 || freeVoices.FindIndex( xaVoice ) >= 0 ) return;
	xaVoice->Stop();
	zombieVoices.Append( xaVoice );
}

void idSoundHardware_XAudio2::Update() {
	if ( pXAudio2 == NULL || pMasterVoice == NULL ) return;
	pMasterVoice->SetVolume( soundSystemLocal.muted ? 0.0f : dryGain );
	pXAudio2->CommitChanges( XAUDIO2_COMMIT_ALL );
	for ( int i = zombieVoices.Num() - 1; i >= 0; --i ) {
		idSoundVoice_XAudio2 * voice = zombieVoices[ i ];
		voice->FlushSourceBuffers();
		if ( !voice->IsPlaying() ) { zombieVoices.RemoveIndexFast( i ); freeVoices.Append( voice ); }
	}
}

void idSoundHardware_XAudio2::SetReverb( const void * environmentPointer ) {
	if ( pSubmixVoice == NULL || environmentPointer == NULL ) return;
	const soundEnvironment_t & environment = *static_cast< const soundEnvironment_t * >( environmentPointer );
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS i3dl2 = XAUDIO2FX_I3DL2_PRESET_DEFAULT;
	i3dl2.WetDryMix = 100.0f;
	i3dl2.Room = static_cast< INT32 >( SoundClamp( environment.RoomGain * 100.0f, -10000.0f, 0.0f ) );
	i3dl2.RoomHF = static_cast< INT32 >( SoundClamp( environment.RoomHFGain * 100.0f, -10000.0f, 0.0f ) );
	i3dl2.DecayTime = SoundClamp( environment.DecayTime * 0.001f, 0.1f, 20.0f );
	i3dl2.DecayHFRatio = SoundClamp( environment.DecayHFTime * 0.001f /
		( std::max )( i3dl2.DecayTime, 0.1f ), 0.1f, 2.0f );
	i3dl2.Reflections = static_cast< INT32 >( SoundClamp( environment.ReflectionsGain * 100.0f, -10000.0f, 1000.0f ) );
	i3dl2.ReflectionsDelay = SoundClamp( environment.ReflectionsDelay * 0.001f, 0.0f, 0.3f );
	i3dl2.Reverb = static_cast< INT32 >( SoundClamp( environment.ReverbGain * 100.0f, -10000.0f, 2000.0f ) );
	i3dl2.ReverbDelay = SoundClamp( environment.ReverbDelay * 0.001f, 0.0f, 0.1f );
	i3dl2.Diffusion = SoundClamp( environment.Diffusion, 0.0f, 100.0f );
	i3dl2.Density = SoundClamp( environment.Density, 0.0f, 100.0f );
	i3dl2.HFReference = SoundClamp( environment.HFReference, 20.0f, 20000.0f );
	XAUDIO2FX_REVERB_PARAMETERS native;
	ReverbConvertI3DL2ToNative( &i3dl2, &native );
	pSubmixVoice->SetEffectParameters( 0, &native, sizeof( native ) );
}

