
// ========================================================================
// ArgCompletion_MTL
// EA  : 0x825F6780
// RVA : 0x005F6780
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void __fastcall ArgCompletion_MTL(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: "mtl", a5: false);
}


// ========================================================================
// ParseVec3
// EA  : 0x825F6950
// RVA : 0x005F6950
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idVec3 *__fastcall ParseVec3(idVec3 *result, idLexer *src)
{
  char *data; // r3
  double x; // fp0
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  idLexer::ParseRestOfLine(this: src, out: v6);
  data = v6[0].data;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( sscanf(string: data, format: "%f %f %f", result, &result->y, &result->z) == 1 )
  {
    x = result->x;
    result->z = result->x;
    result->y = x;
  }
  idStr::FreeData(this: v6);
  return result;
}


// ========================================================================
// __unwind$220407
// EA  : 0x825F69EC
// RVA : 0x005F69EC
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_220407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?ExtractFinalFilename@@YA?AVidStr@@QBD@Z
// EA  : 0x825F6F28
// RVA : 0x005F6F28
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idStr *__fastcall ExtractFinalFilename(idStr *result, const char *str)
{
  int v3; // r29
  const char *v4; // r11
  int v5; // r10
  int i; // r11
  const char *v7; // r30
  unsigned int allocedAndFlag; // r11
  int v9; // r4
  int v10; // r11
  bool v11; // zf
  char *v12; // r10
  char *v13; // r9
  char v14; // r11

  v3 = 0;
  v4 = str;
  do
    v5 = *(unsigned __int8 *)v4++;
  while ( v5 != 0 );
  for ( i = v4 - str - 2; i >= 0; --i )
  {
    if ( str[i] <= 32 )
      break;
  }
  result->len = 0;
  result->allocedAndFlag = 20;
  v7 = &str[i + 1];
  result->data = result->baseBuffer;
  result->baseBuffer[0] = 0;
  if ( &str[i] != (const char *)-1 )
  {
    if ( *v7 != 0 )
    {
      do
        ++v3;
      while ( v7[v3] != 0 );
    }
    allocedAndFlag = result->allocedAndFlag;
    v9 = v3 + 1;
    v11 = allocedAndFlag >> 31 == 0;
    v10 = allocedAndFlag & 0x7FFFFFFF;
    if ( v11 )
    {
      if ( v9 > v10 )
        idStr::ReAllocate(this: result, amount: v9, keepold: true);
    }
    else if ( v9 > v10
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    v12 = (char *)(v7 - 1);
    v13 = result->data - 1;
    do
    {
      v14 = *++v12;
      *++v13 = *v12;
    }
    while ( v14 != 0 );
    result->len = v3;
  }
  return result;
}


// ========================================================================
// ?StripBaseDirFromFilename@@YA?AVidStr@@QBD@Z
// EA  : 0x825F7050
// RVA : 0x005F7050
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idStr *__fastcall StripBaseDirFromFilename(idStr *result, const char *str)
{
  char *v4; // r3
  const char *v5; // r4

  v4 = strstr(str1: str, str2: "base/");
  if ( v4 != nullptr || (v4 = strstr(str1: str, str2: "base\\"), v5 = str, v4 != nullptr) )
    v5 = v4 + 5;
  idStr::idStr(this: result, text: v5);
  return result;
}


// ========================================================================
// ?TestExtractFinalFilename_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x825F70D0
// RVA : 0x005F70D0
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void __fastcall TestExtractFinalFilename_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr v2; // [sp+50h] [-60h] BYREF
  idStr v3; // [sp+70h] [-40h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  ExtractFinalFilename(result: &v2, str: v1);
  idLib::Printf(fmt: "final file name: %s\n", v2.data);
  StripBaseDirFromFilename(result: &v3, str: v2.data);
  idLib::Printf(fmt: "final file name: %s\n", v3.data);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v2);
}


