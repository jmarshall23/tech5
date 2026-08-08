
// ========================================================================
// ?GetClipForAAS@idDynamicCover@@KAPBVidClipModel@@PBVidAAS2@@@Z
// EA  : 0x82A8E428
// RVA : 0x00A8E428
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

const idClipModel *__fastcall idDynamicCover::GetClipForAAS(const idClipModel *aas)
{
  idBounds *v1; // r30
  idClientGame *v2; // r31
  idClipModel *clip24x24x96; // r29
  idClipModel *clip48x48x96; // r31

  if ( aas != nullptr )
  {
    v1 = (idBounds *)(((int (__fastcall *)(const idClipModel *))aas->__vftable[5].dtr_idClipModel)(a1: aas) + 100);
    v2 = clientGame;
    clip24x24x96 = clientGame->clip.clip24x24x96;
    if ( (unsigned __int8)idBounds::Compare(this: v1, a: &clip24x24x96->bounds) != 0 )
    {
      return clip24x24x96;
    }
    else if ( (unsigned __int8)idBounds::Compare(this: v1, a: &v2->clip.clip32x32x96->bounds) != 0 )
    {
      return v2->clip.clip48x48x96;
    }
    else
    {
      clip48x48x96 = v2->clip.clip48x48x96;
      return (unsigned __int8)idBounds::Compare(this: v1, a: &clip48x48x96->bounds) == 0 ? nullptr : clip48x48x96;
    }
  }
  return aas;
}


// ========================================================================
// ?GetPropNameForAAS@idDynamicCover@@KAPBDPBVidAAS2@@@Z
// EA  : 0x82A8E4D8
// RVA : 0x00A8E4D8
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

const char *__fastcall idDynamicCover::GetPropNameForAAS(const idAAS2 *aas)
{
  idBounds *p_boundingBox; // r28
  int v2; // r29
  idBounds *p_bounds; // r30

  if ( (_S18_5 & 1) == 0 )
  {
    aasProperties[0].bounds.b[0].x = -12.0;
    aasProperties[0].bounds.b[0].y = -12.0;
    aasProperties[0].bounds.b[0].z = 0.0;
    aasProperties[0].propName = "_cover24";
    aasProperties[0].bounds.b[1].x = 12.0;
    _S18_5 |= 1u;
    aasProperties[0].bounds.b[1].y = 12.0;
    aasProperties[1].propName = "_cover32";
    aasProperties[0].bounds.b[1].z = 96.0;
    aasProperties[2].propName = "_cover48";
    aasProperties[1].bounds.b[0].x = -16.0;
    aasProperties[1].bounds.b[0].y = -16.0;
    aasProperties[1].bounds.b[0].z = 0.0;
    aasProperties[1].bounds.b[1].x = 16.0;
    aasProperties[1].bounds.b[1].y = 16.0;
    aasProperties[1].bounds.b[1].z = 96.0;
    aasProperties[2].bounds.b[0].x = -24.0;
    aasProperties[2].bounds.b[0].y = -24.0;
    aasProperties[2].bounds.b[0].z = 0.0;
    aasProperties[2].bounds.b[1].x = 24.0;
    aasProperties[2].bounds.b[1].y = 24.0;
    aasProperties[2].bounds.b[1].z = 96.0;
  }
  p_boundingBox = &aas->GetSettings(this: aas)->boundingBox;
  v2 = 0;
  p_bounds = &aasProperties[0].bounds;
  while ( (unsigned __int8)idBounds::Compare(this: p_boundingBox, a: p_bounds) == 0 )
  {
    p_bounds = (idBounds *)((char *)p_bounds + 28);
    ++v2;
    if ( (int)p_bounds >= (int)&ai_debugDynamicCover )
      return "_info";
  }
  return aasProperties[v2].propName;
}


// ========================================================================
// ?GetCoverPoint@idDynamicCover@@QAAPAUaas2Cover_t@@H@Z
// EA  : 0x82A8E620
// RVA : 0x00A8E620
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

idDynamicCover::coverInfo_t *__fastcall idDynamicCover::GetCoverPoint(idDynamicCover *this, int index)
{
  if ( index < 0 || index >= this->numCover )
    return nullptr;
  else
    return &this->coverInfo.list[index];
}


