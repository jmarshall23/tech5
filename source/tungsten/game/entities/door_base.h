#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idDeclAiEvent;
class idDeclInventory;
class idEntity;
class idMaterial;
class idSoundDoor;
class idSoundShader;
class idDoor_Base;
class idDoor_Blocker;

enum idDoorState {
    DOOR_UNKNOWN = 0,
    DOOR_CLOSING = 1,
    DOOR_CLOSED = 2,
    DOOR_OPENING = 3,
    DOOR_OPENED = 4,
    DOOR_BROKEN = 5
};

enum idDoorCrosshairMaterial {
    DOOR_CROSSHAIR_DEFAULT = 0,
    DOOR_CROSSHAIR_DOOR = 1,
    DOOR_CROSSHAIR_LOCKED = 2
};

enum idDoorCrosshairColorState {
    DOOR_CROSSHAIR_COLOR_NORMAL = 0,
    DOOR_CROSSHAIR_COLOR_NEGATIVE = 1
};

struct idDoorCrosshairInfo {
    idDoorCrosshairMaterial material = DOOR_CROSSHAIR_DEFAULT;
    idDoorCrosshairColorState colorState = DOOR_CROSSHAIR_COLOR_NORMAL;
    idDoorCrosshairColorState textColorState =
        DOOR_CROSSHAIR_COLOR_NORMAL;
    int textIndex = -1;
    const idMaterial* icon = nullptr;
};

class idDoorBaseServices {
public:
    virtual ~idDoorBaseServices() = default;
    virtual void PostLinkSoundDoor(idDoor_Base& door);
    virtual bool EntityHasInventoryKey(const idEntity* entity,
        const idDeclInventory* key) const;
    virtual void ChangeAreaTravelFlags(const idBounds& bounds,
        int areaFlags, int travelFlags, bool set);
    virtual void ForceDormancy(idDoor_Base& door,
        bool dormant, int durationMilliseconds);
    virtual bool BaseModifyCrosshairInfo(const idDoor_Base& door,
        const idEntity* activator, int usable,
        idDoorCrosshairInfo& info) const;
    virtual int GetRequiredKeyNameIndex(
        const idDeclInventory* key) const;
    virtual void ActivateTargets(idDoor_Base& door, idEntity* activator);
    virtual void InternalSetDoorState(idDoor_Base& door,
        idEntity* activator, idDoorState state);
    virtual void PostLinkedDoorOpen(idDoor_Base& linked,
        idEntity* activator);
    virtual void PostLinkedDoorClose(idDoor_Base& linked,
        idEntity* activator);
    virtual void SetPhysicsContents(idDoor_Base& door, int contents);
    virtual bool HasPhysics(const idDoor_Base& door) const;
    virtual bool HasPresentable(const idDoor_Base& door) const;
    virtual idBounds GetPhysicsBounds(const idDoor_Base& door) const;
    virtual idBounds GetModelReferenceBounds(
        const idDoor_Base& door) const;
    virtual idVec3 GetPhysicsOrigin(const idDoor_Base& door) const;
    virtual idSoundDoor* FindSoundDoorInBounds(const idBounds& bounds);
    virtual void NotifySoundDoor(idSoundDoor* soundDoor,
        idDoor_Base& door, bool close);
    virtual const idDeclAiEvent* FindDoorMotionEvent();
    virtual void WarnMissingPhysics(const idDoor_Base& door);
    virtual void WarnMissingPresentable(const idDoor_Base& door);
    virtual void DrawDoorDebugInfo();

    virtual bool IsPlayer(const idEntity* entity) const;
    virtual void SetBlockerPhysics(idDoor_Blocker& blocker,
        int contents, bool enableClip);
    virtual void BecomeBlockerActive(idDoor_Blocker& blocker, int flags);
    virtual void BecomeBlockerInactive(idDoor_Blocker& blocker, int flags);
    virtual int GetPlayerJobStatus(const idEntity* entity,
        const char* jobDeclaration) const;
    virtual void PlayBlockerSound(idEntity* user,
        const idSoundShader* sound);
    virtual void PlayBlockerLocalSound(idEntity* player,
        const idSoundShader* sound);
    virtual void ActivateBlockerTargets(idDoor_Blocker& blocker,
        idEntity* player);
    virtual bool DebugPlayerLayerContains(const char* entityName) const;
    virtual void RemoveBlocker(idDoor_Blocker& blocker);
    virtual void ThinkBlockerBase(idDoor_Blocker& blocker);
};

