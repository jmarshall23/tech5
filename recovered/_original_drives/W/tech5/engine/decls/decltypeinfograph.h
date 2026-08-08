
// ========================================================================
// ?Create@?$idGraphItemFactory@VidTypeInfoSubGraph@@@@QBAPAVidTypeInfoSubGraph@@PBD@Z
// EA  : 0x8262B708
// RVA : 0x0062B708
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphLink *__fastcall idGraphItemFactory<idTypeInfoSubGraph>::Create(
        idGraphItemFactory<idTypeInfoGraphLink> *this,
        const char *itemClassName)
{
  int v4; // r30
  int i; // r29
  const char *str; // r3
  int v7; // r3
  char v8; // r11
  idTypeInfoGraphLink *v10; // r3
  idTypeInfoGraphLink *v11; // r31

  v4 = 0;
  if ( this->registry.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    str = this->registry.list[i].type.className.str;
    if ( str == itemClassName || (v7 = idStr::Cmp(s1: str, s2: itemClassName), v8 = 0, v7 == 0) )
      v8 = 1;
    if ( v8 != 0 )
      break;
    if ( ++v4 >= this->registry.num )
      return nullptr;
  }
  v10 = this->registry.list[v4].creationFunction();
  v11 = v10;
  if ( v10 != nullptr )
    idAtomicString::Set(this: &v10->className, str_: itemClassName);
  return v11;
}


// ========================================================================
// ?GetSubGraphColor@idDeclTypeInfoGraph@@UBA?AVidColor@@PBVidTypeInfoSubGraph@@@Z
// EA  : 0x8262B948
// RVA : 0x0062B948
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idDeclTypeInfoGraph *__fastcall idDeclTypeInfoGraph::GetSubGraphColor(
        idDeclTypeInfoGraph *this,
        idColor *result,
        idColor *link)
{
  (*(void (__fastcall **)(idDeclTypeInfoGraph *, idColor *))(LODWORD(link->r) + 4))(a1: this, a2: link);
  return this;
}


// ========================================================================
// ?GetNodeInfo@idDeclTypeInfoGraph@@UBAXPBVidTypeInfoGraphNode@@AAVidStr@@AA_N@Z
// EA  : 0x8262B988
// RVA : 0x0062B988
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void __fastcall idDeclTypeInfoGraph::GetNodeInfo(
        idDeclTypeInfoGraph *this,
        idTypeInfoGraphNode *node,
        idStr *info,
        bool *showSelected)
{
  node->GetInfo(this: node, a2: info, a3: showSelected);
}


// ========================================================================
// ??0?$idGraphItemFactory@VidTypeInfoSubGraph@@@@QAA@XZ
// EA  : 0x8262BBB8
// RVA : 0x0062BBB8
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idGraphItemFactory<idTypeInfoSubGraph>::idGraphItemFactory<idTypeInfoSubGraph>(
        idGraphItemFactory<idTypeInfoSubGraph> *this)
{
  this->__vftable = (idGraphItemFactory<idTypeInfoSubGraph>_vtbl *)&idGraphItemFactory<idTypeInfoSubGraph>::`vftable';
  this->registry.list = nullptr;
  this->registry.granularity = 0;
  this->registry.memTag = 87;
  this->registry.listStatic = 0;
  this->registry.size = 0;
  this->registry.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->registry);
  return this;
}


// ========================================================================
// ??0?$idGraphItemFactory@VidTypeInfoGraphNode@@@@QAA@XZ
// EA  : 0x8262BC18
// RVA : 0x0062BC18
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idGraphItemFactory<idTypeInfoGraphNode>::idGraphItemFactory<idTypeInfoGraphNode>(
        idGraphItemFactory<idTypeInfoGraphNode> *this)
{
  this->__vftable = (idGraphItemFactory<idTypeInfoGraphNode>_vtbl *)&idGraphItemFactory<idTypeInfoGraphNode>::`vftable';
  this->registry.list = nullptr;
  this->registry.granularity = 0;
  this->registry.memTag = 87;
  this->registry.listStatic = 0;
  this->registry.size = 0;
  this->registry.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->registry);
  return this;
}


