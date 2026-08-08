
// ========================================================================
// ?ParseInt@idAAS2Settings@@AAA_NAAVidLexer@@AAH@Z
// EA  : 0x825AFCB0
// RVA : 0x005AFCB0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ParseInt(idAAS2Settings *this, idLexer *src, int *i)
{
  if ( !idLexer::ExpectTokenString(this: src, string: "=") )
    return 0;
  *i = idLexer::ParseInt(this: src);
  return 1;
}


// ========================================================================
// ?ParseFloat@idAAS2Settings@@AAA_NAAVidLexer@@AAM@Z
// EA  : 0x825AFD18
// RVA : 0x005AFD18
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ParseFloat(idAAS2Settings *this, idLexer *src, float *f)
{
  if ( !idLexer::ExpectTokenString(this: src, string: "=") )
    return 0;
  *f = idLexer::ParseFloat(this: src, errorFlag: nullptr);
  return 1;
}


// ========================================================================
// ??0aas2Cover_t@@QAA@XZ
// EA  : 0x825B0208
// RVA : 0x005B0208
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

aas2Cover_t *__fastcall aas2Cover_t::aas2Cover_t(aas2Cover_t *this)
{
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->dir.x = 0.0;
  this->dir.y = 0.0;
  this->dir.z = 0.0;
  this->areaNum = 0;
  this->flags = 0;
  this->durationSec = -1.0;
  this->numTouching = 0;
  this->minRange = 0.0;
  this->firstTouching = 0;
  this->maxRange = 0.0;
  this->reservedBy = 0x1FFF;
  this->usableTime = 0;
  return this;
}


// ========================================================================
// ??0aas2Traversal_t@@QAA@XZ
// EA  : 0x825B0260
// RVA : 0x005B0260
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

aas2Traversal_t *__fastcall aas2Traversal_t::aas2Traversal_t(aas2Traversal_t *this)
{
  this->startPoint.x = 0.0;
  this->startPoint.y = 0.0;
  this->startPoint.z = 0.0;
  this->endPoint.x = 0.0;
  this->endPoint.y = 0.0;
  this->endPoint.z = 0.0;
  idQuantizedVec3::idQuantizedVec3(this: &this->orientationFwd, vec: &vec3_origin);
  idQuantizedVec3::idQuantizedVec3(this: &this->extrusionFwd, vec: &vec3_origin);
  this->animIndex.value = -1;
  *(_DWORD *)&this->reachabilityIndex.value = 0xFFFF;
  this->interactionEntIndex.value = -1;
  this->extrusionDistance = 0;
  this->startAreaNum = 0;
  *(_DWORD *)&this->endAreaNum = 0xFFFF;
  this->flags = 0;
  return this;
}


// ========================================================================
// ?Clear@aas2Traversal_t@@QAAXXZ
// EA  : 0x825B0300
// RVA : 0x005B0300
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall aas2Traversal_t::Clear(aas2Traversal_t *this)
{
  idQuantizedVec3 v2; // [sp+50h] [-30h] BYREF
  idQuantizedVec3 v3[2]; // [sp+58h] [-28h] BYREF

  this->startPoint = vec3_origin;
  this->endPoint = vec3_origin;
  this->orientationFwd = *idQuantizedVec3::idQuantizedVec3(this: &v2, vec: &vec3_origin);
  this->extrusionFwd = *idQuantizedVec3::idQuantizedVec3(this: v3, vec: &vec3_origin);
  this->extrusionDistance = 0;
  this->startAreaNum = 0;
  this->endAreaNum = 0;
  this->animIndex.value = -1;
  this->reachabilityIndex.value = -1;
  this->dependencyIndex.value = -1;
  this->interactionEntIndex.value = -1;
  this->traversalNameIndex.value = -1;
  this->flags = 0;
}


// ========================================================================
// ?CalcExtrusionPoint@aas2Traversal_t@@QBAXAAVidVec3@@@Z
// EA  : 0x825B03E0
// RVA : 0x005B03E0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall aas2Traversal_t::CalcExtrusionPoint(aas2Traversal_t *this, idVec3 *extrusionPoint, const idVec3 *up)
{
  double x; // fp0
  __int128 v4; // r9 OVERLAPPED
  __int64 v5; // r11
  double v6; // fp3
  double y; // fp12

  x = this->startPoint.x;
  *extrusionPoint = this->startPoint;
  if ( this->extrusionDistance > 0 )
  {
    LODWORD(v4) = this->extrusionDistance;
    DWORD2(v4) = (unsigned __int16)this->extrusionFwd.y;
    DWORD1(v4) = &unk_821B0000;
    LODWORD(v5) = this->extrusionFwd.x;
    HIDWORD(v5) = SWORD5(v4);
    v6 = (double)(__int64)v4;
    DWORD2(v4) = this->extrusionFwd.z;
    y = extrusionPoint->y;
    extrusionPoint->z = extrusionPoint->z
                      + (float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.000030518509) * (float)v6);
    extrusionPoint->y = (float)((float)((float)*(__int64 *)((char *)&v4 - 4) * (float)0.000030518509) * (float)v6)
                      + (float)y;
    extrusionPoint->x = (float)x + (float)((float)((float)v5 * (float)0.000030518509) * (float)v6);
  }
}


// ========================================================================
// ??0aas2HintNode_t@@QAA@XZ
// EA  : 0x825B04B0
// RVA : 0x005B04B0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

aas2HintNode_t *__fastcall aas2HintNode_t::aas2HintNode_t(aas2HintNode_t *this)
{
  *(_DWORD *)&this->areaNum = 128;
  this->hintType = 0;
  this->origin.x = 0.0;
  this->orientation = 0;
  this->origin.y = 0.0;
  this->dirFlags = 0;
  this->origin.z = 0.0;
  this->grouping = 0;
  this->hintData = 0;
  return this;
}


// ========================================================================
// ?GetOrientationVector@aas2HintNode_t@@QBAXAAVidVec3@@@Z
// EA  : 0x825B04F0
// RVA : 0x005B04F0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall aas2HintNode_t::GetOrientationVector(aas2HintNode_t *this, idVec3 *dir, int a3, int a4, __int64 a5)
{
  idVec3 v5; // [sp+50h] [-30h] BYREF
  idAngles v6; // [sp+60h] [-20h] BYREF

  LODWORD(a5) = this->orientation;
  v5.x = 0.0;
  v5.z = 0.0;
  v5.y = (float)a5 * (float)1.4117647;
  *dir = *idAngles::ToForward(this: &v6, result: &v5);
}


// ========================================================================
// ??0aas2Area_t@@QAA@XZ
// EA  : 0x825B0570
// RVA : 0x005B0570
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

aas2Area_t *__fastcall aas2Area_t::aas2Area_t(aas2Area_t *this)
{
  this->travelFlags = 0;
  this->flags = 0;
  this->numEdges = 0;
  this->firstEdge = 0;
  this->cluster = 0;
  this->clusterAreaNum = 0;
  this->obstaclePVSOffset = 0;
  this->reach.value = 0;
  this->rev_reach.value = 0;
  this->firstChokePoint = 0;
  this->numChokePoints = 0;
  this->firstCover = 0;
  this->numCover = 0;
  this->firstTraversal = 0;
  this->numTraversals = 0;
  this->firstHintNode = 0;
  this->numHintNodes = 0;
  return this;
}


// ========================================================================
// ??0idAAS2Settings@@QAA@XZ
// EA  : 0x825B05C8
// RVA : 0x005B05C8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2Settings *__fastcall idAAS2Settings::idAAS2Settings(idAAS2Settings *this)
{
  idStr *p_fileExtensionAAS; // r3

  this->fileExtensionAAS.len = 0;
  p_fileExtensionAAS = &this->fileExtensionAAS;
  this->fileExtensionAAS.data = p_fileExtensionAAS->baseBuffer;
  this->fileExtensionAAS.allocedAndFlag = 20;
  this->fileExtensionAAS.baseBuffer[0] = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.len = 0;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  this->explicitGroupName.allocedAndFlag = 20;
  this->explicitGroupName.len = 0;
  this->explicitGroupName.data = this->explicitGroupName.baseBuffer;
  this->explicitGroupName.baseBuffer[0] = 0;
  this->type = AAS_MAX;
  idStr::operator=(this: p_fileExtensionAAS, text: "defaulted");
  idStr::operator=(this: &this->groupName, text: "aas");
  idStr::operator=(this: &this->explicitGroupName, text: "defaulted");
  this->boundingBox.b[0].x = -16.0;
  this->boundingBox.b[0].y = -16.0;
  this->boundingBox.b[0].z = 0.0;
  this->boundingBox.b[1].x = 16.0;
  this->boundingBox.b[1].y = 16.0;
  this->boundingBox.b[1].z = 96.0;
  this->primitiveModeBrush = 0;
  this->primitiveModePatch = 1;
  this->primitiveModeModel = 1;
  this->gravityDir.x = 0.0;
  this->gravityDir.y = 0.0;
  this->gravityDir.z = -1.0;
  this->tt_barrierJump = 100;
  this->tt_waterJump = 100;
  this->tt_startWalkOffLedge = 100;
  this->tt_startLadderClimb = 100;
  this->gravityValue = 1066.0;
  this->maxStepHeight = 14.0;
  this->maxBarrierHeight = 32.0;
  this->maxWaterJumpHeight = 20.0;
  this->maxFallHeight = 64.0;
  this->minFloorCos = 0.69999999;
  this->minHighCeiling = 80.0;
  this->groundSpeed = 250.0;
  this->waterSpeed = 150.0;
  this->ladderSpeed = 50.0;
  this->wallCornerEdgeRadius = 16.0;
  this->ledgeCornerEdgeRadius = 16.0;
  this->obstaclePVSRadius = 1024.0;
  this->wallCornerReachabilityBackoff = 0.0;
  this->highQualityReachabilityBackoff = 0.0;
  this->minCrouchingCoverHeight = 32.0;
  this->minStandingCoverHeight = 64.0;
  this->crouchingFireHeight = 48.0;
  this->standingFireHeight = 72.0;
  this->minDoorWidth = 32.0;
  this->maxDoorWidth = 80.0;
  this->minWallWidth = 8.0;
  this->maxWallWidth = 32.0;
  this->coverCornerDistance = 8.0;
  this->coverWallDistance = 8.0;
  this->chokePointWidth = 96.0;
  return this;
}


// ========================================================================
// __unwind$231315
// EA  : 0x825B07F0
// RVA : 0x005B07F0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_231315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 4));
}


// ========================================================================
// __unwind$231316
// EA  : 0x825B081C
// RVA : 0x005B081C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_231316()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 36));
}


// ========================================================================
// __unwind$231317
// EA  : 0x825B0848
// RVA : 0x005B0848
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_231317()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 68));
}


// ========================================================================
// ?ParseVector@idAAS2Settings@@AAA_NAAVidLexer@@AAVidVec3@@@Z
// EA  : 0x825B0878
// RVA : 0x005B0878
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2Settings::ParseVector(idAAS2Settings *this, idLexer *src, idVec3 *vec)
{
  return idLexer::ExpectTokenString(this: src, string: "=")
      && idLexer::Parse1DMatrix(this: src, x: 3, m: &vec->x, expectCommas: false);
}


// ========================================================================
// ?ParseBounds@idAAS2Settings@@AAA_NAAVidLexer@@AAVidBounds@@@Z
// EA  : 0x825B08F0
// RVA : 0x005B08F0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ParseBounds(idAAS2Settings *this, idLexer *src, idBounds *bounds)
{
  if ( !idLexer::ExpectTokenString(this: src, string: "=") )
    return 0;
  idLexer::Parse1DMatrix(this: src, x: 3, m: (float *)bounds, expectCommas: false);
  if ( !idLexer::ExpectTokenString(this: src, string: "-") )
    return 0;
  idLexer::Parse1DMatrix(this: src, x: 3, m: &bounds->b[1].x, expectCommas: false);
  return 1;
}


// ========================================================================
// ?ValidForBounds@idAAS2Settings@@QBA_NABVidBounds@@@Z
// EA  : 0x825B0990
// RVA : 0x005B0990
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ValidForBounds(idAAS2Settings *this, const idBounds *bounds)
{
  int v3; // r9
  idVec3 *i; // r10

  v3 = 0;
  for ( i = &this->boundingBox.b[1];
        bounds->b[0].x >= (double)i[-1].x && bounds->b[1].x <= (double)i->x;
        i = (idVec3 *)((char *)i + 4) )
  {
    ++v3;
    bounds = (const idBounds *)((char *)bounds + 4);
    if ( v3 >= 3 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?GetAASAnim@idAAS2File@@QBA_NV?$idIndex@FW4invalidAASAnimIndex_t@@@@AAPBUaas2AnimName_t@@@Z
// EA  : 0x825B0A90
// RVA : 0x005B0A90
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASAnim(
        idAAS2File *this,
        const idIndex<short,enum invalidAASAnimIndex_t> *index,
        const aas2AnimName_t **name)
{
  if ( (__int16)index < 0 || (__int16)index >= this->animNames.num )
  {
    *name = nullptr;
    return 0;
  }
  else
  {
    *name = &this->animNames.list[(__int16)index];
    return 1;
  }
}


// ========================================================================
// ?GetAASAnimIndexByName@idAAS2File@@QBA?AV?$idIndex@FW4invalidAASAnimIndex_t@@@@PBD@Z
// EA  : 0x825B0AD0
// RVA : 0x005B0AD0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetAASAnimIndexByName(
        idAAS2File *this,
        idIndex<short,enum invalidAASAnimIndex_t> *result,
        const char *name)
{
  int v6; // r29
  int v7; // r31

  v6 = 0;
  if ( *(int *)&result[282].value <= 0 )
  {
LABEL_5:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: name, s2: (const char *)(v7 + *(_DWORD *)&result[280].value)) != 0 )
    {
      ++v6;
      v7 += 128;
      if ( v6 >= *(_DWORD *)&result[282].value )
        goto LABEL_5;
    }
    HIWORD(this->__vftable) = v6;
    return this;
  }
}


// ========================================================================
// ?GetAASDependency@idAAS2File@@QBA_NV?$idIndex@FW4invalidAASDependencyIndex_t@@@@AAPBUaas2DependencyName_t@@@Z
// EA  : 0x825B0B50
// RVA : 0x005B0B50
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASDependency(
        idAAS2File *this,
        const idIndex<short,enum invalidAASDependencyIndex_t> *index,
        const aas2DependencyName_t **name)
{
  if ( (__int16)index < 0 || (__int16)index >= this->dependencyNames.num )
  {
    *name = nullptr;
    return 0;
  }
  else
  {
    *name = &this->dependencyNames.list[(__int16)index];
    return 1;
  }
}


// ========================================================================
// ?GetAASDependencyIndexByName@idAAS2File@@QBA?AV?$idIndex@FW4invalidAASDependencyIndex_t@@@@PBD@Z
// EA  : 0x825B0B90
// RVA : 0x005B0B90
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetAASDependencyIndexByName(
        idAAS2File *this,
        idIndex<short,enum invalidAASDependencyIndex_t> *result,
        const char *name)
{
  int v6; // r29
  int v7; // r31

  v6 = 0;
  if ( *(int *)&result[290].value <= 0 )
  {
LABEL_5:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: name, s2: (const char *)(v7 + *(_DWORD *)&result[288].value)) != 0 )
    {
      ++v6;
      v7 += 128;
      if ( v6 >= *(_DWORD *)&result[290].value )
        goto LABEL_5;
    }
    HIWORD(this->__vftable) = v6;
    return this;
  }
}


// ========================================================================
// ?GetAASInteractionEntity@idAAS2File@@QBA_NV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@AAPBUaas2InteractionEntityName_t@@@Z
// EA  : 0x825B0C10
// RVA : 0x005B0C10
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASInteractionEntity(
        idAAS2File *this,
        const idIndex<short,enum invalidAASInteractionEntIndex_t> *index,
        const aas2InteractionEntityName_t **name)
{
  if ( (__int16)index < 0 || (__int16)index >= this->interactionEntityNames.num )
  {
    *name = nullptr;
    return 0;
  }
  else
  {
    *name = &this->interactionEntityNames.list[(__int16)index];
    return 1;
  }
}


// ========================================================================
// ?GetAASInteractionEntityIndexByName@idAAS2File@@QBA?AV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@PBD@Z
// EA  : 0x825B0C50
// RVA : 0x005B0C50
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetAASInteractionEntityIndexByName(
        idAAS2File *this,
        idIndex<short,enum invalidAASInteractionEntIndex_t> *result,
        const char *name)
{
  int v6; // r29
  int v7; // r31

  v6 = 0;
  if ( *(int *)&result[298].value <= 0 )
  {
LABEL_5:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: name, s2: (const char *)(v7 + *(_DWORD *)&result[296].value)) != 0 )
    {
      ++v6;
      v7 += 128;
      if ( v6 >= *(_DWORD *)&result[298].value )
        goto LABEL_5;
    }
    HIWORD(this->__vftable) = v6;
    return this;
  }
}


// ========================================================================
// ?GetAASTraversalNameIndex@idAAS2File@@QBA_NV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@AAPBUaas2TraversalEntityName_t@@@Z
// EA  : 0x825B0CD0
// RVA : 0x005B0CD0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASTraversalNameIndex(
        idAAS2File *this,
        const idIndex<short,enum invalidAASTraversalNameIndex_t> *index,
        const aas2TraversalEntityName_t **name)
{
  if ( (__int16)index < 0 || (__int16)index >= this->traversalEntityNames.num )
  {
    *name = nullptr;
    return 0;
  }
  else
  {
    *name = &this->traversalEntityNames.list[(__int16)index];
    return 1;
  }
}


