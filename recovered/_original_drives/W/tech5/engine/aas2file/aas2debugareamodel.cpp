
// ========================================================================
// ??0idAAS2DebugAreaModel@@QAA@XZ
// EA  : 0x825AE5B8
// RVA : 0x005AE5B8
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

idAAS2DebugAreaModel *__fastcall idAAS2DebugAreaModel::idAAS2DebugAreaModel(idAAS2DebugAreaModel *this)
{
  idResource::idResource(this);
  this->__vftable = (idAAS2DebugAreaModel_vtbl *)&idAAS2DebugAreaModel::`vftable';
  idAAS2DebugAreaModelData::idAAS2DebugAreaModelData(this: &this->data);
  this->sourceTimestamp = -1;
  return this;
}


// ========================================================================
// __unwind$219576
// EA  : 0x825AE614
// RVA : 0x005AE614
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void _unwind_219576()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idAAS2DebugAreaModel@@UAA@XZ
// EA  : 0x825AE658
// RVA : 0x005AE658
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModel::~idAAS2DebugAreaModel(idAAS2DebugAreaModel *this)
{
  this->__vftable = (idAAS2DebugAreaModel_vtbl *)&idAAS2DebugAreaModel::`vftable';
  idAAS2DebugAreaModelData::~idAAS2DebugAreaModelData(this: &this->data);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$219598
// EA  : 0x825AE6AC
// RVA : 0x005AE6AC
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void _unwind_219598()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?LoadResource@idAAS2DebugAreaModel@@UAAXXZ
// EA  : 0x825AE750
// RVA : 0x005AE750
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModel::LoadResource(idAAS2DebugAreaModel *this)
{
  idAAS2DebugAreaModelData *p_data; // r29
  const char *str; // r6
  idResource::resourceError_t v4; // r3
  idStr v5; // [sp+50h] [-140h] BYREF
  char v6[288]; // [sp+70h] [-120h] BYREF

  p_data = &this->data;
  idAAS2DebugAreaModelData::Free(this: &this->data);
  str = this->name.str;
  this->sourceTimestamp = -1;
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION,
    a4: str,
    a5: v6,
    a6: 256);
  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.baseBuffer[0] = 0;
  v4 = idAAS2DebugAreaModelData::LoadBinary(this: p_data, binaryFileName: v6, errorMsg: &v5);
  if ( v4 != RESOURCE_ERROR_NONE )
  {
    if ( v4 >= RESOURCE_ERROR_FATAL )
    {
      idResource::SetResourceError(this, fmt: v5.data);
      idLib::Error(fmt: "Resource Fatal Error: %s", v5.data);
    }
    idResource::SetResourceError(this, fmt: "Could not gen binary in retail '%s'", this->name.str);
  }
  idStr::FreeData(this: &v5);
}


// ========================================================================
// $LN36
// EA  : 0x825AE82C
// RVA : 0x005AE82C
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void _LN36()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// ?ReloadIfStale@idAAS2DebugAreaModel@@UAA_NXZ
// EA  : 0x825AE858
// RVA : 0x005AE858
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

int __fastcall idAAS2DebugAreaModel::ReloadIfStale(idAAS2DebugAreaModel *this)
{
  _BYTE v3[264]; // [sp+50h] [-120h] BYREF

  if ( fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->sourceTimestamp )
    return 0;
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION,
    a4: this->name.str,
    a5: v3,
    a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v3, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?WriteResourceFile@idAAS2DebugAreaModel@@UBAXXZ
// EA  : 0x825AE920
// RVA : 0x005AE920
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void __fastcall idAAS2DebugAreaModel::WriteResourceFile(idAAS2DebugAreaModel *this)
{
  idAAS2DebugAreaModelGenerator::WriteToBinary(
    uniqueIdName: this->name.str,
    fileName: this->name.str,
    sourceTimestamp: this->sourceTimestamp,
    data: &this->data);
}


// ========================================================================
// `dynamic initializer for 'idAAS2DebugAreaModel::resourceList''
// EA  : 0x83335040
// RVA : 0x01335040
// PDB : w:\tech5\engine\aas2file\aas2debugareamodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idAAS2DebugAreaModel::resourceList__()
{
  idResourceList::idResourceList(this: &idAAS2DebugAreaModel::resourceList, typeName: "aasDebugAreaModel");
  idAAS2DebugAreaModel::resourceList.__vftable = (idTypedResourceList<idAAS2DebugAreaModel>_vtbl *)&idTypedResourceList<idAAS2DebugAreaModel>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idAAS2DebugAreaModel::resourceList__);
}

