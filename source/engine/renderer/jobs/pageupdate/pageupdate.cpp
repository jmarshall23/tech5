#include "pageupdate.h"

#include <cstring>

void UpdatePageTables_Xenon( const pageImagesUpdateParms_t * parms ) {
	if ( parms == nullptr || parms->updates == nullptr || parms->numUpdates <= 0 ) return;
	for ( int updateIndex = 0; updateIndex < parms->numUpdates; ++updateIndex ) {
		const pageImagesUpdate_t & update = parms->updates[updateIndex];
		if ( update.cancelled || update.effectivePageLevel < 0 ) continue;
		for ( int level = 0; level <= update.effectivePageLevel && level < 14; ++level ) {
			unsigned char * bits = static_cast< unsigned char * >( update.pageTableImageInfo[level].bits );
			const int bytePitch = update.pageTableImageInfo[level].bytePitch;
			if ( bits == nullptr || bytePitch <= 0 ) continue;
			const int shift = update.effectivePageLevel - level;
			const int size = 1 << shift;
			const int startX = update.spotX << shift;
			const int startY = update.spotY << shift;
			for ( int y = 0; y < size; ++y ) {
				unsigned char * destination = bits + ( startY + y ) * bytePitch + startX * 2;
				for ( int x = 0; x < size; ++x ) {
					// Xbox 360 needed a byte permutation before its big-endian texture
					// upload. D3D9 A8L8/R8G8 surfaces consume the logical X/Y pair.
					destination[x * 2 + 0] = update.pageSpot[0];
					destination[x * 2 + 1] = update.pageSpot[1];
				}
			}
		}
	}
}

void UpdatePageImagesJob( const pageImagesUpdateParms_t * parms ) {
	UpdatePageTables_Xenon( parms );
}
