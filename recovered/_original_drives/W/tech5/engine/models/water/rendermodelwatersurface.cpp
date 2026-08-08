
// ========================================================================
// WaterGenJob
// EA  : 0x8288DB70
// RVA : 0x0088DB70
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall WaterGenJob(
        const deferredWaterBlockGenParms_t *parms,
        int a2,
        int a3,
        int a4,
        int a5,
        _BYTE *a6,
        long double a7)
{
  ApplyDisturbances(parms, a2: a7, a3: a2, a4: a3, a5: a4, a6: a5, a7: a6);
  GenWaterSurface(parms, prevHM: parms->prevBlock);
}


// ========================================================================
// ?CreateGeometryInternal@idRenderModelWaterSurface@@CAXPBVidMaterial@@PBDABVidVec3@@HHMHHHHPAVidDrawVert@@PAGAAVidBounds@@@Z
// EA  : 0x8288DBA8
// RVA : 0x0088DBA8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelWaterSurface::CreateGeometryInternal(
        const idMaterial *mtr,
        const char *imgName,
        const idVec3 *org,
        signed int width,
        signed int height,
        double spacing,
        const int numBlocksX,
        int numBlocksY,
        int numVerts,
        const int numIndices,
        idDrawVert *verts,
        unsigned __int16 *indices,
        idBounds *bounds,
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
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        float *numVerts_0)
{
  int v43; // r14
  int v44; // r20
  bool v45; // r26
  int v46; // r23
  int v47; // r27
  int v48; // r24
  int v49; // r17
  int v50; // r28
  _WORD *v51; // r30
  int v52; // r3
  int v53; // r29
  int v54; // r3
  __int16 v55; // r5
  __int16 v56; // r4
  __int16 v57; // r3
  __int16 v58; // r10
  int v59; // r23
  int v67; // r24
  int v68; // r14
  int i; // r20
  int j; // r25
  __int64 v71; // r10 OVERLAPPED
  double v72; // fp28
  double v73; // fp29
  __int64 v74; // r4
  __int64 v75; // r7
  double x; // fp3
  int v77; // r11
  unsigned __int8 *v81; // r7
  double v82; // fp0
  double v83; // fp13
  unsigned __int8 *v84; // r10
  int v85; // r9
  float *v86; // r10
  double v88; // fp11
  double v89; // fp10
  double v90; // fp9
  double v91; // fp8
  double v92; // fp7
  double v98; // fp4
  double v102; // fp5
  double v105; // fp0
  double v112; // fp3
  double v114; // fp12
  double v115; // fp13
  double v123; // fp3
  double v126; // fp0
  double v127; // fp11
  double v128; // fp13
  double v129; // fp10
  double v130; // fp12
  double v136; // fp8
  double v137; // fp7
  double v143; // fp3
  double v145; // fp13
  float *v156; // r10
  int v157; // ctr
  double v159; // fp11
  double v160; // fp10
  double v161; // fp9
  double v162; // fp8
  double v163; // fp7
  unsigned __int8 *v175; // [sp+50h] [-120h] BYREF
  unsigned int v176; // [sp+54h] [-11Ch] BYREF
  unsigned int v177; // [sp+58h] [-118h] BYREF
  unsigned __int64 v178; // [sp+60h] [-110h] BYREF
  __int64 v179; // [sp+68h] [-108h] BYREF
  __int64 v180; // [sp+70h] [-100h] BYREF
  int v181; // [sp+78h] [-F8h] BYREF
  int v182; // [sp+7Ch] [-F4h] BYREF
  int v183[2]; // [sp+80h] [-F0h] BYREF
  __int64 v184; // [sp+88h] [-E8h]
  unsigned __int64 v185; // [sp+90h] [-E0h]
  __int64 v186; // [sp+98h] [-D8h]
  int v188; // [sp+A4h] [-CCh]
  int v190; // [sp+ACh] [-C4h]

  v43 = numVerts;
  v44 = height - 1;
  v45 = false;
  v46 = 0;
  v47 = 0;
  if ( height - 1 > 0 )
  {
    v48 = width - 1;
    v49 = width % 2;
    do
    {
      v50 = 0;
      if ( v48 > 0 )
      {
        v51 = (_WORD *)(2 * v46 + a35 - 2);
        v46 += 6 * v48;
        do
        {
          GridPosToBlockLoc(gridX: v50, gridY: v47, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: (int *)&v178);
          v52 = v50;
          if ( !v45 )
            v52 = v50 + 1;
          GridPosToBlockLoc(gridX: v52, gridY: v47 + 1, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: (int *)&v179);
          v53 = v50 + 1;
          GridPosToBlockLoc(gridX: v50 + 1, gridY: v47, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: (int *)&v180);
          v54 = v50 + 1;
          if ( !v45 )
            v54 = v50;
          GridPosToBlockLoc(gridX: v54, gridY: v47, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: &v181);
          GridPosToBlockLoc(gridX: v50, gridY: v47 + 1, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: &v182);
          GridPosToBlockLoc(gridX: ++v50, gridY: v47 + 1, numBlocksX: numBlocksY, numBlocksY: v43, blockPos: v183);
          v45 = (_cntlzw(v45) & 0x20) != 0;
          v55 = WORD1(v179);
          v56 = v182;
          v57 = WORD1(v180);
          v58 = v181;
          v51[1] = WORD1(v178);
          v51[2] = v55;
          v51[3] = v57;
          v51[4] = v58;
          v51[5] = v56;
          v51 += 6;
          *v51 = v183[0];
        }
        while ( v53 < v48 );
      }
      if ( v49 != 0 )
        v45 = (_cntlzw(v45) & 0x20) != 0;
      ++v47;
    }
    while ( v47 < v44 );
  }
  v59 = 0;
  v177 = 0;
  v176 = 0;
  v175 = nullptr;
  R_LoadImage(cname: imgName, pic: &v175, width: (int *)&v177, height: (int *)&v176, timestamp: nullptr);
  if ( v43 > 0 )
  {
    _R19 = &_real_3f800000;
    _R26 = 1;
    _R27 = 2;
    _R17 = &_real_00000000;
    _R30 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R29 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R28 = &_vmx_3f8000003f8000003f8000003f800000;
    do
    {
      v67 = 0;
      if ( numBlocksY > 0 )
      {
        do
        {
          v68 = 0;
          for ( i = 0; i < 256; i += 16 )
          {
            for ( j = 0; j < 16; ++j )
            {
              BlockToGridPos(blockLocX: v67, blockLocY: v59, blockX: j, blockY: v68, gridX: v183, gridY: &v182);
              if ( v183[0] < width )
              {
                LODWORD(v71) = v182;
                if ( v182 < height )
                {
                  HIDWORD(v71) = v183[0];
                  v179 = *(__int64 *)((char *)&v71 + 4);
                  v180 = v71;
                  v72 = (float)((float)v71 * (float)spacing);
                  v73 = (float)((float)*(__int64 *)((char *)&v71 + 4) * (float)spacing);
                  BlockPosToBlockLoc(blockX: v67, blockY: v59, numBlocksX: numBlocksY, offset: &v181);
                  LODWORD(v75) = width;
                  x = org->x;
                  v184 = v75;
                  v178 = __PAIR64__(width, height);
                  __asm { vspltisw128 v63, 0 }
                  v77 = 32 * (v181 + i + j) + a33;
                  __asm
                  {
                    vor128    v62, v95, v63
                    vor128    v61, v95, v63
                  }
                  _R10 = v77 + 24;
                  *(float *)v77 = (float)x + (float)v73;
                  *(float *)(v77 + 4) = org->y + (float)v72;
                  *(float *)(v77 + 8) = org->z;
                  *(float *)(v77 + 16) = (float)v72
                                       / (float)((float)((float)__SPAIR64__(width, height) - (float)1.0) * (float)spacing);
                  *(float *)(v77 + 12) = (float)v73 / (float)((float)((float)v75 - (float)1.0) * (float)spacing);
                  __asm
                  {
                    lvlx128   v60, r0, r17
                    lvx128    v63, r0, r28
                    lvx128    v13, r0, r30
                    lvx128    v0, r0, r29
                    lvlx128   v59, r0, r19
                    vrlimi128 v62, v59, 8, 0
                    vrlimi128 v62, v60, 4, 3
                    vrlimi128 v61, v60, 8, 0
                    vrlimi128 v62, v60, 2, 2
                    vrlimi128 v61, v60, 4, 3
                    vaddfp128 v12, v94, v63
                    vrlimi128 v61, v59, 2, 2
                    vmaddfp   v0, v12, v0, v13
                    vcfpsxws128 v58, v0, 0
                    vpkswss128 v57, v90, v58
                    vpkshus128 v0, v89, v57
                    stvebx    v0, 0, r10
                    stvebx    v0, r10, r26
                    stvebx    v0, r10, r27
                  }
                  _R10 = v77 + 20;
                  __asm
                  {
                    lvx128    v0, r0, r29
                    lvx128    v13, r0, r30
                    lvx128    v63, r0, r28
                    vaddfp128 v12, v93, v63
                    vmaddfp   v0, v12, v0, v13
                    vcfpsxws128 v56, v0, 0
                    vpkswss128 v55, v88, v56
                    vpkshus128 v0, v87, v55
                    stvebx    v0, 0, r10
                    stvebx    v0, r10, r26
                    stvebx    v0, r10, r27
                  }
                  v81 = v175;
                  *(_BYTE *)(v77 + 27) = -1;
                  if ( v81 != nullptr )
                  {
                    v82 = *(float *)(v77 + 12);
                    v83 = *(float *)(v77 + 16);
                    LODWORD(v74) = v177;
                    v186 = v74;
                    v185 = __PAIR64__(v177, v176);
                    v190 = (int)(float)((float)((float)v74 - (float)1.0) * (float)v82);
                    v188 = (int)(float)((float)((float)__SPAIR64__(v177, v176) - (float)1.0) * (float)v83);
                    v84 = &v81[4 * v188 * v177 + 4 * v190];
                    *(_BYTE *)(v77 + 28) = *v84;
                    *(_BYTE *)(v77 + 29) = v84[1];
                    *(_BYTE *)(v77 + 30) = v84[2];
                    *(_BYTE *)(v77 + 31) = v84[3];
                  }
                  else
                  {
                    *(_BYTE *)(v77 + 28) = -1;
                    *(_BYTE *)(v77 + 29) = -1;
                    *(_BYTE *)(v77 + 30) = -1;
                    *(_BYTE *)(v77 + 31) = -1;
                  }
                }
              }
            }
            ++v68;
          }
          ++v67;
        }
        while ( v67 < numBlocksY );
        v43 = numVerts;
      }
      ++v59;
    }
    while ( v59 < v43 );
  }
  if ( v175 != nullptr )
    idMem::Free(this: &mem, ptr: v175, align: ALIGN_16);
  v85 = 0;
  numVerts_0[2] = 1.0e30;
  numVerts_0[1] = 1.0e30;
  *numVerts_0 = 1.0e30;
  numVerts_0[5] = -1.0e30;
  numVerts_0[4] = -1.0e30;
  numVerts_0[3] = -1.0e30;
  if ( a29 >= 4 )
  {
    v86 = (float *)(a33 + 40);
    do
    {
      _FP12 = (float)(*numVerts_0 - *(v86 - 10));
      v88 = numVerts_0[1];
      v89 = numVerts_0[2];
      v90 = numVerts_0[3];
      v85 += 4;
      v91 = numVerts_0[4];
      v92 = numVerts_0[5];
      __asm { fsel      f6, f12, f0, f13 }
      *numVerts_0 = _FP6;
      _FP2 = (float)((float)v88 - *(v86 - 9));
      __asm { fsel      f1, f2, f5, f11 }
      numVerts_0[1] = _FP1;
      _FP12 = (float)((float)v89 - *(v86 - 8));
      __asm { fsel      f11, f12, f0, f10 }
      numVerts_0[2] = _FP11;
      v98 = _FP6;
      _FP6 = (float)(*(v86 - 10) - (float)v90);
      __asm { fsel      f5, f6, f10, f9 }
      numVerts_0[3] = _FP5;
      _FP1 = (float)(*(v86 - 9) - (float)v91);
      v102 = numVerts_0[1];
      __asm { fsel      f0, f1, f3, f8 }
      numVerts_0[4] = _FP0;
      _FP12 = (float)(*(v86 - 8) - (float)v92);
      v105 = numVerts_0[2];
      __asm { fsel      f10, f12, f13, f7 }
      numVerts_0[5] = _FP10;
      _FP8 = (float)((float)v98 - *(v86 - 2));
      __asm { fsel      f7, f8, f9, f4 }
      *numVerts_0 = _FP7;
      _FP3 = (float)((float)v102 - *(v86 - 1));
      __asm { fsel      f2, f3, f6, f5 }
      numVerts_0[1] = _FP2;
      _FP12 = (float)((float)v105 - *v86);
      v112 = numVerts_0[4];
      __asm { fsel      f10, f12, f1, f0 }
      numVerts_0[2] = _FP10;
      v114 = *numVerts_0;
      v115 = numVerts_0[5];
      _FP7 = (float)(*(v86 - 2) - numVerts_0[3]);
      __asm { fsel      f6, f7, f8, f9 }
      numVerts_0[3] = _FP6;
      _FP2 = (float)(*(v86 - 1) - (float)v112);
      __asm { fsel      f1, f2, f5, f3 }
      numVerts_0[4] = _FP1;
      _FP9 = (float)(*v86 - (float)v115);
      __asm { fsel      f8, f9, f0, f13 }
      numVerts_0[5] = _FP8;
      _FP6 = (float)((float)v114 - v86[6]);
      v123 = numVerts_0[1];
      __asm { fsel      f5, f6, f7, f12 }
      *numVerts_0 = _FP5;
      _FP2 = (float)((float)v123 - v86[7]);
      v126 = numVerts_0[2];
      v127 = _FP8;
      v128 = numVerts_0[3];
      v129 = _FP5;
      v130 = numVerts_0[4];
      __asm { fsel      f9, f2, f4, f3 }
      numVerts_0[1] = _FP9;
      _FP7 = (float)((float)v126 - v86[8]);
      __asm { fsel      f5, f7, f8, f0 }
      numVerts_0[2] = _FP5;
      _FP3 = (float)(v86[6] - (float)v128);
      __asm { fsel      f2, f3, f4, f13 }
      numVerts_0[3] = _FP2;
      v136 = _FP5;
      v137 = _FP2;
      _FP0 = (float)(v86[7] - (float)v130);
      __asm { fsel      f12, f0, f1, f12 }
      numVerts_0[4] = _FP12;
      _FP5 = (float)(v86[8] - (float)v127);
      __asm { fsel      f2, f5, f6, f11 }
      numVerts_0[5] = _FP2;
      _FP0 = (float)((float)v129 - v86[14]);
      v143 = _FP12;
      __asm { fsel      f12, f0, f1, f10 }
      *numVerts_0 = _FP12;
      v145 = _FP2;
      _FP10 = (float)((float)_FP9 - v86[15]);
      __asm { fsel      f5, f10, f11, f9 }
      numVerts_0[1] = _FP5;
      _FP2 = (float)((float)v136 - v86[16]);
      __asm { fsel      f0, f2, f4, f8 }
      numVerts_0[2] = _FP0;
      _FP11 = (float)(v86[14] - (float)v137);
      __asm { fsel      f10, f11, f12, f7 }
      numVerts_0[3] = _FP10;
      _FP8 = (float)(v86[15] - (float)v143);
      __asm { fsel      f6, f8, f9, f3 }
      numVerts_0[4] = _FP6;
      _FP4 = (float)(v86[16] - (float)v145);
      __asm { fsel      f2, f4, f5, f13 }
      numVerts_0[5] = _FP2;
      v86 += 32;
    }
    while ( v85 < a29 - 3 );
  }
  if ( v85 < a29 )
  {
    v156 = (float *)(32 * v85 + a33);
    v157 = a29 - v85;
    do
    {
      _FP12 = (float)(*numVerts_0 - *v156);
      v159 = numVerts_0[1];
      v160 = numVerts_0[2];
      v161 = numVerts_0[3];
      v162 = numVerts_0[4];
      v163 = numVerts_0[5];
      __asm { fsel      f6, f12, f0, f13 }
      *numVerts_0 = _FP6;
      _FP3 = (float)((float)v159 - v156[1]);
      __asm { fsel      f2, f3, f5, f11 }
      numVerts_0[1] = _FP2;
      _FP0 = (float)((float)v160 - v156[2]);
      __asm { fsel      f13, f0, f1, f10 }
      numVerts_0[2] = _FP13;
      _FP11 = (float)(*v156 - (float)v161);
      __asm { fsel      f10, f11, f12, f9 }
      numVerts_0[3] = _FP10;
      _FP5 = (float)(v156[1] - (float)v162);
      __asm { fsel      f4, f5, f9, f8 }
      numVerts_0[4] = _FP4;
      _FP2 = (float)(v156[2] - (float)v163);
      __asm { fsel      f1, f2, f3, f7 }
      numVerts_0[5] = _FP1;
      v156 += 8;
      --v157;
    }
    while ( v157 != 0 );
  }
}


