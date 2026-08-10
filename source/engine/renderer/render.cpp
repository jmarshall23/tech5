#include "render.h"

#include "declrenderparm.h"
#include "image.h"
#include "imagemanager.h"
#include "renderdestination.h"
#include "renderlightparms.h"
#include "rendersystem_local.h"
#include "renderview.h"
#include "renderworld_local.h"
#include "jobs/render/parmstate.h"
#include "jobs/render/rendercapture.h"
#include "jobs/render/rendercull.h"
#include "jobs/render/renderdepth.h"
#include "jobs/render/renderfog.h"
#include "jobs/render/rendergather.h"
#include "jobs/render/renderocclusion.h"
#include "jobs/render/renderpasses.h"
#include "jobs/render/renderpostprocess.h"
#include "jobs/render/rendersort.h"
#include "jobs/render/renderwalkbsp.h"

#include <algorithm>
#include <cstring>

void SetupModelMVPMatrix( idRenderMatrix & mvpMatrix,
	const idRenderModelCommitted * model, const idRenderView * renderView,
	float zNear, float zFar );

namespace {
	const idDeclRenderParm * Parm( const char * name ) {
		return idDeclRenderParm::FindByName( name, true );
	}

	void SetupVisibleModelMVPs( idRender & render, idRenderView * view ) {
		for ( int index = 0; index < render.numViewModels; ++index ) {
			idRenderModelCommitted * const model =
				const_cast< idRenderModelCommitted * >( render.viewModels[index] );
			if ( model != nullptr ) SetupModelMVPMatrix( model->mvpMatrix, model,
				view, render.settings.viewNearZ, render.settings.viewFarZ );
		}
		for ( int index = 0; index < render.numSceneModels; ++index ) {
			idRenderModelCommitted * const model =
				const_cast< idRenderModelCommitted * >( render.sceneModels[index] );
			if ( model != nullptr ) SetupModelMVPMatrix( model->mvpMatrix, model,
				view, render.settings.viewNearZ, render.settings.viewFarZ );
		}
		for ( int index = 0; index < render.numViewAugmentModels; ++index ) {
			idRenderModelCommitted * const model = const_cast< idRenderModelCommitted * >(
				render.viewAugmentModels[index] );
			if ( model != nullptr ) SetupModelMVPMatrix( model->mvpMatrix, model,
				view, render.settings.viewNearZ, render.settings.viewFarZ );
		}
	}
}

renderSettings_t::renderSettings_t() {
	std::memset( this, 0, sizeof( *this ) );
	singleWorldArea = singleLight = singleModel = singleSurface = -1;
	singleGuiSurface = singleDimShadow = -1;
	numViews = 1;
	generateMipMaps = 1;
	queryThreshold = 1;
	dimShadowResolution = 512;
	dimShadowLixelScale = 1.0f;
	dimShadowDensity = 1.0f;
	dimShadowPolyOfsUnits = 1.0f;
	dimShadowPolyOfsFactor = 1.0f;
	dimShadowMaxVisibleRange = 4096.0f;
	dimShadowFadeVisibilityRange = 400.0f;
	useAmbientEnv = true;
	useLightScissors = true;
	useLightDepthBoundsTest = true;
	sortEmit = 10.0f;
	sortEmitOnly = 85.0f;
	sortCoverage = 100.0f;
	sortSkybox = 140.0f;
	sortBackground = 200.0f;
	sortLight = 300.0f;
	sortDecal = 400.0f;
	sortTransSort = 495.0f;
	sortTrans = 500.0f;
	sortWater = 650.0f;
	sortPerturber = 1200.0f;
	sortLast = 10000.0f;
	viewNearZ = 3.0f;
	viewFarZ = 0.0f;
	clearColor.Set( 0.0f, 0.0f, 0.0f );
	viewOrigin.Set( 0.0f, 0.0f, 0.0f, 1.0f );
	viewBounds[0].Zero();
	viewBounds[1].Zero();
	detailBounds = viewBounds;
}

shadowBufferOptions_t::shadowBufferOptions_t() {
	std::memset( this, 0, sizeof( *this ) );
	shadowBufferSize = 1024;
	sliceStep = 1.0f;
	polyOfsFactor = 1.0f;
	polyOfsUnits = 1.0f;
	parallelPolyOfsFactor = 1.0f;
	parallelPolyOfsUnits = 1.0f;
}

