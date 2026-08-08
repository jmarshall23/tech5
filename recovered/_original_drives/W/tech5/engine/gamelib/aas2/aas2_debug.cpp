
// ========================================================================
// ?DefaultSearchBounds@idAAS2Local@@UBA?AVidBounds@@XZ
// EA  : 0x826AB278
// RVA : 0x006AB278
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::DefaultSearchBounds(idAAS2Local *this, idBounds *result)
{
  idAAS2Local *v2; // r10
  idAAS2Local_vtbl **v3; // r11
  int i; // ctr
  double v5; // fp12

  v2 = (idAAS2Local *)((char *)this - 4);
  v3 = (idAAS2Local_vtbl **)(LODWORD(result->b[0].y) + 156);
  for ( i = 6; i != 0; --i )
  {
    ++v3;
    v2 = (idAAS2Local *)((char *)v2 + 4);
    v2->__vftable = *v3;
  }
  v5 = (float)(*(float *)this->name.baseBuffer - *(float *)&this->name.len);
  *(float *)&this->name.len = (float)(*(float *)this->name.baseBuffer - *(float *)&this->name.len) * (float)-0.5;
  *(float *)this->name.baseBuffer = (float)v5 * (float)0.5;
  return this;
}


// ========================================================================
// ?DrawCone@idAAS2Local@@ABAXABVidVec3@@0MABVidVec4@@@Z
// EA  : 0x826AB2C8
// RVA : 0x006AB2C8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawCone(
        idAAS2Local *this,
        const idVec3 *origin,
        const idVec3 *dir,
        double radius,
        const idVec4 *color,
        const idVec4 *a6)
{
  double x; // fp27
  double z; // fp13
  __int64 v12; // r11
  int v13; // r31
  double v14; // fp30
  long double v15; // fp2
  double v16; // fp26
  double v17; // fp25
  double v18; // fp29
  double v19; // fp28
  double v20; // fp27
  double v21; // fp4
  double v22; // fp5
  double v23; // fp24
  double y; // fp23
  double v25; // fp22
  double v26; // fp21
  long double v27; // fp2
  double v28; // fp10
  double v29; // fp21
  double v30; // fp20
  double v31; // fp19
  long double v32; // fp2
  idRenderWorld *v33; // r3
  idRenderWorld *v34; // r3
  float v35; // [sp+58h] [-F8h] BYREF
  float v36; // [sp+5Ch] [-F4h]
  float v37; // [sp+60h] [-F0h]
  float v38; // [sp+68h] [-E8h] BYREF
  float v39; // [sp+6Ch] [-E4h]
  float v40; // [sp+70h] [-E0h]
  float v41[6]; // [sp+78h] [-D8h] BYREF
  idVec3 v42; // [sp+90h] [-C0h] BYREF
  idVec3 v43; // [sp+9Ch] [-B4h] BYREF
  idVec3 v44; // [sp+A8h] [-A8h] BYREF

  x = dir->x;
  v44.x = dir->x;
  z = dir->z;
  v44.y = dir->y;
  v44.z = z;
  idVec3::NormalVectors(this: &v44, left: &v42, down: &v43);
  v13 = 20;
  v14 = (float)(origin->x + (float)x);
  *((double *)&v15 + 1) = v43.y;
  v16 = -v43.y;
  v17 = -v43.z;
  v18 = (float)(origin->y + dir->y);
  v19 = (float)(origin->z + dir->z);
  v21 = (float)(dir->z * (float)((float)radius * (float)3.0));
  v22 = (float)(dir->y * (float)((float)radius * (float)3.0));
  v23 = v42.z;
  y = v42.y;
  v25 = v42.x;
  v39 = (float)((float)v16 * (float)radius) + (float)(origin->y + dir->y);
  v41[0] = (float)((float)x * (float)((float)radius * (float)3.0)) + (float)v14;
  v20 = -v43.x;
  v41[2] = (float)v21 + (float)v19;
  v41[1] = (float)v22 + (float)v18;
  v40 = (float)((float)v17 * (float)radius) + (float)v19;
  v38 = (float)((float)v20 * (float)radius) + (float)v14;
  do
  {
    LODWORD(v12) = v13;
    v26 = (float)v12;
    *(double *)&v15 = (float)((float)v12 * idMath::M_DEG2RAD);
    v27 = cos(x: v15);
    v28 = (float)((float)*(double *)&v27 * (float)radius);
    *(double *)&v27 = (float)((float)v26 * idMath::M_DEG2RAD);
    v29 = (float)((float)v28 * (float)v20);
    v30 = (float)((float)v16 * (float)v28);
    v31 = (float)((float)v17 * (float)v28);
    v32 = sin(x: v27);
    v35 = (float)((float)((float)v25 * (float)((float)*(double *)&v32 * (float)radius)) + (float)v14) + (float)v29;
    v36 = (float)((float)((float)y * (float)((float)*(double *)&v32 * (float)radius)) + (float)v18) + (float)v30;
    v37 = (float)((float)((float)v23 * (float)((float)*(double *)&v32 * (float)radius)) + (float)v19) + (float)v31;
    v33 = common->RW(this: common);
    v33->DebugLine(this: v33, a2: a6, a3: (const idVec3 *)&v38, a4: (const idVec3 *)&v35, a5: 0, a6: false);
    v34 = common->RW(this: common);
    v34->DebugLine(this: v34, a2: a6, a3: (const idVec3 *)&v35, a4: (const idVec3 *)v41, a5: 0, a6: false);
    v13 += 20;
    v38 = v35;
    v39 = v36;
    v40 = v37;
  }
  while ( v13 <= 360 );
}


// ========================================================================
// ?DrawAreaList@idAAS2Local@@ABAXABV?$idList@H$04@@@Z
// EA  : 0x826AB4E0
// RVA : 0x006AB4E0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawAreaList(idAAS2Local *this, const idList<int,5> *areaList)
{
  BOOL v4; // r25
  BOOL v5; // r24
  BOOL v6; // r23
  BOOL v7; // r22
  BOOL v8; // r21
  BOOL v9; // r26
  idResource *v10; // r28
  int v11; // r27
  int v12; // r28
  idRenderWorld *v13; // r3
  int v14; // r27
  int v15; // r28
  idStr v16[4]; // [sp+50h] [-90h] BYREF

  v4 = aas_drawAreaOutline.valueInteger != 0;
  v5 = aas_drawAreaNums.valueInteger != 0;
  v6 = aas_drawReaches.valueInteger != 0;
  v7 = aas_drawClusterNums.valueInteger != 0;
  v8 = aas_drawNormals.valueInteger != 0;
  v9 = aas_drawAreaFilled.valueInteger != 0;
  if ( aas_drawAreaFilled.valueInteger != 0
    && (v16[0].len = 0,
        v16[0].baseBuffer[0] = 0,
        v16[0].allocedAndFlag = 20,
        v16[0].data = v16[0].baseBuffer,
        idAAS2DebugAreaModelData::BuildResourceNameFromAASName(aasName: this->file->name.str, resourceName: v16),
        v10 = idResourceList::Load(
                this: &idAAS2DebugAreaModel::resourceList,
                name: v16[0].data,
                makeDefault: false,
                skipStaleCheck: true),
        idStr::FreeData(this: v16),
        v10 != nullptr) )
  {
    v13 = common->RW(this: common);
    idAAS2DebugAreaModelData::Draw(this: (idAAS2DebugAreaModelData *)&v10[1], rw: v13, visibleAreas: areaList);
  }
  else
  {
    v11 = 0;
    if ( areaList->num > 0 )
    {
      v12 = 0;
      do
      {
        this->DrawArea(this, a2: areaList->list[v12], a3: v6, a4: v5, a5: v7, a6: v8, a7: v9, a8: v4);
        ++v11;
        ++v12;
      }
      while ( v11 < areaList->num );
    }
  }
  if ( v4 || v5 )
  {
    v14 = 0;
    if ( areaList->num > 0 )
    {
      v15 = 0;
      do
      {
        this->DrawArea(this, a2: areaList->list[v15], a3: v6, a4: v5, a5: v7, a6: v8, a7: false, a8: v4);
        ++v14;
        ++v15;
      }
      while ( v14 < areaList->num );
    }
  }
}


// ========================================================================
// __unwind$250684
// EA  : 0x826AB6D8
// RVA : 0x006AB6D8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_250684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?ShowWalkPath@idAAS2Local@@ABAXABVidVec3@@H0HHHHH@Z
// EA  : 0x826AB700
// RVA : 0x006AB700
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowWalkPath(
        idAAS2Local *this,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        const int travelFlags,
        int pathOptimizationTravelFlags,
        int passEntityNum,
        const int time,
        const int gameMsPerFrame)
{
  float y; // r9
  float z; // r8
  idAAS2Local_vtbl *v16; // r23
  int valueInteger; // r29
  int v18; // r22
  idBounds *v19; // r3
  int v20; // r29
  int v21; // r9
  int v22; // r8
  _DWORD v23[4]; // [sp+60h] [-80h] BYREF
  _BYTE v24[112]; // [sp+70h] [-70h] BYREF

  if ( this->file != nullptr )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    v16 = this->__vftable;
    v23[0] = LODWORD(startOrigin->x);
    *(float *)&v23[1] = y;
    *(float *)&v23[2] = z;
    valueInteger = aas_tree.valueInteger;
    v18 = v16->GetInvalidTravelFlags(this);
    v19 = this->DefaultSearchBounds(this: v24, result: this);
    v20 = v16->PointReachableAreaNum(
            this,
            a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
            a3: (const idVec3 *)v23,
            a4: v19,
            a5: 2,
            a6: v18);
    this->PushPointIntoAreaNum(this, a2: v20, a3: (idVec3 *)v23);
    v21 = pathOptimizationTravelFlags;
    if ( pathOptimizationTravelFlags == 0 )
      v21 = 62;
    v22 = globalTravelFlags;
    if ( globalTravelFlags == 0 )
      v22 = -2;
    ((void (__fastcall *)(idAAS2Local *, int, _DWORD *, int, const idVec3 *, int, int, int))this->ShowWalkPath)(
      a1: this,
      a2: v20,
      a3: v23,
      a4: goalAreaNum,
      a5: goalOrigin,
      a6: v22,
      a7: v21,
      a8: passEntityNum);
  }
}


// ========================================================================
// ?ShowHopPath@idAAS2Local@@ABAXABVidVec3@@H0HH@Z
// EA  : 0x826AB828
// RVA : 0x006AB828
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowHopPath(
        idAAS2Local *this,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int pathOptimizationTravelFlags)
{
  float y; // r9
  float z; // r8
  idAAS2Local_vtbl *v12; // r25
  int valueInteger; // r29
  int v14; // r24
  idBounds *v15; // r3
  int v16; // r29
  int v17; // r9
  int v18; // r8
  _DWORD v19[4]; // [sp+50h] [-80h] BYREF
  float v20[4]; // [sp+60h] [-70h] BYREF
  char v21; // [sp+70h] [-60h] BYREF

  if ( this->file != nullptr )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    v12 = this->__vftable;
    v19[0] = LODWORD(startOrigin->x);
    *(float *)&v19[1] = y;
    *(float *)&v19[2] = z;
    valueInteger = aas_tree.valueInteger;
    v14 = v12->GetInvalidTravelFlags(this);
    v15 = this->DefaultSearchBounds(this: &v21, result: this);
    v16 = v12->PointReachableAreaNum(
            this,
            a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
            a3: (const idVec3 *)v19,
            a4: v15,
            a5: 2,
            a6: v14);
    this->PushPointIntoAreaNum(this, a2: v16, a3: (idVec3 *)v19);
    v17 = pathOptimizationTravelFlags;
    v20[0] = 8192.0;
    v20[1] = 1024.0;
    v20[2] = 64.0;
    v20[3] = 2.0;
    if ( pathOptimizationTravelFlags == 0 )
      v17 = 62;
    v18 = globalTravelFlags;
    if ( globalTravelFlags == 0 )
      v18 = -2;
    this->ShowHopPath(
      this,
      a2: v16,
      a3: (const idVec3 *)v19,
      a4: goalAreaNum,
      a5: goalOrigin,
      a6: v18,
      a7: v17,
      a8: (const idAAS2HopPathParms *)v20);
  }
}


// ========================================================================
// ?ShowOptimizedWalkPath@idAAS2Local@@ABAXABVidVec3@@H0HH@Z
// EA  : 0x826AB970
// RVA : 0x006AB970
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowOptimizedWalkPath(
        idAAS2Local *this,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int pathOptimizationTravelFlags)
{
  float y; // r9
  float z; // r8
  idAAS2Local_vtbl *v11; // r25
  int valueInteger; // r29
  int v13; // r24
  idBounds *v14; // r3
  int v15; // r29
  _DWORD v16[4]; // [sp+50h] [-70h] BYREF
  char v17; // [sp+60h] [-60h] BYREF

  if ( this->file != nullptr )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    v11 = this->__vftable;
    v16[0] = LODWORD(startOrigin->x);
    *(float *)&v16[1] = y;
    *(float *)&v16[2] = z;
    valueInteger = aas_tree.valueInteger;
    v13 = v11->GetInvalidTravelFlags(this);
    v14 = this->DefaultSearchBounds(this: &v17, result: this);
    v15 = v11->PointReachableAreaNum(
            this,
            a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
            a3: (const idVec3 *)v16,
            a4: v14,
            a5: 2,
            a6: v13);
    this->PushPointIntoAreaNum(this, a2: v15, a3: (idVec3 *)v16);
    ((void (__fastcall *)(idAAS2Local *, int, _DWORD *, int, const idVec3 *))this->ShowOptimizedWalkPath)(
      a1: this,
      a2: v15,
      a3: v16,
      a4: goalAreaNum,
      a5: goalOrigin);
  }
}


// ========================================================================
// ?ProjectTopDown@@YAXAAVidVec3@@ABV1@ABVidMat3@@2M@Z
// EA  : 0x826ABA80
// RVA : 0x006ABA80
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall ProjectTopDown(
        idVec3 *point,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        const idMat3 *playerAxis,
        double distance)
{
  double y; // fp9
  double z; // fp7
  double v7; // fp5
  double v8; // fp3
  double v9; // fp2
  double v10; // fp0
  double v11; // fp13
  double v12; // fp4
  double v13; // fp3
  double v14; // fp10
  double v15; // fp9

  y = playerAxis->mat[0].y;
  z = playerAxis->mat[0].z;
  v7 = (float)(point->x - viewOrigin->x);
  v8 = (float)((float)(playerAxis->mat[2].y * (float)(point->z - viewOrigin->z))
             + (float)(playerAxis->mat[1].y * (float)(point->y - viewOrigin->y)));
  v9 = (float)((float)(playerAxis->mat[2].z * (float)(point->z - viewOrigin->z))
             + (float)(playerAxis->mat[1].z * (float)(point->y - viewOrigin->y)));
  v10 = (float)((float)(playerAxis->mat[0].x * (float)(point->x - viewOrigin->x))
              + (float)((float)(playerAxis->mat[2].x * (float)(point->z - viewOrigin->z))
                      + (float)(playerAxis->mat[1].x * (float)(point->y - viewOrigin->y))));
  point->x = (float)(playerAxis->mat[0].x * (float)(point->x - viewOrigin->x))
           + (float)((float)(playerAxis->mat[2].x * (float)(point->z - viewOrigin->z))
                   + (float)(playerAxis->mat[1].x * (float)(point->y - viewOrigin->y)));
  v11 = (float)((float)((float)y * (float)v7) + (float)v8);
  point->y = (float)((float)y * (float)v7) + (float)v8;
  point->z = (float)((float)z * (float)v7) + (float)v9;
  v12 = (float)(viewAxis->mat[2].x * (float)v10);
  v14 = (float)((float)((float)(viewAxis->mat[0].y * (float)distance) + viewOrigin->y)
              + (float)(viewAxis->mat[1].y * (float)((float)((float)y * (float)v7) + (float)v8)));
  v15 = (float)((float)(viewOrigin->x + (float)(viewAxis->mat[0].x * (float)distance))
              + (float)(viewAxis->mat[1].x * (float)((float)((float)y * (float)v7) + (float)v8)));
  v13 = (float)(viewAxis->mat[2].y * (float)v10);
  point->z = (float)((float)(viewOrigin->z + (float)(viewAxis->mat[0].z * (float)distance))
                   + (float)(viewAxis->mat[1].z * (float)v11))
           + (float)(viewAxis->mat[2].z * (float)v10);
  point->y = (float)v14 + (float)v13;
  point->x = (float)v15 + (float)v12;
}


// ========================================================================
// ?ShowPushIntoArea@idAAS2Local@@ABAXABVidVec3@@@Z
// EA  : 0x826ABB88
// RVA : 0x006ABB88
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowPushIntoArea(idAAS2Local *this, const idVec3 *origin)
{
  idAAS2Local_vtbl *v2; // r27
  double y; // fp13
  double z; // fp12
  int valueInteger; // r31
  int v8; // r26
  idBounds *v9; // r3
  int v10; // r3
  idRenderWorld *v11; // r3
  float v12[4]; // [sp+50h] [-60h] BYREF
  char v13; // [sp+60h] [-50h] BYREF

  v2 = this->__vftable;
  y = origin->y;
  z = origin->z;
  v12[0] = origin->x;
  v12[1] = y;
  v12[2] = z;
  valueInteger = aas_tree.valueInteger;
  v8 = v2->GetInvalidTravelFlags(this);
  v9 = this->DefaultSearchBounds(this: &v13, result: this);
  v10 = v2->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: (const idVec3 *)v12,
          a4: v9,
          a5: 2,
          a6: v8);
  this->PushPointIntoAreaNum(this, a2: v10, a3: (idVec3 *)v12);
  v11 = common->RW(this: common);
  ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))v11->DebugArrow)(
    a1: v11,
    a2: &idColor::colorGreen,
    a3: origin,
    a4: v12,
    a5: 1.0);
}


// ========================================================================
// ?ShowHeightTrace@idAAS2Local@@ABAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826ABC80
// RVA : 0x006ABC80
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowHeightTrace(idAAS2Local *this, const idVec3 *origin, const idMat3 *viewAxis)
{
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v6; // fp10
  int v7; // r31
  double v8; // fp9
  double v9; // fp7
  bool (__fastcall *TraceHeight)(struct idAAS2Local *, idIndex<int,enum invalidAASTree_t> *__struct_ptr, aas2TraceHeight_t *, const idVec3 *, const idVec3 *); // r10
  int i; // r27
  idColor *v13; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idRenderWorld *v17; // r3
  idRenderWorld *v18; // r3
  int v19; // [sp+50h] [-C70h] BYREF
  int v20; // [sp+54h] [-C6Ch]
  char *v21; // [sp+58h] [-C68h]
  float v22[4]; // [sp+60h] [-C60h] BYREF
  float v23[4]; // [sp+70h] [-C50h] BYREF
  char v24; // [sp+80h] [-C40h] BYREF

  x = viewAxis->mat[0].x;
  y = viewAxis->mat[0].y;
  z = viewAxis->mat[0].z;
  v6 = origin->x;
  v7 = 0;
  v8 = origin->y;
  v19 = 256;
  v20 = 0;
  v9 = origin->z;
  v21 = &v24;
  TraceHeight = this->TraceHeight;
  v22[0] = (float)v6 + (float)((float)x * (float)2048.0);
  v22[1] = (float)v8 + (float)((float)y * (float)2048.0);
  v22[2] = (float)v9 + (float)((float)z * (float)2048.0);
  TraceHeight(
    this,
    a2: (idIndex<int,enum invalidAASTree_t> *)aas_tree.valueInteger,
    a3: (aas2TraceHeight_t *)&v19,
    a4: origin,
    a5: (const idVec3 *)v22);
  for ( i = 0; i < v20; v7 += 12 )
  {
    if ( i <= 0 )
    {
      v18 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, double))v18->DebugArrow)(
        a1: v18,
        a2: &idColor::colorGreen,
        a3: origin,
        a4: 16.0);
    }
    else
    {
      v13 = &idColor::colorGreen;
      if ( i % 2 == 0 )
        v13 = &idColor::colorRed;
      g = v13->g;
      b = v13->b;
      a = v13->a;
      v23[0] = v13->r;
      v23[1] = g;
      v23[2] = b;
      v23[3] = a;
      v17 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, float *, char *, double))v17->DebugArrow)(
        a1: v17,
        a2: v23,
        a3: &v21[v7 - 12],
        a4: 16.0);
    }
    ++i;
  }
}


