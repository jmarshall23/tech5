
// ========================================================================
// DebugPrintf
// EA  : 0x82E1D900
// RVA : 0x00E1D900
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void DebugPrintf(
        printLevel_t level,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  char v11[16]; // [sp+60h] [-1010h] BYREF
  __int64 v12; // [sp+1090h] [+20h] BYREF
  va_list va; // [sp+1090h] [+20h]
  __int64 v14; // [sp+1098h] [+28h]
  __int64 v15; // [sp+10A0h] [+30h]
  __int64 v16; // [sp+10A8h] [+38h]
  __int64 v17; // [sp+10B0h] [+40h]
  __int64 v18; // [sp+10B8h] [+48h]
  va_list va1; // [sp+10C0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v12 = *(__int64 *)((char *)&a3 + 4);
  v14 = a3;
  v15 = *(__int64 *)((char *)&a4 + 4);
  v16 = a4;
  v17 = *(__int64 *)((char *)&a5 + 4);
  v18 = a5;
  if ( level <= g_printLevel )
  {
    idStr::vsnPrintf(dest: v11, size: 4096, fmt, argptr: va);
    idLib::Printf(fmt: v11);
  }
}


// ========================================================================
// PrintExclusion
// EA  : 0x82E1D978
// RVA : 0x00E1D978
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void PrintExclusion(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  char v8[16]; // [sp+60h] [-1010h] BYREF
  __int64 v9; // [sp+1088h] [+18h] BYREF
  va_list va; // [sp+1088h] [+18h]
  __int64 v11; // [sp+1090h] [+20h]
  __int64 v12; // [sp+1098h] [+28h]
  __int64 v13; // [sp+10A0h] [+30h]
  __int64 v14; // [sp+10A8h] [+38h]
  __int64 v15; // [sp+10B0h] [+40h]
  __int64 v16; // [sp+10B8h] [+48h]
  va_list va1; // [sp+10C0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v9 = fmt;
  v11 = *(__int64 *)((char *)&a2 + 4);
  v12 = a2;
  v13 = *(__int64 *)((char *)&a3 + 4);
  v14 = a3;
  v15 = *(__int64 *)((char *)&a4 + 4);
  v16 = a4;
  if ( g_printExclusions )
  {
    idStr::vsnPrintf(dest: v8, size: 4096, fmt: (const char *)HIDWORD(fmt), argptr: va);
    idLib::Printf(fmt: v8);
  }
}


// ========================================================================
// ?DetermineType@idVoiceRecord@@QAAXXZ
// EA  : 0x82E1D9F0
// RVA : 0x00E1D9F0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::DetermineType(idVoiceRecord *this)
{
  voiceRecord_t v2; // r30
  const idVoiceRecord::vrInfo_t *v3; // r31

  v2 = VRT_START_JOBS;
  v3 = idVoiceRecord::info;
  do
  {
    if ( idStr::Icmp(s1: this->tokens[9].data, s2: v3->internalName) == 0 )
      this->type = v2;
    ++v3;
    ++v2;
  }
  while ( (int)v3 < (int)&idVoiceRecord::info[19] );
  if ( this->type == VRT_MAX )
    idLib::Warning(fmt: "Unknown type record '%s', mapped to %s", this->tokens[9].data, "Unknown");
}


// ========================================================================
// ?CleanVOStrings@idJobUtils@@AAAXAAVidLangDict@@@Z
// EA  : 0x82E1DA68
// RVA : 0x00E1DA68
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobUtils::CleanVOStrings(idJobUtils *this, idLangDict *strings)
{
  int i; // r30
  const idLangKeyValue *KeyVal; // r29
  const char **p_stringIDPrefix; // r31
  const char *v6; // r4
  int v7; // r5

  for ( i = 0; i < (int)idParser::GetFlags(this: (idClientGame *)strings); ++i )
  {
    KeyVal = idLangDict::GetKeyVal(this: strings, i);
    p_stringIDPrefix = &idVoiceRecord::info[0].stringIDPrefix;
    while ( 1 )
    {
      v6 = *p_stringIDPrefix;
      v7 = 0;
      if ( **p_stringIDPrefix != 0 )
      {
        do
          ++v7;
        while ( v6[v7] != 0 );
      }
      if ( idStr::Cmpn(s1: KeyVal->key, s2: v6, n: v7) == 0 )
        break;
      p_stringIDPrefix += 2;
      if ( (int)p_stringIDPrefix >= (int)&idVoiceRecord::info[19].stringIDPrefix )
        goto LABEL_9;
    }
    idLangDict::DeleteString(this: strings, idx: i--);
LABEL_9:
    ;
  }
}


// ========================================================================
// ?GetSoundShaderPrefix@@YA?AVidStr@@W4ju_Language_t@@@Z
// EA  : 0x82E1DE40
// RVA : 0x00E1DE40
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idStr *__fastcall GetSoundShaderPrefix(idStr *result, ju_Language_t language)
{
  const char *v3; // r4

  if ( language != JU_LANGUAGE_ENGLISH )
    v3 = "vo/unknown/";
  else
    v3 = "vo/english/";
  idStr::idStr(this: result, text: v3);
  return result;
}


// ========================================================================
// ?GetDescriptionResourceName@idVoiceRecord@@QBAXAAVidStr@@@Z
// EA  : 0x82E1DE98
// RVA : 0x00E1DE98
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::GetDescriptionResourceName(idVoiceRecord *this, idStr *voStringID)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: v4, text: this->tokens[10].data);
  idStr::StripFilename(this: v4);
  idStr::EnsureAlloced(this: v4, amount: v4[0].len + 2, keepold: true, geometricGrowth: true);
  v4[0].data[v4[0].len++] = 47;
  v4[0].data[v4[0].len] = 0;
  idStr::Append(this: v4, text: this->tokens[6].data);
  idStr::Append(this: voStringID, text: v4[0].data);
  idStr::FreeData(this: v4);
}


// ========================================================================
// __unwind$494867
// EA  : 0x82E1DF2C
// RVA : 0x00E1DF2C
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_494867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetSoundShaderName@idVoiceRecord@@QBA?AVidStr@@W4ju_Language_t@@@Z
// EA  : 0x82E1DF60
// RVA : 0x00E1DF60
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idVoiceRecord *__fastcall idVoiceRecord::GetSoundShaderName(idVoiceRecord *this, idStr *result, ju_Language_t language)
{
  const idStr *SoundShaderPrefix; // r3
  idStr *v6; // r27
  size_t len; // r29
  idStr v9; // [sp+60h] [-70h] BYREF
  idStr v10[2]; // [sp+80h] [-50h] BYREF

  idStr::idStr((idStr *)this, text: *(const char **)&result[22].baseBuffer[8]);
  SoundShaderPrefix = GetSoundShaderPrefix(result: v10, language);
  v6 = operator+(result: &v9, a: SoundShaderPrefix, b: (const idStr *)this);
  len = v6->len;
  idStr::EnsureAlloced((idStr *)this, amount: v6->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->tokens[0].data, Src: v6->data, Size: len);
  this->tokens[0].data[len] = 0;
  this->tokens[0].len = len;
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: v10);
  return this;
}


// ========================================================================
// __unwind$494905
// EA  : 0x82E1E004
// RVA : 0x00E1E004
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_494905()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 228));
  }
}


// ========================================================================
// __unwind$494908
// EA  : 0x82E1E048
// RVA : 0x00E1E048
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_494908()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$494909
// EA  : 0x82E1E070
// RVA : 0x00E1E070
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_494909()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?GetWaveFileName@idVoiceRecord@@QBAXAAVidStr@@@Z
// EA  : 0x82E1E098
// RVA : 0x00E1E098
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::GetWaveFileName(idVoiceRecord *this, idStr *waveFileName, int a3, int a4, __int64 a5)
{
  __int64 v5; // r6
  __int64 v6; // r10
  va *v8; // r3
  int v9; // [sp+8h] [-1058h]
  int v10; // [sp+Ch] [-1054h]
  int v11; // [sp+10h] [-1050h]
  int v12; // [sp+14h] [-104Ch]
  int v13; // [sp+18h] [-1048h]
  int v14; // [sp+1Ch] [-1044h]
  va v15; // [sp+50h] [-1010h] BYREF

  LODWORD(v5) = this->tokens[10].data;
  LODWORD(v6) = &off_82350000;
  HIDWORD(v6) = &sys_lang;
  HIDWORD(v5) = sys_lang.valueString.data;
  v8 = va::va(
         this: &v15,
         fmt: "sound/vo/%s/%s.wav",
         a3: v5,
         a4: a5,
         a5: v6,
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idStr::operator=(this: waveFileName, text: v8);
}


// ========================================================================
// ?GetVoiceOver@idVoiceRecord@@QBAPAVidDeclVoiceOver@@XZ
// EA  : 0x82E1E0F8
// RVA : 0x00E1E0F8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idDeclVoiceOver *__fastcall idVoiceRecord::GetVoiceOver(idVoiceRecord *this)
{
  const idDecl *v1; // r30
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  char *data; // r11
  const idDecl *v10; // r3
  idDecl *v11; // r3
  const char *v12; // r4
  int v14; // [sp+8h] [-10C8h]
  int v15; // [sp+8h] [-10C8h]
  int v16; // [sp+Ch] [-10C4h]
  int v17; // [sp+Ch] [-10C4h]
  int v18; // [sp+10h] [-10C0h]
  int v19; // [sp+10h] [-10C0h]
  int v20; // [sp+14h] [-10BCh]
  int v21; // [sp+14h] [-10BCh]
  int v22; // [sp+18h] [-10B8h]
  int v23; // [sp+18h] [-10B8h]
  int v24; // [sp+1Ch] [-10B4h]
  int v25; // [sp+1Ch] [-10B4h]
  idStr v26; // [sp+70h] [-1060h] BYREF
  idStr v27; // [sp+90h] [-1040h] BYREF
  va v28; // [sp+B0h] [-1020h] BYREF

  v1 = nullptr;
  v26.len = 0;
  v26.allocedAndFlag = 20;
  v26.data = v26.baseBuffer;
  v26.baseBuffer[0] = 0;
  idStr::operator=(this: &v26, text: this->tokens[10].data);
  LODWORD(v2) = v27.baseBuffer;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  HIDWORD(v2) = allocationCurrent[242];
  LODWORD(v3) = off_82010000;
  HIDWORD(v3) = &sys_lang;
  LODWORD(v4) = &byte_8200D768;
  HIDWORD(v4) = sys_lang.valueString.data;
  v5 = va::va(
         this: &v28,
         fmt: "decls/voiceover/%s%s.vo",
         a3: v4,
         a4: v3,
         a5: v2,
         a6: v14,
         a7: v16,
         a8: v18,
         a9: v20,
         a10: v22,
         a11: v24);
  idStr::operator=(this: &v27, text: v5);
  data = v26.data;
  if ( v26.data != nullptr )
  {
    v10 = idDeclInfo::FindWithInheritance(this: &idDeclVoiceOver::resourceList, name: v26.data, makeDefault: false);
    data = v26.data;
    v1 = v10;
  }
  if ( v1 != nullptr )
  {
    v12 = "Updating vo decl '%s' with track(s):\n";
  }
  else
  {
    v11 = declManager->CreateNewDecl(
            this: declManager,
            a2: &idDeclVoiceOver::resourceList,
            a3: data,
            a4: v27.data,
            a5: "{\n\ttracks {\n\t}\n}\n");
    LODWORD(v6) = &off_82350000;
    v1 = v11;
    v12 = "Created vo decl '%s'.\n";
  }
  HIDWORD(v8) = v1->name.str;
  DebugPrintf(
    level: PRINT_DEBUG,
    fmt: v12,
    a3: v8,
    a4: v7,
    a5: v6,
    a6: v15,
    a7: v17,
    a8: v19,
    a9: v21,
    a10: v23,
    a11: v25);
  idStr::FreeData(this: &v27);
  idStr::FreeData(this: &v26);
  return (idDeclVoiceOver *)v1;
}


// ========================================================================
// __unwind$495046
// EA  : 0x82E1E218
// RVA : 0x00E1E218
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495046()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 112));
}


// ========================================================================
// __unwind$495047
// EA  : 0x82E1E240
// RVA : 0x00E1E240
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495047()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 144));
}


// ========================================================================
// ?GetVoiceOverDescriptionStringID@idVoiceRecord@@QBAXAAVidStrId@@@Z
// EA  : 0x82E1E270
// RVA : 0x00E1E270
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::GetVoiceOverDescriptionStringID(idVoiceRecord *this, idStrId *voStringID)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: v4, text: idVoiceRecord::info[this->type].stringIDPrefix);
  idVoiceRecord::GetDescriptionResourceName(this, voStringID: v4);
  idStr::ReplaceChar(this: v4, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: v4, oldChar: 92, newChar: 95);
  idLangDict::AddKeyVal(this: &idLocalization::languageDict, key: v4[0].data, val: &byte_8200D768);
  idStrId::Set(this: voStringID, key: v4[0].data);
  idStr::FreeData(this: v4);
}


