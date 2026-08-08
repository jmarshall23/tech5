
// ========================================================================
// ?Spawn@idDoor_Base@@QAAXXZ
// EA  : 0x82C21D88
// RVA : 0x00C21D88
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Base::Spawn(idDoor_Base *this)
{
  idEventReceiver::PostEventMS(this, ev: &EV_LinkSoundDoor, time: 0);
}


// ========================================================================
// ?Event_GetLocked@idDoor_Base@@AAA?AVeventBool@@XZ
// EA  : 0x82C21D98
// RVA : 0x00C21D98
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_GetLocked(idDoor_Base *this, eventBool *result)
{
  eventBool::eventBool((eventBool *)this, b: result[5201].value);
  return this;
}


// ========================================================================
// ?HasKey@idDoor_Base@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C21DD0
// RVA : 0x00C21DD0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Base::HasKey(idDoor_Base *this, const idEntity *activator)
{
  idJobManager *v4; // r3

  return this->requiredKey != nullptr
      && (v4 = (idJobManager *)activator->GetInventory(this: activator)) != nullptr
      && idJobManager::FindJobByDecl(this: v4, jobDecl: (const idDeclJob *)this->requiredKey) != nullptr;
}


// ========================================================================
// ?IsCurrentlyUsable@idDoor_Base@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C21E48
// RVA : 0x00C21E48
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Base::IsCurrentlyUsable(idDoor_Base *this, const idEntity *activator)
{
  return ((unsigned __int8 (__fastcall *)(idDoor_Base *, double))this->IsLockedForEntity)(a1: this, a2: 0.0) == 0
      && this->IsEverUsable(this, a2: activator);
}


// ========================================================================
// ?IsLocked@idDoor_Base@@UBA_NXZ
// EA  : 0x82C21EC0
// RVA : 0x00C21EC0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Base::IsLocked(idDoor_Base *this)
{
  return this->locked;
}


// ========================================================================
// ?IsLockedForEntity@idDoor_Base@@UBA_NPBVidEntity@@M@Z
// EA  : 0x82C21EC8
// RVA : 0x00C21EC8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Base::IsLockedForEntity(idDoor_Base *this, const idEntity *ent, double kicked)
{
  idJobManager *v6; // r3

  if ( !this->locked )
    return false;
  if ( this->requiredKey != nullptr
    && ((int (__fastcall *)(const idEntity *, double))ent->GetInventory)(a1: ent, a2: kicked) != 0 )
  {
    v6 = (idJobManager *)ent->GetInventory(this: ent);
    if ( v6 != nullptr )
      return (_cntlzw((unsigned int)idJobManager::FindJobByDecl(this: v6, jobDecl: (const idDeclJob *)this->requiredKey))
            & 0x20) != 0;
  }
  return true;
}


// ========================================================================
// ?IsEverUsable@idDoor_Blocker@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C21F70
// RVA : 0x00C21F70
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Blocker::IsEverUsable(idDoor_Blocker *this, const idEntity *activator)
{
  return !this->isActuallyUseable || (_cntlzw(this->hasBeenUsed) & 0x20) != 0;
}


// ========================================================================
// ?GetUsableState@idDoor_Blocker@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C21F98
// RVA : 0x00C21F98
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

int __fastcall idDoor_Blocker::GetUsableState(idDoor_Blocker *this, idPlayer *activator, const idFocusTrace *ft)
{
  return idPlayer::CastTo(c: activator) == nullptr ? 0 : 7;
}


// ========================================================================
// ?Spawn@idDoor_Blocker@@QAAXXZ
// EA  : 0x82C21FD0
// RVA : 0x00C21FD0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Blocker::Spawn(idDoor_Blocker *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r31

  Physics = idEntity::GetPhysics(this);
  v3 = Physics;
  if ( Physics != nullptr )
  {
    Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
    v3->EnableClip(this: v3);
  }
  if ( this->uniquelyRemoveable )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?UpdateAASAreas@idDoor_Base@@MAAXXZ
