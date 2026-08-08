
// ========================================================================
// ?IsZoomedIn@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B801A0
// RVA : 0x00B801A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::IsZoomedIn(_BYTE *ptr)
{
  return (ptr[47032] & 0x40) != 0;
}


// ========================================================================
// ?GetPendingWeapon@idPresentablePlayer@@QBAPAVidWeapon@@XZ
// EA  : 0x82B801B8
// RVA : 0x00B801B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idWeapon *__fastcall idPresentablePlayer::GetPendingWeapon(idPresentablePlayer *this)
{
  int pendingQuickWeapon; // r30
  idInventoryCollection *v3; // r3
  int ItemForQuickSlot; // r30
  idInventoryCollection *v5; // r3
  idWeapon *InventoryItem; // r3

  if ( !this->IsLocallyControlled(this) )
    return this->GetEquippedWeapon(this, a2: EQUIP_RIGHT_HAND);
  pendingQuickWeapon = this->pendingQuickWeapon;
  if ( pendingQuickWeapon < 0 )
    return this->GetEquippedWeapon(this, a2: EQUIP_RIGHT_HAND);
  v3 = (idInventoryCollection *)this->GetInventory_2(this);
  ItemForQuickSlot = idInventoryCollection::GetItemForQuickSlot(
                       this: v3,
                       slotGroup: QUICKSLOTGROUP_WEAPON,
                       slot: pendingQuickWeapon,
                       numSlots: 4);
  v5 = (idInventoryCollection *)this->GetInventory_2(this);
  InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v5, index: ItemForQuickSlot);
  return idWeapon::CastTo(c: InventoryItem);
}


// ========================================================================
// ?Reload@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B80280
// RVA : 0x00B80280
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::Reload(idPresentablePlayer *this)
{
  idHands *p_hands; // r31

  p_hands = &this->hands;
  if ( !idHands::Reload(this: &this->hands, slot: EQUIP_RIGHT_HAND, forceSecondary: false) )
    idHands::Reload(this: p_hands, slot: EQUIP_LEFT_HAND, forceSecondary: false);
}


// ========================================================================
// ?ClearPendingAmmo@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B802D8
// RVA : 0x00B802D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClearPendingAmmo(idPresentablePlayer *this)
{
  this->pendingAmmo = nullptr;
  this->nextAmmoChangeTime = 0;
}


// ========================================================================
// ?GetEquippedWeapon@idPresentablePlayer@@UBAPAVidWeapon@@XZ
// EA  : 0x82B802F8
// RVA : 0x00B802F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idWeapon *__fastcall idPresentablePlayer::GetEquippedWeapon(idPresentablePlayer *this)
{
  return this->GetEquippedWeapon(this, a2: EQUIP_RIGHT_HAND);
}


// ========================================================================
// ?StartSoundShader@idPresentableVehicle@@UAAHW4soundChannel_t@@PBVidSoundShader@@HE@Z
// EA  : 0x82B80310
// RVA : 0x00B80310
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// attributes: thunk
int __fastcall idPresentableVehicle::StartSoundShader(
        idPresentablePlayer *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t soundShaderFlags,
        unsigned __int8 peerMask)
{
  return idPresentable::StartSoundShader(this, channel, shader, soundShaderFlags, peerMask);
}


// ========================================================================
// ?StartSoundShader@idPresentablePlayer@@QAAHW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@E@Z
// EA  : 0x82B80318
// RVA : 0x00B80318
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// attributes: thunk
int __fastcall idPresentablePlayer::StartSoundShader(
        idPresentablePlayer *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int8 peerMask)
{
  return idPresentable::StartSoundShader(this, channel, shader, parms, peerMask);
}


// ========================================================================
// ?StartSoundShader_Predicted@idPresentablePlayer@@UAAHW4soundChannel_t@@PBVidSoundShader@@H@Z
// EA  : 0x82B80320
// RVA : 0x00B80320
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::StartSoundShader_Predicted(
        idPresentablePlayer *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t parms)
{
  idPresentablePlayer *v8; // r3
  bool v9; // zf
  unsigned __int8 v10; // r7

  v9 = common->IsMultiplayer(this: common);
  v8 = this;
  if ( v9 )
  {
    v10 = this->GetPeerMaskForPrediction(this);
    v8 = this;
  }
  else
  {
    v10 = -1;
  }
  return idPresentable::StartSoundShader(this: v8, channel, shader, soundShaderFlags: parms, peerMask: v10);
}


// ========================================================================
// ?StopSound@idPresentablePlayer@@QAAXW4soundChannel_t@@E@Z
// EA  : 0x82B803A0
// RVA : 0x00B803A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentablePlayer::StopSound(
        idPresentablePlayer *this,
        soundChannel_t channel,
        unsigned __int8 peerMask)
{
  idPresentable::StopSound(this, channel, peerMask);
}


// ========================================================================
// ?StopSound_Predicted@idPresentablePlayer@@UAAXW4soundChannel_t@@@Z
// EA  : 0x82B803A8
// RVA : 0x00B803A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::StopSound_Predicted(idPresentablePlayer *this, soundChannel_t channel)
{
  unsigned __int8 v4; // r3

  v4 = this->GetPeerMaskForPrediction(this);
  idPresentable::StopSound(this, channel, peerMask: v4);
}


// ========================================================================
// ?SetSoundVolume@idPresentablePlayer@@QAAXW4soundChannel_t@@ME@Z
// EA  : 0x82B80400
// RVA : 0x00B80400
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentablePlayer::SetSoundVolume(
        idPresentablePlayer *this,
        soundChannel_t channel,
        double volume,
        unsigned __int8 peerMask,
        unsigned __int8 a5)
{
  idPresentable::SetSoundVolume(this, channel, volume, peerMask, a5);
}


// ========================================================================
// ?PlayLocalSound@idPresentablePlayer@@QAAXW4soundChannel_t@@PBVidSoundShader@@H@Z
// EA  : 0x82B80408
// RVA : 0x00B80408
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PlayLocalSound(
        idPresentablePlayer *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t soundShaderFlags)
{
  if ( this->IsLocallyControlled(this) )
    idPresentable::StartSoundShader(this, channel, shader, soundShaderFlags, peerMask: 0);
}


// ========================================================================
// ?GetDecayParams@idPresentablePlayer@@QBAABUdecayParams_s@@_N@Z
// EA  : 0x82B80460
// RVA : 0x00B80460
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

const decayParams_s *__fastcall idPresentablePlayer::GetDecayParams(idPresentablePlayer *this, bool crouch)
{
  char *v2; // r3

  v2 = (char *)this + 0x10000;
  if ( crouch )
    return (const decayParams_s *)(v2 - 18392);
  else
    return (const decayParams_s *)(v2 - 18404);
}


// ========================================================================
// ?GetInventory@idPresentablePlayer@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82B80480
// RVA : 0x00B80480
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idInventoryCollection *__fastcall idPresentablePlayer::GetInventory(idPresentablePlayer *this)
{
  return this->activeInventory;
}


// ========================================================================
// ?GetPlayerSounds@idPresentablePlayer@@QBA?BUplayerSounds_t@idDeclPlayerProps@@XZ
// EA  : 0x82B80488
// RVA : 0x00B80488
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetPlayerSounds(
        idPresentablePlayer *this,
        const idDeclPlayerProps::playerSounds_t *result)
{
  const idSoundShader *sndBreatheMedium; // r11

  sndBreatheMedium = result[81].sndBreatheMedium;
  if ( sndBreatheMedium != nullptr )
    memcpy(Dst: this, Src: &sndBreatheMedium->parms.wetMaxDistanceOffset, Size: 0xC8u);
  else
    idDeclPlayerProps::playerSounds_t::playerSounds_t((idDeclPlayerProps::playerSounds_t *)this);
  return this;
}


// ========================================================================
// ?DisplayDeathMessage@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B804D8
// RVA : 0x00B804D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DisplayDeathMessage(idPresentablePlayer *this)
{
  if ( this->deathInfo.show )
    this->deathInfo.show = false;
}


// ========================================================================
// ?GetPeerIndex@idPresentablePlayer@@UAAHXZ
// EA  : 0x82B804F8
// RVA : 0x00B804F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::GetPeerIndex(idPresentablePlayer *this)
{
  idLobbyBase *v2; // r3
  idPresentablePlayer *v3; // r4
  idLobbyBase_vtbl *v4; // r31
  idPresentablePlayer *LobbyUserID; // r3
  char v7; // [sp+50h] [-20h] BYREF

  v2 = session->GetActingGameStateLobbyBase(this: session);
  v3 = this;
  v4 = v2->__vftable;
  LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v7, result: (lobbyUserID_t *)v3);
  return v4->PeerIndexFromLobbyUser(
           this: (idLobbyBase *)LobbyUserID->__vftable,
           a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
}


// ========================================================================
// ?GetPeerMaskForPrediction@idPresentablePlayer@@UAAEXZ
// EA  : 0x82B80570
// RVA : 0x00B80570
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::GetPeerMaskForPrediction(idPresentablePlayer *this)
{
  int v1; // r3

  v1 = this->GetPeerIndex(this);
  if ( v1 < 0 )
    return 255;
  else
    return (unsigned __int8)~(1 << v1);
}


// ========================================================================
// ?InitOutlineModel@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B806C0
// RVA : 0x00B806C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InitOutlineModel(idPresentablePlayer *this)
{
  idRenderModelAugmentOutline **p_outlineModel; // r31
  idRenderModelAugmentOutline *outlineModel; // r3
  idLobbyBase *v4; // r3
  idRenderWorld *v5; // r3
  idRenderModel *v6; // r3
  idRenderModel *v7; // r3
  idVec4 v8; // [sp+60h] [-30h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    p_outlineModel = &this->outlineModel;
    outlineModel = this->outlineModel;
    if ( outlineModel != nullptr )
    {
      outlineModel->unlinked = true;
      outlineModel->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: outlineModel);
    }
    v4 = session->GetActingGameStateLobbyBase(this: session);
    if ( v4->GetMatchParms(this: v4)->gameType != 2 )
    {
      v5 = gameLocal->GetRenderWorld(this: gameLocal);
      v6 = v5->AllocRenderModel(this: v5, a2: "_augmentoutline", a3: true, a4: -1);
      v7 = (idRenderModel *)_RTDynamicCast(
                              inptr: v6,
                              VfDelta: 0,
                              SrcType: &idRenderModel `RTTI Type Descriptor',
                              TargetType: &idRenderModelAugmentOutline `RTTI Type Descriptor',
                              isReference: 0);
      *p_outlineModel = (idRenderModelAugmentOutline *)v7;
      if ( v7 != nullptr )
      {
        v8.z = idColor::colorGreen.b;
        v8.y = idColor::colorGreen.g;
        v8.x = idColor::colorGreen.r;
        v8.w = idColor::colorGreen.a;
        idRenderModel::SetParm(this: v7, parm: rp->Color, v4: &v8);
        idRenderModel::SetParm(
          this: *p_outlineModel,
          parm: (const idDeclRenderParm *)rpOutlineWidth_0.r,
          scalar: 6.4000001);
        idRenderModel::SetParm(
          this: *p_outlineModel,
          parm: (const idDeclRenderParm *)rpOutlineOpacity_0.r,
          scalar: 0.69999999);
        (*p_outlineModel)->g.referenceModel = this->model;
        *((_BYTE *)&(*p_outlineModel)->g + 104) |= 1u;
        idRenderModel::CommitThisFrame(this: *p_outlineModel);
        (*p_outlineModel)->g.suppressSurfaceInViewID = this->entityNumber + 1;
      }
    }
  }
}


// ========================================================================
// ?PresentableRespawn@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B80898
// RVA : 0x00B80898
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PresentableRespawn(idPresentablePlayer *this, bool initial)
{
  idPlayerHud *p_playerHud; // r29
  double valueFloat; // fp12
  char v6; // r9
  localView_t *LocalView; // r3

  p_playerHud = &this->playerHud;
  this->respawn.count = (this->respawn.count + 1) % 7;
  idPlayerHud::Init(this: &this->playerHud, inPlayer: this);
  idPlayerHud::ClearPickupItems(this: p_playerHud, hudInfo: &this->hudInfo);
  idPlayerHud::SetHudState(this: p_playerHud, state: HUDSTATE_ALL);
  idView::ClearEffects(this: &this->view);
  this->cameraShake.active = false;
  this->cameraShake.scale = 0.0;
  this->cameraShake.startTime = 0.0;
  this->cameraShake.decay = 0.0;
  this->pain_debounce_time = 0;
  this->view.cameraShake = 0.0;
  this->baseWeaponSpread.startTime = 0.0;
  this->baseWeaponSpread.duration = 0.0;
  this->baseWeaponSpread.startValue = 0.0;
  this->baseWeaponSpread.endValue = 0.0;
  this->baseWeaponSpread.currentTime = -1.0;
  this->baseWeaponSpread.currentValue = 0.0;
  this->kickWeaponSpread.startTime = 0.0;
  this->kickWeaponSpread.duration = 0.0;
  this->kickWeaponSpread.startValue = 0.0;
  this->kickWeaponSpread.endValue = 0.0;
  this->kickWeaponSpread.currentTime = -1.0;
  this->kickWeaponSpread.currentValue = 0.0;
  valueFloat = g_fov.valueFloat;
  this->zoomFov.startTime = 0.0;
  this->zoomFov.duration = 0.0;
  this->zoomFov.startValue = valueFloat;
  this->zoomFov.endValue = valueFloat;
  this->zoomFov.currentTime = -1.0;
  this->zoomFov.currentValue = valueFloat;
  v6 = *((_BYTE *)this + 47033);
  *((_BYTE *)this + 47032) &= 0x7Cu;
  *((_BYTE *)this + 47033) = v6 & 0x77;
  idAimAssist::Init(this: &this->aimAssist, pres: this);
  this->serverOverridePositionTime = idClientGame::GetServerGameTime(this: clientGame);
  ++this->respawnCount;
  if ( common->IsMultiplayer(this: common) && this->IsLocallyControlled(this) && !initial )
  {
    LocalView = idPresentablePlayer::GetLocalView(this);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalView->hudRender);
  }
}


// ========================================================================
// ?StartPerfectOrigin@idPresentablePlayer@@QAAXABVidQuat@@ABVidVec3@@H@Z
// EA  : 0x82B80A90
// RVA : 0x00B80A90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::StartPerfectOrigin(
        idPresentablePlayer *this,
        const idQuat *idealAxis,
        const idVec3 *idealPos,
        int lerpTimeMs)
{
  *((_BYTE *)this + 47033) |= 4u;
  idPhysics_Player::StartPerfectOrigin(this: &this->physicsObj, idealPos, lerpTimeMs);
  this->perfectOriginRotation = *idealAxis;
  this->perfectOriginDuration = lerpTimeMs;
  this->perfectOriginStartTime = idPresentablePlayer::GetPlayerGameTime(this);
}


// ========================================================================
// ?ChangeCurrentZoomLevel@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B80B20
// RVA : 0x00B80B20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ChangeCurrentZoomLevel(idPresentablePlayer *this)
{
  idWeapon *v2; // r3
  idWeapon *v3; // r31
  __int64 v4; // r11
  idInterpolate<float> *p_zoomFov; // r30
  int changeZoomLevelTime; // r28
  double v7; // fp31
  int currentZoomLevel; // r11
  int v9; // r4
  double ZoomedFOV; // fp30
  __int64 v11; // r11
  double v12; // fp29
  int PlayerGameTime; // r3

  v2 = this->GetEquippedWeapon(this, a2: 2);
  v3 = v2;
  if ( v2 != nullptr && (*((_BYTE *)v2 + 452) & 0x10) != 0 && (*((_BYTE *)v2 + 452) & 8) != 0 )
  {
    LODWORD(v4) = idPresentablePlayer::GetPlayerGameTime(this);
    p_zoomFov = &this->zoomFov;
    if ( (float)v4 >= (double)(float)(p_zoomFov->duration + p_zoomFov->startTime) )
    {
      changeZoomLevelTime = (int)v3->changeZoomLevelTime;
      v7 = *((float *)&v3->decl[2].engineerableItems.list->len + 13 * v3->currentZoomLevel);
      if ( changeZoomLevelTime < idClientGame::GetPlayerGameTime(this: clientGame) )
      {
        currentZoomLevel = v3->currentZoomLevel;
        v9 = 0;
        if ( currentZoomLevel < v3->decl[2].engineerableItems.num - 1 )
          v9 = currentZoomLevel + 1;
        idWeapon::SetZoomLevel(this: v3, inZoomLevel: v9);
      }
      ZoomedFOV = idWeapon::GetZoomedFOV(this: v3);
      LODWORD(v11) = idWeapon::GetZoomTime(this: v3);
      v12 = (float)v11;
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      p_zoomFov->duration = v12;
      p_zoomFov->startValue = v7;
      p_zoomFov->endValue = ZoomedFOV;
      p_zoomFov->startTime = (float)__SPAIR64__(0x82000000, PlayerGameTime);
      p_zoomFov->currentValue = v7;
      p_zoomFov->currentTime = (float)__SPAIR64__(0x82000000, PlayerGameTime) - (float)1.0;
    }
  }
}


// ========================================================================
// ?SetCurrentZoomLevel@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B80CA0
// RVA : 0x00B80CA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetCurrentZoomLevel(idPresentablePlayer *this, int inZoomLevel)
{
  idWeapon *v3; // r3

  v3 = this->GetEquippedWeapon(this, a2: 2);
  if ( v3 != nullptr && inZoomLevel < v3->decl[2].engineerableItems.num - 1 )
    idWeapon::SetZoomLevel(this: v3, inZoomLevel);
}


// ========================================================================
// ?DecayOriginError@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B80D00
// RVA : 0x00B80D00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DecayOriginError(idPresentablePlayer *this)
{
  idVec3 *p_originError; // r31
  double v2; // fp13
  double v3; // fp12
  double v4; // fp0
  double v5; // fp11
  double valueFloat; // fp31
  double v7; // fp7
  double v8; // fp6
  idVec3 v9; // [sp+50h] [-30h] BYREF

  p_originError = &this->originError;
  v2 = -this->originError.y;
  v3 = -this->originError.z;
  v4 = -this->originError.x;
  v9.x = v4;
  v9.y = v2;
  v9.z = v3;
  v5 = __fsqrts((float)((float)((float)v4 * (float)v4)
                      + (float)((float)((float)v3 * (float)v3) + (float)((float)v2 * (float)v2))));
  if ( v5 <= 1000.0 )
  {
    if ( v5 <= 0.0099999998 )
    {
      p_originError->x = vec3_origin.x;
      this->originError.y = vec3_origin.y;
      this->originError.z = vec3_origin.z;
    }
    else
    {
      valueFloat = (float)(net_errorSmoothingDecay.valueFloat * (float)v5);
      if ( valueFloat > net_errorSmoothingMaxDecay.valueFloat )
        valueFloat = net_errorSmoothingMaxDecay.valueFloat;
      idVec3::NormalizeFast(this: &v9);
      v4 = (float)(v9.x * (float)valueFloat);
      v2 = (float)(v9.y * (float)valueFloat);
      v3 = (float)(v9.z * (float)valueFloat);
    }
    v7 = (float)(p_originError->y + (float)v2);
    v8 = (float)(p_originError->z + (float)v3);
    p_originError->x = (float)v4 + p_originError->x;
    p_originError->y = v7;
    p_originError->z = v8;
  }
  else
  {
    p_originError->x = vec3_origin.x;
    this->originError.y = vec3_origin.y;
    this->originError.z = vec3_origin.z;
  }
}


// ========================================================================
// ?GetViewAngles@idPresentablePlayer@@QBA?BVidAngles@@_N@Z
// EA  : 0x82B80E40
// RVA : 0x00B80E40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetViewAngles(
        idPresentablePlayer *this,
        const idAngles *result,
        bool includeWeaponKick)
{
  float yaw; // r8
  float roll; // r7

  yaw = result[3847].yaw;
  roll = result[3847].roll;
  this->__vftable = (idPresentablePlayer_vtbl *)LODWORD(result[3847].pitch);
  *((float *)&this->__vftable + 1) = yaw;
  *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = roll;
  if ( includeWeaponKick )
  {
    *(float *)&this->__vftable = idWeaponKick::GetOffset(this: (idWeaponKick *)&result[3894].yaw)
                               + *(float *)&this->__vftable;
    *(float *)&this->__vftable = idWeaponKick::GetOffset(this: (idWeaponKick *)&result[3898].yaw)
                               + *(float *)&this->__vftable;
    *((float *)&this->__vftable + 1) = idWeaponKick::GetOffset(this: (idWeaponKick *)&result[3890].yaw)
                                     + *((float *)&this->__vftable + 1);
  }
  return this;
}


// ========================================================================
// ?SetLocalViewLimits@idPresentablePlayer@@QAAXABVidAngles@@0@Z
// EA  : 0x82B80EF0
// RVA : 0x00B80EF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetLocalViewLimits(
        idPresentablePlayer *this,
        const idAngles *minAngles,
        const idAngles *maxAngles)
{
  this->localMaxViewAngles = *maxAngles;
  this->localMinViewAngles = *minAngles;
}


// ========================================================================
// ?ResetLocalViewLimits@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B80F28
// RVA : 0x00B80F28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ResetLocalViewLimits(idPresentablePlayer *this)
{
  this->localMaxViewAngles.pitch = 89.0;
  this->localMaxViewAngles.yaw = 180.0;
  this->localMaxViewAngles.roll = 0.0;
  this->localMinViewAngles.pitch = -89.0;
  this->localMinViewAngles.yaw = -180.0;
  this->localMinViewAngles.roll = 0.0;
}


// ========================================================================
// ?DefaultFov@idPresentablePlayer@@QBAMXZ
// EA  : 0x82B80F70
// RVA : 0x00B80F70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

float __fastcall idPresentablePlayer::DefaultFov(idPresentablePlayer *this)
{
  double valueFloat; // fp1

  valueFloat = g_fov.valueFloat;
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?CalcFov@idPresentablePlayer@@QBAM_N@Z
// EA  : 0x82B80F80
// RVA : 0x00B80F80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

float __fastcall idPresentablePlayer::CalcFov(idPresentablePlayer *this, bool honorZoom)
{
  __int64 v3; // r10
  double CurrentValue; // fp0
  double v5; // fp1

  LODWORD(v3) = idClientGame::GetPlayerGameTime(this: clientGame);
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->zoomFov, time: (float)v3);
  v5 = 1.0;
  if ( CurrentValue >= 1.0 )
  {
    v5 = 179.0;
    if ( CurrentValue <= 179.0 )
      v5 = CurrentValue;
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?CheckFovModified@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B81000
// RVA : 0x00B81000
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::CheckFovModified(idPresentablePlayer *this)
{
  double valueFloat; // fp31
  __int64 v3; // [sp+50h] [-30h]

  if ( (g_fov.flags & 0x20000) != 0 )
  {
    valueFloat = g_fov.valueFloat;
    v3 = __PAIR64__(0x82000000, idClientGame::GetPlayerGameTime(this: clientGame));
    this->zoomFov.startTime = (float)v3;
    this->zoomFov.duration = 0.0;
    this->zoomFov.startValue = valueFloat;
    this->zoomFov.endValue = valueFloat;
    this->zoomFov.currentValue = valueFloat;
    this->zoomFov.currentTime = (float)v3 - (float)1.0;
    g_fov.flags &= ~0x20000u;
  }
}


// ========================================================================
// ?GetWeaponClosestToSlot@idPresentablePlayer@@QAAPAVidWeapon@@_NH0@Z
// EA  : 0x82B810C0
// RVA : 0x00B810C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idWeapon *__fastcall idPresentablePlayer::GetWeaponClosestToSlot(
        idPresentablePlayer *this,
        bool forward,
        int currentSlot,
        bool requireAmmo)
{
  idWeapon *result; // r3
  bfx::Planner3D *v9; // r18
  BOOL v10; // r17
  int v11; // r15
  int v12; // r19
  int v13; // r27
  int v14; // r26
  int v15; // r22
  int v16; // r23
  int v17; // r24
  idDeclTypeInfo *parent; // r21
  const idWeapon *CurrentWeapon; // r3
  int v20; // r28
  idWeapon *InventoryItem; // r3
  idWeapon *v22; // r3
  idWeapon *v23; // r31
  int v24; // r30
  bool v25; // cr58
  idWeapon_vtbl *v26; // r29
  idInventoryCollection *v27; // r3
  idWeapon_vtbl *v28; // r29
  idInventoryCollection *v29; // r3
  idWeapon *v30; // r3

  result = (idWeapon *)this->GetInventory(this);
  v9 = (bfx::Planner3D *)result;
  if ( result == nullptr )
    return result;
  v10 = forward;
  v11 = 0;
  v12 = currentSlot + 1;
  if ( !forward )
    v12 = currentSlot - 1;
  v13 = -1;
  v14 = -1;
  v15 = -1;
  v16 = -1;
  v17 = -1;
  parent = nullptr;
  CurrentWeapon = idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
  if ( CurrentWeapon != nullptr )
    parent = CurrentWeapon->decl[1].parent;
  v20 = 0;
  if ( (int)idScriptObject::GetTypeDef(this: v9) <= 0 )
    goto LABEL_47;
  while ( 1 )
  {
    InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: (idInventoryCollection *)v9, index: v20);
    v22 = idWeapon::CastTo(c: InventoryItem);
    v23 = v22;
    if ( v22 == nullptr )
      goto LABEL_37;
    v24 = (int)v22->decl[1].parent;
    v25 = v24 == 0;
    if ( v24 > 0 )
    {
      if ( !idWeapon::IsMelee(this: v22) && (requireAmmo || v23->decl->blockEquipIfEmpty) )
      {
        if ( v23->ammoClip == nullptr
          || (v26 = v23->__vftable,
              v27 = this->GetInventory(this),
              v26->TotalLoadedAmmoCount(this: v23, a2: v27, a3: false) <= 0) )
        {
          if ( (*((_BYTE *)v23 + 453) & 0x40) == 0 )
            goto LABEL_37;
          if ( v23->ammoClipSecondary == nullptr )
            goto LABEL_37;
          v28 = v23->__vftable;
          v29 = this->GetInventory(this);
          if ( v28->TotalLoadedAmmoCount(this: v23, a2: v29, a3: true) <= 0 )
            goto LABEL_37;
        }
      }
      v25 = v24 == 0;
    }
    if ( v25 )
      v15 = v20;
    if ( v16 == -1 || v24 < v16 )
      v16 = v20;
    if ( v17 == -1 || v24 > v17 )
      v17 = v20;
    if ( v24 == v12 )
      break;
    if ( v12 < 0 )
      goto LABEL_35;
    if ( v10 )
    {
      if ( v24 <= currentSlot || v13 != -1 && v24 >= v13 )
        goto LABEL_37;
LABEL_36:
      v13 = v24;
      v14 = v20;
      goto LABEL_37;
    }
    if ( v24 < currentSlot )
    {
      if ( v13 == -1 )
        goto LABEL_36;
LABEL_35:
      if ( v24 > v13 )
        goto LABEL_36;
    }
LABEL_37:
    if ( ++v20 >= (int)idScriptObject::GetTypeDef(this: v9) )
      goto LABEL_40;
  }
  v14 = v20;
LABEL_40:
  if ( v14 == -1 )
  {
    if ( v15 == 0 && parent == nullptr )
    {
      v14 = v16;
      if ( !v10 )
        v14 = v17;
      if ( v14 == -1 )
        v14 = 0;
      goto LABEL_48;
    }
LABEL_47:
    v14 = v15;
    if ( v15 != -1 )
      goto LABEL_48;
  }
  else
  {
LABEL_48:
    v30 = (idWeapon *)idInventoryCollection::GetInventoryItem(this: (idInventoryCollection *)v9, index: v14);
    return idWeapon::CastTo(c: v30);
  }
  return (idWeapon *)v11;
}


// ========================================================================
// ?SelectClosestWeapon@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B81360
// RVA : 0x00B81360
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SelectClosestWeapon(idPresentablePlayer *this, bool forward)
{
  idHands *p_hands; // r28
  idLaserCutter *CurrentWeapon; // r3
  int parent; // r31
  idLaserCutter *v7; // r3
  bool v8; // r6
  idWeapon *WeaponClosestToSlot; // r31
  bool v10; // r4

  p_hands = &this->hands;
  CurrentWeapon = (idLaserCutter *)idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
  parent = 0;
  if ( CurrentWeapon != nullptr )
    parent = (int)CurrentWeapon->decl[1].parent;
  v7 = idLaserCutter::CastTo(c: CurrentWeapon);
  if ( v7 == nullptr || (v8 = false, !v7->hasMobileReactorUpgrade) )
    v8 = true;
  WeaponClosestToSlot = idPresentablePlayer::GetWeaponClosestToSlot(this, forward, currentSlot: parent, requireAmmo: v8);
  if ( WeaponClosestToSlot != nullptr
    && WeaponClosestToSlot != idHands::GetCurrentWeapon(this: p_hands, slot: EQUIP_RIGHT_HAND) )
  {
    if ( WeaponClosestToSlot->decl[1].parent != nullptr
      && idWeapon::CanToggleWeaponMode(this: WeaponClosestToSlot)
      && idLaserCutter::CastTo(c: (idLaserCutter *)WeaponClosestToSlot) == nullptr )
    {
      if ( WeaponClosestToSlot->weaponState != WEAPONSTATE_NORMAL )
      {
        if ( WeaponClosestToSlot->ammoClipSecondary->GetCount(this: WeaponClosestToSlot->ammoClipSecondary) > 0
          || WeaponClosestToSlot->ammoClip->GetCount(this: WeaponClosestToSlot->ammoClip) > 0 )
        {
          goto LABEL_19;
        }
        v10 = false;
      }
      else
      {
        if ( WeaponClosestToSlot->ammoClip->GetCount(this: WeaponClosestToSlot->ammoClip) > 0
          || WeaponClosestToSlot->ammoClipSecondary->GetCount(this: WeaponClosestToSlot->ammoClipSecondary) < 0 )
        {
          goto LABEL_19;
        }
        v10 = true;
      }
      idWeapon::SetWeaponMode(this: WeaponClosestToSlot, secondary: v10);
    }
LABEL_19:
    idHands::SelectWeapon(this: p_hands, slot: EQUIP_RIGHT_HAND, weapon: WeaponClosestToSlot, useIntroBringUp: false);
    this->pendingAmmo = nullptr;
    this->nextAmmoChangeTime = 0;
  }
}


// ========================================================================
// ?NextWeapon@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B814E8
// RVA : 0x00B814E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::NextWeapon(idPresentablePlayer *this)
{
  idPresentablePlayer::SelectClosestWeapon(this, forward: true);
}


// ========================================================================
// ?PrevWeapon@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B814F0
// RVA : 0x00B814F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PrevWeapon(idPresentablePlayer *this)
{
  idPresentablePlayer::SelectClosestWeapon(this, forward: false);
}


// ========================================================================
// ?EquipPrevEquippedWeapon@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B814F8
// RVA : 0x00B814F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::EquipPrevEquippedWeapon(idPresentablePlayer *this)
{
  idHands *p_hands; // r29
  idWeapon *lastWeapon; // r30
  idAmmoItem *ammoClip; // r3

  this->pendingAmmo = nullptr;
  p_hands = &this->hands;
  this->nextAmmoChangeTime = 0;
  lastWeapon = idHands::ItemForSlot(this: &this->hands, slot: EQUIP_RIGHT_HAND)->lastWeapon;
  if ( lastWeapon != nullptr
    && (lastWeapon->decl[1].parent == nullptr
     || (ammoClip = lastWeapon->ammoClip) != nullptr && ammoClip->GetCount(this: ammoClip) > 0) )
  {
    idHands::SelectWeapon(this: p_hands, slot: EQUIP_RIGHT_HAND, weapon: lastWeapon, useIntroBringUp: false);
  }
  else
  {
    idPresentablePlayer::SelectBestWeapon(this);
  }
}


