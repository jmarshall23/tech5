#include "cm/jobs/spheremodel/spheremodel.h"

#include "cm/jobs/collisionresults.h"
#include "idlib/geometry/jointtransform.h"

#include <algorithm>
#include <cmath>
#include <cstring>

int idSphereModelCollisionDetection::SetupCollisionSpherePtrs(
    const cm_sphereModel_t* const model,
    cm_sphereModelPtrs_t& pointers) {
    std::uint8_t* const base = reinterpret_cast<std::uint8_t*>(
        const_cast<cm_sphereModel_t*>(model));
    pointers.joint = base + model->jointOffset;
    pointers.offsetX = reinterpret_cast<float*>(base + model->offsetXOffset);
    pointers.offsetY = reinterpret_cast<float*>(base + model->offsetYOffset);
    pointers.offsetZ = reinterpret_cast<float*>(base + model->offsetZOffset);
    pointers.radius = reinterpret_cast<float*>(base + model->radiusOffset);
    pointers.surfType = base + model->surfTypeOffset;
    return model->numSpheres;
}

void idSphereModelCollisionDetection::TraceThroughModel(trace_t& trace,
    const cm_sphereModel_t& model, const idVec3& start, const idVec3& end,
    const float radius, const idMat3& trmAxis,
    const idJointMat* const modelJoints, const idVec3& modelOrigin,
    const idMat3& modelAxis, const int modelEntityNum,
    const int modelPhysicsId, const int modelBodyId, const int selfId,
    const int modelContentsOverride) {
    std::memset(&trace, 0, sizeof(trace));
    trace.fraction = 1.0f;
    trace.endpos = end;
    trace.endAxis = trmAxis;

    cm_sphereModelPtrs_t spheres;
    const int numSpheres = SetupCollisionSpherePtrs(&model, spheres);
    const idVec3 movement = end - start;
    const float movementLengthSqr = movement.LengthSqr();
    for (int sphereNumber = 0; sphereNumber < numSpheres; ++sphereNumber) {
        const int jointNumber = spheres.joint[sphereNumber];
        const idVec3 offset(spheres.offsetX[sphereNumber],
            spheres.offsetY[sphereNumber], spheres.offsetZ[sphereNumber]);
        idVec3 jointSpace = offset;
        if (modelJoints != nullptr) {
            const idJointMat& joint = modelJoints[jointNumber];
            jointSpace.Set(
                joint.mat[0] * offset.x + joint.mat[1] * offset.y
                    + joint.mat[2] * offset.z + joint.mat[3],
                joint.mat[4] * offset.x + joint.mat[5] * offset.y
                    + joint.mat[6] * offset.z + joint.mat[7],
                joint.mat[8] * offset.x + joint.mat[9] * offset.y
                    + joint.mat[10] * offset.z + joint.mat[11]);
        }
        const idVec3 sphereCenter = modelOrigin + idVec3(
            modelAxis[0].x * jointSpace.x + modelAxis[1].x * jointSpace.y
                + modelAxis[2].x * jointSpace.z,
            modelAxis[0].y * jointSpace.x + modelAxis[1].y * jointSpace.y
                + modelAxis[2].y * jointSpace.z,
            modelAxis[0].z * jointSpace.x + modelAxis[1].z * jointSpace.y
                + modelAxis[2].z * jointSpace.z);
        const float combinedRadius = radius + spheres.radius[sphereNumber];
        const idVec3 relativeStart = start - sphereCenter;
        float fraction = 1.0f;
        if (relativeStart.LengthSqr() <= combinedRadius * combinedRadius) {
            fraction = 0.0f;
        } else if (movementLengthSqr > 1.0e-20f) {
            const float b = relativeStart.Dot(movement);
            const float c = relativeStart.LengthSqr()
                - combinedRadius * combinedRadius;
            const float discriminant = b * b - movementLengthSqr * c;
            if (discriminant >= 0.0f) {
                fraction = (-b - std::sqrt(discriminant))
                    / movementLengthSqr;
            }
        }
        if (fraction < 0.0f || fraction >= trace.fraction
            || fraction > 1.0f) {
            continue;
        }
        trace.fraction = fraction;
        trace.endpos = start + movement * fraction;
        idVec3 normal = trace.endpos - sphereCenter;
        if (normal.NormalizeFast() == 0.0f) {
            normal.Set(0.0f, 0.0f, 1.0f);
        }
        trace.c.type = CONTACT_SPHERE;
        trace.c.normal = normal;
        trace.c.point = trace.endpos - normal * radius;
        trace.c.dist = normal.Dot(trace.c.point);
        trace.c.separation = spheres.radius[sphereNumber];
        trace.c.contentFlags = modelContentsOverride != 0
            ? modelContentsOverride : static_cast<int>(model.contents);
        trace.c.surfaceFlags = 0;
        trace.c.surfaceType = spheres.surfType[sphereNumber];
        trace.c.surfaceColor[0] = trace.c.surfaceColor[1]
            = trace.c.surfaceColor[2] = 0xFF;
        trace.c.modelFeature = (std::min)(sphereNumber, numSpheres - 1);
        trace.c.trmFeature = jointNumber;
        trace.c.entityNum = modelEntityNum;
        trace.c.physicsId = modelPhysicsId;
        trace.c.bodyId = modelBodyId;
        trace.c.selfId = selfId;
        trace.c.flags = 0;
    }
}
