
// ========================================================================
// ?FinishReport@idReport@@IAAXXZ
// EA  : 0x829EC840
// RVA : 0x009EC840
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idReport::FinishReport(idReport *this)
{
  idFile *html; // r3

  this->html->Printf(this: this->html, a2: "    </TABLE>\n");
  this->html->Printf(this: this->html, a2: "  </BODY>\n");
  this->html->Printf(this: this->html, a2: "</HTML>\n");
  html = this->html;
  if ( html != nullptr )
    ((void (__fastcall *)(idFile *, int))html->dtr_idFile)(a1: html, a2: 1);
  this->html = nullptr;
}


// ========================================================================
// ?RunTest@idTestReport@@QAAXAAVidXMLWriter@@@Z
// EA  : 0x829EC900
// RVA : 0x009EC900
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idTestReport::RunTest(idTestReport *this, idXMLWriter *xmlWriter)
{
  idRegression *v3; // r3
  idRegression *v4; // r3

  this->xmlWriter = xmlWriter;
  v3 = common->GetRegression(this: common);
  v3->UpdateCurrentTestFile(this: v3, a2: this->reportPath.data);
  v4 = common->GetRegression(this: common);
  v4->SetTestInProgress(this: v4, a2: true);
  idCommonLocal::RecordPlayback(this: &commonLocal, record: false, fileName: this->reportPath.data);
}


// ========================================================================
// ??0idReport@@QAA@PBDPAVidFolderReport@@@Z
// EA  : 0x829EC9A8
// RVA : 0x009EC9A8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

idReport *__fastcall idReport::idReport(idReport *this, const char *path, idFolderReport *parent)
{
  idStr *p_reportPath; // r28

  this->html = nullptr;
  p_reportPath = &this->reportPath;
  this->__vftable = (idReport_vtbl *)&idReport::`vftable';
  this->xmlWriter = nullptr;
  idStr::idStr(this: &this->reportPath, text: path);
  idStr::idStr(this: &this->pathSuffix, text: &byte_8200D768);
  this->reportParent = parent;
  this->childResults.list = nullptr;
  this->childResults.granularity = 0;
  this->childResults.memTag = 5;
  this->childResults.listStatic = 0;
  this->childResults.size = 0;
  this->childResults.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childResults);
  this->finalResult = TEST_PASS;
  idStr::StripFileExtension(this: p_reportPath);
  return this;
}


// ========================================================================
// __unwind$222517
// EA  : 0x829ECA3C
// RVA : 0x009ECA3C
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222517()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// __unwind$222518_0
// EA  : 0x829ECA68
// RVA : 0x009ECA68
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222518_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// __unwind$222519_0
// EA  : 0x829ECA94
// RVA : 0x009ECA94
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222519_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// ??0idFolderReport@@QAA@PBDPAV0@@Z
// EA  : 0x829ECCA8
// RVA : 0x009ECCA8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

idFolderReport *__fastcall idFolderReport::idFolderReport(
        idFolderReport *this,
        const char *path,
        idFolderReport *parent)
{
  idReport::idReport(this, path, parent);
  this->numChildren = 0;
  this->__vftable = (idFolderReport_vtbl *)&idFolderReport::`vftable';
  this->testPaths.granularity = 0;
  this->testPaths.memTag = 5;
  this->testPaths.listStatic = 0;
  this->testPaths.list = nullptr;
  this->testPaths.size = 0;
  this->testPaths.num = 0;
  idStr::operator=(this: &this->pathSuffix, text: idReport::folderSuffix);
  return this;
}