// ========================================================================
// ?GetAASTraversalNameIndexByName@idAAS2File@@QBA?AV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@PBD@Z
// EA  : 0x825B0D10
// RVA : 0x005B0D10
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetAASTraversalNameIndexByName(
        idAAS2File *this,
        idIndex<short,enum invalidAASTraversalNameIndex_t> *result,
        const char *name)
{
  int v6; // r29
  int v7; // r31

  v6 = 0;
  if ( *(int *)&result[306].value <= 0 )
  {
LABEL_5:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: name, s2: (const char *)(v7 + *(_DWORD *)&result[304].value)) != 0 )
    {
      ++v6;
      v7 += 128;
      if ( v6 >= *(_DWORD *)&result[306].value )
        goto LABEL_5;
    }
    HIWORD(this->__vftable) = v6;
    return this;
  }
}


// ========================================================================
// ?GetAASTraversalIndexByNameIndex@idAAS2File@@QBAHV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@@Z
// EA  : 0x825B0D90
// RVA : 0x005B0D90
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASTraversalIndexByNameIndex(
        idAAS2File *this,
        const idIndex<short,enum invalidAASTraversalNameIndex_t> *index)
{
  int num; // r7
  int v3; // r10
  aas2Traversal_t *list; // r8
  int v5; // r11
  aas2Traversal_t *v6; // r9

  if ( (__int16)index < 0 )
    return 0;
  num = this->traversalPoints.num;
  v3 = 1;
  if ( num <= 1 )
    return 0;
  list = this->traversalPoints.list;
  v5 = 1;
  v6 = list + 1;
  while ( v6->traversalNameIndex.value != (__int16)index )
  {
    ++v3;
    v6 = &list[++v5];
    if ( v3 >= num )
      return 0;
  }
  return v3;
}


// ========================================================================
// ?SetTraversalFlag@idAAS2File@@QAA_NHH@Z
// EA  : 0x825B0DF0
// RVA : 0x005B0DF0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::SetTraversalFlag(idAAS2File *this, int index, int flags)
{
  aas2Traversal_t *v3; // r11
  unsigned int v4; // r9
  int v5; // r10

  if ( index <= 0 )
    return 0;
  if ( index >= this->traversalPoints.num )
    return 0;
  v3 = &this->traversalPoints.list[index];
  v4 = v3->flags;
  v5 = v4 | flags;
  if ( (v4 | flags) == v4 )
    return 0;
  v3->flags = v5;
  if ( (v5 & 1) == 0 )
    this->reachabilities.list[v3->reachabilityIndex.value].travelFlags &= ~1u;
  return 1;
}


// ========================================================================
// ?ClearTraversalFlag@idAAS2File@@QAA_NHH@Z
// EA  : 0x825B0E60
// RVA : 0x005B0E60
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::ClearTraversalFlag(idAAS2File *this, int index, int flags)
{
  aas2Traversal_t *v3; // r11
  unsigned int v4; // r9
  int v5; // r10

  if ( index <= 0 )
    return 0;
  if ( index >= this->traversalPoints.num )
    return 0;
  v3 = &this->traversalPoints.list[index];
  v4 = v3->flags;
  v5 = v4 & ~flags;
  if ( v5 == v4 )
    return 0;
  v3->flags = v5;
  if ( (v5 & 1) == 0 )
    this->reachabilities.list[v3->reachabilityIndex.value].travelFlags |= 1u;
  return 1;
}


// ========================================================================
// ?GetAASTraversalAreas@idAAS2File@@QAA_NHAAH0@Z
// EA  : 0x825B0ED0
// RVA : 0x005B0ED0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetAASTraversalAreas(idAAS2File *this, int index, int *startArea, int *goalArea)
{
  aas2Traversal_t *v4; // r11

  if ( index <= 0 || index >= this->traversalPoints.num )
    return 0;
  v4 = &this->traversalPoints.list[index];
  *startArea = v4->startAreaNum;
  *goalArea = v4->endAreaNum;
  return 1;
}


// ========================================================================
// ?FindReachabilityByName@idAAS2File@@QBA?AV?$idIndex@FW4invalidReachability_t@@@@PBD@Z
// EA  : 0x825B0F18
// RVA : 0x005B0F18
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::FindReachabilityByName(
        idAAS2File *this,
        idIndex<short,enum invalidReachability_t> *result,
        const char *name)
{
  int v6; // r29
  int v7; // r30

  v6 = 0;
  if ( *(int *)&result[274].value <= 0 )
  {
LABEL_5:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: (const char *)(v7 + *(_DWORD *)&result[272].value), s2: name) != 0 )
    {
      ++v6;
      v7 += 132;
      if ( v6 >= *(_DWORD *)&result[274].value )
        goto LABEL_5;
    }
    HIWORD(this->__vftable) = *(_DWORD *)(132 * v6 + *(_DWORD *)&result[272].value + 128);
    return this;
  }
}


// ========================================================================
// ?FlagNoPushAreas@idAAS2File@@QAAXXZ
// EA  : 0x825B0FA8
// RVA : 0x005B0FA8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::FlagNoPushAreas(idAAS2File *this, int a2, int a3, int a4, int a5, __int64 a6)
{
  int v7; // r28
  int v8; // r29
  aas2Area_t *list; // r10
  double v10; // fp12
  aas2Area_t *v11; // r31
  double v12; // fp13
  int v13; // r11
  double v14; // fp0
  int *v15; // r7
  aas2Edge_t *v16; // r6
  idVec3 *v17; // r5
  int v18; // r10
  float *p_x; // r10
  idVec3 v20; // [sp+58h] [-48h] BYREF

  v7 = 1;
  if ( this->areas.num > 1 )
  {
    v8 = 1;
    do
    {
      list = this->areas.list;
      v20.z = 0.0;
      v20.y = 0.0;
      v10 = 0.0;
      v11 = &list[v8];
      v20.x = 0.0;
      v12 = 0.0;
      v13 = 0;
      v14 = 0.0;
      if ( list[v8].numEdges > 0 )
      {
        v15 = this->edgeIndex.list;
        v16 = this->edges.list;
        v17 = this->vertices.list;
        do
        {
          v18 = v11->firstEdge + v13++;
          HIDWORD(a6) = 4 * (3 * abs32(v15[v18]) + ((unsigned int)v15[v18] >> 31));
          p_x = &v17[*(int *)((char *)v16->vertexNum + HIDWORD(a6))].x;
          v14 = (float)(*p_x + (float)v14);
          v20.x = v14;
          v12 = (float)(p_x[1] + (float)v12);
          v20.y = v12;
          v10 = (float)(p_x[2] + (float)v10);
          v20.z = v10;
        }
        while ( v13 < v11->numEdges );
      }
      LODWORD(a6) = v11->numEdges;
      v20.x = (float)((float)1.0 / (float)a6) * (float)v14;
      v20.y = (float)v12 * (float)((float)1.0 / (float)a6);
      v20.z = (float)((float)1.0 / (float)a6) * (float)v10;
      HIDWORD(a6) = idAAS2File::PushPointIntoAreaNum(this, areaNum: v7, point: &v20);
      if ( HIDWORD(a6) != 0 )
        v11->flags |= 0x10u;
      ++v7;
      ++v8;
    }
    while ( v7 < this->areas.num );
  }
}


// ========================================================================
// ?ResetCover@idAAS2File@@QAAXXZ
// EA  : 0x825B1120
// RVA : 0x005B1120
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::ResetCover(idAAS2File *this)
{
  int v1; // r10
  int v2; // r11

  v1 = 0;
  if ( this->cover.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      this->cover.list[v2].usableTime = 0;
      this->cover.list[v2++].reservedBy = 0x1FFF;
    }
    while ( v1 < this->cover.num );
  }
}


// ========================================================================
// ?GetTreeForFloorNormal@idAAS2File@@QBA?AV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@@Z
// EA  : 0x825B1170
// RVA : 0x005B1170
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetTreeForFloorNormal(
        idAAS2File *this,
        idIndex<int,enum invalidAASTree_t> *result,
        const idVec3 *floorNormal)
{
  int value; // r6
  int v4; // r11
  double v5; // fp0
  int v6; // r7
  double z; // fp12
  double y; // fp11
  double x; // fp10
  int v10; // r8
  float *v11; // r10
  double v12; // fp13
  double v13; // fp13
  int v14; // r9
  double v15; // fp13
  double v16; // fp13
  int v17; // r8
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  int v21; // r9
  int v22; // ctr
  double v23; // fp13

  value = result[89].value;
  v4 = 0;
  this->__vftable = (idAAS2File_vtbl *)-1;
  v5 = -2.0;
  if ( value >= 4 )
  {
    v6 = result[88].value;
    z = floorNormal->z;
    y = floorNormal->y;
    x = floorNormal->x;
    v10 = 0;
    do
    {
      v12 = (float)((float)(*(float *)(v10 + v6) * (float)x)
                  + (float)((float)(*(float *)(v10 + v6 + 4) * (float)y) + (float)(*(float *)(v10 + v6 + 8) * (float)z)));
      if ( v5 < v12 && v12 > 0.70710677 )
      {
        v5 = (float)((float)(*(float *)(v10 + v6) * (float)x)
                   + (float)((float)(*(float *)(v10 + v6 + 4) * (float)y) + (float)(*(float *)(v10 + v6 + 8) * (float)z)));
        this->__vftable = (idAAS2File_vtbl *)v4;
      }
      v11 = (float *)(v10 + v6);
      v13 = (float)((float)(v11[6] * (float)x) + (float)((float)(v11[7] * (float)y) + (float)(v11[8] * (float)z)));
      if ( v5 < v13 && v13 > 0.70710677 )
      {
        v5 = (float)((float)(v11[6] * (float)x) + (float)((float)(v11[7] * (float)y) + (float)(v11[8] * (float)z)));
        this->__vftable = (idAAS2File_vtbl *)(v4 + 1);
      }
      v14 = v10 + 72;
      v15 = (float)((float)(*(float *)(v10 + 72 + v6 - 24) * (float)x)
                  + (float)((float)(*(float *)(v10 + 72 + v6 - 20) * (float)y)
                          + (float)(*(float *)(v10 + 72 + v6 - 16) * (float)z)));
      if ( v5 < v15 && v15 > 0.70710677 )
      {
        v5 = (float)((float)(*(float *)(v10 + 72 + v6 - 24) * (float)x)
                   + (float)((float)(*(float *)(v10 + 72 + v6 - 20) * (float)y)
                           + (float)(*(float *)(v10 + 72 + v6 - 16) * (float)z)));
        this->__vftable = (idAAS2File_vtbl *)(v4 + 2);
      }
      v16 = (float)((float)(*(float *)(v14 + v6) * (float)x)
                  + (float)((float)(*(float *)(v14 + v6 + 4) * (float)y) + (float)(*(float *)(v14 + v6 + 8) * (float)z)));
      if ( v5 < v16 && v16 > 0.70710677 )
      {
        v5 = (float)((float)(*(float *)(v14 + v6) * (float)x)
                   + (float)((float)(*(float *)(v14 + v6 + 4) * (float)y) + (float)(*(float *)(v14 + v6 + 8) * (float)z)));
        this->__vftable = (idAAS2File_vtbl *)(v4 + 3);
      }
      v4 += 4;
      v10 += 96;
    }
    while ( v4 < value - 3 );
  }
  if ( v4 < value )
  {
    v17 = result[88].value;
    v18 = floorNormal->z;
    v19 = floorNormal->y;
    v20 = floorNormal->x;
    v21 = 24 * v4;
    v22 = value - v4;
    do
    {
      v23 = (float)((float)(*(float *)(v21 + v17) * (float)v20)
                  + (float)((float)(*(float *)(v21 + v17 + 4) * (float)v19)
                          + (float)(*(float *)(v21 + v17 + 8) * (float)v18)));
      if ( v5 < v23 && v23 > 0.70710677 )
      {
        v5 = (float)((float)(*(float *)(v21 + v17) * (float)v20)
                   + (float)((float)(*(float *)(v21 + v17 + 4) * (float)v19)
                           + (float)(*(float *)(v21 + v17 + 8) * (float)v18)));
        this->__vftable = (idAAS2File_vtbl *)v4;
      }
      ++v4;
      v21 += 24;
      --v22;
    }
    while ( v22 != 0 );
  }
  return this;
}


// ========================================================================
// ?GetTreeForArea@idAAS2File@@QBA?AV?$idIndex@HW4invalidAASTree_t@@@@H@Z
// EA  : 0x825B1318
// RVA : 0x005B1318
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::GetTreeForArea(
        idAAS2File *this,
        idIndex<int,enum invalidAASTree_t> *result,
        int areaNum)
{
  int value; // r7
  idAAS2File_vtbl *v4; // r9
  int v5; // r8
  int v6; // r11

  value = result[89].value;
  v4 = nullptr;
  if ( value <= 0 )
  {
LABEL_6:
    this->__vftable = nullptr;
  }
  else
  {
    v5 = result[88].value;
    v6 = 0;
    while ( areaNum < *(_DWORD *)(v6 + v5 + 16) || areaNum >= *(_DWORD *)(v6 + v5 + 20) )
    {
      v4 = (idAAS2File_vtbl *)((char *)v4 + 1);
      v6 += 24;
      if ( (int)v4 >= value )
        goto LABEL_6;
    }
    this->__vftable = v4;
  }
  return this;
}


// ========================================================================
// ?GetNumAreasInTree@idAAS2File@@QBAHV?$idIndex@HW4invalidAASTree_t@@@@@Z
// EA  : 0x825B1370
// RVA : 0x005B1370
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetNumAreasInTree(idAAS2File *this, idIndex<int,enum invalidAASTree_t> *treeNum)
{
  return this->trees.list[(_DWORD)treeNum].lastArea - this->trees.list[(_DWORD)treeNum].firstArea;
}