// ========================================================================
// __unwind$495233_0
// EA  : 0x82E1E308
// RVA : 0x00E1E308
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495233_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?CreateSoundShader@idVoiceRecord@@QBAPAVidSoundShader@@W4ju_Language_t@@@Z
// EA  : 0x82E1E338
// RVA : 0x00E1E338
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idSoundShader *__fastcall idVoiceRecord::CreateSoundShader(idVoiceRecord *this, ju_Language_t language)
{
  char *data; // r11
  char *v5; // r4
  idDecl *v6; // r28
  long double v7; // fp2
  double v8; // fp31
  double valueFloat; // fp0
  __int64 v10; // r11
  int v11; // r24
  __int64 v12; // r8
  int v13; // r6
  int v14; // r5
  int v15; // r8 OVERLAPPED
  __int128 v16; // r7 OVERLAPPED
  va *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  idVoiceRecord *SoundShaderName; // r3
  idVoiceRecord *v22; // r3
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r10
  idStr *p_whiteSpaceEnd_p; // r3
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  int v31; // [sp+8h] [-11E8h]
  int v32; // [sp+8h] [-11E8h]
  int v33; // [sp+Ch] [-11E4h]
  int v34; // [sp+Ch] [-11E4h]
  int v35; // [sp+10h] [-11E0h]
  int v36; // [sp+10h] [-11E0h]
  int v37; // [sp+14h] [-11DCh]
  int v38; // [sp+14h] [-11DCh]
  int v39; // [sp+18h] [-11D8h]
  int v40; // [sp+18h] [-11D8h]
  int v41; // [sp+1Ch] [-11D4h]
  int v42; // [sp+1Ch] [-11D4h]
  int v43; // [sp+74h] [-117Ch]
  idStr v44; // [sp+80h] [-1170h] BYREF
  idStr v45; // [sp+A0h] [-1150h] BYREF
  int v47; // [sp+C4h] [-112Ch]
  idStr v48; // [sp+D0h] [-1120h] BYREF
  idStr v49; // [sp+F0h] [-1100h] BYREF
  idVoiceRecord v50[3]; // [sp+110h] [-10E0h] BYREF

  data = this->tokens[10].data;
  if ( data == nullptr || *data == 0 )
    return nullptr;
  v5 = idVoiceRecord::GetSoundShaderName(this: (idVoiceRecord *)&v50[0].tokens[0].type, result: (idStr *)this, language)->tokens[0].data;
  if ( v5 != nullptr )
    v6 = (idDecl *)idDeclInfo::FindWithInheritance(this: &idSoundShader::resourceList, name: v5, makeDefault: false);
  else
    v6 = nullptr;
  idStr::FreeData(this: (idStr *)&v50[0].tokens[0].type);
  if ( this->tokens[12].len != 0 )
    v7 = atof(nptr: this->tokens[12].data);
  else
    *(double *)&v7 = jobUtil_defaultVolume.valueFloat;
  v8 = (float)*(double *)&v7;
  if ( this->tokens[13].len != 0 )
  {
    LODWORD(v10) = atol(nptr: this->tokens[13].data);
    valueFloat = (float)v10;
  }
  else
  {
    valueFloat = jobUtil_minDist.valueFloat;
  }
  v11 = (int)valueFloat;
  if ( this->tokens[14].len != 0 )
    atol(nptr: this->tokens[14].data);
  if ( jobUtil_usedefaultValues.valueInteger == 0 && v6 != nullptr )
  {
    v43 = (int)*(float *)&v6[1].name.str;
    v47 = (int)*(float *)&v6[1].nextOnHashChain;
    v11 = v43;
    v8 = *(float *)&v6[1].programaticallyDefined;
  }
  v48.len = 0;
  v48.baseBuffer[0] = 0;
  v48.allocedAndFlag = 20;
  v48.data = v48.baseBuffer;
  if ( idStr::Icmp(s1: this->tokens[15].data, s2: "X") == 0 )
    idStr::operator=(this: &v48, text: "SSF_GLOBAL");
  v45.allocedAndFlag = 20;
  v45.len = 0;
  v45.data = v45.baseBuffer;
  v45.baseBuffer[0] = 0;
  idVoiceRecord::GetWaveFileName(this, waveFileName: &v45, a3: v14, a4: v13, a5: v12);
  v15 = LODWORD(v8);
  DWORD1(v16) = v11;
  *((double *)&v16 + 1) = v8;
  v17 = va::va(
          this: (va *)&v50[0].tokens[1].floatvalue,
          fmt: "{\n"
          "\tedit = {\n"
          "\t\tparms = {\n"
          "\t\t\tminDistance = %d;\n"
          "\t\t\tmaxDistance = %d;\n"
          "\t\t\tgroups = \"SSG_VO\";\n"
          "\t\t\tvolume = {\n"
          "\t\t\t\tmin = %.2f;\n"
          "\t\t\t\tmax = %.2f;\n"
          "\t\t\t\tgranularity = 0.00;\n"
          "\t\t\t}\n"
          "\t\t\tsoundShaderFlags = \"%s\";\n"
          "\t\t\tfalloff = \"sound/falloffs/vo\";\n"
          "\t\t}\n"
          "\t\tsoundFiles = {\n"
          "\t\t\tnum = 1;\n"
          "\t\t\titem[0] = \"%s\";\n"
          "\t\t}\n"
          "\t}\n"
          "}\n",
          a3: *(__int64 *)((char *)&v16 + 4),
          a4: *(__int64 *)&v15,
          a5: __SPAIR64__((unsigned int)v48.data, (unsigned int)v45.data),
          a6: v31,
          a7: v33,
          a8: v35,
          a9: v37,
          a10: v39,
          a11: v41,
          v8,
          v8);
  idStr::idStr(this: &v49, text: v17);
  if ( v6 != nullptr )
  {
    idDecl::SetText(this: v6, text: v49.data, length: 0);
    HIDWORD(v27) = idVoiceRecord::GetSoundShaderName(
                     this: (idVoiceRecord *)&v50[0].tokens[0].whiteSpaceEnd_p,
                     result: (idStr *)this,
                     language)->tokens[0].data;
    DebugPrintf(
      level: PRINT_DEBUG,
      fmt: "Updated sound shader '%s'...\n",
      a3: v27,
      a4: v29,
      a5: v28,
      a6: v32,
      a7: v34,
      a8: v36,
      a9: v38,
      a10: v40,
      a11: v42);
    p_whiteSpaceEnd_p = (idStr *)&v50[0].tokens[0].whiteSpaceEnd_p;
  }
  else
  {
    v44.allocedAndFlag = 20;
    v44.len = 0;
    v44.data = v44.baseBuffer;
    v44.baseBuffer[0] = 0;
    idStr::operator=(this: &v44, text: "decls/sound/vo.sndshd");
    if ( idStr::Icmp(s1: this->tokens[7].data, s2: "X") != 0 )
    {
      PrintExclusion(
        fmt: __SPAIR64__("^3Skipping sound shader '%s' due to input exclusion.\n", (unsigned int)v44.data),
        a2: v20,
        a3: v19,
        a4: v18,
        a5: v32,
        a6: v34,
        a7: v36,
        a8: v38);
    }
    else
    {
      SoundShaderName = idVoiceRecord::GetSoundShaderName(
                          this: (idVoiceRecord *)&v50[0].tokens[1].baseBuffer[12],
                          result: (idStr *)this,
                          language);
      v6 = declManager->CreateNewDecl(
             this: declManager,
             a2: &idSoundShader::resourceList,
             a3: SoundShaderName->tokens[0].data,
             a4: v44.data,
             a5: v49.data);
      idStr::FreeData(this: (idStr *)&v50[0].tokens[1].baseBuffer[12]);
      v22 = idVoiceRecord::GetSoundShaderName(this: v50, result: (idStr *)this, language);
      LODWORD(v23) = &off_82350000;
      HIDWORD(v24) = v22->tokens[0].data;
      DebugPrintf(
        level: PRINT_DEBUG,
        fmt: "Created sound shader '%s'...\n",
        a3: v24,
        a4: v23,
        a5: v25,
        a6: v32,
        a7: v34,
        a8: v36,
        a9: v38,
        a10: v40,
        a11: v42);
      idStr::FreeData(this: (idStr *)v50);
    }
    p_whiteSpaceEnd_p = &v44;
  }
  idStr::FreeData(this: p_whiteSpaceEnd_p);
  if ( v6 != nullptr )
  {
    idDecl::ReplaceSourceFileText(this: v6, useSourceControl: true);
    idDecl::ReParse(this: v6, fromDisk: true);
  }
  idStr::FreeData(this: &v49);
  idStr::FreeData(this: &v45);
  idStr::FreeData(this: &v48);
  return (idSoundShader *)v6;
}


// ========================================================================
// __unwind$495287
// EA  : 0x82E1E6A8
// RVA : 0x00E1E6A8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495287()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 304));
}


// ========================================================================
// __unwind$495288
// EA  : 0x82E1E6D0
// RVA : 0x00E1E6D0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495288()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 208));
}


// ========================================================================
// __unwind$495289
// EA  : 0x82E1E6F8
// RVA : 0x00E1E6F8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495289()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 160));
}


// ========================================================================
// __unwind$495290
// EA  : 0x82E1E720
// RVA : 0x00E1E720
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495290()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 240));
}


// ========================================================================
// __unwind$495291
// EA  : 0x82E1E748
// RVA : 0x00E1E748
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495291()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 128));
}


// ========================================================================
// __unwind$495292
// EA  : 0x82E1E770
// RVA : 0x00E1E770
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 368));
}


// ========================================================================
// __unwind$495293
// EA  : 0x82E1E798
// RVA : 0x00E1E798
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495293()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 272));
}


// ========================================================================
// __unwind$495294
// EA  : 0x82E1E7C0
// RVA : 0x00E1E7C0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495294()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 336));
}


// ========================================================================
// ?Parse@idVoiceRecord@@QAAXAAVidParser@@ABVidToken@@@Z
// EA  : 0x82E1E7F0
// RVA : 0x00E1E7F0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::Parse(idVoiceRecord *this, idParser *src, const idToken *indexToken)
{
  idToken *v5; // r29
  int i; // r30
  idToken v7; // [sp+50h] [-80h] BYREF

  idToken::operator=(this: this->tokens, __that: indexToken);
  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.floatvalue = -3.4028235e38;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v7);
  v5 = &this->tokens[1];
  for ( i = 15; i != 0; --i )
  {
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: v5);
    idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v7);
    ++v5;
  }
  idVoiceRecord::DetermineType(this);
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$495635
// EA  : 0x82E1E8B0
// RVA : 0x00E1E8B0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495635()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ListVoiceTracks@idVORecord@@QBAXXZ
// EA  : 0x82E1E8D8
// RVA : 0x00E1E8D8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVORecord::ListVoiceTracks(idVORecord *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idDeclVoiceOver *voDecl; // r11
  int v7; // r31
  int v8; // r30
  const idVoiceTrack *v9; // r11
  int v10; // [sp+8h] [-88h]
  int v11; // [sp+Ch] [-84h]
  int v12; // [sp+10h] [-80h]
  int v13; // [sp+14h] [-7Ch]
  int v14; // [sp+18h] [-78h]
  int v15; // [sp+1Ch] [-74h]

  voDecl = this->voDecl;
  if ( this->voDecl != nullptr )
  {
    v7 = 0;
    if ( voDecl->tracks.num > 0 )
    {
      LODWORD(a5) = &off_82350000;
      v8 = 0;
      do
      {
        if ( v7 < 0 || (LODWORD(a5) = voDecl->tracks.num, v7 >= (int)a5) )
          v9 = nullptr;
        else
          v9 = voDecl->tracks.list[v8];
        HIDWORD(a3) = v9->name.str;
        DebugPrintf(
          level: PRINT_DEBUG,
          fmt: "  '%s'\n",
          a3,
          a4,
          a5,
          a6: v10,
          a7: v11,
          a8: v12,
          a9: v13,
          a10: v14,
          a11: v15);
        voDecl = this->voDecl;
        ++v7;
        ++v8;
        LODWORD(a5) = this->voDecl->tracks.num;
      }
      while ( v7 < (int)a5 );
    }
  }
}


// ========================================================================
// ?GenerateVisemes@idVORecord@@QAA_NABVidJobUtils@@ABVidVoiceRecord@@PAVidVoiceTrack@@PBD@Z
// EA  : 0x82E1E970
// RVA : 0x00E1E970
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

int __fastcall idVORecord::GenerateVisemes(
        idVORecord *this,
        const idJobUtils *ju,
        const idVoiceRecord *vrec,
        idVoiceTrack *vtrack,
        const char *text)
{
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  va *v11; // r3
  int v13; // [sp+8h] [-1118h]
  int v14; // [sp+Ch] [-1114h]
  int v15; // [sp+10h] [-1110h]
  int v16; // [sp+14h] [-110Ch]
  int v17; // [sp+18h] [-1108h]
  int v18; // [sp+1Ch] [-1104h]
  idStr v19; // [sp+50h] [-10D0h] BYREF
  idStr v20; // [sp+70h] [-10B0h] BYREF
  idStr v21; // [sp+90h] [-1090h] BYREF
  idPhonemeTrack_Annosoft v22; // [sp+B0h] [-1070h] BYREF
  idStr v23; // [sp+D0h] [-1050h] BYREF
  va v24; // [sp+F0h] [-1030h] BYREF

  idStr::idStr(this: &v23, text: vrec->tokens[10].data);
  LODWORD(v8) = vrec->tokens[10].data;
  LODWORD(v9) = &off_82350000;
  HIDWORD(v8) = sys_lang.valueString.data;
  v11 = va::va(
          this: &v24,
          fmt: "sound/vo/%s/%s.wav",
          a3: v8,
          a4: v10,
          a5: v9,
          a6: v13,
          a7: v14,
          a8: v15,
          a9: v16,
          a10: v17,
          a11: v18);
  idStr::operator=(this: &v23, text: v11);
  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  v21.allocedAndFlag = 20;
  v21.data = v21.baseBuffer;
  v21.len = 0;
  v21.baseBuffer[0] = 0;
  v20.allocedAndFlag = 20;
  v20.data = v20.baseBuffer;
  v20.len = 0;
  v20.baseBuffer[0] = 0;
  if ( Lipsync_WriteTextAndExecTool(
         languageName: sys_lang.valueString.data,
         lipsyncText: text,
         sampleName: v23.data,
         outTextFilePath: &v21,
         outAnnoFilePath: &v19,
         textless: false,
         errorMsg: &v20) != 0 )
  {
    idLib::Warning(fmt: v20.data);
    idStr::FreeData(this: &v20);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: &v23);
    return 0;
  }
  else
  {
    idPhonemeTrack_Annosoft::idPhonemeTrack_Annosoft(this: &v22);
    if ( (unsigned __int8)idPhonemeTrack_Annosoft::Load(
                            this: &v22,
                            declVisemeSet: vtrack->declVisemeSet,
                            fileName: v19.data) == 0 )
      idLib::Warning(fmt: "Failed load anno file '%s'", v19.data);
    if ( (unsigned __int8)idPhonemeTrack_Annosoft::GetVoiceTrack(this: &v22, out: vtrack, genFlags: 1) == 0 )
      idLib::Warning(fmt: "Error building voice track from phoneme track '%s'", v19.data);
    idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v22);
    idStr::FreeData(this: &v20);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: &v23);
    return 1;
  }
}


// ========================================================================
// __unwind$495743
// EA  : 0x82E1EAF8
// RVA : 0x00E1EAF8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495743()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 208));
}


// ========================================================================
// __unwind$495744
// EA  : 0x82E1EB20
// RVA : 0x00E1EB20
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495744()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 80));
}


// ========================================================================
// __unwind$495745
// EA  : 0x82E1EB48
// RVA : 0x00E1EB48
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495745()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 144));
}


// ========================================================================
// __unwind$495746
// EA  : 0x82E1EB70
// RVA : 0x00E1EB70
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495746()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 112));
}


// ========================================================================
// __unwind$495747
// EA  : 0x82E1EB98
// RVA : 0x00E1EB98
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_495747()
{
  int v0; // r12

  idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: (idPhonemeTrack_Annosoft *)(v0 - 4384 + 176));
}


// ========================================================================
// ?Parse@idJobTextRecord@@QAAXAAVidParser@@ABVidToken@@@Z
// EA  : 0x82E1ECE8
// RVA : 0x00E1ECE8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobTextRecord::Parse(idJobTextRecord *this, idParser *src, const idToken *indexToken)
{
  char v5; // r30
  int v6; // r27
  idToken *v7; // r28
  idToken *v8; // r6
  idToken v9; // [sp+50h] [-80h] BYREF

  idToken::operator=(this: this->tokens, __that: indexToken);
  v5 = 0;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v9.intvalue = 0;
  v9.floatvalue = -3.4028235e38;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v9);
  v6 = 1;
  v7 = &this->tokens[1];
  do
  {
    if ( idParser::PeekTokenType(this: src, type: 5, subtype: 47, token: &v9) != 0 )
    {
      idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v9);
      v5 = 1;
    }
    else
    {
      v8 = v7;
      if ( v6 >= 7 )
        v8 = &v9;
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: v8);
    }
    idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v9);
    ++v6;
    ++v7;
  }
  while ( v5 == 0 );
  idStr::FreeData(this: &v9);
}


// ========================================================================
// __unwind$496044
// EA  : 0x82E1EDEC
// RVA : 0x00E1EDEC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_496044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?Parse@idJobNoteTextRecord@@QAAXAAVidParser@@ABVidToken@@@Z
// EA  : 0x82E1EE20
// RVA : 0x00E1EE20
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobNoteTextRecord::Parse(idJobNoteTextRecord *this, idParser *src, const idToken *indexToken)
{
  char v5; // r30
  int v6; // r27
  idToken *v7; // r28
  idToken *v8; // r6
  idToken v9; // [sp+50h] [-80h] BYREF

  idToken::operator=(this: this->tokens, __that: indexToken);
  v5 = 0;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v9.intvalue = 0;
  v9.floatvalue = -3.4028235e38;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v9);
  v6 = 1;
  v7 = &this->tokens[1];
  do
  {
    if ( idParser::PeekTokenType(this: src, type: 5, subtype: 47, token: &v9) != 0 )
    {
      idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v9);
      v5 = 1;
    }
    else
    {
      v8 = v7;
      if ( v6 >= 10 )
        v8 = &v9;
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: v8);
    }
    idParser::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v9);
    ++v6;
    ++v7;
  }
  while ( v5 == 0 );
  idStr::FreeData(this: &v9);
}


// ========================================================================
// __unwind$496107
// EA  : 0x82E1EF24
// RVA : 0x00E1EF24
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_496107()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?GetVoiceOverStringID@idVoiceRecord@@QBAXAAVidStrId@@@Z
// EA  : 0x82E1F350
// RVA : 0x00E1F350
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::GetVoiceOverStringID(idVoiceRecord *this, idStrId *voStringID)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: v4, text: idVoiceRecord::info[this->type].stringIDPrefix);
  idStr::Append(this: v4, text: this->tokens[10].data);
  idStr::ReplaceChar(this: v4, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: v4, oldChar: 92, newChar: 95);
  idLangDict::AddKeyVal(this: &idLocalization::languageDict, key: v4[0].data, val: &byte_8200D768);
  idStrId::Set(this: voStringID, key: v4[0].data);
  idStr::FreeData(this: v4);
}


// ========================================================================
// __unwind$496836
// EA  : 0x82E1F3E8
// RVA : 0x00E1F3E8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_496836()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?CleanupText@idVoiceRecord@@QBAXW4voiceRecordToken_t@@AAVidStr@@@Z
// EA  : 0x82E1F410
// RVA : 0x00E1F410
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVoiceRecord::CleanupText(idVoiceRecord *this, const voiceRecordToken_t vrt, idStr *out)
{
  int v6; // r28
  char *data; // r29
  int v8; // r31
  int v9; // r4
  idStr *v10; // r3
  char *v11; // r4

  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  v6 = 0;
  *out->data = 0;
  out->len = 0;
  data = this->tokens[vrt].data;
  if ( *data != 0 )
  {
    do
      ++v6;
    while ( data[v6] != 0 );
  }
  v8 = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v9 = (unsigned __int8)data[v8];
      if ( v9 == 10 || v9 == 13 )
        break;
      v10 = out;
      switch ( v9 )
      {
        case 92:
          idStr::operator+=(this: out, a: 47);
          break;
        case 146:
          LOBYTE(v9) = 39;
          break;
        case 133:
          v11 = "...";
LABEL_14:
          idStr::Append(this: v10, text: v11);
          break;
        default:
          idStr::operator+=(this: out, a: v9);
          break;
      }
      if ( ++v8 >= v6 )
        goto LABEL_16;
    }
    v11 = "\n";
    v10 = out;
    goto LABEL_14;
  }