// ========================================================================
// ?MarkAllUsable@idDynamicCover@@MAAXXZ
// EA  : 0x82A8E658
// RVA : 0x00A8E658
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __fastcall idDynamicCover::MarkAllUsable(idDynamicCover *this)
{
  int v1; // r9
  int v2; // r10
  idDynamicCover::coverInfo_t *v3; // r11

  v1 = 0;
  if ( this->numCover > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &this->coverInfo.list[v2++];
      v3->cover.flags &= ~0x2000u;
    }
    while ( v1 < this->numCover );
  }
}


// ========================================================================
// ?GetReserver@idDynamicCover@@QBAPBVidEntity@@H@Z
// EA  : 0x82A8E6A8
// RVA : 0x00A8E6A8
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

const idEntity *__fastcall idDynamicCover::GetReserver(idDynamicCover *this, int index)
{
  if ( index < 0 || index >= this->numCover )
    return nullptr;
  else
    return gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: this->coverInfo.list[index].cover.reservedBy);
}


// ========================================================================
// ?Reserve@idDynamicCover@@QAAXHPBVidEntity@@@Z
// EA  : 0x82A8E6F8
// RVA : 0x00A8E6F8
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __fastcall idDynamicCover::Reserve(idDynamicCover *this, const int index, const idEntity *ent)
{
  char v3; // [sp+50h] [-20h] BYREF

  this->coverInfo.list[index].cover.reservedBy = idGameLocal::GetSpawnId(
                                                   this: (idGameLocal *)&v3,
                                                   result: (idSpawnId *)gameLocal,
                                                   ent)->value;
}


// ========================================================================
// ?Unreserve@idDynamicCover@@QAAXH@Z
// EA  : 0x82A8E758
// RVA : 0x00A8E758
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __fastcall idDynamicCover::Unreserve(idDynamicCover *this, const int index)
{
  this->coverInfo.list[index].cover.reservedBy = 0x1FFF;
}


// ========================================================================
// ?GetUsableTime@idDynamicCover@@QBAHH@Z
// EA  : 0x82A8E778
// RVA : 0x00A8E778
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

int __fastcall idDynamicCover::GetUsableTime(idDynamicCover *this, int index)
{
  if ( index < 0 || index >= this->numCover )
    return -1;
  else
    return this->coverInfo.list[index].cover.usableTime;
}


// ========================================================================
// ?SetUsableTime@idDynamicCover@@QAAXHH@Z
// EA  : 0x82A8E7B0
// RVA : 0x00A8E7B0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __fastcall idDynamicCover::SetUsableTime(idDynamicCover *this, const int index, int t)
{
  this->coverInfo.list[index].cover.usableTime = t;
}


// ========================================================================
// ?MarkAllUnusable@idDynamicCover@@MAAXXZ
// EA  : 0x82A8E7D0
// RVA : 0x00A8E7D0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDynamicCover::MarkAllUnusable(idDynamicCover *this)
{
  __int64 v1; // r26
  int v2; // r24
  int v3; // r7
  idDynamicCover::coverInfo_t *v4; // r11
  unsigned __int64 v5; // r6
  __int64 v6; // r9
  unsigned __int64 index; // r11
  int v8; // r10
  unsigned int v9; // r11
  char v10; // r11
  bool v11; // zf
  __int64 v12; // r9
  unsigned __int64 v13; // r11
  int v14; // r10
  unsigned int v15; // r11
  char v16; // r11
  unsigned int v17; // r4

  LODWORD(v1) = 0;
  v2 = 0;
  if ( this->numCover > 0 )
  {
    v3 = 0;
    HIDWORD(v1) = 377216;
    do
    {
      this->coverInfo.list[v3].cover.flags |= 0x2000u;
      this->coverInfo.list[v3].cover.reservedBy = 0x1FFF;
      v4 = &this->coverInfo.list[v3];
      v5 = idCollisionQuery::finalResultsFirstSubmittedOffset;
      *(_QWORD *)(&this - 1) = idCollisionQuery::finalResultsLastSubmittedOffset;
      v6 = *(_QWORD *)((char *)&clientGame->clip.world + HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset));
      index = v4->contentsQuery.index;
      if ( (unsigned int)index < (unsigned int)v6
        || (v6 = *(_QWORD *)(HIDWORD(index) + 377216), (unsigned int)index > (unsigned int)v6) )
      {
        v10 = 0;
      }
      else
      {
        v8 = 8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(index);
        v6 = *(_QWORD *)(v8 + 278920);
        v9 = *(_DWORD *)(v8 + 278924);
        if ( v9 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v11 = v9 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v10 = 1, !v11) )
        {
          v10 = 0;
        }
      }
      if ( v10 != 0 )
      {
        *(_QWORD *)(v3 * 72 + *(_DWORD *)(HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset) + 12) + 56) = v1;
        HIDWORD(v6) = clientGame;
        v5 = idCollisionQuery::finalResultsFirstSubmittedOffset;
        *(_QWORD *)(&this - 1) = idCollisionQuery::finalResultsLastSubmittedOffset;
      }
      v12 = *(_QWORD *)(HIDWORD(v6) + 10688 + HIDWORD(v5));
      v13 = this->coverInfo.list[v3].translationQuery.index;
      if ( (unsigned int)v13 < (unsigned int)v12
        || (v12 = *(_QWORD *)(HIDWORD(v13) + 377216), (unsigned int)v13 > (unsigned int)v12) )
      {
        v16 = 0;
      }
      else
      {
        v14 = 8 * ((v13 & 0xFFF) + ((2 * v13) & 0x1FFE)) + HIDWORD(v13);
        v12 = *(_QWORD *)(v14 + 278920);
        v15 = *(_DWORD *)(v14 + 278924);
        if ( v15 < (unsigned int)v5 || (v11 = v15 < v17, v16 = 1, !v11) )
          v16 = 0;
      }
      if ( v16 != 0 )
        *(_QWORD *)HIDWORD(v12) = v1;
      ++v2;
      ++v3;
    }
    while ( v2 < this->numCover );
  }
}


