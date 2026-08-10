#include "videotranscode.h"

#include "../transcode/image/dxt/dxtcodec.h"
#include "../transcode/image/wiccodec.h"
#include "../../image.h"

#include <cstring>
#include <vector>

void VideoTranscodeJob( videoTranscodeParms_t & parms ) {
	if ( parms.dctBuffer == nullptr || parms.dctBufferSize <= 0 ||
		parms.dxtBuffer == nullptr ) return;
	std::vector< unsigned char > rgba;
	int width = 0, height = 0;
	if ( !RendererWICDecode( parms.dctBuffer, parms.dctBufferSize,
		rgba, width, height ) || width != 128 || height != 128 ) return;
	std::vector< unsigned char > blocks( 128 * 128 );
	idDxtEncoder encoder;
	encoder.CompressImageDXT5HQ( rgba.data(), blocks.data(), 128, 128 );
	const int targetPitch = parms.targetBytePitch > 0 ? parms.targetBytePitch : 512;
	for ( int row = 0; row < 32; ++row )
		std::memcpy( parms.dxtBuffer + row * targetPitch,
			blocks.data() + row * 512, 512 );
	if ( parms.needSubImageUpload && parms.image != nullptr )
		parms.image->SubImageUpload( 0, 0, 0, 0, 128, 128,
			parms.dxtBuffer, targetPitch );
}
