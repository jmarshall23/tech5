
// ========================================================================
// ?GetClassName@idAICombatHint@@QBAPADXZ
// EA  : 0x82C61288
// RVA : 0x00C61288
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

char *__fastcall idAICombatHint::GetClassName(idAICombatHint *this)
{
  idAICombatHint::combatHintClass_t hintClass; // r11

  hintClass = this->hintClass;
  switch ( hintClass )
  {
    case 1:
      return "(A)";
    case 2:
      return "(B)";
    case 4:
      return "(C)";
    default:
      break;
  }
  return &byte_8200D768;
}


// ========================================================================
// ?HintTypeColor@idAICombatHint@@SAABVidColor@@W4combatHintType_t@1@@Z
// EA  : 0x82C612D8
// RVA : 0x00C612D8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const idColor *__fastcall idAICombatHint::HintTypeColor(unsigned int hintType)
{
  if ( hintType <= 7 )
  {
    if ( hintType == 1 )
      return &idColor::colorOrange;
    if ( hintType == 2 )
      return &idColor::colorRed;
    if ( hintType != 3 )
    {
      switch ( hintType )
      {
        case 4u:
          return &idColor::colorRed;
        case 5u:
          return &idColor::colorPurple;
        case 6u:
          return &idColor::colorBlue;
        default:
          break;
      }
      if ( hintType != 0 )
        return &idColor::colorYellow;
      return &idColor::colorGreen;
    }
  }
  return &idColor::colorWhite;
}


// ========================================================================
// ?Spawn@idAIBackStandHint@@QAAXXZ
// EA  : 0x82C61358
// RVA : 0x00C61358
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idAIBackStandHint::Spawn(idAIBackStandHint *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
}


// ========================================================================
// ?Event_GetLengthOnSpline@idInfoSplineChild@@QBA?AVeventFloat@@XZ
// EA  : 0x82C61390
// RVA : 0x00C61390
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoSplineChild *__fastcall idInfoSplineChild::Event_GetLengthOnSpline(idInfoSplineChild *this, eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: result[201].value);
  return this;
}


// ========================================================================
// ?Think@idInfoDebugMarker@@UAAXXZ
// EA  : 0x82C613C8
// RVA : 0x00C613C8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoDebugMarker::Think(idInfoDebugMarker *this)
{
  void (__fastcall *GetColor_2)(struct idInfoDebugMarker *, idColor *); // r9
  idPhysics *Physics; // r31
  int GameMsPerFrame; // r29
  idPhysics *v5; // r3
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v7; // r31
  int v8; // r3
  float v9[12]; // [sp+50h] [-30h] BYREF

  GetColor_2 = this->GetColor_2;
  v9[3] = -1.0;
  v9[2] = -1.0;
  v9[1] = -1.0;
  v9[0] = -1.0;
  GetColor_2(this, a2: (idColor *)v9);
  Physics = idEntity::GetPhysics(this);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = Physics;
  GetOrigin = Physics->GetOrigin;
  v7 = clientGame->renderWorld->__vftable;
  v8 = (int)GetOrigin(this: v5, a2: 0);
  v7->DebugPoint(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v9,
    a3: (const idVec3 *)v8,
    a4: GameMsPerFrame,
    a5: true);
}


// ========================================================================
// ?ChoosePlayerLeftAnim@idInfoPath@@QBAHXZ
// EA  : 0x82C61480
// RVA : 0x00C61480
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idInfoPath::ChoosePlayerLeftAnim(idInfoPath *this)
{
  int v2; // r24
  int v3; // r27
  int v4; // r29
  int v5; // r30
  int *v6; // r26
  idInfoPath::anim_t *v7; // r31
  int weight; // r11
  signed int v9; // r11
  idClientGame *v10; // r5
  int v11; // r7
  unsigned int seed; // r9
  signed int v13; // r4
  int v14; // r11
  int v15; // r6
  int *i; // r9
  int v17; // r30
  idInfoPath::anim_t *v18; // r31
  int v20; // [sp+50h] [-E0h]
  int v21; // [sp+5Ch] [-D4h] BYREF
  char v22; // [sp+60h] [-D0h] BYREF

  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( this->playerLeftAnims.num <= 0 )
    return -1;
  v5 = 0;
  v6 = &v21;
  do
  {
    v7 = &this->playerLeftAnims.list[v5];
    if ( v7->nextPlayTime <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      weight = v7->weight;
      if ( weight > 0 )
      {
        ++v2;
        *++v6 = v4;
        v3 += weight;
        if ( v2 == 32 )
          break;
      }
    }
    ++v4;
    ++v5;
  }
  while ( v4 < this->playerLeftAnims.num );
  if ( v2 == 0 )
    return -1;
  v9 = 100 * v3;
  v10 = clientGame;
  if ( 100 * v3 != 0 )
  {
    seed = clientGame->random.seed;
    __twllei(v9, 0);
    clientGame->random.seed = 1664525 * seed + 1013904223;
    v13 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
    v10 = clientGame;
    v11 = v13 % v9;
    __twlgei(v9 & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
  }
  else
  {
    v11 = 0;
  }
  v14 = 0;
  v15 = 0;
  if ( v2 <= 0 )
    return -1;
  for ( i = (int *)&v22; ; ++i )
  {
    v17 = *i;
    v18 = &this->playerLeftAnims.list[*i];
    v14 += 100 * v18->weight;
    if ( v11 < v14 )
      break;
    if ( ++v15 >= v2 )
      return -1;
  }
  v20 = (int)(float)(v18->timeBetween * (float)1000.0);
  v18->nextPlayTime = idGameTimeManager::GetGameMs(this: &v10->gameTimeManager, type: GAMETIME_SCALED) + v20;
  return v17;
}


// ========================================================================
// ?GetInfoDevComment@@YAPBDPBD@Z
// EA  : 0x82C61618
// RVA : 0x00C61618
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const char *__fastcall GetInfoDevComment(const char *entityName)
{
  idEntity *v1; // r3
  _DWORD *v2; // r3

  v1 = gameLocal->FindEntity(this: gameLocal, a2: entityName);
  v2 = _RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &idEntity `RTTI Type Descriptor',
         TargetType: &idInfoDevComment `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    return (const char *)v2[201];
  else
    return nullptr;
}


// ========================================================================
// ??0idAIHint@@QAA@XZ
// EA  : 0x82C61690
// RVA : 0x00C61690
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAIHint *__fastcall idAIHint::idAIHint(idAIHint *this)
{
  idEntity::idEntity(this);
  this->enabled = true;
  this->__vftable = (idAIHint_vtbl *)&idAIHint::`vftable';
  return this;
}


// ========================================================================
// ??0idAIHintGroup@@QAA@XZ
// EA  : 0x82C616D8
// RVA : 0x00C616D8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAIHintGroup *__fastcall idAIHintGroup::idAIHintGroup(idAIHintGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idAIHintGroup_vtbl *)&idAIHintGroup::`vftable';
  return this;
}


// ========================================================================
// ??0idAISearchHintGroup@@QAA@XZ
// EA  : 0x82C61718
// RVA : 0x00C61718
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAISearchHintGroup *__fastcall idAISearchHintGroup::idAISearchHintGroup(idAISearchHintGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idAISearchHintGroup_vtbl *)&idAISearchHintGroup::`vftable';
  return this;
}


// ========================================================================
// ?Spawn@idAICombatHint@@QAAXXZ
// EA  : 0x82C61758
// RVA : 0x00C61758
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idAICombatHint::Spawn(idAICombatHint *this)
{
  idTypeInfoTools *v2; // r3
  const enumValueInfo_t *EnumValueInfo; // r3
  char *data; // r4
  double minWeight; // fp0

  if ( classTypeForHintType[this->combatHintType] != nullptr
    && (idTypeInfo *)this->GetType(this) != classTypeForHintType[this->combatHintType] )
  {
    v2 = (idTypeInfoTools *)gameLocal->GetTypeInfoTools(this: gameLocal);
    EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                      this: v2,
                      enumName: "combatHintType_t",
                      value: this->combatHintType,
                      defaultIfNotFound: true);
    data = this->name.data;
    if ( EnumValueInfo == nullptr )
      idLib::Error(fmt: "Entity '%s' using invalid / unknown combatHintType_t.", data);
    idLib::Error(
      fmt: "Entity '%s' is type '%s' while using entity def info/combat/hint. You must use entity def '%s' to set combat hint type '%s'.",
      data,
      EnumValueInfo->name,
      entityDefForHintType[this->combatHintType],
      EnumValueInfo->name);
  }
  minWeight = this->minWeight;
  if ( minWeight < 0.0 || minWeight > 1.0 )
    idLib::Error(fmt: "'%s' - minWeight must be between >= 0.0 and <= 1.0", this->name.data);
}


// ========================================================================
// ?GetDrawColor@idAICombatHint@@QBAABVidColor@@XZ
// EA  : 0x82C61868
// RVA : 0x00C61868
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const idColor *__fastcall idAICombatHint::GetDrawColor(idAICombatHint *this)
{
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->dontUseUntil )
    return idAICombatHint::HintTypeColor(hintType: this->combatHintType);
  else
    return &idColor::colorMdGrey;
}


// ========================================================================
// ??0idAIBackStandHint@@QAA@XZ
// EA  : 0x82C618D8
// RVA : 0x00C618D8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAIBackStandHint *__fastcall idAIBackStandHint::idAIBackStandHint(idAIBackStandHint *this)
{
  idEntity::idEntity(this);
  this->enabled = true;
  this->__vftable = (idAIBackStandHint_vtbl *)&idAIBackStandHint::`vftable';
  return this;
}


// ========================================================================
// ??0idAIAASHint@@QAA@XZ
// EA  : 0x82C61920
// RVA : 0x00C61920
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAIAASHint *__fastcall idAIAASHint::idAIAASHint(idAIAASHint *this)
{
  idEntity::idEntity(this);
  this->enabled = true;
  this->__vftable = (idAIAASHint_vtbl *)&idAIAASHint::`vftable';
  return this;
}


// ========================================================================
// ??0idAISearchHintAuto@@QAA@XZ
// EA  : 0x82C61968
// RVA : 0x00C61968
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAISearchHintAuto *__fastcall idAISearchHintAuto::idAISearchHintAuto(idAISearchHintAuto *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idAISearchHintAuto_vtbl *)&idAISearchHintAuto::`vftable';
  this->enabled = true;
  this->radius.value = 48.0;
  return this;
}


// ========================================================================
// ??0idAISearchHintAnimation@@QAA@XZ
// EA  : 0x82C619B8
// RVA : 0x00C619B8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAISearchHintAnimation *__fastcall idAISearchHintAnimation::idAISearchHintAnimation(idAISearchHintAnimation *this)
{
  idEntity::idEntity(this);
  this->enabled = true;
  this->__vftable = (idAISearchHintAnimation_vtbl *)&idAISearchHintAnimation::`vftable';
  this->searchAnim = ANIMOVERRIDE_NONE;
  return this;
}


// ========================================================================
// ??0idInfoCover@@QAA@XZ
// EA  : 0x82C61A08
// RVA : 0x00C61A08
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoCover *__fastcall idInfoCover::idInfoCover(idInfoCover *this)
{
  idEntity::idEntity(this);
  this->coverPosture = POSTURE_STANDING;
  this->__vftable = (idInfoCover_vtbl *)&idInfoCover::`vftable';
  this->duration = -1.0;
  this->actions.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
  *((_BYTE *)&this->actions + 4) &= 7u;
  this->transitions = (idCoverTransitions)-1;
  this->minRange = 0.0;
  this->force = false;
  this->maxRange = 0.0;
  this->aasLayer = AAS_MONSTER48;
  return this;
}


// ========================================================================
// ??0idInfoOrbit@@QAA@XZ
// EA  : 0x82C61AA0
// RVA : 0x00C61AA0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoOrbit *__fastcall idInfoOrbit::idInfoOrbit(idInfoOrbit *this)
{
  idEntity::idEntity(this);
  this->degreesPerSec = 1.0;
  this->useRealTime = false;
  this->time = 10.0;
  this->__vftable = (idInfoOrbit_vtbl *)&idInfoOrbit::`vftable';
  this->rtDist = 0.0;
  this->startTime = 0;
  this->upDist = 0.0;
  this->endTime = 0;
  this->spawnOrg = vec3_origin;
  this->spawnDir = vec3_origin;
  return this;
}


// ========================================================================
// ?OnActivate@idInfoOrbit@@UAAXPAVidEntity@@@Z
// EA  : 0x82C61B50
// RVA : 0x00C61B50
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoOrbit::OnActivate(idInfoOrbit *this, idEntity *activator)
{
  idGameLocal_vtbl *v3; // r10
  int v4; // r3
  int v5; // r3
  double time; // fp13

  idEntity::BecomeActive(this, flags: 1);
  v3 = gameLocal->__vftable;
  if ( this->useRealTime )
  {
    v4 = ((int (*)(void))v3->GetGameFrame)();
    v5 = GameFramesToMS(frameNum: v4, type: GAMETIME_SCALED);
  }
  else
  {
    v5 = ((int (*)(void))v3->GetGameMs)();
  }
  time = this->time;
  this->startTime = v5;
  this->endTime = v5 - (int)(float)((float)time * (float)-1000.0);
}


// ========================================================================
// ??0idInfoTexLod@@QAA@XZ
// EA  : 0x82C61BE8
// RVA : 0x00C61BE8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoTexLod *__fastcall idInfoTexLod::idInfoTexLod(idInfoTexLod *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoTexLod_vtbl *)&idInfoTexLod::`vftable';
  this->texLodModelName.len = 0;
  this->texLodModelName.allocedAndFlag = 20;
  this->texLodModelName.data = this->texLodModelName.baseBuffer;
  this->texLodModelName.baseBuffer[0] = 0;
  this->stepDistance = 64.0;
  return this;
}


