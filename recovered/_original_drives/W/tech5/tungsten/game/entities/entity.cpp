
// ========================================================================
// ?Collide@idEntityPhysicsCallbacks@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82C38E90
// RVA : 0x00C38E90
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

collide_t __fastcall idEntityPhysicsCallbacks::Collide(
        idEntityPhysicsCallbacks *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  return this->self->Collide(this: this->self, a2: physId, a3: collision, a4: velocity);
}


// ========================================================================
// ?Contact@idEntityPhysicsCallbacks@@UAA?AW4collide_t@@HAAUcontactInfo_t@@@Z
// EA  : 0x82C38EA8
// RVA : 0x00C38EA8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

collide_t __fastcall idEntityPhysicsCallbacks::Contact(
        idEntityPhysicsCallbacks *this,
        int physId,
        contactInfo_t *contact)
{
  return this->self->Contact(this: this->self, a2: physId, a3: contact);
}


// ========================================================================
// ?ApplyImpulse@idEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82C38EC0
// RVA : 0x00C38EC0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ApplyImpulse(
        idEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  this->self->ApplyImpulse(this: this->self, a2: physId, a3: bodyId, a4: point, a5: impulse);
}


// ========================================================================
// ?ApplyForce@idEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82C38ED8
// RVA : 0x00C38ED8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ApplyForce(
        idEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  this->self->ApplyForce(this: this->self, a2: physId, a3: bodyId, a4: point, a5: force);
}


// ========================================================================
// ?Crush@idEntityPhysicsCallbacks@@UAA_NH@Z
// EA  : 0x82C38EF0
// RVA : 0x00C38EF0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntityPhysicsCallbacks::Crush(idEntityPhysicsCallbacks *this, int physId)
{
  return this->self->Crush(this: this->self, a2: physId);
}


// ========================================================================
// ?ApplyDamage@idEntityPhysicsCallbacks@@UAAXHHPBVidDeclDamage@@@Z
// EA  : 0x82C38F08
// RVA : 0x00C38F08
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ApplyDamage(
        idEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        const idDeclDamage *damageDecl)
{
  this->self->ApplyDamage(this: this->self, a2: physId, a3: bodyId, a4: damageDecl);
}


// ========================================================================
// ?ActivatePhysics@idEntityPhysicsCallbacks@@UAAXH@Z
// EA  : 0x82C38F20
// RVA : 0x00C38F20
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ActivatePhysics(idEntityPhysicsCallbacks *this, int physId)
{
  this->self->ActivatePhysics(this: this->self, a2: physId);
}


// ========================================================================
// ?DeactivatePhysics@idEntityPhysicsCallbacks@@UAAXH@Z
// EA  : 0x82C38F38
// RVA : 0x00C38F38
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::DeactivatePhysics(idEntityPhysicsCallbacks *this, int physId)
{
  this->self->DeactivatePhysics(this: this->self, a2: physId);
}


// ========================================================================
// ?ApplyWaterEffects@idEntityPhysicsCallbacks@@UAAXHH@Z
// EA  : 0x82C38F50
// RVA : 0x00C38F50
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ApplyWaterEffects(idEntityPhysicsCallbacks *this, int physId, int bodyId)
{
  this->self->ApplyWaterEffects(this: this->self, a2: physId, a3: bodyId);
}


// ========================================================================
// ?ApplyWaterSplashEffects@idEntityPhysicsCallbacks@@UAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
// EA  : 0x82C38F68
// RVA : 0x00C38F68
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntityPhysicsCallbacks::ApplyWaterSplashEffects(
        idEntityPhysicsCallbacks *this,
        int physId,
        int bodyId,
        surfTypes_t surfOverride,
        idPhysicsCallbacks::splashState_t splashState)
{
  this->self->ApplyWaterSplashEffects(this: this->self, a2: physId, a3: bodyId, a4: surfOverride, a5: splashState);
}


// ========================================================================
// ?CleanRenderParms@idEntity@@QAAXXZ
// EA  : 0x82C38F80
// RVA : 0x00C38F80
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::CleanRenderParms(idEntity *this)
{
  idRenderModelInfo *v1; // r3

  v1 = this->GetRenderModelInfo(this);
  if ( v1 != nullptr )
    idRenderModelInfo::CleanRenderParms(this: v1);
}


// ========================================================================
// ?UpdatePVSAreas@idEntity@@QAAXABVidBounds@@@Z
// EA  : 0x82C38FB8
// RVA : 0x00C38FB8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdatePVSAreas(idEntity *this, idBounds *bounds)
{
  this->numPVSAreas = idPVS::GetPVSAreas(this: &clientGame->pvs, bounds, areas: this->PVSAreas, maxAreas: 4);
}


// ========================================================================
// ?GetForceDormant@idEntity@@QBA_NXZ
// EA  : 0x82C39000
// RVA : 0x00C39000
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::GetForceDormant(idEntity *this)
{
  unsigned int v2; // r3

  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  return ((((this->dormancy.endForceTime ^ v2) & 0x80000000) == 0) + (v2 >= this->dormancy.endForceTime)) & 1;
}


// ========================================================================
// ?GetColor@idEntity@@UBAXAAVidVec3@@@Z
// EA  : 0x82C39060
// RVA : 0x00C39060
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetColor(idEntity *this, idVec3 *out)
{
  idRenderModelInfo *v3; // r3

  v3 = (idRenderModelInfo *)this->GetRenderModelInfo_2(this);
  if ( v3 != nullptr )
    idRenderModelInfo::GetColor(this: v3, out);
}


// ========================================================================
// ?GetColor@idEntity@@UBAXAAVidColor@@@Z
// EA  : 0x82C390A8
// RVA : 0x00C390A8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetColor(idEntity *this, idColor *out)
{
  idRenderModelInfo *v3; // r3

  v3 = (idRenderModelInfo *)this->GetRenderModelInfo_2(this);
  if ( v3 != nullptr )
    idRenderModelInfo::GetColor(this: v3, out);
}


// ========================================================================
// ?GetColor@idEntity@@UBAXAAVidVec4@@@Z
// EA  : 0x82C390F0
// RVA : 0x00C390F0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetColor(idEntity *this, idVec4 *out)
{
  idRenderModelInfo *v3; // r3

  v3 = (idRenderModelInfo *)this->GetRenderModelInfo_2(this);
  if ( v3 != nullptr )
    idRenderModelInfo::GetColor(this: v3, out);
}


// ========================================================================
// ?GetRenderModelMaterial@idEntity@@QBAPBVidMaterial@@XZ
// EA  : 0x82C39138
// RVA : 0x00C39138
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

const idMaterial *__fastcall idEntity::GetRenderModelMaterial(idEntity *this)
{
  idRenderModelInfo *v1; // r3

  v1 = (idRenderModelInfo *)this->GetRenderModelInfo_2(this);
  if ( v1 != nullptr )
    return idRenderModelInfo::GetRenderModelMaterial(this: v1);
  else
    return nullptr;
}


// ========================================================================
// ?Get_idCombatStage_useRelaxedChatterVO@@YAHPAX@Z
// EA  : 0x82C39188
// RVA : 0x00C39188
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall Get_idCombatStage_useRelaxedChatterVO(unsigned __int8 *ptr)
{
  return ptr[92] >> 7;
}


// ========================================================================
// ?GetScale@idEntity@@UBAXAAVidVec3@@@Z
// EA  : 0x82C39198
// RVA : 0x00C39198
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetScale(idEntity *this, idVec3 *out)
{
  idRenderModelInfo *v3; // r3

  v3 = (idRenderModelInfo *)this->GetRenderModelInfo_2(this);
  if ( v3 != nullptr )
    idRenderModelInfo::GetScale(this: v3, out);
}


// ========================================================================
// ?SetScale@idEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82C391E0
// RVA : 0x00C391E0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetScale(idEntity *this, const idVec3 *scale)
{
  idRenderModelInfo *v3; // r3

  v3 = this->GetRenderModelInfo(this);
  if ( v3 != nullptr )
    idRenderModelInfo::SetScale(this: v3, inScale: scale);
}


// ========================================================================
// ?IsBound@idEntity@@QBA_NXZ
// EA  : 0x82C39228
// RVA : 0x00C39228
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsBound(idEntity *this)
{
  return this->bindInfo.bindMaster != nullptr;
}


// ========================================================================
// ?IsBoundTo@idEntity@@QBA_NPBV1@@Z
// EA  : 0x82C39238
// RVA : 0x00C39238
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::IsBoundTo(idEntity *this, const idEntity *master)
{
  idEntity *bindMaster; // r11

  bindMaster = this->bindInfo.bindMaster;
  if ( bindMaster == nullptr )
    return 0;
  while ( bindMaster != master )
  {
    bindMaster = bindMaster->bindInfo.bindMaster;
    if ( bindMaster == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsBoundOriented@idEntity@@QBA_NXZ
// EA  : 0x82C39268
// RVA : 0x00C39268
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::IsBoundOriented(idEntity *this)
{
  if ( this->bindInfo.bindMaster != nullptr )
    return *((unsigned __int8 *)&this->bindInfo + 112) >> 7;
  else
    return 0;
}


// ========================================================================
// ?GetBindMaster@idEntity@@QBAPAV1@XZ
// EA  : 0x82C39288
// RVA : 0x00C39288
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetBindMaster(idEntity *this)
{
  return this->bindInfo.bindMaster;
}


// ========================================================================
// ?GetTeamMaster@idEntity@@QBAPAV1@XZ
// EA  : 0x82C39290
// RVA : 0x00C39290
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetTeamMaster(idEntity *this)
{
  return this->bindInfo.teamMaster;
}


// ========================================================================
// ?GetNextTeamEntity@idEntity@@QBAPAV1@XZ
// EA  : 0x82C39298
// RVA : 0x00C39298
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetNextTeamEntity(idEntity *this)
{
  return this->bindInfo.teamChain;
}


// ========================================================================
// ?QuitTeam@idEntity@@QAAXXZ
// EA  : 0x82C392A0
// RVA : 0x00C392A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::QuitTeam(idEntity *this)
{
  idEntity *teamMaster; // r11
  idEntity *teamChain; // r11
  idEntity **i; // r11

  teamMaster = this->bindInfo.teamMaster;
  if ( teamMaster == nullptr )
    return;
  if ( teamMaster != this )
  {
    for ( i = &teamMaster->bindInfo.teamChain; *i != this; i = &(*i)->bindInfo.teamChain )
      ;
    *i = this->bindInfo.teamChain;
    teamChain = this->bindInfo.teamMaster;
    if ( teamChain->bindInfo.teamChain != nullptr )
      goto LABEL_11;
    goto LABEL_10;
  }
  teamChain = this->bindInfo.teamChain;
  if ( teamChain->bindInfo.teamChain == nullptr )
  {
LABEL_10:
    teamChain->bindInfo.teamMaster = nullptr;
    goto LABEL_11;
  }
  if ( teamChain == nullptr )
  {
LABEL_11:
    this->bindInfo.teamMaster = nullptr;
    this->bindInfo.teamChain = nullptr;
    return;
  }
  do
  {
    teamChain->bindInfo.teamMaster = this->bindInfo.teamChain;
    teamChain = teamChain->bindInfo.teamChain;
  }
  while ( teamChain != nullptr );
  this->bindInfo.teamMaster = nullptr;
  this->bindInfo.teamChain = nullptr;
}


// ========================================================================
// ?RestorePhysics@idEntity@@QAAXPAVidPhysics@@@Z
// EA  : 0x82C39340
// RVA : 0x00C39340
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RestorePhysics(idEntity *this, idPhysics *phys)
{
  this->physics = phys;
}


// ========================================================================
// ?GetPhysics@idEntity@@QBAPAVidPhysics@@XZ
// EA  : 0x82C39348
// RVA : 0x00C39348
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idPhysics *__fastcall idEntity::GetPhysics(idEntity *this)
{
  return this->physics;
}


// ========================================================================
// ?SetAngles@idEntity@@QAAXABVidAngles@@@Z
// EA  : 0x82C39350
// RVA : 0x00C39350
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetAngles(idEntity *this, idMat3 *ang)
{
  idEntity_vtbl *v2; // r31
  idMat3 *v4; // r3
  idAngles v5[3]; // [sp+50h] [-40h] BYREF

  v2 = this->__vftable;
  v4 = idAngles::ToMat3(this: v5, result: ang);
  v2->SetAxis(this, a2: v4);
}


// ========================================================================
// ?ApplyImpulse@idEntity@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82C393A0
// RVA : 0x00C393A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ApplyImpulse(
        idEntity *this,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  this->physics->ApplyImpulse(this: this->physics, a2: bodyId, a3: point, a4: impulse);
}


// ========================================================================
// ?ApplyForce@idEntity@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82C393C0
// RVA : 0x00C393C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ApplyForce(
        idEntity *this,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  this->physics->ApplyForce(this: this->physics, a2: bodyId, a3: point, a4: force);
}


// ========================================================================
// ?InventoryRemoved@idEntity@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82C393E0
// RVA : 0x00C393E0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::InventoryRemoved(idEntity *this, idInventoryItem *item)
{
  idAttachmentCollection *v3; // r3

  v3 = this->GetAttachments_2(this);
  if ( v3 != nullptr )
    idAttachmentCollection::RemoveAttachment(this: v3, item);
}


// ========================================================================
// ?ExecuteThread@idEntity@@UAAXPAVidThread@@@Z
// EA  : 0x82C39428
// RVA : 0x00C39428
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ExecuteThread(idEntity *this, idThread *thread)
{
  idThread::Execute(this: thread);
}


// ========================================================================
// ?IsCurrentlyUsable@idEntity@@UBA_NPBV1@@Z
// EA  : 0x82C39430
// RVA : 0x00C39430
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsCurrentlyUsable(idEntity *this, const idEntity *activator)
{
  return this->IsEverUsable(this, a2: activator);
}


// ========================================================================
// ?ModifyCrosshairInfo@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C39440
// RVA : 0x00C39440
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::ModifyCrosshairInfo(
        idEntity *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  if ( usable == USABLE_NOT_USABLE
    || ft->distance > ((double (__fastcall *)(idEntity *))this->GetUsableDistance)(a1: this)
    || this->IsCrosshairDisabled(this, a2: activator, a3: ft, a4: usable) )
  {
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
    info->textColorState = CROSSHAIR_TEXT_COLOR_NEGATIVE;
    return 0;
  }
  else if ( this->IsCrosshairSubdued(this, a2: activator, a3: ft, a4: usable) )
  {
    info->textColorState = CROSSHAIR_TEXT_COLOR_SUBDUED;
    return 0;
  }
  else
  {
    return 1;
  }
}


// ========================================================================
// ?SetIsActivatable@idEntity@@QAAX_N@Z
// EA  : 0x82C39518
// RVA : 0x00C39518
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetIsActivatable(idEntity *this, const bool activatable)
{
  void (*OnMakeActivatable)(void); // r7

  OnMakeActivatable = (void (*)(void))this->OnMakeActivatable;
  *(_BYTE *)&this->flags = (8 * activatable) & 8 | *(_BYTE *)&this->flags & 0xF7;
  OnMakeActivatable();
}


// ========================================================================
// ?ShowEditingDialog@idEntity@@UAAXXZ
// EA  : 0x82C39538
// RVA : 0x00C39538
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ShowEditingDialog(idEntity *this)
{
  common->InitTool(this: common, a2: EDITOR_ENTITY_INSPECTOR);
}


// ========================================================================
// ?UpdateEditingDialog@idEntity@@UAAXXZ
// EA  : 0x82C39558
// RVA : 0x00C39558
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateEditingDialog(idEntity *this)
{
  common->UpdateTool(this: common, a2: EDITOR_ENTITY_INSPECTOR);
}


// ========================================================================
// ?Event_FindEntity@idEntity@@AAA?AVeventEntity@@PBD@Z
// EA  : 0x82C39578
// RVA : 0x00C39578
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_FindEntity(idEntity *this, eventEntity *result, const char *name)
{
  idEntity *v4; // r3

  v4 = gameLocal->FindEntity(this: gameLocal, a2: name);
  eventEntity::eventEntity((eventEntity *)this, e: v4);
  return this;
}


// ========================================================================
// ?Event_TargetsReady@idEntity@@AAA?AVeventBool@@XZ
// EA  : 0x82C395D0
// RVA : 0x00C395D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idAI2 *__fastcall idEntity::Event_TargetsReady(idAI2 *this, eventBool *result, const int eventClass)
{
  eventBool::eventBool((eventBool *)this, b: true);
  return this;
}


// ========================================================================
// ?Event_IsHidden@idEntity@@AAA?AVeventInt@@XZ
// EA  : 0x82C39608
// RVA : 0x00C39608
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_IsHidden(idEntity *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: HIBYTE(result[23].value) >> 7);
  return this;
}


// ========================================================================
// ?Event_GetWorldOrigin@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C39640
// RVA : 0x00C39640
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetWorldOrigin(idEntity *this, eventVector *result)
{
  const idVec3 *v3; // r3

  v3 = (const idVec3 *)(*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(result[56].value.z) + 64))(
                         a1: LODWORD(result[56].value.z),
                         a2: 0);
  eventVector::eventVector((eventVector *)this, v: v3);
  return this;
}


// ========================================================================
// ?Event_GetLinearVelocity@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C39690
// RVA : 0x00C39690
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetLinearVelocity(idEntity *this, eventVector *result)
{
  const idVec3 *v3; // r3
  _BYTE v5[16]; // [sp+50h] [-20h] BYREF

  v3 = (const idVec3 *)(*(int (__fastcall **)(_BYTE *))(*(_DWORD *)LODWORD(result[56].value.z) + 88))(a1: v5);
  eventVector::eventVector((eventVector *)this, v: v3);
  return this;
}


// ========================================================================
// ?Event_GetAngularVelocity@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C396E8
// RVA : 0x00C396E8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetAngularVelocity(idEntity *this, eventVector *result)
{
  const idVec3 *v3; // r3
  _BYTE v5[16]; // [sp+50h] [-20h] BYREF

  v3 = (const idVec3 *)(*(int (__fastcall **)(_BYTE *))(*(_DWORD *)LODWORD(result[56].value.z) + 92))(a1: v5);
  eventVector::eventVector((eventVector *)this, v: v3);
  return this;
}


// ========================================================================
// ?Event_HasFunction@idEntity@@AAA?AVeventInt@@PBD@Z
// EA  : 0x82C39740
// RVA : 0x00C39740
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_HasFunction(idEntity *this, eventInt *result, const char *name)
{
  const function_t *Function; // r3

  Function = idScriptObject::GetFunction(this: (idScriptObject *)&result[118], name);
  eventInt::eventInt((eventInt *)this, i: Function != nullptr);
  return this;
}


// ========================================================================
// ?Event_GetScriptObject@idEntity@@AAA?AVeventString@@XZ
// EA  : 0x82C39790
// RVA : 0x00C39790
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetScriptObject(idEntity *this, eventString *result)
{
  const char *TypeName; // r3

  TypeName = idScriptObject::GetTypeName(this: (idScriptObject *)&result[118]);
  eventString::eventString((eventString *)this, s: TypeName);
  return this;
}


// ========================================================================
// ?Event_GetClass@idEntity@@AAA?AVeventString@@XZ
// EA  : 0x82C397D0
// RVA : 0x00C397D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetClass(idEntity *this, idClass *result)
{
  const char *Classname; // r3

  Classname = idClass::GetClassname(this: result);
  eventString::eventString((eventString *)this, s: Classname);
  return this;
}


// ========================================================================
// ?Event_IsSpecificClass@idEntity@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82C39810
// RVA : 0x00C39810
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_IsSpecificClass(idEntity *this, idClass *result, const char *className)
{
  const char *v5; // r3
  unsigned int v6; // r3

  v5 = idClass::GetClassname(this: result);
  v6 = idStr::Icmp(s1: className, s2: v5);
  eventBool::eventBool((eventBool *)this, b: (_cntlzw(v6) & 0x20) != 0);
  return this;
}


// ========================================================================
// ?Event_GetContents@idEntity@@AAA?AVeventInt@@XZ
// EA  : 0x82C39870
// RVA : 0x00C39870
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetContents(idEntity *this, eventInt *result)
{
  int value; // r3
  int v4; // r4

  value = result[170].value;
  if ( value != 0 )
    v4 = (*(int (__fastcall **)(int, int))(*(_DWORD *)value + 28))(a1: value, a2: -1);
  else
    v4 = 0;
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_GetClipMask@idEntity@@AAA?AVeventInt@@XZ
// EA  : 0x82C398D0
// RVA : 0x00C398D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetClipMask(idEntity *this, eventInt *result)
{
  int value; // r3
  int v4; // r4

  value = result[170].value;
  if ( value != 0 )
    v4 = (*(int (__fastcall **)(int, int))(*(_DWORD *)value + 36))(a1: value, a2: -1);
  else
    v4 = 0;
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?SetTeam@idEntity@@QAAXW4gameTeam_t@@@Z
// EA  : 0x82C39930
// RVA : 0x00C39930
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetTeam(idEntity *this, gameTeam_t team)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    idPresentable::SetTeam(this: presentable, newTeam: team);
}


// ========================================================================
// ?SetClipReplicationFlags@idEntity@@IAAX_N0@Z
// EA  : 0x82C39948
// RVA : 0x00C39948
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetClipReplicationFlags(
        idEntity *this,
        bool dynamicClipReplication,
        bool dynamicClipReplicationAxis)
{
  *((_BYTE *)&this->flags + 1) = dynamicClipReplicationAxis
                               | (2 * dynamicClipReplication) & 2
                               | *((_BYTE *)&this->flags + 1) & 0xFC;
}


// ========================================================================
// ?IsFirstPostSerializeRead@idEntity@@QAA_NXZ
// EA  : 0x82C39960
// RVA : 0x00C39960
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsFirstPostSerializeRead(idEntity *this)
{
  BOOL result; // r3

  result = this->firstPostSerializeRead;
  this->firstPostSerializeRead = false;
  return result;
}


// ========================================================================
// ?GetName@idEntityPhysicsCallbacks@@UAAPBDXZ
// EA  : 0x82C39C70
// RVA : 0x00C39C70
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

char *__fastcall idEntityPhysicsCallbacks::GetName(idEntityPhysicsCallbacks *this)
{
  return this->self->name.data;
}


// ========================================================================
// ?GetEntityRenderLight@idGameLocal@@UAAPAVidRenderLight@@PAVidEntity@@@Z
// EA  : 0x82C39D38
// RVA : 0x00C39D38
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idRenderLight *__fastcall idGameLocal::GetEntityRenderLight(idGameLocal *this, idLight *ent)
{
  idLight *v3; // r3
  idLight *v4; // r30
  idRenderLight *renderLight; // r30
  idGameLock v7[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  v3 = idLight::CastTo(c: ent);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idLight::InitRenderLight(this: v3);
    renderLight = v4->renderLight;
    idGameLock::~idGameLock(this: v7);
    return renderLight;
  }
  else
  {
    idGameLock::~idGameLock(this: v7);
    return nullptr;
  }
}


// ========================================================================
// __unwind$495791
// EA  : 0x82C39DB4
// RVA : 0x00C39DB4
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_495791()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?SpawnTransform@idEntity@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82C39DE0
// RVA : 0x00C39DE0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SpawnTransform(idEntity *this, const idVec3 *origin, const idMat3 *axis)
{
  double y; // fp9
  double z; // fp5
  double v5; // fp2
  double v6; // fp1

  y = origin->y;
  z = origin->z;
  v5 = (float)((float)(axis->mat[2].y * this->spawnPosition.z)
             + (float)((float)(axis->mat[0].y * this->spawnPosition.x) + (float)(axis->mat[1].y * this->spawnPosition.y)));
  v6 = (float)((float)(axis->mat[2].z * this->spawnPosition.z)
             + (float)((float)(axis->mat[0].z * this->spawnPosition.x) + (float)(axis->mat[1].z * this->spawnPosition.y)));
  this->spawnPosition.x = origin->x
                        + (float)((float)(this->spawnPosition.x * axis->mat[0].x)
                                + (float)((float)(axis->mat[1].x * this->spawnPosition.y)
                                        + (float)(axis->mat[2].x * this->spawnPosition.z)));
  this->spawnPosition.y = (float)y + (float)v5;
  this->spawnPosition.z = (float)z + (float)v6;
  idMat3::operator*=(this: &this->spawnOrientation, a: axis);
}


// ========================================================================
// ?UpdateDormant@idEntity@@QAA_NXZ
// EA  : 0x82C39E70
// RVA : 0x00C39E70
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::UpdateDormant(idEntity *this)
{
  idEntity_vtbl *v3; // r11
  char *v4; // r28
  int v5; // r3
  int v6; // r3
  char *data; // r29
  int GameMs; // r3

  if ( this->dormancy.endForceTime > idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED) )
    return this->dormancy.forceDormant;
  v3 = this->__vftable;
  if ( (*((_BYTE *)&this->flags + 1) & 0x80) == 0 )
  {
    if ( v3->ShouldEnterDormancy(this) )
    {
      *((_BYTE *)&this->flags + 1) |= 0x80u;
      this->dormancy.becomeDormantTime = idGameTimeManager::GetGameMs(
                                           this: &clientGame->gameTimeManager,
                                           type: GAMETIME_SCALED);
      if ( g_debugDormancy.valueInteger != 0 )
      {
        data = this->name.data;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idLib::Printf(fmt: "(%d):Entity '%s' entered dormancy.\n", GameMs, data);
      }
      this->DormantBegin(this);
    }
  }
  else if ( v3->ShouldLeaveDormancy(this) )
  {
    *((_BYTE *)&this->flags + 1) &= ~0x80u;
    if ( g_debugDormancy.valueInteger != 0 )
    {
      v4 = this->name.data;
      v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d):Entity '%s' left dormancy.\n", v5, v4);
    }
    v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->DormantEnd(this, a2: v6 - this->dormancy.becomeDormantTime);
    return *((unsigned __int8 *)&this->flags + 1) >> 7;
  }
  return *((unsigned __int8 *)&this->flags + 1) >> 7;
}


// ========================================================================
// ?InitComponents@idEntity@@QAAXXZ
// EA  : 0x82C3A010
// RVA : 0x00C3A010
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::InitComponents(idEntity *this)
{
  bool v2; // r30
  idComponentTimeLine *v3; // r3

  v2 = idLib::PushWarningInfo(type: "entity", name: "InitComponents");
  v3 = this->GetComponentTimeLine_2(this);
  if ( v3 != nullptr )
    idComponentTimeLine::Init(this: v3);
  if ( v2 )
    idLib::PopWarningInfo();
}


// ========================================================================
// __unwind$495903
// EA  : 0x82C3A078
// RVA : 0x00C3A078
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_495903()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 128 + 80));
}


// ========================================================================
// ?ShouldEnterDormancy@idEntity@@UAA_NXZ
// EA  : 0x82C3A0A0
// RVA : 0x00C3A0A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::ShouldEnterDormancy(idEntity *this)
{
  int numPVSAreas; // r5
  int GameMs; // r3
  unsigned int v5; // r11

  if ( (*(_BYTE *)&this->flags & 0x40) == 0 )
    return 0;
  if ( this->physics->IsInNonResidentCollisionArea(this: this->physics, a2: false) )
    return 1;
  numPVSAreas = this->numPVSAreas;
  if ( numPVSAreas <= 0
    || idGameLocal::IsInPlayerPVS(this: gameLocal, targetAreas: this->PVSAreas, numTargetAreas: numPVSAreas) )
  {
    this->dormancy.lastTimeInPlayerPVS = idGameTimeManager::GetGameMs(
                                           this: &clientGame->gameTimeManager,
                                           type: GAMETIME_SCALED);
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = (int)(float)(this->dormancy.delay * (float)1000.0) + this->dormancy.lastTimeInPlayerPVS;
  return (GameMs >> 31) + (GameMs >= v5) + (v5 >> 31);
}


// ========================================================================
// ?ShouldLeaveDormancy@idEntity@@UAA_NXZ
// EA  : 0x82C3A190
// RVA : 0x00C3A190
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::ShouldLeaveDormancy(idEntity *this)
{
  int result; // r3
  int numPVSAreas; // r5
  bool v4; // zf

  if ( (*(_BYTE *)&this->flags & 0x40) == 0 )
    return 1;
  numPVSAreas = this->numPVSAreas;
  if ( numPVSAreas > 0
    && !idGameLocal::IsInPlayerPVS(this: gameLocal, targetAreas: this->PVSAreas, numTargetAreas: numPVSAreas) )
  {
    return 0;
  }
  v4 = !this->physics->IsInNonResidentCollisionArea(this: this->physics, a2: false);
  result = 1;
  if ( !v4 )
    return 0;
  return result;
}


// ========================================================================
// ?DormantBegin@idEntity@@UAAXXZ
// EA  : 0x82C3A238
// RVA : 0x00C3A238
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::DormantBegin(idEntity *this)
{
  if ( g_showDormant.valueInteger != 0 )
    idLib::Printf(fmt: "'%s' - beginning dormancy.\n", this->name.data);
}


// ========================================================================
// ?DormantEnd@idEntity@@UAAXH@Z
// EA  : 0x82C3A260
// RVA : 0x00C3A260
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::DormantEnd(idEntity *this, const int timeDormant)
{
  if ( g_showDormant.valueInteger != 0 )
    idLib::Printf(fmt: "'%s' - end dormancy.", this->name.data);
}


// ========================================================================
// ?ForceDormancy@idEntity@@QAAX_NH@Z
// EA  : 0x82C3A288
// RVA : 0x00C3A288
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ForceDormancy(idEntity *this, bool dormant, const int durationMS)
{
  int GameMs; // r3
  char v7; // r11
  int v8; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = *((_BYTE *)&this->flags + 1);
  this->dormancy.endForceTime = GameMs + durationMS;
  this->dormancy.forceDormant = dormant;
  if ( dormant )
  {
    if ( (v7 & 0x80) == 0 )
      this->DormantBegin(this);
  }
  else if ( v7 < 0 )
  {
    v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->DormantEnd(this, a2: v8 - this->dormancy.becomeDormantTime);
  }
}


// ========================================================================
// ?LeaveDormancy@idEntity@@QAAXXZ
// EA  : 0x82C3A340
// RVA : 0x00C3A340
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::LeaveDormancy(idEntity *this)
{
  int GameMs; // r3
  char v3; // r11
  char *data; // r28
  int v5; // r3
  int v6; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = *((_BYTE *)&this->flags + 1);
  this->dormancy.lastTimeInPlayerPVS = GameMs;
  if ( v3 < 0 )
  {
    *((_BYTE *)&this->flags + 1) = v3 & 0x7F;
    if ( g_debugDormancy.valueInteger != 0 )
    {
      data = this->name.data;
      v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d):Entity '%s' entered dormancy.\n", v5, data);
    }
    v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->DormantEnd(this, a2: v6 - this->dormancy.becomeDormantTime);
  }
}


// ========================================================================
// ?BecomeInactive@idEntity@@QAAXH@Z
// EA  : 0x82C3A400
// RVA : 0x00C3A400
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BecomeInactive(idEntity *this, int flags)
{
  idEntity *teamMaster; // r11
  _DWORD *v5; // r31
  int thinkFlags; // r11
  int v7; // r11
  idEntity *v8; // r11

  while ( 1 )
  {
    if ( (flags & 2) != 0 )
    {
      teamMaster = this->bindInfo.teamMaster;
      if ( teamMaster == this )
      {
        v5 = &teamMaster->bindInfo.teamChain->__vftable;
        if ( v5 != nullptr )
        {
          while ( (v5[125] & 2) == 0
               && (*(unsigned __int8 (__fastcall **)(_DWORD *, idEntity *))(*v5 + 252))(a1: v5, a2: this) != 0 )
          {
            v5 = (_DWORD *)v5[102];
            if ( v5 == nullptr )
              goto LABEL_9;
          }
          flags &= ~2u;
        }
      }
    }
LABEL_9:
    thinkFlags = this->thinkFlags;
    if ( thinkFlags != 0 )
    {
      v7 = thinkFlags & ~flags;
      this->thinkFlags = v7;
      if ( v7 == 0 && this->activeNode.head != &this->activeNode )
        ++gameLocal->numEntitiesToDeactivate;
    }
    if ( (flags & 2) == 0 )
      break;
    v8 = this->bindInfo.teamMaster;
    if ( v8 == nullptr || v8 == this || !v8->physics->IsAtRest(this: v8->physics) )
      break;
    this = this->bindInfo.teamMaster;
    flags = 2;
  }
}


// ========================================================================
// ?IsMegaModel@idEntity@@QBA_NXZ
// EA  : 0x82C3A520
// RVA : 0x00C3A520
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsMegaModel(idEntity *this)
{
  const idRenderModelInfo *v1; // r3

  v1 = this->GetRenderModelInfo_2(this);
  return v1 != nullptr && (*((_BYTE *)v1 + 5) & 0x10) != 0;
}


// ========================================================================
// ?SetPrivateLightOnly@idEntity@@QAAX_N@Z
// EA  : 0x82C3A570
// RVA : 0x00C3A570
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetPrivateLightOnly(idEntity *this, bool set)
{
  idRenderModelInfo *v3; // r3

  v3 = this->GetRenderModelInfo(this);
  if ( v3 != nullptr )
    *((_BYTE *)v3 + 5) = (set << 7) | *((_BYTE *)v3 + 5) & 0x7F;
}


// ========================================================================
// ?GetCustomMaterial@idEntity@@UBAPBVidMaterial@@XZ
// EA  : 0x82C3A5C0
// RVA : 0x00C3A5C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

const idMaterial *__fastcall idEntity::GetCustomMaterial(idEntity *this)
{
  const idRenderModelInfo *v1; // r3

  v1 = this->GetRenderModelInfo_2(this);
  if ( v1 != nullptr )
    return v1->customMaterial;
  else
    return nullptr;
}


// ========================================================================
// ?GetModelTransform@idEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C3A610
// RVA : 0x00C3A610
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetModelTransform(idEntity *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  const idMat3 *v6; // r9
  idPhysics *physics; // r3
  idPhysics_vtbl *v8; // r8
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r7

  v6 = this->physics->GetAxis(this: this->physics, a2: 0);
  physics = this->physics;
  v8 = physics->__vftable;
  modelAxis->mat[0].x = v6->mat[0].x;
  modelAxis->mat[0].y = v6->mat[0].y;
  GetOrigin = v8->GetOrigin;
  modelAxis->mat[0].z = v6->mat[0].z;
  modelAxis->mat[1] = v6->mat[1];
  modelAxis->mat[2] = v6->mat[2];
  *modelOrigin = *GetOrigin(this: physics, a2: 0);
}


// ========================================================================
// ?UpdateModelTransform@idEntity@@UAAXXZ
// EA  : 0x82C3A6C8
// RVA : 0x00C3A6C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateModelTransform(idEntity *this)
{
  idPresentable *presentable; // r11
  float v3[4]; // [sp+50h] [-50h] BYREF
  float v4[12]; // [sp+60h] [-40h] BYREF

  if ( this->presentable != nullptr )
  {
    this->GetModelTransform(this, a2: (idVec3 *)v3, a3: (idMat3 *)v4);
    presentable = this->presentable;
    presentable->origin.x = v3[0];
    presentable->origin.y = v3[1];
    presentable->origin.z = v3[2];
    qmemcpy(&this->presentable->axis, v4, sizeof(this->presentable->axis));
    idPresentable::UpdateModelTransform(this: this->presentable);
    this->presentable->Present(this: this->presentable);
  }
}


