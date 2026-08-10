#include "hdpbitio.h"

#include <cstring>

namespace {
	void WriteBits( hdpBitIO_t * io, const unsigned int value, const unsigned int count ) {
		if ( io == nullptr || count > 32 ) return;
		for ( int bit = static_cast< int >( count ) - 1; bit >= 0; --bit ) {
			io->bitBuff = ( io->bitBuff << 1 ) | ( ( value >> bit ) & 1u );
			++io->bitCnt;
			if ( io->bitCnt == 8 ) {
				if ( io->byteBufCur < io->byteBufEnd ) *io->byteBufCur++ = static_cast< unsigned char >( io->bitBuff );
				io->bitBuff = io->bitCnt = 0;
			}
		}
	}
}
hdpError_t StreamWriteAttach( hdpBitIO_t * bitIO, hdpStream_t * stream ) {
	if ( bitIO == nullptr || stream == nullptr || !stream->writable ) return HDP_ERROR_INVALID_ARGUMENT;
	std::memset( bitIO, 0, sizeof( *bitIO ) );
	bitIO->stream = stream;
	bitIO->byteBufStart = stream->memory;
	bitIO->byteBufCur = stream->memory + stream->position;
	bitIO->byteBufEnd = stream->memory + stream->size;
	return HDP_OK;
}
void WriteBits16( hdpBitIO_t * io, unsigned int value, unsigned int bits ) { WriteBits( io, value, bits ); }
void WriteBits32( hdpBitIO_t * io, unsigned int value, unsigned int bits ) { WriteBits( io, value, bits ); }
void WriteUpToByte( hdpBitIO_t * io ) {
	if ( io != nullptr && io->bitCnt != 0 ) WriteBits( io, 0, 8u - static_cast< unsigned int >( io->bitCnt ) );
}
unsigned int GetWritePos( hdpBitIO_t * io ) {
	return io == nullptr ? 0 : static_cast< unsigned int >( io->byteBufCur - io->byteBufStart );
}
hdpError_t StreamWriteDetach( hdpBitIO_t * bitIO ) {
	if ( bitIO == nullptr || bitIO->stream == nullptr ) return HDP_ERROR_INVALID_ARGUMENT;
	WriteUpToByte( bitIO );
	bitIO->stream->position = GetWritePos( bitIO );
	bitIO->stream = nullptr;
	return HDP_OK;
}
