
// ========================================================================
// ??0idPresentableActor@@QAA@PAVidActor@@PAVidRenderModel@@PAVidAnimStack@@PAVidInventoryCollection@@HPBVidDeclFX@@_N@Z
// EA  : 0x82B737A0
// RVA : 0x00B737A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentableActor *__fastcall idPresentableActor::idPresentableActor(
        idPresentableActor *this,
        idActor *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_,
        idInventoryCollection *inv,
        int entityNum_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_)
{
  idActorModifierManager *p_predictedActorModifierManager; // r29

  p_predictedActorModifierManager = &this->predictedActorModifierManager;
  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent,
    renderModel_,
    animStack_,
    entityNumber_: entityNum_,
    fxDecl_,
    useSphereModel_);
  this->__vftable = (idPresentableActor_vtbl *)&idPresentableActor::`vftable';
  idActorModifierManager::idActorModifierManager(this: &this->predictedActorModifierManager);
  this->actorModifierManager = p_predictedActorModifierManager;
  this->overdrivePoints = 0.0;
  return this;
}


// ========================================================================
// __unwind$492828
// EA  : 0x82B737FC
// RVA : 0x00B737FC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_492828()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idPresentableActor@@UAA@XZ
// EA  : 0x82B73830
// RVA : 0x00B73830
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::~idPresentableActor(idPresentableActor *this)
{
  this->__vftable = (idPresentableActor_vtbl *)&idPresentableActor::`vftable';
  idActorModifierManager::~idActorModifierManager(this: &this->predictedActorModifierManager);
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// __unwind$492845_0
// EA  : 0x82B73884
// RVA : 0x00B73884
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_492845_0()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?PostSerializeRead@idPresentableActor@@UAAX_N@Z
// EA  : 0x82B738B0
// RVA : 0x00B738B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::PostSerializeRead(idPresentableActor *this, BOOL firstClientFrame)
{
  idPresentableAnimatedEntity::PostSerializeRead(this, firstClientFrame);
  this->actorModifierManager->PostSerializeRead(this: this->actorModifierManager, a2: firstClientFrame);
}


// ========================================================================
// ?ClientThink@idPresentableActor@@UAAXHM_N@Z
// EA  : 0x82B73900
// RVA : 0x00B73900
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::ClientThink(idPresentableActor *this, int curTime, double fraction, bool predict)
{
  idPresentableAnimatedEntity::ClientThink(this, curTime, fraction, predict);
  idActorModifierManager::ServerThink(this: this->actorModifierManager);
}


// ========================================================================
// ?ServerThink@idPresentableActor@@UAAXH@Z
// EA  : 0x82B73938
// RVA : 0x00B73938
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::ServerThink(idPresentableActor *this, int curTime)
{
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  idActorModifierManager::ServerThink(this: this->actorModifierManager);
}


// ========================================================================
// ?HandleActorModifierMessage@idPresentableActor@@UAAXIE@Z
// EA  : 0x82B73970
// RVA : 0x00B73970
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::HandleActorModifierMessage(
        idPresentableActor *this,
        unsigned int uid,
        unsigned __int8 index)
{
  this->actorModifierManager->HandleActorModifierMessage(this: this->actorModifierManager, a2: uid, a3: index);
}


// ========================================================================
// ?GetSpeedScale@idPresentableActor@@UAAMXZ
// EA  : 0x82B73988
// RVA : 0x00B73988
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

double __fastcall idPresentableActor::GetSpeedScale(idPresentableActor *this)
{
  return idActorModifierManager::GetSpeedModifier(this: this->actorModifierManager);
}


// ========================================================================
// ?GetDamageScale@idPresentableActor@@UAAMXZ
// EA  : 0x82B73990
// RVA : 0x00B73990
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

double __fastcall idPresentableActor::GetDamageScale(idPresentableActor *this)
{
  return idActorModifierManager::GetDamageModifier(this: this->actorModifierManager);
}


// ========================================================================
// ?IsOverdriveDisabled@idPresentableActor@@UAA_NXZ
// EA  : 0x82B73998
// RVA : 0x00B73998
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentableActor::IsOverdriveDisabled(idPresentableActor *this)
{
  return idActorModifierManager::IsOverdriveDisabled(this: this->actorModifierManager);
}


// ========================================================================
// ?ExecuteCoopScoringCallout@idPresentablePlayer@@QAAXPBVidDeclOnlineScoringCallout@@@Z
// EA  : 0x82B73A28
// RVA : 0x00B73A28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ExecuteCoopScoringCallout(
        idPresentablePlayer *this,
        const idDeclOnlineScoringCallout *callout)
{
  idPresentablePlayer *LocalPresentablePlayer; // r3
  char v5; // r11
  const idSoundShader *sound; // r5

  if ( callout == nullptr
    || (LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: clientGame),
        v5 = 1,
        LocalPresentablePlayer == nullptr) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
  {
    sound = callout->sound;
    if ( sound != nullptr )
      idPresentableVehicle::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: sound,
        soundShaderFlags: 0,
        peerMask: 0);
  }
}


// ========================================================================
// ?GetMoveBufferItemForClientGameFrame@idPresentablePlayer@@QAAAAUmoveBufferItem_t@1@H@Z
// EA  : 0x82B73AB0
// RVA : 0x00B73AB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentablePlayer::moveBufferItem_t *__fastcall idPresentablePlayer::GetMoveBufferItemForClientGameFrame(
        idPresentablePlayer *this,
        int frame)
{
  return &this->moveBuffer[frame % 64];
}


// ========================================================================
// ?WriteFireDataToUserCmd@idPresentablePlayer@@QAAXAAVusercmd_t@@@Z
// EA  : 0x82B73AD8
// RVA : 0x00B73AD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::WriteFireDataToUserCmd(idPresentablePlayer *this, usercmd_t *usercmd)
{
  usercmd->fireCount = this->clientFire.fireCount;
  *(_DWORD *)usercmd->fireAngles = *(_DWORD *)this->clientFire.fireAngles;
  usercmd->firePos[0] = this->clientFire.firePos[0];
  usercmd->firePos[1] = this->clientFire.firePos[1];
  usercmd->firePos[2] = this->clientFire.firePos[2];
}


// ========================================================================
// ?IsInterpolated@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B73B18
// RVA : 0x00B73B18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::IsInterpolated(idPresentablePlayer *this)
{
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( !common->IsClient(this: common) )
    return 0;
  v2 = this->IsLocallyControlled(this);
  v3 = 1;
  if ( v2 )
    return 0;
  return v3;
}


// ========================================================================
// ?SetLastPlayerInputAngles@idUCmdTracker@@QAAXPAF@Z
// EA  : 0x82B73B90
// RVA : 0x00B73B90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::SetLastPlayerInputAngles(idUCmdTracker *this, __int16 *angles)
{
  this->lastPlayerInputAngles[0] = *angles;
  this->lastPlayerInputAngles[1] = angles[1];
}


// ========================================================================
// ?GetAnglesMatchLastPlayerInputAngles@idUCmdTracker@@QAA_NPAF@Z
// EA  : 0x82B73BA8
// RVA : 0x00B73BA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idUCmdTracker::GetAnglesMatchLastPlayerInputAngles(idUCmdTracker *this, __int16 *angles)
{
  int v3; // r9
  __int16 *i; // r11

  v3 = 0;
  for ( i = this->lastPlayerInputAngles; *i == 0 || *i == *angles; ++i )
  {
    ++v3;
    ++angles;
    if ( v3 >= 2 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?PlayLootSound@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B73BF8
// RVA : 0x00B73BF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PlayLootSound(idPresentablePlayer *this, bool hasLoot)
{
  const idSoundShader *sndLootEntity; // r5
  _BYTE v4[208]; // [sp+50h] [-E0h] BYREF

  if ( hasLoot )
    sndLootEntity = idPresentablePlayer::GetPlayerSounds(
                      this: (idPresentablePlayer *)v4,
                      result: (const idDeclPlayerProps::playerSounds_t *)this)->sndLootEntity;
  else
    sndLootEntity = idPresentablePlayer::GetPlayerSounds(
                      this: (idPresentablePlayer *)v4,
                      result: (const idDeclPlayerProps::playerSounds_t *)this)->sndCantLootEntity;
  idPresentableVehicle::StartSoundShader(
    this,
    channel: SND_CHANNEL_ANY,
    shader: sndLootEntity,
    soundShaderFlags: 0,
    peerMask: 0);
}


// ========================================================================
// ?GetLocalView@idPresentablePlayer@@QAAPAUlocalView_t@@XZ
// EA  : 0x82B73C60
// RVA : 0x00B73C60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

localView_t *__fastcall idPresentablePlayer::GetLocalView(idPresentablePlayer *this)
{
  if ( !this->IsLocallyControlled(this) )
    return nullptr;
  if ( !this->localView.initialized )
  {
    this->localView.initialized = true;
    idPlayerHud_Render::Init(this: &this->localView.hudRender, mapName: &clientGame->mapName);
    idPlayerGuis_Render::Init(this: &this->localView.guisRender, mapName: &clientGame->mapName);
  }
  return &this->localView;
}


// ========================================================================
// ?ChallengeExit@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B73CE0
// RVA : 0x00B73CE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ChallengeExit(idPresentablePlayer *this)
{
  this->challengeLeavingSoon = true;
  this->challengeLocalRestart = false;
  this->challengeRemoteRestart = false;
}


// ========================================================================
// ?SetPlayerGuiFile@idPresentablePlayer@@QAAXW4playerGuis_t@1@PBD_N@Z
// EA  : 0x82B73D10
// RVA : 0x00B73D10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetPlayerGuiFile(
        idPresentablePlayer *this,
        idPresentablePlayer::playerGuis_t g,
        const char *filename,
        bool purgableImage)
{
  idStr::operator=(this: &this->guiNames[g], text: filename);
  this->purgableGuis[g] = purgableImage;
}


// ========================================================================
// ?HandleGuiEvent@idPresentablePlayer@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82B73D58
// RVA : 0x00B73D58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::HandleGuiEvent(idPresentablePlayer *this, const sysEvent_t *ev)
{
  int v3; // r30
  idSWF **i; // r31

  v3 = 20;
  for ( i = &this->loadedGuis[20]; *i == nullptr || (unsigned __int8)idSWF::HandleEvent(this: *i, event: ev) == 0; --i )
  {
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?p_printInhibitFlags_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B73FD8
// RVA : 0x00B73FD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall p_printInhibitFlags_f(const idCmdArgs *args)
{
  int v1; // r30
  const char *v2; // r3
  idPresentablePlayer *PlayerPresentableByIndex; // r31

  if ( args->argc == 1 )
  {
    v1 = 0;
  }
  else
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v1 = atol(nptr: v2);
  }
  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: v1);
  if ( PlayerPresentableByIndex != nullptr )
  {
    idLib::Printf(fmt: "The following flags are inhibited on player #%d \n", v1);
    idUCmdInhibit::DebugPrintInhibitFlagNames(flags: PlayerPresentableByIndex->inhibitFlags);
    if ( (*((_BYTE *)PlayerPresentableByIndex + 47033) & 2) != 0 )
      idLib::Printf(fmt: "Restricted Gameplay is ON\n");
    if ( !PlayerPresentableByIndex->playerHud.allowWeaponChange
      || (*((_BYTE *)PlayerPresentableByIndex + 47034) & 0x40) != 0 )
    {
      idLib::Printf(fmt: "Weaponchange is BLOCKED\n");
    }
    if ( (*((_BYTE *)PlayerPresentableByIndex + 47034) & 0x80) != 0 )
      idLib::Printf(fmt: "Raise weapon is BLOCKED\n");
  }
  else
  {
    idLib::Printf(fmt: "Could not print inhibit flags: #%d not a valid player \n", v1);
  }
}


// ========================================================================
// ?sub_status_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B740F8
// RVA : 0x00B740F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall sub_status_f(const idCmdArgs *args)
{
  int v1; // r31
  const char *v2; // r3
  idPlayerProfileGame *v3; // r3
  idPlayerProfileGame *v4; // r29
  int i; // r31
  bool SubtitleForLanguage; // r28
  const char *LanguageIsoName; // r3

  if ( args->argc == 1 )
  {
    v1 = 0;
  }
  else
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v1 = atol(nptr: v2);
  }
  idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: v1);
  v4 = v3;
  if ( v3 != nullptr )
  {
    for ( i = 0; i < 10; ++i )
    {
      SubtitleForLanguage = idPlayerProfileGame::GetSubtitleForLanguage(this: v4, language: i);
      LanguageIsoName = idSubtitles::GetLanguageIsoName(language: i);
      idLib::Printf(fmt: "#%d %s: %d\n", i, LanguageIsoName, SubtitleForLanguage);
    }
  }
  else
  {
    idLib::Printf(fmt: "Could not find profile for player #%d\n", v1);
  }
}


// ========================================================================
// ?sub_set_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B741B8
// RVA : 0x00B741B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall sub_set_f(const idCmdArgs *args)
{
  int v2; // r31
  const char *v3; // r3
  idPlayerProfileGame *v4; // r3
  idPlayerProfileGame *v5; // r29
  unsigned int v6; // r31
  const char *LanguageIsoName; // r27
  char *v8; // r3
  const char *v9; // r3
  int v10; // r3

  if ( args->argc == 1 )
  {
    v2 = 0;
  }
  else
  {
    if ( args->argc <= 3 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[3];
    v2 = atol(nptr: v3);
  }
  idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: v2);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = 0;
    while ( 1 )
    {
      LanguageIsoName = idSubtitles::GetLanguageIsoName(language: v6);
      v8 = idCmdArgs::Argv(this: args, arg: 1);
      if ( idStr::Icmp(s1: v8, s2: LanguageIsoName) == 0 )
        break;
      if ( (int)++v6 >= 10 )
      {
        if ( args->argc <= 1 )
          idLib::Printf(fmt: "Could not language %s\n", &byte_8200D768);
        else
          idLib::Printf(fmt: "Could not language %s\n", args->argv[1]);
        return;
      }
    }
    if ( args->argc <= 2 )
      v9 = &byte_8200D768;
    else
      v9 = args->argv[2];
    v10 = atol(nptr: v9);
    idPlayerProfileGame::SetSubtitleForLanguage(this: v5, language: v6, active: (-v10 & ~v10) < 0);
  }
  else
  {
    idLib::Printf(fmt: "Could not find profile for player #%d\n", v2);
  }
}


// ========================================================================
// ?GetActorEntity@idPresentableActor@@QBAPAVidActor@@XZ
// EA  : 0x82B74348
// RVA : 0x00B74348
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idActor *__fastcall idPresentableActor::GetActorEntity(idPresentableActor *this)
{
  return idActor::CastTo(c: (idActor *)this->entity);
}


// ========================================================================
// ?GetEquippedWeapon@idPresentableActor@@UBAPAVidWeapon@@W4equipSlot_t@@@Z
// EA  : 0x82B74350
// RVA : 0x00B74350
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idWeapon *__fastcall idPresentableActor::GetEquippedWeapon(idPresentableActor *this, equipSlot_t slot)
{
  idActor *v3; // r3

  v3 = idActor::CastTo(c: (idActor *)this->entity);
  return idActor::GetEquippedWeapon(this: v3, slot);
}


// ========================================================================
// ?GetEquippedWeapon@idPresentableActor@@UBAPAVidWeapon@@XZ
// EA  : 0x82B74388
// RVA : 0x00B74388
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idWeapon *__fastcall idPresentableActor::GetEquippedWeapon(idPresentableActor *this)
{
  idActor *v1; // r3

  v1 = idActor::CastTo(c: (idActor *)this->entity);
  return v1->GetEquippedWeapon(this: v1);
}


// ========================================================================
// ?UpdateSerializedView@idPresentablePlayer@@UAAXXZ
// EA  : 0x82B74420
// RVA : 0x00B74420
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateSerializedView(idPresentablePlayer *this)
{
  idView::GetViewPos(this: &this->view, origin: &this->serializedViewOrigin, axis: &this->serializedviewAxis);
}


// ========================================================================
// ?ClientJobSync@idPresentablePlayer@@UAAXXZ
// EA  : 0x82B74438
// RVA : 0x00B74438
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientJobSync(idPresentablePlayer *this)
{
  idPresentableAnimatedEntity::ClientJobSync(this);
  if ( this != (idPresentablePlayer *)-37616 )
    idHands::JobSync(this: &this->hands);
}


// ========================================================================
// ?UpdateScoringCallout@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B74478
// RVA : 0x00B74478
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateScoringCallout(idPresentablePlayer *this)
{
  int calloutHistoryIndex; // r10
  int lastCalloutHistoryIndex; // r11
  int v4; // r29
  const idDeclOnlineScoringCallout *v5; // r28
  int v6; // r6
  int v7; // r30
  int v8; // r11
  const idSoundShader *v9; // r5
  int v10; // r10
  int coopScoringIndex; // r9
  int lastCoopScoringIndex; // r11
  int v13; // r7

  calloutHistoryIndex = this->calloutHistoryIndex;
  lastCalloutHistoryIndex = this->lastCalloutHistoryIndex;
  if ( lastCalloutHistoryIndex <= calloutHistoryIndex - 4 )
    lastCalloutHistoryIndex = calloutHistoryIndex - 4;
  this->lastCalloutHistoryIndex = lastCalloutHistoryIndex;
  v4 = 0;
  v5 = nullptr;
  if ( lastCalloutHistoryIndex < calloutHistoryIndex )
  {
    do
    {
      v6 = 8 * (this->lastCalloutHistoryIndex % 4 + 1952);
      v7 = *(int *)((char *)&this->__vftable + v6);
      if ( v7 != 0 )
      {
        v8 = *(_DWORD *)(v7 + 76);
        if ( v8 != 0 )
        {
          if ( v8 >= v4 )
          {
            v5 = *(const idDeclOnlineScoringCallout **)((char *)&this->__vftable + v6);
            v4 = *(_DWORD *)(v7 + 76);
          }
        }
        else if ( idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr )
        {
          v9 = *(const idSoundShader **)(v7 + 64);
          if ( v9 != nullptr )
            idPresentableVehicle::StartSoundShader(
              this,
              channel: SND_CHANNEL_ANY,
              shader: v9,
              soundShaderFlags: 0,
              peerMask: 0);
        }
      }
      v10 = this->lastCalloutHistoryIndex + 1;
      this->lastCalloutHistoryIndex = v10;
    }
    while ( v10 < this->calloutHistoryIndex );
    if ( v5 != nullptr )
      idPresentablePlayer::ExecuteCoopScoringCallout(this, callout: v5);
  }
  coopScoringIndex = this->coopScoringIndex;
  lastCoopScoringIndex = this->lastCoopScoringIndex;
  if ( lastCoopScoringIndex <= coopScoringIndex - 4 )
    lastCoopScoringIndex = coopScoringIndex - 4;
  this->lastCoopScoringIndex = lastCoopScoringIndex;
  if ( lastCoopScoringIndex < coopScoringIndex )
  {
    do
    {
      this->coopScoreHistory[this->lastCoopScoringIndex % 4].time = idGameTimeManager::GetGameMs(
                                                                      this: &clientGame->gameTimeManager,
                                                                      type: GAMETIME_SCALED);
      this->coopScoreHistory[this->lastCoopScoringIndex % 4].index = this->lastCoopScoringIndex;
      v13 = this->lastCoopScoringIndex + 1;
      this->lastCoopScoringIndex = v13;
    }
    while ( v13 < this->coopScoringIndex );
  }
}


// ========================================================================
// ?ClientUpdateFocusEntity@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B74620
// RVA : 0x00B74620
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientUpdateFocusEntity(idPresentablePlayer *this)
{
  int v1; // ctr
  float *p_z; // r11
  float y; // r7
  float z; // r6
  char *v5; // r10
  idVec3 v6; // [sp+50h] [-40h] BYREF
  char v7; // [sp+5Ch] [-34h] BYREF
  idMat3 v8; // [sp+60h] [-30h] BYREF

  v1 = 9;
  p_z = &this->firstPersonViewOrigin.z;
  y = this->firstPersonViewOrigin.y;
  z = this->firstPersonViewOrigin.z;
  v5 = &v7;
  v6.x = this->firstPersonViewOrigin.x;
  v6.y = y;
  v6.z = z;
  do
  {
    ++p_z;
    v5 += 4;
    *(float *)v5 = *p_z;
    --v1;
  }
  while ( v1 != 0 );
  idFocusTracker::ClientUpdateFocus(this: &this->focusTracker, owner: this, viewPos: &v6, viewAxis: &v8);
}


// ========================================================================
// ?SelectBestWeapon@idPresentablePlayer@@QAAPAVidWeapon@@XZ
// EA  : 0x82B74698
// RVA : 0x00B74698
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idWeapon *__fastcall idPresentablePlayer::SelectBestWeapon(idPresentablePlayer *this)
{
  idWeapon *v2; // r27
  double v3; // fp30
  idWeapon *v4; // r3
  int parent; // r26
  int v6; // r28
  bfx::Planner3D *v7; // r3
  idInventoryCollection *v8; // r3
  idWeapon *InventoryItem; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  idLaserCutter *v12; // r3
  idWeapon *v13; // r30
  double v14; // fp31
  idLaserCutter *v15; // r3
  idLaserCutter *v16; // r29
  const idInventoryCollection *v17; // r3
  const idAmmoItem *ammoClip; // r29
  idInventoryCollection *v19; // r3
  const idDeclAmmo *NextLoadableAmmo; // r29
  const idInventoryCollection *v21; // r3
  bfx::Planner3D *v22; // r3

  v2 = nullptr;
  v3 = -1.0;
  v4 = this->GetEquippedWeapon(this, a2: 2);
  if ( v4 != nullptr )
    parent = (int)v4->decl[1].parent;
  else
    parent = -10;
  v6 = 0;
  v7 = (bfx::Planner3D *)this->GetInventory(this);
  if ( (int)idScriptObject::GetTypeDef(this: v7) > 0 )
  {
    do
    {
      v8 = this->GetInventory(this);
      InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v8, index: v6);
      v12 = (idLaserCutter *)idWeapon::CastTo(c: InventoryItem);
      v13 = v12;
      if ( v12 != nullptr )
      {
        LODWORD(v10) = parent;
        LODWORD(v11) = v12->decl[1].parent;
        v14 = (float)v11;
        if ( v14 != (float)v10 )
        {
          v15 = idLaserCutter::CastTo(c: v12);
          v16 = v15;
          if ( v15 != nullptr && !v15->hasBatteryUpgrade )
            v14 = 0.5;
          if ( v14 > v3 )
          {
            if ( !v13->NeedsReload(this: v13, a2: false) && v16 != nullptr && !v16->hasMobileReactorUpgrade
              || (v17 = this->GetInventory(this), idWeapon::CanReload(this: v13, inventory: v17, secondaryAmmo: false))
              || (ammoClip = v13->ammoClip,
                  v19 = this->GetInventory(this),
                  (NextLoadableAmmo = idWeapon::FindNextLoadableAmmo(
                                        this: v13,
                                        inventory: v19,
                                        curAmmo: ammoClip,
                                        secondaryAmmo: false)) != nullptr)
              && (v21 = this->GetInventory(this),
                  idWeapon::CanReload(this: v13, inventory: v21, ammoDecl: NextLoadableAmmo, secondaryAmmo: false)) )
            {
              v3 = v14;
              v2 = v13;
            }
          }
        }
      }
      ++v6;
      v22 = (bfx::Planner3D *)this->GetInventory(this);
    }
    while ( v6 < (int)idScriptObject::GetTypeDef(this: v22) );
    if ( v2 != nullptr && this != (idPresentablePlayer *)-37616 )
      idHands::SelectWeapon(this: &this->hands, slot: EQUIP_RIGHT_HAND, weapon: v2, useIntroBringUp: false);
  }
  return v2;
}


// ========================================================================
// ?SelectFists@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B748E0
// RVA : 0x00B748E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SelectFists(idPresentablePlayer *this, bool deleteCurrentWeapon)
{
  idInventoryCollection *v4; // r3
  idWeapon *InventoryItemByName; // r3
  idWeapon *v6; // r3
  idHands *p_hands; // r31

  v4 = this->GetInventory(this);
  InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(this: v4, internalName: "fists");
  if ( InventoryItemByName != nullptr )
  {
    v6 = idWeapon::CastTo(c: InventoryItemByName);
    if ( v6 != nullptr )
    {
      p_hands = &this->hands;
      idHands::SelectWeapon(
        this: p_hands,
        slot: (const equipSlot_t)v6->decl->equipSlot,
        weapon: v6,
        useIntroBringUp: false);
      if ( deleteCurrentWeapon )
        *((_BYTE *)p_hands + 7912) |= 0x80u;
    }
  }
}


// ========================================================================
// ?GetViewTransform@idPresentablePlayer@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B74980
// RVA : 0x00B74980
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::GetViewTransform(idPresentablePlayer *this, idVec3 *origin, idMat3 *axis)
{
  *origin = this->firstPersonViewOrigin;
  *axis = this->firstPersonViewAxis;
}


// ========================================================================
// ?StartScreenParticle@idPresentablePlayer@@QAAXW4fxScreenPrtType_t@@M@Z
// EA  : 0x82B74A08
// RVA : 0x00B74A08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::StartScreenParticle(
        idPresentablePlayer *this,
        unsigned int screenPrtType,
        double excludeAngle)
{
  idPresentablePlayer::screenParticleState_t *v4; // r30
  idRenderModel *pModel; // r31
  idPhysics_Player *p_physicsObj; // r29
  const idVec3 *v7; // r3
  idPhysics_Player_vtbl *v8; // r10
  const idMat3 *(__fastcall *GetAxis)(struct idPhysics_Player *, int); // r9
  const idMat3 *v10; // r3
  __int64 v11; // r7
  idClientGame *v12; // r11
  __int64 v13; // [sp+50h] [-40h]

  if ( screenPrtType <= 4 )
  {
    v4 = &this->screenPrtState.list[screenPrtType];
    pModel = v4->pModel;
    if ( v4->pModel != nullptr && !v4->isActive )
    {
      p_physicsObj = &this->physicsObj;
      v7 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
      if ( !pModel->deferredPositionInitialized || !pModel->useDeferredPosition )
      {
        pModel->g.origin.x = v7->x;
        pModel->g.origin.y = v7->y;
        pModel->g.origin.z = v7->z;
      }
      v8 = p_physicsObj->__vftable;
      pModel->deferredOrigin.x = v7->x;
      pModel->deferredOrigin.y = v7->y;
      GetAxis = v8->GetAxis;
      pModel->deferredOrigin.z = v7->z;
      v10 = GetAxis(this: p_physicsObj, a2: 0);
      idRenderModel::SetAxis(this: pModel, a: v10);
      HIDWORD(v11) = &off_822B0000;
      v12 = clientGame;
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      LODWORD(v11) = (v12->random.seed >> 10) & 0x7FFF;
      idRenderModel::SetParm(this: pModel, parm: rp->Diversity, scalar: (float)((float)v11 * (float)0.000030518509));
      idRenderModel::SetParm(this: pModel, parm: rp->TimeStop, scalar: 0.0);
      v13 = __PAIR64__(
              &unk_82390000,
              idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
      idRenderModel::SetParm(this: pModel, parm: rp->TimeOffset, scalar: (float)((float)v13 * (float)0.001));
      idRenderModel::SetParm(this: pModel, parm: rp->coverage, scalar: 1.0);
      idRenderModel::CommitThisFrame(this: pModel);
      v4->excludeAngle = excludeAngle;
      v4->fadeStartTime = 0;
      v4->isActive = true;
      v4->fadeEndTime = 0;
    }
  }
}


// ========================================================================
// ?StopScreenParticle@idPresentablePlayer@@QAAXW4fxScreenPrtType_t@@H@Z
// EA  : 0x82B74BE0
// RVA : 0x00B74BE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::StopScreenParticle(
        idPresentablePlayer *this,
        unsigned int screenPrtType,
        const int fadeTime)
{
  idPresentablePlayer::screenParticleState_t *v4; // r31
  idRenderModel *pModel; // r30
  int GameMs; // r3

  if ( screenPrtType <= 4 )
  {
    v4 = &this->screenPrtState.list[screenPrtType];
    if ( fadeTime != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v4->fadeStartTime = GameMs;
      v4->fadeEndTime = GameMs + fadeTime;
    }
    else
    {
      pModel = v4->pModel;
      if ( v4->pModel != nullptr && !pModel->unlinked )
      {
        idRenderModel::CommitThisFrame(this: v4->pModel);
        pModel->unlinked = true;
      }
      v4->isActive = false;
    }
  }
}


// ========================================================================
// ?StartFxScreenParticle@idPresentablePlayer@@QAAHPAVidRenderModel@@M@Z
// EA  : 0x82B74C98
// RVA : 0x00B74C98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::StartFxScreenParticle(
        idPresentablePlayer *this,
        idRenderModel *prtModel,
        double excludeAngle)
{
  bool *p_isActive; // r11
  int i; // r30
  idPhysics_Player *p_physicsObj; // r29
  const idVec3 *v10; // r3
  idPhysics_Player_vtbl *v11; // r10
  const idMat3 *(__fastcall *GetAxis)(struct idPhysics_Player *, int); // r9
  const idMat3 *v13; // r3
  __int64 v14; // r7
  idClientGame *v15; // r11
  float *v16; // r11
  __int64 v17; // [sp+50h] [-50h]

  if ( prtModel == nullptr )
    return -1;
  p_isActive = &this->fxScreenPrtState[0].isActive;
  for ( i = 0; i < 4; ++i )
  {
    if ( !*p_isActive )
      break;
    p_isActive += 20;
  }
  if ( i == 4 )
    return -1;
  p_physicsObj = &this->physicsObj;
  v10 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  if ( !prtModel->deferredPositionInitialized || !prtModel->useDeferredPosition )
  {
    prtModel->g.origin.x = v10->x;
    prtModel->g.origin.y = v10->y;
    prtModel->g.origin.z = v10->z;
  }
  v11 = p_physicsObj->__vftable;
  prtModel->deferredOrigin.x = v10->x;
  prtModel->deferredOrigin.y = v10->y;
  GetAxis = v11->GetAxis;
  prtModel->deferredOrigin.z = v10->z;
  v13 = GetAxis(this: &this->physicsObj, a2: 0);
  idRenderModel::SetAxis(this: prtModel, a: v13);
  HIDWORD(v14) = &off_822B0000;
  v15 = clientGame;
  clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  LODWORD(v14) = (v15->random.seed >> 10) & 0x7FFF;
  idRenderModel::SetParm(this: prtModel, parm: rp->Diversity, scalar: (float)((float)v14 * (float)0.000030518509));
  idRenderModel::SetParm(this: prtModel, parm: rp->TimeStop, scalar: 0.0);
  v17 = __PAIR64__(
          &unk_82390000,
          idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  idRenderModel::SetParm(this: prtModel, parm: rp->TimeOffset, scalar: (float)((float)v17 * (float)0.001));
  idRenderModel::SetParm(this: prtModel, parm: rp->coverage, scalar: 1.0);
  prtModel->g.allowSurfaceOnlyInViewID = this->entityNumber + 1;
  idRenderModel::CommitThisFrame(this: prtModel);
  v16 = (float *)((char *)this + 20 * i);
  v16[3972] = excludeAngle;
  *((_DWORD *)v16 + 3971) = prtModel;
  *((_BYTE *)v16 + 15900) = 1;
  v16[3974] = 0.0;
  v16[3973] = 0.0;
  return i;
}


// ========================================================================
// ?StopFxScreenParticle@idPresentablePlayer@@QAAXHH@Z
// EA  : 0x82B74EA8
// RVA : 0x00B74EA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::StopFxScreenParticle(
        idPresentablePlayer *this,
        unsigned int handle,
        const int fadeTime)
{
  char *v4; // r31
  int v5; // r30
  int GameMs; // r3

  if ( handle < 4 )
  {
    v4 = (char *)this + 20 * handle;
    if ( fadeTime != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      *((_DWORD *)v4 + 3973) = GameMs;
      *((_DWORD *)v4 + 3974) = GameMs + fadeTime;
    }
    else
    {
      v5 = *((_DWORD *)v4 + 3971);
      if ( v5 != 0 )
      {
        if ( *(_BYTE *)(v5 + 75) == 0 )
        {
          idRenderModel::CommitThisFrame(this: *((idRenderModel **)v4 + 3971));
          *(_BYTE *)(v5 + 75) = 1;
        }
        *((_DWORD *)v4 + 3971) = 0;
      }
      v4[15900] = 0;
    }
  }
}


// ========================================================================
// ?UpdateScreenParticles@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B74F48
// RVA : 0x00B74F48
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateScreenParticles(idPresentablePlayer *this)
{
  int num; // r4
  double x; // fp29
  double y; // fp30
  double z; // fp31
  int v6; // r26
  int v7; // r27
  idPresentablePlayer::screenParticleState_t *v8; // r30
  idRenderModel *pModel; // r31
  __int128 v10; // r9
  __int64 v11; // fp12
  int *p_fadeEndTime; // r30
  int i; // r28
  idRenderModel *v14; // r31
  __int128 v15; // r9
  __int64 v16; // [sp+58h] [-D8h]
  idVec3 v17; // [sp+70h] [-C0h] BYREF
  idMat3 v18[2]; // [sp+80h] [-B0h] BYREF

  idView::GetViewPos(this: &this->view, origin: &v17, axis: v18);
  num = this->screenPrtState.num;
  x = v18[0].mat[0].x;
  y = v18[0].mat[0].y;
  z = v18[0].mat[0].z;
  v6 = 0;
  v17.x = (float)(v18[0].mat[0].x * pm_screenParticleOffset.valueFloat) + v17.x;
  v17.y = v17.y + (float)(v18[0].mat[0].y * pm_screenParticleOffset.valueFloat);
  v17.z = v17.z + (float)(v18[0].mat[0].z * pm_screenParticleOffset.valueFloat);
  if ( num > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = &this->screenPrtState.list[v7];
      pModel = v8->pModel;
      if ( v8->pModel == nullptr || !v8->isActive )
        goto LABEL_16;
      if ( (float)((float)(vec3_up.x * (float)x) + (float)((float)((float)y * vec3_up.y) + (float)((float)z * vec3_up.z))) < (double)v8->excludeAngle )
      {
        if ( !pModel->unlinked )
        {
          idRenderModel::CommitThisFrame(this: pModel);
          pModel->unlinked = true;
        }
        goto LABEL_16;
      }
      if ( !pModel->deferredPositionInitialized || !pModel->useDeferredPosition )
        pModel->g.origin = v17;
      pModel->deferredOrigin = v17;
      idRenderModel::SetAxis(this: pModel, a: v18);
      if ( v8->fadeEndTime == 0 )
        goto LABEL_13;
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v8->fadeEndTime )
        break;
      LODWORD(v10) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      DWORD1(v10) = v8->fadeEndTime;
      v11 = v10;
      DWORD2(v10) = v8->fadeStartTime;
      idRenderModel::SetParm(
        this: pModel,
        parm: rp->coverage,
        scalar: (float)((float)1.0
              - (float)((float)((float)v11 - (float)*(__int64 *)((char *)&v10 + 4))
                      / (float)((float)*(__int64 *)&v10 - (float)*(__int64 *)((char *)&v10 + 4)))));
      idRenderModel::CommitThisFrame(this: pModel);
LABEL_16:
      ++v6;
      ++v7;
      if ( v6 >= this->screenPrtState.num )
        goto LABEL_17;
    }
    v8->isActive = false;
    if ( !pModel->unlinked )
    {
      idRenderModel::CommitThisFrame(this: pModel);
      pModel->unlinked = true;
    }
