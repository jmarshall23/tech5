#include "renderdepth.h"

#include "../../declmaterial.h"
#include "../../declrenderprog.h"
#include "../../renderer_d3d9.h"
#include "../../rendermodelcommitted.h"
#include "../../renderview.h"
#include "parmstate.h"

#include <algorithm>

namespace {
	bool BinarySurfaceEnabled( const renderDepthParms_t * parms,
			const idRenderModelSurface & surface ) {
		return parms->binaryModelState == nullptr || surface.binaryModelId < 0 ||
			parms->binaryModelState[surface.binaryModelId];
	}

	void AddDrawSurface( const renderDepthParms_t * parms,
			const idRenderModelCommitted * model,
			const idRenderModelSurface * surface, const idMaterial * material,
			const idDeclRenderProg * program, float sort,
			bool skipDetailTriangles, float & sortOffset ) {
		if ( program == nullptr || parms->drawSurfs == nullptr ||
				parms->numDrawSurfs == nullptr || *parms->numDrawSurfs >= 4096 )
			return;
		drawSurf_t & output = parms->drawSurfs[( *parms->numDrawSurfs )++];
		output.sort = sort + sortOffset;
		output.isWorld = model->r.isWorld != 0;
		output.skipDetailTriangles = skipDetailTriangles;
		output.model = model;
		output.modelSurface = surface;
		output.material = material;
		output.prog = program;
		sortOffset += 0.0001f;
	}

	void DrawDepthSurface( const renderDepthParms_t * parms,
			const idRenderModelCommitted * model,
			const idRenderModelSurface * surface, bool cullSurface,
			bool testOcclusion, bool skipDetailTriangles, float & sortOffset ) {
		if ( model == nullptr || surface == nullptr || surface->geometry == nullptr ||
				surface->material == nullptr ) return;
		const idMaterial * const material = surface->material;
		if ( material->Coverage() == MC_INVISIBLE ) return;
		unsigned char cullBits = 0;
		if ( cullSurface && !model->r.addAlways && surface->joints == nullptr &&
				!parms->settings->skipSurfaceCPUCulling &&
				idRenderMatrix::CullBoundsToMVPbits( model->mvpMatrix,
					surface->geometry->bounds, &cullBits, false ) ) return;

		AddDrawSurface( parms, model, surface, material,
			material->GetProgram( MPR_ADD ), material->stageSort[MPR_ADD],
			skipDetailTriangles, sortOffset );
		AddDrawSurface( parms, model, surface, material,
			material->GetProgram( MPR_BLEND ), material->stageSort[MPR_BLEND],
			skipDetailTriangles, sortOffset );
		const float stageSort = material->stageSort[MPR_STAGE];
		if ( material->GetProgram( MPR_STAGE ) != nullptr &&
				!( material->materialHasMergeableBlendedPass &&
				model->r.isWorld && !model->r.megatexturedModel &&
				parms->settings->isComboMap ) &&
				!( stageSort >= parms->settings->sortCoverage &&
					stageSort < parms->settings->sortBackground ) ) {
			AddDrawSurface( parms, model, surface, material,
				material->GetProgram( MPR_STAGE ), stageSort,
				skipDetailTriangles, sortOffset );
		}
		if ( model->r.modelFade != 1.0f &&
				material->GetProgram( MPR_FADE_PERTURB ) != nullptr ) {
			AddDrawSurface( parms, model, surface, material,
				material->GetProgram( MPR_FADE_PERTURB ),
				parms->settings->sortPerturber,
				skipDetailTriangles, sortOffset );
		}

		const idDeclRenderProg * program = material->Coverage() == MC_TRANSLUCENT
			? ( testOcclusion ? material->GetProgram( MPR_DEPTH_FILL ) : nullptr )
			: material->GetProgram( MPR_AMBIENT );
		if ( program == nullptr && material->Coverage() != MC_TRANSLUCENT )
			program = material->GetProgram( MPR_STAGE );
		if ( program == nullptr ) return;
		program = program->renamed != nullptr ? program->renamed : program;
		if ( model->r.radiosityPreview && program == parms->progOutside &&
				parms->progRadiosityPreview != nullptr )
			program = parms->progRadiosityPreview;
		glStateBits_t state = GLS_DEFAULT;
		if ( material->IsTwoSided() || parms->settings->forceTwoSidedDepth )
			state |= GLS_CULL_TWOSIDED;
		if ( model->r.isSky || ( stageSort >= parms->settings->sortSkybox &&
				stageSort < parms->settings->sortBackground ) ) state |= GLS_DEPTHMASK;
		const idParmBlock & materialParms = *material->GetRenderParmBlock();
		renderThreadParmState->VirtualEvaluateParmBlock(
			materialParms, materialParms );
		renderThreadParmState->VirtualEvaluateParmBlock(
			program->parmBlock, program->parmBlock );
		GL_DrawElements( program, surface, state, skipDetailTriangles );
		renderThreadParmState->VirtualRollbackParmBlock(
			program->parmBlock, program->parmBlock );
		renderThreadParmState->VirtualRollbackParmBlock(
			materialParms, materialParms );
	}

