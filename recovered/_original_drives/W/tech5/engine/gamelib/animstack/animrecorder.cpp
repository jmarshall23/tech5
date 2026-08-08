
// ========================================================================
// ?KillInstance@idAnimRecorder@@SAXXZ
// EA  : 0x826F0F78
// RVA : 0x006F0F78
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

static void __fastcall idAnimRecorder::KillInstance()
{
  if ( idAnimRecorder::instance != nullptr )
  {
    ((void (__fastcall *)(idAnimRecorder *, int))idAnimRecorder::instance->dtr_idAnimRecorder)(
      a1: idAnimRecorder::instance,
      a2: 1);
    idAnimRecorder::instance = nullptr;
  }
}


// ========================================================================
// ?ValidateBlock@idAnimRecorder@@IAAXE@Z
// EA  : 0x826F0FC8
// RVA : 0x006F0FC8
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::ValidateBlock(idAnimRecorder *this, unsigned __int8 expectedBlockType)
{
  idCompressor *compressor; // r3
  int v5; // r3
  unsigned __int8 v6; // r11
  unsigned __int8 v7[8]; // [sp+50h] [-20h] BYREF

  compressor = this->compressor;
  v7[0] = 2;
  v5 = compressor->Read(this: compressor, a2: v7, a3: 1u);
  v6 = v7[0];
  if ( v5 != 1 || v7[0] != expectedBlockType )
  {
    this->activeSerializer = nullptr;
    idLib::Error(
      fmt: "idAnimRecorder::ValidateBlock - Read block type %i, expected block type %i",
      v6,
      expectedBlockType);
  }
}


// ========================================================================
// ?WriteHeaderBlock@idAnimRecorder@@MAAXXZ
// EA  : 0x826F12F8
// RVA : 0x006F12F8
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::WriteHeaderBlock(idAnimRecorder *this)
{
  idFile *v2; // r3
  int v3; // r27
  int v4; // r28
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v5; // r30
  const char *typeName; // r11
  int v7; // r9
  const char *objectName; // r11
  int v9; // r9
  _BYTE v10[4]; // [sp+50h] [-50h] BYREF
  idFileLocal v11; // [sp+54h] [-4Ch] BYREF
  int num; // [sp+58h] [-48h] BYREF
  unsigned int v13; // [sp+5Ch] [-44h] BYREF
  unsigned int v14; // [sp+60h] [-40h] BYREF
  int v15; // [sp+64h] [-3Ch] BYREF

  v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: idAnimRecorder::inputFileName, a3: 0);
  v11.file = v2;
  if ( v2 == nullptr )
  {
    this->activeSerializer = nullptr;
    idLib::Error(fmt: "idAnimRecorder::WriteHeaderBlock - Couldn't open file");
  }
  v3 = 0;
  v10[0] = 0;
  v2->Write(this: v2, a2: v10, a3: 1u);
  v11.file->Write(this: v11.file, a2: &idAnimRecorder::version, a3: 4u);
  num = this->networkIDDict.num;
  v11.file->Write(this: v11.file, a2: &num, a3: 4u);
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->networkIDDict.list[v4];
      v11.file->Write(this: v11.file, a2: v5, a3: 2u);
      typeName = v5->second.typeName;
      do
        v7 = *(unsigned __int8 *)typeName++;
      while ( v7 != 0 );
      v13 = typeName - v5->second.typeName;
      v11.file->Write(this: v11.file, a2: &v13, a3: 4u);
      v11.file->Write(this: v11.file, a2: v5->second.typeName, a3: v13);
      objectName = v5->second.objectName;
      do
        v9 = *(unsigned __int8 *)objectName++;
      while ( v9 != 0 );
      v14 = objectName - v5->second.objectName;
      v11.file->Write(this: v11.file, a2: &v14, a3: 4u);
      v11.file->Write(this: v11.file, a2: v5->second.objectName, a3: v14);
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
  v15 = 12 * this->networkIDDict.num;
  v11.file->Write(this: v11.file, a2: &v15, a3: 4u);
  idFileLocal::~idFileLocal(this: &v11);
}


