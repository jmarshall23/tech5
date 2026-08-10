#pragma once

// Renderer primitives recovered from the retail type database.  The numeric
// values are part of the serialized/image ABI and must not be reordered.

#include <cstdint>
#include <cstring>

#include "../../shared/idlib/math/vector.h"

class idDeclRenderParm;
class idDeclRenderProg;
class idImage;
class idRenderDestination;
class idRenderModelSurface;
class idTriangles;

// The retail renderer packed a 24-bit slot and an 8-bit generation into this
// handle.  Hex-Rays consistently accesses the slot as index >> 8.
class idRenderIndex {
public:
	idRenderIndex() : index( 0xFFFFFFFFu ) {}
	explicit idRenderIndex( unsigned int slot, unsigned int generation = 0 )
		: index( ( slot << 8 ) | ( generation & 0xFFu ) ) {}
	bool IsValid() const { return index != 0xFFFFFFFFu; }
	int GetIndex() const { return IsValid() ? static_cast< int >( index >> 8 ) : -1; }
	void Set( unsigned int slot, unsigned int generation = 0 ) {
		index = ( slot << 8 ) | ( generation & 0xFFu );
	}
	void Invalidate() { index = 0xFFFFFFFFu; }
	bool operator==( const idRenderIndex & other ) const {
		return index == other.index;
	}
	bool operator!=( const idRenderIndex & other ) const {
		return index != other.index;
	}

	unsigned int index;
};

static_assert( sizeof( idRenderIndex ) == 4,
	"Recovered renderer index ABI changed" );

enum textureRepeat_t : int {
	TR_REPEAT = 0,
	TR_CLAMP = 1,
	TR_CLAMP_S = 2,
	TR_CLAMP_T = 3,
	TR_CLAMP_TO_BORDER = 4,
	TR_MIRROR = 5
};

enum textureFilter_t : int {
	TF_LINEAR = 0,
	TF_NEAREST = 1,
	TF_NEAREST_MIPMAP_NEAREST = 2,
	TF_LINEAR_MIPMAP_NEAREST = 3,
	TF_TRILINEAR_NO_ANISO = 4,
	TF_DEFAULT = 5
};

enum textureType_t : int {
	TT_2D = 0,
	TT_3D = 1,
	TT_CUBIC = 2
};

enum textureFormat_t : int {
	FMT_NONE = 0,
	FMT_RGBA32F = 1,
	FMT_RGBA16F = 2,
	FMT_RGBA8 = 3,
	FMT_ARGB8 = 4,
	FMT_ALPHA = 5,
	FMT_L8A8 = 6,
	FMT_RG8 = 7,
	FMT_LUM8 = 8,
	FMT_INT8 = 9,
	FMT_DXT1 = 10,
	FMT_DXT5 = 11,
	FMT_DEPTH = 12,
	FMT_DEPTH_STENCIL = 13,
	FMT_X32F = 14,
	FMT_Y16F_X16F = 15,
	FMT_X16 = 16,
	FMT_Y16_X16 = 17,
	FMT_RGB565 = 18
};

enum textureColor_t : int {
	CFM_DEFAULT = 0,
	CFM_HQ_DXT5 = 1,
	CFM_HQ_NORMAL_DXT5 = 2,
	CFM_YCOCG_DXT5 = 3,
	CFM_YCOCGA_DXT5 = 4,
	CFM_YCOCGA_HQ_DXT5 = 5,
	CFM_HQ_DXT1 = 6
};

enum imageOpts_t : int {
	IMOP_FILTER = 0x001,
	IMOP_REPEAT = 0x002,
	IMOP_BORDER_COLOR = 0x004,
	IMOP_LOD_BIAS = 0x008,
	IMOP_LOD_MIN_CLAMP = 0x010,
	IMOP_LOD_MAX_CLAMP = 0x020,
	IMOP_LOD_ANISO = 0x040,
	IMOP_LOD_FORCE_BIAS = 0x080,
	IMOP_SHADOW_MAP = 0x100,
	IMOP_SWIZZLE = 0x200,
	IMOP_ALL = 0x3ff
};

enum imageState_t : int {
	IS_PURGED = 0,
	IS_BACKGROUND_READING = 1,
	IS_READY = 2
};

enum renderClass_t : int {
	TC_DEPTH = 0,
	TC_RGBA = 1,
	TC_RGBA_DEPTH = 2,
	TC_FLOAT_RGBA = 3,
	TC_FLOAT_RGBA_DEPTH = 4,
	TC_FLOAT16_RGBA = 5,
	TC_FLOAT16_RGBA_DEPTH = 6,
	TC_NUM_RENDER_CLASS = 7
};

