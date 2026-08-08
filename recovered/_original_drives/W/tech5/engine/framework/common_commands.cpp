
// ========================================================================
// Com_Break_f
// EA  : 0x82646BD0
// RVA : 0x00646BD0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Break_f(const idCmdArgs *args)
{
  AssertFailed(
    file: "w:\\tech5\\engine\\framework\\Common_commands.cpp",
    line: 355,
    expression: "Com_Break_f",
    inlineBreak: true);
}


// ========================================================================
// Com_Quit_f
// EA  : 0x82646BF0
// RVA : 0x00646BF0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Quit_f(const idCmdArgs *args)
{
  idLib::Printf(fmt: "\n You intentionally quit the game \n");
  idCommonLocal::Quit(this: &commonLocal, exitCode: 0);
}


// ========================================================================
// ?StopTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646C28
// RVA : 0x00646C28
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall StopTest_f(const idCmdArgs *args)
{
  commonLocal.regression.StopTest(this: &commonLocal.regression);
}


// ========================================================================
// ?GatherMapStats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646C48
// RVA : 0x00646C48
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall GatherMapStats_f(const idCmdArgs *args)
{
  idCVar::SetBool(this: &com_showFPS, newValue: true, force: true);
  idCVar::SetBool(this: &com_gatherMapStats, newValue: true, force: true);
}


// ========================================================================
// ?nextRegressionTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646C98
// RVA : 0x00646C98
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall nextRegressionTest_f(const idCmdArgs *args)
{
  idRegression *v1; // r3

  v1 = common->GetRegression(this: common);
  v1->NextTest(this: v1);
}


// ========================================================================
// ?Com_TestStatsBegin_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646CE0
// RVA : 0x00646CE0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_TestStatsBegin_f(const idCmdArgs *args)
{
  commonLocal.regression.SetTestInProgress(this: &commonLocal.regression, a2: true);
  idCVar::SetBool(this: &com_showFPS, newValue: true, force: true);
}


// ========================================================================
// ?R_VidRestart_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646D30
// RVA : 0x00646D30
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall R_VidRestart_f(const idCmdArgs *args)
{
  renderSystem->Restart(this: renderSystem);
}


// ========================================================================
// ?SetGameHz_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646F28
// RVA : 0x00646F28
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall SetGameHz_f(const idCmdArgs *args)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  idGame *v6; // r3
  const char *v7; // r3
  int v8; // r3
  int v9; // [sp+8h] [-1068h]
  int v10; // [sp+Ch] [-1064h]
  int v11; // [sp+10h] [-1060h]
  int v12; // [sp+14h] [-105Ch]
  int v13; // [sp+18h] [-1058h]
  int v14; // [sp+1Ch] [-1054h]
  va v15; // [sp+50h] [-1020h] BYREF

  if ( common->Game(this: common) != nullptr )
  {
    v6 = common->Game(this: common);
    v6->GetGameTimeManager(this: v6);
    if ( args->argc <= 1 )
      v7 = &byte_8200D768;
    else
      v7 = args->argv[1];
    v8 = atol(nptr: v7);
    idGameTimeManager::SetGameHz(hz: v8);
  }
  else
  {
    LODWORD(v2) = &unk_821C0000;
    HIDWORD(v4) = "SetGameHz_f";
    v5 = va::va(
           this: &v15,
           fmt: "Must have a valid game object for %s",
           a3: v4,
           a4: v3,
           a5: v2,
           a6: v9,
           a7: v10,
           a8: v11,
           a9: v12,
           a10: v13,
           a11: v14);
    idLib::Warning(fmt: v5->buffer);
  }
}


// ========================================================================
// ?StopSlowMotion_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82646FE8
// RVA : 0x00646FE8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall StopSlowMotion_f(const idCmdArgs *args)
{
  __int64 v1; // r10
  __int64 v2; // r8
  __int64 v3; // r6
  va *v4; // r3
  idGame *v5; // r3
  idGameTimeManager *v6; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  if ( common->Game(this: common) != nullptr )
  {
    v5 = common->Game(this: common);
    v6 = v5->GetGameTimeManager(this: v5);
    idGameTimeManager::StopSlowmotion(this: v6);
  }
  else
  {
    LODWORD(v1) = &unk_821C0000;
    HIDWORD(v3) = "StopSlowMotion_f";
    v4 = va::va(
           this: &v13,
           fmt: "Must have a valid game object for %s",
           a3: v3,
           a4: v2,
           a5: v1,
           a6: v7,
           a7: v8,
           a8: v9,
           a9: v10,
           a10: v11,
           a11: v12);
    idLib::Warning(fmt: v4->buffer);
  }
}


// ========================================================================
// ?StartSlowMotion2_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647088
// RVA : 0x00647088
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall StartSlowMotion2_f(const idCmdArgs *args)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  double v6; // fp31
  long double v7; // fp2
  idGame *v8; // r3
  idGameTimeManager *v9; // r3
  int v10; // [sp+8h] [-1078h]
  int v11; // [sp+Ch] [-1074h]
  int v12; // [sp+10h] [-1070h]
  int v13; // [sp+14h] [-106Ch]
  int v14; // [sp+18h] [-1068h]
  int v15; // [sp+1Ch] [-1064h]
  slowmoParms_t v16; // [sp+50h] [-1030h] BYREF
  va v17; // [sp+60h] [-1020h] BYREF

  if ( common->Game(this: common) != nullptr )
  {
    if ( g_enableGameTimeScaling.valueInteger != 0 )
    {
      v6 = 0.30000001;
      if ( args->argc == 2 )
      {
        v7 = atof(nptr: args->argv[1]);
        v6 = (float)*(double *)&v7;
      }
      v16.easeInDuration = 0.0;
      v16.slowmoDuration = 0.0;
      v16.easeOutDuration = 0.0;
      v16.timeScale = 1.0;
      v8 = common->Game(this: common);
      v9 = v8->GetGameTimeManager(this: v8);
      v16.timeScale = v6;
      v16.easeInDuration = 0.5;
      v16.easeOutDuration = 0.5;
      idGameTimeManager::StartSlowmotion(this: v9, slowmoParms: &v16);
    }
  }
  else
  {
    LODWORD(v2) = &unk_821C0000;
    HIDWORD(v4) = "StartSlowMotion2_f";
    v5 = va::va(
           this: &v17,
           fmt: "Must have a valid game object for %s",
           a3: v4,
           a4: v3,
           a5: v2,
           a6: v10,
           a7: v11,
           a8: v12,
           a9: v13,
           a10: v14,
           a11: v15);
    idLib::Warning(fmt: v5->buffer);
  }
}


// ========================================================================
// ?StopSlowMotion2_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647198
// RVA : 0x00647198
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall StopSlowMotion2_f(const idCmdArgs *args)
{
  __int64 v1; // r10
  __int64 v2; // r8
  __int64 v3; // r6
  va *v4; // r3
  idGame *v5; // r3
  idGameTimeManager *v6; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  if ( common->Game(this: common) != nullptr )
  {
    if ( g_enableGameTimeScaling.valueInteger != 0 )
    {
      v5 = common->Game(this: common);
      v6 = v5->GetGameTimeManager(this: v5);
      idGameTimeManager::StopSlowmotion(this: v6);
    }
  }
  else
  {
    LODWORD(v1) = &unk_821C0000;
    HIDWORD(v3) = "StopSlowMotion2_f";
    v4 = va::va(
           this: &v13,
           fmt: "Must have a valid game object for %s",
           a3: v3,
           a4: v2,
           a5: v1,
           a6: v7,
           a7: v8,
           a8: v9,
           a9: v10,
           a10: v11,
           a11: v12);
    idLib::Warning(fmt: v4->buffer);
  }
}


// ========================================================================
// Com_Error_f
// EA  : 0x82647250
// RVA : 0x00647250
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Error_f(const idCmdArgs *args)
{
  if ( args->argc <= 1 )
    idLib::Error(fmt: "Testing drop error");
  else
    idLib::FatalError(fmt: "Testing fatal error");
}


// ========================================================================
// Com_Freeze_f
// EA  : 0x82647278
// RVA : 0x00647278
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Freeze_f(const idCmdArgs *args)
{
  long double v1; // fp2
  double v2; // fp30
  int v3; // r31
  __int64 v4; // r10

  if ( args->argc == 2 )
  {
    v1 = atof(nptr: args->argv[1]);
    v2 = (float)*(double *)&v1;
    v3 = Sys_Milliseconds();
    do
      LODWORD(v4) = Sys_Milliseconds() - v3;
    while ( (float)((float)v4 * (float)0.001) <= v2 );
  }
  else
  {
    idLib::Printf(fmt: "freeze <seconds>\n");
  }
}


// ========================================================================
// Com_Crash_f
// EA  : 0x82647310
// RVA : 0x00647310
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Crash_f(const idCmdArgs *args)
{
  bool v2; // zf
  const char *v3; // r4
  const char *v4; // r3
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  va *v8; // r3
  int v9; // [sp+8h] [-1978h]
  int v10; // [sp+Ch] [-1974h]
  int v11; // [sp+10h] [-1970h]
  int v12; // [sp+14h] [-196Ch]
  int v13; // [sp+18h] [-1968h]
  int v14; // [sp+1Ch] [-1964h]
  idCmdArgs v15; // [sp+50h] [-1930h] BYREF
  va v16; // [sp+960h] [-1020h] BYREF

  if ( args->argc == 2 && atol(nptr: args->argv[1]) > 0 )
  {
    v2 = args->argc <= 0;
    v15.argc = 0;
    if ( v2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[0];
    idCmdArgs::AppendArg(this: &v15, text: v3);
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    HIDWORD(v5) = atol(nptr: v4) - 1;
    v8 = va::va(this: &v16, fmt: "%d", a3: v5, a4: v7, a5: v6, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
    idCmdArgs::AppendArg(this: &v15, text: v8->buffer);
    Com_Crash_f(args: &v15);
  }
  else
  {
    idLib::Printf(fmt: "\n You intentionally crashed the game \n");
    MEMORY[0] = 305419896;
  }
}


// ========================================================================
// ?Com_WriteConfig_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826473F8
// RVA : 0x006473F8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_WriteConfig_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr v2; // [sp+60h] [-30h] BYREF

  v2.len = 0;
  v2.allocedAndFlag = 20;
  v2.data = v2.baseBuffer;
  v2.baseBuffer[0] = 0;
  if ( args->argc == 2 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    idStr::operator=(this: &v2, text: v1);
    idStr::DefaultFileExtension(this: &v2, extension: ".cfg");
    idLib::Printf(fmt: "Writing %s.\n", v2.data);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&commonLocal);
  }
  else
  {
    idLib::Printf(fmt: "Usage: writeconfig <filename>\n");
  }
  idStr::FreeData(this: &v2);
}


// ========================================================================
// __unwind$223848
// EA  : 0x826474B4
// RVA : 0x006474B4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_223848()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 96));
}


// ========================================================================
// ?InitLanguageDict@idCommonLocal@@QAAXXZ
// EA  : 0x826474E8
// RVA : 0x006474E8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall idCommonLocal::InitLanguageDict(idCommonLocal *this)
{
  idResource *v1; // r30
  int trackedMemory; // [sp+50h] [-B0h]
  idStr v3; // [sp+60h] [-A0h] BYREF
  char v4; // [sp+80h] [-80h] BYREF

  v3.baseBuffer[0] = 0;
  v4 = 0;
  v3.data = &v4;
  v3.len = 0;
  v3.allocedAndFlag = -2147483584;
  idStr::Format(this: &v3, fmt: "strings/%s.lang", sys_lang.valueString.data);
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 15u);
  if ( idLib::production == PROD_PRODUCTION )
    resourceManager->SetFileHook(this: resourceManager);
  v1 = idResourceList::Load(
         this: &idFileResource::resourceList,
         name: v3.data,
         makeDefault: true,
         skipStaleCheck: false);
  if ( idLib::production == PROD_PRODUCTION )
    resourceManager->ReleaseFileHook(this: resourceManager);
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  if ( v1 == nullptr || v1[1].trackedMemory <= 0 )
  {
    idCVar::Reset(this: &sys_lang);
    idStr::Format(this: &v3, fmt: "strings/%s.lang", sys_lang.valueString.data);
    v1 = idResourceList::Load(
           this: &idFileResource::resourceList,
           name: v3.data,
           makeDefault: true,
           skipStaleCheck: false);
  }
  if ( v1 != nullptr && (trackedMemory = v1[1].trackedMemory) > 0 )
  {
    if ( !idLocalization::LoadDictionary(
            data: (const unsigned __int8 *)v1[1].name.str,
            dataLen: trackedMemory,
            fileName: v3.data) )
      idLib::Warning(fmt: "Unable to load language data from file %s!", v3.data);
    ((void (__fastcall *)(idResource *, int))v1->dtr_idResource)(a1: v1, a2: 1);
  }
  else
  {
    idLib::Warning(fmt: "Unable to load default language file %s!", v3.data);
  }
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$223953
// EA  : 0x82647698
// RVA : 0x00647698
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_223953()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?Com_ReloadLanguage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826476C0
// RVA : 0x006476C0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_ReloadLanguage_f(const idCmdArgs *args)
{
  idCommonLocal::InitLanguageDict(this: &commonLocal);
}


// ========================================================================
// ?Com_RecordEvents_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826476D0
// RVA : 0x006476D0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_RecordEvents_f(const idCmdArgs *args)
{
  const char *v1; // r5

  if ( args->argc < 2 )
  {
    v1 = nullptr;
  }
  else if ( args->argc <= 1 )
  {
    v1 = &byte_8200D768;
  }
  else
  {
    v1 = args->argv[1];
  }
  idCommonLocal::RecordPlayback(this: &commonLocal, record: true, fileName: v1);
}


// ========================================================================
// ?Com_PlayEvents_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647710
// RVA : 0x00647710
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_PlayEvents_f(const idCmdArgs *args)
{
  const char *v1; // r5

  if ( args->argc < 2 )
  {
    v1 = nullptr;
  }
  else if ( args->argc <= 1 )
  {
    v1 = &byte_8200D768;
  }
  else
  {
    v1 = args->argv[1];
  }
  idCommonLocal::RecordPlayback(this: &commonLocal, record: false, fileName: v1);
}


// ========================================================================
// ?MakeTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647750
// RVA : 0x00647750
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall MakeTest_f(const idCmdArgs *args)
{
  if ( args->argc == 2 || args->argc == 3 )
  {
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "bind ESCAPE \"stopTest\"");
    commonLocal.regression.MakeTest(this: &commonLocal.regression, a2: args);
  }
  else
  {
    idLib::Printf(
      fmt: "Usage: makeTest <mapName> [layer ##]\n"
      "Note: layer regression_## and player start regression_start_## are now used for tests\n");
  }
}


// ========================================================================
// ?MakeTestLoadGame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826477F0
// RVA : 0x006477F0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall MakeTestLoadGame_f(const idCmdArgs *args)
{
  if ( args->argc == 2 || args->argc == 3 )
  {
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "bind ESCAPE \"stopTest\"");
    commonLocal.regression.MakeTestLoadGame(this: &commonLocal.regression, a2: args);
  }
  else
  {
    idLib::Printf(
      fmt: "Usage: makeTestLoadGame <mapName> [layer #]\n"
      "Note: layer regression_## and player start regression_start_## are now used for tests\n");
  }
}


// ========================================================================
// ?PlayTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647890
// RVA : 0x00647890
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall PlayTest_f(const idCmdArgs *args)
{
  const char *v2; // r4

  if ( args->argc == 2 )
  {
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "bind ESCAPE \"stopTest\"");
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    commonLocal.regression.PlayTest(this: &commonLocal.regression, a2: v2, a3: false);
  }
  else if ( args->argc == 3 )
  {
    commonLocal.regression.PlayTest(this: &commonLocal.regression, a2: args->argv[1], a3: true);
  }
  else
  {
    idLib::Printf(fmt: "Usage: playTest <eventsName or folderPath> [startUp]\n");
  }
}


// ========================================================================
// ?PlayTestAndExit_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647980
// RVA : 0x00647980
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall PlayTestAndExit_f(const idCmdArgs *args)
{
  if ( args->argc == 2 || args->argc == 3 )
  {
    idCVar::SetBool(this: &com_exitAfterTests, newValue: true, force: true);
    PlayTest_f(args);
  }
  else
  {
    idLib::Printf(fmt: "Usage: playTestAndExit <eventsName or folderPath> [startUp]\n");
  }
}


// ========================================================================
// ?DelayedScreenshot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826479F8
// RVA : 0x006479F8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall DelayedScreenshot_f(const idCmdArgs *args)
{
  int v2; // r30
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  va *v9; // r4
  va *v10; // r4
  int v11; // [sp+8h] [-1068h]
  int v12; // [sp+Ch] [-1064h]
  int v13; // [sp+10h] [-1060h]
  int v14; // [sp+14h] [-105Ch]
  int v15; // [sp+18h] [-1058h]
  int v16; // [sp+1Ch] [-1054h]
  va v17; // [sp+50h] [-1020h] BYREF

  if ( args->argc == 3 )
  {
    v2 = atol(nptr: args->argv[1]);
    if ( v2 <= Sys_Milliseconds() )
    {
      if ( args->argc <= 2 )
        HIDWORD(v5) = &byte_8200D768;
      else
        HIDWORD(v5) = args->argv[2];
      v10 = va::va(
              this: &v17,
              fmt: "screenshot %s\n",
              a3: v5,
              a4: v4,
              a5: v3,
              a6: v11,
              a7: v12,
              a8: v13,
              a9: v14,
              a10: v15,
              a11: v16);
      cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v10->buffer);
    }
    else
    {
      cmdSystem->AppendCommandText(this: cmdSystem, a2: "wait 10\n");
      HIDWORD(v8) = &byte_8200D768;
      if ( args->argc <= 2 )
        LODWORD(v8) = &byte_8200D768;
      else
        LODWORD(v8) = args->argv[2];
      if ( args->argc > 1 )
        HIDWORD(v8) = args->argv[1];
      v9 = va::va(
             this: &v17,
             fmt: "DelayedScreenshot %s %s\n",
             a3: v8,
             a4: v7,
             a5: v6,
             a6: v11,
             a7: v12,
             a8: v13,
             a9: v14,
             a10: v15,
             a11: v16);
      cmdSystem->AppendCommandText(this: cmdSystem, a2: v9->buffer);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: DelayedScreenshot < time > < filename >\n");
  }
}