// ========================================================================
// ?InitPresentableInternal@idEntity@@QAAXXZ
// EA  : 0x82C3A7A0
// RVA : 0x00C3A7A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::InitPresentableInternal(idEntity *this)
{
  idRenderModel *model; // r4
  idPresentable *v3; // r3
  unsigned int v4; // r29
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r11
  char v9; // r11
  int v10; // r11
  char v11; // r11
  int v12; // r11
  char v13; // r11
  int v14; // r11
  char v15; // r11
  int v16; // r11
  int v17; // r8
  int v18; // r7
  char v19; // r11
  idClientServerInterfaceServer *v20; // r3
  idClientServerInterfaceServer *v21; // r3
  idClientServerInterface *v22; // r29
  idClientServerInterfaceClient *v23; // r3
  idClientServerInterfaceClient *v24; // r3
  idPresentable *presentable; // r11
  float *p_axis; // r11
  int v27; // [sp+8h] [-78h]
  int v28; // [sp+Ch] [-74h]
  int v29; // [sp+10h] [-70h]
  int v30; // [sp+14h] [-6Ch]
  int v31; // [sp+18h] [-68h]
  idPresentable *v32; // [sp+1Ch] [-64h]

  if ( this->GetRenderModelInfo(this) != nullptr )
    model = this->GetRenderModelInfo(this)->model;
  else
    model = nullptr;
  v3 = this->AllocPresentable(this, a2: model);
  this->presentable = v3;
  if ( v3 != nullptr )
  {
    if ( (*((_BYTE *)&this->flags + 1) & 2) != 0 )
      v3->clipModelDynamic = true;
    if ( (*((_BYTE *)&this->flags + 1) & 1) != 0 )
      this->presentable->clipModelDynamicAxis = true;
    idPresentable::SetEntityNumber(this: this->presentable, value: this->entityNumber);
    v4 = 1;
    this->presentable->debugName = idClass::GetClassname(this);
    v5 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v5 < idVehicle::Type.typeNum || (v7 = v5 <= idVehicle::Type.lastChild, v6 = 1, !v7) )
      v6 = 0;
    if ( v6 != 0 )
      v4 = 5;
    v8 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v8 < idAI2::Type.typeNum || (v7 = v8 <= idAI2::Type.lastChild, v9 = 1, !v7) )
      v9 = 0;
    if ( v9 != 0 )
      v4 |= 2u;
    v10 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v10 < idBreakable::Type.typeNum || (v7 = v10 <= idBreakable::Type.lastChild, v11 = 1, !v7) )
      v11 = 0;
    if ( v11 != 0 )
      v4 |= 8u;
    v12 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v12 < idAmmoItem::Type.typeNum || (v7 = v12 <= idAmmoItem::Type.lastChild, v13 = 1, !v7) )
      v13 = 0;
    if ( v13 != 0 )
      v4 |= 0x10u;
    v14 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v14 < idVehicleAI::Type.typeNum || (v7 = v14 <= idVehicleAI::Type.lastChild, v15 = 1, !v7) )
      v15 = 0;
    if ( v15 != 0 )
      v4 |= 0x20u;
    v16 = *(_DWORD *)(this->GetType(this) + 36);
    if ( v16 < idWorldspawn::Type.typeNum || (v7 = v16 <= idWorldspawn::Type.lastChild, v19 = 1, !v7) )
      v19 = 0;
    if ( v19 != 0 )
      v4 |= 0x40u;
    this->presentable->entityTypeFlags = v4;
    idClientGame::AddPresentable(
      this: clientGame,
      presentable: this->presentable,
      index: this->entityNumber,
      skipReplication: (*((_BYTE *)&this->flags + 1) & 4) != 0,
      a5: v18,
      a6: v17,
      a7: *((unsigned __int8 *)&this->flags + 1),
      a8: (int)&ai_useTurnTransitions.valueString.baseBuffer[12],
      a9: v27,
      a10: v28,
      a11: v29,
      a12: v30,
      a13: v31,
      a14: v32);
    if ( common->IsServer(this: common) )
    {
      v20 = (idClientServerInterfaceServer *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                               size: 8u,
                                               tag: TAG_NETWORKING,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
        v21 = idClientServerInterfaceServer::idClientServerInterfaceServer(this: v20);
      else
        v21 = nullptr;
      v22 = v21;
    }
    else
    {
      v23 = (idClientServerInterfaceClient *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                               size: 8u,
                                               tag: TAG_NETWORKING,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
      if ( v23 != nullptr )
        v24 = idClientServerInterfaceClient::idClientServerInterfaceClient(this: v23);
      else
        v24 = nullptr;
      v22 = v24;
    }
    if ( v22 != nullptr )
    {
      v22->Init(this: v22, a2: this);
      this->presentable->csInterface = v22;
    }
  }
  presentable = this->presentable;
  presentable->origin.x = this->spawnPosition.x;
  presentable->origin.y = this->spawnPosition.y;
  presentable->origin.z = this->spawnPosition.z;
  p_axis = (float *)&this->presentable->axis;
  *p_axis = this->spawnOrientation.mat[0].x;
  p_axis[1] = this->spawnOrientation.mat[0].y;
  p_axis[2] = this->spawnOrientation.mat[0].z;
  p_axis[3] = this->spawnOrientation.mat[1].x;
  p_axis[4] = this->spawnOrientation.mat[1].y;
  p_axis[5] = this->spawnOrientation.mat[1].z;
  p_axis[6] = this->spawnOrientation.mat[2].x;
  p_axis[7] = this->spawnOrientation.mat[2].y;
  p_axis[8] = this->spawnOrientation.mat[2].z;
  this->presentable->PostAlloc(this: this->presentable);
}


// ========================================================================
// __unwind$496190_0
// EA  : 0x82C3ABF8
// RVA : 0x00C3ABF8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496190_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// __unwind$496191_0
// EA  : 0x82C3AC24
// RVA : 0x00C3AC24
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496191_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ?AllocPresentable@idEntity@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C3AC58
// RVA : 0x00C3AC58
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idPresentable *__fastcall idEntity::AllocPresentable(idEntity *this, idTreeAnimator *renderModel_)
{
  idPresentable *v4; // r3

  v4 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentable::idPresentable(this: v4, e: this, renderModel_, entityNumber_: 0x1FFF, fxDecl_: nullptr);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496393
// EA  : 0x82C3ACC8
// RVA : 0x00C3ACC8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496393()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?FreePresentable@idEntity@@QAAXXZ
// EA  : 0x82C3ACF8
// RVA : 0x00C3ACF8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::FreePresentable(idEntity *this)
{
  idPresentable *presentable; // r11
  idClientServerInterface *csInterface; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
    {
      ((void (__fastcall *)(idClientServerInterface *, int))csInterface->dtr_idClientServerInterface)(
        a1: csInterface,
        a2: 1);
      this->presentable->csInterface = nullptr;
    }
    idPresentable::Delete(this: this->presentable);
    this->presentable = nullptr;
  }
}


// ========================================================================
// ?GetRenderModelFromPresentable@idEntity@@QBAPAVidRenderModel@@XZ
// EA  : 0x82C3AD70
// RVA : 0x00C3AD70
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idRenderModel *__fastcall idEntity::GetRenderModelFromPresentable(idEntity *this)
{
  idPresentable *presentable; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->model;
  else
    return nullptr;
}


// ========================================================================
// ?GetSoundTransform@idEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C3AD90
// RVA : 0x00C3AD90
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetSoundTransform(idEntity *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idPhysics *physics; // r28
  float *v7; // r3
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  float *v11; // r3
  double v12; // fp6
  double v13; // fp5
  double v14; // fp30
  double v15; // fp29
  double v16; // fp31
  float *v17; // r3
  double v18; // fp0
  double v19; // fp13
  const idVec3 *v20; // r3
  float *v21; // r3

  if ( this->physics->GetNumClipModels(this: this->physics) <= 0 )
  {
    v20 = this->physics->GetOrigin(this: this->physics, a2: 0);
    soundOrigin->x = v20->x;
    soundOrigin->y = v20->y;
    soundOrigin->z = v20->z;
  }
  else
  {
    physics = this->physics;
    v7 = (float *)physics->GetBounds(this: physics, a2: -1);
    v8 = (float)((float)(v7[3] + *v7) * (float)0.5);
    v9 = (float)((float)(v7[4] + v7[1]) * (float)0.5);
    v10 = (float)((float)(v7[5] + v7[2]) * (float)0.5);
    v11 = (float *)physics->GetAxis(this: physics, a2: 0);
    v12 = (float)((float)(v11[7] * (float)v10) + (float)(v11[4] * (float)v9));
    v13 = (float)((float)(v11[8] * (float)v10) + (float)(v11[5] * (float)v9));
    v14 = (float)((float)(*v11 * (float)v8) + (float)((float)(v11[6] * (float)v10) + (float)(v11[3] * (float)v9)));
    v15 = (float)((float)(v11[1] * (float)v8) + (float)v12);
    v16 = (float)((float)(v11[2] * (float)v8) + (float)v13);
    v17 = (float *)physics->GetOrigin(this: physics, a2: 0);
    v18 = (float)(v17[1] + (float)v15);
    v19 = (float)(v17[2] + (float)v16);
    soundOrigin->x = *v17 + (float)v14;
    soundOrigin->y = v18;
    soundOrigin->z = v19;
  }
  v21 = (float *)this->physics->GetAxis(this: this->physics, a2: 0);
  soundAxis->mat[0].x = *v21;
  soundAxis->mat[0].y = v21[1];
  soundAxis->mat[0].z = v21[2];
  soundAxis->mat[1].x = v21[3];
  soundAxis->mat[1].y = v21[4];
  soundAxis->mat[1].z = v21[5];
  soundAxis->mat[2].x = v21[6];
  soundAxis->mat[2].y = v21[7];
  soundAxis->mat[2].z = v21[8];
}


// ========================================================================
// ?ConvertLocalToWorldTransform@idEntity@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C3AF70
// RVA : 0x00C3AF70
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ConvertLocalToWorldTransform(idEntity *this, idVec3 *offset, idMat3 *axis)
{
  double v5; // fp9
  double v6; // fp5
  double v7; // fp2
  double v8; // fp1
  float v9[4]; // [sp+50h] [-50h] BYREF
  idMat3 v10; // [sp+60h] [-40h] BYREF

  this->GetModelTransform(this, a2: (idVec3 *)v9, a3: &v10);
  v5 = v9[1];
  v6 = v9[2];
  v7 = (float)((float)(offset->z * v10.mat[2].y)
             + (float)((float)(offset->x * v10.mat[0].y) + (float)(offset->y * v10.mat[1].y)));
  v8 = (float)((float)(offset->y * v10.mat[1].z)
             + (float)((float)(offset->x * v10.mat[0].z) + (float)(offset->z * v10.mat[2].z)));
  offset->x = (float)((float)(offset->x * v10.mat[0].x)
                    + (float)((float)(offset->z * v10.mat[2].x) + (float)(offset->y * v10.mat[1].x)))
            + v9[0];
  offset->y = (float)v5 + (float)v7;
  offset->z = (float)v6 + (float)v8;
  idMat3::operator*=(this: axis, a: &v10);
}


// ========================================================================
// ?JoinTeam@idEntity@@QAAXPAV1@@Z
// EA  : 0x82C3B040
// RVA : 0x00C3B040
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::JoinTeam(idEntity *this, idEntity *teammember)
{
  idEntity *teamMaster; // r11
  idEntity *v3; // r7
  idEntity *i; // r11
  idEntity *v5; // r8
  idEntity *teamChain; // r9
  idEntity *bindMaster; // r11
  char v8; // r11
  idEntity *v9; // r10
  idEntity **p_teamChain; // r11

  teamMaster = this->bindInfo.teamMaster;
  if ( teamMaster != nullptr && teamMaster != this )
    idEntity::QuitTeam(this);
  if ( teammember == this )
  {
    this->bindInfo.teamMaster = this;
  }
  else
  {
    v3 = teammember->bindInfo.teamMaster;
    if ( v3 != nullptr )
    {
      v5 = teammember;
      teamChain = teammember->bindInfo.teamChain;
      if ( this->bindInfo.bindMaster != nullptr )
      {
        for ( ; teamChain != nullptr; teamChain = teamChain->bindInfo.teamChain )
        {
          bindMaster = teamChain->bindInfo.bindMaster;
          if ( bindMaster != nullptr )
          {
            while ( bindMaster != teammember )
            {
              bindMaster = bindMaster->bindInfo.bindMaster;
              if ( bindMaster == nullptr )
                goto LABEL_15;
            }
            v8 = 1;
          }
          else
          {
LABEL_15:
            v8 = 0;
          }
          if ( v8 == 0 )
            break;
          v5 = teamChain;
        }
      }
      else
      {
        for ( ; teamChain != nullptr; teamChain = teamChain->bindInfo.teamChain )
          v5 = teamChain;
      }
      v9 = this->bindInfo.teamChain;
      p_teamChain = &this->bindInfo.teamChain;
      if ( v9 != nullptr )
      {
        do
        {
          v9->bindInfo.teamMaster = v3;
          p_teamChain = &(*p_teamChain)->bindInfo.teamChain;
          v9 = *p_teamChain;
        }
        while ( *p_teamChain != nullptr );
      }
      v5->bindInfo.teamChain = this;
      *p_teamChain = teamChain;
    }
    else
    {
      teammember->bindInfo.teamMaster = teammember;
      v3 = teammember;
      teammember->bindInfo.teamChain = this;
      for ( i = this->bindInfo.teamChain; i != nullptr; i = i->bindInfo.teamChain )
        i->bindInfo.teamMaster = teammember;
    }
    this->bindInfo.teamMaster = v3;
    gameLocal->sortTeamMasters = true;
  }
}


// ========================================================================
// ?ReferenceDefaultPhysics@idEntity@@QAAXXZ
// EA  : 0x82C3B1A0
// RVA : 0x00C3B1A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ReferenceDefaultPhysics(idEntity *this)
{
  idClipModelInfo::clipModelType_t type; // r11
  idClipModel *v3; // r29
  char *str; // r11
  char v5; // r11
  bool v6; // zf
  idClipModel *v7; // r3
  idClipModel *v8; // r3
  char *v9; // r11
  char v10; // r11
  idClipModel *v11; // r3
  idClipModel *v12; // r3
  const char ***v13; // r3
  const char **v14; // r29
  idTreeAnimator *v15; // r28
  idClipModel *v16; // r3
  idClipModel *v17; // r3
  idClipModel *v18; // r3
  idClipModel *v19; // r3

  type = this->clipModelInfo.type;
  v3 = nullptr;
  if ( type == CLIPMODEL_CUSTOM )
  {
    str = (char *)this->clipModelInfo.clipModelName.str;
    if ( str == &byte_8200D768 || (v6 = *str != 0, v5 = 0, !v6) )
      v5 = 1;
    if ( v5 == 0 )
    {
      v7 = (idClipModel *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idClipModel::idClipModel(
               this: v7,
               clip: &clientGame->clip,
               name: this->clipModelInfo.clipModelName.str,
               overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
      else
        v8 = nullptr;
      v3 = v8;
      goto LABEL_31;
    }
  }
  else
  {
    if ( type != CLIPMODEL_RENDERMODEL )
      return;
    v9 = (char *)this->clipModelInfo.clipModelName.str;
    if ( v9 == &byte_8200D768 || (v6 = *v9 != 0, v10 = 0, !v6) )
      v10 = 1;
    if ( v10 == 0 )
    {
      v11 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v11 != nullptr )
        v12 = idClipModel::idClipModel(
                this: v11,
                clip: &clientGame->clip,
                name: this->clipModelInfo.clipModelName.str,
                overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
      else
        v12 = nullptr;
      v3 = v12;
    }
    v13 = (const char ***)this->GetRenderModelInfo(this);
    if ( v3 != nullptr )
    {
LABEL_32:
      idClipModel::Delete(this: v3);
      return;
    }
    if ( v13 != nullptr )
    {
      v14 = *v13;
      if ( *v13 != nullptr )
      {
        v15 = (idTreeAnimator *)_RTDynamicCast(
                                  inptr: v14,
                                  VfDelta: 0,
                                  SrcType: &idRenderModel `RTTI Type Descriptor',
                                  TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                  isReference: 0);
        if ( v15 != nullptr )
        {
          v16 = (idClipModel *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xD8u,
                                 tag: TAG_CLIPMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
          if ( v16 != nullptr )
            v17 = idClipModel::idClipModel(this: v16, clip: &clientGame->clip, animatedModel: v15);
          else
            v17 = nullptr;
          v3 = v17;
        }
        else
        {
          v18 = (idClipModel *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xD8u,
                                 tag: TAG_CLIPMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
          if ( v18 != nullptr )
            v19 = idClipModel::idClipModel(
                    this: v18,
                    clip: &clientGame->clip,
                    name: v14[4],
                    overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
          else
            v19 = nullptr;
          v3 = v19;
        }
LABEL_31:
        if ( v3 == nullptr )
          return;
        goto LABEL_32;
      }
    }
  }
}


// ========================================================================
// __unwind$496696
// EA  : 0x82C3B400
// RVA : 0x00C3B400
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496696()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496697
// EA  : 0x82C3B42C
// RVA : 0x00C3B42C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496697()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496698
// EA  : 0x82C3B458
// RVA : 0x00C3B458
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496698()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496699
// EA  : 0x82C3B484
// RVA : 0x00C3B484
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496699()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?InitDefaultPhysics@idEntity@@AAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82C3B4B8
// RVA : 0x00C3B4B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::InitDefaultPhysics(idEntity *this, const idVec3 *origin, const idMat3 *axis)
{
  idClipModelInfo::clipModelType_t type; // r11
  idClipModel *v7; // r28
  char *str; // r11
  char v9; // r11
  bool v10; // zf
  idClipModel *v11; // r3
  idClipModel *v12; // r3
  idRenderModelInfo *v13; // r3
  char *v14; // r11
  const char ***v15; // r29
  char v16; // r11
  idClipModel *v17; // r3
  idClipModel *v18; // r3
  const char **v19; // r29
  idTreeAnimator *v20; // r28
  idClipModel *v21; // r3
  idClipModel *v22; // r3
  idClipModel *v23; // r3
  idClipModel *v24; // r3
  float *p_z; // r10
  int v26; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idRenderModelInfo *v28; // r3
  char v29; // r11
  idVec3 *v30; // r29
  float *model; // r11
  double x; // fp0
  double v33; // fp13
  double v34; // fp12
  double v35; // fp11
  double v36; // fp10
  double z; // fp9
  char *data; // r28
  const char *v39; // r3
  idVec3 *p_size; // r11
  int i; // ctr
  double y; // fp10
  double v43; // fp8
  double v44; // fp8
  double v45; // fp7
  double v46; // fp6
  unsigned __int32 v47; // r11
  int numSides; // r11
  int v49; // r11
  double v50; // fp0
  idClipModel *v51; // r3
  idClipModel *v52; // r3
  idBounds v53; // [sp+60h] [-690h] BYREF
  idTraceModel v54; // [sp+80h] [-670h] BYREF

  type = this->clipModelInfo.type;
  v7 = nullptr;
  switch ( type )
  {
    case CLIPMODEL_NONE:
      goto LABEL_80;
    case CLIPMODEL_CUSTOM:
      str = (char *)this->clipModelInfo.clipModelName.str;
      if ( str == &byte_8200D768 || (v10 = *str != 0, v9 = 0, !v10) )
        v9 = 1;
      if ( v9 == 0 )
      {
        v11 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
          v12 = idClipModel::idClipModel(
                  this: v11,
                  clip: &clientGame->clip,
                  name: this->clipModelInfo.clipModelName.str,
                  overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
        else
          v12 = nullptr;
        v7 = v12;
        goto LABEL_34;
      }
      break;
    case CLIPMODEL_RENDERMODEL:
      v13 = this->GetRenderModelInfo(this);
      v14 = (char *)this->clipModelInfo.clipModelName.str;
      v15 = (const char ***)v13;
      if ( v14 == &byte_8200D768 || (v10 = *v14 != 0, v16 = 0, !v10) )
        v16 = 1;
      if ( v16 == 0
        && (v13 == nullptr
         || v13->model == nullptr
         || idStr::Icmp(s1: this->clipModelInfo.clipModelName.str, s2: v13->model->name.str) != 0) )
      {
        v17 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        v18 = v17 != nullptr
            ? idClipModel::idClipModel(
                this: v17,
                clip: &clientGame->clip,
                name: this->clipModelInfo.clipModelName.str,
                overrideClipMaterial: this->clipModelInfo.overrideClipMaterial)
            : nullptr;
        v7 = v18;
        if ( v18 != nullptr )
          goto LABEL_80;
      }
      if ( v15 != nullptr )
      {
        v19 = *v15;
        if ( v19 != nullptr )
        {
          v20 = (idTreeAnimator *)_RTDynamicCast(
                                    inptr: v19,
                                    VfDelta: 0,
                                    SrcType: &idRenderModel `RTTI Type Descriptor',
                                    TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                    isReference: 0);
          if ( v20 != nullptr )
          {
            v21 = (idClipModel *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xD8u,
                                   tag: TAG_CLIPMODEL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            if ( v21 != nullptr )
              v22 = idClipModel::idClipModel(this: v21, clip: &clientGame->clip, animatedModel: v20);
            else
              v22 = nullptr;
            v7 = v22;
          }
          else
          {
            v23 = (idClipModel *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xD8u,
                                   tag: TAG_CLIPMODEL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            if ( v23 != nullptr )
              v24 = idClipModel::idClipModel(
                      this: v23,
                      clip: &clientGame->clip,
                      name: v19[4],
                      overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
            else
              v24 = nullptr;
            v7 = v24;
          }
LABEL_34:
          if ( v7 == nullptr )
            break;
LABEL_80:
          idPhysics::InitPhysics(
            this: &this->defaultPhysicsObj,
            clip_: &clientGame->clip,
            callbacks_: &this->physicsCallbacks,
            entityNumber_: this->entityNumber);
          this->defaultPhysicsObj.SetGravity(this: &this->defaultPhysicsObj, a2: &gameLocal->clientGame.gravity);
          ((void (__fastcall *)(idPhysics_Static *, idClipModel *, double))this->defaultPhysicsObj.SetClipModel)(
            a1: &this->defaultPhysicsObj,
            a2: v7,
            a3: 1.0);
          this->defaultPhysicsObj.SetOrigin(this: &this->defaultPhysicsObj, a2: origin, a3: -1);
          this->defaultPhysicsObj.SetAxis(this: &this->defaultPhysicsObj, a2: axis, a3: -1);
          this->physics = &this->defaultPhysicsObj;
          return;
        }
      }
      break;
    default:
      break;
  }
  memset(&v54.type, 0, 20);
  p_z = &v54.offset.z;
  v26 = 6;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  v54.offset.x = 0.0;
  v54.offset.y = 0.0;
  v54.offset.z = 0.0;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v26;
  }
  while ( v26 != 0 );
  v54.radius = 0.0;
  v54.isConvex = false;
  v54.pad[2] = 0;
  v54.pad[1] = 0;
  v54.pad[0] = 0;
  v28 = this->GetRenderModelInfo(this);
  if ( v28 == nullptr || (v29 = 1, v28->model == nullptr) )
    v29 = 0;
  if ( this->clipModelInfo.type == CLIPMODEL_BOUNDINGBOX && v29 != 0
    || (v30 = &this->clipModelInfo.size,
        ((LODWORD(this->clipModelInfo.size.z) | LODWORD(this->clipModelInfo.size.y) | LODWORD(this->clipModelInfo.size.x))
       & 0x7FFFFFFF) == 0)
    && v29 != 0 )
  {
    model = (float *)v28->model;
    x = v28->model->referenceBounds.b[0].x;
    v53.b[0].x = v28->model->referenceBounds.b[0].x;
    v33 = model[24];
    v53.b[0].y = model[24];
    v34 = model[25];
    v53.b[0].z = model[25];
    v35 = model[26];
    v53.b[1].x = model[26];
    v36 = model[27];
    v53.b[1].y = model[27];
    z = model[28];
  }
  else
  {
    if ( v30->x <= 0.0 || this->clipModelInfo.size.y <= 0.0 || this->clipModelInfo.size.z <= 0.0 )
    {
      data = this->name.data;
      v39 = idVec3::ToString(this: (idAngles *)&this->clipModelInfo.size, precision: 2);
      idLib::Warning(fmt: "invalid clip model size '%s' on entity '%s'", v39, data);
      p_size = &this->clipModelInfo.size;
      for ( i = 3; i != 0; --i )
      {
        if ( p_size->x <= 0.0 )
          p_size->x = 1.0;
        p_size = (idVec3 *)((char *)p_size + 4);
      }
    }
    y = this->clipModelInfo.size.y;
    v43 = v30->x;
    z = this->clipModelInfo.size.z;
    v34 = 0.0;
    v33 = (float)(this->clipModelInfo.size.y * (float)-0.5);
    v53.b[0].y = this->clipModelInfo.size.y * (float)-0.5;
    v53.b[0].z = 0.0;
    v36 = (float)((float)y * (float)0.5);
    x = (float)((float)v43 * (float)-0.5);
    v53.b[0].x = (float)v43 * (float)-0.5;
    v35 = (float)((float)v43 * (float)0.5);
    v53.b[1].x = (float)v43 * (float)0.5;
    v53.b[1].y = v36;
  }
  v53.b[1].z = z;
  if ( x >= v35
    || v33 >= v36
    || v34 >= z
    || (float)((float)((float)((float)z - (float)v34) * (float)((float)v36 - (float)v33))
             * (float)((float)v35 - (float)x)) < 0.0099999998 )
  {
    idLib::Warning(fmt: "%s has an invalid bounds", this->name.data);
    x = -8.0;
    v35 = 8.0;
    v33 = -8.0;
    v36 = 8.0;
    v34 = -8.0;
    z = 8.0;
  }
  v44 = this->clipModelInfo.offset.x;
  v45 = this->clipModelInfo.offset.y;
  v46 = this->clipModelInfo.offset.z;
  v47 = this->clipModelInfo.type - 3;
  v53.b[0].x = this->clipModelInfo.offset.x + (float)x;
  v53.b[0].y = (float)v45 + (float)v33;
  v53.b[0].z = (float)v46 + (float)v34;
  v53.b[1].x = (float)v44 + (float)v35;
  v53.b[1].y = (float)v45 + (float)v36;
  v53.b[1].z = (float)v46 + (float)z;
  if ( v47 <= 3 )
  {
    switch ( v47 )
    {
      case 0u:
        goto LABEL_69;
      case 1u:
        numSides = this->clipModelInfo.numSides;
        if ( numSides < 3 )
          numSides = 3;
        idTraceModel::SetupCylinder(this: &v54, cylBounds: &v53, numSides);
        break;
      case 2u:
        v49 = this->clipModelInfo.numSides;
        if ( v49 < 3 )
          v49 = 3;
        idTraceModel::SetupCone(this: &v54, coneBounds: &v53, numSides: v49);
        break;
      default:
LABEL_69:
        idTraceModel::SetupBox(this: &v54, boxBounds: &v53);
        break;
    }
    if ( this->clipModelInfo.clipShrink )
    {
      v50 = (float)((float)0.5 * (float)2.0);
      if ( (float)(v53.b[1].x - v53.b[0].x) <= v50
        || (float)(v53.b[1].y - v53.b[0].y) <= v50
        || (float)(v53.b[1].z - v53.b[0].z) <= v50 )
      {
        idLib::Warning(fmt: "clipShrink set on entity '%s' with a tiny collision model", this->name.data);
      }
      else
      {
        idTraceModel::Shrink(this: &v54, m: 0.5);
      }
    }
    v51 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v51 != nullptr )
      v52 = idClipModel::idClipModel(
              this: v51,
              clip: &clientGame->clip,
              trm: &v54,
              numTraceModels: 1,
              material: this->clipModelInfo.overrideClipMaterial);
    else
      v52 = nullptr;
    v7 = v52;
    goto LABEL_80;
  }
  idLib::Error(fmt: "Invalid clip model info specified!");
  _LN293();
}


// ========================================================================
// $LN293
// EA  : 0x82C3BBD4
// RVA : 0x00C3BBD4
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _LN293()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1776 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496817
// EA  : 0x82C3BC00
// RVA : 0x00C3BC00
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496817()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1776 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496818
// EA  : 0x82C3BC2C
// RVA : 0x00C3BC2C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496818()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1776 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496819
// EA  : 0x82C3BC58
// RVA : 0x00C3BC58
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496819()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1776 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$496820
// EA  : 0x82C3BC84
// RVA : 0x00C3BC84
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_496820()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1776 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?GetDistanceSqrTo@idEntity@@QBAMABVidVec3@@@Z
// EA  : 0x82C3BCB0
// RVA : 0x00C3BCB0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

float __fastcall idEntity::GetDistanceSqrTo(idEntity *this, const idVec3 *pos)
{
  const idVec3 *v3; // r3
  double v4; // fp10
  double v5; // fp6
  double v6; // fp1

  v3 = this->physics->GetOrigin(this: this->physics, a2: 0);
  v4 = (float)(v3->y - pos->y);
  v5 = (float)(v3->z - pos->z);
  v6 = (float)((float)((float)v5 * (float)v5)
             + (float)((float)((float)(v3->x - pos->x) * (float)(v3->x - pos->x)) + (float)((float)v4 * (float)v4)));
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?CanDisablePhysics@idEntity@@UBA_NPBV1@@Z
// EA  : 0x82C3BD20
// RVA : 0x00C3BD20
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::CanDisablePhysics(idEntity *this, const idEntity *entity)
{
  return this->bindInfo.bindMaster != entity
      || (unsigned __int16)this->bindInfo.bindJoint.value == 0xFFFF
      && this->bindInfo.bindTag.parentJoint.value == 0xFFFF;
}


// ========================================================================
// ?ApplyImpulseFromEntity@idEntity@@UAAXPBV1@HABVidVec3@@1@Z
// EA  : 0x82C3BD60
// RVA : 0x00C3BD60
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ApplyImpulseFromEntity(
        idEntity *this,
        const idEntity *inflictor,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  int physicsId; // r4

  if ( inflictor != nullptr )
    physicsId = inflictor->physics->physicsId;
  else
    physicsId = -1;
  this->ApplyImpulse(this, a2: physicsId, a3: bodyId, a4: point, a5: impulse);
}


// ========================================================================
// ?DeactivatePhysics@idEntity@@UAAXH@Z
// EA  : 0x82C3BD88
// RVA : 0x00C3BD88
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::DeactivatePhysics(idEntity *this, int physId)
{
  ((void (__fastcall *)(idPhysics *, int))this->physics->PutToRest)(a1: this->physics, a2: physId);
  idEntity::BecomeInactive(this, flags: 2);
}


// ========================================================================
// ?Crush@idEntity@@UAA_NH@Z
// EA  : 0x82C3BDD0
// RVA : 0x00C3BDD0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::Crush(idEntity *this, int physId)
{
  idPhysics *PhysicsForId; // r3
  idEventArg *v4; // r31
  idEventArg *v5; // r3
  idEventArg v7; // [sp+50h] [-70h] BYREF
  idEventReceiver v8[6]; // [sp+70h] [-50h] BYREF

  if ( gameLocal->damageCrush == nullptr )
    return 0;
  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  if ( PhysicsForId != nullptr )
  {
    v4 = (idEventArg *)gameLocal->entities.ptr[PhysicsForId->entityNumber];
    if ( v4 != nullptr )
    {
      if ( (*(unsigned __int8 (__fastcall **)(idEventArg *, idEventDef *))(*(_DWORD *)&v4->type + 12))(
             a1: v4,
             a2: &EV_Crush) != 0 )
      {
        v5 = idEventArg::idEventArg(this: &v7, data: this);
        idEventReceiver::ProcessEvent(
          this: v8,
          result: v4,
          ev: *(const idEventDef **)&v5->type,
          arg1: (const idEventArg *)LODWORD(v5->value.v[1]));
        return 1;
      }
      ((void (__fastcall *)(idEntity *, idEventArg *, idEventArg *, const idDeclDamage *, double))this->Damage)(
        a1: this,
        a2: v4,
        a3: v4,
        a4: gameLocal->damageCrush,
        a5: 1.0);
    }
  }
  return 1;
}


// ========================================================================
// ?CalcDamageImpulse@idEntity@@UBA_NPBV1@0PBVidDeclDamage@@MABVidVec3@@PBUtrace_t@@AAV3@4@Z
// EA  : 0x82C3BEE0
// RVA : 0x00C3BEE0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::CalcDamageImpulse(
        idEntity *this,
        const idEntity *inflictor,
        const idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const trace_t *trace,
        idVec3 *impulsePoint,
        idVec3 *impulse,
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
        int a28,
        idVec3 *a29)
{
  idVec3 *v34; // r3
  __int64 v35; // r10
  double x; // fp12
  const idVec3 *v37; // r3
  double y; // fp12
  double v40; // fp13

  v34 = (idVec3 *)this->physics->GetOrigin(this: this->physics, a2: 0);
  HIDWORD(v35) = allocationCurrent[242];
  *impulse = *v34;
  *a29 = vec3_origin;
  if ( damageDef != nullptr )
  {
    if ( impulsePoint != nullptr )
    {
      impulse->x = impulsePoint->y;
      impulse->y = impulsePoint->z;
      x = impulsePoint[1].x;
LABEL_6:
      impulse->z = x;
      LODWORD(v35) = damageDef->knockBack;
      y = trace->endpos.y;
      v40 = trace->endpos.x;
      a29->x = trace->fraction * (float)v35;
      a29->y = (float)v40 * (float)v35;
      a29->z = (float)y * (float)v35;
      return 1;
    }
    if ( inflictor != nullptr )
    {
      v37 = inflictor->physics->GetOrigin(this: inflictor->physics, a2: 0);
      impulse->x = v37->x;
      impulse->y = v37->y;
      x = v37->z;
      goto LABEL_6;
    }
  }
  return 0;
}


// ========================================================================
// ?ConstructScriptObject@idEntity@@QAAXXZ
// EA  : 0x82C3C010
// RVA : 0x00C3C010
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ConstructScriptObject(idEntity *this)
{
  int v2; // r27
  int v3; // r29
  const function_t *Constructor; // r28
  idThread *v5; // r3
  idThread *v6; // r29

  if ( this->superScriptObjects.num > 0 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      idSuperScriptSystem::BindObject(
        this: &gameLocal->superScript,
        object: this->superScriptObjects.list[v3],
        entity: this);
      idSuperScriptSystem::AddObjectToInitList(this: &gameLocal->superScript, object: this->superScriptObjects.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->superScriptObjects.num );
  }
  if ( this->ShouldConstructScriptObjectAtSpawn(this) && idScriptObject::HasObject(this: &this->scriptObject) )
  {
    Constructor = idScriptObject::GetConstructor(this: &this->scriptObject);
    if ( Constructor != nullptr )
    {
      v5 = (idThread *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x1B94u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = idThread::idThread(this: v5);
      else
        v6 = nullptr;
      idThread::SetThreadName(this: v6, name: this->name.data);
      idThread::CallObjectFunction(this: v6, self: this, func: Constructor, clearStack: true);
      idThread::DelayedStart(this: v6, delay: 0);
      idThread::SetThreadEntity(this: v6, ent: this);
    }
  }
}


// ========================================================================
// __unwind$497525
// EA  : 0x82C3C15C
// RVA : 0x00C3C15C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall _unwind_497525(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?HasSignal@idEntity@@QBA_NW4signalNum_t@@@Z
// EA  : 0x82C3C188
// RVA : 0x00C3C188
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

unsigned int __fastcall idEntity::HasSignal(idEntity *this, signalNum_t signalnum)
{
  signalList_t *signals; // r11

  signals = this->signals;
  if ( signals != nullptr )
    return (-signals->signal[signalnum].num & (unsigned int)~signals->signal[signalnum].num) >> 31;
  else
    return 0;
}


// ========================================================================
// ?ClearSignalThread@idEntity@@QAAXW4signalNum_t@@PAVidThread@@@Z
// EA  : 0x82C3C1B8
// RVA : 0x00C3C1B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ClearSignalThread(idEntity *this, int signalnum, idThread *thread)
{
  signalList_t *signals; // r10
  int v4; // r4
  idList<idSWF::orphanedSprite_t,72> *v5; // r3
  int num; // r10
  int i; // r11

  if ( signalnum < 12 )
  {
    signals = this->signals;
    if ( signals != nullptr )
    {
      v5 = (idList<idSWF::orphanedSprite_t,72> *)&signals->signal[signalnum];
      v4 = 0;
      num = v5->num;
      if ( num > 0 )
      {
        for ( i = 0; v5->list[i].spriteInstance != (idSWFSpriteInstance *)thread->threadHandle.value; ++i )
        {
          if ( ++v4 >= num )
            return;
        }
        idList<idSWF::orphanedSprite_t,72>::RemoveIndex(this: v5, index: v4);
      }
    }
  }
  else
  {
    idLib::Error(fmt: "Signal out of range");
  }
}


// ========================================================================
// ?AddThread@idEntity@@UAAHV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82C3C220
// RVA : 0x00C3C220
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::AddThread(idEntity *this, const idHandle<int,enum invalidThreadHandle_t,0> *handle)
{
  if ( this->threadHandle.value != 0 )
    return -1;
  this->threadHandle.value = (int)handle;
  return 0;
}


// ========================================================================
// ?RemoveThread@idEntity@@UAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82C3C240
// RVA : 0x00C3C240
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RemoveThread(idEntity *this, const idHandle<int,enum invalidThreadHandle_t,0> *handle)
{
  if ( (const idHandle<int,enum invalidThreadHandle_t,0> *)this->threadHandle.value == handle )
    this->threadHandle.value = 0;
}


// ========================================================================
// ?GetThread@idEntity@@UBA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@H@Z
// EA  : 0x82C3C258
// RVA : 0x00C3C258
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetThread(
        idEntity *this,
        idHandle<int,enum invalidThreadHandle_t,0> *result,
        const int index)
{
  idEntity_vtbl *value; // r11

  value = nullptr;
  if ( index == 0 )
    value = (idEntity_vtbl *)result[121].value;
  this->__vftable = value;
  return this;
}


// ========================================================================
// ?NumThreads@idEntity@@UBAHXZ
// EA  : 0x82C3C270
// RVA : 0x00C3C270
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::NumThreads(idEntity *this)
{
  return this->threadHandle.value != 0;
}


// ========================================================================
// ?GetUsableState@idEntity@@UBA?AW4usableState_t@@PBV1@ABVidFocusTrace@@@Z
// EA  : 0x82C3C280
// RVA : 0x00C3C280
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

usableState_t __fastcall idEntity::GetUsableState(idEntity *this, idEntity *activator, const idFocusTrace *ft)
{
  idScriptObject *p_scriptObject; // r30
  double v7; // fp8
  double v8; // fp6
  double v9; // fp31
  idVec3 v11; // [sp+80h] [-190h] BYREF
  idScriptFunction v12; // [sp+90h] [-180h] BYREF

  p_scriptObject = &this->scriptObject;
  if ( !idScriptObject::HasObject(this: &this->scriptObject) )
    return USABLE_NOT_USABLE;
  idScriptFunction::idScriptFunction(this: &v12);
  if ( idScriptObject::GetFunction(this: p_scriptObject, name: "getUsableState") == nullptr )
    return USABLE_NOT_USABLE;
  idScriptFunction::SetFunction(
    this: &v12,
    ent: this,
    functionName: "getUsableState",
    returnType: ev_float,
    numParms: 4,
    8,
    "activator",
    6);
  if ( idScriptFunction::GetFunction(this: &v12) == nullptr )
    return USABLE_NOT_USABLE;
  idScriptFunction::SetArg_Entity(this: &v12, argNum: 0, ent: activator);
  idScriptFunction::SetArg_Vec3(this: &v12, argNum: 1, vec: &ft->start);
  v7 = (float)(ft->end.y - ft->start.y);
  v8 = (float)(ft->end.z - ft->start.z);
  v11.x = ft->end.x - ft->start.x;
  v11.y = v7;
  v11.z = v8;
  v9 = idVec3::NormalizeFast(this: &v11);
  idScriptFunction::SetArg_Vec3(this: &v12, argNum: 2, vec: &v11);
  idScriptFunction::SetArg_Float(this: &v12, argNum: 3, value: v9);
  idScriptFunction::CallFunction(this: &v12, defer: false);
  return *gameLocal->program.returnDef->value.value.ip;
}


// ========================================================================
// ?IsCrosshairDisabled@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@@Z
// EA  : 0x82C3C408
// RVA : 0x00C3C408
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::IsCrosshairDisabled(
        idEntity *this,
        idActor *activator,
        const idFocusTrace *ft,
        const usableState_t usable)
{
  idActor *v7; // r3
  __int64 v9; // r11
  idScriptFunction v10; // [sp+70h] [-180h] BYREF

  v7 = idActor::CastTo(c: activator);
  if ( v7 != nullptr && v7->IsDead(this: v7) )
    return 1;
  if ( idScriptObject::HasObject(this: &this->scriptObject) )
  {
    if ( idScriptObject::GetFunction(this: &this->scriptObject, name: "isCrosshairDisabled") != nullptr )
    {
      idScriptFunction::idScriptFunction(this: &v10);
      idScriptFunction::SetFunction(
        this: &v10,
        ent: this,
        functionName: "isCrosshairDisabled",
        returnType: ev_integer,
        numParms: 2,
        8,
        "activator",
        4);
      if ( idScriptFunction::GetFunction(this: &v10) != nullptr )
      {
        idScriptFunction::SetArg_Entity(this: &v10, argNum: 0, ent: activator);
        LODWORD(v9) = usable;
        idScriptFunction::SetArg_Float(this: &v10, argNum: 1, value: (float)v9);
        idScriptFunction::CallFunction(this: &v10, defer: false);
        return *gameLocal->program.returnDef->value.value.ip != 0;
      }
    }
    else if ( idScriptObject::GetFunction(this: &this->scriptObject, name: "canUse") != nullptr )
    {
      idScriptFunction::idScriptFunction(this: &v10);
      idScriptFunction::SetFunction(
        this: &v10,
        ent: this,
        functionName: "canUse",
        returnType: ev_integer,
        numParms: 1,
        8,
        "activator");
      if ( idScriptFunction::GetFunction(this: &v10) != nullptr )
      {
        idScriptFunction::SetArg_Entity(this: &v10, argNum: 0, ent: activator);
        idScriptFunction::CallFunction(this: &v10, defer: false);
        return (_cntlzw(*gameLocal->program.returnDef->value.value.ip) & 0x20) != 0;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?IsCrosshairSubdued@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@@Z
// EA  : 0x82C3C5F0
// RVA : 0x00C3C5F0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsCrosshairSubdued(
        idEntity *this,
        idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable)
{
  idScriptObject *p_scriptObject; // r31
  __int64 v8; // r11
  idScriptFunction v10; // [sp+70h] [-170h] BYREF

  p_scriptObject = &this->scriptObject;
  if ( !idScriptObject::HasObject(this: &this->scriptObject) )
    return false;
  if ( idScriptObject::GetFunction(this: p_scriptObject, name: "isCrosshairSubdued") == nullptr )
    return false;
  idScriptFunction::idScriptFunction(this: &v10);
  idScriptFunction::SetFunction(
    this: &v10,
    ent: this,
    functionName: "isCrosshairSubdued",
    returnType: ev_integer,
    numParms: 2,
    8,
    "activator",
    4);
  if ( idScriptFunction::GetFunction(this: &v10) == nullptr )
    return false;
  idScriptFunction::SetArg_Entity(this: &v10, argNum: 0, ent: activator);
  LODWORD(v8) = usable;
  idScriptFunction::SetArg_Float(this: &v10, argNum: 1, value: (float)v8);
  idScriptFunction::CallFunction(this: &v10, defer: false);
  return *gameLocal->program.returnDef->value.value.ip != 0;
}


// ========================================================================
// ?ClearTargets@idEntity@@QAAXXZ
// EA  : 0x82C3C700
// RVA : 0x00C3C700
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ClearTargets(idEntity *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targets);
}


// ========================================================================
// ?IsPusher@idEntity@@UAA_NXZ
// EA  : 0x82C3C708
// RVA : 0x00C3C708
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsPusher(idEntity *this)
{
  idPhysics *physics; // r3

  physics = this->physics;
  return physics->type == PHYSICS_PARAMETRIC && idPhysics_Parametric::IsPusher(this: (idPhysics_Parametric *)physics);
}


// ========================================================================
// ?Event_GetName@idEntity@@AAA?AVeventString@@XZ
// EA  : 0x82C3C728
// RVA : 0x00C3C728
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetName(idEntity *this, eventString *result)
{
  eventString::eventString((eventString *)this, s: result[4].value);
  return this;
}


// ========================================================================
// ?Event_ActivateTargets@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C3C760
// RVA : 0x00C3C760
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_ActivateTargets(idEntity *this, eventVoid *result, idEntity *activator)
{
  (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 380))(a1: result, a2: activator);
  return this;
}


// ========================================================================
// ?Event_MakeActivatable@idEntity@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82C3C7A8
// RVA : 0x00C3C7A8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_MakeActivatable(idEntity *this, eventVoid *result, bool activatable)
{
  int v3; // r8

  v3 = *(_DWORD *)result;
  result[92] = (eventVoid)((8 * activatable) & 8 | *(_BYTE *)&result[92] & 0xF7);
  (*(void (__fastcall **)(eventVoid *, bool))(v3 + 620))(a1: result, a2: activatable);
  return this;
}


// ========================================================================
// ?Event_ClearTargets@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3C800
// RVA : 0x00C3C800
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_ClearTargets(idEntity *this, eventVoid *result)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&result[96]);
  return this;
}


// ========================================================================
// ?Event_SetOwner@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C3C838
// RVA : 0x00C3C838
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetOwner(idEntity *this, eventVoid *result, idEntity *owner)
{
  int i; // r31
  int entityNumber; // r27

  for ( i = 0; i < (*(int (__fastcall **)(_DWORD))(**(_DWORD **)&result[680] + 12))(a1: *(_DWORD *)&result[680]); ++i )
  {
    entityNumber = owner->entityNumber;
    *(_DWORD *)((*(int (__fastcall **)(_DWORD, int))(**(_DWORD **)&result[680] + 8))(a1: *(_DWORD *)&result[680], a2: i)
              + 16) = entityNumber;
  }
  return this;
}


// ========================================================================
// ?Event_SetProgressionOwner@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C3C8C0
// RVA : 0x00C3C8C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idEntity::Event_SetProgressionOwner@<r4>(idEntity *this@<r3>, int result@<r4>, idEntity *owner@<r5>)
{
  *(_DWORD *)(result + 724) = owner;
  return result;
}


// ========================================================================
// ?Event_NotifyProgressionOwner@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3C8C8
// RVA : 0x00C3C8C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_NotifyProgressionOwner(idEntity *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 624))(a1: result);
  return this;
}


// ========================================================================
// ?Event_SetModel@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C3C908
// RVA : 0x00C3C908
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetModel(idEntity *this, eventVoid *result, const char *modelname)
{
  (*(void (__fastcall **)(eventVoid *, const char *))(*(_DWORD *)result + 84))(a1: result, a2: modelname);
  return this;
}


// ========================================================================
// ?Event_SetClipModel@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C3C958
// RVA : 0x00C3C958
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetClipModel(idEntity *this, eventVoid *result, const char *clipModelName)
{
  int v6; // r11
  idClipModel *v7; // r3
  idClipModel *v8; // r4

  v6 = 0;
  if ( *clipModelName != 0 )
  {
    do
      ++v6;
    while ( clipModelName[v6] != 0 );
    if ( v6 != 0 )
    {
      v7 = (idClipModel *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idClipModel::idClipModel(
               this: v7,
               clip: &clientGame->clip,
               name: clipModelName,
               overrideClipMaterial: nullptr);
      else
        v8 = nullptr;
      if ( v8 != nullptr )
        (*(void (__fastcall **)(_DWORD, double))(**(_DWORD **)&result[680] + 4))(a1: *(_DWORD *)&result[680], a2: 1.0);
    }
  }
  return this;
}


// ========================================================================
// __unwind$497810
// EA  : 0x82C3CA2C
// RVA : 0x00C3CA2C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_497810()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Event_SetColorAndAlpha@idEntity@@AAA?AVeventVoid@@MMMM@Z
// EA  : 0x82C3CA58
// RVA : 0x00C3CA58
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetColorAndAlpha(
        idEntity *this,
        eventVoid *result,
        double red,
        double green,
        double blue,
        double alpha)
{
  (*(void (__fastcall **)(eventVoid *, double, double, double, double))(*(_DWORD *)result + 112))(
    a1: result,
    a2: red,
    a3: green,
    a4: blue,
    a5: alpha);
  return this;
}


// ========================================================================
// ?Event_SetColor@idEntity@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C3CA98
// RVA : 0x00C3CA98
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetColor(idEntity *this, eventVoid *result, double red, double green, double blue)
{
  (*(void (__fastcall **)(eventVoid *, double, double, double))(*(_DWORD *)result + 108))(
    a1: result,
    a2: red,
    a3: green,
    a4: blue);
  return this;
}


// ========================================================================
// ?Event_GetColor@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CAD8
// RVA : 0x00C3CAD8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetColor(idEntity *this, eventVector *result)
{
  idVec3 v4; // [sp+50h] [-20h] BYREF

  (*(void (__fastcall **)(eventVector *, idVec3 *))(LODWORD(result->value.x) + 124))(a1: result, a2: &v4);
  eventVector::eventVector((eventVector *)this, v: &v4);
  return this;
}


// ========================================================================
// ?Event_SetAngles@idEntity@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C3CB30
// RVA : 0x00C3CB30
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetAngles(idEntity *this, eventVoid *result, idMat3 *ang)
{
  int v5; // r31
  idMat3 *v6; // r3
  idAngles v8[6]; // [sp+50h] [-50h] BYREF

  v5 = *(_DWORD *)result;
  v6 = idAngles::ToMat3(this: v8, result: ang);
  (*(void (__fastcall **)(eventVoid *, idMat3 *))(v5 + 248))(a1: result, a2: v6);
  return this;
}


// ========================================================================
// ?Event_GetAngles@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CB78
// RVA : 0x00C3CB78
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetAngles(idEntity *this, eventVector *result)
{
  idAngles *v3; // r3
  idMat3 v5; // [sp+50h] [-30h] BYREF

  v3 = (idAngles *)(*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(result[56].value.z) + 68))(
                     a1: LODWORD(result[56].value.z),
                     a2: 0);
  idMat3::ToAngles(this: &v5, result: v3);
  idAngles::Normalize360(this: (idAngles *)&v5);
  v5.mat[1].y = v5.mat[0].x;
  v5.mat[1].z = v5.mat[0].y;
  v5.mat[2].x = v5.mat[0].z;
  eventVector::eventVector((eventVector *)this, v: (const idVec3 *)&v5.mat[1].y);
  return this;
}


// ========================================================================
// ?Event_GetModelForward@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CBF8
// RVA : 0x00C3CBF8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetModelForward(idEntity *this, eventVector *result)
{
  float z; // r11
  int v4; // r11
  const idVec3 *v5; // r4
  float v7[4]; // [sp+50h] [-20h] BYREF

  z = result[40].value.z;
  if ( z == 0.0 )
    v4 = 0;
  else
    v4 = *(_DWORD *)(LODWORD(z) + 168);
  if ( v4 != 0 )
  {
    v5 = (const idVec3 *)(v4 + 36);
    if ( *(_BYTE *)(v4 + 72) == 0 )
      v5 = (const idVec3 *)(v4 + 128);
  }
  else
  {
    v5 = (const idVec3 *)v7;
    v7[0] = 1.0;
    v7[1] = 0.0;
    v7[2] = 0.0;
  }
  eventVector::eventVector((eventVector *)this, v: v5);
  return this;
}


// ========================================================================
// ?Event_SetLinearVelocity@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C3CC88
// RVA : 0x00C3CC88
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetLinearVelocity(idEntity *this, eventVoid *result, const idVec3 *velocity)
{
  (*(void (__fastcall **)(_DWORD, const idVec3 *, _DWORD))(**(_DWORD **)&result[680] + 80))(
    a1: *(_DWORD *)&result[680],
    a2: velocity,
    a3: 0);
  return this;
}


// ========================================================================
// ?Event_SetAngularVelocity@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C3CCD8
// RVA : 0x00C3CCD8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetAngularVelocity(idEntity *this, eventVoid *result, const idVec3 *velocity)
{
  (*(void (__fastcall **)(_DWORD, const idVec3 *, _DWORD))(**(_DWORD **)&result[680] + 84))(
    a1: *(_DWORD *)&result[680],
    a2: velocity,
    a3: 0);
  return this;
}


// ========================================================================
// ?Event_GetSize@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CD28
// RVA : 0x00C3CD28
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetSize(idEntity *this, eventVector *result)
{
  float *v3; // r3
  double v4; // fp7
  double v5; // fp6
  idVec3 v7; // [sp+50h] [-20h] BYREF

  v3 = (float *)(*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)LODWORD(result[56].value.z) + 40))(
                  a1: LODWORD(result[56].value.z),
                  a2: -1);
  v4 = (float)(v3[4] - v3[1]);
  v5 = (float)(v3[5] - v3[2]);
  v7.x = v3[3] - *v3;
  v7.y = v4;
  v7.z = v5;
  eventVector::eventVector((eventVector *)this, v: &v7);
  return this;
}


