
// ========================================================================
// ?CPUMemoryUsed@idTriangles@@QBAHXZ
// EA  : 0x829718D8
// RVA : 0x009718D8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

idTriangles *__fastcall idTriangles::CPUMemoryUsed(idTriangles *this)
{
  int v1; // r11

  if ( this != nullptr )
  {
    v1 = 0;
    if ( this->verts != nullptr )
      v1 = 32 * this->numVerts;
    if ( this->indexes != nullptr )
      v1 += 2 * this->numIndexes;
    return (idTriangles *)(v1 + 132);
  }
  return this;
}


// ========================================================================
// ?FreeCPUData@idTriangles@@QAAXXZ
// EA  : 0x82971920
// RVA : 0x00971920
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::FreeCPUData(idTriangles *this)
{
  idDrawVert *verts; // r4
  unsigned __int16 *indexes; // r4

  verts = this->verts;
  if ( verts != nullptr )
  {
    idMem::Free(this: &mem, ptr: verts, align: ALIGN_16);
    this->verts = nullptr;
  }
  indexes = this->indexes;
  if ( indexes != nullptr )
    idMem::Free(this: &mem, ptr: indexes, align: ALIGN_16);
  this->indexes = nullptr;
}


// ========================================================================
// ?FreeData@idTriangles@@QAAXXZ
// EA  : 0x82971980
// RVA : 0x00971980
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::FreeData(idTriangles *this)
{
  idDrawVert *verts; // r4
  unsigned __int16 *indexes; // r4

  idVertexBuffer::FreeBufferObject(this: &this->vertexBuffer);
  idIndexBuffer::FreeBufferObject(this: &this->indexBuffer);
  verts = this->verts;
  if ( verts != nullptr )
  {
    idMem::Free(this: &mem, ptr: verts, align: ALIGN_16);
    this->verts = nullptr;
  }
  indexes = this->indexes;
  if ( indexes != nullptr )
    idMem::Free(this: &mem, ptr: indexes, align: ALIGN_16);
  this->indexes = nullptr;
  this->generateNormals = false;
  this->numVerts = 0;
  this->numIndexes = 0;
}


// ========================================================================
// ?AllocStaticTriSurfIndexes@idTriangles@@QAAXH@Z
// EA  : 0x829719F8
// RVA : 0x009719F8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::AllocStaticTriSurfIndexes(idTriangles *this, int numIndexes)
{
  unsigned __int16 *indexes; // r4
  unsigned __int16 *v5; // r3

  indexes = this->indexes;
  if ( indexes != nullptr )
    idMem::Free(this: &mem, ptr: indexes, align: ALIGN_16);
  if ( numIndexes > 0 )
  {
    v5 = (unsigned __int16 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(237) : TAG_TRIANGLES",
                               size: 2 * numIndexes,
                               tag: TAG_TRIANGLES,
                               zeroBuffer: true,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    this->indexes = v5;
    if ( v5 != nullptr )
      return;
    idLib::Error(fmt: "AllocStaticTriSurfIndexes: failed to allocate memory for indices (count %d)", numIndexes);
  }
  this->indexes = nullptr;
}


// ========================================================================
// ?ResizeVerts@idTriangles@@QAAXH@Z
// EA  : 0x82971A88
// RVA : 0x00971A88
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::ResizeVerts(idTriangles *this, int newNumVerts)
{
  idDrawVert *v4; // r29

  if ( (this->numVerts <= 0x10000u) + (this->numVerts < 0) == 0 )
    idLib::Error(fmt: "ResizeVerts: numVerts > %d", 0x10000);
  v4 = (idDrawVert *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(257) : TAG_TRIANGLES",
                       size: 32 * newNumVerts,
                       tag: TAG_TRIANGLES,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    idLib::Error(fmt: "ResizeVerts: failed to allocate memory for vertices (count %d)", newNumVerts);
  if ( newNumVerts >= this->numVerts )
    newNumVerts = this->numVerts;
  memcpy(Dst: v4, Src: this->verts, Size: 32 * newNumVerts);
  idMem::Free(this: &mem, ptr: this->verts, align: ALIGN_16);
  this->verts = v4;
}


// ========================================================================
// ?ResizeIndexes@idTriangles@@QAAXH@Z
// EA  : 0x82971B58
// RVA : 0x00971B58
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::ResizeIndexes(idTriangles *this, int newNumIndexes)
{
  int numIndexes; // r30
  void *v4; // r29

  numIndexes = newNumIndexes;
  v4 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(273) : TAG_TRIANGLES",
         size: 2 * newNumIndexes,
         tag: TAG_TRIANGLES,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    idLib::Error(fmt: "ResizeIndexes: failed to allocate memory for indices (count %d)", numIndexes);
  if ( numIndexes >= this->numIndexes )
    numIndexes = this->numIndexes;
  memcpy(Dst: v4, Src: this->indexes, Size: 2 * numIndexes);
  idMem::Free(this: &mem, ptr: this->indexes, align: ALIGN_16);
  this->indexes = (unsigned __int16 *)v4;
}


// ========================================================================
// ?RangeCheckIndexes@idTriangles@@SAXPAGHH@Z
// EA  : 0x82971BF0
// RVA : 0x00971BF0
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::RangeCheckIndexes(unsigned __int16 *indexes, int numIndexes, int numVerts)
{
  int v4; // r9
  int v5; // r10

  if ( numIndexes >= 0 )
  {
    if ( numVerts >= 0 )
    {
      v4 = 0;
      if ( numIndexes > 0 )
      {
        while ( 1 )
        {
          v5 = *indexes;
          if ( v5 != 0xFFFF && v5 >= numVerts )
            break;
          ++v4;
          ++indexes;
          if ( v4 >= numIndexes )
            return;
        }
        idLib::Error(fmt: "RangeCheckIndexes: index out of range");
      }
    }
    else
    {
      idLib::Error(fmt: "RangeCheckIndexes: numVerts < 0");
    }
  }
  else
  {
    idLib::Error(fmt: "RangeCheckIndexes: numIndexes < 0");
  }
}


// ========================================================================
// ?RemoveDegenerate@idTriangles@@QAAXXZ
// EA  : 0x82971C60
// RVA : 0x00971C60
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::RemoveDegenerate(idTriangles *this)
{
  int v2; // r29
  int v3; // r31
  unsigned __int16 *v4; // r3
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r11

  v2 = 0;
  if ( this->numIndexes / 3 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->indexes[v3];
      v5 = *v4;
      v6 = v4[1];
      if ( v5 == v6 || (v7 = v4[2], v5 == v7) || v6 == v7 )
      {
        v8 = this->numIndexes - 3;
        this->numIndexes = v8;
        memmove(Dst: v4, Src: v4 + 3, Size: 2 * v8 - v3 * 2);
        --v2;
        v3 -= 3;
      }
      ++v2;
      v3 += 3;
    }
    while ( v2 < this->numIndexes / 3 );
  }
}


// ========================================================================
// ?OptimizeIndexOrder@idTriangles@@QAAXXZ
// EA  : 0x82971CF8
// RVA : 0x00971CF8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::OptimizeIndexOrder(idTriangles *this)
{
  unsigned __int16 *v2; // r29

  v2 = (unsigned __int16 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(760) : TAG_TRIANGLES",
                             size: 2 * this->numIndexes,
                             tag: TAG_TRIANGLES,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  MeshOptimizer(
    indexes: this->indexes,
    numIndexes: this->numIndexes,
    outputIndexes: v2,
    k1: 1.0,
    k2: 0.0,
    k3: 0.80000001);
  idMem::Free(this: &mem, ptr: this->indexes, align: ALIGN_16);
  this->indexes = v2;
}


// ========================================================================
// ?MergeTriangles@idTriangles@@QAAXPBV1@@Z
// EA  : 0x82971D80
// RVA : 0x00971D80
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::MergeTriangles(idTriangles *this, const idTriangles *tri)
{
  int v4; // r11
  int v5; // r10
  int v6; // r6
  unsigned __int16 v7; // r9
  int numIndexes; // r10

  idTriangles::ResizeVerts(this, newNumVerts: this->numVerts + tri->numVerts);
  idTriangles::ResizeIndexes(this, newNumIndexes: tri->numIndexes + this->numIndexes);
  memcpy(Dst: &this->verts[this->numVerts], Src: tri->verts, Size: 32 * tri->numVerts);
  v4 = 0;
  if ( tri->numIndexes > 0 )
  {
    v5 = 0;
    do
    {
      v6 = v4 + this->numIndexes;
      ++v4;
      v7 = tri->indexes[v5++];
      this->indexes[v6] = v7 + HIWORD(this->numVerts);
    }
    while ( v4 < tri->numIndexes );
  }
  numIndexes = this->numIndexes;
  this->numVerts += tri->numVerts;
  this->numIndexes = tri->numIndexes + numIndexes;
}


// ========================================================================
// ??0idTriangles@@QAA@XZ
// EA  : 0x82971E70
// RVA : 0x00971E70
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

idTriangles *__fastcall idTriangles::idTriangles(idTriangles *this)
{
  this->generateNormals = false;
  this->numIndexes = 0;
  this->numVerts = 0;
  this->detailOffset = 0;
  this->allowGpuHosting = true;
  this->vsb.xyzScale.x = 1.0;
  this->vsb.xyzScale.y = 1.0;
  this->vsb.xyzScale.z = 1.0;
  this->vsb.xyzBias.x = 0.0;
  this->vsb.xyzBias.y = 0.0;
  this->vsb.xyzBias.z = 0.0;
  this->vsb.stScale.x = 1.0;
  this->vsb.stScale.y = 1.0;
  this->vsb.stBias.x = 0.0;
  this->vsb.stBias.y = 0.0;
  this->cpuVertexMask = 31;
  this->verts = nullptr;
  this->indexes = nullptr;
  this->vertexMask = 31;
  idIndexBuffer::idIndexBuffer(this: (idIndexBuffer *)&this->vertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->indexBuffer);
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  return this;
}


// ========================================================================
// __unwind$232623
// EA  : 0x82971F70
// RVA : 0x00971F70
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_232623()
{
  int v0; // r12

  idVertexBuffer::~idVertexBuffer(this: (idVertexBuffer *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// ??1idTriangles@@QAA@XZ
// EA  : 0x82971FA8
// RVA : 0x00971FA8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::~idTriangles(idTriangles *this)
{
  idTriangles::FreeData(this);
  idIndexBuffer::~idIndexBuffer(this: &this->indexBuffer);
  idVertexBuffer::~idVertexBuffer(this: &this->vertexBuffer);
}


// ========================================================================
// __unwind$232743
// EA  : 0x82971FF4
// RVA : 0x00971FF4
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_232743()
{
  int v0; // r12

  idVertexBuffer::~idVertexBuffer(this: (idVertexBuffer *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$232744
// EA  : 0x82972020
// RVA : 0x00972020
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_232744()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// ?GPUMemoryUsed@idTriangles@@QBAHXZ
// EA  : 0x82972050
// RVA : 0x00972050
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

int __fastcall idTriangles::GPUMemoryUsed(idTriangles *this)
{
  return (this->indexBuffer.size & 0x7FFFFFFF) + (this->vertexBuffer.size & 0x7FFFFFFF);
}


// ========================================================================
// ?AllocStaticTriSurfVerts@idTriangles@@QBAXH@Z
// EA  : 0x82972068
// RVA : 0x00972068
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::AllocStaticTriSurfVerts(idTriangles *this, int numVerts)
{
  idDrawVert *verts; // r4
  unsigned int cpuVertexMask; // r7
  idDrawVert *v6; // r3

  verts = this->verts;
  if ( verts != nullptr )
    idMem::Free(this: &mem, ptr: verts, align: ALIGN_16);
  if ( ((unsigned int)numVerts <= 0x10000) + (numVerts < 0) == 0 )
    idLib::Error(fmt: "AllocStaticTriSurfVerts: numVerts ( %d ) > %d", numVerts, 0x10000);
  if ( numVerts > 0 )
  {
    cpuVertexMask = this->cpuVertexMask;
    v6 = (idDrawVert *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(218) : TAG_TRIANGLES",
                         size: (((cpuVertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                        + ((cpuVertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                        + ((cpuVertexMask & 0x1000) == 0 ? 0 : 0xC)
                        + ((cpuVertexMask & 1) == 0 ? 0 : 0xC)
                        + ((cpuVertexMask >> 9) & 4)
                        + ((cpuVertexMask >> 2) & 4)
                        + ((cpuVertexMask >> 1) & 4)
                        + ((4 * cpuVertexMask) & 8)
                        + (cpuVertexMask & 4))
                       * numVerts,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: true,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    this->verts = v6;
    if ( v6 != nullptr )
      return;
    idLib::Error(fmt: "AllocStaticTriSurfVerts: failed to allocate memory for vertices (count %d)", numVerts);
  }
  this->verts = nullptr;
}


// ========================================================================
// ?BoundsFromVertScan@idTriangles@@QBA?AVidBounds@@XZ
// EA  : 0x829721A8
// RVA : 0x009721A8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

idTriangles *__fastcall idTriangles::BoundsFromVertScan(idTriangles *this, idBounds *result)
{
  float y; // r3
  idVertexBuffer *p_y; // r3
  int v6; // r10
  float *v7; // r11
  double v9; // fp11
  double z; // fp10
  double x; // fp9
  double v12; // fp8
  double v13; // fp7
  double v25; // fp8

  y = result[3].b[1].y;
  if ( y == 0.0 )
  {
    p_y = (idVertexBuffer *)&result[4].b[0].y;
    if ( fabs(result[4].b[0].y) == 0.0 )
      idLib::Error(fmt: "CalcBounds() - invalid vert and vertexBuffer data\n");
    y = COERCE_FLOAT(idVertexBuffer::MapBuffer(this: p_y, mapType: BM_READ));
  }
  v6 = 0;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( SLODWORD(result[1].b[0].z) > 0 )
  {
    v7 = (float *)LODWORD(y);
    do
    {
      ++v6;
      _FP12 = (float)(this->bounds.b[0].x - *v7);
      v9 = this->bounds.b[0].y;
      z = this->bounds.b[0].z;
      x = this->bounds.b[1].x;
      v12 = this->bounds.b[1].y;
      v13 = this->bounds.b[1].z;
      __asm { fsel      f6, f12, f0, f13 }
      this->bounds.b[0].x = _FP6;
      _FP4 = (float)((float)v9 - v7[1]);
      __asm { fsel      f2, f4, f5, f11 }
      this->bounds.b[0].y = _FP2;
      _FP0 = (float)((float)z - v7[2]);
      __asm { fsel      f13, f0, f1, f10 }
      this->bounds.b[0].z = _FP13;
      _FP11 = (float)(*v7 - (float)x);
      __asm { fsel      f10, f11, f12, f9 }
      this->bounds.b[1].x = _FP10;
      _FP5 = (float)(v7[1] - (float)v12);
      __asm { fsel      f4, f5, f9, f8 }
      this->bounds.b[1].y = _FP4;
      _FP2 = (float)(v7[2] - (float)v13);
      __asm { fsel      f1, f2, f3, f7 }
      this->bounds.b[1].z = _FP1;
      v7 += 8;
    }
    while ( v6 < SLODWORD(result[1].b[0].z) );
  }
  this->bounds.b[0].x = (float)(this->bounds.b[0].x * result[1].b[1].z) + result[2].b[0].z;
  v25 = this->bounds.b[0].z;
  this->bounds.b[0].y = (float)(this->bounds.b[0].y * result[2].b[0].x) + result[2].b[1].x;
  this->bounds.b[0].z = (float)((float)v25 * result[2].b[0].y) + result[2].b[1].y;
  this->bounds.b[1].x = (float)(this->bounds.b[1].x * result[1].b[1].z) + result[2].b[0].z;
  this->bounds.b[1].y = (float)(this->bounds.b[1].y * result[2].b[0].x) + result[2].b[1].x;
  this->bounds.b[1].z = (float)(this->bounds.b[1].z * result[2].b[0].y) + result[2].b[1].y;
  if ( LODWORD(y) != LODWORD(result[3].b[1].y) )
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&result[4].b[0].y);
  return this;
}


// ========================================================================
// ?TriangleVectors@idTriangles@@SAXPBVidDrawVert@@00AAVidVec3@@11@Z
// EA  : 0x82972380
// RVA : 0x00972380
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::TriangleVectors(
        const idDrawVert *a,
        const idDrawVert *b,
        const idDrawVert *c,
        idVec3 *normal,
        idVec3 *tangent,
        idVec3 *biTangent)
{
  double v6; // fp7
  double v7; // fp4
  double v8; // fp6
  double v9; // fp5
  double v10; // fp8
  double v11; // fp9
  double v12; // fp13
  double v13; // fp11
  double v14; // fp12
  double v15; // fp10
  double v16; // fp30
  double v17; // fp1
  double v18; // fp2
  double v19; // fp30
  double y; // fp27
  double v21; // fp28
  double v25; // fp1
  double v26; // fp1
  double v27; // fp1
  double v28; // fp1
  double v29; // fp1
  double v30; // fp31
  double v31; // fp27
  double v32; // fp29
  double v33; // fp28
  double v34; // fp30
  double v36; // fp11
  double v37; // fp7
  double v38; // fp6
  double v39; // fp5
  double v40; // fp2
  double v41; // fp1
  double v42; // fp6
  double v43; // fp12
  double v44; // fp4
  double v45; // fp9
  double v48; // fp7
  double v49; // fp11
  double v50; // fp9
  double v51; // fp13
  double v52; // fp7
  double v53; // fp9
  double v54; // fp6
  double v55; // fp2
  double v58; // fp10
  double v59; // fp3
  double v60; // fp13

  v6 = (float)(b->xyz.x - a->xyz.x);
  v7 = (float)(c->xyz.y - a->xyz.y);
  v8 = (float)(b->xyz.y - a->xyz.y);
  v9 = (float)(c->xyz.z - a->xyz.z);
  v10 = (float)(c->xyz.x - a->xyz.x);
  v11 = (float)(b->xyz.z - a->xyz.z);
  v12 = (float)(b->st.x - a->st.x);
  v13 = (float)(c->st.x - a->st.x);
  v14 = (float)(b->st.y - a->st.y);
  v15 = (float)(c->st.y - a->st.y);
  v16 = (float)((float)(c->xyz.z - a->xyz.z) * (float)(b->xyz.y - a->xyz.y));
  v17 = (float)((float)(c->xyz.x - a->xyz.x) * (float)(b->xyz.z - a->xyz.z));
  v18 = (float)((float)((float)(c->xyz.x - a->xyz.x) * (float)(b->xyz.y - a->xyz.y))
              - (float)((float)(c->xyz.y - a->xyz.y) * (float)(b->xyz.x - a->xyz.x)));
  normal->z = (float)((float)(c->xyz.x - a->xyz.x) * (float)(b->xyz.y - a->xyz.y))
            - (float)((float)(c->xyz.y - a->xyz.y) * (float)(b->xyz.x - a->xyz.x));
  v19 = (float)((float)((float)v7 * (float)v11) - (float)v16);
  normal->x = v19;
  normal->y = (float)((float)v9 * (float)v6) - (float)v17;
  y = normal->y;
  v21 = v18;
  _FP25 = (float)((float)((float)((float)v21 * (float)v21)
                        + (float)((float)((float)v19 * (float)v19) + (float)(normal->y * normal->y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f25, f29, f1 }
  v25 = __frsqrte(_FP1);
  v26 = (float)((float)-(float)((float)((float)((float)v25
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v19 * (float)v19)
                                                                      + (float)(normal->y * normal->y)))
                                                      * (float)0.5))
                                      * (float)v25)
                              - (float)1.5)
              * (float)v25);
  v27 = (float)((float)-(float)((float)((float)((float)v26
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v19 * (float)v19)
                                                                      + (float)(normal->y * normal->y)))
                                                      * (float)0.5))
                                      * (float)v26)
                              - (float)1.5)
              * (float)v26);
  v28 = (float)((float)-(float)((float)((float)((float)v27
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v19 * (float)v19)
                                                                      + (float)(normal->y * normal->y)))
                                                      * (float)0.5))
                                      * (float)v27)
                              - (float)1.5)
              * (float)v27);
  normal->x = (float)v19 * (float)v28;
  normal->y = (float)y * (float)v28;
  normal->z = (float)v18 * (float)v28;
  _FP2 = (float)((float)((float)v15 * (float)v12) - (float)((float)v13 * (float)v14));
  if ( __fabs(_FP2) >= 9.9999997e-21 )
  {
    v29 = (float)((float)v10 * (float)v14);
    v30 = (float)((float)v7 * (float)v14);
    v31 = (float)((float)v13 * (float)v11);
    v32 = (float)((float)v13 * (float)v6);
    v33 = (float)((float)v13 * (float)v8);
    v34 = (float)((float)v9 * (float)v14);
    __asm { fsel      f12, f2, f12, f11 }
    v36 = (float)((float)((float)v15 * (float)v6) - (float)v29);
    tangent->x = (float)((float)((float)v15 * (float)v6) - (float)v29) * (float)_FP12;
    v37 = (float)((float)((float)v15 * (float)v8) - (float)v30);
    tangent->y = (float)((float)((float)v15 * (float)v8) - (float)v30) * (float)_FP12;
    v38 = (float)((float)((float)v15 * (float)v11) - (float)v34);
    v40 = (float)((float)((float)((float)v7 * (float)v12) - (float)v33) * (float)_FP12);
    tangent->z = (float)((float)((float)v15 * (float)v11) - (float)v34) * (float)_FP12;
    v41 = (float)((float)((float)((float)v9 * (float)v12) - (float)v31) * (float)_FP12);
    v39 = (float)((float)((float)((float)v10 * (float)v12) - (float)v32) * (float)_FP12);
    v44 = (float)((float)((float)((float)v15 * (float)v11) - (float)v34) * (float)_FP12);
    v45 = (float)((float)((float)((float)v38 * (float)_FP12) * (float)((float)v38 * (float)_FP12))
                + (float)((float)((float)((float)v36 * (float)_FP12) * (float)((float)v36 * (float)_FP12))
                        + (float)((float)((float)v37 * (float)_FP12) * (float)((float)v37 * (float)_FP12))));
    v42 = (float)((float)v36 * (float)_FP12);
    v43 = (float)((float)v37 * (float)_FP12);
    _FP8 = (float)((float)v45 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f8, f9, f13 }
    v48 = (float)((float)v45 * (float)0.5);
    v49 = __frsqrte(_FP13);
    v50 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49
                                                                                        * (float)((float)v45 * (float)0.5))
                                                                                * (float)v49)
                                                                        - (float)1.5)
                                                        * (float)v49)
                                                * (float)((float)v45 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v49
                                                                                * (float)((float)v45 * (float)0.5))
                                                                        * (float)v49)
                                                                - (float)1.5)
                                                * (float)v49))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)v45 * (float)0.5)) * (float)v49)
                                        - (float)1.5)
                        * (float)v49));
    v51 = (float)((float)-(float)((float)((float)((float)v50 * (float)v48) * (float)v50) - (float)1.5) * (float)v50);
    tangent->y = (float)v43
               * (float)((float)-(float)((float)((float)((float)v50 * (float)v48) * (float)v50) - (float)1.5)
                       * (float)v50);
    v53 = (float)((float)v44
                * (float)((float)-(float)((float)((float)((float)v50 * (float)v48) * (float)v50) - (float)1.5)
                        * (float)v50));
    v52 = v41;
    tangent->z = v53;
    tangent->x = (float)v42 * (float)v51;
    biTangent->x = v39;
    biTangent->y = v40;
    v54 = v40;
    biTangent->z = v41;
    v55 = (float)((float)((float)v41 * (float)v41)
                + (float)((float)((float)v39 * (float)v39) + (float)((float)v40 * (float)v40)));
    _FP1 = (float)((float)v55 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f11, f1, f2, f13 }
    v58 = __frsqrte(_FP11);
    v59 = (float)((float)-(float)((float)((float)((float)v58 * (float)((float)v55 * (float)0.5)) * (float)v58)
                                - (float)1.5)
                * (float)v58);
    v60 = (float)((float)-(float)((float)((float)((float)v59 * (float)((float)v55 * (float)0.5)) * (float)v59)
                                - (float)1.5)
                * (float)v59);
    biTangent->x = (float)v39
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v59
                                                                                                 * (float)((float)v55 * (float)0.5))
                                                                                         * (float)v59)
                                                                                 - (float)1.5)
                                                                 * (float)v59)
                                                         * (float)((float)v55 * (float)0.5))
                                                 * (float)v60)
                                         - (float)1.5)
                         * (float)v60);
    biTangent->y = (float)v54
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v59
                                                                                                 * (float)((float)v55 * (float)0.5))
                                                                                         * (float)v59)
                                                                                 - (float)1.5)
                                                                 * (float)v59)
                                                         * (float)((float)v55 * (float)0.5))
                                                 * (float)v60)
                                         - (float)1.5)
                         * (float)v60);
    biTangent->z = (float)v52
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v59
                                                                                                 * (float)((float)v55 * (float)0.5))
                                                                                         * (float)v59)
                                                                                 - (float)1.5)
                                                                 * (float)v59)
                                                         * (float)((float)v55 * (float)0.5))
                                                 * (float)v60)
                                         - (float)1.5)
                         * (float)v60);
  }
  else
  {
    normal->z = 0.0;
    normal->y = 0.0;
    normal->x = 0.0;
    tangent->z = 0.0;
    tangent->y = 0.0;
    tangent->x = 0.0;
    biTangent->z = 0.0;
    biTangent->y = 0.0;
    biTangent->x = 0.0;
  }
}


