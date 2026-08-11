#include "clientgame_local.h"

#include <cmath>
#include <cstring>

namespace {
idClientGameServices* g_clientGameServices = nullptr;
}

void Tungsten_SetClientGameServices(idClientGameServices* const services) {
    g_clientGameServices = services;
}

idReplicatedSound::idReplicatedSound()
    : channel(SND_CHANNEL_ANY), shader(nullptr), internalFlags(0),
      presentableIndex(0xFFFF), peerMask(0xFF), volume(0.0f), pitch(0.0f),
      position(0.0f, 0.0f, 0.0f), changed{}, lastChanged{},
      soundFadeTo(0.0f), clearVolumeAdjustment(false), soundFadeTime(0.0f),
      framesToForceKeep(0), volumeAdjustment(0.0f), time(0), parms{} {}

presentableThink_t::presentableThink_t()
    : name(nullptr), ms(0.0f), maxms(0.0f), avgms(0.0f), lastms(0.0f),
      numThinks(0), numDormantThinks(0), maxThinks(0), lastNumThinks(0),
      lastNumDormantThinks(0) {}

// Retail symbol: ?StringForPresentableType@@YAPBDW4presentableType_t@@@Z
// EA: 0x82B4AE80, RVA: 0x00B4AE80
const char* StringForPresentableType(const presentableType_t type) {
    switch (type) {
    case PRESENTABLE_GENERIC: return "PRESENTABLE_GENERIC";
    case PRESENTABLE_RENDERMODEL: return "PRESENTABLE_RENDERMODEL";
    case PRESENTABLE_ANIMATED_ENTITY: return "PRESENTABLE_ANIMATED_ENTITY";
    case PRESENTABLE_VEHICLE: return "PRESENTABLE_VEHICLE";
    case PRESENTABLE_BREAKABLE: return "PRESENTABLE_BREAKABLE";
    case PRESENTABLE_PIECE_EMITTER: return "PRESENTABLE_PIECE_EMITTER";
    case PRESENTABLE_DAMAGEABLE: return "PRESENTABLE_DAMAGEABLE";
    case PRESENTABLE_ACTOR: return "PRESENTABLE_ACTOR";
    case PRESENTABLE_PLAYER: return "PRESENTABLE_PLAYER";
    case PRESENTABLE_PROJECTILE: return "PRESENTABLE_PROJECTILE";
    case PRESENTABLE_PROJECTILE_GRENADE:
        return "PRESENTABLE_PROJECTILE_GRENADE";
    case PRESENTABLE_PROJECTILE_ROCKET:
        return "PRESENTABLE_PROJECTILE_ROCKET";
    case PRESENTABLE_PROJECTILE_HOMING:
        return "PRESENTABLE_PROJECTILE_HOMING";
    case PRESENTABLE_MULTIPLAYER_TRIGGER:
        return "PRESENTABLE_MULTIPLAYER_TRIGGER";
    case PRESENTABLE_AI: return "PRESENTABLE_AI";
    case PRESENTABLE_PROP: return "PRESENTABLE_PROP";
    case PRESENTABLE_WEAPON_STATIC: return "PRESENTABLE_WEAPON_STATIC";
    case PRESENTABLE_DOOR_ANIMATED: return "PRESENTABLE_DOOR_ANIMATED";
    case PRESENTABLE_WEAPON: return "PRESENTABLE_WEAPON";
    case PRESENTABLE_PARTICLE_EMITTER:
        return "PRESENTABLE_PARTICLE_EMITTER";
    case PRESENTABLE_COLLISION_TRIGGER:
        return "PRESENTABLE_COLLISION_TRIGGER";
    default: return "Unknown presentable";
    }
}

idClientGame::idClientGame()
    : previousServerTime(0), serverTime(0), playerTime(-1),
      vehicleRaceMap(false), objectList(0), presentables(0),
      activePresentables(0), pusherPresentables(0),
      vehiclePresentables(0), serializedPresentables(0),
      lobbyUserIDs(), inputToPlayerIndexRouting(), replicatedSounds(),
      entityToPresentableLUT(), activeViewCallbacks(0),
      queuedReliableMsgs(0),
      simulatingEffectPhysics(0), presentableThinks(0), guiModel(nullptr),
      firstFreePresentable(), presentableSpawnId(1), serialized(false),
      serializedChallengeMode(CHALLENGE_MODE_NORMAL),
      startSoundOverRun(0), overrideSoundPeerMask(0) {
    for (int& route : inputToPlayerIndexRouting) route = -1;
    for (int& presentableIndex : entityToPresentableLUT) {
        presentableIndex = -1;
    }
    firstFreePresentable[0] = 6;
    firstFreePresentable[1] = 0x2000;
    firstFreePresentable[2] = 0x3000;
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->InitializeClientGame(*this);
    }
}

// Retail symbol: ??1idClientGame@@QAA@XZ
// EA: 0x82B51F48, RVA: 0x00B51F48
idClientGame::~idClientGame() {
    DeleteAllPresentables();
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->ShutdownClientGame(*this);
    }
}

// Retail symbol: ?SetServerGameTime@idClientGame@@QAAXH@Z
// EA: 0x82B4B020, RVA: 0x00B4B020
void idClientGame::SetServerGameTime(const int time) {
    previousServerTime = serverTime;
    serverTime = time;
}

// Retail symbol: ?GetServerGameTime@idClientGame@@QBAHXZ
// EA: 0x82B4B040, RVA: 0x00B4B040
int idClientGame::GetServerGameTime() const {
    return serverTime;
}

// Retail symbol: ?GetPreviousServerGameTime@idClientGame@@QBAHXZ
// EA: 0x82B4B050, RVA: 0x00B4B050
int idClientGame::GetPreviousServerGameTime() const {
    return previousServerTime;
}

// Retail symbol: ??1idPlayerTimeLock@@QAA@XZ
// EA: 0x82B4B060, RVA: 0x00B4B060
idPlayerTimeLock::~idPlayerTimeLock() {
    if (g_clientGameServices != nullptr &&
            g_clientGameServices->GetClientGame() != nullptr) {
        g_clientGameServices->GetClientGame()->playerTime = lastTime;
    }
}

// Retail symbol: ?GetPresentableByIndex@idClientGame@@QBAPAVidPresentable@@H@Z
// EA: 0x82B4B258, RVA: 0x00B4B258
idPresentable* idClientGame::GetPresentableByIndex(const int index) const {
    return presentables[index];
}

// Retail symbol: ?IsPresentableIndexValid@idClientGame@@QBA_NH@Z
// EA: 0x82B4B270, RVA: 0x00B4B270
bool idClientGame::IsPresentableIndexValid(const int index) const {
    return index >= 0 && index < presentables.Num() &&
        presentables[index] != nullptr;
}

// Retail symbol: ?FindPlayerPresentableByIndex@idClientGame@@QBAPAVidPresentablePlayer@@H@Z
// EA: 0x82B4B2B8, RVA: 0x00B4B2B8
idPresentablePlayer* idClientGame::FindPlayerPresentableByIndex(
        const int playerNum) const {
    if (!IsPresentableIndexValid(playerNum) ||
            g_clientGameServices == nullptr) {
        return nullptr;
    }
    return g_clientGameServices->GetPlayerInterface(
        presentables[playerNum]);
}

// Retail symbol: ?GetLobbyUserIdFromPlayerIndex@idClientGame@@QBA?AUlobbyUserID_t@@H@Z
// EA: 0x82B4B308, RVA: 0x00B4B308
lobbyUserID_t idClientGame::GetLobbyUserIdFromPlayerIndex(
        const int playerIndex) const {
    return lobbyUserIDs[playerIndex];
}

// Retail symbol: ?SetLobbyUserIdForPlayerIndex@idClientGame@@QAAXHUlobbyUserID_t@@@Z
// EA: 0x82B4B330, RVA: 0x00B4B330
void idClientGame::SetLobbyUserIdForPlayerIndex(const int playerIndex,
        const lobbyUserID_t lobbyUserID) {
    lobbyUserIDs[playerIndex] = lobbyUserID;
}

