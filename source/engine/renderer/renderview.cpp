#include "renderview.h"

#include <algorithm>
#include <cmath>
#include <cstring>

renderView_t::renderView_t( const threadId_t thread ) :
	parmBlock(), envOverrideParmBlock() {
	parmBlock.thread = thread;
	envOverrideParmBlock.thread = thread;
	renderTime = 0;
	viewID = 0;
	forceFullVirtualTextureLoad = false;
	discontinuousViewPosition = false;
	skipDimShadows = false;
	skipPostProcess = false;
	skipDynamicEnvironment = false;
	forceFullResolution = false;
	useHQViewColorMipsGeneration = false;
	fov_x = 90.0f;
	fov_y = 60.0f;
	cramZNear = false;
	explicitProjectionMatrix.Identity();
	useExplicitProjectionMatrix = false;
	vieworg.Zero();
	viewaxis = idMat3( 1.0f );
	forceIdentityViewMatrix = false;
	dynEnvOverride = nullptr;
	dynEnvOverrideDuration = 0.0f;
	dynEnvOverrideModelIndex = -1;
	applyDynEnvOverride = false;
	radialBlurEnabled = false;
	radialBlurCenterPos.Zero();
	godRaysEnabled = false;
	godRaysRelativeToCamera = false;
	godRaysPosition.Zero();
	godRaysColor.Set( 1.0f, 1.0f, 1.0f );
	godRaysSize = 0.0f;
	godRaysSourceSize = 0.0f;
	godRaysMaterial = nullptr;
}

void renderView_t::BuildProjectionMatrix( idRenderMatrix & output,
	const int jitterWidth, const int jitterHeight ) const {
	if ( useExplicitProjectionMatrix ) {
		output = explicitProjectionMatrix;
		return;
	}
	const float zNear = cramZNear ? 0.75f : 3.0f;
	const float zFar = 100000.0f;
	float xOffset = 0.0f;
	float yOffset = 0.0f;
	if ( jitterWidth > 0 && jitterHeight > 0 ) {
		// Deterministic half-pixel jitter is stable across render and capture
		// threads while retaining the retail sub-pixel projection behavior.
		xOffset = zNear * std::tan( fov_x * 0.00872664626f ) / jitterWidth;
		yOffset = zNear * std::tan( fov_y * 0.00872664626f ) / jitterHeight;
	}
	idRenderMatrix::BuildProjectionFov( (std::max)( fov_x, 1.0f ),
		(std::max)( fov_y, 1.0f ), zNear, zFar, xOffset, yOffset, output );
}

void renderView_t::BuildViewMatrix( idRenderMatrix & output ) const {
	if ( forceIdentityViewMatrix ) output.Identity();
	else idRenderMatrix::ModelViewFromOriginAxis( vieworg, viewaxis, output );
}

idRenderView::idRenderView() :
	g( THREAD_MAIN ), imgViewColor( nullptr ), viewIndex( 0 ),
	blendedEnvironmentParms( THREAD_RENDERER ), r( THREAD_RENDERER ),
	windowWidth( 0 ), windowHeight( 0 ), renderWidth( 0 ), renderHeight( 0 ),
	feedbackWidth( 0 ), feedbackHeight( 0 ),
	firstOcclusionQueryInPreviousFrame( 1 ), occlusionState( new occlusionState_t() ) {
	std::memset( &envBlend, 0, sizeof( envBlend ) );
	projectionMatrix.Identity();
	inverseProjectionMatrix.Identity();
	viewMatrix.Identity();
	inverseViewMatrix.Identity();
	worldSpaceMVPMatrix.Identity();
	worldSpaceInverseMVPMatrix.Identity();
	viewSpaceModelMatrix.Identity();
	viewSpaceInverseModelMatrix.Identity();
	viewSpaceMVPMatrix.Identity();
	viewport.Clear();
	scissorRect.Clear();
	testScissor.Clear();
	std::memset( occlusionState, 0, sizeof( *occlusionState ) );
	occlusionState->renderFrameNumber = 1;
}

idRenderView::~idRenderView() { delete occlusionState; }

void idRenderView::CommitParameters( const int newWindowWidth,
	const int newWindowHeight, const int newRenderWidth,
	const int newRenderHeight ) {
	r = g;
	r.parmBlock.thread = THREAD_RENDERER;
	r.envOverrideParmBlock.thread = THREAD_RENDERER;
	r.BuildProjectionMatrix( projectionMatrix );
	if ( !idRenderMatrix::Inverse( projectionMatrix, inverseProjectionMatrix ) ) {
		inverseProjectionMatrix.Identity();
	}
	r.BuildViewMatrix( viewMatrix );
	idRenderMatrix::InverseByTranspose( viewMatrix, inverseViewMatrix );
	idRenderMatrix::Multiply( projectionMatrix, viewMatrix, worldSpaceMVPMatrix );
	if ( !idRenderMatrix::Inverse( worldSpaceMVPMatrix, worldSpaceInverseMVPMatrix ) ) {
		worldSpaceInverseMVPMatrix.Identity();
	}
	viewSpaceModelMatrix = inverseViewMatrix;
	viewSpaceInverseModelMatrix = viewMatrix;
	viewSpaceMVPMatrix = projectionMatrix;
	windowWidth = (std::max)( newWindowWidth, 1 );
	windowHeight = (std::max)( newWindowHeight, 1 );
	renderWidth = (std::max)( newRenderWidth, 1 );
	renderHeight = (std::max)( newRenderHeight, 1 );
	feedbackWidth = 160;
	feedbackHeight = 128;
	viewport.x1 = scissorRect.x1 = testScissor.x1 = 0;
	viewport.y1 = scissorRect.y1 = testScissor.y1 = 0;
	viewport.x2 = scissorRect.x2 = testScissor.x2 = renderWidth - 1;
	viewport.y2 = scissorRect.y2 = testScissor.y2 = renderHeight - 1;
}
