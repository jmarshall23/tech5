
// ========================================================================
// ?DefaultDefinition@idDeclAnimWeb@@UBAPBDXZ
// EA  : 0x825FE818
// RVA : 0x005FE818
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

const char *__fastcall idDeclAnimWeb::DefaultDefinition(idDeclAnimWeb *this)
{
  return "{\n\tprops {\n\t}\nstates {\n\t}\n\tsubWebs {\n\t}\n}\n";
}


// ========================================================================
// ?GetStateNameAtomic@idDeclAnimWeb@@QBA?BVidAtomicString@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x825FE988
// RVA : 0x005FE988
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::GetStateNameAtomic(
        idDeclAnimWeb *this,
        const idAtomicString *result,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *index)
{
  char v3; // r10

  if ( (__int16)index < 0 || (v3 = 1, (__int16)index >= (int)result[23].str) )
    v3 = 0;
  if ( v3 != 0 )
    this->__vftable = *(idDeclAnimWeb_vtbl **)&result[22].str[4 * (__int16)index];
  else
    this->__vftable = (idDeclAnimWeb_vtbl *)&byte_8200D768;
  return this;
}


// ========================================================================
// ?GetStateIndexForName@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@PBD@Z
// EA  : 0x825FE9D8
// RVA : 0x005FE9D8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::GetStateIndexForName(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *result,
        const char *name)
{
  int v7; // r29
  int v8; // r31

  if ( name != nullptr )
  {
    v7 = 0;
    if ( *(int *)&result[46].value <= 0 )
    {
LABEL_7:
      HIWORD(this->__vftable) = -1;
      return this;
    }
    else
    {
      v8 = 0;
      while ( idStr::Icmp(s1: *(const char **)(*(_DWORD *)&result[44].value + v8), s2: name) != 0 )
      {
        ++v7;
        v8 += 4;
        if ( v7 >= *(_DWORD *)&result[46].value )
          goto LABEL_7;
      }
      HIWORD(this->__vftable) = v7;
      return this;
    }
  }
  else
  {
    idLib::Warning(
      fmt: "idDeclAnimWeb::GetStateIndexForName() - NULL state name passed to animWeb '%s'",
      *(const char **)&result[4].value);
    HIWORD(this->__vftable) = -1;
    return this;
  }
}


// ========================================================================
// ?GetSubWebIndexForName@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PBD@Z
// EA  : 0x825FEA80
// RVA : 0x005FEA80
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::GetSubWebIndexForName(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *result,
        const char *subWebName)
{
  int v6; // r29
  int v7; // r31

  if ( subWebName != nullptr && *subWebName != 0 && (v6 = 0, *(int *)&result[38].value > 0) )
  {
    v7 = 0;
    while ( idStr::Icmp(s1: *(const char **)(*(_DWORD *)&result[36].value + v7 + 16), s2: subWebName) != 0 )
    {
      ++v6;
      v7 += 40;
      if ( v6 >= *(_DWORD *)&result[38].value )
        goto LABEL_7;
    }
    HIWORD(this->__vftable) = v6;
    return this;
  }
  else
  {
LABEL_7:
    HIWORD(this->__vftable) = -1;
    return this;
  }
}


// ========================================================================
// ?GetSubWebName@idDeclAnimWeb@@QBAPBDV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x825FEB18
// RVA : 0x005FEB18
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

