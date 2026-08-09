#pragma once

#include "../sys/sys_types.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <utility>

#include "../../shared/idlib/sys/sys_alloc.h"
#ifndef TAG_IDLIB_LIST_SNAPSHOT
#define TAG_IDLIB_LIST_SNAPSHOT TAG_NETWORKING
#endif
#include "../../shared/idlib/sys/sys_networking.h"
#include "../../shared/idlib/csystems/cvarsystem.h"
#include "../../shared/idlib/csystems/cmdsystem.h"
#include "../../shared/idlib/commandlink.h"
#include "../../shared/idlib/text/str.h"
#include "../../shared/idlib/text/strstatic.h"
#include "../../shared/idlib/text/atomicstring.h"
#include "../../shared/idlib/langdict.h"
#include "../../shared/idlib/containers/array.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/containers/staticlist.h"
#include "../../shared/idlib/blockalloc.h"
#include "../../shared/idlib/networking/bitmsg.h"
#include "../../shared/idlib/networking/dataqueue.h"
#include "../../shared/idlib/metrics/metricrecord.h"
#include "../../shared/idlib/metrics/metrics.h"
#include "../../shared/idlib/metrics/metricsframework.h"
#include "../../shared/idlib/parallelism/paralleljoblist.h"
#include "../../shared/idlib/math/mathlib.h"
#include "../../shared/idlib/math/random.h"
#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/math/matrix.h"
#include "../../shared/idlib/lib_print.h"
#include "../../shared/idlib/filesystem/filesystem.h"

#include "../sys/sys_public.h"
#include "../sys/sys_framework.h"

// The Windows shared-idlib recovery exposes the same storage and primitive
// operations as the later BFG headers, but not all of their convenience
// spellings.  Keep these adapters private to engine/network: public function
// signatures and the PDB-visible object layouts continue to use the recovered
// RAGE types directly.
using idLib = idLibPrint;

#ifndef CONSOLE_COMMAND_COMPILE
#define CONSOLE_COMMAND_COMPILE( name, comment, completion ) \
	void name ## _f( const idCmdArgs & args ); \
	idCommandLink name ## _v( #name, name ## _f, comment, completion ); \
	void name ## _f( const idCmdArgs & args )
#define CONSOLE_COMMAND CONSOLE_COMMAND_COMPILE
#define CONSOLE_COMMAND_SHIP CONSOLE_COMMAND_COMPILE
#endif

#ifndef verify
#define verify( expression ) ( !!( expression ) ? true : ( assert( false ), false ) )
#endif
// These were templates in the original utility surface.  Keep them as
// functions so member calls such as idStaticList::Max() remain untouched.
template< typename type >
ID_INLINE const type & Min( const type & left, const type & right ) {
	return left < right ? left : right;
}
template< typename type >
ID_INLINE const type & Max( const type & left, const type & right ) {
	return left > right ? left : right;
}
#ifndef ALIGN16
#define ALIGN16( declaration ) __declspec( align( 16 ) ) declaration
#endif
#ifndef assert_16_byte_aligned
#define assert_16_byte_aligned( pointer ) assert( ( reinterpret_cast< uintptr_t >( pointer ) & 15u ) == 0 )
#endif
#ifndef Mem_Alloc
#define Mem_Alloc( size, tag ) Sys_Alloc( static_cast< unsigned int >( size ), tag )
#endif
#ifndef Mem_Free
#define Mem_Free( pointer ) Sys_Free( pointer )
#endif

class idMath {
public:
	static int ClampInt( int minimum, int maximum, int value ) {
		return (std::max)( minimum, (std::min)( maximum, value ) );
	}
	static float ClampFloat( float minimum, float maximum, float value ) {
		return (std::max)( minimum, (std::min)( maximum, value ) );
	}
	static int Ftoi( float value ) { return static_cast< int >( value ); }
	static float Fabs( float value ) { return std::fabs( value ); }
};

ID_INLINE const char * va( const char * format, ... ) {
	static thread_local char text[ 4096 ];
	va_list args;
	va_start( args, format );
	vsnprintf( text, sizeof( text ), format, args );
	va_end( args );
	return text;
}

ID_INLINE void NetworkMsgSetSize( idBitMsg & msg, int size ) {
	msg.curSize = (std::max)( 0, (std::min)( size, msg.maxSize ) );
	msg.writeBit = 0;
}

ID_INLINE void NetworkMsgSetReadCount( idBitMsg & msg, int count ) {
	msg.readCount = (std::max)( 0, (std::min)( count, msg.curSize ) );
	msg.readBit = 0;
}

ID_INLINE void NetworkMsgWriteByteAlign( idBitMsg & msg ) {
	if ( msg.writeBit != 0 ) {
		msg.curSize++;
		msg.writeBit = 0;
		msg.tempValue = 0;
	}
}

ID_INLINE void NetworkMsgReadByteAlign( idBitMsg & msg ) {
	msg.readBit = 0;
}

template< int maxItems, int maxData >
ID_INLINE int NetworkQueueNum( const idDataQueue< maxItems, maxData > & queue ) {
	return queue.items.Num();
}

template< int maxItems, int maxData >
ID_INLINE int NetworkQueueSequence( const idDataQueue< maxItems, maxData > & queue, int index ) {
	return queue.items[ index ].sequence;
}

template< int maxItems, int maxData >
ID_INLINE int NetworkQueueLength( const idDataQueue< maxItems, maxData > & queue, int index ) {
	return queue.items[ index ].length;
}

template< int maxItems, int maxData >
ID_INLINE byte * NetworkQueueData( idDataQueue< maxItems, maxData > & queue, int index ) {
	return queue.data + queue.items[ index ].dataOffset;
}

template< int maxItems, int maxData >
ID_INLINE const byte * NetworkQueueData( const idDataQueue< maxItems, maxData > & queue, int index ) {
	return queue.data + queue.items[ index ].dataOffset;
}

template< int maxItems, int maxData >
ID_INLINE bool NetworkQueueAppend( idDataQueue< maxItems, maxData > & queue, int sequence, const byte * data, int length ) {
	return queue.Append( sequence, data, length, NULL, 0 );
}

template< int maxItems, int maxData >
ID_INLINE void NetworkQueueClear( idDataQueue< maxItems, maxData > & queue ) {
	queue.items.Clear();
	queue.dataLength = 0;
}

template< typename type >
ID_INLINE unsigned int NetworkReadBig( idFile * file, type & value ) {
	const unsigned int result = file->Read( &value, sizeof( value ) );
#if defined( _WIN32 )
	if ( result == sizeof( value ) ) {
		byte * bytes = reinterpret_cast< byte * >( &value );
		for ( size_t first = 0, last = sizeof( value ) - 1; first < last; ++first, --last ) {
			const byte temp = bytes[ first ]; bytes[ first ] = bytes[ last ]; bytes[ last ] = temp;
		}
	}
#endif
	return result;
}

template< typename type >
ID_INLINE unsigned int NetworkWriteBig( idFile * file, type value ) {
#if defined( _WIN32 )
	byte * bytes = reinterpret_cast< byte * >( &value );
	for ( size_t first = 0, last = sizeof( value ) - 1; first < last; ++first, --last ) {
		const byte temp = bytes[ first ]; bytes[ first ] = bytes[ last ]; bytes[ last ] = temp;
	}
#endif
	return file->Write( &value, sizeof( value ) );
}

#include "serializer.h"
#include "lightweightcompression.h"
#include "snapshot_jobs.h"
#include "snapshot.h"
#include "packetprocessor.h"
#include "snapshotprocessor.h"
