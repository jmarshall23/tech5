
// ========================================================================
// ?Shutdown@idAnimStack@@QAAXXZ
// EA  : 0x826F2718
// RVA : 0x006F2718
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::Shutdown(idAnimStack *this)
{
  this->tree = nullptr;
}


// ========================================================================
// ?Init@idAnimStack@@QAAXPAVidTreeAnimator@@@Z
// EA  : 0x826F2BB8
// RVA : 0x006F2BB8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::Init(idAnimStack *this, idTreeAnimator *treeAnimator)
{
  this->treeAnimator = treeAnimator;
  this->tree = nullptr;
}


// ========================================================================
// ?ShutdownBlendStackIndex@idAnimStack@@AAAXH@Z
// EA  : 0x826F2BC8
// RVA : 0x006F2BC8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::ShutdownBlendStackIndex(idAnimStack *this, int index)
{
  int v2; // r28
  idAnimator_Base *v4; // r31
  idMD6Branch *v5; // r4
  idMD6Branch *v6; // r4

  v2 = index;
  v4 = this->blendStack.list[index];
  if ( v4 != nullptr )
  {
    if ( v4->serializeProps.createdThroughSerialization )
    {
      idAnimator_Base::Shutdown(this: v4, stack: this);
      v5 = v4->serializeProps.serializedTrees[0];
      if ( v5 != nullptr )
      {
        v5->left = nullptr;
        idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v5);
        v4->serializeProps.serializedTrees[0] = nullptr;
      }
      v6 = v4->serializeProps.serializedTrees[1];
      if ( v6 != nullptr )
      {
        v6->left = nullptr;
        idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v6);
        v4->serializeProps.serializedTrees[1] = nullptr;
      }
      ((void (__fastcall *)(idAnimator_Base *, int))v4->dtr_idAnimator_Base)(a1: v4, a2: 1);
    }
    this->blendStack.list[v2] = nullptr;
  }
}


// ========================================================================
// ?RemoveAnimator@idAnimStack@@QAAXPAVidAnimator_Base@@@Z
// EA  : 0x826F2C68
// RVA : 0x006F2C68
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::RemoveAnimator(idAnimStack *this, idAnimator_Base *animator)
{
  int v2; // r11
  int i; // r10
  int num; // r10
  int v5; // r10
  bool v6; // zf
  int v7; // r9
  idAnimator_Base **v8; // r8
  int v9; // r9
  int v10; // r9
  unsigned __int8 *v11; // r9

  v2 = 0;
  if ( this->blendStack.num > 0 )
  {
    for ( i = 0; this->blendStack.list[i] != animator; ++i )
    {
      if ( ++v2 >= this->blendStack.num )
        return;
    }
    if ( v2 >= 0 )
    {
      num = this->blendStack.num;
      if ( v2 < num )
      {
        this->blendStack.num = num - 1;
        v6 = v2 >= num - 1;
        v5 = v2;
        if ( !v6 )
        {
          v7 = v2;
          do
          {
            ++v5;
            v8 = &this->blendStack.list[v7++];
            *v8 = v8[1];
          }
          while ( v5 < this->blendStack.num );
        }
      }
    }
    if ( v2 >= 0 )
    {
      v9 = this->flags.num;
      if ( v2 < v9 )
      {
        v10 = v9 - 1;
        for ( this->flags.num = v10; v2 < this->flags.num; *v11 = v11[1] )
          v11 = &this->flags.list[v2++];
      }
    }
    this->tree = nullptr;
  }
}


// ========================================================================
// ?GetAnimator@idAnimStack@@QAAPAVidAnimator_Base@@PBD@Z
// EA  : 0x826F2D50
// RVA : 0x006F2D50
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

idAnimator_Base *__fastcall idAnimStack::GetAnimator(idAnimStack *this, const char *name)
{
  int v4; // r31

  v4 = 0;
  if ( this->blendStack.num <= 0 )
    return nullptr;
  while ( idStr::Icmp(s1: "<unknown>", s2: name) != 0 )
  {
    if ( ++v4 >= this->blendStack.num )
      return nullptr;
  }
  return this->blendStack.list[v4];
}


// ========================================================================
// ?GetAnimatorIndex@idAnimStack@@QBAHPBVidAnimator_Base@@@Z
// EA  : 0x826F2DC0
// RVA : 0x006F2DC0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

int __fastcall idAnimStack::GetAnimatorIndex(idAnimStack *this, const idAnimator_Base *animator)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->blendStack.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->blendStack.list[i] != animator; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?GetAnimatorByIndex@idAnimStack@@QBAPAVidAnimator_Base@@H@Z
// EA  : 0x826F2E08
// RVA : 0x006F2E08
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

idAnimator_Base *__fastcall idAnimStack::GetAnimatorByIndex(idAnimStack *this, int index)
{
  return this->blendStack.list[index];
}


// ========================================================================
// ?GetAnimatorBySerializeType@idAnimStack@@QAAPAVidAnimator_Base@@W4serializeType_t@@@Z
// EA  : 0x826F2E78
// RVA : 0x006F2E78
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

idAnimator_Base *__fastcall idAnimStack::GetAnimatorBySerializeType(idAnimStack *this, serializeType_t type_)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->blendStack.num <= 0 )
    return nullptr;
  for ( i = 0; this->blendStack.list[i]->GetSerializeType(this: this->blendStack.list[i]) != type_; ++i )
  {
    if ( ++v4 >= this->blendStack.num )
      return nullptr;
  }
  return this->blendStack.list[v4];
}


// ========================================================================
// ?Pause@idAnimStack@@QAAXV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826F2EF8
// RVA : 0x006F2EF8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::Pause(idAnimStack *this, const idTypesafeNumber<int,enum gameTimeUnique_t> *curTime)
{
  int v4; // r29
  int v5; // r30
  idAnimator_Base **list; // r10
  idTypesafeNumber<int,enum gameTimeUnique_t> v7; // [sp+50h] [-30h] BYREF

  if ( this->pauseTime.value < 0 )
    this->pauseTime = (idTypesafeNumber<int,enum gameTimeUnique_t>)curTime->value;
  v4 = 0;
  if ( this->blendStack.num > 0 )
  {
    v5 = 0;
    do
    {
      list = this->blendStack.list;
      v7.value = curTime->value;
      idAnimator_Base::Pause(this: list[v5], stack: this, curTime: &v7);
      ++v4;
      ++v5;
    }
    while ( v4 < this->blendStack.num );
  }
}


// ========================================================================
// ?ClearAnimatorFlag@idAnimStack@@QAAXPBVidAnimator_Base@@W4animatorFlag_t@1@@Z
// EA  : 0x826F2F70
// RVA : 0x006F2F70
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::ClearAnimatorFlag(
        idAnimStack *this,
        const idAnimator_Base *animator,
        const idAnimStack::animatorFlag_t flag)
{
  int num; // r9
  int v4; // r11
  int i; // r10

  num = this->blendStack.num;
  v4 = 0;
  if ( num > 0 )
  {
    for ( i = 0; this->blendStack.list[i] != animator; ++i )
    {
      if ( ++v4 >= num )
        return;
    }
    this->flags.list[v4] &= ~(_BYTE)flag;
  }
}


// ========================================================================
// ?SetAnimatorFlag@idAnimStack@@QAAXPBVidAnimator_Base@@W4animatorFlag_t@1@@Z
// EA  : 0x826F2FC0
// RVA : 0x006F2FC0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::SetAnimatorFlag(
        idAnimStack *this,
        const idAnimator_Base *animator,
        const idAnimStack::animatorFlag_t flag)
{
  int num; // r9
  int v4; // r11
  int i; // r10

  num = this->blendStack.num;
  v4 = 0;
  if ( num > 0 )
  {
    for ( i = 0; this->blendStack.list[i] != animator; ++i )
    {
      if ( ++v4 >= num )
        return;
    }
    this->flags.list[v4] |= flag;
  }
}


// ========================================================================
// ?IsAnimatorFlagSet@idAnimStack@@QBA_NPBVidAnimator_Base@@W4animatorFlag_t@1@@Z
// EA  : 0x826F3010
// RVA : 0x006F3010
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

BOOL __fastcall idAnimStack::IsAnimatorFlagSet(
        idAnimStack *this,
        const idAnimator_Base *animator,
        const idAnimStack::animatorFlag_t flag)
{
  int num; // r9
  int v4; // r10
  int i; // r11

  num = this->blendStack.num;
  v4 = 0;
  if ( num <= 0 )
    return false;
  for ( i = 0; this->blendStack.list[i] != animator; ++i )
  {
    if ( ++v4 >= num )
      return false;
  }
  return (unsigned __int8)(this->flags.list[v4] & flag) != 0;
}


