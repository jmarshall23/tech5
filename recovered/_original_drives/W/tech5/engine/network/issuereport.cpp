
// ========================================================================
// ?Format@idReportData@@QAAXXZ
// EA  : 0x82898570
// RVA : 0x00898570
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void __fastcall idReportData::Format(idReportData *this)
{
  idStr *p_steps; // r30
  idReportData *v2; // r31

  p_steps = &this->steps;
  v2 = this;
  idStr::StripLeadingWhiteSpace(this: &this->steps);
  idStr::StripTrailingWhitespace(this: p_steps);
  idStr::StripLeadingWhiteSpace(this: &v2->title);
  idStr::StripTrailingWhitespace(this: &v2->title);
  v2 = (idReportData *)((char *)v2 + 312);
  idStr::StripLeadingWhiteSpace(this: &v2->userName);
  idStr::StripTrailingWhitespace(this: &v2->userName);
}


// ========================================================================
// ?ReportToHansoft@idIssueReport@@SA_NXZ
// EA  : 0x828985E0
// RVA : 0x008985E0
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

BOOL __fastcall idIssueReport::ReportToHansoft()
{
  return common->IsMultiplayer(this: common);
}


// ========================================================================
// ?Init@idReportData@@QAAXXZ
// EA  : 0x82898620
// RVA : 0x00898620
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void __fastcall idReportData::Init(idReportData *this, int a2, int a3, int a4, __int64 a5)
{
  const char *v5; // r4
  const char *v6; // r10
  const char *v8; // r11
  int v9; // r9
  int v10; // r9
  bool v11; // zf
  const char *v12; // r11
  const char *v13; // r10
  int v14; // r9
  int v15; // r9
  const char *v16; // r10
  const char *v17; // r11
  int v18; // r9
  int v19; // r9
  const char *v20; // r11
  const char *v21; // r10
  int v22; // r9
  int v23; // r9
  const char *v24; // r11
  const char *v25; // r10
  int v26; // r9
  int v27; // r9
  const char *v28; // r11
  __int64 v29; // r10
  va *v30; // r3
  const char *v31; // r3
  const char *v32; // r3
  const char *CommandLineA; // r3
  int v34; // [sp+8h] [-1068h]
  int v35; // [sp+Ch] [-1064h]
  int v36; // [sp+10h] [-1060h]
  int v37; // [sp+14h] [-105Ch]
  int v38; // [sp+18h] [-1058h]
  int v39; // [sp+1Ch] [-1054h]
  va v40; // [sp+50h] [-1020h] BYREF

  v5 = "xbox360";
  v6 = "win-x86";
  v8 = "xbox360";
  do
  {
    v9 = *(unsigned __int8 *)v8;
    v11 = v9 == 0;
    v10 = v9 - *(unsigned __int8 *)v6;
    if ( v11 )
      break;
    ++v8;
    ++v6;
  }
  while ( v10 == 0 );
  if ( v10 == 0 )
  {
    v5 = "win32";
LABEL_29:
    idStr::operator=(this: &this->platform, text: v5);
    goto LABEL_30;
  }
  v12 = "xbox360";
  v13 = "win-x64";
  do
  {
    v14 = *(unsigned __int8 *)v12;
    v11 = v14 == 0;
    v15 = v14 - *(unsigned __int8 *)v13;
    if ( v11 )
      break;
    ++v12;
    ++v13;
  }
  while ( v15 == 0 );
  if ( v15 == 0 )
  {
    v5 = "x64";
    goto LABEL_29;
  }
  v16 = "xbox360";
  v17 = "xbox360";
  do
  {
    v18 = *(unsigned __int8 *)v17;
    v11 = v18 == 0;
    v19 = v18 - *(unsigned __int8 *)v16;
    if ( v11 )
      break;
    ++v17;
    ++v16;
  }
  while ( v19 == 0 );
  if ( v19 == 0 )
    goto LABEL_29;
  v20 = "xbox360";
  v21 = "playstation3";
  do
  {
    v22 = *(unsigned __int8 *)v20;
    v11 = v22 == 0;
    v23 = v22 - *(unsigned __int8 *)v21;
    if ( v11 )
      break;
    ++v20;
    ++v21;
  }
  while ( v23 == 0 );
  if ( v23 == 0 )
  {
    v5 = "ps3";
    goto LABEL_29;
  }
  v24 = "xbox360";
  v25 = "MacOSX";
  do
  {
    v26 = *(unsigned __int8 *)v24;
    v11 = v26 == 0;
    v27 = v26 - *(unsigned __int8 *)v25;
    if ( v11 )
      break;
    ++v24;
    ++v25;
  }
  while ( v27 == 0 );
  if ( v27 == 0 )
  {
    v5 = "osx";
    goto LABEL_29;
  }
  v28 = "xbox360";
  v5 = "linux";
  LODWORD(v29) = "linux";
  do
  {
    HIDWORD(v29) = *(unsigned __int8 *)v28;
    LODWORD(a5) = *(unsigned __int8 *)v29;
    v11 = HIDWORD(v29) == 0;
    HIDWORD(v29) -= a5;
    if ( v11 )
      break;
    ++v28;
    LODWORD(v29) = v29 + 1;
  }
  while ( HIDWORD(v29) == 0 );
  if ( HIDWORD(v29) == 0 )
    goto LABEL_29;
LABEL_30:
  v30 = va::va(
          this: &v40,
          fmt: "1.%d.%d",
          a3: 0x69300000B88LL,
          a4: a5,
          a5: v29,
          a6: v34,
          a7: v35,
          a8: v36,
          a9: v37,
          a10: v38,
          a11: v39);
  idCVar::SetString(this: &com_version, newValue: v30->buffer, force: true);
  this->buildNumberMajor = 1683;
  this->buildNumberMinor = 2952;
  idStr::operator=(this: &this->buildMessage, text: &byte_8200D768);
  v31 = sys->GetOSUserName(this: sys);
  idStr::operator=(this: &this->userName, text: v31);
  if ( idStr::Cmp(s1: this->userName.data, s2: &byte_8200D768) == 0
    || idStr::Cmp(s1: this->userName.data, s2: "User") == 0 )
  {
    v32 = sys->GetMachineName(this: sys);
    idStr::operator=(this: &this->userName, text: v32);
    if ( idStr::Cmp(s1: this->userName.data, s2: &byte_8200D768) == 0 )
      idStr::operator=(this: &this->userName, text: report_userName.valueString.data);
  }
  idStr::operator=(this: &this->cpuID, text: "Generic");
  this->coreNum = 0;
  this->logicalNum = 0;
  this->packageNum = 0;
  this->cpuFrequency = 0.0;
  idStr::operator=(this: &this->launchCommand, text: &byte_8200D768);
  idStr::operator=(this: &this->vtFilePathCvar, text: vt_filePath.valueString.data);
  idStr::operator=(this: &this->vtFilePathVmtrOverrideCvar, text: vt_filePathVmtrOverride.valueString.data);
  CommandLineA = GetCommandLineA();
  idStr::operator=(this: &this->launchCommand, text: CommandLineA);
}


