
// ========================================================================
// ??1idPresentableProp@@UAA@XZ
// EA  : 0x82B8D9C0
// RVA : 0x00B8D9C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

void __fastcall idPresentableProp::~idPresentableProp(idPresentableProp *this)
{
  this->__vftable = (idPresentableProp_vtbl *)&idPresentableProp::`vftable';
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// ?InternalPickupProp@idPresentableProp@@AAAXPAVidPresentable@@@Z
// EA  : 0x82B8D9D0
// RVA : 0x00B8D9D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

void __fastcall idPresentableProp::InternalPickupProp(idPresentableProp *this, idPresentable *activator)
{
  idPresentable *PresentableByIndex; // r3
  idPresentableProp *v5; // r30
  const idSoundShader *pickupSound; // r5
  idPresentableProp *v7; // r3
  idPresentableVehicle *v8; // r3

  idPresentable::LocalStopAllFX(this);
  if ( this->pickupSound != nullptr && this->shouldPlayPickupSound )
  {
    if ( idClientGame::IsPresentableIndexValid(this: clientGame, index: this->pickupEventInfo.presentableIndex)
      && (PresentableByIndex = idClientGame::GetPresentableByIndex(
                                 this: clientGame,
                                 index: this->pickupEventInfo.presentableIndex),
          v5 = (idPresentableProp *)PresentableByIndex,
          PresentableByIndex != nullptr) )
    {
      idPresentable::StopSound(this: PresentableByIndex, channel: SND_CHANNEL_CRASH, peerMask: 0);
      pickupSound = this->pickupSound;
      v7 = v5;
    }
    else
    {
      idPresentable::StopSound(this, channel: SND_CHANNEL_CRASH, peerMask: 0);
      pickupSound = this->pickupSound;
      v7 = this;
    }
    idPresentable::StartSoundShader(
      this: v7,
      channel: SND_CHANNEL_CRASH,
      shader: pickupSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0);
  }
  this->Hide(this, a2: false);
  idPresentable::SetLocalClipModelContents(this, newContents: 0);
  this->LocalStartFX(this, a2: FX_PROP_PICKUP);
  if ( this->specialType != SPECIAL_PROP_NONE )
  {
    if ( activator != nullptr && activator->GetVehicleInterface(this: activator) != nullptr )
    {
      v8 = activator->GetVehicleInterface(this: activator);
      idPresentableVehicle::StartPredictedFX(this: v8, cond: FX_VEH_RALLY_CAP, extraCondition: FX_EXTRA_COND_NONE);
    }
    if ( this->specialType == SPECIAL_PROP_RALLY )
    {
      this->LocalStartFX(this, a2: FX_TOUCH_MARKER);
      idPresentable::LocalStopFX(this, condition: 43);
    }
  }
}


// ========================================================================
// ??0idPresentableProp@@QAA@PAVidProp@@PAVidRenderModel@@PAVidAnimStack@@HPBVidDeclFX@@_NPBVidDeclInventory@@4@Z
// EA  : 0x82B8DBA8
// RVA : 0x00B8DBA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

idPresentableProp *__fastcall idPresentableProp::idPresentableProp(
        idPresentableProp *this,
        idProp *e,
        idRenderModel *renderModel_,
        idAnimStack *animStack_,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_,
        const idDeclInventory *inventoryDecl_,
        bool isUsable_,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        bool a28)
{
  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent: e,
    renderModel_,
    animStack_,
    entityNumber_,
    fxDecl_,
    useSphereModel_);
  this->__vftable = (idPresentableProp_vtbl *)&idPresentableProp::`vftable';
  this->resetPickup.count = 0;
  this->resetPickup.lastCount = 0;
  this->pickupEventInfo.eventTime = 0;
  this->pickupEventInfo.lastHandledEventTime = 0;
  this->pickupEventInfo.playerIndex = 0;
  this->pickupEventInfo.presentableIndex = -1;
  this->pickupSound = nullptr;
  this->shouldPlayPickupSound = true;
  this->predictedPickup = false;
  this->pickupOnTouch = false;
  this->pickupOnUse = false;
  this->specialType = SPECIAL_PROP_NONE;
  this->inventoryDecl = inventoryDecl_;
  this->isUsable = a28;
  this->clipModelDynamic = true;
  this->clipModelDynamicAxis = true;
  return this;
}


