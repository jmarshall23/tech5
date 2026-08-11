#include "clientgame_reliable.h"
#include "clientgame_local.h"

#include <algorithm>

namespace {
idClientGameReliableServices* g_reliableServices = nullptr;

template<class T>
void SerializeDecl(idSerializer& serializer, const T*& declaration) {
    if (g_reliableServices == nullptr) return;
    const void* value = declaration;
    g_reliableServices->SerializeDeclaration(serializer, value);
    declaration = static_cast<const T*>(value);
}

void SerializeSpawnId(idSerializer& serializer, presentableSpawnId_t& id) {
    if (g_reliableServices != nullptr) {
        g_reliableServices->SerializeUnsigned(serializer, id.value, 32);
    }
}

void ExecuteThroughRuntime(idClientGameMsg& message) {
    if (g_reliableServices != nullptr) {
        g_reliableServices->ExecuteMessage(message);
    }
}
} // namespace

void Tungsten_SetClientGameReliableServices(
        idClientGameReliableServices* const services) {
    g_reliableServices = services;
}

idClientGameMsg::idClientGameMsg() : peerMask(0xFF) {}

void idClientGameMsg::PrintDebug() {
    if (g_reliableServices != nullptr) {
        g_reliableServices->PrintDebug(*this);
    }
}

idClientGameMsg_DropItem::idClientGameMsg_DropItem()
    : playerNumber(-1), itemDecl(nullptr), numAmmoTransfers(0),
      ammoTransfers{} {}

idClientGameMsg_HandsEquip::idClientGameMsg_HandsEquip()
    : playerNumber(-1), itemDecl(nullptr), ammoDecl(nullptr) {}

idClientGameMsg_HandsAmmoChange::idClientGameMsg_HandsAmmoChange()
    : playerNumber(-1), ammoDecl(nullptr), weaponDecl(nullptr), forced(false) {}

idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow()
    : playerNumber(-1), throwType(HANDS_THROW_MAX), throwItem(nullptr),
      start(0.0f, 0.0f, 0.0f), fireAxis(), initialSpeed(0.0f),
      startTime(0), serverTime(0), predictedKey(-1) {}

idClientGameMsg_QuickUse::idClientGameMsg_QuickUse()
    : instigator(), invDecl(nullptr) {}

idClientGameMsg_VehicleCrosshairChangeTarget::
idClientGameMsg_VehicleCrosshairChangeTarget() : vehicle() {}

idClientGameMsg_VehicleWeaponChange::idClientGameMsg_VehicleWeaponChange()
    : vehicle() {}

idClientGameMsg_UpdateStat::idClientGameMsg_UpdateStat()
    : presentable(), statType(0), statParm(0) {}

idClientGameMsg_UseFocus::idClientGameMsg_UseFocus()
    : instigator(), usedPresentable(), usableState(0) {}

idClientGameMsg_MeleeHit::idClientGameMsg_MeleeHit()
    : instigator(), hitEntityNum(0x1FFF), damageDecl(nullptr),
      traceJoint(-1), traceModelFeature(0) {}

idClientGameMsg_ActorModifier::idClientGameMsg_ActorModifier()
    : instigator(), uid(0), index(0) {}

idClientGameMsg_PostGameScoreRecap::idClientGameMsg_PostGameScoreRecap()
    : items(0) {}

// Retail symbol: ?ShouldExecuteOnInstigator@idClientGameMsg_HandsThrow@@UAA_NXZ
// EA: 0x82B586F0, RVA: 0x00B586F0
bool idClientGameMsg_HandsThrow::ShouldExecuteOnInstigator() const {
    return throwType == HANDS_THROW_RELEASE ||
        (g_reliableServices != nullptr && g_reliableServices->IsServer());
}

// Retail symbol: ?ExecuteReliableClientGameMsg@idClientGame@@QAAXAAVidClientGameMsg@@@Z
// EA: 0x82B587B8, RVA: 0x00B587B8
void idClientGame::ExecuteReliableClientGameMsg(idClientGameMsg& gameMessage) {
    if (g_reliableServices != nullptr &&
            g_reliableServices->DebugEnabled()) gameMessage.PrintDebug();
    gameMessage.Execute();
}

