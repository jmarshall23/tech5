
// ========================================================================
// ??1idRenderModelCuttableBeams@@UAA@XZ
// EA  : 0x827C58B0
// RVA : 0x007C58B0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::~idRenderModelCuttableBeams(idRenderModelCuttableBeams *this)
{
  this->__vftable = (idRenderModelCuttableBeams_vtbl *)&idRenderModelCuttableBeams::`vftable';
  this->graphManager = nullptr;
  this->graphHandle = -1;
  this->materialIncision = nullptr;
  this->materialIncisionCross = nullptr;
  idRenderModel::FreeSurfaces(this);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$229420
// EA  : 0x827C5918
// RVA : 0x007C5918
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_229420()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// ?Create@idRenderModelCuttableBeams@@QAAXPBVidMaterial@@0@Z
// EA  : 0x827C5940
// RVA : 0x007C5940
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::Create(
        idRenderModelCuttableBeams *this,
        const idMaterial *materialIncision_,
        const idMaterial *materialIncisionCross_)
{
  this->materialIncision = materialIncision_;
  this->materialIncisionCross = materialIncisionCross_;
}


// ========================================================================
// ?EndFrame@idRenderModelCuttableBeams@@SAXXZ
// EA  : 0x827C5950
// RVA : 0x007C5950
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

static void __fastcall idRenderModelCuttableBeams::EndFrame()
{
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer]);
  idRenderModelCuttableBeams::deferredVertices = nullptr;
}


// ========================================================================
// ?Update@idRenderModelCuttableBeams@@QAAXPAVidCutterGraphManager@@H@Z
// EA  : 0x827C5998
// RVA : 0x007C5998
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::Update(
        idRenderModelCuttableBeams *this,
        idCutterGraphManager *graphManager_,
        int graphHandle_)
{
  this->graphManager = graphManager_;
  this->graphHandle = graphHandle_;
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// ??0idRenderModelCuttableBeams@@QAA@XZ
// EA  : 0x827C59B0
// RVA : 0x007C59B0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

idRenderModelCuttableBeams *__fastcall idRenderModelCuttableBeams::idRenderModelCuttableBeams(
        idRenderModelCuttableBeams *this)
{
  char v2; // r8
  char v3; // r10
  int v4; // r27
  idTriangles *v5; // r3
  idTriangles *v6; // r30

  idRenderModel::idRenderModel(this);
  v2 = *((_BYTE *)&this->g + 106);
  v3 = *((_BYTE *)&this->g + 116);
  *((_BYTE *)&this->g + 105) |= 0xC0u;
  this->__vftable = (idRenderModelCuttableBeams_vtbl *)&idRenderModelCuttableBeams::`vftable';
  *((_BYTE *)&this->g + 106) = v2 | 4;
  this->materialIncision = nullptr;
  this->materialIncisionCross = nullptr;
  *((_BYTE *)&this->g + 116) = v3 | 0x20;
  this->graphManager = nullptr;
  this->graphHandle = -1;
  this->referenceBounds.b[0].x = -1.0;
  this->referenceBounds.b[0].y = -1.0;
  this->referenceBounds.b[0].z = -1.0;
  this->referenceBounds.b[1].x = 1.0;
  this->referenceBounds.b[1].y = 1.0;
  v4 = 3;
  this->referenceBounds.b[1].z = 1.0;
  do
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x84u,
                          tag: TAG_TRIANGLES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->bounds.b[0].x = -1.0;
    v6->bounds.b[0].y = -1.0;
    v6->bounds.b[0].z = -1.0;
    v6->bounds.b[1].x = 1.0;
    v6->bounds.b[1].y = 1.0;
    v6->bounds.b[1].z = 1.0;
    idVertexBuffer::Reference(this: &v6->vertexBuffer, other: idRenderModelCuttableBeams::vertexBuffer);
    idIndexBuffer::Reference(this: &v6->indexBuffer, other: &idRenderModelCuttableBeams::indexBuffer);
    v6->numVerts = 0;
    v6->numIndexes = 0;
    idRenderModel::AddSurface(this: nullptr, surf: nullptr);
    --v4;
  }
  while ( v4 != 0 );
  idRenderModel::FinishSurfaces(this);
  return this;
}


// ========================================================================
// __unwind$230013
// EA  : 0x827C5B7C
// RVA : 0x007C5B7C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_230013()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 272 + 292));
}


// ========================================================================
// __unwind$230014
// EA  : 0x827C5BA4
// RVA : 0x007C5BA4
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_230014()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?Init@idRenderModelCuttableBeams@@SAXXZ
// EA  : 0x827C5C30
// RVA : 0x007C5C30
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

static void __fastcall idRenderModelCuttableBeams::Init()
{
  idVertexBuffer *v0; // r31
  char *v1; // r3
  int v2; // r10
  char *v3; // r11
  int i; // ctr

  v0 = idRenderModelCuttableBeams::vertexBuffer;
  do
    idVertexBuffer::AllocBufferObject(
      this: v0++,
      data: nullptr,
      allocSize: 0x80000,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
  while ( (int)v0 < (int)&idRenderModelCuttableBeams::indexBuffer );
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelCuttableBeams::indexBuffer,
    data: nullptr,
    allocSize: 49152,
    allocUsage: BU_DYNAMIC);
  v1 = (char *)idIndexBuffer::MapBuffer(this: &idRenderModelCuttableBeams::indexBuffer, mapType: BM_WRITE);
  v2 = 3;
  v3 = v1 - 2;
  for ( i = 4096; i != 0; --i )
  {
    *((_WORD *)v3 + 3) = v2;
    *((_WORD *)v3 + 1) = v2 - 3;
    *((_WORD *)v3 + 2) = v2 - 1;
    *((_WORD *)v3 + 4) = v2 - 3;
    *((_WORD *)v3 + 5) = v2;
    v3 += 12;
    *(_WORD *)v3 = v2 - 2;
    v2 += 4;
  }
  idIndexBuffer::UnmapBuffer(this: &idRenderModelCuttableBeams::indexBuffer);
}


