#include "rendercull.h"

#include "../../renderview.h"

namespace {
	bool Intersects( const idBounds & left, const idBounds & right ) {
		return left[0].x <= right[1].x && left[1].x >= right[0].x &&
			left[0].y <= right[1].y && left[1].y >= right[0].y &&
			left[0].z <= right[1].z && left[1].z >= right[0].z;
	}
}

void RenderCull( const renderCullParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->renderView == nullptr ) return;
	const idRenderMatrix & mvp = parms->renderView->worldSpaceMVPMatrix;
	for ( int index = 0; index < parms->numAreaNodes; ++index ) {
		unsigned char bits = 0;
		parms->areaNodeBoundsCulled[index] =
			idRenderMatrix::CullBoundsToMVPbits( mvp,
				parms->areaNodeBounds[index], &bits, false ) ? 1 : 0;
	}
	for ( int index = 0; index < parms->numWorldAreas; ++index ) {
		unsigned char bits = 0;
		unsigned char subspaceBits = 0;
		const bool subspaceCulled = idRenderMatrix::CullBoundsToMVPbits( mvp,
			parms->worldAreaSubspaceBounds[index], &subspaceBits, false );
		parms->worldAreaSubspaceBoundsCulled[index] =
			subspaceCulled ? 1 : 0;
		if ( subspaceCulled || idRenderMatrix::CullBoundsToMVPbits( mvp,
				parms->worldAreaGeometryBounds[index], &bits, false ) ) {
			parms->worldAreaGeometryBoundsCulled[index] = 3;
		} else if ( !Intersects( parms->worldAreaGeometryBounds[index],
				parms->settings->detailBounds ) ) {
			parms->worldAreaGeometryBoundsCulled[index] = 2;
		} else {
			parms->worldAreaGeometryBoundsCulled[index] =
				Intersects( parms->worldAreaGeometryBounds[index],
					parms->settings->viewBounds ) ? 0 : 1;
		}
	}
}
