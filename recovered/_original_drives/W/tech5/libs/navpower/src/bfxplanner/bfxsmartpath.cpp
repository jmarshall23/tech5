
// ========================================================================
// ??9CalcCornersSpec@bfx@@QBA_NABV01@@Z
// EA  : 0x8328C0C0
// RVA : 0x0128C0C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::CalcCornersSpec::operator!=(bfx::CalcCornersSpec *this, const bfx::CalcCornersSpec *rhs)
{
  unsigned __int8 v2; // r11

  if ( this->m_maxNumCorners != rhs->m_maxNumCorners )
    return 1;
  if ( this->m_maxPathDist != rhs->m_maxPathDist )
    return 1;
  if ( this->m_addCornersAtEveryAreaBoundary != rhs->m_addCornersAtEveryAreaBoundary )
    return 1;
  v2 = 0;
  if ( this->m_addCornerAtStartingPosition != rhs->m_addCornerAtStartingPosition )
    return 1;
  return v2;
}


// ========================================================================
// ?IsAreaInFan@bfx@@YAXPAVArea@1@0HAA_N1@Z
// EA  : 0x8328C110
// RVA : 0x0128C110
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::IsAreaInFan(
        bfx::Area *pArea,
        bfx::Area *pPrevArea,
        int edgeIndexToNextArea,
        bool *areaIsInLeftFanOut,
        bool *areaIsInRightFanOut)
{
  signed int v5; // r11
  int v6; // r10

  *areaIsInLeftFanOut = false;
  *areaIsInRightFanOut = false;
  if ( edgeIndexToNextArea != -1 && pArea != nullptr && pPrevArea != nullptr )
  {
    v5 = pArea->m_flags.m_flags1 & 0x7F;
    __twllei(v5, 0);
    __twlgei(v5 & ~(__ROL4__(edgeIndexToNextArea + 1, 1) - 1), 0xFFFFFFFF);
    if ( (bfx::Area *)(&pArea[1].m_pProxy)[6 * ((edgeIndexToNextArea + 1) % v5)] == pPrevArea )
      *areaIsInLeftFanOut = true;
    __twllei(v5, 0);
    v6 = v5 + edgeIndexToNextArea - 1;
    __twlgei(v5 & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
    if ( (bfx::Area *)(&pArea[1].m_pProxy)[6 * (v6 % v5)] == pPrevArea )
      *areaIsInRightFanOut = true;
  }
}


// ========================================================================
// ?TransformPosIntoUnwrappedCoordinatesOfArea@bfx@@YA?AVVec3@1@ABV21@PAVArea@1@ABVAreaExitData@1@@Z
// EA  : 0x8328C1E0
// RVA : 0x0128C1E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::TransformPosIntoUnwrappedCoordinatesOfArea(
        bfx::Vec3 *result,
        const bfx::Vec3 *posG,
        bfx::Vec3 *pArea,
        const bfx::AreaExitData *areaExitData)
{
  double v7; // fp3
  double v8; // fp31
  double v11; // fp1
  double v12; // fp13
  double v13; // fp12
  double v14; // fp11
  bfx::Area v16; // [sp+60h] [-70h] BYREF
  bfx::Vec3 m_exitUnitVec; // 0:^50.12

  bfx::Area::CalcNormal(this: &v16, result: pArea);
  v7 = (float)(areaExitData->m_exitSegU.m_v1.m_y - areaExitData->m_exitSegU.m_v0.m_y);
  m_exitUnitVec = areaExitData->m_exitUnitVec;
  v8 = (float)(areaExitData->m_exitSegU.m_v1.m_x - areaExitData->m_exitSegU.m_v0.m_x);
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v8 * (float)v8)
                                       + (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_z
                                                               - areaExitData->m_exitSegU.m_v0.m_z)
                                                       * (float)(areaExitData->m_exitSegU.m_v1.m_z
                                                               - areaExitData->m_exitSegU.m_v0.m_z))
                                               + (float)((float)v7 * (float)v7))))
               - (float)1.0842022e-19);
  __asm { fsel      f8, f8, f7, f6 }
  v12 = (float)(areaExitData->m_exitSegU.m_v0.m_z
              + (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_z - areaExitData->m_exitSegU.m_v0.m_z)
                              * (float)_FP8)
                      * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x) * m_exitUnitVec.m_x)
                              + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z) * m_exitUnitVec.m_z)
                                      + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y) * m_exitUnitVec.m_y)))));
  v13 = (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_y - areaExitData->m_exitSegU.m_v0.m_y) * (float)_FP8)
              * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x)
                              * (float)((float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_y)
                                      - (float)(m_exitUnitVec.m_z * *(float *)&v16.m_dynAreaData.m_data)))
                      + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z)
                                      * (float)((float)(m_exitUnitVec.m_x * *(float *)&v16.m_dynAreaData.m_data)
                                              - (float)(m_exitUnitVec.m_y * *(float *)&v16.m_pProxy)))
                              + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y)
                                      * (float)((float)(m_exitUnitVec.m_z * *(float *)&v16.m_pProxy)
                                              - (float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_x))))));
  v14 = (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_z - areaExitData->m_exitSegU.m_v0.m_z) * (float)_FP8)
              * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x)
                              * (float)((float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_y)
                                      - (float)(m_exitUnitVec.m_z * *(float *)&v16.m_dynAreaData.m_data)))
                      + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z)
                                      * (float)((float)(m_exitUnitVec.m_x * *(float *)&v16.m_dynAreaData.m_data)
                                              - (float)(m_exitUnitVec.m_y * *(float *)&v16.m_pProxy)))
                              + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y)
                                      * (float)((float)(m_exitUnitVec.m_z * *(float *)&v16.m_pProxy)
                                              - (float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_x))))));
  v11 = (float)(areaExitData->m_exitSegU.m_v0.m_x
              + (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_x - areaExitData->m_exitSegU.m_v0.m_x)
                              * (float)_FP8)
                      * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x) * m_exitUnitVec.m_x)
                              + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z) * m_exitUnitVec.m_z)
                                      + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y) * m_exitUnitVec.m_y)))));
  result->m_y = (float)(areaExitData->m_exitSegU.m_v0.m_y
                      + (float)((float)((float)(areaExitData->m_exitSegU.m_v1.m_y - areaExitData->m_exitSegU.m_v0.m_y)
                                      * (float)_FP8)
                              * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x) * m_exitUnitVec.m_x)
                                      + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z)
                                                      * m_exitUnitVec.m_z)
                                              + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y)
                                                      * m_exitUnitVec.m_y)))))
              + (float)((float)-(float)((float)(areaExitData->m_exitSegU.m_v1.m_x - areaExitData->m_exitSegU.m_v0.m_x)
                                      * (float)_FP8)
                      * (float)((float)((float)(posG->m_x - areaExitData->m_exitSeg.m_v0.m_x)
                                      * (float)((float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_y)
                                              - (float)(m_exitUnitVec.m_z * *(float *)&v16.m_dynAreaData.m_data)))
                              + (float)((float)((float)(posG->m_z - areaExitData->m_exitSeg.m_v0.m_z)
                                              * (float)((float)(m_exitUnitVec.m_x * *(float *)&v16.m_dynAreaData.m_data)
                                                      - (float)(m_exitUnitVec.m_y * *(float *)&v16.m_pProxy)))
                                      + (float)((float)(posG->m_y - areaExitData->m_exitSeg.m_v0.m_y)
                                              * (float)((float)(m_exitUnitVec.m_z * *(float *)&v16.m_pProxy)
                                                      - (float)(*(float *)&v16.m_pFirstLink * m_exitUnitVec.m_x))))));
  result->m_x = (float)v11 + (float)v13;
  result->m_z = (float)v12 + (float)v14;
  return result;
}


// ========================================================================
// ?IsInteriorVertOnSide@bfx@@YA_NABVEdgeCursor@1@_N@Z
// EA  : 0x8328C350
// RVA : 0x0128C350
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::IsInteriorVertOnSide(const bfx::EdgeCursor *startCC, bool checkLeftVert)
{
  bfx::Area *m_pArea; // r30
  bfx::EdgeCursor v4; // r11
  bfx::EdgeCursor v6; // [sp+50h] [-30h] BYREF
  bfx::EdgeCursor v7; // [sp+58h] [-28h] BYREF

  m_pArea = startCC->m_pArea;
  v6 = *startCC;
  while ( 1 )
  {
    bfx::EdgeCursor::GetSibling(this: &v7, result: &v6);
    if ( v7.m_pArea == nullptr )
      break;
    v4.m_i = v7.m_i;
    v4.m_pArea = (bfx::Area *)checkLeftVert;
    v6 = v4;
    if ( checkLeftVert )
    {
      v6.m_i = v7.m_i - 1;
      if ( v7.m_i - 1 < 0 )
        v6.m_i = (*(_DWORD *)(checkLeftVert + 0x28) & 0x7F) - 1;
    }
    else
    {
      v6.m_i = (((unsigned int)(v7.m_i + 1) - __PAIR64__((unsigned int)(v7.m_i + 1) >> 31, MEMORY[0x2B] & 0x7F)) >> 32)
             & (v7.m_i + 1);
    }
    if ( (bfx::Area *)checkLeftVert == m_pArea )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?SetNavLayer@SmartPath@bfx@@QAAXI@Z
// EA  : 0x8328C420
// RVA : 0x0128C420
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::SetNavLayer(bfx::SmartPath *this, unsigned int layer)
{
  unsigned int m_curTimestamp; // r11

  if ( layer != this->m_layer )
  {
    m_curTimestamp = this->m_curTimestamp;
    this->m_layer = layer;
    this->m_curTimestamp = ++m_curTimestamp;
    this->m_layerTimestamp = m_curTimestamp;
  }
}


// ========================================================================
// ??8PathSpec@bfx@@QBA_NABV01@@Z
// EA  : 0x8328C448
// RVA : 0x0128C448
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::PathSpec::operator==(bfx::PathSpec *this, const bfx::PathSpec *rhs)
{
  unsigned __int8 v2; // r11

  if ( this->m_obstacleMode != rhs->m_obstacleMode )
    return 0;
  if ( this->m_obstacleBlockageFlags != rhs->m_obstacleBlockageFlags )
    return 0;
  if ( this->m_areaUsageFlags != rhs->m_areaUsageFlags )
    return 0;
  if ( this->m_linkUsageFlags != rhs->m_linkUsageFlags )
    return 0;
  if ( this->m_usePathSharingPenalty != rhs->m_usePathSharingPenalty )
    return 0;
  if ( this->m_pathSharingPenalty != rhs->m_pathSharingPenalty )
    return 0;
  if ( this->m_maxPathSharingPenalty != rhs->m_maxPathSharingPenalty )
    return 0;
  v2 = 1;
  if ( this->m_maxSearchDist != rhs->m_maxSearchDist )
    return 0;
  return v2;
}


// ========================================================================
// ?SetPathSpec@SmartPath@bfx@@QAAXABVPathSpec@2@@Z
// EA  : 0x8328C4D8
// RVA : 0x0128C4D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::SetPathSpec(bfx::SmartPath *this, bfx::PathSpec *pathSpec)
{
  int v2; // r9
  int *v3; // r7
  int v4; // r4
  _DWORD *v5; // r11
  _DWORD *v6; // r10
  int i; // ctr
  int v8; // r11

  if ( (unsigned __int8)bfx::PathSpec::operator==(this: pathSpec, rhs: &this->m_pathSpec) == 0 )
  {
    v5 = (_DWORD *)(v2 - 4);
    v6 = (_DWORD *)(v4 - 4);
    for ( i = 8; i != 0; --i )
      *++v6 = *++v5;
    v8 = *v3 + 1;
    *v3 = v8;
    v3[13] = v8;
  }
}


// ========================================================================
// ?SetPathCreationOptions@SmartPath@bfx@@QAAXABVPathCreationOptions@2@@Z
// EA  : 0x8328C540
// RVA : 0x0128C540
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::SetPathCreationOptions(bfx::SmartPath *this, const bfx::PathCreationOptions *options)
{
  const bfx::PathCreationOptions *v2; // r11
  bfx::PathCreationOptions *p_m_pathCreationOptions; // r10
  BOOL m_performInitialNavProbe; // r6
  int v5; // r8
  unsigned int v6; // r11

  v2 = options;
  p_m_pathCreationOptions = &this->m_pathCreationOptions;
  do
  {
    m_performInitialNavProbe = p_m_pathCreationOptions->m_performInitialNavProbe;
    v5 = v2->m_performInitialNavProbe - m_performInitialNavProbe;
    if ( v2->m_performInitialNavProbe != m_performInitialNavProbe )
      break;
    v2 = (const bfx::PathCreationOptions *)((char *)v2 + 1);
    p_m_pathCreationOptions = (bfx::PathCreationOptions *)((char *)p_m_pathCreationOptions + 1);
  }
  while ( v2 != &options[1] );
  if ( v5 != 0 )
  {
    v6 = this->m_curTimestamp + 1;
    this->m_pathCreationOptions = *options;
    this->m_curTimestamp = v6;
    this->m_pcoTimestamp = v6;
  }
}


// ========================================================================
// ?ClearCachedData@SmartPath@bfx@@QAAXXZ
// EA  : 0x8328C5A0
// RVA : 0x0128C5A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::ClearCachedData(bfx::SmartPath *this)
{
  unsigned int v1; // r11
  unsigned int v2; // r10

  v1 = this->m_curTimestamp + 1;
  v2 = this->m_curTimestamp + 2;
  this->m_curTimestamp = v1;
  this->m_layerTimestamp = v1;
  this->m_curTimestamp = v2;
  this->m_pathSpecTimestamp = v2;
  this->m_curTimestamp = v2 + 1;
  this->m_pcoTimestamp = v2 + 1;
  v2 += 2;
  this->m_curTimestamp = v2;
  this->m_inputStartDataTimestamp = v2;
  this->m_curTimestamp = v2 + 1;
  this->m_inputGoalDataTimestamp = v2 + 1;
}


// ========================================================================
// ??$PopFront@PAVArea@bfx@@@bfx@@YAXAAV?$Array@PAVArea@bfx@@@0@@Z
// EA  : 0x8328C5E8
// RVA : 0x0128C5E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PopFront<bfx::Area *>(bfx::Array<bfx::Area *> *myArray)
{
  int v1; // r10
  int v2; // r11
  bfx::Area **v3; // r9

  v1 = 0;
  if ( myArray->m_size - 1 > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &myArray->m_data[v2++];
      *v3 = v3[1];
    }
    while ( v1 < myArray->m_size - 1 );
  }
  --myArray->m_size;
}


// ========================================================================
// ?BuildIthUnwrappedData@bfx@@YAXHABV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@@Z
// EA  : 0x8328C798
// RVA : 0x0128C798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::BuildIthUnwrappedData(
        int i,
        const bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits)
{
  char v3; // r11
  bfx::AreaExitData *m_data; // r10
  float *p_m_x; // r11
  double v6; // fp0
  double v7; // fp2
  double v8; // fp12
  double v9; // fp4
  double v10; // fp3
  double v11; // fp10
  double v12; // fp11
  double v13; // fp0
  float *v14; // r31
  double v15; // fp2
  double v16; // fp1
  double v17; // fp31
  double v18; // fp5
  double v19; // fp3
  double v20; // fp6
  bfx::AreaProxy *m_pProxy; // r7
  double v22; // fp4
  double v23; // fp9
  double v24; // fp29
  float v25; // r5
  double v26; // fp5
  double v27; // fp3
  double v28; // fp4
  double v29; // fp29
  double v31; // fp26
  double v33; // fp6
  double v34; // fp5
  double v35; // fp3
  double v36; // fp2
  double v37; // fp4
  double v38; // fp0
  double v39; // fp13
  double v40; // fp7
  double v41; // fp5
  double v42; // fp12
  double v43; // fp11
  float v44; // [sp+50h] [-90h]
  float v45; // [sp+54h] [-8Ch]
  float v46; // [sp+58h] [-88h]
  float v47; // [sp+60h] [-80h]
  float v48; // [sp+64h] [-7Ch]
  float v49; // [sp+68h] [-78h]
  bfx::Area v50; // [sp+70h] [-70h] BYREF

  if ( i == 0 || (v3 = 0, areaExits->m_data[i - 1].m_exitType == EXIT_TYPE_LINK) )
    v3 = 1;
  m_data = areaExits->m_data;
  if ( v3 != 0 )
  {
    p_m_x = &m_data[i].m_exitSeg.m_v0.m_x;
    v6 = *p_m_x;
    p_m_x[12] = *p_m_x;
    v7 = v6;
    v8 = p_m_x[1];
    p_m_x[13] = p_m_x[1];
    p_m_x[14] = p_m_x[2];
    v9 = (float)(p_m_x[4] - p_m_x[1]);
    v10 = (float)(p_m_x[5] - p_m_x[2]);
    v11 = p_m_x[14];
    v12 = (float)(p_m_x[3] - *p_m_x);
    v13 = __fsqrts((float)((float)((float)v12 * (float)v12)
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
    p_m_x[16] = (float)v8 + (float)v13;
    p_m_x[15] = (float)((float)v13 * (float)0.0) + (float)v7;
    p_m_x[17] = (float)v11 + (float)((float)v13 * (float)0.0);
  }
  else
  {
    v14 = &m_data[i].m_exitSeg.m_v0.m_x;
    bfx::Area::CalcNormal(this: &v50, result: (bfx::Vec3 *)pathAreas->m_data[i]);
    v15 = (float)(*(v14 - 2) - *(v14 - 5));
    v16 = (float)(*(v14 - 1) - *(v14 - 4));
    v17 = (float)(*(v14 - 3) - *(v14 - 6));
    v46 = *(v14 - 16);
    v45 = *(v14 - 17);
    v18 = v14[2];
    v19 = v14[5];
    v44 = *(v14 - 18);
    v49 = *(v14 - 10);
    v20 = v14[1];
    v48 = *(v14 - 11);
    v22 = v14[4];
    v47 = *(v14 - 12);
    v23 = *(float *)&v50.m_pProxy;
    v24 = *v14;
    v50.m_pProxy = *(bfx::AreaProxy **)(v14 - 6);
    m_pProxy = v50.m_pProxy;
    v25 = *(v14 - 4);
    v26 = (float)((float)v18 - v46);
    v27 = (float)((float)v19 - v46);
    v28 = (float)((float)v22 - v45);
    v29 = (float)((float)v24 - v44);
    _FP7 = (float)((float)__fsqrts((float)((float)((float)v17 * (float)v17)
                                         + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))))
                 - (float)1.0842022e-19);
    v31 = (float)((float)((float)v29 * v47)
                + (float)((float)((float)v26 * v49) + (float)((float)((float)v20 - v45) * v48)));
    __asm { fsel      f7, f7, f6, f13 }
    v33 = (float)((float)((float)v26
                        * (float)((float)(*(float *)&v50.m_dynAreaData.m_data * v47) - (float)(v48 * (float)v23)))
                + (float)((float)((float)v20 - v45)
                        * (float)((float)(v49 * (float)v23) - (float)(*(float *)&v50.m_pFirstLink * v47))));
    v34 = (float)((float)((float)v27
                        * (float)((float)(*(float *)&v50.m_dynAreaData.m_data * v47) - (float)(v48 * (float)v23)))
                + (float)((float)v28 * (float)((float)(v49 * (float)v23) - (float)(*(float *)&v50.m_pFirstLink * v47))));
    v37 = (float)((float)((float)(v14[3] - v44) * v47) + (float)((float)((float)v27 * v49) + (float)((float)v28 * v48)));
    v35 = (float)((float)v15 * (float)_FP7);
    v38 = (float)((float)((float)v29
                        * (float)((float)(*(float *)&v50.m_pFirstLink * v48)
                                - (float)(v49 * *(float *)&v50.m_dynAreaData.m_data)))
                + (float)v33);
    v39 = (float)((float)((float)(v14[3] - v44)
                        * (float)((float)(*(float *)&v50.m_pFirstLink * v48)
                                - (float)(v49 * *(float *)&v50.m_dynAreaData.m_data)))
                + (float)v34);
    v50.m_dynAreaData.m_data = *(char **)(v14 - 5);
    v41 = (float)((float)((float)v17 * (float)_FP7) * (float)v37);
    v42 = (float)(*(float *)&v50.m_dynAreaData.m_data + (float)((float)((float)v15 * (float)_FP7) * (float)v31));
    v43 = (float)((float)((float)((float)v15 * (float)_FP7) * (float)v37) + *(float *)&v50.m_dynAreaData.m_data);
    v14[14] = (float)(v25 + (float)((float)((float)v16 * (float)_FP7) * (float)v31))
            + (float)((float)((float)v16 * (float)_FP7) * (float)v38);
    v14[12] = (float)((float)((float)((float)v17 * (float)_FP7) * (float)v31) + *(float *)&m_pProxy)
            + (float)((float)((float)v15 * (float)_FP7) * (float)v38);
    v36 = (float)((float)v16 * (float)_FP7);
    v40 = -(float)((float)v17 * (float)_FP7);
    v14[13] = (float)v42 + (float)((float)v40 * (float)v38);
    v14[15] = (float)((float)v41 + *(float *)&m_pProxy) + (float)((float)v35 * (float)v39);
    v14[16] = (float)v43 + (float)((float)v40 * (float)v39);
    v14[17] = (float)((float)((float)v36 * (float)v37) + v25) + (float)((float)v36 * (float)v39);
  }
}


