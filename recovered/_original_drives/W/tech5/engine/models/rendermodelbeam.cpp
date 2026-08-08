
// ========================================================================
// ?Shutdown@idRenderModelBeam@@SAXXZ
// EA  : 0x827F6AE0
// RVA : 0x007F6AE0
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

static void __fastcall idRenderModelBeam::Shutdown()
{
  idVertexBuffer *v0; // r31

  v0 = idRenderModelBeam::preAllocatedVertexBuffer;
  do
    idVertexBuffer::FreeBufferObject(this: v0++);
  while ( (int)v0 < (int)&idRenderModelBeam::preAllocatedIndexBuffer );
  idIndexBuffer::FreeBufferObject(this: &idRenderModelBeam::preAllocatedIndexBuffer);
  idRenderModelBeam::preAllocatedBufferInUse = false;
}


// ========================================================================
// ?Init@idRenderModelBeam@@SAXXZ
// EA  : 0x827F6B50
// RVA : 0x007F6B50
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

static void __fastcall idRenderModelBeam::Init()
{
  idVertexBuffer *v0; // r30
  char *v1; // r30
  int v2; // r10
  char *v3; // r11
  int i; // ctr

  v0 = idRenderModelBeam::preAllocatedVertexBuffer;
  do
    idVertexBuffer::AllocBufferObject(
      this: v0++,
      data: nullptr,
      allocSize: 1040384,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
  while ( (int)v0 < (int)&idRenderModelBeam::preAllocatedIndexBuffer );
  v1 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0x17D00u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v2 = 3;
  v3 = v1 - 2;
  for ( i = 8128; i != 0; --i )
  {
    *((_WORD *)v3 + 1) = v2 - 3;
    *((_WORD *)v3 + 2) = v2 - 1;
    *((_WORD *)v3 + 3) = v2;
    *((_WORD *)v3 + 4) = v2 - 3;
    *((_WORD *)v3 + 5) = v2;
    v3 += 12;
    *(_WORD *)v3 = v2 - 2;
    v2 += 4;
  }
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelBeam::preAllocatedIndexBuffer,
    data: v1,
    allocSize: 97536,
    allocUsage: BU_DYNAMIC);
  idRenderModelBeam::preAllocatedBufferInUse = false;
  if ( v1 != nullptr )
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$230529
// EA  : 0x827F6C84
// RVA : 0x007F6C84
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_230529()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateInView@idRenderModelBeam@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827F6E30
// RVA : 0x007F6E30
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

int __fastcall idRenderModelBeam::UpdateInView(
        idRenderModelBeam *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools,
        const char *a5)
{
  unsigned __int64 v5; // r26
  unsigned __int64 v7; // r6
  idVertexBuffer *v9; // r23
  char *v10; // r3
  int *p_beamRenderBufferIndex; // r16
  int v13; // r28
  char *v14; // r27
  int v15; // r24
  int v16; // r19
  char *v17; // r9
  int v18; // r10
  int v19; // r15
  int v21; // r11
  int v22; // r7
  const idMaterial *v23; // r18
  int v24; // r8
  int v25; // r29
  idTriangles *v26; // r20
  int v27; // r23
  _DWORD *v28; // r29
  int v29; // r11
  int v30; // r3
  _DWORD *v31; // r28
  int v33; // r11
  double v39; // fp8
  double v40; // fp7
  double v42; // fp10
  double v44; // fp9
  double v46; // fp6
  double v47; // fp11
  double v48; // fp13
  double v49; // fp12
  double v50; // fp5
  double v51; // fp4
  double v52; // fp3
  double v53; // fp10
  double v54; // fp12
  double v55; // fp0
  const idRenderView *v56; // r10
  double v57; // fp13
  double v58; // fp5
  float *v59; // r10
  double v61; // fp1
  double v63; // fp9
  double v64; // fp3
  double v65; // fp1
  double v66; // fp3
  double v67; // fp0
  double v68; // fp13
  float v69; // r5
  float v70; // r6
  float v71; // r7
  double v72; // fp4
  double v73; // fp2
  double v74; // fp0
  double v75; // fp13
  __int16 *v76; // r10
  char v77; // r8
  char v78; // r7
  char v79; // r6
  double v80; // fp11
  char v81; // r5
  char *v82; // r11
  int v83; // ctr
  char v84; // r17
  char v85; // r16
  char v86; // r9
  int i; // ctr
  idPLog *pLog; // r29
  idPLog::logEntry_t *v93; // r30
  int v94; // r3
  __int64 totalTicks; // r11
  __int64 v96; // r9
  int num; // [sp+50h] [-1D0h]
  int v98; // [sp+50h] [-1D0h]
  int v99; // [sp+5Ch] [-1C4h]
  int v100; // [sp+60h] [-1C0h]
  float v101[2]; // [sp+68h] [-1B8h] BYREF
  float v102; // [sp+70h] [-1B0h]
  idPLogScope v103; // [sp+78h] [-1A8h] BYREF
  float v104; // [sp+80h] [-1A0h]
  float v105; // [sp+84h] [-19Ch]
  float v106; // [sp+88h] [-198h]
  int *v107; // [sp+8Ch] [-194h]
  int v108; // [sp+90h] [-190h]
  idVertexBuffer *v109; // [sp+94h] [-18Ch]
  __int16 v110; // [sp+9Ah] [-186h] BYREF
  float v111[3]; // [sp+A0h] [-180h] BYREF
  float v112; // [sp+ACh] [-174h]
  float v113; // [sp+B0h] [-170h] BYREF
  float v114[8]; // [sp+C0h] [-160h] BYREF
  float v115[8]; // [sp+E0h] [-140h] BYREF
  float v116[8]; // [sp+100h] [-120h] BYREF
  float v117[4]; // [sp+120h] [-100h] BYREF
  idRenderModelSurface v118; // [sp+130h] [-F0h] BYREF

  LODWORD(v7) = "idRenderModelBeam::UpdateInView";
  HIDWORD(v7) = 1;
  idPLogScope::idPLogScope(this: &v103, pl: &::pLog, gMask: v7, label: a5);
  if ( this->surfaces.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  LODWORD(v5) = 0;
  this->surfaces.num = __CFADD__(-this->surfaces.size, this->surfaces.size ^ 0x80000000) ? 0 : this->surfaces.size;
  if ( r_skipBeams.valueInteger != 0 )
  {
    idPLogScope::~idPLogScope(this: &v103);
    return 0;
  }
  else
  {
    v9 = (idVertexBuffer *)((char *)this->vertexBuffer + ((16 * renderSystem->FrameNumber(this: renderSystem)) & 0x10));
    v109 = v9;
    v10 = (char *)idVertexBuffer::MapBuffer(this: v9, mapType: BM_WRITE_NOSYNC);
    v100 = 0;
    p_beamRenderBufferIndex = &this->beamRenderBufferIndex;
    v13 = 0;
    v107 = &this->beamRenderBufferIndex;
    v14 = v10;
    v15 = 0;
    v16 = 0;
    v17 = (char *)this + 820752 * this->beamRenderBufferIndex;
    v18 = *((_DWORD *)v17 + 509);
    if ( v18 > 0 )
    {
      v99 = 0;
      v19 = 0;
      _R30 = 16;
      do
      {
        v22 = 0;
        num = this->surfaces.num;
        v21 = num;
        v23 = *(const idMaterial **)(*((_DWORD *)v17 + 508) + v19 + 12816);
        if ( num > 0 )
        {
          v24 = 0;
          do
          {
            if ( this->surfaces.list[v24].material == v23 )
              break;
            ++v22;
            ++v24;
          }
          while ( v22 < num );
        }
        if ( v22 == num )
        {
          v118.skinOffsets.x = 0.0;
          v118.material = v23;
          v118.skinOffsets.y = 0.0;
          v118.materialNum = 0;
          v118.skinOffsets.z = 0.0;
          v118.extraGLState = v5;
          v118.skinOffsets.w = 0.0;
          v118.referenceMask = 0;
          memset(&v118.binaryModelId, 0, 16);
          v98 = v15;
          v25 = v16;
          v108 = v16;
          v118.geometryIsReference = true;
          HIDWORD(v5) = v13;
          v26 = &this->triangles[v21];
          v118.geometry = v26;
          if ( v13 < v18 )
          {
            v27 = v19;
            do
            {
              v28 = (_DWORD *)(*((_DWORD *)v17 + 508) + v27);
              if ( (const idMaterial *)v28[3204] == v23 )
              {
                v29 = v28[1];
                v101[0] = 0.0;
                v101[1] = 0.0;
                v102 = 0.0;
                v30 = 0;
                if ( v29 > 0 )
                {
                  __asm { vspltisw128 v63, 0 }
                  v31 = v28 + 3205;
                  _R4 = (char *)&v113 - v14;
                  __asm
                  {
                    vcmpequw128 v62, v95, v63
                    vsldoi128 v62, v95, v62, 4
                  }
                  do
                  {
                    __asm { vcmpequw128 v61, v95, v63 }
                    __asm
                    {
                      vcmpequw128 v60, v95, v63
                      vcmpequw128 v59, v95, v63
                      vsldoi128 v58, v95, v61, 4
                      vsldoi128 v57, v95, v60, 4
                      vsldoi128 v56, v95, v59, 4
                    }
                    v33 = 100 * v30 + *v28;
                    _R10 = v111;
                    _R7 = v111;
                    _R6 = v114;
                    _R5 = v114;
                    _R17 = v115;
                    v39 = *(float *)(v33 + 20);
                    v40 = *(float *)(v33 + 16);
                    _R16 = v115;
                    v42 = *(float *)(v33 + 8);
                    _R15 = v116;
                    v44 = *(float *)(v33 + 4);
                    _R14 = v116;
                    v46 = *(float *)(v33 + 12);
                    v47 = *(float *)v33;
                    __asm { stvx128   v63, r0, r10 }
                    __asm { stvx128   v58, r7, r30 }
                    __asm { stvx128   v63, r0, r6 }
                    __asm
                    {
                      stvx128   v57, r5, r30
                      stvx128   v63, r0, r17
                      stvx128   v56, r16, r30
                      stvx128   v63, r0, r15
                      stvx128   v62, r14, r30
                    }
                    if ( *v31 == 2 )
                    {
                      v48 = *(float *)(v33 + 28);
                      v49 = *(float *)(v33 + 32);
                      v50 = *(float *)(v33 + 36);
                      v51 = *(float *)(v33 + 40);
                      v52 = *(float *)(v33 + 44);
                      v114[0] = *(float *)(v33 + 24);
                      v114[1] = v48;
                      v111[0] = v47;
                      v114[2] = v49;
                      v111[1] = v44;
                      v116[0] = v50;
                      v111[2] = v42;
                      v116[1] = v51;
                      v116[2] = v52;
                      v115[0] = v46;
                      v115[1] = v40;
                      v115[2] = v39;
                    }
                    else
                    {
                      if ( *v31 == 1 )
                      {
                        v53 = (float)((float)((float)(*(float *)(v33 + 20) - *(float *)(v33 + 8)) * *(float *)(v33 + 48))
                                    - (float)((float)(*(float *)(v33 + 12) - *(float *)v33) * *(float *)(v33 + 56)));
                        v54 = (float)((float)((float)(*(float *)(v33 + 12) - *(float *)v33) * *(float *)(v33 + 52))
                                    - (float)((float)(*(float *)(v33 + 16) - *(float *)(v33 + 4)) * *(float *)(v33 + 48)));
                        v55 = (float)((float)((float)(*(float *)(v33 + 16) - *(float *)(v33 + 4)) * *(float *)(v33 + 56))
                                    - (float)((float)(*(float *)(v33 + 20) - *(float *)(v33 + 8)) * *(float *)(v33 + 52)));
                      }
                      else
                      {
                        v56 = currentView;
                        v53 = (float)((float)((float)(v56->r.vieworg.x - *(float *)v33)
                                            * (float)(*(float *)(v33 + 20) - *(float *)(v33 + 8)))
                                    - (float)((float)(v56->r.vieworg.z - *(float *)(v33 + 8))
                                            * (float)(*(float *)(v33 + 12) - *(float *)v33)));
                        v54 = (float)((float)((float)(v56->r.vieworg.y - *(float *)(v33 + 4))
                                            * (float)(*(float *)(v33 + 12) - *(float *)v33))
                                    - (float)((float)(v56->r.vieworg.x - *(float *)v33)
                                            * (float)(*(float *)(v33 + 16) - *(float *)(v33 + 4))));
                        v55 = (float)((float)((float)(currentView->r.vieworg.z - *(float *)(v33 + 8))
                                            * (float)(*(float *)(v33 + 16) - *(float *)(v33 + 4)))
                                    - (float)((float)(currentView->r.vieworg.y - *(float *)(v33 + 4))
                                            * (float)(*(float *)(v33 + 20) - *(float *)(v33 + 8))));
                      }
                      v57 = v53;
                      v58 = *(float *)(v33 + 76);
                      v59 = v117;
                      _FP2 = (float)((float)((float)((float)v55 * (float)v55)
                                           + (float)((float)((float)v54 * (float)v54) + (float)((float)v53 * (float)v53)))
                                   - idMath::FLT_SMALLEST_NON_DENORMAL);
                      v61 = (float)((float)((float)((float)v55 * (float)v55)
                                          + (float)((float)((float)v54 * (float)v54) + (float)((float)v53 * (float)v53)))
                                  * (float)0.5);
                      __asm { fsel      f10, f2, f3, f10 }
                      v63 = __frsqrte(_FP10);
                      v64 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v63 * (float)v61)
                                                                                                  * (float)v63)
                                                                                          - (float)1.5)
                                                                          * (float)v63)
                                                                  * (float)v61)
                                                          * (float)((float)-(float)((float)((float)((float)v63
                                                                                                  * (float)v61)
                                                                                          * (float)v63)
                                                                                  - (float)1.5)
                                                                  * (float)v63))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63)
                                                          - (float)1.5)
                                          * (float)v63));
                      v65 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63) - (float)1.5) * (float)v63)
                                                                                                  * (float)v61)
                                                                                          * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63) - (float)1.5)
                                                                                                  * (float)v63))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v63 * (float)v61)
                                                                                                  * (float)v63)
                                                                                          - (float)1.5)
                                                                          * (float)v63))
                                                          * (float)v61)
                                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63) - (float)1.5)
                                                                                                  * (float)v63)
                                                                                          * (float)v61)
                                                                                  * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63) - (float)1.5)
                                                                                          * (float)v63))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v63
                                                                                                  * (float)v61)
                                                                                          * (float)v63)
                                                                                  - (float)1.5)
                                                                  * (float)v63)))
                                          - (float)1.5);
                      v67 = (float)(*(float *)(v33 + 76) * (float)((float)((float)v65 * (float)v64) * (float)v55));
                      v68 = (float)((float)((float)v57 * (float)((float)v65 * (float)v64)) * *(float *)(v33 + 76));
                      v117[0] = v67;
                      v66 = (float)((float)v54 * (float)((float)v65 * (float)v64));
                      v117[1] = v68;
                      v117[2] = (float)v66 * (float)v58;
                      if ( v30 != 0 )
                        v59 = v101;
                      v69 = v59[1];
                      v70 = *v59;
                      v71 = v59[2];
                      v101[0] = v67;
                      v102 = (float)v66 * (float)v58;
                      v105 = v69;
                      v104 = v70;
                      v72 = *(float *)(v33 + 8);
                      v101[1] = v68;
                      v106 = v71;
                      v73 = *(float *)(v33 + 4);
                      v115[0] = (float)v46 - (float)v67;
                      v116[0] = (float)v46 + (float)v67;
                      v115[2] = (float)v39 - v102;
                      v115[1] = (float)v40 - (float)v68;
                      v116[2] = (float)v39 + v102;
                      v116[1] = (float)v40 + (float)v68;
                      v111[1] = (float)v73 - v69;
                      v111[2] = (float)v72 - v71;
                      v114[2] = v71 + (float)v72;
                      v114[1] = v69 + (float)v73;
                      v111[0] = (float)v47 - v70;
                      v114[0] = v70 + (float)v47;
                    }
                    v74 = *(float *)(v33 + 68);
                    v75 = *(float *)(v33 + 72);
                    v76 = &v110;
                    v77 = *(_BYTE *)(v33 + 80);
                    v78 = *(_BYTE *)(v33 + 81);
                    v79 = *(_BYTE *)(v33 + 82);
                    v80 = *(float *)(v33 + 64);
                    v81 = *(_BYTE *)(v33 + 83);
                    v112 = *(float *)(v33 + 60);
                    v82 = (char *)(v33 + 82);
                    v113 = v74;
                    v83 = 4;
                    v114[3] = v112;
                    v114[4] = v75;
                    v115[3] = v80;
                    v115[4] = v74;
                    v116[3] = v80;
                    v116[4] = v75;
                    do
                    {
                      v84 = v82[2];
                      v85 = v82[3];
                      v82 += 4;
                      v86 = *v82;
                      *((_BYTE *)v76 + 34) = v77;
                      *((_BYTE *)v76 + 35) = v78;
                      *((_BYTE *)v76 + 36) = v79;
                      *((_BYTE *)v76 + 37) = v81;
                      *((_BYTE *)v76 + 30) = v84;
                      *((_BYTE *)v76 + 31) = v85;
                      v76 += 16;
                      *(_BYTE *)v76 = v86;
                      --v83;
                    }
                    while ( v83 != 0 );
                    _R11 = v14;
                    _R9 = -16;
                    _R8 = 16;
                    for ( i = 4; i != 0; --i )
                    {
                      _R10 = &_R11[_R4];
                      __asm
                      {
                        lvx128    v55, r4, r11
                        lvx128    v54, r10, r9
                        stvx128   v54, r0, r11
                        stvx128   v55, r11, r8
                      }
                      _R11 += 32;
                    }
                    v15 += 4;
                    v14 = _R11;
                    _R4 -= 128;
                    v16 += 6;
                    if ( v15 > 32508 )
                      break;
                    ++v30;
                  }
                  while ( v30 < v28[1] );
                  v19 = v99;
                  p_beamRenderBufferIndex = v107;
                  v13 = v100;
                }
              }
              ++HIDWORD(v5);
              v27 += 12824;
              v17 = (char *)this + 820752 * *p_beamRenderBufferIndex;
            }
            while ( SHIDWORD(v5) < *((_DWORD *)v17 + 509) );
            v25 = v108;
            v9 = v109;
          }
          if ( this->surfaces.num < 31 )
          {
            HIDWORD(v5) = v16 - v25;
            v26->numVerts = v15 - v98;
            v26->numIndexes = v16 - v25;
            idVertexBuffer::Reference(this: &v26->vertexBuffer, other: v9);
            idIndexBuffer::Reference(
              this: &v26->indexBuffer,
              other: &this->indexBuffer,
              refOffset: 2 * v25,
              refSize: 2 * (v16 - v25));
            idList<idRenderModelSurface,62>::Append(this: &this->surfaces, obj: &v118);
          }
        }
        ++v13;
        v19 += 12824;
        v100 = v13;
        v99 = v19;
        v17 = (char *)this + 820752 * *p_beamRenderBufferIndex;
        v18 = *((_DWORD *)v17 + 509);
      }
      while ( v13 < v18 );
    }
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v9);
    idRenderModel::CommitSurfaces(this);
    if ( v103.logIndex >= 0 )
    {
      pLog = v103.pLog;
      v93 = &v103.pLog->logEntries.list[v103.logIndex];
      v94 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v93->totalTicks;
      HIDWORD(totalTicks) = v93->parent;
      LODWORD(v96) = v94 - totalTicks;
      v93->totalTicks = v96;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    return 1;
  }
}


