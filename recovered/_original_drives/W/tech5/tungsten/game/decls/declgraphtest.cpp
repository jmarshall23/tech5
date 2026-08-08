
// ========================================================================
// ?ToggleHighlightDeadEndLinks@idDeclTypeInfoGraphTest@@CAXPAVidDeclTypeInfoGraph@@@Z
// EA  : 0x82BBE880
// RVA : 0x00BBE880
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::ToggleHighlightDeadEndLinks(idDeclTypeInfoGraph *graph)
{
  int *v1; // r3
  int *v2; // r31
  int v3; // r30
  unsigned __int8 v4; // r3

  v1 = (int *)_RTDynamicCast(
                inptr: graph,
                VfDelta: 0,
                SrcType: &idDeclTypeInfoGraph `RTTI Type Descriptor',
                TargetType: &idDeclTypeInfoGraphTest `RTTI Type Descriptor',
                isReference: 0);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v3 = *v1;
    v4 = (*(int (__fastcall **)(int *))(*v1 + 136))(a1: v1);
    (*(void (__fastcall **)(int *, bool))(v3 + 140))(a1: v2, a2: (_cntlzw(v4) & 0x20) != 0);
  }
}


// ========================================================================
// ?DisableLinks@idDeclTypeInfoGraphTest@@CAXPAVidDeclTypeInfoGraph@@ABV?$idList@PAVidTypeInfoGraphLink@@$04@@@Z
// EA  : 0x82BBEC30
// RVA : 0x00BBEC30
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::DisableLinks(
        idDeclTypeInfoGraph *graph,
        const idList<idTypeInfoGraphLink *,5> *selectedLinks)
{
  int v3; // r27
  int v4; // r31
  _BYTE *v5; // r3

  v3 = 0;
  if ( selectedLinks->num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = _RTDynamicCast(
             inptr: selectedLinks->list[v4],
             VfDelta: 0,
             SrcType: &idTypeInfoGraphLink `RTTI Type Descriptor',
             TargetType: &idTypeInfoGraphLinkTest `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
        v5[20] = 0;
      ++v3;
      ++v4;
    }
    while ( v3 < selectedLinks->num );
  }
}


// ========================================================================
// ?EnableLinks@idDeclTypeInfoGraphTest@@CAXPAVidDeclTypeInfoGraph@@ABV?$idList@PAVidTypeInfoGraphLink@@$04@@@Z
// EA  : 0x82BBECB0
// RVA : 0x00BBECB0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::EnableLinks(
        idDeclTypeInfoGraph *graph,
        const idList<idTypeInfoGraphLink *,5> *selectedLinks)
{
  int v3; // r27
  int v4; // r31
  _BYTE *v5; // r3

  v3 = 0;
  if ( selectedLinks->num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = _RTDynamicCast(
             inptr: selectedLinks->list[v4],
             VfDelta: 0,
             SrcType: &idTypeInfoGraphLink `RTTI Type Descriptor',
             TargetType: &idTypeInfoGraphLinkTest `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
        v5[20] = 1;
      ++v3;
      ++v4;
    }
    while ( v3 < selectedLinks->num );
  }
}


