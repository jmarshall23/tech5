
// ========================================================================
// ?FreeCPUData@idRenderModelCuttableResource@@AAAXXZ
// EA  : 0x827C77A8
// RVA : 0x007C77A8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::FreeCPUData(idRenderModelCuttableResource *this)
{
  idTriangles *triangles; // r3
  idVec2 *stData; // r4

  triangles = this->triangles;
  if ( triangles != nullptr )
    idTriangles::FreeCPUData(this: triangles);
  stData = this->stData;
  if ( stData != nullptr )
  {
    idMem::Free(this: &mem, ptr: stData, align: ALIGN_16);
    this->stData = nullptr;
  }
}


// ========================================================================
// ?ReloadIfStale@idRenderModelCuttableResource@@UAA_NXZ
// EA  : 0x827C7808
// RVA : 0x007C7808
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

int __fastcall idRenderModelCuttableResource::ReloadIfStale(idRenderModelCuttableResource *this)
{
  __int64 v2; // r10
  __int64 v3; // r6
  unsigned int v4; // r3
  __int64 v5; // r8
  int v7; // [sp+8h] [-168h]
  int v8; // [sp+Ch] [-164h]
  int v9; // [sp+10h] [-160h]
  int v10; // [sp+14h] [-15Ch]
  int v11; // [sp+18h] [-158h]
  int v12; // [sp+1Ch] [-154h]
  _BYTE v13[264]; // [sp+50h] [-120h] BYREF

  fileSystem->FixLongFilename(this: fileSystem, a2: &byte_8200D768, a3: "cmodel", a4: this->name.str, a5: v13, a6: 256);
  v4 = fileSystem->GetTimestamp(this: fileSystem, a2: v13, a3: false);
  LODWORD(v5) = this->timestamp;
  if ( v4 == (_DWORD)v5 )
    return 0;
  idResource::SetResourceError(
    this,
    fmt: nullptr,
    a3: v3,
    a4: v5,
    a5: v2,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12);
  fileSystem->RemoveFile(this: fileSystem, a2: v13, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?FreeData@idRenderModelCuttableResource@@AAAXXZ
// EA  : 0x827C78E8
// RVA : 0x007C78E8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::FreeData(idRenderModelCuttableResource *this)
{
  idTriangles *triangles; // r30
  idVertexBuffer *stMap; // r30
  idVec2 *stData; // r4

  triangles = this->triangles;
  if ( triangles != nullptr )
  {
    idTriangles::~idTriangles(this: this->triangles);
    idMem::Free(this: &mem, ptr: triangles, align: ALIGN_16);
    this->triangles = nullptr;
  }
  stMap = this->stMap;
  if ( stMap != nullptr )
  {
    idVertexBuffer::~idVertexBuffer(this: this->stMap);
    idMem::Free(this: &mem, ptr: stMap, align: ALIGN_16);
    this->stMap = nullptr;
  }
  stData = this->stData;
  if ( stData != nullptr )
  {
    idMem::Free(this: &mem, ptr: stData, align: ALIGN_16);
    this->stData = nullptr;
  }
  this->sourceMaterial = nullptr;
  this->material = nullptr;
  this->timestamp = -1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contourBound);
  idTriangleInterpolator::Clear(this: &this->triangleInterpolator);
}


// ========================================================================
// ??1idRenderModelCuttableResource@@UAA@XZ
// EA  : 0x827C79A0
// RVA : 0x007C79A0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::~idRenderModelCuttableResource(idRenderModelCuttableResource *this)
{
  this->__vftable = (idRenderModelCuttableResource_vtbl *)&idRenderModelCuttableResource::`vftable';
  idRenderModelCuttableResource::FreeData(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triangleInterpolator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contourBound);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$221026
// EA  : 0x827C7A00
// RVA : 0x007C7A00
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221026()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221027
// EA  : 0x827C7A28
// RVA : 0x007C7A28
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221027()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$221028
// EA  : 0x827C7A54
// RVA : 0x007C7A54
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221028()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// ?BuildDepthSurface@idRenderModelCuttableResource@@AAAXPAVidRenderModelSurface@@@Z
// EA  : 0x827C7A98
// RVA : 0x007C7A98
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::BuildDepthSurface(
        idRenderModelCuttableResource *this,
        idRenderModelSurface *surface)
{
  const idMaterial *sourceMaterial; // r11
  const char *String; // r29
  idStr *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r8
  va *v10; // r3
  char *data; // r11
  const idMaterial *v12; // r30
  const idDecl *v13; // r3
  idDecl *v14; // r30
  int v15; // [sp+8h] [-1228h]
  int v16; // [sp+Ch] [-1224h]
  int v17; // [sp+10h] [-1220h]
  int v18; // [sp+14h] [-121Ch]
  int v19; // [sp+18h] [-1218h]
  int v20; // [sp+1Ch] [-1214h]
  idStr v21; // [sp+50h] [-11E0h] BYREF
  idStr v22; // [sp+70h] [-11C0h] BYREF
  idStr v23; // [sp+90h] [-11A0h] BYREF
  idFile_Memory v24; // [sp+B0h] [-1180h] BYREF
  va v25; // [sp+200h] [-1030h] BYREF

  if ( this->stMap != nullptr && (sourceMaterial = this->sourceMaterial) != nullptr )
  {
    if ( idParmBlock::SetsRenderParm(this: &sourceMaterial->parmBlock, parm: rp->coverMap) )
    {
      String = idParmBlock::GetString(this: &this->sourceMaterial->parmBlock, parm: rp->coverMap);
      idStr::idStr(this: &v21, text: this->name.str);
      idStr::StripFileExtension(this: &v21);
      v6 = operator+(result: &v23, a: &v21, b: "_cover");
      idStr::operator=(this: &v21, text: v6);
      idStr::FreeData(this: &v23);
      LODWORD(v7) = &unk_82200000;
      HIDWORD(v8) = v21.data;
      v10 = va::va(
              this: &v25,
              fmt: "generated/cuttable/m2/%s.m2",
              a3: v8,
              a4: v9,
              a5: v7,
              a6: v15,
              a7: v16,
              a8: v17,
              a9: v18,
              a10: v19,
              a11: v20);
      idStr::idStr(this: &v22, text: v10);
      idFile_Memory::idFile_Memory(this: &v24);
      idFile::Printf(this: &v24, fmt: "{\n");
      idFile::Printf(this: &v24, fmt: "\tambientProgram cutDepthOnly\n");
      idFile::Printf(this: &v24, fmt: "\tdepthFillProgram cutDepthOnly\n");
      idFile::Printf(this: &v24, fmt: "\ttextureMap \"%s\"\n", String);
      idFile::Printf(this: &v24, fmt: "}\n");
      data = v21.data;
      if ( v21.data != nullptr )
      {
        v13 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v21.data, makeDefault: false);
        data = v21.data;
        v12 = (const idMaterial *)v13;
      }
      else
      {
        v12 = nullptr;
      }
      if ( v12 != nullptr )
      {
        idDecl::SetText(this: &v12->idDecl, text: v24.filePtr, length: 0);
        idDecl::ReplaceSourceFileText(this: &v12->idDecl, useSourceControl: false);
        idDecl::ReParse(this: &v12->idDecl, fromDisk: true);
      }
      else
      {
        v14 = declManager->CreateNewDecl(
                this: declManager,
                a2: &idMaterial::resourceList,
                a3: data,
                a4: v22.data,
                a5: v24.filePtr);
        idDecl::ReplaceSourceFileText(this: v14, useSourceControl: false);
        idResourceList::Remove(this: &idMaterial::resourceList, ptr: v14);
        if ( v14 != nullptr )
          ((void (__fastcall *)(idDecl *, int))v14->dtr_idResource)(a1: v14, a2: 1);
        v12 = (const idMaterial *)idResourceList::Load(
                                    this: &idMaterial::resourceList,
                                    name: v21.data,
                                    makeDefault: true,
                                    skipStaleCheck: false);
      }
      surface->material = v12;
      idFile_Memory::~idFile_Memory(this: &v24);
      idStr::FreeData(this: &v22);
      idStr::FreeData(this: &v21);
    }
  }
  else
  {
    idLib::Warning(fmt: "Couldn't build depth-only surface, re-compile cuttables to create original uv-set");
  }
}


// ========================================================================
// __unwind$221076
// EA  : 0x827C7CD0
// RVA : 0x007C7CD0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4656 + 80));
}


// ========================================================================
// __unwind$221077
// EA  : 0x827C7CF8
// RVA : 0x007C7CF8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221077()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4656 + 144));
}


// ========================================================================
// __unwind$221078
// EA  : 0x827C7D20
// RVA : 0x007C7D20
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221078()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4656 + 112));
}


// ========================================================================
// __unwind$221079
// EA  : 0x827C7D48
// RVA : 0x007C7D48
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221079()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 4656 + 176));
}


// ========================================================================
// ??0idRenderModelCuttableResource@@QAA@XZ
// EA  : 0x827C7D78
// RVA : 0x007C7D78
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

idRenderModelCuttableResource *__fastcall idRenderModelCuttableResource::idRenderModelCuttableResource(
        idRenderModelCuttableResource *this)
{
  idResource::idResource(this);
  this->sourceMaterial = nullptr;
  this->__vftable = (idRenderModelCuttableResource_vtbl *)&idRenderModelCuttableResource::`vftable';
  this->material = nullptr;
  this->triangles = nullptr;
  this->stData = nullptr;
  this->stMap = nullptr;
  this->contourBound.list = nullptr;
  this->contourBound.granularity = 0;
  this->contourBound.memTag = 5;
  this->contourBound.listStatic = 0;
  this->contourBound.size = 0;
  this->contourBound.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contourBound);
  this->triangleInterpolator.triangles.list = nullptr;
  this->triangleInterpolator.triangles.granularity = 0;
  this->triangleInterpolator.triangles.memTag = 5;
  this->triangleInterpolator.triangles.listStatic = 0;
  this->triangleInterpolator.triangles.size = 0;
  this->triangleInterpolator.triangles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triangleInterpolator);
  this->timestamp = -1;
  return this;
}