// Retail symbol: ?Execute@idClientGameMsg_DropItem@@UAAXXZ
// EA: 0x82B58848, RVA: 0x00B58848
void idClientGameMsg_DropItem::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?PrintDebug@idClientGameMsg_DropItem@@UAAXXZ
// EA: 0x82B58BC8, RVA: 0x00B58BC8
void idClientGameMsg_DropItem::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?GetRealStartTime@idClientGameMsg_HandsThrow@@AAAHPAVidPresentablePlayer@@@Z
// EA: 0x82B58C68, RVA: 0x00B58C68
int idClientGameMsg_HandsThrow::GetRealStartTime(
        idPresentablePlayer* const player) {
    if (player == nullptr || g_reliableServices == nullptr ||
            g_reliableServices->IsPlayerLocallyControlled(*player)) {
        return startTime;
    }
    idClientGame* const game = g_reliableServices->GetClientGame();
    const int delta = startTime -
        g_reliableServices->GetPlayerGameTime(*player);
    return (game != nullptr ? game->GetPlayerGameTime() : 0) + delta;
}

// Retail symbol: ?PrintDebug@idClientGameMsg_HandsThrow@@UAAXXZ
// EA: 0x82B58D50, RVA: 0x00B58D50
void idClientGameMsg_HandsThrow::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?AddHit@idClientGameMsg_HitScanHit@@QAAXHHHVidVec3@@@Z
// EA: 0x82B58E60, RVA: 0x00B58E60
void idClientGameMsg_HitScanHit::AddHit(const int entityNumber,
        const int jointNumber, const int bodyId,
        const idVec3 hitPosition) {
    if (numHits < 0 || numHits >= 24) return;
    hitInfo_t& hit = hitInfos[numHits++];
    hit.entityNum = entityNumber;
    hit.jointNum = jointNumber;
    hit.bodyId = bodyId;
    hit.hitPos = hitPosition;
}

// Retail symbol: ?PrintDebug@idClientGameMsg_PostGameScoreRecap@@UAAXXZ
// EA: 0x82B58F10, RVA: 0x00B58F10
void idClientGameMsg_PostGameScoreRecap::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?GetNumAwards@idClientGameMsg_PostGameScoreRecap@@QAAHH@Z
// EA: 0x82B59278, RVA: 0x00B59278
int idClientGameMsg_PostGameScoreRecap::GetNumAwards(
        const int playerNum) {
    int result = 0;
    for (int i = 0; i < items.Num(); ++i) {
        if (items[i].playerIndex == playerNum) ++result;
    }
    return result;
}

// Retail symbol: ?HandleReliableGameMsg@idClientGame@@QAAXAAVidClientGameMsg@@@Z
// EA: 0x82B59368, RVA: 0x00B59368
void idClientGame::HandleReliableGameMsg(idClientGameMsg& gameMessage) {
    if (g_reliableServices == nullptr) return;
    if (gameMessage.IsMPOnly() && !g_reliableServices->IsMultiplayer()) {
        if (g_reliableServices->DebugEnabled()) gameMessage.PrintDebug();
        return;
    }
    if (g_reliableServices->DebugEnabled()) gameMessage.PrintDebug();
    if (gameMessage.ShouldExecuteOnInstigator()) {
        ExecuteReliableClientGameMsg(gameMessage);
    }
    if (!g_reliableServices->IsServer() ||
            gameMessage.ShouldSendServerToClients()) {
        g_reliableServices->SendReliableMessage(gameMessage);
    }
}

// Retail symbol: ??0idClientGameMsg_HitScanHit@@QAA@PAVidPresentable@@PBVidDeclWeapon@@PBVidDeclProjectile@@VidVec3@@@Z
// EA: 0x82B595B0, RVA: 0x00B595B0
idClientGameMsg_HitScanHit::idClientGameMsg_HitScanHit(
        idPresentable* const attacker_, const idDeclWeapon* const weapon,
        const idDeclProjectile* const projectile, const idVec3& start)
    : attacker(), weaponDecl(weapon), projDecl(projectile), startPos(start),
      numHits(0), serverTime(0), hitInfos{} {
    if (g_reliableServices != nullptr) {
        attacker.value = g_reliableServices->GetPresentableSpawnId(attacker_);
        idClientGame* const game = g_reliableServices->GetClientGame();
        if (game != nullptr) serverTime = game->GetServerGameTime();
    }
}

