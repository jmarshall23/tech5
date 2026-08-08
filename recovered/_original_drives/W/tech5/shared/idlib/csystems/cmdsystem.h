
// ========================================================================
// ??$ArgCompletion_Integer@$0A@$02@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x825D72C8
// RVA : 0x005D72C8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<0,3>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 0; i <= 3; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$229458
// EA  : 0x825D73A4
// RVA : 0x005D73A4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_229458()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ??$ArgCompletion_String@$1?cm_contentsNameByIndex@@3PAPBDA@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x825DA3D0
// RVA : 0x005DA3D0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&char const * * cm_contentsNameByIndex>(idAutoComplete *autoComplete)
{
  int v2; // r28
  const char **v3; // r11
  const char *v4; // r30
  int v5; // r29
  char *v6; // r10
  char *v7; // r9
  char v8; // r11
  idStr v9[3]; // [sp+50h] [-70h] BYREF

  v2 = 0;
  if ( cm_contentsNameByIndex[0] != nullptr )
  {
    v3 = cm_contentsNameByIndex;
    do
    {
      v4 = *v3;
      v9[0].allocedAndFlag = 20;
      v9[0].data = v9[0].baseBuffer;
      v9[0].len = 0;
      v9[0].baseBuffer[0] = 0;
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( *v4 != 0 )
        {
          do
            ++v5;
          while ( v4[v5] != 0 );
        }
        idStr::EnsureAlloced(this: v9, amount: v5 + 1, keepold: true, geometricGrowth: false);
        v6 = (char *)(v4 - 1);
        v7 = v9[0].data - 1;
        do
        {
          v8 = *++v6;
          *++v7 = *v6;
        }
        while ( v8 != 0 );
        v9[0].len = v5;
      }
      idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
      idStr::FreeData(this: v9);
      v3 = &cm_contentsNameByIndex[++v2];
    }
    while ( *v3 != nullptr );
  }
}


// ========================================================================
// __unwind$224725
// EA  : 0x825DA4B8
// RVA : 0x005DA4B8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_224725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ArgCompletion_FileName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646D70
// RVA : 0x00646D70
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_FileName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: &byte_8200D768, a5: true);
}


// ========================================================================
// ?ArgCompletion_SaveGame@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646DA0
// RVA : 0x00646DA0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_SaveGame(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "savegame/", a4: "save", a5: true);
}


// ========================================================================
// ?ArgCompletion_EventName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646DD0
// RVA : 0x00646DD0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_EventName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: "events", a5: true);
}


// ========================================================================
// ?ArgCompletion_TimeTrial@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646E00
// RVA : 0x00646E00
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_TimeTrial(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "timetrials/", a4: "tt", a5: false);
}


// ========================================================================
// ?ArgCompletion_DemoFile@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646E30
// RVA : 0x00646E30
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_DemoFile(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "demos/", a4: "demo", a5: false);
}


// ========================================================================
// ?ArgCompletion_RegressionTestName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646E60
// RVA : 0x00646E60
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_RegressionTestName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(
    this: cmdSystem,
    a2: autoComplete,
    a3: "regression/events/",
    a4: "events",
    a5: true);
}


// ========================================================================
// ??$ArgCompletion_Integer@$0A@$01@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8265C3D8
// RVA : 0x0065C3D8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<0,2>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 0; i <= 2; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$221460
// EA  : 0x8265C4B4
// RVA : 0x0065C4B4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_221460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?ArgCompletion_PlayTestFile@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8267B840
// RVA : 0x0067B840
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_PlayTestFile(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "playtest/", a4: ".ptb", a5: false);
}