// ========================================================================
// ?GetVertSize@idTriangles@@QBAHXZ
// EA  : 0x82972648
// RVA : 0x00972648
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

unsigned int __fastcall idTriangles::GetVertSize(idTriangles *this)
{
  unsigned int vertexMask; // r7

  vertexMask = this->vertexMask;
  return ((vertexMask & 0x1000) == 0 ? 0 : 0xC)
       + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
       + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
       + ((vertexMask & 1) == 0 ? 0 : 0xC)
       + ((vertexMask >> 9) & 4)
       + ((vertexMask >> 2) & 4)
       + ((vertexMask >> 1) & 4)
       + ((4 * vertexMask) & 8)
       + (vertexMask & 4);
}


// ========================================================================
// ?UpdateIndexBuffer@idTriangles@@QAAXXZ
// EA  : 0x829726D0
// RVA : 0x009726D0
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::UpdateIndexBuffer(idTriangles *this)
{
  int numIndexes; // r11
  unsigned __int16 *indexes; // r4
  idIndexBuffer *p_indexBuffer; // r31
  int v5; // r30
  int v6; // r5

  numIndexes = this->numIndexes;
  if ( numIndexes != 0 )
  {
    indexes = this->indexes;
    if ( indexes != nullptr )
    {
      p_indexBuffer = &this->indexBuffer;
      v5 = 2 * numIndexes;
      v6 = this->indexBuffer.size & 0x7FFFFFFF;
      if ( v6 != 0 )
      {
        if ( v5 <= v6 )
        {
          idIndexBuffer::Update(this: &this->indexBuffer, data: indexes, updateSize: 2 * numIndexes);
        }
        else
        {
          idLib::Warning(fmt: "idTriangles::UpdateIndexBuffer: size overrun, %i > %i - resizing the buffer", v5, v6);
          idIndexBuffer::FreeBufferObject(this: p_indexBuffer);
          idIndexBuffer::AllocBufferObject(
            this: p_indexBuffer,
            data: this->indexes,
            allocSize: v5,
            allocUsage: BU_DYNAMIC);
        }
      }
      else
      {
        idIndexBuffer::AllocBufferObject(
          this: &this->indexBuffer,
          data: indexes,
          allocSize: 2 * numIndexes,
          allocUsage: BU_DYNAMIC);
      }
    }
  }
}


// ========================================================================
// ?AddCubeFace@idTriangles@@QAAXABVidVec3@@000@Z
// EA  : 0x82972778
// RVA : 0x00972778
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::AddCubeFace(
        idTriangles *this,
        const idVec3 *v1,
        const idVec3 *v2,
        const idVec3 *v3,
        const idVec3 *v4)
{
  int numIndexes; // r10

  __asm { vspltisw128 v63, 0 }
  _R8 = 16;
  __asm { vor128    v62, v95, v63 }
  _R9 = &this->verts[this->numVerts];
  __asm { vor128    v61, v95, v63 }
  __asm { vor128    v60, v95, v63 }
  __asm { vcmpequw128 v59, v94, v62 }
  __asm
  {
    stvx128   v62, r0, r9
    vcmpequw128 v58, v93, v61
    vcmpequw128 v57, v92, v60
    vsldoi128 v56, v94, v59, 4
    vsldoi128 v55, v93, v58, 4
    vsldoi128 v54, v92, v57, 4
    stvx128   v56, r9, r8
  }
  _R9->xyz = *v1;
  this->verts[this->numVerts].st.x = 0.0;
  this->verts[this->numVerts].st.y = 0.0;
  _R9 = &this->verts[this->numVerts + 1];
  __asm
  {
    stvx128   v61, r0, r9
    stvx128   v55, r9, r8
  }
  _R9->xyz = *v2;
  this->verts[this->numVerts + 1].st.x = 1.0;
  this->verts[this->numVerts + 1].st.y = 0.0;
  _R9 = &this->verts[this->numVerts + 2];
  __asm
  {
    stvx128   v60, r0, r9
    stvx128   v54, r9, r8
  }
  _R4 = 16;
  __asm { vcmpequw128 v53, v95, v63 }
  __asm { vsldoi128 v52, v95, v53, 4 }
  _R9->xyz = *v3;
  this->verts[this->numVerts + 2].st.x = 1.0;
  this->verts[this->numVerts + 2].st.y = 1.0;
  _R9 = &this->verts[this->numVerts + 3];
  __asm
  {
    stvx128   v63, r0, r9
    stvx128   v52, r9, r4
  }
  _R9->xyz = *v4;
  this->verts[this->numVerts + 3].st.x = 0.0;
  this->verts[this->numVerts + 3].st.y = 1.0;
  this->indexes[this->numIndexes] = this->numVerts;
  this->indexes[this->numIndexes + 1] = this->numVerts + 1;
  this->indexes[this->numIndexes + 2] = this->numVerts + 2;
  this->indexes[this->numIndexes + 3] = this->numVerts;
  this->indexes[this->numIndexes + 4] = this->numVerts + 2;
  this->indexes[this->numIndexes + 5] = HIWORD(this->numVerts) + 3;
  numIndexes = this->numIndexes;
  this->numVerts += 4;
  this->numIndexes = numIndexes + 6;
}


// ========================================================================
// ?CreateQuads@idTriangles@@QBAHPAG@Z
// EA  : 0x82972A48
// RVA : 0x00972A48
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