// Retail symbol: ?ExecuteQueuedClientGameMsgs@idClientGame@@QAAXXZ
// EA: 0x82B5A378, RVA: 0x00B5A378
void idClientGame::ExecuteQueuedClientGameMsgs() {
    for (int i = 0; i < queuedReliableMsgs.Num(); ++i) {
        idClientGameMsg* const message = queuedReliableMsgs[i];
        if (message != nullptr) {
            ExecuteReliableClientGameMsg(*message);
            delete message;
        }
    }
    queuedReliableMsgs.Clear();
}

// Retail symbol: ?Serialize@idClientGameMsg_DropItem@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5A3F0, RVA: 0x00B5A3F0
void idClientGameMsg_DropItem::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    g_reliableServices->SerializeInt(serializer, playerNumber, 32);
    SerializeDecl(serializer, itemDecl);
    g_reliableServices->SerializeInt(serializer, numAmmoTransfers, 32);
    numAmmoTransfers = (std::max)(0, (std::min)(numAmmoTransfers, 4));
    for (int i = 0; i < numAmmoTransfers; ++i) {
        SerializeDecl(serializer, ammoTransfers[i].ammoDecl);
        g_reliableServices->SerializeInt(serializer,
            ammoTransfers[i].count, 32);
    }
}

// Retail symbol: ?Serialize@idClientGameMsg_HandsEquip@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5A4D0, RVA: 0x00B5A4D0
void idClientGameMsg_HandsEquip::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    g_reliableServices->SerializeInt(serializer, playerNumber, 32);
    SerializeDecl(serializer, itemDecl);
    SerializeDecl(serializer, ammoDecl);
}

// Retail symbol: ?Serialize@idClientGameMsg_HandsAmmoChange@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5A548, RVA: 0x00B5A548
void idClientGameMsg_HandsAmmoChange::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    g_reliableServices->SerializeInt(serializer, playerNumber, 32);
    SerializeDecl(serializer, ammoDecl);
    SerializeDecl(serializer, weaponDecl);
    g_reliableServices->SerializeBool(serializer, forced);
}

// Retail symbol: ??0idClientGameMsg_HandsThrow@@QAA@HW4clientGameMsgHandsThrow_t@0@PBVidDeclThrowable@@VidVec3@@VidMat3@@MH@Z
// EA: 0x82B5A5F8, RVA: 0x00B5A5F8
idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow(
        const int playerNumber_, const clientGameMsgHandsThrow_t throwType_,
        const idDeclThrowable* const throwItem_, const idVec3& start_,
        const idMat3& fireAxis_, const float initialSpeed_,
        const int startTime_)
    : playerNumber(playerNumber_), throwType(throwType_),
      throwItem(throwItem_), start(start_), fireAxis(fireAxis_),
      initialSpeed(initialSpeed_), startTime(startTime_), serverTime(0),
      predictedKey(-1) {
    if (g_reliableServices != nullptr &&
            g_reliableServices->GetClientGame() != nullptr) {
        serverTime = g_reliableServices->GetClientGame()->GetServerGameTime();
    }
}

// Retail symbol: ?Serialize@idClientGameMsg_HandsThrow@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5A7C0, RVA: 0x00B5A7C0
void idClientGameMsg_HandsThrow::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    g_reliableServices->SerializeInt(serializer, playerNumber, 32);
    SerializeDecl(serializer, throwItem);
    g_reliableServices->SerializeInt(serializer, serverTime, 32);
    int type = static_cast<int>(throwType);
    g_reliableServices->SerializeInt(serializer, type, 3);
    throwType = static_cast<clientGameMsgHandsThrow_t>(type);
    if (throwType == HANDS_THROW_RELEASE ||
            throwType == HANDS_THROW_DROPONDEATH) {
        g_reliableServices->SerializeInt(serializer, startTime, 32);
    }
    if (throwType == HANDS_THROW_RELEASE) {
        g_reliableServices->SerializeVec3(serializer, start);
        g_reliableServices->SerializeMat3(serializer, fireAxis);
        g_reliableServices->SerializeFloat(serializer, initialSpeed);
        g_reliableServices->SerializeInt(serializer, predictedKey, 32);
    }
}

// Retail symbol: ?ThrowItem@idClientGameMsg_HandsThrow@@AAAXPAVidPresentablePlayer@@@Z
// EA: 0x82B5A910, RVA: 0x00B5A910
void idClientGameMsg_HandsThrow::ThrowItem(
        idPresentablePlayer* const player) {
    if (player != nullptr && g_reliableServices != nullptr) {
        g_reliableServices->ThrowItem(*this, *player);
    }
}

