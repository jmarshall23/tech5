#include "../../renderlightparms.h"

#include "../../declmaterial.h"
#include "../../declrenderparm.h"
#include "../../declrenderprog.h"
#include "../../renderer_d3d9.h"
#include "../../renderlightcommitted.h"
#include "../../rendermodelcommitted.h"
#include "../../renderview.h"
#include "parmstate.h"

namespace {
	bool BoundsIntersect( const idBounds & left, const idBounds & right ) {
		return left[0].x <= right[1].x && left[1].x >= right[0].x &&
			left[0].y <= right[1].y && left[1].y >= right[0].y &&
			left[0].z <= right[1].z && left[1].z >= right[0].z;
	}

	void SetParm( const idDeclRenderParm * parm, const idVec4 & value ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t parmValue = {};
		parmValue.value[0] = value.x;
		parmValue.value[1] = value.y;
		parmValue.value[2] = value.z;
		parmValue.value[3] = value.w;
		renderThreadParmState->SetParmValue( parm->parmIndex, parmValue );
	}

	void SetMatrixRows( const idRenderMatrix & matrix,
			const idDeclRenderParm * const rows[4] ) {
		for ( int row = 0; row < 4; ++row )
			SetParm( rows[row], idVec4( matrix.m[row * 4 + 0],
				matrix.m[row * 4 + 1], matrix.m[row * 4 + 2],
				matrix.m[row * 4 + 3] ) );
	}

	void SetLightParms( const renderLightsParms_t * parms,
			const idRenderLightCommitted * light ) {
		const idDeclRenderParm * projection[4] = {
			parms->rpLightProjectionS, parms->rpLightProjectionT,
			parms->rpLightProjectionR, parms->rpLightProjectionQ };
		SetMatrixRows( light->baseLightProject, projection );
		SetParm( parms->rpGlobalLightOrigin, idVec4(
			light->globalLightOrigin.x, light->globalLightOrigin.y,
			light->globalLightOrigin.z, 1.0f ) );
		SetParm( parms->rpStaticSpecularScale,
			idVec4( light->r.staticSpecularScale, 0.0f, 0.0f, 0.0f ) );
		SetParm( parms->rpStaticSpecularVector, idVec4(
			light->r.staticSpecularVector.x, light->r.staticSpecularVector.y,
			light->r.staticSpecularVector.z, 0.0f ) );
		SetParm( parms->rpLightScale, idVec4( light->r.lightRadius.x,
			light->r.lightRadius.y, light->r.lightRadius.z, 1.0f ) );
		SetParm( parms->rpLightTranslation, idVec4( light->r.origin.x,
			light->r.origin.y, light->r.origin.z, 1.0f ) );
	}

	bool SurfaceEnabled( const renderLightsParms_t * parms,
			const idRenderModelSurface & surface ) {
		return parms->binaryModelState == nullptr || surface.binaryModelId < 0 ||
			parms->binaryModelState[surface.binaryModelId];
	}

	void DrawInteractionSurface( const renderLightsParms_t * parms,
			const idRenderLightCommitted * light,
			const idRenderModelCommitted * model,
			const idRenderModelSurface & surface ) {
		if ( surface.geometry == nullptr || surface.material == nullptr ||
				!SurfaceEnabled( parms, surface ) ) return;
		const idMaterial * const material = surface.material;
		const idDeclRenderProg * program = material->GetProgram( MPR_INTERACTION );
		if ( program == nullptr || !material->HasInteractions() ) return;
		program = program->renamed != nullptr ? program->renamed : program;
		const idParmBlock & materialParms = *material->GetRenderParmBlock();
		renderThreadParmState->VirtualEvaluateParmBlock(
			materialParms, materialParms );
		renderThreadParmState->VirtualEvaluateParmBlock(
			program->parmBlock, program->parmBlock );
		glStateBits_t state = GLS_DEPTHMASK | GLS_DEPTHFUNC_EQUAL;
		if ( material->IsTwoSided() ) state |= GLS_CULL_TWOSIDED;
		GL_DrawElements( program, &surface, state, false );
		renderThreadParmState->VirtualRollbackParmBlock(
			program->parmBlock, program->parmBlock );
		renderThreadParmState->VirtualRollbackParmBlock(
			materialParms, materialParms );
		if ( light->castsShadows && material->CastsShadows() &&
				!model->r.noShadow && parms->numShadows != nullptr )
			++*parms->numShadows;
	}