// ========================================================================
// ?GetNodeColor@idDeclTypeInfoGraphTest@@UBA?AVidColor@@PBVidTypeInfoGraphNode@@@Z
// EA  : 0x82BBF298
// RVA : 0x00BBF298
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idDeclTypeInfoGraphTest *__fastcall idDeclTypeInfoGraphTest::GetNodeColor(
        idDeclTypeInfoGraphTest *this,
        idDeclTypeInfoGraph *result,
        idColor *node)
{
  int v6; // r9
  const char *v7; // r8
  idResource *v8; // r7
  idResource *v9; // r8
  float v10; // r7
  int v11; // r6
  int v12; // r9
  const char *v13; // r8
  idResource *v14; // r7
  idList<enum encounterGroupRole_t,5> v16; // [sp+50h] [-60h] BYREF
  float v17[4]; // [sp+60h] [-50h] BYREF
  float v18; // [sp+70h] [-40h]
  int v19; // [sp+74h] [-3Ch]
  float v20; // [sp+78h] [-38h]
  float v21; // [sp+7Ch] [-34h]

  (*(void (__fastcall **)(float *, idColor *))(LODWORD(node->r) + 4))(a1: v17, a2: node);
  if ( ((unsigned __int8 (__fastcall *)(idDeclTypeInfoGraph *))result->__vftable[1].dtr_idResource)(a1: result) != 0 )
  {
    memset(&v16, 0, 14);
    *(_WORD *)&v16.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v16);
    idDeclTypeInfoGraph::GetLinksFrom(this: result, (const idTypeInfoGraphNode *)node, links_in: &v16);
    if ( v16.num <= 0 )
    {
      v21 = v17[3];
      v20 = (float)1.0 - v17[2];
      *(float *)&v19 = (float)1.0 - v17[1];
      v18 = (float)1.0 - v17[0];
      v9 = (idResource *)LODWORD(v17[3]);
      v10 = v18;
      v11 = v19;
      *(float *)&this->name.str = v20;
      this->trackedMemory = v11;
      *(float *)&this->__vftable = v10;
      this->nextOnHashChain = v9;
    }
    else
    {
      v6 = LODWORD(v17[1]);
      v7 = (const char *)LODWORD(v17[2]);
      v8 = (idResource *)LODWORD(v17[3]);
      *(float *)&this->__vftable = v17[0];
      this->trackedMemory = v6;
      this->name.str = v7;
      this->nextOnHashChain = v8;
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v16);
  }
  else
  {
    v12 = LODWORD(v17[1]);
    v13 = (const char *)LODWORD(v17[2]);
    v14 = (idResource *)LODWORD(v17[3]);
    *(float *)&this->__vftable = v17[0];
    this->trackedMemory = v12;
    this->name.str = v13;
    this->nextOnHashChain = v14;
  }
  return this;
}


// ========================================================================
// __unwind$491736
// EA  : 0x82BBF3F4
// RVA : 0x00BBF3F4
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_491736()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetSubGraphFactory@idDeclTypeInfoGraphTest@@SAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x82BC0120
// RVA : 0x00BC0120
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraphTest::GetSubGraphFactory()
{
  if ( (_S18_11 & 1) == 0 )
  {
    _S18_11 |= 1u;
    idGraphItemFactory<idTypeInfoSubGraph>::idGraphItemFactory<idTypeInfoSubGraph>(this: &subGraphFactory_0);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphTest::GetSubGraphFactory_::_2_::_dynamic_atexit_destructor_for__subGraphFactory__);
  }
  return &subGraphFactory_0;
}


// ========================================================================
// __unwind$492680
// EA  : 0x82BC0198
// RVA : 0x00BC0198
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492680()
{
  _S18_11 &= ~1u;
}


// ========================================================================
// ?GetGraphNodeFactory@idDeclTypeInfoGraphTest@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x82BC01C0
// RVA : 0x00BC01C0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraphTest::GetGraphNodeFactory()
{
  if ( (_S19_0 & 1) == 0 )
  {
    _S19_0 |= 1u;
    idGraphItemFactory<idTypeInfoGraphNode>::idGraphItemFactory<idTypeInfoGraphNode>(this: &nodeFactory_0);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphTest::GetGraphNodeFactory_::_2_::_dynamic_atexit_destructor_for__nodeFactory__);
  }
  return &nodeFactory_0;
}


// ========================================================================
// __unwind$492697_0
// EA  : 0x82BC0238
// RVA : 0x00BC0238
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492697_0()
{
  _S19_0 &= ~1u;
}


// ========================================================================
// ?GetGraphLinkFactory@idDeclTypeInfoGraphTest@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x82BC0260
// RVA : 0x00BC0260
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraphTest::GetGraphLinkFactory()
{
  if ( (_S20_1 & 1) == 0 )
  {
    _S20_1 |= 1u;
    idGraphItemFactory<idTypeInfoGraphLink>::idGraphItemFactory<idTypeInfoGraphLink>(this: &linkFactory_0);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphTest::GetGraphLinkFactory_::_2_::_dynamic_atexit_destructor_for__linkFactory__);
  }
  return &linkFactory_0;
}