// ========================================================================
// ?FreeData@idRenderModelWaterSurface@@AAAXXZ
// EA  : 0x8288E3B8
// RVA : 0x0088E3B8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall idRenderModelWaterSurface::FreeData(idRenderModelWaterSurface *this)
{
  idWaterSurfaceSim *waterSim; // r30
  idVertexBuffer *vertexBuffer; // r29
  int i; // r30

  waterSim = this->waterSim;
  if ( waterSim != nullptr )
  {
    idWaterSurfaceSim::~idWaterSurfaceSim(this: this->waterSim);
    idMem::Free(this: &mem, ptr: waterSim, align: ALIGN_16);
    this->waterSim = nullptr;
  }
  if ( this->deferredVerts != nullptr )
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffer[this->currentIndex]);
  vertexBuffer = this->vertexBuffer;
  this->deferredVerts = nullptr;
  for ( i = 3; i != 0; --i )
    idVertexBuffer::FreeBufferObject(this: vertexBuffer++);
  idIndexBuffer::FreeBufferObject(this: &this->indexBuffer);
  idMem::Free(this: &mem, ptr: this->waterGenBlockParms, align: ALIGN_16);
  this->waterGenBlockParms = nullptr;
}


// ========================================================================
// ?UpdateInView@idRenderModelWaterSurface@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x8288E460
// RVA : 0x0088E460
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

