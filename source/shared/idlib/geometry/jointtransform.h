#pragma once

#include "../math/matrix.h"

#include <cmath>

enum jointModTransform_t : int {
    JOINTMOD_NONE = 0,
    JOINTMOD_LOCAL = 1,
    JOINTMOD_LOCAL_OVERRIDE = 2,
    JOINTMOD_MODEL = 3,
    JOINTMOD_MODEL_OVERRIDE = 4,
    JOINTMOD_PARENT_OVERRIDE = 5
};

class idJointQuat {
public:
    float jointQuat[8];

    void FromMat4(const idMat4& matrix) {
        const float trace = matrix[0].x + matrix[1].y + matrix[2].z;
        if (trace > 0.0f) {
            const float scale = std::sqrt(trace + 1.0f);
            jointQuat[3] = 0.5f * scale;
            const float inverseScale = 0.5f / scale;
            jointQuat[0] = (matrix[2].y - matrix[1].z) * inverseScale;
            jointQuat[1] = (matrix[0].z - matrix[2].x) * inverseScale;
            jointQuat[2] = (matrix[1].x - matrix[0].y) * inverseScale;
        } else {
            const int next[3] = { 1, 2, 0 };
            int i = matrix[1].y > matrix[0].x ? 1 : 0;
            if (matrix[2].z > matrix[i][i]) i = 2;
            const int j = next[i];
            const int k = next[j];
            float scale = std::sqrt(
                matrix[i][i] - matrix[j][j] - matrix[k][k] + 1.0f);
            jointQuat[i] = 0.5f * scale;
            scale = scale > 0.0f ? 0.5f / scale : 0.0f;
            jointQuat[3] = (matrix[k][j] - matrix[j][k]) * scale;
            jointQuat[j] = (matrix[j][i] + matrix[i][j]) * scale;
            jointQuat[k] = (matrix[k][i] + matrix[i][k]) * scale;
        }
        jointQuat[4] = matrix[0].w;
        jointQuat[5] = matrix[1].w;
        jointQuat[6] = matrix[2].w;
        jointQuat[7] = 0.0f;
    }

    idQuat& Rotation() { return *reinterpret_cast<idQuat*>(jointQuat); }
    const idQuat& Rotation() const {
        return *reinterpret_cast<const idQuat*>(jointQuat);
    }
    idVec3& Translation() { return *reinterpret_cast<idVec3*>(jointQuat + 4); }
    const idVec3& Translation() const {
        return *reinterpret_cast<const idVec3*>(jointQuat + 4);
    }
};

class idJointMat {
public:
    float mat[12];

    float* operator[](const int row) { return mat + row * 4; }
    const float* operator[](const int row) const { return mat + row * 4; }
};

struct jointTransforms_t {
    idJointMat left;
    idJointMat right;
    idJointMat origin;
};

struct jointTransform_t {
    idQuat msQuat;
    idVec3 msOrigin;
};

using getJointTransform_t = bool (*)(
    void*, const idJointMat*, const char*, idVec3*, idMat3*);

static_assert(sizeof(idJointQuat) == 32, "Recovered idJointQuat layout changed");
static_assert(sizeof(idJointMat) == 48, "Recovered idJointMat layout changed");
static_assert(sizeof(jointTransforms_t) == 144,
    "Recovered jointTransforms_t layout changed");
static_assert(sizeof(jointTransform_t) == 28,
    "Recovered jointTransform_t layout changed");