// Retail symbol: ?GetProfileFromPlayerIndex@idClientGame@@QBAPAVidPlayerProfile@@H@Z
// EA: 0x82B4B348, RVA: 0x00B4B348
idPlayerProfile* idClientGame::GetProfileFromPlayerIndex(
        const int index) const {
    if (g_clientGameServices == nullptr) return nullptr;
    idPlayerProfile* const profile = g_clientGameServices->GetProfile(
        lobbyUserIDs[index], index);
    if (profile == nullptr) g_clientGameServices->ReportNullProfile(index);
    return profile;
}

// Retail symbol: ?GetLocalUserFromPlayerIndex@idClientGame@@QBAPAVidLocalUser@@H@Z
// EA: 0x82B4B3D0, RVA: 0x00B4B3D0
idLocalUser* idClientGame::GetLocalUserFromPlayerIndex(
        const int index) const {
    if (g_clientGameServices == nullptr || !lobbyUserIDs[index].IsValid()) {
        return nullptr;
    }
    return g_clientGameServices->GetLocalUser(lobbyUserIDs[index]);
}

// Retail symbol: ?PlayerIndexIsLocal@idClientGame@@QBA_NH@Z
// EA: 0x82B4B480, RVA: 0x00B4B480
bool idClientGame::PlayerIndexIsLocal(const int playerNum) const {
    for (const int routedPlayer : inputToPlayerIndexRouting) {
        if (routedPlayer == playerNum) return true;
    }
    return false;
}

// Retail symbol: ?SubmitEffectPhysicsCollisionQueries@idClientGame@@QAAXXZ
// EA: 0x82B4B4B8, RVA: 0x00B4B4B8
void idClientGame::SubmitEffectPhysicsCollisionQueries() {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->SubmitEffectPhysicsCollisionQueries(
            vehicleRaceMap);
    }
}

// EA 0x82B4B518 is idAnimator_BlendEq::InternalGetMergeBranch and is
// recovered inline in engine/gamelib/animstack/animator_blendeq.h.
// EA 0x82B4B520 is idParser::GetFlags and is recovered inline in
// shared/idlib/text/parser.h.

// Retail symbol: ?GetDeferredDecalMgr@idClientGame@@QAAPAVidDeferredDecalManager@@XZ
// EA: 0x82B4B528, RVA: 0x00B4B528
idDeferredDecalManager* idClientGame::GetDeferredDecalMgr() {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->GetDeferredDecalManager() : nullptr;
}

// Retail symbol: ?GetWeaponTraceMgr@idClientGame@@QAAPAVidWeaponTraceManager@@XZ
// EA: 0x82B4B530, RVA: 0x00B4B530
void* idClientGame::GetWeaponTraceMgr() {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->GetWeaponTraceManager() : nullptr;
}

// Retail symbol: ?GetWeaponImpactMgr@idClientGame@@QAAPAVidImpactManager@@XZ
// EA: 0x82B4B538, RVA: 0x00B4B538
idImpactManager* idClientGame::GetWeaponImpactMgr() {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->GetWeaponImpactManager() : nullptr;
}

// EA 0x82B4B540 is idPhysics_Static::GetAxis and remains with the engine
// physics-static implementation.

// Retail symbol: ?GetLocalViewForPlayerIndex@idClientGame@@QAAPAUlocalView_t@@H@Z
// EA: 0x82B4B548, RVA: 0x00B4B548
localView_t* idClientGame::GetLocalViewForPlayerIndex(const int playerNum) {
    idPresentablePlayer* const player =
        playerNum != -1 && PlayerIndexIsLocal(playerNum)
        ? FindPlayerPresentableByIndex(playerNum) : nullptr;
    return player != nullptr && g_clientGameServices != nullptr
        ? g_clientGameServices->GetLocalView(*player) : nullptr;
}

// Retail symbol: ?RenderLocalViewForPlayer@idClientGame@@QAAPAVidRenderModelGui@@HHPBUrenderView_t@@PAVidRenderWorld@@@Z
// EA: 0x82B4B620, RVA: 0x00B4B620
idRenderModelGui* idClientGame::RenderLocalViewForPlayer(
        const int playerNum, const int currentTime,
        const renderView_t* const view, idRenderWorld* const renderWorld) {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->RenderLocalView(playerNum, currentTime,
            view, renderWorld) : nullptr;
}

// Retail symbol: ?HandleGuiEventForPlayer@idClientGame@@QAA_NHPBUsysEvent_t@@@Z
// EA: 0x82B4B890, RVA: 0x00B4B890
bool idClientGame::HandleGuiEventForPlayer(const int playerNum,
        const sysEvent_t* const event) {
    localView_t* const localView = GetLocalViewForPlayerIndex(playerNum);
    if (localView == nullptr || g_clientGameServices == nullptr) return false;
    return g_clientGameServices->HandlePlayerGuiEvent(
        FindPlayerPresentableByIndex(playerNum), *localView, event);
}

// Retail symbol: ?IsPlayerControlInhibited@idClientGame@@QBA_NH@Z
// EA: 0x82B4B960, RVA: 0x00B4B960
bool idClientGame::IsPlayerControlInhibited(const int playerNum) const {
    idPresentablePlayer* const player =
        FindPlayerPresentableByIndex(playerNum);
    return player != nullptr && g_clientGameServices != nullptr &&
        g_clientGameServices->IsPlayerControlInhibited(*player);
}

// Retail symbol: ?HandleReliableGuiMsg@idClientGame@@QAAXHAAVidBitMsg@@@Z
// EA: 0x82B4B9E8, RVA: 0x00B4B9E8
void idClientGame::HandleReliableGuiMsg(const int type,
        idBitMsg& message) {
    if (g_clientGameServices == nullptr) return;
    for (int playerNum = 0; playerNum < 6; ++playerNum) {
        localView_t* const localView = GetLocalViewForPlayerIndex(playerNum);
        if (localView != nullptr) {
            g_clientGameServices->HandleReliableGuiMessage(
                *localView, type, message);
            return;
        }
    }
}

// Retail symbol: ?SendGameEventReliable_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82B4BAD8, RVA: 0x00B4BAD8
void SendGameEventReliable_f(const idCmdArgs& arguments) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->SendGameEventReliableCommand(arguments);
    }
}

// Retail symbol: ?HandlePlayerMetricsMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA: 0x82B4BB70, RVA: 0x00B4BB70
void idClientGame::HandlePlayerMetricsMsg(idBitMsg& message) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->HandlePlayerMetrics(*this, message);
    }
}

// Retail symbol: ?HandleVehiclePickupMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA: 0x82B4BC70, RVA: 0x00B4BC70
void idClientGame::HandleVehiclePickupMsg(idBitMsg& message) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->HandleVehiclePickup(*this, message);
    }
}

// Retail symbol: ?GetObjectList@idClientGame@@QAAPAPAVidClass@@XZ
// EA: 0x82B4BD98, RVA: 0x00B4BD98
idClass** idClientGame::GetObjectList() {
    return objectList.Ptr();
}

// Retail symbol: ?GetObjectListSize@idClientGame@@QAAHXZ
// EA: 0x82B4BDA8, RVA: 0x00B4BDA8
int idClientGame::GetObjectListSize() const {
    return objectList.Num();
}

// Retail symbol: ?CalcHitscanDamageScale@idClientGame@@QBAMPBVidDeclProjectile@@MPBVidPresentable@@ABVidVec3@@@Z
// EA: 0x82B4BDB8, RVA: 0x00B4BDB8
float idClientGame::CalcHitscanDamageScale(
        const idDeclProjectile* const projectile,
        const float startDamageScale, const idPresentable* const attacker,
        const idVec3& hitOrigin) const {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->CalcHitscanDamageScale(projectile,
            startDamageScale, attacker, hitOrigin) : startDamageScale;
}