// ========================================================================
// $LN60_0
// EA  : 0x826F1508
// RVA : 0x006F1508
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _LN60_0()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 160 + 84));
}


// ========================================================================
// ?SerializeAnimNetworkID@idAnimRecorder@@QAAPBVidMD6Anim@@ABVidAnimStack@@G@Z
// EA  : 0x826F1548
// RVA : 0x006F1548
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::SerializeAnimNetworkID(
        idAnimRecorder *this,
        const idAnimStack *animStack,
        const unsigned __int16 animNetworkID)
{
  int v3; // r11
  char v5; // r10
  int num; // r5
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *list; // r4
  int v8; // r3
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v9; // r29
  idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> v10; // [sp+50h] [-50h] BYREF
  __int64 v11; // [sp+58h] [-48h]
  unsigned __int16 v12; // [sp+60h] [-40h]
  __int64 v13; // [sp+64h] [-3Ch]

  v3 = animNetworkID;
  if ( animNetworkID != 0xFFFF )
  {
    if ( this->activeAnimStack != animStack || (v5 = 1, this->recordingFileMode != RECORDING_FILE_READ) )
      v5 = 0;
    if ( v5 == 0 )
      goto _LN50_0;
    v10.__vftable = (idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>_vtbl *)&idAnimRecorder::idSearch_NetworkIDNamePair::`vftable';
    v12 = animNetworkID;
    num = this->networkIDDict.num;
    list = this->networkIDDict.list;
    HIDWORD(v11) = &byte_8200D768;
    LODWORD(v11) = &byte_8200D768;
    v13 = v11;
    v8 = idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search(
           this: &v10,
           base: list,
           num,
           value: (const idPair<unsigned short,idAnimRecorder::NameStruct_t> *)&byte_8200D768);
    v10.__vftable = (idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>_vtbl *)&idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t>>::`vftable';
    if ( v8 < 0 )
    {
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::SerializeAnimNetworkID - Invalid network ID");
    }
    v9 = &this->networkIDDict.list[v8];
    if ( idResourceList::Load(
           this: &idMD6Anim::resourceList,
           name: (char *)v9->second.objectName,
           makeDefault: false,
           skipStaleCheck: false) == nullptr )
    {
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::SerializeAnimNetworkID - Could not load anim '%s'", v9->second.objectName);
_LN50_0:
      idResourceList::GetNetworkResource(networkID: v3);
    }
  }
}


// ========================================================================
// $LN41
// EA  : 0x826F165C
// RVA : 0x006F165C
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _LN41()
{
  int v0; // r12

  idAnimRecorder::idSearch_NetworkIDNamePair::~idSearch_NetworkIDNamePair(this: (idAnimRecorder::idSearch_NetworkIDNamePair *)(v0 - 160 + 80));
}


