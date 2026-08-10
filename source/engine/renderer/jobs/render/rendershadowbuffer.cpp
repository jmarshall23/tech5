#include "rendershadowbuffer.h"

#include "idlib/geometry/rendermatrix.h"

#include <algorithm>
#include <cmath>

namespace {
	void SetOrientation( const idVec3 & forward, const idVec3 & right,
			const idVec3 & up, idRenderMatrix & matrix ) {
		matrix.Identity();
		matrix.m[0] = forward.x;
		matrix.m[1] = forward.y;
		matrix.m[2] = forward.z;
		matrix.m[4] = -right.x;
		matrix.m[5] = -right.y;
		matrix.m[6] = -right.z;
		matrix.m[8] = up.x;
		matrix.m[9] = up.y;
		matrix.m[10] = up.z;
	}

	void BuildBasis( idVec3 forward, idVec3 & right, idVec3 & up ) {
		if ( forward.NormalizeFast() <= 1.0e-20f )
			forward.Set( 1.0f, 0.0f, 0.0f );
	idVec3 seed = std::fabs( forward.z ) > 0.99f
		? idVec3( 0.0f, 1.0f, 0.0f ) : idVec3( 0.0f, 0.0f, 1.0f );
		right = seed.Cross( forward );
		right.NormalizeFast();
		up = forward.Cross( right );
		up.NormalizeFast();
	}
}

void GetPointLightViewMatrix( int face, idRenderMatrix & matrix ) {
	static const idVec3 forward[6] = {
		idVec3( 1.0f, 0.0f, 0.0f ), idVec3( -1.0f, 0.0f, 0.0f ),
		idVec3( 0.0f, 1.0f, 0.0f ), idVec3( 0.0f, -1.0f, 0.0f ),
		idVec3( 0.0f, 0.0f, 1.0f ), idVec3( 0.0f, 0.0f, -1.0f ) };
	static const idVec3 up[6] = {
		idVec3( 0.0f, 1.0f, 0.0f ), idVec3( 0.0f, 1.0f, 0.0f ),
		idVec3( 0.0f, 0.0f, 1.0f ), idVec3( 0.0f, 0.0f, 1.0f ),
		idVec3( 0.0f, 1.0f, 0.0f ), idVec3( 0.0f, 1.0f, 0.0f ) };
	face = std::max( 0, std::min( face, 5 ) );
	idVec3 right = up[face].Cross( forward[face] );
	right.NormalizeFast();
	SetOrientation( forward[face], right, up[face], matrix );
}

void GetSpotLightViewMatrix( const idVec3 & lightTarget,
		const idVec3 & lightRight, const idVec3 & lightUp,
		idRenderMatrix & matrix ) {
	idVec3 target = lightTarget;
	idVec3 right = lightRight;
	idVec3 up = lightUp;
	if ( target.NormalizeFast() <= 1.0e-20f ) target.Set( 1.0f, 0.0f, 0.0f );
	if ( right.NormalizeFast() <= 1.0e-20f ||
			up.NormalizeFast() <= 1.0e-20f ) BuildBasis( target, right, up );
	SetOrientation( target, right, up, matrix );
}

void GetParallelLightViewMatrix( const idVec3 & direction,
		idRenderMatrix & matrix ) {
	idVec3 forward = direction;
	idVec3 right;
	idVec3 up;
	BuildBasis( forward, right, up );
	forward = direction;
	if ( forward.NormalizeFast() <= 1.0e-20f )
		forward.Set( 1.0f, 0.0f, 0.0f );
	SetOrientation( forward, right, up, matrix );
}

void GetPointShadowProjectionMatrix( float zNear, float zFar,
		idRenderMatrix & matrix ) {
	zNear = std::max( zNear, 0.001f );
	if ( zFar <= zNear ) zFar = zNear + 1.0f;
	idRenderMatrix::BuildProjection( -zNear, zNear, -zNear, zNear,
		zNear, zFar, matrix );
}
