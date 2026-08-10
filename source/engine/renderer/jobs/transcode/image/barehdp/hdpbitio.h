#pragma once

#include <cstdint>

enum hdpError_t : int {
	HDP_OK = 0,
	HDP_ERROR_INVALID_ARGUMENT = -1,
	HDP_ERROR_END_OF_STREAM = -2,
	HDP_ERROR_OUT_OF_MEMORY = -3
};

struct hdpStream_t {
	unsigned char * memory;
	unsigned int size;
	unsigned int position;
	bool writable;
};

struct hdpBitIO_t {
	std::uint64_t bitBuff;
	std::uint64_t bitCnt;
	unsigned char * byteBufStart;
	unsigned char * byteBufEnd;
	unsigned char * byteBufCur;
	unsigned int byteCount;
	hdpStream_t * stream;
	unsigned int streamOffset;
};

hdpError_t ReadWS_Memory( hdpStream_t *, void *, unsigned int );
hdpError_t WriteWS_Memory( hdpStream_t *, const void *, unsigned int );
void * WritePtrWS_Memory( hdpStream_t * );
void * EndPtrWS_Memory( hdpStream_t * );
hdpError_t SetPosWS_Memory( hdpStream_t *, unsigned int );
hdpError_t GetPosWS_Memory( hdpStream_t *, unsigned int * );
hdpError_t CreateWS_Memory( hdpStream_t *, void *, unsigned int );
hdpError_t StreamReadAttach( hdpBitIO_t *, hdpStream_t * );
hdpError_t StreamReadDetach( hdpBitIO_t * );
hdpError_t StreamWriteAttach( hdpBitIO_t *, hdpStream_t * );
hdpError_t StreamWriteDetach( hdpBitIO_t * );
void WriteBits16( hdpBitIO_t *, unsigned int, unsigned int );
void WriteBits32( hdpBitIO_t *, unsigned int, unsigned int );
void WriteUpToByte( hdpBitIO_t * );
unsigned int GetWritePos( hdpBitIO_t * );
