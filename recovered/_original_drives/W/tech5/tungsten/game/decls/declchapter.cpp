
// ========================================================================
// ?FindVariationById@idDeclChapter@@SAPBVidChapterVariation@@H@Z
// EA  : 0x82BBCDF8
// RVA : 0x00BBCDF8
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

const idChapterVariation *__fastcall idDeclChapter::FindVariationById(idResource_vtbl *id)
{
  int v2; // r31
  idResource *v3; // r3
  int resourceListPtr; // r8
  int v5; // r10
  idResource *nextOnHashChain; // r9
  int v7; // r11

  v2 = 0;
  if ( idDeclChapter::resourceList.num <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = idResourceList::Index(this: &idDeclChapter::resourceList, index: v2);
    if ( v3 != nullptr )
    {
      resourceListPtr = (int)v3[3].resourceListPtr;
      v5 = 0;
      if ( resourceListPtr > 0 )
        break;
    }
LABEL_7:
    if ( ++v2 >= idDeclChapter::resourceList.num )
      return nullptr;
  }
  nextOnHashChain = v3[3].nextOnHashChain;
  v7 = 0;
  while ( (&nextOnHashChain->__vftable)[v7] != id )
  {
    ++v5;
    v7 += 7;
    if ( v5 >= resourceListPtr )
      goto LABEL_7;
  }
  return (const idChapterVariation *)((char *)nextOnHashChain + 28 * v5);
}


// ========================================================================
// ?FindCurrentEntry@idDeclChapter@@SA_NPAH00@Z
// EA  : 0x82BBCE98
// RVA : 0x00BBCE98
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

int __fastcall idDeclChapter::FindCurrentEntry(int *chapterIndex, int *variationIndex, int *partIndex)
{
  idGame *v6; // r3
  const char *data; // r27
  int v8; // r22
  idResource *v9; // r3
  idResource **p_nextOnHashChain; // r24
  int v11; // r23
  int v12; // r26
  int v13; // r28
  int *v14; // r11
  _DWORD *v15; // r31
  int v16; // r30
  const char *v17; // r3
  int v18; // r3
  char v19; // r11
  idGame *v20; // r3
  const idList<idAtomicString,5> *v21; // r29
  int v22; // r3

  v6 = common->Game(this: common);
  data = v6->GetGameSpawnInfo(this: v6)->mapName.data;
  v8 = 0;
  if ( idDeclChapter::resourceList.num <= 0 )
    return 0;
  while ( 1 )
  {
    v9 = idResourceList::Index(this: &idDeclChapter::resourceList, index: v8);
    if ( v9 != nullptr )
    {
      p_nextOnHashChain = &v9[3].nextOnHashChain;
      v11 = 0;
      if ( (int)v9[3].resourceListPtr > 0 )
        break;
    }
LABEL_14:
    if ( ++v8 >= idDeclChapter::resourceList.num )
      return 0;
  }
  v12 = 0;
  while ( 1 )
  {
    v13 = 0;
    v14 = (int *)((char *)*p_nextOnHashChain + v12);
    v15 = v14 + 2;
    if ( v14[3] > 0 )
      break;
LABEL_13:
    ++v11;
    v12 += 28;
    if ( v11 >= (int)p_nextOnHashChain[1] )
      goto LABEL_14;
  }
  v16 = 0;
  while ( 1 )
  {
    v17 = *(const char **)(v16 + *v15 + 16);
    if ( v17 == data || (v18 = idStr::Cmp(s1: v17, s2: data), v19 = 0, v18 == 0) )
      v19 = 1;
    if ( v19 != 0 )
    {
      v20 = common->Game(this: common);
      v21 = (const idList<idAtomicString,5> *)(v16 + *v15);
      v22 = (int)v20->GetGameSpawnInfo(this: v20);
      if ( (unsigned __int8)idDeclChapter::ContainsAll<idStaticList<idStrStatic<128>,256>,idList<idAtomicString,5>>(
                              haystack: (const idStaticList<idStrStatic<128>,256> *)(v22 + 3172),
                              needles: v21) != 0 )
        break;
    }
    ++v13;
    v16 += 20;
    if ( v13 >= v15[1] )
      goto LABEL_13;
  }
  *chapterIndex = v8;
  *variationIndex = v11;
  *partIndex = v13;
  return 1;
}


// ========================================================================
// ?FindCurrentVariation@idDeclChapter@@SAPBVidChapterVariation@@XZ
// EA  : 0x82BBD020
// RVA : 0x00BBD020
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

