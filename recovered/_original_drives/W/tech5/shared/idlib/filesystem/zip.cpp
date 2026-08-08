
// ========================================================================
// ?testZipBuilderCombineFiles_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F1E470
// RVA : 0x00F1E470
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall testZipBuilderCombineFiles_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r3
  bool v4; // cr57
  int v5; // r30
  const char **v6; // r29
  const char *v7; // r3
  bool v8; // cr56
  int v9; // r29
  int i; // r27
  idFile_Memory *v11; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  va *v14; // r3
  idFile_Memory *v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  int v19; // [sp+8h] [-1148h]
  int v20; // [sp+Ch] [-1144h]
  int v21; // [sp+10h] [-1140h]
  int v22; // [sp+14h] [-113Ch]
  int v23; // [sp+18h] [-1138h]
  int v24; // [sp+1Ch] [-1134h]
  _BYTE v25[4]; // [sp+50h] [-1100h] BYREF
  encounterGroupRole_t v26[3]; // [sp+54h] [-10FCh] BYREF
  idList<enum encounterGroupRole_t,5> v27; // [sp+60h] [-10F0h] BYREF
  idStr v28; // [sp+70h] [-10E0h] BYREF
  idZipBuilder v29; // [sp+90h] [-10C0h] BYREF
  va v30; // [sp+F0h] [-1060h] BYREF

  memset(&v27, 0, 14);
  *(_WORD *)&v27.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v27);
  argc = args->argc;
  v3 = 2;
  v4 = args->argc > 2;
  v26[0] = (encounterGroupRole_t)args->argc;
  if ( v4 )
  {
    idLib::Printf(fmt: "usage: testZipBuilderExtractFiles [numFiles]\n");
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v27);
  }
  else
  {
    v5 = 1;
    v26[0] = argc;
    if ( argc > 1 )
    {
      v6 = (const char **)&args->argv[1];
      do
      {
        if ( v5 < 0 || v5 >= argc )
          v7 = &byte_8200D768;
        else
          v7 = *v6;
        v3 = atol(nptr: v7);
        argc = args->argc;
        ++v5;
        ++v6;
        v8 = v5 < args->argc;
        v26[0] = (encounterGroupRole_t)args->argc;
      }
      while ( v8 );
    }
    if ( v3 > 0 )
    {
      v9 = 1;
      for ( i = v3; i != 0; --i )
      {
        v11 = (idFile_Memory *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x14Cu,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        v26[0] = (encounterGroupRole_t)v11;
        if ( v11 != nullptr )
        {
          v14 = va::va(
                  this: &v30,
                  fmt: "%s%d.txt",
                  a3: __SPAIR64__("test", v9),
                  a4: v13,
                  a5: v12,
                  a6: v19,
                  a7: v20,
                  a8: v21,
                  a9: v22,
                  a10: v23,
                  a11: v24);
          v15 = idFile_Memory::idFile_Memory(this: v11, name: v14->buffer);
        }
        else
        {
          v15 = nullptr;
        }
        v26[0] = (encounterGroupRole_t)v15;
        idFile_Memory::MakeWritable(this: v15);
        v18 = va::va(
                this: &v30,
                fmt: "%s%d",
                a3: __SPAIR64__("test", v9),
                a4: v17,
                a5: v16,
                a6: v19,
                a7: v20,
                a8: v21,
                a9: v22,
                a10: v23,
                a11: v24);
        idStr::idStr(this: &v28, text: v18);
        v25[0] = v28.len;
        v25[3] = HIBYTE(v28.len);
        v25[2] = BYTE1(v28.len);
        v25[1] = BYTE2(v28.len);
        v15->Write(this: v15, a2: v25, a3: 4u);
        v15->Write(this: v15, a2: v28.data, a3: v28.len);
        idList<idAnimWebBlendTree *,5>::Append(this: &v27, obj: v26);
        idStr::FreeData(this: &v28);
        ++v9;
      }
    }
    idZipBuilder::idZipBuilder(this: &v29);
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&v27);
    idZipBuilder::~idZipBuilder(this: &v29);
    if ( (v27.listStatic == 0 || v27.listStatic == 2) && v27.list != nullptr )
      idMem::Free(this: &mem, ptr: v27.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$118322
// EA  : 0x82F1E6BC
// RVA : 0x00F1E6BC
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118322()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4432 + 96));
}


