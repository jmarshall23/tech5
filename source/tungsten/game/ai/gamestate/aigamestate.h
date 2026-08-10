#pragma once

#include "gamelib/effects/weapontracemanager.h"
#include "idlib/blockalloc_base.h"
#include "idlib/bv/boundsshort.h"
#include "idlib/containers/array.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idDeclFaction;
class idEntity;
class idGameLocal;
enum invalidAIEvent_t : int;

using idAIGameEventHandle = idHandle<int, invalidAIEvent_t, -1>;

struct aiPhysicalState_t {
    idVec3 origin;
    idVec3 velocity;
    idQuat rotation;
    idBoundsShort bounds;
    idVec3 viewfwd;
    idVec3 eyePos;
    std::int16_t crouchChangeDelta;
    std::int16_t entFlags;
    std::uint8_t stimScale;
};

struct aiLatchedState_t {
    aiPhysicalState_t physical;
    const idDeclFaction* faction;
    idSpawnId spawnId;
    idSpawnId masterId;
    int frameNum;
    std::int16_t groupHandle;
    std::uint8_t horzFOV;
    std::uint8_t vertFOV;
    std::uint8_t entityType;
};

struct aiLatchedEvent_t {
    int eventTime;
    idAIGameEventHandle eventHandle;
    idVec3 origin;
    idSpawnId creatorId;
    idSpawnId relevantId;
    std::uint8_t priority;
    std::uint8_t flags;
    int eventClass;
};

enum aiPhysicalEntityFlags_t : int {
    AIPHYSICAL_DEAD = 0x01,
    AIPHYSICAL_CROUCHED = 0x02,
    AIPHYSICAL_LEAN_RIGHT = 0x04,
    AIPHYSICAL_LEAN_LEFT = 0x08,
    AIPHYSICAL_NO_AI_INTERACTION = 0x20,
    AIPHYSICAL_DRIVING = 0x40,
    AIPHYSICAL_DYING = 0x80
};

struct idAIGamePhysicalRuntime {
    bool hasPhysics;
    idVec3 origin;
    idVec3 velocity;
    idQuat rotation;
    idBounds bounds;
    idVec3 viewForward;
    idVec3 eyePosition;
    bool dead;
    bool dying;
    bool actor;
    int leanState;
    bool drivingVehicle;
    int posture;
    bool networkSynchronized;
};

struct idAIGameEntityRuntime {
    bool hasPhysics;
    int entityNumber;
    int physicsContents;
    int spawnIdValue;
    int contents;
    idSpawnId spawnId;
    const idDeclFaction* faction;
    std::int16_t groupHandle;
    std::uint8_t entityType;
    idSpawnId masterId;
    int masterSpawnId;
    idVec3 viewForward;
    std::uint8_t horizontalFov;
    std::uint8_t verticalFov;
    std::uint8_t aiHorizontalFov;
    std::uint8_t stimulusScaleByte;
    std::uint8_t horizontalFOV;
    std::uint8_t verticalFOV;
    bool isAI;
    float aiFovDot;
    float stimulusScale;
    idVec3 origin;
    idVec3 velocity;
    idQuat rotation;
    idBounds bounds;
    idVec3 eyePosition;
    bool dead;
    bool dying;
    bool actor;
    int leanState;
    bool drivingVehicle;
    int posture;
    bool noAIInteraction;
};

struct idAIGameEventRuntime {
    int handle;
    int eventTime;
    idVec3 origin;
    idSpawnId creatorId;
    idSpawnId relevantId;
    int creatorSpawnId;
    int relevantSpawnId;
    std::uint8_t priority;
    std::uint8_t flags;
    bool instigatorStimulus;
    int eventClass;
    const idEntity* creator;
    const idEntity* relevant;
};

class idAIGameState {
public:
    idAIGameState();
    ~idAIGameState();

    const aiLatchedState_t* GetState(const idSpawnId& spawnId) const;
    const aiLatchedState_t* GetStateForEntityNum(int entityNumber) const;
    const aiLatchedEvent_t* GetEvent(
        const idAIGameEventHandle& handle) const;

    void Shutdown();
    static bool GetPhysicalState(const idGameLocal* game,
        const idEntity* entity, aiPhysicalState_t& physicalState);
    void LatchEntityState(const idGameLocal* game,
        const idEntity* entity, bool force);
    void UpdateFromGame(const idGameLocal* game);
    void UpdateForcedLatches(const idGameLocal* game);
    void ForceLatch(const idSpawnId& spawnId);

    idArray<aiLatchedState_t*, 8192> entStates;
    idArray<aiLatchedEvent_t*, 256> events;
    idList<idSpawnId, 5> forcedLatches;
    idBlockAlloc<aiLatchedState_t, 256, 63> stateAllocator;
    idBlockAlloc<aiLatchedEvent_t, 64, 63> eventAllocator;
    int gameTime;
    int gameFrame;
    int numEvents;
    int garbageIndex;
};

bool Tungsten_GetAIGamePhysicalRuntime(const idGameLocal& game,
    const idEntity& entity, idAIGamePhysicalRuntime& runtime);
bool Tungsten_GetAIGameEntityRuntime(const idGameLocal& game,
    const idEntity& entity, idAIGameEntityRuntime& runtime);
int Tungsten_GetAIGameStateGameTime(const idGameLocal& game);
int Tungsten_GetAIGameStateFrame(const idGameLocal& game);
int Tungsten_GetAIGameStateMillisecondsPerFrame(const idGameLocal& game);
std::uint8_t Tungsten_AIGameStateFOVDotToByte(float fovDot);
std::uint8_t Tungsten_AIGameStateStimulusScaleToByte(float scale);
int Tungsten_GetAIGameStateActiveEntityCount(const idGameLocal& game);
const idEntity* Tungsten_GetAIGameStateActiveEntity(
    const idGameLocal& game, int index);
const idEntity* Tungsten_ResolveAIGameStateSpawnId(
    const idGameLocal& game, idSpawnId spawnId);
const idEntity* Tungsten_GetAIGameStateEntityForNumber(
    const idGameLocal& game, int entityNumber);
idSpawnId Tungsten_GetAIGameStateEntitySpawnId(
    const idGameLocal& game, const idEntity& entity);
int Tungsten_GetAIGameStateEventCount(const idGameLocal& game);
bool Tungsten_GetAIGameStateEvent(const idGameLocal& game,
    int index, idAIGameEventRuntime& runtime);
bool Tungsten_IsAIGameStateDebugEnabled();
void Tungsten_DebugAIGameState(
    int activeCount, int forcedCount, int latchedCount);
void Tungsten_WarnAIGameStateEventCapacity(int skippedEventCount);

// Compatibility spellings used by the first recovered runtime boundary.
int Tungsten_GetAIGameMillisecondsPerFrame(const idGameLocal& game);
void Tungsten_GetAIGameTimeAndFrame(const idGameLocal& game,
    int& gameTime, int& gameFrame);
int Tungsten_GetAIGameActiveEntityCount(const idGameLocal& game);
const idEntity* Tungsten_GetAIGameActiveEntity(
    const idGameLocal& game, int index);
const idEntity* Tungsten_ResolveAIGameEntity(
    const idGameLocal& game, int spawnId);
int Tungsten_GetAIGameEntitySpawnId(
    const idGameLocal& game, int entityNumber);
int Tungsten_GetAIGameEventCount(const idGameLocal& game);
bool Tungsten_GetAIGameEventRuntime(const idGameLocal& game,
    int index, idAIGameEventRuntime& runtime);
void Tungsten_WarnAIGameEventOverflow(int skippedEventCount);
