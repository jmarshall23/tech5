#include "../sound_local.h"

namespace {
bool TraceNode( const flatSoundBSP_t & bsp, int nodeNum, const idVec3 & start,
	const idVec3 & end, int depth ) {
	if ( nodeNum == 0 ) return true;
	if ( nodeNum < 0 ) return false;
	if ( depth > 1024 || nodeNum >= bsp.numNodes ) return true;
	const sbspNode_t & node = bsp.nodes[ nodeNum ];
	if ( node.planeNum >= static_cast< unsigned int >( bsp.numPlanes ) ) return true;
	const idPlane & plane = bsp.planes[ node.planeNum ];
	const float d0 = plane.a * start.x + plane.b * start.y + plane.c * start.z + plane.d;
	const float d1 = plane.a * end.x + plane.b * end.y + plane.c * end.z + plane.d;
	if ( d0 >= 0.0f && d1 >= 0.0f ) return TraceNode( bsp, node.children[ 0 ], start, end, depth + 1 );
	if ( d0 < 0.0f && d1 < 0.0f ) return TraceNode( bsp, node.children[ 1 ], start, end, depth + 1 );
	const float fraction = d0 / ( d0 - d1 );
	idVec3 middle;
	middle.x = start.x + ( end.x - start.x ) * fraction;
	middle.y = start.y + ( end.y - start.y ) * fraction;
	middle.z = start.z + ( end.z - start.z ) * fraction;
	const int first = d0 >= 0.0f ? 0 : 1;
	return TraceNode( bsp, node.children[ first ], start, middle, depth + 1 ) ||
		TraceNode( bsp, node.children[ first ^ 1 ], middle, end, depth + 1 );
}
}

bool ExternalSoundTrace( const flatSoundBSP_t & bsp, const idVec3 & start, const idVec3 & end ) {
	return bsp.nodes != NULL && bsp.numNodes > 1 && TraceNode( bsp, 1, start, end, 0 );
}

void SoundOcclusionJob( soundOcclusionParms_t & parms ) {
	soundOcclusionResult_t & result = parms.result;
	result.virtualSoundOrigin = parms.soundOrigin;
	const float dx = parms.soundOrigin.x - parms.listenerOrigin.x;
	const float dy = parms.soundOrigin.y - parms.listenerOrigin.y;
	const float dz = parms.soundOrigin.z - parms.listenerOrigin.z;
	result.occludedDistance = std::sqrt( dx * dx + dy * dy + dz * dz );
	result.numPathPoints = 0;
	result.valid = 1;
	if ( !ExternalSoundTrace( parms.flatBSP, parms.listenerOrigin, parms.soundOrigin ) ) return;

	// Retail follows listenerRoute portal centers.  Preserve that behavior with
	// a bounded walk so malformed or cyclic route data cannot stall the mixer.
	int area = parms.soundAreaNum;
	float distance = 0.0f;
	idVec3 previous = parms.soundOrigin;
	for ( int guard = 0; guard < parms.numAreas && area > 0 &&
		area != parms.listenerAreaNum; ++guard ) {
		const int signedFace = parms.listenerRoute != NULL ? parms.listenerRoute[ area ] : 0;
		const int faceNum = signedFace < 0 ? -signedFace : signedFace;
		if ( faceNum <= 0 || faceNum >= parms.flatBSP.numFaces ) break;
		const sbspFace_t & face = parms.flatBSP.faces[ faceNum ];
		idVec3 point( static_cast< float >( face.center[ 0 ] ),
			static_cast< float >( face.center[ 1 ] ), static_cast< float >( face.center[ 2 ] ) );
		const float px = point.x - previous.x, py = point.y - previous.y, pz = point.z - previous.z;
		distance += std::sqrt( px * px + py * py + pz * pz );
		if ( result.pathPoints != NULL && result.numPathPoints < result.maxPathPoints ) {
			result.pathPoints[ result.numPathPoints++ ] = point;
		}
		result.virtualSoundOrigin = point;
		previous = point;
		area = face.faceAreas[ signedFace >= 0 ? 1 : 0 ];
	}
	const float lx = parms.listenerOrigin.x - previous.x;
	const float ly = parms.listenerOrigin.y - previous.y;
	const float lz = parms.listenerOrigin.z - previous.z;
	result.occludedDistance = distance + std::sqrt( lx * lx + ly * ly + lz * lz );
	if ( parms.maxDistance > 0.0f ) result.occludedDistance = ( std::min )( result.occludedDistance, parms.maxDistance );
}

