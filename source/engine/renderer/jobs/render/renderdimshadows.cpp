#include "renderdimshadows.h"

#include "../../declmaterial.h"
#include "../../declrenderparm.h"
#include "../../declrenderprog.h"
#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "../../rendermodelcommitted.h"
#include "parmstate.h"

#include <algorithm>

namespace {
	void SetVector( const idDeclRenderParm * parm, float x, float y,
			float z, float w ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.value[0] = x; value.value[1] = y;
		value.value[2] = z; value.value[3] = w;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}
}

void RenderDimShadows( const renderDimShadowsParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr || parms->settings->showDimShadows < 0 ||
			parms->renderDestDimShadow == nullptr ||
			renderThreadParmState == nullptr ) return;
	if ( parms->numDimShadows != nullptr ) *parms->numDimShadows = 0;
	int shadowIndex = 0;
	for ( const idRenderModelCommitted * model = parms->dimShadowModels;
			model != nullptr && model->nextDimShadowModel != model;
			model = model->nextDimShadowModel, ++shadowIndex ) {
		if ( parms->settings->singleDimShadow >= 0 &&
				parms->settings->singleDimShadow != shadowIndex ) continue;
		if ( !model->CastsDimShadows() ) continue;
		const int modelIndex = model->index.GetIndex();
		if ( parms->modelDimShadowState != nullptr && modelIndex >= 0 )
			parms->modelDimShadowState[modelIndex] = 1;
		GL_SetRenderDestination( parms->renderDestDimShadow );
		const int resolution = std::min( parms->settings->dimShadowResolution,
			std::min( parms->renderDestDimShadow->targetWidth,
				parms->renderDestDimShadow->targetHeight ) );
		GL_Viewport( 0, 0, resolution, resolution );
		GL_Scissor( 0, 0, resolution, resolution );
		GL_Clear( true, true, false, 0, 0.0f, 0.0f, 0.0f, 0.0f );
		SetVector( parms->rpDimShadowFade,
			parms->settings->dimShadowDensity,
			parms->settings->dimShadowFadeVisibilityRange,
			parms->settings->dimShadowMaxVisibleRange, 0.0f );
		SetVector( parms->rpDimShadowExtrude,
			parms->settings->dimShadowLixelScale, 0.0f, 0.0f, 0.0f );
		SetVector( parms->rpDimShadowClipPlane,
			0.0f, 0.0f, 1.0f, model->r.dimShadowClipZ );
		renderThreadParmState->SetModelMatrix( model->modelMatrix );
		renderThreadParmState->SetInverseModelMatrix( model->inverseModelMatrix );
		renderThreadParmState->SetMVPMatrix( model->mvpMatrix );
		for ( int surfaceIndex = 0; surfaceIndex < model->surfaces.Num();
				++surfaceIndex ) {
			const idRenderModelSurface & surface = model->surfaces[surfaceIndex];
			if ( surface.geometry == nullptr || surface.material == nullptr ||
					!surface.material->CastsShadows() ) continue;
			const idDeclRenderProg * program = surface.material->Coverage() ==
				MC_PERFORATED ? parms->progDimShadowCreateAlpha :
				( model->r.woundsActive ? parms->progDimShadowCreateWound :
					parms->progDimShadowCreate );
			if ( program != nullptr ) GL_DrawElements( program, &surface,
				GLS_CULL_TWOSIDED, false );
		}
		GL_SetRenderDestination( parms->renderDestDefault );
		const idDeclRenderProg * drawProgram =
			model->r.allowHighQualityDimShadows &&
			parms->progDimShadowDrawHighQuality != nullptr
				? parms->progDimShadowDrawHighQuality : parms->progDimShadowDraw;
		if ( drawProgram != nullptr && parms->extrudeBox != nullptr )
			GL_DrawElements( drawProgram, parms->extrudeBox,
				GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
		if ( parms->numDimShadows != nullptr ) ++*parms->numDimShadows;
	}
}
