#include "bufferobject.h"

#include <algorithm>
#include <cstring>
#include <utility>

namespace {

DWORD BufferUsage( bufferUsageType_t usage ) {
	return usage == BU_DYNAMIC ? D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY :
		D3DUSAGE_WRITEONLY;
}

D3DPOOL BufferPool( bufferUsageType_t usage ) {
	return usage == BU_DYNAMIC ? D3DPOOL_DEFAULT : D3DPOOL_MANAGED;
}

DWORD LockFlags( bufferUsageType_t usage, bufferMapType_t type ) {
	DWORD flags = type == BM_READ || type == BM_READ_NOSYNC ? D3DLOCK_READONLY : 0;
	if ( usage == BU_DYNAMIC && type == BM_WRITE_NOSYNC ) flags |= D3DLOCK_NOOVERWRITE;
	if ( usage == BU_DYNAMIC && type == BM_WRITE ) flags |= D3DLOCK_DISCARD;
	if ( type == BM_READ_NOSYNC || type == BM_WRITE_NOSYNC ) flags |= D3DLOCK_DONOTWAIT;
	return flags;
}

template< typename T >
void ReleaseBuffer( void *& object ) {
	T * buffer = static_cast< T * >( object );
	D3D9Release( buffer );
	object = nullptr;
}

} // namespace

void UnbindBufferObjects() {
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr ) return;
	for ( UINT stream = 0; stream < 3; ++stream ) device->SetStreamSource( stream, nullptr, 0, 0 );
	device->SetIndices( nullptr );
}

bool R_AllocVertexBuffer( idVertexBuffer & buffer, const void * data,
		int size, int offset, bufferUsageType_t usage ) {
	R_FreeVertexBuffer( buffer );
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr || size <= 0 ) return false;
	IDirect3DVertexBuffer9 * object = nullptr;
	if ( FAILED( device->CreateVertexBuffer( size, BufferUsage( usage ), 0,
			BufferPool( usage ), &object, nullptr ) ) ) return false;
	buffer.size = size;
	buffer.offsetInOtherBuffer = offset;
	buffer.apiObject = object;
	buffer.usage = usage;
	if ( data != nullptr ) R_UpdateVertexBuffer( buffer, data, size, 0 );
	return true;
}

void R_FreeVertexBuffer( idVertexBuffer & buffer ) {
	ReleaseBuffer< IDirect3DVertexBuffer9 >( buffer.apiObject );
	buffer.size = buffer.offsetInOtherBuffer = 0;
	buffer.usage = BU_DEFAULT;
}

void R_ReferenceVertexBuffer( idVertexBuffer & target,
		const idVertexBuffer & source, int offset, int size ) {
	R_FreeVertexBuffer( target );
	target = source;
	target.offsetInOtherBuffer += std::max( offset, 0 );
	if ( size >= 0 ) target.size = std::min( size, source.size - std::max( offset, 0 ) );
	if ( target.apiObject != nullptr ) static_cast< IDirect3DVertexBuffer9 * >( target.apiObject )->AddRef();
}

void R_UpdateVertexBuffer( const idVertexBuffer & buffer, const void * data,
		int size, int offset ) {
	IDirect3DVertexBuffer9 * object = static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject );
	if ( object == nullptr || data == nullptr || size <= 0 ) return;
	void * destination = nullptr;
	const int writeSize = std::min( size, buffer.size - offset );
	if ( writeSize > 0 && SUCCEEDED( object->Lock( buffer.offsetInOtherBuffer + offset,
		writeSize, &destination, buffer.usage == BU_DYNAMIC ? D3DLOCK_DISCARD : 0 ) ) ) {
		std::memcpy( destination, data, writeSize );
		object->Unlock();
	}
}

void * R_MapVertexBuffer( const idVertexBuffer & buffer, bufferMapType_t type ) {
	IDirect3DVertexBuffer9 * object = static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject );
	void * data = nullptr;
	if ( object != nullptr ) object->Lock( buffer.offsetInOtherBuffer, buffer.size,
		&data, LockFlags( buffer.usage, type ) );
	return data;
}

void R_UnmapVertexBuffer( const idVertexBuffer & buffer ) {
	if ( buffer.apiObject != nullptr ) static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject )->Unlock();
}

bool R_AllocIndexBuffer( idIndexBuffer & buffer, const void * data,
		int size, bufferUsageType_t usage ) {
	R_FreeIndexBuffer( buffer );
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr || size <= 0 ) return false;
	IDirect3DIndexBuffer9 * object = nullptr;
	if ( FAILED( device->CreateIndexBuffer( size, BufferUsage( usage ),
		D3DFMT_INDEX16, BufferPool( usage ), &object, nullptr ) ) ) return false;
	buffer.size = size;
	buffer.offsetInOtherBuffer = 0;
	buffer.apiObject = object;
	buffer.usage = usage;
	if ( data != nullptr ) R_UpdateIndexBuffer( buffer, data, size );
	return true;
}

void R_FreeIndexBuffer( idIndexBuffer & buffer ) {
	ReleaseBuffer< IDirect3DIndexBuffer9 >( buffer.apiObject );
	buffer.size = buffer.offsetInOtherBuffer = 0;
	buffer.usage = BU_DEFAULT;
}