// ========================================================================
// ?FreeSerializedAnimators@idAnimStack@@QAAXXZ
// EA  : 0x826F3290
// RVA : 0x006F3290
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::FreeSerializedAnimators(idAnimStack *this)
{
  int v2; // r27
  int v3; // r29
  idAnimator_Base *v4; // r30
  idMD6Branch *v5; // r4
  idAnimator_Base *v6; // r30
  idMD6Branch *v7; // r4
  idAnimator_Base *v8; // r3
  idAnimator_Base **list; // r4
  unsigned __int8 *v10; // r4

  if ( this->createdFromSnapshot )
  {
    v2 = 0;
    if ( this->blendStack.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = this->blendStack.list[v3];
        v5 = v4->serializeProps.serializedTrees[0];
        if ( v5 != nullptr )
        {
          v5->left = nullptr;
          idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v5);
          v4->serializeProps.serializedTrees[0] = nullptr;
        }
        v6 = this->blendStack.list[v3];
        v7 = v6->serializeProps.serializedTrees[1];
        if ( v7 != nullptr )
        {
          v7->left = nullptr;
          idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v7);
          v6->serializeProps.serializedTrees[1] = nullptr;
        }
        v8 = this->blendStack.list[v3];
        if ( v8 != nullptr )
          ((void (__fastcall *)(idAnimator_Base *, int))v8->dtr_idAnimator_Base)(a1: v8, a2: 1);
        ++v2;
        ++v3;
      }
      while ( v2 < this->blendStack.num );
    }
    if ( this->blendStack.listStatic == 0 || this->blendStack.listStatic == 2 )
    {
      list = this->blendStack.list;
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      this->blendStack.list = nullptr;
      this->blendStack.size = 0;
    }
    this->blendStack.num = 0;
    if ( this->flags.listStatic == 0 || this->flags.listStatic == 2 )
    {
      v10 = this->flags.list;
      if ( v10 != nullptr )
        idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
      this->flags.list = nullptr;
      this->flags.size = 0;
    }
    this->flags.num = 0;
  }
}


// ========================================================================
// ?Unpause@idAnimStack@@QAAXV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826F33C8
// RVA : 0x006F33C8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::Unpause(idAnimStack *this, const idTypesafeNumber<int,enum gameTimeUnique_t> *curTime)
{
  int value; // r10
  idMD6Node *tree; // r11
  int v6; // r6
  int v7; // r7
  idMD6Node **v8; // r9
  idMD6Node *v9; // r8
  unsigned int v10; // r10
  unsigned int v11; // r11
  int v12; // r8
  idMD6Node *v13; // r11
  int type; // r10
  char v15; // r10
  bool v16; // zf
  unsigned __int8 *v17; // r10
  unsigned __int8 *v18; // r11
  int v19; // r30
  int v20; // r31
  idAnimator_Base **list; // r10
  idTypesafeNumber<int,enum gameTimeUnique_t> v22; // [sp+50h] [-C0h] BYREF
  idMD6Node *v23; // [sp+60h] [-B0h] BYREF

  value = this->pauseTime.value;
  if ( value >= 0 )
  {
    tree = this->tree;
    v6 = curTime->value - value;
    this->pauseTime.value = -1;
    if ( tree != nullptr )
    {
      v7 = 0;
      v23 = tree;
      v8 = &v23;
      do
      {
        v9 = *v8;
        if ( (*v8)->type == 6 )
        {
          v10 = *(_DWORD *)&v9[8].type;
          if ( v10 != 0 )
          {
            v11 = *(unsigned __int16 *)&v9[88].type;
            v12 = *(_DWORD *)&v9[4].type;
            if ( *(_DWORD *)(((4 * (((__PAIR64__(v10 >> 31, v11) - v10) >> 32) & v11)) & 0x3FFFC) + v12) != 0 )
              *v8 = *(idMD6Node **)(((4 * (((__PAIR64__(v10 >> 31, v11) - __PAIR64__(v11 >> 31, v10)) >> 32) & v11))
                                   & 0x3FFFC)
                                  + v12);
          }
        }
        v13 = *v8;
        type = (*v8)->type;
        if ( (*v8)->type == 0 || type == 3 || type == 4 || (v16 = type != 5, v15 = 0, !v16) )
          v15 = 1;
        --v7;
        --v8;
        if ( v15 != 0 )
        {
          v17 = *(unsigned __int8 **)&v13[4].type;
          if ( v17 != nullptr )
          {
            ++v7;
            *++v8 = (idMD6Node *)v17;
          }
          v18 = *(unsigned __int8 **)&v13[8].type;
          if ( v18 != nullptr )
          {
            ++v7;
            *++v8 = (idMD6Node *)v18;
          }
        }
        else if ( v13->type == 2 )
        {
          *(_DWORD *)&v13[12].type += v6;
        }
      }
      while ( v7 >= 0 );
    }
    v19 = 0;
    if ( this->blendStack.num > 0 )
    {
      v20 = 0;
      do
      {
        list = this->blendStack.list;
        v22.value = curTime->value;
        idAnimator_Base::Unpause(this: list[v20], stack: this, curTime: &v22);
        ++v19;
        ++v20;
      }
      while ( v19 < this->blendStack.num );
    }
  }
}


// ========================================================================
// ??0idAnimStack@@QAA@XZ
// EA  : 0x826F3998
// RVA : 0x006F3998
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

idAnimStack *__fastcall idAnimStack::idAnimStack(idAnimStack *this)
{
  int v2; // ctr
  __int16 *p_granularity; // r10
  int v4; // ctr
  __int16 *v5; // r10
  bool *p_skipSerialization; // r11
  int i; // ctr

  this->treeAnimator = nullptr;
  this->__vftable = (idAnimStack_vtbl *)&idAnimStack::`vftable';
  idMD6BlockAlloc::idMD6BlockAlloc(this: &this->md6Allocator);
  this->blendStack.list = nullptr;
  this->blendStack.granularity = 0;
  this->blendStack.listStatic = 0;
  this->blendStack.size = 0;
  this->blendStack.num = 0;
  this->blendStack.memTag = 25;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->blendStack);
  this->flags.list = nullptr;
  this->flags.granularity = 0;
  this->flags.listStatic = 0;
  this->flags.size = 0;
  this->flags.num = 0;
  this->flags.memTag = 25;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flags);
  this->tree = nullptr;
  this->pauseTime.value = -1;
  this->skipSerialization = false;
  this->serializedNewTree = false;
  this->prevSerializedTime = 0;
  this->curSerializedTime = 0;
  this->createdFromSnapshot = false;
  this->blendedFromSnapshot = false;
  v2 = 128;
  this->disableSerialization = false;
  this->usedSnapshotNodes.list = this->usedSnapshotNodes.staticList;
  p_granularity = &this->usedSnapshotNodes.granularity;
  this->usedSnapshotNodes.size = 128;
  this->usedSnapshotNodes.num = 0;
  this->usedSnapshotNodes.granularity = 1;
  this->usedSnapshotNodes.memTag = 5;
  this->usedSnapshotNodes.listStatic = 1;
  do
  {
    p_granularity += 2;
    *(_DWORD *)p_granularity = 0;
    --v2;
  }
  while ( v2 != 0 );
  this->rememberedNodes.granularity = 1;
  this->rememberedNodes.listStatic = 1;
  this->rememberedNodes.num = 0;
  this->rememberedNodes.size = 128;
  v4 = 128;
  this->rememberedNodes.list = this->rememberedNodes.staticList;
  v5 = &this->rememberedNodes.granularity;
  this->rememberedNodes.memTag = 5;
  do
  {
    v5 += 2;
    *(_DWORD *)v5 = 0;
    --v4;
  }
  while ( v4 != 0 );
  p_skipSerialization = &this->skipSerialization;
  for ( i = 9; i != 0; --i )
    *++p_skipSerialization = false;
  memset(Dst: this->branchMemory, Val: 0, Size: sizeof(this->branchMemory));
  memset(Dst: this->leafMemory, Val: 0, Size: sizeof(this->leafMemory));
  return this;
}


// ========================================================================
// __unwind$249969
// EA  : 0x826F3AF4
// RVA : 0x006F3AF4
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_249969()
{
  int v0; // r12

  idMD6BlockAlloc::~idMD6BlockAlloc(this: (idMD6BlockAlloc *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$249970
// EA  : 0x826F3B20
// RVA : 0x006F3B20
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_249970()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 204));
}


// ========================================================================
// ??1idAnimStack@@UAA@XZ
// EA  : 0x826F3B58
// RVA : 0x006F3B58
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::~idAnimStack(idAnimStack *this)
{
  idAnimRecorder *v2; // r3
  int num; // r11
  int v4; // r29
  idAnimator_Base **list; // r4
  idMD6Node **v6; // r4
  idMD6Node **v7; // r4
  unsigned __int8 *v8; // r4
  idAnimator_Base **v9; // r4

  this->__vftable = (idAnimStack_vtbl *)&idAnimStack::`vftable';
  v2 = idAnimRecorder::instance;
  if ( idAnimRecorder::instance == nullptr )
  {
    v2 = idAnimRecorder::allocFunction();
    idAnimRecorder::instance = v2;
  }
  if ( v2->activeAnimStack == this )
    v2->Stop(this: v2);
  num = this->blendStack.num;
  v4 = 0;
  this->tree = nullptr;
  if ( num > 0 )
  {
    do
      idAnimStack::ShutdownBlendStackIndex(this, index: v4++);
    while ( v4 < this->blendStack.num );
  }
  if ( this->blendStack.listStatic == 0 || this->blendStack.listStatic == 2 )
  {
    list = this->blendStack.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->blendStack.list = nullptr;
    this->blendStack.size = 0;
  }
  this->blendStack.num = 0;
  this->treeAnimator = nullptr;
  this->tree = nullptr;
  if ( this->rememberedNodes.listStatic == 0 || this->rememberedNodes.listStatic == 2 )
  {
    v6 = this->rememberedNodes.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->rememberedNodes.list = nullptr;
    this->rememberedNodes.size = 0;
  }
  this->rememberedNodes.num = 0;
  if ( this->usedSnapshotNodes.listStatic == 0 || this->usedSnapshotNodes.listStatic == 2 )
  {
    v7 = this->usedSnapshotNodes.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->usedSnapshotNodes.list = nullptr;
    this->usedSnapshotNodes.size = 0;
  }
  this->usedSnapshotNodes.num = 0;
  if ( this->flags.listStatic == 0 || this->flags.listStatic == 2 )
  {
    v8 = this->flags.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->flags.list = nullptr;
    this->flags.size = 0;
  }
  this->flags.num = 0;
  if ( this->blendStack.listStatic == 0 || this->blendStack.listStatic == 2 )
  {
    v9 = this->blendStack.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->blendStack.list = nullptr;
    this->blendStack.size = 0;
  }
  this->blendStack.num = 0;
  idMD6BlockAlloc::~idMD6BlockAlloc(this: &this->md6Allocator);
}


