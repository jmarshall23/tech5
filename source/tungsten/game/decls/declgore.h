#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"

class idDeclInfo;

enum goreLevel_t : int {
    GORELEVEL_NONE = 0,
    GORELEVEL_BLOOD = 1,
    GORELEVEL_LIGHT_DAMAGE = 2,
    GORELEVEL_HEAVY_DAMAGE = 3,
    GORELEVEL_TATTERED = 4,
    GORELEVEL_DISMEMBERED = 5
};

enum goreType_t : int {
    GORETYPE_NONE = 0,
    GORETYPE_DECAPITATION = 1,
    GORETYPE_DISMEMBER_ARMS = 2,
    GORETYPE_DISMEMBER_LEGS = 4,
    GORETYPE_GIB = 8,
    GORETYPE_HEAD_EXPLODE = 16,
    GORETYPE_SMALL_WOUND = 32,
    GORETYPE_BIG_WOUND = 64,
    GORETYPE_TORSO_SAW = 128,
    GORETYPE_BFG = 256,
    GORETYPE_ANY = 0x7FFFFFFF
};

enum goreKitComponent_t : int {
    MESH_KIT_HEADS = 0,
    MESH_KIT_GEAR = 1,
    MESH_KIT_GORE = 2,
    MESH_KIT_NUM = 3
};

struct goreKitInfo_t {
    idAtomicString meshKit;
    goreKitComponent_t kitType = MESH_KIT_HEADS;
};

enum goreClipShapeType_t : int {
    CLIPSHAPETYPE_NONE = 0,
    CLIPSHAPETYPE_SPHERE = 1,
    CLIPSHAPETYPE_ELLIPSOID = 2
};

enum goreSpawnImpulseBehavior_t : int {
    GORE_IMPULSE_WITH_DAMAGE = 0,
    GORE_IMPULSE_AWAY_FROM_DAMAGE = 1,
    GORE_IMPULSE_UP = 2
};

struct goreBloodTrail_t {
    float halfWidth = 0.0f;
    float halfLength = 0.0f;
    float lifeTime = 0.0f;
    float fadeTime = 0.0f;
    const void* material = nullptr;
};

struct idGorePieceInfo_t {
    struct clipShape_t {
        idMat3 axis = idMat3(1.0f);
        idVec3 origin = idVec3(0.0f, 0.0f, 0.0f);
        goreClipShapeType_t type = CLIPSHAPETYPE_NONE;
    };

    struct clothInfo_t {
        const void* clothDecl = nullptr;
        idAtomicString clothAttachTag;
        goreBloodTrail_t bloodTrail;
        const void* gibEntity = nullptr;
        bool gibEntityIsBreakable = false;

        // Header retail inline: 0x82C5B6E0
        bool EntityToSpawnIsABreakable() const {
            return gibEntity != nullptr && gibEntityIsBreakable;
        }
    };

    idAtomicString name;
    goreLevel_t goreLevel = GORELEVEL_NONE;
    int goreType = GORETYPE_NONE;
    idAtomicString jointToZeroOut;
    idAtomicString constraintToBreak;
    idList<goreKitInfo_t, 5> showKitInfo;
    idList<goreKitInfo_t, 5> hideKitInfo;
    idList<idAtomicString, 5> damageGroups;
    const void* entityToSpawn = nullptr;
    bool entityToSpawnIsBreakable = false;
    goreSpawnImpulseBehavior_t spawnedEntityImpulseBehavior =
        GORE_IMPULSE_WITH_DAMAGE;
    idAtomicString fxTagJoint;
    float damageRequiredToGore = 0.0f;
    idList<int, 5> fxToPlay;
    idList<int, 5> morphVertIndex;
    idList<int, 5> clipSphereIndex;
    idList<idAtomicString, 5> exclusionList;
    idList<idAtomicString, 5> overrideList;
    clipShape_t clipShape;
    clothInfo_t cloth;

    // Header retail inline: 0x82C5B678
    bool EntityToSpawnIsABreakable() const {
        return entityToSpawn != nullptr && entityToSpawnIsBreakable;
    }
};

struct idGoreDeathFade {
    float deathFadeStartTime = -1.0f;
    float deathFadeLength = 0.0f;
};

class idDeclGore {
public:
    idList<idGorePieceInfo_t, 5> gorePieces;
    idList<const void*, 5> damageSplatterDecals;
    idList<const void*, 5> fullBodyBreakableGibs;
    idGoreDeathFade deathFadeInfo;
    idDeclInfo* declInfo = nullptr;

    // Header retail inline: 0x82BD6D18
    idDeclInfo* GetDeclInfo() { return declInfo; }
};