// ========================================================================
// ?DumpWarnings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647B20
// RVA : 0x00647B20
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall DumpWarnings_f(const idCmdArgs *args)
{
  if ( args->argc == 2 )
    idCommonLocal::DumpWarnings(this: &commonLocal, fileName: args->argv[1]);
  else
    idLib::Printf(fmt: "USAGE: com_dumpWarnings <file name>\n");
}


// ========================================================================
// ?sys_writeMemoryReport_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647B50
// RVA : 0x00647B50
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall sys_writeMemoryReport_f(const idCmdArgs *args)
{
  const idGameSpawnInfo *v1; // r3
  idStr v2; // [sp+50h] [-50h] BYREF
  idStr v3; // [sp+70h] [-30h] BYREF

  v2.len = 0;
  v2.allocedAndFlag = 20;
  v2.data = v2.baseBuffer;
  v2.baseBuffer[0] = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.len = 0;
  v3.baseBuffer[0] = 0;
  v1 = commonLocal.game->GetGameSpawnInfo(this: commonLocal.game);
  idStr::ExtractFileName(this: &v1->mapName, dest: &v2);
  if ( v2.len != 0 )
  {
    idStr::Format(this: &v3, fmt: "1.%d.%d", 1683, 2952);
    idMem::WriteMemoryReport(this: &mem, mapName: v2.data, version: v3.data);
  }
  else
  {
    idLib::Printf(fmt: "Please load a map before running this command.\n");
  }
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v2);
}


// ========================================================================
// __unwind$224301
// EA  : 0x82647C30
// RVA : 0x00647C30
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_224301()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$224302
// EA  : 0x82647C58
// RVA : 0x00647C58
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_224302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// ?reportNumRenderModels_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647C88
// RVA : 0x00647C88
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall reportNumRenderModels_f(const idCmdArgs *args)
{
  const idGameSpawnInfo *v1; // r3
  idRenderWorld *v2; // r3
  int v3; // r3
  idStr v4; // [sp+50h] [-60h] BYREF
  idStr v5; // [sp+70h] [-40h] BYREF

  v4.len = 0;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.baseBuffer[0] = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.len = 0;
  v5.baseBuffer[0] = 0;
  v1 = commonLocal.game->GetGameSpawnInfo(this: commonLocal.game);
  idStr::ExtractFileName(this: &v1->mapName, dest: &v4);
  if ( v4.len != 0 )
  {
    v2 = commonLocal.game->GetRenderWorld(this: commonLocal.game);
    v3 = v2->GetNumRenderModels(this: v2);
    idLib::Printf(fmt: "Render Model Count: %d\n", v3);
  }
  else
  {
    idLib::Printf(fmt: "Please load a map before running this command.\n");
  }
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: &v4);
}


// ========================================================================
// __unwind$224399
// EA  : 0x82647D78
// RVA : 0x00647D78
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_224399()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$224400
// EA  : 0x82647DA0
// RVA : 0x00647DA0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_224400()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?StartSlowMotion_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82647F08
// RVA : 0x00647F08
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall StartSlowMotion_f(const idCmdArgs *args)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  idGame *v6; // r3
  idGameTimeManager *v7; // r29
  const char *v8; // r4
  const idDecl *v9; // r3
  int v10; // [sp+8h] [-1068h]
  int v11; // [sp+Ch] [-1064h]
  int v12; // [sp+10h] [-1060h]
  int v13; // [sp+14h] [-105Ch]
  int v14; // [sp+18h] [-1058h]
  int v15; // [sp+1Ch] [-1054h]
  va v16; // [sp+50h] [-1020h] BYREF

  if ( common->Game(this: common) != nullptr )
  {
    if ( g_enableGameTimeScaling.valueInteger != 0 )
    {
      v6 = common->Game(this: common);
      v7 = v6->GetGameTimeManager(this: v6);
      if ( args->argc <= 1 )
      {
        v9 = idDeclInfo::FindWithInheritance(
               this: &idDeclGameTime::resourceList,
               name: &byte_8200D768,
               makeDefault: false);
      }
      else
      {
        v8 = args->argv[1];
        if ( v8 != nullptr )
          v9 = idDeclInfo::FindWithInheritance(this: &idDeclGameTime::resourceList, name: v8, makeDefault: false);
        else
          v9 = nullptr;
      }
      if ( v9 == nullptr )
        v9 = idDeclInfo::FindWithInheritance(
               this: &idDeclGameTime::resourceList,
               name: "gametime/slowmo",
               makeDefault: true);
      idGameTimeManager::StartSlowmotion(this: v7, slowmoParms: (const slowmoParms_t *)&v9[1].name);
    }
  }
  else
  {
    LODWORD(v2) = &unk_821C0000;
    HIDWORD(v4) = "StartSlowMotion_f";
    v5 = va::va(
           this: &v16,
           fmt: "Must have a valid game object for %s",
           a3: v4,
           a4: v3,
           a5: v2,
           a6: v10,
           a7: v11,
           a8: v12,
           a9: v13,
           a10: v14,
           a11: v15);
    idLib::Warning(fmt: v5->buffer);
  }
}


// ========================================================================
// ?Com_StripStrings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82648020
// RVA : 0x00648020
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_StripStrings_f(const idCmdArgs *args)
{
  char *v1; // r28
  int v2; // r27
  int v3; // r26
  int v4; // r29
  const idLangKeyValue *KeyVal; // r3
  int v6; // r29
  char *value; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+60h] [-1060h] BYREF
  va v19; // [sp+80h] [-1040h] BYREF

  if ( args->argc != 2 )
  {
    idLib::Printf(fmt: "USAGE: stripStrings <match string>\n");
    return;
  }
  v1 = args->argv[1];
  v2 = 0;
  if ( *v1 != 0 )
  {
    do
      ++v2;
    while ( v1[v2] != 0 );
  }
  v3 = 0;
  if ( (_cntlzw(idStr::Cmpn(s1: v1, s2: "#str_", n: 5)) & 0x20) != 0 )
  {
    idLib::Printf(fmt: "Finding keys starting with '%s'...\n", v1);
    v4 = 0;
    if ( (int)idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict) <= 0 )
      return;
    do
    {
      KeyVal = idLangDict::GetKeyVal(this: &idLocalization::languageDict, i: v4);
      if ( idStr::Cmpn(s1: KeyVal->key, s2: v1, n: v2) == 0 )
      {
        idLangDict::DeleteString(this: &idLocalization::languageDict, idx: v4--);
        ++v3;
      }
      ++v4;
    }
    while ( v4 < (int)idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict) );
  }
  else
  {
    idLib::Printf(fmt: "Finding substrings matching '%s'...\n", v1);
    v6 = 0;
    if ( (int)idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict) <= 0 )
      return;
    do
    {
      value = idLangDict::GetKeyVal(this: &idLocalization::languageDict, i: v6)->value;
      if ( value != nullptr && idStr::Find(searchIn: value, searchFor: v1, casesensitive: true, start: 0, end: -1) != -1 )
      {
        idLangDict::DeleteString(this: &idLocalization::languageDict, idx: v6--);
        ++v3;
      }
      ++v6;
    }
    while ( v6 < (int)idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict) );
  }
  if ( v3 > 0 )
  {
    idLib::Printf(fmt: "Removed %d strings.\n", v3);
    LODWORD(v8) = allocationCurrent[242];
    HIDWORD(v8) = &unk_821C0000;
    LODWORD(v9) = &sys_lang;
    HIDWORD(v10) = sys_lang.valueString.data;
    v11 = va::va(
            this: &v19,
            fmt: "strings/%s.lang",
            a3: v10,
            a4: v9,
            a5: v8,
            a6: v12,
            a7: v13,
            a8: v14,
            a9: v15,
            a10: v16,
            a11: v17);
    idStr::idStr(this: &v18, text: v11);
    if ( idLangDict::Save(this: &idLocalization::languageDict, fileName: v18.data) )
      idLib::Printf(fmt: "Saved strings file '%s'.\n", v18.data);
    idStr::FreeData(this: &v18);
  }
}


// ========================================================================
// __unwind$225156
// EA  : 0x8264822C
// RVA : 0x0064822C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225156()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 96));
}


// ========================================================================
// ?Com_TestStatsEnd_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82648260
// RVA : 0x00648260
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Com_TestStatsEnd_f(const idCmdArgs *args)
{
  const idGameSpawnInfo *v2; // r3
  const char *v3; // r4
  __int64 v4; // r10
  __int64 v5; // r8
  va *v6; // r3
  __int64 v7; // r8
  __int64 v8; // r10
  va *v9; // r3
  __int64 v10; // r8
  __int64 v11; // r10
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  idFile *v16; // r30
  idFile_vtbl *v17; // r25
  char *data; // r23
  char *v19; // r22
  char *v20; // r20
  char *v21; // r19
  const char *v22; // r3
  __int64 v23; // r9
  int v24; // r29
  char *v25; // r27
  char *v26; // r26
  const char *v27; // r3
  __int128 v28; // r9 OVERLAPPED
  int v29; // r10
  va *v30; // r3
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r8
  va *v38; // r3
  int v39; // [sp+8h] [-41C8h]
  int v40; // [sp+8h] [-41C8h]
  int v41; // [sp+8h] [-41C8h]
  int v42; // [sp+8h] [-41C8h]
  int v43; // [sp+8h] [-41C8h]
  int v44; // [sp+8h] [-41C8h]
  int v45; // [sp+Ch] [-41C4h]
  int v46; // [sp+Ch] [-41C4h]
  int v47; // [sp+Ch] [-41C4h]
  int v48; // [sp+Ch] [-41C4h]
  int v49; // [sp+Ch] [-41C4h]
  int v50; // [sp+Ch] [-41C4h]
  int v51; // [sp+10h] [-41C0h]
  int v52; // [sp+10h] [-41C0h]
  int v53; // [sp+10h] [-41C0h]
  int v54; // [sp+10h] [-41C0h]
  int v55; // [sp+10h] [-41C0h]
  int v56; // [sp+10h] [-41C0h]
  int v57; // [sp+14h] [-41BCh]
  int v58; // [sp+14h] [-41BCh]
  int v59; // [sp+14h] [-41BCh]
  int v60; // [sp+14h] [-41BCh]
  int v61; // [sp+14h] [-41BCh]
  int v62; // [sp+14h] [-41BCh]
  int v63; // [sp+18h] [-41B8h]
  int v64; // [sp+18h] [-41B8h]
  int v65; // [sp+18h] [-41B8h]
  int v66; // [sp+18h] [-41B8h]
  int v67; // [sp+18h] [-41B8h]
  int v68; // [sp+18h] [-41B8h]
  int v69; // [sp+1Ch] [-41B4h]
  int v70; // [sp+1Ch] [-41B4h]
  int v71; // [sp+1Ch] [-41B4h]
  int v72; // [sp+1Ch] [-41B4h]
  int v73; // [sp+1Ch] [-41B4h]
  int v74; // [sp+1Ch] [-41B4h]
  int v75; // [sp+30h] [-41A0h]
  idStr v76; // [sp+70h] [-4160h] BYREF
  idStr v77; // [sp+90h] [-4140h] BYREF
  idStr v78; // [sp+B0h] [-4120h] BYREF
  __int64 v79; // [sp+D0h] [-4100h]
  idStr v80; // [sp+E0h] [-40F0h] BYREF
  idStr v81; // [sp+100h] [-40D0h] BYREF
  idStr v82; // [sp+120h] [-40B0h] BYREF
  idStr v83; // [sp+140h] [-4090h] BYREF
  va v84; // [sp+160h] [-4070h] BYREF
  va v85; // [sp+1160h] [-3070h] BYREF
  va v86; // [sp+2160h] [-2070h] BYREF
  va v87; // [sp+3160h] [-1070h] BYREF

  commonLocal.regression.SetTestInProgress(this: &commonLocal.regression, a2: false);
  v2 = commonLocal.game->GetGameSpawnInfo(this: commonLocal.game);
  idStr::idStr(this: &v76, text: &v2->mapName);
  idStr::BackSlashesToSlashes(this: &v76);
  idStr::ToLower(this: &v76);
  v77.len = 0;
  v77.allocedAndFlag = 20;
  v77.data = v77.baseBuffer;
  v77.baseBuffer[0] = 0;
  v78.allocedAndFlag = 20;
  v78.data = v78.baseBuffer;
  v78.len = 0;
  v78.baseBuffer[0] = 0;
  idStr::ExtractFileName(this: &v76, dest: &v77);
  if ( v77.len == 0 )
    idStr::operator=(this: &v77, text: "unknown");
  if ( idStr::Find(searchIn: v76.data, searchFor: "wasteland1", casesensitive: true, start: 0, end: v76.len) < 0 )
  {
    if ( idStr::Find(searchIn: v76.data, searchFor: "wasteland2", casesensitive: true, start: 0, end: v76.len) < 0 )
    {
      if ( idStr::Find(searchIn: v76.data, searchFor: "tracks", casesensitive: true, start: 0, end: v76.len) < 0 )
        v3 = "other";
      else
        v3 = "tracks";
    }
    else
    {
      v3 = "wasteland2";
    }
  }
  else
  {
    v3 = "wasteland1";
  }
  idStr::operator=(this: &v78, text: v3);
  idStr::idStr(this: &v80, text: "win32");
  idStr::operator=(this: &v80, text: "360");
  HIDWORD(v4) = &unk_821C0000;
  v6 = va::va(
         this: &v84,
         fmt: "1.%i.%i",
         a3: 0x69300000B88LL,
         a4: v5,
         a5: v4,
         a6: v39,
         a7: v45,
         a8: v51,
         a9: v57,
         a10: v63,
         a11: v69);
  idStr::idStr(this: &v82, text: v6);
  LODWORD(v7) = &unk_821C0000;
  v9 = va::va(
         this: &v86,
         fmt: "testoutput/%s/%s/",
         a3: __SPAIR64__((unsigned int)v82.data, (unsigned int)v80.data),
         a4: v7,
         a5: v8,
         a6: v40,
         a7: v46,
         a8: v52,
         a9: v58,
         a10: v64,
         a11: v70);
  idStr::idStr(this: &v83, text: v9);
  HIDWORD(v10) = &unk_821C0000;
  v12 = va::va(
          this: &v85,
          fmt: "%s%s",
          a3: __SPAIR64__((unsigned int)v83.data, (unsigned int)v77.data),
          a4: v10,
          a5: v11,
          a6: v41,
          a7: v47,
          a8: v53,
          a9: v59,
          a10: v65,
          a11: v71);
  idStr::idStr(this: &v81, text: v12);
  if ( args->argc > 0 )
  {
    v15 = va::va(
            this: &v87,
            fmt: "%s_%s.mapstats",
            a3: __SPAIR64__((unsigned int)v81.data, (unsigned int)v80.data),
            a4: v14,
            a5: v13,
            a6: v42,
            a7: v48,
            a8: v54,
            a9: v60,
            a10: v66,
            a11: v72);
    v16 = fileSystem->OpenFileWrite(this: fileSystem, a2: v15, a3: 2);
    if ( v16 != nullptr )
    {
      v17 = v16->__vftable;
      data = v82.data;
      v19 = v77.data;
      v20 = v78.data;
      v21 = v76.data;
      v22 = Sys_DateStr(padded: true);
      v17->WriteFloatString(
        this: v16,
        a2: "{\r\t\"name\":\"%s\",\r\t\"buildnum\":\"%s\",\r\t\"date\":\"%s\",\r\t\"map\":\"%s\",\r\t\"groupname\":\"%s\",\r\t"
        "\"texturesize_mb\":\"%s\",\r\t\"platformstats\": [\r\t{\r\t\t\"platform\":\"%s\",\r\t\t\"loadtime_ms\":%i,\r\t\t"
        "\"fps\":%i,\r\t\t\"loaded\":%i\r\\t}\r\t]\r}\r",
        v19,
        data,
        v22,
        v21,
        v20,
        "n/a");
      ((void (__fastcall *)(idFile *, int))v16->dtr_idFile)(a1: v16, a2: 1);
    }
  }
  console->Close(this: console, a2: true);
  LODWORD(v23) = time_mapLoadMS;
  v79 = v23;
  v24 = time_FPS;
  v25 = v80.data;
  v26 = v82.data;
  v27 = Sys_DateStr(padded: true);
  DWORD1(v28) = v26;
  v29 = v24;
  *((double *)&v28 + 1) = (float)((float)v79 * (float)0.001);
  v30 = va::va(
          this: &v87,
          fmt: "Platform: %s\nDate: %s\nBuild: %s\nMap: %s\nLoad time(secs) %1.2f\nFps: %i\n",
          a3: __SPAIR64__((unsigned int)v25, (unsigned int)v27),
          a4: *(__int64 *)((char *)&v28 + 4),
          a5: *(__int64 *)((char *)&v28 - 4),
          a6: v42,
          a7: v48,
          a8: v54,
          a9: v60,
          a10: v66,
          a11: v72);
  idStr::operator=(this: &v76, text: v30);
  if ( (_S13_0 & 1) == 0 )
  {
    handle_1.time = 0;
    _S13_0 |= 1u;
    handle_1.index = -1;
  }
  ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, int, char *, double, double))console->PrintOverlay)(
    a1: console,
    a2: &handle_1,
    a3: 1.0,
    a4: v75,
    a5: v76.data,
    a6: 1.0,
    a7: 1.0);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "wait 120");
  HIDWORD(v31) = v81.data;
  v34 = va::va(
          this: &v87,
          fmt: "screenshot %s.jpg",
          a3: v31,
          a4: v33,
          a5: v32,
          a6: v43,
          a7: v49,
          a8: v55,
          a9: v61,
          a10: v67,
          a11: v73);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v34->buffer);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "wait 5");
  HIDWORD(v35) = v81.data;
  v38 = va::va(
          this: &v87,
          fmt: "%s.log",
          a3: v35,
          a4: v37,
          a5: v36,
          a6: v44,
          a7: v50,
          a8: v56,
          a9: v62,
          a10: v68,
          a11: v74);
  console->Dump(this: console, a2: (const char *)v38, a3: nullptr);
  idStr::FreeData(this: &v81);
  idStr::FreeData(this: &v83);
  idStr::FreeData(this: &v82);
  idStr::FreeData(this: &v80);
  idStr::FreeData(this: &v78);
  idStr::FreeData(this: &v77);
  idStr::FreeData(this: &v76);
}


