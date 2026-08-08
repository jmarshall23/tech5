
// ========================================================================
// ?GetNextEntry@idSoundShader@@QBAPAVidSoundSample@@_N@Z
// EA  : 0x82990108
// RVA : 0x00990108
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

idSoundSample *__fastcall idSoundShader::GetNextEntry(idSoundShader *this, const bool preTouchData)
{
  int num; // r4
  soundShaderFlags_t soundShaderFlags; // r10
  idSoundSample *v7; // r31
  int v8; // r4
  int v9; // r3
  int v10; // r30
  int v11; // r10
  int v12; // r11
  idSoundSample *nextSample; // r30

  num = this->entries.num;
  if ( num == 0 )
    return nullptr;
  soundShaderFlags = this->parms.soundShaderFlags;
  if ( (soundShaderFlags & 0x100000) != 0 )
  {
    v7 = this->entries.list[idRandom2::RandomInt(this: &soundSystemLocal.random, max: num)];
    idSoundSample_XAudio2::PreCacheStreamData(this: v7, highPriority: true);
    return v7;
  }
  else
  {
    if ( this->nextSample == nullptr )
    {
      if ( (soundShaderFlags & 0x800) != 0 )
        this->nextSample = *this->entries.list;
      else
        this->nextSample = this->entries.list[idRandom2::RandomInt(this: &soundSystemLocal.random, max: num)];
    }
    v8 = this->entries.num;
    v9 = 0;
    if ( v8 != 1 )
    {
      if ( v8 == 2 )
      {
        soundSystemLocal.random.seed = 1664525 * soundSystemLocal.random.seed + 1013904223;
        v9 = ((soundSystemLocal.random.seed >> 10) & 0x7FFF)
           - 2 * ((signed int)((soundSystemLocal.random.seed >> 10) & 0x7FFF) >> 1);
      }
      else
      {
        v10 = -1;
        v11 = 0;
        if ( v8 > 0 )
        {
          v12 = 0;
          while ( this->nextSample != this->entries.list[v12] )
          {
            ++v11;
            ++v12;
            if ( v11 >= v8 )
              goto LABEL_18;
          }
          v10 = v11;
        }
LABEL_18:
        if ( (this->parms.soundShaderFlags & 0x800) != 0 )
        {
          __twllei(v8, 0);
          v9 = (v10 + 1) % v8;
          __twlgei(v8 & ~(__ROL4__(v10 + 1, 1) - 1), 0xFFFFFFFF);
        }
        else if ( v10 >= 0 )
        {
          v9 = idRandom2::RandomInt(this: &soundSystemLocal.random, max: v8 - 1);
          if ( v9 >= v10 )
            ++v9;
        }
        else
        {
          v9 = idRandom2::RandomInt(this: &soundSystemLocal.random, max: v8);
        }
      }
    }
    nextSample = this->nextSample;
    this->nextSample = this->entries.list[v9];
    if ( preTouchData )
    {
      idSoundSample_XAudio2::PreCacheStreamData(this: nextSample, highPriority: true);
      idSoundSample_XAudio2::PreCacheStreamData(this: this->nextSample, highPriority: false);
    }
    return nextSample;
  }
}


// ========================================================================
// ?List@idSoundSample@@UBAXXZ
// EA  : 0x82990488
// RVA : 0x00990488
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idSoundSample::List(idSoundSample *this)
{
  unsigned int samplesPerSec; // r10
  __int128 v2; // r11
  double v3; // r5
  double v4; // r7

  samplesPerSec = this->format.basic.samplesPerSec;
  if ( samplesPerSec >= 0x64 )
    __twllei(samplesPerSec / 0x64, 0);
  DWORD1(v2) = this->name.str;
  *((_QWORD *)&v2 + 1) = __PAIR64__(this->staticBufferSize, samplesPerSec);
  v3 = (float)((float)(__int64)v2 * (float)0.001);
  v4 = (float)((float)*(__int64 *)((char *)&v2 + 4) * (float)0.0009765625);
  idLib::Printf(
    fmt: "%s %2.2fkHz \t%6dms \t%5.1fkB %c %s\n",
    (const char *)HIDWORD(v3),
    v3,
    LODWORD(v3),
    v4,
    HIDWORD(v4),
    (const char *)LODWORD(v4));
}