// ========================================================================
// __unwind$221328
// EA  : 0x825F7160
// RVA : 0x005F7160
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221328()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$221329
// EA  : 0x825F7188
// RVA : 0x005F7188
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221329()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?LocalFileNameToGameFileName@@YA?AVidStr@@QBD0@Z
// EA  : 0x825F7778
// RVA : 0x005F7778
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idStr *__fastcall LocalFileNameToGameFileName(idStr *result, const char *localFileName, const char *currentDirectory)
{
  idStr v6; // [sp+60h] [-80h] BYREF
  idStr v7; // [sp+80h] [-60h] BYREF
  idStr v8[2]; // [sp+A0h] [-40h] BYREF

  idStr::idStr(this: &v6, text: localFileName);
  idStr::MakeNameCanonical(this: &v6);
  if ( idStr::Find(searchIn: v6.data, searchFor: ":", casesensitive: true, start: 0, end: v6.len) != -1
    || *v6.data == 47 )
  {
    StripBaseDirFromFilename(result: v8, str: v6.data);
    idStr::idStr(this: result, text: v8);
    idStr::FreeData(this: v8);
  }
  else
  {
    idStr::idStr(this: &v7, text: currentDirectory);
    idStr::StripTrailing(this: &v7, c: 47);
    idStr::StripTrailing(this: &v7, c: 92);
    idStr::Append(this: &v7, text: "/");
    idStr::Append(this: &v7, text: &v6);
    idStr::idStr(this: result, text: &v7);
    idStr::FreeData(this: &v7);
  }
  idStr::FreeData(this: &v6);
  return result;
}


// ========================================================================
// __unwind$221684
// EA  : 0x825F7878
// RVA : 0x005F7878
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$221685
// EA  : 0x825F78A0
// RVA : 0x005F78A0
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221685()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$221686
// EA  : 0x825F78C8
// RVA : 0x005F78C8
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221686()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 224;
  if ( (*(_DWORD *)(v0 - 224 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 244));
  }
}


// ========================================================================
// __unwind$221689
// EA  : 0x825F790C
// RVA : 0x005F790C
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221689()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 160));
}


// ========================================================================
// ?DeclMaterialForParsedMtl@@YAPBVidMaterial@@ABVidParsedMtl@@VidMtlOptions@@@Z
// EA  : 0x825F7940
// RVA : 0x005F7940
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

const idMaterial *__fastcall DeclMaterialForParsedMtl(const idParsedMtl *mtl, const idMtlOptions *mtlOptions)
{
  idDecl *v4; // r3
  const idMaterial *MaterialOrAutoMaterial; // r30
  idStr v7; // [sp+50h] [-D0h] BYREF
  idStr v8; // [sp+70h] [-B0h] BYREF
  idStr v9; // [sp+90h] [-90h] BYREF
  idStr v10; // [sp+B0h] [-70h] BYREF
  idStr v11[2]; // [sp+D0h] [-50h] BYREF

  v4 = (idDecl *)idResourceList::Load(
                   this: &idMaterial::resourceList,
                   name: mtl->mtlName.data,
                   makeDefault: false,
                   skipStaleCheck: false);
  MaterialOrAutoMaterial = (const idMaterial *)v4;
  if ( v4 == nullptr || idDecl::IsImplicit(this: v4) )
  {
    ExtractFinalFilename(result: &v8, str: mtl->map_Kd.data);
    if ( v8.len != 0 )
    {
      idStr::idStr(this: &v7, text: &v8);
      idStr::ToLower(this: &v7);
      idStr::BackSlashesToSlashes(this: &v7);
      idStr::GetFilePath(this: v11, result: &mtlOptions->loadedFile);
      LocalFileNameToGameFileName(result: &v10, localFileName: v7.data, currentDirectory: v11[0].data);
      idStr::GetWithoutExtension(this: &v9, result: &v10);
      MaterialOrAutoMaterial = (const idMaterial *)idResourceList::Load(
                                                     this: &idMaterial::resourceList,
                                                     name: v9.data,
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
      idStr::FreeData(this: &v9);
      idStr::FreeData(this: &v10);
      idStr::FreeData(this: v11);
      idStr::FreeData(this: &v7);
    }
    else
    {
      MaterialOrAutoMaterial = FindMaterialOrAutoMaterial(name: mtl->mtlName.data);
    }
    idStr::FreeData(this: &v8);
  }
  idStr::FreeData(this: &mtlOptions->loadedFile);
  return MaterialOrAutoMaterial;
}


// ========================================================================
// __unwind$221766
// EA  : 0x825F7A60
// RVA : 0x005F7A60
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 288 + 316));
}


