#pragma once

#include <cstdint>

class idImage;

struct alignas( 4 ) videoTranscodeParms_t {
	std::uint8_t dctQualityLuma;
	std::uint8_t dctQualityChroma;
	std::uint8_t * dctBuffer;
	int dctBufferSize;
	idImage * image;
	std::uint8_t * dxtBuffer;
	int targetBytePitch;
	bool needSubImageUpload;
};

void VideoTranscodeJob( videoTranscodeParms_t & parms );

#if defined( _M_IX86 )
static_assert( sizeof( videoTranscodeParms_t ) == 28,
	"Recovered video transcode parameter ABI changed" );
#endif
