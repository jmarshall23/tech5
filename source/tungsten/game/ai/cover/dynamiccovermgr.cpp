#include "dynamiccovermgr.h"

// Retail symbol: ?FindCoverForAAS@idDynamicCoverMgr@@ABAHPBVidAAS2@@@Z
// EA: 0x82A8F130, RVA: 0x00A8F130
int idDynamicCoverMgr::FindCoverForAAS(const idAAS2* const aas) const {
    for (int index = 0; index < list.Num(); ++index) {
        if (Tungsten_GetDynamicCoverAAS(index) == aas) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?Shutdown@idDynamicCoverMgr@@QAAXXZ
// EA: 0x82A8F198, RVA: 0x00A8F198
void idDynamicCoverMgr::Shutdown() {
    for (int index = 0; index < list.Num(); ++index) {
        FreeCover(list[index]);
        list[index] = nullptr;
    }
    list.ClearFree();
}

// Retail symbol:
// ?AppendUsableCover@idDynamicCoverMgr@@QBAHPBVidEntity@@PBVidAAS2@@AAV?$idList@VidAICover@@$04@@@Z
// EA: 0x82A8F240, RVA: 0x00A8F240
int idDynamicCoverMgr::AppendUsableCover(const idEntity* const owner,
        const idAAS2* const aas,
        idList<idAICover, 5>& coverList) const {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->InternalAppendUsableCover(
            owner, aas, coverList)
        : 0;
}

// Retail symbol: ?NumCoverPoints@idDynamicCoverMgr@@UBAHPBVidAAS2@@@Z
// EA: 0x82A8F2A0, RVA: 0x00A8F2A0
int idDynamicCoverMgr::NumCoverPoints(const idAAS2* const aas) const {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->numCover : 0;
}

// Retail symbol:
// ?GetCoverPoint@idDynamicCoverMgr@@UBAPBUaas2Cover_t@@PBVidAAS2@@H@Z
// EA: 0x82A8F300, RVA: 0x00A8F300
aas2Cover_t* idDynamicCoverMgr::GetCoverPoint(
        const idAAS2* const aas, const int index) {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->GetCoverPoint(index) : nullptr;
}

const aas2Cover_t* idDynamicCoverMgr::GetCoverPoint(
        const idAAS2* const aas, const int index) const {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->GetCoverPoint(index) : nullptr;
}

// Retail symbol:
// ?GetReserver@idDynamicCoverMgr@@UBAPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A8F360, RVA: 0x00A8F360
const idEntity* idDynamicCoverMgr::GetReserver(
        const idAAS2* const aas, const int index) const {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->GetReserver(index) : nullptr;
}

// Retail symbol:
// ?Reserve@idDynamicCoverMgr@@UAAXPBVidAAS2@@HPBVidEntity@@@Z
// EA: 0x82A8F3C0, RVA: 0x00A8F3C0
void idDynamicCoverMgr::Reserve(const idAAS2* const aas,
        const int index, const idEntity* const entity) {
    const int coverIndex = FindCoverForAAS(aas);
    if (coverIndex >= 0 && list[coverIndex] != nullptr) {
        list[coverIndex]->Reserve(index, entity);
    }
}

// Retail symbol: ?Unreserve@idDynamicCoverMgr@@UAAXPBVidAAS2@@H@Z
// EA: 0x82A8F408, RVA: 0x00A8F408
void idDynamicCoverMgr::Unreserve(
        const idAAS2* const aas, const int index) {
    const int coverIndex = FindCoverForAAS(aas);
    if (coverIndex >= 0 && list[coverIndex] != nullptr) {
        list[coverIndex]->Unreserve(index);
    }
}

// Retail symbol:
// ?GetUsableTime@idDynamicCoverMgr@@UBAHPBVidAAS2@@H@Z
// EA: 0x82A8F460, RVA: 0x00A8F460
int idDynamicCoverMgr::GetUsableTime(
        const idAAS2* const aas, const int index) const {
    const int coverIndex = FindCoverForAAS(aas);
    return coverIndex >= 0 && list[coverIndex] != nullptr
        ? list[coverIndex]->GetUsableTime(index) : 0;
}

// Retail symbol:
// ?SetUsableTime@idDynamicCoverMgr@@UAAXPBVidAAS2@@HH@Z
// EA: 0x82A8F4C0, RVA: 0x00A8F4C0
void idDynamicCoverMgr::SetUsableTime(const idAAS2* const aas,
        const int index, const int time) {
    const int coverIndex = FindCoverForAAS(aas);
    if (coverIndex >= 0 && list[coverIndex] != nullptr) {
        list[coverIndex]->SetUsableTime(index, time);
    }
}

// Retail symbol: ??0idDynamicCoverMgr@@QAA@XZ
// EA: 0x82A8F510, RVA: 0x00A8F510
idDynamicCoverMgr::idDynamicCoverMgr()
    : isInitializedFlag(false)
    , list() {
}

// Retail symbol: ??1idDynamicCoverMgr@@UAA@XZ
// EA: 0x82A8F5B8, RVA: 0x00A8F5B8
idDynamicCoverMgr::~idDynamicCoverMgr() = default;

// Retail symbol: ?Init@idDynamicCoverMgr@@QAAXXZ
// EA: 0x82A8F638, RVA: 0x00A8F638
void idDynamicCoverMgr::Init() {
    Shutdown();
    const int aasCount = Tungsten_GetDynamicCoverAASCount();
    for (int index = 0; index < aasCount; ++index) {
        list.Append(AllocCover(Tungsten_GetDynamicCoverAAS(index)));
    }
    isInitializedFlag = true;
}

// Retail symbol: ?UpdateUsable@idDynamicCoverMgr@@QAAXPBVidEntity@@H@Z
// EA: 0x82A8F748, RVA: 0x00A8F748
void idDynamicCoverMgr::UpdateUsable(
        const idEntity* const owner, const int currentTime) {
    if (!isInitializedFlag) {
        Init();
    }
    const idAAS2* const ownerAas = owner != nullptr
        ? Tungsten_GetDynamicCoverOwnerAAS(*owner) : nullptr;
    for (int index = 0; index < list.Num(); ++index) {
        const idAAS2* const aas = Tungsten_GetDynamicCoverAAS(index);
        if ((ownerAas == nullptr || ownerAas == aas)
            && list[index] != nullptr) {
            list[index]->UpdateUsable(owner, aas, currentTime);
        }
    }
}

// Retail symbol: ?ShowDynamicCover@idDynamicCoverMgr@@SAXABVidVec3@@M@Z
// EA: 0x82A8F9A0, RVA: 0x00A8F9A0
void idDynamicCoverMgr::ShowDynamicCover(
        const idVec3& point, const float distance) {
    const idAAS2* const aas = Tungsten_GetDynamicCoverDebugAAS();
    if (aas == nullptr) {
        return;
    }
    idList<idDynamicCoverMgr*, 5> managers;
    Tungsten_GatherDynamicCoverManagers(point, distance, *aas, managers);
    idList<idAICover, 5> covers;
    for (int index = 0; index < managers.Num(); ++index) {
        if (managers[index] != nullptr) {
            managers[index]->AppendUsableCover(nullptr, aas, covers);
        }
    }
    for (int index = 0; index < covers.Num(); ++index) {
        const aas2Cover_t* const pointData = covers[index].GetCoverPoint();
        if (pointData != nullptr) {
            Tungsten_DrawDynamicCoverPoint(
                *aas, *pointData, covers[index].coverIndex);
        }
    }
}