// ========================================================================
// ??1idDynamicCover@@UAA@XZ
// EA  : 0x82A8E978
// RVA : 0x00A8E978
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __fastcall idDynamicCover::~idDynamicCover(idDynamicCover *this)
{
  __int64 v2; // r28
  int v3; // r26
  int v4; // r5
  unsigned __int64 index; // r11
  __int64 v6; // r9
  int v7; // r10
  unsigned int v8; // r11
  char v9; // r11
  bool v10; // zf
  unsigned __int64 v11; // r11
  __int64 v12; // r9
  int v13; // r10
  unsigned int v14; // r11
  char v15; // r11
  idDynamicCover::coverInfo_t *list; // r4
  idClipQuery *p_contentsQuery; // [sp+50h] [-50h]
  idClipQuery *p_translationQuery; // [sp+50h] [-50h]

  this->__vftable = (idDynamicCover_vtbl *)&idDynamicCover::`vftable';
  LODWORD(v2) = 0;
  v3 = 0;
  if ( this->numCover > 0 )
  {
    v4 = 0;
    HIDWORD(v2) = &idDeclReachIK::resourceList.hashTable[243];
    do
    {
      p_contentsQuery = &this->coverInfo.list[v4].contentsQuery;
      index = p_contentsQuery->index;
      v6 = *(_QWORD *)(HIDWORD(p_contentsQuery->index) + 377208);
      if ( LODWORD(this->coverInfo.list[v4].contentsQuery.index) < (unsigned int)v6
        || (v6 = *(_QWORD *)(HIDWORD(index) + 377216), (unsigned int)index > (unsigned int)v6) )
      {
        v9 = 0;
      }
      else
      {
        v7 = 8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(index);
        v6 = *(_QWORD *)(v7 + 278920);
        v8 = *(_DWORD *)(v7 + 278924);
        if ( v8 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v10 = v8 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v9 = 1, !v10) )
        {
          v9 = 0;
        }
      }
      if ( v9 != 0 )
        *(_QWORD *)HIDWORD(v6) = v2;
      p_translationQuery = &this->coverInfo.list[v4].translationQuery;
      v11 = p_translationQuery->index;
      v12 = *(_QWORD *)(HIDWORD(p_translationQuery->index) + 377208);
      if ( LODWORD(this->coverInfo.list[v4].translationQuery.index) < (unsigned int)v12
        || (v12 = *(_QWORD *)(HIDWORD(v11) + 377216), (unsigned int)v11 > (unsigned int)v12) )
      {
        v15 = 0;
      }
      else
      {
        v13 = 8 * ((v11 & 0xFFF) + ((2 * v11) & 0x1FFE)) + HIDWORD(v11);
        v12 = *(_QWORD *)(v13 + 278920);
        v14 = *(_DWORD *)(v13 + 278924);
        if ( v14 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v10 = v14 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v15 = 1, !v10) )
        {
          v15 = 0;
        }
      }
      if ( v15 != 0 )
        *(_QWORD *)HIDWORD(v12) = v2;
      ++v3;
      ++v4;
    }
    while ( v3 < this->numCover );
  }
  if ( this->coverInfo.listStatic == 0 || this->coverInfo.listStatic == 2 )
  {
    list = this->coverInfo.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->coverInfo.list = nullptr;
    this->coverInfo.size = 0;
  }
  this->coverInfo.num = 0;
  this->__vftable = (idDynamicCover_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$488436
// EA  : 0x82A8EB60
// RVA : 0x00A8EB60
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void _unwind_488436()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 160 + 180));
}


// ========================================================================
// ??0idDynamicCover@@QAA@H@Z
// EA  : 0x82A8EDD0
// RVA : 0x00A8EDD0
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

idDynamicCover *__fastcall idDynamicCover::idDynamicCover(idDynamicCover *this, const int _numCover)
{
  unsigned __int64 v4; // r30
  idList<idDynamicCover::coverInfo_t,5> *p_coverInfo; // r28
  int v6; // r26
  idDynamicCover::coverInfo_t *v7; // r11
  idDynamicCover::coverInfo_t v9[2]; // [sp+60h] [-90h] BYREF

  LODWORD(v4) = 0;
  this->numCover = 0;
  this->__vftable = (idDynamicCover_vtbl *)&idDynamicCover::`vftable';
  p_coverInfo = &this->coverInfo;
  this->updated = false;
  this->coverInfo.list = nullptr;
  this->coverInfo.granularity = 0;
  this->coverInfo.memTag = 5;
  this->coverInfo.listStatic = 0;
  this->coverInfo.size = 0;
  this->coverInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverInfo);
  if ( _numCover > 0 )
  {
    v6 = 0;
    HIDWORD(v4) = &vec3_origin;
    do
    {
      aas2Cover_t::aas2Cover_t(this: &v9[0].cover);
      v9[0].contentsQuery.index = v4;
      v9[0].translationQuery.index = v4;
      idList<idDynamicCover::coverInfo_t,5>::Append(this: p_coverInfo, obj: v9);
      --_numCover;
      v7 = &p_coverInfo->list[v6++];
      v7->cover.origin = vec3_origin;
      v7->cover.dir = vec3_origin;
      v7->cover.areaNum = 0;
      v7->cover.flags = 0;
      v7->cover.numTouching = 0;
      v7->cover.firstTouching = 0;
      v7->cover.reservedBy = 0x1FFF;
      v7->cover.usableTime = 0;
    }
    while ( _numCover != 0 );
  }
  return this;
}