// ========================================================================
// ?ShowFloorTrace@idAAS2Local@@ABAXABVidVec3@@ABVidMat3@@M@Z
// EA  : 0x826ABE20
// RVA : 0x006ABE20
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowFloorTrace(
        idAAS2Local *this,
        const idVec3 *origin,
        const idMat3 *viewAxis,
        double showTraceDist)
{
  float y; // r9
  float z; // r8
  idAAS2Local_vtbl *v8; // r26
  float x; // r6
  float v12; // r5
  float v13; // r4
  int (__fastcall *GetInvalidTravelFlags)(struct idAAS2Local *); // r11
  int valueInteger; // r28
  int v16; // r25
  idBounds *v17; // r3
  int v18; // r28
  double v19; // fp13
  double v20; // fp8
  idAAS2Local_vtbl *v21; // r7
  double v22; // fp7
  double v23; // fp6
  bool (__fastcall *TraceFloor)(struct idAAS2Local *, aas2TraceFloor_t *, const idVec3 *, int, const idVec3 *, int, bool, bool, bool); // r29
  idRenderWorld *v25; // r3
  double v26; // fp29
  double v27; // fp28
  double v28; // fp27
  idColor *v29; // r29
  idRenderWorld *v30; // r3
  double v31; // fp9
  double v32; // fp7
  idRenderWorld *v33; // r3
  double v34; // fp13
  double v35; // fp11
  _DWORD v36[4]; // [sp+60h] [-130h] BYREF
  float v37; // [sp+70h] [-120h]
  float v38; // [sp+74h] [-11Ch]
  float v39; // [sp+78h] [-118h]
  float v40; // [sp+80h] [-110h] BYREF
  float v41; // [sp+84h] [-10Ch] BYREF
  float v42; // [sp+88h] [-108h]
  float v43; // [sp+8Ch] [-104h]
  int v44; // [sp+90h] [-100h]
  int v45; // [sp+94h] [-FCh]
  int v46; // [sp+98h] [-F8h]
  float v47; // [sp+9Ch] [-F4h]
  float v48; // [sp+A0h] [-F0h]
  float v49; // [sp+A4h] [-ECh]
  int v50; // [sp+A8h] [-E8h]
  int v51; // [sp+ACh] [-E4h]
  float v52; // [sp+B0h] [-E0h]
  float v53; // [sp+B4h] [-DCh]
  float v54; // [sp+B8h] [-D8h]
  int v55; // [sp+BCh] [-D4h]
  int v56; // [sp+C0h] [-D0h]
  int v57; // [sp+C4h] [-CCh]
  int v58; // [sp+C8h] [-C8h]
  int v59; // [sp+CCh] [-C4h]
  int v60; // [sp+D0h] [-C0h]
  float v61[4]; // [sp+D8h] [-B8h] BYREF
  float v62[4]; // [sp+E8h] [-A8h] BYREF
  float v63[6]; // [sp+F8h] [-98h] BYREF
  _BYTE v64[64]; // [sp+110h] [-80h] BYREF

  y = origin->y;
  z = origin->z;
  v8 = this->__vftable;
  x = viewAxis->mat[0].x;
  v36[0] = LODWORD(origin->x);
  *(float *)&v36[1] = y;
  *(float *)&v36[2] = z;
  v13 = viewAxis->mat[0].z;
  v12 = viewAxis->mat[0].y;
  GetInvalidTravelFlags = v8->GetInvalidTravelFlags;
  valueInteger = aas_tree.valueInteger;
  v37 = x;
  v38 = v12;
  v39 = v13;
  v16 = GetInvalidTravelFlags(this);
  v17 = this->DefaultSearchBounds(this: v64, result: this);
  v18 = v8->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: (const idVec3 *)v36,
          a4: v17,
          a5: 2,
          a6: v16);
  this->PushPointIntoAreaNum(this, a2: v18, a3: (idVec3 *)v36);
  if ( showTraceDist == 1.0 )
    v19 = 1024.0;
  else
    v19 = showTraceDist;
  v45 = 0;
  v50 = 0;
  v51 = 0;
  v20 = origin->x;
  v44 = 0;
  v40 = 0.0;
  v46 = 0;
  v21 = this->__vftable;
  v22 = origin->y;
  v23 = origin->z;
  v41 = 0.0;
  TraceFloor = v21->TraceFloor;
  v42 = 0.0;
  v43 = 0.0;
  v47 = 0.0;
  v48 = 0.0;
  v49 = 0.0;
  v55 = 0;
  v52 = 0.0;
  v56 = 0;
  v53 = 0.0;
  v57 = 0;
  v54 = 0.0;
  v58 = 0;
  v62[0] = (float)v20 + (float)(v37 * (float)v19);
  v62[1] = (float)v22 + (float)(v38 * (float)v19);
  v59 = 0;
  v62[2] = (float)v23 + (float)((float)v19 * (float)0.0);
  v60 = 0;
  ((void (__fastcall *)(idAAS2Local *, float *, _DWORD *, int, float *, int, _DWORD, _DWORD))TraceFloor)(
    a1: this,
    a2: &v40,
    a3: v36,
    a4: v18,
    a5: v62,
    a6: 40,
    a7: 0,
    a8: 0);
  v25 = common->RW(this: common);
  ((void (__fastcall *)(idRenderWorld *, idColor *, _DWORD *, float *, double))v25->DebugArrow)(
    a1: v25,
    a2: &idColor::colorCyan,
    a3: v36,
    a4: &v41,
    a5: 1.0);
  v26 = (float)(v41 + (float)(viewAxis->mat[2].x * (float)32.0));
  v27 = (float)(v42 + (float)(viewAxis->mat[2].y * (float)32.0));
  v28 = (float)(v43 + (float)(viewAxis->mat[2].z * (float)32.0));
  if ( v40 < 1.0 )
    v29 = &idColor::colorRed;
  else
    v29 = &idColor::colorGreen;
  v30 = common->RW(this: common);
  v31 = (float)(viewAxis->mat[1].z * (float)32.0);
  v32 = (float)((float)(viewAxis->mat[1].y * (float)32.0) + (float)v27);
  v61[0] = (float)(viewAxis->mat[1].x * (float)32.0) + (float)v26;
  v61[1] = v32;
  v61[2] = (float)v31 + (float)v28;
  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v30->DebugArrow)(
    a1: v30,
    a2: v29,
    a3: &v41,
    a4: v61,
    a5: 1.0);
  v33 = common->RW(this: common);
  v34 = (float)(viewAxis->mat[1].z * (float)32.0);
  v35 = (float)((float)v27 - (float)(viewAxis->mat[1].y * (float)32.0));
  v63[0] = (float)v26 - (float)(viewAxis->mat[1].x * (float)32.0);
  v63[1] = v35;
  v63[2] = (float)v28 - (float)v34;
  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v33->DebugArrow)(
    a1: v33,
    a2: v29,
    a3: &v41,
    a4: v63,
    a5: 1.0);
}


// ========================================================================
// ?ShowObstaclePVSClipModels@idAAS2Local@@ABAXABVidVec3@@PAVidClip@@@Z
// EA  : 0x826AC170
// RVA : 0x006AC170
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowObstaclePVSClipModels(idAAS2Local *this, const idVec3 *origin, idClip *clip)
{
  idAAS2Local_vtbl *v3; // r26
  int valueInteger; // r31
  int v8; // r25
  idBounds *v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r31
  idClipModel **v13; // r30
  _BYTE v14[28]; // [sp+50h] [-1060h] BYREF
  int v15; // [sp+6Ch] [-1044h] BYREF
  _BYTE v16[64]; // [sp+70h] [-1040h] BYREF

  v3 = this->__vftable;
  valueInteger = aas_tree.valueInteger;
  v8 = this->GetInvalidTravelFlags(this);
  v9 = this->DefaultSearchBounds(this: v14, result: this);
  v10 = v3->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: origin,
          a4: v9,
          a5: 2,
          a6: v8);
  v11 = this->GetObstaclePVSClipModels(this, a2: v10, a3: (idClipModel **)v16, a4: 1024);
  if ( v11 > 0 )
  {
    v12 = v11;
    v13 = (idClipModel **)&v15;
    do
    {
      ++v13;
      idClip::DrawSingleClipModel(
        this: clip,
        clipModel: *v13,
        origin: &(*v13)->origin,
        axis: &(*v13)->axis,
        lifeTime: 0);
      --v12;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?DrawTraversal@idAAS2Local@@ABAXPBUaas2Traversal_t@@_N@Z
// EA  : 0x826AC4D0
// RVA : 0x006AC4D0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawTraversal(idAAS2Local *this, const aas2Traversal_t *traversal, BOOL depthTest)
{
  idRenderWorld *v6; // r3
  idVec3 *p_endPoint; // r29
  idRenderWorld *v8; // r3
  __int64 v9; // r4
  __int128 v10; // r8
  double x; // fp13
  double y; // fp9
  const idVec3 *v13; // r5
  idRenderWorld *v14; // r3
  unsigned int flags; // r11
  const aas2TraversalEntityName_t *v16; // r26
  const aas2AnimName_t *v17; // r25
  double v18; // fp30
  double v19; // fp29
  double v20; // fp28
  idRenderWorld *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  idRenderWorld *v24; // r22
  double v25; // fp2
  double v26; // fp13
  va *v27; // r3
  idRenderWorld *v28; // r3
  __int64 v29; // r8
  idRenderWorld *v30; // r30
  __int64 v31; // r10
  va *v32; // r3
  int v33; // [sp+8h] [-1158h]
  int v34; // [sp+8h] [-1158h]
  int v35; // [sp+Ch] [-1154h]
  int v36; // [sp+Ch] [-1154h]
  int v37; // [sp+10h] [-1150h]
  int v38; // [sp+10h] [-1150h]
  int v39; // [sp+14h] [-114Ch]
  int v40; // [sp+14h] [-114Ch]
  int v41; // [sp+18h] [-1148h]
  int v42; // [sp+18h] [-1148h]
  int v43; // [sp+1Ch] [-1144h]
  int v44; // [sp+1Ch] [-1144h]
  const aas2AnimName_t *v45; // [sp+68h] [-10F8h] BYREF
  const aas2TraversalEntityName_t *v46; // [sp+6Ch] [-10F4h] BYREF
  idStr v47; // [sp+70h] [-10F0h] BYREF
  idColor v48; // [sp+90h] [-10D0h] BYREF
  idColor v49; // [sp+A0h] [-10C0h] BYREF
  float v50[4]; // [sp+B0h] [-10B0h] BYREF
  float v51[4]; // [sp+C0h] [-10A0h] BYREF
  idVec3 v52; // [sp+D0h] [-1090h] BYREF
  va v53; // [sp+E0h] [-1080h] BYREF

  v47.len = 0;
  v49 = idColor::colorCyan;
  v47.baseBuffer[0] = 0;
  v47.allocedAndFlag = 20;
  v47.data = v47.baseBuffer;
  if ( (traversal->flags & 1) == 0 )
    idStr::Append(this: &v47, text: "[DISABLED] ");
  if ( (traversal->flags & 0x400) != 0 )
  {
    v49 = idColor::colorMagenta;
    idStr::Append(this: &v47, text: "combat ");
  }
  if ( (traversal->flags & 2) != 0 )
  {
    v49 = idColor::colorOrange;
    idStr::Append(this: &v47, text: "evasion ");
  }
  if ( (traversal->flags & 4) != 0 )
  {
    v49 = idColor::colorRed;
    idStr::Append(this: &v47, text: "emergency ");
  }
  if ( (traversal->flags & 0x100) != 0 )
  {
    v49 = idColor::colorBrown;
    idStr::Append(this: &v47, text: "long ");
  }
  v6 = common->RW(this: common);
  p_endPoint = &traversal->endPoint;
  ((void (__fastcall *)(idRenderWorld *, idColor *, const aas2Traversal_t *, idVec3 *, double))v6->DebugArrow)(
    a1: v6,
    a2: &v49,
    a3: traversal,
    a4: &traversal->endPoint,
    a5: 5.0);
  v8 = common->RW(this: common);
  v8->DebugPoint(this: v8, a2: (const idVec4 *)&v49, a3: &traversal->endPoint, a4: 0, a5: depthTest);
  HIDWORD(v9) = common->RW(this: common);
  DWORD1(v10) = &off_82010000;
  LODWORD(v10) = traversal->orientationFwd.z;
  DWORD2(v10) = traversal->orientationFwd.y;
  x = traversal->startPoint.x;
  LODWORD(v9) = traversal->orientationFwd.x;
  y = traversal->startPoint.y;
  v51[2] = traversal->startPoint.z + (float)((float)((float)(__int64)v10 * (float)0.000030518509) * (float)16.0);
  v51[0] = (float)x + (float)((float)((float)v9 * (float)0.000030518509) * (float)16.0);
  v51[1] = (float)y + (float)((float)((float)*(__int64 *)((char *)&v10 + 4) * (float)0.000030518509) * (float)16.0);
  (*(void (__fastcall **)(_DWORD, idColor *, const aas2Traversal_t *, float *, double))(*(_DWORD *)HIDWORD(v9) + 180))(
    a1: HIDWORD(v9),
    a2: &idColor::colorCyan,
    a3: traversal,
    a4: v51,
    a5: 4.0);
  if ( traversal->extrusionDistance > 0 )
  {
    aas2Traversal_t::CalcExtrusionPoint(this: traversal, extrusionPoint: &v52, up: v13);
    v14 = common->RW(this: common);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const aas2Traversal_t *, idVec3 *, double))v14->DebugArrow)(
      a1: v14,
      a2: &idColor::colorYellow,
      a3: traversal,
      a4: &v52,
      a5: 5.0);
  }
  flags = traversal->flags;
  v48 = idColor::colorRed;
  if ( (flags & 0x3E000000) == 0x3E000000 )
  {
    idStr::Append(this: &v47, text: "classAll ");
    v48 = idColor::colorWhite;
  }
  else
  {
    if ( (flags & 0x2000000) != 0 )
    {
      idStr::Append(this: &v47, text: "classA ");
      v48 = idColor::colorWhite;
    }
    if ( (traversal->flags & 0x4000000) != 0 )
    {
      idStr::Append(this: &v47, text: "classB ");
      v48 = idColor::colorWhite;
    }
    if ( (traversal->flags & 0x8000000) != 0 )
    {
      idStr::Append(this: &v47, text: "classC ");
      v48 = idColor::colorWhite;
    }
    if ( (traversal->flags & 0x10000000) != 0 )
    {
      idStr::Append(this: &v47, text: "classD ");
      v48 = idColor::colorWhite;
    }
    if ( (traversal->flags & 0x20000000) != 0 )
    {
      idStr::Append(this: &v47, text: "classE ");
      v48 = idColor::colorWhite;
    }
  }
  v45 = nullptr;
  v16 = (const aas2TraversalEntityName_t *)"<unknown>";
  v17 = (const aas2AnimName_t *)"<unknown>";
  if ( (unsigned __int8)idAAS2File::GetAASAnim(
                          this: this->file,
                          index: (const idIndex<short,enum invalidAASAnimIndex_t> *)(unsigned __int16)traversal->animIndex.value,
                          name: &v45) != 0 )
    v17 = v45;
  v46 = nullptr;
  if ( (unsigned __int8)idAAS2File::GetAASTraversalNameIndex(
                          this: this->file,
                          index: (const idIndex<short,enum invalidAASTraversalNameIndex_t> *)(unsigned __int16)traversal->traversalNameIndex.value,
                          name: &v46) != 0 )
    v16 = v46;
  v18 = (float)(traversal->endPoint.z - traversal->startPoint.z);
  v19 = (float)(traversal->endPoint.y - traversal->startPoint.y);
  v20 = (float)(p_endPoint->x - traversal->startPoint.x);
  v21 = common->RW(this: common);
  HIDWORD(v22) = 0x82000000;
  LODWORD(v23) = "_AI_OBSTACLE";
  v24 = v21;
  v25 = (float)(traversal->endPoint.y + traversal->startPoint.y);
  v26 = (float)(p_endPoint->x + traversal->startPoint.x);
  HIDWORD(v23) = v47.data;
  v50[2] = (float)(traversal->startPoint.z + traversal->endPoint.z) * (float)0.5;
  v50[1] = (float)v25 * (float)0.5;
  v50[0] = (float)v26 * (float)0.5;
  v27 = va::va(
          this: &v53,
          fmt: "Traversal:%s\nAnim:%s\nFlags:%s",
          a3: __SPAIR64__((unsigned int)v16, (unsigned int)v17),
          a4: v23,
          a5: v22,
          a6: v33,
          a7: v35,
          a8: v37,
          a9: v39,
          a10: v41,
          a11: v43);
  ((void (__fastcall *)(idRenderWorld *, va *, float *, char *, idColor *, int, _DWORD, BOOL, double))v24->DebugText)(
    a1: v24,
    a2: v27,
    a3: v50,
    a4: byte_821B0000,
    a5: &v48,
    a6: 1,
    a7: 0,
    a8: depthTest,
    a9: 0.1);
  v28 = common->RW(this: common);
  HIDWORD(v29) = LODWORD(v18);
  LODWORD(v29) = "_AI_OBSTACLE";
  v30 = v28;
  v32 = va::va(
          this: &v53,
          fmt: "(%.2f %.2f %.2f)",
          a3: __SPAIR64__(LODWORD(v20), LODWORD(v19)),
          a4: v29,
          a5: v31,
          a6: v34,
          a7: v36,
          a8: v38,
          a9: v40,
          a10: v42,
          a11: v44,
          v20,
          v19,
          v18);
  ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, BOOL, double))v30->DebugText)(
    a1: v30,
    a2: v32,
    a3: p_endPoint,
    a4: v30->__vftable,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: 0,
    a8: depthTest,
    a9: 0.1);
  idStr::FreeData(this: &v47);
}


// ========================================================================
// __unwind$251764
// EA  : 0x826ACC00
// RVA : 0x006ACC00
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_251764()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 112));
}


// ========================================================================
// ?DrawEdge@idAAS2Local@@UBAXH_N00@Z
// EA  : 0x826ACC28
// RVA : 0x006ACC28
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawEdge(
        idAAS2Local *this,
        const int edgeNum,
        const bool drawArrow,
        const bool drawEdgeNums,
        const bool drawVertexNums)
{
  idAAS2File *file; // r11
  aas2Edge_t *v10; // r31
  idColor *v11; // r11
  float g; // r8
  float b; // r6
  bool v14; // cr58
  float a; // r5
  int (*RW)(void); // ctr
  int v17; // r3
  int v18; // r3
  idRenderWorld *v19; // r3
  __int64 v20; // r8
  __int64 v21; // r6
  idVec3 *list; // r10
  __int64 v23; // r10
  idRenderWorld *v24; // r24
  float *p_x; // r11
  double v26; // fp3
  double v27; // fp1
  va *v28; // r3
  idRenderWorld *v29; // r3
  __int64 v30; // r6
  idRenderWorld *v31; // r25
  __int64 v32; // r10
  __int64 v33; // r8
  int v34; // r26
  va *v35; // r3
  idRenderWorld *v36; // r3
  __int64 v37; // r6
  idRenderWorld *v38; // r30
  __int64 v39; // r8
  __int64 v40; // r10
  int v41; // r31
  va *v42; // r3
  int v43; // [sp+8h] [-10C8h]
  int v44; // [sp+8h] [-10C8h]
  int v45; // [sp+Ch] [-10C4h]
  int v46; // [sp+Ch] [-10C4h]
  int v47; // [sp+10h] [-10C0h]
  int v48; // [sp+10h] [-10C0h]
  int v49; // [sp+14h] [-10BCh]
  int v50; // [sp+14h] [-10BCh]
  int v51; // [sp+18h] [-10B8h]
  int v52; // [sp+18h] [-10B8h]
  int v53; // [sp+1Ch] [-10B4h]
  int v54; // [sp+1Ch] [-10B4h]
  float v55[4]; // [sp+60h] [-1070h] BYREF
  float v56[4]; // [sp+70h] [-1060h] BYREF
  va v57; // [sp+80h] [-1050h] BYREF

  file = this->file;
  if ( file != nullptr )
  {
    v10 = &file->edges.list[edgeNum];
    if ( (v10->flags & 0x200) != 0 )
      v11 = &idColor::colorRed;
    else
      v11 = &idColor::colorWhite;
    g = v11->g;
    b = v11->b;
    v14 = !drawArrow;
    a = v11->a;
    v56[0] = v11->r;
    v56[1] = g;
    v56[2] = b;
    v56[3] = a;
    RW = (int (*)(void))common->RW;
    if ( v14 )
    {
      v18 = RW();
      (*(void (__fastcall **)(int, float *, idVec3 *, idVec3 *, _DWORD, _DWORD))(*(_DWORD *)v18 + 176))(
        a1: v18,
        a2: v56,
        a3: &this->file->vertices.list[v10->vertexNum[0]],
        a4: &this->file->vertices.list[v10->vertexNum[1]],
        a5: 0,
        a6: 0);
    }
    else
    {
      v17 = RW();
      (*(void (__fastcall **)(int, float *, idVec3 *, idVec3 *, double))(*(_DWORD *)v17 + 180))(
        a1: v17,
        a2: v56,
        a3: &this->file->vertices.list[v10->vertexNum[0]],
        a4: &this->file->vertices.list[v10->vertexNum[1]],
        a5: 1.0);
    }
    if ( drawEdgeNums )
    {
      v19 = common->RW(this: common);
      HIDWORD(v20) = 0x82000000;
      LODWORD(v21) = &off_82010000;
      LODWORD(v20) = 2 * v10->vertexNum[0];
      list = this->file->vertices.list;
      HIDWORD(v23) = 12 * v10->vertexNum[0];
      v24 = v19;
      p_x = &list[v10->vertexNum[1]].x;
      LODWORD(v23) = (char *)list + HIDWORD(v23);
      HIDWORD(v21) = edgeNum;
      v26 = (float)((float)(p_x[2] + *(float *)(v23 + 8)) * (float)0.5);
      v27 = (float)((float)(p_x[1] + *(float *)(v23 + 4)) * (float)0.5);
      v55[0] = (float)(*p_x + *(float *)v23) * (float)0.5;
      v55[1] = v27;
      v55[2] = (float)v26 + (float)4.0;
      v28 = va::va(
              this: &v57,
              fmt: "%d",
              a3: v21,
              a4: v20,
              a5: v23,
              a6: v43,
              a7: v45,
              a8: v47,
              a9: v49,
              a10: v51,
              a11: v53);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, _DWORD, double))v24->DebugText)(
        a1: v24,
        a2: v28,
        a3: v55,
        a4: v24->DebugText,
        a5: v56,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.1);
    }
    if ( drawVertexNums )
    {
      v29 = common->RW(this: common);
      HIDWORD(v30) = v10->vertexNum[0];
      v31 = v29;
      HIDWORD(v32) = this->file;
      LODWORD(v33) = 3 * v10->vertexNum[0];
      LODWORD(v32) = 12 * v10->vertexNum[0];
      v34 = v32 + *(_DWORD *)(HIDWORD(v32) + 384);
      v35 = va::va(
              this: &v57,
              fmt: "%d",
              a3: v30,
              a4: v33,
              a5: v32,
              a6: v43,
              a7: v45,
              a8: v47,
              a9: v49,
              a10: v51,
              a11: v53);
      ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v31->DebugText)(
        a1: v31,
        a2: v35,
        a3: v34,
        a4: v31->__vftable,
        a5: &idColor::colorCyan,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.1);
      v36 = common->RW(this: common);
      HIDWORD(v37) = v10->vertexNum[1];
      v38 = v36;
      LODWORD(v39) = this->file;
      HIDWORD(v39) = 3 * HIDWORD(v37);
      LODWORD(v40) = *(_DWORD *)(v39 + 384);
      v41 = 12 * HIDWORD(v37) + v40;
      v42 = va::va(
              this: &v57,
              fmt: "%d",
              a3: v37,
              a4: v39,
              a5: v40,
              a6: v44,
              a7: v46,
              a8: v48,
              a9: v50,
              a10: v52,
              a11: v54);
      ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v38->DebugText)(
        a1: v38,
        a2: v42,
        a3: v41,
        a4: v38->__vftable,
        a5: &idColor::colorCyan,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.1);
    }
  }
}