idRender renderState;

idRender::idRender() : numNodeWorldAreas( 0 ), numViewWorldAreas( 0 ),
	numViewWorldSurfaces( 0 ), numViewModels( 0 ), numSceneModels( 0 ),
	numViewAugmentModels( 0 ), numViewLights( 0 ), numOcclusionTestNodes( 0 ),
	numOcclusionTestWorldAreas( 0 ), numOcclusionTestModels( 0 ),
	numOcclusionTestLights( 0 ), numDrawSurfs( 0 ), numShadows( 0 ),
	numDimShadows( 0 ), renderViewObject( nullptr ), world( nullptr ),
	screenView( nullptr ) {
	std::memset( temp, 0, sizeof( temp ) );
	std::memset( areaNodeBoundsCulled, 0, sizeof( areaNodeBoundsCulled ) );
	std::memset( worldAreaSubspaceBoundsCulled, 0,
		sizeof( worldAreaSubspaceBoundsCulled ) );
	std::memset( worldAreaGeometryBoundsCulled, 0,
		sizeof( worldAreaGeometryBoundsCulled ) );
	std::memset( nodeWorldAreas, 0, sizeof( nodeWorldAreas ) );
	std::memset( viewWorldAreas, 0, sizeof( viewWorldAreas ) );
	std::memset( viewWorldSurfaces, 0, sizeof( viewWorldSurfaces ) );
	std::memset( viewModels, 0, sizeof( viewModels ) );
	std::memset( sceneModels, 0, sizeof( sceneModels ) );
	std::memset( viewAugmentModels, 0, sizeof( viewAugmentModels ) );
	std::memset( viewLights, 0, sizeof( viewLights ) );
	std::memset( occlusionTestNodes, 0xff, sizeof( occlusionTestNodes ) );
	std::memset( occlusionTestWorldAreas, 0xff,
		sizeof( occlusionTestWorldAreas ) );
	std::memset( occlusionTestModels, 0, sizeof( occlusionTestModels ) );
	std::memset( occlusionTestLights, 0, sizeof( occlusionTestLights ) );
	std::memset( drawSurfs, 0, sizeof( drawSurfs ) );
	std::memset( sortedDrawSurfs, 0, sizeof( sortedDrawSurfs ) );
	std::memset( dimShadowModelSlaves, 0xff, sizeof( dimShadowModelSlaves ) );
	std::memset( modelConsideredAsOccluder, 0,
		sizeof( modelConsideredAsOccluder ) );
	std::memset( modelDimShadowState, 0, sizeof( modelDimShadowState ) );
	for ( int pass = 0; pass < NUM_RENDER_PASSES; ++pass ) {
		renderPasses[pass].firstSurface = 0;
		renderPasses[pass].lastSurface = -1;
	}
	worldSpace.r.isWorld = true;
	worldSpace.r.mvpIsIdentity = true;
	viewSpace.r.mvpIsIdentity = true;
}

void idRender::SetRenderSize( int viewIndex, int width, int height ) {
	viewIndex = std::max( 0, std::min( viewIndex, 1 ) );
	renderSystemLocal.renderWidth = std::max( width, 1 );
	renderSystemLocal.renderHeight = std::max( height, 1 );
	if ( renderSystemLocal.renderDestViewColor[viewIndex] != nullptr )
		renderSystemLocal.renderDestViewColor[viewIndex]->Resize(
			renderSystemLocal.renderWidth, renderSystemLocal.renderHeight );
	if ( renderSystemLocal.renderDestDistortion[viewIndex] != nullptr )
		renderSystemLocal.renderDestDistortion[viewIndex]->Resize(
			std::max( renderSystemLocal.renderWidth / 4, 1 ),
			std::max( renderSystemLocal.renderHeight / 4, 1 ) );
	if ( renderSystemLocal.renderDestDefault != nullptr ) {
		renderSystemLocal.renderDestDefault->targetWidth =
			renderSystemLocal.renderWidth;
		renderSystemLocal.renderDestDefault->targetHeight =
			renderSystemLocal.renderHeight;
	}
}

