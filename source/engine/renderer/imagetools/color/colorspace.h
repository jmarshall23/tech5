#pragma once

class idColorSpace {
public:
	static void ConvertRGBToCoCg_Y( unsigned char * destination,
		const unsigned char * source, int width, int height );
	static void ConvertCoCg_YToRGB( unsigned char * destination,
		const unsigned char * source, int width, int height );
};