// ========================================================================
// ??0idInfoStaticReflection@@QAA@XZ
// EA  : 0x82C61C50
// RVA : 0x00C61C50
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoStaticReflection *__fastcall idInfoStaticReflection::idInfoStaticReflection(idInfoStaticReflection *this)
{
  idEntity::idEntity(this);
  this->spotId = 0;
  this->__vftable = (idInfoStaticReflection_vtbl *)&idInfoStaticReflection::`vftable';
  return this;
}


// ========================================================================
// ?ActivateCars@idTownGarageManager@@QAAXXZ
// EA  : 0x82C61C98
// RVA : 0x00C61C98
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::ActivateCars(idTownGarageManager *this)
{
  int num; // r11
  int v2; // r29
  int v4; // r31
  idVehicle *vehicle; // r8

  num = this->vehicles.num;
  v2 = 0;
  this->shouldDeactivateCars = false;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      idEntity::BecomeInactive(this: this->vehicles.list[v4].vehicle, flags: 2);
      idEntity::BecomeActive(this: this->vehicles.list[v4].vehicle, flags: 5);
      ++v2;
      vehicle = this->vehicles.list[v4++].vehicle;
      *(_BYTE *)&vehicle->flags &= ~0x40u;
    }
    while ( v2 < this->vehicles.num );
  }
}


// ========================================================================
// ?DeactivateCars@idTownGarageManager@@QAAXXZ
// EA  : 0x82C61D18
// RVA : 0x00C61D18
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::DeactivateCars(idTownGarageManager *this)
{
  int v2; // r29
  int v3; // r31
  idVehicle *vehicle; // r9

  v2 = 0;
  if ( this->vehicles.num > 0 )
  {
    v3 = 0;
    do
    {
      idEntity::BecomeInactive(this: this->vehicles.list[v3].vehicle, flags: 7);
      ++v2;
      vehicle = this->vehicles.list[v3++].vehicle;
      *(_BYTE *)&vehicle->flags |= 0x40u;
    }
    while ( v2 < this->vehicles.num );
  }
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ??0idInfoSpawnPoint@@QAA@XZ
// EA  : 0x82C61D88
// RVA : 0x00C61D88
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoSpawnPoint *__fastcall idInfoSpawnPoint::idInfoSpawnPoint(idInfoSpawnPoint *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoSpawnPoint_vtbl *)&idInfoSpawnPoint::`vftable';
  return this;
}


// ========================================================================
// ??0idInfoDebugText@@QAA@XZ
// EA  : 0x82C61DC8
// RVA : 0x00C61DC8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoDebugText *__fastcall idInfoDebugText::idInfoDebugText(idInfoDebugText *this)
{
  float a; // r7

  idEntity::idEntity(this);
  this->__vftable = (idInfoDebugText_vtbl *)&idInfoDebugText::`vftable';
  this->text.len = 0;
  this->text.data = this->text.baseBuffer;
  this->text.allocedAndFlag = 20;
  this->text.baseBuffer[0] = 0;
  this->textColor.r = idColor::colorWhite.r;
  this->textColor.g = idColor::colorWhite.g;
  this->textColor.b = idColor::colorWhite.b;
  a = idColor::colorWhite.a;
  this->textScale = 1.0;
  this->depthTest = true;
  this->permanent = true;
  this->textColor.a = a;
  return this;
}


// ========================================================================
// ?Think@idInfoDebugText@@UAAXXZ
// EA  : 0x82C61EE0
// RVA : 0x00C61EE0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoDebugText::Think(idInfoDebugText *this)
{
  idPhysics *Physics; // r3
  char *data; // r29
  double textScale; // fp31
  BOOL depthTest; // r28
  idColor *p_textColor; // r27
  idRenderWorld_vtbl *v7; // r31
  int v8; // r3

  if ( this->text.len != 0 && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    data = this->text.data;
    textScale = this->textScale;
    depthTest = this->depthTest;
    p_textColor = &this->textColor;
    v7 = clientGame->renderWorld->__vftable;
    v8 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, char *, int, void *, idColor *, int, int, BOOL, double))v7->DebugText)(
      a1: clientGame->renderWorld,
      a2: data,
      a3: v8,
      a4: &unk_82150000,
      a5: p_textColor,
      a6: 1,
      a7: 1,
      a8: depthTest,
      a9: (float)((float)textScale * (float)0.25));
  }
}


// ========================================================================
// ??0idInfoDebugMapName@@QAA@XZ
// EA  : 0x82C61FA0
// RVA : 0x00C61FA0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoDebugMapName *__fastcall idInfoDebugMapName::idInfoDebugMapName(idInfoDebugMapName *this)
{
  const char *v2; // r3

  idInfoDebugText::idInfoDebugText(this);
  this->__vftable = (idInfoDebugMapName_vtbl *)&idInfoDebugMapName::`vftable';
  v2 = gameLocal->GetMapName(this: gameLocal);
  idStr::operator=(this: &this->text, text: v2);
  return this;
}