// ========================================================================
// ?NextQuickWeaponSlot@idPresentablePlayer@@QBAHXZ
// EA  : 0x82B815A8
// RVA : 0x00B815A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::NextQuickWeaponSlot(idPresentablePlayer *this)
{
  idWeapon *CurrentWeapon; // r23
  int v3; // r24
  int v4; // r25
  idStrId *v5; // r27
  idInventoryCollection *v6; // r3
  idWeapon *InventoryItemForQuickSlot; // r3
  char v8; // r26
  idWeapon *v9; // r3
  idWeapon *v10; // r29
  idAmmoItem *ammoClip; // r3
  const idDeclInventory *decl; // r11
  int v13; // r30
  int v14; // r31
  const idDeclInventory *v15; // r21
  idInventoryCollection *v16; // r3
  const char *v18; // r31
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r3
  idInventoryItem v21[2]; // [sp+50h] [-70h] BYREF

  CurrentWeapon = (idWeapon *)idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
  if ( this->pendingQuickWeapon > -1 )
    CurrentWeapon = idPresentablePlayer::GetPendingWeapon(this);
  if ( CurrentWeapon != nullptr )
  {
    v3 = CurrentWeapon->quickSlot == -1 ? 0 : CurrentWeapon->quickSlot;
    v4 = v3;
LABEL_5:
    v5 = nullptr;
    while ( 1 )
    {
      v4 = v4 == 3 ? 0 : v4 + 1;
      if ( v4 == v3 )
        break;
      v6 = (idInventoryCollection *)this->GetInventory_2(this);
      InventoryItemForQuickSlot = (idWeapon *)idInventoryCollection::GetInventoryItemForQuickSlot(
                                                this: v6,
                                                slotGroup: QUICKSLOTGROUP_WEAPON,
                                                slot: v4,
                                                numSlots: 4);
      v5 = (idStrId *)InventoryItemForQuickSlot;
      if ( InventoryItemForQuickSlot == CurrentWeapon )
        break;
      if ( InventoryItemForQuickSlot != nullptr )
      {
        v8 = 0;
        v9 = idWeapon::CastTo(c: InventoryItemForQuickSlot);
        v10 = v9;
        if ( v9 == nullptr )
        {
          v18 = *(const char **)(v5[3].index + 172);
          DisplayName = idInventoryItem::GetDisplayName(this: v21, result: v5);
          LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
          idLib::Warning(
            fmt: "idPresentablePlayer::NextQuickWeaponSlot - Item is not a weapon! - '%s' - '%s'",
            LocalizedString,
            v18);
          return -1;
        }
        ammoClip = v9->ammoClip;
        if ( ammoClip != nullptr
          && (ammoClip->GetCount(this: ammoClip) > 0 || idStr::Cmp(s1: v10->decl->internalName.data, s2: "fists") == 0) )
        {
          v8 = 1;
        }
        if ( v8 == 0 )
        {
          decl = v10->decl;
          v13 = 0;
          if ( (int)decl[1].nextOnHashChain > 0 )
          {
            v14 = 0;
            while ( 1 )
            {
              v15 = *(const idDeclInventory **)&decl[1].name.str[v14];
              v16 = (idInventoryCollection *)this->GetInventory_2(this);
              if ( idInventoryCollection::FindTotalInventoryItemCount(this: v16, decl: v15) > 0 )
                break;
              decl = v10->decl;
              ++v13;
              v14 += 28;
              if ( v13 >= (int)decl[1].nextOnHashChain )
                goto LABEL_21;
            }
            v8 = 1;
          }
        }
LABEL_21:
        if ( v8 == 0 )
          goto LABEL_5;
        break;
      }
    }
    if ( v5 != nullptr && v5 != (idStrId *)CurrentWeapon )
      return v5[6].index;
  }
  return -1;
}


// ========================================================================
// ?GetNextAmmoDecl@idPresentablePlayer@@QBAPBVidDeclAmmo@@XZ
// EA  : 0x82B81790
// RVA : 0x00B81790
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

const idDeclAmmo *__fastcall idPresentablePlayer::GetNextAmmoDecl(idPresentablePlayer *this)
{
  int v2; // r27
  idWeapon *CurrentWeapon; // r3
  idWeapon *v4; // r26
  idAmmoItem *ammoClip; // r11
  const idDeclAmmo *decl; // r31
  const idDeclInventory *v8; // r30
  int AmmoDeclIndex; // r29
  __int64 v10; // r9
  int v11; // r31
  const idInventoryCollection *v12; // r28
  int v13; // r11
  const char *str; // r10

  v2 = 0;
  CurrentWeapon = (idWeapon *)idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
  v4 = CurrentWeapon;
  if ( CurrentWeapon != nullptr )
  {
    ammoClip = CurrentWeapon->ammoClip;
    if ( ammoClip == nullptr )
      return nullptr;
    decl = (const idDeclAmmo *)ammoClip->decl;
    if ( this->pendingAmmo != nullptr )
      decl = this->pendingAmmo;
    v8 = CurrentWeapon->decl;
    AmmoDeclIndex = idWeapon::GetAmmoDeclIndex(this: CurrentWeapon, ammo: decl, secondaryAmmo: false);
    if ( AmmoDeclIndex == -1 )
    {
      idLib::Warning(
        fmt: "Current ammo decl '%s' for weapon '%s' is not in validAmmoClips list",
        decl->name.str,
        v8->name.str);
      AmmoDeclIndex = 0;
    }
    LODWORD(v10) = v8[1].nextOnHashChain;
    HIDWORD(v10) = (unsigned int)(AmmoDeclIndex + 1) >> 31;
    v11 = ((__PAIR64__((unsigned int)v10 >> 31, AmmoDeclIndex + 1) - v10) >> 32) & (AmmoDeclIndex + 1);
    v12 = this->GetInventory_2(this);
    if ( v11 != AmmoDeclIndex )
    {
      v13 = 28 * v11;
      do
      {
        str = v8[1].name.str;
        v2 = *(_DWORD *)&str[v13];
        if ( v2 != 0
          && idWeapon::CanReload(
               this: v4,
               inventory: v12,
               ammoDecl: *(const idDeclAmmo **)&str[v13],
               secondaryAmmo: false) )
        {
          break;
        }
        v11 = ((__PAIR64__((unsigned int)v8[1].nextOnHashChain >> 31, v11 + 1)
              - __PAIR64__((unsigned int)(v11 + 1) >> 31, v8[1].nextOnHashChain)) >> 32)
            & (v11 + 1);
        v13 = 28 * v11;
      }
      while ( v11 != AmmoDeclIndex );
    }
  }
  return (const idDeclAmmo *)v2;
}


// ========================================================================
// ?ReleaseWeaponKickRecoveryDelay@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B818D0
// RVA : 0x00B818D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ReleaseWeaponKickRecoveryDelay(idPresentablePlayer *this)
{
  __int64 v2; // r11
  __int64 v3; // r11
  __int64 v4; // r11

  LODWORD(v2) = idClientGame::GetPlayerGameTime(this: clientGame);
  if ( (float)v2 < (double)(float)(this->weaponKick[2].recoveryOffset.duration
                                 + this->weaponKick[2].recoveryOffset.startTime) )
  {
    LODWORD(v3) = idClientGame::GetPlayerGameTime(this: clientGame);
    HIDWORD(v3) = (char *)this + 0x10000;
    if ( (float)v3 < (double)(float)(this->weaponKick[2].recoilOffset.duration
                                   + this->weaponKick[2].recoilOffset.startTime) )
    {
      LODWORD(v4) = idClientGame::GetPlayerGameTime(this: clientGame);
      this->weaponKick[2].recoveryOffset.startTime = (float)v4;
    }
  }
}


// ========================================================================
// ?SetAmmoStatus@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B819A8
// RVA : 0x00B819A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentablePlayer::SetAmmoStatus(idPresentablePlayer *this, bool leftHand)
{
  BOOL v2; // r21
  idHudWeaponAmmoStatusInfo *v4; // r11
  idWeapon *v5; // r3
  idWeapon *v6; // r28
  bool v7; // r11
  __int64 v8; // r6 OVERLAPPED
  idLaserCutter *v9; // r3
  int maxBattery; // r7
  idAmmoItem *ammoClip; // r11
  int burstMode; // r11
  idWeapon::weaponState_t weaponState; // r11
  const idDeclInventory *decl; // r10
  idAmmoItem *v15; // r11
  __int32 v16; // r11
  idAmmoItem *ammoClipSecondary; // r11
  burstMode_t num; // r11
  unsigned __int32 currentFunctionalityLens; // r10
  BOOL showStatic; // r9
  idWeapon::weaponState_t v21; // r10
  bool v22; // xer_ca
  int v23; // r22
  bool v24; // xer_ca
  int v25; // r6
  int v26; // r7
  const idDeclInventory *v27; // r11
  idAmmoItem *v28; // r10
  __int32 v29; // r11
  idAmmoItem *v30; // r11
  idPresentablePlayer_vtbl *v31; // r11
  int v32; // r9
  const idDeclInventory *v33; // r11
  idAmmoItem *v34; // r10
  __int32 v35; // r11
  idAmmoItem *v36; // r11
  _DWORD *v37; // r30
  const idDeclInventory *v38; // r24
  idPresentablePlayer_vtbl *v39; // r10
  idAmmoItem *v40; // r3
  idPresentablePlayer_vtbl **v41; // r29
  idInventoryCollection *v42; // r3
  int TotalInventoryItemCount; // r24
  _DWORD *v44; // r30
  int v45; // r28
  idPresentablePlayer_vtbl **v46; // r29
  idInventoryCollection *v47; // r3
  int v48; // r31
  burstMode_t v49; // r3
  idAmmoItem *v50; // r11
  int v51; // r11

  v2 = leftHand;
  if ( leftHand )
  {
    if ( !this->hudInfo.weaponAmmoStatus[2].renderReceipt )
      return;
    this->hudInfo.weaponAmmoStatus[2].show = false;
    this->hudInfo.weaponAmmoStatus[2].staticCounter = false;
    this->hudInfo.weaponAmmoStatus[2].nextAnimState = 0;
    this->hudInfo.weaponAmmoStatus[2].ammoClipCount = 0;
    this->hudInfo.weaponAmmoStatus[2].ammoTotalCount = 0;
    this->hudInfo.weaponAmmoStatus[2].burstMode = BURSTMODE_FULLAUTO;
    this->hudInfo.weaponAmmoStatus[2].dwAvailable = false;
    this->hudInfo.weaponAmmoStatus[2].renderReceipt = false;
    if ( !this->hudInfo.weaponAmmoStatus[3].renderReceipt )
      return;
    v4 = &this->hudInfo.weaponAmmoStatus[3];
  }
  else
  {
    if ( !this->hudInfo.weaponAmmoStatus[0].renderReceipt )
      return;
    this->hudInfo.weaponAmmoStatus[0].nextAnimState = 0;
    this->hudInfo.weaponAmmoStatus[0].show = false;
    this->hudInfo.weaponAmmoStatus[0].staticCounter = false;
    this->hudInfo.weaponAmmoStatus[0].ammoClipCount = 0;
    this->hudInfo.weaponAmmoStatus[0].ammoTotalCount = 0;
    this->hudInfo.weaponAmmoStatus[0].burstMode = BURSTMODE_FULLAUTO;
    this->hudInfo.weaponAmmoStatus[0].dwAvailable = false;
    this->hudInfo.weaponAmmoStatus[0].renderReceipt = false;
    this->hudInfo.laserCutterStatus.charge = 0.0;
    this->hudInfo.laserCutterStatus.canShoot = false;
    this->hudInfo.laserCutterStatus.show = false;
    this->hudInfo.laserCutterStatus.nextAnimState = 0;
    this->hudInfo.laserCutterStatus.cuttingMode = true;
    this->hudInfo.laserCutterStatus.shootingFullAuto = false;
    this->hudInfo.laserCutterFuncLensStatus.showPrim = false;
    this->hudInfo.laserCutterFuncLensStatus.showSec = false;
    this->hudInfo.laserCutterFuncLensStatus.showStatic = false;
    this->hudInfo.laserCutterFuncLensStatus.nextAnimState = 0;
    this->hudInfo.laserCutterFuncLensStatus.iconPrim = FUNCTIONALITY_LENS_ZOOM;
    this->hudInfo.laserCutterFuncLensStatus.iconSec = FUNCTIONALITY_LENS_ZOOM;
    this->hudInfo.laserCutterFuncLensStatus.iconStatic = FUNCTIONALITY_LENS_ZOOM;
    if ( !this->hudInfo.weaponAmmoStatus[1].renderReceipt )
      return;
    v4 = &this->hudInfo.weaponAmmoStatus[1];
  }
  v4->renderReceipt = false;
  v4->dwAvailable = false;
  v4->burstMode = BURSTMODE_FULLAUTO;
  v4->ammoTotalCount = 0;
  v4->ammoClipCount = 0;
  v4->nextAnimState = 0;
  v4->staticCounter = false;
  v4->show = false;
  v5 = this->GetEquippedWeapon(this, a2: ((_cntlzw(leftHand) & 0x20) != 0) + 1);
  v6 = v5;
  if ( v5 == nullptr )
    return;
  if ( !v2 )
  {
    if ( (*((_BYTE *)v5 + 452) & 1) == 0 || (v7 = true, this->hands.currentDualWieldState == SET_DUALWIELD_ON) )
      v7 = false;
    this->hudInfo.weaponAmmoStatus[0].dwAvailable = v7;
  }
  if ( idWeapon::IsMelee(this: v5) )
  {
    this->lastWeaponSlotRight = 0;
    return;
  }
  v9 = idLaserCutter::CastTo(c: (idLaserCutter *)v6);
  if ( v9 != nullptr )
  {
    maxBattery = v9->maxBattery;
    LODWORD(v8) = v9->batteryCount;
    this->hudInfo.laserCutterStatus.show = true;
    this->hudInfo.laserCutterStatus.charge = (float)v8 / (float)*(__int64 *)((char *)&v8 - 4);
    this->hudInfo.laserCutterStatus.cuttingMode = v6->weaponState != WEAPONSTATE_NORMAL;
    ammoClip = v6->ammoClip;
    if ( ammoClip != nullptr )
      burstMode = ammoClip->burstMode;
    else
      burstMode = v6->decl[1].attachmentInfo.num;
    this->hudInfo.laserCutterStatus.shootingFullAuto = (_cntlzw(burstMode - 2) & 0x20) != 0;
    this->hudInfo.laserCutterStatus.canShoot = (*((_BYTE *)v6 + 453) & 0x40) != 0;
    weaponState = v6->weaponState;
    if ( weaponState != this->weaponFiremodeAnimStateRight
      || (decl = v6->decl)[1].parent != (idDeclTypeInfo *)this->lastWeaponSlotRight
      || (weaponState != WEAPONSTATE_SECONDARY ? (v15 = v6->ammoClip) : (v15 = v6->ammoClipSecondary),
          v15 == nullptr ? (v16 = decl[1].attachmentInfo.num) : (v16 = v15->burstMode),
          v16 != this->lastBurstModeRight) )
    {
      this->lastWeaponSlotRight = (int)v6->decl[1].parent;
      this->weaponFiremodeAnimStateRight = v6->weaponState;
      if ( v6->weaponState == WEAPONSTATE_SECONDARY )
        ammoClipSecondary = v6->ammoClipSecondary;
      else
        ammoClipSecondary = v6->ammoClip;
      if ( ammoClipSecondary != nullptr )
        num = ammoClipSecondary->burstMode;
      else
        num = v6->decl[1].attachmentInfo.num;
      this->lastBurstModeRight = num;
      this->hudInfo.laserCutterStatus.nextAnimState = 1;
    }
    this->hudInfo.laserCutterFuncLensStatus.showPrim = v9->availableFunctionalityLenses & 1;
    this->hudInfo.laserCutterFuncLensStatus.showSec = (v9->availableFunctionalityLenses & 2) != 0;
    this->hudInfo.laserCutterFuncLensStatus.showStatic = (v9->availableFunctionalityLenses & 4) != 0;
    if ( v9->currentFunctionalityLens != this->lastFunctionalityLens )
    {
      this->hudInfo.laserCutterFuncLensStatus.nextAnimState = 1;
      this->lastFunctionalityLens = v9->currentFunctionalityLens;
    }
    currentFunctionalityLens = v9->currentFunctionalityLens;
    showStatic = this->hudInfo.laserCutterFuncLensStatus.showStatic;
    this->hudInfo.laserCutterFuncLensStatus.iconSec = currentFunctionalityLens;
    if ( showStatic )
    {
      this->hudInfo.laserCutterFuncLensStatus.iconPrim = (int)(currentFunctionalityLens + 2) % 3;
      this->hudInfo.laserCutterFuncLensStatus.iconStatic = (int)(currentFunctionalityLens + 1) % 3;
    }
    else
    {
      this->hudInfo.laserCutterFuncLensStatus.iconPrim = (_cntlzw(currentFunctionalityLens) & 0x20) != 0;
    }
    return;
  }
  v21 = v6->weaponState;
  v22 = !v2;
  if ( v21 != WEAPONSTATE_NORMAL )
    v23 = v22 ? 1 : 3;
  else
    v23 = v22 ? 0 : 2;
  v24 = !v2;
  if ( v21 != WEAPONSTATE_NORMAL )
    v25 = v24 ? 0 : 2;
  else
    v25 = v24 ? 1 : 3;
  if ( v2 )
  {
    v26 = 47092;
    if ( v21 == this->weaponFiremodeAnimStateLeft )
    {
      v27 = v6->decl;
      if ( v27[1].parent == (idDeclTypeInfo *)this->lastWeaponSlotLeft )
      {
        v28 = v21 == WEAPONSTATE_SECONDARY ? v6->ammoClipSecondary : v6->ammoClip;
        v29 = v28 != nullptr ? v28->burstMode : v27[1].attachmentInfo.num;
        if ( v29 == this->lastBurstModeLeft )
          goto LABEL_80;
      }
    }
    this->lastWeaponSlotLeft = (int)v6->decl[1].parent;
    this->weaponFiremodeAnimStateLeft = v6->weaponState;
    if ( v6->weaponState == WEAPONSTATE_SECONDARY )
      v30 = v6->ammoClipSecondary;
    else
      v30 = v6->ammoClip;
    if ( v30 != nullptr )
    {
      v31 = (idPresentablePlayer_vtbl *)v30->burstMode;
      v32 = 35696;
    }
    else
    {
      v32 = 35696;
      v31 = (idPresentablePlayer_vtbl *)v6->decl[1].attachmentInfo.num;
    }
  }
  else
  {
    v26 = 47088;
    if ( v21 == this->weaponFiremodeAnimStateRight )
    {
      v33 = v6->decl;
      if ( v33[1].parent == (idDeclTypeInfo *)this->lastWeaponSlotRight )
      {
        v34 = v21 == WEAPONSTATE_SECONDARY ? v6->ammoClipSecondary : v6->ammoClip;
        v35 = v34 != nullptr ? v34->burstMode : v33[1].attachmentInfo.num;
        if ( v35 == this->lastBurstModeRight )
          goto LABEL_80;
      }
    }
    this->lastWeaponSlotRight = (int)v6->decl[1].parent;
    this->weaponFiremodeAnimStateRight = v6->weaponState;
    if ( v6->weaponState == WEAPONSTATE_SECONDARY )
      v36 = v6->ammoClipSecondary;
    else
      v36 = v6->ammoClip;
    if ( v36 != nullptr )
      v31 = (idPresentablePlayer_vtbl *)v36->burstMode;
    else
      v31 = (idPresentablePlayer_vtbl *)v6->decl[1].attachmentInfo.num;
    v32 = 35648;
  }
  *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v32) = (idPresentablePlayer_vtbl *)1;
  *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v26) = v31;
LABEL_80:
  this->hudInfo.weaponAmmoStatus[v25].show = true;
  v37 = &v6->ammoClip->__vftable;
  if ( v37 != nullptr )
    v38 = (const idDeclInventory *)v37[3];
  else
    v38 = nullptr;
  if ( v38 != nullptr )
  {
    if ( v37 != nullptr )
      v39 = (idPresentablePlayer_vtbl *)v37[10];
    else
      v39 = (idPresentablePlayer_vtbl *)v6->decl[1].attachmentInfo.num;
    v40 = v6->ammoClip;
    v41 = (idPresentablePlayer_vtbl **)((char *)this + 24 * v25);
    v41[8911] = v39;
    v41[8913] = (idPresentablePlayer_vtbl *)(*(int (__fastcall **)(idAmmoItem *))(*v37 + 52))(a1: v40);
    v42 = this->GetInventory(this);
    TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(this: v42, decl: v38);
    v41[8914] = (idPresentablePlayer_vtbl *)(TotalInventoryItemCount
                                           + (*(int (__fastcall **)(_DWORD *))(*v37 + 52))(a1: v37));
  }
  if ( v6->decl[1].trackedMemory != 0 && (*((_BYTE *)v6 + 453) & 0x40) != 0 )
  {
    v44 = &v6->ammoClipSecondary->__vftable;
    if ( v44 != nullptr )
      v45 = v44[3];
    else
      v45 = 0;
    if ( v45 != 0 && *(_BYTE *)(v45 + 787) != 0 )
    {
      v46 = (idPresentablePlayer_vtbl **)((char *)this + 24 * v23);
      v46[8911] = (idPresentablePlayer_vtbl *)3;
      this->hudInfo.weaponAmmoStatus[v23].show = true;
      v46[8913] = (idPresentablePlayer_vtbl *)(*(int (__fastcall **)(_DWORD *))(*v44 + 52))(a1: v44);
      v47 = this->GetInventory(this);
      v48 = idInventoryCollection::FindTotalInventoryItemCount(this: v47, decl: (const idDeclInventory *)v45);
      v46[8914] = (idPresentablePlayer_vtbl *)(v48 + (*(int (__fastcall **)(_DWORD *))(*v44 + 52))(a1: v44));
    }
  }
  else
  {
    this->hudInfo.weaponAmmoStatus[!v2 ? 0 : 2].staticCounter = true;
    v49 = idWeapon::ToggleFireMode(this: v6, justFetchNextMode: true, ignoreMode: true);
    if ( v6->weaponState == WEAPONSTATE_SECONDARY )
      v50 = v6->ammoClipSecondary;
    else
      v50 = v6->ammoClip;
    if ( v50 != nullptr )
      v51 = v50->burstMode;
    else
      v51 = v6->decl[1].attachmentInfo.num;
    if ( v49 != v51 )
    {
      this->hudInfo.weaponAmmoStatus[v23].show = true;
      this->hudInfo.weaponAmmoStatus[v23].burstMode = v49;
    }
  }
}


// ========================================================================
// ?SelectQuickAmmo@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B82218
// RVA : 0x00B82218
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SelectQuickAmmo(idPresentablePlayer *this, int slot)
{
  idWeapon *PendingWeapon; // r3
  const idDeclInventory *decl; // r29
  int v6; // r28
  _DWORD *v7; // r3
  int v8; // r30
  const idDeclInventory *v9; // r27
  idInventoryCollection *v10; // r3
  const idDeclPlayerProps *playerProps; // r11
  idDeclPlayerProps::playerSounds_t sounds; // [sp+50h] [-100h] BYREF

  this->nextAmmoChangeTime = idClientGame::GetPlayerGameTime(this: clientGame);
  PendingWeapon = idPresentablePlayer::GetPendingWeapon(this);
  decl = PendingWeapon->decl;
  v6 = 0;
  if ( slot < 0 || slot >= (int)decl[1].nextOnHashChain )
    goto LABEL_8;
  v7 = &PendingWeapon->ammoClip->__vftable;
  if ( v7 != nullptr && v7[3] == *(_DWORD *)&decl[1].name.str[28 * slot] )
    v6 = (*(int (__fastcall **)(_DWORD *))(*v7 + 52))(a1: v7);
  v8 = 28 * slot;
  v9 = *(const idDeclInventory **)&decl[1].name.str[v8];
  v10 = this->GetInventory(this);
  if ( idInventoryCollection::FindTotalInventoryItemCount(this: v10, decl: v9) + v6 <= 0 )
  {
LABEL_8:
    if ( this->IsLocallyControlled(this) )
    {
      playerProps = this->playerProps;
      if ( playerProps != nullptr )
        sounds = playerProps->sounds;
      else
        idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
      idPresentable::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: sounds.sndButtonBad,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    }
  }
  else
  {
    this->pendingAmmo = *(const idDeclAmmo **)&decl[1].name.str[v8];
  }
}


// ========================================================================
// ?SelectQuickWeapon@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B82350
// RVA : 0x00B82350
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SelectQuickWeapon(idPresentablePlayer *this, int slot)
{
  int (*GetEquippedWeapon)(void); // r8
  int v5; // r3
  int v6; // r10
  idInventoryCollection *v7; // r3

  GetEquippedWeapon = (int (*)(void))this->GetEquippedWeapon;
  this->nextWeaponChangeTime = 0;
  v5 = GetEquippedWeapon();
  if ( v5 != 0 && slot == *(_DWORD *)(v5 + 24) )
  {
    v6 = -1;
LABEL_6:
    if ( v6 != this->pendingQuickWeapon )
    {
      this->pendingQuickWeapon = v6;
      this->pendingAmmo = nullptr;
    }
    return;
  }
  v7 = this->GetInventory(this);
  if ( idInventoryCollection::GetInventoryItemForQuickSlot(
         this: v7,
         slotGroup: QUICKSLOTGROUP_WEAPON,
         slot,
         numSlots: 4) != nullptr )
  {
    v6 = slot;
    if ( slot > -2 )
      goto LABEL_6;
  }
}


// ========================================================================
// ?ClearPickupItems@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B82408
// RVA : 0x00B82408
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClearPickupItems(idPresentablePlayer *this)
{
  idPlayerHud::ClearPickupItems(this: &this->playerHud, hudInfo: &this->hudInfo);
}


// ========================================================================
// ?UpdateSound@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B82420
// RVA : 0x00B82420
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateSound(idPresentablePlayer *this)
{
  idVec3 v2; // [sp+50h] [-50h] BYREF
  idMat3 v3; // [sp+60h] [-40h] BYREF

  if ( !this->IsLocallyControlled(this) || pm_thirdPerson.valueInteger != 0 )
  {
    idPresentable::UpdateSound(this);
  }
  else
  {
    idView::GetViewPos(this: &this->view, origin: &v2, axis: &v3);
    idPresentable::UpdateSound(this, origin: &v2, axis: &v3, velocity: &vec3_origin, listenerId: this->index + 1);
  }
}


// ========================================================================
// ?ClientPredictTriggers@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B824C8
// RVA : 0x00B824C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientPredictTriggers(
        idPresentablePlayer *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
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
        idClipModel *a27)
{
  idPresentablePlayer *v27; // r25
  const idBounds *v28; // r3
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v30; // r30
  const char *i; // r26
  idClipModel *v32; // r31
  idPresentable *PresentableByEntityNum; // r3
  idPresentableCollisionTrigger *v34; // r29

  v27 = (idPresentablePlayer *)((int (*)(void))RtlCheckStack12)();
  v28 = v27->physicsObj.GetAbsBounds(this: &v27->physicsObj, a2: -1);
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: &clientGame->clip,
                               bounds: v28,
                               clipMask: 0x4000,
                               clipModelList: &a27,
                               maxCount: (const char *)0x2000);
  if ( (int)ClipModelsTouchingBounds > 0 )
  {
    v30 = &a27;
    for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
    {
      v32 = *v30;
      PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(
                                 this: clientGame,
                                 entityNum: (*v30)->entityNumber);
      if ( PresentableByEntityNum != nullptr )
      {
        v34 = PresentableByEntityNum->GetCollisionTriggerInterface(this: PresentableByEntityNum);
        if ( v34 != nullptr && v27->physicsObj.ClipContents(this: &v27->physicsObj, a2: v32, a3: 0x4000) != 0 )
          idPresentableCollisionTrigger::PredictTouch(this: v34, player: v27);
      }
      ++v30;
    }
  }
}


// ========================================================================
// ?ToggleDualWieldItem@idPresentablePlayer@@QAA_N_N00@Z
// EA  : 0x82B825B0
// RVA : 0x00B825B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::ToggleDualWieldItem(
        idPresentablePlayer *this,
        bool justClear,
        bool leftWeaponToRightHand,
        bool forceOn)
{
  idWeapon *v8; // r22
  char v10; // r27
  idWeapon *dualWieldItem; // r28
  idInventoryItem *v12; // r31
  const idDeclJob *decl; // r29
  idJobManager *v14; // r3
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v16; // r3
  idInventoryItem *v17; // r26
  idInventoryItem *v18; // r29
  idAmmoItem *v19; // r25
  const idDeclJob *v20; // r25
  idJobManager *v21; // r3
  idAmmoItem *v22; // r3
  idInventoryItem *v23; // r3
  int v24; // r4
  int v25; // r27
  int v26; // r3
  int v27; // r3
  int v28; // r31
  int v29; // r3
  int v30; // r3
  idHands *p_hands; // r31
  bool v32; // r3
  int (__fastcall *GetCount)(idInventoryItem *); // ctr
  const idDeclInventory *v34; // r31
  int v35; // r29
  idInventoryCollection *v36; // r3
  int v37; // r3
  int (__fastcall *v38)(idInventoryItem *); // ctr
  const idDeclInventory *v39; // r31
  int v40; // r29
  idInventoryCollection *v41; // r3
  int v42; // r3
  idInventoryItem *v43; // r29
  bool v44; // r3
  idHandsItem *v45; // r3
  idWeapon_vtbl *v46; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idWeapon_vtbl *v48; // r27
  idTreeAnimator *v49; // r3
  BOOL v50; // r31
  idPlayer *entity; // r3

  v8 = this->GetEquippedWeapon(this, a2: 2);
  if ( v8 == nullptr )
    return 0;
  v10 = 0;
  dualWieldItem = this->GetEquippedWeapon(this, a2: 1);
  if ( dualWieldItem == nullptr || forceOn )
  {
    if ( justClear )
      return 1;
    dualWieldItem = v8->dualWieldItem;
    v10 = 1;
  }
  if ( dualWieldItem == nullptr )
    return 0;
  v12 = &dualWieldItem->ammoClip->idInventoryItem;
  decl = (const idDeclJob *)v12->decl;
  v14 = (idJobManager *)this->GetInventory(this);
  JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(this: v14, jobDecl: decl);
  v16 = idAmmoItem::CastTo(c: JobByDecl);
  v17 = &dualWieldItem->ammoClipSecondary->idInventoryItem;
  v18 = &v16->idInventoryItem;
  if ( v17 != nullptr )
  {
    v20 = (const idDeclJob *)v17->decl;
    v21 = (idJobManager *)this->GetInventory(this);
    v22 = (idAmmoItem *)idJobManager::FindJobByDecl(this: v21, jobDecl: v20);
    v19 = idAmmoItem::CastTo(c: v22);
  }
  else
  {
    v19 = nullptr;
  }
  if ( !justClear )
    v8->wasDualWielding = v10;
  v23 = v12;
  if ( v10 == 0 )
  {
    GetCount = v12->GetCount;
    if ( v18 != nullptr )
    {
      v37 = GetCount(this: v12);
      idInventoryItem::ModifyCount(this: v18, amount: v37);
    }
    else
    {
      v34 = v12->decl;
      v35 = GetCount(this: v23);
      v36 = this->GetInventory(this);
      idInventoryCollection::GiveItem(this: v36, owner: this, decl: v34, count: v35, forceCount: true, canIntro: false);
    }
    if ( v17 != nullptr )
    {
      v38 = v17->GetCount;
      if ( v19 != nullptr )
      {
        v42 = v38(this: v17);
        idInventoryItem::ModifyCount(this: &v19->idInventoryItem, amount: v42);
      }
      else
      {
        v39 = v17->decl;
        v40 = v38(this: v17);
        v41 = this->GetInventory(this);
        idInventoryCollection::GiveItem(
          this: v41,
          owner: this,
          decl: v39,
          count: v40,
          forceCount: true,
          canIntro: false);
      }
    }
    if ( leftWeaponToRightHand )
    {
      v43 = dualWieldItem->dualWieldItem;
      v44 = this->IsLocallyControlled(this);
      idHands::AttachItem(this: &this->hands, item: v43, slot: EQUIP_RIGHT_HAND, initFX: v44);
      v45 = idHands::ItemForSlot(this: &this->hands, slot: EQUIP_RIGHT_HAND);
      idHandsItem::Hide(this: v45);
    }
    p_hands = &this->hands;
    idHands::DetachItem(this: &this->hands, slot: EQUIP_LEFT_HAND);
    dualWieldItem = nullptr;
    goto LABEL_39;
  }
  if ( v18 != nullptr )
  {
    if ( v12->GetCount(this: v12) > 0 )
      goto LABEL_22;
    v25 = v18->GetCount(this: v18);
    v26 = v12->GetCount(this: v12);
    if ( v26 < v25 )
      v25 = v26;
    v27 = v18->GetCount(this: v18);
    idInventoryItem::SetCount(this: v18, amount: v27 - v25);
    v24 = v25;
    v23 = v12;
  }
  else
  {
    v24 = 0;
  }
  idInventoryItem::SetCount(this: v23, amount: v24);
LABEL_22:
  if ( v17 != nullptr && v17->GetCount(this: v17) <= 0 && v19 != nullptr )
  {
    v28 = v19->GetCount(this: v19);
    v29 = v17->GetCount(this: v17);
    if ( v29 < v28 )
      v28 = v29;
    v30 = v19->GetCount(this: v19);
    idInventoryItem::SetCount(this: &v19->idInventoryItem, amount: v30 - v28);
    idInventoryItem::SetCount(this: v17, amount: v28);
  }
  p_hands = &this->hands;
  v32 = this->IsLocallyControlled(this);
  idHands::AttachItem(this: &this->hands, item: dualWieldItem, slot: EQUIP_LEFT_HAND, initFX: v32);
LABEL_39:
  if ( idHands::GetTreeAnimatorFromPresentable(this: p_hands) != nullptr )
  {
    v46 = v8->__vftable;
    TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: p_hands);
    v46->UpdateHiddenMeshes(this: v8, a2: TreeAnimatorFromPresentable);
    idWeapon::SetZoomed(this: v8, zoomed: false, fxMgr: &this->fxManager);
    idHands::ShowRRL(this: p_hands, usePending: false, equipingWeapon: v8);
    if ( dualWieldItem != nullptr )
    {
      v48 = dualWieldItem->__vftable;
      v49 = idHands::GetTreeAnimatorFromPresentable(this: p_hands);
      v48->UpdateHiddenMeshes(this: dualWieldItem, a2: v49);
      idWeapon::SetZoomed(this: dualWieldItem, zoomed: false, fxMgr: &this->fxManager);
      idHands::ShowRRL(this: p_hands, usePending: false, equipingWeapon: dualWieldItem);
    }
  }
  v50 = idPlayer::Server_EquipItem(this: (idPlayer *)this->entity, item: v8, slot: EQUIP_RIGHT_HAND);
  entity = (idPlayer *)this->entity;
  if ( dualWieldItem != nullptr )
    return idPlayer::Server_EquipItem(this: entity, item: dualWieldItem, slot: EQUIP_LEFT_HAND) && v50;
  entity->ClearEquipped_2(this: entity, a2: EQUIP_LEFT_HAND);
  return v50;
}


