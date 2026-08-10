#pragma once

#include <cstdint>

// Values and field widths are fixed by the recovered 32-bit retail ABI.
enum pageCompression_t : std::int32_t {
	COMP_NONE = 1,
	COMP_DXT = 2,
	COMP_LZW = 3,
	COMP_DCT = 4,
	COMP_HDP = 5,
	COMP_JXR = 6,
	COMP_MAX_COMPRESSIONS = 7
};

struct compressionStats_t {
	std::uint64_t headerBytes;
	std::uint64_t specularBytes;
	std::uint64_t diffuseBytes;
	std::uint64_t normalBytes;
	std::uint64_t powerBytes;
	std::uint64_t coverBytes;
	std::uint64_t wastedBytes;
	int diskOffsetScale;

	compressionStats_t();
};

#pragma pack( push, 1 )
struct DCTHeader_t {
	std::uint8_t qualityLuma;
	std::uint8_t qualityChroma;
	std::uint8_t qualityNormal;
	std::uint8_t qualitySpecular;
	std::uint8_t qualityPower;
	std::uint8_t flags;
	std::uint16_t diffuseSize;
	std::uint16_t normalSize;
	std::uint16_t specularSize;
	std::uint16_t powerSize;
	std::uint16_t alphaSize;
};

struct HDPHeader_t {
	std::uint8_t qualityDiffuse;
	std::uint8_t qualityNormal;
	std::uint8_t qualitySpecular;
	std::uint8_t qualityPower;
	std::uint8_t flags;
	std::uint8_t pad;
	std::uint16_t diffuseSize;
	std::uint16_t normalSize;
	std::uint16_t specularSize;
	std::uint16_t powerSize;
	std::uint16_t alphaSize;
};

typedef HDPHeader_t JXRHeader_t;
#pragma pack( pop )

int DCT_Compress( const unsigned char * src, int length, unsigned char * dest,
	int maxDestLength, bool storeCover, bool storeAlpha, compressionStats_t * stats );
int HDP_Compress( char * src, int length, unsigned char * dest,
	unsigned int maxDestLength, bool storeCover, bool storeAlpha, compressionStats_t * stats );
int JXR_Compress( char * src, int length, unsigned char * dest,
	unsigned int maxDestLength, bool storeCover, bool storeAlpha, compressionStats_t * stats );

const char * PageCompressionName( pageCompression_t compression );

static_assert( sizeof( DCTHeader_t ) == 16, "Recovered DCT page header size changed" );
static_assert( sizeof( HDPHeader_t ) == 16, "Recovered HDP/JXR page header size changed" );