// ========================================================================
// __unwind$225237
// EA  : 0x82648714
// RVA : 0x00648714
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225237()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 112));
}


// ========================================================================
// __unwind$225238
// EA  : 0x8264873C
// RVA : 0x0064873C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225238()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 144));
}


// ========================================================================
// __unwind$225239
// EA  : 0x82648764
// RVA : 0x00648764
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225239()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 176));
}


// ========================================================================
// __unwind$225240
// EA  : 0x8264878C
// RVA : 0x0064878C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225240()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 224));
}


// ========================================================================
// __unwind$225241
// EA  : 0x826487B4
// RVA : 0x006487B4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225241()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 288));
}


// ========================================================================
// __unwind$225242
// EA  : 0x826487DC
// RVA : 0x006487DC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225242()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 320));
}


// ========================================================================
// __unwind$225243
// EA  : 0x82648804
// RVA : 0x00648804
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225243()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 256));
}


// ========================================================================
// ?writeEntitiesFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82648838
// RVA : 0x00648838
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall writeEntitiesFile_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idStr *v3; // r29
  size_t len; // r30
  idStr v5; // [sp+50h] [-130h] BYREF
  int v6; // [sp+70h] [-110h]
  idStr v7; // [sp+80h] [-100h] BYREF
  idStr v8; // [sp+A0h] [-E0h] BYREF
  idDeclEntityDef varC0; // [sp+C0h] [-C0h] BYREF

  argc = args->argc;
  v6 = args->argc;
  if ( v6 == 2 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v5, text: v2);
    idStr::BackSlashesToSlashes(this: &v5);
    if ( idStr::Icmpn(s1: v5.data, s2: "maps/", n: 5) != 0 )
    {
      v3 = operator+(result: &v8, a: "maps/", b: &v5);
      len = v3->len;
      idStr::EnsureAlloced(this: &v5, amount: v3->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v5.data, Src: v3->data, Size: len);
      v5.data[len] = 0;
      v5.len = len;
      idStr::FreeData(this: &v8);
    }
    idMapFile::idMapFile(this: (idMapFile *)&varC0);
    varC0.editorVars.animFrame = (int)common->Game(this: common);
    if ( idMapFile::Parse(this: (idMapFile *)&varC0, filename: v5.data, osPath: false, parent: nullptr) )
    {
      if ( idPhysics_Static::GetNumContactPhysics(this: &varC0) != nullptr )
      {
        idStr::idStr(this: &v7, text: &v5);
        idStr::SetFileExtension(this: &v7, extension: "entities");
        if ( idMapFile::WriteEntities(this: (idMapFile *)&varC0, fileName: v7.data, osPath: false) )
          idLib::Printf(fmt: "Done.\n");
        idStr::FreeData(this: &v7);
        idMapFile::~idMapFile(this: (idMapFile *)&varC0);
      }
      else
      {
        idLib::Printf(fmt: "%s has no map entities\n", v5.data);
        idMapFile::~idMapFile(this: (idMapFile *)&varC0);
      }
    }
    else
    {
      idLib::Printf(fmt: "Could not load %s\n", v5.data);
      idMapFile::~idMapFile(this: (idMapFile *)&varC0);
    }
    idStr::FreeData(this: &v5);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: writeEntitiesFile <mapname>\n");
  }
}


// ========================================================================
// __unwind$225483
// EA  : 0x826489F4
// RVA : 0x006489F4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$225484
// EA  : 0x82648A1C
// RVA : 0x00648A1C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$225485
// EA  : 0x82648A44
// RVA : 0x00648A44
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225485()
{
  int v0; // r12

  idMapFile::~idMapFile(this: (idMapFile *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$225486
// EA  : 0x82648A6C
// RVA : 0x00648A6C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// ?Com_Find_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82648D18
// RVA : 0x00648D18
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall Com_Find_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idStr *list; // r23
  signed int num; // r30
  int v5; // r25
  idDeclInfo *v6; // r30
  int v7; // r27
  int v8; // r28
  const char **p_str; // r29
  const char *v10; // r29
  const char *ResourceTypeName; // r3
  idResourceList *BufferPointer; // r29
  int v13; // r27
  int i; // r28
  idResource *v15; // r30
  const char *str; // r30
  const char *v17; // r3
  int v18; // r29
  const idCVar *v19; // r3
  const idCVar *v20; // r30
  int v21; // r11
  int v22; // r10
  int v23; // r10
  int v24; // r11
  int v25; // r8
  int v26; // r7
  int v27; // r6
  __int64 v28; // r10
  int v29; // r29
  int v30; // r30
  int v31; // r11
  int v32; // r10
  char *v33; // r3
  int v34; // r11
  int v35; // r10
  idStr *v36; // r29
  int v37; // r30
  idStr *v38; // r28
  int v39; // r30
  idStr *v40; // r29
  const char **p_data; // r29
  idStr *v42; // r29
  int size; // r30
  idStr *v44; // r28
  int v45; // r30
  idStr *v46; // r29
  idList<idStr,5> v47; // [sp+50h] [-150h] BYREF
  idList<idStr,5> v48; // [sp+60h] [-140h] BYREF
  idSort_Quick<idStr,idSort_Str> v49; // [sp+70h] [-130h] BYREF
  idStr v50; // [sp+80h] [-120h] BYREF
  idStr v51; // [sp+A0h] [-100h] BYREF
  idStr v52; // [sp+C0h] [-E0h] BYREF
  idStr v53; // [sp+E0h] [-C0h] BYREF
  idStr v54[5]; // [sp+100h] [-A0h] BYREF

  argc = args->argc;
  v49.__vftable = (idSort_Quick<idStr,idSort_Str>_vtbl *)args->argc;
  if ( v49.__vftable == (idSort_Quick<idStr,idSort_Str>_vtbl *)2 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: v54, text: v2);
    *(_WORD *)&v48.memTag = 1280;
    list = nullptr;
    num = 0;
    memset(&v48, 0, 14);
    v5 = 0;
    if ( declManager->GetNumDeclTypes(this: declManager) > 0 )
    {
      do
      {
        v6 = declManager->GetDeclType_2(this: declManager, a2: v5);
        v7 = 0;
        if ( v6->declSources.num > 0 )
        {
          v8 = 0;
          do
          {
            p_str = &v6->declSources.list[v8]->name.str;
            if ( idStr::Find(searchIn: *p_str, searchFor: v54[0].data, casesensitive: false, start: 0, end: -1) > -1 )
            {
              v52.allocedAndFlag = 20;
              v52.len = 0;
              v52.data = v52.baseBuffer;
              v52.baseBuffer[0] = 0;
              v10 = *p_str;
              ResourceTypeName = idResourceList::GetResourceTypeName(this: v6);
              idStr::Format(this: &v52, fmt: "^3[^2%s^3] ^0%s\n", ResourceTypeName, v10);
              idList<idStr,5>::Append(this: &v48, obj: &v52);
              idStr::FreeData(this: &v52);
            }
            ++v7;
            ++v8;
          }
          while ( v7 < v6->declSources.num );
        }
        ++v5;
      }
      while ( v5 < declManager->GetNumDeclTypes(this: declManager) );
      num = v48.num;
      list = v48.list;
    }
    BufferPointer = listOfResourceLists;
    if ( listOfResourceLists != nullptr )
    {
      do
      {
        if ( _RTDynamicCast(
               inptr: BufferPointer,
               VfDelta: 0,
               SrcType: &idResourceList `RTTI Type Descriptor',
               TargetType: &idDeclInfo `RTTI Type Descriptor',
               isReference: 0) == nullptr )
        {
          v13 = BufferPointer->num;
          for ( i = 0; i < v13; ++i )
          {
            v15 = idResourceList::Index(this: BufferPointer, index: i);
            if ( idStr::Find(searchIn: v15->name.str, searchFor: v54[0].data, casesensitive: false, start: 0, end: -1) > -1 )
            {
              v53.allocedAndFlag = 20;
              v53.len = 0;
              v53.data = v53.baseBuffer;
              v53.baseBuffer[0] = 0;
              str = v15->name.str;
              v17 = idResourceList::GetResourceTypeName(this: BufferPointer);
              idStr::Format(this: &v53, fmt: "^3[^2%s^3] ^0%s\n", v17, str);
              idList<idStr,5>::Append(this: &v48, obj: &v53);
              idStr::FreeData(this: &v53);
            }
          }
        }
        BufferPointer = (idResourceList *)D3DXShader::CConstantTable::GetBufferPointer(this: (D3DXCore::CBuffer *)BufferPointer);
      }
      while ( BufferPointer != nullptr );
      list = v48.list;
      num = v48.num;
    }
    v18 = 0;
    if ( cvarSystem->NumCVars(this: cvarSystem) > 0 )
    {
      do
      {
        v19 = cvarSystem->FindByIndex(this: cvarSystem, a2: v18);
        v20 = v19;
        if ( v19 != nullptr
          && idStr::Find(searchIn: v19->name, searchFor: v54[0].data, casesensitive: false, start: 0, end: -1) > -1 )
        {
          v50.allocedAndFlag = 20;
          v50.len = 0;
          v50.data = v50.baseBuffer;
          v50.baseBuffer[0] = 0;
          idStr::Format(this: &v50, fmt: "^4[^2%s^4] ^0%s", "cvar", v20->name);
          do
          {
            v21 = v50.len + 2;
            v22 = v50.allocedAndFlag & 0x7FFFFFFF;
            if ( v50.allocedAndFlag >= 0 )
            {
              if ( v21 > v22 )
                idStr::ReAllocate(this: &v50, amount: (v21 >> 1) + v21, keepold: true);
            }
            else if ( v21 > v22
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            v50.data[v50.len++] = 32;
            v50.data[v50.len] = 0;
          }
          while ( v50.len < 40 );
          idStr::Append(this: &v50, text: (char *)v20->description);
          v24 = v50.len + 2;
          v23 = v50.allocedAndFlag & 0x7FFFFFFF;
          if ( v50.allocedAndFlag >= 0 )
          {
            if ( v24 > v23 )
              idStr::ReAllocate(this: &v50, amount: (v24 >> 1) + v24, keepold: true);
          }
          else if ( v24 > v23
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v50.data[v50.len++] = 10;
          v50.data[v50.len] = 0;
          idList<idStr,5>::Append(this: &v48, obj: &v50);
          idStr::FreeData(this: &v50);
        }
        ++v18;
      }
      while ( v18 < cvarSystem->NumCVars(this: cvarSystem) );
      num = v48.num;
      list = v48.list;
    }
    *(_WORD *)&v47.memTag = 1280;
    memset(&v47, 0, 14);
    cmdSystem->FindCommands(this: cmdSystem, a2: v54[0].data, a3: &v47);
    HIDWORD(v28) = v47.num;
    v29 = 0;
    if ( v47.num > 0 )
    {
      v30 = 0;
      do
      {
        v51.allocedAndFlag = 20;
        v51.len = 0;
        v51.data = v51.baseBuffer;
        v51.baseBuffer[0] = 0;
        idStr::Format(this: &v51, fmt: "^5[^2%s^5] ^0%s", "command", v47.list[v30].data);
        do
        {
          v31 = v51.len + 2;
          v32 = v51.allocedAndFlag & 0x7FFFFFFF;
          if ( v51.allocedAndFlag >= 0 )
          {
            if ( v31 > v32 )
              idStr::ReAllocate(this: &v51, amount: (v31 >> 1) + v31, keepold: true);
          }
          else if ( v31 > v32
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v51.data[v51.len++] = 32;
          v51.data[v51.len] = 0;
        }
        while ( v51.len < 40 );
        v33 = (char *)cmdSystem->GetCommandDescription(this: cmdSystem, a2: v47.list[v30].data);
        idStr::Append(this: &v51, text: v33);
        v34 = v51.len + 2;
        v35 = v51.allocedAndFlag & 0x7FFFFFFF;
        if ( v51.allocedAndFlag >= 0 )
        {
          if ( v34 > v35 )
            idStr::ReAllocate(this: &v51, amount: (v34 >> 1) + v34, keepold: true);
        }
        else if ( v34 > v35
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        v51.data[v51.len++] = 10;
        v51.data[v51.len] = 0;
        idList<idStr,5>::Append(this: &v48, obj: &v51);
        idStr::FreeData(this: &v51);
        v26 = v47.num;
        ++v29;
        ++v30;
      }
      while ( v29 < v47.num );
      num = v48.num;
      list = v48.list;
    }
    v49.__vftable = (idSort_Quick<idStr,idSort_Str>_vtbl *)&idSort_Str::`vftable';
    if ( list != nullptr )
      idSort_Quick<idStr,idSort_Str>::Sort(this: &v49, base: list, num, a4: v27, a5: v26, a6: v25, a7: v28);
    v49.__vftable = (idSort_Quick<idStr,idSort_Str>_vtbl *)&idSort<idStr>::`vftable';
    if ( num != 0 )
    {
      idLib::Printf(fmt: "Found %d item(s):\n\n", num);
      if ( num > 0 )
      {
        p_data = (const char **)&list[-1].data;
        do
        {
          p_data += 8;
          idLib::Printf(fmt: *p_data);
          --num;
        }
        while ( num != 0 );
      }
      if ( v47.listStatic == 0 || v47.listStatic == 2 )
      {
        v42 = v47.list;
        if ( v47.list != nullptr )
        {
          size = v47.size;
          v44 = v47.list;
          if ( v47.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v42);
              --size;
              ++v42;
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: v44, align: ALIGN_16);
        }
        v47.list = nullptr;
        v47.size = 0;
      }
      v47.num = 0;
      if ( (v48.listStatic == 0 || v48.listStatic == 2) && list != nullptr )
      {
        v45 = v48.size;
        if ( v48.size > 0 )
        {
          v46 = list;
          do
          {
            idStr::FreeData(this: v46);
            --v45;
            ++v46;
          }
          while ( v45 != 0 );
        }
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
    }
    else
    {
      idLib::Printf(fmt: "^1No items found^0\n");
      if ( v47.listStatic == 0 || v47.listStatic == 2 )
      {
        v36 = v47.list;
        if ( v47.list != nullptr )
        {
          v37 = v47.size;
          v38 = v47.list;
          if ( v47.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v36);
              --v37;
              ++v36;
            }
            while ( v37 != 0 );
          }
          idMem::Free(this: &mem, ptr: v38, align: ALIGN_16);
        }
        v47.list = nullptr;
        v47.size = 0;
      }
      v47.num = 0;
      if ( (v48.listStatic == 0 || v48.listStatic == 2) && list != nullptr )
      {
        v39 = v48.size;
        if ( v48.size > 0 )
        {
          v40 = list;
          do
          {
            idStr::FreeData(this: v40);
            --v39;
            ++v40;
          }
          while ( v39 != 0 );
        }
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
    }
    idStr::FreeData(this: v54);
  }
  else
  {
    idLib::Printf(fmt: "Usage: find <search string>\n");
  }
}


// ========================================================================
// __unwind$225948
// EA  : 0x826495A8
// RVA : 0x006495A8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225948()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 256));
}


// ========================================================================
// __unwind$225949
// EA  : 0x826495D0
// RVA : 0x006495D0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225949()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$225950
// EA  : 0x826495F8
// RVA : 0x006495F8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$225951
// EA  : 0x82649620
// RVA : 0x00649620
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225951()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 224));
}


// ========================================================================
// __unwind$225952
// EA  : 0x82649648
// RVA : 0x00649648
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225952()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$225953
// EA  : 0x82649670
// RVA : 0x00649670
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225953()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$225954
// EA  : 0x82649698
// RVA : 0x00649698
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225954()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$225955
// EA  : 0x826496C0
// RVA : 0x006496C0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_225955()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 416 + 112));
}