LABEL_16:
  idStr::StripLeadingWhiteSpace(this: out);
  idStr::StripTrailingWhitespace(this: out);
}


// ========================================================================
// ?CreateVoiceTrack@idVORecord@@QAAPAVidVoiceTrack@@AAVidJobUtils@@ABVidVoiceRecord@@PBVidSoundShader@@_N@Z
// EA  : 0x82E1F528
// RVA : 0x00E1F528
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idVoiceTrack *__fastcall idVORecord::CreateVoiceTrack(
        idVORecord *this,
        idJobUtils *ju,
        idVoiceRecord *vrec,
        const idSoundShader *ss,
        __int64 generateVisemes)
{
  char v9; // r23
  __int64 v10; // r10
  __int64 v11; // r6
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  idResource *v15; // r3
  idResource *v16; // r30
  __int64 v17; // r6
  const char *v18; // r4
  char IsStale; // r20
  const char *v20; // r27
  const idDecl *v21; // r3
  int staleCount; // r10
  bool v23; // r25
  char *data; // r27
  const char *Key; // r3
  int v26; // r4
  char *v27; // r26
  unsigned int v28; // r27
  int v30; // [sp+8h] [-1138h]
  int v31; // [sp+8h] [-1138h]
  int v32; // [sp+Ch] [-1134h]
  int v33; // [sp+Ch] [-1134h]
  int v34; // [sp+10h] [-1130h]
  int v35; // [sp+10h] [-1130h]
  int v36; // [sp+14h] [-112Ch]
  int v37; // [sp+14h] [-112Ch]
  int v38; // [sp+18h] [-1128h]
  int v39; // [sp+18h] [-1128h]
  int v40; // [sp+1Ch] [-1124h]
  int v41; // [sp+1Ch] [-1124h]
  idStrId v42; // [sp+80h] [-10C0h] BYREF
  idStrId v43; // [sp+84h] [-10BCh] BYREF
  idStr v44; // [sp+90h] [-10B0h] BYREF
  idStr v45; // [sp+B0h] [-1090h] BYREF
  va v46; // [sp+D0h] [-1070h] BYREF

  v44.len = 0;
  v44.allocedAndFlag = 20;
  v44.data = v44.baseBuffer;
  v44.baseBuffer[0] = 0;
  v9 = BYTE3(generateVisemes);
  LODWORD(v10) = allocationCurrent[242];
  HIDWORD(v10) = &off_82350000;
  LODWORD(v11) = vrec->tokens[10].data;
  LODWORD(generateVisemes) = &sys_lang;
  HIDWORD(v11) = sys_lang.valueString.data;
  v12 = va::va(
          this: &v46,
          fmt: "voicetrack/%s/%s.vtr",
          a3: v11,
          a4: generateVisemes,
          a5: v10,
          a6: v30,
          a7: v32,
          a8: v34,
          a9: v36,
          a10: v38,
          a11: v40);
  idStr::operator=(this: &v44, text: v12);
  v15 = idResourceList::Load(
          this: &idVoiceTrack::resourceList,
          name: v44.data,
          makeDefault: true,
          skipStaleCheck: false);
  LODWORD(v17) = v15->resourceError;
  v16 = v15;
  HIDWORD(v17) = v44.data;
  if ( (_DWORD)v17 != 0 )
    v18 = "Created voice track '%s'...\n";
  else
    v18 = "Added voice track '%s'...\n";
  DebugPrintf(
    level: PRINT_DEBUG,
    fmt: v18,
    a3: v17,
    a4: v14,
    a5: v13,
    a6: v31,
    a7: v33,
    a8: v35,
    a9: v37,
    a10: v39,
    a11: v41);
  IsStale = idVoiceTrack::IsStale(this: (idVoiceTrack *)v16);
  idResource::SetName(this: v16, _name: v44.data);
  v20 = idVoiceTrack::DEFAULT_VISEME_SET_NAME;
  if ( idVoiceTrack::DEFAULT_VISEME_SET_NAME == nullptr
    || (v21 = idDeclInfo::FindWithInheritance(
                this: &idDeclVisemeSet::resourceList,
                name: idVoiceTrack::DEFAULT_VISEME_SET_NAME,
                makeDefault: false)) == nullptr )
  {
    idLib::Error(fmt: "Failed to load viseme set '%s'.", v20);
  }
  v16[7].staleCount = (int)v21;
  v42.index = -1;
  if ( importingVoiceOversForCombatChatter.valueInteger != 0 )
    idVoiceRecord::GetVoiceOverDescriptionStringID(this: vrec, voStringID: &v42);
  else
    idVoiceRecord::GetVoiceOverStringID(this: vrec, voStringID: &v42);
  staleCount = v16[4].staleCount;
  v43.index = v42.index;
  v23 = (_cntlzw(staleCount - v42.index) & 0x20) != 0;
  idVoiceTrack::SetTrackTextId(this: (idVoiceTrack *)v16, id: &v43);
  v45.allocedAndFlag = 20;
  v45.data = v45.baseBuffer;
  v45.len = 0;
  v45.baseBuffer[0] = 0;
  idVoiceRecord::CleanupText(this: vrec, vrt: VR_GAME_TEXT, out: &v45);
  data = v45.data;
  Key = idStrId::GetKey(this: &v42);
  idLangDict::SetString(this: &idLocalization::languageDict, key: Key, val: data);
  v26 = 0;
  v27 = v45.data;
  if ( *v45.data != 0 )
  {
    do
      ++v26;
    while ( v45.data[v26] != 0 );
  }
  v28 = CRC32_BlockChecksum(data: v45.data, length: v26);
  idVoiceTrack::SetSoundShader(this: (idVoiceTrack *)v16, shader: ss);
  v16[7].networkID = 0;
  if ( v9 != 0 && (IsStale != 0 || (idResource_vtbl *)v28 != v16[5].__vftable) )
  {
    if ( (unsigned __int8)idVORecord::GenerateVisemes(this, ju, vrec, vtrack: (idVoiceTrack *)v16, text: v27) != 0 )
    {
      v16[5].__vftable = (idResource_vtbl *)v28;
LABEL_18:
      idVoiceTrack::Save(this: (idVoiceTrack *)v16, fileName: v44.data);
    }
  }
  else if ( !v23 )
  {
    goto LABEL_18;
  }
  idStr::FreeData(this: &v45);
  idStr::FreeData(this: &v44);
  return (idVoiceTrack *)v16;
}


// ========================================================================
// $LN112_2
// EA  : 0x82E1F794
// RVA : 0x00E1F794
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _LN112_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 144));
}


// ========================================================================
// __unwind$496942
// EA  : 0x82E1F7BC
// RVA : 0x00E1F7BC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_496942()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 176));
}


// ========================================================================
// ?CreateMergedDecl@idVORecord@@QAAXAAVidJobUtils@@AAVidStr@@@Z
// EA  : 0x82E1F7F0
// RVA : 0x00E1F7F0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idVORecord::CreateMergedDecl(idVORecord *this, idJobUtils *ju, idStr *voName)
{
  int v3; // r28
  __int64 v4; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  va *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  char *data; // r4
  idDeclVoiceOver *v15; // r3
  idDeclVoiceOver *v16; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idVoiceTrack *VoiceTrack; // r4
  int i; // r26
  idVoiceRecord *v25; // r29
  const idSoundShader *SoundShader; // r3
  __int64 v27; // r8
  int v28; // [sp+8h] [-10C8h]
  int v29; // [sp+8h] [-10C8h]
  int v30; // [sp+Ch] [-10C4h]
  int v31; // [sp+Ch] [-10C4h]
  int v32; // [sp+10h] [-10C0h]
  int v33; // [sp+10h] [-10C0h]
  int v34; // [sp+14h] [-10BCh]
  int v35; // [sp+14h] [-10BCh]
  int v36; // [sp+18h] [-10B8h]
  int v37; // [sp+18h] [-10B8h]
  int v38; // [sp+1Ch] [-10B4h]
  int v39; // [sp+1Ch] [-10B4h]
  idStr v40; // [sp+70h] [-1060h] BYREF
  va v41; // [sp+90h] [-1040h] BYREF

  v3 = 0;
  LODWORD(v4) = v40.baseBuffer;
  v40.len = 0;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.baseBuffer[0] = 0;
  HIDWORD(v4) = allocationCurrent[242];
  LODWORD(v8) = &off_82350000;
  HIDWORD(v8) = &sys_lang;
  LODWORD(v9) = "_merged";
  HIDWORD(v9) = sys_lang.valueString.data;
  v10 = va::va(
          this: &v41,
          fmt: "decls/voiceover/%s%s.vo",
          a3: v9,
          a4: v8,
          a5: v4,
          a6: v28,
          a7: v30,
          a8: v32,
          a9: v34,
          a10: v36,
          a11: v38);
  idStr::operator=(this: &v40, text: v10);
  data = voName->data;
  if ( data != nullptr )
    v15 = (idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                               this: &idDeclVoiceOver::resourceList,
                               name: data,
                               makeDefault: false);
  else
    v15 = nullptr;
  this->voDecl = v15;
  if ( v15 != nullptr )
  {
    HIDWORD(v13) = v15->name.str;
    DebugPrintf(
      level: PRINT_DEBUG,
      fmt: "Updated vo decl '%s' with tracks:\n",
      a3: v13,
      a4: v12,
      a5: v11,
      a6: v29,
      a7: v31,
      a8: v33,
      a9: v35,
      a10: v37,
      a11: v39);
    this->voDecl->FreeData(this: this->voDecl);
  }
  else
  {
    v16 = (idDeclVoiceOver *)declManager->CreateNewDecl(
                               this: declManager,
                               a2: &idDeclVoiceOver::resourceList,
                               a3: voName->data,
                               a4: v40.data,
                               a5: "{\n\ttracks {\n\t}\n}\n");
    this->voDecl = v16;
    HIDWORD(v17) = v16;
    LODWORD(v18) = &off_82350000;
    HIDWORD(v18) = v16->name.str;
    DebugPrintf(
      level: PRINT_DEBUG,
      fmt: "Created vo decl '%s' with tracks:\n",
      a3: v18,
      a4: v17,
      a5: v19,
      a6: v29,
      a7: v31,
      a8: v33,
      a9: v35,
      a10: v37,
      a11: v39);
  }
  for ( i = 0; i < this->voiceRecords.num; ++v3 )
  {
    v25 = &ju->records.list[this->voiceRecords.list[v3].value];
    SoundShader = idVoiceRecord::CreateSoundShader(this: v25, language: ju->language);
    HIDWORD(v27) = 1;
    VoiceTrack = idVORecord::CreateVoiceTrack(this, ju, vrec: v25, ss: SoundShader, generateVisemes: v27);
    if ( VoiceTrack != nullptr )
      idDeclVoiceOver::AddTrack(this: this->voDecl, vtrack: (idSpawnArea::GeneratedPosition *)VoiceTrack);
    ++i;
  }
  idVORecord::ListVoiceTracks(this, a2: (int)VoiceTrack, a3: v22, a4: v21, a5: v20);
  idStr::FreeData(this: &v40);
}


// ========================================================================
// __unwind$497179_0
// EA  : 0x82E1F98C
// RVA : 0x00E1F98C
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497179_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 112));
}


// ========================================================================
// ?CleanupText@idJobNoteTextRecord@@QBAXW4jobNoteTextRecordToken_t@@AAVidStr@@@Z
// EA  : 0x82E1F9B8
// RVA : 0x00E1F9B8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobNoteTextRecord::CleanupText(
        idJobNoteTextRecord *this,
        const jobNoteTextRecordToken_t vrt,
        idStr *out)
{
  int v6; // r28
  char *data; // r29
  int v8; // r31
  int v9; // r4
  idStr *v10; // r3
  char *v11; // r4

  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  v6 = 0;
  *out->data = 0;
  out->len = 0;
  data = this->tokens[vrt].data;
  if ( *data != 0 )
  {
    do
      ++v6;
    while ( data[v6] != 0 );
  }
  v8 = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v9 = (unsigned __int8)data[v8];
      if ( v9 == 10 || v9 == 13 )
        break;
      v10 = out;
      switch ( v9 )
      {
        case 92:
          idStr::operator+=(this: out, a: 47);
          break;
        case 146:
          LOBYTE(v9) = 39;
          break;
        case 133:
          v11 = "...";
LABEL_14:
          idStr::Append(this: v10, text: v11);
          break;
        default:
          idStr::operator+=(this: out, a: v9);
          break;
      }
      if ( ++v8 >= v6 )
        goto LABEL_16;
    }
    v11 = "\n";
    v10 = out;
    goto LABEL_14;
  }
LABEL_16:
  idStr::StripLeadingWhiteSpace(this: out);
  idStr::StripTrailingWhitespace(this: out);
}


// ========================================================================
// ?GetJobSummary@idJobTextRecord@@QBAXAAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E1FAD0
// RVA : 0x00E1FAD0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobTextRecord::GetJobSummary(idJobTextRecord *this, idStrId *id, idStr *text)
{
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v7, text: "#str_jobsum_");
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  idStr::operator=(this: &v6, text: this->tokens[2].data);
  idStr::StripLeading(this: &v6, string: "jobs/");
  idStr::ReplaceChar(this: &v6, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: &v6, oldChar: 92, newChar: 95);
  idStr::Append(this: v7, text: &v6);
  idStrId::Set(this: id, key: v7[0].data);
  idJobNoteTextRecord::CleanupText((idJobNoteTextRecord *)this, vrt: JNTR_REMOVENOTE, out: text);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$497376
// EA  : 0x82E1FB94
// RVA : 0x00E1FB94
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497376()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$497377
// EA  : 0x82E1FBBC
// RVA : 0x00E1FBBC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497377()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetJobName@idJobTextRecord@@QBAXAAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E1FBF0
// RVA : 0x00E1FBF0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobTextRecord::GetJobName(idJobTextRecord *this, idStrId *id, idStr *text)
{
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v7, text: "#str_jobname_");
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  idStr::operator=(this: &v6, text: this->tokens[2].data);
  idStr::StripLeading(this: &v6, string: "jobs/");
  idStr::ReplaceChar(this: &v6, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: &v6, oldChar: 92, newChar: 95);
  idStr::Append(this: v7, text: &v6);
  idStrId::Set(this: id, key: v7[0].data);
  idJobNoteTextRecord::CleanupText((idJobNoteTextRecord *)this, vrt: JNTR_HUDINFO, out: text);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$497449
// EA  : 0x82E1FCB4
// RVA : 0x00E1FCB4
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497449()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$497450
// EA  : 0x82E1FCDC
// RVA : 0x00E1FCDC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497450()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetJobRequirements@idJobTextRecord@@QBAXAAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E1FD10
// RVA : 0x00E1FD10
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobTextRecord::GetJobRequirements(idJobTextRecord *this, idStrId *id, idStr *text)
{
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v7, text: "#str_jobreq_");
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  idStr::operator=(this: &v6, text: this->tokens[2].data);
  idStr::StripLeading(this: &v6, string: "jobs/");
  idStr::ReplaceChar(this: &v6, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: &v6, oldChar: 92, newChar: 95);
  idStr::Append(this: v7, text: &v6);
  idStrId::Set(this: id, key: v7[0].data);
  idJobNoteTextRecord::CleanupText((idJobNoteTextRecord *)this, vrt: JNTR_ACCPTFLAG, out: text);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$497522
// EA  : 0x82E1FDD4
// RVA : 0x00E1FDD4
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497522()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$497523
// EA  : 0x82E1FDFC
// RVA : 0x00E1FDFC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetJobRewards@idJobTextRecord@@QBAXAAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E1FE30
// RVA : 0x00E1FE30
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobTextRecord::GetJobRewards(idJobTextRecord *this, idStrId *id, idStr *text)
{
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v7, text: "#str_jobrwd_");
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  idStr::operator=(this: &v6, text: this->tokens[2].data);
  idStr::StripLeading(this: &v6, string: "jobs/");
  idStr::ReplaceChar(this: &v6, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: &v6, oldChar: 92, newChar: 95);
  idStr::Append(this: v7, text: &v6);
  idStrId::Set(this: id, key: v7[0].data);
  idJobNoteTextRecord::CleanupText((idJobNoteTextRecord *)this, vrt: JNTR_REMOVEMAPRELEVANT, out: text);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$497595