// ========================================================================
// ?BuildUnwrappedData@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@@Z
// EA  : 0x8328CA98
// RVA : 0x0128CA98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::BuildUnwrappedData(
        const bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits)
{
  int m_size; // r11
  int v5; // r27
  int v6; // r30
  int v7; // r28
  char v8; // r11
  bfx::AreaExitData *m_data; // r11
  bool v10; // zf
  float *v11; // r11
  double v12; // fp0
  double v13; // fp3
  double v14; // fp1
  double v15; // fp13
  double v16; // fp5
  double v17; // fp4
  double v18; // fp0
  double v19; // fp0
  float *p_m_x; // r31
  double v21; // fp6
  double v22; // fp1
  double v23; // fp28
  double v26; // fp10
  double v27; // fp5
  double v28; // fp2
  double v29; // fp9
  double v30; // fp28
  double v31; // fp8
  double v32; // fp1
  double v33; // fp5
  double v34; // fp11
  double v35; // fp3
  double v36; // fp4
  float v37; // [sp+50h] [-D0h]
  float v38; // [sp+54h] [-CCh]
  float v39; // [sp+58h] [-C8h]
  float v40; // [sp+60h] [-C0h]
  float v41; // [sp+64h] [-BCh]
  float v42; // [sp+68h] [-B8h]
  float v43; // [sp+70h] [-B0h]
  float v44; // [sp+74h] [-ACh]
  float v45; // [sp+78h] [-A8h]
  bfx::Area v46; // [sp+80h] [-A0h] BYREF

  m_size = areaExits->m_size;
  if ( m_size != 0 )
  {
    v5 = 0;
    if ( m_size > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        if ( v5 == 0 || (v8 = 0, areaExits->m_data[v6 - 1].m_exitType == EXIT_TYPE_LINK) )
          v8 = 1;
        v10 = v8 == 0;
        m_data = areaExits->m_data;
        if ( v10 )
        {
          p_m_x = &m_data[v6].m_exitSeg.m_v0.m_x;
          bfx::Area::CalcNormal(this: &v46, result: (bfx::Vec3 *)pathAreas->m_data[v7]);
          v21 = (float)(*(p_m_x - 2) - *(p_m_x - 5));
          v42 = *(p_m_x - 16);
          v22 = (float)(*(p_m_x - 1) - *(p_m_x - 4));
          v41 = *(p_m_x - 17);
          v23 = (float)(*(p_m_x - 3) - *(p_m_x - 6));
          v39 = *(p_m_x - 10);
          v40 = *(p_m_x - 18);
          v38 = *(p_m_x - 11);
          v37 = *(p_m_x - 12);
          v43 = *(p_m_x - 6);
          v44 = *(p_m_x - 5);
          v45 = *(p_m_x - 4);
          _FP25 = (float)((float)__fsqrts((float)((float)((float)v23 * (float)v23)
                                                + (float)((float)((float)v22 * (float)v22)
                                                        + (float)((float)v21 * (float)v21))))
                        - (float)1.0842022e-19);
          __asm { fsel      f7, f25, f7, f31 }
          v26 = (float)((float)((float)(*(p_m_x - 2) - v44) * (float)_FP7)
                      * (float)((float)((float)(*p_m_x - v40) * v37)
                              + (float)((float)((float)(p_m_x[2] - v42) * v39) + (float)((float)(p_m_x[1] - v41) * v38))));
          v27 = -(float)((float)(*(p_m_x - 3) - v43) * (float)_FP7);
          v28 = (float)((float)((float)(*(p_m_x - 3) - v43) * (float)_FP7)
                      * (float)((float)((float)(p_m_x[3] - v40) * v37)
                              + (float)((float)((float)(p_m_x[5] - v42) * v39) + (float)((float)(p_m_x[4] - v41) * v38))));
          v29 = (float)((float)((float)(*(p_m_x - 1) - v45) * (float)_FP7)
                      * (float)((float)((float)(p_m_x[3] - v40) * v37)
                              + (float)((float)((float)(p_m_x[5] - v42) * v39) + (float)((float)(p_m_x[4] - v41) * v38))));
          v30 = (float)((float)((float)(*(p_m_x - 2) - v44) * (float)_FP7)
                      * (float)((float)((float)(*p_m_x - v40)
                                      * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                              - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                              + (float)((float)((float)(p_m_x[2] - v42)
                                              * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                      - (float)(v38 * *(float *)&v46.m_pProxy)))
                                      + (float)((float)(p_m_x[1] - v41)
                                              * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                      - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          v31 = (float)((float)((float)(*(p_m_x - 2) - v44) * (float)_FP7)
                      * (float)((float)((float)(p_m_x[3] - v40)
                                      * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                              - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                              + (float)((float)((float)(p_m_x[5] - v42)
                                              * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                      - (float)(v38 * *(float *)&v46.m_pProxy)))
                                      + (float)((float)(p_m_x[4] - v41)
                                              * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                      - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          v32 = (float)((float)v27
                      * (float)((float)((float)(*p_m_x - v40)
                                      * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                              - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                              + (float)((float)((float)(p_m_x[2] - v42)
                                              * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                      - (float)(v38 * *(float *)&v46.m_pProxy)))
                                      + (float)((float)(p_m_x[1] - v41)
                                              * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                      - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          v33 = (float)((float)v27
                      * (float)((float)((float)(p_m_x[3] - v40)
                                      * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                              - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                              + (float)((float)((float)(p_m_x[5] - v42)
                                              * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                      - (float)(v38 * *(float *)&v46.m_pProxy)))
                                      + (float)((float)(p_m_x[4] - v41)
                                              * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                      - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          v34 = (float)((float)((float)(*(p_m_x - 1) - v45) * (float)_FP7)
                      * (float)((float)((float)(p_m_x[3] - v40)
                                      * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                              - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                              + (float)((float)((float)(p_m_x[5] - v42)
                                              * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                      - (float)(v38 * *(float *)&v46.m_pProxy)))
                                      + (float)((float)(p_m_x[4] - v41)
                                              * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                      - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          v35 = (float)((float)((float)((float)(*(p_m_x - 3) - v43) * (float)_FP7)
                              * (float)((float)((float)(*p_m_x - v40) * v37)
                                      + (float)((float)((float)(p_m_x[2] - v42) * v39)
                                              + (float)((float)(p_m_x[1] - v41) * v38))))
                      + v43);
          v36 = (float)((float)((float)((float)(*(p_m_x - 2) - v44) * (float)_FP7)
                              * (float)((float)((float)(p_m_x[3] - v40) * v37)
                                      + (float)((float)((float)(p_m_x[5] - v42) * v39)
                                              + (float)((float)(p_m_x[4] - v41) * v38))))
                      + v44);
          p_m_x[14] = (float)(v45
                            + (float)((float)((float)(*(p_m_x - 1) - v45) * (float)_FP7)
                                    * (float)((float)((float)(*p_m_x - v40) * v37)
                                            + (float)((float)((float)(p_m_x[2] - v42) * v39)
                                                    + (float)((float)(p_m_x[1] - v41) * v38)))))
                    + (float)((float)((float)(*(p_m_x - 1) - v45) * (float)_FP7)
                            * (float)((float)((float)(*p_m_x - v40)
                                            * (float)((float)(*(float *)&v46.m_pFirstLink * v38)
                                                    - (float)(v39 * *(float *)&v46.m_dynAreaData.m_data)))
                                    + (float)((float)((float)(p_m_x[2] - v42)
                                                    * (float)((float)(*(float *)&v46.m_dynAreaData.m_data * v37)
                                                            - (float)(v38 * *(float *)&v46.m_pProxy)))
                                            + (float)((float)(p_m_x[1] - v41)
                                                    * (float)((float)(v39 * *(float *)&v46.m_pProxy)
                                                            - (float)(*(float *)&v46.m_pFirstLink * v37))))));
          p_m_x[13] = (float)(v44 + (float)v26) + (float)v32;
          p_m_x[12] = (float)v35 + (float)v30;
          p_m_x[15] = (float)((float)v28 + v43) + (float)v31;
          p_m_x[16] = (float)v36 + (float)v33;
          p_m_x[17] = (float)((float)v29 + v45) + (float)v34;
        }
        else
        {
          v11 = &m_data[v6].m_exitSeg.m_v0.m_x;
          v12 = *v11;
          v11[12] = *v11;
          v13 = v12;
          v14 = v11[1];
          v11[13] = v11[1];
          v15 = v11[2];
          v11[14] = v11[2];
          v16 = (float)(v11[3] - *v11);
          v17 = (float)(v11[5] - v11[2]);
          v18 = (float)(v11[4] - v11[1]);
          v19 = __fsqrts((float)((float)((float)v18 * (float)v18)
                               + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))));
          v11[16] = (float)v14 + (float)v19;
          v11[15] = (float)v13 + (float)((float)v19 * (float)0.0);
          v11[17] = (float)v15 + (float)((float)v19 * (float)0.0);
        }
        ++v5;
        ++v7;
        ++v6;
      }
      while ( v5 < areaExits->m_size );
    }
  }
}


// ========================================================================
// ?GetNextCorner@bfx@@YAXABVVec3@1@HAAV?$Array@VAreaExitData@bfx@@@1@M0AAV21@AAHAAW4CornerFlavor@1@@Z
// EA  : 0x8328CD98
// RVA : 0x0128CD98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::GetNextCorner(
        const bfx::Vec3 *startPos,
        int startIndex,
        bfx::Array<bfx::AreaExitData> *areaExits,
        double maxShrinkDist,
        const bfx::Vec3 *pathStartPos,
        bfx::Vec3 *nextCornerPosOut,
        float *nextCornerIndexOut,
        bfx::CornerFlavor *cornerFlavorOut,
        _DWORD *a9)
{
  int m_size; // r11
  int *v13; // r6
  int v14; // ctr
  _DWORD *v16; // r10
  int v17; // r11
  double v18; // fp5
  bfx::CornerFlavor v19; // r26
  char v20; // r3
  double v21; // fp30
  double v22; // fp29
  bfx::CornerFlavor v23; // r29
  double v24; // fp26
  bfx::CornerFlavor v25; // r28
  double v26; // fp28
  int v27; // r6
  double v28; // fp27
  double v29; // fp25
  int v30; // r4
  bfx::AreaExitData *v31; // r11
  float *p_m_x; // r9
  float *v33; // r10
  float m_x; // r8
  float m_y; // r22
  float m_z; // r21
  double v37; // fp6
  double v38; // fp13
  float v39; // r22
  float v40; // r8
  float v41; // r22
  float v42; // r21
  float v43; // r20
  double v44; // fp13
  double v45; // fp8
  double v46; // fp7
  double v47; // fp9
  double v48; // fp6
  double v49; // fp0
  double v50; // fp12
  double v53; // fp24
  double v54; // fp12
  double v55; // fp0
  bfx::CornerFlavor v56; // [sp+50h] [-180h]
  float v57; // [sp+58h] [-178h]
  float v58; // [sp+8Ch] [-144h]
  float v59; // [sp+90h] [-140h]
  float v60; // [sp+9Ch] [-134h]
  bfx::Vec3 v61; // [sp+A8h] [-128h] BYREF
  bfx::Vec3 v62; // [sp+B8h] [-118h] BYREF
  int v63; // [sp+CCh] [-104h] BYREF
  bfx::LineSeg v64[4]; // [sp+D0h] [-100h] BYREF

  *a9 = 5;
  m_size = areaExits->m_size;
  v13 = &v63;
  v14 = 6;
  v16 = (_DWORD *)((char *)&areaExits->m_data[m_size - 1] + 44);
  do
  {
    *++v13 = *++v16;
    --v14;
  }
  while ( v14 != 0 );
  v17 = m_size - 1;
  v18 = (float)((float)maxShrinkDist * (float)maxShrinkDist);
  v19 = v17;
  v56 = v17;
  if ( startIndex == v17 )
  {
    *(bfx::Vec3 *)nextCornerIndexOut = *bfx::GetClosestPtOnLineSeg(result: &v61, seg: v64, pos: startPos);
    goto LABEL_37;
  }
  v20 = 1;
  v21 = 0.0;
  v22 = 0.0;
  v23 = startIndex;
  v24 = 0.0;
  v25 = startIndex;
  v26 = 0.0;
  v27 = startIndex;
  v28 = 0.0;
  v29 = 0.0;
  if ( startIndex >= v17 )
    goto LABEL_34;
  v30 = startIndex;
  while ( 1 )
  {
    v31 = &areaExits->m_data[v30];
    if ( v31->m_exitType == EXIT_TYPE_LINK )
    {
      p_m_x = &v31->m_exitSegU.m_v0.m_x;
      v33 = &v31->m_exitSegU.m_v1.m_x;
      if ( (float)((float)((float)(v31->m_exitSegU.m_v1.m_y - startPos->m_y)
                         * (float)(v31->m_exitSegU.m_v0.m_x - startPos->m_x))
                 - (float)((float)(v31->m_exitSegU.m_v0.m_y - startPos->m_y)
                         * (float)(v31->m_exitSegU.m_v1.m_x - startPos->m_x))) <= 0.0 )
      {
        m_x = v31->m_exitSeg.m_v0.m_x;
        v31->m_exitSeg.m_v0.m_x = v31->m_exitSeg.m_v1.m_x;
        m_y = v31->m_exitSeg.m_v0.m_y;
        m_z = v31->m_exitSeg.m_v0.m_z;
        v31->m_exitSeg.m_v0.m_y = v31->m_exitSeg.m_v1.m_y;
        v31->m_exitSeg.m_v0.m_z = v31->m_exitSeg.m_v1.m_z;
        v31->m_exitSeg.m_v1.m_x = m_x;
        v31->m_exitSeg.m_v1.m_y = m_y;
        v31->m_exitSeg.m_v1.m_z = m_z;
        v37 = v31->m_exitUnitVec.m_z;
        v38 = (float)(v31->m_exitUnitVec.m_x * (float)-1.0);
        v31->m_exitUnitVec.m_y = v31->m_exitUnitVec.m_y * (float)-1.0;
        v31->m_exitUnitVec.m_x = v38;
        v31->m_exitUnitVec.m_z = (float)v37 * (float)-1.0;
        v59 = v31->m_exitSegU.m_v0.m_z;
        v39 = *p_m_x;
        *p_m_x = *v33;
        v58 = v31->m_exitSegU.m_v0.m_y;
        v31->m_exitSegU.m_v0.m_y = v31->m_exitSegU.m_v1.m_y;
        v31->m_exitSegU.m_v0.m_z = v31->m_exitSegU.m_v1.m_z;
        *v33 = v39;
        v31->m_exitSegU.m_v1.m_y = v58;
        v31->m_exitSegU.m_v1.m_z = v59;
      }
    }
    v40 = v31->m_exitSegU.m_v1.m_z;
    v41 = v31->m_exitSegU.m_v0.m_x;
    v42 = v31->m_exitSegU.m_v0.m_y;
    v43 = v31->m_exitSegU.m_v0.m_z;
    v57 = v31->m_exitSegU.m_v1.m_x;
    v44 = v57;
    v45 = v40;
    v46 = v41;
    v47 = v42;
    v48 = v43;
    v60 = v31->m_exitSegU.m_v1.m_y;
    v61.m_y = v42;
    v61.m_x = v41;
    v61.m_z = v43;
    if ( maxShrinkDist <= 0.0 )
    {
      v49 = v60;
    }
    else
    {
      v49 = v60;
      v50 = __fsqrts((float)((float)((float)(v60 - v61.m_y) * (float)(v60 - v61.m_y))
                           + (float)((float)((float)(v57 - v61.m_x) * (float)(v57 - v61.m_x))
                                   + (float)((float)(v40 - v61.m_z) * (float)(v40 - v61.m_z)))));
      _FP23 = (float)((float)maxShrinkDist - (float)((float)v50 * (float)0.25));
      __asm { fsel      f24, f23, f24, f1 }
      v53 = (float)((float)_FP24 / (float)v50);
      if ( (float)((float)((float)(v60 - nextCornerPosOut->m_y) * (float)(v60 - nextCornerPosOut->m_y))
                 + (float)((float)((float)(v57 - nextCornerPosOut->m_x) * (float)(v57 - nextCornerPosOut->m_x))
                         + (float)((float)(v40 - nextCornerPosOut->m_z) * (float)(v40 - nextCornerPosOut->m_z)))) > v18 )
      {
        v44 = (float)(v57 - (float)((float)(v57 - v61.m_x) * (float)v53));
        v49 = (float)(v60 - (float)((float)(v60 - v61.m_y) * (float)v53));
        v45 = (float)(v40 - (float)((float)(v40 - v61.m_z) * (float)v53));
      }
      if ( (float)((float)((float)(v42 - nextCornerPosOut->m_y) * (float)(v42 - nextCornerPosOut->m_y))
                 + (float)((float)((float)(v41 - nextCornerPosOut->m_x) * (float)(v41 - nextCornerPosOut->m_x))
                         + (float)((float)(v43 - nextCornerPosOut->m_z) * (float)(v43 - nextCornerPosOut->m_z)))) > v18 )
      {
        v47 = (float)((float)((float)(v60 - v61.m_y) * (float)v53) + v42);
        v46 = (float)((float)((float)(v57 - v61.m_x) * (float)v53) + v41);
        v48 = (float)((float)((float)(v40 - v61.m_z) * (float)v53) + v43);
      }
    }
    if ( v20 != 0 )
    {
      v21 = v44;
      v23 = v27;
      v22 = v49;
      v20 = 0;
      v24 = v45;
LABEL_27:
      v29 = v48;
      v25 = v27;
      v28 = v47;
      v26 = v46;
      goto LABEL_28;
    }
    if ( (*((_BYTE *)v31 + 44) & 0x80) == 0 || maxShrinkDist > 0.0 )
    {
      if ( (float)((float)((float)((float)v49 - startPos->m_y) * (float)((float)v26 - startPos->m_x))
                 - (float)((float)((float)v28 - startPos->m_y) * (float)((float)v44 - startPos->m_x))) <= 0.0 )
        goto LABEL_31;
      if ( (float)((float)((float)((float)v49 - startPos->m_y) * (float)((float)v21 - startPos->m_x))
                 - (float)((float)((float)v22 - startPos->m_y) * (float)((float)v44 - startPos->m_x))) <= 0.0 )
      {
        v21 = v44;
        v23 = v27;
        v22 = v49;
        v24 = v45;
      }
    }
    if ( (*((_BYTE *)v31 + 44) & 0x40) == 0 || maxShrinkDist > 0.0 )
    {
      if ( (float)((float)((float)((float)v47 - startPos->m_y) * (float)((float)v21 - startPos->m_x))
                 - (float)((float)((float)v22 - startPos->m_y) * (float)((float)v46 - startPos->m_x))) >= 0.0 )
        goto LABEL_32;
      if ( (float)((float)((float)((float)v47 - startPos->m_y) * (float)((float)v26 - startPos->m_x))
                 - (float)((float)((float)v28 - startPos->m_y) * (float)((float)v46 - startPos->m_x))) >= 0.0 )
        goto LABEL_27;
    }
LABEL_28:
    if ( v31->m_exitType == EXIT_TYPE_LINK )
      break;
    ++v27;
    ++v30;
    if ( v27 >= areaExits->m_size - 1 )
    {
      v19 = v56;
      goto LABEL_34;
    }
  }
  v19 = v27;
  v64[0].m_v0.m_x = v31->m_exitSegU.m_v0.m_x;
  v64[0].m_v0.m_y = v31->m_exitSegU.m_v0.m_y;
  v64[0].m_v0.m_z = v31->m_exitSegU.m_v0.m_z;
  v64[0].m_v1.m_x = v31->m_exitSegU.m_v1.m_x;
  v64[0].m_v1.m_y = v31->m_exitSegU.m_v1.m_y;
  v64[0].m_v1.m_z = v31->m_exitSegU.m_v1.m_z;
LABEL_34:
  bfx::GetClosestPtOnLineSeg(result: &v62, seg: v64, pos: startPos);
  v54 = v62.m_y;
  if ( (float)((float)((float)(v62.m_y - startPos->m_y) * (float)((float)v21 - startPos->m_x))
             - (float)((float)((float)v22 - startPos->m_y) * (float)(v62.m_x - startPos->m_x))) >= 0.0 )
  {
LABEL_32:
    *nextCornerIndexOut = v21;
    nextCornerIndexOut[1] = v22;
    nextCornerIndexOut[2] = v24;
    *cornerFlavorOut = v23;
    *a9 = 0;
  }
  else if ( (float)((float)((float)(v62.m_y - startPos->m_y) * (float)((float)v26 - startPos->m_x))
                  - (float)((float)((float)v28 - startPos->m_y) * (float)(v62.m_x - startPos->m_x))) <= 0.0 )
  {
LABEL_31:
    *nextCornerIndexOut = v26;
    nextCornerIndexOut[1] = v28;
    nextCornerIndexOut[2] = v29;
    *cornerFlavorOut = v25;
    *a9 = 1;
  }
  else
  {
    v55 = v62.m_z;
    *nextCornerIndexOut = v62.m_x;
    nextCornerIndexOut[1] = v54;
    nextCornerIndexOut[2] = v55;
LABEL_37:
    *cornerFlavorOut = v19;
    *a9 = 4;
  }
}


// ========================================================================
// ?SkipPastAnyLeftFanAreaExits@bfx@@YAHHABV?$Array@VAreaExitData@bfx@@@1@@Z
// EA  : 0x8328D3F0
// RVA : 0x0128D3F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SkipPastAnyLeftFanAreaExits(int startIndex, const bfx::Array<bfx::AreaExitData> *areaExits)
{
  int v2; // r11

  v2 = startIndex;
  if ( (*((_BYTE *)&areaExits->m_data[startIndex] + 44) & 0x80) != 0 )
  {
    do
    {
      ++startIndex;
      ++v2;
    }
    while ( startIndex < areaExits->m_size && (*((_BYTE *)&areaExits->m_data[v2] + 44) & 0x80) != 0 );
  }
  return startIndex;
}


// ========================================================================
// ?SkipPastAnyRightFanAreaExits@bfx@@YAHHABV?$Array@VAreaExitData@bfx@@@1@@Z
// EA  : 0x8328D440
// RVA : 0x0128D440
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SkipPastAnyRightFanAreaExits(int startIndex, const bfx::Array<bfx::AreaExitData> *areaExits)
{
  int v2; // r11

  v2 = startIndex;
  if ( (*((_BYTE *)&areaExits->m_data[startIndex] + 44) & 0x40) != 0 )
  {
    do
    {
      ++startIndex;
      ++v2;
    }
    while ( startIndex < areaExits->m_size && (*((_BYTE *)&areaExits->m_data[v2] + 44) & 0x40) != 0 );
  }
  return startIndex;
}


// ========================================================================
// ?GetMaxAreaPenaltyForSubsetOfPathAreas@bfx@@YAIHHABV?$Array@PAVArea@bfx@@@1@ABVPathSpec@1@@Z
// EA  : 0x8328D490
// RVA : 0x0128D490
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

unsigned int __fastcall bfx::GetMaxAreaPenaltyForSubsetOfPathAreas(
        int firstAreaIndex,
        int lastAreaIndex,
        const bfx::Array<bfx::Area *> *pathAreas,
        const bfx::PathSpec *pathSpec)
{
  unsigned int v6; // r30
  int v7; // r31
  int v8; // r29
  unsigned int MaxAreaPenalty; // r3

  v6 = 1;
  if ( firstAreaIndex <= lastAreaIndex )
  {
    v7 = firstAreaIndex;
    v8 = lastAreaIndex - firstAreaIndex + 1;
    do
    {
      MaxAreaPenalty = bfx::GetMaxAreaPenalty(pArea: pathAreas->m_data[v7], pathSpec);
      if ( MaxAreaPenalty > v6 )
        v6 = MaxAreaPenalty;
      --v8;
      ++v7;
    }
    while ( v8 != 0 );
  }
  return v6;
}


// ========================================================================
// ?GetMaxAreaPenaltyForAreas@bfx@@YAIABV?$Array@PAVArea@bfx@@@1@ABVPathSpec@1@@Z
// EA  : 0x8328D4F0
// RVA : 0x0128D4F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

unsigned int __fastcall bfx::GetMaxAreaPenaltyForAreas(
        const bfx::Array<bfx::Area *> *areas,
        const bfx::PathSpec *pathSpec)
{
  unsigned int v4; // r29
  int v5; // r28
  int v6; // r31
  unsigned int MaxAreaPenalty; // r3

  v4 = 1;
  v5 = 0;
  if ( areas->m_size > 0 )
  {
    v6 = 0;
    do
    {
      MaxAreaPenalty = bfx::GetMaxAreaPenalty(pArea: areas->m_data[v6], pathSpec);
      if ( MaxAreaPenalty > v4 )
        v4 = MaxAreaPenalty;
      ++v5;
      ++v6;
    }
    while ( v5 < areas->m_size );
  }
  return v4;
}


// ========================================================================
// ?IsCornerRebuildNeeded@SmartPath@bfx@@ABA_NXZ
// EA  : 0x8328D558
// RVA : 0x0128D558
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::IsCornerRebuildNeeded(bfx::SmartPath *this)
{
  unsigned int m_cornerDataTimestamp; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  if ( this->m_corners.m_size == 0 )
    return 1;
  m_cornerDataTimestamp = this->m_cornerDataTimestamp;
  if ( this->m_layerTimestamp > m_cornerDataTimestamp )
    return 1;
  if ( this->m_pathSpecTimestamp > m_cornerDataTimestamp )
    return 1;
  if ( this->m_pcoTimestamp > m_cornerDataTimestamp )
    return 1;
  if ( this->m_inputGoalDataTimestamp > m_cornerDataTimestamp )
    return 1;
  v3 = this->m_pathDataTimestamp <= m_cornerDataTimestamp;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?DistThroughCornersExceedsLimit@SmartPath@bfx@@ABA_NM@Z
// EA  : 0x8328D5B8
// RVA : 0x0128D5B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::DistThroughCornersExceedsLimit(bfx::SmartPath *this, double maxPathDist)
{
  int v2; // r9
  int m_size; // r7
  double v4; // fp11
  bfx::SPCorner *m_data; // r8
  double m_z; // fp8
  double m_y; // fp9
  int v8; // r11
  double m_x; // fp10
  double v10; // fp10
  double v11; // fp13
  double v12; // fp9
  double v13; // fp12
  double v14; // fp8

  v2 = 0;
  m_size = this->m_corners.m_size;
  v4 = 0.0;
  if ( m_size <= 0 )
    return 0;
  m_data = this->m_corners.m_data;
  m_z = this->m_snappedStartPos.m_z;
  m_y = this->m_snappedStartPos.m_y;
  v8 = 0;
  m_x = this->m_snappedStartPos.m_x;
  while ( 1 )
  {
    v10 = (float)(m_data[v8].m_pos.m_x - (float)m_x);
    v11 = m_data[v8].m_pos.m_y;
    v12 = (float)(m_data[v8].m_pos.m_y - (float)m_y);
    v13 = m_data[v8].m_pos.m_z;
    v14 = (float)(m_data[v8].m_pos.m_z - (float)m_z);
    v4 = (float)((float)__fsqrts((float)((float)((float)v10 * (float)v10)
                                       + (float)((float)((float)v14 * (float)v14) + (float)((float)v12 * (float)v12))))
               + (float)v4);
    if ( v4 > maxPathDist )
      break;
    ++v2;
    m_x = m_data[v8++].m_pos.m_x;
    m_y = v11;
    m_z = v13;
    if ( v2 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$PopFront@VSPCorner@bfx@@@bfx@@YAXAAV?$Array@VSPCorner@bfx@@@0@@Z
// EA  : 0x8328D820
// RVA : 0x0128D820
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PopFront<bfx::SPCorner>(bfx::Array<bfx::SPCorner> *myArray)
{
  int v1; // r9
  int v2; // r10
  bfx::SPCorner *v3; // r11

  v1 = 0;
  if ( myArray->m_size - 1 > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &myArray->m_data[v2++];
      v3->m_pos.m_x = v3[1].m_pos.m_x;
      v3->m_pos.m_y = v3[1].m_pos.m_y;
      v3->m_pos.m_z = v3[1].m_pos.m_z;
      v3->m_posU.m_x = v3[1].m_posU.m_x;
      v3->m_posU.m_y = v3[1].m_posU.m_y;
      v3->m_posU.m_z = v3[1].m_posU.m_z;
      v3->m_areaExitIndex = v3[1].m_areaExitIndex;
      v3->m_cornerFlavor = v3[1].m_cornerFlavor;
    }
    while ( v1 < myArray->m_size - 1 );
  }
  --myArray->m_size;
}


// ========================================================================
// ?IsShortcutCornerInArray@bfx@@YA_NHABV?$Array@PAVArea@bfx@@@1@W4CornerFlavor@1@ABV?$Array@VShortcutRecord@bfx@@@1@@Z
// EA  : 0x8328D8A8
// RVA : 0x0128D8A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::IsShortcutCornerInArray(
        int nextCornerIndex,
        const bfx::Array<bfx::Area *> *pathAreas,
        bfx::CornerFlavor cornerFlavor,
        const bfx::Array<bfx::ShortcutRecord> *skipShortcutRecords)
{
  int m_size; // r8
  int v5; // r9
  bfx::Area **v6; // r11
  bfx::Area *v7; // r7
  bfx::Area *v8; // r4
  bfx::ShortcutRecord *m_data; // r6
  int i; // r10
  bfx::ShortcutRecord *v11; // r11

  m_size = skipShortcutRecords->m_size;
  v5 = 0;
  v6 = &pathAreas->m_data[nextCornerIndex];
  v7 = *v6;
  v8 = v6[1];
  if ( m_size <= 0 )
    return 0;
  m_data = skipShortcutRecords->m_data;
  for ( i = 0; ; ++i )
  {
    v11 = &m_data[i];
    if ( m_data[i].m_pArea1 == v7 && v11->m_pArea2 == v8 && v11->m_cornerFlavor == cornerFlavor )
      break;
    if ( ++v5 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?CalcNextNCornersAndOptionallyCheckforShortcuts@bfx@@YAXABVVec3@1@ABV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@HMAAVShortcutInfo@1@PAV?$Array@VShortcutRecord@bfx@@@1@AAV?$Array@VSPCorner@bfx@@@1@@Z
// EA  : 0x8328D920
// RVA : 0x0128D920
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::CalcNextNCornersAndOptionallyCheckforShortcuts(
        const bfx::Vec3 *snappedStartPos,
        const bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits,
        int maxNumCorners,
        double maxPathDist,
        bfx::ShortcutInfo *shortcutInfo,
        bfx::Array<bfx::ShortcutRecord> *pSkipShortcutRecords,
        const bfx::Array<bfx::ShortcutRecord> *cornersOut,
        bfx::Array<bfx::SPCorner> *a9)
{
  int v16; // r4
  float m_z; // r6
  double v18; // fp28
  double v19; // fp31
  int v20; // r30
  double v21; // fp30
  double v22; // fp29
  bfx::AreaExitData *v23; // r31
  bfx::CornerFlavor v24; // r29
  int v25; // r10
  double v26; // fp13
  double v27; // fp11
  double v28; // fp9
  double m_x; // fp7
  double m_y; // fp4
  double v31; // fp8
  double v32; // fp5
  double v33; // fp3
  double v34; // fp6
  double v35; // fp13
  bfx::ExitType m_exitType; // r11
  bfx::HalfLink **m_pProxy; // r11
  bfx::HalfLink *v38; // r4
  int j; // r11
  int i; // r11
  bfx::Vec3 v41; // [sp+50h] [-130h] BYREF
  int v42; // [sp+5Ch] [-124h] BYREF
  bfx::Vec3 v43; // [sp+60h] [-120h] BYREF
  bfx::Vec3 v44; // [sp+70h] [-110h] BYREF
  float v45; // [sp+80h] [-100h] BYREF
  float v46; // [sp+84h] [-FCh]
  float v47; // [sp+88h] [-F8h]
  int v48; // [sp+8Ch] [-F4h] BYREF
  bfx::Vec3 v49; // [sp+90h] [-F0h] BYREF
  bfx::Vec3 v50; // [sp+A0h] [-E0h] BYREF
  bfx::SPCorner v51; // [sp+B0h] [-D0h] BYREF
  bfx::SPCorner v52; // [sp+D0h] [-B0h] BYREF

  a9->m_size = 0;
  bfx::TransformPosIntoUnwrappedCoordinatesOfArea(
    result: &v49,
    posG: snappedStartPos,
    pArea: *(bfx::Vec3 **)pathAreas->m_data,
    areaExitData: areaExits->m_data);
  v16 = 0;
  m_z = v49.m_z;
  v18 = 0.0;
  v41 = v49;
  if ( maxNumCorners > 0 )
  {
    do
    {
      if ( v18 >= maxPathDist )
        return;
      bfx::GetNextCorner(
        startPos: &v41,
        startIndex: v16,
        areaExits,
        maxShrinkDist: 0.0,
        pathStartPos: (const bfx::Vec3 *)LODWORD(m_z),
        nextCornerPosOut: &v49,
        nextCornerIndexOut: &v45,
        cornerFlavorOut: (bfx::CornerFlavor *)&v48,
        a9: &v42);
      v19 = v46;
      v20 = v48;
      v21 = v47;
      v22 = v45;
      v23 = &areaExits->m_data[v48];
      v18 = (float)((float)__fsqrts((float)((float)((float)(v45 - v41.m_x) * (float)(v45 - v41.m_x))
                                          + (float)((float)((float)(v47 - v41.m_z) * (float)(v47 - v41.m_z))
                                                  + (float)((float)(v46 - v41.m_y) * (float)(v46 - v41.m_y)))))
                  + (float)v18);
      if ( v23->m_exitType == EXIT_TYPE_LINK )
      {
        v24 = LINK_START_CORNER_FLAVOR;
        v42 = 2;
      }
      else
      {
        v24 = v42;
      }
      if ( HIBYTE(pSkipShortcutRecords->m_data) != 0
        && v48 < pathAreas->m_size - 1
        && (cornersOut == nullptr
         || (unsigned __int8)bfx::IsShortcutCornerInArray(
                               nextCornerIndex: v48,
                               pathAreas,
                               cornerFlavor: v24,
                               skipShortcutRecords: cornersOut) == 0) )
      {
        if ( v24 != LEFT_CORNER_FLAVOR )
        {
          if ( v24 != RIGHT_CORNER_FLAVOR )
            goto LABEL_15;
          v25 = *((_BYTE *)v23 + 44) & 0x10;
        }
        else
        {
          v25 = *((_BYTE *)v23 + 44) & 0x20;
        }
        if ( v25 != 0 )
        {
          pSkipShortcutRecords->m_size = v20;
          pSkipShortcutRecords->m_cap = v24;
          return;
        }
      }
LABEL_15:
      v26 = (float)((float)v19 - v23->m_exitSegU.m_v0.m_y);
      v27 = (float)((float)v21 - v23->m_exitSegU.m_v0.m_z);
      v28 = (float)((float)v22 - v23->m_exitSegU.m_v0.m_x);
      m_x = v23->m_exitUnitVec.m_x;
      m_y = v23->m_exitUnitVec.m_y;
      v31 = v23->m_exitUnitVec.m_z;
      v32 = v23->m_exitSeg.m_v0.m_x;
      v51.m_posU.m_x = v45;
      v33 = v23->m_exitSeg.m_v0.m_y;
      v51.m_areaExitIndex = v20;
      v34 = v23->m_exitSeg.m_v0.m_z;
      v51.m_cornerFlavor = v24;
      v51.m_posU.m_y = v46;
      v51.m_posU.m_z = v47;
      v35 = __fsqrts((float)((float)((float)v28 * (float)v28)
                           + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))));
      v43.m_x = (float)v32 + (float)((float)m_x * (float)v35);
      v43.m_y = (float)v33 + (float)((float)m_y * (float)v35);
      v43.m_z = (float)v34 + (float)((float)v31 * (float)v35);
      v51.m_pos = v43;
      bfx::Array<bfx::SPCorner>::push_back(this: a9, val: &v51);
      m_exitType = v23->m_exitType;
      if ( m_exitType == EXIT_TYPE_GOAL )
        return;
      if ( m_exitType != EXIT_TYPE_SURFACE )
      {
        m_pProxy = (bfx::HalfLink **)v23->m_exitLink.m_pProxy;
        if ( m_pProxy != nullptr )
          v38 = *m_pProxy;
        else
          v38 = nullptr;
        if ( v38 == nullptr )
          return;
        bfx::GetLinkOutputPos(result: &v50, pLink: v38, posOnLinkStart: &v43);
        bfx::TransformPosIntoUnwrappedCoordinatesOfArea(
          result: &v44,
          posG: &v50,
          pArea: (bfx::Vec3 *)pathAreas->m_data[v20 + 1],
          areaExitData: &areaExits->m_data[v20 + 1]);
        v52.m_areaExitIndex = v20;
        v52.m_cornerFlavor = LINK_END_CORNER_FLAVOR;
        v52.m_pos = v50;
        v52.m_posU = v44;
        bfx::Array<bfx::SPCorner>::push_back(this: a9, val: &v52);
        v41.m_x = v44.m_x;
        v41.m_y = v44.m_y;
        v41.m_z = v44.m_z;
      }
      else
      {
        v41.m_x = v22;
        v41.m_y = v19;
        v41.m_z = v21;
      }
      v16 = v20 + 1;
      if ( v24 != LEFT_CORNER_FLAVOR )
      {
        if ( v24 == RIGHT_CORNER_FLAVOR )
        {
          for ( i = v16;
                (*((_BYTE *)&areaExits->m_data[i] + 44) & 0x40) != 0;
                LODWORD(m_z) = *((_BYTE *)&areaExits->m_data[i] + 44) & 0x40 )
          {
            ++v16;
            ++i;
            if ( v16 >= areaExits->m_size )
              break;
          }
        }
      }
      else
      {
        for ( j = v16;
              (*((_BYTE *)&areaExits->m_data[j] + 44) & 0x80) != 0;
              LODWORD(m_z) = *((_BYTE *)&areaExits->m_data[j] + 44) & 0x80 )
        {
          ++v16;
          ++j;
          if ( v16 >= areaExits->m_size )
            break;
        }
      }
    }
    while ( a9->m_size < maxNumCorners );
  }
}


// ========================================================================
// ?GetShortcutAreaSeries@bfx@@YA_NHABV?$Array@PAVArea@bfx@@@1@_NAAHAAV21@@Z
// EA  : 0x8328DD10
// RVA : 0x0128DD10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::GetShortcutAreaSeries(
        int startAreaIndex,
        const bfx::Array<bfx::Area *> *pathAreas,
        bool checkLeftVert,
        int *endAreaIndexOut,
        bfx::Array<bfx::Space *> *shortcutAreasOut)
{
  int v5; // r30
  bfx::Area **v7; // r11
  int v8; // r31
  bfx::Area *v9; // r24
  unsigned __int8 v13; // r25
  bfx::EdgeCursor v14; // r11
  int v15; // r28
  bfx::Area *m_pArea; // [sp+50h] [-80h] BYREF
  bfx::EdgeCursor v18; // [sp+58h] [-78h] BYREF
  bfx::EdgeCursor v19; // [sp+60h] [-70h] BYREF
  bfx::EdgeCursor v20; // [sp+68h] [-68h] BYREF

  v5 = startAreaIndex;
  *endAreaIndexOut = -1;
  v7 = &pathAreas->m_data[startAreaIndex];
  v8 = startAreaIndex;
  v9 = *v7;
  bfx::GetSharedEdgeCC(result: &v20, pArea0: *v7, pArea1: v7[1]);
  v13 = 0;
  v18 = v20;
  do
  {
    bfx::EdgeCursor::GetSibling(this: &v19, result: &v18);
    if ( v19.m_pArea == nullptr )
    {
      *endAreaIndexOut = -1;
      shortcutAreasOut->m_size = 0;
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)shortcutAreasOut->m_data);
      shortcutAreasOut->m_data = nullptr;
      shortcutAreasOut->m_cap = 0;
      return 0;
    }
    v14.m_i = v19.m_i;
    v14.m_pArea = (bfx::Area *)checkLeftVert;
    v18 = v14;
    if ( checkLeftVert )
    {
      v18.m_i = v19.m_i - 1;
      if ( v19.m_i - 1 < 0 )
        v18.m_i = (*(_DWORD *)(checkLeftVert + 0x28) & 0x7F) - 1;
    }
    else
    {
      v18.m_i = (((unsigned int)(v19.m_i + 1) - __PAIR64__((unsigned int)(v19.m_i + 1) >> 31, MEMORY[0x2B] & 0x7F)) >> 32)
              & (v19.m_i + 1);
    }
    v15 = v13;
    ++v8;
    ++v5;
    if ( v13 != 0 )
      goto LABEL_13;
    if ( v8 > pathAreas->m_size - 1 || (bfx::Area *)checkLeftVert != pathAreas->m_data[v5] )
      v13 = 1;
    v15 = v13;
    if ( v13 != 0 )
    {
      *endAreaIndexOut = v8 - 1;
      bfx::Array<bfx::Portal *>::push_back(this: shortcutAreasOut, val: (bfx::Space *const *)&pathAreas->m_data[v5 - 1]);
      v14.m_pArea = v18.m_pArea;
LABEL_13:
      m_pArea = v14.m_pArea;
      bfx::Array<bfx::Portal *>::push_back(this: shortcutAreasOut, val: (bfx::Space *const *)&m_pArea);
      v14.m_pArea = v18.m_pArea;
    }
  }
  while ( v14.m_pArea != v9 );
  if ( v15 != 0 )
  {
    bfx::Array<bfx::Area *>::reverse(this: (bfx::Array<bfx::Area *> *)shortcutAreasOut);
    return 1;
  }
  else
  {
    *endAreaIndexOut = -1;
    bfx::Array<bfx::HoleRecord>::clear(this: (bfx::Array<bfx::QueuedTri> *)shortcutAreasOut);
    return 0;
  }
}


// ========================================================================
// ?SpliceShortcutIntoPath@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@HHAAV21@@Z
// EA  : 0x8328DED0
// RVA : 0x0128DED0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SpliceShortcutIntoPath(
        const bfx::Array<bfx::Area *> *shortcutAreas,
        int startPathIndex,
        int endPathIndex,
        bfx::Array<bfx::Space *> *pathAreas)
{
  int m_size; // r8
  int v6; // r7
  int v10; // r9
  int v11; // r11
  int v12; // r10
  bfx::Area *v13; // r6
  int v14; // r9
  int v15; // r11
  int v16; // r10
  bfx::Area *v17; // r4
  int v18; // r11
  int v19; // r8
  int v20; // r10
  int v21; // r9
  bfx::Area *v22; // r6
  int i; // ctr
  int v24; // r29
  int v25; // r28
  int v26; // r11
  int v27; // r10
  int v28; // r11
  int v29; // ctr
  bfx::Area *v30; // r8
  int v31; // r9
  int v32; // r11
  int v33; // r10
  bfx::Area *v34; // r6
  bfx::Space *v35; // [sp+50h] [-40h] BYREF

  m_size = shortcutAreas->m_size;
  v6 = endPathIndex - startPathIndex + 1;
  if ( m_size == v6 )
  {
    v10 = 0;
    if ( m_size > 0 )
    {
      v11 = 0;
      v12 = startPathIndex;
      do
      {
        ++v10;
        v13 = shortcutAreas->m_data[v11++];
        pathAreas->m_data[v12++] = (bfx::Space *)v13;
      }
      while ( v10 < shortcutAreas->m_size );
    }
  }
  else if ( m_size >= v6 )
  {
    if ( m_size > v6 )
    {
      v24 = m_size - v6;
      if ( m_size - v6 > 0 )
      {
        v25 = m_size - v6;
        v35 = nullptr;
        do
        {
          bfx::Array<bfx::Portal *>::push_back(this: pathAreas, val: &v35);
          --v25;
        }
        while ( v25 != 0 );
      }
      v26 = pathAreas->m_size - 1;
      if ( v26 > v24 + endPathIndex )
      {
        v27 = v26;
        v29 = v26 - (v24 + endPathIndex);
        v28 = v26 - v24;
        do
        {
          v30 = (bfx::Area *)pathAreas->m_data[v28--];
          pathAreas->m_data[v27--] = (bfx::Space *)v30;
          --v29;
        }
        while ( v29 != 0 );
      }
      v31 = 0;
      if ( shortcutAreas->m_size > 0 )
      {
        v32 = 0;
        v33 = startPathIndex;
        do
        {
          ++v31;
          v34 = shortcutAreas->m_data[v32++];
          pathAreas->m_data[v33++] = (bfx::Space *)v34;
        }
        while ( v31 < shortcutAreas->m_size );
      }
    }
  }
  else
  {
    v14 = 0;
    if ( m_size > 0 )
    {
      v15 = 0;
      v16 = startPathIndex;
      do
      {
        ++v14;
        v17 = shortcutAreas->m_data[v15++];
        pathAreas->m_data[v16++] = (bfx::Space *)v17;
      }
      while ( v14 < shortcutAreas->m_size );
    }
    v18 = endPathIndex + 1;
    v19 = v6 - m_size;
    if ( endPathIndex + 1 < pathAreas->m_size )
    {
      v20 = v18;
      v21 = v18 - v19;
      do
      {
        ++v18;
        v22 = (bfx::Area *)pathAreas->m_data[v20++];
        pathAreas->m_data[v21++] = (bfx::Space *)v22;
      }
      while ( v18 < pathAreas->m_size );
    }
    if ( v19 > 0 )
    {
      for ( i = v19; i != 0; --i )
        --pathAreas->m_size;
    }
  }
}


// ========================================================================
// ?PruneOffshoots@bfx@@YAXHAAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x8328E0A8
// RVA : 0x0128E0A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PruneOffshoots(int indexOfFirstAreaToCheck, bfx::Array<bfx::Area *> *pathAreas)
{
  int m_size; // r30
  int v3; // r11
  int v4; // r6
  int i; // r8
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r9
  int v10; // r10
  bfx::Area *v11; // r6

  m_size = pathAreas->m_size;
  v3 = indexOfFirstAreaToCheck;
  v4 = indexOfFirstAreaToCheck + 15;
  if ( indexOfFirstAreaToCheck + 15 >= m_size - 1 )
    v4 = m_size - 1;
  if ( indexOfFirstAreaToCheck <= v4 - 1 )
  {
    for ( i = indexOfFirstAreaToCheck + 1; ; ++i )
    {
      v6 = ++v3;
      if ( v3 <= v4 )
        break;
LABEL_9:
      if ( v3 > v4 - 1 )
        return;
    }
    v7 = i * 4;
    while ( *(bfx::Area **)((char *)pathAreas->m_data + v7) != pathAreas->m_data[i - 1] )
    {
      ++v6;
      v7 += 4;
      if ( v6 > v4 )
        goto LABEL_9;
    }
    v8 = v6 - v3 + 1;
    if ( v3 < m_size - v8 )
    {
      v9 = v3;
      v10 = v6 + 1;
      do
      {
        ++v3;
        v11 = pathAreas->m_data[v10++];
        pathAreas->m_data[v9++] = v11;
      }
      while ( v3 < pathAreas->m_size - v8 );
    }
    pathAreas->m_size -= v8;
  }
}


// ========================================================================
// ?AddIntermediateCornersBetweenAreaExits@bfx@@YAXABVVec3@1@0HH0AAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@ABVCalcCornersSpec@1@AAMAAV?$Array@VSmartPathCorner@bfx@@@1@@Z
// EA  : 0x8328E188
// RVA : 0x0128E188
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::AddIntermediateCornersBetweenAreaExits(
        const bfx::Vec3 *startPosU,
        const bfx::Vec3 *endPosU,
        int startIndex,
        int endIndex,
        const bfx::Vec3 *snappedStartPos,
        bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits,
        const bfx::CalcCornersSpec *calcCornersSpec,
        float *pathDistSoFar,
        bfx::Array<bfx::SmartPathCorner> *cornersOut,
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
        float *a28,
        int a29,
        bfx::Array<bfx::SmartPathCorner> *a30)
{
  int v30; // r25
  int v38; // r26
  int v39; // r27
  bfx::AreaExitData *v40; // r31
  bfx::Area **m_data; // r11
  double v42; // fp12
  double v43; // fp9
  double v44; // fp6
  double m_x; // fp4
  double m_y; // fp1
  bfx::Area *v47; // r10
  double m_z; // fp5
  double v49; // fp2
  double v50; // fp3
  double v51; // fp10
  int m_size; // r11
  double v53; // fp9
  double v54; // fp7
  double v55; // fp5
  double v56; // fp0
  int v57; // r11
  int v58; // r9
  int v59; // r11
  float *p_m_x; // r10
  double v61; // fp11
  double v62; // fp8
  double v63; // fp5
  bfx::Vec3 v64; // [sp+60h] [-B0h] BYREF
  bfx::SmartPathCorner v65; // [sp+70h] [-A0h] BYREF

  v30 = startIndex + 1;
  if ( startIndex + 1 < endIndex )
  {
    v38 = v30;
    v39 = v30;
    while ( 1 )
    {
      v40 = &areaExits->m_data[v39];
      bfx::GetClosestPtOnLineSegAToLineB(
        result: &v64,
        startA: &v40->m_exitSegU.m_v0,
        endA: &v40->m_exitSegU.m_v1,
        startB: startPosU,
        endB: endPosU);
      m_data = pathAreas->m_data;
      v42 = (float)(v64.m_y - v40->m_exitSegU.m_v0.m_y);
      v43 = (float)(v64.m_z - v40->m_exitSegU.m_v0.m_z);
      v65.m_isGoal = false;
      v44 = (float)(v64.m_x - v40->m_exitSegU.m_v0.m_x);
      v65.m_linkType = SMART_PATH_CORNER_NOT_A_LINK;
      m_x = v40->m_exitUnitVec.m_x;
      m_y = v40->m_exitUnitVec.m_y;
      v47 = m_data[v38];
      m_z = v40->m_exitUnitVec.m_z;
      v65.m_pHalfLink = nullptr;
      v49 = v40->m_exitSeg.m_v0.m_x;
      v50 = v40->m_exitSeg.m_v0.m_z;
      v65.m_pArea = v47;
      v51 = __fsqrts((float)((float)((float)v44 * (float)v44)
                           + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))));
      v65.m_pos.m_y = v40->m_exitSeg.m_v0.m_y + (float)((float)m_y * (float)v51);
      v65.m_pos.m_z = (float)v50 + (float)((float)m_z * (float)v51);
      v65.m_pos.m_x = (float)v49 + (float)((float)m_x * (float)v51);
      bfx::Array<bfx::SmartPathCorner>::push_back(this: a30, val: &v65);
      m_size = a30->m_size;
      if ( m_size == 1 )
      {
        v53 = (float)(a30->m_data->m_pos.m_y - snappedStartPos->m_y);
        v54 = (float)(a30->m_data->m_pos.m_z - snappedStartPos->m_z);
        v55 = (float)(a30->m_data->m_pos.m_x - snappedStartPos->m_x);
        v56 = (float)((float)__fsqrts((float)((float)((float)v55 * (float)v55)
                                            + (float)((float)((float)v54 * (float)v54) + (float)((float)v53 * (float)v53))))
                    + *a28);
      }
      else
      {
        if ( m_size < 2 )
          goto LABEL_8;
        v57 = a30->m_size;
        v58 = v57 - 2;
        v59 = (int)&a30->m_data[v57];
        p_m_x = &a30->m_data[v58].m_pos.m_x;
        v61 = (float)(*(float *)(v59 - 24) - p_m_x[1]);
        v62 = (float)(*(float *)(v59 - 20) - p_m_x[2]);
        v63 = (float)(*(float *)(v59 - 28) - *p_m_x);
        v56 = (float)((float)__fsqrts((float)((float)((float)v63 * (float)v63)
                                            + (float)((float)((float)v62 * (float)v62) + (float)((float)v61 * (float)v61))))
                    + *a28);
      }
      *a28 = v56;
LABEL_8:
      if ( a30->m_size < calcCornersSpec->m_maxNumCorners && *a28 <= (double)calcCornersSpec->m_maxPathDist )
      {
        ++v30;
        ++v39;
        ++v38;
        if ( v30 < endIndex )
          continue;
      }
      return;
    }
  }
}


// ========================================================================
// ?AddOutputCornerForInternalCorner@bfx@@YAXABVSPCorner@1@AAMABVVec3@1@AAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@AAV?$Array@VSmartPathCorner@bfx@@@1@@Z
// EA  : 0x8328E398
// RVA : 0x0128E398
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::AddOutputCornerForInternalCorner(
        const bfx::SPCorner *corner,
        float *pathDistSoFar,
        const bfx::Vec3 *snappedStartPos,
        bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits,
        bfx::Array<bfx::SmartPathCorner> *cornersOut)
{
  bfx::CornerFlavor m_cornerFlavor; // r10
  bfx::SmartPathCornerLinkType v10; // r5
  bool v11; // r29
  int m_areaExitIndex; // r10
  bfx::Handle<bfx::HalfLink> *p_m_exitLink; // r8
  bfx::HalfLink *m_pTarget; // r9
  bfx::Area **m_data; // r8
  int v16; // r7
  float m_x; // r6
  float m_y; // r10
  float m_z; // r11
  bfx::Area *v20; // r8
  int m_size; // r11
  double v22; // fp9
  double v23; // fp7
  double v24; // fp5
  int v25; // r11
  int v26; // r9
  bfx::SmartPathCorner *v27; // r11
  bfx::SmartPathCorner *v28; // r10
  double v29; // fp11
  double v30; // fp8
  double v31; // fp5
  bfx::SmartPathCorner v32; // [sp+50h] [-50h] BYREF

  m_cornerFlavor = corner->m_cornerFlavor;
  v10 = SMART_PATH_CORNER_NOT_A_LINK;
  v11 = (_cntlzw(m_cornerFlavor - 4) & 0x20) != 0;
  if ( m_cornerFlavor == LINK_START_CORNER_FLAVOR )
  {
    v10 = SMART_PATH_CORNER_LINK_START;
  }
  else if ( m_cornerFlavor == LINK_END_CORNER_FLAVOR )
  {
    v10 = SMART_PATH_CORNER_LINK_END;
  }
  m_areaExitIndex = corner->m_areaExitIndex;
  p_m_exitLink = &areaExits->m_data[m_areaExitIndex].m_exitLink;
  if ( p_m_exitLink->m_pProxy != nullptr )
    m_pTarget = (bfx::HalfLink *)p_m_exitLink->m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  m_data = pathAreas->m_data;
  v16 = m_areaExitIndex;
  m_x = corner->m_pos.m_x;
  m_y = corner->m_pos.m_y;
  m_z = corner->m_pos.m_z;
  v32.m_isGoal = v11;
  v20 = m_data[v16];
  v32.m_pos.m_x = m_x;
  v32.m_pos.m_y = m_y;
  v32.m_linkType = v10;
  v32.m_pos.m_z = m_z;
  v32.m_pHalfLink = m_pTarget;
  v32.m_pArea = v20;
  bfx::Array<bfx::SmartPathCorner>::push_back(this: cornersOut, val: &v32);
  m_size = cornersOut->m_size;
  if ( m_size == 1 )
  {
    v22 = (float)(cornersOut->m_data->m_pos.m_y - snappedStartPos->m_y);
    v23 = (float)(cornersOut->m_data->m_pos.m_z - snappedStartPos->m_z);
    v24 = (float)(cornersOut->m_data->m_pos.m_x - snappedStartPos->m_x);
    *pathDistSoFar = (float)__fsqrts((float)((float)((float)v24 * (float)v24)
                                           + (float)((float)((float)v23 * (float)v23) + (float)((float)v22 * (float)v22))))
                   + *pathDistSoFar;
  }
  else if ( m_size >= 2 )
  {
    v25 = cornersOut->m_size;
    v26 = v25 - 2;
    v27 = &cornersOut->m_data[v25];
    v28 = &cornersOut->m_data[v26];
    v29 = (float)(v27[-1].m_pos.m_y - v28->m_pos.m_y);
    v30 = (float)(v27[-1].m_pos.m_z - v28->m_pos.m_z);
    v31 = (float)(v27[-1].m_pos.m_x - v28->m_pos.m_x);
    *pathDistSoFar = (float)__fsqrts((float)((float)((float)v31 * (float)v31)
                                           + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29))))
                   + *pathDistSoFar;
  }
}


// ========================================================================
// ?FillOutputCornerArrayFromCachedCorners@bfx@@YAXABVVec3@1@AAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@ABV?$Array@VSPCorner@bfx@@@1@ABVCalcCornersSpec@1@MAAV?$Array@VSmartPathCorner@bfx@@@1@@Z
// EA  : 0x8328E520
// RVA : 0x0128E520
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::FillOutputCornerArrayFromCachedCorners(
        const bfx::Vec3 *snappedStartPos,
        bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits,
        const bfx::Array<bfx::SPCorner> *realCorners,
        const bfx::CalcCornersSpec *calcCornersSpec,
        double maxShrinkDist,
        bfx::Array<bfx::SmartPathCorner> *cornersOut,
        bfx::Array<bfx::SmartPathCorner> *a8)
{
  int v8; // r25
  int m_size; // r10
  int m_maxNumCorners; // r26
  double m_maxPathDist; // fp31
  bool v18; // r21
  int v19; // r22
  bfx::Area **m_data; // r11
  float m_x; // r10
  float m_y; // r9
  float m_z; // r8
  bfx::Area *v24; // r7
  bfx::Vec3 *v25; // r3
  bfx::SPCorner *v26; // r29
  bool v27; // cr56
  int v28; // r3
  bfx::CornerFlavor m_cornerFlavor; // r11
  bfx::Area **v30; // r11
  float v31; // r10
  float v32; // r9
  float v33; // r8
  bfx::Area *v34; // r7
  int v35; // r29
  float *v36; // [sp+8h] [-118h]
  bfx::Array<bfx::SmartPathCorner> *v37; // [sp+Ch] [-114h]
  int v38; // [sp+10h] [-110h]
  int v39; // [sp+14h] [-10Ch]
  int v40; // [sp+18h] [-108h]
  int v41; // [sp+1Ch] [-104h]
  int v42; // [sp+20h] [-100h]
  int v43; // [sp+24h] [-FCh]
  int v44; // [sp+28h] [-F8h]
  int v45; // [sp+2Ch] [-F4h]
  int v46; // [sp+30h] [-F0h]
  int v47; // [sp+34h] [-ECh]
  int v48; // [sp+38h] [-E8h]
  int v49; // [sp+3Ch] [-E4h]
  int v50; // [sp+40h] [-E0h]
  int v51; // [sp+44h] [-DCh]
  int v52; // [sp+48h] [-D8h]
  int v53; // [sp+4Ch] [-D4h]
  int v54; // [sp+50h] [-D0h]
  int v55; // [sp+58h] [-C8h]
  float v56[2]; // [sp+60h] [-C0h] BYREF
  bfx::Vec3 v57; // [sp+68h] [-B8h] BYREF
  bfx::Vec3 v58[2]; // [sp+78h] [-A8h] BYREF
  bfx::SmartPathCorner v59; // [sp+90h] [-90h] BYREF

  v8 = 0;
  a8->m_size = 0;
  if ( pathAreas->m_size != 0 )
  {
    m_size = realCorners->m_size;
    if ( m_size != 0 )
    {
      m_maxNumCorners = calcCornersSpec->m_maxNumCorners;
      m_maxPathDist = calcCornersSpec->m_maxPathDist;
      v56[0] = 0.0;
      v18 = maxShrinkDist == 0.0;
      if ( calcCornersSpec->m_addCornersAtEveryAreaBoundary )
      {
        v19 = 0;
        if ( m_size > 0 )
        {
          while ( 1 )
          {
            if ( v19 != 0 )
            {
              v26 = &realCorners->m_data[v19];
              v57.m_x = v26[-1].m_posU.m_x;
              v57.m_y = v26[-1].m_posU.m_y;
              v57.m_z = v26[-1].m_posU.m_z;
              v28 = v26[-1].m_areaExitIndex + 1;
              if ( v18 )
              {
                m_cornerFlavor = v26[-1].m_cornerFlavor;
                if ( m_cornerFlavor != LEFT_CORNER_FLAVOR )
                {
                  if ( m_cornerFlavor == RIGHT_CORNER_FLAVOR )
                    v28 = bfx::SkipPastAnyRightFanAreaExits(startIndex: v28, areaExits);
                }
                else
                {
                  v28 = bfx::SkipPastAnyLeftFanAreaExits(startIndex: v28, areaExits);
                }
              }
              bfx::AddIntermediateCornersBetweenAreaExits(
                startPosU: &v57,
                endPosU: &v26->m_posU,
                startIndex: v28 - 1,
                endIndex: v26->m_areaExitIndex,
                snappedStartPos,
                pathAreas,
                areaExits,
                calcCornersSpec,
                pathDistSoFar: v36,
                cornersOut: v37,
                a11: v38,
                a12: v39,
                a13: v40,
                a14: v41,
                a15: v42,
                a16: v43,
                a17: v44,
                a18: v45,
                a19: v46,
                a20: v47,
                a21: v48,
                a22: v49,
                a23: v50,
                a24: v51,
                a25: v52,
                a26: v53,
                a27: v54,
                a28: v56,
                a29: v55,
                a30: a8);
              v27 = a8->m_size < m_maxNumCorners;
            }
            else
            {
              if ( calcCornersSpec->m_addCornerAtStartingPosition )
              {
                m_data = pathAreas->m_data;
                m_x = snappedStartPos->m_x;
                m_y = snappedStartPos->m_y;
                m_z = snappedStartPos->m_z;
                v59.m_isGoal = false;
                v24 = *m_data;
                v59.m_pos.m_x = m_x;
                v59.m_pos.m_y = m_y;
                v59.m_linkType = SMART_PATH_CORNER_NOT_A_LINK;
                v59.m_pos.m_z = m_z;
                v59.m_pHalfLink = nullptr;
                v59.m_pArea = v24;
                bfx::Array<bfx::SmartPathCorner>::push_back(this: a8, val: &v59);
                if ( a8->m_size >= m_maxNumCorners )
                  return;
              }
              v25 = bfx::TransformPosIntoUnwrappedCoordinatesOfArea(
                      result: v58,
                      posG: snappedStartPos,
                      pArea: *(bfx::Vec3 **)pathAreas->m_data,
                      areaExitData: areaExits->m_data);
              v57.m_x = v25->m_x;
              v26 = realCorners->m_data;
              v57.m_y = v25->m_y;
              v57.m_z = v25->m_z;
              bfx::AddIntermediateCornersBetweenAreaExits(
                startPosU: &v57,
                endPosU: &v26->m_posU,
                startIndex: -1,
                endIndex: v26->m_areaExitIndex,
                snappedStartPos,
                pathAreas,
                areaExits,
                calcCornersSpec,
                pathDistSoFar: v36,
                cornersOut: v37,
                a11: v38,
                a12: v39,
                a13: v40,
                a14: v41,
                a15: v42,
                a16: v43,
                a17: v44,
                a18: v45,
                a19: v46,
                a20: v47,
                a21: v48,
                a22: v49,
                a23: v50,
                a24: v51,
                a25: v52,
                a26: v53,
                a27: v54,
                a28: v56,
                a29: v55,
                a30: a8);
              v27 = a8->m_size < m_maxNumCorners;
            }
            if ( v27 && v56[0] < m_maxPathDist )
            {
              bfx::AddOutputCornerForInternalCorner(
                corner: v26,
                pathDistSoFar: v56,
                snappedStartPos,
                pathAreas,
                areaExits,
                cornersOut: a8);
              if ( a8->m_size < m_maxNumCorners && v56[0] < m_maxPathDist && ++v19 < realCorners->m_size )
                continue;
            }
            return;
          }
        }
      }
      else
      {
        if ( !calcCornersSpec->m_addCornerAtStartingPosition )
          goto LABEL_23;
        v30 = pathAreas->m_data;
        v31 = snappedStartPos->m_x;
        v32 = snappedStartPos->m_y;
        v33 = snappedStartPos->m_z;
        v59.m_isGoal = false;
        v34 = *v30;
        v59.m_pos.m_x = v31;
        v59.m_pos.m_y = v32;
        v59.m_linkType = SMART_PATH_CORNER_NOT_A_LINK;
        v59.m_pos.m_z = v33;
        v59.m_pHalfLink = nullptr;
        v59.m_pArea = v34;
        bfx::Array<bfx::SmartPathCorner>::push_back(this: a8, val: &v59);
        if ( a8->m_size < m_maxNumCorners )
        {
LABEL_23:
          if ( realCorners->m_size > 0 )
          {
            v35 = 0;
            do
            {
              bfx::AddOutputCornerForInternalCorner(
                corner: &realCorners->m_data[v35],
                pathDistSoFar: v56,
                snappedStartPos,
                pathAreas,
                areaExits,
                cornersOut: a8);
              if ( a8->m_size >= m_maxNumCorners )
                break;
              if ( v56[0] >= m_maxPathDist )
                break;
              ++v8;
              ++v35;
            }
            while ( v8 < realCorners->m_size );
          }
        }
      }
    }
  }
}


// ========================================================================
// ?SetStartData@SmartPath@bfx@@QAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x8328E830
// RVA : 0x0128E830
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::SetStartData(bfx::SmartPath *this, const bfx::Vec3 *startPos, bfx::Area *pStartArea)
{
  double v3; // fp13
  double v5; // fp0
  double v6; // fp12
  bfx::AreaProxy *m_pProxy; // r9
  bfx::Area *m_pArea; // r9
  unsigned int v9; // r11

  if ( this->m_inputStartDataTimestamp == bfx::UNINITIALIZED_TIMESTAMP
    || (v5 = (float)(startPos->m_x - this->m_inputStartPos.m_x),
        v3 = (float)(startPos->m_y - this->m_inputStartPos.m_y),
        v6 = (float)(startPos->m_z - this->m_inputStartPos.m_z),
        (float)((float)((float)v5 * (float)v5) + (float)((float)((float)v6 * (float)v6) + (float)((float)v3 * (float)v3))) > 1.0842022e-19)
    || ((m_pProxy = this->m_inputStartArea.m_pProxy) == nullptr ? (m_pArea = nullptr) : (m_pArea = m_pProxy->m_pArea),
        pStartArea != m_pArea) )
  {
    this->m_inputStartPos = *startPos;
    bfx::Handle<bfx::Area>::operator=(this: &this->m_inputStartArea, pArea: pStartArea);
    v9 = this->m_curTimestamp + 1;
    this->m_curTimestamp = v9;
    this->m_inputStartDataTimestamp = v9;
  }
}


// ========================================================================
// ?SetGoalData@SmartPath@bfx@@QAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x8328E908
// RVA : 0x0128E908
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::SetGoalData(bfx::SmartPath *this, const bfx::Vec3 *goalPos, bfx::Area *pGoalArea)
{
  double v3; // fp13
  double v5; // fp0
  double v6; // fp12
  bfx::AreaProxy *m_pProxy; // r9
  bfx::Area *m_pArea; // r9
  unsigned int v9; // r11

  if ( this->m_inputGoalDataTimestamp == bfx::UNINITIALIZED_TIMESTAMP
    || (v5 = (float)(goalPos->m_x - this->m_inputGoalPos.m_x),
        v3 = (float)(goalPos->m_y - this->m_inputGoalPos.m_y),
        v6 = (float)(goalPos->m_z - this->m_inputGoalPos.m_z),
        (float)((float)((float)v5 * (float)v5) + (float)((float)((float)v6 * (float)v6) + (float)((float)v3 * (float)v3))) > 1.0842022e-19)
    || ((m_pProxy = this->m_inputGoalArea.m_pProxy) == nullptr ? (m_pArea = nullptr) : (m_pArea = m_pProxy->m_pArea),
        pGoalArea != m_pArea) )
  {
    this->m_inputGoalPos = *goalPos;
    bfx::Handle<bfx::Area>::operator=(this: &this->m_inputGoalArea, pArea: pGoalArea);
    v9 = this->m_curTimestamp + 1;
    this->m_curTimestamp = v9;
    this->m_inputGoalDataTimestamp = v9;
  }
}


// ========================================================================
// ?RebuildSnappedStartDataIfNeeded@SmartPath@bfx@@AAA_NXZ
// EA  : 0x8328E9E0
// RVA : 0x0128E9E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::RebuildSnappedStartDataIfNeeded(bfx::SmartPath *this)
{
  unsigned int m_inputStartDataTimestamp; // r10
  unsigned int m_snappedStartDataProcessedTimestamp; // r11
  bfx::AreaProxy *v5; // r11
  bfx::Volume *m_pArea; // r30
  bfx::Vec3 *p_m_inputStartPos; // r5
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Vec3 *ClosestPosInArea; // r3
  bfx::Area *v10; // r4
  double m_z; // fp9
  unsigned int v12; // r30
  double m_y; // fp10
  double m_x; // fp11
  unsigned int m_snappedStartPosChangedTimestamp; // r9
  unsigned int v16; // r10
  double v17; // fp12
  double v18; // fp13
  double v19; // fp0
  bfx::AreaProxy *v20; // r11
  bfx::Area *v21; // r11
  bfx::Vec3 v22[5]; // [sp+50h] [-40h] BYREF

  m_inputStartDataTimestamp = this->m_inputStartDataTimestamp;
  if ( m_inputStartDataTimestamp == bfx::UNINITIALIZED_TIMESTAMP )
    return 0;
  m_snappedStartDataProcessedTimestamp = this->m_snappedStartDataProcessedTimestamp;
  if ( this->m_layerTimestamp > m_snappedStartDataProcessedTimestamp
    || this->m_pathSpecTimestamp > m_snappedStartDataProcessedTimestamp
    || m_inputStartDataTimestamp > m_snappedStartDataProcessedTimestamp )
  {
    m_pProxy = this->m_inputStartArea.m_pProxy;
    if ( m_pProxy != nullptr )
      m_pArea = (bfx::Volume *)m_pProxy->m_pArea;
    else
      m_pArea = nullptr;
    if ( m_pArea == nullptr || (unsigned int)m_pArea->m_portals.m_cap >> 27 != this->m_layer )
      m_pArea = bfx::Planner::GetClosestArea(
                  this: this->m_pPlanner,
                  pos: &this->m_inputStartPos,
                  layerNum: this->m_layer,
                  pathSpec: &this->m_pathSpec);
    if ( m_pArea == nullptr )
      return 0;
    p_m_inputStartPos = &this->m_inputStartPos;
LABEL_18:
    ClosestPosInArea = bfx::GetClosestPosInArea(
                         result: v22,
                         pArea: (bfx::Vec3 *)m_pArea,
                         pos: p_m_inputStartPos,
                         pEdgeIndexOut: nullptr);
    v10 = (bfx::Area *)m_pArea;
    m_z = ClosestPosInArea->m_z;
    v12 = this->m_curTimestamp + 1;
    m_y = ClosestPosInArea->m_y;
    m_x = ClosestPosInArea->m_x;
    m_snappedStartPosChangedTimestamp = this->m_snappedStartPosChangedTimestamp;
    this->m_curTimestamp = v12;
    this->m_snappedStartDataProcessedTimestamp = v12;
    v16 = bfx::UNINITIALIZED_TIMESTAMP;
    if ( m_snappedStartPosChangedTimestamp == bfx::UNINITIALIZED_TIMESTAMP
      || (v19 = (float)(this->m_snappedStartPos.m_x - (float)m_x),
          v18 = (float)(this->m_snappedStartPos.m_y - (float)m_y),
          v17 = (float)(this->m_snappedStartPos.m_z - (float)m_z),
          (float)((float)((float)v19 * (float)v19)
                + (float)((float)((float)v17 * (float)v17) + (float)((float)v18 * (float)v18))) > 1.0842022e-19) )
    {
      this->m_snappedStartPos.m_x = m_x;
      this->m_snappedStartPos.m_y = m_y;
      this->m_snappedStartPos.m_z = m_z;
      this->m_snappedStartPosChangedTimestamp = v12;
      v16 = bfx::UNINITIALIZED_TIMESTAMP;
    }
    if ( this->m_snappedStartAreaChangedTimestamp == v16
      || ((v20 = this->m_snappedStartArea.m_pProxy) == nullptr ? (v21 = nullptr) : (v21 = v20->m_pArea), v21 != v10) )
    {
      bfx::Handle<bfx::Area>::operator=(this: &this->m_snappedStartArea, pArea: v10);
      this->m_snappedStartAreaChangedTimestamp = v12;
    }
    return 1;
  }
  v5 = this->m_snappedStartArea.m_pProxy;
  if ( v5 == nullptr || v5->m_pArea == nullptr )
  {
    m_pArea = bfx::Planner::GetClosestArea(
                this: this->m_pPlanner,
                pos: &this->m_inputStartPos,
                layerNum: this->m_layer,
                pathSpec: &this->m_pathSpec);
    if ( m_pArea == nullptr )
      return 0;
    p_m_inputStartPos = &this->m_inputStartPos;
    goto LABEL_18;
  }
  return 1;
}


// ========================================================================
// ?GetSnappedStartPos@SmartPath@bfx@@QAA?AVVec3@2@XZ
// EA  : 0x8328EBA0
// RVA : 0x0128EBA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::SmartPath *__fastcall bfx::SmartPath::GetSnappedStartPos(bfx::SmartPath *this, bfx::SmartPath *result)
{
  bfx::SmartPath *v4; // r3
  bool v5; // zf
  float v6; // r8
  float v7; // r7
  float m_y; // r10
  float m_z; // r9

  v5 = (unsigned __int8)bfx::SmartPath::RebuildSnappedStartDataIfNeeded(this: result) != 0;
  v4 = this;
  if ( v5 )
  {
    m_y = result->m_snappedStartPos.m_y;
    m_z = result->m_snappedStartPos.m_z;
    this->m_curTimestamp = LODWORD(result->m_snappedStartPos.m_x);
    *(float *)&this->m_pSpace = m_y;
    *(float *)&this->m_pPlanner = m_z;
  }
  else
  {
    v6 = bfx::ZERO_VEC.m_y;
    v7 = bfx::ZERO_VEC.m_z;
    this->m_curTimestamp = LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_pSpace = v6;
    *(float *)&this->m_pPlanner = v7;
  }
  return v4;
}


// ========================================================================
// ?GetSnappedStartArea@SmartPath@bfx@@QAAPAVArea@2@XZ
// EA  : 0x8328EC28
// RVA : 0x0128EC28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::Area *__fastcall bfx::SmartPath::GetSnappedStartArea(bfx::SmartPath *this)
{
  bfx::AreaProxy *m_pProxy; // r11

  if ( (unsigned __int8)bfx::SmartPath::RebuildSnappedStartDataIfNeeded(this) != 0
    && (m_pProxy = this->m_snappedStartArea.m_pProxy) != nullptr )
  {
    return m_pProxy->m_pArea;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?AllHandlesInArrayValid@bfx@@YA_NAAV?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@1@@Z
// EA  : 0x8328EC88
// RVA : 0x0128EC88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::AllHandlesInArrayValid(bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *handles)
{
  int m_size; // r7
  int v2; // r9
  int i; // r10
  bfx::AreaProxy *m_pProxy; // r11
  char v5; // r11
  bool v6; // zf

  m_size = handles->m_size;
  v2 = 0;
  if ( m_size <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    m_pProxy = handles->m_data[i].m_areaHandle.m_pProxy;
    if ( m_pProxy == nullptr || (v6 = m_pProxy->m_pArea != nullptr, v5 = 1, !v6) )
      v5 = 0;
    if ( v5 == 0 )
      break;
    if ( ++v2 >= m_size )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?AreAllCurrentLinksUsable@SmartPath@bfx@@ABA_NXZ
// EA  : 0x8328ECF0
// RVA : 0x0128ECF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::AreAllCurrentLinksUsable(bfx::SmartPath *this)
{
  int m_size; // r6
  int v2; // r8
  int i; // r9
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *v5; // r10
  char v6; // r11

  m_size = this->m_links.m_size;
  v2 = 0;
  if ( m_size <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    m_pProxy = this->m_links.m_data[i].m_link.m_pProxy;
    v5 = m_pProxy != nullptr ? m_pProxy->m_pTarget : nullptr;
    if ( v5 == nullptr )
      break;
    if ( (HIBYTE(v5[5].m_pProxy) & 0x80) == 0
      || (HIBYTE(v5[5].m_pProxy) & 0x40) != 0
      || (v6 = 1, (HIBYTE(v5[5].m_pProxy) & 0x20) != 0) )
    {
      v6 = 0;
    }
    if ( v6 == 0 || (*((_DWORD *)&v5[6].m_pProxy[5] + 1) & this->m_pathSpec.m_linkUsageFlags) == 0 )
      break;
    if ( ++v2 >= m_size )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?RebuildSnappedGoalDataIfNeeded@SmartPath@bfx@@AAA_NXZ
// EA  : 0x8328EDA0
// RVA : 0x0128EDA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall bfx::SmartPath::RebuildSnappedGoalDataIfNeeded(bfx::SmartPath *this)
{
  __int64 v3; // r8 OVERLAPPED
  bfx::AreaProxy *m_pProxy; // r11
  const bfx::Area *m_pArea; // r28
  bfx::AreaProxy *v6; // r11
  bfx::Vec3 *v7; // r11
  bfx::Vec3 *v8; // r29
  __int64 v9; // r6
  bfx::Vec3 *p_m_inputGoalPos; // r5
  bfx::AreaProxy *v11; // r11
  bfx::Vec3 *v12; // r11
  unsigned int m_pathDataTimestamp; // r11
  bfx::AreaProxy *v14; // r11
  const bfx::Area *v15; // r9
  bfx::HandleForAreaWithUsageCountTracking *v16; // r10
  bfx::Vec3 *v17; // r11
  unsigned int m_layer; // r11
  bfx::NavLayer *v19; // r11
  unsigned __int64 m_areaInvalidationTimestamp; // r10
  __int64 v21; // r6
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  __int64 v25; // r6
  bfx::Area *ClosestReachableArea; // r3
  bfx::Vec3 *ClosestPosInArea; // r3
  double v28; // fp11
  double v29; // fp10
  double v30; // fp9
  bfx::AreaProxy *v31; // r10
  bfx::Vec3 *v32; // r10
  unsigned int v33; // r11
  bfx::Vec3 v34[5]; // [sp+50h] [-40h] BYREF

  if ( this->m_inputGoalDataTimestamp == bfx::UNINITIALIZED_TIMESTAMP
    || (unsigned __int8)bfx::SmartPath::RebuildSnappedStartDataIfNeeded(this) == 0 )
  {
    return 0;
  }
  m_pProxy = this->m_snappedStartArea.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  if ( this->m_inputGoalDataTimestamp > this->m_snappedGoalDataTimestamp )
  {
    v6 = this->m_inputGoalArea.m_pProxy;
    if ( v6 != nullptr )
      v7 = (bfx::Vec3 *)v6->m_pArea;
    else
      v7 = nullptr;
    v8 = v7;
    if ( v7 != nullptr )
    {
      LODWORD(v9) = &this->m_pathSpec;
      HIDWORD(v9) = v7;
      if ( bfx::Planner::IsAreaReachableFromArea(this: this->m_pPlanner, pAreaA: m_pArea, pathSpec: v9, a4: v3) )
      {
        p_m_inputGoalPos = &this->m_inputGoalPos;
LABEL_39:
        ClosestPosInArea = bfx::GetClosestPosInArea(
                             result: v34,
                             pArea: v8,
                             pos: p_m_inputGoalPos,
                             pEdgeIndexOut: nullptr);
        m_x = ClosestPosInArea->m_x;
        m_y = ClosestPosInArea->m_y;
        m_z = ClosestPosInArea->m_z;
LABEL_40:
        if ( v8 != nullptr )
        {
          if ( this->m_snappedGoalDataTimestamp == bfx::UNINITIALIZED_TIMESTAMP
            || (v28 = (float)(this->m_snappedGoalPos.m_x - (float)m_x),
                v29 = (float)(this->m_snappedGoalPos.m_y - (float)m_y),
                v30 = (float)(this->m_snappedGoalPos.m_z - (float)m_z),
                (float)((float)((float)v28 * (float)v28)
                      + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29))) > 1.0842022e-19)
            || ((v31 = this->m_snappedGoalArea.m_pProxy) == nullptr
              ? (v32 = nullptr)
              : (v32 = (bfx::Vec3 *)v31->m_pArea),
                v32 != v8) )
          {
            this->m_snappedGoalPos.m_x = m_x;
            this->m_snappedGoalPos.m_y = m_y;
            this->m_snappedGoalPos.m_z = m_z;
            bfx::Handle<bfx::Area>::operator=(this: &this->m_snappedGoalArea, pArea: (bfx::Area *)v8);
            v33 = this->m_curTimestamp + 1;
            this->m_curTimestamp = v33;
            this->m_snappedGoalDataTimestamp = v33;
          }
          return 1;
        }
        return 0;
      }
    }
LABEL_38:
    LODWORD(v25) = &this->m_pathSpec;
    HIDWORD(v25) = m_pArea;
    ClosestReachableArea = bfx::Planner::GetClosestReachableArea(
                             this: this->m_pPlanner,
                             pos: (bfx::IslandGraph *)&this->m_inputGoalPos,
                             pathSpec: v25,
                             a4: v3);
    p_m_inputGoalPos = &this->m_inputGoalPos;
    v8 = (bfx::Vec3 *)ClosestReachableArea;
    goto LABEL_39;
  }
  v11 = this->m_snappedGoalArea.m_pProxy;
  if ( v11 != nullptr )
    v12 = (bfx::Vec3 *)v11->m_pArea;
  else
    v12 = nullptr;
  v8 = v12;
  if ( v12 == nullptr )
    goto LABEL_38;
  m_pathDataTimestamp = this->m_pathDataTimestamp;
  if ( this->m_layerTimestamp <= m_pathDataTimestamp
    && this->m_pathSpecTimestamp <= m_pathDataTimestamp
    && this->m_pcoTimestamp <= m_pathDataTimestamp
    && this->m_areaHandles.m_size != 0 )
  {
    v14 = this->m_areaHandles.m_data->m_areaHandle.m_pProxy;
    v15 = v14 != nullptr ? v14->m_pArea : nullptr;
    v16 = &this->m_areaHandles.m_data[this->m_areaHandles.m_size - 1];
    v17 = v16->m_areaHandle.m_pProxy != nullptr ? (bfx::Vec3 *)v16->m_areaHandle.m_pProxy->m_pArea : nullptr;
    if ( m_pArea != nullptr && m_pArea == v15 && v8 == v17 )
    {
      m_layer = this->m_layer;
      v19 = m_layer >= 0x20 ? nullptr : this->m_pPlanner->m_layers[m_layer];
      m_areaInvalidationTimestamp = this->m_areaInvalidationTimestamp;
      *(__int64 *)((char *)&v3 - 4) = v19->m_areaInvalidationTimestamp;
      if ( (_DWORD)m_areaInvalidationTimestamp == HIDWORD(m_areaInvalidationTimestamp)
        && (unsigned __int8)bfx::SmartPath::AreAllCurrentLinksUsable(this) != 0 )
      {
        return 1;
      }
    }
  }
  LODWORD(v21) = &this->m_pathSpec;
  HIDWORD(v21) = v8;
  if ( bfx::Planner::IsAreaReachableFromArea(this: this->m_pPlanner, pAreaA: m_pArea, pathSpec: v21, a4: v3) )
  {
    m_x = this->m_snappedGoalPos.m_x;
    m_y = this->m_snappedGoalPos.m_y;
    m_z = this->m_snappedGoalPos.m_z;
    goto LABEL_40;
  }
  goto LABEL_38;
}


// ========================================================================
// ?GetSnappedGoalPos@SmartPath@bfx@@QAA?AVVec3@2@XZ
// EA  : 0x8328F068
// RVA : 0x0128F068
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::SmartPath *__fastcall bfx::SmartPath::GetSnappedGoalPos(bfx::SmartPath *this, bfx::SmartPath *result)
{
  bfx::SmartPath *v4; // r3
  bool v5; // zf
  float v6; // r8
  float v7; // r7
  float m_y; // r10
  float m_z; // r9

  v5 = (unsigned __int8)bfx::SmartPath::RebuildSnappedGoalDataIfNeeded(this: result) != 0;
  v4 = this;
  if ( v5 )
  {
    m_y = result->m_snappedGoalPos.m_y;
    m_z = result->m_snappedGoalPos.m_z;
    this->m_curTimestamp = LODWORD(result->m_snappedGoalPos.m_x);
    *(float *)&this->m_pSpace = m_y;
    *(float *)&this->m_pPlanner = m_z;
  }
  else
  {
    v6 = bfx::ZERO_VEC.m_y;
    v7 = bfx::ZERO_VEC.m_z;
    this->m_curTimestamp = LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_pSpace = v6;
    *(float *)&this->m_pPlanner = v7;
  }
  return v4;
}


// ========================================================================
// ?GetSnappedGoalArea@SmartPath@bfx@@QAAPAVArea@2@XZ
// EA  : 0x8328F0F0
// RVA : 0x0128F0F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::Area *__fastcall bfx::SmartPath::GetSnappedGoalArea(bfx::SmartPath *this)
{
  bfx::AreaProxy *m_pProxy; // r11

  if ( (unsigned __int8)bfx::SmartPath::RebuildSnappedGoalDataIfNeeded(this) != 0
    && (m_pProxy = this->m_snappedGoalArea.m_pProxy) != nullptr )
  {
    return m_pProxy->m_pArea;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??0AreaExitData@bfx@@QAA@ABVLineSeg@1@_N111@Z
// EA  : 0x8328F478
// RVA : 0x0128F478
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::AreaExitData *__fastcall bfx::AreaExitData::AreaExitData(
        bfx::AreaExitData *this,
        const bfx::LineSeg *exitSeg,
        bool leftSideFan,
        bool rightSideFan,
        bool leftSideInteriorVert,
        bool rightSideInteriorVert)
{
  _DWORD *p_m_z; // r10
  _DWORD *v7; // r9
  int i; // ctr
  double v9; // fp11
  double v10; // fp8
  double v11; // fp5

  p_m_z = (_DWORD *)&exitSeg[-1].m_v1.m_z;
  v7 = (_DWORD *)((char *)this - 4);
  for ( i = 6; i != 0; --i )
    *++v7 = *++p_m_z;
  v9 = (float)(this->m_exitSeg.m_v1.m_x - this->m_exitSeg.m_v0.m_x);
  v10 = (float)(this->m_exitSeg.m_v1.m_z - this->m_exitSeg.m_v0.m_z);
  v11 = (float)(this->m_exitSeg.m_v1.m_y - this->m_exitSeg.m_v0.m_y);
  _FP0 = (float)((float)__fsqrts((float)((float)((float)v11 * (float)v11)
                                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))))
               - (float)1.0842022e-19);
  __asm { fsel      f12, f0, f13, f12 }
  this->m_exitUnitVec.m_x = (float)(this->m_exitSeg.m_v1.m_x - this->m_exitSeg.m_v0.m_x) * (float)_FP12;
  this->m_exitUnitVec.m_y = (float)v11 * (float)_FP12;
  this->m_exitUnitVec.m_z = (float)v10 * (float)_FP12;
  this->m_exitType = EXIT_TYPE_SURFACE;
  this->m_exitLink.m_pProxy = nullptr;
  *((_BYTE *)this + 44) = (16 * ((2 * ((2 * rightSideFan) & 2 | leftSideInteriorVert)) | rightSideInteriorVert))
                        | (leftSideFan << 7)
                        | *((_BYTE *)this + 44) & 0xF;
  return this;
}


// ========================================================================
// ??0AreaExitData@bfx@@QAA@PAVHalfLink@1@@Z
// EA  : 0x8328F540
// RVA : 0x0128F540
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::AreaExitData *__fastcall bfx::AreaExitData::AreaExitData(bfx::AreaExitData *this, bfx::Space *pExitLink)
{
  bfx::HandleProxy **p_m_pProxy; // r11
  _DWORD *v4; // r10
  int i; // ctr
  double v6; // fp11
  double v7; // fp8
  double v8; // fp5

  p_m_pProxy = &pExitLink->m_pProxy;
  v4 = (_DWORD *)((char *)this - 4);
  for ( i = 6; i != 0; --i )
    *++v4 = *++p_m_pProxy;
  v6 = (float)(this->m_exitSeg.m_v1.m_z - this->m_exitSeg.m_v0.m_z);
  v7 = (float)(this->m_exitSeg.m_v1.m_x - this->m_exitSeg.m_v0.m_x);
  v8 = (float)(this->m_exitSeg.m_v1.m_y - this->m_exitSeg.m_v0.m_y);
  _FP0 = (float)((float)__fsqrts((float)((float)((float)v8 * (float)v8)
                                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))))
               - (float)1.0842022e-19);
  __asm { fsel      f12, f0, f13, f12 }
  this->m_exitUnitVec.m_x = (float)(this->m_exitSeg.m_v1.m_x - this->m_exitSeg.m_v0.m_x) * (float)_FP12;
  this->m_exitUnitVec.m_y = (float)_FP12 * (float)v8;
  this->m_exitUnitVec.m_z = (float)v6 * (float)_FP12;
  this->m_exitType = EXIT_TYPE_LINK;
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(
    this: (bfx::Handle<bfx::Space> *)&this->m_exitLink,
    pTarget: pExitLink);
  *((_BYTE *)this + 44) &= 0xFu;
  return this;
}


// ========================================================================
// ??$PopFront@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@YAXAAV?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@0@@Z
// EA  : 0x8328F928
// RVA : 0x0128F928
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PopFront<bfx::HandleForAreaWithUsageCountTracking>(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *myArray)
{
  int v2; // r27
  int v3; // r28
  bfx::HandleForAreaWithUsageCountTracking *v4; // r31
  bfx::Area *m_pArea; // r11
  bfx::Area *v6; // r11

  v2 = 0;
  if ( myArray->m_size - 1 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &myArray->m_data[v3];
      if ( v4->m_areaHandle.m_pProxy != nullptr )
      {
        m_pArea = v4->m_areaHandle.m_pProxy->m_pArea;
        if ( m_pArea != nullptr )
          bfx::AreaFlags::DecAreaUsageCount(this: &m_pArea->m_flags);
      }
      bfx::Handle<bfx::Area>::operator=(this: &v4->m_areaHandle, rhs: &v4[1].m_areaHandle);
      if ( v4->m_areaHandle.m_pProxy != nullptr )
      {
        v6 = v4->m_areaHandle.m_pProxy->m_pArea;
        if ( v6 != nullptr )
          bfx::AreaFlags::IncAreaUsageCount(this: &v6->m_flags);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < myArray->m_size - 1 );
  }
  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &myArray->m_data[myArray->m_size - 1]);
  --myArray->m_size;
}


// ========================================================================
// ?RebuildAreaHandlesfFromAreas@SmartPath@bfx@@AAAXXZ
// EA  : 0x8328FC60
// RVA : 0x0128FC60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::RebuildAreaHandlesfFromAreas(bfx::SmartPath *this)
{
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *p_m_areaHandles; // r26
  int v3; // r27
  int v4; // r29
  bfx::Area *v5; // r30
  bfx::Handle<bfx::Area> *p_m_areaHandle; // r30
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r10
  bfx::AreaProxy *v9; // r11
  bfx::Area *v10; // r10
  bfx::Handle<bfx::Area> v11; // [sp+50h] [-40h] BYREF
  bfx::Handle<bfx::Area> v12; // [sp+54h] [-3Ch]

  p_m_areaHandles = &this->m_areaHandles;
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::resize(
    this: &this->m_areaHandles,
    size: this->m_pathAreas.m_size);
  v3 = 0;
  if ( this->m_pathAreas.m_size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->m_pathAreas.m_data[v4];
      bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: &v11, pArea: v5);
      if ( v5 != nullptr )
        bfx::AreaFlags::IncAreaUsageCount(this: &v5->m_flags);
      p_m_areaHandle = &p_m_areaHandles->m_data[v4].m_areaHandle;
      if ( p_m_areaHandle != &v11 )
      {
        m_pProxy = p_m_areaHandle->m_pProxy;
        if ( p_m_areaHandle->m_pProxy != nullptr )
        {
          m_pArea = m_pProxy->m_pArea;
          v12.m_pProxy = p_m_areaHandle->m_pProxy;
          if ( m_pArea != nullptr )
          {
            v12.m_pProxy = m_pProxy;
            bfx::AreaFlags::DecAreaUsageCount(this: &m_pArea->m_flags);
          }
        }
        bfx::Handle<bfx::Area>::operator=(this: p_m_areaHandle, rhs: &v11);
        v9 = p_m_areaHandle->m_pProxy;
        if ( p_m_areaHandle->m_pProxy != nullptr )
        {
          v10 = v9->m_pArea;
          v12.m_pProxy = p_m_areaHandle->m_pProxy;
          if ( v10 != nullptr )
          {
            v12.m_pProxy = v9;
            bfx::AreaFlags::IncAreaUsageCount(this: &v10->m_flags);
          }
        }
      }
      bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)&v11);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_pathAreas.m_size );
  }
}


// ========================================================================
// __unwind$31477
// EA  : 0x8328FD58
// RVA : 0x0128FD58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_31477()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$31463
// EA  : 0x8328FD80
// RVA : 0x0128FD80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_31463()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(v0 - 144 + 80));
}


// ========================================================================
// ??$PopFront@VAreaExitData@bfx@@@bfx@@YAXAAV?$Array@VAreaExitData@bfx@@@0@@Z
// EA  : 0x83290128
// RVA : 0x01290128
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PopFront<bfx::AreaExitData>(bfx::Array<bfx::AreaExitData> *myArray)
{
  int v2; // r29
  int v3; // r30
  bfx::AreaExitData *v4; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v2 = 0;
  if ( myArray->m_size - 1 > 0 )
  {
    v3 = 0;
    do
    {
      bfx::AreaExitData::operator=(this: &myArray->m_data[v3], __that: &myArray->m_data[v3 + 1]);
      ++v2;
      ++v3;
    }
    while ( v2 < myArray->m_size - 1 );
  }
  v4 = &myArray->m_data[myArray->m_size];
  m_pProxy = v4[-1].m_exitLink.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    v4[-1].m_exitLink.m_pProxy = nullptr;
  }
  --myArray->m_size;
}


// ========================================================================
// ??$PopFront@VLinkConnectionData@bfx@@@bfx@@YAXAAV?$Array@VLinkConnectionData@bfx@@@0@@Z
// EA  : 0x832901B8
// RVA : 0x012901B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::PopFront<bfx::LinkConnectionData>(bfx::Array<bfx::LinkConnectionData> *myArray)
{
  int v2; // r27
  int v3; // r28
  bfx::LinkConnectionData *v4; // r31
  bfx::LinkConnectionData *v5; // r30
  bfx::HandleProxy *m_pProxy; // r11
  bool v7; // cr58
  bfx::LinkConnectionData *v8; // r31
  bfx::HandleProxy *v9; // r3

  v2 = 0;
  if ( myArray->m_size - 1 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &myArray->m_data[v3];
      v5 = v4 + 1;
      if ( v4->m_link.m_pProxy != nullptr )
        bfx::HandleProxy::RemRefToHandleProxy(this: v4->m_link.m_pProxy);
      m_pProxy = v5->m_link.m_pProxy;
      v7 = v5->m_link.m_pProxy == nullptr;
      v4->m_link.m_pProxy = v5->m_link.m_pProxy;
      if ( !v7 )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      ++v2;
      ++v3;
      v4->m_startAreaIndex = v4[1].m_startAreaIndex;
    }
    while ( v2 < myArray->m_size - 1 );
  }
  v8 = &myArray->m_data[myArray->m_size];
  v9 = v8[-1].m_link.m_pProxy;
  if ( v9 != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: v9);
    v8[-1].m_link.m_pProxy = nullptr;
  }
  --myArray->m_size;
}


// ========================================================================
// ?BuildAreaExits@bfx@@YA_NABVVec3@1@0AAV?$Array@PAVArea@bfx@@@1@ABVPathSpec@1@AAV?$Array@VAreaExitData@bfx@@@1@AAV?$Array@VLinkConnectionData@bfx@@@1@@Z
// EA  : 0x83290288
// RVA : 0x01290288
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::BuildAreaExits(
        const bfx::Vec3 *snappedStartPos,
        const bfx::Vec3 *snappedGoalPos,
        bfx::Array<bfx::Area *> *pathAreas,
        const bfx::PathSpec *pathSpec,
        bfx::Array<bfx::AreaExitData> *areaExitsOut,
        bfx::Array<bfx::LinkConnectionData> *linkDataOut)
{
  int m_size; // r4
  int v14; // r18
  int v15; // r17
  int v16; // r24
  bfx::Area *v17; // r27
  bfx::Area **v18; // r11
  bfx::Area *v19; // r30
  bfx::Area *v20; // r28
  int m_i; // r29
  bfx::Area *v22; // r3
  bfx::Space *LinkBetweenAdjAreasIfBetter; // r3
  bfx::Space *v24; // r28
  bfx::AreaExitData *v25; // r3
  int v26; // r30
  signed int v27; // r7
  float *v28; // r9
  float v29; // r5
  float v30; // r8
  float *v31; // r11
  float v32; // r9
  float v33; // r6
  float v34; // r5
  float v35; // r11
  char IsInteriorVertOnSide; // r30
  char v37; // r3
  const bfx::AreaExitData *v38; // r3
  bfx::Space *BestLinkBetweenNonSurfaceConnectedAreas; // r3
  bfx::Space *v40; // r30
  bfx::AreaExitData *v41; // r3
  bfx::Space *v42; // r4
  int v43; // r30
  float m_x; // r9
  float m_y; // r7
  float m_z; // r5
  bool v47; // [sp+50h] [-200h] BYREF
  bool v48; // [sp+51h] [-1FFh] BYREF
  bfx::LinkConnectionData v49; // [sp+58h] [-1F8h] BYREF
  bfx::EdgeCursor v50; // [sp+60h] [-1F0h] BYREF
  bfx::LinkConnectionData v51; // [sp+68h] [-1E8h] BYREF
  bfx::LineSeg v52; // [sp+70h] [-1E0h] BYREF
  bfx::AreaExitData v53; // [sp+90h] [-1C0h] BYREF
  bfx::EdgeCursor v54; // [sp+D8h] [-178h] BYREF
  bfx::AreaExitData v55; // [sp+E0h] [-170h] BYREF
  bfx::AreaExitData v56; // [sp+130h] [-120h] BYREF
  bfx::AreaExitData v57; // [sp+180h] [-D0h] BYREF

  m_size = pathAreas->m_size;
  if ( m_size == 0 )
    return 1;
  v49.m_link.m_pProxy = (bfx::HandleProxy *)pathAreas->m_size;
  if ( m_size < 2 )
    goto LABEL_27;
  if ( m_size > areaExitsOut->m_cap )
    bfx::Array<bfx::AreaExitData>::expand_cap(this: areaExitsOut, size: m_size);
  bfx::GetSharedEdgeCC(result: &v54, pArea0: *pathAreas->m_data, pArea1: pathAreas->m_data[1]);
  v14 = 0;
  v15 = pathAreas->m_size - 1;
  if ( v15 <= 0 )
  {
LABEL_27:
    m_x = snappedGoalPos->m_x;
    m_y = snappedGoalPos->m_y;
    m_z = snappedGoalPos->m_z;
    v53.m_exitType = EXIT_TYPE_GOAL;
    v53.m_exitUnitVec.m_x = 0.0;
    v53.m_exitUnitVec.m_y = 0.0;
    v53.m_exitSeg.m_v0.m_x = m_x;
    v53.m_exitUnitVec.m_z = 0.0;
    v53.m_exitSeg.m_v0.m_y = m_y;
    v53.m_exitSeg.m_v0.m_z = m_z;
    v53.m_exitSeg.m_v1.m_x = m_x;
    v53.m_exitSeg.m_v1.m_y = m_y;
    HIBYTE(v53.m_exitLink.m_pProxy) = 0;
    v53.m_exitSeg.m_v1.m_z = m_z;
    *(bfx::HandleProxy **)((char *)&v53.m_exitLink.m_pProxy + 1) = (bfx::HandleProxy *)(*((_BYTE *)&v53 + 44) & 0xF);
    bfx::Array<bfx::AreaExitData>::push_back(this: areaExitsOut, val: &v53);
    bfx::BuildUnwrappedData(pathAreas, areaExits: areaExitsOut);
    return 1;
  }
  v16 = 0;
  while ( 1 )
  {
    if ( v14 <= 0 )
      v17 = nullptr;
    else
      v17 = pathAreas->m_data[v16 - 1];
    v18 = &pathAreas->m_data[v16];
    v19 = *v18;
    v20 = v18[1];
    bfx::GetSharedEdgeCC(result: &v50, pArea0: *v18, pArea1: v20);
    m_i = v50.m_i;
    if ( v50.m_pArea == nullptr )
      m_i = -1;
    v47 = false;
    v48 = false;
    bfx::IsAreaInFan(
      pArea: v19,
      pPrevArea: v17,
      edgeIndexToNextArea: m_i,
      areaIsInLeftFanOut: &v47,
      areaIsInRightFanOut: &v48);
    if ( m_i == -1 )
      break;
    LinkBetweenAdjAreasIfBetter = (bfx::Space *)bfx::GetLinkBetweenAdjAreasIfBetter(
                                                  pArea0: v22,
                                                  pArea1: v20,
                                                  startPos: snappedStartPos,
                                                  goalPos: snappedGoalPos,
                                                  pathSpec);
    v24 = LinkBetweenAdjAreasIfBetter;
    if ( LinkBetweenAdjAreasIfBetter != nullptr )
    {
      v25 = bfx::AreaExitData::AreaExitData(this: &v56, pExitLink: LinkBetweenAdjAreasIfBetter);
      bfx::Array<bfx::AreaExitData>::push_back(this: areaExitsOut, val: v25);
      if ( v56.m_exitLink.m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v56.m_exitLink.m_pProxy);
        v56.m_exitLink.m_pProxy = nullptr;
      }
      v26 = areaExitsOut->m_size;
      bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&v49, pTarget: v24);
      v49.m_startAreaIndex = v26 - 1;
      bfx::Array<bfx::LinkConnectionData>::push_back(this: linkDataOut, val: &v49);
      if ( v49.m_link.m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v49.m_link.m_pProxy);
        v49.m_link.m_pProxy = nullptr;
      }
    }
    else
    {
      v27 = v19->m_flags.m_flags1 & 0x7F;
      v28 = (float *)((char *)v19 + 24 * m_i);
      __twllei(v27, 0);
      v29 = v28[16];
      v30 = v28[15];
      v31 = (float *)((char *)v19 + 24 * ((m_i + 1) % v27));
      v32 = v28[17];
      v52.m_v0.m_y = v29;
      v52.m_v0.m_x = v30;
      v33 = v31[15];
      __twlgei(v27 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
      v34 = v31[16];
      v35 = v31[17];
      v52.m_v0.m_z = v32;
      v52.m_v1.m_x = v33;
      v52.m_v1.m_y = v34;
      v52.m_v1.m_z = v35;
      IsInteriorVertOnSide = bfx::IsInteriorVertOnSide(startCC: &v50, checkLeftVert: true);
      v37 = bfx::IsInteriorVertOnSide(startCC: &v50, checkLeftVert: false);
      v38 = bfx::AreaExitData::AreaExitData(
              this: &v55,
              exitSeg: &v52,
              leftSideFan: v47,
              rightSideFan: v48,
              leftSideInteriorVert: IsInteriorVertOnSide,
              rightSideInteriorVert: v37);
      bfx::Array<bfx::AreaExitData>::push_back(this: areaExitsOut, val: v38);
      if ( v55.m_exitLink.m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v55.m_exitLink.m_pProxy);
        v55.m_exitLink.m_pProxy = nullptr;
      }
    }
_M32490:
    ++v14;
    ++v16;
    if ( v14 >= v15 )
      goto LABEL_27;
  }
  BestLinkBetweenNonSurfaceConnectedAreas = (bfx::Space *)bfx::GetBestLinkBetweenNonSurfaceConnectedAreas(
                                                            pArea0: v22,
                                                            pArea1: v20,
                                                            pos: snappedStartPos,
                                                            pathSpec);
  v40 = BestLinkBetweenNonSurfaceConnectedAreas;
  if ( BestLinkBetweenNonSurfaceConnectedAreas != nullptr )
  {
    v41 = bfx::AreaExitData::AreaExitData(this: &v57, pExitLink: BestLinkBetweenNonSurfaceConnectedAreas);
    bfx::Array<bfx::AreaExitData>::push_back(this: areaExitsOut, val: v41);
    if ( v57.m_exitLink.m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: v57.m_exitLink.m_pProxy);
      v57.m_exitLink.m_pProxy = nullptr;
    }
    v42 = v40;
    v43 = areaExitsOut->m_size;
    bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&v51, pTarget: v42);
    v51.m_startAreaIndex = v43 - 1;
    bfx::Array<bfx::LinkConnectionData>::push_back(this: linkDataOut, val: &v51);
    if ( v51.m_link.m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: v51.m_link.m_pProxy);
      v51.m_link.m_pProxy = nullptr;
    }
    goto _M32490;
  }
  bfx::Array<bfx::AreaExitData>::shrink(this: areaExitsOut, size: 0);
  bfx::Array<bfx::LinkConnectionData>::shrink(this: linkDataOut, size: 0);
  return 0;
}