const char *__fastcall idDeclAnimWeb::GetSubWebName(
        idDeclAnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *index)
{
  char v2; // r10

  if ( (__int16)index < 0 || (v2 = 1, (__int16)index >= this->subWebs.num) )
    v2 = 0;
  if ( v2 != 0 )
    return this->subWebs.list[(__int16)index].name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetSubWebNameAtomic@idDeclAnimWeb@@QBA?BVidAtomicString@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x825FEB70
// RVA : 0x005FEB70
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::GetSubWebNameAtomic(
        idDeclAnimWeb *this,
        const idAtomicString *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *index)
{
  char v3; // r10

  if ( (__int16)index < 0 || (v3 = 1, (__int16)index >= (int)result[19].str) )
    v3 = 0;
  if ( v3 != 0 )
    this->__vftable = *(idDeclAnimWeb_vtbl **)&result[18].str[40 * (__int16)index + 16];
  else
    this->__vftable = (idDeclAnimWeb_vtbl *)&byte_8200D768;
  return this;
}


// ========================================================================
// ?FindNodeIndex@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x825FEBD0
// RVA : 0x005FEBD0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::FindNodeIndex(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex)
{
  int v4; // r11
  int v5; // r5
  int v6; // r8
  int *v7; // r11
  int v8; // r6
  int v9; // r9
  int v10; // r11
  _WORD *v11; // r10

  v4 = (__int16)subWebIndex;
  if ( (__int16)subWebIndex < 0
    || (v5 = (__int16)stateIndex, (__int16)stateIndex < 0)
    || (v6 = 0, v7 = (int *)(40 * v4 + *(_DWORD *)&result[36].value), (v8 = v7[1]) <= 0) )
  {
LABEL_7:
    HIWORD(this->__vftable) = -1;
  }
  else
  {
    v9 = *v7;
    v10 = 0;
    while ( 1 )
    {
      v11 = *(_WORD **)(4 * *(__int16 *)(v10 + v9) + *(_DWORD *)&result[28].value);
      if ( (__int16)v11[2] == v5 )
        break;
      ++v6;
      v10 += 2;
      if ( v6 >= v8 )
        goto LABEL_7;
    }
    HIWORD(this->__vftable) = *v11;
  }
  return this;
}


// ========================================================================
// ?FindNodeIndex@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABVstateList_t@1@_N@Z
// EA  : 0x825FEC60
// RVA : 0x005FEC60
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::FindNodeIndex(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idDeclAnimWeb::stateList_t *stateList,
        const bool exactMatch)
{
  idDeclAnimWebNode *v9; // r24
  int v10; // r26
  int v11; // r27
  _DWORD *v12; // r30
  int v13; // r29
  idDeclAnimWebNode *v14; // r31
  int matched; // r3

  if ( (__int16)subWebIndex < 0 )
  {
LABEL_12:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  v9 = nullptr;
  v10 = 0;
  v11 = 0;
  v12 = (_DWORD *)(40 * (__int16)subWebIndex + *(_DWORD *)&result[36].value);
  if ( (int)v12[1] <= 0 )
  {
LABEL_8:
    if ( !exactMatch && v9 != nullptr )
    {
      HIWORD(this->__vftable) = v9->nodeIndex.value;
      return this;
    }
    goto LABEL_12;
  }
  v13 = 0;
  while ( 1 )
  {
    v14 = *(idDeclAnimWebNode **)(4 * *(__int16 *)(*v12 + v13) + *(_DWORD *)&result[28].value);
    matched = idDeclAnimWebNode::MatchStates(this: v14, stateIndices: stateList);
    if ( matched == stateList->numStates )
      break;
    if ( matched > v10 )
    {
      v9 = v14;
      v10 = matched;
    }
    ++v11;
    v13 += 2;
    if ( v11 >= v12[1] )
      goto LABEL_8;
  }
  HIWORD(this->__vftable) = v14->nodeIndex.value;
  return this;
}


// ========================================================================
// ?FindModelIndex@idDeclAnimWeb@@QBA?BV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@PBVidDeclMD6@@@Z
// EA  : 0x825FED60
// RVA : 0x005FED60
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::FindModelIndex(
        idDeclAnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *result,
        const idDeclMD6 *decl)
{
  int v3; // r9
  int v4; // r10
  int v5; // r11

  v3 = *(_DWORD *)&result[54].value;
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_5:
    LOWORD(v4) = -1;
  }
  else
  {
    v5 = 0;
    while ( *(const idDeclMD6 **)(v5 + *(_DWORD *)&result[52].value) != decl )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
  HIWORD(this->__vftable) = v4;
  return this;
}


// ========================================================================
// ?GetScalars@idDeclAnimWeb@@QBAABV?$idList@VidAnimWebScalar@@$04@@XZ
// EA  : 0x825FEE00
// RVA : 0x005FEE00
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idList<idAnimWebScalar,32> *__fastcall idDeclAnimWeb::GetScalars(idDeclAnimWeb *this)
{
  return &this->scalars;
}


// ========================================================================
// ?Compare@idSort_LayerName@@QBAHABV?$idIndex@FW4invalidLayerIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x825FEE90
// RVA : 0x005FEE90
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

int __fastcall idSort_LayerName::Compare(
        idSort_LayerName *this,
        const idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *li1,
        const idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *li2)
{
  const idDeclAnimWeb *webDecl; // r7
  int value; // r11
  char v5; // r10
  char *v6; // r10
  bool v7; // zf
  char *str; // r11
  int v9; // r9
  char v10; // r8
  int result; // r3

  webDecl = this->webDecl;
  value = li1->value;
  if ( value < 0 || (v5 = 1, value >= webDecl->layers.num) )
    v5 = 0;
  v7 = v5 == 0;
  v6 = &byte_8200D768;
  if ( v7 )
    str = &byte_8200D768;
  else
    str = (char *)webDecl->layers.list[value].name.str;
  v9 = li2->value;
  if ( v9 < 0 || (v10 = 1, v9 >= webDecl->layers.num) )
    v10 = 0;
  if ( v10 != 0 )
    v6 = (char *)webDecl->layers.list[v9].name.str;
  do
  {
    result = (unsigned __int8)*str - (unsigned __int8)*v6;
    if ( *str == 0 )
      break;
    ++str;
    ++v6;
  }
  while ( result == 0 );
  return result;
}


// ========================================================================
// ?Compare@idSort_SubWebName@@QBAHABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x825FEFB0
// RVA : 0x005FEFB0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

int __fastcall idSort_SubWebName::Compare(
        idSort_SubWebName *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *sw1,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *sw2)
{
  const idDeclAnimWeb *webDecl; // r7
  int value; // r11
  char v5; // r10
  char *str; // r11
  int v7; // r10
  char v8; // r9
  char *v9; // r10
  int result; // r3

  webDecl = this->webDecl;
  value = sw1->value;
  if ( value < 0 || (v5 = 1, value >= webDecl->subWebs.num) )
    v5 = 0;
  if ( v5 != 0 )
    str = (char *)webDecl->subWebs.list[value].name.str;
  else
    str = &byte_8200D768;
  v7 = sw2->value;
  if ( v7 < 0 || (v8 = 1, v7 >= webDecl->subWebs.num) )
    v8 = 0;
  if ( v8 != 0 )
    v9 = (char *)webDecl->subWebs.list[v7].name.str;
  else
    v9 = &byte_8200D768;
  do
  {
    result = (unsigned __int8)*str - (unsigned __int8)*v9;
    if ( *str == 0 )
      break;
    ++str;
    ++v9;
  }
  while ( result == 0 );
  return result;
}


// ========================================================================
// ?GetStateName@idDeclAnimWeb@@QBAPBDV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x825FF0E0
// RVA : 0x005FF0E0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

const char *__fastcall idDeclAnimWeb::GetStateName(
        idDeclAnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *index)
{
  char v2; // r10

  if ( (__int16)index < 0 || (v2 = 1, (__int16)index >= this->states.num) )
    v2 = 0;
  if ( v2 != 0 )
    return this->states.list[(__int16)index].name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetNodeIndexForName@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@PBD0@Z
// EA  : 0x825FF128
// RVA : 0x005FF128
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::GetNodeIndexForName(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *result,
        const char *subWebName,
        const char *stateName)
{
  unsigned __int16 v8; // [sp+50h] [-30h] BYREF
  unsigned __int16 v9; // [sp+52h] [-2Eh] BYREF

  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v9, result, subWebName);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v8,
    (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)result,
    name: stateName);
  return idDeclAnimWeb::FindNodeIndex(
           this,
           (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)result,
           subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v9,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v8);
}


// ========================================================================
// ?FindEdge@idDeclAnimWeb@@QBAPBVidDeclAnimWebEdge@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x825FF178
// RVA : 0x005FF178
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

const idDeclAnimWebEdge *__fastcall idDeclAnimWeb::FindEdge(
        idDeclAnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *srcNode,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *dstNode)
{
  idDeclAnimWebNode *v3; // r11
  int num; // r31
  int v5; // r4
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *list; // r8
  idDeclAnimWebEdge *v7; // r9
  int v8; // r11
  idDeclAnimWeb::idEdgeCache *v9; // r6
  __int16 value; // r10
  const idDeclAnimWebEdge *result; // r3

  if ( (__int16)srcNode == -1 )
    return nullptr;
  v3 = this->nodes.list[(__int16)srcNode];
  if ( v3 == nullptr )
    return nullptr;
  num = v3->edges.num;
  v5 = 0;
  if ( num <= 0 )
    return nullptr;
  list = v3->edges.list;
  v7 = this->edges.list;
  v8 = 0;
  v9 = this->edgeCache.list;
  while ( 1 )
  {
    value = list[v8].value;
    result = &v7[value];
    if ( v9[value].destNodeIndex.value == (__int16)dstNode )
      break;
    ++v5;
    ++v8;
    if ( v5 >= num )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?Compare@idSort_StateName@@QBAHABV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x825FF7E8
// RVA : 0x005FF7E8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

int __fastcall idSort_StateName::Compare(
        idSort_StateName *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *ni1,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *ni2)
{
  int value; // r11
  idDeclAnimWebNode *v4; // r10
  int v5; // r11
  idDeclAnimWebNode *v6; // r9
  const idDeclAnimWeb *webDecl; // r7
  int v8; // r11
  char v9; // r10
  char *v10; // r10
  bool v11; // zf
  char *str; // r11
  int v13; // r8
  char v14; // r9
  int result; // r3

  value = ni1->value;
  if ( value == -1 )
    v4 = nullptr;
  else
    v4 = this->webDecl->nodes.list[value];
  v5 = ni2->value;
  if ( v5 == -1 )
    v6 = nullptr;
  else
    v6 = this->webDecl->nodes.list[v5];
  webDecl = this->webDecl;
  v8 = v4->states.stateIndex[0].value;
  if ( v8 < 0 || (v9 = 1, v8 >= webDecl->states.num) )
    v9 = 0;
  v11 = v9 == 0;
  v10 = &byte_8200D768;
  if ( v11 )
    str = &byte_8200D768;
  else
    str = (char *)webDecl->states.list[v8].name.str;
  v13 = v6->states.stateIndex[0].value;
  if ( v13 < 0 || (v14 = 1, v13 >= webDecl->states.num) )
    v14 = 0;
  if ( v14 != 0 )
    v10 = (char *)webDecl->states.list[v13].name.str;
  do
  {
    result = (unsigned __int8)*str - (unsigned __int8)*v10;
    if ( *str == 0 )
      break;
    ++str;
    ++v10;
  }
  while ( result == 0 );
  return result;
}


// ========================================================================
// ?Size@idDeclAnimWeb@@UBAIXZ
// EA  : 0x825FF950
// RVA : 0x005FF950
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

unsigned int __fastcall idDeclAnimWeb::Size(idDeclAnimWeb *this)
{
  int v2; // r28
  int v3; // r30
  int v4; // r29
  int num; // r3
  int v6; // r7
  int v7; // r6
  int v8; // r11
  idDeclAnimWeb::idSubWebInfo *list; // r5
  int v10; // r10
  int size; // r8
  int v12; // r9
  int v13; // r10
  int v14; // r11

  v2 = 276;
  v3 = 0;
  if ( this->nodes.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      v2 += idDeclAnimWebNode::Size(this: this->nodes.list[v4++]);
    }
    while ( v3 < this->nodes.num );
  }
  num = this->subWebs.num;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( num >= 2 )
  {
    list = this->subWebs.list;
    v10 = 0;
    do
    {
      v8 += 2;
      size = list[v10].nodes.size;
      v12 = list[v10 + 1].nodes.size;
      v10 += 2;
      v6 += 2 * (size + 20);
      v7 += 2 * (v12 + 20);
    }
    while ( v8 < num - 1 );
  }
  if ( v8 < num )
    v2 += 2 * (this->subWebs.list[v8].nodes.size + 20);
  v13 = this->states.num;
  v14 = v7 + v6 + v2;
  if ( v13 > 0 )
    v14 += 4 * v13;
  return 4 * (2 * (4 * this->edges.size + this->nodeCache.size) + this->edgeCache.size + this->models.size)
       + this->edgeIndexCacheSize
       + v14;
}


// ========================================================================
// ?Write@idDeclAnimWeb@@QBAXAAVidFile_String@@PBD@Z
// EA  : 0x82600518
// RVA : 0x00600518
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::Write(idDeclAnimWeb *this, idFile_String *str, __int64 indent, __int64 a4, __int64 a5)
{
  unsigned int v7; // r17
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r6
  __int64 v11; // r8
  va *v12; // r3
  const char *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  va *v20; // r3
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  va *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  va *v28; // r3
  __int64 v29; // r8
  __int64 v30; // r6
  __int64 v31; // r10
  va *v32; // r3
  __int64 v33; // r10
  __int64 v34; // r6
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r6
  __int64 v39; // r8
  va *v40; // r3
  __int64 v41; // r8
  idDeclAnimWeb::subWebBlend_t subWebBlend; // r11
  __int64 v43; // r10
  __int64 v44; // r8
  __int64 v45; // r6
  va *v46; // r3
  BOOL alwaysShowNodeProps; // r11
  __int64 v48; // r10
  __int64 v49; // r6
  va *v50; // r3
  __int64 v51; // r8
  __int64 v52; // r6
  __int64 v53; // r10
  va *v54; // r3
  BOOL showIncomingLinks; // r11
  __int64 v56; // r10
  __int64 v57; // r6
  __int64 v58; // r8
  va *v59; // r3
  __int64 v60; // r10
  __int64 v61; // r8
  int v62; // r29
  const char **v63; // r30
  BOOL v64; // r11
  __int64 v65; // r6
  va *v66; // r3
  unsigned int i; // r5
  __int64 v68; // r6
  va *v69; // r3
  unsigned int j; // r5
  __int64 v71; // r8
  __int64 v72; // r6
  __int64 v73; // r10
  int v74; // r29
  int v75; // r30
  __int64 v76; // r6
  va *v77; // r3
  unsigned int k; // r5
  va *v79; // r3
  unsigned int m; // r5
  __int64 v81; // r10
  __int64 v82; // r6
  __int64 v83; // r8
  va *v84; // r3
  unsigned int n; // r5
  __int64 v86; // r8
  __int64 v87; // r6
  __int64 v88; // r10
  int v89; // r29
  int v90; // r30
  idAtomicString *v91; // r11
  __int64 v92; // r6
  va *v93; // r3
  unsigned int ii; // r5
  va *v95; // r3
  unsigned int jj; // r5
  __int64 v97; // r6
  __int64 v98; // r10
  __int64 v99; // r8
  va *v100; // r3
  unsigned int kk; // r5
  __int64 v102; // r10
  __int64 v103; // r8
  __int64 v104; // r6
  idIndex<short,enum invalidUserChannelIndex_t> *list; // r26
  int size; // r11
  int num; // r30
  char v108; // r3
  int v109; // r11
  __int64 v110; // r10
  va *v111; // r3
  unsigned int mm; // r5
  __int64 v113; // r10
  __int64 v114; // r8
  __int64 v115; // r6
  int nn; // r21
  __int64 v117; // r10
  __int64 v118; // r6
  int v119; // r30
  va *v120; // r3
  unsigned int i1; // r5
  __int64 v122; // r10
  __int64 v123; // r6
  __int64 v124; // r8
  va *v125; // r3
  unsigned int i2; // r5
  __int64 v127; // r6
  __int64 v128; // r10
  __int64 v129; // r8
  va *v130; // r3
  unsigned int i3; // r5
  __int64 v132; // r8
  __int64 v133; // r6
  __int64 v134; // r10
  int v135; // r27
  int v136; // r29
  __int64 v137; // r6
  va *v138; // r3
  unsigned int i4; // r5
  va *v140; // r3
  unsigned int i5; // r5
  __int64 v142; // r6
  __int64 v143; // r10
  __int64 v144; // r8
  va *v145; // r3
  unsigned int i6; // r5
  va *v147; // r3
  unsigned int i7; // r5
  __int64 v149; // r10
  __int64 v150; // r6
  __int64 v151; // r8
  va *v152; // r3
  unsigned int i8; // r5
  __int64 v154; // r8
  __int64 v155; // r6
  __int64 v156; // r10
  int v157; // r29
  int v158; // r30
  __int64 v159; // r6
  va *v160; // r3
  unsigned int i9; // r5
  __int64 v162; // r6
  __int64 v163; // r10
  __int64 v164; // r8
  va *v165; // r3
  unsigned int i10; // r5
  va *v167; // r3
  unsigned int i11; // r5
  __int64 v169; // r10
  __int64 v170; // r8
  __int64 v171; // r6
  int v172; // r24
  int v173; // r25
  int v174; // r26
  idDeclAnimWebNode *v175; // r27
  int v176; // r11
  const idDeclAnimWebNode::idModelInfo *v177; // r30
  int v178; // r29
  va *v179; // r3
  unsigned int i12; // r5
  __int64 v181; // r8
  __int64 v182; // r6
  __int64 v183; // r10
  int v184; // r29
  int v185; // r30
  __int64 v186; // r10
  __int64 v187; // r6
  va *v188; // r3
  unsigned int i13; // r5
  va *v190; // r3
  unsigned int i14; // r5
  __int64 v192; // r10
  __int64 v193; // r8
  __int64 v194; // r6
  idIndex<short,enum invalidUserChannelIndex_t> *v195; // r15
  int v196; // r11
  int v197; // r30
  char v198; // r3
  int v199; // r11
  idIndex<short,enum invalidUserChannelIndex_t> *v200; // r16
  int v201; // r11
  int v202; // r30
  char v203; // r3
  int v204; // r11
  __int64 v205; // r10
  va *v206; // r3
  unsigned int i15; // r5
  __int64 v208; // r8
  __int64 v209; // r6
  __int64 v210; // r10
  int v211; // r18
  idIndex<short,enum invalidUserChannelIndex_t> *v212; // r26
  __int64 v213; // r6
  int value; // r27
  __int64 v215; // r10
  int v216; // r30
  va *v217; // r3
  unsigned int i16; // r5
  __int64 v219; // r6
  __int64 v220; // r10
  __int64 v221; // r8
  va *v222; // r3
  unsigned int i17; // r5
  __int64 v224; // r6
  __int64 v225; // r10
  __int64 v226; // r8
  va *v227; // r3
  unsigned int i18; // r5
  const char *v229; // r3
  __int64 v230; // r10
  __int64 v231; // r8
  va *v232; // r3
  unsigned int i19; // r5
  __int64 v234; // r10
  __int64 v235; // r6
  __int64 v236; // r8
  va *v237; // r3
  unsigned int i20; // r5
  __int64 v239; // r10
  __int64 v240; // r6
  __int64 v241; // r8
  va *v242; // r3
  unsigned int i21; // r5
  __int64 v244; // r6
  __int64 v245; // r10
  __int64 v246; // r8
  va *v247; // r3
  unsigned int i22; // r5
  __int64 v249; // r6
  __int64 v250; // r10
  __int64 v251; // r8
  va *v252; // r3
  __int64 v253; // r8
  __int64 v254; // r6
  idDeclAnimWeb *v255; // r30
  int v256; // r29
  __int64 v257; // r10
  idDeclAnimWeb *v258; // r11
  idIndex<short,enum invalidUserChannelIndex_t> *v259; // r30
  idDeclAnimWebNode *v260; // r3
  va *v261; // r3
  unsigned int i23; // r5
  va *v263; // r3
  unsigned int i24; // r5
  __int64 v265; // r10
  __int64 v266; // r6
  __int64 v267; // r8
  va *v268; // r3
  unsigned int i25; // r5
  int v270; // [sp+8h] [-2308h]
  int v271; // [sp+8h] [-2308h]
  int v272; // [sp+8h] [-2308h]
  int v273; // [sp+8h] [-2308h]
  int v274; // [sp+8h] [-2308h]
  int v275; // [sp+8h] [-2308h]
  int v276; // [sp+8h] [-2308h]
  int v277; // [sp+8h] [-2308h]
  int v278; // [sp+8h] [-2308h]
  int v279; // [sp+8h] [-2308h]
  int v280; // [sp+8h] [-2308h]
  int v281; // [sp+8h] [-2308h]
  int v282; // [sp+8h] [-2308h]
  int v283; // [sp+8h] [-2308h]
  int v284; // [sp+8h] [-2308h]
  int v285; // [sp+8h] [-2308h]
  int v286; // [sp+8h] [-2308h]
  int v287; // [sp+8h] [-2308h]
  int v288; // [sp+8h] [-2308h]
  int v289; // [sp+8h] [-2308h]
  int v290; // [sp+8h] [-2308h]
  int v291; // [sp+8h] [-2308h]
  int v292; // [sp+8h] [-2308h]
  int v293; // [sp+8h] [-2308h]
  int v294; // [sp+8h] [-2308h]
  int v295; // [sp+8h] [-2308h]
  idList<idAnimWebBlendEquation::existingNode_t,5> *v296; // [sp+8h] [-2308h]
  int v297; // [sp+8h] [-2308h]
  int v298; // [sp+8h] [-2308h]
  int v299; // [sp+8h] [-2308h]
  int v300; // [sp+8h] [-2308h]
  int v301; // [sp+8h] [-2308h]
  int v302; // [sp+8h] [-2308h]
  int v303; // [sp+8h] [-2308h]
  int v304; // [sp+8h] [-2308h]
  int v305; // [sp+8h] [-2308h]
  int v306; // [sp+8h] [-2308h]
  int v307; // [sp+8h] [-2308h]
  int v308; // [sp+8h] [-2308h]
  int v309; // [sp+Ch] [-2304h]
  int v310; // [sp+Ch] [-2304h]
  int v311; // [sp+Ch] [-2304h]
  int v312; // [sp+Ch] [-2304h]
  int v313; // [sp+Ch] [-2304h]
  int v314; // [sp+Ch] [-2304h]
  int v315; // [sp+Ch] [-2304h]
  int v316; // [sp+Ch] [-2304h]
  int v317; // [sp+Ch] [-2304h]
  int v318; // [sp+Ch] [-2304h]
  int v319; // [sp+Ch] [-2304h]
  int v320; // [sp+Ch] [-2304h]
  int v321; // [sp+Ch] [-2304h]
  int v322; // [sp+Ch] [-2304h]
  int v323; // [sp+Ch] [-2304h]
  int v324; // [sp+Ch] [-2304h]
  int v325; // [sp+Ch] [-2304h]
  int v326; // [sp+Ch] [-2304h]
  int v327; // [sp+Ch] [-2304h]
  int v328; // [sp+Ch] [-2304h]
  int v329; // [sp+Ch] [-2304h]
  int v330; // [sp+Ch] [-2304h]
  int v331; // [sp+Ch] [-2304h]
  int v332; // [sp+Ch] [-2304h]
  int v333; // [sp+Ch] [-2304h]
  int v334; // [sp+Ch] [-2304h]
  idMD6Node **v335; // [sp+Ch] [-2304h]
  int v336; // [sp+Ch] [-2304h]
  int v337; // [sp+Ch] [-2304h]
  int v338; // [sp+Ch] [-2304h]
  int v339; // [sp+Ch] [-2304h]
  int v340; // [sp+Ch] [-2304h]
  int v341; // [sp+Ch] [-2304h]
  int v342; // [sp+Ch] [-2304h]
  int v343; // [sp+Ch] [-2304h]
  int v344; // [sp+Ch] [-2304h]
  int v345; // [sp+Ch] [-2304h]
  int v346; // [sp+Ch] [-2304h]
  int v347; // [sp+Ch] [-2304h]
  int v348; // [sp+10h] [-2300h]
  int v349; // [sp+10h] [-2300h]
  int v350; // [sp+10h] [-2300h]
  int v351; // [sp+10h] [-2300h]
  int v352; // [sp+10h] [-2300h]
  int v353; // [sp+10h] [-2300h]
  int v354; // [sp+10h] [-2300h]
  int v355; // [sp+10h] [-2300h]
  int v356; // [sp+10h] [-2300h]
  int v357; // [sp+10h] [-2300h]
  int v358; // [sp+10h] [-2300h]
  int v359; // [sp+10h] [-2300h]
  int v360; // [sp+10h] [-2300h]
  int v361; // [sp+10h] [-2300h]
  int v362; // [sp+10h] [-2300h]
  int v363; // [sp+10h] [-2300h]
  int v364; // [sp+10h] [-2300h]
  int v365; // [sp+10h] [-2300h]
  int v366; // [sp+10h] [-2300h]
  int v367; // [sp+10h] [-2300h]
  int v368; // [sp+10h] [-2300h]
  int v369; // [sp+10h] [-2300h]
  int v370; // [sp+10h] [-2300h]
  int v371; // [sp+10h] [-2300h]
  int v372; // [sp+10h] [-2300h]
  int v373; // [sp+10h] [-2300h]
  idList<idAnimWebScalarPair,33> *v374; // [sp+10h] [-2300h]
  int v375; // [sp+10h] [-2300h]
  int v376; // [sp+10h] [-2300h]
  int v377; // [sp+10h] [-2300h]
  int v378; // [sp+10h] [-2300h]
  int v379; // [sp+10h] [-2300h]
  int v380; // [sp+10h] [-2300h]
  int v381; // [sp+10h] [-2300h]
  int v382; // [sp+10h] [-2300h]
  int v383; // [sp+10h] [-2300h]
  int v384; // [sp+10h] [-2300h]
  int v385; // [sp+10h] [-2300h]
  int v386; // [sp+10h] [-2300h]
  int v387; // [sp+14h] [-22FCh]
  int v388; // [sp+14h] [-22FCh]
  int v389; // [sp+14h] [-22FCh]
  int v390; // [sp+14h] [-22FCh]
  int v391; // [sp+14h] [-22FCh]
  int v392; // [sp+14h] [-22FCh]
  int v393; // [sp+14h] [-22FCh]
  int v394; // [sp+14h] [-22FCh]
  int v395; // [sp+14h] [-22FCh]
  int v396; // [sp+14h] [-22FCh]
  int v397; // [sp+14h] [-22FCh]
  int v398; // [sp+14h] [-22FCh]
  int v399; // [sp+14h] [-22FCh]
  int v400; // [sp+14h] [-22FCh]
  int v401; // [sp+14h] [-22FCh]
  int v402; // [sp+14h] [-22FCh]
  int v403; // [sp+14h] [-22FCh]
  int v404; // [sp+14h] [-22FCh]
  int v405; // [sp+14h] [-22FCh]
  int v406; // [sp+14h] [-22FCh]
  int v407; // [sp+14h] [-22FCh]
  int v408; // [sp+14h] [-22FCh]
  int v409; // [sp+14h] [-22FCh]
  int v410; // [sp+14h] [-22FCh]
  int v411; // [sp+14h] [-22FCh]
  int v412; // [sp+14h] [-22FCh]
  int v413; // [sp+14h] [-22FCh]
  int v414; // [sp+14h] [-22FCh]
  int v415; // [sp+14h] [-22FCh]
  int v416; // [sp+14h] [-22FCh]
  int v417; // [sp+14h] [-22FCh]
  int v418; // [sp+14h] [-22FCh]
  int v419; // [sp+14h] [-22FCh]
  int v420; // [sp+14h] [-22FCh]
  int v421; // [sp+14h] [-22FCh]
  int v422; // [sp+14h] [-22FCh]
  int v423; // [sp+14h] [-22FCh]
  int v424; // [sp+14h] [-22FCh]
  int v425; // [sp+14h] [-22FCh]
  int v426; // [sp+18h] [-22F8h]
  int v427; // [sp+18h] [-22F8h]
  int v428; // [sp+18h] [-22F8h]
  int v429; // [sp+18h] [-22F8h]
  int v430; // [sp+18h] [-22F8h]
  int v431; // [sp+18h] [-22F8h]
  int v432; // [sp+18h] [-22F8h]
  int v433; // [sp+18h] [-22F8h]
  int v434; // [sp+18h] [-22F8h]
  int v435; // [sp+18h] [-22F8h]
  int v436; // [sp+18h] [-22F8h]
  int v437; // [sp+18h] [-22F8h]
  int v438; // [sp+18h] [-22F8h]
  int v439; // [sp+18h] [-22F8h]
  int v440; // [sp+18h] [-22F8h]
  int v441; // [sp+18h] [-22F8h]
  int v442; // [sp+18h] [-22F8h]
  int v443; // [sp+18h] [-22F8h]
  int v444; // [sp+18h] [-22F8h]
  int v445; // [sp+18h] [-22F8h]
  int v446; // [sp+18h] [-22F8h]
  int v447; // [sp+18h] [-22F8h]
  int v448; // [sp+18h] [-22F8h]
  int v449; // [sp+18h] [-22F8h]
  int v450; // [sp+18h] [-22F8h]
  int v451; // [sp+18h] [-22F8h]
  int v452; // [sp+18h] [-22F8h]
  int v453; // [sp+18h] [-22F8h]
  int v454; // [sp+18h] [-22F8h]
  int v455; // [sp+18h] [-22F8h]
  int v456; // [sp+18h] [-22F8h]
  int v457; // [sp+18h] [-22F8h]
  int v458; // [sp+18h] [-22F8h]
  int v459; // [sp+18h] [-22F8h]
  int v460; // [sp+18h] [-22F8h]
  int v461; // [sp+18h] [-22F8h]
  int v462; // [sp+18h] [-22F8h]
  int v463; // [sp+18h] [-22F8h]
  int v464; // [sp+18h] [-22F8h]
  int v465; // [sp+1Ch] [-22F4h]
  int v466; // [sp+1Ch] [-22F4h]
  int v467; // [sp+1Ch] [-22F4h]
  int v468; // [sp+1Ch] [-22F4h]
  int v469; // [sp+1Ch] [-22F4h]
  int v470; // [sp+1Ch] [-22F4h]
  int v471; // [sp+1Ch] [-22F4h]
  int v472; // [sp+1Ch] [-22F4h]
  int v473; // [sp+1Ch] [-22F4h]
  int v474; // [sp+1Ch] [-22F4h]
  int v475; // [sp+1Ch] [-22F4h]
  int v476; // [sp+1Ch] [-22F4h]
  int v477; // [sp+1Ch] [-22F4h]
  int v478; // [sp+1Ch] [-22F4h]
  int v479; // [sp+1Ch] [-22F4h]
  int v480; // [sp+1Ch] [-22F4h]
  int v481; // [sp+1Ch] [-22F4h]
  int v482; // [sp+1Ch] [-22F4h]
  int v483; // [sp+1Ch] [-22F4h]
  int v484; // [sp+1Ch] [-22F4h]
  int v485; // [sp+1Ch] [-22F4h]
  int v486; // [sp+1Ch] [-22F4h]
  int v487; // [sp+1Ch] [-22F4h]
  int v488; // [sp+1Ch] [-22F4h]
  int v489; // [sp+1Ch] [-22F4h]
  int v490; // [sp+1Ch] [-22F4h]
  int v491; // [sp+1Ch] [-22F4h]
  int v492; // [sp+1Ch] [-22F4h]
  int v493; // [sp+1Ch] [-22F4h]
  int v494; // [sp+1Ch] [-22F4h]
  int v495; // [sp+1Ch] [-22F4h]
  int v496; // [sp+1Ch] [-22F4h]
  int v497; // [sp+1Ch] [-22F4h]
  int v498; // [sp+1Ch] [-22F4h]
  int v499; // [sp+1Ch] [-22F4h]
  int v500; // [sp+1Ch] [-22F4h]
  int v501; // [sp+1Ch] [-22F4h]
  int v502; // [sp+1Ch] [-22F4h]
  int v503; // [sp+1Ch] [-22F4h]
  int v504; // [sp+20h] [-22F0h]
  int v505; // [sp+24h] [-22ECh]
  int v506; // [sp+28h] [-22E8h]
  int v507; // [sp+2Ch] [-22E4h]
  int v508; // [sp+30h] [-22E0h]
  int v509; // [sp+34h] [-22DCh]
  int v510; // [sp+38h] [-22D8h]
  int v511; // [sp+3Ch] [-22D4h]
  int v512; // [sp+40h] [-22D0h]
  int v513; // [sp+44h] [-22CCh]
  int v514; // [sp+48h] [-22C8h]
  int v515; // [sp+4Ch] [-22C4h]
  int v516; // [sp+50h] [-22C0h]
  int v517; // [sp+58h] [-22B8h]
  int v518; // [sp+60h] [-22B0h]
  idList<idAnimWebScalar,5> v519; // [sp+80h] [-2290h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v520; // [sp+90h] [-2280h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v521; // [sp+A0h] [-2270h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v522; // [sp+B0h] [-2260h] BYREF
  idList<idAnimWebBlendEquation::existingNode_t,5> v523; // [sp+C0h] [-2250h] BYREF
  idList<idAnimWebScalarPair,5> v524; // [sp+D0h] [-2240h] BYREF
  idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName> v525[2]; // [sp+E0h] [-2230h] BYREF
  const char *v526; // [sp+E8h] [-2228h]
  idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName> v527[2]; // [sp+F0h] [-2220h] BYREF
  idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName> v528[2]; // [sp+F8h] [-2218h] BYREF
  const char *v529; // [sp+100h] [-2210h]
  idMD6Node *v530; // [sp+104h] [-220Ch] BYREF
  idMD6Allocator_New v531; // [sp+110h] [-2200h] BYREF
  idStr v532; // [sp+130h] [-21E0h] BYREF
  idAnimWebBlendEquation v533; // [sp+150h] [-21C0h] BYREF
  va v534; // [sp+270h] [-20A0h] BYREF
  va v535; // [sp+1270h] [-10A0h] BYREF

  v7 = HIDWORD(indent);
  v8 = va::va(this: &v534, fmt: "{\n", a3: indent, a4, a5, a6: v270, a7: v309, a8: v348, a9: v387, a10: v426, a11: v465);
  idFile_String::operator+=(this: str, str: v8->buffer);
  LODWORD(v9) = &unk_821B0000;
  HIDWORD(v10) = v7;
  v12 = va::va(
          this: &v534,
          fmt: "%s\tprops {\n",
          a3: v10,
          a4: v11,
          a5: v9,
          a6: v271,
          a7: v310,
          a8: v349,
          a9: v388,
          a10: v427,
          a11: v466);
  idFile_String::operator+=(this: str, str: v12->buffer);
  v13 = idVec3::ToString(this: (idAngles *)&this->settings, precision: 2);
  HIDWORD(v14) = &unk_821B0000;
  v16 = va::va(
          this: &v534,
          fmt: "%s\t\teditPos ( %s )\n",
          a3: __SPAIR64__(v7, (unsigned int)v13),
          a4: v15,
          a5: v14,
          a6: v272,
          a7: v311,
          a8: v350,
          a9: v389,
          a10: v428,
          a11: v467);
  idFile_String::operator+=(this: str, str: v16->buffer);
  LODWORD(v17) = &unk_821B0000;
  HIDWORD(v18) = v7;
  LODWORD(v18) = this->settings.gridSize;
  v20 = va::va(
          this: &v534,
          fmt: "%s\t\tgridSize %i\n",
          a3: v18,
          a4: v17,
          a5: v19,
          a6: v273,
          a7: v312,
          a8: v351,
          a9: v390,
          a10: v429,
          a11: v468);
  idFile_String::operator+=(this: str, str: v20->buffer);
  HIDWORD(v21) = &unk_821B0000;
  HIDWORD(v22) = v7;
  LODWORD(v22) = this->settings.snapToGrid;
  v24 = va::va(
          this: &v534,
          fmt: "%s\t\tsnapToGrid %d\n",
          a3: v22,
          a4: v21,
          a5: v23,
          a6: v274,
          a7: v313,
          a8: v352,
          a9: v391,
          a10: v430,
          a11: v469);
  idFile_String::operator+=(this: str, str: v24->buffer);
  HIDWORD(v25) = this->settings.showGrid;
  LODWORD(v25) = &unk_821B0000;
  LODWORD(v26) = HIDWORD(v25) - 1;
  HIDWORD(v27) = v7;
  LODWORD(v27) = HIDWORD(v25) != 0;
  v28 = va::va(
          this: &v534,
          fmt: "%s\t\tshowGrid %d\n",
          a3: v27,
          a4: v26,
          a5: v25,
          a6: v275,
          a7: v314,
          a8: v353,
          a9: v392,
          a10: v431,
          a11: v470);
  idFile_String::operator+=(this: str, str: v28->buffer);
  HIDWORD(v29) = &unk_821B0000;
  HIDWORD(v30) = v7;
  LODWORD(v30) = this->settings.alwaysShowIntraSubwebLinks;
  v32 = va::va(
          this: &v534,
          fmt: "%s\t\talwaysShowIntraSubwebLinks %d\n",
          a3: v30,
          a4: v29,
          a5: v31,
          a6: v276,
          a7: v315,
          a8: v354,
          a9: v393,
          a10: v432,
          a11: v471);
  idFile_String::operator+=(this: str, str: v32->buffer);
  LODWORD(v33) = &unk_821B0000;
  HIDWORD(v34) = v7;
  LODWORD(v34) = this->settings.defaultBlendOutWindow;
  v36 = va::va(
          this: &v534,
          fmt: "%s\t\tdefaultBlendOutWindow %d\n",
          a3: v34,
          a4: v35,
          a5: v33,
          a6: v277,
          a7: v316,
          a8: v355,
          a9: v394,
          a10: v433,
          a11: v472);
  idFile_String::operator+=(this: str, str: v36->buffer);
  HIDWORD(v37) = &unk_821B0000;
  HIDWORD(v38) = v7;
  LODWORD(v38) = this->settings.defaultBlendDuration;
  v40 = va::va(
          this: &v534,
          fmt: "%s\t\tdefaultBlendDuration %d\n",
          a3: v38,
          a4: v39,
          a5: v37,
          a6: v278,
          a7: v317,
          a8: v356,
          a9: v395,
          a10: v434,
          a11: v473);
  idFile_String::operator+=(this: str, str: v40->buffer);
  subWebBlend = this->settings.subWebBlend;
  if ( subWebBlend != SUBWEBBLEND_USE_SOURCE_NODE )
  {
    LODWORD(v43) = &consoleFont[21088];
    HIDWORD(v43) = 4 * subWebBlend;
    LODWORD(v44) = idDeclAnimWeb::subWebBlendNames;
    HIDWORD(v44) = &unk_821B0000;
    HIDWORD(v45) = v7;
    LODWORD(v45) = idDeclAnimWeb::subWebBlendNames[subWebBlend];
    v46 = va::va(
            this: &v534,
            fmt: "%s\t\tsubWebBlend \"%s\"\n",
            a3: v45,
            a4: v44,
            a5: v43,
            a6: v279,
            a7: v318,
            a8: v357,
            a9: v396,
            a10: v435,
            a11: v474);
    idFile_String::operator+=(this: str, str: v46->buffer);
  }
  alwaysShowNodeProps = this->settings.alwaysShowNodeProps;
  LODWORD(v48) = &unk_821B0000;
  HIDWORD(v49) = v7;
  HIDWORD(v48) = alwaysShowNodeProps - 1;
  LODWORD(v49) = alwaysShowNodeProps;
  v50 = va::va(
          this: &v534,
          fmt: "%s\t\talwaysShowNodeProps %d\n",
          a3: v49,
          a4: v41,
          a5: v48,
          a6: v279,
          a7: v318,
          a8: v357,
          a9: v396,
          a10: v435,
          a11: v474);
  idFile_String::operator+=(this: str, str: v50->buffer);
  HIDWORD(v51) = this->settings.showAbbreviatedNodeProps;
  LODWORD(v51) = &unk_821B0000;
  HIDWORD(v52) = v7;
  LODWORD(v52) = HIDWORD(v51) != 0;
  v54 = va::va(
          this: &v534,
          fmt: "%s\t\tshowAbbreviatedNodeProps %d\n",
          a3: v52,
          a4: v51,
          a5: v53,
          a6: v280,
          a7: v319,
          a8: v358,
          a9: v397,
          a10: v436,
          a11: v475);
  idFile_String::operator+=(this: str, str: v54->buffer);
  showIncomingLinks = this->settings.showIncomingLinks;
  LODWORD(v56) = showIncomingLinks - 1;
  HIDWORD(v57) = v7;
  LODWORD(v57) = showIncomingLinks;
  v59 = va::va(
          this: &v534,
          fmt: "%s\t\tshowIncomingLinks %d\n",
          a3: v57,
          a4: v58,
          a5: v56,
          a6: v281,
          a7: v320,
          a8: v359,
          a9: v398,
          a10: v437,
          a11: v476);
  idFile_String::operator+=(this: str, str: v59->buffer);
  v62 = 0;
  v63 = idDeclAnimWeb::nodePropNames;
  do
  {
    v64 = this->settings.nodeProps[v62];
    HIDWORD(v65) = v7;
    LODWORD(v65) = *v63;
    LODWORD(v60) = v64 - 1;
    HIDWORD(v61) = v64;
    v66 = va::va(
            this: &v534,
            fmt: "%s\t\t%s %d\n",
            a3: v65,
            a4: v61,
            a5: v60,
            a6: v282,
            a7: v321,
            a8: v360,
            a9: v399,
            a10: v438,
            a11: v477);
    for ( i = 0; v66->buffer[i] != 0; ++i )
      ;
    str->Write(this: str, a2: v66, a3: i);
    ++v63;
    HIDWORD(v60) = idDeclAnimWeb::subWebBlendNames;
    ++v62;
  }
  while ( (int)v63 < (int)idDeclAnimWeb::subWebBlendNames );
  HIDWORD(v68) = v7;
  v69 = va::va(
          this: &v534,
          fmt: "%s\t\tmodels {\n",
          a3: v68,
          a4: v61,
          a5: v60,
          a6: v282,
          a7: v321,
          a8: v360,
          a9: v399,
          a10: v438,
          a11: v477);
  for ( j = 0; v69->buffer[j] != 0; ++j )
    ;
  str->Write(this: str, a2: v69, a3: j);
  HIDWORD(v73) = this->models.num;
  v74 = 0;
  if ( SHIDWORD(v73) > 0 )
  {
    v75 = 0;
    do
    {
      LODWORD(v73) = this->models.list[v75];
      if ( (_DWORD)v73 != 0 )
      {
        HIDWORD(v76) = v7;
        LODWORD(v76) = *(_DWORD *)(v73 + 8);
        v77 = va::va(
                this: &v534,
                fmt: "%s\t\t\t\"%s\"\n",
                a3: v76,
                a4: v71,
                a5: v73,
                a6: v283,
                a7: v322,
                a8: v361,
                a9: v400,
                a10: v439,
                a11: v478);
        for ( k = 0; v77->buffer[k] != 0; ++k )
          ;
        str->Write(this: str, a2: v77, a3: k);
      }
      ++v74;
      ++v75;
    }
    while ( v74 < this->models.num );
  }
  HIDWORD(v72) = v7;
  v529 = "%s\t\t}\n";
  v79 = va::va(
          this: &v534,
          fmt: "%s\t\t}\n",
          a3: v72,
          a4: v71,
          a5: v73,
          a6: v283,
          a7: v322,
          a8: v361,
          a9: v400,
          a10: v439,
          a11: v478);
  for ( m = 0; v79->buffer[m] != 0; ++m )
    ;
  str->Write(this: str, a2: v79, a3: m);
  HIDWORD(v81) = &unk_821B0000;
  HIDWORD(v82) = v7;
  v84 = va::va(
          this: &v534,
          fmt: "%s\t\teditorModels {\n",
          a3: v82,
          a4: v83,
          a5: v81,
          a6: v284,
          a7: v323,
          a8: v362,
          a9: v401,
          a10: v440,
          a11: v479);
  for ( n = 0; v84->buffer[n] != 0; ++n )
    ;
  str->Write(this: str, a2: v84, a3: n);
  HIDWORD(v88) = this->editorModels.num;
  v89 = 0;
  if ( SHIDWORD(v88) > 0 )
  {
    v90 = 0;
    do
    {
      HIDWORD(v88) = &byte_8200D768;
      v91 = &this->editorModels.list[v90];
      if ( v91->str == &byte_8200D768 || (LOBYTE(v88) = 0, *v91->str == 0) )
        LOBYTE(v88) = 1;
      LODWORD(v88) = (unsigned __int8)v88;
      if ( (_BYTE)v88 == 0 )
      {
        LODWORD(v92) = (idAtomicString)v91->str;
        HIDWORD(v92) = v7;
        v93 = va::va(
                this: &v534,
                fmt: "%s\t\t\t\"%s\"\n",
                a3: v92,
                a4: v86,
                a5: v88,
                a6: v285,
                a7: v324,
                a8: v363,
                a9: v402,
                a10: v441,
                a11: v480);
        for ( ii = 0; v93->buffer[ii] != 0; ++ii )
          ;
        str->Write(this: str, a2: v93, a3: ii);
      }
      ++v89;
      ++v90;
    }
    while ( v89 < this->editorModels.num );
  }
  HIDWORD(v87) = v7;
  v95 = va::va(
          this: &v534,
          fmt: "%s\t\t}\n",
          a3: v87,
          a4: v86,
          a5: v88,
          a6: v285,
          a7: v324,
          a8: v363,
          a9: v402,
          a10: v441,
          a11: v480);
  for ( jj = 0; v95->buffer[jj] != 0; ++jj )
    ;
  str->Write(this: str, a2: v95, a3: jj);
  HIDWORD(v97) = v7;
  v100 = va::va(
           this: &v534,
           fmt: "%s\t}\n",
           a3: v97,
           a4: v99,
           a5: v98,
           a6: v286,
           a7: v325,
           a8: v364,
           a9: v403,
           a10: v442,
           a11: v481);
  for ( kk = 0; v100->buffer[kk] != 0; ++kk )
    ;
  str->Write(this: str, a2: v100, a3: kk);
  list = nullptr;
  *(_WORD *)&v520.memTag = 1280;
  size = 0;
  memset(&v520, 0, 14);
  num = this->layers.num;
  if ( num > 0 )
  {
    v108 = idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
             this: &v520,
             newsize: this->layers.num);
    list = v520.list;
    if ( v108 == 0 )
    {
      num = v520.num;
      goto LABEL_41;
    }
    size = v520.size;
  }
  if ( num >= size )
  {
    num = size;
    v520.num = size;
  }
  else
  {
    v520.num = num;
  }
LABEL_41:
  LODWORD(v102) = this->layers.num;
  v109 = 0;
  if ( (int)v102 > 0 )
  {
    LODWORD(v102) = list - 1;
    do
    {
      HIDWORD(v102) = (__int16)v109;
      LODWORD(v102) = v102 + 2;
      *(_WORD *)v102 = v109++;
      LODWORD(v103) = this->layers.num;
    }
    while ( v109 < (int)v103 );
  }
  v527[1].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName>_vtbl *)this;
  v527[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName>_vtbl *)&idSort_LayerName::`vftable';
  if ( list != nullptr )
    idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName>::Sort(
      this: v527,
      base: (idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *)list,
      num,
      a4: v104,
      a5: SHIDWORD(v103),
      a6: v103,
      a7: v102);
  LODWORD(v110) = &unk_821B0000;
  HIDWORD(v110) = &idSort<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>>::`vftable';
  v527[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName>_vtbl *)&idSort<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>>::`vftable';
  HIDWORD(v104) = v7;
  v111 = va::va(
           this: &v534,
           fmt: "%s\tlayers {\n",
           a3: v104,
           a4: v103,
           a5: v110,
           a6: v287,
           a7: v326,
           a8: v365,
           a9: v404,
           a10: v443,
           a11: v482);
  for ( mm = 0; v111->buffer[mm] != 0; ++mm )
    ;
  str->Write(this: str, a2: v111, a3: mm);
  v526 = "%s\t\t\t}\n";
  if ( num > 0 )
  {
    LODWORD(v114) = &unk_821B0000;
    for ( nn = num; nn != 0; --nn )
    {
      HIDWORD(v117) = this->layers.list;
      HIDWORD(v118) = v7;
      LODWORD(v117) = 3 * list->value;
      v119 = 24 * list->value + HIDWORD(v117);
      LODWORD(v118) = *(_DWORD *)v119;
      v120 = va::va(
               this: &v534,
               fmt: "%s\t\tlayer \"%s\" {\n",
               a3: v118,
               a4: v114,
               a5: v117,
               a6: v288,
               a7: v327,
               a8: v366,
               a9: v405,
               a10: v444,
               a11: v483);
      for ( i1 = 0; v120->buffer[i1] != 0; ++i1 )
        ;
      str->Write(this: str, a2: v120, a3: i1);
      HIDWORD(v122) = *(unsigned __int8 *)(v119 + 20);
      HIDWORD(v123) = v7;
      LODWORD(v124) = HIDWORD(v122) - 1;
      LODWORD(v123) = HIDWORD(v122) != 0;
      v125 = va::va(
               this: &v534,
               fmt: "%s\t\t\tvisible %d\n",
               a3: v123,
               a4: v124,
               a5: v122,
               a6: v289,
               a7: v328,
               a8: v367,
               a9: v406,
               a10: v445,
               a11: v484);
      for ( i2 = 0; v125->buffer[i2] != 0; ++i2 )
        ;
      str->Write(this: str, a2: v125, a3: i2);
      HIDWORD(v127) = v7;
      v130 = va::va(
               this: &v534,
               fmt: "%s\t\t\tsubwebs {\n",
               a3: v127,
               a4: v129,
               a5: v128,
               a6: v290,
               a7: v329,
               a8: v368,
               a9: v407,
               a10: v446,
               a11: v485);
      for ( i3 = 0; v130->buffer[i3] != 0; ++i3 )
        ;
      str->Write(this: str, a2: v130, a3: i3);
      HIDWORD(v134) = *(_DWORD *)(v119 + 8);
      v135 = 0;
      if ( SHIDWORD(v134) > 0 )
      {
        v136 = 0;
        do
        {
          HIDWORD(v137) = v7;
          LODWORD(v137) = *(_DWORD *)(v136 + *(_DWORD *)(v119 + 4));
          v138 = va::va(
                   this: &v534,
                   fmt: "%s\t\t\t\t\"%s\"\n",
                   a3: v137,
                   a4: v132,
                   a5: v134,
                   a6: v291,
                   a7: v330,
                   a8: v369,
                   a9: v408,
                   a10: v447,
                   a11: v486);
          for ( i4 = 0; v138->buffer[i4] != 0; ++i4 )
            ;
          str->Write(this: str, a2: v138, a3: i4);
          HIDWORD(v134) = *(_DWORD *)(v119 + 8);
          ++v135;
          v136 += 4;
        }
        while ( v135 < SHIDWORD(v134) );
      }
      HIDWORD(v133) = v7;
      v140 = va::va(
               this: &v534,
               fmt: "%s\t\t\t}\n",
               a3: v133,
               a4: v132,
               a5: v134,
               a6: v291,
               a7: v330,
               a8: v369,
               a9: v408,
               a10: v447,
               a11: v486);
      for ( i5 = 0; v140->buffer[i5] != 0; ++i5 )
        ;
      str->Write(this: str, a2: v140, a3: i5);
      HIDWORD(v142) = v7;
      v145 = va::va(
               this: &v534,
               fmt: "%s\t\t}\n",
               a3: v142,
               a4: v144,
               a5: v143,
               a6: v292,
               a7: v331,
               a8: v370,
               a9: v409,
               a10: v448,
               a11: v487);
      for ( i6 = 0; v145->buffer[i6] != 0; ++i6 )
        ;
      str->Write(this: str, a2: v145, a3: i6);
      ++list;
    }
  }
  HIDWORD(v115) = v7;
  v147 = va::va(
           this: &v534,
           fmt: "%s\t}\n",
           a3: v115,
           a4: v114,
           a5: v113,
           a6: v288,
           a7: v327,
           a8: v366,
           a9: v405,
           a10: v444,
           a11: v483);
  for ( i7 = 0; v147->buffer[i7] != 0; ++i7 )
    ;
  str->Write(this: str, a2: v147, a3: i7);
  HIDWORD(v149) = &unk_821B0000;
  HIDWORD(v150) = v7;
  v152 = va::va(
           this: &v534,
           fmt: "%s\tstates {\n",
           a3: v150,
           a4: v151,
           a5: v149,
           a6: v293,
           a7: v332,
           a8: v371,
           a9: v410,
           a10: v449,
           a11: v488);
  for ( i8 = 0; v152->buffer[i8] != 0; ++i8 )
    ;
  str->Write(this: str, a2: v152, a3: i8);
  HIDWORD(v156) = this->states.num;
  v157 = 0;
  if ( SHIDWORD(v156) > 0 )
  {
    v158 = 0;
    do
    {
      HIDWORD(v159) = v7;
      LODWORD(v159) = this->states.list[v158].name.str;
      v160 = va::va(
               this: &v534,
               fmt: "%s\t\tstate \"%s\" {\n",
               a3: v159,
               a4: v154,
               a5: v156,
               a6: v294,
               a7: v333,
               a8: v372,
               a9: v411,
               a10: v450,
               a11: v489);
      for ( i9 = 0; v160->buffer[i9] != 0; ++i9 )
        ;
      str->Write(this: str, a2: v160, a3: i9);
      HIDWORD(v162) = v7;
      v165 = va::va(
               this: &v534,
               fmt: "%s\t\t}\n",
               a3: v162,
               a4: v164,
               a5: v163,
               a6: v295,
               a7: v334,
               a8: v373,
               a9: v412,
               a10: v451,
               a11: v490);
      for ( i10 = 0; v165->buffer[i10] != 0; ++i10 )
        ;
      str->Write(this: str, a2: v165, a3: i10);
      HIDWORD(v156) = this->states.num;
      ++v157;
      ++v158;
    }
    while ( v157 < SHIDWORD(v156) );
  }
  HIDWORD(v155) = v7;
  v167 = va::va(
           this: &v534,
           fmt: "%s\t}\n",
           a3: v155,
           a4: v154,
           a5: v156,
           a6: v294,
           a7: v333,
           a8: v372,
           a9: v411,
           a10: v450,
           a11: v489);
  for ( i11 = 0; v167->buffer[i11] != 0; ++i11 )
    ;
  str->Write(this: str, a2: v167, a3: i11);
  *(_WORD *)&v519.memTag = 1280;
  memset(&v519, 0, 14);
  *(_WORD *)&v524.memTag = 1280;
  memset(&v524, 0, 14);
  v530 = nullptr;
  *(_WORD *)&v523.memTag = 1280;
  memset(&v523, 0, 14);
  HIDWORD(v169) = &unk_821B0000;
  LODWORD(v170) = 19;
  HIDWORD(v170) = &idMD6Allocator_New::`vftable';
  v531.nodes.listStatic = 0;
  memset(&v531.nodes, 0, 14);
  v531.nodes.memTag = 19;
  v531.__vftable = (idMD6Allocator_New_vtbl *)&idMD6Allocator_New::`vftable';
  LODWORD(v171) = this->nodes.num;
  v172 = 0;
  if ( (int)v171 > 0 )
  {
    v173 = 0;
    do
    {
      v174 = 0;
      v175 = this->nodes.list[v173];
      v176 = v175->modelInfo.num;
      if ( v176 > 0 )
      {
        do
        {
          LODWORD(v169) = (__int16)v174;
          if ( (v174 & 0x8000u) == 0 && (__int16)v174 < v176 )
          {
            HIDWORD(v169) = v175->modelInfo.list;
            v177 = (const idDeclAnimWebNode::idModelInfo *)(36 * (__int16)v174 + HIDWORD(v169));
            if ( v177 != nullptr )
            {
              LODWORD(v169) = this->models.list;
              HIDWORD(v169) = v177->modelIndex.value;
              LODWORD(v170) = 4 * HIDWORD(v169);
              v178 = *(_DWORD *)(4 * HIDWORD(v169) + v169);
              if ( v178 != 0 )
              {
                idAnimWebBlendEquation::idAnimWebBlendEquation(this: &v533);
                idAnimWebBlendEquation::Parse(
                  this: &v533,
                  modelInfo: v177,
                  model: *(const idMD6Model **)(v178 + 60),
                  allocator: &v531,
                  time: 0,
                  ticksPerSec_: 960,
                  equation: v177->blendEq.str,
                  scalars: &v519,
                  existingNodes: v296,
                  root: v335,
                  scalarPairs: v374,
                  a12: v413,
                  a13: v452,
                  a14: v491,
                  a15: v504,
                  a16: v505,
                  a17: v506,
                  a18: v507,
                  a19: v508,
                  a20: v509,
                  a21: v510,
                  a22: v511,
                  a23: v512,
                  a24: v513,
                  a25: v514,
                  a26: v515,
                  a27: v516,
                  a28: &v523,
                  a29: v517,
                  a30: &v530,
                  a31: v518,
                  a32: &v524);
                if ( v533.allocatedNodes.listStatic == 0 || v533.allocatedNodes.listStatic == 2 )
                {
                  if ( v533.allocatedNodes.list != nullptr )
                    idMem::Free(this: &mem, ptr: v533.allocatedNodes.list, align: ALIGN_16);
                  v533.allocatedNodes.list = nullptr;
                  v533.allocatedNodes.size = 0;
                }
                v533.allocatedNodes.num = 0;
              }
            }
          }
          ++v174;
          v176 = v175->modelInfo.num;
        }
        while ( v174 < v176 );
      }
      ++v172;
      ++v173;
    }
    while ( v172 < this->nodes.num );
  }
  HIDWORD(v171) = v7;
  v179 = va::va(
           this: &v534,
           fmt: "%s\tscalars {\n",
           a3: v171,
           a4: v170,
           a5: v169,
           a6: (int)v296,
           a7: (int)v335,
           a8: (int)v374,
           a9: v413,
           a10: v452,
           a11: v491);
  for ( i12 = 0; v179->buffer[i12] != 0; ++i12 )
    ;
  str->Write(this: str, a2: v179, a3: i12);
  HIDWORD(v183) = v519.num;
  v184 = 0;
  if ( v519.num > 0 )
  {
    v185 = 0;
    do
    {
      LODWORD(v186) = v519.list[v185].flags;
      LODWORD(v187) = v519.list[v185].name.str;
      HIDWORD(v187) = v7;
      HIDWORD(v186) = v186 & 1;
      HIDWORD(v181) = HIDWORD(v186) != 0;
      v188 = va::va(
               this: &v534,
               fmt: "%s\t\t%s %d\n",
               a3: v187,
               a4: v181,
               a5: v186,
               a6: v297,
               a7: v336,
               a8: v375,
               a9: v414,
               a10: v453,
               a11: v492);
      for ( i13 = 0; v188->buffer[i13] != 0; ++i13 )
        ;
      str->Write(this: str, a2: v188, a3: i13);
      HIDWORD(v183) = v519.num;
      ++v184;
      ++v185;
    }
    while ( v184 < v519.num );
  }
  HIDWORD(v182) = v7;
  v190 = va::va(
           this: &v534,
           fmt: "%s\t}\n",
           a3: v182,
           a4: v181,
           a5: v183,
           a6: v297,
           a7: v336,
           a8: v375,
           a9: v414,
           a10: v453,
           a11: v492);
  for ( i14 = 0; v190->buffer[i14] != 0; ++i14 )
    ;
  str->Write(this: str, a2: v190, a3: i14);
  v195 = nullptr;
  v196 = 0;
  *(_WORD *)&v522.memTag = 1280;
  memset(&v522, 0, 14);
  v197 = this->subWebs.num;
  if ( v197 > 0 )
  {
    v198 = idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
             this: &v522,
             newsize: this->subWebs.num);
    v195 = v522.list;
    if ( v198 == 0 )
      goto LABEL_108;
    v196 = v522.size;
  }
  v522.num = v197;
  if ( v197 >= v196 )
    v522.num = v196;
LABEL_108:
  LODWORD(v192) = this->subWebs.num;
  v199 = 0;
  if ( (int)v192 > 0 )
  {
    LODWORD(v192) = v195 - 1;
    do
    {
      HIDWORD(v192) = (__int16)v199;
      LODWORD(v192) = v192 + 2;
      *(_WORD *)v192 = v199++;
      LODWORD(v193) = this->subWebs.num;
    }
    while ( v199 < (int)v193 );
  }
  v525[1].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName>_vtbl *)this;
  v525[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName>_vtbl *)&idSort_SubWebName::`vftable';
  if ( v195 != nullptr )
    idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName>::Sort(
      this: v525,
      base: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v195,
      num: v522.num,
      a4: v194,
      a5: SHIDWORD(v193),
      a6: v193,
      a7: v192);
  v200 = nullptr;
  *(_WORD *)&v521.memTag = 1280;
  v201 = 0;
  memset(&v521, 0, 14);
  v525[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName>_vtbl *)&idSort<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>>::`vftable';
  v202 = this->nodes.num;
  if ( v202 > 0 )
  {
    v203 = idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
             this: &v521,
             newsize: this->nodes.num);
    v200 = v521.list;
    if ( v203 == 0 )
      goto LABEL_118;
    v201 = v521.size;
  }
  v521.num = v202;
  if ( v202 >= v201 )
    v521.num = v201;
LABEL_118:
  LODWORD(v192) = this->nodes.num;
  v204 = 0;
  if ( (int)v192 > 0 )
  {
    LODWORD(v192) = v200 - 1;
    do
    {
      HIDWORD(v192) = (__int16)v204;
      LODWORD(v192) = v192 + 2;
      *(_WORD *)v192 = v204++;
      LODWORD(v193) = this->nodes.num;
    }
    while ( v204 < (int)v193 );
  }
  v528[1].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName>_vtbl *)this;
  v528[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName>_vtbl *)&idSort_StateName::`vftable';
  if ( v200 != nullptr )
    idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName>::Sort(
      this: v528,
      base: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v200,
      num: v521.num,
      a4: v194,
      a5: SHIDWORD(v193),
      a6: v193,
      a7: v192);
  LODWORD(v205) = &unk_821B0000;
  HIDWORD(v205) = &idSort<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>>::`vftable';
  v528[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName>_vtbl *)&idSort<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>>::`vftable';
  HIDWORD(v194) = v7;
  v206 = va::va(
           this: &v534,
           fmt: "%s\tsubWebs {\n",
           a3: v194,
           a4: v193,
           a5: v205,
           a6: v298,
           a7: v337,
           a8: v376,
           a9: v415,
           a10: v454,
           a11: v493);
  for ( i15 = 0; v206->buffer[i15] != 0; ++i15 )
    ;
  str->Write(this: str, a2: v206, a3: i15);
  HIDWORD(v210) = this->subWebs.num;
  v211 = 0;
  if ( SHIDWORD(v210) > 0 )
  {
    LODWORD(v208) = &unk_821B0000;
    HIDWORD(v208) = &unk_821B0000;
    v212 = v195;
    do
    {
      HIDWORD(v213) = v7;
      value = v212->value;
      HIDWORD(v215) = 5 * value;
      LODWORD(v215) = this->subWebs.list;
      v216 = 40 * value + v215;
      LODWORD(v213) = *(_DWORD *)(v216 + 16);
      v217 = va::va(
               this: &v534,
               fmt: "%s\t\t// sub-web \"%s\"\n",
               a3: v213,
               a4: v208,
               a5: v215,
               a6: v299,
               a7: v338,
               a8: v377,
               a9: v416,
               a10: v455,
               a11: v494);
      for ( i16 = 0; v217->buffer[i16] != 0; ++i16 )
        ;
      str->Write(this: str, a2: v217, a3: i16);
      LODWORD(v219) = *(_DWORD *)(v216 + 16);
      HIDWORD(v219) = v7;
      v222 = va::va(
               this: &v534,
               fmt: "%s\t\tsubWeb \"%s\" {\n",
               a3: v219,
               a4: v221,
               a5: v220,
               a6: v300,
               a7: v339,
               a8: v378,
               a9: v417,
               a10: v456,
               a11: v495);
      for ( i17 = 0; v222->buffer[i17] != 0; ++i17 )
        ;
      str->Write(this: str, a2: v222, a3: i17);
      HIDWORD(v224) = v7;
      v227 = va::va(
               this: &v534,
               fmt: "%s\t\t\tprops {\n",
               a3: v224,
               a4: v226,
               a5: v225,
               a6: v301,
               a7: v340,
               a8: v379,
               a9: v418,
               a10: v457,
               a11: v496);
      for ( i18 = 0; v227->buffer[i18] != 0; ++i18 )
        ;
      str->Write(this: str, a2: v227, a3: i18);
      v229 = idColor::ToString(this: (idColor *)(v216 + 20), precision: 2, parens: false);
      v232 = va::va(
               this: &v534,
               fmt: "%s\t\t\t\tcolor ( %s )\n",
               a3: __SPAIR64__(v7, (unsigned int)v229),
               a4: v231,
               a5: v230,
               a6: v302,
               a7: v341,
               a8: v380,
               a9: v419,
               a10: v458,
               a11: v497);
      for ( i19 = 0; v232->buffer[i19] != 0; ++i19 )
        ;
      str->Write(this: str, a2: v232, a3: i19);
      HIDWORD(v234) = *(unsigned __int8 *)(v216 + 36);
      HIDWORD(v235) = v7;
      LODWORD(v236) = HIDWORD(v234) - 1;
      LODWORD(v235) = HIDWORD(v234) != 0;
      v237 = va::va(
               this: &v534,
               fmt: "%s\t\t\t\thub %d\n",
               a3: v235,
               a4: v236,
               a5: v234,
               a6: v303,
               a7: v342,
               a8: v381,
               a9: v420,
               a10: v459,
               a11: v498);
      for ( i20 = 0; v237->buffer[i20] != 0; ++i20 )
        ;
      str->Write(this: str, a2: v237, a3: i20);
      HIDWORD(v239) = *(unsigned __int8 *)(v216 + 37);
      HIDWORD(v240) = v7;
      LODWORD(v241) = HIDWORD(v239) - 1;
      LODWORD(v240) = HIDWORD(v239) != 0;
      v242 = va::va(
               this: &v534,
               fmt: "%s\t\t\t\tvisible %d\n",
               a3: v240,
               a4: v241,
               a5: v239,
               a6: v304,
               a7: v343,
               a8: v382,
               a9: v421,
               a10: v460,
               a11: v499);
      for ( i21 = 0; v242->buffer[i21] != 0; ++i21 )
        ;
      str->Write(this: str, a2: v242, a3: i21);
      HIDWORD(v244) = v7;
      v247 = va::va(
               this: &v534,
               fmt: v526,
               a3: v244,
               a4: v246,
               a5: v245,
               a6: v305,
               a7: v344,
               a8: v383,
               a9: v422,
               a10: v461,
               a11: v500);
      for ( i22 = 0; v247->buffer[i22] != 0; ++i22 )
        ;
      str->Write(this: str, a2: v247, a3: i22);
      HIDWORD(v249) = v7;
      v252 = va::va(
               this: &v534,
               fmt: "%s\t\t\t",
               a3: v249,
               a4: v251,
               a5: v250,
               a6: v306,
               a7: v345,
               a8: v384,
               a9: v423,
               a10: v462,
               a11: v501);
      idStr::idStr(this: &v532, text: v252);
      v255 = this;
      v256 = 0;
      HIDWORD(v257) = this->nodes.num;
      if ( SHIDWORD(v257) > 0 )
      {
        v258 = this;
        v259 = v200;
        do
        {
          HIDWORD(v257) = v258->nodes.list;
          LODWORD(v253) = v259->value;
          HIDWORD(v253) = 4 * v253;
          v260 = *(idDeclAnimWebNode **)(4 * v253 + HIDWORD(v257));
          if ( v260 != nullptr )
          {
            HIDWORD(v257) = v260->subWebIndex.value;
            if ( HIDWORD(v257) == value )
            {
              idDeclAnimWebNode::Write(this: v260, decl: this, str, indent: v532.data);
              v258 = this;
            }
          }
          LODWORD(v257) = v258->nodes.num;
          ++v256;
          ++v259;
        }
        while ( v256 < (int)v257 );
        v255 = this;
      }
      HIDWORD(v254) = v7;
      v261 = va::va(
               this: &v535,
               fmt: v529,
               a3: v254,
               a4: v253,
               a5: v257,
               a6: v307,
               a7: v346,
               a8: v385,
               a9: v424,
               a10: v463,
               a11: v502);
      for ( i23 = 0; v261->buffer[i23] != 0; ++i23 )
        ;
      str->Write(this: str, a2: v261, a3: i23);
      idStr::FreeData(this: &v532);
      HIDWORD(v210) = v255->subWebs.num;
      ++v211;
      ++v212;
    }
    while ( v211 < SHIDWORD(v210) );
  }
  HIDWORD(v209) = v7;
  v263 = va::va(
           this: &v535,
           fmt: "%s\t}\n",
           a3: v209,
           a4: v208,
           a5: v210,
           a6: v299,
           a7: v338,
           a8: v377,
           a9: v416,
           a10: v455,
           a11: v494);
  for ( i24 = 0; v263->buffer[i24] != 0; ++i24 )
    ;
  str->Write(this: str, a2: v263, a3: i24);
  HIDWORD(v265) = &unk_821B0000;
  HIDWORD(v266) = v7;
  v268 = va::va(
           this: &v535,
           fmt: "%s}\n",
           a3: v266,
           a4: v267,
           a5: v265,
           a6: v308,
           a7: v347,
           a8: v386,
           a9: v425,
           a10: v464,
           a11: v503);
  for ( i25 = 0; v268->buffer[i25] != 0; ++i25 )
    ;
  str->Write(this: str, a2: v268, a3: i25);
  if ( (v521.listStatic == 0 || v521.listStatic == 2) && v200 != nullptr )
    idMem::Free(this: &mem, ptr: v200, align: ALIGN_16);
  if ( (v522.listStatic == 0 || v522.listStatic == 2) && v195 != nullptr )
    idMem::Free(this: &mem, ptr: v195, align: ALIGN_16);
  idMD6Allocator_New::~idMD6Allocator_New(this: &v531);
  if ( v523.listStatic == 0 || v523.listStatic == 2 )
  {
    if ( v523.list != nullptr )
      idMem::Free(this: &mem, ptr: v523.list, align: ALIGN_16);
    v523.list = nullptr;
    v523.size = 0;
  }
  v523.num = 0;
  if ( v524.listStatic == 0 || v524.listStatic == 2 )
  {
    if ( v524.list != nullptr )
      idMem::Free(this: &mem, ptr: v524.list, align: ALIGN_16);
    v524.list = nullptr;
    v524.size = 0;
  }
  v524.num = 0;
  if ( v519.listStatic == 0 || v519.listStatic == 2 )
  {
    if ( v519.list != nullptr )
      idMem::Free(this: &mem, ptr: v519.list, align: ALIGN_16);
    v519.list = nullptr;
    v519.size = 0;
  }
  v519.num = 0;
  if ( (v520.listStatic == 0 || v520.listStatic == 2) && v520.list != nullptr )
    idMem::Free(this: &mem, ptr: v520.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$232595
// EA  : 0x826019EC
// RVA : 0x006019EC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232595()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 144));
}


// ========================================================================
// __unwind$232596
// EA  : 0x82601A14
// RVA : 0x00601A14
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232596()
{
  int v0; // r12

  idSort_LayerName::~idSort_LayerName(this: (idSort_LayerName *)(v0 - 8976 + 240));
}


// ========================================================================
// __unwind$232597
// EA  : 0x82601A3C
// RVA : 0x00601A3C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232597()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 128));
}