// ========================================================================
// __unwind$222686_0
// EA  : 0x829ECD30
// RVA : 0x009ECD30
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222686_0()
{
  int v0; // r12

  idReport::~idReport(this: *(idReport **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$222687_0
// EA  : 0x829ECD58
// RVA : 0x009ECD58
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222687_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// ?AddResult@idFolderReport@@UAAXW4testStatus_t@@@Z
// EA  : 0x829ECE18
// RVA : 0x009ECE18
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idFolderReport::AddResult(idFolderReport *this, encounterGroupRole_t result)
{
  encounterGroupRole_t v3[4]; // [sp+50h] [-20h] BYREF

  v3[0] = result;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->childResults, obj: v3);
  if ( this->childResults.num == this->numChildren )
    this->WriteReport(this);
}


// ========================================================================
// ?AddResult@idTestReport@@QAAXW4testStatus_t@@@Z
// EA  : 0x829ECE78
// RVA : 0x009ECE78
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idTestReport::AddResult(idTestReport *this, encounterGroupRole_t result)
{
  encounterGroupRole_t v2[2]; // [sp+50h] [-10h] BYREF

  v2[0] = result;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->childResults, obj: v2);
}


// ========================================================================
// ?StartReport@idReport@@IAAXXZ
// EA  : 0x829ED030
// RVA : 0x009ED030
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idReport::StartReport(idReport *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int num; // r11
  int v7; // r11
  testStatus_t v8; // r10
  __int64 v9; // r6
  va *v10; // r3
  idFolderReport *reportParent; // r29
  va *v12; // r3
  idFile *v13; // r3
  int v14; // [sp+8h] [-10A8h]
  int v15; // [sp+Ch] [-10A4h]
  int v16; // [sp+10h] [-10A0h]
  int v17; // [sp+14h] [-109Ch]
  int v18; // [sp+18h] [-1098h]
  int v19; // [sp+1Ch] [-1094h]
  idStr v20; // [sp+50h] [-1060h] BYREF
  idStr v21; // [sp+70h] [-1040h] BYREF
  va v22; // [sp+90h] [-1020h] BYREF

  num = this->childResults.num;
  HIDWORD(a5) = 0;
  this->finalResult = TEST_SKIP;
  if ( num > 0 )
  {
    LODWORD(a4) = this->childResults.list;
    v7 = 0;
    do
    {
      v8 = *(_DWORD *)(v7 + a4);
      HIDWORD(a4) = this->finalResult;
      if ( v8 > SHIDWORD(a4) )
        this->finalResult = v8;
      LODWORD(a5) = this->childResults.num;
      ++HIDWORD(a5);
      v7 += 4;
    }
    while ( SHIDWORD(a5) < (int)a5 );
  }
  if ( this->reportParent != nullptr )
  {
    LODWORD(v9) = this->pathSuffix.data;
    HIDWORD(v9) = this->reportPath.data;
    v10 = va::va(this: &v22, fmt: "%s%s", a3: v9, a4, a5, a6: v14, a7: v15, a8: v16, a9: v17, a10: v18, a11: v19);
    reportParent = this->reportParent;
    idStr::idStr(this: &v21, text: v10->buffer);
    idList<idStr,5>::Append(this: &reportParent->testPaths, obj: &v21);
    idStr::FreeData(this: &v21);
    this->reportParent->AddResult(this: this->reportParent, a2: this->finalResult);
  }
  HIDWORD(a3) = this->reportPath.data;
  v12 = va::va(
          this: &v22,
          fmt: "regression/reports/%s/report.html",
          a3,
          a4,
          a5,
          a6: v14,
          a7: v15,
          a8: v16,
          a9: v17,
          a10: v18,
          a11: v19);
  idStr::idStr(this: &v20, text: v12);
  v13 = fileSystem->OpenFileWrite(this: fileSystem, a2: v20.data, a3: 2);
  this->html = v13;
  v13->Printf(this: v13, a2: "<HTML>\n");
  this->html->Printf(this: this->html, a2: "  <BODY bgcolor='silver'> <FONT color='black'>\n");
  this->html->Printf(this: this->html, a2: "    <TABLE border='1' bordercolor='black' width='800'>\n");
  this->html->Printf(this: this->html, a2: "      <TR bgcolor='%s'>\n", textColors[this->finalResult]);
  this->html->Printf(this: this->html, a2: "        <TD><B> %s </B></TD>\n", textResult[this->finalResult]);
  this->html->Printf(
    this: this->html,
    a2: "        <TD colspan='2' align='center'><FONT size='+3'><B> %s </B></FONT></TD>\n",
    this->reportPath.data);
  this->html->Printf(this: this->html, a2: "      </TR>\n");
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$222887
// EA  : 0x829ED22C
// RVA : 0x009ED22C
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222887()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 112));
}


