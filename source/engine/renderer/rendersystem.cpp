#include "rendersystem_local.h"

#include "coderenderparm.h"
#include "declmaterial.h"
#include "declrenderparm.h"
#include "declrenderprog.h"
#include "imagemanager.h"
#include "image.h"
#include "render.h"
#include "renderdestination.h"
#include "renderview.h"
#include "renderworld_local.h"
#include "triangles.h"
#include "jobs/render/parmstate.h"

#include <algorithm>
#include <cstring>

namespace {
	const idDeclRenderProg * LoadProgram( const char * name ) {
		return static_cast< const idDeclRenderProg * >(
			idDeclRenderProg::resourceList.Load( name, true ) );
	}

	void SetupDrawVert( idDrawVert & vert, const idVec3 & xyz,
			float s, float t ) {
		vert.xyz = xyz;
		vert.st.Set( s, t );
		vert.SetNormal( idVec3( 0.0f, 0.0f, 1.0f ) );
		vert.SetTangent( idVec3( 1.0f, 0.0f, 0.0f ) );
		vert.SetBiTangent( idVec3( 0.0f, 1.0f, 0.0f ) );
		vert.color[0] = vert.color[1] = vert.color[2] = vert.color[3] = 255;
	}

	idTriangles * CreateUnitSquare() {
		idTriangles * const triangles = new idTriangles();
		R_InitTriangles( *triangles );
		triangles->numVerts = 4;
		triangles->numIndexes = 6;
		R_AllocTriangleVerts( *triangles, triangles->numVerts );
		R_AllocTriangleIndexes( *triangles, triangles->numIndexes );
		SetupDrawVert( triangles->verts[0], idVec3( -1.0f, -1.0f, 0.0f ), 0.0f, 1.0f );
		SetupDrawVert( triangles->verts[1], idVec3(  1.0f, -1.0f, 0.0f ), 1.0f, 1.0f );
		SetupDrawVert( triangles->verts[2], idVec3(  1.0f,  1.0f, 0.0f ), 1.0f, 0.0f );
		SetupDrawVert( triangles->verts[3], idVec3( -1.0f,  1.0f, 0.0f ), 0.0f, 0.0f );
		const unsigned short indexes[6] = { 0, 1, 2, 0, 2, 3 };
		std::memcpy( triangles->indexes, indexes, sizeof( indexes ) );
		triangles->bounds[0].Set( -1.0f, -1.0f, 0.0f );
		triangles->bounds[1].Set( 1.0f, 1.0f, 0.0f );
		return triangles;
	}

	idTriangles * CreateCube( float minimum, float maximum ) {
		idTriangles * const triangles = new idTriangles();
		R_InitTriangles( *triangles );
		triangles->numVerts = 8;
		triangles->numIndexes = 36;
		R_AllocTriangleVerts( *triangles, triangles->numVerts );
		R_AllocTriangleIndexes( *triangles, triangles->numIndexes );
		for ( int corner = 0; corner < 8; ++corner ) {
			SetupDrawVert( triangles->verts[corner], idVec3(
				( corner & 1 ) != 0 ? maximum : minimum,
				( corner & 2 ) != 0 ? maximum : minimum,
				( corner & 4 ) != 0 ? maximum : minimum ),
				( corner & 1 ) != 0 ? 1.0f : 0.0f,
				( corner & 2 ) != 0 ? 1.0f : 0.0f );
		}
		const unsigned short indexes[36] = {
			0, 2, 3, 0, 3, 1, 4, 5, 7, 4, 7, 6,
			0, 1, 5, 0, 5, 4, 2, 6, 7, 2, 7, 3,
			0, 4, 6, 0, 6, 2, 1, 3, 7, 1, 7, 5 };
		std::memcpy( triangles->indexes, indexes, sizeof( indexes ) );
		triangles->bounds[0].Set( minimum, minimum, minimum );
		triangles->bounds[1].Set( maximum, maximum, maximum );
		return triangles;
	}

