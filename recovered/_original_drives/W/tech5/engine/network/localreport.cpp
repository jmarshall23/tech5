
// ========================================================================
// ?WriteReport@idLocalReport@@UAAXXZ
// EA  : 0x8289AB20
// RVA : 0x0089AB20
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void __fastcall idLocalReport::WriteReport(idLocalReport *this)
{
  const char *v2; // r3
  idStr *v3; // r3
  idStr *v4; // r3
  idStr *v5; // r3
  idStr *v6; // r3
  idStr *v7; // r3
  const idStr *v8; // r3
  idStr *v9; // r29
  size_t len; // r30
  idStr v11; // [sp+50h] [-270h] BYREF
  _DWORD v12[4]; // [sp+70h] [-250h] BYREF
  idStr v13; // [sp+80h] [-240h] BYREF
  idStr v14; // [sp+A0h] [-220h] BYREF
  idStr v15; // [sp+C0h] [-200h] BYREF
  idStr v16; // [sp+E0h] [-1E0h] BYREF
  idStr v17; // [sp+100h] [-1C0h] BYREF
  idStr v18; // [sp+120h] [-1A0h] BYREF
  idStr v19; // [sp+140h] [-180h] BYREF
  idStr v20; // [sp+160h] [-160h] BYREF
  char v21[320]; // [sp+180h] [-140h] BYREF

  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: reportData.style.data, a3: v21, a4: 256, a5: FSPATH_SAVE);
  idStr::idStr(this: &v13, text: v21);
  v2 = sys->GetMachineName(this: sys);
  idStr::SetFileExtension(this: &v13, extension: v2);
  idStr::Append(this: &v13, text: ".");
  v12[0] = 0;
  fileSystem->GetNumberedFilename(this: fileSystem, a2: v12, a3: v13.data, a4: "html", a5: &this->fileName, a6: true);
  idStr::ToLower(this: &this->fileName);
  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  if ( reportData.callstack.len != 0 )
  {
    v3 = operator+(result: &v20, a: &reportData.callstack, b: "\r\n");
    idStr::Append(this: &v11, text: v3);
    idStr::FreeData(this: &v20);
    v4 = operator+(result: &v16, a: &reportData.registers, b: "\r\n");
    idStr::Append(this: &v11, text: v4);
    idStr::FreeData(this: &v16);
    v5 = operator+(result: &v14, a: &reportData.exception, b: "\r\n");
    idStr::Append(this: &v11, text: v5);
    idStr::FreeData(this: &v14);
  }
  v6 = operator+(result: &v18, a: &reportData.systemInfo, b: "\r\n");
  idStr::Append(this: &v11, text: v6);
  idStr::FreeData(this: &v18);
  if ( idStr::Cmp(s1: reportData.someFunctionDetails.data, s2: &byte_8200D768) != 0 )
  {
    idStr::Append(this: &v11, text: "Function Details            \r\n");
    idStr::Append(this: &v11, text: "--------------------------- \r\n");
    v7 = operator+(result: &v15, a: &reportData.someFunctionDetails, b: "\r\n");
    idStr::Append(this: &v11, text: v7);
    idStr::FreeData(this: &v15);
  }
  idLib::Printf(fmt: "%s\n", v11.data);
  idStr::Replace(this: &v11, old: "<", nw: "&lt;");
  idStr::Replace(this: &v11, old: ">", nw: "&gt;");
  v8 = operator+(result: &v19, a: "<PRE>\r\n", b: &v11);
  v9 = operator+(result: &v17, a: v8, b: "\r\n</PRE>");
  len = v9->len;
  idStr::EnsureAlloced(this: &v11, amount: v9->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v11.data, Src: v9->data, Size: len);
  v11.data[len] = 0;
  v11.len = len;
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: &v19);
  fileSystem->WriteFile(this: fileSystem, a2: this->fileName.data, a3: v11.data, a4: v11.len, a5: FSPATH_SAVE);
  idStr::FreeData(this: &v11);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$219590
// EA  : 0x8289ADE8
// RVA : 0x0089ADE8
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219590()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 128));
}


// ========================================================================
// __unwind$219591
// EA  : 0x8289AE10
// RVA : 0x0089AE10
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 80));
}


// ========================================================================
// __unwind$219592
// EA  : 0x8289AE38
// RVA : 0x0089AE38
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 352));
}


// ========================================================================
// __unwind$219593
// EA  : 0x8289AE60
// RVA : 0x0089AE60
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 224));
}


// ========================================================================
// __unwind$219594
// EA  : 0x8289AE88
// RVA : 0x0089AE88
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 160));
}


// ========================================================================
// __unwind$219595
// EA  : 0x8289AEB0
// RVA : 0x0089AEB0
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 288));
}


// ========================================================================
// __unwind$219596
// EA  : 0x8289AED8
// RVA : 0x0089AED8
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 192));
}


// ========================================================================
// __unwind$219597
// EA  : 0x8289AF00
// RVA : 0x0089AF00
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 320));
}


// ========================================================================
// __unwind$219598_0
// EA  : 0x8289AF28
// RVA : 0x0089AF28
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void _unwind_219598_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 256));
}


// ========================================================================
// ?TestLocalReport_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8289AF50
// RVA : 0x0089AF50
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void __fastcall TestLocalReport_f(const idCmdArgs *args)
{
  idReportData::SetDefaults(this: &reportData);
  idStr::operator=(this: &reportData.style, text: "TestLocal");
  idStr::operator=(this: &reportData.title, text: "Local report code test");
  idStr::operator=(this: &reportData.steps, text: "\r\n1. Do something\r\n2. Do something else");
  idStr::operator=(this: &reportData.details, text: "Testing Local report code");
  idStr::operator=(this: &reportData.severity, text: "Critical");
  idStr::operator=(this: &reportData.reproduced, text: "Once");
  idReportData::Format(this: &reportData);
  idLocalReport::WriteReport(this: &localReport);
}


// ========================================================================
// `dynamic initializer for 'localReport''
// EA  : 0x833457D8
// RVA : 0x013457D8
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localReport__()
{
  idLocalReport::idLocalReport(this: &localReport);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localReport__);
}


// ========================================================================
// `dynamic initializer for 'TestLocalReport_v''
// EA  : 0x83345810
// RVA : 0x01345810
// PDB : w:\tech5\engine\network\localreport.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestLocalReport_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestLocalReport_v,
           cmdName: "TestLocalReport",
           function: TestLocalReport_f,
           description: "Tests the Local Report code",
           argCompletion: nullptr);
}

