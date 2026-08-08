#include "crc16.h"

#include <array>
#include <cassert>
#include <cstddef>

namespace {

using CrcTable = std::array<std::uint16_t, 256>;

CrcTable BuildCrcTable() {
    CrcTable table = {};

    for (std::size_t index = 0; index < table.size(); ++index) {
        std::uint16_t value = static_cast<std::uint16_t>(index << 8);
        for (int bit = 0; bit < 8; ++bit) {
            value = (value & 0x8000u) != 0
                ? static_cast<std::uint16_t>((value << 1) ^ 0x1021u)
                : static_cast<std::uint16_t>(value << 1);
        }
        table[index] = value;
    }

    return table;
}

const CrcTable& GetCrcTable() {
    static const CrcTable table = BuildCrcTable();
    return table;
}

} // namespace

void CRC16_UpdateChecksum(
    std::uint16_t& crcValue,
    const void* data,
    const int length
) {
    assert(length >= 0);
    assert(data != nullptr || length == 0);

    if (length <= 0) {
        return;
    }

    const CrcTable& table = GetCrcTable();
    const auto* bytes = static_cast<const std::uint8_t*>(data);

    for (int index = 0; index < length; ++index) {
        const std::uint8_t tableIndex = static_cast<std::uint8_t>(
            (crcValue >> 8) ^ bytes[index]
        );
        crcValue = static_cast<std::uint16_t>(
            table[tableIndex] ^ static_cast<std::uint16_t>(crcValue << 8)
        );
    }
}

