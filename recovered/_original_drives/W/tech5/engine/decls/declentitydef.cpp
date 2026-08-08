
// ========================================================================
// ?DefaultDefinition@idDeclEntityDef@@UBAPBDXZ
// EA  : 0x82618750
// RVA : 0x00618750
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

const char *__fastcall idDeclEntityDef::DefaultDefinition(idDeclEntityDef *this)
{
  return "{\n\tinherit = \"\";\n\tclass = \"idEntity\";\n\tedit = {\n\t}\n}\n";
}


// ========================================================================
// ?GetEntityState@idDeclEntityDef@@UBAPBDXZ
// EA  : 0x82618760
// RVA : 0x00618760
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

const char *__fastcall idDeclEntityDef::GetEntityState(idDeclEntityDef *this)
{
  return (char *)idLobby::PeerIndexOnHost((LEAPCORE::CXboxRendererConnection *)this) + this->stateOffset;
}


// ========================================================================
// ?GetEntityStateLength@idDeclEntityDef@@UBAHXZ
// EA  : 0x82618798
// RVA : 0x00618798
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idDeclEntityDef::GetEntityStateLength(idDeclEntityDef *this)
{
  return (int)idreports::MapWarning::GetCachedSize((bfx::SystemInstance *)this) - this->stateOffset;
}


// ========================================================================
// ?GetEntityStateLineNumber@idDeclEntityDef@@UBAHXZ
// EA  : 0x826187D0
// RVA : 0x006187D0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idDeclEntityDef::GetEntityStateLineNumber(idDeclEntityDef *this)
{
  return idDecl::GetLineNum(this: &this->idDecl) + this->stateLineNumberOffset;
}


// ========================================================================
// ?IsParent@idDeclEntityDef@@UBA_NPBV1@@Z
// EA  : 0x82618808
// RVA : 0x00618808
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

BOOL __fastcall idDeclEntityDef::IsParent(idDeclEntityDef *this, const idDeclEntityDef *child)
{
  idDeclEntityDef *listedParent; // r11

  if ( child == this )
    return true;
  listedParent = this->listedParent;
  return listedParent != nullptr && listedParent != this && ((bool (*)(void))listedParent->IsParent)();
}


// ========================================================================
// ?SetEntityState@idDeclEntityDef@@UAAXABVidTypeInfoTree@@_N1@Z
// EA  : 0x82618850
// RVA : 0x00618850
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetEntityState(
        idDeclEntityDef *this,
        idTypeInfoTree *tree,
        bool onlyDiff,
        BOOL writeEditorVars)
{
  idDeclEntityDef_vtbl *v8; // r30
  const char *TypeInfoString; // r3
  idTypeInfoFile v10; // [sp+50h] [-D0h] BYREF

  idTypeInfoFile::idTypeInfoFile(this: &v10, indent_: 2);
  idTypeInfoFile::WriteMemoryFile(this: &v10);
  v10.settings.resolveEntityPointers = false;
  v10.settings.resolveModelPointers = false;
  v10.settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
  v10.settings.writeType = false;
  idTypeInfoTree::Write(this: tree, file: &v10, onlyDiff);
  v8 = this->__vftable;
  TypeInfoString = idTypeInfoFile::GetTypeInfoString(this: &v10);
  v8->SetEntityState(this, a2: TypeInfoString, a3: writeEditorVars);
  idTypeInfoFile::~idTypeInfoFile(this: &v10);
}


// ========================================================================
// __unwind$220234
// EA  : 0x826188E0
// RVA : 0x006188E0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_220234()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 288 + 80));
}


// ========================================================================
// ??0idEntityDefEditorVars@@QAA@XZ
// EA  : 0x82618A58
// RVA : 0x00618A58
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

idEntityDefEditorVars *__fastcall idEntityDefEditorVars::idEntityDefEditorVars(idEntityDefEditorVars *this)
{
  char v1; // r6

  this->editorName.len = 0;
  this->editorName.data = this->editorName.baseBuffer;
  this->editorName.allocedAndFlag = 20;
  this->editorName.baseBuffer[0] = 0;
  this->material.str = &byte_8200D768;
  this->color.a = -1.0;
  this->animName.str = &byte_8200D768;
  this->color.b = -1.0;
  this->color.g = -1.0;
  this->color.r = -1.0;
  *((_BYTE *)this + 84) = *((_BYTE *)this + 84) & 3 | 0xC;
  this->color.r = 1.0;
  this->color.g = 1.0;
  this->color.b = 1.0;
  this->color.a = 1.0;
  this->size.z = 0.0;
  this->size.y = 0.0;
  this->size.x = 0.0;
  this->originOffset.z = 0.0;
  this->originOffset.y = 0.0;
  this->originOffset.x = 0.0;
  v1 = *((_BYTE *)this + 84);
  this->animFrame = 0;
  *((_BYTE *)this + 84) = v1 & 0xFD;
  return this;
}


// ========================================================================
// ??0idDeclEntityDef@@QAA@XZ
// EA  : 0x82618B08
// RVA : 0x00618B08
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

idDeclEntityDef *__fastcall idDeclEntityDef::idDeclEntityDef(idDeclEntityDef *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclEntityDef_vtbl *)&idDeclEntityDef::`vftable';
  this->inherit.str = &byte_8200D768;
  this->className.str = &byte_8200D768;
  idEntityDefEditorVars::idEntityDefEditorVars(this: &this->editorVars);
  this->entityStateWithInheritanceText.len = 0;
  this->entityStateWithInheritanceText.allocedAndFlag = 20;
  this->entityStateWithInheritanceText.data = this->entityStateWithInheritanceText.baseBuffer;
  this->entityStateWithInheritanceText.baseBuffer[0] = 0;
  this->stateOffset = 0;
  this->stateLineNumberOffset = 0;
  this->listedParent = this;
  this->expandInheritance = true;
  return this;
}


// ========================================================================
// ??1idDeclEntityDef@@UAA@XZ
// EA  : 0x82618BB0
// RVA : 0x00618BB0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::~idDeclEntityDef(idDeclEntityDef *this)
{
  this->__vftable = (idDeclEntityDef_vtbl *)&idDeclEntityDef::`vftable';
  idStr::FreeData(this: &this->entityStateWithInheritanceText);
  idStr::FreeData(this: &this->editorVars.editorName);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$220737
// EA  : 0x82618C0C
// RVA : 0x00618C0C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_220737()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$220738
// EA  : 0x82618C34
// RVA : 0x00618C34
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_220738()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ?FreeData@idDeclEntityDef@@UAAXXZ
// EA  : 0x82618C60
// RVA : 0x00618C60
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::FreeData(idDeclEntityDef *this)
{
  idAtomicString::Set(this: &this->inherit, str_: &byte_8200D768);
  idAtomicString::Set(this: &this->className, str_: &byte_8200D768);
  this->stateOffset = 0;
  this->stateLineNumberOffset = 0;
}