// ========================================================================
// ?Event_GetMins@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CDB0
// RVA : 0x00C3CDB0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetMins(idEntity *this, eventVector *result)
{
  const idVec3 *v3; // r3

  v3 = (const idVec3 *)(*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)LODWORD(result[56].value.z) + 40))(
                         a1: LODWORD(result[56].value.z),
                         a2: -1);
  eventVector::eventVector((eventVector *)this, v: v3);
  return this;
}


// ========================================================================
// ?Event_GetMaxs@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C3CE00
// RVA : 0x00C3CE00
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetMaxs(idEntity *this, eventVector *result)
{
  const idVec3 *v3; // r3

  v3 = (const idVec3 *)(*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)LODWORD(result[56].value.z) + 40))(
                         a1: LODWORD(result[56].value.z),
                         a2: -1);
  eventVector::eventVector((eventVector *)this, v: v3 + 1);
  return this;
}


// ========================================================================
// ?Event_Touches@idEntity@@AAA?AVeventInt@@PAV1@@Z
// EA  : 0x82C3CE58
// RVA : 0x00C3CE58
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Touches(idEntity *this, eventInt *result, idEntity *ent)
{
  int v5; // r4
  int v6; // r3
  idPhysics *physics; // r9
  idBounds *v8; // r30
  const idBounds *v9; // r3

  if ( ent != nullptr )
  {
    v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)result[170].value + 44))(a1: result[170].value, a2: -1);
    physics = ent->physics;
    v8 = (idBounds *)v6;
    v9 = physics->GetAbsBounds(this: physics, a2: -1);
    v5 = (unsigned __int8)idBounds::IntersectsBounds(this: v8, a: v9);
  }
  else
  {
    v5 = 0;
  }
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?Event_RestorePosition@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3CEF0
// RVA : 0x00C3CEF0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RestorePosition(idEntity *this, eventVoid *result)
{
  int v4; // r31
  idAngles *v5; // r3
  int i; // r31
  int v7; // r3
  int v8; // r11
  idMat3 v10; // [sp+50h] [-40h] BYREF

  v4 = *(_DWORD *)result;
  v5 = idMat3::ToAngles(this: &v10, result: (idAngles *)&result[56]);
  (*(void (__fastcall **)(eventVoid *, eventVoid *, idAngles *))(v4 + 404))(a1: result, a2: result + 44, a3: v5);
  for ( i = *(_DWORD *)&result[408]; i != 0; i = *(_DWORD *)(i + 408) )
  {
    if ( *(eventVoid **)(i + 400) == result )
    {
      v7 = *(_DWORD *)(i + 680);
      v8 = *(_DWORD *)(v7 + 8);
      if ( v8 == 5 )
      {
        if ( idPhysics_Parametric::IsPusher(this: (idPhysics_Parametric *)v7) )
          idLib::Warning(
            fmt: "teleported '%s' which has the pushing mover '%s' bound to it",
            *(_DWORD *)&result[16],
            *(_DWORD *)(i + 16));
      }
      else if ( v8 == 8 )
      {
        idLib::Warning(
          fmt: "teleported '%s' which has the articulated figure '%s' bound to it",
          *(_DWORD *)&result[16],
          *(_DWORD *)(i + 16));
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_DistanceTo@idEntity@@AAA?AVeventFloat@@PAV1@@Z
// EA  : 0x82C3CFB0
// RVA : 0x00C3CFB0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_DistanceTo(idEntity *this, eventFloat *result, idEntity *ent)
{
  float value; // r30
  const idVec3 *v6; // r29
  float *v7; // r3
  double v8; // fp8
  double v9; // fp6
  double v10; // fp3
  double v12; // fp1
  double v14; // fp12
  double v15; // fp8

  if ( ent != nullptr )
  {
    value = result[170].value;
    v6 = ent->physics->GetOrigin(this: ent->physics, a2: 0);
    v7 = (float *)(*(int (__fastcall **)(double, _DWORD))(*(_DWORD *)LODWORD(value) + 64))(
                    a1: COERCE_DOUBLE(LODWORD(value)),
                    a2: 0);
    v8 = (float)(v7[2] - v6->z);
    v9 = (float)(v7[1] - v6->y);
    v10 = (float)((float)((float)v9 * (float)v9)
                + (float)((float)((float)v8 * (float)v8) + (float)((float)(*v7 - v6->x) * (float)(*v7 - v6->x))));
    _FP2 = (float)((float)((float)((float)v9 * (float)v9)
                         + (float)((float)((float)v8 * (float)v8) + (float)((float)(*v7 - v6->x) * (float)(*v7 - v6->x))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v12 = (float)((float)((float)((float)v9 * (float)v9)
                        + (float)((float)((float)v8 * (float)v8) + (float)((float)(*v7 - v6->x) * (float)(*v7 - v6->x))))
                * (float)0.5);
    __asm { fsel      f13, f2, f3, f13 }
    v14 = __frsqrte(_FP13);
    v15 = (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)v9 * (float)v9)
                                                                + (float)((float)((float)v8 * (float)v8)
                                                                        + (float)((float)(*v7 - v6->x)
                                                                                * (float)(*v7 - v6->x))))
                                                        * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14);
    eventFloat::eventFloat(
      (eventFloat *)this,
      f: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v12)
                                                                                    * (float)v15)
                                                                            - (float)1.5)
                                                            * (float)v15)
                                                    * (float)v12)
                                            * (float)((float)-(float)((float)((float)((float)v15 * (float)v12)
                                                                            * (float)v15)
                                                                    - (float)1.5)
                                                    * (float)v15))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v15 * (float)v12) * (float)v15) - (float)1.5)
                            * (float)v15))
            * (float)v10));
  }
  else
  {
    eventFloat::eventFloat((eventFloat *)this, f: 262144.0);
  }
  return this;
}


// ========================================================================
// ?Event_DistanceToPoint@idEntity@@AAA?AVeventFloat@@ABVidVec3@@@Z
// EA  : 0x82C3D0B8
// RVA : 0x00C3D0B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_DistanceToPoint(idEntity *this, eventFloat *result, const idVec3 *point)
{
  float *v5; // r3
  double v6; // fp10
  double v7; // fp6
  double v8; // fp3
  double v10; // fp1
  double v12; // fp12
  double v13; // fp10

  v5 = (float *)(*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(result[170].value) + 64))(
                  a1: LODWORD(result[170].value),
                  a2: 0);
  v6 = (float)(v5[2] - point->z);
  v7 = (float)(v5[1] - point->y);
  v8 = (float)((float)((float)v7 * (float)v7)
             + (float)((float)((float)(*v5 - point->x) * (float)(*v5 - point->x)) + (float)((float)v6 * (float)v6)));
  _FP2 = (float)((float)((float)((float)v7 * (float)v7)
                       + (float)((float)((float)(*v5 - point->x) * (float)(*v5 - point->x))
                               + (float)((float)v6 * (float)v6)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v10 = (float)((float)((float)((float)v7 * (float)v7)
                      + (float)((float)((float)(*v5 - point->x) * (float)(*v5 - point->x))
                              + (float)((float)v6 * (float)v6)))
              * (float)0.5);
  __asm { fsel      f13, f2, f3, f13 }
  v12 = __frsqrte(_FP13);
  v13 = (float)((float)v12
              * (float)((float)((float)((float)v7 * (float)v7)
                              + (float)((float)((float)(*v5 - point->x) * (float)(*v5 - point->x))
                                      + (float)((float)v6 * (float)v6)))
                      * (float)0.5));
  eventFloat::eventFloat(
    (eventFloat *)this,
    f: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                                                                  * (float)v12)
                                                                                          * (float)v10)
                                                                                  * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                                                          * (float)v12))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)v13 * (float)v12)
                                                                                  - (float)1.5)
                                                                  * (float)v12))
                                                  * (float)v10)
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                                                          * (float)v12)
                                                                                  * (float)v10)
                                                                          * (float)((float)-(float)((float)((float)v13 * (float)v12)
                                                                                                  - (float)1.5)
                                                                                  * (float)v12))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                          * (float)v12)))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v13 * (float)v12)
                                                                                  - (float)1.5)
                                                                  * (float)v12)
                                                          * (float)v10)
                                                  * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                          * (float)v12))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12)))
          * (float)v8));
  return this;
}


// ========================================================================
// ?Event_WaitFrame@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3D198
// RVA : 0x00C3D198
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_WaitFrame(idEntity *this, eventVoid *result)
{
  idThread *currentThread; // r3

  currentThread = gameLocal->program.threadManager.currentThread;
  if ( currentThread != nullptr )
    idThread::WaitFrame(this: currentThread);
  return this;
}


// ========================================================================
// ?Event_Wait@idEntity@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C3D1E8
// RVA : 0x00C3D1E8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Wait(idEntity *this, eventVoid *result, double time)
{
  idThread *currentThread; // r3

  currentThread = gameLocal->program.threadManager.currentThread;
  if ( currentThread == nullptr )
    idLib::Error(fmt: "Event 'wait' called from outside thread", result, time);
  idThread::WaitSec(this: currentThread, time);
  return this;
}


// ========================================================================
// ?Event_CallFunction@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C3D240
// RVA : 0x00C3D240
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_CallFunction(idEntity *this, idEntity *result, const char *funcname)
{
  idThread *currentThread; // r27
  const function_t *Function; // r31
  const char *TypeName; // r3
  const idTypeDef *ParmType; // r25
  idTypeDef *TypeDef; // r3

  currentThread = gameLocal->program.threadManager.currentThread;
  if ( currentThread == nullptr )
    idLib::Error(fmt: "Event 'callFunction' called from outside thread");
  Function = idScriptObject::GetFunction(this: &result->scriptObject, name: funcname);
  if ( Function == nullptr )
  {
    TypeName = idScriptObject::GetTypeName(this: &result->scriptObject);
    idLib::Error(fmt: "Unknown function '%s' in '%s'", funcname, TypeName);
  }
  if ( function_t::Name(this: (idDecl *)Function->type) != (idDeclSource *)1 )
    idLib::Error(fmt: "Function '%s' has the wrong number of parameters for 'callFunction'", funcname);
  ParmType = idTypeDef::GetParmType(this: (idTypeDef *)Function->type, parmNumber: 0);
  TypeDef = (idTypeDef *)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&result->scriptObject);
  if ( !idTypeDef::Inherits(this: TypeDef, basetype: ParmType) )
    idLib::Error(fmt: "Function '%s' is the wrong type for 'callFunction'", funcname);
  idThread::CallObjectFunction(this: currentThread, self: result, func: Function, clearStack: false);
  return this;
}


// ========================================================================
// ?Event_SetCanBecomeDormant@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D338
// RVA : 0x00C3D338
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetCanBecomeDormant(idEntity *this, idEntity *result, int enable)
{
  *(_BYTE *)&result->flags = ((enable != 0) << 6) & 0x40 | *(_BYTE *)&result->flags & 0xBF;
  idEntity::LeaveDormancy(this: result);
  return this;
}


// ========================================================================
// ?Event_Teleport@idEntity@@AAA?AVeventVoid@@ABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82C3D380
// RVA : 0x00C3D380
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Teleport(
        idEntity *this,
        eventVoid *result,
        const idVec3 *origin,
        const idAngles *angles)
{
  (*(void (__fastcall **)(eventVoid *, const idVec3 *, const idAngles *))(*(_DWORD *)result + 404))(
    a1: result,
    a2: origin,
    a3: angles);
  return this;
}


// ========================================================================
// ?Event_ClampAngles@idEntity@@AAA?AVeventVector@@ABVidAngles@@00@Z
// EA  : 0x82C3D3D0
// RVA : 0x00C3D3D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_ClampAngles(
        idEntity *this,
        eventVector *result,
        const idAngles *_angles,
        const idAngles *center,
        const idAngles *offset)
{
  float yaw; // r10
  float roll; // r9
  double v10; // fp13
  double v11; // fp12
  double v12; // fp0
  double pitch; // fp0
  idAngles v15; // [sp+50h] [-50h] BYREF
  idAngles v16; // [sp+60h] [-40h] BYREF
  idVec3 v17; // [sp+70h] [-30h] BYREF

  yaw = _angles->yaw;
  roll = _angles->roll;
  v15.pitch = _angles->pitch;
  v15.yaw = yaw;
  v15.roll = roll;
  idAngles::Normalize180(this: &v15);
  v10 = center->yaw;
  v11 = center->roll;
  v16.pitch = center->pitch;
  v16.yaw = v10;
  v16.roll = v11;
  idAngles::Normalize180(this: &v16);
  v12 = v15.yaw;
  if ( v15.yaw < (double)(float)(v16.yaw - (float)180.0) )
  {
    v12 = (float)(v15.yaw + (float)360.0);
    v15.yaw = v15.yaw + (float)360.0;
  }
  if ( v12 >= (float)(v16.yaw + (float)180.0) )
  {
    v12 = (float)((float)v12 - (float)360.0);
    v15.yaw = v12;
  }
  if ( v12 >= (float)(v16.yaw - offset->yaw) )
  {
    if ( v12 > (float)(offset->yaw + v16.yaw) )
      v15.yaw = offset->yaw + v16.yaw;
  }
  else
  {
    v15.yaw = v16.yaw - offset->yaw;
  }
  pitch = v15.pitch;
  if ( v15.pitch < (double)(float)(v16.pitch - (float)180.0) )
  {
    pitch = (float)(v15.pitch + (float)360.0);
    v15.pitch = v15.pitch + (float)360.0;
  }
  if ( pitch >= (float)(v16.pitch + (float)180.0) )
  {
    pitch = (float)((float)pitch - (float)360.0);
    v15.pitch = pitch;
  }
  if ( pitch >= (float)(v16.pitch - offset->pitch) )
  {
    if ( pitch > (float)(offset->pitch + v16.pitch) )
      v15.pitch = offset->pitch + v16.pitch;
  }
  else
  {
    v15.pitch = v16.pitch - offset->pitch;
  }
  idAngles::Normalize180(this: &v15);
  v17.x = v15.pitch;
  v17.y = v15.yaw;
  v17.z = v15.roll;
  eventVector::eventVector((eventVector *)this, v: &v17);
  return this;
}


// ========================================================================
// ?Event_TestFunctionality@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3D520
// RVA : 0x00C3D520
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_TestFunctionality(idEntity *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 420))(a1: result);
  return this;
}


// ========================================================================
// ?CreateEntityInterface@idEntity@@UAAPAVidEntityInterface@@PAVidGame@@@Z
// EA  : 0x82C3D568
// RVA : 0x00C3D568
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntityInterfaceLocal *__fastcall idEntity::CreateEntityInterface(idEntity *this, idGame *game)
{
  idEntityInterfaceLocal *v4; // r3

  v4 = (idEntityInterfaceLocal *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x14u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idEntityInterfaceLocal::idEntityInterfaceLocal(this: v4, game, ent: this);
  else
    return nullptr;
}


// ========================================================================
// __unwind$498391
// EA  : 0x82C3D5D0
// RVA : 0x00C3D5D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall _unwind_498391(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Event_IsClass@idEntity@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82C3D5F8
// RVA : 0x00C3D5F8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_IsClass(idEntity *this, idClass *result, const char *className)
{
  const char *v6; // r3
  idClass_vtbl *v8; // r3
  const char *v9; // r3
  idTypeInfo *Class; // r31

  v6 = idClass::GetClassname(this: result);
  if ( idStr::Icmp(s1: className, s2: v6) == 0 )
  {
LABEL_2:
    eventBool::eventBool((eventBool *)this, b: true);
    return this;
  }
  v8 = result[124].__vftable;
  if ( v8 != nullptr )
  {
    v9 = (const char *)(*((int (__fastcall **)(idClass_vtbl *))v8->GetType + 19))(a1: v8);
    Class = idClass::GetClass(name: v9);
    if ( Class != nullptr )
    {
      while ( idStr::Icmp(s1: Class->classname, s2: className) != 0 )
      {
        Class = Class->super;
        if ( Class == nullptr )
          goto LABEL_9;
      }
      goto LABEL_2;
    }
  }
  else
  {
    idLib::Warning(fmt: "NO ENTITY DEF FOR ENTITY '%s'", (const char *)result[4].__vftable);
  }
LABEL_9:
  eventBool::eventBool((eventBool *)this, b: false);
  return this;
}


// ========================================================================
// ?Event_PostSpawn@idInfo_TraversalChain@@QAA?AVeventVoid@@XZ
// EA  : 0x82C3D6C0
// RVA : 0x00C3D6C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idInfo_TraversalChain *__fastcall idInfo_TraversalChain::Event_PostSpawn(
        idInfo_TraversalChain *this,
        eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 28))(a1: result);
  return this;
}


// ========================================================================
// ?Event_SetContents@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D700
// RVA : 0x00C3D700
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetContents(idEntity *this, eventVoid *result, int contents)
{
  int v4; // r3

  v4 = *(_DWORD *)&result[680];
  if ( v4 != 0 )
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v4 + 24))(a1: v4, a2: contents, a3: -1);
  return this;
}


