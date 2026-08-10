#pragma once

#include "renderer_types.h"

class idIndexBuffer;
class idJointBuffer;
class idMaterial;
class idTriangles;
class idVertexBuffer;

class idRenderModelSurface {
public:
	idRenderModelSurface() : material( nullptr ), materialNum( -1 ),
		extraGLState( 0 ), geometry( nullptr ), geometryIsReference( false ),
		referenceMask( 0 ), binaryModelId( -1 ), joints( nullptr ),
		morphMap( nullptr ), stMap( nullptr ),
		skinOffsets( 0.0f, 0.0f, 0.0f, 0.0f ) {}

	const idMaterial * material;
	int materialNum;
	std::uint64_t extraGLState;
	idTriangles * geometry;
	bool geometryIsReference;
	unsigned char referenceMask;
	int binaryModelId;
	idJointBuffer * joints;
	idVertexBuffer * morphMap;
	idVertexBuffer * stMap;
	idVec4 skinOffsets;
};

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idRenderModelSurface ) == 56,
	"Recovered render-model surface ABI changed" );
#endif