// ========================================================================
// ?DrawArea@idAAS2Local@@UBAXH_N00000@Z
// EA  : 0x826ACF88
// RVA : 0x006ACF88
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawArea(
        idAAS2Local *this,
        int areaNum,
        const bool drawReachabilities,
        const bool drawAreaNums,
        const bool drawClusterNums,
        const bool drawNormal,
        const bool drawAreaFilled,
        const bool drawAreaOutline)
{
  idAAS2File *file; // r11
  int v14; // r29
  int i; // r30
  const idIndex<short,enum invalidReachability_t> *value; // r4
  int v17; // r11
  aas2Reachability_t *list; // r10
  int v19; // r30
  idRenderWorld *v20; // r30
  float *v21; // r3
  __int64 v22; // r6
  double v23; // fp12
  double v24; // fp11
  __int64 v25; // r10
  va *v26; // r3
  idRenderWorld *v27; // r30
  float *v28; // r3
  __int64 v29; // r6
  double v30; // fp13
  double v31; // fp12
  __int64 v32; // r10
  va *v33; // r3
  idRenderWorld *v34; // r30
  float *v35; // r3
  __int64 v36; // r6
  double v37; // fp12
  double v38; // fp11
  __int64 v39; // r10
  va *v40; // r3
  int v41; // [sp+8h] [-10F8h]
  int v42; // [sp+Ch] [-10F4h]
  int v43; // [sp+10h] [-10F0h]
  int v44; // [sp+14h] [-10ECh]
  int v45; // [sp+18h] [-10E8h]
  int v46; // [sp+1Ch] [-10E4h]
  float v47[4]; // [sp+60h] [-10A0h] BYREF
  float v48[4]; // [sp+70h] [-1090h] BYREF
  float v49[4]; // [sp+80h] [-1080h] BYREF
  idAAS2File v50[5]; // [sp+90h] [-1070h] BYREF

  file = this->file;
  if ( file != nullptr && areaNum != 0 )
  {
    v14 = (int)&file->areas.list[areaNum];
    if ( drawAreaOutline )
    {
      for ( i = 0; i < *(__int16 *)(v14 + 6); ++i )
        this->DrawEdge(
          this,
          a2: abs32(this->file->edgeIndex.list[i + *(_DWORD *)(v14 + 8)]),
          a3: aas_drawEdgeDirection.valueInteger != 0,
          a4: aas_drawEdgeNums.valueInteger != 0,
          a5: aas_drawVertexNums.valueInteger != 0);
    }
    if ( drawReachabilities )
    {
      value = (const idIndex<short,enum invalidReachability_t> *)*(unsigned __int16 *)(v14 + 20);
      v17 = (__int16)value;
      if ( (__int16)value >= 0 )
      {
        list = this->file->reachabilities.list;
        do
        {
          v19 = v17;
          this->DrawReachability(this, a2: value, a3: &list[v17], a4: nullptr);
          list = this->file->reachabilities.list;
          value = (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)list[v19].next.value;
          v17 = (__int16)value;
        }
        while ( (__int16)value >= 0 );
      }
    }
    if ( !drawClusterNums )
      goto LABEL_15;
    if ( drawAreaNums )
    {
      v20 = common->RW(this: common);
      v21 = (float *)idAAS2File::AreaCenter(this: v50, result: (idVec3 *)this->file, areaNum);
      HIDWORD(v22) = areaNum;
      v23 = v21[1];
      v24 = (float)(v21[2] + (float)4.0);
      v48[0] = *v21;
      v48[1] = v23;
      v48[2] = v24;
      LODWORD(v22) = *(__int16 *)(v14 + 12);
      v26 = va::va(
              this: (va *)&v50[0].resourceListPtr,
              fmt: "%d : c(%d)",
              a3: v22,
              a4: __SPAIR64__(&off_82010000, (unsigned int)v21),
              a5: v25,
              a6: v41,
              a7: v42,
              a8: v43,
              a9: v44,
              a10: v45,
              a11: v46);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v20->DebugText)(
        a1: v20,
        a2: v26,
        a3: v48,
        a4: v20->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.1);
      return;
    }
    if ( drawClusterNums )
    {
      v27 = common->RW(this: common);
      v28 = (float *)idAAS2File::AreaCenter(this: v50, result: (idVec3 *)this->file, areaNum);
      LODWORD(v29) = "_AI_OBSTACLE";
      v30 = v28[2];
      v31 = v28[1];
      v49[0] = *v28;
      v49[1] = v31;
      v49[2] = (float)v30 + (float)4.0;
      HIDWORD(v29) = *(__int16 *)(v14 + 12);
      v33 = va::va(
              this: (va *)&v50[0].resourceListPtr,
              fmt: "c(%d)",
              a3: v29,
              a4: __SPAIR64__(&off_82010000, (unsigned int)v28),
              a5: v32,
              a6: v41,
              a7: v42,
              a8: v43,
              a9: v44,
              a10: v45,
              a11: v46);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v27->DebugText)(
        a1: v27,
        a2: v33,
        a3: v49,
        a4: v27->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.1);
    }
    else
    {
LABEL_15:
      if ( drawAreaNums )
      {
        v34 = common->RW(this: common);
        v35 = (float *)idAAS2File::AreaCenter(this: v50, result: (idVec3 *)this->file, areaNum);
        LODWORD(v36) = 0x82000000;
        HIDWORD(v36) = areaNum;
        v37 = v35[1];
        v38 = (float)(v35[2] + (float)4.0);
        v47[0] = *v35;
        v47[1] = v37;
        v47[2] = v38;
        v40 = va::va(
                this: (va *)&v50[0].resourceListPtr,
                fmt: "%d",
                a3: v36,
                a4: __SPAIR64__(&off_82010000, (unsigned int)v35),
                a5: v39,
                a6: v41,
                a7: v42,
                a8: v43,
                a9: v44,
                a10: v45,
                a11: v46);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v34->DebugText)(
          a1: v34,
          a2: v40,
          a3: v47,
          a4: v34->DebugText,
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.1);
      }
    }
  }
}


// ========================================================================
// ?ShowHopPath@idAAS2Local@@UBAXHABVidVec3@@H0HHABUidAAS2HopPathParms@@@Z
// EA  : 0x826AD320
// RVA : 0x006AD320
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAAS2Local::ShowHopPath(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags,
        const idAAS2HopPathParms *parms)
{
  float y; // r10
  int toAreaNum; // r29
  float z; // r9
  int v16; // r14
  aas2Reachability_t *v17; // r30
  idRenderWorld *v18; // r3
  __int64 v19; // r6 OVERLAPPED
  __int64 v20; // r8 OVERLAPPED
  int v21; // r9
  __int16 v22; // r7
  __int64 v23; // r11
  __int128 v24; // r5
  idRenderWorld *v25; // r3
  idRenderWorld *v26; // r3
  __int16 v27[4]; // [sp+60h] [-2C0h] BYREF
  float x; // [sp+68h] [-2B8h] BYREF
  float v29; // [sp+6Ch] [-2B4h]
  float v30; // [sp+70h] [-2B0h]
  float v31[4]; // [sp+78h] [-2A8h] BYREF
  __int64 v32; // [sp+88h] [-298h]
  __int64 v33; // [sp+90h] [-290h]
  __int64 v34; // [sp+98h] [-288h]
  __int64 v35; // [sp+A0h] [-280h]
  __int64 v36; // [sp+A8h] [-278h]
  __int64 v37; // [sp+B0h] [-270h]
  _BYTE v38[8]; // [sp+B8h] [-268h] BYREF
  idAAS2Path v39; // [sp+C0h] [-260h] BYREF

  if ( this->file != nullptr )
  {
    y = startOrigin->y;
    toAreaNum = startAreaNum;
    z = startOrigin->z;
    x = startOrigin->x;
    v29 = y;
    v30 = z;
    v16 = 0;
    do
    {
      v27[0] = -1;
      if ( !this->RouteToGoalArea(
              this,
              a2: toAreaNum,
              a3: (const idVec3 *)&x,
              a4: goalAreaNum,
              a5: goalOrigin,
              a6: travelFlags,
              a7: (int *)v38,
              a8: (idIndex<short,enum invalidReachability_t> *)v27)
        || v27[0] < 0 )
      {
        break;
      }
      v17 = &this->file->reachabilities.list[v27[0]];
      v18 = common->RW(this: common);
      HIDWORD(v19) = &x;
      HIDWORD(v20) = (unsigned __int16)v17->start[2];
      LODWORD(v20) = v17->start[1];
      LODWORD(v19) = v17->start[0];
      v21 = SWORD1(v20);
      v37 = v20;
      v34 = v19;
      v35 = *(__int64 *)((char *)&v20 - 4);
      v31[1] = (float)v20;
      v31[0] = (float)v19;
      v31[2] = (float)*(__int64 *)((char *)&v20 - 4);
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, _DWORD, _DWORD, _DWORD, double))v18->DebugArrow)(
        a1: v18,
        a2: &idColor::colorGreen,
        a3: &x,
        a4: v31,
        a5: HIDWORD(v20),
        a6: 0,
        a7: 0,
        a8: 2.0);
      this->DrawReachability(
        this,
        a2: (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)v27[0],
        a3: v17,
        a4: nullptr);
      if ( aas_showAreas.valueInteger != 0 )
        this->DrawArea(
          this,
          a2: toAreaNum,
          a3: aas_drawReaches.valueInteger != 0,
          a4: aas_drawAreaNums.valueInteger != 0,
          a5: aas_drawClusterNums.valueInteger != 0,
          a6: aas_drawNormals.valueInteger != 0,
          a7: aas_drawAreaFilled.valueInteger != 0,
          a8: aas_drawAreaOutline.valueInteger != 0);
      if ( v17->toAreaNum == goalAreaNum )
        break;
      toAreaNum = v17->toAreaNum;
      v22 = v17->end[2];
      ++v16;
      HIDWORD(v23) = (unsigned __int16)v17->end[0];
      DWORD1(v24) = v22;
      DWORD2(v24) = v17->end[1];
      LODWORD(v23) = v22;
      v36 = *(_QWORD *)((char *)&v24 + 4);
      v33 = v23;
      LODWORD(v24) = SWORD1(v23);
      v32 = v24;
      x = (float)(__int64)v24;
      v30 = (float)v23;
      v29 = (float)*(__int64 *)((char *)&v24 + 4);
    }
    while ( v16 < 100 );
    idAAS2Path::idAAS2Path(this: &v39);
    if ( this->WalkPathToGoal(
           this,
           a2: &v39,
           a3: startAreaNum,
           a4: startOrigin,
           a5: goalAreaNum,
           a6: goalOrigin,
           a7: travelFlags,
           a8: walkTravelFlags) )
    {
      v25 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, idVec3 *, double))v25->DebugArrow)(
        a1: v25,
        a2: &idColor::colorBlue,
        a3: startOrigin,
        a4: &v39.moveGoal,
        a5: 2.0);
      if ( ((unsigned __int8 (__fastcall *)(idAAS2Local *, idAAS2Path *, int, const idVec3 *, int, const idVec3 *, int, int))this->ExtendHopPathToGoal)(
             a1: this,
             a2: &v39,
             a3: startAreaNum,
             a4: startOrigin,
             a5: goalAreaNum,
             a6: goalOrigin,
             a7: travelFlags,
             a8: walkTravelFlags) != 0 )
      {
        v26 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, idVec3 *, double))v26->DebugArrow)(
          a1: v26,
          a2: &idColor::colorCyan,
          a3: startOrigin,
          a4: &v39.moveGoal,
          a5: 2.0);
      }
    }
  }
}


// ========================================================================
// ?ShowOptimizedWalkPath@idAAS2Local@@UBAXHABVidVec3@@H0HH@Z
// EA  : 0x826AD6E0
// RVA : 0x006AD6E0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAAS2Local::ShowOptimizedWalkPath(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags)
{
  float y; // r8
  float z; // r7
  int toAreaNum; // r31
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  idRenderWorld *v18; // r3
  aas2Reachability_t *v19; // r31
  idRenderWorld *v20; // r3
  __int64 v21; // r6 OVERLAPPED
  __int64 v22; // r8 OVERLAPPED
  int v23; // r9
  idRenderWorld *v24; // r3
  int v25; // r6 OVERLAPPED
  __int128 v26; // r10 OVERLAPPED
  __int64 v27; // r6
  __int16 v28; // r11
  __int128 v29; // r4
  __int64 v30; // r10
  idRenderWorld *v31; // r3
  float x; // [sp+50h] [-300h] BYREF
  float v33; // [sp+54h] [-2FCh]
  float v34; // [sp+58h] [-2F8h]
  idVec3 v35; // [sp+60h] [-2F0h] BYREF
  float v36[4]; // [sp+70h] [-2E0h] BYREF
  float v37[4]; // [sp+80h] [-2D0h] BYREF
  float v38[4]; // [sp+90h] [-2C0h] BYREF
  __int64 v39; // [sp+A0h] [-2B0h]
  __int64 v40; // [sp+A8h] [-2A8h]
  __int64 v41; // [sp+B0h] [-2A0h]
  __int64 v42; // [sp+B8h] [-298h]
  __int64 v43; // [sp+C0h] [-290h]
  __int64 v44; // [sp+C8h] [-288h]
  __int64 v45; // [sp+D0h] [-280h]
  __int64 v46; // [sp+D8h] [-278h]
  __int64 v47; // [sp+E0h] [-270h]
  __int64 v48; // [sp+E8h] [-268h]
  __int64 v49; // [sp+F0h] [-260h]
  __int64 v50; // [sp+F8h] [-258h]
  idAAS2Path v51; // [sp+100h] [-250h] BYREF

  if ( this->file != nullptr )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    toAreaNum = startAreaNum;
    x = startOrigin->x;
    v33 = y;
    v34 = z;
    if ( startAreaNum == goalAreaNum )
    {
LABEL_18:
      v31 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, const idVec3 *, double))v31->DebugArrow)(
        a1: v31,
        a2: &idColor::colorBlue,
        a3: &x,
        a4: goalOrigin,
        a5: 2.0);
    }
    else
    {
      while ( 1 )
      {
        idAAS2Path::idAAS2Path(this: &v51);
        if ( !this->WalkPathToGoal(
                this,
                a2: &v51,
                a3: toAreaNum,
                a4: (const idVec3 *)&x,
                a5: goalAreaNum,
                a6: goalOrigin,
                a7: travelFlags,
                a8: walkTravelFlags) )
          break;
        if ( aas_showAreas.valueInteger != 0 )
          this->DrawArea(
            this,
            a2: toAreaNum,
            a3: aas_drawReaches.valueInteger != 0,
            a4: aas_drawAreaNums.valueInteger != 0,
            a5: aas_drawClusterNums.valueInteger != 0,
            a6: aas_drawNormals.valueInteger != 0,
            a7: aas_drawAreaFilled.valueInteger != 0,
            a8: aas_drawAreaOutline.valueInteger != 0);
        if ( v51.reachIndex.value >= 0 )
        {
          v19 = &this->file->reachabilities.list[v51.reachIndex.value];
          v20 = common->RW(this: common);
          HIDWORD(v21) = &x;
          HIDWORD(v22) = (unsigned __int16)v19->start[2];
          LODWORD(v22) = v19->start[1];
          LODWORD(v21) = v19->start[0];
          v23 = SWORD1(v22);
          v41 = v22;
          v43 = v21;
          v50 = *(__int64 *)((char *)&v22 - 4);
          v36[1] = (float)v22;
          v36[0] = (float)v21;
          v36[2] = (float)*(__int64 *)((char *)&v22 - 4);
          ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, _DWORD, _DWORD, _DWORD, double))v20->DebugArrow)(
            a1: v20,
            a2: &idColor::colorBlue,
            a3: &x,
            a4: v36,
            a5: HIDWORD(v22),
            a6: 0,
            a7: 0,
            a8: 2.0);
          v24 = common->RW(this: common);
          v25 = (unsigned __int16)v19->end[1];
          LODWORD(v26) = v19->end[2];
          DWORD2(v26) = (__int16)v25;
          HIDWORD(v26) = v19->end[0];
          v45 = v26;
          v47 = *(_QWORD *)((char *)&v26 + 4);
          v49 = *(_QWORD *)(&v25 - 1);
          v38[2] = (float)(__int64)v26;
          v38[1] = (float)*(__int64 *)((char *)&v26 + 4);
          v38[0] = (float)*(__int64 *)(&v25 - 1);
          LODWORD(v27) = v19->start[2];
          v28 = v19->start[0];
          v39 = v27;
          HIDWORD(v26) = v19->start[1];
          DWORD1(v26) = v28;
          v42 = *(_QWORD *)((char *)&v26 + 12);
          v46 = *(_QWORD *)&v26;
          v37[2] = (float)v27;
          v37[1] = (float)*(__int64 *)((char *)&v26 + 12);
          v37[0] = (float)*(__int64 *)&v26;
          ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v24->DebugArrow)(
            a1: v24,
            a2: &idColor::colorBlue,
            a3: v37,
            a4: v38,
            a5: 2.0);
          DWORD2(v29) = v19->end[1];
          HIDWORD(v30) = (unsigned __int16)v19->end[0];
          LODWORD(v30) = v19->end[2];
          v48 = *(_QWORD *)((char *)&v29 + 4);
          v40 = v30;
          LODWORD(v29) = SWORD1(v30);
          v44 = v29;
          x = (float)(__int64)v29;
          v34 = (float)v30;
          v33 = (float)*(__int64 *)((char *)&v29 + 4);
          toAreaNum = v19->toAreaNum;
        }
        else
        {
          if ( v51.firstEdge.edgeNum != 0
            && (float)((float)((float)(v51.firstEdge.edgePoint.x - x) * (float)(v51.firstEdge.edgePoint.x - x))
                     + (float)((float)((float)(v51.firstEdge.edgePoint.z - v34)
                                     * (float)(v51.firstEdge.edgePoint.z - v34))
                             + (float)((float)(v51.firstEdge.edgePoint.y - v33)
                                     * (float)(v51.firstEdge.edgePoint.y - v33)))) > 0.010000001 )
          {
            v35.x = v51.firstEdge.edgePoint.x;
            v35.y = v51.firstEdge.edgePoint.y;
            v35.z = v51.firstEdge.edgePoint.z;
            toAreaNum = v51.firstEdge.toAreaNum;
            idAAS2File::PushPointIntoAreaNum(this: this->file, areaNum: v51.firstEdge.toAreaNum, point: &v35);
          }
          else
          {
            if ( v51.obstacleRoute.numAreas > 1 && toAreaNum == v51.moveAreaNum )
            {
              v15 = v51.obstacleRoute.areas[1].start.x;
              toAreaNum = v51.obstacleRoute.areas[1].areaNum;
              v16 = v51.obstacleRoute.areas[1].start.y;
              v17 = v51.obstacleRoute.areas[1].start.z;
            }
            else
            {
              v15 = v51.moveGoal.x;
              toAreaNum = v51.moveAreaNum;
              v16 = v51.moveGoal.y;
              v17 = v51.moveGoal.z;
            }
            v35.z = v17;
            v35.y = v16;
            v35.x = v15;
          }
          v18 = common->RW(this: common);
          ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))v18->DebugArrow)(
            a1: v18,
            a2: &idColor::colorBlue,
            a3: &x,
            a4: &v35,
            a5: 2.0);
          x = v35.x;
          v33 = v35.y;
          v34 = v35.z;
        }
        if ( toAreaNum == goalAreaNum )
          goto LABEL_18;
      }
    }
  }
}


// ========================================================================
// ?ShowWallEdges@idAAS2Local@@ABAXABVidVec3@@0ABVidMat3@@H_N@Z
// EA  : 0x826ADB88
// RVA : 0x006ADB88
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowWallEdges(
        idAAS2Local *this,
        const idVec3 *origin,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        int mode,
        bool showNumbers)
{
  double v8; // fp11
  double v9; // fp10
  double v16; // fp4
  double v17; // fp7
  double v18; // fp4
  double v19; // fp27
  idAAS2Local_vtbl *v20; // r28
  double obstaclePVSRadius; // fp31
  int valueInteger; // r31
  int v23; // r25
  idBounds *v24; // r3
  int v25; // r3
  int v26; // r3
  idAAS2File *file; // r7
  int v28; // ctr
  int *v29; // r10
  int *v30; // r6
  int v31; // r9
  int v32; // r31
  int *v33; // r30
  int i; // r21
  double z; // fp0
  const idMat3 *v36; // r5
  const idVec3 *v37; // r4
  int flags; // r11
  idRenderWorld *v39; // r3
  idColor *v40; // r4
  int (*RW)(void); // ctr
  idRenderWorld *v42; // r16
  __int64 v43; // r6
  __int64 v44; // r10
  __int64 v45; // r8
  va *v46; // r3
  float x; // r11
  float v48; // r8
  idVec3 *v49; // r3
  idVec3 *v50; // r3
  int v51; // r10
  float *v52; // r30
  idRenderWorld *v53; // r3
  idRenderWorld *v54; // r3
  idRenderWorld *v55; // r3
  int v56; // [sp+8h] [-21F8h]
  int v57; // [sp+Ch] [-21F4h]
  int v58; // [sp+10h] [-21F0h]
  int v59; // [sp+14h] [-21ECh]
  int v60; // [sp+18h] [-21E8h]
  int v61; // [sp+1Ch] [-21E4h]
  idVec3 v62; // [sp+60h] [-21A0h] BYREF
  idVec3 v63; // [sp+70h] [-2190h] BYREF
  float v64[4]; // [sp+80h] [-2180h] BYREF
  float y; // [sp+90h] [-2170h]
  float v66; // [sp+94h] [-216Ch]
  float v67; // [sp+98h] [-2168h]
  float v68; // [sp+9Ch] [-2164h]
  float v69; // [sp+A0h] [-2160h]
  float v70; // [sp+A4h] [-215Ch]
  float v71; // [sp+A8h] [-2158h]
  float v72; // [sp+ACh] [-2154h]
  float v73; // [sp+B0h] [-2150h] BYREF
  float v74; // [sp+B4h] [-214Ch]
  float v75; // [sp+B8h] [-2148h]
  float v76; // [sp+BCh] [-2144h] BYREF
  float v77; // [sp+C0h] [-2140h]
  float v78; // [sp+C4h] [-213Ch]
  float v79[4]; // [sp+C8h] [-2138h] BYREF
  float v80[6]; // [sp+D8h] [-2128h] BYREF
  idMat3 v81; // [sp+F0h] [-2110h] BYREF
  _BYTE v82[28]; // [sp+120h] [-20E0h] BYREF
  int v83; // [sp+13Ch] [-20C4h] BYREF
  _BYTE v84[192]; // [sp+140h] [-20C0h] BYREF
  va v85; // [sp+1140h] [-10C0h] BYREF

  v8 = -globalViewAxis.mat[0].x;
  v9 = -globalViewAxis.mat[0].y;
  _FP7 = (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f7, f8, f13 }
  v16 = __frsqrte(_FP5);
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                      * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))
                                                                                              * (float)0.5))
                                                                              * (float)v16)
                                                                      - (float)1.5)
                                                      * (float)v16)
                                              * (float)((float)((float)((float)v9 * (float)v9)
                                                              + (float)((float)v8 * (float)v8))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                              * (float)((float)((float)((float)v9 * (float)v9)
                                                                                              + (float)((float)v8 * (float)v8))
                                                                                      * (float)0.5))
                                                                      * (float)v16)
                                                              - (float)1.5)
                                              * (float)v16))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16));
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                              * (float)v16)
                                                                                      * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                      * (float)v16))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                                              * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)) * (float)0.5))
                                                                                      * (float)v16)
                                                                              - (float)1.5)
                                                              * (float)v16))
                                              * (float)((float)((float)((float)v9 * (float)v9)
                                                              + (float)((float)v8 * (float)v8))
                                                      * (float)0.5))
                                      * (float)v17)
                              - (float)1.5)
              * (float)v17);
  v81.mat[0].z = (float)v18 * (float)0.0;
  v81.mat[0].x = (float)v8 * (float)v18;
  v81.mat[0].y = (float)v9 * (float)v18;
  idVec3::OrthogonalBasis(this: v81.mat, left: &v81.mat[1], up: &v81.mat[2]);
  if ( mode == 3 )
    v19 = 0.2;
  else
    v19 = 0.1;
  v20 = this->__vftable;
  obstaclePVSRadius = this->file->settings.obstaclePVSRadius;
  valueInteger = aas_tree.valueInteger;
  v23 = this->GetInvalidTravelFlags(this);
  v24 = this->DefaultSearchBounds(this: v82, result: this);
  v25 = v20->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: origin,
          a4: v24,
          a5: 2,
          a6: v23);
  v26 = this->GetObstaclePVSWallEdges(this, a2: v25, a3: 515, a4: (int *)v84, a5: 1024);
  if ( v26 > 0 )
  {
    file = this->file;
    v28 = v26;
    v29 = (int *)v84;
    v30 = &v83;
    do
    {
      if ( (file->edges.list[abs32(*v29)].flags & 1) != 0 )
      {
        v31 = v30[1];
        *++v30 = *v29;
        *v29 = v31;
      }
      ++v29;
      --v28;
    }
    while ( v28 != 0 );
  }
  v32 = 0;
  if ( v26 > 0 )
  {
    v33 = (int *)v84;
    for ( i = v26; i != 0; --i )
    {
      this->GetEdge(this, a2: *v33, a3: &v63, a4: &v62);
      if ( mode == 2 )
      {
        z = origin->z;
        v63.z = origin->z;
        v62.z = z;
      }
      else if ( mode == 3 )
      {
        ProjectTopDown(
          point: &v63,
          viewOrigin,
          viewAxis,
          playerAxis: &v81,
          distance: (float)((float)obstaclePVSRadius * (float)2.0));
        ProjectTopDown(
          point: &v62,
          viewOrigin: v37,
          viewAxis: v36,
          playerAxis: &v81,
          distance: (float)((float)obstaclePVSRadius * (float)2.0));
      }
      flags = this->file->edges.list[abs32(*v33)].flags;
      if ( (flags & 1) != 0 )
      {
        v39 = common->RW(this: common);
        v40 = &idColor::colorRed;
      }
      else
      {
        RW = (int (*)(void))common->RW;
        if ( (flags & 0x200) != 0 )
        {
          v39 = (idRenderWorld *)RW();
          v40 = &idColor::colorLtGrey;
        }
        else
        {
          v39 = (idRenderWorld *)RW();
          v40 = &idColor::colorGreen;
        }
      }
      v39->DebugLine(this: v39, a2: (const idVec4 *)v40, a3: &v63, a4: &v62, a5: 0, a6: false);
      if ( showNumbers )
      {
        v42 = common->RW(this: common);
        HIDWORD(v43) = *v33;
        v80[0] = (float)(v62.x + v63.x) * (float)0.5;
        v80[1] = (float)(v63.y + v62.y) * (float)0.5;
        v80[2] = (float)(v63.z + v62.z) * (float)0.5;
        v46 = va::va(
                this: &v85,
                fmt: "%d",
                a3: v43,
                a4: v45,
                a5: v44,
                a6: v56,
                a7: v57,
                a8: v58,
                a9: v59,
                a10: v60,
                a11: v61);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v42->DebugText)(
          a1: v42,
          a2: v46,
          a3: v80,
          a4: v42->DebugText,
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: v19);
      }
      ++v33;
    }
  }
  if ( mode == 3 )
  {
    x = origin->x;
    v48 = origin->z;
    y = origin->y;
    v49 = (idVec3 *)v64;
    v64[2] = v48;
    v66 = v48;
    v69 = v48;
    v72 = v48;
    v73 = x;
    v75 = v48;
    v78 = v48;
    v79[2] = v48;
    v67 = x - (float)obstaclePVSRadius;
    v74 = y + (float)obstaclePVSRadius;
    v64[0] = x + (float)obstaclePVSRadius;
    v64[1] = v74;
    v64[3] = v64[0];
    v68 = y - (float)obstaclePVSRadius;
    v70 = v67;
    v71 = v74;
    v76 = (float)((float)obstaclePVSRadius * (float)0.1) + x;
    v77 = (float)((float)obstaclePVSRadius - (float)((float)obstaclePVSRadius * (float)0.1)) + y;
    v79[0] = x - (float)((float)obstaclePVSRadius * (float)0.1);
    v79[1] = v77;
    y = v68;
    do
    {
      ProjectTopDown(
        point: v49,
        viewOrigin,
        viewAxis,
        playerAxis: &v81,
        distance: (float)((float)obstaclePVSRadius * (float)2.0));
      v49 = v50 + 1;
    }
    while ( v51 != 1 );
    v52 = v64;
    do
    {
      v53 = common->RW(this: common);
      ++v32;
      v53->DebugLine(
        this: v53,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: (const idVec3 *)v52,
        a4: (const idVec3 *)&v64[(v32 & 3) + ((2 * v32) & 6)],
        a5: 0,
        a6: false);
      v52 += 3;
    }
    while ( v32 < 4 );
    v54 = common->RW(this: common);
    v54->DebugLine(
      this: v54,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v73,
      a4: (const idVec3 *)&v76,
      a5: 0,
      a6: false);
    v55 = common->RW(this: common);
    v55->DebugLine(
      this: v55,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v73,
      a4: (const idVec3 *)v79,
      a5: 0,
      a6: false);
  }
}


