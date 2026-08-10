#pragma once

#include <vector>

enum rendererWICContainer_t {
	RENDERER_WIC_JPEG,
	RENDERER_WIC_JPEG_XR
};

bool RendererWICDecode( const unsigned char * data, unsigned int dataLength,
	std::vector< unsigned char > & rgba, int & width, int & height );

bool RendererWICEncode( const unsigned char * rgba, int width, int height,
	int bytePitch, rendererWICContainer_t container, float quality,
	std::vector< unsigned char > & encoded );