// ========================================================================
// __unwind$32167
// EA  : 0x83290614
// RVA : 0x01290614
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32167()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 592 + 304));
}


// ========================================================================
// __unwind$32168
// EA  : 0x8329063C
// RVA : 0x0129063C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32168()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 592 + 88));
}


// ========================================================================
// __unwind$32169
// EA  : 0x83290664
// RVA : 0x01290664
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32169()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 592 + 224));
}


// ========================================================================
// __unwind$32170
// EA  : 0x8329068C
// RVA : 0x0129068C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32170()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 592 + 384));
}


// ========================================================================
// __unwind$32171
// EA  : 0x832906B4
// RVA : 0x012906B4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32171()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 592 + 104));
}


// ========================================================================
// __unwind$32172
// EA  : 0x832906DC
// RVA : 0x012906DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32172()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 592 + 144));
}


// ========================================================================
// ?CalcRealCorners@bfx@@YA_NABVVec3@1@0AAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VAreaExitData@bfx@@@1@AAV?$Array@VLinkConnectionData@bfx@@@1@HMABVPathSpec@1@_NAA_NAAV?$Array@VSPCorner@bfx@@@1@@Z
// EA  : 0x83290710
// RVA : 0x01290710
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::CalcRealCorners(
        const bfx::Vec3 *snappedStartPos,
        const bfx::Vec3 *snappedGoalPos,
        bfx::Array<bfx::Area *> *pathAreas,
        bfx::Array<bfx::AreaExitData> *areaExits,
        bfx::Array<bfx::LinkConnectionData> *linkData,
        int maxNumCorners,
        double maxPathDist,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *performAdditionalSmoothing,
        bool *areaPathWasModifiedOut,
        bfx::Array<bfx::SPCorner> *cornersOut,
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
        char a29,
        int a30,
        _BYTE *a31,
        int a32,
        bfx::Array<bfx::SPCorner> *a33)
{
  int i; // r21
  unsigned int v42; // r7
  int m_size; // r29
  unsigned int m_cap; // r28
  bfx::Area **v45; // r11
  bfx::AABB *v46; // r9
  int v47; // r28
  unsigned int MaxAreaPenaltyForSubsetOfPathAreas; // r14
  int v50; // [sp+50h] [-F0h] BYREF
  bfx::Array<bfx::ShortcutRecord> v51; // [sp+58h] [-E8h] BYREF
  bfx::EndPt v52; // [sp+68h] [-D8h] BYREF
  bfx::Array<bfx::SpaceComponent *> v53; // [sp+80h] [-C0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v54; // [sp+90h] [-B0h] BYREF

  *a31 = 0;
  if ( a29 != 0 )
  {
    memset(&v54, 0, 12);
    v54.m_tag = bfx::MEM_BFXPLANNER;
    for ( i = 0; i < 100; ++i )
    {
      v51.m_size = -1;
      v51.m_cap = 5;
      v42 = (_cntlzw(i - 99) & 0x20) != 0;
      HIBYTE(v51.m_data) = (_cntlzw(v42) & 0x20) != 0;
      bfx::CalcNextNCornersAndOptionallyCheckforShortcuts(
        snappedStartPos,
        pathAreas,
        areaExits,
        maxNumCorners,
        maxPathDist,
        shortcutInfo: (bfx::ShortcutInfo *)v42,
        pSkipShortcutRecords: &v51,
        cornersOut: (const bfx::Array<bfx::ShortcutRecord> *)&v54,
        a9: a33);
      m_size = v51.m_size;
      if ( v51.m_size == -1 )
        break;
      m_cap = v51.m_cap;
      if ( v51.m_size < pathAreas->m_size - 1 )
      {
        v45 = &pathAreas->m_data[v51.m_size];
        v52.m_type = v51.m_cap;
        v46 = (bfx::AABB *)v45[1];
        LODWORD(v52.m_val) = *v45;
        v52.m_pAABB = v46;
        bfx::Array<bfx::FollowerBuddyData>::push_back(this: (bfx::Array<bfx::EndPt> *)&v54, val: &v52);
      }
      v50 = -1;
      memset(&v53, 0, 12);
      v53.m_tag = bfx::MEM_BFXPLANNER;
      bfx::Array<bfx::Edge *>::expand_cap(this: &v53, size: 10);
      if ( (unsigned __int8)bfx::GetShortcutAreaSeries(
                              startAreaIndex: m_size,
                              pathAreas,
                              checkLeftVert: (_cntlzw(m_cap) & 0x20) != 0,
                              endAreaIndexOut: &v50,
                              shortcutAreasOut: (bfx::Array<bfx::Space *> *)&v53) != 0 )
      {
        v47 = v50;
        MaxAreaPenaltyForSubsetOfPathAreas = bfx::GetMaxAreaPenaltyForSubsetOfPathAreas(
                                               firstAreaIndex: m_size,
                                               lastAreaIndex: v50,
                                               pathAreas,
                                               pathSpec: performAdditionalSmoothing);
        if ( bfx::GetMaxAreaPenaltyForAreas(
               areas: (const bfx::Array<bfx::Area *> *)&v53,
               pathSpec: performAdditionalSmoothing) <= MaxAreaPenaltyForSubsetOfPathAreas )
        {
          bfx::SpliceShortcutIntoPath(
            shortcutAreas: (const bfx::Array<bfx::Area *> *)&v53,
            startPathIndex: m_size,
            endPathIndex: v47,
            (bfx::Array<bfx::Space *> *)pathAreas);
          bfx::PruneOffshoots(
            indexOfFirstAreaToCheck: ((m_size == 1) + ((unsigned int)(m_size - 1) >> 31) - 1) & (m_size - 1),
            pathAreas);
          bfx::Array<bfx::AreaExitData>::shrink(this: areaExits, size: 0);
          bfx::Array<bfx::LinkConnectionData>::shrink(this: linkData, size: 0);
          *a31 = 1;
          if ( (unsigned __int8)bfx::BuildAreaExits(
                                  snappedStartPos,
                                  snappedGoalPos,
                                  pathAreas,
                                  pathSpec: performAdditionalSmoothing,
                                  areaExitsOut: areaExits,
                                  linkDataOut: linkData) == 0 )
          {
            bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v53);
            bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v54);
            return 0;
          }
        }
      }
      v53.m_size = 0;
      if ( v53.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v53.m_data);
        v53.m_data = nullptr;
      }
      v53.m_cap = 0;
    }
    if ( v54.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v54.m_data);
  }
  else
  {
    HIBYTE(v51.m_data) = 0;
    *(_QWORD *)&v51.m_size = -4294967291LL;
    bfx::CalcNextNCornersAndOptionallyCheckforShortcuts(
      snappedStartPos,
      pathAreas,
      areaExits,
      maxNumCorners,
      maxPathDist,
      shortcutInfo: (bfx::ShortcutInfo *)linkData,
      pSkipShortcutRecords: &v51,
      cornersOut: nullptr,
      a9: a33);
  }
  return 1;
}