// ========================================================================
// __unwind$232598
// EA  : 0x82601A64
// RVA : 0x00601A64
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232598()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 208));
}


// ========================================================================
// __unwind$232599
// EA  : 0x82601A8C
// RVA : 0x00601A8C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232599()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 192));
}


// ========================================================================
// __unwind$233481
// EA  : 0x82601AB4
// RVA : 0x00601AB4
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_233481()
{
  int v0; // r12

  idMD6Allocator::~idMD6Allocator(this: (idMD6Allocator *)(v0 - 8976 + 272));
}


// ========================================================================
// __unwind$232600
// EA  : 0x82601ADC
// RVA : 0x00601ADC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232600()
{
  int v0; // r12

  idMD6Allocator_New::~idMD6Allocator_New(this: (idMD6Allocator_New *)(v0 - 8976 + 272));
}


// ========================================================================
// __unwind$232601
// EA  : 0x82601B04
// RVA : 0x00601B04
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232601()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(v0 - 8976 + 336));
}


// ========================================================================
// __unwind$232602
// EA  : 0x82601B2C
// RVA : 0x00601B2C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232602()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 176));
}


// ========================================================================
// __unwind$232603
// EA  : 0x82601B54
// RVA : 0x00601B54
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232603()
{
  int v0; // r12

  idSort_SubWebName::~idSort_SubWebName(this: (idSort_SubWebName *)(v0 - 8976 + 224));
}