// ========================================================================
// ?SetInherit@idDeclEntityDef@@UAAXPBD@Z
// EA  : 0x82618CC0
// RVA : 0x00618CC0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetInherit(idDeclEntityDef *this, const char *inherit)
{
  idAtomicString::Set(this: &this->inherit, str_: inherit);
}


// ========================================================================
// ?SetClass@idDeclEntityDef@@UAAXPBD@Z
// EA  : 0x82618CC8
// RVA : 0x00618CC8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetClass(idDeclEntityDef *this, const char *className)
{
  idAtomicString::Set(this: &this->className, str_: className);
}


// ========================================================================
// ?GetEntityStateWithInheritanceLength@idDeclEntityDef@@UBAHXZ
// EA  : 0x82618CD0
// RVA : 0x00618CD0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idDeclEntityDef::GetEntityStateWithInheritanceLength(idDeclEntityDef *this)
{
  return this->entityStateWithInheritanceText.len;
}


// ========================================================================
// ?BuildText@idDeclEntityDef@@UAAXPBD0@Z
// EA  : 0x82618CE0
// RVA : 0x00618CE0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::BuildText(idDeclEntityDef *this, const char *inherit, const char *className)
{
  idFile_Memory v6; // [sp+50h] [-180h] BYREF

  idFile_Memory::idFile_Memory(this: &v6);
  idFile::WriteFloatString(this: &v6, fmt: "{\n");
  idFile::WriteFloatString(this: &v6, fmt: "\tinherit = \"%s\";\n", inherit);
  idFile::WriteFloatString(this: &v6, fmt: "\tclass = \"%s\";\n", className);
  idFile::WriteFloatString(this: &v6, fmt: "\tedit = {\n");
  idFile::WriteFloatString(this: &v6, fmt: "\t}\n");
  idFile::WriteFloatString(this: &v6, fmt: "}");
  idDecl::SetText(this: &this->idDecl, text: v6.filePtr, length: 0);
  idDecl::ReParse(this: &this->idDecl, fromDisk: false);
  idFile_Memory::~idFile_Memory(this: &v6);
}


// ========================================================================
// __unwind$220822
// EA  : 0x82618D98
// RVA : 0x00618D98
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_220822()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 464 + 80));
}


// ========================================================================
// ?Parse@idEntityDefEditorVars@@QAA_NAAVidParser@@@Z
// EA  : 0x82618DC8
// RVA : 0x00618DC8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idEntityDefEditorVars::Parse(idEntityDefEditorVars *this, idParser *src)
{
  bool v5; // [sp+50h] [-340h]
  idToken v6; // [sp+60h] [-330h] BYREF
  char v7; // [sp+A8h] [-2E8h] BYREF
  idStr v8; // [sp+1B0h] [-1E0h] BYREF
  int v9; // [sp+1E4h] [-1ACh]
  float v10; // [sp+1E8h] [-1A8h]
  int v11; // [sp+1ECh] [-1A4h]
  int v12; // [sp+1F0h] [-1A0h]
  int v13; // [sp+1F4h] [-19Ch]
  char v14; // [sp+1F8h] [-198h] BYREF

  v6.baseBuffer[0] = 0;
  v6.floatvalue = -3.4028235e38;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  v7 = 0;
  v6.data = &v7;
  v6.len = 0;
  v6.allocedAndFlag = -2147483392;
  v10 = -3.4028235e38;
  v8.baseBuffer[0] = 0;
  v9 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v8.data = &v14;
  v8.len = 0;
  v8.allocedAndFlag = -2147483392;
  if ( idParser::CheckTokenString(this: src, string: "editorVars") != 0 )
  {
    if ( idLib::production <= PROD_DEVELOPMENT )
    {
      v5 = false;
      idParser::ExpectTokenString(this: src, string: "{");
      while ( idParser::CheckTokenString(this: src, string: "}") == 0 )
      {
        idParser::ExpectAnyToken(this: src, token: &v6);
        idParser::ExpectTokenString(this: src, string: "=");
        if ( idStr::Icmp(s1: v6.data, s2: "rotatable") != 0 )
        {
          if ( idStr::Icmp(s1: v6.data, s2: "showOrientation") != 0 )
          {
            if ( idStr::Icmp(s1: v6.data, s2: "noClip") != 0 )
            {
              if ( idStr::Icmp(s1: v6.data, s2: "showFixedBox") != 0 )
              {
                if ( idStr::Icmp(s1: v6.data, s2: "showInRenderMode") != 0 )
                {
                  if ( idStr::Icmp(s1: v6.data, s2: "placeable") != 0 )
                  {
                    if ( idStr::Icmp(s1: v6.data, s2: "instantiable") != 0 )
                    {
                      if ( idStr::Icmp(s1: v6.data, s2: "color") != 0 )
                      {
                        if ( idStr::Icmp(s1: v6.data, s2: "size") != 0 )
                        {
                          if ( idStr::Icmp(s1: v6.data, s2: "originOffset") != 0 )
                          {
                            if ( idStr::Icmp(s1: v6.data, s2: "material") != 0 )
                            {
                              if ( idStr::Icmp(s1: v6.data, s2: "animName") != 0 )
                              {
                                if ( idStr::Icmp(s1: v6.data, s2: "animFrame") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v6.data, s2: "deprecated") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v6.data, s2: "editorName") == 0 )
                                    {
                                      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v6);
                                      idStr::operator=(this: &this->editorName, text: &v6);
                                    }
                                  }
                                  else
                                  {
                                    v5 = idParser::ParseBool(this: src);
                                  }
                                }
                                else
                                {
                                  this->animFrame = idParser::ParseInt(this: src);
                                }
                              }
                              else
                              {
                                idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v6);
                                idAtomicString::Set(this: &this->animName, str_: v6.data);
                              }
                            }
                            else
                            {
                              idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v6);
                              idAtomicString::Set(this: &this->material, str_: v6.data);
                            }
                          }
                          else
                          {
                            idParser::CheckTokenType(this: src, type: 5, subtype: 44, token: &v6);
                            this->originOffset.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                            this->originOffset.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                            this->originOffset.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            idParser::CheckTokenType(this: src, type: 5, subtype: 45, token: &v6);
                          }
                        }
                        else
                        {
                          idParser::CheckTokenType(this: src, type: 5, subtype: 44, token: &v6);
                          this->size.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                          this->size.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                          this->size.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          idParser::CheckTokenType(this: src, type: 5, subtype: 45, token: &v6);
                        }
                      }
                      else
                      {
                        idParser::CheckTokenType(this: src, type: 5, subtype: 44, token: &v6);
                        this->color.r = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                        this->color.g = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                        this->color.b = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        idParser::CheckTokenType(this: src, type: 5, subtype: 40, token: &v6);
                        this->color.a = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        idParser::CheckTokenType(this: src, type: 5, subtype: 45, token: &v6);
                      }
                    }
                    else
                    {
                      *((_BYTE *)this + 84) = (4 * idParser::ParseBool(this: src)) & 4 | *((_BYTE *)this + 84) & 0xFB;
                    }
                  }
                  else
                  {
                    *((_BYTE *)this + 84) = (8 * idParser::ParseBool(this: src)) & 8 | *((_BYTE *)this + 84) & 0xF7;
                  }
                }
                else
                {
                  *((_BYTE *)this + 84) = (16 * idParser::ParseBool(this: src)) & 0x10 | *((_BYTE *)this + 84) & 0xEF;
                }
              }
              else
              {
                *((_BYTE *)this + 84) = (32 * idParser::ParseBool(this: src)) & 0x20 | *((_BYTE *)this + 84) & 0xDF;
              }
            }
            else
            {
              *((_BYTE *)this + 84) = (2 * idParser::ParseBool(this: src)) & 2 | *((_BYTE *)this + 84) & 0xFD;
            }
          }
          else
          {
            *((_BYTE *)this + 84) = (idParser::ParseBool(this: src) << 6) & 0x40 | *((_BYTE *)this + 84) & 0xBF;
          }
        }
        else
        {
          *((_BYTE *)this + 84) = (idParser::ParseBool(this: src) << 7) | *((_BYTE *)this + 84) & 0x7F;
        }
        idParser::SkipUntilString(this: src, string: ";");
      }
      if ( v5 )
        *((_BYTE *)this + 84) &= ~8u;
      idStr::FreeData(this: &v8);
    }
    else
    {
      idParser::SkipBracedSection(this: src, parseFirstBrace: true);
      idStr::FreeData(this: &v8);
    }
    idStr::FreeData(this: &v6);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v8);
    idStr::FreeData(this: &v6);
    return 0;
  }
}