// EA  : 0x82C22058
// RVA : 0x00C22058
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Base::UpdateAASAreas(idDoor_Base *this)
{
  idDoor_Base::doorState_t state; // r11
  bool locked; // r7

  state = this->state;
  if ( this->usableByAI )
  {
    if ( state == DOOR_CLOSED )
    {
      locked = this->locked;
      goto LABEL_7;
    }
LABEL_6:
    locked = false;
    goto LABEL_7;
  }
  if ( state == DOOR_OPENED )
    goto LABEL_6;
  locked = true;
  if ( state == DOOR_BROKEN )
    goto LABEL_6;
LABEL_7:
  idGameLocal::ChangeAreaTravelFlags(
    this: gameLocal,
    bounds: &this->bounds,
    areaFlags: 2048,
    travelFlags: 1,
    set: locked);
}


// ========================================================================
// ?Event_Open@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C220A8
// RVA : 0x00C220A8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_Open(idDoor_Base *this, eventVoid *result, idEntity *user)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)result + 676))(a1: result) != 0 )
    (*(void (__fastcall **)(eventVoid *, idEntity *, int))(*(_DWORD *)result + 456))(a1: result, a2: user, a3: 7);
  return this;
}


// ========================================================================
// ?Event_Close@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C22108
// RVA : 0x00C22108
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_Close(idDoor_Base *this, eventVoid *result, idEntity *user)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)result + 672))(a1: result) != 0 )
    (*(void (__fastcall **)(eventVoid *, idEntity *, int))(*(_DWORD *)result + 456))(a1: result, a2: user, a3: 7);
  return this;
}


// ========================================================================
// ?Event_KickOpen@idDoor_Base@@AAA?AVeventVoid@@PAVidEntity@@M@Z
// EA  : 0x82C22168
// RVA : 0x00C22168
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_KickOpen(
        idDoor_Base *this,
        eventVoid *result,
        idEntity *user,
        double forceScale)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)result + 676))(a1: result) != 0 )
  {
    *(float *)&result[5264] = forceScale;
    (*(void (__fastcall **)(eventVoid *, idEntity *, int))(*(_DWORD *)result + 456))(a1: result, a2: user, a3: 7);
    *(float *)&result[5264] = 0.0;
  }
  return this;
}


// ========================================================================
// ?OnActivate@idDoor_Base@@EAAXPAVidEntity@@@Z
// EA  : 0x82C221E8
// RVA : 0x00C221E8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Base::OnActivate(idDoor_Base *this, idEntity *activator)
{
  const idDeclInventory *requiredKey; // r29
  idJobManager *v5; // r3

  if ( (*((_BYTE *)&this->flags + 1) & 0x80) != 0 )
    idEntity::ForceDormancy(this, dormant: false, durationMS: 30000);
  if ( this->locked )
  {
    if ( this->requiredKey == nullptr
      || activator->GetInventory_2(this: activator) != nullptr
      && (requiredKey = this->requiredKey,
          v5 = (idJobManager *)activator->GetInventory_2(this: activator),
          idJobManager::FindJobByDecl(this: v5, jobDecl: (const idDeclJob *)requiredKey) != nullptr) )
    {
      this->SetLocked(this, a2: false, a3: activator);
    }
  }
}


// ========================================================================
// ?Event_SetLocked@idDoor_Base@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C22298
// RVA : 0x00C22298
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_SetLocked(idDoor_Base *this, eventVoid *result, int lock)
{
  (*(void (__fastcall **)(eventVoid *, bool, _DWORD))(*(_DWORD *)result + 700))(a1: result, a2: lock != 0, a3: 0);
  return this;
}


// ========================================================================
// ?Event_SetForcedUnusable@idDoor_Base@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C222F0
// RVA : 0x00C222F0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idDoor_Base::Event_SetForcedUnusable@<r4>(idDoor_Base *this@<r3>, int result@<r4>, int lock@<r5>)
{
  *(_BYTE *)(result + 5206) = lock != 0;
  return result;
}


// ========================================================================
// ?IsEverUsable@idDoor_Base@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C22300
// RVA : 0x00C22300
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Base::IsEverUsable(idDoor_Base *this, const idEntity *activator)
{
  return this->state != DOOR_BROKEN && (_cntlzw(this->forcedUnusable) & 0x20) != 0;
}


// ========================================================================
// ?GetUsableState@idDoor_Base@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C22328
// RVA : 0x00C22328
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