// ========================================================================
// __unwind$221238
// EA  : 0x827C7E10
// RVA : 0x007C7E10
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221238()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221239
// EA  : 0x827C7E38
// RVA : 0x007C7E38
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221239()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// ?LoadBinary@idRenderModelCuttableResource@@AAA_NPBD@Z
// EA  : 0x827C7ED0
// RVA : 0x007C7ED0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

int __fastcall idRenderModelCuttableResource::LoadBinary(idRenderModelCuttableResource *this, const char *fileName)
{
  idFile *v4; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r3
  int numVerts; // r11
  unsigned int v9; // r5
  idVec2 *v10; // r3
  unsigned int v11; // r10
  idTriangles *triangles; // r11
  int v13; // r9
  int v14; // r10
  idVec2 *v15; // r11
  const idMaterial *v16; // r11
  idFileLocal v17; // [sp+50h] [-90h] BYREF
  unsigned int v18; // [sp+54h] [-8Ch] BYREF
  int v19[2]; // [sp+58h] [-88h] BYREF
  idStr v20; // [sp+60h] [-80h] BYREF
  idStr v21[3]; // [sp+80h] [-60h] BYREF

  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v17.file = v4;
  if ( v4 != nullptr )
  {
    v18 = 0;
    v4->Read(this: v4, a2: &v18, a3: 4u);
    if ( v18 == 122441027 || v18 == 105663811 || v18 == 88886595 )
    {
      v19[0] = 0;
      v17.file->Read(this: v17.file, a2: v19, a3: 4u);
      idList<idVec3,37>::SetNum(this: &this->contourBound, newNum: v19[0]);
      v17.file->Read(this: v17.file, a2: this->contourBound.list, a3: 12 * v19[0]);
      v21[0].len = 0;
      v21[0].baseBuffer[0] = 0;
      v21[0].allocedAndFlag = 20;
      v21[0].data = v21[0].baseBuffer;
      idFile::ReadString(this: v17.file, string: v21);
      v20.allocedAndFlag = 20;
      v20.data = v20.baseBuffer;
      v20.len = 0;
      v20.baseBuffer[0] = 0;
      if ( v18 >= 0x74C4D43 )
        idFile::ReadString(this: v17.file, string: &v20);
      v6 = (idTriangles *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x84u,
                            tag: TAG_TRIANGLES,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      v19[1] = (int)v6;
      if ( v6 != nullptr )
        v7 = idTriangles::idTriangles(this: v6);
      else
        v7 = nullptr;
      this->triangles = v7;
      idTriangles::ReadFromFile(this: v7, file: v17.file);
      numVerts = this->triangles->numVerts;
      if ( numVerts > 0 )
      {
        v9 = 8 * numVerts;
        if ( (unsigned int)numVerts > 0x1FFFFFFF )
          v9 = -1;
        v10 = (idVec2 *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                          size: v9,
                          tag: TAG_RESOURCE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
        v11 = v18;
        triangles = this->triangles;
        this->stData = v10;
        if ( v11 < 0x64C4D43 )
        {
          v13 = 0;
          if ( triangles->numVerts > 0 )
          {
            v14 = 0;
            do
            {
              ++v13;
              v15 = &this->stData[v14++];
              *v15 = vec2_origin;
            }
            while ( v13 < this->triangles->numVerts );
          }
        }
        else
        {
          v17.file->Read(this: v17.file, a2: v10, a3: 8 * triangles->numVerts);
        }
      }
      if ( v18 < 0x74C4D43 )
      {
        this->sourceMaterial = nullptr;
      }
      else if ( v20.data != nullptr )
      {
        this->sourceMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                     this: &idMaterial::resourceList,
                                                     name: v20.data,
                                                     makeDefault: true);
      }
      else
      {
        this->sourceMaterial = nullptr;
      }
      if ( v21[0].data != nullptr )
        v16 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                    this: &idMaterial::resourceList,
                                    name: v21[0].data,
                                    makeDefault: true);
      else
        v16 = nullptr;
      this->material = v16;
      this->timestamp = v17.file->Timestamp(this: v17.file);
      idStr::FreeData(this: &v20);
      idStr::FreeData(this: v21);
      idFileLocal::~idFileLocal(this: &v17);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "idRenderModelCuttableResource::LoadBinary - Bad magic!");
      idFileLocal::~idFileLocal(this: &v17);
      return 0;
    }
  }
  else
  {
    idLib::Warning(
      fmt: "idRenderModelCuttableResource::LoadBinary - Couldn't load cuttable '%s', unable to open file for reading!",
      fileName);
    idFileLocal::~idFileLocal(this: &v17);
    return 0;
  }
}