// ========================================================================
// ?FreeData@idSoundShader@@UAAXXZ
// EA  : 0x829905B8
// RVA : 0x009905B8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idSoundShader::FreeData(idSoundShader *this)
{
  soundShaderParms_t::Clear(this: &this->parms);
  this->parms.minDistance = 128.0;
  this->parms.maxDistance = 1024.0;
  this->parms.lfeVolume = -6.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->soundFiles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entries);
}


// ========================================================================
// ?SetImplicitText@idSoundShader@@UAA_NXZ
// EA  : 0x82990628
// RVA : 0x00990628
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

int __fastcall idSoundShader::SetImplicitText(idSoundShader *this)
{
  __int64 v2; // r10
  __int64 v3; // r6
  __int64 v4; // r8
  va *v5; // r3
  int v7; // [sp+8h] [-10A8h]
  int v8; // [sp+Ch] [-10A4h]
  int v9; // [sp+10h] [-10A0h]
  int v10; // [sp+14h] [-109Ch]
  int v11; // [sp+18h] [-1098h]
  int v12; // [sp+1Ch] [-1094h]
  idStr v13; // [sp+50h] [-1060h] BYREF
  idStr v14; // [sp+70h] [-1040h] BYREF
  va v15; // [sp+90h] [-1020h] BYREF

  idStr::idStr(this: &v13, text: this->name.str);
  idStr::DefaultFileExtension(this: &v13, extension: ".wav");
  LODWORD(v2) = "olor specular";
  HIDWORD(v3) = v13.data;
  v5 = va::va(
         this: &v15,
         fmt: "{ // IMPLICITLY GENERATED\n"
         "\tedit = {\n"
         "\t\tsoundFiles = {\n"
         "\t\t\tnum = 1;\n"
         "\t\t\titem[0] = \"%s\";\n"
         "\t\t}\n"
         "\t}\n"
         "}\n",
         a3: v3,
         a4: v4,
         a5: v2,
         a6: v7,
         a7: v8,
         a8: v9,
         a9: v10,
         a10: v11,
         a11: v12);
  idStr::idStr(this: &v14, text: v5);
  idDecl::SetText(this: &this->idDeclTypeInfo, text: v14.data, length: 0);
  idStr::FreeData(this: &v14);
  idStr::FreeData(this: &v13);
  return 1;
}


// ========================================================================
// __unwind$225389
// EA  : 0x829906C0
// RVA : 0x009906C0
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225389()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 80));
}


// ========================================================================
// __unwind$225390
// EA  : 0x829906E8
// RVA : 0x009906E8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225390()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 112));
}


// ========================================================================
// ?List@idSoundShader@@UBAXXZ
// EA  : 0x82990710
// RVA : 0x00990710
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idSoundShader::List(idSoundShader *this)
{
  const char *str; // r5
  unsigned int v3; // r9
  int v4; // r11
  int num; // ctr
  idSoundSample *v6; // r10
  double v7; // r4
  int v8; // r29
  int v9; // r31
  idSoundSample *v10; // r10

  str = this->name.str;
  v3 = 0;
  if ( this->entries.num > 0 )
  {
    v4 = 0;
    num = this->entries.num;
    do
    {
      v6 = this->entries.list[v4];
      if ( v6 != nullptr )
        v3 += v6->staticBufferSize;
      ++v4;
      --num;
    }
    while ( num != 0 );
  }
  v7 = (float)((float)__SPAIR64__(&unk_821D0000, v3) * (float)0.0009765625);
  idLib::Printf(fmt: (const char *)HIDWORD(v7), LODWORD(v7), str);
  v8 = 0;
  if ( this->entries.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->entries.list[v9];
      if ( v10 != nullptr )
        ((void (*)(void))v10->List)();
      ++v8;
      ++v9;
    }
    while ( v8 < this->entries.num );
  }
}


// ========================================================================
// ?GetMaxLength@idSoundShader@@QBAHXZ
// EA  : 0x829907E8
// RVA : 0x009907E8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

