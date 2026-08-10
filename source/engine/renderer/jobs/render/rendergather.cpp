#include "rendergather.h"

#include "../../renderer_d3d9.h"
#include "../../renderlightcommitted.h"
#include "../../rendermodelcommitted.h"

#include <array>
#include <cmath>

namespace {
	bool BoundsIntersect( const idBounds & left, const idBounds & right ) {
		return left[0].x <= right[1].x && left[1].x >= right[0].x &&
			left[0].y <= right[1].y && left[1].y >= right[0].y &&
			left[0].z <= right[1].z && left[1].z >= right[0].z;
	}

	bool InRange( const idVec4 & range, const idVec4 & viewOrigin ) {
		if ( range.w >= 262144.0f ) return true;
		const float x = range.x - viewOrigin.x;
		const float y = range.y - viewOrigin.y;
		const float z = range.z - viewOrigin.z;
		return x * x + y * y + z * z <= range.w * range.w;
	}

	template< typename T >
	void AppendBounded( T ** output, int * count, int capacity, T * value ) {
		if ( output != nullptr && count != nullptr && *count < capacity )
			output[( *count )++] = value;
	}
}

bool InterpretOcclusionQuery( const renderSettings_t * settings,
		const idRenderView * renderView, std::int64_t queryNumber,
		bool forceVisible, int * result ) {
	if ( settings == nullptr || renderView == nullptr || forceVisible ) {
		if ( result != nullptr ) *result = 1;
		return true;
	}
	if ( queryNumber < renderView->firstOcclusionQueryInPreviousFrame ) {
		if ( result != nullptr ) *result = 1;
		return true;
	}
	const int samples = GL_GetDeferredQueryResult( queryNumber );
	if ( result != nullptr ) *result = samples;
	return samples < 0 || samples >= settings->queryThreshold;
}