int __fastcall idRenderModelWaterSurface::UpdateInView(
        idRenderModelWaterSurface *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  idPixelUnpackBuffer *v6; // r3
  idRenderModelSurface *list; // r11
  int v8; // r11
  idDrawVert *v9; // r3
  idWaterSurfaceSim *waterSim; // r11
  deferredWaterBlockGenParms_t *waterGenBlockParms; // r25
  int v12; // r27
  int numBlocksY; // r18
  int currentDeferred; // r10
  int valueInteger; // r21
  float *v16; // r17
  int numBlocksX; // r28
  float *v18; // r22
  int v19; // r24
  int v20; // r29
  float *p_z; // r31
  idWaterSurfaceSim *v22; // r11
  int v23; // r26
  int v24; // r9
  int v25; // r10
  float *v26; // r11
  float *v27; // r11
  float *v28; // r11
  float *v29; // r11
  int v30; // r7
  int v31; // r6
  int v32; // r5
  int v33; // r4
  long double v34; // fp2
  int v35; // r11
  idDrawVert *deferredVerts; // r8
  int v38; // [sp+50h] [-B0h] BYREF
  int v39; // [sp+54h] [-ACh] BYREF
  int v40; // [sp+58h] [-A8h] BYREF
  int v41; // [sp+5Ch] [-A4h] BYREF
  int v42; // [sp+60h] [-A0h] BYREF

  if ( r_skipWaterSurfaces.valueInteger != 0 || this->surfaces.num == 0 || this->waterSim == nullptr )
    return 0;
  if ( this->deferredVerts != nullptr )
  {
    v6 = (idPixelUnpackBuffer *)&this->vertexBuffer[this->currentIndex];
    if ( v6->size < 0 )
      idVertexBuffer::UnmapBuffer(this: v6);
  }
  list = this->surfaces.list;
  if ( list == nullptr )
    return 0;
  idVertexBuffer::Reference(this: &list->geometry->vertexBuffer, other: &this->vertexBuffer[this->currentIndex]);
  v8 = this->currentIndex + 1;
  this->currentIndex = v8 % 3;
  v9 = (idDrawVert *)idVertexBuffer::MapBuffer(this: &this->vertexBuffer[v8 % 3], mapType: BM_WRITE_NOSYNC);
  waterSim = this->waterSim;
  this->deferredVerts = v9;
  waterGenBlockParms = this->waterGenBlockParms;
  v12 = 0;
  numBlocksY = waterSim->numBlocksY;
  currentDeferred = waterSim->currentDeferred;
  valueInteger = r_useWaterSimulationJobs.valueInteger;
  v16 = waterSim->dummyBlock.list;
  numBlocksX = waterSim->numBlocksX;
  v18 = waterSim->waveHeight[currentDeferred].list;
  v19 = *(int *)((char *)&waterSim->waveHeight[0].list + ((currentDeferred * 16) ^ 0x10));
  if ( numBlocksY > 0 )
  {
    do
    {
      v20 = 0;
      if ( numBlocksX > 0 )
      {
        p_z = &waterGenBlockParms->waterOrg.z;
        do
        {
          *((_WORD *)p_z - 21) = v12;
          *((_WORD *)p_z - 22) = v20;
          v22 = this->waterSim;
          *(p_z - 2) = v22->origin.x;
          *(p_z - 1) = v22->origin.y;
          *p_z = v22->origin.z;
          *((_WORD *)p_z + 2) = this->waterSim->width;
          *((_WORD *)p_z + 3) = this->waterSim->height;
          BlockPosToBlockLoc(blockX: v20, blockY: v12, numBlocksX, offset: &v38);
          v23 = v20 + 1;
          BlockPosToBlockLoc(blockX: v20 - 1, blockY: v12, numBlocksX, offset: &v39);
          BlockPosToBlockLoc(blockX: v20 + 1, blockY: v12, numBlocksX, offset: &v40);
          BlockPosToBlockLoc(blockX: v20, blockY: v12 - 1, numBlocksX, offset: &v41);
          BlockPosToBlockLoc(blockX: v20, blockY: v12 + 1, numBlocksX, offset: &v42);
          v24 = v38;
          v25 = v38;
          waterGenBlockParms->currBlock = (float *)(4 * v38 + v19);
          if ( v20 < 1 )
            v26 = v16;
          else
            v26 = (float *)(4 * v39 + v19);
          *((_DWORD *)p_z - 15) = v26;
          if ( v20 >= numBlocksX - 1 )
            v27 = v16;
          else
            v27 = (float *)(4 * v40 + v19);
          *((_DWORD *)p_z - 14) = v27;
          if ( v12 < 1 )
            v28 = v16;
          else
            v28 = (float *)(4 * v41 + v19);
          *((_DWORD *)p_z - 13) = v28;
          if ( v12 >= numBlocksY - 1 )
            v29 = v16;
          else
            v29 = (float *)(4 * v42 + v19);
          *((_DWORD *)p_z - 12) = v29;
          *((_DWORD *)p_z - 10) = &this->waterSim->simulateParms.list[v25];
          *((_DWORD *)p_z - 9) = &this->waterSim->vertGradient.list[v24];
          *(p_z - 8) = *(float *)&this->waterSim->waterDisturbances[this->waterSim->currentDeferred].list;
          *(p_z - 7) = *(float *)&this->waterSim->numDisturbances;
          *(p_z - 6) = this->waterSim->spacing;
          *(p_z - 5) = this->waterSim->speed;
          *(p_z - 4) = this->waterSim->damping;
          *(double *)&v34 = idWaterSurfaceSim::GetTimeStep(this: this->waterSim);
          v35 = v38;
          *(p_z - 3) = *(double *)&v34;
          deferredVerts = this->deferredVerts;
          *((_DWORD *)p_z + 2) = &deferredVerts[v35];
          *((_DWORD *)p_z + 3) = &v18[v35];
          if ( valueInteger == 1 )
          {
            idParallelJobList::AddJob(
              this: updateTools->renderModelJobList,
              function: (void (__fastcall *)(void *))WaterGenJob,
              data: waterGenBlockParms);
          }
          else
          {
            ApplyDisturbances(parms: waterGenBlockParms, a2: v34, a3: v33, a4: v32, a5: v31, a6: v30, a7: deferredVerts);
            GenWaterSurface(parms: waterGenBlockParms, prevHM: *((const float **)p_z + 3));
          }
          ++waterGenBlockParms;
          p_z += 20;
          ++v20;
        }
        while ( v23 < numBlocksX );
      }
      ++v12;
    }
    while ( v12 < numBlocksY );
  }
  idWaterSurfaceSim::Swap(this: this->waterSim);
  return 1;
}


