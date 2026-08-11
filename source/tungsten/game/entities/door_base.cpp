#include "game/entities/door_base.h"

namespace {
idDoorBaseServices defaultDoorBaseServices;
idDoorBaseServices* doorBaseServices = &defaultDoorBaseServices;

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddBounds(idBounds& destination, const idBounds& source) {
    for (int component = 0; component < 3; ++component) {
        if (source[0][component] < destination[0][component]) {
            destination[0][component] = source[0][component];
        }
        if (source[1][component] > destination[1][component]) {
            destination[1][component] = source[1][component];
        }
    }
}
}

void idDoorBaseServices::PostLinkSoundDoor(idDoor_Base&) {}
bool idDoorBaseServices::EntityHasInventoryKey(const idEntity*,
        const idDeclInventory*) const { return false; }
void idDoorBaseServices::ChangeAreaTravelFlags(const idBounds&, int,
        int, bool) {}
void idDoorBaseServices::ForceDormancy(idDoor_Base&, bool, int) {}
bool idDoorBaseServices::BaseModifyCrosshairInfo(const idDoor_Base&,
        const idEntity*, int, idDoorCrosshairInfo&) const { return true; }
int idDoorBaseServices::GetRequiredKeyNameIndex(
        const idDeclInventory*) const { return -1; }
void idDoorBaseServices::ActivateTargets(idDoor_Base&, idEntity*) {}
void idDoorBaseServices::InternalSetDoorState(idDoor_Base&, idEntity*,
        idDoorState) {}
void idDoorBaseServices::PostLinkedDoorOpen(idDoor_Base&, idEntity*) {}
void idDoorBaseServices::PostLinkedDoorClose(idDoor_Base&, idEntity*) {}
void idDoorBaseServices::SetPhysicsContents(idDoor_Base&, int) {}
bool idDoorBaseServices::HasPhysics(const idDoor_Base&) const {
    return false;
}
bool idDoorBaseServices::HasPresentable(const idDoor_Base&) const {
    return false;
}
idBounds idDoorBaseServices::GetPhysicsBounds(
        const idDoor_Base& door) const { return door.bounds; }
idBounds idDoorBaseServices::GetModelReferenceBounds(
        const idDoor_Base& door) const { return door.bounds; }
idVec3 idDoorBaseServices::GetPhysicsOrigin(
        const idDoor_Base&) const { return idVec3(0.0f, 0.0f, 0.0f); }
idSoundDoor* idDoorBaseServices::FindSoundDoorInBounds(const idBounds&) {
    return nullptr;
}
void idDoorBaseServices::NotifySoundDoor(idSoundDoor*, idDoor_Base&,
        bool) {}
const idDeclAiEvent* idDoorBaseServices::FindDoorMotionEvent() {
    return nullptr;
}
void idDoorBaseServices::WarnMissingPhysics(const idDoor_Base&) {}
void idDoorBaseServices::WarnMissingPresentable(const idDoor_Base&) {}
void idDoorBaseServices::DrawDoorDebugInfo() {}
bool idDoorBaseServices::IsPlayer(const idEntity*) const { return false; }
void idDoorBaseServices::SetBlockerPhysics(idDoor_Blocker&, int, bool) {}
void idDoorBaseServices::BecomeBlockerActive(idDoor_Blocker&, int) {}
void idDoorBaseServices::BecomeBlockerInactive(idDoor_Blocker&, int) {}
int idDoorBaseServices::GetPlayerJobStatus(const idEntity*,
        const char*) const { return -1; }
void idDoorBaseServices::PlayBlockerSound(idEntity*,
        const idSoundShader*) {}
void idDoorBaseServices::PlayBlockerLocalSound(idEntity*,
        const idSoundShader*) {}
void idDoorBaseServices::ActivateBlockerTargets(idDoor_Blocker&,
        idEntity*) {}
bool idDoorBaseServices::DebugPlayerLayerContains(const char*) const {
    return false;
}
void idDoorBaseServices::RemoveBlocker(idDoor_Blocker&) {}
void idDoorBaseServices::ThinkBlockerBase(idDoor_Blocker&) {}