// ========================================================================
// ?GetAllStrIdValues_r@@YAXPAVidTypeInfoObject@@PBVidTypeInfoTools@@ABVidStr@@AAV?$idList@VidStr@@$04@@3@Z
// EA  : 0x826496F0
// RVA : 0x006496F0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall GetAllStrIdValues_r(
        idTypeInfoObject *typeInfoObject,
        idTypeInfoTools *typeInfo,
        const idStr *path,
        idList<idStr,5> *stringTypePaths,
        idList<idStr,5> *stringTypeValues)
{
  const classTypeInfo_t *ClassInfo; // r3
  const classTypeInfo_t *v11; // r27
  int v12; // r26
  int v13; // r29
  char *data; // r9
  int v15; // r27
  idStr *v16; // r29
  int len; // r28
  char *v18; // r10
  char *v19; // r9
  char v20; // r11
  int v21; // r29
  int v22; // r3
  char *v23; // r7
  int i; // r29
  int v25; // r28
  int v26; // r4
  char *v27; // r10
  char *v28; // r9
  char v29; // r11
  int v30; // r10
  int v31; // r11
  idStr *list; // r28
  int size; // r29
  idStr *v34; // r27
  idStr *v35; // r28
  int v36; // r29
  idStr *v37; // r27
  idStr *v38; // r29
  int v39; // r30
  idStr *v40; // r28
  int v41[4]; // [sp+50h] [-230h] BYREF
  idList<idStr,5> v42; // [sp+60h] [-220h] BYREF
  idList<idStr,5> v43; // [sp+70h] [-210h] BYREF
  idList<idStr,5> v44; // [sp+80h] [-200h] BYREF
  int num; // [sp+90h] [-1F0h]
  idStr v46; // [sp+A0h] [-1E0h] BYREF
  idStr v47; // [sp+C0h] [-1C0h] BYREF
  idTypeInfoVariable_idList v48; // [sp+E0h] [-1A0h] BYREF
  idTypeInfoVariable_idStr v49; // [sp+F8h] [-188h] BYREF
  idStr v50; // [sp+110h] [-170h] BYREF
  idTypeInfoObject v51; // [sp+130h] [-150h] BYREF
  idStr v52; // [sp+160h] [-120h] BYREF
  idStr v53; // [sp+180h] [-100h] BYREF
  char v54[224]; // [sp+1A0h] [-E0h] BYREF

  ClassInfo = idTypeInfoTools::FindClassInfo(this: typeInfo, typeName: typeInfoObject->objectType.data);
  v11 = ClassInfo;
  if ( ClassInfo != nullptr )
  {
    *(_WORD *)&v44.memTag = 1280;
    memset(&v44, 0, 14);
    idTypeInfoTools::FindClassVariablePathsForTypeIncludingInherited(
      this: typeInfo,
      classInfo: ClassInfo,
      templateTypeName: "idStrId",
      ops: &byte_8200D768,
      variablePaths: &v44);
    v12 = 0;
    if ( v44.num > 0 )
    {
      v13 = 0;
      do
      {
        v50.allocedAndFlag = 20;
        v50.len = 0;
        v50.data = v50.baseBuffer;
        v50.baseBuffer[0] = 0;
        data = v44.list[v13].data;
        v49.type = "idStrId";
        v49.ops = &byte_8200D768;
        v49.path = data;
        idTypeInfoObject::GetStr(this: typeInfoObject, variable: &v49, s: &v50);
        if ( v50.len != 0 )
        {
          idStr::idStr(this: &v53, text: path);
          idStr::Append(this: &v53, text: &v44.list[v13]);
          idList<idStr,5>::Append(this: stringTypePaths, obj: &v53);
          idList<idStr,5>::Append(this: stringTypeValues, obj: &v50);
          idStr::FreeData(this: &v53);
        }
        idStr::FreeData(this: &v50);
        ++v12;
        ++v13;
      }
      while ( v12 < v44.num );
    }
    *(_WORD *)&v42.memTag = 1280;
    memset(&v42, 0, 14);
    *(_WORD *)&v43.memTag = 1280;
    memset(&v43, 0, 14);
    idTypeInfoTools::FindClassVariablePathsForTemplateTypeIncludingInherited(
      this: typeInfo,
      classInfo: v11,
      templateTypeName: "idList",
      ops: &byte_8200D768,
      variablePaths: &v42,
      variableTypes: &v43);
    if ( v42.num > 0 )
    {
      num = v42.num;
      v15 = 0;
      do
      {
        v47.allocedAndFlag = 20;
        v47.data = v47.baseBuffer;
        v16 = &v43.list[v15];
        v47.len = 0;
        v47.baseBuffer[0] = 0;
        len = v43.list[v15].len;
        if ( len + 1 > 20 )
          idStr::ReAllocate(this: &v47, amount: len + 1, keepold: true);
        v18 = v16->data - 1;
        v19 = v47.data - 1;
        do
        {
          v20 = *++v18;
          *++v19 = *v18;
        }
        while ( v20 != 0 );
        v47.len = len;
        v21 = idStr::Find(str: v47.data, c: 60, start: 0, end: len) + 1;
        v22 = idStr::Last(this: &v47, c: 44, index: -1);
        idStr::Mid(this: &v52, result: &v47, start: v21, len: v22 - v21);
        idStr::StripLeadingWhiteSpace(this: &v52);
        idStr::StripTrailingWhitespace(this: &v52);
        if ( v52.data[v52.len - 1] != 42 )
        {
          v23 = v42.list[v15].data;
          v48.type = v47.data;
          v48.ops = &byte_8200D768;
          v48.argType = v52.data;
          v48.argOps = &byte_8200D768;
          v48.path = v23;
          v41[0] = 0;
          idTypeInfoObject::GetListNum(this: typeInfoObject, variable: &v48, num: v41);
          for ( i = 0; i < v41[0]; ++i )
          {
            v25 = path->len;
            v26 = path->len + 1;
            v46.allocedAndFlag = 20;
            v46.len = 0;
            v46.data = v46.baseBuffer;
            v46.baseBuffer[0] = 0;
            if ( v25 + 1 > 20 )
              idStr::ReAllocate(this: &v46, amount: v26, keepold: true);
            v27 = path->data - 1;
            v28 = v46.data - 1;
            do
            {
              v29 = *++v27;
              *++v28 = *v27;
            }
            while ( v29 != 0 );
            v46.len = v25;
            idStr::Append(this: &v46, text: &v42.list[v15]);
            v31 = v46.len + 2;
            v30 = v46.allocedAndFlag & 0x7FFFFFFF;
            if ( v46.allocedAndFlag >= 0 )
            {
              if ( v31 > v30 )
                idStr::ReAllocate(this: &v46, amount: (v31 >> 1) + v31, keepold: true);
            }
            else if ( v31 > v30
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            v46.data[v46.len++] = 91;
            v46.data[v46.len] = 0;
            sprintf_0(string: v54, format: "%d", i);
            idStr::Append(this: &v46, text: v54);
            idStr::Append(this: &v46, text: "].");
            v51.objectType.len = 0;
            v51.objectType.baseBuffer[0] = 0;
            v51.objectType.data = v51.objectType.baseBuffer;
            v51.objectPtr = nullptr;
            v51.ti = nullptr;
            v51.modified = false;
            v51.objectType.allocedAndFlag = 20;
            idTypeInfoObject::GetTypeInfoObjectForListElement(
              this: typeInfoObject,
              variable: &v48,
              index: i,
              object: &v51);
            GetAllStrIdValues_r(typeInfoObject: &v51, typeInfo, path: &v46, stringTypePaths, stringTypeValues);
            idStr::FreeData(this: &v51.objectType);
            idStr::FreeData(this: &v46);
          }
        }
        idStr::FreeData(this: &v52);
        idStr::FreeData(this: &v47);
        ++v15;
        --num;
      }
      while ( num != 0 );
    }
    if ( v43.listStatic == 0 || v43.listStatic == 2 )
    {
      list = v43.list;
      if ( v43.list != nullptr )
      {
        size = v43.size;
        v34 = v43.list;
        if ( v43.size > 0 )
        {
          do
          {
            idStr::FreeData(this: list);
            --size;
            ++list;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
      }
      v43.list = nullptr;
      v43.size = 0;
    }
    v43.num = 0;
    if ( v42.listStatic == 0 || v42.listStatic == 2 )
    {
      v35 = v42.list;
      if ( v42.list != nullptr )
      {
        v36 = v42.size;
        v37 = v42.list;
        if ( v42.size > 0 )
        {
          do
          {
            idStr::FreeData(this: v35);
            --v36;
            ++v35;
          }
          while ( v36 != 0 );
        }
        idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
      }
      v42.list = nullptr;
      v42.size = 0;
    }
    v42.num = 0;
    if ( v44.listStatic == 0 || v44.listStatic == 2 )
    {
      v38 = v44.list;
      if ( v44.list != nullptr )
      {
        v39 = v44.size;
        v40 = v44.list;
        if ( v44.size > 0 )
        {
          do
          {
            idStr::FreeData(this: v38);
            --v39;
            ++v38;
          }
          while ( v39 != 0 );
        }
        idMem::Free(this: &mem, ptr: v40, align: ALIGN_16);
      }
    }
  }
}


// ========================================================================
// __unwind$226888
// EA  : 0x82649CAC
// RVA : 0x00649CAC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226888()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 640 + 128));
}


// ========================================================================
// __unwind$226889
// EA  : 0x82649CD4
// RVA : 0x00649CD4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226889()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 272));
}


// ========================================================================
// __unwind$226890
// EA  : 0x82649CFC
// RVA : 0x00649CFC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226890()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 384));
}


// ========================================================================
// __unwind$226891
// EA  : 0x82649D24
// RVA : 0x00649D24
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226891()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 640 + 96));
}


// ========================================================================
// __unwind$226892
// EA  : 0x82649D4C
// RVA : 0x00649D4C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226892()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 640 + 112));
}


// ========================================================================
// __unwind$226893
// EA  : 0x82649D74
// RVA : 0x00649D74
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226893()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 192));
}


// ========================================================================
// __unwind$226894
// EA  : 0x82649D9C
// RVA : 0x00649D9C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226894()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 352));
}


// ========================================================================
// __unwind$226895
// EA  : 0x82649DC4
// RVA : 0x00649DC4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226895()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$226896
// EA  : 0x82649DEC
// RVA : 0x00649DEC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_226896()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 640 + 304));
}


