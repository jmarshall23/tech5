#include "baredct.h"

// Keep the retail symbol names for page-file/tool compatibility.  The PC
// variants are scalar because x86 has no Xenon VMX128 register conventions.
void idBareDctBase::ScaleQuantTable_Xenon( std::uint16_t * destination,
		const std::uint16_t * source, const int scale ) {
	ScaleQuantTable( destination, source, scale );
}

void idBareDctBase::SetQuality_Xenon( const int luminance,
		const int chrominance, const int alpha ) {
	SetQuality_Generic( luminance, chrominance, alpha );
}