// ========================================================================
// __unwind$221491
// EA  : 0x827C820C
// RVA : 0x007C820C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221491()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$221492
// EA  : 0x827C8234
// RVA : 0x007C8234
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221492()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$221493
// EA  : 0x827C825C
// RVA : 0x007C825C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221493()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$221494
// EA  : 0x827C8284
// RVA : 0x007C8284
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221494()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 92), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?BuildSurface@idRenderModelCuttableResource@@QAAXPAVidRenderModel@@@Z
// EA  : 0x827C82B8
// RVA : 0x007C82B8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::BuildSurface(idRenderModelCuttableResource *this, idRenderModel *model)
{
  unsigned __int64 v2; // r29
  const idMaterial *material; // r11
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  float *v7; // r11
  float *v8; // r11
  idIndexBuffer *v9; // r3
  idVertexBuffer *v10; // r3
  const idVertexBuffer *v11; // r4
  idRenderModelSurface v12; // [sp+70h] [-C0h] BYREF
  const idMaterial *v13; // [sp+B0h] [-80h]
  idRenderModelSurface *v14; // [sp+B4h] [-7Ch]
  idTriangles *v15; // [sp+C0h] [-70h]
  char v16; // [sp+C4h] [-6Ch]
  char v17; // [sp+C5h] [-6Bh]
  int v18; // [sp+C8h] [-68h]
  int v19; // [sp+CCh] [-64h]
  int v20; // [sp+D0h] [-60h]
  int v21; // [sp+D4h] [-5Ch]
  float v22; // [sp+D8h] [-58h]
  float v23; // [sp+DCh] [-54h]
  float v24; // [sp+E0h] [-50h]
  float v25; // [sp+E4h] [-4Ch]

  HIDWORD(v2) = this;
  if ( this->triangles != nullptr )
  {
    material = this->material;
    LODWORD(v2) = 0;
    v14 = nullptr;
    v15 = nullptr;
    v13 = material;
    v22 = 0.0;
    v16 = 0;
    v23 = 0.0;
    v17 = 0;
    v24 = 0.0;
    v18 = 0;
    v25 = 0.0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    if ( material != nullptr )
    {
      v12.skinOffsets.x = 0.0;
      v12.skinOffsets.y = 0.0;
      v12.materialNum = 0;
      v12.skinOffsets.z = 0.0;
      v12.skinOffsets.w = 0.0;
      v12.geometry = nullptr;
      v12.geometryIsReference = false;
      v12.referenceMask = 0;
      memset(&v12.binaryModelId, 0, 16);
      v12.material = nullptr;
      v12.extraGLState = v2;
      if ( g_cuttablemodel_buildepthonly.valueInteger != 0 )
        idRenderModelCuttableResource::BuildDepthSurface(this, surface: &v12);
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
      v7 = *(float **)(HIDWORD(v2) + 44);
      v6->bounds.b[0].x = *v7;
      v6->bounds.b[0].y = v7[1];
      v6->bounds.b[0].z = v7[2];
      v6->bounds.b[1].x = v7[3];
      v6->bounds.b[1].y = v7[4];
      v6->bounds.b[1].z = v7[5];
      v6->generateNormals = false;
      *(_QWORD *)&v6->numIndexes = *(_QWORD *)(*(_DWORD *)(HIDWORD(v2) + 44) + 28);
      v6->detailOffset = *(_DWORD *)(*(_DWORD *)(HIDWORD(v2) + 44) + 36);
      v6->vertexMask = *(_DWORD *)(*(_DWORD *)(HIDWORD(v2) + 44) + 96);
      v8 = (float *)(*(_DWORD *)(HIDWORD(v2) + 44) + 44);
      v6->vsb.xyzScale.x = *v8;
      v6->vsb.xyzScale.y = v8[1];
      v6->vsb.xyzScale.z = v8[2];
      v6->vsb.xyzBias.x = v8[3];
      v6->vsb.xyzBias.y = v8[4];
      v6->vsb.xyzBias.z = v8[5];
      v6->vsb.stScale.x = v8[6];
      v6->vsb.stScale.y = v8[7];
      v6->vsb.stBias.x = v8[8];
      v6->vsb.stBias.y = v8[9];
      v6->verts = nullptr;
      v6->indexes = nullptr;
      idVertexBuffer::Reference(
        this: &v6->vertexBuffer,
        other: (const idVertexBuffer *)(*(_DWORD *)(HIDWORD(v2) + 44) + 100));
      idIndexBuffer::Reference(
        this: &v6->indexBuffer,
        other: (const idIndexBuffer *)(*(_DWORD *)(HIDWORD(v2) + 44) + 116));
      idTriangles::CreateBounds(this: v6);
      v15 = v6;
      if ( v12.material != nullptr )
      {
        v12.geometry = v6;
        v12.referenceMask = 0;
        v12.geometryIsReference = true;
        v9 = (idIndexBuffer *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x10u,
                                tag: TAG_RENDERMODEL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        if ( v9 != nullptr )
          v10 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v9);
        else
          v10 = nullptr;
        v11 = *(const idVertexBuffer **)(HIDWORD(v2) + 52);
        v12.stMap = v10;
        idVertexBuffer::Reference(this: v10, other: v11);
        idRenderModel::AddSurface(this: (idRenderModel *)v12.material, surf: (idRenderModelSurface *)v12.materialNum);
      }
      idRenderModel::AddSurface(this: model, surf: v14);
    }
  }
}


