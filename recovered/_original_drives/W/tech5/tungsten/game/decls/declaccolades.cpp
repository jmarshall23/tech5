
// ========================================================================
// ??0idDeclAccolade@@QAA@XZ
// EA  : 0x82BBADB8
// RVA : 0x00BBADB8
// PDB : w:\tech5\tungsten\game\decls\declaccolades.cpp
// ========================================================================

idDeclAccolade *__fastcall idDeclAccolade::idDeclAccolade(idDeclAccolade *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclAccolade_vtbl *)&idDeclAccolade::`vftable';
  this->icon = nullptr;
  this->stat = RAGE_STAT_INVALID;
  this->accoladeName.data = this->accoladeName.baseBuffer;
  this->accoladeName.len = 0;
  this->accoladeName.allocedAndFlag = 20;
  this->accoladeName.baseBuffer[0] = 0;
  this->description.allocedAndFlag = 20;
  this->description.data = this->description.baseBuffer;
  this->description.len = 0;
  this->description.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?GetIconName@idDeclAccolade@@QBAPBDXZ
// EA  : 0x82BBAEF8
// RVA : 0x00BBAEF8
// PDB : w:\tech5\tungsten\game\decls\declaccolades.cpp
// ========================================================================

char *__fastcall idDeclAccolade::GetIconName(idDeclAccolade *this)
{
  const idMaterial *icon; // r11
  char *result; // r3

  icon = this->icon;
  result = &byte_8200D768;
  if ( icon != nullptr )
    return (char *)icon->name.str;
  return result;
}


// ========================================================================
// ?LoadAllDecls@idDeclAccolade@@SAXXZ
// EA  : 0x82BBAFE8
// RVA : 0x00BBAFE8
// PDB : w:\tech5\tungsten\game\decls\declaccolades.cpp
// ========================================================================

static void __fastcall idDeclAccolade::LoadAllDecls()
{
  int num; // r29
  idDeclSource **list; // r11
  int v2; // r30
  const char **p_str; // r10
  int v4; // r28
  int size; // r11
  bool v6; // cr56
  int v7; // r30
  int v8; // r29
  const idDeclAccolade *v9; // r3
  const idDeclAccolade **v10; // r4
  int v11; // r10
  int v12; // r11
  int v13; // ctr
  const idDeclAccolade *v14; // r9
  idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr> v15[20]; // [sp+50h] [-50h] BYREF

  if ( idDeclAccolade::resourceList.declSources.num > 0 )
  {
    num = idDeclAccolade::resourceList.declSources.num;
    list = idDeclAccolade::resourceList.declSources.list;
    v2 = 0;
    do
    {
      p_str = &list[v2]->name.str;
      v15[1].__vftable = (idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>_vtbl *)&list[v2];
      if ( *p_str != nullptr )
      {
        idDeclInfo::FindWithInheritance(this: &idDeclAccolade::resourceList, name: *p_str, makeDefault: false);
        list = idDeclAccolade::resourceList.declSources.list;
      }
      --num;
      ++v2;
    }
    while ( num != 0 );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = idDeclAccolade::resourceList.num;
  size = idDeclAccolade::orderedList.size;
  v6 = idDeclAccolade::resourceList.num < idDeclAccolade::orderedList.size;
  if ( idDeclAccolade::resourceList.num > idDeclAccolade::orderedList.size )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&idDeclAccolade::orderedList,
                            newsize: idDeclAccolade::resourceList.num) == 0 )
      goto LABEL_12;
    size = idDeclAccolade::orderedList.size;
    v6 = v4 < idDeclAccolade::orderedList.size;
  }
  if ( v6 )
    idDeclAccolade::orderedList.num = v4;
  else
    idDeclAccolade::orderedList.num = size;
LABEL_12:
  v7 = 0;
  if ( v4 > 0 )
  {
    v8 = 0;
    do
    {
      v9 = (const idDeclAccolade *)idResourceList::Index(this: &idDeclAccolade::resourceList, index: v7++);
      idDeclAccolade::orderedList.list[v8++] = v9;
    }
    while ( v7 < v4 );
  }
  v15[0].__vftable = (idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>_vtbl *)&idSort_DeclAccoladePtr::`vftable';
  v10 = idDeclAccolade::orderedList.list;
  if ( idDeclAccolade::orderedList.list != nullptr )
  {
    idSort_Quick<idDeclSecretType const *,idSort_Quick_SortId<idDeclSecretType const *>>::Sort(
      this: v15,
      base: idDeclAccolade::orderedList.list,
      num: idDeclAccolade::orderedList.num);
    v10 = idDeclAccolade::orderedList.list;
  }
  v11 = 0;
  v15[0].__vftable = (idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>_vtbl *)&idSort<idDeclAccolade const *>::`vftable';
  if ( v4 > 0 )
  {
    v12 = 0;
    v13 = v4;
    while ( 1 )
    {
      v14 = v10[v12++];
      v14->index = v11++;
      if ( --v13 == 0 )
        break;
      v10 = idDeclAccolade::orderedList.list;
    }
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$488068
// EA  : 0x82BBB158
// RVA : 0x00BBB158
// PDB : w:\tech5\tungsten\game\decls\declaccolades.cpp
// ========================================================================

void _unwind_488068()
{
  int v0; // r12

  idSort_DeclAccoladePtr::~idSort_DeclAccoladePtr(this: (idSort_DeclAccoladePtr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'idDeclAccolade::orderedList''
// EA  : 0x83372390
// RVA : 0x01372390
// PDB : w:\tech5\tungsten\game\decls\declaccolades.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclAccolade::orderedList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclAccolade::orderedList__);
}