// Retail symbol: ?Serialize@idClientGameMsg_HitScanHit@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5AAE0, RVA: 0x00B5AAE0
void idClientGameMsg_HitScanHit::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    SerializeSpawnId(serializer, attacker);
    g_reliableServices->SerializeInt(serializer, numHits, 5);
    numHits = (std::max)(0, (std::min)(numHits, 24));
    SerializeDecl(serializer, weaponDecl);
    SerializeDecl(serializer, projDecl);
    g_reliableServices->SerializeInt(serializer, serverTime, 32);
    for (int i = 0; i < numHits; ++i) {
        g_reliableServices->SerializeInt(serializer, hitInfos[i].entityNum, 32);
        g_reliableServices->SerializeInt(serializer, hitInfos[i].jointNum, 32);
        g_reliableServices->SerializeInt(serializer, hitInfos[i].bodyId, 32);
        g_reliableServices->SerializeVec3(serializer, hitInfos[i].hitPos);
    }
}

// Retail symbol: ?Execute@idClientGameMsg_HitScanHit@@UAAXXZ
// EA: 0x82B5ABA8, RVA: 0x00B5ABA8
void idClientGameMsg_HitScanHit::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?PrintDebug@idClientGameMsg_HitScanHit@@UAAXXZ
// EA: 0x82B5AEA8, RVA: 0x00B5AEA8
void idClientGameMsg_HitScanHit::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?Serialize@idClientGameMsg_QuickUse@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5AFB0, RVA: 0x00B5AFB0
void idClientGameMsg_QuickUse::Serialize(idSerializer& serializer) {
    SerializeSpawnId(serializer, instigator);
    SerializeDecl(serializer, invDecl);
}

// Retail symbol: ?Execute@idClientGameMsg_QuickUse@@UAAXXZ
// EA: 0x82B5B020, RVA: 0x00B5B020
void idClientGameMsg_QuickUse::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?PrintDebug@idClientGameMsg_QuickUse@@UAAXXZ
// EA: 0x82B5B2C0, RVA: 0x00B5B2C0
void idClientGameMsg_QuickUse::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?Serialize@idClientGameMsg_VehicleCrosshairChangeTarget@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5B360, RVA: 0x00B5B360
void idClientGameMsg_VehicleCrosshairChangeTarget::Serialize(
        idSerializer& serializer) {
    SerializeSpawnId(serializer, vehicle);
    if (g_reliableServices != nullptr) {
        g_reliableServices->SerializeMessageRuntime(*this, serializer);
    }
}

// Retail symbol: ?Execute@idClientGameMsg_VehicleCrosshairChangeTarget@@UAAXXZ
// EA: 0x82B5B408, RVA: 0x00B5B408
void idClientGameMsg_VehicleCrosshairChangeTarget::Execute() {
    ExecuteThroughRuntime(*this);
}

// Retail symbol: ?Serialize@idClientGameMsg_VehicleWeaponChange@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5B478, RVA: 0x00B5B478
void idClientGameMsg_VehicleWeaponChange::Serialize(
        idSerializer& serializer) {
    SerializeSpawnId(serializer, vehicle);
    if (g_reliableServices != nullptr) {
        g_reliableServices->SerializeMessageRuntime(*this, serializer);
    }
}

// Retail symbol: ?Execute@idClientGameMsg_VehicleWeaponChange@@UAAXXZ
// EA: 0x82B5B518, RVA: 0x00B5B518
void idClientGameMsg_VehicleWeaponChange::Execute() {
    ExecuteThroughRuntime(*this);
}

// Retail symbol: ?Serialize@idClientGameMsg_UpdateStat@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5B588, RVA: 0x00B5B588
void idClientGameMsg_UpdateStat::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    SerializeSpawnId(serializer, presentable);
    g_reliableServices->SerializeInt(serializer, statType, 2);
    g_reliableServices->SerializeInt(serializer, statParm, 32);
}

// Retail symbol: ?Execute@idClientGameMsg_UpdateStat@@UAAXXZ
// EA: 0x82B5B640, RVA: 0x00B5B640
void idClientGameMsg_UpdateStat::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?Serialize@idClientGameMsg_UseFocus@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5B740, RVA: 0x00B5B740
void idClientGameMsg_UseFocus::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    SerializeSpawnId(serializer, instigator);
    SerializeSpawnId(serializer, usedPresentable);
    g_reliableServices->SerializeInt(serializer, usableState, 4);
}

