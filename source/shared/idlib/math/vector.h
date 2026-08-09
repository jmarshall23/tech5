#pragma once

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>

class idVec1 {
public:
    float x;

    idVec1() = default;
    explicit idVec1(const float newX) : x(newX) {}
    void Zero() { x = 0.0f; }
    int GetDimension() const { return 1; }
    float operator[](const int) const { return x; }
    float& operator[](const int) { return x; }
};

static_assert(sizeof(idVec1) == 4, "Recovered idVec1 layout changed");

// Minimal recovered ABI surface for tungsten's idVec2. More vector operations
// will move here as their out-of-line idTech 5 implementations are activated.
class idVec2 {
public:
    float x;
    float y;

    idVec2() = default;

    idVec2(const float newX, const float newY)
        : x(newX)
        , y(newY) {
    }

    void Set(const float newX, const float newY) {
        x = newX;
        y = newY;
    }

    void Zero() {
        x = 0.0f;
        y = 0.0f;
    }

    int GetDimension() const { return 2; }

    float operator[](const int index) const {
        assert(index >= 0 && index < 2);
        return (&x)[index];
    }

    float& operator[](const int index) {
        assert(index >= 0 && index < 2);
        return (&x)[index];
    }
};

static_assert(sizeof(idVec2) == 8, "Recovered idVec2 layout changed");

// Minimal recovered ABI surface for tungsten's idVec3. The class deliberately
// stays a three-float POD layout; Xbox-only SIMD assumptions belong in the PC
// portability layer rather than in this type.
class idVec3 {
public:
    float x;
    float y;
    float z;

    idVec3() = default;

    idVec3(const float newX, const float newY, const float newZ)
        : x(newX)
        , y(newY)
        , z(newZ) {
    }

    void Set(const float newX, const float newY, const float newZ) {
        x = newX;
        y = newY;
        z = newZ;
    }