int __fastcall idSoundShader::GetMaxLength(idSoundShader *this)
{
  soundShaderFlags_t soundShaderFlags; // r11
  int num; // r11
  int result; // r3
  idSoundSample **list; // r6
  int v6; // r8
  int i; // ctr
  _DWORD *v8; // r11
  unsigned int v9; // r10
  signed int v10; // r11
  int v11; // r9
  int v12; // r11

  soundShaderFlags = this->parms.soundShaderFlags;
  if ( (soundShaderFlags & 0x200) != 0 || (soundShaderFlags & 0x100000) != 0 )
    return 0;
  num = this->entries.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->entries.list;
    v6 = 0;
    for ( i = num; i != 0; --i )
    {
      v8 = &list[v6]->__vftable;
      if ( v8 != nullptr )
      {
        v9 = v8[24];
        if ( v9 >= 0x64 )
        {
          v11 = v8[12];
          v12 = v8[11];
          __twllei(v9 / 0x64, 0);
          v10 = 10 * (v11 + v12) / (v9 / 0x64);
        }
        else
        {
          v10 = 0;
        }
        if ( v10 > result )
          result = v10;
      }
      ++v6;
    }
  }
  return result;
}


// ========================================================================
// ?Parse@idDeclDuck@@UAAXAAVidParser@@@Z
// EA  : 0x82990898
// RVA : 0x00990898
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idDeclDuck::Parse(idDeclDuck *this, idParser *src)
{
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v5; // r17
  unsigned int intvalue; // r11
  const enumValueInfo_t *EnumValueInfo; // r26
  double v8; // fp31
  int v9; // r30
  float *groupVolume; // r28
  int i; // r29
  double floatvalue; // fp0
  idStr v13; // [sp+50h] [-110h] BYREF
  idToken v14; // [sp+70h] [-F0h] BYREF

  EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "soundShaderGroups_t");
  v14.len = 0;
  v14.allocedAndFlag = 20;
  v5 = EnumInfo;
  v14.data = v14.baseBuffer;
  v14.floatvalue = -3.4028235e38;
  v14.baseBuffer[0] = 0;
  v14.intvalue = 0;
  memset(&v14.whiteSpaceStart_p, 0, 12);
  while ( idParser::ReadToken(this: src, token: &v14) )
  {
    if ( idStr::Cmp(s1: v14.data, s2: "}") == 0 )
      break;
    if ( idStr::Icmp(s1: v14.data, s2: "layer") != 0 )
    {
      idStr::idStr(this: &v13, text: "SSG_");
      idStr::Append(this: &v13, text: &v14);
      idStr::ToUpper(this: &v13);
      EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                        this: typeInfoTools,
                        enumInfo: v5,
                        name: v13.data,
                        defaultIfNotFound: false);
      if ( EnumValueInfo != nullptr )
      {
        idParser::ExpectTokenString(this: src, string: "=");
        v8 = 1.0;
        if ( idParser::CheckTokenType(this: src, type: 5, subtype: 31, token: &v14) != 0 )
          v8 = -1.0;
        idParser::ExpectTokenType(this: src, type: 3, subtype: 0, token: &v14);
        v9 = 1;
        groupVolume = this->groupVolume;
        for ( i = 25; i != 0; --i )
        {
          if ( (EnumValueInfo->value & v9) != 0 )
          {
            if ( v14.type == 3 )
            {
              if ( (v14.subtype & 0x10000) == 0 )
                idToken::NumberValue(this: &v14);
              floatvalue = v14.floatvalue;
            }
            else
            {
              floatvalue = 0.0;
            }
            *groupVolume = (float)floatvalue * (float)v8;
          }
          ++groupVolume;
          v9 = __ROL4__(v9, 1);
        }
        idParser::CheckTokenType(this: src, type: 5, subtype: 41, token: &v14);
      }
      else
      {
        idParser::Warning(this: src, str: "Unknown group %s", v14.data);
        idParser::ExpectTokenString(this: src, string: "=");
        idParser::CheckTokenType(this: src, type: 5, subtype: 31, token: &v14);
        idParser::ExpectTokenType(this: src, type: 3, subtype: 0, token: &v14);
        idParser::CheckTokenType(this: src, type: 5, subtype: 41, token: &v14);
      }
      idStr::FreeData(this: &v13);
    }
    else
    {
      idParser::ExpectTokenString(this: src, string: "=");
      idParser::ExpectTokenType(this: src, type: 3, subtype: 1, token: &v14);
      if ( v14.type == 3 )
      {
        if ( (v14.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v14);
        intvalue = v14.intvalue;
      }
      else
      {
        intvalue = 0;
      }
      this->layer = intvalue;
      idParser::CheckTokenType(this: src, type: 5, subtype: 41, token: &v14);
    }
  }
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$225543
// EA  : 0x82990B84
// RVA : 0x00990B84
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225543()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$225544
// EA  : 0x82990BAC
// RVA : 0x00990BAC
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225544()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 80));
}