usableState_t __fastcall idDoor_Base::GetUsableState(
        idDoor_Base *this,
        const idEntity *activator,
        const idFocusTrace *ft)
{
  usableState_t result; // r3
  bool v5; // zf

  if ( this->state == DOOR_BROKEN || !this->playerUsable )
    return USABLE_NOT_USABLE;
  if ( ((unsigned __int8 (__fastcall *)(idDoor_Base *, const idEntity *, const idFocusTrace *))this->IsOpen)(
         a1: this,
         a2: activator,
         a3: ft) == 0 )
    return USABLE_DOOR;
  v5 = !this->CanClose(this, a2: true);
  result = USABLE_NOT_USABLE;
  if ( !v5 )
    return USABLE_DOOR;
  return result;
}


// ========================================================================
// ?GetOnlineUsableState@idDoor_Base@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C223D0
// RVA : 0x00C223D0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

usableState_t __fastcall idDoor_Base::GetOnlineUsableState(idDoor_Base *this)
{
  usableState_t result; // r3
  bool v3; // zf

  if ( this->state == DOOR_BROKEN )
    return USABLE_NOT_USABLE;
  if ( !this->IsOpen(this) )
    return USABLE_DOOR;
  v3 = !this->CanClose(this, a2: true);
  result = USABLE_NOT_USABLE;
  if ( !v3 )
    return USABLE_DOOR;
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idDoor_Base@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C22468
// RVA : 0x00C22468
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

int __fastcall idDoor_Base::ModifyCrosshairInfo(
        idDoor_Base *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  const idDeclInventory *requiredKey; // r11
  idCrosshairCustomIcon *list; // r10

  if ( !idEntity::ModifyCrosshairInfo(this, activator, ft, usable, info)
    || this->IsOpen(this) && !this->CanClose(this, a2: true) )
  {
    return 0;
  }
  if ( !this->IsLockedForEntity(this, a2: activator, a3: 0.0) || this->HasKey(this, a2: activator) )
  {
    info->icons.list->material = this->displayIcon;
    return 1;
  }
  else
  {
    requiredKey = this->requiredKey;
    if ( requiredKey != nullptr && requiredKey->requiredName.index >= 0 )
    {
      info->material = CHMATERIAL_DOOR;
      info->text.index = this->requiredKey->requiredName.index;
    }
    else
    {
      info->material = CHMATERIAL_DOOR_LOCKED;
    }
    list = info->icons.list;
    info->textColorState = CROSSHAIR_TEXT_COLOR_NEGATIVE;
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
    list->material = this->displayIconLocked;
    return 1;
  }
}


// ========================================================================
// ?Event_SetPlayerUsable@idDoor_Base@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C225A8
// RVA : 0x00C225A8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idDoor_Base::Event_SetPlayerUsable@<r4>(idDoor_Base *this@<r3>, int result@<r4>, const int usable@<r5>)
{
  *(_BYTE *)(result + 5208) = usable != 0;
  return result;
}


// ========================================================================
// ??0idDoor_Blocker@@QAA@XZ
// EA  : 0x82C225B8
// RVA : 0x00C225B8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Blocker *__fastcall idDoor_Blocker::idDoor_Blocker(idDoor_Blocker *this)
{
  idEntity::idEntity(this);
  this->locked_sound = nullptr;
  this->__vftable = (idDoor_Blocker_vtbl *)&idDoor_Blocker::`vftable';
  this->displayString.index = -1;
  this->isActuallyUseable = false;
  this->dontShowIconOnActuallyUseable = false;
  this->useSound = nullptr;
  this->availableJobDecl.allocedAndFlag = 20;
  this->availableJobDecl.data = this->availableJobDecl.baseBuffer;
  this->availableJobDecl.len = 0;
  this->availableJobDecl.baseBuffer[0] = 0;
  this->availableJobStatus = JOBSTATUS_COMPLETED;
  this->uniquelyRemoveable = false;
  this->hasCheckedForRemove = false;
  this->hasBeenUsed = false;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  return this;
}


// ========================================================================
// ?IsCurrentlyUsable@idDoor_Blocker@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C226C0
// RVA : 0x00C226C0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

BOOL __fastcall idDoor_Blocker::IsCurrentlyUsable(idDoor_Blocker *this, const idEntity *activator)
{
  int v4; // r30
  const idPlayer *PlayerFromEntity; // r3
  idJob *InventoryItemByDeclName; // r3

  if ( !this->isActuallyUseable )
    return this->locked_sound != nullptr;
  if ( this->hasBeenUsed )
    return false;
  v4 = 1;
  if ( this->availableJobDecl.len != 0 )
  {
    v4 = 0;
    PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
    if ( PlayerFromEntity != nullptr )
    {
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this: &PlayerFromEntity->jobManager,
                                  jobName: this->availableJobDecl.data);
      if ( InventoryItemByDeclName != nullptr )
        return InventoryItemByDeclName->status >= this->availableJobStatus;
    }
  }
  return v4;
}


// ========================================================================
// ?Use@idDoor_Blocker@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C22778
// RVA : 0x00C22778
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

int __fastcall idDoor_Blocker::Use(idDoor_Blocker *this, idEntity *user, usableState_t usable)
{
  idPlayer *PlayerFromEntity; // r3
  idPlayer *v6; // r30
  const idSoundShader *useSound; // r5

  if ( !this->isActuallyUseable )
    goto LABEL_9;
  if ( this->hasBeenUsed
    || ((unsigned __int8 (__fastcall *)(idDoor_Blocker *, idEntity *, usableState_t))this->IsCurrentlyUsable)(
         a1: this,
         a2: user,
         a3: usable) == 0 )
  {
    if ( this->hasBeenUsed )
      return 0;
LABEL_9:
    idEntity::StartSoundShader(
      this: user,
      channel: SND_CHANNEL_ANY,
      shader: this->locked_sound,
      soundShaderFlags: 0,
      peerMask: 0);
    return 0;
  }
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: user);
  v6 = PlayerFromEntity;
  if ( PlayerFromEntity == nullptr )
    return 0;
  this->ActivateTargets(this, a2: PlayerFromEntity);
  useSound = this->useSound;
  this->hasBeenUsed = true;
  if ( useSound != nullptr )
    idPlayer::PlayLocalSound(this: v6, channel: SND_CHANNEL_ALERT, shader: useSound, soundShaderFlags: 0);
  return 1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idDoor_Blocker@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C22868
// RVA : 0x00C22868
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

int __fastcall idDoor_Blocker::ModifyCrosshairInfo(
        idDoor_Blocker *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  crosshairTextColorState_t v7; // r11
  float a; // r4

  if ( this->isActuallyUseable )
  {
    if ( this->dontShowIconOnActuallyUseable )
    {
      info->material = CHMATERIAL_DEFAULT;
    }
    else
    {
      if ( ((unsigned __int8 (__fastcall *)(idDoor_Blocker *, const idEntity *, const idFocusTrace *, usableState_t))this->IsCurrentlyUsable)(
             a1: this,
             a2: activator,
             a3: ft,
             a4: usable) != 0 )
      {
        v7 = CROSSHAIR_TEXT_COLOR_NORMAL;
        info->color = idCrosshairInfo::DEFAULT_COLOR;
        info->colorState = CROSSHAIR_COLOR_NORMAL;
        info->textColor = idCrosshairInfo::DEFAULT_TEXT_COLOR;
      }
      else
      {
        v7 = CROSSHAIR_TEXT_COLOR_NEGATIVE;
        info->color = idColor::colorRed;
        info->colorState = CROSSHAIR_COLOR_NEGATIVE;
      }
      info->textColorState = v7;
      info->material = CHMATERIAL_DOOR;
      info->text.index = this->displayString.index;
    }
  }
  else
  {
    info->color.r = idColor::colorRed.r;
    info->color.g = idColor::colorRed.g;
    info->color.b = idColor::colorRed.b;
    a = idColor::colorRed.a;
    info->material = CHMATERIAL_DOOR_LOCKED;
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
    info->textColorState = CROSSHAIR_TEXT_COLOR_NEGATIVE;
    info->color.a = a;
    info->text.index = this->displayString.index;
  }
  return 1;
}


// ========================================================================
// ?Think@idDoor_Blocker@@UAAXXZ
// EA  : 0x82C229D0
// RVA : 0x00C229D0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Blocker::Think(idDoor_Blocker *this)
{
  idPlayer *DebugPlayer; // r3

  idEntity::Think(this);
  if ( !this->hasCheckedForRemove )
  {
    this->hasCheckedForRemove = true;
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr
      && (unsigned __int8)idGameLayerManager::ContainsItemMemory(
                            this: &DebugPlayer->gameLayerManager,
                            itemName: this->name.data) != 0 )
    {
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
    else
    {
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ??0idDoor_Base@@QAA@XZ
// EA  : 0x82C22A78
// RVA : 0x00C22A78
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::idDoor_Base(idDoor_Base *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->usableByAI = false;
  this->locked = false;
  this->__vftable = (idDoor_Base_vtbl *)&idDoor_Base::`vftable';
  this->canKickOpen = false;
  this->kickUnlocks = false;
  this->kickOffHinges = false;
  this->opensWhenUnlocked = false;
  this->forcedUnusable = false;
  *(_WORD *)&this->forceUnusableWhenOpened = 1;
  this->triggerWhenOpenedCount = 1;
  this->displayIcon = nullptr;
  this->displayIconLocked = nullptr;
  this->requiredKey = nullptr;
  this->removeKeyOnUse = false;
  this->locked_sound = nullptr;
  this->unlock_sound = nullptr;
  this->linked.list = nullptr;
  this->linked.granularity = 0;
  this->linked.memTag = 5;
  this->linked.listStatic = 0;
  this->linked.size = 0;
  this->linked.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->linked);
  this->soundDoor = nullptr;
  this->state = DOOR_UNKNOWN;
  this->kicked = 0.0;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  idEntity::SetClipReplicationFlags(this, dynamicClipReplication: true, dynamicClipReplicationAxis: true);
  this->motionEventDecl = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                                   this: &idDeclAiEvent::resourceList,
                                                   name: "base/sound/doormotion",
                                                   makeDefault: true);
  return this;
}


