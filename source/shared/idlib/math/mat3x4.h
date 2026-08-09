#pragma once

#include "vector.h"

class idMat3x4 {
public:
    idMat3x4() {
        Identity();
    }

    idMat3x4(const idMat3& rotation, const idVec3& translation) {
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 3; ++column) {
                mat[row * 4 + column] = rotation[column][row];
            }
            mat[row * 4 + 3] = translation[row];
        }
    }

    void Identity() {
        for (int index = 0; index < 12; ++index) {
            mat[index] = 0.0f;
        }
        mat[0] = mat[5] = mat[10] = 1.0f;
    }

    void Transform(idVec3& result, const idVec3& value) const {
        result.x = value.x * mat[0] + value.y * mat[1]
            + value.z * mat[2] + mat[3];
        result.y = value.x * mat[4] + value.y * mat[5]
            + value.z * mat[6] + mat[7];
        result.z = value.x * mat[8] + value.y * mat[9]
            + value.z * mat[10] + mat[11];
    }

    void Rotate(idMat3& result, const idMat3& value) const {
        for (int column = 0; column < 3; ++column) {
            result[column].x = mat[0] * value[column].x
                + mat[1] * value[column].y + mat[2] * value[column].z;
            result[column].y = mat[4] * value[column].x
                + mat[5] * value[column].y + mat[6] * value[column].z;
            result[column].z = mat[8] * value[column].x
                + mat[9] * value[column].y + mat[10] * value[column].z;
        }
    }

    void Invert() {
        const float old[12] = {
            mat[0], mat[1], mat[2], mat[3],
            mat[4], mat[5], mat[6], mat[7],
            mat[8], mat[9], mat[10], mat[11]
        };
        mat[0] = old[0]; mat[1] = old[4]; mat[2] = old[8];
        mat[4] = old[1]; mat[5] = old[5]; mat[6] = old[9];
        mat[8] = old[2]; mat[9] = old[6]; mat[10] = old[10];
        mat[3] = -(mat[0] * old[3] + mat[1] * old[7] + mat[2] * old[11]);
        mat[7] = -(mat[4] * old[3] + mat[5] * old[7] + mat[6] * old[11]);
        mat[11] = -(mat[8] * old[3] + mat[9] * old[7] + mat[10] * old[11]);
    }

    void LeftTransposeMultiply(const idMat3& value) {
        float old[12];
        for (int index = 0; index < 12; ++index) {
            old[index] = mat[index];
        }
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 4; ++column) {
                mat[row * 4 + column] = value[0][row] * old[column]
                    + value[1][row] * old[4 + column]
                    + value[2][row] * old[8 + column];
            }
        }
    }

    float* ToFloatPtr() { return mat; }
    const float* ToFloatPtr() const { return mat; }

public:
    float mat[12];
};

static_assert(sizeof(idMat3x4) == 48, "Recovered idMat3x4 ABI changed");