// ========================================================================
// __unwind$221064
// EA  : 0x826193F4
// RVA : 0x006193F4
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221064()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 912 + 96));
}


// ========================================================================
// __unwind$221065
// EA  : 0x8261941C
// RVA : 0x0061941C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221065()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 912 + 432));
}


// ========================================================================
// ?Write@idEntityDefEditorVars@@QBA_NPBVidDeclEntityDef@@AAVidFile@@@Z
// EA  : 0x82619728
// RVA : 0x00619728
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idEntityDefEditorVars::Write(
        idEntityDefEditorVars *this,
        const idDeclEntityDef *parentDef,
        idFile *file)
{
  const idEntityDefEditorVars *v6; // r3
  char v7; // r30
  const char *v8; // r5
  const char *v9; // r5
  const char *v10; // r5
  const char *v11; // r5
  const char *v12; // r5
  char v13; // r11
  char v14; // r11
  idEntityDefEditorVars v16; // [sp+60h] [-150h] BYREF
  idEntityDefEditorVars v17; // [sp+C0h] [-F0h] BYREF
  idEntityDefEditorVars v18; // [sp+120h] [-90h] BYREF

  if ( idLib::production <= PROD_DEVELOPMENT )
  {
    if ( parentDef != nullptr )
    {
      v6 = idEntityDefEditorVars::idEntityDefEditorVars(this: &v18, __that: &parentDef->editorVars);
      v7 = 1;
    }
    else
    {
      v6 = idEntityDefEditorVars::idEntityDefEditorVars(this: &v17);
      v7 = 2;
    }
    idEntityDefEditorVars::idEntityDefEditorVars(this: &v16, __that: v6);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      idStr::FreeData(this: &v17.editorName);
    }
    if ( (v7 & 1) != 0 )
      idStr::FreeData(this: &v18.editorName);
    file->WriteFloatString(this: file, a2: "\teditorVars {\n");
    if ( parentDef == nullptr || ((*((unsigned __int8 *)this + 84) ^ *((unsigned __int8 *)&v16 + 84)) & 0x80) != 0 )
    {
      v8 = "true";
      if ( (*((_BYTE *)this + 84) & 0x80) == 0 )
        v8 = "false";
      file->WriteFloatString(this: file, a2: "\t\trotatable = %s;\n", v8);
    }
    if ( parentDef == nullptr || ((*((unsigned __int8 *)this + 84) ^ *((unsigned __int8 *)&v16 + 84)) & 0x40) != 0 )
    {
      v9 = "true";
      if ( (*((_BYTE *)this + 84) & 0x40) == 0 )
        v9 = "false";
      file->WriteFloatString(this: file, a2: "\t\tshowOrientation = %s;\n", v9);
    }
    if ( parentDef == nullptr || ((*((unsigned __int8 *)this + 84) ^ *((unsigned __int8 *)&v16 + 84)) & 0x20) != 0 )
    {
      v10 = "true";
      if ( (*((_BYTE *)this + 84) & 0x20) == 0 )
        v10 = "false";
      file->WriteFloatString(this: file, a2: "\t\tshowFixedBox = %s;\n", v10);
    }
    if ( parentDef == nullptr || ((*((unsigned __int8 *)this + 84) ^ *((unsigned __int8 *)&v16 + 84)) & 0x10) != 0 )
    {
      v11 = "true";
      if ( (*((_BYTE *)this + 84) & 0x10) == 0 )
        v11 = "false";
      file->WriteFloatString(this: file, a2: "\t\tshowInRenderMode = %s;\n", v11);
    }
    v12 = "true";
    if ( (*((_BYTE *)this + 84) & 8) == 0 )
      v12 = "false";
    file->WriteFloatString(this: file, a2: "\t\tplaceable = %s;\n", v12);
    if ( parentDef == nullptr || idQuat::operator!=(this: &this->color, rhs: &v16.color) )
      file->WriteFloatString(
        this: file,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->color.r)),
        COERCE_UNSIGNED_INT64(this->color.r),
        COERCE_UNSIGNED_INT64(this->color.g),
        COERCE_UNSIGNED_INT64(this->color.b),
        COERCE_UNSIGNED_INT64(this->color.a));
    if ( parentDef == nullptr )
      goto LABEL_40;
    if ( this->size.x != v16.size.x || this->size.y != v16.size.y || (v13 = 1, this->size.z != v16.size.z) )
      v13 = 0;
    if ( v13 == 0 )
LABEL_40:
      file->WriteFloatString(
        this: file,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->size.x)),
        COERCE_UNSIGNED_INT64(this->size.x),
        COERCE_UNSIGNED_INT64(this->size.y),
        COERCE_UNSIGNED_INT64(this->size.z));
    if ( parentDef == nullptr )
      goto LABEL_47;
    if ( this->originOffset.x != v16.originOffset.x
      || this->originOffset.y != v16.originOffset.y
      || (v14 = 1, this->originOffset.z != v16.originOffset.z) )
    {
      v14 = 0;
    }
    if ( v14 == 0 )
