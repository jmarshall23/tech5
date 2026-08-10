#include "triangles.h"

#include "bufferobject.h"
#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace {
	idVec3 ScaledPosition( const idTriangles & triangles, const idVec3 & xyz ) {
		return idVec3(
			xyz.x * triangles.vsb.xyzScale.x + triangles.vsb.xyzBias.x,
			xyz.y * triangles.vsb.xyzScale.y + triangles.vsb.xyzBias.y,
			xyz.z * triangles.vsb.xyzScale.z + triangles.vsb.xyzBias.z );
	}

	void ExpandBounds( idBounds & bounds, const idVec3 & point ) {
		for ( int axis = 0; axis < 3; ++axis ) {
			bounds[0][axis] = (std::min)( bounds[0][axis], point[axis] );
			bounds[1][axis] = (std::max)( bounds[1][axis], point[axis] );
		}
	}

	bool IsRestartIndex( const unsigned short index ) { return index == 0xFFFFu; }
}

void R_InitTriangles( idTriangles & triangles ) {
	triangles.bounds[0].Set( 1.0e30f, 1.0e30f, 1.0e30f );
	triangles.bounds[1].Set( -1.0e30f, -1.0e30f, -1.0e30f );
	triangles.generateNormals = false;
	triangles.numIndexes = 0;
	triangles.numVerts = 0;
	triangles.detailOffset = 0;
	triangles.allowGpuHosting = true;
	triangles.vsb.xyzScale.Set( 1.0f, 1.0f, 1.0f );
	triangles.vsb.xyzBias.Zero();
	triangles.vsb.stScale.Set( 1.0f, 1.0f );
	triangles.vsb.stBias.Zero();
	triangles.cpuVertexMask = 31;
	triangles.verts = nullptr;
	triangles.indexes = nullptr;
	triangles.vertexMask = 31;
	triangles.vertexBuffer = {};
	triangles.vertexBuffer.usage = BU_DEFAULT;
	triangles.indexBuffer = {};
	triangles.indexBuffer.usage = BU_DEFAULT;
}

void R_FreeTriangleCPUData( idTriangles & triangles ) {
	delete[] triangles.verts;
	delete[] triangles.indexes;
	triangles.verts = nullptr;
	triangles.indexes = nullptr;
}

void R_FreeTriangleData( idTriangles & triangles ) {
	R_FreeVertexBuffer( triangles.vertexBuffer );
	R_FreeIndexBuffer( triangles.indexBuffer );
	R_FreeTriangleCPUData( triangles );
	triangles.generateNormals = false;
	triangles.numVerts = 0;
	triangles.numIndexes = 0;
}

int R_TriangleCPUMemoryUsed( const idTriangles & triangles ) {
	return sizeof( idTriangles )
		+ ( triangles.verts != nullptr ? triangles.numVerts * sizeof( idDrawVert ) : 0 )
		+ ( triangles.indexes != nullptr ? triangles.numIndexes * sizeof( unsigned short ) : 0 );
}

int R_TriangleGPUMemoryUsed( const idTriangles & triangles ) {
	return ( triangles.vertexBuffer.size & 0x7FFFFFFF )
		+ ( triangles.indexBuffer.size & 0x7FFFFFFF );
}

void R_AllocTriangleVerts( idTriangles & triangles, const int numVerts ) {
	delete[] triangles.verts;
	triangles.verts = numVerts > 0 ? new idDrawVert[numVerts]() : nullptr;
}

void R_AllocTriangleIndexes( idTriangles & triangles, const int numIndexes ) {
	delete[] triangles.indexes;
	triangles.indexes = numIndexes > 0 ? new unsigned short[numIndexes]() : nullptr;
}

void R_ResizeTriangleVerts( idTriangles & triangles, const int newNumVerts ) {
	idDrawVert * const replacement = newNumVerts > 0 ? new idDrawVert[newNumVerts]() : nullptr;
	if ( replacement != nullptr && triangles.verts != nullptr ) {
		std::copy( triangles.verts, triangles.verts + (std::min)( triangles.numVerts, newNumVerts ),
			replacement );
	}
	delete[] triangles.verts;
	triangles.verts = replacement;
}

