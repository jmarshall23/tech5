#include "sound_local.h"

namespace {
soundEnvironment_t DefaultEnvironment() {
	soundEnvironment_t environment;
	memset( &environment, 0, sizeof( environment ) );
	environment.SoundEnvType = SET_DEFAULT;
	environment.currentVolume = 1.0f;
	environment.desiredVolume = 1.0f;
	return environment;
}

void InitializeListener( listener_t & listener ) {
	listener.valid = false;
	listener.environmentValid = false;
	listener.axis = idMat3( 1.0f );
	listener.pos.Set( 0.0f, 0.0f, 0.0f );
	listener.vel.Set( 0.0f, 0.0f, 0.0f );
	listener.id = 0; listener.area = -1;
	listener.maxDB = listener.maxDBFrame = -60.0f;
	listener.shakeAmp = listener.tinnitus = 0.0f;
	listener.environment = listener.currentEnv = DefaultEnvironment();
	listener.route.Clear();
	listener.routingParms = NULL;
	listener.envBlendAlpha = 0.0f;
}
}

idSoundWorldLocal::idSoundWorldLocal() : renderWorld( NULL ), listenerIndex( 0 ),
	numListeners( 1 ), currentCushionDB( -60.0f ), localSound( NULL ), tinnitusEmitter( NULL ),
	pausedTime( 0 ), accumulatedPauseTime( 0 ), isPaused( false ) {
	volumeFade.Clear(); pauseFade.Clear();
	for ( int i = 0; i < 25; ++i ) groupFade[ i ].Clear();
	for ( int i = 0; i < 2; ++i ) { InitializeListener( listeners[ i ] ); AllocRouting( &listeners[ i ] ); }
	for ( int i = 0; i < 32; ++i ) positionedEmitters[ i ] = NULL;
	environments.SetNum( 1 ); environments[ 0 ] = DefaultEnvironment();

	idSoundEmitterLocal * emitter = emitterAllocator.Alloc();
	if ( emitter != NULL ) { emitter->Init( emitters.Append( emitter ), this ); localSound = emitter; }
	for ( int i = 0; i < 32; ++i ) {
		emitter = emitterAllocator.Alloc();
		if ( emitter != NULL ) { emitter->Init( emitters.Append( emitter ), this ); positionedEmitters[ i ] = emitter; }
	}
	emitter = emitterAllocator.Alloc();
	if ( emitter != NULL ) { emitter->Init( emitters.Append( emitter ), this ); tinnitusEmitter = emitter; }
}

idSoundWorldLocal::~idSoundWorldLocal() {
	if ( soundSystemLocal.currentSoundWorld == this ) soundSystemLocal.currentSoundWorld = NULL;
	if ( soundSystemLocal.editorSoundWorld == this ) soundSystemLocal.editorSoundWorld = NULL;
	for ( int i = 0; i < 2; ++i ) {
		if ( listeners[ i ].routingParms != NULL ) {
			delete[] listeners[ i ].routingParms->temp;
			delete listeners[ i ].routingParms;
			listeners[ i ].routingParms = NULL;
		}
	}
	while ( emitters.Num() > 0 ) {
		idSoundEmitterLocal * emitter = emitters[ emitters.Num() - 1 ];
		emitters.RemoveIndexFast( emitters.Num() - 1 );
		emitterAllocator.Free( emitter );
	}
	renderWorld = NULL; localSound = tinnitusEmitter = NULL;
}

void idSoundWorldLocal::AllocRouting( listener_t * listener ) {
	if ( listener == NULL || listener->routingParms != NULL ) return;
	listener->routingParms = new soundRoutingParms_t();
	memset( listener->routingParms, 0, sizeof( *listener->routingParms ) );
	listener->routingParms->tempSize = 61440;
	listener->routingParms->temp = new unsigned char[ listener->routingParms->tempSize ];
}

int idSoundWorldLocal::GetSoundTime() {
	return ( isPaused ? pausedTime : soundSystemLocal.soundTime ) - accumulatedPauseTime;
}

void idSoundWorldLocal::SetNumListeners( int count ) {
	numListeners = ( std::max )( 1, ( std::min )( count, 2 ) );
	listenerIndex = 0;
}

void idSoundWorldLocal::PlaceListener( const idVec3 * origin, const idMat3 * listenerAxis,
	const idVec3 * listenerVelocity, int listenerId ) {
	if ( origin == NULL || listenerAxis == NULL || listenerVelocity == NULL ) return;
	int slot = 0;
	if ( numListeners > 1 ) {
		for ( int i = 0; i < listenerIndex; ++i ) if ( listeners[ i ].id == listenerId ) { slot = i; goto found; }
		if ( listenerIndex >= 2 ) { listenerIndex = 0; return; }
		slot = listenerIndex++;
	}
found:
	listener_t & listener = listeners[ slot ];
	listener.valid = true; listener.axis = *listenerAxis; listener.pos = *origin;
	listener.vel = *listenerVelocity; listener.id = listenerId;
}

