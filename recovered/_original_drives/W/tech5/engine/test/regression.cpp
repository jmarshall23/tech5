
// ========================================================================
// ?StopTest@idRegressionLocal@@UAAXXZ
// EA  : 0x829EA330
// RVA : 0x009EA330
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::StopTest(idRegressionLocal *this)
{
  if ( common->GetRecordState(this: common) == RECORD_MAKE )
  {
    this->QueueEventString(this, a2: "~");
    this->QueueEventString(this, a2: "disconnect \n");
    this->QueueEventString(this, a2: "recordEvents \n");
  }
  else
  {
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "activateConsole 0.5");
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "disconnect");
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "recordEvents");
  }
}


// ========================================================================
// ?FinishXMLReport@idRegressionLocal@@AAAXXZ
// EA  : 0x829EA420
// RVA : 0x009EA420
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::FinishXMLReport(idRegressionLocal *this)
{
  idXMLWriter *p_xmlWriter; // r30

  p_xmlWriter = &this->xmlWriter;
  idXMLWriter::CloseDocument(this: &this->xmlWriter);
  idXMLWriter::CloseFile(this: p_xmlWriter);
  this->UpdateCurrentTestFile(this, a2: &byte_8200D768);
}


// ========================================================================
// ?QueueEventString@idRegressionLocal@@UAAXPBD@Z
// EA  : 0x829EA550
// RVA : 0x009EA550
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::QueueEventString(idRegressionLocal *this, const char *string)
{
  int v2; // r10
  int v3; // r8
  int v4; // ctr
  eventQueue_t *p_eventQueue; // r11
  char v6; // r9

  v2 = 0;
  if ( *string != 0 )
  {
    do
      ++v2;
    while ( string[v2] != 0 );
  }
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = v2;
    p_eventQueue = &this->eventQueue;
    do
    {
      v6 = string[v3++];
      p_eventQueue->data[p_eventQueue->curr] = v6;
      p_eventQueue->curr = (p_eventQueue->curr + 1) % 1000;
      --v4;
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ?ProcessQueuedEvents@idRegressionLocal@@UAA_NXZ
// EA  : 0x829EA5D0
// RVA : 0x009EA5D0
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

int __fastcall idRegressionLocal::ProcessQueuedEvents(idRegressionLocal *this)
{
  char Char; // r3

  if ( this->testInProgress )
    return 0;
  Char = eventQueue_t::GetChar(this: &this->eventQueue);
  switch ( Char )
  {
    case 0:
      return 0;
    case 126:
      sys->QueueEvent(this: sys, a2: SE_KEY, a3: 41, a4: 1, a5: 0, a6: nullptr, a7: 0);
      sys->QueueEvent(this: sys, a2: SE_KEY, a3: 41, a4: 0, a5: 0, a6: nullptr, a7: 0);
      break;
    case 10:
      sys->QueueEvent(this: sys, a2: SE_KEY, a3: 28, a4: 1, a5: 0, a6: nullptr, a7: 0);
      sys->QueueEvent(this: sys, a2: SE_KEY, a3: 28, a4: 0, a5: 0, a6: nullptr, a7: 0);
      break;
    default:
      sys->QueueEvent(this: sys, a2: SE_CHAR, a3: Char, a4: 0, a5: 0, a6: nullptr, a7: 0);
      break;
  }
  return 1;
}


// ========================================================================
// ?NextTest@idRegressionLocal@@UAAXXZ
// EA  : 0x829EA710
// RVA : 0x009EA710
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::NextTest(idRegressionLocal *this)
{
  idTestReport **list; // r6
  int v3; // r11
  idList<idFolderReport *,5> *p_folderReports; // r30
  idFolderReport *v5; // r10
  idFolderReport *v6; // r3
  int num; // r11
  int v8; // r11
  bool v9; // zf
  int v10; // r10
  idFolderReport **v11; // r9
  idList<idTestReport *,5> *p_testReports; // r30
  idTestReport *v13; // r3
  int v14; // r11
  int v15; // r11
  int v16; // r10
  idTestReport **v17; // r9
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r8
  va *v21; // r3
  idJoystick *v22; // r3
  idKeyboard *v23; // r3
  idMouse *v24; // r3
  int v25; // [sp+8h] [-1498h]
  int v26; // [sp+Ch] [-1494h]
  int v27; // [sp+10h] [-1490h]
  int v28; // [sp+14h] [-148Ch]
  int v29; // [sp+18h] [-1488h]
  int v30; // [sp+1Ch] [-1484h]
  idStr v31; // [sp+60h] [-1440h] BYREF
  int v32; // [sp+80h] [-1420h] BYREF
  va v33; // [sp+480h] [-1020h] BYREF

  if ( !this->ignoreNextTest )
  {
    if ( this->currentTestReport <= 0 )
    {
      if ( this->folderReports.num != 0 )
      {
        p_folderReports = &this->folderReports;
        do
        {
          v5 = *p_folderReports->list;
          if ( v5 != nullptr )
          {
            if ( v5->childResults.num != v5->numChildren )
              (*(void (__fastcall **)(idFolderReport *))(**(_DWORD **)p_folderReports->list + 4))(a1: *p_folderReports->list);
            v6 = *p_folderReports->list;
            if ( v6 != nullptr )
              ((void (__fastcall *)(idFolderReport *, int))v6->dtr_idReport)(a1: v6, a2: 1);
          }
          num = this->folderReports.num;
          if ( num > 0 )
          {
            this->folderReports.num = num - 1;
            v9 = num - 1 <= 0;
            v8 = 0;
            if ( !v9 )
            {
              v10 = 0;
              do
              {
                ++v8;
                v11 = &p_folderReports->list[v10++];
                *v11 = v11[1];
              }
              while ( v8 < this->folderReports.num );
            }
          }
        }
        while ( this->folderReports.num != 0 );
      }
      if ( this->testReports.num != 0 )
      {
        p_testReports = &this->testReports;
        do
        {
          v13 = *p_testReports->list;
          if ( v13 != nullptr )
            ((void (__fastcall *)(idTestReport *, int))v13->dtr_idReport)(a1: v13, a2: 1);
          v14 = this->testReports.num;
          if ( v14 > 0 )
          {
            this->testReports.num = v14 - 1;
            v9 = v14 - 1 <= 0;
            v15 = 0;
            if ( !v9 )
            {
              v16 = 0;
              do
              {
                ++v15;
                v17 = &p_testReports->list[v16++];
                *v17 = v17[1];
              }
              while ( v15 < this->testReports.num );
            }
          }
        }
        while ( this->testReports.num != 0 );
      }
      idRegressionLocal::FinishXMLReport(this);
      idStr::StripTrailing(this: &this->rootPath, string: "/");
      idStr::StripTrailing(this: &this->rootPath, string: ".events");
      HIDWORD(v18) = &unk_82270000;
      HIDWORD(v19) = this->rootPath.data;
      v21 = va::va(
              this: &v33,
              fmt: "regression/reports/%s/report.html",
              a3: v19,
              a4: v20,
              a5: v18,
              a6: v25,
              a7: v26,
              a8: v27,
              a9: v28,
              a10: v29,
              a11: v30);
      idStr::idStr(this: &v31, text: v21);
      fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v31.data, a3: (char *)&v32, a4: 1024, a5: FSPATH_SAVE);
      if ( com_exitAfterTests.valueInteger != 0 )
        common->Quit(this: common, a2: 0);
      v22 = sys->Joystick(this: sys);
      v22->Init(this: v22);
      v23 = sys->Keyboard(this: sys);
      v23->Init(this: v23);
      v24 = sys->Mouse(this: sys);
      v24->Init(this: v24);
      idStr::FreeData(this: &v31);
    }
    else
    {
      cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionTest.cfg");
      list = this->testReports.list;
      v3 = this->currentTestReport - 1;
      this->currentTestReport = v3;
      idTestReport::RunTest(this: list[v3], xmlWriter: &this->xmlWriter);
    }
  }
}


// ========================================================================
// __unwind$221372
// EA  : 0x829EA9F4
// RVA : 0x009EA9F4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221372()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5280 + 96));
}