// ========================================================================
// __unwind$232604
// EA  : 0x82601B7C
// RVA : 0x00601B7C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232604()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8976 + 160));
}


// ========================================================================
// __unwind$232605
// EA  : 0x82601BA4
// RVA : 0x00601BA4
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232605()
{
  int v0; // r12

  idSort_StateName::~idSort_StateName(this: (idSort_StateName *)(v0 - 8976 + 248));
}


// ========================================================================
// __unwind$232606
// EA  : 0x82601BCC
// RVA : 0x00601BCC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_232606()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8976 + 304));
}


// ========================================================================
// ?FindNodeIndices@idDeclAnimWeb@@QBAHV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@AAV?$idList@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@$04@@@Z
// EA  : 0x82601BF8
// RVA : 0x00601BF8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

int __fastcall idDeclAnimWeb::FindNodeIndices(
        idDeclAnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *nodeIndices)
{
  __int16 v5; // r26
  int v7; // r29
  int v8; // r28
  int v9; // r31
  idDeclAnimWebNode *v10; // r11
  idIndex<short,enum invalidUserChannelIndex_t> v12; // [sp+50h] [-40h] BYREF

  v5 = (__int16)subWebIndex;
  v7 = 0;
  if ( this->nodes.num > 0 )
  {
    v8 = (__int16)stateIndex;
    v9 = 0;
    do
    {
      v10 = this->nodes.list[v9];
      if ( v10->states.stateIndex[0].value == v8 && (v5 == -1 || v5 == v10->subWebIndex.value) )
      {
        v12.value = v7;
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(this: nodeIndices, obj: &v12);
        if ( idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,5>::IsFull(this: (idList<int,5> *)nodeIndices) )
          break;
      }
      ++v7;
      ++v9;
    }
    while ( v7 < this->nodes.num );
  }
  return nodeIndices->num;
}


