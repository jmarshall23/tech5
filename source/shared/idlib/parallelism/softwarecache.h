#pragma once

#include <cstdint>

// All four recovered template instantiations occupy exactly 128 bytes.  The
// Xbox cache machinery is opaque until its call sites are ported, but the
// generic declaration and storage contract are now available to PC headers.
template<typename elementType, int cacheLines, int associativity>
class idSoftwareCache {
public:
    std::uint8_t storage[128];
};

static_assert(sizeof(idSoftwareCache<int, 1, 4>) == 128,
    "Recovered idSoftwareCache ABI changed");