// ========================================================================
// ?EquipItem@idPresentablePlayer@@QAA_NPAVidInventoryItem@@@Z
// EA  : 0x82B82A60
// RVA : 0x00B82A60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::EquipItem(idPresentablePlayer *this, idWeapon *item)
{
  equipSlot_t equipSlot; // r26
  idWeapon *v5; // r29
  bool v6; // r3
  idWeapon_vtbl *v7; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idFXManager *v9; // r5
  BOOL result; // r3

  equipSlot = item->decl->equipSlot;
  v5 = idWeapon::CastTo(c: item);
  if ( equipSlot == EQUIP_NONE )
    return idPlayer::Server_EquipItem(this: (idPlayer *)this->entity, item, slot: equipSlot);
  switch ( equipSlot )
  {
    case EQUIP_LEFT_HAND:
    case EQUIP_RIGHT_HAND:
      v6 = this->IsLocallyControlled(this);
      idHands::AttachItem(this: &this->hands, item, slot: equipSlot, initFX: v6);
      if ( idHands::GetTreeAnimatorFromPresentable(this: &this->hands) != nullptr && v5 != nullptr )
      {
        v7 = v5->__vftable;
        TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        v7->UpdateHiddenMeshes(this: v5, a2: TreeAnimatorFromPresentable);
        if ( this->entity != nullptr && common->IsServer(this: common) )
          v9 = (idFXManager *)((int (__fastcall *)(idEntity *, idWeapon *))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].GetColor_3)(
                                a1: this->entity,
                                a2: v5);
        else
          v9 = nullptr;
        idWeapon::SetZoomed(this: v5, zoomed: false, fxMgr: v9);
        idHands::ShowRRL(this: &this->hands, usePending: false, equipingWeapon: v5);
      }
      return idPlayer::Server_EquipItem(this: (idPlayer *)this->entity, item, slot: equipSlot);
    case EQUIP_VEHICLE:
    case EQUIP_VEHICLE_RAM:
      result = false;
      break;
    default:
      return idPlayer::Server_EquipItem(this: (idPlayer *)this->entity, item, slot: equipSlot);
  }
  return result;
}


// ========================================================================
// ?GetEquipped@idPresentablePlayer@@QBAPAVidInventoryItem@@W4equipSlot_t@@@Z
// EA  : 0x82B82BE8
// RVA : 0x00B82BE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idInventoryItem *__fastcall idPresentablePlayer::GetEquipped(idPresentablePlayer *this, equipSlot_t slot)
{
  return ((idInventoryItem *(__fastcall *)(idEntity *, equipSlot_t))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].SetColor_5)(
           a1: this->entity,
           a2: slot);
}


// ========================================================================
// ?IsDead@idPresentablePlayer@@UAA_NXZ
// EA  : 0x82B82C00
// RVA : 0x00B82C00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::IsDead(idPresentablePlayer *this)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    return this->entity->IsDead(this: this->entity);
  else
    return *((unsigned __int8 *)this + 47032) >> 7;
}


// ========================================================================
// ?IsCrouching@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B82C90
// RVA : 0x00B82C90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::IsCrouching(idPresentablePlayer *this)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    return idActor::IsCrouching(this: (idActor *)this->entity);
  else
    return idPhysics_Player::IsCrouching(this: &this->physicsObj);
}


// ========================================================================
// ?AFIsActive@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B82D10
// RVA : 0x00B82D10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::AFIsActive(idPresentablePlayer *this)
{
  idAnimator_AF *v2; // r3
  unsigned __int8 v3; // r11

  if ( this->entity == nullptr || !common->IsServer(this: common) )
    return 0;
  v2 = this->entity->GetAF_2(this: this->entity);
  if ( v2->isActive )
    return 1;
  v3 = 0;
  if ( v2->isClientAuthoritativeActive )
    return 1;
  return v3;
}


// ========================================================================
// ?GetFocusFriendly@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B82DB8
// RVA : 0x00B82DB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::GetFocusFriendly(idPresentablePlayer *this)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    return idPlayer::GetFocusFriendly(this: (idPlayer *)this->entity);
  else
    return 0;
}


// ========================================================================
// ?DeployableAllowed@idPresentablePlayer@@QAA_NPBVidDeclThrowable@@@Z
// EA  : 0x82B82E30
// RVA : 0x00B82E30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::DeployableAllowed(idPresentablePlayer *this, const idDeclThrowable *throwableDecl)
{
  const idDeclProjectile *projectileDecl; // r11
  int result; // r3
  bool v6; // zf

  if ( this->entity == nullptr )
    return 1;
  if ( !common->IsServer(this: common) )
    return 1;
  if ( throwableDecl == nullptr )
    return 1;
  projectileDecl = throwableDecl->projectileDecl;
  if ( projectileDecl == nullptr )
    return 1;
  if ( !projectileDecl->notHitscanInfo.followDeployableRules )
    return 1;
  v6 = !idPlayer::CanAddDroppable(this: (idPlayer *)this->entity);
  result = 0;
  if ( !v6 )
    return 1;
  return result;
}


// ========================================================================
// ?GetFireTrajectory@idPresentablePlayer@@QAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B82ED0
// RVA : 0x00B82ED0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::GetFireTrajectory(idPresentablePlayer *this, idVec3 *firePos, idMat3 *fireAxis)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    idPlayer::GetFireTrajectory(this: (idPlayer *)this->entity, firePos, fireAxis);
  }
  else
  {
    firePos->x = this->firstPersonViewOrigin.x;
    firePos->y = this->firstPersonViewOrigin.y;
    firePos->z = this->firstPersonViewOrigin.z;
    fireAxis->mat[0].x = this->firstPersonViewAxis.mat[0].x;
    fireAxis->mat[0].y = this->firstPersonViewAxis.mat[0].y;
    fireAxis->mat[0].z = this->firstPersonViewAxis.mat[0].z;
    fireAxis->mat[1].x = this->firstPersonViewAxis.mat[1].x;
    fireAxis->mat[1].y = this->firstPersonViewAxis.mat[1].y;
    fireAxis->mat[1].z = this->firstPersonViewAxis.mat[1].z;
    fireAxis->mat[2].x = this->firstPersonViewAxis.mat[2].x;
    fireAxis->mat[2].y = this->firstPersonViewAxis.mat[2].y;
    fireAxis->mat[2].z = this->firstPersonViewAxis.mat[2].z;
  }
}


// ========================================================================
// ?BeforeUse@idPresentablePlayer@@QAA_NXZ
// EA  : 0x82B82FB8
// RVA : 0x00B82FB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::BeforeUse(idPresentablePlayer *this)
{
  return this->entity != nullptr
      && common->IsServer(this: common)
      && idPlayer::BeforeUse(this: (idPlayer *)this->entity);
}


// ========================================================================
// ?BeforeUseIsRunning@idPresentablePlayer@@QAA_NXZ
// EA  : 0x82B83030
// RVA : 0x00B83030
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::BeforeUseIsRunning(idPresentablePlayer *this)
{
  return this->entity != nullptr
      && common->IsServer(this: common)
      && idPlayer::BeforeUseIsRunning(this: (idPlayer *)this->entity);
}


// ========================================================================
// ?SetAngles@idPresentablePlayer@@QAAXABVidAngles@@@Z
// EA  : 0x82B830A8
// RVA : 0x00B830A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetAngles(idPresentablePlayer *this, const idAngles *ang)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    idEntity::SetAngles(this: this->entity, ang);
}


// ========================================================================
// ?IsPlayerControlInhibited@idPresentablePlayer@@QAA_NXZ
// EA  : 0x82B83118
// RVA : 0x00B83118
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::IsPlayerControlInhibited(idPresentablePlayer *this)
{
  idPresentablePlayer::playerGuis_t v3; // r31
  idSWF *PlayerGui; // r3
  localView_t *LocalView; // r3
  localView_t *v6; // r31
  unsigned __int8 IsPlayerControlInhibited; // r29

  if ( !common->IsGamePaused(this: common) )
  {
    v3 = GUI_DELIVERY;
    while ( 1 )
    {
      if ( idPresentablePlayer::GuiIsActive(this, g: v3) )
      {
        PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: v3);
        if ( (unsigned __int8)idSWF::IsPlayerControlInhibited(this: PlayerGui) != 0 )
          break;
      }
      if ( ++v3 >= (GUI_TUTORIAL|GUI_JOBOFFER) )
      {
        LocalView = idPresentablePlayer::GetLocalView(this);
        v6 = LocalView;
        if ( LocalView == nullptr )
          return (*((_BYTE *)this + 47032) & 0x10) != 0;
        IsPlayerControlInhibited = idPlayerGuis_Render::IsPlayerControlInhibited(this: &LocalView->guisRender);
        if ( ((unsigned __int8)idPlayerHud_Render::IsPlayerControlInhibited(this: &v6->hudRender)
            | IsPlayerControlInhibited) == 0 )
          return (*((_BYTE *)this + 47032) & 0x10) != 0;
        return true;
      }
    }
  }
  return true;
}


// ========================================================================
// ?InhibitFire@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B831F0
// RVA : 0x00B831F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InhibitFire(idPresentablePlayer *this, bool inhibit)
{
  *((_BYTE *)this + 47033) = (8 * inhibit) & 8 | *((_BYTE *)this + 47033) & 0xF7;
  this->inhibitFireControlStartTime = idGameTimeManager::GetGameMs(
                                        this: &clientGame->gameTimeManager,
                                        type: GAMETIME_SCALED);
}


// ========================================================================
// ?CheckInhibitFire@idPresentablePlayer@@QAA_NXZ
// EA  : 0x82B83258
// RVA : 0x00B83258
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::CheckInhibitFire(idPresentablePlayer *this)
{
  _BYTE *v2; // r31
  char v3; // r10
  unsigned __int8 v4; // r11

  v2 = (char *)this + 47033;
  if ( this->inhibitFireControlStartTime + 48 >= idGameTimeManager::GetGameMs(
                                                   this: &clientGame->gameTimeManager,
                                                   type: GAMETIME_SCALED)
    || (*v2 & 8) != 0 && idUCmdTracker::IsPressedForPlayer(this: &this->ucmdTracker1, mask: 1) )
  {
    v3 = *v2 | 8;
    goto LABEL_8;
  }
  if ( (*v2 & 8) != 0 && !idUCmdTracker::IsPressedForPlayer(this: &this->ucmdTracker1, mask: 1) )
  {
    v3 = *v2 & 0xF7;
LABEL_8:
    *v2 = v3;
  }
  if ( (*v2 & 8) != 0 )
    return 1;
  v4 = 0;
  if ( this->focusTracker.useButtonOverride == 1 )
    return 1;
  return v4;
}


// ========================================================================
// ?GetControlWeapon@idPresentablePlayer@@QBAPBVidWeapon@@XZ
// EA  : 0x82B83350
// RVA : 0x00B83350
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

const idWeapon *__fastcall idPresentablePlayer::GetControlWeapon(idPresentablePlayer *this)
{
  idProp_WeaponStatic *Control; // r3
  idProp_WeaponStatic *v3; // r3

  if ( this->entity == nullptr || !common->IsServer(this: common) )
    return this->GetEquippedWeapon(this, a2: EQUIP_RIGHT_HAND);
  Control = (idProp_WeaponStatic *)idPlayer::GetControl(this: (idPlayer *)this->entity);
  v3 = idProp_WeaponStatic::CastTo(c: Control);
  if ( v3 != nullptr )
    return v3->weapon;
  else
    return idActor::GetEquippedWeapon(this: (idActor *)this->entity, slot: EQUIP_RIGHT_HAND);
}


// ========================================================================
// ?SetControllerShake@idPresentablePlayer@@QAAXMHMH@Z
// EA  : 0x82B83410
// RVA : 0x00B83410
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetControllerShake(
        idPresentablePlayer *this,
        double highMagnitude,
        int highDuration,
        double lowMagnitude,
        int lowDuration)
{
  idView::SetControllerShake(this: &this->view, highMagnitude, highDuration, lowMagnitude, lowDuration);
}


// ========================================================================
// ?ShowInventory@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B83418
// RVA : 0x00B83418
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ShowInventory(idPresentablePlayer *this, bool inVehicle)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    idPlayer::ShowInventory(this: (idPlayer *)this->entity, inVehicle);
}


// ========================================================================
// ?SetWalkState@idPresentablePlayer@@QAAXW4walkState_t@@@Z
// EA  : 0x82B83488
// RVA : 0x00B83488
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetWalkState(idPresentablePlayer *this, walkState_t state)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    ((void (__fastcall *)(idEntity *, walkState_t))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].UpdateAttachments)(
      a1: this->entity,
      a2: state);
}


// ========================================================================
// ?PlayFootStepEffect@idPresentablePlayer@@QAA_NW4footStepType_t@@@Z
// EA  : 0x82B83508
// RVA : 0x00B83508
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::PlayFootStepEffect(idPresentablePlayer *this, footStepType_t footstepType)
{
  return this->entity != nullptr
      && common->IsServer(this: common)
      && idActor::PlayFootStepEffect(this: (idActor *)this->entity, footstepType);
}


// ========================================================================
// ?PresentableDamaged@idPresentablePlayer@@QAAXM@Z
// EA  : 0x82B83580
// RVA : 0x00B83580
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PresentableDamaged(idPresentablePlayer *this, double damage)
{
  int GameMs; // r3
  const idDeclPlayerProps *playerProps; // r11
  float x; // r5
  _BYTE v7[208]; // [sp+50h] [-100h] BYREF

  if ( this->IsLocallyControlled(this)
    && this->pain_debounce_time < idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)
    && !idPresentable::IsPlayingSound(this, channel: SND_CHANNEL_VOICE2) )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    playerProps = this->playerProps;
    this->pain_debounce_time = playerProps->pain.pain_delay + GameMs;
    if ( damage < playerProps->pain.pain_heavyDamageAmount )
    {
      if ( damage < playerProps->pain.pain_mediumDamageAmount )
        x = idPresentablePlayer::GetPlayerSounds(
              this: (idPresentablePlayer *)v7,
              result: (const idDeclPlayerProps::playerSounds_t *)this)->axis.mat[1].x;
      else
        x = idPresentablePlayer::GetPlayerSounds(
              this: (idPresentablePlayer *)v7,
              result: (const idDeclPlayerProps::playerSounds_t *)this)->axis.mat[1].y;
    }
    else
    {
      x = idPresentablePlayer::GetPlayerSounds(
            this: (idPresentablePlayer *)v7,
            result: (const idDeclPlayerProps::playerSounds_t *)this)->axis.mat[1].z;
    }
    idPresentablePlayer::PlayLocalSound(
      this,
      channel: SND_CHANNEL_VOICE2,
      shader: (const idSoundShader *)LODWORD(x),
      soundShaderFlags: (soundShaderFlags_t)0);
  }
}


// ========================================================================
// ?UpdateEditEntityMode@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B83678
// RVA : 0x00B83678
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateEditEntityMode(idPresentablePlayer *this)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    idPlayer::UpdateEditEntityMode(this: (idPlayer *)this->entity);
    idHands::UpdateHidden(this: &this->hands);
  }
}


// ========================================================================
// ?IsFullyZoomedIn@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B836E8
// RVA : 0x00B836E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::IsFullyZoomedIn(idPresentablePlayer *this)
{
  idWeapon *v3; // r3
  idWeapon *v4; // r30
  __int64 v5; // r10
  unsigned __int8 v6; // r11

  if ( !this->IsLocallyControlled(this) )
    return (*((_BYTE *)this + 47032) & 0x40) != 0;
  v3 = this->GetEquippedWeapon(this, a2: 2);
  v4 = v3;
  v6 = false;
  if ( v3 != nullptr )
  {
    if ( (*((_BYTE *)v3 + 452) & 8) != 0 )
    {
      LODWORD(v5) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      HIDWORD(v5) = (char *)this + 0x10000;
      if ( (float)v5 >= (double)(float)(this->zoomFov.duration + this->zoomFov.startTime) )
        return true;
    }
    if ( v4->ForceIronsightSensAndMove(this: v4) )
      return true;
  }
  return v6;
}


// ========================================================================
// ?IsFullyZoomedOut@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B83808
// RVA : 0x00B83808
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::IsFullyZoomedOut(idPresentablePlayer *this)
{
  idWeapon *v3; // r30
  BOOL v4; // r29
  __int64 v5; // r10

  if ( !this->IsLocallyControlled(this) )
    return (~*((unsigned __int8 *)this + 47032) & 0x40) != 0;
  v3 = this->GetEquippedWeapon(this, a2: 2);
  v4 = (_cntlzw((unsigned int)v3) & 0x20) != 0;
  if ( v3 != nullptr )
  {
    LODWORD(v5) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v5) = (char *)this + 0x10000;
    if ( (float)v5 >= (double)(float)(this->zoomFov.duration + this->zoomFov.startTime)
      && (*((_BYTE *)v3 + 452) & 8) == 0 )
    {
      return true;
    }
  }
  return v4;
}


// ========================================================================
// ?GetMovementScale@idPresentablePlayer@@QAAMXZ
// EA  : 0x82B838F8
// RVA : 0x00B838F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

float __fastcall idPresentablePlayer::GetMovementScale(idPresentablePlayer *this)
{
  idWeapon *v2; // r30
  double MovementScale; // fp1

  v2 = this->GetEquippedWeapon(this, a2: 2);
  if ( v2 != nullptr && (unsigned __int8)idPresentablePlayer::IsFullyZoomedIn(this) != 0 )
    MovementScale = idWeapon::GetMovementScale(this: v2);
  else
    MovementScale = 1.0;
  return *((float *)&MovementScale + 1);
}


// ========================================================================
// ?GetCrouchedScale@idPresentablePlayer@@QAAMXZ
// EA  : 0x82B83980
// RVA : 0x00B83980
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

float __fastcall idPresentablePlayer::GetCrouchedScale(idPresentablePlayer *this)
{
  idWeapon *v2; // r30
  double CrouchedScale; // fp1

  v2 = this->GetEquippedWeapon(this, a2: 2);
  if ( v2 != nullptr && (unsigned __int8)idPresentablePlayer::IsFullyZoomedIn(this) != 0 )
    CrouchedScale = idWeapon::GetCrouchedScale(this: v2);
  else
    CrouchedScale = 1.0;
  return *((float *)&CrouchedScale + 1);
}


// ========================================================================
// ?NotifyThrowRelease@idPresentablePlayer@@QAAXPBVidDeclThrowable@@PAVidPresentableProjectile@@@Z
// EA  : 0x82B83A08
// RVA : 0x00B83A08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::NotifyThrowRelease(
        idPresentablePlayer *this,
        const idDeclThrowable *throwItem,
        idPresentableProjectile *spawnedProjectile)
{
  idEntity *entity; // r10

  entity = this->entity;
  ++this->throwCount;
  if ( entity != nullptr
    && ((unsigned __int8 (__fastcall *)(idCommon *, const idDeclThrowable *))common->IsServer)(
         a1: common,
         a2: throwItem) != 0 )
  {
    idPlayer::RemoveThrowItemAttachments(this: (idPlayer *)this->entity, spawnedProjectile);
  }
}


// ========================================================================
// ?HandleCameraShake@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B83A88
// RVA : 0x00B83A88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::HandleCameraShake(idPresentablePlayer *this)
{
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp0

  if ( this->cameraShake.active )
  {
    *(double *)&v2 = (float)((float)((float)((float)__SPAIR64__(
                                                      "1 - formation cover, such as behind regime shield units",
                                                      idGameTimeManager::GetGameMs(
                                                        this: &clientGame->gameTimeManager,
                                                        type: GAMETIME_SCALED))
                                           - this->cameraShake.startTime)
                                   * this->cameraShake.decay)
                           * (float)-0.001);
    v3 = exp(x: v2);
    v4 = (float)(this->cameraShake.scale * (float)*(double *)&v3);
    if ( v4 < 0.0099999998 )
    {
      this->cameraShake.active = false;
      v4 = 0.0;
    }
    this->view.cameraShake = v4;
  }
}


// ========================================================================
// ?SetExplicitMove@idPresentablePlayer@@QAAXABUplayerExplicitMove_t@@_N1@Z
// EA  : 0x82B83B38
// RVA : 0x00B83B38
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetExplicitMove(
        idPresentablePlayer *this,
        const playerExplicitMove_t *move,
        bool alsoAllowPhysicsMove,
        bool useExplicitMove2)
{
  idPresentablePlayer::idPlayerExplicitMotion_t::explicitMoveType_t v4; // r10

  if ( alsoAllowPhysicsMove )
  {
    v4 = EXPLICIT_MOVE_SINGLE_ADDITIONAL;
LABEL_3:
    this->explicitMotion.moveType = v4;
    this->explicitMotion.singleMove = *move;
    return;
  }
  v4 = EXPLICIT_MOVE_SINGLE_EXCLUSIVE;
  if ( !useExplicitMove2 )
    goto LABEL_3;
  this->explicitMotion.moveType = EXPLICIT_MOVE_SINGLE_EXCLUSIVE;
  this->explicitMotion.singleMove2 = *move;
}


// ========================================================================
// ?Init@idPresentablePlayer@@QAAXPBVidDeclMD6@@PBVidDeclAnimWeb@@1PBVidDeclFX@@@Z
// EA  : 0x82B83DE8
// RVA : 0x00B83DE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::Init(
        idPresentablePlayer *this,
        const idDeclMD6 *handsDeclMD6,
        const idDeclAnimWeb *handsDeclAnimWeb,
        const idDeclAnimWeb *handsDeclSecondaryAnimWeb,
        const idDeclFX *handsFX)
{
  idHands *p_hands; // r30
  int i; // r27
  const idDeclPlayerProps *playerProps; // r11
  const idDeclParticle *waterDripsSmall; // r11
  idPresentablePlayer::screenParticleState_t *list; // r28
  idPresentablePlayer::screenParticleState_t *v11; // r8
  idRenderModel *pModel; // r30
  idStr v13[3]; // [sp+50h] [-70h] BYREF

  p_hands = &this->hands;
  idHands::Init(
    this: &this->hands,
    owner: this,
    declMD6: handsDeclMD6,
    declAnimWeb: handsDeclAnimWeb,
    declSecondaryAnimWeb: handsDeclSecondaryAnimWeb,
    setFxDecl: handsFX);
  idHands::SetModelOffset(this: p_hands, offset: &vec3_origin);
  if ( this->playerProps != nullptr )
  {
    for ( i = 0; i < 5; ++i )
    {
      playerProps = this->playerProps;
      if ( (unsigned int)i <= 3 )
      {
        if ( i == 1 )
        {
          waterDripsSmall = playerProps->screenParticles.waterDripsSmall;
        }
        else if ( i == 2 )
        {
          waterDripsSmall = playerProps->screenParticles.waterDripsMedium;
        }
        else
        {
          waterDripsSmall = i != 0
                          ? playerProps->screenParticles.waterDripsLarge
                          : playerProps->screenParticles.waterDroplets;
        }
        if ( waterDripsSmall != nullptr )
        {
          idStr::idStr(this: v13, text: waterDripsSmall->name.str);
          idStr::SetFileExtension(this: v13, extension: "prt");
          list = this->screenPrtState.list;
          list[i].pModel = clientGame->renderWorld->AllocRenderModel(
                             this: clientGame->renderWorld,
                             a2: v13[0].data,
                             a3: 1,
                             a4: -1);
          v11 = this->screenPrtState.list;
          pModel = v11[i].pModel;
          if ( !pModel->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v11[i].pModel);
            pModel->unlinked = true;
          }
          idStr::FreeData(this: v13);
        }
      }
    }
  }
  idPresentablePlayer::InitOutlineModel(this);
  idPresentablePlayer::EnableInfluenceTrail(this);
}


// ========================================================================
// __unwind$495205
// EA  : 0x82B83F30
// RVA : 0x00B83F30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_495205()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ToggleZoom@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B83F58
// RVA : 0x00B83F58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ToggleZoom(idPresentablePlayer *this, bool z)
{
  idWorldspawn *world; // r10
  bool *p_wantZoom; // r29
  idLaserCutter *ControlWeapon; // r3
  idWeapon *v7; // r30
  idLaserCutter *v8; // r3

  world = gameLocal->world;
  if ( world == nullptr || world->mapType != MAPTYPE_TOWN )
  {
    p_wantZoom = &this->wantZoom;
    if ( this->wantZoom != z )
    {
      ControlWeapon = (idLaserCutter *)idPresentablePlayer::GetControlWeapon(this);
      v7 = ControlWeapon;
      if ( ControlWeapon != nullptr )
      {
        v8 = idLaserCutter::CastTo(c: ControlWeapon);
        if ( v8 == nullptr || v8->currentFunctionalityLens == FUNCTIONALITY_LENS_ZOOM )
        {
          if ( !v7->decl[1].programaticallyDefined
            || this != (idPresentablePlayer *)-37616
            && !this->hands.disabled
            && (this->hands.currentDualWieldState == SET_DUALWIELD_ON
             || this->hands.isReloading
             || (unsigned __int8)idHands::IsInRestState(this: &this->hands) != 0) )
          {
            goto LABEL_16;
          }
          if ( idWeapon::GetZoomMode(this: v7) == ZOOM_WEAPON )
          {
            *p_wantZoom = z;
            return;
          }
          if ( idWeapon::GetZoomMode(this: v7) == ZOOM_NONE )
LABEL_16:
            *p_wantZoom = false;
        }
      }
    }
  }
}


// ========================================================================
// ?SetupZoom@idPresentablePlayer@@QAAX_NPAVidWeapon@@@Z
// EA  : 0x82B84080
// RVA : 0x00B84080
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetupZoom(idPresentablePlayer *this, bool handsZoomIn, idWeapon *weapon)
{
  double ZoomedFOV; // fp31
  double valueFloat; // fp30
  double v8; // fp29
  idFXManager *v9; // r5
  int v10; // r4
  idEntity *entity; // r9
  idFXManager *v12; // r5
  int v13; // r4
  double v14; // fp1
  double v15; // fp31
  double v16; // fp30
  double v17; // fp28
  __int64 v18; // r9
  double v19; // fp30
  int ZoomTime; // r3
  double v21; // fp31
  double v22; // fp30
  __int64 v23; // r9
  double v24; // fp31
  __int64 v25; // r8
  __int64 v26; // [sp+50h] [-50h]

  if ( weapon != nullptr && idWeapon::GetZoomMode(this: weapon) == ZOOM_WEAPON )
  {
    if ( handsZoomIn )
    {
      *((_BYTE *)this + 47032) |= 0x40u;
      if ( idWeapon::GetZoomedFOV(this: weapon) > 0.0 )
      {
        ZoomedFOV = idWeapon::GetZoomedFOV(this: weapon);
        valueFloat = g_fov.valueFloat;
        v8 = (float)__SPAIR64__(
                      (idCVar *)&ai_useTurnTransitions.valueString.baseBuffer[12],
                      idWeapon::GetZoomTime(this: weapon));
        v26 = __PAIR64__(0x82000000, idClientGame::GetPlayerGameTime(this: clientGame));
        this->zoomFov.startTime = (float)v26;
        this->zoomFov.duration = v8;
        this->zoomFov.startValue = valueFloat;
        this->zoomFov.endValue = ZoomedFOV;
        this->zoomFov.currentValue = valueFloat;
        this->zoomFov.currentTime = (float)v26 - (float)1.0;
        if ( this->entity != nullptr && common->IsServer(this: common) )
          v9 = (idFXManager *)((int (__fastcall *)(idEntity *, idWeapon *))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].GetColor_3)(
                                a1: this->entity,
                                a2: weapon);
        else
          v9 = nullptr;
        idWeapon::SetZoomed(this: weapon, zoomed: true, fxMgr: v9);
        idBobCycle::SetBobSwayScale(
          this: &this->bobCycle,
          newScale: *(float *)&weapon->decl[2].weaponFX,
          transitionTime: v10);
        if ( idWeapon::HideHandsOnZoom(this: weapon) )
          idHands::Hide(this: &this->hands, hideReason: HAND_HIDE_ZOOM);
      }
    }
    else
    {
      idPresentablePlayer::ToggleZoom(this, z: false);
      entity = this->entity;
      *((_BYTE *)this + 47032) &= ~0x40u;
      if ( entity != nullptr && common->IsServer(this: common) )
        v12 = (idFXManager *)((int (__fastcall *)(idEntity *, idWeapon *))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].GetColor_3)(
                               a1: this->entity,
                               a2: weapon);
      else
        v12 = nullptr;
      idWeapon::SetZoomed(this: weapon, zoomed: false, fxMgr: v12);
      idHands::Show(this: &this->hands, hideReason: HAND_HIDE_ZOOM);
      idBobCycle::SetBobSwayScale(this: &this->bobCycle, newScale: 1.0, transitionTime: v13);
      v14 = idWeapon::GetZoomedFOV(this: weapon);
      v15 = v14;
      if ( v14 <= 0.0 )
      {
        v24 = g_fov.valueFloat;
        LODWORD(v25) = idClientGame::GetPlayerGameTime(this: clientGame);
        HIDWORD(v25) = (char *)this + 0x10000;
        this->zoomFov.startTime = (float)v25;
        this->zoomFov.duration = 0.2;
        this->zoomFov.startValue = this->lastFov;
        this->zoomFov.endValue = v24;
        this->zoomFov.currentTime = (float)v25 - (float)1.0;
        this->zoomFov.currentValue = this->lastFov;
      }
      else
      {
        v16 = g_fov.valueFloat;
        if ( (float)(g_fov.valueFloat - (float)v14) >= 0.000099999997 )
        {
          v19 = (float)((float)(g_fov.valueFloat - this->lastFov) / (float)(g_fov.valueFloat - (float)v14));
          ZoomTime = idWeapon::GetZoomTime(this: weapon);
          v21 = g_fov.valueFloat;
          v22 = (float)((float)__SPAIR64__((idCVar *)&ai_useTurnTransitions.valueString.baseBuffer[12], ZoomTime)
                      * (float)v19);
          LODWORD(v23) = idClientGame::GetPlayerGameTime(this: clientGame);
          HIDWORD(v23) = (char *)this + 0x10000;
          this->zoomFov.startTime = (float)v23;
          this->zoomFov.duration = v22;
          this->zoomFov.startValue = this->lastFov;
          this->zoomFov.endValue = v21;
          this->zoomFov.currentTime = (float)v23 - (float)1.0;
          this->zoomFov.currentValue = this->lastFov;
        }
        else
        {
          v17 = (float)__SPAIR64__(
                         (idCVar *)&ai_useTurnTransitions.valueString.baseBuffer[12],
                         idWeapon::GetZoomTime(this: weapon));
          LODWORD(v18) = idClientGame::GetPlayerGameTime(this: clientGame);
          HIDWORD(v18) = (char *)this + 0x10000;
          this->zoomFov.duration = v17;
          this->zoomFov.startValue = v15;
          this->zoomFov.endValue = v16;
          this->zoomFov.currentValue = v15;
          this->zoomFov.startTime = (float)v18;
          this->zoomFov.currentTime = (float)v18 - (float)1.0;
        }
      }
    }
  }
}


