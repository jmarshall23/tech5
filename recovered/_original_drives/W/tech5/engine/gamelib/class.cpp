
// ========================================================================
// ?CallSpawnFunc@idClass@@AAAP81@AAXXZPAVidTypeInfo@@@Z
// EA  : 0x826F99B0
// RVA : 0x006F99B0
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void (__fastcall *__fastcall idClass::CallSpawnFunc(idClass *this, idTypeInfo *cls))(idClass *this)
{
  idTypeInfo *super; // r4
  void (__fastcall *result)(idClass *); // r3

  super = cls->super;
  if ( super == nullptr || (result = idClass::CallSpawnFunc(this, cls: super)) != cls->Spawn )
  {
    cls->Spawn(this);
    return cls->Spawn;
  }
  return result;
}


// ========================================================================
// ?DisplayInfo_f@idClass@@SAXABVidCmdArgs@@@Z
// EA  : 0x826F9A18
// RVA : 0x006F9A18
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall idClass::DisplayInfo_f(const idCmdArgs *args)
{
  idLib::Printf(fmt: "Class memory status: %i bytes allocated in %i objects\n", idClass::memused, idClass::numobjects);
}


// ========================================================================
// ?GetClassname@idClass@@QBAPBDXZ
// EA  : 0x826F9A38
// RVA : 0x006F9A38
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

const char *__fastcall idClass::GetClassname(idClass *this)
{
  return *(const char **)this->GetType(this);
}


// ========================================================================
// ?CallSpawn@idClass@@QAAXXZ
// EA  : 0x826F9AB8
// RVA : 0x006F9AB8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall idClass::CallSpawn(idClass *this)
{
  int v2; // r3
  idTypeInfo *v3; // r4
  int v4; // r30

  v2 = this->GetType(this);
  v3 = *(idTypeInfo **)(v2 + 20);
  v4 = v2;
  if ( v3 == nullptr || idClass::CallSpawnFunc(this, cls: v3) != *(void (__fastcall **)(idClass *))(v2 + 12) )
    (*(void (__fastcall **)(idClass *))(v4 + 12))(a1: this);
}


// ========================================================================
// ?ListClasses_f@idClass@@SAXABVidCmdArgs@@@Z
// EA  : 0x826F9B30
// RVA : 0x006F9B30
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall idClass::ListClasses_f(const idCmdArgs *args)
{
  int v1; // r31
  int num; // r4
  int v3; // r30

  idLib::Printf(fmt: "%-24s %-24s %-6s %-6s\n", "Classname", "Superclass", "Type", "Subclasses");
  idLib::Printf(fmt: "----------------------------------------------------------------------\n");
  v1 = 0;
  num = idClass::types.num;
  if ( idClass::types.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(
        fmt: "%-24s %-24s %6d %6d\n",
        idClass::types.list[v3]->classname,
        idClass::types.list[v3]->superclass,
        idClass::types.list[v3]->typeNum,
        idClass::types.list[v3]->lastChild - idClass::types.list[v3]->typeNum);
      num = idClass::types.num;
      ++v1;
      ++v3;
    }
    while ( v1 < idClass::types.num );
  }
  idLib::Printf(fmt: "...%d classes", num);
}


// ========================================================================
// ?GetClass@idClass@@SAPAVidTypeInfo@@PBD@Z
// EA  : 0x826F9BE8
// RVA : 0x006F9BE8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

idTypeInfo *__fastcall idClass::GetClass(const char *name)
{
  idTypeInfo *v2; // r31
  int v4; // r28
  int v5; // r29
  int v6; // r31
  idTypeInfo *v7; // r30
  int v8; // r3

  if ( !idClass::initialized )
  {
    v2 = typelist;
    if ( typelist != nullptr )
    {
      while ( idStr::Cmp(s1: v2->classname, s2: name) != 0 )
      {
        v2 = v2->next;
        if ( v2 == nullptr )
          return nullptr;
      }
      return v2;
    }
    return nullptr;
  }
  v4 = 0;
  v5 = idClass::types.num - 1;
  if ( idClass::types.num - 1 < 0 )
    return nullptr;
  while ( 1 )
  {
    v6 = (v5 + v4) / 2;
    v7 = idClass::types.list[v6];
    v8 = idStr::Cmp(s1: v7->classname, s2: name);
    if ( v8 == 0 )
      break;
    if ( v8 <= 0 )
      v4 = v6 + 1;
    else
      v5 = v6 - 1;
    if ( v4 > v5 )
      return nullptr;
  }
  return v7;
}


// ========================================================================
// ?CreateInstance@idClass@@SAPAV1@PBD@Z
// EA  : 0x826F9CC8
// RVA : 0x006F9CC8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

