
// ========================================================================
// itoa
// EA  : 0x82843C20
// RVA : 0x00843C20
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

char *__fastcall itoa(char *a, int i)
{
  int v2; // r11

  v2 = 0;
  a[3] = 0;
  a[2] = 0;
  a[1] = 0;
  *a = 0;
  if ( i >= 100 )
  {
    v2 = 1;
    *a = i % 1000 / 100 + 48;
  }
  if ( i >= 10 )
    a[v2++] = i % 100 / 10 + 48;
  a[v2] = i % 10 + 48;
  return a;
}


// ========================================================================
// ?CompressWeightsToByte@@YAEQBE@Z
// EA  : 0x82843CE0
// RVA : 0x00843CE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

int __fastcall CompressWeightsToByte(const unsigned __int8 *weights, int a2, int a3, __int64 a4)
{
  __int64 v4; // r8
  char v7; // r9
  char v10; // r10
  int v13; // r11

  LODWORD(v4) = weights[1];
  HIDWORD(v4) = &unk_821C0000;
  _FP9 = (float)((float)15.0 - (float)((float)((float)v4 * (float)0.11764706) + (float)0.5));
  __asm { fsel      f8, f9, f10, f0 }
  if ( (int)_FP8 >= 0 )
  {
    v7 = -1;
    if ( (int)_FP8 <= 255 )
      v7 = (int)_FP8;
  }
  else
  {
    v7 = 0;
  }
  LODWORD(a4) = weights[2];
  _FP8 = (float)((float)3.0 - (float)((float)((float)a4 * (float)0.035294119) + (float)0.5));
  __asm { fsel      f7, f8, f9, f0 }
  if ( (int)_FP7 >= 0 )
  {
    v10 = -1;
    if ( (int)_FP7 <= 255 )
      v10 = (int)_FP7;
  }
  else
  {
    v10 = 0;
  }
  LODWORD(a4) = weights[3];
  _FP8 = (float)((float)3.0 - (float)((float)((float)a4 * (float)0.047058824) + (float)0.5));
  __asm { fsel      f7, f8, f9, f0 }
  v13 = (int)_FP7;
  if ( (int)_FP7 >= 0 )
  {
    if ( v13 > 255 )
      LOBYTE(v13) = -1;
  }
  else
  {
    LOBYTE(v13) = 0;
  }
  return (unsigned __int8)(4 * ((4 * v7) | v10)) | (unsigned __int8)v13;
}


// ========================================================================
// ?testByteWeights_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82843E18
// RVA : 0x00843E18
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall testByteWeights_f(const idCmdArgs *args)
{
  int i; // r31
  int v2; // r4
  int v3; // r10
  int v4; // r9
  unsigned __int8 v5; // r11
  __int64 v6; // r8
  int v7; // r5
  int v8; // r4
  int v9; // r4
  unsigned __int8 v10[2]; // [sp+50h] [-50h] BYREF
  unsigned __int8 v11; // [sp+52h] [-4Eh]
  char v12; // [sp+53h] [-4Dh]

  for ( i = 0; i < 256; ++i )
  {
    v2 = ((i << 8) & 0x300) - (i & 3);
    v3 = (unsigned __int8)(v2 / 12);
    v11 = (int)(((i << 6) & 0x300) - (((unsigned int)i >> 2) & 3)) / 9;
    v12 = v2 / 12;
    v4 = (unsigned __int8)((((16 * i) & 0xF00) - ((unsigned __int8)i >> 4)) / 30);
    v10[1] = (((16 * i) & 0xF00) - ((unsigned __int8)i >> 4)) / 30;
    if ( v3 + v11 + v4 <= 255 )
      v5 = -1 - v3 - v11 - v4;
    else
      v5 = 0;
    v10[0] = v5;
    idLib::Printf(
      fmt: "%3i : %3i %3i %3i %3i ",
      i,
      v5,
      (unsigned __int8)((((16 * i) & 0xF00) - ((unsigned __int8)i >> 4)) / 30),
      v11,
      (unsigned __int8)(v2 / 12));
    v9 = (unsigned __int8)CompressWeightsToByte(weights: v10, a2: v8, a3: v7, a4: v6);
    if ( v9 == i )
      idLib::Printf(fmt: "\n");
    else
      idLib::Printf(fmt: "ERROR: recompressed to %i\n", v9);
  }
}


