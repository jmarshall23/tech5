#pragma once

#include "renderer_types.h"

class idMaterial;
class idRenderFrameInfo;
class idRenderModel;
class idRenderVideoOverlay;
class idRenderView;
class idRenderWorld;

class idRenderSystem {
public:
	virtual ~idRenderSystem();
	virtual void Init();
	virtual void Init2();
	virtual void Shutdown();
	virtual idRenderWorld * AllocRenderWorld( const char * name, bool isPrimary );
	virtual void RenderFrame( void * window, const idRenderFrameInfo * frameInfo,
		bool isLoading, bool enableBink, bool runPerformanceCounters );
	virtual void EndFrame( void * window, int windowWidth, int windowHeight,
		idRenderWorld * world, idRenderModel ** models, int numModels,
		bool isLoading, bool showConsole, bool allowSwap, int frameTime );
	virtual void ToolEndFrame( void * window, int width, int height,
		idRenderWorld * world, const struct renderView_t * view,
		idRenderModel * model, int flags );
	virtual int FrameNumber();
	virtual bool SyncRenderThread( bool allowBackground );
	virtual void BeginBinkVideo( void * window, const char * name,
		videoFlags_t flags, idRenderVideoOverlay * overlay );
	virtual bool BinkVideoIsLoaded();
	virtual bool BinkVideoIsPlaying();
	virtual void FreeBinkVideo();
	virtual void AllowBackgroundSwaps( bool allow );
	virtual void BeginAutomaticBackgroundSwaps( void * window, bool loading );
	virtual void EndAutomaticBackgroundSwaps();
	virtual void SetLoadingIconInfo( float x, float y, float scale, float speed );
	virtual void RegenerateReferences();
	virtual void InhibitEndFrameRendering( int inhibit );
	virtual bool IsEndFrameRenderingInhibited();
	virtual int GetNumRenderWorlds();
	virtual idRenderWorld * RenderWorldForIndex( int index );
	virtual int GetNextRenderView( idRenderWorld * world );
	virtual int GetNumMonitors();
	virtual void GetMonitorSize( int monitor, int * width, int * height );
	virtual int GetCurrentMonitor();
	virtual bool GPUTranscodeAvailable();
	virtual void EnableGPUTranscode( bool enable );
	virtual bool GPUTranscodeIsEnabled();
	virtual bool SwapTearAvailable();
	virtual void ClearOutOfMemory();
	virtual bool CheckOutOfMemory();
	virtual void * GetGameWindow();
	virtual void Restart();
	virtual void SwapBuffers( void * window, bool sync );
	virtual void SetBlackLevel( float level );
	virtual void SetGamma( unsigned short * red, unsigned short * green,
		unsigned short * blue );
	virtual bool MakeCurrent( void * window );
	virtual int GetWidth();
	virtual int GetHeight();
	virtual float GetPixelAspect();
	virtual float GetScreenAspect();
	virtual int GetScanoutWidth();
	virtual int GetScanoutHeight();
	virtual stereoRenderMode_t GetStereoRenderMode();
	virtual int GetNumMultisamples();
	virtual int GetMaxSupportedMultisamples();
	virtual bool IgnoreSizeMessages();
	virtual void WindowSizeDragged( int width, int height );
	virtual bool WindowChangeMultisamples( int samples );
	virtual bool EnumerateModes( int mode, int * width, int * height,
		int * refreshRate );
	virtual void ( __fastcall * ExtensionPointer( const char * name ) )();
	virtual void SetPixelFormat( void * window );
	virtual void ShowGameWindow();
	virtual void HideGameWindow();
	virtual bool IsFullscreen();
	virtual void GoWindowed();
	virtual void GoFullScreen();
	virtual void SetStudioMode( bool enabled );
};

extern idRenderSystem * renderSystem;