// ========================================================================
// __unwind$118323
// EA  : 0x82F1E6E4
// RVA : 0x00F1E6E4
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall _unwind_118323(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4432 + 84), tag: a2);
}


// ========================================================================
// __unwind$118324
// EA  : 0x82F1E70C
// RVA : 0x00F1E70C
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 112));
}


// ========================================================================
// __unwind$118325
// EA  : 0x82F1E734
// RVA : 0x00F1E734
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118325()
{
  int v0; // r12

  idZipBuilder::~idZipBuilder(this: (idZipBuilder *)(v0 - 4432 + 144));
}


// ========================================================================
// ?testZipBuilderExtractFiles_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F1E768
// RVA : 0x00F1E768
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall testZipBuilderExtractFiles_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r3
  bool v4; // cr57
  int v5; // r30
  const char **v6; // r29
  const char *v7; // r3
  bool v8; // cr56
  int v9; // r29
  int i; // r27
  idFile_Memory *v11; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  va *v14; // r3
  idFile_Memory *v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  int v19; // [sp+8h] [-1148h]
  int v20; // [sp+Ch] [-1144h]
  int v21; // [sp+10h] [-1140h]
  int v22; // [sp+14h] [-113Ch]
  int v23; // [sp+18h] [-1138h]
  int v24; // [sp+1Ch] [-1134h]
  _BYTE v25[4]; // [sp+50h] [-1100h] BYREF
  encounterGroupRole_t v26[3]; // [sp+54h] [-10FCh] BYREF
  idList<enum encounterGroupRole_t,5> v27; // [sp+60h] [-10F0h] BYREF
  idStr v28; // [sp+70h] [-10E0h] BYREF
  idZipBuilder v29; // [sp+90h] [-10C0h] BYREF
  va v30; // [sp+F0h] [-1060h] BYREF

  memset(&v27, 0, 14);
  *(_WORD *)&v27.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v27);
  argc = args->argc;
  v3 = 2;
  v4 = args->argc > 2;
  v26[0] = (encounterGroupRole_t)args->argc;
  if ( v4 )
  {
    idLib::Printf(fmt: "usage: testZipBuilderExtractFiles [numFiles]\n");
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v27);
  }
  else
  {
    v5 = 1;
    v26[0] = argc;
    if ( argc > 1 )
    {
      v6 = (const char **)&args->argv[1];
      do
      {
        if ( v5 < 0 || v5 >= argc )
          v7 = &byte_8200D768;
        else
          v7 = *v6;
        v3 = atol(nptr: v7);
        argc = args->argc;
        ++v5;
        ++v6;
        v8 = v5 < args->argc;
        v26[0] = (encounterGroupRole_t)args->argc;
      }
      while ( v8 );
    }
    if ( v3 > 0 )
    {
      v9 = 1;
      for ( i = v3; i != 0; --i )
      {
        v11 = (idFile_Memory *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x14Cu,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        v26[0] = (encounterGroupRole_t)v11;
        if ( v11 != nullptr )
        {
          v14 = va::va(
                  this: &v30,
                  fmt: "%s%d.txt",
                  a3: __SPAIR64__("test", v9),
                  a4: v13,
                  a5: v12,
                  a6: v19,
                  a7: v20,
                  a8: v21,
                  a9: v22,
                  a10: v23,
                  a11: v24);
          v15 = idFile_Memory::idFile_Memory(this: v11, name: v14->buffer);
        }
        else
        {
          v15 = nullptr;
        }
        v26[0] = (encounterGroupRole_t)v15;
        idFile_Memory::MakeWritable(this: v15);
        v18 = va::va(
                this: &v30,
                fmt: "%s%d",
                a3: __SPAIR64__("test", v9),
                a4: v17,
                a5: v16,
                a6: v19,
                a7: v20,
                a8: v21,
                a9: v22,
                a10: v23,
                a11: v24);
        idStr::idStr(this: &v28, text: v18);
        v25[0] = v28.len;
        v25[3] = HIBYTE(v28.len);
        v25[2] = BYTE1(v28.len);
        v25[1] = BYTE2(v28.len);
        v15->Write(this: v15, a2: v25, a3: 4u);
        v15->Write(this: v15, a2: v28.data, a3: v28.len);
        idList<idAnimWebBlendTree *,5>::Append(this: &v27, obj: v26);
        idStr::FreeData(this: &v28);
        ++v9;
      }
    }
    idZipBuilder::idZipBuilder(this: &v29);
    idLib::Printf(fmt: "Zip file created: %s\n", "^1FAIL");
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&v27);
    idZipBuilder::~idZipBuilder(this: &v29);
    idLib::Printf(fmt: "[%s] overall tests: %s\n", "testZipBuilderExtractFiles_f", "^1FAIL");
    if ( (v27.listStatic == 0 || v27.listStatic == 2) && v27.list != nullptr )
      idMem::Free(this: &mem, ptr: v27.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$118567_0
// EA  : 0x82F1E9E4
// RVA : 0x00F1E9E4
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118567_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4432 + 96));
}