// ========================================================================
// ?FindNodeIndices@idDeclAnimWeb@@QBA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABVstateList_t@1@AAV?$idList@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@$04@@@Z
// EA  : 0x82601CA0
// RVA : 0x00601CA0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::FindNodeIndices(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idDeclAnimWeb::stateList_t *stateIndices,
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *nodeIndices)
{
  int v9; // r27
  _DWORD *v10; // r31
  int v11; // r29
  idDeclAnimWebNode *v12; // r30
  idIndex<short,enum invalidUserChannelIndex_t> v14; // [sp+50h] [-50h] BYREF

  if ( (__int16)subWebIndex < 0 )
    goto LABEL_9;
  v9 = 0;
  v10 = (_DWORD *)(40 * (__int16)subWebIndex + *(_DWORD *)&result[36].value);
  if ( (int)v10[1] > 0 )
  {
    v11 = 0;
    do
    {
      v12 = *(idDeclAnimWebNode **)(4 * *(__int16 *)(*v10 + v11) + *(_DWORD *)&result[28].value);
      if ( idDeclAnimWebNode::MatchStates(this: v12, stateIndices) == stateIndices->numStates )
      {
        v14.value = v12->nodeIndex.value;
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(this: nodeIndices, obj: &v14);
      }
      ++v9;
      v11 += 2;
    }
    while ( v9 < v10[1] );
  }
  if ( nodeIndices->num <= 0 )
  {
LABEL_9:
    HIWORD(this->__vftable) = -1;
    return this;
  }
  else
  {
    HIWORD(this->__vftable) = nodeIndices->list->value;
    return this;
  }
}


// ========================================================================
// ?AddNode@idDeclAnimWeb@@QAA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82601D88
// RVA : 0x00601D88
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::AddNode(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex)
{
  int v8; // r26
  idDeclAnimWebNode *v9; // r3
  idDeclAnimWebNode *v10; // r29
  encounterGroupRole_t v12[16]; // [sp+50h] [-40h] BYREF

  idDeclAnimWeb::FindNodeIndex(this: (idDeclAnimWeb *)v12, result, subWebIndex, stateIndex);
  if ( SHIWORD(v12[0]) < 0 )
  {
    v8 = *(_DWORD *)&result[30].value;
    ++*(_DWORD *)&result[112].value;
    v9 = (idDeclAnimWebNode *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x40u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v12[0] = (encounterGroupRole_t)v9;
    if ( v9 != nullptr )
      v10 = idDeclAnimWebNode::idDeclAnimWebNode(
              this: v9,
              nodeIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(__int16)v8,
              subWebIndex_: subWebIndex,
              stateIndex_: stateIndex);
    else
      v10 = nullptr;
    v12[0] = (encounterGroupRole_t)v10;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&result[28], obj: v12);
    HIWORD(v12[0]) = v10->nodeIndex.value;
    idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
      this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)(40 * (__int16)subWebIndex
                                                                + *(_DWORD *)&result[36].value),
      obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)v12);
    HIWORD(this->__vftable) = v10->nodeIndex.value;
  }
  else
  {
    HIWORD(this->__vftable) = HIWORD(v12[0]);
  }
  return this;
}


// ========================================================================
// __unwind$234885
// EA  : 0x82601E78
// RVA : 0x00601E78
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall _unwind_234885(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?AddNode@idDeclAnimWeb@@QAA?AV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABVstateList_t@1@@Z
// EA  : 0x82601EA8
// RVA : 0x00601EA8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::AddNode(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *result,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idDeclAnimWeb::stateList_t *stateIndices)
{
  int v8; // r26
  idDeclAnimWebNode *v9; // r3
  idDeclAnimWebNode *v10; // r29
  encounterGroupRole_t v12[16]; // [sp+50h] [-40h] BYREF

  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)v12,
    result,
    subWebIndex,
    stateList: stateIndices,
    exactMatch: true);
  if ( SHIWORD(v12[0]) < 0 )
  {
    v8 = *(_DWORD *)&result[30].value;
    ++*(_DWORD *)&result[112].value;
    v9 = (idDeclAnimWebNode *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x40u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v12[0] = (encounterGroupRole_t)v9;
    if ( v9 != nullptr )
      v10 = idDeclAnimWebNode::idDeclAnimWebNode(
              this: v9,
              nodeIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(__int16)v8,
              subWebIndex_: subWebIndex,
              stateIndices);
    else
      v10 = nullptr;
    v12[0] = (encounterGroupRole_t)v10;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&result[28], obj: v12);
    HIWORD(v12[0]) = v10->nodeIndex.value;
    idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
      this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)(40 * (__int16)subWebIndex
                                                                + *(_DWORD *)&result[36].value),
      obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)v12);
    HIWORD(this->__vftable) = v10->nodeIndex.value;
  }
  else
  {
    HIWORD(this->__vftable) = HIWORD(v12[0]);
  }
  return this;
}


// ========================================================================
// __unwind$234939
// EA  : 0x82601F9C
// RVA : 0x00601F9C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall _unwind_234939(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?rewriteAnimWebs_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82601FD0
// RVA : 0x00601FD0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall rewriteAnimWebs_f(const idCmdArgs *args)
{
  int v1; // r23
  int v2; // r28
  const char *str; // r4
  idDecl *v4; // r3
  idDeclAnimWeb *v5; // r30
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  idFile_Memory v9; // [sp+60h] [-1B0h] BYREF

  common->SetRefreshOnPrint(this: common, a2: true);
  v1 = 0;
  if ( idDeclAnimWeb::resourceList.declSources.num > 0 )
  {
    v2 = 0;
    do
    {
      str = idDeclAnimWeb::resourceList.declSources.list[v2]->name.str;
      if ( str != nullptr )
      {
        v4 = (idDecl *)idDeclInfo::FindWithInheritance(
                         this: &idDeclAnimWeb::resourceList,
                         name: str,
                         makeDefault: false);
        v5 = (idDeclAnimWeb *)v4;
        if ( v4 != nullptr )
        {
          HIBYTE(v4[4].trackedMemory) = 0;
          idDecl::ReParse(this: v4, fromDisk: true);
          idFile_Memory::idFile_Memory(this: &v9, name: "*unknown*");
          v9.__vftable = (idFile_Memory_vtbl *)&idFile_String::`vftable';
          HIDWORD(v6) = &byte_8200D768;
          idDeclAnimWeb::Write(this: v5, str: (idFile_String *)&v9, indent: v6, a4: v8, a5: v7);
          idDecl::SetText(this: &v5->idDecl, text: v9.filePtr, length: 0);
          idDecl::ReplaceSourceFileText(this: &v5->idDecl, useSourceControl: true);
          v5->expandSubWebLinks = true;
          idDecl::ReParse(this: &v5->idDecl, fromDisk: true);
          idFile_Memory::~idFile_Memory(this: &v9);
        }
      }
      ++v1;
      ++v2;
    }
    while ( v1 < idDeclAnimWeb::resourceList.declSources.num );
  }
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// __unwind$234987
// EA  : 0x82602104
// RVA : 0x00602104
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_234987()
{
  int v0; // r12

  idFile_String::~idFile_String(this: (idFile_String *)(v0 - 528 + 96));
}


// ========================================================================
// ?FreeData@idDeclAnimWeb@@UAAXXZ
// EA  : 0x826025C0
// RVA : 0x006025C0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::FreeData(idDeclAnimWeb *this)
{
  int v2; // r27
  int v3; // r30
  idDeclAnimWebNode *v4; // r10
  idDeclAnimWebNode *v5; // r29
  idDeclAnimWebNode **list; // r4
  char *v7; // r3
  char *v8; // r3
  idDeclAnimWeb::idStateInfo *v9; // r4
  const idDeclMD6 **v10; // r4
  idAtomicString *v11; // r4
  char *v12; // r3
  idDeclAnimWeb::idEdgeCache *v13; // r4
  idDeclAnimWeb::idNodeCache *v14; // r4
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *edgeIndexCache; // r4

  v2 = 0;
  if ( this->nodes.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->nodes.list[v3];
      if ( v4 != nullptr )
      {
        v5 = this->nodes.list[v3];
        idDeclAnimWebNode::~idDeclAnimWebNode(this: v4);
        idMem::Free(this: &mem, ptr: (void *)v5, align: ALIGN_16);
        this->nodes.list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->nodes.num );
  }
  if ( this->nodes.listStatic == 0 || this->nodes.listStatic == 2 )
  {
    list = this->nodes.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->nodes.list = nullptr;
    this->nodes.size = 0;
  }
  this->nodes.num = 0;
  if ( this->layers.listStatic == 0 || this->layers.listStatic == 2 )
  {
    v7 = (char *)this->layers.list;
    if ( v7 != nullptr )
      idListArrayDelete<idMD6Mesh::stset_t>(ptr: v7, num: this->layers.size);
    this->layers.list = nullptr;
    this->layers.size = 0;
  }
  this->layers.num = 0;
  if ( this->subWebs.listStatic == 0 || this->subWebs.listStatic == 2 )
  {
    v8 = (char *)this->subWebs.list;
    if ( v8 != nullptr )
      idListArrayDelete<idDeclAnimWeb::idSubWebInfo>(ptr: v8, num: this->subWebs.size);
    this->subWebs.list = nullptr;
    this->subWebs.size = 0;
  }
  this->subWebs.num = 0;
  if ( this->states.listStatic == 0 || this->states.listStatic == 2 )
  {
    v9 = this->states.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->states.list = nullptr;
    this->states.size = 0;
  }
  this->states.num = 0;
  if ( this->models.listStatic == 0 || this->models.listStatic == 2 )
  {
    v10 = this->models.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->models.list = nullptr;
    this->models.size = 0;
  }
  this->models.num = 0;
  if ( this->editorModels.listStatic == 0 || this->editorModels.listStatic == 2 )
  {
    v11 = this->editorModels.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->editorModels.list = nullptr;
    this->editorModels.size = 0;
  }
  this->editorModels.num = 0;
  if ( this->edges.listStatic == 0 || this->edges.listStatic == 2 )
  {
    v12 = (char *)this->edges.list;
    if ( v12 != nullptr )
      idListArrayDelete<idDeclAnimWebEdge>(ptr: v12, num: this->edges.size);
    this->edges.list = nullptr;
    this->edges.size = 0;
  }
  this->edges.num = 0;
  if ( this->edgeCache.listStatic == 0 || this->edgeCache.listStatic == 2 )
  {
    v13 = this->edgeCache.list;
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    this->edgeCache.list = nullptr;
    this->edgeCache.size = 0;
  }
  this->edgeCache.num = 0;
  if ( this->nodeCache.listStatic == 0 || this->nodeCache.listStatic == 2 )
  {
    v14 = this->nodeCache.list;
    if ( v14 != nullptr )
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    this->nodeCache.list = nullptr;
    this->nodeCache.size = 0;
  }
  this->nodeCache.num = 0;
  edgeIndexCache = this->edgeIndexCache;
  if ( edgeIndexCache != nullptr )
  {
    idMem::Free(this: &mem, ptr: edgeIndexCache, align: ALIGN_16);
    this->edgeIndexCache = nullptr;
    this->edgeIndexCacheSize = 0;
  }
  ++this->changeId;
}


// ========================================================================
// ??0idDeclAnimWeb@@QAA@XZ
// EA  : 0x82602CD0
// RVA : 0x00602CD0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::idDeclAnimWeb(idDeclAnimWeb *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclAnimWeb_vtbl *)&idDeclAnimWeb::`vftable';
  this->nodes.list = nullptr;
  this->nodes.granularity = 0;
  this->nodes.memTag = 32;
  this->nodes.listStatic = 0;
  this->nodes.size = 0;
  this->nodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  this->subWebs.granularity = 0;
  this->subWebs.memTag = 32;
  this->subWebs.listStatic = 0;
  this->subWebs.list = nullptr;
  this->subWebs.size = 0;
  this->subWebs.num = 0;
  this->states.list = nullptr;
  this->states.granularity = 0;
  this->states.memTag = 32;
  this->states.listStatic = 0;
  this->states.size = 0;
  this->states.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->states);
  this->models.list = nullptr;
  this->models.granularity = 0;
  this->models.memTag = 32;
  this->models.listStatic = 0;
  this->models.size = 0;
  this->models.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->models);
  this->edges.granularity = 0;
  this->edges.memTag = 32;
  this->edges.listStatic = 0;
  this->edges.list = nullptr;
  this->edges.size = 0;
  this->edges.num = 0;
  this->edgeCache.list = nullptr;
  this->edgeCache.granularity = 0;
  this->edgeCache.memTag = 32;
  this->edgeCache.listStatic = 0;
  this->edgeCache.size = 0;
  this->edgeCache.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeCache);
  this->nodeCache.list = nullptr;
  this->nodeCache.granularity = 0;
  this->nodeCache.memTag = 32;
  this->nodeCache.listStatic = 0;
  this->nodeCache.size = 0;
  this->nodeCache.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodeCache);
  this->scalars.list = nullptr;
  this->scalars.granularity = 0;
  this->scalars.memTag = 32;
  this->scalars.listStatic = 0;
  this->scalars.size = 0;
  this->scalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  this->editorModels.list = nullptr;
  this->editorModels.granularity = 0;
  this->editorModels.memTag = 32;
  this->editorModels.listStatic = 0;
  this->editorModels.size = 0;
  this->editorModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->editorModels);
  this->layers.granularity = 0;
  this->layers.memTag = 32;
  this->layers.listStatic = 0;
  this->layers.list = nullptr;
  this->layers.size = 0;
  this->layers.num = 0;
  this->edgeIndexCache = nullptr;
  this->edgeIndexCacheSize = 0;
  this->changeId = 0;
  this->expandSubWebLinks = true;
  this->settings.editPos.x = 0.0;
  this->settings.editPos.y = 0.0;
  this->settings.gridSize = 32;
  this->settings.editPos.z = 1.0;
  this->settings.snapToGrid = true;
  this->settings.showGrid = true;
  this->settings.alwaysShowIntraSubwebLinks = true;
  this->settings.alwaysShowNodeProps = false;
  this->settings.showAbbreviatedNodeProps = false;
  this->settings.showIncomingLinks = false;
  this->settings.isComposite = false;
  this->settings.mergeModels = true;
  this->settings.defaultBlendOutWindow = 10;
  this->settings.defaultBlendDuration = 10;
  this->settings.subWebBlend = SUBWEBBLEND_USE_SOURCE_NODE;
  this->settings.nodeProps[0] = true;
  this->settings.nodeProps[1] = true;
  this->settings.nodeProps[2] = false;
  this->settings.nodeProps[3] = true;
  this->settings.nodeProps[4] = true;
  this->settings.nodeProps[5] = true;
  this->settings.gridSize = 32;
  this->settings.showGrid = true;
  this->settings.snapToGrid = true;
  return this;
}


// ========================================================================
// __unwind$235781
// EA  : 0x82602EDC
// RVA : 0x00602EDC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235781()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$235782
// EA  : 0x82602F04
// RVA : 0x00602F04
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235782()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// __unwind$235783
// EA  : 0x82602F30
// RVA : 0x00602F30
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235783()
{
  int v0; // r12

  idList<idDeclAnimWeb::idSubWebInfo,32>::~idList<idDeclAnimWeb::idSubWebInfo,32>(this: (idList<idDeclAnimWeb::idSubWebInfo,32> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$235784
// EA  : 0x82602F5C
// RVA : 0x00602F5C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235784()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$235785
// EA  : 0x82602F88
// RVA : 0x00602F88
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235785()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// __unwind$235786
// EA  : 0x82602FB4
// RVA : 0x00602FB4
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235786()
{
  int v0; // r12

  idList<idDeclAnimWebEdge,32>::~idList<idDeclAnimWebEdge,32>(this: (idList<idDeclAnimWebEdge,32> *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// __unwind$235787
// EA  : 0x82602FE0
// RVA : 0x00602FE0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235787()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$235788
// EA  : 0x8260300C
// RVA : 0x0060300C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235788()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 152));
}


// ========================================================================
// __unwind$235789
// EA  : 0x82603038
// RVA : 0x00603038
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235789()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 168));
}


// ========================================================================
// __unwind$235790
// EA  : 0x82603064
// RVA : 0x00603064
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235790()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 184));
}