// ========================================================================
// __unwind$493245
// EA  : 0x82C62010
// RVA : 0x00C62010
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_493245()
{
  int v0; // r12

  idInfoDebugText::~idInfoDebugText(this: *(idInfoDevComment **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetAimPoint@idCamera@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82C62038
// RVA : 0x00C62038
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idCamera::GetAimPoint(idInfoLookTarget *this, const aimPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  *pos = *Physics->GetOrigin(this: Physics, a2: 0);
}


// ========================================================================
// ??0idInfoLookTargetGroup@@QAA@XZ
// EA  : 0x82C62090
// RVA : 0x00C62090
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoLookTargetGroup *__fastcall idInfoLookTargetGroup::idInfoLookTargetGroup(idInfoLookTargetGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoLookTargetGroup_vtbl *)&idInfoLookTargetGroup::`vftable';
  this->radius = 512.0;
  this->height = 128.0;
  return this;
}


// ========================================================================
// ?IsInside@idInfoLookTargetGroup@@QBA_NABVidVec3@@@Z
// EA  : 0x82C620E8
// RVA : 0x00C620E8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idInfoLookTargetGroup::IsInside(idInfoLookTargetGroup *this, const idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp9
  double z; // fp12
  double v8; // fp0
  int result; // r3

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v6 = (float)(pos->y - v5[1]);
  if ( (float)((float)((float)(pos->x - *v5) * (float)(pos->x - *v5)) + (float)((float)v6 * (float)v6)) > (double)(float)(this->radius * this->radius) )
    return 0;
  z = pos->z;
  if ( z < (float)(v5[2] - (float)(this->height * (float)0.5)) )
    return 0;
  v8 = (float)(v5[2] + (float)(this->height * (float)0.5));
  result = 1;
  if ( z >= v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Spawn@idInfo@@QAAXXZ
// EA  : 0x82C622C8
// RVA : 0x00C622C8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfo::Spawn(idInfo *this)
{
  idPresentable *presentable; // r11
  char v2; // r11
  bool v3; // zf

  presentable = this->presentable;
  if ( presentable == nullptr || (v3 = presentable->model != nullptr, v2 = 1, !v3) )
    v2 = 0;
  if ( v2 != 0 )
    this->SetModel(this, a2: nullptr);
}


// ========================================================================
// ?GetFocus@idInfoPath@@QBAPBVidEntity@@XZ
// EA  : 0x82C62310
// RVA : 0x00C62310
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const idEntity *__fastcall idInfoPath::GetFocus(idInfoPath *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->focus.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetPointWeight@idAIHintPrimitive@@QBAMABVidVec3@@ABVidMat3@@0M@Z
// EA  : 0x82C62358
// RVA : 0x00C62358
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

float __fastcall idAIHintPrimitive::GetPointWeight(
        idAIHintPrimitive *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *point,
        double minWeight)
{
  aiHintPrimitive_t type; // r11
  double v8; // fp12
  double v9; // fp8
  double v10; // fp13
  double v13; // fp8
  double v14; // fp5
  double v15; // fp13
  double v17; // fp0
  double v18; // fp11
  double v19; // fp0
  double v21; // fp0
  idEntityPtr<idVolume> *p_volume; // r30
  idVolume *Entity; // r3
  idPhysics *Physics; // r3
  idClipModel *v26; // r3
  const idMat3 *v28; // [sp+8h] [-F8h]
  int v29; // [sp+Ch] [-F4h]
  int v30; // [sp+10h] [-F0h]
  int v31; // [sp+14h] [-ECh]
  int v32; // [sp+18h] [-E8h]
  int v33; // [sp+1Ch] [-E4h]
  int v34; // [sp+20h] [-E0h]
  int v35; // [sp+24h] [-DCh]
  int v36; // [sp+28h] [-D8h]
  int v37; // [sp+2Ch] [-D4h]
  int v38; // [sp+30h] [-D0h]
  int v39; // [sp+34h] [-CCh]
  int v40; // [sp+38h] [-C8h]
  int v41; // [sp+3Ch] [-C4h]
  int v42; // [sp+40h] [-C0h]
  int v43; // [sp+44h] [-BCh]
  int v44; // [sp+48h] [-B8h]
  int v45; // [sp+4Ch] [-B4h]
  int v46; // [sp+50h] [-B0h]
  trace_t v47; // [sp+60h] [-A0h] BYREF

  type = this->type;
  if ( this->type > (unsigned int)AIHINT_PRIMITIVE_VOLUME )
    goto LABEL_21;
  switch ( type )
  {
    case AIHINT_PRIMITIVE_CIRCLE:
      v13 = (float)(point->y - origin->y);
      v14 = (float)(point->z - origin->z);
      v15 = (float)((float)((float)v14 * (float)v14)
                  + (float)((float)((float)v13 * (float)v13)
                          + (float)((float)(point->x - origin->x) * (float)(point->x - origin->x))));
      if ( v15 <= (float)(this->radius * this->radius) )
      {
        _FP8 = (float)((float)minWeight - (float)((float)1.0 - (float)((float)__fsqrts(v15) / this->radius)));
        __asm { fsel      f1, f8, f10, f9 }
        return *((float *)&_FP1 + 1);
      }
      goto LABEL_21;
    case AIHINT_PRIMITIVE_CYLINDER:
      v17 = (float)(point->z - origin->z);
      _FP1 = 0.0;
      if ( v17 >= 0.0 && v17 <= this->height )
      {
        v18 = (float)(point->y - origin->y);
        v19 = (float)((float)((float)v17 * (float)v17)
                    + (float)((float)((float)v18 * (float)v18)
                            + (float)((float)(point->x - origin->x) * (float)(point->x - origin->x))));
        if ( v19 <= (float)(this->radius * this->radius) )
        {
          _FP8 = (float)((float)minWeight - (float)((float)1.0 - (float)((float)__fsqrts(v19) / this->radius)));
          __asm { fsel      f1, f8, f10, f9 }
        }
      }
      return *((float *)&_FP1 + 1);
    case AIHINT_PRIMITIVE_SPHERE:
      v8 = (float)(point->y - origin->y);
      v9 = (float)(point->z - origin->z);
      v10 = (float)((float)((float)(point->x - origin->x) * (float)(point->x - origin->x))
                  + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)));
      if ( v10 <= (float)(this->radius * this->radius) )
      {
        _FP8 = (float)((float)minWeight - (float)((float)1.0 - (float)((float)__fsqrts(v10) / this->radius)));
        __asm { fsel      f1, f8, f10, f9 }
        return *((float *)&_FP1 + 1);
      }
LABEL_21:
      _FP1 = 0.0;
      return *((float *)&_FP1 + 1);
    default:
      break;
  }
  if ( type != AIHINT_PRIMITIVE_PLANE )
  {
    p_volume = &this->volume;
    if ( idEntityPtr<idVolume>::GetEntity(this: &this->volume) == nullptr )
      goto LABEL_21;
    Entity = idEntityPtr<idVolume>::GetEntity(this: p_volume);
    Physics = idEntity::GetPhysics(this: Entity);
    v26 = Physics->GetClipModel(this: Physics, a2: 0);
    idClip::ContentsModel(
      this: &clientGame->clip,
      result: &v47,
      start: point,
      trm: nullptr,
      trmAxis: &mat3_identity,
      clipMask: 0x4000,
      model: v26,
      modelOrigin: &v26->origin,
      modelAxis: v28,
      a10: v29,
      a11: v30,
      a12: v31,
      a13: v32,
      a14: v33,
      a15: v34,
      a16: v35,
      a17: v36,
      a18: v37,
      a19: v38,
      a20: v39,
      a21: v40,
      a22: v41,
      a23: v42,
      a24: v43,
      a25: v44,
      a26: v45,
      a27: v46,
      a28: (float *)&v26->axis);
    if ( v47.c.contentFlags != 0x4000 )
      goto LABEL_21;
LABEL_17:
    _FP1 = 1.0;
    return *((float *)&_FP1 + 1);
  }
  _FP1 = 0.0;
  v21 = (float)((float)((float)(point->x * axis->mat[0].x)
                      + (float)((float)(point->z * axis->mat[0].z) + (float)(point->y * axis->mat[0].y)))
              - (float)((float)(origin->x * axis->mat[0].x)
                      + (float)((float)(origin->z * axis->mat[0].z) + (float)(origin->y * axis->mat[0].y))));
  if ( v21 <= 0.0 )
  {
    if ( -v21 < this->radius )
    {
      _FP12 = (float)((float)minWeight
                    - (float)-(float)((float)((float)((float)(point->x * axis->mat[0].x)
                                                    + (float)((float)(point->z * axis->mat[0].z)
                                                            + (float)(point->y * axis->mat[0].y)))
                                            - (float)((float)(origin->x * axis->mat[0].x)
                                                    + (float)((float)(origin->z * axis->mat[0].z)
                                                            + (float)(origin->y * axis->mat[0].y))))
                                    / this->radius));
      __asm { fsel      f1, f12, f10, f13 }
      return *((float *)&_FP1 + 1);
    }
    goto LABEL_17;
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?GetEntityWeight@idAIHintPrimitive@@QBAMABVidVec3@@ABVidMat3@@PBVidEntity@@M@Z
// EA  : 0x82C625F0
// RVA : 0x00C625F0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

float __fastcall idAIHintPrimitive::GetEntityWeight(
        idAIHintPrimitive *this,
        const idVec3 *origin,
        const idMat3 *axis,
        idEntity *ent,
        double minWeight)
{
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  double PointWeight; // fp1
  int value; // r10
  idVolume *v14; // r3
  int v15; // r9
  idVolume *v16; // r3
  idVolume *v17; // r3

  if ( this->type == AIHINT_PRIMITIVE_VOLUME )
  {
    value = this->volume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v14 = (idVolume *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idVolume::CastTo(c: v14) != nullptr
      && ((v15 = this->volume.spawnId.value, gameLocal->spawnIds.ptr[v15 & 0x1FFF] != v15 >> 13)
       || (v16 = (idVolume *)gameLocal->entities.ptr[v15 & 0x1FFF]) == nullptr
        ? (v17 = nullptr)
        : (v17 = idVolume::CastTo(c: v16)),
          idVolume::IsTouching(this: v17, other: ent)) )
    {
      PointWeight = 1.0;
    }
    else
    {
      PointWeight = 0.0;
    }
  }
  else
  {
    Physics = idEntity::GetPhysics(this: ent);
    v11 = Physics->GetOrigin(this: Physics, a2: 0);
    PointWeight = idAIHintPrimitive::GetPointWeight(this, origin, axis, point: v11, minWeight);
  }
  return *((float *)&PointWeight + 1);
}


// ========================================================================
// ?GetPointWeight@idAICombatHint@@QBAMABVidVec3@@@Z
// EA  : 0x82C62728
// RVA : 0x00C62728
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

float __fastcall idAICombatHint::GetPointWeight(idAICombatHint *this, const idVec3 *point)
{
  idPhysics *Physics; // r29
  idPhysics *v5; // r28
  double minWeight; // fp31
  const idMat3 *v7; // r29
  const idVec3 *v8; // r3
  double PointWeight; // fp1

  Physics = idEntity::GetPhysics(this);
  v5 = idEntity::GetPhysics(this);
  minWeight = this->minWeight;
  v7 = Physics->GetAxis(this: Physics, a2: 0);
  v8 = v5->GetOrigin(this: v5, a2: 0);
  PointWeight = idAIHintPrimitive::GetPointWeight(this: &this->primitive, origin: v8, axis: v7, point, minWeight);
  return *((float *)&PointWeight + 1);
}


// ========================================================================
// ?GetEntityWeight@idAICombatHint@@QBAMPBVidEntity@@@Z
// EA  : 0x82C627B0
// RVA : 0x00C627B0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

float __fastcall idAICombatHint::GetEntityWeight(idAICombatHint *this, idEntity *ent)
{
  idPhysics *Physics; // r29
  idPhysics *v5; // r28
  double minWeight; // fp31
  const idMat3 *v7; // r29
  const idVec3 *v8; // r3
  double EntityWeight; // fp1

  Physics = idEntity::GetPhysics(this);
  v5 = idEntity::GetPhysics(this);
  minWeight = this->minWeight;
  v7 = Physics->GetAxis(this: Physics, a2: 0);
  v8 = v5->GetOrigin(this: v5, a2: 0);
  EntityWeight = idAIHintPrimitive::GetEntityWeight(this: &this->primitive, origin: v8, axis: v7, ent, minWeight);
  return *((float *)&EntityWeight + 1);
}


// ========================================================================
// ?GetVehicle@idInfoGarageBay@@QBAPBVidVehicle@@XZ
// EA  : 0x82C628A0
// RVA : 0x00C628A0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const idVehicle *__fastcall idInfoGarageBay::GetVehicle(idInfoGarageBay *this)
{
  int value; // r10
  idVehicle *v2; // r3

  value = this->vehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idVehicle::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Think@idTownGarageManager@@UAAXXZ
// EA  : 0x82C62928
// RVA : 0x00C62928
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::Think(idTownGarageManager *this)
{
  char v2; // r28
  int v3; // r29
  int v4; // r31
  idPresentable *presentable; // r3
  int v6; // r3

  if ( this->spawnCalled )
  {
    if ( !this->shouldDeactivateCars )
    {
LABEL_14:
      idEntity::BecomeInactive(this, flags: 1);
      return;
    }
    v2 = 1;
    v3 = 0;
    if ( this->vehicles.num > 0 )
    {
      v4 = 0;
      do
      {
        presentable = this->vehicles.list[v4].vehicle->presentable;
        if ( presentable != nullptr )
          v6 = (int)presentable->GetVehicleInterface(this: presentable);
        else
          v6 = 0;
        if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)(v6 + 16512) + 160))(a1: v6 + 16512) != 0 )
          idEntity::BecomeInactive(this: this->vehicles.list[v4].vehicle, flags: 2);
        else
          v2 = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < this->vehicles.num );
    }
    if ( v2 != 0 )
    {
      idTownGarageManager::DeactivateCars(this);
      goto LABEL_14;
    }
  }
}


// ========================================================================
// ?ProperSetup@idTownGarageManager@@QAA_NXZ
// EA  : 0x82C62A08
// RVA : 0x00C62A08
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

BOOL __fastcall idTownGarageManager::ProperSetup(idTownGarageManager *this)
{
  return gameLocal->spawnIds.ptr[this->focusBay.spawnId.value & 0x1FFF] == this->focusBay.spawnId.value >> 13
      && (_cntlzw(
            (this->newRotateEnt.spawnId.value >> 13)
          - gameLocal->spawnIds.ptr[this->newRotateEnt.spawnId.value & 0x1FFF])
        & 0x20) != 0;
}


// ========================================================================
// ?SetupAndMoveOffscreen@idTownGarageManager@@AAAXXZ
// EA  : 0x82C62A60
// RVA : 0x00C62A60
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::SetupAndMoveOffscreen(idTownGarageManager *this)
{
  const idSoundShader *rotationSound; // r5
  __int128 v3; // r10
  double v4; // fp31
  __int64 v5; // r4
  __int64 v6; // r7
  double v7; // fp4
  const float *v8; // r5
  float v9[2]; // [sp+50h] [-40h] BYREF
  __int64 v10; // [sp+58h] [-38h]
  __int64 v11; // [sp+60h] [-30h]

  rotationSound = this->rotationSound;
  this->currentState = GARAGESTATE_MOVINGTOHIDE;
  if ( rotationSound != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BOOST,
      shader: rotationSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  idEntity::BecomeInactive(this: this->vehicles.list[this->currentVehicleIndex].vehicle, flags: 2);
  DWORD1(v3) = &idEventDef::eventDefList[3154];
  LODWORD(v3) = this->timeToRotate;
  DWORD2(v3) = (int)v3 / 4;
  v9[0] = 0.0;
  v10 = *(_QWORD *)((char *)&v3 + 4);
  v11 = v3;
  v4 = (float)*(__int64 *)((char *)&v3 + 4);
  v5 = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMs)(a1: gameLocal, a2: 1);
  LODWORD(v6) = HIDWORD(v5);
  v7 = (float)v11;
  v11 = v6;
  idInterpolateAccelDecelLinear<float>::Init(
    this: &this->rotationInterpolate,
    startTime: (float)v6,
    accelTime: v4,
    decelTime: v4,
    duration: v7,
    startValue: (const float *)v5,
    endValue: v8,
    a8: SHIDWORD(v6),
    a9: SHIDWORD(v5),
    a10: v9,
    a11: &this->rotationStepAmount);
}


// ========================================================================
// ?Spawn@idInfoVehicleObstacle@@QAAXXZ
// EA  : 0x82C62B68
// RVA : 0x00C62B68
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoVehicleObstacle::Spawn(idInfoVehicleObstacle *this)
{
  idPhysics *Physics; // r3
  int v3; // r30
  idCollisionModel *v4; // r3
  double v5; // fp6
  double v6; // fp4
  double v7; // fp1
  double v8; // fp0
  idClipModel *v9; // r3
  idClipModel *v10; // r30
  idPhysics *v11; // r3
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  idPhysics *v14; // r3
  float v15[6]; // [sp+58h] [-6C8h] BYREF
  idBounds v16; // [sp+70h] [-6B0h] BYREF
  float v17[6]; // [sp+90h] [-690h] BYREF
  idMat3 v18; // [sp+A8h] [-678h] BYREF
  idMat3 v19; // [sp+D0h] [-650h] BYREF
  idTraceModel v20; // [sp+100h] [-620h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (int)Physics->GetClipModel(this: Physics, a2: 0);
  v4 = *(idCollisionModel **)(v3 + 132);
  if ( v4 != nullptr
    || (*(int *)(v3 + 140) <= 0
      ? (v4 = idClipModel::NoTraceModelWarning(this: (idClipModel *)v3))
      : (v4 = *(idCollisionModel **)(*(_DWORD *)(4 * **(_DWORD **)(v3 + 136)
                                               + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 156) + 163956) + 52))
                                   + 64)),
        v4 != nullptr) )
  {
    v4->GetBox(this: v4, a2: (idBox *)v17);
    v16.b[1].x = v17[3];
    v16.b[1].y = v17[4];
    v16.b[1].z = v17[5];
    v16.b[0].z = -v17[5];
    v16.b[0].y = -v17[4];
    v16.b[0].x = -v17[3];
    idTraceModel::InitBox(this: &v20);
    idTraceModel::SetupBox(this: &v20, boxBounds: &v16);
    v5 = *(float *)(v3 + 36);
    v7 = (float)((float)(*(float *)(v3 + 48) * v17[0])
               + (float)((float)(*(float *)(v3 + 60) * v17[1]) + (float)(*(float *)(v3 + 72) * v17[2])));
    v6 = *(float *)(v3 + 32);
    v8 = (float)((float)(*(float *)(v3 + 44) * v17[0])
               + (float)((float)(*(float *)(v3 + 56) * v17[1]) + (float)(*(float *)(v3 + 68) * v17[2])));
    v15[2] = *(float *)(v3 + 40)
           + (float)((float)(*(float *)(v3 + 52) * v17[0])
                   + (float)((float)(*(float *)(v3 + 64) * v17[1]) + (float)(*(float *)(v3 + 76) * v17[2])));
    v15[1] = (float)v5 + (float)v7;
    v15[0] = (float)v8 + (float)v6;
    idMat3::operator*(this: &v19, result: &v18, a: (const idMat3 *)(v3 + 44));
    v9 = (idClipModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xD8u,
                          tag: TAG_CLIPMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
      v10 = idClipModel::idClipModel(this: v9, clip: &clientGame->clip, trm: &v20, numTraceModels: 1, material: nullptr);
    else
      v10 = nullptr;
    v11 = idEntity::GetPhysics(this);
    ((void (__fastcall *)(idPhysics *, idClipModel *, double))v11->SetClipModel)(a1: v11, a2: v10, a3: 1.0);
    v12 = idEntity::GetPhysics(this);
    v12->SetOrigin(this: v12, a2: (const idVec3 *)v15, a3: -1);
    v13 = idEntity::GetPhysics(this);
    v13->SetAxis(this: v13, a2: &v19, a3: -1);
  }
  v14 = idEntity::GetPhysics(this);
  v14->SetContents(this: v14, a2: 0x20000, a3: -1);
}


// ========================================================================
// __unwind$495000
// EA  : 0x82C62DC4
// RVA : 0x00C62DC4
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_495000()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1824 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?CheckIsFacing@idInfo_Trigger_Facing_Target@@QAA_NABVidVec3@@0@Z
// EA  : 0x82C62DF0
// RVA : 0x00C62DF0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idInfo_Trigger_Facing_Target::CheckIsFacing(
        idInfo_Trigger_Facing_Target *this,
        const idVec3 *viewDir,
        const idVec3 *viewPos)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  double y; // fp0
  double v9; // fp13
  int result; // r3
  double v14; // fp2
  double v16; // fp12
  double v17; // fp9
  double v18; // fp5
  double v19; // fp1
  double v20; // fp13
  double v21; // fp12
  double v22; // fp9
  double v23; // fp13
  double v24; // fp2
  double v25; // fp12
  double v26; // fp11
  float v27; // [sp+50h] [-30h]
  float v28; // [sp+54h] [-2Ch]
  float v29; // [sp+58h] [-28h]

  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v28 = v7[1];
  v27 = *v7;
  v29 = v7[2];
  if ( this->doVerticleTest )
  {
    if ( (float)((float)(viewDir->x * (float)(viewPos->x - v27))
               + (float)((float)(viewDir->z * (float)(viewPos->z - v29))
                       + (float)(viewDir->y * (float)(viewPos->y - v28)))) <= 0.0 )
    {
      v9 = (float)((float)((float)(viewDir->x * (float)2.0) * (float)(viewPos->x - v27))
                 + (float)((float)((float)(viewDir->z * (float)2.0) * (float)(viewPos->z - v29))
                         + (float)((float)(viewDir->y * (float)2.0) * (float)(viewPos->y - v28))));
      if ( (float)((float)((float)v9 * (float)v9)
                 - (float)((float)((float)-(float)((float)(this->radius.value * this->radius.value)
                                                 - (float)((float)((float)(viewPos->x - v27) * (float)(viewPos->x - v27))
                                                         + (float)((float)((float)(viewPos->z - v29)
                                                                         * (float)(viewPos->z - v29))
                                                                 + (float)((float)(viewPos->y - v28)
                                                                         * (float)(viewPos->y - v28)))))
                                 * (float)((float)(viewDir->x * viewDir->x)
                                         + (float)((float)(viewDir->z * viewDir->z) + (float)(viewDir->y * viewDir->y))))
                         * (float)4.0)) >= 0.0 )
        return 1;
    }
  }
  else
  {
    result = 1;
    _FP9 = (float)((float)((float)(viewDir->y * viewDir->y) + (float)(viewDir->x * viewDir->x))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    _FP5 = (float)((float)((float)((float)(v27 - viewPos->x) * (float)(v27 - viewPos->x))
                         + (float)((float)(v28 - viewPos->y) * (float)(v28 - viewPos->y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f9, f1, f13 }
    v14 = (float)((float)((float)((float)(v27 - viewPos->x) * (float)(v27 - viewPos->x))
                        + (float)((float)(v28 - viewPos->y) * (float)(v28 - viewPos->y)))
                * (float)0.5);
    __asm { fsel      f13, f5, f10, f13 }
    v16 = __frsqrte(_FP1);
    v17 = __frsqrte(_FP13);
    v18 = (float)v16;
    v19 = (float)v17;
    v20 = (float)((float)v16
                * (float)((float)((float)(viewDir->y * viewDir->y) + (float)(viewDir->x * viewDir->x)) * (float)0.5));
    v21 = (float)((float)v17
                * (float)((float)((float)((float)(v27 - viewPos->x) * (float)(v27 - viewPos->x))
                                + (float)((float)(v28 - viewPos->y) * (float)(v28 - viewPos->y)))
                        * (float)0.5));
    v22 = (float)-(float)((float)((float)v20 * (float)v18) - (float)1.5);
    v23 = (float)-(float)((float)((float)v21 * (float)v19) - (float)1.5);
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v23 * (float)v19)
                                                                                        * (float)v14)
                                                                                * (float)((float)v23 * (float)v19))
                                                                        - (float)1.5)
                                                        * (float)((float)v23 * (float)v19))
                                                * (float)v14)
                                        * (float)((float)-(float)((float)((float)((float)((float)v23 * (float)v19)
                                                                                * (float)v14)
                                                                        * (float)((float)v23 * (float)v19))
                                                                - (float)1.5)
                                                * (float)((float)v23 * (float)v19)))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)((float)v23 * (float)v19) * (float)v14)
                                                * (float)((float)v23 * (float)v19))
                                        - (float)1.5)
                        * (float)((float)v23 * (float)v19)));
    y = viewPos->y;
    v26 = (float)((float)((float)(viewDir->y
                                * (float)((float)-(float)((float)((float)((float)((float)v22 * (float)v18)
                                                                        * (float)((float)((float)(viewDir->y * viewDir->y)
                                                                                        + (float)(viewDir->x * viewDir->x))
                                                                                * (float)0.5))
                                                                * (float)((float)v22 * (float)v18))
                                                        - (float)1.5)
                                        * (float)((float)v22 * (float)v18)))
                        * (float)((float)v24
                                * (float)((float)((float)(v27 - viewPos->x) * (float)(v27 - viewPos->x))
                                        + (float)((float)(v28 - (float)y) * (float)(v28 - (float)y)))))
                - (float)(v28 - (float)y));
    v25 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v22 * (float)v18)
                                                                        * (float)((float)((float)(viewDir->y * viewDir->y)
                                                                                        + (float)(viewDir->x * viewDir->x))
                                                                                * (float)0.5))
                                                                * (float)((float)v22 * (float)v18))
                                                        - (float)1.5)
                                        * (float)((float)v22 * (float)v18))
                                * viewDir->x)
                        * (float)((float)v24
                                * (float)((float)((float)(v27 - viewPos->x) * (float)(v27 - viewPos->x))
                                        + (float)((float)(v28 - viewPos->y) * (float)(v28 - viewPos->y)))))
                - (float)(v27 - viewPos->x));
    if ( (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) < (double)(float)(this->radius.value * this->radius.value) )
      return result;
  }
  return 0;
}


// ========================================================================
// ?CanLook@idInfoLookTarget@@QBA_NPBVidEntity@@@Z
// EA  : 0x82C62FE8
// RVA : 0x00C62FE8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

BOOL __fastcall idInfoLookTarget::CanLook(idInfoLookTarget *this, const idEntity *looker)
{
  int v5; // r30
  idInfoLookTarget::lookerInfo_t *lookerInfo; // r31
  idGameLocal *v7; // r10
  idEntity *v8; // r3
  idEntity *v9; // r3

  if ( looker == nullptr )
    return false;
  v5 = 0;
  lookerInfo = this->lookerInfo;
  v7 = gameLocal;
  while ( 1 )
  {
    if ( v7->spawnIds.ptr[lookerInfo->looker.spawnId.value & 0x1FFF] == lookerInfo->looker.spawnId.value >> 13
      && (v8 = v7->entities.ptr[lookerInfo->looker.spawnId.value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v7 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == looker )
      break;
    ++v5;
    ++lookerInfo;
    if ( v5 >= 3 )
      return true;
  }
  return v7->GetGameMs(this: v7, a2: GAMETIME_SCALED) >= this->lookerInfo[v5].nextLookTime;
}


// ========================================================================
// ?Event_GetParentSpline@idInfoSplineChild@@QBA?AVeventEntity@@XZ
// EA  : 0x82C630C8
// RVA : 0x00C630C8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoSplineChild *__fastcall idInfoSplineChild::Event_GetParentSpline(idInfoSplineChild *this, eventEntity *result)
{
  idEntity *value; // r10
  idSplinePath *v4; // r3
  idSplinePath *v5; // r4

  value = result[200].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = (idSplinePath *)gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idSplinePath::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?Spawn@idInfoAAS@@QAAXXZ
// EA  : 0x82C63148
// RVA : 0x00C63148
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoAAS::Spawn(idInfoAAS *this)
{
  idLinkList<idEntity> *head; // r5

  idGameLocal::GetAAS(this: gameLocal, typeName: this->aasName.data, load: true);
  head = gameLocal->removeEntities.head;
  this->removeNode.prev->next = this->removeNode.next;
  this->removeNode.next->prev = this->removeNode.prev;
  this->removeNode.prev = &this->removeNode;
  this->removeNode.head = &this->removeNode;
  this->removeNode.next = head;
  this->removeNode.prev = head->prev;
  head->prev = &this->removeNode;
  this->removeNode.prev->next = &this->removeNode;
  this->removeNode.head = head->head;
}


// ========================================================================
// ?StopAtPoint@idInfoPath@@QBA_NPBVidAI2@@@Z
// EA  : 0x82C631E8
// RVA : 0x00C631E8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

BOOL __fastcall idInfoPath::StopAtPoint(idInfoPath *this, const idAI2 *ai)
{
  int v4; // r26
  int i; // r29
  idStr *ActionEventName; // r3
  const idEventDef *Event; // r30
  idStr v9[3]; // [sp+50h] [-70h] BYREF

  v4 = 0;
  if ( this->actionScript.num <= 0 )
    return false;
  for ( i = 0; ; ++i )
  {
    ActionEventName = idAIAction::GetActionEventName(result: v9, name: &this->actionScript.list[i].eventName);
    Event = idEventDef::FindEvent(name: ActionEventName->data);
    idStr::FreeData(this: v9);
    if ( Event != nullptr )
      break;
    idLib::Warning(
      fmt: "Script action event '%s' not found. The script action was not queued.",
      this->actionScript.list[i].eventName.data);
LABEL_6:
    if ( ++v4 >= this->actionScript.num )
      return false;
  }
  if ( (unsigned __int8)idAIActionManager::GetActionBlocks(this: &ai->aiVolatile.fsms.actionManager, actionEvent: Event) == 0 )
    goto LABEL_6;
  return idAIActionManager::GetActionStopsMovement(this: &ai->aiVolatile.fsms.actionManager, actionEvent: Event);
}


// ========================================================================
// __unwind$496055_0
// EA  : 0x82C632AC
// RVA : 0x00C632AC
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_496055_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetNextPathPoint@idInfoPath@@QBAPBV1@XZ
// EA  : 0x82C632D8
// RVA : 0x00C632D8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

const idInfoPath *__fastcall idInfoPath::GetNextPathPoint(idInfoPath *this)
{
  signed int num; // r11
  unsigned int seed; // r8
  unsigned int v4; // r4
  int v5; // r9
  unsigned int v6; // r5
  int v7; // r11
  int value; // r9
  idEntity *v9; // r3
  idInfoPath *v10; // r3

  num = this->targets.num;
  if ( num <= 0 )
    return nullptr;
  seed = clientGame->random.seed;
  __twllei(num, 0);
  v4 = 1664525 * seed + 1013904223;
  clientGame->random.seed = v4;
  v5 = (v4 >> 10) & 0x7FFF;
  v6 = num & ~(__ROL4__(v5, 1) - 1);
  v7 = v5 % num;
  __twlgei(v6, 0xFFFFFFFF);
  if ( v7 >= this->targets.num )
    return idInfoPath::CastTo(c: nullptr);
  value = this->targets.list[v7].spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return idInfoPath::CastTo(c: nullptr);
  v9 = gameLocal->entities.ptr[this->targets.list[v7].spawnId.value & 0x1FFF];
  if ( v9 == nullptr )
    return idInfoPath::CastTo(c: nullptr);
  v10 = (idInfoPath *)idEntity::CastTo(c: v9);
  return idInfoPath::CastTo(c: v10);
}


// ========================================================================
// ??0idAICombatHint@@QAA@XZ
// EA  : 0x82C633E8
// RVA : 0x00C633E8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idAICombatHint *__fastcall idAICombatHint::idAICombatHint(idAICombatHint *this)
{
  idEntity::idEntity(this);
  this->enabled = true;
  this->combatHintType = COMBAT_HINT_DEFENSE_POINT;
  this->__vftable = (idAICombatHint_vtbl *)&idAICombatHint::`vftable';
  this->primitive.radius = 128.0;
  this->primitive.type = AIHINT_PRIMITIVE_SPHERE;
  this->primitive.height = 0.0;
  this->primitive.arcLen.value = 0.0;
  this->primitive.volume.spawnId.value = 0x1FFF;
  this->minWeight = 0.0;
  this->delay = 0;
  this->hintClass = CLASS_ALL;
  this->coverIndices.list = nullptr;
  this->coverIndices.granularity = 0;
  this->coverIndices.memTag = 5;
  this->coverIndices.listStatic = 0;
  this->coverIndices.size = 0;
  this->coverIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverIndices);
  this->dontUseUntil = 0;
  return this;
}


// ========================================================================
// __unwind$496238
// EA  : 0x82C634A4
// RVA : 0x00C634A4
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_496238()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 128 + 148));
}