// ========================================================================
// ?GetAllStrIdValues@@YAXPAVidTypeInfoObject@@PBVidTypeInfoTools@@AAV?$idList@VidStr@@$04@@2@Z
// EA  : 0x82649E20
// RVA : 0x00649E20
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall GetAllStrIdValues(
        idTypeInfoObject *typeInfoObject,
        idTypeInfoTools *typeInfo,
        idList<idStr,5> *stringTypePaths,
        idList<idStr,5> *stringTypeValues)
{
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  idStr::idStr(this: v8, text: &byte_8200D768);
  GetAllStrIdValues_r(typeInfoObject, typeInfo, path: v8, stringTypePaths, stringTypeValues);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$227609
// EA  : 0x82649E78
// RVA : 0x00649E78
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227609()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?FindUnlocalizedStrings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82649EA8
// RVA : 0x00649EA8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall FindUnlocalizedStrings_f(const idCmdArgs *args)
{
  const char *v1; // r4
  int v2; // r29
  idDeclInfoTemplate<idDeclFX> *v3; // r24
  idDeclInfo *v4; // r3
  idDeclInfo *v5; // r21
  idDeclInfoTemplate<idDeclBreakable> *parent; // r11
  char v7; // r11
  idDeclInfoTemplate<idDeclAF> *v8; // r11
  char v9; // r11
  idDeclInfoTemplate<idDeclAnimWeb> *v10; // r11
  char v11; // r11
  idDeclInfoTemplate<idDeclFlare> *v12; // r11
  char v13; // r11
  idDeclInfoTemplate<idDeclFoliage> *v14; // r11
  char v15; // r11
  idDeclInfoTemplate<idDeclRibbon> *v16; // r11
  char v17; // r11
  idDeclInfoTemplate<idDeclRenderProg> *v18; // r11
  char v19; // r11
  idDeclInfoTemplate<idDeclRenderParm> *v20; // r11
  char v21; // r11
  idDeclInfoTemplate<idDeclMD6> *v22; // r11
  char v23; // r11
  idDeclInfoTemplate<idDeclVoiceOver> *v24; // r11
  char v25; // r11
  idDeclInfoTemplate<idMaterial> *v26; // r11
  char v27; // r11
  idDeclInfoTemplate<idDeclParticle> *v28; // r11
  char v29; // r11
  idDeclInfoTemplate<idSoundShader> *v30; // r11
  char v31; // r11
  idDeclInfoTemplate<idDeclCloth> *v32; // r11
  char v33; // r11
  idDeclInfoTemplate<idDeclWalkIK> *v34; // r11
  char v35; // r11
  idDeclInfoTemplate<idDeclTable> *v36; // r11
  char v37; // r11
  idDeclInfoTemplate<idDeclSkins> *v38; // r11
  char v39; // r11
  idDeclInfoTemplate<idDeclEnv> *v40; // r11
  char v41; // r11
  idDeclInfoTemplate<idDeclFX> *v42; // r11
  char v43; // r11
  idDeclInfoTemplate<idDeclEntityDef> *v44; // r11
  char v45; // r11
  idDeclInfoTemplate<idDeclVisemeSet> *v46; // r11
  char v47; // r11
  char v48; // r25
  int v49; // r24
  int num; // r23
  const char *str; // r4
  idDecl *v52; // r3
  const char **v53; // r30
  char v54; // r28
  idGame *v55; // r3
  idTypeInfoTools *v56; // r29
  int v57; // r3
  int v58; // r27
  int v59; // r29
  const char *String; // r3
  char *filePtr; // r28
  idFile_vtbl *v62; // r30
  unsigned int v63; // r3
  int v64; // [sp+50h] [-2E0h]
  idFile *v65; // [sp+54h] [-2DCh]
  int v66; // [sp+58h] [-2D8h]
  idList<idStr,5> v67; // [sp+60h] [-2D0h] BYREF
  idList<idStr,5> v68; // [sp+70h] [-2C0h] BYREF
  idDeclInfoTemplate<idDeclParticle> *v69; // [sp+80h] [-2B0h]
  struct idDeclTypeInfo *v70; // [sp+84h] [-2ACh]
  struct idDecl *v71; // [sp+88h] [-2A8h]
  idDeclInfoTemplate<idDeclRibbon> *v72; // [sp+8Ch] [-2A4h]
  const char *v73; // [sp+90h] [-2A0h]
  idDeclInfoTemplate<idDeclRenderParm> *v74; // [sp+94h] [-29Ch]
  const char *v75; // [sp+98h] [-298h]
  idDeclInfoTemplate<idDeclVoiceOver> *v76; // [sp+9Ch] [-294h]
  idDeclInfoTemplate<idDeclFX> *v77; // [sp+A0h] [-290h]
  idDeclInfoTemplate<idDeclBreakable> *v78; // [sp+A4h] [-28Ch]
  idDeclInfoTemplate<idDeclAF> *v79; // [sp+A8h] [-288h]
  idDeclInfoTemplate<idDeclVisemeSet> *v80; // [sp+ACh] [-284h]
  idDeclInfoTemplate<idDeclAnimWeb> *v81; // [sp+B0h] [-280h]
  idDeclInfoTemplate<idDeclRenderProg> *v82; // [sp+B4h] [-27Ch]
  idDeclInfoTemplate<idDeclFlare> *v83; // [sp+B8h] [-278h]
  idDeclInfoTemplate<idMaterial> *v84; // [sp+BCh] [-274h]
  idDeclInfoTemplate<idDeclMD6> *v85; // [sp+C0h] [-270h]
  idDeclInfoTemplate<idDeclFoliage> *v86; // [sp+C4h] [-26Ch]
  idDeclInfoTemplate<idSoundShader> *v87; // [sp+C8h] [-268h]
  idStr v88; // [sp+D0h] [-260h] BYREF
  idStr v89; // [sp+F0h] [-240h] BYREF
  idTypeInfoObject v90; // [sp+110h] [-220h] BYREF
  idFile_Memory v91; // [sp+140h] [-1F0h] BYREF

  v88.len = 0;
  v88.allocedAndFlag = 20;
  v88.data = v88.baseBuffer;
  v88.baseBuffer[0] = 0;
  if ( args->argc > 1 )
    v1 = args->argv[1];
  else
    v1 = "unlocalstrings/unlocalstrings";
  idStr::operator=(this: &v88, text: v1);
  idStr::SetFileExtension(this: &v88, extension: "txt");
  v65 = fileSystem->OpenFileWrite(this: fileSystem, a2: v88.data, a3: 2);
  if ( v65 != nullptr )
  {
    v64 = 0;
    v66 = declManager->GetNumDeclTypes(this: declManager);
    if ( v66 > 0 )
    {
      v75 = "\t%s:\t\t%s\n";
      v85 = &idDeclMD6::resourceList;
      v2 = 0;
      v84 = &idMaterial::resourceList;
      v73 = "\nDECL CLASS:\t %s\n";
      v72 = &idDeclRibbon::resourceList;
      v74 = &idDeclRenderParm::resourceList;
      v82 = &idDeclRenderProg::resourceList;
      v3 = &idDeclFX::resourceList;
      v71 = &idDecl `RTTI Type Descriptor';
      v70 = &idDeclTypeInfo `RTTI Type Descriptor';
      v77 = &idDeclFX::resourceList;
      v80 = &idDeclVisemeSet::resourceList;
      v87 = &idSoundShader::resourceList;
      v69 = &idDeclParticle::resourceList;
      v76 = &idDeclVoiceOver::resourceList;
      v86 = &idDeclFoliage::resourceList;
      v83 = &idDeclFlare::resourceList;
      v81 = &idDeclAnimWeb::resourceList;
      v79 = &idDeclAF::resourceList;
      v78 = &idDeclBreakable::resourceList;
      do
      {
        v4 = declManager->GetDeclType_2(this: declManager, a2: v2);
        v5 = v4;
        if ( v4 != nullptr )
        {
          parent = (idDeclInfoTemplate<idDeclBreakable> *)v4;
          while ( parent != v78 )
          {
            parent = (idDeclInfoTemplate<idDeclBreakable> *)parent->parent;
            if ( parent == nullptr )
            {
              v7 = 0;
              goto LABEL_13;
            }
          }
          v7 = 1;
LABEL_13:
          if ( v7 == 0 )
          {
            v8 = (idDeclInfoTemplate<idDeclAF> *)v4;
            while ( v8 != v79 )
            {
              v8 = (idDeclInfoTemplate<idDeclAF> *)v8->parent;
              if ( v8 == nullptr )
              {
                v9 = 0;
                goto LABEL_18;
              }
            }
            v9 = 1;
LABEL_18:
            if ( v9 == 0 )
            {
              v10 = (idDeclInfoTemplate<idDeclAnimWeb> *)v4;
              while ( v10 != v81 )
              {
                v10 = (idDeclInfoTemplate<idDeclAnimWeb> *)v10->parent;
                if ( v10 == nullptr )
                {
                  v11 = 0;
                  goto LABEL_23;
                }
              }
              v11 = 1;
LABEL_23:
              if ( v11 == 0 )
              {
                v12 = (idDeclInfoTemplate<idDeclFlare> *)v4;
                while ( v12 != v83 )
                {
                  v12 = (idDeclInfoTemplate<idDeclFlare> *)v12->parent;
                  if ( v12 == nullptr )
                  {
                    v13 = 0;
                    goto LABEL_28;
                  }
                }
                v13 = 1;
LABEL_28:
                if ( v13 == 0 )
                {
                  v14 = (idDeclInfoTemplate<idDeclFoliage> *)v4;
                  while ( v14 != v86 )
                  {
                    v14 = (idDeclInfoTemplate<idDeclFoliage> *)v14->parent;
                    if ( v14 == nullptr )
                    {
                      v15 = 0;
                      goto LABEL_33;
                    }
                  }
                  v15 = 1;
LABEL_33:
                  if ( v15 == 0 )
                  {
                    v16 = (idDeclInfoTemplate<idDeclRibbon> *)v4;
                    while ( v16 != v72 )
                    {
                      v16 = (idDeclInfoTemplate<idDeclRibbon> *)v16->parent;
                      if ( v16 == nullptr )
                      {
                        v17 = 0;
                        goto LABEL_38;
                      }
                    }
                    v17 = 1;
LABEL_38:
                    if ( v17 == 0 )
                    {
                      v18 = (idDeclInfoTemplate<idDeclRenderProg> *)v4;
                      while ( v18 != v82 )
                      {
                        v18 = (idDeclInfoTemplate<idDeclRenderProg> *)v18->parent;
                        if ( v18 == nullptr )
                        {
                          v19 = 0;
                          goto LABEL_43;
                        }
                      }
                      v19 = 1;
LABEL_43:
                      if ( v19 == 0 )
                      {
                        v20 = (idDeclInfoTemplate<idDeclRenderParm> *)v4;
                        while ( v20 != v74 )
                        {
                          v20 = (idDeclInfoTemplate<idDeclRenderParm> *)v20->parent;
                          if ( v20 == nullptr )
                          {
                            v21 = 0;
                            goto LABEL_48;
                          }
                        }
                        v21 = 1;
LABEL_48:
                        if ( v21 == 0 )
                        {
                          v22 = (idDeclInfoTemplate<idDeclMD6> *)v4;
                          while ( v22 != v85 )
                          {
                            v22 = (idDeclInfoTemplate<idDeclMD6> *)v22->parent;
                            if ( v22 == nullptr )
                            {
                              v23 = 0;
                              goto LABEL_53;
                            }
                          }
                          v23 = 1;
LABEL_53:
                          if ( v23 == 0 )
                          {
                            v24 = (idDeclInfoTemplate<idDeclVoiceOver> *)v4;
                            while ( v24 != v76 )
                            {
                              v24 = (idDeclInfoTemplate<idDeclVoiceOver> *)v24->parent;
                              if ( v24 == nullptr )
                              {
                                v25 = 0;
                                goto LABEL_58;
                              }
                            }
                            v25 = 1;
LABEL_58:
                            if ( v25 == 0 )
                            {
                              v26 = (idDeclInfoTemplate<idMaterial> *)v4;
                              while ( v26 != v84 )
                              {
                                v26 = (idDeclInfoTemplate<idMaterial> *)v26->parent;
                                if ( v26 == nullptr )
                                {
                                  v27 = 0;
                                  goto LABEL_63;
                                }
                              }
                              v27 = 1;
LABEL_63:
                              if ( v27 == 0 )
                              {
                                v28 = (idDeclInfoTemplate<idDeclParticle> *)v4;
                                while ( v28 != v69 )
                                {
                                  v28 = (idDeclInfoTemplate<idDeclParticle> *)v28->parent;
                                  if ( v28 == nullptr )
                                  {
                                    v29 = 0;
                                    goto LABEL_68;
                                  }
                                }
                                v29 = 1;
LABEL_68:
                                if ( v29 == 0 )
                                {
                                  v30 = (idDeclInfoTemplate<idSoundShader> *)v4;
                                  while ( v30 != v87 )
                                  {
                                    v30 = (idDeclInfoTemplate<idSoundShader> *)v30->parent;
                                    if ( v30 == nullptr )
                                    {
                                      v31 = 0;
                                      goto LABEL_73;
                                    }
                                  }
                                  v31 = 1;
LABEL_73:
                                  if ( v31 == 0 )
                                  {
                                    v32 = (idDeclInfoTemplate<idDeclCloth> *)v4;
                                    while ( v32 != &idDeclCloth::resourceList )
                                    {
                                      v32 = (idDeclInfoTemplate<idDeclCloth> *)v32->parent;
                                      if ( v32 == nullptr )
                                      {
                                        v33 = 0;
                                        goto LABEL_78;
                                      }
                                    }
                                    v33 = 1;
LABEL_78:
                                    if ( v33 == 0 )
                                    {
                                      v34 = (idDeclInfoTemplate<idDeclWalkIK> *)v4;
                                      while ( v34 != &idDeclWalkIK::resourceList )
                                      {
                                        v34 = (idDeclInfoTemplate<idDeclWalkIK> *)v34->parent;
                                        if ( v34 == nullptr )
                                        {
                                          v35 = 0;
                                          goto LABEL_83;
                                        }
                                      }
                                      v35 = 1;
LABEL_83:
                                      if ( v35 == 0 )
                                      {
                                        v36 = (idDeclInfoTemplate<idDeclTable> *)v4;
                                        while ( v36 != &idDeclTable::resourceList )
                                        {
                                          v36 = (idDeclInfoTemplate<idDeclTable> *)v36->parent;
                                          if ( v36 == nullptr )
                                          {
                                            v37 = 0;
                                            goto LABEL_88;
                                          }
                                        }
                                        v37 = 1;
LABEL_88:
                                        if ( v37 == 0 )
                                        {
                                          v38 = (idDeclInfoTemplate<idDeclSkins> *)v4;
                                          while ( v38 != &idDeclSkins::resourceList )
                                          {
                                            v38 = (idDeclInfoTemplate<idDeclSkins> *)v38->parent;
                                            if ( v38 == nullptr )
                                            {
                                              v39 = 0;
                                              goto LABEL_93;
                                            }
                                          }
                                          v39 = 1;
LABEL_93:
                                          if ( v39 == 0 )
                                          {
                                            v40 = (idDeclInfoTemplate<idDeclEnv> *)v4;
                                            while ( v40 != &idDeclEnv::resourceList )
                                            {
                                              v40 = (idDeclInfoTemplate<idDeclEnv> *)v40->parent;
                                              if ( v40 == nullptr )
                                              {
                                                v41 = 0;
                                                goto LABEL_98;
                                              }
                                            }
                                            v41 = 1;
LABEL_98:
                                            if ( v41 == 0 )
                                            {
                                              v42 = (idDeclInfoTemplate<idDeclFX> *)v4;
                                              while ( v42 != v3 )
                                              {
                                                v42 = (idDeclInfoTemplate<idDeclFX> *)v42->parent;
                                                if ( v42 == nullptr )
                                                {
                                                  v43 = 0;
                                                  goto LABEL_103;
                                                }
                                              }
                                              v43 = 1;
LABEL_103:
                                              if ( v43 == 0 )
                                              {
                                                v44 = (idDeclInfoTemplate<idDeclEntityDef> *)v4;
                                                while ( v44 != &idDeclEntityDef::resourceList )
                                                {
                                                  v44 = (idDeclInfoTemplate<idDeclEntityDef> *)v44->parent;
                                                  if ( v44 == nullptr )
                                                  {
                                                    v45 = 0;
                                                    goto LABEL_108;
                                                  }
                                                }
                                                v45 = 1;
LABEL_108:
                                                if ( v45 == 0 )
                                                {
                                                  v46 = (idDeclInfoTemplate<idDeclVisemeSet> *)v4;
                                                  while ( v46 != v80 )
                                                  {
                                                    v46 = (idDeclInfoTemplate<idDeclVisemeSet> *)v46->parent;
                                                    if ( v46 == nullptr )
                                                    {
                                                      v47 = 0;
                                                      goto LABEL_113;
                                                    }
                                                  }
                                                  v47 = 1;
LABEL_113:
                                                  if ( v47 == 0 )
                                                  {
                                                    v48 = 0;
                                                    if ( v4->declSources.num > 0 )
                                                    {
                                                      v49 = 0;
                                                      num = v4->declSources.num;
                                                      do
                                                      {
                                                        str = v5->declSources.list[v49]->name.str;
                                                        if ( str != nullptr )
                                                          v52 = (idDecl *)idDeclInfo::FindWithInheritance(
                                                                            this: v5,
                                                                            name: str,
                                                                            makeDefault: false);
                                                        else
                                                          v52 = nullptr;
                                                        v53 = (const char **)_RTDynamicCast(
                                                                               inptr: v52,
                                                                               VfDelta: 0,
                                                                               SrcType: v71,
                                                                               TargetType: v70,
                                                                               isReference: 0);
                                                        if ( v53 != nullptr )
                                                        {
                                                          idFile_Memory::idFile_Memory(this: &v91);
                                                          v54 = 0;
                                                          v55 = common->Game(this: common);
                                                          v56 = (idTypeInfoTools *)v55->GetTypeInfoTools(this: v55);
                                                          *(_WORD *)&v68.memTag = 1280;
                                                          memset(&v68, 0, 14);
                                                          *(_WORD *)&v67.memTag = 1280;
                                                          memset(&v67, 0, 14);
                                                          v57 = (*((int (__fastcall **)(const char **))*v53 + 8))(a1: v53);
                                                          idTypeInfoObject::idTypeInfoObject(
                                                            this: &v90,
                                                            objectPtr: v53,
                                                            objectType: *(const char **)(v57 + 1048),
                                                            ti: v56);
                                                          GetAllStrIdValues(
                                                            typeInfoObject: &v90,
                                                            typeInfo: v56,
                                                            stringTypePaths: &v68,
                                                            stringTypeValues: &v67);
                                                          v58 = 0;
                                                          if ( v67.num > 0 )
                                                          {
                                                            v59 = 0;
                                                            do
                                                            {
                                                              idStr::idStr(this: &v89, text: &v67.list[v59]);
                                                              String = idLocalization::GetString(inString: v89.data);
                                                              if ( idStr::Icmp(s1: v89.data, s2: String) == 0 )
                                                              {
                                                                if ( v48 == 0 )
                                                                {
                                                                  idFile::Printf(this: &v91, fmt: v73, v5->name);
                                                                  v48 = 1;
                                                                }
                                                                if ( v54 == 0 )
                                                                {
                                                                  idFile::Printf(
                                                                    this: &v91,
                                                                    fmt: "\ndecl:\t %s\n",
                                                                    v53[2]);
                                                                  v54 = 1;
                                                                }
                                                                idFile::Printf(
                                                                  this: &v91,
                                                                  fmt: v75,
                                                                  v68.list[v59].data,
                                                                  v89.data);
                                                              }
                                                              idStr::FreeData(this: &v89);
                                                              ++v58;
                                                              ++v59;
                                                            }
                                                            while ( v58 < v67.num );
                                                          }
                                                          filePtr = v91.filePtr;
                                                          v62 = v65->__vftable;
                                                          v63 = (unsigned __int64)idFile_Memory::Length(this: &v91) >> 32;
                                                          v62->Write(this: v65, a2: filePtr, a3: v63);
                                                          idStr::FreeData(this: &v90.objectType);
                                                          idList<idStr,99>::~idList<idStr,99>(this: &v67);
                                                          idList<idStr,99>::~idList<idStr,99>(this: &v68);
                                                          idFile_Memory::~idFile_Memory(this: &v91);
                                                          v2 = v64;
                                                        }
                                                        --num;
                                                        ++v49;
                                                      }
                                                      while ( num != 0 );
                                                      v3 = v77;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v64 = ++v2;
      }
      while ( v2 < v66 );
    }
    ((void (__fastcall *)(idFile *, int))v65->dtr_idFile)(a1: v65, a2: 1);
  }
  else
  {
    idLib::Warning(fmt: "could not create file");
  }
  idStr::FreeData(this: &v88);
}


// ========================================================================
// __unwind$227634
// EA  : 0x8264A75C
// RVA : 0x0064A75C
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227634()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 816 + 208));
}


// ========================================================================
// __unwind$227635
// EA  : 0x8264A784
// RVA : 0x0064A784
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227635()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 816 + 320));
}


// ========================================================================
// __unwind$227636
// EA  : 0x8264A7AC
// RVA : 0x0064A7AC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227636()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 816 + 112));
}


// ========================================================================
// __unwind$227637
// EA  : 0x8264A7D4
// RVA : 0x0064A7D4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227637()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 816 + 96));
}


// ========================================================================
// __unwind$227638
// EA  : 0x8264A7FC
// RVA : 0x0064A7FC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227638()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 816 + 272));
}


// ========================================================================
// __unwind$227639
// EA  : 0x8264A824
// RVA : 0x0064A824
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_227639()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 816 + 240));
}


// ========================================================================
// ?FindUnreferencedStrings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264A858
// RVA : 0x0064A858
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall FindUnreferencedStrings_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr *list; // r22
  int size; // r21
  int v4; // r30
  idDeclInfoTemplate<idDeclWalkIK> *v5; // r30
  int v6; // r29
  idDeclInfo *v7; // r3
  idDeclInfo *v8; // r26
  idDeclInfoTemplate<idDeclBreakable> *parent; // r11
  char v10; // r11
  idDeclInfoTemplate<idDeclAF> *v11; // r11
  char v12; // r11
  idDeclInfoTemplate<idDeclAnimWeb> *v13; // r11
  char v14; // r11
  idDeclInfoTemplate<idDeclFlare> *v15; // r11
  char v16; // r11
  idDeclInfoTemplate<idDeclFoliage> *v17; // r11
  char v18; // r11
  idDeclInfoTemplate<idDeclRibbon> *v19; // r11
  char v20; // r11
  idDeclInfoTemplate<idDeclRenderProg> *v21; // r11
  char v22; // r11
  idDeclInfoTemplate<idDeclRenderParm> *v23; // r11
  char v24; // r11
  idDeclInfoTemplate<idDeclMD6> *v25; // r11
  char v26; // r11
  idDeclInfoTemplate<idDeclVoiceOver> *v27; // r11
  char v28; // r11
  idDeclInfoTemplate<idMaterial> *v29; // r11
  char v30; // r11
  idDeclInfoTemplate<idDeclParticle> *v31; // r11
  char v32; // r11
  idDeclInfoTemplate<idSoundShader> *v33; // r11
  char v34; // r11
  idDeclInfoTemplate<idDeclCloth> *v35; // r11
  char v36; // r11
  idDeclInfoTemplate<idDeclWalkIK> *v37; // r11
  char v38; // r11
  idDeclInfoTemplate<idDeclTable> *v39; // r11
  char v40; // r11
  idDeclInfoTemplate<idDeclSkins> *v41; // r11
  char v42; // r11
  idDeclInfoTemplate<idDeclEnv> *v43; // r11
  char v44; // r11
  idDeclInfoTemplate<idDeclFX> *v45; // r11
  char v46; // r11
  idDeclInfoTemplate<idDeclEntityDef> *v47; // r11
  char v48; // r11
  idDeclInfoTemplate<idDeclVisemeSet> *v49; // r11
  char v50; // r11
  int v51; // r28
  int num; // r27
  const char *str; // r4
  idDecl *v54; // r3
  void *v55; // r30
  idGame *v56; // r3
  idTypeInfoTools *v57; // r29
  int v58; // r3
  int v59; // r29
  int v60; // r30
  idRenderModelDecal *Flags; // r3
  idRenderModelDecal *v62; // r3
  int v63; // r27
  int i; // r26
  const idLangKeyValue *KeyVal; // r30
  int Index; // r3
  int v67; // r29
  idFile_vtbl *v68; // r30
  char *filePtr; // r28
  unsigned int v70; // r3
  idStr *v71; // r29
  int j; // r30
  int v73; // [sp+50h] [-320h]
  idFile *v74; // [sp+54h] [-31Ch]
  idList<idStr,5> v75; // [sp+60h] [-310h] BYREF
  idList<idStr,5> v76; // [sp+70h] [-300h] BYREF
  idList<idStr,5> v77; // [sp+80h] [-2F0h] BYREF
  struct idDecl *v78; // [sp+90h] [-2E0h]
  int v79; // [sp+94h] [-2DCh]
  idDeclInfoTemplate<idDeclRibbon> *v80; // [sp+98h] [-2D8h]
  idDeclInfoTemplate<idDeclAF> *v81; // [sp+9Ch] [-2D4h]
  idDeclInfoTemplate<idDeclEnv> *v82; // [sp+A0h] [-2D0h]
  idDeclInfoTemplate<idDeclAnimWeb> *v83; // [sp+A4h] [-2CCh]
  idDeclInfoTemplate<idDeclEntityDef> *v84; // [sp+A8h] [-2C8h]
  idDeclInfoTemplate<idDeclFlare> *v85; // [sp+ACh] [-2C4h]
  struct idDeclTypeInfo *v86; // [sp+B0h] [-2C0h]
  idDeclInfoTemplate<idDeclFoliage> *v87; // [sp+B4h] [-2BCh]
  const char *v88; // [sp+B8h] [-2B8h]
  idDeclInfoTemplate<idDeclVisemeSet> *v89; // [sp+BCh] [-2B4h]
  idDeclInfoTemplate<idDeclSkins> *v90; // [sp+C0h] [-2B0h]
  idDeclInfoTemplate<idDeclBreakable> *v91; // [sp+C4h] [-2ACh]
  idDeclInfoTemplate<idDeclFX> *v92; // [sp+C8h] [-2A8h]
  idDeclInfoTemplate<idDeclWalkIK> *v93; // [sp+CCh] [-2A4h]
  idStr v94; // [sp+D0h] [-2A0h] BYREF
  idStr v95; // [sp+F0h] [-280h] BYREF
  idStr v96; // [sp+110h] [-260h] BYREF
  idStr v97; // [sp+130h] [-240h] BYREF
  idTypeInfoObject v98; // [sp+150h] [-220h] BYREF
  idFile_Memory v99; // [sp+180h] [-1F0h] BYREF

  v94.len = 0;
  v94.allocedAndFlag = 20;
  v94.data = v94.baseBuffer;
  v94.baseBuffer[0] = 0;
  if ( args->argc > 1 )
    v1 = args->argv[1];
  else
    v1 = "unlocalstrings/unreferencedstrings";
  idStr::operator=(this: &v94, text: v1);
  idStr::SetFileExtension(this: &v94, extension: "txt");
  v74 = fileSystem->OpenFileWrite(this: fileSystem, a2: v94.data, a3: 2);
  if ( v74 != nullptr )
  {
    *(_WORD *)&v75.memTag = 1280;
    list = nullptr;
    size = 0;
    memset(&v75, 0, 14);
    v4 = 0;
    v73 = 0;
    v79 = declManager->GetNumDeclTypes(this: declManager);
    if ( v79 > 0 )
    {
      v86 = &idDeclTypeInfo `RTTI Type Descriptor';
      v88 = "#str_racername_racebuggy";
      v78 = &idDecl `RTTI Type Descriptor';
      v90 = &idDeclSkins::resourceList;
      v89 = &idDeclVisemeSet::resourceList;
      v84 = &idDeclEntityDef::resourceList;
      v92 = &idDeclFX::resourceList;
      v82 = &idDeclEnv::resourceList;
      v5 = &idDeclWalkIK::resourceList;
      v83 = &idDeclAnimWeb::resourceList;
      v93 = &idDeclWalkIK::resourceList;
      v80 = &idDeclRibbon::resourceList;
      v87 = &idDeclFoliage::resourceList;
      v85 = &idDeclFlare::resourceList;
      v6 = 0;
      v81 = &idDeclAF::resourceList;
      v91 = &idDeclBreakable::resourceList;
      do
      {
        v7 = declManager->GetDeclType_2(this: declManager, a2: v6);
        v8 = v7;
        if ( v7 != nullptr )
        {
          parent = (idDeclInfoTemplate<idDeclBreakable> *)v7;
          while ( parent != v91 )
          {
            parent = (idDeclInfoTemplate<idDeclBreakable> *)parent->parent;
            if ( parent == nullptr )
            {
              v10 = 0;
              goto LABEL_13;
            }
          }
          v10 = 1;
LABEL_13:
          if ( v10 == 0 )
          {
            v11 = (idDeclInfoTemplate<idDeclAF> *)v7;
            while ( v11 != v81 )
            {
              v11 = (idDeclInfoTemplate<idDeclAF> *)v11->parent;
              if ( v11 == nullptr )
              {
                v12 = 0;
                goto LABEL_18;
              }
            }
            v12 = 1;
LABEL_18:
            if ( v12 == 0 )
            {
              v13 = (idDeclInfoTemplate<idDeclAnimWeb> *)v7;
              while ( v13 != v83 )
              {
                v13 = (idDeclInfoTemplate<idDeclAnimWeb> *)v13->parent;
                if ( v13 == nullptr )
                {
                  v14 = 0;
                  goto LABEL_23;
                }
              }
              v14 = 1;
LABEL_23:
              if ( v14 == 0 )
              {
                v15 = (idDeclInfoTemplate<idDeclFlare> *)v7;
                while ( v15 != v85 )
                {
                  v15 = (idDeclInfoTemplate<idDeclFlare> *)v15->parent;
                  if ( v15 == nullptr )
                  {
                    v16 = 0;
                    goto LABEL_28;
                  }
                }
                v16 = 1;
LABEL_28:
                if ( v16 == 0 )
                {
                  v17 = (idDeclInfoTemplate<idDeclFoliage> *)v7;
                  while ( v17 != v87 )
                  {
                    v17 = (idDeclInfoTemplate<idDeclFoliage> *)v17->parent;
                    if ( v17 == nullptr )
                    {
                      v18 = 0;
                      goto LABEL_33;
                    }
                  }
                  v18 = 1;
LABEL_33:
                  if ( v18 == 0 )
                  {
                    v19 = (idDeclInfoTemplate<idDeclRibbon> *)v7;
                    while ( v19 != v80 )
                    {
                      v19 = (idDeclInfoTemplate<idDeclRibbon> *)v19->parent;
                      if ( v19 == nullptr )
                      {
                        v20 = 0;
                        goto LABEL_38;
                      }
                    }
                    v20 = 1;
LABEL_38:
                    if ( v20 == 0 )
                    {
                      v21 = (idDeclInfoTemplate<idDeclRenderProg> *)v7;
                      while ( v21 != &idDeclRenderProg::resourceList )
                      {
                        v21 = (idDeclInfoTemplate<idDeclRenderProg> *)v21->parent;
                        if ( v21 == nullptr )
                        {
                          v22 = 0;
                          goto LABEL_43;
                        }
                      }
                      v22 = 1;
LABEL_43:
                      if ( v22 == 0 )
                      {
                        v23 = (idDeclInfoTemplate<idDeclRenderParm> *)v7;
                        while ( v23 != &idDeclRenderParm::resourceList )
                        {
                          v23 = (idDeclInfoTemplate<idDeclRenderParm> *)v23->parent;
                          if ( v23 == nullptr )
                          {
                            v24 = 0;
                            goto LABEL_48;
                          }
                        }
                        v24 = 1;
LABEL_48:
                        if ( v24 == 0 )
                        {
                          v25 = (idDeclInfoTemplate<idDeclMD6> *)v7;
                          while ( v25 != &idDeclMD6::resourceList )
                          {
                            v25 = (idDeclInfoTemplate<idDeclMD6> *)v25->parent;
                            if ( v25 == nullptr )
                            {
                              v26 = 0;
                              goto LABEL_53;
                            }
                          }
                          v26 = 1;
LABEL_53:
                          if ( v26 == 0 )
                          {
                            v27 = (idDeclInfoTemplate<idDeclVoiceOver> *)v7;
                            while ( v27 != &idDeclVoiceOver::resourceList )
                            {
                              v27 = (idDeclInfoTemplate<idDeclVoiceOver> *)v27->parent;
                              if ( v27 == nullptr )
                              {
                                v28 = 0;
                                goto LABEL_58;
                              }
                            }
                            v28 = 1;
LABEL_58:
                            if ( v28 == 0 )
                            {
                              v29 = (idDeclInfoTemplate<idMaterial> *)v7;
                              while ( v29 != &idMaterial::resourceList )
                              {
                                v29 = (idDeclInfoTemplate<idMaterial> *)v29->parent;
                                if ( v29 == nullptr )
                                {
                                  v30 = 0;
                                  goto LABEL_63;
                                }
                              }
                              v30 = 1;
LABEL_63:
                              if ( v30 == 0 )
                              {
                                v31 = (idDeclInfoTemplate<idDeclParticle> *)v7;
                                while ( v31 != &idDeclParticle::resourceList )
                                {
                                  v31 = (idDeclInfoTemplate<idDeclParticle> *)v31->parent;
                                  if ( v31 == nullptr )
                                  {
                                    v32 = 0;
                                    goto LABEL_68;
                                  }
                                }
                                v32 = 1;
LABEL_68:
                                if ( v32 == 0 )
                                {
                                  v33 = (idDeclInfoTemplate<idSoundShader> *)v7;
                                  while ( v33 != &idSoundShader::resourceList )
                                  {
                                    v33 = (idDeclInfoTemplate<idSoundShader> *)v33->parent;
                                    if ( v33 == nullptr )
                                    {
                                      v34 = 0;
                                      goto LABEL_73;
                                    }
                                  }
                                  v34 = 1;
LABEL_73:
                                  if ( v34 == 0 )
                                  {
                                    v35 = (idDeclInfoTemplate<idDeclCloth> *)v7;
                                    while ( v35 != &idDeclCloth::resourceList )
                                    {
                                      v35 = (idDeclInfoTemplate<idDeclCloth> *)v35->parent;
                                      if ( v35 == nullptr )
                                      {
                                        v36 = 0;
                                        goto LABEL_78;
                                      }
                                    }
                                    v36 = 1;
LABEL_78:
                                    if ( v36 == 0 )
                                    {
                                      v37 = (idDeclInfoTemplate<idDeclWalkIK> *)v7;
                                      while ( v37 != v5 )
                                      {
                                        v37 = (idDeclInfoTemplate<idDeclWalkIK> *)v37->parent;
                                        if ( v37 == nullptr )
                                        {
                                          v38 = 0;
                                          goto LABEL_83;
                                        }
                                      }
                                      v38 = 1;
LABEL_83:
                                      if ( v38 == 0 )
                                      {
                                        v39 = (idDeclInfoTemplate<idDeclTable> *)v7;
                                        while ( v39 != &idDeclTable::resourceList )
                                        {
                                          v39 = (idDeclInfoTemplate<idDeclTable> *)v39->parent;
                                          if ( v39 == nullptr )
                                          {
                                            v40 = 0;
                                            goto LABEL_88;
                                          }
                                        }
                                        v40 = 1;
LABEL_88:
                                        if ( v40 == 0 )
                                        {
                                          v41 = (idDeclInfoTemplate<idDeclSkins> *)v7;
                                          while ( v41 != v90 )
                                          {
                                            v41 = (idDeclInfoTemplate<idDeclSkins> *)v41->parent;
                                            if ( v41 == nullptr )
                                            {
                                              v42 = 0;
                                              goto LABEL_93;
                                            }
                                          }
                                          v42 = 1;
LABEL_93:
                                          if ( v42 == 0 )
                                          {
                                            v43 = (idDeclInfoTemplate<idDeclEnv> *)v7;
                                            while ( v43 != v82 )
                                            {
                                              v43 = (idDeclInfoTemplate<idDeclEnv> *)v43->parent;
                                              if ( v43 == nullptr )
                                              {
                                                v44 = 0;
                                                goto LABEL_98;
                                              }
                                            }
                                            v44 = 1;
LABEL_98:
                                            if ( v44 == 0 )
                                            {
                                              v45 = (idDeclInfoTemplate<idDeclFX> *)v7;
                                              while ( v45 != v92 )
                                              {
                                                v45 = (idDeclInfoTemplate<idDeclFX> *)v45->parent;
                                                if ( v45 == nullptr )
                                                {
                                                  v46 = 0;
                                                  goto LABEL_103;
                                                }
                                              }
                                              v46 = 1;
LABEL_103:
                                              if ( v46 == 0 )
                                              {
                                                v47 = (idDeclInfoTemplate<idDeclEntityDef> *)v7;
                                                while ( v47 != v84 )
                                                {
                                                  v47 = (idDeclInfoTemplate<idDeclEntityDef> *)v47->parent;
                                                  if ( v47 == nullptr )
                                                  {
                                                    v48 = 0;
                                                    goto LABEL_108;
                                                  }
                                                }
                                                v48 = 1;
LABEL_108:
                                                if ( v48 == 0 )
                                                {
                                                  v49 = (idDeclInfoTemplate<idDeclVisemeSet> *)v7;
                                                  while ( v49 != v89 )
                                                  {
                                                    v49 = (idDeclInfoTemplate<idDeclVisemeSet> *)v49->parent;
                                                    if ( v49 == nullptr )
                                                    {
                                                      v50 = 0;
                                                      goto LABEL_113;
                                                    }
                                                  }
                                                  v50 = 1;
LABEL_113:
                                                  if ( v50 == 0 && v7->declSources.num > 0 )
                                                  {
                                                    v51 = 0;
                                                    num = v7->declSources.num;
                                                    do
                                                    {
                                                      str = v8->declSources.list[v51]->name.str;
                                                      if ( str != nullptr )
                                                        v54 = (idDecl *)idDeclInfo::FindWithInheritance(
                                                                          this: v8,
                                                                          name: str,
                                                                          makeDefault: false);
                                                      else
                                                        v54 = nullptr;
                                                      v55 = _RTDynamicCast(
                                                              inptr: v54,
                                                              VfDelta: 0,
                                                              SrcType: v78,
                                                              TargetType: v86,
                                                              isReference: 0);
                                                      if ( v55 != nullptr )
                                                      {
                                                        v56 = common->Game(this: common);
                                                        v57 = (idTypeInfoTools *)v56->GetTypeInfoTools(this: v56);
                                                        *(_WORD *)&v77.memTag = 1280;
                                                        memset(&v77, 0, 14);
                                                        *(_WORD *)&v76.memTag = 1280;
                                                        memset(&v76, 0, 14);
                                                        v58 = (*(int (__fastcall **)(void *))(*(_DWORD *)v55 + 32))(a1: v55);
                                                        idTypeInfoObject::idTypeInfoObject(
                                                          this: &v98,
                                                          objectPtr: v55,
                                                          objectType: *(const char **)(v58 + 1048),
                                                          ti: v57);
                                                        GetAllStrIdValues(
                                                          typeInfoObject: &v98,
                                                          typeInfo: v57,
                                                          stringTypePaths: &v77,
                                                          stringTypeValues: &v76);
                                                        v59 = 0;
                                                        if ( v76.num > 0 )
                                                        {
                                                          v60 = 0;
                                                          do
                                                          {
                                                            idStr::idStr(this: &v95, text: &v76.list[v60]);
                                                            if ( v95.len != 0 )
                                                              idList<idStr,5>::AddUnique(this: &v75, obj: &v95);
                                                            if ( idStr::Cmp(s1: v95.data, s2: v88) == 0 )
                                                            {
                                                              idStr::idStr(this: &v96, text: &v77.list[v60]);
                                                              idStr::operator=(this: &v96, text: &v96);
                                                              idStr::FreeData(this: &v96);
                                                            }
                                                            idStr::FreeData(this: &v95);
                                                            ++v59;
                                                            ++v60;
                                                          }
                                                          while ( v59 < v76.num );
                                                        }
                                                        idStr::FreeData(this: &v98.objectType);
                                                        idList<idStr,99>::~idList<idStr,99>(this: &v76);
                                                        idList<idStr,99>::~idList<idStr,99>(this: &v77);
                                                        v6 = v73;
                                                      }
                                                      --num;
                                                      ++v51;
                                                    }
                                                    while ( num != 0 );
                                                    v5 = v93;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v73 = ++v6;
      }
      while ( v6 < v79 );
      size = v75.size;
      v4 = v75.num;
      list = v75.list;
    }
    idFile_Memory::idFile_Memory(this: &v99);
    idLib::Warning(fmt: "Unique Strings Referenced in Decls: %d", v4);
    idFile::Printf(this: &v99, fmt: "Unique Strings Referenced in Decls: %d\n", v4);
    idFile::Printf(this: &v99, fmt: "----------------------------------------\n");
    Flags = idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict);
    idLib::Warning(fmt: "Unique Strings Referenced in Dictionary: %d", Flags);
    v62 = idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict);
    idFile::Printf(this: &v99, fmt: "Unique Strings Referenced in Dictionary: %d\n", v62);
    idFile::Printf(this: &v99, fmt: "----------------------------------------\n");
    idFile::Printf(this: &v99, fmt: "STRINGS NOT FOUND IN DECLS\n");
    idFile::Printf(this: &v99, fmt: "--------------------------\n");
    v63 = 0;
    for ( i = 0; i < (int)idParser::GetFlags(this: (idClientGame *)&idLocalization::languageDict); ++i )
    {
      KeyVal = idLangDict::GetKeyVal(this: &idLocalization::languageDict, i);
      if ( KeyVal != nullptr )
      {
        idStr::idStr(this: &v97, text: KeyVal->key);
        Index = idList<idStr,5>::FindIndex(this: &v75, obj: &v97, startIndex: 0);
        v67 = Index < 0 ? 0 : (int)&list[Index];
        idStr::FreeData(this: &v97);
        if ( v67 == 0 )
        {
          idLib::Printf(fmt: "couldn't find %s\n", KeyVal->key);
          idFile::Printf(this: &v99, fmt: "%s\n", KeyVal->key);
          ++v63;
        }
      }
    }
    idLib::Warning(fmt: "%d:\tUnfound Strings", v63);
    idFile::Printf(this: &v99, fmt: "--------------------------\n");
    idFile::Printf(this: &v99, fmt: "%Unfound Strings %d\n", v63);
    v68 = v74->__vftable;
    filePtr = v99.filePtr;
    v70 = (unsigned __int64)idFile_Memory::Length(this: &v99) >> 32;
    v68->Write(this: v74, a2: filePtr, a3: v70);
    ((void (__fastcall *)(idFile *, int))v74->dtr_idFile)(a1: v74, a2: 1);
    idFile_Memory::~idFile_Memory(this: &v99);
    if ( (v75.listStatic == 0 || v75.listStatic == 2) && list != nullptr )
    {
      if ( size > 0 )
      {
        v71 = list;
        for ( j = size; j != 0; --j )
          idStr::FreeData(this: v71++);
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
  else
  {
    idLib::Warning(fmt: "could not create file");
  }
  idStr::FreeData(this: &v94);
}


// ========================================================================
// __unwind$228131
// EA  : 0x8264B2C0
// RVA : 0x0064B2C0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228131()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 208));
}


// ========================================================================
// __unwind$228132
// EA  : 0x8264B2E8
// RVA : 0x0064B2E8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228132()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 880 + 96));
}


// ========================================================================
// __unwind$228133
// EA  : 0x8264B310
// RVA : 0x0064B310
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228133()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 880 + 128));
}


// ========================================================================
// __unwind$228134
// EA  : 0x8264B338
// RVA : 0x0064B338
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228134()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 880 + 112));
}


// ========================================================================
// __unwind$228135
// EA  : 0x8264B360
// RVA : 0x0064B360
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228135()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 880 + 336));
}


// ========================================================================
// __unwind$228136
// EA  : 0x8264B388
// RVA : 0x0064B388
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228136()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 240));
}


// ========================================================================
// __unwind$228137
// EA  : 0x8264B3B0
// RVA : 0x0064B3B0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228137()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 272));
}


// ========================================================================
// __unwind$228138
// EA  : 0x8264B3D8
// RVA : 0x0064B3D8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228138()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 880 + 384));
}


// ========================================================================
// __unwind$228139
// EA  : 0x8264B400
// RVA : 0x0064B400
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228139()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 304));
}


// ========================================================================
// ?InitCommands@idCommonLocal@@AAAXXZ
// EA  : 0x8264B428
// RVA : 0x0064B428
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall idCommonLocal::InitCommands(idCommonLocal *this)
{
  cmdSystem->AddCommand(this: cmdSystem, a2: "error", a3: Com_Error_f, a4: "causes an error", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "crash", a3: Com_Crash_f, a4: "causes a crash", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "trace",
    a3: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
    a4: "forces a trace",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "break", a3: Com_Break_f, a4: "causes a debug breakpoint", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "freeze",
    a3: Com_Freeze_f,
    a4: "freezes the game for a number of seconds",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "hitch", a3: idCommonLocal::Hitch_f, a4: "hitches the game", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "quit", a3: Com_Quit_f, a4: "quits the game", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "exit", a3: Com_Quit_f, a4: "exits the game", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "writeConfig",
    a3: Com_WriteConfig_f,
    a4: "writes a config file",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "find",
    a3: Com_Find_f,
    a4: "finds all system elements containing the given search string",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "dumpWarnings",
    a3: DumpWarnings_f,
    a4: "Dump all warnings to a text file.",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vid_restart",
    a3: R_VidRestart_f,
    a4: "resizes/fullscreens the game window",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "testLCP", a3: idLCP::Test_f, a4: "test LCP solver code", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadLanguage",
    a3: Com_ReloadLanguage_f,
    a4: "reload language dict",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "stripStrings",
    a3: Com_StripStrings_f,
    a4: "strip strings containing the specified substring or prefix",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "map",
    a3: idCommonLocal::ComboMap_f,
    a4: "loads a combo map",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "cmap",
    a3: idCommonLocal::ComboMap_f,
    a4: "loads a combo map",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "devmap",
    a3: idCommonLocal::DevComboMap_f,
    a4: "loads a combo map in developer mode",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "devcmap",
    a3: idCommonLocal::DevComboMap_f,
    a4: "loads a combo map in developer mode",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "slowmap",
    a3: idCommonLocal::DevMap_f,
    a4: "loads a map using slow non shipping render path in developer mode",
    a5: idCmdSystem::ArgCompletion_MapName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restartmap",
    a3: idCommonLocal::RestartMap_f,
    a4: "restarts the current map",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restartmaphere",
    a3: idCommonLocal::RestartMapHere_f,
    a4: "restarts the current map and teleports the player back to the current position",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "nextmap",
    a3: idCommonLocal::NextMap_f,
    a4: "transitions to the next map, maintaining inventory",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restart_loadgame",
    a3: idCommonLocal::RestartLoadGame_f,
    a4: "loads a game after rebooting due to a disc swap",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restart_passMainMenu",
    a3: idCommonLocal::RestartPassMainMenu_f,
    a4: "continues after a disc swap to somewhere on the main menu",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restart_mapAfterSwap",
    a3: idCommonLocal::RestartMapAfterSwap_f,
    a4: "continues after a disc swap to a map",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "restart_multiplayerInvite",
    a3: idCommonLocal::RestartMultiplayerInvite_f,
    a4: "used after accepting a MP invite from disc 1 or 2",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "disconnect",
    a3: idCommonLocal::Disconnect_f,
    a4: "disconnects from a game",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "leaveGame",
    a3: idCommonLocal::LeaveGame_f,
    a4: "disconnects from a game",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "saveGame", a3: idCommonLocal::SaveGame_f, a4: "saves a game", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "loadGame",
    a3: idCommonLocal::LoadGame_f,
    a4: "loads a game",
    a5: idCmdSystem::ArgCompletion_SaveGame);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demorecord",
    a3: idCommonLocal::RecordDemo_f,
    a4: "Record a demo",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demorecord_playtest",
    a3: idCommonLocal::RecordDemo_Playtest_f,
    a4: "Record a demo for playtest, gets argurments from cvars.  temp...",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demoplay",
    a3: idCommonLocal::PlayDemo_f,
    a4: "Play a recorded demo",
    a5: idCmdSystem::ArgCompletion_DemoFile);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demostop",
    a3: idCommonLocal::StopDemo_f,
    a4: "Stop recording or playing a demo",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ttplay",
    a3: idCommonLocal::TimeTrialPlay_f,
    a4: "Play a recorded timetrial",
    a5: idCmdSystem::ArgCompletion_TimeTrial);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ttplayqueued",
    a3: idCommonLocal::TimeTrialPlayQueued_f,
    a4: "Play a queued timetrial from memory",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ttrecord",
    a3: idCommonLocal::TimeTrialRecord_f,
    a4: "Record a timetrial",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ttstop",
    a3: idCommonLocal::TimeTrialStop_f,
    a4: "Stop recording or playing a timetrial",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demoCaptureFrames",
    a3: idCommonLocal::CaptureDemoFrames_f,
    a4: "Capture demo frames at 1280x720",
    a5: idCmdSystem::ArgCompletion_DemoFile);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "demoCaptureSounds",
    a3: idCommonLocal::CaptureDemoSounds_f,
    a4: "Capture demo sound",
    a5: idCmdSystem::ArgCompletion_DemoFile);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "compressFile",
    a3: idCommonLocal::CompressFile_f,
    a4: "compresses a file",
    a5: idCmdSystem::ArgCompletion_FileName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "decompressFile",
    a3: idCommonLocal::DecompressFile_f,
    a4: "decompresses a file",
    a5: idCmdSystem::ArgCompletion_FileName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "deleteGenerated",
    a3: idCommonLocal::DeleteGenerated_f,
    a4: "deletes the generated path",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "recordEvents",
    a3: Com_RecordEvents_f,
    a4: "recordEvents <name> start recording sys events",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "playEvents",
    a3: Com_PlayEvents_f,
    a4: "playEvents <name> playback sys events F12 will stop playback",
    a5: idCmdSystem::ArgCompletion_EventName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testStatsBegin",
    a3: Com_TestStatsBegin_f,
    a4: "starts a test session for recording stats",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testStatsEnd",
    a3: Com_TestStatsEnd_f,
    a4: "ends a test session for recording stats and exits the game",
    a5: nullptr);
}


// ========================================================================
// ?cleanMapFolders_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264BD98
// RVA : 0x0064BD98
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall cleanMapFolders_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idFileList *v3; // r3
  idFileList *v4; // r29
  int v5; // r26
  int v6; // r28
  const char *data; // r30
  idList<idStr,5> v8; // [sp+50h] [-190h] BYREF
  int v9; // [sp+60h] [-180h]
  idStr v10; // [sp+70h] [-170h] BYREF
  char v11[336]; // [sp+90h] [-150h] BYREF

  argc = args->argc;
  v9 = args->argc;
  if ( v9 == 2 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = fileSystem->ListFilesTree(this: fileSystem, a2: v2, a3: "bcm|sbcm|tbcm|bmodel|proc|bcg", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      *(_WORD *)&v8.memTag = 1280;
      memset(&v8, 0, 14);
      v5 = 0;
      if ( v3->list.num > 0 )
      {
        v6 = 0;
        do
        {
          data = v4->list.list[v6].data;
          if ( !idStr::CheckExtension(name: data, ext: "bmodel")
            || idStr::Find(searchIn: data, searchFor: "_occlusion.bmodel", casesensitive: false, start: 0, end: -1) == -1 )
          {
            fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: data, a3: v11, a4: 256, a5: FSPATH_BASE);
            idStr::idStr(this: &v10, text: v11);
            idList<idStr,5>::Append(this: &v8, obj: &v10);
            idStr::FreeData(this: &v10);
          }
          ++v5;
          ++v6;
        }
        while ( v5 < v4->list.num );
      }
      idFileList::~idFileList(this: v4);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      common->SetRefreshOnPrint(this: common, a2: true);
      idLib::sourceControl->Delete(this: idLib::sourceControl, a2: &v8);
      common->SetRefreshOnPrint(this: common, a2: false);
      idLib::Printf(
        fmt: "%d files deleted. You may still need to submit a change list from your source control client.\n",
        v8.num);
      if ( (v8.listStatic == 0 || v8.listStatic == 2) && v8.list != nullptr )
        idListArrayDelete<idStr>(ptr: v8.list, num: v8.size);
    }
    else
    {
      idLib::Warning(fmt: "Error listing files.");
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: cleanMapFolders <path>\n");
  }
}


// ========================================================================
// __unwind$228792
// EA  : 0x8264BFAC
// RVA : 0x0064BFAC
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228792()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 480 + 80));
}


// ========================================================================
// __unwind$228793
// EA  : 0x8264BFD4
// RVA : 0x0064BFD4
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_228793()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 112));
}


// ========================================================================
// ?testXML_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8264C008
// RVA : 0x0064C008
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall testXML_f(const idCmdArgs *args)
{
  idXMLElement *v1; // r3
  idXMLElement *v2; // r19
  idXMLElement *v3; // r3
  idXMLElement *v4; // r3
  idXMLElement *v5; // r3
  idXMLElement *v6; // r26
  idXMLElement *v7; // r3
  idXMLElement *v8; // r3
  idXMLElement *v9; // r3
  idXMLElement *v10; // r3
  idXMLElement *v11; // r3
  idXMLElement *v12; // r3
  idXMLElement *v13; // r3
  idXMLElement *v14; // r3
  idXMLElement *v15; // r3
  idXMLElement *v16; // r3
  idXMLElement *v17; // r3
  idXMLElement *v18; // r3
  idXMLElement *v19; // r3
  idXMLElement *v20; // r26
  idXMLElement *v21; // r3
  idXMLElement *v22; // r3
  idXMLElement *v23; // r3
  idXMLElement *v24; // r3
  idXMLElement *v25; // r3
  idXMLElement *v26; // r3
  idXMLElement *v27; // r3
  idXMLElement *v28; // r3
  idXMLElement *v29; // r3
  idXMLElement *v30; // r3
  idXMLElement *v31; // r3
  idXMLElement *v32; // r3
  idXMLElement *v33; // r3
  idXMLElement *v34; // r3
  idXMLElement *Document; // r30
  encounterGroupRole_t v36[4]; // [sp+50h] [-2D0h] BYREF
  idXMLWriter v37; // [sp+60h] [-2C0h] BYREF
  idList<idXMLAttribute,44> v38; // [sp+80h] [-2A0h] BYREF
  idList<idXMLAttribute,44> v39; // [sp+90h] [-290h] BYREF
  idXMLAttribute v40; // [sp+A0h] [-280h] BYREF
  idXMLAttribute v41; // [sp+E0h] [-240h] BYREF
  idXMLAttribute v42; // [sp+120h] [-200h] BYREF
  idXMLAttribute v43; // [sp+160h] [-1C0h] BYREF
  idXMLAttribute v44; // [sp+1A0h] [-180h] BYREF
  idXMLAttribute v45; // [sp+1E0h] [-140h] BYREF
  idLexer v46; // [sp+220h] [-100h] BYREF

  idXMLWriter::idXMLWriter(this: &v37);
  if ( idXMLWriter::OpenFile(this: &v37, relativePath: "xmlWriterTest.xml", overwrite: true, savepath: true) )
  {
    *(_WORD *)&v38.memTag = 1280;
    memset(&v38, 0, 14);
    idXMLWriter::OpenElement(this: &v37, name: "Rage");
    idXMLWriter::OpenElement(this: &v37, name: "Wasteland1");
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v38);
    idXMLAttribute::idXMLAttribute(this: &v40, name: "numInstances", value: "9");
    idList<idXMLAttribute,44>::Append(this: &v38, obj: &v40);
    idXMLAttribute::idXMLAttribute(this: &v41, name: "numTracks", value: "1");
    idList<idXMLAttribute,44>::Append(this: &v38, obj: &v41);
    idXMLWriter::OpenElement(this: &v37, name: "Maps", attributes: &v38);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Ghost Hideout");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Dam Facility");
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v38);
    idXMLAttribute::idXMLAttribute(this: &v45, name: "isTown", value: "yes");
    idList<idXMLAttribute,44>::Append(this: &v38, obj: &v45);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Wellspring", attributes: &v38);
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v38);
    idXMLAttribute::idXMLAttribute(this: &v44, name: "isTrack", value: "yes");
    idList<idXMLAttribute,44>::Append(this: &v38, obj: &v44);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Dusty 8", attributes: &v38);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Bash TV");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "RC Bomb Base");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Scientist");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Dead City");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Well");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Prison");
    idXMLWriter::CloseElement(this: &v37);
    idXMLWriter::CloseElement(this: &v37);
    idXMLWriter::CloseFile(this: &v37);
    idKeyValue::~idKeyValue(this: &v44);
    idKeyValue::~idKeyValue(this: &v45);
    idKeyValue::~idKeyValue(this: &v41);
    idKeyValue::~idKeyValue(this: &v40);
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v38);
  }
  else
  {
    idLib::Printf(fmt: "idXMLWriter test 1 failed.\n");
  }
  if ( idXMLWriter::OpenFile(this: &v37, relativePath: "xmlWriterTest.xml", overwrite: false, savepath: true) )
  {
    *(_WORD *)&v39.memTag = 1280;
    memset(&v39, 0, 14);
    idXMLWriter::OpenElement(this: &v37, name: "Wasteland2");
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v39);
    idXMLAttribute::idXMLAttribute(this: &v41, name: "numInstances", value: "7");
    idList<idXMLAttribute,44>::Append(this: &v39, obj: &v41);
    idXMLWriter::OpenElement(this: &v37, name: "Maps", attributes: &v39);
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v39);
    idXMLAttribute::idXMLAttribute(this: &v40, name: "isTown", value: "yes");
    idList<idXMLAttribute,44>::Append(this: &v39, obj: &v40);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Subway Town", attributes: &v39);
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Distillery");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Jackal Canyon");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Mutant Cave");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Plaza");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Power Surge");
    idXMLWriter::WriteElement(this: &v37, name: "Map", value: "Authority Base");
    idXMLWriter::CloseDocument(this: &v37);
    idXMLWriter::CloseFile(this: &v37);
    idKeyValue::~idKeyValue(this: &v40);
    idKeyValue::~idKeyValue(this: &v41);
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v39);
  }
  else
  {
    idLib::Printf(fmt: "idXMLWriter test 2 failed.\n");
  }
  v1 = (idXMLElement *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x60u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v1;
  if ( v1 != nullptr )
    v2 = idXMLElement::idXMLElement(this: v1, name: "Factions");
  else
    v2 = nullptr;
  v3 = (idXMLElement *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x60u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v3;
  if ( v3 != nullptr )
    v4 = idXMLElement::idXMLElement(this: v3, name: "Faction", value: "Authority");
  else
    v4 = nullptr;
  v36[0] = (encounterGroupRole_t)v4;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v2->children, obj: v36);
  v5 = (idXMLElement *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x60u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v5;
  if ( v5 != nullptr )
    v6 = idXMLElement::idXMLElement(this: v5, name: "Faction");
  else
    v6 = nullptr;
  idXMLAttribute::idXMLAttribute(this: &v42, name: "group", value: "Settlers");
  if ( idList<idXMLAttribute,44>::FindIndex(this: &v6->attributes, obj: &v42, startIndex: 0) < 0 )
    idList<idXMLAttribute,44>::Append(this: &v6->attributes, obj: &v42);
  v7 = (idXMLElement *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x60u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v7;
  if ( v7 != nullptr )
    v8 = idXMLElement::idXMLElement(this: v7, name: "Settler", value: "Hagar");
  else
    v8 = nullptr;
  v36[0] = (encounterGroupRole_t)v8;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v6->children, obj: v36);
  v9 = (idXMLElement *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x60u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v9;
  if ( v9 != nullptr )
    v10 = idXMLElement::idXMLElement(this: v9, name: "Settler", value: "Outrigger");
  else
    v10 = nullptr;
  v36[0] = (encounterGroupRole_t)v10;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v6->children, obj: v36);
  v11 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v11;
  if ( v11 != nullptr )
    v12 = idXMLElement::idXMLElement(this: v11, name: "Settler", value: "Wellspring");
  else
    v12 = nullptr;
  v36[0] = (encounterGroupRole_t)v12;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v6->children, obj: v36);
  v13 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v13;
  if ( v13 != nullptr )
    v14 = idXMLElement::idXMLElement(this: v13, name: "Settler", value: "Resistance");
  else
    v14 = nullptr;
  v36[0] = (encounterGroupRole_t)v14;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v6->children, obj: v36);
  v15 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v15;
  if ( v15 != nullptr )
    v16 = idXMLElement::idXMLElement(this: v15, name: "Settler", value: "Subway Town");
  else
    v16 = nullptr;
  v36[0] = (encounterGroupRole_t)v16;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v6->children, obj: v36);
  v36[0] = (encounterGroupRole_t)v6;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v2->children, obj: v36);
  v17 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v17;
  if ( v17 != nullptr )
    v18 = idXMLElement::idXMLElement(this: v17, name: "Faction", value: "Mutants");
  else
    v18 = nullptr;
  v36[0] = (encounterGroupRole_t)v18;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v2->children, obj: v36);
  v19 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v19;
  if ( v19 != nullptr )
    v20 = idXMLElement::idXMLElement(this: v19, name: "Faction");
  else
    v20 = nullptr;
  idXMLAttribute::idXMLAttribute(this: &v43, name: "group", value: "Bandits");
  if ( idList<idXMLAttribute,44>::FindIndex(this: &v20->attributes, obj: &v43, startIndex: 0) < 0 )
    idList<idXMLAttribute,44>::Append(this: &v20->attributes, obj: &v43);
  v21 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v21;
  if ( v21 != nullptr )
    v22 = idXMLElement::idXMLElement(this: v21, name: "Bandit", value: "Ghost");
  else
    v22 = nullptr;
  v36[0] = (encounterGroupRole_t)v22;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v23 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v23;
  if ( v23 != nullptr )
    v24 = idXMLElement::idXMLElement(this: v23, name: "Bandit", value: "Wasted");
  else
    v24 = nullptr;
  v36[0] = (encounterGroupRole_t)v24;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v25 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v25;
  if ( v25 != nullptr )
    v26 = idXMLElement::idXMLElement(this: v25, name: "Bandit", value: "Shrouded");
  else
    v26 = nullptr;
  v36[0] = (encounterGroupRole_t)v26;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v27 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v27;
  if ( v27 != nullptr )
    v28 = idXMLElement::idXMLElement(this: v27, name: "Bandit", value: "Scorcher");
  else
    v28 = nullptr;
  v36[0] = (encounterGroupRole_t)v28;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v29 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v29;
  if ( v29 != nullptr )
    v30 = idXMLElement::idXMLElement(this: v29, name: "Bandit", value: "Jackals");
  else
    v30 = nullptr;
  v36[0] = (encounterGroupRole_t)v30;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v31 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v31;
  if ( v31 != nullptr )
    v32 = idXMLElement::idXMLElement(this: v31, name: "Bandit", value: "Gear Head");
  else
    v32 = nullptr;
  v36[0] = (encounterGroupRole_t)v32;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v33 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v36[0] = (encounterGroupRole_t)v33;
  if ( v33 != nullptr )
    v34 = idXMLElement::idXMLElement(this: v33, name: "Bandit", value: "Toxic");
  else
    v34 = nullptr;
  v36[0] = (encounterGroupRole_t)v34;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v20->children, obj: v36);
  v36[0] = (encounterGroupRole_t)v20;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v2->children, obj: v36);
  idXMLWriter::OpenFile(this: &v37, relativePath: "xmlElementTest.xml", overwrite: true, savepath: true);
  if ( v37.xmlFile != nullptr )
  {
    idXMLWriter::WriteDocument(this: &v37, root: v2);
    idXMLWriter::CloseFile(this: &v37);
  }
  else
  {
    idLib::Printf(fmt: "idXMLElement test failed.\n");
  }
  if ( v2 != nullptr )
  {
    idXMLElement::~idXMLElement(this: v2);
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  }
  Document = nullptr;
  idXMLReader::idXMLReader(this: (idXMLReader *)&v46, relativePath: "xmlElementTest.xml");
  if ( v46.loaded )
  {
    Document = idXMLReader::ReadDocument(this: (idXMLReader *)&v46);
    idLexer::FreeSource(this: &v46);
  }
  idXMLWriter::OpenFile(this: &v37, relativePath: "xmlReaderTest.xml", overwrite: true, savepath: true);
  if ( v37.xmlFile != nullptr && Document != nullptr )
  {
    idXMLWriter::WriteDocument(this: &v37, root: Document);
    idXMLWriter::CloseFile(this: &v37);
    idXMLElement::~idXMLElement(this: Document);
    idMem::Free(this: &mem, ptr: Document, align: ALIGN_16);
  }
  else
  {
    idLib::Printf(fmt: "idXMLReader test failed.\n");
  }
  idLexer::~idLexer(this: &v46);
  idKeyValue::~idKeyValue(this: &v43);
  idKeyValue::~idKeyValue(this: &v42);
}