// ========================================================================
// ??1idDeclAnimWeb@@UAA@XZ
// EA  : 0x826030A8
// RVA : 0x006030A8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::~idDeclAnimWeb(idDeclAnimWeb *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3

  this->__vftable = (idDeclAnimWeb_vtbl *)&idDeclAnimWeb::`vftable';
  idDeclAnimWeb::FreeData(this);
  if ( this->layers.listStatic == 0 || this->layers.listStatic == 2 )
  {
    list = (char *)this->layers.list;
    if ( list != nullptr )
      idListArrayDelete<idMD6Mesh::stset_t>(ptr: list, num: this->layers.size);
    this->layers.list = nullptr;
    this->layers.size = 0;
  }
  this->layers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->editorModels);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodeCache);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeCache);
  if ( this->edges.listStatic == 0 || this->edges.listStatic == 2 )
  {
    v3 = (char *)this->edges.list;
    if ( v3 != nullptr )
      idListArrayDelete<idDeclAnimWebEdge>(ptr: v3, num: this->edges.size);
    this->edges.list = nullptr;
    this->edges.size = 0;
  }
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->models);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->states);
  if ( this->subWebs.listStatic == 0 || this->subWebs.listStatic == 2 )
  {
    v4 = (char *)this->subWebs.list;
    if ( v4 != nullptr )
      idListArrayDelete<idDeclAnimWeb::idSubWebInfo>(ptr: v4, num: this->subWebs.size);
    this->subWebs.list = nullptr;
    this->subWebs.size = 0;
  }
  this->subWebs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$235936
// EA  : 0x826031B8
// RVA : 0x006031B8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235936()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$235937
// EA  : 0x826031E0
// RVA : 0x006031E0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235937()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$235938
// EA  : 0x8260320C
// RVA : 0x0060320C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235938()
{
  int v0; // r12

  idList<idDeclAnimWeb::idSubWebInfo,32>::~idList<idDeclAnimWeb::idSubWebInfo,32>(this: (idList<idDeclAnimWeb::idSubWebInfo,32> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$235939
// EA  : 0x82603238
// RVA : 0x00603238
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235939()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$235940
// EA  : 0x82603264
// RVA : 0x00603264
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235940()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$235941
// EA  : 0x82603290
// RVA : 0x00603290
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235941()
{
  int v0; // r12

  idList<idDeclAnimWebEdge,32>::~idList<idDeclAnimWebEdge,32>(this: (idList<idDeclAnimWebEdge,32> *)(*(_DWORD *)(v0 - 112 + 132) + 120));
}


// ========================================================================
// __unwind$235942
// EA  : 0x826032BC
// RVA : 0x006032BC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$235943
// EA  : 0x826032E8
// RVA : 0x006032E8
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235943()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// __unwind$235944
// EA  : 0x82603314
// RVA : 0x00603314
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235944()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 168));
}


// ========================================================================
// __unwind$235945
// EA  : 0x82603340
// RVA : 0x00603340
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235945()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 184));
}


// ========================================================================
// __unwind$235946
// EA  : 0x8260336C
// RVA : 0x0060336C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_235946()
{
  int v0; // r12

  idList<idDeclAnimWeb::idLayerInfo,32>::Clear(this: (idList<idDeclAnimWeb::idLayerInfo,32> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 200));
}


// ========================================================================
// ?AllocEdge@idDeclAnimWeb@@QAA?AV?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@XZ
// EA  : 0x82603398
// RVA : 0x00603398
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::AllocEdge(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *result)
{
  HIWORD(this->__vftable) = *(_DWORD *)&result[62].value;
  idList<idDeclAnimWebEdge,32>::Alloc(this: (idList<idDeclAnimWebEdge,32> *)&result[60]);
  idList<idDeclAnimWeb::idEdgeCache,32>::Alloc(this: (idList<idDeclAnimWeb::idEdgeCache,32> *)&result[68]);
  return this;
}


// ========================================================================
// ?Composite@idDeclAnimWeb@@SAXAAV?$idList@PBVidDeclAnimWeb@@$04@@PAV1@@Z
// EA  : 0x826033F0
// RVA : 0x006033F0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::Composite(
        idList<idDeclAnimWeb const *,5> *mergeDecls,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *output)
{
  int v4; // r3
  int v5; // r16
  bool value; // r10
  idDeclSource *declSource; // r15
  idResourceList *v8; // r11
  int v9; // r20
  BOOL v10; // r22
  int v11; // r10
  const idDeclAnimWeb *v12; // r26
  int v13; // r28
  int v14; // r29
  int v15; // r10
  int v16; // r9
  const encounterGroupRole_t *v17; // r4
  int v18; // r11
  int v19; // r29
  int v20; // r30
  int v21; // r28
  int v22; // r29
  idDeclAnimWeb::idSubWebInfo *v23; // r30
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *list; // r4
  int v25; // r24
  int v26; // r25
  idDeclAnimWebNode *v27; // r27
  int Index; // r3
  int v29; // r30
  idDeclAnimWeb::stateList_t *p_states; // r29
  int v31; // r11
  char v32; // r10
  const char *v33; // r4
  idDeclAnimWebNode *v34; // r3
  __int16 textSource_high; // r28
  idDeclAnimWebNode *v36; // r30
  int trackedMemory; // r11
  int v38; // r29
  const idDeclAnimWebNode::idModelInfo *v39; // r4
  const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *v40; // r11
  const idDeclMD6 **v41; // r10
  const idDeclMD6 *v42; // r7
  int v43; // r8
  int v44; // r10
  int v45; // r11
  unsigned __int8 animDelta; // r11
  __int16 v47; // r3
  idDeclAnimWeb::idSubWebInfo *v48; // r9
  __int16 v49; // r7
  int v50; // r8
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *v51; // r3
  int v52; // r10
  int v53; // r11
  const char *str; // r30
  const char *size; // r29
  idDeclAnimWebNode *v56; // r28
  idDeclAnimWeb::idSubWebInfo *v57; // r29
  int v58; // r11
  idDeclAnimWeb::idSubWebInfo *v59; // r11
  bool isVisible; // r8
  bool used; // r6
  int v62; // r10
  int v63; // r30
  const idDeclAnimWebNode::idModelInfo *v64; // r4
  const idDeclMD6 **v65; // r10
  const idDeclMD6 *v66; // r7
  int v67; // r8
  int v68; // r10
  int v69; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *trackedMemory_high; // r5
  int v71; // r8
  int v72; // r7
  idDeclAnimWebNode::idModelInfo *v73; // r11
  int v74; // r18
  int v75; // r19
  const idDeclAnimWeb *v76; // r26
  int v77; // r21
  int v78; // r22
  idDeclAnimWebNode *v79; // r24
  idDeclAnimWebNode *v80; // r25
  int v81; // r23
  idDeclAnimWeb::idEdgeCache *v82; // r28
  int v83; // r9
  __int16 v84; // r7
  int v85; // r27
  int v86; // r8
  __int16 v87; // r4
  char v88; // r10
  const char *v89; // r5
  idDeclAnimWebNode *v90; // r30
  int v91; // r11
  int *p_size; // r10
  _DWORD *v93; // r11
  int i; // ctr
  __int16 v95; // r29
  __int16 nextOnHashChain_high; // r30
  char v97; // r3
  int v98; // r5
  idDeclAnimWebEdge *v99; // r8
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v100; // r6
  int v101; // r10
  __int16 v102; // r11
  int v103; // r9
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *p_edges; // r3
  int v105; // r10
  __int16 v106; // r11
  int v107; // r7
  int v108; // r11
  __int64 v109; // r6
  void *md5Checksum; // r28
  idStr *v111; // r29
  idDeclSource *j; // r30
  int num; // [sp+50h] [-1B0h] BYREF
  idDeclAnimWeb v114; // [sp+54h] [-1ACh] BYREF

  v4 = Sys_Microseconds() >> 32;
  v5 = 0;
  value = output[127].value;
  *(_DWORD *)&v114.nodes.granularity = v4;
  declSource = nullptr;
  v114.nodes.list = (idDeclAnimWebNode **)1280;
  memset(&v114.md5Checksum, 0, 12);
  v9 = 0;
  num = mergeDecls->num;
  v8 = (idResourceList *)num;
  v114.nodes.size = (int)&mem;
  if ( num > 0 )
  {
    v10 = value;
    v11 = 0;
    v114.resourceListPtr = (idResourceList *)"Node not found: %s";
    do
    {
      v12 = mergeDecls->list[v11];
      if ( v10 )
      {
        v13 = 0;
        if ( v12->models.num > 0 )
        {
          v14 = 0;
          do
          {
            v15 = 0;
            v16 = *(_DWORD *)&output[54].value;
            v17 = (const encounterGroupRole_t *)&v12->models.list[v14];
            if ( v16 <= 0 )
              goto LABEL_12;
            v18 = 0;
            while ( *(_DWORD *)(v18 + *(_DWORD *)&output[52].value) != *v17 )
            {
              ++v15;
              v18 += 4;
              if ( v15 >= v16 )
                goto LABEL_12;
            }
            if ( v15 < 0 )
LABEL_12:
              idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&output[52], obj: v17);
            ++v13;
            ++v14;
          }
          while ( v13 < v12->models.num );
        }
      }
      v19 = 0;
      if ( v12->states.num > 0 )
      {
        v20 = 0;
        do
        {
          if ( HIWORD(idDeclAnimWeb::GetStateIndexForName(
                        this: (idDeclAnimWeb *)&v114.nodes.num,
                        result: output,
                        name: v12->states.list[v20].name.str)->__vftable) == 0xFFFF )
            idList<idAtomicString,109>::Append(
              this: (idList<idAtomicString,5> *)&output[44],
              obj: &v12->states.list[v20].name);
          ++v19;
          ++v20;
        }
        while ( v19 < v12->states.num );
      }
      v21 = 0;
      if ( v12->subWebs.num > 0 )
      {
        v22 = 0;
        do
        {
          if ( HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                        this: (idDeclAnimWeb *)&v114.nextOnHashChain,
                        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)output,
                        subWebName: v12->subWebs.list[v22].name.str)->__vftable) == 0xFFFF )
          {
            v23 = (idDeclAnimWeb::idSubWebInfo *)(40
                                                * (__int16)idList<idDeclAnimWeb::idSubWebInfo,32>::Append(
                                                             this: (idList<idDeclAnimWeb::idSubWebInfo,32> *)&output[36],
                                                             obj: (const idList<idIndex<short,enum invalidJointIndex_t>,30> *)&v12->subWebs.list[v22])
                                                + *(_DWORD *)&output[36].value);
            if ( v23->nodes.listStatic == 0 || v23->nodes.listStatic == 2 )
            {
              list = v23->nodes.list;
              if ( v23->nodes.list != nullptr )
              {
                num = (int)v23->nodes.list;
                idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
              }
              v23->nodes.list = nullptr;
              v23->nodes.size = 0;
            }
            v23->nodes.num = 0;
          }
          ++v21;
          ++v22;
        }
        while ( v21 < v12->subWebs.num );
      }
      v25 = 0;
      if ( v12->nodes.num > 0 )
      {
        v26 = 0;
        do
        {
          v27 = v12->nodes.list[v26];
          *(_DWORD *)&v114.subWebs.granularity = 20;
          v114.subWebs.size = (int)&v114.states;
          v114.subWebs.num = 0;
          HIBYTE(v114.states.list) = 0;
          idDeclAnimWebNode::GetName(this: v27, web: v12, name: (idStr *)&v114.subWebs.num);
          idStr::ToLower(this: (idStr *)&v114.subWebs.num);
          Index = idList<idStr,5>::FindIndex(
                    this: (idList<idStr,5> *)&v114.md5Checksum,
                    obj: (const idStr *)&v114.subWebs.num,
                    startIndex: 0);
          if ( Index >= 0 && 32 * Index + v114.md5Checksum != 0 )
          {
            str = v12->subWebs.list[v27->subWebIndex.value].name.str;
            *(_DWORD *)&v114.scalars.granularity = 20;
            v114.scalars.size = (int)&v114.editorModels;
            v114.scalars.num = 0;
            HIBYTE(v114.editorModels.list) = 0;
            idDeclAnimWebNode::GetStateName(this: v27, web: v12, idx: 0, name: (idStr *)&v114.scalars.num);
            size = (const char *)v114.scalars.size;
            idDeclAnimWeb::GetSubWebIndexForName(
              this: (idDeclAnimWeb *)((char *)&v114.idResource + 32),
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)output,
              subWebName: str);
            idDeclAnimWeb::GetStateIndexForName(
              this: (idDeclAnimWeb *)((char *)&v114.idResource + 34),
              result: output,
              name: size);
            idDeclAnimWeb::FindNodeIndex(
              this: (idDeclAnimWeb *)&v114.name,
              result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)output,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)*((unsigned __int16 *)&v114.idResource
                                                                               + 16),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)*((unsigned __int16 *)&v114.idResource + 17));
            if ( SHIWORD(v114.name.str) != -1
              && (v56 = *(idDeclAnimWebNode **)(4 * SHIWORD(v114.name.str) + *(_DWORD *)&output[28].value)) != nullptr )
            {
              idDeclAnimWeb::GetSubWebIndexForName(
                this: (idDeclAnimWeb *)((char *)&v114.name.str + 2),
                result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)output,
                subWebName: str);
              if ( SLOWORD(v114.name.str) < 0 || SLOWORD(v114.name.str) >= *(_DWORD *)&output[38].value )
                v57 = nullptr;
              else
                v57 = (idDeclAnimWeb::idSubWebInfo *)(40 * SLOWORD(v114.name.str) + *(_DWORD *)&output[36].value);
              v58 = SHIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                              this: &v114,
                              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v12,
                              subWebName: str)->__vftable);
              if ( v58 < 0 || v58 >= v12->subWebs.num )
                v59 = nullptr;
              else
                v59 = &v12->subWebs.list[v58];
              if ( v57 != nullptr && v59 != nullptr )
              {
                isVisible = v57->isVisible;
                used = v57->used;
                v57->isHub |= v59->isHub;
                v57->isVisible = v59->isVisible || isVisible;
                v57->used = v59->used || used;
              }
              v63 = 0;
              num = v27->modelInfo.num;
              v62 = num;
              if ( num > 0 )
              {
                do
                {
                  if ( (v63 & 0x8000u) != 0 || (num = v62, (__int16)v63 >= v62) )
                    v64 = nullptr;
                  else
                    v64 = &v27->modelInfo.list[(__int16)v63];
                  v65 = v12->models.list;
                  HIWORD(v114.trackedMemory) = v64->modelIndex.value;
                  v66 = v65[SHIWORD(v114.trackedMemory)];
                  if ( v10 )
                  {
                    v67 = *(_DWORD *)&output[54].value;
                    v68 = 0;
                    if ( v67 <= 0 )
                    {
LABEL_90:
                      LOWORD(v68) = -1;
                    }
                    else
                    {
                      v69 = 0;
                      while ( *(const idDeclMD6 **)(v69 + *(_DWORD *)&output[52].value) != v66 )
                      {
                        ++v68;
                        v69 += 4;
                        if ( v68 >= v67 )
                          goto LABEL_90;
                      }
                    }
                    trackedMemory_high = (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v68;
                  }
                  else
                  {
                    trackedMemory_high = (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)HIWORD(v114.trackedMemory);
                  }
                  v72 = 0;
                  num = v56->modelInfo.num;
                  v71 = num;
                  if ( num <= 0 )
                  {
LABEL_100:
                    idDeclAnimWebNode::AddModelInfo(this: v56, info: v64, modelIndex: trackedMemory_high);
                  }
                  else
                  {
                    while ( 1 )
                    {
                      if ( (v72 & 0x8000u) != 0 || (num = v71, (__int16)v72 >= v71) )
                        v73 = nullptr;
                      else
                        v73 = &v56->modelInfo.list[(__int16)v72];
                      if ( v73->modelIndex.value == (__int16)trackedMemory_high )
                        break;
                      ++v72;
                      num = v71;
                      if ( v72 >= v71 )
                        goto LABEL_100;
                    }
                  }
                  ++v63;
                  num = v27->modelInfo.num;
                  v62 = num;
                }
                while ( v63 < num );
              }
            }
            else
            {
              idLib::Warning(fmt: (const char *)v114.resourceListPtr, v114.subWebs.size);
            }
            idStr::FreeData(this: (idStr *)&v114.scalars.num);
          }
          else
          {
            idList<idStr,5>::Append(this: (idList<idStr,5> *)&v114.md5Checksum, obj: (const idStr *)&v114.subWebs.num);
            idDeclAnimWeb::GetSubWebIndexForName(
              this: (idDeclAnimWeb *)&v114.textSource,
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)output,
              subWebName: v12->subWebs.list[v27->subWebIndex.value].name.str);
            v29 = 0;
            v114.resourceError = (const char *)-1;
            v114.networkID = -1;
            HIWORD(v114.staleCount) = 0;
            if ( v27->states.numStates != 0 )
            {
              p_states = &v27->states;
              do
              {
                v31 = p_states->stateIndex[0].value;
                if ( v31 < 0 || (v32 = 1, v31 >= v12->states.num) )
                  v32 = 0;
                if ( v32 != 0 )
                  v33 = v12->states.list[v31].name.str;
                else
                  v33 = &byte_8200D768;
                idStr::idStr(this: (idStr *)&v114.settings.editPos.y, text: v33);
                idDeclAnimWeb::GetStateIndexForName(
                  this: (idDeclAnimWeb *)((char *)&v114.staleCount + 2),
                  result: output,
                  name: (const char *)LODWORD(v114.settings.editPos.z));
                *(_WORD *)((char *)&v114.resourceError + __ROL4__(HIWORD(v114.staleCount), 1)) = v114.staleCount;
                ++HIWORD(v114.staleCount);
                idStr::FreeData(this: (idStr *)&v114.settings.editPos.y);
                ++v29;
                p_states = (idDeclAnimWeb::stateList_t *)((char *)p_states + 2);
              }
              while ( v29 < v27->states.numStates );
            }
            v34 = (idDeclAnimWebNode *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x40u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
            num = (int)v34;
            textSource_high = HIWORD(v114.textSource);
            if ( v34 != nullptr )
              v36 = idDeclAnimWebNode::idDeclAnimWebNode(
                      this: v34,
                      nodeIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(__int16)*(_DWORD *)&output[30].value,
                      subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v114.textSource),
                      stateIndices: (const idDeclAnimWeb::stateList_t *)&v114.resourceError);
            else
              v36 = nullptr;
            v38 = 0;
            v114.trackedMemory = v27->modelInfo.num;
            trackedMemory = v114.trackedMemory;
            for ( num = (int)v36; v38 < v114.trackedMemory; trackedMemory = v114.trackedMemory )
            {
              if ( (v38 & 0x8000u) != 0 || (v114.trackedMemory = trackedMemory, (__int16)v38 >= trackedMemory) )
                v39 = nullptr;
              else
                v39 = &v27->modelInfo.list[(__int16)v38];
              v41 = v12->models.list;
              HIWORD(v114.trackedMemory) = v39->modelIndex.value;
              v40 = (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)HIWORD(v114.trackedMemory);
              v42 = v41[SHIWORD(v114.trackedMemory)];
              if ( v10 && v38 > 0 )
              {
                v43 = *(_DWORD *)&output[54].value;
                v44 = 0;
                if ( v43 <= 0 )
                {
LABEL_56:
                  LOWORD(v44) = -1;
                }
                else
                {
                  v45 = 0;
                  while ( *(const idDeclMD6 **)(v45 + *(_DWORD *)&output[52].value) != v42 )
                  {
                    ++v44;
                    v45 += 4;
                    if ( v44 >= v43 )
                      goto LABEL_56;
                  }
                }
                v40 = (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v44;
              }
              idDeclAnimWebNode::AddModelInfo(this: v36, info: v39, modelIndex: v40);
              ++v38;
              v114.trackedMemory = v27->modelInfo.num;
            }
            animDelta = v27->animDelta;
            v114.trackedMemory = (int)&v36->settings;
            v36->animDelta = animDelta;
            v36->settings.pos.x = v27->settings.pos.x;
            v36->settings.pos.y = v27->settings.pos.y;
            v36->settings.pos.z = v27->settings.pos.z;
            v36->flags = v27->flags;
            v36->customFlags = v27->customFlags;
            v47 = idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&output[28],
                    obj: (const encounterGroupRole_t *)&num);
            v48 = *(idDeclAnimWeb::idSubWebInfo **)&output[36].value;
            v49 = v47;
            HIWORD(v114.trackedMemory) = v47;
            v50 = 0;
            v51 = (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v48[textSource_high];
            v52 = v51->num;
            if ( v52 <= 0 )
              goto LABEL_63;
            v53 = 0;
            while ( v51->list[v53].value != v49 )
            {
              ++v50;
              ++v53;
              if ( v50 >= v52 )
                goto LABEL_63;
            }
            if ( v50 < 0 )
LABEL_63:
              idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
                this: v51,
                obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v114.trackedMemory);
          }
          idStr::FreeData(this: (idStr *)&v114.subWebs.num);
          ++v25;
          ++v26;
        }
        while ( v25 < v12->nodes.num );
      }
      v11 = ++v9;
      num = mergeDecls->num;
      v8 = (idResourceList *)num;
    }
    while ( v9 < num );
    declSource = v114.declSource;
  }
  v114.resourceListPtr = v8;
  if ( (int)v8 > 0 )
  {
    v74 = 0;
    do
    {
      v75 = 0;
      v76 = mergeDecls->list[v74];
      if ( v76->nodes.num > 0 )
      {
        v77 = 0;
        do
        {
          v78 = 0;
          v79 = v76->nodes.list[v77];
          v114.edgeCache.num = 0;
          HIBYTE(v114.nodeCache.list) = 0;
          *(_DWORD *)&v114.edgeCache.granularity = 20;
          v114.edgeCache.size = (int)&v114.nodeCache;
          idDeclAnimWebNode::GetName(this: v79, web: v76, name: (idStr *)&v114.edgeCache.num);
          idStr::ToLower(this: (idStr *)&v114.edgeCache.num);
          v80 = *(idDeclAnimWebNode **)(4
                                      * (__int16)idList<idStr,5>::FindIndex(
                                                   this: (idList<idStr,5> *)&v114.md5Checksum,
                                                   obj: (const idStr *)&v114.edgeCache.num,
                                                   startIndex: 0)
                                      + *(_DWORD *)&output[28].value);
          if ( v79->edges.num > 0 )
          {
            v81 = 0;
            do
            {
              v82 = v76->edgeCache.list;
              v83 = v76->subWebs.num;
              v84 = v79->edges.list[v81].value;
              v85 = v84;
              v86 = (int)&v76->edges.list[v84];
              HIWORD(v114.__vftable) = v84;
              v87 = *(_WORD *)(v86 + 4);
              if ( v87 < 0 || (v88 = 1, v87 >= v83) )
                v88 = 0;
              if ( v88 != 0 )
                v89 = v76->subWebs.list[v87].name.str;
              else
                v89 = &byte_8200D768;
              v90 = nullptr;
              v91 = v82[v85].destNodeIndex.value;
              if ( v91 != -1 )
                v90 = v76->nodes.list[v91];
              v114.layers.num = (int)&idDeclAnimWebEdge::`vftable';
              p_size = &v114.layers.size;
              v93 = (_DWORD *)(v86 + 4);
              HIWORD(v114.layers.size) = *(_WORD *)(v86 + 4);
              for ( i = 5; i != 0; --i )
                *++p_size = *++v93;
              HIWORD(v114.settings.editPos.x) = *(_WORD *)(v86 + 28);
              idDeclAnimWeb::GetSubWebIndexForName(
                this: (idDeclAnimWeb *)((char *)&v114.name.str + 2),
                result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)output,
                subWebName: v89);
              v95 = (__int16)v114.name.str;
              HIWORD(v114.layers.size) = v114.name.str;
              v114.nextOnHashChain = (idResource *)v82[v85];
              if ( v90 != nullptr )
              {
                v114.models.num = 0;
                v114.models.size = (int)&v114.edges;
                *(_DWORD *)&v114.models.granularity = 20;
                HIBYTE(v114.edges.list) = 0;
                idDeclAnimWebNode::GetName(this: v90, web: v76, name: (idStr *)&v114.models.num);
                idStr::ToLower(this: (idStr *)&v114.models.num);
                nextOnHashChain_high = idList<idStr,5>::FindIndex(
                                         this: (idList<idStr,5> *)&v114.md5Checksum,
                                         obj: (const idStr *)&v114.models.num,
                                         startIndex: 0);
                HIWORD(v114.nextOnHashChain) = nextOnHashChain_high;
                idStr::FreeData(this: (idStr *)&v114.models.num);
              }
              else
              {
                nextOnHashChain_high = HIWORD(v114.nextOnHashChain);
              }
              v97 = 0;
              v98 = 0;
              v114.resourceListPtr = (idResourceList *)v80->edges.num;
              if ( (int)v114.resourceListPtr > 0 )
              {
                v99 = *(idDeclAnimWebEdge **)&output[60].value;
                v100 = v80->edges.list;
                v101 = 0;
                while ( 1 )
                {
                  v102 = v100[v101].value;
                  HIWORD(v114.__vftable) = v102;
                  if ( v99[v102].destSubWebIndex.value == v95 )
                  {
                    HIWORD(v114.__vftable) = v102;
                    if ( *(__int16 *)(4 * v102 + *(_DWORD *)&output[68].value) == nextOnHashChain_high )
                      break;
                  }
                  ++v98;
                  ++v101;
                  if ( v98 >= (int)v114.resourceListPtr )
                    goto LABEL_132;
                }
                v97 = 1;
              }