LABEL_13:
    idRenderModel::CommitThisFrame(this: pModel);
    goto LABEL_16;
  }
LABEL_17:
  p_fadeEndTime = &this->fxScreenPrtState[0].fadeEndTime;
  for ( i = 4; i != 0; --i )
  {
    v14 = (idRenderModel *)*(p_fadeEndTime - 3);
    if ( v14 != nullptr && *((_BYTE *)p_fadeEndTime + 4) != 0 )
    {
      if ( (float)((float)(vec3_up.x * (float)x) + (float)((float)((float)y * vec3_up.y) + (float)((float)z * vec3_up.z))) < (double)*((float *)p_fadeEndTime - 2) )
      {
        if ( !v14->unlinked )
        {
          idRenderModel::CommitThisFrame(this: (idRenderModel *)*(p_fadeEndTime - 3));
          v14->unlinked = true;
        }
      }
      else
      {
        if ( !v14->deferredPositionInitialized || !v14->useDeferredPosition )
          v14->g.origin = v17;
        v14->deferredOrigin = v17;
        idRenderModel::SetAxis(this: v14, a: v18);
        if ( *p_fadeEndTime != 0 )
        {
          if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < *p_fadeEndTime )
          {
            LODWORD(v15) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            DWORD1(v15) = *p_fadeEndTime;
            v16 = v15;
            DWORD2(v15) = *(p_fadeEndTime - 1);
            idRenderModel::SetParm(
              this: v14,
              parm: rp->coverage,
              scalar: (float)((float)1.0
                    - (float)((float)((float)v16 - (float)*(__int64 *)((char *)&v15 + 4))
                            / (float)((float)*(__int64 *)&v15 - (float)*(__int64 *)((char *)&v15 + 4)))));
            idRenderModel::CommitThisFrame(this: v14);
            goto LABEL_31;
          }
          *(p_fadeEndTime - 3) = 0;
          *((_BYTE *)p_fadeEndTime + 4) = 0;
          if ( !v14->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v14);
            v14->unlinked = true;
          }
        }
        idRenderModel::CommitThisFrame(this: v14);
      }
    }
LABEL_31:
    p_fadeEndTime += 5;
  }
}


// ========================================================================
// ?UpdateInfluenceTrail@idPresentableAI@@QAAXXZ
// EA  : 0x82B75348
// RVA : 0x00B75348
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableAI::UpdateInfluenceTrail(idPresentableAI *this)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idInfluenceTrailManager::UpdatePosition(
    this: &clientGame->influenceTrailManager,
    trail: &this->influenceHandle,
    position: &this->origin,
    time: GameMs);
}


// ========================================================================
// ?EnableInfluenceTrail@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B753B0
// RVA : 0x00B753B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::EnableInfluenceTrail(idPresentablePlayer *this)
{
  idInfluenceTrailManager::Enable(
    this: &clientGame->influenceTrailManager,
    presentable: this,
    trail: &this->influence,
    sndFoliage: nullptr);
}


// ========================================================================
// ?ClearAngles@idUCmdTracker@@QAAXXZ
// EA  : 0x82B753D8
// RVA : 0x00B753D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::ClearAngles(idUCmdTracker *this)
{
  memset(Dst: &this->prevcmd, Val: 0, Size: sizeof(this->prevcmd));
  memset(Dst: &this->usercmd, Val: 0, Size: sizeof(this->usercmd));
  memset(Dst: &this->usercmdRaw, Val: 0, Size: sizeof(this->usercmdRaw));
  this->viewAngles.roll = 0.0;
  this->viewAngles.yaw = 0.0;
  this->viewAngles.pitch = 0.0;
  this->prevViewAngles.roll = 0.0;
  this->prevViewAngles.yaw = 0.0;
  this->prevViewAngles.pitch = 0.0;
  this->cmdAngles.roll = 0.0;
  this->cmdAngles.yaw = 0.0;
  this->cmdAngles.pitch = 0.0;
  this->deltaViewAngles.roll = 0.0;
  this->deltaViewAngles.yaw = 0.0;
  this->deltaViewAngles.pitch = 0.0;
  this->constrainViewAngles = false;
  this->constrainedViewAnglesBase = ang_zero;
  this->constrainedViewAnglesMinDelta = ang_zero;
  this->constrainedViewAnglesMaxDelta = ang_zero;
  this->constrainedViewAnglesRate = 0.0;
}


// ========================================================================
// ?SetCmdAnglesToView@idUCmdTracker@@QAAXXZ
// EA  : 0x82B754C8
// RVA : 0x00B754C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::SetCmdAnglesToView(idUCmdTracker *this)
{
  __int16 v1; // r9
  __int16 v2; // r7
  __int16 v3; // r5

  v1 = (int)(float)(this->viewAngles.pitch * (float)182.04445);
  this->prevcmd.angles[0] = v1;
  this->usercmd.angles[0] = v1;
  v2 = (int)(float)(this->viewAngles.yaw * (float)182.04445);
  this->prevcmd.angles[1] = v2;
  this->usercmd.angles[1] = v2;
  v3 = (unsigned int)(int)(float)(this->viewAngles.roll * (float)182.04445) >> 16;
  this->prevcmd.angles[2] = v3;
  this->usercmd.angles[2] = v3;
}


// ========================================================================
// ?SetViewAngles@idUCmdTracker@@QAAXABVidAngles@@@Z
// EA  : 0x82B75538
// RVA : 0x00B75538
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUCmdTracker::SetViewAngles(idUCmdTracker *this, __int64 angles, int a3, __int64 a4)
{
  int v4; // r9

  LODWORD(a4) = this->usercmd.angles[0];
  this->deltaViewAngles.pitch = -(float)((float)((float)a4 * (float)0.0054931641) - *(float *)HIDWORD(angles));
  LODWORD(angles) = this->usercmd.angles[1];
  this->deltaViewAngles.yaw = -(float)((float)((float)angles * (float)0.0054931641) - *(float *)(HIDWORD(angles) + 4));
  v4 = this->usercmd.angles[2];
  this->deltaViewAngles.roll = -(float)((float)((float)*(__int64 *)((char *)&a4 - 4) * (float)0.0054931641)
                                      - *(float *)(HIDWORD(angles) + 8));
  this->viewAngles = *(idAngles *)HIDWORD(angles);
}


// ========================================================================
// ?ConstrainViewAngles@idUCmdTracker@@QAAXAAVidAngles@@@Z
// EA  : 0x82B755C8
// RVA : 0x00B755C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::ConstrainViewAngles(idUCmdTracker *this, idAngles *angles)
{
  double yaw; // fp0
  double v5; // fp11
  float v6; // r9
  float roll; // r8
  double v8; // fp13
  double v9; // fp13
  double v10; // fp31
  double i; // fp13
  double v12; // fp3
  double v13; // fp7
  double v14; // fp5
  double v15; // fp1
  double v16; // fp0
  long double v17; // fp2
  int GameMsPerFrame; // r3
  double pitch; // fp11
  double v20; // fp0
  double v21; // fp12
  double v22; // fp13
  double v31; // fp0
  double v32; // fp12
  double v33; // fp13
  double v42; // fp0
  double v43; // fp12
  double v44; // fp13
  double v53; // fp31
  long double v54; // fp2
  double v55; // fp0
  idAngles v56; // [sp+50h] [-60h] BYREF
  idAngles v57; // [sp+60h] [-50h] BYREF

  if ( this->constrainViewAngles )
  {
    yaw = this->constrainedViewAnglesBase.yaw;
    v5 = (float)(angles->yaw - this->constrainedViewAnglesBase.yaw);
    v6 = this->viewAngles.yaw;
    roll = this->viewAngles.roll;
    v57.pitch = this->viewAngles.pitch;
    v57.yaw = v6;
    v57.roll = roll;
    if ( v5 < -180.0 )
    {
      do
      {
        v8 = (float)(angles->yaw + (float)360.0);
        angles->yaw = angles->yaw + (float)360.0;
        yaw = this->constrainedViewAnglesBase.yaw;
      }
      while ( (float)((float)v8 - this->constrainedViewAnglesBase.yaw) < -180.0 );
    }
    if ( (float)(angles->yaw - (float)yaw) > 180.0 )
    {
      do
      {
        v9 = (float)(angles->yaw - (float)360.0);
        angles->yaw = angles->yaw - (float)360.0;
        yaw = this->constrainedViewAnglesBase.yaw;
      }
      while ( (float)((float)v9 - this->constrainedViewAnglesBase.yaw) > 180.0 );
    }
    v10 = v57.yaw;
    for ( i = (float)(v57.yaw - (float)yaw); i < -180.0; i = (float)((float)v10 - (float)yaw) )
      v10 = (float)((float)v10 + (float)360.0);
    if ( i > 180.0 )
    {
      do
        v10 = (float)((float)v10 - (float)360.0);
      while ( (float)((float)v10 - (float)yaw) > 180.0 );
    }
    if ( this->constrainedViewAnglesRate > 0.0 )
    {
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      pitch = this->constrainedViewAnglesBase.pitch;
      *(_QWORD *)&v56.pitch = __PAIR64__(&off_82040000, GameMsPerFrame);
      v20 = (float)((float)pitch - this->constrainedViewAnglesMinDelta.pitch);
      v21 = angles->pitch;
      v22 = (float)(this->constrainedViewAnglesMaxDelta.pitch + (float)pitch);
      if ( v21 >= v20 )
      {
        if ( v21 > v22 )
        {
          if ( v57.pitch <= v22 )
          {
            angles->pitch = this->constrainedViewAnglesMaxDelta.pitch + (float)pitch;
          }
          else
          {
            _FP8 = (float)((float)-(float)((float)(this->constrainedViewAnglesRate
                                                 * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame)
                                                         * (float)0.001))
                                         - angles->pitch)
                         - (float)(this->constrainedViewAnglesMaxDelta.pitch + (float)pitch));
            __asm { fsel      f7, f8, f9, f13 }
            _FP6 = (float)(v57.pitch - (float)_FP7);
            __asm { fsel      f5, f6, f7, f0 }
            angles->pitch = _FP5;
          }
        }
      }
      else if ( v57.pitch >= v20 )
      {
        angles->pitch = (float)pitch - this->constrainedViewAnglesMinDelta.pitch;
      }
      else
      {
        _FP8 = (float)((float)((float)(this->constrainedViewAnglesRate
                                     * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001))
                             + angles->pitch)
                     - (float)((float)pitch - this->constrainedViewAnglesMinDelta.pitch));
        __asm { fsel      f7, f8, f0, f9 }
        _FP6 = (float)(v57.pitch - (float)_FP7);
        __asm { fsel      f5, f6, f13, f7 }
        angles->pitch = _FP5;
      }
      v31 = (float)(this->constrainedViewAnglesBase.yaw - this->constrainedViewAnglesMinDelta.yaw);
      v32 = angles->yaw;
      v33 = (float)(this->constrainedViewAnglesMaxDelta.yaw + this->constrainedViewAnglesBase.yaw);
      if ( v32 >= v31 )
      {
        if ( v32 > v33 )
        {
          if ( v10 <= v33 )
          {
            angles->yaw = this->constrainedViewAnglesMaxDelta.yaw + this->constrainedViewAnglesBase.yaw;
          }
          else
          {
            _FP10 = (float)((float)-(float)((float)(this->constrainedViewAnglesRate
                                                  * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame)
                                                          * (float)0.001))
                                          - angles->yaw)
                          - (float)(this->constrainedViewAnglesMaxDelta.yaw + this->constrainedViewAnglesBase.yaw));
            __asm { fsel      f9, f10, f12, f13 }
            _FP8 = (float)((float)v10 - (float)_FP9);
            __asm { fsel      f7, f8, f9, f31 }
            angles->yaw = _FP7;
          }
        }
      }
      else if ( v10 >= v31 )
      {
        angles->yaw = this->constrainedViewAnglesBase.yaw - this->constrainedViewAnglesMinDelta.yaw;
      }
      else
      {
        _FP10 = (float)((float)((float)(this->constrainedViewAnglesRate
                                      * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001))
                              + angles->yaw)
                      - (float)(this->constrainedViewAnglesBase.yaw - this->constrainedViewAnglesMinDelta.yaw));
        __asm { fsel      f9, f10, f0, f12 }
        _FP8 = (float)((float)v10 - (float)_FP9);
        __asm { fsel      f7, f8, f31, f9 }
        angles->yaw = _FP7;
      }
      v42 = (float)(this->constrainedViewAnglesBase.roll - this->constrainedViewAnglesMinDelta.roll);
      v43 = angles->roll;
      v44 = (float)(this->constrainedViewAnglesMaxDelta.roll + this->constrainedViewAnglesBase.roll);
      if ( v43 >= v42 )
      {
        if ( v43 > v44 )
        {
          if ( v57.roll <= v44 )
          {
            angles->roll = this->constrainedViewAnglesMaxDelta.roll + this->constrainedViewAnglesBase.roll;
          }
          else
          {
            _FP8 = (float)((float)-(float)((float)(this->constrainedViewAnglesRate
                                                 * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame)
                                                         * (float)0.001))
                                         - angles->roll)
                         - (float)(this->constrainedViewAnglesMaxDelta.roll + this->constrainedViewAnglesBase.roll));
            __asm { fsel      f7, f8, f9, f13 }
            _FP6 = (float)(v57.roll - (float)_FP7);
            __asm { fsel      f5, f6, f7, f0 }
            angles->roll = _FP5;
          }
        }
      }
      else if ( v57.roll >= v42 )
      {
        angles->roll = this->constrainedViewAnglesBase.roll - this->constrainedViewAnglesMinDelta.roll;
      }
      else
      {
        _FP8 = (float)((float)((float)(this->constrainedViewAnglesRate
                                     * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001))
                             + angles->roll)
                     - (float)(this->constrainedViewAnglesBase.roll - this->constrainedViewAnglesMinDelta.roll));
        __asm { fsel      f7, f8, f0, f9 }
        _FP6 = (float)(v57.roll - (float)_FP7);
        __asm { fsel      f5, f6, f13, f7 }
        angles->roll = _FP5;
      }
    }
    else
    {
      v12 = (float)(this->constrainedViewAnglesBase.pitch - this->constrainedViewAnglesMinDelta.pitch);
      v13 = (float)(this->constrainedViewAnglesMaxDelta.yaw + this->constrainedViewAnglesBase.yaw);
      v14 = (float)(this->constrainedViewAnglesMaxDelta.roll + this->constrainedViewAnglesBase.roll);
      v15 = (float)(this->constrainedViewAnglesBase.yaw - this->constrainedViewAnglesMinDelta.yaw);
      v16 = (float)(this->constrainedViewAnglesBase.roll - this->constrainedViewAnglesMinDelta.roll);
      v57.pitch = this->constrainedViewAnglesMaxDelta.pitch + this->constrainedViewAnglesBase.pitch;
      v57.yaw = v13;
      v57.roll = v14;
      v56.pitch = v12;
      v56.yaw = v15;
      v56.roll = v16;
      idAngles::Clamp(this: angles, min: &v56, max: &v57);
    }
    v53 = angles->yaw;
    if ( v53 >= 360.0 || v53 < 0.0 )
    {
      *(double *)&v17 = (float)(angles->yaw * (float)0.0027777778);
      v54 = floor(x: v17);
      v53 = (float)-(float)((float)((float)*(double *)&v54 * (float)360.0) - (float)v53);
    }
    v55 = v53;
    if ( v53 > 180.0 )
      v55 = (float)((float)v53 - (float)360.0);
    angles->yaw = v55;
  }
}


// ========================================================================
// ?SetViewAnglesConstraintExplicit@idUCmdTracker@@QAAX_NABVidAngles@@11M@Z
// EA  : 0x82B75978
// RVA : 0x00B75978
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUCmdTracker::SetViewAnglesConstraintExplicit(
        idUCmdTracker *this,
        bool constrain,
        const idAngles *baseAngles,
        const idAngles *minDeltaAngles,
        const idAngles *maxDeltaAngles,
        double rate)
{
  float *p_constrainViewAngles; // r30
  int v7; // r31
  double v8; // fp31
  long double v9; // fp2
  double v10; // fp0

  this->constrainViewAngles = constrain;
  this->constrainedViewAnglesBase = *baseAngles;
  p_constrainViewAngles = (float *)&this->constrainViewAngles;
  this->constrainedViewAnglesMinDelta = *minDeltaAngles;
  v7 = 3;
  this->constrainedViewAnglesMaxDelta = *maxDeltaAngles;
  this->constrainedViewAnglesRate = rate;
  do
  {
    v8 = p_constrainViewAngles[1];
    if ( v8 >= 360.0 || v8 < 0.0 )
    {
      *(double *)&v9 = (float)(p_constrainViewAngles[1] * (float)0.0027777778);
      *(long double *)(&rate - 1) = floor(x: v9);
      v8 = (float)-(float)((float)((float)rate * (float)360.0) - (float)v8);
    }
    v10 = v8;
    if ( v8 > 180.0 )
      v10 = (float)((float)v8 - (float)360.0);
    *++p_constrainViewAngles = v10;
    --v7;
  }
  while ( v7 != 0 );
}


// ========================================================================
// ?ResetPrevViewAngles@idUCmdTracker@@QAAXXZ
// EA  : 0x82B75A70
// RVA : 0x00B75A70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::ResetPrevViewAngles(idUCmdTracker *this)
{
  this->prevViewAngles = this->viewAngles;
}


// ========================================================================
// ?SetViewAnglesConstraintExplicit@idPresentablePlayer@@QAAX_NABVidAngles@@11M@Z
// EA  : 0x82B75A90
// RVA : 0x00B75A90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetViewAnglesConstraintExplicit(
        idPresentablePlayer *this,
        bool constrain,
        const idAngles *baseAngles,
        const idAngles *minDeltaAngles,
        const idAngles *maxDeltaAngles,
        double rate)
{
  idUCmdTracker::SetViewAnglesConstraintExplicit(
    this: &this->ucmdTracker1,
    constrain,
    baseAngles,
    minDeltaAngles,
    maxDeltaAngles,
    rate);
}


// ========================================================================
// ?Update@idUCmdTracker@@QAA_NABVusercmd_t@@ABVidUCmdInhibit@@@Z
// EA  : 0x82B75AA0
// RVA : 0x00B75AA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idUCmdTracker::Update(idUCmdTracker *this, const usercmd_t *newcmd, const idUCmdInhibit *inhibit)
{
  usercmd_t *p_usercmd; // r28
  __int64 v7; // r6
  int v8; // r2 OVERLAPPED
  idAngles *p_viewAngles; // r25
  int flags; // r24
  int buttons; // r27
  unsigned __int8 game; // r26
  __int64 v13; // r9
  int v14; // r11
  int v15; // r11
  int v16; // r11
  double v17; // fp11
  double v18; // fp13
  int v19; // r3
  char v20; // r11
  __int64 v22; // r6
  int v23; // r2 OVERLAPPED
  char v24; // r7
  __int64 v25; // r9
  char forwardmove; // r3
  char maxForward; // r11
  int rightmove; // r11
  int upmove; // r11
  __int16 v30; // r11
  __int16 v31; // r10
  __int16 v32; // r9
  double yaw; // fp12
  double roll; // fp11
  int v35; // r3
  __int16 v36; // r11
  __int64 v37; // r11
  double v38; // fp12
  double v39; // fp11
  int v40; // r3

  p_usercmd = &this->usercmd;
  memcpy(Dst: &this->prevcmd, Src: &this->usercmd, Size: sizeof(this->prevcmd));
  memcpy(Dst: &this->usercmdRaw, Src: newcmd, Size: sizeof(this->usercmdRaw));
  this->prevViewAngles = this->viewAngles;
  p_viewAngles = &this->viewAngles;
  flags = inhibit->flags;
  buttons = inhibit->buttons;
  game = inhibit->game;
  if ( flags <= 0 )
  {
    memcpy(Dst: p_usercmd, Src: newcmd, Size: sizeof(usercmd_t));
    v24 = (game << 7) | *((_BYTE *)&this->usercmd + 9);
    p_usercmd->buttons &= ~buttons;
    HIDWORD(v25) = game;
    *((_BYTE *)&this->usercmd + 9) = v24;
    forwardmove = newcmd->forwardmove;
    maxForward = forwardmove;
    if ( forwardmove >= inhibit->minForward )
    {
      if ( forwardmove > inhibit->maxForward )
        maxForward = inhibit->maxForward;
    }
    else
    {
      maxForward = inhibit->minForward;
    }
    this->usercmd.forwardmove = maxForward;
    rightmove = newcmd->rightmove;
    if ( rightmove >= inhibit->minRight )
    {
      if ( rightmove > inhibit->maxRight )
        LOBYTE(rightmove) = inhibit->maxRight;
    }
    else
    {
      LOBYTE(rightmove) = inhibit->minRight;
    }
    this->usercmd.rightmove = rightmove;
    upmove = newcmd->upmove;
    if ( upmove >= inhibit->minUp )
    {
      if ( upmove > inhibit->maxUp )
        LOBYTE(upmove) = inhibit->maxUp;
    }
    else
    {
      LOBYTE(upmove) = inhibit->minUp;
    }
    this->usercmd.upmove = upmove;
    if ( game != 0 )
    {
      v30 = this->prevcmd.angles[0];
      v31 = this->prevcmd.angles[1];
      v32 = this->prevcmd.angles[2];
      this->usercmd.upmove = 0;
      this->usercmd.rightmove = 0;
      this->usercmd.forwardmove = 0;
      this->usercmd.angles[0] = v30;
      this->usercmd.angles[1] = v31;
      this->usercmd.angles[2] = v32;
    }
    if ( this->clearViewDeltaNextUpdate && (flags & 0x108) == 0 )
    {
      this->clearViewDeltaNextUpdate = false;
      yaw = this->viewAngles.yaw;
      LODWORD(v25) = this->usercmd.angles[0];
      roll = this->viewAngles.roll;
      this->deltaViewAngles.pitch = -(float)((float)((float)v25 * (float)0.0054931641) - p_viewAngles->pitch);
      HIDWORD(v25) = (unsigned __int16)this->usercmd.angles[1];
      LODWORD(v22) = SWORD1(v25);
      this->deltaViewAngles.yaw = -(float)((float)((float)v22 * (float)0.0054931641) - (float)yaw);
      HIDWORD(v22) = (unsigned __int16)this->usercmd.angles[2];
      v35 = SWORD1(v22);
      this->deltaViewAngles.roll = -(float)((float)((float)*(__int64 *)(&v23 - 1) * (float)0.0054931641) - (float)roll);
      LOWORD(v25) = this->usercmd.angles[2];
      this->prevcmd.angles[1] = this->usercmd.angles[1];
      v36 = this->usercmd.angles[0];
      this->prevcmd.angles[2] = v25;
      this->prevcmd.angles[0] = v36;
    }
    HIDWORD(v37) = *((_BYTE *)&this->usercmd + 9) & 0x80;
    if ( (*((_BYTE *)&this->usercmd + 9) & 0x80) == 0 )
    {
      HIDWORD(v37) = *((_BYTE *)&this->prevcmd + 9) & 0x80;
      if ( (*((_BYTE *)&this->prevcmd + 9) & 0x80) != 0 )
      {
        v38 = this->viewAngles.yaw;
        LODWORD(v25) = this->usercmd.angles[0];
        v39 = this->viewAngles.roll;
        this->deltaViewAngles.pitch = -(float)((float)((float)v25 * (float)0.0054931641) - p_viewAngles->pitch);
        HIDWORD(v25) = (unsigned __int16)this->usercmd.angles[1];
        LODWORD(v22) = SWORD1(v25);
        this->deltaViewAngles.yaw = -(float)((float)((float)v22 * (float)0.0054931641) - (float)v38);
        HIDWORD(v22) = (unsigned __int16)this->usercmd.angles[2];
        v40 = SWORD1(v22);
        this->deltaViewAngles.roll = -(float)((float)((float)*(__int64 *)(&v23 - 1) * (float)0.0054931641) - (float)v39);
        HIDWORD(v37) = (unsigned __int16)this->usercmd.angles[2];
        LOWORD(v25) = this->usercmd.angles[1];
        this->prevcmd.angles[0] = this->usercmd.angles[0];
        this->prevcmd.angles[1] = v25;
        this->prevcmd.angles[2] = WORD1(v37);
      }
    }
    LODWORD(v25) = this->usercmd.angles[0];
    this->cmdAngles.pitch = (float)v25 * (float)0.0054931641;
    LODWORD(v22) = this->usercmd.angles[1];
    this->cmdAngles.yaw = (float)v22 * (float)0.0054931641;
    LODWORD(v37) = this->usercmd.angles[2];
    this->cmdAngles.roll = (float)v37 * (float)0.0054931641;
    return 1;
  }
  else
  {
    HIDWORD(v13) = 1;
    if ( !this->cmdInhibited && (flags & 0x108) != 0 )
    {
      this->cmdInhibited = true;
      if ( (flags & 0x100) != 0 )
        this->clearViewDeltaNextUpdate = true;
    }
    if ( (flags & 1) != 0 )
    {
      this->usercmd.forwardmove = 0;
    }
    else
    {
      v14 = newcmd->forwardmove;
      if ( v14 >= inhibit->minForward )
      {
        if ( v14 > inhibit->maxForward )
          LOBYTE(v14) = inhibit->maxForward;
      }
      else
      {
        LOBYTE(v14) = inhibit->minForward;
      }
      this->usercmd.forwardmove = v14;
    }
    if ( (flags & 2) != 0 )
    {
      this->usercmd.rightmove = 0;
    }
    else
    {
      v15 = newcmd->rightmove;
      if ( v15 >= inhibit->minRight )
      {
        if ( v15 > inhibit->maxRight )
          LOBYTE(v15) = inhibit->maxRight;
      }
      else
      {
        LOBYTE(v15) = inhibit->minRight;
      }
      this->usercmd.rightmove = v15;
    }
    if ( (flags & 4) != 0 )
    {
      this->usercmd.upmove = 0;
    }
    else
    {
      v16 = newcmd->upmove;
      if ( v16 >= inhibit->minUp )
      {
        if ( v16 > inhibit->maxUp )
          LOBYTE(v16) = inhibit->maxUp;
      }
      else
      {
        LOBYTE(v16) = inhibit->minUp;
      }
      this->usercmd.upmove = v16;
    }
    if ( (flags & 0x10) == 0 )
      p_usercmd->buttons = newcmd->buttons;
    p_usercmd->buttons &= ~buttons;
    if ( (flags & 0x108) == 0 )
    {
      this->usercmd.angles[0] = newcmd->angles[0];
      this->usercmd.angles[1] = newcmd->angles[1];
      this->usercmd.angles[2] = newcmd->angles[2];
    }
    if ( this->cmdInhibited )
    {
      this->cmdInhibited = false;
      LODWORD(v7) = this->usercmd.angles[0];
      v17 = this->viewAngles.yaw;
      v18 = this->viewAngles.roll;
      this->deltaViewAngles.pitch = -(float)((float)((float)v7 * (float)0.0054931641) - p_viewAngles->pitch);
      v19 = this->usercmd.angles[1];
      this->deltaViewAngles.yaw = -(float)((float)((float)*(__int64 *)(&v8 - 1) * (float)0.0054931641) - (float)v17);
      LODWORD(v13) = this->usercmd.angles[2];
      this->deltaViewAngles.roll = -(float)((float)((float)v13 * (float)0.0054931641) - (float)v18);
    }
    if ( (*((_BYTE *)newcmd + 9) & 0x80) != 0 || (v20 = 0, game != 0) )
      v20 = 1;
    *((_BYTE *)&this->usercmd + 9) = (v20 << 7) | *((_BYTE *)&this->usercmd + 9) & 0x7F;
    return 0;
  }
}


// ========================================================================
// ?Clamp180@idUCmdTracker@@QBAXAAVidAngles@@@Z
// EA  : 0x82B75FF8
// RVA : 0x00B75FF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idUCmdTracker::Clamp180(idUCmdTracker *this, idAngles *clamped, long double a3)
{
  __int64 v3; // r9
  float *p_roll; // r28
  idAngles *p_deltaViewAngles; // r29
  __int16 *angles; // r30
  int i; // r31
  double v8; // fp31
  double v9; // fp0

  HIDWORD(v3) = byte_821B0000;
  p_roll = &clamped[-1].roll;
  p_deltaViewAngles = &this->deltaViewAngles;
  angles = this->usercmd.angles;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v3) = *angles;
    v8 = (float)((float)((float)v3 * (float)0.0054931641) + p_deltaViewAngles->pitch);
    if ( v8 >= 360.0 || v8 < 0.0 )
    {
      *(double *)&a3 = (float)((float)((float)((float)v3 * (float)0.0054931641) + p_deltaViewAngles->pitch)
                             * (float)0.0027777778);
      a3 = floor(x: a3);
      v8 = (float)-(float)((float)((float)*(double *)&a3 * (float)360.0) - (float)v8);
    }
    v9 = v8;
    if ( v8 > 180.0 )
      v9 = (float)((float)v8 - (float)360.0);
    *++p_roll = v9;
    ++angles;
    p_deltaViewAngles = (idAngles *)((char *)p_deltaViewAngles + 4);
  }
}


// ========================================================================
// ?GetUserCmdsForNetSend@idPresentablePlayer@@QAAHQAPAVusercmd_t@@H@Z
// EA  : 0x82B760B8
// RVA : 0x00B760B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::GetUserCmdsForNetSend(
        idPresentablePlayer *this,
        usercmd_t **buffer,
        int bufferSize)
{
  int result; // r3
  int v5; // r10
  usercmd_t **v6; // r9
  int i; // ctr
  int v8; // r11

  result = bufferSize;
  if ( bufferSize >= 64 )
    result = 64;
  if ( result >= this->lastRecordedMoveBufferIndex )
    result = this->lastRecordedMoveBufferIndex;
  v5 = 0;
  if ( result > 0 )
  {
    v6 = buffer - 1;
    for ( i = result; i != 0; --i )
    {
      v8 = this->lastRecordedMoveBufferIndex - result + v5++;
      *++v6 = &this->moveBuffer[v8 % 64].curCmd;
    }
  }
  return result;
}


// ========================================================================
// ?ScopeZoomBlur@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B76138
// RVA : 0x00B76138
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ScopeZoomBlur(idPresentablePlayer *this)
{
  idView::ForceBlurValues(this: &this->view, blurBegin: 5.0, blurEnd: 0.0, blurTime: 500.0);
}


// ========================================================================
// ?GetScopeGuiNum@idPresentablePlayer@@QBA?AW4scopeGuiNum_t@idDeclWeapon@@XZ
// EA  : 0x82B76158
// RVA : 0x00B76158
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idDeclWeapon::scopeGuiNum_t __fastcall idPresentablePlayer::GetScopeGuiNum(idPresentablePlayer *this)
{
  idWeapon *ControlWeapon; // r3

  ControlWeapon = (idWeapon *)idPresentablePlayer::GetControlWeapon(this);
  if ( ControlWeapon != nullptr && (*((_BYTE *)ControlWeapon + 452) & 8) != 0 )
    return idWeapon::GetScopeGuiNum(this: ControlWeapon);
  else
    return SCOPE_NONE;
}


// ========================================================================
// ?RespondToUseItem@idPresentablePlayer@@QAAXPAVidInventoryItem@@_N@Z
// EA  : 0x82B761A8
// RVA : 0x00B761A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::RespondToUseItem(idPresentablePlayer *this, idInventoryItem *item, bool used)
{
  idInventoryCollection *v5; // r3
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  char v7; // [sp+50h] [-E0h] BYREF

  if ( used && item != nullptr )
  {
    if ( item->decl->closeInventoryGuiOnUse && this->entity != nullptr && common->IsServer(this: common) )
      idPlayer::ForceCloseInventory(this: (idPlayer *)this->entity);
    if ( item->decl->removeOnUse )
    {
      v5 = this->GetInventory(this);
      idInventoryCollection::DeleteInventoryItem(this: v5, owner: this, item, count: 1);
    }
  }
  else if ( this->IsLocallyControlled(this) )
  {
    PlayerSounds = idPresentablePlayer::GetPlayerSounds(
                     this: (idPresentablePlayer *)&v7,
                     result: (const idDeclPlayerProps::playerSounds_t *)this);
    idPresentablePlayer::PlayLocalSound(
      this,
      channel: SND_CHANNEL_ITEM,
      shader: PlayerSounds->sndCantUseItem,
      soundShaderFlags: 0);
  }
}


// ========================================================================
// ?InventoryRemoved@idPresentablePlayer@@QAAXPAVidInventoryItem@@@Z
// EA  : 0x82B762B0
// RVA : 0x00B762B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InventoryRemoved(idPresentablePlayer *this, idInventoryItem *item)
{
  idEntity *entity; // r3

  if ( this->hands.leftItem.item == item )
    idHands::DetachItem(this: &this->hands, slot: EQUIP_LEFT_HAND);
  if ( this->hands.rightItem.item == item )
    idHands::DetachItem(this: &this->hands, slot: EQUIP_RIGHT_HAND);
  entity = this->entity;
  if ( entity != nullptr )
    entity->InventoryRemoved(this: entity, a2: item);
}


// ========================================================================
// ?ClientCanUseItem@idPresentablePlayer@@QAA_NPAVidInventoryItem@@@Z
// EA  : 0x82B76338
// RVA : 0x00B76338
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::ClientCanUseItem(idPresentablePlayer *this, idInventoryItem *item)
{
  unsigned int lastUsedTime; // r31
  int GameMs; // r3

  lastUsedTime = this->lastUsedTime;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (GameMs >> 31) + (GameMs >= lastUsedTime) + (lastUsedTime >> 31);
}


// ========================================================================
// ?SetServerOverridePos@idPresentablePlayer@@QAAX_NH@Z
// EA  : 0x82B76388
// RVA : 0x00B76388
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetServerOverridePos(idPresentablePlayer *this, bool teleport, int extra)
{
  this->serverOverridePositionTime = idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED)
                                   + extra;
  if ( teleport )
    this->teleported.count = (this->teleported.count + 1) % 7;
}


// ========================================================================
// ?GetInhibitFlags@idPresentablePlayer@@QAA?AW4inhibitFlags_t@idUCmdInhibit@@AAH@Z
// EA  : 0x82B76410
// RVA : 0x00B76410
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idUCmdInhibit::inhibitFlags_t __fastcall idPresentablePlayer::GetInhibitFlags(
        idPresentablePlayer *this,
        int *specificInhibitButtons)
{
  idUCmdInhibit::inhibitFlags_t inhibitFlags; // r31

  if ( (*((_BYTE *)this + 47032) & 0x20) != 0 || g_freeCam.valueInteger != 0 )
    return UCMD_INHIBIT_NONE;
  inhibitFlags = this->inhibitFlags;
  if ( this->entity != nullptr )
  {
    if ( (*((_BYTE *)this + 47033) & 2) != 0 )
    {
      inhibitFlags |= 4u;
      *specificInhibitButtons |= 0x33F7FFDBu;
    }
    if ( idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: (idPlayer *)this->entity)
      || idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: (idPlayer *)this->entity) )
    {
      inhibitFlags |= 4u;
      *specificInhibitButtons |= 0x800010u;
    }
    if ( idPlayer::PlayerBehavior_Takedown_IsInTakedown(this: (idPlayer *)this->entity) )
      return inhibitFlags | 0x17;
  }
  return inhibitFlags;
}