// EA  : 0x82E1FEF4
// RVA : 0x00E1FEF4
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$497596
// EA  : 0x82E1FF1C
// RVA : 0x00E1FF1C
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetHudInfo@idJobNoteTextRecord@@QBAXAAVidStrId@@AAVidStr@@@Z
// EA  : 0x82E1FF50
// RVA : 0x00E1FF50
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobNoteTextRecord::GetHudInfo(idJobNoteTextRecord *this, idStrId *id, idStr *text)
{
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v7, text: "#str_jobnote_");
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  idStr::operator=(this: &v6, text: this->tokens[2].data);
  idStr::StripLeading(this: &v6, string: "jobnote/");
  idStr::ReplaceChar(this: &v6, oldChar: 47, newChar: 95);
  idStr::ReplaceChar(this: &v6, oldChar: 92, newChar: 95);
  idStr::Append(this: v7, text: &v6);
  idStr::Append(this: v7, text: "_hud");
  idStrId::Set(this: id, key: v7[0].data);
  idJobNoteTextRecord::CleanupText(this, vrt: JNTR_HUDINFO, out: text);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$497704_0
// EA  : 0x82E20024
// RVA : 0x00E20024
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497704_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$497705_0
// EA  : 0x82E2004C
// RVA : 0x00E2004C
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_497705_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ExportJobDescriptions_InsertJob@@YAHPBVidDeclJob@@AAV?$idList@PBVidDeclJob@@$04@@@Z
// EA  : 0x82E20580
// RVA : 0x00E20580
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

int __fastcall ExportJobDescriptions_InsertJob(
        const idDeclJob *jobDecl,
        idList<idDeclJob const *,5> *jobList,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idVec1 a12)
{
  int num; // r10
  int result; // r3
  int v16; // r11
  int v17; // r28
  int i; // r30
  const idDeclJob::jobPreCondition_t *JobPrecondition; // r3
  const idDeclJob::jobPreCondition_t *v20; // r31
  const char *data; // r4
  const idDeclJob *v22; // r3
  int inserted; // r3

  num = jobList->num;
  LODWORD(a12.x) = (idVec1)jobDecl;
  result = 0;
  if ( num <= 0 )
    goto LABEL_7;
  v16 = 0;
  while ( jobList->list[v16] != jobDecl )
  {
    ++result;
    ++v16;
    if ( result >= num )
      goto LABEL_7;
  }
  if ( result < 0 )
  {
LABEL_7:
    v17 = 0;
    for ( i = 0; i < (int)idMapPatch::GetMaterial(hSSMDev: jobDecl); ++i )
    {
      JobPrecondition = idDeclJob::GetJobPrecondition(this: jobDecl, idx: i);
      v20 = JobPrecondition;
      if ( JobPrecondition->precondition == JOBPRECONDITION_JOB
        && idStr::Icmp(s1: JobPrecondition->jobDecl.data, s2: jobDecl->name.str) != 0 )
      {
        data = v20->jobDecl.data;
        if ( data != nullptr )
          v22 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclJob::resourceList,
                                     name: data,
                                     makeDefault: true);
        else
          v22 = nullptr;
        inserted = ExportJobDescriptions_InsertJob(jobDecl: v22, jobList);
        if ( inserted >= v17 )
          v17 = inserted + 1;
      }
    }
    return idList<idVec1,116>::Insert(this: (idList<idVec1,116> *)jobList, obj: &a12, index: v17);
  }
  return result;
}


// ========================================================================
// ?ExportJobDescriptions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E20690
// RVA : 0x00E20690
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ExportJobDescriptions_f(const idCmdArgs *args)
{
  idFile *v1; // r21
  int num; // r27
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // r30
  int i; // r28
  idDeclSource **v9; // r10
  idDeclSource *v10; // r9
  const idDeclJob *v11; // r3
  int v12; // r26
  idDeclJob *v13; // r30
  const char *LocalizedString; // r3
  const char *v15; // r3
  const char *v16; // r3
  const char *v17; // r3
  bool IsJobHidden; // r3
  const char *v19; // r4
  bool v20; // r3
  const char *v21; // r4
  idFile_vtbl *v22; // r30
  char *filePtr; // r29
  unsigned int v24; // r3
  int v25; // [sp+8h] [-278h]
  int v26; // [sp+Ch] [-274h]
  int v27; // [sp+10h] [-270h]
  idVec1 *v28; // [sp+14h] [-26Ch]
  idList<idVehicleState *,5> v29; // [sp+50h] [-230h] BYREF
  idDeclSource **v30; // [sp+60h] [-220h]
  idStr v31; // [sp+70h] [-210h] BYREF
  idStr v32; // [sp+90h] [-1F0h] BYREF
  idStr v33; // [sp+B0h] [-1D0h] BYREF
  idFile_Memory v34; // [sp+D0h] [-1B0h] BYREF

  idFile_Memory::idFile_Memory(this: &v34);
  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "intermediate/jobexport.csv", a3: 0);
  if ( v1 != nullptr )
  {
    memset(&v29, 0, 14);
    *(_WORD *)&v29.memTag = 1280;
    num = idDeclJob::resourceList.declSources.num;
    idList<idThread *,58>::Clear(this: &v29);
    if ( num > v29.size )
      idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v29, newsize: num);
    if ( num > 0 )
    {
      v7 = 0;
      for ( i = num; i != 0; --i )
      {
        v9 = &idDeclJob::resourceList.declSources.list[v7];
        v30 = &idDeclJob::resourceList.declSources.list[v7];
        v10 = idDeclJob::resourceList.declSources.list[v7];
        if ( v10->name.str != nullptr )
          v11 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclJob::resourceList,
                                     name: v10->name.str,
                                     makeDefault: false);
        else
          v11 = nullptr;
        ExportJobDescriptions_InsertJob(
          jobDecl: v11,
          jobList: (idList<idDeclJob const *,5> *)&v29,
          a3: v6,
          a4: v5,
          a5: v4,
          a6: v3,
          a7: (int)v10,
          a8: (int)v9,
          a9: v25,
          a10: v26,
          a11: v27,
          a12: v28);
        ++v7;
      }
      v12 = 0;
      do
      {
        v13 = (idDeclJob *)v29.list[v12];
        if ( !idDeclJob::IsJobHidden(this: v13) )
        {
          idFile::Printf(this: &v34, fmt: "}");
          idFile::Printf(this: &v34, fmt: "%s}", v13->name.str);
          if ( v13->jobNameId.index >= 0 )
          {
            LocalizedString = idStrId::GetLocalizedString(this: &v13->jobNameId);
            idFile::Printf(this: &v34, fmt: "%s}", LocalizedString);
          }
          else
          {
            idFile::Printf(this: &v34, fmt: "}");
          }
          if ( v13->jobSummaryId.index >= 0 )
          {
            v15 = idStrId::GetLocalizedString(this: &v13->jobSummaryId);
            idStr::idStr(this: &v31, text: v15);
            idStr::ReplaceChar(this: &v31, oldChar: 10, newChar: 123);
            idFile::Printf(this: &v34, fmt: "%s}", v31.data);
            idStr::FreeData(this: &v31);
          }
          else
          {
            idFile::Printf(this: &v34, fmt: "}");
          }
          if ( v13->jobRequirementsId.index >= 0 )
          {
            v16 = idStrId::GetLocalizedString(this: &v13->jobRequirementsId);
            idStr::idStr(this: &v33, text: v16);
            idStr::ReplaceChar(this: &v33, oldChar: 10, newChar: 123);
            idFile::Printf(this: &v34, fmt: "%s}", v33.data);
            idStr::FreeData(this: &v33);
          }
          else
          {
            idFile::Printf(this: &v34, fmt: "}");
          }
          if ( v13->jobRewardId.index >= 0 )
          {
            v17 = idStrId::GetLocalizedString(this: &v13->jobRewardId);
            idStr::idStr(this: &v32, text: v17);
            idStr::ReplaceChar(this: &v32, oldChar: 10, newChar: 123);
            idFile::Printf(this: &v34, fmt: "%s}", v32.data);
            idStr::FreeData(this: &v32);
          }
          else
          {
            idFile::Printf(this: &v34, fmt: "}");
          }
          IsJobHidden = idDeclJob::IsJobHidden(this: v13);
          v19 = "X}";
          if ( !IsJobHidden )
            v19 = "}";
          idFile::Printf(this: &v34, fmt: v19);
          v20 = idDeclJob::ShowsGUI(this: v13);
          v21 = "}\n";
          if ( !v20 )
            v21 = "X}\n";
          idFile::Printf(this: &v34, fmt: v21);
        }
        --num;
        ++v12;
      }
      while ( num != 0 );
    }
    v22 = v1->__vftable;
    filePtr = v34.filePtr;
    v24 = (unsigned __int64)idFile_Memory::Length(this: &v34) >> 32;
    v22->Write(this: v1, a2: filePtr, a3: v24);
    ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
    if ( v29.listStatic == 0 || v29.listStatic == 2 )
    {
      if ( v29.list != nullptr )
        idMem::Free(this: &mem, ptr: v29.list, align: ALIGN_16);
      v29.list = nullptr;
      v29.size = 0;
    }
    v29.num = 0;
  }
  else
  {
    idLib::Warning(fmt: "could not create file for job export");
  }
  idFile_Memory::~idFile_Memory(this: &v34);
}


// ========================================================================
// __unwind$498364
// EA  : 0x82E20A10
// RVA : 0x00E20A10
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498364()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 640 + 208));
}


// ========================================================================
// __unwind$498365
// EA  : 0x82E20A38
// RVA : 0x00E20A38
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498365()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 640 + 80));
}


// ========================================================================
// __unwind$498366
// EA  : 0x82E20A60
// RVA : 0x00E20A60
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 112));
}


// ========================================================================
// __unwind$498367
// EA  : 0x82E20A88
// RVA : 0x00E20A88
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 176));
}


// ========================================================================
// __unwind$498368
// EA  : 0x82E20AB0
// RVA : 0x00E20AB0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498368()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 144));
}


// ========================================================================
// ?ExportJobNotes_InsertJobNote@@YAHPBVidDeclJobNote@@AAV?$idList@PBVidDeclJobNote@@$04@@@Z
// EA  : 0x82E20AD8
// RVA : 0x00E20AD8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

int __fastcall ExportJobNotes_InsertJobNote(
        const idDeclJobNote *jobNoteDecl,
        idList<idVec1,116> *jobNoteList,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idVec1 a12)
{
  int num; // r10
  int result; // r3
  int v16; // r11
  int v17; // r28
  int v18; // r30
  const idDeclJobNote *x_low; // r31
  int v20; // r3
  bool v21; // cr57

  num = jobNoteList->num;
  LODWORD(a12.x) = (idVec1)jobNoteDecl;
  result = 0;
  if ( num <= 0 )
    goto LABEL_7;
  v16 = 0;
  while ( (const idDeclJobNote *)LODWORD(jobNoteList->list[v16].x) != jobNoteDecl )
  {
    ++result;
    ++v16;
    if ( result >= num )
      goto LABEL_7;
  }
  if ( result < 0 )
  {
LABEL_7:
    v17 = 0;
    if ( num > 0 )
    {
      v18 = 0;
      do
      {
        x_low = (const idDeclJobNote *)LODWORD(jobNoteList->list[v18].x);
        v20 = idStr::Icmp(s1: x_low->jobDeclReference.data, s2: jobNoteDecl->jobDeclReference.data);
        v21 = v20 > 0;
        if ( v20 == 0 )
          v21 = idStr::Icmp(s1: x_low->name.str, s2: jobNoteDecl->name.str) > 0;
        if ( v21 )
          break;
        ++v17;
        ++v18;
      }
      while ( v17 < jobNoteList->num );
    }
    return idList<idVec1,116>::Insert(this: jobNoteList, obj: &a12, index: v17);
  }
  return result;
}


// ========================================================================
// ?ExportJobNotes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E20BA8
// RVA : 0x00E20BA8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ExportJobNotes_f(const idCmdArgs *args)
{
  idFile *v1; // r23
  int num; // r27
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // r30
  int i; // r28
  idDeclSource **v9; // r10
  idDeclSource *v10; // r9
  const idDeclJobNote *v11; // r3
  idVehicleState **list; // r24
  idVehicleState **v13; // r29
  idVehicleState *v14; // r30
  const char *LocalizedString; // r3
  idFile_vtbl *v16; // r30
  char *filePtr; // r29
  unsigned int v18; // r3
  int v19; // [sp+8h] [-208h]
  int v20; // [sp+Ch] [-204h]
  int v21; // [sp+10h] [-200h]
  idVec1 *v22; // [sp+14h] [-1FCh]
  idList<idVehicleState *,5> v23; // [sp+50h] [-1C0h] BYREF
  idDeclSource **v24; // [sp+60h] [-1B0h]
  idFile_Memory v25; // [sp+70h] [-1A0h] BYREF

  idFile_Memory::idFile_Memory(this: &v25);
  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "intermediate/jobnoteexport.csv", a3: 0);
  if ( v1 != nullptr )
  {
    memset(&v23, 0, 14);
    *(_WORD *)&v23.memTag = 1280;
    num = idDeclJobNote::resourceList.declSources.num;
    idList<idThread *,58>::Clear(this: &v23);
    if ( num > v23.size )
      idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v23, newsize: num);
    if ( num > 0 )
    {
      v7 = 0;
      for ( i = num; i != 0; --i )
      {
        v9 = &idDeclJobNote::resourceList.declSources.list[v7];
        v24 = &idDeclJobNote::resourceList.declSources.list[v7];
        v10 = idDeclJobNote::resourceList.declSources.list[v7];
        if ( v10->name.str != nullptr )
          v11 = (const idDeclJobNote *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclJobNote::resourceList,
                                         name: v10->name.str,
                                         makeDefault: false);
        else
          v11 = nullptr;
        ExportJobNotes_InsertJobNote(
          jobNoteDecl: v11,
          jobNoteList: (idList<idVec1,116> *)&v23,
          a3: v6,
          a4: v5,
          a5: v4,
          a6: v3,
          a7: (int)v10,
          a8: (int)v9,
          a9: v19,
          a10: v20,
          a11: v21,
          a12: v22);
        ++v7;
      }
    }
    list = v23.list;
    if ( num > 0 )
    {
      v13 = v23.list;
      do
      {
        v14 = *v13;
        idFile::Printf(this: &v25, fmt: "%s}", (*v13)->debugInfo.data);
        idFile::Printf(this: &v25, fmt: "%s}", (const char *)v14->listeningToList);
        if ( (int)v14->ai >= 0 )
        {
          LocalizedString = idStrId::GetLocalizedString(this: (idStrId *)&v14->ai);
          idFile::Printf(this: &v25, fmt: "%s}", LocalizedString);
        }
        else
        {
          idFile::Printf(this: &v25, fmt: "}");
        }
        idFile::Printf(this: &v25, fmt: "}");
        idFile::Printf(this: &v25, fmt: "\n");
        --num;
        ++v13;
      }
      while ( num != 0 );
    }
    v16 = v1->__vftable;
    filePtr = v25.filePtr;
    v18 = (unsigned __int64)idFile_Memory::Length(this: &v25) >> 32;
    v16->Write(this: v1, a2: filePtr, a3: v18);
    ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
    if ( (v23.listStatic == 0 || v23.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  else
  {
    idLib::Warning(fmt: "could not create file for job Note export");
  }
  idFile_Memory::~idFile_Memory(this: &v25);
}


// ========================================================================
// __unwind$498635
// EA  : 0x82E20DC4
// RVA : 0x00E20DC4
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498635()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 528 + 112));
}


// ========================================================================
// __unwind$498636
// EA  : 0x82E20DEC
// RVA : 0x00E20DEC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498636()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 80));
}