int __fastcall idTriangles::CreateQuads(idTriangles *this, unsigned __int16 *quads)
{
  unsigned __int16 *indexes; // r3
  int numIndexes; // r22
  int v6; // r25
  int v7; // r5
  unsigned __int16 *v8; // r10
  unsigned __int16 *v9; // r9
  unsigned __int16 *v10; // r11
  unsigned __int16 *v11; // r8
  unsigned __int16 *v12; // r6
  unsigned __int16 *v13; // r7
  int v14; // r28
  int v15; // r27
  int v16; // r4
  unsigned __int16 v17; // r4
  unsigned __int16 v18; // r4
  int v19; // r30
  int v20; // r4
  int v21; // r31
  unsigned __int16 v22; // r4
  unsigned __int16 v23; // r4
  unsigned __int16 v24; // r4
  unsigned __int16 v25; // r4
  int v26; // r31
  unsigned __int16 v27; // r4
  unsigned __int16 v28; // r4
  unsigned __int16 v29; // r4
  unsigned __int16 v30; // r4
  unsigned __int16 *v31; // r10
  unsigned __int16 *v32; // r11
  int v33; // r9

  numIndexes = this->numIndexes;
  indexes = this->indexes;
  if ( indexes == nullptr )
    indexes = (unsigned __int16 *)idIndexBuffer::MapBuffer(this: &this->indexBuffer, mapType: BM_READ);
  v6 = 0;
  v7 = 0;
  if ( numIndexes - 3 > 0 )
  {
    v8 = indexes - 2;
    v9 = indexes - 1;
    v10 = quads + 2;
    v11 = indexes - 1;
    v12 = indexes - 2;
    v13 = indexes - 3;
    do
    {
      v14 = v12[6];
      v15 = v8[3];
      if ( v14 == v15 && (v16 = v8[2], v11[6] == v16) )
      {
        *(v10 - 2) = v16;
        v7 += 6;
        v17 = v13[6];
        v13 += 6;
        *(v10 - 1) = v17;
        v12 += 6;
        v11 += 6;
        *v10 = v9[3];
        v9 += 6;
        v18 = v8[3];
        v8 += 6;
      }
      else
      {
        v19 = v9[3];
        if ( v14 == v19 && v11[6] == v15 )
        {
          *(v10 - 2) = v19;
          v7 += 6;
          v12 += 6;
          *(v10 - 1) = v8[2];
          v11 += 6;
          v9 += 6;
          *v10 = v13[6];
          v13 += 6;
          v18 = v8[3];
          v8 += 6;
        }
        else
        {
          v20 = v8[2];
          if ( v14 == v20 && v11[6] == v19 )
          {
            *(v10 - 2) = v20;
            v7 += 6;
            v12 += 6;
            *(v10 - 1) = v8[3];
            v11 += 6;
            v13 += 6;
            v8 += 6;
            *v10 = *v13;
            v18 = v9[3];
            v9 += 6;
          }
          else
          {
            v21 = v11[6];
            if ( v21 == v15 && v13[6] == v20 )
            {
              *(v10 - 2) = v20;
              v7 += 6;
              v13 += 6;
              v11 += 6;
              v22 = v12[6];
              v12 += 6;
              *(v10 - 1) = v22;
              v23 = v9[3];
              v9 += 6;
              *v10 = v23;
              v18 = v8[3];
              v8 += 6;
            }
            else if ( v21 == v19 && v13[6] == v15 )
            {
              *(v10 - 2) = v19;
              v7 += 6;
              v13 += 6;
              v11 += 6;
              v9 += 6;
              *(v10 - 1) = v8[2];
              v24 = v12[6];
              v12 += 6;
              *v10 = v24;
              v18 = v8[3];
              v8 += 6;
            }
            else if ( v21 == v20 && v13[6] == v19 )
            {
              *(v10 - 2) = v20;
              v7 += 6;
              v13 += 6;
              v11 += 6;
              v25 = v8[3];
              v8 += 6;
              *(v10 - 1) = v25;
              v12 += 6;
              *v10 = *v12;
              v18 = v9[3];
              v9 += 6;
            }
            else
            {
              v26 = v13[6];
              if ( v26 == v15 && v14 == v20 )
              {
                *(v10 - 2) = v20;
                v7 += 6;
                v13 += 6;
                v12 += 6;
                v27 = v11[6];
                v11 += 6;
                *(v10 - 1) = v27;
                v28 = v9[3];
                v9 += 6;
                *v10 = v28;
                v18 = v8[3];
                v8 += 6;
              }
              else if ( v26 == v19 && v14 == v15 )
              {
                *(v10 - 2) = v19;
                v7 += 6;
                v13 += 6;
                v12 += 6;
                v9 += 6;
                *(v10 - 1) = v8[2];
                v29 = v11[6];
                v11 += 6;
                *v10 = v29;
                v18 = v8[3];
                v8 += 6;
              }
              else if ( v26 == v20 && v14 == v19 )
              {
                *(v10 - 2) = v20;
                v7 += 6;
                v13 += 6;
                v12 += 6;
                v30 = v8[3];
                v8 += 6;
                *(v10 - 1) = v30;
                v11 += 6;
                *v10 = *v11;
                v18 = v9[3];
                v9 += 6;
              }
              else
              {
                *(v10 - 2) = v20;
                v7 += 3;
                v13 += 3;
                v12 += 3;
                v11 += 3;
                v8 += 3;
                *(v10 - 1) = *v8;
                *v10 = v9[3];
                v9 += 3;
                v18 = *v9;
              }
            }
          }
        }
      }
      v10[1] = v18;
      ++v6;
      v10 += 4;
    }
    while ( v7 < numIndexes - 3 );
  }
  if ( v7 < numIndexes )
  {
    v31 = &indexes[v7];
    v32 = &quads[4 * v6++];
    v33 = v7 + 2;
    *v32 = *v31;
    v32[1] = v31[1];
    v32[2] = indexes[v33];
    v32[3] = indexes[v33];
  }
  if ( indexes != this->indexes )
    idIndexBuffer::UnmapBuffer(this: &this->indexBuffer);
  return v6;
}


// ========================================================================
// ?GetFullSizeDrawVerts@idTriangles@@QBAPBVidDrawVert@@XZ
// EA  : 0x82972DD8
// RVA : 0x00972DD8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
const idDrawVert *__fastcall idTriangles::GetFullSizeDrawVerts(idTriangles *this)
{
  idDrawVert **p_verts; // r28
  const idDrawVert *result; // r3
  int *p_numVerts; // r30
  __int64 v5; // r5
  D3DVertexBuffer *v6; // r3
  int numVerts; // r9
  float *p_Common; // r11
  unsigned int *p_vertexMask; // r6
  int v13; // r9
  unsigned int v14; // r9
  unsigned int v15; // r9
  unsigned int vertexMask; // r5

  p_verts = &this->verts;
  result = this->verts;
  if ( result == nullptr || this->cpuVertexMask != 31 )
  {
    p_numVerts = &this->numVerts;
    idTriangles::AllocStaticTriSurfVerts(this, numVerts: this->numVerts);
    v6 = idVertexBuffer::MapBuffer(this: &this->vertexBuffer, mapType: BM_READ);
    numVerts = this->numVerts;
    _R10 = *p_verts;
    HIDWORD(_R8) = 0;
    p_Common = (float *)&v6->Common;
    if ( numVerts > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      p_vertexMask = &this->vertexMask;
      LODWORD(_R8) = 16;
      __asm
      {
        vcmpequw128 v62, v95, v63
        vsldoi128 v62, v95, v62, 4
      }
      do
      {
        __asm
        {
          stvx128   v63, r0, r10
          stvx128   v62, r10, r8
        }
        if ( (*p_vertexMask & 0x20) != 0 )
        {
          LODWORD(v5) = *(__int16 *)p_Common;
          _R10->xyz.x = (float)(this->vsb.xyzScale.x * (float)v5) + this->vsb.xyzBias.x;
          HIDWORD(v5) = *((unsigned __int16 *)p_Common + 1);
          LODWORD(_R8) = SWORD1(v5);
          _R10->xyz.y = (float)((float)_R8 * this->vsb.xyzScale.y) + this->vsb.xyzBias.y;
          v13 = *((__int16 *)p_Common + 2);
          p_Common += 2;
          _R10->xyz.z = (float)((float)*(__int64 *)((char *)&_R8 - 4) * this->vsb.xyzScale.z) + this->vsb.xyzBias.z;
        }
        else if ( (*p_vertexMask & 1) != 0 )
        {
          _R10->xyz.x = *p_Common;
          _R10->xyz.y = p_Common[1];
          _R10->xyz.z = p_Common[2];
          p_Common += 3;
        }
        v14 = *p_vertexMask;
        if ( (*p_vertexMask & 0x1000) != 0 )
          p_Common += 3;
        if ( (v14 & 0x40) != 0 )
        {
          LODWORD(v5) = *(__int16 *)p_Common;
          _R10->st.x = (float)(this->vsb.stScale.x * (float)v5) + this->vsb.stBias.x;
          HIDWORD(v5) = *((unsigned __int16 *)p_Common++ + 1);
          LODWORD(_R8) = SWORD1(v5);
          _R10->st.y = (float)((float)_R8 * this->vsb.stScale.y) + this->vsb.stBias.y;
        }
        else if ( (v14 & 2) != 0 )
        {
          _R10->st.x = *p_Common;
          _R10->st.y = p_Common[1];
          p_Common += 2;
        }
        v15 = *p_vertexMask;
        if ( (*p_vertexMask & 0x2000) == 0 && (v15 & 0x800) != 0 )
          ++p_Common;
        if ( (v15 & 4) != 0 )
          *(float *)_R10->normal = *p_Common++;
        if ( (*p_vertexMask & 0x10) != 0 )
          *(float *)_R10->tangent = *p_Common++;
        if ( (*p_vertexMask & 8) != 0 )
          *(float *)_R10->color = *p_Common++;
        numVerts = *p_numVerts;
        ++HIDWORD(_R8);
        ++_R10;
        LODWORD(_R8) = 16;
      }
      while ( SHIDWORD(_R8) < *p_numVerts );
    }
    vertexMask = this->vertexMask;
    if ( (char *)p_Common - (char *)v6 != (((vertexMask & 0x1000) == 0 ? 0 : 0xC)
                                         + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                                         + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                                         + ((vertexMask & 1) == 0 ? 0 : 0xC)
                                         + ((vertexMask >> 9) & 4)
                                         + ((vertexMask >> 2) & 4)
                                         + ((vertexMask >> 1) & 4)
                                         + ((4 * vertexMask) & 8)
                                         + (vertexMask & 4))
                                        * numVerts )
      idLib::FatalError(fmt: "idTriangles::GetFullSizeDrawVerts: miscount");
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffer);
    return *p_verts;
  }
  return result;
}


// ========================================================================
// ?DuplicateMirroredVertexes@idTriangles@@QAAXXZ
// EA  : 0x82973158
// RVA : 0x00973158
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::DuplicateMirroredVertexes(idTriangles *this)
{
  unsigned int v1; // r29
  _DWORD *v3; // r28
  int v4; // r5
  int v5; // r11
  unsigned __int16 *indexes; // r10
  idDrawVert *verts; // r9
  int v8; // r4
  int v9; // r3
  float *v10; // r10
  float *v11; // r8
  float *v12; // r9
  BOOL v13; // r8
  int v14; // r10
  int numVerts; // r26
  _DWORD *v16; // r11
  int v17; // r11
  int v18; // r29
  char *v19; // r3
  void *v20; // r4
  int v21; // r7
  int v22; // r8
  char *v23; // r6
  _DWORD *v24; // r5
  idDrawVert *v25; // r9
  idDrawVert *v26; // r11
  int numIndexes; // r11
  int v28; // r6
  int v29; // r3
  unsigned __int16 *v30; // r8
  idDrawVert *v31; // r11
  unsigned __int16 *v32; // r10
  int v33; // r29
  float *v34; // r10
  float *v35; // r9
  float *v36; // r11

  v1 = 8 * this->numVerts;
  v3 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: v1,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  memset(Dst: v3, Val: 0, Size: v1);
  v4 = 0;
  if ( this->numIndexes > 0 )
  {
    v5 = 0;
    do
    {
      indexes = this->indexes;
      verts = this->verts;
      v8 = indexes[v5 + 2];
      v9 = indexes[v5 + 1];
      v10 = (float *)((char *)&verts->xyz.x + __ROL4__(indexes[v5], 5));
      v11 = (float *)((char *)&verts->xyz.x + __ROL4__(v9, 5));
      v12 = (float *)((char *)&verts->xyz.x + __ROL4__(v8, 5));
      v13 = (float)((float)((float)(v12[4] - v10[4]) * (float)(v11[3] - v10[3]))
                  - (float)((float)(v12[3] - v10[3]) * (float)(v11[4] - v10[4]))) < 0.0;
      v4 += 3;
      *((_BYTE *)v3 + __ROL4__(this->indexes[v5], 3) + v13) = 1;
      *((_BYTE *)v3 + __ROL4__(this->indexes[v5 + 1], 3) + v13) = 1;
      *((_BYTE *)v3 + __ROL4__(this->indexes[v5 + 2], 3) + v13) = 1;
      v5 += 3;
    }
    while ( v4 < this->numIndexes );
  }
  v14 = 0;
  numVerts = this->numVerts;
  if ( numVerts > 0 )
  {
    v16 = v3 + 1;
    do
    {
      if ( *((_BYTE *)v16 - 4) != 0 && *((_BYTE *)v16 - 3) != 0 )
        *v16 = numVerts++;
      ++v14;
      v16 += 2;
    }
    while ( v14 < this->numVerts );
  }
  v17 = this->numVerts;
  v18 = numVerts - v17;
  if ( numVerts != v17 )
  {
    idTriangles::ResizeVerts(this, newNumVerts: numVerts);
    v19 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                    size: 4 * v18,
                    tag: TAG_TEMP,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v20 = v19;
    v21 = 0;
    if ( this->numVerts > 0 )
    {
      v22 = 0;
      v23 = v19 - 4;
      v24 = v3 + 1;
      do
      {
        if ( *v24 != 0 )
        {
          v25 = this->verts;
          v26 = &v25[*v24];
          v26->xyz.x = v25[v22].xyz.x;
          v26->xyz.y = v25[v22].xyz.y;
          v26->xyz.z = v25[v22].xyz.z;
          v26->st.x = v25[v22].st.x;
          v26->st.y = v25[v22].st.y;
          v26->normal[0] = v25[v22].normal[0];
          v26->normal[1] = v25[v22].normal[1];
          v26->normal[2] = v25[v22].normal[2];
          v26->normal[3] = v25[v22].normal[3];
          v26->tangent[0] = v25[v22].tangent[0];
          v26->tangent[1] = v25[v22].tangent[1];
          v26->tangent[2] = v25[v22].tangent[2];
          v26->tangent[3] = v25[v22].tangent[3];
          v26->color[0] = v25[v22].color[0];
          v26->color[1] = v25[v22].color[1];
          v26->color[2] = v25[v22].color[2];
          v26->color[3] = v25[v22].color[3];
          v23 += 4;
          *(_DWORD *)v23 = v21;
        }
        ++v21;
        v24 += 2;
        ++v22;
      }
      while ( v21 < this->numVerts );
    }
    numIndexes = this->numIndexes;
    v28 = 0;
    this->numVerts = numVerts;
    if ( numIndexes > 0 )
    {
      v29 = 0;
      do
      {
        v30 = this->indexes;
        if ( *(_DWORD *)((char *)v3 + __ROL4__(v30[v29], 3) + 4) != 0 )
        {
          v31 = this->verts;
          v32 = &v30[3 * (v28 / 3)];
          v33 = v32[1];
          v34 = (float *)((char *)&v31->xyz.x + __ROL4__(*v32, 5));
          v35 = (float *)((char *)&v31->xyz.x + __ROL4__(v33, 5));
          v36 = (float *)((char *)&v31->xyz.x + __ROL4__(v30[3 * (v28 / 3) + 2], 5));
          if ( (float)((float)((float)(v36[4] - v34[4]) * (float)(v35[3] - v34[3]))
                     - (float)((float)(v36[3] - v34[3]) * (float)(v35[4] - v34[4]))) < 0.0 )
            v30[v29] = *(_DWORD *)((char *)v3 + __ROL4__(v30[v29], 3) + 4);
        }
        ++v28;
        ++v29;
      }
      while ( v28 < this->numIndexes );
    }
    this->numVerts = numVerts;
    if ( v20 != nullptr )
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
  }
  if ( v3 != nullptr )
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
}


// ========================================================================
// __unwind$234869_0
// EA  : 0x82973574
// RVA : 0x00973574
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_234869_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 88));
}


