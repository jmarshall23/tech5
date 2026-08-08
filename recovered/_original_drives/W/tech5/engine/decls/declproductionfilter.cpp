
// ========================================================================
// ?Parse@idDeclProductionFilter@@UAAXAAVidParser@@@Z
// EA  : 0x82629568
// RVA : 0x00629568
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void __fastcall idDeclProductionFilter::Parse(idDeclProductionFilter *this, idParser *src)
{
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  idStr *list; // r4
  unsigned int num; // r5
  idStr *v9; // r4
  unsigned int v10; // r5
  idSort_Quick<idStr,idSort_QuickDefault<idStr> > v11; // [sp+50h] [-30h] BYREF
  idSort_Quick<idStr,idSort_QuickDefault<idStr> > v12; // [sp+54h] [-2Ch] BYREF
  idStr *v13; // [sp+58h] [-28h]

  idDeclTypeInfo::Parse(this, src);
  v11.__vftable = (idSort_Quick<idStr,idSort_QuickDefault<idStr> >_vtbl *)&idSort_QuickDefault<idStr>::`vftable';
  list = this->entityFilter.list;
  if ( list != nullptr )
  {
    num = this->entityFilter.num;
    v13 = this->entityFilter.list;
    idSort_Quick<idStr,idSort_QuickDefault<idStr>>::Sort(this: &v11, base: list, num, a4: v6, a5: v5, a6: v4, a7: v3);
  }
  v12.__vftable = (idSort_Quick<idStr,idSort_QuickDefault<idStr> >_vtbl *)&idSort_QuickDefault<idStr>::`vftable';
  LODWORD(v3) = &idSort<idStr>::`vftable';
  v11.__vftable = (idSort_Quick<idStr,idSort_QuickDefault<idStr> >_vtbl *)&idSort<idStr>::`vftable';
  v9 = this->entityRenderModelFilter.list;
  if ( v9 != nullptr )
  {
    v10 = this->entityRenderModelFilter.num;
    v13 = this->entityRenderModelFilter.list;
    idSort_Quick<idStr,idSort_QuickDefault<idStr>>::Sort(this: &v12, base: v9, num: v10, a4: v6, a5: v5, a6: v4, a7: v3);
  }
}


// ========================================================================
// __unwind$219569
// EA  : 0x826295F0
// RVA : 0x006295F0
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219569()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$219570
// EA  : 0x82629618
// RVA : 0x00629618
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219570()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 128 + 84));
}


// ========================================================================
// ??0idDeclProductionFilter@@QAA@XZ
// EA  : 0x82629648
// RVA : 0x00629648
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

idDeclProductionFilter *__fastcall idDeclProductionFilter::idDeclProductionFilter(idDeclProductionFilter *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclProductionFilter_vtbl *)&idDeclProductionFilter::`vftable';
  this->entityFilter.granularity = 0;
  this->entityFilter.memTag = 5;
  this->entityFilter.listStatic = 0;
  this->entityFilter.list = nullptr;
  this->entityFilter.size = 0;
  this->entityFilter.num = 0;
  this->entityRenderModelFilter.granularity = 0;
  this->entityRenderModelFilter.memTag = 5;
  this->entityRenderModelFilter.listStatic = 0;
  this->entityRenderModelFilter.list = nullptr;
  this->entityRenderModelFilter.size = 0;
  this->entityRenderModelFilter.num = 0;
  return this;
}


// ========================================================================
// __unwind$219711
// EA  : 0x826296D8
// RVA : 0x006296D8
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219711()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219712
// EA  : 0x82629700
// RVA : 0x00629700
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219712()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ??1idDeclProductionFilter@@UAA@XZ
// EA  : 0x82629748
// RVA : 0x00629748
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void __fastcall idDeclProductionFilter::~idDeclProductionFilter(idDeclProductionFilter *this)
{
  idStr *list; // r3
  idStr *v3; // r3

  this->__vftable = (idDeclProductionFilter_vtbl *)&idDeclProductionFilter::`vftable';
  if ( this->entityRenderModelFilter.listStatic == 0 || this->entityRenderModelFilter.listStatic == 2 )
  {
    list = this->entityRenderModelFilter.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->entityRenderModelFilter.size);
    this->entityRenderModelFilter.list = nullptr;
    this->entityRenderModelFilter.size = 0;
  }
  this->entityRenderModelFilter.num = 0;
  if ( this->entityFilter.listStatic == 0 || this->entityFilter.listStatic == 2 )
  {
    v3 = this->entityFilter.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->entityFilter.size);
    this->entityFilter.list = nullptr;
    this->entityFilter.size = 0;
  }
  this->entityFilter.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$219765
// EA  : 0x826297E8
// RVA : 0x006297E8
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219765()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219766
// EA  : 0x82629810
// RVA : 0x00629810
// PDB : w:\tech5\engine\decls\declproductionfilter.cpp
// ========================================================================

void _unwind_219766()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}