// ========================================================================
// ?ShowNearestInsideArea@idAAS2Local@@ABAXABVidVec3@@HHHHH@Z
// EA  : 0x826AE1E0
// RVA : 0x006AE1E0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowNearestInsideArea(
        idAAS2Local *this,
        const idVec3 *origin,
        int travelFlags,
        int pathOptimizationTravelFlags,
        int passEntityNum,
        int time,
        const int ticksPerSec)
{
  idAAS2Local_vtbl *v7; // r22
  int valueInteger; // r29
  int v13; // r21
  idBounds *v14; // r3
  int v15; // r28
  int v16; // r11
  int v17; // r9
  int v18; // r8
  const idVec4 *v19; // r6
  idVec3 v20[2]; // [sp+60h] [-C0h] BYREF
  int v21; // [sp+80h] [-A0h] BYREF
  idVec3 v22; // [sp+84h] [-9Ch] BYREF
  idAAS2Callback_FindFlaggedArea v23[4]; // [sp+90h] [-90h] BYREF

  v7 = this->__vftable;
  valueInteger = aas_tree.valueInteger;
  v13 = this->GetInvalidTravelFlags(this);
  v14 = this->DefaultSearchBounds(this: v20, result: this);
  v15 = v7->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: origin,
          a4: v14,
          a5: 2,
          a6: v13);
  idAAS2Callback_FindFlaggedArea::idAAS2Callback_FindFlaggedArea(this: v23, areaFlag: 4, set: false);
  v16 = globalTravelFlags;
  if ( globalTravelFlags == 0 )
    v16 = -2;
  if ( this->FindNearestGoal(this, a2: (idAAS2Goal *)&v21, a3: v15, a4: origin, a5: v16, a6: v23) )
  {
    this->DrawArea(
      this,
      a2: v21,
      a3: aas_drawReaches.valueInteger != 0,
      a4: aas_drawAreaNums.valueInteger != 0,
      a5: aas_drawClusterNums.valueInteger != 0,
      a6: aas_drawNormals.valueInteger != 0,
      a7: aas_drawAreaFilled.valueInteger != 0,
      a8: aas_drawAreaOutline.valueInteger != 0);
    v17 = pathOptimizationTravelFlags;
    if ( pathOptimizationTravelFlags == 0 )
      v17 = 62;
    v18 = globalTravelFlags;
    if ( globalTravelFlags == 0 )
      v18 = -2;
    ((void (__fastcall *)(idAAS2Local *, int, const idVec3 *, int, idVec3 *, int, int, int))this->ShowWalkPath)(
      a1: this,
      a2: v15,
      a3: origin,
      a4: v21,
      a5: &v22,
      a6: v18,
      a7: v17,
      a8: passEntityNum);
    v20[0].x = 0.0;
    v20[0].y = 0.0;
    v20[0].z = 1.0;
    idAAS2Local::DrawCone(
      this,
      origin: &v22,
      dir: v20,
      radius: 16.0,
      color: v19,
      a6: (const idVec4 *)&idColor::colorWhite);
  }
  idAAS2Callback_FindFlaggedArea::~idAAS2Callback_FindFlaggedArea(this: v23);
}


// ========================================================================
// __unwind$252742
// EA  : 0x826AE3F0
// RVA : 0x006AE3F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_252742()
{
  int v0; // r12

  idAAS2Callback_FindFlaggedArea::~idAAS2Callback_FindFlaggedArea(this: (idAAS2Callback_FindFlaggedArea *)(v0 - 288 + 144));
}


// ========================================================================
// ?PullPlayer@idAAS2Local@@ABA_NABVidVec3@@H0HHHHHAAH1AAVusercmd_t@@AAVidAngles@@@Z
// EA  : 0x826AE418
// RVA : 0x006AE418
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

int __fastcall idAAS2Local::PullPlayer(
        idAAS2Local *this,
        const idVec3 *origin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        const int travelFlags,
        const int pathOptimizationTravelFlags,
        const int passEntityNum,
        int time,
        const int gameMsPerFrame,
        int *startAreaNum,
        int *travelTime,
        usercmd_t *usercmd,
        idAngles *viewAngles,
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
        int a29,
        int *a30,
        int a31,
        _DWORD *a32,
        int a33,
        int a34,
        int a35,
        idAngles *gameMsPerFramea)
{
  double v42; // fp9
  float y; // r9
  float z; // r8
  idAAS2Local_vtbl *v45; // r21
  int valueInteger; // r28
  int v47; // r20
  idBounds *v48; // r3
  int v49; // r3
  obstacleVertex_t *VertexArray; // r28
  obstacleEdge_t *EdgeArray; // r27
  int MaxEdges; // r3
  idAAS2Local_vtbl *v53; // r6
  int v54; // r27
  _BYTE *v55; // r28
  int v56; // r29
  double v57; // fp31
  double v58; // fp30
  float *p_x; // r30
  double v60; // fp10
  double v61; // fp8
  int type; // r11
  double v65; // fp2
  double v66; // fp4
  double v67; // fp2
  obstacleTraceSet_t *v68; // [sp+8h] [-15A8h]
  float x; // [sp+78h] [-1538h] BYREF
  float v70; // [sp+7Ch] [-1534h]
  float v71; // [sp+80h] [-1530h]
  int v72; // [sp+84h] [-152Ch] BYREF
  int MaxVertices; // [sp+88h] [-1528h] BYREF
  idAngles v74; // [sp+90h] [-1520h] BYREF
  idVec3 v75; // [sp+A0h] [-1510h] BYREF
  idBox v76; // [sp+C0h] [-14F0h] BYREF
  idAAS2Path v77; // [sp+100h] [-14B0h] BYREF
  obstaclePath_t v78; // [sp+2C0h] [-12F0h] BYREF
  _BYTE v79[128]; // [sp+530h] [-1080h] BYREF

  *a30 = 0;
  *a32 = 0;
  if ( goalAreaNum == 0 )
    return 0;
  v42 = (float)(goalOrigin->y - origin->y);
  if ( __fsqrts((float)((float)((float)v42 * (float)v42)
                      + (float)((float)(goalOrigin->x - origin->x) * (float)(goalOrigin->x - origin->x)))) < 32.0
    && __fabs((float)(goalOrigin->z - origin->z)) < 128.0 )
  {
    return 0;
  }
  y = origin->y;
  z = origin->z;
  v45 = this->__vftable;
  x = origin->x;
  v70 = y;
  v71 = z;
  valueInteger = aas_tree.valueInteger;
  v47 = v45->GetInvalidTravelFlags(this);
  v48 = this->DefaultSearchBounds(this: &v75, result: this);
  v49 = v45->PointReachableAreaNum(
          this,
          a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
          a3: (const idVec3 *)&x,
          a4: v48,
          a5: 2,
          a6: v47);
  *a30 = v49;
  this->PushPointIntoAreaNum(this, a2: v49, a3: (idVec3 *)&x);
  idAAS2Path::idAAS2Path(this: &v77);
  if ( ((unsigned __int8 (__fastcall *)(idAAS2Local *, idAAS2Path *, int, float *, int, const idVec3 *))this->WalkPathToGoal)(
         a1: this,
         a2: &v77,
         a3: *a30,
         a4: &x,
         a5: goalAreaNum,
         a6: goalOrigin) == 0 )
    return 0;
  idCVar::SetInteger(this: &aas_useObstacleAvoidanceJobs, newValue: 0, force: true);
  idObstacleAvoidance::AllocBuffers(this: &this->obstacleAvoidance);
  VertexArray = idObstacleAvoidance::GetVertexArray(this: &this->obstacleAvoidance);
  EdgeArray = idObstacleAvoidance::GetEdgeArray(this: &this->obstacleAvoidance);
  MaxVertices = idObstacleAvoidance::GetMaxVertices(this: &this->obstacleAvoidance);
  MaxEdges = idObstacleAvoidance::GetMaxEdges(this: &this->obstacleAvoidance);
  v53 = this->__vftable;
  v72 = MaxEdges;
  ((void (__fastcall *)(idAAS2Local *, int, int, obstacleVertex_t *, int *, obstacleEdge_t *, int *, _BYTE *))v53->GetObstaclePVSObstacles)(
    a1: this,
    a2: *a30,
    a3: 515,
    a4: VertexArray,
    a5: &MaxVertices,
    a6: EdgeArray,
    a7: &v72,
    a8: v79);
  idObstacleAvoidance::SetNumVertices(this: &this->obstacleAvoidance, num: MaxVertices);
  idObstacleAvoidance::SetNumEdges(this: &this->obstacleAvoidance, num: v72);
  v54 = 0;
  v55 = v79;
  do
  {
    v56 = *(_DWORD *)v55;
    if ( *(_DWORD *)(*(_DWORD *)v55 + 12) != passEntityNum )
    {
      idBox::idBox(
        this: &v76,
        bounds: (const idBounds *)(v56 + 80),
        origin: (const idVec3 *)(v56 + 32),
        axis: (const idMat3 *)(v56 + 44));
      idObstacleAvoidance::AddObstacle(
        this: &this->obstacleAvoidance,
        box: &v76,
        id: *(const idSpawnId **)(v56 + 16),
        soft: false);
    }
    ++v54;
    v55 += 4;
  }
  while ( v54 < 1024 );
  obstaclePath_t::obstaclePath_t(this: &v78);
  idObstacleAvoidance::FindPathAroundObstacles(
    this: &this->obstacleAvoidance,
    path: &v78,
    time,
    gameMsPerFrame: a28,
    bbox: &this->file->settings.boundingBox,
    gravity: &this->file->settings.gravityDir,
    obstacleRadius: this->file->settings.obstaclePVSRadius,
    frameMoveDist: 32.0,
    cornerCircleRadius: 16.0,
    flags: (const int)&v77.obstacleRoute,
    route: (const obstacleRoute_t *)&off_82230000,
    traceSet: v68);
  v57 = v70;
  v58 = x;
  p_x = &v78.seekPos[(float)((float)((float)(x * v78.seekPosPlane.a)
                                   + (float)((float)(v78.seekPosPlane.b * v70) + (float)(v78.seekPosPlane.c * v71)))
                           + v78.seekPosPlane.d) > -0.0099999998].x;
  memset(Dst: (void *)a34, Val: 0, Size: 0x3Cu);
  v60 = (float)(p_x[1] - (float)v57);
  v61 = (float)(*p_x - (float)v58);
  type = v77.type;
  *(_BYTE *)(a34 + 6) = 96;
  *(_DWORD *)(a34 + 16) = 1;
  _FP5 = (float)((float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f5, f6, f13 }
  v65 = __frsqrte(_FP4);
  v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65
                                                                                      * (float)((float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))
                                                                                              * (float)0.5))
                                                                              * (float)v65)
                                                                      - (float)1.5)
                                                      * (float)v65)
                                              * (float)((float)((float)((float)v61 * (float)v61)
                                                              + (float)((float)v60 * (float)v60))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v65
                                                                              * (float)((float)((float)((float)v61 * (float)v61)
                                                                                              + (float)((float)v60 * (float)v60))
                                                                                      * (float)0.5))
                                                                      * (float)v65)
                                                              - (float)1.5)
                                              * (float)v65))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v65
                                                      * (float)((float)((float)((float)v61 * (float)v61)
                                                                      + (float)((float)v60 * (float)v60))
                                                              * (float)0.5))
                                              * (float)v65)
                                      - (float)1.5)
                      * (float)v65));
  v67 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                      * (float)v65)
                                                                              * (float)((float)((float)((float)v61 * (float)v61)
                                                                                              + (float)((float)v60 * (float)v60))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)) * (float)0.5)) * (float)v65)
                                                                                              - (float)1.5)
                                                                              * (float)v65))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v65
                                                                                      * (float)((float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))
                                                                                              * (float)0.5))
                                                                              * (float)v65)
                                                                      - (float)1.5)
                                                      * (float)v65))
                                      * (float)((float)((float)((float)v61 * (float)v61)
                                                      + (float)((float)v60 * (float)v60))
                                              * (float)0.5))
                              * (float)v66)
                      - (float)1.5);
  v74.pitch = (float)((float)v67 * (float)v66) * (float)v61;
  v74.yaw = (float)((float)v67 * (float)v66) * (float)v60;
  v74.roll = (float)((float)v67 * (float)v66) * (float)0.0;
  if ( type > 0
    && type <= 2
    && (float)((float)((float)v67 * (float)v66)
             * (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) < 80.0 )
  {
    LODWORD(v75.y) = (int)(float)((float)((float)((float)v67 * (float)v66)
                                        * (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                                + (float)16.0);
    *(_BYTE *)(a34 + 6) = LOBYTE(v75.y);
  }
  *gameMsPerFramea = *idVec3::ToAngles(this: &v75, result: &v74);
  return 1;
}


// ========================================================================
// ?RandomPullPlayer@idAAS2Local@@ABAXABVidVec3@@HHHHHHAAVusercmd_t@@AAVidAngles@@@Z
// EA  : 0x826AE8B8
// RVA : 0x006AE8B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::RandomPullPlayer(
        idAAS2Local *this,
        const idVec3 *origin,
        int mode,
        int travelFlags,
        int pathOptimizationTravelFlags,
        int passEntityNum,
        int time,
        int ticksPerSec,
        usercmd_t *usercmd,
        idAngles *viewAngles,
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
        int a29,
        idAngles *a30)
{
  idVec3 *(__fastcall *AreaCenter)(struct idAAS2Local *, idVec3 *, int); // ctr
  const idVec3 *v39; // r3
  int v40; // r8
  int v41; // r6
  int v42; // r4
  idAAS2File *file; // r5
  __int64 v44; // r10
  int num; // r11
  int v46; // r30
  int v47; // r5
  idAAS2File *v48; // r7
  int i; // ctr
  signed int v50; // r31
  int v51; // [sp+8h] [-F8h]
  int *v52; // [sp+Ch] [-F4h]
  int *v53; // [sp+10h] [-F0h]
  usercmd_t *v54; // [sp+14h] [-ECh]
  idAngles *v55; // [sp+18h] [-E8h]
  int v56; // [sp+1Ch] [-E4h]
  int v57; // [sp+20h] [-E0h]
  int v58; // [sp+24h] [-DCh]
  int v59; // [sp+28h] [-D8h]
  int v60; // [sp+2Ch] [-D4h]
  int v61; // [sp+30h] [-D0h]
  int v62; // [sp+34h] [-CCh]
  int v63; // [sp+38h] [-C8h]
  int v64; // [sp+3Ch] [-C4h]
  int v65; // [sp+40h] [-C0h]
  int v66; // [sp+44h] [-BCh]
  int v67; // [sp+48h] [-B8h]
  int v68; // [sp+4Ch] [-B4h]
  int v69; // [sp+50h] [-B0h]
  int v70; // [sp+58h] [-A8h]
  int v71; // [sp+60h] [-A0h]
  int v72; // [sp+68h] [-98h]
  int v73; // [sp+70h] [-90h]
  int v74; // [sp+80h] [-80h] BYREF
  int v75; // [sp+88h] [-78h] BYREF
  int v76; // [sp+8Ch] [-74h]
  _BYTE v77[112]; // [sp+90h] [-70h] BYREF

  if ( (_S13_6 & 1) == 0 )
  {
    random_0.seed = 0;
    _S13_6 |= 1u;
  }
  AreaCenter = this->AreaCenter;
  goalAreaNum = __CFADD__(this->file->areas.num - goalAreaNum, goalAreaNum ^ 0x80000000) ? 0 : goalAreaNum;
  v39 = (const idVec3 *)((int (__fastcall *)(_BYTE *, idAAS2Local *))AreaCenter)(a1: v77, a2: this);
  v40 = (unsigned __int8)idAAS2Local::PullPlayer(
                           this,
                           origin,
                           goalAreaNum: goalAreaNum,
                           goalOrigin: v39,
                           travelFlags,
                           pathOptimizationTravelFlags,
                           passEntityNum,
                           time,
                           gameMsPerFrame: v51,
                           startAreaNum: v52,
                           travelTime: v53,
                           usercmd: v54,
                           viewAngles: v55,
                           a14: v56,
                           a15: v57,
                           a16: v58,
                           a17: v59,
                           a18: v60,
                           a19: v61,
                           a20: v62,
                           a21: v63,
                           a22: v64,
                           a23: v65,
                           a24: v66,
                           a25: v67,
                           a26: v68,
                           a27: v69,
                           a28: ticksPerSec,
                           a29: v70,
                           a30: &v75,
                           a31: v71,
                           a32: &v74,
                           a33: v72,
                           a34: a28,
                           a35: v73,
                           gameMsPerFramea: a30);
  v41 = v75;
  if ( v40 != 0 )
  {
    v47 = goalAreaNum;
    v42 = startAreaNum;
    if ( startAreaNum == 0 )
    {
      v42 = v75;
      startAreaNum = v75;
      bestTravelTime = v74;
      goto LABEL_12;
    }
    v46 = bestTravelTime;
  }
  else
  {
    v42 = 0;
    random_0.seed = 1103515245 * random_0.seed + 12345;
    file = this->file;
    v44 = HIWORD(random_0.seed) & 0x7FFF;
    startAreaNum = 0;
    num = file->areas.num;
    v46 = 0x7FFFFFFF;
    v47 = goalAreaNum;
    bestTravelTime = 0x7FFFFFFF;
    v76 = (int)(float)((float)((float)v44 * (float)__SPAIR64__("_AI_OBSTACLE", num)) * (float)0.000030518509);
    if ( num > 0 )
    {
      v48 = this->file;
      for ( i = num; i != 0; --i )
      {
        v50 = v48->areas.num;
        __twllei(v50, 0);
        __twlgei(v50 & ~(__ROL4__(HIDWORD(v44) + v76, 1) - 1), 0xFFFFFFFF);
        if ( (v48->areas.list[(HIDWORD(v44) + v76) % v50].flags & 2) != 0 )
          v47 = (HIDWORD(v44) + v76) % v50;
        ++HIDWORD(v44);
      }
      goalAreaNum = v47;
    }
  }
  if ( v74 < v46 )
  {
    bestTravelTime = v74;
    failedCount = 0;
    return;
  }
LABEL_12:
  if ( ++failedCount > 303 )
  {
    failedCount = 0;
    if ( mode > 1 )
    {
      idLib::Warning(fmt: "failed to go from area %d to area %d at area %d", v42, v47, v41);
      goalAreaNum = 0;
    }
  }
}


// ========================================================================
// ?ShowManualReachabilities@idAAS2Local@@ABAXXZ
// EA  : 0x826AEB38
// RVA : 0x006AEB38
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowManualReachabilities(idAAS2Local *this)
{
  int v2; // r28
  int v3; // r29
  idAAS2File *file; // r4
  const char *name; // r30
  unsigned __int16 v6; // [sp+50h] [-30h] BYREF

  v2 = 0;
  if ( this->file->reachabilityNames.num > 0 )
  {
    v3 = 0;
    do
    {
      file = this->file;
      name = file->reachabilityNames.list[v3].name;
      idAAS2File::FindReachabilityByName(
        this: (idAAS2File *)&v6,
        result: (idIndex<short,enum invalidReachability_t> *)file,
        name);
      if ( (v6 & 0x8000u) == 0 )
        this->DrawReachability(
          this,
          a2: (const idIndex<short,enum invalidReachability_t> *)v6,
          a3: &this->file->reachabilities.list[(__int16)v6],
          a4: name);
      ++v2;
      ++v3;
    }
    while ( v2 < this->file->reachabilityNames.num );
  }
}


// ========================================================================
// ?ShowTraversals@idAAS2Local@@ABAXABVidVec3@@@Z
// EA  : 0x826AEBD0
// RVA : 0x006AEBD0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowTraversals(
        idAAS2Local *this,
        const idVec3 *testOrigin,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  idAAS2File *file; // r10
  int v9; // r28
  int v10; // r30
  unsigned int valueInteger; // r11
  const aas2Traversal_t *v12; // r4
  double v13; // fp11
  double v14; // fp9
  double v15; // fp11
  double v16; // fp2
  double v17; // fp9
  double v18; // fp7
  double v19; // fp5

  file = this->file;
  v9 = 1;
  if ( file->traversalPoints.num > 1 )
  {
    v10 = 1;
    valueInteger = aas_showTraversals.valueInteger;
    do
    {
      v12 = &file->traversalPoints.list[v10];
      if ( valueInteger == -1 )
        goto LABEL_6;
      v13 = (float)(testOrigin->y - v12->startPoint.y);
      v14 = (float)(testOrigin->z - v12->startPoint.z);
      LODWORD(a6) = valueInteger * valueInteger;
      v16 = (float)((float)((float)(testOrigin->x - v12->startPoint.x) * (float)(testOrigin->x - v12->startPoint.x))
                  + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
      v15 = (float)a6;
      if ( v16 < v15
        || (v17 = (float)(testOrigin->y - v12->endPoint.y),
            v18 = (float)(testOrigin->z - v12->endPoint.z),
            (float)((float)((float)(v19 = (float)(testOrigin->x - v12->endPoint.x)) * (float)v19)
                  + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) < v15) )
      {
LABEL_6:
        idAAS2Local::DrawTraversal(this, traversal: v12, depthTest: ((valueInteger >> 31) + (valueInteger == -1)) & 1);
        valueInteger = aas_showTraversals.valueInteger;
      }
      file = this->file;
      ++v9;
      ++v10;
    }
    while ( v9 < file->traversalPoints.num );
  }
}


// ========================================================================
// ?GetAreaNumAndLocation@idAAS2Local@@ABA_NAAVidCVar@@ABVidVec3@@AAHAAV3@@Z
// EA  : 0x826AECE0
// RVA : 0x006AECE0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAreaNumAndLocation(
        idAAS2Local *this,
        idCVar *cvar,
        idAngles *origin,
        int *areaNum,
        idVec3 *location)
{
  char *data; // r3
  int v11; // r10
  idAAS2Local_vtbl *v12; // r11
  int (__fastcall *GetInvalidTravelFlags)(struct idAAS2Local *); // r8
  idAAS2Local_vtbl *v14; // r25
  int valueInteger; // r28
  int v16; // r24
  idBounds *v17; // r3
  int v18; // r3
  const char *v20; // r3
  char *v21; // r4
  unsigned int v22; // r5
  double v23; // fp1
  BOOL v24; // r9
  idAAS2Local_vtbl *v25; // r25
  int v26; // r28
  int v27; // r24
  idBounds *v28; // r3
  int v29; // r3
  int v30; // r3
  idVec3 *v31; // r3
  bool v32; // [sp+50h] [-100h] BYREF
  char *v33; // [sp+54h] [-FCh]
  _BYTE v34[32]; // [sp+60h] [-F0h] BYREF
  idLexer v35; // [sp+80h] [-D0h] BYREF

  *areaNum = 0;
  data = cvar->valueString.data;
  location->x = 0.0;
  location->z = 0.0;
  location->y = 0.0;
  v11 = (unsigned __int8)*data;
  v33 = data;
  if ( v11 != 0 )
  {
    v33 = data;
    if ( idStr::Icmp(s1: data, s2: "memory") == 0 )
      idCVar::SetString(this: cvar, newValue: aas_locationMemory.valueString.data, force: true);
    if ( idStr::Icmp(s1: cvar->valueString.data, s2: "player") == 0 )
    {
      v12 = this->__vftable;
      location->x = origin->pitch;
      location->y = origin->yaw;
      GetInvalidTravelFlags = v12->GetInvalidTravelFlags;
      location->z = origin->roll;
      v14 = v12;
      valueInteger = aas_tree.valueInteger;
      v16 = GetInvalidTravelFlags(this);
      v17 = this->DefaultSearchBounds(this: v34, result: this);
      v18 = v14->PointReachableAreaNum(
              this,
              a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
              a3: location,
              a4: v17,
              a5: 2,
              a6: v16);
      *areaNum = v18;
      this->PushPointIntoAreaNum(this, a2: v18, a3: location);
      return 1;
    }
    if ( idStr::Icmp(s1: cvar->valueString.data, s2: "current") == 0 )
    {
      v20 = idVec3::ToString(this: origin, precision: 2);
      idCVar::SetString(this: cvar, newValue: v20, force: true);
    }
    idLexer::idLexer(this: &v35, flags_: 3);
    v21 = cvar->valueString.data;
    v22 = 0;
    if ( *v21 != 0 )
    {
      do
        ++v22;
      while ( v21[v22] != 0 );
    }
    v33 = cvar->valueString.data;
    idLexer::LoadMemory(this: &v35, ptr: v21, length_: v22, name: "areaNum");
    v32 = false;
    location->x = idLexer::ParseFloat(this: &v35, errorFlag: &v32);
    location->y = idLexer::ParseFloat(this: &v35, errorFlag: &v32);
    v23 = idLexer::ParseFloat(this: &v35, errorFlag: &v32);
    v24 = v32;
    location->z = v23;
    if ( !v24 )
    {
      v25 = this->__vftable;
      v26 = aas_tree.valueInteger;
      v27 = this->GetInvalidTravelFlags(this);
      v28 = this->DefaultSearchBounds(this: v34, result: this);
      v29 = v25->PointReachableAreaNum(
              this,
              a2: (idIndex<int,enum invalidAASTree_t> *)v26,
              a3: location,
              a4: v28,
              a5: 2,
              a6: v27);
      *areaNum = v29;
      this->PushPointIntoAreaNum(this, a2: v29, a3: location);
      idLexer::~idLexer(this: &v35);
      return 1;
    }
    idLexer::Reset(this: &v35);
    v30 = idLexer::ParseInt(this: &v35);
    *areaNum = v30;
    if ( v30 > 0 && v30 < this->file->areas.num )
    {
      v31 = this->AreaCenter(this: v34, result: this, a3: v30);
      location->x = v31->x;
      location->y = v31->y;
      location->z = v31->z;
      idLexer::~idLexer(this: &v35);
      return 1;
    }
    idLexer::~idLexer(this: &v35);
  }
  return 0;
}