void idDoor_Base::SetServices(idDoorBaseServices* const services) {
    doorBaseServices = services == nullptr
        ? &defaultDoorBaseServices : services;
}

idDoorBaseServices& idDoor_Base::Services() {
    return *doorBaseServices;
}

// Retail: 0x82C21D88 ?Spawn@idDoor_Base@@QAAXXZ
void idDoor_Base::Spawn() {
    Services().PostLinkSoundDoor(*this);
}

// Retail: 0x82C21D98 ?Event_GetLocked@idDoor_Base@@AAA?AVeventBool@@XZ
bool idDoor_Base::Event_GetLocked() const {
    return locked;
}

// Retail: 0x82C21DD0 ?HasKey@idDoor_Base@@UBA_NPBVidEntity@@@Z
bool idDoor_Base::HasKey(const idEntity* const activator) const {
    return requiredKey != nullptr && activator != nullptr
        && Services().EntityHasInventoryKey(activator, requiredKey);
}

// Retail: 0x82C21E48 ?IsCurrentlyUsable@idDoor_Base@@UBA_NPBVidEntity@@@Z
bool idDoor_Base::IsCurrentlyUsable(
        const idEntity* const activator) const {
    return !IsLockedForEntity(activator, 0.0f)
        && IsEverUsable(activator);
}

// Retail: 0x82C21EC0 ?IsLocked@idDoor_Base@@UBA_NXZ
bool idDoor_Base::IsLocked() const {
    return locked;
}

// Retail: 0x82C21EC8 ?IsLockedForEntity@idDoor_Base@@UBA_NPBVidEntity@@M@Z
bool idDoor_Base::IsLockedForEntity(const idEntity* const entity,
        float) const {
    if (!locked) {
        return false;
    }
    if (requiredKey != nullptr && entity != nullptr
            && Services().EntityHasInventoryKey(entity, requiredKey)) {
        return false;
    }
    return true;
}

// Retail: 0x82C21F70 ?IsEverUsable@idDoor_Blocker@@UBA_NPBVidEntity@@@Z
bool idDoor_Blocker::IsEverUsable(const idEntity*) const {
    return !isActuallyUseable || !hasBeenUsed;
}

// Retail: 0x82C21F98 ?GetUsableState@idDoor_Blocker@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
int idDoor_Blocker::GetUsableState(
        const idEntity* const activator) const {
    return idDoor_Base::Services().IsPlayer(activator)
        ? idDoor_Base::USABLE_DOOR : idDoor_Base::USABLE_NOT_USABLE;
}

// Retail: 0x82C21FD0 ?Spawn@idDoor_Blocker@@QAAXXZ
void idDoor_Blocker::Spawn() {
    idDoor_Base::Services().SetBlockerPhysics(*this, 0x200000, true);
    if (uniquelyRemoveable) {
        thinkFlags |= 1;
        idDoor_Base::Services().BecomeBlockerActive(*this, 1);
    }
}

// Retail: 0x82C22058 ?UpdateAASAreas@idDoor_Base@@MAAXXZ
void idDoor_Base::UpdateAASAreas() {
    bool blocked;
    if (usableByAI) {
        blocked = state == DOOR_CLOSED ? locked : false;
    } else {
        blocked = state != DOOR_OPENED && state != DOOR_BROKEN;
    }
    Services().ChangeAreaTravelFlags(bounds, 2048, 1, blocked);
}

// Retail: 0x82C220A8 ?Event_Open@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@@Z
void idDoor_Base::Event_Open(idEntity* const user) {
    if (IsClosed()) {
        Use(user, USABLE_DOOR);
    }
}

// Retail: 0x82C22108 ?Event_Close@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@@Z
void idDoor_Base::Event_Close(idEntity* const user) {
    if (IsOpen()) {
        Use(user, USABLE_DOOR);
    }
}

// Retail: 0x82C22168 ?Event_KickOpen@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@M@Z
void idDoor_Base::Event_KickOpen(idEntity* const user,
        const float forceScale) {
    if (IsClosed()) {
        kicked = forceScale;
        Use(user, USABLE_DOOR);
        kicked = 0.0f;
    }
}