const idChapterVariation *__fastcall idDeclChapter::FindCurrentVariation()
{
  idResource *v0; // r3
  int v2; // [sp+50h] [-20h] BYREF
  int v3; // [sp+54h] [-1Ch] BYREF
  int v4[4]; // [sp+58h] [-18h] BYREF

  if ( (unsigned __int8)idDeclChapter::FindCurrentEntry(chapterIndex: &v2, variationIndex: &v3, partIndex: v4) == 0 )
    return nullptr;
  v0 = idResourceList::Index(this: &idDeclChapter::resourceList, index: v2);
  return (const idChapterVariation *)((char *)v0[3].nextOnHashChain + 28 * v3);
}


// ========================================================================
// ?FindSecretForEntity@idDeclSecrets@@SAHPBD@Z
// EA  : 0x82BBD090
// RVA : 0x00BBD090
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

int __fastcall idDeclSecrets::FindSecretForEntity(const char *name)
{
  int v2; // r26
  idResource *v3; // r31
  idGame *v4; // r3
  const char *v5; // r4
  int v6; // r3
  char v7; // r11
  idGame *v8; // r3
  int v9; // r3
  idResourceList **p_resourceListPtr; // r29
  int v11; // r28
  int v12; // r30
  idResourceList_vtbl **v13; // r31
  const char *v14; // r3
  int v15; // r3
  char v16; // r11

  v2 = 0;
  if ( idDeclSecrets::resourceList.num <= 0 )
    return -1;
  while ( 1 )
  {
    v3 = idResourceList::Index(this: &idDeclSecrets::resourceList, index: v2);
    if ( v3 != nullptr )
    {
      v4 = common->Game(this: common);
      v5 = v4->GetMapName(this: v4);
      if ( *((const char **)&v3[1] + 8) == v5
        || (v6 = idStr::Cmp(s1: *((const char **)&v3[1] + 8), s2: v5), v7 = 1, v6 == 0) )
      {
        v7 = 0;
      }
      if ( v7 == 0 )
      {
        v8 = common->Game(this: common);
        v9 = (int)v8->GetGameSpawnInfo(this: v8);
        if ( (unsigned __int8)idDeclChapter::ContainsAll<idStaticList<idStrStatic<128>,256>,idList<idAtomicString,5>>(
                                haystack: (const idStaticList<idStrStatic<128>,256> *)(v9 + 3172),
                                needles: (const idList<idAtomicString,5> *)&v3[2]) != 0 )
        {
          p_resourceListPtr = &v3[2].resourceListPtr;
          v11 = 0;
          if ( (int)v3[2].resourceError > 0 )
            break;
        }
      }
    }
LABEL_15:
    if ( ++v2 >= idDeclSecrets::resourceList.num )
      return -1;
  }
  v12 = 0;
  while ( 1 )
  {
    v13 = &(&(*p_resourceListPtr)->__vftable)[v12];
    v14 = (const char *)v13[2];
    if ( v14 == name || (v15 = idStr::Cmp(s1: v14, s2: name), v16 = 0, v15 == 0) )
      v16 = 1;
    if ( v16 != 0 )
      return (int)*v13;
    ++v11;
    v12 += 3;
    if ( v11 >= (int)p_resourceListPtr[1] )
      goto LABEL_15;
  }
}


// ========================================================================
// ?GetLayersParsed@idChapterPart@@QBAXPAVidStr@@@Z
// EA  : 0x82BBD1F8
// RVA : 0x00BBD1F8
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

void __fastcall idChapterPart::GetLayersParsed(idChapterPart *this, idStr *retLayers)
{
  int v4; // r27
  int v5; // r26
  const char *v6; // r10
  int v7; // r11
  int v8; // r30
  int v9; // r11
  char i; // r10
  char *data; // r11

  if ( this->layers.num != 0 )
  {
    idStr::operator=(this: retLayers, text: this->layers.list->str);
    v4 = 1;
    if ( this->layers.num > 1 )
    {
      v5 = 1;
      do
      {
        v6 = ",";
        v7 = 0;
        do
        {
          ++v6;
          ++v7;
        }
        while ( *v6 != 0 );
        v8 = retLayers->len + v7;
        idStr::EnsureAlloced(this: retLayers, amount: v8 + 1, keepold: true, geometricGrowth: true);
        v9 = 0;
        for ( i = 44; i != 0; i = asc_821B1414[v9] )
          retLayers->data[retLayers->len + v9++] = i;
        data = retLayers->data;
        retLayers->len = v8;
        data[v8] = 0;
        idStr::Append(this: retLayers, text: (char *)this->layers.list[v5].str);
        ++v4;
        ++v5;
      }
      while ( v4 < this->layers.num );
    }
  }
  else
  {
    idStr::operator=(this: retLayers, text: &byte_8200D768);
  }
}