// ========================================================================
// ?SetInhibitFlags@idPresentablePlayer@@QAAXW4inhibitFlags_t@idUCmdInhibit@@@Z
// EA  : 0x82B76500
// RVA : 0x00B76500
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetInhibitFlags(idPresentablePlayer *this, idUCmdInhibit::inhibitFlags_t flags)
{
  if ( p_debugInhibitFlags.valueInteger != 0 )
    idUCmdInhibit::DebugPrintInhibitFlagNames(flags);
  this->inhibitFlags = flags;
}


// ========================================================================
// ?AddInhibitFlags@idPresentablePlayer@@QAAXW4inhibitFlags_t@idUCmdInhibit@@@Z
// EA  : 0x82B76560
// RVA : 0x00B76560
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::AddInhibitFlags(idPresentablePlayer *this, idUCmdInhibit::inhibitFlags_t flags)
{
  if ( p_debugInhibitFlags.valueInteger != 0 )
    idUCmdInhibit::DebugPrintInhibitFlagNames(flags);
  this->inhibitFlags |= flags;
}


// ========================================================================
// ?ClearInhibitFlags@idPresentablePlayer@@QAAXW4inhibitFlags_t@idUCmdInhibit@@@Z
// EA  : 0x82B765C8
// RVA : 0x00B765C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClearInhibitFlags(idPresentablePlayer *this, idUCmdInhibit::inhibitFlags_t flags)
{
  if ( p_debugInhibitFlags.valueInteger != 0 )
    idUCmdInhibit::DebugPrintInhibitFlagNames(flags);
  this->inhibitFlags &= ~flags;
}


// ========================================================================
// ?SetRestrictedGamePlay@idPresentablePlayer@@QAAX_N0@Z
// EA  : 0x82B76630
// RVA : 0x00B76630
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetRestrictedGamePlay(
        idPresentablePlayer *this,
        bool restricted,
        const bool canRun)
{
  idPlayerHud *p_playerHud; // r26

  if ( restricted )
  {
    if ( (*((_BYTE *)this + 47033) & 2) == 0 )
    {
      p_playerHud = &this->playerHud;
      idPlayerHud::SetTempHudState(this: &this->playerHud, state: this->playerHud.hudState);
      idPlayerHud::SetHudState(this: p_playerHud, state: HUDSTATE_INFO);
    }
  }
  else if ( (*((_BYTE *)this + 47033) & 2) != 0 )
  {
    idPlayerHud::RestoreHudState(this: &this->playerHud);
  }
  *((_BYTE *)this + 47033) = canRun | (2 * restricted) & 2 | *((_BYTE *)this + 47033) & 0xFC;
  this->playerHud.restrictedGameplay = restricted;
}


// ========================================================================
// ?SetInhibitRaiseWeapon@idPresentablePlayer@@QAAX_N@Z
// EA  : 0x82B766E0
// RVA : 0x00B766E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetInhibitRaiseWeapon(idPresentablePlayer *this, const bool restricted)
{
  idPlayerHud *p_playerHud; // r29

  if ( restricted )
  {
    if ( (*((_BYTE *)this + 47033) & 2) == 0 )
    {
      p_playerHud = &this->playerHud;
      idPlayerHud::SetTempHudState(this: &this->playerHud, state: this->playerHud.hudState);
      idPlayerHud::SetHudState(this: p_playerHud, state: HUDSTATE_INFO);
    }
  }
  else if ( (*((_BYTE *)this + 47033) & 2) != 0 )
  {
    idPlayerHud::RestoreHudState(this: &this->playerHud);
  }
  *((_BYTE *)this + 47034) = (restricted << 7) | *((_BYTE *)this + 47034) & 0x7F;
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_IsInShimmy@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B76780
// RVA : 0x00B76780
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(idPresentablePlayer *this)
{
  idPlayer *entity; // r3

  entity = (idPlayer *)this->entity;
  return entity != nullptr && idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: entity);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_IsInWallClimb@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B76798
// RVA : 0x00B76798
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(idPresentablePlayer *this)
{
  idPlayer *entity; // r3

  entity = (idPlayer *)this->entity;
  return entity != nullptr && idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: entity);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_IsSliding@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B767B0
// RVA : 0x00B767B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::PlayerBehavior_SprintSlide_IsSliding(idPresentablePlayer *this)
{
  idPlayer *entity; // r3

  entity = (idPlayer *)this->entity;
  return entity != nullptr && idPlayer::PlayerBehavior_SprintSlide_IsSliding(this: entity);
}


// ========================================================================
// ?PlayerBehavior_Shared_ShouldHideWeapon@idPresentablePlayer@@QBA_NXZ
// EA  : 0x82B767C8
// RVA : 0x00B767C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::PlayerBehavior_Shared_ShouldHideWeapon(idPresentablePlayer *this)
{
  idPlayer *entity; // r3
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( (*((_BYTE *)this + 47034) & 0x80) != 0 )
    return 1;
  entity = (idPlayer *)this->entity;
  v2 = entity != nullptr && idPlayer::PlayerBehavior_Shared_ShouldHideWeapon(this: entity);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}


// ========================================================================
// ?PlayerBehavior_Lean_GetHandsOffsetScale@idPresentablePlayer@@QBAXAAVidVec2@@@Z
// EA  : 0x82B76830
// RVA : 0x00B76830
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PlayerBehavior_Lean_GetHandsOffsetScale(idPresentablePlayer *this, idVec2 *scale)
{
  idPlayer *entity; // r3

  entity = (idPlayer *)this->entity;
  if ( entity != nullptr )
  {
    idPlayer::PlayerBehavior_Lean_GetHandsOffsetScale(this: entity, scale);
  }
  else
  {
    scale->x = 0.0;
    scale->y = 0.0;
  }
}


// ========================================================================
// ?ExitedVehicle@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B76858
// RVA : 0x00B76858
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ExitedVehicle(idPresentablePlayer *this)
{
  this->vehicleExited.count = (this->vehicleExited.count + 1) % 7;
}


// ========================================================================
// ?ChallengeRestart@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B76898
// RVA : 0x00B76898
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ChallengeRestart(idPresentablePlayer *this)
{
  idLobbyBase *v1; // r3
  int v2; // r3

  this->challengeLocalRestart = false;
  this->challengeRestartingSoon = true;
  this->challengeRemoteRestart = false;
  if ( gameLocal != nullptr && gameLocal->mainMenu != nullptr )
  {
    v1 = session->GetActingGameStateLobbyBase(this: session);
    v2 = (int)v1->GetMatchParms(this: v1);
    idMainMenu::SetMatchMapIndex(this: gameLocal->mainMenu, index: *(_DWORD *)(v2 + 8));
  }
}


// ========================================================================
// ?NoteSwfForBuildGame@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B76950
// RVA : 0x00B76950
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::NoteSwfForBuildGame(idPresentablePlayer *this)
{
  int v2; // r30
  char **p_data; // r31

  this->localView.initialized = true;
  idPlayerHud_Render::Init(this: &this->localView.hudRender, mapName: &clientGame->mapName);
  idPlayerGuis_Render::Init(this: &this->localView.guisRender, mapName: &clientGame->mapName);
  v2 = 21;
  p_data = &this->guiNames[0].data;
  do
  {
    if ( (int)*(p_data - 1) > 0 )
      idSWF::RegisterSWFResources(filename: *p_data);
    --v2;
    p_data += 8;
  }
  while ( v2 != 0 );
}


// ========================================================================
// ?GetPlayerGui@idPresentablePlayer@@QAAPAVidSWF@@W4playerGuis_t@1@@Z
// EA  : 0x82B769E0
// RVA : 0x00B769E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idSWF *__fastcall idPresentablePlayer::GetPlayerGui(idPresentablePlayer *this, idPresentablePlayer::playerGuis_t g)
{
  __int32 v5; // r25
  bool v6; // r26
  idSoundWorld *soundWorld; // r29
  idSWF *v8; // r3
  idSWF *v9; // r3
  idMainMenu *mainMenu; // [sp+50h] [-50h]

  if ( !this->IsLocallyControlled(this) )
    return nullptr;
  v5 = 4 * (g + 12202);
  if ( *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v5) == nullptr )
  {
    v6 = resource_errorInGame.valueInteger != 0;
    idCVar::SetBool(this: &resource_errorInGame, newValue: false, force: true);
    soundWorld = clientGame->soundWorld;
    if ( g == GUI_INVENTORY || g == GUI_TOWTRUCK || g == GUI_TUTORIAL )
    {
      if ( gameLocal != nullptr && (mainMenu = gameLocal->mainMenu) != nullptr )
        soundWorld = mainMenu->soundWorld;
      else
        soundWorld = nullptr;
    }
    v8 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
      v9 = idSWF::idSWF(this: v8, filename_: this->guiNames[g].data, soundWorld, atlasPurgable_: this->purgableGuis[g]);
    else
      v9 = nullptr;
    *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v5) = (idPresentablePlayer_vtbl *)v9;
    idSWF::SetListener(this: v9, id: this->entityNumber + 1);
    idCVar::SetBool(this: &resource_errorInGame, newValue: v6, force: true);
  }
  return *(idSWF **)((char *)&this->__vftable + v5);
}


// ========================================================================
// __unwind$496910
// EA  : 0x82B76B3C
// RVA : 0x00B76B3C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_496910()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?ClearPlayerGui@idPresentablePlayer@@QAA_NW4playerGuis_t@1@@Z
// EA  : 0x82B76B68
// RVA : 0x00B76B68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::ClearPlayerGui(idPresentablePlayer *this, idPresentablePlayer::playerGuis_t g)
{
  __int32 v4; // r29
  void *v5; // r31

  if ( !this->IsLocallyControlled(this) )
    return 0;
  v4 = 4 * (g + 12202);
  v5 = *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v4);
  if ( v5 == nullptr )
    return 0;
  idSWF::~idSWF(this: *(idSWF **)((char *)&this->__vftable + v4));
  idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  *(idPresentablePlayer_vtbl **)((char *)&this->__vftable + v4) = nullptr;
  return 1;
}


// ========================================================================
// ?GuiIsActive@idPresentablePlayer@@QAA_NW4playerGuis_t@1@@Z
// EA  : 0x82B76BE8
// RVA : 0x00B76BE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::GuiIsActive(idPresentablePlayer *this, idPresentablePlayer::playerGuis_t g)
{
  idSWF *v2; // r11
  BOOL result; // r3

  v2 = this->loadedGuis[g];
  result = false;
  if ( v2 != nullptr )
    return v2->isActive;
  return result;
}


// ========================================================================
// ?SetGeneralGameGui@idPresentablePlayer@@QAAXPAVidSWF@@@Z
// EA  : 0x82B76C08
// RVA : 0x00B76C08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetGeneralGameGui(idPresentablePlayer *this, idSWF *gui)
{
  this->loadedGuis[8] = gui;
  if ( gui != nullptr )
    gui->pausedRender = false;
  this->isGeneralGuiCardGame = false;
}


// ========================================================================
// ?DrawSubtitles@idPresentablePlayer@@QAAXPAVidRenderModelGui@@@Z
// EA  : 0x82B76C38
// RVA : 0x00B76C38
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DrawSubtitles(idPresentablePlayer *this, idRenderModelGui *guidModel)
{
  idSWF *v4; // r11
  idSWF *v5; // r11
  idSWF *v6; // r11
  idSWF *v7; // r11
  int GameMs; // r29
  idSWF *PlayerGui; // r3
  const char *v10; // r7

  if ( g_showGuis.valueInteger != 0 && !idMainMenu::IsActive(this: gameLocal->mainMenu) )
  {
    v4 = this->loadedGuis[16];
    if ( v4 != nullptr )
      LOBYTE(v4) = v4->isActive;
    if ( (_BYTE)v4 == 0 )
    {
      v5 = this->loadedGuis[15];
      if ( v5 != nullptr )
        LOBYTE(v5) = v5->isActive;
      if ( (_BYTE)v5 != 0 )
      {
        v6 = this->loadedGuis[9];
        if ( v6 != nullptr )
          LOBYTE(v6) = v6->isActive;
        if ( (_BYTE)v6 == 0 )
        {
          v7 = this->loadedGuis[10];
          if ( v7 != nullptr )
            LOBYTE(v7) = v7->isActive;
          if ( (_BYTE)v7 == 0 )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_SUBTITLE);
            idSWF::Render(this: PlayerGui, gui: guidModel, time: GameMs, isSplitscreen: false, a5: v10);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ToggleShowLegendTitle@idPresentablePlayer@@QAAXAAVidStrId@@@Z
// EA  : 0x82B76D58
// RVA : 0x00B76D58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ToggleShowLegendTitle(idPresentablePlayer *this, idStrId *legendTitle)
{
  this->renderLegendTitle ^= 1u;
  this->coopLegendTitle = (idStrId)legendTitle->index;
}


// ========================================================================
// ?GetLobbyUserID@idPresentablePlayer@@QBA?AUlobbyUserID_t@@XZ
// EA  : 0x82B76D70
// RVA : 0x00B76D70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetLobbyUserID(idPresentablePlayer *this, lobbyUserID_t *result)
{
  idClientGame::GetLobbyUserIdFromPlayerIndex(
    (idClientGame *)this,
    result: (lobbyUserID_t *)clientGame,
    playerIndex: *(_DWORD *)&result[22].lobbyType);
  return this;
}


// ========================================================================
// ?SetLobbyUserID@idPresentablePlayer@@QAAXUlobbyUserID_t@@@Z
// EA  : 0x82B76DB0
// RVA : 0x00B76DB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetLobbyUserID(idPresentablePlayer *this, lobbyUserID_t *value, __int64 a3)
{
  HIDWORD(a3) = value;
  idClientGame::SetLobbyUserIdForPlayerIndex(this: clientGame, lobbyUserID: a3);
}


// ========================================================================
// ?GetName@idPlayerViewCallbacks@@UAAPBDXZ
// EA  : 0x82B76DC8
// RVA : 0x00B76DC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

const char *__fastcall idPlayerViewCallbacks::GetName(idPlayerViewCallbacks *this)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
    return self->model->name.str;
  else
    return "NULL";
}


// ========================================================================
// ?GetViewID@idPlayerViewCallbacks@@UBAHXZ
// EA  : 0x82B76DF0
// RVA : 0x00B76DF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPlayerViewCallbacks::GetViewID(idPlayerViewCallbacks *this)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
    return self->view.gameview.viewID;
  else
    return -1;
}


// ========================================================================
// ?GetPosition@idPlayerViewCallbacks@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B76E10
// RVA : 0x00B76E10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::GetPosition(idPlayerViewCallbacks *this, idVec3 *origin, idMat3 *axis)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
  {
    *origin = self->origin;
    *axis = this->self->axis;
  }
  else
  {
    *origin = vec3_origin;
    *axis = mat3_identity;
  }
}


// ========================================================================
// ?GetViewPosition@idPlayerViewCallbacks@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B76F00
// RVA : 0x00B76F00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::GetViewPosition(idPlayerViewCallbacks *this, idVec3 *origin, idMat3 *axis)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
  {
    idView::GetViewPos(this: &self->view, origin, axis);
  }
  else
  {
    *origin = vec3_origin;
    *axis = mat3_identity;
  }
}


// ========================================================================
// ?ApplyScreenShake@idPlayerViewCallbacks@@UAAXMABVidAngles@@ABVidVec3@@@Z
// EA  : 0x82B76F88
// RVA : 0x00B76F88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::ApplyScreenShake(
        idPlayerViewCallbacks *this,
        double shakeMag,
        const idAngles *shakeAngles,
        const idVec3 *shakeOffsets)
{
  idPresentablePlayer *self; // r11
  double v5; // fp0

  self = this->self;
  if ( self != nullptr )
  {
    v5 = 0.0;
    if ( shakeMag >= 0.0 )
    {
      v5 = 1.0;
      if ( shakeMag <= 1.0 )
        v5 = shakeMag;
    }
    self->view.cameraShake = v5;
  }
}


// ========================================================================
// ?ApplyControllerShake@idPlayerViewCallbacks@@UAAXMMMM@Z
// EA  : 0x82B76FC0
// RVA : 0x00B76FC0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::ApplyControllerShake(
        idPlayerViewCallbacks *this,
        double highDuration,
        double lowDuration,
        double highMag,
        double lowMag,
        int a6)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
    idView::SetControllerShake(
      this: &self->view,
      highMagnitude: highMag,
      highDuration: a6,
      lowMagnitude: lowMag,
      lowDuration: (int)highDuration);
}


// ========================================================================
// ?ApplyDynEnvOverride@idPlayerViewCallbacks@@UAAXPBVidDeclEnv@@M@Z
// EA  : 0x82B77018
// RVA : 0x00B77018
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::ApplyDynEnvOverride(
        idPlayerViewCallbacks *this,
        const idDeclEnv *declEnv,
        double blendDuration,
        int a4)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
    idView::SetEnvironmentOverride(this: &self->view, env: declEnv, blendDuration, modelIndex: a4);
}


// ========================================================================
// ?ApplyDynEnvParmOverride@idPlayerViewCallbacks@@UAAXPBVidDeclRenderParm@@ABVidVec4@@_NM@Z
// EA  : 0x82B77038
// RVA : 0x00B77038
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::ApplyDynEnvParmOverride(
        idPlayerViewCallbacks *this,
        const idDeclRenderParm *parm,
        const idVec4 *val,
        const bool clearParm,
        double blendDuration)
{
  idPresentablePlayer *self; // r11
  idView *p_view; // r3

  self = this->self;
  if ( self != nullptr )
  {
    p_view = &self->view;
    if ( clearParm )
      idView::ClearEnvironmentParm(this: p_view, parm, blendDuration);
    else
      idView::SetEnvironmentParm(this: p_view, parm, val, blendDuration);
  }
}


// ========================================================================
// ?ApplyRadialBlur@idPlayerViewCallbacks@@UAAXABVidVec3@@MMMMM@Z
// EA  : 0x82B77060
// RVA : 0x00B77060
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::ApplyRadialBlur(
        idPlayerViewCallbacks *this,
        const idVec3 *pos,
        double startTime,
        double duration,
        double minBlur,
        double maxBlur,
        double maxScale)
{
  idPresentablePlayer *self; // r11

  self = this->self;
  if ( self != nullptr )
    idView::AddRadialBlur(this: &self->view, centerPos: pos, startTime, duration, minBlur, maxBlur, maxScale);
}


// ========================================================================
// ?AddScreenParticle@idPlayerViewCallbacks@@UAAHPAVidRenderModel@@M@Z
// EA  : 0x82B77078
// RVA : 0x00B77078
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPlayerViewCallbacks::AddScreenParticle(
        idPlayerViewCallbacks *this,
        idRenderModel *prtModel,
        double excludeAngle)
{
  idPresentablePlayer *self; // r3

  self = this->self;
  if ( self != nullptr )
    return idPresentablePlayer::StartFxScreenParticle(this: self, prtModel, excludeAngle);
  else
    return -1;
}


// ========================================================================
// ?RemoveScreenParticle@idPlayerViewCallbacks@@UAAXHH@Z
// EA  : 0x82B77090
// RVA : 0x00B77090
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPlayerViewCallbacks::RemoveScreenParticle(
        idPlayerViewCallbacks *this,
        unsigned int handle,
        int fadeTime)
{
  idPresentablePlayer *self; // r3

  self = this->self;
  if ( self != nullptr )
    idPresentablePlayer::StopFxScreenParticle(this: self, handle, fadeTime);
}


// ========================================================================
// ?p_clearInhibitFlags_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B772A0
// RVA : 0x00B772A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall p_clearInhibitFlags_f(const idCmdArgs *args)
{
  int v1; // r30
  const char *v2; // r3
  idPresentablePlayer *PlayerPresentableByIndex; // r31
  _BYTE *v4; // r30
  char v5; // r6

  if ( args->argc == 1 )
  {
    v1 = 0;
  }
  else
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v1 = atol(nptr: v2);
  }
  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: v1);
  if ( PlayerPresentableByIndex != nullptr )
  {
    idLib::Printf(fmt: "Clearing the following flags on player #%d \n", v1);
    idUCmdInhibit::DebugPrintInhibitFlagNames(flags: PlayerPresentableByIndex->inhibitFlags);
    idPresentablePlayer::ClearInhibitFlags(
      this: PlayerPresentableByIndex,
      flags: PlayerPresentableByIndex->inhibitFlags);
    if ( (*((_BYTE *)PlayerPresentableByIndex + 47033) & 2) != 0 )
    {
      idLib::Printf(fmt: "Clearing restricted Gameplay \n");
      idPresentablePlayer::SetRestrictedGamePlay(this: PlayerPresentableByIndex, restricted: false, canRun: false);
    }
    if ( !PlayerPresentableByIndex->playerHud.allowWeaponChange
      || (v4 = (char *)PlayerPresentableByIndex + 47034, (*((_BYTE *)PlayerPresentableByIndex + 47034) & 0x40) != 0) )
    {
      v5 = *((_BYTE *)PlayerPresentableByIndex + 47034);
      PlayerPresentableByIndex->playerHud.allowWeaponChange = true;
      v4 = (char *)PlayerPresentableByIndex + 47034;
      *((_BYTE *)PlayerPresentableByIndex + 47034) = v5 & 0xBF;
      idLib::Printf(fmt: "Removing weaponchange block\n");
    }
    if ( (*v4 & 0x80) != 0 )
    {
      idPresentablePlayer::SetInhibitRaiseWeapon(this: PlayerPresentableByIndex, restricted: false);
      idLib::Printf(fmt: "Removed raise weapon block\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Could not print inhibit flags: #%d not a valid player \n", v1);
  }
}


// ========================================================================
// ?GetOffset@idWeaponKick@@QBAMXZ
// EA  : 0x82B77408
// RVA : 0x00B77408
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

float __fastcall idWeaponKick::GetOffset(idWeaponKick *this)
{
  __int64 v2; // r11
  __int64 v3; // r11
  double CurrentValue; // fp1
  __int64 v5; // r11

  LODWORD(v2) = idClientGame::GetPlayerGameTime(this: clientGame);
  if ( (float)v2 < (double)(float)(this->recoilOffset.duration + this->recoilOffset.startTime) )
  {
    LODWORD(v5) = idClientGame::GetPlayerGameTime(this: clientGame);
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->recoilOffset, time: (float)v5);
  }
  else
  {
    LODWORD(v3) = idClientGame::GetPlayerGameTime(this: clientGame);
    CurrentValue = idInterpolate<float>::GetCurrentValueEaseOut(this: &this->recoveryOffset, time: (float)v3);
  }
  return *((float *)&CurrentValue + 1);
}


// ========================================================================
// ?Init@idWeaponKick@@QAAXABM000_N1M@Z
// EA  : 0x82B774C8
// RVA : 0x00B774C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idWeaponKick::Init(
        idWeaponKick *this,
        const float *kick,
        const float *maxKick,
        const float *inSpeed,
        const float *outSpeed,
        __int64 additiveKick,
        double recoveryDelay)
{
  char v12; // r29
  unsigned int v13; // r3
  double v14; // fp0
  double v15; // fp0
  double v16; // fp29
  double Offset; // fp1
  double v18; // fp0
  double v19; // fp30
  double v20; // fp31
  double v21; // fp13
  double v22; // fp25
  __int64 v23; // r10
  double v24; // fp30
  __int64 v25; // r9

  v12 = additiveKick;
  if ( *kick > 0.0 )
  {
    v13 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v13;
    LODWORD(additiveKick) = (v13 >> 10) & 0x7FFF;
    if ( BYTE3(additiveKick) != 0 )
    {
      v14 = 0.5;
      if ( (float)((float)((float)additiveKick * (float)0.000030518509) - 0.5) <= 0.0 )
        v14 = -0.5;
      v15 = (float)((float)v14 + (float)((float)((float)additiveKick * (float)0.000030518509) - 0.5));
    }
    else
    {
      v15 = (float)-(float)((float)((float)additiveKick * (float)0.000015259255) + 0.5);
    }
    v16 = (float)((float)v15 * *kick);
    Offset = idWeaponKick::GetOffset(this);
    v18 = *maxKick;
    v19 = Offset;
    if ( v12 != 0 )
    {
      v20 = (float)((float)((float)-(float)((float)((float)((float)-(float)((float)((float)((float)Offset / *maxKick)
                                                                                  * (float)2.0)
                                                                          - (float)3.0)
                                                          * (float)((float)Offset / *maxKick))
                                                  * (float)((float)Offset / *maxKick))
                                          - (float)1.0)
                          * (float)v16)
                  + (float)Offset);
    }
    else
    {
      v21 = (float)((float)Offset + (float)v16);
      v20 = -v18;
      if ( v21 >= -v18 )
      {
        if ( v21 <= v18 )
          v20 = (float)((float)Offset + (float)v16);
        else
          v20 = *maxKick;
      }
    }
    v22 = (float)((float)((float)__fabs((float)((float)v20 - (float)Offset)) * (float)1000.0) / *inSpeed);
    LODWORD(v23) = idClientGame::GetPlayerGameTime(this: clientGame);
    this->recoilOffset.startValue = v19;
    this->recoilOffset.currentValue = v19;
    this->recoilOffset.duration = v22;
    this->recoilOffset.endValue = v20;
    this->recoilOffset.startTime = (float)v23;
    this->recoilOffset.currentTime = (float)v23 - (float)1.0;
    v24 = (float)((float)((float)__fabs(v20) * (float)1000.0) / *outSpeed);
    LODWORD(v25) = idClientGame::GetPlayerGameTime(this: clientGame);
    this->recoveryOffset.duration = v24;
    this->recoveryOffset.startValue = v20;
    this->recoveryOffset.endValue = 0.0;
    this->recoveryOffset.currentValue = v20;
    this->recoveryOffset.startTime = (float)((float)v25 + (float)v22) + (float)recoveryDelay;
    this->recoveryOffset.currentTime = (float)((float)((float)v25 + (float)v22) + (float)recoveryDelay) - (float)1.0;
  }
}


// ========================================================================
// ?Serialize@idPresentableActor@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B776D0
// RVA : 0x00B776D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::Serialize(idPresentableActor *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  idPresentableAnimatedEntity::Serialize(this, ser);
  this->actorModifierManager->Serialize(this: this->actorModifierManager, a2: ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(this->overdrivePoints), numBits: 32);
  else
    LODWORD(this->overdrivePoints) = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?InitForClient@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B77758
// RVA : 0x00B77758
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InitForClient(idPresentablePlayer *this)
{
  const idDeclAnimWeb *v2; // r29
  const idDeclAnimWeb *v3; // r6
  idPresentableAnimatedEntity *presentable; // r11

  if ( idPresentablePlayer::HANDS_ANIMWEB_NAME != nullptr )
    v2 = (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclAnimWeb::resourceList,
                                  name: idPresentablePlayer::HANDS_ANIMWEB_NAME,
                                  makeDefault: true);
  else
    v2 = nullptr;
  if ( idPresentablePlayer::HANDS_SECONDARY_ANIMWEB_NAME != nullptr )
    v3 = (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclAnimWeb::resourceList,
                                  name: idPresentablePlayer::HANDS_SECONDARY_ANIMWEB_NAME,
                                  makeDefault: true);
  else
    v3 = nullptr;
  idPresentablePlayer::Init(
    this,
    handsDeclMD6: (const idDeclMD6 *)this->entity[15].listenerList,
    handsDeclAnimWeb: v2,
    handsDeclSecondaryAnimWeb: v3,
    handsFX: nullptr);
  presentable = this->hands.presentable;
  if ( presentable != nullptr )
    presentable->model->g.allowSurfaceOnlyInViewID = this->entityNumber + 1;
  if ( this->IsLocallyControlled(this) && this->index < 12288 )
  {
    idHands::Show(this: &this->hands, hideReason: HAND_HIDE_GENERIC);
    idHands::Enable(this: &this->hands);
  }
  else
  {
    idHands::Hide(this: &this->hands, hideReason: HAND_HIDE_GENERIC);
  }
  if ( this->IsLocallyControlled(this) && idPresentablePlayer::SelectBestWeapon(this) == nullptr )
    idPresentablePlayer::SelectFists(this, deleteCurrentWeapon: false);
}


// ========================================================================
// ?SerializeHud@idPresentablePlayer@@QAAXAAVidSerializer@@AAVidHudInfo@@@Z
// EA  : 0x82B778A0
// RVA : 0x00B778A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SerializeHud(idPresentablePlayer *this, idSerializer *ser, idHudInfo *hudInfo)
{
  idBitMsg *msg; // r3
  int *v6; // r30
  int i; // r28
  char v8; // r31
  idBitMsg *v9; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(hudInfo->healthIndicator.armor), numBits: 32);
  else
    LODWORD(hudInfo->healthIndicator.armor) = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = &hudInfo->combiners.staticList[2].itemState[4];
  for ( i = 4; i != 0; --i )
  {
    v8 = *((_BYTE *)v6 + 24);
    v9 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v9, value: *((unsigned __int8 *)v6 + 24), numBits: 1);
    else
      v8 = (_cntlzw(idBitMsg::ReadBits(this: v9, numBits: 1) - 1) & 0x20) != 0;
    v6 += 6;
    *(_BYTE *)v6 = v8;
  }
}


// ========================================================================
// ?PostSerializeRead@idPresentablePlayer@@UAAX_N@Z
// EA  : 0x82B77940
// RVA : 0x00B77940
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PostSerializeRead(idPresentablePlayer *this, BOOL firstClientFrame)
{
  int count; // r10
  char v5; // r30
  void (__fastcall *RestoreStateFromState)(idPhysics_Player *, playerPState_t *); // r5
  __int64 v7; // r10
  int v8; // r7
  __int64 v9; // r6
  __int64 v10; // r10
  int v11; // r7
  __int64 v12; // r6
  int v13; // r10
  char v14; // r11
  int v15; // r10
  char v16; // r11
  int roverBombSoundCounter; // r10
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  _BYTE v19[240]; // [sp+60h] [-F0h] BYREF

  idPresentableAnimatedEntity::PostSerializeRead(this, firstClientFrame);
  this->actorModifierManager->PostSerializeRead(this: this->actorModifierManager, a2: firstClientFrame);
  idInventoryCollection::PostSerializeRead(this: this->activeInventory, owner: this);
  count = this->teleported.count;
  if ( count == this->teleported.lastCount )
  {
    v5 = 0;
  }
  else
  {
    this->teleported.lastCount = count;
    v5 = 1;
  }
  if ( this->IsLocallyControlled(this) && (this->firstPredictionSerialize || v5 != 0) )
  {
    this->serializedState.deltaViewAngles.pitch = ang_zero.pitch;
    this->serializedState.deltaViewAngles.yaw = ang_zero.yaw;
    RestoreStateFromState = this->physicsObj.RestoreStateFromState;
    this->serializedState.deltaViewAngles.roll = ang_zero.roll;
    RestoreStateFromState(this: &this->physicsObj, a2: &this->serializedState);
    this->physicsObj.SetOrigin(this: &this->physicsObj, a2: &this->serializedState.worldOrigin, a3: -1);
    idUCmdTracker::SetViewAngles(this: &this->ucmdTracker1, angles: v9, a3: v8, a4: v7);
    idUCmdTracker::SetViewAngles(this: &this->ucmdTracker2, angles: v12, a3: v11, a4: v10);
  }
  if ( v5 != 0 )
  {
    this->origins[0].x = this->origins[1].x;
    this->origins[0].y = this->origins[1].y;
    this->origins[0].z = this->origins[1].z;
  }
  v13 = this->respawn.count;
  if ( v13 == this->respawn.lastCount )
  {
    v14 = 0;
  }
  else
  {
    this->respawn.lastCount = v13;
    v14 = 1;
  }
  if ( v14 != 0 )
  {
    idPresentablePlayer::PresentableRespawn(this, initial: false);
    this->origins[0].x = this->origins[1].x;
    this->origins[0].y = this->origins[1].y;
    this->origins[0].z = this->origins[1].z;
  }
  v15 = this->vehicleExited.count;
  if ( v15 == this->vehicleExited.lastCount )
  {
    v16 = 0;
  }
  else
  {
    this->vehicleExited.lastCount = v15;
    v16 = 1;
  }
  if ( v16 != 0 && this->IsLocallyControlled(this) )
  {
    this->view.cameraShake = 0.0;
    idView::ResetControllerShake(this: &this->view);
  }
  if ( this->IsLocallyControlled(this) )
  {
    roverBombSoundCounter = this->roverBombSoundCounter;
    if ( roverBombSoundCounter > this->localRoverBombSoundCounter )
    {
      this->localRoverBombSoundCounter = roverBombSoundCounter;
      if ( idPresentablePlayer::GetPlayerSounds(
             this: (idPresentablePlayer *)v19,
             result: (const idDeclPlayerProps::playerSounds_t *)this)->sndMPRoverBombSelfDestruct != nullptr )
      {
        PlayerSounds = idPresentablePlayer::GetPlayerSounds(
                         this: (idPresentablePlayer *)v19,
                         result: (const idDeclPlayerProps::playerSounds_t *)this);
        idPresentablePlayer::PlayLocalSound(
          this,
          channel: SND_CHANNEL_ANY,
          shader: PlayerSounds->sndMPRoverBombSelfDestruct,
          soundShaderFlags: 0);
      }
    }
  }
}


// ========================================================================
// ?HudThink@idPresentablePlayer@@UAAXXZ
// EA  : 0x82B77BD8
// RVA : 0x00B77BD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::HudThink(idPresentablePlayer *this)
{
  debugHud_x = sDebugHud_x0;
  debugHud_y = sDebugHud_y0;
  idPresentablePlayer::UpdateScoringCallout(this);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->localView.hudRender);
}


// ========================================================================
// ?IsLocallyControlled@idPresentablePlayer@@UBA_NXZ
// EA  : 0x82B77C28
// RVA : 0x00B77C28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::IsLocallyControlled(idPresentablePlayer *this)
{
  char v2; // r11
  int entityNumber; // r4
  int v5; // [sp+50h] [-20h] BYREF
  unsigned __int8 v6; // [sp+54h] [-1Ch]

  idClientGame::GetLobbyUserIdFromPlayerIndex(
    this: (idClientGame *)&v5,
    result: (lobbyUserID_t *)clientGame,
    playerIndex: this->entityNumber);
  if ( v5 == 0 || (v2 = 1, v6 == 255) )
    v2 = 0;
  if ( v2 == 0 )
    return false;
  entityNumber = this->entityNumber;
  return entityNumber != -1
      && this->index < 12288
      && (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: clientGame, playerNum: entityNumber) != 0;
}


