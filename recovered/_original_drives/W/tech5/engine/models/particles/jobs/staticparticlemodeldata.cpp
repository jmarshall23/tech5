
// ========================================================================
// ?FreeData@idStaticParticleModelData@@AAAXXZ
// EA  : 0x827EC2D0
// RVA : 0x007EC2D0
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void __fastcall idStaticParticleModelData::FreeData(idStaticParticleModelData *this)
{
  idDrawVert *staticVerts; // r4

  staticVerts = this->staticVerts;
  this->timestamp = -1;
  idMem::Free(this: &mem, ptr: staticVerts, align: ALIGN_16);
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
}


// ========================================================================
// ?ReloadIfStale@idStaticParticleModelData@@UAA_NXZ
// EA  : 0x827EC320
// RVA : 0x007EC320
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

int __fastcall idStaticParticleModelData::ReloadIfStale(idStaticParticleModelData *this)
{
  _BYTE v3[264]; // [sp+50h] [-120h] BYREF

  if ( fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->timestamp )
    return 0;
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "pmodel", a4: this->name.str, a5: v3, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v3, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ??0idStaticParticleModelData@@QAA@XZ
// EA  : 0x827EC3F0
// RVA : 0x007EC3F0
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

idStaticParticleModelData *__fastcall idStaticParticleModelData::idStaticParticleModelData(
        idStaticParticleModelData *this)
{
  idResource::idResource(this: &this->idResource);
  this->timestamp = -1;
  this->__vftable = (idStaticParticleModelData_vtbl *)&idStaticParticleModelData::`vftable';
  this->staticVerts = nullptr;
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
  return this;
}


// ========================================================================
// __unwind$231188
// EA  : 0x827EC450
// RVA : 0x007EC450
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void _unwind_231188()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idStaticParticleModelData@@UAA@XZ
// EA  : 0x827EC490
// RVA : 0x007EC490
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void __fastcall idStaticParticleModelData::~idStaticParticleModelData(idStaticParticleModelData *this)
{
  idDrawVert *staticVerts; // r4

  this->__vftable = (idStaticParticleModelData_vtbl *)&idStaticParticleModelData::`vftable';
  staticVerts = this->staticVerts;
  this->timestamp = -1;
  idMem::Free(this: &mem, ptr: staticVerts, align: ALIGN_16);
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$231209
// EA  : 0x827EC504
// RVA : 0x007EC504
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void _unwind_231209()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?WriteBinary@idStaticParticleModelData@@AAA_NPBD@Z
// EA  : 0x827EC538
// RVA : 0x007EC538
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

int __fastcall idStaticParticleModelData::WriteBinary(idStaticParticleModelData *this, const char *fileName)
{
  idFile *v4; // r3
  idFileLocal v6[12]; // [sp+50h] [-30h] BYREF

  idLib::Printf(fmt: "Writing %s\n", fileName);
  v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName, a3: 0);
  v6[0].file = v4;
  if ( v4 != nullptr )
  {
    v4->Write(this: v4, a2: &STATICPARTICLE_MODEL_MAGIC, a3: 4u);
    v6[0].file->Write(this: v6[0].file, a2: &this->timestamp, a3: 4u);
    v6[0].file->Write(this: v6[0].file, a2: &this->numStaticVerts, a3: 4u);
    v6[0].file->Write(this: v6[0].file, a2: this->staticVerts, a3: 32 * this->numStaticVerts);
    idFileLocal::~idFileLocal(this: v6);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idStaticParticleModelData::WriteBinary() - Could not open %s", fileName);
    idFileLocal::~idFileLocal(this: v6);
    return 0;
  }
}


// ========================================================================
// __unwind$231231
// EA  : 0x827EC630
// RVA : 0x007EC630
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void _unwind_231231()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 80));
}


// ========================================================================
// ?LoadBinary@idStaticParticleModelData@@AAA_NPBD@Z
// EA  : 0x827EC768
// RVA : 0x007EC768
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