// ========================================================================
// __unwind$492714
// EA  : 0x82BC02D8
// RVA : 0x00BC02D8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492714()
{
  _S20_1 &= ~1u;
}


// ========================================================================
// ?GetMainContextMenuItems@idDeclTypeInfoGraphTest@@UBAXAAV?$idList@VidContextMenuItemMain@idDeclTypeInfoGraph@@$04@@@Z
// EA  : 0x82BC02F8
// RVA : 0x00BC02F8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::GetMainContextMenuItems(
        idDeclTypeInfoGraphTest *this,
        idList<idDeclTypeInfoGraph::idContextMenuItemMain,5> *menuItems)
{
  idDeclTypeInfoGraph::idContextMenuItemMain *v3; // r31
  bool highlightDeadEndNodes; // r8

  v3 = idList<idDeclTypeInfoGraph::idContextMenuItemMain,5>::Alloc(this: menuItems);
  idStr::operator=(this: &v3->description, text: "Highlight Deadend Nodes");
  highlightDeadEndNodes = this->highlightDeadEndNodes;
  v3->callback = idDeclTypeInfoGraphTest::ToggleHighlightDeadEndLinks;
  v3->isChecked = highlightDeadEndNodes;
}


// ========================================================================
// ?GetLinkContextMenuItems@idDeclTypeInfoGraphSingleTypeTest@@UBAXABV?$idList@PAVidTypeInfoGraphLink@@$04@@AAV?$idList@VidContextMenuItemLink@idDeclTypeInfoGraph@@$04@@@Z
// EA  : 0x82BC0358
// RVA : 0x00BC0358
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void __fastcall idDeclTypeInfoGraphSingleTypeTest::GetLinkContextMenuItems(
        idDeclTypeInfoGraphSingleTypeTest *this,
        const idList<idTypeInfoGraphLink *,5> *selectedLinks,
        idList<idDeclTypeInfoGraph::idContextMenuItemLink,5> *menuItems)
{
  char v5; // r24
  char v6; // r25
  int v7; // r27
  int v8; // r30
  _BYTE *v9; // r3
  int num; // r11
  int size; // r10
  idDeclTypeInfoGraph::idContextMenuItemLink *list; // r9
  int v13; // r30
  int v14; // r11
  int v15; // r10
  idDeclTypeInfoGraph::idContextMenuItemLink *v16; // r9
  int v17; // r30

  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( selectedLinks->num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = _RTDynamicCast(
             inptr: selectedLinks->list[v8],
             VfDelta: 0,
             SrcType: &idTypeInfoGraphLink `RTTI Type Descriptor',
             TargetType: &idTypeInfoGraphLinkTest `RTTI Type Descriptor',
             isReference: 0);
      if ( v9 != nullptr )
      {
        if ( v9[20] != 0 )
          v5 = 1;
        else
          v6 = 1;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < selectedLinks->num );
  }
  idList<idDeclTypeInfoGraph::idContextMenuItemLink,5>::PreAllocateWithGranularity(
    this: menuItems,
    newSize: menuItems->num + 1);
  num = menuItems->num;
  size = menuItems->size;
  list = menuItems->list;
  if ( num >= size )
  {
    v13 = (int)&list[size - 1];
  }
  else
  {
    v13 = (int)&list[num];
    menuItems->num = num + 1;
  }
  idStr::operator=(this: (idStr *)(v13 + 4), text: "Enable Link");
  if ( selectedLinks->num > 1 )
    idStr::Append(this: (idStr *)(v13 + 4), text: "s");
  *(_BYTE *)(v13 + 36) = v6;
  *(_DWORD *)(v13 + 40) = idDeclTypeInfoGraphTest::EnableLinks;
  idList<idDeclTypeInfoGraph::idContextMenuItemLink,5>::PreAllocateWithGranularity(
    this: menuItems,
    newSize: menuItems->num + 1);
  v14 = menuItems->num;
  v15 = menuItems->size;
  v16 = menuItems->list;
  if ( v14 >= v15 )
  {
    v17 = (int)&v16[v15 - 1];
  }
  else
  {
    v17 = (int)&v16[v14];
    menuItems->num = v14 + 1;
  }
  idStr::operator=(this: (idStr *)(v17 + 4), text: "Disable Link");
  if ( selectedLinks->num > 1 )
    idStr::Append(this: (idStr *)(v17 + 4), text: "s");
  *(_BYTE *)(v17 + 36) = v5;
  *(_DWORD *)(v17 + 40) = idDeclTypeInfoGraphTest::DisableLinks;
}


