#include "gamelib/effects/ribbon.h"

#include <algorithm>
#include <cmath>

bool GameLib_GetRibbonParameters(const idDeclRibbon* decl,
    idRibbonParameters& parameters);
void GameLib_UpdateRibbonGeometry(idRenderModelBeam* beamModel,
    const idDeclRibbon* decl, const idRibbon::ribbonNode_t* nodes,
    int firstNode, int numNodes, int currentTime,
    const idMat3& viewAxis, const idVec3& viewOrigin,
    bool explicitBothEdges, const idVec4& globalColor);

namespace {

idVec4 MultiplyColor(const idVec4& left, const idVec4& right) {
    return idVec4(left.x * right.x, left.y * right.y,
        left.z * right.z, left.w * right.w);
}

idVec3 Lerp(const idVec3& from, const idVec3& to, const float fraction) {
    return from + (to - from) * fraction;
}

} // namespace

idRibbon::idRibbon(const idDeclRibbon* const decl)
    : ribbonState(RIBBON_INACTIVE)
    , spawnOrg()
    , spawnTime(0)
    , numActiveNodes(0)
    , currHeadIdx(-1)
    , startVariance(0.0f)
    , prevTime(-1)
    , prevOrigin()
    , prevOrigin2()
    , ribbonDecl(decl)
    , globalColor(1.0f, 1.0f, 1.0f, 1.0f)
    , ribbonNodes{}
    , explicitDefineBothEdges(false) {
    ResetNodes();
    // The recovered constructor advances the same LCG once for start phase.
    static unsigned int ribbonSeed = 0;
    ribbonSeed = 1664525u * ribbonSeed + 1013904223u;
    startVariance = ((ribbonSeed >> 10) & 0x7FFFu) *
        (1.0f / 32768.0f);
}

void idRibbon::ResetNodes() {
    prevTime = -1;
    currHeadIdx = -1;
    ribbonState = RIBBON_INACTIVE;
    spawnTime = 0;
    numActiveNodes = 0;
    explicitDefineBothEdges = false;
    for (ribbonNode_t& node : ribbonNodes) {
        node.origin.Zero();
        node.origin2.Zero();
        node.velocity.Zero();
        node.orientVec.Zero();
        node.color = idVec4(0.0f, 0.0f, 0.0f, 0.0f);
        node.spawnTime = 0;
        node.nodeLength = 0.0f;
    }
}

void idRibbon::StartRibbon(const int time, const idVec3& origin) {
    ResetNodes();
    ribbonState = RIBBON_ACTIVE;
    spawnOrg = origin;
    prevOrigin = origin;
    prevOrigin2 = origin;
    spawnTime = time;
    prevTime = time;
}

void idRibbon::CalcTurbulence(const idVec3& origin, const idMat3& axis,
    idVec3& turbulence) const {
    turbulence.Zero();
    idRibbonParameters parms{};
    if (!GameLib_GetRibbonParameters(ribbonDecl, parms) ||
        std::fabs(parms.turbulenceMagnitude) <= 1.1920929e-7f) {
        return;
    }
    const float frequency = parms.turbulenceFrequency;
    const idVec4& magic = parms.turbulenceMagic;
    const idVec3 local(
        std::sin(magic.x * origin.x * frequency) -
            std::cos(magic.w * origin.y * frequency),
        std::sin(magic.y * origin.y * frequency) -
            std::cos(magic.w * origin.x * frequency),
        std::cos(magic.z * origin.z * frequency) -
            std::sin(magic.w * origin.z * frequency));
    turbulence = axis * (local * parms.turbulenceMagnitude);
}

void idRibbon::CalcHelix(const int currentTime, const idVec3& origin,
    const idMat3& axis, const idVec3& velocity, idVec3& helix) const {
    (void)origin;
    helix.Zero();
    idRibbonParameters parms{};
    if (!GameLib_GetRibbonParameters(ribbonDecl, parms) ||
        parms.helixRadius <= 1.1920929e-7f) {
        return;
    }
    const float phase = parms.helixRotationScale *
        static_cast<float>(currentTime - spawnTime) +
        startVariance * 6.28318530718f;
    idVec3 direction = velocity;
    if (direction.NormalizeFast() == 0.0f) {
        direction = axis[0];
    }
    idVec3 side = direction.Cross(axis[2]);
    if (side.NormalizeFast() == 0.0f) {
        side = axis[1];
    }
    idVec3 up = direction.Cross(side);
    up.NormalizeFast();
    helix = (side * std::cos(phase) + up * std::sin(phase)) *
        parms.helixRadius;
}

