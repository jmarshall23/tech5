#pragma once

#include "dynamiccovermgr.h"

enum vehicleDriver_t {
    VEHICLE_DRIVER_ATV = 0,
    VEHICLE_DRIVER_CAR = 1,
    VEHICLE_DRIVER_MAX = 2
};

enum idVehicleCoverDebugResult : int {
    VEHICLE_COVER_DEBUG_SUBMITTED = 0,
    VEHICLE_COVER_DEBUG_CONTENTS_BLOCKED,
    VEHICLE_COVER_DEBUG_TRANSLATION_MISSED,
    VEHICLE_COVER_DEBUG_INVALID_AREA,
    VEHICLE_COVER_DEBUG_VALID
};

struct idVehicleCoverOwnerRuntime {
    bool forced;
    bool isVehicle;
    bool providesDynamicCover;
    idVec3 linearVelocity;
};

struct idVehicleCoverUsableRuntime {
    bool ownerStateValid;
    bool clipModelValid;
    bool tagTransformValid;
    idVec3 origin;
    idVec3 direction;
    idVec3 up;
    idClipQuery contentsQuery;
    idClipQuery translationQuery;
};

struct idVehicleCoverCurrentRuntime {
    bool contentsReady;
    int contentsFlags;
    idVec3 contentsEndPosition;
    bool translationReady;
    float translationFraction;
    idVec3 translationEndPosition;
    int translationAreaNumber;
};

class idVehicleCover : public idDynamicCover {
public:
    idVehicleCover();
    ~idVehicleCover() override = default;

    void UpdateUsable(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
    void InternalUpdateCurrent(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
    void InternalUpdateUsable(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
};

class idVehicleCoverMgr : public idDynamicCoverMgr {
public:
    idDynamicCover* AllocCover(const idAAS2* aas) override;
    void FreeCover(idDynamicCover* cover) override;
};

bool Tungsten_GetVehicleCoverOwnerRuntime(const idEntity& owner,
    idVehicleCoverOwnerRuntime& runtime);
bool Tungsten_GetVehicleCoverUsableRuntime(const idEntity& owner,
    const idAAS2& aas, int coverIndex, const char* tagName,
    idVehicleCoverUsableRuntime& runtime);
bool Tungsten_GetVehicleCoverCurrentRuntime(const idEntity& owner,
    const idAAS2& aas, int coverIndex, const idClipQuery& contentsQuery,
    const idClipQuery& translationQuery,
    idVehicleCoverCurrentRuntime& runtime);
void Tungsten_DebugVehicleCover(const idAAS2& aas,
    int coverIndex, idVehicleCoverDebugResult result,
    const idVec3& position, float translationFraction);