// ========================================================================
// ?FindAASCoverIndices@idAICombatHint@@QAAHXZ
// EA  : 0x82C634D0
// RVA : 0x00C634D0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idAICombatHint::FindAASCoverIndices(idAICombatHint *this)
{
  idAAS2 *v2; // r31
  idAAS2_vtbl *v4; // r11
  int v5; // r29
  const idVec3 *v6; // r26
  idPhysics *Physics; // r25
  idPhysics *v8; // r24
  double minWeight; // fp30
  const idMat3 *v10; // r25
  const idVec3 *v11; // r3
  idAAS2_vtbl *v12; // r11
  encounterGroupRole_t v13[2]; // [sp+50h] [-60h] BYREF

  v2 = idGameLocal::AASForType(this: gameLocal, type: AAS_MONSTER48);
  if ( v2 != nullptr )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverIndices);
    v4 = v2->__vftable;
    v5 = 1;
    v13[0] = ROLE_DEFEND;
    if ( v4->GetNumCoverPoints(this: v2) > 1 )
    {
      do
      {
        v6 = (const idVec3 *)v2->GetCoverPoint(this: v2, a2: v5);
        Physics = idEntity::GetPhysics(this);
        v8 = idEntity::GetPhysics(this);
        minWeight = this->minWeight;
        v10 = Physics->GetAxis(this: Physics, a2: 0);
        v11 = v8->GetOrigin(this: v8, a2: 0);
        if ( idAIHintPrimitive::GetPointWeight(this: &this->primitive, origin: v11, axis: v10, point: v6, minWeight) > 0.0 )
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->coverIndices,
            obj: v13);
        v12 = v2->__vftable;
        v13[0] = ++v5;
      }
      while ( v5 < v12->GetNumCoverPoints(this: v2) );
    }
    return this->coverIndices.num;
  }
  else
  {
    idLib::Warning(fmt: "no AAS to collect cover points for hint node %s", this->name.data);
    return 0;
  }
}


// ========================================================================
// ?Spawn@idInfoExportHint@@QAAXXZ
// EA  : 0x82C63638
// RVA : 0x00C63638
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoExportHint::Spawn(idInfoCloudShot *this)
{
  idPhysics *Physics; // r3
  idLinkList<idEntity> *head; // r4

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  head = gameLocal->removeEntities.head;
  this->removeNode.prev->next = this->removeNode.next;
  this->removeNode.next->prev = this->removeNode.prev;
  this->removeNode.prev = &this->removeNode;
  this->removeNode.head = &this->removeNode;
  this->removeNode.next = head;
  this->removeNode.prev = head->prev;
  head->prev = &this->removeNode;
  this->removeNode.prev->next = &this->removeNode;
  this->removeNode.head = head->head;
}