// ========================================================================
// __unwind$118568_0
// EA  : 0x82F1EA0C
// RVA : 0x00F1EA0C
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall _unwind_118568_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4432 + 84), tag: a2);
}


// ========================================================================
// __unwind$118569
// EA  : 0x82F1EA34
// RVA : 0x00F1EA34
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118569()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 112));
}


// ========================================================================
// __unwind$118570
// EA  : 0x82F1EA5C
// RVA : 0x00F1EA5C
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118570()
{
  int v0; // r12

  idZipBuilder::~idZipBuilder(this: (idZipBuilder *)(v0 - 4432 + 144));
}


// ========================================================================
// ?AddFileFilters@idZipBuilder@@QAAXPBD@Z
// EA  : 0x82F1EA90
// RVA : 0x00F1EA90
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall idZipBuilder::AddFileFilters(idZipBuilder *this, const char *filters)
{
  int num; // r30
  idList<idStr,5> v4[3]; // [sp+50h] [-30h] BYREF

  v4[0].memTag = 5;
  v4[0].listStatic = 0;
  memset(v4, 0, 14);
  idStrListBreakupString(list: v4, string: filters, separator: "|");
  num = v4[0].num;
  if ( v4[0].num > 0 && idStr::Cmp(s1: v4[0].list[v4[0].num - 1].data, s2: &byte_8200D768) == 0 )
    idList<idStr,5>::RemoveIndex(this: v4, index: num - 1);
  idList<idStr,5>::Append(this: &this->filterExts, other: v4);
  if ( (v4[0].listStatic == 0 || v4[0].listStatic == 2) && v4[0].list != nullptr )
    idListArrayDelete<idStr>(ptr: v4[0].list, num: v4[0].size);
}


// ========================================================================
// __unwind$118959
// EA  : 0x82F1EB50
// RVA : 0x00F1EB50
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_118959()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 128 + 80));
}


// ========================================================================
// ?AddUncompressedFileFilters@idZipBuilder@@QAAXPBD@Z
// EA  : 0x82F1EB80
// RVA : 0x00F1EB80
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __fastcall idZipBuilder::AddUncompressedFileFilters(idZipBuilder *this, const char *filters)
{
  int num; // r30
  idList<idStr,5> v4[3]; // [sp+50h] [-30h] BYREF

  v4[0].memTag = 5;
  v4[0].listStatic = 0;
  memset(v4, 0, 14);
  idStrListBreakupString(list: v4, string: filters, separator: "|");
  num = v4[0].num;
  if ( v4[0].num > 0 && idStr::Cmp(s1: v4[0].list[v4[0].num - 1].data, s2: &byte_8200D768) == 0 )
    idList<idStr,5>::RemoveIndex(this: v4, index: num - 1);
  idList<idStr,5>::Append(this: &this->uncompressedFilterExts, other: v4);
  if ( (v4[0].listStatic == 0 || v4[0].listStatic == 2) && v4[0].list != nullptr )
    idListArrayDelete<idStr>(ptr: v4[0].list, num: v4[0].size);
}