// ========================================================================
// ?Shutdown@idRenderModelCuttableBeams@@SAXXZ
// EA  : 0x827C5D28
// RVA : 0x007C5D28
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

static void __fastcall idRenderModelCuttableBeams::Shutdown()
{
  idVertexBuffer *v0; // r31

  if ( !idLib::headless )
  {
    if ( idRenderModelCuttableBeams::deferredVertices != nullptr )
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer]);
    v0 = idRenderModelCuttableBeams::vertexBuffer;
    do
      idVertexBuffer::FreeBufferObject(this: v0++);
    while ( (int)v0 < (int)&idRenderModelCuttableBeams::indexBuffer );
    idIndexBuffer::FreeBufferObject(this: &idRenderModelCuttableBeams::indexBuffer);
  }
}


// ========================================================================
// ?StartFrame@idRenderModelCuttableBeams@@SAXXZ
// EA  : 0x827C5DB8
// RVA : 0x007C5DB8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

static void __fastcall idRenderModelCuttableBeams::StartFrame()
{
  idRenderModelCuttableBeams::currentBuffer = (idRenderModelCuttableBeams::currentBuffer + 1) % 3;
  idRenderModelCuttableBeams::deferredVertices = (idDrawVert *)idVertexBuffer::MapBuffer(
                                                                 this: &idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer],
                                                                 mapType: BM_WRITE_NOSYNC);
  idRenderModelCuttableBeams::vertexOffset = 0;
}


// ========================================================================
// ?SetBounds@idRenderModelCuttableBeams@@QAAXABVidBounds@@@Z
// EA  : 0x827C5E30
// RVA : 0x007C5E30
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::SetBounds(idRenderModelCuttableBeams *this, const idBounds *bounds)
{
  double x; // fp12
  double y; // fp11
  int v4; // r9
  double z; // fp10
  double v6; // fp9
  double v7; // fp8
  double v8; // fp13
  double v9; // fp12
  double v10; // fp11
  double v11; // fp10
  double v12; // fp9
  int v13; // r11
  float *geometry; // r10

  x = bounds->b[1].x;
  y = bounds->b[0].y;
  v4 = 0;
  z = bounds->b[0].z;
  v6 = bounds->b[1].y;
  v7 = bounds->b[1].z;
  v8 = (float)(bounds->b[0].x - (float)1.0);
  this->referenceBounds.b[0].x = bounds->b[0].x - (float)1.0;
  v9 = (float)((float)x + (float)1.0);
  v10 = (float)((float)y - (float)1.0);
  this->referenceBounds.b[1].x = v9;
  v11 = (float)((float)z - (float)1.0);
  this->referenceBounds.b[0].y = v10;
  this->referenceBounds.b[0].z = v11;
  v12 = (float)((float)v6 + (float)1.0);
  this->referenceBounds.b[1].y = v12;
  this->referenceBounds.b[1].z = (float)v7 + (float)1.0;
  if ( this->surfaces.num > 0 )
  {
    v13 = 0;
    do
    {
      if ( &this->surfaces.list[v13] != nullptr )
      {
        geometry = (float *)this->surfaces.list[v13].geometry;
        *geometry = v8;
        geometry[1] = v10;
        geometry[2] = v11;
        geometry[3] = v9;
        geometry[4] = v12;
        geometry[5] = (float)v7 + (float)1.0;
      }
      ++v4;
      ++v13;
    }
    while ( v4 < this->surfaces.num );
  }
}


// ========================================================================
// ?Save@idRenderModelCuttableBeams@@UBAXPAVidFile@@@Z
// EA  : 0x827C5ED8
// RVA : 0x007C5ED8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::Save(idRenderModelCuttableBeams *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  const idMaterial *materialIncision; // r11
  idFile_vtbl *v6; // r10
  const idMaterial *materialIncisionCross; // r11
  _BYTE v8[8]; // [sp+50h] [-20h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  v8[0] = this->materialIncision != nullptr;
  v4->Write(this: fp, a2: v8, a3: 1u);
  materialIncision = this->materialIncision;
  if ( materialIncision != nullptr )
    idFile::WriteString(this: fp, string: materialIncision->name.str);
  v6 = fp->__vftable;
  v8[0] = this->materialIncisionCross != nullptr;
  v6->Write(this: fp, a2: v8, a3: 1u);
  materialIncisionCross = this->materialIncisionCross;
  if ( materialIncisionCross != nullptr )
    idFile::WriteString(this: fp, string: materialIncisionCross->name.str);
}


// ========================================================================
// ?Load@idRenderModelCuttableBeams@@UAA_NPAVidFile@@@Z
// EA  : 0x827C5FA0
// RVA : 0x007C5FA0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

int __fastcall idRenderModelCuttableBeams::Load(idRenderModelCuttableBeams *this, idFile *fp)
{
  idFile_vtbl *v4; // r11
  const idMaterial *v6; // r3
  const idMaterial *v7; // r3
  char v8; // [sp+50h] [-90h] BYREF
  _BYTE v9[15]; // [sp+51h] [-8Fh] BYREF
  idStr v10; // [sp+60h] [-80h] BYREF
  idStr v11[3]; // [sp+80h] [-60h] BYREF

  if ( !idRenderModel::Load(this, fp) )
    return 0;
  v4 = fp->__vftable;
  v8 = 0;
  if ( v4->Read(this: fp, a2: &v8, a3: 1u) == 0 )
    return 0;
  if ( v8 != 0 )
  {
    v10.allocedAndFlag = 20;
    v10.len = 0;
    v10.data = v10.baseBuffer;
    v10.baseBuffer[0] = 0;
    if ( idFile::ReadString(this: fp, string: &v10) == 0 )
    {
      idStr::FreeData(this: &v10);
      return 0;
    }
    if ( v10.data != nullptr )
      v6 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v10.data,
                                 makeDefault: true);
    else
      v6 = nullptr;
    this->materialIncision = v6;
    idStr::FreeData(this: &v10);
  }
  v9[0] = 0;
  if ( fp->Read(this: fp, a2: v9, a3: 1u) == 0 )
    return 0;
  if ( v9[0] != 0 )
  {
    v11[0].allocedAndFlag = 20;
    v11[0].len = 0;
    v11[0].data = v11[0].baseBuffer;
    v11[0].baseBuffer[0] = 0;
    if ( idFile::ReadString(this: fp, string: v11) == 0 )
    {
      idStr::FreeData(this: v11);
      return 0;
    }
    if ( v11[0].data != nullptr )
      v7 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v11[0].data,
                                 makeDefault: true);
    else
      v7 = nullptr;
    this->materialIncisionCross = v7;
    idStr::FreeData(this: v11);
  }
  return 1;
}


