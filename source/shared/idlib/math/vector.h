#pragma once

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>

class idVec1 {
public:
    float x;

    idVec1() = default;
    explicit idVec1(const float newX) : x(newX) {}
    void Zero() { x = 0.0f; }
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
};

static_assert(sizeof(idVec3) == 12, "Recovered idVec3 layout changed");

class idMat3 {
public:
    idVec3 mat[3];

    idMat3() = default;
    explicit idMat3(float diagonal) {
        mat[0].Set(diagonal, 0.0f, 0.0f);
        mat[1].Set(0.0f, diagonal, 0.0f);
        mat[2].Set(0.0f, 0.0f, diagonal);
    }

    idVec3& operator[](const int index) { return mat[index]; }
    const idVec3& operator[](const int index) const { return mat[index]; }
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
};

static_assert(sizeof(idQuat) == 16, "Recovered idQuat layout changed");

// The Xbox 360 type-information stream serializes the dynamic math types by
// their three/four-field facades.  Keep these definitions allocation-simple on
// the standalone recovery targets; the complete idLib target uses BFG's
// layout-compatible implementations.
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

private:
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

private:
    int numRows;
    int numColumns;
    int alloced;
    float* mat;
};

static_assert(sizeof(idMatX) == 16, "Recovered idMatX layout changed");