// Retail: 0x82C221E8 ?OnActivate@idDoor_Base@@EAAXPAVidEntity@@@Z
void idDoor_Base::OnActivate(idEntity* const activator) {
    if (forceDormancyOnActivate) {
        Services().ForceDormancy(*this, false, 30000);
    }
    if (locked && (requiredKey == nullptr || HasKey(activator))) {
        SetLocked(false, activator);
    }
}

// Retail: 0x82C22298 ?Event_SetLocked@idDoor_Base@@AAA?AVeventVoid@@H@Z
void idDoor_Base::Event_SetLocked(const int lock) {
    SetLocked(lock != 0, nullptr);
}

// Retail: 0x82C222F0 ?Event_SetForcedUnusable@idDoor_Base@@AAA?AVeventVoid@@H@Z
void idDoor_Base::Event_SetForcedUnusable(const int unusable) {
    forcedUnusable = unusable != 0;
}

// Retail: 0x82C22300 ?IsEverUsable@idDoor_Base@@UBA_NPBVidEntity@@@Z
bool idDoor_Base::IsEverUsable(const idEntity*) const {
    return state != DOOR_BROKEN && !forcedUnusable;
}

// Retail: 0x82C22328 ?GetUsableState@idDoor_Base@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
int idDoor_Base::GetUsableState(const idEntity*) const {
    if (state == DOOR_BROKEN || !playerUsable) {
        return USABLE_NOT_USABLE;
    }
    if (!IsOpen()) {
        return USABLE_DOOR;
    }
    return CanClose(true) ? USABLE_DOOR : USABLE_NOT_USABLE;
}

// Retail: 0x82C223D0 ?GetOnlineUsableState@idDoor_Base@@UBA?AW4usableState_t@@XZ
int idDoor_Base::GetOnlineUsableState() const {
    if (state == DOOR_BROKEN) {
        return USABLE_NOT_USABLE;
    }
    if (!IsOpen()) {
        return USABLE_DOOR;
    }
    return CanClose(true) ? USABLE_DOOR : USABLE_NOT_USABLE;
}

// Retail: 0x82C22468 ?ModifyCrosshairInfo@idDoor_Base@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
bool idDoor_Base::ModifyCrosshairInfo(const idEntity* const activator,
        const int usable, idDoorCrosshairInfo& info) const {
    if (!Services().BaseModifyCrosshairInfo(
            *this, activator, usable, info)
            || (IsOpen() && !CanClose(true))) {
        return false;
    }
    if (!IsLockedForEntity(activator, 0.0f) || HasKey(activator)) {
        info.icon = displayIcon;
        return true;
    }
    const int keyName = Services().GetRequiredKeyNameIndex(requiredKey);
    if (requiredKey != nullptr && keyName >= 0) {
        info.material = DOOR_CROSSHAIR_DOOR;
        info.textIndex = keyName;
    } else {
        info.material = DOOR_CROSSHAIR_LOCKED;
    }
    info.textColorState = DOOR_CROSSHAIR_COLOR_NEGATIVE;
    info.colorState = DOOR_CROSSHAIR_COLOR_NEGATIVE;
    info.icon = displayIconLocked;
    return true;
}

// Retail: 0x82C225A8 ?Event_SetPlayerUsable@idDoor_Base@@AAA?AVeventVoid@@H@Z
void idDoor_Base::Event_SetPlayerUsable(const int usable) {
    playerUsable = usable != 0;
}

// Retail: 0x82C225B8 ??0idDoor_Blocker@@QAA@XZ
idDoor_Blocker::idDoor_Blocker()
    : lockedSound(nullptr), displayStringIndex(-1),
      isActuallyUseable(false), dontShowIconOnActuallyUseable(false),
      useSound(nullptr), availableJobDecl(), availableJobStatus(2),
      uniquelyRemoveable(false), hasCheckedForRemove(false),
      hasBeenUsed(false), name(), thinkFlags(0), removed(false) {
}