void idSoundWorldLocal::StopAllSounds() {
	for ( int i = 0; i < emitters.Num(); ++i ) if ( emitters[ i ] != NULL ) emitters[ i ]->Reset();
}

idSoundEmitter * idSoundWorldLocal::AllocSoundEmitter() {
	idSoundEmitterLocal * emitter = emitterAllocator.Alloc();
	if ( emitter == NULL ) return NULL;
	emitter->Init( emitters.Append( emitter ), this );
	return emitter;
}

int idSoundWorldLocal::NumEmitters() { return emitters.Num(); }

idSoundEmitter * idSoundWorldLocal::EmitterForIndex( int emitterIndex ) {
	return emitterIndex >= 0 && emitterIndex < emitters.Num() ? emitters[ emitterIndex ] : NULL;
}

int idSoundWorldLocal::FindEnvironment( const idVec3 * origin ) {
	if ( origin == NULL || sbspFile.areas.Num() == 0 ) return 0;
	const int area = sbspFile.PointAreaNum( *origin );
	return area >= 0 && area < sbspFile.areas.Num() ? sbspFile.areas[ area ].environment : 0;
}

bool idSoundWorldLocal::SetEnvironmentParams( int index, const soundEnvironment_t * environment ) {
	if ( environment == NULL || index < 0 || index >= environments.Num() ) return false;
	environments[ index ] = *environment; return true;
}

bool idSoundWorldLocal::GetEnvironmentParams( int index, soundEnvironment_t * environment ) {
	if ( environment == NULL || index < 0 || index >= environments.Num() ) return false;
	*environment = environments[ index ]; return true;
}

void idSoundWorldLocal::BlendEnv( soundEnvironment_t & result, const soundEnvironment_t & from,
	const soundEnvironment_t & to, float alpha ) const {
	alpha = SoundClamp( alpha, 0.0f, 1.0f );
	#define BLEND_FLOAT( member ) result.member = from.member + ( to.member - from.member ) * alpha
	#define BLEND_INT( member ) result.member = static_cast< int >( from.member + ( to.member - from.member ) * alpha )
	BLEND_FLOAT( DryGain ); BLEND_FLOAT( RoomGain ); BLEND_FLOAT( RoomHFGain );
	BLEND_INT( DecayTime ); BLEND_INT( DecayHFTime );
	BLEND_FLOAT( ReflectionsGain ); BLEND_FLOAT( ReverbGain );
	BLEND_INT( ReflectionsDelay ); BLEND_INT( ReverbDelay );
	BLEND_FLOAT( Diffusion ); BLEND_FLOAT( Density ); BLEND_FLOAT( HFReference );
	BLEND_FLOAT( currentVolume ); BLEND_FLOAT( desiredVolume );
	#undef BLEND_FLOAT
	#undef BLEND_INT
	result.SoundEnvType = alpha < 0.5f ? from.SoundEnvType : to.SoundEnvType;
}

void idSoundWorldLocal::OverrideEnvironmentParams( const soundEnvironment_t * environment, int listenerId ) {
	if ( environment == NULL ) return;
	BlendEnvironmentParams( environment, environment->RoomGain <= -60.0f ? 0.0f : 1.0f, listenerId );
}

void idSoundWorldLocal::BlendEnvironmentParams( const soundEnvironment_t * environment, float alpha,
	int listenerId ) {
	if ( environment == NULL ) return;
	int slot = numListeners <= 1 ? 0 : listenerId;
	if ( slot < 0 || slot >= numListeners ) slot = 0;
	listeners[ slot ].environment = *environment;
	listeners[ slot ].envBlendAlpha = SoundClamp( alpha, 0.0f, 1.0f );
	listeners[ slot ].environmentValid = true;
}

int idSoundWorldLocal::FindDoor( const idVec3 * origin ) {
	if ( origin == NULL ) return -1;
	int area = sbspFile.PointAreaNum( *origin );
	if ( area >= 0 && area < sbspFile.areas.Num() && sbspFile.areas[ area ].door >= 0 ) return sbspFile.areas[ area ].door;
	for ( int axisIndex = 0; axisIndex < 3; ++axisIndex ) for ( int sign = -1; sign <= 1; sign += 2 ) {
		idVec3 point = *origin; point[ axisIndex ] += static_cast< float >( sign );
		area = sbspFile.PointAreaNum( point );
		if ( area >= 0 && area < sbspFile.areas.Num() && sbspFile.areas[ area ].door >= 0 ) return sbspFile.areas[ area ].door;
	}
	return -1;
}