// ========================================================================
// ?ClientPredict@idPresentableProp@@UAAXHM@Z
// EA  : 0x82B8DC40
// RVA : 0x00B8DC40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

void __fastcall idPresentableProp::ClientPredict(idPresentableProp *this, int curTime, double fraction)
{
  BOOL predictedPickup; // r10

  if ( gameLocal->numSnapshotsSerialized >= 10 )
  {
    if ( this->pickupEventInfo.lastHandledEventTime != this->pickupEventInfo.eventTime )
    {
      if ( !this->predictedPickup )
        idPresentableProp::InternalPickupProp(this, activator: nullptr);
      this->predictedPickup = false;
    }
  }
  else if ( this->hidden )
  {
    idPresentable::LocalStopAllFX(this);
  }
  predictedPickup = this->predictedPickup;
  this->pickupEventInfo.lastHandledEventTime = this->pickupEventInfo.eventTime;
  if ( predictedPickup )
  {
    ((void (__fastcall *)(idPresentableProp *, _DWORD, double))this->Hide)(a1: this, a2: 0, a3: fraction);
    idPresentable::SetLocalClipModelContents(this, newContents: 0);
  }
}


// ========================================================================
// ?GetOnlineUsableText@idPresentableProp@@UBA?AVidStrId@@XZ
// EA  : 0x82B8DD00
// RVA : 0x00B8DD00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

idPresentableProp *__fastcall idPresentableProp::GetOnlineUsableText(idPresentableProp *this, idStrId *result)
{
  int index; // r11

  index = result[318].index;
  if ( index != 0 )
    this->__vftable = *(idPresentableProp_vtbl **)(index + 164);
  else
    this->__vftable = (idPresentableProp_vtbl *)-1;
  return this;
}


// ========================================================================
// ?Serialize@idPresentableProp@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B8DD28
// RVA : 0x00B8DD28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

