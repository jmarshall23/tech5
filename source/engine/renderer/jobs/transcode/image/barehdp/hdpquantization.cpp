#include "hdpquantization.h"

unsigned char GetQuantizerBits( const unsigned char channels ) {
	return channels <= 1 ? 4 : 5;
}