// ========================================================================
// ?Memory@idMD6Mesh@@QBAIXZ
// EA  : 0x82843F18
// RVA : 0x00843F18
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

int __fastcall idMD6Mesh::Memory(idMD6Mesh *this)
{
  int num; // r11
  int result; // r3
  int v4; // r11
  int v5; // r10
  idMD6Mesh::stset_t *list; // r9
  int v7; // ctr
  int v8; // r11
  idMD6Mesh::stset_t *v9; // r10
  int v10; // r10

  num = this->vertexes.num;
  result = 172;
  if ( num > 0 )
    result = 56 * num + 172;
  v4 = this->indexes.num;
  if ( v4 > 0 )
    result += 2 * v4;
  v5 = this->stSets.num;
  if ( v5 > 0 )
  {
    list = this->stSets.list;
    v7 = v5;
    result += 24 * v5;
    v8 = 0;
    v9 = list;
    do
    {
      v10 = v9->st.num;
      if ( v10 > 0 )
        result += 8 * v10;
      v9 = &list[++v8];
      --v7;
    }
    while ( v7 != 0 );
  }
  return result;
}


// ========================================================================
// ?WriteMesh_Binary@idMD6Mesh@@QBAXPAVidFile@@@Z
// EA  : 0x82843F98
// RVA : 0x00843F98
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall idMD6Mesh::WriteMesh_Binary(idMD6Mesh *this, idFile *file)
{
  int *p_numVerts; // r26
  int *p_numTris; // r29
  idTriangles *tris; // r11
  idDrawVert *verts; // r4
  const void *v8; // r3
  idTriangles *v9; // r11
  unsigned __int16 *indexes; // r4
  const void *v11; // r3
  idFile_vtbl *v12; // r6
  int v13; // r28
  int v14; // r27
  idMD6Mesh::stset_t *v15; // r29
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  char v17; // [sp+50h] [-40h] BYREF
  _BYTE v18[3]; // [sp+51h] [-3Fh] BYREF
  int num; // [sp+54h] [-3Ch] BYREF

  idFile::WriteString(this: file, string: &this->name);
  idFile::WriteString(this: file, string: this->material->name.str);
  file->Write(this: file, a2: &this->allowSkinRemapping, a3: 1u);
  p_numVerts = &this->numVerts;
  file->Write(this: file, a2: &this->numVerts, a3: 4u);
  p_numTris = &this->numTris;
  file->Write(this: file, a2: &this->numTris, a3: 4u);
  file->Write(this: file, a2: &this->bounds, a3: 24u);
  tris = this->tris;
  verts = tris->verts;
  if ( verts != nullptr )
  {
    file->Write(this: file, a2: verts, a3: 32 * *p_numVerts);
  }
  else if ( (tris->vertexBuffer.size & 0x7FFFFFFF) != 0 )
  {
    v8 = idVertexBuffer::MapBuffer(this: &tris->vertexBuffer, mapType: BM_READ);
    file->Write(this: file, a2: v8, a3: 32 * *p_numVerts);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->tris->vertexBuffer);
  }
  v9 = this->tris;
  indexes = v9->indexes;
  if ( indexes != nullptr )
  {
    file->Write(this: file, a2: indexes, a3: 6 * *p_numTris);
  }
  else if ( (v9->indexBuffer.size & 0x7FFFFFFF) != 0 )
  {
    v11 = idIndexBuffer::MapBuffer(this: &v9->indexBuffer, mapType: BM_READ);
    file->Write(this: file, a2: v11, a3: 6 * *p_numTris);
    idIndexBuffer::UnmapBuffer(this: &this->tris->indexBuffer);
  }
  file->Write(this: file, a2: &this->jointOffset, a3: 4u);
  file->Write(this: file, a2: &this->numJoints, a3: 4u);
  v12 = file->__vftable;
  num = this->stSets.num;
  v12->Write(this: file, a2: &num, a3: 4u);
  v13 = 0;
  if ( this->stSets.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = &this->stSets.list[v14];
      file->Write(this: file, a2: v15, a3: 1u);
      file->Write(this: file, a2: v15->st.list, a3: 8 * v15->st.num);
      ++v13;
      ++v14;
    }
    while ( v13 < this->stSets.num );
  }
  Write = file->Write;
  if ( this->morphMap.num <= 0 )
  {
    v18[0] = 0;
    Write(this: file, a2: v18, a3: 1u);
  }
  else
  {
    v17 = 1;
    Write(this: file, a2: &v17, a3: 1u);
    file->Write(this: file, a2: this->morphMap.list, a3: 4 * *p_numVerts);
  }
}