// ========================================================================
// ?GetEyeOffset@idPresentablePlayer@@QBA?BVidVec3@@XZ
// EA  : 0x82B84480
// RVA : 0x00B84480
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetEyeOffset(
        idPresentablePlayer *this,
        idPresentablePlayer *result)
{
  double valueFloat; // fp0
  idPresentablePlayer *v4; // r3
  bool v5; // zf

  valueFloat = pm_normalviewheight.valueFloat;
  *(float *)&this->__vftable = 0.0;
  *((float *)&this->__vftable + 1) = 0.0;
  *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = valueFloat;
  v5 = (unsigned __int8)idPresentablePlayer::IsCrouching(this: result) == 0;
  v4 = this;
  if ( !v5 )
  {
    *(float *)&this->__vftable = 0.0;
    *((float *)&this->__vftable + 1) = 0.0;
    *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = pm_crouchviewheight.valueFloat;
  }
  return v4;
}


// ========================================================================
// ?SelectWeapon@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B84500
// RVA : 0x00B84500
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SelectWeapon(idPresentablePlayer *this, idDeclTypeInfo *num)
{
  idInventoryCollection *v4; // r29
  int v5; // r30
  idWeapon *InventoryItem; // r3
  idWeapon *v7; // r3
  idWeapon *v8; // r31
  const idDeclInventory *decl; // r11
  const idDeclAmmo *NextAmmoDecl; // r5

  v4 = this->GetInventory(this);
  v5 = 0;
  if ( (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v4) > 0 )
  {
    while ( 1 )
    {
      InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v4, index: v5);
      v7 = idWeapon::CastTo(c: InventoryItem);
      v8 = v7;
      if ( v7 != nullptr )
      {
        decl = v7->decl;
        if ( decl[1].parent == num )
          break;
      }
      if ( ++v5 >= (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v4) )
        return;
    }
    if ( this->GetEquippedWeapon(this, a2: decl->equipSlot) == v7 )
    {
      NextAmmoDecl = idPresentablePlayer::GetNextAmmoDecl(this);
      if ( NextAmmoDecl != nullptr )
        idHands::SelectAmmo(this: &this->hands, slot: EQUIP_RIGHT_HAND, ammoDecl: NextAmmoDecl);
    }
    else
    {
      idHands::SelectWeapon(
        this: &this->hands,
        slot: (const equipSlot_t)v8->decl->equipSlot,
        weapon: v8,
        useIntroBringUp: false);
    }
  }
}


// ========================================================================
// ?ClearWeaponKick@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B845F0
// RVA : 0x00B845F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClearWeaponKick(idPresentablePlayer *this)
{
  this->weaponKick[0].recoilOffset.startTime = 0.0;
  this->weaponKick[0].recoilOffset.duration = 0.0;
  this->weaponKick[0].recoilOffset.startValue = 0.0;
  this->weaponKick[0].recoilOffset.endValue = 0.0;
  this->weaponKick[0].recoilOffset.currentTime = -1.0;
  this->weaponKick[0].recoilOffset.currentValue = 0.0;
  this->weaponKick[0].recoveryOffset.startTime = 0.0;
  this->weaponKick[0].recoveryOffset.duration = 0.0;
  this->weaponKick[0].recoveryOffset.startValue = 0.0;
  this->weaponKick[0].recoveryOffset.endValue = 0.0;
  this->weaponKick[0].recoveryOffset.currentTime = -1.0;
  this->weaponKick[0].recoveryOffset.currentValue = 0.0;
  this->weaponKick[1].recoilOffset.startTime = 0.0;
  this->weaponKick[1].recoilOffset.duration = 0.0;
  this->weaponKick[1].recoilOffset.startValue = 0.0;
  this->weaponKick[1].recoilOffset.endValue = 0.0;
  this->weaponKick[1].recoilOffset.currentTime = -1.0;
  this->weaponKick[1].recoilOffset.currentValue = 0.0;
  this->weaponKick[1].recoveryOffset.startTime = 0.0;
  this->weaponKick[1].recoveryOffset.duration = 0.0;
  this->weaponKick[1].recoveryOffset.startValue = 0.0;
  this->weaponKick[1].recoveryOffset.endValue = 0.0;
  this->weaponKick[1].recoveryOffset.currentTime = -1.0;
  this->weaponKick[1].recoveryOffset.currentValue = 0.0;
  this->weaponKick[2].recoilOffset.startTime = 0.0;
  this->weaponKick[2].recoilOffset.duration = 0.0;
  this->weaponKick[2].recoilOffset.startValue = 0.0;
  this->weaponKick[2].recoilOffset.endValue = 0.0;
  this->weaponKick[2].recoilOffset.currentTime = -1.0;
  this->weaponKick[2].recoilOffset.currentValue = 0.0;
  this->weaponKick[2].recoveryOffset.startTime = 0.0;
  this->weaponKick[2].recoveryOffset.duration = 0.0;
  this->weaponKick[2].recoveryOffset.startValue = 0.0;
  this->weaponKick[2].recoveryOffset.endValue = 0.0;
  this->weaponKick[2].recoveryOffset.currentTime = -1.0;
  this->weaponKick[2].recoveryOffset.currentValue = 0.0;
  this->weaponKick[3].recoilOffset.startTime = 0.0;
  this->weaponKick[3].recoilOffset.duration = 0.0;
  this->weaponKick[3].recoilOffset.startValue = 0.0;
  this->weaponKick[3].recoilOffset.endValue = 0.0;
  this->weaponKick[3].recoilOffset.currentTime = -1.0;
  this->weaponKick[3].recoilOffset.currentValue = 0.0;
  this->weaponKick[3].recoveryOffset.startTime = 0.0;
  this->weaponKick[3].recoveryOffset.duration = 0.0;
  this->weaponKick[3].recoveryOffset.startValue = 0.0;
  this->weaponKick[3].recoveryOffset.endValue = 0.0;
  this->weaponKick[3].recoveryOffset.currentTime = -1.0;
  this->weaponKick[3].recoveryOffset.currentValue = 0.0;
  this->weaponKick[4].recoilOffset.startTime = 0.0;
  this->weaponKick[4].recoilOffset.duration = 0.0;
  this->weaponKick[4].recoilOffset.startValue = 0.0;
  this->weaponKick[4].recoilOffset.endValue = 0.0;
  this->weaponKick[4].recoilOffset.currentTime = -1.0;
  this->weaponKick[4].recoilOffset.currentValue = 0.0;
  this->weaponKick[4].recoveryOffset.startTime = 0.0;
  this->weaponKick[4].recoveryOffset.duration = 0.0;
  this->weaponKick[4].recoveryOffset.startValue = 0.0;
  this->weaponKick[4].recoveryOffset.endValue = 0.0;
  this->weaponKick[4].recoveryOffset.currentTime = -1.0;
  this->weaponKick[4].recoveryOffset.currentValue = 0.0;
  this->savedViewPitchForKick = 0.0;
}


// ========================================================================
// ?UpdateWeaponKick@idPresentablePlayer@@QAAXAAVidAngles@@@Z
// EA  : 0x82B84728
// RVA : 0x00B84728
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateWeaponKick(idPresentablePlayer *this, idAngles *viewAngles)
{
  idWeaponKick *v3; // r31
  double Offset; // fp30
  idAngles *p_viewAngles; // r11

  v3 = &this->weaponKick[2];
  Offset = idWeaponKick::GetOffset(this: &this->weaponKick[2]);
  if ( Offset < 0.0 )
  {
    if ( idPresentablePlayer::GetControl(this) != nullptr )
      p_viewAngles = &this->ucmdTracker2.viewAngles;
    else
      p_viewAngles = &this->ucmdTracker1.viewAngles;
    if ( __fabs((float)(this->savedViewPitchForKick - p_viewAngles->pitch)) > 0.5 )
    {
      viewAngles->pitch = viewAngles->pitch + (float)Offset;
      v3->recoilOffset.startTime = 0.0;
      v3->recoilOffset.duration = 0.0;
      v3->recoilOffset.startValue = 0.0;
      v3->recoilOffset.endValue = 0.0;
      v3->recoilOffset.currentTime = -1.0;
      v3->recoilOffset.currentValue = 0.0;
      v3->recoveryOffset.startTime = 0.0;
      v3->recoveryOffset.duration = 0.0;
      v3->recoveryOffset.startValue = 0.0;
      v3->recoveryOffset.endValue = 0.0;
      v3->recoveryOffset.currentTime = -1.0;
      v3->recoveryOffset.currentValue = 0.0;
      this->savedViewPitchForKick = viewAngles->pitch;
    }
  }
}


// ========================================================================
// ?GetCurWeaponSpread@idPresentablePlayer@@QBAM_N@Z
// EA  : 0x82B84828
// RVA : 0x00B84828
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

float __fastcall idPresentablePlayer::GetCurWeaponSpread(idPresentablePlayer *this, bool secondary)
{
  __int64 v4; // r11
  double CurrentValue; // fp30
  double spread; // fp31
  idWeapon *ControlWeapon; // r3
  idWeapon *v8; // r30
  __int64 v9; // r11
  double v10; // fp1

  LODWORD(v4) = idClientGame::GetPlayerGameTime(this: clientGame);
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->baseWeaponSpread, time: (float)v4);
  spread = 0.0;
  ControlWeapon = (idWeapon *)idPresentablePlayer::GetControlWeapon(this);
  v8 = ControlWeapon;
  if ( ControlWeapon != nullptr
    && idWeapon::GetCurrentProjectileDecl(this: ControlWeapon, secondaryAmmo: secondary) != nullptr )
  {
    spread = idWeapon::GetCurrentProjectileDecl(this: v8, secondaryAmmo: secondary)->spread;
  }
  LODWORD(v9) = idClientGame::GetPlayerGameTime(this: clientGame);
  v10 = (float)((float)((float)((float)(idInterpolate<float>::GetCurrentValue(
                                          this: &this->kickWeaponSpread,
                                          time: (float)v9)
                                      + (float)1.0)
                              * (float)spread)
                      * (float)CurrentValue)
              * g_weaponSpreadScale.valueFloat);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?UpdateWeaponAmmoInfo@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B84910
// RVA : 0x00B84910
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateWeaponAmmoInfo(idPresentablePlayer *this)
{
  idEntity *Control; // r3
  int v3; // r11
  char v4; // r11
  bool v5; // zf
  idProp_WeaponStatic *v6; // r3
  idProp_WeaponStatic *v7; // r28
  idWeapon *weapon; // r11
  idAmmoItem *ammoClip; // r10
  int burstMode; // r11

  if ( idPlayer::GetControl(this: (idPlayer *)this->entity) == nullptr )
    goto LABEL_13;
  Control = idPlayer::GetControl(this: (idPlayer *)this->entity);
  v3 = *(_DWORD *)(Control->GetType(this: Control) + 36);
  if ( v3 < idProp_WeaponStatic::Type.typeNum || (v5 = v3 <= idProp_WeaponStatic::Type.lastChild, v4 = 1, !v5) )
    v4 = 0;
  if ( v4 != 0 )
  {
    this->hudInfo.weaponAmmoStatus[1].show = false;
    this->hudInfo.weaponAmmoStatus[1].staticCounter = false;
    this->hudInfo.weaponAmmoStatus[1].nextAnimState = 0;
    this->hudInfo.weaponAmmoStatus[1].ammoClipCount = 0;
    this->hudInfo.weaponAmmoStatus[1].ammoTotalCount = 0;
    this->hudInfo.weaponAmmoStatus[1].burstMode = BURSTMODE_FULLAUTO;
    this->hudInfo.weaponAmmoStatus[1].dwAvailable = false;
    this->hudInfo.weaponAmmoStatus[1].renderReceipt = false;
    this->hudInfo.weaponAmmoStatus[2].show = false;
    this->hudInfo.weaponAmmoStatus[2].staticCounter = false;
    this->hudInfo.weaponAmmoStatus[2].nextAnimState = 0;
    this->hudInfo.weaponAmmoStatus[2].ammoClipCount = 0;
    this->hudInfo.weaponAmmoStatus[2].ammoTotalCount = 0;
    this->hudInfo.weaponAmmoStatus[2].burstMode = BURSTMODE_FULLAUTO;
    this->hudInfo.weaponAmmoStatus[2].dwAvailable = false;
    this->hudInfo.weaponAmmoStatus[2].renderReceipt = false;
    this->hudInfo.weaponAmmoStatus[3].show = false;
    this->hudInfo.weaponAmmoStatus[3].staticCounter = false;
    this->hudInfo.weaponAmmoStatus[3].nextAnimState = 0;
    this->hudInfo.weaponAmmoStatus[3].ammoClipCount = 0;
    this->hudInfo.weaponAmmoStatus[3].ammoTotalCount = 0;
    this->hudInfo.weaponAmmoStatus[3].burstMode = BURSTMODE_FULLAUTO;
    this->hudInfo.weaponAmmoStatus[3].dwAvailable = false;
    this->hudInfo.weaponAmmoStatus[3].renderReceipt = false;
    v6 = (idProp_WeaponStatic *)idPlayer::GetControl(this: (idPlayer *)this->entity);
    v7 = idProp_WeaponStatic::CastTo(c: v6);
    if ( idLaserCutter::CastTo(c: (idLaserCutter *)v7->weapon) != nullptr )
    {
      if ( this->hudInfo.weaponAmmoStatus[0].renderReceipt )
      {
        this->hudInfo.weaponAmmoStatus[0].show = false;
        this->hudInfo.weaponAmmoStatus[0].staticCounter = false;
        this->hudInfo.weaponAmmoStatus[0].nextAnimState = 0;
        this->hudInfo.weaponAmmoStatus[0].ammoClipCount = 0;
        this->hudInfo.weaponAmmoStatus[0].ammoTotalCount = 0;
        this->hudInfo.weaponAmmoStatus[0].burstMode = BURSTMODE_FULLAUTO;
        this->hudInfo.weaponAmmoStatus[0].dwAvailable = false;
        this->hudInfo.weaponAmmoStatus[0].renderReceipt = false;
        this->hudInfo.laserCutterStatus.charge = 0.0;
        this->hudInfo.laserCutterStatus.canShoot = false;
        this->hudInfo.laserCutterStatus.show = false;
        this->hudInfo.laserCutterStatus.nextAnimState = 0;
        this->hudInfo.laserCutterStatus.cuttingMode = true;
        this->hudInfo.laserCutterStatus.shootingFullAuto = false;
        this->hudInfo.laserCutterFuncLensStatus.showPrim = false;
        this->hudInfo.laserCutterFuncLensStatus.showSec = false;
        this->hudInfo.laserCutterFuncLensStatus.showStatic = false;
        this->hudInfo.laserCutterFuncLensStatus.nextAnimState = 0;
        this->hudInfo.laserCutterFuncLensStatus.iconPrim = FUNCTIONALITY_LENS_ZOOM;
        this->hudInfo.laserCutterFuncLensStatus.iconSec = FUNCTIONALITY_LENS_ZOOM;
        this->hudInfo.laserCutterFuncLensStatus.iconStatic = FUNCTIONALITY_LENS_ZOOM;
        this->hudInfo.laserCutterStatus.charge = (float)1.0 - idProp_WeaponStatic::GetOverheatRatio(this: v7);
        this->hudInfo.laserCutterStatus.cuttingMode = true;
        this->hudInfo.laserCutterStatus.show = true;
        weapon = v7->weapon;
        ammoClip = weapon->ammoClip;
        if ( ammoClip != nullptr )
          burstMode = ammoClip->burstMode;
        else
          burstMode = weapon->decl[1].attachmentInfo.num;
        this->hudInfo.laserCutterStatus.canShoot = true;
        this->hudInfo.laserCutterStatus.shootingFullAuto = (_cntlzw(burstMode - 2) & 0x20) != 0;
      }
    }
    else
    {
      this->hudInfo.weaponAmmoStatus[0].show = false;
      this->hudInfo.weaponAmmoStatus[0].staticCounter = false;
      this->hudInfo.weaponAmmoStatus[0].nextAnimState = 0;
      this->hudInfo.weaponAmmoStatus[0].ammoClipCount = 0;
      this->hudInfo.weaponAmmoStatus[0].ammoTotalCount = 0;
      this->hudInfo.weaponAmmoStatus[0].burstMode = BURSTMODE_FULLAUTO;
      this->hudInfo.weaponAmmoStatus[0].dwAvailable = false;
      this->hudInfo.weaponAmmoStatus[0].renderReceipt = false;
      this->hudInfo.laserCutterStatus.charge = 0.0;
      this->hudInfo.laserCutterStatus.canShoot = false;
      this->hudInfo.laserCutterStatus.show = false;
      this->hudInfo.laserCutterStatus.nextAnimState = 0;
      this->hudInfo.laserCutterStatus.cuttingMode = true;
      this->hudInfo.laserCutterStatus.shootingFullAuto = false;
      this->hudInfo.laserCutterFuncLensStatus.showPrim = false;
      this->hudInfo.laserCutterFuncLensStatus.showSec = false;
      this->hudInfo.laserCutterFuncLensStatus.showStatic = false;
      this->hudInfo.laserCutterFuncLensStatus.nextAnimState = 0;
      this->hudInfo.laserCutterFuncLensStatus.iconPrim = FUNCTIONALITY_LENS_ZOOM;
      this->hudInfo.laserCutterFuncLensStatus.iconSec = FUNCTIONALITY_LENS_ZOOM;
      this->hudInfo.laserCutterFuncLensStatus.iconStatic = FUNCTIONALITY_LENS_ZOOM;
      this->hudInfo.laserCutterFuncLensStatus.showPrim = false;
      this->hudInfo.laserCutterFuncLensStatus.showSec = false;
      this->hudInfo.laserCutterFuncLensStatus.showStatic = false;
      this->hudInfo.laserCutterFuncLensStatus.nextAnimState = 0;
      this->hudInfo.laserCutterFuncLensStatus.iconPrim = FUNCTIONALITY_LENS_ZOOM;
      this->hudInfo.laserCutterFuncLensStatus.iconSec = FUNCTIONALITY_LENS_ZOOM;
      this->hudInfo.laserCutterFuncLensStatus.iconStatic = FUNCTIONALITY_LENS_ZOOM;
    }
  }
  else
  {
LABEL_13:
    idPresentablePlayer::SetAmmoStatus(this, leftHand: true);
    idPresentablePlayer::SetAmmoStatus(this, leftHand: false);
  }
}


// ========================================================================
// ?WeaponFireFeedback@idPresentablePlayer@@QAAXPBVidWeapon@@PBVidDeclProjectile@@@Z
// EA  : 0x82B84BE0
// RVA : 0x00B84BE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentablePlayer::WeaponFireFeedback(
        idPresentablePlayer *this,
        idWeapon *weapon,
        const idDeclProjectile *projDecl)
{
  idPlayer *entity; // r29
  const idDeclTutorialEvent *reloadTutorial; // r4
  __int64 v8; // r11
  double CurrentValue; // fp1
  double spreadAdditionMax; // fp31
  double v11; // fp30
  __int64 v12; // r10
  double v13; // fp29
  int PlayerGameTime; // r3
  idAngles *p_viewAngles; // r11
  double maxKick; // fp13
  float pitch; // r29
  double recoilSpeed; // fp12
  float yaw; // r27
  double recoverySpeed; // fp11
  float roll; // r11
  double v24; // fp31
  double v25; // fp9
  double v26; // fp8
  double v27; // fp7
  unsigned int v28; // r10
  __int64 v29; // r10 OVERLAPPED
  double v30; // fp5
  double v31; // fp4
  double v32; // fp3
  idAmmoItem *v33; // r11
  __int32 v34; // r11
  double v35; // fp13
  double v36; // fp12
  __int64 v37; // r10
  double v38; // fp11
  __int64 v39; // r10
  int v40; // r4
  float v41; // [sp+50h] [-80h] BYREF
  float kick; // [sp+54h] [-7Ch] BYREF
  float v43; // [sp+58h] [-78h] BYREF
  float v44; // [sp+5Ch] [-74h] BYREF
  float v45[2]; // [sp+60h] [-70h] BYREF
  unsigned __int64 v46; // [sp+68h] [-68h] BYREF
  float v47; // [sp+70h] [-60h]
  float v48; // [sp+74h] [-5Ch]
  float v49; // [sp+78h] [-58h]

  if ( com_multiplayer.valueInteger == 0 && this->IsLocallyControlled(this) && weapon != nullptr )
  {
    entity = (idPlayer *)this->entity;
    if ( entity != nullptr
      && ((double (__fastcall *)(idWeapon *, _DWORD))weapon->AmmoInClipPercentage)(a1: weapon, a2: 0) < 0.34999999
      && idPlayer::GetControl(this: entity) == nullptr )
    {
      reloadTutorial = this->playerProps->tutorialData.reloadTutorial;
      if ( reloadTutorial != nullptr )
        idPlayer::ShowTutorialGui(this: entity, decl: reloadTutorial, activatingEntity: nullptr);
    }
  }
  idPlayerHud::ActivateCombatHud(this: &this->playerHud);
  LODWORD(v8) = idClientGame::GetPlayerGameTime(this: clientGame);
  v46 = v8;
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->kickWeaponSpread, time: (float)v8);
  spreadAdditionMax = projDecl->weaponFeedBack.spreadAdditionMax;
  v11 = (float)((float)CurrentValue + projDecl->weaponFeedBack.spreadAdditionPerShot);
  LODWORD(v12) = idClientGame::GetPlayerGameTime(this: clientGame);
  v13 = idInterpolate<float>::GetCurrentValue(this: &this->kickWeaponSpread, time: (float)v12);
  PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
  _FP9 = (float)((float)spreadAdditionMax - (float)v11);
  v46 = __PAIR64__(0x82000000, PlayerGameTime);
  __asm { fsel      f5, f9, f30, f31 }
  this->kickWeaponSpread.startValue = v13;
  this->kickWeaponSpread.startTime = (float)__SPAIR64__(0x82000000, PlayerGameTime);
  this->kickWeaponSpread.endValue = _FP5;
  this->kickWeaponSpread.duration = 67.0;
  this->kickWeaponSpread.currentValue = v13;
  this->kickWeaponSpread.currentTime = (float)__SPAIR64__(0x82000000, PlayerGameTime) - (float)1.0;
  if ( g_weaponkick.valueInteger != 0 )
  {
    if ( idPresentablePlayer::GetControl(this) != nullptr )
      p_viewAngles = &this->ucmdTracker2.viewAngles;
    else
      p_viewAngles = &this->ucmdTracker1.viewAngles;
    maxKick = projDecl->weaponFeedBack.weaponKickInfo[1].maxKick;
    pitch = p_viewAngles->pitch;
    recoilSpeed = projDecl->weaponFeedBack.weaponKickInfo[1].recoilSpeed;
    yaw = p_viewAngles->yaw;
    recoverySpeed = projDecl->weaponFeedBack.weaponKickInfo[1].recoverySpeed;
    roll = p_viewAngles->roll;
    kick = projDecl->weaponFeedBack.weaponKickInfo[1].kick;
    v41 = maxKick;
    v44 = recoilSpeed;
    v43 = recoverySpeed;
    v24 = 0.0;
    v47 = pitch;
    v48 = yaw;
    v49 = roll;
    idWeaponKick::Init(
      this: &this->weaponKick[1],
      &kick,
      maxKick: &v41,
      inSpeed: &v44,
      outSpeed: &v43,
      additiveKick: 0x82000000,
      recoveryDelay: 0.0);
    v25 = projDecl->weaponFeedBack.weaponKickInfo[0].maxKick;
    v26 = projDecl->weaponFeedBack.weaponKickInfo[0].recoilSpeed;
    v27 = projDecl->weaponFeedBack.weaponKickInfo[0].recoverySpeed;
    kick = projDecl->weaponFeedBack.weaponKickInfo[0].kick;
    v41 = v25;
    v44 = v26;
    v43 = v27;
    idWeaponKick::Init(
      this: this->weaponKick,
      &kick,
      maxKick: &v41,
      inSpeed: &v44,
      outSpeed: &v43,
      additiveKick: v28,
      recoveryDelay: 0.0);
    v30 = projDecl->weaponFeedBack.weaponKickInfo[2].maxKick;
    v31 = projDecl->weaponFeedBack.weaponKickInfo[2].recoilSpeed;
    v32 = projDecl->weaponFeedBack.weaponKickInfo[2].recoverySpeed;
    kick = projDecl->weaponFeedBack.weaponKickInfo[2].kick;
    v41 = v30;
    v44 = v31;
    v43 = v32;
    if ( weapon != nullptr )
    {
      LODWORD(v29) = weapon->weaponState;
      v33 = (_DWORD)v29 == 1 ? weapon->ammoClipSecondary : weapon->ammoClip;
      v34 = v33 != nullptr ? v33->burstMode : weapon->decl[1].attachmentInfo.num;
      if ( v34 != 0 )
      {
        HIDWORD(v29) = idWeapon::GetFiringInterval(this: weapon, secondaryAmmo: (_cntlzw(v29 - 1) & 0x20) != 0);
        v46 = *(__int64 *)((char *)&v29 + 4);
        v24 = (float)*(__int64 *)((char *)&v29 + 4);
      }
    }
    HIDWORD(v29) = 1;
    idWeaponKick::Init(
      this: &this->weaponKick[2],
      &kick,
      maxKick: &v41,
      inSpeed: &v44,
      outSpeed: &v43,
      additiveKick: v29,
      recoveryDelay: v24);
    v35 = projDecl->weaponFeedBack.weaponKickInfo[3].maxKick;
    v36 = projDecl->weaponFeedBack.weaponKickInfo[3].recoilSpeed;
    HIDWORD(v37) = 1;
    v38 = projDecl->weaponFeedBack.weaponKickInfo[3].recoverySpeed;
    kick = projDecl->weaponFeedBack.weaponKickInfo[3].kick;
    v41 = v35;
    v44 = v36;
    v43 = v38;
    idWeaponKick::Init(
      this: &this->weaponKick[3],
      &kick,
      maxKick: &v41,
      inSpeed: &v44,
      outSpeed: &v43,
      additiveKick: v37,
      recoveryDelay: v24);
    if ( idPresentablePlayer::IsFullyZoomedOut(this) )
    {
      HIDWORD(v39) = 1;
      v45[0] = v41 * (float)0.46000001;
      *(float *)&v46 = kick * (float)0.46000001;
      idWeaponKick::Init(
        this: &this->weaponKick[4],
        kick: (const float *)&v46,
        maxKick: v45,
        inSpeed: &v44,
        outSpeed: &v43,
        additiveKick: v39,
        recoveryDelay: v24);
    }
    this->savedViewPitchForKick = v47;
    idView::SetControllerShake(
      this: &this->view,
      highMagnitude: projDecl->weaponFeedBack.controllerShakeHighMag,
      highDuration: v40,
      lowMagnitude: projDecl->weaponFeedBack.controllerShakeLowMag,
      lowDuration: projDecl->weaponFeedBack.controllerShakeHighTime);
  }
}


// ========================================================================
// ?GetEquippedWeapon@idPresentablePlayer@@UBAPAVidWeapon@@W4equipSlot_t@@@Z
// EA  : 0x82B84FD0
// RVA : 0x00B84FD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idWeapon *__fastcall idPresentablePlayer::GetEquippedWeapon(idPresentablePlayer *this, equipSlot_t slot)
{
  idWeapon *result; // r3

  result = (idWeapon *)((int (__fastcall *)(idEntity *, equipSlot_t))this->entity->idPresentableActor::idPresentableAnimatedEntity::idPresentable::__vftable[1].SetColor_5)(
                         a1: this->entity,
                         a2: slot);
  if ( result != nullptr )
    return idWeapon::CastTo(c: result);
  return result;
}


// ========================================================================
// ?DamageDealtFeedback@idPresentablePlayer@@QAAXPAVidPresentable@@_N@Z
// EA  : 0x82B85020
// RVA : 0x00B85020
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DamageDealtFeedback(
        idPresentablePlayer *this,
        idPresentable *victim,
        bool predicted)
{
  idPresentable *Control; // r3
  float x; // r5
  const idDeclPlayerProps *playerProps; // r11
  idDeclPlayerProps::playerSounds_t sounds; // [sp+50h] [-1C0h] BYREF
  _BYTE v10[240]; // [sp+120h] [-F0h] BYREF

  if ( victim != nullptr )
  {
    if ( common->IsServer(this: common) && !this->IsLocallyControlled(this) && !predicted )
      this->damageDealtBuffer[this->damageDealtBufferIndex++ % 4].victim.spawnId = victim->spawnId;
    if ( idPresentablePlayer::GetControl(this) != nullptr )
    {
      Control = idPresentablePlayer::GetControl(this);
      if ( Control->GetVehicleInterface(this: Control) != nullptr )
      {
        if ( LODWORD(idPresentablePlayer::GetPlayerSounds(
                       this: (idPresentablePlayer *)v10,
                       result: (const idDeclPlayerProps::playerSounds_t *)this)->clipModelInfo.size.x) == 0 )
          return;
        x = idPresentablePlayer::GetPlayerSounds(
              this: (idPresentablePlayer *)v10,
              result: (const idDeclPlayerProps::playerSounds_t *)this)->clipModelInfo.size.x;
        goto LABEL_15;
      }
    }
    playerProps = this->playerProps;
    if ( playerProps != nullptr )
      sounds = playerProps->sounds;
    else
      idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
    if ( sounds.sndMPDmgDealtFeedback != nullptr )
    {
      x = *(float *)&idPresentablePlayer::GetPlayerSounds(
                       this: (idPresentablePlayer *)v10,
                       result: (const idDeclPlayerProps::playerSounds_t *)this)->clipModelInfo.type;
LABEL_15:
      idPresentablePlayer::PlayLocalSound(
        this,
        channel: SND_CHANNEL_ANY,
        shader: (const idSoundShader *)LODWORD(x),
        soundShaderFlags: (soundShaderFlags_t)0);
    }
  }
}


