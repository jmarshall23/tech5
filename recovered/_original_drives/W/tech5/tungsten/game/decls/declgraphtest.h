
// ========================================================================
// ??1idTypeInfoGraphNodeTest2@@UAA@XZ
// EA  : 0x82BBEA08
// RVA : 0x00BBEA08
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

void __fastcall idTypeInfoGraphNodeTest2::~idTypeInfoGraphNodeTest2(idTypeInfoGraphNodeTest2 *this)
{
  this->__vftable = (idTypeInfoGraphNodeTest2_vtbl *)&idTypeInfoGraphNodeTest2::`vftable';
  idStr::FreeData(this: &this->justSomeString);
  this->__vftable = (idTypeInfoGraphNodeTest2_vtbl *)&idTypeInfoGraphItem::`vftable';
}


// ========================================================================
// __unwind$490682
// EA  : 0x82BBEA60
// RVA : 0x00BBEA60
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

void _unwind_490682()
{
  int v0; // r12

  idTypeInfoGraphItem::~idTypeInfoGraphItem(this: *(idTypeInfoGraphNode **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetColor@idTypeInfoGraphNodeTest2@@UBA?AVidColor@@XZ
// EA  : 0x82BBEA88
// RVA : 0x00BBEA88
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idTypeInfoGraphNodeTest2 *__fastcall idTypeInfoGraphNodeTest2::GetColor(
        idTypeInfoGraphNodeTest2 *this,
        idColor *result)
{
  float g; // r8
  float b; // r7
  float a; // r6

  g = idColor::colorRed.g;
  b = idColor::colorRed.b;
  a = idColor::colorRed.a;
  this->__vftable = (idTypeInfoGraphNodeTest2_vtbl *)LODWORD(idColor::colorRed.r);
  *(float *)&this->name.str = g;
  *(float *)&this->className.str = b;
  this->position.x = a;
  return this;
}


// ========================================================================
// ?GetColor@idTypeInfoGraphLinkTest@@UBA?AVidColor@@XZ
// EA  : 0x82BBEB18
// RVA : 0x00BBEB18
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idTypeInfoGraphLinkTest *__fastcall idTypeInfoGraphLinkTest::GetColor(idTypeInfoGraphLinkTest *this, idColor *result)
{
  int g_high; // r10
  float back_chain[3]; // [sp+0h] [-20h] BYREF
  float a; // [sp+Ch] [-14h]
  float v6; // [sp+10h] [-10h]
  float v7; // [sp+14h] [-Ch]
  float v8; // [sp+18h] [-8h]
  float v9; // [sp+1Ch] [-4h]

  g_high = HIBYTE(result[1].g);
  qmemcpy(back_chain, "?333?333?333", sizeof(back_chain));
  a = idTypeInfoGraphLink::baseColor.a;
  if ( g_high != 0 )
  {
    this->__vftable = (idTypeInfoGraphLinkTest_vtbl *)LODWORD(idTypeInfoGraphLink::baseColor.r);
    *(float *)&this->name.str = back_chain[1];
    *(float *)&this->className.str = back_chain[2];
  }
  else
  {
    v9 = a;
    v6 = (float)1.0 - idTypeInfoGraphLink::baseColor.r;
    v7 = (float)1.0 - idTypeInfoGraphLink::baseColor.g;
    v8 = (float)1.0 - back_chain[2];
    *(float *)&this->className.str = v8;
    *(float *)&this->name.str = (float)1.0 - back_chain[1];
    *(float *)&this->__vftable = (float)1.0 - back_chain[0];
  }
  *(float *)&this->startNodeIndex = a;
  return this;
}


// ========================================================================
// ?GetColor@idTypeInfoGraphLinkTest2@@UBA?AVidColor@@XZ
// EA  : 0x82BBEF30
// RVA : 0x00BBEF30
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idTypeInfoGraphLinkTest2 *__fastcall idTypeInfoGraphLinkTest2::GetColor(
        idTypeInfoGraphLinkTest2 *this,
        idColor *result)
{
  float g; // r8
  float b; // r7
  int a_low; // r6

  g = idColor::colorPink.g;
  b = idColor::colorPink.b;
  a_low = LODWORD(idColor::colorPink.a);
  this->__vftable = (idTypeInfoGraphLinkTest2_vtbl *)LODWORD(idColor::colorPink.r);
  *(float *)&this->name.str = g;
  *(float *)&this->className.str = b;
  this->startNodeIndex = a_low;
  return this;
}


// ========================================================================
// ?GetColor@idTypeInfoSubGraphTest@@UBA?AVidColor@@XZ
// EA  : 0x82BBF6D0
// RVA : 0x00BBF6D0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idTypeInfoSubGraphTest *__fastcall idTypeInfoSubGraphTest::GetColor(idTypeInfoSubGraphTest *this, idColor *result)
{
  char *p_g; // r11
  const char *v3; // r9
  const char *v4; // r8
  int *v5; // r7
  _DWORD back_chain[4]; // [sp+0h] [-10h] BYREF

  if ( HIBYTE(result[3].g) != 0 )
  {
    p_g = (char *)&result[2].g;
  }
  else
  {
    p_g = (char *)back_chain;
    back_chain[2] = LODWORD(idTypeInfoSubGraph::baseColor.b);
    back_chain[3] = LODWORD(idTypeInfoSubGraph::baseColor.a);
  }
  v3 = *((const char **)p_g + 1);
  v4 = *((const char **)p_g + 2);
  v5 = *((int **)p_g + 3);
  this->__vftable = *(idTypeInfoSubGraphTest_vtbl **)p_g;
  this->name.str = v3;
  this->className.str = v4;
  this->subnodes.list = v5;
  return this;
}


// ========================================================================
// ?GetMySubGraphFactory@idDeclTypeInfoGraphTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x82BCC8F0
// RVA : 0x00BCC8F0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraphTest::GetMySubGraphFactory(
        idDeclTypeInfoGraphTest *this)
{
  return idDeclTypeInfoGraphTest::GetSubGraphFactory();
}


// ========================================================================
// ?GetMyGraphNodeFactory@idDeclTypeInfoGraphTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x82BCC8F8
// RVA : 0x00BCC8F8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraphTest::GetMyGraphNodeFactory(
        idDeclTypeInfoGraphTest *this)
{
  return idDeclTypeInfoGraphTest::GetGraphNodeFactory();
}


// ========================================================================
// ?GetMyGraphLinkFactory@idDeclTypeInfoGraphTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x82BCC900
// RVA : 0x00BCC900
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraphTest::GetMyGraphLinkFactory(
        idDeclTypeInfoGraphTest *this)
{
  return idDeclTypeInfoGraphTest::GetGraphLinkFactory();
}


// ========================================================================
// ?GetDeclInfo@idDeclTypeInfoGraphTest@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC908
// RVA : 0x00BCC908
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idDeclInfoTemplate<idDeclTypeInfoGraphTest> *__fastcall idDeclTypeInfoGraphTest::GetDeclInfo(
        idDeclTypeInfoGraphTest *this)
{
  return &idDeclTypeInfoGraphTest::resourceList;
}


// ========================================================================
// ?OnDeclParsed@idDeclTypeInfoGraphTest@@UAAXXZ
// EA  : 0x82BCC918
// RVA : 0x00BCC918
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::OnDeclParsed(idDeclTypeInfoGraphTest *this)
{
  idLib::Printf(fmt: "an idDeclTypeInfoGraphTest was just parsed!\n");
}


// ========================================================================
// ?HighlightDeadEndNodes@idDeclTypeInfoGraphTest@@UBA_NXZ
// EA  : 0x82BCC928
// RVA : 0x00BCC928
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

BOOL __fastcall idDeclTypeInfoGraphTest::HighlightDeadEndNodes(idDeclTypeInfoGraphTest *this)
{
  return this->highlightDeadEndNodes;
}


// ========================================================================
// ?SetHighlightDeadEndNodes@idDeclTypeInfoGraphTest@@UAAX_N@Z
// EA  : 0x82BCC930
// RVA : 0x00BCC930
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

void __fastcall idDeclTypeInfoGraphTest::SetHighlightDeadEndNodes(idDeclTypeInfoGraphTest *this, bool b)
{
  this->highlightDeadEndNodes = b;
}


// ========================================================================
// ?GetMySubGraphFactory@idDeclTypeInfoGraphSingleTypeTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoSubGraph@@@@XZ
// EA  : 0x82BD25A0
// RVA : 0x00BD25A0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoSubGraph> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetMySubGraphFactory(
        idDeclTypeInfoGraphSingleTypeTest *this)
{
  return idDeclTypeInfoGraphSingleTypeTest::GetSubGraphFactory();
}