// Retail symbol: ?GetRandomSpreadTraceDir@idClientGame@@QAA?AVidVec3@@ABVidFireParms@@@Z
// EA: 0x82B4BE40, RVA: 0x00B4BE40
idVec3 idClientGame::GetRandomSpreadTraceDir(
        const idFireParms& fireParameters) {
    return g_clientGameServices != nullptr
        ? g_clientGameServices->GetRandomSpreadTraceDirection(fireParameters)
        : idVec3(0.0f, 0.0f, 0.0f);
}

// Retail symbol: ?GetPlayerPresentableCmds@idClientGame@@QAAHHQAPAVusercmd_t@@H@Z
// EA: 0x82B4C130, RVA: 0x00B4C130
int idClientGame::GetPlayerPresentableCmds(const int user,
        usercmd_t** const buffer, const int bufferSize) {
    idPresentablePlayer* const player = user >= 0 && user <= 5
        ? FindPlayerPresentableByIndex(user) : nullptr;
    return player != nullptr && g_clientGameServices != nullptr
        ? g_clientGameServices->GetUserCommands(*player, buffer, bufferSize)
        : -1;
}

// Retail symbol: ?FindReplicatedSound@idClientGame@@QAAPAVidReplicatedSound@@W4soundChannel_t@@G@Z
// EA: 0x82B4C1D0, RVA: 0x00B4C1D0
idReplicatedSound* idClientGame::FindReplicatedSound(
        const soundChannel_t channel, const std::uint16_t presentableIndex) {
    const int now = g_clientGameServices != nullptr
        ? g_clientGameServices->GetMilliseconds() : 0;
    idReplicatedSound* oldest = nullptr;
    int oldestAge = 0;
    for (idReplicatedSound& sound : replicatedSounds) {
        if (sound.channel == channel &&
                sound.presentableIndex == presentableIndex) {
            sound.time = now;
            return &sound;
        }
        const int age = now - sound.time;
        if (sound.framesToForceKeep == 0 &&
                (oldest == nullptr || age > oldestAge)) {
            oldest = &sound;
            oldestAge = age;
        }
    }
    if (oldest != nullptr) {
        *oldest = idReplicatedSound();
        oldest->time = now;
        oldest->presentableIndex = presentableIndex;
    }
    return oldest;
}

namespace {
idReplicatedSound* FindSoundOverRun(idList<idReplicatedSound, 5>& sounds,
        const soundChannel_t channel, const std::uint16_t index) {
    for (int i = 0; i < sounds.Num(); ++i) {
        if (sounds[i].channel == channel &&
                sounds[i].presentableIndex == index) return &sounds[i];
    }
    return nullptr;
}

bool BeginSoundReplication(const std::uint8_t overrideMask,
        std::uint8_t& peerMask) {
    if (g_clientGameServices == nullptr ||
            !g_clientGameServices->IsHost() ||
            !g_clientGameServices->HasActivePeers()) return false;
    if (overrideMask != 0) peerMask &= overrideMask;
    return peerMask != 0;
}
} // namespace

// Retail symbol: ?ReplicateSoundVolume@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA: 0x82B4C308, RVA: 0x00B4C308
void idClientGame::ReplicateSoundVolume(const soundChannel_t channel,
        const idSoundShader* const shader, const soundShaderParms_t& parms,
        const float volume, const std::uint16_t presentableIndex,
        std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr && shader != nullptr) {
        if (sound->shader == shader && std::fabs(sound->volume - volume) <= 0.01f) return;
        sound->volume = volume;
        sound->peerMask = peerMask;
        sound->parms = parms;
        sound->shader = shader;
        ++sound->changed[1];
        return;
    }
    sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
    if (sound == nullptr) return;
    sound->time = g_clientGameServices->GetMilliseconds();
    sound->volume = volume;
    sound->peerMask = peerMask;
    ++sound->changed[1];
}

// Retail symbol: ?ReplicateSoundPitch@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA: 0x82B4C548, RVA: 0x00B4C548
void idClientGame::ReplicateSoundPitch(const soundChannel_t channel,
        const idSoundShader* const shader, const soundShaderParms_t& parms,
        const float pitch, const std::uint16_t presentableIndex,
        std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr && shader != nullptr) {
        if (sound->shader == shader && std::fabs(sound->pitch - pitch) <= 0.01f) return;
        sound->pitch = pitch;
        sound->peerMask = peerMask;
        sound->parms = parms;
        sound->shader = shader;
        ++sound->changed[2];
        return;
    }
    sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
    if (sound == nullptr) return;
    sound->time = g_clientGameServices->GetMilliseconds();
    sound->pitch = pitch;
    sound->peerMask = peerMask;
    ++sound->changed[2];
}

// Retail symbol: ?ReplicateSoundModify@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GE@Z
// EA: 0x82B4C788, RVA: 0x00B4C788
void idClientGame::ReplicateSoundModify(const soundChannel_t channel,
        const idSoundShader* const shader, const soundShaderParms_t& parms,
        const std::uint16_t presentableIndex, std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr && shader != nullptr) {
        sound->parms = parms;
        sound->shader = shader;
        sound->peerMask = peerMask;
        ++sound->changed[3];
        return;
    }
    sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
    if (sound == nullptr) return;
    sound->time = g_clientGameServices->GetMilliseconds();
    sound->parms = parms;
    sound->peerMask = peerMask;
    ++sound->changed[3];
}

// Retail symbol: ?ReplicateSoundVolumeAdjustment@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA: 0x82B4C980, RVA: 0x00B4C980
void idClientGame::ReplicateSoundVolumeAdjustment(
        const soundChannel_t channel, const idSoundShader* const shader,
        const soundShaderParms_t& parms, const float adjustment,
        const std::uint16_t presentableIndex, std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr && shader != nullptr) {
        sound->volumeAdjustment = adjustment;
        sound->peerMask = peerMask;
        sound->parms = parms;
        sound->shader = shader;
        ++sound->changed[5];
        sound->lastChanged[6] = sound->changed[6];
        return;
    }
    sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
    if (sound == nullptr) return;
    sound->time = g_clientGameServices->GetMilliseconds();
    sound->volumeAdjustment = adjustment;
    sound->peerMask = peerMask;
    ++sound->changed[5];
    sound->lastChanged[6] = sound->changed[6];
}

// Retail symbol: ?ReplicateSoundClearVolumeAdjustment@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GE@Z
// EA: 0x82B4CB58, RVA: 0x00B4CB58
void idClientGame::ReplicateSoundClearVolumeAdjustment(
        const soundChannel_t channel, const idSoundShader* const shader,
        const soundShaderParms_t& parms, const std::uint16_t presentableIndex,
        std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr && shader != nullptr) {
        sound->peerMask = peerMask;
        sound->clearVolumeAdjustment = true;
        sound->parms = parms;
        sound->shader = shader;
        ++sound->changed[6];
        sound->lastChanged[5] = sound->changed[5];
        return;
    }
    sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
    if (sound == nullptr) return;
    sound->time = g_clientGameServices->GetMilliseconds();
    sound->clearVolumeAdjustment = true;
    sound->peerMask = peerMask;
    ++sound->changed[6];
    sound->lastChanged[5] = sound->changed[5];
}

// Retail symbol: ?HandleStatusMessageForPlayer@idClientGame@@QAAXHABVidStr@@_N@Z
// EA: 0x82B4CD20, RVA: 0x00B4CD20
void idClientGame::HandleStatusMessageForPlayer(const int playerNum,
        const idStr& header, const bool isError) {
    localView_t* const view = GetLocalViewForPlayerIndex(playerNum);
    if (view != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->HandleStatusMessage(*view, header, isError);
    }
}

// Retail symbol: ?HandleStatusMessage@idClientGame@@QAAXABVidStr@@_N@Z
// EA: 0x82B4CD70, RVA: 0x00B4CD70
void idClientGame::HandleStatusMessage(const idStr& header,
        const bool isError) {
    for (int playerNum = 0; playerNum < 6; ++playerNum) {
        HandleStatusMessageForPlayer(playerNum, header, isError);
    }
}

