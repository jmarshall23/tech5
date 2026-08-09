#pragma once

#include "idlib/text/atomicstring.h"

class idMD6Node;

struct idScalarMemBlock {
    float* floats;
    int num;
};

class idAnimWebScalar {
public:
    enum flags_t : int { AWSFLAG_INIT_TO_1 = 1 };

    idAtomicString name;
    unsigned char flags;
    short scalarIndex;
    float* scalarPtr;
};

class idAnimWebScalarPair {
public:
    enum fieldFlag_t : int {
        FF_NO_OVERRIDE = 0,
        FF_COPY_PRE_BLEND = 1,
        FF_COPY_ON_PLAY = 2,
        FF_INDEX_MODULO = 4,
        FF_INDEX_OFFSET = 8,
        FF_INDEX_TAG = 16
    };
    enum scalarType_t : int {
        FT_CUR_ALPHA = 0,
        FT_RATE_SCALE = 1,
        FT_ANIMATION = 2,
        FT_PAUSE_FRAME = 3,
        FT_COORDINATE = 4
    };

    int scalarIndex;
    int coordinateIndex;
    idMD6Node* node;
    unsigned char fieldType;
    unsigned char fieldFlags;
    unsigned char data1;
    unsigned char data2;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idScalarMemBlock) == 8,
    "Recovered scalar memory block ABI changed");
static_assert(sizeof(idAnimWebScalar) == 12,
    "Recovered animation-web scalar ABI changed");
static_assert(sizeof(idAnimWebScalarPair) == 16,
    "Recovered animation-web scalar pair ABI changed");
#endif