enum resolveTarget_t : int {
	RESOLVE_TARGET_COLOR0 = 0,
	RESOLVE_TARGET_COLOR1 = 1,
	RESOLVE_TARGET_COLOR2 = 2,
	RESOLVE_TARGET_COLOR3 = 3,
	RESOLVE_TARGET_DEPTH = 4
};

enum stereoRenderMode_t : int {
	STEREO_RENDER_OFF = 0,
	STEREO_RENDER_LEFT_AND_RIGHT = 1,
	STEREO_RENDER_TOP_AND_BOTTOM = 2
};

enum videoFlags_t : int {
	VIDEO_EXIT = 0,
	VIDEO_FREEZE = 1,
	VIDEO_LOOP = 2
};

enum parmType_t : int {
	PT_VECTOR = 0,
	PT_TEXTURE = 1,
	PT_TEXTURE_2D = 2,
	PT_TEXTURE_3D = 3,
	PT_TEXTURE_CUBE = 4,
	PT_TEXTURE_SHADOW_2D = 5,
	PT_TEXTURE_SHADOW_3D = 6,
	PT_TEXTURE_SHADOW_CUBE = 7,
	PT_TEXTURE_MULTISAMPLE_2D = 8,
	PT_PROGRAM = 9,
	PT_STRING = 10,
	PT_MAX = 11
};

enum parmEdit_t : int {
	PE_NO_EDIT = 0,
	PE_BOOL = 1,
	PE_RANGE = 2,
	PE_COLOR = 3,
	PE_NO_DISPLAY = 4
};

enum parmCreator_t : int {
	PC_PARSED = 0,
	PC_CONSTANT = 1,
	PC_TEMPORARY = 2
};

class alignas( 4 ) idImageOpts {
public:
	idImageOpts();
	bool operator==( const idImageOpts & rhs ) const;
	bool operator!=( const idImageOpts & rhs ) const { return !( *this == rhs ); }

	textureType_t textureType;
	int width;
	int height;
	int depth;
	int numLevels;
	bool packedTail;
	bool readback;
	bool linear;
	bool cubeFilter;
	bool overlayMemory;
	bool startPurged;
	textureFormat_t format;
	textureColor_t colorFormat;
	textureFilter_t filter;
	textureRepeat_t repeat;
	idVec4 border;
	float lodBias;
	float lodMinClamp;
	float lodMaxClamp;
	float aniso;
	bool forceBias;
	bool depthCompareMode;
};

inline idImageOpts::idImageOpts() :
	textureType( TT_2D ), width( 0 ), height( 0 ), depth( 0 ), numLevels( 0 ),
	packedTail( true ), readback( false ), linear( false ), cubeFilter( false ),
	overlayMemory( false ), startPurged( false ), format( FMT_NONE ),
	colorFormat( CFM_DEFAULT ), filter( TF_DEFAULT ), repeat( TR_REPEAT ),
	border( 0.0f, 0.0f, 0.0f, 0.0f ), lodBias( 0.0f ), lodMinClamp( 0.0f ),
	lodMaxClamp( 13.0f ), aniso( 0.0f ), forceBias( false ),
	depthCompareMode( false ) {
}

inline bool idImageOpts::operator==( const idImageOpts & rhs ) const {
	return std::memcmp( this, &rhs, sizeof( *this ) ) == 0;
}

// The recovered renderer state encoding.  It is shared with the BFG branch,
// but the retail 360 implementation consumed it through a big-endian dword.
using glStateBits_t = std::uint64_t;