// Retail symbol: ?HandleStatusOrSystemMessage@idClientGame@@QAAXHABVidStr@@0_N@Z
// EA: 0x82B4CE60, RVA: 0x00B4CE60
void idClientGame::HandleStatusOrSystemMessage(const int playerNum,
        const idStr& personalText, const idStr& systemText,
        const bool isError) {
    if (g_clientGameServices == nullptr) return;
    for (int localPlayer = 0; localPlayer < 6; ++localPlayer) {
        localView_t* const view = GetLocalViewForPlayerIndex(localPlayer);
        if (view == nullptr) continue;
        if (g_clientGameServices->GetLocalViewPlayerNum(*view) == playerNum) {
            g_clientGameServices->HandleStatusMessage(
                *view, personalText, isError);
        } else {
            const idStr message = g_clientGameServices->FormatPlayerSystemMessage(
                lobbyUserIDs[playerNum], systemText);
            g_clientGameServices->HandleSystemMessage(*view, message);
        }
    }
}

// Retail symbol: ?HandleSystemMessage@idClientGame@@QAAXABVidStr@@@Z
// EA: 0x82B4CFA0, RVA: 0x00B4CFA0
void idClientGame::HandleSystemMessage(const idStr& message) {
    if (g_clientGameServices == nullptr) return;
    for (int playerNum = 0; playerNum < 6; ++playerNum) {
        localView_t* const view = GetLocalViewForPlayerIndex(playerNum);
        if (view != nullptr) {
            g_clientGameServices->HandleSystemMessage(*view, message);
        }
    }
}

// Retail symbol: ?HandlePointsMessageForPlayer@idClientGame@@QAAXHH@Z
// EA: 0x82B4D080, RVA: 0x00B4D080
void idClientGame::HandlePointsMessageForPlayer(const int playerNum,
        const int points) {
    localView_t* const view = GetLocalViewForPlayerIndex(playerNum);
    if (view != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->HandlePointsMessage(*view, points);
    }
}

// Retail symbol: ?HandleMeteorPointsMessageForPlayer@idClientGame@@QAAXHHH@Z
// EA: 0x82B4D090, RVA: 0x00B4D090
void idClientGame::HandleMeteorPointsMessageForPlayer(const int playerNum,
        const int points, const int numMeteors) {
    localView_t* const view = GetLocalViewForPlayerIndex(playerNum);
    if (view != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->HandleMeteorPointsMessage(
            *view, points, numMeteors, std::abs(points) == 1);
    }
}

// Retail symbol: ?HandleShowTutorialForPlayer@idClientGame@@QAAXHH@Z
// EA: 0x82B4D158, RVA: 0x00B4D158
void idClientGame::HandleShowTutorialForPlayer(const int playerNum,
        const int tutorialDeclNetID) {
    if (!PlayerIndexIsLocal(playerNum) ||
            g_clientGameServices == nullptr) return;
    idPresentablePlayer* const player = FindPlayerPresentableByIndex(playerNum);
    if (player == nullptr) return;
    const idDeclTutorialEvent* const declaration = tutorialDeclNetID == 0
        ? nullptr : g_clientGameServices->ResolveTutorialDecl(
            tutorialDeclNetID - 1);
    g_clientGameServices->ShowTutorial(*player, declaration);
}

// Retail symbol: ?GetLocalPresentablePlayer@idClientGame@@QAAPAVidPresentablePlayer@@XZ
// EA: 0x82B4D258, RVA: 0x00B4D258
idPresentablePlayer* idClientGame::GetLocalPresentablePlayer() {
    for (int playerNum = 0; playerNum < 6; ++playerNum) {
        if (!PlayerIndexIsLocal(playerNum)) continue;
        idPresentablePlayer* const player =
            FindPlayerPresentableByIndex(playerNum);
        if (player != nullptr) return player;
    }
    return nullptr;
}

// Retail symbol: ?PlaySoundForAllPeers@idClientGame@@QAAXPAVidEntity@@W4soundChannel_t@@PBVidSoundShader@@H@Z
// EA: 0x82B4D300, RVA: 0x00B4D300
void idClientGame::PlaySoundForAllPeers(idEntity* const entity,
        const soundChannel_t channel, const idSoundShader* const shader,
        const int soundShaderFlags) {
    if (entity == nullptr || shader == nullptr ||
            g_clientGameServices == nullptr) return;
    const std::uint8_t savedMask = overrideSoundPeerMask;
    overrideSoundPeerMask = 0;
    g_clientGameServices->StartSoundShader(
        *entity, channel, *shader, soundShaderFlags, 0xFF);
    overrideSoundPeerMask = savedMask;
}

// Retail symbol: ?GetPresentableByEntityNum@idClientGame@@QAAPAVidPresentable@@H@Z
// EA: 0x82B4D370, RVA: 0x00B4D370
idPresentable* idClientGame::GetPresentableByEntityNum(const int entityNum) {
    if (entityNum < 0 || entityNum >= 0x2000 || entityNum == 0x1FFF) {
        return nullptr;
    }
    const int index = entityToPresentableLUT[entityNum];
    return IsPresentableIndexValid(index) ? presentables[index] : nullptr;
}

// Retail symbol: ?GetPlayerGameTime@idClientGame@@QBAHXZ
// EA: 0x82B4D3E0, RVA: 0x00B4D3E0
int idClientGame::GetPlayerGameTime() const {
    if (g_clientGameServices == nullptr) return playerTime;
    return !g_clientGameServices->IsMultiplayer() || playerTime < 0
        ? g_clientGameServices->GetScaledGameTime() : playerTime;
}

// Retail symbol: ?GetPreviousPlayerGameTime@idClientGame@@QBAHXZ
// EA: 0x82B4D450, RVA: 0x00B4D450
int idClientGame::GetPreviousPlayerGameTime() const {
    return GetPlayerGameTime() - (g_clientGameServices != nullptr
        ? g_clientGameServices->GetScaledMillisecondsPerFrame() : 0);
}

// Retail symbol: ?ConstructPeerMaskForPlayer@idClientGame@@QBAEH@Z
// EA: 0x82B4D4A0, RVA: 0x00B4D4A0
std::uint8_t idClientGame::ConstructPeerMaskForPlayer(
        const int playerNum) const {
    if (g_clientGameServices == nullptr) return 0;
    const int peerIndex = g_clientGameServices->PeerIndexForLobbyUser(
        lobbyUserIDs[playerNum]);
    return peerIndex < 0 || peerIndex >= 8
        ? 0 : static_cast<std::uint8_t>(1u << peerIndex);
}

// Retail symbol: ?FindPredictedPresentable@idClientGame@@QAAPAVidPresentable@@IW4presentableType_t@@@Z
// EA: 0x82B4D530, RVA: 0x00B4D530
idPresentable* idClientGame::FindPredictedPresentable(
        const unsigned predictedKey, const presentableType_t presentableType) {
    if (g_clientGameServices == nullptr) return nullptr;
    for (int i = 0; i < activePresentables.Num(); ++i) {
        idPresentable* const presentable = activePresentables[i];
        if (presentable == nullptr ||
                g_clientGameServices->GetPresentableIndex(*presentable) < 0x2000 ||
                g_clientGameServices->GetPresentablePredictedKey(*presentable) != predictedKey) {
            continue;
        }
        const presentableType_t actual =
            g_clientGameServices->GetPresentableType(*presentable);
        if (actual != presentableType) {
            g_clientGameServices->ReportPredictedTypeMismatch(
                actual, presentableType);
        }
        return presentable;
    }
    return nullptr;
}

// Retail symbol: ?GeneratePredictionKey@idClientGame@@QAAIPAVidWeapon@@PAVidPresentablePlayer@@H@Z
// EA: 0x82B4D610, RVA: 0x00B4D610
unsigned idClientGame::GeneratePredictionKey(idWeapon* const weapon,
        idPresentablePlayer* const playerAttacker, const int overrideKey) {
    if (g_clientGameServices == nullptr) return 0;
    const unsigned handle = overrideKey == -1
        ? g_clientGameServices->GetNextPredictionHandle(weapon, playerAttacker)
        : static_cast<unsigned>(overrideKey);
    const int peerIndex = g_clientGameServices->IsServer()
        ? g_clientGameServices->PeerIndexForLobbyUser(
            playerAttacker != nullptr
                ? g_clientGameServices->GetPlayerLobbyUserID(*playerAttacker)
                : lobbyUserID_t())
        : g_clientGameServices->GetHostPeerIndex();
    return (static_cast<unsigned>(peerIndex) << 28) | (handle & 0x0FFFFFFFu);
}