// ========================================================================
// __unwind$250041
// EA  : 0x826F3D3C
// RVA : 0x006F3D3C
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_250041()
{
  int v0; // r12

  idMD6BlockAlloc::~idMD6BlockAlloc(this: (idMD6BlockAlloc *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$250042
// EA  : 0x826F3D68
// RVA : 0x006F3D68
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_250042()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 204));
}


// ========================================================================
// __unwind$250043
// EA  : 0x826F3D94
// RVA : 0x006F3D94
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_250043()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$250044
// EA  : 0x826F3DC0
// RVA : 0x006F3DC0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_250044()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 516));
}


// ========================================================================
// __unwind$250045
// EA  : 0x826F3DEC
// RVA : 0x006F3DEC
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_250045()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1044));
}


// ========================================================================
// ?AddAnimator@idAnimStack@@QAAXPAVidAnimator_Base@@@Z
// EA  : 0x826F3E18
// RVA : 0x006F3E18
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::AddAnimator(
        idAnimStack *this,
        idAnimator_Base *animator,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idVec1 a14)
{
  int num; // r11
  int v17; // r9
  int v18; // r10
  int v19; // r31
  idList<idAnimator_Base *,25> *p_blendStack; // r28
  int v21; // r30
  idAnimator_Base::priority_t v22; // r25
  unsigned __int8 v23[80]; // [sp+50h] [-50h] BYREF

  num = this->blendStack.num;
  LODWORD(a14.x) = (idVec1)animator;
  v17 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    v19 = 0;
    if ( num <= 0 )
    {
LABEL_9:
      if ( v19 >= num )
      {
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->blendStack,
          obj: (const encounterGroupRole_t *)&a14);
        v23[0] = 0;
        idList<unsigned char,25>::Append(this: (idList<unsigned char,37> *)&this->flags, obj: v23);
      }
    }
    else
    {
      p_blendStack = &this->blendStack;
      v21 = 0;
      while ( 1 )
      {
        v22 = p_blendStack->list[v21]->GetStackPriority(this: p_blendStack->list[v21]);
        if ( v22 > animator->GetStackPriority(this: animator) )
          break;
        num = this->blendStack.num;
        ++v19;
        ++v21;
        if ( v19 >= num )
          goto LABEL_9;
      }
      idList<idVec1,116>::Insert(this: (idList<idVec1,116> *)&this->blendStack, obj: &a14, index: v19);
      v23[0] = 0;
      idList<bool,5>::Insert(this: &this->flags, obj: v23, index: v19);
    }
  }
  else
  {
    v18 = 0;
    while ( this->blendStack.list[v18] != animator )
    {
      ++v17;
      ++v18;
      if ( v17 >= num )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// ?SerializeSnapshot@idAnimStack@@QAAXAAVidSerializer@@PAVidClip@@HPAVidGameTimeManager@@@Z
// EA  : 0x826F3F28
// RVA : 0x006F3F28
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::SerializeSnapshot(
        idAnimStack *this,
        idSerializer *ser,
        idClip *clip,
        int curTime,
        idGameTimeManager *game)
{
  unsigned __int8 v10; // r3
  idTreeAnimator *treeAnimator; // r11
  int v12; // r5
  unsigned __int8 *typesMemory; // r4
  idBitMsg *msg; // r3
  unsigned __int8 *branchMemory; // r4
  idBitMsg *v16; // r3
  unsigned __int8 *leafMemory; // r4
  idBitMsg *v18; // r3
  int v19; // r30
  idList<idAnimator_Base *,25> *p_blendStack; // r27
  int v21; // r20
  idList<unsigned char,25> *p_flags; // r21
  int v23; // r26
  int v24; // r28
  int v25; // r4
  int v26; // r29
  idAnimator_Base *v27; // r10
  idAnimator_AF *v28; // r3
  idAnimator_AF *v29; // r3
  idAnimator_AnimWebHands *v30; // r3
  idAnimator_AnimWebHands *v31; // r3
  idAnimator_WalkIK *v32; // r3
  idAnimator_WalkIK *v33; // r3
  idAnimator_TorsoTracker *v34; // r3
  idAnimator_TorsoTracker *v35; // r3
  idAnimator_Pain *v36; // r3
  idAnimator_Pain *v37; // r3
  idAnimator_JointMod *v38; // r3
  idAnimator_JointMod *v39; // r3
  idAnimator_ReachIK *v40; // r3
  idAnimator_ReachIK *v41; // r3
  idAnimator_Base *v42; // r3
  idAnimator_Base *v43; // r29
  idAnimator_Base *v44; // r11
  idAnimator_Base *v45; // r10
  unsigned __int8 *v46; // r11
  int v47; // r29
  idAnimator_Base *v48; // r10
  int curSerializedTime; // r11
  unsigned __int8 v50[4]; // [sp+50h] [-A0h] BYREF
  int num; // [sp+54h] [-9Ch] BYREF
  idTypesafeNumber<int,enum gameTimeUnique_t> v52[38]; // [sp+58h] [-98h] BYREF

  if ( !this->skipSerialization && !this->disableSerialization )
  {
    v10 = idSerializer::SerializeBoolNonRef(this: ser, value: (_cntlzw((unsigned int)this->treeAnimator) & 0x20) != 0);
    treeAnimator = this->treeAnimator;
    v12 = (_cntlzw((unsigned int)treeAnimator) & 0x20) != 0;
    if ( v12 == v10 )
    {
      if ( v10 == 0 && treeAnimator != nullptr )
      {
        typesMemory = this->typesMemory;
        msg = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteData(this: msg, data: typesMemory, length: 9);
        else
          idBitMsg::ReadData(this: msg, data: typesMemory, length: 9);
        branchMemory = this->branchMemory;
        v16 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteData(this: v16, data: branchMemory, length: 96);
        else
          idBitMsg::ReadData(this: v16, data: branchMemory, length: 96);
        leafMemory = this->leafMemory;
        v18 = ser->msg;
        if ( ser->writing )
          idBitMsg::WriteData(this: v18, data: leafMemory, length: 153);
        else
          idBitMsg::ReadData(this: v18, data: leafMemory, length: 153);
        num = this->blendStack.num;
        idSerializer::Serialize(this: ser, value: &num);
        v19 = 0;
        p_blendStack = &this->blendStack;
        v52[0].value = 0;
        v21 = num;
        idList<idRenderModelCommitted *,5>::SetNum(
          this: (idList<int,5> *)&this->blendStack,
          newNum: num,
          initValue: &v52[0].value);
        v50[0] = 0;
        p_flags = &this->flags;
        idList<bool,5>::SetNum(this: (idList<bool,5> *)&this->flags, newNum: v21, initValue: (const bool *)v50);
        v23 = 0;
        if ( v21 > 0 )
        {
          v24 = 0;
          do
          {
            v25 = 0;
            if ( ser->writing )
              v25 = ((int (__fastcall *)(idAnimator_Base *, _DWORD))p_blendStack->list[v24]->GetSerializeType)(
                      a1: p_blendStack->list[v24],
                      a2: 0);
            v26 = idSerializer::SerializeUMaxNonRef(this: ser, value: v25, maxSize: 7u);
            if ( !ser->writing )
            {
              v27 = p_blendStack->list[v24];
              if ( v27 != nullptr && ((int (*)(void))v27->GetSerializeType)() != v26 )
              {
                idAnimStack::ShutdownBlendStackIndex(this, index: v23);
                p_blendStack->list[v24] = nullptr;
              }
            }
            if ( p_blendStack->list[v24] == nullptr )
            {
              this->createdFromSnapshot = true;
              switch ( v26 )
              {
                case 1:
                  v28 = (idAnimator_AF *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x648u,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v28;
                  if ( v28 != nullptr )
                    v29 = idAnimator_AF::idAnimator_AF(this: v28);
                  else
                    v29 = nullptr;
                  p_blendStack->list[v24] = v29;
                  break;
                case 2:
                  v30 = (idAnimator_AnimWebHands *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                     size: 0x2B0u,
                                                     tag: TAG_NEW,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v30;
                  if ( v30 != nullptr )
                    v31 = idAnimator_AnimWebHands::idAnimator_AnimWebHands(this: v30);
                  else
                    v31 = nullptr;
                  p_blendStack->list[v24] = v31;
                  break;
                case 3:
                  v32 = (idAnimator_WalkIK *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                               size: 0x6D0u,
                                               tag: TAG_NEW,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v32;
                  if ( v32 != nullptr )
                    v33 = idAnimator_WalkIK::idAnimator_WalkIK(this: v32);
                  else
                    v33 = nullptr;
                  p_blendStack->list[v24] = v33;
                  break;
                case 4:
                  v34 = (idAnimator_TorsoTracker *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                     size: 0xBCu,
                                                     tag: TAG_NEW,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v34;
                  if ( v34 != nullptr )
                    v35 = idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: v34);
                  else
                    v35 = nullptr;
                  p_blendStack->list[v24] = v35;
                  break;
                case 5:
                  v36 = (idAnimator_Pain *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                             size: 0x60u,
                                             tag: TAG_NEW,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v36;
                  if ( v36 != nullptr )
                    v37 = idAnimator_Pain::idAnimator_Pain(this: v36);
                  else
                    v37 = nullptr;
                  p_blendStack->list[v24] = v37;
                  break;
                case 6:
                  v38 = (idAnimator_JointMod *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x54u,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v38;
                  if ( v38 != nullptr )
                    v39 = idAnimator_JointMod::idAnimator_JointMod(this: v38);
                  else
                    v39 = nullptr;
                  p_blendStack->list[v24] = v39;
                  break;
                case 7:
                  v40 = (idAnimator_ReachIK *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                size: 0x1C8u,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
                  v52[0].value = (int)v40;
                  if ( v40 != nullptr )
                    v41 = idAnimator_ReachIK::idAnimator_ReachIK(this: v40);
                  else
                    v41 = nullptr;
                  p_blendStack->list[v24] = v41;
                  break;
                default:
                  v42 = (idAnimator_Base *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                             size: 0x28u,
                                             tag: TAG_NEW,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
                  v43 = v42;
                  v52[0].value = (int)v42;
                  if ( v42 != nullptr )
                  {
                    idAnimator_Base::idAnimator_Base(this: v42);
                    v44 = v43;
                    v43->__vftable = (idAnimator_Base_vtbl *)&idAnimator_Client::`vftable';
                  }
                  else
                  {
                    v44 = nullptr;
                  }
                  p_blendStack->list[v24] = v44;
                  break;
              }
              p_blendStack->list[v24]->PreSerializeInit(this: p_blendStack->list[v24], a2: this, a3: clip, a4: game);
            }
            v45 = p_blendStack->list[v24];
            v45->serializeProps.animStack = this;
            v45->serializeProps.clip = clip;
            v45->gametimeManager.gameTimeManager = game;
            v50[0] = p_flags->list[v23];
            idSerializer::Serialize(this: ser, value: v50);
            ++v24;
            v46 = &p_flags->list[v23++];
            *v46 = *v46 & 0x30 | v50[0];
          }
          while ( v23 < v21 );
        }
        if ( this->blendStack.num > 0 )
        {
          v47 = 0;
          do
          {
            p_flags->list[v19] |= !idSerializer::SerializeBoolNonRef(this: ser, value: (p_flags->list[v19] & 2) != 0)
                                ? 0
                                : 2;
            if ( (p_flags->list[v19] & 2) != 0 && (p_flags->list[v19] & 8) != 0 )
            {
              v48 = p_blendStack->list[v47];
              if ( v48 != nullptr )
                ((void (*)(void))v48->SerializeSnapshot)();
            }
            ++v19;
            ++v47;
          }
          while ( v19 < this->blendStack.num );
        }
        if ( ser->writing )
        {
          idSerializer::Serialize(this: ser, value: &this->pauseTime.value);
        }
        else
        {
          idSerializer::Serialize(this: ser, value: &v52[0].value);
          if ( v52[0].value != this->pauseTime.value )
          {
            if ( v52[0].value >= 0 )
            {
              v52[0].value = idGameTimeManager::GetGameMs(this: game, type: GAMETIME_SCALED);
              idAnimStack::Pause(this, curTime: v52);
            }
            else
            {
              v52[0].value = idGameTimeManager::GetGameMs(this: game, type: GAMETIME_SCALED);
              idAnimStack::Unpause(this, curTime: v52);
            }
          }
        }
        curSerializedTime = this->curSerializedTime;
        this->curSerializedTime = curTime;
        this->serializedNewTree = true;
        this->prevSerializedTime = curSerializedTime;
      }
    }
    else
    {
      idLib::Warning(fmt: "Client/Server mismatch on noTreeAnimator. Server: %d Client: %d", v10, v12);
    }
  }
}


// ========================================================================
// __unwind$250382
// EA  : 0x826F453C
// RVA : 0x006F453C
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250382(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250383
// EA  : 0x826F4564
// RVA : 0x006F4564
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250383(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250384
// EA  : 0x826F458C
// RVA : 0x006F458C
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250384(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250385
// EA  : 0x826F45B4
// RVA : 0x006F45B4
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250385(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250386
// EA  : 0x826F45DC
// RVA : 0x006F45DC
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250386(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250387
// EA  : 0x826F4604
// RVA : 0x006F4604
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250387(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250388
// EA  : 0x826F462C
// RVA : 0x006F462C
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250388(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// __unwind$250389
// EA  : 0x826F4654
// RVA : 0x006F4654
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall _unwind_250389(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 88), tag: a2);
}


// ========================================================================
// ?BlendSnapshot@idAnimStack@@QAAXHHHMPAVidGameTimeManager@@PAVidParallelJobList@@@Z
// EA  : 0x826F4680
// RVA : 0x006F4680
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::BlendSnapshot(
        idAnimStack *this,
        int curTime,
        int gameMsPerFrame,
        int ticksPerSec,
        double fraction,
        idGameTimeManager *game,
        idGameTimeManager *parallelJobList,
        idParallelJobList *a8)
{
  idMD6BlockAlloc *p_md6Allocator; // r3
  idMD6Branch *v15; // r25
  double v16; // fp1
  idAnimRecorder *v17; // r3
  char v18; // r11
  int num; // r8
  int v20; // r24
  int v21; // r22
  idAnimator_JointMod *v22; // r31
  idMD6Branch *v23; // r4
  idMD6Branch *v24; // r4
  idMD6Branch *v25; // r30
  idMD6Branch *v26; // r4
  idMD6Branch *v27; // r27
  encounterGroupRole_t v28; // r14
  idMD6Node *right; // r7
  idMD6Node *v30; // r31
  double currentAlpha; // fp0
  idMD6Node *v32; // r11
  idTreeAnimator *treeAnimator; // r11
  idMD6Branch *v34; // r31
  idTreeAnimator *v35; // r3
  int v36; // r31
  int v37; // r30
  idStaticList<idMD6Node *,128> *p_rememberedNodes; // r31
  int v39; // r30
  int v40; // r28
  idTreeAnimator *v41; // r3
  float *v42; // [sp+8h] [-1B8h]
  float *v43; // [sp+Ch] [-1B4h]
  float *v44; // [sp+10h] [-1B0h]
  int v45; // [sp+70h] [-150h] BYREF
  encounterGroupRole_t v46[3]; // [sp+74h] [-14Ch] BYREF
  idBitMsg v47; // [sp+80h] [-140h] BYREF
  idBitMsg v48; // [sp+B0h] [-110h] BYREF
  idBitMsg v49; // [sp+E0h] [-E0h] BYREF

  if ( this->disableSerialization )
    goto LABEL_4;
  if ( this->treeAnimator == nullptr )
  {
    idLib::Warning(fmt: "idAnimStack::BlendSnapshot called with NULL tree animator");
LABEL_4:
    p_md6Allocator = &this->md6Allocator;
    goto LABEL_83;
  }
  v15 = nullptr;
  this->tree = nullptr;
  this->blendedFromSnapshot = true;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->usedSnapshotNodes, newNum: 0);
  if ( fraction >= 0.0 )
  {
    if ( fraction > 1.0 )
      fraction = 1.0;
  }
  else
  {
    fraction = 0.0;
  }
  v45 = curTime;
  v17 = idAnimRecorder::instance;
  if ( idAnimRecorder::instance == nullptr )
  {
    v17 = idAnimRecorder::allocFunction();
    idAnimRecorder::instance = v17;
  }
  if ( v17->activeAnimStack != this || (v18 = 1, v17->recordingFileMode != RECORDING_FILE_READ) )
    v18 = 0;
  if ( v18 != 0 )
    v17->Serialize(this: v17, a2: &v45, a3: parallelJobList, a4: false);
  num = this->blendStack.num;
  v49.writeData = nullptr;
  v49.maxSize = 9;
  v49.curSize = 9;
  memset(&v49.writeBit, 0, 14);
  v49.readData = this->typesMemory;
  v20 = 0;
  v49.tempValue = 0;
  v48.writeData = nullptr;
  v48.readData = this->branchMemory;
  v48.maxSize = 96;
  v48.curSize = 96;
  memset(&v48.writeBit, 0, 14);
  v48.tempValue = 0;
  v47.writeData = nullptr;
  v47.readData = this->leafMemory;
  v47.maxSize = 153;
  v47.curSize = 153;
  memset(&v47.writeBit, 0, 14);
  v47.tempValue = 0;
  if ( num > 0 )
  {
    v21 = 0;
    do
    {
      v22 = (idAnimator_JointMod *)this->blendStack.list[v21];
      if ( (this->flags.list[v20] & 0x10) == 0 && (this->flags.list[v20] & 2) == 0 )
        goto LABEL_64;
      if ( (this->flags.list[v20] & 8) == 0 )
      {
        idAnimator_JointMod::PreBlendSnapshot(this: v22, stack: this, curTime: v45, ticksPerSec, fraction: v16);
        if ( idAnimator_Base::IsContributing(this: v22) )
        {
          v34 = v22->InternalGetMergeBranch_2(this: v22);
          v46[0] = (encounterGroupRole_t)v34->right;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->usedSnapshotNodes,
            obj: v46);
          if ( v15 != nullptr )
          {
            if ( v15->left != nullptr )
              v34->left = v15;
            else
              v34->left = v15->right;
            this->tree = v34;
          }
          else
          {
            this->tree = v34->right;
            if ( v34->alphaRate != 0.0 )
              idMD6Branch::UpdateCurrentAlpha(this: v34, timeMSec: v45, lastTimeMSec: v45 - gameMsPerFrame, ticksPerSec);
          }
          v15 = v34;
        }
        goto LABEL_64;
      }
      v22->PreBlendSnapshot(this: v22, a2: this, a3: v45, a4: ticksPerSec, a5: fraction);
      if ( (this->flags.list[v20] & 0x20) == 0 && (this->flags.list[v20] & 4) == 0 )
      {
        v23 = v22->serializeProps.serializedTrees[0];
        if ( v23 != nullptr )
        {
          v23->left = nullptr;
          idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v23);
          v22->serializeProps.serializedTrees[0] = nullptr;
        }
        v24 = v22->serializeProps.serializedTrees[1];
        if ( v24 != nullptr )
        {
          v24->left = nullptr;
          idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v24);
          v22->serializeProps.serializedTrees[1] = nullptr;
        }
        goto LABEL_64;
      }
      v25 = v22->InternalGetMergeBranch_2(this: v22);
      if ( v22->GetSerializeType(this: v22) == STYPE_GENERIC )
      {
        if ( this->serializedNewTree )
        {
          if ( anim_blendSnapshotDebug.valueInteger != 0 )
            idLib::Printf(fmt: "^6Serialized new tree %s\n", this->treeAnimator->decl->name.str);
          v26 = v22->serializeProps.serializedTrees[0];
          if ( v26 != nullptr )
          {
            v26->left = nullptr;
            idTreeAnimator::FreeTree(allocator: &this->md6Allocator, node: v26);
            v22->serializeProps.serializedTrees[0] = nullptr;
          }
          v22->serializeProps.serializedTrees[0] = v22->serializeProps.serializedTrees[1];
          v22->serializeProps.serializedTrees[1] = (idMD6Branch *)idTreeAnimator::ReadTree(
                                                                    animStack: this,
                                                                    allocator: &this->md6Allocator,
                                                                    typesMsg: &v49,
                                                                    branchMsg: &v48,
                                                                    leafMsg: &v47);
        }
        v25 = v22->serializeProps.serializedTrees[1];
      }
      if ( v25 == nullptr || v25->right == nullptr )
        goto LABEL_64;
      v46[0] = (encounterGroupRole_t)v25->right;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->usedSnapshotNodes,
        obj: v46);
      v27 = v22->serializeProps.serializedTrees[0];
      if ( v27 != nullptr
        && v27->right != nullptr
        && v25->right != nullptr
        && anim_blendSnapshotNoLerp.valueInteger == 0 )
      {
        v46[0] = (encounterGroupRole_t)this->md6Allocator.Alloc(this: &this->md6Allocator, a2: 0);
        v28 = v46[0];
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->rememberedNodes,
          obj: v46);
        *(_DWORD *)(v28 + 4) = v27->right;
        right = v25->right;
        *(float *)(v28 + 24) = fraction;
        *(float *)(v28 + 28) = 1.0;
        *(_DWORD *)(v28 + 8) = right;
        *(float *)(v28 + 32) = 0.0;
        *(_BYTE *)(v28 + 21) = 1;
        *(_BYTE *)(v28 + 20) = 0;
        *(_BYTE *)(v28 + 22) = 0;
        v30 = this->md6Allocator.Alloc(this: &this->md6Allocator, a2: 0);
        currentAlpha = v25->currentAlpha;
        v46[0] = (encounterGroupRole_t)v30;
        *(float *)&v30[24].type = currentAlpha;
        *(float *)&v30[32].type = v25->alphaRate;
        v30[20].type = v25->filterGroup;
        v30[21].type = v25->op;
        *(float *)&v30[28].type = v25->targetAlpha;
        v30[22].type = v25->originBlend;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->rememberedNodes,
          obj: v46);
        *(_DWORD *)&v30[8].type = v28;
        *(_DWORD *)&v30[4].type = 0;
        *(float *)&v30[24].type = (float)((float)(v25->currentAlpha - v27->currentAlpha) * (float)fraction)
                                + v27->currentAlpha;
        v25 = (idMD6Branch *)v30;
      }
      if ( v15 != nullptr )
      {
        if ( v25 != nullptr )
        {
          if ( v15->left != nullptr )
          {
            v25->left = v15;
            v15 = v25;
          }
          else
          {
            v32 = v15->right;
            v15 = v25;
            v25->left = v32;
          }
          this->tree = v25;
          goto LABEL_64;
        }
      }
      else if ( v25 != nullptr )
      {
        this->tree = v25->right;
        if ( v25->alphaRate == 0.0 )
          goto LABEL_54;
        idMD6Branch::UpdateCurrentAlpha(this: v25, timeMSec: v45, lastTimeMSec: v45 - gameMsPerFrame, ticksPerSec);
        v15 = v25;
        goto LABEL_64;
      }
      treeAnimator = this->treeAnimator;
      if ( treeAnimator == nullptr )
      {
        idLib::Warning(fmt: "curBranch == NULL for animator %s in animstack: %s", "<unknown>", "NULL MD6");
LABEL_54:
        v15 = v25;
        goto LABEL_64;
      }
      idLib::Warning(
        fmt: "curBranch == NULL for animator %s in animstack: %s",
        "<unknown>",
        treeAnimator->decl->name.str);
      v15 = v25;
LABEL_64:
      ++v20;
      ++v21;
    }
    while ( v20 < this->blendStack.num );
  }
  v35 = this->treeAnimator;
  if ( v35 != nullptr )
    idTreeAnimator::BlendTreeInternal(
      this: v35,
      currentTime: v45,
      previousTime: v45 - gameMsPerFrame,
      gameMsPerFrame,
      ticksPerSec,
      tree: this->tree,
      parallelJobList: a8,
      localR: nullptr,
      localS: v42,
      localT: v43,
      localU: v44);
  v36 = 0;
  if ( this->blendStack.num > 0 )
  {
    v37 = 0;
    do
    {
      if ( (this->flags.list[v36] & 4) != 0 )
        this->blendStack.list[v37]->InternalPostBlendTree(this: this->blendStack.list[v37], a2: this, a3: v45);
      ++v36;
      ++v37;
    }
    while ( v36 < this->blendStack.num );
  }
  p_rememberedNodes = &this->rememberedNodes;
  v39 = 0;
  if ( this->rememberedNodes.num > 0 )
  {
    v40 = 0;
    do
    {
      this->md6Allocator.Free(this: &this->md6Allocator, a2: p_rememberedNodes->list[v40]);
      ++v39;
      ++v40;
    }
    while ( v39 < this->rememberedNodes.num );
  }
  if ( this->rememberedNodes.listStatic == 0 || this->rememberedNodes.listStatic == 2 )
  {
    if ( p_rememberedNodes->list != nullptr )
      idMem::Free(this: &mem, ptr: p_rememberedNodes->list, align: ALIGN_16);
    p_rememberedNodes->list = nullptr;
    this->rememberedNodes.size = 0;
  }
  this->rememberedNodes.num = 0;
  v41 = this->treeAnimator;
  if ( v41 != nullptr )
    idTreeAnimator::UpdateTime(this: v41, time: v45);
  this->serializedNewTree = false;
  p_md6Allocator = &this->md6Allocator;
LABEL_83:
  idMD6BlockAlloc::DeferredFree(this: p_md6Allocator);
}


// ========================================================================
// ?AddNodeToSyncGroups@idAnimStack@@QAAXAAV?$idList@UsyncGroup_t@idAnimStack@@$04@@PAVidMD6LeafPlay@@M@Z
// EA  : 0x826F5568
// RVA : 0x006F5568
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::AddNodeToSyncGroups(
        idAnimStack *this,
        idList<idAnimStack::syncGroup_t,5> *groups,
        idMD6LeafPlay *node,
        double alpha)
{
  int num; // r7
  int v8; // r10
  idAnimStack::syncGroup_t *v9; // r9
  int v10; // r11
  idList<idAnimStack::syncNode_t,5> *p_nodes; // r3
  unsigned int v12; // r11
  idAnimStack::syncNode_t *v14; // r3
  int v15; // r11
  int size; // r10
  idAnimStack::syncGroup_t *v17; // r31
  int v18; // r4
  int v19; // r11
  int v20; // r10
  idAnimStack::syncNode_t *list; // r9
  int v22; // r11

  num = groups->num;
  v8 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    if ( groups->listStatic != 0 )
      v12 = (num >> 31) + ((unsigned int)num >= groups->size) + ((unsigned int)groups->size >> 31);
    else
      LOBYTE(v12) = 0;
    if ( (_BYTE)v12 != 0 )
    {
      idLib::Warning(fmt: "Sync Groups Full(%d)", groups->size);
    }
    else
    {
      idList<idAnimStack::syncGroup_t,5>::PreAllocateWithGranularity(this: groups, newSize: num + 1);
      v15 = groups->num;
      size = groups->size;
      if ( v15 >= size )
      {
        v17 = &groups->list[size - 1];
      }
      else
      {
        v17 = &groups->list[v15];
        groups->num = v15 + 1;
      }
      v18 = v17->nodes.num + 1;
      v17->groupNumber = node->syncGroup;
      idList<idAnimStack::syncNode_t,5>::PreAllocateWithGranularity(this: &v17->nodes, newSize: v18);
      v19 = v17->nodes.num;
      v20 = v17->nodes.size;
      list = v17->nodes.list;
      if ( v19 >= v20 )
      {
        v22 = (int)&list[v20 - 1];
      }
      else
      {
        v17->nodes.num = v19 + 1;
        v22 = (int)&list[v19];
      }
      *(float *)(v22 + 4) = alpha;
      *(_DWORD *)v22 = node;
    }
  }
  else
  {
    v9 = groups->list;
    v10 = 0;
    while ( 1 )
    {
      p_nodes = &v9[v10].nodes;
      if ( v9[v10].groupNumber == node->syncGroup )
        break;
      ++v8;
      ++v10;
      if ( v8 >= groups->num )
        goto LABEL_5;
    }
    if ( p_nodes->listStatic != 0 && p_nodes->num >= p_nodes->size )
    {
      idLib::Warning(fmt: "Sync Groups Nodes Full(%d)", p_nodes->size);
    }
    else
    {
      v14 = idList<idAnimStack::syncNode_t,5>::Alloc(this: p_nodes);
      v14->alpha = alpha;
      v14->node = node;
    }
  }
}


// ========================================================================
// ?PreSynchronizeNode_r@idAnimStack@@QAAXAAV?$idList@UsyncGroup_t@idAnimStack@@$04@@PAVidMD6Node@@M@Z
// EA  : 0x826F5738
// RVA : 0x006F5738
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::PreSynchronizeNode_r(
        idAnimStack *this,
        idList<idAnimStack::syncGroup_t,5> *groups,
        idMD6Node *_node,
        double branchAlpha)
{
  int type; // r11
  char v9; // r11
  bool v10; // zf
  double v11; // fp1
  double v12; // fp31
  unsigned __int8 *v13; // r5
  unsigned __int8 *v14; // r31
  unsigned int v15; // r11
  __int64 v16; // r10
  int v17; // r10
  char v18; // r11
  char v19; // r11
  unsigned int v20; // r11
  __int64 v21; // r10
  int v22; // r10
  char v23; // r11
  char v24; // r11

  while ( 1 )
  {
    type = _node->type;
    if ( _node->type == 0 || type == 3 || type == 4 || (v10 = type != 5, v9 = 0, !v10) )
      v9 = 1;
    if ( v9 == 0 )
      break;
    v11 = 0.0;
    v12 = 0.0;
    if ( (unsigned int)_node[21].type - 1 <= 7 )
    {
      if ( _node[21].type == 2 )
      {
        v11 = branchAlpha;
        v12 = branchAlpha;
      }
      else if ( _node[21].type != 3 && _node[21].type != 4 && _node[21].type != 5 && _node[21].type != 6 )
      {
        v11 = (float)(*(float *)&_node[24].type * (float)branchAlpha);
        v12 = (float)((float)((float)1.0 - *(float *)&_node[24].type) * (float)branchAlpha);
      }
    }
    v13 = *(unsigned __int8 **)&_node[8].type;
    v14 = *(unsigned __int8 **)&_node[4].type;
    if ( v13 != nullptr )
    {
      if ( *v13 == 6 )
      {
        v15 = *((_DWORD *)v13 + 2);
        if ( v15 == 0 )
          goto LABEL_35;
        LODWORD(v16) = *((unsigned __int16 *)v13 + 44);
        HIDWORD(v16) = v15 >> 31;
        v13 = *(unsigned __int8 **)(((4 * (((v16 - (unsigned __int64)v15) >> 32) & (unsigned __int16)v16)) & 0x3FFFC)
                                  + *((_DWORD *)v13 + 1));
      }
      if ( v13 != nullptr )
      {
        v17 = *v13;
        if ( v17 != 2 )
          goto LABEL_57;
        if ( v13[21] == 0 || (v18 = 1, v13[20] == 0) )
          v18 = 0;
        if ( v18 != 0 )
        {
          idAnimStack::AddNodeToSyncGroups(this, groups, node: (idMD6LeafPlay *)v13, alpha: v11);
        }
        else
        {
LABEL_57:
          if ( *v13 == 0 || v17 == 3 || v17 == 4 || (v19 = 0, v17 == 5) )
            v19 = 1;
          if ( v19 != 0 || v17 == 3 || v17 == 4 )
            idAnimStack::PreSynchronizeNode_r(this, groups, _node: (idMD6Node *)v13, branchAlpha: v11);
        }
      }
    }
LABEL_35:
    if ( v14 == nullptr )
      return;
    if ( *v14 == 6 )
    {
      v20 = *((_DWORD *)v14 + 2);
      if ( v20 == 0 )
        return;
      LODWORD(v21) = *((unsigned __int16 *)v14 + 44);
      HIDWORD(v21) = v20 >> 31;
      v14 = *(unsigned __int8 **)(((4 * (((v21 - (unsigned __int64)v20) >> 32) & (unsigned __int16)v21)) & 0x3FFFC)
                                + *((_DWORD *)v14 + 1));
    }
    if ( v14 == nullptr )
      return;
    v22 = *v14;
    if ( v22 == 2 )
    {
      if ( v14[21] == 0 || (v23 = 1, v14[20] == 0) )
        v23 = 0;
      if ( v23 != 0 )
      {
        idAnimStack::AddNodeToSyncGroups(this, groups, node: (idMD6LeafPlay *)v14, alpha: v12);
        return;
      }
    }
    if ( *v14 == 0 || v22 == 3 || v22 == 4 || (v24 = 0, v22 == 5) )
      v24 = 1;
    if ( v24 == 0 && v22 != 3 && v22 != 4 )
      return;
    branchAlpha = v12;
    _node = (idMD6Node *)v14;
  }
}


// ========================================================================
// ?UpdateSynchronization@idAnimStack@@QAAXHHHH@Z
// EA  : 0x826F59F0
// RVA : 0x006F59F0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimStack::UpdateSynchronization(
        idAnimStack *this,
        int currentTime,
        const int previousTime,
        const int gameMsPerFrame,
        int ticksPerSec)
{
  __int64 v9; // r10 OVERLAPPED
  int AnimLength; // r8 OVERLAPPED
  int v11; // r20
  int v12; // r22
  double v13; // fp28
  double v14; // fp30
  double v15; // fp31
  int v16; // r26
  idAnimStack::syncGroup_t *v17; // r29
  idAnimStack::syncNode_t *list; // r27
  int v19; // r28
  float *v20; // r30
  __int64 v21; // r10
  double v22; // fp26
  int v23; // r9
  long double v24; // fp2
  double v25; // fp0
  double v26; // fp31
  long double v27; // fp2
  int v28; // r28
  int v29; // r30
  idAnimStack::syncNode_t *v30; // r27
  __int64 v31; // r11
  __int64 v32; // [sp+70h] [-330h]
  idStaticList<idAnimStack::syncGroup_t,4> v33; // [sp+80h] [-320h] BYREF

  idStaticList<idAnimStack::syncGroup_t,4>::idStaticList<idAnimStack::syncGroup_t,4>(this: &v33);
  idAnimStack::PreSynchronizeNode_r(this, groups: &v33, _node: this->tree, branchAlpha: 1.0);
  v11 = 0;
  if ( v33.num > 0 )
  {
    v12 = 0;
    LODWORD(v9) = currentTime - previousTime;
    v13 = (float)v9;
    do
    {
      v14 = 0.0;
      v15 = 0.0;
      v16 = 0;
      v17 = &v33.list[v12];
      list = v33.list[v12].nodes.list;
      if ( v33.list[v12].nodes.num > 0 )
      {
        v19 = 0;
        do
        {
          v20 = (float *)&v17->nodes.list[v19];
          if ( v20[1] != 0.0 )
          {
            AnimLength = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v20 + 4) + 40) + 6) & 1;
            if ( AnimLength == 0 )
            {
              v15 = (float)(v20[1] + (float)v15);
              LODWORD(v21) = idMD6LeafPlay::GetAnimLength(
                               this: *(idMD6LeafPlay **)v20,
                               ticksPerSec,
                               applyRateScale: false);
              v22 = v20[1];
              v14 = (float)((float)((float)(idSoundEmitterLocal::GetVolumeAdjustment(this: *(bfx::Orienter **)v20)
                                          / (float)((float)v21 * (float)0.001))
                                  * (float)v22)
                          + (float)v14);
              if ( v22 > list->alpha )
                list = (idAnimStack::syncNode_t *)v20;
            }
          }
          ++v16;
          ++v19;
        }
        while ( v16 < v17->nodes.num );
      }
      v17->syncRate = (float)v14 / (float)v15;
      v23 = previousTime - list->node->startTime;
      v32 = *(_QWORD *)(&AnimLength - 1);
      AnimLength = idMD6LeafPlay::GetAnimLength(this: list->node, ticksPerSec, applyRateScale: false);
      v25 = (float)((float)v32 / (float)*(__int64 *)&AnimLength);
      if ( v25 < 0.0 )
        v25 = 0.0;
      v26 = (float)((float)((float)((float)v13 * 0.001) * v17->syncRate) + (float)v25);
      if ( v26 > 1.0 )
      {
        *(double *)&v24 = (float)((float)((float)((float)v13 * 0.001) * v17->syncRate) + (float)v25);
        v27 = floor(x: v24);
        v26 = (float)((float)v26 - (float)*(double *)&v27);
      }
      v28 = 0;
      if ( v17->nodes.num > 0 )
      {
        v29 = 0;
        do
        {
          v30 = v17->nodes.list;
          LODWORD(v31) = idMD6LeafPlay::GetAnimLength(
                           this: v17->nodes.list[v29].node,
                           ticksPerSec,
                           applyRateScale: false);
          idMD6LeafPlay::SetFrameTime(
            this: v30[v29].node,
            gameTime: currentTime,
            targetTime: (int)(float)((float)v31 * (float)v26));
          ++v28;
          ++v29;
        }
        while ( v28 < v17->nodes.num );
      }
      ++v11;
      ++v12;
    }
    while ( v11 < v33.num );
  }
  idStaticList<idAnimStack::syncGroup_t,4>::~idStaticList<idAnimStack::syncGroup_t,4>(this: &v33);
}


// ========================================================================
// __unwind$251766
// EA  : 0x826F5C4C
// RVA : 0x006F5C4C
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251766()
{
  int v0; // r12

  idStaticList<idAnimStack::syncGroup_t,4>::~idStaticList<idAnimStack::syncGroup_t,4>(this: (idStaticList<idAnimStack::syncGroup_t,4> *)(v0 - 928 + 128));
}


// ========================================================================
// ?BlendStackInternal@idAnimStack@@AAAXHHHHPAVidGameTimeManager@@PAVidParallelJobList@@PAM222@Z
// EA  : 0x826F5C80
// RVA : 0x006F5C80
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __fastcall idAnimStack::BlendStackInternal(
        idAnimStack *this,
        int currentTime,
        int previousTime,
        int gameMsPerFrame,
        idGameTimeManager *ticksPerSec,
        idGameTimeManager *game,
        idParallelJobList *parallelJobList,
        float *localR,
        float *localS,
        float *localT,
        float *localU)
{
  unsigned __int64 v13; // r27
  int v14; // r23
  idAnimRecorder *v15; // r9
  idAnimStack *activeAnimStack; // r10
  char v19; // r11
  idTreeAnimator *v20; // r3
  char v21; // r11
  unsigned __int64 v22; // r6
  const char *v23; // r7
  double v24; // fp1
  int num; // r11
  idMD6Branch *v26; // r24
  char v27; // r21
  int v28; // r25
  int v29; // r23
  unsigned __int8 *list; // r11
  idAnimator_JointMod *v31; // r28
  unsigned __int8 v32; // r29
  int v33; // r3
  idMD6Branch *v34; // r29
  char v35; // r26
  bool v36; // zf
  idMD6Branch *(__fastcall *InternalGetEndBranch_2)(struct idAnimator_JointMod *); // ctr
  int v38; // r3
  idMD6Node *left; // r11
  idMD6Node *right; // r11
  idMD6Node *v41; // r11
  idMD6Node *v42; // r11
  unsigned __int64 v43; // r6
  const char *v44; // r7
  int i; // r11
  unsigned __int8 *v46; // r10
  bool *p_skipSerialization; // r11
  int j; // ctr
  idPLog *pLog; // r28
  idPLog::logEntry_t *v50; // r29
  int v51; // r3
  __int64 totalTicks; // r11
  __int64 v53; // r9
  idPLog *v54; // r28
  idPLog::logEntry_t *v55; // r29
  int v56; // r3
  __int64 v57; // r11
  __int64 v58; // r9
  unsigned __int64 v59; // r6
  const char *v60; // r7
  int v61; // r28
  idPLog::logEntry_t *v62; // r25
  __int64 v63; // r3
  idAnimRecorder *v64; // r3
  idMD6Node *tree; // r8
  idTreeAnimator *treeAnimator; // r3
  idPLog::logEntry_t *v67; // r29
  int v68; // r3
  int parent; // r11
  __int64 v70; // r9
  int v71; // r25
  idPLog::logEntry_t *v72; // r28
  __int64 v73; // r3
  int v74; // r29
  int v75; // r28
  idPLog::logEntry_t *v76; // r29
  int v77; // r3
  int v78; // r11
  __int64 v79; // r9
  float *v80; // [sp+8h] [-1B8h]
  float *v81; // [sp+Ch] [-1B4h]
  float *v82; // [sp+10h] [-1B0h]
  char v83; // [sp+70h] [-150h]
  idAnimRecorder *v84; // [sp+74h] [-14Ch] BYREF
  idPLogScope v85; // [sp+78h] [-148h] BYREF
  idPLogScope v86[2]; // [sp+80h] [-140h] BYREF
  idBitMsg v87; // [sp+90h] [-130h] BYREF
  idBitMsg v88; // [sp+C0h] [-100h] BYREF
  idBitMsg v89; // [sp+F0h] [-D0h] BYREF

  HIDWORD(v13) = currentTime;
  v14 = gameMsPerFrame;
  v15 = idAnimRecorder::instance;
  v84 = idAnimRecorder::instance;
  if ( idAnimRecorder::instance == nullptr )
  {
    v84 = idAnimRecorder::allocFunction();
    v15 = v84;
    idAnimRecorder::instance = v84;
  }
  activeAnimStack = v15->activeAnimStack;
  LODWORD(v13) = 0;
  if ( activeAnimStack != this || (v19 = 1, v15->recordingFileMode != RECORDING_FILE_READ) )
    v19 = 0;
  if ( v19 != 0 )
  {
    idAnimStack::BlendSnapshot(
      this,
      curTime: SHIDWORD(v13),
      gameMsPerFrame: v14,
      (int)ticksPerSec,
      fraction: 0.0,
      game: ticksPerSec,
      parallelJobList: game,
      a8: parallelJobList);
    return;
  }
  if ( this->pauseTime.value < 0 )
  {
    if ( activeAnimStack != this || (v21 = 1, v15->recordingFileMode != RECORDING_FILE_WRITE) )
      v21 = 0;
    v83 = v21;
    RD_EventBegin(name: "idAnimStack::BlendStack - pre");
    LODWORD(v22) = "idAnimStack::BlendStack - pre";
    HIDWORD(v22) = 2;
    idPLogScope::idPLogScope(this: v86, pl: &::pLog, gMask: v22, label: v23);
    if ( this->treeAnimator == nullptr )
    {
      idMD6BlockAlloc::DeferredFree(this: &this->md6Allocator);
      idPLogScope::~idPLogScope(this: v86);
      RD_EventEnd();
      return;
    }
    num = this->blendStack.num;
    this->tree = nullptr;
    v87.writeData = this->typesMemory;
    v87.readData = this->typesMemory;
    memset(&v87.curSize, 0, 16);
    v87.maxSize = 9;
    v26 = nullptr;
    v27 = 0;
    v28 = 0;
    v87.overflowed = false;
    v87.tempValue = v13;
    v88.writeData = this->branchMemory;
    v88.readData = this->branchMemory;
    v88.maxSize = 96;
    memset(&v88.curSize, 0, 16);
    v88.overflowed = false;
    v88.tempValue = v13;
    v89.writeData = this->leafMemory;
    v89.readData = this->leafMemory;
    v89.maxSize = 153;
    memset(&v89.curSize, 0, 16);
    v89.overflowed = false;
    v89.tempValue = v13;
    v87.allowOverflow = true;
    v88.allowOverflow = true;
    v89.allowOverflow = true;
    if ( num > 0 )
    {
      v29 = 0;
      do
      {
        list = this->flags.list;
        v31 = (idAnimator_JointMod *)this->blendStack.list[v29];
        v32 = list[v28];
        if ( (v32 & 2) != 0 && (list[v28] & 1) != 0 )
        {
          idAnimator_JointMod::PreBlendSnapshot(
            this: v31,
            stack: this,
            curTime: SHIDWORD(v13),
            (int)ticksPerSec,
            fraction: v24);
          this->flags.list[v28] = v32 & 0xFB;
          if ( idAnimator_Base::IsContributing(this: v31) )
          {
            v33 = (int)v31->InternalGetMergeBranch_2(this: v31);
            v35 = 0;
            v36 = (v32 & 8) == 0;
            v34 = (idMD6Branch *)v33;
            if ( !v36
              && (v83 != 0
               || common->IsMultiplayer(this: common) && common->IsServer(this: common) && !this->disableSerialization)
              && v27 == 0 )
            {
              this->flags.list[v28] |= 4u;
              if ( v31->GetSerializeType(this: v31) == STYPE_GENERIC )
              {
                v34->left = nullptr;
                idTreeAnimator::StoreTree(
                  model: this->treeAnimator->decl->model,
                  timeMSec: currentTime,
                  (const int)ticksPerSec,
                  animStack: this,
                  node: v34,
                  typesMsg: &v87,
                  branchMsg: &v88,
                  leafMsg: &v89);
                v35 = 1;
                if ( v87.overflowed || v88.overflowed || v89.overflowed )
                {
                  idLib::Warning(fmt: "idAnimStack::BlendStack: Tree too large to serialize.");
                  v27 = 1;
                }
              }
            }
            if ( v35 == 0 )
              idTreeAnimator::UpdateTree(
                model: this->treeAnimator->decl->model,
                timeMSec: currentTime,
                (const int)ticksPerSec,
                node: v34);
            InternalGetEndBranch_2 = v31->InternalGetEndBranch_2;
            if ( v26 != nullptr )
            {
              v38 = (int)InternalGetEndBranch_2(this: v31);
              left = v26->left;
              if ( v38 != 0 )
              {
                if ( left != nullptr )
                {
                  *(_DWORD *)(v38 + 4) = v26;
                  v26 = v34;
                  right = v34->right;
                  HIDWORD(v13) = currentTime;
                }
                else
                {
                  v41 = v26->right;
                  v26 = v34;
                  HIDWORD(v13) = currentTime;
                  *(_DWORD *)(v38 + 4) = v41;
                  right = v34->right;
                }
                this->tree = right;
              }
              else
              {
                if ( left != nullptr )
                {
                  v34->left = v26;
                  v26 = v34;
                  HIDWORD(v13) = currentTime;
                }
                else
                {
                  v42 = v26->right;
                  v26 = v34;
                  HIDWORD(v13) = currentTime;
                  v34->left = v42;
                }
                this->tree = v34;
              }
            }
            else if ( (int)InternalGetEndBranch_2(this: v31) != 0 )
            {
              HIDWORD(v13) = currentTime;
              this->tree = nullptr;
            }
            else
            {
              this->tree = v34->right;
              if ( v34->alphaRate != 0.0 )
                idMD6Branch::UpdateCurrentAlpha(
                  this: v34,
                  timeMSec: currentTime,
                  lastTimeMSec: previousTime,
                  (const int)ticksPerSec);
              HIDWORD(v13) = currentTime;
              v26 = v34;
            }
          }
        }
        else
        {
          list[v28] = v32 & 0xFB;
        }
        ++v28;
        ++v29;
      }
      while ( v28 < this->blendStack.num );
      v14 = gameMsPerFrame;
    }
    if ( v27 != 0 )
    {
      RD_EventBegin(name: "idAnimStack::BlendStack - tree too large");
      LODWORD(v43) = "idAnimStack::BlendStack - tree too large";
      HIDWORD(v43) = 2;
      idPLogScope::idPLogScope(this: &v85, pl: &::pLog, gMask: v43, label: v44);
      for ( i = 0; i < this->blendStack.num; *v46 &= ~4u )
        v46 = &this->flags.list[i++];
      p_skipSerialization = &this->skipSerialization;
      for ( j = 9; j != 0; --j )
        *++p_skipSerialization = false;
      memset(Dst: this->branchMemory, Val: 0, Size: sizeof(this->branchMemory));
      memset(Dst: this->leafMemory, Val: 0, Size: sizeof(this->leafMemory));
      if ( v85.logIndex >= 0 )
      {
        pLog = v85.pLog;
        v50 = &v85.pLog->logEntries.list[v85.logIndex];
        v51 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v50->totalTicks;
        HIDWORD(totalTicks) = v50->parent;
        LODWORD(v53) = v51 - totalTicks;
        v50->totalTicks = v53;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
    }
    if ( v86[0].logIndex >= 0 )
    {
      v54 = v86[0].pLog;
      v55 = &v86[0].pLog->logEntries.list[v86[0].logIndex];
      v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v57 = v55->totalTicks;
      HIDWORD(v57) = v55->parent;
      LODWORD(v58) = v56 - v57;
      v55->totalTicks = v58;
      v54->lastEntry = HIDWORD(v57);
    }
    RD_EventEnd();
    if ( this->tree != nullptr )
    {
      RD_EventBegin(name: "idAnimStack::BlendStack - sync groups");
      LODWORD(v59) = "idAnimStack::BlendStack - sync groups";
      HIDWORD(v59) = 2;
      idPLogScope::idPLogScope(this: &v85, pl: &::pLog, gMask: v59, label: v60);
      idAnimStack::UpdateSynchronization(
        this,
        currentTime: SHIDWORD(v13),
        previousTime,
        gameMsPerFrame: v14,
        (int)ticksPerSec);
      idPLogScope::~idPLogScope(this: &v85);
      RD_EventEnd();
    }
    RD_EventBegin(name: "idTreeAnimator::BlendTree");
    v85.pLog = &::pLog;
    v61 = -1;
    v85.logIndex = -1;
    if ( (::pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v62 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
      idMem::PopHeap(this: &mem);
      v62->label = "idTreeAnimator::BlendTree";
      v62->parent = ::pLog.lastEntry;
      v61 = ::pLog.logEntries.num - 1;
      ::pLog.lastEntry = ::pLog.logEntries.num - 1;
      v85.logIndex = ::pLog.logEntries.num - 1;
      LODWORD(v63) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v62->totalTicks = v63;
    }
    if ( v83 != 0 )
    {
      v64 = v84;
      v84 = (idAnimRecorder *)currentTime;
      v64->Serialize(this: v64, a2: (int *)&v84, a3: game, a4: true);
    }
    tree = this->tree;
    treeAnimator = this->treeAnimator;
    if ( localR != nullptr )
      idTreeAnimator::BlendTreeInternal(
        this: treeAnimator,
        currentTime,
        previousTime,
        gameMsPerFrame,
        (const int)ticksPerSec,
        tree,
        parallelJobList: nullptr,
        localR,
        localS: v80,
        localT: v81,
        localU: v82);
    else
      idTreeAnimator::BlendTreeInternal(
        this: treeAnimator,
        currentTime,
        previousTime,
        gameMsPerFrame,
        (const int)ticksPerSec,
        tree,
        parallelJobList,
        localR: nullptr,
        localS: v80,
        localT: v81,
        localU: v82);
    if ( v61 >= 0 )
    {
      v67 = &::pLog.logEntries.list[v61];
      v68 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      parent = v67->parent;
      LODWORD(v70) = v68 - LODWORD(v67->totalTicks);
      v67->totalTicks = v70;
      ::pLog.lastEntry = parent;
    }
    RD_EventEnd();
    RD_EventBegin(name: "idAnimStack::BlendStack - post");
    v71 = -1;
    v85.pLog = &::pLog;
    v85.logIndex = -1;
    if ( (::pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v72 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
      idMem::PopHeap(this: &mem);
      v72->label = "idAnimStack::BlendStack - post";
      v72->parent = ::pLog.lastEntry;
      v71 = ::pLog.logEntries.num - 1;
      ::pLog.lastEntry = ::pLog.logEntries.num - 1;
      v85.logIndex = ::pLog.logEntries.num - 1;
      LODWORD(v73) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v72->totalTicks = v73;
    }
    v74 = 0;
    if ( this->blendStack.num > 0 )
    {
      v75 = 0;
      do
      {
        if ( (this->flags.list[v74] & 2) != 0 && (this->flags.list[v74] & 1) != 0 )
          this->blendStack.list[v75]->InternalPostBlendTree(this: this->blendStack.list[v75], a2: this, a3: currentTime);
        ++v74;
        ++v75;
      }
      while ( v74 < this->blendStack.num );
    }
    idTreeAnimator::UpdateTime(this: this->treeAnimator, time: currentTime);
    if ( v71 >= 0 )
    {
      v76 = &::pLog.logEntries.list[v71];
      v77 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v78 = v76->parent;
      LODWORD(v79) = v77 - LODWORD(v76->totalTicks);
      v76->totalTicks = v79;
      ::pLog.lastEntry = v78;
    }
    RD_EventEnd();
  }
  else
  {
    v20 = this->treeAnimator;
    if ( v20 != nullptr )
      idTreeAnimator::UpdateTime(this: v20, time: SHIDWORD(v13));
  }
  idMD6BlockAlloc::DeferredFree(this: &this->md6Allocator);
}


// ========================================================================
// __unwind$251851
// EA  : 0x826F6528
// RVA : 0x006F6528
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251851()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 448 + 280));
}


// ========================================================================
// __unwind$251852
// EA  : 0x826F6550
// RVA : 0x006F6550
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251852()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 448 + 128));
}


// ========================================================================
// __unwind$251853
// EA  : 0x826F6578
// RVA : 0x006F6578
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251853()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 448 + 281));
}


// ========================================================================
// __unwind$251855
// EA  : 0x826F65A0
// RVA : 0x006F65A0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251855()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 448 + 282));
}


// ========================================================================
// __unwind$251856
// EA  : 0x826F65C8
// RVA : 0x006F65C8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251856()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 448 + 120));
}


// ========================================================================
// __unwind$251857
// EA  : 0x826F65F0
// RVA : 0x006F65F0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251857()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 448 + 283));
}


// ========================================================================
// __unwind$251858
// EA  : 0x826F6618
// RVA : 0x006F6618
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251858()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 448 + 120));
}


// ========================================================================
// __unwind$251859
// EA  : 0x826F6640
// RVA : 0x006F6640
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251859()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 448 + 284));
}


// ========================================================================
// __unwind$251860
// EA  : 0x826F6668
// RVA : 0x006F6668
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void _unwind_251860()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 448 + 120));
}


// ========================================================================
// `dynamic initializer for 'anim_blendSnapshotDebug''
// EA  : 0x8333F3A0
// RVA : 0x0133F3A0
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_blendSnapshotDebug__()
{
  idCVar::idCVar(
    this: &anim_blendSnapshotDebug,
    name: "anim_blendSnapshotDebug",
    value: "0",
    flags: 2,
    description: "Debug events in idAnimStack::BlendSnapshot\n",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_blendSnapshotDebug__);
}


// ========================================================================
// `dynamic initializer for 'anim_blendSnapshotNoLerp''
// EA  : 0x8333F3F8
// RVA : 0x0133F3F8
// PDB : w:\tech5\engine\gamelib\animstack\animstack.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_blendSnapshotNoLerp__()
{
  idCVar::idCVar(
    this: &anim_blendSnapshotNoLerp,
    name: "anim_blendSnapshotNoLerp",
    value: "0",
    flags: 2,
    description: "Dont lerp between serialized animstacks, for testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_blendSnapshotNoLerp__);
}