// ========================================================================
// ??0idUCmdTracker@@QAA@XZ
// EA  : 0x82B77CD0
// RVA : 0x00B77CD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idUCmdTracker *__fastcall idUCmdTracker::idUCmdTracker(idUCmdTracker *this)
{
  char v2; // r9
  char v3; // r7
  char v4; // r5

  this->lastPlayerInputTime = 0;
  this->prevcmd.buttons = 0;
  this->prevcmd.buttons2 = 0;
  this->prevcmd.forwardmove = 0;
  this->prevcmd.rightmove = 0;
  this->prevcmd.pos[2] = 0.0;
  this->prevcmd.upmove = 0;
  this->prevcmd.pos[1] = 0.0;
  this->prevcmd.angles[2] = 0;
  this->prevcmd.pos[0] = 0.0;
  this->prevcmd.angles[1] = 0;
  this->prevcmd.angles[0] = 0;
  this->prevcmd.clientGameFrame = 0;
  this->prevcmd.yaw = 0;
  this->prevcmd.pitch = 0;
  this->prevcmd.roll = 0;
  this->prevcmd.predictionStateBits = 0;
  this->prevcmd.vehicleThrottle = 0;
  this->prevcmd.serverGameTime = 0;
  this->prevcmd.fireCount = 0;
  this->prevcmd.fireAngles[1] = 0;
  this->prevcmd.fireAngles[0] = 0;
  this->prevcmd.firePos[2] = 0;
  v2 = *((_BYTE *)&this->prevcmd + 9);
  this->prevcmd.firePos[1] = 0;
  this->prevcmd.firePos[0] = 0;
  this->prevcmd.speed = 0;
  *((_BYTE *)&this->prevcmd + 9) = v2 & 0x3F;
  this->usercmd.pos[2] = 0.0;
  this->usercmd.pos[1] = 0.0;
  this->usercmd.buttons = 0;
  this->usercmd.pos[0] = 0.0;
  this->usercmd.buttons2 = 0;
  this->usercmd.forwardmove = 0;
  this->usercmd.rightmove = 0;
  this->usercmd.upmove = 0;
  this->usercmd.angles[2] = 0;
  this->usercmd.angles[1] = 0;
  this->usercmd.angles[0] = 0;
  this->usercmd.clientGameFrame = 0;
  this->usercmd.yaw = 0;
  this->usercmd.pitch = 0;
  this->usercmd.roll = 0;
  this->usercmd.predictionStateBits = 0;
  this->usercmd.vehicleThrottle = 0;
  this->usercmd.serverGameTime = 0;
  this->usercmd.fireCount = 0;
  this->usercmd.fireAngles[1] = 0;
  this->usercmd.fireAngles[0] = 0;
  this->usercmd.firePos[2] = 0;
  v3 = *((_BYTE *)&this->usercmd + 9);
  this->usercmd.firePos[1] = 0;
  this->usercmd.firePos[0] = 0;
  this->usercmd.speed = 0;
  *((_BYTE *)&this->usercmd + 9) = v3 & 0x3F;
  this->usercmdRaw.pos[2] = 0.0;
  this->usercmdRaw.pos[1] = 0.0;
  this->usercmdRaw.buttons = 0;
  this->usercmdRaw.pos[0] = 0.0;
  this->usercmdRaw.buttons2 = 0;
  this->usercmdRaw.forwardmove = 0;
  this->usercmdRaw.rightmove = 0;
  this->usercmdRaw.upmove = 0;
  this->usercmdRaw.angles[2] = 0;
  this->usercmdRaw.angles[1] = 0;
  this->usercmdRaw.angles[0] = 0;
  this->usercmdRaw.clientGameFrame = 0;
  this->usercmdRaw.yaw = 0;
  this->usercmdRaw.pitch = 0;
  this->usercmdRaw.roll = 0;
  this->usercmdRaw.predictionStateBits = 0;
  this->usercmdRaw.vehicleThrottle = 0;
  v4 = *((_BYTE *)&this->usercmdRaw + 9);
  this->usercmdRaw.serverGameTime = 0;
  this->usercmdRaw.fireCount = 0;
  this->usercmdRaw.fireAngles[1] = 0;
  this->usercmdRaw.fireAngles[0] = 0;
  this->usercmdRaw.firePos[2] = 0;
  *((_BYTE *)&this->usercmdRaw + 9) = v4 & 0x3F;
  this->usercmdRaw.firePos[1] = 0;
  this->usercmdRaw.firePos[0] = 0;
  this->usercmdRaw.speed = 0;
  this->clearViewDeltaNextUpdate = false;
  idUCmdTracker::ClearAngles(this);
  this->lastPlayerInputAngles[1] = 0;
  this->lastPlayerInputAngles[0] = 0;
  return this;
}


// ========================================================================
// ?SetViewAnglesConstraint@idPresentablePlayer@@QAAX_NABVidAngles@@1M@Z
// EA  : 0x82B77E80
// RVA : 0x00B77E80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetViewAnglesConstraint(
        idPresentablePlayer *this,
        bool constrain,
        const idAngles *minAngles,
        const idAngles *maxAngles,
        double rate)
{
  idUCmdTracker::SetViewAnglesConstraintExplicit(
    this: &this->ucmdTracker1,
    constrain,
    baseAngles: minAngles,
    minDeltaAngles: maxAngles,
    maxDeltaAngles: maxAngles,
    rate);
}


// ========================================================================
// ?IsPressedForPlayer@idUCmdTracker@@QBA_NH@Z
// EA  : 0x82B77E90
// RVA : 0x00B77E90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idUCmdTracker::IsPressedForPlayer(idUCmdTracker *this, int mask)
{
  int buttons; // r11

  buttons = 0;
  if ( (*((_BYTE *)&this->usercmd + 9) & 0x80) == 0 )
    buttons = this->usercmd.buttons;
  return (buttons & mask) != 0;
}


// ========================================================================
// ?WasReleasedForPlayer@idUCmdTracker@@QBA_NH@Z
// EA  : 0x82B77EB8
// RVA : 0x00B77EB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idUCmdTracker::WasReleasedForPlayer(idUCmdTracker *this, int mask)
{
  int buttons; // r11
  int v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  buttons = 0;
  if ( (*((_BYTE *)&this->usercmd + 9) & 0x80) == 0 )
    buttons = this->usercmd.buttons;
  if ( (buttons & mask) != 0 )
    return 0;
  v3 = 0;
  if ( (*((_BYTE *)&this->prevcmd + 9) & 0x80) == 0 )
    v3 = this->prevcmd.buttons;
  v5 = (v3 & mask) != 0;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}


// ========================================================================
// ?WasPressedForPlayer@idUCmdTracker@@QBA_NH@Z
// EA  : 0x82B77F10
// RVA : 0x00B77F10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idUCmdTracker::WasPressedForPlayer(idUCmdTracker *this, int mask)
{
  int buttons; // r11
  int v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  buttons = 0;
  if ( (*((_BYTE *)&this->usercmd + 9) & 0x80) == 0 )
    buttons = this->usercmd.buttons;
  if ( (buttons & mask) == 0 )
    return 0;
  v3 = 0;
  if ( (*((_BYTE *)&this->prevcmd + 9) & 0x80) == 0 )
    v3 = this->prevcmd.buttons;
  v5 = (v3 & mask) == 0;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}


// ========================================================================
// ?IsPressedForMenu@idUCmdTracker@@QBA_NH@Z
// EA  : 0x82B77F68
// RVA : 0x00B77F68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idUCmdTracker::IsPressedForMenu(idUCmdTracker *this, int mask)
{
  return (this->usercmd.buttons & mask) != 0;
}


// ========================================================================
// ?WasReleasedForMenu@idUCmdTracker@@QBA_NH@Z
// EA  : 0x82B77F88
// RVA : 0x00B77F88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idUCmdTracker::WasReleasedForMenu(idUCmdTracker *this, int mask)
{
  unsigned __int8 v2; // r11

  if ( (this->usercmd.buttons & mask) != 0 )
    return 0;
  v2 = 1;
  if ( (this->prevcmd.buttons & mask) == 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?InventoryAdded@idPresentablePlayer@@UAAXPAVidInventoryItem@@H_N@Z
// EA  : 0x82B77FD8
// RVA : 0x00B77FD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InventoryAdded(
        idPresentablePlayer *this,
        idWeapon *item,
        int count,
        bool canIntro)
{
  const idDeclInventory *decl; // r27
  const char *CallEvent; // r4
  idPlayer *entity; // r3
  bool v10; // r30
  idWeapon *v11; // r3
  idDeclInventory *v12; // r11
  idStrId *v13; // r4
  idWeapon *v14; // r27
  int itemUse; // r28
  bool specialItem; // r25
  idStrId *DisplayName; // r3
  idInventoryItem v18[2]; // [sp+50h] [-70h] BYREF

  if ( this->entity != nullptr && common->IsServer(this: common) )
    this->entity->InventoryAdded(this: this->entity, a2: item, a3: count);
  if ( this->IsLocallyControlled(this) )
  {
    decl = item->decl;
    if ( !decl->noPickupMessage )
    {
      v18[0].__vftable = (idInventoryItem_vtbl *)decl->icon;
      if ( v18[0].__vftable != nullptr )
        CallEvent = (const char *)v18[0].CallEvent;
      else
        CallEvent = &byte_8200D768;
      idStr::idStr(this: (idStr *)&v18[0].count, text: CallEvent);
      entity = (idPlayer *)this->entity;
      v10 = false;
      if ( entity != nullptr )
        v10 = idPlayer::CheckIsNewItem(this: entity, decl);
      v11 = idWeapon::CastTo(c: item);
      v12 = (idDeclInventory *)item->decl;
      v13 = (idStrId *)item;
      v14 = v11;
      itemUse = v12->itemUse;
      specialItem = v12->specialItem;
      v18[0].__vftable = (idInventoryItem_vtbl *)v12;
      DisplayName = idInventoryItem::GetDisplayName(this: v18, result: v13);
      idPlayerHud::PickUp(
        this: &this->playerHud,
        icon: (const idStr *)&v18[0].count,
        isWeapon: v14 != nullptr,
        count,
        special: specialItem,
        displayName: DisplayName,
        itemType: itemUse,
        newItem: v10);
      idStr::FreeData(this: (idStr *)&v18[0].count);
    }
  }
}


// ========================================================================
// __unwind$499741
// EA  : 0x82B7811C
// RVA : 0x00B7811C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_499741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?ApplyDamageToPresentable@idPresentablePlayer@@QAAXPAVidPresentable@@PBVidDeclDamage@@MVidVec3@@2H@Z
// EA  : 0x82B78148
// RVA : 0x00B78148
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ApplyDamageToPresentable(
        idPresentablePlayer *this,
        idPresentable *_attacker,
        const idDeclDamage *_damageDef,
        double _damage,
        idVec3 *dir,
        idVec3 *kick,
        __int64 timer,
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
        int a27,
        int a28)
{
  int *p_damageFeedbackBufferPos; // r10
  unsigned int spawnId; // r8
  idVec3 *p_impactDir; // r9
  idVec3 *p_impactKick; // r9
  float v33; // [sp+48h] [+48h]

  v33 = *((float *)&timer + 1);
  p_damageFeedbackBufferPos = &this->damageFeedbackBufferPos;
  spawnId = 0;
  if ( _attacker != nullptr )
    spawnId = _attacker->spawnId;
  this->damageFeedback[this->damageFeedbackBufferPos % 10].attacker.spawnId = spawnId;
  this->damageFeedback[*p_damageFeedbackBufferPos % 10].damageDef = _damageDef;
  this->damageFeedback[this->damageFeedbackBufferPos % 10].damage = _damage;
  p_impactDir = &this->damageFeedback[*p_damageFeedbackBufferPos % 10].impactDir;
  p_impactDir->x = *(float *)&dir;
  p_impactDir->y = *(float *)&kick;
  p_impactDir->z = *(float *)&kick;
  p_impactKick = &this->damageFeedback[*p_damageFeedbackBufferPos % 10].impactKick;
  *(_QWORD *)&p_impactKick->x = timer;
  p_impactKick->z = v33;
  this->damageFeedback[*p_damageFeedbackBufferPos % 10].impactOverrideTimer = a28;
  ++*p_damageFeedbackBufferPos;
}


// ========================================================================
// `idPresentablePlayer::ShowTutorialGui'::`32'::idSWFScriptFunction_waitInput::idSWFScriptFunction_waitInput
// EA  : 0x82B78328
// RVA : 0x00B78328
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall _idPresentablePlayer::ShowTutorialGui_::_32_::idSWFScriptFunction_waitInput::idSWFScriptFunction_waitInput(
        const idDeclTutorialEvent *_decl,
        idSWF *_gui,
        idResource *_activatingEntity,
        idResourceList *_player,
        idStr *_actionCheck,
        idStr *a6)
{
  idStr *p_networkID; // r3
  size_t len; // r29

  _decl->trackedMemory = 0;
  _decl->__vftable = (idDeclTutorialEvent_vtbl *)&`idPresentablePlayer::ShowTutorialGui'::`32'::idSWFScriptFunction_waitInput::`vftable';
  *((_DWORD *)&_decl->idResource + 8) = 20;
  p_networkID = (idStr *)&_decl->networkID;
  _decl->staleCount = (int)p_networkID->baseBuffer;
  _decl->networkID = 0;
  HIBYTE(_decl->textSource) = 0;
  _decl->name.str = (const char *)_gui;
  _decl->nextOnHashChain = _activatingEntity;
  _decl->resourceListPtr = _player;
  _decl->resourceError = (const char *)_actionCheck;
  len = a6->len;
  idStr::EnsureAlloced(this: p_networkID, amount: a6->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: (void *)_decl->staleCount, Src: a6->data, Size: len);
  *(_BYTE *)(_decl->staleCount + len) = 0;
  _decl->networkID = len;
  idStr::FreeData(this: a6);
}


// ========================================================================
// __unwind$500013_0
// EA  : 0x82B783D8
// RVA : 0x00B783D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_500013_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 204));
}


// ========================================================================
// __unwind$500014
// EA  : 0x82B78400
// RVA : 0x00B78400
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_500014()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$500015
// EA  : 0x82B78428
// RVA : 0x00B78428
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_500015()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// ?HideTutorialGui@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B78538
// RVA : 0x00B78538
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::HideTutorialGui(idPresentablePlayer *this)
{
  idSWF *PlayerGui; // r3

  PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_TUTORIAL);
  if ( PlayerGui != nullptr && PlayerGui->isActive )
  {
    idSWF::Activate(this: PlayerGui, b: false);
    this->currentTutorialGuiDecl = nullptr;
  }
}


// ========================================================================
// ?HideSpecificTutorialGui@idPresentablePlayer@@QAAXPBVidDeclTutorialEvent@@@Z
// EA  : 0x82B78598
// RVA : 0x00B78598
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::HideSpecificTutorialGui(
        idPresentablePlayer *this,
        const idDeclTutorialEvent *decl)
{
  idSWF *PlayerGui; // r3
  const idDeclTutorialEvent **p_currentTutorialGuiDecl; // r31

  PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_TUTORIAL);
  if ( PlayerGui != nullptr && PlayerGui->isActive )
  {
    p_currentTutorialGuiDecl = &this->currentTutorialGuiDecl;
    if ( *p_currentTutorialGuiDecl == decl )
    {
      idSWF::Activate(this: PlayerGui, b: false);
      *p_currentTutorialGuiDecl = nullptr;
    }
  }
}


// ========================================================================
// ?DeactivateGuis@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B78610
// RVA : 0x00B78610
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DeactivateGuis(idPresentablePlayer *this)
{
  idPresentablePlayer::playerGuis_t v2; // r31
  idSWF **loadedGuis; // r30
  idSWF *v4; // r11
  idSWF *PlayerGui; // r3

  if ( this->IsLocallyControlled(this) )
  {
    v2 = GUI_DELIVERY;
    loadedGuis = this->loadedGuis;
    do
    {
      if ( v2 != GUI_SUBTITLE )
      {
        v4 = *loadedGuis;
        if ( *loadedGuis != nullptr )
          LOBYTE(v4) = v4->isActive;
        if ( (_BYTE)v4 != 0 )
        {
          PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: v2);
          idSWF::Activate(this: PlayerGui, b: false);
        }
      }
      ++v2;
      ++loadedGuis;
    }
    while ( v2 < (GUI_TUTORIAL|GUI_JOBOFFER) );
  }
}


// ========================================================================
// ?PostAlloc@idPresentableActor@@UAAXXZ
// EA  : 0x82B78B30
// RVA : 0x00B78B30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentableActor::PostAlloc(idPresentableActor *this)
{
  unsigned int spawnId; // r11

  spawnId = 0;
  if ( this != nullptr )
    spawnId = this->spawnId;
  this->predictedActorModifierManager.parent.spawnId = spawnId;
}


// ========================================================================
// ?GetControl@idPresentablePlayer@@QBAPAVidPresentable@@XZ
// EA  : 0x82B78BD0
// RVA : 0x00B78BD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentable *__fastcall idPresentablePlayer::GetControl(idPresentablePlayer *this)
{
  int num; // r11

  num = this->controlledPresentables.num;
  if ( num <= 0 )
    return nullptr;
  else
    return idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]);
}


// ========================================================================
// ?GetVehicle@idPresentablePlayer@@QBAPAVidPresentableVehicle@@XZ
// EA  : 0x82B78C08
// RVA : 0x00B78C08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentableVehicle *__fastcall idPresentablePlayer::GetVehicle(idPresentablePlayer *this)
{
  int *p_num; // r29
  int num; // r11
  idList<idPresentablePtr<idPresentable>,5> *p_controlledPresentables; // r31
  idPresentable *v5; // r3
  idPresentable *v6; // r3
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_groupMaster; // r29
  int v10; // r31
  idPresentable *v11; // r3
  idPresentable *v12; // r3

  p_num = &this->controlledPresentables.num;
  num = this->controlledPresentables.num;
  if ( num > 0
    && (p_controlledPresentables = &this->controlledPresentables,
        idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr)
    && (*p_num <= 0
      ? (v5 = nullptr)
      : (v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: &p_controlledPresentables->list[*p_num - 1])),
        v5->GetType(this: v5) == PRESENTABLE_VEHICLE) )
  {
    if ( *p_num <= 0 )
    {
      return (idPresentableVehicle *)(*(int (**)(void))(MEMORY[0] + 76))();
    }
    else
    {
      v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: &p_controlledPresentables->list[*p_num - 1]);
      return v6->GetVehicleInterface(this: v6);
    }
  }
  else
  {
    spawnId = this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId;
    p_groupMaster = &this->groupMaster;
    v10 = spawnId & 0x3FFF;
    if ( spawnId != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v10)->spawnId == p_groupMaster->spawnId
      && (v11 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster),
          v11->GetType(this: v11) == PRESENTABLE_VEHICLE) )
    {
      v12 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster);
      return v12->GetVehicleInterface(this: v12);
    }
    else
    {
      return nullptr;
    }
  }
}