// ========================================================================
// ?RebuildTextSource@idDeclDuck@@UAA_NXZ
// EA  : 0x82990BE0
// RVA : 0x00990BE0
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

int __fastcall idDeclDuck::RebuildTextSource(idDeclDuck *this)
{
  const enumTypeInfo_t *EnumInfo; // r26
  int v3; // r29
  float *groupVolume; // r30
  int i; // r27
  const enumValueInfo_t *EnumValueInfo; // r11
  idStr v8; // [sp+50h] [-1D0h] BYREF
  idFile_Memory v9; // [sp+70h] [-1B0h] BYREF

  idFile_Memory::idFile_Memory(this: &v9);
  idFile::WriteFloatString(this: &v9, fmt: "{\n");
  EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "soundShaderGroups_t");
  idFile::WriteFloatString(this: &v9, fmt: "layer = %d\n", this->layer);
  v3 = 1;
  groupVolume = this->groupVolume;
  for ( i = 25; i != 0; --i )
  {
    if ( *groupVolume != 0.0 )
    {
      EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this: typeInfoTools, enumInfo: EnumInfo, value: v3);
      if ( EnumValueInfo != nullptr )
      {
        idStr::idStr(this: &v8, text: EnumValueInfo->name);
        idStr::StripLeading(this: &v8, string: "SSG_");
        idStr::ToLower(this: &v8);
        idFile::WriteFloatString(this: &v9, fmt: "%s = %f\n", v8.data, *groupVolume);
        idStr::FreeData(this: &v8);
      }
    }
    ++groupVolume;
    v3 = __ROL4__(v3, 1);
  }
  idFile::WriteFloatString(this: &v9, fmt: "}");
  idDecl::SetText(this: &this->idDecl, text: v9.filePtr, length: 0);
  idFile_Memory::~idFile_Memory(this: &v9);
  return 1;
}


// ========================================================================
// __unwind$225672
// EA  : 0x82990D14
// RVA : 0x00990D14
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225672()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 544 + 112));
}


// ========================================================================
// __unwind$225673
// EA  : 0x82990D3C
// RVA : 0x00990D3C
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225673()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 80));
}


// ========================================================================
// ??0idSoundShader@@QAA@XZ
// EA  : 0x82990D70
// RVA : 0x00990D70
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

idSoundShader *__fastcall idSoundShader::idSoundShader(idSoundShader *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idSoundShader_vtbl *)&idSoundShader::`vftable';
  soundShaderParms_t::Clear(this: &this->parms);
  this->soundFiles.list = nullptr;
  this->soundFiles.granularity = 0;
  this->soundFiles.memTag = 38;
  this->soundFiles.listStatic = 0;
  this->soundFiles.size = 0;
  this->soundFiles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->soundFiles);
  this->entries.memTag = 38;
  this->entries.list = nullptr;
  this->entries.granularity = 0;
  this->entries.listStatic = 0;
  this->entries.size = 0;
  this->entries.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entries);
  this->playingChannels.owner = nullptr;
  this->playingChannels.head = &this->playingChannels;
  this->playingChannels.next = &this->playingChannels;
  this->playingChannels.prev = &this->playingChannels;
  this->nextSample = nullptr;
  this->preSound = nullptr;
  this->postSound = nullptr;
  this->remoteSound = nullptr;
  soundShaderParms_t::Clear(this: &this->parms);
  this->parms.minDistance = 128.0;
  this->parms.maxDistance = 1024.0;
  this->parms.lfeVolume = -6.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->soundFiles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entries);
  return this;
}


// ========================================================================
// __unwind$225737
// EA  : 0x82990E6C
// RVA : 0x00990E6C
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225737()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$225738
// EA  : 0x82990E94
// RVA : 0x00990E94
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225738()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 212));
}


// ========================================================================
// __unwind$225739
// EA  : 0x82990EC0
// RVA : 0x00990EC0
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225739()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 228));
}


// ========================================================================
// __unwind$225740
// EA  : 0x82990EEC
// RVA : 0x00990EEC
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225740()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 260));
}


// ========================================================================
// ??1idSoundShader@@UAA@XZ
// EA  : 0x82990F30
// RVA : 0x00990F30
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idSoundShader::~idSoundShader(idSoundShader *this)
{
  this->__vftable = (idSoundShader_vtbl *)&idSoundShader::`vftable';
  this->nextSample = nullptr;
  this->preSound = nullptr;
  this->postSound = nullptr;
  this->remoteSound = nullptr;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->playingChannels);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->soundFiles);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$225794_0