// ========================================================================
// __unwind$229019
// EA  : 0x8264CB38
// RVA : 0x0064CB38
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229019()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 800 + 128));
}


// ========================================================================
// __unwind$229020
// EA  : 0x8264CB60
// RVA : 0x0064CB60
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229020()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 160));
}


// ========================================================================
// __unwind$229021
// EA  : 0x8264CB88
// RVA : 0x0064CB88
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229021()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 224));
}


// ========================================================================
// __unwind$229022
// EA  : 0x8264CBB0
// RVA : 0x0064CBB0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229022()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 480));
}


// ========================================================================
// __unwind$229023
// EA  : 0x8264CBD8
// RVA : 0x0064CBD8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229023()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 416));
}


// ========================================================================
// __unwind$229024
// EA  : 0x8264CC00
// RVA : 0x0064CC00
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229024()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 800 + 144));
}


// ========================================================================
// __unwind$229025
// EA  : 0x8264CC28
// RVA : 0x0064CC28
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229025()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 224));
}


// ========================================================================
// __unwind$229026
// EA  : 0x8264CC50
// RVA : 0x0064CC50
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229026()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 160));
}


// ========================================================================
// __unwind$229027
// EA  : 0x8264CC78
// RVA : 0x0064CC78
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229027(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229028
// EA  : 0x8264CCA0
// RVA : 0x0064CCA0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229028(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229029
// EA  : 0x8264CCC8
// RVA : 0x0064CCC8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229029(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229030
// EA  : 0x8264CCF0
// RVA : 0x0064CCF0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229030()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 288));
}