void __fastcall idPresentableProp::Serialize(idPresentableProp *this, idSerializer *ser)
{
  netBoolEvent_t *p_resetPickup; // r29
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int lastCount; // r10
  char v11; // r11
  idBitMsg *msg; // r3
  idBitMsg *v13; // r3
  unsigned int v14; // r10
  idBitMsg *v15; // r3
  bool isUsable; // r29
  idBitMsg *v17; // r3
  bool shouldPlayPickupSound; // r29
  idBitMsg *v19; // r3
  bool pickupOnTouch; // r29
  idBitMsg *v21; // r3
  bool pickupOnUse; // r29
  idBitMsg *v23; // r3

  p_resetPickup = &this->resetPickup;
  netBoolEvent_t::Serialize(this: &this->resetPickup, ser);
  if ( !ser->writing )
  {
    lastCount = p_resetPickup->lastCount;
    if ( p_resetPickup->count == lastCount )
    {
      v11 = 0;
    }
    else
    {
      p_resetPickup->lastCount = p_resetPickup->count;
      v11 = 1;
    }
    if ( v11 != 0 )
    {
      this->predictedPickup = false;
      idPresentable::SetClipModelContents(this, newContents: 0, a3: v9, a4: v8, a5: v7, a6: v6, a7: v5, a8: lastCount);
    }
  }
  idPresentableAnimatedEntity::Serialize(this, ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->pickupEventInfo.eventTime, numBits: 32);
  else
    this->pickupEventInfo.eventTime = idBitMsg::ReadBits(this: msg, numBits: 32);
  v13 = ser->msg;
  v14 = _cntlzw(6u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: this->pickupEventInfo.playerIndex, numBits: 32 - v14);
  else
    this->pickupEventInfo.playerIndex = idBitMsg::ReadBits(this: v13, numBits: 32 - v14);
  v15 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v15, value: this->pickupEventInfo.presentableIndex, numBits: 32);
  else
    this->pickupEventInfo.presentableIndex = idBitMsg::ReadBits(this: v15, numBits: 32);
  isUsable = this->isUsable;
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: this->isUsable, numBits: 1);
  else
    isUsable = (_cntlzw(idBitMsg::ReadBits(this: v17, numBits: 1) - 1) & 0x20) != 0;
  this->isUsable = isUsable;
  shouldPlayPickupSound = this->shouldPlayPickupSound;
  v19 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v19, value: this->shouldPlayPickupSound, numBits: 1);
  else
    shouldPlayPickupSound = (_cntlzw(idBitMsg::ReadBits(this: v19, numBits: 1) - 1) & 0x20) != 0;
  this->shouldPlayPickupSound = shouldPlayPickupSound;
  pickupOnTouch = this->pickupOnTouch;
  v21 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v21, value: this->pickupOnTouch, numBits: 1);
  else
    pickupOnTouch = (_cntlzw(idBitMsg::ReadBits(this: v21, numBits: 1) - 1) & 0x20) != 0;
  this->pickupOnTouch = pickupOnTouch;
  pickupOnUse = this->pickupOnUse;
  v23 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v23, value: this->pickupOnUse, numBits: 1);
  else
    pickupOnUse = (_cntlzw(idBitMsg::ReadBits(this: v23, numBits: 1) - 1) & 0x20) != 0;
  this->pickupOnUse = pickupOnUse;
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->pickupSound);
  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->inventoryDecl);
}


// ========================================================================
// ?GetPlayerIndex@idPresentableProp@@AAAHPAVidPresentable@@@Z
// EA  : 0x82B8DF40
// RVA : 0x00B8DF40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

int __fastcall idPresentableProp::GetPlayerIndex(idPresentableProp *this, idPresentable *presentable)
{
  idPresentablePlayer *Controller; // r3

  Controller = presentable->GetPlayerInterface_2(this: presentable);
  if ( Controller != nullptr )
    return Controller->entityNumber;
  Controller = idPresentable::GetController(this: presentable);
  if ( Controller != nullptr )
    return Controller->entityNumber;
  else
    return 0;
}


// ========================================================================
// ?PickupProp@idPresentableProp@@QAAXPAVidPresentable@@@Z
// EA  : 0x82B8DFB0
// RVA : 0x00B8DFB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprop.cpp
// ========================================================================

void __fastcall idPresentableProp::PickupProp(idPresentableProp *this, idPresentable *activator)
{
  double v4; // fp12
  double v5; // fp9
  double v6; // fp6
  int ServerGameTime; // r3
  int index; // r11

  if ( activator == nullptr
    || activator->GetPlayerInterface_2(this: activator) == nullptr
    || (v4 = (float)(this->origin.z - activator->origin.z),
        v5 = (float)(this->origin.x - activator->origin.x),
        (float)((float)((float)(v6 = (float)(this->origin.y - activator->origin.y)) * (float)v6)
              + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))) <= 25600.0) )
  {
    if ( common->IsServer(this: common) )
    {
      this->pickupEventInfo.playerIndex = idPresentableProp::GetPlayerIndex(this, presentable: activator);
      ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
      this->pickupEventInfo.eventTime = ServerGameTime;
      this->pickupEventInfo.lastHandledEventTime = ServerGameTime;
    }
    else
    {
      this->predictedPickup = true;
    }
    index = -1;
    if ( activator != nullptr )
      index = activator->index;
    this->pickupEventInfo.presentableIndex = index;
    idPresentableProp::InternalPickupProp(this, activator);
  }
}