// Retail symbol: ?Execute@idClientGameMsg_UseFocus@@UAAXXZ
// EA: 0x82B5B7F8, RVA: 0x00B5B7F8
void idClientGameMsg_UseFocus::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?PrintDebug@idClientGameMsg_UseFocus@@UAAXXZ
// EA: 0x82B5B8D8, RVA: 0x00B5B8D8
void idClientGameMsg_UseFocus::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?Serialize@idClientGameMsg_MeleeHit@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5B9C0, RVA: 0x00B5B9C0
void idClientGameMsg_MeleeHit::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    SerializeSpawnId(serializer, instigator);
    g_reliableServices->SerializeInt(serializer, hitEntityNum, 32);
    SerializeDecl(serializer, damageDecl);
    int encodedJoint = traceJoint < 0 ? 0xFFFF : traceJoint;
    g_reliableServices->SerializeInt(serializer, encodedJoint, 16);
    traceJoint = encodedJoint == 0xFFFF ? -1 : encodedJoint;
    g_reliableServices->SerializeInt(serializer, traceModelFeature, 32);
}

// Retail symbol: ?Execute@idClientGameMsg_MeleeHit@@UAAXXZ
// EA: 0x82B5BAF0, RVA: 0x00B5BAF0
void idClientGameMsg_MeleeHit::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?PrintDebug@idClientGameMsg_MeleeHit@@UAAXXZ
// EA: 0x82B5BC80, RVA: 0x00B5BC80
void idClientGameMsg_MeleeHit::PrintDebug() {
    idClientGameMsg::PrintDebug();
}

// Retail symbol: ?Serialize@idClientGameMsg_ActorModifier@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5BCF8, RVA: 0x00B5BCF8
void idClientGameMsg_ActorModifier::Serialize(idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    SerializeSpawnId(serializer, instigator);
    g_reliableServices->SerializeUnsigned(serializer, uid, 32);
    g_reliableServices->SerializeInt(serializer, index, 8);
}

// Retail symbol: ?Execute@idClientGameMsg_ActorModifier@@UAAXXZ
// EA: 0x82B5BDB0, RVA: 0x00B5BDB0
void idClientGameMsg_ActorModifier::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?QueueReliableClientGameMsg@idClientGame@@QAAXPAVidClientGameMsg@@AAVidBitMsg@@@Z
// EA: 0x82B5C088, RVA: 0x00B5C088
void idClientGame::QueueReliableClientGameMsg(
        idClientGameMsg* const gameMessage, idBitMsg& message) {
    if (gameMessage == nullptr) return;
    if (g_reliableServices != nullptr) {
        g_reliableServices->DeserializeMessage(*gameMessage, message);
    }
    queuedReliableMsgs.Append(gameMessage);
}

// Retail symbol: ?Execute@idClientGameMsg_HandsEquip@@UAAXXZ
// EA: 0x82B5C140, RVA: 0x00B5C140
void idClientGameMsg_HandsEquip::Execute() { ExecuteThroughRuntime(*this); }

// Retail symbol: ?Execute@idClientGameMsg_HandsAmmoChange@@UAAXXZ
// EA: 0x82B5C280, RVA: 0x00B5C280
void idClientGameMsg_HandsAmmoChange::Execute() {
    ExecuteThroughRuntime(*this);
}

// Retail symbol: ?Execute@idClientGameMsg_HandsThrow@@UAAXXZ
// EA: 0x82B5C428, RVA: 0x00B5C428
void idClientGameMsg_HandsThrow::Execute() {
    if (g_reliableServices == nullptr) return;
    idClientGame* const game = g_reliableServices->GetClientGame();
    idPresentablePlayer* const player = game != nullptr
        ? game->FindPlayerPresentableByIndex(playerNumber) : nullptr;
    if (player == nullptr) {
        PrintDebug();
    } else if (throwType == HANDS_THROW_RELEASE) {
        ThrowItem(player);
    } else if (throwType < HANDS_THROW_QUICK ||
            throwType > HANDS_THROW_DROPONDEATH) {
        PrintDebug();
    }
}

