#pragma once

#include <cstddef>
#include <cstdint>

struct rbitstream {
	const unsigned char * data;
	std::size_t size;
	std::size_t bitPosition;
	std::size_t mark;
};
struct wbitstream {
	unsigned char * data;
	std::size_t size;
	std::size_t bitPosition;
	std::size_t mark;
};
struct jxr_image {
	int width, height;
	void * userData;
};

int _jxr_floor_div2( int value );
int _jxr_ceil_div2( int value );
void _jxr_2ptT( int * a, int * b );
void _jxr_2ptFwdT( int * a, int * b );
void _jxr_2x2IPCT( int * values );
void _jxr_4x4IPCT( int * values );
void _jxr_4x4PCT( int * values );

unsigned int _jxr_rbitstream_uintN( rbitstream *, int bits );
void _jxr_wbitstream_uintN( wbitstream *, unsigned int value, int bits );
void _jxr_wbitstream_flush( wbitstream * );
