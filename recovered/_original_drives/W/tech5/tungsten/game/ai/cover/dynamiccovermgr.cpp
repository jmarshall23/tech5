
// ========================================================================
// ?FindCoverForAAS@idDynamicCoverMgr@@ABAHPBVidAAS2@@@Z
// EA  : 0x82A8F130
// RVA : 0x00A8F130
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

int __fastcall idDynamicCoverMgr::FindCoverForAAS(idDynamicCoverMgr *this, const idAAS2 *aas)
{
  int v4; // r31

  v4 = 0;
  if ( this->list.num <= 0 )
    return -1;
  while ( idGameLocal::GetAAS(this: gameLocal, idx: v4) != aas )
  {
    if ( ++v4 >= this->list.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?Shutdown@idDynamicCoverMgr@@QAAXXZ
// EA  : 0x82A8F198
// RVA : 0x00A8F198
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::Shutdown(idDynamicCoverMgr *this)
{
  int v2; // r29
  int v3; // r30
  idDynamicCover **list; // r4

  v2 = 0;
  if ( this->list.num > 0 )
  {
    v3 = 0;
    do
    {
      this->FreeCover(this, a2: this->list.list[v3]);
      ++v2;
      this->list.list[v3++] = nullptr;
    }
    while ( v2 < this->list.num );
  }
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ?AppendUsableCover@idDynamicCoverMgr@@QBAHPBVidEntity@@PBVidAAS2@@AAV?$idList@VidAICover@@$04@@@Z
// EA  : 0x82A8F240
// RVA : 0x00A8F240
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::AppendUsableCover(
        idDynamicCoverMgr *this,
        const idEntity *owner,
        const idAAS2 *aas,
        idList<idAICover,5> *coverList)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    idAIEvent::IsTouching(this: (idResource *)this->list.list[CoverForAAS]);
}


// ========================================================================
// ?NumCoverPoints@idDynamicCoverMgr@@UBAHPBVidAAS2@@@Z
// EA  : 0x82A8F2A0
// RVA : 0x00A8F2A0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

bfx::Space *__fastcall idDynamicCoverMgr::NumCoverPoints(idDynamicCoverMgr *this, const idAAS2 *aas)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    return idScriptObject::GetTypeDef(this: (bfx::Planner3D *)this->list.list[CoverForAAS]);
  else
    return nullptr;
}


// ========================================================================
// ?GetCoverPoint@idDynamicCoverMgr@@UBAPBUaas2Cover_t@@PBVidAAS2@@H@Z
// EA  : 0x82A8F300
// RVA : 0x00A8F300
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

idDynamicCover::coverInfo_t *__fastcall idDynamicCoverMgr::GetCoverPoint(
        idDynamicCoverMgr *this,
        const idAAS2 *aas,
        int index)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    return idDynamicCover::GetCoverPoint(this: this->list.list[CoverForAAS], index);
  else
    return nullptr;
}


// ========================================================================
// ?GetReserver@idDynamicCoverMgr@@UBAPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A8F360
// RVA : 0x00A8F360
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

const idEntity *__fastcall idDynamicCoverMgr::GetReserver(idDynamicCoverMgr *this, const idAAS2 *aas, int index)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    return idDynamicCover::GetReserver(this: this->list.list[CoverForAAS], index);
  else
    return nullptr;
}


// ========================================================================
// ?Reserve@idDynamicCoverMgr@@UAAXPBVidAAS2@@HPBVidEntity@@@Z
// EA  : 0x82A8F3C0
// RVA : 0x00A8F3C0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::Reserve(idDynamicCoverMgr *this, const idAAS2 *aas, int index, const idEntity *ent)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    idDynamicCover::Reserve(this: this->list.list[CoverForAAS], index, ent);
}


// ========================================================================
// ?Unreserve@idDynamicCoverMgr@@UAAXPBVidAAS2@@H@Z
// EA  : 0x82A8F408
// RVA : 0x00A8F408
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::Unreserve(idDynamicCoverMgr *this, const idAAS2 *aas, int index)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    idDynamicCover::Unreserve(this: this->list.list[CoverForAAS], index);
}


// ========================================================================
// ?GetUsableTime@idDynamicCoverMgr@@UBAHPBVidAAS2@@H@Z
// EA  : 0x82A8F460
// RVA : 0x00A8F460
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

int __fastcall idDynamicCoverMgr::GetUsableTime(idDynamicCoverMgr *this, const idAAS2 *aas, int index)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    return idDynamicCover::GetUsableTime(this: this->list.list[CoverForAAS], index);
  else
    return 0;
}


// ========================================================================
// ?SetUsableTime@idDynamicCoverMgr@@UAAXPBVidAAS2@@HH@Z
// EA  : 0x82A8F4C0
// RVA : 0x00A8F4C0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::SetUsableTime(idDynamicCoverMgr *this, const idAAS2 *aas, int index, int t)
{
  int CoverForAAS; // r3

  CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this, aas);
  if ( CoverForAAS >= 0 )
    idDynamicCover::SetUsableTime(this: this->list.list[CoverForAAS], index, t);
}