// ========================================================================
// ?GetSeverity@idReportData@@SA?AVidStr@@H@Z
// EA  : 0x82898928
// RVA : 0x00898928
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

idStr *__fastcall idReportData::GetSeverity(idStr *result, unsigned int index)
{
  if ( index >= 6 )
    index = 0;
  idStr::idStr(this: result, text: idReportData::trackerSeverity[index]);
  return result;
}


// ========================================================================
// ?GetDevGroup@idReportData@@SA?AVidStr@@H@Z
// EA  : 0x82898988
// RVA : 0x00898988
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

idStr *__fastcall idReportData::GetDevGroup(idStr *result, unsigned int index)
{
  if ( index > 4 )
    index = 0;
  idStr::idStr(this: result, text: idReportData::trackerDevGroup[index]);
  return result;
}


// ========================================================================
// ?GetReproduced@idReportData@@SA?AVidStr@@H@Z
// EA  : 0x828989E8
// RVA : 0x008989E8
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

idStr *__fastcall idReportData::GetReproduced(idStr *result, unsigned int index, int a3, int a4, int a5)
{
  unsigned int v6; // r31

  v6 = index;
  if ( ((unsigned __int8 (__fastcall *)(idCommon *, unsigned int, int, int, int, bool (__fastcall *)(idCommon *), idCommon_vtbl *, _DWORD))common->IsMultiplayer)(
         a1: common,
         a2: index,
         a3,
         a4,
         a5,
         a6: common->IsMultiplayer,
         a7: common->__vftable,
         a8: 0) != 0 )
  {
    idReportData::GetDevGroup(result, index: v6);
  }
  else
  {
    if ( v6 >= 6 )
      v6 = 0;
    idStr::idStr(this: result, text: idReportData::trackerReproduced[v6]);
  }
  return result;
}


