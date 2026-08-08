
// ========================================================================
// ?discSwapper_getDiscNumber_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829A3268
// RVA : 0x009A3268
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall discSwapper_getDiscNumber_f(const idCmdArgs *args)
{
  int v1; // r3

  v1 = resourceManager->GetCurrentDiscNumber(this: resourceManager);
  idLib::Printf(fmt: "Using disc %d.\n", v1);
}


// ========================================================================
// ??1idDiscSwapManager@@QAA@XZ
// EA  : 0x829A3450
// RVA : 0x009A3450
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall idDiscSwapManager::~idDiscSwapManager(idDiscSwapManager *this)
{
  idStr::FreeData(this: &this->additionalArguments);
  idStr::FreeData(this: &this->savegameFile);
  idStr::FreeData(this: &this->map);
}


// ========================================================================
// __unwind$221557
// EA  : 0x829A34A0
// RVA : 0x009A34A0
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_221557()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221558
// EA  : 0x829A34C8
// RVA : 0x009A34C8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_221558()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 284));
}


// ========================================================================
// ?IsSwapRequired@idDiscSwapManager@@SA_NH@Z
// EA  : 0x829A34F8
// RVA : 0x009A34F8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

BOOL __fastcall idDiscSwapManager::IsSwapRequired(const int requiredDiscNumber)
{
  int v3; // r3

  return discSwapper_enable.valueInteger != 0
      && (v3 = resourceManager->GetCurrentDiscNumber(this: resourceManager)) != 0
      && requiredDiscNumber != 0
      && requiredDiscNumber != v3;
}


// ========================================================================
// ?RequestSwapSync360@@YA?AW4error_t@idDiscSwapManager@@H@Z
// EA  : 0x829A3680
// RVA : 0x009A3680
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