void RenderGather( const renderGatherParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr ) return;
	if ( parms->numViewWorldAreas != nullptr ) *parms->numViewWorldAreas = 0;
	if ( parms->numViewWorldSurfaces != nullptr ) *parms->numViewWorldSurfaces = 0;
	if ( parms->numViewModels != nullptr ) *parms->numViewModels = 0;
	if ( parms->numSceneModels != nullptr ) *parms->numSceneModels = 0;
	if ( parms->numViewAugmentModels != nullptr ) *parms->numViewAugmentModels = 0;
	if ( parms->numViewLights != nullptr ) *parms->numViewLights = 0;
	if ( parms->numOcclusionTestWorldAreas != nullptr )
		*parms->numOcclusionTestWorldAreas = 0;
	if ( parms->numOcclusionTestModels != nullptr )
		*parms->numOcclusionTestModels = 0;
	if ( parms->numOcclusionTestLights != nullptr )
		*parms->numOcclusionTestLights = 0;

	std::array< bool, 4096 > modelSeen = {};
	std::array< bool, 4096 > lightSeen = {};
	const int viewID = parms->renderView->r.viewID;

	if ( !parms->settings->skipWorld && parms->linkedRenderModels != nullptr &&
			parms->numLinkedRenderModels > 0 && parms->linkedRenderModels[0] != nullptr ) {
		AppendBounded( parms->viewModels, parms->numViewModels, 4096,
			parms->linkedRenderModels[0] );
		modelSeen[0] = true;
	}

	for ( int nodeIndex = 0; nodeIndex < parms->numNodeWorldAreas; ++nodeIndex ) {
		const int areaNum = parms->nodeWorldAreas[nodeIndex].areaNum;
		if ( areaNum < 0 || areaNum >= parms->numWorldAreas ) continue;
		if ( !parms->settings->skipAreaCPUCulling &&
				parms->worldAreaSubspaceBoundsCulled[areaNum] != 0 ) continue;
		const worldArea_t & area = parms->worldAreas[areaNum];

		if ( !parms->settings->skipWorld &&
				( parms->settings->skipAreaCPUCulling ||
					parms->worldAreaGeometryBoundsCulled[areaNum] != 3 ) ) {
			int queryResult = 0;
			const bool forceVisible = parms->settings->skipAreaGPUCulling ||
				parms->worldAreaGeometryBoundsCulled[areaNum] == 0 ||
				parms->occlusionState == nullptr;
			const std::int64_t query = parms->occlusionState != nullptr
				? parms->occlusionState->worldAreaOcclusionQuery[areaNum] : -1;
			if ( InterpretOcclusionQuery( parms->settings, parms->renderView,
					query, forceVisible, &queryResult ) ) {
				if ( parms->nodeWorldAreas[nodeIndex].nodeOcclusionTestIndex >= 0 &&
						parms->occlusionTestNodes != nullptr )
					parms->occlusionTestNodes[
						parms->nodeWorldAreas[nodeIndex].nodeOcclusionTestIndex] = -1;
				if ( parms->numViewWorldAreas != nullptr &&
						*parms->numViewWorldAreas < 8192 ) {
					viewWorldArea_t & output = parms->viewWorldAreas[
						( *parms->numViewWorldAreas )++];
					output.areaNum = areaNum;
					output.numSurfs = static_cast< short >( area.worldSurfaces.Num() );
					output.skipDetailTriangles =
						parms->worldAreaGeometryBoundsCulled[areaNum] == 2;
				}
				for ( int surfaceIndex = 0;
						surfaceIndex < area.worldSurfaces.Num(); ++surfaceIndex ) {
					if ( parms->numViewWorldSurfaces != nullptr &&
							*parms->numViewWorldSurfaces < 8192 )
						parms->viewWorldSurfaces[
							( *parms->numViewWorldSurfaces )++] =
							&area.worldSurfaces[surfaceIndex];
				}
			} else if ( parms->numOcclusionTestWorldAreas != nullptr &&
					*parms->numOcclusionTestWorldAreas < 4096 ) {
				parms->occlusionTestWorldAreas[
					( *parms->numOcclusionTestWorldAreas )++] = areaNum;
			}
		}

		for ( int referenceIndex = 0; referenceIndex < area.drawModelRefs.Num();
				++referenceIndex ) {
			const int modelIndex = area.drawModelRefs[referenceIndex].GetIndex();
			if ( modelIndex < 0 || modelIndex >= parms->numLinkedRenderModels ||
					modelIndex >= 4096 || modelSeen[modelIndex] ) continue;
			modelSeen[modelIndex] = true;
			const idRenderModelCommitted * const model =
				parms->linkedRenderModels[modelIndex];
			if ( model == nullptr || !model->mayBeDrawn ||
					( parms->settings->singleModel >= 0 &&
						parms->settings->singleModel != modelIndex ) ||
					( model->r.allowSurfaceOnlyInViewID != 0 &&
						model->r.allowSurfaceOnlyInViewID != viewID ) ||
					( model->r.suppressSurfaceInViewID != 0 &&
						model->r.suppressSurfaceInViewID == viewID ) ||
					( !parms->settings->skipModelRangeCulling &&
						!InRange( model->maxVisibleRange,
							parms->settings->viewOrigin ) ) ) continue;
			unsigned char cullBits = 0;
			if ( !parms->settings->skipModelCPUCulling && !model->r.addAlways &&
					idRenderMatrix::CullBoundsToMVPbits(
						parms->renderView->worldSpaceMVPMatrix,
						model->globalReferenceBounds, &cullBits, false ) ) continue;
			int queryResult = 0;
			const bool visible = InterpretOcclusionQuery( parms->settings,
				parms->renderView,
				parms->occlusionState != nullptr
					? parms->occlusionState->modelOcclusionQuery[modelIndex] : -1,
				parms->settings->skipModelGPUCulling || model->r.noGPUocclusionTest ||
					parms->occlusionState == nullptr ||
					BoundsIntersect( model->globalReferenceBounds,
						parms->settings->viewBounds ), &queryResult );
			if ( !visible ) {
				AppendBounded( parms->occlusionTestModels,
					parms->numOcclusionTestModels, 4096, model );
				continue;
			}
			if ( model->r.isSceneModel )
				AppendBounded( parms->sceneModels, parms->numSceneModels, 64, model );
			else if ( model->r.isAugment )
				AppendBounded( parms->viewAugmentModels,
					parms->numViewAugmentModels, 32, model );
			else
				AppendBounded( parms->viewModels, parms->numViewModels, 4096, model );
		}

		for ( int referenceIndex = 0; referenceIndex < area.drawLightRefs.Num();
				++referenceIndex ) {
			const int lightIndex = area.drawLightRefs[referenceIndex].GetIndex();
			if ( lightIndex < 0 || lightIndex >= parms->numLinkedRenderLights ||
					lightIndex >= 4096 || lightSeen[lightIndex] ) continue;
			lightSeen[lightIndex] = true;
			const idRenderLightCommitted * const light =
				parms->linkedRenderLights[lightIndex];
			if ( light == nullptr ||
					( parms->settings->singleLight >= 0 &&
						parms->settings->singleLight != lightIndex ) ||
					( light->r.allowLightOnlyInViewID != 0 &&
						light->r.allowLightOnlyInViewID != viewID ) ||
					( light->r.suppressLightInViewID != 0 &&
						light->r.suppressLightInViewID == viewID ) ||
					( !parms->settings->skipLightRangeCulling &&
						!InRange( light->maxVisibleRange,
							parms->settings->viewOrigin ) ) ) continue;
			unsigned char cullBits = 0;
			if ( !parms->settings->skipLightCPUCulling &&
					idRenderMatrix::CullBoundsToMVPbits(
						parms->renderView->worldSpaceMVPMatrix,
						light->globalReferenceBounds, &cullBits, false ) ) continue;
			int queryResult = 0;
			if ( InterpretOcclusionQuery( parms->settings, parms->renderView,
					parms->occlusionState != nullptr
						? parms->occlusionState->lightOcclusionQuery[lightIndex] : -1,
					parms->settings->skipLightGPUCulling ||
						parms->occlusionState == nullptr ||
						BoundsIntersect( light->globalReferenceBounds,
							parms->settings->viewBounds ), &queryResult ) ) {
				AppendBounded( parms->viewLights, parms->numViewLights, 4096, light );
			} else {
				AppendBounded( parms->occlusionTestLights,
					parms->numOcclusionTestLights, 512, light );
			}
		}
	}

	if ( !parms->settings->skipAddAlways ) {
		for ( const idRenderModelCommitted * model = parms->addAlwaysModels;
				model != nullptr && model->nextAddAlwaysModel != model;
				model = model->nextAddAlwaysModel ) {
			if ( model->r.isAugment )
				AppendBounded( parms->viewAugmentModels,
					parms->numViewAugmentModels, 32, model );
			else if ( model->r.isSceneModel )
				AppendBounded( parms->sceneModels, parms->numSceneModels, 64, model );
			else
				AppendBounded( parms->viewModels,
					parms->numViewModels, 4096, model );
		}
	}
}