// ========================================================================
// __unwind$230758
// EA  : 0x827C6114
// RVA : 0x007C6114
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_230758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$230759
// EA  : 0x827C613C
// RVA : 0x007C613C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_230759()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?BuildIncisions@idRenderModelCuttableBeams@@AAAXABUgraphTree_t@@@Z
// EA  : 0x827C6168
// RVA : 0x007C6168
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::BuildIncisions(
        idRenderModelCuttableBeams *this,
        const graphTree_t *graphTree)
{
  idRenderModelSurface *v2; // r21
  const graphTree_t *v3; // r22
  const idMaterial **p_materialIncision; // r16
  idTriangles *v5; // r11
  int *v7; // r24
  int *p_num; // r19
  int v9; // r30
  int num; // r5
  int v11; // r25
  int v12; // r18
  double v13; // fp7
  double v14; // fp31
  int v15; // r11
  int v16; // r20
  idStaticList<graphBranch_t,256> *p_branches; // r17
  idDrawVert **v18; // r23
  graphBranch_t *v22; // r10
  __int16 v23; // r9
  int v24; // r5
  idDrawVert *v25; // r7
  int v26; // r8
  int v27; // r9
  idDrawVert *v28; // r31
  double v29; // fp12
  int index; // r4
  int v31; // r28
  int v32; // r6
  int v34; // r30
  float *p_x; // r11
  double v36; // fp8
  float *v37; // r9
  float *v38; // r8
  double v39; // fp0
  float *v40; // r10
  double v41; // fp13
  float *v42; // r7
  double v43; // fp4
  float *v44; // r11
  double v45; // fp30
  double v46; // fp29
  double v47; // fp9
  double v48; // fp5
  double v49; // fp10
  double v52; // fp4
  double v53; // fp11
  double v54; // fp11
  double v55; // fp9
  double v56; // fp5
  double v57; // fp11
  double v58; // fp10
  double v59; // fp9
  float v61; // r23
  float v62; // r22
  float v64; // r11
  double v71; // fp28
  double v72; // fp0
  double v73; // fp30
  double v75; // fp5
  double v78; // fp11
  double v79; // fp26
  double v80; // fp23
  double v81; // fp13
  double v82; // fp24
  double v83; // fp25
  double v84; // fp4
  double v85; // fp29
  int v88; // ctr
  int v91; // ctr
  idTriangles *geometry; // r7
  int v96; // [sp+50h] [-1F0h]
  int v97; // [sp+58h] [-1E8h]
  float v98; // [sp+60h] [-1E0h] BYREF
  float v99; // [sp+64h] [-1DCh]
  float v100; // [sp+68h] [-1D8h]
  const idMaterial **v101; // [sp+6Ch] [-1D4h]
  idRenderModelSurface *list; // [sp+70h] [-1D0h]
  int v103; // [sp+74h] [-1CCh]
  int *v104; // [sp+78h] [-1C8h]
  void *v105; // [sp+7Ch] [-1C4h]
  idStaticList<graphBranch_t,256> *v106; // [sp+80h] [-1C0h]
  float v107; // [sp+88h] [-1B8h]
  float v108; // [sp+8Ch] [-1B4h]
  float v109; // [sp+90h] [-1B0h]
  __vector4 *v110; // [sp+94h] [-1ACh]
  idDrawVert **v111; // [sp+98h] [-1A8h]
  int *v112; // [sp+9Ch] [-1A4h]
  float *v113; // [sp+A0h] [-1A0h]
  int v114; // [sp+A4h] [-19Ch]
  idVec3 v115; // [sp+A8h] [-198h] BYREF
  float v116[6]; // [sp+B8h] [-188h] BYREF
  float v117[4]; // [sp+D0h] [-170h] BYREF
  float v118; // [sp+E0h] [-160h] BYREF
  char v119; // [sp+EAh] [-156h] BYREF
  float v120[8]; // [sp+F0h] [-150h] BYREF
  float v121[8]; // [sp+110h] [-130h] BYREF
  float v122[8]; // [sp+130h] [-110h] BYREF
  idVec3 v123; // [sp+150h] [-F0h] BYREF
  idVec3 v124[7]; // [sp+160h] [-E0h] BYREF

  v3 = graphTree;
  list = this->surfaces.list;
  v2 = list;
  if ( list != nullptr )
  {
    p_materialIncision = &this->materialIncision;
    v101 = &this->materialIncision;
    if ( this->materialIncision != nullptr )
    {
      idCutterGraphManager::GetNormalVectors(
        this: this->graphManager,
        id: this->graphHandle,
        normal_: &v115,
        left_: v124,
        up_: &v123);
      v7 = &idRenderModelCuttableBeams::vertexOffset;
      v104 = &idRenderModelCuttableBeams::vertexOffset;
      p_num = &v3->branches.num;
      v112 = &v3->branches.num;
      v9 = 0;
      num = v3->branches.num;
      v11 = 0;
      v12 = 0;
      v13 = (float)(beamWidth * (float)0.5);
      v96 = 0;
      v14 = (float)((float)1.0 / beamRepeat);
      v15 = idRenderModelCuttableBeams::vertexOffset;
      v103 = 6 * (idRenderModelCuttableBeams::vertexOffset >> 2);
      if ( num > 0 )
      {
        v97 = 0;
        v16 = 0;
        p_branches = &v3->branches;
        v105 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        v106 = &v3->branches;
        v18 = &idRenderModelCuttableBeams::deferredVertices;
        v110 = &_vmx_3f8000003f8000003f8000003f800000;
        _R3 = 16;
        v113 = (float *)&idMath::FLT_SMALLEST_NON_DENORMAL;
        _R26 = 4;
        v111 = &idRenderModelCuttableBeams::deferredVertices;
        _R29 = &vec3_origin;
        do
        {
          v22 = (graphBranch_t *)((char *)p_branches->list + v16);
          v23 = v22->num;
          if ( v23 > 0 )
          {
            v24 = 4 * v23 - 4;
            if ( v15 + v24 <= 0x4000 )
            {
              v25 = *v18;
              v98 = 0.0;
              v99 = 0.0;
              *v7 = v15 + v24;
              v9 += v24;
              v26 = 3 * v23;
              v27 = v22->num;
              v100 = 0.0;
              v28 = &v25[v15];
              v15 += v24;
              v29 = 0.0;
              index = v22->index;
              v11 = 2 * v26 + v11 - 6;
              v31 = v27 + index - 1;
              v32 = index;
              v114 = v9;
              if ( index < v31 )
              {
                __asm { vspltisw128 v63, 0 }
                _R5 = (char *)((char *)&v118 - (char *)v28);
                v34 = index;
                do
                {
                  p_x = &v3->positions.list[v34].x;
                  v36 = v29;
                  v37 = p_x + 1;
                  v38 = p_x + 4;
                  v39 = p_x[3];
                  v40 = p_x + 5;
                  v41 = *p_x;
                  v42 = p_x + 2;
                  v43 = (float)(p_x[3] - *p_x);
                  v45 = (float)(p_x[4] - p_x[1]);
                  v46 = (float)(p_x[5] - p_x[2]);
                  v47 = (float)((float)((float)(p_x[5] - p_x[2]) * v115.x) - (float)(v115.z * (float)(p_x[3] - *p_x)));
                  v48 = (float)((float)(v115.y * (float)(p_x[3] - *p_x)) - (float)((float)(p_x[4] - p_x[1]) * v115.x));
                  v49 = (float)((float)(v115.z * (float)(p_x[4] - p_x[1])) - (float)(v115.y * (float)(p_x[5] - p_x[2])));
                  v29 = (float)((float)((float)__fsqrts((float)((float)((float)v43 * (float)v43)
                                                              + (float)((float)((float)v46 * (float)v46)
                                                                      + (float)((float)v45 * (float)v45))))
                                      * (float)v14)
                              + (float)v29);
                  _FP4 = (float)((float)((float)((float)v49 * (float)v49)
                                       + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47)))
                               - *v113);
                  __asm { fsel      f11, f4, f30, f11 }
                  v52 = __frsqrte(_FP11);
                  v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5))
                                                                                              * (float)v52)
                                                                                      - (float)1.5)
                                                                      * (float)v52)
                                                              * (float)((float)((float)((float)v49 * (float)v49)
                                                                              + (float)((float)((float)v48 * (float)v48)
                                                                                      + (float)((float)v47 * (float)v47)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v52
                                                                                              * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5))
                                                                                      * (float)v52)
                                                                              - (float)1.5)
                                                              * (float)v52))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v52
                                                                      * (float)((float)((float)((float)v49 * (float)v49)
                                                                                      + (float)((float)((float)v48 * (float)v48)
                                                                                              + (float)((float)v47 * (float)v47)))
                                                                              * (float)0.5))
                                                              * (float)v52)
                                                      - (float)1.5)
                                      * (float)v52));
                  v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5)) * (float)v52) - (float)1.5) * (float)v52) * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5)) * (float)v52) - (float)1.5) * (float)v52))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v49 * (float)v49) + (float)((float)((float)v48 * (float)v48) + (float)((float)v47 * (float)v47))) * (float)0.5)) * (float)v52)
                                                                                              - (float)1.5)
                                                                              * (float)v52))
                                                              * (float)((float)((float)((float)v49 * (float)v49)
                                                                              + (float)((float)((float)v48 * (float)v48)
                                                                                      + (float)((float)v47 * (float)v47)))
                                                                      * (float)0.5))
                                                      * (float)v53)
                                              - (float)1.5)
                              * (float)v53);
                  v55 = (float)((float)((float)((float)(p_x[5] - p_x[2]) * v115.x)
                                      - (float)(v115.z * (float)(p_x[3] - *p_x)))
                              * (float)v54);
                  v56 = (float)((float)((float)(v115.y * (float)(p_x[3] - *p_x))
                                      - (float)((float)(p_x[4] - p_x[1]) * v115.x))
                              * (float)v54);
                  v57 = (float)((float)((float)((float)(v115.z * (float)(p_x[4] - p_x[1]))
                                              - (float)(v115.y * (float)(p_x[5] - p_x[2])))
                                      * (float)v54)
                              * (float)v13);
                  v44 = v116;
                  v116[0] = v57;
                  v58 = (float)((float)v55 * (float)v13);
                  v116[1] = (float)v55 * (float)v13;
                  v59 = (float)((float)v56 * (float)v13);
                  v116[2] = (float)v56 * (float)v13;
                  if ( v32 != index )
                    v44 = &v98;
                  __asm { vor128    v62, v95, v63 }
                  _R24 = v117;
                  v61 = *v44;
                  __asm { vor128    v61, v95, v63 }
                  v62 = v44[1];
                  _R21 = v117;
                  v64 = v44[2];
                  v98 = v57;
                  __asm { vcmpequw128 v60, v94, v62 }
                  v99 = v58;
                  v100 = (float)v56 * (float)v13;
                  __asm
                  {
                    vor128    v59, v95, v63
                    stvx128   v62, r0, r24
                    vor128    v58, v95, v63
                    vcmpequw128 v57, v93, v61
                  }
                  _R24 = v120;
                  __asm
                  {
                    vsldoi128 v56, v94, v60, 4
                    stvx128   v56, r21, r3
                    vcmpequw128 v55, v91, v59
                  }
                  _R21 = v120;
                  __asm { vcmpequw128 v54, v90, v58 }
                  _R20 = v121;
                  __asm { vsldoi128 v53, v93, v57, 4 }
                  _R19 = v121;
                  __asm { stvx128   v61, r0, r24 }
                  _R18 = v122;
                  __asm { vsldoi128 v52, v91, v55, 4 }
                  _R24 = v122;
                  __asm { vsldoi128 v51, v90, v54, 4 }
                  v71 = (float)((float)v39 - (float)v57);
                  v72 = (float)((float)v39 + (float)v57);
                  v109 = v64;
                  v108 = v62;
                  __asm { vor128    v50, v95, v63 }
                  v107 = v61;
                  __asm { stvx128   v53, r21, r3 }
                  v73 = (float)((float)v41 - v61);
                  __asm { stvx128   v59, r0, r20 }
                  __asm { stvx128   v52, r19, r3 }
                  v75 = (float)((float)v41 + v61);
                  __asm { stvx128   v58, r0, r18 }
                  _R23 = 8;
                  __asm { stvx128   v51, r24, r3 }
                  _R24 = v105;
                  v78 = *v40;
                  v79 = *v38;
                  __asm { lvlx128   v48, r0, r29 }
                  v80 = (float)(*v42 - v64);
                  v81 = (float)(*v42 + v64);
                  _R11 = v110;
                  v82 = (float)(*v37 - v62);
                  __asm { lvlx128   v49, r29, r23 }
                  v83 = (float)(*v38 - (float)v58);
                  __asm { lvx128    v62, r0, r11 }
                  v84 = (float)(*v37 + v62);
                  __asm { lvx128    v0, r0, r24 }
                  v85 = (float)(*v40 - (float)v59);
                  v117[3] = v36;
                  v120[3] = v36;
                  v121[3] = v29;
                  v122[3] = v29;
                  __asm { vrlimi128 v50, v48, 8, 0 }
                  v117[0] = v73;
                  v117[1] = v82;
                  v117[2] = v80;
                  v120[0] = v75;
                  v120[1] = v84;
                  v120[2] = v81;
                  v118 = 1.0;
                  v120[4] = 0.0;
                  v121[4] = 1.0;
                  v122[4] = 0.0;
                  v121[0] = v71;
                  v121[1] = v83;
                  __asm { lvlx128   v47, r29, r26 }
                  _R9 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
                  __asm { vrlimi128 v50, v47, 4, 3 }
                  v121[2] = v85;
                  _R11 = &v119;
                  v122[0] = v72;
                  v88 = 4;
                  v122[1] = (float)v79 + (float)v58;
                  _R10 = -2;
                  __asm
                  {
                    vrlimi128 v50, v49, 2, 2
                    lvx128    v13, r0, r9
                  }
                  v122[2] = (float)v78 + (float)v59;
                  _R9 = -1;
                  __asm
                  {
                    vaddfp128 v12, v82, v62
                    vmaddfp   v0, v12, v0, v13
                    vcfpsxws128 v62, v0, 0
                  }
                  do
                  {
                    __asm { vor128    v46, v94, v62 }
                    _R11[2] = -1;
                    _R11[3] = -1;
                    _R11[4] = -1;
                    _R11[5] = -1;
                    __asm
                    {
                      vpkswss128 v45, v78, v46
                      vpkshus128 v0, v77, v45
                      stvebx    v0, r11, r10
                      stvebx    v0, r11, r9
                      stvebx    v0, 0, r11
                    }
                    _R11 += 32;
                    --v88;
                  }
                  while ( v88 != 0 );
                  v91 = 4;
                  _R11 = v28;
                  _R9 = _R5 - 16;
                  _R8 = 16;
                  do
                  {
                    __asm
                    {
                      lvx128    v44, r9, r11
                      stvx128   v44, r0, r11
                      lvx128    v43, r5, r11
                      stvx128   v43, r11, r8
                    }
                    ++_R11;
                    --v91;
                  }
                  while ( v91 != 0 );
                  ++v32;
                  v3 = graphTree;
                  v28 = _R11;
                  _R5 -= 128;
                  ++v34;
                }
                while ( v32 < v31 );
                v7 = v104;
                v16 = v97;
                v18 = v111;
                p_branches = v106;
                p_num = v112;
                v15 = *v104;
                p_materialIncision = v101;
                v12 = v96;
                v9 = v114;
                v2 = list;
              }
            }
          }
          ++v12;
          v16 += 4;
          v96 = v12;
          v97 = v16;
        }
        while ( v12 < *p_num );
      }
      geometry = v2->geometry;
      v2->material = *p_materialIncision;
      geometry->numVerts = v9;
      v2->geometry->numIndexes = v11;
      idVertexBuffer::Reference(
        this: &v2->geometry->vertexBuffer,
        other: &idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer]);
      idIndexBuffer::Reference(
        this: &v2->geometry->indexBuffer,
        other: &idRenderModelCuttableBeams::indexBuffer,
        refOffset: 2 * v103,
        refSize: 2 * v11);
    }
    else
    {
      v5 = list->geometry;
      list->material = nullptr;
      v5->numVerts = 0;
      v2->geometry->numIndexes = 0;
    }
  }
}


