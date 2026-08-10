#include "hdpbitio.h"

#include <cstring>

hdpError_t StreamReadAttach( hdpBitIO_t * bitIO, hdpStream_t * stream ) {
	if ( bitIO == nullptr || stream == nullptr ) return HDP_ERROR_INVALID_ARGUMENT;
	std::memset( bitIO, 0, sizeof( *bitIO ) );
	bitIO->stream = stream;
	bitIO->byteBufStart = stream->memory;
	bitIO->byteBufCur = stream->memory + stream->position;
	bitIO->byteBufEnd = stream->memory + stream->size;
	return HDP_OK;
}
hdpError_t StreamReadDetach( hdpBitIO_t * bitIO ) {
	if ( bitIO == nullptr || bitIO->stream == nullptr ) return HDP_ERROR_INVALID_ARGUMENT;
	bitIO->stream->position = static_cast< unsigned int >( bitIO->byteBufCur - bitIO->byteBufStart );
	bitIO->stream = nullptr;
	return HDP_OK;
}