// ========================================================================
// ?UseItem@idPresentablePlayer@@QAA_NPAVidInventoryItem@@@Z
// EA  : 0x82B78D88
// RVA : 0x00B78D88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::UseItem(idPresentablePlayer *this, idAmmoItem *item)
{
  idAmmoItem *v5; // r3
  int v6; // r26
  idThrowableItem *v7; // r3
  idThrowableItem *v8; // r28
  const idDeclThrowable *DeclThrowable; // r3
  const idDeclThrowable *v10; // r3
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  int TotalInventoryItemCount; // r3
  int index; // r29
  idPresentablePlayer_vtbl *v14; // r10
  unsigned __int8 v15; // r28
  const idDeclPlayerProps::playerSounds_t *v16; // r3
  const idDeclInventory *decl; // r28
  unsigned int spawnId; // r11
  idClientGameMsg v19; // [sp+50h] [-1B0h] BYREF
  unsigned int v20; // [sp+58h] [-1A8h]
  const idDeclInventory *v21; // [sp+5Ch] [-1A4h]
  soundShaderParms_t v22; // [sp+60h] [-1A0h] BYREF
  _BYTE v23[256]; // [sp+100h] [-100h] BYREF

  if ( item == nullptr )
    return false;
  if ( this->entity != nullptr )
    common->IsServer(this: common);
  if ( (unsigned __int8)idAmmoItem::IsTypeOf(c: &item->idInventoryItem) != 0 )
  {
    v5 = idAmmoItem::CastTo(c: item);
    idHands::SelectAmmo(this: &this->hands, slot: EQUIP_RIGHT_HAND, ammo: v5);
    return true;
  }
  else
  {
    v6 = 0;
    v7 = idThrowableItem::CastTo(c: (idThrowableItem *)item);
    v8 = v7;
    if ( v7 != nullptr )
    {
      if ( idHands::CanThrowItem(this: &this->hands, item: v7)
        && (DeclThrowable = idThrowableItem::GetDeclThrowable(this: v8),
            idPresentablePlayer::UniqueProjectileAllowed(this, throwableDecl: DeclThrowable))
        && (v10 = idThrowableItem::GetDeclThrowable(this: v8),
            idPresentablePlayer::DeployableAllowed(this, throwableDecl: v10)) )
      {
        idHands::ThrowItem(this: &this->hands, item: v8);
        if ( g_infiniteAmmo.valueInteger == 0 )
          return g_permaInfiniteAmmo.valueInteger == 0;
      }
      else if ( !idHands::CookItemPending(this: &this->hands) )
      {
        PlayerSounds = idPresentablePlayer::GetPlayerSounds(
                         this: (idPresentablePlayer *)v23,
                         result: (const idDeclPlayerProps::playerSounds_t *)this);
        idPresentablePlayer::PlayLocalSound(
          this,
          channel: SND_CHANNEL_ITEM,
          shader: PlayerSounds->sndCantUseItem,
          soundShaderFlags: 0);
      }
    }
    else if ( this->entity != nullptr && common->IsServer(this: common) )
    {
      v6 = ((int (__fastcall *)(idAmmoItem *, idEntity *))item->Use)(a1: item, a2: this->entity);
      idPresentablePlayer::RespondToUseItem(this, item: &item->idInventoryItem, used: v6);
      if ( (_BYTE)v6 == 0 && !this->IsLocallyControlled(this) )
      {
        TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(
                                    this: this->activeInventory,
                                    decl: item->decl);
        idInventoryCollection::SetItemCount(
          this: this->activeInventory,
          owner: this,
          decl: item->decl,
          count: TotalInventoryItemCount,
          forceCount: true);
        index = this->index;
        soundShaderParms_t::Clear(this: &v22);
        v14 = this->__vftable;
        v22.soundShaderFlags = 0;
        v15 = v14->GetPeerIndex(this);
        v16 = idPresentablePlayer::GetPlayerSounds(
                this: (idPresentablePlayer *)v23,
                result: (const idDeclPlayerProps::playerSounds_t *)this);
        idClientGame::ReplicatePlaySound(
          this: clientGame,
          channel: SND_CHANNEL_ITEM,
          shader: v16->sndCantUseItem,
          parms: &v22,
          presentableIndex: index,
          pos: &vec3_infinity,
          peerMask: v15);
      }
    }
    else if ( (unsigned __int8)idPresentablePlayer::ClientCanUseItem(this, item: &item->idInventoryItem) != 0 )
    {
      decl = item->decl;
      v6 = ((int (__fastcall *)(idAmmoItem *, idPresentablePlayer *))item->ClientUse)(a1: item, a2: this);
      idPresentablePlayer::RespondToUseItem(this, item: &item->idInventoryItem, used: v6);
      if ( (_BYTE)v6 != 0 )
      {
        spawnId = this->spawnId;
        v21 = decl;
        v19.peerMask = -1;
        v19.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_QuickUse::`vftable';
        v20 = spawnId;
        idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v19);
        this->lastUsedTime = pm_clientUseThrottleTime.valueInteger
                           + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      }
    }
    return v6;
  }
}


// ========================================================================
// __unwind$501172
// EA  : 0x82B790B8
// RVA : 0x00B790B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_501172()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 512 + 80));
}


// ========================================================================
// ?ChallengeRestartRequest@idPresentablePlayer@@QAAX_N0@Z
// EA  : 0x82B790E0
// RVA : 0x00B790E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentablePlayer::ChallengeRestartRequest(
        idPresentablePlayer *this,
        bool restartChallenge,
        bool local)
{
  int v4; // r31 OVERLAPPED
  int value; // r7
  idGameChallenge *v6; // r3
  idGameChallenge *v7; // r3
  idGameLocal *v8; // r11
  int v9; // r9
  idGameChallenge *v10; // r3
  idGameChallenge *v11; // r3
  idGameChallenge *v12; // r29
  int v13; // r9
  idGameChallenge *v14; // r3
  idGameChallenge *v15; // r3
  idGameChallenge *v16; // r30 OVERLAPPED
  idLobbyBase *v17; // r3
  int v18; // r3
  idLobbyBase *v19; // r3
  idGameLocal *v20; // r11
  int v21; // r9
  idGameChallenge *v22; // r3
  idGameChallenge *v23; // r3
  idGameChallenge *v24; // r29
  int v25; // r9
  idGameChallenge *v26; // r3
  idGameChallenge *v27; // r3
  idGameChallenge *v28; // r30 OVERLAPPED
  idLobbyBase *v29; // r3
  _BYTE v30[2]; // [sp+50h] [-C0h] BYREF
  _BYTE v31[14]; // [sp+52h] [-BEh] BYREF
  idBitMsg v32; // [sp+60h] [-B0h] BYREF
  idBitMsg v33[3]; // [sp+90h] [-80h] BYREF

  v4 = 0;
  if ( local )
  {
    this->challengeLocalRestart = true;
  }
  else if ( restartChallenge )
  {
    this->challengeRemoteRestart = true;
  }
  else
  {
    this->challengeLocalRestart = false;
    this->challengeLeavingSoon = true;
    this->challengeRemoteRestart = false;
    value = gameLocal->challengeEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = (idGameChallenge *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v7 = idGameChallenge::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v7->bFinishGameExit = true;
    v8 = gameLocal;
    v9 = gameLocal->challengeEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
      && (v10 = (idGameChallenge *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
    {
      v11 = idGameChallenge::CastTo(c: v10);
      v8 = gameLocal;
      v12 = v11;
    }
    else
    {
      v12 = nullptr;
    }
    v13 = v8->challengeEntity.spawnId.value;
    if ( v8->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
      && (v14 = (idGameChallenge *)v8->entities.ptr[v13 & 0x1FFF]) != nullptr )
    {
      v15 = idGameChallenge::CastTo(c: v14);
      v8 = gameLocal;
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v16->endTimeoutDuration = v8->GetGameMs(this: v8, a2: GAMETIME_SCALED) + 3000 - v12->endTime;
    v32.writeData = v30;
    v32.readData = v30;
    v32.maxSize = 2;
    memset(&v32.curSize, 0, 18);
    v32.tempValue = *(_QWORD *)&v4;
    idBitMsg::WriteBits(this: &v32, value: 2, numBits: 8);
    v17 = session->GetActingGameStateLobbyBase(this: session);
    v17->SendReliable(this: v17, a2: 27, a3: &v32, a4: false, a5: 255u);
  }
  v18 = session->signInManager->GetNumLocalUsers(this: session->signInManager);
  if ( (((v18 >= 0) + ((unsigned int)v18 <= 1)) & 1) != 0
    || (v19 = session->GetActingGameStateLobbyBase(this: session), v19->IsHost(this: v19) != 0)
    && this->challengeLocalRestart )
  {
    idPresentablePlayer::ChallengeRestart(this);
    v20 = gameLocal;
    v21 = gameLocal->challengeEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
      && (v22 = (idGameChallenge *)gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr )
    {
      v23 = idGameChallenge::CastTo(c: v22);
      v20 = gameLocal;
      v24 = v23;
    }
    else
    {
      v24 = nullptr;
    }
    v25 = v20->challengeEntity.spawnId.value;
    if ( v20->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
      && (v26 = (idGameChallenge *)v20->entities.ptr[v25 & 0x1FFF]) != nullptr )
    {
      v27 = idGameChallenge::CastTo(c: v26);
      v20 = gameLocal;
      v28 = v27;
    }
    else
    {
      v28 = nullptr;
    }
    v28->endTimeoutDuration = v20->GetGameMs(this: v20, a2: GAMETIME_SCALED) + 3000 - v24->endTime;
    v33[0].writeData = v31;
    v33[0].readData = v31;
    v33[0].maxSize = 2;
    v33[0].curSize = 0;
    v33[0].writeBit = 0;
    v33[0].readCount = 0;
    v33[0].readBit = 0;
    v33[0].allowOverflow = false;
    v33[0].overflowed = false;
    v33[0].tempValue = *(_QWORD *)&v4;
    idBitMsg::WriteBits(this: v33, value: 1, numBits: 8);
    v29 = session->GetActingGameStateLobbyBase(this: session);
    v29->SendReliable(this: v29, a2: 27, a3: v33, a4: false, a5: 255u);
  }
}


// ========================================================================
// ?SetupSubtitle@idPresentablePlayer@@QAAXPBVidVoiceTrack@@PBVidPresentable@@VidStrId@@@Z
// EA  : 0x82B79488
// RVA : 0x00B79488
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SetupSubtitle(
        idPresentablePlayer *this,
        const idVoiceTrack *track,
        const idPresentable *pres,
        idStrId *whoStartedMeText)
{
  int v7; // r3
  idSWF *v8; // r11
  idEntity *v9; // r31
  idEntity *entity; // r3
  const idSoundShader *soundShader; // r31
  idPhysics *Physics; // r3
  const idVec3 *v13; // r3
  idPhysics_Player_vtbl *v14; // r7
  float y; // r5
  float z; // r11
  const idVec3 *(__fastcall *GetOrigin)(struct idPhysics_Player *, int); // r10
  float *v18; // r3
  double v19; // fp10
  float v20; // r7
  double v21; // fp8
  float v22; // r6
  double v25; // fp3
  double v26; // fp12
  __int64 v27; // r7
  const char *LocalizedString; // r3
  char *v29; // r28
  idEntity *v30; // r11
  const char *data; // r30
  int value; // r31
  const char *str; // r5
  double v34; // r7
  unsigned __int64 v35; // [sp+50h] [-50h] BYREF
  float v36; // [sp+58h] [-48h]

  if ( track != nullptr )
  {
    idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: this->entityNumber);
    if ( v7 != 0
      && (((_cntlzw(*(unsigned __int8 *)(v7 + 2064)) & 0x20) != 0)
        & ((_cntlzw(swf_useSubtitles.valueInteger) & 0x20) != 0)) == 0 )
    {
      v8 = this->loadedGuis[9];
      if ( v8 != nullptr )
        LOBYTE(v8) = v8->isActive;
      if ( (_BYTE)v8 == 0 && this->IsLocallyControlled(this) && !this->disableSubtitles )
      {
        if ( this->entity == nullptr
          || !common->IsServer(this: common)
          || gameLocal->spawnIds.ptr[*(_DWORD *)&this->entity[15].renderModelInfo.editorModel.baseBuffer[8] & 0x1FFF] != *(int *)&this->entity[15].renderModelInfo.editorModel.baseBuffer[8] >> 13
          || pres != nullptr
          && (HIDWORD(v35) = *(_DWORD *)&this->entity[15].renderModelInfo.editorModel.baseBuffer[8],
              (v9 = pres->entity) == idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&v35)) )
        {
          if ( pres == nullptr )
            goto LABEL_22;
          entity = pres->entity;
          if ( entity == nullptr )
            goto LABEL_22;
          soundShader = track->soundShader;
          if ( soundShader == nullptr )
            goto LABEL_22;
          if ( (soundShader->parms.soundShaderFlags & 8) != 0 )
            goto LABEL_22;
          Physics = idEntity::GetPhysics(this: entity);
          v13 = Physics->GetOrigin(this: Physics, a2: 0);
          v14 = this->physicsObj.__vftable;
          y = v13->y;
          z = v13->z;
          *(float *)&v35 = v13->x;
          GetOrigin = v14->GetOrigin;
          *((float *)&v35 + 1) = y;
          v36 = z;
          v18 = (float *)GetOrigin(this: &this->physicsObj, a2: 0);
          v19 = v36;
          v20 = *v18;
          v21 = *(float *)&v35;
          v22 = v18[1];
          _FP13 = soundShader->parms.wetMaxDistanceOffset;
          v36 = v18[2];
          *(float *)&v35 = v20;
          __asm { fsel      f7, f13, f13, f0 }
          v25 = (float)(v22 - *((float *)&v35 + 1));
          *((float *)&v35 + 1) = v22;
          v26 = (float)((float)((float)_FP7 + soundShader->parms.maxDistance) * soundShader->parms.distanceFactor);
          if ( (float)((float)((float)(v20 - (float)v21) * (float)(v20 - (float)v21))
                     + (float)((float)((float)(v36 - (float)v19) * (float)(v36 - (float)v19))
                             + (float)((float)v25 * (float)v25))) <= (double)(float)((float)v26 * (float)v26) )
          {
LABEL_22:
            if ( track->subtitleId.index >= 0 )
            {
              LocalizedString = idStrId::GetLocalizedString(this: &track->subtitleId);
              v29 = (char *)LocalizedString;
              if ( LocalizedString != nullptr && *LocalizedString != 0 )
              {
                if ( sub_debug.valueInteger != 0 )
                {
                  if ( pres != nullptr && (v30 = pres->entity) != nullptr )
                    data = v30->name.data;
                  else
                    data = "?";
                  value = track->approximateDuration.value;
                  if ( track->subtitleId.index >= 0 )
                    idStrId::GetKey(this: &track->subtitleId);
                  str = track->name.str;
                  v35 = __PAIR64__(&off_822B0000, value);
                  v34 = (float)((float)__SPAIR64__(&off_822B0000, value) * (float)0.001);
                  idLib::Printf(
                    fmt: "Subtitle starting\n\tEntity: %s\n\tTrack: %s\n\tStrId: %s\n\tApprox. Duration: %f\n\tText: %s\n",
                    data,
                    str,
                    (const char *)HIDWORD(v34),
                    v34,
                    (const char *)LODWORD(v34));
                }
                this->subtitleStartTime = -1;
                LODWORD(v27) = track->approximateDuration.value;
                v35 = v27;
                idSubtitleSequencer::Start(
                  this: &this->subtitleSequencer,
                  text: v29,
                  endTime: (float)((float)v27 * (float)0.001));
              }
            }
          }
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "SetupSubtitle: tried to play NULL vtr");
  }
}


// ========================================================================
// ?GetFiredWeapon@idPresentableActor@@UAAPAVidWeapon@@PBVidDeclWeapon@@@Z
// EA  : 0x82B79898
// RVA : 0x00B79898
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idWeapon *__fastcall idPresentableActor::GetFiredWeapon(idPresentableActor *this, const idDeclJob *wepDef)
{
  idJobManager *v4; // r3
  idWeapon *JobByDecl; // r3
  idPresentablePlayer *v7; // r3
  int num; // r11
  idPresentable *v9; // r3

  v4 = (idJobManager *)this->GetInventory(this);
  JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v4, jobDecl: wepDef);
  if ( JobByDecl != nullptr && JobByDecl->decl->isWeapon )
    return idWeapon::CastTo(c: JobByDecl);
  v7 = this->GetPlayerInterface_2(this);
  if ( v7 != nullptr
    && (num = v7->controlledPresentables.num) > 0
    && (v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v7->controlledPresentables.list[num - 1])) != nullptr )
  {
    return v9->GetFiredWeapon(this: v9, a2: (const idDeclWeapon *)wepDef);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?InitSideMissions@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B79A00
// RVA : 0x00B79A00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::InitSideMissions(idPresentablePlayer *this)
{
  idSWF *PlayerGui; // r29
  idSWFScriptVar v3; // [sp+50h] [-30h] BYREF
  idSWFScriptVar v4[5]; // [sp+58h] [-28h] BYREF

  PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_SIDEMISSION);
  this->scriptFunction_goToMission.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v3, nf: &this->scriptFunction_goToMission);
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "goToMission", value: &v3);
  idSWFScriptVar::Free(this: &v3);
  this->scriptFunction_resumeMap.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: v4, nf: &this->scriptFunction_resumeMap);
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "resumeMap", value: v4);
  idSWFScriptVar::Free(this: v4);
}


// ========================================================================
// __unwind$502390
// EA  : 0x82B79A88
// RVA : 0x00B79A88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_502390()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$502391
// EA  : 0x82B79AB0
// RVA : 0x00B79AB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_502391()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 88));
}


// ========================================================================
// ?Call@idSWFScriptFunction_resumeMap@idPresentablePlayer@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82B79AD8
// RVA : 0x00B79AD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentablePlayer::idSWFScriptFunction_resumeMap *__fastcall idPresentablePlayer::idSWFScriptFunction_resumeMap::Call(
        idPresentablePlayer::idSWFScriptFunction_resumeMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Sending parameters to resumeMap not allowed exiting", result, thisObject);
    this->__vftable = (idPresentablePlayer::idSWFScriptFunction_resumeMap_vtbl *)4;
  }
  else
  {
    if ( idGameLocal::GetPlayer(this: gameLocal, i: 0) == nullptr )
      idLib::Warning(fmt: "player null exiting");
    this->__vftable = (idPresentablePlayer::idSWFScriptFunction_resumeMap_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_goToMission@idPresentablePlayer@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82B79B60
// RVA : 0x00B79B60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentablePlayer::idSWFScriptFunction_goToMission *__fastcall idPresentablePlayer::idSWFScriptFunction_goToMission::Call(
        idPresentablePlayer::idSWFScriptFunction_goToMission *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayer *Player; // r3
  idPlayer *v7; // r27
  idPresentable *presentable; // r3
  idPresentablePlayer *v9; // r3
  idProp_MissionPin *MissionPin; // r3
  idProp_MissionPin *v11; // r31
  idPlayerProfileGame *v12; // r3
  idPlayerProfileGame *v13; // r30
  idGame *v14; // r29
  idGame *v15; // r26
  idGame *v16; // r3
  int fromPartIndex; // r29
  int fromVariationID; // r25
  const idGameSpawnInfo *(__fastcall *GetGameSpawnInfo)(idGame *); // ctr
  const idStr *p_spawnSpot; // r24
  int v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  int v25; // [sp+8h] [-1098h]
  int v26; // [sp+Ch] [-1094h]
  int v27; // [sp+10h] [-1090h]
  int v28; // [sp+14h] [-108Ch]
  int v29; // [sp+18h] [-1088h]
  int v30; // [sp+1Ch] [-1084h]
  va v31; // [sp+50h] [-1050h] BYREF

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Sending parameters to goToMission not allowed exiting");
    this->__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)4;
    return this;
  }
  else
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    v7 = Player;
    if ( Player != nullptr )
    {
      presentable = Player->presentable;
      if ( presentable != nullptr )
        v9 = presentable->GetPlayerInterface_2(this: presentable);
      else
        v9 = nullptr;
      MissionPin = (idProp_MissionPin *)idPresentablePlayer::GetMissionPin(this: v9);
      v11 = idProp_MissionPin::CastTo(c: MissionPin);
      if ( v11 != nullptr )
      {
        v12 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
        v13 = v12;
        if ( v12 != nullptr )
        {
          idPlayerProfileGame::SetProgress(this: v12, variationId: v11->spawn.varID);
          v14 = common->Game(this: common);
          v15 = common->Game(this: common);
          v16 = v14;
          fromVariationID = v11->fromVariationID;
          GetGameSpawnInfo = v14->GetGameSpawnInfo;
          fromPartIndex = v11->fromPartIndex;
          p_spawnSpot = &GetGameSpawnInfo(this: v16)->spawnSpot;
          v21 = (int)v15->GetGameSpawnInfo(this: v15);
          idPlayerProfileGame::SetSideMissionData(
            this: v13,
            mapName: (const idStr *)(v21 + 4),
            spawnPoint: p_spawnSpot,
            layers: &v11->fromLayers,
            variationIndex: fromVariationID,
            partIndex: fromPartIndex);
        }
        idPlayer::PrepareForNextMap(this: v7, fadeColor: &idColor::colorBlack, fadeTo: &idColor::colorBlack, to: 750.0);
        HIDWORD(v22) = v11->spawn.layers.data;
        HIDWORD(v23) = v11->spawn.spawnPoint.data;
        LODWORD(v23) = &byte_8200D768;
        LODWORD(v22) = &byte_8200D768;
        v24 = va::va(
                this: &v31,
                fmt: "nextmap %d %s \"%s\" \"%s\" \"%s\" \"%s\"\n",
                a3: (unsigned int)v11->spawn.mapName.data,
                a4: v23,
                a5: v22,
                a6: v25,
                a7: v26,
                a8: v27,
                a9: v28,
                a10: v29,
                a11: v30);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v24->buffer);
        this->__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)4;
        return this;
      }
      else
      {
        idLib::Warning(fmt: "missionPin null we wont be able to switch correctly exiting");
        this->__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)4;
        return this;
      }
    }
    else
    {
      idLib::Warning(fmt: "player null exiting");
      this->__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)4;
      return this;
    }
  }
}


// ========================================================================
// ?Draw@idPresentablePlayer@@UAA_NPAV1@@Z
// EA  : 0x82B79D60
// RVA : 0x00B79D60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::Draw(
        idPresentablePlayer *this,
        idPresentablePlayer *player,
        unsigned __int64 a3,
        int a4)
{
  __int64 v5; // r28
  int *p_num; // r29
  int num; // r11
  idPresentable *v8; // r3
  idSerializer v10; // [sp+50h] [-70h] BYREF
  _DWORD v11[7]; // [sp+60h] [-60h] BYREF
  char v12; // [sp+7Ch] [-44h]
  char v13; // [sp+7Dh] [-43h]
  __int64 v14; // [sp+80h] [-40h]

  HIDWORD(v5) = &this->view;
  idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), a2: defaultExtraGLState, bits: a3, a4);
  idPlayerHud::Update(this: &this->playerHud, hudInfo: &this->hudInfo);
  LODWORD(v5) = 0;
  if ( common->IsMultiplayer(this: common) && !common->IsServer(this: common) && this->IsLocallyControlled(this) )
  {
    v11[0] = 0;
    memset(&v11[4], 0, 12);
    v11[2] = 444;
    v11[1] = this->serializedHudInfoBuffer;
    v11[3] = 444;
    v12 = 0;
    v13 = 0;
    v14 = v5;
    v10.writing = false;
    v10.msg = (idBitMsg *)v11;
    idPresentablePlayer::SerializeHud(this, ser: &v10, hudInfo: &this->hudInfo);
  }
  if ( this->index >= 12288 || !this->IsLocallyControlled(this) )
    return 0;
  p_num = &this->controlledPresentables.num;
  num = this->controlledPresentables.num;
  if ( num > 0
    && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
  {
    if ( *p_num <= 0 )
      v8 = nullptr;
    else
      v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]);
    if ( !v8->Draw(this: v8, a2: this) )
    {
      if ( this->IsDead(this) && (*((_BYTE *)this + 47032) & 4) == 0 )
      {
        idView::SetViewID(this: (idView *)HIDWORD(v5), id: 0);
        idView::Render(this: (idView *)HIDWORD(v5));
      }
      idView::SetViewPos(
        this: (idView *)HIDWORD(v5),
        origin: &this->serializedViewOrigin,
        axis: &this->serializedviewAxis);
      return 0;
    }
  }
  else
  {
    idPresentablePlayer::Draw_Shared(this);
  }
  return 1;
}


// ========================================================================
// ?ClientPredict@idPresentablePlayer@@UAAXHM@Z
// EA  : 0x82B79F88
// RVA : 0x00B79F88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientPredict(idPresentablePlayer *this, int curTime, double fraction)
{
  int *p_num; // r29
  bool v5; // r28
  int num; // r11

  if ( this->IsLocallyControlled(this) )
  {
    p_num = &this->controlledPresentables.num;
    v5 = idPresentablePlayer::GetVehicle(this) != nullptr;
    num = this->controlledPresentables.num;
    if ( num <= 0
      || idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) == nullptr
      || (*((_BYTE *)this + 47032) & 4) != 0
      || v5 )
    {
      idPlayer::ProcessInput(this: (idPlayer *)this->entity, doMovement: true);
    }
    else if ( this->IsDead(this) )
    {
      idHands::Update(this: &this->hands);
    }
    else
    {
      common->IsMultiplayer(this: common);
    }
    if ( *p_num <= 0
      || idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]) == nullptr )
    {
      idPresentablePlayer::ClientPredictTriggers(this);
    }
  }
}


// ========================================================================
// ?ShouldLinkPresentableCollision@idPresentablePlayer@@UAA_NXZ
// EA  : 0x82B7A0B0
// RVA : 0x00B7A0B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

BOOL __fastcall idPresentablePlayer::ShouldLinkPresentableCollision(idPresentablePlayer *this)
{
  int num; // r11

  num = this->controlledPresentables.num;
  if ( num <= 0 )
    return (_cntlzw(0) & 0x20) != 0;
  else
    return (_cntlzw((unsigned int)idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]))
          & 0x20) != 0;
}


// ========================================================================
// ?UpdateOutline@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B7A120
// RVA : 0x00B7A120
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateOutline(idPresentablePlayer *this)
{
  idRenderModelAugmentOutline **p_outlineModel; // r28
  int *p_num; // r30
  int num; // r11
  idList<idPresentablePtr<idPresentable>,5> *p_controlledPresentables; // r31
  idPresentable *v6; // r3
  int v7; // r3
  char v8; // r11
  idRenderModel *v9; // r31
  double v10; // fp13
  double v11; // fp12
  idRenderModel *v12; // r3
  idVec4 v13; // [sp+50h] [-40h] BYREF

  p_outlineModel = &this->outlineModel;
  if ( this->outlineModel != nullptr )
  {
    p_num = &this->controlledPresentables.num;
    num = this->controlledPresentables.num;
    if ( num <= 0
      || (p_controlledPresentables = &this->controlledPresentables,
          idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) == nullptr)
      || (*p_num <= 0
        ? (v6 = nullptr)
        : (v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: &p_controlledPresentables->list[*p_num - 1])),
          v7 = (int)v6->GetVehicleInterface(this: v6),
          v8 = 1,
          v7 == 0) )
    {
      v8 = 0;
    }
    if ( v8 != 0 || this->hidden )
    {
      v9 = *p_outlineModel;
      if ( !(*p_outlineModel)->unlinked )
      {
        idRenderModel::CommitThisFrame(this: *p_outlineModel);
        v9->unlinked = true;
      }
    }
    else
    {
      idRenderModel::CommitThisFrame(this: *p_outlineModel);
    }
    if ( (*((_BYTE *)this + 47032) & 4) != 0 )
    {
      v10 = 0.5;
      v11 = 0.0;
    }
    else
    {
      v11 = 0.5;
      v10 = 0.0;
    }
    v13.z = 0.0;
    v13.x = v10;
    v13.y = v11;
    v12 = *p_outlineModel;
    v13.w = 1.0;
    idRenderModel::SetParm(this: v12, parm: rp->Color, v4: &v13);
  }
}


// ========================================================================
// ?SerializePredictionState@idPresentablePlayer@@QAAXAAVidSerializer@@@Z
// EA  : 0x82B7A288
// RVA : 0x00B7A288
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SerializePredictionState(idPresentablePlayer *this, idSerializer *ser)
{
  __int64 v2; // r27
  __int64 v5; // r8
  idBitMsg *msg; // r3
  idVec3 *p_serializedViewOrigin; // r4
  int clientPlayerInputFrame; // r30
  idBitMsg *v9; // r3
  int v10; // r5
  int *p_num; // r29
  int num; // r11
  idPresentable *v13; // r3
  idPresentableVehicle *v14; // r3
  idSerializer v15; // [sp+50h] [-70h] BYREF
  _DWORD v16[7]; // [sp+60h] [-60h] BYREF
  char v17; // [sp+7Ch] [-44h]
  char v18; // [sp+7Dh] [-43h]
  __int64 v19; // [sp+80h] [-40h]

  if ( common->SnapshotState(this: common) == SNAP_WRITING && this->IsLocallyControlled(this)
    || common->SnapshotState(this: common) == SNAP_READING && !this->IsLocallyControlled(this) )
  {
    idLib::Warning(fmt: "Received prediction state for non local player %d ", this->entityNumber);
  }
  else
  {
    idPresentablePlayer::SerializeHud(this, ser, hudInfo: &this->hudInfo);
    idSerializer::SerializeQ(this: ser, axis: (idQuat *)&this->serializedviewAxis, bits: 15, a4: v5);
    msg = ser->msg;
    p_serializedViewOrigin = &this->serializedViewOrigin;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,17>(this: msg, v: p_serializedViewOrigin);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,17>(this: msg, v: p_serializedViewOrigin);
    LODWORD(v2) = 0;
    if ( !ser->writing )
    {
      memset(&v16[3], 0, 16);
      v16[2] = 444;
      v16[0] = this->serializedHudInfoBuffer;
      v16[1] = this->serializedHudInfoBuffer;
      v17 = 0;
      v18 = 0;
      v19 = v2;
      v15.writing = true;
      v15.msg = (idBitMsg *)v16;
      idPresentablePlayer::SerializeHud(this, ser: &v15, hudInfo: &this->hudInfo);
    }
    clientPlayerInputFrame = this->clientPlayerInputFrame;
    v9 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v9, value: this->clientPlayerInputFrame, numBits: 32);
    else
      this->clientPlayerInputFrame = idBitMsg::ReadBits(this: v9, numBits: 32);
    if ( !ser->writing )
    {
      v10 = this->clientPlayerInputFrame;
      if ( v10 != 0 && v10 <= clientPlayerInputFrame )
        idLib::Printf(fmt: "clientPlayerInputFrame out of sequence (%i/%i) \n", clientPlayerInputFrame, v10);
    }
    p_num = &this->controlledPresentables.num;
    num = this->controlledPresentables.num;
    if ( num > 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr
      && (*p_num <= 0
        ? (v13 = nullptr)
        : (v13 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1])),
          (v14 = v13->GetVehicleInterface(this: v13)) != nullptr) )
    {
      idPresentableVehicle::SerializePredictionState(this: v14, ser);
    }
    else
    {
      playerPState_t::operator=(this: &this->serializedState, __that: &this->physicsObj.current);
      this->physicsObj.Serialize(this: &this->physicsObj, a2: ser, a3: &this->serializedState);
      this->firstPredictionSerialize = false;
    }
  }
}


// ========================================================================
// ?SerializeNonPredictionState@idPresentablePlayer@@QAAXAAVidSerializer@@@Z
// EA  : 0x82B7A510
// RVA : 0x00B7A510
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::SerializeNonPredictionState(idPresentablePlayer *this, idSerializer *ser)
{
  int *p_num; // r29
  int num; // r11
  idPresentable *v6; // r3
  idPresentableVehicle *v7; // r3

  if ( ser->writing || !this->IsLocallyControlled(this) )
  {
    p_num = &this->controlledPresentables.num;
    num = this->controlledPresentables.num;
    if ( num > 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
    {
      if ( *p_num <= 0 )
        v6 = nullptr;
      else
        v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]);
      v7 = v6->GetVehicleInterface(this: v6);
      if ( v7 != nullptr )
        idPresentableVehicle::SerializeNonPredictionState(this: v7, ser);
    }
    this->physicsObj.SerializeNonPredictiveState(this: &this->physicsObj, a2: ser);
  }
  else
  {
    idLib::Warning(fmt: "Received NonPredictionState for local player");
  }
}


// ========================================================================
// ?RecordMove@idPresentablePlayer@@QAAXABVusercmd_t@@0ABVidAngles@@HH@Z
// EA  : 0x82B7A608
// RVA : 0x00B7A608
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::RecordMove(
        idPresentablePlayer *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd,
        const idAngles *angles,
        int startTime,
        int endTime)
{
  idPresentablePlayer::moveBufferItem_t *v12; // r31
  int *p_num; // r26
  int num; // r11
  idPresentable *v15; // r3
  int v16; // r3
  float *v17; // r3
  double v20; // fp3
  double v21; // fp9
  double v22; // fp6
  unsigned __int8 v23; // r11
  const idVec3 *v24; // r3
  int clientGameFrame; // r4
  float y; // r10
  float z; // r6
  float v28[24]; // [sp+50h] [-60h] BYREF

  v12 = &this->moveBuffer[idAccolade::Count(this: &clientGame->gameTimeManager) % 64];
  this->lastRecordedMoveBufferIndex = idAccolade::Count(this: &clientGame->gameTimeManager);
  memcpy(Dst: v12, Src: prevcmd, Size: 0x3Cu);
  memcpy(Dst: &v12->curCmd, Src: usercmd, Size: sizeof(v12->curCmd));
  v12->viewAngles = *angles;
  v12->startTime = startTime;
  v12->endTime = endTime;
  v12->origin = *this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  p_num = &this->controlledPresentables.num;
  v12->speed = 0.0;
  num = this->controlledPresentables.num;
  if ( num > 0
    && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
  {
    v15 = *p_num <= 0
        ? nullptr
        : idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]);
    v16 = (int)v15->GetVehicleInterface(this: v15);
    if ( v16 != 0 )
    {
      v17 = (float *)(*(int (__fastcall **)(float *, int, _DWORD))(*(_DWORD *)(v16 + 16512) + 88))(
                       a1: v28,
                       a2: v16 + 16512,
                       a3: 0);
      _FP6 = (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f4, f6, f7, f13 }
      v20 = __frsqrte(_FP4);
      v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                          * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v20)
                                                                          - (float)1.5)
                                                          * (float)v20)
                                                  * (float)((float)((float)(v17[2] * v17[2])
                                                                  + (float)((float)(*v17 * *v17)
                                                                          + (float)(v17[1] * v17[1])))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v20
                                                                                  * (float)((float)((float)(v17[2] * v17[2])
                                                                                                  + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                                                                                          * (float)0.5))
                                                                          * (float)v20)
                                                                  - (float)1.5)
                                                  * (float)v20))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v20
                                                          * (float)((float)((float)(v17[2] * v17[2])
                                                                          + (float)((float)(*v17 * *v17)
                                                                                  + (float)(v17[1] * v17[1])))
                                                                  * (float)0.5))
                                                  * (float)v20)
                                          - (float)1.5)
                          * (float)v20));
      v22 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1]))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                          * (float)v20)
                                                                                  * (float)((float)((float)(v17[2] * v17[2])
                                                                                                  + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1]))) * (float)0.5)) * (float)v20)
                                                                                                  - (float)1.5)
                                                                                  * (float)v20))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v20
                                                                                          * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v20)
                                                                          - (float)1.5)
                                                          * (float)v20))
                                          * (float)((float)((float)(v17[2] * v17[2])
                                                          + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])))
                                                  * (float)0.5))
                                  * (float)v21)
                          - (float)1.5);
      v12->speed = (float)((float)v22
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1]))) * (float)0.5))
                                                                                                 * (float)v20)
                                                                                         - (float)1.5)
                                                                         * (float)v20)
                                                                 * (float)((float)((float)(v17[2] * v17[2])
                                                                                 + (float)((float)(*v17 * *v17)
                                                                                         + (float)(v17[1] * v17[1])))
                                                                         * (float)0.5))
                                                         * (float)((float)-(float)((float)((float)((float)v20
                                                                                                 * (float)((float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1]))) * (float)0.5))
                                                                                         * (float)v20)
                                                                                 - (float)1.5)
                                                                 * (float)v20))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v20
                                                                         * (float)((float)((float)(v17[2] * v17[2])
                                                                                         + (float)((float)(*v17 * *v17)
                                                                                                 + (float)(v17[1] * v17[1])))
                                                                                 * (float)0.5))
                                                                 * (float)v20)
                                                         - (float)1.5)
                                         * (float)v20)))
                 * (float)((float)(v17[2] * v17[2]) + (float)((float)(*v17 * *v17) + (float)(v17[1] * v17[1])));
    }
  }
  v12->predictionBits = 0;
  v23 = ((unsigned __int8)idPhysics_Player::IsCrouching(this: &this->physicsObj) != 0) | v12->predictionBits;
  v12->predictionBits = v23;
  v12->predictionBits = (!this->isSprinting ? 0 : 2) | v23;
  v12->predictionBits |= !idPresentablePlayer::IsFullyZoomedIn(this) ? 0 : 4;
  v12->curCmd.clientGameFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  if ( pm_clientAuthoritative_debug.valueInteger != 0 )
  {
    v24 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    clientGameFrame = usercmd->clientGameFrame;
    y = v24->y;
    z = v24->z;
    v28[0] = v24->x;
    v28[1] = y;
    v28[2] = z;
    idLib::Printf(
      fmt: "[%d]Remote client player physics forward: %d pos <%.2f, %.2f, %.2f> \n",
      clientGameFrame,
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v28[0])),
      v28[0],
      y,
      z);
  }
}


// ========================================================================
// ?HandleUserCmds@idPresentablePlayer@@QAAXABVusercmd_t@@@Z
// EA  : 0x82B7A920
// RVA : 0x00B7A920
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::HandleUserCmds(idPresentablePlayer *this, const usercmd_t *newcmd)
{
  int clientGameFrame; // r31
  int clientPlayerInputFrame; // r30
  idUCmdInhibit::inhibitFlags_t InhibitFlags; // r3
  unsigned int v7; // r30
  int v8; // r25
  int v9; // r27
  int *p_num; // r29
  int v11; // r28
  int num; // r11
  idPresentable *v13; // r3
  idCamera *v14; // r3
  idCamera *v15; // r31
  char v16; // r11
  char v17; // r7
  char v18; // r10
  char v19; // r9
  char v20; // r8
  int buttons; // r31
  int v22; // r11
  int v23; // r10
  int v24[4]; // [sp+50h] [-E0h] BYREF
  idUCmdInhibit v25; // [sp+60h] [-D0h] BYREF
  idUCmdInhibit v26; // [sp+80h] [-B0h] BYREF
  usercmd_t v27[2]; // [sp+A0h] [-90h] BYREF

  if ( !common->IsClient(this: common) )
  {
    clientGameFrame = newcmd->clientGameFrame;
    clientPlayerInputFrame = this->clientPlayerInputFrame;
    if ( !this->IsLocallyControlled(this) )
    {
      if ( clientGameFrame <= clientPlayerInputFrame )
        idLib::Printf(fmt: "HandleUserCmds: Usercmd older (%i/%i).\n", clientPlayerInputFrame, clientGameFrame);
      if ( clientGameFrame != clientPlayerInputFrame + 1 )
        idLib::Printf(
          fmt: "HandleUserCmds: Usercmd out of sequence (%i/%i).\n",
          clientPlayerInputFrame,
          clientGameFrame);
    }
    this->clientPlayerInputFrame = clientGameFrame;
  }
  v24[0] = 0;
  InhibitFlags = idPresentablePlayer::GetInhibitFlags(this, specificInhibitButtons: v24);
  v7 = InhibitFlags;
  if ( (InhibitFlags & 0x20) != 0 )
  {
    v7 = InhibitFlags & 0xFFFFFFD8 | 7;
    this->inhibitFlags &= ~0x20u;
  }
  if ( (v7 & 0x80) != 0 )
  {
    v7 = v7 & 0xFFFFFF6F | 0x10;
    this->inhibitFlags &= ~0x80u;
  }
  if ( (v7 & 0x40) != 0 )
  {
    v7 = v7 & 0xFFFFFFB7 | 8;
    this->inhibitFlags &= ~0x40u;
  }
  if ( this->IsLocallyControlled(this) )
    LOBYTE(v8) = idPresentablePlayer::IsPlayerControlInhibited(this);
  else
    v8 = *((unsigned __int8 *)newcmd + 9) >> 7;
  v9 = 0;
  p_num = &this->controlledPresentables.num;
  v11 = 0;
  num = this->controlledPresentables.num;
  if ( num > 0
    && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
  {
    v13 = *p_num <= 0
        ? nullptr
        : idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]);
    v14 = idCamera::CastTo(c: (idCamera *)v13->entity);
    v15 = v14;
    if ( v14 != nullptr )
    {
      v11 = v14->InhibitFlags(this: v14);
      v9 = v15->InhibitButtons(this: v15);
    }
  }
  v25.game = v8;
  v25.minUp = 0x80;
  v25.minForward = 0x80;
  v25.maxUp = 127;
  v16 = 0x80;
  v25.maxForward = 127;
  v17 = *((_BYTE *)this + 47033);
  v18 = 127;
  v19 = 0x80;
  v25.flags = v11 | v7;
  v25.buttons = v9 | v24[0];
  v20 = 127;
  v25.minRight = 0x80;
  v25.maxRight = 127;
  if ( (v17 & 2) != 0 && (v17 & 1) == 0 )
  {
    v16 = -64;
    v18 = 64;
    v19 = -64;
    v25.minForward = -64;
    v20 = 64;
    v25.maxForward = 64;
    v25.minRight = -64;
    v25.maxRight = 64;
  }
  v26.minUp = 0x80;
  v26.flags = v7;
  v26.game = v8;
  v26.maxUp = 127;
  v26.buttons = 0;
  v26.minForward = v16;
  v26.maxForward = v18;
  v26.minRight = v19;
  v26.maxRight = v20;
  memcpy(Dst: v27, Src: newcmd, Size: 0x3Cu);
  buttons = v27[0].buttons;
  if ( (v27[0].buttons & 0x30000000) != 0 )
  {
    if ( (v27[0].buttons & 0x10000000) != 0 )
      buttons = v27[0].buttons & 0xDFFCFFFF;
    else
      buttons = v27[0].buttons & 0xEFFCFFFF;
LABEL_34:
    v27[0].buttons = buttons;
    goto LABEL_35;
  }
  if ( (v27[0].buttons & 0x30000) != 0 )
  {
    buttons = v27[0].buttons & 0xCFFDFFFF;
    if ( (v27[0].buttons & 0x10000) == 0 )
      buttons = v27[0].buttons & 0xCFFEFFFF;
    goto LABEL_34;
  }
LABEL_35:
  if ( this->hands.currentDualWieldState == SET_DUALWIELD_ON && !usercmdGen->GetUseAimAssist(this: usercmdGen) )
  {
    v22 = newcmd->buttons;
    v23 = newcmd->buttons & 8;
    if ( v23 != 0 )
    {
      buttons |= 1u;
      v27[0].buttons = buttons;
      if ( (v22 & 1) == 0 )
      {
        buttons &= ~8u;
        v27[0].buttons = buttons;
      }
    }
    if ( (v22 & 1) != 0 )
    {
      v27[0].buttons = buttons | 8;
      if ( v23 == 0 )
        v27[0].buttons = buttons & 0xFFFFFFF6 | 8;
    }
  }
  idUCmdTracker::Update(this: &this->ucmdTracker1, newcmd: v27, inhibit: &v25);
  idUCmdTracker::Update(this: &this->ucmdTracker2, newcmd: v27, inhibit: &v26);
}


// ========================================================================
// ?GetPlayerGameTime@idPresentablePlayer@@QAAHXZ
// EA  : 0x82B7ACF0
// RVA : 0x00B7ACF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::GetPlayerGameTime(idPresentablePlayer *this)
{
  int num; // r11
  idUCmdTracker *p_ucmdTracker2; // r31

  if ( !common->IsMultiplayer(this: common)
    || (unsigned __int8)idPresentablePlayer::IsInterpolated(this) != 0
    || common->IsServer(this: common) && this->IsLocallyControlled(this) )
  {
    return idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
  num = this->controlledPresentables.num;
  if ( num > 0
    && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
  {
    p_ucmdTracker2 = &this->ucmdTracker2;
  }
  else
  {
    p_ucmdTracker2 = &this->ucmdTracker1;
  }
  return p_ucmdTracker2->usercmd.clientGameFrame
       * idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?AttachController@idPresentablePlayer@@AAAXPAVidPresentable@@@Z
// EA  : 0x82B7AE20
// RVA : 0x00B7AE20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::AttachController(idPresentablePlayer *this, idPresentable *control)
{
  unsigned int spawnId; // r11

  if ( control != nullptr )
  {
    spawnId = 0;
    if ( this != nullptr )
      spawnId = this->spawnId;
    control->controller.spawnId = spawnId;
    this->isTurretControl = idProp_WeaponStatic::CastTo(c: (idProp_WeaponStatic *)control->entity) != nullptr;
    idPresentablePlayer::HandleUserCmds(this, newcmd: &this->ucmdTracker2.usercmd);
  }
}


// ========================================================================
// ?DetachController@idPresentablePlayer@@AAAXPAVidPresentable@@@Z
// EA  : 0x82B7AE90
// RVA : 0x00B7AE90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DetachController(idPresentablePlayer *this, idPresentable *control)
{
  unsigned int spawnId; // r11
  int v5; // r30

  spawnId = control->controller.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == control->controller.spawnId
    && idPresentable::GetController(this: control) == this )
  {
    control->ControlReleased(this: control);
    control->controller.spawnId = 0;
  }
}


// ========================================================================
// `idPresentablePlayer::ShowTutorialGui'::`31'::idSWFScriptFunction_DeactivateCallback::Call
// EA  : 0x82B7AF20
// RVA : 0x00B7AF20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPresentablePlayer::ShowTutorialGui_::_31_::idSWFScriptFunction_DeactivateCallback::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r11
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int size; // r11
  int v10; // r11
  int v11; // r10
  const idDeclJob *v12; // r31
  char v13; // r29
  idJobManager *v14; // r3
  idJob *JobByDecl; // r3

  idSWF::Activate(this: (idSWF *)thisObject->variables.num, b: false);
  v5 = *(_DWORD *)&thisObject->variables.granularity;
  if ( v5 != 0 )
  {
    v6 = *(_DWORD *)(v5 + 488);
    if ( v6 != 0 && (*(int (__fastcall **)(int))(*(_DWORD *)v6 + 104))(a1: v6) != 0 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)&thisObject->variables.granularity + 488);
      if ( v7 != 0 )
        v8 = (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 104))(a1: v7);
      else
        v8 = 0;
      *(_DWORD *)(v8 + 48576) = 0;
    }
  }
  size = thisObject->variables.size;
  if ( size != 0 )
    (*(void (**)(void))(*(_DWORD *)size + 380))();
  v10 = thisObject->variablesHash[0];
  if ( *(_DWORD *)(v10 + 80) == 4 )
  {
    v11 = *(_DWORD *)&thisObject->variables.granularity;
    if ( v11 != 0 )
    {
      v12 = *(const idDeclJob **)(v10 + 140);
      v13 = 1;
      if ( v12 != nullptr )
      {
        v14 = (idJobManager *)(*(int (**)(void))(*(_DWORD *)v11 + 468))();
        JobByDecl = idJobManager::FindJobByDecl(this: v14, jobDecl: v12);
        if ( JobByDecl == nullptr
          || ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) < 1 )
        {
          v13 = 0;
        }
      }
      if ( v13 != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&thisObject->variables.granularity + 12732) = 1;
        idPlayer::ShowInventory(this: *(idPlayer **)&thisObject->variables.granularity, inVehicle: false);
      }
    }
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idPresentablePlayer::ShowTutorialGui'::`32'::idSWFScriptFunction_waitInput::Call
// EA  : 0x82B7B070
// RVA : 0x00B7B070
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPresentablePlayer::ShowTutorialGui_::_32_::idSWFScriptFunction_waitInput::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a4)
{
  keyNum_t v6; // r31
  bool v7; // r27
  char v8; // r25
  int v9; // r11
  int v10; // r11
  unsigned int v11; // r30
  unsigned int v12; // r3
  char *Binding; // r28
  int num; // r11
  int v15; // r30
  int v16; // r31
  int v17; // r11
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r11

  if ( *(_DWORD *)(a4 + 4) == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: *(idSWFScriptVar **)a4);
    v7 = false;
    v8 = 0;
    if ( *(_DWORD *)(thisObject->variables.num + 80) == 2 )
    {
      v9 = thisObject->variablesHash[0];
      if ( v9 != 0 )
        v7 = (*(int (**)(void))(*(_DWORD *)v9 + 828))() == 0;
    }
    if ( *(_DWORD *)(thisObject->variables.num + 80) == 3 )
    {
      v10 = thisObject->variablesHash[0];
      if ( v10 != 0 && (*(int (**)(void))(*(_DWORD *)v10 + 828))() != 0 )
        v7 = true;
    }
    v11 = *(_DWORD *)(thisObject->variables.num + 84);
    v12 = common->GetFocusDeviceNum(this: common);
    Binding = idKeyInput::GetBinding(numDevice: v12, bindset: v11, keynum: v6);
    if ( idStr::Icmp(s1: Binding, s2: (const char *)thisObject->variablesHash[2]) == 0 )
    {
      v7 = true;
      v8 = 1;
    }
    num = thisObject->variables.num;
    v15 = 0;
    if ( *(int *)(num + 124) > 0 )
    {
      v16 = 0;
      do
      {
        if ( v7 )
          break;
        if ( idStr::Icmp(s1: Binding, s2: *(const char **)(*(_DWORD *)(num + 120) + v16 + 4)) == 0 )
          v7 = true;
        num = thisObject->variables.num;
        ++v15;
        v16 += 32;
      }
      while ( v15 < *(_DWORD *)(num + 124) );
    }
    if ( v7 )
    {
      idSWF::Activate(this: (idSWF *)thisObject->variables.size, b: false);
      v17 = thisObject->variablesHash[0];
      if ( v17 != 0 )
      {
        v18 = *(_DWORD *)(v17 + 488);
        if ( v18 != 0 && (*(int (__fastcall **)(int))(*(_DWORD *)v18 + 104))(a1: v18) != 0 )
        {
          v19 = *(_DWORD *)(thisObject->variablesHash[0] + 488);
          if ( v19 != 0 )
            v20 = (*(int (__fastcall **)(int))(*(_DWORD *)v19 + 104))(a1: v19);
          else
            v20 = 0;
          *(_DWORD *)(v20 + 48576) = 0;
        }
      }
      if ( v8 != 0 )
      {
        v21 = *(_DWORD *)&thisObject->variables.granularity;
        if ( v21 != 0 )
          (*(void (**)(void))(*(_DWORD *)v21 + 380))();
      }
    }
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Serialize@idPresentablePlayer@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B7B5B0
// RVA : 0x00B7B5B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::Serialize(idPresentablePlayer *this, idSerializer *ser)
{
  int v4; // r24
  int v5; // r25
  int i; // r28
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  idPresentablePtr<idPresentable> *list; // r29
  unsigned int spawnId; // r11
  int v13; // r30
  idPresentable *PresentableByIndex; // r3
  idPresentable *v15; // r4
  idPresentablePtr<idPresentable> *v16; // r30
  idBitMsg *v17; // r3
  idBitMsg *msg; // r3
  idInventoryCollection *activeInventory; // r3
  idGameChallenge *ChallengeEntity; // r29
  bool sentOfficialSnap; // r30
  idBitMsg *v22; // r3
  char *v23; // r30
  idBitMsg *v24; // r3
  int v25; // r29
  bool isTurretControl; // r29
  idBitMsg *v27; // r3
  idBitMsg *v28; // r3
  bool v29; // r29
  char v30; // r9
  bool v31; // r29
  idBitMsg *v32; // r3
  char v33; // r9
  bool v34; // r29
  idBitMsg *v35; // r3
  _BYTE *v36; // r29
  idBitMsg *v37; // r3
  char v38; // r28
  char v39; // r9
  bool v40; // r28
  idBitMsg *v41; // r3
  char v42; // r9
  bool v43; // r28
  idBitMsg *v44; // r3
  char v45; // r9
  char v46; // r28
  idBitMsg *v47; // r3
  char v48; // r10
  bool v49; // r28
  idBitMsg *v50; // r3
  idPresentablePlayer_vtbl *v51; // r9
  idBitMsg *v52; // r3
  bool v53; // r30
  netBoolEvent_t *p_respawn; // r30
  int count; // r4
  idBitMsg *v56; // r3
  unsigned int v57; // r10
  int v58; // r29
  netBoolEvent_t *p_teleported; // r30
  int v60; // r4
  idBitMsg *v61; // r3
  netBoolEvent_t *p_vehicleExited; // r30
  int v63; // r4
  idBitMsg *v64; // r3
  idBitMsg *v65; // r3
  int *p_scoreIndex; // r30
  int j; // r29
  idBitMsg *v68; // r3
  idBitMsg *v69; // r3
  int *p_score; // r27
  int k; // r26
  int *v72; // r29
  idBitMsg *v73; // r28
  int v74; // r30
  idBitMsg *v75; // r3
  idBitMsg *v76; // r3
  int *p_damageFeedbackBufferPos; // r27
  int damageFeedbackBufferPos; // r29
  int v79; // r28
  idPresentablePtr<idPresentable> *p_attacker; // r30
  idBitMsg *v81; // r3
  idBitMsg *v82; // r3
  idVec3 *v83; // r4
  idBitMsg *v84; // r3
  idVec3 *v85; // r4
  idBitMsg *v86; // r3
  idVec3 *v87; // r4
  idBitMsg *v88; // r3
  idBitMsg *v89; // r3
  int v90; // r4
  int v91; // r6
  idPresentablePlayer::damageDealtFeedbackItem_t *damageDealtBuffer; // r30
  int m; // r29
  idBitMsg *v94; // r3
  idBitMsg *v95; // r3
  idBitMsg *v96; // r3
  int *p_roverBombSoundCounter; // r30
  int v98; // [sp+8h] [-A8h]
  int v99; // [sp+Ch] [-A4h]
  int v100; // [sp+10h] [-A0h]
  int v101; // [sp+14h] [-9Ch]
  int v102; // [sp+18h] [-98h]
  idPresentable *v103; // [sp+1Ch] [-94h]
  int v104[24]; // [sp+50h] [-60h] BYREF

  idPresentableActor::Serialize(this, ser);
  if ( ser->writing )
  {
    v104[0] = this->controlledPresentables.num;
    idSerializer::Serialize(this: ser, value: v104);
    v4 = v104[0];
  }
  else
  {
    idSerializer::Serialize(this: ser, value: v104);
    v4 = v104[0];
    idList<idSysInterlockedInteger,96>::SetNum(this: &this->controlledPresentables, newNum: v104[0]);
  }
  v5 = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( v5 >= v4 )
    {
      msg = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: msg, value: 0, numBits: 32);
      else
        idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    else
    {
      v8 = common->IsServer(this: common);
      if ( v8 != 0 )
      {
        list = this->controlledPresentables.list;
        spawnId = list[i].spawnId;
        v13 = spawnId & 0x3FFF;
        if ( spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v13),
              v7 = PresentableByIndex->spawnId,
              v15 = PresentableByIndex,
              v7 != list[i].spawnId) )
        {
          v15 = nullptr;
        }
        idClientGame::MarkPresentableSerialized(
          this: clientGame,
          presentable: v15,
          serialized: true,
          deleted: false,
          a5: v10,
          a6: v9,
          a7: v8,
          a8: v7,
          a9: v98,
          a10: v99,
          a11: v100,
          a12: v101,
          a13: v102,
          a14: v103);
      }
      v16 = this->controlledPresentables.list;
      v17 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v17, value: v16[i].spawnId, numBits: 32);
      else
        v16[i].spawnId = idBitMsg::ReadBits(this: v17, numBits: 32);
    }
    ++v5;
  }
  if ( !common->TimeTrialPlaying(this: common)
    && !common->TimeTrialRecording(this: common)
    && !common->DemoPlaying(this: common)
    && !common->DemoRecording(this: common) )
  {
    activeInventory = this->activeInventory;
    if ( activeInventory != nullptr )
      idInventoryCollection::Serialize(this: activeInventory, ser);
  }
  if ( ser->writing )
  {
    this->sentOfficialSnap = false;
    ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
    if ( idGameChallenge::GetPlayerData(this: ChallengeEntity, player: (const idPlayer *)this->entity) != nullptr
      && !idGameChallenge::GetPlayerData(this: ChallengeEntity, player: (const idPlayer *)this->entity)->needToSendFullSnap )
    {
      this->sentOfficialSnap = true;
    }
  }
  sentOfficialSnap = this->sentOfficialSnap;
  v22 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v22, value: this->sentOfficialSnap, numBits: 1);
  else
    sentOfficialSnap = (_cntlzw(idBitMsg::ReadBits(this: v22, numBits: 1) - 1) & 0x20) != 0;
  this->sentOfficialSnap = sentOfficialSnap;
  v23 = (char *)this + 47032;
  v24 = ser->msg;
  v25 = *((unsigned __int8 *)this + 47032) >> 7;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v24, value: *((_BYTE *)this + 47032) >> 7, numBits: 1);
  else
    LOBYTE(v25) = (_cntlzw(idBitMsg::ReadBits(this: v24, numBits: 1) - 1) & 0x20) != 0;
  *v23 = ((_BYTE)v25 << 7) | *v23 & 0x7F;
  isTurretControl = this->isTurretControl;
  v27 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v27, value: this->isTurretControl, numBits: 1);
  else
    isTurretControl = (_cntlzw(idBitMsg::ReadBits(this: v27, numBits: 1) - 1) & 0x20) != 0;
  this->isTurretControl = isTurretControl;
  v28 = ser->msg;
  v29 = (*v23 & 0x10) != 0;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v28, value: (*v23 & 0x10) != 0, numBits: 1);
  else
    v29 = (_cntlzw(idBitMsg::ReadBits(this: v28, numBits: 1) - 1) & 0x20) != 0;
  v30 = (16 * v29) & 0x10 | *v23 & 0xEF;
  *v23 = v30;
  v31 = (v30 & 0x20) != 0;
  v32 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v32, value: (v30 & 0x20) != 0, numBits: 1);
  else
    v31 = (_cntlzw(idBitMsg::ReadBits(this: v32, numBits: 1) - 1) & 0x20) != 0;
  v33 = (32 * v31) & 0x20 | *v23 & 0xDF;
  *v23 = v33;
  v34 = (v33 & 8) != 0;
  v35 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v35, value: (v33 & 8) != 0, numBits: 1);
  else
    v34 = (_cntlzw(idBitMsg::ReadBits(this: v35, numBits: 1) - 1) & 0x20) != 0;
  *v23 = (8 * v34) & 8 | *v23 & 0xF7;
  v36 = (char *)this + 47033;
  v37 = ser->msg;
  v38 = (*((_BYTE *)this + 47033) & 0x40) != 0;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v37, value: (*((_BYTE *)this + 47033) & 0x40) != 0, numBits: 1);
  else
    v38 = (_cntlzw(idBitMsg::ReadBits(this: v37, numBits: 1) - 1) & 0x20) != 0;
  v39 = *v23;
  *v36 = (v38 << 6) & 0x40 | *v36 & 0xBF;
  v40 = (v39 & 4) != 0;
  v41 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v41, value: (v39 & 4) != 0, numBits: 1);
  else
    v40 = (_cntlzw(idBitMsg::ReadBits(this: v41, numBits: 1) - 1) & 0x20) != 0;
  v42 = (4 * v40) & 4 | *v23 & 0xFB;
  *v23 = v42;
  v43 = (v42 & 2) != 0;
  v44 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v44, value: (v42 & 2) != 0, numBits: 1);
  else
    v43 = (_cntlzw(idBitMsg::ReadBits(this: v44, numBits: 1) - 1) & 0x20) != 0;
  v45 = (2 * v43) & 2 | *v23 & 0xFD;
  *v23 = v45;
  v46 = v45 & 1;
  v47 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v47, value: v45 & 1, numBits: 1);
  else
    v46 = (_cntlzw(idBitMsg::ReadBits(this: v47, numBits: 1) - 1) & 0x20) != 0;
  v48 = *v23 & 0xFE | v46 & 1;
  v49 = (*v36 & 0x20) != 0;
  *v23 = v48;
  v50 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v50, value: v49, numBits: 1);
  else
    v49 = (_cntlzw(idBitMsg::ReadBits(this: v50, numBits: 1) - 1) & 0x20) != 0;
  v51 = this->__vftable;
  *v36 = (32 * v49) & 0x20 | *v36 & 0xDF;
  if ( v51->IsLocallyControlled(this) && ser->writing )
    *v36 = (16 * ((int (__fastcall *)(idCommon *))common->IsGamePaused)(a1: common)) & 0x10 | *v36 & 0xEF;
  v52 = ser->msg;
  v53 = (*v36 & 0x10) != 0;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v52, value: (*v36 & 0x10) != 0, numBits: 1);
  else
    v53 = (_cntlzw(idBitMsg::ReadBits(this: v52, numBits: 1) - 1) & 0x20) != 0;
  *v36 = (16 * v53) & 0x10 | *v36 & 0xEF;
  p_respawn = &this->respawn;
  count = this->respawn.count;
  if ( count >= 7 )
    idLib::Warning(fmt: "netBoolEvent_t. count %d > max %d", count, 7);
  v56 = ser->msg;
  v57 = _cntlzw(7u);
  v58 = 32 - v57;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v56, value: p_respawn->count, numBits: 32 - v57);
  else
    p_respawn->count = idBitMsg::ReadBits(this: v56, numBits: 32 - v57);
  p_teleported = &this->teleported;
  v60 = this->teleported.count;
  if ( v60 >= 7 )
    idLib::Warning(fmt: "netBoolEvent_t. count %d > max %d", v60, 7);
  v61 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v61, value: p_teleported->count, numBits: v58);
  else
    p_teleported->count = idBitMsg::ReadBits(this: v61, numBits: v58);
  p_vehicleExited = &this->vehicleExited;
  v63 = this->vehicleExited.count;
  if ( v63 >= 7 )
    idLib::Warning(fmt: "netBoolEvent_t. count %d > max %d", v63, 7);
  v64 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v64, value: p_vehicleExited->count, numBits: v58);
  else
    p_vehicleExited->count = idBitMsg::ReadBits(this: v64, numBits: v58);
  idSerializer::Serialize<idDeclPlayerProps>(this: ser, decl: &this->playerProps);
  idHands::Serialize(this: &this->hands, ser);
  v65 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v65, value: this->calloutHistoryIndex, numBits: 32);
  else
    this->calloutHistoryIndex = idBitMsg::ReadBits(this: v65, numBits: 32);
  p_scoreIndex = &this->calloutHistory[0].scoreIndex;
  for ( j = 4; j != 0; --j )
  {
    idSerializer::Serialize<idDeclOnlineScoringCallout>(this: ser, decl: (const idDecl **)p_scoreIndex - 1);
    v68 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v68, value: *p_scoreIndex, numBits: 32);
    else
      *p_scoreIndex = idBitMsg::ReadBits(this: v68, numBits: 32);
    p_scoreIndex += 2;
  }
  v69 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v69, value: this->coopScoringIndex, numBits: 32);
  else
    this->coopScoringIndex = idBitMsg::ReadBits(this: v69, numBits: 32);
  p_score = &this->coopScoreHistory[0].score;
  for ( k = 4; k != 0; --k )
  {
    v72 = p_score - 4;
    v73 = ser->msg;
    v74 = 3;
    if ( ser->writing )
    {
      do
      {
        v104[0] = *++v72;
        idBitMsg::WriteBits(this: v73, value: v104[0], numBits: 32);
        --v74;
      }
      while ( v74 != 0 );
    }
    else
    {
      do
      {
        --v74;
        *++v72 = idBitMsg::ReadBits(this: v73, numBits: 32);
      }
      while ( v74 != 0 );
    }
    v75 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v75, value: *p_score, numBits: 32);
    else
      *p_score = idBitMsg::ReadBits(this: v75, numBits: 32);
    p_score += 6;
  }
  if ( !common->TimeTrialPlaying(this: common)
    && !common->TimeTrialRecording(this: common)
    && !common->DemoPlaying(this: common)
    && !common->DemoRecording(this: common)
    && (common->SnapshotState(this: common) != SNAP_WRITING || !this->IsLocallyControlled(this)) )
  {
    if ( common->SnapshotState(this: common) != SNAP_READING || this->IsLocallyControlled(this) )
    {
      v76 = ser->msg;
      p_damageFeedbackBufferPos = &this->damageFeedbackBufferPos;
      damageFeedbackBufferPos = this->damageFeedbackBufferPos;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v76, value: this->damageFeedbackBufferPos, numBits: 32);
      else
        damageFeedbackBufferPos = idBitMsg::ReadBits(this: v76, numBits: 32);
      v79 = 10;
      p_attacker = &this->damageFeedback[0].attacker;
      do
      {
        v81 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteBits(this: v81, value: p_attacker->spawnId, numBits: 32);
        else
          p_attacker->spawnId = idBitMsg::ReadBits(this: v81, numBits: 32);
        idSerializer::Serialize<idDeclDamage>(this: ser, decl: (const idDecl **)&p_attacker[-1]);
        v82 = ser->msg;
        if ( ser->writing )
        {
          v104[0] = p_attacker[-2].spawnId;
          idBitMsg::WriteBits(this: v82, value: v104[0], numBits: 32);
        }
        else
        {
          p_attacker[-2].spawnId = idBitMsg::ReadBits(this: v82, numBits: 32);
        }
        v83 = (idVec3 *)&p_attacker[1];
        v84 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v84, v: v83);
        else
          idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v84, v: v83);
        v85 = (idVec3 *)&p_attacker[4];
        v86 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v86, v: v85);
        else
          idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v86, v: v85);
        v87 = (idVec3 *)&p_attacker[7];
        v88 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v88, v: v87);
        else
          idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v88, v: v87);
        v89 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteBits(this: v89, value: p_attacker[10].spawnId, numBits: 32);
        else
          p_attacker[10].spawnId = idBitMsg::ReadBits(this: v89, numBits: 32);
        --v79;
        p_attacker += 13;
      }
      while ( v79 != 0 );
      v90 = *p_damageFeedbackBufferPos;
      v91 = damageFeedbackBufferPos - *p_damageFeedbackBufferPos;
      this->serializeDamageFeedbackCount = v91;
      if ( v91 > 10 )
      {
        idLib::Warning(
          fmt: "Too many player damage feedback serialized [damageFeedbackBufferPos %d -> newDamageFeedbackBufferPos %d ] (%d)"
          ", dropping all but last %d!",
          v90,
          damageFeedbackBufferPos,
          v91,
          10);
        *p_damageFeedbackBufferPos = damageFeedbackBufferPos - 10;
        this->serializeDamageFeedbackCount = 10;
      }
      damageDealtBuffer = this->damageDealtBuffer;
      for ( m = 4; m != 0; --m )
      {
        v94 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteBits(this: v94, value: damageDealtBuffer->victim.spawnId, numBits: 32);
        else
          damageDealtBuffer->victim.spawnId = idBitMsg::ReadBits(this: v94, numBits: 32);
        ++damageDealtBuffer;
      }
      v95 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v95, value: this->damageDealtBufferIndex, numBits: 32);
      else
        this->damageDealtBufferIndex = idBitMsg::ReadBits(this: v95, numBits: 32);
      v96 = ser->msg;
      p_roverBombSoundCounter = &this->roverBombSoundCounter;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v96, value: *p_roverBombSoundCounter, numBits: 32);
      else
        *p_roverBombSoundCounter = idBitMsg::ReadBits(this: v96, numBits: 32);
    }
    else
    {
      this->physicsObj.SetOrigin(this: &this->physicsObj, a2: &this->origin, a3: -1);
    }
  }
}