// ========================================================================
// __unwind$231117
// EA  : 0x827F7518
// RVA : 0x007F7518
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_231117()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 544 + 120));
}


// ========================================================================
// ??1idRenderModelBeam@@UAA@XZ
// EA  : 0x827F7800
// RVA : 0x007F7800
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __fastcall idRenderModelBeam::~idRenderModelBeam(idRenderModelBeam *this)
{
  int v2; // r30
  idVertexBuffer *vertexBuffer; // r29
  idTriangles *triangles; // r3
  bufferUsageType_t *p_usage; // r29

  this->__vftable = (idRenderModelBeam_vtbl *)&idRenderModelBeam::`vftable';
  if ( this->usesPreAllocatedBuffer )
    idRenderModelBeam::preAllocatedBufferInUse = false;
  v2 = 2;
  vertexBuffer = this->vertexBuffer;
  do
  {
    idVertexBuffer::FreeBufferObject(this: vertexBuffer);
    --v2;
    ++vertexBuffer;
  }
  while ( v2 != 0 );
  idIndexBuffer::FreeBufferObject(this: &this->indexBuffer);
  triangles = this->triangles;
  if ( triangles != nullptr )
  {
    p_usage = &triangles[-1].indexBuffer.usage;
    `eh vector destructor iterator'(
      ptr: triangles,
      size: 0x84u,
      count: triangles[-1].indexBuffer.usage,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
    idMem::Free(this: &mem, ptr: p_usage, align: ALIGN_16);
  }
  idIndexBuffer::~idIndexBuffer(this: &this->indexBuffer);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  `eh vector destructor iterator'(
    ptr: this->beamBuffer,
    size: 0xC8610u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStaticList<beam_t,64>::~idStaticList<beam_t,64>);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231774
// EA  : 0x827F7904
// RVA : 0x007F7904
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_231774()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$231775
// EA  : 0x827F792C
// RVA : 0x007F792C
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_231775()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2032),
    size: 0xC8610u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStaticList<beam_t,64>::~idStaticList<beam_t,64>);
}


// ========================================================================
// __unwind$231776
// EA  : 0x827F796C
// RVA : 0x007F796C
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_231776()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 1643544),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$231777
// EA  : 0x827F79B0
// RVA : 0x007F79B0
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_231777()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 128 + 148) + 1643576));
}


// ========================================================================
// ?Update@idRenderModelBeam@@QAAXH@Z
// EA  : 0x827F79E8
// RVA : 0x007F79E8
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __fastcall idRenderModelBeam::Update(idRenderModelBeam *this, const int currTime)
{
  idList<beam_t,5> *v3; // r11
  idList<beam_t,5> *v4; // r30

  v3 = (idList<beam_t,5> *)((char *)this + 820752 * (this->beamRenderBufferIndex ^ 1));
  v4 = v3 + 127;
  if ( v3[127].size < 0 )
    idList<beam_t,5>::Clear(this: v3 + 127);
  v4->num = __CFADD__(-v4->size, v4->size ^ 0x80000000) ? 0 : v4->size;
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// ?CommitSubclass@idRenderModelBeam@@EAA_NXZ
// EA  : 0x827F7A78
// RVA : 0x007F7A78
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

int __fastcall idRenderModelBeam::CommitSubclass(idRenderModelBeam *this)
{
  int *p_beamRenderBufferIndex; // r30
  idList<beam_t,5> *v2; // r11
  idList<beam_t,5> *v3; // r31

  p_beamRenderBufferIndex = &this->beamRenderBufferIndex;
  v2 = (idList<beam_t,5> *)((char *)this + 820752 * this->beamRenderBufferIndex);
  v3 = v2 + 127;
  if ( v2[127].size < 0 )
    idList<beam_t,5>::Clear(this: v2 + 127);
  v3->num = __CFADD__(-v3->size, v3->size ^ 0x80000000) ? 0 : v3->size;
  *p_beamRenderBufferIndex ^= 1u;
  return 0;
}


// ========================================================================
// ??0idRenderModelBeam@@QAA@XZ
// EA  : 0x827F7C40
// RVA : 0x007F7C40
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

idRenderModelBeam *__fastcall idRenderModelBeam::idRenderModelBeam(idRenderModelBeam *this)
{
  idVertexBuffer *vertexBuffer; // r29
  const idVertexBuffer *v3; // r30
  int i; // r30
  char *v5; // r30
  int v6; // r10
  char *v7; // r11
  int j; // ctr
  _DWORD *v9; // r3
  idTriangles *v10; // r30
  idTriangles *v11; // r8
  idTriangles **p_triangles; // r10
  int v13; // r11
  int v14; // ctr
  float *v15; // r9
  float *v16; // r9
  idTriangles *v17; // r9
  float *v18; // r9
  float *v19; // r9
  float *v20; // r9
  float *v21; // r9
  float *v22; // r9
  int v23; // r29
  char *v24; // r30
  char *v25; // r3

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelBeam_vtbl *)&idRenderModelBeam::`vftable';
  `eh vector constructor iterator'(
    ptr: this->beamBuffer,
    size: 0xC8610u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idStaticList<beam_t,64>::idStaticList<beam_t,64>,
    pDtor: (void (__fastcall *)(void *))idStaticList<beam_t,64>::~idStaticList<beam_t,64>);
  vertexBuffer = this->vertexBuffer;
  `eh vector constructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->indexBuffer);
  idRenderModel::SetAxis(this, a: &mat3_identity);
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
    this->g.origin = vec3_origin;
  this->deferredOrigin = vec3_origin;
  idRenderModel::FreeSurfaces(this);
  *((_BYTE *)&this->g + 105) |= 0x84u;
  if ( idRenderModelBeam::preAllocatedBufferInUse )
  {
    for ( i = 2; i != 0; --i )
      idVertexBuffer::AllocBufferObject(
        this: vertexBuffer++,
        data: nullptr,
        allocSize: 1040384,
        vertexMask: 31,
        allocUsage: BU_DYNAMIC);
    v5 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                   size: 0x17D00u,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v6 = 3;
    v7 = v5 - 2;
    for ( j = 8128; j != 0; --j )
    {
      *((_WORD *)v7 + 1) = v6 - 3;
      *((_WORD *)v7 + 2) = v6 - 1;
      *((_WORD *)v7 + 3) = v6;
      *((_WORD *)v7 + 4) = v6 - 3;
      *((_WORD *)v7 + 5) = v6;
      v7 += 12;
      *(_WORD *)v7 = v6 - 2;
      v6 += 4;
    }
    idIndexBuffer::AllocBufferObject(this: &this->indexBuffer, data: v5, allocSize: 97536, allocUsage: BU_DYNAMIC);
    this->usesPreAllocatedBuffer = false;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  }
  else
  {
    v3 = idRenderModelBeam::preAllocatedVertexBuffer;
    do
      idVertexBuffer::Reference(this: vertexBuffer++, other: v3++);
    while ( (int)v3 < (int)&idRenderModelBeam::preAllocatedIndexBuffer );
    idIndexBuffer::Reference(this: &this->indexBuffer, other: &idRenderModelBeam::preAllocatedIndexBuffer);
    idRenderModelBeam::preAllocatedBufferInUse = true;
    this->usesPreAllocatedBuffer = true;
  }
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
         size: 0x1084u,
         tag: TAG_EFFECT_PARTICLE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
  {
    v10 = (idTriangles *)(v9 + 1);
    *v9 = 32;
    `eh vector constructor iterator'(
      ptr: v9 + 1,
      size: 0x84u,
      count: 32,
      pCtor: (void (__fastcall *)(void *))idTriangles::idTriangles,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  p_triangles = &this->triangles;
  v13 = 3;
  v14 = 4;
  this->triangles = v11;
  do
  {
    v15 = (float *)&(*p_triangles)[v13 - 3];
    v15[1] = -99999.0;
    v15[4] = 99999.0;
    *v15 = -99999.0;
    v15[2] = -99999.0;
    v15[5] = 99999.0;
    v15[3] = 99999.0;
    v16 = (float *)&(*p_triangles)[v13 - 3];
    v16[35] = -99999.0;
    v16[34] = -99999.0;
    v16[33] = -99999.0;
    v16[38] = 99999.0;
    v16[37] = 99999.0;
    v16[36] = 99999.0;
    v17 = &(*p_triangles)[v13];
    v17[-1].bounds.b[0].z = -99999.0;
    v17[-1].bounds.b[0].y = -99999.0;
    v17[-1].bounds.b[0].x = -99999.0;
    v17[-1].bounds.b[1].z = 99999.0;
    v17[-1].bounds.b[1].y = 99999.0;
    v17[-1].bounds.b[1].x = 99999.0;
    v18 = (float *)&(*p_triangles)[v13];
    v18[2] = -99999.0;
    v18[1] = -99999.0;
    *v18 = -99999.0;
    v18[5] = 99999.0;
    v18[4] = 99999.0;
    v18[3] = 99999.0;
    v19 = (float *)&(*p_triangles)[v13];
    v19[35] = -99999.0;
    v19[34] = -99999.0;
    v19[33] = -99999.0;
    v19[38] = 99999.0;
    v19[37] = 99999.0;
    v19[36] = 99999.0;
    v20 = (float *)&(*p_triangles)[v13];
    v20[68] = -99999.0;
    v20[67] = -99999.0;
    v20[66] = -99999.0;
    v20[71] = 99999.0;
    v20[70] = 99999.0;
    v20[69] = 99999.0;
    v21 = (float *)&(*p_triangles)[v13];
    v21[101] = -99999.0;
    v21[100] = -99999.0;
    v21[99] = -99999.0;
    v21[104] = 99999.0;
    v21[103] = 99999.0;
    v21[102] = 99999.0;
    v22 = (float *)&(*p_triangles)[v13];
    v22[134] = -99999.0;
    v13 += 8;
    v22[133] = -99999.0;
    v22[132] = -99999.0;
    v22[137] = 99999.0;
    v22[136] = 99999.0;
    v22[135] = 99999.0;
    --v14;
  }
  while ( v14 != 0 );
  v23 = 2;
  v24 = (char *)this - 818716;
  do
  {
    if ( v24[820763] == 0 || v24[820763] == 2 )
    {
      v25 = *((char **)v24 + 205187);
      if ( v25 != nullptr )
        idListArrayDelete<beam_t>(ptr: v25, num: *((_DWORD *)v24 + 205189));
      *((_DWORD *)v24 + 205187) = 0;
      *((_DWORD *)v24 + 205189) = 0;
    }
    --v23;
    v24 += 820752;
    *(_DWORD *)v24 = 0;
  }
  while ( v23 != 0 );
  this->beamRenderBufferIndex = 0;
  return this;
}


// ========================================================================
// __unwind$232211
// EA  : 0x827F80D8
// RVA : 0x007F80D8
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232211()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$232212
// EA  : 0x827F8100
// RVA : 0x007F8100
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232212()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 176 + 196) + 2032),
    size: 0xC8610u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStaticList<beam_t,64>::~idStaticList<beam_t,64>);
}


// ========================================================================
// __unwind$232213
// EA  : 0x827F8140
// RVA : 0x007F8140
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232213()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 176 + 196) + 1643544),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$232214
// EA  : 0x827F8184
// RVA : 0x007F8184
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232214()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 176 + 196) + 1643576));
}


// ========================================================================
// __unwind$232215
// EA  : 0x827F81B8
// RVA : 0x007F81B8
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232215()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$232216
// EA  : 0x827F81E0
// RVA : 0x007F81E0
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void _unwind_232216()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_EFFECT_PARTICLE);
}


// ========================================================================
// ?DrawBeamAlloc@idRenderModelBeam@@QAAPAUbeam_t@@XZ
// EA  : 0x827F8270
// RVA : 0x007F8270
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

idList<idVehicleState *,5> *__fastcall idRenderModelBeam::DrawBeamAlloc(idRenderModelBeam *this)
{
  char *v2; // r9
  idList<idVehicleState *,5> *v3; // r31

  if ( r_skipBeams.valueInteger != 0 )
    return nullptr;
  v2 = (char *)this + 820752 * (this->beamRenderBufferIndex ^ 1);
  if ( *((_DWORD *)v2 + 509) >= *((_DWORD *)v2 + 510) )
    return nullptr;
  v3 = (idList<idVehicleState *,5> *)idList<beam_t,5>::Alloc(this: &this->beamBuffer[this->beamRenderBufferIndex ^ 1]);
  idList<idThread *,58>::Clear(this: v3);
  return v3;
}


// ========================================================================
// ?DrawBeam@idRenderModelBeam@@QAAXAAUbeamNodeParms_t@@PBVidMaterial@@W4beamOrientType_t@@@Z
// EA  : 0x827F8318
// RVA : 0x007F8318
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __fastcall idRenderModelBeam::DrawBeam(
        idRenderModelBeam *this,
        beamNodeParms_t *node,
        beamNodeParms_t *mtr,
        int type)
{
  idList<beamNodeParms_t,5> *v7; // r3

  if ( mtr != nullptr )
  {
    v7 = (idList<beamNodeParms_t,5> *)idRenderModelBeam::DrawBeamAlloc(this);
    if ( v7 != nullptr )
    {
      v7[801].list = mtr;
      v7[801].num = type;
      idList<beamNodeParms_t,5>::Append(this: v7, obj: node);
    }
  }
}


// ========================================================================
// ?DrawBeam@idRenderModelBeam@@QAAXPAUbeamNodeParms_t@@HPBVidMaterial@@W4beamOrientType_t@@@Z
// EA  : 0x827F8360
// RVA : 0x007F8360
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __fastcall idRenderModelBeam::DrawBeam(
        idRenderModelBeam *this,
        beamNodeParms_t *nodes,
        int numNodes,
        idVehicleState **mtr,
        int type)
{
  const beamNodeParms_t *v5; // r30
  int v6; // r31
  idList<idVehicleState *,5> *v9; // r3
  idList<beamNodeParms_t,5> *v10; // r29

  v5 = nodes;
  v6 = numNodes;
  if ( nodes != nullptr && numNodes != 0 && mtr != nullptr )
  {
    v9 = idRenderModelBeam::DrawBeamAlloc(this);
    v10 = (idList<beamNodeParms_t,5> *)v9;
    if ( v9 != nullptr )
    {
      v9[801].list = mtr;
      v9[801].num = type;
      idList<idThread *,58>::Clear(this: v9);
      if ( v6 > 0 )
      {
        do
        {
          idList<beamNodeParms_t,5>::Append(this: v10, obj: v5);
          --v6;
          ++v5;
        }
        while ( v6 != 0 );
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'r_skipBeams''
// EA  : 0x833437D8
// RVA : 0x013437D8
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipBeams__()
{
  idCVar::idCVar(
    this: &r_skipBeams,
    name: "r_skipBeams",
    value: "0",
    flags: 1,
    description: "skip render model beam system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipBeams__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelBeam::preAllocatedVertexBuffer''
// EA  : 0x83343830
// RVA : 0x01343830
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelBeam::preAllocatedVertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelBeam::preAllocatedVertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelBeam::preAllocatedVertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelBeam::preAllocatedIndexBuffer''
// EA  : 0x83343880
// RVA : 0x01343880
// PDB : w:\tech5\engine\models\rendermodelbeam.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelBeam::preAllocatedIndexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelBeam::preAllocatedIndexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelBeam::preAllocatedIndexBuffer__);
}

