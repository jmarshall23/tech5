#include "crc32.h"

#include <array>
#include <cstdint>

namespace {

const std::uint32_t* CRC32Table() {
    static const std::array<std::uint32_t, 256> table = [] {
        std::array<std::uint32_t, 256> values = {};
        for (std::uint32_t index = 0; index < 256; ++index) {
            std::uint32_t value = index;
            for (int bit = 0; bit < 8; ++bit)
                value = (value >> 1) ^ ((value & 1) != 0 ? 0xEDB88320u : 0u);
            values[index] = value;
        }
        return values;
    }();
    return table.data();
}

} // namespace

void CRC32_UpdateChecksum(unsigned int& checksum, const void* data,
        const int length) {
    if (data == nullptr || length <= 0) return;
    const std::uint32_t* const table = CRC32Table();
    const unsigned char* bytes = static_cast<const unsigned char*>(data);
    for (int index = 0; index < length; ++index)
        checksum = table[(checksum ^ bytes[index]) & 0xFFu] ^ (checksum >> 8);
}

void CRC32_FinishChecksum(unsigned int& checksum) {
    checksum = ~checksum;
}

unsigned int CRC32_BlockChecksum(const void* data, const int length) {
    unsigned int checksum = 0xFFFFFFFFu;
    CRC32_UpdateChecksum(checksum, data, length);
    CRC32_FinishChecksum(checksum);
    return checksum;
}
