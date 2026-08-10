#include "rendersystem_local.h"

#include "renderthread.h"

idRenderThread::idRenderThread() : hdc( nullptr ), renderMode( RENDER_MODE_MANUAL ),
	renderModeBeforeSync( RENDER_MODE_MANUAL ), initialized( false ) {}
idRenderThread::~idRenderThread() {}

int idRenderThread::Run() {
	initialized = true;
	if ( renderMode == RENDER_MODE_BINK ) {
		if ( !renderSystemLocal.WaitForNextVideoFrame() ) renderMode = RENDER_MODE_MANUAL;
		else renderSystemLocal.UpdateBinkTextures();
	}
	if ( renderMode != RENDER_MODE_MANUAL && rendererD3D9.EnsureReady() )
		rendererD3D9.Present();
	return 0;
}
void idRenderSystemLocal::StartRenderThread() {
	if ( renderThread != nullptr ) return;
	renderThread = new idRenderThread();
	if ( !renderThread->StartWorkerThread( "Renderer", CORE_ANY,
		THREAD_NORMAL, 0x20000 ) ) {
		delete renderThread;
		renderThread = nullptr;
	}
}

bool idRenderSystemLocal::SyncRenderThread( const bool syncGPU ) {
	if ( renderThread == nullptr ) {
		if ( syncGPU ) GL_Finish();
		return false;
	}
	renderThread->renderModeBeforeSync = renderThread->renderMode;
	renderThread->renderMode = RENDER_MODE_MANUAL;
	const bool waited = !renderSynced;
	if ( waited ) renderThread->WaitForThread();
	renderSynced = true;
	if ( syncGPU ) GL_Finish();
	return waited;
}

void idRenderSystemLocal::RestartRenderThread( void * window ) {
	if ( renderThread == nullptr || !renderSynced ) return;
	if ( window != nullptr ) renderThread->hdc = window;
	renderThread->renderMode = renderThread->renderModeBeforeSync;
	if ( renderThread->renderMode != RENDER_MODE_MANUAL ) {
		renderSynced = false;
		renderThread->SignalWork();
	}
}

void idRenderSystemLocal::AllowBackgroundSwaps( const bool allow ) { allowBackgroundSwaps = allow; }
void idRenderSystemLocal::SetLoadingIconInfo( float x, float y, float scale, float speed ) {
	loadingIconPosX = x; loadingIconPosY = y; loadingIconScale = scale; loadingIconSpeed = speed;
}
void idRenderSystemLocal::BeginAutomaticBackgroundSwaps( void * window, const bool showIcon ) {
	if ( !allowBackgroundSwaps || renderThread == nullptr ) return;
	SyncRenderThread( false );
	renderLoadingIcon = showIcon;
	automaticBackgroundSwapsEnabled = true;
	renderThread->renderModeBeforeSync = RENDER_MODE_AUTOMATIC;
	RestartRenderThread( window );
}
void idRenderSystemLocal::EndAutomaticBackgroundSwaps() {
	if ( renderThread != nullptr ) {
		SyncRenderThread( false );
		renderThread->renderModeBeforeSync = RENDER_MODE_MANUAL;
	}
	automaticBackgroundSwapsEnabled = false;
	renderLoadingIcon = false;
}