// ========================================================================
// ?GetSubGraphFactory@idDeclTypeInfoGraphSingleTypeTest@@SAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x82BC0500
// RVA : 0x00BC0500
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetSubGraphFactory()
{
  if ( (_S22 & 1) == 0 )
  {
    _S22 |= 1u;
    idGraphItemFactory<idTypeInfoSubGraph>::idGraphItemFactory<idTypeInfoSubGraph>(this: &subGraphFactory_1);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphSingleTypeTest::GetSubGraphFactory_::_2_::_dynamic_atexit_destructor_for__subGraphFactory__);
  }
  return &subGraphFactory_1;
}


// ========================================================================
// __unwind$492791
// EA  : 0x82BC0578
// RVA : 0x00BC0578
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492791()
{
  _S22 &= ~1u;
}


// ========================================================================
// ?GetGraphNodeFactory@idDeclTypeInfoGraphSingleTypeTest@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x82BC05A0
// RVA : 0x00BC05A0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetGraphNodeFactory()
{
  if ( (_S23 & 1) == 0 )
  {
    _S23 |= 1u;
    idGraphItemFactory<idTypeInfoGraphNode>::idGraphItemFactory<idTypeInfoGraphNode>(this: &nodeFactory_1);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphSingleTypeTest::GetGraphNodeFactory_::_2_::_dynamic_atexit_destructor_for__nodeFactory__);
  }
  return &nodeFactory_1;
}


// ========================================================================
// __unwind$492808
// EA  : 0x82BC0618
// RVA : 0x00BC0618
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492808()
{
  _S23 &= ~1u;
}


// ========================================================================
// ?GetGraphLinkFactory@idDeclTypeInfoGraphSingleTypeTest@@SAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x82BC0640
// RVA : 0x00BC0640
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetGraphLinkFactory()
{
  if ( (_S24 & 1) == 0 )
  {
    _S24 |= 1u;
    idGraphItemFactory<idTypeInfoGraphLink>::idGraphItemFactory<idTypeInfoGraphLink>(this: &linkFactory_1);
    atexit(func: (void (__fastcall *)())_idDeclTypeInfoGraphSingleTypeTest::GetGraphLinkFactory_::_2_::_dynamic_atexit_destructor_for__linkFactory__);
  }
  return &linkFactory_1;
}


// ========================================================================
// __unwind$492825
// EA  : 0x82BC06B8
// RVA : 0x00BC06B8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_492825()
{
  _S24 &= ~1u;
}


// ========================================================================
// ?RegisterGraphTypes@idDeclTypeInfoGraphTest@@SA_NXZ
// EA  : 0x82BC0B90
// RVA : 0x00BC0B90
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