// ========================================================================
// ?RemoveControl@idPresentablePlayer@@QAAXPAVidPresentable@@@Z
// EA  : 0x82B7C370
// RVA : 0x00B7C370
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::RemoveControl(idPresentablePlayer *this, idPresentable *control)
{
  int *p_num; // r23
  int v5; // r28
  int v6; // r29
  idList<idEntityPtr<idEntity>,58> *p_controlledPresentables; // r26
  idEntityPtr<idEntity> *list; // r30
  int value; // r11
  int v10; // r31
  idPresentable *PresentableByIndex; // r31
  idPresentablePtr<idPresentable> *v12; // r31
  unsigned int spawnId; // r11
  int v14; // r30
  idPresentable *v15; // r3

  if ( control != nullptr )
  {
    p_num = &this->controlledPresentables.num;
    v5 = this->controlledPresentables.num - 1;
    if ( v5 >= 0 )
    {
      v6 = v5;
      p_controlledPresentables = (idList<idEntityPtr<idEntity>,58> *)&this->controlledPresentables;
      while ( 1 )
      {
        list = p_controlledPresentables->list;
        value = p_controlledPresentables->list[v6].spawnId.value;
        v10 = value & 0x3FFF;
        if ( value == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: value & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v10))->spawnId != list[v6].spawnId.value )
        {
          PresentableByIndex = nullptr;
        }
        if ( control == PresentableByIndex )
          break;
        --v5;
        --v6;
        if ( v5 < 0 )
          goto LABEL_12;
      }
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_controlledPresentables, index: v5);
      idPresentablePlayer::DetachController(this, control: PresentableByIndex);
    }
LABEL_12:
    if ( *p_num > 0 )
    {
      v12 = &this->controlledPresentables.list[*p_num];
      spawnId = v12[-1].spawnId;
      v14 = spawnId & 0x3FFF;
      if ( spawnId != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
      {
        v15 = idClientGame::GetPresentableByIndex(this: clientGame, index: v14);
        if ( v15->spawnId == v12[-1].spawnId )
        {
          v15->controller.spawnId = this->spawnId;
          this->isTurretControl = idProp_WeaponStatic::CastTo(c: (idProp_WeaponStatic *)v15->entity) != nullptr;
          idPresentablePlayer::HandleUserCmds(this, newcmd: &this->ucmdTracker2.usercmd);
        }
      }
    }
  }
}


// ========================================================================
// ?ResetControl@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B7C4D0
// RVA : 0x00B7C4D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ResetControl(idPresentablePlayer *this)
{
  int v2; // r28
  int v3; // r30
  idList<idPresentablePtr<idPresentable>,5> *p_controlledPresentables; // r25
  idPresentablePtr<idPresentable> *list; // r29
  unsigned int spawnId; // r11
  int v7; // r31
  idPresentable *PresentableByIndex; // r31
  idList<idPresentablePtr<idPresentable>,5> *v9; // r31

  v2 = this->controlledPresentables.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    p_controlledPresentables = &this->controlledPresentables;
    do
    {
      list = p_controlledPresentables->list;
      spawnId = p_controlledPresentables->list[v3].spawnId;
      v7 = spawnId & 0x3FFF;
      if ( spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != list[v3].spawnId )
      {
        PresentableByIndex = nullptr;
      }
      idPresentablePlayer::RemoveControl(this, control: PresentableByIndex);
      PresentableByIndex->ControlReleased(this: PresentableByIndex);
      --v2;
      PresentableByIndex->controller.spawnId = 0;
      --v3;
    }
    while ( v2 >= 0 );
  }
  v9 = &this->controlledPresentables;
  if ( this->controlledPresentables.listStatic == 0 || this->controlledPresentables.listStatic == 2 )
  {
    if ( v9->list != nullptr )
      idMem::Free(this: &mem, ptr: v9->list, align: ALIGN_16);
    v9->list = nullptr;
    this->controlledPresentables.size = 0;
  }
  this->controlledPresentables.num = 0;
  this->isTurretControl = false;
}


// ========================================================================
// ?ShowTutorialGui@idPresentablePlayer@@QAA_NPBVidDeclTutorialEvent@@PAVidEntity@@@Z
// EA  : 0x82B7C5E8
// RVA : 0x00B7C5E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

int __fastcall idPresentablePlayer::ShowTutorialGui(
        idPresentablePlayer *this,
        idSWF *decl,
        idResourceList *activatingEntity)
{
  idDeclTutorialEvent::tutorialSpecialType_t str; // r11
  idSWF *PlayerGui; // r30
  const idDeclTutorialEvent *currentTutorialGuiDecl; // r11
  idLocalUser *LocalUserFromPlayerIndex; // r3
  idSWFScriptFunction *v11; // r3
  idEntity *entity; // r11
  idSWFScriptFunction *v13; // r4
  int mainspriteInstance; // r28
  idInventoryCollection *v15; // r27
  int v16; // r28
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  idStrId *InventoryItemForQuickSlot; // r3
  idSWFScriptVar *v21; // r3
  va *v22; // r3
  const char *LocalizedString; // r3
  __int64 v24; // r6
  __int64 v25; // r10
  __int64 v26; // r8
  va *v27; // r3
  int atlasMaterial; // r28
  const idDeclTutorialEvent *v29; // r28
  idStr *v30; // r3
  idSWFScriptFunction *v31; // r3
  idSWFScriptFunction *v32; // r4
  idSWFScriptVar *v33; // r3
  const idMaterial *shortcutKeys; // r11
  idSWFScriptVar *v35; // r3
  idDeclTutorialEvent::tutorialType_t soundEmitter; // r28
  idEntity *v37; // r11
  idEntity *v38; // r3
  int v39; // [sp+8h] [-21C8h]
  int v40; // [sp+8h] [-21C8h]
  int v41; // [sp+Ch] [-21C4h]
  int v42; // [sp+Ch] [-21C4h]
  int v43; // [sp+10h] [-21C0h]
  int v44; // [sp+10h] [-21C0h]
  int v45; // [sp+14h] [-21BCh]
  int v46; // [sp+14h] [-21BCh]
  int v47; // [sp+18h] [-21B8h]
  int v48; // [sp+18h] [-21B8h]
  int v49; // [sp+1Ch] [-21B4h]
  int v50; // [sp+1Ch] [-21B4h]
  idStrId v51[2]; // [sp+50h] [-2180h] BYREF
  idSWFScriptVar v52; // [sp+58h] [-2178h] BYREF
  idSWFScriptVar v53; // [sp+60h] [-2170h] BYREF
  idSWFScriptVar v54; // [sp+68h] [-2168h] BYREF
  idStrId v55; // [sp+70h] [-2160h] BYREF
  idSWFScriptVar v56; // [sp+78h] [-2158h] BYREF
  idSWFScriptVar v57; // [sp+80h] [-2150h] BYREF
  idSWFScriptVar v58; // [sp+88h] [-2148h] BYREF
  idSWFScriptVar v59; // [sp+90h] [-2140h] BYREF
  idSWFScriptVar v60; // [sp+98h] [-2138h] BYREF
  idSWFScriptVar v61; // [sp+A0h] [-2130h] BYREF
  idSWFScriptVar v62; // [sp+A8h] [-2128h] BYREF
  idSWFScriptVar v63[2]; // [sp+B0h] [-2120h] BYREF
  idStr v64; // [sp+C0h] [-2110h] BYREF
  idStr v65; // [sp+E0h] [-20F0h] BYREF
  idStr v66; // [sp+100h] [-20D0h] BYREF
  idStr v67; // [sp+120h] [-20B0h] BYREF
  idStr v68; // [sp+140h] [-2090h] BYREF
  va v69; // [sp+160h] [-2070h] BYREF
  va v70; // [sp+1160h] [-1070h] BYREF

  if ( decl == nullptr )
    return 0;
  str = (idDeclTutorialEvent::tutorialSpecialType_t)decl->atlasTextureName.str;
  if ( str == TUTORIAL_SPECIAL_CROUCH )
  {
    if ( idPresentablePlayer::IsCrouching(this) )
      return 0;
  }
  else if ( str == TUTORIAL_SPECIAL_VEHICLE )
  {
    if ( idPresentablePlayer::GetVehicle(this) == nullptr )
      return 0;
  }
  else if ( str == TUTORIAL_SPECIAL_NONVEHICLE && idPresentablePlayer::GetVehicle(this) != nullptr )
  {
    return 0;
  }
  PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_TUTORIAL);
  if ( PlayerGui->isActive )
  {
    currentTutorialGuiDecl = this->currentTutorialGuiDecl;
    if ( currentTutorialGuiDecl != nullptr
      && decl->textInstanceAllocator.allowAllocs
      && !currentTutorialGuiDecl->lowPriorityTutorial )
    {
      return 0;
    }
  }
  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
  if ( LocalUserFromPlayerIndex != nullptr )
    PlayerGui->userDeviceNumber = LocalUserFromPlayerIndex->GetInputDevice(this: LocalUserFromPlayerIndex);
  else
    PlayerGui->userDeviceNumber = 0;
  v11 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x18u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
  {
    entity = this->entity;
    v11[2].__vftable = (idSWFScriptFunction_vtbl *)PlayerGui;
    v13 = v11;
    v11[3].__vftable = (idSWFScriptFunction_vtbl *)activatingEntity;
    v11[5].__vftable = (idSWFScriptFunction_vtbl *)decl;
    v11[1].__vftable = nullptr;
    v11->__vftable = (idSWFScriptFunction_vtbl *)&`idPresentablePlayer::ShowTutorialGui'::`31'::idSWFScriptFunction_DeactivateCallback::`vftable';
    v11[4].__vftable = (idSWFScriptFunction_vtbl *)entity;
  }
  else
  {
    v13 = nullptr;
  }
  idSWFScriptVar::idSWFScriptVar(this: &v58, nf: v13);
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "closeTutorial", value: &v58);
  idSWFScriptVar::Free(this: &v58);
  v52.type = SWF_VAR_UNDEF;
  mainspriteInstance = (int)decl->mainspriteInstance;
  idSWFScriptVar::Free(this: &v52);
  v52.value.i = mainspriteInstance;
  v52.type = SWF_VAR_STRINGID;
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "headingText", value: &v52);
  idSWFScriptVar::Free(this: &v52);
  idStr::idStr(this: &v66, text: (const idStr *)&decl->atlasImage);
  if ( decl->atlasTextureName.str != (const char *)5 )
  {
    v51[0] = (idStrId)decl->globals;
    idSWFScriptVar::idSWFScriptVar(this: &v60, s: v51);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "bodyText", value: &v60);
    v21 = &v60;
    goto _M505927;
  }
  v15 = this->GetInventory(this);
  if ( v15 == nullptr )
    goto LABEL_27;
  v16 = 0;
  while ( 1 )
  {
    InventoryItemForQuickSlot = (idStrId *)idInventoryCollection::GetInventoryItemForQuickSlot(
                                             this: v15,
                                             slotGroup: QUICKSLOTGROUP_ITEM,
                                             slot: v16,
                                             numSlots: 4);
    if ( InventoryItemForQuickSlot != nullptr )
    {
      v51[0] = InventoryItemForQuickSlot[3];
      if ( v51[0].index != 0 )
      {
        LODWORD(v17) = decl->textInstanceAllocator.active;
        if ( v51[0].index == (_DWORD)v17 )
          break;
      }
    }
    if ( ++v16 >= 4 )
      goto LABEL_27;
  }
  if ( v16 == -1 )
  {
LABEL_27:
    v51[0] = (idStrId)decl->globals;
    idSWFScriptVar::idSWFScriptVar(this: &v62, s: v51);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "bodyText", value: &v62);
    v21 = &v62;
_M505927:
    idSWFScriptVar::Free(this: v21);
    goto LABEL_32;
  }
  HIDWORD(v19) = v16;
  v22 = va::va(
          this: &v69,
          fmt: "_quick%d",
          a3: v19,
          a4: v18,
          a5: v17,
          a6: v39,
          a7: v41,
          a8: v43,
          a9: v45,
          a10: v47,
          a11: v49);
  idStr::idStr(this: &v65, text: v22);
  idStr::operator=(this: &v66, text: &v65);
  v55.index = (int)decl->globals;
  LocalizedString = idStrId::GetLocalizedString(this: &v55);
  idStr::idStr(this: &v68, text: LocalizedString);
  HIDWORD(v24) = v65.data;
  v27 = va::va(
          this: &v70,
          fmt: v68.data,
          a3: v24,
          a4: v26,
          a5: v25,
          a6: v40,
          a7: v42,
          a8: v44,
          a9: v46,
          a10: v48,
          a11: v50);
  idStr::idStr(this: &v67, text: v27);
  idSWFScriptVar::idSWFScriptVar(this: v63, s: &v67);
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "bodyText", value: v63);
  idSWFScriptVar::Free(this: v63);
  idStr::FreeData(this: &v67);
  idStr::FreeData(this: &v68);
  idStr::FreeData(this: &v65);
LABEL_32:
  v53.type = SWF_VAR_UNDEF;
  atlasMaterial = (int)decl->atlasMaterial;
  idSWFScriptVar::Free(this: &v53);
  v53.value.i = atlasMaterial;
  v53.type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "bindSet", value: &v53);
  idSWFScriptVar::Free(this: &v53);
  if ( decl->soundEmitter == (idSoundEmitter *)3 )
  {
    v29 = (const idDeclTutorialEvent *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x38u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
    v51[0].index = (int)v29;
    if ( v29 != nullptr )
    {
      v30 = idStr::idStr(this: &v64, text: &v66);
      _idPresentablePlayer::ShowTutorialGui_::_32_::idSWFScriptFunction_waitInput::idSWFScriptFunction_waitInput(
        _decl: v29,
        _gui: decl,
        _activatingEntity: (idResource *)PlayerGui,
        _player: activatingEntity,
        _actionCheck: (idStr *)this->entity,
        a6: v30);
      v32 = v31;
    }
    else
    {
      v32 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v56, nf: v32);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "waitInput", value: &v56);
    v33 = &v56;
  }
  else
  {
    idSWFScriptVar::idSWFScriptVar(this: &v59, s: &byte_8200D768);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "waitInput", value: &v59);
    v33 = &v59;
  }
  idSWFScriptVar::Free(this: v33);
  shortcutKeys = (const idMaterial *)decl->shortcutKeys;
  if ( shortcutKeys != nullptr )
  {
    idSWFScriptVar::idSWFScriptVar(this: &v61, s: shortcutKeys->name.str);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "tutorialImg", value: &v61);
    v35 = &v61;
  }
  else
  {
    idSWFScriptVar::idSWFScriptVar(this: &v57, s: &byte_8200D768);
    idSWFScriptObject::Set(this: PlayerGui->globals, name: "tutorialImg", value: &v57);
    v35 = &v57;
  }
  idSWFScriptVar::Free(this: v35);
  v54.type = SWF_VAR_UNDEF;
  soundEmitter = (idDeclTutorialEvent::tutorialType_t)decl->soundEmitter;
  idSWFScriptVar::Free(this: &v54);
  v54.value.i = soundEmitter;
  v54.type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "type", value: &v54);
  idSWFScriptVar::Free(this: &v54);
  if ( PlayerGui->isActive )
    idSWF::Activate(this: PlayerGui, b: false);
  idSWF::Activate(this: PlayerGui, b: true);
  v37 = this->entity;
  this->currentTutorialGuiDecl = (const idDeclTutorialEvent *)decl;
  if ( v37 != nullptr
    && common->IsServer(this: common)
    && decl->textInstanceAllocator.clearAllocs
    && (int)decl->orphanedSprites.list > 0 )
  {
    v64.data = (char *)decl;
    v38 = this->entity;
    HIBYTE(v64.len) = 100;
    idEventReceiver::PostEventMS(
      this: v38,
      ev: &EV_EndSpecificTutorial,
      time: v64.len,
      arg1: (const idEventArg *)v64.allocedAndFlag);
  }
  idStr::FreeData(this: &v66);
  return 1;
}


// ========================================================================
// __unwind$505642
// EA  : 0x82B7CB84
// RVA : 0x00B7CB84
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505642()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 136));
}


// ========================================================================
// __unwind$505643
// EA  : 0x82B7CBAC
// RVA : 0x00B7CBAC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505643()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 88));
}


// ========================================================================
// __unwind$505644
// EA  : 0x82B7CBD4
// RVA : 0x00B7CBD4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505644()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8656 + 256));
}


// ========================================================================
// __unwind$505649
// EA  : 0x82B7CBFC
// RVA : 0x00B7CBFC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505649()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 168));
}


// ========================================================================
// __unwind$505645
// EA  : 0x82B7CC24
// RVA : 0x00B7CC24
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505645()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8656 + 224));
}


// ========================================================================
// __unwind$505646
// EA  : 0x82B7CC4C
// RVA : 0x00B7CC4C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505646()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8656 + 320));
}


// ========================================================================
// __unwind$505647
// EA  : 0x82B7CC74
// RVA : 0x00B7CC74
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505647()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8656 + 288));
}


// ========================================================================
// __unwind$505648
// EA  : 0x82B7CC9C
// RVA : 0x00B7CC9C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505648()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 176));
}


// ========================================================================
// __unwind$505650
// EA  : 0x82B7CCC4
// RVA : 0x00B7CCC4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505650()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 152));
}


// ========================================================================
// __unwind$505651
// EA  : 0x82B7CCEC
// RVA : 0x00B7CCEC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505651()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 96));
}


// ========================================================================
// __unwind$505652
// EA  : 0x82B7CD14
// RVA : 0x00B7CD14
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall _unwind_505652(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 8656 + 80), tag: a2);
}


// ========================================================================
// __unwind$505654
// EA  : 0x82B7CD3C
// RVA : 0x00B7CD3C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505654()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 120));
}


// ========================================================================
// __unwind$505655
// EA  : 0x82B7CD64
// RVA : 0x00B7CD64
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505655()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 144));
}


// ========================================================================
// __unwind$505656
// EA  : 0x82B7CD8C
// RVA : 0x00B7CD8C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505656()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 160));
}


// ========================================================================
// __unwind$505657
// EA  : 0x82B7CDB4
// RVA : 0x00B7CDB4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505657()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 128));
}


// ========================================================================
// __unwind$505658
// EA  : 0x82B7CDDC
// RVA : 0x00B7CDDC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_505658()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 8656 + 104));
}


