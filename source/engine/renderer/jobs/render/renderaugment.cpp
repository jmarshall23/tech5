#include "renderaugment.h"

#include "../../renderer_d3d9.h"
#include "../../rendermodelcommitted.h"
#include "parmstate.h"

void RenderAugment( const renderAugmentParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipAugment || parms->progColorParmOnly == nullptr ||
			renderThreadParmState == nullptr ) return;
	GL_SetRenderDestination( parms->renderDestAugment != nullptr
		? parms->renderDestAugment : parms->renderDestDefault );
	for ( int modelIndex = 0; modelIndex < parms->numViewAugmentModels;
			++modelIndex ) {
		const idRenderModelCommitted * const model =
			parms->viewAugmentModels[modelIndex];
		if ( model == nullptr ) continue;
		renderThreadParmState->SetModelMatrix( model->modelMatrix );
		renderThreadParmState->SetInverseModelMatrix( model->inverseModelMatrix );
		renderThreadParmState->SetMVPMatrix( model->mvpMatrix );
		for ( int surfaceIndex = 0; surfaceIndex < model->surfaces.Num();
				++surfaceIndex ) {
			const idRenderModelSurface & surface = model->surfaces[surfaceIndex];
			if ( surface.geometry != nullptr ) GL_DrawElements(
				parms->progColorParmOnly, &surface,
				GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
		}
	}
	GL_SetRenderDestination( parms->renderDestDefault );
}