LABEL_47:
      file->WriteFloatString(
        this: file,
        a2: "\t\toriginOffset = ( %f, %f, %f );\n",
        (unsigned int)COERCE_UNSIGNED_INT64(this->originOffset.x),
        (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->originOffset.z)),
        (unsigned int)COERCE_UNSIGNED_INT64(this->originOffset.z));
    if ( parentDef == nullptr || this->material.str != v16.material.str )
      file->WriteFloatString(this: file, a2: "\t\tmaterial = \"%s\";\n", this->material.str);
    if ( parentDef == nullptr || this->animName.str != v16.animName.str )
      file->WriteFloatString(this: file, a2: "\t\tanimName = \"%s\";\n", this->animName.str);
    if ( parentDef == nullptr || this->animFrame != v16.animFrame )
      file->WriteFloatString(this: file, a2: "\t\tanimFrame = %d;\n", this->animFrame);
    if ( parentDef == nullptr || idStr::Cmp(s1: this->editorName.data, s2: v16.editorName.data) != 0 )
      file->WriteFloatString(this: file, a2: "\t\teditorName = \"%s\";\n", this->editorName.data);
    file->WriteFloatString(this: file, a2: "\t}\n");
    idStr::FreeData(this: &v16.editorName);
  }
  return 1;
}


// ========================================================================
// __unwind$221507
// EA  : 0x82619C0C
// RVA : 0x00619C0C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221507()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 432;
  if ( (*(_DWORD *)(v0 - 432 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 288));
  }
}


// ========================================================================
// __unwind$221509
// EA  : 0x82619C50
// RVA : 0x00619C50
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221509()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 432;
  if ( (*(_DWORD *)(v0 - 432 + 80) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~2u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 192));
  }
}


// ========================================================================
// __unwind$221511
// EA  : 0x82619C94
// RVA : 0x00619C94
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// ?SetInheritedClass@idDeclEntityDef@@UAAX_N@Z
// EA  : 0x82619CC8
// RVA : 0x00619CC8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetInheritedClass(idDeclEntityDef *this, bool writeEditorVars)
{
  const char *str; // r4
  const idDecl *v5; // r3
  const char *v6; // r3
  const char *v7; // r11
  int v8; // r3
  char v9; // r11
  const char *v10; // r4
  const char *v11; // r3
  int v12; // r29
  const char *v13; // r3
  idFile_Memory v14; // [sp+60h] [-180h] BYREF

  str = this->inherit.str;
  if ( *str != 0 && str != nullptr )
  {
    v5 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: str, makeDefault: false);
    if ( v5 != nullptr )
    {
      v6 = (const char *)((int (__fastcall *)(const idDecl *))v5->__vftable[1].WriteResourceFile)(a1: v5);
      v7 = this->className.str;
      if ( v7 == v6 || (v8 = idStr::Cmp(s1: v7, s2: v6), v9 = 0, v8 == 0) )
        v9 = 1;
      if ( v9 == 0 )
      {
        idFile_Memory::idFile_Memory(this: &v14);
        idFile::WriteFloatString(this: &v14, fmt: "{\n");
        idFile::WriteFloatString(this: &v14, fmt: "\tinherit = \"%s\";\n", this->inherit.str);
        if ( writeEditorVars )
        {
          v10 = this->inherit.str;
          if ( v10 != nullptr )
            v10 = (const char *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclEntityDef::resourceList,
                                  name: v10,
                                  makeDefault: false);
          idEntityDefEditorVars::Write(this: &this->editorVars, parentDef: (const idDeclEntityDef *)v10, file: &v14);
        }
        v11 = this->GetEntityState(this);
        v12 = idStr::Find(str: v11, c: 123, start: 0, end: -1);
        v13 = this->GetEntityState(this);
        idFile::WriteFloatString(this: &v14, fmt: "\tedit = %s", &v13[v12]);
        idDecl::SetText(this: &this->idDecl, text: v14.filePtr, length: 0);
        idDecl::ReParse(this: &this->idDecl, fromDisk: false);
        idFile_Memory::~idFile_Memory(this: &v14);
      }
    }
  }
}


// ========================================================================
// __unwind$221634
// EA  : 0x82619E40
// RVA : 0x00619E40
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221634()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 480 + 96));
}


// ========================================================================
// ?SetEntityState@idDeclEntityDef@@UAAXPBD_N@Z
// EA  : 0x82619E70
// RVA : 0x00619E70
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetEntityState(idDeclEntityDef *this, const char *state, bool writeEditorVars)
{
  int v6; // r25
  int v7; // r10
  int i; // r11
  bool v9; // r29
  char *str; // r11
  char v11; // r11
  bool v12; // zf
  int j; // r30
  const char *v14; // r3
  const char *v15; // r3
  const char *v16; // r4
  const char *v17; // r3
  const char *v18; // r11
  int v19; // r3
  char v20; // r11
  int k; // r30
  const char *v22; // r3
  const char *v23; // r4
  unsigned int v24; // r5
  int m; // r30
  idFile_Memory v26; // [sp+60h] [-1A0h] BYREF

  idFile_Memory::idFile_Memory(this: &v26);
  v6 = 0;
  v7 = 0;
  if ( *state != 0 )
  {
    do
      ++v7;
    while ( state[v7] != 0 );
  }
  for ( i = 0; i < v7; ++v6 )
  {
    if ( state[i] != 9 )
      break;
    ++i;
  }
  v9 = true;
  idFile::WriteFloatString(this: &v26, fmt: "{\n");
  str = (char *)this->inherit.str;
  if ( str == &byte_8200D768 || (v12 = *str != 0, v11 = 0, !v12) )
    v11 = 1;
  if ( v11 == 0 )
  {
    if ( v6 > 0 )
    {
      for ( j = v6; j != 0; --j )
        idFile::WriteFloatString(this: &v26, fmt: "\t");
    }
    v14 = this->GetInherit(this);
    idFile::WriteFloatString(this: &v26, fmt: "inherit = \"%s\";\n", v14);
    v15 = this->GetInherit(this);
    v16 = v15;
    if ( v15 != nullptr )
      v15 = (const char *)idDeclInfo::FindWithInheritance(
                            this: &idDeclEntityDef::resourceList,
                            name: v15,
                            makeDefault: true);
    v17 = (const char *)(*(int (__fastcall **)(const char *, const char *))(*(_DWORD *)v15 + 76))(a1: v15, a2: v16);
    v18 = this->className.str;
    if ( v18 == v17 || (v19 = idStr::Cmp(s1: v18, s2: v17), v20 = 0, v19 == 0) )
      v20 = 1;
    v9 = v20 == 0;
  }
  if ( v9 )
  {
    if ( v6 > 0 )
    {
      for ( k = v6; k != 0; --k )
        idFile::WriteFloatString(this: &v26, fmt: "\t");
    }
    v22 = this->GetClass(this);
    idFile::WriteFloatString(this: &v26, fmt: "class = \"%s\";\n", v22);
  }
  if ( writeEditorVars )
  {
    v23 = this->inherit.str;
    if ( v23 != nullptr )
      v23 = (const char *)idDeclInfo::FindWithInheritance(
                            this: &idDeclEntityDef::resourceList,
                            name: v23,
                            makeDefault: false);
    idEntityDefEditorVars::Write(this: &this->editorVars, parentDef: (const idDeclEntityDef *)v23, file: &v26);
  }
  v24 = 0;
  if ( *state != 0 )
  {
    do
      ++v24;
    while ( state[v24] != 0 );
  }
  idFile_Memory::Write(this: &v26, buffer: state, len: v24);
  idFile::WriteFloatString(this: &v26, fmt: "\n");
  for ( m = 0; m < v6 - 1; ++m )
    idFile::WriteFloatString(this: &v26, fmt: "\t");
  idFile::WriteFloatString(this: &v26, fmt: "}");
  idDecl::SetText(this: &this->idDecl, text: v26.filePtr, length: 0);
  idDecl::ReParse(this: &this->idDecl, fromDisk: false);
  idFile_Memory::~idFile_Memory(this: &v26);
}


