#include "md5.h"

#include <cstdint>
#include <cstring>

namespace {

std::uint32_t RotateLeft(const std::uint32_t value, const int amount) {
    return (value << amount) | (value >> (32 - amount));
}

std::uint32_t LoadLittle32(const unsigned char* bytes) {
    return static_cast<std::uint32_t>(bytes[0])
        | (static_cast<std::uint32_t>(bytes[1]) << 8)
        | (static_cast<std::uint32_t>(bytes[2]) << 16)
        | (static_cast<std::uint32_t>(bytes[3]) << 24);
}

void StoreLittle32(unsigned char* bytes, const std::uint32_t value) {
    bytes[0] = static_cast<unsigned char>(value);
    bytes[1] = static_cast<unsigned char>(value >> 8);
    bytes[2] = static_cast<unsigned char>(value >> 16);
    bytes[3] = static_cast<unsigned char>(value >> 24);
}

} // namespace

void MD5_Transform(unsigned int state[4], const unsigned char block[64]) {
    static const int shifts[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };
    static const std::uint32_t constants[64] = {
        0xd76aa478u, 0xe8c7b756u, 0x242070dbu, 0xc1bdceeeu,
        0xf57c0fafu, 0x4787c62au, 0xa8304613u, 0xfd469501u,
        0x698098d8u, 0x8b44f7afu, 0xffff5bb1u, 0x895cd7beu,
        0x6b901122u, 0xfd987193u, 0xa679438eu, 0x49b40821u,
        0xf61e2562u, 0xc040b340u, 0x265e5a51u, 0xe9b6c7aau,
        0xd62f105du, 0x02441453u, 0xd8a1e681u, 0xe7d3fbc8u,
        0x21e1cde6u, 0xc33707d6u, 0xf4d50d87u, 0x455a14edu,
        0xa9e3e905u, 0xfcefa3f8u, 0x676f02d9u, 0x8d2a4c8au,
        0xfffa3942u, 0x8771f681u, 0x6d9d6122u, 0xfde5380cu,
        0xa4beea44u, 0x4bdecfa9u, 0xf6bb4b60u, 0xbebfbc70u,
        0x289b7ec6u, 0xeaa127fau, 0xd4ef3085u, 0x04881d05u,
        0xd9d4d039u, 0xe6db99e5u, 0x1fa27cf8u, 0xc4ac5665u,
        0xf4292244u, 0x432aff97u, 0xab9423a7u, 0xfc93a039u,
        0x655b59c3u, 0x8f0ccc92u, 0xffeff47du, 0x85845dd1u,
        0x6fa87e4fu, 0xfe2ce6e0u, 0xa3014314u, 0x4e0811a1u,
        0xf7537e82u, 0xbd3af235u, 0x2ad7d2bbu, 0xeb86d391u
    };

    std::uint32_t words[16];
    for (int index = 0; index < 16; ++index)
        words[index] = LoadLittle32(block + index * 4);

    std::uint32_t a = state[0];
    std::uint32_t b = state[1];
    std::uint32_t c = state[2];
    std::uint32_t d = state[3];
    for (int index = 0; index < 64; ++index) {
        std::uint32_t function;
        int wordIndex;
        if (index < 16) {
            function = (b & c) | (~b & d);
            wordIndex = index;
        } else if (index < 32) {
            function = (d & b) | (~d & c);
            wordIndex = (5 * index + 1) & 15;
        } else if (index < 48) {
            function = b ^ c ^ d;
            wordIndex = (3 * index + 5) & 15;
        } else {
            function = c ^ (b | ~d);
            wordIndex = (7 * index) & 15;
        }
        const std::uint32_t oldD = d;
        d = c;
        c = b;
        b += RotateLeft(a + function + constants[index] + words[wordIndex],
            shifts[index]);
        a = oldD;
    }
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

void MD5_Init(MD5_CTX* context) {
    context->state[0] = 0x67452301u;
    context->state[1] = 0xefcdab89u;
    context->state[2] = 0x98badcfeu;
    context->state[3] = 0x10325476u;
    context->bits[0] = 0;
    context->bits[1] = 0;
    std::memset(context->in, 0, sizeof(context->in));
}

void MD5_Update(MD5_CTX* context, const unsigned char* input,
        const unsigned int inputLength) {
    if (inputLength == 0) return;
    const unsigned int oldLowBits = context->bits[0];
    const unsigned int bufferIndex = (oldLowBits >> 3) & 63u;
    context->bits[0] += inputLength << 3;
    if (context->bits[0] < oldLowBits) ++context->bits[1];
    context->bits[1] += inputLength >> 29;

    unsigned int consumed = 0;
    const unsigned int firstBlock = 64u - bufferIndex;
    if (inputLength >= firstBlock) {
        std::memcpy(context->in + bufferIndex, input, firstBlock);
        MD5_Transform(context->state, context->in);
        consumed = firstBlock;
        while (consumed + 63u < inputLength) {
            MD5_Transform(context->state, input + consumed);
            consumed += 64;
        }
        std::memcpy(context->in, input + consumed, inputLength - consumed);
    } else {
        std::memcpy(context->in + bufferIndex, input, inputLength);
    }
}

void MD5_Final(MD5_CTX* context, unsigned char digest[16]) {
    static const unsigned char padding[64] = { 0x80 };
    unsigned char bitCount[8];
    StoreLittle32(bitCount, context->bits[0]);
    StoreLittle32(bitCount + 4, context->bits[1]);
    const unsigned int bufferIndex = (context->bits[0] >> 3) & 63u;
    const unsigned int paddingLength = bufferIndex < 56
        ? 56u - bufferIndex : 120u - bufferIndex;
    MD5_Update(context, padding, paddingLength);
    MD5_Update(context, bitCount, sizeof(bitCount));
    for (int index = 0; index < 4; ++index)
        StoreLittle32(digest + index * 4, context->state[index]);
    std::memset(context, 0, sizeof(*context));
}

unsigned int MD5_BlockChecksum(const void* data, const unsigned int length) {
    MD5_CTX context;
    unsigned char digest[16];
    MD5_Init(&context);
    MD5_Update(&context, static_cast<const unsigned char*>(data), length);
    MD5_Final(&context, digest);
    return LoadLittle32(digest) ^ LoadLittle32(digest + 4)
        ^ LoadLittle32(digest + 8) ^ LoadLittle32(digest + 12);
}
