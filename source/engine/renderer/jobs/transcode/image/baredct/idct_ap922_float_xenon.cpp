#include "baredct.h"

void IDCT_AP922_float_Xenon( const float * input,
		const std::uint16_t * quantTable, float * output ) {
	IDCT_AP922_float( input, quantTable, output );
}

