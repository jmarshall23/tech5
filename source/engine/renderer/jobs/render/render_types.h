#pragma once

// Shared render-job ABI recovered from the retail PDB/type database.  These
// structures are deliberately platform-neutral; the Xbox command emission
// that consumed them is replaced by the D3D9 wrapper.

#include "../../renderer_types.h"
#include "idlib/bv/bounds.h"

class idDeclRenderParm;
class idDeclRenderProg;
class idImage;
class idMaterial;
class idPixelPackBuffer;
class idRenderDestination;
class idRenderLightCommitted;
class idRenderMatrix;
class idRenderModelCommitted;
class idRenderModelSurface;
class idRenderView;
class idTriangles;
struct occlusionState_t;

enum renderPass_t : int {
	RENDERPASS_CLEAR = 0,
	RENDERPASS_EMISSIVE = 1,
	RENDERPASS_EMISSIVE_ONLY = 2,
	RENDERPASS_BLEND = 3,
	RENDERPASS_DISTORTION = 4,
	NUM_RENDER_PASSES = 5
};

enum renderCapture_t : int {
	CAPTURE_VIEW_COLOR = 0,
	CAPTURE_VIEW_DEPTH = 1,
	CAPTURE_FEEDBACK = 2,
	CAPTURE_GLARE_MAP = 3,
	CAPTURE_GUI_IMAGE = 4
};

struct nodeWorldArea_t {
	short areaNum;
	short nodeOcclusionTestIndex;
};

struct viewWorldArea_t {
	int areaNum;
	short numSurfs;
	bool skipDetailTriangles;
};

struct drawSurf_t {
	float sort;
	bool isWorld;
	bool skipDetailTriangles;
	const idRenderModelCommitted * model;
	const idRenderModelSurface * modelSurface;
	const idMaterial * material;
	const idDeclRenderProg * prog;
};

struct renderPassSurfaces_t {
	int firstSurface;
	int lastSurface;
};

struct alignas( 16 ) renderSettings_t {
	renderSettings_t();
	bool isComboMap;
	bool skipWorld;
	bool skipModels;
	bool skipLights;
	bool skipBlendLightShadows;
	bool skipSuppress;
	bool skipFeedback;
	bool skipDynamic;
	bool skipAddAlways;
	bool skipAugment;
	bool skipAutosprites;
	bool skipOcclusionBaseModel;
	bool skipEmissiveSurfaces;
	bool skipBlendedSurfaces;
	bool skipDistortionSurfaces;
	bool skipGuis;
	bool skipInGameGuis;
	bool skipAdaptiveGlare;
	bool skipPostProcess;
	bool skipEmissiveGlare;
	bool skipBlendLights;
	bool skipSlowLights;
	bool skipFog;
	bool skipGodRays;
	bool skipNodeCPUCulling;
	bool skipNodeGPUCulling;
	bool skipAreaCPUCulling;
	bool skipAreaGPUCulling;
	bool skipModelCPUCulling;
	bool skipModelGPUCulling;
	bool skipLightCPUCulling;
	bool skipLightGPUCulling;
	bool skipSurfaceCPUCulling;
	bool skipModelRangeCulling;
	bool skipLightRangeCulling;
	int singleWorldArea;
	int singleLight;
	int singleModel;
	int singleSurface;
	int singleGuiSurface;
	int singleDimShadow;
	bool forceTwoSidedDepth;
	bool useAmbientEnv;
	bool feedbackBGRA;
	bool showOcclusionBoxes;
	bool forceOcclusionBoxQueries;
	int numViews;
	int generateMipMaps;
	int guiFrameCount;
	int queryThreshold;
	bool dimShadowUseQuery;
	bool dimShadowDepthBoundsTest;
	int dimShadowResolution;
	int dimShadowForceHighQuality;
	int showDimShadows;
	float dimShadowLixelScale;
	float dimShadowDensity;
	float dimShadowPolyOfsUnits;
	float dimShadowPolyOfsFactor;
	float dimShadowMaxVisibleRange;
	float dimShadowFadeVisibilityRange;
	bool dimShadowSkipRangeCulling;
	bool useLightScissors;
	bool useLightDepthBoundsTest;
	bool useDeferredSlowMapLighting;
	bool showLightScissors;
	int showBlendedLights;
	float sortCoverage;
	float sortSkybox;
	float sortBackground;
	float sortEmit;
	float sortEmitOnly;
	float sortLight;
	float sortDecal;
	float sortTransSort;
	float sortTrans;
	float sortWater;
	float sortPerturber;
	float sortLast;
	float viewNearZ;
	float viewFarZ;
	const idDeclRenderProg * progShowGuiOverdraw;
	idVec3 clearColor;
	idVec4 viewOrigin;
	idBounds viewBounds;
	alignas( 16 ) idBounds detailBounds;
};

struct alignas( 4 ) shadowBufferOptions_t {
	shadowBufferOptions_t();
	int shadowBufferSize;
	int occluderFacing;
	int singleSide;
	float sliceStep;
	float polyOfsFactor;
	float polyOfsUnits;
	float parallelPolyOfsFactor;
	float parallelPolyOfsUnits;
	bool skipShadows;
	bool skipShadowModelSort;
	bool skipShadowOccluders;
	bool skipShadowModelCPUCulling;
	bool skipShadowSurfaceCPUCulling;
};

struct captureParms_t {
	renderCapture_t capture;
	const renderSettings_t * settings;
	int renderWidth;
	int renderHeight;
	int windowWidth;
	int windowHeight;
	bool forceFullVirtualTextureLoad;
	int viewIndex;
	const idRenderDestination * renderDestDefault;
	const idImage * imgViewDepth;
	const idRenderDestination * renderDestViewColor;
	const idRenderDestination * renderDestViewDepth;
	idRenderDestination * renderDestFeedback;
	void * feedbackBuffer;
	idPixelPackBuffer * feedbackBufferObject;
	const idDeclRenderParm * rpFeedbackColor;
	const idRenderDestination * renderDestGui;
	bool createMipMaps;
	const idRenderDestination * renderDestMip;
	const idRenderDestination * renderDestMip3;
	const idDeclRenderParm * rpGlareMap;
	const idDeclRenderProg * progGlareScale;
	const idDeclRenderProg * progOverlappedDownSample;
	const idDeclRenderProg * progFeedbackDownSample;
	const idDeclRenderParm * rpViewColor;
	const idTriangles * unitSquareTris;
	const idImage * imgBlack;
};

static_assert( sizeof( nodeWorldArea_t ) == 4,
	"Recovered node/world-area ABI changed" );
static_assert( sizeof( viewWorldArea_t ) == 8,
	"Recovered visible-area ABI changed" );
#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( drawSurf_t ) == 24,
	"Recovered draw-surface ABI changed" );
#endif