// ========================================================================
// ?Spawn@idInfoOrbit@@QAAXXZ
// EA  : 0x82C636D8
// RVA : 0x00C636D8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoOrbit::Spawn(idInfoOrbit *this)
{
  int value; // r9
  idEntity *v3; // r3
  idEntity *v4; // r30
  idPhysics *Physics; // r29
  idPhysics *v6; // r28
  float *v7; // r29
  float *v8; // r3
  double v9; // fp31
  double v10; // fp30
  double v11; // fp29
  idPhysics *v12; // r3
  float *v13; // r3
  idPhysics *v14; // r3
  float *v15; // r3
  idPhysics *v16; // r3
  float *v17; // r3
  idPhysics *v18; // r3
  float *v19; // r3

  if ( this->targets.num > 0 )
  {
    value = this->targets.list->spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v4);
      v6 = idEntity::GetPhysics(this);
      v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v8 = (float *)v6->GetOrigin(this: v6, a2: 0);
      v9 = (float)(*v8 - *v7);
      v10 = (float)(v8[1] - v7[1]);
      v11 = (float)(v8[2] - v7[2]);
      v12 = idEntity::GetPhysics(this: v4);
      v13 = (float *)v12->GetAxis(this: v12, a2: 0);
      this->rtDist = (float)(v13[3] * (float)v9) + (float)((float)(v13[5] * (float)v11) + (float)(v13[4] * (float)v10));
      v14 = idEntity::GetPhysics(this: v4);
      v15 = (float *)v14->GetAxis(this: v14, a2: 0);
      this->upDist = (float)(v15[6] * (float)v9) + (float)((float)(v15[8] * (float)v11) + (float)(v15[7] * (float)v10));
      v16 = idEntity::GetPhysics(this: v4);
      v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
      this->spawnOrg.x = *v17;
      this->spawnOrg.y = v17[1];
      this->spawnOrg.z = v17[2];
      v18 = idEntity::GetPhysics(this);
      v19 = (float *)v18->GetAxis(this: v18, a2: 0);
      this->spawnDir.x = *v19;
      this->spawnDir.y = v19[1];
      this->spawnDir.z = v19[2];
    }
  }
}


// ========================================================================
// ?Think@idInfoOrbit@@UAAXXZ
// EA  : 0x82C638C8
// RVA : 0x00C638C8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoOrbit::Think(idInfoOrbit *this)
{
  int value; // r9
  idGameLocal *v3; // r11
  idEntity *v4; // r3
  idEntity *v5; // r3
  idEntity *v6; // r30
  idGameLocal_vtbl *v7; // r10
  int v8; // r3
  __int64 v9; // r7
  int v10; // r3
  double degreesPerSec; // fp13
  double x; // fp12
  double y; // fp11
  double z; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp4
  const idMat3 *v18; // r3
  char *v19; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPhysics *Physics; // r3
  double v23; // fp31
  double v24; // fp30
  double v25; // fp29
  double v26; // fp28
  double v27; // fp27
  double v28; // fp26
  float *v29; // r3
  double v30; // fp2
  double v31; // fp1
  idPhysics *v32; // r3
  float v33[5]; // [sp+58h] [-E8h] BYREF
  char v34; // [sp+6Ch] [-D4h] BYREF
  float v35; // [sp+7Ch] [-C4h]
  float v36; // [sp+80h] [-C0h]
  float v37; // [sp+84h] [-BCh]
  float v38; // [sp+88h] [-B8h]
  float v39; // [sp+8Ch] [-B4h]
  float v40; // [sp+90h] [-B0h]
  idRotation v41; // [sp+A0h] [-A0h] BYREF

  if ( this->targets.num > 0 )
  {
    value = this->targets.list->spawnId.value;
    v3 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v5 = idEntity::CastTo(c: v4);
      v3 = gameLocal;
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != nullptr )
    {
      v7 = v3->__vftable;
      if ( this->useRealTime )
      {
        v8 = v7->GetGameFrame(this: v3);
        v10 = GameFramesToMS(frameNum: v8, type: GAMETIME_SCALED);
      }
      else
      {
        v10 = v7->GetGameMs(this: v3, a2: GAMETIME_SCALED);
      }
      degreesPerSec = this->degreesPerSec;
      x = this->spawnOrg.x;
      y = this->spawnOrg.y;
      z = this->spawnOrg.z;
      LODWORD(v9) = this->startTime - v10;
      v15 = this->spawnDir.x;
      v16 = this->spawnDir.y;
      v41.axisValid = false;
      v17 = this->spawnDir.z;
      v41.origin.x = x;
      v41.origin.y = y;
      v41.origin.z = z;
      v41.vec.x = v15;
      v41.vec.y = v16;
      v41.vec.z = v17;
      v41.angle = (float)((float)v9 * (float)degreesPerSec) * (float)0.001;
      v18 = idRotation::ToMat3(this: &v41);
      v19 = &v34;
      p_z = (_DWORD *)&v18[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v19 += 4;
        *(_DWORD *)v19 = *p_z;
      }
      Physics = idEntity::GetPhysics(this: v6);
      v23 = (float)(v38 * this->upDist);
      v24 = (float)(v39 * this->upDist);
      v25 = (float)(v40 * this->upDist);
      v26 = (float)(v35 * this->rtDist);
      v27 = (float)(v36 * this->rtDist);
      v28 = (float)(v37 * this->rtDist);
      v29 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v30 = (float)(v29[1] + (float)v27);
      v31 = (float)(v29[2] + (float)v28);
      v33[0] = (float)(*v29 + (float)v26) + (float)v23;
      v33[1] = (float)v30 + (float)v24;
      v33[2] = (float)v31 + (float)v25;
      v32 = idEntity::GetPhysics(this);
      v32->SetOrigin(this: v32, a2: (const idVec3 *)v33, a3: -1);
      if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->endTime )
        idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ??0idInfoGarageBay@@QAA@XZ
// EA  : 0x82C63B00
// RVA : 0x00C63B00
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoGarageBay *__fastcall idInfoGarageBay::idInfoGarageBay(idInfoGarageBay *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoGarageBay_vtbl *)&idInfoGarageBay::`vftable';
  this->vehicle.spawnId.value = 0x1FFF;
  this->garage = GARAGE_NONE;
  this->vehicleClass = VEHICLE_CLASSNONE;
  this->vehicle.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idTownGarageManager@@QAA@XZ
// EA  : 0x82C63B60
// RVA : 0x00C63B60
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idTownGarageManager *__fastcall idTownGarageManager::idTownGarageManager(idTownGarageManager *this)
{
  int v2; // r7
  int v3; // r6
  float v5; // [sp+50h] [-40h] BYREF
  float v6; // [sp+54h] [-3Ch] BYREF

  idEntity::idEntity(this);
  this->__vftable = (idTownGarageManager_vtbl *)&idTownGarageManager::`vftable';
  this->focusBay.spawnId.value = 0x1FFF;
  this->newRotateEnt.spawnId.value = 0x1FFF;
  this->effectEnt.spawnId.value = 0x1FFF;
  this->shadowInfoList.list = nullptr;
  this->shadowInfoList.granularity = 0;
  this->shadowInfoList.memTag = 5;
  this->shadowInfoList.listStatic = 0;
  this->shadowInfoList.size = 0;
  this->shadowInfoList.num = 0;
  LODWORD(v6) = &this->effectEnt;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->shadowInfoList);
  this->wastelandMultiSpawn.spawnId.value = 0x1FFF;
  this->vehicles.list = nullptr;
  this->vehicles.granularity = 0;
  this->vehicles.memTag = 5;
  this->vehicles.listStatic = 0;
  this->vehicles.size = 0;
  this->vehicles.num = 0;
  LODWORD(v6) = &this->wastelandMultiSpawn;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vehicles);
  this->rotationInterpolate.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->rotationInterpolate.extrapolate.duration = 0.0;
  this->rotationInterpolate.extrapolate.startTime = 0.0;
  this->rotationInterpolate.extrapolate.startValue = 0.0;
  this->rotationInterpolate.extrapolate.baseSpeed = 0.0;
  this->rotationInterpolate.extrapolate.speed = 0.0;
  this->rotationInterpolate.extrapolate.currentTime = -1.0;
  v5 = 0.0;
  v6 = 0.0;
  this->rotationInterpolate.extrapolate.currentValue = this->rotationInterpolate.extrapolate.startValue;
  this->rotationInterpolate.decelTime = 0.0;
  this->rotationInterpolate.linearTime = 0.0;
  this->rotationInterpolate.accelTime = 0.0;
  this->rotationInterpolate.startTime = 0.0;
  this->rotationInterpolate.startValue = 0.0;
  this->rotationInterpolate.endValue = this->rotationInterpolate.startValue;
  this->garage = GARAGE_NONE;
  this->currentVehicleIndex = -1;
  this->nextVehicleIndex = -1;
  this->currentState = GARAGESTATE_NORMAL;
  idInterpolateAccelDecelLinear<float>::Init(
    this: &this->rotationInterpolate,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: (const float *)1,
    endValue: (const float *)0x82000000,
    a8: v3,
    a9: v2,
    a10: &v6,
    a11: &v5);
  this->spawnCalled = false;
  this->needStopSound = false;
  this->timeToRotate = 450;
  this->rotationSound = nullptr;
  this->stopSound = nullptr;
  this->rotationStepAmount = 45.0;
  this->vehicleMGAmmo = nullptr;
  this->vehicleRocketAmmo = nullptr;
  this->vehicleEnergyAmmo = nullptr;
  this->shouldDeactivateCars = false;
  this->spawnTime = -1;
  this->cantEnterSound = nullptr;
  return this;
}


// ========================================================================
// __unwind$496805
// EA  : 0x82C63CE8
// RVA : 0x00C63CE8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_496805()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$496806
// EA  : 0x82C63D10
// RVA : 0x00C63D10
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_496806()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 844));
}


// ========================================================================
// ?GotoNextTarget@idTownGarageManager@@QAA_NXZ
// EA  : 0x82C63DF0
// RVA : 0x00C63DF0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idTownGarageManager::GotoNextTarget(idTownGarageManager *this)
{
  int num; // r10
  int v3; // r11
  int nextVehicleIndex; // r11
  int v5; // r11

  num = this->vehicles.num;
  if ( num <= 1 )
    return 0;
  if ( this->currentState != GARAGESTATE_NORMAL )
  {
    nextVehicleIndex = this->nextVehicleIndex;
    if ( nextVehicleIndex <= -1 )
      nextVehicleIndex = this->currentVehicleIndex;
    v5 = nextVehicleIndex + 1;
    this->nextVehicleIndex = v5;
    if ( v5 >= num )
      this->nextVehicleIndex = 0;
    return 1;
  }
  else
  {
    v3 = this->currentVehicleIndex + 1;
    this->nextVehicleIndex = v3;
    if ( v3 >= num )
      this->nextVehicleIndex = 0;
    idTownGarageManager::SetupAndMoveOffscreen(this);
    return 1;
  }
}


// ========================================================================
// ?GotoPreviousTarget@idTownGarageManager@@QAA_NXZ
// EA  : 0x82C63EA0
// RVA : 0x00C63EA0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idTownGarageManager::GotoPreviousTarget(idTownGarageManager *this)
{
  int num; // r10
  int v3; // r11
  int nextVehicleIndex; // r11
  int v5; // r11

  num = this->vehicles.num;
  if ( num <= 1 )
    return 0;
  if ( this->currentState != GARAGESTATE_NORMAL )
  {
    nextVehicleIndex = this->nextVehicleIndex;
    if ( nextVehicleIndex <= -1 )
      nextVehicleIndex = this->currentVehicleIndex;
    v5 = nextVehicleIndex - 1;
    this->nextVehicleIndex = v5;
    if ( v5 < 0 )
      this->nextVehicleIndex = num - 1;
    return 1;
  }
  else
  {
    v3 = this->currentVehicleIndex - 1;
    this->nextVehicleIndex = v3;
    if ( v3 < 0 )
      this->nextVehicleIndex = num - 1;
    idTownGarageManager::SetupAndMoveOffscreen(this);
    return 1;
  }
}


