#pragma once

#include "renderer_types.h"
#include "idlib/bv/bounds.h"
#include "idlib/geometry/rendermatrix.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

class idDeclRenderParm;
class idDeclRenderProg;
class idIESfile;
class idMaterial;
class idRenderDestination;
class idRenderLightCommitted;
class idRenderModelCommitted;
class idRenderModelSurface;
class idRenderView;
class idTriangles;
struct renderDrawSurfParms_t;
struct renderSettings_t;
struct renderShadowBufferParms_t;

enum lightType_t : int {
	LIGHT_POINT = 0,
	LIGHT_SPOT = 1,
	LIGHT_PARALLEL = 2,
	LIGHT_REAL = 3,
	LIGHT_MAX_TYPES = 4
};

enum lightFallOff_t : int {
	LIGHT_FALLOFF_TEXTURE = 0,
	LIGHT_FALLOFF_LINEAR = 1,
	LIGHT_FALLOFF_INVERSE_SQUARE = 2,
	LIGHT_FALLOFF_RADIAL = 3
};

enum lightClass_t : int {
	LIGHT_NORMAL = 0,
	LIGHT_PRELIGHT_ONLY = 1,
	LIGHT_SLOWLIGHT_DYNAMIC_ONLY = 2,
	LIGHT_SLOWLIGHT_PRIVATE_ONLY = 3,
	LIGHT_DYNAMIC_ONLY = 4,
	LIGHT_PRIVATE_DYNAMIC_ONLY = 5,
	LIGHT_PRIVATE_PRIME = 6,
	LIGHT_BLENDED_ONLY = 7
};

class idRenderLightParms {
public:
	idRenderLightParms();

	void ComputePointLightProjectionMatrix( idRenderMatrix & localProject ) const;
	void ComputeSpotLightProjectionMatrix( idRenderMatrix & localProject ) const;
	void ComputeWorldToLightMatrix( idRenderMatrix & baseLightProject,
		idRenderMatrix & inverseBaseLightProject ) const;
	void ComputeLightGlobalOrigin( idVec3 & globalOrigin ) const;
	void ComputeLightGlobalReferenceBounds( idBounds & globalReferenceBounds,
		idVec3 * corners = nullptr ) const;

	idMat3 axis;
	idVec3 origin;
	int allowLightOnlyInViewID;
	int suppressLightInViewID;
	lightType_t lightType;
	lightClass_t lightClass;
	lightFallOff_t lightFalloff;
	bool noShadows;
	bool slowLight;
	const idMaterial * shader;
	idVec3 lightRadius;
	idVec3 lightCenter;
	idVec3 target;
	idVec3 right;
	idVec3 up;
	idVec3 start;
	idVec3 end;
	idVec3 dynamicModelLightingScale;
	float dimShadowStretch;
	float maxVisibleRange;
	float fadeVisibilityOver;
	float staticSpecularScale;
	idVec3 staticSpecularVector;
	bool bakedParallelShadows;
	const idIESfile * iesFile;
	float iesPowerScale;
	float iesAreaScale;
	float areaLightSize;
	float shadowSampleScale;
	int slowMultiPass;
};

#include "jobs/render/renderdrawsurf.h"
#include "jobs/render/rendershadowbuffer.h"

struct renderLightsParms_t {
	const renderSettings_t * settings;
	const idRenderView * renderView;
	renderDrawSurfParms_t drawSurfParms;
	renderShadowBufferParms_t shadowBufferParms;
	const idRenderLightCommitted ** viewLights;
	int numViewLights;
	const idRenderModelCommitted ** viewModels;
	int numViewModels;
	const idRenderModelSurface ** viewWorldSurfaces;
	int numViewWorldSurfaces;
	const idDeclRenderParm * rpLightRotation;
	const idDeclRenderParm * rpLightTranslation;
	const idDeclRenderParm * rpLightScale;
	const idDeclRenderParm * rpLightOscillationAmp;
	const idDeclRenderParm * rpLightOscillationFreq;
	const idDeclRenderParm * rpLightOscillationPhase;
	const idDeclRenderParm * rpWindowPosToProjectedTexS;
	const idDeclRenderParm * rpWindowPosToProjectedTexT;
	const idDeclRenderParm * rpWindowPosToProjectedTexR;
	const idDeclRenderParm * rpWindowPosToProjectedTexQ;
	const idDeclRenderParm * rpWindowPosToProjectedShadowS;
	const idDeclRenderParm * rpWindowPosToProjectedShadowT;
	const idDeclRenderParm * rpWindowPosToProjectedShadowR;
	const idDeclRenderParm * rpWindowPosToProjectedShadowQ;
	const idDeclRenderParm * rpShadowProjectionS;
	const idDeclRenderParm * rpShadowProjectionT;
	const idDeclRenderParm * rpShadowProjectionR;
	const idDeclRenderParm * rpShadowProjectionQ;
	const idDeclRenderParm * rpGlobalLightOrigin;
	const idDeclRenderParm * rpStaticSpecularScale;
	const idDeclRenderParm * rpStaticSpecularVector;
	const idDeclRenderParm * rpLightProjectionS;
	const idDeclRenderParm * rpLightProjectionT;
	const idDeclRenderParm * rpLightProjectionR;
	const idDeclRenderParm * rpLightProjectionQ;
	const idDeclRenderParm * rpLocalToLightS;
	const idDeclRenderParm * rpLocalToLightT;
	const idDeclRenderParm * rpLocalToLightR;
	const idDeclRenderParm * rpLocalToLightQ;
	const idDeclRenderParm * rpLightFade;
	const idDeclRenderProg * progDepthOnly;
	const idDeclRenderProg * progBlendedLightDebugDraw;
	const idDeclRenderProg * progDeferredPointLight;
	const idDeclRenderProg * progDeferredSpotLight;
	const idDeclRenderProg * progDeferredParallelLight;
	const idRenderDestination * renderDestDefault;
	const idTriangles * zeroOneCubeTris;
	const bool * binaryModelState;
	int * numShadows;
};

void RenderLights( const renderLightsParms_t * parms );
