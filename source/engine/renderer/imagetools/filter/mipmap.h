#pragma once

class idMipMap {
public:
	static bool CreateSingleMipMultiChannel( const unsigned char * source,
		int width, int height, int channels, unsigned char * destination );
	static bool CreateSingleMip( const unsigned char * source,
		int width, int height, unsigned char * destination );
};