int __fastcall RequestSwapSync360(int discNumber)
{
  void *EventA; // r29
  const char *LocalizedString; // r3
  const char *v5; // r3
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  va *v9; // r3
  idStr *v10; // r3
  const char *v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r28
  int v14; // r30
  int v15; // [sp+8h] [-1B48h]
  int v16; // [sp+Ch] [-1B44h]
  int v17; // [sp+10h] [-1B40h]
  int v18; // [sp+14h] [-1B3Ch]
  int v19; // [sp+18h] [-1B38h]
  int v20; // [sp+1Ch] [-1B34h]
  idStrId v21; // [sp+50h] [-1B00h] BYREF
  idStrId v22; // [sp+54h] [-1AFCh] BYREF
  idStrId v23[2]; // [sp+58h] [-1AF8h] BYREF
  _XSWAPDISC_ERROR_TEXT v24; // [sp+60h] [-1AF0h] BYREF
  idStr v25; // [sp+70h] [-1AE0h] BYREF
  idStr v26; // [sp+90h] [-1AC0h] BYREF
  char v27; // [sp+B0h] [-1AA0h] BYREF
  idStrStatic<256> v28; // [sp+1B0h] [-19A0h] BYREF
  idStrStatic<256> v29; // [sp+2D0h] [-1880h] BYREF
  idStrStatic<256> v30; // [sp+3F0h] [-1760h] BYREF
  unsigned __int16 v31[256]; // [sp+510h] [-1640h] BYREF
  unsigned __int16 v32[256]; // [sp+710h] [-1440h] BYREF
  unsigned __int16 v33[256]; // [sp+910h] [-1240h] BYREF
  va v34; // [sp+B10h] [-1040h] BYREF

  idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "[%s] Enter\n", "RequestSwapSync360");
  v26.baseBuffer[0] = 0;
  v27 = 0;
  v26.data = &v27;
  v26.len = 0;
  v26.allocedAndFlag = -2147483392;
  idLib::Printf(fmt: "Insert 'Disc %d'\n", discNumber);
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset: 0, bInitialState: 0, lpName: nullptr);
  if ( EventA != nullptr )
  {
    idStrId::Set(this: v23, key: "#str_dlg_incorrect_disc");
    LocalizedString = idStrId::GetLocalizedString(this: v23);
    idStrStatic<256>::idStrStatic<256>(this: &v28, text: LocalizedString);
    v26.len = v28.len;
    memcpy(Dst: v26.data, Src: v28.data, Size: v28.len + 1);
    idStr::FreeData(this: &v28);
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: v26.data,
      cbMultiByte: -1,
      lpWideCharStr: v31,
      cchWideChar: 256);
    idStrId::Set(this: &v22, key: "#str_dlg_ask_for_correct_disc");
    v5 = idStrId::GetLocalizedString(this: &v22);
    idStrStatic<256>::idStrStatic<256>(this: &v29, text: v5);
    v26.len = v29.len;
    memcpy(Dst: v26.data, Src: v29.data, Size: v29.len + 1);
    idStr::FreeData(this: &v29);
    HIDWORD(v6) = discNumber;
    v9 = va::va(
           this: &v34,
           fmt: v26.data,
           a3: v6,
           a4: v8,
           a5: v7,
           a6: v15,
           a7: v16,
           a8: v17,
           a9: v18,
           a10: v19,
           a11: v20);
    v10 = idStr::idStr(this: &v25, text: v9);
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: v10->data,
      cbMultiByte: -1,
      lpWideCharStr: v33,
      cchWideChar: 256);
    idStr::FreeData(this: &v25);
    idStrId::Set(this: &v21, key: "#str_dlg_incorrect_disc_button");
    v11 = idStrId::GetLocalizedString(this: &v21);
    idStrStatic<256>::idStrStatic<256>(this: &v30, text: v11);
    v26.len = v30.len;
    memcpy(Dst: v26.data, Src: v30.data, Size: v30.len + 1);
    idStr::FreeData(this: &v30);
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: v26.data,
      cbMultiByte: -1,
      lpWideCharStr: v32,
      cchWideChar: 256);
    v24.wszTitle = v31;
    v24.wszText = v33;
    v24.wszButton = v32;
    v12 = XSwapDisc(bDiscNum: discNumber, hComplete: EventA, pErrorStrings: &v24);
    if ( v12 != 0 )
    {
      idLib::Warning(fmt: "Immediate swap error (ret = %d)", v12);
      idLib::Warning(fmt: "Trouble issuing the disc swap command, must be from real DVDs or emulated XGDs.");
      v14 = 4;
    }
    else
    {
      idLib::Printf(fmt: "Successfully issued swap command (ret = %d).\n", 0);
      do
      {
        v13 = WaitForSingleObject(hHandle: EventA, dwMilliseconds: 0xAu);
        common->Frame(this: common);
      }
      while ( v13 != 258 );
      idLib::Warning(fmt: "Other error (waitResult = %d)", 258);
      v14 = 2;
    }
    CloseHandle(hObject: EventA);
    idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "[%s] Exit\n", "RequestSwapSync360");
    idStr::FreeData(this: &v26);
    return v14;
  }
  else
  {
    idStr::FreeData(this: &v26);
    return 2;
  }
}


// ========================================================================
// __unwind$222142
// EA  : 0x829A3954
// RVA : 0x009A3954
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6992 + 144));
}


// ========================================================================
// ?Reset@idDiscSwapManager@@QAAXXZ
// EA  : 0x829A3980
// RVA : 0x009A3980
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall idDiscSwapManager::Reset(idDiscSwapManager *this)
{
  char *data; // r4
  size_t v3; // r5
  char *v4; // r3
  char *v5; // r4
  size_t v6; // r5
  char *v7; // r3
  char *v8; // r4
  size_t v9; // r5
  char *v10; // r3
  idStrStatic<64> v11; // [sp+50h] [-5A0h] BYREF
  idStrStatic<251> v12; // [sp+B0h] [-540h] BYREF
  idStrStatic<1000> v13; // [sp+1D0h] [-420h] BYREF

  idStrStatic<251>::idStrStatic<251>(this: &v12, text: &byte_8200D768);
  data = v12.data;
  v3 = v12.len + 1;
  v4 = this->map.data;
  this->map.len = v12.len;
  memcpy(Dst: v4, Src: data, Size: v3);
  idStr::FreeData(this: &v12);
  idStrStatic<64>::idStrStatic<64>(this: &v11, text: &byte_8200D768);
  v5 = v11.data;
  v6 = v11.len + 1;
  v7 = this->savegameFile.data;
  this->savegameFile.len = v11.len;
  memcpy(Dst: v7, Src: v5, Size: v6);
  idStr::FreeData(this: &v11);
  idStrStatic<1000>::idStrStatic<1000>(this: &v13, text: &byte_8200D768);
  v8 = v13.data;
  v9 = v13.len + 1;
  v10 = this->additionalArguments.data;
  this->additionalArguments.len = v13.len;
  memcpy(Dst: v10, Src: v8, Size: v9);
  idStr::FreeData(this: &v13);
  this->user = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
}