	idImage * CreateRenderImage( const char * name, int width, int height,
			textureFormat_t format, int levels = 1,
			textureType_t type = TT_2D ) {
		idImage * const image = globalImages->AllocImage( name );
		if ( image == nullptr ) return nullptr;
		idImageOpts opts;
		opts.textureType = type;
		opts.width = std::max( width, 1 );
		opts.height = std::max( height, 1 );
		opts.depth = 1;
		opts.numLevels = levels;
		opts.format = format;
		opts.filter = levels == 1 ? TF_LINEAR : TF_TRILINEAR_NO_ANISO;
		opts.repeat = TR_CLAMP;
		return image->AllocRenderTarget( opts ) ? image : nullptr;
	}

	void DestroyTriangles( idTriangles *& triangles ) {
		if ( triangles == nullptr ) return;
		R_FreeTriangleData( *triangles );
		delete triangles;
		triangles = nullptr;
	}
}

// Pointer-only bridge implemented by renderworld.cpp; see renderworld.h.
idRenderWorld * R_CreateRenderWorld( const char *, bool );
void R_DestroyRenderWorld( idRenderWorld * );
idRenderWorld * R_GetNextRenderWorld( idRenderWorld * );
void R_SetNextRenderWorld( idRenderWorld *, idRenderWorld * );

idRenderSystem::~idRenderSystem() {}
void idRenderSystem::Init() {}
void idRenderSystem::Init2() {}
void idRenderSystem::Shutdown() {}
idRenderWorld * idRenderSystem::AllocRenderWorld( const char *, bool ) { return nullptr; }
void idRenderSystem::RenderFrame( void *, const idRenderFrameInfo *, bool, bool, bool ) {}
void idRenderSystem::EndFrame( void *, int, int, idRenderWorld *, idRenderModel **,
	int, bool, bool, bool, int ) {}
void idRenderSystem::ToolEndFrame( void *, int, int, idRenderWorld *,
	const renderView_t *, idRenderModel *, int ) {}
int idRenderSystem::FrameNumber() { return 0; }
bool idRenderSystem::SyncRenderThread( bool ) { return true; }
void idRenderSystem::BeginBinkVideo( void *, const char *, videoFlags_t, idRenderVideoOverlay * ) {}
bool idRenderSystem::BinkVideoIsLoaded() { return false; }
bool idRenderSystem::BinkVideoIsPlaying() { return false; }
void idRenderSystem::FreeBinkVideo() {}
void idRenderSystem::AllowBackgroundSwaps( bool ) {}
void idRenderSystem::BeginAutomaticBackgroundSwaps( void *, bool ) {}
void idRenderSystem::EndAutomaticBackgroundSwaps() {}
void idRenderSystem::SetLoadingIconInfo( float, float, float, float ) {}
void idRenderSystem::RegenerateReferences() {}
void idRenderSystem::InhibitEndFrameRendering( int ) {}
bool idRenderSystem::IsEndFrameRenderingInhibited() { return false; }
int idRenderSystem::GetNumRenderWorlds() { return 0; }
idRenderWorld * idRenderSystem::RenderWorldForIndex( int ) { return nullptr; }
int idRenderSystem::GetNextRenderView( idRenderWorld * ) { return 0; }
int idRenderSystem::GetNumMonitors() { return 1; }
void idRenderSystem::GetMonitorSize( int, int * w, int * h ) { if ( w ) *w = 0; if ( h ) *h = 0; }
int idRenderSystem::GetCurrentMonitor() { return 0; }
bool idRenderSystem::GPUTranscodeAvailable() { return false; }
void idRenderSystem::EnableGPUTranscode( bool ) {}
bool idRenderSystem::GPUTranscodeIsEnabled() { return false; }
bool idRenderSystem::SwapTearAvailable() { return false; }
void idRenderSystem::ClearOutOfMemory() {}
bool idRenderSystem::CheckOutOfMemory() { return false; }
void * idRenderSystem::GetGameWindow() { return nullptr; }
void idRenderSystem::Restart() {}
void idRenderSystem::SwapBuffers( void *, bool ) {}
void idRenderSystem::SetBlackLevel( float ) {}
void idRenderSystem::SetGamma( unsigned short *, unsigned short *, unsigned short * ) {}
bool idRenderSystem::MakeCurrent( void * ) { return true; }
int idRenderSystem::GetWidth() { return 0; }
int idRenderSystem::GetHeight() { return 0; }
float idRenderSystem::GetPixelAspect() { return 1.0f; }
float idRenderSystem::GetScreenAspect() { return 1.0f; }
int idRenderSystem::GetScanoutWidth() { return GetWidth(); }
int idRenderSystem::GetScanoutHeight() { return GetHeight(); }
stereoRenderMode_t idRenderSystem::GetStereoRenderMode() { return STEREO_RENDER_OFF; }
int idRenderSystem::GetNumMultisamples() { return 0; }
int idRenderSystem::GetMaxSupportedMultisamples() { return 0; }
bool idRenderSystem::IgnoreSizeMessages() { return false; }
void idRenderSystem::WindowSizeDragged( int, int ) {}
bool idRenderSystem::WindowChangeMultisamples( int ) { return false; }
bool idRenderSystem::EnumerateModes( int, int *, int *, int * ) { return false; }
void ( __fastcall * idRenderSystem::ExtensionPointer( const char * ) )() { return nullptr; }
void idRenderSystem::SetPixelFormat( void * ) {}
void idRenderSystem::ShowGameWindow() {}
void idRenderSystem::HideGameWindow() {}
bool idRenderSystem::IsFullscreen() { return false; }
void idRenderSystem::GoWindowed() {}
void idRenderSystem::GoFullScreen() {}
void idRenderSystem::SetStudioMode( bool ) {}

