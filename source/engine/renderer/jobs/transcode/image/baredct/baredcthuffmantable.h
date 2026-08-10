#pragma once

#include <cstdint>

enum huffmanType_t : int {
	HUFFMAN_DC_LUMINANCE = 0,
	HUFFMAN_AC_LUMINANCE = 1,
	HUFFMAN_DC_CHROMINANCE = 2,
	HUFFMAN_AC_CHROMINANCE = 3
};

class idBareDCTHuffmanTable {
public:
	idBareDCTHuffmanTable( huffmanType_t type = HUFFMAN_DC_LUMINANCE,
		bool decoderTable = false );

	unsigned int code[256];
	char size[256];
	std::uint8_t look_nbits[256];
	std::uint8_t look_sym[256];
	std::uint8_t symbols[256];
	int test_nbits[16];
	int minCode[17];
	int maxCode[18];
	int symOffset[17];

private:
	void Init( const std::uint8_t * bitCounts,
		const std::uint8_t * values, bool decoderTable );
};