// ========================================================================
// __unwind$229031
// EA  : 0x8264CD18
// RVA : 0x0064CD18
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229031(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229032
// EA  : 0x8264CD40
// RVA : 0x0064CD40
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229032(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229033
// EA  : 0x8264CD68
// RVA : 0x0064CD68
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229033(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229034
// EA  : 0x8264CD90
// RVA : 0x0064CD90
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229034(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229035
// EA  : 0x8264CDB8
// RVA : 0x0064CDB8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229035(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229036
// EA  : 0x8264CDE0
// RVA : 0x0064CDE0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229036(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229037
// EA  : 0x8264CE08
// RVA : 0x0064CE08
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229037(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229038
// EA  : 0x8264CE30
// RVA : 0x0064CE30
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229038()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 800 + 352));
}


// ========================================================================
// __unwind$229039
// EA  : 0x8264CE58
// RVA : 0x0064CE58
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229039(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229040
// EA  : 0x8264CE80
// RVA : 0x0064CE80
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229040(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229041
// EA  : 0x8264CEA8
// RVA : 0x0064CEA8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229041(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229042
// EA  : 0x8264CED0
// RVA : 0x0064CED0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229042(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229043
// EA  : 0x8264CEF8
// RVA : 0x0064CEF8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229043(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229044
// EA  : 0x8264CF20
// RVA : 0x0064CF20
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229044(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229045
// EA  : 0x8264CF48
// RVA : 0x0064CF48
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __fastcall _unwind_229045(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$229046
// EA  : 0x8264CF70
// RVA : 0x0064CF70
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void _unwind_229046()
{
  int v0; // r12

  idXMLReader::~idXMLReader(this: (idXMLReader *)(v0 - 800 + 544));
}


// ========================================================================
// `dynamic initializer for 'com_exitAfterTests''
// EA  : 0x83337FA0
// RVA : 0x01337FA0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_exitAfterTests__()
{
  idCVar::idCVar(
    this: &com_exitAfterTests,
    name: "com_exitAfterTests",
    value: "0",
    flags: 1,
    description: "if set, exits game after regression tests complete",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_exitAfterTests__);
}


// ========================================================================
// `dynamic initializer for 'com_gatherMapStats''
// EA  : 0x83337FF8
// RVA : 0x01337FF8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_gatherMapStats__()
{
  idCVar::idCVar(
    this: &com_gatherMapStats,
    name: "com_gatherMapStats",
    value: "0",
    flags: 1,
    description: "if set, map statistics will be written out after next map load",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_gatherMapStats__);
}


// ========================================================================
// `dynamic initializer for 'com_uploadMapStats''
// EA  : 0x83338050
// RVA : 0x01338050
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_uploadMapStats__()
{
  idCVar::idCVar(
    this: &com_uploadMapStats,
    name: "com_uploadMapStats",
    value: "1",
    flags: 1,
    description: "if set, map statistics will be sent to the map-stat server.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_uploadMapStats__);
}


// ========================================================================
// `dynamic initializer for 'SetGameHz_v''
// EA  : 0x833380A8
// RVA : 0x013380A8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SetGameHz_v__()
{
  return idCommandLink::idCommandLink(
           this: &SetGameHz_v,
           cmdName: "SetGameHz",
           function: SetGameHz_f,
           description: "Sets the game speed",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'StartSlowMotion_v''
// EA  : 0x833380D0
// RVA : 0x013380D0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StartSlowMotion_v__()
{
  return idCommandLink::idCommandLink(
           this: &StartSlowMotion_v,
           cmdName: "StartSlowMotion",
           function: StartSlowMotion_f,
           description: "Starts SlowMotion with decl",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclGameTime>);
}


// ========================================================================
// `dynamic initializer for 'StopSlowMotion_v''
// EA  : 0x83338100
// RVA : 0x01338100
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StopSlowMotion_v__()
{
  return idCommandLink::idCommandLink(
           this: &StopSlowMotion_v,
           cmdName: "StopSlowMotion",
           function: StopSlowMotion_f,
           description: "Stops SlowMotion",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'StartSlowMotion2_v''
// EA  : 0x83338128
// RVA : 0x01338128
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StartSlowMotion2_v__()
{
  return idCommandLink::idCommandLink(
           this: &StartSlowMotion2_v,
           cmdName: "StartSlowMotion2",
           function: StartSlowMotion2_f,
           description: "Starts SlowMotion without decl, just a raw scale value",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'StopSlowMotion2_v''
// EA  : 0x83338150
// RVA : 0x01338150
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StopSlowMotion2_v__()
{
  return idCommandLink::idCommandLink(
           this: &StopSlowMotion2_v,
           cmdName: "StopSlowMotion2",
           function: StopSlowMotion2_f,
           description: "Stops SlowMotion",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'FindUnlocalizedStrings_v''
// EA  : 0x83338178
// RVA : 0x01338178
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__FindUnlocalizedStrings_v__()
{
  return idCommandLink::idCommandLink(
           this: &FindUnlocalizedStrings_v,
           cmdName: "FindUnlocalizedStrings",
           function: FindUnlocalizedStrings_f,
           description: "Goes through the decls and writes out a file of some of the unlocalized strings, if given a parameter that'll"
           " be the file it writes to.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'FindUnreferencedStrings_v''
// EA  : 0x833381A0
// RVA : 0x013381A0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__FindUnreferencedStrings_v__()
{
  return idCommandLink::idCommandLink(
           this: &FindUnreferencedStrings_v,
           cmdName: "FindUnreferencedStrings",
           function: FindUnreferencedStrings_f,
           description: "Goes through the lang file and finds ones that aren't in decls. (doesn't mean it's not in a map though)",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MakeTest_v''
// EA  : 0x833381C8
// RVA : 0x013381C8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MakeTest_v__()
{
  return idCommandLink::idCommandLink(
           this: &MakeTest_v,
           cmdName: "MakeTest",
           function: MakeTest_f,
           description: "makeTest <mapName> [##] Starts recording a regression test using layer ##",
           argCompletion: idCmdSystem::ArgCompletion_MapName);
}


// ========================================================================
// `dynamic initializer for 'MakeTestLoadGame_v''
// EA  : 0x833381F8
// RVA : 0x013381F8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MakeTestLoadGame_v__()
{
  return idCommandLink::idCommandLink(
           this: &MakeTestLoadGame_v,
           cmdName: "MakeTestLoadGame",
           function: MakeTestLoadGame_f,
           description: "makeTestLoadGame <mapName> <layer #> Starts recording a regression test for loading a savegame",
           argCompletion: idCmdSystem::ArgCompletion_MapName);
}


// ========================================================================
// `dynamic initializer for 'StopTest_v''
// EA  : 0x83338228
// RVA : 0x01338228
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StopTest_v__()
{
  return idCommandLink::idCommandLink(
           this: &StopTest_v,
           cmdName: "StopTest",
           function: StopTest_f,
           description: "stopTest Stops a regression test recording or playback",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'PlayTest_v''
// EA  : 0x83338250
// RVA : 0x01338250
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__PlayTest_v__()
{
  return idCommandLink::idCommandLink(
           this: &PlayTest_v,
           cmdName: "PlayTest",
           function: PlayTest_f,
           description: "playTest <events|folder> [startUp] Plays a regression test. Use third argument if running from command line ",
           argCompletion: idCmdSystem::ArgCompletion_RegressionTestName);
}


// ========================================================================
// `dynamic initializer for 'PlayTestAndExit_v''
// EA  : 0x83338280
// RVA : 0x01338280
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__PlayTestAndExit_v__()
{
  return idCommandLink::idCommandLink(
           this: &PlayTestAndExit_v,
           cmdName: "PlayTestAndExit",
           function: PlayTestAndExit_f,
           description: "playTestAndExit <events|folder> [startUp] Plays a regression test or folder tree, then shuts down the game",
           argCompletion: idCmdSystem::ArgCompletion_RegressionTestName);
}


// ========================================================================
// `dynamic initializer for 'GatherMapStats_v''
// EA  : 0x833382B0
// RVA : 0x013382B0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GatherMapStats_v__()
{
  return idCommandLink::idCommandLink(
           this: &GatherMapStats_v,
           cmdName: "GatherMapStats",
           function: GatherMapStats_f,
           description: "sends the map stats after a load to the map stat server",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DelayedScreenshot_v''
// EA  : 0x833382D8
// RVA : 0x013382D8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DelayedScreenshot_v__()
{
  return idCommandLink::idCommandLink(
           this: &DelayedScreenshot_v,
           cmdName: "DelayedScreenshot",
           function: DelayedScreenshot_f,
           description: "write out screenshot after time passed in",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testXML_v''
// EA  : 0x83338300
// RVA : 0x01338300
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testXML_v__()
{
  return idCommandLink::idCommandLink(
           this: &testXML_v,
           cmdName: "testXML",
           function: testXML_f,
           description: "tests the idXML classes",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'nextRegressionTest_v''
// EA  : 0x83338328
// RVA : 0x01338328
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__nextRegressionTest_v__()
{
  return idCommandLink::idCommandLink(
           this: &nextRegressionTest_v,
           cmdName: "nextRegressionTest",
           function: nextRegressionTest_f,
           description: "force NextTest() call on regression system",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cleanMapFolders_v''
// EA  : 0x83338350
// RVA : 0x01338350
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cleanMapFolders_v__()
{
  return idCommandLink::idCommandLink(
           this: &cleanMapFolders_v,
           cmdName: "cleanMapFolders",
           function: cleanMapFolders_f,
           description: "Cleans out old map files (.bcm, .bcg, .bmodel and .proc) from map folders)",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'sys_writeMemoryReport_v''
// EA  : 0x83338378
// RVA : 0x01338378
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sys_writeMemoryReport_v__()
{
  return idCommandLink::idCommandLink(
           this: &sys_writeMemoryReport_v,
           cmdName: "sys_writeMemoryReport",
           function: sys_writeMemoryReport_f,
           description: "Walks the heap and writes stats to XML file",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportNumRenderModels_v''
// EA  : 0x833383A0
// RVA : 0x013383A0
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportNumRenderModels_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportNumRenderModels_v,
           cmdName: "reportNumRenderModels",
           function: reportNumRenderModels_f,
           description: "Writes the number of render models in the map to the console",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'writeEntitiesFile_v''
// EA  : 0x833383C8
// RVA : 0x013383C8
// PDB : w:\tech5\engine\framework\common_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__writeEntitiesFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &writeEntitiesFile_v,
           cmdName: "writeEntitiesFile",
           function: writeEntitiesFile_f,
           description: "writes out a production build .entities file for the specified map",
           argCompletion: idCmdSystem::ArgCompletion_MapName);
}