idRenderSystemLocal renderSystemLocal;
idRenderSystem * renderSystem = &renderSystemLocal;

idRenderSystemLocal::idRenderSystemLocal() : insideEndFrame( false ),
	automaticBackgroundSwapsEnabled( false ), renderLoadingIcon( false ),
	renderingIsReadyForSwapbuffers( false ), allowBackgroundSwaps( false ),
	renderSynced( true ), frameCount( 0 ), inhibitRendering( 0 ), loadingIconPosX( 0.0f ),
	loadingIconPosY( 0.0f ), loadingIconScale( 1.0f ), loadingIconSpeed( 1.0f ),
	worlds( nullptr ), primaryWorld( nullptr ), performanceCounterLogWorld( nullptr ),
	performanceCounterLogWorldFrame( 0 ), testWorld( nullptr ), testImage( nullptr ),
	testCubeImage( nullptr ), testMaterial( nullptr ), videoOverlay( nullptr ),
	mtrDefault( nullptr ), progDepthOnly( nullptr ), progColorOnly( nullptr ),
	progWireFrame( nullptr ), progTextureOnly( nullptr ), progCubeImageOnly( nullptr ),
	progBasicBlend( nullptr ), progOccluderDepthOnly( nullptr ),
	progDeferredPointLight( nullptr ), progDeferredSpotLight( nullptr ),
	progDeferredParallelLight( nullptr ), progGlobalFog( nullptr ),
	progPostProcess( nullptr ), rpFrameNumber( nullptr ), rpViewColor( nullptr ),
	declHighlightTable( nullptr ), defaultCubeModel( nullptr ), unitSquareTris( nullptr ),
	unitCubeTris( nullptr ), zeroOneCubeTris( nullptr ), extrudeBoxTris( nullptr ),
	renderDestViewDepth( nullptr ), renderDestGui( nullptr ),
	renderDestDefault( nullptr ), windowWidth( 1280 ),
	windowHeight( 720 ), renderWidth( 1280 ), renderHeight( 720 ), currentRenderView( nullptr ),
	updateGammaTable( false ), drawsMetric( "renderer_draws" ),
	trisMetric( "renderer_triangles" ), vertsMetric( "renderer_vertices" ),
	renderThread( nullptr ), gpuTranscodeEnabled( false ), outOfMemory( false ),
	studioMode( false ), binkLoaded( false ), binkPlaying( false ), multisamples( 0 ) {
	std::memset( &pc, 0, sizeof( pc ) );
	std::memset( imgViewColor, 0, sizeof( imgViewColor ) );
	std::memset( imgColorGradingLUT, 0, sizeof( imgColorGradingLUT ) );
	std::memset( imgDistortion, 0, sizeof( imgDistortion ) );
	std::memset( imgDynamicEnvironment, 0, sizeof( imgDynamicEnvironment ) );
	imgViewDepth = imgGui = nullptr;
	std::memset( renderDestViewColor, 0, sizeof( renderDestViewColor ) );
	std::memset( renderDestDistortion, 0, sizeof( renderDestDistortion ) );
	std::memset( gammaTable, 0, sizeof( gammaTable ) );
	blackLevel[0] = blackLevel[1] = 0.0f;
}

