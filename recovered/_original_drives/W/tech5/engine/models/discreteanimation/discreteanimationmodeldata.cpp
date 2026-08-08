
// ========================================================================
// ?UpdateBuffers@idDiscreteAnimationModelData@@AAAXXZ
// EA  : 0x827CE958
// RVA : 0x007CE958
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::UpdateBuffers(idDiscreteAnimationModelData *this)
{
  int v2; // r29
  int v3; // r31

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      idTriangles::UpdateVertexBuffer(this: this->surfaces.list[v3]->triangles);
      idTriangles::UpdateIndexBuffer(this: this->surfaces.list[v3]->triangles);
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
}


// ========================================================================
// ?FreeCPUData@idDiscreteAnimationModelData@@AAAXXZ
// EA  : 0x827CE9B8
// RVA : 0x007CE9B8
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::FreeCPUData(idDiscreteAnimationModelData *this)
{
  int v2; // r30
  int v3; // r31

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      idTriangles::FreeCPUData(this: this->surfaces.list[v3]->triangles);
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
}


// ========================================================================
// ?WriteBinary@idDiscreteAnimationModelData@@AAA_NPBD@Z
// EA  : 0x827CEA10
// RVA : 0x007CEA10
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

int __fastcall idDiscreteAnimationModelData::WriteBinary(idDiscreteAnimationModelData *this, const char *fileName)
{
  idFile *file; // r3
  int v6; // r28
  int v7; // r29
  int v8; // r28
  int v9; // r29
  idTriangles *triangles; // r7
  idTriangles *v11; // r9
  int v12; // r28
  int v13; // r27
  sourceSurface_t *v14; // r29
  int v15; // r28
  int v16; // r29
  idFileLocal v17; // [sp+50h] [-50h] BYREF
  int num; // [sp+54h] [-4Ch] BYREF
  int v19; // [sp+58h] [-48h] BYREF
  int v20; // [sp+5Ch] [-44h] BYREF
  int v21; // [sp+60h] [-40h] BYREF
  int v22; // [sp+64h] [-3Ch] BYREF
  int v23; // [sp+68h] [-38h] BYREF

  idLib::Printf(fmt: "Writing %s\n", fileName);
  file = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName, a3: 0);
  v17.file = file;
  if ( file != nullptr )
  {
    v6 = 0;
    if ( this->traceModels.num > 0 )
    {
      v7 = 0;
      do
      {
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->traceModels.list[v7]);
        ++v6;
        ++v7;
      }
      while ( v6 < this->traceModels.num );
      file = v17.file;
    }
    file->Write(this: file, a2: &DISCRETEANIMATION_MODEL_MAGIC, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->timestamp, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->maxRadius, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->bounds, a3: 24u);
    idFile::WriteString(this: v17.file, string: this->material->name.str);
    num = this->traceModels.num;
    v17.file->Write(this: v17.file, a2: &num, a3: 4u);
    v17.file->Write(this: v17.file, a2: this->traceModels.list, a3: 1536 * this->traceModels.num);
    v19 = this->transforms.num;
    v17.file->Write(this: v17.file, a2: &v19, a3: 4u);
    v17.file->Write(this: v17.file, a2: this->transforms.list, a3: 48 * this->transforms.num);
    v20 = this->surfaces.num;
    v17.file->Write(this: v17.file, a2: &v20, a3: 4u);
    v8 = 0;
    if ( this->surfaces.num > 0 )
    {
      v9 = 0;
      do
      {
        v17.file->Write(this: v17.file, a2: this->surfaces.list[v9], a3: 4u);
        v17.file->Write(this: v17.file, a2: &this->surfaces.list[v9]->numJoints, a3: 4u);
        v17.file->Write(this: v17.file, a2: &this->surfaces.list[v9]->triangles->numVerts, a3: 4u);
        v17.file->Write(this: v17.file, a2: &this->surfaces.list[v9]->triangles->numIndexes, a3: 4u);
        triangles = this->surfaces.list[v9]->triangles;
        v17.file->Write(this: v17.file, a2: triangles->verts, a3: 32 * triangles->numVerts);
        v11 = this->surfaces.list[v9]->triangles;
        v17.file->Write(this: v17.file, a2: v11->indexes, a3: 2 * v11->numIndexes);
        ++v8;
        ++v9;
      }
      while ( v8 < this->surfaces.num );
    }
    v21 = this->sourceSurfaces.num;
    v17.file->Write(this: v17.file, a2: &v21, a3: 4u);
    v12 = 0;
    if ( this->sourceSurfaces.num > 0 )
    {
      v13 = 0;
      do
      {
        v14 = &this->sourceSurfaces.list[v13];
        idFile::WriteString(this: v17.file, string: v14->mtr->name.str);
        v17.file->Write(this: v17.file, a2: &v14->mtrChecksum, a3: 4u);
        v17.file->Write(this: v17.file, a2: &v14->renderSurface, a3: 4u);
        v17.file->Write(this: v17.file, a2: &v14->firstVertex, a3: 4u);
        v17.file->Write(this: v17.file, a2: &v14->lastVertex, a3: 4u);
        ++v12;
        ++v13;
      }
      while ( v12 < this->sourceSurfaces.num );
    }
    v15 = 0;
    if ( this->traceModels.num > 0 )
    {
      v16 = 0;
      do
      {
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->traceModels.list[v16]);
        ++v15;
        ++v16;
      }
      while ( v15 < this->traceModels.num );
    }
    if ( this->baseModel != nullptr )
    {
      v22 = 1;
      v17.file->Write(this: v17.file, a2: &v22, a3: 4u);
      idFile::WriteString(this: v17.file, string: this->baseModel->name.str);
    }
    else
    {
      v23 = 0;
      v17.file->Write(this: v17.file, a2: &v23, a3: 4u);
    }
    idFileLocal::~idFileLocal(this: &v17);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idDiscreteAnimationModelData::WriteBinary() - Could not open %s", fileName);
    idFileLocal::~idFileLocal(this: &v17);
    return 0;
  }
}