// ========================================================================
// __unwind$489379
// EA  : 0x82C22B90
// RVA : 0x00C22B90
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void _unwind_489379()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489380
// EA  : 0x82C22BB8
// RVA : 0x00C22BB8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void _unwind_489380()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5244));
}


// ========================================================================
// ?DrawDebugInfo@idDoor_Base@@SAXXZ
// EA  : 0x82C22BE8
// RVA : 0x00C22BE8
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

static void __fastcall idDoor_Base::DrawDebugInfo()
{
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  idPlayer *v2; // r3
  idPhysics *v3; // r3
  float *v4; // r3
  double v5; // fp31
  double v6; // fp30
  double v7; // fp29
  idLinkList<idEntity> *next; // r11
  double v9; // fp28
  double v10; // fp27
  double v11; // fp26
  idDoor_Base *i; // r22
  idDoor_Base *v13; // r3
  idDoor_Base *v14; // r30
  idPhysics *v15; // r3
  idPhysics *v16; // r31
  float *v17; // r3
  char v18; // r11
  const idBounds *v19; // r3
  float *v20; // r3
  double v21; // fp8
  double v22; // fp7
  double v23; // fp5
  idPhysics *v24; // r3
  idRenderWorld *renderWorld; // r31
  const idBounds *(__fastcall *GetAbsBounds)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v27; // r21
  int v28; // r3
  idPhysics *v29; // r3
  int v30; // r3
  __int64 v31; // r10
  int v32; // r31
  __int64 v33; // r6
  __int64 v34; // r8
  va *v35; // r3
  idLinkList<idEntity> *v36; // r11
  int v37; // [sp+8h] [-1138h]
  int v38; // [sp+Ch] [-1134h]
  int v39; // [sp+10h] [-1130h]
  int v40; // [sp+14h] [-112Ch]
  int v41; // [sp+18h] [-1128h]
  int v42; // [sp+1Ch] [-1124h]
  float v43; // [sp+60h] [-10E0h] BYREF
  float v44; // [sp+64h] [-10DCh]
  float v45; // [sp+68h] [-10D8h]
  float v46; // [sp+6Ch] [-10D4h]
  float v47; // [sp+70h] [-10D0h]
  float v48; // [sp+74h] [-10CCh]
  idBounds v49; // [sp+80h] [-10C0h] BYREF
  va v50; // [sp+A0h] [-10A0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  Physics = idEntity::GetPhysics(this: DebugPlayer);
  Physics->GetOrigin(this: Physics, a2: 0);
  v2 = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = idEntity::GetPhysics(this: v2);
  v4 = (float *)v3->GetOrigin(this: v3, a2: 0);
  v5 = (float)(*v4 - (float)512.0);
  v6 = (float)(v4[1] - (float)512.0);
  v7 = (float)(v4[2] - (float)512.0);
  next = gameLocal->spawnedEntities.next;
  v9 = (float)(*v4 + (float)512.0);
  v10 = (float)(v4[1] + (float)512.0);
  v11 = (float)(v4[2] + (float)512.0);
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    for ( i = (idDoor_Base *)next->owner; i != nullptr; i = (idDoor_Base *)v36->owner )
    {
      v13 = idDoor_Base::CastTo(c: i);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = idEntity::GetPhysics(this: v13);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = (float *)v15->GetAbsBounds(this: v15, a2: -1);
          if ( v17[3] < v5 || v17[4] < v6 || v17[5] < v7 || *v17 > v9 || v17[1] > v10 || (v18 = 1, v17[2] > v11) )
            v18 = 0;
          if ( v18 != 0 )
          {
            v19 = v16->GetAbsBounds(this: v16, a2: -1);
            v20 = (float *)idBounds::operator+(this: &v49, result: &v14->bounds, a: v19);
            v43 = *v20;
            v44 = v20[1];
            v45 = v20[2];
            v21 = (float)(v20[3] + g_doorClosingRange.valueFloat);
            v46 = v20[3];
            v22 = (float)(v20[4] + g_doorClosingRange.valueFloat);
            v47 = v20[4];
            v23 = (float)(v20[5] + g_doorClosingRange.valueFloat);
            v43 = v43 - g_doorClosingRange.valueFloat;
            v44 = v44 - g_doorClosingRange.valueFloat;
            v45 = v45 - g_doorClosingRange.valueFloat;
            v46 = v21;
            v47 = v22;
            v48 = v23;
            clientGame->renderWorld->DebugBounds(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorOrange,
              a3: (const idBounds *)&v43,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            v24 = v16;
            GetAbsBounds = v16->GetAbsBounds;
            renderWorld = clientGame->renderWorld;
            v27 = renderWorld->__vftable;
            v28 = (int)GetAbsBounds(this: v24, a2: -1);
            v27->DebugBounds(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorYellow,
              a3: (const idBounds *)v28,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            if ( v14->requiredKey != nullptr )
            {
              v29 = idEntity::GetPhysics(this: v14);
              v30 = (int)v29->GetOrigin(this: v29, a2: 0);
              HIDWORD(v31) = v14->requiredKey;
              v32 = v30;
              HIDWORD(v33) = *(_DWORD *)(HIDWORD(v31) + 8);
              v35 = va::va(
                      this: &v50,
                      fmt: "Key: %s",
                      a3: v33,
                      a4: v34,
                      a5: v31,
                      a6: v37,
                      a7: v38,
                      a8: v39,
                      a9: v40,
                      a10: v41,
                      a11: v42);
              ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                a1: clientGame->renderWorld,
                a2: v35,
                a3: v32,
                a4: clientGame->renderWorld->__vftable,
                a5: &idColor::colorYellow,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 1.0);
            }
          }
        }
      }
      v36 = i->spawnNode.next;
      if ( v36 == nullptr )
        break;
      if ( v36 == i->spawnNode.head )
        break;
    }
  }
}


