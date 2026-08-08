
// ========================================================================
// ?Parse@idDeclTypeInfoGraph@@UAAXAAVidParser@@@Z
// EA  : 0x8262B6C8
// RVA : 0x0062B6C8
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraph::Parse(idDeclTypeInfoGraph *this, idParser *src)
{
  idDeclTypeInfo::Parse(this, src);
  this->OnDeclParsed(this);
}


// ========================================================================
// ??0idDeclTypeInfoGraph@@QAA@XZ
// EA  : 0x8262B828
// RVA : 0x0062B828
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

idDeclTypeInfoGraph *__fastcall idDeclTypeInfoGraph::idDeclTypeInfoGraph(idDeclTypeInfoGraph *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclTypeInfoGraph_vtbl *)&idDeclTypeInfoGraph::`vftable';
  this->subGraphs.list = nullptr;
  this->subGraphs.granularity = 0;
  this->subGraphs.memTag = 5;
  this->subGraphs.listStatic = 0;
  this->subGraphs.size = 0;
  this->subGraphs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subGraphs);
  this->nodes.list = nullptr;
  this->nodes.granularity = 0;
  this->nodes.memTag = 5;
  this->nodes.listStatic = 0;
  this->nodes.size = 0;
  this->nodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  this->links.list = nullptr;
  this->links.granularity = 0;
  this->links.memTag = 5;
  this->links.listStatic = 0;
  this->links.size = 0;
  this->links.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->links);
  return this;
}


// ========================================================================
// __unwind$224458
// EA  : 0x8262B8C4
// RVA : 0x0062B8C4
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224458()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$224459
// EA  : 0x8262B8EC
// RVA : 0x0062B8EC
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$224460
// EA  : 0x8262B918
// RVA : 0x0062B918
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224460()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// ??1idDeclTypeInfoGraph@@UAA@XZ
// EA  : 0x8262B9B0
// RVA : 0x0062B9B0
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraph::~idDeclTypeInfoGraph(idDeclTypeInfoGraph *this)
{
  idList<idVehicleState *,5> *p_subGraphs; // r29

  this->__vftable = (idDeclTypeInfoGraph_vtbl *)&idDeclTypeInfoGraph::`vftable';
  p_subGraphs = (idList<idVehicleState *,5> *)&this->subGraphs;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->subGraphs);
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->nodes);
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: &this->links);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->links);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  idList<idThread *,58>::Clear(this: p_subGraphs);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$224547
// EA  : 0x8262BA20
// RVA : 0x0062BA20
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224547()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$224548
// EA  : 0x8262BA48
// RVA : 0x0062BA48
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224548()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$224549
// EA  : 0x8262BA74
// RVA : 0x0062BA74
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224549()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// __unwind$224550
// EA  : 0x8262BAA0
// RVA : 0x0062BAA0
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_224550()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 96));
}


// ========================================================================
// ?GetLinksFrom@idDeclTypeInfoGraph@@QBAXPBVidTypeInfoGraphNode@@AAV?$idList@PBVidTypeInfoGraphLink@@$04@@@Z
// EA  : 0x8262BB30
// RVA : 0x0062BB30
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraph::GetLinksFrom(
        idDeclTypeInfoGraph *this,
        const idTypeInfoGraphNode *node,
        idList<enum encounterGroupRole_t,5> *links_in)
{
  int v6; // r29
  int v7; // r30
  const encounterGroupRole_t *v8; // r4
  idTypeInfoGraphNode *v9; // r11

  if ( node != nullptr )
  {
    v6 = 0;
    if ( this->links.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = (const encounterGroupRole_t *)&this->links.list[v7];
        v9 = (idTypeInfoGraphNode *)*v8;
        if ( *v8 != ROLE_NONE )
          v9 = this->nodes.list[LODWORD(v9->position.x)];
        if ( v9 == node )
          idList<idAnimWebBlendTree *,5>::Append(this: links_in, obj: v8);
        ++v6;
        ++v7;
      }
      while ( v6 < this->links.num );
    }
  }
}


// ========================================================================
// ?GetSubGraphFactory@idDeclTypeInfoGraph@@SAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x8262BE30
// RVA : 0x0062BE30
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraph::GetSubGraphFactory()
{
  if ( (_S13 & 1) == 0 )
  {
    _S13 |= 1u;
    idGraphItemFactory<idTypeInfoSubGraph>::idGraphItemFactory<idTypeInfoSubGraph>(this: &subGraphFactory);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraph::GetSubGraphFactory_::_2_::_dynamic_atexit_destructor_for__subGraphFactory__);
  }
  return &subGraphFactory;
}


// ========================================================================
// __unwind$226282
// EA  : 0x8262BEA8
// RVA : 0x0062BEA8
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_226282()
{
  _S13 &= ~1u;
}


// ========================================================================
// ?GetGraphNodeFactory@idDeclTypeInfoGraph@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x8262BED0
// RVA : 0x0062BED0
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraph::GetGraphNodeFactory()
{
  if ( (_S14 & 1) == 0 )
  {
    _S14 |= 1u;
    idGraphItemFactory<idTypeInfoGraphNode>::idGraphItemFactory<idTypeInfoGraphNode>(this: &nodeFactory);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraph::GetGraphNodeFactory_::_2_::_dynamic_atexit_destructor_for__nodeFactory__);
  }
  return &nodeFactory;
}


// ========================================================================
// __unwind$226299
// EA  : 0x8262BF48
// RVA : 0x0062BF48
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_226299()
{
  _S14 &= ~1u;
}


// ========================================================================
// ?GetGraphLinkFactory@idDeclTypeInfoGraph@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x8262BF70
// RVA : 0x0062BF70
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraph::GetGraphLinkFactory()
{
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    idGraphItemFactory<idTypeInfoGraphLink>::idGraphItemFactory<idTypeInfoGraphLink>(this: &linkFactory);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraph::GetGraphLinkFactory_::_2_::_dynamic_atexit_destructor_for__linkFactory__);
  }
  return &linkFactory;
}


// ========================================================================
// __unwind$226316
// EA  : 0x8262BFE8
// RVA : 0x0062BFE8
// PDB : w:\tech5\engine\decls\decltypeinfograph.cpp
// ========================================================================

void _unwind_226316()
{
  _S15 &= ~1u;
}

