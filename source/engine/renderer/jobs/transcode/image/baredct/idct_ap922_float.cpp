#include "baredct.h"

#include <cmath>

void IDCT_AP922_float( const float * input, const std::uint16_t * quantTable,
		float * output ) {
	if ( input == nullptr || output == nullptr ) return;
	static const float kPi = 3.14159265358979323846f;
	for ( int y = 0; y < 8; ++y ) for ( int x = 0; x < 8; ++x ) {
		float sum = 0.0f;
		for ( int v = 0; v < 8; ++v ) for ( int u = 0; u < 8; ++u ) {
			const float cu = u == 0 ? 0.70710678118f : 1.0f;
			const float cv = v == 0 ? 0.70710678118f : 1.0f;
			const float q = quantTable != nullptr ? static_cast< float >( quantTable[v * 8 + u] ) : 1.0f;
			sum += cu * cv * input[v * 8 + u] * q *
				std::cos( ( 2 * x + 1 ) * u * kPi / 16.0f ) *
				std::cos( ( 2 * y + 1 ) * v * kPi / 16.0f );
		}
		output[y * 8 + x] = 0.25f * sum;
	}
}