// ========================================================================
// ?LoadAllDecls@idDeclChapter@@SAXXZ
// EA  : 0x82BBD2F8
// RVA : 0x00BBD2F8
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

static void __fastcall idDeclChapter::LoadAllDecls()
{
  int v0; // r25
  int num; // r22
  const char *str; // r4
  const idDecl *v3; // r3
  const idDecl *v4; // r28
  idAtomicString *p_name; // r29
  int v6; // r30
  int v7; // r31
  unsigned int v8; // r6
  _BYTE v9[352]; // [sp+50h] [-160h] BYREF

  memset(v9, 0, 256);
  if ( idDeclChapter::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclChapter::resourceList.declSources.num;
    do
    {
      str = idDeclChapter::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
      {
        v3 = idDeclInfo::FindWithInheritance(this: &idDeclChapter::resourceList, name: str, makeDefault: false);
        v4 = v3;
        if ( v3 != nullptr )
        {
          p_name = &v3[2].name;
          v6 = 0;
          if ( (int)v3[2].nextOnHashChain > 0 )
          {
            v7 = 0;
            do
            {
              v8 = *(_DWORD *)&p_name->str[v7];
              if ( v8 >= 0x100 )
              {
                idLib::Warning(
                  fmt: "Variation nr %d in chapter '%s' has invalid id of %d. Id has to be 0 <= id < %d",
                  v6,
                  v4->name.str,
                  v8,
                  256);
              }
              else
              {
                if ( v9[v8] != 0 )
                  idLib::Warning(fmt: "Several variations uses the %d id number.", *(_DWORD *)&p_name->str[v7]);
                v9[*(_DWORD *)&p_name->str[v7]] = 1;
              }
              ++v6;
              v7 += 28;
            }
            while ( v6 < (int)p_name[1].str );
          }
        }
      }
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?LoadAllDecls@idDeclSecretType@@SAXXZ
// EA  : 0x82BBD418
// RVA : 0x00BBD418
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

static void __fastcall idDeclSecretType::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclSecretType::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclSecretType::resourceList.declSources.num;
    do
    {
      str = idDeclSecretType::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclSecretType::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?LoadAllDecls@idDeclSecrets@@SAXXZ
// EA  : 0x82BBD478
// RVA : 0x00BBD478
// PDB : w:\tech5\tungsten\game\decls\declchapter.cpp
// ========================================================================

static void __fastcall idDeclSecrets::LoadAllDecls()
{
  int v0; // r25
  int num; // r22
  const char *str; // r4
  const idDecl *v3; // r3
  const idDecl *v4; // r28
  idResource *v5; // r30
  int v6; // r29
  int v7; // r31
  int *v8; // r11
  int v9; // r6
  _BYTE v10[2144]; // [sp+50h] [-860h] BYREF

  memset(v10, 0, 2048);
  if ( idDeclSecrets::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclSecrets::resourceList.declSources.num;
    do
    {
      str = idDeclSecrets::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
      {
        v3 = idDeclInfo::FindWithInheritance(this: &idDeclSecrets::resourceList, name: str, makeDefault: false);
        v4 = v3;
        if ( v3 != nullptr )
        {
          v5 = (idResource *)((char *)&v3[1].idResource + 32);
          v6 = 0;
          if ( (int)v3[1].textSource > 0 )
          {
            v7 = 0;
            do
            {
              v8 = (int *)((char *)v5->__vftable + v7);
              v9 = *v8;
              if ( *v8 < 0 || v9 >= 2048 )
              {
                idLib::Warning(
                  fmt: "decl '%s' secret '%s' have an invalid id of %d. Has to be 0 <= id < %d",
                  v4->name.str,
                  (const char *)v8[2],
                  v9,
                  2048);
              }
              else
              {
                if ( v10[v9] != 0 )
                  idLib::Warning(fmt: "Several secrets uses the %d id number. ", *v8);
                (*(_BYTE **)((char *)&v5->dtr_idResource + v7))[(unsigned int)v10] = 1;
              }
              ++v6;
              v7 += 12;
            }
            while ( v6 < v5->trackedMemory );
          }
        }
      }
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}