// ========================================================================
// ??$ArgCompletion_Integer@$00$07@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x826A9D88
// RVA : 0x006A9D88
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<1,8>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 1; i <= 8; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$221811
// EA  : 0x826A9E64
// RVA : 0x006A9E64
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_221811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ??$ArgCompletion_String@$1?fileExtensions@idAAS2Settings@@2PAPBDA$07@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x826AF1E0
// RVA : 0x006AF1E0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&public: static char const * * idAAS2Settings::fileExtensions,8>(
        idAutoComplete *autoComplete)
{
  const char **v2; // r28
  const char *v3; // r30
  int v4; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11
  idStr v8[3]; // [sp+50h] [-70h] BYREF

  v2 = idAAS2Settings::fileExtensions;
  do
  {
    v3 = *v2;
    v8[0].allocedAndFlag = 20;
    v8[0].data = v8[0].baseBuffer;
    v8[0].len = 0;
    v8[0].baseBuffer[0] = 0;
    if ( v3 != nullptr )
    {
      v4 = 0;
      if ( *v3 != 0 )
      {
        do
          ++v4;
        while ( v3[v4] != 0 );
      }
      idStr::EnsureAlloced(this: v8, amount: v4 + 1, keepold: true, geometricGrowth: false);
      v5 = (char *)(v3 - 1);
      v6 = v8[0].data - 1;
      do
      {
        v7 = *++v5;
        *++v6 = *v5;
      }
      while ( v7 != 0 );
      v8[0].len = v4;
    }
    idAutoComplete::Append(this: autoComplete, suggestion: v8, completingArg: -1);
    idStr::FreeData(this: v8);
    ++v2;
  }
  while ( (int)v2 < (int)&idTypedResourceList<idAAS2File> `RTTI Type Descriptor' );
}


// ========================================================================
// __unwind$253462
// EA  : 0x826AF2B0
// RVA : 0x006AF2B0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_253462()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??$ArgCompletion_Integer@$0A@$00@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x827B01C8
// RVA : 0x007B01C8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<0,1>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 0; i <= 1; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$232108
// EA  : 0x827B02A4
// RVA : 0x007B02A4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_232108()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?ArgCompletion_ModelName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82867860
// RVA : 0x00867860
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_ModelName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(
    this: cmdSystem,
    a2: autoComplete,
    a3: "models/",
    a4: "lwo|ase|obj|md6mesh",
    a5: false);
}


// ========================================================================
// ?ArgCompletion_ImageName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x828C5510
// RVA : 0x008C5510
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_ImageName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: "tga", a5: true);
}


// ========================================================================
// ??$ArgCompletion_String@$1?imageFilter@@3PAPBDA@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x828C5CD8
// RVA : 0x008C5CD8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&char const * * imageFilter>(idAutoComplete *autoComplete)
{
  int v2; // r28
  const char **v3; // r11
  const char *v4; // r30
  int v5; // r29
  char *v6; // r10
  char *v7; // r9
  char v8; // r11
  idStr v9[3]; // [sp+50h] [-70h] BYREF

  v2 = 0;
  if ( imageFilter[0] != nullptr )
  {
    v3 = imageFilter;
    do
    {
      v4 = *v3;
      v9[0].allocedAndFlag = 20;
      v9[0].data = v9[0].baseBuffer;
      v9[0].len = 0;
      v9[0].baseBuffer[0] = 0;
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( *v4 != 0 )
        {
          do
            ++v5;
          while ( v4[v5] != 0 );
        }
        idStr::EnsureAlloced(this: v9, amount: v5 + 1, keepold: true, geometricGrowth: false);
        v6 = (char *)(v4 - 1);
        v7 = v9[0].data - 1;
        do
        {
          v8 = *++v6;
          *++v7 = *v6;
        }
        while ( v8 != 0 );
        v9[0].len = v5;
      }
      idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
      idStr::FreeData(this: v9);
      v3 = &imageFilter[++v2];
    }
    while ( *v3 != nullptr );
  }
}


// ========================================================================
// __unwind$230778
// EA  : 0x828C5DC0
// RVA : 0x008C5DC0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_230778()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??$ArgCompletion_Integer@$0?3$03@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x829483E0
// RVA : 0x009483E0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<-4,4>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v6; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  v6 = -4;
  do
  {
    HIDWORD(a3) = v6;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
    ++v6;
  }
  while ( v6 <= 4 );
}


// ========================================================================
// __unwind$235370
// EA  : 0x829484BC
// RVA : 0x009484BC
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_235370()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ??$ArgCompletion_String@$1?compressionStrings@@3PAPBDA@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82978B40
// RVA : 0x00978B40
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&char const * * compressionStrings>(idAutoComplete *autoComplete)
{
  int v2; // r28
  const char **v3; // r11
  const char *v4; // r30
  int v5; // r29
  char *v6; // r10
  char *v7; // r9
  char v8; // r11
  idStr v9[3]; // [sp+50h] [-70h] BYREF

  v2 = 0;
  if ( compressionStrings[0] != nullptr )
  {
    v3 = compressionStrings;
    do
    {
      v4 = *v3;
      v9[0].allocedAndFlag = 20;
      v9[0].data = v9[0].baseBuffer;
      v9[0].len = 0;
      v9[0].baseBuffer[0] = 0;
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( *v4 != 0 )
        {
          do
            ++v5;
          while ( v4[v5] != 0 );
        }
        idStr::EnsureAlloced(this: v9, amount: v5 + 1, keepold: true, geometricGrowth: false);
        v6 = (char *)(v4 - 1);
        v7 = v9[0].data - 1;
        do
        {
          v8 = *++v6;
          *++v7 = *v6;
        }
        while ( v8 != 0 );
        v9[0].len = v5;
      }
      idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
      idStr::FreeData(this: v9);
      v3 = &compressionStrings[++v2];
    }
    while ( *v3 != nullptr );
  }
}


// ========================================================================
// __unwind$233304
// EA  : 0x82978C28
// RVA : 0x00978C28
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_233304()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??$ArgCompletion_String@$1?soundShaderGroups@idSoundShader@@2PAPBDA$0BJ@@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8298EB40
// RVA : 0x0098EB40
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&public: static char const * * idSoundShader::soundShaderGroups,25>(
        idAutoComplete *autoComplete)
{
  const char **v2; // r28
  const char *v3; // r30
  int v4; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11
  idStr v8[3]; // [sp+50h] [-70h] BYREF

  v2 = idSoundShader::soundShaderGroups;
  do
  {
    v3 = *v2;
    v8[0].allocedAndFlag = 20;
    v8[0].data = v8[0].baseBuffer;
    v8[0].len = 0;
    v8[0].baseBuffer[0] = 0;
    if ( v3 != nullptr )
    {
      v4 = 0;
      if ( *v3 != 0 )
      {
        do
          ++v4;
        while ( v3[v4] != 0 );
      }
      idStr::EnsureAlloced(this: v8, amount: v4 + 1, keepold: true, geometricGrowth: false);
      v5 = (char *)(v3 - 1);
      v6 = v8[0].data - 1;
      do
      {
        v7 = *++v5;
        *++v6 = *v5;
      }
      while ( v7 != 0 );
      v8[0].len = v4;
    }
    idAutoComplete::Append(this: autoComplete, suggestion: v8, completingArg: -1);
    idStr::FreeData(this: v8);
    ++v2;
  }
  while ( (int)v2 < (int)&idSoundShader::soundShaderGroups[25] );
}


// ========================================================================
// __unwind$228330
// EA  : 0x8298EC10
// RVA : 0x0098EC10
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_228330()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??$ArgCompletion_String@$1?aiWalkModifierNames@@3PAPBDA$06@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x829FBA98
// RVA : 0x009FBA98
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&char const * * aiWalkModifierNames,7>(idAutoComplete *autoComplete)
{
  const char **v2; // r28
  const char *v3; // r30
  int v4; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11
  idStr v8[3]; // [sp+50h] [-70h] BYREF

  v2 = aiWalkModifierNames;
  do
  {
    v3 = *v2;
    v8[0].allocedAndFlag = 20;
    v8[0].data = v8[0].baseBuffer;
    v8[0].len = 0;
    v8[0].baseBuffer[0] = 0;
    if ( v3 != nullptr )
    {
      v4 = 0;
      if ( *v3 != 0 )
      {
        do
          ++v4;
        while ( v3[v4] != 0 );
      }
      idStr::EnsureAlloced(this: v8, amount: v4 + 1, keepold: true, geometricGrowth: false);
      v5 = (char *)(v3 - 1);
      v6 = v8[0].data - 1;
      do
      {
        v7 = *++v5;
        *++v6 = *v5;
      }
      while ( v7 != 0 );
      v8[0].len = v4;
    }
    idAutoComplete::Append(this: autoComplete, suggestion: v8, completingArg: -1);
    idStr::FreeData(this: v8);
    ++v2;
  }
  while ( (int)v2 < (int)aiMovePushStatusNames );
}


// ========================================================================
// __unwind$527882
// EA  : 0x829FBB68
// RVA : 0x009FBB68
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_527882()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??$ArgCompletion_Integer@$0A@$03@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82B40058
// RVA : 0x00B40058
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<0,4>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 0; i <= 4; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$489078
// EA  : 0x82B40134
// RVA : 0x00B40134
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_489078()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?ArgCompletion_Boolean@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82D6ED58
// RVA : 0x00D6ED58
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Boolean(idAutoComplete *autoComplete)
{
  idStr v2; // [sp+50h] [-60h] BYREF
  idStr v3; // [sp+70h] [-40h] BYREF

  idStr::idStr(this: &v2, text: "0");
  idAutoComplete::Append(this: autoComplete, suggestion: &v2, completingArg: -1);
  idStr::FreeData(this: &v2);
  idStr::idStr(this: &v3, text: "1");
  idAutoComplete::Append(this: autoComplete, suggestion: &v3, completingArg: -1);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$494893_0
// EA  : 0x82D6EDDC
// RVA : 0x00D6EDDC
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_494893_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$494894_0
// EA  : 0x82D6EE04
// RVA : 0x00D6EE04
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_494894_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ??$ArgCompletion_Integer@$0A@$08@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82D76340
// RVA : 0x00D76340
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_Integer<0,9>(
        idAutoComplete *autoComplete,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int i; // r28
  va *v7; // r3
  va *v8; // r30
  int v9; // r29
  char *v10; // r10
  char *v11; // r9
  char v12; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  for ( i = 0; i <= 9; ++i )
  {
    HIDWORD(a3) = i;
    v7 = va::va(this: &v20, fmt: "%d", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    v19.allocedAndFlag = 20;
    v8 = v7;
    v19.len = 0;
    v9 = 0;
    v19.data = v19.baseBuffer;
    for ( v19.baseBuffer[0] = 0; v7->buffer[v9] != 0; ++v9 )
      ;
    if ( v9 + 1 > 20 )
      idStr::ReAllocate(this: &v19, amount: v9 + 1, keepold: true);
    v10 = &v8[-1].buffer[4095];
    v11 = v19.data - 1;
    do
    {
      v12 = *++v10;
      *++v11 = *v10;
    }
    while ( v12 != 0 );
    v19.len = v9;
    idAutoComplete::Append(this: autoComplete, suggestion: &v19, completingArg: -1);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$489227
// EA  : 0x82D7641C
// RVA : 0x00D7641C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_489227()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ??1idCmdSystem@@UAA@XZ
// EA  : 0x82EFC060
// RVA : 0x00EFC060
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::~idCmdSystem(idCmdSystem *this)
{
  this->__vftable = (idCmdSystem_vtbl *)&idCmdSystem::`vftable';
}


// ========================================================================
// ?ArgCompletion_ConfigName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82EFC0C8
// RVA : 0x00EFC0C8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_ConfigName(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: "cfg", a5: true);
}