// ========================================================================
// __unwind$224478
// EA  : 0x827CEE84
// RVA : 0x007CEE84
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_224478()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 160 + 80));
}


// ========================================================================
// ?ReloadIfStale@idDiscreteAnimationModelData@@UAA_NXZ
// EA  : 0x827CEEB0
// RVA : 0x007CEEB0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

int __fastcall idDiscreteAnimationModelData::ReloadIfStale(idDiscreteAnimationModelData *this)
{
  unsigned int v2; // r8
  BOOL v3; // r11
  int v4; // r29
  int v5; // r30
  const idMaterial *mtr; // r10
  const char *str; // r4
  idCollisionModelLocal *v8; // r3
  int mtrChecksum; // r26
  cmType_t ScriptP; // r3
  _BYTE v12[320]; // [sp+50h] [-140h] BYREF

  v2 = this->timestamp - fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false);
  v3 = v2 != 0;
  if ( v2 == 0 )
  {
    v4 = 0;
    if ( this->sourceSurfaces.num <= 0 )
    {
LABEL_10:
      if ( !v3 )
        return 0;
    }
    else
    {
      v5 = 0;
      while ( 1 )
      {
        mtr = this->sourceSurfaces.list[v5].mtr;
        if ( mtr != nullptr )
        {
          str = mtr->name.str;
          v8 = str != nullptr
             ? (idCollisionModelLocal *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: str,
                                          makeDefault: true)
             : nullptr;
          mtrChecksum = this->sourceSurfaces.list[v5].mtrChecksum;
          ScriptP = idLexer::GetScriptP(this: v8);
          v3 = ScriptP != mtrChecksum;
          if ( ScriptP != mtrChecksum )
            break;
        }
        ++v4;
        ++v5;
        if ( v4 >= this->sourceSurfaces.num )
          goto LABEL_10;
      }
    }
  }
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "dmodel", a4: this->name.str, a5: v12, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v12, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?RemapSourceSurfaces@idDiscreteAnimationModelData@@AAAXXZ
// EA  : 0x827CF0D0
// RVA : 0x007CF0D0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::RemapSourceSurfaces(idDiscreteAnimationModelData *this)
{
  int v2; // r29
  int v3; // r27
  idList<idMaterial const *,5> v4; // [sp+50h] [-60h] BYREF
  idList<skinRemap_t,5> v5[5]; // [sp+60h] [-50h] BYREF

  memset(v5, 0, 14);
  v5[0].listStatic = 0;
  v5[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v5);
  memset(&v4, 0, 14);
  *(_WORD *)&v4.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v4);
  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
      idTriangles::VmtrMapTexCoordsWithSkins(
        this: this->surfaces.list[v3++]->triangles,
        sourceSurfaces: (idList<sourceSurface_t,5> *)&this->sourceSurfaces,
        renderSurface: v2++,
        originalMaterial: this->material,
        skins: nullptr,
        skinRemaps: v5,
        usedMaterials: &v4);
    while ( v2 < this->surfaces.num );
  }
  if ( v4.listStatic == 0 || v4.listStatic == 2 )
  {
    if ( v4.list != nullptr )
      idMem::Free(this: &mem, ptr: v4.list, align: ALIGN_16);
    v4.list = nullptr;
    v4.size = 0;
  }
  v4.num = 0;
  if ( (v5[0].listStatic == 0 || v5[0].listStatic == 2) && v5[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v5[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$224953
// EA  : 0x827CF1F4
// RVA : 0x007CF1F4
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_224953()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$224954
// EA  : 0x827CF21C
// RVA : 0x007CF21C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_224954()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 80));
}


// ========================================================================
// ?FreeData@idDiscreteAnimationModelData@@AAAXXZ
// EA  : 0x827CF3E8
// RVA : 0x007CF3E8
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::FreeData(idDiscreteAnimationModelData *this)
{
  int v2; // r28
  int v3; // r30
  idDiscreteAnimationModelSurface *v4; // r10
  idTriangles *triangles; // r29
  idList<idDiscreteAnimationModelSurface *,59> *p_surfaces; // r29
  idList<idTraceModel,59> *p_traceModels; // r30
  idList<idJointMat,59> *p_transforms; // r29

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->surfaces.list[v3];
      triangles = v4->triangles;
      if ( triangles != nullptr )
      {
        idTriangles::~idTriangles(this: v4->triangles);
        idMem::Free(this: &mem, ptr: triangles, align: ALIGN_16);
      }
      idMem::Free(this: &mem, ptr: this->surfaces.list[v3], align: ALIGN_16);
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
  p_surfaces = &this->surfaces;
  if ( this->surfaces.size < 0 )
  {
    if ( this->surfaces.listStatic == 0 || this->surfaces.listStatic == 2 )
    {
      if ( p_surfaces->list != nullptr )
        idMem::Free(this: &mem, ptr: p_surfaces->list, align: ALIGN_16);
      p_surfaces->list = nullptr;
      this->surfaces.size = 0;
    }
    this->surfaces.num = 0;
  }
  p_traceModels = &this->traceModels;
  this->surfaces.num = __CFADD__(-this->surfaces.size, this->surfaces.size ^ 0x80000000) ? 0 : this->surfaces.size;
  if ( this->traceModels.size < 0 )
  {
    if ( this->traceModels.listStatic == 0 || this->traceModels.listStatic == 2 )
    {
      if ( p_traceModels->list != nullptr )
        idMem::Free(this: &mem, ptr: p_traceModels->list, align: ALIGN_16);
      p_traceModels->list = nullptr;
      this->traceModels.size = 0;
    }
    this->traceModels.num = 0;
  }
  p_transforms = &this->transforms;
  this->traceModels.num = __CFADD__(-this->traceModels.size, this->traceModels.size ^ 0x80000000)
                        ? 0
                        : this->traceModels.size;
  if ( this->transforms.size < 0 )
  {
    if ( this->transforms.listStatic == 0 || this->transforms.listStatic == 2 )
    {
      if ( p_transforms->list != nullptr )
        idMem::Free(this: &mem, ptr: p_transforms->list, align: ALIGN_16);
      p_transforms->list = nullptr;
      this->transforms.size = 0;
    }
    this->transforms.num = 0;
  }
  this->transforms.num = __CFADD__(-this->transforms.size, this->transforms.size ^ 0x80000000)
                       ? 0
                       : this->transforms.size;
  this->material = nullptr;
  this->bounds.b[1].z = 0.0;
  this->bounds.b[1].y = 0.0;
  this->bounds.b[1].x = 0.0;
  this->bounds.b[0].z = 0.0;
  this->bounds.b[0].y = 0.0;
  this->bounds.b[0].x = 0.0;
  this->timestamp = -1;
  this->maxRadius = 0.0;
  this->baseModel = nullptr;
}


// ========================================================================
// ?LoadBinary@idDiscreteAnimationModelData@@AAA_NPBD@Z
// EA  : 0x827CF5E0
// RVA : 0x007CF5E0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

int __fastcall idDiscreteAnimationModelData::LoadBinary(idDiscreteAnimationModelData *this, const char *fileName)
{
  idFile *v4; // r3
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  const idMaterial *v9; // r3
  idFile *file; // r11
  idList<idDiscreteAnimationModelSurface *,59> *p_surfaces; // r29
  int v12; // r25
  int v13; // r30
  idDiscreteAnimationModelSurface *v14; // r3
  idDiscreteAnimationModelSurface *v15; // r11
  idTriangles *v16; // r3
  idTriangles *v17; // r3
  idDiscreteAnimationModelSurface **list; // r11
  float *triangles; // r11
  double z; // fp12
  idTriangles *v21; // r3
  idTriangles *v22; // r3
  idTriangles *v23; // r7
  idTriangles *v24; // r8
  int v25; // r30
  int size; // r11
  int v27; // r27
  int v28; // r29
  sourceSurface_t *v29; // r30
  const idDecl *v30; // r3
  int v31; // r29
  int v32; // r30
  idCollisionModel *Model; // r3
  int v34; // [sp+8h] [-108h]
  int v35; // [sp+Ch] [-104h]
  int v36; // [sp+10h] [-100h]
  int v37; // [sp+14h] [-FCh]
  int v38; // [sp+18h] [-F8h]
  int v39; // [sp+1Ch] [-F4h]
  idFileLocal v40; // [sp+50h] [-C0h] BYREF
  int v41; // [sp+54h] [-BCh] BYREF
  int v42; // [sp+58h] [-B8h] BYREF
  idBounds *p_bounds; // [sp+5Ch] [-B4h]
  idStr v44; // [sp+60h] [-B0h] BYREF
  idStr v45[4]; // [sp+80h] [-90h] BYREF

  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v40.file = v4;
  if ( v4 == nullptr )
  {
    idFileLocal::~idFileLocal(this: &v40);
    return 0;
  }
  v42 = 0;
  v4->Read(this: v4, a2: &v42, a3: 4u);
  HIDWORD(v7) = 72089600;
  HIDWORD(v8) = v42;
  LODWORD(v8) = 72109380;
  if ( v42 != 72109380 )
  {
    HIDWORD(v6) = fileName;
    idResource::SetResourceError(
      this: &this->idResource,
      fmt: "bad magic on discreteanimation '%s'",
      a3: v6,
      a4: v8,
      a5: v7,
      a6: v34,
      a7: v35,
      a8: v36,
      a9: v37,
      a10: v38,
      a11: v39);
    idFileLocal::~idFileLocal(this: &v40);
    return 0;
  }
  v44.len = 0;
  v44.baseBuffer[0] = 0;
  v44.allocedAndFlag = 20;
  v44.data = v44.baseBuffer;
  v40.file->Read(this: v40.file, a2: &this->timestamp, a3: 4u);
  v40.file->Read(this: v40.file, a2: &this->maxRadius, a3: 4u);
  p_bounds = &this->bounds;
  v40.file->Read(this: v40.file, a2: &this->bounds, a3: 24u);
  idFile::ReadString(this: v40.file, string: &v44);
  if ( v44.data != nullptr )
    v9 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: v44.data,
                               makeDefault: true);
  else
    v9 = nullptr;
  file = v40.file;
  this->material = v9;
  file->Read(this: file, a2: &v41, a3: 4u);
  idList<idTraceModel,59>::SetNum(this: &this->traceModels, newNum: v41);
  v40.file->Read(this: v40.file, a2: this->traceModels.list, a3: 1536 * this->traceModels.num);
  v40.file->Read(this: v40.file, a2: &v41, a3: 4u);
  idList<idJointMat,59>::SetNum(this: &this->transforms, newNum: v41);
  v40.file->Read(this: v40.file, a2: this->transforms.list, a3: 48 * this->transforms.num);
  v40.file->Read(this: v40.file, a2: &v41, a3: 4u);
  p_surfaces = &this->surfaces;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->surfaces, newNum: v41);
  v12 = 0;
  if ( this->surfaces.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = (idDiscreteAnimationModelSurface *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                 size: 0xCu,
                                                 tag: TAG_FXPHYSICS,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
      if ( v14 != nullptr )
      {
        v14->jointOffset = 0;
        v15 = v14;
        v14->numJoints = 0;
        v14->triangles = nullptr;
      }
      else
      {
        v15 = nullptr;
      }
      p_surfaces->list[v13] = v15;
      v16 = (idTriangles *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_TRIANGLES,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      p_bounds = &v16->bounds;
      if ( v16 != nullptr )
        v17 = idTriangles::idTriangles(this: v16);
      else
        v17 = nullptr;
      list = p_surfaces->list;
      p_bounds = (idBounds *)&this->bounds.b[1];
      list[v13]->triangles = v17;
      triangles = (float *)p_surfaces->list[v13]->triangles;
      *triangles = this->bounds.b[0].x;
      triangles[1] = this->bounds.b[0].y;
      z = this->bounds.b[0].z;
      p_bounds = (idBounds *)(triangles + 3);
      triangles[2] = z;
      triangles[3] = this->bounds.b[1].x;
      triangles[4] = this->bounds.b[1].y;
      triangles[5] = this->bounds.b[1].z;
      v40.file->Read(this: v40.file, a2: p_surfaces->list[v13], a3: 4u);
      v40.file->Read(this: v40.file, a2: &p_surfaces->list[v13]->numJoints, a3: 4u);
      v40.file->Read(this: v40.file, a2: &p_surfaces->list[v13]->triangles->numVerts, a3: 4u);
      v40.file->Read(this: v40.file, a2: &p_surfaces->list[v13]->triangles->numIndexes, a3: 4u);
      v21 = p_surfaces->list[v13]->triangles;
      idTriangles::AllocStaticTriSurfVerts(this: v21, numVerts: v21->numVerts);
      v22 = p_surfaces->list[v13]->triangles;
      idTriangles::AllocStaticTriSurfIndexes(this: v22, numIndexes: v22->numIndexes);
      v23 = p_surfaces->list[v13]->triangles;
      v40.file->Read(this: v40.file, a2: v23->verts, a3: 32 * v23->numVerts);
      v24 = p_surfaces->list[v13]->triangles;
      v40.file->Read(this: v40.file, a2: v24->indexes, a3: 2 * v24->numIndexes);
      ++v12;
      ++v13;
    }
    while ( v12 < this->surfaces.num );
  }
  v40.file->Read(this: v40.file, a2: &v41, a3: 4u);
  v25 = v41;
  if ( v41 <= this->sourceSurfaces.size
    || (unsigned __int8)idList<sourceSurface_t,5>::Resize(
                          this: (idList<cm_buildMaterial_t,13> *)&this->sourceSurfaces,
                          newsize: v41) != 0 )
  {
    size = this->sourceSurfaces.size;
    if ( v25 < size )
      size = v25;
    this->sourceSurfaces.num = size;
  }
  v27 = 0;
  if ( this->sourceSurfaces.num > 0 )
  {
    v28 = 0;
    do
    {
      v29 = &this->sourceSurfaces.list[v28];
      idFile::ReadString(this: v40.file, string: &v44);
      if ( v44.data != nullptr )
        v30 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v44.data, makeDefault: true);
      else
        v30 = nullptr;
      v29->mtr = (const idMaterial *)v30;
      v40.file->Read(this: v40.file, a2: &v29->mtrChecksum, a3: 4u);
      v40.file->Read(this: v40.file, a2: &v29->renderSurface, a3: 4u);
      v40.file->Read(this: v40.file, a2: &v29->firstVertex, a3: 4u);
      v40.file->Read(this: v40.file, a2: &v29->lastVertex, a3: 4u);
      ++v27;
      ++v28;
    }
    while ( v27 < this->sourceSurfaces.num );
  }
  v31 = 0;
  if ( this->traceModels.num > 0 )
  {
    v32 = 0;
    do
    {
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->traceModels.list[v32]);
      ++v31;
      ++v32;
    }
    while ( v31 < this->traceModels.num );
  }
  v40.file->Read(this: v40.file, a2: &v41, a3: 4u);
  if ( v41 > 0 )
  {
    v45[0].allocedAndFlag = 20;
    v45[0].len = 0;
    v45[0].data = v45[0].baseBuffer;
    v45[0].baseBuffer[0] = 0;
    idFile::ReadString(this: v40.file, string: v45);
    Model = idCollisionModelManager::LoadModel(this: collisionModelManager, modelName: v45[0].data);
    this->baseModel = Model;
    if ( Model == nullptr )
    {
      idDiscreteAnimationModelData::FreeData(this);
      idStr::FreeData(this: v45);
      idStr::FreeData(this: &v44);
      idFileLocal::~idFileLocal(this: &v40);
      return 0;
    }
    idStr::FreeData(this: v45);
  }
  idStr::FreeData(this: &v44);
  idFileLocal::~idFileLocal(this: &v40);
  return 1;
}


