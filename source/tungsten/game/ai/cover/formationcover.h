#pragma once

#include "dynamiccovermgr.h"

enum idFormationCoverDebugResult : int {
    FORMATION_DEBUG_SUBMITTED = 0,
    FORMATION_DEBUG_CONTENTS_BLOCKED,
    FORMATION_DEBUG_TRANSLATION_MISSED,
    FORMATION_DEBUG_INVALID_AREA,
    FORMATION_DEBUG_VALID
};

struct idFormationCoverUsableRuntime {
    bool ownerStateValid;
    bool clipModelValid;
    bool tagTransformValid;
    idVec3 origin;
    idVec3 direction;
    idVec3 up;
    idClipQuery contentsQuery;
    idClipQuery translationQuery;
};

struct idFormationCoverCurrentRuntime {
    bool ownerStateValid;
    bool tagTransformValid;
    idVec3 origin;
    idVec3 direction;
    bool contentsReady;
    int contentsFlags;
    idVec3 contentsEndPosition;
    bool translationReady;
    float translationFraction;
    idVec3 translationEndPosition;
    int translationAreaNumber;
};

class idFormationCover : public idDynamicCover {
public:
    idFormationCover();
    ~idFormationCover() override = default;

    void UpdateUsable(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
    void InternalUpdateCurrent(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
    void InternalUpdateUsable(
        const idEntity* owner, const idAAS2* aas, int currentTime) override;
};

class idFormationCoverMgr : public idDynamicCoverMgr {
public:
    idDynamicCover* AllocCover(const idAAS2* aas) override;
    void FreeCover(idDynamicCover* cover) override;
};

bool Tungsten_IsFormationCoverOwnerDead(const idEntity& owner);
bool Tungsten_GetFormationCoverUsableRuntime(const idEntity& owner,
    const idAAS2& aas, int coverIndex,
    idFormationCoverUsableRuntime& runtime);
bool Tungsten_GetFormationCoverCurrentRuntime(const idEntity& owner,
    const idAAS2& aas, int coverIndex,
    const idClipQuery& contentsQuery,
    const idClipQuery& translationQuery,
    idFormationCoverCurrentRuntime& runtime);
void Tungsten_DebugFormationCover(const idAAS2& aas,
    int coverIndex, idFormationCoverDebugResult result,
    const idVec3& position, float translationFraction);
