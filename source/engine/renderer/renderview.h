#pragma once

#include "parmblock.h"
#include "idlib/geometry/rendermatrix.h"
#include "idlib/geometry/screenrect.h"

#include <cstdint>

class idDeclEnv;
class idImage;
class idMaterial;

struct alignas( 16 ) renderView_t {
	renderView_t( threadId_t thread = THREAD_MAIN );
	void BuildProjectionMatrix( idRenderMatrix & projectionMatrix,
		int jitterWidth = 0, int jitterHeight = 0 ) const;
	void BuildViewMatrix( idRenderMatrix & viewMatrix ) const;

	int renderTime;
	int viewID;
	bool forceFullVirtualTextureLoad;
	bool discontinuousViewPosition;
	bool skipDimShadows;
	bool skipPostProcess;
	bool skipDynamicEnvironment;
	bool forceFullResolution;
	bool useHQViewColorMipsGeneration;
	float fov_x;
	float fov_y;
	bool cramZNear;
	idRenderMatrix explicitProjectionMatrix;
	bool useExplicitProjectionMatrix;
	idVec3 vieworg;
	idMat3 viewaxis;
	bool forceIdentityViewMatrix;
	idStaticParmBlock< 32 > parmBlock;
	const idDeclEnv * dynEnvOverride;
	float dynEnvOverrideDuration;
	int dynEnvOverrideModelIndex;
	bool applyDynEnvOverride;
	idStaticParmBlock< 32 > envOverrideParmBlock;
	bool radialBlurEnabled;
	idVec3 radialBlurCenterPos;
	bool godRaysEnabled;
	bool godRaysRelativeToCamera;
	idVec3 godRaysPosition;
	idVec3 godRaysColor;
	float godRaysSize;
	float godRaysSourceSize;
	const idMaterial * godRaysMaterial;
};

struct envBlend_t {
	const idDeclEnv * env;
	float blendStartTime;
	float blendDuration;
	bool cubeFinished;
	bool hasOverrideParms;
};

struct alignas( 8 ) occlusionState_t {
	std::int64_t nodeOcclusionQuery[64];
	std::int64_t worldAreaOcclusionQuery[8192];
	std::int64_t modelOcclusionQuery[4096];
	std::int64_t shadowOcclusionQuery[4096];
	std::int64_t lightOcclusionQuery[4096];
	int modelVisibleFrameNumber[4096];
	int modelVisibleFrameCount[4096];
	int modelOcclusionQueryResult[4096];
	int renderFrameNumber;
};

class alignas( 16 ) idRenderView {
public:
	idRenderView();
	~idRenderView();
	void CommitParameters( int windowWidth, int windowHeight,
		int renderWidth, int renderHeight );

	renderView_t g;
	idImage * imgViewColor;
	int viewIndex;
	envBlend_t envBlend;
	idParmBlock blendedEnvironmentParms;
	renderView_t r;
	idRenderMatrix projectionMatrix;
	idRenderMatrix inverseProjectionMatrix;
	idRenderMatrix viewMatrix;
	idRenderMatrix inverseViewMatrix;
	idRenderMatrix worldSpaceMVPMatrix;
	idRenderMatrix worldSpaceInverseMVPMatrix;
	idRenderMatrix viewSpaceModelMatrix;
	idRenderMatrix viewSpaceInverseModelMatrix;
	idRenderMatrix viewSpaceMVPMatrix;
	int windowWidth;
	int windowHeight;
	int renderWidth;
	int renderHeight;
	int feedbackWidth;
	int feedbackHeight;
	idScreenRect viewport;
	idScreenRect scissorRect;
	idScreenRect testScissor;
	std::int64_t firstOcclusionQueryInPreviousFrame;
	occlusionState_t * occlusionState;
};

struct alignas( 16 ) foliageRenderView_t {
	float time;
	float nearDist;
	float farDist;
	float fov[2];
	idVec3 viewOrg;
	idVec3 viewFwd;
	idVec3 viewLeft;
	idVec3 viewUp;
	idRenderMatrix mvpMatrix;
	unsigned short atlasWidth;
	unsigned short atlasHeight;
	int pad[2];
};

struct alignas( 16 ) detailRenderView_t {
	float time;
	float nearDist;
	float farDist;
	float fov[2];
	idVec3 viewOrg;
	idVec3 viewFwd;
	idVec3 viewLeft;
	idVec3 viewUp;
	int pad[3];
	idRenderMatrix mvpMatrix;
};

struct particleRenderView_t {
	idVec3 viewOrg;
	idVec3 viewFwd;
	idVec3 viewLeft;
	idVec3 viewUp;
	int renderTime;
	int deltaTime;
	unsigned short atlasWidth;
	unsigned short atlasHeight;
	int pad;
};