// ========================================================================
// ?IsSwapRequired@idDiscSwapManager@@SA_NABVidStr@@AAH@Z
// EA  : 0x829A3A50
// RVA : 0x009A3A50
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

BOOL __fastcall idDiscSwapManager::IsSwapRequired(const idStr *nextMap, idResource **newDiscNumber)
{
  char *data; // r4
  const idDecl *v6; // r3

  if ( discSwapper_enable.valueInteger == 0 )
    return false;
  if ( nextMap->len != 0 )
  {
    data = nextMap->data;
    if ( data == nullptr
      || (v6 = idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: data, makeDefault: false)) == nullptr )
    {
      idLib::Warning(fmt: "Map (%s) not found in idDeclMapInfo!", nextMap->data);
      *newDiscNumber = nullptr;
      return false;
    }
    *newDiscNumber = v6[1].nextOnHashChain;
  }
  return idDiscSwapManager::IsSwapRequired(requiredDiscNumber: (const int)*newDiscNumber);
}


// ========================================================================
// ?EncodeData@idDiscSwapManager@@AAAXAAVidStr@@@Z
// EA  : 0x829A3B08
// RVA : 0x009A3B08
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall idDiscSwapManager::EncodeData(idDiscSwapManager *this, idStr *data)
{
  idBase64 v3[2]; // [sp+50h] [-30h] BYREF

  memset(v3, 0, 12);
  idBase64::Encode(this: v3, from: (const unsigned __int8 *)data->data, size: data->len);
  idStr::operator=(this: data, text: (const char *)v3[0].data);
  idStr::ReplaceChar(this: data, oldChar: 43, newChar: 95);
  idStr::ReplaceChar(this: data, oldChar: 61, newChar: 58);
  if ( v3[0].data != nullptr )
    idMem::Free(this: &mem, ptr: v3[0].data, align: ALIGN_16);
}


// ========================================================================
// __unwind$222691
// EA  : 0x829A3BA4
// RVA : 0x009A3BA4
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222691()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 128 + 80));
}


// ========================================================================
// ?DecodeData@idDiscSwapManager@@AAAXAAVidStr@@@Z
// EA  : 0x829A3BD8
// RVA : 0x009A3BD8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall idDiscSwapManager::DecodeData(idDiscSwapManager *this, idStr *data)
{
  void *v3; // r30
  idBase64 v4[2]; // [sp+58h] [-68h] BYREF
  idStr v5[2]; // [sp+70h] [-50h] BYREF

  idStr::ReplaceChar(this: data, oldChar: 95, newChar: 43);
  idStr::ReplaceChar(this: data, oldChar: 58, newChar: 61);
  v3 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
         size: 2 * data->len,
         tag: TAG_TEMP,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  memset(Dst: v3, Val: 0, Size: 2 * data->len);
  idStr::idStr(this: v5, text: data->data);
  memset(v4, 0, 12);
  idBase64::operator=(this: v4, s: v5);
  idStr::FreeData(this: v5);
  idBase64::Decode(this: v4, to: (unsigned __int8 *)v3);
  idStr::operator=(this: data, text: (const char *)v3);
  if ( v4[0].data != nullptr )
    idMem::Free(this: &mem, ptr: v4[0].data, align: ALIGN_16);
  memset(v4, 0, 12);
  if ( v3 != nullptr )
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
}


// ========================================================================
// __unwind$222755
// EA  : 0x829A3CE4
// RVA : 0x009A3CE4
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222755()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$222756
// EA  : 0x829A3D0C
// RVA : 0x009A3D0C
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222756()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$222757
// EA  : 0x829A3D34
// RVA : 0x009A3D34
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222757()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 192 + 88));
}