// ========================================================================
// ?SerializeDeclNetworkID@idAnimRecorder@@QAAPBVidResource@@ABVidSerializer@@G@Z
// EA  : 0x826F1690
// RVA : 0x006F1690
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::SerializeDeclNetworkID(
        idAnimRecorder *this,
        const idSerializer *ser,
        const unsigned __int16 declNetworkID)
{
  int v3; // r11
  char v5; // r10
  int num; // r5
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *list; // r4
  int v8; // r3
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v9; // r29
  idDeclInfo *v10; // r3
  idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> v11; // [sp+50h] [-50h] BYREF
  __int64 v12; // [sp+58h] [-48h]
  unsigned __int16 v13; // [sp+60h] [-40h]
  __int64 v14; // [sp+64h] [-3Ch]

  v3 = declNetworkID;
  if ( declNetworkID != 0xFFFF )
  {
    if ( this->activeSerializer != ser || (v5 = 1, this->recordingFileMode != RECORDING_FILE_READ) )
      v5 = 0;
    if ( v5 == 0 )
      goto _LN52_1;
    v11.__vftable = (idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>_vtbl *)&idAnimRecorder::idSearch_NetworkIDNamePair::`vftable';
    v13 = declNetworkID;
    num = this->networkIDDict.num;
    list = this->networkIDDict.list;
    HIDWORD(v12) = &byte_8200D768;
    LODWORD(v12) = &byte_8200D768;
    v14 = v12;
    v8 = idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search(
           this: &v11,
           base: list,
           num,
           value: (const idPair<unsigned short,idAnimRecorder::NameStruct_t> *)&byte_8200D768);
    v11.__vftable = (idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>_vtbl *)&idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t>>::`vftable';
    if ( v8 < 0 )
    {
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::SerializeDeclNetworkID - Invalid network ID");
    }
    v9 = &this->networkIDDict.list[v8];
    v10 = declManager->GetDeclType(this: declManager, a2: v9->second.typeName);
    if ( v10 == nullptr )
    {
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::SerializeDeclNetworkID - Could not load decl info '%s'", v9->second.typeName);
    }
    if ( idResourceList::Load(this: v10, name: (char *)v9->second.objectName, makeDefault: false, skipStaleCheck: false) == nullptr )
    {
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::SerializeDeclNetworkID - Could not load decl '%s'", v9->second.objectName);
_LN52_1:
      idResourceList::GetNetworkResource(networkID: v3);
    }
  }
}


// ========================================================================
// $LN42
// EA  : 0x826F17D4
// RVA : 0x006F17D4
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _LN42()
{
  int v0; // r12

  idAnimRecorder::idSearch_NetworkIDNamePair::~idSearch_NetworkIDNamePair(this: (idAnimRecorder::idSearch_NetworkIDNamePair *)(v0 - 160 + 80));
}


// ========================================================================
// ??0idAnimRecorder@@IAA@XZ
// EA  : 0x826F1800
// RVA : 0x006F1800
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