// ========================================================================
// ?Event_AddContentsFlag@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D758
// RVA : 0x00C3D758
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_AddContentsFlag(idEntity *this, eventVoid *result, const int contents)
{
  int v3; // r31
  int v6; // r3

  v3 = *(_DWORD *)&result[680];
  if ( v3 != 0 )
  {
    v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v3 + 28))(a1: v3, a2: -1);
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v3 + 24))(a1: v3, a2: v6 | contents, a3: -1);
  }
  return this;
}


// ========================================================================
// ?Event_RemoveContentsFlag@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D7B8
// RVA : 0x00C3D7B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RemoveContentsFlag(idEntity *this, eventVoid *result, const int contents)
{
  int v3; // r31
  int v6; // r3

  v3 = *(_DWORD *)&result[680];
  if ( v3 != 0 )
  {
    v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v3 + 28))(a1: v3, a2: -1);
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v3 + 24))(a1: v3, a2: v6 & ~contents, a3: -1);
  }
  return this;
}


// ========================================================================
// ?Event_SetClipMask@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D818
// RVA : 0x00C3D818
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetClipMask(idEntity *this, eventVoid *result, int mask)
{
  int v4; // r3

  v4 = *(_DWORD *)&result[680];
  if ( v4 != 0 )
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v4 + 32))(a1: v4, a2: mask, a3: -1);
  return this;
}


// ========================================================================
// ?Event_AddClipMaskFlag@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D870
// RVA : 0x00C3D870
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_AddClipMaskFlag(idEntity *this, eventVoid *result, const int mask)
{
  int v3; // r31
  int v6; // r3

  v3 = *(_DWORD *)&result[680];
  if ( v3 != 0 )
  {
    v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v3 + 36))(a1: v3, a2: -1);
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v3 + 32))(a1: v3, a2: v6 | mask, a3: -1);
  }
  return this;
}


// ========================================================================
// ?Event_RemoveClipMaskFlag@idEntity@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C3D8D0
// RVA : 0x00C3D8D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RemoveClipMaskFlag(idEntity *this, eventVoid *result, const int mask)
{
  int v3; // r31
  int v6; // r3

  v3 = *(_DWORD *)&result[680];
  if ( v3 != 0 )
  {
    v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v3 + 36))(a1: v3, a2: -1);
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)v3 + 24))(a1: v3, a2: v6 & ~mask, a3: -1);
  }
  return this;
}


// ========================================================================
// ?Event_SetTakesDamage@idEntity@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82C3D930
// RVA : 0x00C3D930
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idEntity::Event_SetTakesDamage@<r4>(idEntity *this@<r3>, int result@<r4>, const bool takesDamage@<r5>)
{
  *(_BYTE *)(result + 92) = (2 * takesDamage) & 2 | *(_BYTE *)(result + 92) & 0xFD;
  return result;
}


// ========================================================================
// ?GetTeam@idEntity@@QBA?AW4gameTeam_t@@XZ
// EA  : 0x82C3D948
// RVA : 0x00C3D948
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

gameTeam_t __fastcall idEntity::GetTeam(idEntity *this)
{
  idPresentable *presentable; // r11
  gameTeam_t result; // r3

  presentable = this->presentable;
  result = TEAM_NONE;
  if ( presentable != nullptr )
    return presentable->team;
  return result;
}


// ========================================================================
// ?GetViewStateFOV@idEntity@@UAAXAAVidVec3@@AAE1@Z
// EA  : 0x82C3D960
// RVA : 0x00C3D960
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetViewStateFOV(
        idEntity *this,
        idVec3 *viewfwd,
        unsigned __int8 *horzFOV,
        unsigned __int8 *vertFOV)
{
  idRenderModelInfo *v8; // r3
  idRenderModel *model; // r11
  float *p_deferredAxis; // r11
  double z; // fp12
  idPhysics *physics; // r3
  float *v13; // r3

  v8 = this->GetRenderModelInfo(this);
  if ( v8 != nullptr && (model = v8->model, v8->model != nullptr) )
  {
    if ( model->useDeferredPosition )
      p_deferredAxis = (float *)&model->deferredAxis;
    else
      p_deferredAxis = (float *)&model->g.axis;
    viewfwd->x = *p_deferredAxis;
    viewfwd->y = p_deferredAxis[1];
    z = p_deferredAxis[2];
  }
  else
  {
    physics = this->physics;
    if ( physics != nullptr )
    {
      v13 = (float *)physics->GetAxis(this: physics, a2: 0);
      viewfwd->x = *v13;
      viewfwd->y = v13[1];
      z = v13[2];
    }
    else
    {
      viewfwd->x = this->spawnOrientation.mat[0].x;
      viewfwd->y = this->spawnOrientation.mat[0].y;
      z = this->spawnOrientation.mat[0].z;
    }
  }
  viewfwd->z = z;
  *horzFOV = 0;
  *vertFOV = 0;
}


// ========================================================================
// ?GetViewStateFOV@idEntity@@UBAXAAVidVec3@@AAE1@Z
// EA  : 0x82C3DA38
// RVA : 0x00C3DA38
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::GetViewStateFOV(
        idEntity *this,
        idVec3 *viewfwd,
        unsigned __int8 *horzFOV,
        unsigned __int8 *vertFOV)
{
  const idRenderModelInfo *v8; // r3
  idRenderModel *model; // r11
  float *p_deferredAxis; // r11
  double z; // fp12
  idPhysics *physics; // r3
  float *v13; // r3

  v8 = this->GetRenderModelInfo_2(this);
  if ( v8 != nullptr && (model = v8->model, v8->model != nullptr) )
  {
    if ( model->useDeferredPosition )
      p_deferredAxis = (float *)&model->deferredAxis;
    else
      p_deferredAxis = (float *)&model->g.axis;
    viewfwd->x = *p_deferredAxis;
    viewfwd->y = p_deferredAxis[1];
    z = p_deferredAxis[2];
  }
  else
  {
    physics = this->physics;
    if ( physics != nullptr )
    {
      v13 = (float *)physics->GetAxis(this: physics, a2: 0);
      viewfwd->x = *v13;
      viewfwd->y = v13[1];
      z = v13[2];
    }
    else
    {
      viewfwd->x = this->spawnOrientation.mat[0].x;
      viewfwd->y = this->spawnOrientation.mat[0].y;
      z = this->spawnOrientation.mat[0].z;
    }
  }
  viewfwd->z = z;
  *horzFOV = 0;
  *vertFOV = 0;
}


// ========================================================================
// ?GetRepairBotTetherPoint@idEntity@@UBA_NHHAAVidVec3@@@Z
// EA  : 0x82C3DB10
// RVA : 0x00C3DB10
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::GetRepairBotTetherPoint(
        idEntity *this,
        const int tetherPointIdx,
        const int clipMask,
        idVec3 *outPos)
{
  idBounds *v6; // r31
  double RadiusXY; // fp1
  double x; // fp8
  double y; // fp7
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  float v14[2]; // [sp+50h] [-40h] BYREF
  float v15; // [sp+58h] [-38h]

  this->GetModelTransform(this, a2: outPos, a3: (idMat3 *)v14);
  v6 = (idBounds *)this->physics->GetBounds(this: this->physics, a2: -1);
  RadiusXY = idBounds::GetRadiusXY(this: v6);
  x = outPos->x;
  y = outPos->y;
  v11 = (float)(v14[0] * (float)((float)RadiusXY * (float)2.0));
  v12 = (float)(v14[1] * (float)((float)RadiusXY * (float)2.0));
  v13 = (float)(outPos->z - (float)(v15 * (float)((float)RadiusXY * (float)2.0)));
  outPos->z = outPos->z - (float)(v15 * (float)((float)RadiusXY * (float)2.0));
  outPos->x = (float)x - (float)v11;
  outPos->y = (float)y - (float)v12;
  outPos->z = (float)(v6->b[1].z * (float)1.5) + (float)v13;
  return 1;
}


// ========================================================================
// ?InitRenderModel@idEntity@@QAAXXZ
// EA  : 0x82C3DBE8
// RVA : 0x00C3DBE8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::InitRenderModel(idEntity *this)
{
  idRenderModelInfo *v2; // r3
  idRenderModelInfo *v3; // r30
  char *data; // r29
  const char *Classname; // r3
  idPresentable *presentable; // r3

  v2 = this->GetRenderModelInfo(this);
  v3 = v2;
  if ( v2 != nullptr && v2->model != nullptr )
  {
    data = this->name.data;
    Classname = idClass::GetClassname(this);
    idRenderModelInfo::InitRenderModel(
      this: v3,
      spawnPosition: &this->spawnPosition,
      spawnOrientation: &this->spawnOrientation,
      enableStaticSpecular: (*((_BYTE *)&this->flags + 1) & 0x20) != 0,
      name: data,
      className: Classname);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->SetRenderModel(this: presentable, a2: v3->model, a3: true);
    v3->ownedByPresentable = true;
  }
}


// ========================================================================
// ?Remove@idEntity@@UAAXXZ
// EA  : 0x82C3DCA0
// RVA : 0x00C3DCA0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Remove(idEntity *this)
{
  idLinkList<idEntity> *head; // r5
  idEventArg *progressionEntity; // r4
  idEventReceiver v4[2]; // [sp+50h] [-30h] BYREF

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
  progressionEntity = (idEventArg *)this->progressionEntity;
  if ( progressionEntity != nullptr )
  {
    idEventReceiver::ProcessEvent(this: v4, result: progressionEntity, ev: &EV_NotifyProgressionOwner);
    this->progressionEntity = nullptr;
  }
}


// ========================================================================
// ?SetName@idEntity@@QAAXPBD@Z
// EA  : 0x82C3DD50
// RVA : 0x00C3DD50
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetName(idEntity *this, const char *newName)
{
  __int64 v3; // r30
  int i; // r28
  __int64 v5; // r10
  __int64 v6; // r8
  const char *EntityDefName; // r3
  va *v8; // r3
  va *v9; // r29
  size_t j; // r30
  int v11; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  va *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  int len; // r30
  int v19; // [sp+8h] [-10D8h]
  int v20; // [sp+8h] [-10D8h]
  int v21; // [sp+Ch] [-10D4h]
  int v22; // [sp+Ch] [-10D4h]
  int v23; // [sp+10h] [-10D0h]
  int v24; // [sp+10h] [-10D0h]
  int v25; // [sp+14h] [-10CCh]
  int v26; // [sp+14h] [-10CCh]
  int v27; // [sp+18h] [-10C8h]
  int v28; // [sp+18h] [-10C8h]
  int v29; // [sp+1Ch] [-10C4h]
  int v30; // [sp+1Ch] [-10C4h]
  idStr v31; // [sp+50h] [-1090h] BYREF
  idStr v32; // [sp+70h] [-1070h] BYREF
  va v33; // [sp+90h] [-1050h] BYREF

  HIDWORD(v3) = newName;
  if ( this->entityNumber == 0x1FFF )
  {
    idStr::operator=(this: &this->name, text: newName);
  }
  else
  {
    if ( *this->name.data != 0 )
    {
      idGameLocal::RemoveEntityFromHash(this: gameLocal, ent: this);
      idProgram::SetEntity(this: &gameLocal->program, name: this->name.data, ent: nullptr);
    }
    if ( *(_BYTE *)HIDWORD(v3) != 0 )
    {
      if ( gameLocal->FindEntity(this: gameLocal, a2: HIDWORD(v3)) != nullptr )
      {
        LODWORD(v12) = v31.baseBuffer;
        v31.len = 0;
        v31.allocedAndFlag = 20;
        v31.data = v31.baseBuffer;
        v31.baseBuffer[0] = 0;
        LODWORD(v3) = this->entityNumber;
        v14 = va::va(
                this: &v33,
                fmt: "%s_renamed_%d",
                a3: v3,
                a4: v13,
                a5: v12,
                a6: v19,
                a7: v21,
                a8: v23,
                a9: v25,
                a10: v27,
                a11: v29);
        idStr::operator=(this: &v31, text: v14);
        while ( gameLocal->FindEntity(this: gameLocal, a2: v31.data) != nullptr )
        {
          LODWORD(v3) = v3 + 1;
          v17 = va::va(
                  this: &v33,
                  fmt: "%s_renamed_%d",
                  a3: v3,
                  a4: v16,
                  a5: v15,
                  a6: v20,
                  a7: v22,
                  a8: v24,
                  a9: v26,
                  a10: v28,
                  a11: v30);
          idStr::operator=(this: &v31, text: v17);
        }
        idLib::Warning(
          fmt: "Multiple entities named '%s', new entity renamed to '%s'",
          (const char *)HIDWORD(v3),
          v31.data);
        len = v31.len;
        idStr::EnsureAlloced(this: &this->name, amount: v31.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: this->name.data, Src: v31.data, Size: len);
        this->name.data[len] = 0;
        this->name.len = len;
        idStr::FreeData(this: &v31);
      }
      else
      {
        idStr::operator=(this: &this->name, text: (const char *)HIDWORD(v3));
      }
    }
    else
    {
      v32.len = 0;
      v32.allocedAndFlag = 20;
      v32.data = v32.baseBuffer;
      v32.baseBuffer[0] = 0;
      for ( i = this->entityNumber; ; ++i )
      {
        if ( this->entityDef != nullptr )
          EntityDefName = idEntity::GetEntityDefName(this);
        else
          EntityDefName = idClass::GetClassname(this);
        v8 = va::va(
               this: &v33,
               fmt: "%s_%d",
               a3: __SPAIR64__((unsigned int)EntityDefName, i),
               a4: v6,
               a5: v5,
               a6: v19,
               a7: v21,
               a8: v23,
               a9: v25,
               a10: v27,
               a11: v29);
        v9 = v8;
        for ( j = 0; v8->buffer[j] != 0; ++j )
          ;
        idStr::EnsureAlloced(this: &v32, amount: j + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v32.data, Src: v9, Size: j);
        v32.data[j] = 0;
        v32.len = j;
        if ( gameLocal->FindEntity(this: gameLocal, a2: v32.data) == nullptr )
          break;
      }
      v11 = v32.len;
      idStr::EnsureAlloced(this: &this->name, amount: v32.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->name.data, Src: v32.data, Size: v11);
      this->name.data[v11] = 0;
      this->name.len = v11;
      idStr::FreeData(this: &v32);
    }
    if ( idStr::Icmp(s1: this->name.data, s2: "NULL") != 0 && idStr::Icmp(s1: this->name.data, s2: "null_entity") != 0 )
    {
      idGameLocal::AddEntityToHash(this: gameLocal, ent: this);
      idProgram::SetEntity(this: &gameLocal->program, name: this->name.data, ent: this);
    }
    else
    {
      idLib::Error(fmt: "Cannot name entity '%s'.  '%s' is reserved for script.", this->name.data, this->name.data);
      _LN122_1();
    }
  }
}


// ========================================================================
// $LN122_1
// EA  : 0x82C3E080
// RVA : 0x00C3E080
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _LN122_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 112));
}


// ========================================================================
// __unwind$499941
// EA  : 0x82C3E0A8
// RVA : 0x00C3E0A8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_499941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 80));
}


// ========================================================================
// ?UpdatePVSAreas@idEntity@@QAAXXZ
// EA  : 0x82C3E0D0
// RVA : 0x00C3E0D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdatePVSAreas(idEntity *this)
{
  idPresentable *presentable; // r11
  idBounds *v3; // r4
  idBounds v4; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    idBounds::FromTransformedBounds(
      this: &v4,
      bounds: &presentable->model->referenceBounds,
      origin: &presentable->origin,
      axis: &presentable->axis);
    v3 = &v4;
  }
  else
  {
    v3 = (idBounds *)this->physics->GetAbsBounds(this: this->physics, a2: -1);
  }
  this->numPVSAreas = idPVS::GetPVSAreas(this: &clientGame->pvs, bounds: v3, areas: this->PVSAreas, maxAreas: 4);
}


// ========================================================================
// ?BecomeActive@idEntity@@QAAXH@Z
// EA  : 0x82C3E168
// RVA : 0x00C3E168
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BecomeActive(idEntity *this, int flags)
{
  idEntity *teamMaster; // r3
  idPhysics *physics; // r11
  physicsType_t type; // r11
  bool *p_sortPushers; // r30
  bool v8; // r3
  int v9; // r8
  int v10; // r7
  int thinkFlags; // r10
  idEntity *head; // r9
  idLinkList<idEntity> *p_activeNode; // r11
  idLinkList<idEntity> *v14; // r5
  int v15; // r10
  idPresentable *presentable; // r4
  int v17; // [sp+8h] [-78h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+10h] [-70h]
  int v20; // [sp+14h] [-6Ch]
  int v21; // [sp+18h] [-68h]
  idPresentable *v22; // [sp+1Ch] [-64h]

  if ( (flags & 2) != 0 )
  {
    teamMaster = this->bindInfo.teamMaster;
    if ( teamMaster == nullptr || teamMaster == this )
    {
      if ( (this->thinkFlags & 2) == 0 )
      {
        physics = this->physics;
        if ( physics != nullptr )
        {
          type = physics->type;
          if ( type == PHYSICS_PARAMETRIC || type == PHYSICS_PLAYER )
            gameLocal->sortPushers = true;
        }
      }
    }
    else
    {
      idEntity::BecomeActive(this: teamMaster, flags: 2);
    }
  }
  p_sortPushers = &gameLocal->sortPushers;
  v8 = this->IsPusher(this);
  v9 = *p_sortPushers;
  v10 = v8;
  *p_sortPushers = v8 | v9;
  thinkFlags = this->thinkFlags;
  this->thinkFlags = thinkFlags | flags | 8;
  head = (idEntity *)this->activeNode.head;
  p_activeNode = &this->activeNode;
  if ( head == (idEntity *)&this->activeNode )
  {
    v10 = 151844;
    v14 = gameLocal->activeEntities.head;
    this->activeNode.prev->next = this->activeNode.next;
    this->activeNode.next->prev = this->activeNode.prev;
    this->activeNode.prev = &this->activeNode;
    p_activeNode->head = p_activeNode;
    this->activeNode.next = v14;
    this->activeNode.prev = v14->prev;
    v14->prev = p_activeNode;
    head = (idEntity *)this->activeNode.prev;
    head->listenerList = (idList<idEventReceiver *,5> *)p_activeNode;
    v9 = (int)v14->head;
    p_activeNode->head = v14->head;
  }
  else if ( thinkFlags == 0 )
  {
    head = (idEntity *)(gameLocal->numEntitiesToDeactivate - 1);
    gameLocal->numEntitiesToDeactivate = (int)head;
  }
  v15 = this->thinkFlags & 1;
  if ( v15 != 0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      idClientGame::MarkPresentableSerialized(
        this: clientGame,
        presentable,
        serialized: true,
        deleted: false,
        a5: v10,
        a6: v9,
        a7: (int)head,
        a8: v15,
        a9: v17,
        a10: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22);
  }
}


// ========================================================================
// ?UpdateFX@idEntity@@UAAXXZ
// EA  : 0x82C3E2F0
// RVA : 0x00C3E2F0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateFX(idEntity *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->UpdateFX_3(this: presentable, a2: 1.0, a3: 0.0);
}


// ========================================================================
// ?StopSound@idEntity@@QAAXW4soundChannel_t@@E@Z
// EA  : 0x82C3E320
// RVA : 0x00C3E320
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::StopSound(idEntity *this, soundChannel_t channel, unsigned __int8 peerMask)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    idPresentable::StopSound(this: presentable, channel, peerMask);
}


// ========================================================================
// ?UpdateSound@idEntity@@QAAXXZ
// EA  : 0x82C3E338
// RVA : 0x00C3E338
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateSound(idEntity *this)
{
  idPresentable *presentable; // r30
  idPhysics *physics; // r29
  int entityNumber; // r31
  const idVec3 *v5; // r3
  idVec3 v6; // [sp+50h] [-70h] BYREF
  char v7; // [sp+60h] [-60h] BYREF
  idMat3 v8[2]; // [sp+70h] [-50h] BYREF

  if ( this->presentable != nullptr )
  {
    this->GetSoundTransform(this, a2: &v6, a3: v8);
    presentable = this->presentable;
    physics = this->physics;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    entityNumber = this->entityNumber;
    v5 = physics->GetLinearVelocity(this: (idPhysics *)&v7, result: (idVec3 *)physics, a3: 0);
    idPresentable::UpdateSound(this: presentable, origin: &v6, axis: v8, velocity: v5, listenerId: entityNumber + 1);
  }
}


// ========================================================================
// ?FreeSoundEmitter@idEntity@@QAAX_N@Z
// EA  : 0x82C3E3C8
// RVA : 0x00C3E3C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::FreeSoundEmitter(idEntity *this, bool immediate)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    idPresentable::FreeSoundEmitter(this: presentable, immediate);
}


// ========================================================================
// ?IsPlayingSound@idEntity@@QBA_NW4soundChannel_t@@@Z
// EA  : 0x82C3E3E0
// RVA : 0x00C3E3E0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsPlayingSound(idEntity *this, soundChannel_t channel)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  return presentable != nullptr && idPresentable::IsPlayingSound(this: presentable, channel);
}


// ========================================================================
// ?GetCurrentSoundShader@idEntity@@QBAPBVidSoundShader@@W4soundChannel_t@@@Z
// EA  : 0x82C3E3F8
// RVA : 0x00C3E3F8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

const idSoundShader *__fastcall idEntity::GetCurrentSoundShader(idEntity *this, soundChannel_t channel)
{
  idPresentable *presentable; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  return idPresentable::GetCurrentSoundShader(this: presentable, channel);
}


// ========================================================================
// ?PostBind@idEntity@@UAAXXZ
// EA  : 0x82C3E450
// RVA : 0x00C3E450
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::PostBind(idEntity *this)
{
  idAnimatedEntity *v2; // r3
  idPresentable *presentable; // r11
  idRenderModel *model; // r10

  v2 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)this->bindInfo.bindMaster);
  if ( v2 != nullptr && idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v2) != nullptr )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
    {
      model = presentable->model;
      if ( model != nullptr )
        model->useDeferredPosition = false;
    }
  }
}


// ========================================================================
// ?FinishBind@idEntity@@AAAXXZ
// EA  : 0x82C3E4B8
// RVA : 0x00C3E4B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::FinishBind(idEntity *this)
{
  int v2; // r3
  int v3; // r3
  idPresentable *presentable; // r30
  idPresentable *v5; // r3

  idEntity::JoinTeam(this, teammember: this->bindInfo.bindMaster);
  v3 = *(_DWORD *)(v2 + 404);
  if ( (*(_BYTE *)(v3 + 92) & 0x80) == 0 )
    idEntity::BecomeActive(this: (idEntity *)v3, flags: 2);
  if ( (*((_BYTE *)&this->bindInfo + 112) & 0x40) != 0
    && this->presentable != nullptr
    && this->bindInfo.bindMaster->presentable != nullptr )
  {
    presentable = this->bindInfo.bindMaster->presentable;
    v5 = this->presentable;
    if ( v5 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v5 = this->presentable;
    }
    idPresentable::SetGroupMaster(this: v5, pres: presentable);
  }
}