// ========================================================================
// __unwind$221767
// EA  : 0x825F7A88
// RVA : 0x005F7A88
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221767()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$221768
// EA  : 0x825F7AB0
// RVA : 0x005F7AB0
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221768()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$221769
// EA  : 0x825F7AD8
// RVA : 0x005F7AD8
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221769()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 208));
}


// ========================================================================
// __unwind$221770
// EA  : 0x825F7B00
// RVA : 0x005F7B00
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221770()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 176));
}


// ========================================================================
// __unwind$221771
// EA  : 0x825F7B28
// RVA : 0x005F7B28
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_221771()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// ?ParseMtlFile@@YA_NQBDAAV?$idList@VidParsedMtl@@$04@@@Z
// EA  : 0x825F7E88
// RVA : 0x005F7E88
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

int __fastcall ParseMtlFile(const char *mtlText, idList<idParsedMtl,5> *parsedMtls)
{
  const char *v4; // r11
  int v5; // r10
  idToken v7; // [sp+60h] [-400h] BYREF
  const char *v8; // [sp+A8h] [-3B8h]
  const char *v9; // [sp+ACh] [-3B4h]
  const char *v10; // [sp+B0h] [-3B0h]
  const char *v11; // [sp+B4h] [-3ACh]
  const char *v12; // [sp+B8h] [-3A8h]
  const char *v13; // [sp+BCh] [-3A4h]
  const char *v14; // [sp+C0h] [-3A0h]
  const char *v15; // [sp+C4h] [-39Ch]
  const char *v16; // [sp+C8h] [-398h]
  const char *v17; // [sp+CCh] [-394h]
  idStr v18; // [sp+D0h] [-390h] BYREF
  idStr v19; // [sp+F0h] [-370h] BYREF
  idLexer v20; // [sp+110h] [-350h] BYREF
  idVec3 v21; // [sp+198h] [-2C8h] BYREF
  idVec3 v22; // [sp+1A8h] [-2B8h] BYREF
  idVec3 v23; // [sp+1B8h] [-2A8h] BYREF
  idVec3 v24; // [sp+1C8h] [-298h] BYREF
  idVec3 v25[2]; // [sp+1D8h] [-288h] BYREF
  idParsedMtl v26; // [sp+1F0h] [-270h] BYREF

  if ( parsedMtls->listStatic == 0 || parsedMtls->listStatic == 2 )
  {
    if ( parsedMtls->list != nullptr )
      idListArrayDelete<idParsedMtl>(ptr: parsedMtls->list, num: parsedMtls->size);
    parsedMtls->list = nullptr;
    parsedMtls->size = 0;
  }
  parsedMtls->num = 0;
  idLexer::idLexer(this: &v20, flags_: 8724);
  v4 = mtlText;
  do
    v5 = *(unsigned __int8 *)v4++;
  while ( v5 != 0 );
  if ( !idLexer::LoadMemory(this: &v20, ptr: mtlText, length_: v4 - mtlText - 1, name: "parsed mtl file") )
  {
    idLexer::~idLexer(this: &v20);
    return 0;
  }
  v7.len = 0;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  v7.data = v7.baseBuffer;
  v7.allocedAndFlag = 20;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v7.floatvalue = -3.4028235e38;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.len = 0;
  v18.baseBuffer[0] = 0;
  if ( !idLexer::ReadToken(this: &v20, token: &v7) )
  {
LABEL_72:
    idStr::FreeData(this: &v18);
    idStr::FreeData(this: &v7);
    idLexer::~idLexer(this: &v20);
    return 1;
  }
  v13 = "map_opacity";
  v9 = "map_ns";
  v8 = "tf";
  v11 = "map_bump";
  v10 = "map_refl";
  v14 = "map_ke";
  v17 = "map_d";
  v15 = "bump";
  v16 = "map_ks";
  v12 = "map_kd";
  while ( 1 )
  {
    idStr::ToLower(this: &v7);
    if ( idStr::Cmp(s1: v7.data, s2: "#") != 0 )
      break;
    idLexer::ParseCompleteLine(this: &v20, out: &v18);
LABEL_71:
    if ( !idLexer::ReadToken(this: &v20, token: &v7) )
      goto LABEL_72;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "newmtl") != 0 )
  {
    idLexer::ParseCompleteLine(this: &v20, out: &v18);
    idStr::FreeData(this: &v18);
    idStr::FreeData(this: &v7);
    idLexer::~idLexer(this: &v20);
    return 0;
  }
  idParsedMtl::idParsedMtl(this: &v26);
  idLexer::ParseRestOfLine(this: &v20, out: &v26.mtlName);
  if ( !idLexer::ReadToken(this: &v20, token: &v7) )
  {
LABEL_70:
    idList<idParsedMtl,5>::Append(this: parsedMtls, obj: &v26);
    idParsedMtl::~idParsedMtl(this: &v26);
    goto LABEL_71;
  }
  while ( 1 )
  {
    idStr::ToLower(this: &v7);
    if ( idStr::Cmp(s1: v7.data, s2: "#") != 0 )
      break;
    idLexer::ParseCompleteLine(this: &v20, out: &v18);
LABEL_67:
    if ( !idLexer::ReadToken(this: &v20, token: &v7) )
      goto LABEL_70;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "newmtl") == 0 )
  {
    idLexer::UnreadToken(this: &v20);
    goto LABEL_70;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "map_ka") == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_Ka);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v12) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_Kd);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v16) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_Ks);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v14) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_Ke);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v11) == 0 || idStr::Cmp(s1: v7.data, s2: v15) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_bump);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v13) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_opacity);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v17) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_d);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v9) == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_Ns);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v10) == 0 || idStr::Cmp(s1: v7.data, s2: "refl") == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.map_refl);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "decal") == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.decal);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "disp") == 0 )
  {
    idLexer::ParseRestOfLine(this: &v20, out: &v26.disp);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "map_aat") == 0 )
  {
    v19.len = 0;
    v19.data = v19.baseBuffer;
    v19.allocedAndFlag = 20;
    v19.baseBuffer[0] = 0;
    idLexer::ParseRestOfLine(this: &v20, out: &v19);
    idStr::ToLower(this: &v19);
    if ( idStr::Cmp(s1: v19.data, s2: "on") != 0 )
    {
      idStr::FreeData(this: &v19);
      v26.map_aat = false;
    }
    else
    {
      idStr::FreeData(this: &v19);
      v26.map_aat = true;
    }
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "ns") == 0 )
  {
    v26.Ns = idLexer::ParseFloat(this: &v20, errorFlag: nullptr);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "ni") == 0 )
  {
    v26.Ni = idLexer::ParseFloat(this: &v20, errorFlag: nullptr);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "d") == 0 )
  {
    v26.d = idLexer::ParseFloat(this: &v20, errorFlag: nullptr);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "tr") == 0 )
  {
    v26.Tr = idLexer::ParseFloat(this: &v20, errorFlag: nullptr);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "illum") == 0 )
  {
    v26.illum = idLexer::ParseInt(this: &v20);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: v8) == 0 )
  {
    v26.Tf = *ParseVec3(result: &v21, src: &v20);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "ka") == 0 )
  {
    v26.Ka = *ParseVec3(result: &v23, src: &v20);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "kd") == 0 )
  {
    v26.Kd = *ParseVec3(result: v25, src: &v20);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "ks") == 0 )
  {
    v26.Ks = *ParseVec3(result: &v22, src: &v20);
    goto LABEL_67;
  }
  if ( idStr::Cmp(s1: v7.data, s2: "ke") == 0 )
  {
    v26.Ke = *ParseVec3(result: &v24, src: &v20);
    goto LABEL_67;
  }
  idParsedMtl::~idParsedMtl(this: &v26);
  idStr::FreeData(this: &v18);
  idStr::FreeData(this: &v7);
  idLexer::~idLexer(this: &v20);
  return 0;
}


