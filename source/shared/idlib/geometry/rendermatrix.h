#pragma once

#include "../bv/bounds.h"
#include "../math/matrix.h"
#include "../math/plane.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>

// Row-major 4x4 matrix recovered from Tungsten. The methods below follow the
// operand order and projection conventions visible in the Hex-Rays bodies.
class idRenderMatrix {
public:
    float m[16];

    float* operator[](const int row) { return m + row * 4; }
    const float* operator[](const int row) const { return m + row * 4; }

    void Identity() {
        std::memset(m, 0, sizeof(m));
        m[0] = m[5] = m[10] = m[15] = 1.0f;
    }

    void TransformPoint(const idVec3& input, idVec4& output) const {
        output.Set(
            input.x * m[0] + input.y * m[1] + input.z * m[2] + m[3],
            input.x * m[4] + input.y * m[5] + input.z * m[6] + m[7],
            input.x * m[8] + input.y * m[9] + input.z * m[10] + m[11],
            input.x * m[12] + input.y * m[13] + input.z * m[14] + m[15]);
    }

    void TransformPoint(const idVec4& input, idVec4& output) const {
        idVec4 result;
        result.Set(
            input.x * m[0] + input.y * m[1] + input.z * m[2] + input.w * m[3],
            input.x * m[4] + input.y * m[5] + input.z * m[6] + input.w * m[7],
            input.x * m[8] + input.y * m[9] + input.z * m[10] + input.w * m[11],
            input.x * m[12] + input.y * m[13] + input.z * m[14] + input.w * m[15]);
        output = result;
    }

    void TransformDir(const idVec3& input, idVec3& output,
            const bool normalize) const {
        idVec3 result(
            input.x * m[0] + input.y * m[1] + input.z * m[2],
            input.x * m[4] + input.y * m[5] + input.z * m[6],
            input.x * m[8] + input.y * m[9] + input.z * m[10]);
        if (normalize) Normalize(result);
        output = result;
    }

    void InverseTransformPlane(const idPlane& input, idPlane& output,
            const bool normalize) const {
        idPlane result(
            input.a * m[0] + input.b * m[4] + input.c * m[8] + input.d * m[12],
            input.a * m[1] + input.b * m[5] + input.c * m[9] + input.d * m[13],
            input.a * m[2] + input.b * m[6] + input.c * m[10] + input.d * m[14],
            input.a * m[3] + input.b * m[7] + input.c * m[11] + input.d * m[15]);
        if (normalize) {
            const float lengthSqr = result.a * result.a + result.b * result.b
                + result.c * result.c;
            if (lengthSqr > 1.0e-30f) {
                const float inverseLength = 1.0f / std::sqrt(lengthSqr);
                result.a *= inverseLength;
                result.b *= inverseLength;
                result.c *= inverseLength;
                result.d *= inverseLength;
            }
        }
        output = result;
    }

    static void FromOriginAxisScale(const idVec3& origin, const idMat3& axis,
            const idVec3& scale, idRenderMatrix& output) {
        output.m[0] = axis[0].x * scale.x;
        output.m[1] = axis[1].x * scale.y;
        output.m[2] = axis[2].x * scale.z;
        output.m[3] = origin.x;
        output.m[4] = axis[0].y * scale.x;
        output.m[5] = axis[1].y * scale.y;
        output.m[6] = axis[2].y * scale.z;
        output.m[7] = origin.y;
        output.m[8] = axis[0].z * scale.x;
        output.m[9] = axis[1].z * scale.y;
        output.m[10] = axis[2].z * scale.z;
        output.m[11] = origin.z;
        output.m[12] = output.m[13] = output.m[14] = 0.0f;
        output.m[15] = 1.0f;
    }

