#include "renderglare.h"

#include "../../declrenderparm.h"
#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "../../renderview.h"
#include "parmstate.h"

namespace {
	void SetImage( const idDeclRenderParm * parm, const idImage * image ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.image = image;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}

	void SetVector( const idDeclRenderParm * parm, float x, float y,
			float z = 0.0f, float w = 0.0f ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.value[0] = x; value.value[1] = y;
		value.value[2] = z; value.value[3] = w;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}

	void SetTarget( const idRenderDestination * destination ) {
		GL_SetRenderDestination( destination );
		GL_Viewport( 0, 0, destination->targetWidth, destination->targetHeight );
		GL_Scissor( 0, 0, destination->targetWidth, destination->targetHeight );
	}
}

void RenderGlare( const renderGlareParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipEmissiveGlare || parms->unitSquareTris == nullptr ||
			parms->progGauss == nullptr || parms->renderDestMip3 == nullptr ||
			parms->renderDestMip3Alt == nullptr ) return;
	SetTarget( parms->renderDestMip3Alt );
	SetImage( parms->rpGlareMap, parms->renderDestMip3->targetImage[0] );
	SetVector( parms->rpGlareStep,
		parms->xScale / parms->renderDestMip3->targetWidth, 0.0f );
	GL_DrawElements( parms->progGauss, parms->unitSquareTris,
		GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	SetTarget( parms->renderDestMip3 );
	SetImage( parms->rpGlareMap, parms->renderDestMip3Alt->targetImage[0] );
	SetVector( parms->rpGlareStep, 0.0f,
		parms->yScale / parms->renderDestMip3->targetHeight );
	GL_DrawElements( parms->progGauss, parms->unitSquareTris,
		GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	GL_SetRenderDestination( parms->renderDestDefault );
}

void RenderAdaptiveGlare( const renderAdapativeGlareParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipAdaptiveGlare ||
			parms->unitSquareTris == nullptr ||
			parms->renderDestAdaptiveGlare == nullptr ||
			parms->renderDestAdaptiveGlareAlt == nullptr ) return;
	SetVector( parms->rpAdaptiveGlareParms, parms->minThreshold,
		parms->maxThreshold, parms->avgBrightness, parms->decayRate );
	if ( parms->progLuminosity != nullptr &&
			parms->renderDestLuminosity != nullptr ) {
		SetTarget( parms->renderDestLuminosity );
		SetImage( parms->rpViewColor, parms->imgViewColor );
		SetImage( parms->rpLuminosityMapAlt, parms->imgLuminosityAlt );
		GL_DrawElements( parms->progLuminosity, parms->unitSquareTris,
			GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	}
	if ( parms->progBloomThreshold != nullptr ) {
		SetTarget( parms->renderDestAdaptiveGlare );
		SetImage( parms->rpViewColor, parms->imgViewColor );
		SetImage( parms->rpLuminosityMap, parms->imgLuminosity );
		GL_DrawElements( parms->progBloomThreshold, parms->unitSquareTris,
			GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	}
	if ( parms->progAdaptiveGlareGauss != nullptr ) {
		SetTarget( parms->renderDestAdaptiveGlareAlt );
		SetImage( parms->rpAdaptiveGlareBlurMap,
			parms->renderDestAdaptiveGlare->targetImage[0] );
		SetVector( parms->rpAdaptiveGlareBlurStep,
			parms->xScale / parms->renderDestAdaptiveGlare->targetWidth, 0.0f );
		GL_DrawElements( parms->progAdaptiveGlareGauss,
			parms->unitSquareTris, GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
		SetTarget( parms->renderDestAdaptiveGlare );
		SetImage( parms->rpAdaptiveGlareBlurMap,
			parms->renderDestAdaptiveGlareAlt->targetImage[0] );
		SetVector( parms->rpAdaptiveGlareBlurStep, 0.0f,
			parms->yScale / parms->renderDestAdaptiveGlare->targetHeight );
		GL_DrawElements( parms->progAdaptiveGlareGauss,
			parms->unitSquareTris, GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	}
	GL_SetRenderDestination( parms->renderDestDefault );
}