// ========================================================================
// __unwind$221703
// EA  : 0x8261A120
// RVA : 0x0061A120
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221703()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 512 + 96));
}


// ========================================================================
// ?GetTextWithInheritance@idDeclEntityDef@@UBAXAAVidStr@@_N@Z
// EA  : 0x8261A150
// RVA : 0x0061A150
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::GetTextWithInheritance(idDeclEntityDef *this, idStr *text, bool stripWhiteSpace)
{
  char *str; // r5
  char v7; // r11
  idFile_Memory v8; // [sp+60h] [-180h] BYREF

  idFile_Memory::idFile_Memory(this: &v8);
  idFile::WriteFloatString(this: &v8, fmt: "{\n");
  str = (char *)this->inherit.str;
  if ( str == &byte_8200D768 || (v7 = 0, *str == 0) )
    v7 = 1;
  if ( v7 == 0 )
    idFile::WriteFloatString(this: &v8, fmt: "inherit = \"%s\";\n", str);
  idFile::WriteFloatString(this: &v8, fmt: "class = \"%s\";\n", this->className.str);
  idFile::WriteFloatString(this: &v8, fmt: "expandInheritance = false;\n");
  idFile_Memory::Write(
    this: &v8,
    buffer: this->entityStateWithInheritanceText.data,
    len: this->entityStateWithInheritanceText.len);
  idStr::operator=(this: text, text: v8.filePtr);
  idStr::Replace(this: text, old: "\n", nw: "\n\t");
  idStr::Append(this: text, text: "\n}");
  if ( stripWhiteSpace )
  {
    idStr::Replace(this: text, old: "\t", nw: " ");
    idStr::Replace(this: text, old: "\r", nw: &byte_8200D768);
    idStr::Replace(this: text, old: "\n", nw: &byte_8200D768);
    idStr::Replace(this: text, old: "   ", nw: " ");
    idStr::Replace(this: text, old: "  ", nw: " ");
  }
  idFile_Memory::~idFile_Memory(this: &v8);
}


// ========================================================================
// __unwind$221797
// EA  : 0x8261A2C4
// RVA : 0x0061A2C4
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221797()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 480 + 96));
}


// ========================================================================
// ?RebuildTextSource@idDeclEntityDef@@UAA_NXZ
// EA  : 0x8261A2F8
// RVA : 0x0061A2F8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

int __fastcall idDeclEntityDef::RebuildTextSource(idDeclEntityDef *this)
{
  const char *v2; // r4
  const idDecl *v3; // r27
  int *v4; // r26
  int v5; // r25
  idTypeInfoSettings *v6; // r3
  int v7; // r3
  idGame *v8; // r26
  idGame_vtbl *v9; // r27
  const char *v10; // r3
  idEntity *v11; // r27
  idGame *v12; // r25
  idGame_vtbl *v13; // r26
  idTypeInfoSettings *v14; // r3
  int v15; // r3
  idEntity *v16; // r26
  idGame *v17; // r3
  idGame *v18; // r3
  idGame *v19; // r3
  idGame *v20; // r3
  idTypeInfoTree v22; // [sp+50h] [-1E0h] BYREF
  idTypeInfoTree v23; // [sp+70h] [-1C0h] BYREF
  idTypeInfoSettings v24; // [sp+88h] [-1A8h] BYREF
  idTypeInfoSettings v25[2]; // [sp+98h] [-198h] BYREF
  idTypeInfoFile v26; // [sp+B0h] [-180h] BYREF
  idTypeInfoFile v27; // [sp+150h] [-E0h] BYREF

  if ( *this->GetInherit(this) != 0 )
  {
    v2 = this->GetInherit(this);
    if ( v2 != nullptr )
      v3 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: v2, makeDefault: false);
    else
      v3 = nullptr;
    v4 = (int *)((int (__fastcall *)(idCommon *, const char *))common->Game)(a1: common, a2: v2);
    v5 = *v4;
    v6 = idTypeInfoSettings::idTypeInfoSettings(this: v25, resolveEntityPointers: false, resolveModelPointers: false);
    v7 = (*(int (__fastcall **)(int *, const idDecl *, idTypeInfoSettings *))(v5 + 472))(a1: v4, a2: v3, a3: v6);
  }
  else
  {
    v8 = common->Game(this: common);
    v9 = v8->__vftable;
    v10 = this->GetClass(this);
    v7 = (int)v9->CreateClass(this: v8, a2: v10);
  }
  v11 = (idEntity *)v7;
  v12 = common->Game(this: common);
  v13 = v12->__vftable;
  v14 = idTypeInfoSettings::idTypeInfoSettings(this: &v24, resolveEntityPointers: false, resolveModelPointers: false);
  v15 = (int)v13->CreateEntityFromDef(this: v12, a2: this, a3: v14);
  v16 = (idEntity *)v15;
  if ( v11 != nullptr && v15 != 0 )
  {
    idTypeInfoFile::idTypeInfoFile(this: &v27, indent_: 0);
    idTypeInfoFile::idTypeInfoFile(this: &v26, indent_: 0);
    v23.nodeBlockAlloc.allowAllocs = true;
    v23.nodeBlockAlloc.clearAllocs = false;
    memset(&v23, 0, 20);
    v22.nodeBlockAlloc.allowAllocs = true;
    v22.nodeBlockAlloc.clearAllocs = false;
    memset(&v22, 0, 20);
    idTypeInfoFile::WriteMemoryFile(this: &v27);
    v27.settings.resolveEntityPointers = false;
    v27.settings.resolveModelPointers = false;
    v17 = common->Game(this: common);
    v17->GetEntityEditState(this: v17, a2: v11, a3: &v27, a4: true);
    idTypeInfoFile::ReadMemoryFile(this: &v27);
    idTypeInfoTree::Parse(this: &v23, file: &v27);
    idTypeInfoFile::WriteMemoryFile(this: &v26);
    v26.settings.resolveEntityPointers = false;
    v26.settings.resolveModelPointers = false;
    v18 = common->Game(this: common);
    v18->GetEntityEditState(this: v18, a2: v16, a3: &v26, a4: true);
    idTypeInfoFile::ReadMemoryFile(this: &v26);
    idTypeInfoTree::Parse(this: &v22, file: &v26);
    idTypeInfoTree::Diff(this: &v22, tree: &v23);
    idTypeInfoTree::ForceRootDifferent(this: &v22, set: true);
    this->SetEntityState_2(this, a2: &v22, a3: true, a4: true);
    idTypeInfoTree::~idTypeInfoTree(this: &v22);
    idTypeInfoTree::~idTypeInfoTree(this: &v23);
    idTypeInfoFile::~idTypeInfoFile(this: &v26);
    idTypeInfoFile::~idTypeInfoFile(this: &v27);
  }
  v19 = common->Game(this: common);
  v19->DeleteEntity(this: v19, a2: v11);
  v20 = common->Game(this: common);
  v20->DeleteEntity(this: v20, a2: v16);
  return 0;
}