// ========================================================================
// ?CheckValid@idRenderModelWaterSurface@@QAA_NPBVidWaterSurfaceSim@@ABVidBounds@@@Z
// EA  : 0x8288E7E8
// RVA : 0x0088E7E8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

int __fastcall idRenderModelWaterSurface::CheckValid(
        idRenderModelWaterSurface *this,
        const idWaterSurfaceSim *_waterSim,
        const idBounds *waterSimBounds)
{
  int result; // r3
  idTriangles *geometry; // r10

  if ( idLib::production == PROD_PRODUCTION )
    return 1;
  if ( this->waterSim == nullptr )
    return 0;
  if ( this->surfaces.num != 1 )
    return 0;
  geometry = this->surfaces.list->geometry;
  if ( geometry == nullptr )
    return 0;
  if ( geometry->numVerts != (_waterSim->numBlocksY * _waterSim->numBlocksX) << 8 )
    return 0;
  result = 1;
  if ( geometry->numIndexes != (6 * _waterSim->height - 6) * (_waterSim->width - 1) )
    return 0;
  return result;
}


// ========================================================================
// ?CreateGeometry@idRenderModelWaterSurface@@AAAXPBVidMaterial@@PBDABVidVec3@@HHMHH@Z
// EA  : 0x8288E888
// RVA : 0x0088E888
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall idRenderModelWaterSurface::CreateGeometry(
        idRenderModelWaterSurface *this,
        const idMaterial *mtr,
        const char *imgName,
        const idVec3 *org,
        signed int width,
        signed int height,
        double spacing,
        const int numBlocksX,
        int numBlocksY,
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
        int a29)
{
  int v37; // r26
  int v38; // r22
  int v39; // r25
  void *v40; // r23
  void *v41; // r24
  int v42; // r30
  idVertexBuffer *vertexBuffer; // r27
  idTriangles *v44; // r30
  idTriangles *v45; // r3
  double v46; // fp12
  double v47; // fp11
  double v48; // fp10
  double v49; // fp9
  int v50; // [sp+8h] [-178h]
  __int64 v51; // [sp+8h] [-178h]
  idDrawVert *v52; // [sp+Ch] [-174h]
  unsigned __int16 *v53; // [sp+10h] [-170h]
  __int64 v54; // [sp+10h] [-170h]
  idBounds *v55; // [sp+14h] [-16Ch]
  int v56; // [sp+18h] [-168h]
  __int64 v57; // [sp+18h] [-168h]
  int v58; // [sp+1Ch] [-164h]
  int v59; // [sp+20h] [-160h]
  __int64 v60; // [sp+20h] [-160h]
  int v61; // [sp+24h] [-15Ch]
  int v62; // [sp+28h] [-158h]
  __int64 v63; // [sp+28h] [-158h]
  int v64; // [sp+2Ch] [-154h]
  int v65; // [sp+30h] [-150h]
  __int64 v66; // [sp+30h] [-150h]
  int v67; // [sp+34h] [-14Ch]
  int v68; // [sp+38h] [-148h]
  __int64 v69; // [sp+38h] [-148h]
  int v70; // [sp+3Ch] [-144h]
  int v71; // [sp+40h] [-140h]
  __int64 v72; // [sp+40h] [-140h]
  int v73; // [sp+44h] [-13Ch]
  int v74; // [sp+48h] [-138h]
  __int64 v75; // [sp+48h] [-138h]
  int v76; // [sp+4Ch] [-134h]
  int v77; // [sp+50h] [-130h]
  __int64 v78; // [sp+50h] [-130h]
  int v79; // [sp+58h] [-128h]
  int v80; // [sp+60h] [-120h]
  int v81; // [sp+68h] [-118h]
  int v82; // [sp+70h] [-110h]
  float v83[8]; // [sp+90h] [-F0h] BYREF
  idRenderModel *v84; // [sp+B0h] [-D0h]
  idRenderModelSurface *v85; // [sp+B4h] [-CCh]
  idTriangles *v86; // [sp+C0h] [-C0h]
  char v87; // [sp+C4h] [-BCh]
  char v88; // [sp+C5h] [-BBh]
  unsigned int v89; // [sp+C8h] [-B8h]
  int v90; // [sp+CCh] [-B4h]
  unsigned int v91; // [sp+D0h] [-B0h]
  int v92; // [sp+D4h] [-ACh]
  unsigned int v93; // [sp+D8h] [-A8h]
  float v94; // [sp+DCh] [-A4h]
  __int64 v95; // [sp+E0h] [-A0h]

  v37 = (numBlocksY * a29) << 8;
  v38 = (numBlocksY * a29) << 13;
  v39 = 6 * (width - 1) * (height - 1);
  this->FreeSurfaces(this);
  v40 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface.cpp(268) : TAG_WATER",
          size: (numBlocksY * a29) << 13,
          tag: TAG_WATER,
          zeroBuffer: true,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v41 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface.cpp(269) : TAG_WATER",
          size: 12 * (width - 1) * (height - 1),
          tag: TAG_WATER,
          zeroBuffer: true,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  idRenderModelWaterSurface::CreateGeometryInternal(
    mtr,
    imgName,
    org,
    width,
    height,
    spacing,
    numBlocksX: (const int)v83,
    numBlocksY,
    numVerts: a29,
    numIndices: v50,
    verts: v52,
    indices: v53,
    bounds: v55,
    a14: v56,
    a15: v58,
    a16: v59,
    a17: v61,
    a18: v62,
    a19: v64,
    a20: v65,
    a21: v67,
    a22: v68,
    a23: v70,
    a24: v71,
    a25: v73,
    a26: v74,
    a27: v76,
    a28: v77,
    a29: (numBlocksY * a29) << 8,
    a30: v79,
    a31: 6 * (width - 1) * (height - 1),
    a32: v80,
    a33: (int)v40,
    a34: v81,
    a35: (int)v41,
    a36: v82,
    numVerts_0: v83);
  idIndexBuffer::AllocBufferObject(this: &this->indexBuffer, data: v41, allocSize: 2 * v39, allocUsage: BU_DYNAMIC);
  v42 = 3;
  vertexBuffer = this->vertexBuffer;
  do
  {
    idVertexBuffer::AllocBufferObject(
      this: vertexBuffer,
      data: v40,
      allocSize: v38,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    --v42;
    ++vertexBuffer;
  }
  while ( v42 != 0 );
  v84 = (idRenderModel *)mtr;
  v44 = nullptr;
  v85 = nullptr;
  *(float *)&v93 = 0.0;
  v94 = 0.0;
  *(float *)&v95 = 0.0;
  *((float *)&v95 + 1) = 0.0;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v45 = (idTriangles *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x84u,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v45 != nullptr )
    v44 = idTriangles::idTriangles(this: v45);
  v44->bounds.b[0].x = v83[0];
  v46 = v83[2];
  v47 = v83[3];
  v86 = v44;
  v48 = v83[4];
  v44->bounds.b[0].y = v83[1];
  v44->bounds.b[0].z = v46;
  v44->bounds.b[1].x = v47;
  v49 = v83[5];
  v44->bounds.b[1].y = v48;
  v44->bounds.b[1].z = v49;
  v44->numVerts = v37;
  v44->numIndexes = v39;
  idVertexBuffer::Reference(this: &v44->vertexBuffer, other: this->vertexBuffer);
  idIndexBuffer::Reference(this: &v44->indexBuffer, other: &this->indexBuffer);
  idRenderModel::AddSurface(
    this: v84,
    surf: v85,
    a3: __SPAIR64__((unsigned int)v86, v89),
    a4: __SPAIR64__(v91, v93),
    a5: v95,
    a6: v51,
    a7: v54,
    a8: v57,
    a9: v60,
    a10: v63,
    a11: v66,
    a12: v69,
    a13: v72,
    a14: v75,
    a15: v78);
  idRenderModel::FinishSurfaces(this);
  idMem::Free(this: &mem, ptr: v40, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v41, align: ALIGN_16);
}


// ========================================================================
// __unwind$231126
// EA  : 0x8288EB00
// RVA : 0x0088EB00
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231126()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 128), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?Save@idRenderModelWaterSurface@@EBAXPAVidFile@@@Z
// EA  : 0x8288EB30
// RVA : 0x0088EB30
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall idRenderModelWaterSurface::Save(idRenderModelWaterSurface *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  const idMaterial *material; // r11
  bool v6[8]; // [sp+50h] [-20h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  v6[0] = this->material != nullptr;
  v4->Write(this: fp, a2: v6, a3: 1u);
  material = this->material;
  if ( material != nullptr )
    idFile::WriteString(this: fp, string: material->name.str);
  fp->Write(this: fp, a2: &this->waterSimParms.waterBounds, a3: 24u);
  fp->Write(this: fp, a2: &this->waterSimParms, a3: 4u);
  fp->Write(this: fp, a2: &this->waterSimParms.damping, a3: 4u);
  fp->Write(this: fp, a2: &this->waterSimParms.speed, a3: 4u);
  fp->Write(this: fp, a2: &this->waterSimParms.timeStep, a3: 4u);
}