idRenderSystemLocal::~idRenderSystemLocal() { Shutdown(); }

void idRenderSystemLocal::Init() {
	InitContext();
	if ( rendererD3D9.IsInitialized() ) {
		wrapperContext_t context;
		context.d3d = rendererD3D9.GetDevice();
		GL_SetWrapperContext( context );
		GL_SetDefaultState();
		globalImages->Init();
		idCodeRenderParm::ResolveIRenderParmResources();
		renderThreadParmState->Init();
		mtrDefault = static_cast< const idMaterial * >(
			idMaterial::resourceList.Load( "_default", true ) );
		progDepthOnly = static_cast< const idDeclRenderProg * >(
			idDeclRenderProg::resourceList.Load( "depthOnly", true ) );
		progColorOnly = static_cast< const idDeclRenderProg * >(
			idDeclRenderProg::resourceList.Load( "colorOnly", true ) );
		progTextureOnly = static_cast< const idDeclRenderProg * >(
			idDeclRenderProg::resourceList.Load( "textureOnly", true ) );
		progBasicBlend = LoadProgram( "basicBlend" );
		progOccluderDepthOnly = LoadProgram( "occluderDepthOnly" );
		progDeferredPointLight = LoadProgram( "deferredPointLight" );
		progDeferredSpotLight = LoadProgram( "deferredSpotLight" );
		progDeferredParallelLight = LoadProgram( "deferredParallelLight" );
		progGlobalFog = LoadProgram( "globalFog" );
		progPostProcess = LoadProgram( "postProcess" );
		rpFrameNumber = idDeclRenderParm::FindByName( "frameNumber", true );
		rpViewColor = idDeclRenderParm::FindByName( "viewColor", true );

		unitSquareTris = CreateUnitSquare();
		unitCubeTris = CreateCube( -1.0f, 1.0f );
		zeroOneCubeTris = CreateCube( 0.0f, 1.0f );
		extrudeBoxTris = CreateCube( -1.0f, 1.0f );

		InitRenderTargets();
	}
}

void idRenderSystemLocal::InitRenderTargets() {
	if ( globalImages == nullptr || !rendererD3D9.IsInitialized() ) return;
	if ( renderDestDefault == nullptr ) renderDestDefault = new idRenderDestination();
	renderDestDefault->isDefault = true;
	renderDestDefault->targetWidth = renderWidth;
	renderDestDefault->targetHeight = renderHeight;
	for ( int index = 0; index < 2; ++index ) {
		const char * const viewName = index == 0 ? "_viewColor0" : "_viewColor1";
		const char * const distortionName = index == 0 ? "_distortion0" : "_distortion1";
		imgViewColor[index] = CreateRenderImage( viewName, renderWidth,
			renderHeight, FMT_ARGB8, 0 );
		imgDistortion[index] = CreateRenderImage( distortionName,
			std::max( renderWidth / 4, 1 ), std::max( renderHeight / 4, 1 ),
			FMT_ARGB8 );
		if ( renderDestViewColor[index] == nullptr ) renderDestViewColor[index] = new idRenderDestination();
		renderDestViewColor[index]->CreateFromImages( imgViewColor[index], nullptr, nullptr );
		if ( renderDestDistortion[index] == nullptr ) renderDestDistortion[index] = new idRenderDestination();
		renderDestDistortion[index]->CreateFromImages( imgDistortion[index], nullptr, nullptr );
	}
	imgViewDepth = CreateRenderImage( "_viewDepth", renderWidth, renderHeight,
		FMT_X32F );
	if ( renderDestViewDepth == nullptr ) renderDestViewDepth = new idRenderDestination();
	renderDestViewDepth->CreateFromImages( imgViewDepth, nullptr, nullptr );
	imgGui = CreateRenderImage( "_guiRender", 512, 512, FMT_ARGB8, 0 );
	if ( renderDestGui == nullptr ) renderDestGui = new idRenderDestination();
	renderDestGui->CreateFromImages( imgGui, nullptr, nullptr );
}