// ========================================================================
// __unwind$253176
// EA  : 0x826AEFF8
// RVA : 0x006AEFF8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_253176()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 336 + 128));
}


// ========================================================================
// ?ShowCover@idAAS2Local@@ABAXABVidVec3@@@Z
// EA  : 0x826AF020
// RVA : 0x006AF020
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowCover(idAAS2Local *this, const idVec3 *origin)
{
  idAAS2Local_vtbl *v2; // r25
  int valueInteger; // r30
  int v6; // r28
  idBounds *v7; // r3
  int v8; // r4
  idAAS2File *file; // r11
  int v10; // r30
  int v11; // r29
  __int64 v12; // r11
  int v13; // r30
  int *v14; // r29
  int v15; // [sp+60h] [-1070h] BYREF
  __int64 v16; // [sp+68h] [-1068h]
  _BYTE v17[28]; // [sp+70h] [-1060h] BYREF
  int v18; // [sp+8Ch] [-1044h] BYREF
  _BYTE v19[64]; // [sp+90h] [-1040h] BYREF

  v2 = this->__vftable;
  valueInteger = aas_showCover.valueInteger;
  v6 = aas_tree.valueInteger;
  v7 = this->DefaultSearchBounds(this: v17, result: this);
  v8 = v2->PointReachableAreaNum(this, a2: (idIndex<int,enum invalidAASTree_t> *)v6, a3: origin, a4: v7, a5: 2, a6: 1);
  v15 = 0;
  if ( valueInteger >= 0 )
  {
    if ( valueInteger > 0 )
    {
      if ( valueInteger == 1 )
      {
        this->GetAreaCoverPoints(this, a2: v8, a3: (int *)v19, a4: 1024, a5: &v15);
      }
      else
      {
        LODWORD(v12) = valueInteger;
        HIDWORD(v12) = this->__vftable;
        v16 = v12;
        (*(void (__fastcall **)(idAAS2Local *, int, const idVec3 *, _DWORD, int, _DWORD, int, _BYTE *, double))(HIDWORD(v12) + 276))(
          a1: this,
          a2: v8,
          a3: origin,
          a4: *(_DWORD *)(HIDWORD(v12) + 276),
          a5: 0x7FFFFFFF,
          a6: 0,
          a7: 0x7FFFFFFF,
          a8: v19,
          a9: (float)v12);
      }
      v13 = 0;
      if ( v15 > 0 )
      {
        v14 = &v18;
        do
        {
          ((void (__fastcall *)(idAAS2Local *, aas2Cover_t *))this->DrawCoverPoint)(
            a1: this,
            a2: &this->file->cover.list[*++v14]);
          ++v13;
        }
        while ( v13 < v15 );
      }
    }
  }
  else
  {
    file = this->file;
    v10 = 1;
    if ( file->cover.num > 1 )
    {
      v11 = 1;
      do
      {
        this->DrawCoverPoint(this, a2: &file->cover.list[v11], a3: v10);
        file = this->file;
        ++v10;
        ++v11;
      }
      while ( v10 < file->cover.num );
    }
  }
}


// ========================================================================
// ?FloodFindAreasInRadius_r@idAAS2Local@@ABAXABVidVec3@@HMAAVidBitArray@@AAV?$idList@H$04@@@Z
// EA  : 0x826AF340
// RVA : 0x006AF340
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::FloodFindAreasInRadius_r(
        idAAS2Local *this,
        const idVec3 *origin,
        unsigned int areaNum,
        double distSqr,
        idBitArray *visitedAreas,
        idList<int,5> *foundAreas,
        idList<enum encounterGroupRole_t,5> *a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        unsigned int a17)
{
  unsigned int num; // r11
  _BYTE *v23; // r11
  char v24; // r10
  char v25; // r9
  const idIndex<short,enum invalidReachability_t> *i; // r31
  __int64 v27; // r4
  __int64 v28; // r6
  _BYTE *v29; // r11
  char v30; // r10
  char v31; // r9
  __int64 v33; // r11
  double v34; // fp1
  double v35; // fp3
  double v36; // fp13

  num = foundAreas->num;
  a17 = areaNum;
  if ( areaNum >= num )
  {
    v23 = nullptr;
    v24 = 0;
    v25 = 0;
  }
  else
  {
    v23 = (char *)foundAreas->list + (areaNum >> 3);
    v24 = 1 << (areaNum & 7);
    v25 = 1;
  }
  if ( v25 != 0 )
    *v23 |= v24;
  idList<idAnimWebBlendTree *,5>::Append(this: a7, obj: (const encounterGroupRole_t *)&a17);
  for ( i = (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)this->file->areas.list[areaNum].reach.value;
        (__int16)i >= 0;
        i = (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)this->GetReachability(this, a2: i)->next.value )
  {
    HIDWORD(v27) = this->GetReachability(this, a2: i);
    HIDWORD(v28) = *(unsigned __int16 *)(HIDWORD(v27) + 8);
    if ( HIDWORD(v28) >= foundAreas->num )
    {
      v29 = nullptr;
      v30 = 0;
      v31 = 0;
    }
    else
    {
      v29 = (char *)foundAreas->list + (HIDWORD(v28) >> 3);
      v30 = 1 << (BYTE3(v28) & 7);
      v31 = 1;
    }
    if ( v31 == 0 || (unsigned __int8)(*v29 & v30) == 0 )
    {
      LODWORD(v28) = *(__int16 *)(HIDWORD(v27) + 18);
      HIDWORD(v33) = *(unsigned __int16 *)(HIDWORD(v27) + 20);
      LODWORD(v33) = *(__int16 *)(HIDWORD(v27) + 22);
      LODWORD(v27) = SWORD1(v33);
      v34 = (float)((float)v28 - origin->x);
      v35 = (float)((float)v33 - origin->z);
      v36 = (float)((float)v27 - origin->y);
      if ( (float)((float)((float)v36 * (float)v36)
                 + (float)((float)((float)v34 * (float)v34) + (float)((float)v35 * (float)v35))) <= distSqr )
        idAAS2Local::FloodFindAreasInRadius_r(
          this,
          origin,
          areaNum: SHIDWORD(v28),
          distSqr,
          visitedAreas: (idBitArray *)v28,
          foundAreas);
    }
  }
}


// ========================================================================
// ?ShowAreas@idAAS2Local@@ABAXABVidVec3@@H@Z
// EA  : 0x826AF548
// RVA : 0x006AF548
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowAreas(idAAS2Local *this, const idVec3 *origin, int mode)
{
  float y; // r10
  float z; // r9
  idAAS2Local_vtbl *v8; // r27
  int valueInteger; // r29
  int v10; // r24
  idBounds *v11; // r3
  int v12; // r3
  idAAS2Local_vtbl *v13; // r10
  unsigned int v14; // r28
  int (__fastcall *PointAreaNum)(struct idAAS2Local *, idIndex<int,enum invalidAASTree_t> *__struct_ptr, const idVec3 *); // ctr
  int v16; // r29
  idAAS2Local_vtbl *v17; // r27
  int v18; // r3
  aas2Reachability_t *v19; // r29
  aas2Area_t *v20; // r29
  char v21; // r11
  __int16 *p_granularity; // r10
  char *v23; // r11
  int i; // ctr
  idRenderWorld *v25; // r3
  idRenderWorld *v26; // r3
  unsigned int v27; // r5
  int v28; // r12
  idAAS2File *file; // r8
  __int64 v30; // r6
  int v31; // r10
  int v32; // r9
  _DWORD back_chain[20]; // [sp+0h] [-100h]
  __int16 v34; // [sp+50h] [-B0h] BYREF
  unsigned int v35; // [sp+54h] [-ACh] BYREF
  __int64 v36; // [sp+58h] [-A8h] BYREF
  float x; // [sp+60h] [-A0h] BYREF
  float v38; // [sp+64h] [-9Ch]
  float v39; // [sp+68h] [-98h]
  idList<int,5> v40[2]; // [sp+70h] [-90h] BYREF
  idList<int,5> v41; // [sp+90h] [-70h] BYREF
  float v42[24]; // [sp+A0h] [-60h] BYREF

  y = origin->y;
  z = origin->z;
  x = origin->x;
  v38 = y;
  v39 = z;
  if ( mode == 2 )
  {
    PointAreaNum = this->PointAreaNum;
    HIDWORD(v36) = aas_tree.valueInteger;
    v14 = ((int (__fastcall *)(idAAS2Local *))PointAreaNum)(a1: this);
    v35 = v14;
  }
  else
  {
    v8 = this->__vftable;
    valueInteger = aas_tree.valueInteger;
    v10 = this->GetInvalidTravelFlags(this);
    v11 = this->DefaultSearchBounds(this: v40, result: this);
    v12 = v8->PointReachableAreaNum(
            this,
            a2: (idIndex<int,enum invalidAASTree_t> *)valueInteger,
            a3: origin,
            a4: v11,
            a5: 2,
            a6: v10);
    v13 = this->__vftable;
    v14 = v12;
    v35 = v12;
    v13->PushPointIntoAreaNum(this, a2: v12, a3: (idVec3 *)&x);
  }
  if ( v14 != 0 )
  {
    v16 = aas_showTravelTime.valueInteger;
    if ( aas_showTravelTime.valueInteger != 0 )
    {
      v17 = this->__vftable;
      v34 = -1;
      v18 = (int)v17->AreaCenter(
                   this: (struct idAAS2Local *)v40,
                   result: (idVec3 *)this,
                   a3: aas_showTravelTime.valueInteger);
      v17->RouteToGoalArea(
        this,
        a2: v14,
        a3: (const idVec3 *)&x,
        a4: v16,
        a5: (const idVec3 *)v18,
        a6: 40,
        a7: (int *)&v36,
        a8: (idIndex<short,enum invalidReachability_t> *)&v34);
      idLib::Printf(fmt: "\rtt = %4d", HIDWORD(v36));
      if ( v34 >= 0 )
      {
        v19 = &this->file->reachabilities.list[v34];
        idLib::Printf(fmt: " to area %4d", v19->toAreaNum);
        this->DrawArea(
          this,
          a2: v19->toAreaNum,
          a3: aas_drawReaches.valueInteger != 0,
          a4: aas_drawAreaNums.valueInteger != 0,
          a5: aas_drawClusterNums.valueInteger != 0,
          a6: aas_drawNormals.valueInteger != 0,
          a7: aas_drawAreaFilled.valueInteger != 0,
          a8: aas_drawAreaOutline.valueInteger != 0);
      }
    }
    if ( v14 != lastAreaNum )
    {
      v20 = &this->file->areas.list[v14];
      idLib::Printf(fmt: "area %d / %d:", v14, v20->cluster);
      if ( (v20->flags & 1) != 0 )
        idLib::Printf(fmt: " ledge");
      if ( (v20->flags & 0x400) != 0 )
        idLib::Printf(fmt: " clusterportal");
      if ( (v20->flags & 0x800) != 0 )
        idLib::Printf(fmt: " obstacle");
      if ( (v20->flags & 4) != 0 )
        idLib::Printf(fmt: " outside");
      if ( (v20->flags & 8) != 0 )
        idLib::Printf(fmt: " highceiling");
      if ( (v20->travelFlags & 7) != 0 )
      {
        idLib::Printf(fmt: " /");
        if ( (v20->travelFlags & 1) != 0 )
          idLib::Printf(fmt: " invalid");
        if ( (v20->travelFlags & 2) != 0 )
          idLib::Printf(fmt: " invalidteam1");
        if ( (v20->travelFlags & 4) != 0 )
          idLib::Printf(fmt: " invalidteam2");
      }
      idLib::Printf(fmt: "\n");
      lastAreaNum = v14;
    }
    if ( x != origin->x || v38 != origin->y || (v21 = 1, v39 != origin->z) )
      v21 = 0;
    if ( v21 == 0 )
    {
      p_granularity = &v41.granularity;
      v23 = &this->file->settings.explicitGroupName.baseBuffer[16];
      for ( i = 6; i != 0; --i )
      {
        v23 += 4;
        p_granularity += 2;
        *(_DWORD *)p_granularity = *(_DWORD *)v23;
      }
      v42[5] = v42[2];
      v25 = common->RW(this: common);
      v25->DebugBounds(
        this: v25,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: (const idBounds *)v42,
        a4: (const idVec3 *)&x,
        a5: 0,
        a6: false);
      v26 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))v26->DebugArrow)(
        a1: v26,
        a2: &idColor::colorYellow,
        a3: origin,
        a4: &x,
        a5: 1.0);
    }
    memset(&v41, 0, 14);
    *(_WORD *)&v41.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
    if ( mode <= 2 )
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&v41,
        obj: (const encounterGroupRole_t *)&v35);
    }
    else
    {
      HIDWORD(v36) = this->file->areas.num;
      ((void (*)(void))RtlCheckStack12)();
      HIDWORD(v36) = v27;
      *(_DWORD *)((char *)back_chain + v28) = back_chain[0];
      idBitArray::idBitArray(this: (idBitArray *)v40, buff: (unsigned __int8 *)&v34, bits: v27, _memTag: TAG_TEMP);
      file = this->file;
      HIDWORD(v36) = 6;
      idList<int,5>::PreAllocate(this: &v41, newSize: file->areas.num, initValue: (const int *)&v36);
      LODWORD(v30) = mode * mode;
      v36 = v30;
      idAAS2Local::FloodFindAreasInRadius_r(
        this,
        origin,
        areaNum: v14,
        distSqr: (float)v30,
        visitedAreas: (idBitArray *)(mode * mode),
        foundAreas: v40,
        a7: (idList<enum encounterGroupRole_t,5> *)&v41,
        a8: v32,
        a9: v31,
        a10: back_chain[2],
        a11: back_chain[3],
        a12: back_chain[4],
        a13: back_chain[5],
        a14: back_chain[6],
        a15: back_chain[7],
        a16: back_chain[8],
        a17: back_chain[9]);
      idBitArray::~idBitArray(this: (idBitArray *)v40);
    }
    idAAS2Local::DrawAreaList(this, areaList: &v41);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
  }
}


// ========================================================================
// __unwind$253811
// EA  : 0x826AFAA8
// RVA : 0x006AFAA8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_253811()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$253812
// EA  : 0x826AFAD0
// RVA : 0x006AFAD0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_253812()
{
  int v0; // r12

  idBitArray::~idBitArray(this: (idBitArray *)(v0 - 256 + 112));
}


// ========================================================================
// ?FloodFindAreasByCluster_r@idAAS2Local@@ABAXABVidVec3@@HHAAVidBitArray@@AAV?$idList@H$04@@@Z
// EA  : 0x826AFAF8
// RVA : 0x006AFAF8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::FloodFindAreasByCluster_r(
        idAAS2Local *this,
        const idVec3 *origin,
        unsigned int areaNum,
        int clusterNum,
        idBitArray *visitedAreas,
        idList<enum encounterGroupRole_t,5> *foundAreas,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        unsigned int a16)
{
  unsigned int bits; // r11
  unsigned __int8 *v22; // r11
  char v23; // r10
  char v24; // r9
  aas2Area_t *v25; // r31
  const idIndex<short,enum invalidReachability_t> *i; // r31
  unsigned int toAreaNum; // r5
  unsigned __int8 *v28; // r11
  char v29; // r10
  char v30; // r9

  bits = visitedAreas->bits;
  a16 = areaNum;
  if ( areaNum >= bits )
  {
    v22 = nullptr;
    v23 = 0;
    v24 = 0;
  }
  else
  {
    v22 = &visitedAreas->buffer[areaNum >> 3];
    v23 = 1 << (areaNum & 7);
    v24 = 1;
  }
  if ( v24 != 0 )
    *v22 |= v23;
  v25 = &this->file->areas.list[areaNum];
  if ( v25->cluster == clusterNum )
  {
    idList<idAnimWebBlendTree *,5>::Append(this: foundAreas, obj: (const encounterGroupRole_t *)&a16);
    for ( i = (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)v25->reach.value;
          (__int16)i >= 0;
          i = (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)this->GetReachability(this, a2: i)->next.value )
    {
      toAreaNum = this->GetReachability(this, a2: i)->toAreaNum;
      if ( toAreaNum >= visitedAreas->bits )
      {
        v28 = nullptr;
        v29 = 0;
        v30 = 0;
      }
      else
      {
        v28 = &visitedAreas->buffer[toAreaNum >> 3];
        v29 = 1 << (toAreaNum & 7);
        v30 = 1;
      }
      if ( v30 == 0 || (unsigned __int8)(*v28 & v29) == 0 )
        idAAS2Local::FloodFindAreasByCluster_r(
          this,
          origin,
          areaNum: toAreaNum,
          clusterNum,
          visitedAreas,
          (idList<int,5> *)foundAreas);
    }
  }
}


