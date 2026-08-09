#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <type_traits>

class idSwap {
public:
    template<typename type>
    static void Little(type&) {
        static_assert(!std::is_pointer<type>::value,
            "serialized pointers cannot be endian swapped");
    }

    template<typename type>
    static void Big(type& value) {
        static_assert(!std::is_pointer<type>::value,
            "serialized pointers cannot be endian swapped");
        unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
        std::reverse(bytes, bytes + sizeof(type));
    }

    template<typename type>
    static void LittleArray(type*, int) {
    }

    template<typename type>
    static void BigArray(type* values, const int count) {
        for (int index = 0; index < count; ++index) Big(values[index]);
    }

    static void SixtetsForInt(unsigned char* output, const int source) {
        const unsigned int value = static_cast<unsigned int>(source);
        output[0] = static_cast<unsigned char>((value >> 18) & 0x3F);
        output[1] = static_cast<unsigned char>((value >> 12) & 0x3F);
        output[2] = static_cast<unsigned char>((value >> 6) & 0x3F);
        output[3] = static_cast<unsigned char>(value & 0x3F);
    }

    static int IntForSixtets(const unsigned char* input) {
        return static_cast<int>((static_cast<unsigned int>(input[0]) << 18)
            | (static_cast<unsigned int>(input[1]) << 12)
            | (static_cast<unsigned int>(input[2]) << 6)
            | static_cast<unsigned int>(input[3]));
    }
};

static_assert(sizeof(idSwap) == 1, "Recovered idSwap must remain empty");