// ========================================================================
// __unwind$221848
// EA  : 0x8261A610
// RVA : 0x0061A610
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221848()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 560 + 336));
}


// ========================================================================
// __unwind$221849
// EA  : 0x8261A638
// RVA : 0x0061A638
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221849()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 560 + 176));
}


// ========================================================================
// __unwind$221850
// EA  : 0x8261A660
// RVA : 0x0061A660
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221850()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 560 + 112));
}


// ========================================================================
// __unwind$221851
// EA  : 0x8261A688
// RVA : 0x0061A688
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221851()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 560 + 80));
}


// ========================================================================
// ?TestDefMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8261A6B8
// RVA : 0x0061A6B8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall TestDefMemory_f(const idCmdArgs *args)
{
  int v1; // r27
  int v2; // r26
  int v3; // r28
  idStr *p_debugInfo; // r30
  char *data; // r11
  idList<idVehicleState *,5> v6[5]; // [sp+50h] [-50h] BYREF

  Sys_DumpMemory();
  memset(v6, 0, 14);
  v6[0].listStatic = 0;
  v6[0].memTag = 5;
  idList<idThread *,58>::Clear(this: v6);
  idResourceList::GetLoadedResources(this: &idDeclEntityDef::resourceList, resourceList: (idList<idResource *,99> *)v6);
  v1 = 0;
  v2 = 0;
  if ( v6[0].num > 0 )
  {
    v3 = 0;
    do
    {
      p_debugInfo = &v6[0].list[v3][1].debugInfo;
      v1 += p_debugInfo->len;
      if ( v6[0].list[v3][1].debugInfo.allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: &v6[0].list[v3][1].debugInfo);
        p_debugInfo->allocedAndFlag = 20;
        p_debugInfo->data = p_debugInfo->baseBuffer;
        p_debugInfo->len = 0;
        p_debugInfo->baseBuffer[0] = 0;
      }
      else
      {
        data = v6[0].list[v3][1].debugInfo.data;
        p_debugInfo->len = 0;
        *data = 0;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v6[0].num );
  }
  Sys_DumpMemory();
  idLib::Printf(fmt: "%i total string length in %i entitydefs\n", v1, v6[0].num);
  if ( (v6[0].listStatic == 0 || v6[0].listStatic == 2) && v6[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v6[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$221918
// EA  : 0x8261A7D4
// RVA : 0x0061A7D4
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_221918()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetupEntityStateWithInheritance_r@idDeclEntityDef@@AAAXAAVidTypeInfoTree@@@Z
// EA  : 0x8261A808
// RVA : 0x0061A808
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetupEntityStateWithInheritance_r(idDeclEntityDef *this, idTypeInfoTree *tree)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  char *str; // r11
  char v7; // r11
  bool v8; // zf
  const char *v9; // r4
  idDeclEntityDef *v10; // r3
  idDeclEntityDef *v11; // r29
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int v14; // r29
  const char *FileName; // r26
  int v16; // r25
  const char *v17; // r3
  unsigned __int64 v18; // r6
  const char *v19; // r7
  idPLogScope v20; // [sp+50h] [-100h] BYREF
  idPLogScope v21; // [sp+58h] [-F8h] BYREF
  idTypeInfoFile v22; // [sp+60h] [-F0h] BYREF

  RD_EventBegin(name: "idDeclEntityDef::SetupEntityStateWithInheritance_r");
  LODWORD(v4) = "idDeclEntityDef::SetupEntityStateWithInheritance_r";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v21, pl: &pLog, gMask: v4, label: v5);
  str = (char *)this->inherit.str;
  if ( str == &byte_8200D768 || (v8 = *str != 0, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 == 0 )
  {
    v9 = this->inherit.str;
    if ( v9 != nullptr
      && (v10 = (idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclEntityDef::resourceList,
                                     name: v9,
                                     makeDefault: false),
          v11 = v10,
          v10 != nullptr) )
    {
      idDeclEntityDef::SetupEntityStateWithInheritance_r(this: v10, tree);
      if ( (*((_BYTE *)&v11->idResource + 32) & 0x80) != 0 )
        this->listedParent = v11;
      else
        this->listedParent = v11->listedParent;
    }
    else
    {
      idLib::Warning(fmt: "Unknown entityDef '%s' inherited by '%s'", this->inherit.str, this->name.str);
    }
  }
  idTypeInfoFile::idTypeInfoFile(this: &v22, indent_: 0);
  RD_EventBegin(name: "idDeclEntityDef::SetupEntityStateWithInheritance_r - ReadMemory");
  LODWORD(v12) = "idDeclEntityDef::SetupEntityStateWithInheritance_r - ReadMemory";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &pLog, gMask: v12, label: v13);
  v14 = this->GetEntityStateLineNumber(this);
  FileName = idDecl::GetFileName(this: &this->idDecl);
  v16 = this->GetEntityStateLength(this);
  v17 = this->GetEntityState(this);
  idTypeInfoFile::ReadMemory(this: &v22, data: v17, length: v16, name: FileName, startLine: v14);
  idPLogScope::~idPLogScope(this: &v20);
  RD_EventEnd();
  RD_EventBegin(name: "idDeclEntityDef::SetupEntityStateWithInheritance_r - ParseOverwrite");
  LODWORD(v18) = "idDeclEntityDef::SetupEntityStateWithInheritance_r - ParseOverwrite";
  HIDWORD(v18) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &pLog, gMask: v18, label: v19);
  idTypeInfoTree::ParseOverwrite(this: tree, file: &v22);
  idPLogScope::~idPLogScope(this: &v20);
  RD_EventEnd();
  idTypeInfoFile::~idTypeInfoFile(this: &v22);
  idPLogScope::~idPLogScope(this: &v21);
  RD_EventEnd();
}


// ========================================================================
// __unwind$222051
// EA  : 0x8261A9E8
// RVA : 0x0061A9E8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222051()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 256));
}


