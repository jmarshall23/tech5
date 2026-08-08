#pragma once

#include <cstdint>

// Recovered from ?CRC16_UpdateChecksum@@YAXAAGPBXH@Z at 0x82F2BE00.
// The reference parameter and const void pointer match the decorated PDB name;
// Hex-Rays displayed the reference as a pointer in the raw 360 dump.
void CRC16_UpdateChecksum(
    std::uint16_t& crcValue,
    const void* data,
    int length
);