void R_ReferenceIndexBuffer( idIndexBuffer & target,
		const idIndexBuffer & source, int offset, int size ) {
	R_FreeIndexBuffer( target ); target = source;
	target.offsetInOtherBuffer += std::max( offset, 0 );
	if ( size >= 0 ) target.size = std::min( size, source.size - std::max( offset, 0 ) );
	if ( target.apiObject != nullptr ) static_cast< IDirect3DIndexBuffer9 * >( target.apiObject )->AddRef();
}

void R_UpdateIndexBuffer( const idIndexBuffer & buffer, const void * data, int size ) {
	IDirect3DIndexBuffer9 * object = static_cast< IDirect3DIndexBuffer9 * >( buffer.apiObject );
	if ( object == nullptr || data == nullptr ) return;
	void * destination = nullptr;
	const int writeSize = std::min( size, buffer.size );
	if ( writeSize > 0 && SUCCEEDED( object->Lock( buffer.offsetInOtherBuffer,
		writeSize, &destination, buffer.usage == BU_DYNAMIC ? D3DLOCK_DISCARD : 0 ) ) ) {
		std::memcpy( destination, data, writeSize ); object->Unlock();
	}
}

void * R_MapIndexBuffer( const idIndexBuffer & buffer, bufferMapType_t type ) {
	IDirect3DIndexBuffer9 * object = static_cast< IDirect3DIndexBuffer9 * >( buffer.apiObject );
	void * data = nullptr;
	if ( object != nullptr ) object->Lock( buffer.offsetInOtherBuffer, buffer.size,
		&data, LockFlags( buffer.usage, type ) );
	return data;
}

void R_UnmapIndexBuffer( const idIndexBuffer & buffer ) {
	if ( buffer.apiObject != nullptr ) static_cast< IDirect3DIndexBuffer9 * >( buffer.apiObject )->Unlock();
}

bool R_AllocJointBuffer( idJointBuffer & buffer, const float * joints, int numJoints ) {
	R_FreeJointBuffer( buffer );
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr || numJoints <= 0 ) return false;
	const int bytes = numJoints * 12 * static_cast< int >( sizeof( float ) );
	IDirect3DVertexBuffer9 * object = nullptr;
	if ( FAILED( device->CreateVertexBuffer( bytes, D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY,
		0, D3DPOOL_DEFAULT, &object, nullptr ) ) ) return false;
	buffer.numJoints = numJoints; buffer.offsetInOtherBuffer = 0;
	buffer.apiObject = object; buffer.flags = 0;
	if ( joints != nullptr ) R_UpdateJointBuffer( buffer, joints, numJoints );
	return true;
}

void R_FreeJointBuffer( idJointBuffer & buffer ) {
	ReleaseBuffer< IDirect3DVertexBuffer9 >( buffer.apiObject );
	buffer.numJoints = buffer.offsetInOtherBuffer = buffer.flags = 0;
}

void R_ReferenceJointBuffer( idJointBuffer & target,
		const idJointBuffer & source, int offset, int numJoints ) {
	R_FreeJointBuffer( target ); target = source;
	target.offsetInOtherBuffer += offset * 12 * static_cast< int >( sizeof( float ) );
	target.numJoints = std::min( numJoints, source.numJoints - offset );
	if ( target.apiObject != nullptr ) static_cast< IDirect3DVertexBuffer9 * >( target.apiObject )->AddRef();
}

void R_UpdateJointBuffer( const idJointBuffer & buffer, const float * joints,
		int numJoints ) {
	IDirect3DVertexBuffer9 * object = static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject );
	if ( object == nullptr || joints == nullptr ) return;
	const int bytes = std::min( numJoints, buffer.numJoints ) * 12 * sizeof( float );
	void * destination = nullptr;
	if ( SUCCEEDED( object->Lock( buffer.offsetInOtherBuffer, bytes, &destination,
			D3DLOCK_DISCARD ) ) ) { std::memcpy( destination, joints, bytes ); object->Unlock(); }
}

float * R_MapJointBuffer( const idJointBuffer & buffer, bufferMapType_t type ) {
	IDirect3DVertexBuffer9 * object = static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject );
	void * data = nullptr;
	if ( object != nullptr ) object->Lock( buffer.offsetInOtherBuffer,
		buffer.numJoints * 12 * sizeof( float ), &data, LockFlags( BU_DYNAMIC, type ) );
	return static_cast< float * >( data );
}

void R_UnmapJointBuffer( const idJointBuffer & buffer ) {
	if ( buffer.apiObject != nullptr ) static_cast< IDirect3DVertexBuffer9 * >( buffer.apiObject )->Unlock();
}

void R_SwapJointBuffers( idJointBuffer & left, idJointBuffer & right ) { std::swap( left, right ); }
void R_FreePixelPackBuffer( idPixelPackBuffer & buffer ) {
	ReleaseBuffer< IDirect3DSurface9 >( buffer.apiObject );
	buffer.size = buffer.offsetInOtherBuffer = 0;
}