// ========================================================================
// ?DeriveTangents@idTriangles@@QAAXXZ
// EA  : 0x829735A8
// RVA : 0x009735A8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::DeriveTangents(idTriangles *this)
{
  idDrawVert **p_verts; // r22
  int *p_numVerts; // r21
  int v5; // r10
  vertexTangents_t *v6; // r25
  float *v7; // r11
  int v8; // r28
  int v9; // r30
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v13; // fp11
  int v14; // r11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  float *v20; // r11
  double v21; // fp1
  double v22; // fp5
  double v23; // fp3
  double v24; // fp1
  double v25; // fp3
  double v26; // fp5
  int v27; // r11
  float *v28; // r11
  int v29; // r11
  float *v30; // r11
  bool *p_generateNormals; // r19
  __int64 v32; // r24
  _DWORD *v33; // r24
  int v34; // r5
  int v35; // r11
  int v36; // r30
  int v37; // r27
  int v38; // r29
  idDrawVert *v39; // r10
  double v40; // fp12
  double v41; // fp0
  int v42; // r3
  int v43; // r28
  int v44; // r11
  float *p_x; // r9
  int indexSize; // r5
  int v47; // r7
  int v48; // r8
  _DWORD *v49; // r7
  float *p_z; // r10
  float *v51; // r11
  double v52; // fp11
  int v53; // r9
  _DWORD *v54; // r8
  float *v55; // r11
  float *v56; // r10
  int v57; // r8
  int v58; // r9
  float *v59; // r11
  unsigned __int8 *v60; // r10
  __int128 v61; // r6
  double v62; // fp3
  double v63; // fp2
  double v64; // fp6
  double v67; // fp8
  double v68; // fp12
  int v69; // r26
  int v70; // r29
  double v79; // fp13
  double v80; // fp10
  unsigned __int8 *v81; // r8
  int v83; // ctr
  double v86; // fp4
  double v87; // fp8
  double v88; // fp6
  double v89; // fp5
  double v90; // fp0
  double v91; // fp9
  double v92; // fp3
  double v93; // fp5
  double v94; // fp1
  double v95; // fp13
  double v96; // fp11
  double v98; // fp6
  double v100; // fp4
  double v101; // fp8
  double v102; // fp6
  double v104; // fp11
  double v105; // fp7
  double v106; // fp9
  __int64 v107; // fp3
  double v108; // fp7
  double v109; // fp8
  double v110; // fp5
  double v111; // fp3
  double v114; // fp4
  double v115; // fp12
  double v116; // fp6
  double v117; // fp12
  double v118; // fp4
  double v119; // fp1
  double v120; // fp6
  double v123; // fp0
  double v124; // fp0
  double v125; // fp8
  double v126; // fp7
  double v127; // fp6
  __int64 v128; // [sp+58h] [-118h] BYREF
  __int64 v129; // [sp+60h] [-110h]
  __int64 v130; // [sp+68h] [-108h]
  __int64 v131; // [sp+70h] [-100h]
  __int64 v132; // [sp+78h] [-F8h]
  idVec3 v133; // [sp+80h] [-F0h] BYREF
  idVec3 v134; // [sp+90h] [-E0h] BYREF
  idVec3 v135; // [sp+9Ch] [-D4h] BYREF
  idHashIndex v136[2]; // [sp+B0h] [-C0h] BYREF

  if ( this->indexes != nullptr )
  {
    p_verts = &this->verts;
    if ( this->verts != nullptr )
    {
      p_numVerts = &this->numVerts;
      idTempArray<vertexTangents_t>::idTempArray<vertexTangents_t>(
        this: (idTempArray<vertexTangents_t> *)&v128,
        num: this->numVerts);
      v5 = 0;
      v6 = (vertexTangents_t *)HIDWORD(v128);
      if ( this->numVerts > 0 )
      {
        v7 = (float *)(HIDWORD(v128) - 12);
        do
        {
          v7[5] = 0.0;
          ++v5;
          v7[4] = 0.0;
          v7[3] = 0.0;
          v7[8] = 0.0;
          v7[7] = 0.0;
          v7[6] = 0.0;
          v7[11] = 0.0;
          v7[10] = 0.0;
          v7 += 9;
          *v7 = 0.0;
        }
        while ( v5 < *p_numVerts );
      }
      v8 = 0;
      if ( this->numIndexes > 0 )
      {
        v9 = 0;
        do
        {
          idTriangles::TriangleVectors(
            a: (idDrawVert *)((char *)*p_verts + __ROL4__(this->indexes[v9], 5)),
            b: (idDrawVert *)((char *)*p_verts + __ROL4__(this->indexes[v9 + 1], 5)),
            c: (idDrawVert *)((char *)*p_verts + __ROL4__(this->indexes[v9 + 2], 5)),
            normal: &v133,
            tangent: &v134,
            biTangent: &v135);
          x = v133.x;
          v8 += 3;
          y = v133.y;
          z = v133.z;
          v13 = v134.x;
          v14 = this->indexes[v9];
          v15 = v134.y;
          v16 = v134.z;
          v17 = v135.x;
          v18 = v135.y;
          v19 = v135.z;
          v20 = &v6->normal.x + v14 + __ROL4__(v14, 3);
          v21 = (float)(v133.y + v20[1]);
          v22 = (float)(v133.z + v20[2]);
          *v20 = *v20 + v133.x;
          v20[2] = v22;
          v20[1] = v21;
          v23 = v20[4];
          v24 = (float)((float)v16 + v20[5]);
          v20[3] = v20[3] + (float)v13;
          v20[4] = (float)v15 + (float)v23;
          v20[5] = v24;
          v25 = v20[6];
          v26 = (float)(v20[8] + (float)v19);
          v20[7] = (float)v18 + v20[7];
          v20[8] = v26;
          v20[6] = (float)v17 + (float)v25;
          v27 = this->indexes[v9 + 1];
          v28 = &v6->normal.x + v27 + __ROL4__(v27, 3);
          *v28 = *v28 + (float)x;
          v28[1] = (float)y + v28[1];
          v28[2] = (float)z + v28[2];
          v28[3] = v28[3] + (float)v13;
          v28[4] = (float)v15 + v28[4];
          v28[5] = (float)v16 + v28[5];
          v28[6] = (float)v17 + v28[6];
          v28[7] = (float)v18 + v28[7];
          v28[8] = v28[8] + (float)v19;
          v29 = this->indexes[v9 + 2];
          v9 += 3;
          v30 = &v6->normal.x + v29 + __ROL4__(v29, 3);
          *v30 = *v30 + (float)x;
          v30[1] = (float)y + v30[1];
          v30[2] = (float)z + v30[2];
          v30[3] = v30[3] + (float)v13;
          v30[4] = (float)v15 + v30[4];
          v30[5] = (float)v16 + v30[5];
          v30[6] = (float)v17 + v30[6];
          v30[7] = (float)v18 + v30[7];
          v30[8] = v30[8] + (float)v19;
        }
        while ( v8 < this->numIndexes );
      }
      p_generateNormals = &this->generateNormals;
      HIDWORD(v32) = &idMath::FLT_SMALLEST_NON_DENORMAL;
      if ( this->generateNormals )
      {
        LODWORD(v129) = *p_numVerts;
        v33 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                size: 4 * v129,
                tag: TAG_TEMP,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        HIDWORD(v129) = v33;
        v34 = *p_numVerts;
        v136[0].memTag = TAG_HASHINDEX;
        idHashIndex::InternalInit(this: v136, initialHashSize: 1024, initialIndexSize: v34);
        v35 = *p_numVerts;
        v36 = 0;
        if ( *p_numVerts > 0 )
        {
          v37 = 0;
          v38 = 0;
          do
          {
            v39 = *p_verts;
            v40 = (*p_verts)[v38].xyz.x;
            v41 = (*p_verts)[v38].xyz.y;
            LODWORD(v130) = (int)v41;
            v42 = (int)v39[v38].xyz.z + (int)v41 + (int)v40;
            v43 = v42 & v136[0].hashMask;
            v44 = v136[0].hash[v136[0].lookupMask & v136[0].hashMask & v42 & v136[0].hashMask];
            if ( v44 == -1 )
            {
LABEL_19:
              v33[v37] = v36;
              if ( v136[0].hash == idHashIndex::INVALID_INDEX )
              {
                indexSize = v136[0].indexSize;
                if ( v36 >= v136[0].indexSize )
                  indexSize = v36 + 1;
                idHashIndex::Allocate(this: v136, newHashSize: v136[0].hashSize, newIndexSize: indexSize);
              }
              else if ( v36 >= v136[0].indexSize )
              {
                idHashIndex::ResizeIndex(this: v136, newIndexSize: v36 + 1);
              }
              v47 = v136[0].hashMask & v43;
              v136[0].indexChain[v37] = v136[0].hash[v47];
              v136[0].hash[v47] = v36;
            }
            else
            {
              while ( 1 )
              {
                p_x = &v39[v44].xyz.x;
                if ( __fabs((float)(*p_x - (float)v40)) < 0.000099999997
                  && __fabs((float)(p_x[1] - (float)v41)) < 0.000099999997
                  && __fabs((float)(p_x[2] - v39[v38].xyz.z)) < 0.000099999997 )
                {
                  break;
                }
                v44 = v136[0].indexChain[v136[0].lookupMask & v44];
                if ( v44 == -1 )
                  goto LABEL_19;
              }
              v33[v37] = v44;
            }
            v35 = *p_numVerts;
            ++v36;
            ++v38;
            ++v37;
          }
          while ( v36 < *p_numVerts );
        }
        v48 = 0;
        if ( v35 > 0 )
        {
          v49 = v33;
          p_z = &v6->normal.z;
          do
          {
            if ( *v49 != v48 )
            {
              v51 = &v6[*v49].normal.x;
              v52 = v51[1];
              *v51 = *v51 + *(p_z - 2);
              v51[1] = (float)v52 + *(p_z - 1);
              v51[2] = *p_z + v51[2];
            }
            v35 = *p_numVerts;
            ++v48;
            p_z += 9;
            ++v49;
          }
          while ( v48 < *p_numVerts );
        }
        v53 = 0;
        if ( v35 > 0 )
        {
          v54 = v33 - 1;
          v55 = &v6[-1].normal.z;
          do
          {
            ++v54;
            ++v53;
            v56 = &v6[*v54].normal.x;
            v55[7] = *v56;
            v55[8] = v56[1];
            v55 += 9;
            *v55 = v56[2];
          }
          while ( v53 < *p_numVerts );
        }
        idHashIndex::Free(this: v136);
        if ( v33 != nullptr )
          idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
      }
      else
      {
        v57 = 0;
        if ( *p_numVerts > 0 )
        {
          v58 = 0;
          v59 = &v6[-1].normal.z;
          do
          {
            ++v57;
            v60 = (unsigned __int8 *)&(*p_verts)[v58++];
            LODWORD(v61) = v60[20];
            DWORD2(v61) = v60[21];
            DWORD1(v61) = v60[22];
            HIDWORD(v61) = v61;
            v128 = v61;
            v129 = *(_QWORD *)((char *)&v61 + 4);
            v130 = *(_QWORD *)&v61;
            v62 = (float)((float)((float)*(__int64 *)((char *)&v61 + 4) * (float)0.0078431377) - (float)1.0);
            v63 = (float)((float)((float)(__int64)v61 * (float)0.0078431377) - (float)1.0);
            v64 = (float)((float)((float)*(__int64 *)&v61 * (float)0.0078431377) - (float)1.0);
            _FP11 = (float)((float)((float)((float)v64 * (float)v64)
                                  + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f9, f11, f12, f0 }
            v67 = __frsqrte(_FP9);
            v68 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67
                                                                                                * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5))
                                                                                        * (float)v67)
                                                                                - (float)1.5)
                                                                * (float)v67)
                                                        * (float)((float)((float)((float)v64 * (float)v64)
                                                                        + (float)((float)((float)v63 * (float)v63)
                                                                                + (float)((float)v62 * (float)v62)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v67
                                                                                        * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62)))
                                                                                                * (float)0.5))
                                                                                * (float)v67)
                                                                        - (float)1.5)
                                                        * (float)v67))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v67
                                                                * (float)((float)((float)((float)v64 * (float)v64)
                                                                                + (float)((float)((float)v63 * (float)v63)
                                                                                        + (float)((float)v62 * (float)v62)))
                                                                        * (float)0.5))
                                                        * (float)v67)
                                                - (float)1.5)
                                * (float)v67));
            v59[7] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5) * (float)v67) * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5) * (float)v67))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67)
                                                                                           - (float)1.5)
                                                                           * (float)v67))
                                                           * (float)((float)((float)((float)v64 * (float)v64)
                                                                           + (float)((float)((float)v63 * (float)v63)
                                                                                   + (float)((float)v62 * (float)v62)))
                                                                   * (float)0.5))
                                                   * (float)v68)
                                           - (float)1.5)
                           * (float)v68)
                   * (float)v63;
            v59[8] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5) * (float)v67) * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5) * (float)v67))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67)
                                                                                           - (float)1.5)
                                                                           * (float)v67))
                                                           * (float)((float)((float)((float)v64 * (float)v64)
                                                                           + (float)((float)((float)v63 * (float)v63)
                                                                                   + (float)((float)v62 * (float)v62)))
                                                                   * (float)0.5))
                                                   * (float)v68)
                                           - (float)1.5)
                           * (float)v68)
                   * (float)v62;
            v59 += 9;
            *v59 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5) * (float)v67)
                                                                                                 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5)) * (float)v67) - (float)1.5)
                                                                                                 * (float)v67))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)((float)v64 * (float)v64) + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) * (float)0.5))
                                                                                                 * (float)v67)
                                                                                         - (float)1.5)
                                                                         * (float)v67))
                                                         * (float)((float)((float)((float)v64 * (float)v64)
                                                                         + (float)((float)((float)v63 * (float)v63)
                                                                                 + (float)((float)v62 * (float)v62)))
                                                                 * (float)0.5))
                                                 * (float)v68)
                                         - (float)1.5)
                         * (float)v68)
                 * (float)v64;
          }
          while ( v57 < *p_numVerts );
        }
      }
      v69 = 0;
      if ( *p_numVerts > 0 )
      {
        __asm { vspltisw128 v63, 0 }
        v70 = 0;
        HIDWORD(_R11) = &v6->normal.y;
        HIDWORD(_R7) = 2;
        _R30 = 1;
        _R27 = 4;
        _R28 = 8;
        _R5 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
        _R4 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        _R3 = &_vmx_3f8000003f8000003f8000003f800000;
        do
        {
          v79 = *(float *)(HIDWORD(_R11) + 4);
          v80 = *(float *)HIDWORD(_R11);
          v81 = (unsigned __int8 *)&(*p_verts)[v70];
          _R9 = (float *)(HIDWORD(_R11) - 4);
          LODWORD(_R7) = HIDWORD(_R11) + 4;
          v83 = 2;
          LODWORD(_R11) = HIDWORD(_R11) + 4;
          _FP7 = (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11))
                               + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4))
                                       + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4))))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f5, f7, f8, f0 }
          v86 = __frsqrte(_FP5);
          v87 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86
                                                                                              * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5))
                                                                                      * (float)v86)
                                                                              - (float)1.5)
                                                              * (float)v86)
                                                      * (float)((float)((float)(*(float *)HIDWORD(_R11)
                                                                              * *(float *)HIDWORD(_R11))
                                                                      + (float)((float)(*(float *)(HIDWORD(_R11) - 4)
                                                                                      * *(float *)(HIDWORD(_R11) - 4))
                                                                              + (float)(*(float *)(HIDWORD(_R11) + 4)
                                                                                      * *(float *)(HIDWORD(_R11) + 4))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v86
                                                                                      * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4))))
                                                                                              * (float)0.5))
                                                                              * (float)v86)
                                                                      - (float)1.5)
                                                      * (float)v86))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v86
                                                              * (float)((float)((float)(*(float *)HIDWORD(_R11)
                                                                                      * *(float *)HIDWORD(_R11))
                                                                              + (float)((float)(*(float *)(HIDWORD(_R11) - 4)
                                                                                              * *(float *)(HIDWORD(_R11) - 4))
                                                                                      + (float)(*(float *)(HIDWORD(_R11) + 4)
                                                                                              * *(float *)(HIDWORD(_R11) + 4))))
                                                                      * (float)0.5))
                                                      * (float)v86)
                                              - (float)1.5)
                              * (float)v86));
          v88 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                              * (float)v86)
                                                                                      * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                      * (float)v86))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v86
                                                                                              * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5))
                                                                                      * (float)v86)
                                                                              - (float)1.5)
                                                              * (float)v86))
                                              * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11))
                                                              + (float)((float)(*(float *)(HIDWORD(_R11) - 4)
                                                                              * *(float *)(HIDWORD(_R11) - 4))
                                                                      + (float)(*(float *)(HIDWORD(_R11) + 4)
                                                                              * *(float *)(HIDWORD(_R11) + 4))))
                                                      * (float)0.5))
                                      * (float)v87)
                              - (float)1.5);
          v89 = (float)((float)v88
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5))
                                                                                              * (float)v86)
                                                                                      - (float)1.5)
                                                                      * (float)v86)
                                                              * (float)((float)((float)(*(float *)HIDWORD(_R11)
                                                                                      * *(float *)HIDWORD(_R11))
                                                                              + (float)((float)(*(float *)(HIDWORD(_R11) - 4)
                                                                                              * *(float *)(HIDWORD(_R11) - 4))
                                                                                      + (float)(*(float *)(HIDWORD(_R11) + 4)
                                                                                              * *(float *)(HIDWORD(_R11) + 4))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v86
                                                                                              * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5))
                                                                                      * (float)v86)
                                                                              - (float)1.5)
                                                              * (float)v86))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v86
                                                                      * (float)((float)((float)(*(float *)HIDWORD(_R11)
                                                                                              * *(float *)HIDWORD(_R11))
                                                                                      + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4))
                                                                                              + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4))))
                                                                              * (float)0.5))
                                                              * (float)v86)
                                                      - (float)1.5)
                                      * (float)v86)));
          *(float *)(HIDWORD(_R11) - 4) = *(float *)(HIDWORD(_R11) - 4)
                                        * (float)((float)v88
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                                * (float)v86)
                                                                                        * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4))))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                        * (float)v86))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v86
                                                                                                * (float)((float)((float)(*(float *)HIDWORD(_R11) * *(float *)HIDWORD(_R11)) + (float)((float)(*(float *)(HIDWORD(_R11) - 4) * *(float *)(HIDWORD(_R11) - 4)) + (float)(*(float *)(HIDWORD(_R11) + 4) * *(float *)(HIDWORD(_R11) + 4)))) * (float)0.5))
                                                                                        * (float)v86)
                                                                                - (float)1.5)
                                                                * (float)v86)));
          *(float *)HIDWORD(_R11) = (float)v89 * (float)v80;
          *(float *)(HIDWORD(_R11) + 4) = (float)v79 * (float)v89;
          do
          {
            v90 = *(float *)(_R11 + 8);
            v91 = *(float *)(_R11 + 12);
            v92 = (float)(*(float *)HIDWORD(_R11)
                        * (float)((float)(*(float *)_R7 * *(float *)(_R11 + 12))
                                + (float)((float)(*_R9 * *(float *)(_R11 + 4))
                                        + (float)(*(float *)HIDWORD(_R11) * *(float *)(_R11 + 8)))));
            v93 = (float)(*(float *)_R7
                        * (float)((float)(*(float *)_R7 * *(float *)(_R11 + 12))
                                + (float)((float)(*_R9 * *(float *)(_R11 + 4))
                                        + (float)(*(float *)HIDWORD(_R11) * *(float *)(_R11 + 8)))));
            v94 = (float)(*(float *)(_R11 + 4)
                        - (float)(*_R9
                                * (float)((float)(*(float *)_R7 * *(float *)(_R11 + 12))
                                        + (float)((float)(*_R9 * *(float *)(_R11 + 4))
                                                + (float)(*(float *)HIDWORD(_R11) * *(float *)(_R11 + 8))))));
            *(float *)(_R11 + 4) = *(float *)(_R11 + 4)
                                 - (float)(*_R9
                                         * (float)((float)(*(float *)_R7 * *(float *)(_R11 + 12))
                                                 + (float)((float)(*_R9 * *(float *)(_R11 + 4))
                                                         + (float)(*(float *)HIDWORD(_R11) * *(float *)(_R11 + 8)))));
            *(float *)(_R11 + 8) = (float)v90 - (float)v92;
            *(float *)(_R11 + 12) = (float)v91 - (float)v93;
            v95 = (float)((float)v91 - (float)v93);
            v96 = *(float *)(_R11 + 8);
            _FP7 = (float)((float)((float)((float)((float)v91 - (float)v93) * (float)((float)v91 - (float)v93))
                                 + (float)((float)((float)v94 * (float)v94)
                                         + (float)(*(float *)(_R11 + 8) * *(float *)(_R11 + 8))))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v98 = (float)((float)((float)((float)((float)v91 - (float)v93) * (float)((float)v91 - (float)v93))
                                + (float)((float)((float)v94 * (float)v94)
                                        + (float)(*(float *)(_R11 + 8) * *(float *)(_R11 + 8))))
                        * (float)0.5);
            __asm { fsel      f5, f7, f8, f0 }
            v100 = __frsqrte(_FP5);
            v101 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v100
                                                                                                 * (float)v98)
                                                                                         * (float)v100)
                                                                                 - (float)1.5)
                                                                 * (float)v100)
                                                         * (float)v98)
                                                 * (float)((float)-(float)((float)((float)((float)v100 * (float)v98)
                                                                                 * (float)v100)
                                                                         - (float)1.5)
                                                         * (float)v100))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v100 * (float)v98) * (float)v100) - (float)1.5)
                                 * (float)v100));
            v102 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v100 * (float)v98) * (float)v100) - (float)1.5)
                                                                                                 * (float)v100)
                                                                                         * (float)v98)
                                                                                 * (float)((float)-(float)((float)((float)((float)v100 * (float)v98) * (float)v100) - (float)1.5)
                                                                                         * (float)v100))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v100
                                                                                                 * (float)v98)
                                                                                         * (float)v100)
                                                                                 - (float)1.5)
                                                                 * (float)v100))
                                                 * (float)v98)
                                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v100 * (float)v98) * (float)v100) - (float)1.5)
                                                                                         * (float)v100)
                                                                                 * (float)v98)
                                                                         * (float)((float)-(float)((float)((float)((float)v100 * (float)v98) * (float)v100)
                                                                                                 - (float)1.5)
                                                                                 * (float)v100))
                                                                 - (float)1.5)
                                                 * (float)((float)-(float)((float)((float)((float)v100 * (float)v98)
                                                                                 * (float)v100)
                                                                         - (float)1.5)
                                                         * (float)v100)))
                                 - (float)1.5);
            *(float *)(_R11 + 4) = (float)((float)v102 * (float)v101) * (float)v94;
            *(float *)(_R11 + 8) = (float)((float)v102 * (float)v101) * (float)v96;
            LODWORD(_R11) = _R11 + 12;
            *(float *)_R11 = (float)((float)v102 * (float)v101) * (float)v95;
            --v83;
          }
          while ( v83 != 0 );
          if ( *p_generateNormals )
          {
            __asm
            {
              vor128    v61, v95, v63
              lvlx128   v60, r0, r9
              lvlx128   v59, r0, r10
            }
            _R11 = v81 + 20;
            __asm
            {
              lvlx128   v58, r0, r7
              lvx128    v62, r0, r3
              vrlimi128 v61, v60, 8, 0
              lvx128    v0, r0, r4
              lvx128    v13, r0, r5
              vrlimi128 v61, v59, 4, 3
              vrlimi128 v61, v58, 2, 2
              vaddfp128 v12, v93, v62
              vmaddfp   v0, v12, v0, v13
              vcfpsxws128 v57, v0, 0
              vpkswss128 v56, v89, v57
              vpkshus128 v0, v88, v56
              stvebx    v0, 0, r11
              stvebx    v0, r11, r30
              stvebx    v0, r11, r6
            }
          }
          LODWORD(_R7) = _R9 + 3;
          __asm
          {
            vor128    v55, v95, v63
            lvx128    v62, r0, r3
          }
          LODWORD(_R11) = v81 + 24;
          __asm { lvx128    v0, r0, r4 }
          __asm { lvx128    v13, r0, r5 }
          __asm
          {
            lvlx128   v54, r0, r7
            vrlimi128 v55, v54, 8, 0
            lvlx128   v53, r7, r27
            lvlx128   v52, r7, r28
            vrlimi128 v55, v53, 4, 3
            vrlimi128 v55, v52, 2, 2
            vaddfp128 v12, v87, v62
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v51, v0, 0
            vpkswss128 v50, v83, v51
            vpkshus128 v0, v82, v50
            stvebx    v0, 0, r11
            stvebx    v0, r11, r30
            stvebx    v0, r11, r6
          }
          LODWORD(_R7) = v81[26];
          v130 = _R7;
          LODWORD(v32) = v81[24];
          v104 = (double)_R7;
          LODWORD(_R11) = v81[25];
          v129 = _R11;
          v128 = v32;
          v105 = (double)_R11;
          LODWORD(_R11) = v81[21];
          v131 = _R11;
          LODWORD(_R7) = v81[22];
          v132 = _R7;
          v106 = (float)((float)((float)v105 * (float)0.0078431377) - (float)1.0);
          v107 = _R7;
          LODWORD(_R7) = v81[20];
          *(_QWORD *)&v133.x = _R7;
          v108 = (float)((float)((float)v32 * (float)0.0078431377) - (float)1.0);
          v109 = (float)((float)((float)v104 * (float)0.0078431377) - (float)1.0);
          v110 = (float)((float)((float)_R11 * (float)0.0078431377) - (float)1.0);
          v111 = (float)((float)((float)v107 * (float)0.0078431377) - (float)1.0);
          _FP11 = (float)((float)((float)((float)v109 * (float)v109)
                                + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106)))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f6, f11, f12, f0 }
          v114 = __frsqrte(_FP6);
          v115 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114
                                                                                               * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5))
                                                                                       * (float)v114)
                                                                               - (float)1.5)
                                                               * (float)v114)
                                                       * (float)((float)((float)((float)v109 * (float)v109)
                                                                       + (float)((float)((float)v108 * (float)v108)
                                                                               + (float)((float)v106 * (float)v106)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v114
                                                                                       * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106)))
                                                                                               * (float)0.5))
                                                                               * (float)v114)
                                                                       - (float)1.5)
                                                       * (float)v114))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v114
                                                               * (float)((float)((float)((float)v109 * (float)v109)
                                                                               + (float)((float)((float)v108
                                                                                               * (float)v108)
                                                                                       + (float)((float)v106
                                                                                               * (float)v106)))
                                                                       * (float)0.5))
                                                       * (float)v114)
                                               - (float)1.5)
                               * (float)v114));
          v116 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114)
                                                                                               * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5)) * (float)v114) - (float)1.5)
                                                                                               * (float)v114))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5))
                                                                                               * (float)v114)
                                                                                       - (float)1.5)
                                                                       * (float)v114))
                                                       * (float)((float)((float)((float)v109 * (float)v109)
                                                                       + (float)((float)((float)v108 * (float)v108)
                                                                               + (float)((float)v106 * (float)v106)))
                                                               * (float)0.5))
                                               * (float)v115)
                                       - (float)1.5)
                       * (float)v115);
          v117 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114) * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v109 * (float)v109) + (float)((float)((float)v108 * (float)v108) + (float)((float)v106 * (float)v106))) * (float)0.5)) * (float)v114)
                                                                                               - (float)1.5)
                                                                               * (float)v114))
                                                               * (float)((float)((float)((float)v109 * (float)v109)
                                                                               + (float)((float)((float)v108
                                                                                               * (float)v108)
                                                                                       + (float)((float)v106
                                                                                               * (float)v106)))
                                                                       * (float)0.5))
                                                       * (float)v115)
                                               - (float)1.5)
                               * (float)v115)
                       * (float)v106);
          v118 = (float)((float)v116 * (float)v109);
          v119 = (float)((float)v116 * (float)((float)((float)v32 * (float)0.0078431377) - (float)1.0));
          LOBYTE(_R11) = 0;
          v120 = (float)((float)((float)_R7 * (float)0.0078431377) - (float)1.0);
          _FP8 = (float)((float)((float)((float)v111 * (float)v111)
                               + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f2, f8, f9, f0 }
          v123 = __frsqrte(_FP2);
          v124 = (float)((float)-(float)((float)((float)((float)v123
                                                       * (float)((float)((float)((float)v111 * (float)v111)
                                                                       + (float)((float)((float)v120 * (float)v120)
                                                                               + (float)((float)v110 * (float)v110)))
                                                               * (float)0.5))
                                               * (float)v123)
                                       - (float)1.5)
                       * (float)v123);
          v125 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v124
                                                                                               * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                       * (float)v124)
                                                                               - (float)1.5)
                                                               * (float)v124)
                                                       * (float)((float)((float)((float)v111 * (float)v111)
                                                                       + (float)((float)((float)v120 * (float)v120)
                                                                               + (float)((float)v110 * (float)v110)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v124
                                                                                       * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110)))
                                                                                               * (float)0.5))
                                                                               * (float)v124)
                                                                       - (float)1.5)
                                                       * (float)v124))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v124
                                                               * (float)((float)((float)((float)v111 * (float)v111)
                                                                               + (float)((float)((float)v120
                                                                                               * (float)v120)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)v124)
                                               - (float)1.5)
                               * (float)v124));
          v126 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v124 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                               * (float)v124)
                                                                                       - (float)1.5)
                                                                       * (float)v124)
                                                               * (float)((float)((float)((float)v111 * (float)v111)
                                                                               + (float)((float)((float)v120
                                                                                               * (float)v120)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v124
                                                                                               * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                       * (float)v124)
                                                                               - (float)1.5)
                                                               * (float)v124))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v124
                                                                       * (float)((float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)((float)v120 * (float)v120)
                                                                                               + (float)((float)v110 * (float)v110)))
                                                                               * (float)0.5))
                                                               * (float)v124)
                                                       - (float)1.5)
                                       * (float)v124))
                       * (float)v120);
          v127 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v124 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                               * (float)v124)
                                                                                       - (float)1.5)
                                                                       * (float)v124)
                                                               * (float)((float)((float)((float)v111 * (float)v111)
                                                                               + (float)((float)((float)v120
                                                                                               * (float)v120)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v124
                                                                                               * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v120 * (float)v120) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                       * (float)v124)
                                                                               - (float)1.5)
                                                               * (float)v124))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v124
                                                                       * (float)((float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)((float)v120 * (float)v120)
                                                                                               + (float)((float)v110 * (float)v110)))
                                                                               * (float)0.5))
                                                               * (float)v124)
                                                       - (float)1.5)
                                       * (float)v124))
                       * (float)v110);
          if ( (float)((float)((float)((float)((float)v127 * (float)v118)
                                     - (float)((float)((float)v125 * (float)v111) * (float)v117))
                             * _R9[6])
                     + (float)((float)(_R9[8]
                                     * (float)((float)((float)v117 * (float)v126) - (float)((float)v127 * (float)v119)))
                             + (float)(_R9[7]
                                     * (float)((float)((float)((float)v125 * (float)v111) * (float)v119)
                                             - (float)((float)v118 * (float)v126))))) >= 0.0 )
            LOBYTE(_R11) = -1;
          ++v69;
          v81[27] = _R11;
          HIDWORD(_R11) += 36;
          ++v70;
        }
        while ( v69 < *p_numVerts );
      }
      if ( v6 != nullptr )
        idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$235221