// ========================================================================
// ?BuildIncisionCrossings@idRenderModelCuttableBeams@@AAAXABUgraphTree_t@@@Z
// EA  : 0x827C6730
// RVA : 0x007C6730
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::BuildIncisionCrossings(
        idRenderModelCuttableBeams *this,
        const graphTree_t *graphTree)
{
  idRenderModelSurface *list; // r11
  idRenderModelSurface *v4; // r21
  int v5; // r11
  int num; // r31
  const idMaterial **p_materialIncisionCross; // r18
  int v8; // r22
  int v9; // r20
  int v10; // r19
  idDrawVert *v11; // r29
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp0
  double v17; // fp13
  double v18; // fp12
  idStaticList<idVec3,1024> *p_intersections; // r25
  int v21; // r3
  float *p_x; // r10
  int v32; // ctr
  double v33; // fp4
  double v34; // fp3
  double v35; // fp2
  double v36; // fp1
  double v37; // fp6
  double v38; // fp5
  double v39; // fp3
  int v40; // ctr
  idTriangles *geometry; // r7
  idTriangles *v45; // r10
  idVec3 v46; // [sp+58h] [-148h] BYREF
  idVec3 v47; // [sp+68h] [-138h] BYREF
  float v48; // [sp+80h] [-120h]
  float v49; // [sp+84h] [-11Ch]
  float v50; // [sp+88h] [-118h]
  float v51; // [sp+8Ch] [-114h]
  float v52; // [sp+90h] [-110h] BYREF
  char v53; // [sp+9Ah] [-106h] BYREF
  float v54; // [sp+A0h] [-100h]
  float v55; // [sp+A4h] [-FCh]
  float v56; // [sp+A8h] [-F8h]
  float v57; // [sp+ACh] [-F4h]
  float v58; // [sp+B0h] [-F0h]
  float v59; // [sp+C0h] [-E0h]
  float v60; // [sp+C4h] [-DCh]
  float v61; // [sp+C8h] [-D8h]
  float v62; // [sp+CCh] [-D4h]
  float v63; // [sp+D0h] [-D0h]
  float v64; // [sp+E0h] [-C0h]
  float v65; // [sp+E4h] [-BCh]
  float v66; // [sp+E8h] [-B8h]
  float v67; // [sp+ECh] [-B4h]
  float v68; // [sp+F0h] [-B0h]
  idVec3 v69; // [sp+100h] [-A0h] BYREF

  list = this->surfaces.list;
  v4 = list + 1;
  if ( list != (idRenderModelSurface *)-56 )
  {
    v5 = idRenderModelCuttableBeams::vertexOffset;
    num = (0x4000 - idRenderModelCuttableBeams::vertexOffset) >> 2;
    if ( graphTree->intersections.num < num )
      num = graphTree->intersections.num;
    p_materialIncisionCross = &this->materialIncisionCross;
    if ( this->materialIncisionCross != nullptr && num > 0 )
    {
      v8 = 4 * num;
      idRenderModelCuttableBeams::vertexOffset += 4 * num;
      v9 = 6 * num;
      v10 = 6 * (v5 >> 2);
      v11 = &idRenderModelCuttableBeams::deferredVertices[v5];
      idCutterGraphManager::GetNormalVectors(
        this: this->graphManager,
        id: this->graphHandle,
        normal_: &v69,
        left_: &v47,
        up_: &v46);
      v13 = (float)(v47.x * (float)(beamWidth * (float)0.5));
      v14 = (float)(v47.y * (float)(beamWidth * (float)0.5));
      v15 = (float)(v47.z * (float)(beamWidth * (float)0.5));
      v16 = (float)(v46.x * (float)(beamWidth * (float)0.5));
      v17 = (float)(v46.y * (float)(beamWidth * (float)0.5));
      v18 = (float)(v46.z * (float)(beamWidth * (float)0.5));
      __asm { vspltisw128 v62, 0 }
      _R5 = (char *)((char *)&v52 - (char *)v11);
      p_intersections = &graphTree->intersections;
      v21 = 0;
      _R9 = 4;
      _R26 = 8;
      _R23 = -2;
      _R24 = -1;
      _R30 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      _R28 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R27 = &_vmx_3f8000003f8000003f8000003f800000;
      _R6 = &vec3_origin;
      do
      {
        __asm
        {
          vor128    v61, v94, v62
          lvlx128   v60, r0, r6
          lvlx128   v58, r6, r9
        }
        __asm { lvlx128   v59, r6, r26 }
        __asm { lvx128    v63, r0, r27 }
        p_x = &p_intersections->list[v21].x;
        __asm
        {
          vrlimi128 v61, v60, 8, 0
          lvx128    v0, r0, r28
          lvx128    v13, r0, r30
        }
        _R11 = &v53;
        v51 = 1.0;
        v32 = 4;
        v52 = 1.0;
        __asm { vrlimi128 v61, v58, 4, 3 }
        v33 = (float)(*p_x - (float)v13);
        v34 = p_x[2];
        v35 = (float)(p_x[1] - (float)v14);
        v36 = (float)(p_x[2] - (float)v15);
        __asm { vrlimi128 v61, v59, 2, 2 }
        v37 = (float)(*p_x + (float)v13);
        v38 = (float)(p_x[1] + (float)v14);
        v57 = 0.0;
        v58 = 1.0;
        v39 = (float)((float)v34 + (float)v15);
        v62 = 1.0;
        v63 = 0.0;
        __asm { vaddfp128 v12, v93, v63 }
        v67 = 0.0;
        v68 = 0.0;
        v48 = (float)v33 - (float)v16;
        v49 = (float)v35 - (float)v17;
        v50 = (float)v36 - (float)v18;
        v59 = (float)v33 + (float)v16;
        v54 = (float)v37 - (float)v16;
        v55 = (float)v38 - (float)v17;
        v56 = (float)v39 - (float)v18;
        v60 = (float)v35 + (float)v17;
        v61 = (float)v36 + (float)v18;
        __asm { vmaddfp   v0, v12, v0, v13 }
        v64 = (float)v37 + (float)v16;
        v65 = (float)v38 + (float)v17;
        v66 = (float)v39 + (float)v18;
        __asm { vcfpsxws128 v63, v0, 0 }
        do
        {
          __asm { vor128    v57, v95, v63 }
          _R11[2] = -1;
          _R11[3] = -1;
          _R11[4] = -1;
          _R11[5] = -1;
          __asm
          {
            vpkswss128 v56, v89, v57
            vpkshus128 v0, v88, v56
            stvebx    v0, r11, r23
            stvebx    v0, r11, r24
            stvebx    v0, 0, r11
          }
          _R11 += 32;
          --v32;
        }
        while ( v32 != 0 );
        v40 = 4;
        _R11 = v11;
        _R8 = _R5 - 16;
        _R7 = 16;
        do
        {
          __asm
          {
            lvx128    v55, r8, r11
            stvx128   v55, r0, r11
            lvx128    v54, r5, r11
            stvx128   v54, r11, r7
          }
          ++_R11;
          --v40;
        }
        while ( v40 != 0 );
        --num;
        v11 = _R11;
        _R5 -= 128;
        ++v21;
      }
      while ( num != 0 );
      geometry = v4->geometry;
      v4->material = *p_materialIncisionCross;
      geometry->numVerts = v8;
      v4->geometry->numIndexes = v9;
      idVertexBuffer::Reference(
        this: &v4->geometry->vertexBuffer,
        other: &idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer]);
      idIndexBuffer::Reference(
        this: &v4->geometry->indexBuffer,
        other: &idRenderModelCuttableBeams::indexBuffer,
        refOffset: 2 * v10,
        refSize: 2 * v9);
    }
    else
    {
      v45 = v4->geometry;
      v4->material = nullptr;
      v45->numVerts = 0;
      v4->geometry->numIndexes = 0;
    }
  }
}