void R_ResizeTriangleIndexes( idTriangles & triangles, const int newNumIndexes ) {
	unsigned short * const replacement = newNumIndexes > 0
		? new unsigned short[newNumIndexes]() : nullptr;
	if ( replacement != nullptr && triangles.indexes != nullptr ) {
		std::copy( triangles.indexes,
			triangles.indexes + (std::min)( triangles.numIndexes, newNumIndexes ), replacement );
	}
	delete[] triangles.indexes;
	triangles.indexes = replacement;
}

bool R_RangeCheckIndexes( const unsigned short * indexes, const int numIndexes,
	const int numVerts ) {
	if ( indexes == nullptr || numIndexes < 0 || numVerts < 0 ) return false;
	for ( int index = 0; index < numIndexes; ++index ) {
		if ( !IsRestartIndex( indexes[index] ) && indexes[index] >= numVerts ) return false;
	}
	return true;
}

void R_RemoveDegenerateTriangles( idTriangles & triangles ) {
	if ( triangles.indexes == nullptr ) return;
	int output = 0;
	for ( int index = 0; index + 2 < triangles.numIndexes; index += 3 ) {
		const unsigned short a = triangles.indexes[index + 0];
		const unsigned short b = triangles.indexes[index + 1];
		const unsigned short c = triangles.indexes[index + 2];
		if ( a == b || a == c || b == c || IsRestartIndex( a )
			|| IsRestartIndex( b ) || IsRestartIndex( c ) ) continue;
		triangles.indexes[output++] = a;
		triangles.indexes[output++] = b;
		triangles.indexes[output++] = c;
	}
	triangles.numIndexes = output;
}

void R_OptimizeTriangleIndexOrder( idTriangles & triangles ) {
	if ( triangles.indexes == nullptr || triangles.numIndexes < 6 ) return;
	const int triangleCount = triangles.numIndexes / 3;
	std::vector< bool > emitted( triangleCount, false );
	std::vector< unsigned short > result;
	result.reserve( triangles.numIndexes );
	unsigned short cache[16];
	int cacheCount = 0;
	for ( int outputTriangle = 0; outputTriangle < triangleCount; ++outputTriangle ) {
		int best = -1;
		int bestHits = -1;
		for ( int candidate = 0; candidate < triangleCount; ++candidate ) {
			if ( emitted[candidate] ) continue;
			int hits = 0;
			for ( int corner = 0; corner < 3; ++corner ) {
				const unsigned short vertex = triangles.indexes[candidate * 3 + corner];
				for ( int cached = 0; cached < cacheCount; ++cached ) {
					if ( cache[cached] == vertex ) { ++hits; break; }
				}
			}
			if ( hits > bestHits ) { bestHits = hits; best = candidate; if ( hits == 3 ) break; }
		}
		if ( best < 0 ) break;
		emitted[best] = true;
		for ( int corner = 0; corner < 3; ++corner ) {
			const unsigned short vertex = triangles.indexes[best * 3 + corner];
			result.push_back( vertex );
			int found = -1;
			for ( int cached = 0; cached < cacheCount; ++cached ) if ( cache[cached] == vertex ) found = cached;
			if ( found >= 0 ) {
				for ( int cached = found; cached > 0; --cached ) cache[cached] = cache[cached - 1];
				cache[0] = vertex;
			} else {
				cacheCount = (std::min)( cacheCount + 1, 16 );
				for ( int cached = cacheCount - 1; cached > 0; --cached ) cache[cached] = cache[cached - 1];
				cache[0] = vertex;
			}
		}
	}
	std::copy( result.begin(), result.end(), triangles.indexes );
}

void R_OptimizeTriangleVertexOrder( idTriangles & triangles ) {
	if ( triangles.verts == nullptr || triangles.indexes == nullptr ) return;
	std::vector< int > remap( triangles.numVerts, -1 );
	std::vector< idDrawVert > reordered;
	reordered.reserve( triangles.numVerts );
	for ( int index = 0; index < triangles.numIndexes; ++index ) {
		const unsigned short oldIndex = triangles.indexes[index];
		if ( IsRestartIndex( oldIndex ) || oldIndex >= triangles.numVerts ) continue;
		if ( remap[oldIndex] < 0 ) {
			remap[oldIndex] = static_cast< int >( reordered.size() );
			reordered.push_back( triangles.verts[oldIndex] );
		}
		triangles.indexes[index] = static_cast< unsigned short >( remap[oldIndex] );
	}
	for ( int oldIndex = 0; oldIndex < triangles.numVerts; ++oldIndex ) {
		if ( remap[oldIndex] < 0 ) reordered.push_back( triangles.verts[oldIndex] );
	}
	std::copy( reordered.begin(), reordered.end(), triangles.verts );
}

