
// ========================================================================
// ?GetAreaNum@idAASPosition@@QBAHXZ
// EA  : 0x829EE4C0
// RVA : 0x009EE4C0
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

int __fastcall idAASPosition::GetAreaNum(idAASPosition *this)
{
  if ( this->valid )
    return this->areaNum;
  else
    return 0;
}


// ========================================================================
// ?Initialize@idAASPosition@@QAAXPBVidAAS2@@HABVidVec3@@@Z
// EA  : 0x829EE4E0
// RVA : 0x009EE4E0
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

void __fastcall idAASPosition::Initialize(
        idAASPosition *this,
        const idAAS2 *_aas,
        unsigned __int16 _areaNum,
        const idVec3 *_origin)
{
  this->aas = _aas;
  this->areaNum = _areaNum;
  this->origin = *_origin;
  this->validOrigin = *_origin;
  this->valid = true;
}


// ========================================================================
// ?Update@idAASPosition@@QAAXPBVidAAS2@@ABVidVec3@@@Z
// EA  : 0x829EE528
// RVA : 0x009EE528
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

void __fastcall idAASPosition::Update(idAASPosition *this, idAAS2 *aas, const idVec3 *origin)
{
  idRenderWorld *v6; // r3
  idRenderWorld *v7; // r3
  char v8; // r11
  int (__fastcall *PointAreaNum)(idAAS2 *, idIndex<int,enum invalidAASTree_t> *__struct_ptr, const idVec3 *); // r10
  int v10; // r30
  idAAS2_vtbl *v11; // r24
  idBounds *v12; // r3
  unsigned __int16 v13; // r3
  char v14; // [sp+50h] [-60h] BYREF

  if ( aas == nullptr )
  {
    this->valid = false;
    return;
  }
  if ( ai_debugAASPosition.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    v6 = common->RW(this: common);
    v6->DebugPoint(this: v6, a2: (const idVec4 *)&idColor::colorYellow, a3: &this->origin, a4: 0, a5: false);
    v7 = common->RW(this: common);
    v7->DebugPoint(this: v7, a2: (const idVec4 *)&idColor::colorWhite, a3: &this->validOrigin, a4: 0, a5: false);
  }
  if ( this->areaNum == 0 )
    goto LABEL_13;
  if ( this->origin.x != origin->x || this->origin.y != origin->y || (v8 = 1, this->origin.z != origin->z) )
    v8 = 0;
  if ( v8 == 0 || this->aas != aas )
  {
LABEL_13:
    this->aas = aas;
    this->origin.x = origin->x;
    PointAreaNum = aas->PointAreaNum;
    this->origin.y = origin->y;
    this->origin.z = origin->z;
    v10 = (unsigned __int16)PointAreaNum(this: aas, a2: nullptr, a3: origin);
    this->valid = v10 != 0;
    if ( v10 != 0 )
    {
      this->validOrigin.x = origin->x;
      this->validOrigin.y = origin->y;
      this->validOrigin.z = origin->z;
    }
    else
    {
      v11 = aas->__vftable;
      v12 = aas->DefaultSearchBounds(this: &v14, result: aas);
      v13 = v11->PointReachableAreaNum(this: aas, a2: nullptr, a3: origin, a4: v12, a5: 2, a6: 1);
      LOWORD(v10) = v13;
      if ( v13 == 0 )
        return;
      aas->PushPointIntoAreaNum(this: aas, a2: v13, a3: &this->origin);
      this->validOrigin.x = this->origin.x;
      this->validOrigin.y = this->origin.y;
      this->validOrigin.z = this->origin.z;
      this->valid = true;
    }
    this->areaNum = v10;
  }
}


// ========================================================================
// ?Update@idAASPosition@@QAAXPBVidAAS2@@PBVidEntity@@@Z
// EA  : 0x829EE760
// RVA : 0x009EE760
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

void __fastcall idAASPosition::Update(idAASPosition *this, idAAS2 *aas, idEntity *ent)
{
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3

  Physics = idEntity::GetPhysics(this: ent);
  v6 = Physics->GetOrigin(this: Physics, a2: 0);
  idAASPosition::Update(this, aas, origin: v6);
}


// ========================================================================
// ??0idAASPositionMgr@@QAA@XZ
// EA  : 0x829EE7C0
// RVA : 0x009EE7C0
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