// ========================================================================
// ?ShowAreasByCluster@idAAS2Local@@ABAXABVidVec3@@@Z
// EA  : 0x826AFC90
// RVA : 0x006AFC90
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowAreasByCluster(idAAS2Local *this, const idVec3 *origin)
{
  int valueInteger; // r21
  idAAS2File *v5; // r5
  int v6; // r29
  int v7; // r22
  int (__fastcall *PointAreaNum)(struct idAAS2Local *, idIndex<int,enum invalidAASTree_t> *__struct_ptr, const idVec3 *); // ctr
  int v9; // r3
  unsigned int v10; // r29
  aas2Area_t *v11; // r28
  unsigned int v12; // r5
  int v13; // r12
  int v14; // r10
  idAAS2File *file; // r9
  int v16; // r4
  _DWORD back_chain[20]; // [sp+0h] [-F0h]
  int num; // [sp+50h] [-A0h] BYREF
  idBitArray v19[2]; // [sp+58h] [-98h] BYREF
  idList<enum encounterGroupRole_t,5> v20[8]; // [sp+70h] [-80h] BYREF

  valueInteger = aas_showAreasInCluster.valueInteger;
  if ( aas_showAreasInCluster.valueInteger <= 0 )
  {
    PointAreaNum = this->PointAreaNum;
    num = aas_tree.valueInteger;
    v9 = ((int (__fastcall *)(idAAS2Local *))PointAreaNum)(a1: this);
    v10 = v9;
    if ( v9 != 0 )
    {
      v11 = &this->file->areas.list[v9];
      if ( v9 != lastAreaNum_0 )
      {
        idLib::Printf(fmt: "area %d / %d:", v9, v11->cluster);
        if ( (v11->flags & 1) != 0 )
          idLib::Printf(fmt: " ledge");
        if ( (v11->flags & 0x400) != 0 )
          idLib::Printf(fmt: " clusterportal");
        if ( (v11->flags & 0x800) != 0 )
          idLib::Printf(fmt: " obstacle");
        if ( (v11->flags & 4) != 0 )
          idLib::Printf(fmt: " outside");
        if ( (v11->flags & 8) != 0 )
          idLib::Printf(fmt: " highceiling");
        if ( (v11->travelFlags & 7) != 0 )
        {
          idLib::Printf(fmt: " /");
          if ( (v11->travelFlags & 1) != 0 )
            idLib::Printf(fmt: " invalid");
          if ( (v11->travelFlags & 2) != 0 )
            idLib::Printf(fmt: " invalidteam1");
          if ( (v11->travelFlags & 4) != 0 )
            idLib::Printf(fmt: " invalidteam2");
        }
        idLib::Printf(fmt: "\n");
        lastAreaNum_0 = v10;
      }
      num = this->file->areas.num;
      ((void (*)(void))RtlCheckStack12)();
      num = v12;
      *(_DWORD *)((char *)back_chain + v13) = back_chain[0];
      idBitArray::idBitArray(this: v19, buff: (unsigned __int8 *)&num, bits: v12, _memTag: TAG_TEMP);
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v20);
      file = this->file;
      v16 = file->areas.num;
      if ( v16 > v20[0].size )
        idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v20, newsize: v16);
      idAAS2Local::FloodFindAreasByCluster_r(
        this,
        origin,
        areaNum: v10,
        clusterNum: v11->cluster,
        visitedAreas: v19,
        foundAreas: v20,
        a7: (int)file,
        a8: v14,
        a9: back_chain[2],
        a10: back_chain[3],
        a11: back_chain[4],
        a12: back_chain[5],
        a13: back_chain[6],
        a14: back_chain[7],
        a15: back_chain[8],
        a16: back_chain[9]);
      idAAS2Local::DrawAreaList(this, areaList: (const idList<int,5> *)v20);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v20);
      idBitArray::~idBitArray(this: v19);
    }
  }
  else
  {
    v5 = this->file;
    v6 = 0;
    if ( v5->areas.num > 0 )
    {
      v7 = 0;
      do
      {
        if ( v5->areas.list[v7].cluster == valueInteger )
          this->DrawArea(
            this,
            a2: v6,
            a3: aas_drawReaches.valueInteger != 0,
            a4: aas_drawAreaNums.valueInteger != 0,
            a5: aas_drawClusterNums.valueInteger != 0,
            a6: aas_drawNormals.valueInteger != 0,
            a7: aas_drawAreaFilled.valueInteger != 0,
            a8: aas_drawAreaOutline.valueInteger != 0);
        v5 = this->file;
        ++v6;
        ++v7;
      }
      while ( v6 < v5->areas.num );
    }
  }
}


// ========================================================================
// __unwind$254035
// EA  : 0x826AFFC8
// RVA : 0x006AFFC8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_254035()
{
  int v0; // r12

  idBitArray::~idBitArray(this: (idBitArray *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$254036
// EA  : 0x826AFFF0
// RVA : 0x006AFFF0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_254036()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// ?ShowWalkPath@idAAS2Local@@UBAXHABVidVec3@@H0HHHHH@Z
// EA  : 0x826B0018
// RVA : 0x006B0018
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAAS2Local::ShowWalkPath(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags,
        const int passEntityNum,
        const int time,
        const int gameMsPerFrame,
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
        int a29,
        int a30)
{
  const idVec3 *v32; // r30
  idCVar *v36; // r29
  int toAreaNum; // r29
  float y; // r10
  float z; // r9
  int v40; // r19
  aas2Reachability_t *v41; // r30
  idRenderWorld *v42; // r3
  __int64 v43; // r6 OVERLAPPED
  __int64 v44; // r8 OVERLAPPED
  int v45; // r9
  __int16 v46; // r7
  __int64 v47; // r11
  __int128 v48; // r5
  idRenderWorld *v49; // r3
  __int64 v50; // r11
  __int64 v51; // r7
  idRenderWorld *v52; // r3
  obstacleVertex_t *VertexArray; // r29
  obstacleEdge_t *EdgeArray; // r28
  int v55; // r27
  _BYTE *v56; // r28
  int v57; // r29
  idIndex<int,enum invalidAASTree_t> *file; // r29
  float *v59; // r29
  double v60; // fp12
  double v61; // fp10
  idRenderWorld *v62; // r3
  obstacleTraceSet_t *v63; // [sp+8h] [-1608h]
  __int16 v64; // [sp+70h] [-15A0h] BYREF
  idCVar *v65; // [sp+74h] [-159Ch]
  int v66; // [sp+78h] [-1598h]
  __int64 v67; // [sp+80h] [-1590h]
  int MaxVertices; // [sp+88h] [-1588h] BYREF
  int MaxEdges; // [sp+8Ch] [-1584h] BYREF
  float x; // [sp+90h] [-1580h] BYREF
  float v71; // [sp+94h] [-157Ch]
  float v72; // [sp+98h] [-1578h]
  idAAS2File v73; // [sp+9Ch] [-1574h] BYREF
  int v74; // [sp+494h] [-117Ch]
  _BYTE v75[160]; // [sp+570h] [-10A0h] BYREF

  v32 = startOrigin;
  if ( this->file != nullptr )
  {
    v36 = &aas_showObstacleAvoidance;
    v65 = &aas_showObstacleAvoidance;
    if ( aas_showObstacleAvoidance.valueInteger != 2 )
    {
      toAreaNum = startAreaNum;
      y = startOrigin->y;
      z = startOrigin->z;
      x = startOrigin->x;
      v71 = y;
      v72 = z;
      v40 = 0;
      do
      {
        v64 = -1;
        if ( !this->RouteToGoalArea(
                this,
                a2: toAreaNum,
                a3: (const idVec3 *)&x,
                a4: goalAreaNum,
                a5: goalOrigin,
                a6: travelFlags,
                a7: (int *)&v73,
                a8: (idIndex<short,enum invalidReachability_t> *)&v64)
          || v64 < 0 )
        {
          break;
        }
        v41 = &this->file->reachabilities.list[v64];
        v42 = common->RW(this: common);
        HIDWORD(v43) = &x;
        HIDWORD(v44) = (unsigned __int16)v41->start[2];
        LODWORD(v44) = v41->start[1];
        LODWORD(v43) = v41->start[0];
        v45 = SWORD1(v44);
        *(_QWORD *)&v73.settings.type = v44;
        *(_QWORD *)&v73.settings.fileExtensionAAS.baseBuffer[8] = v43;
        *(_QWORD *)v73.settings.fileExtensionAAS.baseBuffer = *(__int64 *)((char *)&v44 - 4);
        *(float *)&v73.name.str = (float)v44;
        *(float *)&v73.trackedMemory = (float)v43;
        *(float *)&v73.nextOnHashChain = (float)*(__int64 *)((char *)&v44 - 4);
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int *, _DWORD, _DWORD, _DWORD, double))v42->DebugArrow)(
          a1: v42,
          a2: &idColor::colorGreen,
          a3: &x,
          a4: &v73.trackedMemory,
          a5: HIDWORD(v44),
          a6: 0,
          a7: 0,
          a8: 2.0);
        this->DrawReachability(
          this,
          a2: (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)v64,
          a3: v41,
          a4: nullptr);
        if ( aas_showAreas.valueInteger != 0 )
          this->DrawArea(
            this,
            a2: toAreaNum,
            a3: aas_drawReaches.valueInteger != 0,
            a4: aas_drawAreaNums.valueInteger != 0,
            a5: aas_drawClusterNums.valueInteger != 0,
            a6: aas_drawNormals.valueInteger != 0,
            a7: aas_drawAreaFilled.valueInteger != 0,
            a8: aas_drawAreaOutline.valueInteger != 0);
        if ( v41->toAreaNum == goalAreaNum )
        {
          v49 = common->RW(this: common);
          LODWORD(v50) = v41->end[2];
          LODWORD(v51) = v41->end[0];
          HIDWORD(v50) = v41->end[1];
          HIDWORD(v51) = goalOrigin;
          v67 = v51;
          *(float *)&v73.timestamp = (float)HIDWORD(v50);
          *(float *)&v73.crc = (float)v51;
          *(float *)&v73.visitedAreas.list = (float)v50;
          ((void (__fastcall *)(idRenderWorld *, idColor *, unsigned int *, const idVec3 *, double))v49->DebugArrow)(
            a1: v49,
            a2: &idColor::colorGreen,
            a3: &v73.crc,
            a4: goalOrigin,
            a5: 2.0);
          v32 = startOrigin;
          break;
        }
        toAreaNum = v41->toAreaNum;
        v46 = v41->end[2];
        ++v40;
        HIDWORD(v47) = (unsigned __int16)v41->end[0];
        DWORD1(v48) = v46;
        DWORD2(v48) = v41->end[1];
        LODWORD(v47) = v46;
        *(_QWORD *)&v73.settings.fileExtensionAAS.data = *(_QWORD *)((char *)&v48 + 4);
        v67 = v47;
        v32 = startOrigin;
        LODWORD(v48) = SWORD1(v47);
        *(_QWORD *)&v73.visitedAreas.size = v48;
        x = (float)(__int64)v48;
        v72 = (float)v47;
        v71 = (float)*(__int64 *)((char *)&v48 + 4);
      }
      while ( v40 < 1000 );
      v36 = v65;
    }
    idAAS2Path::idAAS2Path(this: (idAAS2Path *)&v73.settings.boundingBox.b[0].y);
    if ( this->WalkPathToGoal(
           this,
           a2: (idAAS2Path *)&v73.settings.boundingBox.b[0].y,
           a3: startAreaNum,
           a4: v32,
           a5: goalAreaNum,
           a6: goalOrigin,
           a7: travelFlags,
           a8: walkTravelFlags) )
    {
      if ( v36->valueInteger != 2 )
      {
        v52 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))v52->DebugArrow)(
          a1: v52,
          a2: &idColor::colorBlue,
          a3: v32,
          a4: &v73.settings.boundingBox.b[0].z,
          a5: 2.0);
      }
      idCVar::SetInteger(this: &aas_useObstacleAvoidanceJobs, newValue: 0, force: true);
      idObstacleAvoidance::AllocBuffers(this: &this->obstacleAvoidance);
      v66 = 1024;
      VertexArray = idObstacleAvoidance::GetVertexArray(this: &this->obstacleAvoidance);
      EdgeArray = idObstacleAvoidance::GetEdgeArray(this: &this->obstacleAvoidance);
      MaxVertices = idObstacleAvoidance::GetMaxVertices(this: &this->obstacleAvoidance);
      MaxEdges = idObstacleAvoidance::GetMaxEdges(this: &this->obstacleAvoidance);
      ((void (__fastcall *)(idAAS2Local *, int, int, obstacleVertex_t *, int *, obstacleEdge_t *, int *, _BYTE *))this->GetObstaclePVSObstacles)(
        a1: this,
        a2: startAreaNum,
        a3: 515,
        a4: VertexArray,
        a5: &MaxVertices,
        a6: EdgeArray,
        a7: &MaxEdges,
        a8: v75);
      idObstacleAvoidance::SetNumVertices(this: &this->obstacleAvoidance, num: MaxVertices);
      idObstacleAvoidance::SetNumEdges(this: &this->obstacleAvoidance, num: MaxEdges);
      v55 = 0;
      if ( v66 > 0 )
      {
        v56 = v75;
        do
        {
          v57 = *(_DWORD *)v56;
          if ( *(_DWORD *)(*(_DWORD *)v56 + 12) != passEntityNum )
          {
            idBox::idBox(
              this: (idBox *)&v73.settings.groupName.data,
              bounds: (const idBounds *)(v57 + 80),
              origin: (const idVec3 *)(v57 + 32),
              axis: (const idMat3 *)(v57 + 44));
            idObstacleAvoidance::AddObstacle(
              this: &this->obstacleAvoidance,
              box: (const idBox *)&v73.settings.groupName.data,
              id: *(const idSpawnId **)(v57 + 16),
              soft: false);
          }
          ++v55;
          v56 += 4;
        }
        while ( v55 < v66 );
      }
      file = (idIndex<int,enum invalidAASTree_t> *)this->file;
      v59 = (float *)(file[88].value
                    + 24 * (int)idAAS2File::GetTreeForArea(this: &v73, result: file, areaNum: startAreaNum)->__vftable);
      obstaclePath_t::obstaclePath_t(this: (obstaclePath_t *)&v73.traversalEntityNames.num);
      v60 = -v59[2];
      v61 = -v59[1];
      *(float *)&v73.resourceError = -*v59;
      *(float *)&v73.staleCount = v60;
      *(float *)&v73.networkID = v61;
      idObstacleAvoidance::FindPathAroundObstacles(
        this: &this->obstacleAvoidance,
        path: (obstaclePath_t *)&v73.traversalEntityNames.num,
        time: a28,
        gameMsPerFrame: a30,
        bbox: &this->file->settings.boundingBox,
        gravity: (const idVec3 *)&v73.resourceError,
        obstacleRadius: this->file->settings.obstaclePVSRadius,
        frameMoveDist: 32.0,
        cornerCircleRadius: 16.0,
        flags: (const int)&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor',
        route: (const obstacleRoute_t *)&v73.settings.highQualityReachabilityBackoff,
        traceSet: v63);
      if ( v74 != -1 )
      {
        v73.settings.boundingBox.b[0].z = *(float *)&v73.traversalEntityNames.num;
        v73.settings.boundingBox.b[1].x = *(float *)&v73.traversalEntityNames.size;
        v73.settings.boundingBox.b[1].y = *(float *)&v73.traversalEntityNames.granularity;
        v62 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))v62->DebugArrow)(
          a1: v62,
          a2: &idColor::colorOrange,
          a3: startOrigin,
          a4: &v73.settings.boundingBox.b[0].z,
          a5: 2.0);
      }
    }
  }
}


