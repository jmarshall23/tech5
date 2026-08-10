#pragma once

#include "../aideathvolume.h"
#include "idlib/math/vector.h"

class idAI2;
class idScenePoint;

// The PDB identifies scenePointType_t as a bitmask.  The four concrete
// scene-point constructors establish these exact retail values.
enum scenePointType_t : int {
    SCENEPOINT_NONE = 0,
    ROAM = 1,
    LOOK = 2,
    SEARCH = 3,
    COMBAT = 4
};

enum scenePointLookFlags_t : int {
    LOOKFLAG_NONE = 0
};

// idAIPos is a vector followed by its validity byte in the retail x86
// object.  Naming the padding prevents host compilers from changing the
// recovered 16-byte layout.
class idAIPos {
public:
    idAIPos() : origin(), valid(false), padding{} {}
    explicit idAIPos(const idVec3& value)
        : origin(value), valid(true), padding{} {}

    idVec3 origin;
    bool valid;
    unsigned char padding[3];
};

static_assert(sizeof(idAIPos) == 16, "idAIPos retail layout changed");

struct idScriptScenePointRuntime {
    int scriptFlags;
    bool hasPlayer;
    bool playerInArc;
    int lastDamageTime;
    int currentScenePointTakeTime;
    int currentScenePointActivateTime;
    bool hasEnemyState;
    unsigned int enemyAwareness;
    bool enemyVisible;
};

struct idScenePointRuntime {
    bool enabled;
    scenePointType_t type;
    int scriptFlags;
    bool hasCurrentUser;
    int requestTime;
    idVec3 origin;
    bool inFocusArc;
    bool lookCastValid;
    int lookFlags;
    bool combatCastValid;
    bool hasTurret;
    bool tactical;
    bool hasDeathAnimation;
    const idAnimWebPath* customCoverSet;
    float lookHistoryScore;
    float historyScore;
};

struct idScenePointSelectionRuntime {
    bool usesScenePointType;
    int currentTime;
    idScenePoint* lastHeldScenePoint;
    idScenePoint* nextMatchingScenePoint;
    idScenePoint* nextScenePoint;
    idScenePoint* overrideScenePoint;
    bool hasScenePointVolumes;
    idVec3 aiOrigin;
    bool hasSquadLeader;
    idVec3 squadLeaderOrigin;
    float squadScenePointRange;
    int selectionFlags;
    float coverVerticalWeight;
    float coverRandomWeight;
    float coverTacticalWeight;
    float coverHistoryWeight;
    bool hasEnemy;
    idVec3 enemyForward;
    idScenePoint* const* candidatePoints;
    int candidateCount;
};

bool IsScriptScenePointValid(
    const idAI2* ai, const idScenePoint* scriptScenePoint);
bool SupportsCustomCoverSet(
    const idAI2* ai, const idAnimWebPath& animPath);
idScenePoint* GetBestScenePoint(idAI2* ai, float minRange,
    float maxRange, const idAIPos& focus, scenePointType_t type,
    scenePointLookFlags_t lookFlags);

bool Tungsten_GetScriptScenePointRuntime(const idAI2& ai,
    const idScenePoint& point, idScriptScenePointRuntime& runtime);
void Tungsten_GetScenePointWeaponPrefix(
    const idAI2& ai, idStr& prefix);
void Tungsten_SplitScenePointAnimWebPath(const idAI2& ai,
    const char* path, idStr& subWebName, idStr& stateName);
bool Tungsten_HasScenePointAnimWebState(const idAI2& ai,
    const char* subWebName, const char* stateName);
bool Tungsten_GetScenePointSelectionRuntime(const idAI2& ai,
    scenePointType_t type, idScenePointSelectionRuntime& runtime);
bool Tungsten_GetScenePointRuntime(const idAI2& ai,
    const idScenePoint& point, const idAIPos& focus,
    idScenePointRuntime& runtime);
void Tungsten_SetOverrideScenePoint(idAI2& ai, idScenePoint* point);
void Tungsten_SetScenePointSelectionTime(idAI2& ai,
    scenePointType_t type, int currentTime);
float Tungsten_ScenePointRandomFloat();