// Retail: 0x82C226C0 ?IsCurrentlyUsable@idDoor_Blocker@@UBA_NPBVidEntity@@@Z
bool idDoor_Blocker::IsCurrentlyUsable(
        const idEntity* const activator) const {
    if (!isActuallyUseable) {
        return lockedSound != nullptr;
    }
    if (hasBeenUsed) {
        return false;
    }
    if (availableJobDecl.IsEmpty()) {
        return true;
    }
    return idDoor_Base::Services().GetPlayerJobStatus(
        activator, availableJobDecl.c_str()) >= availableJobStatus;
}

// Retail: 0x82C22778 ?Use@idDoor_Blocker@@UAA_NPAVidEntity@@W4usableState_t@@@Z
bool idDoor_Blocker::Use(idEntity* const user, int) {
    if (!isActuallyUseable) {
        idDoor_Base::Services().PlayBlockerSound(user, lockedSound);
        return false;
    }
    if (hasBeenUsed) {
        return false;
    }
    if (!IsCurrentlyUsable(user)) {
        idDoor_Base::Services().PlayBlockerSound(user, lockedSound);
        return false;
    }
    if (!idDoor_Base::Services().IsPlayer(user)) {
        return false;
    }
    idDoor_Base::Services().ActivateBlockerTargets(*this, user);
    hasBeenUsed = true;
    if (useSound != nullptr) {
        idDoor_Base::Services().PlayBlockerLocalSound(user, useSound);
    }
    return true;
}

// Retail: 0x82C22868 ?ModifyCrosshairInfo@idDoor_Blocker@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
bool idDoor_Blocker::ModifyCrosshairInfo(
        const idEntity* const activator, int,
        idDoorCrosshairInfo& info) const {
    if (isActuallyUseable) {
        if (dontShowIconOnActuallyUseable) {
            info.material = DOOR_CROSSHAIR_DEFAULT;
        } else {
            const bool available = IsCurrentlyUsable(activator);
            info.colorState = available
                ? DOOR_CROSSHAIR_COLOR_NORMAL
                : DOOR_CROSSHAIR_COLOR_NEGATIVE;
            info.textColorState = info.colorState;
            info.material = DOOR_CROSSHAIR_DOOR;
            info.textIndex = displayStringIndex;
        }
    } else {
        info.material = DOOR_CROSSHAIR_LOCKED;
        info.colorState = DOOR_CROSSHAIR_COLOR_NEGATIVE;
        info.textColorState = DOOR_CROSSHAIR_COLOR_NEGATIVE;
        info.textIndex = displayStringIndex;
    }
    return true;
}

// Retail: 0x82C229D0 ?Think@idDoor_Blocker@@UAAXXZ
void idDoor_Blocker::Think() {
    idDoor_Base::Services().ThinkBlockerBase(*this);
    if (hasCheckedForRemove) {
        return;
    }
    hasCheckedForRemove = true;
    if (idDoor_Base::Services().DebugPlayerLayerContains(name.c_str())) {
        removed = true;
        idDoor_Base::Services().RemoveBlocker(*this);
    } else {
        thinkFlags &= ~1;
        idDoor_Base::Services().BecomeBlockerInactive(*this, 1);
    }
}

// Retail: 0x82C22A78 ??0idDoor_Base@@QAA@XZ
idDoor_Base::idDoor_Base()
    : usableByAI(false), locked(false), canKickOpen(false),
      kickUnlocks(false), kickOffHinges(false), opensWhenUnlocked(false),
      forcedUnusable(false), forceUnusableWhenOpened(true),
      playerUsable(false), triggerWhenOpenedCount(1), displayIcon(nullptr),
      displayIconLocked(nullptr), requiredKey(nullptr),
      removeKeyOnUse(false), lockedSound(nullptr), unlockSound(nullptr),
      motionEventDecl(nullptr), linked(), soundDoor(nullptr), kicked(0.0f),
      state(DOOR_UNKNOWN), bounds(), forceDormancyOnActivate(false) {
    ClearBounds(bounds);
    motionEventDecl = Services().FindDoorMotionEvent();
}

// Retail: 0x82C22BE8 ?DrawDebugInfo@idDoor_Base@@SAXXZ
void idDoor_Base::DrawDebugInfo() {
    Services().DrawDoorDebugInfo();
}

