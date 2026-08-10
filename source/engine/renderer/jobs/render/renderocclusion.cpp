#include "renderocclusion.h"

#include "../../declrenderprog.h"
#include "../../renderer_d3d9.h"
#include "../../renderlightcommitted.h"
#include "../../rendermodelcommitted.h"
#include "parmstate.h"

namespace {
	void DrawBoundsQuery( const renderOcclusionParms_t * parms,
			const idBounds & bounds, std::int64_t * queryNumber,
			const idTriangles * cube ) {
		if ( queryNumber == nullptr || cube == nullptr ||
				parms->progDepthOnly == nullptr || renderThreadParmState == nullptr )
			return;
		idRenderMatrix mvp;
		idRenderMatrix::OffsetScaleForBounds(
			parms->renderView->worldSpaceMVPMatrix, bounds, mvp );
		renderThreadParmState->SetMVPMatrix( mvp );
		GL_BeginQuery( queryNumber );
		const glStateBits_t state = GLS_DEPTHMASK | GLS_CULL_TWOSIDED |
			( parms->settings->showOcclusionBoxes ? 0 : GLS_COLORMASK );
		GL_DrawElements( parms->progDepthOnly, cube, state, false );
		GL_EndQuery();
	}
}

void RenderOcclusion( const renderOcclusionParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr || parms->occlusionState == nullptr ) return;
	GL_SetRenderDestination( parms->renderDestDefault );
	GL_BeginQueryBatch();
	for ( int index = 0; index < parms->numOcclusionTestNodes; ++index ) {
		const int node = parms->occlusionTestNodes[index];
		if ( node < 0 || parms->areaNodeOcclusionIndex == nullptr ) continue;
		const int queryIndex = parms->areaNodeOcclusionIndex[node];
		if ( queryIndex < 0 || queryIndex >= 64 ) continue;
		DrawBoundsQuery( parms, parms->areaNodeBounds[node],
			&parms->occlusionState->nodeOcclusionQuery[queryIndex],
			parms->unitCubeTris );
	}
	for ( int index = 0; index < parms->numOcclusionTestWorldAreas; ++index ) {
		const int area = parms->occlusionTestWorldAreas[index];
		if ( area < 0 || area >= parms->numWorldAreas ) continue;
		DrawBoundsQuery( parms, parms->worldAreaGeometryBounds[area],
			&parms->occlusionState->worldAreaOcclusionQuery[area],
			parms->unitCubeTris );
	}
	for ( int index = 0; index < parms->numOcclusionTestModels; ++index ) {
		const idRenderModelCommitted * const model =
			parms->occlusionTestModels[index];
		if ( model == nullptr || !model->index.IsValid() ) continue;
		DrawBoundsQuery( parms, model->globalReferenceBounds,
			&parms->occlusionState->modelOcclusionQuery[model->index.GetIndex()],
			parms->unitCubeTris );
	}
	for ( int index = 0; index < parms->numOcclusionTestLights; ++index ) {
		const idRenderLightCommitted * const light =
			parms->occlusionTestLights[index];
		if ( light == nullptr || !light->index.IsValid() ) continue;
		DrawBoundsQuery( parms, light->globalReferenceBounds,
			&parms->occlusionState->lightOcclusionQuery[light->index.GetIndex()],
			parms->zeroOneCubeTris != nullptr
				? parms->zeroOneCubeTris : parms->unitCubeTris );
	}
}
