
// ========================================================================
// ??1idAIDeathVolume@@UAA@XZ
// EA  : 0x82A422C0
// RVA : 0x00A422C0
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void __fastcall idAIDeathVolume::~idAIDeathVolume(idAIDeathVolume *this)
{
  this->__vftable = (idAIDeathVolume_vtbl *)&idAIDeathVolume::`vftable';
  idStr::FreeData(this: &this->animFacingRefBack);
  idStr::FreeData(this: &this->animFacingRefRight);
  idStr::FreeData(this: &this->animFacingRefLeft);
  idStr::FreeData(this: &this->animFacingRefFwd);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$487627
// EA  : 0x82A4232C
// RVA : 0x00A4232C
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void _unwind_487627()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487628
// EA  : 0x82A42354
// RVA : 0x00A42354
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void _unwind_487628()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 848));
}


// ========================================================================
// __unwind$487629
// EA  : 0x82A42380
// RVA : 0x00A42380
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void _unwind_487629()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// __unwind$487630
// EA  : 0x82A423AC
// RVA : 0x00A423AC
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void _unwind_487630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 912));
}


// ========================================================================
// ?Spawn@idAIDeathVolume@@QAAXXZ
// EA  : 0x82A423D8
// RVA : 0x00A423D8
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void __fastcall idAIDeathVolume::Spawn(idAIDeathVolume *this)
{
  if ( (float)((float)(this->referenceDir.z * this->referenceDir.z)
             + (float)((float)(this->referenceDir.x * this->referenceDir.x)
                     + (float)(this->referenceDir.y * this->referenceDir.y))) < 0.0099999998 )
    idLib::Error(fmt: "idAIDeathVolume '%s' has a referenceDir with zero length", this->name.data);
}


// ========================================================================
// ??0idAIDeathVolume@@QAA@XZ
// EA  : 0x82A42418
// RVA : 0x00A42418
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

idAIDeathVolume *__fastcall idAIDeathVolume::idAIDeathVolume(idAIDeathVolume *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idAIDeathVolume_vtbl *)&idAIDeathVolume::`vftable';
  this->referenceDir.y = 0.0;
  this->referenceDir.z = 0.0;
  this->referenceDir.x = 1.0;
  this->unidirectional = true;
  this->makeRagdollTouchTriggers = false;
  this->killDuration = 3.0;
  this->damageDecl = nullptr;
  this->animFacingRefFwd.data = this->animFacingRefFwd.baseBuffer;
  this->animFacingRefFwd.allocedAndFlag = 20;
  this->animFacingRefFwd.len = 0;
  this->animFacingRefFwd.baseBuffer[0] = 0;
  this->animFacingRefLeft.allocedAndFlag = 20;
  this->animFacingRefLeft.data = this->animFacingRefLeft.baseBuffer;
  this->animFacingRefLeft.len = 0;
  this->animFacingRefLeft.baseBuffer[0] = 0;
  this->animFacingRefRight.allocedAndFlag = 20;
  this->animFacingRefRight.data = this->animFacingRefRight.baseBuffer;
  this->animFacingRefRight.len = 0;
  this->animFacingRefRight.baseBuffer[0] = 0;
  this->animFacingRefBack.allocedAndFlag = 20;
  this->animFacingRefBack.data = this->animFacingRefBack.baseBuffer;
  this->animFacingRefBack.len = 0;
  this->animFacingRefBack.baseBuffer[0] = 0;
  this->lastActivator.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?Event_Touch@idAIDeathVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82A42560
// RVA : 0x00A42560
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

idAIDeathVolume *__fastcall idAIDeathVolume::Event_Touch(
        idAIDeathVolume *this,
        eventVoid *result,
        idAI2 *toucher,
        int clipModelId)
{
  idAI2 *v7; // r3
  idAI2 *v8; // r30
  idEntity *v9; // r5
  int v10; // r6
  char v12; // [sp+50h] [-50h] BYREF
  float v13; // [sp+58h] [-48h]
  float v14; // [sp+5Ch] [-44h]
  float v15; // [sp+60h] [-40h]

  idVolume::Event_Touch(this: (idVolume *)&v12, result, other: toucher, clipModelId);
  v7 = idAI2::CastTo(c: toucher);
  v8 = v7;
  if ( v7 != nullptr
    && ((double (__fastcall *)(idAIHealth *))v7->aiHealth.GetCurBaseHealth_Impl)(a1: &v7->aiHealth) > 0.0
    && !v8->IsDead(this: v8)
    && !v8->IsDying(this: v8) )
  {
    if ( idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[976]) != nullptr )
      v9 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[976]);
    else
      v9 = (idEntity *)result;
    v13 = 0.0;
    v14 = 0.0;
    v10 = *(_DWORD *)&result[844];
    v15 = 1.0;
    ((void (__fastcall *)(idAI2 *, eventVoid *, idEntity *, int))v8->Damage)(a1: v8, a2: result, a3: v9, a4: v10);
  }
  return this;
}


// ========================================================================
// ?Event_StopKilling@idAIDeathVolume@@QAA?AVeventVoid@@XZ
// EA  : 0x82A42670
// RVA : 0x00A42670
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

idAIDeathVolume *__fastcall idAIDeathVolume::Event_StopKilling(idAIDeathVolume *this, idVolume *result)
{
  idVolume::DisableTouch(this: result);
  LODWORD(result[1].renderModelInfo.color.r) = 0x1FFF;
  return this;
}


// ========================================================================
// ?OnActivate@idAIDeathVolume@@UAAXPAVidEntity@@@Z
// EA  : 0x82A426B8
// RVA : 0x00A426B8
// PDB : w:\tech5\tungsten\game\ai\aideathvolume.cpp
// ========================================================================

void __fastcall idAIDeathVolume::OnActivate(idAIDeathVolume *this, idEntity *activator)
{
  if ( idVolume::IsTouchable(this)
    || (activator != nullptr
      ? (this->lastActivator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                           | activator->entityNumber)
      : (this->lastActivator.spawnId.value = 0x1FFF),
        idVolume::EnableTouch(this),
        this->killDuration <= 0.0) )
  {
    idVolume::DisableTouch(this);
    this->lastActivator.spawnId.value = 0x1FFF;
  }
  else
  {
    idEventReceiver::PostEventMS(this, ev: &EV_StopKilling, time: (int)(float)(this->killDuration * (float)1000.0));
  }
}