// EA  : 0x8297404C
// RVA : 0x0097404C
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_235221()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 88));
}


// ========================================================================
// __unwind$235222
// EA  : 0x82974074
// RVA : 0x00974074
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_235222()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$235223
// EA  : 0x8297409C
// RVA : 0x0097409C
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_235223()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 368 + 176));
}


// ========================================================================
// ?OptimizeVertexOrder@idTriangles@@QAAXXZ
// EA  : 0x829740D0
// RVA : 0x009740D0
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::OptimizeVertexOrder(idTriangles *this)
{
  char v2; // r11
  int *buffer; // r29
  int v4; // r11
  int *v5; // r10
  idDrawVert *v6; // r3
  idDrawVert *v7; // r27
  int v8; // r8
  int v9; // r5
  int v10; // r6
  unsigned __int8 *v11; // r10
  int v12; // r11
  int v13; // r9
  idDrawVert *v14; // r11
  idTempArray<int> v15; // [sp+58h] [-38h] BYREF

  if ( this->cpuVertexMask != 31 || (v2 = 1, this->verts == nullptr) )
    v2 = 0;
  if ( v2 != 0 )
  {
    idTempArray<int>::idTempArray<int>(this: &v15, num: this->numVerts);
    buffer = v15.buffer;
    v4 = 0;
    if ( this->numVerts > 0 )
    {
      v5 = v15.buffer - 1;
      do
      {
        ++v4;
        *++v5 = -1;
      }
      while ( v4 < this->numVerts );
    }
    v6 = (idDrawVert *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(776) : TAG_TRIANGLES",
                         size: 32 * this->numVerts,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    v7 = v6;
    v8 = 0;
    v9 = 0;
    if ( this->numIndexes > 0 )
    {
      v10 = 0;
      v11 = &v6[-1].color[3];
      do
      {
        v12 = this->indexes[v10];
        v13 = __ROL4__(v12, 2);
        if ( *(int *)((char *)buffer + v13) == -1 )
        {
          *(int *)((char *)buffer + v13) = v8++;
          v14 = &this->verts[v12];
          *(float *)(v11 + 1) = v14->xyz.x;
          *(float *)(v11 + 5) = v14->xyz.y;
          *(float *)(v11 + 9) = v14->xyz.z;
          *(float *)(v11 + 13) = v14->st.x;
          *(float *)(v11 + 17) = v14->st.y;
          v11[21] = v14->normal[0];
          v11[22] = v14->normal[1];
          v11[23] = v14->normal[2];
          v11[24] = v14->normal[3];
          v11[25] = v14->tangent[0];
          v11[26] = v14->tangent[1];
          v11[27] = v14->tangent[2];
          v11[28] = v14->tangent[3];
          v11[29] = v14->color[0];
          v11[30] = v14->color[1];
          v11[31] = v14->color[2];
          v11 += 32;
          *v11 = v14->color[3];
        }
        ++v9;
        this->indexes[v10++] = *(int *)((char *)buffer + v13);
      }
      while ( v9 < this->numIndexes );
    }
    this->numVerts = v8;
    idMem::Free(this: &mem, ptr: this->verts, align: ALIGN_16);
    this->verts = v7;
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$235869
// EA  : 0x829742B4
// RVA : 0x009742B4
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_235869()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 144 + 88));
}


