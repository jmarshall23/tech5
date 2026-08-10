#include "baredct.h"

#include <algorithm>

namespace {
	const std::uint16_t kLumaQuant[64] = {
		16,11,10,16,24,40,51,61, 12,12,14,19,26,58,60,55,
		14,13,16,24,40,57,69,56, 14,17,22,29,51,87,80,62,
		18,22,37,56,68,109,103,77, 24,35,55,64,81,104,113,92,
		49,64,78,87,103,121,120,101, 72,92,95,98,112,100,103,99
	};
	const std::uint16_t kChromaQuant[64] = {
		17,18,24,47,99,99,99,99, 18,21,26,66,99,99,99,99,
		24,26,56,99,99,99,99,99, 47,66,99,99,99,99,99,99,
		99,99,99,99,99,99,99,99, 99,99,99,99,99,99,99,99,
		99,99,99,99,99,99,99,99, 99,99,99,99,99,99,99,99
	};
}

idBareDctBase::idBareDctBase() : luminanceQuality( 75 ),
	chrominanceQuality( 75 ), alphaQuality( 75 ), sampleMode( SAMPLE_MODE_420 ) {
	InitQuantTable();
}

int idBareDctBase::QuantizationScaleFromQuality( int quality ) {
	quality = (std::max)( 1, (std::min)( quality, 100 ) );
	return quality < 50 ? 5000 / quality : 200 - quality * 2;
}

void idBareDctBase::ScaleQuantTable( std::uint16_t * destination,
		const std::uint16_t * source, const int scale ) {
	for ( int i = 0; i < 64; ++i )
		destination[i] = static_cast< std::uint16_t >(
			( std::max )( 1, ( std::min )( 255, ( source[i] * scale + 50 ) / 100 ) ) );
}

void idBareDctBase::InitQuantTable() {
	ScaleQuantTable( quantTableY, kLumaQuant,
		QuantizationScaleFromQuality( luminanceQuality ) );
	ScaleQuantTable( quantTableCoCg, kChromaQuant,
		QuantizationScaleFromQuality( chrominanceQuality ) );
	ScaleQuantTable( quantTableA, kLumaQuant,
		QuantizationScaleFromQuality( alphaQuality ) );
}

void idBareDctBase::SetQuality_Generic( const int luminance,
		const int chrominance, const int alpha ) {
	luminanceQuality = (std::max)( 1, (std::min)( luminance, 100 ) );
	chrominanceQuality = (std::max)( 1, (std::min)( chrominance, 100 ) );
	alphaQuality = (std::max)( 1, (std::min)( alpha, 100 ) );
	InitQuantTable();
}