// ========================================================================
// ?ExportJobCompletions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E20E20
// RVA : 0x00E20E20
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ExportJobCompletions_f(const idCmdArgs *args)
{
  idFile *v1; // r26
  int v2; // r27
  int num; // r28
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v8; // r30
  int i; // r29
  idDeclSource **v10; // r10
  idDeclSource *v11; // r9
  const idDeclJob *v12; // r3
  int v13; // r15
  idDeclJob *v14; // r26
  const idDeclJob::jobComplete_t *CompletionRequirement; // r3
  idStrId *v16; // r30
  int index; // r11
  idStrId *v18; // r11
  const char *Key; // r3
  idStrId *v20; // r3
  const char *v21; // r4
  idStrId *v22; // r30
  const char *v23; // r3
  const char *LocalizedString; // r3
  const char *v25; // r4
  idStrId *v26; // r3
  idStrId *v27; // r30
  const char *v28; // r3
  const char *v29; // r3
  idFile_vtbl *v30; // r30
  char *filePtr; // r29
  unsigned int v32; // r3
  int v33; // [sp+8h] [-258h]
  int v34; // [sp+Ch] [-254h]
  int v35; // [sp+10h] [-250h]
  idVec1 *v36; // [sp+14h] [-24Ch]
  idList<idVehicleState *,5> v37; // [sp+50h] [-210h] BYREF
  idFile *v38; // [sp+60h] [-200h]
  idDeclSource **v39; // [sp+64h] [-1FCh]
  idFile_Memory v40; // [sp+70h] [-1F0h] BYREF

  idFile_Memory::idFile_Memory(this: &v40);
  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "intermediate/jobcompletionsexport.csv", a3: 0);
  v38 = v1;
  if ( v1 == nullptr )
  {
    idLib::Warning(fmt: "could not create file for job completion export");
    goto LABEL_46;
  }
  v2 = 0;
  memset(&v37, 0, 14);
  *(_WORD *)&v37.memTag = 1280;
  num = idDeclJob::resourceList.declSources.num;
  idList<idThread *,58>::Clear(this: &v37);
  if ( num > v37.size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v37, newsize: num);
  if ( num > 0 )
  {
    v8 = 0;
    for ( i = num; i != 0; --i )
    {
      v10 = &idDeclJob::resourceList.declSources.list[v8];
      v39 = &idDeclJob::resourceList.declSources.list[v8];
      v11 = idDeclJob::resourceList.declSources.list[v8];
      if ( v11->name.str != nullptr )
        v12 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclJob::resourceList,
                                   name: v11->name.str,
                                   makeDefault: false);
      else
        v12 = nullptr;
      ExportJobDescriptions_InsertJob(
        jobDecl: v12,
        jobList: (idList<idDeclJob const *,5> *)&v37,
        a3: v7,
        a4: v6,
        a5: v5,
        a6: v4,
        a7: (int)v11,
        a8: (int)v10,
        a9: v33,
        a10: v34,
        a11: v35,
        a12: v36);
      ++v8;
    }
  }
  idFile::Printf(this: &v40, fmt: "JOB}");
  idFile::Printf(this: &v40, fmt: "INDEX}");
  idFile::Printf(this: &v40, fmt: "TYPE}");
  idFile::Printf(this: &v40, fmt: "STRING ID}");
  idFile::Printf(this: &v40, fmt: "TEXT}\n");
  if ( num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = (idDeclJob *)v37.list[v13];
      if ( idDeclJob::GetNumCompletionRequirements(this: v14) > 0 )
      {
        do
        {
          CompletionRequirement = idDeclJob::GetCompletionRequirement(this: v14, idx: v2);
          v16 = (idStrId *)CompletionRequirement;
          if ( !CompletionRequirement->showTrackerMessage || CompletionRequirement->completion == JOBCOMPLETE_NONE )
            goto LABEL_37;
          idFile::Printf(this: &v40, fmt: "%s}", v14->name.str);
          idFile::Printf(this: &v40, fmt: "%d}", v2);
          index = v16->index;
          if ( v16->index == 1 )
          {
            idFile::Printf(this: &v40, fmt: "ITEM}");
            v18 = (idStrId *)v16[1].index;
            if ( v18 == nullptr )
              goto LABEL_35;
            Key = idStrId::GetKey(this: v18 + 41);
            idFile::Printf(this: &v40, fmt: "%s}", Key);
            v20 = (idStrId *)(v16[1].index + 164);
          }
          else
          {
            if ( index == 3 )
            {
              idFile::Printf(this: &v40, fmt: "JOB COMPLETE}");
            }
            else
            {
              if ( index != 4 )
              {
                if ( index == 2 )
                {
                  idFile::Printf(this: &v40, fmt: "TRIGGERED}");
                }
                else if ( index == 5 )
                {
                  idFile::Printf(this: &v40, fmt: "GAME STATE INT ?}");
                }
                else
                {
                  v21 = "JUST DISPLAY}";
                  if ( index != 6 )
                    v21 = "RACER WIN ? }";
                  idFile::Printf(this: &v40, fmt: v21);
                }
                v22 = v16 + 4;
                v23 = idStrId::GetKey(this: v22);
                idFile::Printf(this: &v40, fmt: "%s}", v23);
                LocalizedString = idStrId::GetLocalizedString(this: v22);
                idFile::Printf(this: &v40, fmt: "%s}", LocalizedString);
                goto LABEL_36;
              }
              idFile::Printf(this: &v40, fmt: "JOB ACCEPTED}");
            }
            v25 = (const char *)v16[6].index;
            if ( v25 == nullptr
              || (v26 = (idStrId *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclJob::resourceList,
                                     name: v25,
                                     makeDefault: false)) == nullptr )
            {
LABEL_35:
              idFile::Printf(this: &v40, fmt: "NO DECL!}BAD DATA}");
              goto LABEL_36;
            }
            v27 = v26 + 16;
            v28 = idStrId::GetKey(this: v26 + 16);
            idFile::Printf(this: &v40, fmt: "%s}", v28);
            v20 = v27;
          }
          v29 = idStrId::GetLocalizedString(this: v20);
          idFile::Printf(this: &v40, fmt: "%s}", v29);
LABEL_36:
          idFile::Printf(this: &v40, fmt: "\n");
LABEL_37:
          ++v2;
        }
        while ( v2 < idDeclJob::GetNumCompletionRequirements(this: v14) );
      }
      --num;
      ++v13;
      v2 = 0;
    }
    while ( num != 0 );
    v1 = v38;
  }
  v30 = v1->__vftable;
  filePtr = v40.filePtr;
  v32 = (unsigned __int64)idFile_Memory::Length(this: &v40) >> 32;
  v30->Write(this: v1, a2: filePtr, a3: v32);
  ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
  if ( v37.listStatic == 0 || v37.listStatic == 2 )
  {
    if ( v37.list != nullptr )
      idMem::Free(this: &mem, ptr: v37.list, align: ALIGN_16);
    v37.list = nullptr;
    v37.size = 0;
  }
  v37.num = 0;
LABEL_46:
  idFile_Memory::~idFile_Memory(this: &v40);
}


// ========================================================================
// __unwind$498793
// EA  : 0x82E21230
// RVA : 0x00E21230
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498793()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 608 + 112));
}


// ========================================================================
// __unwind$498794
// EA  : 0x82E21258
// RVA : 0x00E21258
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_498794()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 608 + 80));
}


// ========================================================================
// ?TokenizeBySemicolon@@YAXPBDAAV?$idList@VidToken@@$04@@@Z
// EA  : 0x82E21CF8
// RVA : 0x00E21CF8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall TokenizeBySemicolon(const char *text, idList<idToken,5> *tokens)
{
  const char *v3; // r30
  idToken *v4; // r31
  char v5; // r27
  char *data; // r9
  int v7; // r11

  v3 = text;
  v4 = nullptr;
  if ( *text != 0 )
  {
    do
    {
      if ( *v3 == 59 )
      {
        if ( v4 != nullptr )
        {
          idStr::StripLeadingWhiteSpace(this: v4);
          idStr::StripTrailingWhitespace(this: v4);
        }
        v4 = nullptr;
      }
      else
      {
        if ( v4 == nullptr )
          v4 = idList<idToken,5>::Alloc(this: tokens);
        v5 = *v3;
        idStr::EnsureAlloced(this: v4, amount: v4->len + 2, keepold: true, geometricGrowth: true);
        v4->data[v4->len] = v5;
        data = v4->data;
        v7 = v4->len + 1;
        v4->len = v7;
        data[v7] = 0;
      }
      ++v3;
    }
    while ( *v3 != 0 );
    if ( v4 != nullptr )
    {
      idStr::StripLeadingWhiteSpace(this: v4);
      idStr::StripTrailingWhitespace(this: v4);
    }
  }
}


// ========================================================================
// ?ImportJobDescriptions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E220B8
// RVA : 0x00E220B8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ImportJobDescriptions_f(const idCmdArgs *args)
{
  const char *v2; // r4
  int v3; // r3
  int v4; // r30
  idJobTextRecord *v5; // r3
  const char *v6; // r5
  int num; // r19
  idDeclJob *v8; // r3
  char *list; // r20
  idDeclTypeInfo *v10; // r18
  int i; // r26
  char *v12; // r29
  const char *v13; // r4
  idStrId *v14; // r3
  idStrId *v15; // r30
  char *data; // r28
  const char *Key; // r3
  char *v18; // r28
  const char *v19; // r3
  char *v20; // r28
  const char *v21; // r3
  char *v22; // r29
  const char *v23; // r3
  const char *v24; // r3
  __int64 v25; // r8
  __int64 v26; // r6
  __int64 v27; // r10
  va *v28; // r3
  const char *v29; // r4
  int v30; // [sp+8h] [-1418h]
  int v31; // [sp+Ch] [-1414h]
  int v32; // [sp+10h] [-1410h]
  int v33; // [sp+14h] [-140Ch]
  int v34; // [sp+18h] [-1408h]
  int v35; // [sp+1Ch] [-1404h]
  idList<idJobTextRecord,5> v36; // [sp+50h] [-13D0h] BYREF
  idStr v37; // [sp+60h] [-13C0h] BYREF
  idToken v38; // [sp+80h] [-13A0h] BYREF
  idStr v39; // [sp+D0h] [-1350h] BYREF
  idParser v40; // [sp+F0h] [-1330h] BYREF
  va v41; // [sp+380h] [-10A0h] BYREF

  if ( args->argc < 2 )
  {
    idLib::Printf(fmt: usage);
  }
  else
  {
    idParser::idParser(this: &v40, flags: 0);
    idParser::SetFlags(this: &v40, flags: 0x40000);
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    if ( idParser::LoadFile(this: &v40, filename: v2, OSPath: false) )
    {
      common->SetRefreshOnPrint(this: common, a2: true);
      v3 = idParser::ParseInt(this: &v40);
      v38.len = 0;
      v38.allocedAndFlag = 20;
      v4 = v3;
      v38.data = v38.baseBuffer;
      v38.floatvalue = -3.4028235e38;
      v38.baseBuffer[0] = 0;
      v38.intvalue = 0;
      memset(&v38.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v40, type: 5, subtype: 40, token: &v38);
      *(_WORD *)&v36.memTag = 1280;
      memset(&v36, 0, 14);
      if ( v4 > 0 )
        idList<idJobTextRecord,5>::Resize(this: &v36, newsize: v4);
      while ( idParser::ReadToken(this: &v40, token: &v38) )
      {
        if ( v38.type != 3 )
          idParser::Error(this: &v40, str: "Expected an integer, got '%s'", v38.data);
        v5 = idList<idJobTextRecord,5>::Alloc(this: &v36);
        idJobTextRecord::Parse(this: v5, src: &v40, indexToken: &v38);
      }
      idList<idJobTextRecord,5>::Resize(this: &v36, newsize: v36.num);
      if ( args->argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      num = v36.num;
      idLib::Printf(fmt: "Read %d records from '%s'\n", v36.num, v6);
      v8 = idDeclInfoTemplate<idDeclJob>::AllocDecl(this: &idDeclJob::resourceList);
      list = (char *)v36.list;
      v10 = &v8->idDeclTypeInfo;
      for ( i = 0; i < num; ++i )
      {
        v12 = &list[580 * i];
        if ( *((_DWORD *)v12 + 37) != 0 )
        {
          v13 = *((const char **)v12 + 38);
          if ( v13 != nullptr
            && (v14 = (idStrId *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclJob::resourceList,
                                   name: v13,
                                   makeDefault: false),
                v15 = v14,
                v14 != nullptr) )
          {
            v37.allocedAndFlag = 20;
            v37.len = 0;
            v37.data = v37.baseBuffer;
            v37.baseBuffer[0] = 0;
            if ( *((_DWORD *)v12 + 55) != 0 )
            {
              idJobTextRecord::GetJobName(this: (idJobTextRecord *)&list[580 * i], id: v14 + 16, text: &v37);
              data = v37.data;
              Key = idStrId::GetKey(this: v15 + 16);
              idLangDict::SetString(this: &idLocalization::languageDict, key: Key, val: data);
            }
            else if ( v14[16].index >= 0 )
            {
              v14[16].index = -1;
            }
            if ( *((_DWORD *)v12 + 73) != 0 )
            {
              idJobTextRecord::GetJobSummary(this: (idJobTextRecord *)&list[580 * i], id: v15 + 17, text: &v37);
              v18 = v37.data;
              v19 = idStrId::GetKey(this: v15 + 17);
              idLangDict::SetString(this: &idLocalization::languageDict, key: v19, val: v18);
            }
            else if ( v15[17].index >= 0 )
            {
              v15[17].index = -1;
            }
            if ( *((_DWORD *)v12 + 91) != 0 )
            {
              idJobTextRecord::GetJobRequirements(this: (idJobTextRecord *)&list[580 * i], id: v15 + 18, text: &v37);
              v20 = v37.data;
              v21 = idStrId::GetKey(this: v15 + 18);
              idLangDict::SetString(this: &idLocalization::languageDict, key: v21, val: v20);
            }
            else if ( v15[18].index >= 0 )
            {
              v15[18].index = -1;
            }
            if ( *((_DWORD *)v12 + 109) != 0 )
            {
              idJobTextRecord::GetJobRewards(this: (idJobTextRecord *)&list[580 * i], id: v15 + 19, text: &v37);
              v22 = v37.data;
              v23 = idStrId::GetKey(this: v15 + 19);
              idLangDict::SetString(this: &idLocalization::languageDict, key: v23, val: v22);
            }
            else if ( v15[19].index >= 0 )
            {
              v15[19].index = -1;
            }
            idDeclTypeInfo::SetState(this: (idDeclTypeInfo *)v15, empty: v10);
            idDecl::ReplaceSourceFileText(this: (idDecl *)v15, useSourceControl: true);
            idStr::FreeData(this: &v37);
          }
          else
          {
            idLib::Warning(fmt: "Could not find job decl %s", *((const char **)v12 + 38));
          }
        }
        else
        {
          idLib::Warning(fmt: "No decl name for index %d", i);
        }
      }
      v24 = cvarSystem->GetCVarString(this: cvarSystem, a2: "sys_lang", a3: &byte_8200D768);
      HIDWORD(v25) = &unk_821C0000;
      HIDWORD(v26) = v24;
      v28 = va::va(
              this: &v41,
              fmt: "strings/%s.lang",
              a3: v26,
              a4: v25,
              a5: v27,
              a6: v30,
              a7: v31,
              a8: v32,
              a9: v33,
              a10: v34,
              a11: v35);
      idStr::idStr(this: &v39, text: v28);
      idLangDict::Save(this: &idLocalization::languageDict, fileName: v39.data);
      common->SetRefreshOnPrint(this: common, a2: false);
      idStr::FreeData(this: &v39);
      if ( (v36.listStatic == 0 || v36.listStatic == 2) && list != nullptr )
        idListArrayDelete<idJobTextRecord>(ptr: list, num: v36.size);
      idStr::FreeData(this: &v38);
      idParser::~idParser(this: &v40);
    }
    else
    {
      if ( args->argc <= 1 )
        v29 = &byte_8200D768;
      else
        v29 = args->argv[1];
      idLib::Warning(fmt: "Failed to load file '%s'.", v29);
      idParser::~idParser(this: &v40);
    }
  }
}


// ========================================================================
// $M500267
// EA  : 0x82E225A0
// RVA : 0x00E225A0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void *_M500267()
{
  idLib::Warning(fmt: idException::error);
  return &_M500254_1;
}


// ========================================================================
// __unwind$499909
// EA  : 0x82E225D0
// RVA : 0x00E225D0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_499909()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5152 + 240));
}


// ========================================================================
// __unwind$499910
// EA  : 0x82E225F8
// RVA : 0x00E225F8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_499910()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5152 + 128));
}


// ========================================================================
// __unwind$499911
// EA  : 0x82E22620
// RVA : 0x00E22620
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_499911()
{
  int v0; // r12

  idList<idJobTextRecord,5>::Clear(this: (idList<idJobTextRecord,5> *)(v0 - 5152 + 80));
}


// ========================================================================
// __unwind$499912
// EA  : 0x82E22648
// RVA : 0x00E22648
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_499912()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5152 + 96));
}


// ========================================================================
// __unwind$499913
// EA  : 0x82E22670
// RVA : 0x00E22670
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_499913()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5152 + 208));
}


