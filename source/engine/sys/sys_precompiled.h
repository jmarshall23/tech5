#pragma once

// Common include surface for the recovered system layer.  The original
// project supplied these declarations through a large engine precompiled
// header which is not present in the recovered PC tree.

#include <algorithm>
#include <array>
#include <atomic>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <new>
#include <utility>

#include "sys_types.h"

#include "../../shared/idlib/sys/sys_alloc.h"
#include "../../shared/idlib/sys/sys_networking.h"
#include "../../shared/idlib/sys/sys_threading.h"
#include "../../shared/idlib/text/cmdargs.h"
#include "../../shared/idlib/text/str.h"
#include "../../shared/idlib/text/strstatic.h"
#include "../../shared/idlib/containers/array.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/containers/staticlist.h"
#include "../../shared/idlib/containers/queue.h"
#include "../../shared/idlib/blockalloc.h"
#include "../../shared/idlib/callback.h"
#include "../../shared/idlib/dict.h"
#include "../../shared/idlib/filesystem/file.h"
#include "../../shared/idlib/filesystem/file_savegame.h"
#include "../../shared/idlib/filesystem/filesystem.h"
#include "../../shared/idlib/hashing/md5.h"
#include "../../shared/idlib/networking/bitmsg.h"
#include "../../shared/idlib/metrics/metricrecord.h"
#include "../../shared/idlib/runningaverage.h"
#include "../../shared/idlib/csystems/cvarsystem.h"
#include "../../shared/idlib/csystems/cmdsystem.h"
#include "../../shared/idlib/lib_print.h"
#include "../../shared/idlib/commandlink.h"
#include "../../shared/idlib/hashing/crc32.h"
#include "../../shared/idlib/text/parser.h"

#include "../network/network_precompiled.h"
#include "sys_framework.h"

static const int MAX_PROFILE_SIZE = 1024 * 1000;

#ifndef TAG_SYSTEM
#define TAG_SYSTEM TAG_NEW
#endif
#ifndef PORT_ANY
#define PORT_ANY -1
#endif

template< typename type >
class idTempArray {
public:
	explicit idTempArray( int count ) : data( count > 0 ? new type[ count ] : NULL ), count( count ) {}
	type * Ptr() { return data.get(); }
	const type * Ptr() const { return data.get(); }
	int Size() const { return count; }
	type & operator[]( int index ) { return data[ index ]; }
	const type & operator[]( int index ) const { return data[ index ]; }
private:
	std::unique_ptr< type[] > data;
	int count;
};

ID_INLINE unsigned int Sys_StringHash( const char * text ) {
	unsigned int hash = 0;
	if ( text != NULL ) {
		while ( *text != '\0' ) hash = 31u * hash + static_cast< byte >( *text++ );
	}
	return hash;
}

#ifndef MS2SEC
#define MS2SEC( milliseconds ) ( static_cast< float >( milliseconds ) * 0.001f )
#endif
#ifndef SEC2MS
#define SEC2MS( seconds ) ( static_cast< int >( ( seconds ) * 1000.0f ) )
#endif

template< typename type >
ID_INLINE void SwapValues( type & left, type & right ) {
	type temporary = left;
	left = right;
	right = temporary;
}

#ifndef CONSOLE_COMMAND_COMPILE
#define CONSOLE_COMMAND_COMPILE( name, comment, completion ) \
	void name ## _f( const idCmdArgs & args ); \
	idCommandLink name ## _v( #name, name ## _f, comment, completion ); \
	void name ## _f( const idCmdArgs & args )
#define CONSOLE_COMMAND CONSOLE_COMMAND_COMPILE
#define CONSOLE_COMMAND_SHIP CONSOLE_COMMAND_COMPILE
#endif

ID_INLINE void * operator new( size_t size, memTag_t tag ) {
	return Sys_Alloc( static_cast< unsigned int >( size ), tag );
}
ID_INLINE void operator delete( void * pointer, memTag_t ) noexcept {
	Sys_Free( pointer );
}

// Convenience spellings present on the original idBitMsg but not yet on the
// recovered shared facade.  They lower directly to its PDB-authentic fields
// and bit primitives without changing the public idBitMsg type.
#define InitWrite( data, size ) Init( data, size )
#define InitRead( data, size ) Init( static_cast< const byte * >( data ), size )
#define WriteLong( value ) WriteBits( value, 32 )
#define WriteShort( value ) WriteBits( value, -16 )
#define WriteUShort( value ) WriteBits( value, 16 )
#define WriteByte( value ) WriteBits( value, 8 )
#define WriteBool( value ) WriteBits( ( value ) ? 1 : 0, 1 )
#define ReadLong() ReadBits( 32 )
#define ReadShort() ReadBits( -16 )
#define ReadUShort() ReadBits( 16 )
#define ReadByte() ReadBits( 8 )
#define ReadBool() ReadBits( 1 ) != 0
#define SetReadCount( value ) readCount = ( value )
#define ReadByteAlign() readBit = 0
#define GetWriteBit() writeBit
#define GetReadBit() readBit

#ifndef SCOPED_PROFILE_EVENT
#define SCOPED_PROFILE_EVENT( name ) (void)0
#endif
#ifndef ASSERT_ENUM_STRING
#define ASSERT_ENUM_STRING( value, ordinal ) #value
#endif
#ifndef verify_array_size
#define verify_array_size( array, expected ) static_assert( _countof( array ) == ( expected ), "array size" )
#endif

#include "sys_public.h"

ID_INLINE long Sys_InterlockedIncrement( interlockedInt_t & value ) {
	return ::InterlockedIncrement( reinterpret_cast< volatile LONG * >( &value ) );
}

// Match the original idTech 5 precompiled-header order.  These declarations
// deliberately form one system-layer surface; individual translation units
// relied on the PCH rather than repeating this dependency chain.
#include "sys_savegame.h"
#include "sys_session_savegames.h"
#include "sys_profile.h"
#include "sys_localuser.h"
#include "sys_signin.h"
#include "sys_stats_misc.h"
#include "sys_stats.h"
#include "sys_session.h"
#include "sys_server_query.h"
#include "sys_disc_swapper.h"
#include "sys_achievements.h"