// ========================================================================
// ?Cleanup@idTriangles@@QAAX_N@Z
// EA  : 0x829742E0
// RVA : 0x009742E0
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::Cleanup(idTriangles *this, bool optimize)
{
  char v4; // [sp+50h] [-30h] BYREF

  idTriangles::RangeCheckIndexes(indexes: this->indexes, numIndexes: this->numIndexes, numVerts: this->numVerts);
  idTriangles::RemoveDegenerate(this);
  idTriangles::DuplicateMirroredVertexes(this);
  if ( optimize )
  {
    idTriangles::OptimizeIndexOrder(this);
    idTriangles::OptimizeVertexOrder(this);
  }
  this->bounds = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v4, result: &this->bounds)->bounds;
  idTriangles::DeriveTangents(this);
}


// ========================================================================
// ?UpdateVertexBuffer@idTriangles@@QAAXXZ
// EA  : 0x829743A0
// RVA : 0x009743A0
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::UpdateVertexBuffer(idTriangles *this)
{
  int numVerts; // r27
  idDrawVert *verts; // r26
  signed int VertSize; // r3
  signed int v5; // r28
  int v6; // r27
  int v7; // r11
  int v8; // r5
  int v9; // r9
  int v10; // r8
  int v11; // r5
  int v12; // r26
  int v13; // r4
  char *buffer; // r28
  idTempArray<char> v15; // [sp+50h] [-40h] BYREF

  numVerts = this->numVerts;
  if ( numVerts != 0 )
  {
    verts = this->verts;
    if ( verts != nullptr )
    {
      VertSize = idTriangles::GetVertSize(this);
      v5 = VertSize;
      if ( VertSize != 0 )
      {
        v6 = numVerts * VertSize;
        v7 = this->vertexBuffer.size & 0x7FFFFFFF;
        if ( v7 != 0 )
        {
          if ( v6 <= v7 )
            goto LABEL_9;
          v11 = this->vertexBuffer.size & 0x7FFFFFFF;
          v12 = v11 / VertSize;
          __twllei(VertSize, 0);
          __twlgei(VertSize & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
          idLib::Warning(fmt: "idTriangles::UpdateVertexBuffer: size overrun, %i > %i - resizing the buffer", v6, v11);
          idVertexBuffer::FreeBufferObject(this: &this->vertexBuffer);
          idVertexBuffer::AllocBufferObject(
            this: &this->vertexBuffer,
            data: this->verts,
            allocSize: v6,
            vertexMask: this->vertexMask,
            allocUsage: BU_DYNAMIC);
          v13 = this->numVerts - v12;
          v9 = 32 * v13;
          v10 = v13 * v5;
        }
        else
        {
          idVertexBuffer::AllocBufferObject(
            this: &this->vertexBuffer,
            data: verts,
            allocSize: v6,
            vertexMask: this->vertexMask,
            allocUsage: BU_DYNAMIC);
          v8 = this->numVerts;
          v9 = 32 * v8;
          v10 = v8 * v5;
        }
        strippedBytes += v10;
        unstrippedBytes += v9;
LABEL_9:
        if ( v5 == VertexSizeFromMask(vertexMask: this->cpuVertexMask) )
        {
          idVertexBuffer::Update(
            this: &this->vertexBuffer,
            data: this->verts,
            updateSize: v6,
            vertexMask: this->vertexMask);
        }
        else
        {
          idTempArray<char>::idTempArray<char>(this: &v15, num: v6);
          buffer = v15.buffer;
          PackToVertexFormat(
            dv: this->verts,
            packed: v15.buffer,
            numVerts: this->numVerts,
            vertexMask: this->vertexMask);
          idVertexBuffer::Update(this: &this->vertexBuffer, data: buffer, updateSize: v6, vertexMask: this->vertexMask);
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$235970
// EA  : 0x82974528
// RVA : 0x00974528
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_235970()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 144 + 80));
}


// ========================================================================
// ?VmtrMapTexCoords@idTriangles@@QAAXHHVidVec4@@@Z
// EA  : 0x82974550
// RVA : 0x00974550
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTriangles::VmtrMapTexCoords(
        idTriangles *this,
        int firstVertex,
        int lastVertex,
        __int64 map,
        int a5,
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
        __int64 a18,
        __int64 a19)
{
  const idDrawVert *FullSizeDrawVerts; // r28
  long double v22; // fp2
  int v23; // r27
  int v24; // r26
  int v25; // r31
  float *v26; // r29
  int v27; // r30
  double v28; // fp31
  double v29; // fp13

  a18 = *(__int64 *)((char *)&map + 4);
  a19 = map;
  if ( lastVertex >= firstVertex )
  {
    FullSizeDrawVerts = idTriangles::GetFullSizeDrawVerts(this);
    v23 = 8 * firstVertex + 3;
    v24 = lastVertex - firstVertex + 1;
    do
    {
      v25 = 0;
      v26 = (float *)&a17;
      do
      {
        v27 = 4 * (v23 + v25);
        v28 = *(float *)((char *)&FullSizeDrawVerts->xyz.x + v27);
        if ( v28 >= 0.0 || v28 <= -0.0099999998 )
        {
          if ( v28 <= 1.0 || v28 >= 1.01 )
          {
            if ( v28 < 0.0 || v28 > 1.0 )
            {
              *(double *)&v22 = *(float *)((char *)&FullSizeDrawVerts->xyz.x + v27);
              v22 = floor(x: v22);
              v28 = (float)((float)v28 - (float)*(double *)&v22);
            }
          }
          else
          {
            v28 = 1.0;
          }
        }
        else
        {
          v28 = 0.0;
        }
        v29 = v26[3];
        ++v25;
        *(float *)((char *)&FullSizeDrawVerts->xyz.x + v27) = (float)(*++v26 * (float)v28) + (float)v29;
      }
      while ( v25 < 2 );
      --v24;
      v23 += 8;
    }
    while ( v24 != 0 );
  }
}


// ========================================================================
// ?TurnIntoQuads@idTriangles@@QAAXXZ
// EA  : 0x82974668
// RVA : 0x00974668
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::TurnIntoQuads(idTriangles *this)
{
  unsigned __int16 *v2; // r25
  int Quads; // r3
  idDrawVert *verts; // r29
  int v5; // r28
  idDrawVert *v6; // r3
  idDrawVert *v7; // r27
  unsigned __int16 *v8; // r9
  int v9; // ctr
  unsigned __int8 *v10; // r11
  float *v11; // r10
  float *v12; // r10
  float *v13; // r10
  float *v14; // r10
  unsigned __int16 *indexes; // r4
  int v16; // ctr
  int v17; // r11

  v2 = (unsigned __int16 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 8 * (this->numIndexes / 3),
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  Quads = idTriangles::CreateQuads(this, quads: v2);
  verts = this->verts;
  v5 = Quads;
  if ( verts == nullptr )
    verts = (idDrawVert *)idVertexBuffer::MapBuffer(this: &this->vertexBuffer, mapType: BM_READ);
  v6 = (idDrawVert *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(1655) : TAG_TRIANGLES",
                       size: v5 << 7,
                       tag: TAG_TRIANGLES,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v7 = v6;
  if ( v5 > 0 )
  {
    v8 = v2 - 1;
    v9 = v5;
    v10 = &v6[-1].color[3];
    do
    {
      v11 = (float *)((char *)&verts->xyz.x + __ROL4__(v8[1], 5));
      *(float *)(v10 + 1) = *v11;
      *(float *)(v10 + 5) = v11[1];
      *(float *)(v10 + 9) = v11[2];
      *(float *)(v10 + 13) = v11[3];
      *(float *)(v10 + 17) = v11[4];
      v10[21] = *((_BYTE *)v11 + 20);
      v10[22] = *((_BYTE *)v11 + 21);
      v10[23] = *((_BYTE *)v11 + 22);
      v10[24] = *((_BYTE *)v11 + 23);
      v10[25] = *((_BYTE *)v11 + 24);
      v10[26] = *((_BYTE *)v11 + 25);
      v10[27] = *((_BYTE *)v11 + 26);
      v10[28] = *((_BYTE *)v11 + 27);
      v10[29] = *((_BYTE *)v11 + 28);
      v10[30] = *((_BYTE *)v11 + 29);
      v10[31] = *((_BYTE *)v11 + 30);
      v10[32] = *((_BYTE *)v11 + 31);
      v12 = (float *)((char *)&verts->xyz.x + __ROL4__(v8[2], 5));
      *(float *)(v10 + 33) = *v12;
      *(float *)(v10 + 37) = v12[1];
      *(float *)(v10 + 41) = v12[2];
      *(float *)(v10 + 45) = v12[3];
      *(float *)(v10 + 49) = v12[4];
      v10[53] = *((_BYTE *)v12 + 20);
      v10[54] = *((_BYTE *)v12 + 21);
      v10[55] = *((_BYTE *)v12 + 22);
      v10[56] = *((_BYTE *)v12 + 23);
      v10[57] = *((_BYTE *)v12 + 24);
      v10[58] = *((_BYTE *)v12 + 25);
      v10[59] = *((_BYTE *)v12 + 26);
      v10[60] = *((_BYTE *)v12 + 27);
      v10[61] = *((_BYTE *)v12 + 28);
      v10[62] = *((_BYTE *)v12 + 29);
      v10[63] = *((_BYTE *)v12 + 30);
      v10[64] = *((_BYTE *)v12 + 31);
      v13 = (float *)((char *)&verts->xyz.x + __ROL4__(v8[3], 5));
      *(float *)(v10 + 65) = *v13;
      *(float *)(v10 + 69) = v13[1];
      *(float *)(v10 + 73) = v13[2];
      *(float *)(v10 + 77) = v13[3];
      *(float *)(v10 + 81) = v13[4];
      v10[85] = *((_BYTE *)v13 + 20);
      v10[86] = *((_BYTE *)v13 + 21);
      v10[87] = *((_BYTE *)v13 + 22);
      v10[88] = *((_BYTE *)v13 + 23);
      v10[89] = *((_BYTE *)v13 + 24);
      v10[90] = *((_BYTE *)v13 + 25);
      v10[91] = *((_BYTE *)v13 + 26);
      v10[92] = *((_BYTE *)v13 + 27);
      v10[93] = *((_BYTE *)v13 + 28);
      v10[94] = *((_BYTE *)v13 + 29);
      v10[95] = *((_BYTE *)v13 + 30);
      v10[96] = *((_BYTE *)v13 + 31);
      v8 += 4;
      v14 = (float *)((char *)&verts->xyz.x + __ROL4__(*v8, 5));
      *(float *)(v10 + 97) = *v14;
      *(float *)(v10 + 101) = v14[1];
      *(float *)(v10 + 105) = v14[2];
      *(float *)(v10 + 109) = v14[3];
      *(float *)(v10 + 113) = v14[4];
      v10[117] = *((_BYTE *)v14 + 20);
      v10[118] = *((_BYTE *)v14 + 21);
      v10[119] = *((_BYTE *)v14 + 22);
      v10[120] = *((_BYTE *)v14 + 23);
      v10[121] = *((_BYTE *)v14 + 24);
      v10[122] = *((_BYTE *)v14 + 25);
      v10[123] = *((_BYTE *)v14 + 26);
      v10[124] = *((_BYTE *)v14 + 27);
      v10[125] = *((_BYTE *)v14 + 28);
      v10[126] = *((_BYTE *)v14 + 29);
      v10[127] = *((_BYTE *)v14 + 30);
      v10 += 128;
      *v10 = *((_BYTE *)v14 + 31);
      --v9;
    }
    while ( v9 != 0 );
  }
  if ( verts == this->verts )
    idMem::Free(this: &mem, ptr: verts, align: ALIGN_16);
  else
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffer);
  this->verts = v7;
  indexes = this->indexes;
  this->numVerts = 4 * v5;
  idMem::Free(this: &mem, ptr: indexes, align: ALIGN_16);
  this->indexes = (unsigned __int16 *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\engine\\renderer\\Triangles.cpp(1673) : TAG_TRIANGLES",
                                        size: 12 * v5,
                                        tag: TAG_TRIANGLES,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  this->numIndexes = 0;
  if ( v5 > 0 )
  {
    v16 = v5;
    v17 = 3;
    do
    {
      this->indexes[this->numIndexes] = v17 - 3;
      this->indexes[this->numIndexes + 1] = v17 - 1;
      this->indexes[this->numIndexes + 2] = v17;
      this->indexes[this->numIndexes + 3] = v17 - 3;
      this->indexes[this->numIndexes + 4] = v17;
      this->indexes[this->numIndexes + 5] = v17 - 2;
      v17 += 4;
      this->numIndexes += 6;
      --v16;
    }
    while ( v16 != 0 );
  }
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
}


// ========================================================================
// __unwind$236298
// EA  : 0x82974B04
// RVA : 0x00974B04
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_236298()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 88));
}


// ========================================================================
// ?WriteToFile@idTriangles@@QBAXPAVidFile@@@Z
// EA  : 0x82974B38
// RVA : 0x00974B38
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::WriteToFile(idTriangles *this, idFile *file)
{
  int *p_numVerts; // r27
  int *p_numIndexes; // r23
  int *p_vertexMask; // r24
  unsigned int vertexMask; // r11
  unsigned int v8; // r29
  idDrawVert *verts; // r3
  size_t num; // r25
  char *buffer; // r26
  D3DVertexBuffer *v12; // r3
  idTempArray<char> v13; // [sp+50h] [-60h] BYREF

  p_numVerts = &this->numVerts;
  p_numIndexes = &this->numIndexes;
  file->Write(this: file, a2: &this->numVerts, a3: 4u);
  file->Write(this: file, a2: &this->numIndexes, a3: 4u);
  p_vertexMask = (int *)&this->vertexMask;
  file->Write(this: file, a2: &this->vertexMask, a3: 4u);
  file->Write(this: file, a2: &this->vsb, a3: 40u);
  vertexMask = this->vertexMask;
  if ( vertexMask == 31 )
  {
    file->Write(this: file, a2: this->verts, a3: 32 * *p_numVerts);
  }
  else
  {
    v13.buffer = (char *)this->vertexMask;
    v8 = (((vertexMask & 0x1000) == 0 ? 0 : 0xC)
        + ((vertexMask >> 9) & 4)
        + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
        + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
        + ((vertexMask >> 2) & 4)
        + ((vertexMask >> 1) & 4)
        + (vertexMask & 4)
        + ((vertexMask & 1) == 0 ? 0 : 0xC)
        + ((4 * vertexMask) & 8))
       * *p_numVerts;
    idTempArray<char>::idTempArray<char>(this: &v13, num: v8);
    verts = this->verts;
    num = v13.num;
    if ( verts != nullptr )
    {
      buffer = v13.buffer;
      if ( this->cpuVertexMask == (*p_vertexMask & 0xFFFFFDFF) )
        memcpy(Dst: v13.buffer, Src: this->verts, Size: v8);
      else
        PackToVertexFormat(dv: verts, packed: v13.buffer, numVerts: *p_numVerts, vertexMask: *p_vertexMask);
    }
    else
    {
      v12 = idVertexBuffer::MapBuffer(this: &this->vertexBuffer, mapType: BM_READ);
      buffer = v13.buffer;
      memcpy(Dst: v13.buffer, Src: v12, Size: num);
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffer);
    }
    if ( num != SwapVertexBuffer(buf: buffer, numVerts: *p_numVerts, vertexMask: *p_vertexMask) )
      idLib::FatalError(fmt: "SwapVertexBuffer() returned mismatched size");
    file->Write(this: file, a2: buffer, a3: num);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
  file->Write(this: file, a2: this->indexes, a3: 2 * *p_numIndexes);
  file->Write(this: file, a2: this, a3: 24u);
  file->Write(this: file, a2: &this->detailOffset, a3: 4u);
}


// ========================================================================
// $LN48_3
// EA  : 0x82974DC8
// RVA : 0x00974DC8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _LN48_3()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 80));
}


// ========================================================================
// ?CreateStandardTriangles@idTriangles@@QBAPAV1@XZ
// EA  : 0x82974DF8
// RVA : 0x00974DF8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

idTriangles *__fastcall idTriangles::CreateStandardTriangles(idTriangles *this)
{
  idTriangles *v2; // r3
  idTriangles *v3; // r29
  char v4; // r11
  D3DVertexBuffer *v5; // r3
  unsigned int vertexMask; // r11
  int numIndexes; // r4
  unsigned __int16 *indexes; // r3
  D3DIndexBuffer *v9; // r3
  unsigned __int16 *v10; // r3
  int v11; // r11
  unsigned __int16 *v12; // r4
  D3DIndexBuffer *v13; // r3
  idList<idDeclVehicleUpgrade const *,5> v15[4]; // [sp+60h] [-40h] BYREF

  v2 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idTriangles::idTriangles(this: v2);
  else
    v3 = nullptr;
  idTriangles::AllocStaticTriSurfVerts(this: v3, numVerts: this->numVerts);
  v3->numVerts = this->numVerts;
  if ( this->cpuVertexMask != 31 || (v4 = 1, this->verts == nullptr) )
    v4 = 0;
  if ( v4 != 0 || !this->allowGpuHosting )
  {
    memcpy(Dst: v3->verts, Src: this->verts, Size: 32 * this->numVerts);
  }
  else
  {
    v5 = idVertexBuffer::MapBuffer(this: &this->vertexBuffer, mapType: BM_READ);
    TransferVerts(
      inputMask: this->vertexMask,
      outputMask: 31,
      vsb: &this->vsb,
      vertexCount: this->numVerts,
      byteSwap: false,
      inputBuffer: v5,
      outputBuffer: v3->verts);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffer);
  }
  vertexMask = this->vertexMask;
  if ( (vertexMask & 0x100) != 0 )
    idLib::FatalError(fmt: "idTriangles::CreateStandardTriangles(): VERTEX_MASK_INDEX_LONG");
  numIndexes = this->numIndexes;
  if ( numIndexes != 0 )
  {
    if ( (vertexMask & 0x200) != 0 )
    {
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v15);
      indexes = this->indexes;
      if ( indexes != nullptr )
      {
        StripIndexesToTriangleIndexes(
          stripIndexes: indexes,
          numStripIndexes: this->numIndexes,
          triIndexes: (idList<idVehicleState *,5> *)v15);
      }
      else
      {
        v9 = idIndexBuffer::MapBuffer(this: &this->indexBuffer, mapType: BM_READ);
        StripIndexesToTriangleIndexes(
          stripIndexes: (const unsigned __int16 *)v9,
          numStripIndexes: this->numIndexes,
          triIndexes: (idList<idVehicleState *,5> *)v15);
        idIndexBuffer::UnmapBuffer(this: &this->indexBuffer);
      }
      idTriangles::AllocStaticTriSurfIndexes(this: v3, numIndexes: v15[0].num);
      v10 = v3->indexes;
      v3->numIndexes = v15[0].num;
      memcpy(Dst: v10, Src: v15[0].list, Size: 2 * v15[0].num);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v15);
    }
    else
    {
      idTriangles::AllocStaticTriSurfIndexes(this: v3, numIndexes);
      v11 = this->numIndexes;
      v3->numIndexes = v11;
      v12 = this->indexes;
      if ( v12 != nullptr )
      {
        memcpy(Dst: v3->indexes, Src: v12, Size: 2 * v11);
      }
      else
      {
        v13 = idIndexBuffer::MapBuffer(this: &this->indexBuffer, mapType: BM_READ);
        memcpy(Dst: v3->indexes, Src: v13, Size: 2 * this->numIndexes);
        idIndexBuffer::UnmapBuffer(this: &this->indexBuffer);
      }
    }
  }
  else
  {
    v3->numIndexes = 0;
  }
  v3->bounds.b[0].x = this->bounds.b[0].x;
  v3->bounds.b[0].y = this->bounds.b[0].y;
  v3->bounds.b[0].z = this->bounds.b[0].z;
  v3->bounds.b[1].x = this->bounds.b[1].x;
  v3->bounds.b[1].y = this->bounds.b[1].y;
  v3->bounds.b[1].z = this->bounds.b[1].z;
  return v3;
}