// ========================================================================
// ?Unbind@idEntity@@QAAXXZ
// EA  : 0x82C3E578
// RVA : 0x00C3E578
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Unbind(idEntity *this)
{
  idPhysics *physics; // r3
  idEntity *teamMaster; // r8
  idEntity *i; // r11
  idEntity *teamChain; // r11
  idEntity *j; // r9
  idEntity *bindMaster; // r10
  char v8; // r10
  int p_teamChain; // r10
  idEntity *v10; // r9
  int v11; // r8
  idEntity *v12; // r11
  idPresentable *presentable; // r3

  if ( this->bindInfo.bindMaster != nullptr )
  {
    if ( this->bindInfo.teamMaster != nullptr )
    {
      this->PreUnbind(this);
      physics = this->physics;
      if ( physics != nullptr )
        physics->SetMaster(
          this: physics,
          a2: false,
          a3: &vec3_origin,
          a4: &mat3_identity,
          a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
      teamMaster = this->bindInfo.teamMaster;
      for ( i = teamMaster->bindInfo.teamChain; i != nullptr; i = i->bindInfo.teamChain )
      {
        if ( i == this )
          break;
        teamMaster = i;
      }
      teamChain = this->bindInfo.teamChain;
      for ( j = this; teamChain != nullptr; teamChain = teamChain->bindInfo.teamChain )
      {
        bindMaster = teamChain->bindInfo.bindMaster;
        if ( bindMaster != nullptr )
        {
          while ( bindMaster != this )
          {
            bindMaster = bindMaster->bindInfo.bindMaster;
            if ( bindMaster == nullptr )
              goto LABEL_13;
          }
          v8 = 1;
        }
        else
        {
LABEL_13:
          v8 = 0;
        }
        if ( v8 == 0 )
          break;
        teamChain->bindInfo.teamMaster = this;
        j = teamChain;
      }
      j->bindInfo.teamChain = nullptr;
      if ( this->bindInfo.teamMaster == this )
      {
        if ( teamChain != nullptr )
        {
          p_teamChain = (int)&teamChain->bindInfo.teamChain;
          v10 = teamChain;
          if ( teamChain->bindInfo.teamChain != nullptr )
          {
            do
            {
              v10->bindInfo.teamMaster = teamChain;
              v10 = *(idEntity **)p_teamChain;
              v11 = *(_DWORD *)(*(_DWORD *)p_teamChain + 408);
              p_teamChain = *(_DWORD *)p_teamChain + 408;
            }
            while ( v11 != 0 );
          }
          teamChain->bindInfo.teamMaster = teamChain;
        }
      }
      else
      {
        teamMaster->bindInfo.teamChain = teamChain;
        if ( teamChain == nullptr && this->bindInfo.teamMaster == teamMaster )
          teamMaster->bindInfo.teamMaster = nullptr;
      }
      v12 = this->bindInfo.teamChain;
      presentable = this->presentable;
      this->bindInfo.bindJoint.value = -1;
      this->bindInfo.teamMaster = v12 == nullptr ? nullptr : this;
      LOWORD(v12) = NULL_JOINT;
      this->bindInfo.bindMaster = nullptr;
      this->bindInfo.bindTag.parentJoint.value = (unsigned __int16)v12;
      if ( presentable != nullptr )
        idPresentable::SetGroupMaster(this: presentable, pres: nullptr);
      this->PostUnbind(this);
    }
    else
    {
      this->bindInfo.bindMaster = nullptr;
    }
  }
}


// ========================================================================
// ?RemoveBinds@idEntity@@AAAXXZ
// EA  : 0x82C3E768
// RVA : 0x00C3E768
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RemoveBinds(idEntity *this)
{
  idEntity *teamChain; // r31
  idEntity *bindMaster; // r10
  idEntity *v4; // r11
  idPhysics *physics; // r3
  idEntity *teamMaster; // r8
  idEntity *i; // r11
  idEntity *v8; // r11
  idEntity *j; // r9
  idEntity *v10; // r10
  char v11; // r10
  int p_teamChain; // r10
  _DWORD *v13; // r9
  int v14; // r8
  idEntity *v15; // r11
  idPresentable *presentable; // r3

  teamChain = this->bindInfo.teamChain;
  if ( teamChain != nullptr )
  {
    do
    {
      bindMaster = teamChain->bindInfo.bindMaster;
      v4 = teamChain->bindInfo.teamChain;
      if ( bindMaster == this )
      {
        if ( bindMaster != nullptr )
        {
          if ( teamChain->bindInfo.teamMaster != nullptr )
          {
            teamChain->PreUnbind(this: teamChain);
            physics = teamChain->physics;
            if ( physics != nullptr )
              physics->SetMaster(
                this: physics,
                a2: false,
                a3: &vec3_origin,
                a4: &mat3_identity,
                a5: (const bindFlags_t)((*((_BYTE *)&teamChain->bindInfo + 112) & 0x80) != 0));
            teamMaster = teamChain->bindInfo.teamMaster;
            for ( i = teamMaster->bindInfo.teamChain; i != nullptr; i = i->bindInfo.teamChain )
            {
              if ( i == teamChain )
                break;
              teamMaster = i;
            }
            v8 = teamChain->bindInfo.teamChain;
            for ( j = teamChain; v8 != nullptr; v8 = v8->bindInfo.teamChain )
            {
              v10 = v8->bindInfo.bindMaster;
              if ( v10 != nullptr )
              {
                while ( v10 != teamChain )
                {
                  v10 = v10->bindInfo.bindMaster;
                  if ( v10 == nullptr )
                    goto LABEL_15;
                }
                v11 = 1;
              }
              else
              {
LABEL_15:
                v11 = 0;
              }
              if ( v11 == 0 )
                break;
              v8->bindInfo.teamMaster = teamChain;
              j = v8;
            }
            j->bindInfo.teamChain = nullptr;
            if ( teamChain->bindInfo.teamMaster == teamChain )
            {
              if ( v8 != nullptr )
              {
                p_teamChain = (int)&v8->bindInfo.teamChain;
                v13 = &v8->__vftable;
                if ( v8->bindInfo.teamChain != nullptr )
                {
                  do
                  {
                    v13[101] = v8;
                    v13 = *(_DWORD **)p_teamChain;
                    v14 = *(_DWORD *)(*(_DWORD *)p_teamChain + 408);
                    p_teamChain = *(_DWORD *)p_teamChain + 408;
                  }
                  while ( v14 != 0 );
                }
                v8->bindInfo.teamMaster = v8;
              }
            }
            else
            {
              teamMaster->bindInfo.teamChain = v8;
              if ( v8 == nullptr && teamChain->bindInfo.teamMaster == teamMaster )
                teamMaster->bindInfo.teamMaster = nullptr;
            }
            v15 = teamChain->bindInfo.teamChain;
            presentable = teamChain->presentable;
            teamChain->bindInfo.bindJoint.value = -1;
            teamChain->bindInfo.teamMaster = v15 == nullptr ? nullptr : teamChain;
            LOWORD(v15) = NULL_JOINT;
            teamChain->bindInfo.bindMaster = nullptr;
            teamChain->bindInfo.bindTag.parentJoint.value = (unsigned __int16)v15;
            if ( presentable != nullptr )
              idPresentable::SetGroupMaster(this: presentable, pres: nullptr);
            teamChain->PostUnbind(this: teamChain);
          }
          else
          {
            teamChain->bindInfo.bindMaster = nullptr;
          }
        }
        idEventReceiver::PostEventMS(this: teamChain, ev: &EV_Remove, time: 0);
        v4 = this->bindInfo.teamChain;
      }
      teamChain = v4;
    }
    while ( v4 != nullptr );
  }
}


// ========================================================================
// ?GetMasterPosition@idEntity@@QBA_NAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C3E980
// RVA : 0x00C3E980
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::GetMasterPosition(idEntity *this, idVec3 *masterOrigin, idMat3 *masterAxis)
{
  idEntity *bindMaster; // r29
  idAnimatedEntity *v7; // r29
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v9; // r3
  idPresentable *v10; // r29
  idTreeAnimator *TreeAnimator; // r27
  idAnimatedEntity *v13; // r3
  idEntity *v14; // r29
  idPresentable *v15; // r11
  idRenderModel *model; // r3
  idTreeAnimator *v17; // r3
  idPresentable *v18; // r3
  idPresentableAnimatedEntity *v19; // r3
  idPresentable *v20; // r29
  idTreeAnimator *v21; // r27
  idVec3 *v22; // r11
  idEntity *v23; // r30
  float *v24; // r11
  float *v25; // r3
  float *v26; // r3

  bindMaster = this->bindInfo.bindMaster;
  if ( bindMaster == nullptr )
  {
LABEL_25:
    *masterOrigin = vec3_origin;
    *masterAxis = mat3_identity;
    return 0;
  }
  if ( (unsigned __int16)this->bindInfo.bindJoint.value != 0xFFFF )
  {
    v7 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)this->bindInfo.bindMaster);
    presentable = v7->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v7);
      presentable = v7->presentable;
    }
    v9 = presentable->GetAnimatedEntityInterface(this: presentable);
    v10 = v9;
    if ( v9 != nullptr )
    {
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v9);
      idPresentable::UpdateModelTransform(this: v10);
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: TreeAnimator,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->bindInfo.bindJoint.value,
        origin: masterOrigin,
        axis: masterAxis);
      return 1;
    }
    goto LABEL_25;
  }
  if ( this->bindInfo.bindTag.parentJoint.value == 0xFFFF )
  {
    v22 = (idVec3 *)bindMaster->presentable;
    if ( v22 != nullptr )
    {
      *masterOrigin = v22[10];
      v23 = this->bindInfo.bindMaster;
      v24 = (float *)v23->presentable;
      if ( v24 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->bindInfo.bindMaster);
        v24 = (float *)v23->presentable;
      }
      masterAxis->mat[0].x = v24[33];
      masterAxis->mat[0].y = v24[34];
      masterAxis->mat[0].z = v24[35];
      masterAxis->mat[1].x = v24[36];
      masterAxis->mat[1].y = v24[37];
      masterAxis->mat[1].z = v24[38];
      masterAxis->mat[2].x = v24[39];
      masterAxis->mat[2].y = v24[40];
      masterAxis->mat[2].z = v24[41];
      return 1;
    }
    else
    {
      v25 = (float *)bindMaster->physics->GetOrigin(this: bindMaster->physics, a2: 0);
      masterOrigin->x = *v25;
      masterOrigin->y = v25[1];
      masterOrigin->z = v25[2];
      v26 = (float *)this->bindInfo.bindMaster->physics->GetAxis(this: this->bindInfo.bindMaster->physics, a2: 0);
      masterAxis->mat[0].x = *v26;
      masterAxis->mat[0].y = v26[1];
      masterAxis->mat[0].z = v26[2];
      masterAxis->mat[1].x = v26[3];
      masterAxis->mat[1].y = v26[4];
      masterAxis->mat[1].z = v26[5];
      masterAxis->mat[2].x = v26[6];
      masterAxis->mat[2].y = v26[7];
      masterAxis->mat[2].z = v26[8];
      return 1;
    }
  }
  else
  {
    v13 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)this->bindInfo.bindMaster);
    v14 = v13;
    if ( v13 != nullptr )
    {
      v18 = v13->presentable;
      if ( v18 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v14);
        v18 = v14->presentable;
      }
      v19 = v18->GetAnimatedEntityInterface(this: v18);
      v20 = v19;
      if ( v19 != nullptr )
      {
        v21 = idPresentableAnimatedEntity::GetTreeAnimator(this: v19);
        idPresentable::UpdateModelTransform(this: v20);
        idTreeAnimator::GetWorldSpaceTagTransform(
          this: v21,
          tagData: &this->bindInfo.bindTag,
          origin: masterOrigin,
          axis: masterAxis);
        return 1;
      }
      goto LABEL_25;
    }
    v15 = this->bindInfo.bindMaster->presentable;
    if ( v15 != nullptr )
      model = v15->model;
    else
      model = nullptr;
    if ( model != nullptr
      && (v17 = (idTreeAnimator *)_RTDynamicCast(
                                    inptr: model,
                                    VfDelta: 0,
                                    SrcType: &idRenderModel `RTTI Type Descriptor',
                                    TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                    isReference: 0)) != nullptr )
    {
      idTreeAnimator::GetWorldSpaceTagTransform(
        this: v17,
        tagData: &this->bindInfo.bindTag,
        origin: masterOrigin,
        axis: masterAxis);
      return 1;
    }
    else
    {
      *masterOrigin = vec3_origin;
      *masterAxis = mat3_identity;
      return 1;
    }
  }
}


// ========================================================================
// ?CreateMoveableClipModel@idEntity@@QAAPAVidClipModel@@_NM@Z
// EA  : 0x82C3ED50
// RVA : 0x00C3ED50
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idClipModel *__fastcall idEntity::CreateMoveableClipModel(idEntity *this, bool barrelCollision, double overrideRadius)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r30
  idRenderModelInfo *(__fastcall *GetRenderModelInfo)(idEntity *); // ctr
  const char *v9; // r7
  idRenderModelInfo *v10; // r3
  idVec3 v12[2]; // [sp+50h] [-40h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    model = presentable->model;
  else
    model = nullptr;
  GetRenderModelInfo = this->GetRenderModelInfo;
  v12[0] = vec3_origin;
  v10 = GetRenderModelInfo(this);
  if ( v10 != nullptr )
    idRenderModelInfo::GetScale(this: v10, out: v12);
  return idPresentable::CreateMoveableClipModel(
           clipModelInfo: &this->clipModelInfo,
           renderModel: model,
           renderModelScale: v12,
           barrelCollision,
           overrideRadius,
           debugName: v9,
           a7: this->name.data);
}


// ========================================================================
// ?SetPhysics@idEntity@@QAAXPAVidPhysics@@@Z
// EA  : 0x82C3EDF0
// RVA : 0x00C3EDF0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetPhysics(idEntity *this, idPhysics *phys, int a3)
{
  idPhysics *physics; // r3
  int GameMs; // r3
  idVec3 v7; // [sp+50h] [-50h] BYREF
  idMat3 v8; // [sp+60h] [-40h] BYREF

  physics = this->physics;
  if ( physics != nullptr )
    physics->ClearContacts(this: physics);
  if ( phys != nullptr )
  {
    ((void (__fastcall *)(idPhysics_Static *, _DWORD, int, _DWORD, int, double))this->defaultPhysicsObj.SetClipModel)(
      a1: &this->defaultPhysicsObj,
      a2: 0,
      a3,
      a4: 0,
      a5: 1,
      a6: 1.0);
    this->physics = phys;
    phys->Activate(this: phys);
  }
  else
  {
    this->physics = &this->defaultPhysicsObj;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->physics->UpdateTime(this: this->physics, a2: GameMs);
  idEntity::GetMasterPosition(this, masterOrigin: &v7, masterAxis: &v8);
  this->physics->SetMaster(
    this: this->physics,
    a2: this->bindInfo.bindMaster != nullptr,
    a3: &v7,
    a4: &v8,
    a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
}


// ========================================================================
// ?ActivatePhysics@idEntity@@UAAXH@Z
// EA  : 0x82C3EF10
// RVA : 0x00C3EF10
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ActivatePhysics(idEntity *this, int physId)
{
  ((void (__fastcall *)(idPhysics *, int))this->physics->Activate)(a1: this->physics, a2: physId);
  idEntity::BecomeActive(this, flags: 2);
}


// ========================================================================
// ?DeconstructScriptObject@idEntity@@QAAXXZ
// EA  : 0x82C3EF60
// RVA : 0x00C3EF60
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::DeconstructScriptObject(idEntity *this)
{
  const function_t *Destructor; // r28
  idThread *v3; // r3
  idThread *v4; // r30
  int v5; // r27
  int v6; // r30
  idSSObject **list; // r10
  idSSObject **v8; // r4

  if ( idGameLocal::GameState(this: gameLocal) != GAMESTATE_SHUTDOWN )
  {
    Destructor = idScriptObject::GetDestructor(this: &this->scriptObject);
    if ( Destructor != nullptr )
    {
      v3 = (idThread *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x1B94u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      v4 = v3 != nullptr ? idThread::idThread(this: v3) : nullptr;
      idThread::SetThreadName(this: v4, name: this->name.data);
      idThread::CallObjectFunction(this: v4, self: this, func: Destructor, clearStack: true);
      this->ExecuteThread(this, a2: v4);
      if ( v4 != nullptr )
        ((void (__fastcall *)(idThread *, int))v4->dtr_idClass)(a1: v4, a2: 1);
    }
    v5 = 0;
    if ( this->superScriptObjects.num > 0 )
    {
      v6 = 0;
      do
      {
        list = this->superScriptObjects.list;
        if ( list[v6] != nullptr )
        {
          idSuperScriptSystem::DestroyObject(this: &gameLocal->superScript, object: list[v6]);
          this->superScriptObjects.list[v6] = nullptr;
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->superScriptObjects.num );
    }
    if ( this->superScriptObjects.listStatic == 0 || this->superScriptObjects.listStatic == 2 )
    {
      v8 = this->superScriptObjects.list;
      if ( v8 != nullptr )
        idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
      this->superScriptObjects.list = nullptr;
      this->superScriptObjects.size = 0;
    }
    this->superScriptObjects.num = 0;
  }
}


// ========================================================================
// __unwind$500789
// EA  : 0x82C3F0DC
// RVA : 0x00C3F0DC
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall _unwind_500789(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?Signal@idEntity@@QAAXW4signalNum_t@@@Z
// EA  : 0x82C3F108
// RVA : 0x00C3F108
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Signal(idEntity *this, signalNum_t signalnum)
{
  signalList_t *signals; // r9
  _DWORD *v4; // r11
  int i; // ctr
  idList<signal_t,5> *v6; // r31
  int num; // r29
  signal_t *list; // r8
  int v9; // r11
  int v10; // r10
  _DWORD *v11; // r6
  int value; // r5
  const function_t *function; // r4
  int v14; // r27
  const function_t **v15; // r30
  idThread *Thread; // r3
  idThread *v17; // r31
  _BYTE v18[12]; // [sp+48h] [-C8h] BYREF
  char v19; // [sp+54h] [-BCh] BYREF

  signals = this->signals;
  if ( signals != nullptr )
  {
    v4 = v18;
    for ( i = 16; i != 0; --i )
    {
      v4 += 2;
      *v4 = 0;
    }
    v6 = &signals->signal[signalnum];
    num = v6->num;
    if ( num > 0 )
    {
      list = v6->list;
      v9 = 0;
      v10 = v6->num;
      do
      {
        --v10;
        v11 = &v18[v9 * 8 + 8];
        value = list[v9].threadHandle.value;
        function = list[v9++].function;
        *v11 = value;
        v11[1] = function;
      }
      while ( v10 != 0 );
    }
    if ( v6->listStatic == 0 || v6->listStatic == 2 )
    {
      if ( v6->list != nullptr )
        idMem::Free(this: &mem, ptr: v6->list, align: ALIGN_16);
      v6->list = nullptr;
      v6->size = 0;
    }
    v6->num = 0;
    if ( num > 0 )
    {
      v14 = num;
      v15 = (const function_t **)&v19;
      do
      {
        Thread = idThreadManager::GetThread(
                   this: &gameLocal->program.threadManager,
                   threadHandle: (const idHandle<int,enum invalidThreadHandle_t,0> *)*(v15 - 1));
        v17 = Thread;
        if ( Thread != nullptr )
        {
          idThread::CallObjectFunction(this: Thread, self: this, func: *v15, clearStack: true);
          this->ExecuteThread(this, a2: v17);
        }
        --v14;
        v15 += 2;
      }
      while ( v14 != 0 );
    }
  }
}


// ========================================================================
// ?RemoveTargetIndex@idEntity@@QAAXH@Z
// EA  : 0x82C3F238
// RVA : 0x00C3F238
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RemoveTargetIndex(idEntity *this, int i)
{
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
    this: (idList<idEntityPtr<idEntity>,58> *)&this->targets,
    index: i);
}


// ========================================================================
// ?UntouchTrigger@idEntity@@QAAXPAV1@@Z
// EA  : 0x82C3F240
// RVA : 0x00C3F240
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UntouchTrigger(idEntity *this, idEventArg *trigger)
{
  idList<idEntityPtr<idEntity>,5> *v4; // r3
  idList<idEntityPtr<idEntity>,5> *v5; // r31
  int v6; // r29
  int v7; // r30
  idGameLocal *v8; // r10
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEventArg *v12; // r3
  int num; // r11
  int v14; // r11
  idEventArg v15; // [sp+90h] [-70h] BYREF
  idEventReceiver v16[6]; // [sp+B0h] [-50h] BYREF

  v4 = this->GetTriggerTouchList_2(this);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = 0;
    if ( v4->num > 0 )
    {
      v7 = 0;
      v8 = gameLocal;
      while ( 1 )
      {
        value = v5->list[v7].spawnId.value;
        if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v10 = v8->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v11 = idEntity::CastTo(c: v10);
          v8 = gameLocal;
        }
        else
        {
          v11 = nullptr;
        }
        if ( v11 == (idEntity *)trigger )
          break;
        ++v6;
        ++v7;
        if ( v6 >= v5->num )
          return;
      }
      (*(void (__fastcall **)(_DWORD, _DWORD))(**(_DWORD **)&trigger[34].type + 8))(
        a1: *(_DWORD *)&trigger[34].type,
        a2: 0);
      v12 = idEventArg::idEventArg(this: &v15, data: this);
      idEventReceiver::ProcessEvent(
        this: v16,
        result: trigger,
        ev: *(const idEventDef **)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v12->value.v[2]));
      if ( v6 >= 0 )
      {
        num = v5->num;
        if ( v6 < num )
        {
          v14 = num - 1;
          v5->num = v14;
          if ( v6 != v14 )
            v5->list[v6].spawnId.value = v5->list[v14].spawnId.value;
        }
      }
    }
  }
}


// ========================================================================
// ?Event_SetName@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C3F3B0
// RVA : 0x00C3F3B0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetName(idEntity *this, idEntity *result, const char *newName)
{
  idEntity::SetName(this: result, newName);
  return this;
}


// ========================================================================
// ?Event_NumTargets@idEntity@@AAA?AVeventFloat@@XZ
// EA  : 0x82C3F3E8
// RVA : 0x00C3F3E8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_NumTargets(
        idEntity *this,
        eventFloat *result,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  LODWORD(a7) = result[25];
  eventFloat::eventFloat((eventFloat *)this, f: (float)a7);
  return this;
}


// ========================================================================
// ?Event_GetTarget@idEntity@@AAA?AVeventEntity@@M@Z
// EA  : 0x82C3F430
// RVA : 0x00C3F430
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetTarget(idEntity *this, eventEntity *result, double index)
{
  int v3; // r11
  int v5; // r9
  idEntity *v6; // r3
  idEntity *v7; // r4

  v3 = (int)index;
  if ( (int)index >= 0
    && v3 < (int)result[25].value
    && (v5 = *((_DWORD *)&result[24].value->__vftable + v3), gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13)
    && (v6 = gameLocal->entities.ptr[(int)*(&result[24].value->__vftable + v3) & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v7);
  return this;
}


// ========================================================================
// ?Event_RemoveBinds@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3F4D8
// RVA : 0x00C3F4D8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RemoveBinds(idEntity *this, idEntity *result)
{
  idEntity::RemoveBinds(this: result);
  return this;
}


// ========================================================================
// ?Event_Unbind@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C3F510
// RVA : 0x00C3F510
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Unbind(idEntity *this, idEntity *result)
{
  idEntity::Unbind(this: result);
  return this;
}


// ========================================================================
// ?Event_StopSound@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@H@Z
// EA  : 0x82C3F548
// RVA : 0x00C3F548
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_StopSound(idEntity *this, eventVoid *result, soundChannel_t channel, int netSync)
{
  idPresentable *v5; // r3

  v5 = *(idPresentable **)&result[488];
  if ( v5 != nullptr )
    idPresentable::StopSound(this: v5, channel, peerMask: (netSync == 0) - 1);
  return this;
}


// ========================================================================
// ?Event_FadeSound@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@MM@Z
// EA  : 0x82C3F598
// RVA : 0x00C3F598
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_FadeSound(
        idEntity *this,
        eventVoid *result,
        soundChannel_t channel,
        double to,
        double over)
{
  idPresentable *v6; // r3

  v6 = *(idPresentable **)&result[488];
  if ( v6 != nullptr )
    idPresentable::FadeSound(this: v6, channel, to, over);
  return this;
}


// ========================================================================
// ?Event_FadePitch@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@MM@Z
// EA  : 0x82C3F5D8
// RVA : 0x00C3F5D8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_FadePitch(
        idEntity *this,
        eventVoid *result,
        soundChannel_t channel,
        double to,
        double over)
{
  idPresentable *v6; // r3

  v6 = *(idPresentable **)&result[488];
  if ( v6 != nullptr )
    idPresentable::FadePitch(this: v6, channel, to, over);
  return this;
}


// ========================================================================
// ?AnimEvent_ForceVoiceOver@idEntity@@AAA?AVeventVoid@@PBVidMD6Anim@@PBDM@Z
// EA  : 0x82C3F620
// RVA : 0x00C3F620
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::AnimEvent_ForceVoiceOver(
        idEntity *this,
        const idEntity *result,
        const idMD6Anim *animHandle,
        const char *text,
        double duration)
{
  idStr v9; // [sp+60h] [-50h] BYREF

  idStr::idStr(this: &v9, text);
  idGameLocal::ForceVoiceOver(
    this: gameLocal,
    whoStartedMe: result,
    target: nullptr,
    text: &v9,
    duration: (int)(float)((float)1000.0 * (float)duration));
  idStr::FreeData(this: &v9);
  return this;
}


// ========================================================================
// __unwind$501225
// EA  : 0x82C3F694
// RVA : 0x00C3F694
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_501225()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Event_AngleTo@idEntity@@AAA?AVeventFloat@@PAV1@@Z
// EA  : 0x82C3F6C0
// RVA : 0x00C3F6C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_AngleTo(idEntity *this, idEntity *result, idEntity *ent)
{
  int v7; // r3
  idPhysics *physics; // r9
  float *v9; // r30
  float *v10; // r3
  float v11; // r11
  double roll; // fp0
  double yaw; // fp13
  double pitch; // fp12
  char *v15; // r10
  _DWORD *v16; // r11
  int i; // ctr
  idAngles v18; // [sp+50h] [-70h] BYREF
  idVec3 v19; // [sp+60h] [-60h] BYREF
  char v20; // [sp+6Ch] [-54h] BYREF
  float v21; // [sp+70h] [-50h]
  float v22; // [sp+74h] [-4Ch]
  float v23; // [sp+78h] [-48h]
  float v24; // [sp+7Ch] [-44h]
  float v25; // [sp+80h] [-40h]
  float v26; // [sp+84h] [-3Ch]
  float v27; // [sp+88h] [-38h]
  float v28; // [sp+8Ch] [-34h]
  float v29; // [sp+90h] [-30h]

  if ( ent != nullptr )
  {
    v7 = (int)result->physics->GetOrigin(this: result->physics, a2: 0);
    physics = ent->physics;
    v9 = (float *)v7;
    v10 = (float *)physics->GetOrigin(this: physics, a2: 0);
    v11 = *(float *)&result->presentable;
    roll = (float)(v10[2] - v9[2]);
    yaw = (float)(v10[1] - v9[1]);
    pitch = (float)(*v10 - *v9);
    v18.pitch = *v10 - *v9;
    v18.roll = roll;
    v18.yaw = yaw;
    if ( v11 == 0.0 )
    {
      idEntity::InitPresentableInternal(this: result);
      v11 = *(float *)&result->presentable;
      roll = v18.roll;
      yaw = v18.yaw;
      pitch = v18.pitch;
    }
    v15 = &v20;
    v16 = (_DWORD *)(LODWORD(v11) + 128);
    for ( i = 9; i != 0; --i )
    {
      ++v16;
      v15 += 4;
      *(_DWORD *)v15 = *v16;
    }
    v18.yaw = (float)(v25 * (float)yaw) + (float)((float)((float)roll * v26) + (float)(v24 * (float)pitch));
    v18.roll = (float)(v28 * (float)yaw) + (float)((float)(v29 * (float)roll) + (float)(v27 * (float)pitch));
    v18.pitch = (float)(v22 * (float)yaw) + (float)((float)(v21 * (float)pitch) + (float)((float)roll * v23));
    idVec3::ToAngles(this: &v19, result: &v18);
    eventFloat::eventFloat((eventFloat *)this, f: v19.y);
    return this;
  }
  else
  {
    eventFloat::eventFloat((eventFloat *)this, f: 0.0);
    return this;
  }
}


// ========================================================================
// ?Event_GetScriptObjectFloat@idEntity@@AAA?AVeventFloat@@PBD@Z
// EA  : 0x82C3F818
// RVA : 0x00C3F818
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetScriptObjectFloat(idEntity *this, eventFloat *result, const char *name)
{
  double v4; // fp1
  idScriptVariableBase<float,4,float> v6; // [sp+50h] [-20h] BYREF

  v6.object = nullptr;
  v6.offset = 0;
  idScriptVariableBase<float,4,float>::LinkTo(this: &v6, obj: (idScriptObject *)&result[118], name);
  if ( v6.object != nullptr )
    v4 = *(float *)&v6.object->data[v6.offset];
  else
    v4 = 0.0;
  eventFloat::eventFloat((eventFloat *)this, f: v4);
  return this;
}


// ========================================================================
// ?Event_GetScriptObjectBool@idEntity@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82C3F888
// RVA : 0x00C3F888
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetScriptObjectBool(idEntity *this, eventBool *result, const char *name)
{
  int v4; // r11
  idScriptVariableBase<int,5,int> v6; // [sp+50h] [-20h] BYREF

  v6.object = nullptr;
  v6.offset = 0;
  idScriptVariableBase<int,5,int>::LinkTo(this: &v6, obj: (idScriptObject *)&result[472], name);
  if ( v6.object != nullptr )
    v4 = *(_DWORD *)&v6.object->data[v6.offset];
  else
    v4 = 0;
  eventBool::eventBool((eventBool *)this, b: v4 != 0);
  return this;
}


// ========================================================================
// ?Event_GetScriptObjectString@idEntity@@AAA?AVeventString@@PBD@Z
// EA  : 0x82C3F908
// RVA : 0x00C3F908
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetScriptObjectString(idEntity *this, eventString *result, const char *name)
{
  const char *v4; // r4
  idScriptVariableBase<char const *,3,char const *> v6; // [sp+50h] [-20h] BYREF

  v6.object = nullptr;
  v6.offset = 0;
  idScriptVariableBase<char const *,3,char const *>::LinkTo(this: &v6, obj: (idScriptObject *)&result[118], name);
  if ( v6.object != nullptr )
    v4 = (const char *)&v6.object->data[v6.offset];
  else
    v4 = nullptr;
  eventString::eventString((eventString *)this, s: v4);
  return this;
}


// ========================================================================
// ?Event_SetScriptObject@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C3F980
// RVA : 0x00C3F980
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetScriptObject(idEntity *this, idEntity *result, const char *name)
{
  idEntity::DeconstructScriptObject(this: result);
  idScriptObject::SetType(this: &result->scriptObject, typeName: name, clear: true);
  idEntity::ConstructScriptObject(this: result);
  return this;
}


// ========================================================================
// ?GetStimulusScale@idEntity@@QBAMXZ
// EA  : 0x82C3F9C8
// RVA : 0x00C3F9C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

float __fastcall idEntity::GetStimulusScale(idEntity *this)
{
  const idList<idEntityPtr<idEntity>,5> *v1; // r3
  const idList<idEntityPtr<idEntity>,5> *v2; // r30
  double v3; // fp1
  double v4; // fp31
  int v5; // r28
  int v6; // r31
  int value; // r9
  idEntity *v8; // r3
  idPerceptionVolume *v9; // r3
  idPerceptionVolume *v10; // r3

  v1 = this->GetTriggerTouchList(this);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v4 = 1.0;
    v5 = 0;
    if ( v1->num > 0 )
    {
      v6 = 0;
      do
      {
        value = v2->list[v6].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v9 = (idPerceptionVolume *)idEntity::CastTo(c: v8);
        }
        else
        {
          v9 = nullptr;
        }
        v10 = idPerceptionVolume::CastTo(c: v9);
        if ( v10 != nullptr )
          v4 = (float)(v10->scale * (float)v4);
        ++v5;
        ++v6;
      }
      while ( v5 < v2->num );
    }
    v3 = v4;
  }
  else
  {
    v3 = 1.0;
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetStimulusDistanceScale@idEntity@@QBAMXZ
// EA  : 0x82C3FAA8
// RVA : 0x00C3FAA8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

float __fastcall idEntity::GetStimulusDistanceScale(idEntity *this)
{
  const idList<idEntityPtr<idEntity>,5> *v1; // r3
  const idList<idEntityPtr<idEntity>,5> *v2; // r30
  double v3; // fp1
  double v4; // fp31
  int v5; // r28
  int v6; // r31
  int value; // r9
  idEntity *v8; // r3
  idPerceptionVolume *v9; // r3
  idPerceptionVolume *v10; // r3

  v1 = this->GetTriggerTouchList(this);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v4 = 1.0;
    if ( ai_enableSenseVolumes.valueInteger != 0 )
    {
      v5 = 0;
      if ( v1->num > 0 )
      {
        v6 = 0;
        do
        {
          value = v2->list[v6].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v9 = (idPerceptionVolume *)idEntity::CastTo(c: v8);
          }
          else
          {
            v9 = nullptr;
          }
          v10 = idPerceptionVolume::CastTo(c: v9);
          if ( v10 != nullptr )
            v4 = (float)(v10->distanceScale * (float)v4);
          ++v5;
          ++v6;
        }
        while ( v5 < v2->num );
      }
    }
    v3 = v4;
  }
  else
  {
    v3 = 1.0;
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetLocationCallingVO@idEntity@@QBAPBVidDeclVoiceOver@@PBVidAI2@@@Z
// EA  : 0x82C3FBA0
// RVA : 0x00C3FBA0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

const idDeclVoiceOver *__fastcall idEntity::GetLocationCallingVO(idEntity *this, idAI2 *caller)
{
  const idList<idEntityPtr<idEntity>,5> *v4; // r3
  const idList<idEntityPtr<idEntity>,5> *v5; // r29
  int v6; // r27
  int i; // r30
  int value; // r9
  idEntity *v9; // r3
  idVolume_LocationCalling *v10; // r3
  idVolume_LocationCalling *v11; // r31
  idEncounterGroup *EncounterGroup; // r3

  if ( caller->IsDead(this: caller) )
    return nullptr;
  v4 = this->GetTriggerTouchList(this);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  v6 = 0;
  if ( v4->num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    value = v5->list[i].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = (idVolume_LocationCalling *)idEntity::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    v11 = idVolume_LocationCalling::CastTo(c: v10);
    if ( v11 != nullptr && idAI2::GetEncounterGroup(this: caller) != nullptr )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: caller);
      if ( idStr::Cmp(s1: v11->groupName.data, s2: EncounterGroup->groupName.data) == 0 )
        break;
    }
    if ( ++v6 >= v5->num )
      return nullptr;
  }
  return v11->locationVo;
}


// ========================================================================
// ?GetLocationCallingSS@idEntity@@QBAPBVidSoundShader@@PBVidAI2@@@Z
// EA  : 0x82C3FCC0
// RVA : 0x00C3FCC0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

const idSoundShader *__fastcall idEntity::GetLocationCallingSS(idEntity *this, idAI2 *caller)
{
  const idList<idEntityPtr<idEntity>,5> *v4; // r3
  const idList<idEntityPtr<idEntity>,5> *v5; // r29
  int v6; // r27
  int i; // r30
  int value; // r9
  idEntity *v9; // r3
  idVolume_LocationCalling *v10; // r3
  idVolume_LocationCalling *v11; // r31
  idEncounterGroup *EncounterGroup; // r3

  if ( caller->IsDead(this: caller) )
    return nullptr;
  v4 = this->GetTriggerTouchList(this);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  v6 = 0;
  if ( v4->num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    value = v5->list[i].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = (idVolume_LocationCalling *)idEntity::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    v11 = idVolume_LocationCalling::CastTo(c: v10);
    if ( v11 != nullptr && idAI2::GetEncounterGroup(this: caller) != nullptr )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: caller);
      if ( idStr::Cmp(s1: v11->groupName.data, s2: EncounterGroup->groupName.data) == 0 )
        break;
    }
    if ( ++v6 >= v5->num )
      return nullptr;
  }
  return v11->locationSs;
}


// ========================================================================
// ?Event_SignalEvent@idEntity@@AAA?AVeventVoid@@W4signalNum_t@@@Z
// EA  : 0x82C3FDE0
// RVA : 0x00C3FDE0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SignalEvent(idEntity *this, idEntity *result, signalNum_t signal)
{
  idEntity::Signal(this: result, signalnum: signal);
  return this;
}


// ========================================================================
// ?ClientThink@idEntity@@UAAXXZ
// EA  : 0x82C3FE18
// RVA : 0x00C3FE18
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ClientThink(idEntity *this)
{
  idPresentable *presentable; // r31
  idPresentable_vtbl *v2; // r30
  double pct; // fp31
  const netInterpolationInfo_t *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->__vftable;
    pct = gameLocal->GetInterpolationInfo(this: gameLocal)->pct;
    v4 = gameLocal->GetInterpolationInfo(this: gameLocal);
    ((void (__fastcall *)(idPresentable *, int, double))v2->ClientThink)(a1: presentable, a2: v4->serverGameMs, a3: pct);
  }
}


// ========================================================================
// ?Serialize@idEntity@@UAAXAAVidSerializer@@@Z
// EA  : 0x82C3FE98
// RVA : 0x00C3FE98
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Serialize(idEntity *this, idSerializer *ser)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->Serialize(this: presentable, a2: ser);
}


// ========================================================================
// ?PostSerializeRead@idEntity@@UAAX_N@Z
// EA  : 0x82C3FEB8
// RVA : 0x00C3FEB8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::PostSerializeRead(idEntity *this, bool initial)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->PostSerializeRead(this: presentable, a2: initial);
}


// ========================================================================
// ?GetMasterPosition@idEntityPhysicsCallbacks@@UAA_NAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C3FED8
// RVA : 0x00C3FED8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntityPhysicsCallbacks::GetMasterPosition(
        idEntityPhysicsCallbacks *this,
        idVec3 *masterOrigin,
        idMat3 *masterAxis)
{
  return idEntity::GetMasterPosition(this: this->self, masterOrigin, masterAxis);
}


// ========================================================================
// ?Spawn@idEntity@@QAAXXZ
// EA  : 0x82C3FEE0
// RVA : 0x00C3FEE0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Spawn(idEntity *this, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  const idDeclEntityDef *entityDef; // r30
  char *data; // r11
  const idDeclEntityDef *v9; // r11
  __int64 v10; // r6
  int entityNumber; // r30
  va *v12; // r3
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  idClipModelInfo::clipModelType_t type; // r11
  idPresentable *presentable; // r3
  idPresentable *v19; // r11
  int v20; // r30
  idRenderModelInfo *v21; // r3
  idRenderModel *model; // r3
  int GameMs; // r30
  int v24; // r29
  int GameMsPerFrame; // r3
  char flags; // r11
  int value; // r9
  idEntity *v28; // r3
  idPresentable *v29; // r30
  idPhysics *physics; // r3
  int v31; // r3
  int v32; // r10
  int v33; // r9
  int v34; // r8
  int v35; // r7
  int v36; // r6
  int v37; // r5
  int v38; // [sp+8h] [-1078h]
  int v39; // [sp+Ch] [-1074h]
  int v40; // [sp+10h] [-1070h]
  int v41; // [sp+14h] [-106Ch]
  int v42; // [sp+18h] [-1068h]
  idPresentable *v43; // [sp+1Ch] [-1064h]
  va v44; // [sp+60h] [-1020h] BYREF

  entityDef = this->entityDef;
  if ( entityDef != nullptr && (*((_BYTE *)&entityDef->idResource + 32) & 0x80) == 0 )
  {
    if ( entityDef == entityDef->GetListedParent(this: this->entityDef) )
      idLib::Error(fmt: "EntityDef %s does not have a valid parent", this->entityDef->name.str);
    this->entityDef = this->entityDef->GetListedParent(this: this->entityDef);
  }
  data = this->name.data;
  if ( data == nullptr || *data == 0 )
  {
    v9 = this->entityDef;
    if ( v9 != nullptr )
    {
      LODWORD(a6) = &unk_822D0000;
      HIDWORD(v10) = v9->name.str;
      LODWORD(v10) = this->entityNumber;
    }
    else
    {
      entityNumber = this->entityNumber;
      v10 = __PAIR64__((unsigned int)idClass::GetClassname(this), entityNumber);
    }
    v12 = va::va(
            this: &v44,
            fmt: "%s_%d",
            a3: v10,
            a4: a5,
            a5: a6,
            a6: v38,
            a7: v39,
            a8: v40,
            a9: v41,
            a10: v42,
            a11: (int)v43);
    idEntity::SetName(this, newName: v12->buffer);
  }
  idEntity::InitRenderModel(this);
  if ( this->presentable == nullptr )
  {
    if ( this->clipModelInfo.type == CLIPMODEL_NONE )
      goto LABEL_23;
    idEntity::InitPresentableInternal(this);
  }
  type = this->clipModelInfo.type;
  if ( type == CLIPMODEL_CUSTOM || type == CLIPMODEL_RENDERMODEL )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetClipModelInfo(
      this: presentable,
      clipModelInfo_: &this->clipModelInfo,
      clipModelSpawnPos_: &this->spawnPosition,
      clipModelSpawnAxis_: &this->spawnOrientation,
      a5: v16,
      a6: v15,
      a7: v14,
      a8: v13,
      a9: v38,
      a10: v39,
      a11: v40,
      a12: v41,
      a13: v42,
      a14: v43);
  }
  v19 = this->presentable;
  v20 = this->entityNumber;
  if ( v19 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v19 = this->presentable;
  }
  idPresentable::SetEntityNumber(this: v19, value: v20);
LABEL_23:
  v21 = this->GetRenderModelInfo(this);
  if ( v21 != nullptr )
  {
    model = v21->model;
    if ( model != nullptr )
      idRenderModel::CommitThisFrame(this: model);
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v24 = (int)(float)(this->dormancy.delay * (float)1000.0);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  flags = (char)this->flags;
  this->dormancy.lastTimeInPlayerPVS = 5 * GameMsPerFrame - v24 + GameMs;
  if ( flags < 0 )
  {
    *(_BYTE *)&this->flags = flags & 0x7F;
    idEventReceiver::PostEventMS(this, ev: &EV_Hide, time: 0);
  }
  idEntity::InitDefaultPhysics(this, origin: &this->spawnPosition, axis: &this->spawnOrientation);
  value = this->bindInfo.bindParent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v28 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v28 != nullptr && idEntity::CastTo(c: v28) != nullptr )
      idEventReceiver::PostEventMS(this, ev: &EV_SpawnBind, time: 0);
  }
  idEntity::ConstructScriptObject(this);
  v29 = this->presentable;
  if ( v29 != nullptr )
  {
    physics = this->physics;
    if ( physics != nullptr )
    {
      v31 = physics->GetContents(this: physics, a2: -1);
      idPresentable::SetClipModelContents(
        this: v29,
        newContents: v31,
        a3: v37,
        a4: v36,
        a5: v35,
        a6: v34,
        a7: v33,
        a8: v32);
    }
  }
  idEntity::InitComponents(this);
}


// ========================================================================
// ?FreeRenderModel@idEntity@@QAAXXZ
// EA  : 0x82C401D0
// RVA : 0x00C401D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::FreeRenderModel(idEntity *this)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r3
  idPresentable *v4; // r11
  idRenderModelInfo *v5; // r3

  presentable = this->presentable;
  if ( presentable != nullptr && presentable->model != nullptr )
  {
    model = presentable->model;
    model->unlinked = true;
    model->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: model);
    v4 = this->presentable;
    if ( v4 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v4 = this->presentable;
    }
    v4->SetRenderModel(this: v4, a2: nullptr, a3: true);
  }
  v5 = this->GetRenderModelInfo(this);
  if ( v5 != nullptr )
    idRenderModelInfo::FreeRenderModel(this: v5);
}


// ========================================================================
// ?UpdateVisuals@idEntity@@QAAXXZ
// EA  : 0x82C40288
// RVA : 0x00C40288
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateVisuals(idEntity *this)
{
  this->UpdateModelTransform(this);
  idEntity::UpdateSound(this);
}


// ========================================================================
// ?UpdateDeferredVisuals@idEntity@@QAAXXZ
// EA  : 0x82C402C8
// RVA : 0x00C402C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::UpdateDeferredVisuals(idEntity *this)
{
  idEntity *teamMaster; // r11
  idEntity *teamChain; // r31
  idPresentable *presentable; // r11
  idRenderModel *model; // r10

  teamMaster = this->bindInfo.teamMaster;
  if ( teamMaster == nullptr || teamMaster == this )
  {
    teamChain = this;
    do
    {
      presentable = teamChain->presentable;
      if ( presentable != nullptr )
      {
        model = presentable->model;
        if ( model != nullptr && model->useDeferredPosition )
        {
          teamChain->UpdateModelTransform(this: teamChain);
          idEntity::UpdateSound(this: teamChain);
        }
      }
      teamChain = teamChain->bindInfo.teamChain;
    }
    while ( teamChain != nullptr );
  }
}


// ========================================================================
// ?ProjectOverlay@idEntity@@UAAXABVidVec3@@0MPBD@Z
// EA  : 0x82C40358
// RVA : 0x00C40358
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ProjectOverlay(
        idEntity *this,
        const idVec3 *origin,
        const idVec3 *dir,
        double size,
        const char *material)
{
  idPresentable *presentable; // r11
  char v7; // r11
  bool v8; // zf
  __int64 v9; // r7
  float *v10; // r3
  float v11[2]; // [sp+50h] [-20h] BYREF
  __int64 v12; // [sp+58h] [-18h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (v8 = presentable->model != nullptr, v7 = 1, !v8) )
    v7 = 0;
  if ( v7 != 0 )
  {
    HIDWORD(v9) = clientGame->random.seed;
    v10 = (float *)(1664525 * clientGame->random.seed);
    clientGame->random.seed = (unsigned int)v10 + 1013904223;
    LODWORD(v9) = (((unsigned int)v10 + 1013904223) >> 10) & 0x7FFF;
    v12 = v9;
    idMath::SinCos16(
      a: (float)((float)((float)v9 * idMath::TWO_PI) * (float)0.000030518509),
      s: v10,
      c: (float *)&v12,
      a4: v11);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetNoShadows@idEntity@@QAAX_N@Z
// EA  : 0x82C40450
// RVA : 0x00C40450
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetNoShadows(idEntity *this, bool set)
{
  idRenderModelInfo *v4; // r3
  idPresentable *presentable; // r11
  char v6; // r10

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    idRenderModelInfo::SetNoShadows(this: v4, set);
    presentable = this->presentable;
    if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
      v6 = 0;
    if ( v6 != 0 )
    {
      *((_BYTE *)&presentable->model->g + 105) = (set << 7) | *((_BYTE *)&presentable->model->g + 105) & 0x7F;
      this->UpdateModelTransform(this);
      idEntity::UpdateSound(this);
    }
  }
}


// ========================================================================
// ?InitBind@idEntity@@AAA_NPAV1@@Z
// EA  : 0x82C40500
// RVA : 0x00C40500
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::InitBind(idEntity *this, idWorldspawn *master)
{
  int result; // r3

  if ( master == this )
    idLib::Error(fmt: "Tried to bind an object to itself.");
  if ( this == gameLocal->world )
    idLib::Error(fmt: "Tried to bind world to another entity");
  idEntity::Unbind(this);
  if ( master == nullptr )
    return 0;
  result = 1;
  if ( master == gameLocal->world )
    return 0;
  return result;
}


// ========================================================================
// ?Bind@idEntity@@QAAXPAV1@_N@Z
// EA  : 0x82C40578
// RVA : 0x00C40578
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Bind(idEntity *this, idWorldspawn *master, bool orientated)
{
  char v6; // r7
  unsigned __int16 value; // r11
  idPhysics *physics; // r3
  idPhysics_vtbl *v9; // r29
  const idMat3 *v10; // r28
  idMat3 *v11; // r3
  idMat3 *v12; // r3
  idVec3 v13; // [sp+50h] [-C0h] BYREF
  idMat3 v14; // [sp+60h] [-B0h] BYREF
  idAngles v15[4]; // [sp+90h] [-80h] BYREF
  idMat3 v16[2]; // [sp+C0h] [-50h] BYREF

  if ( (unsigned __int8)idEntity::InitBind(this, master) != 0 )
  {
    this->PreBind(this);
    v6 = (orientated << 7) | *((_BYTE *)&this->bindInfo + 112) & 0x7F;
    this->bindInfo.bindJoint.value = -1;
    value = NULL_JOINT.value;
    this->bindInfo.bindMaster = master;
    this->bindInfo.bindTag.parentJoint.value = value;
    *((_BYTE *)&this->bindInfo + 112) = v6;
    idEntity::GetMasterPosition(this, masterOrigin: &v13, masterAxis: &v14);
    if ( (*((_BYTE *)&this->bindInfo + 112) & 0x10) != 0 )
    {
      this->physics->SetOrigin(this: this->physics, a2: &v13, a3: -1);
      this->physics->SetAxis(this: this->physics, a2: &v14, a3: -1);
    }
    if ( ((LODWORD(this->bindInfo.bindOffset.roll)
         | LODWORD(this->bindInfo.bindOffset.yaw)
         | LODWORD(this->bindInfo.bindOffset.pitch))
        & 0x7FFFFFFF) != 0 )
    {
      physics = this->physics;
      v9 = physics->__vftable;
      v10 = physics->GetAxis(this: physics, a2: 0);
      v11 = idAngles::ToMat3(this: v15, result: (idMat3 *)&this->bindInfo.bindOffset);
      v12 = idMat3::operator*(this: v16, result: v11, a: v10);
      v9->SetAxis(this: this->physics, a2: v12, a3: -1);
    }
    this->physics->SetMaster(
      this: this->physics,
      a2: this->bindInfo.bindMaster != nullptr,
      a3: &v13,
      a4: &v14,
      a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
    idEntity::FinishBind(this);
    this->PostBind(this);
  }
}


// ========================================================================
// ?BindToJoint@idEntity@@QAAXPAV1@PBD1_N@Z
// EA  : 0x82C40700
// RVA : 0x00C40700
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BindToJoint(
        idEntity *this,
        idAnimatedEntity *master,
        char *animName,
        const char *jointName,
        bool orientated)
{
  idAnimatedEntity *v10; // r3
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v12; // r29
  __int16 v13; // r8
  char v14; // r9
  idRenderModelInfo *v15; // r3
  idRenderModelInfo *v16; // r28
  int v17; // r12
  bool v18; // r25
  idMD6Blend::configInfo_t *VisualOffset; // r3
  const idMD6Anim *SingleAnimFrame; // r3
  idRenderModel *model; // r11
  const idMat3 *p_deferredAxis; // r5
  float *v23; // r11
  double v24; // fp13
  double v25; // fp12
  double v26; // fp11
  double v27; // fp10
  double v28; // fp9
  double v29; // fp8
  double v30; // fp7
  double v31; // fp6
  idRenderModel *v32; // r10
  float *p_axis; // r11
  int v34; // r9
  float *p_x; // r11
  double v36; // fp0
  double v37; // fp13
  double v38; // fp12
  double v39; // fp7
  double v40; // fp6
  idMat3 *v41; // r11
  idRenderModel *v42; // r11
  idVec3 *p_deferredOrigin; // r11
  idPhysics *physics; // r29
  idPhysics_vtbl *v45; // r28
  const idMat3 *v46; // r27
  idMat3 *v47; // r3
  idMat3 *v48; // r3
  _DWORD back_chain[20]; // [sp+0h] [-140h]
  _WORD v50[4]; // [sp+50h] [-F0h] BYREF
  idVec3 v51[2]; // [sp+58h] [-E8h] BYREF
  idMat3 v52; // [sp+70h] [-D0h] BYREF
  idMat3 v53; // [sp+A0h] [-A0h] BYREF
  idMat3 v54[3]; // [sp+D0h] [-70h] BYREF

  if ( (unsigned __int8)idEntity::InitBind(this, (idWorldspawn *)master) != 0 )
  {
    if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: master) != 0 )
    {
      v10 = idAnimatedEntity::CastTo(c: master);
      if ( v10 != nullptr
        && (TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10),
            v12 = (idTreeAnimator *)TreeAnimatorFromPresentable,
            TreeAnimatorFromPresentable != nullptr) )
      {
        idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)v50, result: TreeAnimatorFromPresentable, jointName);
        if ( v50[0] == 0xFFFF )
          idLib::Warning(
            fmt: "idEntity::BindToJoint: Can't bind '%s' to entity '%s' joint '%s' since the joint was not found.",
            this->name.data,
            master->name.data,
            jointName);
        this->PreBind(this);
        v13 = v50[0];
        v14 = (orientated << 7) | *((_BYTE *)&this->bindInfo + 112) & 0x7F;
        this->bindInfo.bindMaster = master;
        *((_BYTE *)&this->bindInfo + 112) = v14;
        this->bindInfo.bindJoint.value = v13;
        v15 = master->GetRenderModelInfo(this: master);
        v16 = v15;
        if ( animName != nullptr && *animName != 0 && v15 != nullptr )
        {
          idTreeAnimator::NumJoints(this: v12);
          ((void (*)(void))RtlCheckStack12)();
          *(_DWORD *)((char *)back_chain + v17) = back_chain[0];
          v18 = idTreeAnimator::GetRemoveOriginTranslation(ptr: v12);
          VisualOffset = idTreeAnimator::GetVisualOffset(this: v12);
          SingleAnimFrame = idTreeAnimator::GetSingleAnimFrame(
                              this: v12,
                              joints: (idJointMat *)v50,
                              animName,
                              time: 0,
                              offset: (const idVec3 *)VisualOffset,
                              removeOriginOffset: v18);
          model = v16->model;
          if ( SingleAnimFrame != nullptr )
          {
            p_deferredAxis = &model->deferredAxis;
            if ( !v16->model->useDeferredPosition )
              p_deferredAxis = &model->g.axis;
            v23 = (float *)&v50[24 * v50[0]];
            v24 = v23[6];
            v25 = v23[2];
            v26 = v23[9];
            v27 = v23[5];
            v28 = v23[1];
            v29 = v23[8];
            v30 = v23[4];
            v31 = *v23;
            v53.mat[2].z = v23[10];
            v53.mat[2].y = v24;
            v53.mat[2].x = v25;
            v53.mat[1].z = v26;
            v53.mat[1].y = v27;
            v53.mat[1].x = v28;
            v53.mat[0].z = v29;
            v53.mat[0].y = v30;
            v53.mat[0].x = v31;
            v52 = *idMat3::operator*(this: v54, result: &v53, a: p_deferredAxis);
            v32 = v16->model;
            p_axis = (float *)&v16->model->deferredAxis;
            if ( !v16->model->useDeferredPosition )
              p_axis = (float *)&v32->g.axis;
            v34 = 24 * v50[0];
            v36 = (float)((float)(*(float *)&v50[v34 + 6] * *p_axis)
                        + (float)((float)(p_axis[6] * *(float *)&v50[v34 + 22])
                                + (float)(p_axis[3] * *(float *)&v50[v34 + 14])));
            v37 = (float)((float)(p_axis[1] * *(float *)&v50[v34 + 6])
                        + (float)((float)(p_axis[7] * *(float *)&v50[v34 + 22])
                                + (float)(p_axis[4] * *(float *)&v50[v34 + 14])));
            v38 = (float)((float)(p_axis[2] * *(float *)&v50[v34 + 6])
                        + (float)((float)(p_axis[8] * *(float *)&v50[v34 + 22])
                                + (float)(p_axis[5] * *(float *)&v50[v34 + 14])));
            p_x = &v32->deferredOrigin.x;
            if ( !v32->useDeferredPosition )
              p_x = &v32->g.origin.x;
            v39 = (float)(p_x[1] + (float)v37);
            v40 = (float)(p_x[2] + (float)v38);
            v51[0].x = (float)v36 + *p_x;
            v51[0].y = v39;
            v51[0].z = v40;
          }
          else
          {
            if ( v16->model->useDeferredPosition )
              v41 = &model->deferredAxis;
            else
              v41 = &model->g.axis;
            v52 = *v41;
            v42 = v16->model;
            if ( v16->model->useDeferredPosition )
              p_deferredOrigin = &v42->deferredOrigin;
            else
              p_deferredOrigin = &v42->g.origin;
            v51[0] = *p_deferredOrigin;
          }
        }
        else
        {
          idEntity::GetMasterPosition(this, masterOrigin: v51, masterAxis: &v52);
        }
        if ( (*((_BYTE *)&this->bindInfo + 112) & 0x10) != 0 )
        {
          this->physics->SetOrigin(this: this->physics, a2: v51, a3: -1);
          this->physics->SetAxis(this: this->physics, a2: &v52, a3: -1);
        }
        if ( ((LODWORD(this->bindInfo.bindOffset.roll)
             | LODWORD(this->bindInfo.bindOffset.yaw)
             | LODWORD(this->bindInfo.bindOffset.pitch))
            & 0x7FFFFFFF) != 0 )
        {
          physics = this->physics;
          v45 = physics->__vftable;
          v46 = physics->GetAxis(this: physics, a2: 0);
          v47 = idAngles::ToMat3(this: (idAngles *)v54, result: (idMat3 *)&this->bindInfo.bindOffset);
          v48 = idMat3::operator*(this: &v53, result: v47, a: v46);
          v45->SetAxis(this: physics, a2: v48, a3: -1);
        }
        this->physics->SetMaster(
          this: this->physics,
          a2: this->bindInfo.bindMaster != nullptr,
          a3: v51,
          a4: &v52,
          a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
        idEntity::FinishBind(this);
        this->PostBind(this);
      }
      else
      {
        idLib::Warning(
          fmt: "idEntity::BindToJoint: Can't bind '%s' to entity '%s' joint '%s' since it does not use a skeletal model.",
          this->name.data,
          master->name.data,
          jointName);
      }
    }
    else
    {
      idLib::Warning(
        fmt: "idEntity::BindToJoint: Can't bind '%s' to entity '%s' joint '%s' since it does not support skeletal models.",
        this->name.data,
        master->name.data,
        jointName);
    }
  }
}


// ========================================================================
// ?BindToJoint@idEntity@@QAAXPAV1@V?$idIndex@FW4invalidJointIndex_t@@@@_N@Z
// EA  : 0x82C40C08
// RVA : 0x00C40C08
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BindToJoint(
        idEntity *this,
        idWorldspawn *master,
        idIndex<short,enum invalidJointIndex_t> *jointnum,
        bool orientated)
{
  __int16 v6; // r29
  char v8; // r9
  idPhysics *physics; // r3
  idPhysics_vtbl *v10; // r29
  const idMat3 *v11; // r28
  idMat3 *v12; // r3
  idMat3 *v13; // r3
  idVec3 v14; // [sp+50h] [-C0h] BYREF
  idMat3 v15; // [sp+60h] [-B0h] BYREF
  idAngles v16[4]; // [sp+90h] [-80h] BYREF
  idMat3 v17[2]; // [sp+C0h] [-50h] BYREF

  v6 = (__int16)jointnum;
  if ( (unsigned __int8)idEntity::InitBind(this, master) != 0 )
  {
    this->PreBind(this);
    v8 = *((_BYTE *)&this->bindInfo + 112);
    this->bindInfo.bindJoint.value = v6;
    this->bindInfo.bindMaster = master;
    *((_BYTE *)&this->bindInfo + 112) = (orientated << 7) | v8 & 0x7F;
    idEntity::GetMasterPosition(this, masterOrigin: &v14, masterAxis: &v15);
    if ( (*((_BYTE *)&this->bindInfo + 112) & 0x10) != 0 )
    {
      this->physics->SetOrigin(this: this->physics, a2: &v14, a3: -1);
      this->physics->SetAxis(this: this->physics, a2: &v15, a3: -1);
    }
    if ( ((LODWORD(this->bindInfo.bindOffset.roll)
         | LODWORD(this->bindInfo.bindOffset.yaw)
         | LODWORD(this->bindInfo.bindOffset.pitch))
        & 0x7FFFFFFF) != 0 )
    {
      physics = this->physics;
      v10 = physics->__vftable;
      v11 = physics->GetAxis(this: physics, a2: 0);
      v12 = idAngles::ToMat3(this: v16, result: (idMat3 *)&this->bindInfo.bindOffset);
      v13 = idMat3::operator*(this: v17, result: v12, a: v11);
      v10->SetAxis(this: this->physics, a2: v13, a3: -1);
    }
    this->physics->SetMaster(
      this: this->physics,
      a2: this->bindInfo.bindMaster != nullptr,
      a3: &v14,
      a4: &v15,
      a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
    idEntity::FinishBind(this);
    this->PostBind(this);
  }
}


// ========================================================================
// ?BindToTag@idEntity@@QAAXPAV1@ABUtagData_t@@_N@Z
// EA  : 0x82C40D88
// RVA : 0x00C40D88
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BindToTag(idEntity *this, idWorldspawn *master, const tagData_t *tag, bool orientated)
{
  char v8; // r8
  idVec3 v9; // [sp+50h] [-60h] BYREF
  idMat3 v10[2]; // [sp+60h] [-50h] BYREF

  if ( (unsigned __int8)idEntity::InitBind(this, master) != 0 )
  {
    this->PreBind(this);
    this->bindInfo.bindTag.trans.x = tag->trans.x;
    this->bindInfo.bindTag.trans.y = tag->trans.y;
    this->bindInfo.bindTag.trans.z = tag->trans.z;
    this->bindInfo.bindTag.rot.x = tag->rot.x;
    this->bindInfo.bindTag.rot.y = tag->rot.y;
    this->bindInfo.bindTag.rot.z = tag->rot.z;
    this->bindInfo.bindTag.rot.w = tag->rot.w;
    this->bindInfo.bindTag.parentJoint.value = tag->parentJoint.value;
    v8 = (orientated << 7) | *((_BYTE *)&this->bindInfo + 112) & 0x7F;
    this->bindInfo.bindMaster = master;
    *((_BYTE *)&this->bindInfo + 112) = v8;
    idEntity::GetMasterPosition(this, masterOrigin: &v9, masterAxis: v10);
    this->physics->SetOrigin(this: this->physics, a2: &v9, a3: -1);
    this->physics->SetAxis(this: this->physics, a2: v10, a3: -1);
    this->physics->SetMaster(
      this: this->physics,
      a2: this->bindInfo.bindMaster != nullptr,
      a3: &v9,
      a4: v10,
      a5: (const bindFlags_t)((*((_BYTE *)&this->bindInfo + 112) & 0x80) != 0));
    idEntity::FinishBind(this);
    this->PostBind(this);
  }
}


// ========================================================================
// ?GetLocalCoordinates@idEntity@@QBA?AVidVec3@@ABV2@@Z
// EA  : 0x82C40EC0
// RVA : 0x00C40EC0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetLocalCoordinates(idEntity *this, idEntity *result, const idVec3 *vec)
{
  idEntity *v3; // r31
  float v5; // r10
  float z; // r9
  double v7; // fp8
  double v8; // fp3
  double y; // fp6
  double v10; // fp7
  double v11; // fp0
  float x; // r10
  double v13; // fp2
  idVec3 v15; // [sp+50h] [-50h] BYREF
  idMat3 v16; // [sp+60h] [-40h] BYREF

  v3 = this;
  if ( result->bindInfo.bindMaster != nullptr )
  {
    idEntity::GetMasterPosition(this: result, masterOrigin: &v15, masterAxis: &v16);
    v7 = (float)(vec->z - v15.z);
    v8 = (float)(vec->y - v15.y);
    y = v16.mat[1].y;
    v10 = (float)(v16.mat[1].x * (float)(vec->x - v15.x));
    v11 = (float)((float)(v16.mat[0].y * (float)(vec->y - v15.y))
                + (float)((float)(v16.mat[0].z * (float)(vec->z - v15.z))
                        + (float)(v16.mat[0].x * (float)(vec->x - v15.x))));
    v15.z = (float)(v16.mat[2].y * (float)(vec->y - v15.y))
          + (float)((float)(v16.mat[2].z * (float)(vec->z - v15.z)) + (float)(v16.mat[2].x * (float)(vec->x - v15.x)));
    v15.x = v11;
    x = v15.x;
    v13 = (float)((float)(v16.mat[1].z * (float)v7) + (float)v10);
    v3->listeningToList = (idList<idEventReceiver *,5> *)LODWORD(v15.z);
    *(float *)&v3->listenerList = (float)((float)y * (float)v8) + (float)v13;
    *(float *)&v3->__vftable = x;
    return v3;
  }
  else
  {
    v5 = vec->y;
    z = vec->z;
    this->__vftable = (idEntity_vtbl *)LODWORD(vec->x);
    *(float *)&this->listenerList = v5;
    *(float *)&this->listeningToList = z;
  }
  return this;
}


// ========================================================================
// ?GetWorldVector@idEntity@@QBA?AVidVec3@@ABV2@@Z
// EA  : 0x82C40FC8
// RVA : 0x00C40FC8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::GetWorldVector(idEntity *this, idEntity *result, const idVec3 *vec)
{
  idEntity *v3; // r31
  float y; // r10
  float z; // r9
  double v7; // fp1
  double v8; // fp7
  double v9; // fp3
  double v10; // fp13
  double v11; // fp0
  float x; // r10
  idVec3 v14; // [sp+50h] [-50h] BYREF
  idMat3 v15; // [sp+60h] [-40h] BYREF

  v3 = this;
  if ( result->bindInfo.bindMaster != nullptr )
  {
    idEntity::GetMasterPosition(this: result, masterOrigin: &v14, masterAxis: &v15);
    v7 = (float)(v15.mat[2].z * vec->z);
    v8 = (float)(v15.mat[1].y * vec->y);
    v9 = (float)(v15.mat[0].y * vec->x);
    v10 = (float)((float)(vec->x * v15.mat[0].z) + (float)(v15.mat[1].z * vec->y));
    v11 = (float)(v15.mat[2].y * vec->z);
    v14.x = (float)((float)(v15.mat[0].x * vec->x) + (float)(v15.mat[1].x * vec->y)) + (float)(v15.mat[2].x * vec->z);
    x = v14.x;
    *(float *)&v3->listeningToList = (float)v10 + (float)v7;
    v14.y = (float)((float)v9 + (float)v8) + (float)v11;
    v3->listenerList = (idList<idEventReceiver *,5> *)LODWORD(v14.y);
    *(float *)&v3->__vftable = x;
    return v3;
  }
  else
  {
    y = vec->y;
    z = vec->z;
    this->__vftable = (idEntity_vtbl *)LODWORD(vec->x);
    *(float *)&this->listenerList = y;
    *(float *)&this->listeningToList = z;
  }
  return this;
}


// ========================================================================
// ?SetOrigin@idEntity@@QAAXABVidVec3@@@Z
// EA  : 0x82C410D0
// RVA : 0x00C410D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetOrigin(idEntity *this, const idVec3 *org)
{
  this->physics->SetOrigin(this: this->physics, a2: org, a3: -1);
  this->UpdateModelTransform(this);
  idEntity::UpdateSound(this);
}


// ========================================================================
// ?SetAxis@idEntity@@UAAXABVidMat3@@@Z
// EA  : 0x82C41130
// RVA : 0x00C41130
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetAxis(idEntity *this, const idMat3 *axis)
{
  this->physics->SetAxis(this: this->physics, a2: axis, a3: -1);
  this->UpdateModelTransform(this);
  idEntity::UpdateSound(this);
}


// ========================================================================
// ?IsToLeft@idEntity@@QBA_NABVidVec3@@@Z
// EA  : 0x82C41190
// RVA : 0x00C41190
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::IsToLeft(idEntity *this, const idVec3 *pos)
{
  const idVec3 *v4; // r3
  double v5; // fp8
  idPresentable *presentable; // r11
  double v7; // fp6
  double v10; // fp12
  double v11; // fp2
  double v12; // fp0
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29

  v4 = this->physics->GetOrigin(this: this->physics, a2: 0);
  v5 = (float)(pos->z - v4->z);
  presentable = this->presentable;
  v7 = (float)(pos->y - v4->y);
  _FP2 = (float)((float)((float)((float)v7 * (float)v7)
                       + (float)((float)((float)v5 * (float)v5)
                               + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v10 = __frsqrte(_FP13);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)(pos->x - v4->x)
                                                                              * (float)(pos->x - v4->x))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                              + (float)((float)(pos->x - v4->x)
                                                                                      * (float)(pos->x - v4->x))))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10)
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5)) * (float)v10)
                                                                                              - (float)1.5)
                                                                              * (float)v10))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                      + (float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                              * (float)0.5))
                              * (float)v11)
                      - (float)1.5);
  v13 = (float)((float)(pos->x - v4->x)
              * (float)((float)v12
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                              * (float)v10)
                                                                                      - (float)1.5)
                                                                      * (float)v10)
                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)(pos->x - v4->x)
                                                                                              * (float)(pos->x - v4->x))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v10
                                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                              * (float)0.5))
                                                              * (float)v10)
                                                      - (float)1.5)
                                      * (float)v10))));
  v14 = (float)((float)((float)v12
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                              * (float)v10)
                                                                                      - (float)1.5)
                                                                      * (float)v10)
                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)(pos->x - v4->x)
                                                                                              * (float)(pos->x - v4->x))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v10
                                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                              * (float)0.5))
                                                              * (float)v10)
                                                      - (float)1.5)
                                      * (float)v10)))
              * (float)v7);
  v15 = (float)((float)v5
              * (float)((float)v12
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                              * (float)v10)
                                                                                      - (float)1.5)
                                                                      * (float)v10)
                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)(pos->x - v4->x)
                                                                                              * (float)(pos->x - v4->x))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v5 * (float)v5) + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x)))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v10
                                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)(pos->x - v4->x) * (float)(pos->x - v4->x))))
                                                                              * (float)0.5))
                                                              * (float)v10)
                                                      - (float)1.5)
                                      * (float)v10))));
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  return (float)((float)(presentable->axis.mat[1].x * (float)v13)
               + (float)((float)(presentable->axis.mat[1].z * (float)v15)
                       + (float)(presentable->axis.mat[1].y * (float)v14))) >= 0.0;
}


// ========================================================================
// ?RemoveNullTargets@idEntity@@QAAXXZ
// EA  : 0x82C412C8
// RVA : 0x00C412C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RemoveNullTargets(idEntity *this)
{
  int v2; // r30
  idList<idEntityPtr<idEntity>,5> *p_targets; // r31
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  int num; // r11
  int v8; // r11
  bool v9; // zf
  int v10; // r10
  _DWORD *v11; // r9

  v2 = this->targets.num - 1;
  if ( v2 >= 0 )
  {
    p_targets = &this->targets;
    v4 = v2;
    do
    {
      if ( v2 >= this->targets.num
        || (value = p_targets->list[v4].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
        || (v6 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        || idEntity::CastTo(c: v6) == nullptr )
      {
        num = p_targets->num;
        if ( v2 < num )
        {
          p_targets->num = num - 1;
          v9 = v2 >= num - 1;
          v8 = v2;
          if ( !v9 )
          {
            v10 = v4 * 4;
            do
            {
              ++v8;
              v11 = (int *)((char *)&p_targets->list->spawnId.value + v10);
              v10 += 4;
              *v11 = v11[1];
            }
            while ( v8 < p_targets->num );
          }
        }
      }
      --v2;
      --v4;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?Teleport@idEntity@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82C413B0
// RVA : 0x00C413B0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Teleport(idEntity *this, const idVec3 *origin, idMat3 *angles)
{
  idMat3 *v5; // r4
  idPhysics *physics; // r29
  idPhysics_vtbl *v7; // r30
  idMat3 *v8; // r3
  idBounds *v9; // r3
  idAngles v10[6]; // [sp+50h] [-50h] BYREF

  ((void (__fastcall *)(idPhysics *))this->physics->SetOrigin)(a1: this->physics);
  v5 = angles;
  physics = this->physics;
  v7 = physics->__vftable;
  v8 = idAngles::ToMat3(this: v10, result: v5);
  v7->SetAxis(this: physics, a2: v8, a3: -1);
  this->UpdateModelTransform(this);
  idEntity::UpdateSound(this);
  v9 = (idBounds *)this->physics->GetAbsBounds(this: this->physics, a2: -1);
  this->numPVSAreas = idPVS::GetPVSAreas(this: &clientGame->pvs, bounds: v9, areas: this->PVSAreas, maxAreas: 4);
}


// ========================================================================
// ?Event_RemoveTarget@idEntity@@AAA?AVeventBool@@PAV1@@Z
// EA  : 0x82C41468
// RVA : 0x00C41468
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RemoveTarget(idEntity *this, eventBool *result, idEntity *target)
{
  bool v6; // r28
  int v7; // r31
  int v8; // r30
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  int v12; // r11
  int v13; // r11

  v6 = false;
  v7 = 0;
  if ( *(int *)&result[100].value > 0 )
  {
    v8 = 0;
    do
    {
      v9 = *(_DWORD *)(v8 + *(_DWORD *)&result[96].value);
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
        v11 = idEntity::CastTo(c: v10);
      else
        v11 = nullptr;
      if ( v11 == target )
      {
        if ( v7 >= 0 )
        {
          v12 = *(_DWORD *)&result[100].value;
          if ( v7 < v12 )
          {
            v13 = v12 - 1;
            *(_DWORD *)&result[100].value = v13;
            if ( v7 != v13 )
              *(_DWORD *)(v8 + *(_DWORD *)&result[96].value) = *(_DWORD *)(4 * v13 + *(_DWORD *)&result[96].value);
          }
        }
        v6 = true;
        --v7;
        v8 -= 4;
      }
      ++v7;
      v8 += 4;
    }
    while ( v7 < *(_DWORD *)&result[100].value );
  }
  eventBool::eventBool((eventBool *)this, b: v6);
  return this;
}


// ========================================================================
// ?Event_RandomTarget@idEntity@@AAA?AVeventEntity@@PBD@Z
// EA  : 0x82C41568
// RVA : 0x00C41568
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_RandomTarget(idEntity *this, idEntity *result, const char *ignore)
{
  int num; // r11
  int v7; // r31
  idEntity *Target; // r3
  signed int v9; // r11
  int v10; // r11
  signed int v11; // r11
  unsigned int seed; // r8
  unsigned int v13; // r4
  int v14; // r3
  unsigned int v15; // r6
  unsigned int v16; // r8
  unsigned int v17; // r4
  int v18; // r3
  unsigned int v19; // r6
  int value; // r9
  idEntity *v21; // r3
  idEntity *v22; // r3

  idEntity::RemoveNullTargets(this: result);
  num = result->targets.num;
  if ( num == 0 )
    goto LABEL_21;
  if ( ignore == nullptr || *ignore == 0 || num <= 1 )
    goto LABEL_9;
  v7 = 0;
  while ( 1 )
  {
    Target = idEntity::GetTarget(this: result, i: v7);
    if ( Target != nullptr && idStr::Cmp(s1: Target->name.data, s2: ignore) == 0 )
      break;
    if ( ++v7 >= result->targets.num )
      goto LABEL_9;
  }
  if ( v7 >= 0 )
  {
    v11 = result->targets.num - 1;
    if ( result->targets.num == 1 )
    {
      v10 = 0;
    }
    else
    {
      seed = clientGame->random.seed;
      __twllei(v11, 0);
      v13 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v13;
      v14 = (v13 >> 10) & 0x7FFF;
      v15 = v11 & ~(__ROL4__(v14, 1) - 1);
      v10 = v14 % v11;
      __twlgei(v15, 0xFFFFFFFF);
    }
    if ( v10 >= v7 )
      ++v10;
  }
  else
  {
LABEL_9:
    v9 = result->targets.num;
    if ( v9 != 0 )
    {
      v16 = clientGame->random.seed;
      __twllei(v9, 0);
      v17 = 1664525 * v16 + 1013904223;
      clientGame->random.seed = v17;
      v18 = (v17 >> 10) & 0x7FFF;
      v19 = v9 & ~(__ROL4__(v18, 1) - 1);
      v10 = v18 % v9;
      __twlgei(v19, 0xFFFFFFFF);
    }
    else
    {
      v10 = 0;
    }
  }
  value = result->targets.list[v10].spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v21 = gameLocal->entities.ptr[result->targets.list[v10].spawnId.value & 0x1FFF]) != nullptr )
  {
    v22 = idEntity::CastTo(c: v21);
    eventEntity::eventEntity((eventEntity *)this, e: v22);
    return this;
  }
  else
  {
LABEL_21:
    eventEntity::eventEntity((eventEntity *)this, e: nullptr);
    return this;
  }
}


// ========================================================================
// ?Event_BindToJoint@idEntity@@AAA?AVeventVoid@@PAV1@PBD1M@Z
// EA  : 0x82C41748
// RVA : 0x00C41748
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_BindToJoint(
        idEntity *this,
        idEntity *result,
        idAnimatedEntity *master,
        char *animName,
        const char *jointName,
        double orientated)
{
  idEntity::BindToJoint(this: result, master, animName, jointName, orientated: orientated != 0.0);
  return this;
}


// ========================================================================
// ?Event_Bind@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C417A0
// RVA : 0x00C417A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Bind(idEntity *this, idEntity *result, idWorldspawn *master)
{
  idEntity::Bind(this: result, master, orientated: true);
  return this;
}


// ========================================================================
// ?Event_BindPosition@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C417E0
// RVA : 0x00C417E0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_BindPosition(idEntity *this, idEntity *result, idWorldspawn *master)
{
  idEntity::Bind(this: result, master, orientated: false);
  return this;
}


// ========================================================================
// ?Event_GetModel@idEntity@@AAA?AVeventString@@XZ
// EA  : 0x82C41820
// RVA : 0x00C41820
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetModel(idEntity *this, idEntity *result)
{
  const char *presentable; // r11
  char v5; // r10
  const char *v6; // r4

  presentable = (const char *)result->presentable;
  if ( presentable == nullptr || (v5 = 1, *((_DWORD *)presentable + 42) == 0) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = (const char *)result->presentable;
    }
    v6 = *(const char **)(*((_DWORD *)presentable + 42) + 16);
  }
  else
  {
    v6 = &byte_8200D768;
  }
  eventString::eventString((eventString *)this, s: v6);
  return this;
}


// ========================================================================
// ?Event_SetSkin@idEntity@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C418B8
// RVA : 0x00C418B8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetSkin(
        idEntity *this,
        idEntity *result,
        double parm0,
        double parm1,
        double parm2,
        double parm3)
{
  ((void (__fastcall *)(idEntity *, double, double, double, double))result->UpdateModelTransform)(
    a1: result,
    a2: parm0,
    a3: parm1,
    a4: parm2,
    a5: parm3);
  idEntity::UpdateSound(this: result);
  return this;
}


// ========================================================================
// ?Event_SetHighlight@idEntity@@AAA?AVeventVoid@@W4highlightColor_t@@@Z
// EA  : 0x82C41910
// RVA : 0x00C41910
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetHighlight(idEntity *this, idEntity *result, highlightColor_t hlColor)
{
  idPresentable *presentable; // r11
  char v7; // r10
  idRenderModel *model; // r10
  idPresentable *v9; // r11

  presentable = result->presentable;
  if ( presentable == nullptr || (v7 = 1, presentable->model == nullptr) )
    v7 = 0;
  if ( v7 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = hlColor;
    model->g.highlightColor = hlColor;
    v9 = result->presentable;
    if ( v9 != nullptr )
      idRenderModel::CommitThisFrame(this: v9->model);
    else
      idRenderModel::CommitThisFrame(this: nullptr);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Event_SetHighLight Called on entity without render model:  %s", result->name.data);
    return this;
  }
}


// ========================================================================
// ?Event_SetWorldOrigin@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C419C8
// RVA : 0x00C419C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetWorldOrigin(idEntity *this, idEntity *result, const idVec3 *org)
{
  result->physics->SetOrigin(this: result->physics, a2: org, a3: -1);
  result->UpdateModelTransform(this: result);
  idEntity::UpdateSound(this: result);
  return this;
}


// ========================================================================
// ?Event_SetOrigin@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C41A38
// RVA : 0x00C41A38
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SetOrigin(idEntity *this, idEntity *result, const idVec3 *org)
{
  idEntity *bindMaster; // r11

  bindMaster = result->bindInfo.bindMaster;
  if ( bindMaster != nullptr )
    idLib::Warning(
      fmt: "setOrigin:: called when entity '%s' is bound to '%s'",
      result->name.data,
      bindMaster->name.data);
  result->physics->SetLocalOrigin(this: result->physics, a2: org, a3: -1);
  result->UpdateModelTransform(this: result);
  idEntity::UpdateSound(this: result);
  return this;
}


// ========================================================================
// ?Event_GetOrigin@idEntity@@AAA?AVeventVector@@XZ
// EA  : 0x82C41AC0
// RVA : 0x00C41AC0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_GetOrigin(idEntity *this, idEntity *result)
{
  float v2; // r11
  const idVec3 *v5; // r3
  idEntity *LocalCoordinates; // r3
  char v8; // [sp+50h] [-30h] BYREF

  v2 = *(float *)&result->bindInfo.bindMaster;
  if ( v2 != 0.0 )
    idLib::Warning(
      fmt: "getOrigin:: called when entity '%s' is bound to '%s'",
      result->name.data,
      *(const char **)(LODWORD(v2) + 16));
  v5 = result->physics->GetOrigin(this: result->physics, a2: 0);
  LocalCoordinates = idEntity::GetLocalCoordinates(this: (idEntity *)&v8, result, vec: v5);
  eventVector::eventVector((eventVector *)this, v: (const idVec3 *)LocalCoordinates);
  return this;
}


// ========================================================================
// ?SetColor@idEntity@@UAAXMMMM@Z
// EA  : 0x82C41DD8
// RVA : 0x00C41DD8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetColor(idEntity *this, double red, double green, double blue, double alpha)
{
  idRenderModelInfo *v10; // r3

  v10 = this->GetRenderModelInfo(this);
  if ( v10 != nullptr )
  {
    idRenderModelInfo::SetColor(this: v10, red, green, blue, alpha);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetColor@idEntity@@UAAXMMM@Z
// EA  : 0x82C41E68
// RVA : 0x00C41E68
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetColor(idEntity *this, double red, double green, double blue)
{
  idRenderModelInfo *v8; // r3

  v8 = this->GetRenderModelInfo(this);
  if ( v8 != nullptr )
  {
    idRenderModelInfo::SetColor(this: v8, red, green, blue);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetColor@idEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82C41EF8
// RVA : 0x00C41EF8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetColor(idEntity *this, const idVec3 *color)
{
  idRenderModelInfo *v4; // r3

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    idRenderModelInfo::SetColor(this: v4, inColor: color);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetColor@idEntity@@UAAXABVidColor@@@Z
// EA  : 0x82C41F68
// RVA : 0x00C41F68
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetColor(idEntity *this, const idColor *color)
{
  idRenderModelInfo *v4; // r3

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    idRenderModelInfo::SetColor(this: v4, inColor: color);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetColor@idEntity@@UAAXABVidVec4@@@Z
// EA  : 0x82C41FD8
// RVA : 0x00C41FD8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetColor(idEntity *this, const idVec4 *color)
{
  idRenderModelInfo *v4; // r3

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    idRenderModelInfo::SetColor(this: v4, inColor: color);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetModelByName@idEntity@@UAAXPBD@Z
// EA  : 0x82C42048
// RVA : 0x00C42048
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetModelByName(idEntity *this, const char *modelname)
{
  idRenderModelInfo *v4; // r30
  const char *Classname; // r3
  idPresentable *presentable; // r3

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    Classname = idClass::GetClassname(this);
    idRenderModelInfo::SetModelByName(this: v4, modelName: modelname, className: Classname);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->SetRenderModel(this: presentable, a2: v4->model, a3: true);
    v4->ownedByPresentable = true;
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?SetModel@idEntity@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82C42100
// RVA : 0x00C42100
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetModel(idEntity *this, idRenderModel *model)
{
  idRenderModelInfo *v4; // r30
  const char *Classname; // r3
  idPresentable *presentable; // r11
  idRenderModel *v7; // r3
  idPresentable *v8; // r3

  v4 = this->GetRenderModelInfo(this);
  if ( v4 != nullptr )
  {
    Classname = idClass::GetClassname(this);
    idRenderModelInfo::SetModel(this: v4, inModel: model, className: Classname);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v7 = presentable->model;
    if ( v4->ownedByPresentable && v7 != nullptr && v7 != model )
    {
      v7->unlinked = true;
      v7->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: v7);
    }
    v8 = this->presentable;
    if ( v8 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v8 = this->presentable;
    }
    v8->SetRenderModel(this: v8, a2: v4->model, a3: true);
    v4->ownedByPresentable = true;
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?Hide@idEntity@@UAAXXZ
// EA  : 0x82C42200
// RVA : 0x00C42200
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Hide(idEntity *this)
{
  char flags; // r11
  idPresentable *presentable; // r3

  flags = (char)this->flags;
  if ( (flags & 0x80) == 0 )
  {
    presentable = this->presentable;
    *(_BYTE *)&this->flags = flags & 0x7F | 0x80;
    if ( presentable != nullptr )
      presentable->Hide(this: presentable, a2: true);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?Hide@idEntity@@UAAX_N@Z
// EA  : 0x82C42280
// RVA : 0x00C42280
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Hide(idEntity *this, bool stopFx)
{
  char flags; // r11
  idPresentable *presentable; // r3

  flags = (char)this->flags;
  if ( (flags & 0x80) == 0 )
  {
    presentable = this->presentable;
    *(_BYTE *)&this->flags = flags & 0x7F | 0x80;
    if ( presentable != nullptr )
      presentable->Hide(this: presentable, a2: stopFx);
    ((void (__fastcall *)(idEntity *, bool))this->UpdateModelTransform)(a1: this, a2: stopFx);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?Show@idEntity@@UAAXXZ
// EA  : 0x82C42300
// RVA : 0x00C42300
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Show(idEntity *this)
{
  idPresentable *presentable; // r3

  if ( (*(_BYTE *)&this->flags & 0x80) != 0 )
  {
    idEntity::LeaveDormancy(this);
    presentable = this->presentable;
    *(_BYTE *)&this->flags &= ~0x80u;
    if ( presentable != nullptr )
      presentable->Show(this: presentable);
    this->UpdateModelTransform(this);
    idEntity::UpdateSound(this);
  }
}


// ========================================================================
// ?BindToTag@idEntity@@QAAXPAV1@PBD_N@Z
// EA  : 0x82C42380
// RVA : 0x00C42380
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::BindToTag(idEntity *this, idWorldspawn *master, const char *tagName, bool orientated)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r3
  _DWORD *v10; // r29
  const char *str; // r30
  idAnimatedEntity *v12; // r3
  idEntity *v13; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const idDeclMD6 *decl; // r11
  idPresentable *v16; // r3
  idPropsCollection *v17; // r11
  idPropsCollection *v18; // r3
  const tagData_t *Tag; // r3
  char *v20; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r11
  int i; // ctr
  unsigned __int16 value; // r11
  idPropsCollection *v24; // r11
  idPropsCollection *v25; // r3
  const tagData_t *v26; // r3
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v30; // fp11
  double v31; // fp10
  double v32; // fp9
  double w; // fp8
  bool v34; // cr58
  idPropsCollection *v35; // r11
  idPropsCollection *v36; // r10
  idPropsCollection *v37; // r3
  const tagData_t *v38; // r3
  char *v39; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v40; // r11
  int j; // ctr
  char v42; // [sp+4Ch] [-64h] BYREF
  tagData_t v43; // [sp+50h] [-60h] BYREF

  presentable = master->presentable;
  if ( presentable != nullptr )
    model = presentable->model;
  else
    model = nullptr;
  v10 = _RTDynamicCast(
          inptr: model,
          VfDelta: 0,
          SrcType: &idRenderModel `RTTI Type Descriptor',
          TargetType: &idTreeAnimator `RTTI Type Descriptor',
          isReference: 0);
  if ( v10 == nullptr )
  {
    idLib::Warning(
      fmt: "Unable to bind '%s' to animated-entity-without-tree-animator '%s'.",
      this->name.data,
      master->name.data);
    return;
  }
  str = nullptr;
  v12 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)this);
  v13 = v12;
  if ( v12 != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v12);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      decl = TreeAnimatorFromPresentable->decl;
      if ( decl != nullptr )
        str = decl->name.str;
      else
        str = &byte_8200D768;
    }
    v16 = v13->presentable;
    if ( v16 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v13);
      v16 = v13->presentable;
    }
    idPresentable::UpdateModelTransform(this: v16);
    if ( str != nullptr )
    {
      v17 = (idPropsCollection *)v10[508];
      v18 = v17 + 22;
      if ( v17 == nullptr )
        v18 = nullptr;
      Tag = idPropsCollection::GetTag(this: v18, propName: str, tagName);
      v20 = &v42;
      p_parentJoint = &Tag[-1].parentJoint;
      for ( i = 8; i != 0; --i )
      {
        p_parentJoint += 2;
        v20 += 4;
        *(_DWORD *)v20 = *(_DWORD *)&p_parentJoint->value;
      }
      value = v43.parentJoint.value;
      if ( v43.parentJoint.value == 0xFFFF )
      {
        v24 = (idPropsCollection *)v10[508];
        v25 = v24 + 22;
        if ( v24 == nullptr )
          v25 = nullptr;
        v26 = idPropsCollection::GetTag(this: v25, propName: "_info", tagName);
        value = v26->parentJoint.value;
        x = v26->trans.x;
        y = v26->trans.y;
        z = v26->trans.z;
        v30 = v26->rot.x;
        v31 = v26->rot.y;
        v43.parentJoint.value = value;
        v32 = v26->rot.z;
        w = v26->rot.w;
        v43.trans.x = x;
        v43.trans.y = y;
        v43.trans.z = z;
        v43.rot.x = v30;
        v43.rot.y = v31;
        v43.rot.z = v32;
        v43.rot.w = w;
      }
      v34 = value == 0xFFFF;
LABEL_31:
      if ( !v34 )
        idEntity::BindToTag(this, master, tag: &v43, orientated);
      return;
    }
  }
  v35 = (idPropsCollection *)v10[508];
  v36 = v35 + 22;
  if ( v35 == nullptr )
    v36 = nullptr;
  if ( v36->props.num > 0 )
  {
    v37 = v35 + 22;
    if ( v35 == nullptr )
      v37 = nullptr;
    v38 = idPropsCollection::GetTag(this: v37, propName: "_info", tagName);
    v39 = &v42;
    v40 = &v38[-1].parentJoint;
    for ( j = 8; j != 0; --j )
    {
      v40 += 2;
      v39 += 4;
      *(_DWORD *)v39 = *(_DWORD *)&v40->value;
    }
    v34 = v43.parentJoint.value == 0xFFFF;
    goto LABEL_31;
  }
}


// ========================================================================
// ?IsEverUsable@idEntity@@UBA_NPBV1@@Z
// EA  : 0x82C425A0
// RVA : 0x00C425A0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::IsEverUsable(idEntity *this, idEntity *activator)
{
  idScriptObject *p_scriptObject; // r30
  const function_t *Function; // r30
  int GameMs; // r3
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r8
  va *v10; // r3
  BOOL v11; // r30
  int v13; // [sp+8h] [-2C18h]
  int v14; // [sp+Ch] [-2C14h]
  int v15; // [sp+10h] [-2C10h]
  int v16; // [sp+14h] [-2C0Ch]
  int v17; // [sp+18h] [-2C08h]
  int v18; // [sp+1Ch] [-2C04h]
  va v19; // [sp+50h] [-2BD0h] BYREF
  idThread v20; // [sp+1050h] [-1BD0h] BYREF

  p_scriptObject = &this->scriptObject;
  if ( !idScriptObject::HasObject(this: &this->scriptObject)
    || idScriptObject::GetFunction(this: p_scriptObject, name: "use") == nullptr
    || idScriptObject::GetFunction(this: p_scriptObject, name: "getUsableState") == nullptr
    && idScriptObject::GetFunction(this: p_scriptObject, name: "isCrosshairDisabled") == nullptr
    && idScriptObject::GetFunction(this: p_scriptObject, name: "isCrosshairSubdued") == nullptr )
  {
    return 0;
  }
  if ( idScriptObject::GetFunction(this: p_scriptObject, name: "isEverUsable") == nullptr )
    return 1;
  Function = idScriptObject::GetFunction(this: p_scriptObject, name: "isEverUsable");
  idThread::idThread(this: &v20);
  idThread::ManualDelete(this: &v20);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  LODWORD(v7) = &unk_822D0000;
  LODWORD(v8) = GameMs;
  HIDWORD(v8) = this->name.data;
  v10 = va::va(this: &v19, fmt: "%s_%d", a3: v8, a4: v9, a5: v7, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
  idThread::SetThreadName(this: &v20, name: v10->buffer);
  idInterpreter::PushEntity(this: &v20.interpreter, ent: activator);
  idInterpreter::EnterObjectFunction(this: &v20.interpreter, self: activator, func: Function, clearStack: false);
  idThread::Execute(this: &v20);
  v11 = *gameLocal->program.returnDef->value.value.ip != 0;
  idThread::~idThread(this: &v20);
  return v11;
}


// ========================================================================
// __unwind$506718
// EA  : 0x82C42720
// RVA : 0x00C42720
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_506718()
{
  int v0; // r12

  idThread::~idThread(this: (idThread *)(v0 - 11296 + 4176));
}


// ========================================================================
// ?Event_SpawnBind@idEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C42748
// RVA : 0x00C42748
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_SpawnBind(idEntity *this, idEntity *result)
{
  int value; // r10
  idEntity *v5; // r3
  idWorldspawn *v6; // r3
  idAnimatedEntity *v7; // r30
  int len; // r11

  value = result->bindInfo.bindParent.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return this;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr )
    return this;
  v6 = (idWorldspawn *)idEntity::CastTo(c: v5);
  v7 = (idAnimatedEntity *)v6;
  if ( v6 == nullptr )
    return this;
  len = result->bindInfo.bindToTag.len;
  if ( result->bindInfo.bindToJoint.len == 0 )
  {
    if ( len != 0 )
    {
      idEntity::BindToTag(
        this: result,
        master: v6,
        tagName: result->bindInfo.bindToTag.data,
        orientated: *((_BYTE *)&result->bindInfo + 112) >> 7);
      return this;
    }
    idEntity::Bind(this: result, master: v6, orientated: *((_BYTE *)&result->bindInfo + 112) >> 7);
    return this;
  }
  if ( len != 0 )
    idLib::Warning(fmt: "Entity '%s' is bound to a joint AND a tag, only the joint is being used.", result->name.data);
  idEntity::BindToJoint(
    this: result,
    master: v7,
    animName: v7->bindInfo.bindAnim.data,
    jointName: result->bindInfo.bindToJoint.data,
    orientated: *((_BYTE *)&result->bindInfo + 112) >> 7);
  return this;
}


// ========================================================================
// ?CheckForErrors@idEntity@@UAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82C42840
// RVA : 0x00C42840
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::CheckForErrors(idEntity *this, idList<idStr,5> *errorList)
{
  __int64 v4; // r8
  unsigned int v5; // r6
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  va *v9; // r3
  int v10; // r11
  __int64 v11; // r10
  double v12; // fp0
  char v13; // r11
  va *v14; // r3
  int i; // r30
  idClipModel *v16; // r3
  int v17; // [sp+8h] [-1108h]
  int v18; // [sp+Ch] [-1104h]
  int v19; // [sp+10h] [-1100h]
  int v20; // [sp+14h] [-10FCh]
  int v21; // [sp+18h] [-10F8h]
  int v22; // [sp+1Ch] [-10F4h]
  idStr v23; // [sp+50h] [-10C0h] BYREF
  idStr v24; // [sp+70h] [-10A0h] BYREF
  idStr v25; // [sp+90h] [-1080h] BYREF
  idStr v26; // [sp+B0h] [-1060h] BYREF
  va v27; // [sp+D0h] [-1040h] BYREF

  if ( (unsigned __int8)idMat3::IsOrthoNormal(this: &this->spawnOrientation, epsilon: 0.000099999997) == 0 )
  {
    idStr::idStr(this: &v24, text: "bad spawnOrientation");
    idList<idStr,5>::Append(this: errorList, obj: &v24);
    idStr::FreeData(this: &v24);
  }
  if ( (unsigned __int8)IsValid<idVec3>(v: &this->spawnPosition) == 0 )
  {
    HIDWORD(v6) = idVec3::ToString(this: (idAngles *)&this->spawnPosition, precision: 2);
    v9 = va::va(
           this: &v27,
           fmt: "bad spawnPosition ( %s )",
           a3: v6,
           a4: v8,
           a5: v7,
           a6: v17,
           a7: v18,
           a8: v19,
           a9: v20,
           a10: v21,
           a11: v22);
    idStr::idStr(this: &v26, text: v9);
    idList<idStr,5>::Append(this: errorList, obj: &v26);
    idStr::FreeData(this: &v26);
  }
  HIDWORD(v11) = &unk_822D0000;
  LODWORD(v4) = &unk_822D0000;
  v10 = 0;
  LODWORD(v11) = &this->spawnPosition;
  while ( 1 )
  {
    v12 = *(float *)v11;
    if ( v12 > 64000.0 || v12 < -64000.0 )
      break;
    ++v10;
    LODWORD(v11) = v11 + 4;
    if ( v10 >= 3 )
    {
      v13 = 1;
      goto LABEL_10;
    }
  }
  v13 = 0;
LABEL_10:
  if ( v13 == 0 )
  {
    LODWORD(v11) = &unk_822D0000;
    v14 = va::va(
            this: &v27,
            fmt: (const char *)0x40EF4000,
            a3: v5,
            a4: v4,
            a5: v11,
            a6: v17,
            a7: v18,
            a8: v19,
            a9: v20,
            a10: v21,
            a11: v22);
    idStr::idStr(this: &v23, text: v14);
    idList<idStr,5>::Append(this: errorList, obj: &v23);
    idStr::FreeData(this: &v23);
  }
  for ( i = 0; i < this->physics->GetNumClipModels(this: this->physics); ++i )
  {
    v16 = this->physics->GetClipModel(this: this->physics, a2: i);
    if ( v16 != nullptr && v16->contents == 0x80000000 )
    {
      idStr::idStr(this: &v25, text: "uninitialized clip model contents");
      idList<idStr,5>::Append(this: errorList, obj: &v25);
      idStr::FreeData(this: &v25);
    }
  }
}


// ========================================================================
// $M506935
// EA  : 0x82C42A28
// RVA : 0x00C42A28
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _M506935()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 112));
}


// ========================================================================
// __unwind$506865
// EA  : 0x82C42A50
// RVA : 0x00C42A50
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_506865()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 176));
}


// ========================================================================
// __unwind$506866
// EA  : 0x82C42A78
// RVA : 0x00C42A78
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_506866()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 80));
}


// ========================================================================
// __unwind$506867
// EA  : 0x82C42AA0
// RVA : 0x00C42AA0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_506867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 144));
}


// ========================================================================
// ?SetSignal@idEntity@@QAAXW4signalNum_t@@PAVidThread@@PBVfunction_t@@@Z
// EA  : 0x82C42F48
// RVA : 0x00C42F48
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetSignal(
        idEntity *this,
        signalNum_t signalnum,
        idThread *thread,
        const function_t *function)
{
  signalList_t *v8; // r3
  signalList_t *v9; // r29
  signalList_t *v10; // r11
  signalNum_t v11; // r29
  int value; // r30
  int v13; // r10
  idList<signal_t,5> *v14; // r11
  int num; // r9
  signal_t *list; // r8
  int v17; // r11
  signal_t v18; // [sp+50h] [-40h] BYREF

  if ( this->signals == nullptr )
  {
    v8 = (signalList_t *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xC0u,
                           tag: TAG_GAME,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v9 = v8;
    v18.threadHandle.value = (int)v8;
    if ( v8 != nullptr )
    {
      `eh vector constructor iterator'(
        ptr: v8,
        size: 0x10u,
        count: 12,
        pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
        pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
      v10 = v9;
    }
    else
    {
      v10 = nullptr;
    }
    this->signals = v10;
  }
  v11 = signalnum;
  v13 = 0;
  v14 = &this->signals->signal[signalnum];
  value = thread->threadHandle.value;
  num = v14->num;
  if ( num <= 0 )
  {
LABEL_10:
    if ( num >= 16 )
      idThread::Error(this: thread, fmt: "Exceeded maximum number of signals per object");
    v18.threadHandle.value = value;
    v18.function = function;
    idList<signal_t,5>::Append(this: &this->signals->signal[v11], obj: &v18);
  }
  else
  {
    list = v14->list;
    v17 = 0;
    while ( list[v17].threadHandle.value != value )
    {
      ++v13;
      ++v17;
      if ( v13 >= num )
        goto LABEL_10;
    }
    list[v13].function = function;
  }
}


