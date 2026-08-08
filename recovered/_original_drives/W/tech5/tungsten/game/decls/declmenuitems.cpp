
// ========================================================================
// ??0idDeclMenuItem@@QAA@XZ
// EA  : 0x82BC8360
// RVA : 0x00BC8360
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

idDeclMenuItem *__fastcall idDeclMenuItem::idDeclMenuItem(idDeclMenuItem *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclMenuItem_vtbl *)&idDeclMenuItem::`vftable';
  this->material = nullptr;
  this->title.data = this->title.baseBuffer;
  this->title.len = 0;
  this->title.allocedAndFlag = 20;
  this->title.baseBuffer[0] = 0;
  this->help.allocedAndFlag = 20;
  this->help.data = this->help.baseBuffer;
  this->help.len = 0;
  this->help.baseBuffer[0] = 0;
  this->loadoutSlot = LOADOUT_SLOT_VEHICLE_CLASS;
  this->index = 0;
  return this;
}


// ========================================================================
// ??1idDeclMenuItem@@UAA@XZ
// EA  : 0x82BC83F8
// RVA : 0x00BC83F8
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

void __fastcall idDeclMenuItem::~idDeclMenuItem(idDeclMenuItem *this)
{
  this->__vftable = (idDeclMenuItem_vtbl *)&idDeclMenuItem::`vftable';
  idStr::FreeData(this: &this->help);
  idStr::FreeData(this: &this->title);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$487429_0
// EA  : 0x82BC8454
// RVA : 0x00BC8454
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

void _unwind_487429_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487430
// EA  : 0x82BC847C
// RVA : 0x00BC847C
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

void _unwind_487430()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// ?LoadAllDecls@idDeclMenuItem@@SAXXZ
// EA  : 0x82BC8508
// RVA : 0x00BC8508
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

static void __fastcall idDeclMenuItem::LoadAllDecls()
{
  int v0; // r31
  int num; // r30
  const char *str; // r4
  int v3; // r29
  int size; // r11
  bool v5; // cr56
  int v6; // r31
  int v7; // r30
  const idDeclMenuItem *v8; // r3
  int v9; // r10
  int v10; // r11
  int i; // ctr
  const idDeclMenuItem *v12; // r9

  if ( idDeclMenuItem::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclMenuItem::resourceList.declSources.num;
    do
    {
      str = idDeclMenuItem::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclMenuItem::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v3 = idDeclMenuItem::resourceList.num;
  size = idDeclMenuItem::orderedList.size;
  v5 = idDeclMenuItem::resourceList.num < idDeclMenuItem::orderedList.size;
  if ( idDeclMenuItem::resourceList.num > idDeclMenuItem::orderedList.size )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&idDeclMenuItem::orderedList,
                            newsize: idDeclMenuItem::resourceList.num) == 0 )
      goto LABEL_12;
    size = idDeclMenuItem::orderedList.size;
    v5 = v3 < idDeclMenuItem::orderedList.size;
  }
  if ( v5 )
    idDeclMenuItem::orderedList.num = v3;
  else
    idDeclMenuItem::orderedList.num = size;
LABEL_12:
  v6 = 0;
  if ( v3 > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (const idDeclMenuItem *)idResourceList::Index(this: &idDeclMenuItem::resourceList, index: v6++);
      idDeclMenuItem::orderedList.list[v7++] = v8;
    }
    while ( v6 < v3 );
  }
  v9 = 0;
  if ( v3 > 0 )
  {
    v10 = 0;
    for ( i = v3; i != 0; --i )
    {
      v12 = idDeclMenuItem::orderedList.list[v10++];
      v12->index = v9++;
    }
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// `dynamic initializer for 'idDeclMenuItem::orderedList''
// EA  : 0x833723B0
// RVA : 0x013723B0
// PDB : w:\tech5\tungsten\game\decls\declmenuitems.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclMenuItem::orderedList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclMenuItem::orderedList__);
}