// ========================================================================
// __unwind$488662
// EA  : 0x82A8EED8
// RVA : 0x00A8EED8
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void _unwind_488662()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 240 + 260));
}


// ========================================================================
// __unwind$488663
// EA  : 0x82A8EF00
// RVA : 0x00A8EF00
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void _unwind_488663()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 12));
}


// ========================================================================
// ?InternalAppendUsableCover@idDynamicCover@@MBAHPBVidEntity@@PBVidAAS2@@AAV?$idList@VidAICover@@$04@@@Z
// EA  : 0x82A8F090
// RVA : 0x00A8F090
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

int __fastcall idDynamicCover::InternalAppendUsableCover(
        idDynamicCover *this,
        const idEntity *owner,
        const idAAS2 *aas,
        idList<int,5> *coverList)
{
  int v8; // r30
  int v9; // r31
  int v10; // r28
  idAICover *v11; // r3

  v8 = 0;
  v9 = 0;
  if ( this->numCover > 0 )
  {
    v10 = 0;
    do
    {
      if ( idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,5>::IsFull(this: coverList) )
        break;
      if ( (this->coverInfo.list[v10].cover.flags & 0x2000) == 0 )
      {
        v11 = idList<idAICover,5>::Alloc(this: (idList<idAICover,5> *)coverList);
        idAICover::Init(this: v11, ent: owner, aas, index: v9);
        ++v8;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->numCover );
  }
  return v8;
}


// ========================================================================
// `dynamic initializer for 'ai_debugDynamicCover''
// EA  : 0x83369088
// RVA : 0x01369088
// PDB : w:\tech5\tungsten\game\ai\cover\dynamiccover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugDynamicCover__()
{
  idCVar::idCVar(
    this: &ai_debugDynamicCover,
    name: "ai_debugDynamicCover",
    value: "0",
    flags: 2,
    description: "1 = show debug info for dynamic cover, 2 = show dynamic cover collision checks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugDynamicCover__);
}