// ========================================================================
// ?SetupAndMoveBackOn@idTownGarageManager@@AAAXXZ
// EA  : 0x82C63F48
// RVA : 0x00C63F48
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::SetupAndMoveBackOn(idTownGarageManager *this)
{
  idMat3 *p_spawnOrientation; // r29
  idVec3 *p_spawnPosition; // r28
  idVehicle *vehicle; // r27
  idVehicle_vtbl *v5; // r30
  idAngles *v6; // r3
  idEntityPtr<idDynamicEntity> *p_shadowEntity; // r11
  idDynamicEntity *v8; // r3
  idDynamicEntity *v9; // r30
  idDynamicEntity_vtbl *v10; // r26
  idAngles *v11; // r3
  int nextVehicleIndex; // r7
  idTownGarageManager::vehicleInfo_t *list; // r6
  const idSoundShader *rotationSound; // r5
  __int128 v15; // r8
  double v16; // fp31
  __int64 v17; // r4
  double v18; // fp4
  int v19; // r7
  int v20; // r6
  const float *v21; // r5
  float v22[2]; // [sp+50h] [-60h] BYREF
  idMat3 v23[2]; // [sp+58h] [-58h] BYREF

  p_spawnOrientation = &this->spawnOrientation;
  p_spawnPosition = &this->spawnPosition;
  vehicle = this->vehicles.list[this->currentVehicleIndex].vehicle;
  v5 = vehicle->__vftable;
  v6 = idMat3::ToAngles(this: v23, result: (idAngles *)&this->spawnOrientation);
  v5->Teleport(this: vehicle, a2: p_spawnPosition, a3: v6);
  p_shadowEntity = &this->vehicles.list[this->currentVehicleIndex].shadowEntity;
  if ( gameLocal->spawnIds.ptr[p_shadowEntity->spawnId.value & 0x1FFF] == p_shadowEntity->spawnId.value >> 13 )
  {
    v8 = (idDynamicEntity *)gameLocal->entities.ptr[p_shadowEntity->spawnId.value & 0x1FFF];
    if ( v8 != nullptr )
      v9 = idDynamicEntity::CastTo(c: v8);
    else
      v9 = nullptr;
    v10 = v9->__vftable;
    v11 = idMat3::ToAngles(this: v23, result: (idAngles *)p_spawnOrientation);
    v10->Teleport(this: v9, a2: p_spawnPosition, a3: v11);
  }
  idEntity::BecomeInactive(this: this->vehicles.list[this->currentVehicleIndex].vehicle, flags: 2);
  nextVehicleIndex = this->nextVehicleIndex;
  list = this->vehicles.list;
  this->nextVehicleIndex = -1;
  this->currentVehicleIndex = nextVehicleIndex;
  idEntity::BecomeInactive(this: list[nextVehicleIndex].vehicle, flags: 2);
  rotationSound = this->rotationSound;
  this->currentState = GARAGESTATE_MOVINGTORETURN;
  if ( rotationSound != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BOOST,
      shader: rotationSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  LODWORD(v15) = this->timeToRotate;
  DWORD2(v15) = (int)v15 / 4;
  v22[0] = 0.0;
  DWORD1(v15) = gameLocal->__vftable;
  *(_QWORD *)&v23[0].mat[0].x = v15;
  v16 = (float)*(__int64 *)((char *)&v15 + 4);
  LODWORD(v17) = (*(int (__fastcall **)(idGameLocal *, int))(DWORD1(v15) + 156))(a1: gameLocal, a2: 1);
  HIDWORD(v17) = &this->rotationInterpolate;
  v18 = (float)*(__int64 *)&v23[0].mat[0].x;
  *(_QWORD *)&v23[0].mat[0].x = v17;
  idInterpolateAccelDecelLinear<float>::Init(
    this: &this->rotationInterpolate,
    startTime: (float)v17,
    accelTime: v16,
    decelTime: v16,
    duration: v18,
    startValue: (const float *)v17,
    endValue: v21,
    a8: v20,
    a9: v19,
    a10: &this->rotationStepAmount,
    a11: v22);
}


// ========================================================================
// ?SetSystemRotation@idTownGarageManager@@AAAXM@Z
// EA  : 0x82C64140
// RVA : 0x00C64140
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::SetSystemRotation(idTownGarageManager *this, double angle)
{
  double y; // fp13
  int value; // r9
  double z; // fp12
  idEntity *v6; // r3
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r31
  const idMat3 *v11; // r3
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r31
  idEntity_vtbl *v15; // r29
  idAngles *v16; // r3
  int v17; // r27
  int v18; // r29
  int v19; // r9
  idInfo *v20; // r3
  idInfo *v21; // r3
  int v22; // r9
  idInfo *v23; // r3
  idInfo *v24; // r31
  const idMat3 *v25; // r3
  idVehicle *vehicle; // r31
  idVehicle_vtbl *v27; // r24
  idAngles *v28; // r3
  idEntityPtr<idDynamicEntity> *p_shadowEntity; // r11
  idDynamicEntity *v30; // r3
  idDynamicEntity *v31; // r3
  idTownGarageManager::vehicleInfo_t *v32; // r11
  int v33; // r9
  idDynamicEntity *v34; // r3
  idDynamicEntity *v35; // r31
  const idMat3 *v36; // r3
  float *v37; // r3
  int v38; // r9
  idDynamicEntity *v39; // r3
  idDynamicEntity *v40; // r31
  idDynamicEntity_vtbl *v41; // r24
  idAngles *v42; // r3
  idRotation v43; // [sp+50h] [-170h] BYREF
  idRotation v44; // [sp+A0h] [-120h] BYREF
  idRotation v45; // [sp+E8h] [-D8h] BYREF
  idMat3 v46[3]; // [sp+138h] [-88h] BYREF

  y = this->spawnPosition.y;
  value = this->newRotateEnt.spawnId.value;
  z = this->spawnPosition.z;
  v44.origin.x = this->spawnPosition.x;
  v44.axisValid = false;
  v44.origin.y = y;
  v44.origin.z = z;
  v44.angle = angle;
  v44.axis.mat[0].x = mat3_identity.mat[0].x;
  v44.vec.x = 0.0;
  v44.vec.y = 0.0;
  v44.vec.z = 1.0;
  v44.axis.mat[0].y = mat3_identity.mat[0].y;
  v44.axis.mat[0].z = mat3_identity.mat[0].z;
  v44.axis.mat[1].x = mat3_identity.mat[1].x;
  v44.axis.mat[1].y = mat3_identity.mat[1].y;
  v44.axis.mat[1].z = mat3_identity.mat[1].z;
  v44.axis.mat[2].x = mat3_identity.mat[2].x;
  v44.axis.mat[2].y = mat3_identity.mat[2].y;
  v44.axis.mat[2].z = mat3_identity.mat[2].z;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idRotation::operator*(this: &v45, result: &v44, v: &v7->spawnPosition);
  v8 = this->newRotateEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
    v10 = idEntity::CastTo(c: v9);
  else
    v10 = nullptr;
  v11 = idRotation::ToMat3(this: &v44);
  idMat3::operator*(this: (idMat3 *)&v45.angle, result: &v10->spawnOrientation, a: v11);
  idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v45.angle);
  idMat3::FixDenormals(this: (idMat3 *)&v45.angle);
  v12 = this->newRotateEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
    v14 = idEntity::CastTo(c: v13);
  else
    v14 = nullptr;
  v15 = v14->__vftable;
  v16 = idMat3::ToAngles(this: (idMat3 *)&v43.axis.mat[2].y, result: (idAngles *)&v45.angle);
  v15->Teleport(this: v14, a2: &v45.origin, a3: v16);
  v17 = 0;
  if ( this->vehicles.num > 0 )
  {
    v18 = 0;
    do
    {
      if ( v17 == this->currentVehicleIndex )
      {
        v19 = this->focusBay.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
          && (v20 = (idInfo *)gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
        {
          v21 = idInfo::CastTo(c: v20);
        }
        else
        {
          v21 = nullptr;
        }
        idRotation::operator*(this: &v43, result: &v44, v: &v21->spawnPosition);
        if ( g_towngarage_use_Zadjust.valueInteger != 0 )
          v43.origin.z = v43.origin.z + g_towngarage_Zadjust.valueFloat;
        else
          v43.origin.z = *(float *)&this->vehicles.list[v18].vehicle->playerKey->decl[1].entityDef + v43.origin.z;
        v22 = this->focusBay.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
          && (v23 = (idInfo *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
        {
          v24 = idInfo::CastTo(c: v23);
        }
        else
        {
          v24 = nullptr;
        }
        v25 = idRotation::ToMat3(this: &v44);
        idMat3::operator*(this: (idMat3 *)&v43.vec.y, result: &v24->spawnOrientation, a: v25);
        idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v43.vec.y);
        idMat3::FixDenormals(this: (idMat3 *)&v43.vec.y);
        vehicle = this->vehicles.list[v18].vehicle;
        v27 = vehicle->__vftable;
        v28 = idMat3::ToAngles(this: v46, result: (idAngles *)&v43.vec.y);
        v27->Teleport(this: vehicle, a2: &v43.origin, a3: v28);
        p_shadowEntity = &this->vehicles.list[v18].shadowEntity;
        if ( gameLocal->spawnIds.ptr[p_shadowEntity->spawnId.value & 0x1FFF] == p_shadowEntity->spawnId.value >> 13 )
        {
          v30 = (idDynamicEntity *)gameLocal->entities.ptr[p_shadowEntity->spawnId.value & 0x1FFF];
          if ( v30 != nullptr )
            v31 = idDynamicEntity::CastTo(c: v30);
          else
            v31 = nullptr;
          idRotation::operator*(this: (idRotation *)&v43.axis.mat[2].y, result: &v44, v: &v31->spawnPosition);
          v32 = &this->vehicles.list[v18];
          v43.origin.y = v43.axis.mat[2].z;
          v43.origin.x = v43.axis.mat[2].y;
          v43.origin.z = *(float *)&v43.axisValid;
          v33 = v32->shadowEntity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v33 & 0x1FFF] == v33 >> 13
            && (v34 = (idDynamicEntity *)gameLocal->entities.ptr[v33 & 0x1FFF]) != nullptr )
          {
            v35 = idDynamicEntity::CastTo(c: v34);
          }
          else
          {
            v35 = nullptr;
          }
          v36 = idRotation::ToMat3(this: &v44);
          v37 = (float *)idMat3::operator*(this: (idMat3 *)&v46[0].mat[2], result: &v35->spawnOrientation, a: v36);
          v43.vec.y = *v37;
          v43.vec.z = v37[1];
          v43.angle = v37[2];
          v43.axis.mat[0].x = v37[3];
          v43.axis.mat[0].y = v37[4];
          v43.axis.mat[0].z = v37[5];
          v43.axis.mat[1].x = v37[6];
          v43.axis.mat[1].y = v37[7];
          v43.axis.mat[1].z = v37[8];
          idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v43.vec.y);
          idMat3::FixDenormals(this: (idMat3 *)&v43.vec.y);
          v38 = this->vehicles.list[v18].shadowEntity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v38 & 0x1FFF] == v38 >> 13
            && (v39 = (idDynamicEntity *)gameLocal->entities.ptr[this->vehicles.list[v18].shadowEntity.spawnId.value
                                                               & 0x1FFF]) != nullptr )
          {
            v40 = idDynamicEntity::CastTo(c: v39);
          }
          else
          {
            v40 = nullptr;
          }
          v41 = v40->__vftable;
          v42 = idMat3::ToAngles(this: (idMat3 *)&v45.axisValid, result: (idAngles *)&v43.vec.y);
          v41->Teleport(this: v40, a2: &v43.origin, a3: v42);
        }
      }
      idEntity::BecomeInactive(this: this->vehicles.list[v18].vehicle, flags: 2);
      ++v17;
      ++v18;
    }
    while ( v17 < this->vehicles.num );
  }
}


// ========================================================================
// ?StopMovingEffects@idTownGarageManager@@AAAXXZ
// EA  : 0x82C646A8
// RVA : 0x00C646A8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::StopMovingEffects(idTownGarageManager *this)
{
  const idSoundShader *stopSound; // r5
  int value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r3

  stopSound = this->stopSound;
  if ( stopSound != nullptr && this->needStopSound )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BOOST,
      shader: stopSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    this->needStopSound = false;
  }
  value = this->effectEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
      v5 = idEntity::CastTo(c: v4);
    else
      v5 = nullptr;
    idEntity::Activate(this: v5, activator: this);
  }
}


// ========================================================================
// ?Update@idTownGarageManager@@QAAXXZ
// EA  : 0x82C64768
// RVA : 0x00C64768
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::Update(idTownGarageManager *this)
{
  __int64 v2; // r9
  idTownGarageManager::garageState_t currentState; // r11
  int nextVehicleIndex; // r11
  int currentVehicleIndex; // r10
  idTownGarageManager::vehicleInfo_t *list; // r9
  __int64 v7; // r9
  double v8; // fp31
  double CurrentValue; // fp1

  if ( this->currentState != GARAGESTATE_NORMAL )
  {
    LODWORD(v2) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( (float)v2 >= (double)(float)((float)((float)(this->rotationInterpolate.decelTime
                                                    + this->rotationInterpolate.linearTime)
                                            + this->rotationInterpolate.accelTime)
                                    + this->rotationInterpolate.startTime) )
    {
      currentState = this->currentState;
      if ( currentState == GARAGESTATE_MOVINGTOHIDE )
      {
        idTownGarageManager::SetupAndMoveBackOn(this);
      }
      else if ( currentState == GARAGESTATE_MOVINGTORETURN )
      {
        nextVehicleIndex = this->nextVehicleIndex;
        if ( nextVehicleIndex <= -1 || this->currentVehicleIndex == nextVehicleIndex )
        {
          currentVehicleIndex = this->currentVehicleIndex;
          list = this->vehicles.list;
          this->nextVehicleIndex = -1;
          idEntity::BecomeInactive(this: list[currentVehicleIndex].vehicle, flags: 2);
          this->currentState = GARAGESTATE_NORMAL;
          idTownGarageManager::StopMovingEffects(this);
        }
        else
        {
          idTownGarageManager::SetupAndMoveOffscreen(this);
        }
      }
    }
    LODWORD(v7) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v8 = (float)v7;
    idInterpolateAccelDecelLinear<float>::SetPhase(this: &this->rotationInterpolate, time: v8);
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->rotationInterpolate.extrapolate, time: v8);
    idTownGarageManager::SetSystemRotation(this, angle: CurrentValue);
  }
}


