#pragma once

#include "renderer_d3d9.h"
#include "../models/rendermodel.h"

enum bufferMapType_t : int {
	BM_READ = 0,
	BM_READ_NOSYNC = 1,
	BM_WRITE = 2,
	BM_WRITE_NOSYNC = 3
};

class idPixelPackBuffer {
public:
	idPixelPackBuffer() : size( 0 ), offsetInOtherBuffer( 0 ), apiObject( nullptr ) {}
	int size;
	int offsetInOtherBuffer;
	void * apiObject;
};

void UnbindBufferObjects();
bool R_AllocVertexBuffer( idVertexBuffer & buffer, const void * data,
	int size, int offset, bufferUsageType_t usage );
void R_FreeVertexBuffer( idVertexBuffer & buffer );
void R_ReferenceVertexBuffer( idVertexBuffer & target,
	const idVertexBuffer & source, int offset = 0, int size = -1 );
void R_UpdateVertexBuffer( const idVertexBuffer & buffer, const void * data,
	int size, int offset = 0 );
void * R_MapVertexBuffer( const idVertexBuffer & buffer, bufferMapType_t type );
void R_UnmapVertexBuffer( const idVertexBuffer & buffer );

bool R_AllocIndexBuffer( idIndexBuffer & buffer, const void * data,
	int size, bufferUsageType_t usage );
void R_FreeIndexBuffer( idIndexBuffer & buffer );
void R_ReferenceIndexBuffer( idIndexBuffer & target,
	const idIndexBuffer & source, int offset = 0, int size = -1 );
void R_UpdateIndexBuffer( const idIndexBuffer & buffer, const void * data,
	int size );
void * R_MapIndexBuffer( const idIndexBuffer & buffer, bufferMapType_t type );
void R_UnmapIndexBuffer( const idIndexBuffer & buffer );

bool R_AllocJointBuffer( idJointBuffer & buffer, const float * joints,
	int numJoints );
void R_FreeJointBuffer( idJointBuffer & buffer );
void R_ReferenceJointBuffer( idJointBuffer & target,
	const idJointBuffer & source, int offset, int numJoints );
void R_UpdateJointBuffer( const idJointBuffer & buffer, const float * joints,
	int numJoints );
float * R_MapJointBuffer( const idJointBuffer & buffer, bufferMapType_t type );
void R_UnmapJointBuffer( const idJointBuffer & buffer );
void R_SwapJointBuffers( idJointBuffer & left, idJointBuffer & right );

void R_FreePixelPackBuffer( idPixelPackBuffer & buffer );