class idDoor_Base {
public:
    static constexpr int USABLE_NOT_USABLE = 0;
    static constexpr int USABLE_DOOR = 7;

    idDoor_Base();
    virtual ~idDoor_Base() = default;

    static void SetServices(idDoorBaseServices* services);
    static idDoorBaseServices& Services();

    void Spawn();
    bool Event_GetLocked() const;
    virtual bool HasKey(const idEntity* activator) const;
    virtual bool IsCurrentlyUsable(const idEntity* activator) const;
    virtual bool IsLocked() const;
    virtual bool IsLockedForEntity(const idEntity* entity,
        float kickedAmount) const;
    virtual void UpdateAASAreas();
    void Event_Open(idEntity* user);
    void Event_Close(idEntity* user);
    void Event_KickOpen(idEntity* user, float forceScale);
    virtual void OnActivate(idEntity* activator);
    void Event_SetLocked(int lock);
    void Event_SetForcedUnusable(int unusable);
    virtual bool IsEverUsable(const idEntity* activator) const;
    virtual int GetUsableState(const idEntity* activator = nullptr) const;
    virtual int GetOnlineUsableState() const;
    virtual bool ModifyCrosshairInfo(const idEntity* activator,
        int usable, idDoorCrosshairInfo& info) const;
    void Event_SetPlayerUsable(int usable);
    static void DrawDebugInfo();
    void SetDoorState(idEntity* activator, idDoorState newState);
    void Event_LinkSoundDoor();
    void UpdateState();

    virtual bool IsOpen() const;
    virtual bool IsClosed() const;
    virtual bool CanClose(bool testingForUse) const;
    virtual bool Use(idEntity* user, int usableState);
    virtual void SetLocked(bool lock, idEntity* user);

    bool usableByAI;
    bool locked;
    bool canKickOpen;
    bool kickUnlocks;
    bool kickOffHinges;
    bool opensWhenUnlocked;
    bool forcedUnusable;
    bool forceUnusableWhenOpened;
    bool playerUsable;
    int triggerWhenOpenedCount;
    const idMaterial* displayIcon;
    const idMaterial* displayIconLocked;
    const idDeclInventory* requiredKey;
    bool removeKeyOnUse;
    const idSoundShader* lockedSound;
    const idSoundShader* unlockSound;
    const idDeclAiEvent* motionEventDecl;
    idList<idDoor_Base*, 5> linked;
    idSoundDoor* soundDoor;
    float kicked;
    idDoorState state;
    idBounds bounds;
    bool forceDormancyOnActivate;
};

class idDoor_Blocker {
public:
    idDoor_Blocker();

    static void SetServices(idDoorBaseServices* services) {
        idDoor_Base::SetServices(services);
    }

    bool IsEverUsable(const idEntity* activator) const;
    int GetUsableState(const idEntity* activator) const;
    void Spawn();
    bool IsCurrentlyUsable(const idEntity* activator) const;
    bool Use(idEntity* user, int usableState);
    bool ModifyCrosshairInfo(const idEntity* activator,
        int usable, idDoorCrosshairInfo& info) const;
    void Think();

    const idSoundShader* lockedSound;
    int displayStringIndex;
    bool isActuallyUseable;
    bool dontShowIconOnActuallyUseable;
    const idSoundShader* useSound;
    idStr availableJobDecl;
    int availableJobStatus;
    bool uniquelyRemoveable;
    bool hasCheckedForRemove;
    bool hasBeenUsed;
    idStr name;
    int thinkFlags;
    bool removed;
};
