
// ========================================================================
// ?CreateDrawVertNormal@@YAXAAY03EABVidVec3@@@Z
// EA  : 0x827D1BF0
// RVA : 0x007D1BF0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void __fastcall CreateDrawVertNormal(unsigned __int8 (*drawVertNormal)[4], const idVec3 *normal)
{
  int v2; // r11
  int v3; // r11
  int v4; // r11

  v2 = (int)(float)((float)((float)(normal->x + (float)1.0) * (float)127.5) + (float)0.5);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      LOBYTE(v2) = -1;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  (*drawVertNormal)[0] = v2;
  v3 = (int)(float)((float)((float)(normal->y + (float)1.0) * (float)127.5) + (float)0.5);
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  (*drawVertNormal)[1] = v3;
  v4 = (int)(float)((float)((float)(normal->z + (float)1.0) * (float)127.5) + (float)0.5);
  if ( v4 >= 0 )
  {
    if ( v4 <= 255 )
      (*drawVertNormal)[2] = v4;
    else
      (*drawVertNormal)[2] = -1;
    (*drawVertNormal)[3] = 0;
  }
  else
  {
    (*drawVertNormal)[2] = 0;
    (*drawVertNormal)[3] = 0;
  }
}


// ========================================================================
// ??0idRenderModelManyBoxes@@QAA@XZ
// EA  : 0x827D1CF8
// RVA : 0x007D1CF8
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

idRenderModelManyBoxes *__fastcall idRenderModelManyBoxes::idRenderModelManyBoxes(
        idRenderModelManyBoxes *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idRenderModelManyBoxes *a12)
{
  idVertexBuffer *vertexBuffers; // r28
  char *v16; // r25
  int v17; // r11
  char *v18; // r10
  int v19; // r26
  char *v21; // r3
  int i; // ctr

  _R12 = -128;
  __asm { stvx128   v126, r1, r12 }
  _R12 = -112;
  __asm { stvx128   v127, r1, r12 }
  a12 = this;
  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelManyBoxes_vtbl *)&idRenderModelManyBoxes::`vftable';
  this->boxes.list = nullptr;
  this->boxes.granularity = 0;
  this->boxes.memTag = 5;
  this->boxes.listStatic = 0;
  this->boxes.size = 0;
  this->boxes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->boxes);
  vertexBuffers = this->vertexBuffers;
  `eh vector constructor iterator'(
    ptr: this->vertexBuffers,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idTriangles::idTriangles(this: &this->triangles);
  idIndexBuffer::idIndexBuffer(this: &this->indexBuffer);
  this->gameTime = 0;
  this->material = nullptr;
  v16 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                  size: 0x12000u,
                  tag: TAG_TEMP,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v17 = 2;
  v18 = v16 - 2;
  do
  {
    *((_WORD *)v18 + 1) = v17 - 2;
    *((_WORD *)v18 + 2) = v17 - 1;
    *((_WORD *)v18 + 3) = v17;
    *((_WORD *)v18 + 4) = v17 - 2;
    *((_WORD *)v18 + 5) = v17;
    v18 += 12;
    *(_WORD *)v18 = v17 + 1;
    v17 += 4;
  }
  while ( v17 - 2 < 24576 );
  idIndexBuffer::AllocBufferObject(this: &this->indexBuffer, data: v16, allocSize: 73728, allocUsage: BU_DYNAMIC);
  __asm { vspltisw128 v127, 0 }
  v19 = 2;
  __asm { vcmpequw128 v63, v127, v127 }
  _R29 = 16;
  __asm { vsldoi128 v126, v127, v63, 4 }
  do
  {
    idVertexBuffer::AllocBufferObject(
      this: vertexBuffers,
      data: nullptr,
      allocSize: 786432,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    v21 = (char *)idVertexBuffer::MapBuffer(this: vertexBuffers, mapType: BM_WRITE);
    _R7 = 16;
    _R11 = (float *)(v21 + 32);
    for ( i = 6144; i != 0; --i )
    {
      __asm { vcmpequw128 v62, v127, v127 }
      _R10 = _R11 - 8;
      __asm { vcmpequw128 v61, v127, v127 }
      _R9 = _R11 + 8;
      __asm { vcmpequw128 v60, v127, v127 }
      _R8 = _R11 + 16;
      __asm
      {
        vsldoi128 v59, v127, v62, 4
        vsldoi128 v58, v127, v61, 4
        stvx128   v127, r0, r10
        vsldoi128 v57, v127, v60, 4
        stvx128   v59, r10, r7
      }
      *(_R11 - 5) = 0.0;
      *(_R11 - 4) = 0.0;
      __asm
      {
        stvx128   v127, r0, r11
        stvx128   v58, r11, r29
      }
      _R11[3] = 1.0;
      _R11[4] = 0.0;
      __asm
      {
        stvx128   v127, r0, r9
        stvx128   v57, r9, r29
      }
      _R11[11] = 1.0;
      _R11[12] = 1.0;
      __asm
      {
        stvx128   v127, r0, r8
        stvx128   v126, r8, r29
      }
      _R11[19] = 0.0;
      _R11[20] = 1.0;
      _R11 += 32;
    }
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)vertexBuffers);
    --v19;
    ++vertexBuffers;
  }
  while ( v19 != 0 );
  idIndexBuffer::Reference(this: &this->triangles.indexBuffer, other: &this->indexBuffer);
  this->triangles.bounds.b[0].z = -99999.0;
  this->triangles.bounds.b[0].y = -99999.0;
  this->triangles.bounds.b[0].x = -99999.0;
  this->triangles.bounds.b[1].z = 99999.0;
  this->triangles.bounds.b[1].y = 99999.0;
  this->triangles.bounds.b[1].x = 99999.0;
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
    this->g.origin = vec3_origin;
  this->deferredOrigin = vec3_origin;
  idRenderModel::SetAxis(this, a: &mat3_identity);
  idRenderModel::FreeSurfaces(this);
  *((_BYTE *)&this->g + 105) |= 0x84u;
  if ( v16 != nullptr )
    idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
  _R0 = -128;
  __asm { lvx128    v126, r1, r0 }
  _R0 = -112;
  __asm { lvx128    v127, r1, r0 }
  return this;
}