int __fastcall idStaticParticleModelData::LoadBinary(idStaticParticleModelData *this, const char *fileName)
{
  idFile *v3; // r3
  __int64 v5; // r10
  __int64 v6; // r6
  idDrawVert *v7; // r4
  idFile *file; // r3
  int v9; // [sp+8h] [-78h]
  int v10; // [sp+Ch] [-74h]
  int v11; // [sp+10h] [-70h]
  int v12; // [sp+14h] [-6Ch]
  int v13; // [sp+18h] [-68h]
  int v14; // [sp+1Ch] [-64h]
  idFileLocal v15; // [sp+50h] [-30h] BYREF
  _DWORD v16[5]; // [sp+54h] [-2Ch] BYREF

  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v15.file = v3;
  if ( v3 != nullptr )
  {
    v16[0] = 0;
    v3->Read(this: v3, a2: v16, a3: 4u);
    LODWORD(v6) = v16[0];
    if ( v16[0] == 21777744 )
    {
      v15.file->Read(this: v15.file, a2: &this->timestamp, a3: 4u);
      v15.file->Read(this: v15.file, a2: &this->numStaticVerts, a3: 4u);
      v7 = (idDrawVert *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\models\\particles\\jobs\\StaticParticleModelData.cpp(125) : TAG_PARTICLE",
                           size: 32 * this->numStaticVerts,
                           tag: TAG_PARTICLE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      file = v15.file;
      this->staticVerts = v7;
      v16[1] = v7;
      ((void (__fastcall *)(idFile *))file->Read)(a1: file);
      idFileLocal::~idFileLocal(this: &v15);
      return 1;
    }
    else
    {
      HIDWORD(v6) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "bad magic on staticparticlemodeldata '%s'",
        a3: v6,
        a4: 0x14C4D50014C0000LL,
        a5: v5,
        a6: v9,
        a7: v10,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14);
      idFileLocal::~idFileLocal(this: &v15);
      return 0;
    }
  }
  else
  {
    idFileLocal::~idFileLocal(this: &v15);
    return 0;
  }
}


// ========================================================================
// __unwind$231428
// EA  : 0x827EC8C8
// RVA : 0x007EC8C8
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void _unwind_231428()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 80));
}


// ========================================================================
// ?Generate@idStaticParticleModelData@@AAA_NXZ
// EA  : 0x827EC8F8
// RVA : 0x007EC8F8
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

