#pragma once

// The retail build pulled the SWF implementation through
// engine/framework/precompiled.h.  That umbrella header was not present on
// the recovered drives, so this local include surface records the concrete
// dependencies of the subsystem without widening the recovery boundary.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>
#include <utility>

#include "../../../shared/idlib/sys/sys_alloc.h"
#include "../../../shared/idlib/blockalloc.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/containers/staticlist.h"
#include "../../../shared/idlib/containers/sort.h"
#include "../../../shared/idlib/commandlink.h"
#include "../../../shared/idlib/filesystem/file.h"
#include "../../../shared/idlib/langdict.h"
#include "../../../shared/idlib/math/random.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/math/vectori.h"
#include "../../../shared/idlib/swap.h"
#include "../../../shared/idlib/text/atomicstring.h"
#include "../../../shared/idlib/text/cmdargs.h"
#include "../../../shared/idlib/text/str.h"

using byte = std::uint8_t;
using uint8 = std::uint8_t;
using int8 = std::int8_t;
using uint16 = std::uint16_t;
using int16 = std::int16_t;
using uint32 = std::uint32_t;
using int32 = std::int32_t;
using uint64 = std::uint64_t;
using int64 = std::int64_t;
using ID_TIME_T = std::uint32_t;

#ifndef ID_INLINE
#define ID_INLINE inline
#endif
#ifndef BIT
#define BIT( bit ) ( 1u << ( bit ) )
#endif
#ifndef Min
#define Min( a, b ) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
#endif
#ifndef Max
#define Max( a, b ) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )
#endif
#ifndef DEG2RAD
#define DEG2RAD( value ) ( ( value ) * 0.01745329251994329577f )
#endif
#ifndef RAD2DEG
#define RAD2DEG( value ) ( ( value ) * 57.295779513082320876f )
#endif
#ifndef Mem_Alloc
#define Mem_Alloc( size, tag ) Sys_Alloc( static_cast< unsigned int >( size ), tag )
#endif
#ifndef Mem_Free
#define Mem_Free( pointer ) Sys_Free( pointer )
#endif
#ifndef Prefetch
#define Prefetch( pointer, offset ) (void)0
#endif

class idMath {
public:
	static constexpr float FLT_SMALLEST_NON_DENORMAL = 1.17549435e-38f;
	static int Ftoi( float value ) { return static_cast< int >( value ); }
	static byte Ftob( float value ) {
		const int integer = static_cast< int >( value );
		return static_cast< byte >( ( std::max )( 0, ( std::min )( 255, integer ) ) );
	}
	static float Fabs( float value ) { return std::fabs( value ); }
	static float Floor( float value ) { return std::floor( value ); }
	static float Ceil( float value ) { return std::ceil( value ); }
	static float Sin( float value ) { return std::sin( value ); }
	static float Cos( float value ) { return std::cos( value ); }
	static float ACos( float value ) { return std::acos( value ); }
	static void SinCos( float value, float & sine, float & cosine ) {
		sine = std::sin( value );
		cosine = std::cos( value );
	}
	static float Sqrt( float value ) { return std::sqrt( value ); }
	static float Pow( float value, float exponent ) { return std::pow( value, exponent ); }
	static float ClampFloat( float minimum, float maximum, float value ) {
		return ( std::max )( minimum, ( std::min )( maximum, value ) );
	}
};

class idMaterial;
class idImage;
class idFont;
class idSoundWorld;
class idSoundEmitter;
class idSoundShader;
class idRenderModelGui;
class idFileResource;
class idDeclInfo;
struct sysEvent_t;

enum soundChannel_t : int;
enum bindSet_t : int;

#include "swf.h"
