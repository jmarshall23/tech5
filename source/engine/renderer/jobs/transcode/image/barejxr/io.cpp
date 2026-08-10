#include "jxr_compat.h"

unsigned int _jxr_rbitstream_uintN( rbitstream * stream, const int bits ) {
	if ( stream == nullptr || bits < 0 || bits > 32 ) return 0;
	unsigned int value = 0;
	for ( int i = 0; i < bits; ++i ) {
		value <<= 1;
		if ( stream->bitPosition < stream->size * 8 ) {
			const std::size_t bit = stream->bitPosition++;
			value |= ( stream->data[bit >> 3] >> ( 7 - ( bit & 7 ) ) ) & 1u;
		}
	}
	return value;
}
void _jxr_wbitstream_uintN( wbitstream * stream, unsigned int value, const int bits ) {
	if ( stream == nullptr || bits < 0 || bits > 32 ) return;
	for ( int i = bits - 1; i >= 0; --i ) {
		if ( stream->bitPosition >= stream->size * 8 ) return;
		const std::size_t bit = stream->bitPosition++;
		const unsigned char mask = static_cast< unsigned char >( 1u << ( 7 - ( bit & 7 ) ) );
		if ( ( value >> i ) & 1u ) stream->data[bit >> 3] |= mask;
		else stream->data[bit >> 3] &= static_cast< unsigned char >( ~mask );
	}
}
void _jxr_wbitstream_flush( wbitstream * stream ) {
	if ( stream != nullptr ) stream->bitPosition = ( stream->bitPosition + 7u ) & ~std::size_t( 7u );
}
