#pragma once

// Portable image-filter vocabulary.  Hex-Rays also attributed unrelated MD6
// and AI symbols to this basename; they are deliberately not renderer types.
class idFilter {
public:
	enum bicubicFilter_t : int {
		BICUBIC_PHOTOSHOP = 0,
		BICUBIC_SHIFTED = 1
	};
};

struct aiFilter_t {
	const char * filterName;
	int filter;
};