// ========================================================================
// __unwind$507159
// EA  : 0x82C43064
// RVA : 0x00C43064
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507159()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_GAME);
}


// ========================================================================
// ?TouchTrigger@idEntity@@QAAXPAV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@PAV1@PBVidClipModel@@@Z
// EA  : 0x82C43090
// RVA : 0x00C43090
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::TouchTrigger(
        idEntity *this,
        idList<idEntityPtr<idEntity>,58> *touchList,
        idEntity *trigger,
        const idClipModel *clipModel)
{
  int size; // r4
  idEventArg *v9; // r3
  idEntityPtr<idEntity> v10; // [sp+70h] [-90h] BYREF
  char v11; // [sp+80h] [-80h]
  int bodyId; // [sp+84h] [-7Ch]
  idEventArg v13; // [sp+A0h] [-60h] BYREF
  idEventReceiver v14[5]; // [sp+C0h] [-40h] BYREF

  if ( touchList->listStatic != 0 && (size = touchList->size, touchList->num == size) )
  {
    idLib::Warning(
      fmt: "Too many (%i) touched triggers for '%s'! Increase limits or remove triggers!",
      size,
      this->name.data);
  }
  else
  {
    if ( trigger != nullptr )
      v10.spawnId.value = (gameLocal->spawnIds.ptr[trigger->entityNumber] << 13) | trigger->entityNumber;
    else
      v10.spawnId.value = 0x1FFF;
    idList<idEntityPtr<idEntity>,58>::Append(this: touchList, obj: &v10);
    idEntity::Signal(this: trigger, signalnum: SIG_TOUCH);
    bodyId = clipModel->bodyId;
    v11 = 105;
    v9 = idEventArg::idEventArg(this: &v13, data: this);
    idEventReceiver::ProcessEvent(
      this: v14,
      result: (idEventArg *)trigger,
      ev: *(const idEventDef **)&v9->type,
      arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v9->value.v[2]));
  }
}