// ========================================================================
// ??0?$idGraphItemFactory@VidTypeInfoGraphLink@@@@QAA@XZ
// EA  : 0x8262BC78
// RVA : 0x0062BC78
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idGraphItemFactory<idTypeInfoGraphLink>::idGraphItemFactory<idTypeInfoGraphLink>(
        idGraphItemFactory<idTypeInfoGraphLink> *this)
{
  this->__vftable = (idGraphItemFactory<idTypeInfoGraphLink>_vtbl *)&idGraphItemFactory<idTypeInfoGraphLink>::`vftable';
  this->registry.list = nullptr;
  this->registry.granularity = 0;
  this->registry.memTag = 87;
  this->registry.listStatic = 0;
  this->registry.size = 0;
  this->registry.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->registry);
  return this;
}


// ========================================================================
// ?GetMySubGraphFactory@idDeclTypeInfoGraph@@UBAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x8262C008
// RVA : 0x0062C008
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraph::GetMySubGraphFactory(idDeclTypeInfoGraph *this)
{
  return idDeclTypeInfoGraph::GetSubGraphFactory();
}


// ========================================================================
// ?GetMyGraphNodeFactory@idDeclTypeInfoGraph@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x8262C010
// RVA : 0x0062C010
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraph::GetMyGraphNodeFactory(
        idDeclTypeInfoGraph *this)
{
  return idDeclTypeInfoGraph::GetGraphNodeFactory();
}


// ========================================================================
// ?GetMyGraphLinkFactory@idDeclTypeInfoGraph@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x8262C018
// RVA : 0x0062C018
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraph::GetMyGraphLinkFactory(
        idDeclTypeInfoGraph *this)
{
  return idDeclTypeInfoGraph::GetGraphLinkFactory();
}


// ========================================================================
// ??1idTypeInfoGraphItem@@UAA@XZ
// EA  : 0x82BBE900
// RVA : 0x00BBE900
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void __fastcall idTypeInfoGraphItem::~idTypeInfoGraphItem(idTypeInfoGraphNode *this)
{
  this->__vftable = (idTypeInfoGraphNode_vtbl *)&idTypeInfoGraphItem::`vftable';
}


// ========================================================================
// ?GetColor@idTypeInfoSubGraphTest2@@UBA?AVidColor@@XZ
// EA  : 0x82BBE910
// RVA : 0x00BBE910
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoSubGraphTest2 *__fastcall idTypeInfoSubGraphTest2::GetColor(idTypeInfoSubGraphTest2 *this, idColor *result)
{
  float g; // r8
  float b; // r7
  float a; // r6

  g = idColor::colorWhite.g;
  b = idColor::colorWhite.b;
  a = idColor::colorWhite.a;
  this->__vftable = (idTypeInfoSubGraphTest2_vtbl *)LODWORD(idColor::colorWhite.r);
  *(float *)&this->name.str = g;
  *(float *)&this->className.str = b;
  *(float *)&this->subnodes.list = a;
  return this;
}


// ========================================================================
// ?GetDisplayName@idTypeInfoGraphItem@@UBAXAAVidStr@@@Z
// EA  : 0x82BBE940
// RVA : 0x00BBE940
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void __fastcall idTypeInfoGraphItem::GetDisplayName(idTypeInfoGraphItem *this, idStr *displayName)
{
  idStr::operator=(this: displayName, text: this->name.str);
}


// ========================================================================
// ?GetColor@idTypeInfoGraphNode@@UBA?AVidColor@@XZ
// EA  : 0x82BBE950
// RVA : 0x00BBE950
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphNode *__fastcall idTypeInfoGraphNode::GetColor(idTypeInfoGraphNode *this, idColor *result)
{
  float g; // r8
  float b; // r7
  float a; // r6

  g = idTypeInfoGraphNode::baseColor.g;
  b = idTypeInfoGraphNode::baseColor.b;
  a = idTypeInfoGraphNode::baseColor.a;
  this->__vftable = (idTypeInfoGraphNode_vtbl *)LODWORD(idTypeInfoGraphNode::baseColor.r);
  *(float *)&this->name.str = g;
  *(float *)&this->className.str = b;
  this->position.x = a;
  return this;
}