// ========================================================================
// ?SetDefaults@idReportData@@QAAXXZ
// EA  : 0x82898A90
// RVA : 0x00898A90
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void __fastcall idReportData::SetDefaults(idReportData *this)
{
  idGame *v2; // r3
  idGame *v3; // r3
  const char *v4; // r4
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  va *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  va *v16; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  va *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  __int64 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  va *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r6
  __int64 v31; // r8
  va *v32; // r3
  __int64 v33; // r10
  __int64 v34; // r6
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r8
  __int64 v38; // r6
  __int64 v39; // r10
  va *v40; // r3
  __int64 v41; // r8
  __int64 v42; // r6
  __int64 v43; // r10
  va *v44; // r3
  idStr *v45; // r3
  const idStr *v46; // r3
  idStr *v47; // r3
  idStr *v48; // r26
  size_t len; // r29
  int v50; // [sp+8h] [-1388h]
  int v51; // [sp+8h] [-1388h]
  int v52; // [sp+8h] [-1388h]
  int v53; // [sp+8h] [-1388h]
  int v54; // [sp+8h] [-1388h]
  int v55; // [sp+8h] [-1388h]
  int v56; // [sp+8h] [-1388h]
  int v57; // [sp+8h] [-1388h]
  int v58; // [sp+8h] [-1388h]
  int v59; // [sp+8h] [-1388h]
  int v60; // [sp+Ch] [-1384h]
  int v61; // [sp+Ch] [-1384h]
  int v62; // [sp+Ch] [-1384h]
  int v63; // [sp+Ch] [-1384h]
  int v64; // [sp+Ch] [-1384h]
  int v65; // [sp+Ch] [-1384h]
  int v66; // [sp+Ch] [-1384h]
  int v67; // [sp+Ch] [-1384h]
  int v68; // [sp+Ch] [-1384h]
  int v69; // [sp+Ch] [-1384h]
  int v70; // [sp+10h] [-1380h]
  int v71; // [sp+10h] [-1380h]
  int v72; // [sp+10h] [-1380h]
  int v73; // [sp+10h] [-1380h]
  int v74; // [sp+10h] [-1380h]
  int v75; // [sp+10h] [-1380h]
  int v76; // [sp+10h] [-1380h]
  int v77; // [sp+10h] [-1380h]
  int v78; // [sp+10h] [-1380h]
  int v79; // [sp+10h] [-1380h]
  int v80; // [sp+14h] [-137Ch]
  int v81; // [sp+14h] [-137Ch]
  int v82; // [sp+14h] [-137Ch]
  int v83; // [sp+14h] [-137Ch]
  int v84; // [sp+14h] [-137Ch]
  int v85; // [sp+14h] [-137Ch]
  int v86; // [sp+14h] [-137Ch]
  int v87; // [sp+14h] [-137Ch]
  int v88; // [sp+14h] [-137Ch]
  int v89; // [sp+14h] [-137Ch]
  int v90; // [sp+18h] [-1378h]
  int v91; // [sp+18h] [-1378h]
  int v92; // [sp+18h] [-1378h]
  int v93; // [sp+18h] [-1378h]
  int v94; // [sp+18h] [-1378h]
  int v95; // [sp+18h] [-1378h]
  int v96; // [sp+18h] [-1378h]
  int v97; // [sp+18h] [-1378h]
  int v98; // [sp+18h] [-1378h]
  int v99; // [sp+18h] [-1378h]
  int v100; // [sp+1Ch] [-1374h]
  int v101; // [sp+1Ch] [-1374h]
  int v102; // [sp+1Ch] [-1374h]
  int v103; // [sp+1Ch] [-1374h]
  int v104; // [sp+1Ch] [-1374h]
  int v105; // [sp+1Ch] [-1374h]
  int v106; // [sp+1Ch] [-1374h]
  int v107; // [sp+1Ch] [-1374h]
  int v108; // [sp+1Ch] [-1374h]
  int v109; // [sp+1Ch] [-1374h]
  idStr v110; // [sp+50h] [-1340h] BYREF
  idStr v111; // [sp+70h] [-1320h] BYREF
  idStr v112; // [sp+90h] [-1300h] BYREF
  idStr v113; // [sp+B0h] [-12E0h] BYREF
  idStr v114; // [sp+D0h] [-12C0h] BYREF
  idStr v115; // [sp+F0h] [-12A0h] BYREF
  idStr v116; // [sp+110h] [-1280h] BYREF
  idStr v117; // [sp+130h] [-1260h] BYREF
  _BYTE v118[512]; // [sp+150h] [-1240h] BYREF
  va v119; // [sp+350h] [-1040h] BYREF

  idStr::operator=(this: &this->title, text: &byte_8200D768);
  idStr::operator=(this: &this->steps, text: &byte_8200D768);
  idStr::operator=(this: &this->details, text: &byte_8200D768);
  idStr::operator=(this: &this->severity, text: &byte_8200D768);
  idStr::operator=(this: &this->component, text: &byte_8200D768);
  idStr::operator=(this: &this->reproduced, text: &byte_8200D768);
  idStr::operator=(this: &this->style, text: "unspecified");
  if ( common != nullptr && (v2 = common->Game(this: common)) != nullptr && *v2->GetMapName(this: v2) != 0 )
  {
    v3 = common->Game(this: common);
    v4 = v3->GetMapName(this: v3);
  }
  else
  {
    v4 = "None";
  }
  idStr::operator=(this: &this->mapPath, text: v4);
  idStr::StripFileExtension(this: &this->mapPath);
  idStr::operator=(this: &this->priority, text: &byte_8200D768);
  idStr::operator=(this: &this->systemInfo, text: &byte_8200D768);
  idStr::operator=(this: &this->localFilename, text: &byte_8200D768);
  idStr::operator=(this: &this->dmpPath, text: "Not saved");
  idStr::operator=(this: &this->callstack, text: &byte_8200D768);
  idStr::operator=(this: &this->exception, text: &byte_8200D768);
  idStr::operator=(this: &this->registers, text: &byte_8200D768);
  idStr::operator=(this: &this->attachFilename, text: &byte_8200D768);
  idStr::operator=(this: &this->fullFunctionDetails, text: &byte_8200D768);
  idStr::operator=(this: &this->someFunctionDetails, text: &byte_8200D768);
  idStr::idStr(this: &v113, text: &byte_8200D768);
  idStr::idStr(this: &v112, text: &byte_8200D768);
  idStr::idStr(this: &v111, text: &byte_8200D768);
  idStr::idStr(this: &v110, text: &byte_8200D768);
  memset(v118, 0, sizeof(v118));
  LODWORD(v5) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  v8 = va::va(
         this: &v119,
         fmt: "Build & Runtime Info        \r\n",
         a3: v7,
         a4: v6,
         a5: v5,
         a6: v50,
         a7: v60,
         a8: v70,
         a9: v80,
         a10: v90,
         a11: v100);
  idStr::Append(this: &v110, text: v8);
  HIDWORD(v9) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  v12 = va::va(
          this: &v119,
          fmt: "--------------------------- \r\n",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v51,
          a7: v61,
          a8: v71,
          a9: v81,
          a10: v91,
          a11: v101);
  idStr::Append(this: &v110, text: v12);
  LODWORD(v13) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v14) = this->userName.data;
  v16 = va::va(
          this: &v119,
          fmt: "User:             %s        \r\n",
          a3: v14,
          a4: v13,
          a5: v15,
          a6: v52,
          a7: v62,
          a8: v72,
          a9: v82,
          a10: v92,
          a11: v102);
  idStr::Append(this: &v110, text: v16);
  HIDWORD(v17) = &idDeclReachIK::resourceList.hashTable[243];
  LODWORD(v18) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v18) = com_version.valueString.data;
  v20 = va::va(
          this: &v119,
          fmt: "Version:          %s        \r\n",
          a3: v18,
          a4: v17,
          a5: v19,
          a6: v53,
          a7: v63,
          a8: v73,
          a9: v83,
          a10: v93,
          a11: v103);
  idStr::Append(this: &v110, text: v20);
  HIDWORD(v21) = v118;
  v24 = va::va(
          this: &v119,
          fmt: "File Path:        %s        \r\n",
          a3: v21,
          a4: v23,
          a5: v22,
          a6: v54,
          a7: v64,
          a8: v74,
          a9: v84,
          a10: v94,
          a11: v104);
  idStr::Append(this: &v110, text: v24);
  HIDWORD(v25) = v113.data;
  v28 = va::va(
          this: &v119,
          fmt: "System Time:      %s        \r\n",
          a3: v25,
          a4: v27,
          a5: v26,
          a6: v55,
          a7: v65,
          a8: v75,
          a9: v85,
          a10: v95,
          a11: v105);
  idStr::Append(this: &v110, text: v28);
  LODWORD(v29) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v30) = com_version.valueString.data;
  v32 = va::va(
          this: &v119,
          fmt: "Build String:     %s        \r\n",
          a3: v30,
          a4: v31,
          a5: v29,
          a6: v56,
          a7: v66,
          a8: v76,
          a9: v86,
          a10: v96,
          a11: v106);
  idStr::Append(this: &v110, text: v32);
  HIDWORD(v33) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v34) = this->vtFilePathCvar.data;
  v36 = va::va(
          this: &v119,
          fmt: "VT File Path:     %s        \r\n",
          a3: v34,
          a4: v35,
          a5: v33,
          a6: v57,
          a7: v67,
          a8: v77,
          a9: v87,
          a10: v97,
          a11: v107);
  idStr::Append(this: &v110, text: v36);
  LODWORD(v37) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v38) = this->vtFilePathVmtrOverrideCvar.data;
  v40 = va::va(
          this: &v119,
          fmt: "VMTR Override:    %s        \r\n",
          a3: v38,
          a4: v37,
          a5: v39,
          a6: v58,
          a7: v68,
          a8: v78,
          a9: v88,
          a10: v98,
          a11: v108);
  idStr::Append(this: &v110, text: v40);
  HIDWORD(v41) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v42) = this->launchCommand.data;
  v44 = va::va(
          this: &v119,
          fmt: "Launch Command:   %s        \r\n",
          a3: v42,
          a4: v41,
          a5: v43,
          a6: v59,
          a7: v69,
          a8: v79,
          a9: v89,
          a10: v99,
          a11: v109);
  idStr::Append(this: &v110, text: v44);
  idStr::Clear(this: &this->systemInfo);
  v45 = operator+(result: &v115, a: &v110, b: "\r\n");
  v46 = operator+(result: &v117, a: v45, b: &v112);
  v47 = operator+(result: &v116, a: v46, b: "\r\n");
  v48 = operator+(result: &v114, a: v47, b: &v111);
  len = v48->len;
  idStr::EnsureAlloced(this: &this->systemInfo, amount: v48->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->systemInfo.data, Src: v48->data, Size: len);
  this->systemInfo.data[len] = 0;
  this->systemInfo.len = len;
  idStr::FreeData(this: &v114);
  idStr::FreeData(this: &v116);
  idStr::FreeData(this: &v117);
  idStr::FreeData(this: &v115);
  idStr::FreeData(this: &v110);
  idStr::FreeData(this: &v111);
  idStr::FreeData(this: &v112);
  idStr::FreeData(this: &v113);
}


