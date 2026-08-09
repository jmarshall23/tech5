#include "models/zipline/jobs/ziplinegen.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr float PI = 3.14159265358979323846f;

idVec3 Normalize(const idVec3& value, const idVec3& fallback) {
    const float lengthSquared = value.LengthSqr();
    if (lengthSquared <= 1.0e-20f) {
        return fallback;
    }
    return value * (1.0f / std::sqrt(lengthSquared));
}

float EstimateSplineLength(const idNonUniformBSpline<idVec3>& spline,
    float firstTime, float lastTime) {
    constexpr int SAMPLE_COUNT = 32;
    idVec3 previous = spline.GetCurrentValue(firstTime);
    float length = 0.0f;
    for (int sample = 1; sample <= SAMPLE_COUNT; ++sample) {
        const float fraction = static_cast<float>(sample) / SAMPLE_COUNT;
        const idVec3 current = spline.GetCurrentValue(
            firstTime + (lastTime - firstTime) * fraction);
        length += std::sqrt((current - previous).LengthSqr());
        previous = current;
    }
    return length;
}

} // namespace

void GenZipline(const zipLineGenParms_t* parms) {
    if (parms == nullptr) {
        return;
    }
    if (parms->numVertices != nullptr) {
        *parms->numVertices = 0;
    }
    if (parms->numIndices != nullptr) {
        *parms->numIndices = 0;
    }

    const idNonUniformBSpline<idVec3>* spline = parms->controlSpline;
    const int sides = parms->cableSubdivisions;
    if (spline == nullptr || spline->numKnots < 2 || sides < 3 ||
        parms->vertices == nullptr || parms->indices == nullptr ||
        parms->numVertices == nullptr || parms->numIndices == nullptr ||
        parms->maxVertices <= 0 || parms->maxIndices <= 0) {
        return;
    }

    const float firstTime = spline->times[0];
    const float lastTime = spline->times[spline->numKnots - 1];
    const float length = EstimateSplineLength(*spline, firstTime, lastTime);
    const int tessellationDistance =
        (std::max)(1, parms->splineTessellationDistance);
    int rings = (std::max)(2,
        static_cast<int>(length / tessellationDistance) + 1);
    rings = (std::min)(rings,
        (std::max)(2, (std::min)(512, parms->splineMaxSubdivisions)));
    rings = (std::min)(rings, parms->maxVertices / sides);
    rings = (std::min)(rings, parms->maxIndices / (6 * sides) + 1);
    if (rings < 2) {
        return;
    }

    const float radius = 0.5f * parms->cableDiameter;
    idVec3 previousSide(1.0f, 0.0f, 0.0f);
    float accumulatedLength = 0.0f;
    idVec3 previousCenter;

    for (int ring = 0; ring < rings; ++ring) {
        float fraction = static_cast<float>(ring) / (rings - 1);
        if (parms->downDirection) {
            fraction = 1.0f - fraction;
        }
        const float sampleTime = firstTime + (lastTime - firstTime) * fraction;
        const float timeStep = (lastTime - firstTime)
            / static_cast<float>((std::max)(32, rings * 2));
        const idVec3 center = spline->GetCurrentValue(sampleTime);
        const idVec3 before = spline->GetCurrentValue(
            (std::max)(firstTime, sampleTime - timeStep));
        const idVec3 after = spline->GetCurrentValue(
            (std::min)(lastTime, sampleTime + timeStep));
        const idVec3 pathTangent = Normalize(after - before,
            idVec3(0.0f, 0.0f, 1.0f));

        if (ring > 0) {
            accumulatedLength += std::sqrt(
                (center - previousCenter).LengthSqr());
        }
        previousCenter = center;

        idVec3 reference = std::fabs(pathTangent.z) < 0.95f
            ? idVec3(0.0f, 0.0f, 1.0f)
            : idVec3(0.0f, 1.0f, 0.0f);
        idVec3 side = Normalize(reference.Cross(pathTangent), previousSide);
        if (side.Dot(previousSide) < 0.0f) {
            side = -side;
        }
        const idVec3 up = Normalize(pathTangent.Cross(side),
            idVec3(0.0f, 1.0f, 0.0f));
        previousSide = side;

        for (int radial = 0; radial < sides; ++radial) {
            idDrawVert& vertex = parms->vertices[ring * sides + radial];
            idVec3 surfaceNormal;
            float textureS;

            if (parms->sweptPoints != nullptr) {
                const sweptPoint_t& swept = parms->sweptPoints[radial];
                vertex.xyz = center + side * swept.pos.x
                    + up * swept.pos.y + pathTangent * swept.pos.z;
                surfaceNormal = Normalize(side * swept.tangent.x
                        + up * swept.tangent.y
                        + pathTangent * swept.tangent.z,
                    side);
                textureS = swept.s;
            } else {
                const float angle = 2.0f * PI * radial / sides;
                surfaceNormal = side * std::cos(angle)
                    + up * std::sin(angle);
                vertex.xyz = center + surfaceNormal * radius;
                textureS = static_cast<float>(radial) / sides;
            }

            vertex.st.Set(textureS, accumulatedLength);
            vertex.SetNormal(surfaceNormal);
            vertex.SetTangent(pathTangent);
            vertex.SetBiTangent(surfaceNormal.Cross(pathTangent));
            vertex.color[0] = 255;
            vertex.color[1] = 255;
            vertex.color[2] = 255;
            vertex.color[3] = 255;
        }
    }

    int outputIndex = 0;
    for (int ring = 0; ring < rings - 1; ++ring) {
        const int nextRing = ring + 1;
        for (int radial = 0; radial < sides; ++radial) {
            const int nextRadial = (radial + 1) % sides;
            const std::uint16_t a = static_cast<std::uint16_t>(
                ring * sides + radial);
            const std::uint16_t b = static_cast<std::uint16_t>(
                nextRing * sides + radial);
            const std::uint16_t c = static_cast<std::uint16_t>(
                nextRing * sides + nextRadial);
            const std::uint16_t d = static_cast<std::uint16_t>(
                ring * sides + nextRadial);
            parms->indices[outputIndex++] = a;
            parms->indices[outputIndex++] = b;
            parms->indices[outputIndex++] = c;
            parms->indices[outputIndex++] = a;
            parms->indices[outputIndex++] = c;
            parms->indices[outputIndex++] = d;
        }
    }

    *parms->numVertices = rings * sides;
    *parms->numIndices = outputIndex;
}
