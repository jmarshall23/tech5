#include "renderwalkbsp.h"

#include <algorithm>

int GL_GetDeferredQueryResult( std::int64_t queryNumber );

void RenderWalkBSP( const renderWalkBSPParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->numNodeWorldAreas == nullptr ||
			parms->nodeWorldAreas == nullptr ) return;
	*parms->numNodeWorldAreas = 0;
	if ( parms->numWorldAreas <= 0 ) return;
	if ( parms->settings->singleWorldArea >= 0 ) {
		parms->nodeWorldAreas[0].areaNum = static_cast< short >(
			std::min( parms->settings->singleWorldArea,
				parms->numWorldAreas - 1 ) );
		parms->nodeWorldAreas[0].nodeOcclusionTestIndex = -1;
		*parms->numNodeWorldAreas = 1;
		return;
	}
	if ( !parms->settings->isComboMap || parms->areaNodes == nullptr ||
			parms->numAreaNodes <= 0 ) {
		for ( int area = 0; area < parms->numWorldAreas && area < 8192; ++area ) {
			parms->nodeWorldAreas[area].areaNum = static_cast< short >( area );
			parms->nodeWorldAreas[area].nodeOcclusionTestIndex = -1;
		}
		*parms->numNodeWorldAreas = std::min( parms->numWorldAreas, 8192 );
		return;
	}

	struct stackEntry_t { int node; short querySlot; };
	stackEntry_t stack[128];
	int stackCount = 0;
	stack[stackCount++] = { 0, -1 };
	while ( stackCount > 0 && *parms->numNodeWorldAreas < 8192 ) {
		const stackEntry_t entry = stack[--stackCount];
		if ( entry.node < 0 ) {
			const int area = -1 - entry.node;
			if ( area >= 0 && area < parms->numWorldAreas ) {
				nodeWorldArea_t & output =
					parms->nodeWorldAreas[( *parms->numNodeWorldAreas )++];
				output.areaNum = static_cast< short >( area );
				output.nodeOcclusionTestIndex = entry.querySlot;
			}
			continue;
		}
		if ( entry.node >= parms->numAreaNodes ) continue;
		if ( !parms->settings->skipNodeCPUCulling &&
				parms->areaNodeBoundsCulled[entry.node] != 0 ) continue;

		short querySlot = entry.querySlot;
		const int queryIndex = parms->areaNodeOcclusionIndex != nullptr
			? parms->areaNodeOcclusionIndex[entry.node] : -1;
		if ( queryIndex >= 0 && queryIndex < 64 &&
				!parms->settings->skipNodeGPUCulling ) {
			querySlot = static_cast< short >( *parms->numOcclusionTestNodes );
			if ( *parms->numOcclusionTestNodes < 64 )
				parms->occlusionTestNodes[
					( *parms->numOcclusionTestNodes )++] = entry.node;
			const std::int64_t query = parms->areaNodeOcclusionQuery[queryIndex];
			if ( query >= parms->renderView->firstOcclusionQueryInPreviousFrame &&
					GL_GetDeferredQueryResult( query ) == 0 ) continue;
		}

		const areaNode_t & node = parms->areaNodes[entry.node];
		const idVec3 viewOrigin( parms->settings->viewOrigin.x,
			parms->settings->viewOrigin.y, parms->settings->viewOrigin.z );
		const int nearSide = node.plane.Distance( viewOrigin ) < 0.0f ? 1 : 0;
		const int farSide = nearSide ^ 1;
		if ( stackCount + 2 <= 128 ) {
			stack[stackCount++] = { node.children[farSide], querySlot };
			stack[stackCount++] = { node.children[nearSide], querySlot };
		}
	}
}