int __fastcall idDeclTypeInfoGraphTest::RegisterGraphTypes()
{
  unsigned int v0; // r11
  idGraphItemFactory<idTypeInfoSubGraph> *SubGraphFactory; // r29
  idGraphItemFactory<idTypeInfoSubGraph> *v2; // r3
  idGraphItemFactory<idTypeInfoSubGraph> *v3; // r29
  idGraphItemFactory<idTypeInfoSubGraph> *v4; // r3
  idGraphItemFactory<idTypeInfoGraphNode> *GraphNodeFactory; // r29
  idGraphItemFactory<idTypeInfoGraphNode> *v6; // r3
  idGraphItemFactory<idTypeInfoGraphNode> *v7; // r29
  idGraphItemFactory<idTypeInfoGraphNode> *v8; // r3
  idGraphItemFactory<idTypeInfoGraphLink> *GraphLinkFactory; // r29
  idGraphItemFactory<idTypeInfoGraphLink> *v10; // r3
  idGraphItemFactory<idTypeInfoGraphLink> *v11; // r30
  idGraphItemFactory<idTypeInfoGraphLink> *v12; // r3

  v0 = _S21;
  if ( (_S21 & 1) == 0 )
  {
    _S21 |= 1u;
    SubGraphFactory = idDeclTypeInfoGraph::GetSubGraphFactory();
    v2 = idDeclTypeInfoGraphTest::GetSubGraphFactory();
    idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>(
      this: &pleaseRegister_idTypeInfoSubGraphTest_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoSubGraphTest",
      diplayedName: "basic subgraph",
      graphItemFactory: v2,
      globalItemFactory: SubGraphFactory);
    v0 = _S21;
  }
  if ( (v0 & 2) == 0 )
  {
    _S21 = v0 | 2;
    v3 = idDeclTypeInfoGraph::GetSubGraphFactory();
    v4 = idDeclTypeInfoGraphTest::GetSubGraphFactory();
    idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>::idRegisterInGraphItemFactory<idTypeInfoSubGraphTest2,idTypeInfoSubGraph>(
      this: &pleaseRegister_idTypeInfoSubGraphTest2_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoSubGraphTest2",
      diplayedName: "white subgraph",
      graphItemFactory: v4,
      globalItemFactory: v3);
    v0 = _S21;
  }
  if ( (v0 & 4) == 0 )
  {
    _S21 = v0 | 4;
    GraphNodeFactory = idDeclTypeInfoGraph::GetGraphNodeFactory();
    v6 = idDeclTypeInfoGraphTest::GetGraphNodeFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>(
      this: &pleaseRegister_idTypeInfoGraphNodeTest_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoGraphNodeTest",
      diplayedName: "basic node",
      graphItemFactory: v6,
      globalItemFactory: GraphNodeFactory);
    v0 = _S21;
  }
  if ( (v0 & 8) == 0 )
  {
    _S21 = v0 | 8;
    v7 = idDeclTypeInfoGraph::GetGraphNodeFactory();
    v8 = idDeclTypeInfoGraphTest::GetGraphNodeFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>::idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest2,idTypeInfoGraphNode>(
      this: &pleaseRegister_idTypeInfoGraphNodeTest2_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoGraphNodeTest2",
      diplayedName: "red node",
      graphItemFactory: v8,
      globalItemFactory: v7);
    v0 = _S21;
  }
  if ( (v0 & 0x10) == 0 )
  {
    _S21 = v0 | 0x10;
    GraphLinkFactory = idDeclTypeInfoGraph::GetGraphLinkFactory();
    v10 = idDeclTypeInfoGraphTest::GetGraphLinkFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>(
      this: &pleaseRegister_idTypeInfoGraphLinkTest_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoGraphLinkTest",
      diplayedName: "basic link",
      graphItemFactory: v10,
      globalItemFactory: GraphLinkFactory);
    v0 = _S21;
  }
  if ( (v0 & 0x20) == 0 )
  {
    _S21 = v0 | 0x20;
    v11 = idDeclTypeInfoGraph::GetGraphLinkFactory();
    v12 = idDeclTypeInfoGraphTest::GetGraphLinkFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>::idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest2,idTypeInfoGraphLink>(
      this: &pleaseRegister_idTypeInfoGraphLinkTest2_with_idDeclTypeInfoGraphTest,
      className: "idTypeInfoGraphLinkTest2",
      diplayedName: "pink link",
      graphItemFactory: v12,
      globalItemFactory: v11);
  }
  return 1;
}


// ========================================================================
// __unwind$493269
// EA  : 0x82BC0D78
// RVA : 0x00BC0D78
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493269()
{
  _S21 &= ~1u;
}


// ========================================================================
// __unwind$493270
// EA  : 0x82BC0D98
// RVA : 0x00BC0D98
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493270()
{
  _S21 &= ~2u;
}


// ========================================================================
// __unwind$493271
// EA  : 0x82BC0DB8
// RVA : 0x00BC0DB8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493271()
{
  _S21 &= ~4u;
}


// ========================================================================
// __unwind$493272
// EA  : 0x82BC0DD8
// RVA : 0x00BC0DD8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493272()
{
  _S21 &= ~8u;
}