// ========================================================================
// __unwind$221748
// EA  : 0x827C85B0
// RVA : 0x007C85B0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221748()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$221749
// EA  : 0x827C85DC
// RVA : 0x007C85DC
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221749()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 96), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?LoadResource@idRenderModelCuttableResource@@UAAXXZ
// EA  : 0x827C86B8
// RVA : 0x007C86B8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __fastcall idRenderModelCuttableResource::LoadResource(idRenderModelCuttableResource *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  unsigned int v8; // r3
  idTriangles *triangles; // r11
  idIndexBuffer *v10; // r3
  idVertexBuffer *v11; // r3
  int v12; // [sp+8h] [-178h]
  int v13; // [sp+Ch] [-174h]
  int v14; // [sp+10h] [-170h]
  int v15; // [sp+14h] [-16Ch]
  int v16; // [sp+18h] [-168h]
  int v17; // [sp+1Ch] [-164h]
  char v18[288]; // [sp+60h] [-120h] BYREF

  idRenderModelCuttableResource::FreeData(this);
  fileSystem->FixLongFilename(this: fileSystem, a2: &byte_8200D768, a3: "cmodel", a4: this->name.str, a5: v18, a6: 256);
  LODWORD(v3) = fileSystem->FileExists(this: fileSystem, a2: v18, a3: false);
  if ( (_DWORD)v3 != 0 )
  {
    if ( (unsigned __int8)idRenderModelCuttableResource::LoadBinary(this, fileName: v18) != 0 )
    {
      v8 = fileSystem->GetTimestamp(this: fileSystem, a2: v18, a3: false);
      triangles = this->triangles;
      this->timestamp = v8;
      if ( triangles != nullptr )
      {
        idTriangleInterpolator::AddTriangles(
          this: &this->triangleInterpolator,
          verts: triangles->verts,
          st: this->stData,
          indices: triangles->indexes,
          numIndices: triangles->numIndexes);
        idTriangles::UpdateVertexBuffer(this: this->triangles);
        idTriangles::UpdateIndexBuffer(this: this->triangles);
      }
      if ( this->stData != nullptr )
      {
        v10 = (idIndexBuffer *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x10u,
                                 tag: TAG_RESOURCE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        if ( v10 != nullptr )
          v11 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v10);
        else
          v11 = nullptr;
        this->stMap = v11;
        idVertexBuffer::AllocBufferObject(
          this: v11,
          data: this->stData,
          allocSize: 8 * this->triangles->numVerts,
          vertexMask: 9216,
          allocUsage: BU_DYNAMIC);
      }
      if ( r_cuttablemodel_freecpudata.valueInteger != 0 )
        idRenderModelCuttableResource::FreeCPUData(this);
    }
    else
    {
      HIDWORD(v7) = v18;
      idResource::SetResourceError(
        this,
        fmt: "Binary file corrupt or inaccessible '%s'",
        a3: v7,
        a4: v6,
        a5: v5,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17);
    }
  }
  else
  {
    HIDWORD(v4) = v18;
    idResource::SetResourceError(
      this,
      fmt: "missing file '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v12,
      a7: v13,
      a8: v14,
      a9: v15,
      a10: v16,
      a11: v17);
  }
}