// ========================================================================
// __unwind$222862
// EA  : 0x829ED254
// RVA : 0x009ED254
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222862()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 80));
}


// ========================================================================
// ?WriteReport@idFolderReport@@UAAXXZ
// EA  : 0x829ED2E8
// RVA : 0x009ED2E8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idFolderReport::WriteReport(idFolderReport *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v6; // r20
  int v7; // r28
  int v8; // r29
  testStatus_t v9; // r11
  idStr v10[4]; // [sp+50h] [-90h] BYREF

  idReport::StartReport(this, a2, a3, a4, a5);
  this->html->Printf(this: this->html, a2: "      <TR>\n");
  this->html->Printf(this: this->html, a2: "        <TD align='center' width='100'> STATUS      </TD>\n");
  this->html->Printf(this: this->html, a2: "        <TD align='center' width='700'> TEST        </TD>\n");
  this->html->Printf(this: this->html, a2: "      </TR>\n");
  v6 = 0;
  if ( this->testPaths.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      idStr::idStr(this: v10, text: &this->testPaths.list[v7]);
      idStr::StripTrailing(this: v10, string: idReport::folderSuffix);
      idStr::StripPath(this: v10);
      v9 = this->childResults.list[v8];
      if ( v9 != TEST_SKIP )
      {
        this->html->Printf(this: this->html, a2: "      <TR bgcolor='%s'>\n", textColors[v9]);
        this->html->Printf(
          this: this->html,
          a2: "        <TD><B> <A HREF=\"./%s/report.html\">%s</A> </B></TD>\n",
          v10[0].data,
          textResult[this->childResults.list[v8]]);
        this->html->Printf(this: this->html, a2: "        <TD><B> %s </B></TD>\n", this->testPaths.list[v7].data);
        this->html->Printf(this: this->html, a2: "      </TR>\n");
      }
      idStr::FreeData(this: v10);
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < this->testPaths.num );
  }
  idReport::FinishReport(this);
}


// ========================================================================
// __unwind$222952
// EA  : 0x829ED4A4
// RVA : 0x009ED4A4
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_222952()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ??0idTestReport@@QAA@PBDPAVidFolderReport@@@Z
// EA  : 0x829ED4D8
// RVA : 0x009ED4D8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