// ========================================================================
// $LN45
// EA  : 0x8297504C
// RVA : 0x0097504C
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _LN45()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$236657
// EA  : 0x82975078
// RVA : 0x00975078
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_236657()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ?ReadFromFile@idTriangles@@QAAXPAVidFile@@@Z
// EA  : 0x829750A8
// RVA : 0x009750A8
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::ReadFromFile(idTriangles *this, idFile *file)
{
  int *p_numVerts; // r28
  int *p_numIndexes; // r24
  int numVerts; // r4
  unsigned int *p_vertexMask; // r26
  unsigned int v8; // r3
  unsigned int num; // r25
  char *buffer; // r27
  idTempArray<char> v11; // [sp+50h] [-50h] BYREF

  p_numVerts = &this->numVerts;
  p_numIndexes = &this->numIndexes;
  file->Read(this: file, a2: &this->numVerts, a3: 4u);
  file->Read(this: file, a2: &this->numIndexes, a3: 4u);
  numVerts = this->numVerts;
  if ( numVerts < 0 )
    idLib::FatalError(fmt: "idTriangles::ReadFromFile: bad numVerts (surf %d)", numVerts);
  if ( *p_numIndexes < 0 )
    idLib::FatalError(fmt: "idTriangles::ReadFromFile: bad numIndexes (surf %d)", *p_numIndexes);
  p_vertexMask = &this->vertexMask;
  file->Read(this: file, a2: &this->vertexMask, a3: 4u);
  this->cpuVertexMask = this->vertexMask;
  file->Read(this: file, a2: &this->vsb, a3: 40u);
  if ( !this->allowGpuHosting || *p_vertexMask == 31 )
  {
    idTriangles::AllocStaticTriSurfVerts(this, numVerts: *p_numVerts);
    file->Read(this: file, a2: this->verts, a3: 32 * *p_numVerts);
  }
  else
  {
    v8 = VertexSizeFromMask(vertexMask: *p_vertexMask);
    idTempArray<char>::idTempArray<char>(this: &v11, num: *p_numVerts * v8);
    num = v11.num;
    buffer = v11.buffer;
    file->Read(this: file, a2: v11.buffer, a3: v11.num);
    if ( num != SwapVertexBuffer(buf: buffer, numVerts: *p_numVerts, vertexMask: *p_vertexMask) )
      idLib::FatalError(fmt: "SwapVertexBuffer() returned bad size");
    idVertexBuffer::AllocBufferObject(
      this: &this->vertexBuffer,
      data: buffer,
      allocSize: num,
      vertexMask: *p_vertexMask,
      allocUsage: BU_DYNAMIC);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
  idTriangles::AllocStaticTriSurfIndexes(this, numIndexes: *p_numIndexes);
  file->Read(this: file, a2: this->indexes, a3: 2 * *p_numIndexes);
  file->Read(this: file, a2: this, a3: 24u);
  file->Read(this: file, a2: &this->detailOffset, a3: 4u);
}


// ========================================================================
// $LN54_2
// EA  : 0x829752BC
// RVA : 0x009752BC
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _LN54_2()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 80));
}