void R_MergeTriangles( idTriangles & destination, const idTriangles & source ) {
	if ( source.numVerts <= 0 || source.numIndexes <= 0 ) return;
	const int oldVerts = destination.numVerts;
	const int oldIndexes = destination.numIndexes;
	R_ResizeTriangleVerts( destination, oldVerts + source.numVerts );
	R_ResizeTriangleIndexes( destination, oldIndexes + source.numIndexes );
	std::copy( source.verts, source.verts + source.numVerts, destination.verts + oldVerts );
	for ( int index = 0; index < source.numIndexes; ++index ) {
		destination.indexes[oldIndexes + index] = IsRestartIndex( source.indexes[index] )
			? 0xFFFFu : static_cast< unsigned short >( source.indexes[index] + oldVerts );
	}
	destination.numVerts += source.numVerts;
	destination.numIndexes += source.numIndexes;
	destination.bounds = R_BoundsFromTriangleVerts( destination );
}

idBounds R_BoundsFromTriangleVerts( const idTriangles & triangles ) {
	idBounds bounds;
	bounds[0].Set( 1.0e30f, 1.0e30f, 1.0e30f );
	bounds[1].Set( -1.0e30f, -1.0e30f, -1.0e30f );
	if ( triangles.verts == nullptr || triangles.numVerts <= 0 ) {
		bounds[0].Zero();
		bounds[1].Zero();
		return bounds;
	}
	for ( int index = 0; index < triangles.numVerts; ++index ) {
		ExpandBounds( bounds, ScaledPosition( triangles, triangles.verts[index].xyz ) );
	}
	return bounds;
}

void R_TriangleVectors( const idDrawVert & a, const idDrawVert & b,
	const idDrawVert & c, idVec3 & normal, idVec3 & tangent, idVec3 & bitangent ) {
	const idVec3 edge1 = b.xyz - a.xyz;
	const idVec3 edge2 = c.xyz - a.xyz;
	normal = edge1.Cross( edge2 );
	normal.NormalizeFast();
	const float ds1 = b.st.x - a.st.x;
	const float dt1 = b.st.y - a.st.y;
	const float ds2 = c.st.x - a.st.x;
	const float dt2 = c.st.y - a.st.y;
	const float determinant = ds1 * dt2 - ds2 * dt1;
	if ( std::fabs( determinant ) < 1.0e-20f ) {
		tangent = edge1;
		tangent.NormalizeFast();
		bitangent = normal.Cross( tangent );
		return;
	}
	const float inverse = 1.0f / determinant;
	tangent = ( edge1 * dt2 - edge2 * dt1 ) * inverse;
	bitangent = ( edge2 * ds1 - edge1 * ds2 ) * inverse;
	tangent.NormalizeFast();
	bitangent.NormalizeFast();
}

void R_DeriveTriangleTangents( idTriangles & triangles ) {
	if ( triangles.verts == nullptr || triangles.indexes == nullptr ) return;
	std::vector< idVec3 > normals( triangles.numVerts, idVec3( 0, 0, 0 ) );
	std::vector< idVec3 > tangents( triangles.numVerts, idVec3( 0, 0, 0 ) );
	std::vector< idVec3 > bitangents( triangles.numVerts, idVec3( 0, 0, 0 ) );
	for ( int index = 0; index + 2 < triangles.numIndexes; index += 3 ) {
		const int ia = triangles.indexes[index + 0];
		const int ib = triangles.indexes[index + 1];
		const int ic = triangles.indexes[index + 2];
		if ( ia >= triangles.numVerts || ib >= triangles.numVerts || ic >= triangles.numVerts ) continue;
		idVec3 normal, tangent, bitangent;
		R_TriangleVectors( triangles.verts[ia], triangles.verts[ib], triangles.verts[ic],
			normal, tangent, bitangent );
		for ( const int vertex : { ia, ib, ic } ) {
			normals[vertex] = normals[vertex] + normal;
			tangents[vertex] = tangents[vertex] + tangent;
			bitangents[vertex] = bitangents[vertex] + bitangent;
		}
	}
	for ( int vertex = 0; vertex < triangles.numVerts; ++vertex ) {
		normals[vertex].NormalizeFast();
		// Gram-Schmidt gives the D3D9 declaration a stable orthogonal basis.
		tangents[vertex] = tangents[vertex]
			- normals[vertex] * normals[vertex].Dot( tangents[vertex] );
		tangents[vertex].NormalizeFast();
		triangles.verts[vertex].SetNormal( normals[vertex] );
		triangles.verts[vertex].SetTangent( tangents[vertex] );
		triangles.verts[vertex].SetBiTangent( bitangents[vertex] );
	}
}

