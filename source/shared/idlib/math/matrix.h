#pragma once

#include "../containers/array.h"
#include "vector.h"
#include "mat3x4.h"

struct alignas(16) idNativeVector4 {
    float value[4];
};

struct _XMMATRIX {
    union {
        idNativeVector4 r[4];
        struct {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        } __s1;
        float m[4][4];
    } ___u0;
};

struct _D3DMATRIX {
    union {
        struct {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        } __s0;
        float m[4][4];
    } ___u0;
};

struct _ATIMATRIX {
    float _11, _21, _31, _41;
    float _12, _22, _32, _42;
    float _13, _23, _33, _43;
    float _14, _24, _34, _44;
    unsigned int dwFlags;
};

class idMat2 {
public:
    idVec2 mat[2];
    idMat2() = default;
    explicit idMat2(float diagonal) {
        mat[0].Set(diagonal, 0.0f);
        mat[1].Set(0.0f, diagonal);
    }
    idVec2& operator[](int index) { return mat[index]; }
    const idVec2& operator[](int index) const { return mat[index]; }
};

class idMat4 {
public:
    idVec4 mat[4];
    idMat4() = default;
    explicit idMat4(float diagonal) {
        for (int row = 0; row < 4; ++row)
            for (int column = 0; column < 4; ++column)
                mat[row][column] = row == column ? diagonal : 0.0f;
    }
    idVec4& operator[](int index) { return mat[index]; }
    const idVec4& operator[](int index) const { return mat[index]; }
};

class idMat5 {
public:
    idVec5 mat[5];
    idVec5& operator[](int index) { return mat[index]; }
    const idVec5& operator[](int index) const { return mat[index]; }
};

class idMat6 {
public:
    idVec6 mat[6];
    idVec6& operator[](int index) { return mat[index]; }
    const idVec6& operator[](int index) const { return mat[index]; }
};

struct swfMatrix_t {
    float xx;
    float yy;
    float xy;
    float yx;
    float tx;
    float ty;
};

using XMMATRIX = _XMMATRIX;
using ATIMATRIX = _ATIMATRIX;
using D3DMATRIX = _D3DMATRIX;
using matrix_t = idArray<float, 36>;
using FXLMATRIX = _XMMATRIX;

static_assert(sizeof(_XMMATRIX) == 64, "Recovered XMMATRIX ABI changed");
static_assert(sizeof(_D3DMATRIX) == 64, "Recovered D3DMATRIX ABI changed");
static_assert(sizeof(_ATIMATRIX) == 68, "Recovered ATIMATRIX ABI changed");
static_assert(sizeof(idMat2) == 16, "Recovered idMat2 ABI changed");
static_assert(sizeof(idMat4) == 64, "Recovered idMat4 ABI changed");
static_assert(sizeof(idMat5) == 100, "Recovered idMat5 ABI changed");
static_assert(sizeof(idMat6) == 144, "Recovered idMat6 ABI changed");
static_assert(sizeof(swfMatrix_t) == 24, "Recovered swfMatrix_t ABI changed");