// ========================================================================
// ?CreateHashST@idMD6Mesh@@AAAXXZ
// EA  : 0x82844280
// RVA : 0x00844280
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall idMD6Mesh::CreateHashST(idMD6Mesh *this)
{
  char *v2; // r3
  int v3; // r30
  int v4; // r29
  char *v5; // r3
  char *data; // r9
  int v7; // r11
  unsigned __int8 i; // r8
  int v9[4]; // [sp+50h] [-170h] BYREF
  idStr v10; // [sp+60h] [-160h] BYREF
  char v11; // [sp+80h] [-140h] BYREF

  v9[0] = this->stSets.num;
  if ( v9[0] > 0 )
  {
    v10.baseBuffer[0] = 0;
    v11 = 0;
    v10.len = 0;
    v10.data = &v11;
    v10.allocedAndFlag = -2147483392;
    v2 = itoa(a: (char *)v9, i: v9[0]);
    idStr::Append(this: &v10, text: v2);
    v3 = 0;
    if ( this->stSets.num > 0 )
    {
      v4 = 0;
      do
      {
        idStr::Append(this: &v10, text: "_");
        v5 = itoa(a: (char *)v9, i: this->stSets.list[v4].slot);
        idStr::Append(this: &v10, text: v5);
        ++v3;
        ++v4;
      }
      while ( v3 < this->stSets.num );
    }
    data = v10.data;
    v7 = 0;
    for ( i = *v10.data; *data != 0; i = *data )
    {
      ++data;
      v7 = 31 * v7 + i;
    }
    this->hashST = v7;
    idStr::FreeData(this: &v10);
  }
  else
  {
    this->hashST = 0;
  }
}


// ========================================================================
// __unwind$224709
// EA  : 0x82844390
// RVA : 0x00844390
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void _unwind_224709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 96));
}


// ========================================================================
// ?FreeLoadData@idMD6Mesh@@QAAXXZ
// EA  : 0x828443C0
// RVA : 0x008443C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall idMD6Mesh::FreeLoadData(idMD6Mesh *this)
{
  idMD6Mesh::stset_t *list; // r30
  idVertexBuffer *vb; // r3
  int v4; // r29
  idIndexBuffer *v5; // r3
  idVertexBuffer *v6; // r3
  int v7; // r27
  int v8; // r29
  idMD6Mesh::stset_t *v9; // r30
  idVec2 *v10; // r4

  if ( this->stSets.num > 0 )
  {
    list = this->stSets.list;
    vb = list->vb;
    v4 = 8 * list->st.num;
    if ( vb != nullptr )
    {
      if ( v4 <= (vb->size & 0x7FFFFFFF) )
      {
        idVertexBuffer::Update(this: vb, data: list->st.list, updateSize: v4, vertexMask: 9216);
      }
      else
      {
        idVertexBuffer::FreeBufferObject(this: vb);
        idVertexBuffer::AllocBufferObject(
          this: list->vb,
          data: list->st.list,
          allocSize: v4,
          vertexMask: 9216,
          allocUsage: BU_DYNAMIC);
      }
    }
    else
    {
      v5 = (idIndexBuffer *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x10u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v5);
      else
        v6 = nullptr;
      list->vb = v6;
      idVertexBuffer::AllocBufferObject(
        this: v6,
        data: list->st.list,
        allocSize: v4,
        vertexMask: 9216,
        allocUsage: BU_DYNAMIC);
    }
    this->tris->vertexMask |= 0x2000u;
  }
  idTriangles::UpdateIndexBuffer(this: this->tris);
  idTriangles::UpdateVertexBuffer(this: this->tris);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexes);
  v7 = 0;
  if ( this->stSets.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->stSets.list[v8];
      if ( v9->st.listStatic == 0 || v9->st.listStatic == 2 )
      {
        v10 = v9->st.list;
        if ( v10 != nullptr )
          idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
        v9->st.list = nullptr;
        v9->st.size = 0;
      }
      ++v7;
      v9->st.num = 0;
      ++v8;
    }
    while ( v7 < this->stSets.num );
  }
  idTriangles::FreeCPUData(this: this->tris);
}


