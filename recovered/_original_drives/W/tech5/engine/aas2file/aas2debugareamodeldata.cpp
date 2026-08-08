
// ========================================================================
// `idAAS2DebugAreaModelData::LoadBinary'::`2'::idLocalFileBuffer::~idLocalFileBuffer
// EA  : 0x825AE9E0
// RVA : 0x005AE9E0
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void __fastcall _idAAS2DebugAreaModelData::LoadBinary_::_2_::idLocalFileBuffer::~idLocalFileBuffer(int a1)
{
  void *v1; // r4

  v1 = *(void **)(a1 + 4);
  if ( v1 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
    *(_DWORD *)(a1 + 4) = 0;
  }
}


// ========================================================================
// ?Draw@idAAS2DebugAreaModelData@@QBAXPAVidRenderWorld@@ABV?$idList@H$04@@@Z
// EA  : 0x825AECE8
// RVA : 0x005AECE8
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModelData::Draw(
        idAAS2DebugAreaModelData *this,
        idRenderWorld *rw,
        const idList<int,5> *visibleAreas)
{
  int num; // r10
  int v7; // r19
  int v8; // r21
  int v9; // r28
  idAAS2DebugAreaModelData::debugAreaInfo_t *v10; // r25
  int v11; // r26
  idAAS2DebugAreaModelData::areaTri_t *list; // r11
  idAAS2DebugAreaModelData::areaTri_t *v13; // r30
  idWinding v14; // [sp+50h] [-90h] BYREF
  float v15[32]; // [sp+60h] [-80h] BYREF

  num = visibleAreas->num;
  v15[0] = 0.0;
  v7 = 0;
  v15[1] = 1.0;
  v15[2] = 0.0;
  v15[3] = 0.5;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = 0;
      v10 = &this->areas.list[visibleAreas->list[v8]];
      if ( v10->tris.num > 0 )
      {
        v11 = 0;
        do
        {
          list = v10->tris.list;
          v13 = &v10->tris.list[v11];
          v14.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
          memset(&v14.numPoints, 0, 12);
          idWinding::AddPoint(this: &v14, v: &this->vertices.list[list[v11].v0]);
          idWinding::AddPoint(this: &v14, v: &this->vertices.list[v13->v1]);
          idWinding::AddPoint(this: &v14, v: &this->vertices.list[v13->v2]);
          rw->DebugFilledPolygon(this: rw, a2: (const idVec4 *)v15, a3: &v14, a4: 0, a5: true);
          v14.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
          idMem::Free(this: &mem, ptr: v14.p, align: ALIGN_16);
          ++v9;
          v14.p = nullptr;
          ++v11;
        }
        while ( v9 < v10->tris.num );
      }
      ++v7;
      ++v8;
    }
    while ( v7 < visibleAreas->num );
  }
}


// ========================================================================
// __unwind$220514
// EA  : 0x825AEE60
// RVA : 0x005AEE60
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_220514()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 224 + 80));
}


// ========================================================================
// ?BuildResourceNameFromAASName@idAAS2DebugAreaModelData@@SAXPBDAAVidStr@@@Z
// EA  : 0x825AEE88
// RVA : 0x005AEE88
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModelData::BuildResourceNameFromAASName(const char *aasName, idStr *resourceName)
{
  idStr::operator=(this: resourceName, text: aasName);
  idStr::Append(this: resourceName, text: (char *)idAAS2DebugAreaModelData::TEXT_FILE_EXTENSION);
}


// ========================================================================
// ?Free@idAAS2DebugAreaModelData@@QAAXXZ
// EA  : 0x825AF098
// RVA : 0x005AF098
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModelData::Free(idAAS2DebugAreaModelData *this)
{
  char *list; // r3

  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  if ( this->areas.listStatic == 0 || this->areas.listStatic == 2 )
  {
    list = (char *)this->areas.list;
    if ( list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: list, num: this->areas.size);
    this->areas.list = nullptr;
    this->areas.size = 0;
  }
  this->areas.num = 0;
}


// ========================================================================
// ??0idAAS2DebugAreaModelData@@QAA@XZ
// EA  : 0x825AF180
// RVA : 0x005AF180
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