// ========================================================================
// ?ReadFromFile@idAAS2Settings@@QAA_NAAVidLexer@@@Z
// EA  : 0x825B1560
// RVA : 0x005B1560
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ReadFromFile(idAAS2Settings *this, idLexer *src)
{
  unsigned __int64 v2; // r30
  __int64 v3; // r22
  __int64 v4; // r8
  double y; // fp13
  double z; // fp12
  size_t v8; // [sp+50h] [-1A0h]
  size_t v9; // [sp+50h] [-1A0h]
  size_t len; // [sp+50h] [-1A0h]
  idToken v11; // [sp+70h] [-180h] BYREF
  const char *v12; // [sp+B8h] [-138h]
  const char *v13; // [sp+BCh] [-134h]
  const char *v14; // [sp+C0h] [-130h]
  const char *v15; // [sp+C4h] [-12Ch]
  const char *v16; // [sp+C8h] [-128h]
  const char *v17; // [sp+CCh] [-124h]
  const char *v18; // [sp+D0h] [-120h]
  const char *v19; // [sp+D4h] [-11Ch]
  const char *v20; // [sp+D8h] [-118h]
  const char *v21; // [sp+DCh] [-114h]
  const char *v22; // [sp+E0h] [-110h]
  const char *v23; // [sp+E4h] [-10Ch]
  const char *v24; // [sp+E8h] [-108h]
  const char *v25; // [sp+ECh] [-104h]
  const char *v26; // [sp+F0h] [-100h]
  const char *v27; // [sp+F4h] [-FCh]
  const char *v28; // [sp+F8h] [-F8h]
  const char *v29; // [sp+FCh] [-F4h]
  const char *v30; // [sp+100h] [-F0h]
  const char *v31; // [sp+104h] [-ECh]
  const char *v32; // [sp+108h] [-E8h]
  idVec3 v33; // [sp+110h] [-E0h] BYREF
  __int64 v34; // [sp+120h] [-D0h]
  unsigned __int64 v35; // [sp+128h] [-C8h]
  unsigned __int64 v36; // [sp+130h] [-C0h]
  unsigned __int64 v37; // [sp+138h] [-B8h]
  unsigned __int64 v38; // [sp+140h] [-B0h]
  __int64 v39; // [sp+148h] [-A8h]
  unsigned __int64 v40; // [sp+150h] [-A0h]

  v11.len = 0;
  v2 = __PAIR64__((unsigned int)src, (unsigned int)this);
  v11.allocedAndFlag = 20;
  v11.floatvalue = -3.4028235e38;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  if ( idLexer::ExpectTokenString(this: src, string: "{") )
  {
    if ( idLexer::ReadToken(this: (idLexer *)HIDWORD(v2), token: &v11) )
    {
      v22 = "invalid token '%s'";
      v14 = (const char *)-2113419412;
      v30 = (const char *)-2113419324;
      v20 = (const char *)-2113419544;
      v18 = (const char *)-2113419524;
      v16 = (const char *)-2113419500;
      v26 = (const char *)-2113418816;
      v31 = (const char *)-2113418744;
      HIDWORD(v3) = "mMaterial";
      LODWORD(v3) = -2113404928;
      HIDWORD(v4) = "mMaterial";
      LODWORD(v4) = -2113536000;
      v34 = v3;
      HIDWORD(v2) = "primitiveModePatch";
      v35 = 0x821B000082080000uLL;
      v37 = 0x82060000821B0000uLL;
      v40 = 0x8208000082080000uLL;
      v38 = 0x8208000082080000uLL;
      v39 = v4;
      v36 = v2;
      v27 = (const char *)-2113418952;
      v29 = (const char *)-2113419220;
      v19 = (const char *)-2113418556;
      v21 = (const char *)-2113418884;
      v32 = "primitiveModeModel";
      v24 = (const char *)-2113418452;
      v25 = (const char *)-2113418692;
      v12 = "type";
      v13 = (const char *)-2113419112;
      v17 = "maxBarrierHeight";
      v28 = "maxStepHeight";
      v15 = "gravity";
      v23 = "primitiveModePatch";
      do
      {
        if ( idStr::Cmp(s1: v11.data, s2: "}") == 0 )
          break;
        if ( idStr::Cmp(s1: v11.data, s2: v12) != 0 )
        {
          if ( idStr::Cmp(s1: v11.data, s2: "mMaterial") != 0 )
          {
            if ( idStr::Cmp(s1: v11.data, s2: "groupName") != 0 )
            {
              if ( idStr::Cmp(s1: v11.data, s2: "explicitGroupName") != 0 )
              {
                if ( idStr::Cmp(s1: v11.data, s2: "bbox") != 0 )
                {
                  if ( idStr::Cmp(s1: v11.data, s2: "primitiveModeBrush") != 0 )
                  {
                    if ( idStr::Cmp(s1: v11.data, s2: v23) != 0 )
                    {
                      if ( idStr::Cmp(s1: v11.data, s2: v32) != 0 )
                      {
                        if ( idStr::Cmp(s1: v11.data, s2: v15) != 0 )
                        {
                          if ( idStr::Cmp(s1: v11.data, s2: v28) != 0 )
                          {
                            if ( idStr::Cmp(s1: v11.data, s2: v17) != 0 )
                            {
                              if ( idStr::Cmp(s1: v11.data, s2: "maxWaterJumpHeight") != 0 )
                              {
                                if ( idStr::Cmp(s1: v11.data, s2: "maxFallHeight") != 0 )
                                {
                                  if ( idStr::Cmp(s1: v11.data, s2: "minFloorCos") != 0 )
                                  {
                                    if ( idStr::Cmp(s1: v11.data, s2: "minHighCeiling") != 0 )
                                    {
                                      if ( idStr::Cmp(s1: v11.data, s2: "groundSpeed") != 0 )
                                      {
                                        if ( idStr::Cmp(s1: v11.data, s2: "waterSpeed") != 0 )
                                        {
                                          if ( idStr::Cmp(s1: v11.data, s2: "ladderSpeed") != 0 )
                                          {
                                            if ( idStr::Cmp(s1: v11.data, s2: "wallCornerEdgeRadius") != 0 )
                                            {
                                              if ( idStr::Cmp(s1: v11.data, s2: "ledgeCornerEdgeRadius") != 0 )
                                              {
                                                if ( idStr::Cmp(s1: v11.data, s2: "obstaclePVSRadius") != 0 )
                                                {
                                                  if ( idStr::Cmp(s1: v11.data, s2: "wallCornerReachabilityBackoff") != 0 )
                                                  {
                                                    if ( idStr::Cmp(s1: v11.data, s2: v24) != 0 )
                                                    {
                                                      if ( idStr::Cmp(s1: v11.data, s2: v19) != 0 )
                                                      {
                                                        if ( idStr::Cmp(s1: v11.data, s2: v25) != 0 )
                                                        {
                                                          if ( idStr::Cmp(s1: v11.data, s2: v21) != 0 )
                                                          {
                                                            if ( idStr::Cmp(s1: v11.data, s2: v27) != 0 )
                                                            {
                                                              if ( idStr::Cmp(s1: v11.data, s2: v13) != 0 )
                                                              {
                                                                if ( idStr::Cmp(s1: v11.data, s2: v29) != 0 )
                                                                {
                                                                  if ( idStr::Cmp(s1: v11.data, s2: v31) != 0 )
                                                                  {
                                                                    if ( idStr::Cmp(s1: v11.data, s2: v26) != 0 )
                                                                    {
                                                                      if ( idStr::Cmp(s1: v11.data, s2: v30) != 0 )
                                                                      {
                                                                        if ( idStr::Cmp(s1: v11.data, s2: v14) != 0 )
                                                                        {
                                                                          if ( idStr::Cmp(s1: v11.data, s2: v16) != 0 )
                                                                          {
                                                                            if ( idStr::Cmp(s1: v11.data, s2: v18) != 0 )
                                                                            {
                                                                              if ( idStr::Cmp(s1: v11.data, s2: v20) != 0 )
                                                                              {
                                                                                idLexer::Error(
                                                                                  this: (idLexer *)"primitiveModePatch",
                                                                                  str: v22,
                                                                                  v11.data);
                                                                              }
                                                                              else if ( (unsigned __int8)idAAS2Settings::ParseInt(this: (idAAS2Settings *)v2, src: (idLexer *)"primitiveModePatch", i: (int *)(v2 + 264)) == 0 )
                                                                              {
                                                                                goto LABEL_112;
                                                                              }
                                                                            }
                                                                            else if ( (unsigned __int8)idAAS2Settings::ParseInt(this: (idAAS2Settings *)v2, src: (idLexer *)"primitiveModePatch", i: (int *)(v2 + 260)) == 0 )
                                                                            {
                                                                              goto LABEL_112;
                                                                            }
                                                                          }
                                                                          else if ( (unsigned __int8)idAAS2Settings::ParseInt(this: (idAAS2Settings *)v2, src: (idLexer *)"primitiveModePatch", i: (int *)(v2 + 256)) == 0 )
                                                                          {
                                                                            goto LABEL_112;
                                                                          }
                                                                        }
                                                                        else if ( (unsigned __int8)idAAS2Settings::ParseInt(
                                                                                                     this: (idAAS2Settings *)v2,
                                                                                                     src: (idLexer *)"primitiveModePatch",
                                                                                                     i: (int *)(v2 + 252)) == 0 )
                                                                        {
                                                                          goto LABEL_112;
                                                                        }
                                                                      }
                                                                      else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                                   this: (idAAS2Settings *)v2,
                                                                                                   src: (idLexer *)"primitiveModePatch",
                                                                                                   f: (float *)(v2 + 248)) == 0 )
                                                                      {
                                                                        goto LABEL_112;
                                                                      }
                                                                    }
                                                                    else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                                 this: (idAAS2Settings *)v2,
                                                                                                 src: (idLexer *)"primitiveModePatch",
                                                                                                 f: (float *)(v2 + 220)) == 0 )
                                                                    {
                                                                      goto LABEL_112;
                                                                    }
                                                                  }
                                                                  else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                               this: (idAAS2Settings *)v2,
                                                                                               src: (idLexer *)"primitiveModePatch",
                                                                                               f: (float *)(v2 + 216)) == 0 )
                                                                  {
                                                                    goto LABEL_112;
                                                                  }
                                                                }
                                                                else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                             this: (idAAS2Settings *)v2,
                                                                                             src: (idLexer *)"primitiveModePatch",
                                                                                             f: (float *)(v2 + 244)) == 0 )
                                                                {
                                                                  goto LABEL_112;
                                                                }
                                                              }
                                                              else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                           this: (idAAS2Settings *)v2,
                                                                                           src: (idLexer *)"primitiveModePatch",
                                                                                           f: (float *)(v2 + 240)) == 0 )
                                                              {
                                                                goto LABEL_112;
                                                              }
                                                            }
                                                            else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                         this: (idAAS2Settings *)v2,
                                                                                         src: (idLexer *)"primitiveModePatch",
                                                                                         f: (float *)(v2 + 228)) == 0 )
                                                            {
                                                              goto LABEL_112;
                                                            }
                                                          }
                                                          else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                       this: (idAAS2Settings *)v2,
                                                                                       src: (idLexer *)"primitiveModePatch",
                                                                                       f: (float *)(v2 + 224)) == 0 )
                                                          {
                                                            goto LABEL_112;
                                                          }
                                                        }
                                                        else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                     this: (idAAS2Settings *)v2,
                                                                                     src: (idLexer *)"primitiveModePatch",
                                                                                     f: (float *)(v2 + 212)) == 0 )
                                                        {
                                                          goto LABEL_112;
                                                        }
                                                      }
                                                      else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                   this: (idAAS2Settings *)v2,
                                                                                   src: (idLexer *)"primitiveModePatch",
                                                                                   f: (float *)(v2 + 208)) == 0 )
                                                      {
                                                        goto LABEL_112;
                                                      }
                                                    }
                                                    else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                                 this: (idAAS2Settings *)v2,
                                                                                 src: (idLexer *)"primitiveModePatch",
                                                                                 f: (float *)(v2 + 204)) == 0 )
                                                    {
                                                      goto LABEL_112;
                                                    }
                                                  }
                                                  else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                               this: (idAAS2Settings *)v2,
                                                                               src: (idLexer *)"primitiveModePatch",
                                                                               f: (float *)(v2 + 200)) == 0 )
                                                  {
                                                    goto LABEL_112;
                                                  }
                                                }
                                                else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                             this: (idAAS2Settings *)v2,
                                                                             src: (idLexer *)"primitiveModePatch",
                                                                             f: (float *)(v2 + 196)) == 0 )
                                                {
                                                  goto LABEL_112;
                                                }
                                              }
                                              else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                           this: (idAAS2Settings *)v2,
                                                                           src: (idLexer *)"primitiveModePatch",
                                                                           f: (float *)(v2 + 192)) == 0 )
                                              {
                                                goto LABEL_112;
                                              }
                                            }
                                            else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                         this: (idAAS2Settings *)v2,
                                                                         src: (idLexer *)"primitiveModePatch",
                                                                         f: (float *)(v2 + 188)) == 0 )
                                            {
                                              goto LABEL_112;
                                            }
                                          }
                                          else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                       this: (idAAS2Settings *)v2,
                                                                       src: (idLexer *)"primitiveModePatch",
                                                                       f: (float *)(v2 + 184)) == 0 )
                                          {
                                            goto LABEL_112;
                                          }
                                        }
                                        else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                     this: (idAAS2Settings *)v2,
                                                                     src: (idLexer *)"primitiveModePatch",
                                                                     f: (float *)(v2 + 180)) == 0 )
                                        {
                                          goto LABEL_112;
                                        }
                                      }
                                      else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                   this: (idAAS2Settings *)v2,
                                                                   src: (idLexer *)"primitiveModePatch",
                                                                   f: (float *)(v2 + 176)) == 0 )
                                      {
                                        goto LABEL_112;
                                      }
                                    }
                                    else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                                 this: (idAAS2Settings *)v2,
                                                                 src: (idLexer *)"primitiveModePatch",
                                                                 f: (float *)(v2 + 172)) == 0 )
                                    {
                                      goto LABEL_112;
                                    }
                                  }
                                  else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                               this: (idAAS2Settings *)v2,
                                                               src: (idLexer *)"primitiveModePatch",
                                                               f: (float *)(v2 + 168)) == 0 )
                                  {
                                    goto LABEL_112;
                                  }
                                }
                                else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                             this: (idAAS2Settings *)v2,
                                                             src: (idLexer *)"primitiveModePatch",
                                                             f: (float *)(v2 + 164)) == 0 )
                                {
                                  goto LABEL_112;
                                }
                              }
                              else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                           this: (idAAS2Settings *)v2,
                                                           src: (idLexer *)"primitiveModePatch",
                                                           f: (float *)(v2 + 160)) == 0 )
                              {
                                goto LABEL_112;
                              }
                            }
                            else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                         this: (idAAS2Settings *)v2,
                                                         src: (idLexer *)"primitiveModePatch",
                                                         f: (float *)(v2 + 156)) == 0 )
                            {
                              goto LABEL_112;
                            }
                          }
                          else if ( (unsigned __int8)idAAS2Settings::ParseFloat(
                                                       this: (idAAS2Settings *)v2,
                                                       src: (idLexer *)"primitiveModePatch",
                                                       f: (float *)(v2 + 152)) == 0 )
                          {
                            goto LABEL_112;
                          }
                        }
                        else
                        {
                          idAAS2Settings::ParseVector(
                            this: (idAAS2Settings *)v2,
                            src: (idLexer *)"primitiveModePatch",
                            vec: &v33);
                          y = v33.y;
                          z = v33.z;
                          *(float *)(v2 + 136) = v33.x;
                          *(float *)(v2 + 140) = y;
                          *(float *)(v2 + 144) = z;
                          *(float *)(v2 + 148) = idVec3::NormalizeFast(this: (idVec3 *)(v2 + 136));
                        }
                      }
                      else if ( (unsigned __int8)idAAS2Settings::ParseInt(
                                                   this: (idAAS2Settings *)v2,
                                                   src: (idLexer *)"primitiveModePatch",
                                                   i: (int *)(v2 + 132)) == 0 )
                      {
                        goto LABEL_112;
                      }
                    }
                    else if ( (unsigned __int8)idAAS2Settings::ParseInt(
                                                 this: (idAAS2Settings *)v2,
                                                 src: (idLexer *)"primitiveModePatch",
                                                 i: (int *)(v2 + 128)) == 0 )
                    {
                      goto LABEL_112;
                    }
                  }
                  else if ( (unsigned __int8)idAAS2Settings::ParseInt(
                                               this: (idAAS2Settings *)v2,
                                               src: (idLexer *)"primitiveModePatch",
                                               i: (int *)(v2 + 124)) == 0 )
                  {
                    goto LABEL_112;
                  }
                }
                else if ( (unsigned __int8)idAAS2Settings::ParseBounds(
                                             this: (idAAS2Settings *)v2,
                                             src: (idLexer *)"primitiveModePatch",
                                             bounds: (idBounds *)(v2 + 100)) == 0 )
                {
                  goto LABEL_112;
                }
              }
              else
              {
                idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 5, subtype: 32, token: &v11);
                idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 1, subtype: 0, token: &v11);
                len = v11.len;
                idStr::EnsureAlloced(
                  this: (idStr *)(v2 + 68),
                  amount: v11.len + 1,
                  keepold: false,
                  geometricGrowth: false);
                memcpy(Dst: *(void **)(v2 + 72), Src: v11.data, Size: len);
                *(_BYTE *)(*(_DWORD *)(v2 + 72) + len) = 0;
                *(_DWORD *)(v2 + 68) = len;
              }
            }
            else
            {
              idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 5, subtype: 32, token: &v11);
              idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 1, subtype: 0, token: &v11);
              v9 = v11.len;
              idStr::EnsureAlloced(
                this: (idStr *)(v2 + 36),
                amount: v11.len + 1,
                keepold: false,
                geometricGrowth: false);
              memcpy(Dst: *(void **)(v2 + 40), Src: v11.data, Size: v9);
              *(_BYTE *)(*(_DWORD *)(v2 + 40) + v9) = 0;
              *(_DWORD *)(v2 + 36) = v9;
            }
          }
          else
          {
            idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 5, subtype: 32, token: &v11);
            idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 1, subtype: 0, token: &v11);
            v8 = v11.len;
            idStr::EnsureAlloced(this: (idStr *)(v2 + 4), amount: v11.len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: *(void **)(v2 + 8), Src: v11.data, Size: v8);
            *(_BYTE *)(v8 + *(_DWORD *)(v2 + 8)) = 0;
            *(_DWORD *)(v2 + 4) = v8;
          }
        }
        else
        {
          idLexer::ExpectTokenType(this: (idLexer *)"primitiveModePatch", type: 5, subtype: 32, token: &v11);
          if ( idLexer::CheckTokenString(this: (idLexer *)"primitiveModePatch", string: "player") )
          {
            *(_DWORD *)v2 = 0;
          }
          else if ( idLexer::CheckTokenString(this: (idLexer *)"primitiveModePatch", string: "monster") )
          {
            *(_DWORD *)v2 = 1;
          }
          else
          {
            if ( !idLexer::CheckTokenString(this: (idLexer *)"primitiveModePatch", string: "vehicle") )
              goto LABEL_112;
            *(_DWORD *)v2 = 2;
          }
        }
      }
      while ( idLexer::ReadToken(this: (idLexer *)"primitiveModePatch", token: &v11) );
    }
    idStr::FreeData(this: &v11);
    return 1;
  }
  else
  {
LABEL_112:
    idStr::FreeData(this: &v11);
    return 0;
  }
}


// ========================================================================
// __unwind$234736
// EA  : 0x825B2194
// RVA : 0x005B2194
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_234736()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 112));
}


// ========================================================================
// ?WriteToFileBinary@idAAS2Settings@@QBA_NPAVidFile@@@Z
// EA  : 0x825B21C0
// RVA : 0x005B21C0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::WriteToFileBinary(idAAS2Settings *this, idFile *fp)
{
  fp->Write(this: fp, a2: this, a3: 4u);
  idFile::WriteString(this: fp, string: &this->fileExtensionAAS);
  idFile::WriteString(this: fp, string: &this->groupName);
  idFile::WriteString(this: fp, string: &this->explicitGroupName);
  fp->Write(this: fp, a2: &this->boundingBox, a3: 24u);
  fp->Write(this: fp, a2: &this->primitiveModeBrush, a3: 4u);
  fp->Write(this: fp, a2: &this->primitiveModePatch, a3: 4u);
  fp->Write(this: fp, a2: &this->primitiveModeModel, a3: 4u);
  fp->Write(this: fp, a2: &this->gravityDir, a3: 12u);
  fp->Write(this: fp, a2: &this->gravityValue, a3: 4u);
  fp->Write(this: fp, a2: &this->maxStepHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->maxBarrierHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->maxWaterJumpHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->maxFallHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->minFloorCos, a3: 4u);
  fp->Write(this: fp, a2: &this->minHighCeiling, a3: 4u);
  fp->Write(this: fp, a2: &this->groundSpeed, a3: 4u);
  fp->Write(this: fp, a2: &this->waterSpeed, a3: 4u);
  fp->Write(this: fp, a2: &this->ladderSpeed, a3: 4u);
  fp->Write(this: fp, a2: &this->wallCornerEdgeRadius, a3: 4u);
  fp->Write(this: fp, a2: &this->ledgeCornerEdgeRadius, a3: 4u);
  fp->Write(this: fp, a2: &this->obstaclePVSRadius, a3: 4u);
  fp->Write(this: fp, a2: &this->minCrouchingCoverHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->minStandingCoverHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->obstaclePVSRadius, a3: 4u);
  fp->Write(this: fp, a2: &this->standingFireHeight, a3: 4u);
  fp->Write(this: fp, a2: &this->minWallWidth, a3: 4u);
  fp->Write(this: fp, a2: &this->maxWallWidth, a3: 4u);
  fp->Write(this: fp, a2: &this->minDoorWidth, a3: 4u);
  fp->Write(this: fp, a2: &this->maxDoorWidth, a3: 4u);
  fp->Write(this: fp, a2: &this->coverCornerDistance, a3: 4u);
  fp->Write(this: fp, a2: &this->coverWallDistance, a3: 4u);
  fp->Write(this: fp, a2: &this->chokePointWidth, a3: 4u);
  fp->Write(this: fp, a2: &this->tt_barrierJump, a3: 4u);
  fp->Write(this: fp, a2: &this->tt_waterJump, a3: 4u);
  fp->Write(this: fp, a2: &this->tt_startWalkOffLedge, a3: 4u);
  fp->Write(this: fp, a2: &this->tt_startLadderClimb, a3: 4u);
  return 1;
}


