#include "../sound_local.h"

void SoundRoutingJob( soundRoutingParms_t & parms ) {
	if ( parms.route == NULL || parms.numAreas <= 0 ) return;
	for ( int i = 0; i < parms.numAreas; ++i ) parms.route[ i ] = 0;
	if ( parms.listenerAreaNum <= 0 || parms.listenerAreaNum >= parms.numAreas ) return;

	const float infinite = ( std::numeric_limits< float >::max )();
	idList< float, 38 > distance;
	idList< unsigned char, 38 > closed;
	distance.SetNum( parms.numAreas ); closed.SetNum( parms.numAreas );
	for ( int i = 0; i < parms.numAreas; ++i ) { distance[ i ] = infinite; closed[ i ] = 0; }
	distance[ parms.listenerAreaNum ] = 0.0f;

	for ( int pass = 0; pass < parms.numAreas; ++pass ) {
		int areaNum = -1;
		for ( int i = 1; i < parms.numAreas; ++i ) {
			if ( !closed[ i ] && ( areaNum < 0 || distance[ i ] < distance[ areaNum ] ) ) areaNum = i;
		}
		if ( areaNum < 0 || distance[ areaNum ] == infinite ) break;
		closed[ areaNum ] = 1;
		const sbspArea_t & area = parms.flatBSP.areas[ areaNum ];
		for ( int f = 0; f < area.numFaces; ++f ) {
			const int signedFace = parms.flatBSP.faceIndex[ area.firstFace + f ];
			const int faceNum = signedFace < 0 ? -signedFace : signedFace;
			if ( faceNum < 0 || faceNum >= parms.flatBSP.numFaces ) continue;
			const sbspFace_t & face = parms.flatBSP.faces[ faceNum ];
			const int adjacent = face.faceAreas[ signedFace >= 0 ? 1 : 0 ];
			if ( adjacent <= 0 || adjacent >= parms.numAreas ) continue;
			const idVec3 center( static_cast< float >( face.center[ 0 ] ),
				static_cast< float >( face.center[ 1 ] ), static_cast< float >( face.center[ 2 ] ) );
			const float dx = center.x - parms.listenerOrigin.x;
			const float dy = center.y - parms.listenerOrigin.y;
			const float dz = center.z - parms.listenerOrigin.z;
			const float candidate = distance[ areaNum ] + std::sqrt( dx * dx + dy * dy + dz * dz );
			if ( candidate < distance[ adjacent ] ) {
				distance[ adjacent ] = candidate;
				parms.route[ adjacent ] = -signedFace;
			}
		}
	}
}