idAAS2DebugAreaModelData *__fastcall idAAS2DebugAreaModelData::idAAS2DebugAreaModelData(idAAS2DebugAreaModelData *this)
{
  this->vertices.list = nullptr;
  this->vertices.granularity = 0;
  this->vertices.memTag = 5;
  this->vertices.listStatic = 0;
  this->vertices.size = 0;
  this->vertices.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->areas.granularity = 0;
  this->areas.memTag = 5;
  this->areas.listStatic = 0;
  this->areas.list = nullptr;
  this->areas.size = 0;
  this->areas.num = 0;
  return this;
}


// ========================================================================
// __unwind$221093
// EA  : 0x825AF1E4
// RVA : 0x005AF1E4
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_221093()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idAAS2DebugAreaModelData@@QAA@XZ
// EA  : 0x825AF218
// RVA : 0x005AF218
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModelData::~idAAS2DebugAreaModelData(idAAS2DebugAreaModelData *this)
{
  char *list; // r3

  if ( this->areas.listStatic == 0 || this->areas.listStatic == 2 )
  {
    list = (char *)this->areas.list;
    if ( list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: list, num: this->areas.size);
    this->areas.list = nullptr;
    this->areas.size = 0;
  }
  this->areas.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$221128
// EA  : 0x825AF278
// RVA : 0x005AF278
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_221128()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?LoadBinary@idAAS2DebugAreaModelData@@QAA?AW4resourceError_t@idResource@@PBDAAVidStr@@@Z
// EA  : 0x825AF2A8
// RVA : 0x005AF2A8
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

int __fastcall idAAS2DebugAreaModelData::LoadBinary(
        idAAS2DebugAreaModelData *this,
        const char *binaryFileName,
        idStr *errorMsg)
{
  unsigned __int64 v3; // r26
  char **p_areas; // r24
  idFile *v8; // r3
  idResource::resourceError_t v10; // r3
  idResource::resourceError_t v11; // r30
  unsigned int v12; // r30
  void *v13; // r23
  int v14; // r22
  int v15; // r25
  idList<idAAS2DebugAreaModelData::areaTri_t,5> *v16; // r27
  int v17; // r29
  int v18; // r28
  idAAS2DebugAreaModelData::areaTri_t *v19; // r30
  idFileLocal v20; // [sp+50h] [-420h] BYREF
  int v21; // [sp+54h] [-41Ch] BYREF
  int v22; // [sp+58h] [-418h] BYREF
  int v23[5]; // [sp+5Ch] [-414h] BYREF
  idResource::resourceHeader_t v24; // [sp+70h] [-400h] BYREF
  idFile_Memory v25; // [sp+B0h] [-3C0h] BYREF
  char v26[256]; // [sp+200h] [-270h] BYREF
  char v27; // [sp+300h] [-170h] BYREF

  p_areas = (char **)&this->areas;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  LODWORD(v3) = 0;
  if ( this->areas.listStatic == 0 || this->areas.listStatic == 2 )
  {
    if ( *p_areas != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: *p_areas, num: this->areas.size);
    *p_areas = nullptr;
    this->areas.size = 0;
  }
  this->areas.num = 0;
  v8 = fileSystem->OpenFileRead(this: fileSystem, a2: binaryFileName, a3: 1, a4: 0);
  v20.file = v8;
  if ( v8 == nullptr )
  {
    idStr::operator=(this: errorMsg, text: idResource::resourceErrorMessage[1]);
    idFileLocal::~idFileLocal(this: &v20);
    return 1;
  }
  v24.versionHi = 0;
  v24.versionLo = 0;
  v24.sourceFileNameLen = 0;
  v24.uniqueIdNameLen = 0;
  v24.resourceId = 0xFFFF;
  v24.headerVersionHi = 1;
  v24.headerVersionLo = 1;
  v24.platform = 4;
  v24.sourceTimestamp = 0xFFFFFF;
  v24.pad[0] = 0;
  v24.pad[1] = 0;
  v24.pad[2] = 0;
  v24.hash = v3;
  v24.dataOffset = v3;
  v24.totalSize = v3;
  v10 = idResource::ReadBinaryHeader(
          file: v8,
          expectedResourceId: 0x41415344u,
          expectedVersionHi: 1u,
          expectedVersionLo: 0,
          header: &v24,
          sourceFileName: &v27,
          uniqueIdName: v26);
  v11 = v10;
  if ( v10 != RESOURCE_ERROR_NONE )
  {
    idStr::operator=(this: errorMsg, text: idResource::resourceErrorMessage[v10]);
    idFileLocal::~idFileLocal(this: &v20);
    return v11;
  }
  v12 = LODWORD(v24.totalSize) - LODWORD(v24.dataOffset);
  v23[1] = LODWORD(v24.totalSize) - LODWORD(v24.dataOffset);
  v13 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\aas2file\\AAS2DebugAreaModelData.cpp(106) : TAG_AAS",
          size: LODWORD(v24.totalSize) - LODWORD(v24.dataOffset),
          tag: TAG_AAS,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v23[2] = (int)v13;
  if ( v20.file->Read(this: v20.file, a2: v13, a3: v12) != v12 )
  {
    idStr::operator=(this: errorMsg, text: idResource::resourceErrorMessage[7]);
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    idFileLocal::~idFileLocal(this: &v20);
    return 7;
  }
  idFile_Memory::idFile_Memory(this: &v25);
  idFile_Memory::SetReadOnlyData(this: &v25, data: (const char *)v13, length: v12);
  v25.Read(this: &v25, a2: v23, a3: 4u);
  if ( v23[0] <= 0 )
  {
    idStr::operator=(this: errorMsg, text: "Bad number of vertices");
    idFile_Memory::~idFile_Memory(this: &v25);
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
LABEL_34:
    idFileLocal::~idFileLocal(this: &v20);
    return 6;
  }
  idList<idVec3,37>::SetNum(this: &this->vertices, newNum: v23[0]);
  v25.Read(this: &v25, a2: this->vertices.list, a3: 12 * v23[0]);
  v25.Read(this: &v25, a2: &v22, a3: 4u);
  if ( v22 <= 0 )
  {
    idStr::operator=(this: errorMsg, text: "Bad number of areas");
    idFile_Memory::~idFile_Memory(this: &v25);
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    goto LABEL_34;
  }
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::SetNum(this: &this->areas, newNum: v22);
  v14 = 0;
  if ( v22 > 0 )
  {
    v15 = 0;
    while ( 1 )
    {
      v25.Read(this: &v25, a2: &v21, a3: 4u);
      if ( v21 < 0 )
        break;
      v16 = (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&(*p_areas)[v15];
      idList<idAnimWebBlendEquation::existingNode_t,5>::SetNum(this: v16, newNum: v21);
      v17 = 0;
      if ( v21 > 0 )
      {
        v18 = 0;
        do
        {
          v19 = &v16->list[v18];
          v25.Read(this: &v25, a2: v19, a3: 4u);
          v25.Read(this: &v25, a2: &v19->v1, a3: 4u);
          v25.Read(this: &v25, a2: &v19->v2, a3: 4u);
          ++v17;
          ++v18;
        }
        while ( v17 < v21 );
      }
      ++v14;
      v15 += 16;
      if ( v14 >= v22 )
        goto LABEL_29;
    }
    idStr::operator=(this: errorMsg, text: "Bad number of area tris");
    idFile_Memory::~idFile_Memory(this: &v25);
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    goto LABEL_34;
  }
LABEL_29:
  idFile_Memory::~idFile_Memory(this: &v25);
  if ( v13 != nullptr )
    idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
  idFileLocal::~idFileLocal(this: &v20);
  return 0;
}


// ========================================================================
// __unwind$221172
// EA  : 0x825AF72C
// RVA : 0x005AF72C
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_221172()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 1136 + 80));
}


// ========================================================================
// __unwind$221173
// EA  : 0x825AF754
// RVA : 0x005AF754
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_221173()
{
  int v0; // r12

  _idAAS2DebugAreaModelData::LoadBinary_::_2_::idLocalFileBuffer::~idLocalFileBuffer(a1: v0 - 1136 + 96);
}


// ========================================================================
// __unwind$221174
// EA  : 0x825AF77C
// RVA : 0x005AF77C
// PDB : w:\tech5\engine\aas2file\aas2debugareamodeldata.cpp
// ========================================================================

void _unwind_221174()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 1136 + 176));
}