// ========================================================================
// ?WriteBinary@idRenderModelWaterSurface@@AAA_NPBD@Z
// EA  : 0x8288EC40
// RVA : 0x0088EC40
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

int __fastcall idRenderModelWaterSurface::WriteBinary(idRenderModelWaterSurface *this, const char *modelName)
{
  idFile *v4; // r3
  idTriangles *geometry; // r29
  const void *v7; // r3
  idIndexBuffer *p_indexBuffer; // r30
  const void *v9; // r3
  idFileLocal v10[12]; // [sp+50h] [-30h] BYREF

  idLib::Printf(fmt: "Writing %s\n", modelName);
  v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: modelName, a3: 0);
  v10[0].file = v4;
  if ( v4 != nullptr )
  {
    v4->Write(this: v4, a2: &WATERSURFACE_MODEL_MAGIC, a3: 4u);
    idFile::WriteString(this: v10[0].file, string: this->material->name.str);
    v10[0].file->Write(this: v10[0].file, a2: &this->waterSimParms, a3: 4u);
    v10[0].file->Write(this: v10[0].file, a2: &this->waterSimParms.damping, a3: 4u);
    v10[0].file->Write(this: v10[0].file, a2: &this->waterSimParms.speed, a3: 4u);
    v10[0].file->Write(this: v10[0].file, a2: &this->waterSimParms.timeStep, a3: 4u);
    v10[0].file->Write(this: v10[0].file, a2: &this->waterSimParms.waterBounds, a3: 24u);
    geometry = this->surfaces.list->geometry;
    v10[0].file->Write(this: v10[0].file, a2: geometry, a3: 24u);
    v10[0].file->Write(this: v10[0].file, a2: &geometry->numVerts, a3: 4u);
    v10[0].file->Write(this: v10[0].file, a2: &geometry->numIndexes, a3: 4u);
    v7 = idVertexBuffer::MapBuffer(this: this->vertexBuffer, mapType: BM_READ);
    v10[0].file->Write(this: v10[0].file, a2: v7, a3: 32 * geometry->numVerts);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)this->vertexBuffer);
    p_indexBuffer = &this->indexBuffer;
    v9 = idIndexBuffer::MapBuffer(this: p_indexBuffer, mapType: BM_READ);
    v10[0].file->Write(this: v10[0].file, a2: v9, a3: 2 * geometry->numIndexes);
    idIndexBuffer::UnmapBuffer(this: p_indexBuffer);
    idFileLocal::~idFileLocal(this: v10);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idWaterSurfaceModelData::WriteBinary() - Could not open %s", modelName);
    idFileLocal::~idFileLocal(this: v10);
    return 0;
  }
}


// ========================================================================
// __unwind$231384
// EA  : 0x8288EE50
// RVA : 0x0088EE50
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231384()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 80));
}


