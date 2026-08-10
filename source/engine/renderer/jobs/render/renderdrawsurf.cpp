#include "renderdrawsurf.h"

#include "../../declmaterial.h"
#include "../../declrenderprog.h"
#include "../../renderer_d3d9.h"
#include "../../rendermodelcommitted.h"
#include "../../renderview.h"
#include "parmstate.h"

void SetupModelMVPMatrix( idRenderMatrix & mvpMatrix,
	const idRenderModelCommitted * model, const idRenderView * renderView,
	float zNear, float zFar );

void idRenderDrawSurf::PopModel() {
	if ( currentModel == nullptr || renderThreadParmState == nullptr ) return;
	renderThreadParmState->VirtualRollbackParmBlock(
		currentModel->renderParmBlock, currentModel->renderParmBlock );
	currentModel = nullptr;
}

void RenderGui( const idRenderModelCommitted * model,
		const renderSettings_t * settings, const idRenderView * renderView,
		bool ) {
	if ( model == nullptr || settings == nullptr || renderView == nullptr ||
			settings->skipGuis || renderThreadParmState == nullptr ) return;
	idRenderMatrix mvp;
	SetupModelMVPMatrix( mvp, model, renderView,
		settings->viewNearZ, settings->viewFarZ );
	renderThreadParmState->SetMVPMatrix( mvp );
	renderThreadParmState->VirtualEvaluateParmBlock(
		model->renderParmBlock, model->renderParmBlock );
	for ( int index = 0; index < model->surfaces.Num(); ++index ) {
		if ( settings->singleGuiSurface >= 0 &&
				settings->singleGuiSurface != index ) continue;
		const idRenderModelSurface & surface = model->surfaces[index];
		const idMaterial * const material = surface.material;
		if ( surface.geometry == nullptr || material == nullptr ) continue;
		const idDeclRenderProg * program = settings->progShowGuiOverdraw != nullptr
			? settings->progShowGuiOverdraw : material->GetProgram( MPR_STAGE );
		if ( program == nullptr ) continue;
		renderThreadParmState->VirtualEvaluateParmBlock(
			*material->GetRenderParmBlock(), *material->GetRenderParmBlock() );
		renderThreadParmState->VirtualEvaluateParmBlock(
			program->parmBlock, program->parmBlock );
		GL_DrawElements( program, surface.geometry,
			settings->progShowGuiOverdraw != nullptr ? 0 : surface.extraGLState );
		renderThreadParmState->VirtualRollbackParmBlock(
			program->parmBlock, program->parmBlock );
		renderThreadParmState->VirtualRollbackParmBlock(
			*material->GetRenderParmBlock(), *material->GetRenderParmBlock() );
	}
	renderThreadParmState->VirtualRollbackParmBlock(
		model->renderParmBlock, model->renderParmBlock );
}

void idRenderDrawSurf::PushModel( const renderDrawSurfParms_t * parms,
		const idRenderModelCommitted * model ) {
	if ( parms == nullptr || model == nullptr ||
			renderThreadParmState == nullptr ) return;
	currentModel = model;
	if ( model->referenceModel != nullptr && !parms->settings->skipInGameGuis &&
			parms->renderDestGui != nullptr ) {
		GL_SetRenderDestination( parms->renderDestGui );
		GL_Clear( true, false, false, 0, 0.0f, 0.0f, 0.0f, 0.0f );
		RenderGui( model->referenceModel, parms->settings, parms->renderView, true );
		CaptureGuiImage( &parms->captureParms );
		GL_SetRenderDestination( parms->renderDestDefault );
		const idScreenRect & viewport = parms->renderView->viewport;
		GL_Viewport( viewport.x1, viewport.y1,
			viewport.x2 - viewport.x1 + 1, viewport.y2 - viewport.y1 + 1 );
		const idScreenRect & scissor = parms->renderView->scissorRect;
		GL_Scissor( scissor.x1, scissor.y1,
			scissor.x2 - scissor.x1 + 1, scissor.y2 - scissor.y1 + 1 );
	}
	renderThreadParmState->SetModelMatrix( model->modelMatrix );
	renderThreadParmState->SetInverseModelMatrix( model->inverseModelMatrix );
	renderThreadParmState->SetMVPMatrix( model->mvpMatrix );
	renderThreadParmState->SetApproximateLighting( model->approximateLighting );
	renderThreadParmState->SetHighlightColor( model->highlightColor );
	renderThreadParmState->VirtualEvaluateParmBlock(
		model->renderParmBlock, model->renderParmBlock );
}

void idRenderDrawSurf::RenderDrawSurf( const renderDrawSurfParms_t * parms,
		const drawSurf_t * surface, glStateBits_t extraState ) {
	if ( parms == nullptr || surface == nullptr || surface->model == nullptr ||
			surface->material == nullptr || surface->prog == nullptr ||
			surface->modelSurface == nullptr || renderThreadParmState == nullptr )
		return;
	if ( surface->model->referenceModel != nullptr && !parms->allowInGameGUIs )
		return;
	if ( currentModel != surface->model ) {
		PopModel();
		PushModel( parms, surface->model );
	}
	const idParmBlock & materialParms =
		*surface->material->GetRenderParmBlock();
	renderThreadParmState->VirtualEvaluateParmBlock(
		materialParms, materialParms );
	if ( renderThreadParmState->values[
			renderThreadParmState->parmIndexIf].value[0] != 0.0f ) {
		const idDeclRenderProg * const program = surface->prog->renamed != nullptr
			? surface->prog->renamed : surface->prog;
		const parmValue_t & polygonOffset = renderThreadParmState->values[
			renderThreadParmState->parmIndexPolygonOffset];
		const bool offset = polygonOffset.value[0] != 0.0f ||
			polygonOffset.value[1] != 0.0f;
		if ( offset ) GL_PolygonOffset( polygonOffset.value[0],
			polygonOffset.value[1], true );
		renderThreadParmState->VirtualEvaluateParmBlock(
			program->parmBlock, program->parmBlock );
		GL_DrawElements( program, surface->modelSurface,
			extraState, surface->skipDetailTriangles );
		renderThreadParmState->VirtualRollbackParmBlock(
			program->parmBlock, program->parmBlock );
		if ( offset ) GL_PolygonOffset( 0.0f, 0.0f, false );
	}
	renderThreadParmState->VirtualRollbackParmBlock(
		materialParms, materialParms );
}