// Retail symbol: ?GetTracePresentable@idClientGame@@QAAPAVidPresentable@@ABUtrace_t@@@Z
// EA: 0x82B4D798, RVA: 0x00B4D798
idPresentable* idClientGame::GetTracePresentable(const trace_t& trace) {
    if (g_clientGameServices == nullptr) return nullptr;
    if (!g_clientGameServices->IsServer()) {
        return GetPresentableByEntityNum(
            g_clientGameServices->GetTraceEntityNum(trace));
    }
    idEntity* const entity = g_clientGameServices->GetServerTraceEntity(trace);
    if (entity == nullptr) return nullptr;
    idPresentable* const presentable =
        g_clientGameServices->GetEntityPresentable(*entity);
    return presentable != nullptr ? presentable
        : g_clientGameServices->InitializeEntityPresentable(*entity);
}

// Retail symbol: ?ClientDisablePresentablePushers@idClientGame@@QAAX_N@Z
// EA: 0x82B4D8E8, RVA: 0x00B4D8E8
void idClientGame::ClientDisablePresentablePushers(const bool disable) {
    if (g_clientGameServices == nullptr) return;
    for (int i = 0; i < pusherPresentables.Num(); ++i) {
        idPresentable* const presentable = pusherPresentables[i];
        if (presentable == nullptr) continue;
        idPresentablePusher* const pusher =
            g_clientGameServices->GetPusherInterface(*presentable);
        if (pusher != nullptr) {
            g_clientGameServices->DisablePusherClip(*pusher, disable);
        }
    }
}

// Retail symbol: ?GetVehiclePresentable@idClientGame@@QAAPAVidPresentableVehicle@@H@Z
// EA: 0x82B4D988, RVA: 0x00B4D988
idPresentableVehicle* idClientGame::GetVehiclePresentable(const int index) {
    if (index < 0 || index >= vehiclePresentables.Num() ||
            vehiclePresentables[index] == nullptr ||
            g_clientGameServices == nullptr) return nullptr;
    return g_clientGameServices->GetVehicleInterface(
        *vehiclePresentables[index]);
}

// Retail symbol: ?GenerateInputToPlayerIndexRouting@idClientGame@@QAAHXZ
// EA: 0x82B4D9C8, RVA: 0x00B4D9C8
int idClientGame::GenerateInputToPlayerIndexRouting() {
    for (int& route : inputToPlayerIndexRouting) route = -1;
    if (g_clientGameServices == nullptr) return 0;
    if (g_clientGameServices->SkipInputRouting()) {
        inputToPlayerIndexRouting[0] = 0;
        return 1;
    }
    int inputOrdinals[4];
    g_clientGameServices->GetInputRouting(inputOrdinals);
    int routed = 0;
    for (int input = 0; input < 4; ++input) {
        if (inputOrdinals[input] == -1) continue;
        const lobbyUserID_t user =
            g_clientGameServices->GetLobbyUserIdByOrdinal(inputOrdinals[input]);
        for (int playerNum = 0; playerNum < 6; ++playerNum) {
            if (lobbyUserIDs[playerNum] == user) {
                inputToPlayerIndexRouting[input] = playerNum;
                ++routed;
                break;
            }
        }
    }
    return routed;
}

// Retail symbol: ?GetPlayerIndexFromInputDevice@idClientGame@@QBAHH@Z
// EA: 0x82B4DB08, RVA: 0x00B4DB08
int idClientGame::GetPlayerIndexFromInputDevice(const int inputDevice) const {
    return inputToPlayerIndexRouting[inputDevice];
}

// Retail symbol: ?ClearViewCallbacks@idClientGame@@QAAXXZ
// EA: 0x82B4E078, RVA: 0x00B4E078
void idClientGame::ClearViewCallbacks() {
    activeViewCallbacks.Clear();
}

// Retail symbol: ?DeleteAllPresentables@idClientGame@@QAAXXZ
// EA: 0x82B4E088, RVA: 0x00B4E088
void idClientGame::DeleteAllPresentables() {
    for (int i = 0; i < presentables.Num(); ++i) {
        idPresentable* const presentable = presentables[i];
        if (presentable == nullptr) continue;
        if (g_clientGameServices != nullptr) {
            g_clientGameServices->RemovePresentableFromEntityLUT(*presentable);
            g_clientGameServices->DestroyPresentable(*presentable);
        }
        presentables[i] = nullptr;
    }
    presentables.ClearFree();
    activePresentables.ClearFree();
    pusherPresentables.ClearFree();
    vehiclePresentables.ClearFree();
    serializedPresentables.ClearFree();
    for (int& entry : entityToPresentableLUT) entry = -1;
}

// Retail symbol: ?RenderLocalViewForGame@idClientGame@@QAAPAVidRenderModelGui@@HPAVidRenderWorld@@@Z
// EA: 0x82B4E270, RVA: 0x00B4E270
idRenderModelGui* idClientGame::RenderLocalViewForGame(const int time,
        idRenderWorld* const renderWorld) {
    if (g_clientGameServices != nullptr) {
        guiModel = g_clientGameServices->RenderGameView(
            guiModel, time, renderWorld, GetLocalPresentablePlayer());
    }
    return guiModel;
}

// Retail symbol: ?HandleKillMessage@idClientGame@@QAAXHHPBVidDeclDamage@@_NH@Z
// EA: 0x82B4E498, RVA: 0x00B4E498
void idClientGame::HandleKillMessage(const int victimIndex,
        const int attackerIndex, const idDeclDamage* const damageDef,
        const bool isTeamKill, const int points) {
    localView_t* const view = GetLocalViewForPlayerIndex(attackerIndex);
    if (view != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->HandleKillMessage(*view,
            lobbyUserIDs[victimIndex], attackerIndex, damageDef,
            isTeamKill, points);
    }
}

// Retail symbol: ?HandleDeathMessage@idClientGame@@QAAXHHPBVidDeclDamage@@_N1@Z
// EA: 0x82B4E620, RVA: 0x00B4E620
void idClientGame::HandleDeathMessage(const int victimIndex,
        const int attackerIndex, const idDeclDamage* const damageDef,
        const bool isTeamKill, const bool isSuicide) {
    localView_t* const view = GetLocalViewForPlayerIndex(victimIndex);
    if (view != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->HandleDeathMessage(*view,
            lobbyUserIDs[victimIndex], attackerIndex, damageDef,
            isTeamKill, isSuicide);
    }
}

// Retail symbol: ?HandlePersonalOrSystemMessage@idClientGame@@QAAXHABVidStr@@PBUsoundShaderParms_t@@PBVidDeclVoiceOver@@@Z
// EA: 0x82B4E8B0, RVA: 0x00B4E8B0
void idClientGame::HandlePersonalOrSystemMessage(const int playerNum,
        const idStr& text, const soundShaderParms_t* const parms,
        const idDeclVoiceOver* const voiceOver) {
    if (g_clientGameServices == nullptr ||
            !g_clientGameServices->IsCompetitiveMultiplayer()) return;
    for (int localPlayer = 0; localPlayer < 6; ++localPlayer) {
        localView_t* const view = GetLocalViewForPlayerIndex(localPlayer);
        if (view == nullptr) continue;
        if (g_clientGameServices->GetLocalViewPlayerNum(*view) == playerNum) {
            g_clientGameServices->HandleStatusMessage(*view, text, false);
            idPresentablePlayer* const player = GetLocalPresentablePlayer();
            if (voiceOver != nullptr && player != nullptr) {
                g_clientGameServices->PlayPersonalVoiceOver(
                    *player, text, parms, voiceOver);
            }
        } else {
            const idStr message = g_clientGameServices->FormatPlayerSystemMessage(
                lobbyUserIDs[playerNum], text);
            g_clientGameServices->HandleSystemMessage(*view, message);
        }
    }
}