LABEL_132:
              if ( v97 == 0 )
              {
                idList<idDeclAnimWebEdge,32>::Append(
                  this: (idList<idDeclAnimWebEdge,32> *)&output[60],
                  obj: (const idDeclAnimWebEdge *)&v114.layers.num);
                idList<idDeclAnimWeb::idEdgeCache,32>::Append(
                  this: (idList<idDeclAnimWeb::idEdgeCache,32> *)&output[68],
                  obj: (const idDeclAnimWeb::idEdgeCache *)&v114.nextOnHashChain);
                v103 = v80->edges.num;
                p_edges = (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v80->edges;
                v105 = 0;
                v106 = *(_DWORD *)&output[62].value - 1;
                HIWORD(v114.name.str) = v106;
                if ( v103 <= 0 )
                  goto LABEL_139;
                v107 = v106;
                v108 = 0;
                while ( p_edges->list[v108].value != v107 )
                {
                  ++v105;
                  ++v108;
                  if ( v105 >= v103 )
                    goto LABEL_139;
                }
                if ( v105 < 0 )
LABEL_139:
                  idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
                    this: p_edges,
                    obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v114.name);
              }
              idDeclAnimWebEdge::~idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)&v114.layers.num);
              ++v78;
              ++v81;
            }
            while ( v78 < v79->edges.num );
          }
          idStr::FreeData(this: (idStr *)&v114.edgeCache.num);
          ++v75;
          ++v77;
        }
        while ( v75 < v76->nodes.num );
      }
      ++v5;
      ++v74;
    }
    while ( v5 < mergeDecls->num );
  }
  LODWORD(v109) = (Sys_Microseconds() >> 32) - *(_DWORD *)&v114.nodes.granularity;
  *(_QWORD *)&v114.nodes.granularity = v109;
  idLib::Printf(
    fmt: "Animweb compositing for '%s' took %.4f milliseconds.\n",
    (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v109 * (float)0.001))),
    (float)((float)v109 * (float)0.001));
  if ( LOBYTE(v114.nodes.list) == 0 || LOBYTE(v114.nodes.list) == 2 )
  {
    md5Checksum = (void *)v114.md5Checksum;
    if ( v114.md5Checksum != 0 )
    {
      if ( (int)declSource > 0 )
      {
        v111 = (idStr *)v114.md5Checksum;
        for ( j = declSource; j != nullptr; j = (idDeclSource *)((char *)j - 1) )
          idStr::FreeData(this: v111++);
      }
      idMem::Free(this: (idMem *)v114.nodes.size, ptr: md5Checksum, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$237894
// EA  : 0x82604064
// RVA : 0x00604064
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237894()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 512 + 128));
}


// ========================================================================
// __unwind$237895
// EA  : 0x8260408C
// RVA : 0x0060408C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237895()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 160));
}


// ========================================================================
// __unwind$237896
// EA  : 0x826040B4
// RVA : 0x006040B4
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237896()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 320));
}


// ========================================================================
// __unwind$237897
// EA  : 0x826040DC
// RVA : 0x006040DC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall _unwind_237897(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 512 + 80), tag: a2);
}


// ========================================================================
// __unwind$237898
// EA  : 0x82604104
// RVA : 0x00604104
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237898()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 256));
}


// ========================================================================
// __unwind$237899
// EA  : 0x8260412C
// RVA : 0x0060412C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237899()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 224));
}


// ========================================================================
// __unwind$237900
// EA  : 0x82604154
// RVA : 0x00604154
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237900()
{
  int v0; // r12

  idDeclAnimWebEdge::~idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)(v0 - 512 + 288));
}


// ========================================================================
// __unwind$237901
// EA  : 0x8260417C
// RVA : 0x0060417C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_237901()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 192));
}


// ========================================================================
// ?AddSubWeb@idDeclAnimWeb@@QAA?AV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PBD@Z
// EA  : 0x82604328
// RVA : 0x00604328
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idDeclAnimWeb *__fastcall idDeclAnimWeb::AddSubWeb(
        idDeclAnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *result,
        const char *subWebName)
{
  idDeclAnimWeb::idSubWebInfo *v7; // r3
  __int16 v8; // [sp+50h] [-30h] BYREF

  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v8, result, subWebName);
  if ( v8 < 0 )
  {
    ++*(_DWORD *)&result[112].value;
    v7 = idList<idDeclAnimWeb::idSubWebInfo,32>::Alloc(this: (idList<idDeclAnimWeb::idSubWebInfo,32> *)&result[36]);
    idAtomicString::Set(this: &v7->name, str_: subWebName);
    HIWORD(this->__vftable) = *(_DWORD *)&result[38].value - 1;
    return this;
  }
  else
  {
    HIWORD(this->__vftable) = v8;
    return this;
  }
}


// ========================================================================
// ?AddNode@idDeclAnimWeb@@QAAXPBD0AAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x826043A0
// RVA : 0x006043A0
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::AddNode(
        idDeclAnimWeb *this,
        const char *subWebName,
        const char *stateName,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex)
{
  unsigned __int16 v11; // r11
  idAtomicString *v12; // r3
  int v13; // r10
  __int16 v14; // [sp+50h] [-40h] BYREF
  _BYTE v15[62]; // [sp+52h] [-3Eh] BYREF

  subWebIndex->value = (__int16)HIWORD(idDeclAnimWeb::AddSubWeb(
                                         this: (idDeclAnimWeb *)v15,
                                         result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this,
                                         subWebName)->__vftable);
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v14,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this,
    name: stateName);
  v11 = v14;
  if ( v14 < 0 )
  {
    v12 = idList<idAtomicString,32>::Alloc(this: (idList<idAtomicString,32> *)&this->states);
    idAtomicString::Set(this: v12, str_: stateName);
    v13 = this->states.num - 1;
    ++this->changeId;
    v11 = v13;
  }
  stateIndex->value = v11;
  nodeIndex->value = (__int16)HIWORD(idDeclAnimWeb::AddNode(
                                       this: (idDeclAnimWeb *)v15,
                                       result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this,
                                       subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)subWebIndex->value,
                                       stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v11)->__vftable);
  ++this->changeId;
}


// ========================================================================
// ?AddNode@idDeclAnimWeb@@QAAXPBDABV?$idStaticList@VidStr@@$03@@AAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAVstateList_t@1@@Z
// EA  : 0x82604460
// RVA : 0x00604460
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::AddNode(
        idDeclAnimWeb *this,
        const char *subWebName,
        const idStaticList<idStr,4> *stateNames,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idDeclAnimWeb::stateList_t *stateIndices)
{
  int v11; // r26
  int v12; // r28
  char *data; // r30
  __int16 v14; // r11
  idAtomicString *v15; // r3
  int v16; // r10
  _WORD v17[40]; // [sp+50h] [-50h] BYREF

  v11 = 0;
  subWebIndex->value = (__int16)HIWORD(idDeclAnimWeb::AddSubWeb(
                                         this: (idDeclAnimWeb *)v17,
                                         result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this,
                                         subWebName)->__vftable);
  if ( stateNames->num > 0 )
  {
    v12 = 0;
    do
    {
      if ( stateIndices->numStates >= 4u )
        break;
      data = stateNames->list[v12].data;
      idDeclAnimWeb::GetStateIndexForName(
        this: (idDeclAnimWeb *)v17,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this,
        name: data);
      v14 = v17[0];
      if ( v17[0] < 0 )
      {
        v15 = idList<idAtomicString,32>::Alloc(this: (idList<idAtomicString,32> *)&this->states);
        idAtomicString::Set(this: v15, str_: data);
        v16 = this->states.num - 1;
        ++this->changeId;
        v14 = v16;
      }
      ++v11;
      ++v12;
      *(__int16 *)((char *)&stateIndices->stateIndex[0].value + __ROL4__(stateIndices->numStates++, 1)) = v14;
    }
    while ( v11 < stateNames->num );
  }
  nodeIndex->value = (__int16)HIWORD(idDeclAnimWeb::AddNode(
                                       this: (idDeclAnimWeb *)v17,
                                       result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this,
                                       subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)subWebIndex->value,
                                       stateIndices)->__vftable);
  ++this->changeId;
}


// ========================================================================
// ?Parse@idDeclAnimWeb@@UAAXAAVidParser@@@Z
// EA  : 0x82604578
// RVA : 0x00604578
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void __fastcall idDeclAnimWeb::Parse(idDeclAnimWeb *this, idClientGame *src)
{
  idParser *v4; // r30
  idDeclAnimWeb::subWebBlend_t v5; // r30
  const char *v6; // r11
  idDecl *v7; // r30
  const idDecl *v8; // r3
  idDeclSource *v9; // r3
  const char *FileName; // r3
  char *data; // r10
  int v12; // r11
  const idDecl *v13; // r3
  idAtomicString *v14; // r3
  int i; // r30
  bool v16; // cr58
  bool v17; // r3
  int k; // r11
  int num; // r30
  idParser *v20; // r22
  idDeclAnimWeb::idLayerInfo *v21; // r29
  idParser *v22; // r30
  int v23; // r29
  int v24; // r11
  int v25; // r29
  int v26; // r11
  unsigned __int8 v27; // r5
  char *textSource; // r18
  const char *v29; // r29
  __int16 v30; // r29
  idList<idDeclAnimWeb::idSubWebInfo,32> *p_subWebs; // r30
  int size; // r10
  int v33; // r11
  idDeclAnimWeb::idSubWebInfo *list; // r10
  idAtomicString *v35; // r11
  idDeclAnimWeb::idSubWebInfo *v36; // r30
  idDeclAnimWeb::idSubWebInfo *v37; // r30
  int v38; // r10
  int *j; // r11
  int v40; // r30
  int v41; // r11
  unsigned int v42; // r5
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v43; // r3
  int v44; // r29
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v45; // r30
  int v46; // r11
  int v47; // r7
  int v48; // r8
  int v49; // r10
  idDeclAnimWeb::idNodeCache *v50; // r11
  idDeclAnimWebNode *v51; // r9
  int v52; // r3
  int v53; // r8
  __int16 value; // r5
  idToken v55; // [sp+50h] [-260h] BYREF
  const char *v56; // [sp+98h] [-218h] BYREF
  const char *v57; // [sp+9Ch] [-214h] BYREF
  idDeclAnimWeb v58; // [sp+A0h] [-210h] BYREF

  this->FreeData(this);
  ++this->changeId;
  v58.textLength = (int)idParser::GetFlags(this: src);
  idParser::SetFlags(this: (idParser *)src, flags: v58.textLength | 0x40000);
  v55.len = 0;
  v55.data = v55.baseBuffer;
  v55.allocedAndFlag = 20;
  v55.floatvalue = -3.4028235e38;
  v55.baseBuffer[0] = 0;
  v55.intvalue = 0;
  memset(&v55.whiteSpaceStart_p, 0, 12);
  memset(&v58.resourceListPtr, 0, 12);
  v58.staleCount = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58.resourceListPtr);
  v58.textSource = "props";
  idParser::ExpectTokenString(this: (idParser *)src, string: "props");
  idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: &v55);
  *(_DWORD *)&v58.nodes.granularity = "Unknown token '%s' in 'props' block.";
  v58.declSource = (idDeclSource *)"showAbbreviatedNodeProps";
  *((_DWORD *)&v58.idResource + 8) = "showWeakRefs";
  v58.nodes.list = (idDeclAnimWebNode **)"editorModels";
  v58.md5Checksum = (unsigned int)"Unknown token '%s' in 'models' block.";
  v58.nodes.size = (int)"snapToGrid";
  *(_DWORD *)&v58.programaticallyDefined = "alwaysShowIntraSubwebLinks";
  v58.subWebs.list = (idDeclAnimWeb::idSubWebInfo *)"alwaysShowNodeProps";
  v56 = "showGrid";
  v58.__vftable = (idDeclAnimWeb_vtbl *)"gridSize";
  v57 = "editPos";
LABEL_2:
  v4 = (idParser *)src;