// ========================================================================
// __unwind$225892_0
// EA  : 0x827CFC44
// RVA : 0x007CFC44
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_225892_0()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$225893
// EA  : 0x827CFC6C
// RVA : 0x007CFC6C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_225893()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$225895
// EA  : 0x827CFC94
// RVA : 0x007CFC94
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_225895()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 92), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$225896
// EA  : 0x827CFCC0
// RVA : 0x007CFCC0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_225896()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// ?Generate@idDiscreteAnimationModelData@@AAA_NPBD@Z
// EA  : 0x827CFCF0
// RVA : 0x007CFCF0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

int __fastcall idDiscreteAnimationModelData::Generate(
        idDiscreteAnimationModelData *this,
        const char *baseCollisionName)
{
  const char *v2; // r24
  char *v3; // r17
  int v4; // r14
  double v5; // fp31
  idMem *k; // r19
  idStaticModel *v9; // r3
  int v10; // r18
  idStaticModel *v11; // r15
  const idMaterial **p_material; // r10
  idMaterial *v13; // r3
  const idMaterial *v14; // r3
  float *p_y; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  double v18; // fp13
  int v19; // r16
  double v20; // fp12
  double v21; // fp11
  int v22; // r27
  double v23; // fp10
  int v24; // r22
  float x; // r23
  double v26; // fp9
  int v27; // r26
  int v28; // r25
  idStaticModelSurface *v29; // r30
  const idMaterial *material; // r3
  idTriangles *geometry; // r29
  const idMaterial *v32; // r28
  float *v33; // r25
  int v34; // r26
  float *v35; // r28
  int v36; // r29
  int v37; // r30
  idList<idTraceModel,59> *p_traceModels; // r28
  int size; // r11
  int v40; // r3
  int v41; // r11
  float v42; // r27
  const char *str; // r4
  idList<idTraceModel,59> *v44; // r29
  int v45; // r30
  int v46; // r30
  int num; // r10
  int j; // r11
  int v49; // r11
  float *v50; // r4
  int v51; // r22
  int v52; // r21
  idTraceModel *v53; // r3
  double Radius; // fp1
  float *v55; // r11
  int materialNum; // r24
  float *v57; // r11
  int v58; // r23
  idStaticModelSurface *v59; // r11
  idCollisionModelLocal *v60; // r3
  idTriangles *v61; // r30
  float v62; // r3
  float v63; // r10
  int v64; // r11
  char *indexes; // r3
  int v66; // r11
  char *v67; // r10
  char *v68; // r9
  idDrawVert *verts; // r28
  int numVerts; // r9
  int v71; // r8
  int v72; // r11
  double v73; // fp8
  int *v74; // r3
  int *v75; // r30
  idTriangles *v76; // r3
  float *v77; // r3
  int v78; // r11
  float v80; // [sp+50h] [-1E0h]
  int v81; // [sp+5Ch] [-1D4h]
  int v82; // [sp+60h] [-1D0h]
  int v83; // [sp+64h] [-1CCh] BYREF
  int v84; // [sp+68h] [-1C8h]
  idMat3 v85; // [sp+70h] [-1C0h] BYREF
  float v86; // [sp+94h] [-19Ch]
  float v87; // [sp+98h] [-198h]
  float v88; // [sp+9Ch] [-194h]
  int v89; // [sp+A0h] [-190h]
  float v90; // [sp+A4h] [-18Ch]
  int *v91; // [sp+A8h] [-188h] BYREF
  idList<idTraceModel,59> *v92; // [sp+ACh] [-184h]
  idStr v93; // [sp+B0h] [-180h] BYREF
  idVec3 v94; // [sp+D0h] [-160h] BYREF
  idVec3 v95[4]; // [sp+DCh] [-154h] BYREF
  int v96[32]; // [sp+110h] [-120h] BYREF

  k = &mem;
  LODWORD(v85.mat[1].x) = &mem;
  v92 = (idList<idTraceModel,59> *)"w:\\tech5\\shared\\idlib\\Heap.h(64) : tag";
  v9 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_FXPHYSICS,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v10 = 0;
  if ( v9 != nullptr )
    v11 = idStaticModel::idStaticModel(this: v9);
  else
    v11 = nullptr;
  idResource::SetName(this: v11, _name: this->name.str);
  idStaticModel::PristineLoadResource(this: v11);
  if ( v11->resourceError != nullptr || v11->surfaces.num == 0 )
  {
_LN443:
    ((void (__fastcall *)(idStaticModel *, int))v11->dtr_idResource)(a1: v11, a2: 1);
    idLib::Warning(fmt: "idRenderModelDiscreteAnimation: Couldn't load model: %s", this->name.str);
    return 0;
  }
  else
  {
    this->timestamp = v11->sourceTimeStamp;
    p_material = &v11->surfaces.list->material;
    v13 = *p_material;
    this->material = *p_material;
    v14 = idMaterial::CompatibleGenericMaterial(this: v13);
    if ( v14 != nullptr )
      this->material = v14;
    p_y = &v85.mat[2].y;
    p_modelIsAutosprite = &v11->modelIsAutosprite;
    for ( i = 6; i != 0; --i )
    {
      p_modelIsAutosprite += 4;
      *++p_y = *(float *)p_modelIsAutosprite;
    }
    v18 = v86;
    v19 = 0;
    v20 = v87;
    v21 = v88;
    this->bounds.b[0].x = v85.mat[2].z;
    v22 = 0;
    v23 = *(float *)&v89;
    this->bounds.b[0].y = v18;
    v24 = 0;
    this->bounds.b[0].z = v20;
    v81 = 0;
    this->bounds.b[1].x = v21;
    x = 0.0;
    v26 = v90;
    v27 = 0;
    this->bounds.b[1].y = v23;
    this->bounds.b[1].z = v26;
    if ( v11->surfaces.num > 0 )
    {
      v28 = 0;
      v2 = "idRenderModelDiscreteAnimation: material '%s' and '%s' are not compatible generic materials on '%s'";
      do
      {
        v29 = &v11->surfaces.list[v28];
        material = v29->material;
        if ( v29->material->coverage == MC_INVISIBLE )
          break;
        geometry = v29->geometry;
        if ( material != this->material )
        {
          v32 = this->material;
          if ( idMaterial::CompatibleGenericMaterial(this: material) != v32 )
            idLib::Warning(
              fmt: "idRenderModelDiscreteAnimation: material '%s' and '%s' are not compatible generic materials on '%s'",
              v32->name.str,
              v29->material->name.str,
              v11->name.str);
        }
        ++v22;
        v24 += geometry->numIndexes;
        v19 += geometry->numVerts;
        if ( v27 > 0 && v29->materialNum == v11->surfaces.list[v28 - 1].materialNum )
          ++LODWORD(x);
        ++v27;
        ++v28;
      }
      while ( v27 < v11->surfaces.num );
      v81 = v19;
    }
    v33 = (float *)(v22 - LODWORD(x));
    LODWORD(v85.mat[1].y) = v22 - LODWORD(x);
    v34 = (int)idDeclInfo::FindWithInheritance(
                 this: &idDeclRenderParm::resourceList,
                 name: "surfaceFlags",
                 makeDefault: true);
    if ( v22 < v11->surfaces.num )
    {
      v35 = nullptr;
      v36 = v22;
      v37 = v22;
      while ( (idParmBlock::GetInteger(
                 this: &v11->surfaces.list[v37].material->parmBlock,
                 parm: (const idDeclRenderParm *)v34)
             & 0x40) != 0 )
      {
        ++v36;
        v35 = (float *)((char *)v35 + 1);
        ++v37;
        if ( v36 >= v11->surfaces.num )
        {
          if ( v35 == v33 )
            goto _LN440;
          idLib::Error(
            fmt: "idRenderModelDiscreteAnimation: '%s' must have the same number of collision surfaces as visible surfaces on '%s'",
            v11->name.str,
            this->name.str);
          break;
        }
      }
      idLib::Error(
        fmt: "idRenderModelDiscreteAnimation: all invisible '%s' surfaces must be collision surfaces on '%s'",
        v11->name.str,
        this->name.str);
    }
_LN440:
    p_traceModels = &this->traceModels;
    v83 = 32;
    if ( (int)v33 <= this->traceModels.size
      || (unsigned __int8)idList<idTraceModel,59>::Resize(this: &this->traceModels, newsize: v22 - LODWORD(x)) != 0 )
    {
      size = this->traceModels.size;
      if ( (int)v33 < size )
        size = v22 - LODWORD(x);
      this->traceModels.num = size;
    }
    *(float *)&v40 = COERCE_FLOAT(
                       idCollisionModelManager::CompoundTrmFromModel(
                         this: collisionModelManager,
                         modelName: v11->name.str,
                         trms: p_traceModels->list,
                         maxTrms: this->traceModels.num,
                         invalidSubmodelIndices: v96,
                         numInvalidIndices: &v83));
    v41 = v83;
    v42 = *(float *)&v40;
    this->baseModel = nullptr;
    v80 = *(float *)&v40;
    if ( v41 > 0 )
    {
      v93.len = 0;
      v93.baseBuffer[0] = 0;
      v93.allocedAndFlag = 20;
      v93.data = v93.baseBuffer;
      if ( baseCollisionName != nullptr )
        str = baseCollisionName;
      else
        str = v11->name.str;
      idStr::operator=(this: &v93, text: str);
      idStr::StripFileExtension(this: &v93);
      idStr::Append(this: &v93, text: "_base");
      this->baseModel = idCollisionModelManager::BuildModel(
                          this: collisionModelManager,
                          modelName: v93.data,
                          staticModel: v11,
                          submodelIndices: v96,
                          numSubmodelIndices: v83);
      idStr::FreeData(this: &v93);
    }
    v44 = nullptr;
    if ( this->traceModels.num > 0 )
    {
      v45 = 0;
      while ( idTraceModel::IsClosedSurface(this: &p_traceModels->list[v45]) )
      {
        v44 = (idList<idTraceModel,59> *)((char *)v44 + 1);
        ++v45;
        if ( (int)v44 >= this->traceModels.num )
          goto LABEL_42;
      }
      idLib::Error(
        fmt: "idRenderModelDiscreteAnimation: '%s' surface %d is not a closed hull on '%s'",
        v11->name.str,
        v44,
        this->name.str);
_LN441:
      idLib::Error(
        fmt: "idRenderModelDiscreteAnimation: '%s' surface %d has one or more triangle flaps on '%s'",
        v11->name.str,
        v44,
        this->name.str);
      goto _LN442;
    }
LABEL_42:
    v44 = nullptr;
    if ( this->traceModels.num > 0 )
    {
      v46 = 0;
      while ( !idTraceModel::HasFlaps(this: &p_traceModels->list[v46]) )
      {
        v44 = (idList<idTraceModel,59> *)((char *)v44 + 1);
        ++v46;
        if ( (int)v44 >= this->traceModels.num )
          goto LABEL_46;
      }
      goto _LN441;
    }
LABEL_46:
    num = this->traceModels.num;
    for ( j = 0; j < num; ++j )
      ;
    if ( (int)v33 <= this->transforms.size
      || (unsigned __int8)idList<idJointMat,59>::Resize(this: &this->transforms, newsize: (int)v33) != 0 )
    {
      v49 = this->transforms.size;
      if ( (int)v33 < v49 )
        v49 = (int)v33;
      this->transforms.num = v49;
    }
    v3 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\models\\discreteanimation\\DiscreteAnimationModelData.cpp(409) : TAG_FXPHYSICS",
                   size: 2 * v24,
                   tag: TAG_FXPHYSICS,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v19 = (int)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\models\\discreteanimation\\DiscreteAnimationModelData.cpp(410) : TAG_FXPHYSICS",
                 size: 32 * v19,
                 tag: TAG_FXPHYSICS,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
    v4 = 0;
    if ( (int)v33 > 0 )
    {
      v44 = &this->traceModels;
      v84 = 0;
      v82 = 0;
      v33 = (float *)&mat3_identity;
      v5 = 1.0;
      do
      {
        v51 = v82;
        v34 = 0;
        v52 = v84;
        v42 = 0.0;
        for ( k = nullptr; (int)k < 74; ++k )
        {
          if ( (int)&k[v4] >= SLODWORD(v85.mat[1].y) )
            break;
          idTraceModel::GetMassProperties(
            this: (idTraceModel *)((char *)v44->list + v52),
            density: v5,
            mass: v50,
            centerOfMass: v95,
            inertiaTensor: &v85);
          v94.x = -v85.mat[0].x;
          v94.z = -v85.mat[0].z;
          v53 = (idTraceModel *)((char *)v44->list + v52);
          v94.y = -v85.mat[0].y;
          idTraceModel::Translate(this: v53, translation: &v94);
          Radius = idBounds::GetRadius(this: (idBounds *)((char *)&v44->list->bounds + v52));
          if ( Radius > this->maxRadius )
            this->maxRadius = Radius;
          v55 = (float *)((char *)this->transforms.list->mat + v51);
          materialNum = -1;
          v55[3] = v85.mat[0].x;
          v55[7] = v85.mat[0].y;
          v55[11] = v85.mat[0].z;
          v57 = (float *)((char *)this->transforms.list->mat + v51);
          *v57 = *v33;
          v57[1] = v33[3];
          v57[2] = v33[6];
          v57[4] = v33[1];
          v57[5] = v33[4];
          v57[6] = v33[7];
          v57[8] = v33[2];
          v57[9] = v33[5];
          v57[10] = v33[8];
          if ( v10 < v11->surfaces.num )
          {
            v58 = v10;
            do
            {
              v59 = &v11->surfaces.list[v58];
              if ( materialNum != -1 && v59->materialNum != materialNum )
                break;
              v60 = (idCollisionModelLocal *)v59->material;
              materialNum = v59->materialNum;
              if ( v59->material->coverage != MC_INVISIBLE )
              {
                if ( SLODWORD(v42) >= v81 )
                {
                  idLib::Error(
                    fmt: "idRenderModelDiscreteAnimation: invalid surface configuration. numVerts >= totalVerts '%s'",
                    v11->name.str);
                  goto _LN443;
                }
                v61 = v59->geometry;
                LODWORD(v85.mat[2].z) = v59->material;
                v62 = COERCE_FLOAT(idLexer::GetScriptP(this: v60));
                v63 = *(float *)&this->surfaces.num;
                v64 = v61->numVerts + LODWORD(v42);
                v86 = v62;
                v88 = v42;
                v87 = v63;
                v89 = v64 - 1;
                idList<sourceSurface_t,59>::Append(
                  this: (idList<cm_buildMaterial_t,13> *)&this->sourceSurfaces,
                  obj: (const cm_buildMaterial_t *)&v85.mat[2].z);
                indexes = (char *)v61->indexes;
                if ( indexes == nullptr )
                  indexes = (char *)idIndexBuffer::MapBuffer(this: &v61->indexBuffer, mapType: BM_READ);
                v66 = 0;
                if ( v61->numIndexes > 0 )
                {
                  v67 = indexes - 2;
                  v68 = &v3[2 * v34 - 2];
                  do
                  {
                    v67 += 2;
                    ++v66;
                    ++v34;
                    v68 += 2;
                    *(_WORD *)v68 = *(_WORD *)v67 + LOWORD(v42);
                  }
                  while ( v66 < v61->numIndexes );
                }
                if ( indexes != (char *)v61->indexes )
                  idIndexBuffer::UnmapBuffer(this: &v61->indexBuffer);
                verts = v61->verts;
                if ( verts == nullptr )
                  verts = (idDrawVert *)idVertexBuffer::MapBuffer(this: &v61->vertexBuffer, mapType: BM_READ);
                memcpy(Dst: (void *)(32 * LODWORD(v42) + v19), Src: verts, Size: 32 * v61->numVerts);
                numVerts = v61->numVerts;
                v71 = 0;
                if ( numVerts > 0 )
                {
                  v72 = 32 * LODWORD(v42) + v19 - 9;
                  do
                  {
                    ++v71;
                    *(float *)(v72 + 9) = *(float *)(v72 + 9) - v85.mat[0].x;
                    v73 = *(float *)(v72 + 17);
                    *(float *)(v72 + 13) = *(float *)(v72 + 13) - v85.mat[0].y;
                    *(float *)(v72 + 17) = (float)v73 - v85.mat[0].z;
                    *(_BYTE *)(v72 + 37) = (_BYTE)k;
                    *(_BYTE *)(v72 + 38) = (_BYTE)k;
                    *(_BYTE *)(v72 + 39) = (_BYTE)k;
                    *(_BYTE *)(v72 + 40) = (_BYTE)k;
                    v72 += 32;
                    *(_BYTE *)v72 = 0;
                    numVerts = v61->numVerts;
                  }
                  while ( v71 < numVerts );
                }
                LODWORD(v42) += numVerts;
                if ( verts != v61->verts )
                  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&v61->vertexBuffer);
                v44 = &this->traceModels;
              }
              ++v10;
              ++v58;
            }
            while ( v10 < v11->surfaces.num );
          }
          v52 += 1536;
          v51 += 48;
        }
        p_traceModels = v92;
        x = v85.mat[1].x;
        v74 = (int *)idMem::AllocWithLocation(
                       this: (idMem *)LODWORD(v85.mat[1].x),
                       location: (const char *)v92,
                       size: 0xCu,
                       tag: TAG_FXPHYSICS,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
        v2 = nullptr;
        if ( v74 != nullptr )
        {
          v75 = v74;
          *v74 = 0;
          v74[1] = 0;
          v74[2] = 0;
        }
        else
        {
_LN442:
          v75 = nullptr;
        }
        v91 = v75;
        v76 = (idTriangles *)idMem::AllocWithLocation(
                               this: (idMem *)LODWORD(x),
                               location: (const char *)p_traceModels,
                               size: 0x84u,
                               tag: TAG_TRIANGLES,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v76 != nullptr )
          v77 = (float *)idTriangles::idTriangles(this: v76);
        else
          v77 = (float *)v2;
        *v77 = this->bounds.b[0].x;
        v75[2] = (int)v77;
        v77[1] = this->bounds.b[0].y;
        v77[2] = this->bounds.b[0].z;
        v77[3] = this->bounds.b[1].x;
        v77[4] = this->bounds.b[1].y;
        v77[5] = this->bounds.b[1].z;
        *v75 = v4;
        v75[1] = (int)k;
        *(float *)(v75[2] + 32) = v42;
        *(_DWORD *)(v75[2] + 28) = v34;
        idTriangles::AllocStaticTriSurfVerts(this: (idTriangles *)v75[2], numVerts: SLODWORD(v42));
        idTriangles::AllocStaticTriSurfIndexes(this: (idTriangles *)v75[2], numIndexes: v34);
        memcpy(Dst: *(void **)(v75[2] + 88), Src: (const void *)v19, Size: 32 * LODWORD(v42));
        memcpy(Dst: *(void **)(v75[2] + 92), Src: v3, Size: 2 * v34);
        idTriangles::Cleanup(this: (idTriangles *)v75[2], optimize: true);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->surfaces,
          obj: (const encounterGroupRole_t *)&v91);
        v4 += 74;
        v82 += 3552;
        v84 += 113664;
      }
      while ( v4 < SLODWORD(v85.mat[1].y) );
      k = (idMem *)LODWORD(v85.mat[1].x);
      p_traceModels = &this->traceModels;
      v42 = v80;
    }
    idMem::Free(this: k, ptr: v3, align: ALIGN_16);
    idMem::Free(this: k, ptr: (void *)v19, align: ALIGN_16);
    ((void (__fastcall *)(idStaticModel *, int))v11->dtr_idResource)(a1: v11, a2: 1);
    if ( SLODWORD(v42) <= p_traceModels->size
      || (unsigned __int8)idList<idTraceModel,59>::Resize(this: p_traceModels, newsize: SLODWORD(v42)) != 0 )
    {
      v78 = p_traceModels->size;
      if ( SLODWORD(v42) < v78 )
        v78 = LODWORD(v42);
      p_traceModels->num = v78;
    }
    return 1;
  }
}