// ========================================================================
// __unwind$224837
// EA  : 0x82844548
// RVA : 0x00844548
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall _unwind_224837(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?Free@idMD6Mesh@@QAAXXZ
// EA  : 0x82844570
// RVA : 0x00844570
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall idMD6Mesh::Free(idMD6Mesh *this)
{
  idTriangles *tris; // r31
  int v3; // r27
  int v4; // r28
  idMD6Mesh::stset_t *list; // r11
  idMD6Mesh::stset_t *v6; // r29
  idVertexBuffer *vb; // r31
  idMD6Mesh::stset_t *v8; // r3

  tris = this->tris;
  if ( tris != nullptr )
  {
    idTriangles::~idTriangles(this: this->tris);
    idMem::Free(this: &mem, ptr: tris, align: ALIGN_16);
    this->tris = nullptr;
  }
  v3 = 0;
  if ( this->stSets.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->stSets.list;
      v6 = &list[v4];
      vb = list[v4].vb;
      if ( vb != nullptr )
      {
        idVertexBuffer::~idVertexBuffer(this: list[v4].vb);
        idMem::Free(this: &mem, ptr: vb, align: ALIGN_16);
        v6->vb = nullptr;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->stSets.num );
  }
  if ( this->stSets.listStatic == 0 || this->stSets.listStatic == 2 )
  {
    v8 = this->stSets.list;
    if ( v8 != nullptr )
      idListArrayDelete<idMD6Mesh::stset_t>(ptr: (char *)v8, num: this->stSets.size);
    this->stSets.list = nullptr;
    this->stSets.size = 0;
  }
  this->stSets.num = 0;
}


// ========================================================================
// ?LoadMesh_Binary@idMD6Mesh@@QAAXPAVidFile@@I@Z
// EA  : 0x82844A40
// RVA : 0x00844A40
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void __fastcall idMD6Mesh::LoadMesh_Binary(idMD6Mesh *this, idFile *file, unsigned int magic)
{
  const idMaterial *v6; // r3
  int *p_numVerts; // r25
  idFile_vtbl *v8; // r9
  idList<idMD6Mesh::stset_t,19> *p_stSets; // r26
  int v10; // r24
  int v11; // r28
  idMD6Mesh::stset_t *v12; // r27
  idVec2 *list; // r4
  int v14; // r23
  int v15; // r26
  int v16; // r27
  idMD6Mesh::stset_t *v17; // r24
  int size; // r11
  int v19; // r28
  int v20; // r11
  float *tris; // r11
  double x; // fp0
  char v23[4]; // [sp+50h] [-90h] BYREF
  int v24; // [sp+54h] [-8Ch] BYREF
  idBounds *p_bounds; // [sp+58h] [-88h]
  idStr v26[4]; // [sp+60h] [-80h] BYREF

  v26[0].len = 0;
  v26[0].allocedAndFlag = 20;
  v26[0].data = v26[0].baseBuffer;
  v26[0].baseBuffer[0] = 0;
  idFile::ReadString(this: file, string: &this->name);
  idFile::ReadString(this: file, string: v26);
  if ( !idMaterial::IsValidMaterialName(name: v26[0].data, allowUnderscore: true, allowAmpersand: true) )
    idLib::Error(fmt: "Model '%s' has been generated with an invalid materialname", this->name.data);
  if ( v26[0].data != nullptr )
    v6 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: v26[0].data,
                               makeDefault: true);
  else
    v6 = nullptr;
  this->material = v6;
  file->Read(this: file, a2: &this->allowSkinRemapping, a3: 1u);
  file->Read(this: file, a2: &this->numTexCoordSets, a3: 4u);
  p_numVerts = &this->numVerts;
  file->Read(this: file, a2: &this->numVerts, a3: 4u);
  file->Read(this: file, a2: &this->numTris, a3: 4u);
  v8 = file->__vftable;
  p_bounds = &this->bounds;
  v8->Read(this: file, a2: &this->bounds, a3: 24u);
  this->tris->numVerts = this->numVerts;
  this->tris->numIndexes = 3 * this->numTris;
  idTriangles::AllocStaticTriSurfVerts(this: this->tris, numVerts: this->numVerts);
  idTriangles::AllocStaticTriSurfIndexes(this: this->tris, numIndexes: 3 * this->numTris);
  file->Read(this: file, a2: this->tris->verts, a3: 32 * this->numVerts);
  file->Read(this: file, a2: this->tris->indexes, a3: 6 * this->numTris);
  file->Read(this: file, a2: &this->jointOffset, a3: 4u);
  file->Read(this: file, a2: &this->numJoints, a3: 4u);
  if ( magic == 557206861 )
  {
    v24 = 0;
    file->Read(this: file, a2: &v24, a3: 4u);
    p_stSets = &this->stSets;
    idList<idMD6Mesh::stset_t,19>::SetNum(this: &this->stSets, newNum: v24);
    v10 = 0;
    if ( this->stSets.num > 0 )
    {
      v11 = 0;
      do
      {
        p_stSets->list[v11].slot = 0;
        p_stSets->list[v11].vb = nullptr;
        v12 = &p_stSets->list[v11];
        if ( v12->st.listStatic == 0 || v12->st.listStatic == 2 )
        {
          list = v12->st.list;
          if ( list != nullptr )
          {
            p_bounds = (idBounds *)v12->st.list;
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          }
          v12->st.list = nullptr;
          v12->st.size = 0;
        }
        ++v10;
        v12->st.num = 0;
        ++v11;
      }
      while ( v10 < this->stSets.num );
    }
  }
  v14 = 0;
  if ( this->stSets.num > 0 )
  {
    v15 = 0;
    do
    {
      v16 = *p_numVerts;
      v17 = &this->stSets.list[v15];
      if ( *p_numVerts <= v17->st.size
        || (unsigned __int8)idList<idVec2,72>::Resize(this: (idList<idVec2,72> *)&v17->st, newsize: *p_numVerts) != 0 )
      {
        size = v17->st.size;
        if ( v16 < size )
          size = v16;
        v17->st.num = size;
      }
      file->Read(this: file, a2: v17, a3: 1u);
      file->Read(this: file, a2: v17->st.list, a3: 8 * *p_numVerts);
      ++v14;
      ++v15;
    }
    while ( v14 < this->stSets.num );
  }
  v23[0] = 0;
  file->Read(this: file, a2: v23, a3: 1u);
  if ( v23[0] != 0 )
  {
    v19 = 4 * *p_numVerts;
    if ( v19 <= this->morphMap.size
      || idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&this->morphMap, newsize: 4 * *p_numVerts) )
    {
      v20 = this->morphMap.size;
      if ( v19 < v20 )
        v20 = v19;
      this->morphMap.num = v20;
    }
    file->Read(this: file, a2: this->morphMap.list, a3: 4 * *p_numVerts);
  }
  tris = (float *)this->tris;
  x = this->bounds.b[0].x;
  p_bounds = (idBounds *)(tris + 3);
  *tris = x;
  tris[1] = this->bounds.b[0].y;
  tris[2] = this->bounds.b[0].z;
  tris[3] = this->bounds.b[1].x;
  tris[4] = this->bounds.b[1].y;
  tris[5] = this->bounds.b[1].z;
  idMD6Mesh::CreateHashST(this);
  idStr::FreeData(this: v26);
}


// ========================================================================
// $LN150
// EA  : 0x82844EA8
// RVA : 0x00844EA8
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

void _LN150()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// `dynamic initializer for 'testByteWeights_v''
// EA  : 0x833442A0
// RVA : 0x013442A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testByteWeights_v__()
{
  return idCommandLink::idCommandLink(
           this: &testByteWeights_v,
           cmdName: "testByteWeights",
           function: testByteWeights_f,
           description: "test the weight-packing-to-bytes code",
           argCompletion: nullptr);
}