// ========================================================================
// __unwind$221885
// EA  : 0x827C8854
// RVA : 0x007C8854
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void _unwind_221885()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelCuttableResource::resourceList''
// EA  : 0x833423E8
// RVA : 0x013423E8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelCuttableResource::resourceList__()
{
  idResourceList::idResourceList(this: &idRenderModelCuttableResource::resourceList, typeName: "cuttableResource");
  idRenderModelCuttableResource::resourceList.__vftable = (idTypedResourceList<idRenderModelCuttableResource>_vtbl *)&idTypedResourceList<idRenderModelCuttableResource>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelCuttableResource::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'r_cuttablemodel_freecpudata''
// EA  : 0x83342438
// RVA : 0x01342438
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_cuttablemodel_freecpudata__()
{
  idCVar::idCVar(
    this: &r_cuttablemodel_freecpudata,
    name: "r_cuttablemodel_freecpudata",
    value: "1",
    flags: 1,
    description: "Free cuttable model CPU data",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_cuttablemodel_freecpudata__);
}


// ========================================================================
// `dynamic initializer for 'g_cuttablemodel_buildepthonly''
// EA  : 0x83342490
// RVA : 0x01342490
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttableresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_cuttablemodel_buildepthonly__()
{
  idCVar::idCVar(
    this: &g_cuttablemodel_buildepthonly,
    name: "g_cuttablemodel_buildepthonly",
    value: "1",
    flags: 1,
    description: "Build seperate physical texture depth only pass",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_cuttablemodel_buildepthonly__);
}

