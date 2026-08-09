#pragma once

#include "idlib/math/vector.h"

#include <cassert>
#include <cmath>
#include <cstring>

class idPluecker {
public:
    float p[6];

    idPluecker() = default;
    explicit idPluecker(const float* values) {
        std::memcpy(p, values, sizeof(p));
    }
    idPluecker(const float p0, const float p1, const float p2,
        const float p3, const float p4, const float p5) {
        Set(p0, p1, p2, p3, p4, p5);
    }
    idPluecker(const idVec3& start, const idVec3& end) { FromLine(start, end); }

    float operator[](const int index) const { assert(index >= 0 && index < 6); return p[index]; }
    float& operator[](const int index) { assert(index >= 0 && index < 6); return p[index]; }

    idPluecker operator-() const {
        return idPluecker(-p[0], -p[1], -p[2], -p[3], -p[4], -p[5]);
    }
    idPluecker operator*(const float scale) const {
        return idPluecker(p[0] * scale, p[1] * scale, p[2] * scale,
            p[3] * scale, p[4] * scale, p[5] * scale);
    }
    idPluecker operator/(const float scale) const {
        assert(scale != 0.0f); return *this * (1.0f / scale);
    }
    float operator*(const idPluecker& other) const {
        return PermutedInnerProduct(other);
    }
    idPluecker operator+(const idPluecker& other) const {
        return idPluecker(p[0] + other.p[0], p[1] + other.p[1],
            p[2] + other.p[2], p[3] + other.p[3],
            p[4] + other.p[4], p[5] + other.p[5]);
    }
    idPluecker operator-(const idPluecker& other) const { return *this + -other; }
    idPluecker& operator*=(const float scale) {
        for (float& value : p) value *= scale; return *this;
    }
    idPluecker& operator/=(const float scale) {
        assert(scale != 0.0f); return *this *= 1.0f / scale;
    }
    idPluecker& operator+=(const idPluecker& other) {
        for (int index = 0; index < 6; ++index) p[index] += other.p[index];
        return *this;
    }
    idPluecker& operator-=(const idPluecker& other) {
        for (int index = 0; index < 6; ++index) p[index] -= other.p[index];
        return *this;
    }

    bool Compare(const idPluecker& other) const {
        for (int index = 0; index < 6; ++index) if (p[index] != other.p[index]) return false;
        return true;
    }
    bool Compare(const idPluecker& other, const float epsilon) const {
        for (int index = 0; index < 6; ++index)
            if (std::fabs(p[index] - other.p[index]) > epsilon) return false;
        return true;
    }
    bool operator==(const idPluecker& other) const { return Compare(other); }
    bool operator!=(const idPluecker& other) const { return !Compare(other); }

    void Set(const float p0, const float p1, const float p2,
        const float p3, const float p4, const float p5) {
        p[0] = p0; p[1] = p1; p[2] = p2;
        p[3] = p3; p[4] = p4; p[5] = p5;
    }
    void Zero() { for (float& value : p) value = 0.0f; }
    void FromLine(const idVec3& start, const idVec3& end) {
        p[0] = start.x * end.y - end.x * start.y;
        p[1] = start.x * end.z - end.x * start.z;
        p[2] = start.x - end.x;
        p[3] = start.y * end.z - end.y * start.z;
        p[4] = start.z - end.z;
        p[5] = end.y - start.y;
    }
    void FromRay(const idVec3& start, const idVec3& direction) {
        p[0] = start.x * direction.y - direction.x * start.y;
        p[1] = start.x * direction.z - direction.x * start.z;
        p[2] = -direction.x;
        p[3] = start.y * direction.z - direction.y * start.z;
        p[4] = -direction.z;
        p[5] = direction.y;
    }
    bool ToRay(idVec3& start, idVec3& direction) const {
        const idVec3 moment(p[3], -p[1], p[0]);
        direction.Set(-p[2], p[5], -p[4]);
        const float lengthSqr = direction.LengthSqr();
        if (lengthSqr == 0.0f) return false;
        start = direction.Cross(moment) * (1.0f / lengthSqr);
        return true;
    }
    bool ToLine(idVec3& start, idVec3& end) const {
        idVec3 direction;
        if (!ToRay(start, direction)) return false;
        end = start + direction;
        return true;
    }
    void ToDir(idVec3& direction) const { direction.Set(-p[2], p[5], -p[4]); }
    float PermutedInnerProduct(const idPluecker& other) const {
        return p[0] * other.p[4] + p[1] * other.p[5]
            + p[2] * other.p[3] + p[4] * other.p[0]
            + p[5] * other.p[1] + p[3] * other.p[2];
    }
    float LengthSqr() const { return p[2] * p[2] + p[4] * p[4] + p[5] * p[5]; }
    float Length() const { return std::sqrt(LengthSqr()); }
    float NormalizeSelf() {
        const float length = Length();
        if (length != 0.0f) *this /= length;
        return length;
    }
    idPluecker Normalize() const { idPluecker result(*this); result.NormalizeSelf(); return result; }
    int GetDimension() const { return 6; }
    const float* ToFloatPtr() const { return p; }
    float* ToFloatPtr() { return p; }
};

static_assert(sizeof(idPluecker) == 24, "Recovered idPluecker ABI changed");