namespace {
void DisplayMessageEntry(const bool team) {
    if (g_clientGameServices == nullptr) return;
    idClientGame* const game = g_clientGameServices->GetClientGame();
    if (game == nullptr) return;
    const int device = g_clientGameServices->GetMasterLocalUserInputDevice();
    const int playerNum = game->GetPlayerIndexFromInputDevice(device);
    localView_t* const view = game->GetLocalViewForPlayerIndex(playerNum);
    if (view != nullptr) {
        g_clientGameServices->DisplayTextChatEntry(*view, team);
    }
}
} // namespace

// Retail symbol: ?messagemode_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82B4EA58, RVA: 0x00B4EA58
void messagemode_f(const idCmdArgs&) { DisplayMessageEntry(false); }

// Retail symbol: ?messagemode2_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82B4EAC8, RVA: 0x00B4EAC8
void messagemode2_f(const idCmdArgs&) { DisplayMessageEntry(true); }

// Retail symbol: ?SendChatText@idClientGame@@QAAXAAVidStr@@W4messageMode_t@@@Z
// EA: 0x82B4EB38, RVA: 0x00B4EB38
void idClientGame::SendChatText(idStr& text,
        const messageMode_t messageMode) {
    text.TrimWhitespaceRecovered();
    text.CapLength(256);
    if (text.IsEmpty() || g_clientGameServices == nullptr) return;
    idPresentablePlayer* const player = GetLocalPresentablePlayer();
    const lobbyUserID_t user = player != nullptr
        ? g_clientGameServices->GetPlayerLobbyUserID(*player)
        : lobbyUserID_t();
    if (user.IsValid()) {
        g_clientGameServices->SendChatTextMessage(user, text, messageMode);
    }
}

// Retail symbol: ?HandleTextChat@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA: 0x82B4EDE8, RVA: 0x00B4EDE8
void idClientGame::HandleTextChat(idBitMsg& message) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->HandleTextChatMessage(*this, message);
    }
}

// Retail symbol: ?RemoveSimulatingEffectPhysics@idClientGame@@QAAXPAVidEffectPhysicsBroadPhase@@@Z
// EA: 0x82B4F118, RVA: 0x00B4F118
void idClientGame::RemoveSimulatingEffectPhysics(
        idEffectPhysicsBroadPhase* const broadPhase) {
    simulatingEffectPhysics.Remove(broadPhase);
}

// Retail symbol: ?ShowThinks@idClientGame@@QAAXXZ
// EA: 0x82B4F498, RVA: 0x00B4F498
void idClientGame::ShowThinks() {
    const int mode = g_clientGameServices != nullptr
        ? g_clientGameServices->GetShowThinksMode() : 0;
    if (mode == 0) {
        presentableThinks.Clear();
        return;
    }
    float totalMs = 0.0f;
    int totalThinks = 0;
    int totalDormant = 0;
    idStr overlay;
    for (int i = 0; i < presentableThinks.Num(); ++i) {
        presentableThink_t& think = presentableThinks[i];
        if (mode == 2) {
            think.ms = think.lastms;
            think.numThinks = think.lastNumThinks;
            think.numDormantThinks = think.lastNumDormantThinks;
        } else {
            think.avgms += (think.ms - think.avgms) * 0.1f;
        }
        totalMs += think.ms;
        totalThinks += think.numThinks;
        totalDormant += think.numDormantThinks;
        char line[256];
        std::snprintf(line, sizeof(line),
            "%s%5.02f / %5.02f ms (%3ix / %3ix) %s\n",
            think.ms > 1.0f ? "^1" : "^2", think.ms, think.maxms,
            think.numThinks - think.numDormantThinks, think.numDormantThinks,
            think.name != nullptr ? think.name : "<unnamed>");
        overlay.Append(line);
        if (mode == 1) {
            think.lastms = think.ms;
            think.lastNumThinks = think.numThinks;
            think.lastNumDormantThinks = think.numDormantThinks;
            think.ms = 0.0f;
            think.numThinks = 0;
            think.numDormantThinks = 0;
        }
    }
    overlay.Append("^2--------------------------------\n");
    char total[160];
    std::snprintf(total, sizeof(total),
        "^2Total: %5.02f (%3ix / %3ix)\n", totalMs,
        totalThinks - totalDormant, totalDormant);
    overlay.Append(total);
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->PrintThinkOverlay(overlay);
    }
}

// Retail symbol: ?ShowPresentableInfo@idClientGame@@QAAXXZ
// EA: 0x82B4F7D0, RVA: 0x00B4F7D0
void idClientGame::ShowPresentableInfo() {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->ShowPresentableInfo(*this);
    }
}

// Retail symbol: ?HandleReliableOnlineGameEvent@idClientGame@@QAAXHAAVidBitMsg@@@Z
// EA: 0x82B4FA48, RVA: 0x00B4FA48
void idClientGame::HandleReliableOnlineGameEvent(const int type,
        idBitMsg& message) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->HandleReliableOnlineGameEvent(
            *this, type, message);
    }
}

// Retail symbol: ?HandleXpGainMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA: 0x82B51318, RVA: 0x00B51318
void idClientGame::HandleXpGainMsg(idBitMsg& message) {
    if (g_clientGameServices != nullptr &&
            g_clientGameServices->IsMultiplayer()) {
        g_clientGameServices->HandleXpGain(*this, message);
    }
}

// Retail symbol: ?ReplicateStopSound@idClientGame@@QAAXW4soundChannel_t@@GE@Z
// EA: 0x82B51560, RVA: 0x00B51560
void idClientGame::ReplicateStopSound(const soundChannel_t channel,
        const std::uint16_t presentableIndex, std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask)) return;
    idReplicatedSound* const sound =
        FindReplicatedSound(channel, presentableIndex);
    if (sound != nullptr) {
        sound->channel = channel;
        sound->shader = nullptr;
        sound->presentableIndex = presentableIndex;
        sound->peerMask = peerMask;
        ++sound->changed[0];
        return;
    }
    for (int i = 0; i < startSoundOverRun.Num(); ++i) {
        if (startSoundOverRun[i].channel == channel &&
                startSoundOverRun[i].presentableIndex == presentableIndex) {
            startSoundOverRun.RemoveIndex(i);
            return;
        }
    }
}

// Retail symbol: ?FindFreePresentableIndex@idClientGame@@QAAHHH@Z
// EA: 0x82B52978, RVA: 0x00B52978
int idClientGame::FindFreePresentableIndex(int index,
        const int freeListType) {
    const int limit = freeListType == 1 ? 0x3000 : 0x2000;
    const int list = freeListType >= 0 && freeListType < 3
        ? freeListType : 0;
    if (index == -1) {
        const int searchEnd = (std::min)(presentables.Num(), limit);
        while (firstFreePresentable[list] < searchEnd &&
                presentables[firstFreePresentable[list]] != nullptr) {
            ++firstFreePresentable[list];
        }
        index = firstFreePresentable[list]++;
    }
    if (index < 0 || index >= limit) return -1;
    if (index >= presentables.Num()) {
        const int oldNum = presentables.Num();
        if (!presentables.SetNum(index + 1)) return -1;
        for (int i = oldNum; i <= index; ++i) presentables[i] = nullptr;
    }
    return index;
}

// Retail symbol: ?GetLocalViewCallbacks@idClientGame@@QAAABV?$idList@PAVidViewCallbacks@@$04@@XZ
// EA: 0x82B52A70, RVA: 0x00B52A70
const idList<idViewCallbacks*, 5>& idClientGame::GetLocalViewCallbacks() {
    if (activeViewCallbacks.Num() > 0 || g_clientGameServices == nullptr) {
        return activeViewCallbacks;
    }
    for (int input = 0; input < 4; ++input) {
        const int playerNum = inputToPlayerIndexRouting[input];
        idPresentablePlayer* const player =
            FindPlayerPresentableByIndex(playerNum);
        if (player == nullptr) continue;
        idViewCallbacks* const callbacks =
            g_clientGameServices->GetViewCallbacks(*player);
        if (callbacks != nullptr) activeViewCallbacks.Append(callbacks);
    }
    return activeViewCallbacks;
}

