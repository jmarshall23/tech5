
// ========================================================================
// ??1idAAS2@@UAA@XZ
// EA  : 0x826A9F08
// RVA : 0x006A9F08
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2::~idAAS2(idAAS2 *this)
{
  this->__vftable = (idAAS2_vtbl *)&idAAS2::`vftable';
}


// ========================================================================
// ?Shutdown@idAAS2Local@@UAAXXZ
// EA  : 0x826A9F18
// RVA : 0x006A9F18
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::Shutdown(idAAS2Local *this)
{
  if ( this->file != nullptr )
  {
    idAAS2Local::ShutdownRouting(this);
    idAAS2Local::ShutdownObstaclePVS(this);
    this->file = nullptr;
    this->areaCacheIndex = nullptr;
    this->portalCacheIndex = nullptr;
    this->areaUpdate = nullptr;
    this->portalUpdate = nullptr;
    this->goalAreaTravelTimes = nullptr;
    this->areaTravelTimes = nullptr;
    this->cacheListStart = nullptr;
    this->cacheListEnd = nullptr;
    this->obstaclePVS = nullptr;
    this->areaClipModels = nullptr;
  }
}


// ========================================================================
// ?PointAreaNum@idAAS2Local@@UBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@@Z
// EA  : 0x826A9F88
// RVA : 0x006A9F88
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::PointAreaNum(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        const idVec3 *origin)
{
  return idAAS2File::PointAreaNum(this: this->file, (int)tree, origin);
}


// ========================================================================
// ?PointReachableAreaNum@idAAS2Local@@UBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@ABVidBounds@@HH@Z
// EA  : 0x826A9F90
// RVA : 0x006A9F90
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::PointReachableAreaNum(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        const idVec3 *origin,
        const idBounds *searchBounds,
        int areaFlags,
        int excludeTravelFlags)
{
  return idAAS2File::PointReachableAreaNum(this: this->file, tree, origin, areaFlags, excludeTravelFlags);
}


// ========================================================================
// ?BoundsReachableAreaNum@idAAS2Local@@UBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidBounds@@HH@Z
// EA  : 0x826A9FA0
// RVA : 0x006A9FA0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::BoundsReachableAreaNum(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        idBounds *bounds,
        unsigned __int16 areaFlags,
        int excludeTravelFlags)
{
  return idAAS2File::BoundsReachableAreaNum(this: this->file, (int)tree, bounds, areaFlags, excludeTravelFlags);
}


// ========================================================================
// ?AreaCenter@idAAS2Local@@UBA?AVidVec3@@H@Z
// EA  : 0x826A9FA8
// RVA : 0x006A9FA8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::AreaCenter(idAAS2Local *this, idVec3 *result, int areaNum)
{
  idAAS2File::AreaCenter((idAAS2File *)this, result: (idVec3 *)LODWORD(result->y), areaNum);
  return this;
}


// ========================================================================
// ?Trace@idAAS2Local@@UBA_NV?$idIndex@HW4invalidAASTree_t@@@@AAUaas2Trace_t@@ABVidVec3@@2@Z
// EA  : 0x826A9FE0
// RVA : 0x006A9FE0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::Trace(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        aas2Trace_t *trace,
        const idVec3 *start,
        const idVec3 *end)
{
  return idAAS2File::Trace(this: this->file, (int)tree, trace, start, end);
}


// ========================================================================
// ?TraceHeight@idAAS2Local@@UBA_NV?$idIndex@HW4invalidAASTree_t@@@@AAUaas2TraceHeight_t@@ABVidVec3@@2@Z
// EA  : 0x826A9FE8
// RVA : 0x006A9FE8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::TraceHeight(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        aas2TraceHeight_t *trace,
        const idVec3 *start,
        __int64 end)
{
  return idAAS2File::TraceHeight(this: this->file, (int)tree, trace, end);
}


// ========================================================================
// ?TraceFloor@idAAS2Local@@UBA_NAAUaas2TraceFloor_t@@ABVidVec3@@H1H_N22@Z
// EA  : 0x826A9FF0
// RVA : 0x006A9FF0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::TraceFloor(
        idAAS2Local *this,
        aas2TraceFloor_t *trace,
        const idVec3 *start,
        int startAreaNum,
        const idVec3 *end,
        int travelFlags,
        bool allowFloorNormalChange,
        char ignoreGravityDirectionDistance,
        bool ignoreSameArea,
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
        char a28)
{
  bool v29; // [sp+Bh] [-65h]
  bool v30; // [sp+Fh] [-61h]
  int v31; // [sp+10h] [-60h]
  int v32; // [sp+14h] [-5Ch]
  int v33; // [sp+18h] [-58h]
  int v34; // [sp+1Ch] [-54h]
  int v35; // [sp+20h] [-50h]
  int v36; // [sp+24h] [-4Ch]
  int v37; // [sp+28h] [-48h]
  int v38; // [sp+2Ch] [-44h]
  int v39; // [sp+30h] [-40h]
  int v40; // [sp+34h] [-3Ch]
  int v41; // [sp+38h] [-38h]
  int v42; // [sp+3Ch] [-34h]
  int v43; // [sp+40h] [-30h]
  int v44; // [sp+44h] [-2Ch]
  int v45; // [sp+48h] [-28h]
  int v46; // [sp+4Ch] [-24h]
  int v47; // [sp+50h] [-20h]
  int v48; // [sp+58h] [-18h]

  return idAAS2File::TraceFloor(
           this: this->file,
           trace,
           start,
           startAreaNum,
           end,
           endAreaNum: 0,
           travelFlags,
           allowFloorNormalChange,
           ignoreGravityDirectionDistance: v29,
           ignoreSameArea: v30,
           a11: v31,
           a12: v32,
           a13: v33,
           a14: v34,
           a15: v35,
           a16: v36,
           a17: v37,
           a18: v38,
           a19: v39,
           a20: v40,
           a21: v41,
           a22: v42,
           a23: v43,
           a24: v44,
           a25: v45,
           a26: v46,
           a27: v47,
           a28: ignoreGravityDirectionDistance,
           a29: v48,
           a30: a28);
}


// ========================================================================
// ?GetAASAnim@idAAS2Local@@UBA_NV?$idIndex@FW4invalidAASAnimIndex_t@@@@AAPBUaas2AnimName_t@@@Z
// EA  : 0x826AA038
// RVA : 0x006AA038
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAASAnim(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASAnimIndex_t> *index,
        const aas2AnimName_t **name_)
{
  return idAAS2File::GetAASAnim(this: this->file, index, name: name_);
}


// ========================================================================
// ?GetAASAnimIndexByName@idAAS2Local@@UBA?AV?$idIndex@FW4invalidAASAnimIndex_t@@@@PBD@Z
// EA  : 0x826AA040
// RVA : 0x006AA040
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetAASAnimIndexByName(
        idAAS2Local *this,
        idIndex<short,enum invalidAASAnimIndex_t> *result,
        const char *name_)
{
  idAAS2File::GetAASAnimIndexByName(
    (idAAS2File *)this,
    result: *(idIndex<short,enum invalidAASAnimIndex_t> **)&result[2].value,
    name: name_);
  return this;
}


// ========================================================================
// ?GetAASDependency@idAAS2Local@@UBA_NV?$idIndex@FW4invalidAASDependencyIndex_t@@@@AAPBUaas2DependencyName_t@@@Z
// EA  : 0x826AA078
// RVA : 0x006AA078
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAASDependency(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASDependencyIndex_t> *index,
        const aas2DependencyName_t **name_)
{
  return idAAS2File::GetAASDependency(this: this->file, index, name: name_);
}


// ========================================================================
// ?GetAASDependencyIndexByName@idAAS2Local@@UBA?AV?$idIndex@FW4invalidAASDependencyIndex_t@@@@PBD@Z
// EA  : 0x826AA080
// RVA : 0x006AA080
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetAASDependencyIndexByName(
        idAAS2Local *this,
        idIndex<short,enum invalidAASDependencyIndex_t> *result,
        const char *name_)
{
  idAAS2File::GetAASDependencyIndexByName(
    (idAAS2File *)this,
    result: *(idIndex<short,enum invalidAASDependencyIndex_t> **)&result[2].value,
    name: name_);
  return this;
}


// ========================================================================
// ?GetAASInteractionEntity@idAAS2Local@@UBA_NV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@AAPBUaas2InteractionEntityName_t@@@Z
// EA  : 0x826AA0B8
// RVA : 0x006AA0B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAASInteractionEntity(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASInteractionEntIndex_t> *index,
        const aas2InteractionEntityName_t **name_)
{
  return idAAS2File::GetAASInteractionEntity(this: this->file, index, name: name_);
}


// ========================================================================
// ?GetAASInteractionEntityIndexByName@idAAS2Local@@UBA?AV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@PBD@Z
// EA  : 0x826AA0C0
// RVA : 0x006AA0C0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetAASInteractionEntityIndexByName(
        idAAS2Local *this,
        idIndex<short,enum invalidAASInteractionEntIndex_t> *result,
        const char *name_)
{
  idAAS2File::GetAASInteractionEntityIndexByName(
    (idAAS2File *)this,
    result: *(idIndex<short,enum invalidAASInteractionEntIndex_t> **)&result[2].value,
    name: name_);
  return this;
}


// ========================================================================
// ?GetAASTraversalNameIndex@idAAS2Local@@UBA_NV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@AAPBUaas2TraversalEntityName_t@@@Z
// EA  : 0x826AA0F8
// RVA : 0x006AA0F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAASTraversalNameIndex(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASTraversalNameIndex_t> *index,
        const aas2TraversalEntityName_t **name)
{
  return idAAS2File::GetAASTraversalNameIndex(this: this->file, index, name);
}


// ========================================================================
// ?GetAASTraversalNameIndexByName@idAAS2Local@@UBA?AV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@PBD@Z
// EA  : 0x826AA100
// RVA : 0x006AA100
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetAASTraversalNameIndexByName(
        idAAS2Local *this,
        idIndex<short,enum invalidAASTraversalNameIndex_t> *result,
        const char *name)
{
  idAAS2File::GetAASTraversalNameIndexByName(
    (idAAS2File *)this,
    result: *(idIndex<short,enum invalidAASTraversalNameIndex_t> **)&result[2].value,
    name);
  return this;
}


// ========================================================================
// ?GetAASTraversalIndexByNameIndex@idAAS2Local@@UBAHV?$idIndex@FW4invalidAASTraversalNameIndex_t@@@@@Z
// EA  : 0x826AA138
// RVA : 0x006AA138
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAASTraversalIndexByNameIndex(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASTraversalNameIndex_t> *index)
{
  return idAAS2File::GetAASTraversalIndexByNameIndex(this: this->file, index);
}


// ========================================================================
// ?SetTraversalFlag@idAAS2Local@@UAA_NHH@Z
// EA  : 0x826AA140
// RVA : 0x006AA140
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::SetTraversalFlag(idAAS2Local *this, int index, int flags)
{
  int v6; // [sp+50h] [-20h] BYREF
  int v7; // [sp+54h] [-1Ch] BYREF

  if ( (unsigned __int8)idAAS2File::SetTraversalFlag(this: this->file, index, flags) == 0 )
    return 0;
  if ( (unsigned __int8)idAAS2File::GetAASTraversalAreas(this: this->file, index, startArea: &v6, goalArea: &v7) != 0 )
  {
    idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v6);
    idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v7);
  }
  return 1;
}


// ========================================================================
// ?ClearTraversalFlag@idAAS2Local@@UAA_NHH@Z
// EA  : 0x826AA1D0
// RVA : 0x006AA1D0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::ClearTraversalFlag(idAAS2Local *this, int index, int flags)
{
  int v6; // [sp+50h] [-20h] BYREF
  int v7; // [sp+54h] [-1Ch] BYREF

  if ( (unsigned __int8)idAAS2File::ClearTraversalFlag(this: this->file, index, flags) == 0 )
    return 0;
  if ( (unsigned __int8)idAAS2File::GetAASTraversalAreas(this: this->file, index, startArea: &v6, goalArea: &v7) != 0 )
  {
    idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v6);
    idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v7);
  }
  return 1;
}


// ========================================================================
// ?ClipGridToAreas@idAAS2Local@@UBAXABVidVec3@@HHHHPAE@Z
// EA  : 0x826AA260
// RVA : 0x006AA260
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::ClipGridToAreas(
        idAAS2Local *this,
        const idVec3 *startOrigin,
        int startAreaNum,
        int travelFlags,
        unsigned int cellSize,
        int cellsWide,
        unsigned __int8 *reachable)
{
  idAAS2File::ClipGridToAreas(
    this: this->file,
    startOrigin,
    startAreaNum,
    travelFlags,
    cellSize,
    dimension: cellsWide,
    reachable);
}


// ========================================================================
// ?GetTreeForFloorNormal@idAAS2Local@@UBA?AV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@@Z
// EA  : 0x826AA268
// RVA : 0x006AA268
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetTreeForFloorNormal(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *result,
        const idVec3 *floorNormal)
{
  idAAS2File::GetTreeForFloorNormal(
    (idAAS2File *)this,
    result: (idIndex<int,enum invalidAASTree_t> *)result[1].value,
    floorNormal);
  return this;
}


// ========================================================================
// ?GetNumAreasInTree@idAAS2Local@@UBAHV?$idIndex@HW4invalidAASTree_t@@@@@Z
// EA  : 0x826AA2A0
// RVA : 0x006AA2A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumAreasInTree(idAAS2Local *this, idIndex<int,enum invalidAASTree_t> *treeNum)
{
  return idAAS2File::GetNumAreasInTree(this: this->file, treeNum);
}


// ========================================================================
// ?Init@idAAS2Local@@UAA_NPBDI@Z
// EA  : 0x826AA2A8
// RVA : 0x006AA2A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::Init(idAAS2Local *this, char *mapName, unsigned int mapFileCRC)
{
  idAAS2File *file; // r11
  idAAS2File *v7; // r11
  idAAS2File *v9; // r3

  file = this->file;
  if ( file != nullptr
    && idStr::Icmp(s1: mapName, s2: file->name.str) == 0
    && (v7 = this->file, mapFileCRC == v7->crc)
    && mapFileCRC != 0 )
  {
    idLib::Printf(fmt: "Keeping %s\n", v7->name.str);
    return 1;
  }
  else
  {
    this->Shutdown(this);
    v9 = (idAAS2File *)idResourceList::Load(
                         this: &idAAS2File::resourceList,
                         name: mapName,
                         makeDefault: true,
                         skipStaleCheck: false);
    this->file = v9;
    if ( v9->resourceError != nullptr )
    {
      idLib::Warning(fmt: "Couldn't load AAS file: '%s'", mapName);
      this->defaulted = true;
    }
    idAAS2File::ResetCover(this: this->file);
    idAAS2Local::SetupRouting(this);
    idAAS2Local::SetupObstaclePVS(this);
    return 1;
  }
}


// ========================================================================
// ?GetSettings@idAAS2Local@@UBAPBVidAAS2Settings@@XZ
// EA  : 0x826AA390
// RVA : 0x006AA390
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const idAAS2Settings *__fastcall idAAS2Local::GetSettings(idAAS2Local *this)
{
  return &this->file->settings;
}


// ========================================================================
// ?BoundsReachableAreaNum@idAAS2Local@@UBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@ABVidBounds@@HH@Z
// EA  : 0x826AA3A0
// RVA : 0x006AA3A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::BoundsReachableAreaNum(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        const idVec3 *origin,
        const idBounds *bounds,
        unsigned __int16 areaFlags,
        int excludeTravelFlags)
{
  idAAS2File *file; // r3
  double v7; // fp3
  double v8; // fp7
  double v9; // fp5
  double v10; // fp1
  double v11; // fp0
  idBounds v13; // [sp+50h] [-20h] BYREF

  file = this->file;
  v7 = (float)(bounds->b[0].x + origin->x);
  v8 = (float)(bounds->b[1].y + origin->y);
  v9 = (float)(bounds->b[1].z + origin->z);
  v10 = (float)(bounds->b[0].y + origin->y);
  v11 = (float)(bounds->b[0].z + origin->z);
  v13.b[1].x = bounds->b[1].x + origin->x;
  v13.b[1].y = v8;
  v13.b[1].z = v9;
  v13.b[0].x = v7;
  v13.b[0].y = v10;
  v13.b[0].z = v11;
  return idAAS2File::BoundsReachableAreaNum(this: file, (int)tree, bounds: &v13, areaFlags, excludeTravelFlags);
}


// ========================================================================
// ??0idAAS2Local@@QAA@XZ
// EA  : 0x826AA438
// RVA : 0x006AA438
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::idAAS2Local(idAAS2Local *this)
{
  this->__vftable = (idAAS2Local_vtbl *)&idAAS2Local::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->clipModelLinkAllocator.blocks = nullptr;
  this->clipModelLinkAllocator.free = nullptr;
  this->clipModelLinkAllocator.total = 0;
  this->clipModelLinkAllocator.active = 0;
  this->clipModelLinkAllocator.allowAllocs = true;
  this->clipModelLinkAllocator.clearAllocs = false;
  idObstacleAvoidance::idObstacleAvoidance(this: &this->obstacleAvoidance);
  this->file = nullptr;
  this->defaulted = false;
  this->areaCacheIndex = nullptr;
  this->areaCacheIndexSize = 0;
  this->portalCacheIndex = nullptr;
  this->groundSpeedMultiplier = 1.0;
  this->portalCacheIndexSize = 0;
  this->waterSpeedMultiplier = 1.0;
  this->areaUpdate = nullptr;
  this->portalUpdate = nullptr;
  this->goalAreaTravelTimes = nullptr;
  this->areaTravelTimes = nullptr;
  this->numAreaTravelTimes = 0;
  this->cacheListStart = nullptr;
  this->cacheListEnd = nullptr;
  this->totalCacheMemory = 0;
  this->obstaclePVS = nullptr;
  this->obstaclePVSAreaNum = 0;
  this->numObstaclePVSBytes = 0;
  this->areaClipModels = nullptr;
  return this;
}


// ========================================================================
// __unwind$247261
// EA  : 0x826AA50C
// RVA : 0x006AA50C
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247261()
{
  int v0; // r12

  idAAS2::~idAAS2(this: *(idAAS2 **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$247262
// EA  : 0x826AA534
// RVA : 0x006AA534
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247262()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$247263
// EA  : 0x826AA560
// RVA : 0x006AA560
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247263()
{
  int v0; // r12

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(this: (idBlockAlloc<idAASClipLink,128,37> *)(*(_DWORD *)(v0 - 128 + 148) + 116));
}


// ========================================================================
// ??1idAAS2Local@@UAA@XZ
// EA  : 0x826AA5A0
// RVA : 0x006AA5A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::~idAAS2Local(idAAS2Local *this)
{
  this->__vftable = (idAAS2Local_vtbl *)&idAAS2Local::`vftable';
  idAAS2Local::Shutdown(this);
  idObstacleAvoidance::~idObstacleAvoidance(this: &this->obstacleAvoidance);
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: &this->clipModelLinkAllocator);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idAAS2Local_vtbl *)&idAAS2::`vftable';
}


// ========================================================================
// __unwind$247324_0
// EA  : 0x826AA60C
// RVA : 0x006AA60C
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247324_0()
{
  int v0; // r12

  idAAS2::~idAAS2(this: *(idAAS2 **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247325_0
// EA  : 0x826AA634
// RVA : 0x006AA634
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247325_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$247326_0
// EA  : 0x826AA660
// RVA : 0x006AA660
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247326_0()
{
  int v0; // r12

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(this: (idBlockAlloc<idAASClipLink,128,37> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// __unwind$247327_0
// EA  : 0x826AA68C
// RVA : 0x006AA68C
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void _unwind_247327_0()
{
  int v0; // r12

  idObstacleAvoidance::~idObstacleAvoidance(this: (idObstacleAvoidance *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// ?Stats@idAAS2Local@@UBAXXZ
// EA  : 0x826AA6B8
// RVA : 0x006AA6B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::Stats(idAAS2Local *this)
{
  unsigned int v2; // r3

  idLib::Printf(fmt: "[%s]\n", this->file->name.str);
  idLib::Printf(fmt: "%6d areas\n", this->file->areas.num - 1);
  v2 = idAAS2File::MemorySize(this: this->file);
  idLib::Printf(fmt: "%6d kB file size\n", v2 >> 10);
  idAAS2Local::RoutingStats(this);
}


// ========================================================================
// ?PushPointIntoAreaNum@idAAS2Local@@UBAXHAAVidVec3@@@Z
// EA  : 0x826AA730
// RVA : 0x006AA730
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::PushPointIntoAreaNum(idAAS2Local *this, int areaNum, idVec3 *origin)
{
  idAAS2File *file; // r3

  file = this->file;
  if ( (file->areas.list[areaNum].flags & 0x10) == 0 )
    idAAS2File::PushPointIntoAreaNum(this: file, areaNum, point: origin);
}


// ========================================================================
// ?GetEdgeVertexNumbers@idAAS2Local@@UBAXHQAH@Z
// EA  : 0x826AA760
// RVA : 0x006AA760
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::GetEdgeVertexNumbers(idAAS2Local *this, unsigned int edgeNum, int *verts)
{
  aas2Edge_t *v3; // r11

  v3 = &this->file->edges.list[abs32(edgeNum)];
  *verts = *(int *)((char *)v3->vertexNum + ((edgeNum >> 29) & 4));
  verts[1] = *(int *)((char *)v3->vertexNum + ((~edgeNum >> 29) & 4));
}


// ========================================================================
// ?GetEdge@idAAS2Local@@UBAXHAAVidVec3@@0@Z
// EA  : 0x826AA7A8
// RVA : 0x006AA7A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall idAAS2Local::GetEdge(idAAS2Local *this, unsigned int edgeNum, idVec3 *start, idVec3 *end)
{
  idAAS2File *file; // r9
  aas2Edge_t *list; // r8
  idVec3 *v6; // r9
  aas2Edge_t *v7; // r10

  file = this->file;
  list = file->edges.list;
  v6 = file->vertices.list;
  v7 = &list[abs32(edgeNum)];
  *start = v6[*(int *)((char *)v7->vertexNum + ((edgeNum >> 29) & 4))];
  *end = v6[*(int *)((char *)v7->vertexNum + ((~edgeNum >> 29) & 4))];
}


// ========================================================================
// ?GetAreaFlags@idAAS2Local@@UBAHH@Z
// EA  : 0x826AA838
// RVA : 0x006AA838
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAreaFlags(idAAS2Local *this, int areaNum)
{
  return this->file->areas.list[areaNum].flags;
}


// ========================================================================
// ?GetEdgeFlags@idAAS2Local@@UBAHH@Z
// EA  : 0x826AA858
// RVA : 0x006AA858
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetEdgeFlags(idAAS2Local *this, int edgeNum)
{
  return this->file->edges.list[abs32(edgeNum)].flags;
}


// ========================================================================
// ?GetPlane@idAAS2Local@@UBAABVidPlane@@H@Z
// EA  : 0x826AA888
// RVA : 0x006AA888
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const idPlane *__fastcall idAAS2Local::GetPlane(idAAS2Local *this, const int index)
{
  return &this->file->planes.list[index];
}


// ========================================================================
// ?GetNumAreas@idAAS2Local@@UBAHXZ
// EA  : 0x826AA8A0
// RVA : 0x006AA8A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumAreas(idAAS2Local *this)
{
  return this->file->areas.num;
}


// ========================================================================
// ?GetArea@idAAS2Local@@UBAABUaas2Area_t@@H@Z
// EA  : 0x826AA8B0
// RVA : 0x006AA8B0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const aas2Area_t *__fastcall idAAS2Local::GetArea(idAAS2Local *this, const int areaNum)
{
  return &this->file->areas.list[areaNum];
}


// ========================================================================
// ?GetReachability@idAAS2Local@@UBAABUaas2Reachability_t@@V?$idIndex@FW4invalidReachability_t@@@@@Z
// EA  : 0x826AA8D0
// RVA : 0x006AA8D0
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const aas2Reachability_t *__fastcall idAAS2Local::GetReachability(
        idAAS2Local *this,
        const idIndex<short,enum invalidReachability_t> *reachNum)
{
  return &this->file->reachabilities.list[(__int16)reachNum];
}


// ========================================================================
// ?GetTraversal@idAAS2Local@@UBAABUaas2Traversal_t@@H@Z
// EA  : 0x826AA8E8
// RVA : 0x006AA8E8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const aas2Traversal_t *__fastcall idAAS2Local::GetTraversal(idAAS2Local *this, const int traversalNum)
{
  return &this->file->traversalPoints.list[traversalNum];
}


// ========================================================================
// ?GetNumTrees@idAAS2Local@@UBAHXZ
// EA  : 0x826AA900
// RVA : 0x006AA900
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumTrees(idAAS2Local *this)
{
  return this->file->trees.num;
}


// ========================================================================
// ?GetTree@idAAS2Local@@UBA?AV?$idIndex@HW4invalidAASTree_t@@@@H@Z
// EA  : 0x826AA910
// RVA : 0x006AA910
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetTree(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *result,
        idAAS2Local_vtbl *index)
{
  this->__vftable = index;
  return this;
}


// ========================================================================
// ?GetFloorNormalForTree@idAAS2Local@@UBAABVidVec3@@V?$idIndex@HW4invalidAASTree_t@@@@@Z
// EA  : 0x826AA918
// RVA : 0x006AA918
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2File::bspTree_t *__fastcall idAAS2Local::GetFloorNormalForTree(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *treeNum)
{
  return &this->file->trees.list[(_DWORD)treeNum];
}


// ========================================================================
// ?Alloc@idAAS2@@SAPAV1@XZ
// EA  : 0x826AA940
// RVA : 0x006AA940
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2::Alloc()
{
  idAAS2Local *v0; // r3

  v0 = (idAAS2Local *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0xACu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idAAS2Local::idAAS2Local(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$247602
// EA  : 0x826AA9A8
// RVA : 0x006AA9A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

void __fastcall _unwind_247602(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?GetFloorNormalForArea@idAAS2Local@@UBAABVidVec3@@H@Z
// EA  : 0x826AAA30
// RVA : 0x006AAA30
// PDB : w:\tech5\engine\gamelib\aas2\aas2.cpp
// ========================================================================

const idVec3 *__fastcall idAAS2Local::GetFloorNormalForArea(idAAS2Local *this, int areaNum)
{
  idIndex<int,enum invalidAASTree_t> *file; // r31
  char v4; // [sp+50h] [-20h] BYREF

  file = (idIndex<int,enum invalidAASTree_t> *)this->file;
  return (const idVec3 *)(file[88].value
                        + 24
                        * (int)idAAS2File::GetTreeForArea(this: (idAAS2File *)&v4, result: file, areaNum)->__vftable);
}

