#pragma once

#include "aicover.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"

#include <cstdint>

class idAAS2;
class idClipModel;
class idEntity;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    std::uint64_t index;
};
#endif

class idDynamicCover {
public:
    struct coverInfo_t {
        aas2Cover_t cover;
        idClipQuery contentsQuery;
        idClipQuery translationQuery;
    };

    explicit idDynamicCover(int numberOfCoverPoints);
    virtual ~idDynamicCover();

    virtual void UpdateUsable(
        const idEntity*, const idAAS2*, int) {}
    virtual void InternalUpdateCurrent(
        const idEntity*, const idAAS2*, int) {}
    virtual void InternalUpdateUsable(
        const idEntity*, const idAAS2*, int) {}
    virtual int InternalAppendUsableCover(const idEntity* owner,
        const idAAS2* aas, idList<idAICover, 5>& coverList);
    virtual void MarkAllUnusable();
    virtual void MarkAllUsable();

    static const idClipModel* GetClipForAAS(const idAAS2* aas);
    static const char* GetPropNameForAAS(const idAAS2* aas);

    aas2Cover_t* GetCoverPoint(int index);
    const aas2Cover_t* GetCoverPoint(int index) const;
    const idEntity* GetReserver(int index) const;
    void Reserve(int index, const idEntity* entity);
    void Unreserve(int index);
    int GetUsableTime(int index) const;
    void SetUsableTime(int index, int time);

    int numCover;
    bool updated;
    idList<coverInfo_t, 5> coverInfo;
};

bool Tungsten_GetDynamicCoverAASBounds(
    const idAAS2& aas, idBounds& bounds);
const idClipModel* Tungsten_GetDynamicCoverClipModel(int hullSize);
void Tungsten_CancelDynamicCoverQuery(idClipQuery& query);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDynamicCover::coverInfo_t) == 72,
    "Recovered dynamic-cover point runtime layout changed");
#endif