// ========================================================================
// ?ShowObstaclePVS@idAAS2Local@@ABAXH@Z
// EA  : 0x826B0648
// RVA : 0x006B0648
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowObstaclePVS(idAAS2Local *this, const int areaNum)
{
  int v3; // r3
  int v4; // r27
  idAAS2File *file; // r8
  int num; // r29
  int v7; // r30
  int i; // [sp+50h] [-60h] BYREF
  idList<enum encounterGroupRole_t,5> v9[5]; // [sp+60h] [-50h] BYREF

  v3 = ((int (__fastcall *)(idAAS2Local *))this->GetObstaclePVS)(a1: this);
  memset(v9, 0, 14);
  v4 = v3;
  v9[0].memTag = 5;
  v9[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v9);
  file = this->file;
  num = file->areas.num;
  if ( num > v9[0].size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v9, newsize: file->areas.num);
  v7 = 1;
  for ( i = 1; v7 < num; i = v7 )
  {
    if ( ((1 << (v7 & 7)) & *(unsigned __int8 *)((v7 >> 3) + v4)) != 0 )
      idList<idAnimWebBlendTree *,5>::Append(this: v9, obj: (const encounterGroupRole_t *)&i);
    ++v7;
  }
  idAAS2Local::DrawAreaList(this, areaList: (const idList<int,5> *)v9);
  if ( (v9[0].listStatic == 0 || v9[0].listStatic == 2) && v9[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v9[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$254347
// EA  : 0x826B0748
// RVA : 0x006B0748
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_254347()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?ShowAASBadAreas@idAAS2Local@@ABAXH@Z
// EA  : 0x826B0770
// RVA : 0x006B0770
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::ShowAASBadAreas(idAAS2Local *this, int mode)
{
  int v2; // r17
  idAAS2File *file; // r4
  int v5; // r27
  double v6; // fp27
  int v7; // r18
  double v8; // fp12
  double v9; // fp13
  aas2Area_t *v10; // r26
  double v11; // fp0
  __int64 v12; // r11
  int v13; // r28
  idAAS2File *v14; // r3
  int v15; // r30
  int firstEdge; // r31
  int *list; // r8
  aas2Edge_t *v18; // r17
  int *v19; // r7
  unsigned int v20; // r15
  float *v21; // r9
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  float *v25; // r9
  double v26; // fp5
  double v27; // fp4
  float *v28; // r9
  double v29; // fp0
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  float *v33; // r9
  int v34; // ctr
  char v35; // r30
  double v36; // fp31
  double v37; // fp30
  double v38; // fp29
  int v39; // r31
  idIndex<int,enum invalidAASTree_t> *v40; // r28
  int valueInteger; // r16
  idAAS2File *TreeForArea; // r3
  __int64 v43; // r10
  idAAS2File_vtbl *v44; // r11
  idAAS2File *v45; // r3
  float *v46; // r11
  double v47; // fp5
  double v48; // fp3
  unsigned int v49; // [sp+50h] [-F0h]
  char v50; // [sp+54h] [-ECh] BYREF
  __int64 v51; // [sp+58h] [-E8h]
  __int64 v52; // [sp+60h] [-E0h]
  idVec3 v53; // [sp+68h] [-D8h] BYREF

  v2 = mode;
  file = this->file;
  if ( file != nullptr )
  {
    v5 = 0;
    v6 = (float)(file->settings.boundingBox.b[1].z - file->settings.boundingBox.b[0].z);
    if ( file->areas.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = 0.0;
        v9 = 0.0;
        LODWORD(v12) = 0;
        v10 = &file->areas.list[v7];
        v11 = 0.0;
        HIDWORD(v12) = (unsigned __int16)v10->numEdges;
        v13 = SWORD1(v12);
        if ( SWORD1(v12) >= 4 )
        {
          v14 = this->file;
          v15 = SWORD1(v12) - 3;
          firstEdge = v10->firstEdge;
          HIDWORD(v12) = v14->vertices.list;
          do
          {
            list = file->edgeIndex.list;
            v18 = v14->edges.list;
            v19 = &list[firstEdge + v12];
            v20 = list[firstEdge + 2 + (_DWORD)v12];
            v49 = list[firstEdge + 3 + (_DWORD)v12];
            v21 = (float *)(12 * v18[abs32(*v19)].vertexNum[(unsigned int)*v19 >> 31] + HIDWORD(v12));
            v22 = v21[1];
            v23 = v21[2];
            v24 = (float)(*v21 + (float)v11);
            v25 = (float *)(12 * v18[abs32(v19[1])].vertexNum[(unsigned int)v19[1] >> 31] + HIDWORD(v12));
            v26 = *v25;
            v27 = v25[1];
            v29 = (float)(v25[2] + (float)((float)v23 + (float)v8));
            v28 = (float *)(12 * v18[abs32(v20)].vertexNum[v20 >> 31] + HIDWORD(v12));
            v31 = (float)(v28[1] + (float)((float)v27 + (float)((float)v22 + (float)v9)));
            v30 = (float)(*v28 + (float)((float)v26 + (float)v24));
            v32 = (float)(v28[2] + (float)v29);
            LODWORD(v12) = v12 + 4;
            v33 = (float *)(12 * v18[abs32(v49)].vertexNum[v49 >> 31] + HIDWORD(v12));
            v11 = (float)(*v33 + (float)v30);
            v9 = (float)(v33[1] + (float)v31);
            v8 = (float)(v33[2] + (float)v32);
          }
          while ( (int)v12 < v15 );
          v2 = mode;
        }
        if ( (int)v12 < v13 )
        {
          v34 = v13 - v12;
          do
          {
            HIDWORD(v12) = 4 * (v10->firstEdge + v12);
            LODWORD(v12) = v12 + 1;
            HIDWORD(v12) = &this->file->vertices.list[this->file->edges.list[abs32(*(int *)((char *)file->edgeIndex.list
                                                                                          + HIDWORD(v12)))].vertexNum[*(unsigned int *)((char *)file->edgeIndex.list + HIDWORD(v12)) >> 31]];
            v11 = (float)(*(float *)HIDWORD(v12) + (float)v11);
            v9 = (float)(*(float *)(HIDWORD(v12) + 4) + (float)v9);
            v8 = (float)(*(float *)(HIDWORD(v12) + 8) + (float)v8);
            --v34;
          }
          while ( v34 != 0 );
        }
        LODWORD(v12) = v13;
        v35 = 0;
        v51 = v12;
        v36 = (float)((float)((float)1.0 / (float)v12) * (float)v11);
        v37 = (float)((float)v9 * (float)((float)1.0 / (float)v12));
        v38 = (float)((float)v8 * (float)((float)1.0 / (float)v12));
        if ( v2 == 1 || v2 == 3 )
        {
          v39 = 0;
          while ( 1 )
          {
            v40 = (idIndex<int,enum invalidAASTree_t> *)this->file;
            valueInteger = aas_tree.valueInteger;
            TreeForArea = idAAS2File::GetTreeForArea(this: (idAAS2File *)&v50, result: v40, areaNum: v5);
            LODWORD(v43) = v39;
            v44 = TreeForArea->__vftable;
            v52 = v43;
            v45 = this->file;
            v46 = (float *)(v40[88].value + 24 * (_DWORD)v44);
            v47 = (float)(v46[2] * (float)((float)v43 * (float)v6));
            v48 = (float)((float)(v46[1] * (float)((float)v43 * (float)v6)) + (float)v37);
            v53.x = (float)(*v46 * (float)((float)v43 * (float)v6)) + (float)v36;
            v53.y = v48;
            v53.z = (float)v47 + (float)v38;
            if ( idAAS2File::PointAreaNum(this: v45, tree: valueInteger, origin: &v53) == v5 )
              break;
            if ( ++v39 >= 4 )
            {
              v35 = 1;
              break;
            }
          }
        }
        if ( (v2 == 2 || v2 == 3) && (v10->flags & 0x10) != 0 )
          v35 = 1;
        if ( v35 != 0 )
          this->DrawArea(
            this,
            a2: v5,
            a3: aas_drawReaches.valueInteger != 0,
            a4: aas_drawAreaNums.valueInteger != 0,
            a5: aas_drawClusterNums.valueInteger != 0,
            a6: aas_drawNormals.valueInteger != 0,
            a7: aas_drawAreaFilled.valueInteger != 0,
            a8: aas_drawAreaOutline.valueInteger != 0);
        file = this->file;
        ++v5;
        ++v7;
      }
      while ( v5 < file->areas.num );
    }
  }
}


// ========================================================================
// ?DrawCoverPoint@idAAS2Local@@UBAXPBUaas2Cover_t@@H@Z
// EA  : 0x826B0BE0
// RVA : 0x006B0BE0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::DrawCoverPoint(idAAS2Local *this, const aas2Cover_t *cover, const int coverIndex)
{
  idRenderWorld *v6; // r3
  idRenderWorld *v7; // r31
  int *v8; // r9
  int v9; // ctr
  char *v10; // r11
  __int16 flags; // r11
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r6
  double v15; // fp13
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  double v19; // fp9
  va *v20; // r3
  idIndex<int,enum invalidAASTree_t> *file; // r29
  idAAS2File *TreeForArea; // r3
  float *v23; // r8
  double x; // fp11
  double y; // fp9
  __int16 v26; // r7
  double v27; // fp8
  float *v28; // r5
  float v29; // r10
  float v30; // r9
  double z; // fp4
  double v32; // fp13
  double v33; // fp7
  double v34; // fp5
  double v35; // fp6
  double v36; // fp10
  double v37; // fp9
  double v38; // fp8
  double v39; // fp10
  double v40; // fp8
  double v41; // fp6
  double v42; // fp2
  double v43; // fp1
  double v44; // fp30
  double v45; // fp29
  idAAS2File *v46; // r9
  double v47; // fp28
  double v48; // fp26
  double v49; // fp21
  double v50; // fp5
  double v51; // fp27
  double v52; // fp28
  double v53; // fp26
  double v54; // fp23
  idVec3 *p_dir; // r29
  double v56; // fp24
  double v57; // fp7
  double v58; // fp21
  double v59; // fp29
  double v60; // fp25
  double v61; // fp0
  double v62; // fp9
  double v63; // fp9
  double v64; // fp4
  double v65; // fp13
  double v66; // fp10
  double v67; // fp21
  double v68; // fp20
  double v69; // fp29
  double v70; // fp4
  double v71; // fp13
  double v72; // fp10
  double v73; // fp27
  double v74; // fp28
  double v75; // fp4
  double v76; // fp13
  double v77; // fp10
  double v78; // fp4
  double v79; // fp13
  double v80; // fp10
  int v81; // [sp+8h] [-1268h]
  int v82; // [sp+Ch] [-1264h]
  int v83; // [sp+10h] [-1260h]
  int v84; // [sp+14h] [-125Ch]
  int v85; // [sp+18h] [-1258h]
  int v86; // [sp+1Ch] [-1254h]
  float v87; // [sp+60h] [-1210h] BYREF
  float v88; // [sp+64h] [-120Ch]
  float v89; // [sp+68h] [-1208h]
  float v90; // [sp+70h] [-1200h] BYREF
  float v91; // [sp+74h] [-11FCh]
  float v92; // [sp+78h] [-11F8h]
  int v93; // [sp+7Ch] [-11F4h] BYREF
  float v94; // [sp+80h] [-11F0h] BYREF
  float v95; // [sp+84h] [-11ECh]
  float v96; // [sp+88h] [-11E8h]
  float v97; // [sp+8Ch] [-11E4h]
  float v98; // [sp+90h] [-11E0h]
  float v99; // [sp+94h] [-11DCh]
  float v100; // [sp+98h] [-11D8h] BYREF
  float v101; // [sp+9Ch] [-11D4h]
  float v102; // [sp+A0h] [-11D0h]
  float v103; // [sp+A8h] [-11C8h] BYREF
  float v104; // [sp+ACh] [-11C4h]
  float v105; // [sp+B0h] [-11C0h]
  float v106; // [sp+B8h] [-11B8h]
  float v107; // [sp+BCh] [-11B4h]
  float v108; // [sp+C0h] [-11B0h]
  float v109[4]; // [sp+C8h] [-11A8h] BYREF
  float v110[4]; // [sp+D8h] [-1198h] BYREF
  float v111[4]; // [sp+E8h] [-1188h] BYREF
  float v112; // [sp+F8h] [-1178h] BYREF
  float v113; // [sp+FCh] [-1174h]
  float v114; // [sp+100h] [-1170h]
  float v115[4]; // [sp+108h] [-1168h] BYREF
  float v116[4]; // [sp+118h] [-1158h] BYREF
  float v117; // [sp+128h] [-1148h] BYREF
  float v118; // [sp+12Ch] [-1144h]
  float v119; // [sp+130h] [-1140h]
  float v120[4]; // [sp+138h] [-1138h] BYREF
  float v121[4]; // [sp+148h] [-1128h] BYREF
  float v122[4]; // [sp+158h] [-1118h] BYREF
  float v123[4]; // [sp+168h] [-1108h] BYREF
  float v124; // [sp+178h] [-10F8h] BYREF
  float v125; // [sp+17Ch] [-10F4h]
  float v126; // [sp+180h] [-10F0h]
  float v127; // [sp+188h] [-10E8h] BYREF
  float v128; // [sp+18Ch] [-10E4h]
  float v129; // [sp+190h] [-10E0h]
  float v130[4]; // [sp+198h] [-10D8h] BYREF
  float v131[3]; // [sp+1A8h] [-10C8h] BYREF
  idAAS2File v132[5]; // [sp+1B4h] [-10BCh] BYREF

  v6 = common->RW(this: common);
  v7 = v6;
  v8 = &v93;
  v9 = 6;
  v10 = &this->file->settings.explicitGroupName.baseBuffer[16];
  do
  {
    v10 += 4;
    *++v8 = *(_DWORD *)v10;
    --v9;
  }
  while ( v9 != 0 );
  flags = cover->flags;
  if ( (flags & 1) != 0 )
    v99 = (float)((float)(v99 - v96) * (float)0.5) + v96;
  if ( (flags & 0x400) != 0 )
    *(idColor *)&v132[0].nextOnHashChain = idColor::colorRed;
  else
    *(idColor *)&v132[0].nextOnHashChain = idColor::colorOrange;
  v6->DebugBounds(
    this: v6,
    a2: (const idVec4 *)&v132[0].nextOnHashChain,
    a3: (const idBounds *)&v94,
    a4: &cover->origin,
    a5: 0,
    a6: true);
  LODWORD(v12) = (unsigned __int16)cover->areaNum;
  HIDWORD(v13) = "_AI_OBSTACLE";
  HIDWORD(v14) = coverIndex;
  v15 = (float)(v95 + cover->origin.y);
  v16 = (float)(v96 + cover->origin.z);
  v17 = (float)(v97 + cover->origin.x);
  v18 = (float)(v98 + cover->origin.y);
  v19 = (float)(v99 + cover->origin.z);
  v94 = cover->origin.x + v94;
  v95 = v15;
  v96 = v16;
  LODWORD(v14) = (__int16)v12;
  v97 = v17;
  v98 = v18;
  v99 = v19;
  v120[0] = (float)((float)v17 + v94) * (float)0.5;
  v120[1] = (float)((float)v18 + (float)v15) * (float)0.5;
  v120[2] = (float)((float)v19 + (float)v16) * (float)0.5;
  v20 = va::va(
          this: (va *)&v132[0].staleCount,
          fmt: "%d (area %d)",
          a3: v14,
          a4: v12,
          a5: v13,
          a6: v81,
          a7: v82,
          a8: v83,
          a9: v84,
          a10: v85,
          a11: v86);
  ((void (__fastcall *)(idRenderWorld *, va *, float *, char *, idColor *, int, _DWORD, _DWORD, double))v7->DebugText)(
    a1: v7,
    a2: v20,
    a3: v120,
    a4: byte_821B0000,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: 0,
    a8: 0,
    a9: 0.1);
  file = (idIndex<int,enum invalidAASTree_t> *)this->file;
  TreeForArea = idAAS2File::GetTreeForArea(this: v132, result: file, areaNum: cover->areaNum);
  v23 = (float *)this->file;
  x = cover->origin.x;
  y = cover->origin.y;
  v26 = cover->flags;
  v27 = v23[45];
  v28 = (float *)(file[88].value + 24 * (int)TreeForArea->__vftable);
  v29 = v28[2];
  v30 = v28[1];
  z = cover->origin.z;
  v106 = *v28;
  v108 = v29;
  v107 = v30;
  v32 = v30;
  v33 = (float)((float)x + (float)((float)((float)v27 * v106) * (float)0.5));
  v100 = (float)x + (float)((float)((float)v27 * v106) * (float)0.5);
  v34 = (float)((float)((float)(v29 * (float)v27) * (float)0.5) + (float)z);
  v102 = (float)((float)(v29 * (float)v27) * (float)0.5) + (float)z;
  v35 = (float)((float)((float)(v30 * (float)v27) * (float)0.5) + (float)y);
  v101 = (float)((float)(v30 * (float)v27) * (float)0.5) + (float)y;
  v36 = (float)((float)x + (float)((float)(v106 * (float)v27) * (float)0.75));
  v37 = (float)((float)((float)(v30 * (float)v27) * (float)0.75) + (float)y);
  v38 = (float)((float)((float)(v29 * (float)v27) * (float)0.75) + (float)z);
  if ( (v26 & 1) != 0 )
  {
    v87 = v33;
    v88 = v35;
    v89 = v34;
    v39 = v23[69];
  }
  else
  {
    v87 = v36;
    v88 = v37;
    v89 = v38;
    v39 = v23[70];
  }
  v40 = cover->origin.y;
  v41 = cover->origin.z;
  v42 = cover->dir.x;
  v43 = (float)(v30 * (float)0.1);
  v44 = cover->dir.y;
  v45 = (float)(v106 * cover->dir.z);
  v47 = (float)(v30 * cover->dir.x);
  v48 = (float)(v29 * cover->dir.y);
  v49 = cover->dir.z;
  v50 = (float)((float)(v30 * (float)v39) + cover->origin.y);
  v46 = this->file;
  v103 = (float)x + (float)(v106 * (float)v39);
  v104 = v50;
  v105 = (float)(v29 * (float)v39) + (float)v41;
  v90 = (float)x + (float)(v106 * (float)0.1);
  v92 = (float)(v29 * (float)0.1) + (float)v41;
  v91 = (float)v43 + (float)v40;
  v51 = (float)((float)(v29 * (float)v42) - (float)v45);
  v52 = (float)((float)(v106 * (float)v44) - (float)v47);
  v53 = (float)((float)((float)v32 * (float)v49) - (float)v48);
  v54 = (float)((float)((float)(v29 * (float)v42) - (float)v45) * (float)-1.0);
  p_dir = &cover->dir;
  v56 = (float)((float)v52 * (float)-1.0);
  v57 = __fabs((float)((float)((float)(v23[43] - v23[40]) * (float)((float)v53 * (float)-1.0))
                     + (float)((float)((float)(v23[45] - v23[42]) * (float)((float)v52 * (float)-1.0))
                             + (float)((float)(v23[44] - v23[41])
                                     * (float)((float)((float)(v29 * (float)v42) - (float)v45) * (float)-1.0)))));
  v58 = __fabs((float)((float)((float)(v23[45] - v23[42]) * (float)v49)
                     + (float)((float)((float)(v23[44] - v23[41]) * (float)v44)
                             + (float)((float)(v23[43] - v23[40]) * (float)v42))));
  v59 = (float)((float)((float)v57 * (float)0.5) + v46->settings.coverCornerDistance);
  v60 = (float)(v46->settings.coverCornerDistance + (float)v57);
  v7->DebugPoint(this: v7, a2: (const idVec4 *)&idColor::colorMagenta, a3: (const idVec3 *)&v90, a4: 0, a5: true);
  v61 = (float)(cover->dir.z * (float)8.0);
  v62 = (float)((float)(cover->dir.y * (float)8.0) + v101);
  v111[0] = (float)(cover->dir.x * (float)8.0) + v100;
  v111[1] = v62;
  v111[2] = (float)v61 + v102;
  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
    a1: v7,
    a2: &idColor::colorGreen,
    a3: &v100,
    a4: v111,
    a5: 4.0);
  if ( (cover->flags & 0x20) != 0 )
  {
    v63 = (float)(cover->dir.z * (float)v58);
    v64 = (float)((float)(cover->dir.y * (float)v58) + v104);
    v130[0] = (float)(p_dir->x * (float)v58) + v103;
    v130[1] = v64;
    v130[2] = (float)v63 + v105;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorOrange,
      a3: &v103,
      a4: v130,
      a5: 4.0);
  }
  if ( (cover->flags & 0x40) != 0 )
  {
    v115[2] = (float)((float)v52 * (float)v59) + v89;
    v115[0] = (float)((float)v53 * (float)v59) + v87;
    v115[1] = (float)((float)v51 * (float)v59) + v88;
    v7->DebugLine(
      this: v7,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: (const idVec3 *)&v87,
      a4: (const idVec3 *)v115,
      a5: 0,
      a6: true);
    v117 = (float)((float)v53 * (float)v59) + v87;
    v119 = (float)((float)v52 * (float)v59) + v89;
    v65 = (float)(cover->dir.y * (float)8.0);
    v66 = (float)(cover->dir.z * (float)8.0);
    v109[0] = v117 + (float)(p_dir->x * (float)8.0);
    v118 = (float)((float)v51 * (float)v59) + v88;
    v109[1] = v118 + (float)v65;
    v109[2] = v119 + (float)v66;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorOrange,
      a3: &v117,
      a4: v109,
      a5: 4.0);
  }
  if ( (cover->flags & 0x80) != 0 )
  {
    v67 = (float)((float)((float)v53 * (float)-1.0) * (float)v59);
    v68 = (float)((float)v54 * (float)v59);
    v121[0] = (float)((float)((float)v53 * (float)-1.0) * (float)v59) + v87;
    v121[1] = (float)((float)v54 * (float)v59) + v88;
    v69 = (float)((float)((float)v52 * (float)-1.0) * (float)v59);
    v121[2] = (float)v69 + v89;
    v7->DebugLine(
      this: v7,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: (const idVec3 *)&v87,
      a4: (const idVec3 *)v121,
      a5: 0,
      a6: true);
    v70 = (float)(p_dir->x * (float)8.0);
    v71 = (float)(cover->dir.y * (float)8.0);
    v72 = (float)(cover->dir.z * (float)8.0);
    v124 = (float)v67 + v87;
    v125 = (float)v68 + v88;
    v126 = (float)v69 + v89;
    v122[0] = v124 + (float)v70;
    v122[1] = v125 + (float)v71;
    v122[2] = v126 + (float)v72;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorOrange,
      a3: &v124,
      a4: v122,
      a5: 4.0);
  }
  if ( (cover->flags & 0x100) != 0 )
  {
    v73 = (float)((float)v51 * (float)v60);
    v74 = (float)((float)v52 * (float)v60);
    v110[0] = (float)((float)v53 * (float)v60) + v90;
    v110[1] = (float)v73 + v91;
    v110[2] = (float)v74 + v92;
    v7->DebugLine(
      this: v7,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: (const idVec3 *)&v90,
      a4: (const idVec3 *)v110,
      a5: 0,
      a6: true);
    v75 = (float)(p_dir->x * (float)8.0);
    v76 = (float)(cover->dir.y * (float)8.0);
    v112 = (float)((float)v53 * (float)v60) + v90;
    v113 = (float)v73 + v91;
    v114 = (float)v74 + v92;
    v77 = (float)(cover->dir.z * (float)8.0);
    v116[0] = v112 + (float)v75;
    v116[1] = v113 + (float)v76;
    v116[2] = v114 + (float)v77;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorOrange,
      a3: &v112,
      a4: v116,
      a5: 4.0);
  }
  if ( (cover->flags & 0x200) != 0 )
  {
    v123[0] = (float)((float)((float)v53 * (float)-1.0) * (float)v60) + v90;
    v123[1] = (float)((float)v54 * (float)v60) + v91;
    v123[2] = (float)((float)v56 * (float)v60) + v92;
    v7->DebugLine(
      this: v7,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: (const idVec3 *)&v90,
      a4: (const idVec3 *)v123,
      a5: 0,
      a6: true);
    v78 = (float)(p_dir->x * (float)8.0);
    v79 = (float)(cover->dir.y * (float)8.0);
    v80 = (float)(cover->dir.z * (float)8.0);
    v127 = (float)((float)((float)v53 * (float)-1.0) * (float)v60) + v90;
    v128 = (float)((float)v54 * (float)v60) + v91;
    v129 = (float)((float)v56 * (float)v60) + v92;
    v131[0] = v127 + (float)v78;
    v131[1] = v128 + (float)v79;
    v131[2] = v129 + (float)v80;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorOrange,
      a3: &v127,
      a4: v131,
      a5: 4.0);
  }
}


// ========================================================================
// ?Test@idAAS2Local@@UAAXABVidVec3@@0ABVidMat3@@HHHHHPAVidClip@@AAVusercmd_t@@AAVidAngles@@@Z
// EA  : 0x826B1490
// RVA : 0x006B1490
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __fastcall idAAS2Local::Test(
        idAAS2Local *this,
        idVec3 *origin,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        int travelFlags,
        int pathOptimizationTravelFlags,
        int passEntityNum,
        int time,
        const int ticksPerSec,
        idClip *clip,
        usercmd_t *usercmd,
        idAngles *viewAngles,
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
        int a29,
        idClip *a30,
        int a31,
        int a32,
        int a33,
        idAngles *a34)
{
  float y; // r9
  float z; // r8
  int valueInteger; // r28
  idVec3 *v45; // r3
  __int64 v46; // r10
  int v47; // r7
  int v48; // r6
  int v49; // r5
  usercmd_t *v50; // [sp+8h] [-118h]
  int *v51; // [sp+Ch] [-114h]
  int *v52; // [sp+10h] [-110h]
  usercmd_t *v53; // [sp+14h] [-10Ch]
  idAngles *v54; // [sp+18h] [-108h]
  int v55; // [sp+1Ch] [-104h]
  int v56; // [sp+20h] [-100h]
  int v57; // [sp+24h] [-FCh]
  int v58; // [sp+28h] [-F8h]
  int v59; // [sp+2Ch] [-F4h]
  int v60; // [sp+30h] [-F0h]
  int v61; // [sp+34h] [-ECh]
  int v62; // [sp+38h] [-E8h]
  int v63; // [sp+3Ch] [-E4h]
  int v64; // [sp+40h] [-E0h]
  int v65; // [sp+44h] [-DCh]
  int v66; // [sp+48h] [-D8h]
  int v67; // [sp+4Ch] [-D4h]
  int v68; // [sp+50h] [-D0h]
  int v69; // [sp+58h] [-C8h]
  int v70; // [sp+60h] [-C0h]
  int v71; // [sp+68h] [-B8h]
  int v72; // [sp+70h] [-B0h]
  int v73; // [sp+80h] [-A0h] BYREF
  int v74; // [sp+84h] [-9Ch] BYREF
  int v75; // [sp+88h] [-98h] BYREF
  idAngles v76; // [sp+90h] [-90h] BYREF
  idVec3 v77; // [sp+A0h] [-80h] BYREF
  _BYTE v78[112]; // [sp+B0h] [-70h] BYREF

  if ( this->file != nullptr )
  {
    y = origin->y;
    z = origin->z;
    v76.pitch = origin->x;
    v76.yaw = y;
    valueInteger = aas_testArea.valueInteger;
    v76.roll = z;
    if ( aas_testArea.valueInteger > -1 && valueInteger < this->GetNumAreas(this) )
    {
      v45 = this->AreaCenter(this: v78, result: this, a3: aas_testArea.valueInteger);
      v76.pitch = v45->x;
      v76.yaw = v45->y;
      v76.roll = v45->z;
    }
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_locationMemory,
                            origin: &v76,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::ShowWalkPath(
        this,
        startOrigin: (const idVec3 *)&v76,
        goalAreaNum: v73,
        goalOrigin: &v77,
        travelFlags,
        pathOptimizationTravelFlags,
        passEntityNum,
        time,
        gameMsPerFrame: (const int)v50);
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_showPath,
                            origin: &v76,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::ShowWalkPath(
        this,
        startOrigin: (const idVec3 *)&v76,
        goalAreaNum: v73,
        goalOrigin: &v77,
        travelFlags,
        pathOptimizationTravelFlags,
        passEntityNum,
        time,
        gameMsPerFrame: (const int)v50);
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_showHopPath,
                            origin: &v76,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::ShowHopPath(
        this,
        startOrigin: (const idVec3 *)&v76,
        goalAreaNum: v73,
        goalOrigin: &v77,
        travelFlags,
        pathOptimizationTravelFlags);
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_showOptimizedPath,
                            origin: &v76,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::ShowOptimizedWalkPath(
        this,
        startOrigin: (const idVec3 *)&v76,
        goalAreaNum: v73,
        goalOrigin: &v77,
        travelFlags,
        pathOptimizationTravelFlags);
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_pullPlayer,
                            (idAngles *)origin,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::PullPlayer(
        this,
        origin,
        goalAreaNum: v73,
        goalOrigin: &v77,
        travelFlags,
        pathOptimizationTravelFlags,
        passEntityNum,
        time,
        gameMsPerFrame: (const int)v50,
        startAreaNum: v51,
        travelTime: v52,
        usercmd: v53,
        viewAngles: v54,
        a14: v55,
        a15: v56,
        a16: v57,
        a17: v58,
        a18: v59,
        a19: v60,
        a20: v61,
        a21: v62,
        a22: v63,
        a23: v64,
        a24: v65,
        a25: v66,
        a26: v67,
        a27: v68,
        a28,
        a29: v69,
        a30: &v75,
        a31: v70,
        a32: &v74,
        a33: v71,
        a34: a32,
        a35: v72,
        gameMsPerFramea: a34);
    if ( aas_randomPullPlayer.valueInteger != 0 )
      idAAS2Local::RandomPullPlayer(
        this,
        origin,
        mode: aas_randomPullPlayer.valueInteger,
        travelFlags,
        pathOptimizationTravelFlags,
        passEntityNum,
        time,
        ticksPerSec: a28,
        usercmd: v50,
        viewAngles: (idAngles *)v51,
        a11: (int)v52,
        a12: (int)v53,
        a13: (int)v54,
        a14: v55,
        a15: v56,
        a16: v57,
        a17: v58,
        a18: v59,
        a19: v60,
        a20: v61,
        a21: v62,
        a22: v63,
        a23: v64,
        a24: v65,
        a25: v66,
        a26: v67,
        a27: v68,
        a28: a32,
        a29: v69,
        a30: a34);
    if ( aas_showAreasByCluster.valueInteger != 0 || aas_showAreasInCluster.valueInteger > 0 )
    {
      idAAS2Local::ShowAreasByCluster(this, origin: (const idVec3 *)&v76);
    }
    else if ( aas_showAreas.valueInteger > 0 )
    {
      idAAS2Local::ShowAreas(this, origin: (const idVec3 *)&v76, mode: aas_showAreas.valueInteger);
    }
    if ( aas_showNearestInsideArea.valueInteger != 0 )
      idAAS2Local::ShowNearestInsideArea(
        this,
        origin: (const idVec3 *)&v76,
        travelFlags,
        pathOptimizationTravelFlags,
        passEntityNum,
        time,
        ticksPerSec: a28);
    if ( aas_showWallEdges.valueInteger != 0 )
      idAAS2Local::ShowWallEdges(
        this,
        origin: (const idVec3 *)&v76,
        viewOrigin,
        viewAxis,
        mode: aas_showWallEdges.valueInteger,
        showNumbers: aas_showWallEdgeNums.valueInteger != 0);
    if ( aas_showPushIntoArea.valueInteger != 0 )
      idAAS2Local::ShowPushIntoArea(this, origin: (const idVec3 *)&v76);
    if ( aas_showFloorTrace.valueFloat > 0.0 )
      idAAS2Local::ShowFloorTrace(this, origin, viewAxis, showTraceDist: aas_showFloorTrace.valueFloat);
    if ( (unsigned __int8)idAAS2Local::GetAreaNumAndLocation(
                            this,
                            cvar: &aas_showObstaclePVS,
                            origin: &v76,
                            areaNum: &v73,
                            location: &v77) != 0 )
      idAAS2Local::ShowObstaclePVS(this, areaNum: v73);
    if ( aas_showObstaclePVSClipModels.valueInteger != 0 )
      idAAS2Local::ShowObstaclePVSClipModels(this, origin, clip: a30);
    if ( aas_showManualReachabilities.valueInteger != 0 )
      idAAS2Local::ShowManualReachabilities(this);
    LODWORD(v46) = &aas_showTraversals;
    if ( aas_showTraversals.valueInteger != 0 )
      idAAS2Local::ShowTraversals(this, testOrigin: (const idVec3 *)&v76, a3: v49, a4: v48, a5: v47, a6: v46);
    if ( aas_showBadAreas.valueInteger != 0 )
      idAAS2Local::ShowAASBadAreas(this, mode: aas_showBadAreas.valueInteger);
    if ( aas_showCover.valueInteger != 0 )
      idAAS2Local::ShowCover(this, origin: (const idVec3 *)&v76);
    if ( *aas_testObstacleAvoidance.valueString.data != 0 )
    {
      idObstacleAvoidance::AllocBuffers(this: &this->obstacleAvoidance);
      idObstacleAvoidance::TestQuery(
        this: &this->obstacleAvoidance,
        fileName: aas_testObstacleAvoidance.valueString.data);
    }
    if ( aas_showAreaNumber.valueInteger != 0 )
      this->DrawArea(
        this,
        a2: aas_showAreaNumber.valueInteger,
        a3: aas_drawReaches.valueInteger != 0,
        a4: aas_drawAreaNums.valueInteger != 0,
        a5: aas_drawClusterNums.valueInteger != 0,
        a6: aas_drawNormals.valueInteger != 0,
        a7: aas_drawAreaFilled.valueInteger != 0,
        a8: aas_drawAreaOutline.valueInteger != 0);
    if ( aas_showHeightTrace.valueInteger != 0 )
      idAAS2Local::ShowHeightTrace(this, origin: (const idVec3 *)&v76, viewAxis);
  }
}


