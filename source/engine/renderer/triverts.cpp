#include "triangles.h"

#include <cstring>

int SwapVertexBuffer( void *, const int numVerts, const int ) {
	// Xbox swapped packed streams to big endian.  Native D3D9 consumes the
	// little-endian PC stream directly.
	return numVerts;
}

void PackToVertexFormat( const idDrawVert * source, void * destination,
	const int numVerts, const int ) {
	if ( source == nullptr || destination == nullptr || numVerts <= 0 ) return;
	std::memcpy( destination, source, numVerts * sizeof( idDrawVert ) );
}

void TransferVerts( const int, const int numVerts,
	const idVertexScaleAndBias * scaleAndBias, const int sourceStride,
	const bool, const void * source, void * destination ) {
	if ( source == nullptr || destination == nullptr || numVerts <= 0 ) return;
	const int stride = sourceStride > 0 ? sourceStride : sizeof( idDrawVert );
	for ( int index = 0; index < numVerts; ++index ) {
		idDrawVert vertex;
		std::memcpy( &vertex,
			static_cast< const unsigned char * >( source ) + index * stride,
			sizeof( idDrawVert ) );
		if ( scaleAndBias != nullptr ) {
			vertex.xyz.Set(
				vertex.xyz.x * scaleAndBias->xyzScale.x + scaleAndBias->xyzBias.x,
				vertex.xyz.y * scaleAndBias->xyzScale.y + scaleAndBias->xyzBias.y,
				vertex.xyz.z * scaleAndBias->xyzScale.z + scaleAndBias->xyzBias.z );
			vertex.st.Set(
				vertex.st.x * scaleAndBias->stScale.x + scaleAndBias->stBias.x,
				vertex.st.y * scaleAndBias->stScale.y + scaleAndBias->stBias.y );
		}
		static_cast< idDrawVert * >( destination )[index] = vertex;
	}
}
