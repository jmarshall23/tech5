
// ========================================================================
// ?Shutdown@idTraceModelRecycler@@QAAXXZ
// EA  : 0x82769BE8
// RVA : 0x00769BE8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void __fastcall idTraceModelRecycler::Shutdown(idTraceModelRecycler *this)
{
  int v2; // r30
  int v3; // r31
  idRecycledTraceModel *v4; // r8
  idRecycledTraceModel **list; // r4
  int *p_num; // r31
  int i; // r30
  void *v8; // r4

  v2 = 0;
  if ( this->allocated.num > 0 )
  {
    v3 = 0;
    do
    {
      idTraceModel::operator delete(p: this->allocated.list[v3]->trm);
      ++v2;
      v4 = this->allocated.list[v3++];
      v4->trm = nullptr;
    }
    while ( v2 < this->allocated.num );
  }
  if ( this->allocated.listStatic == 0 || this->allocated.listStatic == 2 )
  {
    list = this->allocated.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->allocated.list = nullptr;
    this->allocated.size = 0;
  }
  p_num = &this->allocated.num;
  this->allocated.num = 0;
  for ( i = 3; i != 0; --i )
  {
    if ( *((_BYTE *)p_num + 27) == 0 || *((_BYTE *)p_num + 27) == 2 )
    {
      v8 = (void *)p_num[3];
      if ( v8 != nullptr )
        idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
      p_num[3] = 0;
      p_num[5] = 0;
    }
    p_num += 4;
    *p_num = 0;
  }
  idBlockAlloc<idMD6LeafPlay,32,18>::Shutdown((idBlockAlloc<idMD6LeafPlay,32,18> *)this);
}


// ========================================================================
// ??1idTraceModelRecycler@@QAA@XZ
// EA  : 0x82769CE0
// RVA : 0x00769CE0
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void __fastcall idTraceModelRecycler::~idTraceModelRecycler(idTraceModelRecycler *this)
{
  idTraceModelRecycler::Shutdown(this);
  `eh vector destructor iterator'(
    ptr: this->free,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->allocated);
  idBlockAlloc<idMD6LeafPlay,32,18>::Shutdown((idBlockAlloc<idMD6LeafPlay,32,18> *)this);
}


// ========================================================================
// __unwind$245843
// EA  : 0x82769D44
// RVA : 0x00769D44
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void _unwind_245843()
{
  int v0; // r12

  idBlockAlloc<idRecycledTraceModel,64,13>::~idBlockAlloc<idRecycledTraceModel,64,13>(this: *(idBlockAlloc<idMD6LeafPlay,32,18> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$245844
// EA  : 0x82769D6C
// RVA : 0x00769D6C
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void _unwind_245844()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$245845
// EA  : 0x82769D98
// RVA : 0x00769D98
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void _unwind_245845()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 36),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?GetTraceModel@idTraceModelRecycler@@QAAPAVidRecycledTraceModel@@XZ
// EA  : 0x82769DD8
// RVA : 0x00769DD8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

idBlockAlloc<idRecycledTraceModel,64,13>::element_t *__fastcall idTraceModelRecycler::GetTraceModel(
        idTraceModelRecycler *this)
{
  int num; // r11
  idList<idRecycledTraceModel *,13> *free; // r11
  int v4; // r10
  bool v5; // cr32
  idRecycledTraceModel **v6; // r9
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *result; // r3
  int v8; // r9
  int v9; // r9
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *v10; // r30
  _DWORD *v11; // r3
  _DWORD *v12; // r9
  idSysMutex *p_viewNoteMutex; // r10
  int v14; // ctr
  idRecycledTraceModel *v15; // r10
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *v16; // [sp+50h] [-20h] BYREF

  num = this->free[0].num;
  if ( num != 0 )
  {
    v4 = num - 1;
    v5 = num - 1 < 0;
    v6 = &this->free[0].list[num];
    free = this->free;
    result = (idBlockAlloc<idRecycledTraceModel,64,13>::element_t *)*(v6 - 1);
    if ( !v5 )
    {
      v8 = free->num;
      if ( v4 < v8 )
      {
        v9 = v8 - 1;
        free->num = v9;
        if ( v4 != v9 )
          free->list[v4] = free->list[v9];
      }
    }
  }
  else
  {
    v10 = idBlockAlloc<idRecycledTraceModel,64,13>::Alloc(this: &this->allocator);
    v16 = v10;
    v11 = idTraceModel::operator new(size: 0x600u);
    if ( v11 != nullptr )
    {
      v11[368] = 0;
      v11[369] = 0;
      v12 = v11 + 375;
      v11[370] = 0;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      v11[371] = 0;
      v14 = 6;
      v11[372] = 0;
      *((float *)v11 + 373) = 0.0;
      *((float *)v11 + 374) = 0.0;
      *((float *)v11 + 375) = 0.0;
      do
      {
        ++p_viewNoteMutex;
        *++v12 = p_viewNoteMutex->handle;
        --v14;
      }
      while ( v14 != 0 );
      *((float *)v11 + 382) = 0.0;
      *((_BYTE *)v11 + 1532) = 0;
      *((_BYTE *)v11 + 1535) = 0;
      v15 = (idRecycledTraceModel *)v11;
      *((_BYTE *)v11 + 1534) = 0;
      *((_BYTE *)v11 + 1533) = 0;
    }
    else
    {
      v15 = nullptr;
    }
    v10->data = v15;
    *(_DWORD *)&v10->buffer[4] = idList<idAnimWebBlendTree *,5>::Append(
                                   this: (idList<enum encounterGroupRole_t,5> *)&this->allocated,
                                   obj: (const encounterGroupRole_t *)&v16);
    return v10;
  }
  return result;
}


// ========================================================================
// ?RecycleTraceModel@idTraceModelRecycler@@QAAXPAVidRecycledTraceModel@@_N@Z
// EA  : 0x82769F10
// RVA : 0x00769F10
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void __fastcall idTraceModelRecycler::RecycleTraceModel(
        idTraceModelRecycler *this,
        idRecycledTraceModel *recycledTrm,
        bool defer,
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
        idRecycledTraceModel *a14)
{
  a14 = recycledTrm;
  if ( defer )
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->free[2],
      obj: (const encounterGroupRole_t *)&a14);
  else
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)this->free,
      obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?UpdateDeferredFreed@idTraceModelRecycler@@QAAXXZ
// EA  : 0x82769F60
// RVA : 0x00769F60
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.cpp
// ========================================================================

void __fastcall idTraceModelRecycler::UpdateDeferredFreed(idTraceModelRecycler *this)
{
  unsigned __int8 *p_listStatic; // r30
  int i; // r26
  int v3; // r29
  int v4; // r31
  void *v5; // r4

  p_listStatic = &this->free[1].listStatic;
  for ( i = 2; i != 0; --i )
  {
    v3 = 0;
    if ( *(int *)(p_listStatic - 11) > 0 )
    {
      v4 = 0;
      do
      {
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)(p_listStatic - 31),
          obj: (const encounterGroupRole_t *)(*(_DWORD *)(p_listStatic - 15) + v4));
        ++v3;
        v4 += 4;
      }
      while ( v3 < *(_DWORD *)(p_listStatic - 11) );
    }
    if ( *p_listStatic == 0 || *p_listStatic == 2 )
    {
      v5 = *(void **)(p_listStatic - 15);
      if ( v5 != nullptr )
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      *(_DWORD *)(p_listStatic - 15) = 0;
      *(_DWORD *)(p_listStatic - 7) = 0;
    }
    *(_DWORD *)(p_listStatic - 11) = 0;
    p_listStatic += 16;
  }
}

