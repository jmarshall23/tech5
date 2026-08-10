#pragma once

// Recovered fixed-capacity front-end state.  The layout and collection sizes
// follow the retail PDB; only the orchestration methods are platform-neutral.

#include "jobs/render/render_types.h"
#include "rendermodelcommitted.h"

class idRenderWorldLocal;
class idScreenView;

class idRender {
public:
	idRender();

	void SetRenderSize( int viewIndex, int renderWidth, int renderHeight );
	void InitSettings( const idRenderWorldLocal * world,
		const idRenderView * renderView );
	void SetupCaptureParms( captureParms_t & parms, renderCapture_t capture,
		bool createMipMaps, int viewIndex ) const;
	void CaptureToViewColor( int viewIndex );
	void RenderSingleView( idRenderWorldLocal * world,
		idRenderView * renderView );
	void SimpleWorldSetup();
	void PolygonClear( const idVec4 & color, unsigned long long state );
	void ShowModelGroupMasters();
	void ShowDestinationAlpha();
	void ShowIntensity();
	void ShowDepthBuffer();
	void ShowCracks();
	void ShowLights();
	void ShowEnvironments();
	void ColorByStencilBuffer();
	void ShowLightCount();
	void ShowTransparencySortOverdraw();
	void ShowViewModels();
	void ShowSurfaceBounds();
	void ShowOcclusionBaseModel();
	void ShowGamma();
	void ShowGammaBias();
	void ShowTextureReconstruct();
	void ShowGammaCalibrationTest();
	void ShowLoadedImages();
	void ShowTestImage();
	void ShowTestVMTR();
	void ShowTris();
	void ShowTwoSided();
	void ShowBlendedSurfaces();
	void ShowBlendedSurfaceOverdraw();
	void ShowTrace();
	void ShowTangentSpace();
	void ShowTextureSpace();
	void ShowTextureDistortion();
	void ShowVertexColor();
	void ShowGlobalShadows();
	void ShowAutosprite();
	void ShowSurfaceInfo();
	void ShowModelLightingInfo();
	void InternalDrawText( const char * text, const idVec3 & origin,
		float scale, const idVec4 & color, const idMat3 & viewAxis,
		int align );
	void ShowDebugText();
	void ShowDebugLines();
	void ShowDebugPolygons();
	void ShowTestCubeImage();
	void RenderDebugTools_NonPortable();
	void RenderDebugTools();

	unsigned char temp[1024];
	unsigned char areaNodeBoundsCulled[8192];
	unsigned char worldAreaSubspaceBoundsCulled[8192];
	unsigned char worldAreaGeometryBoundsCulled[8192];
	nodeWorldArea_t nodeWorldAreas[8192];
	viewWorldArea_t viewWorldAreas[8192];
	const idRenderModelSurface * viewWorldSurfaces[8192];
	const idRenderModelCommitted * viewModels[4096];
	const idRenderModelCommitted * sceneModels[64];
	const idRenderModelCommitted * viewAugmentModels[32];
	const idRenderLightCommitted * viewLights[4096];
	int occlusionTestNodes[64];
	int occlusionTestWorldAreas[4096];
	const idRenderModelCommitted * occlusionTestModels[4096];
	const idRenderLightCommitted * occlusionTestLights[512];
	drawSurf_t drawSurfs[4096];
	drawSurf_t * sortedDrawSurfs[4096];
	short dimShadowModelSlaves[4096];
	unsigned char modelConsideredAsOccluder[512];
	unsigned char modelDimShadowState[4096];
	int numNodeWorldAreas;
	int numViewWorldAreas;
	int numViewWorldSurfaces;
	int numViewModels;
	int numSceneModels;
	int numViewAugmentModels;
	int numViewLights;
	int numOcclusionTestNodes;
	int numOcclusionTestWorldAreas;
	int numOcclusionTestModels;
	int numOcclusionTestLights;
	int numDrawSurfs;
	int numShadows;
	int numDimShadows;
	renderPassSurfaces_t renderPasses[NUM_RENDER_PASSES];
	renderSettings_t settings;
	idRenderView * renderViewObject;
	const idRenderWorldLocal * world;
	const idScreenView * screenView;
	idRenderModelCommitted worldSpace;
	idRenderModelCommitted viewSpace;
};

extern idRender renderState;