// ========================================================================
// __unwind$222046
// EA  : 0x825F8660
// RVA : 0x005F8660
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222046()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 1120 + 272));
}


// ========================================================================
// __unwind$222047
// EA  : 0x825F8688
// RVA : 0x005F8688
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222047()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 96));
}


// ========================================================================
// __unwind$222048
// EA  : 0x825F86B0
// RVA : 0x005F86B0
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222048()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 208));
}


// ========================================================================
// __unwind$222049
// EA  : 0x825F86D8
// RVA : 0x005F86D8
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222049()
{
  int v0; // r12

  idParsedMtl::~idParsedMtl(this: (idParsedMtl *)(v0 - 1120 + 496));
}


// ========================================================================
// __unwind$222185
// EA  : 0x825F8700
// RVA : 0x005F8700
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222185()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 240));
}


// ========================================================================
// ?LoadAndParseMtlFile@@YA_NQBDAAV?$idList@VidParsedMtl@@$04@@@Z
// EA  : 0x825F8778
// RVA : 0x005F8778
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

char *__fastcall LoadAndParseMtlFile(const char *filename, idList<idParsedMtl,5> *parsedMtls)
{
  char *result; // r3
  int v4; // r31
  char *v5; // [sp+50h] [-20h] BYREF

  fileSystem->ReadFile(this: fileSystem, a2: filename, a3: (void **)&v5, a4: nullptr);
  result = v5;
  if ( v5 != nullptr )
  {
    v4 = ParseMtlFile(mtlText: v5, parsedMtls);
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    return (char *)v4;
  }
  return result;
}