// ========================================================================
// ?VmtrMapTexCoordsWithSkins@idTriangles@@QAAXAAV?$idList@UsourceSurface_t@@$04@@HPBVidMaterial@@PBVidDeclSkins@@AAV?$idList@UskinRemap_t@@$04@@AAV?$idList@PBVidMaterial@@$04@@@Z
// EA  : 0x82975540
// RVA : 0x00975540
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void __fastcall idTriangles::VmtrMapTexCoordsWithSkins(
        idTriangles *this,
        idList<sourceSurface_t,5> *sourceSurfaces,
        int renderSurface,
        const idMaterial *originalMaterial,
        const idDeclSkins *skins,
        idList<idVehicleState *,5> *skinRemaps,
        idList<idVehicleState *,5> *usedMaterials)
{
  idList<sourceSurface_t,5> *v7; // r17
  int v8; // r15
  idList<skinRemap_t,5> *v10; // r14
  int v12; // r29
  int num; // r8
  int v14; // r30
  sourceSurface_t *v15; // r4
  int v16; // r10
  encounterGroupRole_t *list; // r11
  int v18; // r21
  encounterGroupRole_t v19; // r27
  int v20; // r26
  const idMaterial *v21; // r30
  const idMaterial *v22; // r28
  int v23; // r10
  double v24; // fp10
  double v25; // fp9
  double v26; // fp0
  double z; // fp12
  int v28; // r7
  const char *v29; // r8
  const char *v30; // r6
  double v31; // fp13
  double v32; // fp0
  const skinRemap_t *v33; // r4
  int v34; // r10
  int v35; // r11
  idList<sourceSurface_t,5> *v36; // r27
  int v37; // r20
  idMem *v38; // r30
  skinRemap_t *v39; // r4
  const idMaterial **v40; // r4
  idStr *v41; // r30
  idStr *v42; // r3
  idStr *v43; // r29
  size_t len; // r30
  int v45; // r4
  idMaterial *v46; // r3
  const idMaterial *v47; // r26
  char *data; // r30
  unsigned int v49; // r3
  int v50; // r28
  int v51; // r29
  sourceSurface_t *v52; // r30
  float *MaterialMapping; // r3
  int firstVertex; // r4
  double v55; // fp13
  double v56; // fp12
  double v57; // fp11
  __int64 v58; // r8
  int v59; // r10
  int v60; // r9
  int v61; // r25
  int v62; // r27
  idMaterial **v63; // r11
  char v64; // r29
  int v65; // r28
  int v66; // r30
  idSkin *v67; // r3
  const idMaterial *v68; // r14
  const idMaterial *v69; // r3
  const idMaterial *v70; // r28
  int listStatic; // r11
  idStr *v72; // r3
  const idMaterial *v73; // r30
  char *v74; // r30
  unsigned int v75; // r3
  double v76; // fp0
  double w; // fp13
  float x; // r6
  int v79; // r5
  int v80; // r4
  double v81; // fp12
  int v82; // r10
  int v83; // r11
  int v84; // r11
  int v85; // r27
  int v86; // r28
  sourceSurface_t *v87; // r29
  const char *mtr; // r30
  int v89; // r10
  int v90; // r11
  int v91; // r11
  int v92; // r10
  float v93; // r9
  double v94; // fp0
  __int64 v95; // r8
  int v96; // r6
  double v97; // fp11
  int v98; // [sp+8h] [-238h]
  int v99; // [sp+Ch] [-234h]
  int v100; // [sp+10h] [-230h]
  int v101; // [sp+14h] [-22Ch]
  int v102; // [sp+18h] [-228h]
  int v103; // [sp+1Ch] [-224h]
  int v104; // [sp+20h] [-220h]
  int v105; // [sp+24h] [-21Ch]
  int v106; // [sp+28h] [-218h]
  int v107; // [sp+2Ch] [-214h]
  int v108; // [sp+30h] [-210h]
  __int64 v109; // [sp+38h] [-208h]
  __int64 v110; // [sp+40h] [-200h]
  encounterGroupRole_t v111[4]; // [sp+50h] [-1F0h] BYREF
  idList<enum encounterGroupRole_t,5> v112; // [sp+60h] [-1E0h] BYREF
  idMem *v113; // [sp+70h] [-1D0h]
  idList<enum encounterGroupRole_t,5> v114; // [sp+80h] [-1C0h] BYREF
  const char *p_virtualMapping; // [sp+90h] [-1B0h] BYREF
  idVec2 v116; // [sp+98h] [-1A8h]
  int v117; // [sp+A0h] [-1A0h]
  float v118; // [sp+A4h] [-19Ch]
  float v119; // [sp+A8h] [-198h]
  float v120; // [sp+ACh] [-194h]
  skinRemap_t v121; // [sp+B0h] [-190h] BYREF
  skinRemap_t v122; // [sp+C0h] [-180h] BYREF
  const char *v123; // [sp+CCh] [-174h]
  idStr v124; // [sp+D0h] [-170h] BYREF
  skinRemap_t v125; // [sp+F0h] [-150h] BYREF
  idStr v126; // [sp+100h] [-140h] BYREF
  idStr v127; // [sp+120h] [-120h] BYREF
  idStr v128; // [sp+140h] [-100h] BYREF
  idStr v129; // [sp+160h] [-E0h] BYREF
  idStr v130[6]; // [sp+180h] [-C0h] BYREF

  v7 = sourceSurfaces;
  v8 = renderSurface;
  v10 = (idList<skinRemap_t,5> *)skinRemaps;
  if ( skinRemaps->size < 0 )
    idList<idThread *,58>::Clear(this: skinRemaps);
  v10->num = __CFADD__(-v10->size, v10->size ^ 0x80000000) ? 0 : v10->size;
  if ( usedMaterials->size < 0 )
    idList<idThread *,58>::Clear(this: usedMaterials);
  usedMaterials->num = __CFADD__(-usedMaterials->size, usedMaterials->size ^ 0x80000000) ? 0 : usedMaterials->size;
  if ( skins != nullptr )
  {
    memset(&v114, 0, 14);
    *(_WORD *)&v114.memTag = 11520;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v114);
    v12 = 0;
    if ( v7->num <= 0 )
    {
      num = v114.num;
    }
    else
    {
      num = v114.num;
      v14 = 0;
      do
      {
        v15 = &v7->list[v14];
        if ( v15->renderSurface == v8 )
        {
          v16 = 0;
          if ( num <= 0 )
            goto LABEL_15;
          list = v114.list;
          while ( (const idMaterial *)*list != v15->mtr )
          {
            ++v16;
            ++list;
            if ( v16 >= num )
              goto LABEL_15;
          }
          if ( v16 < 0 )
          {
LABEL_15:
            idList<idAnimWebBlendTree *,5>::Append(this: &v114, obj: (const encounterGroupRole_t *)v15);
            num = v114.num;
          }
        }
        ++v12;
        ++v14;
      }
      while ( v12 < v7->num );
    }
    v113 = &mem;
    if ( num == 1 )
    {
      v18 = 0;
      v19 = *v114.list;
      if ( skins->skins.num > 0 )
      {
        v20 = 0;
        do
        {
          v21 = idSkin::Remap(this: &skins->skins.list[v20], mtr: (const idMaterial *)v19);
          v111[0] = (encounterGroupRole_t)v21;
          v22 = idMaterial::CompatibleGenericMaterial(this: v21);
          idMaterial::CompatibleGenericMaterial(this: (idMaterial *)v19);
          v23 = *(_DWORD *)(v19 + 260);
          v24 = *(float *)(v19 + 248);
          p_virtualMapping = (const char *)&v21->virtualMapping;
          v25 = *(float *)(v19 + 252);
          p_virtualMapping = (const char *)&v21->virtualMapping;
          v26 = *(float *)(v19 + 256);
          z = v21->virtualMapping.z;
          v28 = (*(_DWORD *)(v19 + 256) | v23 | *(_DWORD *)(v19 + 252) | *(_DWORD *)(v19 + 248)) & 0x7FFFFFFF;
          if ( (v28 != 0) == (((LODWORD(v21->virtualMapping.w)
                              | LODWORD(v21->virtualMapping.z)
                              | LODWORD(v21->virtualMapping.y)
                              | LODWORD(v21->virtualMapping.x))
                             & 0x7FFFFFFF) != 0) )
          {
            if ( v28 != 0 )
            {
              v31 = (float)(v21->virtualMapping.w - *(float *)(v19 + 260));
              v116.y = v21->virtualMapping.w - *(float *)(v19 + 260);
              v32 = (float)((float)z - (float)v26);
              v116.x = v32;
              if ( v22 != nullptr )
              {
                v33 = &v122;
                v122.mtr = v22;
                v122.texOffset = v116;
              }
              else
              {
                if ( v24 > 0.00000011920929 )
                  v116.x = (float)v32 / (float)v24;
                if ( v25 > 0.00000011920929 )
                  v116.y = (float)v31 / (float)v25;
                v33 = &v122;
                v122.mtr = v21;
                v122.texOffset = v116;
              }
            }
            else
            {
              v121.mtr = v22;
              if ( v22 == nullptr )
                v121.mtr = v21;
              v33 = &v121;
              v121.texOffset = vec2_origin;
            }
            idList<skinRemap_t,5>::Append(this: v10, obj: v33);
            v34 = 0;
            if ( usedMaterials->num <= 0 )
              goto LABEL_45;
            v35 = 0;
            while ( (const idMaterial *)usedMaterials->list[v35] != v21 )
            {
              ++v34;
              ++v35;
              if ( v34 >= usedMaterials->num )
                goto LABEL_45;
            }
            if ( v34 < 0 )
LABEL_45:
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)usedMaterials,
                obj: v111);
          }
          else
          {
            v29 = &byte_8200D768;
            if ( ((LODWORD(v21->virtualMapping.w)
                 | LODWORD(v21->virtualMapping.z)
                 | LODWORD(v21->virtualMapping.y)
                 | LODWORD(v21->virtualMapping.x))
                & 0x7FFFFFFF) == 0 )
              v29 = "non-";
            v30 = &byte_8200D768;
            if ( v28 == 0 )
              v30 = "non-";
            idLib::Warning(
              fmt: "skin %s on model %s tries to remap the %svirtual material %s to the %svirtual material %s",
              skins->skins.list[v20].name.str,
              skins->name.str,
              v30,
              *(const char **)(v19 + 8),
              v29,
              v21->name.str);
          }
          ++v18;
          ++v20;
        }
        while ( v18 < skins->skins.num );
      }
    }
    else
    {
      v36 = sourceSurfaces;
      v37 = 0;
      v123 = "amount <= GetAlloced()";
      p_virtualMapping = "rebuilding all packed materials";
      do
      {
        v38 = v113;
        if ( v10->size < 0 )
        {
          if ( v10->listStatic == 0 || v10->listStatic == 2 )
          {
            v39 = v10->list;
            if ( v10->list != nullptr )
            {
              v111[0] = (encounterGroupRole_t)v10->list;
              idMem::Free(this: v113, ptr: v39, align: ALIGN_16);
            }
            v10->list = nullptr;
            v10->size = 0;
          }
          v10->num = 0;
        }
        v10->num = __CFADD__(-v10->size, v10->size ^ 0x80000000) ? 0 : v10->size;
        if ( usedMaterials->size < 0 )
        {
          if ( usedMaterials->listStatic == 0 || usedMaterials->listStatic == 2 )
          {
            v40 = (const idMaterial **)usedMaterials->list;
            if ( usedMaterials->list != nullptr )
            {
              v111[0] = (encounterGroupRole_t)usedMaterials->list;
              idMem::Free(this: v38, ptr: v40, align: ALIGN_16);
            }
            usedMaterials->list = nullptr;
            usedMaterials->size = 0;
          }
          usedMaterials->num = 0;
        }
        usedMaterials->num = __CFADD__(-usedMaterials->size, usedMaterials->size ^ 0x80000000) ? 0 : usedMaterials->size;
        idStr::idStr(this: &v124, text: skins->name.str);
        idStr::StripFileExtension(this: &v124);
        v41 = idStr::idStr(this: &v128, i: renderSurface);
        v42 = operator+(result: &v129, a: &v124, b: "_");
        v43 = operator+(result: &v127, a: v42, b: v41);
        len = v43->len;
        v45 = v43->len + 1;
        if ( v124.allocedAndFlag >= 0 )
        {
          if ( v45 > (v124.allocedAndFlag & 0x7FFFFFFF) )
            idStr::ReAllocate(this: &v124, amount: v45, keepold: false);
        }
        else if ( v45 > (v124.allocedAndFlag & 0x7FFFFFFF)
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: v123,
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v124.data, Src: v43->data, Size: len);
        v124.data[len] = 0;
        v124.len = len;
        idStr::FreeData(this: &v127);
        idStr::FreeData(this: &v129);
        idStr::FreeData(this: &v128);
        if ( v37 != 0
          || (v124.data != nullptr
            ? (v46 = (idMaterial *)idDeclInfo::FindWithInheritance(
                                     this: &idMaterial::resourceList,
                                     name: v124.data,
                                     makeDefault: false))
            : (v46 = nullptr),
              (v47 = v46, v46 == nullptr)
           || (unsigned __int8)idMaterial::MaterialMappingNeedsReload(this: v46, skins) != 0) )
        {
          data = v124.data;
          v49 = skins->GetDeclTimestamp(this: skins);
          v47 = idMaterial::PackMaterials(
                  name: data,
                  materials: (const idList<idMaterial const *,5> *)&v114,
                  skinFileTimeStamp: v49);
        }
        v50 = 0;
        if ( v36->num > 0 )
        {
          v51 = 0;
          do
          {
            v52 = &v36->list[v51];
            if ( v52->renderSurface == renderSurface )
            {
              MaterialMapping = idMaterial::GetMaterialMapping(this: v47, mtr: v52->mtr);
              firstVertex = v52->firstVertex;
              v55 = MaterialMapping[2];
              v56 = MaterialMapping[1];
              v57 = *MaterialMapping;
              v120 = MaterialMapping[3];
              v119 = v55;
              *(float *)&v58 = v120;
              *(float *)&v117 = v57;
              v118 = v56;
              idTriangles::VmtrMapTexCoords(
                this,
                firstVertex,
                lastVertex: v117,
                map: v58,
                a5: v60,
                a6: v59,
                a7: v98,
                a8: v99,
                a9: v100,
                a10: v101,
                a11: v102,
                a12: v103,
                a13: v104,
                a14: v105,
                a15: v106,
                a16: v107,
                a17: v108,
                a18: v109,
                a19: v110);
              v52->mtr = v47;
            }
            ++v50;
            ++v51;
          }
          while ( v50 < v36->num );
        }
        v61 = 0;
        if ( skins->skins.num > 0 )
        {
          v62 = 0;
          while ( 1 )
          {
            v63 = nullptr;
            *(_WORD *)&v112.memTag = 11520;
            v64 = 0;
            memset(&v112, 0, 14);
            v65 = 0;
            if ( v114.num > 0 )
            {
              v66 = 0;
              do
              {
                v67 = &skins->skins.list[v62];
                v111[0] = (encounterGroupRole_t)&v114.list[v66];
                v111[0] = (encounterGroupRole_t)idSkin::Remap(this: v67, mtr: (const idMaterial *)v114.list[v66]);
                idList<idAnimWebBlendTree *,5>::Append(this: &v112, obj: v111);
                v111[0] = (encounterGroupRole_t)&v112.list[v66];
                v64 |= v114.list[v66] != v112.list[v66];
                v68 = idMaterial::CompatibleGenericMaterial(this: (idMaterial *)v112.list[v66]);
                if ( v68 != idMaterial::CompatibleGenericMaterial(this: *(idMaterial **)v112.list) )
                  idLib::Warning(
                    fmt: "skin %s on model %s tries to remap generic material %s to the non-generic material %s",
                    skins->skins.list[v62].name.str,
                    skins->name.str,
                    *(const char **)(v114.list[v66] + 8),
                    *(const char **)(v112.list[v66] + 8));
                ++v65;
                ++v66;
              }
              while ( v65 < v114.num );
              v63 = (idMaterial **)v112.list;
              v10 = (idList<skinRemap_t,5> *)skinRemaps;
            }
            v69 = idMaterial::CompatibleGenericMaterial(this: *v63);
            v70 = v69;
            if ( v69 == nullptr )
            {
              idLib::Error(
                fmt: "skin %s on model %s tries to remap generic materials on surface %d to non-generic materials",
                skins->skins.list[v61].name.str,
                skins->name.str,
                renderSurface);
              goto _LN789;
            }
            if ( v64 != 0 )
            {
              v72 = operator+(result: v130, a: &v124, b: "_");
              operator+(result: &v126, a: v72, b: (char *)skins->skins.list[v62].name.str);
              idStr::FreeData(this: v130);
              if ( v37 != 0
                || (v126.data != nullptr
                  ? (v73 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                 this: &idMaterial::resourceList,
                                                 name: v126.data,
                                                 makeDefault: false))
                  : (v73 = nullptr),
                    (v111[0] = (encounterGroupRole_t)v73, v73 == nullptr)
                 || (unsigned __int8)idMaterial::MaterialMappingNeedsReload(this: v73, skins) != 0
                 || (unsigned __int8)idMaterial::MaterialMappingsAreCompatible(this: v73, mtr: v47) == 0) )
              {
                v74 = v126.data;
                v75 = skins->GetDeclTimestamp(this: skins);
                v73 = idMaterial::PackMaterials(
                        name: v74,
                        materials: (const idList<idMaterial const *,5> *)&v112,
                        skinFileTimeStamp: v75);
                v111[0] = (encounterGroupRole_t)v73;
                if ( (unsigned __int8)idMaterial::MaterialMappingsAreCompatible(this: v73, mtr: v47) == 0 )
                {
                  if ( v37 == 0 )
                  {
                    idLib::Warning(fmt: p_virtualMapping);
                    idStr::FreeData(this: &v126);
                    if ( v112.listStatic == 0 || v112.listStatic == 2 )
                    {
                      if ( v112.list != nullptr )
                        idMem::Free(this: v113, ptr: v112.list, align: ALIGN_16);
                      v112.list = nullptr;
                      v112.size = 0;
                    }
                    v112.num = 0;
LABEL_125:
                    v36 = sourceSurfaces;
                    break;
                  }
_LN789:
                  idLib::Error(
                    fmt: "skin %s on model %s uses different texture sizes",
                    skins->skins.list[v61].name.str,
                    skins->name.str);
_LN790:
                  idStr::FreeData(this: &v124);
                  goto LABEL_132;
                }
              }
              v76 = v47->virtualMapping.z;
              w = v47->virtualMapping.w;
              x = v73->virtualMapping.x;
              v79 = LODWORD(v73->virtualMapping.w) | LODWORD(v73->virtualMapping.z) | LODWORD(v73->virtualMapping.y);
              v80 = (LODWORD(v47->virtualMapping.y)
                   | LODWORD(v47->virtualMapping.w)
                   | LODWORD(v47->virtualMapping.z)
                   | LODWORD(v47->virtualMapping.x))
                  & 0x7FFFFFFF;
              LODWORD(v116.x) = &v73->virtualMapping;
              v81 = v73->virtualMapping.z;
              if ( ((v79 | LODWORD(x)) & 0x7FFFFFFF) != 0 && v80 != 0 )
              {
                v121.texOffset.y = v73->virtualMapping.w - (float)w;
                v121.texOffset.x = (float)v81 - (float)v76;
                v121.mtr = v70;
                idList<skinRemap_t,5>::Append(this: v10, obj: &v121);
                v82 = 0;
                if ( usedMaterials->num <= 0 )
                  goto LABEL_108;
                v83 = 0;
                while ( (const idMaterial *)usedMaterials->list[v83] != v73 )
                {
                  ++v82;
                  ++v83;
                  if ( v82 >= usedMaterials->num )
                    goto LABEL_108;
                }
                if ( v82 < 0 )
LABEL_108:
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)usedMaterials,
                    obj: v111);
                idStr::FreeData(this: &v126);
                listStatic = v112.listStatic;
              }
              else
              {
                v125.mtr = v70;
                v125.texOffset = vec2_origin;
                idList<skinRemap_t,5>::Append(this: v10, obj: &v125);
                idLib::Warning(
                  fmt: "Failed to remap skin %s on model %s, vmtr for material %s is NULL",
                  skins->skins.list[v62].name.str,
                  skins->name.str,
                  v73->name.str);
                idStr::FreeData(this: &v126);
                listStatic = v112.listStatic;
              }
            }
            else
            {
              v122.mtr = v69;
              v122.texOffset = vec2_origin;
              idList<skinRemap_t,5>::Append(this: v10, obj: &v122);
              listStatic = v112.listStatic;
            }
            if ( listStatic == 0 || listStatic == 2 )
            {
              if ( v112.list != nullptr )
                idMem::Free(this: v113, ptr: v112.list, align: ALIGN_16);
              v112.list = nullptr;
              v112.size = 0;
            }
            v84 = skins->skins.num;
            ++v61;
            v112.num = 0;
            ++v62;
            if ( v61 >= v84 )
              goto LABEL_125;
          }
        }
        if ( v61 >= skins->skins.num )
          goto _LN790;
        idStr::FreeData(this: &v124);
        ++v37;
      }
      while ( v37 < 2 );
LABEL_132:
      v7 = sourceSurfaces;
      v8 = renderSurface;
    }
    if ( v114.listStatic == 0 || v114.listStatic == 2 )
    {
      if ( v114.list != nullptr )
        idMem::Free(this: v113, ptr: v114.list, align: ALIGN_16);
      v114.list = nullptr;
      v114.size = 0;
    }
    v114.num = 0;
  }
  v85 = 0;
  if ( v7->num > 0 )
  {
    v86 = 0;
    do
    {
      v87 = &v7->list[v86];
      if ( v87->renderSurface == v8 )
      {
        mtr = (const char *)v87->mtr;
        v89 = 0;
        v90 = usedMaterials->num;
        p_virtualMapping = (const char *)v87->mtr;
        if ( v90 <= 0 )
          goto LABEL_148;
        v91 = 0;
        while ( (const char *)usedMaterials->list[v91] != mtr )
        {
          ++v89;
          ++v91;
          if ( v89 >= usedMaterials->num )
            goto LABEL_148;
        }
        if ( v89 < 0 )
LABEL_148:
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)usedMaterials,
            obj: (const encounterGroupRole_t *)&p_virtualMapping);
        if ( mtr != (const char *)originalMaterial )
        {
          v92 = *((_DWORD *)mtr + 65);
          v93 = *((float *)mtr + 64);
          v94 = *((float *)mtr + 62);
          LODWORD(v95) = *((_DWORD *)mtr + 63);
          v96 = *((_DWORD *)mtr + 62);
          LODWORD(v116.x) = mtr + 248;
          v97 = *((float *)mtr + 65);
          *(float *)&v117 = v94;
          LODWORD(v116.x) = mtr + 248;
          v118 = *((float *)&v95 + 1);
          v119 = v93;
          v120 = v97;
          if ( ((v92 | LODWORD(v93) | (unsigned int)v95 | v96) & 0x7FFFFFFF) != 0 )
          {
            if ( v87->lastVertex < this->numVerts )
            {
              *(float *)&v95 = v120;
              idTriangles::VmtrMapTexCoords(
                this,
                firstVertex: v87->firstVertex,
                lastVertex: v117,
                map: v95,
                a5: SLODWORD(v93),
                a6: v92,
                a7: v98,
                a8: v99,
                a9: v100,
                a10: v101,
                a11: v102,
                a12: v103,
                a13: v104,
                a14: v105,
                a15: v106,
                a16: v107,
                a17: v108,
                a18: v109,
                a19: v110);
            }
            else
            {
              idLib::Warning(
                fmt: "idTriangles::VmtrMapTexCoords: remap failed due to wrong number of vertices -- consider deleting your generated");
            }
          }
        }
      }
      ++v85;
      ++v86;
    }
    while ( v85 < v7->num );
  }
}


// ========================================================================
// $LN735
// EA  : 0x829761BC
// RVA : 0x009761BC
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _LN735()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$237042
// EA  : 0x829761E4
// RVA : 0x009761E4
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 208));
}


// ========================================================================
// __unwind$237043
// EA  : 0x8297620C
// RVA : 0x0097620C
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237043()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 320));
}


// ========================================================================
// __unwind$237044
// EA  : 0x82976234
// RVA : 0x00976234
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 352));
}


// ========================================================================
// __unwind$237045
// EA  : 0x8297625C
// RVA : 0x0097625C
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237045()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 288));
}


// ========================================================================
// __unwind$237046
// EA  : 0x82976284
// RVA : 0x00976284
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237046()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 96));
}


// ========================================================================
// __unwind$237047
// EA  : 0x829762AC
// RVA : 0x009762AC
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237047()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 384));
}


// ========================================================================
// __unwind$237048
// EA  : 0x829762D4
// RVA : 0x009762D4
// PDB : w:\tech5\engine\renderer\triangles.cpp
// ========================================================================

void _unwind_237048()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 256));
}