	void DrawModelInteractions( const renderLightsParms_t * parms,
			const idRenderLightCommitted * light,
			const idRenderModelCommitted * model ) {
		if ( model == nullptr || !model->mayMakeInteractions ||
				!BoundsIntersect( light->globalReferenceBounds,
					model->globalReferenceBounds ) ||
				model->r.suppressShadowInLightIndex == light->index.GetIndex() ) return;
		renderThreadParmState->SetModelMatrix( model->modelMatrix );
		renderThreadParmState->SetInverseModelMatrix( model->inverseModelMatrix );
		renderThreadParmState->SetMVPMatrix( model->mvpMatrix );
		renderThreadParmState->SetApproximateLighting( model->approximateLighting );
		renderThreadParmState->VirtualEvaluateParmBlock(
			model->renderParmBlock, model->renderParmBlock );
		for ( int surfaceIndex = 0; surfaceIndex < model->surfaces.Num();
				++surfaceIndex )
			DrawInteractionSurface( parms, light, model,
				model->surfaces[surfaceIndex] );
		renderThreadParmState->VirtualRollbackParmBlock(
			model->renderParmBlock, model->renderParmBlock );
	}
}

void RenderLights( const renderLightsParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr || renderThreadParmState == nullptr ||
			parms->settings->skipLights ) return;
	GL_SetRenderDestination( parms->renderDestDefault );
	if ( parms->numShadows != nullptr ) *parms->numShadows = 0;
	for ( int lightIndex = 0; lightIndex < parms->numViewLights; ++lightIndex ) {
		const idRenderLightCommitted * const light = parms->viewLights[lightIndex];
		if ( light == nullptr || light->lightMtr == nullptr ) continue;
		if ( light->r.lightClass == LIGHT_BLENDED_ONLY &&
				parms->settings->skipBlendLights ) continue;
		if ( light->r.slowLight && parms->settings->skipSlowLights ) continue;
		SetLightParms( parms, light );
		renderThreadParmState->VirtualEvaluateParmBlock(
			light->renderParmBlock, light->renderParmBlock );
		const idParmBlock & lightMaterialParms =
			*light->lightMtr->GetRenderParmBlock();
		renderThreadParmState->VirtualEvaluateParmBlock(
			lightMaterialParms, lightMaterialParms );

		for ( int modelIndex = 0; modelIndex < parms->numViewModels; ++modelIndex )
			DrawModelInteractions( parms, light, parms->viewModels[modelIndex] );
		if ( parms->numViewModels > 0 && parms->viewModels[0] != nullptr ) {
			const idRenderModelCommitted * const worldModel = parms->viewModels[0];
			renderThreadParmState->SetModelMatrix( worldModel->modelMatrix );
			renderThreadParmState->SetInverseModelMatrix(
				worldModel->inverseModelMatrix );
			renderThreadParmState->SetMVPMatrix( worldModel->mvpMatrix );
			for ( int surfaceIndex = 0;
					surfaceIndex < parms->numViewWorldSurfaces; ++surfaceIndex ) {
				const idRenderModelSurface * const surface =
					parms->viewWorldSurfaces[surfaceIndex];
				if ( surface != nullptr ) DrawInteractionSurface(
					parms, light, worldModel, *surface );
			}
		}

		if ( parms->settings->useDeferredSlowMapLighting &&
				parms->zeroOneCubeTris != nullptr ) {
			const idDeclRenderProg * program = light->r.lightType == LIGHT_POINT
				? parms->progDeferredPointLight
				: ( light->r.lightType == LIGHT_PARALLEL
					? parms->progDeferredParallelLight
					: parms->progDeferredSpotLight );
			if ( program != nullptr ) {
				idRenderMatrix mvp;
				idRenderMatrix::OffsetScaleForBounds(
					parms->renderView->worldSpaceMVPMatrix,
					light->globalReferenceBounds, mvp );
				renderThreadParmState->SetMVPMatrix( mvp );
				GL_DrawElements( program, parms->zeroOneCubeTris,
					GLS_DEPTHMASK | GLS_CULL_BACKSIDED, false );
			}
		}
		renderThreadParmState->VirtualRollbackParmBlock(
			lightMaterialParms, lightMaterialParms );
		renderThreadParmState->VirtualRollbackParmBlock(
			light->renderParmBlock, light->renderParmBlock );
	}
}