// ========================================================================
// ?discSwapper_testTokenization_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829A3D68
// RVA : 0x009A3D68
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __fastcall discSwapper_testTokenization_f(const idCmdArgs *args)
{
  __int64 v1; // r8
  __int64 v2; // r6
  __int64 v3; // r10
  int v4; // r30
  int argc; // r11
  char **argv; // r28
  const char *v7; // r5
  va *v8; // r3
  int v9; // r11
  int v10; // r30
  char **v11; // r29
  const char *v12; // r5
  int v13; // [sp+8h] [-22C8h]
  int v14; // [sp+Ch] [-22C4h]
  int v15; // [sp+10h] [-22C0h]
  int v16; // [sp+14h] [-22BCh]
  int v17; // [sp+18h] [-22B8h]
  int v18; // [sp+1Ch] [-22B4h]
  idStr v19; // [sp+50h] [-2280h] BYREF
  idCmdArgs v20; // [sp+70h] [-2260h] BYREF
  idCmdArgs v21; // [sp+980h] [-1950h] BYREF
  va v22; // [sp+1290h] [-1040h] BYREF

  idCmdArgs::TokenizeString(this: &v20, text: discSwapper_testTokenizationStr.valueString.data, keepAsStrings: true);
  idLib::Printf(fmt: "source string: %s\n", discSwapper_testTokenizationStr.valueString.data);
  LODWORD(v3) = &off_82010000;
  v4 = 0;
  argc = v20.argc;
  if ( v20.argc > 0 )
  {
    argv = v20.argv;
    do
    {
      if ( v4 < 0 || v4 >= argc )
        v7 = &byte_8200D768;
      else
        v7 = *argv;
      idLib::Printf(fmt: "string %d = %s\n", v4, v7);
      argc = v20.argc;
      ++v4;
      ++argv;
    }
    while ( v4 < v20.argc );
  }
  HIDWORD(v2) = discSwapper_testTokenizationStr.valueString.data;
  v8 = va::va(this: &v22, fmt: "\"%s\"", a3: v2, a4: v1, a5: v3, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
  idStr::idStr(this: &v19, text: v8);
  idCmdArgs::TokenizeString(this: &v21, text: v19.data, keepAsStrings: true);
  idLib::Printf(fmt: "source string: %s\n", v19.data);
  v9 = v21.argc;
  v10 = 0;
  if ( v21.argc > 0 )
  {
    v11 = v21.argv;
    do
    {
      if ( v10 < 0 || v10 >= v9 )
        v12 = &byte_8200D768;
      else
        v12 = *v11;
      idLib::Printf(fmt: "string %d = %s\n", v10, v12);
      v9 = v21.argc;
      ++v10;
      ++v11;
    }
    while ( v10 < v21.argc );
  }
  idStr::FreeData(this: &v19);
}


// ========================================================================
// __unwind$222864
// EA  : 0x829A3EA8
// RVA : 0x009A3EA8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_222864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8912 + 80));
}


// ========================================================================
// ?RebuildStateAfterSwap@idDiscSwapManager@@QAA_NW4command_t@1@ABVidCmdArgs@@@Z
// EA  : 0x829A3ED8
// RVA : 0x009A3ED8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