void idSoundWorldLocal::SetDoor( int doorNum, float value ) {
	if ( doorNum >= 0 && doorNum < doors.Num() ) doors[ doorNum ] = value;
}

float idSoundWorldLocal::CurrentShakeAmplitude( int listenerId ) {
	float total = 0.0f;
	for ( int i = 0; i < numListeners; ++i ) {
		if ( listeners[ i ].id == listenerId ) return listeners[ i ].shakeAmp;
		total += listeners[ i ].shakeAmp;
	}
	return numListeners > 0 ? total / numListeners : 0.0f;
}

int idSoundWorldLocal::PlayGlobalShaderDirectly( const idSoundShader * shader,
	soundChannel_t channel, float volume ) {
	if ( localSound == NULL ) return 0;
	localSound->SetVolumeAdjustment( volume );
	return localSound->StartSound( channel, shader, NULL );
}

int idSoundWorldLocal::PlayPositionedShaderDirectly( const idSoundShader * shader,
	const idVec3 * origin, const idMat3 * emitterAxis, float volume ) {
	if ( shader == NULL || origin == NULL || emitterAxis == NULL ) return 0;
	for ( int i = 0; i < 32; ++i ) {
		idSoundEmitterLocal * emitter = static_cast< idSoundEmitterLocal * >( positionedEmitters[ i ] );
		if ( emitter != NULL && ( emitter->canFree || emitter->channels.Num() == 0 ) ) {
			emitter->Reset(); idVec3 zero; zero.Set( 0.0f, 0.0f, 0.0f );
			emitter->UpdateEmitter( origin, emitterAxis, &zero, -1 ); emitter->SetVolumeAdjustment( volume );
			const int length = emitter->StartSound( SND_CHANNEL_ANY, shader, NULL ); emitter->Free( false ); return length;
		}
	}
	return 0;
}

void idSoundWorldLocal::Fade( soundShaderGroups_t group, float to, int length ) {
	const int now = GetSoundTime();
	if ( group == SSG_MASTER ) { volumeFade.Fade( to, length, now ); return; }
	int mask = 1;
	for ( int i = 0; i < 25; ++i, mask <<= 1 ) if ( static_cast< int >( group ) & mask ) groupFade[ i ].Fade( to, length, now );
}

void idSoundWorldLocal::Duck( const idDeclDuck * declaration, int fadeIn, int hold, int fadeOut ) {
	if ( declaration == NULL ) return;
	const int now = GetSoundTime();
	int index = -1;
	for ( int i = 0; i < ducks.Num(); ++i ) if ( ducks[ i ].decl == declaration ) { index = i; break; }
	if ( index < 0 ) {
		if ( ducks.Num() >= 4 ) ducks.RemoveIndex( 0 );
		idDuckLayer layer; memset( &layer, 0, sizeof( layer ) ); layer.decl = declaration;
		for ( int i = 0; i < 25; ++i ) layer.fromVolumes[ i ] = 0.0f;
		index = ducks.Append( layer );
	}
	idDuckLayer & layer = ducks[ index ];
	layer.startFadeStart = now; layer.startFadeEnd = now + fadeIn;
	layer.endFadeStart = hold < 0 ? -1 : layer.startFadeEnd + hold;
	layer.endFadeEnd = layer.endFadeStart < 0 ? -1 : layer.endFadeStart + fadeOut;
	layer.blendAlpha = 1.0f;
}

void idSoundWorldLocal::DuckBlend( const idDeclDuck * declaration, float alpha ) {
	if ( declaration == NULL ) return;
	for ( int i = 0; i < ducks.Num(); ++i ) if ( ducks[ i ].decl == declaration ) {
		ducks[ i ].blendAlpha = SoundClamp( alpha, 0.0f, 1.0f ); return;
	}
	Duck( declaration, 0, -1, 0 ); ducks[ ducks.Num() - 1 ].blendAlpha = SoundClamp( alpha, 0.0f, 1.0f );
}

bool idSoundWorldLocal::Trace( const idVec3 * start, const idVec3 * end ) {
	return start != NULL && end != NULL && ExternalSoundTrace( sbspFile.flatBSP, *start, *end );
}

void idSoundWorldLocal::Pause() {
	if ( isPaused ) return;
	pausedTime = soundSystemLocal.soundTime; isPaused = true; pauseFade.SetVolume( -60.0f );
	for ( int e = 0; e < emitters.Num(); ++e ) for ( int c = 0; c < emitters[ e ]->channels.Num(); ++c )
		if ( emitters[ e ]->channels[ c ]->hardwareVoice != NULL ) emitters[ e ]->channels[ c ]->hardwareVoice->Pause();
}

