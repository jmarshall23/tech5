
// ========================================================================
// ?IsEnum@idAIActionParm@@QBA_NXZ
// EA  : 0x82A3B9A8
// RVA : 0x00A3B9A8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idAIActionParm::IsEnum(idAIActionParm *this)
{
  return *((unsigned __int8 *)&idAIActionParm::subParmInfo[0].isEnum + __ROL4__(this->subType, 4));
}


// ========================================================================
// ??0idActionScriptConvertor@@QAA@XZ
// EA  : 0x82A3C1B8
// RVA : 0x00A3C1B8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

idActionScriptConvertor *__fastcall idActionScriptConvertor::idActionScriptConvertor(idActionScriptConvertor *this)
{
  this->buffer = nullptr;
  idLexer::idLexer(this: &this->src, flags_: 262704);
  idFile_Memory::idFile_Memory(this: &this->out, name: "*unknown*");
  this->out.__vftable = (idFile_String_vtbl *)&idFile_String::`vftable';
  this->startPos = nullptr;
  this->numScripts = 0;
  this->fileType = FT_MAX;
  return this;
}


// ========================================================================
// __unwind$489354
// EA  : 0x82A3C220
// RVA : 0x00A3C220
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_489354()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?Begin@idActionScriptConvertor@@AAA_NPBDI0@Z
// EA  : 0x82A3C250
// RVA : 0x00A3C250
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::Begin(
        idActionScriptConvertor *this,
        const char *buffer,
        unsigned int length,
        const char *fileName)
{
  idLexer *p_src; // r30

  p_src = &this->src;
  if ( this->src.loaded )
    idLexer::FreeSource(this: &this->src);
  if ( !idLexer::LoadMemory(this: p_src, ptr: buffer, length_: length, name: fileName) )
    return 0;
  this->out.Clear(this: &this->out, a2: true);
  this->startPos = buffer;
  this->numScripts = 0;
  return 1;
}


// ========================================================================
// ?BeginFile@idActionScriptConvertor@@AAA_NPBD@Z
// EA  : 0x82A3C2E0
// RVA : 0x00A3C2E0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::BeginFile(idActionScriptConvertor *this, const char *fileName)
{
  signed int v4; // r5

  v4 = fileSystem->ReadFile(this: fileSystem, a2: fileName, a3: (void **)this, a4: nullptr);
  if ( v4 > 0 )
  {
    if ( (unsigned __int8)idActionScriptConvertor::Begin(this, buffer: this->buffer, length: v4, fileName) != 0 )
    {
      idLib::Printf(fmt: "Parsing '%s'...", fileName);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Error lexing file.");
      fileSystem->FreeFile(this: fileSystem, a2: this->buffer);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "Error reading file.");
    return 0;
  }
}


// ========================================================================
// ?ConvertActionParm@idActionScriptConvertor@@AAAXHABVidStr@@AAVidAIActionParm@@@Z
// EA  : 0x82A3C428
// RVA : 0x00A3C428
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall idActionScriptConvertor::ConvertActionParm(
        idActionScriptConvertor *this,
        const int index,
        const idStr *argType,
        idAIActionParm *parm)
{
  idGame *v7; // r3
  int v8; // r3
  int v9; // r30
  idTypeInfoTools *v10; // r26
  idLexer *p_src; // r24
  BOOL v12; // r30
  int v13; // r29
  long double v14; // fp2
  char *v15; // r30
  char *v16; // r30
  char *v17; // r30
  const idDeclVoiceOver *v18; // r3
  const idSoundShader *v19; // r3
  const idDeclAmmo *v20; // r3
  const idDeclWeapon *v21; // r3
  char *data; // r30
  const enumTypeInfo_t *EnumInfo; // r27
  const enumValueInfo_t *values; // r11
  int value; // r26
  int v26; // r29
  int v27; // r3
  idToken v28; // [sp+50h] [-190h] BYREF
  idVec3 v29[2]; // [sp+98h] [-148h] BYREF
  idToken v30; // [sp+B0h] [-130h] BYREF
  idAngles v31[2]; // [sp+F8h] [-E8h] BYREF
  idLexer v32; // [sp+110h] [-D0h] BYREF

  v7 = common->Game(this: common);
  v8 = (int)v7->GetTypeInfoTools(this: v7);
  v9 = 0;
  v30.len = 0;
  v30.allocedAndFlag = 20;
  v10 = (idTypeInfoTools *)v8;
  v30.data = v30.baseBuffer;
  v30.floatvalue = -3.4028235e38;
  v30.baseBuffer[0] = 0;
  v30.intvalue = 0;
  memset(&v30.whiteSpaceStart_p, 0, 12);
  v28.floatvalue = -3.4028235e38;
  v28.allocedAndFlag = 20;
  v28.data = v28.baseBuffer;
  v28.len = 0;
  v28.baseBuffer[0] = 0;
  v28.intvalue = 0;
  memset(&v28.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ExpectTokenType(this: &this->src, type: 1, subtype: 0, token: &v28);
  idLexer::ExpectTokenType(this: &this->src, type: 5, subtype: 41, token: &v30);
  if ( idStr::Cmp(s1: argType->data, s2: "bool") != 0 )
  {
    if ( idStr::Cmp(s1: argType->data, s2: "int") != 0 )
    {
      if ( idStr::Cmp(s1: argType->data, s2: "float") != 0 )
      {
        if ( idStr::Cmp(s1: argType->data, s2: "idVec3&") != 0 )
        {
          if ( idStr::Cmp(s1: argType->data, s2: "idAngles&") != 0 )
          {
            if ( idStr::Cmp(s1: argType->data, s2: "char*") != 0 )
            {
              if ( idStr::Cmp(s1: argType->data, s2: "idAnimWebPath&") != 0 )
              {
                if ( idStr::Cmp(s1: argType->data, s2: "aliasHandle_t") != 0 )
                {
                  if ( idStr::Cmp(s1: argType->data, s2: "idDeclVoiceOver*") != 0 )
                  {
                    if ( idStr::Cmp(s1: argType->data, s2: "idSoundShader*") != 0 )
                    {
                      if ( idStr::Cmp(s1: argType->data, s2: "idDeclAmmo*") != 0 )
                      {
                        if ( idStr::Cmp(s1: argType->data, s2: "idDeclWeapon*") != 0 )
                        {
                          if ( idStr::Cmp(s1: argType->data, s2: "idEntity*") != 0 )
                          {
                            EnumInfo = idTypeInfoTools::FindEnumInfo(this: v10, typeName: argType->data);
                            if ( EnumInfo == nullptr )
                              idLexer::Error(this: &this->src, str: "Unknown enum type '%s'", argType->data);
                            values = EnumInfo->values;
                            value = 0x80000000;
                            v26 = 0;
                            if ( values->name != nullptr )
                            {
                              while ( 1 )
                              {
                                v27 = idStr::Cmp(s1: values[v9].name, s2: v28.data);
                                values = EnumInfo->values;
                                if ( v27 == 0 )
                                  break;
                                v9 = ++v26;
                                if ( values[v26].name == nullptr )
                                  goto LABEL_42;
                              }
                              value = values[v9].value;
                            }
LABEL_42:
                            idAIActionParm::Clear(this: parm);
                            if ( value == 0x80000000 )
                            {
                              if ( idStr::Cmp(s1: v28.data, s2: "AIPLAYER_1") != 0 )
                                idLexer::Error(this: p_src, str: "Unknown enum value '%s'", v28.data);
                              else
                                idAIActionParm::Set(this: parm, in: 0);
                            }
                            if ( parm->type == 0 )
                            {
                              if ( idStr::Cmp(s1: argType->data, s2: "aiArrivalAction_t") != 0 )
                              {
                                if ( idStr::Cmp(s1: argType->data, s2: "posture_t") != 0 )
                                {
                                  if ( idStr::Cmp(s1: argType->data, s2: "coverAction_t") != 0 )
                                  {
                                    if ( idStr::Cmp(s1: argType->data, s2: "equipSlot_t") != 0 )
                                    {
                                      if ( idStr::Cmp(s1: argType->data, s2: "alertCycle_t") != 0 )
                                      {
                                        if ( idStr::Cmp(s1: argType->data, s2: "aiFireMode_t") != 0 )
                                        {
                                          if ( idStr::Cmp(s1: argType->data, s2: "aimPoint_t") != 0 )
                                          {
                                            if ( idStr::Cmp(s1: argType->data, s2: "walkState_t") != 0 )
                                            {
                                              if ( idStr::Cmp(s1: argType->data, s2: "aiPlayer_t") != 0 )
                                              {
                                                if ( idStr::Cmp(s1: argType->data, s2: "overrideAnim_t") != 0 )
                                                {
                                                  if ( idStr::Cmp(s1: argType->data, s2: "painType_t") != 0 )
                                                  {
                                                    if ( idStr::Cmp(s1: argType->data, s2: "aiDirection_t") != 0 )
                                                    {
                                                      if ( idStr::Cmp(s1: argType->data, s2: "aiDodgeDir_t") != 0 )
                                                      {
                                                        if ( idStr::Cmp(s1: argType->data, s2: "aiSubWeb_t") != 0 )
                                                        {
                                                          if ( idStr::Cmp(s1: argType->data, s2: "aiActionBool_t") != 0 )
                                                            idLexer::Error(
                                                              this: p_src,
                                                              str: "Unsupported enum type '%s'",
                                                              argType->data);
                                                          else
                                                            idAIActionParm::Set(this: parm, in: value != 0);
                                                        }
                                                        else
                                                        {
                                                          idAIActionParm::Set(this: parm, in: value);
                                                        }
                                                      }
                                                      else
                                                      {
                                                        idAIActionParm::Set(this: parm, in: value);
                                                      }
                                                    }
                                                    else
                                                    {
                                                      idAIActionParm::Set(this: parm, in: value);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    idAIActionParm::Set(this: parm, in: value);
                                                  }
                                                }
                                                else
                                                {
                                                  idAIActionParm::Set(this: parm, in: value);
                                                }
                                              }
                                              else
                                              {
                                                idAIActionParm::Set(this: parm, in: value);
                                              }
                                            }
                                            else
                                            {
                                              idAIActionParm::Set(this: parm, in: value);
                                            }
                                          }
                                          else
                                          {
                                            idAIActionParm::Set(this: parm, in: value);
                                          }
                                        }
                                        else
                                        {
                                          idAIActionParm::Set(this: parm, in: value);
                                        }
                                      }
                                      else
                                      {
                                        idAIActionParm::Set(this: parm, in: value);
                                      }
                                    }
                                    else
                                    {
                                      idAIActionParm::Set(this: parm, in: value);
                                    }
                                  }
                                  else
                                  {
                                    idAIActionParm::Set(this: parm, in: value);
                                  }
                                }
                                else
                                {
                                  idAIActionParm::Set(this: parm, in: value);
                                }
                              }
                              else
                              {
                                idAIActionParm::Set(this: parm, in: value);
                              }
                            }
                          }
                          else
                          {
                            data = v28.data;
                            idAIActionParm::Clear(this: parm);
                            parm->type = 3;
                            parm->subType = 23;
                            idStr::operator=(this: &parm->strVal, text: data);
                          }
                        }
                        else if ( v28.data != nullptr )
                        {
                          v21 = (const idDeclWeapon *)idDeclInfo::FindWithInheritance(
                                                        this: &idDeclWeapon::resourceList,
                                                        name: v28.data,
                                                        makeDefault: true);
                          idAIActionParm::Set(this: parm, decl: v21);
                        }
                        else
                        {
                          idAIActionParm::Set(this: parm, decl: nullptr);
                        }
                      }
                      else if ( v28.data != nullptr )
                      {
                        v20 = (const idDeclAmmo *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclAmmo::resourceList,
                                                    name: v28.data,
                                                    makeDefault: true);
                        idAIActionParm::Set(this: parm, decl: v20);
                      }
                      else
                      {
                        idAIActionParm::Set(this: parm, decl: nullptr);
                      }
                    }
                    else if ( v28.data != nullptr )
                    {
                      v19 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                                     this: &idSoundShader::resourceList,
                                                     name: v28.data,
                                                     makeDefault: true);
                      idAIActionParm::Set(this: parm, ss: v19);
                    }
                    else
                    {
                      idAIActionParm::Set(this: parm, ss: nullptr);
                    }
                  }
                  else if ( v28.data != nullptr )
                  {
                    v18 = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                     this: &idDeclVoiceOver::resourceList,
                                                     name: v28.data,
                                                     makeDefault: true);
                    idAIActionParm::Set(this: parm, vo: v18);
                  }
                  else
                  {
                    idAIActionParm::Set(this: parm, vo: nullptr);
                  }
                }
                else
                {
                  v17 = v28.data;
                  idAIActionParm::Clear(this: parm);
                  parm->type = 3;
                  parm->subType = 21;
                  idStr::operator=(this: &parm->strVal, text: v17);
                }
              }
              else
              {
                v16 = v28.data;
                idAIActionParm::Clear(this: parm);
                parm->type = 3;
                parm->subType = 22;
                idStr::operator=(this: &parm->strVal, text: v16);
              }
            }
            else
            {
              v15 = v28.data;
              idAIActionParm::Clear(this: parm);
              parm->subType = 20;
              parm->type = 3;
              idStr::operator=(this: &parm->strVal, text: v15);
            }
          }
          else
          {
            idLexer::idLexer(this: &v32, flags_: 564);
            idLexer::LoadMemory(this: &v32, ptr: v28.data, length_: v28.len, name: "idAngles& Parm");
            idLexer::Parse1DMatrix(this: &v32, x: 3, m: &v31[0].pitch, expectCommas: false);
            idAIActionParm::Set(this: parm, in: v31);
            idLexer::~idLexer(this: &v32);
          }
        }
        else
        {
          idLexer::idLexer(this: &v32, flags_: 564);
          idLexer::LoadMemory(this: &v32, ptr: v28.data, length_: v28.len, name: "idVec3& Parm");
          idLexer::Parse1DMatrix(this: &v32, x: 3, m: &v29[0].x, expectCommas: false);
          idAIActionParm::Set(this: parm, in: v29);
          idLexer::~idLexer(this: &v32);
        }
      }
      else
      {
        v14 = atof(nptr: v28.data);
        idAIActionParm::Set(this: parm, in: (float)*(double *)&v14);
      }
    }
    else
    {
      v13 = atol(nptr: v28.data);
      idAIActionParm::Clear(this: parm);
      parm->intVal = v13;
      parm->type = 1;
      parm->subType = 0;
    }
  }
  else
  {
    v12 = (_cntlzw(idStr::Cmp(s1: v28.data, s2: "true")) & 0x20) != 0;
    idAIActionParm::Clear(this: parm);
    parm->type = 1;
    parm->subType = 1;
    parm->intVal = v12;
  }
  idStr::FreeData(this: &v28);
  idStr::FreeData(this: &v30);
}


// ========================================================================
// __unwind$489770
// EA  : 0x82A3CC4C
// RVA : 0x00A3CC4C
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_489770()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 176));
}


// ========================================================================
// __unwind$489771
// EA  : 0x82A3CC74
// RVA : 0x00A3CC74
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_489771()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// __unwind$489772
// EA  : 0x82A3CC9C
// RVA : 0x00A3CC9C
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_489772()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 272));
}


// ========================================================================
// __unwind$489773
// EA  : 0x82A3CCC4
// RVA : 0x00A3CCC4
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_489773()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 272));
}


// ========================================================================
// ?EndFile@idActionScriptConvertor@@AAA_NPBD@Z
// EA  : 0x82A3CE88
// RVA : 0x00A3CE88
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::EndFile(idActionScriptConvertor *this, const char *fileName)
{
  idFile_String *p_out; // r28
  BOOL v5; // r26
  const char *ScriptP; // r26
  idFile_String *v8; // r3
  __int64 (__fastcall *Length)(struct idFile_String *); // ctr
  char *filePtr; // r26
  idFileSystem_vtbl *v11; // r28
  int v12; // r3
  idStr v13; // [sp+50h] [-180h] BYREF
  idStr v14; // [sp+70h] [-160h] BYREF
  char v15[320]; // [sp+90h] [-140h] BYREF

  p_out = &this->out;
  if ( (int)this->out.Length(this: &this->out) <= 0 )
  {
    idLib::Printf(fmt: "no scripts found.\n");
  }
  else
  {
    idLib::Printf(fmt: "found %d action scripts. Writing '%s'...\n", this->numScripts, fileName);
    idStr::idStr(this: &v13, text: fileName);
    fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: fileName, a3: v15, a4: 256, a5: FSPATH_BASE);
    if ( idLib::sourceControl != nullptr )
    {
      idStr::idStr(this: &v14, text: v15);
      v5 = (_cntlzw(idSourceControl::CheckOut(this: idLib::sourceControl, file: &v14)) & 0x20) != 0;
      idStr::FreeData(this: &v14);
      if ( v5 )
      {
        idLib::Warning(fmt: "Failed to check out file '%s'", fileName);
        idStr::FreeData(this: &v13);
        return 0;
      }
    }
    idStr::SetFileExtension(this: &v13, extension: ".map.actionscript.bak");
    fileSystem->RenameFile(this: fileSystem, a2: fileName, a3: v13.data, a4: FSPATH_BASE);
    ScriptP = (const char *)idLexer::GetScriptP(this: (idCollisionModelLocal *)&this->src);
    p_out->Write(this: p_out, a2: this->startPos, a3: ScriptP - this->startPos);
    this->startPos = ScriptP;
    v8 = p_out;
    Length = p_out->Length;
    filePtr = this->out.filePtr;
    v11 = fileSystem->__vftable;
    v12 = Length(this: v8);
    v11->WriteFile(this: fileSystem, a2: fileName, a3: filePtr, a4: v12, a5: FSPATH_BASE);
    idStr::FreeData(this: &v13);
  }
  fileSystem->FreeFile(this: fileSystem, a2: this->buffer);
  return 1;
}


// ========================================================================
// __unwind$490686
// EA  : 0x82A3D040
// RVA : 0x00A3D040
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// __unwind$490687
// EA  : 0x82A3D068
// RVA : 0x00A3D068
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490687()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 112));
}


// ========================================================================
// ?ConvertScriptAction@idActionScriptConvertor@@AAA_NHAAVidScriptAction@@@Z
// EA  : 0x82A3D118
// RVA : 0x00A3D118
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::ConvertScriptAction(
        idActionScriptConvertor *this,
        const int index,
        idScriptAction *action)
{
  idLexer *p_src; // r30
  const idEventDef *Event; // r25
  int len; // r29
  idList<idAIActionParm,5> *p_parms; // r29
  int num; // r11
  int size; // r10
  idAIActionParm *v12; // r27
  idToken v13; // [sp+50h] [-1C0h] BYREF
  idToken v14; // [sp+A0h] [-170h] BYREF
  idStr v15; // [sp+F0h] [-120h] BYREF
  idLexer v16; // [sp+110h] [-100h] BYREF

  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.floatvalue = -3.4028235e38;
  v13.data = v13.baseBuffer;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "idStr");
  idLexer::ReadToken(this: p_src, token: &v13);
  idLexer::ExpectTokenString(this: p_src, string: "eventName");
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v13);
  v14.floatvalue = -3.4028235e38;
  v14.allocedAndFlag = 20;
  v14.data = v14.baseBuffer;
  v14.len = 0;
  v14.baseBuffer[0] = 0;
  v14.intvalue = 0;
  memset(&v14.whiteSpaceStart_p, 0, 12);
  idLexer::ExpectTokenType(this: p_src, type: 1, subtype: 0, token: &v14);
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 41, token: &v13);
  Event = idEventDef::FindEvent(name: v14.data);
  if ( Event == nullptr )
  {
    idStr::Insert(this: &v14, a: 60, index: 0);
    idStr::operator+=(this: &v14, a: 62);
    Event = idEventDef::FindEvent(name: v14.data);
  }
  len = v14.len;
  idStr::EnsureAlloced(this: &action->eventName, amount: v14.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: action->eventName.data, Src: v14.data, Size: len);
  action->eventName.data[len] = 0;
  action->eventName.len = len;
  if ( Event != nullptr )
  {
    idLexer::ExpectTokenType(this: p_src, type: 1, subtype: 0, token: &v13);
    idLexer::idLexer(this: &v16, flags_: 564);
    idLexer::LoadMemory(this: &v16, ptr: v13.data, length_: v13.len, name: "Event Parms");
    idLexer::ExpectTokenString(this: &v16, string: "idList");
    idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 39, token: &v13);
    idLexer::ExpectTokenType(this: &v16, type: 4, subtype: 0, token: &v13);
    if ( idStr::Cmp(s1: v13.data, s2: "idStr") != 0 )
    {
      if ( idStr::Cmp(s1: v13.data, s2: "idAIActionParm") == 0 )
      {
        idLexer::SkipRestOfLine(this: p_src);
        idLexer::SkipBracedSection(this: p_src, parseFirstBrace: false);
        idLexer::SkipBracedSection(this: p_src, parseFirstBrace: false);
        idLexer::~idLexer(this: &v16);
        idStr::FreeData(this: &v14);
        idStr::FreeData(this: &v13);
        return 0;
      }
      idLexer::Error(this: &v16, str: "Expected type 'idStr', found '%s'", v13.data);
    }
    if ( idLexer::CheckTokenType(this: &v16, type: 5, subtype: 40, token: &v13) )
    {
      idLexer::ReadToken(this: &v16, token: &v13);
      if ( v13.type != 4 && v13.type != 3 )
        idLexer::Error(this: p_src, str: "Expected a name or number for idList granularity, found '%s'", v13.data);
    }
    if ( idLexer::CheckTokenType(this: &v16, type: 5, subtype: 40, token: &v13) )
      idLexer::ParseInt(this: &v16);
    idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 38, token: &v13);
    idLexer::ReadToken(this: p_src, token: &v13);
    idLexer::ExpectTokenString(this: p_src, string: "params");
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v13);
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 46, token: &v13);
    idLexer::ExpectTokenString(this: p_src, string: "int");
    idLexer::ReadToken(this: p_src, token: &v13);
    idLexer::ExpectTokenString(this: p_src, string: "num");
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v13);
    idLexer::ParseInt(this: p_src);
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 41, token: &v13);
    while ( idLexer::ReadToken(this: p_src, token: &v13) )
    {
      if ( v13.type == 5 && v13.subtype == 47 )
        break;
      if ( idStr::Cmp(s1: v13.data, s2: "idStr") != 0 )
      {
        idLexer::Error(this: p_src, str: "Expected 'idStr' found '%s'", v13.data);
      }
      else
      {
        idLexer::ReadToken(this: p_src, token: &v13);
        idLexer::ExpectTokenString(this: p_src, string: "item");
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 48, token: &v13);
        idLexer::ParseInt(this: p_src);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 49, token: &v13);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v13);
        p_parms = &action->parms;
        idList<idAIActionParm,5>::PreAllocateWithGranularity(this: &action->parms, newSize: action->parms.num + 1);
        num = action->parms.num;
        size = action->parms.size;
        if ( num >= size )
        {
          v12 = &p_parms->list[size - 1];
        }
        else
        {
          v12 = &p_parms->list[num];
          action->parms.num = num + 1;
        }
        v15.allocedAndFlag = 20;
        v15.len = 0;
        v15.data = v15.baseBuffer;
        v15.baseBuffer[0] = 0;
        idEventDef::GetEventArgTypeName(eventNum: Event->eventnum, argNum: action->parms.num - 1, argType: &v15);
        idActionScriptConvertor::ConvertActionParm(this, index: action->parms.num - 1, argType: &v15, parm: v12);
        idStr::FreeData(this: &v15);
      }
    }
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 47, token: &v13);
    idLexer::~idLexer(this: &v16);
    idStr::FreeData(this: &v14);
  }
  else
  {
    idLib::Warning(fmt: "Error: event '%s' was not found.", v14.data);
    idLexer::SkipBracedSection(this: p_src, parseFirstBrace: false);
    idStr::FreeData(this: &v14);
  }
  idStr::FreeData(this: &v13);
  return 1;
}


// ========================================================================
// __unwind$490849
// EA  : 0x82A3D670
// RVA : 0x00A3D670
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490849()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 80));
}


// ========================================================================
// __unwind$490850
// EA  : 0x82A3D698
// RVA : 0x00A3D698
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490850()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 160));
}


// ========================================================================
// __unwind$490851
// EA  : 0x82A3D6C0
// RVA : 0x00A3D6C0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490851()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 528 + 272));
}


// ========================================================================
// __unwind$490852
// EA  : 0x82A3D6E8
// RVA : 0x00A3D6E8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_490852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 240));
}


// ========================================================================
// ?ConvertActionScript@idActionScriptConvertor@@AAA_NABVidToken@@PBD@Z
// EA  : 0x82A3D8A8
// RVA : 0x00A3D8A8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::ConvertActionScript(
        idActionScriptConvertor *this,
        const idToken *typeName,
        const char *curPos)
{
  idLexer *p_src; // r30
  int num; // r11
  idScriptAction *v7; // r5
  idGame *v9; // r3
  idTypeInfoTools *v10; // r29
  int v11; // r4
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  const char *TypeInfoString; // r3
  int v17; // [sp+8h] [-11E8h]
  void *v18; // [sp+8h] [-11E8h]
  int v19; // [sp+Ch] [-11E4h]
  bool v20; // [sp+Fh] [-11E1h]
  int v21; // [sp+10h] [-11E0h]
  int v22; // [sp+14h] [-11DCh]
  int v23; // [sp+18h] [-11D8h]
  int v24; // [sp+1Ch] [-11D4h]
  idList<idScriptAction,5> v25; // [sp+60h] [-1190h] BYREF
  idToken v26; // [sp+70h] [-1180h] BYREF
  idStr v27; // [sp+C0h] [-1130h] BYREF
  idStr v28; // [sp+E0h] [-1110h] BYREF
  idTypeInfoFile v29; // [sp+100h] [-10F0h] BYREF
  va v30; // [sp+1A0h] [-1050h] BYREF

  v26.len = 0;
  v26.allocedAndFlag = 20;
  v26.floatvalue = -3.4028235e38;
  v26.data = v26.baseBuffer;
  v26.baseBuffer[0] = 0;
  v26.intvalue = 0;
  memset(&v26.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "int");
  idLexer::ReadToken(this: p_src, token: &v26);
  idLexer::ExpectTokenString(this: p_src, string: "num");
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v26);
  idLexer::ParseInt(this: p_src);
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 41, token: &v26);
  *(_WORD *)&v25.memTag = 1280;
  memset(&v25, 0, 14);
  if ( idLexer::ReadToken(this: p_src, token: &v26) )
  {
    while ( v26.type != 5 || v26.subtype != 47 )
    {
      if ( idStr::Cmp(s1: v26.data, s2: "idScriptAction") != 0 )
      {
        idLexer::Error(this: p_src, str: "Expected 'idScriptAction', found '%s'", v26.data);
      }
      else
      {
        idLexer::ReadToken(this: p_src, token: &v26);
        idLexer::ReadToken(this: p_src, token: &v26);
        if ( idStr::Cmp(s1: v26.data, s2: "item") != 0 )
          idLexer::Error(this: p_src, str: "Expected 'item' found '%s'", v26.data);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 48, token: &v26);
        idLexer::ParseInt(this: p_src);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 49, token: &v26);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v26);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 46, token: &v26);
        idList<idScriptAction,5>::PreAllocateWithGranularity(this: &v25, newSize: v25.num + 1);
        num = v25.num;
        if ( v25.num >= v25.size )
        {
          v7 = &v25.list[v25.size - 1];
        }
        else
        {
          num = v25.num + 1;
          v7 = &v25.list[v25.num++];
        }
        if ( (unsigned __int8)idActionScriptConvertor::ConvertScriptAction(this, index: num - 1, action: v7) == 0 )
        {
          idList<idScriptAction,5>::RemoveIndexFast(this: &v25, index: v25.num - 1);
          idLexer::SkipBracedSection(this: p_src, parseFirstBrace: false);
          idList<idScriptAction,5>::Clear(this: &v25);
          idStr::FreeData(this: &v26);
          return 0;
        }
      }
      if ( !idLexer::ReadToken(this: p_src, token: &v26) )
        break;
    }
  }
  this->out.Write(this: &this->out, a2: this->startPos, a3: curPos - this->startPos);
  this->startPos = curPos;
  v9 = common->Game(this: common);
  v10 = (idTypeInfoTools *)v9->GetTypeInfoTools(this: v9);
  idStr::idStr(this: &v27, text: "\n\\\\ BEGIN REWRITE\n");
  v11 = 4;
  if ( this->fileType != FT_TYPEINFO )
    v11 = 2;
  idTypeInfoFile::idTypeInfoFile(this: &v29, indent_: v11);
  idTypeInfoFile::WriteMemoryFile(this: &v29);
  HIDWORD(v12) = v25.num;
  v15 = va::va(
          this: &v30,
          fmt: "[%d]",
          a3: v12,
          a4: v14,
          a5: v13,
          a6: v17,
          a7: v19,
          a8: v21,
          a9: v22,
          a10: v23,
          a11: v24);
  idStr::idStr(this: &v28, text: v15);
  idTypeInfoFile::WriteType(
    this: &v29,
    type: "idList < idScriptAction , TAG_IDLIST >",
    ops: &byte_8200D768,
    name: "actionScript");
  idTypeInfoTools::WriteType_r(
    this: v10,
    file: &v29,
    scope: &byte_8200D768,
    varType: "idList < idScriptAction , TAG_IDLIST >",
    varOps: &byte_8200D768,
    varName: "actionScript",
    varFlags: 0,
    comment: &byte_8200D768,
    varPtr: v18,
    allowSpecialCase: v20);
  TypeInfoString = idTypeInfoFile::GetTypeInfoString(this: &v29);
  idStr::operator=(this: &v27, text: TypeInfoString);
  this->out.Write(this: &this->out, a2: v27.data, a3: v27.len);
  idStr::operator=(this: &v27, text: "\n\\\\ END REWRITE\n");
  idStr::FreeData(this: &v28);
  idTypeInfoFile::~idTypeInfoFile(this: &v29);
  idStr::FreeData(this: &v27);
  idList<idScriptAction,5>::Clear(this: &v25);
  idStr::FreeData(this: &v26);
  return 1;
}


// ========================================================================
// __unwind$491399
// EA  : 0x82A3DCB0
// RVA : 0x00A3DCB0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491399()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 112));
}


// ========================================================================
// __unwind$491400
// EA  : 0x82A3DCD8
// RVA : 0x00A3DCD8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491400()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(v0 - 4592 + 96));
}


// ========================================================================
// __unwind$491401
// EA  : 0x82A3DD00
// RVA : 0x00A3DD00
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 192));
}


// ========================================================================
// __unwind$491402
// EA  : 0x82A3DD28
// RVA : 0x00A3DD28
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491402()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 4592 + 256));
}


// ========================================================================
// __unwind$491403
// EA  : 0x82A3DD50
// RVA : 0x00A3DD50
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491403()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 224));
}


// ========================================================================
// ?ParseVariableDef_r@idActionScriptConvertor@@AAAXXZ
// EA  : 0x82A3DD80
// RVA : 0x00A3DD80
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall idActionScriptConvertor::ParseVariableDef_r(idActionScriptConvertor *this)
{
  idLexer *p_src; // r29
  cmType_t ScriptP; // r3
  const char *v4; // r26
  bool v5; // r28
  idToken v6; // [sp+50h] [-230h] BYREF
  idToken v7; // [sp+A0h] [-1E0h] BYREF
  idToken v8; // [sp+F0h] [-190h] BYREF
  idToken v9; // [sp+140h] [-140h] BYREF
  idLexer v10; // [sp+190h] [-F0h] BYREF

  p_src = &this->src;
  ScriptP = idLexer::GetScriptP(this: (idCollisionModelLocal *)&this->src);
  v7.len = 0;
  v7.allocedAndFlag = 20;
  v4 = (const char *)ScriptP;
  v7.data = v7.baseBuffer;
  v7.floatvalue = -3.4028235e38;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  if ( idLexer::ReadToken(this: p_src, token: &v7) )
  {
    while ( 1 )
    {
      if ( v7.type == 5 && v7.subtype == 47 )
        goto LABEL_22;
      v9.floatvalue = -3.4028235e38;
      v9.allocedAndFlag = 20;
      v9.data = v9.baseBuffer;
      v9.len = 0;
      v9.baseBuffer[0] = 0;
      v9.intvalue = 0;
      memset(&v9.whiteSpaceStart_p, 0, 12);
      idLexer::ExpectTokenType(this: p_src, type: 1, subtype: 0, token: &v9);
      v8.floatvalue = -3.4028235e38;
      v8.allocedAndFlag = 20;
      v8.data = v8.baseBuffer;
      v8.len = 0;
      v8.baseBuffer[0] = 0;
      v8.intvalue = 0;
      memset(&v8.whiteSpaceStart_p, 0, 12);
      idLexer::ReadToken(this: p_src, token: &v8);
      if ( v8.type != 1 && v8.type != 4 )
        idLexer::Error(this: p_src, str: "Expect a string or name, found '%s'", v8.data);
      v6.floatvalue = -3.4028235e38;
      v6.allocedAndFlag = 20;
      v6.data = v6.baseBuffer;
      v6.len = 0;
      v6.baseBuffer[0] = 0;
      v6.intvalue = 0;
      memset(&v6.whiteSpaceStart_p, 0, 12);
      if ( idLexer::CheckTokenType(this: p_src, type: 5, subtype: 48, token: &v6) )
      {
        idLexer::ParseInt(this: p_src);
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 49, token: &v6);
      }
      idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v6);
      v5 = false;
      idLexer::idLexer(this: &v10, flags_: 564);
      idLexer::LoadMemory(this: &v10, ptr: v7.data, length_: v7.len, name: "Looking for ActionScript");
      if ( idLexer::CheckTokenString(this: &v10, string: "idList")
        && idLexer::CheckTokenType(this: &v10, type: 5, subtype: 39, token: &v6) )
      {
        v5 = idLexer::CheckTokenString(this: &v10, string: "idScriptAction");
      }
      if ( v5 )
      {
        idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 46, token: &v6);
        if ( (unsigned __int8)idActionScriptConvertor::ConvertActionScript(this, typeName: &v7, curPos: v4) != 0 )
        {
          ++this->numScripts;
          this->startPos = (const char *)idLexer::GetScriptP(this: (idCollisionModelLocal *)p_src);
        }
        goto LABEL_21;
      }
      idLexer::CheckTokenType(this: p_src, type: 5, subtype: 37, token: &v6);
      idLexer::ReadToken(this: p_src, token: &v6);
      if ( v6.type != 5 )
        goto LABEL_20;
      if ( v6.subtype != 46 )
        break;
      idActionScriptConvertor::ParseVariableDef_r(this);
LABEL_21:
      v4 = (const char *)idLexer::GetScriptP(this: (idCollisionModelLocal *)p_src);
      idLexer::~idLexer(this: &v10);
      idStr::FreeData(this: &v6);
      idStr::FreeData(this: &v8);
      idStr::FreeData(this: &v9);
      if ( !idLexer::ReadToken(this: p_src, token: &v7) )
        goto LABEL_22;
    }
    if ( v6.subtype == 31 )
      idLexer::ReadToken(this: p_src, token: &v6);
LABEL_20:
    idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 41, token: &v6);
    goto LABEL_21;
  }
LABEL_22:
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$491575
// EA  : 0x82A3E0B8
// RVA : 0x00A3E0B8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491575()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$491576
// EA  : 0x82A3E0E0
// RVA : 0x00A3E0E0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491576()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 320));
}


// ========================================================================
// __unwind$491577
// EA  : 0x82A3E108
// RVA : 0x00A3E108
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491577()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 240));
}


// ========================================================================
// __unwind$491578
// EA  : 0x82A3E130
// RVA : 0x00A3E130
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491578()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 80));
}


// ========================================================================
// __unwind$491579
// EA  : 0x82A3E158
// RVA : 0x00A3E158
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491579()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 640 + 400));
}


// ========================================================================
// ?ParseEntityClassDef@idActionScriptConvertor@@AAAXAAVidToken@@@Z
// EA  : 0x82A3E188
// RVA : 0x00A3E188
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall idActionScriptConvertor::ParseEntityClassDef(idActionScriptConvertor *this, idToken *entityClassName)
{
  idLexer *p_src; // r30
  idToken v4; // [sp+50h] [-70h] BYREF

  v4.len = 0;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.floatvalue = -3.4028235e38;
  v4.baseBuffer[0] = 0;
  v4.intvalue = 0;
  memset(&v4.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ExpectTokenType(this: &this->src, type: 1, subtype: 0, token: &v4);
  idLexer::ReadToken(this: p_src, token: &v4);
  if ( v4.type != 1 && v4.type != 4 && idStr::Cmp(s1: v4.data, s2: "edit") != 0 )
    idLexer::Error(this: p_src, str: "Expected 'edit', found '%s'", v4.data);
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 32, token: &v4);
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 46, token: &v4);
  idActionScriptConvertor::ParseVariableDef_r(this);
  idStr::FreeData(this: &v4);
}


// ========================================================================
// __unwind$491873
// EA  : 0x82A3E278
// RVA : 0x00A3E278
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491873()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?FixEntityDefActionScripts@idActionScriptConvertor@@QAAXXZ
// EA  : 0x82A3E2A8
// RVA : 0x00A3E2A8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall idActionScriptConvertor::FixEntityDefActionScripts(idActionScriptConvertor *this)
{
  idLexer *p_src; // r30
  idToken v3; // [sp+50h] [-D0h] BYREF
  idToken v4; // [sp+A0h] [-80h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.floatvalue = -3.4028235e38;
  v3.baseBuffer[0] = 0;
  v3.intvalue = 0;
  memset(&v3.whiteSpaceStart_p, 0, 12);
  v4.floatvalue = -3.4028235e38;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.len = 0;
  v4.baseBuffer[0] = 0;
  v4.intvalue = 0;
  memset(&v4.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ReadToken(this: &this->src, token: &v4);
  if ( v4.type != 4 && v4.type != 1 && v4.type != 3 )
    idLexer::Error(this: p_src, str: "Expected entity name, found '%s'", v4.data);
  idLexer::ExpectTokenType(this: p_src, type: 5, subtype: 46, token: &v3);
  while ( idLexer::ReadToken(this: p_src, token: &v3) )
  {
    if ( v3.type == 5 && v3.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v3.data, s2: "inherit") != 0 && idStr::Cmp(s1: v3.data, s2: "class") != 0 )
    {
      if ( v3.type == 1 || v3.type == 4 )
        idActionScriptConvertor::ParseEntityClassDef(this, entityClassName: &v3);
    }
    else
    {
      idLexer::ParseRestOfLine(this: p_src, out: &v3);
    }
  }
  idStr::FreeData(this: &v4);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$491945
// EA  : 0x82A3E448
// RVA : 0x00A3E448
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491945()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$491946
// EA  : 0x82A3E470
// RVA : 0x00A3E470
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_491946()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// ?ParseDeclAIInteraction@idActionScriptConvertor@@AAAXXZ
// EA  : 0x82A3E4A0
// RVA : 0x00A3E4A0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall idActionScriptConvertor::ParseDeclAIInteraction(idActionScriptConvertor *this)
{
  idLexer *p_src; // r30
  idToken v3; // [sp+50h] [-80h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.floatvalue = -3.4028235e38;
  v3.baseBuffer[0] = 0;
  v3.intvalue = 0;
  memset(&v3.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  while ( idLexer::ReadToken(this: p_src, token: &v3) )
  {
    if ( v3.type == 5 && v3.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v3.data, s2: "inherit") != 0 && idStr::Cmp(s1: v3.data, s2: "class") != 0 )
    {
      if ( v3.type == 1 || v3.type == 4 )
        idActionScriptConvertor::ParseEntityClassDef(this, entityClassName: &v3);
      else
        idLexer::Error(this: p_src, str: "Expected a name, found '%s'", v3.data);
    }
    else
    {
      idLexer::ParseRestOfLine(this: p_src, out: &v3);
    }
  }
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$492065
// EA  : 0x82A3E5DC
// RVA : 0x00A3E5DC
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492065()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?FixTypeInfoActionScripts@idActionScriptConvertor@@QAA_NPBD@Z
// EA  : 0x82A3E610
// RVA : 0x00A3E610
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::FixTypeInfoActionScripts(idActionScriptConvertor *this, const char *fileName)
{
  idToken v5; // [sp+50h] [-150h] BYREF
  idToken v6; // [sp+A0h] [-100h] BYREF
  idToken v7; // [sp+F0h] [-B0h] BYREF

  if ( (unsigned __int8)idActionScriptConvertor::BeginFile(this, fileName) == 0 )
    return 0;
  this->fileType = FT_TYPEINFO;
  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.floatvalue = -3.4028235e38;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  while ( idLexer::ReadToken(this: &this->src, token: &v5) )
  {
    if ( v5.type != 4 && v5.type != 1 )
      idLexer::Error(this: &this->src, str: "Expected decl type, found '%s'", v5.data);
    idToken::idToken(this: &v7, token: &v5);
    v6.floatvalue = -3.4028235e38;
    v6.allocedAndFlag = 20;
    v6.data = v6.baseBuffer;
    v6.len = 0;
    v6.baseBuffer[0] = 0;
    v6.intvalue = 0;
    memset(&v6.whiteSpaceStart_p, 0, 12);
    idLexer::ReadToken(this: &this->src, token: &v6);
    if ( v5.type != 1 && v5.type != 4 )
      idLexer::Error(this: &this->src, str: "Expected decl name, found '%s'", v5.data);
    idLexer::ExpectTokenType(this: &this->src, type: 5, subtype: 46, token: &v5);
    if ( idStr::Cmp(s1: v7.data, s2: "aiInteraction") != 0 )
      idLexer::SkipBracedSection(this: &this->src, parseFirstBrace: false);
    else
      idActionScriptConvertor::ParseDeclAIInteraction(this);
    idStr::FreeData(this: &v6);
    idStr::FreeData(this: &v7);
  }
  idStr::FreeData(this: &v5);
  return idActionScriptConvertor::EndFile(this, fileName);
}


// ========================================================================
// $M492308
// EA  : 0x82A3E7F8
// RVA : 0x00A3E7F8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void *_M492308()
{
  int v0; // r12
  int v1; // r30

  v1 = *(_DWORD *)(v0 - 416 + 436);
  idLib::Warning(fmt: "Failed to parse map file '%s' - %s", *(const char **)(v1 + 12), idException::error);
  fileSystem->FreeFile(this: fileSystem, a2: *(void **)v1);
  return &_M492300;
}


// ========================================================================
// __unwind$492140
// EA  : 0x82A3E858
// RVA : 0x00A3E858
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492140()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$492141
// EA  : 0x82A3E880
// RVA : 0x00A3E880
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492141()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 240));
}


// ========================================================================
// __unwind$492142
// EA  : 0x82A3E8A8
// RVA : 0x00A3E8A8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// ?FixMapFileActionScripts@idActionScriptConvertor@@QAA_NPBD@Z
// EA  : 0x82A3E8D8
// RVA : 0x00A3E8D8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

int __fastcall idActionScriptConvertor::FixMapFileActionScripts(idActionScriptConvertor *this, const char *fileName)
{
  idLexer *p_src; // r3
  bool v5; // zf
  idToken v7[2]; // [sp+50h] [-C0h] BYREF

  if ( (unsigned __int8)idActionScriptConvertor::BeginFile(this, fileName) == 0 )
    return 0;
  this->fileType = FT_MAP;
  v7[0].len = 0;
  v7[0].baseBuffer[0] = 0;
  v7[0].intvalue = 0;
  v7[0].allocedAndFlag = 20;
  v7[0].data = v7[0].baseBuffer;
  v7[0].whiteSpaceStart_p = nullptr;
  v7[0].floatvalue = -3.4028235e38;
  v7[0].whiteSpaceEnd_p = nullptr;
  v7[0].next = nullptr;
  idLexer::ExpectTokenString(this: &this->src, string: "Version");
  if ( idLexer::ParseInt(this: &this->src) != 3 )
    idLexer::Error(this: &this->src, str: "Map version must be 3 in order to convert!");
LABEL_4:
  while ( idLexer::ReadToken(this: &this->src, token: v7) )
  {
    if ( idStr::Cmp(s1: v7[0].data, s2: "entity") != 0 )
    {
      if ( idStr::Cmp(s1: v7[0].data, s2: "groupstates") != 0 )
      {
        if ( idStr::Cmp(s1: v7[0].data, s2: "compound") != 0 )
        {
          v5 = idStr::Cmp(s1: v7[0].data, s2: "includes") != 0;
          p_src = &this->src;
          if ( v5 )
            idLexer::Error(this: p_src, str: "Unknown token '%s'", v7[0].data);
          else
            idLexer::SkipBracedSection(this: p_src, parseFirstBrace: true);
        }
        else
        {
          idLexer::ParseInt(this: &this->src);
          idLexer::SkipBracedSection(this: &this->src, parseFirstBrace: true);
        }
      }
      else
      {
        idLexer::SkipBracedSection(this: &this->src, parseFirstBrace: true);
      }
    }
    else
    {
      idLexer::ParseInt(this: &this->src);
      idLexer::ExpectTokenType(this: &this->src, type: 5, subtype: 46, token: v7);
      if ( idLexer::CheckTokenString(this: &this->src, string: "groups") )
      {
        idLexer::ExpectTokenType(this: &this->src, type: 5, subtype: 46, token: v7);
        while ( idLexer::ReadToken(this: &this->src, token: v7) )
        {
          if ( v7[0].type == 5 )
          {
            if ( v7[0].subtype == 47 )
              break;
LABEL_20:
            idLexer::Error(this: &this->src, str: "Expected group name, found '%s'", v7[0].data);
          }
          else if ( v7[0].type != 1 )
          {
            goto LABEL_20;
          }
        }
      }
      if ( idLexer::CheckTokenString(this: &this->src, string: "layers") )
        idLexer::SkipBracedSection(this: &this->src, parseFirstBrace: true);
      idLexer::ExpectTokenString(this: &this->src, string: "entityDef");
      idActionScriptConvertor::FixEntityDefActionScripts(this);
      while ( idLexer::ReadToken(this: &this->src, token: v7) )
      {
        if ( v7[0].type != 5 )
          goto _M492475;
        if ( v7[0].subtype == 47 )
          goto LABEL_4;
        if ( v7[0].subtype == 46 )
          idLexer::SkipBracedSection(this: &this->src, parseFirstBrace: false);
        else
_M492475:
          idLexer::Error(this: &this->src, str: "Unknown token '%s'", v7[0].data);
      }
    }
  }
  idStr::FreeData(this: &v7[0]);
  return idActionScriptConvertor::EndFile(this, fileName);
}


// ========================================================================
// $M492504
// EA  : 0x82A3EC34
// RVA : 0x00A3EC34
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void *_M492504()
{
  int v0; // r12
  int v1; // r30

  v1 = *(_DWORD *)(v0 - 272 + 292);
  idLib::Warning(fmt: "Failed to parse map file '%s' - %s", *(const char **)(v1 + 12), idException::error);
  fileSystem->FreeFile(this: fileSystem, a2: *(void **)v1);
  return &_M492496;
}


// ========================================================================
// __unwind$492333
// EA  : 0x82A3EC94
// RVA : 0x00A3EC94
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492333()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// ?Cmd_FixActionScripts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82A3ECC8
// RVA : 0x00A3ECC8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void __fastcall Cmd_FixActionScripts_f(const idCmdArgs *args)
{
  bool v2; // cr57
  idFileList *v3; // r30
  int v4; // r29
  int v5; // r28
  idFileList *v6; // r30
  int v7; // r29
  int v8; // r28
  idStr v9; // [sp+50h] [-280h] BYREF
  int argc; // [sp+70h] [-260h]
  idStr v11; // [sp+80h] [-250h] BYREF
  idActionScriptConvertor v12; // [sp+A0h] [-230h] BYREF

  idActionScriptConvertor::idActionScriptConvertor(this: &v12);
  v2 = args->argc > 1;
  argc = args->argc;
  if ( v2 )
  {
    idStr::idStr(this: &v11, text: args->argv[1]);
    v9.allocedAndFlag = 20;
    v9.data = v9.baseBuffer;
    v9.len = 0;
    v9.baseBuffer[0] = 0;
    idStr::ExtractFileExtension(this: &v11, dest: &v9);
    if ( idStr::Cmp(s1: v9.data, s2: "tdef") != 0 )
    {
      if ( idStr::Cmp(s1: v9.data, s2: "map") != 0 )
        idLib::Warning(fmt: "Unknown extension type '%s'", v9.data);
      else
        idActionScriptConvertor::FixMapFileActionScripts(this: &v12, fileName: v11.data);
    }
    else
    {
      idActionScriptConvertor::FixTypeInfoActionScripts(this: &v12, fileName: v11.data);
    }
    idStr::FreeData(this: &v9);
    idStr::FreeData(this: &v11);
    idActionScriptConvertor::~idActionScriptConvertor(this: &v12);
  }
  else
  {
    if ( idLib::sourceControl != nullptr )
      idLib::sourceControl->SetSilentCheckOut(this: idLib::sourceControl, a2: true);
    common->SetRefreshOnPrint(this: common, a2: true);
    v3 = fileSystem->ListFilesTree(this: fileSystem, a2: "typeinfo", a3: ".tdef", a4: 0);
    v4 = 0;
    if ( v3->list.num > 0 )
    {
      v5 = 0;
      do
      {
        idActionScriptConvertor::FixTypeInfoActionScripts(this: &v12, fileName: v3->list.list[v5].data);
        ++v4;
        ++v5;
      }
      while ( v4 < v3->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v3);
    v6 = fileSystem->ListFilesTree(this: fileSystem, a2: "maps", a3: ".map", a4: 0);
    v7 = 0;
    if ( v6->list.num > 0 )
    {
      v8 = 0;
      do
      {
        idActionScriptConvertor::FixMapFileActionScripts(this: &v12, fileName: v6->list.list[v8].data);
        ++v7;
        ++v8;
      }
      while ( v7 < v6->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v6);
    common->SetRefreshOnPrint(this: common, a2: false);
    if ( idLib::sourceControl != nullptr )
      idLib::sourceControl->SetSilentCheckOut(this: idLib::sourceControl, a2: false);
    idFile_Memory::~idFile_Memory(this: &v12.out);
    idLexer::~idLexer(this: &v12.src);
  }
}


// ========================================================================
// __unwind$492518
// EA  : 0x82A3EF3C
// RVA : 0x00A3EF3C
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492518()
{
  int v0; // r12

  idActionScriptConvertor::~idActionScriptConvertor(this: (idActionScriptConvertor *)(v0 - 720 + 160));
}


// ========================================================================
// __unwind$492519
// EA  : 0x82A3EF64
// RVA : 0x00A3EF64
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492519()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 128));
}


// ========================================================================
// __unwind$492520
// EA  : 0x82A3EF8C
// RVA : 0x00A3EF8C
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492520()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 80));
}


// ========================================================================
// __unwind$492649
// EA  : 0x82A3EFB4
// RVA : 0x00A3EFB4
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.cpp
// ========================================================================

void _unwind_492649()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 720 + 164));
}