// ========================================================================
// ?Spawn@idInfoDebugText@@QAAXXZ
// EA  : 0x82C648C0
// RVA : 0x00C648C0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoDebugText::Spawn(idInfoDebugText *this)
{
  idPhysics *Physics; // r3
  idLinkList<idEntity> *head; // r4
  idPhysics *v4; // r3
  char *data; // r29
  double textScale; // fp31
  BOOL depthTest; // r28
  idColor *p_textColor; // r27
  idRenderWorld_vtbl *v9; // r31
  int v10; // r3
  int v11; // r6

  if ( idLib::production == PROD_PRODUCTION )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    head = gameLocal->removeEntities.head;
    this->removeNode.prev->next = this->removeNode.next;
    this->removeNode.next->prev = this->removeNode.prev;
    this->removeNode.prev = &this->removeNode;
    this->removeNode.head = &this->removeNode;
    this->removeNode.next = head;
    this->removeNode.prev = head->prev;
    head->prev = &this->removeNode;
    this->removeNode.prev->next = &this->removeNode;
    this->removeNode.head = head->head;
  }
  else if ( this->permanent )
  {
    if ( this->text.len != 0 )
    {
      v4 = idEntity::GetPhysics(this);
      data = this->text.data;
      textScale = this->textScale;
      depthTest = this->depthTest;
      p_textColor = &this->textColor;
      v9 = clientGame->renderWorld->__vftable;
      v10 = (int)v4->GetOrigin(this: v4, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, char *, int, int, idColor *, int, int, BOOL, double))v9->DebugText)(
        a1: clientGame->renderWorld,
        a2: data,
        a3: v10,
        a4: v11,
        a5: p_textColor,
        a6: 1,
        a7: 0x7FFFFFFF,
        a8: depthTest,
        a9: (float)((float)textScale * (float)0.25));
    }
  }
  else
  {
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ??0idInfoLookTarget@@QAA@XZ
// EA  : 0x82C64A20
// RVA : 0x00C64A20
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoLookTarget *__fastcall idInfoLookTarget::idInfoLookTarget(idInfoLookTarget *this)
{
  idEntity::idEntity(this);
  this->lookTime = 3.0;
  this->lookDelay = 3.0;
  this->__vftable = (idInfoLookTarget_vtbl *)&idInfoLookTarget::`vftable';
  this->maxDist = 512.0;
  this->aim = true;
  this->lookerInfo[0].looker.spawnId.value = 0x1FFF;
  this->lookerInfo[0].nextLookTime = -1;
  this->lookerInfo[1].looker.spawnId.value = 0x1FFF;
  this->lookerInfo[1].nextLookTime = -1;
  this->lookerInfo[2].looker.spawnId.value = 0x1FFF;
  this->lookerInfo[2].nextLookTime = -1;
  this->nextLookerInfo = 0;
  return this;
}


// ========================================================================
// ?SetLooking@idInfoLookTarget@@QAAXPBVidEntity@@@Z
// EA  : 0x82C64AA8
// RVA : 0x00C64AA8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoLookTarget::SetLooking(idInfoLookTarget *this, const idEntity *looker)
{
  int nextLookerInfo; // r31
  idInfoLookTarget::lookerInfo_t *lookerInfo; // r29
  idGameLocal *v6; // r10
  idEntity *v7; // r3
  idEntity *v8; // r3
  int v9; // r9
  int v10; // r29

  nextLookerInfo = 0;
  lookerInfo = this->lookerInfo;
  v6 = gameLocal;
  while ( 1 )
  {
    if ( v6->spawnIds.ptr[lookerInfo->looker.spawnId.value & 0x1FFF] == lookerInfo->looker.spawnId.value >> 13
      && (v7 = v6->entities.ptr[lookerInfo->looker.spawnId.value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      v6 = gameLocal;
    }
    else
    {
      v8 = nullptr;
    }
    if ( v8 == looker )
      break;
    ++nextLookerInfo;
    ++lookerInfo;
    if ( nextLookerInfo >= 3 )
      goto LABEL_10;
  }
  if ( nextLookerInfo < 0 )
  {
LABEL_10:
    nextLookerInfo = this->nextLookerInfo;
    this->nextLookerInfo = nextLookerInfo + 1;
    v6 = gameLocal;
  }
  v9 = 8 * (nextLookerInfo + 102);
  if ( looker != nullptr )
    *(idInfoLookTarget_vtbl **)((char *)&this->__vftable + v9) = (idInfoLookTarget_vtbl *)((v6->spawnIds.ptr[looker->entityNumber] << 13)
                                                                                         | looker->entityNumber);
  else
    *(idInfoLookTarget_vtbl **)((char *)&this->__vftable + v9) = (idInfoLookTarget_vtbl *)0x1FFF;
  v10 = (int)(float)(this->lookDelay * (float)1000.0);
  this->lookerInfo[nextLookerInfo].nextLookTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v10;
}


// ========================================================================
// ??0idInfoSplineChild@@QAA@XZ
// EA  : 0x82C64BD0
// RVA : 0x00C64BD0
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoSplineChild *__fastcall idInfoSplineChild::idInfoSplineChild(idInfoSplineChild *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoSplineChild_vtbl *)&idInfoSplineChild::`vftable';
  this->splineLoc.splinePath.spawnId.value = 0x1FFF;
  this->splineLoc.controlPointLength = -1.0;
  this->splineLoc.lengthOnSpline = 0.0;
  this->splineLoc.controlPointOrigin = vec3_origin;
  this->splineLoc.controlPointIndex = 0;
  this->splineLoc.controlPointPCT = 0.0;
  this->splineLoc.controlPointOrigin = vec3_origin;
  this->splineLoc.controlPointOriginNext = vec3_origin;
  this->splineLoc.initialized = false;
  this->splineLoc.dirty = false;
  return this;
}


// ========================================================================
// ??1idInfoGarageBay@@UAA@XZ
// EA  : 0x82C64CF8
// RVA : 0x00C64CF8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoGarageBay::~idInfoGarageBay(idInfoGarageBay *this)
{
  int entityNumber; // r10
  idList<idEntityPtr<idEntity>,58> *p_infoGarageBays; // r3
  int v4; // r4
  int num; // r9
  int v6; // r11

  entityNumber = this->entityNumber;
  this->__vftable = (idInfoGarageBay_vtbl *)&idInfoGarageBay::`vftable';
  p_infoGarageBays = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->infoGarageBays;
  v4 = 0;
  num = gameLocal->infoGarageBays.num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( p_infoGarageBays->list[v6].spawnId.value != ((gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber) )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_infoGarageBays, index: v4);
  }
LABEL_8:
  idEntity::~idEntity(this);
}


// ========================================================================
// ?SetUpVehiclesForView@idTownGarageManager@@QAA_NXZ
// EA  : 0x82C64E00
// RVA : 0x00C64E00
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

int __fastcall idTownGarageManager::SetUpVehiclesForView(idTownGarageManager *this)
{
  int num; // r9
  int currentVehicleIndex; // r11

  num = this->vehicles.num;
  if ( num <= 0 )
    return 0;
  if ( gameLocal->spawnIds.ptr[this->focusBay.spawnId.value & 0x1FFF] != this->focusBay.spawnId.value >> 13
    || (_cntlzw((this->newRotateEnt.spawnId.value >> 13) - gameLocal->spawnIds.ptr[this->newRotateEnt.spawnId.value
                                                                                 & 0x1FFF])
      & 0x20) == 0 )
  {
    return 0;
  }
  currentVehicleIndex = this->currentVehicleIndex;
  if ( currentVehicleIndex < 0 || currentVehicleIndex >= num )
    this->currentVehicleIndex = 0;
  idTownGarageManager::ActivateCars(this);
  idTownGarageManager::SetSystemRotation(this, angle: 0.0);
  return 1;
}


// ========================================================================
// ?GetCurrentKey@idTownGarageManager@@QAAPAVidVehicleKey@@XZ
// EA  : 0x82C64EE8
// RVA : 0x00C64EE8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idVehicleKey *__fastcall idTownGarageManager::GetCurrentKey(idTownGarageManager *this)
{
  int num; // r11
  int currentVehicleIndex; // r10
  int nextVehicleIndex; // r11

  num = this->vehicles.num;
  if ( num <= 0 )
    return nullptr;
  currentVehicleIndex = this->currentVehicleIndex;
  if ( currentVehicleIndex < 0 || currentVehicleIndex >= num )
  {
    idTownGarageManager::SetUpVehiclesForView(this);
    return nullptr;
  }
  nextVehicleIndex = this->nextVehicleIndex;
  if ( nextVehicleIndex <= -1 )
    return this->vehicles.list[currentVehicleIndex].vehicle->playerKey;
  else
    return this->vehicles.list[nextVehicleIndex].vehicle->playerKey;
}


// ========================================================================
// ??1idInfoLookTargetGroup@@UAA@XZ
// EA  : 0x82C64F78
// RVA : 0x00C64F78
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoLookTargetGroup::~idInfoLookTargetGroup(idInfoLookTargetGroup *this)
{
  int entityNumber; // r10
  idList<idEntityPtr<idEntity>,58> *p_lookTargetGroups; // r3
  int v4; // r4
  int num; // r9
  int v6; // r11

  entityNumber = this->entityNumber;
  this->__vftable = (idInfoLookTargetGroup_vtbl *)&idInfoLookTargetGroup::`vftable';
  p_lookTargetGroups = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->lookTargetGroups;
  v4 = 0;
  num = gameLocal->lookTargetGroups.num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( p_lookTargetGroups->list[v6].spawnId.value != ((gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber) )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_lookTargetGroups, index: v4);
  }
LABEL_8:
  idEntity::~idEntity(this);
}


// ========================================================================
// ?SpawnVehicles@idTownGarageManager@@QAAXPAVidPlayer@@@Z
// EA  : 0x82C65460
// RVA : 0x00C65460
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idTownGarageManager::SpawnVehicles(idTownGarageManager *this, idPlayer *player)
{
  int v4; // r28
  idGameLocal *v5; // r10
  int v6; // r29
  idTownGarageManager::vehicleShadowInfo_t *v7; // r11
  int value; // r8
  idDynamicEntity *v9; // r3
  idDynamicEntity *v10; // r30
  idDynamicEntity_vtbl *v11; // r26
  idAngles *v12; // r3
  idInventoryCollection *v13; // r3
  int v14; // r18
  int v15; // r23
  int v16; // r27
  char v17; // r8
  int v18; // r10
  int v19; // r11
  float y; // r6
  float *v21; // r10
  float z; // r8
  float *p_z; // r11
  double x; // fp13
  int v25; // ctr
  double v26; // fp12
  double v27; // fp11
  idGameLocal *v28; // r3
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  idVehicle *v34; // r3
  idVehicle *v35; // r3
  idVehicle *v36; // r26
  idStr *v37; // r28
  int v38; // r11
  size_t len; // r29
  int v40; // r4
  idPresentable *presentable; // r11
  char v42; // r10
  idPresentable *v43; // r11
  idRenderModel *RenderModelFromPresentable; // r3
  int i; // r30
  idPresentable *v46; // r3
  int v47; // r3
  idPresentable *v48; // r3
  bool v49; // zf
  int v50; // r3
  int v51; // r3
  int v52; // r9
  int v53; // r30
  idInfo *v54; // r3
  idInfo *v55; // r3
  int num; // r11
  int v57; // r8
  idTownGarageManager::vehicleShadowInfo_t *list; // r7
  int v59; // r10
  char flags; // r11
  int v61; // r10
  int v62; // r10
  int v63; // r11
  idTownGarageManager::vehicleInfo_t v64; // [sp+58h] [-108h] BYREF
  idMat3 v65; // [sp+60h] [-100h] BYREF
  float v66[49]; // [sp+9Ch] [-C4h] BYREF

  this->spawnCalled = true;
  this->spawnTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->shouldDeactivateCars = true;
  idEntity::BecomeActive(this, flags: 1);
  v4 = 0;
  if ( this->shadowInfoList.num > 0 )
  {
    v5 = gameLocal;
    v6 = 0;
    do
    {
      v7 = &this->shadowInfoList.list[v6];
      value = v7->shadowEntity.spawnId.value;
      if ( v5->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v9 = (idDynamicEntity *)v5->entities.ptr[v7->shadowEntity.spawnId.value & 0x1FFF];
        if ( v9 != nullptr )
          v10 = idDynamicEntity::CastTo(c: v9);
        else
          v10 = nullptr;
        v11 = v10->__vftable;
        v12 = idMat3::ToAngles(this: &v65, result: (idAngles *)&this->spawnOrientation);
        v11->Teleport(this: v10, a2: &this->spawnPosition, a3: v12);
        v5 = gameLocal;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->shadowInfoList.num );
  }
  LODWORD(v65.mat[2].y) = 1280;
  memset(&v65.mat[1].y, 0, 12);
  v13 = player->GetInventory_2(this: player);
  idInventoryCollection::GetVehicleKeys(this: v13, vehicleList: (idList<idVehicleKey *,5> *)&v65.mat[1].y);
  v14 = LODWORD(v65.mat[1].z) - 1;
  if ( LODWORD(v65.mat[1].z) - 1 >= 0 )
  {
    v15 = 4 * v14;
    do
    {
      v16 = *(_DWORD *)(v15 + LODWORD(v65.mat[1].y));
      if ( *(_DWORD *)(v16 + 140) == this->garage )
      {
        v17 = 0;
        v18 = 0;
        if ( this->vehicles.num > 0 )
        {
          v19 = 0;
          while ( this->vehicles.list[v19].vehicle->playerKey != (idVehicleKey *)v16 )
          {
            ++v18;
            ++v19;
            if ( v18 >= this->vehicles.num )
              goto LABEL_18;
          }
          v17 = 1;
        }
LABEL_18:
        if ( v17 == 0 )
        {
          y = this->spawnPosition.y;
          v21 = v66;
          z = this->spawnPosition.z;
          p_z = &this->spawnPosition.z;
          v65.mat[0].x = this->spawnPosition.x;
          x = v65.mat[0].x;
          v65.mat[0].y = y;
          v65.mat[0].z = z;
          *(float *)(v16 + 156) = z;
          v25 = 9;
          *(float *)(v16 + 152) = y;
          *(float *)(v16 + 148) = x;
          do
          {
            *++v21 = *++p_z;
            --v25;
          }
          while ( v25 != 0 );
          *(float *)(v16 + 160) = v66[1];
          v26 = v66[2];
          v27 = v66[3];
          *(float *)(v16 + 172) = v66[4];
          v28 = gameLocal;
          v29 = v66[5];
          *(float *)(v16 + 164) = v26;
          *(float *)(v16 + 168) = v27;
          v30 = v66[6];
          *(float *)(v16 + 176) = v29;
          v31 = v66[7];
          *(float *)(v16 + 180) = v30;
          v32 = v66[8];
          *(float *)(v16 + 184) = v31;
          v33 = v66[9];
          *(float *)(v16 + 188) = v32;
          *(float *)(v16 + 192) = v33;
          v34 = (idVehicle *)idGameLocal::SpawnPlayerVehicle(this: v28, key: (idVehicleKey *)v16);
          v35 = idVehicle::CastTo(c: v34);
          v36 = v35;
          if ( v35 != nullptr )
          {
            idVehicle::SetArmorFromKey(this: v35, key: (idVehicleKey *)v16);
            v37 = idStr::idStr(this: (idStr *)&v65.mat[2].z, text: v36->name.data);
            v38 = *(_DWORD *)(v16 + 204);
            len = v37->len;
            v40 = v37->len + 1;
            if ( v38 >= 0 )
            {
              if ( v40 > (v38 & 0x7FFFFFFF) )
                idStr::ReAllocate(this: (idStr *)(v16 + 196), amount: v40, keepold: false);
            }
            else if ( v40 > (v38 & 0x7FFFFFFF)
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v16 + 200), Src: v37->data, Size: len);
            *(_BYTE *)(*(_DWORD *)(v16 + 200) + len) = 0;
            *(_DWORD *)(v16 + 196) = len;
            idStr::FreeData(this: v37);
            presentable = v36->presentable;
            if ( presentable == nullptr || (v42 = 1, presentable->model == nullptr) )
              v42 = 0;
            if ( v42 != 0 )
            {
              if ( presentable == nullptr )
              {
                idEntity::InitPresentableInternal(this: v36);
                presentable = v36->presentable;
              }
              *((_BYTE *)&presentable->model->g + 106) |= 1u;
              v43 = v36->presentable;
              if ( v43 == nullptr )
              {
                idEntity::InitPresentableInternal(this: v36);
                v43 = v36->presentable;
              }
              *((_BYTE *)&v43->model->g + 105) |= 0x10u;
              RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v36);
              *((_BYTE *)&RenderModelFromPresentable->g + 104) |= 0x80u;
              idEntity::GetRenderModelFromPresentable(this: v36)->g.castDimShadows = DIMSHADOW_HIGH_QUALITY;
            }
            for ( i = 0; ; ++i )
            {
              v46 = v36->presentable;
              v47 = v46 != nullptr ? (int)v46->GetVehicleInterface(this: v46) : 0;
              v49 = i >= (*(int (__fastcall **)(int))(*(_DWORD *)(v47 + 16512) + 12))(a1: v47 + 16512);
              v48 = v36->presentable;
              if ( v49 )
                break;
              if ( v48 != nullptr )
                v50 = (int)v48->GetVehicleInterface(this: v48);
              else
                v50 = 0;
              (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v50 + 16512) + 24))(a1: v50 + 16512, a2: 0, a3: i);
            }
            if ( v48 != nullptr )
              v51 = (int)v48->GetVehicleInterface(this: v48);
            else
              v51 = 0;
            v52 = this->focusBay.spawnId.value;
            v53 = v51 + 16512;
            if ( gameLocal->spawnIds.ptr[v52 & 0x1FFF] == v52 >> 13
              && (v54 = (idInfo *)gameLocal->entities.ptr[v52 & 0x1FFF]) != nullptr )
            {
              v55 = idInfo::CastTo(c: v54);
            }
            else
            {
              v55 = nullptr;
            }
            (*(void (__fastcall **)(int, idMat3 *, int))(*(_DWORD *)v53 + 52))(
              a1: v53,
              a2: &v55->spawnOrientation,
              a3: -1);
            if ( *(_BYTE *)(v16 + 41) != 0 )
            {
              idVehicleKey::DoTotalRepair(this: (idVehicleKey *)v16);
              *(_BYTE *)(v16 + 41) = 0;
            }
            num = this->shadowInfoList.num;
            v57 = 0;
            v64.vehicle = v36;
            v64.shadowEntity.spawnId.value = 0x1FFF;
            if ( num > 0 )
            {
              list = this->shadowInfoList.list;
              v59 = 0;
              while ( gameLocal->spawnIds.ptr[list[v59].shadowEntity.spawnId.value & 0x1FFF] != list[v59].shadowEntity.spawnId.value >> 13
                   || *(const idDeclVehicleKey **)(v16 + 12) != list[v59].keyDecl )
              {
                ++v57;
                ++v59;
                if ( v57 >= this->shadowInfoList.num )
                  goto LABEL_62;
              }
              v64.shadowEntity.spawnId.value = list[v57].shadowEntity.spawnId.value;
            }
LABEL_62:
            idEntity::SetPrivateLightOnly(this: v36, set: true);
            flags = (char)v36->flags;
            v36->vehicleAnimator.updateWheelAngle = false;
            *(_BYTE *)&v36->flags = flags & 0xFD;
            idList<idTownGarageManager::vehicleInfo_t,5>::Append(this: &this->vehicles, obj: &v64);
          }
          else
          {
            idLib::Warning(
              fmt: "Error spawning vehicle from key %s",
              *(const char **)(*(_DWORD *)(*(_DWORD *)(v16 + 12) + 508) + 8));
          }
          v61 = *(unsigned __int8 *)(v16 + 145);
          *(_BYTE *)(v16 + 144) = 0;
          if ( v61 != 0 )
          {
            v62 = 0;
            if ( this->vehicles.num > 0 )
            {
              v63 = 0;
              while ( this->vehicles.list[v63].vehicle->playerKey != (idVehicleKey *)v16 )
              {
                ++v62;
                ++v63;
                if ( v62 >= this->vehicles.num )
                  goto LABEL_71;
              }
              this->currentVehicleIndex = v62;
            }
LABEL_71:
            *(_BYTE *)(v16 + 145) = 0;
          }
        }
      }
      --v14;
      v15 -= 4;
    }
    while ( v14 >= 0 );
  }
  idTownGarageManager::DeactivateCars(this);
  if ( (LOBYTE(v65.mat[2].y) == 0 || LOBYTE(v65.mat[2].y) == 2) && LODWORD(v65.mat[1].y) != 0 )
    idMem::Free(this: &mem, ptr: (void *)LODWORD(v65.mat[1].y), align: ALIGN_16);
}