// ========================================================================
// __unwind$222052
// EA  : 0x8261AA10
// RVA : 0x0061AA10
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222052()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 88));
}


// ========================================================================
// __unwind$222053
// EA  : 0x8261AA38
// RVA : 0x0061AA38
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222053()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$222054
// EA  : 0x8261AA60
// RVA : 0x0061AA60
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222054()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 257));
}


// ========================================================================
// __unwind$222055
// EA  : 0x8261AA88
// RVA : 0x0061AA88
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222055()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$222056
// EA  : 0x8261AAB0
// RVA : 0x0061AAB0
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222056()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 258));
}


// ========================================================================
// __unwind$222057
// EA  : 0x8261AAD8
// RVA : 0x0061AAD8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222057()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 80));
}


// ========================================================================
// ?SetupEntityStateWithInheritance@idDeclEntityDef@@AAAXXZ
// EA  : 0x8261AB08
// RVA : 0x0061AB08
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::SetupEntityStateWithInheritance(idDeclEntityDef *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned __int64 v4; // r6
  const char *v5; // r7
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const char *TypeInfoString; // r3
  int v9; // r29
  const char *v10; // r3
  char *str; // r11
  char v12; // r11
  bool v13; // zf
  const char *v14; // r4
  const idDeclEntityDef *v15; // r3
  idPLogScope v16[2]; // [sp+50h] [-110h] BYREF
  idTypeInfoTree v17; // [sp+60h] [-100h] BYREF
  idPLogScope v18; // [sp+78h] [-E8h] BYREF
  idTypeInfoFile v19; // [sp+80h] [-E0h] BYREF

  RD_EventBegin(name: "idDeclEntityDef::SetupEntityStateWithInheritance");
  LODWORD(v2) = "idDeclEntityDef::SetupEntityStateWithInheritance";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v18, pl: &pLog, gMask: v2, label: v3);
  if ( this->expandInheritance )
  {
    v17.nodeBlockAlloc.allowAllocs = true;
    v17.nodeBlockAlloc.clearAllocs = false;
    memset(&v17, 0, 20);
    idDeclEntityDef::SetupEntityStateWithInheritance_r(this, tree: &v17);
    idTypeInfoFile::idTypeInfoFile(this: &v19, indent_: 0);
    RD_EventBegin(name: "idTypeInfoFile::WriteMemoryFile");
    LODWORD(v4) = "idTypeInfoFile::WriteMemoryFile";
    HIDWORD(v4) = 2;
    idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v4, label: v5);
    idTypeInfoFile::WriteMemoryFile(this: &v19);
    idPLogScope::~idPLogScope(this: v16);
    RD_EventEnd();
    v19.settings.resolveEntityPointers = false;
    v19.settings.resolveModelPointers = false;
    RD_EventBegin(name: "idTypeInfoTree::Write");
    LODWORD(v6) = "idTypeInfoTree::Write";
    HIDWORD(v6) = 2;
    idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v6, label: v7);
    idTypeInfoTree::Write(this: &v17, file: &v19, onlyDiff: false);
    idPLogScope::~idPLogScope(this: v16);
    RD_EventEnd();
    TypeInfoString = idTypeInfoFile::GetTypeInfoString(this: &v19);
    idStr::operator=(this: &this->entityStateWithInheritanceText, text: TypeInfoString);
    idTypeInfoFile::~idTypeInfoFile(this: &v19);
    idTypeInfoTree::~idTypeInfoTree(this: &v17);
  }
  else
  {
    v9 = this->GetEntityStateLength(this);
    v10 = this->GetEntityState(this);
    idStr::CopyRange(this: &this->entityStateWithInheritanceText, text: v10, start: 0, end: v9);
    str = (char *)this->inherit.str;
    if ( str == &byte_8200D768 || (v13 = *str != 0, v12 = 0, !v13) )
      v12 = 1;
    if ( v12 == 0 )
    {
      v14 = this->inherit.str;
      if ( v14 != nullptr )
        v15 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclEntityDef::resourceList,
                                         name: v14,
                                         makeDefault: false);
      else
        v15 = nullptr;
      this->listedParent = v15;
    }
  }
  idPLogScope::~idPLogScope(this: &v18);
  RD_EventEnd();
}


// ========================================================================
// __unwind$222177
// EA  : 0x8261ACEC
// RVA : 0x0061ACEC
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222177()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 288));
}


// ========================================================================
// __unwind$222178
// EA  : 0x8261AD14
// RVA : 0x0061AD14
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222178()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 120));
}


// ========================================================================
// __unwind$222179
// EA  : 0x8261AD3C
// RVA : 0x0061AD3C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222179()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$222180
// EA  : 0x8261AD64
// RVA : 0x0061AD64
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222180()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$222181
// EA  : 0x8261AD8C
// RVA : 0x0061AD8C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222181()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 289));
}


// ========================================================================
// __unwind$222182
// EA  : 0x8261ADB4
// RVA : 0x0061ADB4
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222182()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$222183
// EA  : 0x8261ADDC
// RVA : 0x0061ADDC
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222183()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 290));
}


// ========================================================================
// __unwind$222184
// EA  : 0x8261AE04
// RVA : 0x0061AE04
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222184()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 80));
}