idClass *__fastcall idClass::CreateInstance(const char *name)
{
  idClass *result; // r3

  result = (idClass *)idClass::GetClass(name);
  if ( result != nullptr )
    return ((idClass *(*)(void))result[2].__vftable)();
  return result;
}


// ========================================================================
// ?Shutdown@idClass@@SAXXZ
// EA  : 0x826F9D10
// RVA : 0x006F9D10
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

static void __fastcall idClass::Shutdown()
{
  idTypeInfo *i; // r11

  for ( i = typelist; i != nullptr; i = i->next )
    ;
  if ( idClass::types.listStatic == 0 || idClass::types.listStatic == 2 )
  {
    if ( idClass::types.list != nullptr )
      idMem::Free(this: &mem, ptr: idClass::types.list, align: ALIGN_16);
    idClass::types.list = nullptr;
    idClass::types.size = 0;
  }
  idClass::types.num = 0;
  if ( idClass::typenums.listStatic != 0 && idClass::typenums.listStatic != 2 )
  {
    idClass::typenums.num = 0;
    idClass::initialized = false;
  }
  else
  {
    if ( idClass::typenums.list != nullptr )
      idMem::Free(this: &mem, ptr: idClass::typenums.list, align: ALIGN_16);
    idClass::typenums.list = nullptr;
    idClass::typenums.size = 0;
    idClass::typenums.num = 0;
    idClass::initialized = false;
  }
}


// ========================================================================
// ?Init@idTypeInfo@@QAAXXZ
// EA  : 0x826FA008
// RVA : 0x006FA008
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall idTypeInfo::Init(idTypeInfo *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  idTypeInfo *super; // r3
  idTypeInfo *v9; // r11
  idHierarchy<idTypeInfo> *p_node; // r4
  idTypeInfo *v11; // r11

  if ( !this->initialized )
  {
    super = this->super;
    if ( super != nullptr && !super->initialized )
      idTypeInfo::Init(this: super);
    v9 = this->super;
    if ( v9 != nullptr )
      p_node = &v9->node;
    else
      p_node = &classHierarchy;
    idHierarchy<idTypeInfo>::ParentTo(this: &this->node, node: p_node, a3, a4, a5, a6, a7);
    v11 = this->super;
    for ( this->node.owner = this; v11 != nullptr; v11 = v11->super )
      ++v11->lastChild;
    this->initialized = true;
  }
}


// ========================================================================
// ??0idTypeInfo@@QAA@PBD0H_NP6APAVidClass@@XZP81@AAXXZ@Z
// EA  : 0x826FA0C0
// RVA : 0x006FA0C0
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

idTypeInfo *__fastcall idTypeInfo::idTypeInfo(
        idTypeInfo *this,
        const char *classname,
        const char *superclass,
        int size,
        bool abstract,
        idClass *(__fastcall *CreateInstance)(),
        void (__fastcall *Spawn)(idClass *this))
{
  idTypeInfo *Class; // r3
  const char ***p_next; // r29
  idTypeInfo *v13; // r28
  int v14; // r3
  idTypeInfo *v15; // r11

  this->node.owner = nullptr;
  this->node.parent = nullptr;
  this->node.sibling = nullptr;
  this->node.child = nullptr;
  this->superclass = superclass;
  this->initialized = false;
  this->classname = classname;
  this->Spawn = Spawn;
  this->CreateInstance = CreateInstance;
  Class = idClass::GetClass(name: superclass);
  this->size = size;
  this->super = Class;
  p_next = (const char ***)&typelist;
  this->isAbstract = abstract;
  this->typeNum = 0;
  this->lastChild = 0;
  v13 = typelist;
  if ( typelist == nullptr )
    goto LABEL_13;
  do
  {
    if ( v13->super == nullptr
      && idStr::Cmp(s1: v13->superclass, s2: this->classname) == 0
      && idStr::Cmp(s1: v13->classname, s2: "idClass") != 0 )
    {
      v13->super = this;
    }
    v13 = v13->next;
  }
  while ( v13 != nullptr );
  if ( typelist == nullptr )
    goto LABEL_13;
  while ( 1 )
  {
    v14 = idStr::Cmp(s1: classname, s2: **p_next);
    v15 = (idTypeInfo *)*p_next;
    if ( v14 < 0 )
      break;
    p_next = (const char ***)&v15->next;
    if ( v15->next == nullptr )
      goto LABEL_12;
  }
  this->next = v15;
  *p_next = &this->classname;
LABEL_12:
  if ( *p_next == nullptr )
  {
LABEL_13:
    *p_next = &this->classname;
    this->next = nullptr;
  }
  return this;
}


// ========================================================================
// __unwind$246315
// EA  : 0x826FA1FC
// RVA : 0x006FA1FC
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall _unwind_246315(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r12

  idHierarchy<idTypeInfo>::~idHierarchy<idTypeInfo>(
    this: (idHierarchy<idTypeInfo> *)(*(_DWORD *)(v7 - 160 + 180) + 44),
    a2,
    a3,
    a4,
    a5,
    a6,
    a7);
}