int __fastcall idStaticParticleModelData::Generate(idStaticParticleModelData *this)
{
  unsigned __int16 *v2; // r3
  idStaticModel *v3; // r25
  idTriangles *geometry; // r24
  idDrawVert *verts; // r26
  unsigned __int16 *buffer; // r23
  int v7; // r30
  idDrawVert *v8; // r3
  int numStaticVerts; // r10
  int v10; // r28
  int v11; // r30
  unsigned __int16 *v12; // r27
  idTempArray<unsigned short> v14; // [sp+50h] [-60h] BYREF

  v2 = (unsigned __int16 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x194u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v14.buffer = v2;
  if ( v2 != nullptr )
    v3 = idStaticModel::idStaticModel(this: (idStaticModel *)v2);
  else
    v3 = nullptr;
  idResource::SetName(this: v3, _name: this->name.str);
  idStaticModel::PristineLoadResource(this: v3);
  if ( v3->resourceError != nullptr || v3->surfaces.num == 0 )
  {
    ((void (__fastcall *)(idStaticModel *, int))v3->dtr_idResource)(a1: v3, a2: 1);
    idLib::Warning(fmt: "idStaticParticleModelData: Couldn't load model: %s", this->name.str);
    return 0;
  }
  this->timestamp = v3->sourceTimeStamp;
  geometry = v3->surfaces.list->geometry;
  if ( v3->surfaces.num != 1 || geometry->numVerts > 128 )
  {
    idStaticParticleModelData::FreeData(this);
    ((void (__fastcall *)(idStaticModel *, int))v3->dtr_idResource)(a1: v3, a2: 1);
    idLib::Warning(
      fmt: "Particle %s: Cannot have a static mesh with more than 1 surface or more than %d verts",
      this->name.str,
      128);
    return 0;
  }
  verts = geometry->verts;
  if ( verts == nullptr )
    verts = (idDrawVert *)idVertexBuffer::MapBuffer(this: &geometry->vertexBuffer, mapType: BM_READ);
  idTempArray<unsigned short>::idTempArray<unsigned short>(this: &v14, num: 4 * (geometry->numIndexes / 3));
  buffer = v14.buffer;
  v7 = 4 * idTriangles::CreateQuads(this: geometry, quads: v14.buffer);
  if ( v7 > 128 )
  {
    idStaticParticleModelData::FreeData(this);
    if ( verts != geometry->verts )
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&geometry->vertexBuffer);
    ((void (__fastcall *)(idStaticModel *, int))v3->dtr_idResource)(a1: v3, a2: 1);
    idLib::Warning(
      fmt: "Particle %s creates %d verts : Cannot have a static mesh with more than %d verts",
      this->name.str,
      v7,
      128);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    return 0;
  }
  this->numStaticVerts = v7;
  v8 = (idDrawVert *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\engine\\models\\particles\\jobs\\StaticParticleModelData.cpp(214) : TAG_PARTICLE",
                       size: 32 * v7,
                       tag: TAG_PARTICLE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  numStaticVerts = this->numStaticVerts;
  this->staticVerts = v8;
  v10 = 0;
  if ( numStaticVerts > 0 )
  {
    v11 = 0;
    v12 = buffer - 1;
    do
    {
      idDrawVert::operator=(this: &this->staticVerts[v11], rhs: (idDrawVert *)((char *)verts + __ROL4__(*++v12, 5)));
      ++v10;
      ++v11;
    }
    while ( v10 < this->numStaticVerts );
  }
  if ( verts != geometry->verts )
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&geometry->vertexBuffer);
  ((void (__fastcall *)(idStaticModel *, int))v3->dtr_idResource)(a1: v3, a2: 1);
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$231539
// EA  : 0x827ECB88
// RVA : 0x007ECB88
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void __fastcall _unwind_231539(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// __unwind$231540
// EA  : 0x827ECBB0
// RVA : 0x007ECBB0
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void _unwind_231540()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 80));
}


// ========================================================================
// ?LoadResource@idStaticParticleModelData@@UAAXXZ
// EA  : 0x827ECBD8
// RVA : 0x007ECBD8
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void __fastcall idStaticParticleModelData::LoadResource(idStaticParticleModelData *this)
{
  idDrawVert *staticVerts; // r4
  const char *str; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  int v7; // [sp+8h] [-158h]
  int v8; // [sp+Ch] [-154h]
  int v9; // [sp+10h] [-150h]
  int v10; // [sp+14h] [-14Ch]
  int v11; // [sp+18h] [-148h]
  int v12; // [sp+1Ch] [-144h]
  char v13[256]; // [sp+50h] [-110h] BYREF

  staticVerts = this->staticVerts;
  this->timestamp = -1;
  idMem::Free(this: &mem, ptr: staticVerts, align: ALIGN_16);
  str = this->name.str;
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "pmodel", a4: str, a5: v13, a6: 256);
  if ( (unsigned __int8)idStaticParticleModelData::LoadBinary(this, fileName: v13) == 0 )
  {
    if ( (unsigned __int8)idStaticParticleModelData::Generate(this) != 0 )
    {
      idStaticParticleModelData::WriteBinary(this, fileName: v13);
    }
    else
    {
      HIDWORD(v6) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Couldn't load staticparticlemodeldata '%s'",
        a3: v6,
        a4: v5,
        a5: v4,
        a6: v7,
        a7: v8,
        a8: v9,
        a9: v10,
        a10: v11,
        a11: v12);
      idStaticParticleModelData::FreeData(this);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'idStaticParticleModelData::resourceList''
// EA  : 0x83342F70
// RVA : 0x01342F70
// PDB : w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idStaticParticleModelData::resourceList__()
{
  idResourceList::idResourceList(this: &idStaticParticleModelData::resourceList, typeName: "staticParticleModel");
  idStaticParticleModelData::resourceList.__vftable = (idTypedResourceList<idStaticParticleModelData>_vtbl *)&idTypedResourceList<idStaticParticleModelData>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idStaticParticleModelData::resourceList__);
}