// ========================================================================
// __unwind$493273
// EA  : 0x82BC0DF8
// RVA : 0x00BC0DF8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493273()
{
  _S21 &= ~0x10u;
}


// ========================================================================
// __unwind$493274
// EA  : 0x82BC0E18
// RVA : 0x00BC0E18
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493274()
{
  _S21 &= ~0x20u;
}


// ========================================================================
// ?RegisterGraphTypes@idDeclTypeInfoGraphSingleTypeTest@@SA_NXZ
// EA  : 0x82BC0E40
// RVA : 0x00BC0E40
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

int __fastcall idDeclTypeInfoGraphSingleTypeTest::RegisterGraphTypes()
{
  unsigned int v0; // r11
  idGraphItemFactory<idTypeInfoSubGraph> *SubGraphFactory; // r29
  idGraphItemFactory<idTypeInfoSubGraph> *v2; // r3
  idGraphItemFactory<idTypeInfoGraphNode> *GraphNodeFactory; // r29
  idGraphItemFactory<idTypeInfoGraphNode> *v4; // r3
  idGraphItemFactory<idTypeInfoGraphLink> *GraphLinkFactory; // r30
  idGraphItemFactory<idTypeInfoGraphLink> *v6; // r3

  v0 = _S25;
  if ( (_S25 & 1) == 0 )
  {
    _S25 |= 1u;
    SubGraphFactory = idDeclTypeInfoGraph::GetSubGraphFactory();
    v2 = idDeclTypeInfoGraphSingleTypeTest::GetSubGraphFactory();
    idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>::idRegisterInGraphItemFactory<idTypeInfoSubGraphTest,idTypeInfoSubGraph>(
      this: &pleaseRegister_idTypeInfoSubGraphTest_with_idDeclTypeInfoGraphSingleTypeTest,
      className: "idTypeInfoSubGraphTest",
      diplayedName: "idTypeInfoSubGraphTest",
      graphItemFactory: v2,
      globalItemFactory: SubGraphFactory);
    v0 = _S25;
  }
  if ( (v0 & 2) == 0 )
  {
    _S25 = v0 | 2;
    GraphNodeFactory = idDeclTypeInfoGraph::GetGraphNodeFactory();
    v4 = idDeclTypeInfoGraphSingleTypeTest::GetGraphNodeFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>::idRegisterInGraphItemFactory<idTypeInfoGraphNodeTest,idTypeInfoGraphNode>(
      this: &pleaseRegister_idTypeInfoGraphNodeTest_with_idDeclTypeInfoGraphSingleTypeTest,
      className: "idTypeInfoGraphNodeTest",
      diplayedName: "idTypeInfoGraphNodeTest",
      graphItemFactory: v4,
      globalItemFactory: GraphNodeFactory);
    v0 = _S25;
  }
  if ( (v0 & 4) == 0 )
  {
    _S25 = v0 | 4;
    GraphLinkFactory = idDeclTypeInfoGraph::GetGraphLinkFactory();
    v6 = idDeclTypeInfoGraphSingleTypeTest::GetGraphLinkFactory();
    idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>::idRegisterInGraphItemFactory<idTypeInfoGraphLinkTest,idTypeInfoGraphLink>(
      this: &pleaseRegister_idTypeInfoGraphLinkTest_with_idDeclTypeInfoGraphSingleTypeTest,
      className: "idTypeInfoGraphLinkTest",
      diplayedName: "idTypeInfoGraphLinkTest",
      graphItemFactory: v6,
      globalItemFactory: GraphLinkFactory);
  }
  return 1;
}


// ========================================================================
// __unwind$493371
// EA  : 0x82BC0F38
// RVA : 0x00BC0F38
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493371()
{
  _S25 &= ~1u;
}


// ========================================================================
// __unwind$493372
// EA  : 0x82BC0F58
// RVA : 0x00BC0F58
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493372()
{
  _S25 &= ~2u;
}


// ========================================================================
// __unwind$493373
// EA  : 0x82BC0F78
// RVA : 0x00BC0F78
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.cpp
// ========================================================================

void _unwind_493373()
{
  _S25 &= ~4u;
}