// ========================================================================
// ?Clear@idAAS2File@@QAAXXZ
// EA  : 0x825B25C0
// RVA : 0x005B25C0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::Clear(idAAS2File *this)
{
  this->crc = 0;
  this->timestamp = 0;
  this->firstFakeVertex = 0;
  this->firstFakeEdge = 0;
  this->firstFakeEdgeIndex = 0;
  this->firstFakeArea = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilities);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areas);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portals);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portalIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clusters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->obstaclePVS);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilityNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dependencyNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->interactionEntityNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cover);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areaCoverIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touchingCoverIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chokePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traversalPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hintNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
}


// ========================================================================
// ?ReloadIfStale@idAAS2File@@UAA_NXZ
// EA  : 0x825B26C0
// RVA : 0x005B26C0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::ReloadIfStale(idAAS2File *this)
{
  idStr v3; // [sp+50h] [-160h] BYREF
  idStr v4; // [sp+70h] [-140h] BYREF
  _BYTE v5[288]; // [sp+90h] [-120h] BYREF

  if ( this->timestamp == fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) )
    return 0;
  idStr::idStr(this: &v4, text: this->name.str);
  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  idStr::ExtractFileExtension(this: &v4, dest: &v3);
  idStr::Insert(this: &v3, a: 98, index: 0);
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: v3.data, a4: this->name.str, a5: v5, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v5, a3: FSPATH_BASE);
  this->LoadResource(this);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v4);
  return 1;
}


// ========================================================================
// __unwind$235483
// EA  : 0x825B27C4
// RVA : 0x005B27C4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_235483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 112));
}


// ========================================================================
// __unwind$235484
// EA  : 0x825B27EC
// RVA : 0x005B27EC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_235484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// ?MemorySize@idAAS2File@@QBAIXZ
// EA  : 0x825B2818
// RVA : 0x005B2818
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::MemorySize(idAAS2File *this)
{
  return 4
       * (4 * (2 * this->reachabilities.size + this->clusters.size + this->nodes.size + this->planes.size)
        + 3 * (this->portals.size + this->edges.size + this->vertices.size)
        + 14 * this->cover.size
        + 10 * this->areas.size
        + this->touchingCoverIndex.size
        + this->areaCoverIndex.size
        + this->portalIndex.size
        + this->edgeIndex.size
        + 67)
       + this->obstaclePVS.size;
}


// ========================================================================
// ?ReadFromFileBinary@idAAS2Settings@@QAA_NPAVidFile@@@Z
// EA  : 0x825B2A40
// RVA : 0x005B2A40
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2Settings::ReadFromFileBinary(idAAS2Settings *this, idFile *fp)
{
  fp->Read(this: fp, a2: (void *)this, a3: 4u);
  idFile::ReadString(this: fp, string: &this->fileExtensionAAS);
  idFile::ReadString(this: fp, string: &this->groupName);
  idFile::ReadString(this: fp, string: &this->explicitGroupName);
  fp->Read(this: fp, a2: &this->boundingBox, a3: 24u);
  fp->Read(this: fp, a2: &this->primitiveModeBrush, a3: 4u);
  fp->Read(this: fp, a2: &this->primitiveModePatch, a3: 4u);
  fp->Read(this: fp, a2: &this->primitiveModeModel, a3: 4u);
  fp->Read(this: fp, a2: &this->gravityDir, a3: 12u);
  fp->Read(this: fp, a2: &this->gravityValue, a3: 4u);
  fp->Read(this: fp, a2: &this->maxStepHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->maxBarrierHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->maxWaterJumpHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->maxFallHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->minFloorCos, a3: 4u);
  fp->Read(this: fp, a2: &this->minHighCeiling, a3: 4u);
  fp->Read(this: fp, a2: &this->groundSpeed, a3: 4u);
  fp->Read(this: fp, a2: &this->waterSpeed, a3: 4u);
  fp->Read(this: fp, a2: &this->ladderSpeed, a3: 4u);
  fp->Read(this: fp, a2: &this->wallCornerEdgeRadius, a3: 4u);
  fp->Read(this: fp, a2: &this->ledgeCornerEdgeRadius, a3: 4u);
  fp->Read(this: fp, a2: &this->obstaclePVSRadius, a3: 4u);
  fp->Read(this: fp, a2: &this->minCrouchingCoverHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->minStandingCoverHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->obstaclePVSRadius, a3: 4u);
  fp->Read(this: fp, a2: &this->standingFireHeight, a3: 4u);
  fp->Read(this: fp, a2: &this->minWallWidth, a3: 4u);
  fp->Read(this: fp, a2: &this->maxWallWidth, a3: 4u);
  fp->Read(this: fp, a2: &this->minDoorWidth, a3: 4u);
  fp->Read(this: fp, a2: &this->maxDoorWidth, a3: 4u);
  fp->Read(this: fp, a2: &this->coverCornerDistance, a3: 4u);
  fp->Read(this: fp, a2: &this->coverWallDistance, a3: 4u);
  fp->Read(this: fp, a2: &this->chokePointWidth, a3: 4u);
  fp->Read(this: fp, a2: &this->tt_barrierJump, a3: 4u);
  fp->Read(this: fp, a2: &this->tt_waterJump, a3: 4u);
  fp->Read(this: fp, a2: &this->tt_startWalkOffLedge, a3: 4u);
  fp->Read(this: fp, a2: &this->tt_startLadderClimb, a3: 4u);
  return 1;
}