void idRender::InitSettings( const idRenderWorldLocal * renderWorld,
		const idRenderView * view ) {
	settings = renderSettings_t();
	world = renderWorld;
	renderViewObject = const_cast< idRenderView * >( view );
	settings.isComboMap = renderWorld != nullptr && renderWorld->isComboMap;
	settings.skipPostProcess = view != nullptr && view->r.skipPostProcess;
	settings.skipGodRays = view == nullptr || !view->r.godRaysEnabled;
	settings.clearColor.Set( 0.4f, 0.0f, 0.25f );
	if ( view != nullptr ) {
		settings.viewOrigin.Set( view->r.vieworg.x, view->r.vieworg.y,
			view->r.vieworg.z, 0.0f );
		settings.viewBounds[0] = view->r.vieworg - idVec3( 16.0f, 16.0f, 16.0f );
		settings.viewBounds[1] = view->r.vieworg + idVec3( 16.0f, 16.0f, 16.0f );
		settings.detailBounds[0] = view->r.vieworg -
			idVec3( 8192.0f, 8192.0f, 8192.0f );
		settings.detailBounds[1] = view->r.vieworg +
			idVec3( 8192.0f, 8192.0f, 8192.0f );
	}
}

void idRender::SetupCaptureParms( captureParms_t & parms,
		renderCapture_t capture, bool createMipMaps, int viewIndex ) const {
	std::memset( &parms, 0, sizeof( parms ) );
	parms.capture = capture;
	parms.settings = &settings;
	parms.viewIndex = std::max( 0, std::min( viewIndex, 1 ) );
	if ( renderViewObject != nullptr ) {
		parms.renderWidth = renderViewObject->renderWidth;
		parms.renderHeight = renderViewObject->renderHeight;
		parms.windowWidth = renderViewObject->windowWidth;
		parms.windowHeight = renderViewObject->windowHeight;
		parms.forceFullVirtualTextureLoad =
			renderViewObject->r.forceFullVirtualTextureLoad;
	} else {
		parms.renderWidth = parms.windowWidth = renderSystemLocal.renderWidth;
		parms.renderHeight = parms.windowHeight = renderSystemLocal.renderHeight;
	}
	parms.renderDestDefault = renderSystemLocal.renderDestDefault;
	parms.imgViewDepth = renderSystemLocal.imgViewDepth;
	parms.renderDestViewColor =
		renderSystemLocal.renderDestViewColor[parms.viewIndex];
	parms.renderDestViewDepth = renderSystemLocal.renderDestViewDepth;
	parms.renderDestGui = renderSystemLocal.renderDestGui;
	parms.createMipMaps = createMipMaps;
	parms.rpViewColor = renderSystemLocal.rpViewColor;
	parms.unitSquareTris = renderSystemLocal.unitSquareTris;
	parms.imgBlack = globalImages != nullptr ? globalImages->blackImage : nullptr;
}

void idRender::CaptureToViewColor( int viewIndex ) {
	captureParms_t capture;
	SetupCaptureParms( capture, CAPTURE_VIEW_COLOR, false, viewIndex );
	RenderCapture( &capture );
}