// ========================================================================
// __unwind$32528
// EA  : 0x832909B8
// RVA : 0x012909B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32528()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$32529
// EA  : 0x832909E0
// RVA : 0x012909E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32529()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 320 + 128));
}


// ========================================================================
// ??0SmartPath@bfx@@QAA@PAVSpace@1@HABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83290A08
// RVA : 0x01290A08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::SmartPath *__fastcall bfx::SmartPath::SmartPath(
        bfx::SmartPath *this,
        bfx::Space *pSpace,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  _DWORD *p_m_maxSearchDist; // r9
  unsigned int *p_m_layerTimestamp; // r8
  int v7; // ctr
  unsigned int v8; // r11
  unsigned __int64 v9; // r11
  bfx::bfxMemTag v10; // r9
  bfx::bfxMemTag v11; // r9
  bfx::bfxMemTag v12; // r9
  bfx::bfxMemTag v13; // r9
  bfx::bfxMemTag v14; // r10

  p_m_maxSearchDist = (_DWORD *)&pathSpec[-1].m_maxSearchDist;
  p_m_layerTimestamp = &this->m_layerTimestamp;
  v7 = 8;
  v8 = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_pSpace = pSpace;
  this->m_curTimestamp = v8;
  this->m_pPlanner = *((bfx::Planner **)pSpace->m_components.m_data + 1);
  this->m_layer = layer;
  this->m_layerTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  do
  {
    *++p_m_layerTimestamp = *++p_m_maxSearchDist;
    --v7;
  }
  while ( v7 != 0 );
  LODWORD(v9) = 0;
  this->m_pathSpecTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_pathCreationOptions = *options;
  this->m_pcoTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_inputStartPos = bfx::ZERO_VEC;
  this->m_inputStartArea.m_pProxy = nullptr;
  this->m_inputStartDataTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_inputGoalPos = bfx::ZERO_VEC;
  this->m_inputGoalArea.m_pProxy = nullptr;
  this->m_inputGoalDataTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_snappedStartPos = bfx::ZERO_VEC;
  this->m_snappedStartArea.m_pProxy = nullptr;
  this->m_snappedStartDataProcessedTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_snappedStartPosChangedTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_snappedStartAreaChangedTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  this->m_snappedGoalPos = bfx::ZERO_VEC;
  this->m_snappedGoalArea.m_pProxy = nullptr;
  this->m_snappedGoalDataTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  v10 = bfx::MEM_BFXPLANNER;
  this->m_pathAreas.m_data = nullptr;
  this->m_pathAreas.m_size = 0;
  this->m_pathAreas.m_cap = 0;
  this->m_pathAreas.m_tag = v10;
  v11 = bfx::MEM_BFXPLANNER;
  this->m_areaHandles.m_data = nullptr;
  this->m_areaHandles.m_size = 0;
  this->m_areaHandles.m_cap = 0;
  this->m_areaHandles.m_tag = v11;
  v12 = bfx::MEM_BFXPLANNER;
  this->m_areaExits.m_data = nullptr;
  this->m_areaExits.m_size = 0;
  this->m_areaExits.m_cap = 0;
  this->m_areaExits.m_tag = v12;
  v13 = bfx::MEM_BFXPLANNER;
  this->m_links.m_data = nullptr;
  this->m_links.m_size = 0;
  this->m_links.m_cap = 0;
  this->m_links.m_tag = v13;
  this->m_pathDataTimestamp = bfx::UNINITIALIZED_TIMESTAMP;
  v14 = bfx::MEM_BFXPLANNER;
  this->m_corners.m_size = 0;
  this->m_corners.m_data = nullptr;
  this->m_corners.m_cap = 0;
  this->m_corners.m_tag = v14;
  this->m_cornerDataTimestamp = 0;
  HIDWORD(v9) = bfx::MEM_BFXPLANNER;
  this->m_outputCorners.m_data = nullptr;
  this->m_outputCorners.m_size = 0;
  this->m_outputCorners.m_cap = 0;
  *(_QWORD *)&this->m_outputCorners.m_tag = __PAIR64__(HIDWORD(v9), 0);
  this->m_outputCornersSpec.m_maxPathDist = 3.4028235e38;
  this->m_outputCornersSpec.m_maxNumCorners = 2;
  this->m_outputCornersSpec.m_addCornersAtEveryAreaBoundary = false;
  this->m_outputCornersSpec.m_addCornerAtStartingPosition = false;
  this->m_areaInvalidationTimestamp = v9;
  return this;
}


