#pragma once

#include <cstdint>

// PDB signatures:
//   ?MurMur32_HashData@@YAIPBXHI@Z
//   ?MurMur64_HashData@@YA_KPBXHI@Z
std::uint32_t MurMur32_HashData(
    const void* key,
    int length,
    std::uint32_t seed
);

std::uint64_t MurMur64_HashData(
    const void* key,
    int length,
    std::uint32_t seed
);

