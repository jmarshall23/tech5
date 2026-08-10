#include "color.h"

// Retail symbol: ??0ssColor@@QAA@HHHH@Z
// EA: 0x82EE6DC8, RVA: 0x00EE6DC8
// Hex-Rays could not allocate the four PPC argument locals and interleaved
// their registers. The decorated signature, PDB field order, and common
// 1/256 scale resolve the source-level component mapping.
ssColor::ssColor(const int red, const int green, const int blue,
        const int alpha)
    : r(static_cast<float>(red) * (1.0f / 256.0f))
    , g(static_cast<float>(green) * (1.0f / 256.0f))
    , b(static_cast<float>(blue) * (1.0f / 256.0f))
    , a(static_cast<float>(alpha) * (1.0f / 256.0f)) {
}