// ========================================================================
// ?DisplayTextScreen@idRegressionLocal@@UBAXPBDH@Z
// EA  : 0x829EAA20
// RVA : 0x009EAA20
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::DisplayTextScreen(idRegressionLocal *this, char *text, int seconds)
{
  unsigned int v4; // r23
  int v5; // r22
  int v6; // r7
  unsigned __int64 v7; // r6
  __int64 v8; // r18
  __int64 v9; // r4
  unsigned __int64 v10; // r10
  __int64 v11; // r3
  const idVec4 *v12; // r5
  const char *v13; // r4
  idRenderSystem_vtbl *v14; // r19
  void *v15; // r3
  int v16; // [sp+70h] [-120h] BYREF
  __int64 v17; // [sp+78h] [-118h]
  __int64 v18; // [sp+80h] [-110h]
  __int64 v19; // [sp+88h] [-108h]
  __int64 v20; // [sp+90h] [-100h]
  idVec4 v21; // [sp+A0h] [-F0h] BYREF
  idVec4 v22; // [sp+B0h] [-E0h] BYREF
  idVec4 v23; // [sp+C0h] [-D0h] BYREF
  idVec4 v24; // [sp+D0h] [-C0h] BYREF
  idVec4 v25; // [sp+E0h] [-B0h] BYREF

  v5 = 1000 * seconds;
  v4 = Sys_Milliseconds();
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: true, a4: 0);
  while ( (int)(Sys_Milliseconds() - v4) < v5 )
  {
    console->Gui(this: console);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v7,
      a4: v6);
    LODWORD(v8) = renderSystem->GetWidth(this: renderSystem);
    HIDWORD(v8) = renderSystem->GetHeight(this: renderSystem);
    idRenderModelGui::SetViewport(this: nullptr, x: 0, y: 0, width: v8, height: HIDWORD(v8));
    MEMORY[0x7F4] = idColor::PackColor(color: (const idVec4 *)&idColor::colorBlack);
    v9 = __PAIR64__(
           (unsigned int)idDeclInfo::FindWithInheritance(
                           this: &idMaterial::resourceList,
                           name: "_white",
                           makeDefault: true),
           HIDWORD(v8));
    v22.x = 0.0;
    v18 = v9;
    v17 = v8;
    v22.z = 0.0;
    v22.w = 1.0;
    v23.z = 1.0;
    v23.w = 1.0;
    v24.y = 0.0;
    v24.z = 1.0;
    v24.w = 0.0;
    v21.x = 0.0;
    v21.y = 0.0;
    v21.z = 0.0;
    v21.w = 0.0;
    v22.y = (float)v9;
    v23.y = v22.y;
    v23.x = (float)v8;
    v24.x = v23.x;
    idRenderModelGui::DrawStretchPic(
      this: nullptr,
      topLeft: &v21,
      topRight: &v24,
      bottomRight: &v23,
      bottomLeft: &v22,
      material: (const idMaterial *)HIDWORD(v9),
      a7: v10);
    LODWORD(v11) = idRenderModelGui::GetStringWidth(this: nullptr, string: text, scale: 1.0);
    v25.x = 1.0;
    v19 = v11;
    v25.y = 1.0;
    v25.z = 1.0;
    v25.w = 1.0;
    v20 = (unsigned int)(SHIDWORD(v8) / 2);
    idRenderModelGui::DrawString(
      this: nullptr,
      x: (float)((float)((float)v8 - (float)v11) * (float)0.5),
      y: (float)(unsigned int)v20,
      string: v13,
      defaultColor: v12,
      forceColor: (unsigned __int8 *)text,
      scale: 1.0,
      a8: &v25,
      a9: SBYTE3(v20));
    v16 = 0;
    v14 = renderSystem->__vftable;
    v15 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystem *, void *, _DWORD, _DWORD, _DWORD, int *, int, int))v14->EndFrame)(
      a1: renderSystem,
      a2: v15,
      a3: v8,
      a4: HIDWORD(v8),
      a5: 0,
      a6: &v16,
      a7: 1,
      a8: 1);
  }
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_stopTime", a3: false, a4: 0);
}