void idSoundWorldLocal::UnPause() {
	if ( !isPaused ) return;
	accumulatedPauseTime += soundSystemLocal.soundTime - pausedTime; isPaused = false; pauseFade.SetVolume( 0.0f );
	for ( int e = 0; e < emitters.Num(); ++e ) for ( int c = 0; c < emitters[ e ]->channels.Num(); ++c )
		if ( emitters[ e ]->channels[ c ]->hardwareVoice != NULL ) emitters[ e ]->channels[ c ]->hardwareVoice->UnPause();
}

bool idSoundWorldLocal::LoadMap( const char * mapName ) {
	if ( mapName == NULL || mapName[ 0 ] == '\0' ) {
		sbspFile.Clear(); environments.SetNum( 1 ); environments[ 0 ] = DefaultEnvironment(); doors.Clear(); return true;
	}
	idStr path( mapName ); path.SetFileExtension( "sbsp" );
	if ( !sbspFile.Read( path.c_str() ) ) {
		sbspFile.Clear(); environments.SetNum( 1 ); environments[ 0 ] = DefaultEnvironment(); doors.Clear(); return false;
	}
	environments.SetNum( ( std::max )( 1, sbspFile.numEnvironments ) );
	for ( int i = 0; i < environments.Num(); ++i ) environments[ i ] = DefaultEnvironment();
	doors.SetNum( sbspFile.numDoors ); for ( int i = 0; i < doors.Num(); ++i ) doors[ i ] = 0.0f;
	return true;
}

void idSoundWorldLocal::UpdateForListener( listener_t * listener ) {
	if ( listener == NULL || !listener->valid ) return;
	listener->area = sbspFile.PointAreaNum( listener->pos );
	if ( listener->routingParms != NULL ) {
		listener->route.SetNum( sbspFile.areas.Num() );
		listener->routingParms->route = listener->route.Ptr();
		listener->routingParms->flatBSP = sbspFile.flatBSP;
		listener->routingParms->numAreas = sbspFile.areas.Num();
		listener->routingParms->listenerAreaNum = listener->area;
		listener->routingParms->listenerOrigin = listener->pos;
		SoundRoutingJob( *listener->routingParms );
	}
	int environmentIndex = listener->area >= 0 && listener->area < sbspFile.areas.Num() ?
		sbspFile.areas[ listener->area ].environment : 0;
	if ( environmentIndex < 0 || environmentIndex >= environments.Num() ) environmentIndex = 0;
	soundEnvironment_t mapEnvironment = environments[ environmentIndex ];
	if ( listener->environmentValid ) BlendEnv( listener->currentEnv, mapEnvironment,
		listener->environment, listener->envBlendAlpha ); else listener->currentEnv = mapEnvironment;
	if ( listener == &listeners[ 0 ] ) soundSystemLocal.hardware.SetReverb( &listener->currentEnv );
	listener->maxDBFrame = -60.0f; listener->shakeAmp = 0.0f;
	for ( int i = 0; i < emitters.Num(); ++i ) {
		if ( emitters[ i ] == NULL || emitters[ i ]->canFree ) continue;
		listener->maxDBFrame = ( std::max )( listener->maxDBFrame,
			emitters[ i ]->Update( listener, GetSoundTime() ) );
		for ( int c = 0; c < emitters[ i ]->channels.Num(); ++c ) listener->shakeAmp += emitters[ i ]->channels[ c ]->currentShakeAmplitude;
	}
	listener->maxDB = listener->maxDBFrame;
}

void idSoundWorldLocal::Update() {
	for ( int i = 0; i < numListeners; ++i ) UpdateForListener( &listeners[ i ] );
	const int now = GetSoundTime();
	for ( int i = emitters.Num() - 1; i >= 0; --i ) {
		idSoundEmitterLocal * emitter = emitters[ i ];
		if ( emitter != NULL && emitter->CheckForCompletion( now ) && emitter != localSound &&
			emitter != tinnitusEmitter ) {
			bool positioned = false;
			for ( int p = 0; p < 32; ++p ) if ( positionedEmitters[ p ] == emitter ) positioned = true;
			if ( !positioned ) {
				emitters.RemoveIndexFast( i );
				if ( i < emitters.Num() && emitters[ i ] != NULL ) emitters[ i ]->index = i;
				emitterAllocator.Free( emitter );
			}
		}
	}
}

void idSoundWorldLocal::OnReloadSound( const idSoundShader * shader ) {
	for ( int i = 0; i < emitters.Num(); ++i ) if ( emitters[ i ] != NULL ) emitters[ i ]->OnReloadSound( shader );
}

void idSoundWorldLocal::FreeSoundChannel( idSoundChannel * channel ) {
	if ( channel == NULL ) return;
	channel->channelNode.Remove();
	channelAllocator.Free( channel );
}

void idSoundWorldLocal::DrawDebug( idRenderWorld * world ) {
	for ( int i = 0; i < emitters.Num(); ++i ) if ( emitters[ i ] != NULL ) emitters[ i ]->DrawDebugInfo( world );
}