// ========================================================================
// ?UntouchTriggers@idEntity@@QAA_NABV?$idStaticList@V?$idEntityPtr@VidEntity@@@@$07@@@Z
// EA  : 0x82C43190
// RVA : 0x00C43190
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idList<idEntityPtr<idEntity>,5> *__fastcall idEntity::UntouchTriggers(
        idEntity *this,
        const idStaticList<idEntityPtr<idEntity>,8> *touched)
{
  idList<idEntityPtr<idEntity>,5> *result; // r3
  idList<idEntityPtr<idEntity>,58> *v5; // r28
  int v6; // r20
  int v7; // r27
  int v8; // r24
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r29
  int v12; // r30
  int v13; // r31
  int v14; // r9
  idEntity *v15; // r3
  idEntity *v16; // r3
  idEventArg *v17; // r3
  int num; // r11
  int v19; // r11
  int v20; // r30
  int v21; // r31
  int v22; // r10
  idEntityPtr<idEntity> *v23; // r4
  int v24; // r11
  idEventArg v25; // [sp+90h] [-A0h] BYREF
  idEventReceiver v26[10]; // [sp+B0h] [-80h] BYREF

  result = this->GetTriggerTouchList_2(this);
  v5 = (idList<idEntityPtr<idEntity>,58> *)result;
  if ( result != nullptr )
  {
    v6 = 0;
    v7 = result->num - 1;
    if ( v7 >= 0 )
    {
      v8 = v7;
      do
      {
        value = v5->list[v8].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v10 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v10 != nullptr )
          {
            v11 = idEntity::CastTo(c: v10);
            if ( v11 != nullptr )
            {
              v12 = 0;
              if ( touched->num > 0 )
              {
                v13 = 0;
                do
                {
                  v14 = touched->list[v13].spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
                    && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
                  {
                    v16 = idEntity::CastTo(c: v15);
                  }
                  else
                  {
                    v16 = nullptr;
                  }
                  if ( v16 == v11 )
                    break;
                  ++v12;
                  ++v13;
                }
                while ( v12 < touched->num );
              }
              if ( v12 < touched->num )
                goto LABEL_20;
              v11->physics->GetClipModel(this: v11->physics, a2: 0);
              v17 = idEventArg::idEventArg(this: &v25, data: this);
              idEventReceiver::ProcessEvent(
                this: v26,
                result: (idEventArg *)v11,
                ev: *(const idEventDef **)&v17->type,
                arg1: (const idEventArg *)LODWORD(v17->value.v[1]),
                arg2: (const idEventArg *)LODWORD(v17->value.v[2]));
            }
          }
        }
        ++v6;
        num = v5->num;
        if ( v7 < num )
        {
          v19 = num - 1;
          v5->num = v19;
          if ( v7 != v19 )
            v5->list[v8].spawnId.value = v5->list[v19].spawnId.value;
        }
LABEL_20:
        --v7;
        --v8;
      }
      while ( v7 >= 0 );
    }
    v20 = 0;
    if ( touched->num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = 0;
        v23 = &touched->list[v21];
        if ( v5->num <= 0 )
          goto LABEL_29;
        v24 = 0;
        while ( v5->list[v24].spawnId.value != v23->spawnId.value )
        {
          ++v22;
          ++v24;
          if ( v22 >= v5->num )
            goto LABEL_29;
        }
        if ( v22 < 0 )
LABEL_29:
          idList<idEntityPtr<idEntity>,58>::Append(this: v5, obj: v23);
        ++v20;
        ++v21;
      }
      while ( v20 < touched->num );
    }
    return (idList<idEntityPtr<idEntity>,5> *)(v6 != 0);
  }
  return result;
}


// ========================================================================
// ??0idEntity@@QAA@XZ
// EA  : 0x82C434F8
// RVA : 0x00C434F8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::idEntity(idEntity *this)
{
  char flags; // r6

  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idEntity_vtbl *)&idEntity::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->targets.list = nullptr;
  this->targets.granularity = 0;
  this->targets.memTag = 5;
  this->targets.listStatic = 0;
  this->targets.size = 0;
  this->targets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targets);
  idRenderModelInfo::idRenderModelInfo(this: &this->renderModelInfo, nextModel: nullptr);
  this->clipModelInfo.clipModelName.str = &byte_8200D768;
  idClipModelInfo::Clear(this: &this->clipModelInfo);
  this->bindInfo.bindParent.spawnId.value = 0x1FFF;
  this->bindInfo.bindToJoint.allocedAndFlag = 20;
  this->bindInfo.bindToJoint.len = 0;
  this->bindInfo.bindToJoint.data = this->bindInfo.bindToJoint.baseBuffer;
  this->bindInfo.bindToJoint.baseBuffer[0] = 0;
  this->bindInfo.bindToTag.data = this->bindInfo.bindToTag.baseBuffer;
  this->bindInfo.bindToTag.allocedAndFlag = 20;
  this->bindInfo.bindToTag.len = 0;
  this->bindInfo.bindToTag.baseBuffer[0] = 0;
  this->bindInfo.bindAnim.data = this->bindInfo.bindAnim.baseBuffer;
  this->bindInfo.bindAnim.allocedAndFlag = 20;
  this->bindInfo.bindAnim.len = 0;
  this->bindInfo.bindAnim.baseBuffer[0] = 0;
  this->bindInfo.bindJoint.value = -1;
  this->bindInfo.bindTag.trans.x = 0.0;
  this->bindInfo.bindTag.trans.y = 0.0;
  this->bindInfo.bindTag.trans.z = 0.0;
  this->bindInfo.bindTag.rot.x = 0.0;
  this->bindInfo.bindTag.rot.y = 0.0;
  this->bindInfo.bindTag.rot.z = 0.0;
  this->bindInfo.bindTag.rot.w = 0.0;
  this->bindInfo.bindTag.parentJoint.value = -1;
  idScriptObject::idScriptObject(this: &this->scriptObject);
  this->threadHandle.value = 0;
  this->entityNumber = 0x1FFF;
  this->entityDef = nullptr;
  idPhysics_Static::idPhysics_Static(this: &this->defaultPhysicsObj);
  this->physicsCallbacks.__vftable = (idEntityPhysicsCallbacks_vtbl *)&idEntityPhysicsCallbacks::`vftable';
  this->physics = nullptr;
  this->touchTriggersQuery.index = 0xFFFFFFFF00000000uLL;
  this->progressionEntity = nullptr;
  this->superScriptObjects.list = nullptr;
  this->superScriptObjects.granularity = 0;
  this->superScriptObjects.memTag = 5;
  this->superScriptObjects.listStatic = 0;
  this->superScriptObjects.size = 0;
  this->superScriptObjects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->superScriptObjects);
  this->spawnNode.owner = nullptr;
  this->spawnNode.head = &this->spawnNode;
  this->spawnNode.next = &this->spawnNode;
  this->spawnNode.prev = &this->spawnNode;
  this->activeNode.head = &this->activeNode;
  this->activeNode.next = &this->activeNode;
  this->activeNode.prev = &this->activeNode;
  this->activeNode.owner = nullptr;
  this->removeNode.owner = nullptr;
  this->removeNode.head = &this->removeNode;
  this->removeNode.next = &this->removeNode;
  this->removeNode.prev = &this->removeNode;
  this->physicsCallbacks.self = this;
  this->spawnNode.owner = this;
  this->activeNode.owner = this;
  this->removeNode.owner = this;
  this->spawnPosition.z = 0.0;
  this->spawnPosition.y = 0.0;
  this->spawnPosition.x = 0.0;
  this->spawnOrientation.mat[2].z = 1.0;
  this->spawnOrientation.mat[1].y = 1.0;
  this->spawnOrientation.mat[0].x = 1.0;
  this->spawnOrientation.mat[1].z = 0.0;
  this->spawnOrientation.mat[0].z = 0.0;
  this->spawnOrientation.mat[0].y = 0.0;
  this->spawnOrientation.mat[2].y = 0.0;
  this->spawnOrientation.mat[2].x = 0.0;
  this->spawnOrientation.mat[1].x = 0.0;
  *(_WORD *)&this->flags = 0;
  *((_BYTE *)&this->flags + 2) = 0;
  flags = (char)this->flags;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  *(_BYTE *)&this->flags = flags & 0xB7 | 8;
  this->clipModelInfo.size.z = 0.0;
  this->clipModelInfo.size.y = 0.0;
  this->clipModelInfo.size.x = 0.0;
  this->clipModelInfo.offset.z = 0.0;
  this->clipModelInfo.offset.y = 0.0;
  this->clipModelInfo.offset.x = 0.0;
  *((_BYTE *)&this->bindInfo + 112) = *((_BYTE *)&this->bindInfo + 112) & 0xF | 0xC0;
  this->clipModelInfo.numSides = 0;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.allowInline = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->bindInfo.bindOffset = ang_zero;
  this->bindInfo.bindMaster = nullptr;
  this->bindInfo.teamMaster = nullptr;
  this->dormancy.delay = 3.0;
  this->bindInfo.teamChain = nullptr;
  this->dormancy.distance = 256.0;
  this->bindInfo.bindJoint.value = -1;
  this->thinkFlags = 0;
  this->dormancy.lastTimeInPlayerPVS = 0;
  this->dormancy.becomeDormantTime = 0;
  this->dormancy.endForceTime = 0;
  this->dormancy.forceDormant = false;
  this->PVSAreas[0] = 0;
  this->PVSAreas[1] = 0;
  this->PVSAreas[2] = 0;
  this->PVSAreas[3] = 0;
  this->numPVSAreas = -1;
  this->signals = nullptr;
  this->presentable = nullptr;
  this->entitiesKilled = 0;
  this->firstPostSerializeRead = true;
  return this;
}


// ========================================================================
// __unwind$507698
// EA  : 0x82C43840
// RVA : 0x00C43840
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507698()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$507699
// EA  : 0x82C43868
// RVA : 0x00C43868
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507699()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// __unwind$507700
// EA  : 0x82C43894
// RVA : 0x00C43894
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507700()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 96));
}


// ========================================================================
// __unwind$507701
// EA  : 0x82C438C0
// RVA : 0x00C438C0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507701()
{
  int v0; // r12

  idRenderModelInfo::~idRenderModelInfo(this: (idRenderModelInfo *)(*(_DWORD *)(v0 - 160 + 180) + 112));
}


// ========================================================================
// __unwind$507702
// EA  : 0x82C438EC
// RVA : 0x00C438EC
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507702()
{
  int v0; // r12

  idEntity::idBindInfo::~idBindInfo(this: (idEntity::idBindInfo *)(*(_DWORD *)(v0 - 160 + 180) + 284));
}


// ========================================================================
// __unwind$507703
// EA  : 0x82C43918
// RVA : 0x00C43918
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507703()
{
  int v0; // r12

  idScriptObject::~idScriptObject(this: (idScriptObject *)(*(_DWORD *)(v0 - 160 + 180) + 472));
}


// ========================================================================
// __unwind$507704
// EA  : 0x82C43944
// RVA : 0x00C43944
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_507704()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 160 + 180) + 504));
}


// ========================================================================
// ??1idEntity@@UAA@XZ
// EA  : 0x82C43978
// RVA : 0x00C43978
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::~idEntity(idEntity *this)
{
  int thinkFlags; // r4
  signalList_t *signals; // r27
  idPresentable *presentable; // r3

  this->__vftable = (idEntity_vtbl *)&idEntity::`vftable';
  idEntity::DeconstructScriptObject(this);
  idScriptObject::Free(this: &this->scriptObject);
  thinkFlags = this->thinkFlags;
  if ( thinkFlags != 0 )
    idEntity::BecomeInactive(this, flags: thinkFlags);
  this->activeNode.prev->next = this->activeNode.next;
  this->activeNode.next->prev = this->activeNode.prev;
  this->activeNode.next = &this->activeNode;
  this->activeNode.prev = &this->activeNode;
  this->activeNode.head = &this->activeNode;
  idEntity::Signal(this, signalnum: SIG_REMOVED);
  this->physics = &this->defaultPhysicsObj;
  idEntity::RemoveBinds(this);
  idEntity::Unbind(this);
  idEntity::QuitTeam(this);
  idGameLocal::RemoveEntityFromHash(this: gameLocal, ent: this);
  signals = this->signals;
  if ( signals != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: this->signals,
      size: 0x10u,
      count: 12,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
    idMem::Free(this: &mem, ptr: signals, align: ALIGN_16);
  }
  this->signals = nullptr;
  idEntity::FreeRenderModel(this);
  idEntity::FreePresentable(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    idPresentable::FreeSoundEmitter(this: presentable, immediate: false);
  idGameLocal::UnregisterEntity(this: gameLocal, ent: this);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->removeNode);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->activeNode);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->spawnNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->superScriptObjects);
  idPhysics_Static::~idPhysics_Static(this: &this->defaultPhysicsObj);
  idScriptObject::~idScriptObject(this: &this->scriptObject);
  idEntity::idBindInfo::~idBindInfo(this: &this->bindInfo);
  idRenderModelInfo::~idRenderModelInfo(this: &this->renderModelInfo);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targets);
  idStr::FreeData(this: &this->name);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$508371
// EA  : 0x82C43AFC
// RVA : 0x00C43AFC
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508371()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$508372
// EA  : 0x82C43B24
// RVA : 0x00C43B24
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508372()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// __unwind$508373
// EA  : 0x82C43B50
// RVA : 0x00C43B50
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508373()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 96));
}


// ========================================================================
// __unwind$508374
// EA  : 0x82C43B7C
// RVA : 0x00C43B7C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508374()
{
  int v0; // r12

  idRenderModelInfo::~idRenderModelInfo(this: (idRenderModelInfo *)(*(_DWORD *)(v0 - 160 + 180) + 112));
}


// ========================================================================
// __unwind$508375
// EA  : 0x82C43BA8
// RVA : 0x00C43BA8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508375()
{
  int v0; // r12

  idEntity::idBindInfo::~idBindInfo(this: (idEntity::idBindInfo *)(*(_DWORD *)(v0 - 160 + 180) + 284));
}


// ========================================================================
// __unwind$508376
// EA  : 0x82C43BD4
// RVA : 0x00C43BD4
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508376()
{
  int v0; // r12

  idScriptObject::~idScriptObject(this: (idScriptObject *)(*(_DWORD *)(v0 - 160 + 180) + 472));
}


// ========================================================================
// __unwind$508377
// EA  : 0x82C43C00
// RVA : 0x00C43C00
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508377()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 160 + 180) + 504));
}


