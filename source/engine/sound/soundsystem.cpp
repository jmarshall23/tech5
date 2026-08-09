#include "sound_local.h"

idSoundSystemLocal soundSystemLocal;
idSoundSystem * soundSystem = &soundSystemLocal;

idSoundThread::idSoundThread() : initialized( false ) {}

void idSoundThread::Render() {
	if ( soundSystemLocal.currentSoundWorld != NULL ) soundSystemLocal.currentSoundWorld->Update();
	soundSystemLocal.hardware.Update();
	soundSystemLocal.soundTime = Sys_Milliseconds();
}

int idSoundThread::Run() {
	initialized = true;
	Render();
	return 0;
}

idSoundSystemLocal::idSoundSystemLocal() : soundTime( 0 ), editorSoundWorld( NULL ),
	currentSoundWorld( NULL ), random( 0 ), muted( false ), musicMuted( false ),
	needsRestart( false ), soundThreadRunning( false ), soundThread( NULL ), parallelJobList( NULL ) {}

idSoundSystemLocal::~idSoundSystemLocal() { Shutdown(); }

void idSoundSystemLocal::Init() {
	if ( soundThread != NULL ) return;
	idLib::Printf( "----- Initializing Sound System ------\n" );
	soundTime = Sys_Milliseconds(); random.SetSeed( static_cast< unsigned int >( soundTime ) );
	soundThread = new idSoundThread();
	soundThread->StartWorkerThread( "SoundThread", CORE_ANY, THREAD_NORMAL, 0x20000 );
	hardware.Init();
	InitStreamBuffers();
	idLib::Printf( "sound system initialized.\n--------------------------------------\n" );
}

void idSoundSystemLocal::Shutdown() {
	if ( soundThread == NULL && hardware.GetIXAudio2() == NULL && bufferContexts.Num() == 0 ) return;
	WaitForSoundThread();
	StopAllSounds();
	hardware.Shutdown();
	FreeStreamBuffers();
	if ( soundThread != NULL ) { soundThread->StopThread( true ); delete soundThread; soundThread = NULL; }
	soundThreadRunning = false;
}

idSoundWorld * idSoundSystemLocal::AllocSoundWorld( const char * name, idRenderWorld * world ) {
	idSoundWorldLocal * result = new idSoundWorldLocal();
	result->LoadMap( name ); result->renderWorld = world;
	soundWorlds.Append( result );
	return result;
}

void idSoundSystemLocal::FreeSoundWorld( idSoundWorld * world ) {
	idSoundWorldLocal * local = static_cast< idSoundWorldLocal * >( world );
	const int index = soundWorlds.FindIndex( local );
	if ( index >= 0 ) soundWorlds.RemoveIndexFast( index );
	if ( currentSoundWorld == local ) currentSoundWorld = NULL;
	if ( editorSoundWorld == local ) editorSoundWorld = NULL;
	delete local;
}

void idSoundSystemLocal::SetPlayingSoundWorld( idSoundWorld * world ) {
	idSoundWorldLocal * local = static_cast< idSoundWorldLocal * >( world );
	if ( currentSoundWorld == local ) return;
	idSoundWorldLocal * previous = currentSoundWorld;
	currentSoundWorld = local;
	if ( previous != NULL ) previous->Update();
}

void idSoundSystemLocal::SetEditorSoundWorld( idSoundWorld * world ) {
	editorSoundWorld = static_cast< idSoundWorldLocal * >( world );
}

void idSoundSystemLocal::WaitForSoundThread() {
	if ( soundThread != NULL && soundThreadRunning ) {
		soundThread->WaitForThread(); soundThreadRunning = false;
	}
}

void idSoundSystemLocal::Render( bool threaded ) {
	if ( soundThread == NULL ) return;
	WaitForSoundThread();
	if ( needsRestart ) { needsRestart = false; Restart(); }
	if ( threaded ) { soundThreadRunning = true; soundThread->SignalWork(); }
	else soundThread->Render();
}