// ========================================================================
// ?DrawGuis@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B7CE10
// RVA : 0x00B7CE10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::DrawGuis(idPresentablePlayer *this, int id)
{
  idGameLocal *v4; // r10
  idSWF *v5; // r11
  idSWFScriptVar **v6; // r29
  idSWFScriptObject *v7; // r30
  idSWFSpriteInstance *v8; // r3
  bool isActive; // r10
  idSWF *v10; // r11
  int GameMs; // r3
  const char *v12; // r7
  bool v13; // r10
  idSWF *v14; // r11
  idSWFSpriteInstance *v15; // r30
  bool v16; // r4
  int v17; // r3
  const char *v18; // r7
  int v19; // r29
  idSWF **loadedGuis; // r30
  int v21; // r3
  const char *v22; // r7
  idSWF *v23; // r11
  idSWF **v24; // r30
  bool v25; // r10
  idSWF *v26; // r29
  char v27; // r11
  int v28; // r3
  const char *v29; // r7
  idSWFScriptVar v30; // [sp+58h] [-C8h] BYREF
  idSWFScriptObject v31[2]; // [sp+60h] [-C0h] BYREF

  if ( this->IsLocallyControlled(this) )
  {
    v4 = gameLocal;
    if ( gameLocal != nullptr )
    {
      if ( this->isGeneralGuiCardGame )
      {
        v5 = this->loadedGuis[8];
        v6 = (idSWFScriptVar **)&this->loadedGuis[8];
        if ( v5 != nullptr && v5->isActive )
        {
          idStr::idStr(this: (idStr *)&v31[0].variablesHash[15], text: v5->filename.str);
          idStr::StripPath(this: (idStr *)&v31[0].variablesHash[15]);
          idStr::StripFileExtension(this: (idStr *)&v31[0].variablesHash[15]);
          if ( idStr::Icmp(s1: (const char *)v31[0].prototype, s2: "crossroads") == 0 )
          {
            v7 = *(idSWFScriptObject **)((*v6)[8].type + 40);
            if ( gameLocal->MainMenu_IsActive(this: gameLocal) )
            {
              idSWFScriptObject::Get(this: (idSWFScriptObject *)&v31[0].variables.num, result: v7, name: "deckBuilder");
              if ( v31[0].variables.num == 8 )
              {
                idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v31[0].variablesHash[3], i: nullptr);
                idSWFScriptObject::Set(
                  this: (idSWFScriptObject *)v31[0].variables.size,
                  name: "onEnterFrame",
                  value: (idSWFScriptVar *)&v31[0].variablesHash[3]);
                idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[3]);
              }
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variables.num);
            }
            idSWFScriptObject::Get(
              this: (idSWFScriptObject *)&v31[0].variablesHash[7],
              result: v7,
              name: "diffSelector");
            v8 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v31[0].variablesHash[7]);
            if ( v8 != nullptr && v8->currentFrame == 11 )
            {
              idSWF::GetGlobal(this: (idSWF *)&v30, result: *v6, name: "shortcutKeys");
              if ( v30.type == SWF_VAR_OBJECT )
              {
                idSWFScriptObject::Get(
                  this: (idSWFScriptObject *)&v31[0].variablesHash[5],
                  result: v30.value.object,
                  name: "JOY2");
                idSWFScriptObject::Set(
                  this: v30.value.object,
                  name: "BACKSPACE",
                  value: (idSWFScriptVar *)&v31[0].variablesHash[5]);
                idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[5]);
              }
              idSWFScriptVar::Free(this: &v30);
            }
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[7]);
          }
          idStr::FreeData(this: (idStr *)&v31[0].variablesHash[15]);
          v4 = gameLocal;
        }
      }
      if ( g_showGuis.valueInteger != 0 )
      {
        if ( !idMainMenu::IsActive(this: v4->mainMenu) )
        {
          isActive = false;
          v10 = this->loadedGuis[17];
          if ( v10 != nullptr )
            isActive = v10->isActive;
          if ( isActive && v10 != nullptr )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idSWF::Render(
              this: this->loadedGuis[17],
              gui: this->view.guiModel,
              time: GameMs,
              isSplitscreen: false,
              a5: v12);
          }
          v13 = false;
          v14 = this->loadedGuis[16];
          if ( v14 != nullptr )
            v13 = v14->isActive;
          if ( v13 )
          {
            if ( v14 != nullptr )
            {
              idSWFScriptObject::Get(this: v31, result: v14->mainspriteInstance->scriptObject, name: "item3");
              if ( v31[0].refCount == 8 )
              {
                idSWFScriptObject::Get(
                  this: (idSWFScriptObject *)&v31[0].variablesHash[11],
                  result: (idSWFScriptObject *)v31[0].variables.list,
                  name: "desc_scroll");
                v15 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v31[0].variablesHash[11]);
                idSWFScriptObject::Get(
                  this: (idSWFScriptObject *)&v31[0].variablesHash[1],
                  result: (idSWFScriptObject *)v31[0].variables.list,
                  name: "mc_desc");
                if ( v31[0].variablesHash[1] == 8 && v15 != nullptr )
                {
                  idSWFScriptObject::Get(
                    this: (idSWFScriptObject *)&v31[0].variables.granularity,
                    result: (idSWFScriptObject *)v31[0].variablesHash[2],
                    name: "desc");
                  if ( *(_DWORD *)&v31[0].variables.granularity == 8 )
                  {
                    idSWFScriptObject::Get(
                      this: (idSWFScriptObject *)&v31[0].variablesHash[9],
                      result: (idSWFScriptObject *)v31[0].variablesHash[0],
                      name: "maxscroll");
                    v16 = idSWFScriptVar::ToInteger(this: (idSWFScriptVar *)&v31[0].variablesHash[9]) > 0;
                    idSWFSpriteInstance::SetVisible(this: v15, visible: v16);
                    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[9]);
                  }
                  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variables.granularity);
                }
                idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[1]);
                idSWFScriptVar::Free(this: (idSWFScriptVar *)&v31[0].variablesHash[11]);
              }
              v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              idSWF::Render(
                this: this->loadedGuis[16],
                gui: this->view.guiModel,
                time: v17,
                isSplitscreen: false,
                a5: v18);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)v31);
            }
          }
          else
          {
            v19 = 0;
            loadedGuis = this->loadedGuis;
            do
            {
              if ( *loadedGuis != nullptr && v19 != 15 && v19 != 8 )
              {
                idSWF::SetListener(this: *loadedGuis, id);
                v21 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                idSWF::Render(this: *loadedGuis, gui: this->view.guiModel, time: v21, isSplitscreen: false, a5: v22);
              }
              ++v19;
              ++loadedGuis;
            }
            while ( v19 < 21 );
          }
        }
        v23 = this->loadedGuis[8];
        v24 = &this->loadedGuis[8];
        v25 = false;
        if ( v23 != nullptr )
          v25 = v23->isActive;
        if ( v25
          && v23 != nullptr
          && (v23->pausedRender && gameLocal->GetGamePaused(this: gameLocal)
           || !gameLocal->GetGamePaused(this: gameLocal)) )
        {
          if ( (*v24)->paused || !gameLocal->GetGamePaused(this: gameLocal) )
          {
            if ( !(*v24)->paused || gameLocal->GetGamePaused(this: gameLocal) )
              goto LABEL_57;
            v26 = *v24;
            idSWFSpriteInstance::Play(this: (*v24)->mainspriteInstance);
            v27 = 0;
          }
          else
          {
            v26 = *v24;
            idSWFSpriteInstance::Stop(this: (*v24)->mainspriteInstance);
            v27 = 1;
          }
          v26->paused = v27;
LABEL_57:
          v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idSWF::Render(this: *v24, gui: this->view.guiModel, time: v28, isSplitscreen: false, a5: v29);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$506017
// EA  : 0x82B7D340
// RVA : 0x00B7D340
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506017()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 176));
}


// ========================================================================
// __unwind$506018
// EA  : 0x82B7D368
// RVA : 0x00B7D368
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506018()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 104));
}


// ========================================================================
// __unwind$506019
// EA  : 0x82B7D390
// RVA : 0x00B7D390
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506019()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$506020
// EA  : 0x82B7D3B8
// RVA : 0x00B7D3B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506020()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$506021
// EA  : 0x82B7D3E0
// RVA : 0x00B7D3E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506021()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 88));
}


// ========================================================================
// __unwind$506022
// EA  : 0x82B7D408
// RVA : 0x00B7D408
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506022()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 136));
}


// ========================================================================
// __unwind$506023
// EA  : 0x82B7D430
// RVA : 0x00B7D430
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506023()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$506024
// EA  : 0x82B7D458
// RVA : 0x00B7D458
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506024()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$506025
// EA  : 0x82B7D480
// RVA : 0x00B7D480
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506025()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 120));
}


// ========================================================================
// __unwind$506026
// EA  : 0x82B7D4A8
// RVA : 0x00B7D4A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506026()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$506027
// EA  : 0x82B7D4D0
// RVA : 0x00B7D4D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506027()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 152));
}


