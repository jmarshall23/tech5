#pragma once

#include "aicover.h"
#include "idlib/containers/list.h"

class idAI2;

struct idAICoverManagerRuntime {
    idAICoverManagerRuntime();

    const idAAS2* aas;
    int travelFlags;
    int dynamicCoverCapabilities;
    float coverRadius;
    float coverRadiusOverride;
    bool useVehicleCover;
    bool useFormationCover;
    bool useStageCoverFilter;
};

class idAICoverManager {
public:
    idAICoverManager();

    void UpdateCover(idAI2* ai, const idVec3& referencePoint,
        int currentTime, bool force, bool useStageFilter);
    bool HasCover(idAI2* ai, const idVec3& referencePoint,
        int currentTime, bool inAvoid);

    idList<idAICover, 5> knownCover;
    int lastUpdateTime;
    int lastTravelFlags;
    idVec3 lastUpdatePos;
    bool forceUpdate;
};

bool Tungsten_GetAICoverManagerRuntime(
    const idAI2& ai, idAICoverManagerRuntime& runtime);
int Tungsten_PopulateAICoverManager(const idAI2& ai,
    const idAICoverManagerRuntime& runtime,
    const idVec3& referencePoint, bool useStageFilter,
    idList<idAICover, 5>& knownCover);
void Tungsten_DebugAICoverManagerUpdate(const idAI2& ai,
    int currentTime, int elapsedTime, float movedDistance,
    bool travelFlagsChanged, int dynamicCoverCount);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAICoverManager) == 40,
    "Recovered AI cover-manager ABI changed");
#endif