// ========================================================================
// ?Parse@idDeclEntityDef@@UAAXAAVidParser@@@Z
// EA  : 0x8261AE38
// RVA : 0x0061AE38
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __fastcall idDeclEntityDef::Parse(idDeclEntityDef *this, idParser *src)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idLexer *scriptstack; // r11
  int v7; // r10
  idAtomicString *p_inherit; // r28
  idLexer *v9; // r11
  int v10; // r11
  idAtomicString *p_className; // r27
  idLexer *v12; // r11
  int v13; // r11
  char v14; // r11
  const idDecl *v15; // r3
  const idDecl *v16; // r30
  char v17; // r11
  bool v18; // r28
  char v19; // r11
  void (__fastcall *WriteResourceFile)(struct idDecl *); // ctr
  const char *v21; // r3
  const char *str; // r28
  const char *v23; // r3
  const idDecl *v24; // r3
  const char *v25; // r30
  void (__fastcall *v26)(struct idDecl *); // ctr
  const char *v27; // r3
  char v28; // r11
  idLexer *v29; // r11
  int v30; // r11
  idLexer *v31; // r11
  int v32; // r11
  idLexer *v33; // r11
  int line; // r30
  idPLogScope v35; // [sp+58h] [-1B8h] BYREF
  idToken v36; // [sp+60h] [-1B0h] BYREF
  char v37; // [sp+A8h] [-168h] BYREF

  RD_EventBegin(name: "idDeclEntityDef::Parse");
  LODWORD(v4) = "idDeclEntityDef::Parse";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v35, pl: &pLog, gMask: v4, label: v5);
  v36.baseBuffer[0] = 0;
  v36.intvalue = 0;
  v36.floatvalue = -3.4028235e38;
  memset(&v36.whiteSpaceStart_p, 0, 12);
  v37 = 0;
  v36.data = &v37;
  v36.len = 0;
  v36.allocedAndFlag = -2147483392;
  if ( com_traceDeclEntityDef.valueInteger > 0 )
    idCVar::SetInteger(this: &com_traceDeclEntityDef, newValue: com_traceDeclEntityDef.valueInteger - 1, force: true);
  scriptstack = src->scriptstack;
  if ( scriptstack != nullptr )
    v7 = scriptstack->script_p - scriptstack->buffer;
  else
    v7 = 0;
  this->stateOffset = v7;
  p_inherit = &this->inherit;
  idAtomicString::Set(this: &this->inherit, str_: &byte_8200D768);
  if ( idParser::CheckTokenString(this: src, string: "inherit") != 0 )
  {
    idParser::ExpectTokenString(this: src, string: "=");
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v36);
    idAtomicString::Set(this: &this->inherit, str_: v36.data);
    idParser::ExpectTokenString(this: src, string: ";");
    v9 = src->scriptstack;
    if ( v9 != nullptr )
      v10 = v9->script_p - v9->buffer;
    else
      v10 = 0;
    this->stateOffset = v10;
  }
  p_className = &this->className;
  idAtomicString::Set(this: &this->className, str_: &byte_8200D768);
  if ( idParser::CheckTokenString(this: src, string: "class") != 0 )
  {
    idParser::ExpectTokenString(this: src, string: "=");
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v36);
    idAtomicString::Set(this: &this->className, str_: v36.data);
    idParser::ExpectTokenString(this: src, string: ";");
    v12 = src->scriptstack;
    if ( v12 != nullptr )
      v13 = v12->script_p - v12->buffer;
    else
      v13 = 0;
    this->stateOffset = v13;
  }
  if ( p_inherit->str == &byte_8200D768 || (v14 = 0, *p_inherit->str == 0) )
    v14 = 1;
  if ( v14 == 0 )
  {
    if ( p_inherit->str != nullptr
      && (v15 = idDeclInfo::FindWithInheritance(
                  this: &idDeclEntityDef::resourceList,
                  name: p_inherit->str,
                  makeDefault: false),
          v16 = v15,
          v15 != nullptr) )
    {
      declManager->AddDependency_2(this: declManager, a2: (idDecl *)this, a3: v15);
      v18 = (*((_BYTE *)&this->editorVars + 84) & 8) != 0;
      idEntityDefEditorVars::operator=(this: &this->editorVars, __that: (const idEntityDefEditorVars *)&v16[1].name);
      *((_BYTE *)&this->editorVars + 84) = (8 * v18) & 8 | *((_BYTE *)&this->editorVars + 84) & 0xF7;
      if ( p_className->str == &byte_8200D768 || (v19 = 0, *p_className->str == 0) )
        v19 = 1;
      WriteResourceFile = v16->__vftable[1].WriteResourceFile;
      if ( v19 != 0 )
      {
        v21 = (const char *)((int (__fastcall *)(const idDecl *))WriteResourceFile)(a1: v16);
        idAtomicString::Set(this: &this->className, str_: v21);
      }
      else
      {
        str = p_className->str;
        v23 = (const char *)((int (__fastcall *)(const idDecl *))WriteResourceFile)(a1: v16);
        if ( !idTypeInfoTools::IsSubclassOf(this: typeInfoTools, typeName: str, superType: v23) )
        {
          v24 = v16;
          v26 = v16->__vftable[1].WriteResourceFile;
          v25 = p_className->str;
          v27 = (const char *)((int (__fastcall *)(const idDecl *))v26)(a1: v24);
          idParser::Error(this: src, str: "Class %s does not derive from %s", v25, v27);
        }
      }
    }
    else
    {
      idParser::Warning(this: src, str: "Unknown entityDef '%s' inherited by '%s'", p_inherit->str, this->name.str);
      if ( p_className->str == &byte_8200D768 || (v17 = 0, *p_className->str == 0) )
        v17 = 1;
      if ( v17 != 0 )
        idAtomicString::Set(this: &this->className, str_: "idEntity");
    }
  }
  if ( p_className->str == &byte_8200D768 || (v28 = 0, *p_className->str == 0) )
    v28 = 1;
  if ( v28 != 0 )
    idParser::Error(this: src, str: "No class specified");
  if ( idParser::CheckTokenString(this: src, string: "expandInheritance") != 0 )
  {
    idParser::ExpectTokenString(this: src, string: "=");
    this->expandInheritance = idParser::ParseBool(this: src);
    idParser::ExpectTokenString(this: src, string: ";");
    v29 = src->scriptstack;
    if ( v29 != nullptr )
      v30 = v29->script_p - v29->buffer;
    else
      v30 = 0;
    this->stateOffset = v30;
  }
  if ( (unsigned __int8)idEntityDefEditorVars::Parse(this: &this->editorVars, src) != 0 )
  {
    v31 = src->scriptstack;
    if ( v31 != nullptr )
      v32 = v31->script_p - v31->buffer;
    else
      v32 = 0;
    this->stateOffset = v32;
  }
  v33 = src->scriptstack;
  if ( v33 != nullptr )
    line = v33->line;
  else
    line = 0;
  this->stateLineNumberOffset = line - idDecl::GetLineNum(this: &this->idDecl);
  idDeclEntityDef::SetupEntityStateWithInheritance(this);
  idStr::FreeData(this: &v36);
  idPLogScope::~idPLogScope(this: &v35);
  RD_EventEnd();
}


// ========================================================================
// __unwind$222301
// EA  : 0x8261B2FC
// RVA : 0x0061B2FC
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222301()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 528 + 424));
}


// ========================================================================
// __unwind$222302
// EA  : 0x8261B324
// RVA : 0x0061B324
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222302()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 528 + 88));
}


// ========================================================================
// __unwind$222303
// EA  : 0x8261B34C
// RVA : 0x0061B34C
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void _unwind_222303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 96));
}


// ========================================================================
// `dynamic initializer for 'com_traceDeclEntityDef''
// EA  : 0x833365E8
// RVA : 0x013365E8
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_traceDeclEntityDef__()
{
  idCVar::idCVar(
    this: &com_traceDeclEntityDef,
    name: "com_traceDeclEntityDef",
    value: "0",
    flags: 2,
    description: "number of times tot capture XTraces for idDeclEntityDef::Parse()",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_traceDeclEntityDef__);
}


// ========================================================================
// `dynamic initializer for 'TestDefMemory_v''
// EA  : 0x83336640
// RVA : 0x01336640
// PDB : w:\tech5\engine\decls\declentitydef.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestDefMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestDefMemory_v,
           cmdName: "TestDefMemory",
           function: TestDefMemory_f,
           description: "Test memory savings",
           argCompletion: nullptr);
}

