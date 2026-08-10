#include "renderpasses.h"

#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "../../rendermodelsurface.h"
#include "../../renderview.h"
#include "parmstate.h"

namespace {
	void SetViewTarget( const renderPassParms_t * parms,
			const idRenderDestination * destination ) {
		GL_SetRenderDestination( destination );
		const idScreenRect & viewport = parms->renderView->viewport;
		GL_Viewport( viewport.x1, viewport.y1,
			viewport.x2 - viewport.x1 + 1, viewport.y2 - viewport.y1 + 1 );
		const idScreenRect & scissor = parms->renderView->scissorRect;
		GL_Scissor( scissor.x1, scissor.y1,
			scissor.x2 - scissor.x1 + 1, scissor.y2 - scissor.y1 + 1 );
	}

	bool SurfaceEnabled( const renderPassParms_t * parms,
			const drawSurf_t * surface ) {
		if ( surface == nullptr || surface->modelSurface == nullptr ) return false;
		const int binaryId = surface->modelSurface->binaryModelId;
		return parms->binaryModelState == nullptr || binaryId < 0 ||
			parms->binaryModelState[binaryId];
	}

	void DrawPassRange( const renderPassParms_t * parms, renderPass_t pass ) {
		idRenderDrawSurf renderer;
		const renderPassSurfaces_t & range = parms->renderPasses[pass];
		for ( int index = range.firstSurface; index <= range.lastSurface; ++index ) {
			drawSurf_t * const surface = parms->sortedDrawSurfs[index];
			if ( SurfaceEnabled( parms, surface ) )
				renderer.RenderDrawSurf( &parms->drawSurfParms, surface, 0 );
		}
	}
}

void RenderClearPass( const renderPassParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr ) return;
	SetViewTarget( parms, parms->renderDestDefault );
	GL_State( GLS_DEFAULT );
	GL_Clear( true, false, false, 0x80,
		parms->settings->clearColor.x,
		parms->settings->clearColor.y,
		parms->settings->clearColor.z, 1.0f );
}

void RenderEmissivePass( const renderPassParms_t * parms ) {
	if ( parms == nullptr || parms->renderView == nullptr ) return;
	SetViewTarget( parms, parms->renderDestDefault );
	DrawPassRange( parms, RENDERPASS_EMISSIVE );
}

void RenderEmissiveOnlyPass( const renderPassParms_t * parms ) {
	if ( parms == nullptr || parms->renderView == nullptr ) return;
	SetViewTarget( parms, parms->renderDestDefault );
	DrawPassRange( parms, RENDERPASS_EMISSIVE_ONLY );
}

void RenderBlendPass( const renderPassParms_t * parms ) {
	if ( parms == nullptr || parms->renderView == nullptr ) return;
	SetViewTarget( parms, parms->renderDestDefault );
	DrawPassRange( parms, RENDERPASS_BLEND );
}

void RenderDistortionPass( const renderPassParms_t * parms ) {
	if ( parms == nullptr || parms->renderView == nullptr ||
			parms->renderDestDistortion == nullptr ) return;
	GL_SetRenderDestination( parms->renderDestDistortion );
	GL_Viewport( 0, 0, parms->renderDestDistortion->targetWidth,
		parms->renderDestDistortion->targetHeight );
	GL_Scissor( 0, 0, parms->renderDestDistortion->targetWidth,
		parms->renderDestDistortion->targetHeight );
	GL_State( GLS_DEFAULT );
	GL_Clear( true, false, false, 0, 0.5f, 0.5f, 0.5f, 0.0f );
	DrawPassRange( parms, RENDERPASS_DISTORTION );
	GL_ResolveTarget( RESOLVE_TARGET_COLOR0, parms->renderDestDistortion );
	SetViewTarget( parms, parms->renderDestDefault );
	if ( renderThreadParmState != nullptr )
		renderThreadParmState->SetPositionToViewTexture(
			parms->renderView->windowWidth, parms->renderView->windowHeight,
			parms->renderView->renderWidth, parms->renderView->renderHeight );
}

void RenderPass( const renderPassParms_t * parms ) {
	if ( parms == nullptr ) return;
	switch ( parms->pass ) {
		case RENDERPASS_CLEAR: RenderClearPass( parms ); break;
		case RENDERPASS_EMISSIVE: RenderEmissivePass( parms ); break;
		case RENDERPASS_EMISSIVE_ONLY: RenderEmissiveOnlyPass( parms ); break;
		case RENDERPASS_BLEND: RenderBlendPass( parms ); break;
		case RENDERPASS_DISTORTION: RenderDistortionPass( parms ); break;
		default: break;
	}
}