void idRibbon::AddNode(const int currentTime, const idVec3& origin,
    const idVec3& origin2, const idMat3& axis, const idVec3& velocity,
    const idVec4& color) {
    idRibbonParameters parms{};
    if (!GameLib_GetRibbonParameters(ribbonDecl, parms)) {
        return;
    }
    explicitDefineBothEdges = &origin != &origin2 ||
        (origin - origin2).LengthSqr() > 0.0f;
    idVec3 turbulence1, turbulence2, helix1, helix2;
    CalcTurbulence(origin, axis, turbulence1);
    CalcHelix(currentTime, origin, axis, velocity, helix1);
    if (explicitDefineBothEdges) {
        CalcTurbulence(origin2, axis, turbulence2);
        CalcHelix(currentTime, origin2, axis, velocity, helix2);
    } else {
        turbulence2 = turbulence1;
        helix2 = helix1;
    }

    currHeadIdx = (currHeadIdx + 1) % MAX_NODES;
    ribbonNode_t& node = ribbonNodes[currHeadIdx];
    node.spawnTime = currentTime;
    node.origin = origin + turbulence1 + helix1;
    node.origin2 = origin2 + turbulence2 + helix2;
    node.velocity = velocity + axis * parms.velocity +
        turbulence1 * parms.turbulenceVelocity +
        helix1 * parms.helixVelocity;
    node.color = MultiplyColor(parms.color, color);
    node.orientVec = axis[0];
    if (numActiveNodes > 0) {
        const ribbonNode_t& previous =
            ribbonNodes[(currHeadIdx + MAX_NODES - 1) % MAX_NODES];
        node.nodeLength = (node.origin - previous.origin).Length();
    } else {
        node.nodeLength = 0.0f;
    }
    if (numActiveNodes < MAX_NODES) {
        ++numActiveNodes;
    }
}

void idRibbon::UpdatePosition(const int currentTime, const idVec3& origin,
    const idMat3& axis, const idVec3& velocity, const idVec4& color) {
    UpdatePosition(currentTime, origin, origin, axis, velocity, color);
}

void idRibbon::UpdatePosition(const int currentTime, const idVec3& origin,
    const idVec3& origin2, const idMat3& axis, const idVec3& velocity,
    const idVec4& color) {
    idRibbonParameters parms{};
    if (ribbonState != RIBBON_ACTIVE ||
        !GameLib_GetRibbonParameters(ribbonDecl, parms)) {
        return;
    }
    const float distanceSqr = (prevOrigin - origin).LengthSqr();
    if (parms.minNodeDistance > 0.0f &&
        distanceSqr <= parms.minNodeDistance * parms.minNodeDistance) {
        return;
    }
    int subdivisions = 1;
    if (parms.nodeSubdivision > 0.0f && prevTime >= 0) {
        subdivisions = (std::min)(MAX_NODES,
            static_cast<int>(std::sqrt(distanceSqr) /
                parms.nodeSubdivision) + 1);
    }
    for (int index = 1; index <= subdivisions; ++index) {
        const float fraction = index / static_cast<float>(subdivisions);
        const int nodeTime = prevTime + static_cast<int>(
            (currentTime - prevTime) * fraction);
        AddNode(nodeTime, Lerp(prevOrigin, origin, fraction),
            Lerp(prevOrigin2, origin2, fraction), axis, velocity, color);
    }
    prevTime = currentTime;
    prevOrigin = origin;
    prevOrigin2 = origin2;
}

void idRibbon::RemoveOldNodes(const int currentTime) {
    if (numActiveNodes == 0) {
        return;
    }
    idRibbonParameters parms{};
    if (!GameLib_GetRibbonParameters(ribbonDecl, parms)) {
        return;
    }
    if (parms.maxLength != 0.0f) {
        float length = 0.0f;
        int retained = 0;
        for (int offset = 0; offset < numActiveNodes; ++offset) {
            const int index = (currHeadIdx - offset + MAX_NODES) % MAX_NODES;
            length += ribbonNodes[index].nodeLength;
            if (length <= parms.maxLength) ++retained;
        }
        numActiveNodes = retained;
    }
    while (numActiveNodes > 0) {
        const int oldest =
            (currHeadIdx - numActiveNodes + 1 + MAX_NODES) % MAX_NODES;
        if (parms.duration > 0 &&
            ribbonNodes[oldest].spawnTime + parms.duration < currentTime) {
            --numActiveNodes;
        } else if (parms.duration <= 0 &&
            ribbonState == RIBBON_DEACTIVATING) {
            --numActiveNodes;
        } else {
            break;
        }
    }
    if (numActiveNodes <= 0) {
        numActiveNodes = 0;
        explicitDefineBothEdges = false;
        ribbonState = RIBBON_INACTIVE;
    }
}

int idRibbon::GetRemainingTime(const int currentTime) const {
    idRibbonParameters parms{};
    if (!GameLib_GetRibbonParameters(ribbonDecl, parms) ||
        parms.duration <= 0) {
        return 0;
    }
    int remaining = 0;
    for (int offset = 0; offset < numActiveNodes; ++offset) {
        const int index =
            (currHeadIdx - offset + MAX_NODES) % MAX_NODES;
        remaining = (std::max)(remaining,
            ribbonNodes[index].spawnTime + parms.duration - currentTime);
    }
    return remaining;
}

void idRibbon::UpdateGeometry(const int currentTime,
    idRenderModelBeam* const beamModel, const idMat3& viewAxis,
    const idVec3& viewOrigin) {
    RemoveOldNodes(currentTime);
    if (beamModel == nullptr) {
        return;
    }
    const int firstNode = numActiveNodes > 0
        ? (currHeadIdx - numActiveNodes + 1 + MAX_NODES) % MAX_NODES
        : 0;
    GameLib_UpdateRibbonGeometry(beamModel, ribbonDecl, ribbonNodes,
        firstNode, numActiveNodes, currentTime, viewAxis, viewOrigin,
        explicitDefineBothEdges, globalColor);
}