// ========================================================================
// ?UpdateDecal@idPresentablePlayer@@QAAXMVidStr@@M@Z
// EA  : 0x82B85180
// RVA : 0x00B85180
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateDecal(
        idPresentablePlayer *this,
        double value,
        idStr *tagName,
        double decalSize,
        idStr *a5)
{
  idStr *v9; // r3
  idTreeAnimator *TreeAnimator; // r29
  char v11; // r11
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r30
  const idMD6Skel *skeleton; // r10
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  double v20; // fp0
  double v21; // fp13
  __int64 v22; // [sp+8h] [-D8h]
  __int64 v23; // [sp+10h] [-D0h]
  __int64 v24; // [sp+18h] [-C8h]
  __int64 v25; // [sp+20h] [-C0h]
  __int64 v26; // [sp+28h] [-B8h]
  __int16 v27; // [sp+50h] [-90h] BYREF
  float v28; // [sp+60h] [-80h]
  float v29; // [sp+64h] [-7Ch]
  __int64 v30; // [sp+68h] [-78h]
  idMat3x4 v31; // [sp+70h] [-70h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
LABEL_19:
    v9 = a5;
    goto LABEL_20;
  }
  if ( __fabs((float)(this->lastDecalValue - (float)value)) >= 0.000001 )
  {
    this->lastDecalValue = value;
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
    idPresentable::UpdateModelTransform(this);
    if ( TreeAnimator == nullptr || (v11 = 1, TreeAnimator->decl == nullptr) )
      v11 = 0;
    if ( v11 != 0 )
    {
      decl = TreeAnimator->decl;
      p_props = &decl->props;
      if ( decl == nullptr )
        p_props = nullptr;
      Tag = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: a5->data);
      idDeclMD6::GetJointIndex(
        this: (idDeclMD6 *)&v27,
        result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator->decl,
        handle: &Tag->parentJoint);
      if ( v27 >= 0 )
      {
        skeleton = TreeAnimator->decl->model->skeleton;
        if ( skeleton != nullptr && (v16 = (int)skeleton->data + skeleton->data->inverseBasePoseOffset) != 0 )
        {
          v31 = *(idMat3x4 *)(48 * v27 + v16);
          idMat3x4::Invert(this: &v31);
          v20 = 0.0;
          v21 = (float)(v31.mat[11]
                      + (float)((float)(Tag->trans.y * v31.mat[9])
                              + (float)((float)(Tag->trans.x * v31.mat[8]) + (float)(Tag->trans.z * v31.mat[10]))));
          if ( value < 0.0 || (v20 = 1.0, value > 1.0) )
            value = v20;
          v28 = (float)((float)(Tag->trans.y * v31.mat[5])
                      + (float)((float)(Tag->trans.x * v31.mat[4]) + (float)(Tag->trans.z * v31.mat[6])))
              + v31.mat[7];
          v29 = v21;
          *(float *)&v30 = value;
          *((float *)&v30 + 1) = decalSize;
          idPresentable::SetParm(
            this,
            parm: (const idDeclRenderParm *)rp_DecalPos.r,
            v4: v30,
            a4: v19,
            a5: v18,
            a6: v17,
            a7: (int)&rp_DecalPos,
            a8: v22,
            a9: v23,
            a10: v24,
            a11: v25,
            a12: v26);
        }
        else
        {
          idLib::Warning(
            fmt: "idPresentableActor::UpdateDecal() - '%s'has invalid inverted Base Pose",
            this->model->name.str);
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "idPresentableActor::UpdateDecal() - '%s' has no tree animator", this->model->name.str);
    }
    goto LABEL_19;
  }
  v9 = a5;
LABEL_20:
  idStr::FreeData(this: v9);
}


// ========================================================================
// __unwind$496008
// EA  : 0x82B853B8
// RVA : 0x00B853B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_496008()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 224 + 260));
}


// ========================================================================
// ?GetSensitivityScale@idPresentablePlayer@@QAAXAAM0@Z
// EA  : 0x82B853E0
// RVA : 0x00B853E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::GetSensitivityScale(
        idPresentablePlayer *this,
        float *mouseSensScale,
        float *joySensScale)
{
  idWeapon *v6; // r30

  v6 = this->GetEquippedWeapon(this, a2: 2);
  if ( v6 != nullptr && (unsigned __int8)idPresentablePlayer::IsFullyZoomedIn(this) != 0 )
  {
    idWeapon::GetSensitivityScale(this: v6, mouseSensScale, joySensScale);
  }
  else
  {
    *mouseSensScale = 1.0;
    *joySensScale = 1.0;
  }
}


// ========================================================================
// ?Draw_Shared@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B85460
// RVA : 0x00B85460
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::Draw_Shared(idPresentablePlayer *this)
{
  double v2; // fp1
  char *v3; // r10
  int v4; // ctr
  float *p_z; // r11
  float y; // r7
  float z; // r6
  double v8; // fp7
  double v9; // fp6
  idMat3 *v10; // r3
  float *v11; // r3
  double v12; // fp1
  char v13; // r30
  int v14; // r4
  float v15; // r4
  float pitch; // r7
  float yaw; // r6
  float roll; // r5
  double v19; // fp13
  const idWeapon *ControlWeapon; // r3
  double CurWeaponSpread; // fp27
  long double v22; // fp2
  long double v23; // fp2
  double v24; // fp30
  __int64 v25; // r11
  float *v26; // r29
  int v27; // r30
  double v28; // fp26
  long double v29; // fp2
  double v30; // fp5
  double v31; // fp26
  double v32; // fp25
  double v33; // fp24
  double v34; // fp10
  double v35; // fp9
  double v36; // fp0
  double v37; // fp13
  const idVec3 *v38; // r30
  int i; // r29
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  double v43; // fp6
  double v44; // fp4
  va *v45; // r3
  idPlayer *entity; // r4
  idSpringCamera *springCamera; // r3
  int v48; // [sp+8h] [-1338h]
  int v49; // [sp+Ch] [-1334h]
  int v50; // [sp+10h] [-1330h]
  int v51; // [sp+14h] [-132Ch]
  int v52; // [sp+18h] [-1328h]
  int v53; // [sp+1Ch] [-1324h]
  idVec3 v54; // [sp+60h] [-12E0h] BYREF
  __int64 v55; // [sp+70h] [-12D0h] BYREF
  float v56; // [sp+78h] [-12C8h]
  char v57; // [sp+7Ch] [-12C4h] BYREF
  idMat3 v58; // [sp+80h] [-12C0h] BYREF
  float v59[2]; // [sp+A8h] [-1298h] BYREF
  float v60; // [sp+B0h] [-1290h]
  float v61[6]; // [sp+B8h] [-1288h] BYREF
  idColor v62; // [sp+D0h] [-1270h] BYREF
  idVec3 v63; // [sp+E0h] [-1260h] BYREF
  idMat3 v64; // [sp+F0h] [-1250h] BYREF
  idMat3 v65; // [sp+120h] [-1220h] BYREF
  int v66; // [sp+14Ch] [-11F4h] BYREF
  char v67; // [sp+15Ch] [-11E4h] BYREF
  va v68; // [sp+2C0h] [-1080h] BYREF

  this->view.viewVelocity = *(idVec3 *)((int (__fastcall *)(float *))this->physicsObj.GetLinearVelocity)(a1: v59);
  idPresentablePlayer::CheckFovModified(this);
  if ( vehicle_cam.valueInteger != 0
    && idVehicle::GetVehicleCameraView(origin: &v63, axis: &v64, fov_x: (float *)&v55, view: &this->view) )
  {
    idView::SetViewPos(this: &this->view, origin: &v63, axis: &v64);
    v2 = idPresentablePlayer::CalcFov(this, honorZoom: true);
    this->lastFov = v2;
    idView::CalcFOV(this: &this->view, base_fov: v2);
    idView::Render(this: &this->view);
  }
  else
  {
    v3 = &v57;
    v4 = 9;
    p_z = &this->firstPersonViewOrigin.z;
    y = this->firstPersonViewOrigin.y;
    z = this->firstPersonViewOrigin.z;
    v54.x = this->firstPersonViewOrigin.x;
    v54.y = y;
    v54.z = z;
    do
    {
      ++p_z;
      v3 += 4;
      *(float *)v3 = *p_z;
      --v4;
    }
    while ( v4 != 0 );
    if ( idPresentablePlayer::GetControl(this) == nullptr )
    {
      if ( this->addViewAnglBlendState != ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT )
      {
        v8 = (float)(this->addViweOffset.y + v54.y);
        v9 = (float)(this->addViweOffset.z + v54.z);
        v54.x = this->addViweOffset.x + v54.x;
        v54.y = v8;
        v54.z = v9;
        v10 = idAngles::ToMat3(this: (idAngles *)&v64, result: (idMat3 *)&this->addViewAngles);
        v11 = (float *)idMat3::operator*(this: &v65, result: v10, a: &v58);
        v58.mat[0].x = *v11;
        v58.mat[0].y = v11[1];
        v58.mat[0].z = v11[2];
        v58.mat[1].x = v11[3];
        v58.mat[1].y = v11[4];
        v58.mat[1].z = v11[5];
        v58.mat[2].x = v11[6];
        v58.mat[2].y = v11[7];
        v58.mat[2].z = v11[8];
      }
      idView::SetViewPos(this: &this->view, origin: &v54, axis: &v58);
    }
    v12 = idPresentablePlayer::CalcFov(this, honorZoom: true);
    this->lastFov = v12;
    idView::CalcFOV(this: &this->view, base_fov: v12);
    if ( this->entity == nullptr
      || !common->IsServer(this: common)
      || (v13 = 1, !idPlayer::IsBotControllingAFKPlayer(this: (idPlayer *)this->entity)) )
    {
      v13 = 0;
    }
    if ( pm_thirdPerson.valueInteger != 0 || this->IsDead(this) && (*((_BYTE *)this + 47033) & 0x20) != 0 || v13 != 0 )
      v14 = 0;
    else
      v14 = this->entityNumber + 1;
    idView::SetViewID(this: &this->view, id: v14);
    if ( idPresentablePlayer::GetControl(this) != nullptr )
    {
      this->view.viewBob = vec3_origin;
      this->view.viewBobAngles = ang_zero;
    }
    else
    {
      v15 = this->bobCycle.viewBob.y;
      pitch = this->bobCycle.viewBobAngles.pitch;
      yaw = this->bobCycle.viewBobAngles.yaw;
      roll = this->bobCycle.viewBobAngles.roll;
      v59[0] = this->bobCycle.viewBob.x;
      v19 = v59[0];
      v59[1] = v15;
      *(float *)&v55 = pitch;
      *((float *)&v55 + 1) = yaw;
      v56 = roll;
      v60 = this->bobCycle.viewBob.z;
      this->view.viewBob.z = v60;
      this->view.viewBob.y = v15;
      this->view.viewBob.x = v19;
      this->view.viewBobAngles.pitch = pitch;
      this->view.viewBobAngles.yaw = yaw;
      this->view.viewBobAngles.roll = roll;
    }
    if ( common->TimeTrialPlaying(this: common) && this->index >= 12288 )
    {
      this->model->g.suppressShadowInViewID = -1;
      this->model->g.suppressSurfaceInViewID = -1;
    }
    if ( g_showSpread.valueInteger > 0 )
    {
      ControlWeapon = idPresentablePlayer::GetControlWeapon(this);
      CurWeaponSpread = idPresentablePlayer::GetCurWeaponSpread(
                          this,
                          secondary: (_cntlzw(ControlWeapon->weaponState - 1) & 0x20) != 0);
      v62 = idColor::colorGreen;
      if ( CurWeaponSpread < 0.25 )
      {
        CurWeaponSpread = 0.25;
        v62 = idColor::colorRed;
      }
      *(double *)&v22 = (float)(idMath::M_DEG2RAD * (float)CurWeaponSpread);
      v23 = sin(x: v22);
      v24 = (float)*(double *)&v23;
      HIDWORD(v25) = byte_821B0000;
      v26 = (float *)&v66;
      v27 = 0;
      do
      {
        LODWORD(v25) = v27;
        v28 = (float)((float)((float)v25 * (float)0.034482758) * (float)(idMath::M_DEG2RAD * (float)360.0));
        *(double *)&v23 = v28;
        v55 = v25;
        v29 = cos(x: v23);
        v30 = (float)((float)*(double *)&v29 * (float)v24);
        *(double *)&v29 = v28;
        v31 = (float)(v58.mat[1].x * (float)v30);
        v32 = (float)(v58.mat[1].y * (float)v30);
        v33 = (float)(v58.mat[1].z * (float)v30);
        v23 = sin(x: v29);
        ++v27;
        v34 = v54.y;
        v35 = v54.z;
        *((double *)&v23 + 1) = (float)(v58.mat[0].z
                                      + (float)(v58.mat[2].z * (float)((float)*(double *)&v23 * (float)v24)));
        v36 = (float)((float)(v58.mat[0].y + (float)(v58.mat[2].y * (float)((float)*(double *)&v23 * (float)v24)))
                    - (float)v32);
        v37 = (float)((float)(v58.mat[0].z + (float)(v58.mat[2].z * (float)((float)*(double *)&v23 * (float)v24)))
                    - (float)v33);
        v26[1] = (float)((float)((float)(v58.mat[0].x
                                       + (float)(v58.mat[2].x * (float)((float)*(double *)&v23 * (float)v24)))
                               - (float)v31)
                       * (float)250.0)
               + v54.x;
        v26[2] = (float)((float)v36 * (float)250.0) + (float)v34;
        v26 += 3;
        *v26 = (float)((float)v37 * (float)250.0) + (float)v35;
      }
      while ( v27 < 30 );
      v38 = (const idVec3 *)&v67;
      for ( i = 29; i != 0; --i )
      {
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&v62,
          a3: &v38[-1],
          a4: v38,
          a5: 0,
          a6: false);
        ++v38;
      }
      if ( g_showSpread.valueInteger > 1 )
      {
        HIDWORD(v42) = LODWORD(CurWeaponSpread);
        v43 = this->firstPersonViewOrigin.z;
        v44 = (float)(this->firstPersonViewOrigin.y + (float)(v58.mat[0].y * (float)250.0));
        v61[0] = this->firstPersonViewOrigin.x + (float)(v58.mat[0].x * (float)250.0);
        v61[1] = v44;
        v61[2] = (float)v43 + (float)(v58.mat[0].z * (float)250.0);
        v45 = va::va(
                this: &v68,
                fmt: "%g",
                a3: v42,
                a4: v41,
                a5: v40,
                a6: v48,
                a7: v49,
                a8: v50,
                a9: v51,
                a10: v52,
                a11: v53,
                CurWeaponSpread);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, double))clientGame->renderWorld->DebugText)(
          a1: clientGame->renderWorld,
          a2: v45,
          a3: v61,
          a4: clientGame->renderWorld->__vftable,
          a5: &v62,
          a6: 1,
          a7: 0,
          a8: 0.1);
      }
    }
    idView::Render(this: &this->view);
    idPresentablePlayer::UpdateScreenParticles(this);
    idPresentablePlayer::DrawGuis(this, id: this->entityNumber + 1);
    idPresentablePlayer::DrawSubtitles(this, guidModel: this->view.guiModel);
    if ( this->IsLocallyControlled(this) )
    {
      entity = (idPlayer *)this->entity;
      if ( entity != nullptr )
      {
        springCamera = entity->springCamera;
        if ( springCamera != nullptr )
          idSpringCamera::CalculateView(this: springCamera, player: entity);
      }
    }
  }
}


// ========================================================================
// ?GetPlayerInputSettings@idPresentablePlayer@@QAA?AUinputSettings_t@@XZ
// EA  : 0x82B85B48
// RVA : 0x00B85B48
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetPlayerInputSettings(
        idPresentablePlayer *this,
        idPresentablePlayer *result)
{
  idPresentable *Control; // r3
  double v6; // fp10
  idLobbyBase *v7; // r29
  lobbyUserID_t *v8; // r4
  idLobbyBase_vtbl *v9; // r30
  idPresentablePlayer *LobbyUserID; // r3
  int v11; // r3
  double v12; // fp10
  double valueFloat; // fp0
  bool v14; // r10
  double v15; // fp13
  double v16; // fp12
  idPlayerProfileGame *v17; // r3
  float *v18; // r30
  bool InvertLook; // r29
  double v20; // fp31
  double v21; // fp30
  double v22; // fp1
  double v23; // fp0
  double v24; // fp13
  float v25; // [sp+50h] [-40h] BYREF
  float v26; // [sp+54h] [-3Ch] BYREF
  char v27; // [sp+58h] [-38h] BYREF

  if ( idPresentablePlayer::GetControl(this: result) != nullptr )
  {
    Control = idPresentablePlayer::GetControl(this: result);
    Control->GetInputSettings(this, result: (inputSettings_t *)Control, a3: result);
    return this;
  }
  else
  {
    v25 = 1.0;
    v26 = 1.0;
    idPresentablePlayer::GetSensitivityScale(this: result, mouseSensScale: &v25, joySensScale: &v26);
    if ( usercmdGen->GetUseAimAssist(this: usercmdGen) )
    {
      v6 = (float)(result->aimAssist.frictionScalar * v26);
      v25 = result->aimAssist.frictionScalar * v25;
      v26 = v6;
    }
    v7 = session->GetActingGameStateLobbyBase(this: session);
    v8 = (lobbyUserID_t *)result;
    v9 = v7->__vftable;
    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v27, result: v8);
    v11 = (int)v9->GetLocalUserFromLobbyUser(
                 this: (idLobbyBase *)LobbyUserID->__vftable,
                 a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
    if ( v11 != 0
      && (v17 = (idPlayerProfileGame *)(*(int (__fastcall **)(int))(*(_DWORD *)v11 + 72))(a1: v11),
          v18 = (float *)v17,
          v17 != nullptr) )
    {
      InvertLook = idPlayerProfileGame::GetInvertLook(this: v17);
      v20 = v18[517];
      v21 = v18[518];
      v22 = ((double (__fastcall *)(float *))*(_DWORD *)(*(_DWORD *)v18 + 20))(a1: v18);
      v23 = v25;
      BYTE1(this->origins[0].y) = InvertLook;
      v24 = v26;
      *((float *)&this->__vftable + 1) = v23;
      *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = v24;
      *(float *)&this->clipModelDynamic = v21;
      *(float *)&this->clipModelPhysID = v20;
      this->origins[0].x = v22;
    }
    else
    {
      v12 = v26;
      valueFloat = m_sensitivity.valueFloat;
      v14 = in_invertLook.valueInteger != 0;
      v15 = joy_yawSpeed.valueFloat;
      v16 = joy_pitchSpeed.valueFloat;
      *((float *)&this->__vftable + 1) = v25;
      BYTE1(this->origins[0].y) = v14;
      *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = v12;
      *(float *)&this->clipModelDynamic = v16;
      *(float *)&this->clipModelPhysID = v15;
      this->origins[0].x = valueFloat;
    }
    this->__vftable = nullptr;
    HIBYTE(this->origins[0].y) = 0;
    return this;
  }
}


// ========================================================================
// ?PlayerUpdateZoomState@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B85DF8
// RVA : 0x00B85DF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PlayerUpdateZoomState(idPresentablePlayer *this)
{
  idWeapon *weapon; // r30
  idEntity *Control; // r3
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  idProp_WeaponStatic *v7; // r3
  bool v8; // r4

  weapon = this->GetEquippedWeapon(this, a2: 2);
  if ( idPlayer::GetControl(this: (idPlayer *)this->entity) != nullptr )
  {
    Control = idPlayer::GetControl(this: (idPlayer *)this->entity);
    v4 = *(_DWORD *)(Control->GetType(this: Control) + 36);
    if ( v4 < idProp_WeaponStatic::Type.typeNum || (v6 = v4 <= idProp_WeaponStatic::Type.lastChild, v5 = 1, !v6) )
      v5 = 0;
    if ( v5 != 0 )
    {
      v7 = (idProp_WeaponStatic *)idPlayer::GetControl(this: (idPlayer *)this->entity);
      weapon = idProp_WeaponStatic::CastTo(c: v7)->weapon;
    }
  }
  if ( weapon != nullptr )
  {
    if ( weapon->decl[1].programaticallyDefined && this->wantZoom && (*((_BYTE *)this + 47032) & 0x40) == 0 )
    {
      v8 = true;
LABEL_15:
      idPresentablePlayer::SetupZoom(this, handsZoomIn: v8, weapon);
      return;
    }
    if ( !this->wantZoom && (*((_BYTE *)this + 47032) & 0x40) != 0 )
    {
      v8 = false;
      goto LABEL_15;
    }
  }
}


// ========================================================================
// ?OffsetThirdPersonView@idPresentablePlayer@@QAAXMMMPBD_N@Z
// EA  : 0x82B85F28
// RVA : 0x00B85F28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::OffsetThirdPersonView(
        idPresentablePlayer *this,
        double angle,
        double range,
        double height,
        const char *focusJoint,
        bool clip,
        int a7,
        const char *a8,
        char a9)
{
  idPhysics_Player *p_physicsObj; // r30
  double v16; // fp28
  float *v17; // r3
  double v18; // fp27
  double v19; // fp26
  double v20; // fp28
  float *v21; // r3
  double v22; // fp8
  double v23; // fp6
  idTreeAnimator *TreeAnimator; // r29
  const idIndex<short,enum invalidJointIndex_t> *v25; // r5
  idVec3 *v26; // r3
  double v27; // fp10
  double v28; // fp6
  idPhysics_Player_vtbl *v29; // r6
  const idMat3 *(__fastcall *GetGravityAxis)(struct idPhysics_Player *); // r5
  const idMat3 *v31; // r29
  idMat3 *v32; // r3
  float *v33; // r3
  long double v34; // fp2
  double v35; // fp29
  long double v36; // fp2
  double v37; // fp28
  long double v38; // fp2
  int entityNumber; // r9
  idPhysics_Player_vtbl *v40; // r11
  const idVec3 *(__fastcall *GetGravity)(struct idPhysics_Player *); // ctr
  float *v42; // r3
  double v43; // fp0
  double v44; // fp13
  double v45; // fp4
  double v46; // fp2
  double v47; // fp1
  double v48; // fp31
  idQuat *v49; // r31
  float *p_y; // r11
  double z; // fp10
  double w; // fp8
  double v53; // fp4
  double v54; // fp3
  const idQuat *v55; // r30
  const idQuat *v56; // r3
  double v59; // fp1
  double v60; // fp2
  double v61; // fp1
  idVec3 v62; // [sp+50h] [-1E0h] BYREF
  idVec3 v63; // [sp+60h] [-1D0h] BYREF
  idMat3 v64; // [sp+70h] [-1C0h] BYREF
  idMat3 v65; // [sp+A0h] [-190h] BYREF
  idMat3 v66[4]; // [sp+D0h] [-160h] BYREF
  idMat3 v67; // [sp+160h] [-D0h] BYREF
  idMat3 v68[2]; // [sp+1A0h] [-90h] BYREF

  p_physicsObj = &this->physicsObj;
  idPresentablePlayer::GetViewAngles(
    this: (idPresentablePlayer *)&v65.mat[2].z,
    result: (const idAngles *)this,
    includeWeaponKick: true);
  v16 = -*(float *)&idPresentablePlayer::GetEyeOffset(this: (idPresentablePlayer *)v66, result: this)->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId;
  v17 = (float *)p_physicsObj->GetGravityNormal(this: &this->physicsObj);
  v18 = (float)(*v17 * (float)v16);
  v19 = (float)(v17[1] * (float)v16);
  v20 = (float)(v17[2] * (float)v16);
  v21 = (float *)p_physicsObj->GetOrigin(this: &this->physicsObj, a2: 0);
  v22 = (float)(v21[2] + (float)v20);
  v23 = (float)(v21[1] + (float)v19);
  v63.x = *v21 + (float)v18;
  v63.z = v22;
  v63.y = v23;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
  idPresentable::UpdateModelTransform(this);
  if ( TreeAnimator != nullptr
    && (__int16)(v25 = (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(idTreeAnimator::GetJointIndex(
                                                                                 this: (idTreeAnimator *)&v65.mat[2].y,
                                                                                 result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator,
                                                                                 jointName: a8)->__vftable)) >= 0 )
  {
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: TreeAnimator,
      pose: DRIVER_MODEL,
      jointIndex: v25,
      origin: (idVec3 *)&v65.mat[1].y,
      axis: (idMat3 *)&v67.mat[1].y);
  }
  else
  {
    v26 = idAngles::ToForward(this: (idAngles *)v66, result: (idVec3 *)&v65.mat[2].z);
    v27 = (float)(v26->z + v63.z);
    v28 = (float)(v26->y + v63.y);
    v65.mat[1].y = v26->x + v63.x;
    v65.mat[1].z = v28;
    v65.mat[2].x = (float)v27 + (float)height;
  }
  v29 = p_physicsObj->__vftable;
  v62 = v63;
  v65.mat[2].z = v65.mat[2].z * (float)0.5;
  GetGravityAxis = v29->GetGravityAxis;
  v62.z = (float)(v63.z + (float)height) + (float)8.0;
  v31 = GetGravityAxis(this: &this->physicsObj);
  v32 = idAngles::ToMat3(this: (idAngles *)&v67.mat[1].y, result: (idMat3 *)&v65.mat[2].z);
  v33 = (float *)idMat3::operator*(this: v68, result: v32, a: v31);
  v64.mat[0].x = *v33;
  v64.mat[0].y = v33[1];
  v64.mat[0].z = v33[2];
  v64.mat[1].x = v33[3];
  v64.mat[1].y = v33[4];
  v64.mat[1].z = v33[5];
  v64.mat[2].x = v33[6];
  *((double *)&v34 + 1) = v33[7];
  v64.mat[2].y = v33[7];
  v64.mat[2].z = v33[8];
  v35 = (float)(idMath::M_DEG2RAD * (float)angle);
  *(double *)&v34 = v35;
  v36 = sin(x: v34);
  v37 = (float)*(double *)&v36;
  *(double *)&v36 = v35;
  v38 = cos(x: v36);
  v62.x = (float)(v64.mat[1].x * (float)((float)v37 * (float)range))
        + (float)(v63.x - (float)(v64.mat[0].x * (float)((float)*(double *)&v38 * (float)range)));
  v62.y = (float)(v64.mat[1].y * (float)((float)v37 * (float)range))
        + (float)(v63.y - (float)(v64.mat[0].y * (float)((float)*(double *)&v38 * (float)range)));
  v62.z = (float)(v64.mat[1].z * (float)((float)v37 * (float)range))
        + (float)(v62.z - (float)(v64.mat[0].z * (float)((float)*(double *)&v38 * (float)range)));
  if ( a9 != 0 )
  {
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: (trace_t *)&v66[0].mat[1].y,
      start: &v63,
      end: &v62,
      trm: clientGame->clip.clip8x8,
      clipMask: 3,
      passEntityNumber: this->entityNumber);
    if ( v66[0].mat[1].y != 1.0 )
    {
      v62.x = v66[0].mat[1].z;
      v62.y = v66[0].mat[2].x;
      entityNumber = this->entityNumber;
      v62.z = (float)((float)((float)1.0 - v66[0].mat[1].y) * (float)32.0) + v66[0].mat[2].y;
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: (trace_t *)&v66[0].mat[1].y,
        start: &v63,
        end: &v62,
        trm: clientGame->clip.clip8x8,
        clipMask: 3,
        passEntityNumber: entityNumber);
      v62.x = v66[0].mat[1].z;
      v62.y = v66[0].mat[2].x;
      v62.z = v66[0].mat[2].y;
    }
  }
  v40 = p_physicsObj->__vftable;
  v64.mat[0].x = v65.mat[1].y - v62.x;
  v64.mat[0].y = v65.mat[1].z - v62.y;
  GetGravity = v40->GetGravity;
  v64.mat[0].z = v65.mat[2].x - v62.z;
  v42 = (float *)GetGravity(this: &this->physicsObj);
  v43 = *v42;
  v64.mat[2].x = *v42;
  v44 = v42[1];
  v45 = (float)(v42[1] * v64.mat[0].z);
  v64.mat[2].y = v42[1];
  v46 = (float)(v42[2] * v64.mat[0].x);
  v47 = (float)((float)(v42[2] * v64.mat[0].y) - (float)v45);
  v64.mat[2].z = v42[2];
  v64.mat[1].z = (float)((float)v44 * v64.mat[0].x) - (float)((float)v43 * v64.mat[0].y);
  v64.mat[1].x = v47;
  v64.mat[1].y = (float)((float)v43 * v64.mat[0].z) - (float)v46;
  idMat3::OrthoNormalizeSelf(this: &v64);
  if ( this->IsDead(this) || (unsigned __int8)idPresentablePlayer::AFIsActive(this) != 0 )
    v48 = 0.050000001;
  else
    v48 = 0.99000001;
  v49 = (idQuat *)((char *)this + 0x10000);
  p_y = &v49[-1188].y;
  z = v49[-1188].z;
  w = v49[-1188].w;
  v53 = (float)((float)(v62.y - v49[-1188].z) * (float)v48);
  v54 = (float)((float)(v62.z - v49[-1188].w) * (float)v48);
  v49 -= 1187;
  *p_y = *p_y + (float)((float)(v62.x - *p_y) * (float)v48);
  p_y[1] = (float)v53 + (float)z;
  p_y[2] = (float)v54 + (float)w;
  v55 = idMat3::ToQuat(this: v66, result: (idQuat *)&v64);
  v56 = idMat3::ToQuat(this: &v67, result: v49);
  idQuat::Slerp(this: (idQuat *)&v65, from: v56, to: v55, t: v48);
  _FP4 = (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                       + (float)((float)(v65.mat[0].y * v65.mat[0].y)
                               + (float)((float)(v65.mat[1].x * v65.mat[1].x) + (float)(v65.mat[0].z * v65.mat[0].z))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f12 }
  v59 = __frsqrte(_FP2);
  v60 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v59
                                                                                      * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x) + (float)((float)(v65.mat[0].y * v65.mat[0].y) + (float)((float)(v65.mat[1].x * v65.mat[1].x) + (float)(v65.mat[0].z * v65.mat[0].z))))
                                                                                              * (float)0.5))
                                                                              * (float)v59)
                                                                      - (float)1.5)
                                                      * (float)v59)
                                              * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                                                              + (float)((float)(v65.mat[0].y * v65.mat[0].y)
                                                                      + (float)((float)(v65.mat[1].x * v65.mat[1].x)
                                                                              + (float)(v65.mat[0].z * v65.mat[0].z))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v59
                                                                              * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                                                                                              + (float)((float)(v65.mat[0].y * v65.mat[0].y) + (float)((float)(v65.mat[1].x * v65.mat[1].x) + (float)(v65.mat[0].z * v65.mat[0].z))))
                                                                                      * (float)0.5))
                                                                      * (float)v59)
                                                              - (float)1.5)
                                              * (float)v59))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v59
                                                      * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                                                                      + (float)((float)(v65.mat[0].y * v65.mat[0].y)
                                                                              + (float)((float)(v65.mat[1].x
                                                                                              * v65.mat[1].x)
                                                                                      + (float)(v65.mat[0].z
                                                                                              * v65.mat[0].z))))
                                                              * (float)0.5))
                                              * (float)v59)
                                      - (float)1.5)
                      * (float)v59));
  v61 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v59
                                                                                              * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x) + (float)((float)(v65.mat[0].y * v65.mat[0].y) + (float)((float)(v65.mat[1].x * v65.mat[1].x) + (float)(v65.mat[0].z * v65.mat[0].z)))) * (float)0.5))
                                                                                      * (float)v59)
                                                                              - (float)1.5)
                                                              * (float)v59)
                                                      * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                                                                      + (float)((float)(v65.mat[0].y * v65.mat[0].y)
                                                                              + (float)((float)(v65.mat[1].x
                                                                                              * v65.mat[1].x)
                                                                                      + (float)(v65.mat[0].z
                                                                                              * v65.mat[0].z))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v59
                                                                                      * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x) + (float)((float)(v65.mat[0].y * v65.mat[0].y) + (float)((float)(v65.mat[1].x * v65.mat[1].x) + (float)(v65.mat[0].z * v65.mat[0].z))))
                                                                                              * (float)0.5))
                                                                              * (float)v59)
                                                                      - (float)1.5)
                                                      * (float)v59))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v59
                                                              * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                                                                              + (float)((float)(v65.mat[0].y
                                                                                              * v65.mat[0].y)
                                                                                      + (float)((float)(v65.mat[1].x * v65.mat[1].x)
                                                                                              + (float)(v65.mat[0].z * v65.mat[0].z))))
                                                                      * (float)0.5))
                                                      * (float)v59)
                                              - (float)1.5)
                              * (float)v59))
              * (float)((float)((float)(v65.mat[0].x * v65.mat[0].x)
                              + (float)((float)(v65.mat[0].y * v65.mat[0].y)
                                      + (float)((float)(v65.mat[1].x * v65.mat[1].x)
                                              + (float)(v65.mat[0].z * v65.mat[0].z))))
                      * (float)0.5));
  v65.mat[0].x = v65.mat[0].x * (float)((float)-(float)((float)((float)v61 * (float)v60) - (float)1.5) * (float)v60);
  v65.mat[0].y = v65.mat[0].y * (float)((float)-(float)((float)((float)v61 * (float)v60) - (float)1.5) * (float)v60);
  v65.mat[0].z = v65.mat[0].z * (float)((float)-(float)((float)((float)v61 * (float)v60) - (float)1.5) * (float)v60);
  v65.mat[1].x = v65.mat[1].x * (float)((float)-(float)((float)((float)v61 * (float)v60) - (float)1.5) * (float)v60);
  *(idMat3 *)&v49->x = *idQuat::ToMat3(this: (idQuat *)v68, result: &v65);
}