// ========================================================================
// ??$ArgCompletion_String@$1?sysLanguageNames@@3PAPBDA@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82F81DB0
// RVA : 0x00F81DB0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_String<&char const * * sysLanguageNames>(idAutoComplete *autoComplete)
{
  int v2; // r28
  const char **v3; // r11
  const char *v4; // r30
  int v5; // r29
  char *v6; // r10
  char *v7; // r9
  char v8; // r11
  idStr v9[3]; // [sp+50h] [-70h] BYREF

  v2 = 0;
  if ( sysLanguageNames[0] != nullptr )
  {
    v3 = sysLanguageNames;
    do
    {
      v4 = *v3;
      v9[0].allocedAndFlag = 20;
      v9[0].data = v9[0].baseBuffer;
      v9[0].len = 0;
      v9[0].baseBuffer[0] = 0;
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( *v4 != 0 )
        {
          do
            ++v5;
          while ( v4[v5] != 0 );
        }
        idStr::EnsureAlloced(this: v9, amount: v5 + 1, keepold: true, geometricGrowth: false);
        v6 = (char *)(v4 - 1);
        v7 = v9[0].data - 1;
        do
        {
          v8 = *++v6;
          *++v7 = *v6;
        }
        while ( v8 != 0 );
        v9[0].len = v5;
      }
      idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
      idStr::FreeData(this: v9);
      v3 = &sysLanguageNames[++v2];
    }
    while ( *v3 != nullptr );
  }
}


// ========================================================================
// __unwind$114314
// EA  : 0x82F81E98
// RVA : 0x00F81E98
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.h
// ========================================================================

void _unwind_114314()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}