    static void ModelViewFromOriginAxis(const idVec3& origin,
            const idMat3& axis, idRenderMatrix& output) {
        output.m[0] = -axis[1].x;
        output.m[1] = -axis[1].y;
        output.m[2] = -axis[1].z;
        output.m[3] = -(origin.x * output.m[0] + origin.y * output.m[1]
            + origin.z * output.m[2]);
        output.m[4] = axis[2].x;
        output.m[5] = axis[2].y;
        output.m[6] = axis[2].z;
        output.m[7] = -(origin.x * output.m[4] + origin.y * output.m[5]
            + origin.z * output.m[6]);
        output.m[8] = -axis[0].x;
        output.m[9] = -axis[0].y;
        output.m[10] = -axis[0].z;
        output.m[11] = -(origin.x * output.m[8] + origin.y * output.m[9]
            + origin.z * output.m[10]);
        output.m[12] = output.m[13] = output.m[14] = 0.0f;
        output.m[15] = 1.0f;
    }

    static void Multiply(const idRenderMatrix& a, const idRenderMatrix& b,
            idRenderMatrix& output) {
        idRenderMatrix result;
        for (int row = 0; row < 4; ++row) {
            for (int column = 0; column < 4; ++column) {
                result[row][column] = a[row][0] * b[0][column]
                    + a[row][1] * b[1][column]
                    + a[row][2] * b[2][column]
                    + a[row][3] * b[3][column];
            }
        }
        output = result;
    }

    static bool InverseByDoubles(const idRenderMatrix& source,
            idRenderMatrix& output) {
        double augmented[4][8] = {};
        for (int row = 0; row < 4; ++row) {
            for (int column = 0; column < 4; ++column)
                augmented[row][column] = source[row][column];
            augmented[row][row + 4] = 1.0;
        }
        for (int column = 0; column < 4; ++column) {
            int pivotRow = column;
            for (int row = column + 1; row < 4; ++row) {
                if (std::fabs(augmented[row][column])
                        > std::fabs(augmented[pivotRow][column])) {
                    pivotRow = row;
                }
            }
            if (std::fabs(augmented[pivotRow][column]) < 1.0e-20) return false;
            if (pivotRow != column) {
                for (int entry = 0; entry < 8; ++entry)
                    std::swap(augmented[pivotRow][entry], augmented[column][entry]);
            }
            const double inversePivot = 1.0 / augmented[column][column];
            for (int entry = 0; entry < 8; ++entry)
                augmented[column][entry] *= inversePivot;
            for (int row = 0; row < 4; ++row) {
                if (row == column) continue;
                const double scale = augmented[row][column];
                for (int entry = 0; entry < 8; ++entry)
                    augmented[row][entry] -= scale * augmented[column][entry];
            }
        }
        for (int row = 0; row < 4; ++row)
            for (int column = 0; column < 4; ++column)
                output[row][column] = static_cast<float>(augmented[row][column + 4]);
        return true;
    }

    static bool Inverse(const idRenderMatrix& source, idRenderMatrix& output) {
        return InverseByDoubles(source, output);
    }

    static void InverseByTranspose(const idRenderMatrix& source,
            idRenderMatrix& output) {
        output.m[0] = source.m[0]; output.m[1] = source.m[4];
        output.m[2] = source.m[8]; output.m[12] = 0.0f;
        output.m[4] = source.m[1]; output.m[5] = source.m[5];
        output.m[6] = source.m[9]; output.m[13] = 0.0f;
        output.m[8] = source.m[2]; output.m[9] = source.m[6];
        output.m[10] = source.m[10]; output.m[14] = 0.0f;
        output.m[3] = -(source.m[3] * source.m[0]
            + source.m[7] * source.m[4] + source.m[11] * source.m[8]);
        output.m[7] = -(source.m[3] * source.m[1]
            + source.m[7] * source.m[5] + source.m[11] * source.m[9]);
        output.m[11] = -(source.m[3] * source.m[2]
            + source.m[7] * source.m[6] + source.m[11] * source.m[10]);
        output.m[15] = 1.0f;
    }

    static void BuildProjection(const float xMin, const float xMax,
            const float yMin, const float yMax, const float zNear,
            const float zFar, idRenderMatrix& output) {
        std::memset(output.m, 0, sizeof(output.m));
        output.m[0] = 2.0f * zNear / (xMax - xMin);
        output.m[2] = (xMin + xMax) / (xMax - xMin);
        output.m[5] = 2.0f * zNear / (yMax - yMin);
        output.m[6] = (yMin + yMax) / (yMax - yMin);
        output.m[14] = -1.0f;
        if (zFar > zNear) {
            output.m[10] = -zFar / (zFar - zNear);
            output.m[11] = -(zNear * zFar) / (zFar - zNear);
        } else {
            output.m[10] = -1.0f;
            output.m[11] = -zNear;
        }
    }