// EA  : 0x82990FA8
// RVA : 0x00990FA8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225794_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$225795
// EA  : 0x82990FD0
// RVA : 0x00990FD0
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void _unwind_225795()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 212));
}


// ========================================================================
// ?Parse@idSoundShader@@UAAXAAVidParser@@@Z
// EA  : 0x829911A8
// RVA : 0x009911A8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __fastcall idSoundShader::Parse(idSoundShader *this, idParser *src)
{
  int v3; // r30
  int v4; // r31
  char *str; // r11
  char v6; // r11
  bool v7; // zf
  int num; // r31
  idList<idSoundSample *,38> *p_entries; // r29
  int v10; // r30
  idStrSound *v11; // r11
  char v12; // r10
  idResource *v13; // [sp+50h] [-50h] BYREF

  idDeclTypeInfo::Parse(this: &this->idDeclTypeInfo, src);
  if ( function_t::Name(this: &this->idDeclTypeInfo) != nullptr )
  {
    v3 = this->soundFiles.num - 1;
    if ( v3 >= 0 )
    {
      v4 = v3;
      do
      {
        str = (char *)this->soundFiles.list[v4].str;
        if ( str == &byte_8200D768 || (v7 = *str != 0, v6 = 0, !v7) )
          v6 = 1;
        if ( v6 != 0 )
          idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
            this: (idList<idEntityPtr<idEntity>,58> *)&this->soundFiles,
            index: v3);
        --v3;
        --v4;
      }
      while ( v3 >= 0 );
    }
  }
  num = this->soundFiles.num;
  if ( s_noSound.valueInteger != 0 )
  {
    num = 0;
  }
  else if ( s_maxSamples.valueInteger > 0 && s_maxSamples.valueInteger < num )
  {
    num = s_maxSamples.valueInteger;
  }
  p_entries = &this->entries;
  if ( this->entries.listStatic == 0 || this->entries.listStatic == 2 )
  {
    if ( p_entries->list != nullptr )
      idMem::Free(this: &mem, ptr: p_entries->list, align: ALIGN_16);
    p_entries->list = nullptr;
    this->entries.size = 0;
  }
  this->entries.num = 0;
  if ( num > this->entries.size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->entries, newsize: num);
  if ( num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = &this->soundFiles.list[v10];
      if ( v11->str == &byte_8200D768 || (v12 = 0, *v11->str == 0) )
        v12 = 1;
      if ( v12 == 0 )
      {
        v13 = idResourceList::Load(
                this: &idSoundSample::resourceList,
                name: (char *)v11->str,
                makeDefault: true,
                skipStaleCheck: false);
        if ( v13 != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->entries,
            obj: (const encounterGroupRole_t *)&v13);
      }
      --num;
      ++v10;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// `dynamic initializer for 'idSoundSample::resourceList''
// EA  : 0x833607B8
// RVA : 0x013607B8
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idSoundSample::resourceList__()
{
  idResourceList::idResourceList(this: &idSoundSample::resourceList, typeName: "sample");
  idSoundSample::resourceList.__vftable = (idTypedResourceList<idSoundSample>_vtbl *)&idTypedResourceList<idSoundSample>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idSoundSample::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'idSoundShader::resourceList''
// EA  : 0x83360808
// RVA : 0x01360808
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idSoundShader::resourceList__()
{
  idDeclInfo::idDeclInfo(
    this: &idSoundShader::resourceList,
    identifier: "sound",
    classname: "idSoundShader",
    fileExt: "sndshd");
  idSoundShader::resourceList.__vftable = (idDeclInfoTemplate<idSoundShader>_vtbl *)&idDeclInfoTemplate<idSoundShader>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idSoundShader::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'idDeclDuck::resourceList''
// EA  : 0x83360868
// RVA : 0x01360868
// PDB : w:\tech5\engine\sound\soundshader.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclDuck::resourceList__()
{
  idDeclInfo::idDeclInfo(
    this: &idDeclDuck::resourceList,
    identifier: "duck",
    classname: "idDeclDuck",
    fileExt: "sndshd");
  idDeclDuck::resourceList.__vftable = (idDeclInfoTemplate<idDeclDuck>_vtbl *)&idDeclInfoTemplate<idDeclDuck>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclDuck::resourceList__);
}