// ========================================================================
// ?UpdateStepUpSprings@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B864D0
// RVA : 0x00B864D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateStepUpSprings(idPresentablePlayer *this)
{
  idCVar *v2; // r9
  idCVar *v3; // r8
  bool v4; // r7
  double v5; // fp11
  double StepUp; // fp1
  int GameMsPerFrame; // r3
  __int64 v8; // r8

  if ( !this->stepUpSpringCrouchState && (unsigned __int8)idPhysics_Player::IsCrouching(this: &this->physicsObj) != 0 )
  {
    v2 = &pm_normalviewheight;
    v3 = &pm_crouchviewheight;
    v4 = true;
LABEL_7:
    v5 = (float)(v2->valueFloat - v3->valueFloat);
    this->stepUpViewSpring.p1.x = this->stepUpViewSpring.p1.x + (float)(v2->valueFloat - v3->valueFloat);
    this->stepUpHandsSpring.p1.x = this->stepUpHandsSpring.p1.x + (float)v5;
    this->stepUpSpringCrouchState = v4;
    goto LABEL_8;
  }
  if ( this->stepUpSpringCrouchState && (unsigned __int8)idPhysics_Player::IsCrouching(this: &this->physicsObj) == 0 )
  {
    v2 = &pm_crouchviewheight;
    v3 = &pm_normalviewheight;
    v4 = false;
    goto LABEL_7;
  }
LABEL_8:
  if ( idPhysics_Player::HasSteppedUp(this: &this->physicsObj) )
  {
    StepUp = idPhysics_Player::GetStepUp(this: &this->physicsObj);
    this->stepUpViewSpring.p1.x = this->stepUpViewSpring.p1.x - (float)StepUp;
    this->stepUpHandsSpring.p1.x = this->stepUpHandsSpring.p1.x - (float)StepUp;
  }
  if ( (p_stepUpViewSpringK.flags & 0x20000) != 0 )
  {
    p_stepUpViewSpringK.flags &= ~0x20000u;
    idSpring<idVec1>::SetConstants(this: &this->stepUpViewSpring, _k: p_stepUpViewSpringK.valueFloat, _c: -1.0);
  }
  if ( (p_stepUpHandsSpringK.flags & 0x20000) != 0 )
  {
    p_stepUpHandsSpringK.flags &= ~0x20000u;
    idSpring<idVec1>::SetConstants(this: &this->stepUpHandsSpring, _k: p_stepUpHandsSpringK.valueFloat, _c: -1.0);
  }
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idSpring<idVec1>::Update(
    this: &this->stepUpViewSpring,
    dt: (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001));
  LODWORD(v8) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idSpring<idVec1>::Update(this: &this->stepUpHandsSpring, dt: (float)((float)v8 * (float)0.001));
}


// ========================================================================
// ?WeaponFireFeedback@idPresentablePlayer@@QAAXPBVidWeapon@@PBVidDeclProjectile@@ABVidFireParms@@ABVidTestFireResults@@ABVidFinishFireResults@@@Z
// EA  : 0x82B866A0
// RVA : 0x00B866A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::WeaponFireFeedback(
        idPresentablePlayer *this,
        idWeapon *weapon,
        const idDeclProjectile *projDecl,
        const idFireParms *fp,
        const idTestFireResults *tfr,
        const idFinishFireResults *ffr)
{
  if ( weapon != nullptr )
  {
    if ( common->IsServer(this: common) )
      idWeapon::IsMelee(this: weapon);
    else
      idPresentablePlayer::RecordClientFire(this, weapon, projDecl, fp, tfr, ffr);
  }
  idPresentablePlayer::WeaponFireFeedback(this, weapon, projDecl);
}


// ========================================================================
// ?GetFocusEntity@idPresentablePlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82B86730
// RVA : 0x00B86730
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

idEntity *__fastcall idPresentablePlayer::GetFocusEntity(idPresentablePlayer *this)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
    return idPlayer::GetFocusEntity(this: (idPlayer *)this->entity);
  else
    return nullptr;
}


// ========================================================================
// ?TrackUniqueProjectile@idPresentablePlayer@@QAAXPAVidPresentableProjectile@@@Z
// EA  : 0x82B867A8
// RVA : 0x00B867A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::TrackUniqueProjectile(
        idPresentablePlayer *this,
        idPresentableProjectile *projectile)
{
  unsigned int spawnId; // r11

  spawnId = 0;
  if ( projectile != nullptr )
    spawnId = projectile->spawnId;
  this->uniqueTrackedProjectile.spawnId = spawnId;
  if ( common->IsServer(this: common) )
    this->uniqueTrackedProjectileClientGameFrameWhenFired = idAccolade::Count(this: &clientGame->gameTimeManager);
  else
    this->uniqueTrackedProjectileClientGameFrameWhenFired = this->ucmdTracker2.usercmd.clientGameFrame;
}


// ========================================================================
// ?UniqueProjectileAllowed@idPresentablePlayer@@QAA_NPBVidDeclThrowable@@@Z
// EA  : 0x82B86848
// RVA : 0x00B86848
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::UniqueProjectileAllowed(
        idPresentablePlayer *this,
        const idDeclThrowable *throwableDecl)
{
  const idDeclProjectile *projectileDecl; // r11
  idPresentablePtr<idPresentable> *p_uniqueTrackedProjectile; // r31
  idPresentableProjectile *v4; // r3
  int result; // r3
  bool IsActive; // zf

  if ( throwableDecl == nullptr )
    return 1;
  projectileDecl = throwableDecl->projectileDecl;
  if ( projectileDecl == nullptr )
    return 1;
  if ( !projectileDecl->notHitscanInfo.allowOnlyOne )
    return 1;
  p_uniqueTrackedProjectile = (idPresentablePtr<idPresentable> *)&this->uniqueTrackedProjectile;
  if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->uniqueTrackedProjectile) )
    return 1;
  v4 = (idPresentableProjectile *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_uniqueTrackedProjectile);
  if ( v4 == nullptr )
    return 1;
  IsActive = idPresentableProjectile::IsActive(this: v4);
  result = 0;
  if ( !IsActive )
    return 1;
  return result;
}