void R_CleanupTriangles( idTriangles & triangles, const bool createNormals ) {
	if ( !R_RangeCheckIndexes( triangles.indexes, triangles.numIndexes, triangles.numVerts ) ) return;
	R_RemoveDegenerateTriangles( triangles );
	R_OptimizeTriangleIndexOrder( triangles );
	R_OptimizeTriangleVertexOrder( triangles );
	if ( createNormals || triangles.generateNormals ) R_DeriveTriangleTangents( triangles );
	triangles.bounds = R_BoundsFromTriangleVerts( triangles );
	R_UpdateTriangleVertexBuffer( triangles );
	R_UpdateTriangleIndexBuffer( triangles );
}

void R_UpdateTriangleVertexBuffer( idTriangles & triangles ) {
	if ( triangles.verts == nullptr || triangles.numVerts <= 0 ) return;
	const int bytes = triangles.numVerts * static_cast< int >( sizeof( idDrawVert ) );
	if ( triangles.vertexBuffer.apiObject == nullptr || triangles.vertexBuffer.size != bytes ) {
		R_FreeVertexBuffer( triangles.vertexBuffer );
		R_AllocVertexBuffer( triangles.vertexBuffer, triangles.verts, bytes, 0, BU_STATIC );
	} else {
		R_UpdateVertexBuffer( triangles.vertexBuffer, triangles.verts, bytes );
	}
}

void R_UpdateTriangleIndexBuffer( idTriangles & triangles ) {
	if ( triangles.indexes == nullptr || triangles.numIndexes <= 0 ) return;
	const int bytes = triangles.numIndexes * static_cast< int >( sizeof( unsigned short ) );
	if ( triangles.indexBuffer.apiObject == nullptr || triangles.indexBuffer.size != bytes ) {
		R_FreeIndexBuffer( triangles.indexBuffer );
		R_AllocIndexBuffer( triangles.indexBuffer, triangles.indexes, bytes, BU_STATIC );
	} else {
		R_UpdateIndexBuffer( triangles.indexBuffer, triangles.indexes, bytes );
	}
}

float R_TriangleSurfaceArea( const idTriangles & triangles ) {
	if ( triangles.verts == nullptr || triangles.indexes == nullptr ) return 0.0f;
	float area = 0.0f;
	for ( int index = 0; index + 2 < triangles.numIndexes; index += 3 ) {
		const int ia = triangles.indexes[index + 0];
		const int ib = triangles.indexes[index + 1];
		const int ic = triangles.indexes[index + 2];
		if ( ia >= triangles.numVerts || ib >= triangles.numVerts || ic >= triangles.numVerts ) continue;
		const idVec3 cross = ( triangles.verts[ib].xyz - triangles.verts[ia].xyz )
			.Cross( triangles.verts[ic].xyz - triangles.verts[ia].xyz );
		area += 0.5f * cross.Length();
	}
	return area;
}