idAnimRecorder *__fastcall idAnimRecorder::idAnimRecorder(idAnimRecorder *this)
{
  this->__vftable = (idAnimRecorder_vtbl *)&idAnimRecorder::`vftable';
  this->networkIDDict.list = nullptr;
  this->networkIDDict.granularity = 0;
  this->networkIDDict.memTag = 5;
  this->networkIDDict.listStatic = 0;
  this->networkIDDict.size = 0;
  this->networkIDDict.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->networkIDDict);
  this->cachedGameTime = 0;
  this->cachedMessageSize = 0;
  this->dataStart = 0;
  this->compressor = nullptr;
  this->file = nullptr;
  this->activeSerializer = nullptr;
  this->activeAnimStack = nullptr;
  this->recordingFileMode = RECORDING_FILE_CLOSED;
  this->isPaused = false;
  return this;
}


// ========================================================================
// ?AllocInstance@idAnimRecorder@@KAPAV1@XZ
// EA  : 0x826F1898
// RVA : 0x006F1898
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

idAnimRecorder *__fastcall idAnimRecorder::AllocInstance()
{
  idAnimRecorder *v0; // r3

  v0 = (idAnimRecorder *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x53Cu,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idAnimRecorder::idAnimRecorder(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$247171
// EA  : 0x826F1900
// RVA : 0x006F1900
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall _unwind_247171(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?ReadHeaderBlock@idAnimRecorder@@MAA_NXZ
// EA  : 0x826F1928
// RVA : 0x006F1928
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

BOOL __fastcall idAnimRecorder::ReadHeaderBlock(idAnimRecorder *this)
{
  idFile *file; // r3
  idFile *v4; // r3
  int i; // r29
  int v6; // r30
  int v7; // r3
  int v8; // r11
  char v9; // r8
  BOOL v10; // r31
  unsigned __int8 v11[2]; // [sp+50h] [-170h] BYREF
  __int16 v12; // [sp+52h] [-16Eh] BYREF
  int v13; // [sp+54h] [-16Ch] BYREF
  unsigned int v14; // [sp+58h] [-168h] BYREF
  int v15; // [sp+5Ch] [-164h] BYREF
  unsigned int v16; // [sp+60h] [-160h] BYREF
  int v17; // [sp+64h] [-15Ch] BYREF
  _QWORD v18[2]; // [sp+68h] [-158h] BYREF
  aas2Edge_t v19; // [sp+78h] [-148h] BYREF
  char v20[304]; // [sp+90h] [-130h] BYREF

  file = this->file;
  v11[0] = 2;
  file->Read(this: file, a2: v11, a3: 1u);
  if ( v11[0] != 0 )
  {
    idLib::Warning(fmt: "idAnimRecorder::ReadHeaderBlock - Wrong block type");
    return false;
  }
  else
  {
    v4 = this->file;
    v15 = -1;
    v4->Read(this: v4, a2: &v15, a3: 4u);
    if ( v15 == 1 )
    {
      v13 = -1;
      this->file->Read(this: this->file, a2: &v13, a3: 4u);
      for ( i = 0; i < v13; ++i )
      {
        v12 = -1;
        this->file->Read(this: this->file, a2: &v12, a3: 2u);
        v16 = -1;
        this->file->Read(this: this->file, a2: &v16, a3: 4u);
        this->file->Read(this: this->file, a2: v20, a3: v16);
        idAtomicString::Set(this: (idAtomicString *)v18, str_: v20);
        v14 = -1;
        this->file->Read(this: this->file, a2: &v14, a3: 4u);
        this->file->Read(this: this->file, a2: v20, a3: v14);
        idAtomicString::Set(this: (idAtomicString *)v18 + 1, str_: v20);
        HIWORD(v19.vertexNum[0]) = v12;
        v18[1] = v18[0];
        *(_QWORD *)&v19.vertexNum[1] = v18[0];
        idList<idRenderModelEffects::deferredStage_t,5>::Append(
          this: (idList<aas2Edge_t,37> *)&this->networkIDDict,
          obj: &v19);
      }
      v17 = -1;
      v6 = 12 * this->networkIDDict.num + v11[0];
      this->file->Read(this: this->file, a2: &v17, a3: 4u);
      v7 = this->file->Tell(this: this->file);
      v8 = v17;
      this->dataStart = v7;
      v9 = _cntlzw(v8 - v6);
      v10 = (v9 & 0x20) != 0;
      if ( (v9 & 0x20) == 0 )
        idLib::Warning(fmt: "idAnimRecorder::ReadHeaderBlock - Wrong end block marker");
      return v10;
    }
    else
    {
      idLib::Warning(fmt: "idAnimRecorder::ReadHeaderBlock - File is version %i. Expected version is %i.", v15, 1);
      return false;
    }
  }
}


// ========================================================================
// ?CloseFile@idAnimRecorder@@IAAXXZ
// EA  : 0x826F1B80
// RVA : 0x006F1B80
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::CloseFile(idAnimRecorder *this)
{
  idCompressor *compressor; // r3
  idCompressor_vtbl *v3; // r11
  idFile *file; // r3
  idFile_vtbl *v5; // r11
  idFile *v6; // r3
  unsigned int v7; // r30
  idFileLocal v8; // [sp+50h] [-4050h] BYREF
  idFileLocal v9; // [sp+54h] [-404Ch] BYREF
  idCompressor *v10; // [sp+58h] [-4048h]
  _BYTE v11[64]; // [sp+60h] [-4040h] BYREF

  if ( this->recordingFileMode == RECORDING_FILE_WRITE )
    this->WriteHeaderBlock(this);
  compressor = this->compressor;
  if ( compressor != nullptr )
  {
    v3 = compressor->__vftable;
    v10 = this->compressor;
    ((void (__fastcall *)(idCompressor *, int))v3->dtr_idFile)(a1: compressor, a2: 1);
    this->compressor = nullptr;
  }
  file = this->file;
  if ( file != nullptr )
  {
    v5 = file->__vftable;
    v10 = (idCompressor *)this->file;
    ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: file, a2: 1);
    this->file = nullptr;
  }
  if ( this->recordingFileMode != RECORDING_FILE_WRITE )
    goto LABEL_14;
  v8.file = fileSystem->OpenFileAppend(this: fileSystem, a2: idAnimRecorder::inputFileName, a3: 0);
  v6 = fileSystem->OpenFileRead(this: fileSystem, a2: idAnimRecorder::outputDataFileName, a3: 1, a4: 0);
  v9.file = v6;
  if ( v8.file != nullptr && v6 != nullptr )
  {
    v7 = v6->Read(this: v6, a2: v11, a3: 0x4000u);
    if ( v7 != 0 )
    {
      while ( v7 == v8.file->Write(this: v8.file, a2: v11, a3: v7) )
      {
        v7 = v9.file->Read(this: v9.file, a2: v11, a3: 0x4000u);
        if ( v7 == 0 )
          goto LABEL_13;
      }
      this->activeSerializer = nullptr;
      idLib::Error(fmt: "idAnimRecorder::CloseFile - Error writing merged file");
      goto _LN56_0;
    }
LABEL_13:
    idFileLocal::~idFileLocal(this: &v9);
    idFileLocal::~idFileLocal(this: &v8);
    fileSystem->RemoveFile(this: fileSystem, a2: idAnimRecorder::outputDataFileName, a3: FSPATH_BASE);
LABEL_14:
    this->recordingFileMode = RECORDING_FILE_CLOSED;
    idList<idAnimWebBlendEquation::existingNode_t,5>::SetNum(
      this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&this->networkIDDict,
      newNum: 0);
    this->isPaused = false;
    this->dataStart = 0;
    this->cachedGameTime = 0;
    this->cachedMessageSize = 0;
    memset(Dst: &this->buffer, Val: 0, Size: sizeof(this->buffer));
    this->activeSerializer = nullptr;
    return;
  }
_LN56_0:
  this->activeSerializer = nullptr;
  idLib::Error(fmt: "idAnimRecorder::CloseFile - Couldn't merge data with header");
  _LN57_1();
}


// ========================================================================
// $LN57_1
// EA  : 0x826F1D7C
// RVA : 0x006F1D7C
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _LN57_1()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 16544 + 80));
}


// ========================================================================
// __unwind$247460
// EA  : 0x826F1DA4
// RVA : 0x006F1DA4
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _unwind_247460()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 16544 + 84));
}


// ========================================================================
// ?OpenFile@idAnimRecorder@@IAAX_N@Z
// EA  : 0x826F1DD0
// RVA : 0x006F1DD0
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::OpenFile(idAnimRecorder *this, bool writing)
{
  BOOL v3; // r30
  idFileSystem_vtbl *v4; // r9
  idFile *v5; // r3
  idCompressor *v6; // r3
  idCompressor *v7; // r3
  const char *v8; // r4

  v3 = writing;
  idAnimRecorder::CloseFile(this);
  v4 = fileSystem->__vftable;
  if ( v3 )
    v5 = (idFile *)((int (*)(void))v4->OpenFileWrite)();
  else
    v5 = (idFile *)((int (*)(void))v4->OpenFileRead)();
  this->file = v5;
  if ( v5 != nullptr )
  {
    if ( v3 )
    {
      v6 = idCompressor::AllocLZW();
      this->compressor = v6;
      v6->Init(this: v6, a2: this->file, a3: true, a4: 8);
      this->recordingFileMode = RECORDING_FILE_WRITE;
    }
    else if ( this->ReadHeaderBlock(this) )
    {
      v7 = idCompressor::AllocLZW();
      this->compressor = v7;
      v7->Init(this: v7, a2: this->file, a3: false, a4: 8);
      this->recordingFileMode = RECORDING_FILE_READ;
    }
    else
    {
      this->Stop(this);
    }
  }
  else
  {
    idAnimRecorder::CloseFile(this);
    if ( v3 )
      v8 = "writing";
    else
      v8 = "reading";
    idLib::Warning(fmt: "idAnimRecorder::OpenFile - Can't open file for %s", v8);
  }
}


// ========================================================================
// ?Stop@idAnimRecorder@@UAAXXZ
// EA  : 0x826F1F38
// RVA : 0x006F1F38
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::Stop(idAnimRecorder *this)
{
  idAnimRecorder::CloseFile(this);
  this->activeSerializer = nullptr;
  this->activeAnimStack = nullptr;
}


// ========================================================================
// ?RecordAnimStack@idAnimRecorder@@QAAXAAVidAnimStack@@@Z
// EA  : 0x826F1F70
// RVA : 0x006F1F70
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::RecordAnimStack(idAnimRecorder *this, idAnimStack *animStack)
{
  this->activeAnimStack = animStack;
  idAnimRecorder::OpenFile(this, writing: true);
}


// ========================================================================
// ?PlaybackAnimStack@idAnimRecorder@@QAAXAAVidAnimStack@@@Z
// EA  : 0x826F1F80
// RVA : 0x006F1F80
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::PlaybackAnimStack(idAnimRecorder *this, idAnimStack *animStack)
{
  this->activeAnimStack = animStack;
  idAnimRecorder::OpenFile(this, writing: false);
}


// ========================================================================
// ?ValidateFile@idAnimRecorder@@IAAX_N@Z
// EA  : 0x826F2130
// RVA : 0x006F2130
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::ValidateFile(idAnimRecorder *this, const bool writing)
{
  idFile *file; // r30
  int v4; // r29

  if ( this->recordingFileMode == ((_cntlzw(writing) & 0x20) == 0) + 1 )
  {
    if ( !writing )
    {
      file = this->file;
      v4 = file->Tell(this: file);
      if ( (int)file->Length(this: file) <= v4 )
      {
        this->file->Seek(this: this->file, a2: this->dataStart, a3: FS_SEEK_SET);
        this->compressor->Init(this: this->compressor, a2: this->file, a3: false, a4: 8);
      }
    }
  }
  else
  {
    idAnimRecorder::OpenFile(this, writing);
  }
}


// ========================================================================
// ?ReadFrames@idAnimRecorder@@UAAXH@Z
// EA  : 0x826F21F8
// RVA : 0x006F21F8
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void __fastcall idAnimRecorder::ReadFrames(idAnimRecorder *this, int numFrames)
{
  int v4; // r26
  int *p_cachedMessageSize; // r30
  unsigned int v6; // r3
  unsigned __int8 v7; // r11
  int v8; // r29
  unsigned int v9; // r3
  int v10; // r4
  char v11[4]; // [sp+50h] [-50h] BYREF
  int v12; // [sp+54h] [-4Ch] BYREF

  v4 = 0;
  if ( numFrames > 0 )
  {
    p_cachedMessageSize = &this->cachedMessageSize;
    while ( 1 )
    {
      idAnimRecorder::ValidateFile(this, writing: false);
      v11[0] = 2;
      *p_cachedMessageSize = -1;
      v6 = this->compressor->Read(this: this->compressor, a2: v11, a3: 1u);
      v7 = v11[0];
      if ( v6 != 1 || v11[0] != 1 )
        goto _LN24;
      this->compressor->Read(this: this->compressor, a2: &this->cachedGameTime, a3: 4u);
      this->compressor->Read(this: this->compressor, a2: p_cachedMessageSize, a3: 4u);
      this->compressor->Read(this: this->compressor, a2: &this->buffer, a3: *p_cachedMessageSize);
      v12 = -1;
      v8 = *p_cachedMessageSize + 1;
      v9 = this->compressor->Read(this: this->compressor, a2: &v12, a3: 4u);
      v10 = v12;
      if ( v9 != 4 || v12 != v8 )
        break;
      if ( ++v4 >= numFrames )
        return;
    }
    this->activeSerializer = nullptr;
    idLib::Error(fmt: "idAnimRecorder::ValidateInt - Read %i, expected %i", v10, v8);
_LN24:
    this->activeSerializer = nullptr;
    idLib::Error(fmt: "idAnimRecorder::ValidateBlock - Read block type %i, expected block type %i", v7, 1);
    JUMPOUT(0x826F2340);
  }
}


// ========================================================================
// ?AddAnimNetworkID@idAnimRecorder@@QAAGABVidAnimStack@@PBVidMD6Anim@@@Z
// EA  : 0x826F2348
// RVA : 0x006F2348
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

int __fastcall idAnimRecorder::AddAnimNetworkID(
        idAnimRecorder *this,
        const idAnimStack *animStack,
        const idMD6Anim *anim)
{
  int NetworkID; // r27
  char v7; // r11
  idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> > v9; // [sp+50h] [-50h] BYREF
  idAnimRecorder::NameStruct_t v10; // [sp+58h] [-48h]
  idPair<unsigned short,idAnimRecorder::NameStruct_t> v11[5]; // [sp+60h] [-40h] BYREF

  if ( anim == nullptr )
    return -1;
  NetworkID = (unsigned __int16)idResource::GetNetworkID(this: &anim->idResource, alloc: true);
  if ( this->activeAnimStack != animStack || (v7 = 1, this->recordingFileMode != RECORDING_FILE_WRITE) )
    v7 = 0;
  if ( v7 != 0 )
  {
    v10.objectName = anim->name.str;
    v11[0].first = NetworkID;
    v9.__vftable = (idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> >_vtbl *)&idAnimRecorder::idSearch_NetworkIDNamePair::`vftable';
    v10.typeName = &byte_8200D768;
    v11[0].second = v10;
    idList<idPair<unsigned short,idAnimRecorder::NameStruct_t>,5>::InsertSortedUnique(
      this: &this->networkIDDict,
      obj: v11,
      search: &v9);
  }
  return NetworkID;
}