// ========================================================================
// ?GetMyGraphNodeFactory@idDeclTypeInfoGraphSingleTypeTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphNode@@@@XZ
// EA  : 0x82BD25A8
// RVA : 0x00BD25A8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphNode> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetMyGraphNodeFactory(
        idDeclTypeInfoGraphSingleTypeTest *this)
{
  return idDeclTypeInfoGraphSingleTypeTest::GetGraphNodeFactory();
}


// ========================================================================
// ?GetMyGraphLinkFactory@idDeclTypeInfoGraphSingleTypeTest@@UBAAAV?$idGraphItemFactory@VidTypeInfoGraphLink@@@@XZ
// EA  : 0x82BD25B0
// RVA : 0x00BD25B0
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

// attributes: thunk
idGraphItemFactory<idTypeInfoGraphLink> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetMyGraphLinkFactory(
        idDeclTypeInfoGraphSingleTypeTest *this)
{
  return idDeclTypeInfoGraphSingleTypeTest::GetGraphLinkFactory();
}


// ========================================================================
// ?GetDeclInfo@idDeclTypeInfoGraphSingleTypeTest@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD25B8
// RVA : 0x00BD25B8
// PDB : w:\tech5\tungsten\game\decls\declgraphtest.h
// ========================================================================

idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest> *__fastcall idDeclTypeInfoGraphSingleTypeTest::GetDeclInfo(
        idDeclTypeInfoGraphSingleTypeTest *this)
{
  return &idDeclTypeInfoGraphSingleTypeTest::resourceList;
}

