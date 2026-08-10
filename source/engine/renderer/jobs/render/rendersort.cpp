#include "rendersort.h"

#include <algorithm>
#include <cstdint>

namespace {
	bool SurfaceLess( const drawSurf_t * left, const drawSurf_t * right ) {
		if ( left->sort != right->sort ) return left->sort < right->sort;
		const std::uintptr_t leftModel = reinterpret_cast< std::uintptr_t >(
			left->model );
		const std::uintptr_t rightModel = reinterpret_cast< std::uintptr_t >(
			right->model );
		if ( leftModel != rightModel ) return leftModel < rightModel;
		return reinterpret_cast< std::uintptr_t >( left->modelSurface ) <
			reinterpret_cast< std::uintptr_t >( right->modelSurface );
	}

	int FirstAtOrAbove( drawSurf_t * const * surfaces, int first, int count,
			float threshold ) {
		while ( first < count && surfaces[first]->sort < threshold ) ++first;
		return first;
	}
}

void RenderSort( const renderSortParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->sortedDrawSurfs == nullptr || parms->renderPasses == nullptr )
		return;
	const int count = std::max( parms->numDrawSurfs, 0 );
	for ( int index = 0; index < count; ++index )
		parms->sortedDrawSurfs[index] = &parms->drawSurfs[index];
	std::sort( parms->sortedDrawSurfs, parms->sortedDrawSurfs + count,
		SurfaceLess );
	int first = 0;
	parms->renderPasses[RENDERPASS_CLEAR].firstSurface = 0;
	parms->renderPasses[RENDERPASS_CLEAR].lastSurface = -1;
	const float thresholds[4] = { parms->settings->sortEmitOnly,
		parms->settings->sortLight, parms->settings->sortPerturber,
		parms->settings->sortLast };
	for ( int pass = RENDERPASS_EMISSIVE; pass < NUM_RENDER_PASSES; ++pass ) {
		parms->renderPasses[pass].firstSurface = first;
		first = FirstAtOrAbove( parms->sortedDrawSurfs, first, count,
			thresholds[pass - RENDERPASS_EMISSIVE] );
		parms->renderPasses[pass].lastSurface = first - 1;
	}
}