// ========================================================================
// $LN420
// EA  : 0x827D0740
// RVA : 0x007D0740
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _LN420()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 560 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// __unwind$226508
// EA  : 0x827D076C
// RVA : 0x007D076C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_226508()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 176));
}


// ========================================================================
// __unwind$226510
// EA  : 0x827D0794
// RVA : 0x007D0794
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_226510()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 560 + 88), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?LoadResource@idDiscreteAnimationModelData@@UAAXXZ
// EA  : 0x827D07C8
// RVA : 0x007D07C8
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::LoadResource(idDiscreteAnimationModelData *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // [sp+8h] [-188h]
  int v6; // [sp+Ch] [-184h]
  int v7; // [sp+10h] [-180h]
  int v8; // [sp+14h] [-17Ch]
  int v9; // [sp+18h] [-178h]
  int v10; // [sp+1Ch] [-174h]
  idStr v11; // [sp+50h] [-140h] BYREF
  char v12[264]; // [sp+70h] [-120h] BYREF

  idDiscreteAnimationModelData::FreeData(this);
  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  if ( idStr::Icmpn(s1: this->name.str, s2: "maps/", n: 5) != 0 )
  {
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "dmodel", a4: this->name.str, a5: v12, a6: 256);
    idStr::operator=(this: &v11, text: v12);
  }
  else
  {
    idStr::operator=(this: &v11, text: this->name.str);
    idStr::SetFileExtension(this: &v11, extension: "dmodel");
  }
  if ( (unsigned __int8)idDiscreteAnimationModelData::LoadBinary(this, fileName: v11.data) == 0 )
  {
    if ( (unsigned __int8)idDiscreteAnimationModelData::Generate(this, baseCollisionName: nullptr) == 0 )
    {
      HIDWORD(v4) = v11.data;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Couldn't load discreteanimationmodeldata '%s'",
        a3: v4,
        a4: v3,
        a5: v2,
        a6: v5,
        a7: v6,
        a8: v7,
        a9: v8,
        a10: v9,
        a11: v10);
      idDiscreteAnimationModelData::FreeData(this);
      goto LABEL_9;
    }
    idDiscreteAnimationModelData::WriteBinary(this, fileName: v11.data);
  }
  idDiscreteAnimationModelData::RemapSourceSurfaces(this);
  idDiscreteAnimationModelData::UpdateBuffers(this);
  if ( r_discretemodel_freecpudata.valueInteger != 0 )
    idDiscreteAnimationModelData::FreeCPUData(this);