int __fastcall idDiscSwapManager::RebuildStateAfterSwap(
        idDiscSwapManager *this,
        const idDiscSwapManager::command_t command,
        const idCmdArgs *args)
{
  const char *v6; // r4
  const char *v8; // r4
  char *data; // r4
  size_t v10; // r5
  char *v11; // r3
  const char *v12; // r4
  char *v13; // r4
  size_t v14; // r5
  char *v15; // r3
  const char *v16; // r4
  char *v17; // r4
  size_t v18; // r5
  char *v19; // r3
  idStr v20; // [sp+60h] [-5E0h] BYREF
  idStrStatic<64> v21; // [sp+80h] [-5C0h] BYREF
  idStrStatic<251> v22; // [sp+E0h] [-560h] BYREF
  idStrStatic<1000> v23; // [sp+200h] [-440h] BYREF

  if ( command != DSC_MULTIPLAYER_INVITE )
  {
    if ( args->argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    idStr::idStr(this: &v20, text: v6);
    idDiscSwapManager::DecodeData(this, data: &v20);
    if ( !session->signInManager->CreateNewUserFromEncodedSwapData(this: session->signInManager, a2: &v20) )
    {
      idLib::Warning(fmt: "Error creating user after relaunch.");
      session->MoveToPressStart(this: session);
      idStr::FreeData(this: &v20);
      return 0;
    }
    idStr::FreeData(this: &v20);
  }
  if ( command == DSC_MAP )
  {
    if ( args->argc <= 2 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[2];
    idStrStatic<1000>::idStrStatic<1000>(this: &v23, text: v8);
    data = v23.data;
    v10 = v23.len + 1;
    v11 = this->additionalArguments.data;
    this->additionalArguments.len = v23.len;
    memcpy(Dst: v11, Src: data, Size: v10);
    idStr::FreeData(this: &v23);
    idDiscSwapManager::DecodeData(this, data: &this->additionalArguments);
    if ( args->argc <= 3 )
      v12 = &byte_8200D768;
    else
      v12 = args->argv[3];
    idStrStatic<251>::idStrStatic<251>(this: &v22, text: v12);
    v13 = v22.data;
    v14 = v22.len + 1;
    v15 = this->map.data;
    this->map.len = v22.len;
    memcpy(Dst: v15, Src: v13, Size: v14);
    idStr::FreeData(this: &v22);
    idDiscSwapManager::DecodeData(this, data: &this->map);
  }
  else if ( command == DSC_LOAD )
  {
    if ( args->argc <= 2 )
      v16 = &byte_8200D768;
    else
      v16 = args->argv[2];
    idStrStatic<64>::idStrStatic<64>(this: &v21, text: v16);
    v17 = v21.data;
    v18 = v21.len + 1;
    v19 = this->savegameFile.data;
    this->savegameFile.len = v21.len;
    memcpy(Dst: v19, Src: v17, Size: v18);
    idStr::FreeData(this: &v21);
  }
  return 1;
}


// ========================================================================
// __unwind$223038
// EA  : 0x829A4098
// RVA : 0x009A4098
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1600 + 96));
}


// ========================================================================
// ?EncodeParmsForSwap@idDiscSwapManager@@AAA_NW4command_t@1@AAVidStr@@@Z
// EA  : 0x829A40C8
// RVA : 0x009A40C8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