void idRenderSystemLocal::PurgeRenderTargets() {
	for ( int index = 0; index < 2; ++index ) {
		if ( renderDestViewColor[index] != nullptr ) renderDestViewColor[index]->ReleaseSurfaces();
		if ( renderDestDistortion[index] != nullptr ) renderDestDistortion[index]->ReleaseSurfaces();
		if ( imgViewColor[index] != nullptr ) imgViewColor[index]->PurgeImage();
		if ( imgDistortion[index] != nullptr ) imgDistortion[index]->PurgeImage();
	}
	if ( renderDestViewDepth != nullptr ) renderDestViewDepth->ReleaseSurfaces();
	if ( renderDestGui != nullptr ) renderDestGui->ReleaseSurfaces();
	if ( imgViewDepth != nullptr ) imgViewDepth->PurgeImage();
	if ( imgGui != nullptr ) imgGui->PurgeImage();
}

bool idRenderSystemLocal::ResetContext( const int width, const int height,
		const bool fullscreen, const int samples ) {
	if ( !rendererD3D9.IsInitialized() || width <= 0 || height <= 0 ) return false;
	if ( rendererD3D9.IsSceneActive() ) GL_EndFrame();
	PurgeRenderTargets();
	if ( !rendererD3D9.Reset( width, height, fullscreen, samples, true ) ) {
		outOfMemory = true;
		return false;
	}
	windowWidth = renderWidth = rendererD3D9.Width();
	windowHeight = renderHeight = rendererD3D9.Height();
	multisamples = rendererD3D9.Multisamples();
	InitRenderTargets();
	GL_SetDefaultState();
	return true;
}