// ========================================================================
// ?UpdateCurrentTestFile@idRegressionLocal@@EAAXPBD@Z
// EA  : 0x829EACD8
// RVA : 0x009EACD8
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::UpdateCurrentTestFile(idRegressionLocal *this, const char *testPath)
{
  int v3; // r11
  idFile *v4; // r3
  idFile *v5; // r30
  idStr v6; // [sp+50h] [-60h] BYREF
  idStr v7[2]; // [sp+70h] [-40h] BYREF

  idStr::idStr(this: v7, text: &this->rootPath);
  idStr::StripTrailing(this: v7, string: "/");
  idStr::StripTrailing(this: v7, string: ".events");
  v6.len = 0;
  v6.baseBuffer[0] = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  idStr::Format(this: &v6, fmt: "regression/reports/%s/currentTest.txt", v7[0].data);
  v3 = 0;
  if ( *testPath == 0 )
    goto LABEL_4;
  do
    ++v3;
  while ( testPath[v3] != 0 );
  if ( v3 != 0 )
  {
    v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: v6.data, a3: 2);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->Printf(this: v4, a2: testPath);
      ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
    }
  }
  else
  {
LABEL_4:
    fileSystem->RemoveFile(this: fileSystem, a2: v6.data, a3: FSPATH_BASE);
  }
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$221556
// EA  : 0x829EAE04
// RVA : 0x009EAE04
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221556()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$221557_0
// EA  : 0x829EAE2C
// RVA : 0x009EAE2C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221557_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?MakeTest@idRegressionLocal@@UAAXABVidCmdArgs@@@Z
// EA  : 0x829EAE60
// RVA : 0x009EAE60
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::MakeTest(idRegressionLocal *this, const idCmdArgs *args)
{
  const char *v4; // r4
  int v5; // r30
  int argc; // r11
  bool v7; // cr56
  const char *v8; // r4
  __int64 v9; // r10
  __int64 v10; // r8
  char *v11; // r4
  __int64 v12; // r6
  unsigned int v13; // r27
  char *v14; // r30
  char v15; // r23
  bool v16; // zf
  int v17; // r22
  char v18; // r11
  char v19; // r11
  int v20; // r11
  int v21; // r11
  int v22; // r11
  va *v23; // r3
  va *v24; // r28
  size_t i; // r29
  int v26; // r4
  int v27; // r11
  char v28; // r29
  __int64 v29; // r10
  __int64 v30; // r8
  va *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  __int64 v35; // r10
  __int64 v36; // r6
  __int64 v37; // r8
  va *v38; // r3
  __int64 v39; // r10
  __int64 v40; // r8
  int v41; // r3
  __int64 v42; // r6
  va *v43; // r3
  __int64 v44; // r8
  __int64 v45; // r6
  __int64 v46; // r10
  va *v47; // r3
  int v48; // [sp+8h] [-11C8h]
  int v49; // [sp+8h] [-11C8h]
  int v50; // [sp+8h] [-11C8h]
  int v51; // [sp+8h] [-11C8h]
  int v52; // [sp+Ch] [-11C4h]
  int v53; // [sp+Ch] [-11C4h]
  int v54; // [sp+Ch] [-11C4h]
  int v55; // [sp+Ch] [-11C4h]
  int v56; // [sp+10h] [-11C0h]
  int v57; // [sp+10h] [-11C0h]
  int v58; // [sp+10h] [-11C0h]
  int v59; // [sp+10h] [-11C0h]
  int v60; // [sp+14h] [-11BCh]
  int v61; // [sp+14h] [-11BCh]
  int v62; // [sp+14h] [-11BCh]
  int v63; // [sp+14h] [-11BCh]
  int v64; // [sp+18h] [-11B8h]
  int v65; // [sp+18h] [-11B8h]
  int v66; // [sp+18h] [-11B8h]
  int v67; // [sp+18h] [-11B8h]
  int v68; // [sp+1Ch] [-11B4h]
  int v69; // [sp+1Ch] [-11B4h]
  int v70; // [sp+1Ch] [-11B4h]
  int v71; // [sp+1Ch] [-11B4h]
  char *v72; // [sp+50h] [-1180h] BYREF
  char v73; // [sp+54h] [-117Ch]
  idStr v74; // [sp+60h] [-1170h] BYREF
  idStr v75; // [sp+80h] [-1150h] BYREF
  int v76; // [sp+A0h] [-1130h]
  idStr v77; // [sp+B0h] [-1120h] BYREF
  idStr v78; // [sp+D0h] [-1100h] BYREF
  idStr v79; // [sp+F0h] [-10E0h] BYREF
  idStr v80; // [sp+110h] [-10C0h] BYREF
  idStr v81; // [sp+130h] [-10A0h] BYREF
  va v82; // [sp+150h] [-1080h] BYREF

  if ( args->argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  idStr::idStr(this: &v78, text: v4);
  idStr::idStr(this: &v74, text: &v78);
  idStr::idStr(this: &v80, text: "regression");
  idStr::idStr(this: &v79, text: "regression_start");
  idStr::idStr(this: &v75, text: &byte_8200D768);
  idStr::StripFileExtension(this: &v74);
  idStr::idStr(this: &v77, text: &v78);
  idStr::Insert(this: &v77, text: "maps/", index: 0);
  idStr::StripFileExtension(this: &v77);
  idStr::DefaultFileExtension(this: &v77, extension: ".txt");
  v5 = fileSystem->ReadFile(this: fileSystem, a2: v77.data, a3: (void **)&v72, a4: nullptr);
  if ( v72 != nullptr )
  {
    argc = args->argc;
    v7 = args->argc < 3;
    v76 = args->argc;
    if ( v7 )
    {
      v8 = "01";
    }
    else if ( argc <= 2 )
    {
      v8 = &byte_8200D768;
    }
    else
    {
      v8 = args->argv[2];
    }
    idStr::operator=(this: &v75, text: v8);
    v11 = v72;
    LODWORD(v12) = v75.data;
    v13 = (unsigned int)&v72[v5];
    v15 = v75.data[1];
    v16 = v11 >= &v11[v5];
    v14 = v72;
    if ( !v16 )
    {
      v17 = *v75.data;
      while ( 1 )
      {
        v18 = *v14;
        LODWORD(v9) = *v14++;
        if ( v18 == v17 )
        {
          v19 = *v14;
          LODWORD(v9) = v15;
          HIDWORD(v9) = *v14++;
          if ( v19 == v15 )
          {
            v20 = (unsigned __int8)*v14++;
            if ( v20 == 32 )
              break;
          }
        }
        if ( (unsigned int)v14 < v13 )
        {
          while ( 1 )
          {
            v21 = *v14;
            if ( v21 == 10 || v21 == 13 )
              break;
            if ( (unsigned int)++v14 >= v13 )
              goto LABEL_25;
          }
          for ( ; (unsigned int)v14 < v13; ++v14 )
          {
            v22 = *v14;
            if ( v22 != 10 && v22 != 13 )
              break;
          }
        }
LABEL_25:
        HIDWORD(v12) = v74.data;
        v23 = va::va(
                this: &v82,
                fmt: "%s_%s",
                a3: v12,
                a4: v10,
                a5: v9,
                a6: v48,
                a7: v52,
                a8: v56,
                a9: v60,
                a10: v64,
                a11: v68);
        v24 = v23;
        for ( i = 0; v23->buffer[i] != 0; ++i )
          ;
        v26 = i + 1;
        v27 = v74.allocedAndFlag & 0x7FFFFFFF;
        if ( v74.allocedAndFlag >= 0 )
        {
          if ( v26 > v27 )
            idStr::ReAllocate(this: &v74, amount: v26, keepold: false);
        }
        else if ( v26 > v27
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v74.data, Src: v24, Size: i);
        v74.data[i] = 0;
        v74.len = i;
        if ( (unsigned int)v14 >= v13 )
          goto LABEL_39;
        LODWORD(v12) = v75.data;
      }
      idStr::StripFilename(this: &v74);
      idStr::Append(this: &v74, text: "/");
      for ( ; (unsigned int)v14 < v13; v74.data[v74.len] = 0 )
      {
        v28 = *v14;
        if ( *v14 == 10 )
          break;
        if ( v28 == 13 )
          break;
        v73 = *v14;
        idStr::EnsureAlloced(this: &v74, amount: v74.len + 2, keepold: true, geometricGrowth: true);
        ++v14;
        v74.data[v74.len++] = v28;
      }
LABEL_39:
      v11 = v72;
    }
    fileSystem->FreeFile(this: fileSystem, a2: v11);
  }
  if ( idStr::Cmp(s1: v75.data, s2: &byte_8200D768) != 0 )
  {
    v31 = va::va(
            this: &v82,
            fmt: "%s_%s",
            a3: __SPAIR64__((unsigned int)v80.data, (unsigned int)v75.data),
            a4: v30,
            a5: v29,
            a6: v48,
            a7: v52,
            a8: v56,
            a9: v60,
            a10: v64,
            a11: v68);
    idStr::operator=(this: &v80, text: v31);
    v34 = va::va(
            this: &v82,
            fmt: "%s_%s",
            a3: __SPAIR64__((unsigned int)v79.data, (unsigned int)v75.data),
            a4: v33,
            a5: v32,
            a6: v49,
            a7: v53,
            a8: v57,
            a9: v61,
            a10: v65,
            a11: v69);
    idStr::operator=(this: &v79, text: v34);
  }
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionWindow.cfg");
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionTest.cfg");
  common->RecordPlayback(this: common, a2: true, a3: v74.data);
  HIDWORD(v35) = &unk_82270000;
  HIDWORD(v36) = v80.data;
  v38 = va::va(
          this: &v82,
          fmt: "si_nextlayeractive %s\n",
          a3: v36,
          a4: v37,
          a5: v35,
          a6: v48,
          a7: v52,
          a8: v56,
          a9: v60,
          a10: v64,
          a11: v68);
  this->QueueEventString(this, a2: (const char *)v38);
  idStr::idStr(this: &v81, text: si_spawnspot.valueString.data);
  v41 = idStr::Cmp(s1: v81.data, s2: "player_start");
  HIDWORD(v42) = v79.data;
  if ( v41 != 0 )
    HIDWORD(v42) = v81.data;
  v43 = va::va(
          this: &v82,
          fmt: "si_spawnSpot %s\n",
          a3: v42,
          a4: v40,
          a5: v39,
          a6: v50,
          a7: v54,
          a8: v58,
          a9: v62,
          a10: v66,
          a11: v70);
  this->QueueEventString(this, a2: (const char *)v43);
  LODWORD(v44) = &unk_82270000;
  HIDWORD(v45) = v78.data;
  v47 = va::va(
          this: &v82,
          fmt: "map %s noclear   \n",
          a3: v45,
          a4: v44,
          a5: v46,
          a6: v51,
          a7: v55,
          a8: v59,
          a9: v63,
          a10: v67,
          a11: v71);
  this->QueueEventString(this, a2: (const char *)v47);
  idStr::FreeData(this: &v81);
  idStr::FreeData(this: &v77);
  idStr::FreeData(this: &v75);
  idStr::FreeData(this: &v79);
  idStr::FreeData(this: &v80);
  idStr::FreeData(this: &v74);
  idStr::FreeData(this: &v78);
}


// ========================================================================
// __unwind$221737
// EA  : 0x829EB35C
// RVA : 0x009EB35C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221737()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 208));
}