    void Zero() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }


    int GetDimension() const { return 3; }

    float operator[](const int index) const {
        assert(index >= 0 && index < 3);
        return (&x)[index];
    }

    float& operator[](const int index) {
        assert(index >= 0 && index < 3);
        return (&x)[index];
    }

    idVec3 operator-() const {
        return idVec3(-x, -y, -z);
    }

    idVec3 operator+(const idVec3& other) const {
        return idVec3(x + other.x, y + other.y, z + other.z);
    }

    idVec3 operator-(const idVec3& other) const {
        return idVec3(x - other.x, y - other.y, z - other.z);
    }

    idVec3 operator*(const float scale) const {
        return idVec3(x * scale, y * scale, z * scale);
    }

    float Dot(const idVec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    idVec3 Cross(const idVec3& other) const {
        return idVec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float LengthSqr() const {
        return Dot(*this);
    }

    float Length() const {
        return std::sqrt(LengthSqr());
    }

    // Materialized in the authoritative shared/idlib/math/vector.h dump.
    // The original PowerPC implementation uses a refined reciprocal square
    // root; the scalar PC path preserves its normalized result and returns
    // the vector's original length.
    float NormalizeFast() {
        const float lengthSqr = LengthSqr();
        if (lengthSqr <= 0.0f) {
            return 0.0f;
        }

        const float length = std::sqrt(lengthSqr);
        const float inverseLength = 1.0f / length;
        x *= inverseLength;
        y *= inverseLength;
        z *= inverseLength;
        return length;
    }
};

static_assert(sizeof(idVec3) == 12, "Recovered idVec3 layout changed");

// Unit vectors embedded in AAS traversal records are stored as signed
// 16-bit components.  The authoritative constructor normalizes before
// quantizing with a scale of 32767.
class idQuantizedVec3 {
public:
    std::int16_t x;
    std::int16_t y;
    std::int16_t z;

    idQuantizedVec3() = default;
    explicit idQuantizedVec3(const idVec3& vector) { Set(vector); }

    void Set(idVec3 vector) {
        vector.NormalizeFast();
        x = static_cast<std::int16_t>(vector.x * 32767.0f);
        y = static_cast<std::int16_t>(vector.y * 32767.0f);
        z = static_cast<std::int16_t>(vector.z * 32767.0f);
    }

    idVec3 ToVec3() const {
        constexpr float inverseQuantization = 1.0f / 32767.0f;
        return idVec3(x * inverseQuantization, y * inverseQuantization,
            z * inverseQuantization);
    }
};

static_assert(sizeof(idQuantizedVec3) == 6,
    "Recovered idQuantizedVec3 ABI changed");

class idMat3 {
public:
    idVec3 mat[3];

    idMat3() = default;
    explicit idMat3(float diagonal) {
        mat[0].Set(diagonal, 0.0f, 0.0f);
        mat[1].Set(0.0f, diagonal, 0.0f);
        mat[2].Set(0.0f, 0.0f, diagonal);
    }

    idMat3(float xx, float xy, float xz,
            float yx, float yy, float yz,
            float zx, float zy, float zz) {
        mat[0].Set(xx, xy, xz);
        mat[1].Set(yx, yy, yz);
        mat[2].Set(zx, zy, zz);
    }

    idVec3& operator[](const int index) { return mat[index]; }
    const idVec3& operator[](const int index) const { return mat[index]; }

    idVec3 operator*(const idVec3& vector) const {
        return idVec3(
            mat[0].x * vector.x + mat[0].y * vector.y + mat[0].z * vector.z,
            mat[1].x * vector.x + mat[1].y * vector.y + mat[1].z * vector.z,
            mat[2].x * vector.x + mat[2].y * vector.y + mat[2].z * vector.z);
    }

    idMat3 operator*(const idMat3& other) const {
        idMat3 result;
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 3; ++column) {
                result[row][column] = mat[row][0] * other[0][column]
                    + mat[row][1] * other[1][column]
                    + mat[row][2] * other[2][column];
            }
        }
        return result;
    }

    idMat3& operator*=(const idMat3& other) {
        *this = *this * other;
        return *this;
    }

    idMat3& OrthoNormalizeSelf() {
        mat[0].NormalizeFast();
        mat[2] = mat[0].Cross(mat[1]);
        mat[2].NormalizeFast();
        mat[1] = mat[2].Cross(mat[0]);
        mat[1].NormalizeFast();
        return *this;
    }

    idMat3 Transpose() const {
        return idMat3(
            mat[0].x, mat[1].x, mat[2].x,
            mat[0].y, mat[1].y, mat[2].y,
            mat[0].z, mat[1].z, mat[2].z);
    }

    float Determinant() const {
        return mat[0].x * (mat[1].y * mat[2].z - mat[1].z * mat[2].y)
            - mat[0].y * (mat[1].x * mat[2].z - mat[1].z * mat[2].x)
            + mat[0].z * (mat[1].x * mat[2].y - mat[1].y * mat[2].x);
    }

    bool InverseSelf() {
        const float determinant = Determinant();
        if (std::fabs(determinant) < 1.0e-14f) return false;
        const float inverseDeterminant = 1.0f / determinant;
        const idMat3 source = *this;
        mat[0].Set(
            (source[1].y * source[2].z - source[1].z * source[2].y) * inverseDeterminant,
            (source[0].z * source[2].y - source[0].y * source[2].z) * inverseDeterminant,
            (source[0].y * source[1].z - source[0].z * source[1].y) * inverseDeterminant);
        mat[1].Set(
            (source[1].z * source[2].x - source[1].x * source[2].z) * inverseDeterminant,
            (source[0].x * source[2].z - source[0].z * source[2].x) * inverseDeterminant,
            (source[0].z * source[1].x - source[0].x * source[1].z) * inverseDeterminant);
        mat[2].Set(
            (source[1].x * source[2].y - source[1].y * source[2].x) * inverseDeterminant,
            (source[0].y * source[2].x - source[0].x * source[2].y) * inverseDeterminant,
            (source[0].x * source[1].y - source[0].y * source[1].x) * inverseDeterminant);
        return true;
    }
};

static_assert(sizeof(idMat3) == 36, "Recovered idMat3 layout changed");

class idVec4 {
public:
    float x;
    float y;
    float z;
    float w;

    idVec4() = default;

    idVec4(
        const float newX,
        const float newY,
        const float newZ,
        const float newW
    )
        : x(newX)
        , y(newY)
        , z(newZ)
        , w(newW) {
    }

