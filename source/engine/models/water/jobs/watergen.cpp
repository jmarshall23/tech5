#include "models/water/jobs/watergen.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr int BLOCK_SIZE = 16;
constexpr int BLOCK_AREA = BLOCK_SIZE * BLOCK_SIZE;

float Clamp01(float value) {
    return (std::max)(0.0f, (std::min)(1.0f, value));
}

float ShapedSine(float phase, float exponent) {
    const float value = std::sin(phase);
    if (exponent <= 0.0f || exponent == 1.0f) {
        return value;
    }
    return std::copysign(std::pow(std::fabs(value), exponent), value);
}

float DisturbanceAt(const waterDisturbanceParms_t& disturbance,
    float worldX, float worldY, float spacing) {
    switch (disturbance.type) {
    case WATER_DISTURBANCE_TYPE_WAVE: {
        const float phase =
            (worldX * disturbance.loc.x + worldY * disturbance.loc.y)
                * disturbance.parms.y
            + disturbance.parms.z;
        return disturbance.parms.x
            * ShapedSine(phase, disturbance.parms.w);
    }

    case WATER_DISTURBANCE_TYPE_RIPPLE:
    case WATER_DISTURBANCE_TYPE_DROPLET: {
        const idVec2 center =
            disturbance.type == WATER_DISTURBANCE_TYPE_DROPLET
            ? idVec2(disturbance.gridX * spacing,
                  disturbance.gridY * spacing)
            : disturbance.loc;
        const float dx = worldX - center.x;
        const float dy = worldY - center.y;
        const float radius = disturbance.radius;
        if (radius <= 0.0f) {
            return 0.0f;
        }
        const float normalizedDistanceSquared =
            (dx * dx + dy * dy) / (radius * radius);
        if (normalizedDistanceSquared >= 1.0f) {
            return 0.0f;
        }
        return disturbance.parms.x
            * std::sqrt(1.0f - normalizedDistanceSquared);
    }

    case WATER_DISTURBANCE_TYPE_FANCY_RIPPLE: {
        const float dx = worldX - disturbance.loc.x;
        const float dy = worldY - disturbance.loc.y;
        const float distance = std::sqrt(dx * dx + dy * dy);
        if (distance >= disturbance.currentDistance) {
            return 0.0f;
        }
        const float waveDistance = disturbance.currentDistance - distance;
        const float attenuation = std::exp(
            -disturbance.parms.z * waveDistance
            -disturbance.parms.w * distance);
        return disturbance.parms.x * attenuation
            * std::sin(disturbance.parms.y * waveDistance);
    }
    }
    return 0.0f;
}

unsigned char PackedByte(unsigned int packed, int byteIndex) {
    return static_cast<unsigned char>((packed >> (byteIndex * 8)) & 0xffu);
}

} // namespace

void BlockToGridPos(int blockLocX, int blockLocY, int blockX,
    int blockY, int& gridX, int& gridY) {
    gridX = BLOCK_SIZE * blockLocX + blockX;
    gridY = BLOCK_SIZE * blockLocY + blockY;
}

int GridPosToBlockLoc(int gridX, int gridY, int numBlocksX,
    int /*numBlocksY*/) {
    return BLOCK_SIZE
        * (BLOCK_SIZE * ((gridY / BLOCK_SIZE) * numBlocksX
              + gridX / BLOCK_SIZE)
            + gridY % BLOCK_SIZE)
        + gridX % BLOCK_SIZE;
}

int BlockPosToBlockLoc(int blockX, int blockY, int numBlocksX) {
    return (blockY * numBlocksX + blockX) * BLOCK_AREA;
}

void ApplyDisturbances(const deferredWaterBlockGenParms_t* parms) {
    if (parms == nullptr || parms->currBlock == nullptr ||
        parms->simulationParms == nullptr || parms->spacing <= 0.0f) {
        return;
    }

    for (int y = 0; y < BLOCK_SIZE; ++y) {
        for (int x = 0; x < BLOCK_SIZE; ++x) {
            const int blockIndex = y * BLOCK_SIZE + x;
            int gridX;
            int gridY;
            BlockToGridPos(parms->blockLocX, parms->blockLocY,
                x, y, gridX, gridY);
            const float worldX = gridX * parms->spacing;
            const float worldY = gridY * parms->spacing;

            float disturbanceHeight = 0.0f;
            for (unsigned int index = 0;
                 index < parms->numDisturbances; ++index) {
                disturbanceHeight += DisturbanceAt(
                    parms->disturbances[index], worldX, worldY,
                    parms->spacing);
            }

            const float simulationScale =
                PackedByte(parms->simulationParms[blockIndex], 0)
                * (1.0f / 255.0f);
            parms->currBlock[blockIndex] += simulationScale
                * parms->timeDelta * disturbanceHeight;
        }
    }
}