// ========================================================================
// ??1idRenderModelWaterSurface@@MAA@XZ
// EA  : 0x8288EE80
// RVA : 0x0088EE80
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall idRenderModelWaterSurface::~idRenderModelWaterSurface(idRenderModelWaterSurface *this)
{
  this->__vftable = (idRenderModelWaterSurface_vtbl *)&idRenderModelWaterSurface::`vftable';
  idRenderModelWaterSurface::FreeData(this);
  idIndexBuffer::~idIndexBuffer(this: &this->indexBuffer);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231632
// EA  : 0x8288EEF0
// RVA : 0x0088EEF0
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231632()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231633
// EA  : 0x8288EF18
// RVA : 0x0088EF18
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231633()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 2036),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$231634
// EA  : 0x8288EF54
// RVA : 0x0088EF54
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231634()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 112 + 132) + 2084));
}


// ========================================================================
// ?BuildWaterModel@idRenderModelWaterSurface@@QAAXPBVidMaterial@@ABVidBounds@@MMMMPBD@Z
// EA  : 0x8288EF88
// RVA : 0x0088EF88
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __fastcall idRenderModelWaterSurface::BuildWaterModel(
        idRenderModelWaterSurface *this,
        const idMaterial *mtr,
        const idBounds *waterBounds,
        double spacing,
        double damping,
        double speed,
        double timeStep,
        const char *imgName,
        int a9,
        int a10,
        int a11,
        const char *a12)
{
  idWaterSurfaceSim *v20; // r3
  idWaterSurfaceSim *v21; // r3
  double y; // fp13
  idWaterSurfaceSim *waterSim; // r5
  int numBlocksX; // r25
  int numBlocksY; // r20
  signed int width; // r22
  signed int height; // r21
  deferredWaterBlockGenParms_t *v28; // r3
  idWaterSurfaceSim *v29; // r11
  int v30; // r9
  char *v31; // r24
  int i; // r28
  int j; // r29
  int v34; // r23
  int k; // r26
  int m; // r30
  unsigned __int8 *v37; // r11
  int v38; // [sp+8h] [-208h]
  int v39; // [sp+Ch] [-204h]
  int v40; // [sp+10h] [-200h]
  int v41; // [sp+14h] [-1FCh]
  int v42; // [sp+18h] [-1F8h]
  int v43; // [sp+1Ch] [-1F4h]
  int v44; // [sp+20h] [-1F0h]
  int v45; // [sp+24h] [-1ECh]
  int v46; // [sp+28h] [-1E8h]
  int v47; // [sp+2Ch] [-1E4h]
  int v48; // [sp+30h] [-1E0h]
  int v49; // [sp+34h] [-1DCh]
  int v50; // [sp+38h] [-1D8h]
  int v51; // [sp+3Ch] [-1D4h]
  int v52; // [sp+40h] [-1D0h]
  int v53; // [sp+44h] [-1CCh]
  int v54; // [sp+48h] [-1C8h]
  int v55; // [sp+4Ch] [-1C4h]
  int v56; // [sp+50h] [-1C0h]
  idVec3 *v57; // [sp+60h] [-1B0h] BYREF
  unsigned int v58; // [sp+64h] [-1ACh] BYREF
  unsigned int v59; // [sp+68h] [-1A8h] BYREF
  idVec4 v60; // [sp+70h] [-1A0h] BYREF
  char v61[288]; // [sp+80h] [-190h] BYREF

  idRenderModelWaterSurface::FreeData(this);
  v20 = (idWaterSurfaceSim *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xB4u,
                               tag: TAG_WATER,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  v57 = (idVec3 *)v20;
  if ( v20 != nullptr )
    v21 = idWaterSurfaceSim::idWaterSurfaceSim(this: v20, bounds: waterBounds, s: spacing, damping, speed, timeStep);
  else
    v21 = nullptr;
  this->waterSim = v21;
  this->waterSimParms.spacing = spacing;
  this->waterSimParms.damping = damping;
  this->waterSimParms.speed = speed;
  this->waterSimParms.timeStep = timeStep;
  this->waterSimParms.waterBounds.b[0].x = waterBounds->b[0].x;
  v57 = &waterBounds->b[1];
  y = waterBounds->b[0].y;
  v57 = &this->waterSimParms.waterBounds.b[1];
  this->waterSimParms.waterBounds.b[0].y = y;
  this->waterSimParms.waterBounds.b[0].z = waterBounds->b[0].z;
  this->waterSimParms.waterBounds.b[1].x = waterBounds->b[1].x;
  this->waterSimParms.waterBounds.b[1].y = waterBounds->b[1].y;
  this->waterSimParms.waterBounds.b[1].z = waterBounds->b[1].z;
  this->material = mtr;
  waterSim = this->waterSim;
  numBlocksX = waterSim->numBlocksX;
  numBlocksY = waterSim->numBlocksY;
  width = waterSim->width;
  height = waterSim->height;
  v28 = (deferredWaterBlockGenParms_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface.cpp(456) : TAG_WATER",
                                          size: 80 * numBlocksY * numBlocksX,
                                          tag: TAG_WATER,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  v29 = this->waterSim;
  this->waterGenBlockParms = v28;
  idRenderModelWaterSurface::CreateGeometry(
    this,
    mtr,
    imgName: a12,
    org: &v29->origin,
    width,
    height,
    spacing: v29->spacing,
    numBlocksX: v30,
    numBlocksY: numBlocksX,
    a10: v38,
    a11: v39,
    a12: v40,
    a13: v41,
    a14: v42,
    a15: v43,
    a16: v44,
    a17: v45,
    a18: v46,
    a19: v47,
    a20: v48,
    a21: v49,
    a22: v50,
    a23: v51,
    a24: v52,
    a25: v53,
    a26: v54,
    a27: v55,
    a28: v56,
    a29: numBlocksY);
  idRenderModel::SetParm(this, parm: (const idDeclRenderParm *)rpWaterHeight.r, scalar: this->waterSim->origin.z);
  idRenderModel::CommitThisFrame(this);
  v31 = (char *)idVertexBuffer::MapBuffer(this: this->vertexBuffer, mapType: BM_READ);
  for ( i = 0; i < numBlocksY; ++i )
  {
    for ( j = 0; j < numBlocksX; ++j )
    {
      v34 = 0;
      for ( k = 0; k < 256; k += 16 )
      {
        for ( m = 0; m < 16; ++m )
        {
          BlockToGridPos(blockLocX: j, blockLocY: i, blockX: m, blockY: v34, gridX: (int *)&v59, gridY: (int *)&v58);
          if ( (int)v59 >= 1 && v59 <= width - 2 && (int)v58 >= 1 && v58 <= height - 2 )
          {
            BlockPosToBlockLoc(blockX: j, blockY: i, numBlocksX, offset: (int *)&v57);
            v37 = (unsigned __int8 *)&v31[32 * ((_DWORD)v57 + k + m)];
            idColor::UnpackColor(
              color: ((((__ROL4__(v37[31], 8) | v37[30]) << 8) | v37[29]) << 8) | v37[28],
              unpackedColor: &v60);
            if ( v60.z <= 0.5 )
              v60.z = 0.0;
            else
              v60.z = 1.0;
            idWaterSurfaceSim::SetSimulationParms(this: this->waterSim, gridX: v59, gridY: v58, parms: &v60);
          }
        }
        ++v34;
      }
    }
  }
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)this->vertexBuffer);
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "wmodel", a4: this->name.str, a5: v61, a6: 256);
  idRenderModelWaterSurface::WriteBinary(this, modelName: v61);
}


// ========================================================================
// __unwind$231755
// EA  : 0x8288F2BC
// RVA : 0x0088F2BC
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231755()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 528 + 96), tag: TAG_WATER);
}


// ========================================================================
// ?Load@idRenderModelWaterSurface@@EAA_NPAVidFile@@@Z
// EA  : 0x8288F2F0
// RVA : 0x0088F2F0
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

BOOL __fastcall idRenderModelWaterSurface::Load(idRenderModelWaterSurface *this, idFile *fp)
{
  idFile_vtbl *v4; // r11
  const idMaterial *v6; // r3
  char v7; // [sp+50h] [-60h] BYREF
  idStr v8[2]; // [sp+60h] [-50h] BYREF

  if ( (unsigned __int8)idRenderModel::Load(this, fp) == 0 )
    return false;
  v4 = fp->__vftable;
  v7 = 0;
  if ( v4->Read(this: fp, a2: &v7, a3: 1u) == 0 )
    return false;
  if ( v7 != 0 )
  {
    v8[0].len = 0;
    v8[0].baseBuffer[0] = 0;
    v8[0].allocedAndFlag = 20;
    v8[0].data = v8[0].baseBuffer;
    if ( idFile::ReadString(this: fp, string: v8) == 0 )
    {
      idStr::FreeData(this: v8);
      return false;
    }
    if ( v8[0].data != nullptr )
      v6 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v8[0].data,
                                 makeDefault: true);
    else
      v6 = nullptr;
    this->material = v6;
    idStr::FreeData(this: v8);
  }
  if ( fp->Read(this: fp, a2: &this->waterSimParms.waterBounds, a3: 24u) == 0
    || fp->Read(this: fp, a2: &this->waterSimParms, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->waterSimParms.damping, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->waterSimParms.speed, a3: 4u) == 0 )
  {
    return false;
  }
  return fp->Read(this: fp, a2: &this->waterSimParms.timeStep, a3: 4u) != 0;
}


// ========================================================================
// __unwind$231929
// EA  : 0x8288F478
// RVA : 0x0088F478
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_231929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?LoadBinary@idRenderModelWaterSurface@@AAA_NPBD@Z
// EA  : 0x8288F4A8
// RVA : 0x0088F4A8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

int __fastcall idRenderModelWaterSurface::LoadBinary(idRenderModelWaterSurface *this, char *modelName)
{
  idFileResource *v3; // r3
  idFile_Memory *File; // r3
  idFile *v5; // r15
  const idMaterial *v7; // r3
  idTriangles *v8; // r3
  idTriangles *v9; // r30
  idFile_vtbl *v10; // r11
  idFile_vtbl *v11; // r9
  idFile_vtbl *v12; // r7
  char *v13; // r17
  void *v14; // r3
  idFile_vtbl *v15; // r8
  int numVerts; // r7
  void *v17; // r28
  int v18; // r28
  idVertexBuffer *vertexBuffer; // r27
  idWaterSurfaceSim *waterSim; // r30
  idMem *v21; // r25
  idWaterSurfaceSim *v22; // r3
  idWaterSurfaceSim *v23; // r3
  int i; // r28
  int j; // r29
  int v26; // r26
  int k; // r27
  int m; // r30
  idWaterSurfaceSim *v29; // r11
  unsigned int v30; // r9
  unsigned __int8 *v31; // r11
  __int64 v32; // [sp+8h] [-198h]
  __int64 v33; // [sp+10h] [-190h]
  __int64 v34; // [sp+18h] [-188h]
  __int64 v35; // [sp+20h] [-180h]
  __int64 v36; // [sp+28h] [-178h]
  __int64 v37; // [sp+30h] [-170h]
  __int64 v38; // [sp+38h] [-168h]
  __int64 v39; // [sp+40h] [-160h]
  __int64 v40; // [sp+48h] [-158h]
  __int64 v41; // [sp+50h] [-150h]
  idMem *v42; // [sp+60h] [-140h] BYREF
  void *p_numVerts; // [sp+64h] [-13Ch]
  idWaterSurfaceSim *v44; // [sp+68h] [-138h] BYREF
  unsigned int v45; // [sp+6Ch] [-134h] BYREF
  int v46; // [sp+70h] [-130h] BYREF
  idFileResource *v47; // [sp+74h] [-12Ch]
  idRenderModel *material; // [sp+80h] [-120h]
  idRenderModelSurface *v49; // [sp+84h] [-11Ch]
  idTriangles *v50; // [sp+90h] [-110h]
  char v51; // [sp+94h] [-10Ch]
  char v52; // [sp+95h] [-10Bh]
  unsigned int v53; // [sp+98h] [-108h]
  int v54; // [sp+9Ch] [-104h]
  unsigned int v55; // [sp+A0h] [-100h]
  int v56; // [sp+A4h] [-FCh]
  unsigned int v57; // [sp+A8h] [-F8h]
  float v58; // [sp+ACh] [-F4h]
  __int64 v59; // [sp+B0h] [-F0h]
  idVec4 v60; // [sp+C0h] [-E0h] BYREF
  idStr v61; // [sp+D0h] [-D0h] BYREF
  idWaterSurfaceSim *v62; // [sp+F0h] [-B0h]

  v3 = (idFileResource *)idResourceList::Load(
                           this: &idFileResource::resourceList,
                           name: modelName,
                           makeDefault: true,
                           skipStaleCheck: false);
  v47 = v3;
  if ( v3 == nullptr )
    return 0;
  if ( (int)v3->length <= 0 )
    return 0;
  File = idFileResource::GetFile(this: v3);
  v5 = File;
  if ( File == nullptr || (int)File->Length(this: File) <= 0 )
    return 0;
  v46 = 0;
  v5->Read(this: v5, a2: &v46, a3: 4u);
  if ( v46 != 72109399 )
  {
    idLib::Warning(fmt: "idRenderModelWaterSurface::LoadBinary - Bad magic");
    return 0;
  }
  v61.len = 0;
  v61.baseBuffer[0] = 0;
  v61.allocedAndFlag = 20;
  v61.data = v61.baseBuffer;
  idFile::ReadString(this: v5, string: &v61);
  if ( v61.data != nullptr )
    v7 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: v61.data,
                               makeDefault: true);
  else
    v7 = nullptr;
  this->material = v7;
  v5->Read(this: v5, a2: &this->waterSimParms, a3: 4u);
  v5->Read(this: v5, a2: &this->waterSimParms.damping, a3: 4u);
  v5->Read(this: v5, a2: &this->waterSimParms.speed, a3: 4u);
  v5->Read(this: v5, a2: &this->waterSimParms.timeStep, a3: 4u);
  v5->Read(this: v5, a2: &this->waterSimParms.waterBounds, a3: 24u);
  v49 = nullptr;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  *(float *)&v57 = 0.0;
  v58 = 0.0;
  *(float *)&v59 = 0.0;
  *((float *)&v59 + 1) = 0.0;
  v42 = &mem;
  v56 = 0;
  material = (idRenderModel *)this->material;
  v8 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  p_numVerts = v8;
  if ( v8 != nullptr )
    v9 = idTriangles::idTriangles(this: v8);
  else
    v9 = nullptr;
  v10 = v5->__vftable;
  v50 = v9;
  v10->Read(this: v5, a2: v9, a3: 24u);
  v11 = v5->__vftable;
  p_numVerts = &v9->numVerts;
  v11->Read(this: v5, a2: &v9->numVerts, a3: 4u);
  v12 = v5->__vftable;
  p_numVerts = &v9->numIndexes;
  ((void (__fastcall *)(idFile *))v12->Read)(a1: v5);
  v13 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface.cpp(736) : TAG_WATER",
                  size: 32 * v9->numVerts,
                  tag: TAG_WATER,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v14 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface.cpp(737) : TAG_WATER",
          size: 2 * v9->numIndexes,
          tag: TAG_WATER,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v15 = v5->__vftable;
  numVerts = v9->numVerts;
  v17 = v14;
  p_numVerts = v14;
  v15->Read(this: v5, a2: v13, a3: 32 * numVerts);
  v5->Read(this: v5, a2: v17, a3: 2 * v9->numIndexes);
  idIndexBuffer::AllocBufferObject(
    this: &this->indexBuffer,
    data: v17,
    allocSize: 2 * v9->numIndexes,
    allocUsage: BU_DYNAMIC);
  v18 = 3;
  vertexBuffer = this->vertexBuffer;
  do
  {
    idVertexBuffer::AllocBufferObject(
      this: vertexBuffer,
      data: v13,
      allocSize: 32 * v9->numVerts,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    --v18;
    ++vertexBuffer;
  }
  while ( v18 != 0 );
  idVertexBuffer::Reference(this: &v9->vertexBuffer, other: this->vertexBuffer);
  idIndexBuffer::Reference(this: &v9->indexBuffer, other: &this->indexBuffer);
  idRenderModel::AddSurface(
    this: material,
    surf: v49,
    a3: __SPAIR64__((unsigned int)v50, v53),
    a4: __SPAIR64__(v55, v57),
    a5: v59,
    a6: v32,
    a7: v33,
    a8: v34,
    a9: v35,
    a10: v36,
    a11: v37,
    a12: v38,
    a13: v39,
    a14: v40,
    a15: v41);
  idRenderModel::FinishSurfaces(this);
  waterSim = this->waterSim;
  if ( waterSim != nullptr )
  {
    idWaterSurfaceSim::~idWaterSurfaceSim(this: this->waterSim);
    v21 = v42;
    idMem::Free(this: v42, ptr: waterSim, align: ALIGN_16);
  }
  else
  {
    v21 = v42;
  }
  v22 = (idWaterSurfaceSim *)idMem::AllocWithLocation(
                               this: v21,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xB4u,
                               tag: TAG_WATER,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  v44 = v22;
  if ( v22 != nullptr )
    v23 = idWaterSurfaceSim::idWaterSurfaceSim(
            this: v22,
            bounds: &this->waterSimParms.waterBounds,
            s: this->waterSimParms.spacing,
            damping: this->waterSimParms.damping,
            speed: this->waterSimParms.speed,
            timeStep: this->waterSimParms.timeStep);
  else
    v23 = nullptr;
  this->waterSim = v23;
  for ( i = 0; i < this->waterSim->numBlocksY; ++i )
  {
    for ( j = 0; j < this->waterSim->numBlocksX; ++j )
    {
      v26 = 0;
      for ( k = 0; k < 256; k += 16 )
      {
        for ( m = 0; m < 16; ++m )
        {
          BlockToGridPos(blockLocX: j, blockLocY: i, blockX: m, blockY: v26, gridX: (int *)&v45, gridY: (int *)&v42);
          if ( (int)v45 >= 1 )
          {
            v29 = this->waterSim;
            v30 = v29->width - 2;
            v62 = v29;
            if ( v45 <= v30 && (int)v42 >= 1 && (unsigned int)v42 <= v29->height - 2 )
            {
              BlockPosToBlockLoc(blockX: j, blockY: i, numBlocksX: v29->numBlocksX, offset: (int *)&v44);
              v31 = (unsigned __int8 *)&v13[32 * ((_DWORD)v44 + k + m)];
              idColor::UnpackColor(
                color: ((((__ROL4__(v31[31], 8) | v31[30]) << 8) | v31[29]) << 8) | v31[28],
                unpackedColor: &v60);
              if ( v60.z <= 0.5 )
                v60.z = 0.0;
              else
                v60.z = 1.0;
              idWaterSurfaceSim::SetSimulationParms(
                this: this->waterSim,
                gridX: v45,
                gridY: (unsigned int)v42,
                parms: &v60);
            }
          }
        }
        ++v26;
      }
    }
  }
  this->waterGenBlockParms = (deferredWaterBlockGenParms_t *)idMem::AllocWithLocation(
                                                               this: v21,
                                                               location: "w:\\tech5\\engine\\models\\water\\RenderModelWaterSurface"
                                                               ".cpp(813) : TAG_WATER",
                                                               size: 80
                                                             * this->waterSim->numBlocksY
                                                             * this->waterSim->numBlocksX,
                                                               tag: TAG_WATER,
                                                               zeroBuffer: false,
                                                               align: ALIGN_16,
                                                               heap: HEAP_DEFAULTHEAP);
  idMem::Free(this: v21, ptr: v13, align: ALIGN_16);
  idMem::Free(this: v21, ptr: p_numVerts, align: ALIGN_16);
  idRenderModel::SetParm(this, parm: (const idDeclRenderParm *)rpWaterHeight.r, scalar: this->waterSim->origin.z);
  idRenderModel::CommitThisFrame(this);
  ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
  ((void (__fastcall *)(idFileResource *, int))v47->dtr_idResource)(a1: v47, a2: 1);
  idStr::FreeData(this: &v61);
  return 1;
}


// ========================================================================
// __unwind$232065
// EA  : 0x8288FB30
// RVA : 0x0088FB30
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232065()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 208));
}


// ========================================================================
// __unwind$232066
// EA  : 0x8288FB58
// RVA : 0x0088FB58
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232066()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 100), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$232067
// EA  : 0x8288FB84
// RVA : 0x0088FB84
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232067()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 104), tag: TAG_WATER);
}


// ========================================================================
// ?LoadModel@idRenderModelWaterSurface@@AAA_NPBD@Z
// EA  : 0x8288FC10
// RVA : 0x0088FC10
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

BOOL __fastcall idRenderModelWaterSurface::LoadModel(idRenderModelWaterSurface *this, const char *modelName)
{
  char v4[256]; // [sp+50h] [-110h] BYREF

  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "wmodel", a4: modelName, a5: v4, a6: 256);
  return (unsigned __int8)idRenderModelWaterSurface::LoadBinary(this, modelName: v4) != 0;
}


// ========================================================================
// ??0idRenderModelWaterSurface@@QAA@PBD@Z
// EA  : 0x8288FC90
// RVA : 0x0088FC90
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

idRenderModelWaterSurface *__fastcall idRenderModelWaterSurface::idRenderModelWaterSurface(
        idRenderModelWaterSurface *this,
        const char *modelName)
{
  idRenderModel::idRenderModel(this);
  this->waterSim = nullptr;
  this->__vftable = (idRenderModelWaterSurface_vtbl *)&idRenderModelWaterSurface::`vftable';
  `eh vector constructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->indexBuffer);
  this->deferredVerts = nullptr;
  this->currentIndex = 0;
  this->waterGenBlockParms = nullptr;
  this->material = nullptr;
  this->waterSimParms.spacing = 0.0;
  this->waterSimParms.damping = 0.0;
  this->waterSimParms.speed = 0.0;
  this->waterSimParms.timeStep = 0.0;
  this->waterSimParms.waterBounds.b[1].z = 0.0;
  this->waterSimParms.waterBounds.b[1].y = 0.0;
  this->waterSimParms.waterBounds.b[1].x = 0.0;
  this->waterSimParms.waterBounds.b[0].z = 0.0;
  this->waterSimParms.waterBounds.b[0].y = 0.0;
  this->waterSimParms.waterBounds.b[0].x = 0.0;
  *((_BYTE *)&this->g + 105) |= 0xC0u;
  idRenderModel::SetName(this, name_: modelName);
  idRenderModelWaterSurface::LoadModel(this, modelName);
  return this;
}


// ========================================================================
// __unwind$232366
// EA  : 0x8288FD64
// RVA : 0x0088FD64
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232366()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$232367
// EA  : 0x8288FD8C
// RVA : 0x0088FD8C
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232367()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2036),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$232368
// EA  : 0x8288FDC8
// RVA : 0x0088FDC8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _unwind_232368()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 128 + 148) + 2084));
}


// ========================================================================
// `dynamic initializer for 'r_skipWaterSurfaces''
// EA  : 0x83345540
// RVA : 0x01345540
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipWaterSurfaces__()
{
  idCVar::idCVar(
    this: &r_skipWaterSurfaces,
    name: "r_skipWaterSurfaces",
    value: "0",
    flags: 2,
    description: "1 = skip render update of all water surfaces",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY",
    a9: (int)&loc_827B0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,1>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipWaterSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'r_useWaterSimulationJobs''
// EA  : 0x833455A8
// RVA : 0x013455A8
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useWaterSimulationJobs__()
{
  idCVar::idCVar(
    this: &r_useWaterSimulationJobs,
    name: "r_useWaterSimulationJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useWaterSimulationJobs__);
}


// ========================================================================
// `dynamic initializer for 'register_WaterGenJob''
// EA  : 0x83345600
// RVA : 0x01345600
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_WaterGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_WaterGenJob,
           function: (void (__fastcall *)(void *))WaterGenJob,
           name: "WaterGenJob");
}


// ========================================================================
// `dynamic initializer for 'rpWaterHeight''
// EA  : 0x83345620
// RVA : 0x01345620
// PDB : w:\tech5\engine\models\water\rendermodelwatersurface.cpp
// ========================================================================

void _dynamic_initializer_for__rpWaterHeight__()
{
  rpWaterHeight.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpWaterHeight;
}