static const glStateBits_t GLS_SRCBLEND_ONE = 0ull << 0;
static const glStateBits_t GLS_SRCBLEND_ZERO = 1ull << 0;
static const glStateBits_t GLS_SRCBLEND_DST_COLOR = 2ull << 0;
static const glStateBits_t GLS_SRCBLEND_ONE_MINUS_DST_COLOR = 3ull << 0;
static const glStateBits_t GLS_SRCBLEND_SRC_ALPHA = 4ull << 0;
static const glStateBits_t GLS_SRCBLEND_ONE_MINUS_SRC_ALPHA = 5ull << 0;
static const glStateBits_t GLS_SRCBLEND_DST_ALPHA = 6ull << 0;
static const glStateBits_t GLS_SRCBLEND_ONE_MINUS_DST_ALPHA = 7ull << 0;
static const glStateBits_t GLS_SRCBLEND_BITS = 7ull << 0;
static const glStateBits_t GLS_DSTBLEND_ZERO = 0ull << 3;
static const glStateBits_t GLS_DSTBLEND_ONE = 1ull << 3;
static const glStateBits_t GLS_DSTBLEND_SRC_COLOR = 2ull << 3;
static const glStateBits_t GLS_DSTBLEND_ONE_MINUS_SRC_COLOR = 3ull << 3;
static const glStateBits_t GLS_DSTBLEND_SRC_ALPHA = 4ull << 3;
static const glStateBits_t GLS_DSTBLEND_ONE_MINUS_SRC_ALPHA = 5ull << 3;
static const glStateBits_t GLS_DSTBLEND_DST_ALPHA = 6ull << 3;
static const glStateBits_t GLS_DSTBLEND_ONE_MINUS_DST_ALPHA = 7ull << 3;
static const glStateBits_t GLS_DSTBLEND_BITS = 7ull << 3;
static const glStateBits_t GLS_DEPTHMASK = 1ull << 6;
static const glStateBits_t GLS_REDMASK = 1ull << 7;
static const glStateBits_t GLS_GREENMASK = 1ull << 8;
static const glStateBits_t GLS_BLUEMASK = 1ull << 9;
static const glStateBits_t GLS_ALPHAMASK = 1ull << 10;
static const glStateBits_t GLS_COLORMASK = GLS_REDMASK | GLS_GREENMASK | GLS_BLUEMASK;
static const glStateBits_t GLS_POLYMODE_LINE = 1ull << 11;
static const glStateBits_t GLS_POLYGON_OFFSET = 1ull << 12;
static const glStateBits_t GLS_DEPTHFUNC_LESS = 0ull << 13;
static const glStateBits_t GLS_DEPTHFUNC_ALWAYS = 1ull << 13;
static const glStateBits_t GLS_DEPTHFUNC_GREATER = 2ull << 13;
static const glStateBits_t GLS_DEPTHFUNC_EQUAL = 3ull << 13;
static const glStateBits_t GLS_DEPTHFUNC_BITS = 3ull << 13;
static const glStateBits_t GLS_CULL_TWOSIDED = 1ull << 15;
static const glStateBits_t GLS_CULL_BACKSIDED = 1ull << 16;
static const glStateBits_t GLS_ALPHATOCOVERAGE = 1ull << 17;
static const glStateBits_t GLS_BLENDOP_ADD = 0ull << 18;
static const glStateBits_t GLS_BLENDOP_SUB = 1ull << 18;
static const glStateBits_t GLS_BLENDOP_MIN = 2ull << 18;
static const glStateBits_t GLS_BLENDOP_MAX = 3ull << 18;
static const glStateBits_t GLS_BLENDOP_BITS = 3ull << 18;
static const int GLS_STENCIL_FUNC_REF_SHIFT = 20;
static const glStateBits_t GLS_STENCIL_FUNC_REF_BITS = 0xffull << GLS_STENCIL_FUNC_REF_SHIFT;
static const int GLS_STENCIL_FUNC_MASK_SHIFT = 28;
static const glStateBits_t GLS_STENCIL_FUNC_MASK_BITS = 0xffull << GLS_STENCIL_FUNC_MASK_SHIFT;
static const glStateBits_t GLS_STENCIL_FUNC_BITS = 7ull << 36;
static const glStateBits_t GLS_STENCIL_OP_FAIL_BITS = 7ull << 39;
static const glStateBits_t GLS_STENCIL_OP_ZFAIL_BITS = 7ull << 42;
static const glStateBits_t GLS_STENCIL_OP_PASS_BITS = 7ull << 45;
static const glStateBits_t GLS_STENCIL_OP_BITS = GLS_STENCIL_OP_FAIL_BITS | GLS_STENCIL_OP_ZFAIL_BITS | GLS_STENCIL_OP_PASS_BITS;
static const glStateBits_t GLS_OVERRIDE = 1ull << 63;
static const glStateBits_t GLS_DEFAULT = 0;

struct wrapperStats_t {
	int c_queriesIssued;
	int c_queriesPassed;
	int c_queriesWaitTime;
	int c_queriesTooOld;
	int c_programsBound;
	int c_texturesBound;
	int c_drawElements;
	int c_drawIndices;
	int c_drawVertices;
};

struct wrapperConfig_t {
	bool waitForOcclusionQuery;
	bool forceTwoSided;
	bool disableStateCaching;
	bool lazyBindPrograms;
	bool lazyBindParms;
	bool lazyBindTextures;
	bool stripFragmentBranches;
	bool skipDetailTris;
	bool singleTriangle;
	bool finishEveryDraw;
	float defaultPolyOfsFactor;
	float defaultPolyOfsUnits;
	int textureMinFilter;
	int textureMaxFilter;
	int textureMipFilter;
	float textureAnisotropy;
	float textureLODBias;
};

int BitsForFormat( textureFormat_t format );
void ComputeNumLevels( idImageOpts & opts, const char * name );