// ========================================================================
// ?Use@idPresentablePlayer@@QAA_NXZ
// EA  : 0x82B868D8
// RVA : 0x00B868D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::Use(idPresentablePlayer *this)
{
  unsigned int spawnId; // r11
  int v4; // r30
  idPresentable *PresentableByIndex; // r30
  double v6; // fp1
  __int64 v7; // r8
  int lastUsedTime; // r27
  unsigned int v9; // r11
  usableState_t usableState; // r9
  idPresentableProp *v11; // r3
  int v12; // r3
  idPresentableAI *v13; // r30
  idClientGameMsg v14; // [sp+60h] [-50h] BYREF
  unsigned int v15; // [sp+68h] [-48h]
  unsigned int v16; // [sp+6Ch] [-44h]
  usableState_t v17; // [sp+70h] [-40h]

  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    if ( this->IsLocallyControlled(this) )
      return idPlayer::Use(this: (idPlayer *)this->entity);
  }
  else
  {
    spawnId = this->focusTracker.focusPresentable.spawnId;
    v4 = spawnId & 0x3FFF;
    if ( spawnId != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    {
      PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v4);
      if ( PresentableByIndex->spawnId == this->focusTracker.focusPresentable.spawnId )
      {
        v6 = ((double (__fastcall *)(idFocusTracker_Player *))this->focusTracker.GetTraceDistance)(a1: &this->focusTracker);
        LODWORD(v7) = 160;
        if ( v6 < (float)v7 )
        {
          lastUsedTime = PresentableByIndex->lastUsedTime;
          if ( lastUsedTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
            && this->focusTracker.usableState != USABLE_NOT_USABLE
            && PresentableByIndex->GetPlayerInterface_2(this: PresentableByIndex) == nullptr )
          {
            v9 = this->spawnId;
            usableState = this->focusTracker.usableState;
            v14.peerMask = -1;
            v14.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_UseFocus::`vftable';
            v16 = 0;
            v15 = v9;
            v16 = PresentableByIndex->spawnId;
            v17 = usableState;
            idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v14);
            PresentableByIndex->lastUsedTime = pm_clientUseThrottleTime.valueInteger
                                             + idGameTimeManager::GetGameMs(
                                                 this: &clientGame->gameTimeManager,
                                                 type: GAMETIME_SCALED);
            return true;
          }
          v11 = PresentableByIndex->GetPropInterface(this: PresentableByIndex);
          if ( v11 != nullptr && v11->isUsable && v11->pickupOnUse && !v11->predictedPickup )
          {
            idPresentableProp::PickupProp(this: v11, activator: this);
            return true;
          }
          v12 = (int)PresentableByIndex->GetAIInterface(this: PresentableByIndex);
          v13 = (idPresentableAI *)v12;
          if ( v12 != 0
            && (*(int (__fastcall **)(int, idPresentablePlayer *, int))(*(_DWORD *)v12 + 276))(
                 a1: v12,
                 a2: this,
                 a3: this->clientPlayerInputFrame) == 2 )
          {
            idPresentableAI::LootBody(this: v13, playerIndex: this->entityNumber, hasLoot: v13->hasLoot);
            return true;
          }
        }
      }
    }
  }
  return false;
}


// ========================================================================
// __unwind$498050
// EA  : 0x82B86B4C
// RVA : 0x00B86B4C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_498050()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 176 + 96));
}


// ========================================================================
// ?AddAttacker@idPresentablePlayer@@QAAXPAVidPresentable@@MPBVidVec3@@PBVidDeclDamage@@@Z
// EA  : 0x82B86B78
// RVA : 0x00B86B78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::AddAttacker(
        idPresentablePlayer *this,
        idPresentablePlayer *attacker,
        double damage,
        const idVec3 *dir,
        const idDeclDamage *damageDef)
{
  int v8; // r30
  idPresentablePlayer::attackerInfo_t *i; // r28
  int v10; // r29
  int v11; // r29
  idPresentable *PresentableByIndex; // r3
  int v13; // r11
  double v14; // fp12
  float *p_spikeDamage; // r10
  double v16; // fp13
  double v17; // fp0
  double v18; // fp12
  char *v19; // r10
  double v20; // fp0
  int v21; // r11
  unsigned int spawnId; // r9
  char *v23; // r10
  double v24; // fp0
  int v25; // r11

  if ( (attacker == nullptr || (attacker->entityTypeFlags & 0x40) == 0) && attacker != this )
  {
    v8 = 0;
    for ( i = this->attackerInfo; ; ++i )
    {
      v10 = i->attacker.spawnId & 0x3FFF;
      if ( i->attacker.spawnId != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: i->attacker.spawnId & 0x3FFF)
        && idClientGame::GetPresentableByIndex(this: clientGame, index: v10)->spawnId == i->attacker.spawnId )
      {
        v11 = i->attacker.spawnId & 0x3FFF;
        if ( i->attacker.spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: i->attacker.spawnId & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v11))->spawnId != i->attacker.spawnId )
        {
          PresentableByIndex = nullptr;
        }
        if ( PresentableByIndex == attacker )
          break;
      }
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)i)
        && attacker != nullptr
        && i->damageDone < damage )
      {
        v19 = (char *)this + 12 * v8;
        *((_DWORD *)v19 + 8753) = attacker->spawnId;
        v20 = (float)(player_damageFeedbackScale.valueFloat * (float)damage);
        v21 = 12 * (v8 + 2918);
        *(float *)((char *)&this->__vftable + v21) = player_damageFeedbackScale.valueFloat * (float)damage;
        v16 = 0.0;
        p_spikeDamage = (float *)(v19 + 35020);
        *p_spikeDamage = player_spikeDamageFeedbackScale.valueFloat * (float)damage;
        if ( v20 >= 0.0 )
        {
          if ( v20 > 100.0 )
            v20 = 100.0;
        }
        else
        {
          v20 = 0.0;
        }
        v18 = *p_spikeDamage;
        *(float *)((char *)&this->__vftable + v21) = v20;
        if ( v18 >= 0.0 )
        {
          if ( v18 > 100.0 )
          {
            *p_spikeDamage = 100.0;
            return;
          }
          goto LABEL_42;
        }
        goto LABEL_43;
      }
      if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)i) )
      {
        spawnId = 0;
        v23 = (char *)this + 12 * v8;
        if ( attacker != nullptr )
          spawnId = attacker->spawnId;
        *((_DWORD *)v23 + 8753) = spawnId;
        v24 = (float)(player_damageFeedbackScale.valueFloat * (float)damage);
        v25 = 12 * (v8 + 2918);
        p_spikeDamage = (float *)(v23 + 35020);
        *(float *)((char *)&this->__vftable + v25) = player_damageFeedbackScale.valueFloat * (float)damage;
        v16 = 0.0;
        *p_spikeDamage = player_spikeDamageFeedbackScale.valueFloat * (float)damage;
        if ( v24 >= 0.0 )
        {
          if ( v24 > 100.0 )
            v24 = 100.0;
        }
        else
        {
          v24 = 0.0;
        }
        v18 = *p_spikeDamage;
        *(float *)((char *)&this->__vftable + v25) = v24;
        if ( v18 >= 0.0 )
        {
          if ( v18 > 100.0 )
          {
            *p_spikeDamage = 100.0;
            return;
          }
          goto LABEL_42;
        }
        goto LABEL_43;
      }
      if ( ++v8 >= 3 )
        return;
    }
    v13 = 12 * (v8 + 2918);
    v14 = (float)((float)(player_damageFeedbackScale.valueFloat * (float)damage)
                + *(float *)((char *)&this->__vftable + v13));
    *(float *)((char *)&this->__vftable + v13) = (float)(player_damageFeedbackScale.valueFloat * (float)damage)
                                               + *(float *)((char *)&this->__vftable + v13);
    p_spikeDamage = &this->attackerInfo[v8].spikeDamage;
    v16 = 0.0;
    v17 = v14;
    *p_spikeDamage = (float)(player_spikeDamageFeedbackScale.valueFloat * (float)damage) + *p_spikeDamage;
    if ( v14 >= 0.0 )
    {
      if ( v14 > 100.0 )
        v17 = 100.0;
    }
    else
    {
      v17 = 0.0;
    }
    v18 = *p_spikeDamage;
    *(float *)((char *)&this->__vftable + v13) = v17;
    if ( v18 >= 0.0 )
    {
      if ( v18 > 100.0 )
      {
        *p_spikeDamage = 100.0;
        return;
      }
LABEL_42:
      v16 = v18;
    }
LABEL_43:
    *p_spikeDamage = v16;
  }
}


// ========================================================================
// ?UpdateDamageDealt@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B86EE8
// RVA : 0x00B86EE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateDamageDealt(idPresentablePlayer *this)
{
  int v2; // r29
  int v3; // r6
  int v4; // r30
  idPresentable *PresentableByIndex; // r4
  int v6; // r10

  if ( this->lastDamageDealtBufferIndex < this->damageDealtBufferIndex )
  {
    do
    {
      v2 = 4 * (this->lastDamageDealtBufferIndex % 4 + 3898);
      v3 = *(int *)((char *)&this->__vftable + v2);
      v4 = v3 & 0x3FFF;
      if ( v3 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v3 & 0x3FFF)
        || (idPresentablePlayer_vtbl *)(PresentableByIndex = idClientGame::GetPresentableByIndex(
                                                               this: clientGame,
                                                               index: v4))->spawnId != *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v2) )
      {
        PresentableByIndex = nullptr;
      }
      idPresentablePlayer::DamageDealtFeedback(this, victim: PresentableByIndex, predicted: false);
      v6 = this->lastDamageDealtBufferIndex + 1;
      this->lastDamageDealtBufferIndex = v6;
    }
    while ( v6 < this->damageDealtBufferIndex );
  }
}


// ========================================================================
// ?UpdateDamageFeedback@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B86FA8
// RVA : 0x00B86FA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateDamageFeedback(idPresentablePlayer *this)
{
  idEntity *Control; // r3
  idPresentable *v3; // r3
  idPresentable *v4; // r3
  int v5; // r27
  int *p_damageFeedbackBufferPos; // r30
  int v7; // r11
  int v8; // r29
  idPresentable *v9; // r3
  int v10; // r11
  int v11; // r29
  idPresentable *v12; // r3
  int v13; // r11
  int v14; // r29
  idPresentable *PresentableByIndex; // r11
  float y; // r9
  float z; // r8
  double v18; // fp13
  double v19; // fp1
  unsigned __int8 v20; // r11
  int v21; // r30
  bool IsPlayingSound; // r3
  const idDeclPlayerProps *playerProps; // r11
  idMat3 v24; // [sp+60h] [-1A0h] BYREF
  idAngles v25[4]; // [sp+90h] [-170h] BYREF
  idDeclPlayerProps::playerSounds_t sounds; // [sp+C0h] [-140h] BYREF

  if ( this->entity != nullptr
    && common->IsServer(this: common)
    && idPlayer::GetControl(this: (idPlayer *)this->entity) != nullptr
    && (Control = idPlayer::GetControl(this: (idPlayer *)this->entity),
        (unsigned __int8)idClass::IsType(this: Control, superclass: &idCameraView::Type) != 0)
    || idPresentablePlayer::GetControl(this) != nullptr
    && ((v3 = idPresentablePlayer::GetControl(this), v3->GetAIInterface(this: v3) != nullptr)
     || (v4 = idPresentablePlayer::GetControl(this), v4->GetVehicleInterface(this: v4) != nullptr)) )
  {
    idView::ClearDamageEffects(this: &this->view);
  }
  else
  {
    v5 = 0;
    p_damageFeedbackBufferPos = &this->damageFeedbackBufferPos;
    do
    {
      v7 = p_damageFeedbackBufferPos[2];
      v8 = v7 & 0x3FFF;
      if ( v7 != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: v7 & 0x3FFF)
        && (v9 = idClientGame::GetPresentableByIndex(this: clientGame, index: v8),
            v10 = p_damageFeedbackBufferPos[2],
            v9->spawnId == v10)
        && (v11 = p_damageFeedbackBufferPos[2] & 0x3FFF, v10 != 0)
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: p_damageFeedbackBufferPos[2] & 0x3FFF)
        && (v12 = idClientGame::GetPresentableByIndex(this: clientGame, index: v11),
            v13 = p_damageFeedbackBufferPos[2],
            v12->spawnId == v13) )
      {
        v14 = p_damageFeedbackBufferPos[2] & 0x3FFF;
        if ( v13 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_damageFeedbackBufferPos[2] & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v14))->spawnId != p_damageFeedbackBufferPos[2] )
        {
          PresentableByIndex = nullptr;
        }
        y = PresentableByIndex->origin.y;
        z = PresentableByIndex->origin.z;
        v24.mat[1].y = PresentableByIndex->origin.x;
        v24.mat[1].z = y;
        v24.mat[2].x = z;
        v24.mat[0].y = *((float *)&idPresentablePlayer::GetViewAngles(
                                     this: (idPresentablePlayer *)&v24.mat[2].z,
                                     result: (const idAngles *)this,
                                     includeWeaponKick: true)->__vftable
                       + 1);
        v24.mat[0].x = 0.0;
        v24.mat[0].z = 0.0;
        idAngles::ToMat3(this: v25, result: &v24);
        this->GetTotalMaxHealth(this);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->view);
      }
      else
      {
        this->GetTotalMaxHealth(this);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->view);
      }
      v18 = *((float *)p_damageFeedbackBufferPos + 3);
      ++v5;
      *((float *)p_damageFeedbackBufferPos + 4) = -(float)((float)(this->playerProps->damageFeedback.spikeIndicatorDecay
                                                                 * *((float *)p_damageFeedbackBufferPos + 4))
                                                         - *((float *)p_damageFeedbackBufferPos + 4));
      p_damageFeedbackBufferPos += 3;
      *(float *)p_damageFeedbackBufferPos = -(float)((float)(this->playerProps->damageFeedback.centerIndicatorDecay
                                                           * (float)v18)
                                                   - (float)v18);
    }
    while ( v5 < 3 );
    this->GetTotalMaxHealth(this);
    this->GetTotalMaxHealth(this);
    this->GetTotalCurHealth(this);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->view);
    v19 = ((double (__fastcall *)(idPresentablePlayer *))this->GetTotalCurHealth)(a1: this);
    if ( v19 <= 0.0 || (v20 = 1, v19 >= this->playerProps->soundParms.lowHealthThreshold) )
      v20 = 0;
    v21 = v20;
    IsPlayingSound = idPresentable::IsPlayingSound(this, channel: SND_CHANNEL_LOW_HEALTH);
    if ( v21 == 0 || IsPlayingSound )
    {
      if ( v21 == 0 && IsPlayingSound )
        idPresentable::StopSound(this, channel: SND_CHANNEL_LOW_HEALTH, peerMask: 0);
    }
    else
    {
      playerProps = this->playerProps;
      if ( playerProps != nullptr )
        sounds = playerProps->sounds;
      else
        idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
      idPresentable::StartSoundShader(
        this,
        channel: SND_CHANNEL_LOW_HEALTH,
        shader: sounds.sndAlmostDead,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    }
  }
}


// ========================================================================
// ?SetDefaults@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B87498
// RVA : 0x00B87498
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetDefaults(idPresentablePlayer *this)
{
  idStaticList<idPresentablePlayer::screenParticleState_t,5> *p_screenPrtState; // r30
  int size; // r11
  idPresentablePlayer::coopCalloutItem_t v4; // r11
  char v5; // r9
  char v6; // r4
  double valueFloat; // fp0
  double v8; // fp13
  int *p_serializeDamageFeedbackCount; // r10
  int i; // ctr
  idPlayerViewCallbacks *v11; // r3
  idPlayerViewCallbacks *v12; // r11
  unsigned __int64 v13; // r9
  idClipQuery *p_deferredHeadPoint; // r11
  int v15; // ctr
  char v16; // r9
  char v17; // r10
  char *v18; // [sp+50h] [-D0h]
  char *v19; // [sp+54h] [-CCh]

  p_screenPrtState = &this->screenPrtState;
  if ( this->screenPrtState.size >= 5
    || (unsigned __int8)idList<idPresentablePlayer::screenParticleState_t,5>::Resize(
                          this: &this->screenPrtState,
                          newsize: 5) != 0 )
  {
    size = p_screenPrtState->size;
    if ( size > 5 )
      size = 5;
    p_screenPrtState->num = size;
  }
  if ( idPresentablePlayer::HANDS_ANIMWEB_NAME != nullptr )
    idDeclInfo::FindWithInheritance(
      this: &idDeclAnimWeb::resourceList,
      name: idPresentablePlayer::HANDS_ANIMWEB_NAME,
      makeDefault: true);
  memset(Dst: this->serializedHudInfoBuffer, Val: 0, Size: sizeof(this->serializedHudInfoBuffer));
  v4.scoreIndex = 0;
  this->calloutHistory[0] = v4;
  this->calloutHistory[1] = v4;
  this->calloutHistory[2] = v4;
  this->calloutHistory[3] = v4;
  v19 = (char *)this + 47034;
  v18 = (char *)this + 47033;
  this->serializedViewOrigin = vec3_origin;
  this->serializedviewAxis = mat3_identity;
  v5 = *((_BYTE *)this + 47034);
  v6 = *((_BYTE *)this + 47032) & 0xC;
  LOBYTE(v4.callout) = *((_BYTE *)this + 47033);
  this->standDecay.linear = 0.90000004;
  this->standDecay.time = 250;
  this->standDecay.lambda = 0.5;
  this->disableLandingResultsFrames = 0;
  this->crouchDecay.time = 230;
  *((_BYTE *)this + 47033) = (int)v4.callout & 0x67;
  this->crouchDecay.lambda = 0.2;
  this->crouchDecay.linear = 0.30000001;
  *((_BYTE *)this + 47032) = v6;
  this->calloutHistoryIndex = 0;
  this->coopScoringIndex = 0;
  this->lastCalloutHistoryIndex = 0;
  this->lastCoopScoringIndex = 0;
  this->lastDamageDealtBufferIndex = 0;
  this->damageDealtBufferIndex = 0;
  *((_BYTE *)this + 47034) = v5 & 0xCF;
  valueFloat = pm_sprintMaxTime.valueFloat;
  this->staminaStopTime = 0.0;
  this->staminaCharge = valueFloat;
  this->staminaPercent = 1.0;
  this->previousStaminaCharge = 0;
  this->staminaStartTime = 0.0;
  this->deferredOriginOffsetZ = 0.0;
  this->breath_sprintScale = 1.0;
  this->isSprinting = false;
  this->wasSprinting = false;
  this->requireSprintButtonrelease = false;
  this->inInteractionView = false;
  *((_BYTE *)this + 47032) = v6 & 0xFB;
  this->pendingAmmo = nullptr;
  this->isTurretControl = false;
  this->respawnCount = 0;
  this->useIntroBringUp = false;
  this->pendingQuickWeapon = -1;
  this->nextWeaponChangeTime = 0;
  this->pain_debounce_time = 0;
  this->nextAmmoChangeTime = 0;
  this->weaponButtonPressTime = 0;
  this->ammoButtonPressTime = 0;
  this->inhibitFireControlStartTime = 0;
  this->nextBeatTime = 0;
  this->playDamagedBreathing = false;
  this->heartBeatLub = true;
  this->firstPersonViewOrigin = vec3_origin;
  this->firstPersonViewAxis = mat3_identity;
  this->originError = vec3_origin;
  this->lastFov = -1.0;
  this->baseWeaponSpread.startTime = 0.0;
  this->baseWeaponSpread.duration = 0.0;
  this->baseWeaponSpread.startValue = 0.0;
  this->baseWeaponSpread.endValue = 0.0;
  this->baseWeaponSpread.currentTime = -1.0;
  this->baseWeaponSpread.currentValue = 0.0;
  this->kickWeaponSpread.startTime = 0.0;
  this->kickWeaponSpread.currentTime = -1.0;
  this->kickWeaponSpread.currentValue = 0.0;
  this->kickWeaponSpread.duration = 0.0;
  this->kickWeaponSpread.startValue = 0.0;
  this->kickWeaponSpread.endValue = 0.0;
  v8 = g_fov.valueFloat;
  this->zoomFov.startTime = 0.0;
  this->zoomFov.duration = 0.0;
  this->zoomFov.startValue = v8;
  this->zoomFov.endValue = v8;
  this->zoomFov.currentTime = -1.0;
  this->zoomFov.currentValue = v8;
  this->wantZoom = false;
  this->perfectOriginRotation = quat_identity;
  this->perfectOriginDuration = 0;
  this->perfectOriginStartTime = 0;
  this->inhibitFlags = UCMD_INHIBIT_NONE;
  this->playerProps = nullptr;
  idPresentablePlayer::ClearWeaponKick(this);
  this->wrongWeapons = 0;
  this->wrongAmmo = 0;
  memset(Dst: this->moveBuffer, Val: 0, Size: sizeof(this->moveBuffer));
  memset(Dst: this->damageFeedback, Val: 0, Size: sizeof(this->damageFeedback));
  this->damageFeedbackBufferPos = 0;
  this->serializeDamageFeedbackCount = 0;
  p_serializeDamageFeedbackCount = &this->serializeDamageFeedbackCount;
  for ( i = 9; i != 0; --i )
    *++p_serializeDamageFeedbackCount = 0;
  v11 = (idPlayerViewCallbacks *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 8u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
  {
    v11->self = nullptr;
    v12 = v11;
    v11->__vftable = (idPlayerViewCallbacks_vtbl *)&idPlayerViewCallbacks::`vftable';
  }
  else
  {
    v12 = nullptr;
  }
  this->viewCallbacks = v12;
  v12->self = this;
  this->stepUpSpringCrouchState = false;
  this->stepUpViewSpring.k = 1.0;
  this->stepUpViewSpring.restLength = 0.0;
  this->stepUpViewSpring.hasPMax = false;
  this->stepUpViewSpring.p0.x = 0.0;
  this->stepUpViewSpring.hasPMin = false;
  this->stepUpViewSpring.p1.x = 0.0;
  this->stepUpViewSpring.vel.x = 0.0;
  this->stepUpViewSpring.maxSpeed = 0.0;
  this->stepUpViewSpring.pMin.x = 0.0;
  this->stepUpViewSpring.pMax.x = 0.0;
  this->stepUpViewSpring.m = 1.0;
  this->stepUpViewSpring.c = 2.0;
  idSpring<idVec1>::SetConstants(this: &this->stepUpViewSpring, _k: p_stepUpViewSpringK.valueFloat, _c: -1.0);
  this->stepUpHandsSpring.vel.x = 0.0;
  this->stepUpHandsSpring.hasPMin = false;
  this->stepUpHandsSpring.p1.x = 0.0;
  this->stepUpHandsSpring.maxSpeed = 0.0;
  this->stepUpHandsSpring.hasPMax = false;
  this->stepUpHandsSpring.pMin.x = 0.0;
  this->stepUpHandsSpring.pMax.x = 0.0;
  this->stepUpHandsSpring.restLength = 0.0;
  this->stepUpHandsSpring.k = 1.0;
  this->stepUpHandsSpring.m = 1.0;
  this->stepUpHandsSpring.c = 2.0;
  this->stepUpHandsSpring.p0.x = 0.0;
  idSpring<idVec1>::SetConstants(this: &this->stepUpHandsSpring, _k: p_stepUpHandsSpringK.valueFloat, _c: -1.0);
  this->leanRoll = 0.0;
  this->cameraShake.scale = 0.0;
  this->cameraShake.startTime = 0.0;
  this->cameraShake.decay = 0.0;
  this->cameraShake.active = false;
  this->localMaxViewAngles.pitch = 89.0;
  this->localMaxViewAngles.roll = 0.0;
  this->localMaxViewAngles.yaw = 180.0;
  this->localMinViewAngles.pitch = -89.0;
  this->localMinViewAngles.yaw = -180.0;
  this->localMinViewAngles.roll = 0.0;
  this->influence.angle = 20.0;
  this->activeInventory = nullptr;
  this->clientPlayerInputFrame = 0;
  this->lastRecordedMoveBufferIndex = 0;
  HIDWORD(v13) = *v18 & 0xDB | 0x20;
  this->firstPredictionSerialize = true;
  this->outlineModel = nullptr;
  LODWORD(v13) = 0;
  this->physicsInitialized = false;
  p_deferredHeadPoint = &this->aimAssist.deferredHeadPoint;
  this->throwCount = 0;
  v15 = 10;
  this->serverOverridePositionTime = 1;
  *v18 = BYTE3(v13);
  this->subtitleStartTime = -1;
  do
  {
    ++p_deferredHeadPoint;
    p_deferredHeadPoint->index = v13;
    --v15;
  }
  while ( v15 != 0 );
  HIDWORD(p_deferredHeadPoint[1].index) = 0;
  idPresentablePlayer::SetPlayerGuiFile(this, g: GUI_SUBTITLE, filename: "vo", purgableImage: false);
  idPresentablePlayer::SetPlayerGuiFile(this, g: GUI_INVENTORY, filename: "tunginventory", purgableImage: true);
  idPresentablePlayer::SetPlayerGuiFile(this, g: GUI_SIDEMISSION, filename: "tungmission", purgableImage: true);
  this->renderLegendTitle = false;
  this->uniqueTrackedProjectileClientGameFrameWhenFired = -1;
  this->challengeLeavingSoon = false;
  this->challengeRestartingSoon = false;
  this->challengeLocalRestart = false;
  this->ignoreTutorialPause = false;
  this->challengeRemoteRestart = false;
  this->challengeEndTime = 0;
  this->wasPaused = false;
  this->ignoreTowTruckPause = false;
  this->lastDecalValue = 0.0;
  this->currentTutorialGuiDecl = nullptr;
  this->roverBombSoundCounter = 0;
  this->localRoverBombSoundCounter = 0;
  this->disableSubtitles = false;
  memset(Dst: &this->serializedState, Val: 0, Size: sizeof(this->serializedState));
  this->quickUseFailedTime = 0;
  this->sentOfficialSnap = false;
  this->quickSelectUsed = false;
  this->isGeneralGuiCardGame = false;
  v16 = *v18;
  this->weaponFiremodeAnimStateLeft = WEAPONSTATE_NORMAL;
  v17 = *v19;
  this->lastWeaponSlotLeft = -1;
  this->weaponFiremodeAnimStateRight = WEAPONSTATE_NORMAL;
  this->lastBurstModeLeft = BURSTMODE_DEFAULT;
  this->lastWeaponSlotRight = -1;
  this->lastBurstModeRight = BURSTMODE_DEFAULT;
  this->lastFunctionalityLens = FUNCTIONALITY_LENS_ZOOM;
  *v18 = v16 & 0xFC;
  *v19 = v17 & 0x3F;
  this->addViewAngles.roll = 0.0;
  this->addViewAngles.yaw = 0.0;
  this->addViewAngles.pitch = 0.0;
  this->addViweOffset.z = 0.0;
  this->addViweOffset.y = 0.0;
  this->addViweOffset.x = 0.0;
  this->addViewAnglDoneAtTime = 0;
  this->addViewAnglBlendState = ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT;
  this->missionPin.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?CalculateView@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B87DD0
// RVA : 0x00B87DD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::CalculateView(idPresentablePlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  char v4; // r30
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idMat3 *p_firstPersonViewAxis; // r30
  idVec3 *p_firstPersonViewOrigin; // r28
  const idIndex<short,enum invalidJointIndex_t> *v8; // r20
  idTreeAnimator *v9; // r3
  double v10; // fp31
  const idVec3 *v11; // r3
  double v12; // fp30
  double v13; // fp29
  double v14; // fp31
  float *v15; // r3
  double v16; // fp8
  double v17; // fp6
  const idMat3 *v18; // r30
  idMat3 *v19; // r3
  idMat3 *v20; // r3
  idMat3 *v21; // r3
  double y; // fp3
  double v23; // fp31
  double v24; // fp13
  double v25; // fp8
  double z; // fp7
  double v27; // fp3
  double v28; // fp2
  idRenderWorld *v29; // r20
  idPresentable *Presentable; // r3
  idRenderWorld_vtbl *v31; // r10
  idRenderWorld *v32; // r18
  double v33; // fp30
  double v34; // fp29
  double v35; // fp28
  idPresentable *v36; // r3
  double v37; // fp9
  double v38; // fp7
  int v39; // r3
  __int64 v40; // r10
  __int64 v41; // r6
  __int64 v42; // r8
  va *v43; // r3
  idRenderWorld *v44; // r3
  idRenderWorld *v45; // r20
  __int64 v46; // r6
  __int64 v47; // r10
  __int64 v48; // r8
  va *v49; // r3
  idIndex<short,enum invalidJointIndex_t> *v50; // r3
  const idIndex<short,enum invalidJointIndex_t> *v51; // r19
  idTreeAnimator *v52; // r3
  idRenderWorld *v53; // r3
  idIndex<short,enum invalidJointIndex_t> *v54; // r3
  const idIndex<short,enum invalidJointIndex_t> *v55; // r20
  idTreeAnimator *v56; // r3
  idRenderWorld *v57; // r3
  idIndex<short,enum invalidJointIndex_t> *v58; // r3
  const idIndex<short,enum invalidJointIndex_t> *v59; // r24
  idTreeAnimator *v60; // r3
  idRenderWorld *v61; // r3
  double v62; // fp31
  const idVec3 *v63; // r3
  double v64; // fp30
  double v65; // fp29
  double v66; // fp31
  float *SmoothOrigin; // r3
  double v68; // fp8
  double v69; // fp5
  const idMat3 *v70; // r30
  idMat3 *ViewAngles; // r3
  idMat3 *v72; // r3
  idMat3 *v73; // r3
  idMat3 *v74; // r3
  idVec3 *v75; // r29
  idVec3 *v76; // r26
  double v77; // fp11
  double v78; // fp9
  const idMat3 *v79; // r29
  idMat3 *v80; // r3
  idMat3 *v81; // r3
  idMat3 *v82; // r3
  double x; // fp11
  double v84; // fp9
  double valueFloat; // fp31
  const idVec3 *v86; // r3
  double v87; // fp6
  double v88; // fp12
  double v89; // fp7
  double v90; // fp13
  double v91; // fp5
  double v92; // fp8
  double v93; // fp6
  double v94; // fp10
  double v95; // fp7
  double v96; // fp6
  idMat3 *v97; // r3
  double v98; // fp4
  double v99; // fp2
  idTreeAnimator_vtbl *entity; // r4
  bool (__fastcall *Load)(struct idTreeAnimator *, idFile *); // r11
  idSpringCamera *v102; // r3
  int v103; // [sp+8h] [-1268h]
  int v104; // [sp+8h] [-1268h]
  int v105; // [sp+Ch] [-1264h]
  int v106; // [sp+Ch] [-1264h]
  int v107; // [sp+10h] [-1260h]
  int v108; // [sp+10h] [-1260h]
  int v109; // [sp+14h] [-125Ch]
  int v110; // [sp+14h] [-125Ch]
  int v111; // [sp+18h] [-1258h]
  int v112; // [sp+18h] [-1258h]
  int v113; // [sp+1Ch] [-1254h]
  int v114; // [sp+1Ch] [-1254h]
  idTreeAnimator v115; // [sp+60h] [-1210h] BYREF

  idPresentablePlayer::DecayOriginError(this);
  RD_EventBegin(name: "idPresentablePlayer::CalculateView");
  LODWORD(v2) = "idPresentablePlayer::CalculateView";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v115.deferredAxis.mat[0].y, pl: &pLog, gMask: v2, label: v3);
  if ( this->entity == nullptr
    || !common->IsServer(this: common)
    || (v4 = 1, !idPlayer::IsBotControllingAFKPlayer(this: (idPlayer *)this->entity)) )
  {
    v4 = 0;
  }
  if ( pm_thirdPerson.valueInteger != 0 || this->IsDead(this) || v4 != 0 )
  {
    idPresentablePlayer::OffsetThirdPersonView(
      this,
      angle: pm_thirdPersonAngle.valueFloat,
      range: pm_thirdPersonRange.valueFloat,
      height: pm_thirdPersonHeight.valueFloat,
      focusJoint: (const char *)&pm_thirdPersonHeight,
      clip: (bool)&idEventDef::eventDefList[3154],
      a7: (int)&idEventDef::eventDefList[3154],
      a8: pm_thirdPersonFocusJoint.valueString.data,
      a9: pm_thirdPersonClip.valueInteger != 0);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v115.deferredAxis.mat[0].y);
  }
  else
  {
    if ( (*((_BYTE *)this + 47032) & 0x20) != 0 || hands_updatePos.valueInteger == 0 )
    {
      v62 = -*(float *)&idPresentablePlayer::GetEyeOffset(
                          this: (idPresentablePlayer *)&v115.deferredOrigin,
                          result: this)->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId;
      v63 = this->physicsObj.GetGravityNormal(this: &this->physicsObj);
      v64 = (float)(v63->z * (float)v62);
      v65 = (float)(v63->y * (float)v62);
      v66 = (float)(v63->x * (float)v62);
      SmoothOrigin = (float *)idPresentablePlayer::GetSmoothOrigin(
                                this: (idPresentablePlayer *)&v115.g.customMaterial,
                                result: (idVec3 *)this);
      p_firstPersonViewOrigin = &this->firstPersonViewOrigin;
      v68 = (float)(*SmoothOrigin + (float)v66);
      v69 = (float)(SmoothOrigin[2] + (float)v64);
      this->firstPersonViewOrigin.y = SmoothOrigin[1] + (float)v65;
      this->firstPersonViewOrigin.z = v69;
      this->firstPersonViewOrigin.x = v68;
      this->firstPersonViewOrigin.x = v68;
      this->firstPersonViewOrigin.y = this->firstPersonViewOrigin.y;
      this->firstPersonViewOrigin.z = this->firstPersonViewOrigin.z;
      v70 = this->physicsObj.GetGravityAxis(this: &this->physicsObj);
      ViewAngles = (idMat3 *)idPresentablePlayer::GetViewAngles(
                               this: (idPresentablePlayer *)&v115.deferredOrigin,
                               result: (const idAngles *)this,
                               includeWeaponKick: true);
      v72 = idAngles::ToMat3(this: (idAngles *)&v115.g.highlightColor, result: ViewAngles);
      v73 = idMat3::operator*(this: (idMat3 *)&v115.gameParmBlock, result: v72, a: v70);
      p_firstPersonViewAxis = &this->firstPersonViewAxis;
      this->firstPersonViewAxis.mat[0].x = v73->mat[0].x;
      v115.__vftable = (idTreeAnimator_vtbl *)&this->firstPersonViewAxis.mat[2];
      this->firstPersonViewAxis.mat[0].y = v73->mat[0].y;
      this->firstPersonViewAxis.mat[0].z = v73->mat[0].z;
      this->firstPersonViewAxis.mat[1] = v73->mat[1];
      this->firstPersonViewAxis.mat[2] = v73->mat[2];
    }
    else
    {
      TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
      idTreeAnimator::GetJointIndex(
        this: (idTreeAnimator *)(&v115.__vftable + 1),
        result: TreeAnimatorFromPresentable,
        jointName: "player_camera_game");
      if ( *((__int16 *)&v115.__vftable + 2) < 0 )
      {
        v10 = -*(float *)&idPresentablePlayer::GetEyeOffset(
                            this: (idPresentablePlayer *)&v115.g.customMaterial,
                            result: this)->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId;
        v11 = this->physicsObj.GetGravityNormal(this: &this->physicsObj);
        v12 = (float)(v11->z * (float)v10);
        v13 = (float)(v11->y * (float)v10);
        v14 = (float)(v11->x * (float)v10);
        v15 = (float *)idPresentablePlayer::GetSmoothOrigin(
                         this: (idPresentablePlayer *)&v115.deferredOrigin,
                         result: (idVec3 *)this);
        p_firstPersonViewOrigin = &this->firstPersonViewOrigin;
        v16 = (float)((float)v14 + *v15);
        v17 = (float)(v15[2] + (float)v12);
        this->firstPersonViewOrigin.y = v15[1] + (float)v13;
        this->firstPersonViewOrigin.z = v17;
        this->firstPersonViewOrigin.x = v16;
        v18 = this->physicsObj.GetGravityAxis(this: &this->physicsObj);
        v19 = (idMat3 *)idPresentablePlayer::GetViewAngles(
                          this: (idPresentablePlayer *)&v115.deferredOrigin,
                          result: (const idAngles *)this,
                          includeWeaponKick: true);
        v20 = idAngles::ToMat3(this: (idAngles *)&v115.gameParmBlock, result: v19);
        v21 = idMat3::operator*(this: (idMat3 *)&v115.g.highlightColor, result: v20, a: v18);
        p_firstPersonViewAxis = &this->firstPersonViewAxis;
        this->firstPersonViewAxis.mat[0].x = v21->mat[0].x;
        v115.__vftable = (idTreeAnimator_vtbl *)&v21->mat[2];
        y = v21->mat[0].y;
        v115.__vftable = (idTreeAnimator_vtbl *)&this->firstPersonViewAxis.mat[2];
        this->firstPersonViewAxis.mat[0].y = y;
        this->firstPersonViewAxis.mat[0].z = v21->mat[0].z;
        this->firstPersonViewAxis.mat[1] = v21->mat[1];
        this->firstPersonViewAxis.mat[2] = v21->mat[2];
      }
      else
      {
        p_firstPersonViewAxis = &this->firstPersonViewAxis;
        p_firstPersonViewOrigin = &this->firstPersonViewOrigin;
        v8 = (const idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&v115.__vftable + 2);
        v9 = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v9,
          pose: DRIVER_MODEL,
          jointIndex: v8,
          origin: &this->firstPersonViewOrigin,
          axis: &this->firstPersonViewAxis);
      }
      v23 = __fabs(idWeaponKick::GetOffset(this: &this->weaponKick[1]));
      v24 = __fabs(idWeaponKick::GetOffset(this: this->weaponKick));
      v25 = p_firstPersonViewOrigin->y;
      z = p_firstPersonViewOrigin->z;
      v27 = (float)((float)((float)((float)v24 + (float)v23) * (float)-2.0) * p_firstPersonViewAxis->mat[0].z);
      v28 = (float)(p_firstPersonViewAxis->mat[0].y * (float)((float)((float)v24 + (float)v23) * (float)-2.0));
      p_firstPersonViewOrigin->x = p_firstPersonViewOrigin->x
                                 + (float)(p_firstPersonViewAxis->mat[0].x
                                         * (float)((float)((float)v24 + (float)v23) * (float)-2.0));
      p_firstPersonViewOrigin->z = (float)z + (float)v27;
      p_firstPersonViewOrigin->y = (float)v25 + (float)v28;
      if ( p_useStepUpSprings.valueInteger != 0 && pm_doom4BobCycle.valueInteger != 0 )
        this->firstPersonViewOrigin.z = this->stepUpViewSpring.p1.x + this->firstPersonViewOrigin.z;
      if ( pm_debugView.valueInteger != 0 )
      {
        v29 = common->RW(this: common);
        Presentable = idHands::GetPresentable(this: &this->hands);
        *(idVec3 *)&v115.g.axis.mat[1].y = Presentable->origin;
        v115.g.axis.mat[2].y = 1.0;
        v31 = v29->__vftable;
        v115.__vftable = (idTreeAnimator_vtbl *)&Presentable->origin;
        v31->DebugSphere(
          this: v29,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: (const idSphere *)&v115.g.axis.mat[1].y,
          a4: 4,
          a5: 2000,
          a6: false);
        v32 = common->RW(this: common);
        v33 = (float)(vec3_up.x * (float)10.0);
        v34 = (float)(vec3_up.z * (float)10.0);
        v35 = (float)(vec3_up.y * (float)10.0);
        v36 = idHands::GetPresentable(this: &this->hands);
        v37 = (float)(v36->origin.z + (float)v34);
        v38 = (float)(v36->origin.y + (float)v35);
        v115.referenceBounds.b[0].y = (float)v33 + v36->origin.x;
        v115.referenceBounds.b[1].x = v37;
        v115.referenceBounds.b[0].z = v38;
        v115.__vftable = (idTreeAnimator_vtbl *)&v36->origin;
        v39 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        HIDWORD(v40) = &unk_821F0000;
        HIDWORD(v41) = v39;
        v43 = va::va(
                this: (va *)&v115.gameParmBlock.staticOps[1],
                fmt: "%i",
                a3: v41,
                a4: v42,
                a5: v40,
                a6: v103,
                a7: v105,
                a8: v107,
                a9: v109,
                a10: v111,
                a11: v113);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, char *, idColor *, int, int, _DWORD, double))v32->DebugText)(
          a1: v32,
          a2: v43,
          a3: &v115.referenceBounds.b[0].y,
          a4: &aAvSsobjectVCom[20],
          a5: &idColor::colorOrange,
          a6: 1,
          a7: 2000,
          a8: 0,
          a9: 0.0099999998);
        v44 = common->RW(this: common);
        v44->DebugAxis_2(
          this: v44,
          a2: (const idVec3 *)(&v115.__vftable + 2),
          a3: (const idMat3 *)&v115.g.suppressSurfaceInViewID,
          a4: 2000,
          a5: false);
        v45 = common->RW(this: common);
        *(float *)&v115.useDeferredPosition = *(float *)&v115.name.str + (float)(vec3_up.z * (float)10.0);
        v115.deferredAxis.mat[2].y = (float)(vec3_up.x * (float)10.0) + *((float *)&v115.__vftable + 2);
        v115.deferredAxis.mat[2].z = *((float *)&v115.__vftable + 3) + (float)(vec3_up.y * (float)10.0);
        HIDWORD(v46) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v49 = va::va(
                this: (va *)&v115.gameParmBlock.staticOps[1],
                fmt: "%i",
                a3: v46,
                a4: v48,
                a5: v47,
                a6: v104,
                a7: v106,
                a8: v108,
                a9: v110,
                a10: v112,
                a11: v114);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v45->DebugText)(
          a1: v45,
          a2: v49,
          a3: &v115.deferredAxis.mat[2].y,
          a4: v45->DebugText,
          a5: &idColor::colorOrange,
          a6: 1,
          a7: 2000,
          a8: 0,
          a9: 0.0099999998);
        v50 = (idIndex<short,enum invalidJointIndex_t> *)idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        *((_WORD *)&v115.__vftable + 2) = HIWORD(idTreeAnimator::GetJointIndex(
                                                   this: &v115,
                                                   result: v50,
                                                   jointName: "game_view_ctrl")->__vftable);
        v51 = (const idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&v115.__vftable + 2);
        v52 = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v52,
          pose: DRIVER_MODEL,
          jointIndex: v51,
          origin: (idVec3 *)(&v115.__vftable + 2),
          axis: (idMat3 *)&v115.g.suppressSurfaceInViewID);
        v53 = common->RW(this: common);
        v115.g.axis.mat[0].z = *(float *)&v115.name.str;
        v115.g.axis.mat[0].x = *((float *)&v115.__vftable + 2);
        v115.g.axis.mat[1].x = 0.1;
        v115.g.axis.mat[0].y = *((float *)&v115.__vftable + 3);
        v53->DebugSphere(
          this: v53,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: (const idSphere *)&v115.g.axis,
          a4: 4,
          a5: 2000,
          a6: false);
        v54 = (idIndex<short,enum invalidJointIndex_t> *)idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        *((_WORD *)&v115.__vftable + 2) = HIWORD(idTreeAnimator::GetJointIndex(
                                                   this: &v115,
                                                   result: v54,
                                                   jointName: "player_camera_game")->__vftable);
        v55 = (const idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&v115.__vftable + 2);
        v56 = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v56,
          pose: DRIVER_MODEL,
          jointIndex: v55,
          origin: (idVec3 *)(&v115.__vftable + 2),
          axis: (idMat3 *)&v115.g.suppressSurfaceInViewID);
        v57 = common->RW(this: common);
        v115.g.axis.mat[2].z = *((float *)&v115.__vftable + 2);
        v115.g.scale.x = *((float *)&v115.__vftable + 3);
        v115.g.scale.y = *(float *)&v115.name.str;
        v115.g.scale.z = 0.1;
        v57->DebugSphere(
          this: v57,
          a2: (const idVec4 *)&idColor::colorPurple,
          a3: (const idSphere *)&v115.g.axis.mat[2].z,
          a4: 4,
          a5: 2000,
          a6: false);
        v58 = (idIndex<short,enum invalidJointIndex_t> *)idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        *((_WORD *)&v115.__vftable + 2) = HIWORD(idTreeAnimator::GetJointIndex(
                                                   this: &v115,
                                                   result: v58,
                                                   jointName: "player_pivot")->__vftable);
        v59 = (const idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&v115.__vftable + 2);
        v60 = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v60,
          pose: DRIVER_MODEL,
          jointIndex: v59,
          origin: (idVec3 *)(&v115.__vftable + 2),
          axis: (idMat3 *)&v115.g.suppressSurfaceInViewID);
        v61 = common->RW(this: common);
        v115.referenceBounds.b[1].z = *((float *)&v115.__vftable + 2);
        v115.g.origin.z = 0.1;
        v115.g.origin.x = *((float *)&v115.__vftable + 3);
        v115.g.origin.y = *(float *)&v115.name.str;
        v61->DebugSphere(
          this: v61,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idSphere *)&v115.referenceBounds.b[1].z,
          a4: 4,
          a5: 2000,
          a6: false);
      }
    }
    if ( common->IsMultiplayer(this: common) )
    {
      this->firstPersonViewOrigin.z = this->deferredOriginOffsetZ + this->firstPersonViewOrigin.z;
      this->deferredOriginOffsetZ = 0.0;
    }
    if ( !this->IsDead(this) || (*((_BYTE *)this + 47032) & 4) != 0 )
    {
      v79 = this->physicsObj.GetGravityAxis(this: &this->physicsObj);
      v80 = (idMat3 *)idPresentablePlayer::GetViewAngles(
                        this: (idPresentablePlayer *)&v115.deferredOrigin,
                        result: (const idAngles *)this,
                        includeWeaponKick: true);
      v81 = idAngles::ToMat3(this: (idAngles *)&v115.g.highlightColor, result: v80);
      v82 = idMat3::operator*(this: (idMat3 *)&v115.gameParmBlock, result: v81, a: v79);
      p_firstPersonViewAxis->mat[0] = v82->mat[0];
      v75 = &p_firstPersonViewAxis->mat[1];
      v76 = &p_firstPersonViewAxis->mat[2];
      x = v82->mat[1].x;
      v115.__vftable = (idTreeAnimator_vtbl *)&p_firstPersonViewAxis->mat[1];
      p_firstPersonViewAxis->mat[1].x = x;
      p_firstPersonViewAxis->mat[1].y = v82->mat[1].y;
      v115.__vftable = (idTreeAnimator_vtbl *)&p_firstPersonViewAxis->mat[2];
      v84 = v82->mat[1].z;
      v115.__vftable = (idTreeAnimator_vtbl *)&v82->mat[2];
      p_firstPersonViewAxis->mat[1].z = v84;
      p_firstPersonViewAxis->mat[2] = v82->mat[2];
      if ( aas_showWallEdges.valueInteger != 3 && ai_showObstacleAvoidance.valueInteger < 3 )
      {
        valueFloat = g_viewNodalZ.valueFloat;
        v86 = this->physicsObj.GetGravityNormal(this: &this->physicsObj);
        v87 = (float)(v86->z * (float)valueFloat);
        v88 = p_firstPersonViewOrigin->z;
        v89 = (float)((float)valueFloat * v86->x);
        v90 = p_firstPersonViewOrigin->x;
        v91 = (float)(p_firstPersonViewOrigin->y + (float)(v86->y * (float)valueFloat));
        p_firstPersonViewOrigin->y = p_firstPersonViewOrigin->y + (float)(v86->y * (float)valueFloat);
        p_firstPersonViewOrigin->z = (float)v88 + (float)v87;
        p_firstPersonViewOrigin->x = (float)v90 + (float)v89;
        v92 = (float)((float)v88 + (float)v87);
        v93 = (float)((float)(g_viewNodalX.valueFloat * p_firstPersonViewAxis->mat[0].z)
                    + (float)(this->firstPersonViewAxis.mat[2].z * g_viewNodalZ.valueFloat));
        v94 = (float)((float)(g_viewNodalX.valueFloat * p_firstPersonViewAxis->mat[0].y)
                    + (float)(this->firstPersonViewAxis.mat[2].y * g_viewNodalZ.valueFloat));
        p_firstPersonViewOrigin->x = (float)((float)v90 + (float)v89)
                                   + (float)((float)(g_viewNodalX.valueFloat * p_firstPersonViewAxis->mat[0].x)
                                           + (float)(g_viewNodalZ.valueFloat * this->firstPersonViewAxis.mat[2].x));
        p_firstPersonViewOrigin->z = (float)v93 + (float)v92;
        p_firstPersonViewOrigin->y = (float)v94 + (float)v91;
      }
    }
    else
    {
      v115.deferredAxis.mat[1].y = *((float *)&idPresentablePlayer::GetViewAngles(
                                                 this: (idPresentablePlayer *)&v115.deferredOrigin,
                                                 result: (const idAngles *)this,
                                                 includeWeaponKick: true)->__vftable
                                   + 1);
      v115.deferredAxis.mat[1].z = 40.0;
      v115.deferredAxis.mat[1].x = -15.0;
      v74 = idAngles::ToMat3(this: (idAngles *)&v115.g.highlightColor, result: (idMat3 *)&v115.deferredAxis.mat[1]);
      p_firstPersonViewAxis->mat[0].x = v74->mat[0].x;
      v75 = &p_firstPersonViewAxis->mat[1];
      p_firstPersonViewAxis->mat[0].y = v74->mat[0].y;
      v76 = &p_firstPersonViewAxis->mat[2];
      v77 = v74->mat[0].z;
      v115.__vftable = (idTreeAnimator_vtbl *)&p_firstPersonViewAxis->mat[1];
      p_firstPersonViewAxis->mat[0].z = v77;
      p_firstPersonViewAxis->mat[1].x = v74->mat[1].x;
      v115.__vftable = (idTreeAnimator_vtbl *)&p_firstPersonViewAxis->mat[2];
      v78 = v74->mat[1].y;
      v115.__vftable = (idTreeAnimator_vtbl *)&v74->mat[2];
      p_firstPersonViewAxis->mat[1].y = v78;
      p_firstPersonViewAxis->mat[1].z = v74->mat[1].z;
      p_firstPersonViewAxis->mat[2] = v74->mat[2];
    }
    if ( this->IsLocallyControlled(this) )
    {
      v115.__vftable = (idTreeAnimator_vtbl *)this->entity;
      if ( v115.__vftable != nullptr )
      {
        if ( idPlayer::PlayerBehavior_Lean_IsLeaning(this: (idPlayer *)v115.__vftable, bAny: true)
          && idPlayer::PlayerBehavior_Lean_UpdateViewOffset(
               this: (idPlayer *)this->entity,
               offsetTrans: (idVec3 *)&v115.nextOnCommitList,
               offsetDir: (idMat3 *)&v115.g.suppressSurfaceInViewID) )
        {
          v95 = (float)(*(float *)&v115.needCommitFrameNum + p_firstPersonViewOrigin->y);
          v96 = (float)(*(float *)&v115.committed + p_firstPersonViewOrigin->z);
          p_firstPersonViewOrigin->x = p_firstPersonViewOrigin->x + *(float *)&v115.nextOnCommitList;
          p_firstPersonViewOrigin->y = v95;
          p_firstPersonViewOrigin->z = v96;
          v97 = idMat3::operator*(
                  this: (idMat3 *)&v115.g.highlightColor,
                  result: (idMat3 *)&v115.g.suppressSurfaceInViewID,
                  a: p_firstPersonViewAxis);
          p_firstPersonViewAxis->mat[0].x = v97->mat[0].x;
          v98 = v97->mat[0].y;
          v115.__vftable = (idTreeAnimator_vtbl *)v75;
          p_firstPersonViewAxis->mat[0].y = v98;
          p_firstPersonViewAxis->mat[0].z = v97->mat[0].z;
          v115.__vftable = (idTreeAnimator_vtbl *)&v97->mat[1];
          v99 = v97->mat[1].x;
          v115.__vftable = (idTreeAnimator_vtbl *)&v97->mat[2];
          v75->x = v99;
          v75->y = v97->mat[1].y;
          v75->z = v97->mat[1].z;
          *v76 = v97->mat[2];
        }
        entity = (idTreeAnimator_vtbl *)this->entity;
        Load = entity[276].Load;
        v115.__vftable = entity;
        if ( Load != nullptr )
        {
          v115.__vftable = entity;
          if ( *((_BYTE *)Load + 1476) == 0 )
          {
            v115.__vftable = entity;
            v102 = (idSpringCamera *)entity[276].Load;
            v115.__vftable = entity;
            idSpringCamera::CalculateView(this: v102, player: (idPlayer *)entity);
          }
        }
      }
    }
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v115.deferredAxis.mat[0].y);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$499064
// EA  : 0x82B88B60
// RVA : 0x00B88B60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_499064()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4720 + 4528));
}


// ========================================================================
// __unwind$499065
// EA  : 0x82B88B88
// RVA : 0x00B88B88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_499065()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4720 + 136));
}


// ========================================================================
// ?SetViewAngles@idPresentablePlayer@@QAAXABVidAngles@@_N@Z
// EA  : 0x82B88BB0
// RVA : 0x00B88BB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetViewAngles(idPresentablePlayer *this, const idAngles *angles, bool force)
{
  __int64 v3; // r10
  int v5; // r7
  __int64 v7; // r6
  char v8; // r4
  __int64 v9; // r10
  int v10; // r7
  __int64 v11; // r6
  idAngles v12[5]; // [sp+50h] [-40h] BYREF

  LODWORD(v3) = LODWORD(angles->pitch);
  *(float *)&v3 = angles->yaw;
  v5 = 47032;
  LODWORD(v7) = LODWORD(angles->roll);
  HIDWORD(v7) = 0;
  v12[0].pitch = angles->pitch;
  v12[0].yaw = *(float *)&v3;
  v8 = *((_BYTE *)this + 47032);
  LODWORD(v12[0].roll) = v7;
  if ( (v8 & 0x20) == 0 )
  {
    idUCmdTracker::ConstrainViewAngles(this: &this->ucmdTracker1, angles: v12);
    idUCmdTracker::ConstrainViewAngles(this: &this->ucmdTracker2, angles: v12);
  }
  idUCmdTracker::SetViewAngles(this: &this->ucmdTracker1, angles: v7, a3: v5, a4: v3);
  idUCmdTracker::SetViewAngles(this: &this->ucmdTracker2, angles: v11, a3: v10, a4: v9);
  if ( force )
    idPresentablePlayer::CalculateView(this);
}