// ========================================================================
// ??0idPresentablePlayer@@QAA@PAVidPlayer@@PAVidRenderModel@@PAVidAnimStack@@PAVidInventoryCollection@@PBVidDeclPlayerProps@@H@Z
// EA  : 0x82B7D6D0
// RVA : 0x00B7D6D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::idPresentablePlayer(
        idPresentablePlayer *this,
        idPlayer *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_,
        idInventoryCollection *inv,
        const idDeclPlayerProps *props,
        int entityNum_)
{
  bool v12; // r3
  float z; // r7
  float v14; // r10
  idPresentablePlayer::moveBufferItem_t *moveBuffer; // r26
  int i; // r27
  float v17; // r7
  float v18; // r5
  float v19; // r8
  float v20; // r24
  float v21; // r7
  float v22; // r7
  float v23; // r5
  float v24; // r5
  float v25; // r5
  float v26; // r10
  double currentValue; // fp0
  double v28; // fp13
  double v29; // fp12

  v12 = common->IsMultiplayer(this: common);
  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent,
    renderModel_,
    animStack_,
    entityNumber_: entityNum_,
    fxDecl_: nullptr,
    useSphereModel_: v12);
  this->__vftable = (idPresentablePlayer_vtbl *)&idPresentableActor::`vftable';
  idActorModifierManager::idActorModifierManager(this: &this->predictedActorModifierManager);
  this->actorModifierManager = &this->predictedActorModifierManager;
  this->overdrivePoints = 0.0;
  this->__vftable = (idPresentablePlayer_vtbl *)&idPresentablePlayer::`vftable';
  this->damageDealtBuffer[0].victim.spawnId = 0;
  this->damageDealtBuffer[1].victim.spawnId = 0;
  this->damageDealtBuffer[2].victim.spawnId = 0;
  this->damageDealtBuffer[3].victim.spawnId = 0;
  this->calloutHistory[0].callout = nullptr;
  this->calloutHistory[0].scoreIndex = 0;
  this->calloutHistory[1].callout = nullptr;
  this->calloutHistory[1].scoreIndex = 0;
  this->calloutHistory[2].callout = nullptr;
  this->calloutHistory[2].scoreIndex = 0;
  this->calloutHistory[3].callout = nullptr;
  this->calloutHistory[3].scoreIndex = 0;
  this->coopScoreHistory[0].worldPosition.x = vec3_origin.x;
  this->coopScoreHistory[0].worldPosition.y = vec3_origin.y;
  z = vec3_origin.z;
  this->coopScoreHistory[0].score = 0;
  this->coopScoreHistory[0].time = 0;
  this->coopScoreHistory[0].index = 0;
  this->coopScoreHistory[0].worldPosition.z = z;
  this->coopScoreHistory[1].worldPosition.x = vec3_origin.x;
  this->coopScoreHistory[1].worldPosition.y = vec3_origin.y;
  v14 = vec3_origin.z;
  this->coopScoreHistory[1].score = 0;
  this->coopScoreHistory[1].worldPosition.z = v14;
  this->coopScoreHistory[1].time = 0;
  this->coopScoreHistory[1].index = 0;
  this->coopScoreHistory[2].worldPosition = vec3_origin;
  this->coopScoreHistory[2].score = 0;
  this->coopScoreHistory[2].time = 0;
  this->coopScoreHistory[2].index = 0;
  this->coopScoreHistory[3].worldPosition = vec3_origin;
  this->coopScoreHistory[3].score = 0;
  this->coopScoreHistory[3].time = 0;
  this->coopScoreHistory[3].index = 0;
  this->coopLegendTitle.index = -1;
  this->screenPrtState.size = 5;
  this->screenPrtState.num = 0;
  this->screenPrtState.granularity = 1;
  this->screenPrtState.list = this->screenPrtState.staticList;
  this->screenPrtState.memTag = 5;
  this->screenPrtState.listStatic = 1;
  this->screenPrtState.staticList[0].excludeAngle = 0.0;
  this->screenPrtState.staticList[1].excludeAngle = 0.0;
  this->screenPrtState.staticList[2].excludeAngle = 0.0;
  this->screenPrtState.staticList[3].excludeAngle = 0.0;
  this->screenPrtState.staticList[0].pModel = nullptr;
  this->screenPrtState.staticList[4].excludeAngle = 0.0;
  this->screenPrtState.staticList[0].fadeStartTime = 0;
  this->screenPrtState.staticList[0].fadeEndTime = 0;
  this->screenPrtState.staticList[0].isActive = false;
  this->screenPrtState.staticList[1].pModel = nullptr;
  this->screenPrtState.staticList[1].fadeStartTime = 0;
  this->screenPrtState.staticList[1].fadeEndTime = 0;
  this->screenPrtState.staticList[1].isActive = false;
  this->screenPrtState.staticList[2].pModel = nullptr;
  this->screenPrtState.staticList[2].fadeStartTime = 0;
  this->screenPrtState.staticList[2].fadeEndTime = 0;
  this->screenPrtState.staticList[2].isActive = false;
  this->screenPrtState.staticList[3].pModel = nullptr;
  this->screenPrtState.staticList[3].fadeStartTime = 0;
  this->screenPrtState.staticList[3].fadeEndTime = 0;
  this->screenPrtState.staticList[3].isActive = false;
  this->screenPrtState.staticList[4].pModel = nullptr;
  this->screenPrtState.staticList[4].fadeStartTime = 0;
  this->screenPrtState.staticList[4].fadeEndTime = 0;
  this->screenPrtState.staticList[4].isActive = false;
  this->fxScreenPrtState[0].excludeAngle = 0.0;
  this->fxScreenPrtState[1].excludeAngle = 0.0;
  this->fxScreenPrtState[0].pModel = nullptr;
  this->fxScreenPrtState[2].excludeAngle = 0.0;
  this->fxScreenPrtState[0].fadeStartTime = 0;
  this->fxScreenPrtState[3].excludeAngle = 0.0;
  this->fxScreenPrtState[0].fadeEndTime = 0;
  this->fxScreenPrtState[0].isActive = false;
  this->fxScreenPrtState[1].pModel = nullptr;
  this->fxScreenPrtState[1].fadeStartTime = 0;
  this->fxScreenPrtState[1].fadeEndTime = 0;
  this->fxScreenPrtState[1].isActive = false;
  this->fxScreenPrtState[2].pModel = nullptr;
  this->fxScreenPrtState[2].fadeStartTime = 0;
  this->fxScreenPrtState[2].fadeEndTime = 0;
  this->fxScreenPrtState[2].isActive = false;
  this->fxScreenPrtState[3].pModel = nullptr;
  this->fxScreenPrtState[3].fadeStartTime = 0;
  this->fxScreenPrtState[3].fadeEndTime = 0;
  this->fxScreenPrtState[3].isActive = false;
  this->uniqueTrackedProjectile.spawnId = 0;
  this->cameraShake.scale = 0.0;
  this->cameraShake.startTime = 0.0;
  this->cameraShake.active = false;
  this->cameraShake.decay = 0.0;
  this->stepUpViewSpring.hasPMin = false;
  this->stepUpViewSpring.restLength = 0.0;
  this->stepUpViewSpring.hasPMax = false;
  this->stepUpViewSpring.p0.x = 0.0;
  this->stepUpViewSpring.p1.x = 0.0;
  this->stepUpViewSpring.vel.x = 0.0;
  this->stepUpViewSpring.maxSpeed = 0.0;
  this->stepUpViewSpring.pMin.x = 0.0;
  this->stepUpViewSpring.k = 1.0;
  this->stepUpViewSpring.m = 1.0;
  this->stepUpViewSpring.c = 2.0;
  this->stepUpViewSpring.pMax.x = 0.0;
  this->stepUpHandsSpring.hasPMin = false;
  this->stepUpHandsSpring.restLength = 0.0;
  this->stepUpHandsSpring.hasPMax = false;
  this->stepUpHandsSpring.k = 1.0;
  this->stepUpHandsSpring.m = 1.0;
  this->stepUpHandsSpring.c = 2.0;
  this->stepUpHandsSpring.p0.x = 0.0;
  this->stepUpHandsSpring.p1.x = 0.0;
  this->stepUpHandsSpring.vel.x = 0.0;
  this->stepUpHandsSpring.maxSpeed = 0.0;
  this->stepUpHandsSpring.pMin.x = 0.0;
  this->stepUpHandsSpring.pMax.x = 0.0;
  idPresentablePlayer::idPlayerExplicitMotion_t::idPlayerExplicitMotion_t(this: &this->explicitMotion);
  idView::idView(this: &this->view);
  localView_t::localView_t(this: &this->localView);
  this->clientFire.fireCount = 0;
  *(_DWORD *)this->clientFire.fireAngles = 0;
  *(_DWORD *)this->clientFire.firePos = 0;
  this->clientFire.firePos[2] = 0;
  idInventoryCollection::idInventoryCollection(this: &this->predictedInventory);
  moveBuffer = this->moveBuffer;
  for ( i = 63; i >= 0; --i )
    cockpitUserCmd_t::cockpitUserCmd_t(this: moveBuffer++);
  this->damageFeedback[0].damage = 0.0;
  this->damageFeedback[0].attacker.spawnId = 0;
  this->damageFeedback[0].impactPoint = vec3_origin;
  this->damageFeedback[0].impactDir = vec3_origin;
  this->damageFeedback[0].impactKick.x = vec3_origin.x;
  this->damageFeedback[0].impactKick.y = vec3_origin.y;
  v17 = vec3_origin.z;
  this->damageFeedback[1].damage = 0.0;
  this->damageFeedback[0].impactOverrideTimer = 0;
  this->damageFeedback[0].impactKick.z = v17;
  this->damageFeedback[1].attacker.spawnId = 0;
  this->damageFeedback[1].impactPoint = vec3_origin;
  this->damageFeedback[1].impactDir = vec3_origin;
  this->damageFeedback[1].impactKick.x = vec3_origin.x;
  this->damageFeedback[1].impactKick.y = vec3_origin.y;
  v18 = vec3_origin.z;
  this->damageFeedback[2].damage = 0.0;
  this->damageFeedback[1].impactKick.z = v18;
  this->damageFeedback[1].impactOverrideTimer = 0;
  this->damageFeedback[2].attacker.spawnId = 0;
  this->damageFeedback[2].impactPoint = vec3_origin;
  this->damageFeedback[2].impactDir = vec3_origin;
  this->damageFeedback[2].impactKick.x = vec3_origin.x;
  this->damageFeedback[2].impactKick.y = vec3_origin.y;
  v19 = vec3_origin.z;
  this->damageFeedback[3].damage = 0.0;
  this->damageFeedback[2].impactOverrideTimer = 0;
  this->damageFeedback[2].impactKick.z = v19;
  this->damageFeedback[3].attacker.spawnId = 0;
  this->damageFeedback[3].impactPoint = vec3_origin;
  this->damageFeedback[3].impactDir = vec3_origin;
  this->damageFeedback[3].impactKick.x = vec3_origin.x;
  this->damageFeedback[3].impactKick.y = vec3_origin.y;
  v20 = vec3_origin.z;
  this->damageFeedback[4].damage = 0.0;
  this->damageFeedback[3].impactKick.z = v20;
  this->damageFeedback[3].impactOverrideTimer = 0;
  this->damageFeedback[4].attacker.spawnId = 0;
  this->damageFeedback[4].impactPoint = vec3_origin;
  this->damageFeedback[4].impactDir = vec3_origin;
  this->damageFeedback[4].impactKick.x = vec3_origin.x;
  this->damageFeedback[4].impactKick.y = vec3_origin.y;
  v21 = vec3_origin.z;
  this->damageFeedback[5].damage = 0.0;
  this->damageFeedback[4].impactKick.z = v21;
  this->damageFeedback[4].impactOverrideTimer = 0;
  this->damageFeedback[5].attacker.spawnId = 0;
  this->damageFeedback[5].impactPoint = vec3_origin;
  this->damageFeedback[5].impactDir = vec3_origin;
  this->damageFeedback[5].impactKick.x = vec3_origin.x;
  this->damageFeedback[5].impactKick.y = vec3_origin.y;
  v22 = vec3_origin.z;
  this->damageFeedback[6].damage = 0.0;
  this->damageFeedback[5].impactKick.z = v22;
  this->damageFeedback[5].impactOverrideTimer = 0;
  this->damageFeedback[6].attacker.spawnId = 0;
  this->damageFeedback[6].impactPoint = vec3_origin;
  this->damageFeedback[6].impactDir = vec3_origin;
  this->damageFeedback[6].impactKick.x = vec3_origin.x;
  this->damageFeedback[6].impactKick.y = vec3_origin.y;
  v23 = vec3_origin.z;
  this->damageFeedback[7].damage = 0.0;
  this->damageFeedback[6].impactOverrideTimer = 0;
  this->damageFeedback[6].impactKick.z = v23;
  this->damageFeedback[7].attacker.spawnId = 0;
  this->damageFeedback[7].impactPoint = vec3_origin;
  this->damageFeedback[7].impactDir = vec3_origin;
  this->damageFeedback[7].impactKick.x = vec3_origin.x;
  this->damageFeedback[7].impactKick.y = vec3_origin.y;
  v24 = vec3_origin.z;
  this->damageFeedback[8].damage = 0.0;
  this->damageFeedback[7].impactOverrideTimer = 0;
  this->damageFeedback[7].impactKick.z = v24;
  this->damageFeedback[8].attacker.spawnId = 0;
  this->damageFeedback[8].impactPoint = vec3_origin;
  this->damageFeedback[8].impactDir = vec3_origin;
  this->damageFeedback[8].impactKick.x = vec3_origin.x;
  this->damageFeedback[8].impactKick.y = vec3_origin.y;
  v25 = vec3_origin.z;
  this->damageFeedback[9].damage = 0.0;
  this->damageFeedback[8].impactKick.z = v25;
  this->damageFeedback[8].impactOverrideTimer = 0;
  this->damageFeedback[9].attacker.spawnId = 0;
  this->damageFeedback[9].impactPoint = vec3_origin;
  this->damageFeedback[9].impactDir = vec3_origin;
  this->damageFeedback[9].impactKick.x = vec3_origin.x;
  this->damageFeedback[9].impactKick.y = vec3_origin.y;
  v26 = vec3_origin.z;
  this->damageFeedback[9].impactOverrideTimer = 0;
  this->damageFeedback[9].impactKick.z = v26;
  this->attackerInfo[0].damageDone = 0.0;
  this->attackerInfo[0].spikeDamage = 0.0;
  this->attackerInfo[0].attacker.spawnId = 0;
  this->attackerInfo[1].damageDone = 0.0;
  this->attackerInfo[1].attacker.spawnId = 0;
  this->attackerInfo[1].spikeDamage = 0.0;
  this->attackerInfo[2].attacker.spawnId = 0;
  this->attackerInfo[2].damageDone = 0.0;
  this->attackerInfo[2].spikeDamage = 0.0;
  this->controlledPresentables.list = nullptr;
  this->controlledPresentables.granularity = 0;
  this->controlledPresentables.memTag = 5;
  this->controlledPresentables.listStatic = 0;
  this->controlledPresentables.size = 0;
  this->controlledPresentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlledPresentables);
  this->influence.innerRadius = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailDist = 32.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  idPlayerHud::idPlayerHud(this: &this->playerHud);
  idHudInfo::idHudInfo(this: &this->hudInfo);
  idPhysics_Player::idPhysics_Player(this: &this->physicsObj);
  idHands::idHands(this: &this->hands);
  idBobCycle::idBobCycle(this: &this->bobCycle);
  idUCmdTracker::idUCmdTracker(this: &this->ucmdTracker1);
  idUCmdTracker::idUCmdTracker(this: &this->ucmdTracker2);
  this->zoomFov.duration = 0.0;
  this->zoomFov.startTime = 0.0;
  this->zoomFov.currentTime = 0.0;
  this->zoomFov.currentValue = 0.0;
  currentValue = this->zoomFov.currentValue;
  this->zoomFov.endValue = this->zoomFov.currentValue;
  this->zoomFov.startValue = currentValue;
  this->missionPin.spawnId.value = 0x1FFF;
  this->controlledEntity.spawnId.value = 0x1FFF;
  `eh vector constructor iterator'(
    ptr: this->weaponKick,
    size: 0x30u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idWeaponKick::idWeaponKick,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  this->baseWeaponSpread.duration = 0.0;
  this->baseWeaponSpread.startTime = 0.0;
  this->baseWeaponSpread.currentTime = 0.0;
  this->baseWeaponSpread.currentValue = 0.0;
  v28 = this->baseWeaponSpread.currentValue;
  this->baseWeaponSpread.endValue = this->baseWeaponSpread.currentValue;
  this->baseWeaponSpread.startValue = v28;
  this->kickWeaponSpread.duration = 0.0;
  this->kickWeaponSpread.startTime = 0.0;
  this->kickWeaponSpread.currentTime = 0.0;
  this->kickWeaponSpread.currentValue = 0.0;
  v29 = this->kickWeaponSpread.currentValue;
  this->kickWeaponSpread.endValue = this->kickWeaponSpread.currentValue;
  this->kickWeaponSpread.startValue = v29;
  idFocusTracker::idFocusTracker(this: &this->focusTracker);
  this->focusTracker.__vftable = (idFocusTracker_Player_vtbl *)&idFocusTracker_Player::`vftable';
  idEnvironmentAnalyzer::idEnvironmentAnalyzer(this: &this->environmentAnalyzer);
  this->killed.count = 0;
  this->killed.lastCount = 0;
  this->respawn.count = 0;
  this->respawn.lastCount = 0;
  this->teleported.count = 0;
  this->teleported.lastCount = 0;
  this->vehicleExited.count = 0;
  this->vehicleExited.lastCount = 0;
  this->deathInfo.attacker.allocedAndFlag = 20;
  this->deathInfo.attacker.data = this->deathInfo.attacker.baseBuffer;
  this->deathInfo.attacker.len = 0;
  this->deathInfo.attacker.baseBuffer[0] = 0;
  this->deathInfo.attackerEmblem.allocedAndFlag = 20;
  this->deathInfo.attackerEmblem.data = this->deathInfo.attackerEmblem.baseBuffer;
  this->deathInfo.attackerEmblem.len = 0;
  this->deathInfo.attackerEmblem.baseBuffer[0] = 0;
  this->deathInfo.damageDef = nullptr;
  this->deathInfo.isKilledByPlayer = false;
  this->deathInfo.isTeamKill = false;
  this->deathInfo.isSuicide = false;
  this->deathInfo.hasQuad = false;
  this->deathInfo.show = false;
  idDedicatedServerSearch::idDedicatedServerSearch(this: &this->subtitleSequencer);
  idAimAssist::idAimAssist(this: &this->aimAssist);
  `eh vector constructor iterator'(
    ptr: this->guiNames,
    size: 0x20u,
    count: 21,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->postGameItems.list = nullptr;
  this->postGameItems.granularity = 0;
  this->postGameItems.memTag = 5;
  this->postGameItems.listStatic = 0;
  this->postGameItems.size = 0;
  this->postGameItems.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->postGameItems);
  this->scriptFunction_goToMission.pThis = nullptr;
  this->scriptFunction_goToMission.__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)&idPresentablePlayer::idSWFScriptFunction_goToMission::`vftable';
  this->scriptFunction_resumeMap.pThis = nullptr;
  this->scriptFunction_resumeMap.__vftable = (idPresentablePlayer::idSWFScriptFunction_resumeMap_vtbl *)&idPresentablePlayer::idSWFScriptFunction_resumeMap::`vftable';
  idPresentablePlayer::SetDefaults(this);
  this->activeInventory = inv;
  this->playerProps = props;
  return this;
}


// ========================================================================
// __unwind$506493
// EA  : 0x82B7E154
// RVA : 0x00B7E154
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506493()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 256 + 276));
}


// ========================================================================
// __unwind$506472
// EA  : 0x82B7E17C
// RVA : 0x00B7E17C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506472()
{
  int v0; // r12

  idPresentableActor::~idPresentableActor(this: *(idPresentableActor **)(v0 - 256 + 276));
}


// ========================================================================
// __unwind$506473
// EA  : 0x82B7E1A4
// RVA : 0x00B7E1A4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506473()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 15768));
}


// ========================================================================
// __unwind$506474
// EA  : 0x82B7E1D0
// RVA : 0x00B7E1D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506474()
{
  int v0; // r12

  idView::~idView(this: (idView *)(*(_DWORD *)(v0 - 256 + 276) + 16224));
}


// ========================================================================
// __unwind$506475
// EA  : 0x82B7E1FC
// RVA : 0x00B7E1FC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506475()
{
  int v0; // r12

  localView_t::~localView_t(this: (localView_t *)(*(_DWORD *)(v0 - 256 + 276) + 23128));
}


// ========================================================================
// __unwind$506476
// EA  : 0x82B7E228
// RVA : 0x00B7E228
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506476()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 23356));
}


// ========================================================================
// __unwind$506477
// EA  : 0x82B7E254
// RVA : 0x00B7E254
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506477()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 35048));
}


// ========================================================================
// __unwind$506478
// EA  : 0x82B7E288
// RVA : 0x00B7E288
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506478()
{
  int v0; // r12

  idPlayerHud::~idPlayerHud(this: (idPlayerHud *)(*(_DWORD *)(v0 - 256 + 276) + 35096));
}


// ========================================================================
// __unwind$506479
// EA  : 0x82B7E2BC
// RVA : 0x00B7E2BC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506479()
{
  int v0; // r12

  idHudInfo::~idHudInfo(this: (idHudInfo *)(*(_DWORD *)(v0 - 256 + 276) + 35368));
}


// ========================================================================
// __unwind$506480
// EA  : 0x82B7E2F0
// RVA : 0x00B7E2F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506480()
{
  int v0; // r12

  idPhysics_Player::~idPhysics_Player(this: (idPhysics_Player *)(*(_DWORD *)(v0 - 256 + 276) + 36264));
}


// ========================================================================
// __unwind$506481
// EA  : 0x82B7E324
// RVA : 0x00B7E324
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506481()
{
  int v0; // r12

  idHands::~idHands(this: (idHands *)(*(_DWORD *)(v0 - 256 + 276) + 37616));
}


// ========================================================================
// __unwind$506482
// EA  : 0x82B7E358
// RVA : 0x00B7E358
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506482()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 256 + 276) + 46684),
    size: 0x30u,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
}


// ========================================================================
// __unwind$506483
// EA  : 0x82B7E39C
// RVA : 0x00B7E39C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506483()
{
  int v0; // r12

  idFocusTracker_Player::~idFocusTracker_Player(this: (idFocusTracker_Player *)(*(_DWORD *)(v0 - 256 + 276) + 47160));
}


// ========================================================================
// __unwind$506484
// EA  : 0x82B7E3D0
// RVA : 0x00B7E3D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506484()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 256 + 276) + 47840));
}


// ========================================================================
// __unwind$506485
// EA  : 0x82B7E404
// RVA : 0x00B7E404
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506485()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(*(_DWORD *)(v0 - 256 + 276) + 48580));
}


// ========================================================================
// __unwind$506486
// EA  : 0x82B7E438
// RVA : 0x00B7E438
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506486()
{
  int v0; // r12

  idList<idSubtitles::idPart,5>::Clear(this: (idSubtitleSequencer *)(*(_DWORD *)(v0 - 256 + 276) + 48656));
}


// ========================================================================
// __unwind$506487
// EA  : 0x82B7E46C
// RVA : 0x00B7E46C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506487()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 256 + 276) + 48688));
}


// ========================================================================
// __unwind$506488
// EA  : 0x82B7E4A0
// RVA : 0x00B7E4A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506488()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 256 + 276) + 48892),
    size: 0x20u,
    count: 21,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$506489
// EA  : 0x82B7E4E4
// RVA : 0x00B7E4E4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506489()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 49604));
}


// ========================================================================
// __unwind$506490
// EA  : 0x82B7E518
// RVA : 0x00B7E518
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506490()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 256 + 276) + 49632));
}


// ========================================================================
// __unwind$506491
// EA  : 0x82B7E54C
// RVA : 0x00B7E54C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_506491()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 256 + 276) + 49640));
}


// ========================================================================
// ??1idPresentablePlayer@@UAA@XZ
// EA  : 0x82B7E5D0
// RVA : 0x00B7E5D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::~idPresentablePlayer(idPresentablePlayer *this)
{
  __int64 v2; // r6
  idRenderModelAugmentOutline *outlineModel; // r3
  idPlayerViewCallbacks *viewCallbacks; // r4
  int v5; // r26
  idSWF **loadedGuis; // r27
  idSWF *v7; // r29
  idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5> *p_postGameItems; // r29
  idSubtitleSequencer *p_subtitleSequencer; // r26
  idSubtitles::idPart *list; // r25
  int size; // r29
  idStr *p_phrase; // r27
  idCrosshairCombinerInfo *v13; // r4
  idHudInteractionInfo::icon_t *v14; // r4
  idList<idPresentablePtr<idPresentable>,5> *p_controlledPresentables; // r29
  idInventoryItem **v16; // r4
  idPresentablePlayer::screenParticleState_t *v17; // r4
  int v18; // [sp+5Ch] [-54h]

  this->__vftable = (idPresentablePlayer_vtbl *)&idPresentablePlayer::`vftable';
  idInfluenceTrailManager::FreeInfluenceTrail(this: &clientGame->influenceTrailManager, presentable: this);
  idPlayerHud_Render::Cleanup(this: &this->localView.hudRender);
  idPlayerGuis_Render::Cleanup(this: &this->localView.guisRender);
  outlineModel = this->outlineModel;
  if ( outlineModel != nullptr )
  {
    outlineModel->unlinked = true;
    outlineModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: outlineModel);
  }
  viewCallbacks = this->viewCallbacks;
  if ( viewCallbacks != nullptr )
  {
    idMem::Free(this: &mem, ptr: viewCallbacks, align: ALIGN_16);
    this->viewCallbacks = nullptr;
  }
  HIBYTE(v18) = -1;
  this->loadedGuis[8] = nullptr;
  this->isGeneralGuiCardGame = false;
  HIDWORD(v2) = v18;
  idClientGame::SetLobbyUserIdForPlayerIndex(this: clientGame, lobbyUserID: v2);
  v5 = 21;
  loadedGuis = this->loadedGuis;
  do
  {
    v7 = *loadedGuis;
    if ( *loadedGuis != nullptr )
    {
      idSWF::~idSWF(this: *loadedGuis);
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
      *loadedGuis = nullptr;
    }
    --v5;
    ++loadedGuis;
  }
  while ( v5 != 0 );
  this->scriptFunction_resumeMap.__vftable = (idPresentablePlayer::idSWFScriptFunction_resumeMap_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_goToMission.__vftable = (idPresentablePlayer::idSWFScriptFunction_goToMission_vtbl *)&idSWFScriptFunction::`vftable';
  p_postGameItems = &this->postGameItems;
  if ( this->postGameItems.listStatic == 0 || this->postGameItems.listStatic == 2 )
  {
    if ( p_postGameItems->list != nullptr )
      idMem::Free(this: &mem, ptr: p_postGameItems->list, align: ALIGN_16);
    p_postGameItems->list = nullptr;
    this->postGameItems.size = 0;
  }
  this->postGameItems.num = 0;
  `eh vector destructor iterator'(
    ptr: this->guiNames,
    size: 0x20u,
    count: 21,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->aimAssist.__vftable = (idAimAssist_vtbl *)&idClass::`vftable';
  p_subtitleSequencer = &this->subtitleSequencer;
  if ( this->subtitleSequencer.parts.listStatic == 0 || this->subtitleSequencer.parts.listStatic == 2 )
  {
    list = p_subtitleSequencer->parts.list;
    if ( p_subtitleSequencer->parts.list != nullptr )
    {
      size = this->subtitleSequencer.parts.size;
      if ( size > 0 )
      {
        p_phrase = &list->phrase;
        do
        {
          idStr::FreeData(this: p_phrase);
          --size;
          p_phrase = (idStr *)((char *)p_phrase + 44);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    p_subtitleSequencer->parts.list = nullptr;
    this->subtitleSequencer.parts.size = 0;
  }
  this->subtitleSequencer.parts.num = 0;
  idStr::FreeData(this: &this->deathInfo.attackerEmblem);
  idStr::FreeData(this: &this->deathInfo.attacker);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->environmentAnalyzer);
  idFocusTracker::~idFocusTracker(this: &this->focusTracker);
  `eh vector destructor iterator'(
    ptr: this->weaponKick,
    size: 0x30u,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  idHands::~idHands(this: &this->hands);
  idPhysics_Player::~idPhysics_Player(this: &this->physicsObj);
  if ( this->hudInfo.combiners.listStatic == 0 || this->hudInfo.combiners.listStatic == 2 )
  {
    v13 = this->hudInfo.combiners.list;
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    this->hudInfo.combiners.list = nullptr;
    this->hudInfo.combiners.size = 0;
  }
  this->hudInfo.combiners.num = 0;
  if ( this->hudInfo.interact.icons.listStatic == 0 || this->hudInfo.interact.icons.listStatic == 2 )
  {
    v14 = this->hudInfo.interact.icons.list;
    if ( v14 != nullptr )
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    this->hudInfo.interact.icons.list = nullptr;
    this->hudInfo.interact.icons.size = 0;
  }
  this->hudInfo.interact.icons.num = 0;
  idPlayerHud::~idPlayerHud(this: &this->playerHud);
  p_controlledPresentables = &this->controlledPresentables;
  if ( this->controlledPresentables.listStatic == 0 || this->controlledPresentables.listStatic == 2 )
  {
    if ( p_controlledPresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_controlledPresentables->list, align: ALIGN_16);
    p_controlledPresentables->list = nullptr;
    this->controlledPresentables.size = 0;
  }
  this->controlledPresentables.num = 0;
  if ( this->predictedInventory.inventory.listStatic == 0 || this->predictedInventory.inventory.listStatic == 2 )
  {
    v16 = this->predictedInventory.inventory.list;
    if ( v16 != nullptr )
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    this->predictedInventory.inventory.list = nullptr;
    this->predictedInventory.inventory.size = 0;
  }
  this->predictedInventory.inventory.num = 0;
  idPlayerGuis_Render::~idPlayerGuis_Render(this: &this->localView.guisRender);
  idPlayerHud_Render::~idPlayerHud_Render(this: &this->localView.hudRender);
  idView::~idView(this: &this->view);
  if ( this->screenPrtState.listStatic == 0 || this->screenPrtState.listStatic == 2 )
  {
    v17 = this->screenPrtState.list;
    if ( v17 != nullptr )
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    this->screenPrtState.list = nullptr;
    this->screenPrtState.size = 0;
  }
  this->screenPrtState.num = 0;
  this->__vftable = (idPresentablePlayer_vtbl *)&idPresentableActor::`vftable';
  idActorModifierManager::~idActorModifierManager(this: &this->predictedActorModifierManager);
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// __unwind$507249
// EA  : 0x82B7E9DC
// RVA : 0x00B7E9DC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507249()
{
  int v0; // r12

  idPresentableActor::~idPresentableActor(this: *(idPresentableActor **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$507250
// EA  : 0x82B7EA04
// RVA : 0x00B7EA04
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507250()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 15768));
}


// ========================================================================
// __unwind$507251
// EA  : 0x82B7EA30
// RVA : 0x00B7EA30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507251()
{
  int v0; // r12

  idView::~idView(this: (idView *)(*(_DWORD *)(v0 - 176 + 196) + 16224));
}


// ========================================================================
// __unwind$507252
// EA  : 0x82B7EA5C
// RVA : 0x00B7EA5C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507252()
{
  int v0; // r12

  localView_t::~localView_t(this: (localView_t *)(*(_DWORD *)(v0 - 176 + 196) + 23128));
}


// ========================================================================
// __unwind$507253
// EA  : 0x82B7EA88
// RVA : 0x00B7EA88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507253()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 23356));
}


// ========================================================================
// __unwind$507254
// EA  : 0x82B7EAB4
// RVA : 0x00B7EAB4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507254()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 35048));
}


// ========================================================================
// __unwind$507255
// EA  : 0x82B7EAE8
// RVA : 0x00B7EAE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507255()
{
  int v0; // r12

  idPlayerHud::~idPlayerHud(this: (idPlayerHud *)(*(_DWORD *)(v0 - 176 + 196) + 35096));
}


// ========================================================================
// __unwind$507256
// EA  : 0x82B7EB1C
// RVA : 0x00B7EB1C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507256()
{
  int v0; // r12

  idHudInfo::~idHudInfo(this: (idHudInfo *)(*(_DWORD *)(v0 - 176 + 196) + 35368));
}


// ========================================================================
// __unwind$507257
// EA  : 0x82B7EB50
// RVA : 0x00B7EB50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507257()
{
  int v0; // r12

  idPhysics_Player::~idPhysics_Player(this: (idPhysics_Player *)(*(_DWORD *)(v0 - 176 + 196) + 36264));
}


// ========================================================================
// __unwind$507258
// EA  : 0x82B7EB84
// RVA : 0x00B7EB84
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507258()
{
  int v0; // r12

  idHands::~idHands(this: (idHands *)(*(_DWORD *)(v0 - 176 + 196) + 37616));
}


// ========================================================================
// __unwind$507259
// EA  : 0x82B7EBB8
// RVA : 0x00B7EBB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507259()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 176 + 196) + 46684),
    size: 0x30u,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
}


// ========================================================================
// __unwind$507260
// EA  : 0x82B7EBFC
// RVA : 0x00B7EBFC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507260()
{
  int v0; // r12

  idFocusTracker_Player::~idFocusTracker_Player(this: (idFocusTracker_Player *)(*(_DWORD *)(v0 - 176 + 196) + 47160));
}


// ========================================================================
// __unwind$507261
// EA  : 0x82B7EC30
// RVA : 0x00B7EC30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507261()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 176 + 196) + 47840));
}


// ========================================================================
// __unwind$507262_0
// EA  : 0x82B7EC64
// RVA : 0x00B7EC64
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507262_0()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(*(_DWORD *)(v0 - 176 + 196) + 48580));
}


// ========================================================================
// __unwind$507263
// EA  : 0x82B7EC98
// RVA : 0x00B7EC98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507263()
{
  int v0; // r12

  idList<idSubtitles::idPart,5>::Clear(this: (idSubtitleSequencer *)(*(_DWORD *)(v0 - 176 + 196) + 48656));
}


// ========================================================================
// __unwind$507264
// EA  : 0x82B7ECCC
// RVA : 0x00B7ECCC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507264()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 176 + 196) + 48688));
}


// ========================================================================
// __unwind$507265
// EA  : 0x82B7ED00
// RVA : 0x00B7ED00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507265()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 176 + 196) + 48892),
    size: 0x20u,
    count: 21,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$507266
// EA  : 0x82B7ED44
// RVA : 0x00B7ED44
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507266()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 49604));
}


// ========================================================================
// __unwind$507267
// EA  : 0x82B7ED78
// RVA : 0x00B7ED78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507267()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 176 + 196) + 49632));
}


// ========================================================================
// __unwind$507268
// EA  : 0x82B7EDAC
// RVA : 0x00B7EDAC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507268()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 176 + 196) + 49640));
}


// ========================================================================
// __unwind$507507
// EA  : 0x82B7EDE0
// RVA : 0x00B7EDE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507507()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$507528
// EA  : 0x82B7EE08
// RVA : 0x00B7EE08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507528()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 80) + 44));
}


// ========================================================================
// __unwind$507780
// EA  : 0x82B7EE34
// RVA : 0x00B7EE34
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507780()
{
  int v0; // r12

  idPlayerHud_Render::~idPlayerHud_Render(this: (idPlayerHud_Render *)(*(_DWORD *)(v0 - 176 + 88) + 4));
}


// ========================================================================
// __unwind$507839
// EA  : 0x82B7EE60
// RVA : 0x00B7EE60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_507839()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 176 + 196));
}


// ========================================================================
// ?ResetLocalViews@idPresentablePlayer@@QAAXXZ
// EA  : 0x82B7EE90
// RVA : 0x00B7EE90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ResetLocalViews(idPresentablePlayer *this)
{
  idHudInfo v2; // [sp+50h] [-1E0h] BYREF

  if ( this->localView.initialized )
  {
    idHudInfo::idHudInfo(this: &v2);
    idHudInfo::operator=(this: &this->hudInfo, __that: &v2);
    idHudInfo::~idHudInfo(this: &v2);
  }
}


// ========================================================================
// __unwind$508016
// EA  : 0x82B7EEF0
// RVA : 0x00B7EEF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_508016()
{
  int v0; // r12

  idHudInfo::~idHudInfo(this: (idHudInfo *)(v0 - 560 + 80));
}


// ========================================================================
// ?AddControl@idPresentablePlayer@@QAAXPAVidPresentable@@@Z
// EA  : 0x82B7EF18
// RVA : 0x00B7EF18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::AddControl(idPresentablePlayer *this, idPresentablePlayer *control)
{
  int num; // r11
  idPresentable *v4; // r29
  idPresentable *v5; // r4
  idHandle<int,enum invalidFiberId_t,0> v6; // [sp+50h] [-30h] BYREF

  num = this->controlledPresentables.num;
  v4 = this == control ? nullptr : control;
  if ( num <= 0 )
    v5 = nullptr;
  else
    v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]);
  if ( v4 != nullptr )
  {
    if ( v4 != v5 )
    {
      if ( v5 != nullptr )
        idPresentablePlayer::DetachController(this, control: v5);
      v6.value = v4->spawnId;
      idList<idHandle<int,enum invalidFiberId_t,0>,5>::Append(
        this: (idList<idHandle<int,enum invalidFiberId_t,0>,5> *)&this->controlledPresentables,
        obj: &v6);
      idPresentablePlayer::AttachController(this, control: v4);
    }
  }
  else
  {
    idPresentablePlayer::ResetControl(this);
  }
}


// ========================================================================
// ?UpdateSubtitles@idPresentablePlayer@@QAAXH@Z
// EA  : 0x82B7F038
// RVA : 0x00B7F038
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::UpdateSubtitles(idPresentablePlayer *this, int curTime)
{
  int *p_subtitleStartTime; // r30
  idGame *v5; // r3
  const idTypesafeNumber<int,enum millisecondUnique_t> *v6; // r3
  idGameTimeManager *v7; // r3
  __int64 v8; // r10
  int entityNumber; // r4
  double v10; // fp31
  __int64 v11; // r8
  unsigned int v12; // r4
  int v13; // r3
  int v14; // r5
  char *v15; // r30
  idSWF *v16; // r11
  idSWF *PlayerGui; // r3
  idSWF *v18; // r3
  idTypesafeNumber<int,enum gameTimeUnique_t> v19; // [sp+50h] [-D0h] BYREF
  idGameTimeManager v20; // [sp+58h] [-C8h] BYREF

  p_subtitleStartTime = &this->subtitleStartTime;
  if ( this->subtitleStartTime == -1 )
    *p_subtitleStartTime = curTime;
  v5 = common->Game(this: common);
  v19.value = curTime - *p_subtitleStartTime;
  v6 = (const idTypesafeNumber<int,enum millisecondUnique_t> *)v5->GetGameTimeManager(this: v5);
  v7 = idGameTimeManager::ConvertTimeGameToReal(this: &v20, result: v6, ticks: &v19);
  HIDWORD(v8) = &off_82040000;
  entityNumber = this->entityNumber;
  LODWORD(v8) = v7->framenum;
  *(_QWORD *)&v20.framenum = v8;
  v10 = (float)((float)v8 * (float)0.001);
  idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: entityNumber);
  if ( v13 != 0 )
    v14 = (*(int (__fastcall **)(int))(*(_DWORD *)v13 + 36))(a1: v13);
  else
    v14 = -1;
  v15 = idSubtitleSequencer::Update(this: &this->subtitleSequencer, newTime: v10, languageMask: v12, a4: v14, a5: v11);
  if ( v15 != nullptr && idPresentablePlayer::GetPlayerGui(this, g: GUI_SUBTITLE) != nullptr )
  {
    v16 = this->loadedGuis[15];
    if ( v16 != nullptr )
      LOBYTE(v16) = v16->isActive;
    if ( (_BYTE)v16 == 0 )
    {
      PlayerGui = idPresentablePlayer::GetPlayerGui(this, g: GUI_SUBTITLE);
      idSWF::Activate(this: PlayerGui, b: true);
    }
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v20.hz[1]);
    idSWFParmList::Append(this: (idSWFParmList *)&v20.hz[1], s: v15);
    v18 = idPresentablePlayer::GetPlayerGui(this, g: GUI_SUBTITLE);
    idSWF::Invoke(this: v18, functionName: "setSubtitle", parms: (const idSWFParmList *)&v20.hz[1]);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v20.hz[1]);
  }
}


// ========================================================================
// __unwind$509048
// EA  : 0x82B7F1B4
// RVA : 0x00B7F1B4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_509048()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// ?ClientThink@idPresentablePlayer@@UAAXHM_N@Z
// EA  : 0x82B7F1E8
// RVA : 0x00B7F1E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __fastcall idPresentablePlayer::ClientThink(
        idPresentablePlayer *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  int v7; // r19
  int *p_num; // r28
  idPresentable *v10; // r3
  unsigned __int64 v11; // r21
  idPlayerHud::hudState_t v12; // r4
  double v13; // fp31
  double v14; // fp31
  double v15; // fp1
  idStr *v16; // r4
  int GameMs; // r3
  idGameTimeManager *p_gameTimeManager; // r28
  int GameMsPerFrame; // r27
  int v20; // r28
  int v21; // r3
  int v22; // r11
  int v23; // r27
  idUCmdTracker *p_ucmdTracker2; // r29
  const idAngles *ViewAngles; // r3
  int *p_serializeDamageFeedbackCount; // r22
  int *p_damageFeedbackBufferPos; // r28
  int v28; // r9
  int v29; // r8
  idPresentablePlayer_vtbl **v30; // r11
  float *v31; // r26
  int v32; // r27
  idVec3 *v33; // r3
  idPhysics_Player_vtbl *v34; // r8
  double v35; // fp9
  double v36; // fp7
  void (__fastcall *SetLinearVelocity)(struct idPhysics_Player *, const idVec3 *, int); // r7
  int v38; // r5
  int v39; // r27
  idPresentablePtr<idPresentable> *p_attacker; // r26
  int v41; // r25
  idPresentable *PresentableByIndex; // r4
  idPresentablePtr<idPresentable> *v43; // r27
  int v44; // r26
  double x; // fp10
  double y; // fp9
  double v47; // fp8
  double v48; // fp7
  double z; // fp6
  double v50; // fp5
  double v51; // fp4
  double v52; // fp3
  double v53; // fp2
  int v54; // r10
  float *v55; // r11
  float v56; // r7
  float v57; // r6
  double v60; // fp1
  double v61; // fp0
  double v62; // fp0
  double v63; // fp1
  double v64; // fp0
  double v65; // fp11
  double v66; // fp9
  double v67; // fp8
  float *v68; // r5
  double v69; // fp0
  double v70; // fp13
  double v71; // fp11
  double v72; // fp10
  double v74; // fp6
  double v76; // fp4
  double v77; // fp12
  double v78; // fp11
  double v79; // fp6
  idPresentablePlayer_vtbl *v80; // r9
  double v81; // fp29
  idPresentablePtr<idPresentable> *v82; // r27
  int v83; // r26
  idPresentablePtr<idPresentable> *v84; // r27
  int v85; // r26
  idPresentable *v86; // r3
  idVec3 *p_origin; // r11
  int v88; // r9
  int v89; // r7
  float v90; // r6
  float v91; // r3
  bool v92; // r3
  idLobbyBase *v93; // r3
  idActorModifierManager *v94; // r3
  int num; // [sp+50h] [-170h]
  _DWORD v96[3]; // [sp+54h] [-16Ch] BYREF
  idVec3 v97; // [sp+60h] [-160h] BYREF
  float v98; // [sp+70h] [-150h]
  float v99; // [sp+74h] [-14Ch]
  float v100; // [sp+78h] [-148h]
  idVec3 v101; // [sp+80h] [-140h] BYREF
  float v102[4]; // [sp+90h] [-130h] BYREF
  idBitMsg v103; // [sp+A0h] [-120h] BYREF
  int v104; // [sp+C8h] [-F8h] BYREF
  idStr v105[2]; // [sp+E0h] [-E0h] BYREF

  v7 = curTime;
  if ( common->IsMultiplayer(this: common) )
  {
    p_num = &this->controlledPresentables.num;
    num = this->controlledPresentables.num;
    if ( num > 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[num - 1]) != nullptr )
    {
      if ( *p_num <= 0 )
      {
        LODWORD(v11) = 0;
        v10 = nullptr;
      }
      else
      {
        v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[*p_num - 1]);
        LODWORD(v11) = 0;
      }
      if ( v10->GetVehicleInterface(this: v10) != nullptr )
      {
        this->physicsObj.DisableClip(this: &this->physicsObj);
        idHands::UpdateHidden(this: &this->hands);
        goto LABEL_12;
      }
    }
    else
    {
      LODWORD(v11) = 0;
    }
    this->physicsObj.EnableClip(this: &this->physicsObj);
    idHands::UpdateHidden(this: &this->hands);
  }
  else
  {
    LODWORD(v11) = 0;
  }
LABEL_12:
  if ( !this->IsLocallyControlled(this) )
    this->Interpolate(this, a2: v7, a3: fraction);
  if ( a5 == 1 )
  {
    this->ClientPredict(this, a2: v7, a3: fraction);
    if ( this->IsLocallyControlled(this) )
      idPresentablePlayer::ClientUpdateFocusEntity(this);
    else
      idPhysics_Player::UpdateNonPredictiveClip(this: &this->physicsObj);
  }
  if ( common->IsClient(this: common) && this->IsLocallyControlled(this) )
  {
    v12 = HUDSTATE_DAMAGE;
    if ( (*((_BYTE *)this + 47032) & 4) == 0 )
      v12 = HUDSTATE_ALL;
    idPlayerHud::SetHudState(this: &this->playerHud, state: v12);
  }
  this->HudThink(this);
  idPlayerHud::Think(this: &this->playerHud);
  idPresentableAnimatedEntity::UpdateAnimation(this, curTime: v7, fraction);
  idPresentablePlayer::UpdateSound(this);
  if ( this->IsLocallyControlled(this) )
  {
    idPresentablePlayer::UpdateDamageFeedback(this);
    idPresentablePlayer::UpdateDamageDealt(this);
  }
  idStr::idStr(this: v105, text: "fx_wound");
  v13 = ((double (__fastcall *)(idPresentablePlayer *))this->GetTotalMaxHealth)(a1: this);
  v14 = (float)((float)v13 - this->GetTotalCurHealth(this));
  v15 = ((double (__fastcall *)(idPresentablePlayer *))this->GetTotalMaxHealth)(a1: this);
  idPresentablePlayer::UpdateDecal(this, value: (float)((float)v14 / (float)v15), tagName: v16, decalSize: 20.0);
  this->Present(this);
  idHands::Draw(this: &this->hands);
  HIDWORD(v11) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idInfluenceTrailManager::UpdatePosition(
    this: &clientGame->influenceTrailManager,
    trail: &this->influenceHandle,
    position: &this->origin,
    time: GameMs);
  if ( common->IsClient(this: common) && this->IsLocallyControlled(this) && !common->DemoPlaying(this: common) )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v20 = idAccolade::Count(this: p_gameTimeManager) * GameMsPerFrame;
    v21 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v22 = this->controlledPresentables.num;
    v23 = v20 - v21;
    if ( v22 > 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &this->controlledPresentables.list[v22 - 1]) != nullptr )
    {
      p_ucmdTracker2 = &this->ucmdTracker2;
    }
    else
    {
      p_ucmdTracker2 = &this->ucmdTracker1;
    }
    ViewAngles = idPresentablePlayer::GetViewAngles(
                   this: (idPresentablePlayer *)&v101,
                   result: (const idAngles *)this,
                   includeWeaponKick: true);
    idPresentablePlayer::RecordMove(
      this,
      prevcmd: &p_ucmdTracker2->prevcmd,
      usercmd: &p_ucmdTracker2->usercmd,
      angles: ViewAngles,
      startTime: v23,
      endTime: v20);
  }
  p_serializeDamageFeedbackCount = &this->serializeDamageFeedbackCount;
  if ( this->serializeDamageFeedbackCount > 0 )
  {
    p_damageFeedbackBufferPos = &this->damageFeedbackBufferPos;
    do
    {
      v28 = *p_damageFeedbackBufferPos;
      v29 = (unsigned __int64)(1717986919LL * *p_damageFeedbackBufferPos) >> 32;
      --*p_serializeDamageFeedbackCount;
      v30 = (idPresentablePlayer_vtbl **)((char *)this + 52 * (v28 - 10 * ((v29 >> 2) + ((unsigned int)v29 >> 31))));
      v31 = (float *)(v30 + 8630);
      v32 = (int)v30[8633];
      if ( v32 > 0 && (((unsigned int)v30[8631] | (unsigned int)v30[8632] | (unsigned int)v30[8630]) & 0x7FFFFFFF) != 0 )
      {
        v33 = this->physicsObj.GetLinearVelocity(this: &v104, result: &this->physicsObj, a3: 0);
        v34 = this->physicsObj.__vftable;
        v35 = (float)(v33->z + v31[2]);
        v36 = (float)(v33->y + v31[1]);
        v102[0] = *v31 + v33->x;
        v102[2] = v35;
        SetLinearVelocity = v34->SetLinearVelocity;
        v102[1] = v36;
        SetLinearVelocity(this: &this->physicsObj, a2: (const idVec3 *)v102, a3: 0);
        idPhysics_Player::SetKnockBack(this: &this->physicsObj, knockBackTime: v32, absoluteKnockBack: false);
      }
      v38 = *p_damageFeedbackBufferPos % 10;
      v39 = v38;
      p_attacker = &this->damageFeedback[v38].attacker;
      v41 = p_attacker->spawnId & 0x3FFF;
      if ( p_attacker->spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_attacker->spawnId & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v41))->spawnId != p_attacker->spawnId )
      {
        PresentableByIndex = nullptr;
      }
      idPresentablePlayer::AddAttacker(
        this,
        attacker: PresentableByIndex,
        damage: this->damageFeedback[v39].damage,
        dir: (const idVec3 *)v38,
        damageDef: nullptr);
      v43 = &this->damageFeedback[*p_damageFeedbackBufferPos % 10].attacker;
      v44 = v43->spawnId & 0x3FFF;
      if ( v43->spawnId != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: v43->spawnId & 0x3FFF)
        && idClientGame::GetPresentableByIndex(this: clientGame, index: v44)->spawnId == v43->spawnId )
      {
        x = this->firstPersonViewAxis.mat[0].x;
        y = this->firstPersonViewAxis.mat[0].y;
        v47 = this->firstPersonViewAxis.mat[1].y;
        v48 = this->firstPersonViewAxis.mat[2].y;
        z = this->firstPersonViewAxis.mat[0].z;
        v50 = this->firstPersonViewAxis.mat[1].z;
        v51 = this->firstPersonViewAxis.mat[2].z;
        v52 = this->firstPersonViewAxis.mat[1].x;
        v53 = this->firstPersonViewAxis.mat[2].x;
        v54 = *p_damageFeedbackBufferPos % 10;
        v55 = (float *)((char *)this + 52 * v54);
        v96[1] = &this->firstPersonViewAxis.mat[2];
        v56 = v55[8628];
        v57 = v55[8629];
        v98 = v55[8627];
        v99 = v56;
        v100 = v57;
        _FP29 = (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f0, f29, f1, f0 }
        v60 = __frsqrte(_FP0);
        v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                            * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100))) * (float)0.5))
                                                                                    * (float)v60)
                                                                            - (float)1.5)
                                                            * (float)v60)
                                                    * (float)((float)((float)(v56 * v56)
                                                                    + (float)((float)(v98 * v98) + (float)(v100 * v100)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v60
                                                                                    * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100)))
                                                                                            * (float)0.5))
                                                                            * (float)v60)
                                                                    - (float)1.5)
                                                    * (float)v60))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v60
                                                            * (float)((float)((float)(v56 * v56)
                                                                            + (float)((float)(v98 * v98)
                                                                                    + (float)(v100 * v100)))
                                                                    * (float)0.5))
                                                    * (float)v60)
                                            - (float)1.5)
                            * (float)v60));
        v62 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100))) * (float)0.5)) * (float)v60) - (float)1.5) * (float)v60)
                                                                                            * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                            * (float)v60))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v56 * v56) + (float)((float)(v98 * v98) + (float)(v100 * v100))) * (float)0.5))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    * (float)((float)((float)(v56 * v56)
                                                                    + (float)((float)(v98 * v98) + (float)(v100 * v100)))
                                                            * (float)0.5))
                                            * (float)v61)
                                    - (float)1.5)
                    * (float)v61);
        v63 = (float)(v57 * (float)v62);
        v66 = (float)((float)((float)z * (float)(v57 * (float)v62)) + (float)((float)y * (float)(v56 * (float)v62)));
        v67 = (float)((float)((float)v50 * (float)(v57 * (float)v62)) + (float)((float)v47 * (float)(v56 * (float)v62)));
        v65 = (float)((float)v48 * (float)(v56 * (float)v62));
        v64 = (float)(v98 * (float)v62);
        v97.x = (float)((float)x * (float)v64) + (float)v66;
        v97.y = (float)((float)v52 * (float)v64) + (float)v67;
        v97.z = (float)((float)v53 * (float)v64) + (float)((float)((float)v51 * (float)v63) + (float)v65);
      }
      else
      {
        v54 = *p_damageFeedbackBufferPos % 10;
        v68 = (float *)((char *)this + 52 * v54);
        v69 = v68[8627];
        v97.x = v68[8627];
        v70 = v68[8628];
        v71 = (float)(v68[8628] * v68[8628]);
        v97.y = v68[8628];
        v72 = v68[8629];
        _FP7 = (float)((float)((float)((float)v69 * (float)v69) + (float)((float)(v68[8629] * v68[8629]) + (float)v71))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v74 = (float)((float)((float)((float)v69 * (float)v69) + (float)((float)(v68[8629] * v68[8629]) + (float)v71))
                    * (float)0.5);
        __asm { fsel      f5, f7, f8, f12 }
        v76 = __frsqrte(_FP5);
        v77 = (float)((float)-(float)((float)((float)((float)v76
                                                    * (float)((float)((float)((float)v69 * (float)v69)
                                                                    + (float)((float)(v68[8629] * v68[8629]) + (float)v71))
                                                            * (float)0.5))
                                            * (float)v76)
                                    - (float)1.5)
                    * (float)v76);
        v78 = (float)((float)((float)-(float)((float)((float)((float)v76
                                                            * (float)((float)((float)((float)v69 * (float)v69)
                                                                            + (float)((float)(v68[8629] * v68[8629])
                                                                                    + (float)v71))
                                                                    * (float)0.5))
                                                    * (float)v76)
                                            - (float)1.5)
                            * (float)v76)
                    * (float)((float)((float)((float)v69 * (float)v69)
                                    + (float)((float)(v68[8629] * v68[8629]) + (float)v71))
                            * (float)0.5));
        v79 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)v78 * (float)v77) - (float)1.5)
                                                    * (float)v77)
                                            * (float)v74)
                                    * (float)((float)-(float)((float)((float)v78 * (float)v77) - (float)1.5) * (float)v77))
                            - (float)1.5);
        v97.x = (float)((float)v79 * (float)((float)-(float)((float)((float)v78 * (float)v77) - (float)1.5) * (float)v77))
              * (float)v69;
        v97.y = (float)v70
              * (float)((float)v79 * (float)((float)-(float)((float)((float)v78 * (float)v77) - (float)1.5) * (float)v77));
        v97.z = (float)v72
              * (float)((float)v79 * (float)((float)-(float)((float)((float)v78 * (float)v77) - (float)1.5) * (float)v77));
      }
      v80 = this->__vftable;
      v96[1] = v54;
      v81 = (float)(this->damageFeedback[v54].damage / v80->GetTotalMaxHealth(this));
      v82 = &this->damageFeedback[*p_damageFeedbackBufferPos % 10].attacker;
      v83 = v82->spawnId & 0x3FFF;
      if ( v82->spawnId != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: v82->spawnId & 0x3FFF)
        && idClientGame::GetPresentableByIndex(this: clientGame, index: v83)->spawnId == v82->spawnId )
      {
        v84 = &this->damageFeedback[*p_damageFeedbackBufferPos % 10].attacker;
        v85 = v84->spawnId & 0x3FFF;
        if ( v84->spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v84->spawnId & 0x3FFF)
          || (v86 = idClientGame::GetPresentableByIndex(this: clientGame, index: v85))->spawnId != v84->spawnId )
        {
          v86 = nullptr;
        }
        p_origin = &v86->origin;
      }
      else
      {
        p_origin = &vec3_origin;
      }
      v88 = *p_damageFeedbackBufferPos;
      v89 = (unsigned __int64)(1717986919LL * *p_damageFeedbackBufferPos) >> 32;
      v90 = p_origin->y;
      v91 = p_origin->z;
      v101.x = p_origin->x;
      v101.y = v90;
      v101.z = v91;
      idView::DamageImpulse(
        this: &this->view,
        localKickDir: &v97,
        inflictorOrg: &v101,
        damageDef: this->damageFeedback[v88 - 10 * ((v89 >> 2) + ((unsigned int)v89 >> 31))].damageDef,
        impulseDamageScale: v81);
      idPresentablePlayer::PresentableDamaged(
        this,
        damage: this->damageFeedback[*p_damageFeedbackBufferPos % 10].damage);
      ++*p_damageFeedbackBufferPos;
    }
    while ( *p_serializeDamageFeedbackCount > 0 );
    v7 = curTime;
    LODWORD(v11) = 0;
  }
  idPresentablePlayer::UpdateOutline(this);
  if ( common->IsClient(this: common)
    && this->IsLocallyControlled(this)
    && this->wasPaused != common->IsGamePaused(this: common)
    && !common->DemoPlaying(this: common) )
  {
    memset(&v103.curSize, 0, 18);
    v103.writeData = (unsigned __int8 *)v96;
    v103.readData = (const unsigned __int8 *)v96;
    v103.maxSize = 2;
    v103.tempValue = v11;
    idBitMsg::WriteBits(this: &v103, value: this->entityNumber, numBits: 8);
    v92 = common->IsGamePaused(this: common);
    idBitMsg::WriteBits(this: &v103, value: v92, numBits: 1);
    v93 = session->GetActingGameStateLobbyBase(this: session);
    v93->SendReliable(this: v93, a2: 14, a3: &v103, a4: false, a5: 255u);
    this->wasPaused = common->IsGamePaused(this: common);
  }
  v94 = this->GetActorModifierManager(this);
  idActorModifierManager::ServerThink(this: v94);
  idPresentablePlayer::UpdateSubtitles(this, curTime: v7);
}


// ========================================================================
// __unwind$509113
// EA  : 0x82B7FDEC
// RVA : 0x00B7FDEC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _unwind_509113()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 448 + 80));
}


// ========================================================================
// `dynamic initializer for 'sub_debug''
// EA  : 0x8336DC68
// RVA : 0x0136DC68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sub_debug__()
{
  idCVar::idCVar(
    this: &sub_debug,
    name: "sub_debug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sub_debug__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative''
// EA  : 0x8336DCC0
// RVA : 0x0136DCC0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative,
    name: "pm_clientAuthoritative",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative_debug''
// EA  : 0x8336DD18
// RVA : 0x0136DD18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative_debug__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative_debug,
    name: "pm_clientAuthoritative_debug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative_debug__);
}


// ========================================================================
// `dynamic initializer for 'pm_predict''
// EA  : 0x8336DD70
// RVA : 0x0136DD70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_predict__()
{
  idCVar::idCVar(
    this: &pm_predict,
    name: "pm_predict",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_predict__);
}


// ========================================================================
// `dynamic initializer for 'pm_predict_db''
// EA  : 0x8336DDC8
// RVA : 0x0136DDC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_predict_db__()
{
  idCVar::idCVar(
    this: &pm_predict_db,
    name: "pm_predict_db",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_predict_db__);
}


// ========================================================================
// `dynamic initializer for 'p_debugInhibitFlags''
// EA  : 0x8336DE20
// RVA : 0x0136DE20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugInhibitFlags__()
{
  idCVar::idCVar(
    this: &p_debugInhibitFlags,
    name: "p_debugInhibitFlags",
    value: "0",
    flags: 1,
    description: "prints out inhibitplags when they are set",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugInhibitFlags__);
}


// ========================================================================
// `dynamic initializer for 'p_printInhibitFlags_v''
// EA  : 0x8336DE78
// RVA : 0x0136DE78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__p_printInhibitFlags_v__()
{
  return idCommandLink::idCommandLink(
           this: &p_printInhibitFlags_v,
           cmdName: "p_printInhibitFlags",
           function: p_printInhibitFlags_f,
           description: "print out all current inhibit flags",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'p_clearInhibitFlags_v''
// EA  : 0x8336DEA0
// RVA : 0x0136DEA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__p_clearInhibitFlags_v__()
{
  return idCommandLink::idCommandLink(
           this: &p_clearInhibitFlags_v,
           cmdName: "p_clearInhibitFlags",
           function: p_clearInhibitFlags_f,
           description: "clears inhibit flags",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'sub_status_v''
// EA  : 0x8336DEC8
// RVA : 0x0136DEC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sub_status_v__()
{
  return idCommandLink::idCommandLink(
           this: &sub_status_v,
           cmdName: "sub_status",
           function: sub_status_f,
           description: "shows status of which subtitles are active",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'sub_set_v''
// EA  : 0x8336DEF0
// RVA : 0x0136DEF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sub_set_v__()
{
  return idCommandLink::idCommandLink(
           this: &sub_set_v,
           cmdName: "sub_set",
           function: sub_set_f,
           description: "changes the status of a subtitle",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'rpOutlineWidth''
// EA  : 0x8336DF18
// RVA : 0x0136DF18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _dynamic_initializer_for__rpOutlineWidth__()
{
  rpOutlineWidth.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpOutlineWidth;
}


// ========================================================================
// `dynamic initializer for 'rpOutlineOpacity''
// EA  : 0x8336DF38
// RVA : 0x0136DF38
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void _dynamic_initializer_for__rpOutlineOpacity__()
{
  rpOutlineOpacity.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpOutlineOpacity;
}


// ========================================================================
// `dynamic initializer for 'pm_screenParticleOffset''
// EA  : 0x8336DF58
// RVA : 0x0136DF58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_screenParticleOffset__()
{
  idCVar::idCVar(
    this: &pm_screenParticleOffset,
    name: "pm_screenParticleOffset",
    value: "3.2",
    flags: 4,
    description: "forward offset when placing screen particles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_screenParticleOffset__);
}