    static void BuildProjectionFov(const float xFovDegrees,
            const float yFovDegrees, const float zNear, const float zFar,
            const float xOffset, const float yOffset, idRenderMatrix& output) {
        const float degreeToRadian = 0.01745329251994329577f;
        const float xSize = std::tan(0.5f * xFovDegrees * degreeToRadian) * zNear;
        const float ySize = std::tan(0.5f * yFovDegrees * degreeToRadian) * zNear;
        BuildProjection(-xSize + xOffset, xSize + xOffset,
            -ySize + yOffset, ySize + yOffset, zNear, zFar, output);
    }

    static void OffsetScaleForBounds(const idRenderMatrix& source,
            const idBounds& bounds, idRenderMatrix& output) {
        const idVec3 center = (bounds[0] + bounds[1]) * 0.5f;
        const idVec3 extent = (bounds[1] - bounds[0]) * 0.5f;
        for (int row = 0; row < 4; ++row) {
            output[row][0] = source[row][0] * extent.x;
            output[row][1] = source[row][1] * extent.y;
            output[row][2] = source[row][2] * extent.z;
            output[row][3] = source[row][3] + source[row][0] * center.x
                + source[row][1] * center.y + source[row][2] * center.z;
        }
    }

    static void InverseOffsetScaleForBounds(const idRenderMatrix& source,
            const idBounds& bounds, idRenderMatrix& output) {
        const idVec3 center = (bounds[0] + bounds[1]) * 0.5f;
        const idVec3 extent = (bounds[1] - bounds[0]) * 0.5f;
        for (int row = 0; row < 4; ++row) {
            const float inverseExtent = row < 3 && extent[row] != 0.0f
                ? 1.0f / extent[row]
                : 1.0f;
            for (int column = 0; column < 4; ++column)
                output[row][column] = source[row][column] * inverseExtent;
        }
        for (int column = 0; column < 4; ++column) {
            output[0][column] -= center.x * output[3][column];
            output[1][column] -= center.y * output[3][column];
            output[2][column] -= center.z * output[3][column];
        }
    }

    static void CopyMatrix(const idRenderMatrix& matrix, idVec4& row0,
            idVec4& row1, idVec4& row2, idVec4& row3) {
        row0.Set(matrix.m[0], matrix.m[1], matrix.m[2], matrix.m[3]);
        row1.Set(matrix.m[4], matrix.m[5], matrix.m[6], matrix.m[7]);
        row2.Set(matrix.m[8], matrix.m[9], matrix.m[10], matrix.m[11]);
        row3.Set(matrix.m[12], matrix.m[13], matrix.m[14], matrix.m[15]);
    }

    static void SetMVP(const idRenderMatrix& matrix, idVec4& row0,
            idVec4& row1, idVec4& row2, idVec4& row3,
            bool& negativeDeterminant) {
        CopyMatrix(matrix, row0, row1, row2, row3);
        negativeDeterminant = Determinant3x3(matrix) < 0.0f;
    }

    static void SetMVPForBounds(const idRenderMatrix& matrix,
            const idBounds& bounds, idVec4& row0, idVec4& row1,
            idVec4& row2, idVec4& row3, bool& negativeDeterminant) {
        idRenderMatrix adjusted;
        OffsetScaleForBounds(matrix, bounds, adjusted);
        SetMVP(adjusted, row0, row1, row2, row3, negativeDeterminant);
    }

    static void SetMVPForInverseProject(const idRenderMatrix& matrix,
            const idRenderMatrix& inverseProject, idVec4& row0,
            idVec4& row1, idVec4& row2, idVec4& row3,
            bool& negativeDeterminant) {
        idRenderMatrix adjusted;
        Multiply(matrix, inverseProject, adjusted);
        SetMVP(adjusted, row0, row1, row2, row3, negativeDeterminant);
    }

