
// ========================================================================
// ?DefaultDefinition@idDeclVisemeSet@@UBAPBDXZ
// EA  : 0x8262C308
// RVA : 0x0062C308
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

const char *__fastcall idDeclVisemeSet::DefaultDefinition(idDeclVisemeSet *this)
{
  return "{\n"
         "\tphonemeSet \"\"\n"
         "\tvisemeSilence viseme_REST\n"
         "\tphonemeSilence x\n"
         "\tvisemes {\n"
         "\t}\n"
         "\tphonemes {\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ??0idViseme@@QAA@XZ
// EA  : 0x8262C318
// RVA : 0x0062C318
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

idViseme *__fastcall idViseme::idViseme(idViseme *this)
{
  this->name.str = &byte_8200D768;
  this->aliasName.str = &byte_8200D768;
  this->viseme = -1;
  return this;
}


// ========================================================================
// ??0idPhoneme@@QAA@XZ
// EA  : 0x8262C338
// RVA : 0x0062C338
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

idPhoneme *__fastcall idPhoneme::idPhoneme(idPhoneme *this)
{
  this->phoneme = -1;
  this->weightScale = 1.0;
  this->viseme = -1;
  this->durationScale = 1.0;
  this->timeOffsetMS = 0;
  this->name.str = &byte_8200D768;
  return this;
}


// ========================================================================
// ?VisemeForName@idDeclVisemeSet@@QBAHPBD@Z
// EA  : 0x8262C370
// RVA : 0x0062C370
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

int __fastcall idDeclVisemeSet::VisemeForName(idDeclVisemeSet *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->visemes.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->visemes.list[i].name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->visemes.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?PhonemeForName@idDeclVisemeSet@@QBAHPBD@Z
// EA  : 0x8262C3E0
// RVA : 0x0062C3E0
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

int __fastcall idDeclVisemeSet::PhonemeForName(idDeclVisemeSet *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->phonemes.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->phonemes.list[i].name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->phonemes.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?FreeData@idDeclVisemeSet@@UAAXXZ
// EA  : 0x8262C4F8
// RVA : 0x0062C4F8
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void __fastcall idDeclVisemeSet::FreeData(idDeclVisemeSet *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->phonemes);
}


// ========================================================================
// ?Size@idDeclVisemeSet@@UBAIXZ
// EA  : 0x8262C530
// RVA : 0x0062C530
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

int __fastcall idDeclVisemeSet::Size(idDeclVisemeSet *this)
{
  return 12 * (2 * (this->phonemes.size + 4) + this->visemes.size);
}


// ========================================================================
// ??0idDeclVisemeSet@@QAA@XZ
// EA  : 0x8262C608
// RVA : 0x0062C608
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

idDeclVisemeSet *__fastcall idDeclVisemeSet::idDeclVisemeSet(idDeclVisemeSet *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclVisemeSet_vtbl *)&idDeclVisemeSet::`vftable';
  this->phonemeSet.len = 0;
  this->phonemeSet.allocedAndFlag = 20;
  this->phonemeSet.data = this->phonemeSet.baseBuffer;
  this->phonemeSet.baseBuffer[0] = 0;
  this->visemes.list = nullptr;
  this->visemes.granularity = 0;
  this->visemes.memTag = 69;
  this->visemes.listStatic = 0;
  this->visemes.size = 0;
  this->visemes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemes);
  this->phonemes.list = nullptr;
  this->phonemes.granularity = 0;
  this->phonemes.memTag = 70;
  this->phonemes.listStatic = 0;
  this->phonemes.size = 0;
  this->phonemes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->phonemes);
  this->silenceViseme = -1;
  this->silencePhoneme = -1;
  return this;
}


// ========================================================================
// __unwind$221146
// EA  : 0x8262C6B0
// RVA : 0x0062C6B0
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221146()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221147
// EA  : 0x8262C6D8
// RVA : 0x0062C6D8
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221147()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$221148
// EA  : 0x8262C704
// RVA : 0x0062C704
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221148()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ??1idDeclVisemeSet@@UAA@XZ
// EA  : 0x8262C748
// RVA : 0x0062C748
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void __fastcall idDeclVisemeSet::~idDeclVisemeSet(idDeclVisemeSet *this)
{
  this->__vftable = (idDeclVisemeSet_vtbl *)&idDeclVisemeSet::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->phonemes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemes);
  idStr::FreeData(this: &this->phonemeSet);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$221210
// EA  : 0x8262C7AC
// RVA : 0x0062C7AC
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221210()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221211
// EA  : 0x8262C7D4
// RVA : 0x0062C7D4
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221211()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$221212
// EA  : 0x8262C800
// RVA : 0x0062C800
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221212()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ?Parse@idDeclVisemeSet@@UAAXAAVidParser@@@Z
// EA  : 0x8262CD60
// RVA : 0x0062CD60
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void __fastcall idDeclVisemeSet::Parse(idDeclVisemeSet *this, idParser *src)
{
  int len; // r29
  int num; // r26
  char *data; // r25
  double v7; // fp30
  double v8; // fp31
  int v9; // r29
  int v10; // r28
  int v11; // r3
  int v12; // r16
  idToken v13; // [sp+50h] [-1D0h] BYREF
  idViseme v14[2]; // [sp+98h] [-188h] BYREF
  idPhoneme v15; // [sp+B0h] [-170h] BYREF
  idStr v16; // [sp+D0h] [-150h] BYREF
  idStr v17; // [sp+F0h] [-130h] BYREF
  idStr v18; // [sp+110h] [-110h] BYREF
  idToken v19; // [sp+130h] [-F0h] BYREF

  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.floatvalue = -3.4028235e38;
  v13.data = v13.baseBuffer;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenString(this: src, string: "phonemeSet");
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13);
  len = v13.len;
  idStr::EnsureAlloced(this: &this->phonemeSet, amount: v13.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->phonemeSet.data, Src: v13.data, Size: len);
  this->phonemeSet.data[len] = 0;
  this->phonemeSet.len = len;
  idParser::ExpectTokenString(this: src, string: "visemeSilence");
  idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v13);
  idStr::idStr(this: &v18, text: &v13);
  idParser::ExpectTokenString(this: src, string: "phonemeSilence");
  idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v13);
  idStr::idStr(this: &v17, text: &v13);
  idParser::ExpectTokenString(this: src, string: "visemes");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v13);
  while ( idParser::ReadToken(this: src, token: &v13) )
  {
    if ( v13.type == 5 )
    {
      if ( v13.subtype == 47 )
        break;
    }
    else if ( v13.type == 4 )
    {
      idToken::idToken(this: &v19, token: &v13);
      idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v13);
      idParser::ExpectTokenString(this: src, string: "alias");
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13);
      num = this->visemes.num;
      data = v13.data;
      idAtomicString::Set(this: &v14[0].name, str_: v19.data);
      idAtomicString::Set(this: &v14[0].aliasName, str_: data);
      v14[0].viseme = num;
      idList<idViseme,69>::Append(this: &this->visemes, obj: v14);
      idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v13);
      idStr::FreeData(this: &v19);
      continue;
    }
    idParser::Error(this: src, str: "Expected a viseme name, read '%s'", v13.data);
  }
  idParser::ExpectTokenString(this: src, string: "phonemes");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v13);
  while ( idParser::ReadToken(this: src, token: &v13) )
  {
    if ( v13.type == 5 )
    {
      if ( v13.subtype == 47 )
        break;
    }
    else if ( v13.type == 4 )
    {
      idStr::idStr(this: &v16, text: &v13);
      v7 = 1.0;
      v8 = 1.0;
      v9 = -1;
      v10 = 0;
      if ( idParser::CheckTokenType(this: src, type: 5, subtype: 46, token: &v13) != 0 )
      {
        while ( idParser::ReadToken(this: src, token: &v13) )
        {
          if ( v13.type == 5 && v13.subtype == 47 )
            break;
          if ( idStr::Icmp(s1: v13.data, s2: "weightScale") != 0 )
          {
            if ( idStr::Icmp(s1: v13.data, s2: "durationScale") != 0 )
            {
              if ( idStr::Icmp(s1: v13.data, s2: "timeOffsetMS") != 0 )
              {
                v11 = idDeclVisemeSet::VisemeForName(this, name: v13.data);
                if ( v11 == -1 )
                {
                  idParser::Error(
                    this: src,
                    str: "Unknown token '%s' in phoneme '%s', expected phoneme property.",
                    v13.data,
                    v16.data);
                }
                else if ( v9 == -1 )
                {
                  v9 = v11;
                }
                else
                {
                  idParser::Error(this: src, str: "Multiple visemes specified in phoneme '%s'", v16.data);
                }
              }
              else
              {
                v10 = idParser::ParseInt(this: src);
              }
            }
            else
            {
              v8 = idParser::ParseFloat(this: src, errorFlag: nullptr);
              if ( v8 < 0.0 )
                idParser::Error(this: src, str: "Negative duration scale in phoneme '%s'", v16.data);
            }
          }
          else
          {
            v7 = idParser::ParseFloat(this: src, errorFlag: nullptr);
            if ( v7 < 0.0 )
              idParser::Error(this: src, str: "Negative weight scale in phoneme '%s'", v16.data);
          }
        }
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 5, subtype: 32, token: &v13);
        idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v13);
        v9 = idDeclVisemeSet::VisemeForName(this, name: v13.data);
        if ( v9 == -1 )
          idParser::Error(this: src, str: "Phoneme '%s' maps to viseme '%s', which does not exist.", v16.data, v13.data);
      }
      v12 = this->phonemes.num;
      idAtomicString::Set(this: &v15.name, str_: v16.data);
      v15.weightScale = v7;
      v15.durationScale = v8;
      v15.phoneme = v12;
      v15.viseme = v9;
      v15.timeOffsetMS = v10;
      idList<idPhoneme,70>::Append(this: &this->phonemes, obj: &v15);
      idStr::FreeData(this: &v16);
      continue;
    }
    idParser::Error(this: src, str: "Expected a phoneme name, but read '%s'", v13.data);
  }
  idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v13);
  this->silenceViseme = idDeclVisemeSet::VisemeForName(this, name: v18.data);
  this->silencePhoneme = idDeclVisemeSet::PhonemeForName(this, name: v17.data);
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: &v18);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// $M221537_0
// EA  : 0x8262D2D0
// RVA : 0x0062D2D0
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _M221537_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 80));
}


// ========================================================================
// __unwind$221300
// EA  : 0x8262D2F8
// RVA : 0x0062D2F8
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221300()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 272));
}


// ========================================================================
// __unwind$221301
// EA  : 0x8262D320
// RVA : 0x0062D320
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221301()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$221302
// EA  : 0x8262D348
// RVA : 0x0062D348
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 304));
}


// ========================================================================
// __unwind$221303
// EA  : 0x8262D370
// RVA : 0x0062D370
// PDB : w:\tech5\engine\decls\voiceovers\declvisemeset.cpp
// ========================================================================

void _unwind_221303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 208));
}