// ========================================================================
// __unwind$221738_0
// EA  : 0x829EB384
// RVA : 0x009EB384
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221738_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 96));
}


// ========================================================================
// __unwind$221739
// EA  : 0x829EB3AC
// RVA : 0x009EB3AC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221739()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 272));
}


// ========================================================================
// __unwind$221740
// EA  : 0x829EB3D4
// RVA : 0x009EB3D4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221740()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 240));
}


// ========================================================================
// __unwind$221741
// EA  : 0x829EB3FC
// RVA : 0x009EB3FC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 128));
}


// ========================================================================
// __unwind$221742
// EA  : 0x829EB424
// RVA : 0x009EB424
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 176));
}


// ========================================================================
// __unwind$221743_0
// EA  : 0x829EB44C
// RVA : 0x009EB44C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_221743_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 304));
}


// ========================================================================
// ?MakeTestLoadGame@idRegressionLocal@@UAAXABVidCmdArgs@@@Z
// EA  : 0x829EB480
// RVA : 0x009EB480
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::MakeTestLoadGame(idRegressionLocal *this, const idCmdArgs *args)
{
  const char *v4; // r4
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r8
  va *v8; // r3
  idStr *v9; // r3
  BOOL v10; // r28
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  va *v14; // r3
  int v15; // [sp+8h] [-10E8h]
  int v16; // [sp+8h] [-10E8h]
  int v17; // [sp+Ch] [-10E4h]
  int v18; // [sp+Ch] [-10E4h]
  int v19; // [sp+10h] [-10E0h]
  int v20; // [sp+10h] [-10E0h]
  int v21; // [sp+14h] [-10DCh]
  int v22; // [sp+14h] [-10DCh]
  int v23; // [sp+18h] [-10D8h]
  int v24; // [sp+18h] [-10D8h]
  int v25; // [sp+1Ch] [-10D4h]
  int v26; // [sp+1Ch] [-10D4h]
  idStr v27; // [sp+60h] [-1090h] BYREF
  idStr v28; // [sp+80h] [-1070h] BYREF
  idStr v29; // [sp+A0h] [-1050h] BYREF
  va v30; // [sp+C0h] [-1030h] BYREF

  if ( args->argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  idStr::idStr(this: &v28, text: v4);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionWindow.cfg");
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionTest.cfg");
  idStr::idStr(this: &v27, text: v28.data);
  idStr::StripFileExtension(this: &v27);
  if ( args->argc > 2 )
    idStr::Append(this: &v27, text: args->argv[2]);
  idStr::Append(this: &v27, text: "_loadgame");
  common->RecordPlayback(this: common, a2: true, a3: v27.data);
  HIDWORD(v6) = si_nextlayeractive.valueString.data;
  HIDWORD(v7) = (unsigned __int8)*si_nextlayeractive.valueString.data;
  if ( *si_nextlayeractive.valueString.data == 0 )
  {
    idCVar::SetString(this: &si_nextlayeractive, newValue: "regression", force: true);
    HIDWORD(v6) = si_nextlayeractive.valueString.data;
  }
  v8 = va::va(
         this: &v30,
         fmt: "si_nextlayeractive %s\n",
         a3: v6,
         a4: v7,
         a5: v5,
         a6: v15,
         a7: v17,
         a8: v19,
         a9: v21,
         a10: v23,
         a11: v25);
  this->QueueEventString(this, a2: (const char *)v8);
  v9 = idStr::idStr(this: &v29, text: si_spawnspot.valueString.data);
  v10 = (_cntlzw(idStr::Cmp(s1: v9->data, s2: "player_start")) & 0x20) != 0;
  idStr::FreeData(this: &v29);
  if ( v10 )
    idCVar::SetString(this: &si_spawnspot, newValue: "regression_start", force: true);
  HIDWORD(v13) = si_spawnspot.valueString.data;
  v14 = va::va(
          this: &v30,
          fmt: "si_spawnSpot %s\n",
          a3: v13,
          a4: v12,
          a5: v11,
          a6: v16,
          a7: v18,
          a8: v20,
          a9: v22,
          a10: v24,
          a11: v26);
  this->QueueEventString(this, a2: (const char *)v14);
  this->QueueEventString(this, a2: "si_forcePlayerRespawn 1\n");
  this->QueueEventString(this, a2: "loadgame regressiontest\n");
  idStr::FreeData(this: &v27);
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$222022
// EA  : 0x829EB684
// RVA : 0x009EB684
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222022()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 128));
}