void idSoundSystemLocal::Restart() {
	WaitForSoundThread();
	for ( int w = 0; w < soundWorlds.Num(); ++w ) {
		idSoundWorldLocal * world = soundWorlds[ w ];
		for ( int e = 0; world != NULL && e < world->emitters.Num(); ++e ) {
			idSoundEmitterLocal * emitter = world->emitters[ e ];
			for ( int c = 0; emitter != NULL && c < emitter->channels.Num(); ++c ) emitter->channels[ c ]->Mute();
		}
	}
	hardware.Shutdown(); hardware.Init(); InitStreamBuffers();
}

void idSoundSystemLocal::OnReloadSound( const idDecl * sound ) {
	const idSoundShader * shader = static_cast< const idSoundShader * >( sound );
	for ( int i = 0; i < soundWorlds.Num(); ++i ) if ( soundWorlds[ i ] != NULL ) soundWorlds[ i ]->OnReloadSound( shader );
}

void idSoundSystemLocal::StopAllSounds() {
	for ( int i = 0; i < soundWorlds.Num(); ++i ) if ( soundWorlds[ i ] != NULL ) soundWorlds[ i ]->StopAllSounds();
	hardware.Update();
}

idSoundVoice * idSoundSystemLocal::AllocateVoice( const idSoundSample * leadin,
	const idSoundSample * looping ) {
	return hardware.AllocateVoice( leadin, looping );
}

void idSoundSystemLocal::FreeVoice( idSoundVoice * voice ) { hardware.FreeVoice( voice ); }

void idSoundSystemLocal::StopVoicesWithSample( const idSoundSample * sample ) {
	for ( int w = 0; w < soundWorlds.Num(); ++w ) {
		idSoundWorldLocal * world = soundWorlds[ w ];
		for ( int e = 0; world != NULL && e < world->emitters.Num(); ++e ) {
			idSoundEmitterLocal * emitter = world->emitters[ e ];
			for ( int c = 0; emitter != NULL && c < emitter->channels.Num(); ++c )
				if ( emitter->channels[ c ]->sample == sample ) emitter->channels[ c ]->Mute();
		}
	}
}

void idSoundSystemLocal::InitStreamBuffers() {
	streamBufferMutex.Lock();
	if ( bufferContexts.Num() == 0 ) {
		bufferContexts.SetNum( 144 );
		for ( int i = 0; i < bufferContexts.Num(); ++i ) {
			bufferContexts[ i ].voice = NULL;
			bufferContexts[ i ].sampleRate = 0;
			bufferContexts[ i ].buffer = new unsigned char[ 64 * 1024 ];
			freeStreamBufferContexts.Append( &bufferContexts[ i ] );
		}
	} else {
		for ( int i = 0; i < activeStreamBufferContexts.Num(); ++i ) freeStreamBufferContexts.Append( activeStreamBufferContexts[ i ] );
		activeStreamBufferContexts.Clear();
	}
	streamBufferMutex.Unlock();
}

void idSoundSystemLocal::FreeStreamBuffers() {
	streamBufferMutex.Lock();
	for ( int i = 0; i < bufferContexts.Num(); ++i ) {
		delete[] static_cast< unsigned char * >( bufferContexts[ i ].buffer );
		bufferContexts[ i ].buffer = NULL;
	}
	bufferContexts.Clear(); freeStreamBufferContexts.Clear(); activeStreamBufferContexts.Clear();
	streamBufferMutex.Unlock();
}

idSoundSystemLocal::bufferContext_t * idSoundSystemLocal::ObtainStreamBufferContext() {
	streamBufferMutex.Lock();
	bufferContext_t * result = NULL;
	if ( freeStreamBufferContexts.Num() > 0 ) {
		result = freeStreamBufferContexts[ freeStreamBufferContexts.Num() - 1 ];
		freeStreamBufferContexts.RemoveIndexFast( freeStreamBufferContexts.Num() - 1 );
		activeStreamBufferContexts.Append( result );
	}
	streamBufferMutex.Unlock();
	return result;
}

void idSoundSystemLocal::ReleaseStreamBufferContext( bufferContext_t * context ) {
	if ( context == NULL ) return;
	streamBufferMutex.Lock();
	const int index = activeStreamBufferContexts.FindIndex( context );
	if ( index >= 0 ) { activeStreamBufferContexts.RemoveIndexFast( index ); freeStreamBufferContexts.Append( context ); }
	streamBufferMutex.Unlock();
}