void GenWaterSurface(const deferredWaterBlockGenParms_t* parms,
    const float* previousHeightMap) {
    if (parms == nullptr || parms->currBlock == nullptr ||
        parms->prevBlock == nullptr || previousHeightMap == nullptr ||
        parms->simulationParms == nullptr || parms->spacing <= 0.0f) {
        return;
    }

    const float invSpacing = 1.0f / parms->spacing;
    const float waveScale = 0.5f * parms->speed * parms->speed
        * parms->timeDelta * parms->timeDelta * invSpacing * invSpacing;
    const float dampingScale = 1.0f - parms->damping * parms->timeDelta;
    const float invTextureWidth = parms->gridWidth > 1
        ? 1.0f / ((parms->gridWidth - 1) * parms->spacing) : 0.0f;
    const float invTextureHeight = parms->gridHeight > 1
        ? 1.0f / ((parms->gridHeight - 1) * parms->spacing) : 0.0f;

    for (int y = 0; y < BLOCK_SIZE; ++y) {
        for (int x = 0; x < BLOCK_SIZE; ++x) {
            const int index = y * BLOCK_SIZE + x;
            const float left = x > 0
                ? parms->currBlock[index - 1]
                : parms->currBlockL[y * BLOCK_SIZE + BLOCK_SIZE - 1];
            const float right = x + 1 < BLOCK_SIZE
                ? parms->currBlock[index + 1]
                : parms->currBlockR[y * BLOCK_SIZE];
            const float up = y > 0
                ? parms->currBlock[index - BLOCK_SIZE]
                : parms->currBlockU[(BLOCK_SIZE - 1) * BLOCK_SIZE + x];
            const float down = y + 1 < BLOCK_SIZE
                ? parms->currBlock[index + BLOCK_SIZE]
                : parms->currBlockD[x];

            const float simulationScale =
                PackedByte(parms->simulationParms[index], 0)
                * (1.0f / 255.0f);
            float nextHeight = ((left + right + up + down
                    - 4.0f * parms->currBlock[index]) * waveScale
                + 1.99f * parms->currBlock[index]
                - 0.99f * previousHeightMap[index]) * dampingScale;
            if (std::fabs(nextHeight) < 1.0e-30f) {
                nextHeight = 0.0f;
            }
            nextHeight *= simulationScale;
            parms->prevBlock[index] = nextHeight;

            if (parms->verts == nullptr) {
                continue;
            }

            int gridX;
            int gridY;
            BlockToGridPos(parms->blockLocX, parms->blockLocY,
                x, y, gridX, gridY);
            idDrawVert& vertex = parms->verts[index];
            vertex.xyz.Set(
                parms->waterOrg.x + gridX * parms->spacing,
                parms->waterOrg.y + gridY * parms->spacing,
                parms->waterOrg.z + nextHeight);
            vertex.st.Set(gridX * parms->spacing * invTextureWidth,
                gridY * parms->spacing * invTextureHeight);

            const float dx = 0.5f * (right - left) * invSpacing
                * simulationScale;
            const float dy = 0.5f * (down - up) * invSpacing
                * simulationScale;
            vertex.SetNormal(idVec3(dx, dy, 1.0f));
            vertex.SetTangent(idVec3(1.0f, 0.0f, dx));
            vertex.tangent[3] = 255;

            vertex.color[0] = parms->vertGradient != nullptr
                ? parms->vertGradient[index] : 0;
            vertex.color[1] = PackedByte(parms->simulationParms[index], 2);
            vertex.color[2] = PackedByte(parms->simulationParms[index], 1);
            vertex.color[3] = PackedByte(parms->simulationParms[index], 0);
        }
    }
}
