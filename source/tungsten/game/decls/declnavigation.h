#pragma once

#include "decls/decltypeinfo.h"
#include "game/navpower/navtypes.h"
#include "idlib/containers/list.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

class idDeclNavigation : public idDeclTypeInfo {
public:
    enum navCategory_t : int {
        NAVCAT_PLAYER = 0,
        NAVCAT_MONSTER = 1,
        NAVCAT_VEHICLE = 2,
        NAVCAT_MAX = 3
    };

    enum navGenType_t : int {
        NAVGEN_2D_SURFACES = 0,
        NAVGEN_3D_VOLUMES = 1
    };

    struct coverSet_t {
        idNavCoverInfo_t coverLow;
        idNavCoverInfo_t coverMid;
        idNavCoverInfo_t coverHigh;
    };

    idDeclNavigation();
    ~idDeclNavigation() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static const idDeclNavigation* FindDeclByLayer(navLayer_t layer);
    void GetResourceNames(const char* mapName,
        idList<idStr, 5>& fileNames) const;

    navGenType_t navGenType;
    navCategory_t navCategory;
    navLayer_t navLayer;
    idAtomicString fileExtensionNav;
    idAtomicString groupName;
    idAtomicString altGroupName;
    navCustomFlags_t includeSurfaceFlags;
    float voxelSize;
    float agentRadius;
    float agentHeight;
    float agentStepHeight;
    float agentWalkableSlope;
    float agentLedgeRadius;
    float verticalOffsetDist;
    float vertexSnap;
    float customMergeDistance;
    float additionalInwardsSmoothingDist;
    bool useEnhancedTerrainTracking;
    bool tessellateForPathAccuracy;
    int islandsMax;
    float islandsMinSurfaceArea;
    bool islandsLeaveSmallTouchingPortals;
    bool addBrushesAsExclusions;
    bool optimizeForAxisAligned;
    float volumeDistanceTolerance;
    float volumeAngleTolerance;
    bool buildImpNodeSurfaces;
    bool useCollisionModels;
    bool useEntityIslandMetadata;
    bool bakeFlightVolumes;
    coverSet_t cover;

    static idDeclInfoTemplate<idDeclNavigation> resourceList;
};

static_assert(sizeof(idDeclNavigation::coverSet_t) == 48,
    "Recovered navigation cover-set ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclNavigation) == 208,
    "Recovered navigation declaration ABI changed");
#endif