// ========================================================================
// __unwind$499628
// EA  : 0x82C65B18
// RVA : 0x00C65B18
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_499628()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$499828_0
// EA  : 0x82C65B40
// RVA : 0x00C65B40
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_499828_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 352 + 80));
}


// ========================================================================
// ?Spawn@idInfoLookTargetGroup@@QAAXXZ
// EA  : 0x82C65B68
// RVA : 0x00C65B68
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoLookTargetGroup::Spawn(idInfoLookTargetGroup *this)
{
  idEntityPtr<idEntity> v1; // [sp+50h] [-10h] BYREF

  if ( this != nullptr )
    v1.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v1.spawnId.value = 0x1FFF;
  idList<idEntityPtr<idEntity>,58>::Append(
    this: (idList<idEntityPtr<idEntity>,58> *)&gameLocal->lookTargetGroups,
    obj: &v1);
}


// ========================================================================
// ?Spawn@idInfoGarageBay@@QAAXXZ
// EA  : 0x82C65C48
// RVA : 0x00C65C48
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoGarageBay::Spawn(idInfoGarageBay *this)
{
  idEntityPtr<idAI2> *v2; // r3

  v2 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->infoGarageBays);
  if ( this != nullptr )
    v2->spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2->spawnId.value = 0x1FFF;
}


// ========================================================================
// ??0idInfoPath@@QAA@XZ
// EA  : 0x82C65CC8
// RVA : 0x00C65CC8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

idInfoPath *__fastcall idInfoPath::idInfoPath(idInfoPath *this)
{
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp0

  idEntity::idEntity(this);
  this->__vftable = (idInfoPath_vtbl *)&idInfoPath::`vftable';
  this->plugAnim.minLoopTime = 5.0;
  this->plugAnim.plugAnims.granularity = 0;
  this->plugAnim.maxLoopTime = 10.0;
  this->plugAnim.plugAnims.memTag = 5;
  this->plugAnim.plugAnims.listStatic = 0;
  this->plugAnim.plugAnims.list = nullptr;
  this->plugAnim.plugAnims.size = 0;
  this->plugAnim.plugAnims.num = 0;
  this->plugAnim.priority = ALERTCYCLE_RELAXED;
  this->plugAnim.stateInfo.animWebStates = nullptr;
  this->plugAnim.stateInfo.currentState = 0;
  this->plugAnim.stateInfo.animWebStates = &this->plugAnim.plugAnims;
  this->actionScript.granularity = 0;
  this->actionScript.memTag = 5;
  this->actionScript.listStatic = 0;
  this->actionScript.list = nullptr;
  this->actionScript.size = 0;
  this->actionScript.num = 0;
  this->focus.spawnId.value = 0x1FFF;
  this->stopTime = 0.0;
  *(double *)&v2 = 0.99984771;
  v3 = acos(x: v2);
  v4 = idMath::M_RAD2DEG;
  this->turnEarly = false;
  this->alignmentTolerance = (float)v4 * (float)*(double *)&v3;
  this->lookAtNextPoint = false;
  this->alignToNode = false;
  this->keepFocusInView = false;
  *(_WORD *)&this->interactionPoint = 1;
  this->abortForSearch = true;
  this->walkState = WALKSTATE_WALKING;
  this->standState = STANDSTATE_DEFAULT;
  this->sitState = SITSTATE_DEFAULT;
  this->walkMod = AIWALKMOD_DEFAULT;
  this->runMod = AIWALKMOD_DEFAULT;
  this->aasType = AAS_MONSTER48;
  this->playerLeftAnims.granularity = 0;
  this->playerLeftAnims.memTag = 5;
  this->playerLeftAnims.listStatic = 0;
  this->playerLeftAnims.list = nullptr;
  this->playerLeftAnims.size = 0;
  this->playerLeftAnims.num = 0;
  return this;
}


// ========================================================================
// __unwind$500742
// EA  : 0x82C65DFC
// RVA : 0x00C65DFC
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_500742()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$500743
// EA  : 0x82C65E24
// RVA : 0x00C65E24
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_500743()
{
  int v0; // r12

  idInfoPath::plugAnim_t::~plugAnim_t(this: (idInfoPath::plugAnim_t *)(*(_DWORD *)(v0 - 144 + 164) + 800));
}


// ========================================================================
// __unwind$500744
// EA  : 0x82C65E50
// RVA : 0x00C65E50
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_500744()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(*(_DWORD *)(v0 - 144 + 164) + 836));
}


// ========================================================================
// ?Spawn@idInfoPath@@QAAXXZ
// EA  : 0x82C66260
// RVA : 0x00C66260
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __fastcall idInfoPath::Spawn(idInfoPath *this)
{
  idAAS2 *AAS; // r3
  idAAS2 *v3; // r30
  idAAS2_vtbl *v4; // r25
  int v5; // r3
  int v6; // r3
  idAIActionParm *list; // r30
  int v8; // r26
  idAIActionParm *v9; // r30
  int v10; // [sp+60h] [-90h] BYREF
  idScriptAction v11[2]; // [sp+80h] [-70h] BYREF

  AAS = idGameLocal::LoadAAS(this: gameLocal, type: (const aasType_t)this->aasType);
  v3 = AAS;
  if ( AAS == nullptr || AAS->IsDefault(this: AAS) )
  {
    idLib::Warning(fmt: "idInfoPath '%s' - failed to load appropriate AAS.", this->name.data);
  }
  else
  {
    v4 = v3->__vftable;
    v5 = (int)v3->DefaultSearchBounds(this: (idAAS2 *)&v10, result: (idBounds *)v3);
    if ( v4->PointReachableAreaNum(
           this: v3,
           a2: nullptr,
           a3: &this->spawnPosition,
           a4: (const idBounds *)v5,
           a5: 2,
           a6: 1) <= 0 )
    {
      v6 = (int)v3->GetSettings(this: v3);
      idLib::Warning(fmt: "idInfoPath '%s' is outside of aas %s'", this->name.data, *(const char **)(v6 + 8));
    }
  }
  if ( this->stopTime > 0.0 )
  {
    v11[0].eventName.len = 0;
    v11[0].eventName.baseBuffer[0] = 0;
    v11[0].eventName.allocedAndFlag = 20;
    v11[0].eventName.data = v11[0].eventName.baseBuffer;
    v11[0].parms.granularity = 0;
    v11[0].parms.memTag = 5;
    v11[0].parms.listStatic = 0;
    v11[0].parms.list = nullptr;
    v11[0].parms.size = 0;
    v11[0].parms.num = 0;
    idStr::operator=(this: &v11[0].eventName, text: "action_Idle");
    if ( v11[0].parms.size < 2 )
      idList<idAIActionParm,5>::Resize(this: &v11[0].parms, newsize: 2);
    idList<idAIActionParm,5>::SetNum(this: &v11[0].parms, newNum: 2);
    list = v11[0].parms.list;
    v8 = (int)(float)(this->stopTime * (float)1000.0);
    idAIActionParm::Clear(this: v11[0].parms.list);
    list->intVal = v8;
    list->type = 1;
    list->subType = 0;
    v9 = v11[0].parms.list + 1;
    idAIActionParm::Clear(this: v11[0].parms.list + 1);
    v9->type = 1;
    v9->subType = 40;
    v9->intVal = 1;
    idList<idScriptAction,5>::Insert(this: &this->actionScript, obj: v11, index: 1);
    idScriptAction::~idScriptAction(this: v11);
  }
}


// ========================================================================
// __unwind$501049
// EA  : 0x82C6642C
// RVA : 0x00C6642C
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_501049()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$501018
// EA  : 0x82C66454
// RVA : 0x00C66454
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void _unwind_501018()
{
  int v0; // r12

  idScriptAction::~idScriptAction(this: (idScriptAction *)(v0 - 240 + 128));
}


// ========================================================================
// `dynamic initializer for 'g_towngarage_Zadjust''
// EA  : 0x833777F8
// RVA : 0x013777F8
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_towngarage_Zadjust__()
{
  idCVar::idCVar(
    this: &g_towngarage_Zadjust,
    name: "g_towngarage_Zadjust",
    value: "10",
    flags: 4,
    description: "vertical distance added to teleport spawn position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_towngarage_Zadjust__);
}


// ========================================================================
// `dynamic initializer for 'g_towngarage_use_Zadjust''
// EA  : 0x83377850
// RVA : 0x01377850
// PDB : w:\tech5\tungsten\game\entities\info.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_towngarage_use_Zadjust__()
{
  idCVar::idCVar(
    this: &g_towngarage_use_Zadjust,
    name: "g_towngarage_use_Zadjust",
    value: "0",
    flags: 1,
    description: "should we use the zadjust",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_towngarage_use_Zadjust__);
}