// Retail symbol: ?ReadFromSnapshot@idClientGame@@QAAXAAVidSnapShot@@PBV2@@Z
// EA: 0x82B52B38, RVA: 0x00B52B38
void idClientGame::ReadFromSnapshot(idSnapShot& snapshot,
        const idSnapShot* const oldSnapshot) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->ReadClientSnapshot(
            *this, snapshot, oldSnapshot);
    }
    serialized = true;
}

// Retail symbol: ?GetChallengeMode@idClientGame@@QBA?AW4challengeGameMode_t@@XZ
// EA: 0x82B53148, RVA: 0x00B53148
challengeGameMode_t idClientGame::GetChallengeMode() const {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->IsServer()
        ? g_clientGameServices->GetServerChallengeMode()
        : serializedChallengeMode;
}

// Retail symbol: ?MarkPresentableSerialized@idClientGame@@QAAXPAVidPresentable@@_N1@Z
// EA: 0x82B531C0, RVA: 0x00B531C0
void idClientGame::MarkPresentableSerialized(idPresentable* const presentable,
        const bool isSerialized, const bool deleted) {
    if (presentable == nullptr || g_clientGameServices == nullptr ||
            !g_clientGameServices->IsServer() ||
            !g_clientGameServices->IsMultiplayer()) return;
    const int index = g_clientGameServices->GetPresentableIndex(*presentable);
    if (index < 0 || index >= 0x2000) return;
    if (isSerialized) {
        g_clientGameServices->SetPresentableStopSerializeCount(*presentable, 0);
        if (g_clientGameServices->GetPresentableSerializedIndex(
                *presentable) == -1) {
            const int serializedIndex = serializedPresentables.Append(presentable);
            g_clientGameServices->SetPresentableSerializedIndex(
                *presentable, serializedIndex);
        }
        g_clientGameServices->RefreshPresentableSnapshotObject(index + 19);
        return;
    }
    const int serializedIndex =
        g_clientGameServices->GetPresentableSerializedIndex(*presentable);
    if (serializedIndex >= 0 &&
            serializedIndex < serializedPresentables.Num()) {
        const int lastIndex = serializedPresentables.Num() - 1;
        if (serializedIndex != lastIndex) {
            serializedPresentables[serializedIndex] =
                serializedPresentables[lastIndex];
            if (serializedPresentables[serializedIndex] != nullptr) {
                g_clientGameServices->SetPresentableSerializedIndex(
                    *serializedPresentables[serializedIndex], serializedIndex);
            }
        }
        serializedPresentables.SetNum(lastIndex);
        g_clientGameServices->SetPresentableSerializedIndex(*presentable, -1);
    }
    if (deleted) {
        g_clientGameServices->MarkPresentableSnapshotObjectDeleted(index + 19);
    }
}

// Retail symbol: ?MarkAllPresentablesAsSerialized@idClientGame@@QAAX_N@Z
// EA: 0x82B53368, RVA: 0x00B53368
void idClientGame::MarkAllPresentablesAsSerialized(const bool skyOnly) {
    if (g_clientGameServices == nullptr) return;
    for (int i = 0; i < activePresentables.Num(); ++i) {
        idPresentable* const presentable = activePresentables[i];
        if (presentable == nullptr ||
                g_clientGameServices->GetPresentableIndex(*presentable) >= 0x2000 ||
                (skyOnly && !g_clientGameServices->IsSkyPresentable(*presentable))) {
            continue;
        }
        MarkPresentableSerialized(presentable, true, false);
    }
}

// Retail symbol: ??0idClientGame@@QAA@XZ
// EA: 0x82B534E8, RVA: 0x00B534E8
// Construction is implemented by idClientGame::idClientGame above; C++ RAII
// initializes every owned list, sound record, routing slot, LUT and runtime seam.

// Retail symbol: ?AddPresentable@idClientGame@@QAAXPAVidPresentable@@HH@Z
// EA: 0x82B540A8, RVA: 0x00B540A8
void idClientGame::AddPresentable(idPresentable* const presentable,
        const int requestedIndex, const int freeListType) {
    if (presentable == nullptr || g_clientGameServices == nullptr) return;
    const int index = FindFreePresentableIndex(requestedIndex, freeListType);
    if (index < 0) return;
    presentables[index] = presentable;
    const int activeIndex = activePresentables.Append(presentable);
    const unsigned spawnId = (presentableSpawnId++ << 14) |
        static_cast<unsigned>(index);
    g_clientGameServices->SetPresentableRegistration(
        *presentable, index, activeIndex, spawnId);
    g_clientGameServices->AddPresentableToEntityLUT(*presentable);
    if (g_clientGameServices->GetPusherInterface(*presentable) != nullptr) {
        pusherPresentables.Append(presentable);
    } else if (g_clientGameServices->GetVehicleInterface(*presentable) != nullptr) {
        vehiclePresentables.Append(presentable);
    }
    MarkPresentableSerialized(presentable, true, false);
}

// Retail symbol: ?RemovePresentable@idClientGame@@QAAXPAVidPresentable@@@Z
// EA: 0x82B54198, RVA: 0x00B54198
void idClientGame::RemovePresentable(idPresentable* const presentable) {
    if (presentable == nullptr || g_clientGameServices == nullptr) return;
    g_clientGameServices->RemovePresentableFromEntityLUT(*presentable);
    MarkPresentableSerialized(presentable, false, true);
    const int index = g_clientGameServices->GetPresentableIndex(*presentable);
    if (index >= 0 && index < presentables.Num()) presentables[index] = nullptr;
    const int activeIndex =
        g_clientGameServices->GetPresentableActiveIndex(*presentable);
    if (activeIndex >= 0 && activeIndex < activePresentables.Num()) {
        const int lastIndex = activePresentables.Num() - 1;
        if (activeIndex != lastIndex) {
            activePresentables[activeIndex] = activePresentables[lastIndex];
            if (activePresentables[activeIndex] != nullptr) {
                g_clientGameServices->SetPresentableActiveIndex(
                    *activePresentables[activeIndex], activeIndex);
            }
        }
        activePresentables.SetNum(lastIndex);
    }
    if (index >= 6) {
        const int freeListType = index < 0x2000 ? 0 :
            (index < 0x3000 ? 1 : 2);
        firstFreePresentable[freeListType] =
            (std::min)(firstFreePresentable[freeListType], index);
    }
    pusherPresentables.Remove(presentable);
    vehiclePresentables.Remove(presentable);
}

// Retail symbol: ?MakePresentableNonReplicated@idClientGame@@QAAXPAVidPresentable@@@Z
// EA: 0x82B54328, RVA: 0x00B54328
void idClientGame::MakePresentableNonReplicated(
        idPresentable* const presentable) {
    RemovePresentable(presentable);
    AddPresentable(presentable, -1, 1);
}

// Retail symbol: ?AddThink@idClientGame@@QAAXPBD_NM@Z
// EA: 0x82B54378, RVA: 0x00B54378
void idClientGame::AddThink(const char* const name, const bool isDormant,
        const float milliseconds) {
    presentableThink_t* think = nullptr;
    for (int i = 0; i < presentableThinks.Num(); ++i) {
        if (presentableThinks[i].name != nullptr && name != nullptr &&
                _stricmp(presentableThinks[i].name, name) == 0) {
            think = &presentableThinks[i];
            break;
        }
    }
    if (think == nullptr) {
        presentableThink_t value;
        value.name = name;
        value.ms = milliseconds;
        value.maxms = milliseconds;
        value.avgms = milliseconds;
        value.numThinks = 1;
        value.numDormantThinks = isDormant ? 1 : 0;
        value.maxThinks = 1;
        presentableThinks.Append(value);
        return;
    }
    think->ms += milliseconds;
    ++think->numThinks;
    if (isDormant) ++think->numDormantThinks;
    think->maxms = (std::max)(think->maxms, think->ms);
    think->maxThinks = (std::max)(think->maxThinks, think->numThinks);
}