// ========================================================================
// ?ImportJobNotes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E226A0
// RVA : 0x00E226A0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ImportJobNotes_f(const idCmdArgs *args)
{
  const char *v2; // r4
  int v3; // r3
  int v4; // r30
  idJobNoteTextRecord *v5; // r3
  const char *v6; // r5
  int num; // r14
  idDeclJobNote *v8; // r3
  char *list; // r15
  int i; // r27
  char *v11; // r30
  const char *v12; // r4
  const idDecl *v13; // r3
  idDecl *v14; // r29
  size_t len; // r28
  char *data; // r28
  const char *Key; // r3
  const char *v18; // r4
  const idDecl *v19; // r3
  const char *v20; // r3
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  va *v24; // r3
  const char *v25; // r4
  int v26; // [sp+8h] [-1458h]
  int v27; // [sp+Ch] [-1454h]
  int v28; // [sp+10h] [-1450h]
  int v29; // [sp+14h] [-144Ch]
  int v30; // [sp+18h] [-1448h]
  int v31; // [sp+1Ch] [-1444h]
  idList<idJobNoteTextRecord,5> v32; // [sp+60h] [-1400h] BYREF
  idLangDict *v33; // [sp+70h] [-13F0h]
  idDeclJobNote *v34; // [sp+74h] [-13ECh]
  idStr v35; // [sp+80h] [-13E0h] BYREF
  idToken v36; // [sp+A0h] [-13C0h] BYREF
  idStr v37; // [sp+F0h] [-1370h] BYREF
  idStr v38; // [sp+110h] [-1350h] BYREF
  idParser v39; // [sp+130h] [-1330h] BYREF
  va v40; // [sp+3C0h] [-10A0h] BYREF

  if ( args->argc < 2 )
  {
    idLib::Printf(fmt: usage_0);
  }
  else
  {
    v33 = &idLocalization::languageDict;
    idParser::idParser(this: &v39, flags: 0);
    idParser::SetFlags(this: &v39, flags: 0x40000);
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    if ( idParser::LoadFile(this: &v39, filename: v2, OSPath: false) )
    {
      common->SetRefreshOnPrint(this: common, a2: true);
      v3 = idParser::ParseInt(this: &v39);
      v36.len = 0;
      v36.data = v36.baseBuffer;
      v4 = v3;
      v36.allocedAndFlag = 20;
      v36.floatvalue = -3.4028235e38;
      v36.baseBuffer[0] = 0;
      v36.intvalue = 0;
      memset(&v36.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v39, type: 5, subtype: 40, token: &v36);
      *(_WORD *)&v32.memTag = 1280;
      memset(&v32, 0, 14);
      if ( v4 > 0 )
        idList<idJobNoteTextRecord,5>::Resize(this: &v32, newsize: v4);
      while ( idParser::ReadToken(this: &v39, token: &v36) )
      {
        if ( v36.type != 3 )
          idParser::Error(this: &v39, str: "Expected an integer, got '%s'", v36.data);
        v5 = idList<idJobNoteTextRecord,5>::Alloc(this: &v32);
        idJobNoteTextRecord::Parse(this: v5, src: &v39, indexToken: &v36);
      }
      idList<idJobNoteTextRecord,5>::Resize(this: &v32, newsize: v32.num);
      if ( args->argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      num = v32.num;
      idLib::Printf(fmt: "Read %d records from '%s'\n", v32.num, v6);
      v8 = idDeclInfoTemplate<idDeclJobNote>::AllocDecl(this: &idDeclJobNote::resourceList);
      list = (char *)v32.list;
      v34 = v8;
      for ( i = 0; i < num; ++i )
      {
        v11 = &list[796 * i];
        if ( *((_DWORD *)v11 + 37) != 0 )
        {
          v12 = *((const char **)v11 + 38);
          if ( v12 != nullptr )
            v13 = idDeclInfo::FindWithInheritance(this: &idDeclJobNote::resourceList, name: v12, makeDefault: false);
          else
            v13 = nullptr;
          v14 = (idDecl *)v13;
          if ( v13 != nullptr
            || (idLib::Printf(fmt: "index: %d  Could not find job Note Decl %s adding\n", i, *((const char **)v11 + 38)),
                (v14 = declManager->CreateNewDecl(
                         this: declManager,
                         a2: &idDeclJobNote::resourceList,
                         a3: *((_DWORD *)v11 + 38),
                         a4: "decls/typeinfo/jobNotes.tdef",
                         a5: "{ }\n")) != nullptr) )
          {
            v35.len = 0;
            v35.baseBuffer[0] = 0;
            v35.data = v35.baseBuffer;
            v35.allocedAndFlag = 20;
            if ( *((_DWORD *)v11 + 19) != 0 )
            {
              if ( idStr::Icmp(s1: (const char *)v14[1].nextOnHashChain, s2: *((const char **)v11 + 20)) != 0 )
                idLib::Warning(
                  fmt: "index: %d  referenced job changed from %s to %s for job Note %s,    careful now...",
                  i,
                  (const char *)v14[1].nextOnHashChain,
                  *((const char **)v11 + 20),
                  *((const char **)v11 + 38));
              idStr::idStr(this: &v37, text: *((const char **)v11 + 20));
              len = v37.len;
              idStr::EnsureAlloced(
                this: (idStr *)&v14[1].name,
                amount: v37.len + 1,
                keepold: false,
                geometricGrowth: false);
              memcpy(Dst: v14[1].nextOnHashChain, Src: v37.data, Size: len);
              *((_BYTE *)&v14[1].nextOnHashChain->idResource::__vftable + len) = 0;
              v14[1].name.str = (const char *)len;
              idStr::FreeData(this: &v37);
            }
            else
            {
              idLib::Warning(fmt: "index: %d  No Job Decl Name on job Note %s", i, *((const char **)v11 + 38));
            }
            if ( *((_DWORD *)v11 + 55) != 0 )
            {
              idJobNoteTextRecord::GetHudInfo(
                this: (idJobNoteTextRecord *)&list[796 * i],
                id: (idStrId *)&v14[1].textLength,
                text: &v35);
              data = v35.data;
              Key = idStrId::GetKey(this: (idStrId *)&v14[1].textLength);
              idLangDict::SetString(this: v33, key: Key, val: data);
            }
            else
            {
              v14[1].textLength = -1;
            }
            if ( *((_DWORD *)v11 + 73) != 0 )
            {
              v18 = *((const char **)v11 + 74);
              if ( v18 != nullptr )
                v19 = idDeclInfo::FindWithInheritance(this: &idDeclJobNote::resourceList, name: v18, makeDefault: false);
              else
                v19 = nullptr;
              v14[1].md5Checksum = (unsigned int)v19;
              if ( v19 == nullptr )
                idLib::Warning(
                  fmt: "index: %d on job Note %s, could not find remove note decl",
                  i,
                  *((const char **)v11 + 38));
            }
            else
            {
              v14[1].md5Checksum = 0;
            }
            idDeclTypeInfo::SetState(this: (idDeclTypeInfo *)v14, empty: &v34->idDeclTypeInfo);
            idDecl::ReplaceSourceFileText(this: v14, useSourceControl: true);
            idStr::FreeData(this: &v35);
          }
          else
          {
            idLib::Warning(fmt: "COULD NOT CREATE %s", *((const char **)v11 + 38));
          }
        }
        else
        {
          idLib::Warning(fmt: "index: %d  No decl name for index", i);
        }
      }
      v20 = cvarSystem->GetCVarString(this: cvarSystem, a2: "sys_lang", a3: &byte_8200D768);
      HIDWORD(v21) = &unk_821C0000;
      HIDWORD(v22) = v20;
      v24 = va::va(
              this: &v40,
              fmt: "strings/%s.lang",
              a3: v22,
              a4: v21,
              a5: v23,
              a6: v26,
              a7: v27,
              a8: v28,
              a9: v29,
              a10: v30,
              a11: v31);
      idStr::idStr(this: &v38, text: v24);
      idLangDict::Save(this: v33, fileName: v38.data);
      common->SetRefreshOnPrint(this: common, a2: false);
      idStr::FreeData(this: &v38);
      if ( (v32.listStatic == 0 || v32.listStatic == 2) && list != nullptr )
        idListArrayDelete<idJobNoteTextRecord>(ptr: list, num: v32.size);
      idStr::FreeData(this: &v36);
      idParser::~idParser(this: &v39);
    }
    else
    {
      if ( args->argc <= 1 )
        v25 = &byte_8200D768;
      else
        v25 = args->argv[1];
      idLib::Warning(fmt: "Failed to load file '%s'.", v25);
      idParser::~idParser(this: &v39);
    }
  }
}


// ========================================================================
// $M500750
// EA  : 0x82E22C04
// RVA : 0x00E22C04
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void *_M500750()
{
  idLib::Warning(fmt: idException::error);
  return &_M500737;
}


// ========================================================================
// __unwind$500300
// EA  : 0x82E22C34
// RVA : 0x00E22C34
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500300()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5216 + 304));
}


// ========================================================================
// __unwind$500301
// EA  : 0x82E22C5C
// RVA : 0x00E22C5C
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500301()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5216 + 160));
}


// ========================================================================
// __unwind$500302
// EA  : 0x82E22C84
// RVA : 0x00E22C84
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500302()
{
  int v0; // r12

  idList<idJobNoteTextRecord,5>::Clear(this: (idList<idJobNoteTextRecord,5> *)(v0 - 5216 + 96));
}


// ========================================================================
// __unwind$500303
// EA  : 0x82E22CAC
// RVA : 0x00E22CAC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5216 + 128));
}


// ========================================================================
// __unwind$500304
// EA  : 0x82E22CD4
// RVA : 0x00E22CD4
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500304()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5216 + 240));
}


// ========================================================================
// __unwind$500305
// EA  : 0x82E22CFC
// RVA : 0x00E22CFC
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_500305()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5216 + 272));
}