LABEL_3:
  while ( idParser::ReadToken(this: v4, token: &v55) && (v55.type != 5 || v55.subtype != 47) )
  {
    if ( idStr::Cmp(s1: v55.data, s2: v57) != 0 )
    {
      if ( idStr::Cmp(s1: v55.data, s2: (const char *)v58.__vftable) != 0 )
      {
        if ( idStr::Cmp(s1: v55.data, s2: v56) != 0 )
        {
          if ( idStr::Cmp(s1: v55.data, s2: *(const char **)&v58.programaticallyDefined) != 0 )
          {
            if ( idStr::Cmp(s1: v55.data, s2: (const char *)v58.nodes.size) != 0 )
            {
              if ( idStr::Cmp(s1: v55.data, s2: (const char *)v58.subWebs.list) != 0 )
              {
                if ( idStr::Cmp(s1: v55.data, s2: (const char *)v58.declSource) != 0 )
                {
                  if ( idStr::Cmp(s1: v55.data, s2: "showIncomingLinks") != 0 )
                  {
                    if ( idStr::Cmp(s1: v55.data, s2: "defaultBlendOutWindow") != 0 )
                    {
                      if ( idStr::Cmp(s1: v55.data, s2: "defaultBlendDuration") != 0 )
                      {
                        if ( idStr::Cmp(s1: v55.data, s2: "subWebBlend") == 0 )
                        {
                          idParser::ExpectTokenType(this: v4, type: 1, subtype: 0, token: &v55);
                          v5 = SUBWEBBLEND_USE_SOURCE_NODE;
                          this->settings.subWebBlend = SUBWEBBLEND_MAX;
                          while ( v5 < SUBWEBBLEND_MAX )
                          {
                            if ( idStr::Icmp(s1: v55.data, s2: idDeclAnimWeb::subWebBlendNames[v5]) == 0 )
                            {
                              this->settings.subWebBlend = v5;
                              break;
                            }
                            ++v5;
                          }
                          if ( this->settings.subWebBlend == SUBWEBBLEND_MAX )
                            idParser::Error(this: (idParser *)src, str: "Unknown subWebBlend type: '%s'", v55.data);
                          goto LABEL_2;
                        }
                        if ( idStr::Cmp(s1: v55.data, s2: "composite") != 0 )
                        {
                          if ( idStr::Icmp(s1: v55.data, s2: "mergeModels") != 0 )
                          {
                            if ( idStr::Cmp(s1: v55.data, s2: "models") == 0 )
                            {
                              idParser::ExpectTokenType(this: v4, type: 5, subtype: 46, token: &v55);
                              while ( 1 )
                              {
                                if ( !idParser::ReadToken(this: v4, token: &v55) )
                                  goto LABEL_3;
                                if ( v55.type == 5 )
                                {
                                  if ( v55.subtype == 47 )
                                    goto LABEL_3;
LABEL_55:
                                  idParser::Error(this: v4, str: (const char *)v58.md5Checksum, v55.data);
                                }
                                else
                                {
                                  if ( v55.type != 1 )
                                    goto LABEL_55;
                                  data = v55.data;
                                  if ( v55.data != nullptr )
                                  {
                                    v13 = idDeclInfo::FindWithInheritance(
                                            this: &idDeclMD6::resourceList,
                                            name: v55.data,
                                            makeDefault: false);
                                    data = v55.data;
                                    v12 = (int)v13;
                                  }
                                  else
                                  {
                                    v12 = 0;
                                  }
                                  v58.trackedMemory = v12;
                                  if ( v12 != 0 )
                                    idList<idAnimWebBlendTree *,5>::Append(
                                      this: (idList<enum encounterGroupRole_t,5> *)&this->models,
                                      obj: (const encounterGroupRole_t *)&v58.trackedMemory);
                                  else
                                    idParser::Error(this: v4, str: "Could not find model '%s' in 'models' block.", data);
                                }
                              }
                            }
                            if ( idStr::Cmp(s1: v55.data, s2: (const char *)v58.nodes.list) == 0 )
                            {
                              idParser::ExpectTokenType(this: v4, type: 5, subtype: 46, token: &v55);
                              while ( 1 )
                              {
                                if ( !idParser::ReadToken(this: v4, token: &v55) )
                                  goto LABEL_3;
                                if ( v55.type == 5 )
                                {
                                  if ( v55.subtype == 47 )
                                    goto LABEL_3;
LABEL_68:
                                  idParser::Error(
                                    this: v4,
                                    str: "Unknown token '%s' in 'editorModels' block.",
                                    v55.data);
                                }
                                else
                                {
                                  if ( v55.type != 1 )
                                    goto LABEL_68;
                                  v14 = idList<idAtomicString,32>::Alloc(this: &this->editorModels);
                                  idAtomicString::Set(this: v14, str_: v55.data);
                                }
                              }
                            }
                            for ( i = 0; ; ++i )
                            {
                              v16 = i == 6;
                              if ( i >= 6 )
                                break;
                              if ( idStr::Cmp(s1: v55.data, s2: idDeclAnimWeb::nodePropNames[i]) == 0 )
                              {
                                v17 = idParser::ParseBool(this: (idParser *)src);
                                v16 = i == 6;
                                this->settings.nodeProps[i] = v17;
                                break;
                              }
                            }
                            if ( v16 )
                            {
                              if ( idStr::Cmp(s1: v55.data, s2: *((const char **)&v58.idResource + 8)) != 0 )
                                idParser::Error(
                                  this: (idParser *)src,
                                  str: *(const char **)&v58.nodes.granularity,
                                  v55.data);
                              else
                                idParser::ParseBool(this: (idParser *)src);
                            }
                            goto LABEL_2;
                          }
                          this->settings.mergeModels = idParser::ParseBool(this: v4);
                        }
                        else
                        {
                          idParser::ExpectTokenType(this: v4, type: 5, subtype: 46, token: &v55);
                          while ( idParser::ReadToken(this: v4, token: &v55) )
                          {
                            if ( v55.type == 5 )
                            {
                              if ( v55.subtype == 47 )
                                break;
                            }
                            else
                            {
                              idStr::idStr(this: (idStr *)&v58.scalars.size, text: v55.data);
                              v6 = *(const char **)&v58.scalars.granularity;
                              if ( *(_DWORD *)&v58.scalars.granularity != 0 )
                              {
                                v8 = idDeclInfo::FindWithInheritance(
                                       this: &idDeclAnimWeb::resourceList,
                                       name: *(const char **)&v58.scalars.granularity,
                                       makeDefault: false);
                                v6 = *(const char **)&v58.scalars.granularity;
                                v7 = (idDecl *)v8;
                              }
                              else
                              {
                                v7 = nullptr;
                              }
                              v58.trackedMemory = (int)v7;
                              if ( v7 != nullptr )
                              {
                                idList<idAnimWebBlendTree *,5>::Append(
                                  this: (idList<enum encounterGroupRole_t,5> *)&v58.resourceListPtr,
                                  obj: (const encounterGroupRole_t *)&v58.trackedMemory);
                                if ( function_t::Name(this: v7) != nullptr )
                                {
                                  v9 = function_t::Name(this: v7);
                                  FileName = idDeclSource::GetFileName(this: v9);
                                  declManager->AddDependency(this: declManager, a2: (idDecl *)this, a3: FileName);
                                }
                              }
                              else
                              {
                                idParser::Error(this: (idParser *)src, str: "Could not find animweb decl: '%s'", v6);
                              }
                              idStr::FreeData(this: (idStr *)&v58.scalars.size);
                              v4 = (idParser *)src;
                            }
                          }
                          this->settings.isComposite = true;
                        }
                      }
                      else
                      {
                        this->settings.defaultBlendDuration = idParser::ParseInt(this: v4);
                      }
                    }
                    else
                    {
                      this->settings.defaultBlendOutWindow = idParser::ParseInt(this: v4);
                    }
                  }
                  else
                  {
                    this->settings.showIncomingLinks = idParser::ParseBool(this: v4);
                  }
                }
                else
                {
                  this->settings.showAbbreviatedNodeProps = idParser::ParseBool(this: v4);
                }
              }
              else
              {
                this->settings.alwaysShowNodeProps = idParser::ParseBool(this: v4);
              }
            }
            else
            {
              this->settings.snapToGrid = idParser::ParseBool(this: v4);
            }
          }
          else
          {
            this->settings.alwaysShowIntraSubwebLinks = idParser::ParseBool(this: v4);
          }
        }
        else
        {
          this->settings.showGrid = idParser::ParseBool(this: v4);
        }
      }
      else
      {
        this->settings.gridSize = idParser::ParseInt(this: v4);
      }
    }
    else
    {
      idParser::Parse1DMatrix(this: v4, x: 3, m: &this->settings.editPos.x);
    }
  }
  if ( this->settings.isComposite )
  {
    idDeclAnimWeb::Composite(
      mergeDecls: (idList<idDeclAnimWeb const *,5> *)&v58.resourceListPtr,
      output: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this);
    goto LABEL_82;
  }
  if ( idParser::CheckTokenString(this: v4, string: "layers") != 0 )
  {
    idParser::ExpectTokenType(this: v4, type: 5, subtype: 46, token: &v55);
    while ( 1 )
    {
LABEL_90:
      v4 = (idParser *)src;
      if ( !idParser::ReadToken(this: (idParser *)src, token: &v55) || v55.type == 5 && v55.subtype == 47 )
        goto LABEL_110;
      if ( idStr::Cmp(s1: v55.data, s2: "layer") == 0 )
        break;
      idParser::Error(this: (idParser *)src, str: "Unknown token '%s' in 'layers' block.", v55.data);
    }
    idParser::ExpectTokenType(this: (idParser *)src, type: 1, subtype: 0, token: &v55);
    num = this->layers.num;
    idList<idDeclAnimWeb::idLayerInfo,32>::Alloc(this: &this->layers);
    idAtomicString::Set(this: &this->layers.list[num].name, str_: v55.data);
    v20 = (idParser *)src;
    idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: &v55);
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_95:
        if ( !idParser::ReadToken(this: v20, token: &v55) || v55.type == 5 && v55.subtype == 47 )
          goto LABEL_90;
        if ( idStr::Cmp(s1: v55.data, s2: "visible") != 0 )
          break;
        v20 = (idParser *)src;
        v21 = &this->layers.list[num];
        v21->isVisible = idParser::ParseBool(this: (idParser *)src);
      }
      v20 = (idParser *)src;
      if ( idStr::Cmp(s1: v55.data, s2: "subwebs") == 0 )
        break;
      idParser::Error(this: (idParser *)src, str: "Unknown token '%s' in 'layer' block.", v55.data);
    }
    idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: &v55);
    while ( 1 )
    {
LABEL_102:
      if ( !idParser::ReadToken(this: (idParser *)src, token: &v55) )
        goto LABEL_95;
      if ( v55.type == 5 )
        break;
      if ( v55.type != 1 )
        goto LABEL_105;
      idAtomicString::Set(this: (idAtomicString *)&v58.nodes.num, str_: v55.data);
      idList<idAtomicString,109>::Append(
        this: &this->layers.list[num].subWebsOnLayer,
        obj: (const idAtomicString *)&v58.nodes.num);
    }
    if ( v55.subtype == 47 )
      goto LABEL_95;
LABEL_105:
    idParser::Error(this: (idParser *)src, str: "Unknown token '%s' in layer 'subwebs' block.", v55.data);
    goto LABEL_102;
  }
LABEL_110:
  idParser::ExpectTokenString(this: v4, string: "states");
  idParser::ExpectTokenType(this: v4, type: 5, subtype: 46, token: &v55);
  while ( 1 )
  {
    v22 = (idParser *)src;
    if ( !idParser::ReadToken(this: (idParser *)src, token: &v55) || v55.type == 5 && v55.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v55.data, s2: "state") != 0 )
    {
      idParser::Error(this: (idParser *)src, str: "Unknown token '%s' in 'states' block.", v55.data);
    }
    else
    {
      idParser::ExpectTokenType(this: (idParser *)src, type: 1, subtype: 0, token: &v55);
      v23 = this->states.num;
      idList<idAtomicString,109>::PreAllocateWithGranularity(
        this: (idList<idAtomicString,32> *)&this->states,
        newSize: v23 + 1);
      v24 = this->states.num;
      if ( v24 < this->states.size )
        this->states.num = v24 + 1;
      idAtomicString::Set(this: &this->states.list[v23].name, str_: v55.data);
      idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: &v55);
      while ( idParser::ReadToken(this: (idParser *)src, token: &v55) && (v55.type != 5 || v55.subtype != 47) )
      {
        if ( idStr::Cmp(s1: v55.data, s2: "destination") != 0 )
          idParser::Error(this: (idParser *)src, str: "Unknown token '%s' in 'state' block.", v55.data);
      }
    }
  }
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "scalars") != 0 )
  {
    idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: &v55);
    while ( idParser::ReadToken(this: v22, token: &v55) )
    {
      if ( v55.type == 5 )
      {
        if ( v55.subtype == 47 )
          break;
LABEL_129:
        idParser::Error(this: v22, str: "'%s' is not a valid scalar name.", v55.data);
      }
      else
      {
        if ( v55.type != 4 )
          goto LABEL_129;
        v25 = this->scalars.num;
        idList<idAnimWebScalar,5>::PreAllocateWithGranularity(
          this: (idList<idAnimWebScalar,5> *)&this->scalars,
          newSize: v25 + 1);
        v26 = this->scalars.num;
        if ( v26 < this->scalars.size )
          this->scalars.num = v26 + 1;
        v27 = idParser::ParseInt(this: (idParser *)src) != 0;
        idAnimWebScalar::Init(this: &this->scalars.list[v25], name_: v55.data, flags_: v27, scalar: nullptr);
        v22 = (idParser *)src;
      }
    }
  }
  idParser::ExpectTokenString(this: v22, string: "subWebs");
  idParser::ExpectTokenType(this: v22, type: 5, subtype: 46, token: &v55);
  textSource = v58.textSource;
  while ( idParser::ReadToken(this: v22, token: &v55) && (v55.type != 5 || v55.subtype != 47) )
  {
    if ( idStr::Cmp(s1: v55.data, s2: "subWeb") != 0 )
    {
      idParser::Error(this: v22, str: "Unknown token '%s' in 'subWebs' block.", v55.data);
    }
    else
    {
      *(float *)&v58.nodeCache.list = -3.4028235e38;
      v58.states.size = 0;
      *(_DWORD *)&v58.states.granularity = &v58.models.num;
      v58.models.list = (const idDeclMD6 **)20;
      HIBYTE(v58.models.num) = 0;
      *(_DWORD *)&v58.edgeCache.granularity = 0;
      memset(&v58.nodeCache.num, 0, 12);
      idParser::ExpectTokenType(this: v22, type: 1, subtype: 0, token: (idToken *)&v58.states.size);
      v29 = *(const char **)&v58.states.granularity;
      idDeclAnimWeb::GetSubWebIndexForName(
        this: &v58,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this,
        subWebName: *(const char **)&v58.states.granularity);
      if ( SHIWORD(v58.__vftable) < 0 )
      {
        p_subWebs = &this->subWebs;
        ++this->changeId;
        idList<idDeclAnimWeb::idSubWebInfo,32>::PreAllocateWithGranularity(
          this: &this->subWebs,
          newSize: this->subWebs.num + 1);
        size = this->subWebs.size;
        v33 = this->subWebs.num;
        if ( v33 >= size )
        {
          v35 = (idAtomicString *)&p_subWebs->list[size - 1];
        }
        else
        {
          list = p_subWebs->list;
          this->subWebs.num = v33 + 1;
          v35 = (idAtomicString *)&list[v33];
        }
        idAtomicString::Set(this: v35 + 4, str_: v29);
        v22 = (idParser *)src;
        v30 = HIWORD(this->subWebs.num) - 1;
      }
      else
      {
        v30 = HIWORD(v58.__vftable);
      }
      idParser::ExpectTokenType(this: v22, type: 5, subtype: 46, token: &v55);
      while ( idParser::ReadToken(this: v22, token: &v55) && (v55.type != 5 || v55.subtype != 47) )
      {
        if ( idStr::Cmp(s1: v55.data, s2: textSource) != 0 )
        {
          if ( idStr::Cmp(s1: v55.data, s2: "node") != 0 )
          {
            idParser::Error(this: v22, str: "Unknown token '%s' in 'subWeb' block.", v55.data);
          }
          else
          {
            idStaticList<idStr,4>::idStaticList<idStr,4>(this: (idStaticList<idStr,4> *)&v58.layers.size);
            while ( idParser::ReadToken(this: v22, token: &v55) )
            {
              if ( *(int *)&v58.layers.granularity >= 4 )
                idParser::Error(this: v22, str: "Node contains too many states.");
              if ( v55.type == 5 && v55.subtype == 46 )
                break;
              idList<idStr,5>::Append(this: (idList<idStr,5> *)&v58.layers.size, obj: &v55);
            }
            HIWORD(v56) = -1;
            v38 = 4;
            HIWORD(v57) = -1;
            for ( j = &v58.subWebs.size; --v38 >= 0; j = (int *)((char *)j + 2) )
              *(_WORD *)j = -1;
            HIWORD(v58.states.list) = 0;
            idDeclAnimWeb::AddNode(
              this,
              subWebName: *(const char **)&v58.states.granularity,
              stateNames: (const idStaticList<idStr,4> *)&v58.layers.size,
              nodeIndex: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)&v56,
              subWebIndex: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&v57,
              stateIndices: (idDeclAnimWeb::stateList_t *)&v58.subWebs.size);
            idDeclAnimWebNode::Parse(this: this->nodes.list[SHIWORD(v56)], decl: this, src: v22);
            idStaticList<idStr,4>::~idStaticList<idStr,4>(this: (idStaticList<idStr,4> *)&v58.layers.size);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: v22, type: 5, subtype: 46, token: &v55);
          while ( idParser::ReadToken(this: v22, token: &v55) && (v55.type != 5 || v55.subtype != 47) )
          {
            if ( idStr::Cmp(s1: v55.data, s2: "color") != 0 )
            {
              if ( idStr::Cmp(s1: v55.data, s2: "hub") != 0 )
              {
                if ( idStr::Cmp(s1: v55.data, s2: "visible") != 0 )
                {
                  idParser::Error(this: v22, str: "Unexpected token '%s' in subWeb 'props' block.", v55.data);
                }
                else
                {
                  v37 = &this->subWebs.list[v30];
                  v37->isVisible = idParser::ParseBool(this: (idParser *)src);
                  v22 = (idParser *)src;
                }
              }
              else
              {
                v36 = &this->subWebs.list[v30];
                v36->isHub = idParser::ParseBool(this: (idParser *)src);
                v22 = (idParser *)src;
              }
            }
            else
            {
              idParser::Parse1DMatrix(this: v22, x: 4, m: &this->subWebs.list[v30].color.r);
            }
          }
        }
      }
      idStr::FreeData(this: (idStr *)&v58.states.size);
    }
  }
LABEL_82:
  if ( (LOBYTE(v58.staleCount) == 0 || LOBYTE(v58.staleCount) == 2) && v58.resourceListPtr != nullptr )
  {
    for ( k = 0; k < v58.networkID; ++k )
      ;
    idMem::Free(this: &mem, ptr: v58.resourceListPtr, align: ALIGN_16);
  }
  idStr::FreeData(this: &v55);
  if ( this->expandSubWebLinks )
  {
    v40 = 0;
    if ( this->nodes.num > 0 )
    {
      v41 = 0;
      do
      {
        idDeclAnimWebNode::CreateSubWebEdges(this: this->nodes.list[v41], decl: this);
        v41 = ++v40;
      }
      while ( v40 < this->nodes.num );
    }
  }
  v42 = 2 * this->edgeCache.num;
  this->edgeIndexCacheSize = v42;
  v43 = (idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *)idMem::AllocWithLocation(
                                                                   this: &mem,
                                                                   location: "w:\\tech5\\engine\\decls\\AnimWebs\\DeclAnimWeb.cpp(4"
                                                                   "62) : TAG_DECL_ANIMWEB",
                                                                   size: v42,
                                                                   tag: TAG_DECL_ANIMWEB,
                                                                   zeroBuffer: false,
                                                                   align: ALIGN_16,
                                                                   heap: HEAP_DEFAULTHEAP);
  v44 = this->nodes.num;
  this->edgeIndexCache = v43;
  v45 = v43;
  if ( v44 <= this->nodeCache.size
    || (unsigned __int8)idList<idDeclAnimWeb::idNodeCache,32>::Resize(this: &this->nodeCache, newsize: v44) != 0 )
  {
    v46 = this->nodeCache.size;
    if ( v44 < v46 )
      v46 = v44;
    this->nodeCache.num = v46;
  }
  v47 = 0;
  if ( this->nodes.num > 0 )
  {
    v48 = 0;
    do
    {
      v49 = 0;
      v50 = &this->nodeCache.list[v47];
      v51 = this->nodes.list[v48];
      v52 = (unsigned __int16)v51->edges.num;
      v50->numEdges = v51->edges.num;
      v50->edgeIndexOffset = v45 - this->edgeIndexCache;
      v50->flags = v51->flags;
      if ( v52 != 0 )
      {
        v53 = 0;
        do
        {
          ++v49;
          value = v51->edges.list[v53].value;
          v53 = v49;
          v45->value = value;
          ++v45;
        }
        while ( v49 < v50->numEdges );
      }
      v48 = ++v47;
    }
    while ( v47 < this->nodes.num );
  }
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->nodes,
    newsize: this->nodes.num);
  idList<idDeclAnimWeb::idLayerInfo,32>::Resize(this: &this->layers, newsize: this->layers.num);
  idList<idDeclAnimWeb::idSubWebInfo,32>::Resize(this: &this->subWebs, newsize: this->subWebs.num);
  idList<idDeclAnimWeb::idStateInfo,32>::Resize(
    this: (idList<idAtomicString,5> *)&this->states,
    newsize: this->states.num);
  idList<idDeclAnimWebEdge,32>::Resize(this: &this->edges, newsize: this->edges.num);
  idList<idDeclAnimWeb::idEdgeCache,32>::Resize(this: &this->edgeCache, newsize: this->edgeCache.num);
  idList<idDeclAnimWeb::idNodeCache,32>::Resize(this: &this->nodeCache, newsize: this->nodeCache.num);
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->models,
    newsize: this->models.num);
  idList<idDeclAnimWeb::idStateInfo,32>::Resize(
    this: (idList<idAtomicString,5> *)&this->editorModels,
    newsize: this->editorModels.num);
  idParser::SetFlags(this: (idParser *)src, flags: v58.textLength);
}


// ========================================================================
// $M240285
// EA  : 0x826059AC
// RVA : 0x006059AC
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void *_M240285()
{
  idLib::Warning(fmt: "%s", idException::error);
  return &_LN162;
}


// ========================================================================
// __unwind$239321
// EA  : 0x826059E4
// RVA : 0x006059E4
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_239321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 80));
}


// ========================================================================
// __unwind$239322
// EA  : 0x82605A0C
// RVA : 0x00605A0C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_239322()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 688 + 176));
}


// ========================================================================
// __unwind$239323
// EA  : 0x82605A34
// RVA : 0x00605A34
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_239323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 336));
}


// ========================================================================
// __unwind$239324
// EA  : 0x82605A5C
// RVA : 0x00605A5C
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_239324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 256));
}


// ========================================================================
// __unwind$239325
// EA  : 0x82605A84
// RVA : 0x00605A84
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

void _unwind_239325()
{
  int v0; // r12

  idStaticList<idStr,4>::~idStaticList<idStr,4>(this: (idStaticList<idStr,4> *)(v0 - 688 + 368));
}


// ========================================================================
// `dynamic initializer for 'rewriteAnimWebs_v''
// EA  : 0x83336538
// RVA : 0x01336538
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__rewriteAnimWebs_v__()
{
  return idCommandLink::idCommandLink(
           this: &rewriteAnimWebs_v,
           cmdName: "rewriteAnimWebs",
           function: rewriteAnimWebs_f,
           description: "Loads and resaves all animweb decls",
           argCompletion: nullptr);
}

