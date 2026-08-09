#pragma once

#include "idlib/text/atomicstring.h"

class idMD6Node;
template<typename type, int memoryTag> class idList;

struct idScalarMemBlock {
    idScalarMemBlock() : floats(nullptr), num(0) {}
    ~idScalarMemBlock();

    void Alloc(int count);
    void Free();
    void Free(idList<class idAnimWebScalar, 5>& scalars);
    void Free(idList<class idAnimWebScalar, 33>& scalars);

    float* floats;
    int num;
};

class idAnimWebScalar {
public:
    enum flags_t : int { AWSFLAG_INIT_TO_1 = 1 };

    idAnimWebScalar()
        : name(""), flags(0), scalarIndex(-1), scalarPtr(nullptr) {}

    void SetScalarPtr(float* scalar);
    void SetIndex(const idScalarMemBlock& memBlock, int index);
    void SetName(const char* scalarName);
    float GetScalar(const idScalarMemBlock& memBlock) const;
    void SetScalar(idScalarMemBlock& memBlock, float value);
    void Init(const char* scalarName, unsigned char scalarFlags,
        float* scalar);

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

    idAnimWebScalarPair()
        : scalarIndex(-1), coordinateIndex(-1), node(nullptr),
          fieldType(0), fieldFlags(0), data1(0), data2(0) {}

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