    void Set(
        const float newX,
        const float newY,
        const float newZ,
        const float newW
    ) {
        x = newX;
        y = newY;
        z = newZ;
        w = newW;
    }

    int GetDimension() const { return 4; }

    float operator[](const int index) const {
        assert(index >= 0 && index < 4);
        return (&x)[index];
    }

    float& operator[](const int index) {
        assert(index >= 0 && index < 4);
        return (&x)[index];
    }
};

static_assert(sizeof(idVec4) == 16, "Recovered idVec4 layout changed");

class idVec5 {
public:
    float x;
    float y;
    float z;
    float s;
    float t;

    idVec5() = default;
    idVec5(float newX, float newY, float newZ, float newS, float newT)
        : x(newX), y(newY), z(newZ), s(newS), t(newT) {}
    int GetDimension() const { return 5; }
    float& operator[](int index) { return (&x)[index]; }
    float operator[](int index) const { return (&x)[index]; }
};

class idVec6 {
public:
    float p[6];
    int GetDimension() const { return 6; }

    idVec6() = default;
    float& operator[](int index) { return p[index]; }
    float operator[](int index) const { return p[index]; }
};

static_assert(sizeof(idVec5) == 20, "Recovered idVec5 layout changed");
static_assert(sizeof(idVec6) == 24, "Recovered idVec6 layout changed");

class idAngles {
public:
    float pitch;
    float yaw;
    float roll;

    idAngles() = default;
    idAngles(const float newPitch, const float newYaw, const float newRoll)
        : pitch(newPitch), yaw(newYaw), roll(newRoll) {
    }

    float operator[](const int index) const { return (&pitch)[index]; }
    float& operator[](const int index) { return (&pitch)[index]; }

    idAngles operator+(const idAngles& other) const {
        return idAngles(pitch + other.pitch, yaw + other.yaw, roll + other.roll);
    }
    idAngles operator-(const idAngles& other) const {
        return idAngles(pitch - other.pitch, yaw - other.yaw, roll - other.roll);
    }
    idAngles operator*(const float scale) const {
        return idAngles(pitch * scale, yaw * scale, roll * scale);
    }

    idAngles& Normalize360() {
        float* angle = &pitch;
        for (int index = 0; index < 3; ++index) {
            angle[index] -= std::floor(angle[index] / 360.0f) * 360.0f;
            if (angle[index] >= 360.0f) angle[index] -= 360.0f;
            if (angle[index] < 0.0f) angle[index] += 360.0f;
        }
        return *this;
    }

    idAngles& Normalize180() {
        Normalize360();
        if (pitch > 180.0f) pitch -= 360.0f;
        if (yaw > 180.0f) yaw -= 360.0f;
        if (roll > 180.0f) roll -= 360.0f;
        return *this;
    }

    void ToVectors(idVec3* forward, idVec3* right = nullptr,
            idVec3* up = nullptr) const {
        constexpr float DEG2RAD = 0.01745329251994329577f;
        const float sy = std::sin(yaw * DEG2RAD);
        const float cy = std::cos(yaw * DEG2RAD);
        const float sp = std::sin(pitch * DEG2RAD);
        const float cp = std::cos(pitch * DEG2RAD);
        const float sr = std::sin(roll * DEG2RAD);
        const float cr = std::cos(roll * DEG2RAD);
        if (forward != nullptr) forward->Set(cp * cy, cp * sy, -sp);
        if (right != nullptr) right->Set(
            cr * sy - sr * sp * cy,
            -(sr * sp * sy + cr * cy),
            -sr * cp);
        if (up != nullptr) up->Set(
            cr * sp * cy + sr * sy,
            cr * sp * sy - sr * cy,
            cr * cp);
    }

    idVec3 ToForward() const {
        idVec3 result;
        ToVectors(&result);
        return result;
    }

    idMat3 ToMat3() const {
        idMat3 result;
        ToVectors(&result[0], &result[1], &result[2]);
        return result;
    }
};

static_assert(sizeof(idAngles) == 12, "Recovered idAngles layout changed");

class idQuat {
public:
    float x;
    float y;
    float z;
    float w;

    idQuat() = default;
    idQuat(const float newX, const float newY, const float newZ, const float newW)
        : x(newX), y(newY), z(newZ), w(newW) {
    }