// ========================================================================
// __unwind$119025
// EA  : 0x82F1EC40
// RVA : 0x00F1EC40
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_119025()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateMapFolderZip@idZipBuilder@@SA_NPBD@Z
// EA  : 0x82F1EC70
// RVA : 0x00F1EC70
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

int __fastcall idZipBuilder::UpdateMapFolderZip(const char *mapFileName)
{
  char *data; // r29
  char *v3; // r30
  idStr v5; // [sp+50h] [-C0h] BYREF
  idStr v6; // [sp+70h] [-A0h] BYREF
  idZipBuilder v7; // [sp+90h] [-80h] BYREF

  idStr::idStr(this: &v5, text: mapFileName);
  idStr::SetFileExtension(this: &v5, extension: "pk5");
  idStr::idStr(this: &v6, text: mapFileName);
  idStr::StripFileExtension(this: &v6);
  idZipBuilder::idZipBuilder(this: &v7);
  idZipBuilder::AddFileFilters(this: &v7, filters: "bcm|bmodel|proc|bmd6model|cmodel|bcg");
  idZipBuilder::AddUncompressedFileFilters(this: &v7, filters: "genmodel|sbcm|tbcm|");
  data = v5.data;
  v3 = v6.data;
  ((void (__fastcall *)(idFileSystem *))fileSystem->GetTimestamp)(a1: fileSystem);
  idStr::operator=(this: &v7.zipFileName, text: data);
  idStr::operator=(this: &v7.sourceFolderName, text: v3);
  idZipBuilder::~idZipBuilder(this: &v7);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: &v5);
  return 0;
}


// ========================================================================
// __unwind$119166
// EA  : 0x82F1ED44
// RVA : 0x00F1ED44
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_119166()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$119167
// EA  : 0x82F1ED6C
// RVA : 0x00F1ED6C
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_119167()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$119168
// EA  : 0x82F1ED94
// RVA : 0x00F1ED94
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void _unwind_119168()
{
  int v0; // r12

  idZipBuilder::~idZipBuilder(this: (idZipBuilder *)(v0 - 272 + 144));
}


// ========================================================================
// `dynamic initializer for 'zip_verbosity''
// EA  : 0x83395428
// RVA : 0x01395428
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zip_verbosity__()
{
  idCVar::idCVar(
    this: &zip_verbosity,
    name: "zip_verbosity",
    value: "0",
    flags: 1,
    description: "1 = verbose logging when building zip files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zip_verbosity__);
}


// ========================================================================
// `dynamic initializer for 'testZipBuilderCombineFiles_v''
// EA  : 0x83395480
// RVA : 0x01395480
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testZipBuilderCombineFiles_v__()
{
  return idCommandLink::idCommandLink(
           this: &testZipBuilderCombineFiles_v,
           cmdName: "testZipBuilderCombineFiles",
           function: testZipBuilderCombineFiles_f,
           description: "test routine for memory zip file building",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testZipBuilderExtractFiles_v''
// EA  : 0x833954A8
// RVA : 0x013954A8
// PDB : w:\tech5\shared\idlib\filesystem\zip.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testZipBuilderExtractFiles_v__()
{
  return idCommandLink::idCommandLink(
           this: &testZipBuilderExtractFiles_v,
           cmdName: "testZipBuilderExtractFiles",
           function: testZipBuilderExtractFiles_f,
           description: "test routine for memory zip file extraction",
           argCompletion: nullptr);
}