// ========================================================================
// ??1SmartPath@bfx@@QAA@XZ
// EA  : 0x83290BF0
// RVA : 0x01290BF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::~SmartPath(bfx::SmartPath *this)
{
  char *m_data; // r4
  char *v3; // r4
  char *v4; // r4
  char *v5; // r4
  char *v6; // r4
  char *v7; // r4

  m_data = (char *)this->m_outputCorners.m_data;
  this->m_outputCorners.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_outputCorners.m_data = nullptr;
  }
  this->m_outputCorners.m_cap = 0;
  v3 = (char *)this->m_corners.m_data;
  this->m_corners.m_size = 0;
  if ( v3 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
    this->m_corners.m_data = nullptr;
  }
  this->m_corners.m_cap = 0;
  bfx::Array<bfx::LinkConnectionData>::shrink(this: &this->m_links, size: 0);
  v4 = (char *)this->m_links.m_data;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_links.m_data = nullptr;
  }
  this->m_links.m_cap = 0;
  bfx::Array<bfx::AreaExitData>::shrink(this: &this->m_areaExits, size: 0);
  v5 = (char *)this->m_areaExits.m_data;
  if ( v5 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
    this->m_areaExits.m_data = nullptr;
  }
  this->m_areaExits.m_cap = 0;
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(this: &this->m_areaHandles, size: 0);
  v6 = (char *)this->m_areaHandles.m_data;
  if ( v6 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
    this->m_areaHandles.m_data = nullptr;
  }
  this->m_areaHandles.m_cap = 0;
  v7 = (char *)this->m_pathAreas.m_data;
  this->m_pathAreas.m_size = 0;
  if ( v7 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7);
    this->m_pathAreas.m_data = nullptr;
  }
  this->m_pathAreas.m_cap = 0;
  bfx::Handle<bfx::Area>::Release(this: &this->m_snappedGoalArea);
  bfx::Handle<bfx::Area>::Release(this: &this->m_snappedStartArea);
  bfx::Handle<bfx::Area>::Release(this: &this->m_inputGoalArea);
  bfx::Handle<bfx::Area>::Release(this: &this->m_inputStartArea);
}