// ========================================================================
// ?ImportVoiceOvers@idJobUtils@@QAAXABVidCmdArgs@@@Z
// EA  : 0x82E23000
// RVA : 0x00E23000
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobUtils::ImportVoiceOvers(idJobUtils *this, const idCmdArgs *args)
{
  char v4; // r9
  int i; // r30
  int argc; // r11
  bool v7; // cr56
  const char *v8; // r4
  int v9; // r3
  int v10; // r29
  char **p_records; // r30
  char **p_mergeVOsList; // r30
  idList<idVoiceRecord,5> *v13; // r30
  int num; // r11
  int size; // r10
  idVoiceRecord *v16; // r26
  const char *data; // r29
  idToken *list; // r27
  int v19; // r25
  int j; // r28
  int v21; // r11
  int v22; // r10
  idVoiceRecord *v23; // r29
  int v24; // r29
  int k; // r30
  const char *v26; // r5
  char **p_vos; // r30
  int v28; // r4
  int v29; // r11
  int v30; // r25
  int v31; // r20
  idVoiceRecord *v32; // r26
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  __int64 v36; // r4
  const char *v37; // r27
  char v38; // r28
  int v39; // r30
  int v40; // r11
  idVoiceRecordMergeVO *v41; // r10
  idList<idStrId,5> *p_mergeVOList; // r3
  int v43; // r10
  int v44; // r9
  int v45; // r11
  int v46; // r10
  idVoiceRecordMergeVO *v47; // r9
  idStr *p_mergeVOName; // r30
  int v49; // r9
  idList<idStrId,5> *v50; // r3
  int v51; // r11
  int v52; // r10
  const idSoundShader *SoundShader; // r28
  idList<idVORecord,5> *v54; // r30
  int v55; // r11
  int v56; // r10
  idVORecord *v57; // r10
  int v58; // r30
  idVoiceRecord *v59; // r29
  idDeclVoiceOver *VoiceOver; // r3
  __int64 v61; // r8
  idVoiceTrack *VoiceTrack; // r4
  int v63; // r11
  int m; // r27
  idList<idVORecord,5> *v65; // r30
  int v66; // r11
  int v67; // r10
  idVORecord *v68; // r10
  int v69; // r28
  int v70; // r30
  int n; // r29
  __int64 v72; // r10
  __int64 v73; // r6
  __int64 v74; // r8
  int v75; // r29
  idDeclTypeInfo *v76; // r30
  const char *v77; // r3
  __int64 v78; // r6
  __int64 v79; // r10
  __int64 v80; // r8
  va *v81; // r3
  const char *v82; // r4
  const char *v83; // r3
  int v84; // [sp+8h] [-1488h]
  int v85; // [sp+Ch] [-1484h]
  int v86; // [sp+10h] [-1480h]
  int v87; // [sp+14h] [-147Ch]
  int v88; // [sp+18h] [-1478h]
  int v89; // [sp+1Ch] [-1474h]
  idStrId v90[4]; // [sp+70h] [-1420h] BYREF
  idList<idToken,5> v91; // [sp+80h] [-1410h] BYREF
  idToken v92; // [sp+90h] [-1400h] BYREF
  idStr v93; // [sp+E0h] [-13B0h] BYREF
  idDeclVoiceOver v94; // [sp+100h] [-1390h] BYREF
  idParser v95; // [sp+160h] [-1330h] BYREF
  va v96; // [sp+3F0h] [-10A0h] BYREF

  if ( args->argc < 2 )
  {
LABEL_117:
    idLib::Printf(fmt: usage_1);
  }
  else
  {
    this->language = JU_LANGUAGE_ENGLISH;
    v4 = 0;
    if ( args->argc != 2 )
    {
      for ( i = 2; ; ++i )
      {
        argc = args->argc;
        v7 = i < args->argc;
        v90[0] = (idStrId)args->argc;
        if ( !v7 )
          break;
        if ( i < 0 || i >= argc )
          v83 = &byte_8200D768;
        else
          v83 = args->argv[i];
        if ( idStr::Icmp(s1: v83, s2: "cleanstrings") != 0 )
          goto LABEL_117;
        v4 = 1;
      }
    }
    if ( v4 != 0 )
      idJobUtils::CleanVOStrings(this, strings: &idLocalization::languageDict);
    idParser::idParser(this: &v95, flags: 0);
    idParser::SetFlags(this: &v95, flags: 0x40000);
    if ( args->argc <= 1 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[1];
    if ( idParser::LoadFile(this: &v95, filename: v8, OSPath: false) )
    {
      common->SetRefreshOnPrint(this: common, a2: true);
      v9 = idParser::ParseInt(this: &v95);
      v92.len = 0;
      v92.baseBuffer[0] = 0;
      v92.allocedAndFlag = 20;
      v10 = v9;
      v92.data = v92.baseBuffer;
      v92.intvalue = 0;
      v92.floatvalue = -3.4028235e38;
      memset(&v92.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v95, type: 5, subtype: 40, token: &v92);
      p_records = (char **)&this->records;
      if ( this->records.listStatic == 0 || this->records.listStatic == 2 )
      {
        if ( *p_records != nullptr )
          idListArrayDelete<idVoiceRecord>(ptr: *p_records, num: this->records.size);
        *p_records = nullptr;
        this->records.size = 0;
      }
      this->records.num = 0;
      if ( v10 > this->records.size )
        idList<idVoiceRecord,5>::Resize(this: &this->records, newsize: v10);
      p_mergeVOsList = (char **)&this->mergeVOsList;
      if ( this->mergeVOsList.listStatic == 0 || this->mergeVOsList.listStatic == 2 )
      {
        if ( *p_mergeVOsList != nullptr )
          idListArrayDelete<idPair<idStr,idList<int,19>>>(ptr: *p_mergeVOsList, num: this->mergeVOsList.size);
        *p_mergeVOsList = nullptr;
        this->mergeVOsList.size = 0;
      }
      this->mergeVOsList.num = 0;
      if ( v10 > this->mergeVOsList.size )
        idList<idVoiceRecordMergeVO,5>::Resize(this: &this->mergeVOsList, newsize: v10);
      while ( idParser::ReadToken(this: &v95, token: &v92) )
      {
        if ( v92.type != 3 )
          idParser::Error(this: &v95, str: "Expected an integer, got '%s'", v92.data);
        v13 = &this->records;
        idList<idVoiceRecord,5>::PreAllocateWithGranularity(this: &this->records, newSize: this->records.num + 1);
        num = this->records.num;
        size = this->records.size;
        if ( num >= size )
        {
          v16 = &v13->list[size - 1];
        }
        else
        {
          v16 = &v13->list[num];
          this->records.num = num + 1;
        }
        idVoiceRecord::Parse(this: v16, src: &v95, indexToken: &v92);
        data = v16->tokens[11].data;
        if ( idStr::Find(searchIn: data, searchFor: ";", casesensitive: true, start: 0, end: -1) != -1 )
        {
          *(_WORD *)&v91.memTag = 1280;
          memset(&v91, 0, 14);
          TokenizeBySemicolon(text: data, tokens: &v91);
          list = v91.list;
          idToken::operator=(this: &v16->tokens[11], __that: v91.list);
          v19 = v91.num;
          for ( j = 1; j < v19; ++j )
          {
            idList<idVoiceRecord,5>::PreAllocateWithGranularity(this: &this->records, newSize: this->records.num + 1);
            v21 = this->records.num;
            v22 = this->records.size;
            if ( v21 >= v22 )
            {
              v23 = &v13->list[v22 - 1];
            }
            else
            {
              v23 = &v13->list[v21];
              this->records.num = v21 + 1;
            }
            idVoiceRecord::operator=(this: v23, __that: v16);
            idToken::operator=(this: &v23->tokens[11], __that: &list[j]);
            idVoiceRecord::DetermineType(this: v23);
          }
          if ( v91.listStatic == 0 || v91.listStatic == 2 )
          {
            if ( list != nullptr )
            {
              v24 = v91.size;
              for ( k = 0; k < v24; ++k )
                idStr::FreeData(this: &list[k]);
              idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
            }
            v91.list = nullptr;
            v91.size = 0;
          }
          v91.num = 0;
        }
      }
      idList<idVoiceRecord,5>::Resize(this: &this->records, newsize: this->records.num);
      if ( args->argc <= 1 )
        v26 = &byte_8200D768;
      else
        v26 = args->argv[1];
      idLib::Printf(fmt: "Read %d records from '%s'\n", this->records.num, v26);
      p_vos = (char **)&this->vos;
      if ( this->vos.listStatic == 0 || this->vos.listStatic == 2 )
      {
        if ( *p_vos != nullptr )
          idListArrayDelete<idStateData::transition_t>(ptr: *p_vos, num: this->vos.size);
        *p_vos = nullptr;
        this->vos.size = 0;
      }
      this->vos.num = 0;
      v28 = this->records.num;
      if ( v28 > this->vos.size )
        idList<idVORecord,5>::Resize(this: &this->vos, newsize: v28);
      v29 = this->records.num;
      v30 = 0;
      v31 = 0;
      v90[0].index = 0;
      if ( v29 > 0 )
      {
        do
        {
          v32 = &this->records.list[v30];
          if ( idStr::Icmp(s1: v32->tokens[7].data, s2: "X") != 0 )
          {
            HIDWORD(v36) = "^3Skipping voice record %s due to input exclusion.\n";
            LODWORD(v36) = v32->tokens[0].data;
            PrintExclusion(fmt: v36, a2: v35, a3: v34, a4: v33, a5: v84, a6: v85, a7: v86, a8: v87);
          }
          else
          {
            if ( v32->type == VRT_MAX )
              ++v31;
            v37 = v32->tokens[11].data;
            if ( *v37 != 0 )
            {
              v38 = 0;
              v39 = 0;
              if ( this->mergeVOsList.num > 0 )
              {
                while ( idStr::Icmp(s1: this->mergeVOsList.list[v39].mergeVOName.data, s2: v37) != 0 )
                {
                  if ( ++v39 >= this->mergeVOsList.num )
                    goto LABEL_74;
                }
                v38 = 1;
                v40 = 0;
                v41 = &this->mergeVOsList.list[v39];
                p_mergeVOList = (idList<idStrId,5> *)&v41->mergeVOList;
                v43 = v41->mergeVOList.voiceRecords.num;
                if ( v43 <= 0 )
                  goto LABEL_73;
                v44 = 0;
                while ( p_mergeVOList->list[v44].index != v30 )
                {
                  v44 = ++v40;
                  if ( v40 >= v43 )
                    goto LABEL_73;
                }
                if ( v40 < 0 )
LABEL_73:
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: p_mergeVOList, obj: v90);
              }
LABEL_74:
              if ( v38 == 0 )
              {
                idList<idVoiceRecordMergeVO,5>::PreAllocateWithGranularity(
                  this: &this->mergeVOsList,
                  newSize: this->mergeVOsList.num + 1);
                v45 = this->mergeVOsList.num;
                v46 = this->mergeVOsList.size;
                v47 = this->mergeVOsList.list;
                if ( v45 >= v46 )
                {
                  p_mergeVOName = &v47[v46 - 1].mergeVOName;
                }
                else
                {
                  this->mergeVOsList.num = v45 + 1;
                  p_mergeVOName = &v47[v45].mergeVOName;
                }
                idStr::operator=(this: p_mergeVOName, text: v37);
                v49 = (int)p_mergeVOName[1].data;
                v50 = (idList<idStrId,5> *)&p_mergeVOName[1];
                v51 = 0;
                if ( v49 <= 0 )
                  goto LABEL_84;
                v52 = 0;
                while ( v50->list[v52].index != v30 )
                {
                  v52 = ++v51;
                  if ( v51 >= v49 )
                    goto LABEL_84;
                }
                if ( v51 < 0 )
LABEL_84:
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: v50, obj: v90);
              }
            }
            SoundShader = idVoiceRecord::CreateSoundShader(this: v32, language: this->language);
            if ( SoundShader != nullptr )
            {
              v54 = &this->vos;
              idList<idVORecord,5>::PreAllocateWithGranularity(this: &this->vos, newSize: this->vos.num + 1);
              v55 = this->vos.num;
              v56 = this->vos.size;
              if ( v55 >= v56 )
              {
                v58 = (int)&v54->list[v56 - 1];
              }
              else
              {
                v57 = v54->list;
                this->vos.num = v55 + 1;
                v58 = (int)&v57[v55];
              }
              v90[0].index = v30;
              v59 = &this->records.list[v30];
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)(v58 + 4), obj: v90);
              VoiceOver = idVoiceRecord::GetVoiceOver(this: v59);
              *(_DWORD *)v58 = VoiceOver;
              VoiceOver->FreeData(this: VoiceOver);
              HIDWORD(v61) = 1;
              VoiceTrack = idVORecord::CreateVoiceTrack(
                             this: (idVORecord *)v58,
                             ju: this,
                             vrec: v59,
                             ss: SoundShader,
                             generateVisemes: v61);
              if ( VoiceTrack != nullptr )
                idDeclVoiceOver::AddTrack(
                  this: *(idDeclVoiceOver **)v58,
                  vtrack: (idSpawnArea::GeneratedPosition *)VoiceTrack);
            }
            else
            {
              idLib::Warning(fmt: "Error: record '%s' has an invalid resource name.", v32->tokens[0].data);
            }
          }
          v63 = this->records.num;
          v90[0].index = ++v30;
        }
        while ( v30 < v63 );
      }
      for ( m = 0; m < this->mergeVOsList.num; ++m )
      {
        v65 = &this->vos;
        idList<idVORecord,5>::PreAllocateWithGranularity(this: &this->vos, newSize: this->vos.num + 1);
        v66 = this->vos.num;
        v67 = this->vos.size;
        if ( v66 >= v67 )
        {
          v69 = (int)&v65->list[v67 - 1];
        }
        else
        {
          v68 = v65->list;
          this->vos.num = v66 + 1;
          v69 = (int)&v68[v66];
        }
        v70 = 0;
        for ( n = m; v70 < this->mergeVOsList.list[n].mergeVOList.voiceRecords.num; ++v70 )
          idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(
            this: (idList<idStrId,5> *)(v69 + 4),
            obj: (const idStrId *)&this->mergeVOsList.list[n].mergeVOList.voiceRecords.list[v70]);
        if ( *(int *)(v69 + 8) > 0 )
          idVORecord::CreateMergedDecl(
            this: (idVORecord *)v69,
            ju: this,
            voName: &this->mergeVOsList.list[n].mergeVOName);
      }
      idLib::Printf(fmt: "Finished parsing input:\n");
      idLib::Printf(fmt: "  ^7Found ^2%d ^7unknown voice overs.\n", v31);
      idLib::Printf(fmt: "  ^7Generated ^2%d ^7unique voice overs.\n", this->vos.num);
      LODWORD(v74) = this->vos.num;
      v75 = 0;
      if ( (int)v74 > 0 )
      {
        do
        {
          LODWORD(v72) = this->vos.list;
          v76 = *(idDeclTypeInfo **)(20 * v75 + v72);
          if ( v76 != nullptr )
          {
            HIDWORD(v73) = v76->name.str;
            DebugPrintf(
              level: PRINT_DEBUG,
              fmt: "Saving decl '%s'...\n",
              a3: v73,
              a4: v74,
              a5: v72,
              a6: v84,
              a7: v85,
              a8: v86,
              a9: v87,
              a10: v88,
              a11: v89);
            idDeclVoiceOver::idDeclVoiceOver(this: &v94);
            idDeclTypeInfo::SetState(this: v76, empty: &v94);
            idDecl::ReplaceSourceFileText(this: v76, useSourceControl: true);
            idDeclVoiceOver::~idDeclVoiceOver(this: &v94);
          }
          ++v75;
        }
        while ( v75 < this->vos.num );
      }
      idLib::Printf(fmt: "Wrote %d voice overs.\n", this->vos.num);
      v77 = cvarSystem->GetCVarString(this: cvarSystem, a2: "sys_lang", a3: &byte_8200D768);
      LODWORD(v78) = &unk_821C0000;
      HIDWORD(v78) = v77;
      v81 = va::va(
              this: &v96,
              fmt: "strings/%s.lang",
              a3: v78,
              a4: v80,
              a5: v79,
              a6: v84,
              a7: v85,
              a8: v86,
              a9: v87,
              a10: v88,
              a11: v89);
      idStr::idStr(this: &v93, text: v81);
      idLangDict::Save(this: &idLocalization::languageDict, fileName: v93.data);
      common->SetRefreshOnPrint(this: common, a2: false);
      idStr::FreeData(this: &v93);
      idStr::FreeData(this: &v92);
      idParser::~idParser(this: &v95);
    }
    else
    {
      if ( args->argc <= 1 )
        v82 = &byte_8200D768;
      else
        v82 = args->argv[1];
      idLib::Warning(fmt: "Failed to load file '%s'.", v82);
      idParser::~idParser(this: &v95);
    }
  }
}


// ========================================================================
// $M501683
// EA  : 0x82E23A48
// RVA : 0x00E23A48
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void *_M501683()
{
  idLib::Warning(fmt: idException::error);
  return &_M501671_1;
}


// ========================================================================
// __unwind$501092_0
// EA  : 0x82E23A78
// RVA : 0x00E23A78
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501092_0()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5264 + 352));
}


// ========================================================================
// __unwind$501093_0
// EA  : 0x82E23AA0
// RVA : 0x00E23AA0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501093_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 144));
}


// ========================================================================
// __unwind$501094_0
// EA  : 0x82E23AC8
// RVA : 0x00E23AC8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501094_0()
{
  int v0; // r12

  idList<idToken,5>::Clear(this: (idList<idToken,5> *)(v0 - 5264 + 128));
}


// ========================================================================
// __unwind$501095_0
// EA  : 0x82E23AF0
// RVA : 0x00E23AF0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501095_0()
{
  int v0; // r12

  idDeclVoiceOver::~idDeclVoiceOver(this: (idDeclVoiceOver *)(v0 - 5264 + 256));
}


// ========================================================================
// __unwind$501096_0
// EA  : 0x82E23B18
// RVA : 0x00E23B18
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501096_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 224));
}


// ========================================================================
// ?ImportVoiceOvers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E23B48
// RVA : 0x00E23B48
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall ImportVoiceOvers_f(const idCmdArgs *args)
{
  idJobUtils v2; // [sp+50h] [-50h] BYREF

  idJobUtils::idJobUtils(this: &v2);
  idJobUtils::ImportVoiceOvers(this: &v2, args);
  idJobUtils::~idJobUtils(this: &v2);
}


// ========================================================================
// __unwind$501713_0
// EA  : 0x82E23B98
// RVA : 0x00E23B98
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501713_0()
{
  int v0; // r12

  idJobUtils::~idJobUtils(this: (idJobUtils *)(v0 - 160 + 80));
}