// ========================================================================
// ?UpdateViewAngles@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B88C58
// RVA : 0x00B88C58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentablePlayer::UpdateViewAngles(idPresentablePlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  __int64 v4; // r4 OVERLAPPED
  int v5; // r5
  double v6; // fp13
  double v7; // fp12
  idPresentablePlayer *v8; // r3
  long double v9; // fp2
  double v10; // fp31
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  idPresentablePlayer::additiveBlendType_t *p_addViewAnglBlendState; // r28
  double v13; // fp11
  double x; // fp0
  double y; // fp13
  double v16; // fp6
  double v17; // fp5
  double v18; // fp3
  idPresentablePlayer::additiveBlendType_t addViewAnglBlendState; // r11
  __int64 v20; // r7
  idPresentablePlayer::additiveBlendType_t v21; // r11
  idPresentablePlayer::additiveBlendType_t *v22; // r27
  __int64 v23; // r8
  double v24; // fp9
  double v25; // fp13
  double yaw; // fp12
  double Offset; // fp1
  double pitch; // fp13
  double v29; // fp12
  double v30; // fp0
  double v31; // fp13
  int PlayerGameTime; // r3
  int v33; // r9 OVERLAPPED
  __int64 v34; // r11 OVERLAPPED
  double v35; // fp31
  double v36; // fp13
  double z; // fp12
  double w; // fp11
  idAngles *v39; // r3
  idQuat v40; // [sp+50h] [-160h] BYREF
  idQuat v41; // [sp+60h] [-150h] BYREF
  idPLogScope v42[2]; // [sp+70h] [-140h] BYREF
  idQuat v43; // [sp+80h] [-130h] BYREF
  idAngles v44; // [sp+90h] [-120h] BYREF
  idMat3 v45; // [sp+A0h] [-110h] BYREF
  float v46; // [sp+C4h] [-ECh]
  float v47; // [sp+C8h] [-E8h]
  _WORD v48[32]; // [sp+D0h] [-E0h] BYREF
  idMat3 v49; // [sp+110h] [-A0h] BYREF

  RD_EventBegin(name: "idPresentablePlayer::UpdateViewAngles");
  LODWORD(v2) = "idPresentablePlayer::UpdateViewAngles";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v42, pl: &pLog, gMask: v2, label: v3);
  idPresentablePlayer::GetViewAngles(
    this: (idPresentablePlayer *)&v40,
    result: (const idAngles *)this,
    includeWeaponKick: true);
  if ( common->IsMultiplayer(this: common)
    && pm_clientAuthoritative.valueInteger != 0
    && !this->IsLocallyControlled(this)
    && (memcpy(Dst: v48, Src: &this->ucmdTracker1.usercmd, Size: 0x3Cu),
        HIDWORD(v4) = idPlayer::AllowClientAuthPhysics(this: (idPlayer *)this->entity),
        BYTE3(v4) != 0) )
  {
    v5 = v48[17];
    LODWORD(v4) = v48[16];
    *(_QWORD *)&v41.x = v4;
    v40.z = 0.0;
    v40.y = (float)*(__int64 *)((char *)&v4 - 4) * (float)0.0054931641;
    v40.x = (float)v4 * (float)0.0054931641;
    idPresentablePlayer::SetViewAngles(this, angles: (const idAngles *)&v40, force: true);
    idPLogScope::~idPLogScope(this: v42);
  }
  else if ( (*((_BYTE *)this + 47032) & 4) != 0 || !this->IsDead(this) )
  {
    if ( common->IsMultiplayer(this: common) && idPresentablePlayer::IsPlayerControlInhibited(this) )
      this->physicsObj.current.deltaViewAngles = ang_zero;
    idUCmdTracker::Clamp180(this: &this->ucmdTracker1, clamped: &v44, a3: v9);
    v40.x = v44.pitch;
    v40.y = v44.yaw;
    v40.z = v44.roll;
    v10 = 0.0;
    if ( idHands::ShouldAnimateCamera(this: &this->hands) )
    {
      TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: &this->hands);
      idTreeAnimator::GetJointIndex(
        this: (idTreeAnimator *)&v40.w,
        result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
        jointName: "camera");
      if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                              this: TreeAnimatorFromPresentable,
                              pose: DRIVER_MODEL,
                              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v40.w),
                              origin: (idVec3 *)&v45.mat[1].y,
                              axis: &v49) != 0 )
      {
        HIWORD(v40.w) = HIWORD(idTreeAnimator::GetJointIndex(
                                 this: (idTreeAnimator *)&v41,
                                 result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
                                 jointName: "origin")->__vftable);
        if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                                this: TreeAnimatorFromPresentable,
                                pose: DRIVER_MODEL,
                                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v40.w),
                                origin: (idVec3 *)&v45.mat[2].z,
                                axis: (idMat3 *)v48) != 0 )
        {
          this->addViewAngles = *idMat3::ToAngles(this: &v45, result: (idAngles *)&v49);
          p_addViewAnglBlendState = &this->addViewAnglBlendState;
          LODWORD(v41.x) = &TreeAnimatorFromPresentable->g.axis;
          v13 = (float)(v45.mat[2].x - v47);
          x = TreeAnimatorFromPresentable->g.axis.mat[0].x;
          y = TreeAnimatorFromPresentable->g.axis.mat[2].y;
          v16 = (float)(v45.mat[1].y - v45.mat[2].z);
          v17 = (float)((float)(TreeAnimatorFromPresentable->g.axis.mat[0].y * (float)(v45.mat[1].y - v45.mat[2].z))
                      + (float)(TreeAnimatorFromPresentable->g.axis.mat[1].y * (float)(v45.mat[1].z - v46)));
          v18 = (float)((float)(TreeAnimatorFromPresentable->g.axis.mat[1].x * (float)(v45.mat[1].z - v46))
                      + (float)(TreeAnimatorFromPresentable->g.axis.mat[2].x * (float)(v45.mat[2].x - v47)));
          this->addViweOffset.z = (float)(TreeAnimatorFromPresentable->g.axis.mat[2].z * (float)(v45.mat[2].x - v47))
                                + (float)((float)(TreeAnimatorFromPresentable->g.axis.mat[0].z
                                                * (float)(v45.mat[1].y - v45.mat[2].z))
                                        + (float)(TreeAnimatorFromPresentable->g.axis.mat[1].z
                                                * (float)(v45.mat[1].z - v46)));
          this->addViweOffset.y = (float)((float)y * (float)v13) + (float)v17;
          this->addViweOffset.x = (float)((float)x * (float)v16) + (float)v18;
          addViewAnglBlendState = this->addViewAnglBlendState;
          if ( addViewAnglBlendState == ADDITIVE_VIEW_ANGLE_BLEND_FULL_IN )
          {
            v10 = 1.0;
          }
          else
          {
            if ( addViewAnglBlendState == ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT
              || addViewAnglBlendState == ADDITIVE_VIEW_ANGLE_BLEND_OUT )
            {
              *p_addViewAnglBlendState = ADDITIVE_VIEW_ANGLE_BLEND_IN;
              this->addViewAnglDoneAtTime = idClientGame::GetPlayerGameTime(this: clientGame) + 500;
            }
            LODWORD(v20) = this->addViewAnglDoneAtTime - idClientGame::GetPlayerGameTime(this: clientGame);
            *(_QWORD *)&v41.x = v20;
            v10 = (float)-(float)((float)((float)v20 * (float)0.0020000001) - (float)1.0);
            if ( v10 > 1.0 )
            {
              v10 = 1.0;
              *p_addViewAnglBlendState = ADDITIVE_VIEW_ANGLE_BLEND_FULL_IN;
            }
          }
        }
      }
    }
    else
    {
      v21 = this->addViewAnglBlendState;
      v22 = &this->addViewAnglBlendState;
      if ( v21 != ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT )
      {
        if ( v21 == ADDITIVE_VIEW_ANGLE_BLEND_FULL_IN || v21 == ADDITIVE_VIEW_ANGLE_BLEND_IN )
        {
          *v22 = ADDITIVE_VIEW_ANGLE_BLEND_OUT;
          this->addViewAnglDoneAtTime = idClientGame::GetPlayerGameTime(this: clientGame) + 500;
        }
        LODWORD(v23) = this->addViewAnglDoneAtTime - idClientGame::GetPlayerGameTime(this: clientGame);
        *(_QWORD *)&v41.x = v23;
        v10 = (float)((float)v23 * (float)0.0020000001);
        if ( v10 < 0.0 )
        {
          v10 = 0.0;
          *v22 = ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT;
        }
      }
    }
    if ( this->addViewAnglBlendState == ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT )
    {
      this->addViweOffset.x = 0.0;
      this->addViweOffset.z = 0.0;
      this->addViweOffset.y = 0.0;
    }
    this->addViewAngles.pitch = this->addViewAngles.pitch * (float)v10;
    v24 = (float)(this->addViewAngles.roll * (float)v10);
    this->addViewAngles.yaw = this->addViewAngles.yaw * (float)v10;
    this->addViewAngles.roll = v24;
    idPresentablePlayer::UpdateWeaponKick(this, viewAngles: (idAngles *)&v40);
    LODWORD(v41.x) = this->entity;
    if ( LODWORD(v41.x) != 0
      && idEntity::GetBindMaster(this: (idEntity *)LODWORD(v41.x)) == nullptr
      && (float)((float)(this->physicsObj.current.deltaViewAngles.pitch * this->physicsObj.current.deltaViewAngles.pitch)
               + (float)((float)(this->physicsObj.current.deltaViewAngles.yaw
                               * this->physicsObj.current.deltaViewAngles.yaw)
                       + (float)(this->physicsObj.current.deltaViewAngles.roll
                               * this->physicsObj.current.deltaViewAngles.roll))) != 0.0 )
    {
      v25 = v40.y;
      yaw = this->physicsObj.current.deltaViewAngles.yaw;
      this->physicsObj.current.deltaViewAngles.pitch = ang_zero.pitch;
      v40.y = (float)yaw + (float)v25;
      this->physicsObj.current.deltaViewAngles.yaw = ang_zero.yaw;
      this->physicsObj.current.deltaViewAngles.roll = ang_zero.roll;
    }
    Offset = idWeaponKick::GetOffset(this: &this->weaponKick[2]);
    pitch = this->localMinViewAngles.pitch;
    v29 = this->localMaxViewAngles.pitch;
    v30 = (float)((float)Offset + v40.x);
    if ( (*((_BYTE *)this + 47032) & 0x20) != 0 )
    {
      if ( v30 >= pitch )
      {
        if ( v30 > v29 )
          v30 = this->localMaxViewAngles.pitch;
      }
      else
      {
        v30 = this->localMinViewAngles.pitch;
      }
    }
    else
    {
      if ( v30 >= pitch )
      {
        if ( v30 > v29 )
          v30 = this->localMaxViewAngles.pitch;
      }
      else
      {
        v30 = this->localMinViewAngles.pitch;
      }
      v31 = this->localMinViewAngles.yaw;
      if ( v40.y >= v31 )
      {
        if ( v40.y <= (double)this->localMaxViewAngles.yaw )
          v31 = v40.y;
        else
          v31 = this->localMaxViewAngles.yaw;
      }
      v40.y = v31;
    }
    v40.x = (float)v30 - (float)Offset;
    if ( (*((_BYTE *)this + 47033) & 4) != 0 )
    {
      PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this);
      v33 = 47028;
      LODWORD(v34) = this->perfectOriginDuration;
      HIDWORD(v34) = PlayerGameTime - this->perfectOriginStartTime;
      if ( SHIDWORD(v34) >= (int)v34 )
      {
        v36 = this->perfectOriginRotation.y;
        z = this->perfectOriginRotation.z;
        w = this->perfectOriginRotation.w;
        v43.x = this->perfectOriginRotation.x;
        v43.y = v36;
        v43.z = z;
        v43.w = w;
      }
      else
      {
        *(_QWORD *)&v41.x = *(__int64 *)((char *)&v34 + 4);
        *(_QWORD *)&v45.mat[0].x = v34;
        v35 = (float)((float)*(__int64 *)((char *)&v34 + 4) / (float)v34);
        idAngles::ToQuat(this: (idAngles *)&v41, result: &v40);
        idQuat::Slerp(this: &v43, from: &v41, to: &this->perfectOriginRotation, t: v35);
      }
      v39 = idQuat::ToAngles(this: (idQuat *)&v45, result: (idAngles *)&v43);
      v40.x = v39->pitch;
      v40.y = v39->yaw;
      v40.z = v39->roll;
    }
    idPresentablePlayer::SetViewAngles(this, angles: (const idAngles *)&v40, force: false);
    idPLogScope::~idPLogScope(this: v42);
  }
  else
  {
    LODWORD(v41.x) = this->entity;
    v40.z = 40.0;
    v40.x = -15.0;
    if ( LODWORD(v41.x) != 0
      && idEntity::GetBindMaster(this: (idEntity *)LODWORD(v41.x)) == nullptr
      && (float)((float)(this->physicsObj.current.deltaViewAngles.roll * this->physicsObj.current.deltaViewAngles.roll)
               + (float)((float)(this->physicsObj.current.deltaViewAngles.pitch
                               * this->physicsObj.current.deltaViewAngles.pitch)
                       + (float)(this->physicsObj.current.deltaViewAngles.yaw
                               * this->physicsObj.current.deltaViewAngles.yaw))) != 0.0 )
    {
      v6 = v40.y;
      v7 = this->physicsObj.current.deltaViewAngles.yaw;
      this->physicsObj.current.deltaViewAngles.pitch = ang_zero.pitch;
      this->physicsObj.current.deltaViewAngles.yaw = ang_zero.yaw;
      v40.y = (float)v7 + (float)v6;
      this->physicsObj.current.deltaViewAngles.roll = ang_zero.roll;
    }
    idPresentablePlayer::ClearWeaponKick(this);
    idPresentablePlayer::SetViewAngles(this: v8, angles: (const idAngles *)&v40, force: false);
    idPLogScope::~idPLogScope(this: v42);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$499766
// EA  : 0x82B89424
// RVA : 0x00B89424
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_499766()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 308));
}


// ========================================================================
// __unwind$499767
// EA  : 0x82B8944C
// RVA : 0x00B8944C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_499767()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 112));
}


// ========================================================================
// ?CalcCurWeaponSpread@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B89480
// RVA : 0x00B89480
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::CalcCurWeaponSpread(idPresentablePlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  double spreadRecoveryDelay; // fp29
  double v5; // fp26
  double SpreadReductionWithZoom; // fp27
  double v7; // fp28
  double v8; // fp30
  idWeapon *v9; // r3
  idWeapon *v10; // r30
  double valueFloat; // fp30
  float *v12; // r3
  double v15; // fp28
  __int64 v16; // r11
  double CurrentValue; // fp27
  double v18; // fp30
  __int64 v19; // r8
  idClientGame *v20; // r3
  __int64 v21; // r7
  __int64 v22; // r11
  double v23; // fp30
  int PlayerGameTime; // r3
  unsigned __int64 v25; // [sp+50h] [-80h] BYREF
  idPLogScope v26[9]; // [sp+60h] [-70h] BYREF

  RD_EventBegin(name: "idPresentablePlayer::CalcCurWeaponSpread");
  LODWORD(v2) = "idPresentablePlayer::CalcCurWeaponSpread";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &pLog, gMask: v2, label: v3);
  spreadRecoveryDelay = 100.0;
  v5 = 1.0;
  SpreadReductionWithZoom = 1.0;
  v7 = 1.0;
  v8 = 1.0;
  v9 = this->GetEquippedWeapon(this, a2: 2);
  v10 = v9;
  if ( v9 != nullptr
    && idWeapon::GetCurrentProjectileDecl(this: v9, secondaryAmmo: (_cntlzw(v9->weaponState - 1) & 0x20) != 0) != nullptr )
  {
    if ( (unsigned __int8)idPresentablePlayer::IsCrouching(this) != 0 )
      v5 = *(float *)&v10->decl[3].__vftable;
    if ( (*((_BYTE *)v10 + 452) & 8) != 0 )
      SpreadReductionWithZoom = idWeapon::GetSpreadReductionWithZoom(this: v10);
    if ( (*((_BYTE *)v10 + 452) & 2) != 0 )
      v7 = 0.0;
    valueFloat = pm_runspeed.valueFloat;
    v12 = (float *)((int (__fastcall *)(unsigned __int64 *))this->physicsObj.GetLinearVelocity)(a1: &v25);
    _FP5 = (float)((float)1.0
                 - (float)((float)__fsqrts((float)((float)(v12[2] * v12[2])
                                                 + (float)((float)(*v12 * *v12) + (float)(v12[1] * v12[1]))))
                         / (float)valueFloat));
    __asm { fsel      f4, f5, f6, f31 }
    v8 = (float)((float)(*(float *)&v10->decl[3].trackedMemory * (float)_FP4) + (float)1.0);
    spreadRecoveryDelay = idWeapon::GetCurrentProjectileDecl(
                            this: v10,
                            secondaryAmmo: (_cntlzw(v10->weaponState - 1) & 0x20) != 0)->weaponFeedBack.spreadRecoveryDelay;
  }
  v15 = (float)((float)((float)((float)v8 * (float)v7) * (float)SpreadReductionWithZoom) * (float)v5);
  LODWORD(v16) = idClientGame::GetPlayerGameTime(this: clientGame);
  v25 = v16;
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->baseWeaponSpread, time: (float)v16);
  v18 = pm_clientZoomInDelay.valueFloat;
  LODWORD(v19) = idClientGame::GetPlayerGameTime(this: clientGame);
  this->baseWeaponSpread.duration = v18;
  this->baseWeaponSpread.startValue = CurrentValue;
  v20 = clientGame;
  v25 = v19;
  this->baseWeaponSpread.endValue = v15;
  this->baseWeaponSpread.startTime = (float)v19;
  this->baseWeaponSpread.currentValue = CurrentValue;
  this->baseWeaponSpread.currentTime = (float)v19 - (float)1.0;
  LODWORD(v21) = idClientGame::GetPlayerGameTime(this: v20);
  v25 = v21;
  if ( (float)v21 >= (double)(float)(this->kickWeaponSpread.startTime + this->kickWeaponSpread.duration) )
  {
    LODWORD(v22) = idClientGame::GetPlayerGameTime(this: clientGame);
    v25 = v22;
    v23 = idInterpolate<float>::GetCurrentValue(this: &this->kickWeaponSpread, time: (float)v22);
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    this->kickWeaponSpread.startValue = v23;
    v25 = __PAIR64__(byte_821B0000, PlayerGameTime);
    this->kickWeaponSpread.endValue = 0.0;
    this->kickWeaponSpread.duration = 250.0;
    this->kickWeaponSpread.currentValue = v23;
    this->kickWeaponSpread.startTime = (float)__SPAIR64__(byte_821B0000, PlayerGameTime) + (float)spreadRecoveryDelay;
    this->kickWeaponSpread.currentTime = (float)((float)__SPAIR64__(byte_821B0000, PlayerGameTime)
                                               + (float)spreadRecoveryDelay)
                                       - (float)1.0;
  }
  idPLogScope::~idPLogScope(this: v26);
  RD_EventEnd();
}


// ========================================================================
// __unwind$500058
// EA  : 0x82B89750
// RVA : 0x00B89750
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_500058()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 104));
}


// ========================================================================
// __unwind$500059
// EA  : 0x82B89778
// RVA : 0x00B89778
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_500059()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 96));
}


// ========================================================================
// ?UpdateWeapon@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B897A8
// RVA : 0x00B897A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateWeapon(idPresentablePlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idWeapon *PendingWeapon; // r28
  const idDeclAmmo *pendingAmmo; // r4
  const idDeclAmmo **p_pendingAmmo; // r29
  const idDeclAmmo *v7; // r28
  idInventoryCollection *v8; // r3
  const idDeclAmmo **v9; // r29
  idWeapon *CurrentWeapon; // r3
  int *p_nextWeaponChangeTime; // r26
  idWeapon *v12; // r27
  const idDeclAmmo *v13; // r4
  const idDeclAmmo **v14; // r29
  const idDeclAmmo *v15; // r27
  idInventoryCollection *v16; // r3
  int *p_nextAmmoChangeTime; // r27
  const idDeclAmmo **v18; // r29
  idWeapon *v19; // r3
  int QuickWeaponSlot; // r3
  idPLogScope v21[22]; // [sp+50h] [-B0h] BYREF

  RD_EventBegin(name: "idPresentablePlayer::UpdateWeapon");
  LODWORD(v2) = "idPresentablePlayer::UpdateWeapon";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v21, pl: &pLog, gMask: v2, label: v3);
  if ( this->IsDead(this) )
  {
    idHands::Update(this: &this->hands);
    idPLogScope::~idPLogScope(this: v21);
  }
  else
  {
    if ( this->playerHud.hudState >= HUDSTATE_ALL && idPresentablePlayer::GetControl(this) == nullptr )
    {
      if ( this->playerHud.allowWeaponChange )
      {
        if ( (unsigned __int8)idUCmdTracker::WasReleasedForMenu(this: &this->ucmdTracker1, mask: 64) != 0 )
        {
          PendingWeapon = idPresentablePlayer::GetPendingWeapon(this);
          if ( PendingWeapon != nullptr )
          {
            if ( PendingWeapon != this->GetEquippedWeapon(this, a2: 2) )
            {
              idHands::SelectWeapon(
                this: &this->hands,
                slot: EQUIP_RIGHT_HAND,
                weapon: PendingWeapon,
                useIntroBringUp: this->useIntroBringUp);
              pendingAmmo = this->pendingAmmo;
              p_pendingAmmo = &this->pendingAmmo;
              if ( pendingAmmo != nullptr )
              {
                if ( idWeapon::GetAmmoDeclIndex(this: PendingWeapon, ammo: pendingAmmo, secondaryAmmo: false) > -1 )
                {
                  v7 = *p_pendingAmmo;
                  v8 = this->GetInventory(this);
                  if ( idInventoryCollection::FindTotalInventoryItemCount(this: v8, decl: v7) > 0 )
                    idHands::ForceAmmo(this: &this->hands, ammoDecl: *p_pendingAmmo);
                }
                *p_pendingAmmo = nullptr;
                this->nextAmmoChangeTime = 0;
              }
            }
            this->pendingQuickWeapon = -1;
            this->useIntroBringUp = false;
            this->nextWeaponChangeTime = 0;
          }
          v9 = &this->pendingAmmo;
          if ( this->pendingAmmo != nullptr )
          {
            CurrentWeapon = (idWeapon *)idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
            if ( idWeapon::GetAmmoDeclIndex(this: CurrentWeapon, ammo: *v9, secondaryAmmo: false) > -1 )
              idHands::SelectAmmo(this: &this->hands, slot: EQUIP_RIGHT_HAND, ammoDecl: *v9);
            *v9 = nullptr;
            this->nextAmmoChangeTime = 0;
          }
        }
        p_nextWeaponChangeTime = &this->nextWeaponChangeTime;
        if ( this->nextWeaponChangeTime > 0
          && idClientGame::GetPlayerGameTime(this: clientGame) > *p_nextWeaponChangeTime
          && !idUCmdTracker::IsPressedForMenu(this: &this->ucmdTracker1, mask: 64) )
        {
          v12 = idPresentablePlayer::GetPendingWeapon(this);
          if ( v12 != nullptr && v12 != this->GetEquippedWeapon(this, a2: 2) )
          {
            idHands::SelectWeapon(
              this: &this->hands,
              slot: EQUIP_RIGHT_HAND,
              weapon: v12,
              useIntroBringUp: this->useIntroBringUp);
            v13 = this->pendingAmmo;
            v14 = &this->pendingAmmo;
            this->pendingQuickWeapon = -1;
            this->useIntroBringUp = false;
            *p_nextWeaponChangeTime = 0;
            if ( v13 != nullptr && idWeapon::GetAmmoDeclIndex(this: v12, ammo: v13, secondaryAmmo: false) > -1 )
            {
              v15 = *v14;
              v16 = this->GetInventory(this);
              if ( idInventoryCollection::FindTotalInventoryItemCount(this: v16, decl: v15) > 0 )
              {
                idHands::ForceAmmo(this: &this->hands, ammoDecl: *v14);
                *v14 = nullptr;
                this->nextAmmoChangeTime = 0;
              }
            }
          }
        }
        p_nextAmmoChangeTime = &this->nextAmmoChangeTime;
        if ( this->nextAmmoChangeTime > 0 )
        {
          v18 = &this->pendingAmmo;
          if ( this->pendingAmmo != nullptr
            && idClientGame::GetPlayerGameTime(this: clientGame) > *p_nextAmmoChangeTime
            && !idUCmdTracker::IsPressedForMenu(this: &this->ucmdTracker1, mask: 64) )
          {
            v19 = (idWeapon *)idHands::GetCurrentWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND);
            if ( idWeapon::GetAmmoDeclIndex(this: v19, ammo: *v18, secondaryAmmo: false) > -1 )
              idHands::SelectAmmo(this: &this->hands, slot: EQUIP_RIGHT_HAND, ammoDecl: *v18);
            *v18 = nullptr;
            *p_nextAmmoChangeTime = 0;
          }
        }
      }
      idPresentablePlayer::CalcCurWeaponSpread(this);
      if ( this->playerHud.allowWeaponChange && idPresentablePlayer::GetControl(this) == nullptr )
      {
        if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: &this->ucmdTracker1, mask: 64) != 0 )
          this->weaponButtonPressTime = idClientGame::GetPlayerGameTime(this: clientGame);
        if ( (unsigned __int8)idUCmdTracker::WasReleasedForPlayer(this: &this->ucmdTracker1, mask: 64) != 0
          && this->pendingQuickWeapon == -1
          && idClientGame::GetPlayerGameTime(this: clientGame) - this->weaponButtonPressTime < 180 )
        {
          QuickWeaponSlot = idPresentablePlayer::NextQuickWeaponSlot(this);
          this->pendingQuickWeapon = QuickWeaponSlot;
          if ( QuickWeaponSlot != -1 )
            this->nextWeaponChangeTime = idClientGame::GetPlayerGameTime(this: clientGame);
        }
      }
    }
    idPresentablePlayer::UpdateWeaponAmmoInfo(this);
    idHands::Update(this: &this->hands);
    if ( this->entity != nullptr && common->IsServer(this: common) )
      idPlayer::PlayerBehavior_PostEvent(this: (idPlayer *)this->entity, event: PBE_HANDS_UPDATED);
    idPLogScope::~idPLogScope(this: v21);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$500185
// EA  : 0x82B89C60
// RVA : 0x00B89C60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_500185()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$500186
// EA  : 0x82B89C88
// RVA : 0x00B89C88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _unwind_500186()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// `dynamic initializer for 'pm_lookUpTweak''
// EA  : 0x8336DFB0
// RVA : 0x0136DFB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_lookUpTweak__()
{
  idCVar::idCVar(
    this: &pm_lookUpTweak,
    name: "pm_lookUpTweak",
    value: "5",
    flags: 4,
    description: "Depress the view this much when looking up to avoid clipping into geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_lookUpTweak__);
}


// ========================================================================
// `dynamic initializer for 'coop_dmgRumbleScalarHigh''
// EA  : 0x8336E008
// RVA : 0x0136E008
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__coop_dmgRumbleScalarHigh__()
{
  idCVar::idCVar(
    this: &coop_dmgRumbleScalarHigh,
    name: "coop_dmgRumbleScalarHigh",
    value: "0.5",
    flags: 4,
    description: "Rumble high scalar when taking damage in coop",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__coop_dmgRumbleScalarHigh__);
}


// ========================================================================
// `dynamic initializer for 'coop_dmgRumbleScalarLow''
// EA  : 0x8336E060
// RVA : 0x0136E060
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__coop_dmgRumbleScalarLow__()
{
  idCVar::idCVar(
    this: &coop_dmgRumbleScalarLow,
    name: "coop_dmgRumbleScalarLow",
    value: "0.3",
    flags: 4,
    description: "Rumble high scalar when taking damage in coop",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__coop_dmgRumbleScalarLow__);
}


// ========================================================================
// `dynamic initializer for 'coop_dmgRumbleDurHigh''
// EA  : 0x8336E0B8
// RVA : 0x0136E0B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__coop_dmgRumbleDurHigh__()
{
  idCVar::idCVar(
    this: &coop_dmgRumbleDurHigh,
    name: "coop_dmgRumbleDurHigh",
    value: "100",
    flags: 2,
    description: "Rumble high duration when taking damage in coop",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__coop_dmgRumbleDurHigh__);
}


// ========================================================================
// `dynamic initializer for 'coop_dmgRumbleDurLow''
// EA  : 0x8336E110
// RVA : 0x0136E110
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__coop_dmgRumbleDurLow__()
{
  idCVar::idCVar(
    this: &coop_dmgRumbleDurLow,
    name: "coop_dmgRumbleDurLow",
    value: "50",
    flags: 2,
    description: "Rumble high duration when taking damage in coop",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__coop_dmgRumbleDurLow__);
}


// ========================================================================
// `dynamic initializer for 'pm_debugView''
// EA  : 0x8336E168
// RVA : 0x0136E168
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_debugView__()
{
  idCVar::idCVar(
    this: &pm_debugView,
    name: "pm_debugView",
    value: "0",
    flags: 1,
    description: "if true will draw debug info for player view calculations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_debugView__);
}


// ========================================================================
// `dynamic initializer for 'p_useStepUpSprings''
// EA  : 0x8336E1C0
// RVA : 0x0136E1C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_useStepUpSprings__()
{
  idCVar::idCVar(
    this: &p_useStepUpSprings,
    name: "p_useStepUpSprings",
    value: "1",
    flags: 1,
    description: "Use springs instead of the procedural bob cycle to smooth view and hands movement when stepping up or crouching",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_useStepUpSprings__);
}


// ========================================================================
// `dynamic initializer for 'p_stepUpViewSpringK''
// EA  : 0x8336E218
// RVA : 0x0136E218
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_stepUpViewSpringK__()
{
  idCVar::idCVar(
    this: &p_stepUpViewSpringK,
    name: "p_stepUpViewSpringK",
    value: "350",
    flags: 4,
    description: "Spring constant for step-up and crouch spring on view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_stepUpViewSpringK__);
}


// ========================================================================
// `dynamic initializer for 'p_stepUpHandsSpringK''
// EA  : 0x8336E270
// RVA : 0x0136E270
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_stepUpHandsSpringK__()
{
  idCVar::idCVar(
    this: &p_stepUpHandsSpringK,
    name: "p_stepUpHandsSpringK",
    value: "325",
    flags: 4,
    description: "Spring constant for step-up and crouch spring on hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_stepUpHandsSpringK__);
}


// ========================================================================
// `dynamic initializer for 'g_debugPlayerZoom''
// EA  : 0x8336E2C8
// RVA : 0x0136E2C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugPlayerZoom__()
{
  idCVar::idCVar(
    this: &g_debugPlayerZoom,
    name: "g_debugPlayerZoom",
    value: "0",
    flags: 1,
    description: "Debug zoom values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugPlayerZoom__);
}


// ========================================================================
// `dynamic initializer for 'g_debugZoomBlur''
// EA  : 0x8336E320
// RVA : 0x0136E320
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugZoomBlur__()
{
  idCVar::idCVar(
    this: &g_debugZoomBlur,
    name: "g_debugZoomBlur",
    value: "0",
    flags: 1,
    description: "Debug zoom blur values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugZoomBlur__);
}


// ========================================================================
// `dynamic initializer for 'g_blendedZoom_nonLinear''
// EA  : 0x8336E378
// RVA : 0x0136E378
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_blendedZoom_nonLinear__()
{
  idCVar::idCVar(
    this: &g_blendedZoom_nonLinear,
    name: "g_blendedZoom_nonLinear",
    value: "1",
    flags: 1,
    description: "Do a non linear blended lerp for",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_blendedZoom_nonLinear__);
}


// ========================================================================
// `dynamic initializer for 'rpOutlineWidth''_0
// EA  : 0x8336E3D0
// RVA : 0x0136E3D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _dynamic_initializer_for__rpOutlineWidth___0()
{
  rpOutlineWidth_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpOutlineWidth_0;
}


// ========================================================================
// `dynamic initializer for 'rpOutlineOpacity''_0
// EA  : 0x8336E3F0
// RVA : 0x0136E3F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _dynamic_initializer_for__rpOutlineOpacity___0()
{
  rpOutlineOpacity_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpOutlineOpacity_0;
}


// ========================================================================
// `dynamic initializer for 'net_errorSmoothingMaxDecay''
// EA  : 0x8336E410
// RVA : 0x0136E410
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_errorSmoothingMaxDecay__()
{
  idCVar::idCVar(
    this: &net_errorSmoothingMaxDecay,
    name: "net_errorSmoothingMaxDecay",
    value: "25.0",
    flags: 4,
    description: "Max rate at which origin error smoothing decays (in units per game frame)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_errorSmoothingMaxDecay__);
}


// ========================================================================
// `dynamic initializer for 'net_errorSmoothingDecay''
// EA  : 0x8336E468
// RVA : 0x0136E468
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_errorSmoothingDecay__()
{
  idCVar::idCVar(
    this: &net_errorSmoothingDecay,
    name: "net_errorSmoothingDecay",
    value: "0.06",
    flags: 4,
    description: "Rate at which error smoothing decays (in percent per game frame)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_errorSmoothingDecay__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientZoomInDelay''
// EA  : 0x8336E4C0
// RVA : 0x0136E4C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientZoomInDelay__()
{
  idCVar::idCVar(
    this: &pm_clientZoomInDelay,
    name: "pm_clientZoomInDelay",
    value: "1.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientZoomInDelay__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientUseThrottleTime''
// EA  : 0x8336E518
// RVA : 0x0136E518
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientUseThrottleTime__()
{
  idCVar::idCVar(
    this: &pm_clientUseThrottleTime,
    name: "pm_clientUseThrottleTime",
    value: "250",
    flags: 2,
    description: " how long to wait untill we can send the next use message to the server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientUseThrottleTime__);
}


// ========================================================================
// `dynamic initializer for 'player_damageFeedbackScale''
// EA  : 0x8336E570
// RVA : 0x0136E570
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_damageFeedbackScale__()
{
  idCVar::idCVar(
    this: &player_damageFeedbackScale,
    name: "player_damageFeedbackScale",
    value: "4.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_damageFeedbackScale__);
}


// ========================================================================
// `dynamic initializer for 'player_spikeDamageFeedbackScale''
// EA  : 0x8336E5C8
// RVA : 0x0136E5C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_spikeDamageFeedbackScale__()
{
  idCVar::idCVar(
    this: &player_spikeDamageFeedbackScale,
    name: "player_spikeDamageFeedbackScale",
    value: "15.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_spikeDamageFeedbackScale__);
}


// ========================================================================
// `dynamic initializer for 'rp_DecalPos''
// EA  : 0x8336E620
// RVA : 0x0136E620
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer_shared.cpp
// ========================================================================

void _dynamic_initializer_for__rp_DecalPos__()
{
  rp_DecalPos.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_DecalPos;
}