// Retail symbol: ?AddSimulatingEffectPhysics@idClientGame@@QAAXPAVidEffectPhysicsBroadPhase@@@Z
// EA: 0x82B544F8, RVA: 0x00B544F8
void idClientGame::AddSimulatingEffectPhysics(
        idEffectPhysicsBroadPhase* const broadPhase) {
    if (simulatingEffectPhysics.FindIndex(broadPhase) == -1) {
        simulatingEffectPhysics.Append(broadPhase);
    }
}

// Retail symbol: ?AddPresentable@idClientGame@@QAAXPAVidPresentable@@H_N@Z
// EA: 0x82B546E8, RVA: 0x00B546E8
void idClientGame::AddPresentable(idPresentable* const presentable,
        const int index, const bool skipReplication) {
    AddPresentable(presentable, index, skipReplication ? 1 : 0);
}

// Retail symbol: ?WriteToSnapshot@idClientGame@@QBAXAAVidSnapShot@@PBV2@@Z
// EA: 0x82B54700, RVA: 0x00B54700
void idClientGame::WriteToSnapshot(idSnapShot& snapshot,
        const idSnapShot* const oldSnapshot) const {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->WriteClientSnapshot(
            *this, snapshot, oldSnapshot);
    }
}

// Retail symbol: ?TestLaunchProjectile@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA: 0x82B54B50, RVA: 0x00B54B50
bool idClientGame::TestLaunchProjectile(const idFireParms& fireParameters,
        idTestFireResults& testResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->TestLaunchProjectile(
            *this, fireParameters, testResults);
}

// Retail symbol: ?FinishLaunchProjectile@idClientGame@@QAA_NABVidFireParms@@ABVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA: 0x82B54D08, RVA: 0x00B54D08
bool idClientGame::FinishLaunchProjectile(
        const idFireParms& fireParameters,
        const idTestFireResults& testResults,
        idFinishFireResults& finishResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->FinishLaunchProjectile(
            *this, fireParameters, testResults, finishResults);
}

// Retail symbol: ?TestHitScan@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA: 0x82B55300, RVA: 0x00B55300
bool idClientGame::TestHitScan(const idFireParms& fireParameters,
        idTestFireResults& testResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->TestHitScan(*this, fireParameters, testResults);
}

// Retail symbol: ?ReplicatePlaySound@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GABVidVec3@@E@Z
// EA: 0x82B55DB0, RVA: 0x00B55DB0
void idClientGame::ReplicatePlaySound(const soundChannel_t channel,
        const idSoundShader* const shader, const soundShaderParms_t& parms,
        const std::uint16_t presentableIndex, const idVec3& position,
        std::uint8_t peerMask) {
    if (!BeginSoundReplication(overrideSoundPeerMask, peerMask) ||
            (shader != nullptr &&
             (shader->parms.soundShaderFlags & SSF_PRIVATE_SOUND) != 0)) {
        return;
    }
    idReplicatedSound* sound = FindReplicatedSound(channel, presentableIndex);
    if (sound == nullptr) {
        sound = FindSoundOverRun(startSoundOverRun, channel, presentableIndex);
        if (sound == nullptr) {
            if (startSoundOverRun.Num() >= 512) return;
            const int index = startSoundOverRun.Append(idReplicatedSound());
            if (index < 0) return;
            sound = &startSoundOverRun[index];
        }
    }
    sound->position = position;
    sound->channel = channel;
    sound->shader = shader;
    sound->internalFlags = g_clientGameServices != nullptr &&
        g_clientGameServices->IsGlobalSoundPosition(position) ? 1 : 0;
    sound->presentableIndex = presentableIndex;
    sound->peerMask = peerMask;
    sound->volume = 0.0f;
    sound->parms = parms;
    sound->framesToForceKeep = 2;
    ++sound->changed[0];
}

// Retail symbol: ?PlayShaderDirectly@idClientGame@@QAAXPBVidSoundShader@@W4soundChannel_t@@ABVidVec3@@ABVidMat3@@E@Z
// EA: 0x82B56210, RVA: 0x00B56210
void idClientGame::PlayShaderDirectly(const idSoundShader* const shader,
        const soundChannel_t channel, const idVec3& position,
        const idMat3& axis, const std::uint8_t peerMask) {
    if (shader == nullptr || g_clientGameServices == nullptr) return;
    const bool global = g_clientGameServices->IsGlobalSoundPosition(position);
    g_clientGameServices->PlayShaderDirectly(
        *shader, channel, position, axis, global);
    if (peerMask != 0) {
        soundShaderParms_t parms{};
        parms.soundShaderFlags = static_cast<soundShaderFlags_t>(0);
        ReplicatePlaySound(channel, shader, parms, 0xFFFF,
            position, peerMask);
    }
}

// Retail symbol: ?TestFire@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA: 0x82B56300, RVA: 0x00B56300
bool idClientGame::TestFire(const idFireParms& fireParameters,
        idTestFireResults& testResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->IsHitscanFire(fireParameters)
        ? TestHitScan(fireParameters, testResults)
        : TestLaunchProjectile(fireParameters, testResults);
}

// Retail symbol: ?ImpactEffect@idClientGame@@QAAXABVidVec3@@0ABVidColor@@PBUprojectileImpactEffect_t@idDeclProjectileImpactEffect@@_N33PBVidPresentable@@PAV6@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA: 0x82B56320, RVA: 0x00B56320
void idClientGame::ImpactEffect(const idVec3& point, const idVec3& normal,
        const idColor& color, const void* const impactEffect,
        const bool skipParticle, const bool noDecals, const bool noSounds,
        const idPresentable* const owner, idPresentable* const entity,
        const int jointId) {
    if (impactEffect != nullptr && g_clientGameServices != nullptr) {
        g_clientGameServices->CreateImpactEffect(*this, point, normal,
            color, impactEffect, skipParticle, noDecals, noSounds,
            owner, entity, jointId);
    }
}

// Retail symbol: ?ProjectileImpact@idClientGame@@QAAXABUtrace_t@@PBVidPresentable@@PBVidDeclProjectile@@_N33@Z
// EA: 0x82B56908, RVA: 0x00B56908
void idClientGame::ProjectileImpact(const trace_t& trace,
        const idPresentable* const attacker,
        const idDeclProjectile* const projectile, const bool noDamage,
        const bool noDecals, const bool noSounds) {
    if (g_clientGameServices != nullptr) {
        g_clientGameServices->HandleProjectileImpact(*this, trace,
            attacker, projectile, noDamage, noDecals, noSounds);
    }
}

// Retail symbol: ?FinishHitScan@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA: 0x82B57038, RVA: 0x00B57038
bool idClientGame::FinishHitScan(const idFireParms& fireParameters,
        idTestFireResults& testResults, idFinishFireResults& finishResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->FinishHitScan(
            *this, fireParameters, testResults, finishResults);
}

// Retail symbol: ?FinishFire@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA: 0x82B586D8, RVA: 0x00B586D8
bool idClientGame::FinishFire(const idFireParms& fireParameters,
        idTestFireResults& testResults, idFinishFireResults& finishResults) {
    return g_clientGameServices != nullptr &&
        g_clientGameServices->FinishFire(
            *this, fireParameters, testResults, finishResults);
}

// Retail symbol: ??0idPlayerTimeLock@@QAA@H@Z
// EA: 0x82B4D840, RVA: 0x00B4D840
idPlayerTimeLock::idPlayerTimeLock(const int newTime) : lastTime(-1) {
    if (g_clientGameServices == nullptr) return;
    idClientGame* const game = g_clientGameServices->GetClientGame();
    if (game == nullptr) return;
    if (g_clientGameServices->IsMultiplayer() && game->playerTime >= 0) {
        lastTime = game->GetPlayerGameTime();
    }
    game->playerTime = newTime;
}