// ========================================================================
// ??1idTypeInfo@@QAA@XZ
// EA  : 0x826FA228
// RVA : 0x006FA228
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __fastcall idTypeInfo::~idTypeInfo(idTypeInfo *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  idHierarchy<idTypeInfo>::RemoveFromHierarchy(this: &this->node, a2, a3, a4, a5, a6, a7);
}


// ========================================================================
// ?Init@idClass@@SAXXZ
// EA  : 0x826FA230
// RVA : 0x006FA230
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

static void __fastcall idClass::Init()
{
  int v0; // r9
  int v1; // r8
  int v2; // r7
  int v3; // r6
  int v4; // r5
  int v5; // r4
  idTypeInfo *i; // r31
  int v7; // r30
  idHierarchy<idTypeInfo> *v8; // r11
  idHierarchy<idTypeInfo> *child; // r10
  idTypeInfo *j; // r11
  int lastChild; // r9
  idHierarchy<idTypeInfo> *p_node; // r10
  idHierarchy<idTypeInfo> *v13; // r11
  const char *superclass; // r10
  int size; // r11
  bool v16; // cr56
  int v17; // r11
  bool v18; // cr56
  idTypeInfo *v19; // r11
  int v20; // r10

  idLib::Printf(fmt: "Initializing class hierarchy\n");
  if ( idClass::initialized )
  {
    idLib::Printf(fmt: "...already initialized\n");
    return;
  }
  for ( i = typelist; i != nullptr; i = i->next )
    idTypeInfo::Init(this: i, a2: v5, a3: v4, a4: v3, a5: v2, a6: v1, a7: v0);
  v7 = 0;
  v8 = &classHierarchy;
  child = classHierarchy.child;
  if ( classHierarchy.child == nullptr )
  {
    while ( 1 )
    {
      child = v8->sibling;
      if ( child != nullptr )
        break;
      v8 = v8->parent;
      if ( v8 == nullptr )
        goto LABEL_16;
    }
  }
  for ( j = child->owner; j != nullptr; ++v7 )
  {
    lastChild = j->lastChild;
    p_node = &j->node;
    j->typeNum = v7;
    j->lastChild = v7 + lastChild;
    v13 = j->node.child;
    if ( v13 != nullptr )
    {
      j = v13->owner;
    }
    else
    {
      j = (idTypeInfo *)p_node;
      while ( 1 )
      {
        superclass = j->superclass;
        if ( superclass != nullptr )
          break;
        j = (idTypeInfo *)j->classname;
        if ( j == nullptr )
          goto LABEL_15;
      }
      j = *((idTypeInfo **)superclass + 3);
    }
LABEL_15:
    ;
  }
LABEL_16:
  size = idClass::types.size;
  idClass::typeNumBits = 32 - _cntlzw(v7);
  v16 = v7 < idClass::types.size;
  if ( v7 > idClass::types.size )
  {
    if ( !idList<idNavSpline *,5>::Resize(
            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&idClass::types,
            newsize: v7) )
      goto LABEL_23;
    size = idClass::types.size;
    v16 = v7 < idClass::types.size;
  }
  if ( v16 )
    idClass::types.num = v7;
  else
    idClass::types.num = size;
LABEL_23:
  v17 = idClass::typenums.size;
  v18 = v7 < idClass::typenums.size;
  if ( v7 <= idClass::typenums.size )
    goto LABEL_26;
  if ( idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&idClass::typenums,
         newsize: v7) )
  {
    v17 = idClass::typenums.size;
    v18 = v7 < idClass::typenums.size;
LABEL_26:
    if ( v18 )
      idClass::typenums.num = v7;
    else
      idClass::typenums.num = v17;
  }
  v19 = typelist;
  if ( typelist != nullptr )
  {
    v20 = 0;
    do
    {
      idClass::types.list[v20++] = v19;
      idClass::typenums.list[v19->typeNum] = v19;
      v19 = v19->next;
    }
    while ( v19 != nullptr );
  }
  idClass::initialized = true;
}


// ========================================================================
// `dynamic initializer for 'classHierarchy''
// EA  : 0x8333F4A8
// RVA : 0x0133F4A8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__classHierarchy__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__classHierarchy__);
}


// ========================================================================
// `dynamic initializer for 'idClass::types''
// EA  : 0x8333F4B8
// RVA : 0x0133F4B8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idClass::types__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idClass::types__);
}


// ========================================================================
// `dynamic initializer for 'idClass::typenums''
// EA  : 0x8333F4C8
// RVA : 0x0133F4C8
// PDB : w:\tech5\engine\gamelib\class.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idClass::typenums__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idClass::typenums__);
}