idAASPositionMgr *__fastcall idAASPositionMgr::idAASPositionMgr(idAASPositionMgr *this)
{
  this->aasPosition[0].valid = false;
  this->aasPosition[0].areaNum = 0;
  this->aasPosition[0].origin.x = 0.0;
  this->aasPosition[0].origin.y = 0.0;
  this->aasPosition[0].origin.z = 0.0;
  this->aasPosition[0].validOrigin.x = 0.0;
  this->aasPosition[0].validOrigin.y = 0.0;
  this->aasPosition[0].validOrigin.z = 0.0;
  this->aasPosition[0].aas = nullptr;
  this->aasPosition[1].valid = false;
  this->aasPosition[1].areaNum = 0;
  this->aasPosition[1].origin.x = 0.0;
  this->aasPosition[1].origin.y = 0.0;
  this->aasPosition[1].origin.z = 0.0;
  this->aasPosition[1].validOrigin.x = 0.0;
  this->aasPosition[1].validOrigin.y = 0.0;
  this->aasPosition[1].validOrigin.z = 0.0;
  this->aasPosition[1].aas = nullptr;
  this->numAASPositions = 0;
  this->lastUpdateFrame[0] = -1;
  this->lastUpdateFrame[1] = -1;
  return this;
}


// ========================================================================
// ?AllocAASPositionIndex@idAASPositionMgr@@AAAHPBVidAAS2@@@Z
// EA  : 0x829EE828
// RVA : 0x009EE828
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

int __fastcall idAASPositionMgr::AllocAASPositionIndex(idAASPositionMgr *this, const idAAS2 *aas)
{
  int numAASPositions; // r10
  int result; // r3
  int v5; // r7
  int v6; // r11
  int *lastUpdateFrame; // r9
  const idAAS2 **p_aas; // r8

  numAASPositions = this->numAASPositions;
  if ( numAASPositions >= 2 )
  {
    result = -1;
    v5 = 0x7FFFFFFF;
    v6 = 0;
    lastUpdateFrame = this->lastUpdateFrame;
    p_aas = &this->aasPosition[0].aas;
    do
    {
      if ( *p_aas == aas )
        return v6;
      if ( *lastUpdateFrame < v5 )
      {
        v5 = *lastUpdateFrame;
        result = v6;
      }
      ++v6;
      ++lastUpdateFrame;
      p_aas += 8;
    }
    while ( v6 < this->numAASPositions );
    if ( result < 0 )
      return -1;
  }
  else
  {
    result = this->numAASPositions;
    this->numAASPositions = numAASPositions + 1;
  }
  return result;
}


// ========================================================================
// ?GetAASPosition@idAASPositionMgr@@QAAABVidAASPosition@@PBVidAAS2@@PBVidEntity@@@Z
// EA  : 0x829EE8B8
// RVA : 0x009EE8B8
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

const idAASPosition *__fastcall idAASPositionMgr::GetAASPosition(idAASPositionMgr *this, idAAS2 *aas, idEntity *ent)
{
  int numAASPositions; // r9
  int v6; // r11
  const idAAS2 **p_aas; // r10
  int v8; // r31
  unsigned int v9; // r3
  idPhysics *Physics; // r3
  idAASPosition *v11; // r31
  const idVec3 *v12; // r3

  numAASPositions = this->numAASPositions;
  v6 = 0;
  if ( numAASPositions <= 0 )
    goto LABEL_7;
  p_aas = &this->aasPosition[0].aas;
  while ( *p_aas != aas )
  {
    ++v6;
    p_aas += 8;
    if ( v6 >= numAASPositions )
      goto LABEL_7;
  }
  v8 = v6;
  if ( v6 < 0 )
  {
LABEL_7:
    v9 = idAASPositionMgr::AllocAASPositionIndex(this, aas);
    v8 = ((v9 >> 31) - 1) & v9;
  }
  Physics = idEntity::GetPhysics(this: ent);
  v11 = &this->aasPosition[v8];
  v12 = Physics->GetOrigin(this: Physics, a2: 0);
  idAASPosition::Update(this: v11, aas, origin: v12);
  return v11;
}


// ========================================================================
// `dynamic initializer for 'ai_debugAASPosition''
// EA  : 0x833641A0
// RVA : 0x013641A0
// PDB : w:\tech5\tungsten\game\ai\aaspositionmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugAASPosition__()
{
  idCVar::idCVar(
    this: &ai_debugAASPosition,
    name: "ai_debugAASPosition",
    value: "0",
    flags: 1,
    description: "1 = show debug markers for AAS position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugAASPosition__);
}