// ========================================================================
// __unwind$222023
// EA  : 0x829EB6AC
// RVA : 0x009EB6AC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222023()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 96));
}


// ========================================================================
// __unwind$222024
// EA  : 0x829EB6D4
// RVA : 0x009EB6D4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222024()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 160));
}


// ========================================================================
// ??0idRegressionLocal@@QAA@XZ
// EA  : 0x829EB708
// RVA : 0x009EB708
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

idRegressionLocal *__fastcall idRegressionLocal::idRegressionLocal(idRegressionLocal *this)
{
  this->__vftable = (idRegressionLocal_vtbl *)&idRegressionLocal::`vftable';
  this->includedTests.granularity = 0;
  this->includedTests.memTag = 5;
  this->includedTests.listStatic = 0;
  this->includedTests.list = nullptr;
  this->includedTests.size = 0;
  this->includedTests.num = 0;
  this->excludedTests.granularity = 0;
  this->excludedTests.memTag = 5;
  this->excludedTests.listStatic = 0;
  this->excludedTests.list = nullptr;
  this->excludedTests.size = 0;
  this->excludedTests.num = 0;
  this->testReports.list = nullptr;
  this->testReports.granularity = 0;
  this->testReports.memTag = 5;
  this->testReports.listStatic = 0;
  this->testReports.size = 0;
  this->testReports.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->testReports);
  this->folderReports.list = nullptr;
  this->folderReports.granularity = 0;
  this->folderReports.memTag = 5;
  this->folderReports.listStatic = 0;
  this->folderReports.size = 0;
  this->folderReports.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->folderReports);
  this->currentTestReport = 0;
  this->rootPath.len = 0;
  this->rootPath.allocedAndFlag = 20;
  this->rootPath.data = this->rootPath.baseBuffer;
  this->rootPath.baseBuffer[0] = 0;
  this->regressionName.allocedAndFlag = 20;
  this->regressionName.len = 0;
  this->regressionName.data = this->regressionName.baseBuffer;
  this->regressionName.baseBuffer[0] = 0;
  this->testInProgress = false;
  this->eventQueue.curr = 0;
  this->eventQueue.last = 0;
  this->ignoreNextTest = false;
  idXMLWriter::idXMLWriter(this: &this->xmlWriter);
  idStr::operator=(this: &this->regressionName, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$222234
// EA  : 0x829EB82C
// RVA : 0x009EB82C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222234()
{
  int v0; // r12

  idRegression::~idRegression(this: *(idRegression **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$222235
// EA  : 0x829EB854
// RVA : 0x009EB854
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222235()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$222236
// EA  : 0x829EB880
// RVA : 0x009EB880
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222236()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// __unwind$222237
// EA  : 0x829EB8AC
// RVA : 0x009EB8AC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222237()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$222238
// EA  : 0x829EB8D8
// RVA : 0x009EB8D8
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222238()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$222239
// EA  : 0x829EB904
// RVA : 0x009EB904
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222239()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$222240
// EA  : 0x829EB930
// RVA : 0x009EB930
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222240()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// ??1idRegressionLocal@@UAA@XZ
// EA  : 0x829EB9A0
// RVA : 0x009EB9A0
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::~idRegressionLocal(idRegressionLocal *this)
{
  idStr *list; // r3
  idStr *v3; // r3

  this->__vftable = (idRegressionLocal_vtbl *)&idRegressionLocal::`vftable';
  idStr::FreeData(this: &this->regressionName);
  idStr::FreeData(this: &this->rootPath);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->folderReports);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->testReports);
  if ( this->excludedTests.listStatic == 0 || this->excludedTests.listStatic == 2 )
  {
    list = this->excludedTests.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->excludedTests.size);
    this->excludedTests.list = nullptr;
    this->excludedTests.size = 0;
  }
  this->excludedTests.num = 0;
  if ( this->includedTests.listStatic == 0 || this->includedTests.listStatic == 2 )
  {
    v3 = this->includedTests.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->includedTests.size);
    this->includedTests.list = nullptr;
    this->includedTests.size = 0;
  }
  this->includedTests.num = 0;
  this->__vftable = (idRegressionLocal_vtbl *)&idRegression::`vftable';
}


// ========================================================================
// __unwind$222393
// EA  : 0x829EBA64
// RVA : 0x009EBA64
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222393()
{
  int v0; // r12

  idRegression::~idRegression(this: *(idRegression **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$222394
// EA  : 0x829EBA8C
// RVA : 0x009EBA8C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222394()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$222395_0
// EA  : 0x829EBAB8
// RVA : 0x009EBAB8
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222395_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$222396
// EA  : 0x829EBAE4
// RVA : 0x009EBAE4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222396()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$222397
// EA  : 0x829EBB10
// RVA : 0x009EBB10
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222397()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$222398_0
// EA  : 0x829EBB3C
// RVA : 0x009EBB3C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222398_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?ReadTestList@idRegressionLocal@@AAAXVidStr@@AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x829EBB70
// RVA : 0x009EBB70
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::ReadTestList(idRegressionLocal *this, idStr *listName, idList<idStr,5> *list)
{
  int v5; // r3
  const char *v6; // r4
  int v7; // r29
  int v8; // r30
  int i; // r5
  int v10; // r11
  int v11; // r11
  const char *v12; // [sp+50h] [-80h] BYREF
  idStr v13[3]; // [sp+60h] [-70h] BYREF

  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: list->list, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  if ( idStr::Cmp(s1: listName->data, s2: &byte_8200D768) != 0 )
  {
    idStr::DefaultPath(this: listName, basepath: "regression/");
    idStr::DefaultFileExtension(this: listName, extension: ".txt");
    v5 = fileSystem->ReadFile(this: fileSystem, a2: listName->data, a3: (void **)&v12, a4: nullptr);
    v6 = v12;
    v7 = v5;
    if ( v12 != nullptr )
    {
      v8 = 0;
      if ( v5 > 0 )
      {
        do
        {
          for ( i = v8; v8 < v7; ++v8 )
          {
            v10 = v6[v8];
            if ( v10 == 10 )
              break;
            if ( v10 == 13 )
              break;
            if ( v10 == 32 )
              break;
          }
          v13[0].allocedAndFlag = 20;
          v13[0].len = 0;
          v13[0].data = v13[0].baseBuffer;
          v13[0].baseBuffer[0] = 0;
          idStr::CopyRange(this: v13, text: v6, start: i, end: v8);
          idList<idStr,5>::Append(this: list, obj: v13);
          while ( 1 )
          {
            v11 = v12[v8];
            if ( v11 != 10 && v11 != 13 && v11 != 32 )
              break;
            ++v8;
          }
          idStr::FreeData(this: v13);
          v6 = v12;
        }
        while ( v8 < v7 );
      }
      ((void (__fastcall *)(idFileSystem *))fileSystem->FreeFile)(a1: fileSystem);
    }
  }
  idStr::FreeData(this: listName);
}


// ========================================================================
// __unwind$222485_0
// EA  : 0x829EBD08
// RVA : 0x009EBD08
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222485_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 208 + 236));
}


// ========================================================================
// __unwind$222486_1
// EA  : 0x829EBD30
// RVA : 0x009EBD30
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222486_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?BuildReportTree_r@idRegressionLocal@@AAAHPBDPAVidFolderReport@@@Z
// EA  : 0x829EBD60
// RVA : 0x009EBD60
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

int __fastcall idRegressionLocal::BuildReportTree_r(
        idRegressionLocal *this,
        const char *testPath,
        idFolderReport *parent)
{
  char v5; // r27
  char v6; // r26
  int v7; // r23
  int v8; // r29
  int v9; // r30
  idStr *v10; // r3
  BOOL v11; // r25
  int v12; // r29
  int v13; // r30
  idStr *v14; // r3
  BOOL v15; // r25
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  sysFolder_t v20; // r3
  idFolderReport *v21; // r3
  idFolderReport *v22; // r27
  char *data; // r30
  const char *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  va *v27; // r3
  __int64 v28; // r10
  __int64 v29; // r8
  int v30; // r30
  int v31; // r29
  __int64 v32; // r6
  va *v33; // r3
  int v34; // r29
  int v35; // r30
  __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r6
  va *v39; // r3
  idStr *list; // r29
  int size; // r30
  idStr *v42; // r28
  idStr *v43; // r29
  int v44; // r30
  idStr *v45; // r28
  idTestReport *v46; // r3
  idTestReport *v47; // r3
  int v49; // [sp+8h] [-41C8h]
  int v50; // [sp+8h] [-41C8h]
  int v51; // [sp+8h] [-41C8h]
  int v52; // [sp+Ch] [-41C4h]
  int v53; // [sp+Ch] [-41C4h]
  int v54; // [sp+Ch] [-41C4h]
  int v55; // [sp+10h] [-41C0h]
  int v56; // [sp+10h] [-41C0h]
  int v57; // [sp+10h] [-41C0h]
  int v58; // [sp+14h] [-41BCh]
  int v59; // [sp+14h] [-41BCh]
  int v60; // [sp+14h] [-41BCh]
  int v61; // [sp+18h] [-41B8h]
  int v62; // [sp+18h] [-41B8h]
  int v63; // [sp+18h] [-41B8h]
  int v64; // [sp+1Ch] [-41B4h]
  int v65; // [sp+1Ch] [-41B4h]
  int v66; // [sp+1Ch] [-41B4h]
  encounterGroupRole_t v67[4]; // [sp+50h] [-4180h] BYREF
  idList<idStr,5> v68; // [sp+60h] [-4170h] BYREF
  idList<idStr,5> v69; // [sp+70h] [-4160h] BYREF
  idStr v70; // [sp+80h] [-4150h] BYREF
  idStr v71; // [sp+A0h] [-4130h] BYREF
  idStr v72; // [sp+C0h] [-4110h] BYREF
  idStr v73; // [sp+E0h] [-40F0h] BYREF
  idStr v74; // [sp+100h] [-40D0h] BYREF
  idStr v75; // [sp+120h] [-40B0h] BYREF
  idStr v76; // [sp+140h] [-4090h] BYREF
  va v77; // [sp+160h] [-4070h] BYREF
  va v78; // [sp+1160h] [-3070h] BYREF
  va v79; // [sp+2160h] [-2070h] BYREF
  va v80; // [sp+3160h] [-1070h] BYREF

  idStr::idStr(this: &v70, text: testPath);
  v5 = 1;
  v6 = 0;
  v7 = 0;
  v67[0] = (encounterGroupRole_t)this->includedTests.num;
  if ( v67[0] != ROLE_NONE )
  {
    v5 = 0;
    v8 = 0;
    if ( v67[0] > ROLE_NONE )
    {
      v9 = 0;
      do
      {
        v10 = idStr::Left(this: &v75, result: &v70, len: this->includedTests.list[v9].len);
        v11 = (_cntlzw(idStr::Cmp(s1: this->includedTests.list[v9].data, s2: v10->data)) & 0x20) != 0;
        idStr::FreeData(this: &v75);
        if ( v11 )
          v5 = 1;
        ++v8;
        ++v9;
      }
      while ( v8 < this->includedTests.num );
    }
  }
  v12 = 0;
  if ( this->excludedTests.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = idStr::Left(this: &v76, result: &v70, len: this->excludedTests.list[v13].len);
      v15 = (_cntlzw(idStr::Cmp(s1: this->excludedTests.list[v13].data, s2: v14->data)) & 0x20) != 0;
      idStr::FreeData(this: &v76);
      if ( v15 )
        v6 = 1;
      ++v12;
      ++v13;
    }
    while ( v12 < this->excludedTests.num );
  }
  if ( v6 == 0 )
  {
    idStr::StripTrailing(this: &v70, string: "/");
    HIDWORD(v16) = v70.data;
    v19 = va::va(
            this: &v77,
            fmt: "regression/events/%s",
            a3: v16,
            a4: v18,
            a5: v17,
            a6: v49,
            a7: v52,
            a8: v55,
            a9: v58,
            a10: v61,
            a11: v64);
    idStr::idStr(this: &v71, text: v19);
    v20 = fileSystem->IsFolder(this: fileSystem, a2: v71.data, a3: FSPATH_BASE);
    if ( v20 == FOLDER_ERROR )
    {
      idLib::Warning(fmt: "Unknown file or folder: %s", v71.data);
    }
    else if ( v20 != FOLDER_NO )
    {
      if ( v20 == FOLDER_YES )
      {
        v21 = (idFolderReport *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x78u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        v67[0] = (encounterGroupRole_t)v21;
        if ( v21 != nullptr )
          v22 = idFolderReport::idFolderReport(this: v21, path: v70.data, parent);
        else
          v22 = nullptr;
        data = v71.data;
        v67[0] = (encounterGroupRole_t)v22;
        v24 = fileSystem->GetBasePathStr(this: fileSystem, a2: 0);
        HIDWORD(v25) = &unk_82270000;
        v27 = va::va(
                this: &v79,
                fmt: "%s/base/%s",
                a3: __SPAIR64__((unsigned int)v24, (unsigned int)data),
                a4: v26,
                a5: v25,
                a6: v50,
                a7: v53,
                a8: v56,
                a9: v59,
                a10: v62,
                a11: v65);
        idStr::idStr(this: &v72, text: v27);
        *(_WORD *)&v69.memTag = 1280;
        memset(&v69, 0, 14);
        Sys_ListFiles(directory: v72.data, extension: "events", list: &v69);
        HIDWORD(v29) = v69.num;
        v30 = v69.num - 1;
        if ( v69.num - 1 >= 0 )
        {
          v31 = v30;
          do
          {
            HIDWORD(v32) = v70.data;
            LODWORD(v32) = v69.list[v31].data;
            v33 = va::va(
                    this: &v78,
                    fmt: "%s/%s",
                    a3: v32,
                    a4: v29,
                    a5: v28,
                    a6: v51,
                    a7: v54,
                    a8: v57,
                    a9: v60,
                    a10: v63,
                    a11: v66);
            idStr::idStr(this: &v73, text: v33);
            v7 += idRegressionLocal::BuildReportTree_r(this, testPath: v73.data, parent: v22);
            idStr::FreeData(this: &v73);
            --v30;
            --v31;
          }
          while ( v30 >= 0 );
        }
        *(_WORD *)&v68.memTag = 1280;
        memset(&v68, 0, 14);
        Sys_ListFiles(directory: v72.data, extension: "/", list: &v68);
        v34 = v68.num - 1;
        if ( v68.num - 1 >= 0 )
        {
          v35 = v34;
          do
          {
            if ( idStr::Cmp(s1: v68.list[v35].data, s2: "..") != 0 && idStr::Cmp(s1: v68.list[v35].data, s2: ".") != 0 )
            {
              HIDWORD(v38) = v70.data;
              LODWORD(v38) = v68.list[v35].data;
              v39 = va::va(
                      this: &v80,
                      fmt: "%s/%s",
                      a3: v38,
                      a4: v37,
                      a5: v36,
                      a6: v51,
                      a7: v54,
                      a8: v57,
                      a9: v60,
                      a10: v63,
                      a11: v66);
              idStr::idStr(this: &v74, text: v39);
              v7 += idRegressionLocal::BuildReportTree_r(this, testPath: v74.data, parent: v22);
              idStr::FreeData(this: &v74);
            }
            --v34;
            --v35;
          }
          while ( v34 >= 0 );
        }
        if ( v7 != 0 )
        {
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->folderReports,
            obj: v67);
          if ( parent != nullptr )
            ++parent->numChildren;
        }
        else if ( v22 != nullptr )
        {
          ((void (__fastcall *)(idFolderReport *, int))v22->dtr_idReport)(a1: v22, a2: 1);
        }
        if ( v68.listStatic == 0 || v68.listStatic == 2 )
        {
          list = v68.list;
          if ( v68.list != nullptr )
          {
            size = v68.size;
            v42 = v68.list;
            if ( v68.size > 0 )
            {
              do
              {
                idStr::FreeData(this: list);
                --size;
                ++list;
              }
              while ( size != 0 );
            }
            idMem::Free(this: &mem, ptr: v42, align: ALIGN_16);
          }
          v68.list = nullptr;
          v68.size = 0;
        }
        v68.num = 0;
        if ( v69.listStatic == 0 || v69.listStatic == 2 )
        {
          v43 = v69.list;
          if ( v69.list != nullptr )
          {
            v44 = v69.size;
            v45 = v69.list;
            if ( v69.size > 0 )
            {
              do
              {
                idStr::FreeData(this: v43);
                --v44;
                ++v43;
              }
              while ( v44 != 0 );
            }
            idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
          }
          v69.list = nullptr;
          v69.size = 0;
        }
        v69.num = 0;
        idStr::FreeData(this: &v72);
      }
    }
    else if ( v5 != 0 )
    {
      v46 = (idTestReport *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x94u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      v67[0] = (encounterGroupRole_t)v46;
      if ( v46 != nullptr )
        v47 = idTestReport::idTestReport(this: v46, path: v70.data, parent);
      else
        v47 = nullptr;
      v67[0] = (encounterGroupRole_t)v47;
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->testReports, obj: v67);
      if ( parent != nullptr )
        ++parent->numChildren;
      v7 = 1;
      ++this->currentTestReport;
    }
    idStr::FreeData(this: &v71);
  }
  idStr::FreeData(this: &v70);
  return v7;
}


// ========================================================================
// __unwind$222586
// EA  : 0x829EC2CC
// RVA : 0x009EC2CC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 128));
}


// ========================================================================
// __unwind$222587
// EA  : 0x829EC2F4
// RVA : 0x009EC2F4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222587()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 288));
}


// ========================================================================
// __unwind$222588
// EA  : 0x829EC31C
// RVA : 0x009EC31C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222588()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 320));
}


// ========================================================================
// __unwind$222589
// EA  : 0x829EC344
// RVA : 0x009EC344
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222589()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 160));
}


// ========================================================================
// __unwind$222591
// EA  : 0x829EC36C
// RVA : 0x009EC36C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall _unwind_222591(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 16848 + 80), tag: a2);
}


// ========================================================================
// __unwind$222592
// EA  : 0x829EC394
// RVA : 0x009EC394
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 192));
}


// ========================================================================
// __unwind$222593
// EA  : 0x829EC3BC
// RVA : 0x009EC3BC
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222593()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 16848 + 112));
}


// ========================================================================
// __unwind$222594_0
// EA  : 0x829EC3E4
// RVA : 0x009EC3E4
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222594_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 224));
}


// ========================================================================
// __unwind$222595_0
// EA  : 0x829EC40C
// RVA : 0x009EC40C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222595_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 16848 + 96));
}


// ========================================================================
// __unwind$222596_0
// EA  : 0x829EC434
// RVA : 0x009EC434
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_222596_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16848 + 256));
}


// ========================================================================
// __unwind$222590
// EA  : 0x829EC45C
// RVA : 0x009EC45C
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall _unwind_222590(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 16848 + 80), tag: a2);
}


// ========================================================================
// ?StartXMLReport@idRegressionLocal@@AAAXXZ
// EA  : 0x829EC4F0
// RVA : 0x009EC4F0
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::StartXMLReport(idRegressionLocal *this)
{
  idXMLWriter *p_xmlWriter; // r29
  idList<idXMLAttribute,44> v3; // [sp+50h] [-B0h] BYREF
  idStr v4; // [sp+60h] [-A0h] BYREF
  idStr v5; // [sp+80h] [-80h] BYREF
  idXMLAttribute v6; // [sp+A0h] [-60h] BYREF

  idStr::idStr(this: &v5, text: &this->rootPath);
  idStr::StripTrailing(this: &v5, string: "/");
  idStr::StripTrailing(this: &v5, string: ".events");
  v4.len = 0;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.baseBuffer[0] = 0;
  idStr::Format(this: &v4, fmt: "regression/reports/%s/report.xml", v5.data);
  p_xmlWriter = &this->xmlWriter;
  idXMLWriter::OpenFile(this: p_xmlWriter, relativePath: v4.data, overwrite: true, savepath: true);
  if ( p_xmlWriter->xmlFile != nullptr )
  {
    *(_WORD *)&v3.memTag = 1280;
    memset(&v3, 0, 14);
    idXMLAttribute::idXMLAttribute(this: &v6, name: "version", value: "1.1");
    idList<idXMLAttribute,44>::Append(this: &v3, obj: &v6);
    idXMLWriter::OpenElement(this: p_xmlWriter, name: "RegressionTests", attributes: &v3);
    idKeyValue::~idKeyValue(this: &v6);
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)&v3);
  }
  idStr::FreeData(this: &v4);
  idStr::FreeData(this: &v5);
}


// ========================================================================
// __unwind$223087
// EA  : 0x829EC600
// RVA : 0x009EC600
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_223087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$223088
// EA  : 0x829EC628
// RVA : 0x009EC628
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_223088()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$223089
// EA  : 0x829EC650
// RVA : 0x009EC650
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_223089()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$223090
// EA  : 0x829EC678
// RVA : 0x009EC678
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void _unwind_223090()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 256 + 160));
}


// ========================================================================
// ?PlayTest@idRegressionLocal@@UAAXPBD_N@Z
// EA  : 0x829EC6A0
// RVA : 0x009EC6A0
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __fastcall idRegressionLocal::PlayTest(idRegressionLocal *this, const char *testPath, bool atStartUp)
{
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  va *v8; // r3
  idStr *v9; // r3
  idStr *v10; // r3
  idJoystick *v11; // r3
  idKeyboard *v12; // r3
  idMouse *v13; // r3
  int v14; // [sp+8h] [-1088h]
  int v15; // [sp+Ch] [-1084h]
  int v16; // [sp+10h] [-1080h]
  int v17; // [sp+14h] [-107Ch]
  int v18; // [sp+18h] [-1078h]
  int v19; // [sp+1Ch] [-1074h]
  idStr v20; // [sp+50h] [-1040h] BYREF
  va v21; // [sp+70h] [-1020h] BYREF

  if ( atStartUp )
  {
    this->QueueEventString(this, a2: "~");
    LODWORD(v5) = &unk_82270000;
    HIDWORD(v6) = testPath;
    v8 = va::va(
           this: &v21,
           fmt: "playtest %s \n",
           a3: v6,
           a4: v5,
           a5: v7,
           a6: v14,
           a7: v15,
           a8: v16,
           a9: v17,
           a10: v18,
           a11: v19);
    this->QueueEventString(this, a2: (const char *)v8);
  }
  else
  {
    idStr::operator=(this: &this->rootPath, text: testPath);
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "exec regression/regressionWindow.cfg");
    v9 = idStr::idStr(this: &v20, text: reg_includeList.valueString.data);
    idRegressionLocal::ReadTestList(this, listName: v9, list: &this->includedTests);
    v10 = idStr::idStr(this: &v20, text: reg_excludeList.valueString.data);
    idRegressionLocal::ReadTestList(this, listName: v10, list: &this->excludedTests);
    idRegressionLocal::BuildReportTree_r(this, testPath, parent: nullptr);
    idRegressionLocal::StartXMLReport(this);
    v11 = sys->Joystick(this: sys);
    v11->Shutdown(this: v11);
    v12 = sys->Keyboard(this: sys);
    v12->Shutdown(this: v12);
    v13 = sys->Mouse(this: sys);
    v13->Shutdown(this: v13);
    this->NextTest(this);
  }
}


// ========================================================================
// `dynamic initializer for 'com_prod_regression''
// EA  : 0x83364040
// RVA : 0x01364040
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_prod_regression__()
{
  idCVar::idCVar(
    this: &com_prod_regression,
    name: "com_prod_regression",
    value: "0",
    flags: 1,
    description: "Regression tests require certain functionality in production builds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_prod_regression__);
}


// ========================================================================
// `dynamic initializer for 'playtest_openbrowser''
// EA  : 0x83364098
// RVA : 0x01364098
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playtest_openbrowser__()
{
  idCVar::idCVar(
    this: &playtest_openbrowser,
    name: "playtest_openbrowser",
    value: "1",
    flags: 1,
    description: "Open web browser to show regression test results.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playtest_openbrowser__);
}


// ========================================================================
// `dynamic initializer for 'reg_includeList''
// EA  : 0x833640F0
// RVA : 0x013640F0
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__reg_includeList__()
{
  idCVar::idCVar(
    this: &reg_includeList,
    name: "reg_includeList",
    value: &byte_8200D768,
    flags: 0,
    description: "optional file for specifying list of tests/paths to run",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__reg_includeList__);
}


// ========================================================================
// `dynamic initializer for 'reg_excludeList''
// EA  : 0x83364148
// RVA : 0x01364148
// PDB : w:\tech5\engine\test\regression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__reg_excludeList__()
{
  idCVar::idCVar(
    this: &reg_excludeList,
    name: "reg_excludeList",
    value: &byte_8200D768,
    flags: 0,
    description: "optional file for specifying list of tests/paths to skip, which override reg_includeList",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__reg_excludeList__);
}

