#pragma once

// The retail sound translation units used the engine PCH.  This recovered
// bridge provides the same common surface without changing public headers.
#include "../sys/sys_precompiled.h"
#include "../framework/resource.h"
#include "../framework/resourcelist.h"
#include "../decls/decl.h"
#include "../decls/decltypeinfo.h"
#include "../decls/decltable.h"
#include "../../shared/idlib/typesafenumber.h"
#include "../../shared/idlib/containers/linklist.h"
#include "../../shared/idlib/math/random.h"
#include "../../shared/idlib/parallelism/paralleljoblist.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <xaudio2.h>
#include <xaudio2fx.h>
#include <x3daudio.h>
#include <cmath>
#include <cfloat>
#include <cstdint>
#include <limits>

#include "files/wavefile.h"
#include "soundshader.h"
#include "xaudio2/xa2_soundsample.h"
#include "soundvoice.h"
#include "xaudio2/xa2_soundhardware.h"
#include "occlusion/flatsoundbsp.h"
#include "occlusion/soundrouting.h"
#include "occlusion/soundocclusion.h"
#include "soundbspfile.h"
#include "soundemitter.h"
#include "soundemitter_local.h"
#include "soundworld.h"
#include "soundworld_local.h"
#include "soundsystem.h"
#include "soundsystem_local.h"

struct idLocalizedSampleOnDisc {
	char lang[ 16 ];
	int offset;
	int size;
	void * data;
};

ID_INLINE float SoundClamp( float value, float minimum, float maximum ) {
	return value < minimum ? minimum : ( value > maximum ? maximum : value );
}

ID_INLINE float SoundDbToScale( float decibels ) {
	return std::pow( 10.0f, decibels / 20.0f );
}

ID_INLINE float SoundScaleToDb( float scale ) {
	return scale > 0.000001f ? 20.0f * std::log10( scale ) : -120.0f;
}