// ========================================================================
// ?RewriteInteractions@idJobUtils@@QAAXABVidCmdArgs@@@Z
// EA  : 0x82E23BC0
// RVA : 0x00E23BC0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall idJobUtils::RewriteInteractions(idJobUtils *this, const idCmdArgs *args)
{
  int v2; // r29
  idDeclAIPlayerInteraction *v3; // r3
  int num; // r27
  idDeclTypeInfo *v5; // r26
  int v6; // r28
  const char *str; // r4
  idDeclTypeInfo *v8; // r3
  idDecl *v9; // r30

  v2 = 0;
  this->language = JU_LANGUAGE_ENGLISH;
  common->SetRefreshOnPrint(this: common, a2: true);
  v3 = idDeclInfoTemplate<idDeclAIPlayerInteraction>::AllocDecl(this: &idDeclAIPlayerInteraction::resourceList);
  num = idDeclAIPlayerInteraction::resourceList.declSources.num;
  v5 = &v3->idDeclTypeInfo;
  if ( idDeclAIPlayerInteraction::resourceList.declSources.num > 0 )
  {
    v6 = idDeclAIPlayerInteraction::resourceList.declSources.num;
    do
    {
      str = idDeclAIPlayerInteraction::resourceList.declSources.list[v2]->name.str;
      if ( str != nullptr )
      {
        v8 = (idDeclTypeInfo *)idDeclInfo::FindWithInheritance(
                                 this: &idDeclAIPlayerInteraction::resourceList,
                                 name: str,
                                 makeDefault: false);
        v9 = v8;
        if ( v8 != nullptr )
        {
          idDeclTypeInfo::SetState(this: v8, empty: v5);
          idDecl::ReplaceSourceFileText(this: v9, useSourceControl: true);
        }
      }
      --v6;
      ++v2;
    }
    while ( v6 != 0 );
  }
  if ( v5 != nullptr )
    ((void (__fastcall *)(idDeclTypeInfo *, int))v5->dtr_idResource)(a1: v5, a2: 1);
  idLib::Printf(fmt: "Rewrote %d decls.\n", num);
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// ?RewriteInteractions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E23CB8
// RVA : 0x00E23CB8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall RewriteInteractions_f(const idCmdArgs *args)
{
  idJobUtils v2; // [sp+50h] [-50h] BYREF

  idJobUtils::idJobUtils(this: &v2);
  idJobUtils::RewriteInteractions(this: &v2, args);
  idJobUtils::~idJobUtils(this: &v2);
}


// ========================================================================
// __unwind$501935
// EA  : 0x82E23D08
// RVA : 0x00E23D08
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501935()
{
  int v0; // r12

  idJobUtils::~idJobUtils(this: (idJobUtils *)(v0 - 160 + 80));
}


// ========================================================================
// ?CalculateDevMenuLayerInformation@@YAXPAVidDeclDevMenuList@@AAH11@Z
// EA  : 0x82E23D38
// RVA : 0x00E23D38
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall CalculateDevMenuLayerInformation(
        idDeclDevMenuList *listDecl,
        int *maxLayers,
        int *biggestlayer,
        int *biggestMaxSize)
{
  int v8; // r26
  idDeclDevMenuList *v9; // r3
  int num; // r10
  int v11; // r20
  int v12; // r27
  idDeclDevMenuList::idDevMenuOption *v13; // r11
  const idStr *p_devMenuMissionDecl; // r4
  simpleMissionStatus_t devMenuMissionStatus; // r11
  idDeclDevMenuList::idDevMenuOption *list; // r11
  int v17; // r29
  idDeclDevMenuList::idDevMenuOption *v18; // r10
  int v19; // r30
  int v20; // r29
  int v21; // r30
  int Index; // r4
  int v23; // r11
  int v24; // ctr
  idStr *v25; // r10
  int len; // r11
  bool v27; // cr57
  int v28; // r26
  idStr *v29; // r28
  size_t v30; // r29
  idDeclDevMenuList::idDevMenuOption *v31; // r11
  int v32; // r4
  idStr *p_devMenuActiveLayers; // r30
  int allocedAndFlag; // r11
  idDeclDevMenuList::idDevMenuOption *v35; // r11
  int v36; // r29
  idDeclDevMenuList::idDevMenuOption *v37; // r10
  int v38; // r30
  int v39; // r29
  int v40; // r30
  int v41; // r4
  int v42; // r11
  int v43; // ctr
  idStr *v44; // r10
  int v45; // r11
  bool v46; // cr57
  idStr *v47; // r28
  size_t v48; // r29
  idDeclDevMenuList::idDevMenuOption *v49; // r11
  int v50; // r4
  idStr *p_devMenuDeactiveLayers; // r30
  int v52; // r11
  idStr *v53; // r29
  int size; // r30
  idStr *v55; // r28
  idStr *v56; // r29
  int v57; // r30
  idStr *v58; // r28
  idList<idStr,5> v59; // [sp+50h] [-220h] BYREF
  idList<idStr,5> v60; // [sp+60h] [-210h] BYREF
  int v61; // [sp+70h] [-200h]
  idDeclDevMenuList *v62; // [sp+74h] [-1FCh]
  idStr v63; // [sp+80h] [-1F0h] BYREF
  idStr v64; // [sp+A0h] [-1D0h] BYREF
  idStr v65; // [sp+C0h] [-1B0h] BYREF
  idStr v66; // [sp+E0h] [-190h] BYREF
  idStr v67; // [sp+100h] [-170h] BYREF
  idStr v68; // [sp+120h] [-150h] BYREF
  idJobManager v69[2]; // [sp+140h] [-130h] BYREF

  *maxLayers = 0;
  *biggestlayer = 0;
  *biggestMaxSize = 0;
  v8 = 0;
  if ( listDecl != nullptr )
  {
    idJobManager::idJobManager(this: v69);
    v9 = idDeclInfoTemplate<idDeclDevMenuList>::AllocDecl(this: &idDeclDevMenuList::resourceList);
    num = listDecl->devMenuList.num;
    v62 = v9;
    v11 = 0;
    if ( num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = &listDecl->devMenuList.list[v12];
        if ( v13->devMenuSubList == nullptr )
        {
          memset(&v59, 0, 14);
          *(_WORD *)&v59.memTag = 1280;
          *(_WORD *)&v60.memTag = 1280;
          memset(&v60, 0, 14);
          if ( v13->devMenuRaceDescDecl.len != 0 )
          {
            idJobManager::GetLayerInfoForMainMenuDebugJob(
              this: v69,
              jobDebugName: &v13->devMenuRaceDescDecl,
              state: 3,
              layerListActive: &v59,
              layerListDeactive: &v60);
          }
          else
          {
            p_devMenuMissionDecl = &v13->devMenuMissionDecl;
            if ( v13->devMenuMissionDecl.len != 0 )
            {
              devMenuMissionStatus = v13->devMenuMissionStatus;
              if ( devMenuMissionStatus != SIMPLEMISSIONSTATUS_ACCEPTED )
              {
                if ( devMenuMissionStatus == SIMPLEMISSIONSTATUS_READYTOTURNIN )
                {
                  idJobManager::GetLayerInfoForMainMenuDebugJob(
                    this: v69,
                    jobDebugName: p_devMenuMissionDecl,
                    state: 1,
                    layerListActive: &v59,
                    layerListDeactive: &v60);
                }
                else if ( devMenuMissionStatus == SIMPLEMISSIONSTATUS_COMPLETED )
                {
                  idJobManager::GetLayerInfoForMainMenuDebugJob(
                    this: v69,
                    jobDebugName: p_devMenuMissionDecl,
                    state: 2,
                    layerListActive: &v59,
                    layerListDeactive: &v60);
                }
                else
                {
                  idLib::Warning(fmt: "invalid status for job in devmenu layer list  %s   %d", listDecl->name.str, v11);
                }
              }
              else
              {
                idJobManager::GetLayerInfoForMainMenuDebugJob(
                  this: v69,
                  jobDebugName: p_devMenuMissionDecl,
                  state: 0,
                  layerListActive: &v59,
                  layerListDeactive: &v60);
              }
            }
          }
          list = listDecl->devMenuList.list;
          v17 = 0;
          v18 = &list[v12];
          if ( list[v12].devMenuAddActiveLayers.num > 0 )
          {
            v19 = 0;
            do
            {
              idStr::idStr(this: &v64, text: list[v12].devMenuAddActiveLayers.list[v19]->name.str);
              if ( idList<idStr,5>::FindIndex(this: &v59, obj: &v64, startIndex: 0) < 0 )
                idList<idStr,5>::Append(this: &v59, obj: &v64);
              idStr::FreeData(this: &v64);
              list = listDecl->devMenuList.list;
              ++v17;
              v18 = &list[v12];
              ++v19;
            }
            while ( v17 < list[v12].devMenuAddActiveLayers.num );
          }
          v20 = 0;
          if ( v18->devMenuRemoveActiveLayers.num > 0 )
          {
            v21 = 0;
            do
            {
              idStr::idStr(this: &v66, text: list[v12].devMenuRemoveActiveLayers.list[v21]->name.str);
              Index = idList<idStr,5>::FindIndex(this: &v59, obj: &v66, startIndex: 0);
              if ( Index >= 0 )
                idList<idStr,5>::RemoveIndex(this: &v59, index: Index);
              idStr::FreeData(this: &v66);
              list = listDecl->devMenuList.list;
              ++v20;
              ++v21;
            }
            while ( v20 < list[v12].devMenuRemoveActiveLayers.num );
          }
          v23 = v59.num;
          if ( v59.num > *maxLayers )
            *maxLayers = v59.num;
          if ( v23 > 0 )
          {
            v24 = v23;
            v25 = v59.list - 1;
            do
            {
              len = v25[1].len;
              v27 = len > *biggestlayer;
              v61 = len;
              if ( v27 )
                *biggestlayer = len;
              ++v25;
              v8 += v25->len + 1;
              --v24;
            }
            while ( v24 != 0 );
          }
          if ( v8 > *biggestMaxSize )
            *biggestMaxSize = v8;
          v28 = 0;
          v29 = idStrListCombineString(result: &v67, list: &v59, separator: ",");
          v30 = v29->len;
          v31 = &listDecl->devMenuList.list[v12];
          v32 = v29->len + 1;
          p_devMenuActiveLayers = &v31->devMenuActiveLayers;
          allocedAndFlag = v31->devMenuActiveLayers.allocedAndFlag;
          if ( allocedAndFlag >= 0 )
          {
            if ( v32 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: p_devMenuActiveLayers, amount: v32, keepold: false);
          }
          else if ( v32 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: p_devMenuActiveLayers->data, Src: v29->data, Size: v30);
          p_devMenuActiveLayers->data[v30] = 0;
          p_devMenuActiveLayers->len = v30;
          idStr::FreeData(this: &v67);
          v35 = listDecl->devMenuList.list;
          v36 = 0;
          v37 = &v35[v12];
          if ( v35[v12].devMenuAddDeactiveLayers.num > 0 )
          {
            v38 = 0;
            do
            {
              idStr::idStr(this: &v63, text: v35[v12].devMenuAddDeactiveLayers.list[v38]->name.str);
              if ( idList<idStr,5>::FindIndex(this: &v60, obj: &v63, startIndex: 0) < 0 )
                idList<idStr,5>::Append(this: &v60, obj: &v63);
              idStr::FreeData(this: &v63);
              v35 = listDecl->devMenuList.list;
              ++v36;
              v37 = &v35[v12];
              ++v38;
            }
            while ( v36 < v35[v12].devMenuAddDeactiveLayers.num );
          }
          v39 = 0;
          if ( v37->devMenuRemoveDeactiveLayers.num > 0 )
          {
            v40 = 0;
            do
            {
              idStr::idStr(this: &v65, text: v35[v12].devMenuRemoveDeactiveLayers.list[v40]->name.str);
              v41 = idList<idStr,5>::FindIndex(this: &v60, obj: &v65, startIndex: 0);
              if ( v41 >= 0 )
                idList<idStr,5>::RemoveIndex(this: &v60, index: v41);
              idStr::FreeData(this: &v65);
              v35 = listDecl->devMenuList.list;
              ++v39;
              ++v40;
            }
            while ( v39 < v35[v12].devMenuRemoveDeactiveLayers.num );
          }
          v42 = v60.num;
          if ( v60.num > *maxLayers )
            *maxLayers = v60.num;
          if ( v42 > 0 )
          {
            v43 = v42;
            v44 = v60.list - 1;
            do
            {
              v45 = v44[1].len;
              v46 = v45 > *biggestlayer;
              v61 = v45;
              if ( v46 )
                *biggestlayer = v45;
              ++v44;
              v28 += v44->len + 1;
              --v43;
            }
            while ( v43 != 0 );
          }
          if ( v28 > *biggestMaxSize )
            *biggestMaxSize = v28;
          v8 = 0;
          v47 = idStrListCombineString(result: &v68, list: &v60, separator: ",");
          v48 = v47->len;
          v49 = &listDecl->devMenuList.list[v12];
          v50 = v47->len + 1;
          p_devMenuDeactiveLayers = &v49->devMenuDeactiveLayers;
          v52 = v49->devMenuDeactiveLayers.allocedAndFlag;
          if ( v52 >= 0 )
          {
            if ( v50 > (v52 & 0x7FFFFFFF) )
              idStr::ReAllocate(this: p_devMenuDeactiveLayers, amount: v50, keepold: false);
          }
          else if ( v50 > (v52 & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: p_devMenuDeactiveLayers->data, Src: v47->data, Size: v48);
          p_devMenuDeactiveLayers->data[v48] = 0;
          p_devMenuDeactiveLayers->len = v48;
          idStr::FreeData(this: &v68);
          idJobManager::Clear(this: v69);
          if ( v60.listStatic == 0 || v60.listStatic == 2 )
          {
            v53 = v60.list;
            if ( v60.list != nullptr )
            {
              size = v60.size;
              v55 = v60.list;
              if ( v60.size > 0 )
              {
                do
                {
                  idStr::FreeData(this: v53);
                  --size;
                  ++v53;
                }
                while ( size != 0 );
              }
              idMem::Free(this: &mem, ptr: v55, align: ALIGN_16);
            }
            v60.list = nullptr;
            v60.size = 0;
          }
          v60.num = 0;
          if ( v59.listStatic == 0 || v59.listStatic == 2 )
          {
            v56 = v59.list;
            if ( v59.list != nullptr )
            {
              v57 = v59.size;
              v58 = v59.list;
              if ( v59.size > 0 )
              {
                do
                {
                  idStr::FreeData(this: v56);
                  --v57;
                  ++v56;
                }
                while ( v57 != 0 );
              }
              idMem::Free(this: &mem, ptr: v58, align: ALIGN_16);
            }
            v59.list = nullptr;
            v59.size = 0;
          }
          v59.num = 0;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < listDecl->devMenuList.num );
    }
    idDeclTypeInfo::SetState(this: &listDecl->idDeclTypeInfo, empty: &v62->idDeclTypeInfo);
    idDecl::ReplaceSourceFileText(this: &listDecl->idDeclTypeInfo, useSourceControl: true);
    idJobManager::~idJobManager(this: v69);
  }
  else
  {
    idLib::Warning(fmt: "NULL decl passed into CalculateDevMenuLayerInformation");
  }
}


// ========================================================================
// __unwind$501958
// EA  : 0x82E243C8
// RVA : 0x00E243C8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501958()
{
  int v0; // r12

  idJobManager::~idJobManager(this: (idJobManager *)(v0 - 624 + 320));
}


// ========================================================================
// __unwind$501959
// EA  : 0x82E243F0
// RVA : 0x00E243F0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501959()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 624 + 80));
}


// ========================================================================
// __unwind$501960
// EA  : 0x82E24418
// RVA : 0x00E24418
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501960()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 624 + 96));
}


// ========================================================================
// __unwind$501961
// EA  : 0x82E24440
// RVA : 0x00E24440
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 160));
}


// ========================================================================
// __unwind$501962_0
// EA  : 0x82E24468
// RVA : 0x00E24468
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501962_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 224));
}


// ========================================================================
// __unwind$501963
// EA  : 0x82E24490
// RVA : 0x00E24490
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501963()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 256));
}


// ========================================================================
// __unwind$501964
// EA  : 0x82E244B8
// RVA : 0x00E244B8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501964()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 128));
}


// ========================================================================
// __unwind$501965
// EA  : 0x82E244E0
// RVA : 0x00E244E0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501965()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 192));
}


// ========================================================================
// __unwind$501966
// EA  : 0x82E24508
// RVA : 0x00E24508
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void _unwind_501966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 288));
}


// ========================================================================
// ?GenerateAllDevMenuLayerInformation_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E24530
// RVA : 0x00E24530
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall GenerateAllDevMenuLayerInformation_f(const idCmdArgs *args)
{
  int v1; // r27
  int v2; // r22
  int v3; // r23
  int v4; // r30
  int num; // r24
  int v6; // r26
  const char *str; // r4
  idDeclDevMenuList *v8; // r31
  int v9; // [sp+50h] [-70h] BYREF
  int v10; // [sp+54h] [-6Ch] BYREF
  int v11; // [sp+58h] [-68h] BYREF

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  num = idDeclDevMenuList::resourceList.declSources.num;
  if ( idDeclDevMenuList::resourceList.declSources.num > 0 )
  {
    v6 = 0;
    do
    {
      str = idDeclDevMenuList::resourceList.declSources.list[v6]->name.str;
      if ( str != nullptr )
        v8 = (idDeclDevMenuList *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclDevMenuList::resourceList,
                                    name: str,
                                    makeDefault: false);
      else
        v8 = nullptr;
      idLib::Printf(fmt: "%d: %s\n", v4, v8->name.str);
      v9 = 0;
      v10 = 0;
      v11 = 0;
      CalculateDevMenuLayerInformation(listDecl: v8, maxLayers: &v9, biggestlayer: &v10, biggestMaxSize: &v11);
      if ( v9 > v1 )
        v1 = v9;
      if ( v10 > v2 )
        v2 = v10;
      if ( v11 > v3 )
        v3 = v11;
      ++v4;
      ++v6;
    }
    while ( v4 < num );
  }
  idLib::Warning(fmt: "Max layers found for setup is %d", v1);
  idLib::Warning(fmt: "Biggest Layer found is        %d", v2);
  idLib::Warning(fmt: "Biggest Max Size is\t\t   %d", v3);
}


// ========================================================================
// ?GenerateSpecificDevMenuLayerInformation_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E24648
// RVA : 0x00E24648
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __fastcall GenerateSpecificDevMenuLayerInformation_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idDeclDevMenuList *v2; // r3
  int v3; // [sp+50h] [-20h] BYREF
  int v4; // [sp+54h] [-1Ch] BYREF
  int v5; // [sp+58h] [-18h] BYREF

  if ( args->argc == 2 )
  {
    v1 = args->argv[1];
    if ( v1 != nullptr )
      v2 = (idDeclDevMenuList *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclDevMenuList::resourceList,
                                  name: v1,
                                  makeDefault: false);
    else
      v2 = nullptr;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    CalculateDevMenuLayerInformation(listDecl: v2, maxLayers: &v3, biggestlayer: &v4, biggestMaxSize: &v5);
    idLib::Warning(fmt: "Max layers found for setup is %d", v3);
    idLib::Warning(fmt: "Biggest Layer found is        %d", v4);
    idLib::Warning(fmt: "Biggest Max Size is\t\t   %d", v5);
  }
  else
  {
    idLib::Printf(fmt: "usage: GenerateSpecificDevMenuLayerInformation <decl name>\n");
  }
}


// ========================================================================
// `dynamic initializer for 'jobUtil_defaultVolume''
// EA  : 0x83388830
// RVA : 0x01388830
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobUtil_defaultVolume__()
{
  idCVar::idCVar(
    this: &jobUtil_defaultVolume,
    name: "jobUtil_defaultVolume",
    value: "0.01",
    flags: 4,
    description: "volume to set if none in spreadsheet",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobUtil_defaultVolume__);
}


// ========================================================================
// `dynamic initializer for 'jobUtil_minDist''
// EA  : 0x83388888
// RVA : 0x01388888
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobUtil_minDist__()
{
  idCVar::idCVar(
    this: &jobUtil_minDist,
    name: "jobUtil_minDist",
    value: "512.0",
    flags: 4,
    description: "mindist to set if none in spreadsheet",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobUtil_minDist__);
}


// ========================================================================
// `dynamic initializer for 'jobUtil_maxDist''
// EA  : 0x833888E0
// RVA : 0x013888E0
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobUtil_maxDist__()
{
  idCVar::idCVar(
    this: &jobUtil_maxDist,
    name: "jobUtil_maxDist",
    value: "3072.0",
    flags: 4,
    description: "maxdist to set if none in spreadsheet",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobUtil_maxDist__);
}


// ========================================================================
// `dynamic initializer for 'jobUtil_usedefaultValues''
// EA  : 0x83388938
// RVA : 0x01388938
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobUtil_usedefaultValues__()
{
  idCVar::idCVar(
    this: &jobUtil_usedefaultValues,
    name: "jobUtil_usedefaultValues",
    value: "0",
    flags: 1,
    description: "if true use the cvars to overrite already set values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobUtil_usedefaultValues__);
}


// ========================================================================
// `dynamic initializer for 'importingVoiceOversForCombatChatter''
// EA  : 0x83388990
// RVA : 0x01388990
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__importingVoiceOversForCombatChatter__()
{
  idCVar::idCVar(
    this: &importingVoiceOversForCombatChatter,
    name: "importingVoiceOversForCombatChatter",
    value: "0",
    flags: 1,
    description: "if true we're importing voiceovers for combat chatter which uses a different string setup",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__importingVoiceOversForCombatChatter__);
}


// ========================================================================
// `dynamic initializer for 'GenerateAllDevMenuLayerInformation_v''
// EA  : 0x833889E8
// RVA : 0x013889E8
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GenerateAllDevMenuLayerInformation_v__()
{
  return idCommandLink::idCommandLink(
           this: &GenerateAllDevMenuLayerInformation_v,
           cmdName: "GenerateAllDevMenuLayerInformation",
           function: GenerateAllDevMenuLayerInformation_f,
           description: "generates the layer information for all idDeclDevMenuList",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'GenerateSpecificDevMenuLayerInformation_v''
// EA  : 0x83388A10
// RVA : 0x01388A10
// PDB : w:\tech5\tungsten\game\player\jobutils.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GenerateSpecificDevMenuLayerInformation_v__()
{
  return idCommandLink::idCommandLink(
           this: &GenerateSpecificDevMenuLayerInformation_v,
           cmdName: "GenerateSpecificDevMenuLayerInformation",
           function: GenerateSpecificDevMenuLayerInformation_f,
           description: "generates the layer information for a specific idDeclDevMenuList",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclDevMenuList>);
}

