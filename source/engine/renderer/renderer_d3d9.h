#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>
// The recovered shared math headers retain an ABI-only `_D3DMATRIX` tag.
// Rename the private D3D9 tag while including the SDK so renderer jobs may
// include both native D3D9 declarations and idRenderMatrix in either order.
#define _D3DMATRIX _D3DMATRIX_D3D9_NATIVE
#define D3DMATRIX D3DMATRIX_D3D9_NATIVE
#include <d3d9.h>
#undef D3DMATRIX
#undef _D3DMATRIX
#include <d3dcompiler.h>
#include <array>
#include <cstdint>

#include "renderer_types.h"

template< typename T >
inline void D3D9Release( T *& object ) {
	if ( object != nullptr ) {
		object->Release();
		object = nullptr;
	}
}

struct wrapperContext_t {
	wrapperContext_t();
	IDirect3DDevice9 * d3d;
	IDirect3DQuery9 * occlusionQueryBatch[16];
};

struct idD3D9Mode {
	int width;
	int height;
	int refreshRate;
	D3DFORMAT format;
};

class idD3D9Renderer {
public:
	idD3D9Renderer();
	~idD3D9Renderer();

	bool Initialize( HWND window, int width, int height, bool fullscreen,
		int multisamples, bool vsync );
	void Shutdown();
	bool Reset( int width, int height, bool fullscreen, int multisamples,
		bool vsync );
	bool EnsureReady();
	bool Present();
	void BeginScene();
	void EndScene();

	IDirect3D9 * GetD3D() const { return d3d; }
	IDirect3DDevice9 * GetDevice() const { return device; }
	const D3DPRESENT_PARAMETERS & GetPresentParameters() const { return presentParameters; }
	HWND GetWindow() const { return window; }
	bool IsInitialized() const { return device != nullptr; }
	bool IsDeviceLost() const { return deviceLost; }
	bool IsSceneActive() const { return sceneActive; }

	int Width() const { return static_cast< int >( presentParameters.BackBufferWidth ); }
	int Height() const { return static_cast< int >( presentParameters.BackBufferHeight ); }
	bool IsFullscreen() const { return presentParameters.Windowed == FALSE; }
	int Multisamples() const;
	int MaxSupportedMultisamples() const;
	float PixelAspect() const;

	bool EnumerateModes( std::array< idD3D9Mode, 256 > & modes, int & count ) const;
	D3DFORMAT BackBufferFormat() const { return presentParameters.BackBufferFormat; }
	D3DFORMAT DepthStencilFormat() const { return presentParameters.AutoDepthStencilFormat; }
	D3DCAPS9 Caps() const { return caps; }

private:
	bool CreateDevice();
	void BuildPresentParameters( int width, int height, bool fullscreen,
		int multisamples, bool vsync );
	D3DMULTISAMPLE_TYPE ChooseMultisampleType( int requested ) const;
	bool FindDepthStencilFormat( D3DFORMAT adapterFormat,
		D3DFORMAT backBufferFormat, D3DFORMAT & result ) const;

	IDirect3D9 * d3d;
	IDirect3DDevice9 * device;
	HWND window;
	D3DPRESENT_PARAMETERS presentParameters;
	D3DCAPS9 caps;
	D3DDEVTYPE deviceType;
	DWORD behaviorFlags;
	bool deviceLost;
	bool sceneActive;
};

extern idD3D9Renderer rendererD3D9;

class idImage;
class idDeclRenderProg;
class idRenderDestination;
class idRenderModelSurface;
class idTriangles;

void GL_SetWrapperContext( const wrapperContext_t & context );
void GL_SetWrapperConfig( const wrapperConfig_t & config );
void GL_StartFrame( int frame );
void GL_EndFrame();
void GL_WaitForEndFrame();
void GL_GetLastFrameTime( std::uint64_t & startGPUTimeMicroSec,
	std::uint64_t & endGPUTimeMicroSec );
void GL_Flush();
void GL_Finish();
void GL_State( glStateBits_t stateBits, bool forceGlState = false );
void GL_Scissor( int x, int y, int width, int height );
void GL_Viewport( int x, int y, int width, int height );
void GL_Clear( bool color, bool depth, bool stencil, unsigned char stencilValue,
	float red, float green, float blue, float alpha );
void GL_PolygonOffset( float scale, float bias, bool fill );
std::int64_t GL_GetCurrentQueryNumber();
void GL_CacheOcclusionQueryBatches( std::int64_t upToIncludingBatchNum );
void GL_BeginQueryBatch();
void GL_BeginQuery( std::int64_t * queryNumber );
void GL_EndQuery();
int GL_GetDeferredQueryResult( std::int64_t queryNumber );
void GL_ResetProgramState();
void GL_ResetTextureState();
wrapperStats_t GL_GetCurrentStats();
void GL_ClearStats();
void GL_SetDefaultState();
void GL_SetRenderDestination( const idRenderDestination * destination,
	int face = 0, int mipLevel = 0 );
void GL_ResolveTarget( resolveTarget_t target,
	const idRenderDestination * destination );
void GL_ResolveTarget( resolveTarget_t target,
	const idRenderDestination * destination, int sourceX, int sourceY,
	int destinationX, int destinationY, int width, int height );
void GL_BindTexture( const idImage * image, int unit );
void GL_BindProgram( const idDeclRenderProg * program,
	glStateBits_t extraState, unsigned int vertexMask );
void GL_DrawElements( const idDeclRenderProg * program,
	const idRenderModelSurface * surface, glStateBits_t extraState,
	bool forceState = false );
void GL_DrawElements( const idDeclRenderProg * program,
	const idTriangles * triangles, glStateBits_t extraState,
	bool forceState = false );