// ========================================================================
// __unwind$247645
// EA  : 0x826F23F8
// RVA : 0x006F23F8
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _unwind_247645()
{
  int v0; // r12

  idAnimRecorder::idSearch_NetworkIDNamePair::~idSearch_NetworkIDNamePair(this: (idAnimRecorder::idSearch_NetworkIDNamePair *)(v0 - 160 + 80));
}


// ========================================================================
// ?AddDeclNetworkID@idAnimRecorder@@QAAGABVidSerializer@@PBVidDecl@@@Z
// EA  : 0x826F2428
// RVA : 0x006F2428
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

int __fastcall idAnimRecorder::AddDeclNetworkID(idAnimRecorder *this, const idSerializer *ser, const idDecl *decl)
{
  int NetworkID; // r27
  char v7; // r11
  const idDecl *v8; // r3
  idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> >_vtbl *str; // r30
  idDeclInfo *(__fastcall *GetDeclInfo)(idDecl *); // ctr
  idResourceList *v11; // r3
  unsigned int v12; // r3
  idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> > v14[2]; // [sp+50h] [-50h] BYREF
  idPair<unsigned short,idAnimRecorder::NameStruct_t> v15[6]; // [sp+58h] [-48h] BYREF

  if ( decl == nullptr )
    return -1;
  NetworkID = (unsigned __int16)idResource::GetNetworkID(this: &decl->idResource, alloc: true);
  if ( this->activeSerializer != ser || (v7 = 1, this->recordingFileMode != RECORDING_FILE_WRITE) )
    v7 = 0;
  if ( v7 != 0 )
  {
    v8 = decl;
    GetDeclInfo = decl->GetDeclInfo;
    str = (idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> >_vtbl *)decl->name.str;
    v11 = GetDeclInfo(this: (idDecl *)v8);
    idResourceList::GetResourceTypeName(this: v11);
    v14[1].__vftable = str;
    v15[0].first = NetworkID;
    v15[0].second = (idAnimRecorder::NameStruct_t)__PAIR64__(v12, (unsigned int)str);
    v14[0].__vftable = (idSearch<idPair<unsigned short,idAnimRecorder::NameStruct_t> >_vtbl *)&idAnimRecorder::idSearch_NetworkIDNamePair::`vftable';
    idList<idPair<unsigned short,idAnimRecorder::NameStruct_t>,5>::InsertSortedUnique(
      this: &this->networkIDDict,
      obj: v15,
      search: v14);
  }
  return NetworkID;
}


// ========================================================================
// __unwind$247718
// EA  : 0x826F24E8
// RVA : 0x006F24E8
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

void _unwind_247718()
{
  int v0; // r12

  idAnimRecorder::idSearch_NetworkIDNamePair::~idSearch_NetworkIDNamePair(this: (idAnimRecorder::idSearch_NetworkIDNamePair *)(v0 - 160 + 80));
}


// ========================================================================
// ?Serialize@idAnimRecorder@@UAAXAAHAAVidGameTimeManager@@_N@Z
// EA  : 0x826F2510
// RVA : 0x006F2510
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimRecorder::Serialize(
        idAnimRecorder *this,
        int *gameTime,
        idGameTimeManager *gameTimeManager,
        bool writing)
{
  int v4; // r31 OVERLAPPED
  idCompressor *compressor; // r3
  idCompressor *v9; // r3
  int cachedGameTime; // r6
  int cachedMessageSize; // r11
  char v12[4]; // [sp+50h] [-80h] BYREF
  unsigned int v13; // [sp+54h] [-7Ch] BYREF
  unsigned int v14; // [sp+58h] [-78h] BYREF
  idSerializer v15[2]; // [sp+60h] [-70h] BYREF
  idArray<unsigned char,1282> *p_buffer; // [sp+70h] [-60h] BYREF
  idArray<unsigned char,1282> *v17; // [sp+74h] [-5Ch]
  int v18; // [sp+78h] [-58h]
  int v19; // [sp+7Ch] [-54h]
  int v20; // [sp+80h] [-50h]
  int v21; // [sp+84h] [-4Ch]
  int v22; // [sp+88h] [-48h]
  char v23; // [sp+8Ch] [-44h]
  char v24; // [sp+8Dh] [-43h]
  __int64 v25; // [sp+90h] [-40h]

  v4 = 0;
  v15[0].writing = writing;
  p_buffer = nullptr;
  v17 = nullptr;
  v18 = 0;
  this->activeSerializer = v15;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = *(_QWORD *)&v4;
  v15[0].msg = (idBitMsg *)&p_buffer;
  if ( writing )
  {
    idAnimRecorder::ValidateFile(this, writing: true);
    v19 = 0;
    p_buffer = &this->buffer;
    v17 = &this->buffer;
    v12[0] = 1;
    v18 = 1282;
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v25 = *(_QWORD *)&v4;
    idAnimStack::SerializeSnapshot(
      this: this->activeAnimStack,
      ser: v15,
      clip: nullptr,
      curTime: *gameTime,
      game: gameTimeManager);
    compressor = this->compressor;
    v13 = (v20 != 0) + v19;
    compressor->Write(this: compressor, a2: v12, a3: 1u);
    this->compressor->Write(this: this->compressor, a2: gameTime, a3: 4u);
    this->compressor->Write(this: this->compressor, a2: &v13, a3: 4u);
    this->compressor->Write(this: this->compressor, a2: &this->buffer, a3: v13);
    v9 = this->compressor;
    v14 = v13 + 1;
    v9->Write(this: v9, a2: &v14, a3: 4u);
    this->activeSerializer = nullptr;
  }
  else
  {
    if ( !this->isPaused )
      this->ReadFrames(this, a2: 1);
    cachedGameTime = this->cachedGameTime;
    p_buffer = nullptr;
    v17 = &this->buffer;
    v18 = 1282;
    v20 = 0;
    *gameTime = cachedGameTime;
    cachedMessageSize = this->cachedMessageSize;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v25 = *(_QWORD *)&v4;
    v19 = 1282;
    if ( cachedMessageSize <= 1282 )
      v19 = cachedMessageSize;
    idAnimStack::SerializeSnapshot(
      this: this->activeAnimStack,
      ser: v15,
      clip: nullptr,
      curTime: cachedGameTime,
      game: gameTimeManager);
    this->activeSerializer = nullptr;
  }
}

