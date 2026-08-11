#include "game/decls/declnavigation.h"

idDeclInfoTemplate<idDeclNavigation> idDeclNavigation::resourceList(
    "navigation", "idDeclNavigation", "tdef");

// EA 0x82BC90A8
idDeclNavigation::idDeclNavigation()
    : navGenType(NAVGEN_2D_SURFACES)
    , navCategory(NAVCAT_MONSTER)
    , navLayer(NAVLAYER_MONSTER32)
    , fileExtensionNav("nav_monster32")
    , groupName("aas")
    , altGroupName("aas_monster32")
    , includeSurfaceFlags(NavCustomNone)
    , voxelSize(8.0f)
    , agentRadius(16.0f)
    , agentHeight(96.0f)
    , agentStepHeight(18.0f)
    , agentWalkableSlope(45.0f)
    , agentLedgeRadius(-1.0f)
    , verticalOffsetDist(2.0f)
    , vertexSnap(1.0f)
    , customMergeDistance(150.0f)
    , additionalInwardsSmoothingDist(0.0f)
    , useEnhancedTerrainTracking(false)
    , tessellateForPathAccuracy(false)
    , islandsMax(4096)
    , islandsMinSurfaceArea(0.0f)
    , islandsLeaveSmallTouchingPortals(false)
    , addBrushesAsExclusions(true)
    , optimizeForAxisAligned(false)
    , volumeDistanceTolerance(0.2f)
    , volumeAngleTolerance(5.0f)
    , buildImpNodeSurfaces(false)
    , useCollisionModels(false)
    , useEntityIslandMetadata(false)
    , bakeFlightVolumes(false)
    , cover{} {
}

// EA 0x82BC9268
const idDeclNavigation* idDeclNavigation::FindDeclByLayer(
        const navLayer_t layer) {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source == nullptr || source->name.c_str() == nullptr) {
            continue;
        }
        const idDeclNavigation* declaration =
            static_cast<const idDeclNavigation*>(
                resourceList.FindWithInheritance(
                    source->name.c_str(), true));
        if (declaration != nullptr && declaration->navLayer == layer) {
            return declaration;
        }
    }
    return nullptr;
}

// EA 0x82BC92F8
void idDeclNavigation::GetResourceNames(const char* mapName,
        idList<idStr, 5>& fileNames) const {
    idStr baseName;
    baseName.Format("maps/%s/%s/%s_base",
        mapName != nullptr ? mapName : "",
        fileExtensionNav.c_str(), fileExtensionNav.c_str());
    fileNames.Append(baseName);

    if (buildImpNodeSurfaces) {
        idStr impNodeName;
        impNodeName.Format("%s_impnodes", baseName.c_str());
        fileNames.Append(impNodeName);
    }
}