// ========================================================================
// ?DrawReachability@idAAS2Local@@UBAXV?$idIndex@FW4invalidReachability_t@@@@PBUaas2Reachability_t@@PBD@Z
// EA  : 0x826B1A00
// RVA : 0x006B1A00
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAAS2Local::DrawReachability(
        idAAS2Local *this,
        const idIndex<short,enum invalidReachability_t> *reachIndex,
        const aas2Reachability_t *reach,
        const char *name)
{
  idAAS2File *file; // r3
  unsigned int travelFlags; // r11
  unsigned int v8; // r7
  idColor *v9; // r9
  float r; // r8
  float b; // r6
  float g; // r7
  int v13; // r29
  int i; // r30
  aas2Traversal_t *v15; // r11
  __int128 v16; // r9
  __int64 v17; // r5
  double z; // fp0
  double y; // fp13
  double x; // fp12
  __int64 v21; // fp10
  double v22; // fp27
  double v23; // fp28
  double v24; // fp26
  idRenderWorld *v25; // r3
  __int128 v26; // r5 OVERLAPPED
  __int16 v27; // r4
  int v28; // r6
  int v29; // r7 OVERLAPPED
  __int128 v30; // r11 OVERLAPPED
  idColor v31; // [sp+60h] [-180h] BYREF
  float v32; // [sp+70h] [-170h] BYREF
  float v33; // [sp+74h] [-16Ch]
  float v34; // [sp+78h] [-168h]
  __int64 v35; // [sp+80h] [-160h]
  __int64 v36; // [sp+88h] [-158h]
  __int64 v37; // [sp+90h] [-150h]
  float v38[4]; // [sp+98h] [-148h] BYREF
  float v39[4]; // [sp+A8h] [-138h] BYREF
  float v40[6]; // [sp+B8h] [-128h] BYREF
  float v41[4]; // [sp+D0h] [-110h] BYREF
  idList<idVehicleState *,5> v42; // [sp+E0h] [-100h] BYREF
  int v43; // [sp+F0h] [-F0h] BYREF

  file = this->file;
  if ( file == nullptr )
    return;
  travelFlags = reach->travelFlags;
  v8 = reach->travelFlags & 0xB000;
  v31 = idColor::colorGreen;
  if ( v8 != 0 )
  {
    v9 = &idColor::colorCyan;
    r = idColor::colorCyan.r;
LABEL_10:
    b = v9->b;
    g = v9->g;
    v31.a = v9->a;
    v31.b = b;
    v31.g = g;
    v31.r = r;
    goto LABEL_11;
  }
  if ( (travelFlags & 0x400) != 0 )
  {
    v9 = &idColor::colorOrange;
    r = idColor::colorOrange.r;
    goto LABEL_10;
  }
  if ( (travelFlags & 0x1870810) != 0 )
  {
    v9 = &idColor::colorCyan;
    r = idColor::colorCyan.r;
    goto LABEL_10;
  }
  if ( (travelFlags & 0x1C0) != 0 )
  {
    v9 = &idColor::colorMagenta;
    r = idColor::colorMagenta.r;
    goto LABEL_10;
  }
LABEL_11:
  v13 = 0;
  v42.granularity = 1;
  v42.num = 0;
  v42.size = 32;
  v42.list = (idVehicleState **)&v43;
  v42.memTag = 5;
  v42.listStatic = 1;
  idAAS2File::GetTraversalsForReachability(this: file, reachIndex, traversals: &v42);
  for ( i = 0; i < v42.num; ++v13 )
  {
    v15 = &this->file->traversalPoints.list[(int)v42.list[v13]];
    DWORD2(v16) = &v15->orientationFwd;
    HIDWORD(v37) = &v15->orientationFwd;
    HIDWORD(v17) = (unsigned __int16)v15->orientationFwd.y;
    z = v15->startPoint.z;
    DWORD1(v16) = (unsigned __int16)v15->orientationFwd.x;
    y = v15->startPoint.y;
    LODWORD(v17) = SWORD1(v17);
    WORD1(v16) = v15->orientationFwd.z;
    LODWORD(v16) = SWORD3(v16);
    x = v15->startPoint.x;
    v36 = v16;
    v21 = v16;
    DWORD2(v16) = SWORD1(v16);
    v32 = x;
    v35 = *(_QWORD *)((char *)&v16 + 4);
    v33 = y;
    v34 = (float)z + (float)8.0;
    v22 = (float)((float)*(__int64 *)((char *)&v16 + 4) * (float)0.000030518509);
    v23 = (float)((float)v17 * (float)0.000030518509);
    v24 = (float)((float)v21 * (float)0.000030518509);
    v25 = common->RW(this: common);
    v38[2] = v34 + (float)((float)v22 * (float)8.0);
    v38[1] = v33 + (float)((float)v23 * (float)8.0);
    v38[0] = (float)((float)v24 * (float)8.0) + v32;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v25->DebugArrow)(
      a1: v25,
      a2: &v31,
      a3: &v32,
      a4: v38,
      a5: 2.0);
    ++i;
  }
  DWORD1(v26) = common->RW(this: common);
  v27 = reach->end[0];
  LOWORD(v28) = reach->start[1];
  v41[0] = v31.r;
  LODWORD(v26) = v27;
  v29 = (unsigned __int16)reach->end[1];
  v28 = (__int16)v28;
  DWORD1(v30) = (unsigned __int16)reach->end[2];
  DWORD2(v26) = reach->start[0];
  DWORD2(v30) = (__int16)v29;
  LODWORD(v30) = SWORD3(v30);
  HIDWORD(v30) = reach->start[2];
  v35 = v26;
  v36 = *(_QWORD *)((char *)&v26 + 4);
  v37 = v30;
  v41[1] = v31.g;
  v41[2] = v31.b;
  v41[3] = v31.a;
  v40[1] = (float)*(__int64 *)((char *)&v26 - 4);
  v39[1] = (float)*(__int64 *)((char *)&v30 + 4);
  v39[0] = (float)(__int64)v26;
  v40[0] = (float)*(__int64 *)((char *)&v26 + 4);
  v39[2] = (float)(__int64)v30;
  v40[2] = (float)*(__int64 *)(&v29 - 1);
  (*(void (__fastcall **)(_DWORD, float *, float *, float *, double))(*(_DWORD *)DWORD1(v26) + 180))(
    a1: DWORD1(v26),
    a2: v41,
    a3: v40,
    a4: v39,
    a5: 2.0);
  if ( (v42.listStatic == 0 || v42.listStatic == 2) && v42.list != nullptr )
    idMem::Free(this: &mem, ptr: v42.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$255801
// EA  : 0x826B1DA8
// RVA : 0x006B1DA8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void _unwind_255801()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 224));
}


// ========================================================================
// `dynamic initializer for 'aas_test''
// EA  : 0x8333D740
// RVA : 0x0133D740
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_test__()
{
  idCVar::idCVar(
    this: &aas_test,
    name: "aas_test",
    value: &byte_8200D768,
    flags: 0,
    description: "select which AAS to test (aas_monster48, etc)",
    valueCompletion: (const char **)idCmdSystem::ArgCompletion_String<&public: static char const * * idAAS2Settings::fileExtensions,8>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_test__);
}


// ========================================================================
// `dynamic initializer for 'aas_tree''
// EA  : 0x8333D798
// RVA : 0x0133D798
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_tree__()
{
  idCVar::idCVar(
    this: &aas_tree,
    name: "aas_tree",
    value: "0",
    flags: 2,
    description: "tree number in the AAS to show",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_tree__);
}


// ========================================================================
// `dynamic initializer for 'aas_showAreas''
// EA  : 0x8333D7F0
// RVA : 0x0133D7F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showAreas__()
{
  idCVar::idCVar(
    this: &aas_showAreas,
    name: "aas_showAreas",
    value: "0",
    flags: 2,
    description: "1 = show the player's current area in the test AAS using PointReachableAreaNum\n"
    " 2 = same as = 1, except use PointAreaNum\n"
    " > 2 = radius to show areas in current test AAS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showAreas__);
}


// ========================================================================
// `dynamic initializer for 'aas_showPath''
// EA  : 0x8333D848
// RVA : 0x0133D848
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showPath__()
{
  idCVar::idCVar(
    this: &aas_showPath,
    name: "aas_showPath",
    value: "0",
    flags: 0,
    description: "show the path to the walk specified area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showPath__);
}


// ========================================================================
// `dynamic initializer for 'aas_showHopPath''
// EA  : 0x8333D8A0
// RVA : 0x0133D8A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showHopPath__()
{
  idCVar::idCVar(
    this: &aas_showHopPath,
    name: "aas_showHopPath",
    value: "0",
    flags: 0,
    description: "show hop path to specified area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showHopPath__);
}


// ========================================================================
// `dynamic initializer for 'aas_showOptimizedPath''
// EA  : 0x8333D8F8
// RVA : 0x0133D8F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showOptimizedPath__()
{
  idCVar::idCVar(
    this: &aas_showOptimizedPath,
    name: "aas_showOptimizedPath",
    value: "0",
    flags: 0,
    description: "show optimized walk path",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showOptimizedPath__);
}


// ========================================================================
// `dynamic initializer for 'aas_showWallEdges''
// EA  : 0x8333D950
// RVA : 0x0133D950
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showWallEdges__()
{
  idCVar::idCVar(
    this: &aas_showWallEdges,
    name: "aas_showWallEdges",
    value: "0",
    flags: 2,
    description: "show the edges of walls, 2 = project all to same height, 3 = project onscreen",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"_AI_OBSTACLE",
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showWallEdges__);
}


// ========================================================================
// `dynamic initializer for 'aas_showWallEdgeNums''
// EA  : 0x8333D9B8
// RVA : 0x0133D9B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showWallEdgeNums__()
{
  idCVar::idCVar(
    this: &aas_showWallEdgeNums,
    name: "aas_showWallEdgeNums",
    value: "0",
    flags: 1,
    description: "show the number of the edges of walls",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showWallEdgeNums__);
}


// ========================================================================
// `dynamic initializer for 'aas_showNearestInsideArea''
// EA  : 0x8333DA10
// RVA : 0x0133DA10
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showNearestInsideArea__()
{
  idCVar::idCVar(
    this: &aas_showNearestInsideArea,
    name: "aas_showNearestInsideArea",
    value: "0",
    flags: 1,
    description: "show the nearest area that is inside",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showNearestInsideArea__);
}


// ========================================================================
// `dynamic initializer for 'aas_showTravelTime''
// EA  : 0x8333DA68
// RVA : 0x0133DA68
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showTravelTime__()
{
  idCVar::idCVar(
    this: &aas_showTravelTime,
    name: "aas_showTravelTime",
    value: "0",
    flags: 2,
    description: "print the travel time to the specified goal area (only when aas_showAreas is set)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showTravelTime__);
}


// ========================================================================
// `dynamic initializer for 'aas_showPushIntoArea''
// EA  : 0x8333DAC0
// RVA : 0x0133DAC0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showPushIntoArea__()
{
  idCVar::idCVar(
    this: &aas_showPushIntoArea,
    name: "aas_showPushIntoArea",
    value: "0",
    flags: 1,
    description: "show an arrow going to the closest area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showPushIntoArea__);
}


// ========================================================================
// `dynamic initializer for 'aas_showFloorTrace''
// EA  : 0x8333DB18
// RVA : 0x0133DB18
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showFloorTrace__()
{
  idCVar::idCVar(
    this: &aas_showFloorTrace,
    name: "aas_showFloorTrace",
    value: "0.0f",
    flags: 4,
    description: "1 = show trace 1024 units out. > 1, show trace to cvar's value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showFloorTrace__);
}


// ========================================================================
// `dynamic initializer for 'aas_showObstaclePVS''
// EA  : 0x8333DB70
// RVA : 0x0133DB70
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showObstaclePVS__()
{
  idCVar::idCVar(
    this: &aas_showObstaclePVS,
    name: "aas_showObstaclePVS",
    value: "0",
    flags: 0,
    description: "show obstacle PVS for the given area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showObstaclePVS__);
}


// ========================================================================
// `dynamic initializer for 'aas_showObstaclePVSClipModels''
// EA  : 0x8333DBC8
// RVA : 0x0133DBC8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showObstaclePVSClipModels__()
{
  idCVar::idCVar(
    this: &aas_showObstaclePVSClipModels,
    name: "aas_showObstaclePVSClipModels",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showObstaclePVSClipModels__);
}


// ========================================================================
// `dynamic initializer for 'aas_showManualReachabilities''
// EA  : 0x8333DC20
// RVA : 0x0133DC20
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showManualReachabilities__()
{
  idCVar::idCVar(
    this: &aas_showManualReachabilities,
    name: "aas_showManualReachabilities",
    value: "0",
    flags: 1,
    description: "show manually placed reachabilities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showManualReachabilities__);
}


// ========================================================================
// `dynamic initializer for 'aas_showTraversals''
// EA  : 0x8333DC78
// RVA : 0x0133DC78
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showTraversals__()
{
  idCVar::idCVar(
    this: &aas_showTraversals,
    name: "aas_showTraversals",
    value: "0",
    flags: 2,
    description: "< -1 = draw radius in -world units with depth test\n"
    "-1 = show all traversals in the map\n"
    "0 = show nothing\n"
    "> 1 = draw radius in world units",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showTraversals__);
}


// ========================================================================
// `dynamic initializer for 'aas_showFuncObstacles''
// EA  : 0x8333DCD0
// RVA : 0x0133DCD0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showFuncObstacles__()
{
  idCVar::idCVar(
    this: &aas_showFuncObstacles,
    name: "aas_showFuncObstacles",
    value: "0",
    flags: 1,
    description: "show the AAS func_obstacles on the map",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showFuncObstacles__);
}


// ========================================================================
// `dynamic initializer for 'aas_showBadAreas''
// EA  : 0x8333DD28
// RVA : 0x0133DD28
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showBadAreas__()
{
  idCVar::idCVar(
    this: &aas_showBadAreas,
    name: "aas_showBadAreas",
    value: "0",
    flags: 2,
    description: "show bad AAS areas",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"_AI_OBSTACLE",
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showBadAreas__);
}


// ========================================================================
// `dynamic initializer for 'aas_locationMemory''
// EA  : 0x8333DD90
// RVA : 0x0133DD90
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_locationMemory__()
{
  idCVar::idCVar(
    this: &aas_locationMemory,
    name: "aas_locationMemory",
    value: "0",
    flags: 0,
    description: "used to remember a particular location, set to 'current' to store the current x,y,z location",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_locationMemory__);
}


// ========================================================================
// `dynamic initializer for 'aas_pullPlayer''
// EA  : 0x8333DDE8
// RVA : 0x0133DDE8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_pullPlayer__()
{
  idCVar::idCVar(
    this: &aas_pullPlayer,
    name: "aas_pullPlayer",
    value: "0",
    flags: 0,
    description: "pull the player to the specified area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_pullPlayer__);
}


// ========================================================================
// `dynamic initializer for 'aas_randomPullPlayer''
// EA  : 0x8333DE40
// RVA : 0x0133DE40
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_randomPullPlayer__()
{
  idCVar::idCVar(
    this: &aas_randomPullPlayer,
    name: "aas_randomPullPlayer",
    value: "0",
    flags: 2,
    description: "pull the player to a random area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_randomPullPlayer__);
}


// ========================================================================
// `dynamic initializer for 'aas_showCover''
// EA  : 0x8333DE98
// RVA : 0x0133DE98
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showCover__()
{
  idCVar::idCVar(
    this: &aas_showCover,
    name: "aas_showCover",
    value: "0",
    flags: 2,
    description: "-1 = show all cover in the map\n"
    "1 = show cover for the current area\n"
    "values above 1 are treated as a radius in world units",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showCover__);
}


// ========================================================================
// `dynamic initializer for 'aas_showReachabilities''
// EA  : 0x8333DEF0
// RVA : 0x0133DEF0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showReachabilities__()
{
  idCVar::idCVar(
    this: &aas_showReachabilities,
    name: "aas_showReachabilities",
    value: "0",
    flags: 1,
    description: "1 = show reachability flags",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showReachabilities__);
}


// ========================================================================
// `dynamic initializer for 'aas_testObstacleAvoidance''
// EA  : 0x8333DF48
// RVA : 0x0133DF48
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_testObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &aas_testObstacleAvoidance,
    name: "aas_testObstacleAvoidance",
    value: &byte_8200D768,
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_testObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'aas_testArea''
// EA  : 0x8333DF98
// RVA : 0x0133DF98
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_testArea__()
{
  idCVar::idCVar(
    this: &aas_testArea,
    name: "aas_testArea",
    value: "-1",
    flags: 2,
    description: "area to be used as the origin for path debug display. -1 = use player position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_testArea__);
}


// ========================================================================
// `dynamic initializer for 'aas_showHeightTrace''
// EA  : 0x8333DFF0
// RVA : 0x0133DFF0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showHeightTrace__()
{
  idCVar::idCVar(
    this: &aas_showHeightTrace,
    name: "aas_showHeightTrace",
    value: "0",
    flags: 1,
    description: "1 = show height trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showHeightTrace__);
}


// ========================================================================
// `dynamic initializer for 'aas_showAreaNumber''
// EA  : 0x8333E048
// RVA : 0x0133E048
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showAreaNumber__()
{
  idCVar::idCVar(
    this: &aas_showAreaNumber,
    name: "aas_showAreaNumber",
    value: "0",
    flags: 2,
    description: "show the specific area number set",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showAreaNumber__);
}


// ========================================================================
// `dynamic initializer for 'aas_showAreasByCluster''
// EA  : 0x8333E0A0
// RVA : 0x0133E0A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showAreasByCluster__()
{
  idCVar::idCVar(
    this: &aas_showAreasByCluster,
    name: "aas_showAreasByCluster",
    value: "0",
    flags: 1,
    description: "1 = draw areas, showing only the areas in the same cluster as the player's current area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showAreasByCluster__);
}


// ========================================================================
// `dynamic initializer for 'aas_showAreasInCluster''
// EA  : 0x8333E0F8
// RVA : 0x0133E0F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showAreasInCluster__()
{
  idCVar::idCVar(
    this: &aas_showAreasInCluster,
    name: "aas_showAreasInCluster",
    value: "0",
    flags: 2,
    description: "draw areas that are in the specified cluster",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showAreasInCluster__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawEdgeNums''
// EA  : 0x8333E150
// RVA : 0x0133E150
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawEdgeNums__()
{
  idCVar::idCVar(
    this: &aas_drawEdgeNums,
    name: "aas_drawEdgeNums",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawEdgeNums__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawVertexNums''
// EA  : 0x8333E1A8
// RVA : 0x0133E1A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawVertexNums__()
{
  idCVar::idCVar(
    this: &aas_drawVertexNums,
    name: "aas_drawVertexNums",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawVertexNums__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawEdgeDirection''
// EA  : 0x8333E200
// RVA : 0x0133E200
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawEdgeDirection__()
{
  idCVar::idCVar(
    this: &aas_drawEdgeDirection,
    name: "aas_drawEdgeDirection",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawEdgeDirection__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawAreaNums''
// EA  : 0x8333E258
// RVA : 0x0133E258
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawAreaNums__()
{
  idCVar::idCVar(
    this: &aas_drawAreaNums,
    name: "aas_drawAreaNums",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawAreaNums__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawClusterNums''
// EA  : 0x8333E2B0
// RVA : 0x0133E2B0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawClusterNums__()
{
  idCVar::idCVar(
    this: &aas_drawClusterNums,
    name: "aas_drawClusterNums",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawClusterNums__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawReaches''
// EA  : 0x8333E308
// RVA : 0x0133E308
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawReaches__()
{
  idCVar::idCVar(
    this: &aas_drawReaches,
    name: "aas_drawReaches",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawReaches__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawAreaFilled''
// EA  : 0x8333E360
// RVA : 0x0133E360
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawAreaFilled__()
{
  idCVar::idCVar(
    this: &aas_drawAreaFilled,
    name: "aas_drawAreaFilled",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawAreaFilled__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawAreaOutline''
// EA  : 0x8333E3B8
// RVA : 0x0133E3B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawAreaOutline__()
{
  idCVar::idCVar(
    this: &aas_drawAreaOutline,
    name: "aas_drawAreaOutline",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawAreaOutline__);
}


// ========================================================================
// `dynamic initializer for 'aas_drawNormals''
// EA  : 0x8333E410
// RVA : 0x0133E410
// PDB : w:\tech5\engine\gamelib\aas2\aas2_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_drawNormals__()
{
  idCVar::idCVar(
    this: &aas_drawNormals,
    name: "aas_drawNormals",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_drawNormals__);
}