// ========================================================================
// __unwind$508378
// EA  : 0x82C43C2C
// RVA : 0x00C43C2C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508378()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 732));
}


// ========================================================================
// __unwind$508379
// EA  : 0x82C43C58
// RVA : 0x00C43C58
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508379()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                           + 748));
}


// ========================================================================
// __unwind$508380
// EA  : 0x82C43C84
// RVA : 0x00C43C84
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508380()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                           + 764));
}


// ========================================================================
// __unwind$508381
// EA  : 0x82C43CB0
// RVA : 0x00C43CB0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508381()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                           + 780));
}


// ========================================================================
// ?GetSoundEmitter@idEntity@@QAAPAVidSoundEmitter@@_N@Z
// EA  : 0x82C43CE8
// RVA : 0x00C43CE8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idSoundEmitter *__fastcall idEntity::GetSoundEmitter(idEntity *this, bool alloc)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPresentable *presentable; // r3
  idSoundEmitter *SoundEmitter; // r30
  idPLogScope v9[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idEntity::GetSoundEmitter - alloc");
  LODWORD(v4) = "idEntity::GetSoundEmitter - alloc";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v4, label: v5);
  if ( alloc || this->presentable != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    SoundEmitter = idPresentable::GetSoundEmitter(this: presentable, alloc);
    idPLogScope::~idPLogScope(this: v9);
    RD_EventEnd();
    return SoundEmitter;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v9);
    RD_EventEnd();
    return nullptr;
  }
}


// ========================================================================
// __unwind$508502
// EA  : 0x82C43D90
// RVA : 0x00C43D90
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508502()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$508503
// EA  : 0x82C43DB8
// RVA : 0x00C43DB8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508503()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?RunPhysics@idEntity@@QAAXXZ
// EA  : 0x82C43DE8
// RVA : 0x00C43DE8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::RunPhysics(idEntity *this)
{
  idEntity *teamMaster; // r11
  int v3; // r18
  int v4; // r16
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idEntity *teamChain; // r29
  idEntity *v8; // r17
  char *v9; // r25
  int v10; // r28
  idPLog::logEntry_t *v11; // r29
  __int64 v12; // r3
  bool v13; // r27
  idPLog::logEntry_t *v14; // r29
  int v15; // r3
  int parent; // r11
  __int64 v17; // r9
  char v18; // r11
  int v19; // r29
  idPLog::logEntry_t *v20; // r28
  __int64 v21; // r3
  idPLog::logEntry_t *v22; // r29
  int v23; // r3
  int v24; // r11
  __int64 v25; // r9
  const idEntity *v26; // r24
  idEntity *v27; // r30
  int v28; // r3
  int v29; // r3
  idEntity *v30; // r26
  _BYTE *v31; // r25
  int v32; // r28
  idPLog::logEntry_t *v33; // r29
  __int64 v34; // r3
  idPresentable *presentable; // r29
  idPhysics *physics; // r27
  idPhysics *v37; // r4
  int entityNumber; // r27
  idVec3 *(__fastcall *GetLinearVelocity)(idPhysics *, idVec3 *, int); // ctr
  const idVec3 *v40; // r3
  idPLog::logEntry_t *v41; // r29
  int v42; // r3
  int v43; // r11
  __int64 v44; // r9
  idEventArg *v45; // r3
  idEventArg *v46; // r3
  idEntity *v47; // r30
  idPLog *pLog; // r29
  idPLog::logEntry_t *v49; // r30
  int v50; // r3
  __int64 totalTicks; // r11
  __int64 v52; // r9
  idEventArg v53; // [sp+80h] [-2120h] BYREF
  idPLogScope v54; // [sp+98h] [-2108h] BYREF
  idVec3 v55; // [sp+A0h] [-2100h] BYREF
  idMat3 v56; // [sp+B0h] [-20F0h] BYREF
  idEventArg v57; // [sp+E0h] [-20C0h] BYREF
  _BYTE v58[160]; // [sp+100h] [-20A0h] BYREF

  teamMaster = this->bindInfo.teamMaster;
  if ( teamMaster == nullptr || teamMaster == this )
  {
    v3 = gameLocal->GetPreviousGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( v3 != v4 )
    {
      RD_EventBegin(name: "idEntity::RunPhysics");
      LODWORD(v5) = "idEntity::RunPhysics";
      HIDWORD(v5) = 2;
      idPLogScope::idPLogScope(this: &v54, pl: &::pLog, gMask: v5, label: v6);
      if ( (this->thinkFlags & 2) != 0 )
      {
        idPush::InitSavingPushedPhysicsObjectState(this: &clientGame->push);
        teamChain = this;
        do
        {
          if ( (*((_BYTE *)&teamChain->bindInfo + 112) & 0x20) == 0 )
            teamChain->physics->DisableClip(this: teamChain->physics);
          teamChain->physics->SaveState(this: teamChain->physics);
          teamChain = teamChain->bindInfo.teamChain;
        }
        while ( teamChain != nullptr );
        v53.value.i = (int)&::pLog;
        v8 = this;
        v9 = v58;
        while ( 1 )
        {
          RD_EventBegin(name: "idEntity::RunPhysics -- Evaluate");
          v10 = -1;
          *(_DWORD *)&v53.type = -1;
          if ( (::pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &::pLog.logEntries,
              newSize: ::pLog.logEntries.num + 1);
            if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
              v11 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
            else
              v11 = &::pLog.logEntries.list[::pLog.logEntries.num++];
            idMem::PopHeap(this: &mem);
            v11->label = "idEntity::RunPhysics -- Evaluate";
            v11->parent = ::pLog.lastEntry;
            v10 = ::pLog.logEntries.num - 1;
            ::pLog.lastEntry = ::pLog.logEntries.num - 1;
            *(_DWORD *)&v53.type = ::pLog.logEntries.num - 1;
            LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v11->totalTicks = v12;
          }
          v13 = v8->physics->Evaluate(this: v8->physics, a2: v4 - v3, a3: v4);
          if ( v10 >= 0 )
          {
            v14 = &::pLog.logEntries.list[v10];
            v15 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            parent = v14->parent;
            LODWORD(v17) = v15 - LODWORD(v14->totalTicks);
            *(_DWORD *)&v53.type = -1;
            v14->totalTicks = v17;
            ::pLog.lastEntry = parent;
          }
          RD_EventEnd();
          if ( v13 || (v18 = 0, (*(_BYTE *)&v8->flags & 0x20) != 0) )
            v18 = 1;
          *v9 = v18;
          if ( v18 != 0 )
          {
            RD_EventBegin(name: "idEntity::RunPhysics -- UpdateVisuals");
            v19 = -1;
            if ( (::pLog.groupMask & 2) != 0 )
            {
              idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
              v20 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
              idMem::PopHeap(this: &mem);
              v20->label = "idEntity::RunPhysics -- UpdateVisuals";
              v20->parent = ::pLog.lastEntry;
              v19 = ::pLog.logEntries.num - 1;
              ::pLog.lastEntry = ::pLog.logEntries.num - 1;
              LODWORD(v21) = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v20->totalTicks = v21;
            }
            v8->UpdateModelTransform(this: v8);
            idEntity::UpdateSound(this: v8);
            if ( v19 >= 0 )
            {
              v22 = &::pLog.logEntries.list[v19];
              v23 = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v24 = v22->parent;
              LODWORD(v25) = v23 - LODWORD(v22->totalTicks);
              v22->totalTicks = v25;
              ::pLog.lastEntry = v24;
            }
            RD_EventEnd();
          }
          v26 = gameLocal->entities.ptr[v8->physics->GetBlockingEntityNum(this: v8->physics)];
          if ( v26 != nullptr )
            break;
          v8 = v8->bindInfo.teamChain;
          ++v9;
          if ( v8 == nullptr )
          {
            v27 = this;
            do
            {
              if ( (*((_BYTE *)&v27->bindInfo + 112) & 0x20) == 0 )
                v27->physics->EnableClip(this: v27->physics);
              v28 = v27->physics->GetLinearEndTime(this: v27->physics);
              if ( v3 < v28 && v4 >= v28 )
                idEventReceiver::ProcessEvent(
                  this: (idEventReceiver *)&v53,
                  result: (idEventArg *)v27,
                  ev: &EV_ReachedPos);
              v29 = v27->physics->GetAngularEndTime(this: v27->physics);
              if ( v3 < v29 && v4 >= v29 )
                idEventReceiver::ProcessEvent(
                  this: (idEventReceiver *)&v53,
                  result: (idEventArg *)v27,
                  ev: &EV_ReachedAng);
              v27 = v27->bindInfo.teamChain;
            }
            while ( v27 != nullptr );
            idPush::SetPushedOnPushedPhysicsObjects(this: &clientGame->push, deltaTime: v4 - v3);
            goto LABEL_57;
          }
        }
        v30 = this;
        v31 = v58;
        do
        {
          v30->physics->RestoreState(this: v30->physics);
          if ( *v31 != 0 )
          {
            RD_EventBegin(name: "idEntity::RunPhysics -- UpdateVisuals");
            v32 = -1;
            if ( (::pLog.groupMask & 2) != 0 )
            {
              idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
              idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
                this: &::pLog.logEntries,
                newSize: ::pLog.logEntries.num + 1);
              if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
                v33 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
              else
                v33 = &::pLog.logEntries.list[::pLog.logEntries.num++];
              idMem::PopHeap(this: &mem);
              v33->label = "idEntity::RunPhysics -- UpdateVisuals";
              v33->parent = ::pLog.lastEntry;
              v32 = ::pLog.logEntries.num - 1;
              ::pLog.lastEntry = ::pLog.logEntries.num - 1;
              LODWORD(v34) = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v33->totalTicks = v34;
            }
            v30->UpdateModelTransform(this: v30);
            if ( v30->presentable != nullptr )
            {
              v30->GetSoundTransform(this: v30, a2: &v55, a3: &v56);
              presentable = v30->presentable;
              physics = v30->physics;
              if ( presentable == nullptr )
              {
                idEntity::InitPresentableInternal(this: v30);
                presentable = v30->presentable;
              }
              v37 = physics;
              GetLinearVelocity = physics->GetLinearVelocity;
              entityNumber = v30->entityNumber;
              v40 = GetLinearVelocity(this: (idPhysics *)&v53, result: (idVec3 *)v37, a3: 0);
              idPresentable::UpdateSound(
                this: presentable,
                origin: &v55,
                axis: &v56,
                velocity: v40,
                listenerId: entityNumber + 1);
            }
            if ( v32 >= 0 )
            {
              v41 = &::pLog.logEntries.list[v32];
              v42 = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v43 = v41->parent;
              LODWORD(v44) = v42 - LODWORD(v41->totalTicks);
              v41->totalTicks = v44;
              ::pLog.lastEntry = v43;
            }
            RD_EventEnd();
          }
          if ( (*((_BYTE *)&v30->bindInfo + 112) & 0x20) == 0 )
            v30->physics->EnableClip(this: v30->physics);
          v30->physics->UpdateTime(this: v30->physics, a2: v4);
          ++v31;
          v30 = v30->bindInfo.teamChain;
        }
        while ( v30 != nullptr );
        idPush::RestorePushedPhysicsObjectState(this: &clientGame->push);
        idEntity::Signal(this, signalnum: SIG_BLOCKED);
        idEventArg::idEventArg(this: &v53, data: v26);
        v45 = idEventArg::idEventArg(this: &v57, data: v8);
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&v56,
          result: (idEventArg *)this,
          ev: *(const idEventDef **)&v45->type,
          arg1: (const idEventArg *)LODWORD(v45->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v45->value.v[2]));
        v46 = idEventArg::idEventArg(this: (idEventArg *)&v56, data: v26);
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&v57,
          result: (idEventArg *)v8,
          ev: *(const idEventDef **)&v46->type,
          arg1: (const idEventArg *)LODWORD(v46->value.v[1]));
      }
LABEL_57:
      v47 = this;
      do
      {
        if ( v47->UpdateAnimationControllers(this: v47) )
          idEntity::BecomeActive(this: v47, flags: 4);
        v47 = v47->bindInfo.teamChain;
      }
      while ( v47 != nullptr );
      if ( v54.logIndex >= 0 )
      {
        pLog = v54.pLog;
        v49 = &v54.pLog->logEntries.list[v54.logIndex];
        v50 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v49->totalTicks;
        HIDWORD(totalTicks) = v49->parent;
        LODWORD(v52) = v50 - totalTicks;
        v49->totalTicks = v52;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
    }
  }
}


// ========================================================================
// __unwind$508557
// EA  : 0x82C44508
// RVA : 0x00C44508
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508557()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 8608 + 8448));
}


// ========================================================================
// __unwind$508558
// EA  : 0x82C44530
// RVA : 0x00C44530
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508558()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 8608 + 152));
}


// ========================================================================
// __unwind$508559
// EA  : 0x82C44558
// RVA : 0x00C44558
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508559()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 8608 + 8449));
}


// ========================================================================
// __unwind$508560
// EA  : 0x82C44580
// RVA : 0x00C44580
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508560()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 8608 + 128));
}


// ========================================================================
// __unwind$508561
// EA  : 0x82C445A8
// RVA : 0x00C445A8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508561()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 8608 + 8450));
}


// ========================================================================
// __unwind$508562
// EA  : 0x82C445D0
// RVA : 0x00C445D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508562()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 8608 + 112));
}


// ========================================================================
// __unwind$508563
// EA  : 0x82C445F8
// RVA : 0x00C445F8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508563()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 8608 + 8451));
}


// ========================================================================
// __unwind$508564
// EA  : 0x82C44620
// RVA : 0x00C44620
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508564()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 8608 + 112));
}


// ========================================================================
// ?AddTarget@idEntity@@QAAXPAV1@@Z
// EA  : 0x82C44648
// RVA : 0x00C44648
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::AddTarget(idEntity *this, idEntity *target)
{
  idEntityPtr<idAI2> *v3; // r3

  v3 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&this->targets);
  if ( target != nullptr )
    v3->spawnId.value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  else
    v3->spawnId.value = 0x1FFF;
}


// ========================================================================
// ?TouchTriggers@idEntity@@QAA_NXZ
// EA  : 0x82C446C8
// RVA : 0x00C446C8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::TouchTriggers(idEntity *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *physics; // r3
  const idClipModel *v5; // r20
  idAnimator_AF *v6; // r3
  char v7; // r11
  idAnimator_AF *v8; // r3
  unsigned __int64 index; // r11
  char v11; // r11
  bool v12; // zf
  int GatheredClipModels; // r22
  int v14; // r24
  idClipModel **v15; // r26
  const idClipModel *v16; // r28
  idEntity *v17; // r30
  signalList_t *signals; // r11
  unsigned int v19; // r11
  BOOL v20; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v22; // r30
  int v23; // r3
  __int64 totalTicks; // r11
  __int64 v25; // r9
  idPLogScope v26[2]; // [sp+50h] [-2D0h] BYREF
  idStaticList<idEntityPtr<idEntity>,8> v27; // [sp+60h] [-2C0h] BYREF
  int v28; // [sp+90h] [-290h] BYREF
  idClipModel *v29[160]; // [sp+A0h] [-280h] BYREF

  RD_EventBegin(name: "idEntity::TouchTriggers");
  LODWORD(v2) = "idEntity::TouchTriggers";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &::pLog, gMask: v2, label: v3);
  physics = this->physics;
  *((_BYTE *)&this->flags + 1) |= 0x10u;
  v5 = physics->GetClipModel(this: physics, a2: 0);
  if ( this->GetAF_2(this) != nullptr )
  {
    v6 = this->GetAF_2(this);
    if ( v6->isActive || (v7 = 0, v6->isClientAuthoritativeActive) )
      v7 = 1;
    if ( v7 != 0 || this->GetAF_2(this)->isSyncing )
    {
      v8 = this->GetAF_2(this);
      v5 = v8->physicsObj.GetClipModel(this: &v8->physicsObj, a2: 0);
    }
  }
  if ( v5 != nullptr )
  {
    v27.num = 0;
    v27.granularity = 1;
    v27.listStatic = 1;
    v27.size = 8;
    v27.list = v27.staticList;
    v27.memTag = 5;
    v27.staticList[0].spawnId.value = 0x1FFF;
    v27.staticList[1].spawnId.value = 0x1FFF;
    v27.staticList[2].spawnId.value = 0x1FFF;
    v27.staticList[3].spawnId.value = 0x1FFF;
    v27.staticList[4].spawnId.value = 0x1FFF;
    v27.staticList[5].spawnId.value = 0x1FFF;
    v27.staticList[6].spawnId.value = 0x1FFF;
    v27.staticList[7].spawnId.value = 0x1FFF;
    index = this->touchTriggersQuery.index;
    if ( (unsigned int)index < LODWORD(clientGame->clip.gatherQueryFirstSubmittedIndex)
      || (v12 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v11 = 1, !v12) )
    {
      v11 = 0;
    }
    if ( v11 != 0
      && (GatheredClipModels = idClip::GetGatheredClipModels(
                                 this: &clientGame->clip,
                                 query: &this->touchTriggersQuery,
                                 clipModelList: v29,
                                 maxCount: 128),
          v14 = 0,
          GatheredClipModels > 0) )
    {
      v15 = v29;
      while ( 1 )
      {
        v16 = *v15;
        v17 = gameLocal->entities.ptr[(*v15)->entityNumber];
        if ( v17->RespondsTo(this: v17, a2: &EV_Touch)
          || ((signals = v17->signals) != nullptr
            ? (v19 = (-signals->signal[0].num & (unsigned int)~signals->signal[0].num) >> 31)
            : (LOBYTE(v19) = 0),
              (_BYTE)v19 != 0) )
        {
          idEntity::TouchTrigger(
            this,
            touchList: (idList<idEntityPtr<idEntity>,58> *)&v27,
            trigger: v17,
            clipModel: v16);
          if ( gameLocal->entities.ptr[this->entityNumber] == nullptr )
            break;
        }
        ++v14;
        ++v15;
        if ( v14 >= GatheredClipModels )
          goto LABEL_23;
      }
      idLib::Printf(fmt: "entity was removed while touching triggers\n");
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v27);
      idPLogScope::~idPLogScope(this: v26);
      RD_EventEnd();
      return 1;
    }
    else
    {
LABEL_23:
      this->touchTriggersQuery.index = *(_QWORD *)&idClip::GatherTouchingClipModel(
                                                     this: (idClip *)&v28,
                                                     result: (idGatherQuery *)&clientGame->clip,
                                                     start: &v5->origin,
                                                     clipModel: v5,
                                                     startAxis: &v5->axis,
                                                     clipMask: 0x4000,
                                                     passEntityNumber: this->entityNumber)->world;
      idEntity::UntouchTriggers(this, touched: &v27);
      v20 = v27.num != 0;
      if ( v27.listStatic == 0 || v27.listStatic == 2 )
      {
        if ( v27.list != nullptr )
          idMem::Free(this: &mem, ptr: v27.list, align: ALIGN_16);
        v27.list = nullptr;
        v27.size = 0;
      }
      v27.num = 0;
      if ( v26[0].logIndex >= 0 )
      {
        pLog = v26[0].pLog;
        v22 = &v26[0].pLog->logEntries.list[v26[0].logIndex];
        v23 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v22->totalTicks;
        HIDWORD(totalTicks) = v22->parent;
        LODWORD(v25) = v23 - totalTicks;
        v22->totalTicks = v25;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
      return v20;
    }
  }
  else
  {
    idLib::Warning(fmt: "Entity '%s' is trying to touch triggers without a valid clipModel", this->name.data);
    idPLogScope::~idPLogScope(this: v26);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$508888
// EA  : 0x82C44A7C
// RVA : 0x00C44A7C
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508888()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 800 + 672));
}


// ========================================================================
// __unwind$508889
// EA  : 0x82C44AA4
// RVA : 0x00C44AA4
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508889()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 800 + 80));
}


// ========================================================================
// __unwind$508890
// EA  : 0x82C44ACC
// RVA : 0x00C44ACC
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_508890()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 800 + 96));
}


// ========================================================================
// ?Event_AddTarget@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C44AF8
// RVA : 0x00C44AF8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_AddTarget(idEntity *this, eventVoid *result, idEntity *target)
{
  int v6; // r29
  idGameLocal *v7; // r10
  int v8; // r30
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idList<idEntityPtr<idAI2>,5> *v12; // r31
  int num; // r11
  int size; // r10
  idEntityPtr<idAI2> *list; // r9
  int *p_value; // r11

  v6 = 0;
  if ( *(int *)&result[100] <= 0 )
  {
LABEL_9:
    v12 = (idList<idEntityPtr<idAI2>,5> *)&result[96];
    idList<idEntityPtr<idInfoGarageBay>,5>::PreAllocateWithGranularity(this: v12, newSize: v12->num + 1);
    num = v12->num;
    size = v12->size;
    list = v12->list;
    if ( num >= size )
    {
      p_value = &list[size - 1].spawnId.value;
    }
    else
    {
      v12->num = num + 1;
      p_value = &list[num].spawnId.value;
    }
    if ( target == nullptr )
    {
      *p_value = 0x1FFF;
      return this;
    }
    *p_value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  }
  else
  {
    v7 = gameLocal;
    v8 = 0;
    while ( 1 )
    {
      v9 = *(_DWORD *)(v8 + *(_DWORD *)&result[96]);
      if ( v7->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = v7->entities.ptr[v9 & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        v7 = gameLocal;
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11 == target )
        break;
      ++v6;
      v8 += 4;
      if ( v6 >= *(_DWORD *)&result[100] )
        goto LABEL_9;
    }
  }
  return this;
}


// ========================================================================
// ?Think@idEntity@@UAAXXZ
// EA  : 0x82C45788
// RVA : 0x00C45788
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Think(idEntity *this)
{
  idEntity::RunPhysics(this);
  this->UpdateFX(this);
}


// ========================================================================
// ?StartSoundShader@idEntity@@QAAHW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@E@Z
// EA  : 0x82C457D0
// RVA : 0x00C457D0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::StartSoundShader(
        idEntity *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int8 peerMask)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idPresentable *presentable; // r3
  int started; // r30
  idPLogScope v15[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idEntity::StartSoundShader");
  LODWORD(v10) = "idEntity::StartSoundShader";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: v15, pl: &pLog, gMask: v10, label: v11);
  if ( shader != nullptr )
  {
    idEntity::GetSoundEmitter(this, alloc: true);
    idEntity::UpdateSound(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    started = idPresentable::StartSoundShader(this: presentable, channel, shader, parms, peerMask);
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    return started;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$510600
// EA  : 0x82C45894
// RVA : 0x00C45894
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_510600()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$510601
// EA  : 0x82C458BC
// RVA : 0x00C458BC
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void _unwind_510601()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?StartSoundShader@idEntity@@QAAHW4soundChannel_t@@PBVidSoundShader@@HE@Z
// EA  : 0x82C458E8
// RVA : 0x00C458E8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

int __fastcall idEntity::StartSoundShader(
        idEntity *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t soundShaderFlags,
        unsigned __int8 peerMask)
{
  soundShaderParms_t v11; // [sp+50h] [-D0h] BYREF

  soundShaderParms_t::Clear(this: &v11);
  v11.soundShaderFlags = soundShaderFlags;
  return idEntity::StartSoundShader(this, channel, shader, parms: &v11, peerMask);
}


// ========================================================================
// ?SetSoundVolume@idEntity@@QAAXW4soundChannel_t@@M@Z
// EA  : 0x82C45938
// RVA : 0x00C45938
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetSoundVolume(idEntity *this, soundChannel_t channel, double volume)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    SoundEmitter->SetVolume(this: SoundEmitter, a2: channel, a3: volume);
  }
}


// ========================================================================
// ?SetSoundPitch@idEntity@@QAAXW4soundChannel_t@@M@Z
// EA  : 0x82C459B0
// RVA : 0x00C459B0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetSoundPitch(idEntity *this, soundChannel_t channel, double pitch)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    SoundEmitter->SetPitch(this: SoundEmitter, a2: channel, a3: pitch);
  }
}


// ========================================================================
// ?FadeSound@idEntity@@QAAXW4soundChannel_t@@MM_N@Z
// EA  : 0x82C45A28
// RVA : 0x00C45A28
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::FadeSound(idEntity *this, soundChannel_t channel, double to, double over, bool additive)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    ((void (__fastcall *)(idSoundEmitter *, const soundChannel_t, double, double, double))SoundEmitter->FadeSound)(
      a1: SoundEmitter,
      a2: channel,
      a3: to,
      a4: over,
      a5: 0.0);
  }
}


// ========================================================================
// ?ModifySound@idEntity@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@@Z
// EA  : 0x82C45AA8
// RVA : 0x00C45AA8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ModifySound(
        idEntity *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    SoundEmitter->ModifySound(this: SoundEmitter, a2: channel, a3: shader, a4: parms);
  }
}


// ========================================================================
// ?SetVolumeAdjustment@idEntity@@QAAXM@Z
// EA  : 0x82C45B08
// RVA : 0x00C45B08
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::SetVolumeAdjustment(idEntity *this, double adjustment)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    SoundEmitter->SetVolumeAdjustment(this: SoundEmitter, a2: adjustment);
  }
}


// ========================================================================
// ?ClearVolumeAdjustment@idEntity@@QAAXXZ
// EA  : 0x82C45B70
// RVA : 0x00C45B70
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ClearVolumeAdjustment(idEntity *this)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    SoundEmitter->ClearVolumeAdjustment(this: SoundEmitter);
  }
}


// ========================================================================
// ?Activate@idEntity@@QAAXPAV1@@Z
// EA  : 0x82C45BC8
// RVA : 0x00C45BC8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::Activate(idEntity *this, idEntity *activator)
{
  int valueInteger; // r11
  char *data; // r26
  int GameMs; // r3
  char *v7; // r31
  int v8; // r3
  signalList_t *signals; // r11
  idScriptObject *v10; // r3
  char **SpawnId; // r3
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  idPresentable *presentable; // r4
  int v17; // [sp+8h] [-1D8h]
  int v18; // [sp+Ch] [-1D4h]
  int v19; // [sp+10h] [-1D0h]
  int v20; // [sp+14h] [-1CCh]
  int v21; // [sp+18h] [-1C8h]
  idPresentable *v22; // [sp+1Ch] [-1C4h]
  char v23; // [sp+50h] [-190h] BYREF
  idScriptFunction v24; // [sp+60h] [-180h] BYREF

  valueInteger = g_debugTriggers.valueInteger;
  if ( g_debugTriggers.valueInteger != 0 )
  {
    data = this->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d): '%s' idEntity::Activate\n", GameMs, data);
    valueInteger = g_debugTriggers.valueInteger;
  }
  if ( (*(_BYTE *)&this->flags & 8) != 0 )
  {
    idEntity::LeaveDormancy(this);
    signals = this->signals;
    if ( signals != nullptr )
      signals = (signalList_t *)((-signals->signal[2].num & (unsigned int)~signals->signal[2].num) >> 31);
    if ( (_BYTE)signals != 0 )
      idEntity::Signal(this, signalnum: SIG_TRIGGER);
    this->OnActivate(this, a2: activator);
    v10 = this->GetScriptObject_2(this);
    if ( idScriptObject::HasObject(this: v10) )
    {
      idScriptFunction::idScriptFunction(this: &v24);
      idScriptFunction::SetFunction(
        this: &v24,
        ent: this,
        functionName: "onTrigger",
        returnType: ev_void,
        numParms: 1,
        8,
        "activator");
      if ( idScriptFunction::GetFunction(this: &v24) != nullptr )
      {
        idScriptFunction::SetArg_Entity(this: &v24, argNum: 0, ent: activator);
        idScriptFunction::CallFunction(this: &v24, defer: true);
      }
    }
    SpawnId = (char **)idGameLocal::GetSpawnId(
                         this: (idGameLocal *)&v23,
                         result: (idSpawnId *)gameLocal,
                         ent: activator);
    idEntity::SendNotify_OnActivate(this, activator: *SpawnId);
    presentable = this->presentable;
    if ( presentable != nullptr )
      idClientGame::MarkPresentableSerialized(
        this: clientGame,
        presentable,
        serialized: true,
        deleted: false,
        a5: v15,
        a6: v14,
        a7: v13,
        a8: v12,
        a9: v17,
        a10: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22);
  }
  else if ( valueInteger != 0 )
  {
    v7 = this->name.data;
    v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d): '%s' idEntity::Activate - isActivatable = false\n", v8, v7);
  }
}


// ========================================================================
// ?Use@idEntity@@UAA_NPAV1@W4usableState_t@@@Z
// EA  : 0x82C45D90
// RVA : 0x00C45D90
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

BOOL __fastcall idEntity::Use(idEntity *this, idEntity *activator, const usableState_t usable)
{
  char **SpawnId; // r3
  idScriptObject *v7; // r3
  __int64 v8; // r11
  __int64 v10; // [sp+60h] [-180h] BYREF
  idScriptFunction v11; // [sp+70h] [-170h] BYREF

  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v10, result: (idSpawnId *)gameLocal, ent: activator);
  idEntity::SendNotify_OnUse(this, user: *SpawnId);
  v7 = this->GetScriptObject_2(this);
  if ( !idScriptObject::HasObject(this: v7) )
    return false;
  idScriptFunction::idScriptFunction(this: &v11);
  idScriptFunction::SetFunction(
    this: &v11,
    ent: this,
    functionName: "use",
    returnType: ev_integer,
    numParms: 2,
    8,
    "activator",
    4);
  if ( idScriptFunction::GetFunction(this: &v11) == nullptr )
    return false;
  idScriptFunction::SetArg_Entity(this: &v11, argNum: 0, ent: activator);
  LODWORD(v8) = usable;
  v10 = v8;
  idScriptFunction::SetArg_Float(this: &v11, argNum: 1, value: (float)v8);
  idScriptFunction::CallFunction(this: &v11, defer: false);
  return *gameLocal->program.returnDef->value.value.ip != 0;
}


// ========================================================================
// ?ActivateTargets@idEntity@@UAAXPAV1@@Z
// EA  : 0x82C45EB0
// RVA : 0x00C45EB0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __fastcall idEntity::ActivateTargets(idEntity *this, idEntity *activator)
{
  int v4; // r29
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  char **SpawnId; // r3
  char v10; // [sp+50h] [-40h] BYREF

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      if ( v8 != nullptr )
        idEntity::Activate(this: v8, activator);
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v10, result: (idSpawnId *)gameLocal, ent: activator);
  idEntity::SendNotify_OnActivateTargets(this, activator: *SpawnId);
}


// ========================================================================
// ?Event_Activate@idEntity@@AAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82C45F80
// RVA : 0x00C45F80
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_Activate(idEntity *this, idEntity *result, idEntity *activator)
{
  idEntity::Activate(this: result, activator);
  return this;
}


// ========================================================================
// ?Event_StartSoundShader@idEntity@@AAA?AVeventFloat@@PBVidSoundShader@@W4soundChannel_t@@@Z
// EA  : 0x82C45FB8
// RVA : 0x00C45FB8
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_StartSoundShader(
        idEntity *this,
        idEntity *result,
        const idSoundShader *shader,
        soundChannel_t channel)
{
  __int64 v9; // [sp+50h] [-E0h]
  soundShaderParms_t v10; // [sp+60h] [-D0h] BYREF

  if ( shader != nullptr && shader->GetDeclInfo(this: shader) == &idSoundShader::resourceList )
  {
    soundShaderParms_t::Clear(this: &v10);
    v10.soundShaderFlags = 0;
    v9 = __PAIR64__(
           &unk_82390000,
           idEntity::StartSoundShader(this: result, channel, shader, parms: &v10, peerMask: 0xFFu));
    eventFloat::eventFloat((eventFloat *)this, f: (float)((float)v9 * (float)0.001));
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idEntity::Event_StartSoundShader",
      decl: shader,
      declInfo: &idSoundShader::resourceList);
    eventFloat::eventFloat((eventFloat *)this, f: 0.0);
    return this;
  }
}


// ========================================================================
// ?Event_PlayVoiceOver@idEntity@@AAA?AVeventFloat@@PBVidDeclVoiceOver@@W4soundChannel_t@@PBD@Z
// EA  : 0x82C46090
// RVA : 0x00C46090
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

idEntity *__fastcall idEntity::Event_PlayVoiceOver(
        idEntity *this,
        idEntity *result,
        const idDeclVoiceOver *voToPlay,
        soundChannel_t channel,
        const char *talkerID)
{
  int num; // r4
  double v11; // fp31
  int v12; // r30
  const idVoiceTrack *v13; // r11
  const idSoundShader *soundShader; // r25
  float v15; // r11
  double v16; // fp1
  _QWORD v18[2]; // [sp+50h] [-F0h] BYREF
  soundShaderParms_t v19; // [sp+60h] [-E0h] BYREF

  if ( voToPlay != nullptr && voToPlay->GetDeclInfo(this: voToPlay) == &idDeclVoiceOver::resourceList )
  {
    num = voToPlay->tracks.num;
    v11 = 0.0;
    if ( num > 0 )
    {
      v12 = 0;
      if ( num > 1 && (v12 = idRandom2::RandomInt(this: &clientGame->random, max: num)) < 0
        || v12 >= voToPlay->tracks.num )
      {
        v13 = nullptr;
      }
      else
      {
        v13 = voToPlay->tracks.list[v12];
      }
      soundShader = v13->soundShader;
      soundShaderParms_t::Clear(this: &v19);
      v19.soundShaderFlags = 0;
      v18[0] = __PAIR64__(
                 &unk_82390000,
                 idEntity::StartSoundShader(this: result, channel, shader: soundShader, parms: &v19, peerMask: 0xFFu));
      v11 = (float)((float)v18[0] * (float)0.001);
      idStrId::Set(this: (idStrId *)v18, key: talkerID);
      v15 = *(float *)&result->presentable;
      if ( v15 == 0.0 )
      {
        idEntity::InitPresentableInternal(this: result);
        v15 = *(float *)&result->presentable;
      }
      idGameLocal::PlayedVoiceOver(
        this: gameLocal,
        whoStartedMe: nullptr,
        target: (idPresentable *)LODWORD(v15),
        vo: voToPlay,
        voiceTrackIndex: v12,
        whoStartedMeText: (idStrId *)v18);
    }
    v16 = v11;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idEntity::Event_PlayVoiceOver",
      decl: voToPlay,
      declInfo: &idDeclVoiceOver::resourceList);
    v16 = 0.0;
  }
  eventFloat::eventFloat((eventFloat *)this, f: v16);
  return this;
}


// ========================================================================
// `dynamic initializer for 'g_showDormant''
// EA  : 0x83376A98
// RVA : 0x01376A98
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showDormant__()
{
  idCVar::idCVar(
    this: &g_showDormant,
    name: "g_showDormant",
    value: "0",
    flags: 1,
    description: "if true, show entities entering and leaving dormancy.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showDormant__);
}


// ========================================================================
// `dynamic initializer for 'g_debugDormancy''
// EA  : 0x83376AF0
// RVA : 0x01376AF0
// PDB : w:\tech5\tungsten\game\entities\entity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugDormancy__()
{
  idCVar::idCVar(
    this: &g_debugDormancy,
    name: "g_debugDormancy",
    value: "0",
    flags: 1,
    description: "show when entities begin and end dormancy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugDormancy__);
}