// ========================================================================
// ?SetDoorState@idDoor_Base@@QAAXPAVidEntity@@W4doorState_t@1@@Z
// EA  : 0x82C22F18
// RVA : 0x00C22F18
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Base::SetDoorState(idDoor_Base *this, idDoor_Base *activator, __int32 s)
{
  idDoor_Base::doorState_t state; // r11
  idEntity *v5; // r24
  int triggerWhenOpenedCount; // r11
  int v8; // r27
  int v9; // r28
  int value; // r9
  idEntity *v11; // r3
  idDoor_Base *v12; // r3
  idDoor_Base *v13; // r30
  idEventArg *v14; // r3
  const idEventDef *v15; // r4
  idPhysics *Physics; // r3
  idPhysics *v17; // r30
  idDoor_Base::doorState_t v18; // r11
  int v19; // r4
  eventVoid *soundDoor; // r4
  _BYTE v21[16]; // [sp+50h] [-80h] BYREF
  idEventArg v22[5]; // [sp+60h] [-70h] BYREF

  state = this->state;
  v5 = activator;
  if ( state != s && s == 3 && state == DOOR_CLOSED )
  {
    triggerWhenOpenedCount = this->triggerWhenOpenedCount;
    if ( triggerWhenOpenedCount >= 0 )
    {
      if ( triggerWhenOpenedCount <= 0 )
        goto LABEL_10;
      this->triggerWhenOpenedCount = triggerWhenOpenedCount - 1;
    }
    if ( activator == nullptr )
      activator = this;
    this->ActivateTargets(this, a2: activator);
  }
LABEL_10:
  v8 = 0;
  if ( this->linked.num > 0 )
  {
    v9 = 0;
    do
    {
      value = this->linked.list[v9].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v11 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v11 == nullptr )
          goto LABEL_23;
        v12 = (idDoor_Base *)idEntity::CastTo(c: v11);
        if ( v12 == nullptr )
          goto LABEL_23;
        v13 = idDoor_Base::CastTo(c: v12);
        if ( v13 == nullptr )
          goto LABEL_23;
        if ( s == 3 || s == 4 )
        {
          v14 = idEventArg::idEventArg(this: v22, data: v5);
          v15 = &EV_Open;
        }
        else
        {
          if ( s != 1 && s != 2 )
            goto LABEL_23;
          v14 = idEventArg::idEventArg(this: v22, data: v5);
          v15 = &EV_Close;
        }
        idEventReceiver::PostEventMS(
          this: v13,
          ev: v15,
          time: *(_DWORD *)&v14->type,
          arg1: (const idEventArg *)v14->value.i);
      }
LABEL_23:
      ++v8;
      ++v9;
    }
    while ( v8 < this->linked.num );
  }
  this->InternalSetDoorState(this, a2: v5, a3: (const idDoor_Base::doorState_t)s);
  Physics = idEntity::GetPhysics(this);
  v17 = Physics;
  if ( this->usableByAI )
  {
    v18 = this->state;
    if ( s != v18 && Physics != nullptr )
    {
      if ( s == 2 )
      {
        if ( v18 != DOOR_CLOSED && !this->IsLocked(this) )
        {
          v19 = 1;
LABEL_34:
          v17->SetContents(this: v17, a2: v19, a3: -1);
        }
      }
      else if ( s == 4 && v18 != DOOR_OPENED )
      {
        v19 = 131073;
        goto LABEL_34;
      }
    }
  }
  this->state = s;
  this->UpdateAASAreas(this);
  soundDoor = (eventVoid *)this->soundDoor;
  if ( soundDoor != nullptr )
  {
    if ( s == 2 || s == 1 )
      idSoundDoor::Event_Close(this: (idSoundDoor *)v21, result: soundDoor, user: this);
    else
      idSoundDoor::Event_Open(this: (idSoundDoor *)v21, result: soundDoor, user: this);
  }
}


