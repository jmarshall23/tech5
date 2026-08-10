#pragma once

#include "../../../shared/idlib/math/vector.h"

#include <cstdint>

class idAAS2;
class idEntity;

class idAASPosition {
public:
    int GetAreaNum() const;
    void Initialize(const idAAS2* aas, int areaNum, const idVec3& origin);
    void Update(const idAAS2* aas, const idVec3& origin);
    void Update(const idAAS2* aas, const idEntity* entity);

    bool valid;
    std::uint16_t areaNum;
    idVec3 origin;
    idVec3 validOrigin;
    const idAAS2* aas;
};

class idAASPositionMgr {
public:
    idAASPositionMgr();

    const idAASPosition& GetAASPosition(
        const idAAS2* aas, const idEntity* entity);

    idAASPosition aasPosition[2];
    int lastUpdateFrame[2];
    int numAASPositions;

private:
    int AllocAASPositionIndex(const idAAS2* aas);
};

bool Tungsten_DebugAASPositionEnabled();
void Tungsten_DebugAASPositionPoint(
    const idVec3& point, bool validOriginPoint);
int Tungsten_AASPositionPointAreaNum(
    const idAAS2& aas, const idVec3& origin);
int Tungsten_AASPositionPointReachableAreaNum(
    const idAAS2& aas, const idVec3& origin, int areaFlags,
    int excludeTravelFlags);
void Tungsten_AASPositionPushPointIntoAreaNum(
    const idAAS2& aas, int areaNum, idVec3& origin);
const idVec3& Tungsten_GetAASPositionEntityOrigin(const idEntity& entity);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAASPosition) == 32,
    "Recovered cached AAS-position ABI changed");
static_assert(sizeof(idAASPositionMgr) == 76,
    "Recovered AAS-position manager ABI changed");
#endif