// ========================================================================
// __unwind$220137
// EA  : 0x827D2028
// RVA : 0x007D2028
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220137()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$220138
// EA  : 0x827D2050
// RVA : 0x007D2050
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220138()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 2040));
}


// ========================================================================
// __unwind$220139
// EA  : 0x827D207C
// RVA : 0x007D207C
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220139()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 224 + 244) + 2056),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$220140
// EA  : 0x827D20B8
// RVA : 0x007D20B8
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220140()
{
  int v0; // r12

  idTriangles::~idTriangles(this: (idTriangles *)(*(_DWORD *)(v0 - 224 + 244) + 2088));
}


// ========================================================================
// __unwind$220141
// EA  : 0x827D20E4
// RVA : 0x007D20E4
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220141()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 224 + 244) + 2220));
}


// ========================================================================
// __unwind$220142
// EA  : 0x827D2110
// RVA : 0x007D2110
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220142()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 88));
}


// ========================================================================
// ??1idRenderModelManyBoxes@@MAA@XZ
// EA  : 0x827D2140
// RVA : 0x007D2140
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void __fastcall idRenderModelManyBoxes::~idRenderModelManyBoxes(idRenderModelManyBoxes *this)
{
  this->__vftable = (idRenderModelManyBoxes_vtbl *)&idRenderModelManyBoxes::`vftable';
  idIndexBuffer::~idIndexBuffer(this: &this->indexBuffer);
  idTriangles::~idTriangles(this: &this->triangles);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffers,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->boxes);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$220581
// EA  : 0x827D21BC
// RVA : 0x007D21BC
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220581()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$220582
// EA  : 0x827D21E4
// RVA : 0x007D21E4
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220582()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2040));
}


// ========================================================================
// __unwind$220583
// EA  : 0x827D2210
// RVA : 0x007D2210
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220583()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 2056),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$220584
// EA  : 0x827D224C
// RVA : 0x007D224C
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

void _unwind_220584()
{
  int v0; // r12

  idTriangles::~idTriangles(this: (idTriangles *)(*(_DWORD *)(v0 - 112 + 132) + 2088));
}


// ========================================================================
// ?CommitSubclass@idRenderModelManyBoxes@@EAA_NXZ
// EA  : 0x827D24B8
// RVA : 0x007D24B8
// PDB : w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.cpp
// ========================================================================

int __fastcall idRenderModelManyBoxes::CommitSubclass(idRenderModelManyBoxes *this, int a2, int a3, int a4)
{
  unsigned __int64 v5; // r23
  int v6; // r25
  int v7; // r24
  int v8; // r11
  int v9; // r5
  idVertexBuffer *v10; // r21
  char *v11; // r3
  int v12; // r26
  int v13; // r28
  char *v14; // r31
  idRenderModelManyBoxes::box_t *v15; // r30
  int v16; // r11
  char v17; // r5
  int v18; // r10
  int v19; // r9
  int v20; // r11
  int v21; // r11
  char v22; // r9
  int v23; // r8
  int v24; // r6
  int v25; // r11
  int v26; // r11
  char v27; // r10
  char v28; // r9
  int v29; // r11
  float *p_x; // r11
  double v31; // fp1
  double v32; // fp13
  double v33; // fp12
  double v34; // fp8
  double v35; // fp7
  double v36; // fp9
  double v37; // fp6
  double v38; // fp11
  double v39; // fp5
  double v40; // fp0
  double v41; // fp10
  double v42; // fp2
  double v43; // fp31
  double v44; // fp3
  double v45; // fp4
  double v46; // fp4
  double v47; // fp3
  double v48; // fp0
  double v49; // fp10
  double v50; // fp2
  double v51; // fp31
  double v52; // fp3
  double v53; // fp4
  double v54; // fp2
  double v55; // fp0
  double v56; // fp10
  double v57; // fp31
  double v58; // fp4
  double v59; // fp3
  double v60; // fp10
  double v61; // fp3
  double v62; // fp31
  double v63; // fp2
  double v64; // fp4
  double v65; // fp0
  double v66; // fp10
  double v67; // fp3
  double v68; // fp0
  double v69; // fp31
  double v70; // fp10
  double v71; // fp4
  double v72; // fp2
  double v73; // fp0
  double v74; // fp4
  double v75; // fp2
  double v76; // fp13
  double v77; // fp6
  double v78; // fp5
  const idMaterial *material; // r10
  _DWORD v81[4]; // [sp+50h] [-C0h] BYREF
  idRenderModelSurface v82; // [sp+60h] [-B0h] BYREF

  LODWORD(v5) = 0;
  HIDWORD(v5) = &this->surfaces;
  v6 = 0;
  v7 = 0;
  if ( this->surfaces.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  v8 = *(_DWORD *)(HIDWORD(v5) + 8);
  v9 = __CFADD__(-v8, v8 ^ 0x80000000) - 1;
  *(_DWORD *)(HIDWORD(v5) + 4) = v9 & v8;
  v10 = (idVertexBuffer *)((char *)this->vertexBuffers
                         + ((16
                           * ((int (__fastcall *)(idRenderSystem *, int, int, int, unsigned int))renderSystem->FrameNumber)(
                               a1: renderSystem,
                               a2: v9 & v8,
                               a3: v9,
                               a4,
                               a5: (v8 ^ 0x80000000) - v8))
                          & 0x10));
  v11 = (char *)idVertexBuffer::MapBuffer(this: v10, mapType: BM_WRITE_NOSYNC);
  v12 = 0;
  if ( this->boxes.num > 0 )
  {
    v13 = 0;
    v14 = v11 - 24;
    do
    {
      v15 = &this->boxes.list[v13];
      CreateDrawVertNormal(drawVertNormal: (unsigned __int8 (*)[4])v81, normal: v15->orientation.mat);
      v16 = v81[0];
      v17 = BYTE2(v81[0]);
      v18 = -HIBYTE(v81[0]);
      v19 = -BYTE1(v81[0]);
      *((_DWORD *)v14 + 11) = v81[0];
      *((_DWORD *)v14 + 19) = v16;
      *((_DWORD *)v14 + 27) = v16;
      *((_DWORD *)v14 + 35) = v16;
      HIBYTE(v81[0]) = v18;
      BYTE1(v81[0]) = v19;
      BYTE2(v81[0]) = -v17;
      LOBYTE(v81[0]) = -LOBYTE(v81[0]);
      v20 = v81[0];
      *((_DWORD *)v14 + 43) = v81[0];
      *((_DWORD *)v14 + 51) = v20;
      *((_DWORD *)v14 + 59) = v20;
      *((_DWORD *)v14 + 67) = v20;
      CreateDrawVertNormal(drawVertNormal: (unsigned __int8 (*)[4])v81, normal: &v15->orientation.mat[1]);
      v21 = v81[0];
      v22 = v81[0];
      v23 = -HIBYTE(v81[0]);
      v24 = -BYTE2(v81[0]);
      *((_DWORD *)v14 + 75) = v81[0];
      *((_DWORD *)v14 + 83) = v21;
      *((_DWORD *)v14 + 91) = v21;
      *((_DWORD *)v14 + 99) = v21;
      HIBYTE(v81[0]) = v23;
      BYTE2(v81[0]) = v24;
      LOBYTE(v81[0]) = -v22;
      BYTE1(v81[0]) = -BYTE1(v81[0]);
      v25 = v81[0];
      *((_DWORD *)v14 + 107) = v81[0];
      *((_DWORD *)v14 + 115) = v25;
      *((_DWORD *)v14 + 123) = v25;
      *((_DWORD *)v14 + 131) = v25;
      CreateDrawVertNormal(drawVertNormal: (unsigned __int8 (*)[4])v81, normal: &v15->orientation.mat[2]);
      v26 = v81[0];
      v27 = -BYTE2(v81[0]);
      BYTE1(v81[0]) = -BYTE1(v81[0]);
      v28 = -LOBYTE(v81[0]);
      HIBYTE(v81[0]) = -HIBYTE(v81[0]);
      *((_DWORD *)v14 + 139) = v26;
      *((_DWORD *)v14 + 147) = v26;
      *((_DWORD *)v14 + 155) = v26;
      *((_DWORD *)v14 + 163) = v26;
      BYTE2(v81[0]) = v27;
      LOBYTE(v81[0]) = v28;
      v29 = v81[0];
      *((_DWORD *)v14 + 171) = v81[0];
      *((_DWORD *)v14 + 179) = v29;
      *((_DWORD *)v14 + 187) = v29;
      *((_DWORD *)v14 + 195) = v29;
      p_x = &this->boxes.list[v13].position.x;
      v31 = (float)(p_x[4] * p_x[12]);
      v32 = (float)(p_x[3] * p_x[12]);
      v33 = (float)(p_x[5] * p_x[12]);
      v34 = (float)(p_x[7] * p_x[12]);
      v35 = (float)(p_x[6] * p_x[12]);
      v36 = (float)(p_x[8] * p_x[12]);
      v37 = (float)(p_x[10] * p_x[12]);
      v38 = (float)(p_x[11] * p_x[12]);
      v39 = (float)(p_x[9] * p_x[12]);
      v40 = (float)((float)((float)(p_x[4] * p_x[12]) + v15->position.y) - (float)(p_x[7] * p_x[12]));
      v41 = (float)((float)((float)(p_x[4] * p_x[12]) + v15->position.y) + (float)(p_x[7] * p_x[12]));
      v42 = (float)((float)(v15->position.x + (float)(p_x[3] * p_x[12])) - (float)(p_x[6] * p_x[12]));
      v43 = (float)((float)(v15->position.z + (float)(p_x[5] * p_x[12])) - (float)(p_x[8] * p_x[12]));
      v44 = (float)((float)(v15->position.z + (float)(p_x[5] * p_x[12])) + (float)(p_x[8] * p_x[12]));
      v45 = (float)((float)(v15->position.x + (float)(p_x[3] * p_x[12])) + (float)(p_x[6] * p_x[12]));
      *((float *)v14 + 7) = (float)((float)((float)(p_x[4] * p_x[12]) + v15->position.y) - (float)(p_x[7] * p_x[12]))
                          + (float)(p_x[10] * p_x[12]);
      *((float *)v14 + 6) = (float)v42 + (float)v39;
      *((float *)v14 + 8) = (float)v43 + (float)v38;
      *((float *)v14 + 15) = (float)v41 + (float)v37;
      *((float *)v14 + 14) = (float)v45 + (float)v39;
      *((float *)v14 + 16) = (float)v44 + (float)v38;
      *((float *)v14 + 22) = (float)v45 - (float)v39;
      *((float *)v14 + 23) = (float)v41 - (float)v37;
      *((float *)v14 + 24) = (float)v44 - (float)v38;
      *((float *)v14 + 30) = (float)v42 - (float)v39;
      *((float *)v14 + 31) = (float)v40 - (float)v37;
      *((float *)v14 + 32) = (float)v43 - (float)v38;
      v46 = (float)(v15->position.z - (float)v33);
      v47 = (float)(v15->position.y - (float)v31);
      v48 = (float)((float)(v15->position.x - (float)v32) - (float)v35);
      v49 = (float)((float)(v15->position.x - (float)v32) + (float)v35);
      v50 = (float)((float)(v15->position.z - (float)v33) - (float)v36);
      v51 = (float)((float)(v15->position.y - (float)v31) - (float)v34);
      *((float *)v14 + 38) = (float)((float)(v15->position.x - (float)v32) - (float)v35) + (float)v39;
      v52 = (float)((float)v47 + (float)v34);
      v53 = (float)((float)v46 + (float)v36);
      *((float *)v14 + 40) = (float)v50 + (float)v38;
      *((float *)v14 + 39) = (float)v51 + (float)v37;
      *((float *)v14 + 46) = (float)v48 - (float)v39;
      *((float *)v14 + 48) = (float)v50 - (float)v38;
      *((float *)v14 + 47) = (float)v51 - (float)v37;
      *((float *)v14 + 55) = (float)v52 - (float)v37;
      *((float *)v14 + 54) = (float)v49 - (float)v39;
      *((float *)v14 + 56) = (float)v53 - (float)v38;
      *((float *)v14 + 63) = (float)v52 + (float)v37;
      *((float *)v14 + 62) = (float)v49 + (float)v39;
      *((float *)v14 + 64) = (float)v53 + (float)v38;
      v54 = (float)((float)((float)v34 + v15->position.y) - (float)v37);
      v55 = (float)((float)((float)v34 + v15->position.y) + (float)v37);
      v56 = (float)((float)(v15->position.x + (float)v35) - (float)v39);
      v57 = (float)((float)(v15->position.z + (float)v36) - (float)v38);
      v58 = (float)((float)(v15->position.x + (float)v35) + (float)v39);
      v59 = (float)((float)(v15->position.z + (float)v36) + (float)v38);
      *((float *)v14 + 71) = (float)((float)((float)v34 + v15->position.y) - (float)v37) + (float)v31;
      *((float *)v14 + 70) = (float)v56 + (float)v32;
      *((float *)v14 + 72) = (float)v57 + (float)v33;
      *((float *)v14 + 78) = (float)v58 + (float)v32;
      *((float *)v14 + 79) = (float)v55 + (float)v31;
      *((float *)v14 + 80) = (float)v59 + (float)v33;
      *((float *)v14 + 87) = (float)v55 - (float)v31;
      *((float *)v14 + 88) = (float)v59 - (float)v33;
      *((float *)v14 + 86) = (float)v58 - (float)v32;
      *((float *)v14 + 94) = (float)v56 - (float)v32;
      *((float *)v14 + 95) = (float)v54 - (float)v31;
      *((float *)v14 + 96) = (float)v57 - (float)v33;
      v60 = (float)(v15->position.z - (float)v36);
      v61 = (float)((float)(v15->position.x - (float)v35) - (float)v39);
      v62 = (float)((float)(v15->position.y - (float)v34) - (float)v37);
      v63 = (float)((float)(v15->position.x - (float)v35) + (float)v39);
      v64 = (float)((float)(v15->position.y - (float)v34) + (float)v37);
      v65 = (float)((float)(v15->position.z - (float)v36) - (float)v38);
      *((float *)v14 + 102) = (float)((float)(v15->position.x - (float)v35) - (float)v39) + (float)v32;
      v66 = (float)((float)v60 + (float)v38);
      *((float *)v14 + 103) = (float)v62 + (float)v31;
      *((float *)v14 + 104) = (float)v65 + (float)v33;
      *((float *)v14 + 110) = (float)v61 - (float)v32;
      *((float *)v14 + 111) = (float)v62 - (float)v31;
      *((float *)v14 + 112) = (float)v65 - (float)v33;
      *((float *)v14 + 118) = (float)v63 - (float)v32;
      *((float *)v14 + 119) = (float)v64 - (float)v31;
      *((float *)v14 + 120) = (float)v66 - (float)v33;
      *((float *)v14 + 126) = (float)v63 + (float)v32;
      *((float *)v14 + 128) = (float)v66 + (float)v33;
      *((float *)v14 + 127) = (float)v64 + (float)v31;
      ++v12;
      v6 += 24;
      v7 += 36;
      v67 = (float)((float)(v15->position.x + (float)v39) - (float)v32);
      ++v13;
      v68 = (float)((float)((float)v37 + v15->position.y) - (float)v31);
      v69 = (float)((float)(v15->position.z + (float)v38) - (float)v33);
      v70 = (float)((float)(v15->position.x + (float)v39) + (float)v32);
      v71 = (float)((float)((float)v37 + v15->position.y) + (float)v31);
      v72 = (float)((float)(v15->position.z + (float)v38) + (float)v33);
      *((float *)v14 + 134) = (float)((float)(v15->position.x + (float)v39) - (float)v32) + (float)v35;
      *((float *)v14 + 135) = (float)v68 + (float)v34;
      *((float *)v14 + 136) = (float)v69 + (float)v36;
      *((float *)v14 + 142) = (float)v70 + (float)v35;
      *((float *)v14 + 143) = (float)v71 + (float)v34;
      *((float *)v14 + 144) = (float)v72 + (float)v36;
      *((float *)v14 + 150) = (float)v70 - (float)v35;
      *((float *)v14 + 151) = (float)v71 - (float)v34;
      *((float *)v14 + 152) = (float)v72 - (float)v36;
      *((float *)v14 + 158) = (float)v67 - (float)v35;
      *((float *)v14 + 159) = (float)v68 - (float)v34;
      *((float *)v14 + 160) = (float)v69 - (float)v36;
      v73 = (float)(v15->position.y - (float)v37);
      v74 = (float)((float)(v15->position.x - (float)v39) - (float)v32);
      v75 = (float)((float)(v15->position.x - (float)v39) + (float)v32);
      v76 = (float)((float)(v15->position.y - (float)v37) - (float)v31);
      v77 = (float)((float)(v15->position.z - (float)v38) - (float)v33);
      v78 = (float)((float)(v15->position.z - (float)v38) + (float)v33);
      *((float *)v14 + 166) = (float)v74 + (float)v35;
      *((float *)v14 + 167) = (float)v76 + (float)v34;
      *((float *)v14 + 168) = (float)v77 + (float)v36;
      *((float *)v14 + 174) = (float)v74 - (float)v35;
      *((float *)v14 + 175) = (float)v76 - (float)v34;
      *((float *)v14 + 176) = (float)v77 - (float)v36;
      *((float *)v14 + 182) = (float)v75 - (float)v35;
      *((float *)v14 + 183) = (float)((float)v73 + (float)v31) - (float)v34;
      *((float *)v14 + 184) = (float)v78 - (float)v36;
      *((float *)v14 + 190) = (float)v75 + (float)v35;
      *((float *)v14 + 191) = (float)((float)v73 + (float)v31) + (float)v34;
      v14 += 768;
      *(float *)v14 = (float)v78 + (float)v36;
    }
    while ( v12 < this->boxes.num );
  }
  material = this->material;
  this->triangles.numVerts = v6;
  this->triangles.numIndexes = v7;
  v82.geometry = &this->triangles;
  v82.materialNum = v5;
  v82.material = material;
  v82.skinOffsets.x = 0.0;
  v82.extraGLState = v5;
  v82.skinOffsets.y = 0.0;
  v82.referenceMask = v5;
  v82.skinOffsets.z = 0.0;
  v82.binaryModelId = v5;
  v82.skinOffsets.w = 0.0;
  v82.joints = (idJointBuffer *)v5;
  v82.morphMap = (idVertexBuffer *)v5;
  v82.stMap = (idVertexBuffer *)v5;
  v82.geometryIsReference = true;
  idVertexBuffer::Reference(this: &this->triangles.vertexBuffer, other: v10);
  idList<idRenderModelSurface,62>::Append(this: (idList<idRenderModelSurface,85> *)HIDWORD(v5), obj: &v82);
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v10);
  return 0;
}