    float operator[](const int index) const { return (&x)[index]; }
    float& operator[](const int index) { return (&x)[index]; }

    idQuat operator+(const idQuat& other) const {
        return idQuat(x + other.x, y + other.y, z + other.z, w + other.w);
    }
    idQuat operator-(const idQuat& other) const {
        return idQuat(x - other.x, y - other.y, z - other.z, w - other.w);
    }
    idQuat operator*(const float scale) const {
        return idQuat(x * scale, y * scale, z * scale, w * scale);
    }

    // Materialized in the authoritative shared/idlib/math/quat.h dump.
    idQuat& Normalize() {
        const float lengthSqr = x * x + y * y + z * z + w * w;
        if (lengthSqr <= 0.0f) {
            return *this;
        }

        const float inverseLength = 1.0f / std::sqrt(lengthSqr);
        x *= inverseLength;
        y *= inverseLength;
        z *= inverseLength;
        w *= inverseLength;
        return *this;
    }
};

static_assert(sizeof(idQuat) == 16, "Recovered idQuat layout changed");

// The Xbox 360 type-information stream serializes the dynamic math types by
// their three/four-field facades. Keep these definitions allocation-simple on
// the standalone recovery targets while preserving the recovered public ABI.
class idVecX {
public:
    idVecX() : size(0), alloced(0), p(nullptr) {}
    explicit idVecX(const int newSize) : idVecX() { SetSize(newSize); }
    idVecX(const idVecX& other) : idVecX() {
        SetSize(other.size);
        if (size > 0) std::memcpy(p, other.p, sizeof(float) * size);
    }
    ~idVecX() { std::free(p); }

    idVecX& operator=(const idVecX& other) {
        if (this != &other) {
            SetSize(other.size);
            if (size > 0) std::memcpy(p, other.p, sizeof(float) * size);
        }
        return *this;
    }

    void SetSize(const int newSize) {
        const int safeSize = newSize > 0 ? newSize : 0;
        if (safeSize > alloced) {
            float* const replacement = static_cast<float*>(
                std::realloc(p, sizeof(float) * safeSize));
            if (replacement == nullptr) return;
            p = replacement;
            alloced = safeSize;
        }
        size = safeSize;
    }
    int GetSize() const { return size; }
    float& operator[](const int index) { return p[index]; }
    float operator[](const int index) const { return p[index]; }

public:
    int size;
    int alloced;
    float* p;
};

static_assert(sizeof(idVecX) == 12, "Recovered idVecX layout changed");

class idMatX {
public:
    idMatX() : numRows(0), numColumns(0), alloced(0), mat(nullptr) {}
    idMatX(const int rows, const int columns) : idMatX() {
        SetSize(rows, columns);
    }
    idMatX(const idMatX& other) : idMatX() {
        SetSize(other.numRows, other.numColumns);
        const int count = numRows * numColumns;
        if (count > 0) std::memcpy(mat, other.mat, sizeof(float) * count);
    }
    ~idMatX() { std::free(mat); }

    idMatX& operator=(const idMatX& other) {
        if (this != &other) {
            SetSize(other.numRows, other.numColumns);
            const int count = numRows * numColumns;
            if (count > 0) std::memcpy(mat, other.mat, sizeof(float) * count);
        }
        return *this;
    }

    void SetSize(const int rows, const int columns) {
        const int safeRows = rows > 0 ? rows : 0;
        const int safeColumns = columns > 0 ? columns : 0;
        const int count = safeRows * safeColumns;
        if (count > alloced) {
            float* const replacement = static_cast<float*>(
                std::realloc(mat, sizeof(float) * count));
            if (replacement == nullptr) return;
            mat = replacement;
            alloced = count;
        }
        numRows = safeRows;
        numColumns = safeColumns;
    }
    int GetNumRows() const { return numRows; }
    int GetNumColumns() const { return numColumns; }
    float* operator[](const int row) { return mat + row * numColumns; }
    const float* operator[](const int row) const {
        return mat + row * numColumns;
    }

public:
    int numRows;
    int numColumns;
    int alloced;
    float* mat;
};

static_assert(sizeof(idMatX) == 16, "Recovered idMatX layout changed");