// ========================================================================
// ?Event_LinkSoundDoor@idDoor_Base@@AAA?AVeventVoid@@XZ
// EA  : 0x82C23190
// RVA : 0x00C23190
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

idDoor_Base *__fastcall idDoor_Base::Event_LinkSoundDoor(idDoor_Base *this, idDoor_Base *result)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r31
  int v7; // r3
  char *v8; // r10
  _DWORD *v9; // r11
  int i; // ctr
  idPresentable *presentable; // r11
  float *p_referenceBounds; // r11
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  double v17; // fp27
  double v18; // fp26
  float *v19; // r3
  double v20; // fp13
  double v21; // fp11
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  idLinkList<idEntity> *next; // r11
  idSoundDoor *owner; // r31
  idSoundDoor *v27; // r3
  idEntity *v28; // r30
  idPhysics *v29; // r3
  const idVec3 *v30; // r3
  idLinkList<idEntity> *v31; // r11
  char v32; // [sp+5Ch] [-74h] BYREF
  idBounds v33; // [sp+60h] [-70h] BYREF

  Physics = idEntity::GetPhysics(this: result);
  v5 = Physics;
  if ( Physics != nullptr )
  {
    if ( result->presentable != nullptr )
    {
      v7 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
      v8 = &v32;
      v9 = (_DWORD *)(v7 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v9;
        v8 += 4;
        *(_DWORD *)v8 = *v9;
      }
      if ( (COERCE_UNSIGNED_INT(fabs(v33.b[1].y - v33.b[0].y))
          | COERCE_UNSIGNED_INT(fabs(v33.b[1].z - v33.b[0].z))
          | COERCE_UNSIGNED_INT(fabs(v33.b[1].x - v33.b[0].x))) == 0 )
      {
        presentable = result->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          presentable = result->presentable;
        }
        p_referenceBounds = (float *)&presentable->model->referenceBounds;
        v13 = *p_referenceBounds;
        v14 = p_referenceBounds[1];
        v15 = p_referenceBounds[2];
        v16 = p_referenceBounds[3];
        v17 = p_referenceBounds[4];
        v18 = p_referenceBounds[5];
        v19 = (float *)v5->GetOrigin(this: v5, a2: 0);
        v20 = v19[1];
        v21 = v19[2];
        v22 = (float)(v19[1] + (float)v14);
        v23 = (float)(v19[2] + (float)v15);
        v24 = (float)(*v19 + (float)v16);
        v33.b[0].x = *v19 + (float)v13;
        v33.b[0].y = v22;
        v33.b[0].z = v23;
        v33.b[1].x = v24;
        v33.b[1].y = (float)v20 + (float)v17;
        v33.b[1].z = (float)v21 + (float)v18;
      }
      next = gameLocal->spawnedEntities.next;
      if ( next != nullptr && next != gameLocal->spawnedEntities.head )
      {
        owner = (idSoundDoor *)next->owner;
        if ( owner != nullptr )
        {
          while ( 1 )
          {
            v27 = idSoundDoor::CastTo(c: owner);
            v28 = v27;
            if ( v27 != nullptr && idEntity::GetPhysics(this: v27) != nullptr )
            {
              v29 = idEntity::GetPhysics(this: v28);
              v30 = v29->GetOrigin(this: v29, a2: 0);
              if ( (unsigned __int8)idBounds::ContainsPoint(this: &v33, p: v30) != 0 )
                break;
            }
            v31 = owner->spawnNode.next;
            if ( v31 == nullptr || v31 == owner->spawnNode.head )
              return this;
            owner = (idSoundDoor *)v31->owner;
            if ( owner == nullptr )
              return this;
          }
          result->soundDoor = (idSoundDoor *)v28;
          idDoor_Base::SetDoorState(this: result, activator: result, s: result->state);
        }
      }
      return this;
    }
    else
    {
      idLib::Warning(fmt: "iDoor_Base::Event_LinkSoundDoor '%s' has no presentable", result->name.data);
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "iDoor_Base '%s' does not have any physics, door will not function properly", result->name.data);
    return this;
  }
}


// ========================================================================
// ?UpdateState@idDoor_Base@@IAAXXZ
// EA  : 0x82C234D0
// RVA : 0x00C234D0
// PDB : w:\tech5\tungsten\game\entities\door_base.cpp
// ========================================================================

void __fastcall idDoor_Base::UpdateState(idDoor_Base *this)
{
  __int32 v2; // r5

  if ( this->state != DOOR_BROKEN )
  {
    if ( this->IsClosed(this) && this->state != DOOR_CLOSED )
    {
      v2 = 2;
LABEL_8:
      idDoor_Base::SetDoorState(this, activator: this, s: v2);
      return;
    }
    if ( this->IsOpen(this) && this->state != DOOR_OPENED )
    {
      v2 = 4;
      goto LABEL_8;
    }
  }
}