// ========================================================================
// ??0idAAS2File@@QAA@XZ
// EA  : 0x825B2E48
// RVA : 0x005B2E48
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::idAAS2File(idAAS2File *this)
{
  idResource::idResource(this);
  this->crc = 0;
  this->__vftable = (idAAS2File_vtbl *)&idAAS2File::`vftable';
  this->timestamp = 0;
  this->visitedAreas.list = nullptr;
  this->visitedAreas.granularity = 0;
  this->visitedAreas.memTag = 37;
  this->visitedAreas.listStatic = 0;
  this->visitedAreas.size = 0;
  this->visitedAreas.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visitedAreas);
  idAAS2Settings::idAAS2Settings(this: &this->settings);
  this->major = 0;
  this->minor = 0;
  this->firstFakeVertex = 0;
  this->firstFakeEdge = 0;
  this->firstFakeEdgeIndex = 0;
  this->firstFakeArea = 0;
  this->trees.list = nullptr;
  this->trees.granularity = 0;
  this->trees.memTag = 37;
  this->trees.listStatic = 0;
  this->trees.size = 0;
  this->trees.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
  this->planes.list = nullptr;
  this->planes.granularity = 0;
  this->planes.memTag = 37;
  this->planes.listStatic = 0;
  this->planes.size = 0;
  this->planes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planes);
  this->vertices.list = nullptr;
  this->vertices.granularity = 0;
  this->vertices.memTag = 37;
  this->vertices.listStatic = 0;
  this->vertices.size = 0;
  this->vertices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  this->edges.list = nullptr;
  this->edges.granularity = 0;
  this->edges.memTag = 37;
  this->edges.listStatic = 0;
  this->edges.size = 0;
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  this->edgeIndex.list = nullptr;
  this->edgeIndex.granularity = 0;
  this->edgeIndex.memTag = 37;
  this->edgeIndex.listStatic = 0;
  this->edgeIndex.size = 0;
  this->edgeIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeIndex);
  this->reachabilities.list = nullptr;
  this->reachabilities.granularity = 0;
  this->reachabilities.memTag = 37;
  this->reachabilities.listStatic = 0;
  this->reachabilities.size = 0;
  this->reachabilities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilities);
  this->areas.list = nullptr;
  this->areas.granularity = 0;
  this->areas.memTag = 37;
  this->areas.listStatic = 0;
  this->areas.size = 0;
  this->areas.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areas);
  this->nodes.list = nullptr;
  this->nodes.granularity = 0;
  this->nodes.memTag = 37;
  this->nodes.listStatic = 0;
  this->nodes.size = 0;
  this->nodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  this->portals.list = nullptr;
  this->portals.granularity = 0;
  this->portals.memTag = 37;
  this->portals.listStatic = 0;
  this->portals.size = 0;
  this->portals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portals);
  this->portalIndex.list = nullptr;
  this->portalIndex.granularity = 0;
  this->portalIndex.memTag = 37;
  this->portalIndex.listStatic = 0;
  this->portalIndex.size = 0;
  this->portalIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portalIndex);
  this->clusters.list = nullptr;
  this->clusters.granularity = 0;
  this->clusters.memTag = 37;
  this->clusters.listStatic = 0;
  this->clusters.size = 0;
  this->clusters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clusters);
  this->obstaclePVS.list = nullptr;
  this->obstaclePVS.granularity = 0;
  this->obstaclePVS.memTag = 37;
  this->obstaclePVS.listStatic = 0;
  this->obstaclePVS.size = 0;
  this->obstaclePVS.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->obstaclePVS);
  this->reachabilityNames.list = nullptr;
  this->reachabilityNames.granularity = 0;
  this->reachabilityNames.memTag = 37;
  this->reachabilityNames.listStatic = 0;
  this->reachabilityNames.size = 0;
  this->reachabilityNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilityNames);
  this->animNames.list = nullptr;
  this->animNames.granularity = 0;
  this->animNames.memTag = 37;
  this->animNames.listStatic = 0;
  this->animNames.size = 0;
  this->animNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animNames);
  this->dependencyNames.list = nullptr;
  this->dependencyNames.granularity = 0;
  this->dependencyNames.memTag = 37;
  this->dependencyNames.listStatic = 0;
  this->dependencyNames.size = 0;
  this->dependencyNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dependencyNames);
  this->interactionEntityNames.list = nullptr;
  this->interactionEntityNames.granularity = 0;
  this->interactionEntityNames.memTag = 37;
  this->interactionEntityNames.listStatic = 0;
  this->interactionEntityNames.size = 0;
  this->interactionEntityNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->interactionEntityNames);
  this->traversalEntityNames.list = nullptr;
  this->traversalEntityNames.granularity = 0;
  this->traversalEntityNames.memTag = 37;
  this->traversalEntityNames.listStatic = 0;
  this->traversalEntityNames.size = 0;
  this->traversalEntityNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traversalEntityNames);
  this->cover.list = nullptr;
  this->cover.granularity = 0;
  this->cover.memTag = 37;
  this->cover.listStatic = 0;
  this->cover.size = 0;
  this->cover.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cover);
  this->areaCoverIndex.list = nullptr;
  this->areaCoverIndex.granularity = 0;
  this->areaCoverIndex.memTag = 37;
  this->areaCoverIndex.listStatic = 0;
  this->areaCoverIndex.size = 0;
  this->areaCoverIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areaCoverIndex);
  this->touchingCoverIndex.list = nullptr;
  this->touchingCoverIndex.granularity = 0;
  this->touchingCoverIndex.memTag = 37;
  this->touchingCoverIndex.listStatic = 0;
  this->touchingCoverIndex.size = 0;
  this->touchingCoverIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touchingCoverIndex);
  this->chokePoints.list = nullptr;
  this->chokePoints.granularity = 0;
  this->chokePoints.memTag = 37;
  this->chokePoints.listStatic = 0;
  this->chokePoints.size = 0;
  this->chokePoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chokePoints);
  this->traversalPoints.list = nullptr;
  this->traversalPoints.granularity = 0;
  this->traversalPoints.memTag = 37;
  this->traversalPoints.listStatic = 0;
  this->traversalPoints.size = 0;
  this->traversalPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traversalPoints);
  this->hintNodes.list = nullptr;
  this->hintNodes.granularity = 0;
  this->hintNodes.memTag = 37;
  this->hintNodes.listStatic = 0;
  this->hintNodes.size = 0;
  this->hintNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hintNodes);
  this->areaBounds.list = nullptr;
  this->areaBounds.granularity = 0;
  this->areaBounds.memTag = 37;
  this->areaBounds.listStatic = 0;
  this->areaBounds.size = 0;
  this->areaBounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areaBounds);
  return this;
}


// ========================================================================
// __unwind$237222
// EA  : 0x825B31CC
// RVA : 0x005B31CC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237222()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$237223
// EA  : 0x825B31F4
// RVA : 0x005B31F4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237223()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// __unwind$237224
// EA  : 0x825B3220
// RVA : 0x005B3220
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237224()
{
  int v0; // r12

  idAAS2Settings::~idAAS2Settings(this: (idAnimator_AF::idBindConstraint *)(*(_DWORD *)(v0 - 128 + 148) + 60));
}


// ========================================================================
// __unwind$237225
// EA  : 0x825B324C
// RVA : 0x005B324C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237225()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 352));
}


// ========================================================================
// __unwind$237226
// EA  : 0x825B3278
// RVA : 0x005B3278
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237226()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 368));
}


// ========================================================================
// __unwind$237227
// EA  : 0x825B32A4
// RVA : 0x005B32A4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237227()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 384));
}


// ========================================================================
// __unwind$237228
// EA  : 0x825B32D0
// RVA : 0x005B32D0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237228()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 400));
}


// ========================================================================
// __unwind$237229
// EA  : 0x825B32FC
// RVA : 0x005B32FC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237229()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$237230
// EA  : 0x825B3328
// RVA : 0x005B3328
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237230()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 432));
}


// ========================================================================
// __unwind$237231
// EA  : 0x825B3354
// RVA : 0x005B3354
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237231()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 448));
}


// ========================================================================
// __unwind$237232
// EA  : 0x825B3380
// RVA : 0x005B3380
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237232()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 464));
}


// ========================================================================
// __unwind$237233
// EA  : 0x825B33AC
// RVA : 0x005B33AC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237233()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 480));
}


// ========================================================================
// __unwind$237234
// EA  : 0x825B33D8
// RVA : 0x005B33D8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237234()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 496));
}


// ========================================================================
// __unwind$237235
// EA  : 0x825B3404
// RVA : 0x005B3404
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237235()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 512));
}


// ========================================================================
// __unwind$237236
// EA  : 0x825B3430
// RVA : 0x005B3430
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237236()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 528));
}


// ========================================================================
// __unwind$237237
// EA  : 0x825B345C
// RVA : 0x005B345C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237237()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 544));
}


// ========================================================================
// __unwind$237238
// EA  : 0x825B3488
// RVA : 0x005B3488
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237238()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 560));
}


// ========================================================================
// __unwind$237239
// EA  : 0x825B34B4
// RVA : 0x005B34B4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237239()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 576));
}


// ========================================================================
// __unwind$237240
// EA  : 0x825B34E0
// RVA : 0x005B34E0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237240()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 592));
}


// ========================================================================
// __unwind$237241
// EA  : 0x825B350C
// RVA : 0x005B350C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237241()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 608));
}


// ========================================================================
// __unwind$237242
// EA  : 0x825B3538
// RVA : 0x005B3538
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237242()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 624));
}


// ========================================================================
// __unwind$237243
// EA  : 0x825B3564
// RVA : 0x005B3564
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237243()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 640));
}


// ========================================================================
// __unwind$237244
// EA  : 0x825B3590
// RVA : 0x005B3590
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237244()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 656));
}


// ========================================================================
// __unwind$237245
// EA  : 0x825B35BC
// RVA : 0x005B35BC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237245()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 672));
}


// ========================================================================
// __unwind$237246
// EA  : 0x825B35E8
// RVA : 0x005B35E8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237246()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 688));
}


// ========================================================================
// __unwind$237247
// EA  : 0x825B3614
// RVA : 0x005B3614
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237247()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 704));
}


// ========================================================================
// ??1idAAS2File@@UAA@XZ
// EA  : 0x825B3658
// RVA : 0x005B3658
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::~idAAS2File(idAAS2File *this)
{
  this->__vftable = (idAAS2File_vtbl *)&idAAS2File::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areaBounds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hintNodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traversalPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chokePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touchingCoverIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areaCoverIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cover);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traversalEntityNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->interactionEntityNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dependencyNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilityNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->obstaclePVS);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clusters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portalIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->portals);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->areas);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reachabilities);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeIndex);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
  idAAS2Settings::~idAAS2Settings(this: (idAnimator_AF::idBindConstraint *)&this->settings);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visitedAreas);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$237492
// EA  : 0x825B3774
// RVA : 0x005B3774
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237492()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$237493
// EA  : 0x825B379C
// RVA : 0x005B379C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237493()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$237494
// EA  : 0x825B37C8
// RVA : 0x005B37C8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237494()
{
  int v0; // r12

  idAAS2Settings::~idAAS2Settings(this: (idAnimator_AF::idBindConstraint *)(*(_DWORD *)(v0 - 112 + 132) + 60));
}


// ========================================================================
// __unwind$237495
// EA  : 0x825B37F4
// RVA : 0x005B37F4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237495()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 352));
}


// ========================================================================
// __unwind$237496
// EA  : 0x825B3820
// RVA : 0x005B3820
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237496()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 368));
}


// ========================================================================
// __unwind$237497
// EA  : 0x825B384C
// RVA : 0x005B384C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 384));
}


// ========================================================================
// __unwind$237498
// EA  : 0x825B3878
// RVA : 0x005B3878
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237498()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 400));
}


// ========================================================================
// __unwind$237499
// EA  : 0x825B38A4
// RVA : 0x005B38A4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237499()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$237500
// EA  : 0x825B38D0
// RVA : 0x005B38D0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237500()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 432));
}


// ========================================================================
// __unwind$237501
// EA  : 0x825B38FC
// RVA : 0x005B38FC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237501()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 448));
}


// ========================================================================
// __unwind$237502
// EA  : 0x825B3928
// RVA : 0x005B3928
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237502()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 464));
}


// ========================================================================
// __unwind$237503
// EA  : 0x825B3954
// RVA : 0x005B3954
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237503()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 480));
}


// ========================================================================
// __unwind$237504
// EA  : 0x825B3980
// RVA : 0x005B3980
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237504()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 496));
}


// ========================================================================
// __unwind$237505
// EA  : 0x825B39AC
// RVA : 0x005B39AC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237505()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 512));
}


// ========================================================================
// __unwind$237506
// EA  : 0x825B39D8
// RVA : 0x005B39D8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237506()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$237507
// EA  : 0x825B3A04
// RVA : 0x005B3A04
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237507()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 544));
}


// ========================================================================
// __unwind$237508
// EA  : 0x825B3A30
// RVA : 0x005B3A30
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237508()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 560));
}


// ========================================================================
// __unwind$237509
// EA  : 0x825B3A5C
// RVA : 0x005B3A5C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237509()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 576));
}


// ========================================================================
// __unwind$237510
// EA  : 0x825B3A88
// RVA : 0x005B3A88
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237510()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 592));
}


// ========================================================================
// __unwind$237511
// EA  : 0x825B3AB4
// RVA : 0x005B3AB4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237511()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 608));
}


// ========================================================================
// __unwind$237512
// EA  : 0x825B3AE0
// RVA : 0x005B3AE0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237512()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 624));
}


// ========================================================================
// __unwind$237513
// EA  : 0x825B3B0C
// RVA : 0x005B3B0C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237513()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// __unwind$237514
// EA  : 0x825B3B38
// RVA : 0x005B3B38
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237514()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 656));
}


// ========================================================================
// __unwind$237515
// EA  : 0x825B3B64
// RVA : 0x005B3B64
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237515()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 672));
}


// ========================================================================
// __unwind$237516
// EA  : 0x825B3B90
// RVA : 0x005B3B90
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 688));
}


// ========================================================================
// __unwind$237517
// EA  : 0x825B3BBC
// RVA : 0x005B3BBC
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_237517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 704));
}


// ========================================================================
// ?ParseIndex@idAAS2File@@AAA_NAAVidLexer@@AAV?$idList@H$04@@@Z
// EA  : 0x825B3BE8
// RVA : 0x005B3BE8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseIndex(
        idAAS2File *this,
        idLexer *src,
        idList<idSpawnArea::GeneratedPosition *,5> *indexes)
{
  int v5; // r3
  int v6; // r30
  int v8; // [sp+50h] [-40h] BYREF

  v5 = idLexer::ParseInt(this: src);
  v6 = v5;
  if ( v5 > indexes->size )
    idList<idNavSpline *,5>::Resize(this: indexes, newsize: v5);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v8 = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)indexes,
        obj: (const encounterGroupRole_t *)&v8);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?GetTraversalsForReachability@idAAS2File@@QBAHV?$idIndex@FW4invalidReachability_t@@@@AAV?$idList@H$04@@@Z
// EA  : 0x825B3CC8
// RVA : 0x005B3CC8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetTraversalsForReachability(
        idAAS2File *this,
        const idIndex<short,enum invalidReachability_t> *reachIndex,
        idList<idVehicleState *,5> *traversals)
{
  aas2Reachability_t *v5; // r29
  char *v6; // r30
  int v7; // r31
  int v8; // r10
  aas2Traversal_t *v9; // r11
  int v10; // r11
  int v11; // r10
  int v13; // [sp+50h] [-40h] BYREF

  v5 = &this->reachabilities.list[(__int16)reachIndex];
  if ( traversals->size < 0 )
    idList<idThread *,58>::Clear(this: traversals);
  traversals->num = __CFADD__(-traversals->size, traversals->size ^ 0x80000000) ? 0 : traversals->size;
  v6 = (char *)this->areas.list + 8 * v5->fromAreaNum + 8 * __ROL4__(v5->fromAreaNum, 2);
  v7 = *((unsigned __int16 *)v6 + 16);
  v8 = *((unsigned __int16 *)v6 + 17) + v7;
  v13 = v7;
  if ( v7 < v8 )
  {
    do
    {
      v9 = &this->traversalPoints.list[v7];
      if ( v9->startAreaNum == v5->fromAreaNum && v9->endAreaNum == v5->toAreaNum )
      {
        if ( idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,5>::IsFull(this: (idList<int,5> *)traversals) )
          return traversals->num;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)traversals,
          obj: (const encounterGroupRole_t *)&v13);
      }
      v10 = *((unsigned __int16 *)v6 + 17);
      ++v7;
      v11 = *((unsigned __int16 *)v6 + 16);
      v13 = v7;
    }
    while ( v7 < v10 + v11 );
  }
  return traversals->num;
}


// ========================================================================
// ?GetTraversalsForInteractableEntity@idAAS2File@@QBAHV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@AAV?$idList@H$04@@@Z
// EA  : 0x825B3DD0
// RVA : 0x005B3DD0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::GetTraversalsForInteractableEntity(
        idAAS2File *this,
        const idIndex<short,enum invalidAASInteractionEntIndex_t> *intrEntIndex,
        idList<idVehicleState *,5> *traversals)
{
  __int16 v4; // r29
  int size; // r11
  int v7; // r31
  int num; // r11
  int v10; // [sp+50h] [-30h] BYREF

  v4 = (__int16)intrEntIndex;
  if ( traversals->size < 0 )
    idList<idThread *,58>::Clear(this: traversals);
  size = traversals->size;
  v7 = 0;
  v10 = 0;
  traversals->num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
  if ( this->traversalPoints.num > 0 )
  {
    do
    {
      if ( this->traversalPoints.list[v7].interactionEntIndex.value == v4 )
      {
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)traversals,
          obj: (const encounterGroupRole_t *)&v10);
        if ( idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,5>::IsFull(this: (idList<int,5> *)traversals) )
          break;
      }
      num = this->traversalPoints.num;
      v10 = ++v7;
    }
    while ( v7 < num );
  }
  return traversals->num;
}


// ========================================================================
// ?WriteBinary@idAAS2File@@AAA_NPBD0II@Z
// EA  : 0x825B3E98
// RVA : 0x005B3E98
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::WriteBinary(
        idAAS2File *this,
        const char *fileName,
        const char *binaryFileName,
        unsigned int mapFileCRC,
        unsigned int sourceTimestamp,
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
        unsigned int a18,
        int a19,
        unsigned int a20)
{
  int v22; // r10
  int v23; // r11
  idFile *v24; // r3
  char v26; // [sp+50h] [-90h] BYREF
  char v27; // [sp+51h] [-8Fh] BYREF
  char v28[2]; // [sp+52h] [-8Eh] BYREF
  idFileLocal v29; // [sp+54h] [-8Ch] BYREF
  int num; // [sp+58h] [-88h] BYREF
  int v31; // [sp+5Ch] [-84h] BYREF
  int v32; // [sp+60h] [-80h] BYREF
  int v33; // [sp+64h] [-7Ch] BYREF
  int v34; // [sp+68h] [-78h] BYREF
  int v35; // [sp+6Ch] [-74h] BYREF
  int v36; // [sp+70h] [-70h] BYREF
  int v37; // [sp+74h] [-6Ch] BYREF
  int v38; // [sp+78h] [-68h] BYREF
  int v39; // [sp+7Ch] [-64h] BYREF
  int v40; // [sp+80h] [-60h] BYREF
  int v41; // [sp+84h] [-5Ch] BYREF
  int v42; // [sp+88h] [-58h] BYREF
  int v43; // [sp+8Ch] [-54h] BYREF
  int v44; // [sp+90h] [-50h] BYREF
  int v45; // [sp+94h] [-4Ch] BYREF
  int v46; // [sp+98h] [-48h] BYREF
  int v47; // [sp+9Ch] [-44h] BYREF
  int v48; // [sp+A0h] [-40h] BYREF
  int v49; // [sp+A4h] [-3Ch] BYREF
  int v50; // [sp+A8h] [-38h] BYREF
  int v51; // [sp+ACh] [-34h] BYREF
  int v52[12]; // [sp+B0h] [-30h] BYREF

  a18 = mapFileCRC;
  a20 = sourceTimestamp;
  idLib::Printf(fmt: "[Writing AAS Binary]\n");
  idLib::Printf(fmt: "writing '%s'\n", binaryFileName);
  v22 = 0;
  if ( this->cover.num > 0 )
  {
    v23 = 0;
    do
    {
      ++v22;
      this->cover.list[v23].reservedBy = 0x1FFF;
      this->cover.list[v23++].usableTime = 0;
    }
    while ( v22 < this->cover.num );
  }
  v24 = fileSystem->OpenFileWrite(this: fileSystem, a2: binaryFileName, a3: 0);
  v29.file = v24;
  if ( v24 == nullptr )
    idLib::Error(fmt: "Error opening %s", binaryFileName);
  v24->Write(this: v24, a2: &AAS2_FILE_ID_BINARY, a3: 4u);
  v26 = 3;
  v27 = 18;
  v28[0] = 97;
  v29.file->Write(this: v29.file, a2: &v26, a3: 1u);
  v29.file->Write(this: v29.file, a2: &v27, a3: 1u);
  v29.file->Write(this: v29.file, a2: v28, a3: 1u);
  v29.file->Write(this: v29.file, a2: &a20, a3: 4u);
  v29.file->Write(this: v29.file, a2: &a18, a3: 4u);
  v29.file->Write(this: v29.file, a2: &this->firstFakeVertex, a3: 4u);
  v29.file->Write(this: v29.file, a2: &this->firstFakeEdge, a3: 4u);
  v29.file->Write(this: v29.file, a2: &this->firstFakeEdgeIndex, a3: 4u);
  v29.file->Write(this: v29.file, a2: &this->firstFakeArea, a3: 4u);
  idAAS2Settings::WriteToFileBinary(this: &this->settings, fp: v29.file);
  num = this->planes.num;
  v29.file->Write(this: v29.file, a2: &num, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->planes.list, a3: 16 * this->planes.num);
  v31 = this->vertices.num;
  v29.file->Write(this: v29.file, a2: &v31, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->vertices.list, a3: 12 * this->vertices.num);
  v32 = this->edges.num;
  v29.file->Write(this: v29.file, a2: &v32, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->edges.list, a3: 12 * this->edges.num);
  v33 = this->edgeIndex.num;
  v29.file->Write(this: v29.file, a2: &v33, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->edgeIndex.list, a3: 4 * this->edgeIndex.num);
  v34 = this->reachabilities.num;
  v29.file->Write(this: v29.file, a2: &v34, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->reachabilities.list, a3: 32 * this->reachabilities.num);
  v35 = this->areas.num;
  v29.file->Write(this: v29.file, a2: &v35, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->areas.list, a3: 40 * this->areas.num);
  v36 = this->nodes.num;
  v29.file->Write(this: v29.file, a2: &v36, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->nodes.list, a3: 16 * this->nodes.num);
  v37 = this->portals.num;
  v29.file->Write(this: v29.file, a2: &v37, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->portals.list, a3: 12 * this->portals.num);
  v38 = this->portalIndex.num;
  v29.file->Write(this: v29.file, a2: &v38, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->portalIndex.list, a3: 4 * this->portalIndex.num);
  v39 = this->clusters.num;
  v29.file->Write(this: v29.file, a2: &v39, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->clusters.list, a3: 16 * this->clusters.num);
  v40 = this->obstaclePVS.num;
  v29.file->Write(this: v29.file, a2: &v40, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->obstaclePVS.list, a3: this->obstaclePVS.num);
  v41 = this->reachabilityNames.num;
  v29.file->Write(this: v29.file, a2: &v41, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->reachabilityNames.list, a3: 132 * this->reachabilityNames.num);
  v42 = this->animNames.num;
  v29.file->Write(this: v29.file, a2: &v42, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->animNames.list, a3: this->animNames.num << 7);
  v43 = this->dependencyNames.num;
  v29.file->Write(this: v29.file, a2: &v43, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->dependencyNames.list, a3: this->dependencyNames.num << 7);
  v44 = this->interactionEntityNames.num;
  v29.file->Write(this: v29.file, a2: &v44, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->interactionEntityNames.list, a3: this->interactionEntityNames.num << 7);
  v45 = this->traversalEntityNames.num;
  v29.file->Write(this: v29.file, a2: &v45, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->traversalEntityNames.list, a3: this->traversalEntityNames.num << 7);
  v46 = this->cover.num;
  v29.file->Write(this: v29.file, a2: &v46, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->cover.list, a3: 56 * this->cover.num);
  v47 = this->areaCoverIndex.num;
  v29.file->Write(this: v29.file, a2: &v47, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->areaCoverIndex.list, a3: 4 * this->areaCoverIndex.num);
  v48 = this->touchingCoverIndex.num;
  v29.file->Write(this: v29.file, a2: &v48, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->touchingCoverIndex.list, a3: 4 * this->touchingCoverIndex.num);
  v49 = this->traversalPoints.num;
  v29.file->Write(this: v29.file, a2: &v49, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->traversalPoints.list, a3: 56 * this->traversalPoints.num);
  v50 = this->hintNodes.num;
  v29.file->Write(this: v29.file, a2: &v50, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->hintNodes.list, a3: 24 * this->hintNodes.num);
  v51 = this->trees.num;
  v29.file->Write(this: v29.file, a2: &v51, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->trees.list, a3: 24 * this->trees.num);
  v52[0] = this->areaBounds.num;
  v29.file->Write(this: v29.file, a2: v52, a3: 4u);
  v29.file->Write(this: v29.file, a2: this->areaBounds.list, a3: 12 * this->areaBounds.num);
  idFileLocal::~idFileLocal(this: &v29);
  return 1;
}


// ========================================================================
// $LN332
// EA  : 0x825B46F8
// RVA : 0x005B46F8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _LN332()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 224 + 84));
}


// ========================================================================
// ?ParseNames@idAAS2File@@AAA_NAAVidLexer@@AAV?$idList@Uaas2Name_t@@$04@@@Z
// EA  : 0x825B5290
// RVA : 0x005B5290
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseNames(idAAS2File *this, idLexer *src, idList<aas2Name_t,5> *names)
{
  int v5; // r3
  int v6; // r29
  idToken v8; // [sp+50h] [-120h] BYREF
  aas2Name_t v9; // [sp+A0h] [-D0h] BYREF

  v5 = idLexer::ParseInt(this: src);
  v6 = v5;
  if ( v5 > names->size )
    idList<aas2Name_t,37>::Resize(this: names, newsize: v5);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      v8.floatvalue = -3.4028235e38;
      v8.allocedAndFlag = 20;
      v8.data = v8.baseBuffer;
      v8.len = 0;
      v8.baseBuffer[0] = 0;
      v8.intvalue = 0;
      memset(&v8.whiteSpaceStart_p, 0, 12);
      idLexer::ReadToken(this: src, token: &v8);
      idStr::Copynz(dest: v9.name, src: v8.data, destsize: 128);
      v9.index = idLexer::ParseInt(this: src);
      idList<aas2Name_t,5>::Append(this: names, obj: &v9);
      idStr::FreeData(this: &v8);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// __unwind$239852
// EA  : 0x825B53A0
// RVA : 0x005B53A0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_239852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 80));
}


// ========================================================================
// ?ParseInteractionEntityNames@idAAS2File@@AAA_NAAVidLexer@@AAV?$idList@Uaas2InteractionEntityName_t@@$04@@@Z
// EA  : 0x825B53D0
// RVA : 0x005B53D0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseInteractionEntityNames(
        idAAS2File *this,
        idLexer *src,
        idList<aas2TraversalEntityName_t,5> *names)
{
  int v5; // r3
  int v6; // r29
  idToken v8; // [sp+50h] [-110h] BYREF
  aas2TraversalEntityName_t v9; // [sp+A0h] [-C0h] BYREF

  v5 = idLexer::ParseInt(this: src);
  v6 = v5;
  if ( v5 > names->size )
    idList<aas2TraversalEntityName_t,5>::Resize(this: names, newsize: v5);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      v8.floatvalue = -3.4028235e38;
      v8.allocedAndFlag = 20;
      v8.data = v8.baseBuffer;
      v8.len = 0;
      v8.baseBuffer[0] = 0;
      v8.intvalue = 0;
      memset(&v8.whiteSpaceStart_p, 0, 12);
      idLexer::ReadToken(this: src, token: &v8);
      idStr::Copynz(dest: v9.name, src: v8.data, destsize: 128);
      idList<aas2TraversalEntityName_t,5>::Append(this: names, obj: &v9);
      idStr::FreeData(this: &v8);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// __unwind$240156
// EA  : 0x825B54D4
// RVA : 0x005B54D4
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_240156()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 80));
}


// ========================================================================
// ?ParseVertices@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B5500
// RVA : 0x005B5500
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseVertices(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int v5; // r29
  idList<idVec3,5> *p_vertices; // r30
  int v8; // r31
  idVec3 v9[5]; // [sp+50h] [-40h] BYREF

  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  p_vertices = (idList<idVec3,5> *)&this->vertices;
  if ( v4 + 1 > this->vertices.size )
    idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->vertices, newsize: v4 + 1);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  v8 = 0;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      idLexer::ParseInt(this: src);
      if ( !idLexer::Parse1DMatrix(this: src, x: 3, m: &v9[0].x, expectCommas: false) )
        break;
      idList<idAngles,5>::Append(this: p_vertices, obj: v9);
      if ( ++v8 >= v5 )
        return idLexer::ExpectTokenString(this: src, string: "}");
    }
    return false;
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseEdges@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B55D8
// RVA : 0x005B55D8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseEdges(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<aas2Edge_t,37> *p_edges; // r27
  int v6; // r30
  int size; // r11
  aas2Edge_t v9; // [sp+50h] [-40h] BYREF

  p_edges = &this->edges;
  v4 = idLexer::ParseInt(this: src);
  size = this->edges.size;
  v6 = v4;
  if ( v4 > size )
    idList<testAlloc_t,5>::Resize(this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)p_edges, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v9.vertexNum[0] = idLexer::ParseInt(this: src);
      v9.vertexNum[1] = idLexer::ParseInt(this: src);
      v9.flags = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<idRenderModelEffects::deferredStage_t,5>::Append(this: p_edges, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseNodes@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B56D0
// RVA : 0x005B56D0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseNodes(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<idPlane,37> *p_nodes; // r27
  int v6; // r30
  int size; // r11
  idPlane v9; // [sp+50h] [-40h] BYREF

  p_nodes = (idList<idPlane,37> *)&this->nodes;
  v4 = idLexer::ParseInt(this: src);
  size = this->nodes.size;
  v6 = v4;
  if ( v4 > size )
    idList<idPlayerCoverScore_t,5>::Resize(this: p_nodes, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      LODWORD(v9.a) = idLexer::ParseInt(this: src);
      LODWORD(v9.b) = idLexer::ParseInt(this: src);
      LODWORD(v9.c) = idLexer::ParseInt(this: src);
      LODWORD(v9.d) = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<aas2Cluster_t,37>::Append(this: p_nodes, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParsePortals@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B57D8
// RVA : 0x005B57D8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParsePortals(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<aas2Portal_t,37> *p_portals; // r27
  int v6; // r30
  int size; // r11
  aas2Portal_t v9; // [sp+50h] [-40h] BYREF

  p_portals = &this->portals;
  v4 = idLexer::ParseInt(this: src);
  size = this->portals.size;
  v6 = v4;
  if ( v4 > size )
    idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Resize(this: (idList<aas2AreaBounds_t,37> *)p_portals, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v9.areaNum = idLexer::ParseInt(this: src);
      v9.clusters[0] = idLexer::ParseInt(this: src);
      v9.clusters[1] = idLexer::ParseInt(this: src);
      v9.clusterAreaNum[0] = idLexer::ParseInt(this: src);
      v9.clusterAreaNum[1] = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Append(this: p_portals, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseClusters@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B5900
// RVA : 0x005B5900
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseClusters(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<idPlane,37> *p_clusters; // r27
  int v6; // r30
  int size; // r11
  idPlane v9; // [sp+50h] [-40h] BYREF

  p_clusters = (idList<idPlane,37> *)&this->clusters;
  v4 = idLexer::ParseInt(this: src);
  size = this->clusters.size;
  v6 = v4;
  if ( v4 > size )
    idList<idPlayerCoverScore_t,5>::Resize(this: p_clusters, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      LODWORD(v9.a) = idLexer::ParseInt(this: src);
      LODWORD(v9.b) = idLexer::ParseInt(this: src);
      LODWORD(v9.d) = idLexer::ParseInt(this: src);
      LODWORD(v9.c) = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<aas2Cluster_t,37>::Append(this: p_clusters, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseObstaclePVS@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B5A08
// RVA : 0x005B5A08
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseObstaclePVS(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<unsigned char,37> *p_obstaclePVS; // r27
  int v6; // r30
  int size; // r11
  unsigned __int8 v9; // [sp+50h] [-40h] BYREF

  p_obstaclePVS = &this->obstaclePVS;
  v4 = idLexer::ParseInt(this: src);
  size = this->obstaclePVS.size;
  v6 = v4;
  if ( v4 > size )
    idList<unsigned char,25>::Resize(this: p_obstaclePVS, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v9 = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<unsigned char,25>::Append(this: p_obstaclePVS, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?CalculateAreaBounds@idAAS2File@@QAAXXZ
// EA  : 0x825B5AF0
// RVA : 0x005B5AF0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::CalculateAreaBounds(idAAS2File *this)
{
  int num; // r31
  idList<aas2AreaBounds_t,37> *p_areaBounds; // r24
  int size; // r11
  int v5; // r25
  int v6; // r26
  int v7; // r27
  aas2Area_t *v10; // r29
  aas2AreaBounds_t *v12; // r31
  int v14; // r30
  float *v17; // r3
  char v24; // [sp+60h] [-A0h] BYREF

  num = this->areas.num;
  p_areaBounds = &this->areaBounds;
  if ( num <= this->areaBounds.size
    || idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Resize(this: &this->areaBounds, newsize: this->areas.num) )
  {
    size = p_areaBounds->size;
    if ( num < size )
      size = num;
    p_areaBounds->num = size;
  }
  v5 = 0;
  if ( this->areas.num > 0 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      _FP31 = 1.0e30;
      _FP28 = -1.0e30;
      v10 = &this->areas.list[v6];
      _FP29 = 1.0e30;
      v12 = &p_areaBounds->list[v7];
      _FP30 = 1.0e30;
      v14 = 0;
      _FP26 = -1.0e30;
      _FP27 = -1.0e30;
      while ( v14 < v10->numEdges )
      {
        v17 = (float *)idAAS2File::EdgeBounds(
                         this: (idAAS2File *)&v24,
                         result: (idBounds *)this,
                         edgeNum: abs32(this->edgeIndex.list[v10->firstEdge + v14]));
        _FP12 = (float)((float)_FP31 - *v17);
        _FP10 = (float)((float)_FP30 - v17[1]);
        _FP8 = (float)((float)_FP29 - v17[2]);
        _FP6 = (float)(v17[3] - (float)_FP28);
        _FP4 = (float)(v17[4] - (float)_FP27);
        _FP3 = (float)(v17[5] - (float)_FP26);
        ++v14;
        __asm
        {
          fsel      f31, f12, f0, f31
          fsel      f30, f10, f13, f30
          fsel      f29, f8, f11, f29
          fsel      f28, f6, f9, f28
          fsel      f27, f4, f7, f27
          fsel      f26, f3, f5, f26
        }
      }
      ++v5;
      ++v7;
      ++v6;
      v12->min[1] = (int)(float)((float)_FP30 + (float)65535.0) + 1;
      v12->max[1] = (int)(float)((float)_FP27 - (float)65535.0) - 1;
      v12->max[0] = (int)(float)((float)_FP28 - (float)65535.0) - 1;
      v12->min[2] = (int)(float)((float)_FP29 + (float)65535.0) + 1;
      v12->min[0] = (int)(float)((float)_FP31 + (float)65535.0) + 1;
      v12->max[2] = (int)(float)((float)_FP26 - (float)65535.0) - 1;
    }
    while ( v5 < this->areas.num );
  }
}


// ========================================================================
// ?ParsePlanes@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B6608
// RVA : 0x005B6608
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParsePlanes(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int v5; // r30
  idList<idPlane,37> *p_planes; // r29
  int v8; // r31
  float v9[4]; // [sp+50h] [-50h] BYREF
  idPlane v10; // [sp+60h] [-40h] BYREF

  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  p_planes = &this->planes;
  if ( v4 > this->planes.size )
    idList<idPlayerCoverScore_t,5>::Resize(this: &this->planes, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  v8 = 0;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      idLexer::ParseInt(this: src);
      if ( !idLexer::Parse1DMatrix(this: src, x: 4, m: v9, expectCommas: false) )
        break;
      v10.a = v9[0];
      v10.b = v9[1];
      v10.c = v9[2];
      v10.d = -v9[3];
      idList<aas2Cluster_t,37>::Append(this: p_planes, obj: &v10);
      if ( ++v8 >= v5 )
        return idLexer::ExpectTokenString(this: src, string: "}");
    }
    return false;
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseReachabilities@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B6700
// RVA : 0x005B6700
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseReachabilities(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int v5; // r28
  aas2Reachability_t v7; // [sp+50h] [-50h] BYREF

  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  if ( v4 > this->reachabilities.size )
    idList<aas2Reachability_t,37>::Resize(this: &this->reachabilities, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v5 > 0 )
  {
    v7.next.value = -1;
    v7.rev_next.value = -1;
    v7.areaTTOfsAndNumber = 0;
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v7.travelFlags = idLexer::ParseInt(this: src);
      v7.travelTime = idLexer::ParseInt(this: src);
      v7.fromAreaNum = idLexer::ParseInt(this: src);
      v7.toAreaNum = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v7.start[0] = idLexer::ParseInt(this: src);
      v7.start[1] = idLexer::ParseInt(this: src);
      v7.start[2] = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: "(");
      v7.end[0] = idLexer::ParseInt(this: src);
      v7.end[1] = idLexer::ParseInt(this: src);
      v7.end[2] = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<aas2Reachability_t,37>::Append(this: &this->reachabilities, obj: &v7);
      --v5;
    }
    while ( v5 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseAreas@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B68B8
// RVA : 0x005B68B8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseAreas(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<aas2Area_t,37> *p_areas; // r25
  int v6; // r30
  int size; // r11
  aas2Area_t v9; // [sp+50h] [-70h] BYREF

  p_areas = &this->areas;
  v4 = idLexer::ParseInt(this: src);
  size = this->areas.size;
  v6 = v4;
  if ( v4 > size )
    idList<aas2Area_t,37>::Resize(this: p_areas, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v9.firstChokePoint = 0;
      v9.numChokePoints = 0;
      v9.flags = idLexer::ParseInt(this: src);
      v9.travelFlags = idLexer::ParseInt(this: src);
      v9.numEdges = idLexer::ParseInt(this: src);
      v9.firstEdge = idLexer::ParseInt(this: src);
      v9.cluster = idLexer::ParseInt(this: src);
      v9.clusterAreaNum = idLexer::ParseInt(this: src);
      v9.obstaclePVSOffset = idLexer::ParseInt(this: src);
      v9.reach.value = -1;
      v9.rev_reach.value = -1;
      v9.firstCover = idLexer::ParseInt(this: src);
      v9.numCover = idLexer::ParseInt(this: src);
      v9.firstTraversal = idLexer::ParseInt(this: src);
      v9.numTraversals = idLexer::ParseInt(this: src);
      v9.firstHintNode = idLexer::ParseInt(this: src);
      v9.numHintNodes = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idList<aas2Area_t,37>::Append(this: p_areas, obj: &v9);
      --v6;
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseCover@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B6A68
// RVA : 0x005B6A68
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseCover(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int v5; // r20
  int size; // r11
  int v8; // r23
  int v9; // r26
  aas2Cover_t *v10; // r31

  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  if ( v4 <= this->cover.size || (unsigned __int8)idList<aas2Cover_t,37>::Resize(this: &this->cover, newsize: v4) != 0 )
  {
    size = this->cover.size;
    if ( v5 < size )
      size = v5;
    this->cover.num = size;
  }
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  v8 = 0;
  if ( v5 > 0 )
  {
    v9 = 0;
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v10 = &this->cover.list[v9];
      v10->origin = vec3_origin;
      v10->dir = vec3_origin;
      v10->areaNum = 0;
      v10->durationSec = -1.0;
      v10->flags = 0;
      v10->minRange = 0.0;
      v10->numTouching = 0;
      v10->maxRange = 0.0;
      v10->firstTouching = 0;
      v10->reservedBy = 0x1FFF;
      v10->usableTime = 0;
      v10->origin.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->origin.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->origin.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->dir.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->dir.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->dir.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->areaNum = idLexer::ParseInt(this: src);
      v10->flags = idLexer::ParseInt(this: src);
      v10->firstTouching = idLexer::ParseInt(this: src);
      v10->numTouching = idLexer::ParseInt(this: src);
      if ( !idLexer::CheckTokenString(this: src, string: ")") )
      {
        v10->durationSec = idLexer::ParseFloat(this: src, errorFlag: nullptr);
        v10->minRange = idLexer::ParseFloat(this: src, errorFlag: nullptr);
        v10->maxRange = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      }
      idLexer::ExpectTokenString(this: src, string: ")");
      if ( v10->areaNum == 0 && v8 > 0 )
        idLib::Warning(
          fmt: "AAS %s: cover %d has an invalid area origin at (%f %f %f).",
          this->name.str,
          v10->origin.x,
          (unsigned int)COERCE_UNSIGNED_INT64(v10->origin.y),
          (unsigned int)COERCE_UNSIGNED_INT64(v10->origin.z));
      ++v8;
      ++v9;
    }
    while ( v8 < v5 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseTraversalPoints@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B6D28
// RVA : 0x005B6D28
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseTraversalPoints(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int v5; // r21
  int size; // r11
  int v8; // r29
  int v9; // r28
  aas2Traversal_t *v10; // r31

  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  if ( v4 <= this->traversalPoints.size
    || (unsigned __int8)idList<aas2Traversal_t,37>::Resize(this: &this->traversalPoints, newsize: v4) != 0 )
  {
    size = this->traversalPoints.size;
    if ( v5 < size )
      size = v5;
    this->traversalPoints.num = size;
  }
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  v8 = 0;
  if ( v5 > 0 )
  {
    v9 = 0;
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v10 = &this->traversalPoints.list[v9];
      aas2Traversal_t::Clear(this: v10);
      v10->startPoint.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->startPoint.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->startPoint.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->endPoint.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->endPoint.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->endPoint.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v10->orientationFwd.x = idLexer::ParseInt(this: src);
      v10->orientationFwd.y = idLexer::ParseInt(this: src);
      v10->orientationFwd.z = idLexer::ParseInt(this: src);
      v10->extrusionFwd.x = idLexer::ParseInt(this: src);
      v10->extrusionFwd.y = idLexer::ParseInt(this: src);
      v10->extrusionFwd.z = idLexer::ParseInt(this: src);
      v10->extrusionDistance = idLexer::ParseInt(this: src);
      v10->startAreaNum = idLexer::ParseInt(this: src);
      v10->endAreaNum = idLexer::ParseInt(this: src);
      v10->animIndex.value = idLexer::ParseInt(this: src);
      v10->reachabilityIndex.value = idLexer::ParseInt(this: src);
      v10->flags = idLexer::ParseInt(this: src);
      v10->dependencyIndex.value = idLexer::ParseInt(this: src);
      v10->interactionEntIndex.value = idLexer::ParseInt(this: src);
      v10->traversalNameIndex.value = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      if ( v10->startAreaNum == 0 && v8 > 0 )
        idLib::Warning(
          fmt: "AAS %s: traversal point %d has an invalid start area at (%f %f %f)",
          this->name.str,
          v10->startPoint.x,
          (unsigned int)COERCE_UNSIGNED_INT64(v10->startPoint.y),
          (unsigned int)COERCE_UNSIGNED_INT64(v10->startPoint.z));
      if ( v10->endAreaNum == 0 && v8 > 0 )
        idLib::Warning(
          fmt: "AAS %s: traversal point %d has an invalid end area at (%f %f %f)",
          this->name.str,
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v10->endPoint.x)),
          v10->endPoint.x,
          v10->endPoint.y,
          v10->endPoint.z);
      ++v8;
      ++v9;
    }
    while ( v8 < v5 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?ParseHintNodes@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B7018
// RVA : 0x005B7018
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseHintNodes(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  int num; // r4
  idList<aas2HintNode_t,37> *p_hintNodes; // r23
  int v7; // r27
  int size; // r11
  int v10; // r26
  aas2HintNode_t *v11; // r31
  double z; // fp0

  v4 = idLexer::ParseInt(this: src);
  num = this->hintNodes.num;
  p_hintNodes = &this->hintNodes;
  v7 = v4;
  if ( num > this->hintNodes.size )
    idList<aas2HintNode_t,37>::Resize(this: &this->hintNodes, newsize: num);
  if ( v7 <= this->hintNodes.size
    || (unsigned __int8)idList<aas2HintNode_t,37>::Resize(this: &this->hintNodes, newsize: v7) != 0 )
  {
    size = this->hintNodes.size;
    if ( v7 < size )
      size = v7;
    this->hintNodes.num = size;
  }
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v7 > 0 )
  {
    v10 = 0;
    do
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v11 = &p_hintNodes->list[v10];
      v11->origin.x = vec3_origin.x;
      v11->origin.y = vec3_origin.y;
      z = vec3_origin.z;
      v11->areaNum = 0;
      v11->origin.z = z;
      v11->radius = 128;
      v11->hintType = 0;
      v11->orientation = 0;
      v11->dirFlags = 0;
      v11->grouping = 0;
      v11->hintData = 0;
      v11->origin.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v11->origin.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v11->origin.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v11->areaNum = idLexer::ParseInt(this: src);
      v11->radius = idLexer::ParseInt(this: src);
      v11->hintType = idLexer::ParseInt(this: src);
      v11->orientation = idLexer::ParseInt(this: src);
      v11->dirFlags = idLexer::ParseInt(this: src);
      v11->grouping = idLexer::ParseInt(this: src);
      v11->hintData = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      --v7;
      ++v10;
    }
    while ( v7 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?MakeDefault@idAAS2File@@AAAXXZ
// EA  : 0x825B74C8
// RVA : 0x005B74C8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::MakeDefault(idAAS2File *this)
{
  unsigned __int16 *p_firstHintNode; // r10
  int i; // ctr
  aas2Area_t *v4; // r3
  unsigned __int16 *p_maxAreaTravelTime; // r10
  int j; // ctr
  aas2Cluster_t *v7; // r3
  aas2Cluster_t *v8; // r3
  idList<idAAS2File::bspTree_t,37> *p_trees; // r31
  int size; // r11
  idAAS2File::bspTree_t *list; // r11
  unsigned __int8 v12[4]; // [sp+50h] [-E0h] BYREF
  encounterGroupRole_t v13[3]; // [sp+54h] [-DCh] BYREF
  idPlane v14; // [sp+60h] [-D0h] BYREF
  idPlane v15; // [sp+70h] [-C0h] BYREF
  idPlane v16; // [sp+80h] [-B0h] BYREF
  idPlane v17; // [sp+90h] [-A0h] BYREF
  idPlane v18; // [sp+A0h] [-90h] BYREF
  idPlane v19; // [sp+B0h] [-80h] BYREF

  if ( this->resourceError == nullptr )
    idResource::SetResourceError(this, fmt: "defaulted '%s", this->name.str);
  idAAS2File::Clear(this);
  v18.a = 0.0;
  v18.b = -1.0;
  v18.c = 0.0;
  v18.d = 32768.0;
  idList<aas2Cluster_t,37>::Append(this: &this->planes, obj: &v18);
  v18.b = 0.0;
  v18.c = 0.0;
  v18.d = 32768.0;
  v18.a = 1.0;
  idList<aas2Cluster_t,37>::Append(this: &this->planes, obj: &v18);
  v18.a = 1.0;
  v18.b = 0.0;
  v18.c = 0.0;
  v18.d = -32768.0;
  idList<aas2Cluster_t,37>::Append(this: &this->planes, obj: &v18);
  v18.a = 0.0;
  v18.b = -1.0;
  v18.c = 0.0;
  v18.d = -32768.0;
  idList<aas2Cluster_t,37>::Append(this: &this->planes, obj: &v18);
  v18.a = 0.0;
  v18.b = 0.0;
  v18.c = 1.0;
  v18.d = 32768.0;
  idList<aas2Cluster_t,37>::Append(this: &this->planes, obj: &v18);
  v14.a = -32768.0;
  v14.b = -32768.0;
  v14.c = -32768.0;
  idList<idAngles,5>::Append(this: (idList<idVec3,5> *)&this->vertices, obj: (const idVec3 *)&v14);
  v14.a = -32768.0;
  v14.b = 32768.0;
  v14.c = -32768.0;
  idList<idAngles,5>::Append(this: (idList<idVec3,5> *)&this->vertices, obj: (const idVec3 *)&v14);
  v14.a = 32768.0;
  v14.b = 32768.0;
  v14.c = -32768.0;
  idList<idAngles,5>::Append(this: (idList<idVec3,5> *)&this->vertices, obj: (const idVec3 *)&v14);
  v14.a = 32768.0;
  v14.b = -32768.0;
  v14.c = -32768.0;
  idList<idAngles,5>::Append(this: (idList<idVec3,5> *)&this->vertices, obj: (const idVec3 *)&v14);
  memset(&v14, 0, 12);
  v15.a = 0.0;
  v18.b = 0.0;
  LODWORD(v15.b) = 1;
  LODWORD(v15.c) = 1;
  LODWORD(v16.a) = 1;
  LODWORD(v16.b) = 2;
  LODWORD(v16.c) = 1;
  LODWORD(v17.a) = 2;
  LODWORD(v17.b) = 3;
  LODWORD(v17.c) = 1;
  LODWORD(v18.a) = 3;
  LODWORD(v18.c) = 1;
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &this->edges, obj: (const aas2Edge_t *)&v14);
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &this->edges, obj: (const aas2Edge_t *)&v15);
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &this->edges, obj: (const aas2Edge_t *)&v16);
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &this->edges, obj: (const aas2Edge_t *)&v17);
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &this->edges, obj: (const aas2Edge_t *)&v18);
  v13[0] = ROLE_DEFEND;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->edgeIndex, obj: v13);
  v13[0] = ROLE_ASSAULT;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->edgeIndex, obj: v13);
  v13[0] = ROLE_FLANK;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->edgeIndex, obj: v13);
  v13[0] = ROLE_FLANK_CHARGE;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->edgeIndex, obj: v13);
  p_firstHintNode = &idList<aas2Area_t,37>::Alloc(this: &this->areas)[-1].firstHintNode;
  for ( i = 10; i != 0; --i )
  {
    p_firstHintNode += 2;
    *(_DWORD *)p_firstHintNode = 0;
  }
  v4 = idList<aas2Area_t,37>::Alloc(this: &this->areas);
  v4->numEdges = 4;
  v4->firstEdge = 0;
  v18.a = 0.0;
  v4->travelFlags = 8;
  v4->flags = 14;
  memset(&v18.b, 0, 12);
  v4->cluster = 1;
  v4->clusterAreaNum = 0;
  v4->obstaclePVSOffset = 1;
  v4->reach.value = -1;
  v4->rev_reach.value = -1;
  v4->firstChokePoint = 0;
  v4->numChokePoints = 0;
  v4->firstCover = 0;
  v4->numCover = 0;
  v4->firstTraversal = 0;
  v4->numTraversals = 0;
  v4->firstHintNode = 0;
  v4->numHintNodes = 0;
  v17.a = 0.0;
  v17.b = 0.0;
  LODWORD(v17.c) = 2;
  v17.d = 0.0;
  LODWORD(v16.a) = 1;
  v16.b = 0.0;
  LODWORD(v16.c) = 3;
  v16.d = 0.0;
  LODWORD(v15.a) = 2;
  v15.b = 0.0;
  v15.c = 0.0;
  LODWORD(v15.d) = 4;
  LODWORD(v14.a) = 3;
  v14.b = 0.0;
  v14.c = 0.0;
  LODWORD(v14.d) = 5;
  LODWORD(v19.a) = 4;
  v19.b = NAN;
  v19.c = NAN;
  v19.d = 0.0;
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v18);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v17);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v16);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v15);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v14);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->nodes, obj: &v19);
  p_maxAreaTravelTime = &idList<aas2Portal_t,37>::Alloc(this: &this->portals)[-1].maxAreaTravelTime;
  for ( j = 6; j != 0; --j )
    *++p_maxAreaTravelTime = 0;
  v7 = idList<idPlayerCoverScore_t,5>::Alloc(this: &this->clusters);
  v7->numAreas = 0;
  v7->numReachableAreas = 0;
  v7->numPortals = 0;
  v7->firstPortal = 0;
  v8 = idList<idPlayerCoverScore_t,5>::Alloc(this: &this->clusters);
  v12[0] = 1;
  v8->numAreas = 1;
  v8->numReachableAreas = 1;
  v8->numPortals = 0;
  v8->firstPortal = 0;
  idList<unsigned char,25>::Append(this: &this->obstaclePVS, obj: v12);
  v12[0] = 2;
  idList<unsigned char,25>::Append(this: &this->obstaclePVS, obj: v12);
  p_trees = &this->trees;
  if ( this->trees.size >= 1
    || (unsigned __int8)idList<idAAS2File::bspTree_t,37>::Resize(this: &this->trees, newsize: 1) != 0 )
  {
    size = this->trees.size;
    if ( size > 1 )
      size = 1;
    this->trees.num = size;
  }
  list = p_trees->list;
  list->floorNormal.x = 0.0;
  list->floorNormal.y = 0.0;
  list->floorNormal.z = 1.0;
  list->headNode = 1;
  p_trees->list->firstArea = 1;
  p_trees->list->lastArea = 2;
  idList<aas2Cover_t,37>::Alloc(this: &this->cover);
  idList<aas2Traversal_t,37>::Alloc(this: &this->traversalPoints);
}


// ========================================================================
// ?LoadBinary@idAAS2File@@AAA_NPBD0II@Z
// EA  : 0x825B7938
// RVA : 0x005B7938
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

int __fastcall idAAS2File::LoadBinary(
        idAAS2File *this,
        const char *fileName,
        const char *binaryFileName,
        unsigned int mapFileCRC,
        unsigned int sourceTimestamp)
{
  idFile *v10; // r3
  idFile *file; // r3
  idList<aas2Area_t,37> *p_areas; // r29
  __int64 v13; // r10
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int v17; // r4
  idIndex<int,enum invalidAASTree_t> *v18; // r28
  int v19; // r4
  char v21; // [sp+50h] [-60h] BYREF
  char v22; // [sp+51h] [-5Fh] BYREF
  _BYTE v23[2]; // [sp+52h] [-5Eh] BYREF
  idFileLocal v24; // [sp+54h] [-5Ch] BYREF
  int v25; // [sp+58h] [-58h] BYREF
  int v26; // [sp+5Ch] [-54h] BYREF
  int v27; // [sp+60h] [-50h] BYREF
  _DWORD v28[19]; // [sp+64h] [-4Ch] BYREF

  v10 = fileSystem->OpenFileRead(this: fileSystem, a2: binaryFileName, a3: 1, a4: 0);
  v24.file = v10;
  if ( v10 == nullptr )
  {
    idLib::Printf(fmt: "file '%s' not found\n", binaryFileName);
LABEL_26:
    idFileLocal::~idFileLocal(this: &v24);
    return 0;
  }
  v10->Read(this: v10, a2: &v26, a3: 4u);
  if ( v26 != 844316993 )
    goto LABEL_26;
  v24.file->Read(this: v24.file, a2: &v21, a3: 1u);
  v24.file->Read(this: v24.file, a2: &v22, a3: 1u);
  v24.file->Read(this: v24.file, a2: v23, a3: 1u);
  if ( v21 != 3 )
    goto LABEL_26;
  if ( v22 != 18 )
    goto LABEL_26;
  if ( v23[0] != 97 )
    goto LABEL_26;
  file = v24.file;
  this->major = 3;
  this->minor = 18;
  file->Read(this: file, a2: &v27, a3: 4u);
  if ( sourceTimestamp != 0 && sourceTimestamp != -1 && sourceTimestamp != v27 )
    goto LABEL_26;
  v24.file->Read(this: v24.file, a2: v28, a3: 4u);
  if ( v28[0] != mapFileCRC )
  {
    idLib::Warning(fmt: "AAS file '%s' is out of date", binaryFileName);
    goto LABEL_26;
  }
  v24.file->Read(this: v24.file, a2: &this->firstFakeVertex, a3: 4u);
  v24.file->Read(this: v24.file, a2: &this->firstFakeEdge, a3: 4u);
  v24.file->Read(this: v24.file, a2: &this->firstFakeEdgeIndex, a3: 4u);
  v24.file->Read(this: v24.file, a2: &this->firstFakeArea, a3: 4u);
  this->crc = mapFileCRC;
  this->timestamp = sourceTimestamp;
  if ( (unsigned __int8)idAAS2Settings::ReadFromFileBinary(this: &this->settings, fp: v24.file) == 0 )
    goto LABEL_26;
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<parmValue_t,56>::SetNum(this: &this->planes, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->planes.list, a3: 16 * this->planes.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  if ( v25 + 1 > this->vertices.size )
    idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->vertices, newsize: v25 + 1);
  idList<idVec3,37>::SetNum(this: (idList<idVec3,5> *)&this->vertices, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->vertices.list, a3: 12 * this->vertices.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idAnimWebBlendEquation::existingNode_t,5>::SetNum(
    this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&this->edges,
    newNum: v25);
  v24.file->Read(this: v24.file, a2: this->edges.list, a3: 12 * this->edges.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: &this->edgeIndex, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->edgeIndex.list, a3: 4 * this->edgeIndex.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Reachability_t,37>::SetNum(this: &this->reachabilities, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->reachabilities.list, a3: 32 * this->reachabilities.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  p_areas = &this->areas;
  idList<aas2Area_t,37>::SetNum(this: &this->areas, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->areas.list, a3: 40 * this->areas.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->nodes, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->nodes.list, a3: 16 * this->nodes.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Portal_t,37>::SetNum(this: (idList<aas2AreaBounds_t,37> *)&this->portals, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->portals.list, a3: 12 * this->portals.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: &this->portalIndex, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->portalIndex.list, a3: 4 * this->portalIndex.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->clusters, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->clusters.list, a3: 16 * this->clusters.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<unsigned char,19>::SetNum(this: &this->obstaclePVS, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->obstaclePVS.list, a3: this->obstaclePVS.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Name_t,37>::SetNum(this: &this->reachabilityNames, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->reachabilityNames.list, a3: 132 * this->reachabilityNames.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2AnimName_t,37>::SetNum(this: (idList<aas2TraversalEntityName_t,37> *)&this->animNames, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->animNames.list, a3: this->animNames.num << 7);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2AnimName_t,37>::SetNum(this: (idList<aas2TraversalEntityName_t,37> *)&this->dependencyNames, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->dependencyNames.list, a3: this->dependencyNames.num << 7);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2AnimName_t,37>::SetNum(
    this: (idList<aas2TraversalEntityName_t,37> *)&this->interactionEntityNames,
    newNum: v25);
  v24.file->Read(
    this: v24.file,
    a2: (void *)this->interactionEntityNames.list,
    a3: this->interactionEntityNames.num << 7);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2AnimName_t,37>::SetNum(this: &this->traversalEntityNames, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->traversalEntityNames.list, a3: this->traversalEntityNames.num << 7);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Cover_t,37>::SetNum(this: &this->cover, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->cover.list, a3: 56 * this->cover.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: &this->areaCoverIndex, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->areaCoverIndex.list, a3: 4 * this->areaCoverIndex.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: &this->touchingCoverIndex, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->touchingCoverIndex.list, a3: 4 * this->touchingCoverIndex.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Traversal_t,37>::SetNum(this: &this->traversalPoints, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->traversalPoints.list, a3: 56 * this->traversalPoints.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2HintNode_t,37>::SetNum(this: &this->hintNodes, newNum: v25);
  v24.file->Read(this: v24.file, a2: (void *)this->hintNodes.list, a3: 24 * this->hintNodes.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<idAAS2File::bspTree_t,37>::SetNum(this: &this->trees, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->trees.list, a3: 24 * this->trees.num);
  v24.file->Read(this: v24.file, a2: &v25, a3: 4u);
  idList<aas2Portal_t,37>::SetNum(this: &this->areaBounds, newNum: v25);
  v24.file->Read(this: v24.file, a2: this->areaBounds.list, a3: 12 * this->areaBounds.num);
  idFileLocal::~idFileLocal(this: &v24);
  idAAS2File::FlagNoPushAreas(this, a2: v17, a3: v16, a4: v15, a5: v14, a6: v13);
  v18 = nullptr;
  if ( this->trees.num > 0 )
  {
    while ( 1 )
    {
      v28[1] = v18;
      v19 = idAAS2File::MaxTreeDepth(this, tree: v18);
      if ( v19 > 128 )
        break;
      v18 = (idIndex<int,enum invalidAASTree_t> *)((char *)v18 + 1);
      if ( (int)v18 >= this->trees.num )
        goto LABEL_18;
    }
    idLib::Printf(fmt: "idAAS2File::LoadBinary: tree depth = %d for tree %d in '%s'", v19, v18, binaryFileName);
    idAAS2File::MakeDefault(this);
    return 0;
  }
LABEL_18:
  if ( idStr::Find(searchIn: fileName, searchFor: "ghost_hideout", casesensitive: true, start: 0, end: -1) == -1 )
  {
    if ( idStr::Find(searchIn: fileName, searchFor: "wellspring_coop", casesensitive: true, start: 0, end: -1) != -1
      && CRC32_BlockChecksum(data: p_areas->list, length: 40 * this->areas.num) == 706577107 )
    {
      p_areas->list[79].flags |= 0x10u;
    }
  }
  else if ( CRC32_BlockChecksum(data: p_areas->list, length: 40 * this->areas.num) == -137815694 )
  {
    p_areas->list[1271].travelFlags |= 1u;
    return 1;
  }
  return 1;
}


// ========================================================================
// __unwind$241528
// EA  : 0x825B839C
// RVA : 0x005B839C
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_241528()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 176 + 84));
}


// ========================================================================
// ?ParseTrees@idAAS2File@@AAA_NAAVidLexer@@@Z
// EA  : 0x825B8458
// RVA : 0x005B8458
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

BOOL __fastcall idAAS2File::ParseTrees(idAAS2File *this, idLexer *src)
{
  int v4; // r3
  idList<idAAS2File::bspTree_t,37> *p_trees; // r27
  int v6; // r30
  int size; // r11
  idAAS2File::bspTree_t *v9; // r26

  p_trees = &this->trees;
  v4 = idLexer::ParseInt(this: src);
  size = this->trees.size;
  v6 = v4;
  if ( v4 > size )
    idList<idAAS2File::bspTree_t,37>::Resize(this: p_trees, newsize: v4);
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    return false;
  if ( v6 > 0 )
  {
    do
    {
      idLexer::ParseInt(this: src);
      v9 = idList<idAAS2File::bspTree_t,37>::Alloc(this: p_trees);
      idLexer::ExpectTokenString(this: src, string: "(");
      v9->floorNormal.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v9->floorNormal.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v9->floorNormal.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      idLexer::ExpectTokenString(this: src, string: ")");
      v9->headNode = idLexer::ParseInt(this: src);
      v9->firstArea = idLexer::ParseInt(this: src);
      --v6;
      v9->lastArea = idLexer::ParseInt(this: src);
    }
    while ( v6 != 0 );
  }
  return idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?LoadResource@idAAS2File@@UAAXXZ
// EA  : 0x825B8588
// RVA : 0x005B8588
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __fastcall idAAS2File::LoadResource(idAAS2File *this)
{
  unsigned int v2; // r28
  int v3; // r3
  int v4; // r29
  idStr *v5; // r3
  idStr *v6; // r3
  int major; // r5
  int minor; // r5
  idAAS2File::bspTree_t *list; // r9
  double v10; // fp12
  double v11; // fp10
  int v12; // r10
  int v13; // r9
  aas2Reachability_t *v14; // r11
  int v15; // r8
  int v16; // r8
  int v17; // r10
  int v18; // r9
  int v19; // r8
  __int64 v20; // r10
  int v21; // r7
  int v22; // r6
  int v23; // r5
  int v24; // r4
  char *v25; // r29
  int v26; // r5
  int v27; // [sp+8h] [-368h]
  int v28; // [sp+Ch] [-364h]
  int v29; // [sp+10h] [-360h]
  int v30; // [sp+14h] [-35Ch]
  int v31; // [sp+18h] [-358h]
  int v32; // [sp+1Ch] [-354h]
  int v33; // [sp+20h] [-350h]
  int v34; // [sp+24h] [-34Ch]
  int v35; // [sp+28h] [-348h]
  unsigned int v36; // [sp+2Ch] [-344h]
  int v37; // [sp+30h] [-340h]
  unsigned int v38; // [sp+34h] [-33Ch]
  idStr v39; // [sp+50h] [-320h] BYREF
  idStr v40; // [sp+70h] [-300h] BYREF
  idToken v41; // [sp+90h] [-2E0h] BYREF
  const char *p_gravityDir; // [sp+D8h] [-298h]
  unsigned int v43; // [sp+DCh] [-294h]
  idLexer v44; // [sp+E0h] [-290h] BYREF
  const char *v45; // [sp+168h] [-208h]
  const char *v46; // [sp+16Ch] [-204h]
  const char *v47; // [sp+170h] [-200h]
  const char *v48; // [sp+174h] [-1FCh]
  const char *v49; // [sp+178h] [-1F8h]
  const char *v50; // [sp+17Ch] [-1F4h]
  const char *v51; // [sp+180h] [-1F0h]
  idStr v52; // [sp+190h] [-1E0h] BYREF
  idStr v53; // [sp+1B0h] [-1C0h] BYREF
  char v54[416]; // [sp+1D0h] [-1A0h] BYREF

  idStr::idStr(this: &v39, text: this->name.str);
  idLexer::idLexer(this: &v44, flags_: 564);
  v41.len = 0;
  v41.baseBuffer[0] = 0;
  v41.intvalue = 0;
  v41.floatvalue = -3.4028235e38;
  memset(&v41.whiteSpaceStart_p, 0, 12);
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  idStr::ExtractFileExtension(this: &v39, dest: &this->settings.fileExtensionAAS);
  v40.len = 0;
  v40.baseBuffer[0] = 0;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  idStr::EnsureAlloced(this: &v40, amount: 2, keepold: true, geometricGrowth: false);
  *v40.data = 98;
  v40.data[1] = 0;
  v40.len = 1;
  idStr::Append(this: &v40, text: &this->settings.fileExtensionAAS);
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: v40.data, a4: v39.data, a5: v54, a6: 256);
  v43 = 0;
  v2 = 0;
  if ( idLib::production == PROD_DEVELOPMENT )
  {
    v2 = fileSystem->GetTimestamp(this: fileSystem, a2: v39.data, a3: false);
    v43 = v2;
  }
  if ( (unsigned __int8)idAAS2File::LoadBinary(
                          this,
                          fileName: v39.data,
                          binaryFileName: v54,
                          mapFileCRC: 0,
                          sourceTimestamp: v2) != 0 )
    goto LABEL_4;
  idLib::Printf(fmt: "[Load AAS]\n");
  if ( !idLexer::LoadFile(this: &v44, filename_: v39.data, OSPath: false) )
  {
    idResource::SetResourceError(this, fmt: "AAS2File '%s' file not found", v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  idLib::Printf(fmt: "loading %s\n", v39.data);
  if ( !idLexer::ExpectTokenString(this: &v44, string: AAS2_FILE_ID) )
  {
    idResource::SetResourceError(this, fmt: "Not an AAS file '%s'", v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  if ( !idLexer::ExpectTokenType(this: &v44, type: 3, subtype: 0, token: &v41) )
  {
    idResource::SetResourceError(
      this,
      fmt: "AAS file has malformed version number '%s' for file '%s'",
      v41.data,
      v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  v3 = idStr::Find(str: v41.data, c: 46, start: 0, end: v41.len);
  v4 = v3;
  if ( v3 == -1 )
  {
    idResource::SetResourceError(
      this,
      fmt: "AAS file has malformed version number. Expected a '.' between major and minor versions '%s'",
      v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  v5 = idStr::Left(this: &v52, result: &v41, len: v3);
  this->major = atol(nptr: v5->data);
  idStr::FreeData(this: &v52);
  v6 = idStr::Right(this: &v53, result: &v41, len: v41.len - v4 - 1);
  this->minor = atol(nptr: v6->data);
  idStr::FreeData(this: &v53);
  major = this->major;
  if ( major != 3 )
  {
    idResource::SetResourceError(
      this,
      fmt: "AAS file has major version %d instead of %d for file '%s'",
      major,
      3,
      v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  minor = this->minor;
  if ( minor != 13 )
  {
    idResource::SetResourceError(
      this,
      fmt: "AAS file has minor version %d instead of %d for file '%s'",
      minor,
      13,
      v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  if ( !idLexer::ExpectTokenType(this: &v44, type: 3, subtype: 1, token: &v41) )
  {
    idResource::SetResourceError(this, fmt: "AAS file has no map file CRC '%s'", v39.data);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
    goto LABEL_103;
  }
  idToken::GetUnsignedIntValue(this: &v41);
  idLexer::ExpectTokenString(this: &v44, string: "firstFakeVertex");
  this->firstFakeVertex = idLexer::ParseInt(this: &v44);
  idLexer::ExpectTokenString(this: &v44, string: "firstFakeEdge");
  this->firstFakeEdge = idLexer::ParseInt(this: &v44);
  idLexer::ExpectTokenString(this: &v44, string: "firstFakeEdgeIndex");
  this->firstFakeEdgeIndex = idLexer::ParseInt(this: &v44);
  idLexer::ExpectTokenString(this: &v44, string: "firstFakeArea");
  this->firstFakeArea = idLexer::ParseInt(this: &v44);
  idAAS2File::Clear(this);
  this->timestamp = v2;
  this->crc = 0;
  if ( idLexer::ReadToken(this: &v44, token: &v41) )
  {
    p_gravityDir = "hintNodes";
    v45 = "traversalPoints";
    v50 = "touchingCoverIndex";
    v51 = "areaCoverIndex";
    v47 = "cover";
    v46 = "traversalEntityNames";
    v48 = "interactionEntityNames";
    v49 = "dependencyNames";
    do
    {
      if ( idStr::Cmp(s1: v41.data, s2: "settings") != 0 )
      {
        if ( idStr::Cmp(s1: v41.data, s2: "planes") != 0 )
        {
          if ( idStr::Cmp(s1: v41.data, s2: "vertices") != 0 )
          {
            if ( idStr::Cmp(s1: v41.data, s2: "edges") != 0 )
            {
              if ( idStr::Cmp(s1: v41.data, s2: "edgeIndex") != 0 )
              {
                if ( idStr::Cmp(s1: v41.data, s2: "reachabilities") != 0 )
                {
                  if ( idStr::Cmp(s1: v41.data, s2: "areas") != 0 )
                  {
                    if ( idStr::Cmp(s1: v41.data, s2: "nodes") != 0 )
                    {
                      if ( idStr::Cmp(s1: v41.data, s2: "portals") != 0 )
                      {
                        if ( idStr::Cmp(s1: v41.data, s2: "portalIndex") != 0 )
                        {
                          if ( idStr::Cmp(s1: v41.data, s2: "clusters") != 0 )
                          {
                            if ( idStr::Cmp(s1: v41.data, s2: "obstaclePVS") != 0 )
                            {
                              if ( idStr::Cmp(s1: v41.data, s2: "reachNames") != 0 )
                              {
                                if ( idStr::Cmp(s1: v41.data, s2: "traversalAnimNames") != 0
                                  && idStr::Cmp(s1: v41.data, s2: "animNames") != 0 )
                                {
                                  if ( idStr::Cmp(s1: v41.data, s2: v49) != 0 )
                                  {
                                    if ( idStr::Cmp(s1: v41.data, s2: v48) != 0 )
                                    {
                                      if ( idStr::Cmp(s1: v41.data, s2: v46) != 0 )
                                      {
                                        if ( idStr::Cmp(s1: v41.data, s2: v47) != 0 )
                                        {
                                          if ( idStr::Cmp(s1: v41.data, s2: v51) != 0 )
                                          {
                                            if ( idStr::Cmp(s1: v41.data, s2: v50) != 0 )
                                            {
                                              if ( idStr::Cmp(s1: v41.data, s2: v45) != 0 )
                                              {
                                                if ( idStr::Cmp(s1: v41.data, s2: p_gravityDir) != 0 )
                                                {
                                                  if ( idStr::Cmp(s1: v41.data, s2: "trees") != 0 )
                                                  {
                                                    idLexer::Error(
                                                      this: &v44,
                                                      str: "idAAS2File::Load: bad token \"%s\"",
                                                      v41.data);
                                                    idAAS2File::MakeDefault(this);
                                                    idStr::FreeData(this: &v40);
                                                    idStr::FreeData(this: &v41);
                                                    idLexer::~idLexer(this: &v44);
                                                    goto LABEL_103;
                                                  }
                                                  if ( !idAAS2File::ParseTrees(this, src: &v44) )
                                                  {
_M243951:
                                                    idAAS2File::MakeDefault(this);
                                                    idStr::FreeData(this: &v40);
                                                    idStr::FreeData(this: &v41);
                                                    idLexer::~idLexer(this: &v44);
                                                    goto LABEL_103;
                                                  }
                                                }
                                                else if ( !idAAS2File::ParseHintNodes(this, src: &v44) )
                                                {
                                                  goto _M243951;
                                                }
                                              }
                                              else if ( !idAAS2File::ParseTraversalPoints(this, src: &v44) )
                                              {
                                                goto _M243951;
                                              }
                                            }
                                            else if ( !idAAS2File::ParseIndex(
                                                         this,
                                                         src: &v44,
                                                         indexes: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->touchingCoverIndex) )
                                            {
                                              goto _M243951;
                                            }
                                          }
                                          else if ( !idAAS2File::ParseIndex(
                                                       this,
                                                       src: &v44,
                                                       indexes: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->areaCoverIndex) )
                                          {
                                            goto _M243951;
                                          }
                                        }
                                        else if ( !idAAS2File::ParseCover(this, src: &v44) )
                                        {
                                          goto _M243951;
                                        }
                                      }
                                      else if ( !idAAS2File::ParseInteractionEntityNames(
                                                   this,
                                                   src: &v44,
                                                   names: (idList<aas2TraversalEntityName_t,5> *)&this->traversalEntityNames) )
                                      {
                                        goto _M243951;
                                      }
                                    }
                                    else if ( !idAAS2File::ParseInteractionEntityNames(
                                                 this,
                                                 src: &v44,
                                                 names: (idList<aas2TraversalEntityName_t,5> *)&this->interactionEntityNames) )
                                    {
                                      goto _M243951;
                                    }
                                  }
                                  else if ( !idAAS2File::ParseInteractionEntityNames(
                                               this,
                                               src: &v44,
                                               names: (idList<aas2TraversalEntityName_t,5> *)&this->dependencyNames) )
                                  {
                                    goto _M243951;
                                  }
                                }
                                else if ( !idAAS2File::ParseInteractionEntityNames(
                                             this,
                                             src: &v44,
                                             names: (idList<aas2TraversalEntityName_t,5> *)&this->animNames) )
                                {
                                  goto _M243951;
                                }
                              }
                              else if ( !idAAS2File::ParseNames(
                                           this,
                                           src: &v44,
                                           names: (idList<aas2Name_t,5> *)&this->reachabilityNames) )
                              {
                                goto _M243951;
                              }
                            }
                            else if ( !idAAS2File::ParseObstaclePVS(this, src: &v44) )
                            {
                              goto _M243951;
                            }
                          }
                          else if ( !idAAS2File::ParseClusters(this, src: &v44) )
                          {
                            goto _M243951;
                          }
                        }
                        else if ( !idAAS2File::ParseIndex(
                                     this,
                                     src: &v44,
                                     indexes: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->portalIndex) )
                        {
                          goto _M243951;
                        }
                      }
                      else if ( !idAAS2File::ParsePortals(this, src: &v44) )
                      {
                        goto _M243951;
                      }
                    }
                    else if ( !idAAS2File::ParseNodes(this, src: &v44) )
                    {
                      goto _M243951;
                    }
                  }
                  else if ( !idAAS2File::ParseAreas(this, src: &v44) )
                  {
                    goto _M243951;
                  }
                }
                else if ( !idAAS2File::ParseReachabilities(this, src: &v44) )
                {
                  goto _M243951;
                }
              }
              else if ( !idAAS2File::ParseIndex(
                           this,
                           src: &v44,
                           indexes: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->edgeIndex) )
              {
                goto _M243951;
              }
            }
            else if ( !idAAS2File::ParseEdges(this, src: &v44) )
            {
              goto _M243951;
            }
          }
          else if ( !idAAS2File::ParseVertices(this, src: &v44) )
          {
            goto _M243951;
          }
        }
        else if ( !idAAS2File::ParsePlanes(this, src: &v44) )
        {
          goto _M243951;
        }
      }
      else if ( (unsigned __int8)idAAS2Settings::ReadFromFile(this: &this->settings, src: &v44) == 0 )
      {
        goto _M243951;
      }
    }
    while ( idLexer::ReadToken(this: &v44, token: &v41) );
  }
  if ( this->trees.num == 0 )
  {
    idList<idAAS2File::bspTree_t,37>::SetNum(this: &this->trees, newNum: 1);
    list = this->trees.list;
    v10 = -this->settings.gravityDir.x;
    v11 = -this->settings.gravityDir.z;
    list->floorNormal.y = -this->settings.gravityDir.y;
    list->floorNormal.z = v11;
    p_gravityDir = (const char *)&this->settings.gravityDir;
    list->floorNormal.x = v10;
    this->trees.list->headNode = 1;
    this->trees.list->firstArea = 1;
    this->trees.list->lastArea = this->areas.num;
  }
  v12 = 0;
  if ( this->reachabilities.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &this->reachabilities.list[v13++];
      v15 = 8 * (v14->fromAreaNum + __ROL4__(v14->fromAreaNum, 2));
      v14->next.value = *(__int16 *)((char *)&this->areas.list->reach.value + v15);
      *(__int16 *)((char *)&this->areas.list->reach.value + v15) = v12;
      v16 = 8 * (v14->toAreaNum + __ROL4__(v14->toAreaNum, 2));
      v14->rev_next.value = *(__int16 *)((char *)&this->areas.list->rev_reach.value + v16);
      *(__int16 *)((char *)&this->areas.list->rev_reach.value + v16) = v12++;
    }
    while ( v12 < this->reachabilities.num );
  }
  idAAS2File::CalculateAreaBounds(this);
  idAAS2File::WriteBinary(
    this,
    fileName: v39.data,
    binaryFileName: v54,
    mapFileCRC: 0,
    sourceTimestamp: v43,
    a6: v19,
    a7: v18,
    a8: v17,
    a9: v27,
    a10: v28,
    a11: v29,
    a12: v30,
    a13: v31,
    a14: v32,
    a15: v33,
    a16: v34,
    a17: v35,
    a18: v36,
    a19: v37,
    a20: v38);
  idAAS2File::FlagNoPushAreas(this, a2: v24, a3: v23, a4: v22, a5: v21, a6: v20);
  v25 = nullptr;
  if ( this->trees.num <= 0 )
  {
LABEL_4:
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
  }
  else
  {
    while ( 1 )
    {
      p_gravityDir = v25;
      v26 = idAAS2File::MaxTreeDepth(this, tree: (idIndex<int,enum invalidAASTree_t> *)v25);
      if ( v26 > 128 )
        break;
      if ( (int)++v25 >= this->trees.num )
        goto LABEL_4;
    }
    idLexer::Error(this: &v44, str: "idAAS2File::Load: tree depth = %d for tree %s", v26, v54);
    idAAS2File::MakeDefault(this);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v41);
    idLexer::~idLexer(this: &v44);
  }
LABEL_103:
  idStr::FreeData(this: &v39);
}


// ========================================================================
// __unwind$242806
// EA  : 0x825B9498
// RVA : 0x005B9498
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_242806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 80));
}


// ========================================================================
// __unwind$242807
// EA  : 0x825B94C0
// RVA : 0x005B94C0
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_242807()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 880 + 224));
}


// ========================================================================
// __unwind$242808
// EA  : 0x825B94E8
// RVA : 0x005B94E8
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_242808()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 144));
}


// ========================================================================
// __unwind$242809
// EA  : 0x825B9510
// RVA : 0x005B9510
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void _unwind_242809()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 112));
}


// ========================================================================
// `dynamic initializer for 'idAAS2File::resourceList''
// EA  : 0x83335090
// RVA : 0x01335090
// PDB : w:\tech5\engine\aas2file\aas2file.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idAAS2File::resourceList__()
{
  idResourceList::idResourceList(this: &idAAS2File::resourceList, typeName: "aas");
  idAAS2File::resourceList.__vftable = (idTypedResourceList<idAAS2File>_vtbl *)&idTypedResourceList<idAAS2File>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idAAS2File::resourceList__);
}

