#pragma once

#include "vector.h"

#include <cmath>

class idRotation {
public:
    idVec3 origin;
    idVec3 vec;
    float angle;
    mutable idMat3 axis;
    mutable bool axisValid;

    idRotation()
        : origin(0.0f, 0.0f, 0.0f), vec(0.0f, 0.0f, 1.0f), angle(0.0f),
          axis(1.0f), axisValid(false) {
    }

    idRotation(const idVec3& rotationOrigin, const idVec3& rotationVector,
            const float rotationAngle)
        : origin(rotationOrigin), vec(rotationVector), angle(rotationAngle),
          axis(1.0f), axisValid(false) {
    }

    const idMat3& ToMat3() const {
        if (axisValid) return axis;
        const float halfAngle = angle * 0.00872664625997164788f;
        const float sine = std::sin(halfAngle);
        const float cosine = std::cos(halfAngle);
        const float x = vec.x * sine;
        const float y = vec.y * sine;
        const float z = vec.z * sine;
        const float x2 = x + x;
        const float y2 = y + y;
        const float z2 = z + z;
        const float xx = x * x2;
        const float xy = x * y2;
        const float xz = x * z2;
        const float yy = y * y2;
        const float yz = y * z2;
        const float zz = z * z2;
        const float wx = cosine * x2;
        const float wy = cosine * y2;
        const float wz = cosine * z2;
        axis = idMat3(
            1.0f - (yy + zz), xy - wz, xz + wy,
            xy + wz, 1.0f - (xx + zz), yz - wx,
            xz - wy, yz + wx, 1.0f - (xx + yy));
        axisValid = true;
        return axis;
    }

    idVec3 operator*(const idVec3& point) const {
        return origin + ToMat3() * (point - origin);
    }

    idRotation operator-() const {
        return idRotation(origin, vec, -angle);
    }

    void RotatePoint(idVec3& point) const { point = *this * point; }
    void RotateAxis(idMat3& value) const { value *= ToMat3(); }

    void Normalize180() {
        angle -= std::floor(angle / 360.0f) * 360.0f;
        if (angle > 180.0f) angle -= 360.0f;
        if (angle < -180.0f) angle += 360.0f;
        axisValid = false;
    }

    idVec3 ToAngularVelocity() const {
        return vec * (angle * 0.01745329251994329577f);
    }

    void SetOrigin(const idVec3& value) { origin = value; }
    void SetVec(const idVec3& value) { vec = value; axisValid = false; }
    void SetAngle(float value) { angle = value; axisValid = false; }
    const idVec3& GetOrigin() const { return origin; }
    const idVec3& GetVec() const { return vec; }
    float GetAngle() const { return angle; }
};

inline idVec3& operator*=(idVec3& vector, const idRotation& rotation) {
    vector = rotation * vector;
    return vector;
}

static_assert(sizeof(idRotation) == 68, "Recovered idRotation ABI changed");
