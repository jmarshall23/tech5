
// ========================================================================
// ?DefaultDefinition@idDeclSkins@@UBAPBDXZ
// EA  : 0x82629DF0
// RVA : 0x00629DF0
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

const char *__fastcall idDeclSkins::DefaultDefinition(idDeclSkins *this)
{
  return "{\n}\n";
}


// ========================================================================
// ?Remap@idSkin@@QBAPBVidMaterial@@PBV2@@Z
// EA  : 0x82629E00
// RVA : 0x00629E00
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

const idMaterial *__fastcall idSkin::Remap(idSkin *this, const idMaterial *mtr)
{
  int num; // r8
  int v3; // r10
  idSkinMapping *list; // r9
  int i; // r11

  num = this->mappings.num;
  v3 = 0;
  if ( num <= 0 )
    return mtr;
  list = this->mappings.list;
  for ( i = 0; list[i].from != mtr; ++i )
  {
    if ( ++v3 >= num )
      return mtr;
  }
  return list[v3].to;
}


// ========================================================================
// ?IndexForSkin@idDeclSkins@@QBAHPBD@Z
// EA  : 0x82629E50
// RVA : 0x00629E50
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

int __fastcall idDeclSkins::IndexForSkin(idDeclSkins *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->skins.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->skins.list[i].name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->skins.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?RebuildTextSource@idDeclSkins@@UAA_NXZ
// EA  : 0x82629EC8
// RVA : 0x00629EC8
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

int __fastcall idDeclSkins::RebuildTextSource(idDeclSkins *this)
{
  __int64 v2; // r8
  __int64 v3; // r6
  int v4; // r24
  __int64 v5; // r10
  int v6; // r30
  va *v7; // r3
  __int64 v8; // r8
  idSkin *list; // r11
  int v10; // r28
  __int64 v11; // r10
  int v12; // r29
  idSkin *v13; // r11
  idSkinMapping *v14; // r11
  const idMaterial *to; // r11
  __int64 v16; // r6
  va *v17; // r3
  int v19; // [sp+8h] [-10B8h]
  int v20; // [sp+Ch] [-10B4h]
  int v21; // [sp+10h] [-10B0h]
  int v22; // [sp+14h] [-10ACh]
  int v23; // [sp+18h] [-10A8h]
  int v24; // [sp+1Ch] [-10A4h]
  idStr v25; // [sp+50h] [-1070h] BYREF
  va v26; // [sp+70h] [-1050h] BYREF

  idStr::idStr(this: &v25, text: "{\n");
  v4 = 0;
  if ( this->skins.num > 0 )
  {
    LODWORD(v5) = &unk_821C0000;
    HIDWORD(v5) = &unk_821C0000;
    v6 = 0;
    do
    {
      HIDWORD(v3) = this->skins.list[v6].name.str;
      v7 = va::va(
             this: &v26,
             fmt: "\t%s {\n",
             a3: v3,
             a4: v2,
             a5: v5,
             a6: v19,
             a7: v20,
             a8: v21,
             a9: v22,
             a10: v23,
             a11: v24);
      idStr::Append(this: &v25, text: v7);
      list = this->skins.list;
      v10 = 0;
      HIDWORD(v11) = list[v6].mappings.num;
      if ( SHIDWORD(v11) > 0 )
      {
        v12 = 0;
        v13 = &list[v6];
        do
        {
          v14 = &v13->mappings.list[v12];
          LODWORD(v11) = v14->from;
          if ( v14->from != nullptr )
          {
            to = v14->to;
            if ( to != nullptr )
            {
              LODWORD(v16) = to->name.str;
              HIDWORD(v16) = *(_DWORD *)(v11 + 8);
              v17 = va::va(
                      this: &v26,
                      fmt: "\t\t\"%s\" \"%s\"\n",
                      a3: v16,
                      a4: v8,
                      a5: v11,
                      a6: v19,
                      a7: v20,
                      a8: v21,
                      a9: v22,
                      a10: v23,
                      a11: v24);
              idStr::Append(this: &v25, text: v17);
            }
          }
          ++v10;
          ++v12;
          v13 = &this->skins.list[v6];
          HIDWORD(v11) = v13->mappings.num;
        }
        while ( v10 < SHIDWORD(v11) );
      }
      idStr::Append(this: &v25, text: "\t}\n");
      ++v4;
      ++v6;
    }
    while ( v4 < this->skins.num );
  }
  idStr::Append(this: &v25, text: "}\n");
  idDecl::SetText(this: &this->idDecl, text: v25.data, length: v25.len);
  idStr::FreeData(this: &v25);
  return 1;
}


// ========================================================================
// __unwind$219940
// EA  : 0x8262A010
// RVA : 0x0062A010
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

void _unwind_219940()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?FreeData@idDeclSkins@@UAAXXZ
// EA  : 0x8262A038
// RVA : 0x0062A038
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

void __fastcall idDeclSkins::FreeData(idDeclSkins *this)
{
  char *list; // r3

  if ( this->skins.listStatic == 0 || this->skins.listStatic == 2 )
  {
    list = (char *)this->skins.list;
    if ( list != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: list, num: this->skins.size);
    this->skins.list = nullptr;
    this->skins.size = 0;
  }
  this->skins.num = 0;
}


// ========================================================================
// ?Parse@idDeclSkins@@UAAXAAVidParser@@@Z
// EA  : 0x8262A2F0
// RVA : 0x0062A2F0
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

void __fastcall idDeclSkins::Parse(idDeclSkins *this, idParser *src)
{
  const idMaterial *v4; // r3
  const idMaterial *v5; // r3
  idSkinMapping v6; // [sp+50h] [-D0h] BYREF
  idSkin v7; // [sp+60h] [-C0h] BYREF
  idToken v8[2]; // [sp+80h] [-A0h] BYREF

  v8[0].len = 0;
  v8[0].allocedAndFlag = 20;
  v8[0].floatvalue = -3.4028235e38;
  v8[0].data = v8[0].baseBuffer;
  v8[0].baseBuffer[0] = 0;
  v8[0].intvalue = 0;
  v8[0].whiteSpaceStart_p = nullptr;
  v8[0].whiteSpaceEnd_p = nullptr;
  v8[0].next = nullptr;
  if ( idParser::CheckTokenString(this: src, string: "}") == 0 )
  {
    while ( 1 )
    {
      v7.mappings.memTag = 46;
      v7.mappings.listStatic = 0;
      memset(&v7.mappings, 0, 14);
      v7.name.str = &byte_8200D768;
      idParser::ExpectAnyToken(this: src, token: v8);
      idAtomicString::Set(this: &v7.name, str_: v8[0].data);
      idParser::ExpectTokenString(this: src, string: "{");
      if ( idParser::CheckTokenString(this: src, string: "}") == 0 )
        break;
LABEL_12:
      if ( v7.mappings.num != 0 )
        idList<idSkin,46>::Append(this: &this->skins, obj: &v7);
      if ( v7.mappings.listStatic == 0 || v7.mappings.listStatic == 2 )
      {
        if ( v7.mappings.list != nullptr )
          idMem::Free(this: &mem, ptr: v7.mappings.list, align: ALIGN_16);
        v7.mappings.list = nullptr;
        v7.mappings.size = 0;
      }
      v7.mappings.num = 0;
      if ( idParser::CheckTokenString(this: src, string: "}") != 0 )
        goto LABEL_20;
    }
    while ( idParser::ReadToken(this: src, token: v8) )
    {
      if ( v8[0].data != nullptr )
        v4 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                   this: &idMaterial::resourceList,
                                   name: v8[0].data,
                                   makeDefault: true);
      else
        v4 = nullptr;
      v6.from = v4;
      if ( !idParser::ReadToken(this: src, token: v8) )
      {
        idParser::Warning(this: src, str: "Unexpected end of file");
        if ( v7.mappings.listStatic == 0 || v7.mappings.listStatic == 2 )
        {
          if ( v7.mappings.list != nullptr )
            idMem::Free(this: &mem, ptr: v7.mappings.list, align: ALIGN_16);
          v7.mappings.list = nullptr;
          v7.mappings.size = 0;
        }
        v7.mappings.num = 0;
        goto LABEL_20;
      }
      if ( v8[0].data != nullptr )
        v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                   this: &idMaterial::resourceList,
                                   name: v8[0].data,
                                   makeDefault: true);
      else
        v5 = nullptr;
      v6.to = v5;
      idList<cachedPageFile_t,5>::Append(this: &v7.mappings, obj: &v6);
      if ( idParser::CheckTokenString(this: src, string: "}") != 0 )
        goto LABEL_12;
    }
    idParser::Warning(this: src, str: "Unexpected end of file");
    if ( v7.mappings.listStatic == 0 || v7.mappings.listStatic == 2 )
    {
      if ( v7.mappings.list != nullptr )
        idMem::Free(this: &mem, ptr: v7.mappings.list, align: ALIGN_16);
      v7.mappings.list = nullptr;
      v7.mappings.size = 0;
    }
    v7.mappings.num = 0;
  }
LABEL_20:
  idStr::FreeData(this: &v8[0]);
}


// ========================================================================
// __unwind$220341
// EA  : 0x8262A580
// RVA : 0x0062A580
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

void _unwind_220341()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$220342
// EA  : 0x8262A5A8
// RVA : 0x0062A5A8
// PDB : w:\tech5\engine\decls\declskins.cpp
// ========================================================================

void _unwind_220342()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 288 + 96));
}

