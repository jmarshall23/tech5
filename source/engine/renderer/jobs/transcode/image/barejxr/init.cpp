#include "jxr_compat.h"

int jxr_image_size() { return sizeof( jxr_image ); }
int jxr_estimate_temp_memory( const int width, const int height, const int channels ) {
	return width > 0 && height > 0 && channels > 0 ? width * height * channels + 4096 : 0;
}