	void DrawModelDepthSurfaces( const renderDepthParms_t * parms,
			const idRenderModelCommitted * model, float & sortOffset ) {
		if ( model == nullptr || renderThreadParmState == nullptr ) return;
		renderThreadParmState->SetModelMatrix( model->modelMatrix );
		renderThreadParmState->SetInverseModelMatrix( model->inverseModelMatrix );
		renderThreadParmState->SetMVPMatrix( model->mvpMatrix );
		renderThreadParmState->SetApproximateLighting( model->approximateLighting );
		renderThreadParmState->SetHighlightColor( model->highlightColor );
		renderThreadParmState->VirtualEvaluateParmBlock(
			model->renderParmBlock, model->renderParmBlock );
		const bool query = !model->r.alwaysOcclusionCullBounds &&
			( !model->r.addAlways || model->r.addAlwaysForceOcclusionQuery );
		if ( query && parms->occlusionState != nullptr && model->index.IsValid() )
			GL_BeginQuery( &parms->occlusionState->modelOcclusionQuery[
				model->index.GetIndex()] );
		const bool cullSurface = model->surfaces.Num() <= 1;
		for ( int index = 0; index < model->surfaces.Num(); ++index ) {
			if ( parms->settings->singleSurface >= 0 &&
					parms->settings->singleSurface != index ) continue;
			DrawDepthSurface( parms, model, &model->surfaces[index], cullSurface,
				query, false, sortOffset );
		}
		if ( query ) GL_EndQuery();
		renderThreadParmState->VirtualRollbackParmBlock(
			model->renderParmBlock, model->renderParmBlock );
	}
}

void RenderDepth( const renderDepthParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr || renderThreadParmState == nullptr ) return;
	GL_SetDefaultState();
	GL_SetRenderDestination( parms->renderDestDefault );
	const idScreenRect & viewport = parms->renderView->viewport;
	GL_Viewport( viewport.x1, viewport.y1,
		viewport.x2 - viewport.x1 + 1, viewport.y2 - viewport.y1 + 1 );
	const idScreenRect & test = parms->renderView->testScissor;
	const idScreenRect & scissor = test.x1 <= test.x2 && test.y1 <= test.y2
		? test : parms->renderView->scissorRect;
	GL_Scissor( scissor.x1, scissor.y1,
		scissor.x2 - scissor.x1 + 1, scissor.y2 - scissor.y1 + 1 );
	for ( int clear = 0; clear < parms->extraClears; ++clear )
		GL_Clear( true, true, true, 0, 0.0f, 0.0f, 0.0f, 0.0f );
	if ( parms->extraClears == 0 )
		GL_Clear( false, true, true, 0, 0.0f, 0.0f, 0.0f, 0.0f );
	GL_BeginQueryBatch();
	GL_BindTexture( parms->imgBlack, 0 );
	renderThreadParmState->SetPositionToFeedback(
		parms->renderView->renderWidth, parms->renderView->renderHeight,
		parms->renderView->feedbackWidth, parms->renderView->feedbackHeight );
	float sortOffset = 0.0f;
	for ( int index = 0; index < parms->numSceneModels; ++index )
		DrawModelDepthSurfaces( parms, parms->sceneModels[index], sortOffset );

	const idRenderModelCommitted * const worldModel =
		parms->numViewModels > 0 ? parms->viewModels[0] : nullptr;
	if ( worldModel != nullptr ) {
		renderThreadParmState->SetModelMatrix( worldModel->modelMatrix );
		renderThreadParmState->SetInverseModelMatrix( worldModel->inverseModelMatrix );
		renderThreadParmState->SetMVPMatrix( worldModel->mvpMatrix );
		renderThreadParmState->SetApproximateLighting(
			worldModel->approximateLighting );
		int surfaceOffset = 0;
		for ( int areaIndex = 0; areaIndex < parms->numViewWorldAreas; ++areaIndex ) {
			const viewWorldArea_t & area = parms->viewWorldAreas[areaIndex];
			if ( parms->occlusionState != nullptr && area.areaNum >= 0 )
				GL_BeginQuery( &parms->occlusionState->worldAreaOcclusionQuery[
					area.areaNum] );
			for ( int surfaceIndex = 0; surfaceIndex < area.numSurfs;
					++surfaceIndex, ++surfaceOffset ) {
				const idRenderModelSurface * const surface =
					parms->viewWorldSurfaces[surfaceOffset];
				if ( surface != nullptr && BinarySurfaceEnabled( parms, *surface ) )
					DrawDepthSurface( parms, worldModel, surface,
						area.numSurfs <= 1, true,
						area.skipDetailTriangles, sortOffset );
			}
			GL_EndQuery();
		}
		if ( !parms->settings->skipOcclusionBaseModel &&
				parms->occlusionBaseTriangles != nullptr &&
				parms->progOccluderDepthOnly != nullptr ) {
			GL_DrawElements( parms->progOccluderDepthOnly,
				parms->occlusionBaseTriangles,
				GLS_CULL_TWOSIDED | GLS_COLORMASK, false );
		}
	}
	for ( int index = worldModel != nullptr ? 1 : 0;
			index < parms->numViewModels; ++index )
		DrawModelDepthSurfaces( parms, parms->viewModels[index], sortOffset );
}