// ========================================================================
// __unwind$32725
// EA  : 0x83290D34
// RVA : 0x01290D34
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32725()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// __unwind$32726
// EA  : 0x83290D60
// RVA : 0x01290D60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32726()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 96));
}


// ========================================================================
// __unwind$32727
// EA  : 0x83290D8C
// RVA : 0x01290D8C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32727()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 116));
}


// ========================================================================
// __unwind$32728
// EA  : 0x83290DB8
// RVA : 0x01290DB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32728()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}


// ========================================================================
// __unwind$32729
// EA  : 0x83290DE4
// RVA : 0x01290DE4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32729()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 152));
}


// ========================================================================
// __unwind$32730
// EA  : 0x83290E10
// RVA : 0x01290E10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32730()
{
  int v0; // r12

  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::~Array<bfx::HandleForAreaWithUsageCountTracking>(this: (bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *)(*(_DWORD *)(v0 - 128 + 148) + 168));
}


// ========================================================================
// __unwind$32731
// EA  : 0x83290E3C
// RVA : 0x01290E3C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32731()
{
  int v0; // r12

  bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(this: (bfx::Array<bfx::AreaExitData> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                                 + 184));
}


// ========================================================================
// __unwind$32732
// EA  : 0x83290E68
// RVA : 0x01290E68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32732()
{
  int v0; // r12

  bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: (bfx::Array<bfx::LinkConnectionData> *)(*(_DWORD *)(v0 - 128 + 148) + 200));
}


// ========================================================================
// __unwind$32733
// EA  : 0x83290E94
// RVA : 0x01290E94
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32733()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 220));
}