    static bool CullPointToMVPbits(const idRenderMatrix& matrix,
            const idVec3& point, std::uint8_t* outBits, const bool zeroToOne) {
        idVec4 clip;
        matrix.TransformPoint(point, clip);
        std::uint8_t bits = 0;
        if (clip.x < -clip.w) bits |= 1;
        if (clip.x > clip.w) bits |= 2;
        if (clip.y < -clip.w) bits |= 4;
        if (clip.y > clip.w) bits |= 8;
        if (clip.z < (zeroToOne ? 0.0f : -clip.w)) bits |= 16;
        if (clip.z > clip.w) bits |= 32;
        if (outBits != nullptr) *outBits = bits;
        return bits != 0;
    }

    static bool CullBoundsToMVPbits(const idRenderMatrix& matrix,
            const idBounds& bounds, std::uint8_t* outBits,
            const bool zeroToOne) {
        std::uint8_t allBits = 0x3F;
        std::uint8_t anyBits = 0;
        for (int corner = 0; corner < 8; ++corner) {
            const idVec3 point(
                bounds[(corner & 1) != 0 ? 1 : 0].x,
                bounds[(corner & 2) != 0 ? 1 : 0].y,
                bounds[(corner & 4) != 0 ? 1 : 0].z);
            std::uint8_t bits;
            CullPointToMVPbits(matrix, point, &bits, zeroToOne);
            anyBits |= bits;
            allBits &= bits;
        }
        if (outBits != nullptr) *outBits = anyBits;
        return allBits != 0;
    }

    static void ProjectedBounds(idBounds& projected,
            const idRenderMatrix& matrix, const idBounds& bounds,
            const bool windowSpace) {
        projected[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        projected[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        for (int corner = 0; corner < 8; ++corner) {
            idVec4 clip;
            matrix.TransformPoint(idVec3(
                bounds[(corner & 1) != 0 ? 1 : 0].x,
                bounds[(corner & 2) != 0 ? 1 : 0].y,
                bounds[(corner & 4) != 0 ? 1 : 0].z), clip);
            if (std::fabs(clip.w) < 1.0e-20f) continue;
            const float inverseW = 1.0f / clip.w;
            idVec3 point(clip.x * inverseW, clip.y * inverseW, clip.z * inverseW);
            if (windowSpace) {
                point.x = point.x * 0.5f + 0.5f;
                point.y = point.y * 0.5f + 0.5f;
            }
            for (int axis = 0; axis < 3; ++axis) {
                projected[0][axis] = (std::min)(projected[0][axis], point[axis]);
                projected[1][axis] = (std::max)(projected[1][axis], point[axis]);
            }
        }
    }

    static void DepthBoundsForBounds(float& minDepth, float& maxDepth,
            const idRenderMatrix& matrix, const idBounds& bounds,
            const bool windowSpace) {
        idBounds projected;
        ProjectedBounds(projected, matrix, bounds, windowSpace);
        minDepth = projected[0].z;
        maxDepth = projected[1].z;
    }

    static void TransformModelToClip(const idVec3& source,
            const idRenderMatrix& modelView, const idRenderMatrix& projection,
            idVec4& eye, idVec4& clip) {
        modelView.TransformPoint(source, eye);
        projection.TransformPoint(eye, clip);
    }

    static void TransformClipToDevice(const idVec4& clip, idVec3& device) {
        const float inverseW = std::fabs(clip.w) > 1.0e-20f ? 1.0f / clip.w : 0.0f;
        device.Set(clip.x * inverseW, clip.y * inverseW, clip.z * inverseW);
    }

private:
    static void Normalize(idVec3& value) {
        const float lengthSqr = value.LengthSqr();
        if (lengthSqr > 1.0e-30f) value = value * (1.0f / std::sqrt(lengthSqr));
    }

    static float Determinant3x3(const idRenderMatrix& matrix) {
        return matrix.m[0] * (matrix.m[5] * matrix.m[10] - matrix.m[6] * matrix.m[9])
            - matrix.m[1] * (matrix.m[4] * matrix.m[10] - matrix.m[6] * matrix.m[8])
            + matrix.m[2] * (matrix.m[4] * matrix.m[9] - matrix.m[5] * matrix.m[8]);
    }
};

static_assert(sizeof(idRenderMatrix) == 64,
    "Recovered idRenderMatrix layout changed");
