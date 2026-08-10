#include "hdpcodec.h"

#include <algorithm>

unsigned int HDPEstimateTempMemory( const int width, const int height, const int channels ) {
	if ( width <= 0 || height <= 0 || channels <= 0 ) return 0;
	return static_cast< unsigned int >( width ) * height * (std::max)( channels, 1 ) + 4096u;
}
