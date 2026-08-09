#include "base64.h"

namespace {

int DecodeCharacter(const unsigned char character) {
    if (character >= 'A' && character <= 'Z') return character - 'A';
    if (character >= 'a' && character <= 'z') return character - 'a' + 26;
    if (character >= '0' && character <= '9') return character - '0' + 52;
    if (character == '+') return 62;
    if (character == '/') return 63;
    return -1;
}

} // namespace

void idBase64::Encode(const unsigned char* source, const int size) {
    static const unsigned char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if (source == nullptr || size <= 0) {
        if (EnsureAlloced(1)) data[0] = 0;
        len = 0;
        return;
    }
    const int outputLength = ((size + 2) / 3) * 4;
    if (!EnsureAlloced(outputLength + 1)) return;
    len = 0;
    int input = 0;
    while (input + 2 < size) {
        const unsigned int value = (static_cast<unsigned int>(source[input]) << 16)
            | (static_cast<unsigned int>(source[input + 1]) << 8)
            | source[input + 2];
        data[len++] = alphabet[(value >> 18) & 63];
        data[len++] = alphabet[(value >> 12) & 63];
        data[len++] = alphabet[(value >> 6) & 63];
        data[len++] = alphabet[value & 63];
        input += 3;
    }
    if (size - input == 1) {
        const unsigned int value = static_cast<unsigned int>(source[input]) << 16;
        data[len++] = alphabet[(value >> 18) & 63];
        data[len++] = alphabet[(value >> 12) & 63];
        data[len++] = '=';
        data[len++] = '=';
    } else if (size - input == 2) {
        const unsigned int value = (static_cast<unsigned int>(source[input]) << 16)
            | (static_cast<unsigned int>(source[input + 1]) << 8);
        data[len++] = alphabet[(value >> 18) & 63];
        data[len++] = alphabet[(value >> 12) & 63];
        data[len++] = alphabet[(value >> 6) & 63];
        data[len++] = '=';
    }
    data[len] = 0;
}

int idBase64::Decode(unsigned char* destination) const {
    if (destination == nullptr || data == nullptr || len == 0
        || (len & 3) != 0) return 0;
    int output = 0;
    for (int input = 0; input < len; input += 4) {
        const bool lastGroup = input + 4 == len;
        const bool pad2 = data[input + 2] == '=';
        const bool pad3 = data[input + 3] == '=';
        if ((!lastGroup && (pad2 || pad3)) || (pad2 && !pad3)) return 0;
        const int a = DecodeCharacter(data[input]);
        const int b = DecodeCharacter(data[input + 1]);
        const int c = pad2 ? 0 : DecodeCharacter(data[input + 2]);
        const int d = pad3 ? 0 : DecodeCharacter(data[input + 3]);
        if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
        const unsigned int value = (static_cast<unsigned int>(a) << 18)
            | (static_cast<unsigned int>(b) << 12)
            | (static_cast<unsigned int>(c) << 6)
            | static_cast<unsigned int>(d);
        destination[output++] = static_cast<unsigned char>(value >> 16);
        if (!pad2) destination[output++] = static_cast<unsigned char>(value >> 8);
        if (!pad3) destination[output++] = static_cast<unsigned char>(value);
    }
    destination[output] = 0;
    return output;
}
