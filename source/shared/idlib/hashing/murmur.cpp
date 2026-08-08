#include "murmur.h"

#include <cassert>

namespace {

constexpr std::uint32_t MURMUR_MULTIPLIER = 0x5BD1E995u;

std::uint32_t ReadLittleEndian32(const std::uint8_t* data) {
    return static_cast<std::uint32_t>(data[0])
        | (static_cast<std::uint32_t>(data[1]) << 8)
        | (static_cast<std::uint32_t>(data[2]) << 16)
        | (static_cast<std::uint32_t>(data[3]) << 24);
}

std::uint32_t ReadBigEndian32(const std::uint8_t* data) {
    return (static_cast<std::uint32_t>(data[0]) << 24)
        | (static_cast<std::uint32_t>(data[1]) << 16)
        | (static_cast<std::uint32_t>(data[2]) << 8)
        | static_cast<std::uint32_t>(data[3]);
}

std::uint32_t MixWord(std::uint32_t value) {
    value *= MURMUR_MULTIPLIER;
    value ^= value >> 24;
    value *= MURMUR_MULTIPLIER;
    return value;
}

} // namespace

std::uint32_t MurMur32_HashData(
    const void* key,
    const int length,
    const std::uint32_t seed
) {
    assert(length >= 0);
    assert(key != nullptr || length == 0);

    if (length < 0 || (key == nullptr && length != 0)) {
        return 0;
    }

    const auto* data = static_cast<const std::uint8_t*>(key);
    int remaining = length;
    std::uint32_t hash = seed ^ static_cast<std::uint32_t>(length);

    while (remaining >= 4) {
        const std::uint32_t word = MixWord(ReadLittleEndian32(data));
        hash = (hash * MURMUR_MULTIPLIER) ^ word;
        data += 4;
        remaining -= 4;
    }

    switch (remaining) {
        case 3:
            hash ^= static_cast<std::uint32_t>(data[2]) << 16;
            // Fall through.
        case 2:
            hash ^= static_cast<std::uint32_t>(data[1]) << 8;
            // Fall through.
        case 1:
            hash ^= data[0];
            hash *= MURMUR_MULTIPLIER;
            break;
        default:
            break;
    }

    hash ^= hash >> 13;
    hash *= MURMUR_MULTIPLIER;
    hash ^= hash >> 15;
    return hash;
}

std::uint64_t MurMur64_HashData(
    const void* key,
    const int length,
    const std::uint32_t seed
) {
    assert(length >= 0);
    assert(key != nullptr || length == 0);

    if (length < 0 || (key == nullptr && length != 0)) {
        return 0;
    }

    const auto* data = static_cast<const std::uint8_t*>(key);
    int remaining = length;
    std::uint32_t hash1 = seed ^ static_cast<std::uint32_t>(length);
    std::uint32_t hash2 = 0;

    // The recovered 360 function loads full words directly on big-endian PPC,
    // but constructs its one-to-three-byte tail explicitly. Preserve that byte
    // behavior so hashes continue to match the supplied Xbox resource data.
    while (remaining >= 8) {
        hash1 = (hash1 * MURMUR_MULTIPLIER)
            ^ MixWord(ReadBigEndian32(data));
        hash2 = (hash2 * MURMUR_MULTIPLIER)
            ^ MixWord(ReadBigEndian32(data + 4));
        data += 8;
        remaining -= 8;
    }

    if (remaining >= 4) {
        hash1 = (hash1 * MURMUR_MULTIPLIER)
            ^ MixWord(ReadBigEndian32(data));
        data += 4;
        remaining -= 4;
    }

    switch (remaining) {
        case 3:
            hash2 ^= static_cast<std::uint32_t>(data[2]) << 16;
            // Fall through.
        case 2:
            hash2 ^= static_cast<std::uint32_t>(data[1]) << 8;
            // Fall through.
        case 1:
            hash2 ^= data[0];
            hash2 *= MURMUR_MULTIPLIER;
            break;
        default:
            break;
    }

    hash1 ^= hash2 >> 18;
    hash1 *= MURMUR_MULTIPLIER;
    hash2 ^= hash1 >> 22;
    hash2 *= MURMUR_MULTIPLIER;
    hash1 ^= hash2 >> 17;
    hash1 *= MURMUR_MULTIPLIER;
    hash2 ^= hash1 >> 19;
    hash2 *= MURMUR_MULTIPLIER;

    return (static_cast<std::uint64_t>(hash1) << 32) | hash2;
}
