#include "rendergodrays.h"

#include "../../declmaterial.h"
#include "../../declrenderparm.h"
#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "../../renderview.h"
#include "parmstate.h"

#include <cmath>

namespace {
	void SetVector( const idDeclRenderParm * parm, const idVec4 & vector ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.value[0] = vector.x; value.value[1] = vector.y;
		value.value[2] = vector.z; value.value[3] = vector.w;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}

	void SetImage( const idDeclRenderParm * parm, const idImage * image ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.image = image;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}
}

void RenderGodRays( const renderGodRaysParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipGodRays || parms->renderView == nullptr ||
			parms->renderDestOffScreen == nullptr || parms->unitSquareTris == nullptr ||
			parms->progCreateGodRays == nullptr ||
			parms->progDrawGodRays == nullptr ) return;
	idVec4 clip;
	( parms->godRaysRelativeToCamera
		? parms->renderView->viewSpaceMVPMatrix
		: parms->renderView->worldSpaceMVPMatrix )
		.TransformPoint( parms->godRaysPosition, clip );
	const float inverseW = std::fabs( clip.w ) > 1.0e-20f
		? 1.0f / clip.w : 1.0f;
	const float sourceX = clip.x * inverseW * 0.5f + 0.5f;
	const float sourceY = 0.5f - clip.y * inverseW * 0.5f;
	SetVector( parms->rpScaleBiasSource, idVec4( sourceX, sourceY,
		parms->godRaysSourceSize, parms->godRaysSize ) );
	SetVector( parms->rpScaleBiasQuad, idVec4( 1.0f, 1.0f, 0.0f, 0.0f ) );
	SetVector( parms->rpGodRaysColor, idVec4( parms->godRaysColor.x,
		parms->godRaysColor.y, parms->godRaysColor.z, 1.0f ) );
	if ( parms->godRaysMaterial != nullptr ) {
		SetImage( parms->rpTransMap, parms->godRaysMaterial->GetEditorImage() );
		renderThreadParmState->VirtualEvaluateParmBlock(
			*parms->godRaysMaterial->GetRenderParmBlock(),
			*parms->godRaysMaterial->GetRenderParmBlock() );
	}
	GL_SetRenderDestination( parms->renderDestOffScreen );
	GL_Viewport( 0, 0, parms->renderDestOffScreen->targetWidth,
		parms->renderDestOffScreen->targetHeight );
	GL_Scissor( 0, 0, parms->renderDestOffScreen->targetWidth,
		parms->renderDestOffScreen->targetHeight );
	GL_Clear( true, false, false, 0, 0.0f, 0.0f, 0.0f, 0.0f );
	GL_DrawElements( parms->progCreateGodRays, parms->unitSquareTris,
		GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	SetImage( parms->rpGodRayMap, parms->imgOffScreen );
	GL_SetRenderDestination( parms->renderDestDefault );
	const idScreenRect & viewport = parms->renderView->viewport;
	GL_Viewport( viewport.x1, viewport.y1,
		viewport.x2 - viewport.x1 + 1, viewport.y2 - viewport.y1 + 1 );
	GL_DrawElements( parms->progDrawGodRays, parms->unitSquareTris,
		GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	if ( parms->godRaysMaterial != nullptr )
		renderThreadParmState->VirtualRollbackParmBlock(
			*parms->godRaysMaterial->GetRenderParmBlock(),
			*parms->godRaysMaterial->GetRenderParmBlock() );
}