// Retail: 0x82C22F18 ?SetDoorState@idDoor_Base@@QAAXPAVidEntity@@W4doorState_t@1@@Z
void idDoor_Base::SetDoorState(idEntity* activator,
        const idDoorState newState) {
    const idDoorState oldState = state;
    idEntity* const originalActivator = activator;
    if (oldState != newState && newState == DOOR_OPENING
            && oldState == DOOR_CLOSED) {
        if (triggerWhenOpenedCount != 0) {
            if (triggerWhenOpenedCount > 0) {
                --triggerWhenOpenedCount;
            }
            if (activator == nullptr) {
                activator = reinterpret_cast<idEntity*>(this);
            }
            Services().ActivateTargets(*this, activator);
        }
    }
    for (int index = 0; index < linked.Num(); ++index) {
        idDoor_Base* const linkedDoor = linked[index];
        if (linkedDoor == nullptr) {
            continue;
        }
        if (newState == DOOR_OPENING || newState == DOOR_OPENED) {
            Services().PostLinkedDoorOpen(*linkedDoor, originalActivator);
        } else if (newState == DOOR_CLOSING || newState == DOOR_CLOSED) {
            Services().PostLinkedDoorClose(*linkedDoor, originalActivator);
        }
    }
    Services().InternalSetDoorState(*this, originalActivator, newState);
    if (usableByAI && oldState != newState && Services().HasPhysics(*this)) {
        if (newState == DOOR_CLOSED && oldState != DOOR_CLOSED
                && !IsLocked()) {
            Services().SetPhysicsContents(*this, 1);
        } else if (newState == DOOR_OPENED && oldState != DOOR_OPENED) {
            Services().SetPhysicsContents(*this, 131073);
        }
    }
    state = newState;
    UpdateAASAreas();
    if (soundDoor != nullptr) {
        Services().NotifySoundDoor(soundDoor, *this,
            newState == DOOR_CLOSED || newState == DOOR_CLOSING);
    }
}

// Retail: 0x82C23190 ?Event_LinkSoundDoor@idDoor_Base@@AAA?AVeventVoid@@XZ
void idDoor_Base::Event_LinkSoundDoor() {
    if (!Services().HasPhysics(*this)) {
        Services().WarnMissingPhysics(*this);
        return;
    }
    if (!Services().HasPresentable(*this)) {
        Services().WarnMissingPresentable(*this);
        return;
    }
    idBounds searchBounds = Services().GetPhysicsBounds(*this);
    const idVec3 size = searchBounds[1] - searchBounds[0];
    if (size.LengthSqr() == 0.0f) {
        searchBounds = Services().GetModelReferenceBounds(*this);
        const idVec3 physicsOrigin = Services().GetPhysicsOrigin(*this);
        searchBounds[0] = searchBounds[0] + physicsOrigin;
        searchBounds[1] = searchBounds[1] + physicsOrigin;
    }
    soundDoor = Services().FindSoundDoorInBounds(searchBounds);
    if (soundDoor != nullptr) {
        SetDoorState(reinterpret_cast<idEntity*>(this), state);
    }
}

// Retail: 0x82C234D0 ?UpdateState@idDoor_Base@@IAAXXZ
void idDoor_Base::UpdateState() {
    if (state == DOOR_BROKEN) {
        return;
    }
    if (IsClosed() && state != DOOR_CLOSED) {
        SetDoorState(reinterpret_cast<idEntity*>(this), DOOR_CLOSED);
    } else if (IsOpen() && state != DOOR_OPENED) {
        SetDoorState(reinterpret_cast<idEntity*>(this), DOOR_OPENED);
    }
}

bool idDoor_Base::IsOpen() const { return state == DOOR_OPENED; }
bool idDoor_Base::IsClosed() const { return state == DOOR_CLOSED; }
bool idDoor_Base::CanClose(bool) const { return true; }
bool idDoor_Base::Use(idEntity*, int) { return false; }

void idDoor_Base::SetLocked(const bool lock, idEntity*) {
    if (locked == lock) {
        return;
    }
    locked = lock;
    UpdateAASAreas();
}