LABEL_9:
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$227302
// EA  : 0x827D0924
// RVA : 0x007D0924
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// ??0idDiscreteAnimationModelData@@QAA@XZ
// EA  : 0x827D0958
// RVA : 0x007D0958
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

idDiscreteAnimationModelData *__fastcall idDiscreteAnimationModelData::idDiscreteAnimationModelData(
        idDiscreteAnimationModelData *this)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idDiscreteAnimationModelData_vtbl *)&idDiscreteAnimationModelData::`vftable';
  this->traceModels.list = nullptr;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 59;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->transforms.list = nullptr;
  this->transforms.granularity = 0;
  this->transforms.memTag = 59;
  this->transforms.listStatic = 0;
  this->transforms.size = 0;
  this->transforms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transforms);
  this->surfaces.list = nullptr;
  this->surfaces.granularity = 0;
  this->surfaces.memTag = 59;
  this->surfaces.listStatic = 0;
  this->surfaces.size = 0;
  this->surfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  this->sourceSurfaces.list = nullptr;
  this->sourceSurfaces.granularity = 0;
  this->sourceSurfaces.memTag = 59;
  this->sourceSurfaces.listStatic = 0;
  this->sourceSurfaces.size = 0;
  this->sourceSurfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  idDiscreteAnimationModelData::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$227455
// EA  : 0x827D0A1C
// RVA : 0x007D0A1C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227455()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$227456
// EA  : 0x827D0A44
// RVA : 0x007D0A44
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$227457
// EA  : 0x827D0A70
// RVA : 0x007D0A70
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$227458
// EA  : 0x827D0A9C
// RVA : 0x007D0A9C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// __unwind$227459
// EA  : 0x827D0AC8
// RVA : 0x007D0AC8
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// ??1idDiscreteAnimationModelData@@UAA@XZ
// EA  : 0x827D0B10
// RVA : 0x007D0B10
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __fastcall idDiscreteAnimationModelData::~idDiscreteAnimationModelData(idDiscreteAnimationModelData *this)
{
  this->__vftable = (idDiscreteAnimationModelData_vtbl *)&idDiscreteAnimationModelData::`vftable';
  idDiscreteAnimationModelData::FreeData(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transforms);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$227514