// ========================================================================
// ?BuildIncisionEndpoints@idRenderModelCuttableBeams@@AAAXABUgraphTree_t@@@Z
// EA  : 0x827C6A78
// RVA : 0x007C6A78
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __fastcall idRenderModelCuttableBeams::BuildIncisionEndpoints(
        idRenderModelCuttableBeams *this,
        const graphTree_t *graphTree)
{
  idRenderModelSurface *list; // r11
  idRenderModelSurface *v4; // r21
  int v5; // r11
  int num; // r31
  const idMaterial **p_materialIncisionCross; // r18
  int v8; // r22
  int v9; // r20
  int v10; // r19
  idDrawVert *v11; // r29
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp0
  double v17; // fp13
  double v18; // fp12
  idStaticList<idVec3,1024> *p_endpoints; // r25
  int v21; // r3
  float *p_x; // r10
  int v32; // ctr
  double v33; // fp4
  double v34; // fp3
  double v35; // fp2
  double v36; // fp1
  double v37; // fp6
  double v38; // fp5
  double v39; // fp3
  int v40; // ctr
  idTriangles *geometry; // r7
  idTriangles *v45; // r10
  idVec3 v46; // [sp+58h] [-148h] BYREF
  idVec3 v47; // [sp+68h] [-138h] BYREF
  float v48; // [sp+80h] [-120h]
  float v49; // [sp+84h] [-11Ch]
  float v50; // [sp+88h] [-118h]
  float v51; // [sp+8Ch] [-114h]
  float v52; // [sp+90h] [-110h] BYREF
  char v53; // [sp+9Ah] [-106h] BYREF
  float v54; // [sp+A0h] [-100h]
  float v55; // [sp+A4h] [-FCh]
  float v56; // [sp+A8h] [-F8h]
  float v57; // [sp+ACh] [-F4h]
  float v58; // [sp+B0h] [-F0h]
  float v59; // [sp+C0h] [-E0h]
  float v60; // [sp+C4h] [-DCh]
  float v61; // [sp+C8h] [-D8h]
  float v62; // [sp+CCh] [-D4h]
  float v63; // [sp+D0h] [-D0h]
  float v64; // [sp+E0h] [-C0h]
  float v65; // [sp+E4h] [-BCh]
  float v66; // [sp+E8h] [-B8h]
  float v67; // [sp+ECh] [-B4h]
  float v68; // [sp+F0h] [-B0h]
  idVec3 v69; // [sp+100h] [-A0h] BYREF

  list = this->surfaces.list;
  v4 = list + 2;
  if ( list != (idRenderModelSurface *)-112 )
  {
    v5 = idRenderModelCuttableBeams::vertexOffset;
    num = graphTree->endpoints.num;
    if ( num >= (0x4000 - idRenderModelCuttableBeams::vertexOffset) >> 2 )
      num = (0x4000 - idRenderModelCuttableBeams::vertexOffset) >> 2;
    p_materialIncisionCross = &this->materialIncisionCross;
    if ( this->materialIncisionCross != nullptr && num > 0 )
    {
      v8 = 4 * num;
      idRenderModelCuttableBeams::vertexOffset += 4 * num;
      v9 = 6 * num;
      v10 = 6 * (v5 >> 2);
      v11 = &idRenderModelCuttableBeams::deferredVertices[v5];
      idCutterGraphManager::GetNormalVectors(
        this: this->graphManager,
        id: this->graphHandle,
        normal_: &v69,
        left_: &v47,
        up_: &v46);
      v13 = (float)(v47.x * (float)(beamWidth * (float)0.5));
      v14 = (float)(v47.y * (float)(beamWidth * (float)0.5));
      v15 = (float)(v47.z * (float)(beamWidth * (float)0.5));
      v16 = (float)(v46.x * (float)(beamWidth * (float)0.5));
      v17 = (float)(v46.y * (float)(beamWidth * (float)0.5));
      v18 = (float)(v46.z * (float)(beamWidth * (float)0.5));
      __asm { vspltisw128 v62, 0 }
      _R5 = (char *)((char *)&v52 - (char *)v11);
      p_endpoints = &graphTree->endpoints;
      v21 = 0;
      _R9 = 4;
      _R26 = 8;
      _R23 = -2;
      _R24 = -1;
      _R30 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      _R28 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R27 = &_vmx_3f8000003f8000003f8000003f800000;
      _R6 = &vec3_origin;
      do
      {
        __asm
        {
          vor128    v61, v94, v62
          lvlx128   v60, r0, r6
          lvlx128   v58, r6, r9
        }
        __asm { lvlx128   v59, r6, r26 }
        __asm { lvx128    v63, r0, r27 }
        p_x = &p_endpoints->list[v21].x;
        __asm
        {
          vrlimi128 v61, v60, 8, 0
          lvx128    v0, r0, r28
          lvx128    v13, r0, r30
        }
        _R11 = &v53;
        v51 = 1.0;
        v32 = 4;
        v52 = 1.0;
        __asm { vrlimi128 v61, v58, 4, 3 }
        v33 = (float)(*p_x - (float)v13);
        v34 = p_x[2];
        v35 = (float)(p_x[1] - (float)v14);
        v36 = (float)(p_x[2] - (float)v15);
        __asm { vrlimi128 v61, v59, 2, 2 }
        v37 = (float)(*p_x + (float)v13);
        v38 = (float)(p_x[1] + (float)v14);
        v57 = 0.0;
        v58 = 1.0;
        v39 = (float)((float)v34 + (float)v15);
        v62 = 1.0;
        v63 = 0.0;
        __asm { vaddfp128 v12, v93, v63 }
        v67 = 0.0;
        v68 = 0.0;
        v48 = (float)v33 - (float)v16;
        v49 = (float)v35 - (float)v17;
        v50 = (float)v36 - (float)v18;
        v59 = (float)v33 + (float)v16;
        v54 = (float)v37 - (float)v16;
        v55 = (float)v38 - (float)v17;
        v56 = (float)v39 - (float)v18;
        v60 = (float)v35 + (float)v17;
        v61 = (float)v36 + (float)v18;
        __asm { vmaddfp   v0, v12, v0, v13 }
        v64 = (float)v37 + (float)v16;
        v65 = (float)v38 + (float)v17;
        v66 = (float)v39 + (float)v18;
        __asm { vcfpsxws128 v63, v0, 0 }
        do
        {
          __asm { vor128    v57, v95, v63 }
          _R11[2] = -1;
          _R11[3] = -1;
          _R11[4] = -1;
          _R11[5] = -1;
          __asm
          {
            vpkswss128 v56, v89, v57
            vpkshus128 v0, v88, v56
            stvebx    v0, r11, r23
            stvebx    v0, r11, r24
            stvebx    v0, 0, r11
          }
          _R11 += 32;
          --v32;
        }
        while ( v32 != 0 );
        v40 = 4;
        _R11 = v11;
        _R8 = _R5 - 16;
        _R7 = 16;
        do
        {
          __asm
          {
            lvx128    v55, r8, r11
            stvx128   v55, r0, r11
            lvx128    v54, r5, r11
            stvx128   v54, r11, r7
          }
          ++_R11;
          --v40;
        }
        while ( v40 != 0 );
        --num;
        v11 = _R11;
        _R5 -= 128;
        ++v21;
      }
      while ( num != 0 );
      geometry = v4->geometry;
      v4->material = *p_materialIncisionCross;
      geometry->numVerts = v8;
      v4->geometry->numIndexes = v9;
      idVertexBuffer::Reference(
        this: &v4->geometry->vertexBuffer,
        other: &idRenderModelCuttableBeams::vertexBuffer[idRenderModelCuttableBeams::currentBuffer]);
      idIndexBuffer::Reference(
        this: &v4->geometry->indexBuffer,
        other: &idRenderModelCuttableBeams::indexBuffer,
        refOffset: 2 * v10,
        refSize: 2 * v9);
    }
    else
    {
      v45 = v4->geometry;
      v4->material = nullptr;
      v45->numVerts = 0;
      v4->geometry->numIndexes = 0;
    }
  }
}