// ========================================================================
// ?GetDisplayName@idTypeInfoGraphLink@@UBAXAAVidStr@@@Z
// EA  : 0x82BBE980
// RVA : 0x00BBE980
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void __fastcall idTypeInfoGraphLink::GetDisplayName(idTypeInfoGraphLink *this, idStr *displayName)
{
  idStr::operator=(this: displayName, text: &byte_8200D768);
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoGraphNodeTest@@VidTypeInfoGraphNode@@@@SAPAVidTypeInfoGraphNode@@XZ
// EA  : 0x82BBED30
// RVA : 0x00BBED30
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphNode *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::CreateInstance()
{
  idTypeInfoGraphNode *result; // r3

  result = (idTypeInfoGraphNode *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x14u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (idTypeInfoGraphNode_vtbl *)&idTypeInfoGraphItem::`vftable';
  result->name.str = &byte_8200D768;
  result->className.str = &byte_8200D768;
  result->position.x = 0.0;
  result->position.y = 0.0;
  result->__vftable = (idTypeInfoGraphNode_vtbl *)&idTypeInfoGraphNodeTest::`vftable';
  return result;
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoGraphNodeTest2@@VidTypeInfoGraphNode@@@@SAPAVidTypeInfoGraphNode@@XZ
// EA  : 0x82BBEDD0
// RVA : 0x00BBEDD0
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphNode *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>::CreateInstance()
{
  idTypeInfoGraphNode *result; // r3

  result = (idTypeInfoGraphNode *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x34u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (idTypeInfoGraphNode_vtbl *)&idTypeInfoGraphItem::`vftable';
  result->name.str = &byte_8200D768;
  result->className.str = &byte_8200D768;
  result->position.x = 0.0;
  result->position.y = 0.0;
  result->__vftable = (idTypeInfoGraphNode_vtbl *)&idTypeInfoGraphNodeTest2::`vftable';
  result[1].className.str = (const char *)20;
  result[1].name.str = (const char *)&result[1].position;
  result[1].__vftable = nullptr;
  HIBYTE(result[1].position.x) = 0;
  return result;
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoGraphLinkTest@@VidTypeInfoGraphLink@@@@SAPAVidTypeInfoGraphLink@@XZ
// EA  : 0x82BBEE90
// RVA : 0x00BBEE90
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphLink *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::CreateInstance()
{
  idTypeInfoGraphLink *result; // r3

  result = (idTypeInfoGraphLink *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x18u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (idTypeInfoGraphLink_vtbl *)&idTypeInfoGraphItem::`vftable';
  result->name.str = &byte_8200D768;
  result->className.str = &byte_8200D768;
  result->startNodeIndex = -1;
  result->endNodeIndex = -1;
  result->__vftable = (idTypeInfoGraphLink_vtbl *)&idTypeInfoGraphLinkTest::`vftable';
  HIBYTE(result[1].__vftable) = 1;
  return result;
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoGraphLinkTest2@@VidTypeInfoGraphLink@@@@SAPAVidTypeInfoGraphLink@@XZ
// EA  : 0x82BBF130
// RVA : 0x00BBF130
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoGraphLink *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>::CreateInstance()
{
  idTypeInfoGraphLink *result; // r3

  result = (idTypeInfoGraphLink *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x14u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (idTypeInfoGraphLink_vtbl *)&idTypeInfoGraphItem::`vftable';
  result->name.str = &byte_8200D768;
  result->className.str = &byte_8200D768;
  result->startNodeIndex = -1;
  result->endNodeIndex = -1;
  result->__vftable = (idTypeInfoGraphLink_vtbl *)&idTypeInfoGraphLinkTest2::`vftable';
  return result;
}


// ========================================================================
// ??0idTypeInfoSubGraph@@QAA@XZ
// EA  : 0x82BBF4D8
// RVA : 0x00BBF4D8
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoSubGraph *__fastcall idTypeInfoSubGraph::idTypeInfoSubGraph(idTypeInfoSubGraph *this)
{
  this->__vftable = (idTypeInfoSubGraph_vtbl *)&idTypeInfoGraphItem::`vftable';
  this->name.str = &byte_8200D768;
  this->className.str = &byte_8200D768;
  this->__vftable = (idTypeInfoSubGraph_vtbl *)&idTypeInfoSubGraph::`vftable';
  this->subnodes.list = nullptr;
  this->subnodes.granularity = 0;
  this->subnodes.memTag = 5;
  this->subnodes.listStatic = 0;
  this->subnodes.size = 0;
  this->subnodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subnodes);
  this->position.x = 0.0;
  this->position.y = 0.0;
  return this;
}


// ========================================================================
// __unwind$492022
// EA  : 0x82BBF590
// RVA : 0x00BBF590
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void _unwind_492022()
{
  int v0; // r12

  idTypeInfoGraphItem::~idTypeInfoGraphItem(this: *(idTypeInfoGraphNode **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetColor@idTypeInfoSubGraph@@UBA?AVidColor@@XZ
// EA  : 0x82BBF5B8
// RVA : 0x00BBF5B8
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoSubGraph *__fastcall idTypeInfoSubGraph::GetColor(idTypeInfoSubGraph *this, idColor *result)
{
  float g; // r8
  float b; // r7
  float a; // r6

  g = idTypeInfoSubGraph::baseColor.g;
  b = idTypeInfoSubGraph::baseColor.b;
  a = idTypeInfoSubGraph::baseColor.a;
  this->__vftable = (idTypeInfoSubGraph_vtbl *)LODWORD(idTypeInfoSubGraph::baseColor.r);
  *(float *)&this->name.str = g;
  *(float *)&this->className.str = b;
  *(float *)&this->subnodes.list = a;
  return this;
}


// ========================================================================
// ??1idTypeInfoSubGraph@@UAA@XZ
// EA  : 0x82BBF5F0
// RVA : 0x00BBF5F0
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void __fastcall idTypeInfoSubGraph::~idTypeInfoSubGraph(idTypeInfoSubGraph *this)
{
  this->__vftable = (idTypeInfoSubGraph_vtbl *)&idTypeInfoSubGraph::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subnodes);
  this->__vftable = (idTypeInfoSubGraph_vtbl *)&idTypeInfoGraphItem::`vftable';
}


// ========================================================================
// __unwind$492064
// EA  : 0x82BBF648
// RVA : 0x00BBF648
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void _unwind_492064()
{
  int v0; // r12

  idTypeInfoGraphItem::~idTypeInfoGraphItem(this: *(idTypeInfoGraphNode **)(v0 - 112 + 132));
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoSubGraphTest@@VidTypeInfoSubGraph@@@@SAPAVidTypeInfoSubGraph@@XZ
// EA  : 0x82BBF810
// RVA : 0x00BBF810
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoSubGraph *__fastcall idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::CreateInstance()
{
  idTypeInfoSubGraph *v0; // r3
  idTypeInfoSubGraph *v1; // r30

  v0 = (idTypeInfoSubGraph *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x38u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  idTypeInfoSubGraph::idTypeInfoSubGraph(this: v0);
  v1->__vftable = (idTypeInfoSubGraph_vtbl *)&idTypeInfoSubGraphTest::`vftable';
  *(float *)&v1[1].subnodes.list = -1.0;
  *(float *)&v1[1].className.str = -1.0;
  *(float *)&v1[1].name.str = -1.0;
  *(float *)&v1[1].__vftable = -1.0;
  HIBYTE(v1[1].subnodes.num) = 0;
  return v1;
}


// ========================================================================
// __unwind$492164
// EA  : 0x82BBF8BC
// RVA : 0x00BBF8BC
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void _unwind_492164()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?CreateInstance@?$idRegisterInGraphItemFactory@VidTypeInfoSubGraphTest2@@VidTypeInfoSubGraph@@@@SAPAVidTypeInfoSubGraph@@XZ
// EA  : 0x82BBF8F0
// RVA : 0x00BBF8F0
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idTypeInfoSubGraph *__fastcall idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>::CreateInstance()
{
  idTypeInfoSubGraph *v0; // r3
  _DWORD *v1; // r30

  v0 = (idTypeInfoSubGraph *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x24u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  idTypeInfoSubGraph::idTypeInfoSubGraph(this: v0);
  *v1 = &idTypeInfoSubGraphTest2::`vftable';
  return (idTypeInfoSubGraph *)v1;
}


// ========================================================================
// __unwind$492197_0
// EA  : 0x82BBF974
// RVA : 0x00BBF974
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

void _unwind_492197_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoSubGraphTest@@VidTypeInfoSubGraph@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@1@Z
// EA  : 0x82BC06D8
// RVA : 0x00BC06D8
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph> *__fastcall idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>(
        idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoSubGraph> *graphItemFactory,
        idGraphItemFactory<idTypeInfoSubGraph> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::CreateInstance;
  return this;
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoSubGraphTest2@@VidTypeInfoSubGraph@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@1@Z
// EA  : 0x82BC07A0
// RVA : 0x00BC07A0
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph> *__fastcall idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>::idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>(
        idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoSubGraph> *graphItemFactory,
        idGraphItemFactory<idTypeInfoSubGraph> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>::CreateInstance;
  return this;
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoGraphNodeTest@@VidTypeInfoGraphNode@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@1@Z
// EA  : 0x82BC0868
// RVA : 0x00BC0868
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode> *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>(
        idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoGraphNode> *graphItemFactory,
        idGraphItemFactory<idTypeInfoGraphNode> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::CreateInstance;
  return this;
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoGraphNodeTest2@@VidTypeInfoGraphNode@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@1@Z
// EA  : 0x82BC0930
// RVA : 0x00BC0930
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode> *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>::idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>(
        idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoGraphNode> *graphItemFactory,
        idGraphItemFactory<idTypeInfoGraphNode> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: (idList<idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair,87> *)&globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = (idTypeInfoGraphLink *(__fastcall *)())idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>::CreateInstance;
  return this;
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoGraphLinkTest@@VidTypeInfoGraphLink@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@1@Z
// EA  : 0x82BC09F8
// RVA : 0x00BC09F8
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink> *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>(
        idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoGraphLink> *graphItemFactory,
        idGraphItemFactory<idTypeInfoGraphLink> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: &graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: &globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::CreateInstance;
  return this;
}


// ========================================================================
// ??0?$idRegisterInGraphItemFactory@VidTypeInfoGraphLinkTest2@@VidTypeInfoGraphLink@@@@IAA@PBD0AAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@1@Z
// EA  : 0x82BC0AC0
// RVA : 0x00BC0AC0
// PDB : w:\tech5\engine\decls\decltypeinfograph.h
// ========================================================================

idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink> *__fastcall idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>::idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>(
        idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink> *this,
        const char *className,
        const char *diplayedName,
        idGraphItemFactory<idTypeInfoGraphLink> *graphItemFactory,
        idGraphItemFactory<idTypeInfoGraphLink> *globalItemFactory)
{
  char v9; // r11
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink>::idTypeCreationPair *v11; // r3
  idAtomicString v13; // [sp+50h] [-30h] BYREF
  idAtomicString v14; // [sp+54h] [-2Ch] BYREF

  idAtomicString::Set(this: &v13, str_: className);
  idAtomicString::Set(this: &v14, str_: diplayedName);
  if ( v14.str == &byte_8200D768 || (v9 = 0, *v14.str == 0) )
    v9 = 1;
  if ( v9 != 0 )
    v14.str = v13.str;
  v10 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: &graphItemFactory->registry);
  v10->type.className = v13;
  v10->type.displayedName = v14;
  v10->creationFunction = idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>::CreateInstance;
  v11 = idList<idGraphItemFactory<idTypeInfoSubGraph>::idTypeCreationPair,87>::Alloc(this: &globalItemFactory->registry);
  v11->type.className = v13;
  v11->type.displayedName = v14;
  v11->creationFunction = idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>::CreateInstance;
  return this;
}

