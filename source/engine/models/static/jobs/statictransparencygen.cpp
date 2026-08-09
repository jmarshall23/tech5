#include "models/static/jobs/statictransparencygen.h"

#include <algorithm>
#include <cmath>

namespace {

idVec3 TransformPoint(const idVec3& point, const idVec3& origin,
        const idMat3& axis) {
    return origin + idVec3(
        axis[0].x * point.x + axis[1].x * point.y + axis[2].x * point.z,
        axis[0].y * point.x + axis[1].y * point.y + axis[2].y * point.z,
        axis[0].z * point.x + axis[1].z * point.y + axis[2].z * point.z);
}

idVec3 TransformDirection(const idVec3& direction, const idMat3& axis) {
    idVec3 result(
        axis[0].x * direction.x + axis[1].x * direction.y +
            axis[2].x * direction.z,
        axis[0].y * direction.x + axis[1].y * direction.y +
            axis[2].y * direction.z,
        axis[0].z * direction.x + axis[1].z * direction.y +
            axis[2].z * direction.z);
    result.NormalizeFast();
    return result;
}

std::int16_t PackTexCoord(float value) {
    const int packed = static_cast<int>(std::floor(
        (value - 0.5f) * 65534.0f + 0.5f));
    return static_cast<std::int16_t>((std::max)(-32768,
        (std::min)(32767, packed)));
}

std::uint8_t PackColor(float value) {
    const int packed = static_cast<int>(value * 255.0f);
    return static_cast<std::uint8_t>((std::max)(0,
        (std::min)(255, packed)));
}

idVec3 ApproximateLight(const idVec3& normal,
        const approximateLighting_t& lighting) {
    const idVec4& xLight = lighting.channelLighting[normal.x >= 0.0f ? 0 : 1];
    const idVec4& yLight = lighting.channelLighting[normal.y >= 0.0f ? 2 : 3];
    const idVec4& zLight = lighting.channelLighting[normal.z >= 0.0f ? 4 : 5];
    const float prime = 0.5f * std::fabs(
        lighting.primeLightDir.x * normal.x +
        lighting.primeLightDir.y * normal.y +
        lighting.primeLightDir.z * normal.z);
    return idVec3(
        std::fabs(normal.x) * xLight.x + std::fabs(normal.y) * yLight.x +
            std::fabs(normal.z) * zLight.x + prime * lighting.primeLightColor.x,
        std::fabs(normal.x) * xLight.y + std::fabs(normal.y) * yLight.y +
            std::fabs(normal.z) * zLight.y + prime * lighting.primeLightColor.y,
        std::fabs(normal.x) * xLight.z + std::fabs(normal.y) * yLight.z +
            std::fabs(normal.z) * zLight.z + prime * lighting.primeLightColor.z);
}

} // namespace

void StaticTransparencyGenJob(const staticTransparencyGenParms_t* parms) {
    if (parms == nullptr || parms->quadsUsed == nullptr) {
        return;
    }

    const int numQuads = (std::max)(0, parms->numInputVerts / 4);
    *parms->quadsUsed = 0;
    if (numQuads == 0 || parms->inputVerts == nullptr ||
            parms->verts == nullptr || parms->quadDepth == nullptr) {
        return;
    }

    const float fadeRange = parms->fadeMaxDist - parms->fadeStartDist;
    const float inverseFadeRange = fadeRange != 0.0f ? 1.0f / fadeRange : 0.0f;
    for (int quad = 0; quad < numQuads; ++quad) {
        idVec3 center(0.0f, 0.0f, 0.0f);
        for (int corner = 0; corner < 4; ++corner) {
            const int index = quad * 4 + corner;
            const idDrawVert& input = parms->inputVerts[index];
            idTransparencyVert& output = parms->verts[index];
            output.xyz = TransformPoint(input.xyz, parms->origin, parms->axis);
            center = center + output.xyz;

            const float mappedS = parms->transSortScaleBias.x * input.st.x +
                parms->transSortScaleBias.z;
            const float mappedT = parms->transSortScaleBias.y * input.st.y +
                parms->transSortScaleBias.w;
            output.st[0] = output.st1[0] = PackTexCoord(mappedS);
            output.st[1] = output.st1[1] = PackTexCoord(mappedT);

            output.normal[0] = output.normal[1] = output.normal[2] = 0;
            output.normal[3] = 255;
            output.tangent[0] = output.tangent[1] = output.tangent[2] = 0;
            output.tangent[3] = 255;

            const idVec3 normal = TransformDirection(input.GetNormal(),
                parms->axis);
            const idVec3 light = ApproximateLight(normal, parms->lighting);
            output.color[0] = PackColor(light.x);
            output.color[1] = PackColor(light.y);
            output.color[2] = PackColor(light.z);
            const float depth = (output.xyz - parms->viewOrg).Dot(
                parms->viewDir);
            const float alpha = fadeRange != 0.0f
                ? 1.0f - (depth - parms->fadeStartDist) * inverseFadeRange
                : (depth <= parms->fadeStartDist ? 1.0f : 0.0f);
            output.color[3] = PackColor(alpha);
        }
        center = center * 0.25f;
        parms->quadDepth[quad] = (center - parms->viewOrg).Dot(
            parms->viewDir);
    }
    *parms->quadsUsed = numQuads;
}