// ========================================================================
// ?UpdateInView@idRenderModelCuttableBeams@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827C6F78
// RVA : 0x007C6F78
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idRenderModelCuttableBeams::UpdateInView(
        idRenderModelCuttableBeams *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  idRenderModelCuttableBeams *v4; // r28
  idCutterGraphManager *graphManager; // r3
  int graphHandle; // r4
  _BYTE *v8; // r6
  char v9; // r10
  char v10; // r29
  char v11; // r30
  graphTree_t v12; // [sp+50h] [-C470h] BYREF

  v4 = (idRenderModelCuttableBeams *)((int (*)(void))RtlCheckStack12)();
  graphManager = v4->graphManager;
  if ( graphManager == nullptr )
    return 0;
  graphHandle = v4->graphHandle;
  if ( graphHandle < 0
    || v4->surfaces.num <= 0
    || !idCutterGraphManager::IsGraphValid(this: graphManager, id: graphHandle) )
  {
    return 0;
  }
  graphTree_t::graphTree_t(this: &v12);
  idCutterGraphManager::BuildGraphTree(this: v4->graphManager, id: v4->graphHandle, graphTree: &v12, a4: v8);
  if ( g_cuttableBeamIncisions.valueInteger == 0 || (v9 = 0, g_cuttableBeamIncisions.valueInteger == 1) )
    v9 = 1;
  if ( g_cuttableBeamIncisions.valueInteger == 0 || (v10 = 0, g_cuttableBeamIncisions.valueInteger == 2) )
    v10 = 1;
  if ( g_cuttableBeamIncisions.valueInteger == 0 || (v11 = 0, g_cuttableBeamIncisions.valueInteger == 3) )
    v11 = 1;
  if ( v9 != 0 )
    idRenderModelCuttableBeams::BuildIncisions(this: v4, graphTree: &v12);
  if ( v10 != 0 )
    idRenderModelCuttableBeams::BuildIncisionCrossings(this: v4, graphTree: &v12);
  if ( v11 != 0 )
    idRenderModelCuttableBeams::BuildIncisionEndpoints(this: v4, graphTree: &v12);
  idRenderModel::CommitSurfaces(this: v4);
  graphTree_t::~graphTree_t(this: &v12);
  return 1;
}


// ========================================================================
// __unwind$231973
// EA  : 0x827C70AC
// RVA : 0x007C70AC
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void _unwind_231973()
{
  int v0; // r12

  graphTree_t::~graphTree_t(this: (graphTree_t *)(v0 + 15248));
}


// ========================================================================
// `dynamic initializer for 'idRenderModelCuttableBeams::vertexBuffer''
// EA  : 0x83342308
// RVA : 0x01342308
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelCuttableBeams::vertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelCuttableBeams::vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelCuttableBeams::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelCuttableBeams::indexBuffer''
// EA  : 0x83342358
// RVA : 0x01342358
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelCuttableBeams::indexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelCuttableBeams::indexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelCuttableBeams::indexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'g_cuttableBeamIncisions''
// EA  : 0x83342390
// RVA : 0x01342390
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_cuttableBeamIncisions__()
{
  idCVar::idCVar(
    this: &g_cuttableBeamIncisions,
    name: "g_cuttableBeamIncisions",
    value: "0",
    flags: 2,
    description: "0 Render normaly, 1 Render only incisions, 2 Render only incision crossings, 3 Render only incision end-points",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_cuttableBeamIncisions__);
}

