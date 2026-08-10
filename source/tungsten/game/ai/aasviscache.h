#pragma once

#include "../../../shared/idlib/containers/bitarray.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/math/vector.h"

#include <cstdint>

class idAAS2;
class idAASVisCache;
class idAASVisPoint;
class idCmdArgs;

class idAASVisArea {
public:
    idAASVisArea();

    bool IsPointVisible(const idAASVisCache* visCache,
        const idAASVisPoint* visPoint, const idVec3& testPoint);
    void CacheVisibilities(const idAASVisCache* visCache,
        const idAASVisPoint* visPoint, int areaNum);

    int areaNum;
    int xcells;
    int ycells;
    float visRatio;
    idBitArray cellVis;
};

class idAASVisPoint {
public:
    idAASVisPoint(const idVec3& eyePoint, int time);
    ~idAASVisPoint();

    bool IsPointVisible(const idAASVisCache* visCache,
        const idVec3& testPoint, int testPointAreaNum);
    float VisibilityRatio(const idAASVisCache* visCache, int areaNum);

    idVec3 eyePoint;
    idList<idAASVisArea*, 5> visAreas;
    int cacheTime;

private:
    void Free();
    idAASVisArea* AddVisArea(int areaNum);
    idAASVisArea* GetVisArea(int areaNum);
};

class idAASVisCache {
public:
    idAASVisCache();
    ~idAASVisCache();

    void Init(const idAAS2* aas, int subDivisionSize, float eyeHeight);
    void Shutdown();
    int GetNumCachedAreas() const;
    std::uint32_t Size() const;
    bool IsPointVisible(const idVec3& eyePoint, const idVec3& destPoint,
        const idAAS2* aas, int destAreaNum);
    float VisibilityRatio(
        const idVec3& eyePoint, const idAAS2* aas, int areaNum);
    static void Cmd_VisCacheInfo_f(const idCmdArgs& args);

    const idAAS2* aas;
    float eyeHeight;
    int subDivisionSize;
    idList<idAASVisPoint*, 93> visPoints;

private:
    idAASVisPoint* FindVisPoint(const idVec3& eyePoint);
    int FindOldest() const;
    void RemoveOldest();
    idAASVisPoint* AddVisPoint(const idVec3& eyePoint);
    void Free();
};

bool Tungsten_AASVisCacheWorldPosToCellPos(const idAAS2& aas, int areaNum,
    int subDivisionSize, const idVec3& point, int& x, int& y);
bool Tungsten_AASVisCacheGetAreaCells(const idAAS2& aas, int areaNum,
    int subDivisionSize, int& xcells, int& ycells);
void Tungsten_AASVisCacheCellPosToWorldPos(const idAAS2& aas, int areaNum,
    int subDivisionSize, int x, int y, idVec3& point, bool onFloor);
void Tungsten_AASVisCachePushPointIntoAreaNum(
    const idAAS2& aas, int areaNum, idVec3& point);
bool Tungsten_AASVisCacheTraceVisible(
    const idVec3& eyePoint, const idVec3& testPoint, int clipMask);
int Tungsten_GetAASVisCacheGameMilliseconds();
const idAASVisCache& Tungsten_GetGameAASVisCache();
void Tungsten_AASVisCachePrint(const char* text);
void Tungsten_AASVisCacheWarning(const char* text);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAASVisArea) == 28,
    "Recovered AAS visibility-area ABI changed");
static_assert(sizeof(idAASVisPoint) == 32,
    "Recovered AAS visibility-point ABI changed");
static_assert(sizeof(idAASVisCache) == 28,
    "Recovered AAS visibility-cache ABI changed");
#endif
