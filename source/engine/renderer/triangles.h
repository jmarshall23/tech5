#pragma once

#include "../models/rendermodel.h"

struct localTrace_t {
	float fraction;
	idVec3 point;
	idVec3 normal;
	int jointIndex;
	int indexes[3];
};

// idTriangles is owned by models/rendermodel.h in this recovered tree.  These
// adapters expose the original renderer behavior without modifying files
// outside renderer, the directory boundary of this recovery pass.
void R_InitTriangles( idTriangles & triangles );
void R_FreeTriangleCPUData( idTriangles & triangles );
void R_FreeTriangleData( idTriangles & triangles );
int R_TriangleCPUMemoryUsed( const idTriangles & triangles );
int R_TriangleGPUMemoryUsed( const idTriangles & triangles );
void R_AllocTriangleVerts( idTriangles & triangles, int numVerts );
void R_AllocTriangleIndexes( idTriangles & triangles, int numIndexes );
void R_ResizeTriangleVerts( idTriangles & triangles, int newNumVerts );
void R_ResizeTriangleIndexes( idTriangles & triangles, int newNumIndexes );
bool R_RangeCheckIndexes( const unsigned short * indexes, int numIndexes,
	int numVerts );
void R_RemoveDegenerateTriangles( idTriangles & triangles );
void R_OptimizeTriangleIndexOrder( idTriangles & triangles );
void R_OptimizeTriangleVertexOrder( idTriangles & triangles );
void R_MergeTriangles( idTriangles & destination, const idTriangles & source );
idBounds R_BoundsFromTriangleVerts( const idTriangles & triangles );
void R_DeriveTriangleTangents( idTriangles & triangles );
void R_CleanupTriangles( idTriangles & triangles, bool createNormals );
void R_UpdateTriangleVertexBuffer( idTriangles & triangles );
void R_UpdateTriangleIndexBuffer( idTriangles & triangles );
float R_TriangleSurfaceArea( const idTriangles & triangles );
localTrace_t R_TraceTriangles( const idTriangles & triangles,
	const idVec3 & start, const idVec3 & end, float radius, bool twoSided );
void R_TriangleVectors( const idDrawVert & a, const idDrawVert & b,
	const idDrawVert & c, idVec3 & normal, idVec3 & tangent,
	idVec3 & bitangent );
void R_WriteTriangles( const idTriangles & triangles, idFile * file );
bool R_ReadTriangles( idTriangles & triangles, idFile * file );

// Retail free functions from triverts.cpp.  The PC path intentionally keeps
// idDrawVert's 32-byte CPU format and lets D3D9 declarations describe it.
int SwapVertexBuffer( void * vertexBuffer, int numVerts, int vertexSize );
void PackToVertexFormat( const idDrawVert * source, void * destination,
	int numVerts, int vertexMask );
void TransferVerts( int vertexMask, int numVerts,
	const idVertexScaleAndBias * scaleAndBias, int sourceStride,
	bool sourceIsPacked, const void * source, void * destination );