// Retail symbol: ?Serialize@idClientGameMsg_PostGameScoreRecap@@UAAXAAVidSerializer@@@Z
// EA: 0x82B5C510, RVA: 0x00B5C510
void idClientGameMsg_PostGameScoreRecap::Serialize(
        idSerializer& serializer) {
    if (g_reliableServices == nullptr) return;
    int count = items.Num();
    g_reliableServices->SerializeInt(serializer, count, 32);
    if (!g_reliableServices->IsWriting(serializer)) {
        count = (std::max)(0, (std::min)(count, 4096));
        items.SetNum(count);
    }
    for (int i = 0; i < items.Num(); ++i) {
        scoreItem_t& item = items[i];
        g_reliableServices->SerializeBool(serializer, item.isFloat);
        if (item.isFloat) {
            g_reliableServices->SerializeFloat(serializer, item.floatValue);
        } else {
            g_reliableServices->SerializeInt(serializer, item.intValue, 32);
        }
        g_reliableServices->SerializeInt(serializer, item.playerIndex, 32);
        SerializeDecl(serializer, item.metric);
    }
}

// Retail symbol: ?Execute@idClientGameMsg_PostGameScoreRecap@@UAAXXZ
// EA: 0x82B5C6C8, RVA: 0x00B5C6C8
void idClientGameMsg_PostGameScoreRecap::Execute() {
    if (g_reliableServices != nullptr) {
        g_reliableServices->ExecutePostGameScoreRecap(*this);
    }
    PrintDebug();
}

// Retail symbol: ?NetReceiveReliable@idClientGame@@QAAXHAAVidBitMsg@@H@Z
// EA: 0x82B5C860, RVA: 0x00B5C860
void idClientGame::NetReceiveReliable(const int type, idBitMsg& message,
        const int) {
    idClientGameMsg* gameMessage = nullptr;
    switch (static_cast<gameReliable_t>(type)) {
    case RELIABLE_CLIENTGAMEMSG_HANDS_EQUIP:
        gameMessage = new idClientGameMsg_HandsEquip(); break;
    case RELIABLE_CLIENTGAMEMSG_HANDS_AMMO_CHANGE:
        gameMessage = new idClientGameMsg_HandsAmmoChange(); break;
    case RELIABLE_CLIENTGAMEMSG_HANDS_THROW:
        gameMessage = new idClientGameMsg_HandsThrow(); break;
    case RELIABLE_CLIENTGAMEMSG_HITSCANHIT:
        gameMessage = new idClientGameMsg_HitScanHit(); break;
    case RELIABLE_CLIENTGAMEMSG_QUICKUSE:
        gameMessage = new idClientGameMsg_QuickUse(); break;
    case RELIABLE_CLIENTGAMEMSG_USEFOCUS:
        gameMessage = new idClientGameMsg_UseFocus(); break;
    case RELIABLE_CLIENTGAMEMSG_MELEEHIT:
        gameMessage = new idClientGameMsg_MeleeHit(); break;
    case RELIABLE_CLIENTGAMEMSG_DROPITEM:
        gameMessage = new idClientGameMsg_DropItem(); break;
    case RELIABLE_CLIENTGAMEMSG_VEHICLE_CROSSHAIR_CHANGE_TARGET:
        gameMessage = new idClientGameMsg_VehicleCrosshairChangeTarget(); break;
    case RELIABLE_CLIENTGAMEMSG_VEHICLE_WEAPON_CHANGE:
        gameMessage = new idClientGameMsg_VehicleWeaponChange(); break;
    case RELIABLE_CLIENTGAMEMSG_UPDATE_STAT:
        gameMessage = new idClientGameMsg_UpdateStat(); break;
    case RELIABLE_CLIENTGAMEMSG_ACTORMODIFIER:
        gameMessage = new idClientGameMsg_ActorModifier(); break;
    case RELIABLE_POSTGAME_SCORERECAP:
        gameMessage = new idClientGameMsg_PostGameScoreRecap(); break;
    default:
        return;
    }
    QueueReliableClientGameMsg(gameMessage, message);
}

// Retail symbol: ?AddInt@idClientGameMsg_PostGameScoreRecap@@QAAXPBVidDeclMetric@@HH@Z
// EA: 0x82B5CE60, RVA: 0x00B5CE60
void idClientGameMsg_PostGameScoreRecap::AddInt(
        const idDeclMetric* const metric, const int playerIndex,
        const int value) {
    if (metric == nullptr) return;
    scoreItem_t* const item = items.Alloc();
    if (item == nullptr) return;
    item->intValue = value;
    item->isFloat = false;
    item->metric = metric;
    item->playerIndex = playerIndex;
}