int __fastcall idDiscSwapManager::EncodeParmsForSwap(
        idDiscSwapManager *this,
        const idDiscSwapManager::command_t command,
        idStr *encodedData)
{
  int len; // r28
  idLocalUser *user; // r4
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  int v13; // r28
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  const char *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r6
  __int64 v21; // r8
  va *v22; // r3
  int v23; // [sp+8h] [-1098h]
  int v24; // [sp+8h] [-1098h]
  int v25; // [sp+Ch] [-1094h]
  int v26; // [sp+Ch] [-1094h]
  int v27; // [sp+10h] [-1090h]
  int v28; // [sp+10h] [-1090h]
  int v29; // [sp+14h] [-108Ch]
  int v30; // [sp+14h] [-108Ch]
  int v31; // [sp+18h] [-1088h]
  int v32; // [sp+18h] [-1088h]
  int v33; // [sp+1Ch] [-1084h]
  int v34; // [sp+1Ch] [-1084h]
  idStr v35; // [sp+50h] [-1050h] BYREF
  va v36; // [sp+70h] [-1030h] BYREF

  if ( command == DSC_MULTIPLAYER_INVITE )
  {
    len = this->additionalArguments.len;
    idStr::EnsureAlloced(this: encodedData, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: encodedData->data, Src: this->additionalArguments.data, Size: len);
    encodedData->data[len] = 0;
    encodedData->len = len;
    idDiscSwapManager::EncodeData(this, data: encodedData);
    return 1;
  }
  else
  {
    user = this->user;
    if ( user != nullptr )
    {
      session->signInManager->EncodeUser(this: session->signInManager, a2: user, a3: encodedData);
      idDiscSwapManager::EncodeData(this, data: encodedData);
      if ( command == DSC_MAP )
      {
        idStr::idStr(this: &v35, text: &this->additionalArguments);
        idDiscSwapManager::EncodeData(this, data: &v35);
        HIDWORD(v9) = v35.data;
        v12 = va::va(
                this: &v36,
                fmt: " %s",
                a3: v9,
                a4: v11,
                a5: v10,
                a6: v23,
                a7: v25,
                a8: v27,
                a9: v29,
                a10: v31,
                a11: v33);
        idStr::Append(this: encodedData, text: v12);
        v13 = this->map.len;
        idStr::EnsureAlloced(this: &v35, amount: this->map.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v35.data, Src: this->map.data, Size: v13);
        v35.data[v13] = 0;
        v35.len = v13;
        idDiscSwapManager::EncodeData(this, data: &v35);
        HIDWORD(v14) = v35.data;
        v17 = va::va(
                this: &v36,
                fmt: " %s",
                a3: v14,
                a4: v16,
                a5: v15,
                a6: v24,
                a7: v26,
                a8: v28,
                a9: v30,
                a10: v32,
                a11: v34);
        idStr::Append(this: encodedData, text: v17);
        idStr::FreeData(this: &v35);
        return 1;
      }
      else
      {
        if ( command == DSC_LOAD )
        {
          v18 = session->GetCurrentSaveSlot(this: session);
          HIDWORD(v19) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
          HIDWORD(v20) = v18;
          v22 = va::va(
                  this: &v36,
                  fmt: " %s",
                  a3: v20,
                  a4: v21,
                  a5: v19,
                  a6: v23,
                  a7: v25,
                  a8: v27,
                  a9: v29,
                  a10: v31,
                  a11: v33);
          idStr::Append(this: encodedData, text: v22);
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
}


// ========================================================================
// __unwind$223153
// EA  : 0x829A4278
// RVA : 0x009A4278
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223153()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 80));
}


// ========================================================================
// ?SwapLaunchProcess@idDiscSwapManager@@AAA_NW4command_t@1@H@Z
// EA  : 0x829A42A8
// RVA : 0x009A42A8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

int __fastcall idDiscSwapManager::SwapLaunchProcess(
        idDiscSwapManager *this,
        idDiscSwapManager::command_t command,
        const int newCurrentDiscNumber)
{
  idStr v6; // [sp+50h] [-140h] BYREF
  idStr v7; // [sp+70h] [-120h] BYREF
  idStr v8; // [sp+90h] [-100h] BYREF
  idStr v9; // [sp+B0h] [-E0h] BYREF
  idStr v10; // [sp+D0h] [-C0h] BYREF
  idStr v11; // [sp+F0h] [-A0h] BYREF
  idStr v12; // [sp+110h] [-80h] BYREF
  idStr v13[3]; // [sp+130h] [-60h] BYREF

  idLib::PrintfIf(
    condition: discSwapper_verbose.valueInteger != 0,
    fmt: "[%s] Enter\n",
    "idDiscSwapManager::SwapLaunchProcess");
  idStr::idStr(this: &v6, text: &byte_8200D768);
  idStr::idStr(this: &v7, text: &byte_8200D768);
  if ( command != DSC_SIMPLE_REBOOT )
  {
    if ( (unsigned __int8)idDiscSwapManager::EncodeParmsForSwap(this, command, encodedData: &v7) == 0 )
    {
      idStr::FreeData(this: &v7);
      idStr::FreeData(this: &v6);
      return 0;
    }
    idStr::idStr(this: &v8, text: &byte_8200D768);
    idStr::idStr(this: &v9, text: "+restart_mapAfterSwap");
    idStr::idStr(this: &v10, text: "+restart_multiplayerInvite");
    idStr::idStr(this: &v11, text: "+restart_loadgame");
    idStr::idStr(this: &v12, text: "+restart_passMainMenu");
    idStr::idStr(this: v13, text: &byte_8200D768);
    idStr::Append(this: &v6, text: "+fromGameRestart ");
    idStr::Append(this: &v6, text: &v8 + command);
    idStr::Append(this: &v6, text: " ");
    idStr::Append(this: &v6, text: &v7);
    `eh vector destructor iterator'(
      ptr: &v8,
      size: 0x20u,
      count: 6,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  }
  idLib::PrintfIf(
    condition: discSwapper_verbose.valueInteger != 0,
    fmt: "launch cmd line, sizeof user data (%d): %s\n",
    v7.len,
    v6.data);
  Sys_ReLaunch(data: v6.data, dataSize: v6.len);
  idLib::PrintfIf(
    condition: discSwapper_verbose.valueInteger != 0,
    fmt: "[%s] Exit\n",
    "idDiscSwapManager::SwapLaunchProcess");
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: &v6);
  return 1;
}


// ========================================================================
// __unwind$223207_0
// EA  : 0x829A445C
// RVA : 0x009A445C
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223207_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$223208
// EA  : 0x829A4484
// RVA : 0x009A4484
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$223209
// EA  : 0x829A44AC
// RVA : 0x009A44AC
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223209()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$223210
// EA  : 0x829A44D4
// RVA : 0x009A44D4
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223210()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$223211
// EA  : 0x829A44FC
// RVA : 0x009A44FC
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223211()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$223212
// EA  : 0x829A4524
// RVA : 0x009A4524
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223212()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$223213
// EA  : 0x829A454C
// RVA : 0x009A454C
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223213()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 272));
}


// ========================================================================
// __unwind$223215
// EA  : 0x829A4574
// RVA : 0x009A4574
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void _unwind_223215()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 400 + 144),
    size: 0x20u,
    count: 6,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// ?Swap@idDiscSwapManager@@QAA?AW4error_t@1@W4command_t@1@H@Z
// EA  : 0x829A45B0
// RVA : 0x009A45B0
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

idDiscSwapManager::error_t __fastcall idDiscSwapManager::Swap(
        idDiscSwapManager *this,
        idDiscSwapManager::command_t command,
        idResource *forceDiscNumber)
{
  int v5; // r31
  _DWORD *v6; // r3
  _DWORD *v7; // r26
  _DWORD *v8; // r3
  _DWORD *v9; // r6
  int i; // r11
  idDiscSwapManager::error_t result; // r3
  idResource *v12; // r29
  int v13; // [sp+70h] [-50h] BYREF
  idResource *v14; // [sp+74h] [-4Ch] BYREF

  v14 = forceDiscNumber;
  v5 = 0;
  if ( !idDiscSwapManager::IsSwapRequired(nextMap: &this->map, newDiscNumber: &v14) )
    return v5;
  idLib::PrintfIf(condition: discSwapper_verbose.valueInteger != 0, fmt: "--- NEED TO SWAP DISCS ---\n");
  v13 = 2;
  v6 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0xCu,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v6[1] = 0;
    v7 = v6;
    v6[2] = &v13;
    *v6 = &`idDiscSwapManager::Swap'::`6'::idSWFScriptFunction_Cancel::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  v8 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0xCu,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    v8[1] = 0;
    v9 = v8;
    v8[2] = &v13;
    *v8 = &`idDiscSwapManager::Swap'::`5'::idSWFScriptFunction_Accept::`vftable';
  }
  else
  {
    v9 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, int, const char *, int))common->AddDialog)(
    a1: common,
    a2: 116,
    a3: 2,
    a4: v9,
    a5: v7,
    a6: 1,
    a7: "idDiscSwapManager::Swap",
    a8: 248);
  for ( i = v13; v13 == 2; i = v13 )
  {
    common->Frame(this: common);
    mgthread_sleep(ms: 10);
  }
  if ( i == 1 )
    return DSE_CANCEL;
  v12 = v14;
  ((void (__fastcall *)(idCommon *, idResource *, _DWORD, _DWORD, _DWORD, _DWORD, const char *, int))common->AddDialog)(
    a1: common,
    a2: v14,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: "idDiscSwapManager::Swap",
    a8: 263);
  common->SyncAllBackgroundOperations(this: common, a2: false);
  session->ShutdownSoundRelatedSystems(this: session);
  soundSystem->Shutdown(this: soundSystem);
  resourceManager->CloseOpenFileHandles(this: resourceManager);
  result = RequestSwapSync360(discNumber: (int)v12);
  if ( result == DSE_OK )
    return (unsigned __int8)idDiscSwapManager::SwapLaunchProcess(this, command, newCurrentDiscNumber: (const int)v12) == 0
         ? 2
         : 7;
  return result;
}


