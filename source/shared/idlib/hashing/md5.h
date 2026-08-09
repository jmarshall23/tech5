#pragma once

struct MD5_CTX {
    unsigned int state[4];
    unsigned int bits[2];
    unsigned char in[64];
};

void MD5_Transform(unsigned int state[4], const unsigned char block[64]);
void MD5_Init(MD5_CTX* context);
void MD5_Update(MD5_CTX* context, const unsigned char* input,
    unsigned int inputLength);
void MD5_Final(MD5_CTX* context, unsigned char digest[16]);
unsigned int MD5_BlockChecksum(const void* data, unsigned int length);

static_assert(sizeof(MD5_CTX) == 88, "Recovered MD5_CTX layout changed");
