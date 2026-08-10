#include "rendersystem_local.h"

#include "renderthread.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace {
	ULONGLONG binkStartTime = 0;
}
void idRenderSystemLocal::BeginBinkVideo( void * window, const char * name,
		const videoFlags_t flags, idRenderVideoOverlay * overlay ) {
	FreeBinkVideo();
	if ( name == nullptr || *name == '\0' || flags == VIDEO_EXIT ) return;
	videoOverlay = overlay;
	binkLoaded = true;
	binkPlaying = true;
	binkStartTime = GetTickCount64();
	if ( renderThread != nullptr ) {
		SyncRenderThread( false );
		renderThread->renderModeBeforeSync = RENDER_MODE_BINK;
		RestartRenderThread( window );
	}
}
bool idRenderSystemLocal::BinkVideoIsLoaded() { return binkLoaded; }
bool idRenderSystemLocal::BinkVideoIsPlaying() { return binkPlaying; }
bool idRenderSystemLocal::WaitForNextVideoFrame() { return binkLoaded && binkPlaying; }
unsigned int idRenderSystemLocal::GetBinkWidth() const { return binkLoaded ? 1280u : 0u; }
unsigned int idRenderSystemLocal::GetBinkHeight() const { return binkLoaded ? 720u : 0u; }
float idRenderSystemLocal::GetBinkTime() const {
	return binkLoaded ? static_cast< float >( GetTickCount64() - binkStartTime ) * 0.001f : 0.0f;
}
void idRenderSystemLocal::UpdateBinkTextures() {
	// Bink is middleware-owned.  The recovered renderer only maintains the
	// playback/present contract; decoded planes arrive through videoOverlay.
}
void idRenderSystemLocal::FreeBinkVideo() {
	binkLoaded = binkPlaying = false;
	videoOverlay = nullptr;
	binkStartTime = 0;
}