void idRenderSystemLocal::Init2() {
	if ( !rendererD3D9.IsInitialized() ) Init();
}
void idRenderSystemLocal::Shutdown() {
	while ( worlds != nullptr ) {
		idRenderWorld * const world = reinterpret_cast< idRenderWorld * >( worlds );
		worlds = reinterpret_cast< idRenderWorldLocal * >(
			R_GetNextRenderWorld( world ) );
		R_DestroyRenderWorld( world );
	}
	primaryWorld = nullptr;
	delete renderDestDefault;
	renderDestDefault = nullptr;
	for ( int index = 0; index < 2; ++index ) {
		delete renderDestViewColor[index];
		renderDestViewColor[index] = nullptr;
		delete renderDestDistortion[index];
		renderDestDistortion[index] = nullptr;
		if ( imgViewColor[index] != nullptr ) imgViewColor[index]->PurgeImage();
		if ( imgDistortion[index] != nullptr ) imgDistortion[index]->PurgeImage();
		imgViewColor[index] = nullptr;
		imgDistortion[index] = nullptr;
	}
	delete renderDestViewDepth;
	renderDestViewDepth = nullptr;
	delete renderDestGui;
	renderDestGui = nullptr;
	if ( imgViewDepth != nullptr ) imgViewDepth->PurgeImage();
	if ( imgGui != nullptr ) imgGui->PurgeImage();
	imgViewDepth = imgGui = nullptr;
	DestroyTriangles( unitSquareTris );
	DestroyTriangles( unitCubeTris );
	DestroyTriangles( zeroOneCubeTris );
	DestroyTriangles( extrudeBoxTris );
	if ( globalImages != nullptr ) globalImages->Shutdown();
	rendererD3D9.Shutdown();
	renderingIsReadyForSwapbuffers = false;
}
void idRenderSystemLocal::RenderFrame( void *, const idRenderFrameInfo * info,
	bool, bool, bool ) {
	if ( info != nullptr ) currentRenderFrameInfo = *info;
	if ( inhibitRendering != 0 ) return;
	if ( !rendererD3D9.EnsureReady() && rendererD3D9.IsDeviceLost() )
		ResetContext( windowWidth, windowHeight, IsFullscreen(), multisamples );
	if ( !rendererD3D9.EnsureReady() ) return;
	GL_StartFrame( frameCount );
}
void idRenderSystemLocal::EndFrame( void * window, int width, int height,
	idRenderWorld * world, idRenderModel ** models, int numModels, bool,
	bool, bool allowSwap, int ) {
	insideEndFrame = true;
	const int requestedWidth = width > 0 ? width : windowWidth;
	const int requestedHeight = height > 0 ? height : windowHeight;
	if ( requestedWidth != rendererD3D9.Width() || requestedHeight != rendererD3D9.Height() )
		ResetContext( requestedWidth, requestedHeight, IsFullscreen(), multisamples );
	windowWidth = requestedWidth;
	windowHeight = requestedHeight;
	renderWidth = rendererD3D9.Width();
	renderHeight = rendererD3D9.Height();
	if ( inhibitRendering == 0 && rendererD3D9.EnsureReady() ) {
		if ( !rendererD3D9.IsSceneActive() ) GL_StartFrame( frameCount );
		for ( int index = 0; index < numModels; ++index ) {
			if ( models != nullptr && models[index] != nullptr )
				models[index]->Commit();
		}
		idRenderWorldLocal * const localWorld =
			static_cast< idRenderWorldLocal * >( world );
		if ( localWorld != nullptr ) {
			primaryWorld = localWorld;
			if ( localWorld->renderViews.Num() == 0 )
				localWorld->SetNumRenderViews( 1 );
			currentRenderView = localWorld->RenderViewForIndex( 0 );
			if ( currentRenderView != nullptr )
				renderState.RenderSingleView( localWorld, currentRenderView );
		}
	}
	GL_EndFrame();
	const wrapperStats_t stats = GL_GetCurrentStats();
	drawsMetric.Log( static_cast< float >( stats.c_drawElements ) );
	trisMetric.Log( static_cast< float >( stats.c_drawIndices / 3 ) );
	vertsMetric.Log( static_cast< float >( stats.c_drawVertices ) );
	if ( allowSwap && inhibitRendering == 0 ) SwapBuffers( window, true );
	++frameCount;
	insideEndFrame = false;
}
void idRenderSystemLocal::ToolEndFrame( void * window, int width, int height,
	idRenderWorld * world, const renderView_t * view, idRenderModel * model, int flags ) {
	if ( world != nullptr && view != nullptr ) {
		idRenderWorldLocal * const localWorld =
			static_cast< idRenderWorldLocal * >( world );
		if ( localWorld->renderViews.Num() == 0 ) localWorld->SetNumRenderViews( 1 );
		idRenderView * const renderView = localWorld->RenderViewForIndex( 0 );
		if ( renderView != nullptr ) renderView->g = *view;
	}
	idRenderModel * models[1] = { model };
	EndFrame( window, width, height, world, models, model != nullptr ? 1 : 0,
		false, false, true, flags );
}
int idRenderSystemLocal::FrameNumber() { return frameCount; }
bool idRenderSystemLocal::SyncRenderThread( bool ) { GL_Finish(); renderSynced = true; return true; }
void idRenderSystemLocal::BeginBinkVideo( void *, const char *, videoFlags_t flags,
	idRenderVideoOverlay * overlay ) { videoOverlay = overlay; binkLoaded = true; binkPlaying = flags != VIDEO_EXIT; }
