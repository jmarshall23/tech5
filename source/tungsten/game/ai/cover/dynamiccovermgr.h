#pragma once

#include "dynamiccover.h"

class idDynamicCoverMgr {
public:
    idDynamicCoverMgr();
    virtual ~idDynamicCoverMgr();

    void Init();
    void Shutdown();
    void UpdateUsable(const idEntity* owner, int currentTime);
    int AppendUsableCover(const idEntity* owner, const idAAS2* aas,
        idList<idAICover, 5>& coverList) const;

    virtual int NumCoverPoints(const idAAS2* aas) const;
    virtual aas2Cover_t* GetCoverPoint(const idAAS2* aas, int index);
    virtual const aas2Cover_t* GetCoverPoint(
        const idAAS2* aas, int index) const;
    virtual const idEntity* GetReserver(
        const idAAS2* aas, int index) const;
    virtual void Reserve(const idAAS2* aas, int index,
        const idEntity* entity);
    virtual void Unreserve(const idAAS2* aas, int index);
    virtual int GetUsableTime(const idAAS2* aas, int index) const;
    virtual void SetUsableTime(
        const idAAS2* aas, int index, int time);
    virtual idDynamicCover* AllocCover(const idAAS2* aas) = 0;
    virtual void FreeCover(idDynamicCover* cover) = 0;

    static void ShowDynamicCover(const idVec3& point, float distance);

protected:
    int FindCoverForAAS(const idAAS2* aas) const;

public:
    bool isInitializedFlag;
    idList<idDynamicCover*, 5> list;
};

int Tungsten_GetDynamicCoverAASCount();
const idAAS2* Tungsten_GetDynamicCoverAAS(int index);
const idAAS2* Tungsten_GetDynamicCoverOwnerAAS(const idEntity& owner);
const idAAS2* Tungsten_GetDynamicCoverDebugAAS();
void Tungsten_GatherDynamicCoverManagers(const idVec3& point,
    float distance, const idAAS2& aas,
    idList<idDynamicCoverMgr*, 5>& managers);
void Tungsten_DrawDynamicCoverPoint(
    const idAAS2& aas, const aas2Cover_t& cover, int coverIndex);
