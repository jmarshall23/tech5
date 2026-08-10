#include "baredcthuffmantable.h"

#include <cstring>

idBareDCTHuffmanTable::idBareDCTHuffmanTable( const huffmanType_t,
		const bool decoderTable ) {
	static const std::uint8_t counts[16] = { 0, 1, 5, 1, 1, 1, 1, 1 };
	static const std::uint8_t values[256] = {};
	Init( counts, values, decoderTable );
}

void idBareDCTHuffmanTable::Init( const std::uint8_t * bitCounts,
		const std::uint8_t * values, const bool ) {
	std::memset( this, 0, sizeof( *this ) );
	unsigned int nextCode = 0;
	int symbol = 0;
	for ( int bits = 1; bits <= 16; ++bits ) {
		minCode[bits] = bitCounts[bits - 1] != 0 ? static_cast< int >( nextCode ) : -1;
		symOffset[bits] = symbol - static_cast< int >( nextCode );
		for ( int i = 0; i < bitCounts[bits - 1] && symbol < 256; ++i, ++symbol ) {
			const unsigned char value = values[symbol];
			code[value] = nextCode++;
			size[value] = static_cast< char >( bits );
			symbols[symbol] = value;
		}
		maxCode[bits] = bitCounts[bits - 1] != 0 ? static_cast< int >( nextCode - 1 ) : -1;
		nextCode <<= 1;
	}
	maxCode[17] = 0x7fffffff;
}