// ========================================================================
// __unwind$219766_0
// EA  : 0x82898E6C
// RVA : 0x00898E6C
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219766_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 176));
}


// ========================================================================
// __unwind$219767_0
// EA  : 0x82898E94
// RVA : 0x00898E94
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219767_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 144));
}


// ========================================================================
// __unwind$219768
// EA  : 0x82898EBC
// RVA : 0x00898EBC
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219768()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 112));
}


// ========================================================================
// __unwind$219769
// EA  : 0x82898EE4
// RVA : 0x00898EE4
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219769()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 80));
}


// ========================================================================
// __unwind$219770
// EA  : 0x82898F0C
// RVA : 0x00898F0C
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219770()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 240));
}


// ========================================================================
// __unwind$219771
// EA  : 0x82898F34
// RVA : 0x00898F34
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219771()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 304));
}


// ========================================================================
// __unwind$219772
// EA  : 0x82898F5C
// RVA : 0x00898F5C
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219772()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 272));
}


// ========================================================================
// __unwind$219773_0
// EA  : 0x82898F84
// RVA : 0x00898F84
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void _unwind_219773_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 208));
}


// ========================================================================
// `dynamic initializer for 'report_userName''
// EA  : 0x83345748
// RVA : 0x01345748
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__report_userName__()
{
  idCVar::idCVar(
    this: &report_userName,
    name: "report_userName",
    value: "Unknown",
    flags: 0,
    description: "User name to use for reports for any OS that does not provide one",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__report_userName__);
}


// ========================================================================
// `dynamic initializer for 'reportData''
// EA  : 0x833457A0
// RVA : 0x013457A0
// PDB : w:\tech5\engine\network\issuereport.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__reportData__()
{
  idReportData::idReportData(this: &reportData);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__reportData__);
}