// ========================================================================
// ?testMtlLoader_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x825F8810
// RVA : 0x005F8810
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void __fastcall testMtlLoader_f(const idCmdArgs *args)
{
  int v1; // r30
  idFileList *v2; // r29
  int i; // r28
  idList<idParsedMtl,5> v4[4]; // [sp+60h] [-40h] BYREF

  if ( args->argc == 2 )
  {
    v1 = 0;
    v4[0].listStatic = 0;
    v4[0].memTag = 5;
    memset(v4, 0, 14);
    if ( *args->argv[1] == 42 )
    {
      v2 = fileSystem->ListFilesTree(this: fileSystem, a2: "models", a3: "mtl", a4: 0);
      for ( i = 0; i < v2->list.num; ++v1 )
      {
        idLib::Printf(fmt: "parsing %s.\n", v2->list.list[v1].data);
        LoadAndParseMtlFile(filename: v2->list.list[v1].data, parsedMtls: v4);
        ++i;
      }
      idFileList::~idFileList(this: v2);
      idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
    }
    else
    {
      LoadAndParseMtlFile(filename: args->argv[1], parsedMtls: v4);
    }
    if ( (v4[0].listStatic == 0 || v4[0].listStatic == 2) && v4[0].list != nullptr )
      idListArrayDelete<idParsedMtl>(ptr: v4[0].list, num: v4[0].size);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: testMtlLoader <.mtl file | *>\n");
  }
}


// ========================================================================
// __unwind$222398
// EA  : 0x825F897C
// RVA : 0x005F897C
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222398()
{
  int v0; // r12

  idList<idParsedMtl,5>::~idList<idParsedMtl,5>(this: (idList<idParsedMtl,5> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$222399
// EA  : 0x825F89A4
// RVA : 0x005F89A4
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void _unwind_222399()
{
  int v0; // r12

  std::auto_ptr<idFileList>::~auto_ptr<idFileList>(this: (std::auto_ptr<idFileList> *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'r_fixObjMaterialPath''
// EA  : 0x83336488
// RVA : 0x01336488
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_fixObjMaterialPath__()
{
  idCVar::idCVar(
    this: &r_fixObjMaterialPath,
    name: "r_fixObjMaterialPath",
    value: "0",
    flags: 1,
    description: "temp hack fix for material paths being jumbled up for objs coming out of modo",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_fixObjMaterialPath__);
}


// ========================================================================
// `dynamic initializer for 'TestExtractFinalFilename_v''
// EA  : 0x833364E0
// RVA : 0x013364E0
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestExtractFinalFilename_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestExtractFinalFilename_v,
           cmdName: "TestExtractFinalFilename",
           function: TestExtractFinalFilename_f,
           description: "Test ExtractFinalFilename()",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testMtlLoader_v''
// EA  : 0x83336508
// RVA : 0x01336508
// PDB : w:\tech5\engine\compilers\renderbump\mtltocpuvmtr.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testMtlLoader_v__()
{
  return idCommandLink::idCommandLink(
           this: &testMtlLoader_v,
           cmdName: "testMtlLoader",
           function: testMtlLoader_f,
           description: "Tests the parsing and processing of .mtl files",
           argCompletion: ArgCompletion_MTL);
}