// ========================================================================
// ?ClearAllPathData@SmartPath@bfx@@AAAXXZ
// EA  : 0x83290EC0
// RVA : 0x01290EC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::ClearAllPathData(bfx::SmartPath *this)
{
  this->m_pathAreas.m_size = 0;
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(this: &this->m_areaHandles, size: 0);
  bfx::Array<bfx::AreaExitData>::shrink(this: &this->m_areaExits, size: 0);
  bfx::Array<bfx::LinkConnectionData>::shrink(this: &this->m_links, size: 0);
}


// ========================================================================
// ?RemoveFirstAreaFromPath@SmartPath@bfx@@AAAX_N@Z
// EA  : 0x83290F18
// RVA : 0x01290F18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __fastcall bfx::SmartPath::RemoveFirstAreaFromPath(bfx::SmartPath *this, bool updateCornerData)
{
  int v4; // r10
  int v5; // r9
  bfx::SPCorner *v6; // r11
  int v7; // r10
  int v8; // r9
  bfx::LinkConnectionData *v9; // r11

  bfx::PopFront<bfx::Area *>(myArray: &this->m_pathAreas);
  bfx::PopFront<bfx::HandleForAreaWithUsageCountTracking>(myArray: &this->m_areaHandles);
  bfx::PopFront<bfx::AreaExitData>(myArray: &this->m_areaExits);
  *((_BYTE *)this->m_areaExits.m_data + 44) &= 0x3Fu;
  if ( updateCornerData )
  {
    while ( this->m_corners.m_size != 0 )
    {
      if ( this->m_corners.m_data->m_areaExitIndex != 0 )
        break;
      bfx::PopFront<bfx::SPCorner>(myArray: &this->m_corners);
    }
    v4 = 0;
    if ( this->m_corners.m_size > 0 )
    {
      v5 = 0;
      do
      {
        ++v4;
        v6 = &this->m_corners.m_data[v5++];
        --v6->m_areaExitIndex;
      }
      while ( v4 < this->m_corners.m_size );
    }
  }
  if ( this->m_links.m_size != 0 && this->m_links.m_data->m_startAreaIndex == 0 )
    bfx::PopFront<bfx::LinkConnectionData>(myArray: &this->m_links);
  v7 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v8 = 0;
    do
    {
      ++v7;
      v9 = &this->m_links.m_data[v8++];
      --v9->m_startAreaIndex;
    }
    while ( v7 < this->m_links.m_size );
  }
}


// ========================================================================
// ?RebuildAreaPath@SmartPath@bfx@@AAA_NXZ
// EA  : 0x83291060
// RVA : 0x01291060
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall bfx::SmartPath::RebuildAreaPath(bfx::SmartPath *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r4
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *p_m_areaHandles; // r20
  bfx::Array<bfx::Space *> *p_m_pathAreas; // r21
  unsigned int m_layer; // r11
  bfx::NavLayer *v10; // r25
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Space *m_pArea; // r23
  bfx::AreaProxy *v13; // r11
  bfx::Area *v14; // r26
  bfx::Area *v15; // r27
  bfx::Area *v16; // r29
  bfx::AreaProxy *v17; // r11
  bfx::Area *v18; // r10
  bfx::AreaProxy *v19; // r11
  bfx::Path *Path; // r25
  int m_size; // r4
  int v22; // r4
  int v23; // r30
  int v24; // r29
  bfx::Area *v25; // r27
  int v27; // [sp+8h] [-B8h]
  int v28; // [sp+Ch] [-B4h]
  int v29; // [sp+10h] [-B0h]
  int v30; // [sp+14h] [-ACh]
  bfx::HandleForAreaWithUsageCountTracking v31; // [sp+50h] [-70h] BYREF
  bfx::AreaProxy *v32; // [sp+54h] [-6Ch] BYREF

  LODWORD(a5) = bfx::g_displayPathRebuildWarnings;
  if ( bfx::g_displayPathRebuildWarnings )
  {
    HIDWORD(v6) = "rebuilding path\n";
    bfx::InternalWarning(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v27, a6: v28, a7: v29, a8: v30);
  }
  p_m_areaHandles = &this->m_areaHandles;
  this->m_pathAreas.m_size = 0;
  p_m_pathAreas = (bfx::Array<bfx::Space *> *)&this->m_pathAreas;
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(this: &this->m_areaHandles, size: 0);
  bfx::Array<bfx::AreaExitData>::shrink(this: &this->m_areaExits, size: 0);
  bfx::Array<bfx::LinkConnectionData>::shrink(this: &this->m_links, size: 0);
  m_layer = this->m_layer;
  if ( m_layer >= 0x20 )
    return 0;
  v10 = this->m_pPlanner->m_layers[m_layer];
  if ( v10 == nullptr )
    return 0;
  m_pProxy = this->m_snappedStartArea.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    m_pArea = (bfx::Space *)m_pProxy->m_pArea;
    v32 = this->m_snappedStartArea.m_pProxy;
  }
  else
  {
    m_pArea = nullptr;
  }
  if ( m_pArea == nullptr )
    return 0;
  v13 = this->m_snappedGoalArea.m_pProxy;
  if ( v13 != nullptr )
  {
    v14 = v13->m_pArea;
    v32 = this->m_snappedGoalArea.m_pProxy;
  }
  else
  {
    v14 = nullptr;
  }
  if ( v14 == nullptr )
    return 0;
  v15 = nullptr;
  v16 = nullptr;
  if ( this->m_pathSpec.m_usePathSharingPenalty )
  {
    v17 = this->m_inputStartArea.m_pProxy;
    if ( v17 != nullptr )
    {
      v18 = v17->m_pArea;
      v32 = this->m_inputStartArea.m_pProxy;
    }
    else
    {
      v18 = nullptr;
    }
    v19 = this->m_inputGoalArea.m_pProxy;
    v15 = v18;
    if ( v19 != nullptr )
    {
      v16 = v19->m_pArea;
      v32 = this->m_inputGoalArea.m_pProxy;
    }
    else
    {
      v16 = nullptr;
    }
    bfx::Handle<bfx::Area>::Release(this: &this->m_inputStartArea);
    bfx::Handle<bfx::Area>::Release(this: &this->m_inputGoalArea);
    bfx::Handle<bfx::Area>::Release(this: &this->m_snappedStartArea);
    bfx::Handle<bfx::Area>::Release(this: &this->m_snappedGoalArea);
  }
  Path = bfx::FindPath(
           pNavLayer: v10,
           startPos: &this->m_snappedStartPos,
           pStartArea: m_pArea,
           goalPos: &this->m_snappedGoalPos,
           pGoalArea: v14,
           pathSpec: &this->m_pathSpec,
           options: &this->m_pathCreationOptions);
  if ( this->m_pathSpec.m_usePathSharingPenalty )
  {
    bfx::Handle<bfx::Area>::operator=(this: &this->m_inputStartArea, pArea: v15);
    bfx::Handle<bfx::Area>::operator=(this: &this->m_inputGoalArea, pArea: v16);
    bfx::Handle<bfx::Area>::operator=(this: &this->m_snappedStartArea, pArea: (bfx::Area *)m_pArea);
    bfx::Handle<bfx::Area>::operator=(this: &this->m_snappedGoalArea, pArea: v14);
  }
  if ( Path == nullptr )
    return 0;
  m_size = Path->m_areas.m_size;
  if ( m_size > this->m_pathAreas.m_cap )
    bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_pathAreas, size: m_size);
  v22 = Path->m_areas.m_size;
  if ( v22 > this->m_areaHandles.m_cap )
    bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::expand_cap(this: &this->m_areaHandles, size: v22);
  v23 = 0;
  if ( Path->m_areas.m_size > 0 )
  {
    v24 = 0;
    do
    {
      v32 = (bfx::AreaProxy *)Path->m_areas.m_data[v24];
      v25 = (bfx::Area *)v32;
      bfx::Array<bfx::Portal *>::push_back(this: p_m_pathAreas, val: (bfx::Space *const *)&v32);
      bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(this: &v31, pArea: v25);
      bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::push_back(this: p_m_areaHandles, val: &v31);
      bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &v31);
      ++v23;
      ++v24;
    }
    while ( v23 < Path->m_areas.m_size );
  }
  ((void (__fastcall *)(bfx::Path *, int))Path->dtr_Path)(a1: Path, a2: 1);
  return 1;
}


// ========================================================================
// __unwind$32992
// EA  : 0x832912D4
// RVA : 0x012912D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_32992()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(v0 - 192 + 80));
}


// ========================================================================
// ?RebuildPathDataIfNeeded@SmartPath@bfx@@AAA_NXZ
// EA  : 0x83291308
// RVA : 0x01291308
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::RebuildPathDataIfNeeded(bfx::SmartPath *this)
{
  unsigned int m_layer; // r11
  bfx::NavLayer *v3; // r26
  unsigned int m_pathDataTimestamp; // r11
  char v5; // r11
  bool v6; // zf
  bool v7; // r27
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *v9; // r10
  bool v10; // r29
  unsigned int v11; // r11
  unsigned int v12; // r11
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  bfx::Array<bfx::Area *> *p_m_pathAreas; // r4
  bfx::AreaProxy *v17; // r11
  bfx::AreaExitData *v18; // r10
  bfx::AreaExitData *v19; // r10
  unsigned int v20; // r11
  int v21; // r10
  float m_x; // r9
  float m_y; // r7
  float m_z; // r5
  unsigned int v25; // r11
  unsigned int v26; // r11
  int m_size; // [sp+50h] [-90h]
  int v29; // [sp+50h] [-90h]
  bfx::AreaExitData v30; // [sp+60h] [-80h] BYREF

  if ( this->m_inputStartDataTimestamp != bfx::UNINITIALIZED_TIMESTAMP
    && this->m_inputGoalDataTimestamp != bfx::UNINITIALIZED_TIMESTAMP )
  {
    m_layer = this->m_layer;
    if ( m_layer < 0x20 )
    {
      v3 = this->m_pPlanner->m_layers[m_layer];
      if ( v3 != nullptr )
      {
        m_pathDataTimestamp = this->m_pathDataTimestamp;
        if ( this->m_layerTimestamp > m_pathDataTimestamp
          || this->m_pathSpecTimestamp > m_pathDataTimestamp
          || (v6 = this->m_pcoTimestamp <= m_pathDataTimestamp, v5 = 0, !v6) )
        {
          v5 = 1;
        }
        v7 = v5;
        if ( this->m_pathAreas.m_size == 0 )
          v7 = true;
        if ( !v7
          && LODWORD(this->m_areaInvalidationTimestamp) != LODWORD(v3->m_areaInvalidationTimestamp)
          && (unsigned __int8)bfx::AllHandlesInArrayValid(handles: &this->m_areaHandles) == 0 )
        {
          v7 = true;
        }
        if ( !v7 )
          v7 = (_cntlzw((unsigned __int8)bfx::SmartPath::AreAllCurrentLinksUsable(this)) & 0x20) != 0;
        if ( (unsigned __int8)bfx::SmartPath::RebuildSnappedStartDataIfNeeded(this) != 0 )
        {
          if ( !v7 )
          {
            m_pProxy = this->m_snappedStartArea.m_pProxy;
            v9 = m_pProxy != nullptr ? m_pProxy->m_pArea : nullptr;
            m_size = this->m_pathAreas.m_size;
            if ( m_size < 1 || v9 != *this->m_pathAreas.m_data )
            {
              if ( m_size >= 2 && v9 == this->m_pathAreas.m_data[1] )
              {
                v10 = this->m_cornerDataTimestamp >= this->m_pathDataTimestamp;
                bfx::SmartPath::RemoveFirstAreaFromPath(this, updateCornerData: v10);
                v11 = this->m_curTimestamp + 1;
                this->m_curTimestamp = v11;
                this->m_pathDataTimestamp = v11;
                if ( v10 )
                {
                  v12 = v11 + 1;
                  this->m_curTimestamp = v12;
                  this->m_cornerDataTimestamp = v12;
                }
              }
              else
              {
                v7 = true;
              }
            }
          }
          if ( (unsigned __int8)bfx::SmartPath::RebuildSnappedGoalDataIfNeeded(this) != 0 )
          {
            v17 = this->m_snappedGoalArea.m_pProxy;
            LODWORD(v13) = &this->m_snappedGoalArea;
            if ( v17 != nullptr )
              LODWORD(v14) = v17->m_pArea;
            else
              LODWORD(v14) = 0;
            if ( !v7 )
            {
              LODWORD(v13) = this->m_pathDataTimestamp;
              if ( this->m_snappedGoalDataTimestamp > (unsigned int)v13 )
              {
                v29 = this->m_pathAreas.m_size;
                if ( v29 >= 1
                  && (LODWORD(v13) = this->m_pathAreas.m_data,
                      p_m_pathAreas = &this->m_pathAreas,
                      HIDWORD(v13) = 4 * v29,
                      HIDWORD(v14) = 4 * v29 + v13,
                      LODWORD(v15) = *(_DWORD *)(HIDWORD(v14) - 4),
                      (_DWORD)v14 == (_DWORD)v15) )
                {
                  v18 = &this->m_areaExits.m_data[this->m_areaExits.m_size];
                  v18[-1].m_exitSeg.m_v0.m_x = this->m_snappedGoalPos.m_x;
                  v18[-1].m_exitSeg.m_v0.m_y = this->m_snappedGoalPos.m_y;
                  v18[-1].m_exitSeg.m_v0.m_z = this->m_snappedGoalPos.m_z;
                  v19 = &this->m_areaExits.m_data[this->m_areaExits.m_size];
                  v19[-1].m_exitSeg.m_v1.m_x = this->m_snappedGoalPos.m_x;
                  v19[-1].m_exitSeg.m_v1.m_y = this->m_snappedGoalPos.m_y;
                  v19[-1].m_exitSeg.m_v1.m_z = this->m_snappedGoalPos.m_z;
                  bfx::BuildIthUnwrappedData(
                    i: this->m_areaExits.m_size - 1,
                    pathAreas: p_m_pathAreas,
                    areaExits: &this->m_areaExits);
                  v20 = this->m_curTimestamp + 1;
                  this->m_curTimestamp = v20;
                  this->m_pathDataTimestamp = v20;
                }
                else if ( v29 >= 2
                       && (LODWORD(v13) = v29 - 2,
                           HIDWORD(v13) = this->m_pathAreas.m_data,
                           HIDWORD(v14) = 4 * (v29 - 2),
                           LODWORD(v15) = *(_DWORD *)(HIDWORD(v14) + HIDWORD(v13)),
                           (_DWORD)v14 == (_DWORD)v15) )
                {
                  --this->m_pathAreas.m_size;
                  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::pop_back(this: &this->m_areaHandles);
                  bfx::Array<bfx::AreaExitData>::pop_back(this: &this->m_areaExits);
                  v21 = this->m_links.m_size;
                  if ( v21 != 0 && this->m_links.m_data[v21 - 1].m_startAreaIndex >= this->m_pathAreas.m_size - 1 )
                    bfx::Array<bfx::LinkConnectionData>::pop_back(this: &this->m_links);
                  m_x = this->m_snappedGoalPos.m_x;
                  m_y = this->m_snappedGoalPos.m_y;
                  m_z = this->m_snappedGoalPos.m_z;
                  v30.m_exitType = EXIT_TYPE_GOAL;
                  v30.m_exitUnitVec.m_x = 0.0;
                  v30.m_exitUnitVec.m_y = 0.0;
                  HIBYTE(v30.m_exitLink.m_pProxy) = 0;
                  v30.m_exitUnitVec.m_z = 0.0;
                  *(bfx::HandleProxy **)((char *)&v30.m_exitLink.m_pProxy + 1) = (bfx::HandleProxy *)(*((_BYTE *)&v30 + 44) & 0xF);
                  v30.m_exitSeg.m_v0.m_x = m_x;
                  v30.m_exitSeg.m_v0.m_y = m_y;
                  v30.m_exitSeg.m_v0.m_z = m_z;
                  v30.m_exitSeg.m_v1.m_x = m_x;
                  v30.m_exitSeg.m_v1.m_y = m_y;
                  v30.m_exitSeg.m_v1.m_z = m_z;
                  bfx::AreaExitData::operator=(
                    this: &this->m_areaExits.m_data[this->m_areaExits.m_size - 1],
                    __that: &v30);
                  if ( v30.m_exitLink.m_pProxy != nullptr )
                    bfx::HandleProxy::RemRefToHandleProxy(this: v30.m_exitLink.m_pProxy);
                  bfx::BuildIthUnwrappedData(
                    i: this->m_areaExits.m_size - 1,
                    pathAreas: &this->m_pathAreas,
                    areaExits: &this->m_areaExits);
                  v25 = this->m_curTimestamp + 1;
                  this->m_curTimestamp = v25;
                  this->m_pathDataTimestamp = v25;
                }
                else
                {
                  v7 = true;
                }
              }
            }
            if ( v7 )
              bfx::SmartPath::ClearAllPathData(this);
            if ( this->m_pathAreas.m_size != 0 )
              goto LABEL_53;
            if ( (unsigned __int8)bfx::SmartPath::RebuildAreaPath(
                                    this,
                                    a2: (int)p_m_pathAreas,
                                    a3: v15,
                                    a4: v14,
                                    a5: v13) != 0
              && (unsigned __int8)bfx::BuildAreaExits(
                                    snappedStartPos: &this->m_snappedStartPos,
                                    snappedGoalPos: &this->m_snappedGoalPos,
                                    pathAreas: &this->m_pathAreas,
                                    pathSpec: &this->m_pathSpec,
                                    areaExitsOut: &this->m_areaExits,
                                    linkDataOut: &this->m_links) != 0 )
            {
              v26 = this->m_curTimestamp + 1;
              this->m_curTimestamp = v26;
              this->m_pathDataTimestamp = v26;
LABEL_53:
              this->m_areaInvalidationTimestamp = v3->m_areaInvalidationTimestamp;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// __unwind$33172
// EA  : 0x832917A8
// RVA : 0x012917A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_33172()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 224 + 96));
}


// ========================================================================
// ?CalcNextNCorners@SmartPath@bfx@@QAAPBV?$Array@VSmartPathCorner@bfx@@@2@ABVCalcCornersSpec@2@@Z
// EA  : 0x832917D0
// RVA : 0x012917D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

const bfx::Array<bfx::SmartPathCorner> *__fastcall bfx::SmartPath::CalcNextNCorners(
        bfx::SmartPath *this,
        bfx::CalcCornersSpec *calcCornersSpec)
{
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r4
  bfx::Array<bfx::SPCorner> *p_m_corners; // r28
  unsigned int m_cornerDataTimestamp; // r26
  const bfx::Vec3 *v11; // r6
  float *p_m_x; // r11
  double v13; // fp30
  double v14; // fp29
  double v15; // fp28
  double Scale; // fp1
  unsigned int v17; // r11
  int v18; // r7
  bfx::Array<bfx::SmartPathCorner> *v19; // r8
  char v20; // r29
  bfx::Array<bfx::SmartPathCorner> *v21; // r8
  unsigned int v22; // r11
  unsigned int v23; // r11
  int v24; // r7
  unsigned int v25; // r11
  bool *v26; // [sp+8h] [-108h]
  bfx::Array<bfx::SPCorner> *v27; // [sp+Ch] [-104h]
  int v28; // [sp+10h] [-100h]
  int v29; // [sp+14h] [-FCh]
  int v30; // [sp+18h] [-F8h]
  int v31; // [sp+1Ch] [-F4h]
  int v32; // [sp+20h] [-F0h]
  int v33; // [sp+24h] [-ECh]
  int v34; // [sp+28h] [-E8h]
  int v35; // [sp+2Ch] [-E4h]
  int v36; // [sp+30h] [-E0h]
  int v37; // [sp+34h] [-DCh]
  int v38; // [sp+38h] [-D8h]
  int v39; // [sp+3Ch] [-D4h]
  int v40; // [sp+40h] [-D0h]
  int v41; // [sp+44h] [-CCh]
  int v42; // [sp+48h] [-C8h]
  int v43; // [sp+4Ch] [-C4h]
  int v44; // [sp+50h] [-C0h]
  int v45; // [sp+58h] [-B8h]
  int v46; // [sp+60h] [-B0h]
  bfx::PathSpec v47; // [sp+70h] [-A0h] BYREF
  bfx::Vec3 v48[4]; // [sp+90h] [-80h] BYREF

  if ( calcCornersSpec->m_maxNumCorners <= 0 || calcCornersSpec->m_maxPathDist <= 0.0 )
  {
    this->m_outputCorners.m_size = 0;
    goto LABEL_23;
  }
  if ( (unsigned __int8)bfx::SmartPath::RebuildPathDataIfNeeded(this) == 0 )
    return nullptr;
  if ( (unsigned __int8)bfx::SmartPath::IsCornerRebuildNeeded(this) == 0 )
  {
    p_m_corners = &this->m_corners;
    HIDWORD(v7) = this->m_areaExits.m_data;
    if ( *(_DWORD *)(72 * this->m_corners.m_data[this->m_corners.m_size - 1].m_areaExitIndex + HIDWORD(v7) + 36) == 2
      || this->m_corners.m_size >= calcCornersSpec->m_maxNumCorners
      || (unsigned __int8)bfx::SmartPath::DistThroughCornersExceedsLimit(
                            this,
                            maxPathDist: calcCornersSpec->m_maxPathDist) != 0 )
    {
      m_cornerDataTimestamp = this->m_cornerDataTimestamp;
      if ( this->m_snappedStartPosChangedTimestamp > m_cornerDataTimestamp )
      {
        bfx::TransformPosIntoUnwrappedCoordinatesOfArea(
          result: v48,
          posG: &this->m_snappedStartPos,
          pArea: *(bfx::Vec3 **)this->m_pathAreas.m_data,
          areaExitData: (const bfx::AreaExitData *)HIDWORD(v7));
        bfx::GetNextCorner(
          startPos: v48,
          startIndex: 0,
          areaExits: &this->m_areaExits,
          maxShrinkDist: 0.0,
          pathStartPos: v11,
          nextCornerPosOut: v48,
          nextCornerIndexOut: (float *)&v47.m_usePathSharingPenalty,
          cornerFlavorOut: (bfx::CornerFlavor *)&v47.m_obstacleBlockageFlags,
          a9: &v47.m_areaUsageFlags);
        p_m_x = &p_m_corners->m_data->m_pos.m_x;
        HIDWORD(v5) = p_m_corners->m_data->m_areaExitIndex;
        if ( v47.m_obstacleBlockageFlags == HIDWORD(v5) )
        {
          v13 = (float)(*(float *)&v47.m_usePathSharingPenalty - p_m_x[3]);
          v14 = (float)(v47.m_pathSharingPenalty - p_m_x[4]);
          v15 = (float)(v47.m_maxPathSharingPenalty - p_m_x[5]);
          Scale = bfx::GetScale();
          if ( (float)((float)((float)v13 * (float)v13)
                     + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) <= (double)(float)((float)((float)Scale * (float)0.001) * (float)((float)Scale * (float)0.001)) )
          {
            this->m_outputCorners.m_size = 0;
            bfx::FillOutputCornerArrayFromCachedCorners(
              snappedStartPos: &this->m_snappedStartPos,
              pathAreas: &this->m_pathAreas,
              areaExits: &this->m_areaExits,
              realCorners: &this->m_corners,
              calcCornersSpec,
              maxShrinkDist: 0.0,
              cornersOut: (bfx::Array<bfx::SmartPathCorner> *)v6,
              a8: &this->m_outputCorners);
            v17 = this->m_curTimestamp + 1;
            this->m_outputCornersSpec.m_maxNumCorners = calcCornersSpec->m_maxNumCorners;
            this->m_outputCornersSpec.m_maxPathDist = calcCornersSpec->m_maxPathDist;
            v18 = *(_DWORD *)&calcCornersSpec->m_addCornersAtEveryAreaBoundary;
            this->m_curTimestamp = v17;
            *(_DWORD *)&this->m_outputCornersSpec.m_addCornersAtEveryAreaBoundary = v18;
            this->m_cornerDataTimestamp = v17;
            this->m_curTimestamp = v17 + 1;
            this->m_outputCornersTimestamp = v17 + 1;
            return &this->m_outputCorners;
          }
        }
        goto LABEL_16;
      }
      if ( (unsigned __int8)bfx::CalcCornersSpec::operator!=(this: calcCornersSpec, rhs: &this->m_outputCornersSpec) == 0
        && m_cornerDataTimestamp <= this->m_outputCornersTimestamp )
      {
        return &this->m_outputCorners;
      }
      bfx::FillOutputCornerArrayFromCachedCorners(
        snappedStartPos: &this->m_snappedStartPos,
        pathAreas: &this->m_pathAreas,
        areaExits: &this->m_areaExits,
        realCorners: &this->m_corners,
        calcCornersSpec,
        maxShrinkDist: 0.0,
        cornersOut: v19,
        a8: &this->m_outputCorners);
      this->m_outputCornersSpec.m_maxNumCorners = calcCornersSpec->m_maxNumCorners;
      this->m_outputCornersSpec.m_maxPathDist = calcCornersSpec->m_maxPathDist;
      *(_DWORD *)&this->m_outputCornersSpec.m_addCornersAtEveryAreaBoundary = *(_DWORD *)&calcCornersSpec->m_addCornersAtEveryAreaBoundary;
LABEL_23:
      v25 = this->m_curTimestamp + 1;
      this->m_curTimestamp = v25;
      this->m_outputCornersTimestamp = v25;
      return &this->m_outputCorners;
    }
  }
LABEL_16:
  LODWORD(v5) = bfx::g_displayPathRebuildWarnings;
  if ( bfx::g_displayPathRebuildWarnings )
  {
    HIDWORD(v8) = "rebuilding all corners";
    bfx::InternalWarning(fmt: v8, a2: v7, a3: v6, a4: v5, a5: (int)v26, a6: (int)v27, a7: v28, a8: v29);
  }
  this->m_corners.m_size = 0;
  v20 = bfx::CalcRealCorners(
          snappedStartPos: &this->m_snappedStartPos,
          snappedGoalPos: &this->m_snappedGoalPos,
          pathAreas: &this->m_pathAreas,
          areaExits: &this->m_areaExits,
          linkData: &this->m_links,
          maxNumCorners: calcCornersSpec->m_maxNumCorners,
          maxPathDist: calcCornersSpec->m_maxPathDist,
          pathSpec: &v47,
          performAdditionalSmoothing: &this->m_pathSpec,
          areaPathWasModifiedOut: v26,
          cornersOut: v27,
          a12: v28,
          a13: v29,
          a14: v30,
          a15: v31,
          a16: v32,
          a17: v33,
          a18: v34,
          a19: v35,
          a20: v36,
          a21: v37,
          a22: v38,
          a23: v39,
          a24: v40,
          a25: v41,
          a26: v42,
          a27: v43,
          a28: v44,
          a29: this->m_pathCreationOptions.m_performAdditionalSmoothing,
          a30: v45,
          a31: &v47,
          a32: v46,
          a33: &this->m_corners);
  if ( HIBYTE(v47.m_obstacleMode) != 0 )
  {
    bfx::SmartPath::RebuildAreaHandlesfFromAreas(this);
    v22 = this->m_curTimestamp + 1;
    this->m_curTimestamp = v22;
    this->m_pathDataTimestamp = v22;
  }
  if ( v20 == 0 )
    return nullptr;
  this->m_outputCorners.m_size = 0;
  bfx::FillOutputCornerArrayFromCachedCorners(
    snappedStartPos: &this->m_snappedStartPos,
    pathAreas: &this->m_pathAreas,
    areaExits: &this->m_areaExits,
    realCorners: &this->m_corners,
    calcCornersSpec,
    maxShrinkDist: 0.0,
    cornersOut: v21,
    a8: &this->m_outputCorners);
  v23 = this->m_curTimestamp + 1;
  this->m_outputCornersSpec.m_maxNumCorners = calcCornersSpec->m_maxNumCorners;
  this->m_outputCornersSpec.m_maxPathDist = calcCornersSpec->m_maxPathDist;
  v24 = *(_DWORD *)&calcCornersSpec->m_addCornersAtEveryAreaBoundary;
  this->m_curTimestamp = v23;
  *(_DWORD *)&this->m_outputCornersSpec.m_addCornersAtEveryAreaBoundary = v24;
  this->m_cornerDataTimestamp = v23;
  this->m_curTimestamp = v23 + 1;
  this->m_outputCornersTimestamp = v23 + 1;
  return &this->m_outputCorners;
}


// ========================================================================
// ?CalcCornersOnAreaPath@bfx@@YA_NABVVec3@1@0AAV?$Array@PAVArea@bfx@@@1@ABVPathSpec@1@_NHAAV?$Array@VSmartPathCorner@bfx@@@1@@Z
// EA  : 0x83291B78
// RVA : 0x01291B78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::CalcCornersOnAreaPath(
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *goalPos,
        bfx::Array<bfx::Area *> *areas,
        const bfx::PathSpec *pathSpec,
        char performAdditionalSmoothing,
        int maxNumRealCorners,
        bfx::Array<bfx::SmartPathCorner> *cornersOut)
{
  bool *v15; // [sp+8h] [-118h]
  bfx::Array<bfx::SPCorner> *v16; // [sp+Ch] [-114h]
  int v17; // [sp+10h] [-110h]
  int v18; // [sp+14h] [-10Ch]
  int v19; // [sp+18h] [-108h]
  int v20; // [sp+1Ch] [-104h]
  int v21; // [sp+20h] [-100h]
  int v22; // [sp+24h] [-FCh]
  int v23; // [sp+28h] [-F8h]
  int v24; // [sp+2Ch] [-F4h]
  int v25; // [sp+30h] [-F0h]
  int v26; // [sp+34h] [-ECh]
  int v27; // [sp+38h] [-E8h]
  int v28; // [sp+3Ch] [-E4h]
  int v29; // [sp+40h] [-E0h]
  int v30; // [sp+44h] [-DCh]
  int v31; // [sp+48h] [-D8h]
  int v32; // [sp+4Ch] [-D4h]
  int v33; // [sp+50h] [-D0h]
  int v34; // [sp+58h] [-C8h]
  int v35; // [sp+60h] [-C0h]
  bfx::PathSpec v36; // [sp+70h] [-B0h] BYREF
  bfx::Array<bfx::AreaExitData> v37; // [sp+90h] [-90h] BYREF
  bfx::Array<bfx::LinkConnectionData> v38; // [sp+A0h] [-80h] BYREF
  bfx::Array<bfx::SpaceComponent *> v39[7]; // [sp+B0h] [-70h] BYREF

  memset(&v37, 0, 12);
  v37.m_tag = bfx::MEM_BFXPLANNER;
  v38.m_tag = bfx::MEM_BFXPLANNER;
  memset(&v38, 0, 12);
  bfx::Array<bfx::AreaExitData>::expand_cap(this: &v37, size: 20);
  bfx::Array<bfx::LinkConnectionData>::expand_cap(this: &v38, size: 10);
  if ( (unsigned __int8)bfx::BuildAreaExits(
                          snappedStartPos: startPos,
                          snappedGoalPos: goalPos,
                          pathAreas: areas,
                          pathSpec,
                          areaExitsOut: &v37,
                          linkDataOut: &v38) != 0 )
  {
    memset(v39, 0, 12);
    v39[0].m_tag = bfx::MEM_BFXPLANNER;
    bfx::Array<bfx::GoalReachedData>::expand_cap(this: (bfx::Array<bfx::SPCorner> *)v39, size: 10);
    if ( (unsigned __int8)bfx::CalcRealCorners(
                            snappedStartPos: startPos,
                            snappedGoalPos: goalPos,
                            pathAreas: areas,
                            areaExits: &v37,
                            linkData: &v38,
                            maxNumCorners: maxNumRealCorners,
                            maxPathDist: 3.4028235e38,
                            pathSpec: &v36,
                            performAdditionalSmoothing: pathSpec,
                            areaPathWasModifiedOut: v15,
                            cornersOut: v16,
                            a12: v17,
                            a13: v18,
                            a14: v19,
                            a15: v20,
                            a16: v21,
                            a17: v22,
                            a18: v23,
                            a19: v24,
                            a20: v25,
                            a21: v26,
                            a22: v27,
                            a23: v28,
                            a24: v29,
                            a25: v30,
                            a26: v31,
                            a27: v32,
                            a28: v33,
                            a29: performAdditionalSmoothing,
                            a30: v34,
                            a31: &v36,
                            a32: v35,
                            a33: (bfx::Array<bfx::SPCorner> *)v39) != 0 )
    {
      *(float *)&v36.m_linkUsageFlags = 3.4028235e38;
      v36.m_usePathSharingPenalty = true;
      v36.m_areaUsageFlags = 0x7FFFFFFF;
      *(&v36.m_usePathSharingPenalty + 1) = true;
      bfx::FillOutputCornerArrayFromCachedCorners(
        snappedStartPos: startPos,
        pathAreas: areas,
        areaExits: &v37,
        realCorners: (const bfx::Array<bfx::SPCorner> *)v39,
        calcCornersSpec: (const bfx::CalcCornersSpec *)&v36.m_areaUsageFlags,
        maxShrinkDist: 0.0,
        cornersOut: (bfx::Array<bfx::SmartPathCorner> *)0x82000000,
        a8: cornersOut);
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v39);
      bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: &v38);
      bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(this: &v37);
      return 1;
    }
    else
    {
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v39);
      bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: &v38);
      bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(this: &v37);
      return 0;
    }
  }
  else
  {
    bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: &v38);
    bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(this: &v37);
    return 0;
  }
}