idTestReport *__fastcall idTestReport::idTestReport(idTestReport *this, const char *path, idFolderReport *parent)
{
  idReport::idReport(this, path, parent);
  this->__vftable = (idTestReport_vtbl *)&idTestReport::`vftable';
  this->types.granularity = 0;
  this->types.memTag = 5;
  this->types.listStatic = 0;
  this->types.list = nullptr;
  this->types.size = 0;
  this->types.num = 0;
  this->infos.granularity = 0;
  this->infos.memTag = 5;
  this->infos.listStatic = 0;
  this->infos.list = nullptr;
  this->infos.size = 0;
  this->infos.num = 0;
  this->testReportFields.granularity = 0;
  this->testReportFields.memTag = 5;
  this->testReportFields.listStatic = 0;
  this->testReportFields.list = nullptr;
  this->testReportFields.size = 0;
  this->testReportFields.num = 0;
  return this;
}


// ========================================================================
// __unwind$223005
// EA  : 0x829ED588
// RVA : 0x009ED588
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223005()
{
  int v0; // r12

  idReport::~idReport(this: *(idReport **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$223006
// EA  : 0x829ED5B0
// RVA : 0x009ED5B0
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223006()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$223007
// EA  : 0x829ED5DC
// RVA : 0x009ED5DC
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223007()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// ?AddTestReportField@idTestReport@@QAAXVidStr@@00@Z
// EA  : 0x829ED760
// RVA : 0x009ED760
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idTestReport::AddTestReportField(idTestReport *this, idStr *name, idStr *type, idStr *value)
{
  int len; // r29
  int v9; // r29
  int v10; // r29
  testReportField_t v11; // [sp+50h] [-A0h] BYREF

  v11.name.len = 0;
  v11.name.baseBuffer[0] = 0;
  v11.type.len = 0;
  v11.type.baseBuffer[0] = 0;
  v11.value.len = 0;
  v11.name.allocedAndFlag = 20;
  v11.name.data = v11.name.baseBuffer;
  v11.type.data = v11.type.baseBuffer;
  v11.value.data = v11.value.baseBuffer;
  v11.value.baseBuffer[0] = 0;
  v11.type.allocedAndFlag = 20;
  v11.value.allocedAndFlag = 20;
  len = name->len;
  idStr::EnsureAlloced(this: &v11.name, amount: name->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v11.name.data, Src: name->data, Size: len);
  v11.name.data[len] = 0;
  v11.name.len = len;
  v9 = type->len;
  idStr::EnsureAlloced(this: &v11.type, amount: type->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v11.type.data, Src: type->data, Size: v9);
  v11.type.data[v9] = 0;
  v11.type.len = v9;
  v10 = value->len;
  idStr::EnsureAlloced(this: &v11.value, amount: value->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v11.value.data, Src: value->data, Size: v10);
  v11.value.data[v10] = 0;
  v11.value.len = v10;
  idList<idPlaytestStorage::ai2FSMStateInfo_t,5>::Append(
    this: (idList<idPlaytestStorage::ai2FSMStateInfo_t,5> *)&this->testReportFields,
    obj: (const idIKArm *)&v11);
  keyBindings_t::~keyBindings_t(this: &v11);
  idStr::FreeData(this: name);
  idStr::FreeData(this: type);
  idStr::FreeData(this: value);
}


// ========================================================================
// __unwind$223151
// EA  : 0x829ED8BC
// RVA : 0x009ED8BC
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223151()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 240 + 284));
}


// ========================================================================
// __unwind$223152
// EA  : 0x829ED8E4
// RVA : 0x009ED8E4
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223152()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 240 + 276));
}


// ========================================================================
// __unwind$223153_0
// EA  : 0x829ED90C
// RVA : 0x009ED90C
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223153_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 240 + 268));
}


// ========================================================================
// __unwind$223154_0
// EA  : 0x829ED934
// RVA : 0x009ED934
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223154_0()
{
  int v0; // r12

  keyBindings_t::~keyBindings_t(this: (testReportField_t *)(v0 - 240 + 80));
}


// ========================================================================
// ?WriteReport@idTestReport@@UAAXXZ
// EA  : 0x829ED9C8
// RVA : 0x009ED9C8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void __fastcall idTestReport::WriteReport(idTestReport *this)
{
  __int64 v2; // r8
  __int64 v3; // r6
  int v4; // r4
  __int64 v5; // r10
  int v6; // r26
  int v7; // r28
  int v8; // r29
  encounterGroupRole_t *list; // r16
  int v10; // r10
  int v11; // r11
  int v12; // r27
  int v13; // r28
  int v14; // r29
  idXMLWriter *xmlWriter; // r3
  idFile *xmlFile; // r11
  char v17; // r28
  idXMLWriter *v18; // r3
  idXMLAttribute *v19; // r3
  int v20; // r28
  int v21; // r29
  char *data; // r22
  char *v23; // r22
  testReportField_t *v24; // r27
  int size; // r29
  testReportField_t *v26; // r28
  int v27; // r27
  int v28; // r28
  int v29; // r29
  idList<idXMLAttribute,44> v30; // [sp+50h] [-160h] BYREF
  idList<enum encounterGroupRole_t,5> v31; // [sp+60h] [-150h] BYREF
  idStr v32; // [sp+70h] [-140h] BYREF
  idXMLWriter *v33; // [sp+90h] [-120h]
  idXMLAttribute v34; // [sp+A0h] [-110h] BYREF
  idXMLAttribute v35[3]; // [sp+E0h] [-D0h] BYREF

  memset(&v31, 0, 14);
  *(_WORD *)&v31.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
  LODWORD(v5) = this->childResults.num;
  v6 = 0;
  if ( (int)v5 > 0 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: &v31,
        obj: (const encounterGroupRole_t *)&this->childResults.list[v7]);
      if ( idStr::Find(
             searchIn: this->infos.list[v8].data,
             searchFor: "NOREPORT",
             casesensitive: true,
             start: 0,
             end: this->infos.list[v8].len) != -1 )
      {
        idStr::Replace(this: &this->infos.list[v8], old: "NOREPORT", nw: &byte_8200D768);
        this->childResults.list[v7] = TEST_PASS;
      }
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < this->childResults.num );
  }
  idReport::StartReport(this, a2: v4, a3: v3, a4: v2, a5: v5);
  list = v31.list;
  v10 = 0;
  if ( this->childResults.num > 0 )
  {
    v11 = 0;
    do
    {
      ++v10;
      this->childResults.list[v11] = list[v11];
      ++v11;
    }
    while ( v10 < this->childResults.num );
  }
  this->html->Printf(this: this->html, a2: "      <TR>\n");
  this->html->Printf(this: this->html, a2: "        <TD align='center' width='100'> STATUS      </TD>\n");
  this->html->Printf(this: this->html, a2: "        <TD align='center' width='100'> TYPE        </TD>\n");
  this->html->Printf(this: this->html, a2: "        <TD align='center' width='600'> INFORMATION </TD>\n");
  this->html->Printf(this: this->html, a2: "      </TR>\n");
  v12 = 0;
  if ( this->childResults.num > 0 )
  {
    v13 = 0;
    v14 = 0;
    do
    {
      this->html->Printf(this: this->html, a2: "      <TR bgcolor='%s'>\n", textColors[this->childResults.list[v14]]);
      this->html->Printf(
        this: this->html,
        a2: "        <TD><B> %s </B></TD>\n",
        textResult[this->childResults.list[v14]]);
      this->html->Printf(this: this->html, a2: "        <TD><B> %s </B></TD>\n", this->types.list[v13].data);
      this->html->Printf(this: this->html, a2: "        <TD>    %s </TD>\n", this->infos.list[v13].data);
      this->html->Printf(this: this->html, a2: "      </TR>\n");
      ++v12;
      ++v14;
      ++v13;
    }
    while ( v12 < this->childResults.num );
  }
  xmlWriter = this->xmlWriter;
  if ( xmlWriter != nullptr )
  {
    xmlFile = xmlWriter->xmlFile;
    v33 = this->xmlWriter;
    if ( xmlFile != nullptr )
    {
      idXMLWriter::OpenElement(this: xmlWriter, name: "RegressionTest");
      idXMLWriter::WriteElement(this: this->xmlWriter, name: "TestName", value: this->reportPath.data);
      idXMLWriter::WriteElement(this: this->xmlWriter, name: "TestResult", value: textResult[this->finalResult]);
      v17 = 0;
      if ( this->finalResult == TEST_FAIL )
      {
        v32.len = 0;
        v32.baseBuffer[0] = 0;
        v32.allocedAndFlag = 20;
        v32.data = v32.baseBuffer;
        idStr::Format(this: &v32, fmt: "regression/reports/%s/screenshot_error.jpg", this->reportPath.data);
        if ( fileSystem->FileExists(this: fileSystem, a2: v32.data, a3: false) )
        {
          idXMLWriter::WriteElement(this: this->xmlWriter, name: "ScreenShot", value: v32.data);
          v17 = 1;
        }
        idStr::FreeData(this: &v32);
      }
      if ( v17 == 0 )
        idXMLWriter::WriteElement(this: this->xmlWriter, name: "ScreenShot", value: &byte_8200D768);
      v18 = this->xmlWriter;
      if ( this->testReportFields.num != 0 )
      {
        idXMLWriter::OpenElement(this: v18, name: "TestFields");
        v19 = nullptr;
        *(_WORD *)&v30.memTag = 1280;
        memset(&v30, 0, 14);
        v20 = 0;
        if ( this->testReportFields.num > 0 )
        {
          v21 = 0;
          while ( 1 )
          {
            if ( v30.listStatic == 0 || v30.listStatic == 2 )
            {
              if ( v19 != nullptr )
                idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &v19->name, num: v30.size);
              v30.list = nullptr;
              v30.size = 0;
            }
            v30.num = 0;
            data = this->testReportFields.list[v21].name.data;
            idStr::idStr(this: &v35[0].name, text: "name");
            idStr::idStr(this: &v35[0].value, text: data);
            idStr::StripLeadingWhiteSpace(this: &v35[0].name);
            idStr::StripTrailingWhitespace(this: &v35[0].name);
            idList<idXMLAttribute,44>::Append(this: &v30, obj: v35);
            v23 = this->testReportFields.list[v21].type.data;
            idStr::idStr(this: &v34.name, text: "type");
            idStr::idStr(this: &v34.value, text: v23);
            idStr::StripLeadingWhiteSpace(this: &v34.name);
            idStr::StripTrailingWhitespace(this: &v34.name);
            idList<idXMLAttribute,44>::Append(this: &v30, obj: &v34);
            idXMLWriter::WriteElement(
              this: this->xmlWriter,
              name: "TestField",
              value: this->testReportFields.list[v21].value.data,
              attributes: &v30);
            idStr::FreeData(this: &v34.value);
            idStr::FreeData(this: &v34.name);
            idStr::FreeData(this: &v35[0].value);
            idStr::FreeData(this: &v35[0].name);
            ++v20;
            ++v21;
            if ( v20 >= this->testReportFields.num )
              break;
            v19 = v30.list;
          }
        }
        idXMLWriter::CloseElement(this: this->xmlWriter);
        if ( this->testReportFields.listStatic == 0 || this->testReportFields.listStatic == 2 )
        {
          v24 = this->testReportFields.list;
          if ( v24 != nullptr )
          {
            size = this->testReportFields.size;
            if ( size > 0 )
            {
              v26 = this->testReportFields.list;
              do
              {
                keyBindings_t::~keyBindings_t(this: v26);
                --size;
                ++v26;
              }
              while ( size != 0 );
            }
            idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
          }
          this->testReportFields.list = nullptr;
          this->testReportFields.size = 0;
        }
        this->testReportFields.num = 0;
        if ( v30.listStatic == 0 || v30.listStatic == 2 )
        {
          if ( v30.list != nullptr )
            idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &v30.list->name, num: v30.size);
          v30.list = nullptr;
          v30.size = 0;
        }
        v30.num = 0;
      }
      else
      {
        idXMLWriter::WriteElement(this: v18, name: "TestFields", value: &byte_8200D768);
      }
      idXMLWriter::OpenElement(this: this->xmlWriter, name: "TestActions");
      v27 = 0;
      if ( this->childResults.num > 0 )
      {
        v28 = 0;
        v29 = 0;
        do
        {
          idXMLWriter::OpenElement(this: this->xmlWriter, name: "TestAction");
          idXMLWriter::WriteElement(this: this->xmlWriter, name: "TestType", value: this->types.list[v29].data);
          idXMLWriter::WriteElement(
            this: this->xmlWriter,
            name: "TestResult",
            value: textResult[this->childResults.list[v28]]);
          idXMLWriter::CloseElement(this: this->xmlWriter);
          ++v27;
          ++v29;
          ++v28;
        }
        while ( v27 < this->childResults.num );
      }
      idXMLWriter::CloseElement(this: this->xmlWriter);
      idXMLWriter::CloseElement(this: this->xmlWriter);
    }
  }
  idReport::FinishReport(this);
  if ( (v31.listStatic == 0 || v31.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$223339_0
// EA  : 0x829EE078
// RVA : 0x009EE078
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223339_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$223340
// EA  : 0x829EE0A0
// RVA : 0x009EE0A0
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223340()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 112));
}


// ========================================================================
// __unwind$223341
// EA  : 0x829EE0C8
// RVA : 0x009EE0C8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223341()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$223485
// EA  : 0x829EE0F0
// RVA : 0x009EE0F0
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$223486
// EA  : 0x829EE118
// RVA : 0x009EE118
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 256));
}


// ========================================================================
// __unwind$223342
// EA  : 0x829EE144
// RVA : 0x009EE144
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223342()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$223498_0
// EA  : 0x829EE16C
// RVA : 0x009EE16C
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223498_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$223499_0
// EA  : 0x829EE194
// RVA : 0x009EE194
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223499_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 192));
}


// ========================================================================
// __unwind$223343
// EA  : 0x829EE1C0
// RVA : 0x009EE1C0
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223343()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$223513_0
// EA  : 0x829EE1E8
// RVA : 0x009EE1E8
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223513_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$223528_0
// EA  : 0x829EE210
// RVA : 0x009EE210
// PDB : w:\tech5\engine\test\report.cpp
// ========================================================================

void _unwind_223528_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 224));
}