void idRender::RenderSingleView( idRenderWorldLocal * renderWorld,
		idRenderView * view ) {
	if ( renderWorld == nullptr || view == nullptr ||
			renderThreadParmState == nullptr ) return;
	renderWorld->CommitData();
	SetRenderSize( view->viewIndex, renderSystemLocal.renderWidth,
		renderSystemLocal.renderHeight );
	view->CommitParameters( renderSystemLocal.windowWidth,
		renderSystemLocal.windowHeight, renderSystemLocal.renderWidth,
		renderSystemLocal.renderHeight );
	view->imgViewColor = renderSystemLocal.imgViewColor[view->viewIndex];
	InitSettings( renderWorld, view );
	numNodeWorldAreas = numViewWorldAreas = numViewWorldSurfaces = 0;
	numViewModels = numSceneModels = numViewAugmentModels = numViewLights = 0;
	numOcclusionTestNodes = numOcclusionTestWorldAreas = 0;
	numOcclusionTestModels = numOcclusionTestLights = 0;
	numDrawSurfs = numShadows = numDimShadows = 0;

	renderThreadParmState->SetPositionToViewTexture( view->windowWidth,
		view->windowHeight, view->renderWidth, view->renderHeight );
	renderThreadParmState->SetRenderPositionToViewTexture( view->windowWidth,
		view->windowHeight, view->renderWidth, view->renderHeight );
	renderThreadParmState->VirtualEvaluateParmBlock(
		view->r.parmBlock, view->r.parmBlock );

	const int areaNodeCount = std::min( renderWorld->numAreaNodes, 8192 );
	const int worldAreaCount = std::min( renderWorld->numWorldAreas, 8192 );
	renderCullParms_t cull = {};
	cull.settings = &settings;
	cull.renderView = view;
	cull.areaNodeBounds = renderWorld->areaNodeBounds;
	cull.worldAreaSubspaceBounds = renderWorld->worldAreaSubspaceBounds;
	cull.worldAreaGeometryBounds = renderWorld->worldAreaGeometryBounds;
	cull.numAreaNodes = areaNodeCount;
	cull.numWorldAreas = worldAreaCount;
	cull.areaNodeBoundsCulled = areaNodeBoundsCulled;
	cull.worldAreaSubspaceBoundsCulled = worldAreaSubspaceBoundsCulled;
	cull.worldAreaGeometryBoundsCulled = worldAreaGeometryBoundsCulled;
	RenderCull( &cull );

	renderWalkBSPParms_t walk = {};
	walk.settings = &settings;
	walk.renderView = view;
	walk.areaNodeBoundsCulled = areaNodeBoundsCulled;
	walk.areaNodeOcclusionIndex = renderWorld->areaNodeOcclusionIndex;
	walk.areaNodeOcclusionQuery = view->occlusionState != nullptr
		? view->occlusionState->nodeOcclusionQuery : nullptr;
	walk.areaNodeBounds = renderWorld->areaNodeBounds;
	walk.areaNodes = renderWorld->areaNodes;
	walk.numAreaNodes = areaNodeCount;
	walk.numWorldAreas = worldAreaCount;
	walk.occlusionTestNodes = occlusionTestNodes;
	walk.numOcclusionTestNodes = &numOcclusionTestNodes;
	walk.nodeWorldAreas = nodeWorldAreas;
	walk.numNodeWorldAreas = &numNodeWorldAreas;
	RenderWalkBSP( &walk );

	renderGatherParms_t gather = {};
	gather.temp = temp;
	gather.tempSize = sizeof( temp );
	gather.settings = &settings;
	gather.renderView = view;
	gather.linkedRenderModels = renderWorld->linkedRenderModels.Ptr();
	gather.numLinkedRenderModels = renderWorld->linkedRenderModels.Num();
	gather.linkedRenderLights = renderWorld->linkedRenderLights.Ptr();
	gather.numLinkedRenderLights = renderWorld->linkedRenderLights.Num();
	gather.nodeWorldAreas = nodeWorldAreas;
	gather.worldAreaSubspaceBoundsCulled = worldAreaSubspaceBoundsCulled;
	gather.worldAreaGeometryBoundsCulled = worldAreaGeometryBoundsCulled;
	gather.numNodeWorldAreas = numNodeWorldAreas;
	gather.worldAreas = renderWorld->worldAreas;
	gather.numWorldAreas = worldAreaCount;
	gather.addAlwaysModels = renderWorld->addAlwaysModels;
	gather.occlusionState = view->occlusionState;
	gather.occlusionTestNodes = occlusionTestNodes;
	gather.numOcclusionTestNodes = &numOcclusionTestNodes;
	gather.viewWorldAreas = viewWorldAreas;
	gather.numViewWorldAreas = &numViewWorldAreas;
	gather.viewWorldSurfaces = viewWorldSurfaces;
	gather.numViewWorldSurfaces = &numViewWorldSurfaces;
	gather.viewModels = viewModels;
	gather.numViewModels = &numViewModels;
	gather.sceneModels = sceneModels;
	gather.numSceneModels = &numSceneModels;
	gather.viewAugmentModels = viewAugmentModels;
	gather.numViewAugmentModels = &numViewAugmentModels;
	gather.viewLights = viewLights;
	gather.numViewLights = &numViewLights;
	gather.occlusionTestWorldAreas = occlusionTestWorldAreas;
	gather.numOcclusionTestWorldAreas = &numOcclusionTestWorldAreas;
	gather.occlusionTestModels = occlusionTestModels;
	gather.numOcclusionTestModels = &numOcclusionTestModels;
	gather.occlusionTestLights = occlusionTestLights;
	gather.numOcclusionTestLights = &numOcclusionTestLights;
	RenderGather( &gather );
	SetupVisibleModelMVPs( *this, view );

	const bool * const binaryState = renderWorld->binaryModelState.Num() > 0
		? renderWorld->binaryModelState.Ptr() : nullptr;
	renderDepthParms_t depth = {};
	depth.settings = &settings;
	depth.renderView = view;
	depth.viewWorldAreas = viewWorldAreas;
	depth.numViewWorldAreas = numViewWorldAreas;
	depth.viewWorldSurfaces = viewWorldSurfaces;
	depth.numViewWorldSurfaces = numViewWorldSurfaces;
	depth.viewModels = viewModels;
	depth.numViewModels = numViewModels;
	depth.sceneModels = sceneModels;
	depth.numSceneModels = numSceneModels;
	depth.binaryModelState = binaryState;
	depth.renderDestDefault = renderSystemLocal.renderDestDefault;
	depth.occlusionBaseTriangles = nullptr;
	depth.progOccluderDepthOnly = renderSystemLocal.progOccluderDepthOnly;
	depth.progOutside = nullptr;
	depth.progRadiosityPreview = nullptr;
	depth.imgBlack = globalImages != nullptr ? globalImages->blackImage : nullptr;
	depth.extraClears = 1;
	depth.occlusionState = view->occlusionState;
	depth.drawSurfs = drawSurfs;
	depth.numDrawSurfs = &numDrawSurfs;
	RenderDepth( &depth );

	renderOcclusionParms_t occlusion = {};
	occlusion.settings = &settings;
	occlusion.renderView = view;
	occlusion.occlusionTestNodes = occlusionTestNodes;
	occlusion.numOcclusionTestNodes = numOcclusionTestNodes;
	occlusion.occlusionTestWorldAreas = occlusionTestWorldAreas;
	occlusion.numOcclusionTestWorldAreas = numOcclusionTestWorldAreas;
	occlusion.occlusionTestModels = occlusionTestModels;
	occlusion.numOcclusionTestModels = numOcclusionTestModels;
	occlusion.occlusionTestLights = occlusionTestLights;
	occlusion.numOcclusionTestLights = numOcclusionTestLights;
	occlusion.areaNodeOcclusionIndex = renderWorld->areaNodeOcclusionIndex;
	occlusion.areaNodeBounds = renderWorld->areaNodeBounds;
	occlusion.worldAreaGeometryBounds = renderWorld->worldAreaGeometryBounds;
	occlusion.numWorldAreas = worldAreaCount;
	occlusion.renderDestDefault = renderSystemLocal.renderDestDefault;
	occlusion.progDepthOnly = renderSystemLocal.progDepthOnly;
	occlusion.unitCubeTris = renderSystemLocal.unitCubeTris;
	occlusion.zeroOneCubeTris = renderSystemLocal.zeroOneCubeTris;
	occlusion.occlusionState = view->occlusionState;
	RenderOcclusion( &occlusion );

	renderSortParms_t sort = {};
	sort.settings = &settings;
	sort.renderView = view;
	sort.drawSurfs = drawSurfs;
	sort.numDrawSurfs = numDrawSurfs;
	sort.sortedDrawSurfs = sortedDrawSurfs;
	sort.renderPasses = renderPasses;
	RenderSort( &sort );

	renderLightsParms_t lights = {};
	lights.settings = &settings;
	lights.renderView = view;
	lights.drawSurfParms.settings = &settings;
	lights.drawSurfParms.renderView = view;
	lights.drawSurfParms.allowInGameGUIs = true;
	SetupCaptureParms( lights.drawSurfParms.captureParms,
		CAPTURE_GUI_IMAGE, false, view->viewIndex );
	lights.drawSurfParms.renderDestDefault = renderSystemLocal.renderDestDefault;
	lights.drawSurfParms.renderDestGui = renderSystemLocal.renderDestGui;
	lights.viewLights = viewLights;
	lights.numViewLights = numViewLights;
	lights.viewModels = viewModels;
	lights.numViewModels = numViewModels;
	lights.viewWorldSurfaces = viewWorldSurfaces;
	lights.numViewWorldSurfaces = numViewWorldSurfaces;
	lights.rpLightTranslation = Parm( "lightTranslation" );
	lights.rpLightScale = Parm( "lightScale" );
	lights.rpGlobalLightOrigin = Parm( "globalLightOrigin" );
	lights.rpStaticSpecularScale = Parm( "staticSpecularScale" );
	lights.rpStaticSpecularVector = Parm( "staticSpecularVector" );
	lights.rpLightProjectionS = Parm( "lightProjectionS" );
	lights.rpLightProjectionT = Parm( "lightProjectionT" );
	lights.rpLightProjectionR = Parm( "lightProjectionR" );
	lights.rpLightProjectionQ = Parm( "lightProjectionQ" );
	lights.rpLightFade = Parm( "lightFade" );
	lights.progDepthOnly = renderSystemLocal.progDepthOnly;
	lights.progDeferredPointLight = renderSystemLocal.progDeferredPointLight;
	lights.progDeferredSpotLight = renderSystemLocal.progDeferredSpotLight;
	lights.progDeferredParallelLight = renderSystemLocal.progDeferredParallelLight;
	lights.renderDestDefault = renderSystemLocal.renderDestDefault;
	lights.zeroOneCubeTris = renderSystemLocal.zeroOneCubeTris;
	lights.binaryModelState = binaryState;
	lights.numShadows = &numShadows;
	RenderLights( &lights );

	renderFogParms_t fog = {};
	fog.settings = &settings;
	fog.renderView = view;
	fog.progGlobalFog = renderSystemLocal.progGlobalFog;
	fog.unitSquareTris = renderSystemLocal.unitSquareTris;
	RenderFog( &fog );

	for ( int passIndex = RENDERPASS_EMISSIVE;
			passIndex < NUM_RENDER_PASSES; ++passIndex ) {
		renderPassParms_t pass = {};
		pass.pass = static_cast< renderPass_t >( passIndex );
		pass.settings = &settings;
		pass.renderView = view;
		pass.drawSurfParms.settings = &settings;
		pass.drawSurfParms.renderView = view;
		pass.drawSurfParms.allowInGameGUIs = true;
		SetupCaptureParms( pass.drawSurfParms.captureParms,
			CAPTURE_GUI_IMAGE, false, view->viewIndex );
		pass.drawSurfParms.renderDestDefault = renderSystemLocal.renderDestDefault;
		pass.drawSurfParms.renderDestGui = renderSystemLocal.renderDestGui;
		pass.renderDestDefault = renderSystemLocal.renderDestDefault;
		pass.renderDestDistortion =
			renderSystemLocal.renderDestDistortion[view->viewIndex];
		pass.rpViewColor = renderSystemLocal.rpViewColor;
		pass.renderPasses = renderPasses;
		pass.sortedDrawSurfs = sortedDrawSurfs;
		pass.binaryModelState = binaryState;
		RenderPass( &pass );
	}

	CaptureToViewColor( view->viewIndex );
	renderPostProcessParms_t post = {};
	post.settings = &settings;
	post.renderView = view;
	post.rpViewColor = renderSystemLocal.rpViewColor;
	post.rpDistortionMap = Parm( "distortionMap" );
	post.progPostProcess = renderSystemLocal.progPostProcess;
	post.imgViewColor = renderSystemLocal.imgViewColor[view->viewIndex];
	post.imgBlack = globalImages != nullptr ? globalImages->blackImage : nullptr;
	post.imgDistortion = renderSystemLocal.imgDistortion[view->viewIndex];
	post.unitSquareTris = renderSystemLocal.unitSquareTris;
	RenderPostProcess( &post );
	RenderDebugTools();

	renderThreadParmState->VirtualRollbackParmBlock(
		view->r.parmBlock, view->r.parmBlock );
	if ( view->occlusionState != nullptr )
		++view->occlusionState->renderFrameNumber;
}