// ========================================================================
// `idDiscSwapManager::Swap'::`5'::idSWFScriptFunction_Accept::Call
// EA  : 0x829A4828
// RVA : 0x009A4828
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idDiscSwapManager::Swap_::_5_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  *(_DWORD *)thisObject->variables.num = 0;
  common->ClearDialog(this: common, a2: GDM_DISC_SWAP_CONFIRMATION, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idDiscSwapManager::Swap'::`6'::idSWFScriptFunction_Cancel::Call
// EA  : 0x829A4890
// RVA : 0x009A4890
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idDiscSwapManager::Swap_::_6_::idSWFScriptFunction_Cancel::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  *(_DWORD *)thisObject->variables.num = 1;
  common->ClearDialog(this: common, a2: GDM_DISC_SWAP_CONFIRMATION, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `dynamic initializer for 'discSwapper_enable''
// EA  : 0x83361A98
// RVA : 0x01361A98
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_enable__()
{
  idCVar::idCVar(
    this: &discSwapper_enable,
    name: "discSwapper_enable",
    value: "0",
    flags: 17,
    description: "disc swap enabled, simulator for PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_enable__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_verbose''
// EA  : 0x83361AF0
// RVA : 0x01361AF0
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_verbose__()
{
  idCVar::idCVar(
    this: &discSwapper_verbose,
    name: "discSwapper_verbose",
    value: "0",
    flags: 1,
    description: "debug spam for disc swapper",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_verbose__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_enableSimulator''
// EA  : 0x83361B48
// RVA : 0x01361B48
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_enableSimulator__()
{
  idCVar::idCVar(
    this: &discSwapper_enableSimulator,
    name: "discSwapper_enableSimulator",
    value: "0",
    flags: 17,
    description: "simulator for disc swap testing on the PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_enableSimulator__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_currentDisc''
// EA  : 0x83361BA0
// RVA : 0x01361BA0
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_currentDisc__()
{
  idCVar::idCVar(
    this: &discSwapper_currentDisc,
    name: "discSwapper_currentDisc",
    value: "1",
    flags: 18,
    description: "for simulation purposes, which disc is in the drive",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_currentDisc__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_sleep''
// EA  : 0x83361BF8
// RVA : 0x01361BF8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_sleep__()
{
  idCVar::idCVar(
    this: &discSwapper_sleep,
    name: "discSwapper_sleep",
    value: "3000",
    flags: 18,
    description: "sleep amount for simulation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_sleep__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_deleteSwapFile''
// EA  : 0x83361C50
// RVA : 0x01361C50
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_deleteSwapFile__()
{
  idCVar::idCVar(
    this: &discSwapper_deleteSwapFile,
    name: "discSwapper_deleteSwapFile",
    value: "1",
    flags: 17,
    description: "should we delete the swap file after reading it?  used for testing PS3 details in the XMB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_deleteSwapFile__);
}


// ========================================================================
// `dynamic initializer for 'discSwapStateMgrLocal''
// EA  : 0x83361CA8
// RVA : 0x01361CA8
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapStateMgrLocal__()
{
  discSwapStateMgrLocal.savegameFile.allocedAndFlag = -2147483584;
  discSwapStateMgrLocal.additionalArguments.allocedAndFlag = -2147482648;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapStateMgrLocal__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_getDiscNumber_v''
// EA  : 0x83361D08
// RVA : 0x01361D08
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__discSwapper_getDiscNumber_v__()
{
  return idCommandLink::idCommandLink(
           this: &discSwapper_getDiscNumber_v,
           cmdName: "discSwapper_getDiscNumber",
           function: discSwapper_getDiscNumber_f,
           description: "Returns which disc is in use",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_testTokenizationStr''
// EA  : 0x83361D30
// RVA : 0x01361D30
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__discSwapper_testTokenizationStr__()
{
  idCVar::idCVar(
    this: &discSwapper_testTokenizationStr,
    name: "discSwapper_testTokenization",
    value: "~!@#$%^&*()_+{}|:<>?,.;'[]\\-",
    flags: 0,
    description: "sample base64 string used by discSwapper_testTokenization",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__discSwapper_testTokenizationStr__);
}


// ========================================================================
// `dynamic initializer for 'discSwapper_testTokenization_v''
// EA  : 0x83361D88
// RVA : 0x01361D88
// PDB : w:\tech5\engine\sys\sys_disc_swapper.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__discSwapper_testTokenization_v__()
{
  return idCommandLink::idCommandLink(
           this: &discSwapper_testTokenization_v,
           cmdName: "discSwapper_testTokenization",
           function: discSwapper_testTokenization_f,
           description: "Tests how the string is going to be broken up",
           argCompletion: nullptr);
}

