
// ========================================================================
// ??0idDeclNavigation@@QAA@XZ
// EA  : 0x82BC90A8
// RVA : 0x00BC90A8
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

idDeclNavigation *__fastcall idDeclNavigation::idDeclNavigation(idDeclNavigation *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->navLayer = NAVLAYER_MONSTER32;
  this->__vftable = (idDeclNavigation_vtbl *)&idDeclNavigation::`vftable';
  this->navGenType = NAVGEN_2D_SURFACES;
  this->navCategory = NAVCAT_MONSTER;
  idAtomicString::Set(this: &this->fileExtensionNav, str_: "nav_monster32");
  idAtomicString::Set(this: &this->groupName, str_: "aas");
  idAtomicString::Set(this: &this->altGroupName, str_: "aas_monster32");
  this->includeSurfaceFlags = NavCustomNone;
  this->useEnhancedTerrainTracking = false;
  this->tessellateForPathAccuracy = false;
  this->islandsLeaveSmallTouchingPortals = false;
  this->islandsMax = 4096;
  this->addBrushesAsExclusions = true;
  this->optimizeForAxisAligned = false;
  this->voxelSize = 8.0;
  this->buildImpNodeSurfaces = false;
  this->agentRadius = 16.0;
  this->useCollisionModels = false;
  this->agentHeight = 96.0;
  this->useEntityIslandMetadata = false;
  this->agentStepHeight = 18.0;
  this->bakeFlightVolumes = false;
  this->agentWalkableSlope = 45.0;
  this->agentLedgeRadius = -1.0;
  this->verticalOffsetDist = 2.0;
  this->vertexSnap = 1.0;
  this->customMergeDistance = 150.0;
  this->additionalInwardsSmoothingDist = 0.0;
  this->islandsMinSurfaceArea = 0.0;
  this->volumeDistanceTolerance = 0.2;
  this->volumeAngleTolerance = 5.0;
  this->cover.coverLow.coverHeight = 0.0;
  this->cover.coverLow.coverFireOverHeight = 0.0;
  this->cover.coverLow.coverStepOutDist = 0.0;
  this->cover.coverLow.coverStepOutHeight = 0.0;
  this->cover.coverMid.coverHeight = 0.0;
  this->cover.coverMid.coverFireOverHeight = 0.0;
  this->cover.coverMid.coverStepOutDist = 0.0;
  this->cover.coverMid.coverStepOutHeight = 0.0;
  this->cover.coverHigh.coverHeight = 0.0;
  this->cover.coverHigh.coverFireOverHeight = 0.0;
  this->cover.coverHigh.coverStepOutDist = 0.0;
  this->cover.coverHigh.coverStepOutHeight = 0.0;
  return this;
}


// ========================================================================
// __unwind$488181
// EA  : 0x82BC922C
// RVA : 0x00BC922C
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

void _unwind_488181()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// ?FindDeclByLayer@idDeclNavigation@@SAPBV1@W4navLayer_t@@@Z
// EA  : 0x82BC9268
// RVA : 0x00BC9268
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

const idDeclNavigation *__fastcall idDeclNavigation::FindDeclByLayer(navLayer_t layer)
{
  int v2; // r29
  int num; // r10
  int v4; // r30
  idDeclSource *v5; // r11
  const idDeclNavigation *result; // r3

  v2 = 0;
  num = idDeclNavigation::resourceList.declSources.num;
  if ( idDeclNavigation::resourceList.declSources.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = idDeclNavigation::resourceList.declSources.list[v4];
      if ( v5 != nullptr && v5->name.str != nullptr )
      {
        result = (const idDeclNavigation *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclNavigation::resourceList,
                                             name: v5->name.str,
                                             makeDefault: true);
        if ( result != nullptr && result->navLayer == layer )
          return result;
        num = idDeclNavigation::resourceList.declSources.num;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < num );
  }
  return nullptr;
}


// ========================================================================
// ?GetResourceNames@idDeclNavigation@@QBAXPBDAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82BC92F8
// RVA : 0x00BC92F8
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

void __fastcall idDeclNavigation::GetResourceNames(
        idDeclNavigation *this,
        const char *mapName,
        __int64 fileNames,
        __int64 a4,
        __int64 a5)
{
  idList<idStr,5> *v5; // r30
  va *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r6
  __int64 v10; // r8
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r3
  int v16; // [sp+8h] [-20A8h]
  int v17; // [sp+8h] [-20A8h]
  int v18; // [sp+8h] [-20A8h]
  int v19; // [sp+Ch] [-20A4h]
  int v20; // [sp+Ch] [-20A4h]
  int v21; // [sp+Ch] [-20A4h]
  int v22; // [sp+10h] [-20A0h]
  int v23; // [sp+10h] [-20A0h]
  int v24; // [sp+10h] [-20A0h]
  int v25; // [sp+14h] [-209Ch]
  int v26; // [sp+14h] [-209Ch]
  int v27; // [sp+14h] [-209Ch]
  int v28; // [sp+18h] [-2098h]
  int v29; // [sp+18h] [-2098h]
  int v30; // [sp+18h] [-2098h]
  int v31; // [sp+1Ch] [-2094h]
  int v32; // [sp+1Ch] [-2094h]
  int v33; // [sp+1Ch] [-2094h]
  idStr v34; // [sp+50h] [-2060h] BYREF
  idStr v35; // [sp+70h] [-2040h] BYREF
  va v36; // [sp+90h] [-2020h] BYREF
  va v37; // [sp+1090h] [-1020h] BYREF

  v5 = (idList<idStr,5> *)HIDWORD(fileNames);
  HIDWORD(fileNames) = mapName;
  v7 = va::va(
         this: &v36,
         fmt: "maps/%s/",
         a3: fileNames,
         a4,
         a5,
         a6: v16,
         a7: v19,
         a8: v22,
         a9: v25,
         a10: v28,
         a11: v31);
  idStr::idStr(this: &v34, text: v7);
  idStr::AppendPath(this: &v34, text: this->fileExtensionNav.str);
  LODWORD(v8) = &unk_822C0000;
  HIDWORD(v9) = this->fileExtensionNav.str;
  v11 = va::va(
          this: &v37,
          fmt: "%s_base",
          a3: v9,
          a4: v10,
          a5: v8,
          a6: v17,
          a7: v20,
          a8: v23,
          a9: v26,
          a10: v29,
          a11: v32);
  idStr::AppendPath(this: &v34, text: v11->buffer);
  idList<idStr,5>::Append(this: v5, obj: &v34);
  if ( this->buildImpNodeSurfaces )
  {
    HIDWORD(v14) = v34.data;
    HIDWORD(v12) = this->buildImpNodeSurfaces;
    v15 = va::va(
            this: &v37,
            fmt: "%s_impnodes",
            a3: v14,
            a4: v13,
            a5: v12,
            a6: v18,
            a7: v21,
            a8: v24,
            a9: v27,
            a10: v30,
            a11: v33);
    idStr::idStr(this: &v35, text: v15);
    idList<idStr,5>::Append(this: v5, obj: &v35);
    idStr::FreeData(this: &v35);
  }
  idStr::FreeData(this: &v34);
}


// ========================================================================
// __unwind$488362
// EA  : 0x82BC93C0
// RVA : 0x00BC93C0
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

void _unwind_488362()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8368 + 80));
}


// ========================================================================
// __unwind$488363
// EA  : 0x82BC93E8
// RVA : 0x00BC93E8
// PDB : w:\tech5\tungsten\game\decls\declnavigation.cpp
// ========================================================================

void _unwind_488363()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8368 + 112));
}