bool idRenderSystemLocal::BinkVideoIsLoaded() { return binkLoaded; }
bool idRenderSystemLocal::BinkVideoIsPlaying() { return binkPlaying; }
void idRenderSystemLocal::FreeBinkVideo() { binkLoaded = binkPlaying = false; videoOverlay = nullptr; }
void idRenderSystemLocal::AllowBackgroundSwaps( bool allow ) { allowBackgroundSwaps = allow; }
void idRenderSystemLocal::BeginAutomaticBackgroundSwaps( void *, bool loading ) { automaticBackgroundSwapsEnabled = true; renderLoadingIcon = loading; }
void idRenderSystemLocal::EndAutomaticBackgroundSwaps() { automaticBackgroundSwapsEnabled = false; }
void idRenderSystemLocal::SetLoadingIconInfo( float x, float y, float scale, float speed ) { loadingIconPosX=x; loadingIconPosY=y; loadingIconScale=scale; loadingIconSpeed=speed; }
void idRenderSystemLocal::RegenerateReferences() {}
void idRenderSystemLocal::InhibitEndFrameRendering( int change ) {
	inhibitRendering = change <= -inhibitRendering ? 0 : inhibitRendering + change;
}
bool idRenderSystemLocal::IsEndFrameRenderingInhibited() { return inhibitRendering != 0; }
idRenderWorld * idRenderSystemLocal::AllocRenderWorld( const char * name,
		const bool comboMap ) {
	idRenderWorld * const world = R_CreateRenderWorld( name, comboMap );
	if ( world == nullptr ) return nullptr;
	R_SetNextRenderWorld( world,
		reinterpret_cast< idRenderWorld * >( worlds ) );
	worlds = reinterpret_cast< idRenderWorldLocal * >( world );
	if ( primaryWorld == nullptr )
		primaryWorld = reinterpret_cast< idRenderWorldLocal * >( world );
	return world;
}
int idRenderSystemLocal::GetNumRenderWorlds() {
	int count = 0;
	for ( idRenderWorld * world = reinterpret_cast< idRenderWorld * >( worlds );
			world != nullptr; world = R_GetNextRenderWorld( world ) ) ++count;
	return count;
}
idRenderWorld * idRenderSystemLocal::RenderWorldForIndex( int index ) {
	if ( index < 0 ) return nullptr;
	idRenderWorld * world = reinterpret_cast< idRenderWorld * >( worlds );
	while ( world != nullptr && index-- > 0 ) world = R_GetNextRenderWorld( world );
	return world;
}
int idRenderSystemLocal::GetNextRenderView( idRenderWorld * ) { return frameCount; }
bool idRenderSystemLocal::GPUTranscodeAvailable() { return false; }
void idRenderSystemLocal::EnableGPUTranscode( bool enable ) { gpuTranscodeEnabled = enable && GPUTranscodeAvailable(); }
bool idRenderSystemLocal::GPUTranscodeIsEnabled() { return gpuTranscodeEnabled; }
bool idRenderSystemLocal::SwapTearAvailable() { return false; }
void idRenderSystemLocal::ClearOutOfMemory() { outOfMemory = false; }
bool idRenderSystemLocal::CheckOutOfMemory() { return outOfMemory; }
void idRenderSystemLocal::Restart() { ResetContext( windowWidth, windowHeight, IsFullscreen(), multisamples ); }
void idRenderSystemLocal::SetBlackLevel( float level ) { blackLevel[0] = blackLevel[1] = level; }
bool idRenderSystemLocal::MakeCurrent( void * ) { return rendererD3D9.IsInitialized(); }
int idRenderSystemLocal::GetWidth() { return rendererD3D9.Width(); }
int idRenderSystemLocal::GetScanoutWidth() { return rendererD3D9.Width(); }
int idRenderSystemLocal::GetScanoutHeight() { return rendererD3D9.Height(); }
float idRenderSystemLocal::GetScreenAspect() { return GetHeight() > 0 ? static_cast<float>(GetWidth()) / GetHeight() : 1.0f; }
int idRenderSystemLocal::GetNumMultisamples() { return rendererD3D9.Multisamples(); }
int idRenderSystemLocal::GetMaxSupportedMultisamples() { return rendererD3D9.MaxSupportedMultisamples(); }
bool idRenderSystemLocal::IgnoreSizeMessages() { return insideEndFrame; }
void idRenderSystemLocal::WindowSizeDragged( int width, int height ) { if ( width > 0 && height > 0 ) ResetContext( width, height, IsFullscreen(), multisamples ); }
bool idRenderSystemLocal::WindowChangeMultisamples( int samples ) { return ResetContext( GetWidth(), GetHeight(), IsFullscreen(), samples ); }
void ( __fastcall * idRenderSystemLocal::ExtensionPointer( const char * ) )() { return nullptr; }
void idRenderSystemLocal::SetPixelFormat( void * ) {}
void idRenderSystemLocal::SetStudioMode( bool enabled ) { studioMode = enabled; }