// ========================================================================
// __unwind$33517
// EA  : 0x83291D18
// RVA : 0x01291D18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_33517()
{
  int v0; // r12

  bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(this: (bfx::Array<bfx::AreaExitData> *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$33518
// EA  : 0x83291D40
// RVA : 0x01291D40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_33518()
{
  int v0; // r12

  bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: (bfx::Array<bfx::LinkConnectionData> *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$33519
// EA  : 0x83291D68
// RVA : 0x01291D68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void _unwind_33519()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 288 + 176));
}


// ========================================================================
// ?GetPosAlongPath@SmartPath@bfx@@QAA_NABVPosAlongPathSpecInternal@2@AAVPosAlongPathDataInternal@2@@Z
// EA  : 0x83291D90
// RVA : 0x01291D90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

int __fastcall bfx::SmartPath::GetPosAlongPath(
        bfx::SmartPath *this,
        const bfx::PosAlongPathSpecInternal *spec,
        bfx::PosAlongPathDataInternal *dataOut)
{
  float m_z; // r7
  int v5; // r30
  float m_y; // r6
  float m_x; // r11
  float v9; // r8
  double v10; // fp31
  bfx::Vec3 *p_m_directionOfApproach; // r28
  int result; // r3
  _DWORD *v15; // r7
  int v16; // r6
  int v17; // r5
  int v18; // r11
  int *v19; // r8
  _DWORD *v20; // r9
  int i; // ctr
  char *v22; // r10
  _DWORD *v23; // r11
  int j; // ctr
  double v25; // fp9
  double v26; // fp5
  double v27; // fp0
  double v28; // fp8
  double v29; // fp4
  double v30; // fp13
  double v31; // fp7
  double v32; // fp3
  double v33; // fp12
  double v34; // fp11
  bfx::Vec3 *v35; // r11
  int v36; // r11
  double v37; // fp12
  bfx::Area *v38; // r6
  double v39; // fp10
  bfx::HalfLink *v40; // r11
  bfx::HalfLink *v41; // r11
  bfx::CalcCornersSpec v42; // [sp+50h] [-A0h] BYREF
  char v43; // [sp+5Ch] [-94h] BYREF
  float v44; // [sp+60h] [-90h]
  float v45; // [sp+64h] [-8Ch]
  float v46; // [sp+68h] [-88h]
  int v47; // [sp+70h] [-80h]
  bfx::HalfLink *v48; // [sp+74h] [-7Ch]
  bfx::Area *v49; // [sp+78h] [-78h]
  int v50; // [sp+7Ch] [-74h] BYREF
  float v51; // [sp+80h] [-70h]
  float v52; // [sp+84h] [-6Ch]
  float v53; // [sp+88h] [-68h]
  int v54; // [sp+90h] [-60h]
  bfx::HalfLink *v55; // [sp+94h] [-5Ch]
  float v56; // [sp+9Ch] [-54h]
  float v57; // [sp+A0h] [-50h]
  float v58; // [sp+A4h] [-4Ch]

  m_z = bfx::ZERO_VEC.m_z;
  v5 = 0;
  m_y = bfx::ZERO_VEC.m_y;
  m_x = bfx::ZERO_VEC.m_x;
  v9 = bfx::ZERO_VEC.m_z;
  dataOut->m_pos.m_x = bfx::ZERO_VEC.m_x;
  v10 = 0.0;
  dataOut->m_type = POS_ON_SURFACE_INTERNAL;
  v53 = m_z;
  v57 = m_y;
  v56 = m_x;
  v58 = v9;
  dataOut->m_pathDistToPos = 0.0;
  v52 = m_y;
  dataOut->m_pArea = nullptr;
  dataOut->m_pos.m_y = m_y;
  dataOut->m_pHalfLink = nullptr;
  dataOut->m_pos.m_z = m_z;
  v42.m_maxNumCorners = 0x7FFFFFFF;
  dataOut->m_directionOfApproach.m_x = m_x;
  v42.m_addCornersAtEveryAreaBoundary = true;
  dataOut->m_directionOfApproach.m_y = m_y;
  v42.m_addCornerAtStartingPosition = true;
  dataOut->m_directionOfApproach.m_z = v9;
  _FP7 = (float)(spec->m_distAlongPath - (float)1.0842022e-19);
  __asm { fsel      f6, f7, f8, f0 }
  v42.m_maxPathDist = _FP6;
  v51 = m_x;
  p_m_directionOfApproach = &dataOut->m_directionOfApproach;
  result = (int)bfx::SmartPath::CalcNextNCorners(this, calcCornersSpec: &v42);
  v15 = (_DWORD *)result;
  if ( result != 0 )
  {
    v16 = 0;
    v17 = *(_DWORD *)(result + 4) - 1;
    if ( v17 <= 0 )
    {
LABEL_14:
      v36 = 28 * v15[1] + *v15;
      dataOut->m_pos.m_x = *(float *)(v36 - 28);
      dataOut->m_pos.m_y = *(float *)(v36 - 24);
      v37 = *(float *)(v36 - 20);
      dataOut->m_type = POS_AT_GOAL_INTERNAL;
      dataOut->m_pos.m_z = v37;
      v38 = *(bfx::Area **)(28 * v15[1] + *v15 - 4);
      dataOut->m_pathDistToPos = v10;
      dataOut->m_pArea = v38;
      return 1;
    }
    else
    {
      while ( 1 )
      {
        v18 = v5 + *(_DWORD *)result;
        v19 = &v50;
        v20 = (_DWORD *)(v18 - 4);
        for ( i = 7; i != 0; --i )
          *++v19 = *++v20;
        v22 = &v43;
        v23 = (_DWORD *)(v18 + 24);
        for ( j = 7; j != 0; --j )
        {
          ++v23;
          v22 += 4;
          *(_DWORD *)v22 = *v23;
        }
        v25 = v45;
        v26 = v52;
        v27 = (float)(v45 - v52);
        v28 = v46;
        v29 = v53;
        v30 = (float)(v46 - v53);
        v31 = v44;
        v32 = v51;
        v33 = (float)(v44 - v51);
        v34 = __fsqrts((float)((float)((float)(v44 - v51) * (float)(v44 - v51))
                             + (float)((float)((float)(v46 - v53) * (float)(v46 - v53))
                                     + (float)((float)(v45 - v52) * (float)(v45 - v52)))));
        if ( v34 <= 1.0842022e-19 )
        {
          v35 = &bfx::ZERO_VEC;
        }
        else
        {
          v35 = (bfx::Vec3 *)&v42;
          *(float *)&v42.m_maxNumCorners = (float)((float)1.0 / (float)v34) * (float)(v44 - v51);
          v42.m_maxPathDist = (float)((float)1.0 / (float)v34) * (float)(v45 - v52);
          *(float *)&v42.m_addCornersAtEveryAreaBoundary = (float)((float)1.0 / (float)v34) * (float)(v46 - v53);
        }
        v10 = (float)((float)v34 + (float)v10);
        p_m_directionOfApproach->m_x = v35->m_x;
        p_m_directionOfApproach->m_y = v35->m_y;
        p_m_directionOfApproach->m_z = v35->m_z;
        if ( v10 > spec->m_distAlongPath )
          break;
        if ( spec->m_stopAtLink && v47 == 1 )
        {
          v41 = v48;
          dataOut->m_pos.m_x = v31;
          dataOut->m_pos.m_y = v25;
          dataOut->m_type = POS_ON_LINK_INTERNAL;
          dataOut->m_pos.m_z = v28;
          dataOut->m_pathDistToPos = v10;
          dataOut->m_pHalfLink = v41;
          return 1;
        }
        ++v16;
        v5 += 28;
        if ( v16 >= v17 )
          goto LABEL_14;
      }
      if ( v34 <= 1.0842022e-19 )
      {
        dataOut->m_pos.m_x = v32;
        dataOut->m_pos.m_y = v26;
        dataOut->m_pos.m_z = v29;
      }
      else
      {
        v39 = (float)((float)v10 - spec->m_distAlongPath);
        dataOut->m_pos.m_y = (float)v25
                           - (float)((float)v27 * (float)((float)((float)v10 - spec->m_distAlongPath) / (float)v34));
        dataOut->m_pos.m_x = (float)v31 - (float)((float)v33 * (float)((float)v39 / (float)v34));
        dataOut->m_pos.m_z = (float)v28 - (float)((float)v30 * (float)((float)v39 / (float)v34));
      }
      if ( v54 == 1 )
      {
        v40 = v55;
        result = 1;
        dataOut->m_type = POS_ON_LINK_INTERNAL;
        dataOut->m_pHalfLink = v40;
      }
      else
      {
        result = 1;
        dataOut->m_pArea = v49;
      }
      dataOut->m_pathDistToPos = spec->m_distAlongPath;
    }
  }
  return result;
}


// ========================================================================
// ?GetNextLink@SmartPath@bfx@@QAAPAVHalfLink@2@XZ
// EA  : 0x832920C0
// RVA : 0x012920C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

bfx::HalfLink *__fastcall bfx::SmartPath::GetNextLink(bfx::SmartPath *this)
{
  bfx::HandleProxy *m_pProxy; // r11

  if ( (unsigned __int8)bfx::SmartPath::RebuildPathDataIfNeeded(this) != 0
    && this->m_links.m_size != 0
    && (m_pProxy = this->m_links.m_data->m_link.m_pProxy) != nullptr )
  {
    return (bfx::HalfLink *)m_pProxy->m_pTarget;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?HasPath@SmartPath@bfx@@QAA_NXZ
// EA  : 0x83292130
// RVA : 0x01292130
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

BOOL __fastcall bfx::SmartPath::HasPath(bfx::SmartPath *this)
{
  return (unsigned __int8)bfx::SmartPath::RebuildPathDataIfNeeded(this) != 0;
}


// ========================================================================
// ?GetPathAreas@SmartPath@bfx@@QAAPBV?$Array@PAVArea@bfx@@@2@AAH@Z
// EA  : 0x83292160
// RVA : 0x01292160
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

const bfx::Array<bfx::Area *> *__fastcall bfx::SmartPath::GetPathAreas(
        bfx::SmartPath *this,
        int *numAreasInFirstSurfaceSectionOut)
{
  int m_size; // r11

  *numAreasInFirstSurfaceSectionOut = 0;
  if ( (unsigned __int8)bfx::SmartPath::RebuildPathDataIfNeeded(this) == 0 )
    return nullptr;
  if ( this->m_links.m_size != 0 )
    m_size = this->m_links.m_data->m_startAreaIndex + 1;
  else
    m_size = this->m_pathAreas.m_size;
  *numAreasInFirstSurfaceSectionOut = m_size;
  return &this->m_pathAreas;
}


// ========================================================================
// bfx::`dynamic initializer for 'g_displayPathRebuildWarningsRestore''
// EA  : 0x83398D58
// RVA : 0x01398D58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_displayPathRebuildWarningsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_displayPathRebuildWarningsRestore);
  bfx::g_displayPathRebuildWarningsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_displayPathRebuildWarningsRestore.m_targetBool = &bfx::g_displayPathRebuildWarnings;
  bfx::g_displayPathRebuildWarningsRestore.m_name = "smart_path_display_path_rebuild_warnings";
  bfx::g_displayPathRebuildWarningsRestore.m_defaultBool = bfx::g_displayPathRebuildWarnings;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_displayPathRebuildWarningsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawAreasRestore''
// EA  : 0x83398DD0
// RVA : 0x01398DD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawAreasRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawAreasRestore);
  bfx::g_drawAreasRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawAreasRestore.m_targetBool = &bfx::g_drawAreas;
  bfx::g_drawAreasRestore.m_name = "smart_path_draw_areas";
  bfx::g_drawAreasRestore.m_defaultBool = bfx::g_drawAreas;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawAreasRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawGlobalAreaExitsRestore''
// EA  : 0x83398E48
// RVA : 0x01398E48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawGlobalAreaExitsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawGlobalAreaExitsRestore);
  bfx::g_drawGlobalAreaExitsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawGlobalAreaExitsRestore.m_targetBool = &bfx::g_drawGlobalAreaExits;
  bfx::g_drawGlobalAreaExitsRestore.m_name = "smart_path_draw_global_area_exits";
  bfx::g_drawGlobalAreaExitsRestore.m_defaultBool = bfx::g_drawGlobalAreaExits;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawGlobalAreaExitsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawUnwrappedAreaExitsRestore''
// EA  : 0x83398EC0
// RVA : 0x01398EC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawUnwrappedAreaExitsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawUnwrappedAreaExitsRestore);
  bfx::g_drawUnwrappedAreaExitsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawUnwrappedAreaExitsRestore.m_targetBool = &bfx::g_drawUnwrappedAreaExits;
  bfx::g_drawUnwrappedAreaExitsRestore.m_name = "smart_path_draw_unwrapped_area_exits";
  bfx::g_drawUnwrappedAreaExitsRestore.m_defaultBool = bfx::g_drawUnwrappedAreaExits;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawUnwrappedAreaExitsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawInteriorVerticesRestore''
// EA  : 0x83398F38
// RVA : 0x01398F38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawInteriorVerticesRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawInteriorVerticesRestore);
  bfx::g_drawInteriorVerticesRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawInteriorVerticesRestore.m_targetBool = &bfx::g_drawInteriorVertices;
  bfx::g_drawInteriorVerticesRestore.m_name = "smart_path_draw_interior_vertices";
  bfx::g_drawInteriorVerticesRestore.m_defaultBool = bfx::g_drawInteriorVertices;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawInteriorVerticesRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawCornersRestore''
// EA  : 0x83398FB0
// RVA : 0x01398FB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsmartpath.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawCornersRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawCornersRestore);
  bfx::g_drawCornersRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawCornersRestore.m_targetBool = &bfx::g_drawCorners;
  bfx::g_drawCornersRestore.m_name = "smart_path_draw_corners";
  bfx::g_drawCornersRestore.m_defaultBool = bfx::g_drawCorners;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawCornersRestore__);
}