// ========================================================================
// ??0idDynamicCoverMgr@@QAA@XZ
// EA  : 0x82A8F510
// RVA : 0x00A8F510
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

idDynamicCoverMgr *__fastcall idDynamicCoverMgr::idDynamicCoverMgr(idDynamicCoverMgr *this)
{
  this->isInitializedFlag = false;
  this->__vftable = (idDynamicCoverMgr_vtbl *)&idDynamicCoverMgr::`vftable';
  this->list.list = nullptr;
  this->list.granularity = 0;
  this->list.memTag = 5;
  this->list.listStatic = 0;
  this->list.size = 0;
  this->list.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
  return this;
}


// ========================================================================
// __unwind$487985
// EA  : 0x82A8F584
// RVA : 0x00A8F584
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void _unwind_487985()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDynamicCoverMgr@@UAA@XZ
// EA  : 0x82A8F5B8
// RVA : 0x00A8F5B8
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::~idDynamicCoverMgr(idDynamicCoverMgr *this)
{
  this->__vftable = (idDynamicCoverMgr_vtbl *)&idDynamicCoverMgr::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->list);
  this->__vftable = (idDynamicCoverMgr_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$488010
// EA  : 0x82A8F610
// RVA : 0x00A8F610
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void _unwind_488010()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@idDynamicCoverMgr@@QAAXXZ
// EA  : 0x82A8F638
// RVA : 0x00A8F638
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::Init(idDynamicCoverMgr *this)
{
  int v1; // r30
  int v3; // r28
  int v4; // r29
  idList<idDynamicCover *,5> *p_list; // r28
  idDynamicCoverMgr_vtbl *v6; // r27
  idAAS2 *AAS; // r3
  int v8; // [sp+50h] [-40h] BYREF

  v1 = 0;
  v3 = 0;
  if ( this->list.num > 0 )
  {
    v4 = 0;
    do
    {
      this->FreeCover(this, a2: this->list.list[v4]);
      ++v3;
      this->list.list[v4++] = nullptr;
    }
    while ( v3 < this->list.num );
  }
  p_list = &this->list;
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( p_list->list != nullptr )
      idMem::Free(this: &mem, ptr: p_list->list, align: ALIGN_16);
    p_list->list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
  if ( idGameLocal::NumAAS(this: gameLocal) > 0 )
  {
    do
    {
      v6 = this->__vftable;
      AAS = idGameLocal::GetAAS(this: gameLocal, idx: v1);
      v8 = (int)v6->AllocCover(this, a2: AAS);
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->list,
        obj: (const encounterGroupRole_t *)&v8);
      ++v1;
    }
    while ( v1 < idGameLocal::NumAAS(this: gameLocal) );
  }
  this->isInitializedFlag = true;
}


// ========================================================================
// ?UpdateUsable@idDynamicCoverMgr@@QAAXPBVidEntity@@H@Z
// EA  : 0x82A8F748
// RVA : 0x00A8F748
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::UpdateUsable(idDynamicCoverMgr *this, const idEntity *owner, int curTime)
{
  int v6; // r31
  int v7; // r28
  const idAAS2 *v8; // r30
  idDynamicCover *v9; // r24
  idDynamicCover_vtbl *v10; // r30
  idAAS2 *AAS; // r3

  if ( !this->isInitializedFlag )
    idDynamicCoverMgr::Init(this);
  v6 = 0;
  if ( this->list.num > 0 )
  {
    v7 = 0;
    do
    {
      if ( owner->GetAAS(this: owner) == nullptr
        || (v8 = idGameLocal::GetAAS(this: gameLocal, idx: v6), owner->GetAAS(this: owner) == v8) )
      {
        v9 = this->list.list[v7];
        v10 = v9->__vftable;
        AAS = idGameLocal::GetAAS(this: gameLocal, idx: v6);
        v10->UpdateUsable(this: v9, a2: owner, a3: AAS, a4: curTime);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->list.num );
  }
}


// ========================================================================
// ?ShowDynamicCover@idDynamicCoverMgr@@SAXABVidVec3@@M@Z
// EA  : 0x82A8F9A0
// RVA : 0x00A8F9A0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __fastcall idDynamicCoverMgr::ShowDynamicCover(const idVec3 *point, double dist)
{
  const idAAS2 *AAS; // r27
  idGameLocal *v5; // r9
  double v6; // fp31
  idLinkList<idVehicle> *next; // r11
  idVehicle *owner; // r30
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp10
  double v12; // fp6
  idDynamicCoverMgr *v13; // r3
  idDynamicCoverMgr *v14; // r29
  int CoverForAAS; // r3
  idLinkList<idVehicle> *v16; // r11
  idLinkList<idActor> *v17; // r11
  idAI2 *v18; // r30
  idAI2 *v19; // r3
  idPhysics *v20; // r3
  float *v21; // r3
  double v22; // fp10
  double v23; // fp6
  idDynamicCoverMgr *v24; // r3
  idDynamicCoverMgr *v25; // r29
  int v26; // r3
  idLinkList<idActor> *v27; // r11
  int v28; // r28
  int v29; // r29
  idAICover *v30; // r30
  const aas2Cover_t *CoverPoint; // r4
  idStaticList<idAICover,128> v32; // [sp+50h] [-650h] BYREF

  AAS = idGameLocal::GetAAS(this: gameLocal, typeName: aas_test.valueString.data, load: true);
  idStaticList<idAICover,128>::idStaticList<idAICover,128>(this: &v32);
  v5 = gameLocal;
  v6 = (float)((float)dist * (float)dist);
  next = gameLocal->vehicleEntities.next;
  if ( next != nullptr && next != gameLocal->vehicleEntities.head )
  {
    owner = next->owner;
    if ( owner != nullptr )
    {
      do
      {
        Physics = idEntity::GetPhysics(this: owner);
        v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v11 = (float)(v10[1] - point->y);
        v12 = (float)(v10[2] - point->z);
        if ( (float)((float)((float)v12 * (float)v12)
                   + (float)((float)((float)(*v10 - point->x) * (float)(*v10 - point->x))
                           + (float)((float)v11 * (float)v11))) <= v6 )
        {
          v13 = owner->GetDynamicCoverMgr(this: owner);
          v14 = v13;
          if ( v13 != nullptr )
          {
            CoverForAAS = idDynamicCoverMgr::FindCoverForAAS(this: v13, aas: AAS);
            if ( CoverForAAS >= 0 )
              idAIEvent::IsTouching(this: (idResource *)v14->list.list[CoverForAAS]);
          }
        }
        v16 = owner->controlNode.next;
        if ( v16 == nullptr || v16 == owner->controlNode.head )
          owner = nullptr;
        else
          owner = v16->owner;
      }
      while ( owner != nullptr );
      v5 = gameLocal;
    }
  }
  v17 = v5->actorEntities.next;
  if ( v17 != nullptr && v17 != v5->actorEntities.head )
  {
    v18 = (idAI2 *)v17->owner;
    while ( v18 != nullptr )
    {
      v19 = idAI2::CastTo(c: v18);
      if ( v19 != nullptr && (*(_BYTE *)&v19->aiEditable.behaviors.decl->dynamicCoverCaps & 0x20) != 0 )
      {
        v20 = idEntity::GetPhysics(this: v18);
        v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
        v22 = (float)(v21[1] - point->y);
        v23 = (float)(v21[2] - point->z);
        if ( (float)((float)((float)v23 * (float)v23)
                   + (float)((float)((float)(*v21 - point->x) * (float)(*v21 - point->x))
                           + (float)((float)v22 * (float)v22))) <= v6 )
        {
          v24 = v18->GetDynamicCoverMgr(this: v18);
          v25 = v24;
          if ( v24 != nullptr )
          {
            v26 = idDynamicCoverMgr::FindCoverForAAS(this: v24, aas: AAS);
            if ( v26 >= 0 )
              idAIEvent::IsTouching(this: (idResource *)v25->list.list[v26]);
          }
        }
      }
      v27 = v18->actorNode.next;
      if ( v27 == nullptr || v27 == v18->actorNode.head )
        v18 = nullptr;
      else
        v18 = (idAI2 *)v27->owner;
    }
  }
  v28 = 0;
  if ( v32.num > 0 )
  {
    v29 = 0;
    do
    {
      v30 = &v32.list[v29];
      CoverPoint = idAICover::GetCoverPoint(this: &v32.list[v29]);
      if ( CoverPoint != nullptr )
        AAS->DrawCoverPoint(this: (idAAS2 *)AAS, a2: CoverPoint, a3: v30->coverIndex);
      ++v28;
      ++v29;
    }
    while ( v28 < v32.num );
  }
  idStaticList<idAICover,128>::~idStaticList<idAICover,128>(this: &v32);
}


// ========================================================================
// __unwind$488196
// EA  : 0x82A8FC78
// RVA : 0x00A8FC78
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void _unwind_488196()
{
  int v0; // r12

  idStaticList<idAICover,128>::~idStaticList<idAICover,128>(this: (idStaticList<idAICover,128> *)(v0 - 1696 + 80));
}


// ========================================================================
// `dynamic initializer for 'ai_showDynamicCover''
// EA  : 0x833690E0
// RVA : 0x013690E0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showDynamicCover__()
{
  idCVar::idCVar(
    this: &ai_showDynamicCover,
    name: "ai_showDynamicCover",
    value: "0",
    flags: 4,
    description: "draw dynamic cover within this distance of the player, 0 = don't draw any",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showDynamicCover__);
}

