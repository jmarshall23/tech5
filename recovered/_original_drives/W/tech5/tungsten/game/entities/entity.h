
// ========================================================================
// ?GetGamerTag@idLocalUserXbox@@UBAPBDXZ
// EA  : 0x824E3290
// RVA : 0x004E3290
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

idRenderModelInfo *__fastcall idLocalUserXbox::GetGamerTag(idEntity *this)
{
  return &this->renderModelInfo;
}


// ========================================================================
// ?GetJointIndexFromTrace@idEntity@@UAA?AV?$idIndex@FW4invalidJointIndex_t@@@@Utrace_t@@@Z
// EA  : 0x824E3298
// RVA : 0x004E3298
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

idEntity *__fastcall idEntity::GetJointIndexFromTrace(
        idEntity *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        trace_t *trace)
{
  HIWORD(this->__vftable) = NULL_JOINT_INDEX;
  return this;
}


// ========================================================================
// ?GetScriptObject@idEntity@@UBAABVidScriptObject@@XZ
// EA  : 0x824E32A8
// RVA : 0x004E32A8
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

const idScriptObject *__fastcall idEntity::GetScriptObject(idEntity *this)
{
  return &this->scriptObject;
}


// ========================================================================
// ?GetUsableDistance@idFocusTracker@@MBAMPBVidActor@@PBVidEntity@@@Z
// EA  : 0x824E32B0
// RVA : 0x004E32B0
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

float __fastcall idFocusTracker::GetUsableDistance(idEntity *this)
{
  double v1; // fp1

  v1 = 160.0;
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetVisibilityPoint@idEntity@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x824E32C0
// RVA : 0x004E32C0
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

void __fastcall idEntity::GetVisibilityPoint(idEntity *this, const aimPoint_t type, idVec3 *pos)
{
  *pos = *this->physics->GetOrigin(this: this->physics, a2: 0);
}


// ========================================================================
// ?GetEyePos@idEntity@@UBAXAAVidVec3@@@Z
// EA  : 0x824E3318
// RVA : 0x004E3318
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

void __fastcall idEntity::GetEyePos(idEntity *this, idVec3 *eyePos)
{
  *eyePos = *this->physics->GetOrigin(this: this->physics, a2: 0);
}


// ========================================================================
// ?IsVisible@idEntity@@UBA_NXZ
// EA  : 0x824E3370
// RVA : 0x004E3370
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

BOOL __fastcall idEntity::IsVisible(idEntity *this)
{
  idEntity *BindMaster; // r3
  bool v3; // zf

  v3 = idEntity::GetBindMaster(this) == nullptr;
  BindMaster = this;
  if ( !v3 )
    BindMaster = idEntity::GetBindMaster(this);
  return (_cntlzw((unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: BindMaster)) & 0x20) != 0;
}


// ========================================================================
// ?GetInputSettings@idProp_Zipline@@UAA?AUinputSettings_t@@PAVidPlayer@@@Z
// EA  : 0x824E33C0
// RVA : 0x004E33C0
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

idUtilityCamera *__fastcall idProp_Zipline::GetInputSettings(
        idUtilityCamera *this,
        inputSettings_t *result,
        idPlayer *player)
{
  double valueFloat; // fp13
  bool v4; // r7
  double v5; // fp12
  double v6; // fp11

  valueFloat = joy_pitchSpeed.valueFloat;
  v4 = in_invertLook.valueInteger != 0;
  v5 = joy_yawSpeed.valueFloat;
  v6 = m_sensitivity.valueFloat;
  this->__vftable = nullptr;
  this->name.baseBuffer[0] = 0;
  *(float *)&this->listenerList = 1.0;
  this->name.baseBuffer[1] = v4;
  *(float *)&this->listeningToList = 1.0;
  *(float *)&this->name.len = valueFloat;
  *(float *)&this->name.data = v5;
  *(float *)&this->name.allocedAndFlag = v6;
  return this;
}


// ========================================================================
// ?GetLinearVelocity@idEntity@@QBA?AVidVec3@@XZ
// EA  : 0x829F0860
// RVA : 0x009F0860
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

idEntity *__fastcall idEntity::GetLinearVelocity(idEntity *this, idEntity *result)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this: result);
  Physics->GetLinearVelocity((idPhysics *)this, result: (idVec3 *)Physics, a3: 0);
  return this;
}


// ========================================================================
// ?GetTarget@idEntity@@QBAPAV1@H@Z
// EA  : 0x829FBDB8
// RVA : 0x009FBDB8
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

idEntity *__fastcall idEntity::GetTarget(idEntity *this, int i)
{
  int value; // r9
  idEntity *v3; // r3

  if ( i < this->targets.num
    && (value = this->targets.list[i].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v3 = gameLocal->entities.ptr[this->targets.list[i].spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v3);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntityDefName@idEntity@@QBAPBDXZ
// EA  : 0x82A35470
// RVA : 0x00A35470
// PDB : w:\tech5\tungsten\game\entities\entity.h
// ========================================================================

const char *__fastcall idEntity::GetEntityDefName(idEntity *this)
{
  const idDeclEntityDef *entityDef; // r11

  entityDef = this->entityDef;
  if ( entityDef != nullptr )
    return entityDef->name.str;
  else
    return "*unknown*";
}