// EA  : 0x827D0B80
// RVA : 0x007D0B80
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227514()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$227515_0
// EA  : 0x827D0BA8
// RVA : 0x007D0BA8
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227515_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$227516
// EA  : 0x827D0BD4
// RVA : 0x007D0BD4
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$227517
// EA  : 0x827D0C00
// RVA : 0x007D0C00
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$227518
// EA  : 0x827D0C2C
// RVA : 0x007D0C2C
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void _unwind_227518()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 120));
}


// ========================================================================
// `dynamic initializer for 'idDiscreteAnimationModelData::resourceList''
// EA  : 0x833427E0
// RVA : 0x013427E0
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDiscreteAnimationModelData::resourceList__()
{
  idResourceList::idResourceList(this: &idDiscreteAnimationModelData::resourceList, typeName: "discreteAnimation");
  idDiscreteAnimationModelData::resourceList.__vftable = (idTypedResourceList<idDiscreteAnimationModelData>_vtbl *)&idTypedResourceList<idDiscreteAnimationModelData>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDiscreteAnimationModelData::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'r_discretemodel_freecpudata''
// EA  : 0x83342830
// RVA : 0x01342830
// PDB : w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_discretemodel_freecpudata__()
{
  idCVar::idCVar(
    this: &r_discretemodel_freecpudata,
    name: "r_discretemodel_freecpudata",
    value: "1",
    flags: 1,
    description: "Free Discrete Animatation model CPU data ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_discretemodel_freecpudata__);
}