localTrace_t R_TraceTriangles( const idTriangles & triangles,
	const idVec3 & start, const idVec3 & end, const float radius,
	const bool twoSided ) {
	localTrace_t trace = {};
	trace.fraction = 1.0f;
	trace.jointIndex = -1;
	trace.indexes[0] = trace.indexes[1] = trace.indexes[2] = -1;
	if ( triangles.verts == nullptr || triangles.indexes == nullptr ) return trace;
	const idVec3 direction = end - start;
	for ( int index = 0; index + 2 < triangles.numIndexes; index += 3 ) {
		const int ia = triangles.indexes[index + 0];
		const int ib = triangles.indexes[index + 1];
		const int ic = triangles.indexes[index + 2];
		if ( ia >= triangles.numVerts || ib >= triangles.numVerts || ic >= triangles.numVerts ) continue;
		const idVec3 a = ScaledPosition( triangles, triangles.verts[ia].xyz );
		const idVec3 b = ScaledPosition( triangles, triangles.verts[ib].xyz );
		const idVec3 c = ScaledPosition( triangles, triangles.verts[ic].xyz );
		const idVec3 edge1 = b - a;
		const idVec3 edge2 = c - a;
		const idVec3 p = direction.Cross( edge2 );
		const float determinant = edge1.Dot( p );
		if ( twoSided ? std::fabs( determinant ) < 1.0e-8f : determinant <= 1.0e-8f ) continue;
		const float inverse = 1.0f / determinant;
		const idVec3 t = start - a;
		const float u = t.Dot( p ) * inverse;
		if ( u < -radius || u > 1.0f + radius ) continue;
		const idVec3 q = t.Cross( edge1 );
		const float v = direction.Dot( q ) * inverse;
		if ( v < -radius || u + v > 1.0f + radius ) continue;
		const float fraction = edge2.Dot( q ) * inverse;
		if ( fraction < 0.0f || fraction >= trace.fraction ) continue;
		trace.fraction = fraction;
		trace.point = start + direction * fraction;
		trace.normal = edge1.Cross( edge2 );
		trace.normal.NormalizeFast();
		if ( trace.normal.Dot( direction ) > 0.0f ) trace.normal = -trace.normal;
		trace.indexes[0] = ia;
		trace.indexes[1] = ib;
		trace.indexes[2] = ic;
	}
	return trace;
}

void R_WriteTriangles( const idTriangles & triangles, idFile * file ) {
	if ( file == nullptr ) return;
	file->WriteLittle( triangles.numVerts );
	file->WriteLittle( triangles.numIndexes );
	file->WriteLittle( triangles.detailOffset );
	file->WriteLittle( triangles.cpuVertexMask );
	file->WriteLittle( triangles.vertexMask );
	file->Write( &triangles.vsb, sizeof( triangles.vsb ) );
	file->Write( triangles.verts, triangles.numVerts * sizeof( idDrawVert ) );
	file->Write( triangles.indexes, triangles.numIndexes * sizeof( unsigned short ) );
}

bool R_ReadTriangles( idTriangles & triangles, idFile * file ) {
	if ( file == nullptr ) return false;
	int numVerts = 0;
	int numIndexes = 0;
	if ( file->ReadLittle( numVerts ) != sizeof( numVerts )
		|| file->ReadLittle( numIndexes ) != sizeof( numIndexes )
		|| numVerts < 0 || numVerts > 65536 || numIndexes < 0 ) return false;
	R_FreeTriangleData( triangles );
	R_InitTriangles( triangles );
	triangles.numVerts = numVerts;
	triangles.numIndexes = numIndexes;
	if ( file->ReadLittle( triangles.detailOffset ) != sizeof( triangles.detailOffset )
		|| file->ReadLittle( triangles.cpuVertexMask ) != sizeof( triangles.cpuVertexMask )
		|| file->ReadLittle( triangles.vertexMask ) != sizeof( triangles.vertexMask )
		|| file->Read( &triangles.vsb, sizeof( triangles.vsb ) ) != sizeof( triangles.vsb ) ) return false;
	R_AllocTriangleVerts( triangles, numVerts );
	R_AllocTriangleIndexes( triangles, numIndexes );
	if ( file->Read( triangles.verts, numVerts * sizeof( idDrawVert ) )
			!= numVerts * sizeof( idDrawVert )
		|| file->Read( triangles.indexes, numIndexes * sizeof( unsigned short ) )
			!= numIndexes * sizeof( unsigned short ) ) return false;
	triangles.bounds = R_BoundsFromTriangleVerts( triangles );
	return R_RangeCheckIndexes( triangles.indexes, numIndexes, numVerts );
}
