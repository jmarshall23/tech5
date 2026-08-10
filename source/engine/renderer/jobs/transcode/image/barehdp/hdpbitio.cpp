#include "hdpbitio.h"

#include <cstring>

hdpError_t CreateWS_Memory( hdpStream_t * stream, void * memory, const unsigned int size ) {
	if ( stream == nullptr || memory == nullptr || size == 0 ) return HDP_ERROR_INVALID_ARGUMENT;
	stream->memory = static_cast< unsigned char * >( memory );
	stream->size = size;
	stream->position = 0;
	stream->writable = true;
	return HDP_OK;
}
hdpError_t ReadWS_Memory( hdpStream_t * stream, void * output, const unsigned int bytes ) {
	if ( stream == nullptr || output == nullptr || bytes > stream->size - stream->position )
		return HDP_ERROR_END_OF_STREAM;
	std::memcpy( output, stream->memory + stream->position, bytes );
	stream->position += bytes;
	return HDP_OK;
}
hdpError_t WriteWS_Memory( hdpStream_t * stream, const void * input, const unsigned int bytes ) {
	if ( stream == nullptr || input == nullptr || !stream->writable ||
		bytes > stream->size - stream->position ) return HDP_ERROR_END_OF_STREAM;
	std::memcpy( stream->memory + stream->position, input, bytes );
	stream->position += bytes;
	return HDP_OK;
}
void * WritePtrWS_Memory( hdpStream_t * stream ) {
	return stream == nullptr ? nullptr : stream->memory + stream->position;
}
void * EndPtrWS_Memory( hdpStream_t * stream ) {
	return stream == nullptr ? nullptr : stream->memory + stream->size;
}
hdpError_t SetPosWS_Memory( hdpStream_t * stream, const unsigned int position ) {
	if ( stream == nullptr || position > stream->size ) return HDP_ERROR_INVALID_ARGUMENT;
	stream->position = position;
	return HDP_OK;
}
hdpError_t GetPosWS_Memory( hdpStream_t * stream, unsigned int * position ) {
	if ( stream == nullptr || position == nullptr ) return HDP_ERROR_INVALID_ARGUMENT;
	*position = stream->position;
	return HDP_OK;
}
