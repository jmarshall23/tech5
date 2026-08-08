
// ========================================================================
// ?SetupScalarPair@idAnimWebBlendEquation@@AAAAAVidAnimWebScalarPair@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@VidAnimWebScalarPair@@$04@@PAVidMD6Node@@HHEEH@Z
// EA  : 0x825F8BC0
// RVA : 0x005F8BC0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

idAnimWebScalarPair *__fastcall idAnimWebBlendEquation::SetupScalarPair(
        idAnimWebBlendEquation *this,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        idMD6Node *node,
        int scalarIndex,
        const int scalarPairIndex,
        unsigned __int8 fieldType,
        const unsigned __int8 fieldFlags,
        const int coordinateIndex,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idAnimWebScalarPair *result; // r3

  result = &scalarPairs->list[scalarPairIndex];
  result->scalarIndex = scalarIndex;
  result->coordinateIndex = a28;
  result->node = node;
  result->fieldType = fieldType;
  result->fieldFlags = scalars->list[scalarIndex].flags | fieldFlags;
  if ( fieldType == 1 )
    scalars->list[scalarIndex].flags = 1;
  return result;
}


// ========================================================================
// ?ParseScalarName@idAnimWebBlendEquation@@AAA_NAAVidLexer@@AAVidToken@@@Z
// EA  : 0x825F8C30
// RVA : 0x005F8C30
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

int __fastcall idAnimWebBlendEquation::ParseScalarName(idAnimWebBlendEquation *this, idLexer *src, idToken *token)
{
  if ( (token->type != 5 || idStr::Cmp(s1: token->data, s2: "#") != 0)
    && (token->type != 4 || idStr::Cmp(s1: token->data, s2: "onplay") != 0) )
  {
    if ( token->type != 4 )
      idLexer::Error(this: src, str: "Expected a scalar variable name or a number, got \"%s\"", token->data);
    return 0;
  }
  else
  {
    idLexer::ExpectTokenType(this: src, type: 4, subtype: 0, token);
    return 1;
  }
}


// ========================================================================
// ?AllocateUndeclaredScalars@idAnimWebBlendEquation@@SAXAAV?$idList@VidAnimWebScalar@@$0CB@@@AAVidScalarMemBlock@@@Z
// EA  : 0x825F8CE0
// RVA : 0x005F8CE0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::AllocateUndeclaredScalars(
        idList<idAnimWebScalar,5> *scalars,
        idScalarMemBlock *block)
{
  int v4; // r25
  idAnimWebScalar *list; // r9
  int v6; // r10
  int num; // ctr
  char v8; // r11
  int v9; // r29
  int v10; // r28
  int v11; // r30
  idAnimWebScalar *v12; // r31
  char v13; // r11
  double v14; // fp1

  idScalarMemBlock::Free(this: block, scalars);
  v4 = 0;
  if ( scalars->num > 0 )
  {
    list = scalars->list;
    v6 = 0;
    num = scalars->num;
    do
    {
      if ( (unsigned __int16)list[v6].scalarIndex < 0x8000u || (v8 = 0, list[v6].scalarPtr != nullptr) )
        v8 = 1;
      if ( v8 == 0 )
        ++v4;
      ++v6;
      --num;
    }
    while ( num != 0 );
    if ( v4 != 0 )
    {
      idScalarMemBlock::Alloc(this: block, num_: v4);
      v9 = 0;
      v10 = 0;
      if ( scalars->num > 0 )
      {
        v11 = 0;
        do
        {
          v12 = &scalars->list[v11];
          if ( (unsigned __int16)v12->scalarIndex >= 0x8000u )
          {
            v13 = 0;
            if ( v12->scalarPtr == nullptr )
              goto LABEL_23;
          }
          v13 = 1;
LABEL_23:
          if ( v13 == 0 )
          {
            idAnimWebScalar::SetIndex(this: &scalars->list[v11], memBlock: block, index: v9);
            v14 = (v12->flags & 1) != 0 ? 1.0 : 0.0;
            idAnimWebScalar::SetScalar(this: v12, memBlock: block, f: v14);
            if ( ++v9 >= v4 )
              break;
          }
          ++v10;
          ++v11;
        }
        while ( v10 < scalars->num );
      }
    }
  }
}


// ========================================================================
// ?ParseWeightGroup@idAnimWebBlendEquation@@ABA?AW4md6WeightGroup_t@@AAVidLexer@@@Z
// EA  : 0x825F8E60
// RVA : 0x005F8E60
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

int __fastcall idAnimWebBlendEquation::ParseWeightGroup(idAnimWebBlendEquation *this, idLexer *src)
{
  int v3; // r29
  unsigned int v4; // r3
  unsigned int v5; // r30
  int v6; // r26
  const char **v7; // r30
  idToken v9; // [sp+50h] [-180h] BYREF
  char v10; // [sp+98h] [-138h] BYREF

  v3 = 0;
  if ( !idLexer::CheckTokenString(this: src, string: "filtered")
    && !idLexer::CheckTokenString(this: src, string: "masked")
    && !idLexer::CheckTokenString(this: src, string: "weighted") )
  {
    return 0;
  }
  idLexer::CheckTokenString(this: src, string: "by");
  v9.baseBuffer[0] = 0;
  v9.intvalue = 0;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  v9.floatvalue = -3.4028235e38;
  v10 = 0;
  v9.data = &v10;
  v9.len = 0;
  v9.allocedAndFlag = -2147483392;
  if ( idLexer::PeekTokenType(this: src, type: 3, subtype: 1, token: &v9) )
  {
    v4 = idLexer::ParseInt(this: src);
    v5 = v4;
    if ( v4 >= 8 )
      idLexer::Error(
        this: src,
        str: "Specified weight group index '%d' is out of range. Valid values are %d through %d.",
        v4,
        0,
        8);
    v6 = v5;
  }
  else
  {
    idLexer::ReadToken(this: src, token: &v9);
    v6 = 8;
    v7 = idMD6Skel::weightGroupNames;
    while ( idStr::Icmp(s1: *v7, s2: v9.data) != 0 )
    {
      ++v7;
      ++v3;
      if ( (int)v7 >= (int)&NULL_JOINT )
        goto LABEL_13;
    }
    v6 = v3;
    if ( v3 != 8 )
      goto LABEL_14;
LABEL_13:
    idLexer::Error(this: src, str: "Unknown weight group name '%s'", v9.data);
  }
LABEL_14:
  idStr::FreeData(this: &v9);
  return v6;
}


// ========================================================================
// __unwind$224356
// EA  : 0x825F8FFC
// RVA : 0x005F8FFC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_224356()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ??0idAnimWebBlendEquation@@QAA@XZ
// EA  : 0x825F9028
// RVA : 0x005F9028
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

idAnimWebBlendEquation *__fastcall idAnimWebBlendEquation::idAnimWebBlendEquation(idAnimWebBlendEquation *this)
{
  this->startTime = 0;
  this->ticksPerSec = 0;
  this->allocatedNodes.size = 64;
  this->allocatedNodes.num = 0;
  this->allocatedNodes.granularity = 1;
  this->allocatedNodes.list = this->allocatedNodes.staticList;
  this->allocatedNodes.memTag = 5;
  this->allocatedNodes.listStatic = 1;
  return this;
}


// ========================================================================
// ?AddScalar@idAnimWebBlendEquation@@AAAXPBDAAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@VidAnimWebScalarPair@@$04@@AAH3@Z
// EA  : 0x825F9268
// RVA : 0x005F9268
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::AddScalar(
        idAnimWebBlendEquation *this,
        const char *scalarName,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        int *scalarIndex,
        int *scalarPairIndex)
{
  int v11; // r28
  int v12; // r29
  int num; // r11
  int size; // r10
  idAnimWebScalarPair *list; // r9
  idAnimWebScalarPair *v16; // r29
  int v17; // r11

  v11 = 0;
  if ( scalars->num > 0 )
  {
    v12 = 0;
    while ( idStr::Icmp(s1: scalars->list[v12].name.str, s2: scalarName) != 0 )
    {
      ++v11;
      ++v12;
      if ( v11 >= scalars->num )
        goto LABEL_7;
    }
    *scalarIndex = v11;
  }
LABEL_7:
  *scalarPairIndex = scalarPairs->num;
  idList<idAnimWebScalarPair,5>::PreAllocateWithGranularity(this: scalarPairs, newSize: scalarPairs->num + 1);
  num = scalarPairs->num;
  size = scalarPairs->size;
  list = scalarPairs->list;
  if ( num >= size )
  {
    v16 = &list[size - 1];
  }
  else
  {
    v16 = &list[num];
    scalarPairs->num = num + 1;
  }
  if ( *scalarIndex >= 0 )
  {
    v16->scalarIndex = *scalarIndex;
  }
  else
  {
    *scalarIndex = scalars->num;
    idList<idAnimWebScalar,5>::PreAllocateWithGranularity(this: scalars, newSize: scalars->num + 1);
    v17 = scalars->num;
    if ( v17 < scalars->size )
      scalars->num = v17 + 1;
    idAnimWebScalar::SetName(this: &scalars->list[*scalarIndex], name_: scalarName);
    v16->scalarIndex = *scalarIndex;
  }
}


// ========================================================================
// ?ParseImmediate@idAnimWebBlendEquation@@AAAXAAVidLexer@@AAM@Z
// EA  : 0x825F93A0
// RVA : 0x005F93A0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::ParseImmediate(idAnimWebBlendEquation *this, idLexer *src, float *value)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idPLogScope v7[2]; // [sp+50h] [-190h] BYREF
  idToken v8; // [sp+60h] [-180h] BYREF
  char v9; // [sp+A8h] [-138h] BYREF

  RD_EventBegin(name: "idAnimWebBlendEquation::ParseImmediate");
  LODWORD(v5) = "idAnimWebBlendEquation::ParseImmediate";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v5, label: v6);
  v8.baseBuffer[0] = 0;
  *value = 0.0;
  v8.intvalue = 0;
  v8.floatvalue = -3.4028235e38;
  memset(&v8.whiteSpaceStart_p, 0, 12);
  v9 = 0;
  v8.data = &v9;
  v8.len = 0;
  v8.allocedAndFlag = -2147483392;
  if ( !idLexer::PeekTokenType(this: src, type: 3, subtype: 0, token: &v8) )
    idLexer::Error(this: src, str: "Expected constant (non-variable) value, found '%s'", v8.data);
  *value = idLexer::ParseFloat(this: src, errorFlag: nullptr);
  idStr::FreeData(this: &v8);
  idPLogScope::~idPLogScope(this: v7);
  RD_EventEnd();
}


// ========================================================================
// __unwind$225254
// EA  : 0x825F948C
// RVA : 0x005F948C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225254()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 424));
}


// ========================================================================
// __unwind$225255
// EA  : 0x825F94B4
// RVA : 0x005F94B4
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225255()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 80));
}


// ========================================================================
// __unwind$225256
// EA  : 0x825F94DC
// RVA : 0x005F94DC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 96));
}


// ========================================================================
// ?AddLeafPlayFromDefaultLeaf@idAnimWebBlendEquation@@AAAPAVidMD6LeafPlay@@PAVidMD6Allocator@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@MHHHMW4wrapMode_t@idMD6Leaf@@W4md6WeightGroup_t@@@Z
// EA  : 0x825F9510
// RVA : 0x005F9510
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idAnimWebBlendEquation::AddLeafPlayFromDefaultLeaf(
        idAnimWebBlendEquation *this,
        idMD6Allocator *allocator,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        double animIndex,
        const int startTime,
        int ticksPerSec,
        int startFrame,
        double rateScale,
        int wrapMode,
        const md6WeightGroup_t weightGroup,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        md6WeightGroup_t a30)
{
  idMD6LeafPlay *v37; // r3
  idMD6Leaf::wrapMode_t num; // r8
  encounterGroupRole_t v39; // r29
  const idMD6Anim *v40; // r4
  unsigned __int64 v41; // r6
  const char *v42; // r7
  encounterGroupRole_t v44[2]; // [sp+50h] [-70h] BYREF
  idPLogScope v45[3]; // [sp+58h] [-68h] BYREF

  v37 = (idMD6LeafPlay *)allocator->Alloc(this: allocator, a2: 2);
  num = existingNodes->num;
  v44[1] = (int)animIndex;
  v39 = (encounterGroupRole_t)v37;
  v40 = nullptr;
  if ( num > (int)animIndex )
    v40 = *(const idMD6Anim **)&existingNodes->list[(int)animIndex].node[4].type;
  idMD6LeafPlay::Init(
    this: v37,
    anim: v40,
    gameTime: ticksPerSec,
    ticksPerSec: startFrame,
    frame: wrapMode,
    rateScale,
    wrapMode: num,
    weightGroup: a30);
  RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
  LODWORD(v41) = "idAnimWebBlendEquation - allocatedNodes.Append";
  HIDWORD(v41) = 2;
  idPLogScope::idPLogScope(this: v45, pl: &pLog, gMask: v41, label: v42);
  v44[0] = v39;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes, obj: v44);
  idPLogScope::~idPLogScope(this: v45);
  RD_EventEnd();
  return (idMD6LeafPlay *)v39;
}


// ========================================================================
// __unwind$225378
// EA  : 0x825F9614
// RVA : 0x005F9614
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225378()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$225379
// EA  : 0x825F963C
// RVA : 0x005F963C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225379()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?AddLeafPauseFromDefaultLeaf@idAnimWebBlendEquation@@AAAPAVidMD6LeafPause@@PAVidMD6Allocator@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@MMW4wrapMode_t@idMD6Leaf@@W4md6WeightGroup_t@@@Z
// EA  : 0x825F9670
// RVA : 0x005F9670
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

idMD6LeafPause *__fastcall idAnimWebBlendEquation::AddLeafPauseFromDefaultLeaf(
        idAnimWebBlendEquation *this,
        idMD6Allocator *allocator,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        double animIndex,
        double frame,
        const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup,
        md6WeightGroup_t a8)
{
  idMD6Leaf::wrapMode_t v13; // r5
  idMD6LeafPause *v14; // r3
  int num; // r8
  encounterGroupRole_t v16; // r29
  const idMD6Anim *v17; // r4
  unsigned __int64 v18; // r6
  const char *v19; // r7
  encounterGroupRole_t v21[2]; // [sp+50h] [-60h] BYREF
  idPLogScope v22[2]; // [sp+58h] [-58h] BYREF

  v14 = (idMD6LeafPause *)allocator->Alloc(this: allocator, a2: 1);
  num = existingNodes->num;
  v21[1] = (int)animIndex;
  v16 = (encounterGroupRole_t)v14;
  v17 = nullptr;
  if ( num > (int)animIndex )
    v17 = *(const idMD6Anim **)&existingNodes->list[(int)animIndex].node[4].type;
  idMD6LeafPause::Init(this: v14, anim: v17, frame, wrapMode: v13, weightGroup: a8);
  RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
  LODWORD(v18) = "idAnimWebBlendEquation - allocatedNodes.Append";
  HIDWORD(v18) = 2;
  idPLogScope::idPLogScope(this: v22, pl: &pLog, gMask: v18, label: v19);
  v21[0] = v16;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes, obj: v21);
  idPLogScope::~idPLogScope(this: v22);
  RD_EventEnd();
  return (idMD6LeafPause *)v16;
}


// ========================================================================
// __unwind$225423
// EA  : 0x825F9764
// RVA : 0x005F9764
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225423()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$225424
// EA  : 0x825F978C
// RVA : 0x005F978C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225424()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?ProcessTagGroup@idAnimWebBlendEquation@@AAAPBVidDeclAnimWebTagGroup@@_NPBDABVidModelInfo@idDeclAnimWebNode@@PAVidMD6Node@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@VidAnimWebScalarPair@@$04@@AAI6666@Z
// EA  : 0x825F97B8
// RVA : 0x005F97B8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

const idDeclAnimWebTagGroup *__fastcall idAnimWebBlendEquation::ProcessTagGroup(
        idAnimWebBlendEquation *this,
        const bool isCopyOnPlay,
        const char *tagGroupName,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        idMD6Node *node,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        unsigned int *tagBias,
        unsigned int *tagCount,
        unsigned int *defaultTag,
        unsigned int *tagGroupIndex,
        unsigned int *tagGroupMask,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28,
        int a29,
        _DWORD *a30,
        int a31,
        int *a32,
        int a33,
        int *a34)
{
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r11
  const char *v35; // r23
  idDeclAnimWebTagGroup *v40; // r14
  unsigned int v41; // r30
  bool v42; // r29
  int v43; // r19
  char v44; // r20
  idList<idDeclAnimWebTagGroup,32> *v45; // r11
  idDeclAnimWebTagGroup *v46; // r24
  int v47; // r31
  int v48; // r3
  char v49; // r11
  int v50; // r9
  int v51; // ctr
  int v52; // r8
  int v53; // r27
  BOOL v54; // r23
  int v55; // r29
  idDeclAnimWebTag *v56; // r11
  const char *str; // r4
  int v58; // r10
  idAnimWebScalarPair *v59; // r11
  bool v61; // [sp+50h] [-B0h]
  int num; // [sp+54h] [-ACh]
  int v63; // [sp+58h] [-A8h]
  int v64; // [sp+5Ch] [-A4h] BYREF
  int v65; // [sp+60h] [-A0h] BYREF
  const idDeclAnimWebNode::idModelInfo *v66; // [sp+64h] [-9Ch]

  tagGroups = modelInfo->tagGroups;
  v35 = tagGroupName;
  v66 = modelInfo;
  v40 = nullptr;
  if ( tagGroups != nullptr )
    num = tagGroups->num;
  else
    num = 0;
  v41 = 0;
  v42 = (_cntlzw(node->type - 7) & 0x20) != 0;
  v61 = v42;
  v43 = 0;
  v44 = (((_cntlzw(isCopyOnPlay) & 0x20) == 0) + 1) | 0x10;
  if ( num > 0 )
  {
    v63 = 0;
    while ( 1 )
    {
      v45 = modelInfo->tagGroups;
      if ( v45 != nullptr )
        v46 = &v45->list[v63];
      else
        v46 = nullptr;
      v47 = v46->tagList.num;
      if ( v46->name.str == v35 || (v48 = idStr::Cmp(s1: v46->name.str, s2: v35), v49 = 0, v48 == 0) )
        v49 = 1;
      if ( v49 != 0 )
      {
        *tagBias = v41;
        v40 = v46;
        *a28 = v47;
        *a32 = v43;
        v50 = __ROL4__(1, *tagBias);
        if ( *tagBias < *a28 + *tagBias )
        {
          v51 = *a28;
          do
          {
            v52 = *a34 | v50;
            v50 = __ROL4__(v50, 1);
            *a34 = v52;
            --v51;
          }
          while ( v51 != 0 );
        }
        if ( v42 )
          break;
      }
      v53 = __ROL4__(1, v41);
      if ( v47 > 0 )
      {
        v54 = v42;
        v55 = 0;
        do
        {
          v56 = &v46->tagList.list[v55];
          if ( v56->isDefault )
            *a30 |= v53;
          if ( !v54 )
          {
            v64 = -1;
            str = v56->name.str;
            v65 = -1;
            idAnimWebBlendEquation::AddScalar(
              this,
              scalarName: str,
              scalars,
              scalarPairs,
              scalarIndex: &v64,
              scalarPairIndex: &v65);
            v58 = v64;
            if ( v64 >= 0 )
            {
              v59 = &scalarPairs->list[v65];
              v59->scalarIndex = v64;
              v59->node = node;
              v59->coordinateIndex = -1;
              v59->fieldType = 0;
              v59->fieldFlags = scalars->list[v58].flags | v44;
              v59->data1 = v41;
            }
          }
          --v47;
          ++v41;
          v53 = __ROL4__(v53, 1);
          ++v55;
        }
        while ( v47 != 0 );
        v42 = v61;
        v35 = tagGroupName;
      }
      ++v43;
      ++v63;
      if ( v43 >= num )
        break;
      modelInfo = v66;
    }
  }
  return v40;
}


// ========================================================================
// ?ParseAnimList@idAnimWebBlendEquation@@AAAXAAVidLexer@@ABVidModelInfo@idDeclAnimWebNode@@PBVidMD6Model@@PAVidMD6Allocator@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@PBVidDeclAnimWebTagGroup@@AAUanimList_t@1@@Z
// EA  : 0x825F9A10
// RVA : 0x005F9A10
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::ParseAnimList(
        idAnimWebBlendEquation *this,
        idLexer *src,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idMD6Model *model,
        idMD6Allocator *allocator,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        const idDeclAnimWebTagGroup *tagGroup,
        idAnimWebBlendEquation::animList_t *animList)
{
  idList<idAnimWebBlendEquation::existingNode_t,5> *v9; // r27
  idMD6Allocator *v13; // r26
  char v14; // r15
  idMem *v15; // r25
  int num; // r24
  int v17; // r9
  unsigned int v18; // r21
  int v19; // r27
  int v20; // r26
  idMD6Node **v21; // r4
  int v22; // r11
  idMD6AnimProps *v23; // r11
  int v24; // r21
  int v25; // r20
  unsigned int v26; // r18
  int v27; // r22
  int v28; // r23
  idMD6AnimProps *v29; // r25
  idMD6LeafPlay *node; // r26
  int v31; // r27
  idMem *v32; // r27
  idPLog::logEntry_t *v33; // r28
  __int64 v34; // r3
  idPLog::logEntry_t *v35; // r28
  int v36; // r3
  int parent; // r11
  __int64 v38; // r9
  idMD6Leaf::wrapMode_t v39; // r8
  idList<idAnimWebScalarPair,5> *v40; // [sp+8h] [-B08h]
  idAnimWebBlendEquation::animList_t *v41; // [sp+Ch] [-B04h]
  encounterGroupRole_t v42[2]; // [sp+60h] [-AB0h] BYREF
  idMD6Node *v43[2]; // [sp+68h] [-AA8h] BYREF
  idMem *v44; // [sp+70h] [-AA0h]
  _DWORD *v45; // [sp+80h] [-A90h]
  int v46; // [sp+84h] [-A8Ch]
  int v47; // [sp+88h] [-A88h]
  __int16 v48; // [sp+8Ch] [-A84h]
  char v49; // [sp+8Eh] [-A82h]
  char v50; // [sp+8Fh] [-A81h]
  _DWORD v51[3]; // [sp+90h] [-A80h] BYREF
  __int16 v52; // [sp+9Ch] [-A74h]
  __int16 v53; // [sp+9Eh] [-A72h]
  idList<idAnimWebScalar,5> v54; // [sp+A0h] [-A70h] BYREF
  _DWORD v55[4]; // [sp+B0h] [-A60h] BYREF
  idToken v56; // [sp+C0h] [-A50h] BYREF
  char v57; // [sp+108h] [-A08h] BYREF
  idAnimWebBlendEquation::animList_t v58; // [sp+210h] [-900h] BYREF

  v9 = existingNodes;
  v56.floatvalue = -3.4028235e38;
  v56.baseBuffer[0] = 0;
  v56.intvalue = 0;
  memset(&v56.whiteSpaceStart_p, 0, 12);
  v13 = allocator;
  v14 = 1;
  v57 = 0;
  v56.data = &v57;
  v56.len = 0;
  v56.allocedAndFlag = -2147483392;
  v15 = &mem;
  v44 = &mem;
  if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v56) )
  {
    v14 = 0;
    do
    {
      *(_QWORD *)&v54.num = 1;
      v54.list = (idAnimWebScalar *)v55;
      *(_DWORD *)&v54.granularity = 66817;
      v55[0] = &byte_8200D768;
      HIBYTE(v55[1]) = 0;
      LOWORD(v55[1]) = -1;
      v55[2] = 0;
      v47 = 1;
      v46 = 0;
      v48 = 1;
      v45 = v51;
      v49 = 5;
      v50 = 1;
      v51[0] = -1;
      v51[1] = -1;
      v51[2] = 0;
      v52 = 0;
      v53 = 0;
      v58.filterList.size = 10;
      v58.filterList.num = 0;
      v58.filterList.granularity = 1;
      v58.filterList.list = v58.filterList.staticList;
      v58.filterList.memTag = 5;
      v58.filterList.listStatic = 1;
      v58.animList.size = 256;
      v58.animList.num = 0;
      v58.animList.granularity = 1;
      v58.animList.list = v58.animList.staticList;
      v58.animList.memTag = 5;
      v58.animList.listStatic = 1;
      v58.tagList.size = 256;
      v58.tagList.num = 0;
      v58.tagList.granularity = 1;
      v58.tagList.list = v58.tagList.staticList;
      v58.tagList.memTag = 5;
      v58.tagList.listStatic = 1;
      v58.animPropIndex = -1;
      v43[0] = nullptr;
      idAnimWebBlendEquation::Parse_r(
        this,
        src,
        modelInfo,
        model,
        allocator: v13,
        scalars: &v54,
        existingNodes: v9,
        root: v43,
        scalarPairs: v40,
        animList: v41);
      idList<idMD6Filter *,5>::Append(this: &animList->filterList, other: &v58.filterList);
      if ( v58.animPropIndex < 0 )
      {
        idList<idMD6Filter *,5>::Append(
          this: (idList<idMD6Filter *,5> *)&animList->animList,
          other: (const idList<idMD6Filter *,5> *)&v58.animList);
        idList<idMD6Filter *,5>::Append(
          this: (idList<idMD6Filter *,5> *)&animList->tagList,
          other: (const idList<idMD6Filter *,5> *)&v58.tagList);
      }
      else
      {
        num = v58.animList.num;
        v17 = -v58.animList.num & ~v58.animList.num;
        v18 = (unsigned int)v17 >> 31;
        if ( v17 >= 0 )
          num = 1;
        v19 = 0;
        if ( num > 0 )
        {
          v20 = 0;
          do
          {
            if ( v18 != 0 )
              v21 = &v58.animList.list[v20];
            else
              v21 = v43;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&animList->animList,
              obj: (const encounterGroupRole_t *)v21);
            if ( tagGroup != nullptr )
            {
              v22 = v19 + v58.animPropIndex;
              if ( v19 + v58.animPropIndex < 0 || v22 >= modelInfo->animProps.num )
                v23 = nullptr;
              else
                v23 = &modelInfo->animProps.list[v22];
              v42[0] = (encounterGroupRole_t)v23->tags;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&animList->tagList,
                obj: v42);
            }
            ++v19;
            ++v20;
          }
          while ( v19 < num );
          v13 = allocator;
          v15 = v44;
        }
        v9 = existingNodes;
      }
      idAnimWebBlendEquation::animList_t::~animList_t(this: &v58);
      if ( v50 == 0 || v50 == 2 )
      {
        if ( v45 != nullptr )
          idMem::Free(this: v15, ptr: v45, align: ALIGN_16);
        v45 = nullptr;
        v47 = 0;
      }
      v46 = 0;
      if ( v54.listStatic == 0 || v54.listStatic == 2 )
      {
        if ( v54.list != nullptr )
          idMem::Free(this: v15, ptr: v54.list, align: ALIGN_16);
        v54.list = nullptr;
        v54.size = 0;
      }
      v54.num = 0;
    }
    while ( idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v56) );
  }
  if ( v14 != 0 )
  {
    v24 = 0;
    v25 = modelInfo->animProps.num;
    if ( v25 > 0 )
    {
      v26 = (-v9->num & (unsigned int)~v9->num) >> 31;
      v27 = 0;
      v28 = 0;
      while ( 1 )
      {
        v29 = v24 < 0 || v24 >= modelInfo->animProps.num ? nullptr : &modelInfo->animProps.list[v28];
        if ( v26 != 0 )
        {
          node = (idMD6LeafPlay *)v9->list[v27].node;
        }
        else
        {
          node = (idMD6LeafPlay *)v13->Alloc(this: v13, a2: NODE_LEAF_PLAY);
          RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
          v31 = -1;
          v43[1] = (idMD6Node *)&pLog;
          v43[0] = (idMD6Node *)-1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            v32 = v44;
            idMem::PushHeap(this: v44, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v33 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v33 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v32);
            v33->label = "idAnimWebBlendEquation - allocatedNodes.Append";
            v33->parent = pLog.lastEntry;
            v31 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v43[0] = (idMD6Node *)(pLog.logEntries.num - 1);
            LODWORD(v34) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v33->totalTicks = v34;
          }
          v42[0] = (encounterGroupRole_t)node;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
            obj: v42);
          if ( v31 >= 0 )
          {
            v35 = &pLog.logEntries.list[v31];
            v36 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            parent = v35->parent;
            LODWORD(v38) = v36 - LODWORD(v35->totalTicks);
            v43[0] = (idMD6Node *)-1;
            v35->totalTicks = v38;
            pLog.lastEntry = parent;
          }
          RD_EventEnd();
          idMD6LeafPlay::Init(
            this: node,
            anim: v29->anim,
            gameTime: this->startTime,
            ticksPerSec: this->ticksPerSec,
            frame: 0,
            rateScale: v29->rate,
            wrapMode: v39,
            weightGroup: (const md6WeightGroup_t)v29->wrap);
        }
        v42[0] = (encounterGroupRole_t)node;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&animList->animList,
          obj: v42);
        if ( tagGroup != nullptr )
        {
          v42[0] = (encounterGroupRole_t)v29->tags;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&animList->tagList,
            obj: v42);
        }
        ++v24;
        ++v28;
        ++v27;
        if ( v24 >= v25 )
          break;
        v13 = allocator;
        v9 = existingNodes;
      }
    }
  }
  idStr::FreeData(this: &v56);
}


// ========================================================================
// __unwind$225595
// EA  : 0x825F9F84
// RVA : 0x005F9F84
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2832 + 192));
}


// ========================================================================
// __unwind$225596
// EA  : 0x825F9FAC
// RVA : 0x005F9FAC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225596()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2832 + 160));
}


// ========================================================================
// __unwind$225597
// EA  : 0x825F9FD4
// RVA : 0x005F9FD4
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225597()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2832 + 128));
}


// ========================================================================
// __unwind$225598
// EA  : 0x825F9FFC
// RVA : 0x005F9FFC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225598()
{
  int v0; // r12

  idAnimWebBlendEquation::animList_t::~animList_t(this: (idAnimWebBlendEquation::animList_t *)(v0 - 2832 + 528));
}


// ========================================================================
// __unwind$225599
// EA  : 0x825FA024
// RVA : 0x005FA024
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225599()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2832 + 2668));
}


// ========================================================================
// __unwind$225600
// EA  : 0x825FA04C
// RVA : 0x005FA04C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_225600()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2832 + 104));
}


// ========================================================================
// ?ParseScalar@idAnimWebBlendEquation@@AAAXAAVidLexer@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@VidAnimWebScalarPair@@$04@@AAH3AAMAA_N@Z
// EA  : 0x825FA080
// RVA : 0x005FA080
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::ParseScalar(
        idAnimWebBlendEquation *this,
        idLexer *src,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        int *scalarIndex,
        int *scalarPairIndex,
        float *value,
        bool *isCopyOnPlay)
{
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idPLogScope v18[2]; // [sp+50h] [-1C0h] BYREF
  idToken v19; // [sp+60h] [-1B0h] BYREF
  char v20; // [sp+A8h] [-168h] BYREF

  RD_EventBegin(name: "idAnimWebBlendEquation::ParseScalar");
  LODWORD(v16) = "idAnimWebBlendEquation::ParseScalar";
  HIDWORD(v16) = 2;
  idPLogScope::idPLogScope(this: v18, pl: &pLog, gMask: v16, label: v17);
  *scalarIndex = -1;
  *scalarPairIndex = -1;
  v19.baseBuffer[0] = 0;
  *value = 0.0;
  *isCopyOnPlay = false;
  v19.floatvalue = -3.4028235e38;
  v19.intvalue = 0;
  memset(&v19.whiteSpaceStart_p, 0, 12);
  v20 = 0;
  v19.data = &v20;
  v19.len = 0;
  v19.allocedAndFlag = -2147483392;
  idLexer::ReadToken(this: src, token: &v19);
  if ( v19.type == 3 )
  {
    *value = idToken::GetFloatValue(this: &v19);
    idStr::FreeData(this: &v19);
    idPLogScope::~idPLogScope(this: v18);
  }
  else if ( v19.type != 5 || idStr::Cmp(s1: v19.data, s2: "-") != 0 )
  {
    *isCopyOnPlay = idAnimWebBlendEquation::ParseScalarName(this, src, token: &v19);
    idAnimWebBlendEquation::AddScalar(this, scalarName: v19.data, scalars, scalarPairs, scalarIndex, scalarPairIndex);
    idStr::FreeData(this: &v19);
    idPLogScope::~idPLogScope(this: v18);
  }
  else
  {
    idLexer::ExpectTokenType(this: src, type: 3, subtype: 0, token: &v19);
    *value = -idToken::GetFloatValue(this: &v19);
    idStr::FreeData(this: &v19);
    idPLogScope::~idPLogScope(this: v18);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$226065
// EA  : 0x825FA210
// RVA : 0x005FA210
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226065()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 528 + 424));
}


// ========================================================================
// __unwind$226066
// EA  : 0x825FA238
// RVA : 0x005FA238
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226066()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 528 + 80));
}


// ========================================================================
// __unwind$226067
// EA  : 0x825FA260
// RVA : 0x005FA260
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226067()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 96));
}


// ========================================================================
// ?ParseNode@idAnimWebBlendEquation@@AAAXAAVidLexer@@PBDPBVidMD6Model@@PAVidMD6Allocator@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@AAPAVidMD6Node@@AAV?$idList@VidAnimWebScalarPair@@$04@@PAUanimList_t@1@@Z
// EA  : 0x825FA290
// RVA : 0x005FA290
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::ParseNode(
        idAnimWebBlendEquation *this,
        idLexer *src,
        const char *name,
        const idMD6Model *model,
        idMD6Allocator *allocator,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        idMD6Node **root,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        idAnimWebBlendEquation::animList_t *animList,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idList<idAnimWebScalarPair,5> *a28,
        int a29,
        int a30)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  bool v38; // r23
  int v39; // r25
  double v40; // fp30
  double v41; // fp31
  int num; // r22
  int v43; // r21
  char v44; // r20
  __int64 v45; // r10
  __int64 v46; // r10
  double v47; // fp0
  __int64 v48; // r11
  __int64 v49; // r11
  int v50; // r27
  bool v51; // r24
  double v52; // fp26
  double v53; // fp1
  double v54; // fp28
  int v55; // r26
  md6WeightGroup_t v56; // r7
  idMD6Leaf::wrapMode_t v57; // r6
  double v58; // fp1
  int v59; // r29
  idList<idAnimWebBlendEquation::existingNode_t,5> *v60; // r10
  int v61; // r30
  idMD6Node *node; // r11
  int type; // r9
  idMD6Node *v64; // r3
  const char *v65; // r5
  int v66; // r11
  char v67; // r10
  char v68; // r10
  char v69; // r10
  const char *v70; // r9
  double v71; // fp29
  double v72; // fp31
  const char *v73; // r27
  int v74; // r30
  int v75; // r29
  md6WeightGroup_t v76; // r7
  idMD6Leaf::wrapMode_t v77; // r6
  idMD6Node *v78; // r30
  int v79; // r11
  char v80; // r10
  unsigned __int8 v81; // r10
  idMD6Node *v82; // r3
  unsigned __int8 v83; // r11
  unsigned __int8 v84; // r10
  char v85; // r11
  bool v86; // r29
  int i; // r30
  char v88; // r11
  const idMD6Anim *v89; // r27
  idMD6LeafPlay *v90; // r28
  int v91; // r29
  idPLog::logEntry_t *v92; // r30
  __int64 v93; // r3
  idPLog::logEntry_t *v94; // r30
  int v95; // r3
  int parent; // r11
  __int64 v97; // r9
  idMD6Leaf::wrapMode_t v98; // r8
  int v99; // r29
  idPLog::logEntry_t *v100; // r30
  __int64 v101; // r3
  idPLog::logEntry_t *v102; // r30
  int v103; // r3
  int v104; // r11
  __int64 v105; // r9
  idMD6Leaf::wrapMode_t v106; // r5
  int v107; // r28
  int v108; // r29
  int v109; // r30
  int v110; // r11
  int v111; // r11
  int size; // r10
  idAnimWebScalarPair *list; // r10
  idAnimWebScalarPair *v114; // r11
  idAnimWebScalarPair *v115; // r10
  encounterGroupRole_t v116; // r7
  char v117; // r9
  idAnimWebScalarPair *v118; // r11
  int v119; // r4
  idPLog *v120; // r29
  idPLog::logEntry_t *v121; // r30
  int v122; // r3
  __int64 v123; // r11
  __int64 v124; // r9
  int v125; // r11
  const char *v126; // r6
  int v127; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v129; // r30
  int v130; // r3
  __int64 totalTicks; // r11
  __int64 v132; // r9
  int v133; // [sp+8h] [-2F8h]
  int v134; // [sp+Ch] [-2F4h]
  int v135; // [sp+10h] [-2F0h]
  int v136; // [sp+14h] [-2ECh]
  int v137; // [sp+18h] [-2E8h]
  int v138; // [sp+1Ch] [-2E4h]
  double v139; // [sp+20h] [-2E0h]
  int v140; // [sp+28h] [-2D8h]
  int v141; // [sp+2Ch] [-2D4h]
  int v142; // [sp+30h] [-2D0h]
  int v143; // [sp+34h] [-2CCh]
  int v144; // [sp+38h] [-2C8h]
  int v145; // [sp+3Ch] [-2C4h]
  int v146; // [sp+40h] [-2C0h]
  int v147; // [sp+44h] [-2BCh]
  int v148; // [sp+48h] [-2B8h]
  int v149; // [sp+4Ch] [-2B4h]
  int v150; // [sp+50h] [-2B0h]
  bool v151; // [sp+60h] [-2A0h] BYREF
  float v152; // [sp+64h] [-29Ch] BYREF
  float v153; // [sp+68h] [-298h] BYREF
  bool v154[4]; // [sp+6Ch] [-294h] BYREF
  __int64 v155; // [sp+70h] [-290h] BYREF
  __int16 v156; // [sp+78h] [-288h]
  float v157; // [sp+7Ch] [-284h] BYREF
  int v158[2]; // [sp+80h] [-280h] BYREF
  int v159[2]; // [sp+88h] [-278h] BYREF
  idMD6LeafPlay *v160; // [sp+90h] [-270h] BYREF
  int v161; // [sp+94h] [-26Ch]
  const char *v162; // [sp+98h] [-268h]
  idPLogScope v163; // [sp+A0h] [-260h] BYREF
  _DWORD v164[2]; // [sp+A8h] [-258h] BYREF
  _DWORD v165[2]; // [sp+B0h] [-250h] BYREF
  int v166; // [sp+B8h] [-248h]
  idPLog *v167; // [sp+BCh] [-244h]
  idStr v168; // [sp+C0h] [-240h] BYREF
  idToken v169; // [sp+E0h] [-220h] BYREF
  char v170; // [sp+128h] [-1D8h] BYREF

  RD_EventBegin(name: "idAnimWebBlendEquation::ParseNode");
  LODWORD(v36) = "idAnimWebBlendEquation::ParseNode";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: &v163, pl: &::pLog, gMask: v36, label: v37);
  v38 = false;
  v169.baseBuffer[0] = 0;
  v169.intvalue = 0;
  v169.floatvalue = -3.4028235e38;
  memset(&v169.whiteSpaceStart_p, 0, 12);
  v170 = 0;
  v169.data = &v170;
  v169.len = 0;
  v169.allocedAndFlag = -2147483392;
  *root = nullptr;
  v162 = "anim";
  if ( a30 != 0 && idStr::Find(searchIn: name, searchFor: "anim", casesensitive: true, start: 0, end: -1) == 0 )
    *(_DWORD *)(a30 + 2136) = atol(nptr: name + 4);
  v154[0] = false;
  v159[0] = -1;
  v157 = NAN;
  v153 = 0.0;
  *(float *)v158 = 0.0;
  v39 = -1;
  v40 = 0.0;
  v152 = NAN;
  v41 = 0.0;
  v160 = (idMD6LeafPlay *)-1;
  v156 = 2;
  num = 0;
  v43 = 0;
  v44 = 0;
  if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 48, token: &v169) )
  {
    idAnimWebBlendEquation::ParseScalar(
      this,
      src,
      scalars,
      scalarPairs: a28,
      scalarIndex: (int *)&v152,
      scalarPairIndex: (int *)&v160,
      value: &v153,
      isCopyOnPlay: v154);
    if ( idStr::Icmp(s1: name, s2: "anim") != 0 )
      idLexer::Error(this: src, str: "Unrecognized anim array name '%s' - must use syntax 'anim[ ... ]'", name);
    v39 = LODWORD(v152);
    v40 = v153;
    if ( v152 < 0.0 )
    {
      if ( v40 < 0.0 || (LODWORD(v45) = existingNodes->num, v155 = v45, v40 >= (float)v45) )
        idLexer::Error(this: src, str: "Blend equation uses 'anim' array, but array index is out of bounds!");
      LODWORD(v45) = (int)v40;
      v155 = v45;
      if ( (float)v45 != v40 )
      {
        v139 = v40;
        idLexer::Error(this: src, str: (const char *)HIDWORD(v40), LODWORD(v40), v40);
      }
      if ( a30 != 0 && idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v169) )
      {
        idAnimWebBlendEquation::ParseScalar(
          this,
          src,
          scalars,
          scalarPairs: a28,
          scalarIndex: v159,
          scalarPairIndex: (int *)&v157,
          value: (float *)v158,
          isCopyOnPlay: &v151);
        v41 = *(float *)v158;
        if ( *(float *)v158 < 0.0 || (LODWORD(v46) = existingNodes->num, v155 = v46, v41 >= (float)v46) )
          idLexer::Error(this: src, str: "Blend equation uses 'anim' array, but span index is out of bounds!");
        LODWORD(v46) = (int)v41;
        v155 = v46;
        if ( (float)v46 != v41 )
        {
          v139 = v41;
          idLexer::Error(this: src, str: (const char *)HIDWORD(v41), LODWORD(v41), v41);
        }
        if ( v40 > v41 )
        {
          v47 = v40;
          v40 = v41;
          v41 = v47;
        }
        v44 = 1;
        *(_DWORD *)(a30 + 2136) = (int)v40;
      }
    }
    if ( v44 == 0 )
    {
      if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 29, token: &v169) )
      {
        if ( idLexer::CheckTokenString(this: src, string: "_numanims") )
        {
          num = existingNodes->num;
        }
        else
        {
          v152 = 0.0;
          idAnimWebBlendEquation::ParseImmediate(this, src, value: &v152);
          num = (int)v152;
          LODWORD(v48) = num;
          v155 = v48;
          if ( (float)v48 != v152 )
          {
            v139 = v152;
            idLexer::Error(this: src, str: "non-integer anim index modulo used (%f)!", v152);
          }
        }
      }
      if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 30, token: &v169) )
      {
        v152 = 0.0;
        idAnimWebBlendEquation::ParseImmediate(this, src, value: &v152);
        v43 = (int)v152;
        LODWORD(v49) = v43;
        v155 = v49;
        if ( (float)v49 != v152 )
        {
          v139 = v152;
          idLexer::Error(
            this: src,
            str: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v152)),
            (unsigned int)COERCE_UNSIGNED_INT64(v152));
        }
      }
    }
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 49, token: &v169);
  }
  v153 = COERCE_FLOAT(idAnimWebBlendEquation::ParseWeightGroup(this, src));
  v158[0] = -1;
  v152 = NAN;
  v151 = false;
  v50 = -1;
  *(float *)v159 = 1.0;
  v51 = false;
  v52 = 1.0;
  if ( idLexer::PeekTokenType(this: src, type: 5, subtype: 27, token: &v169)
    || idLexer::PeekTokenType(this: src, type: 4, subtype: 0, token: &v169) )
  {
    idLexer::ReadToken(this: src, token: &v169);
    if ( idStr::Icmp(s1: v169.data, s2: "scaled") == 0 )
      idLexer::CheckTokenString(this: src, string: "by");
    if ( idLexer::PeekTokenType(this: src, type: 3, subtype: 128, token: &v169) )
    {
      v53 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v52 = v53;
      if ( v53 <= 0.0 || v53 >= 9.0 )
        idLexer::Error(this: src, str: "Specified rate scale is out of range. Must be between 0.0f and 9.0f");
    }
    else
    {
      idAnimWebBlendEquation::ParseScalar(
        this,
        src,
        scalars,
        scalarPairs: a28,
        scalarIndex: (int *)&v152,
        scalarPairIndex: v158,
        value: (float *)v159,
        isCopyOnPlay: &v151);
      v50 = LODWORD(v152);
      v52 = *(float *)v159;
      v51 = v151;
    }
  }
  v157 = 0.0;
  v54 = 0.0;
  v159[0] = -1;
  v152 = NAN;
  v55 = -1;
  v151 = false;
  if ( idLexer::PeekTokenType(this: src, type: 5, subtype: 55, token: &v169)
    || idLexer::PeekTokenType(this: src, type: 4, subtype: 0, token: &v169) )
  {
    idLexer::ReadToken(this: src, token: &v169);
    if ( idStr::Icmp(s1: v169.data, s2: "paused") == 0 )
      idLexer::CheckTokenString(this: src, string: "at");
    if ( idLexer::PeekTokenType(this: src, type: 3, subtype: 128, token: &v169) )
    {
      v58 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v54 = v58;
      if ( v58 <= 0.0 || v58 >= 1.0 )
        idLexer::Error(
          this: src,
          str: "Specified normalized pause frame is out of range. Must be between 0.0f and 1.0f");
    }
    else
    {
      idAnimWebBlendEquation::ParseScalar(
        this,
        src,
        scalars,
        scalarPairs: a28,
        scalarIndex: v159,
        scalarPairIndex: (int *)&v152,
        value: &v157,
        isCopyOnPlay: &v151);
      v156 = 1;
      v55 = v159[0];
      v54 = v157;
      v38 = v151;
    }
  }
  v157 = COERCE_FLOAT("unhandled node type in anim web blend equation!");
  if ( v39 >= 0 )
  {
    v59 = 0;
    if ( existingNodes->num > 0 )
    {
      v60 = existingNodes;
      v61 = 0;
      do
      {
        node = v60->list[v61].node;
        type = node->type;
        v159[0] = (int)node;
        if ( type != 2 )
        {
          v159[0] = (int)node;
          if ( (unsigned __int8)type != 1 )
          {
            idLexer::Error(
              this: src,
              str: "'anim' arrays can only index leaves that are idMD6LeafPlay or idMD6LeafPause!");
            v60 = existingNodes;
          }
        }
        ++v59;
        ++v61;
      }
      while ( v59 < v60->num );
    }
    if ( v156 == 1 )
    {
      v64 = idAnimWebBlendEquation::AddLeafPauseFromDefaultLeaf(
              this,
              allocator,
              existingNodes,
              animIndex: v40,
              frame: v54,
              wrapMode: v57,
              weightGroup: v56,
              a8: MD6_WEIGHTGROUP_LEGS);
    }
    else
    {
      if ( v156 != 2 )
      {
        idLexer::Error(this: src, str: (const char *)LODWORD(v157));
LABEL_64:
        v65 = (const char *)*root;
        v66 = (int)&a28->list[(_DWORD)v160];
        v67 = _cntlzw(v154[0]);
        *(_DWORD *)v66 = v39;
        *(_BYTE *)(v66 + 12) = 2;
        *(_DWORD *)(v66 + 8) = v65;
        *(_DWORD *)(v66 + 4) = -1;
        v68 = scalars->list[v39].flags | (((v67 & 0x20) == 0) + 1);
        *(_BYTE *)(v66 + 13) = v68;
        if ( num >= 1 )
        {
          *(_BYTE *)(v66 + 14) = num;
          *(_BYTE *)(v66 + 13) = v68 | 4;
        }
        if ( v43 >= 1 )
        {
          v69 = *(_BYTE *)(v66 + 13);
          *(_BYTE *)(v66 + 15) = v43;
          *(_BYTE *)(v66 + 13) = v69 | 8;
        }
        goto LABEL_68;
      }
      v64 = idAnimWebBlendEquation::AddLeafPlayFromDefaultLeaf(
              this,
              allocator,
              existingNodes,
              animIndex: v40,
              startTime: v57,
              ticksPerSec: this->startTime,
              startFrame: this->ticksPerSec,
              rateScale: v52,
              wrapMode: 0,
              weightGroup: MD6_WEIGHTGROUP_LEGS,
              a11: v133,
              a12: v134,
              a13: v135,
              a14: v136,
              a15: v137,
              a16: v138,
              a17: SHIDWORD(v139),
              a18: SLODWORD(v139),
              a19: v140,
              a20: v141,
              a21: v142,
              a22: v143,
              a23: v144,
              a24: v145,
              a25: v146,
              a26: v147,
              a27: v148,
              a28: v149,
              a29: v150,
              a30: MD6_WEIGHTGROUP_LEGS);
    }
    *root = v64;
    goto LABEL_64;
  }
LABEL_68:
  v70 = (const char *)*root;
  if ( *root != nullptr )
  {
    if ( v50 >= 0 )
    {
      v125 = (int)&a28->list[v158[0]];
      v162 = (const char *)*root;
      *(_DWORD *)(v125 + 8) = v70;
      *(_DWORD *)v125 = v50;
      *(_DWORD *)(v125 + 4) = -1;
      *(_BYTE *)(v125 + 12) = 1;
      *(_BYTE *)(v125 + 13) = scalars->list[v50].flags | (((_cntlzw(v51) & 0x20) == 0) + 1);
      scalars->list[v50].flags = 1;
    }
    if ( v55 >= 0 )
    {
      v126 = (const char *)*root;
      v127 = (int)&a28->list[LODWORD(v152)];
      *(_BYTE *)(v127 + 12) = 3;
      *(_DWORD *)v127 = v55;
      *(_DWORD *)(v127 + 4) = -1;
      *(_DWORD *)(v127 + 8) = v126;
      *(_BYTE *)(v127 + 13) = scalars->list[v55].flags | (((_cntlzw(v38) & 0x20) == 0) + 1);
    }
    idStr::FreeData(this: &v169);
    if ( v163.logIndex >= 0 )
    {
      pLog = v163.pLog;
      v129 = &v163.pLog->logEntries.list[v163.logIndex];
      v130 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v129->totalTicks;
      HIDWORD(totalTicks) = v129->parent;
      LODWORD(v132) = v130 - totalTicks;
      v129->totalTicks = v132;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    if ( v44 != 0 )
      v71 = (float)((float)((float)v41 - (float)v40) + (float)1.0);
    else
      v71 = 1.0;
    v72 = 0.0;
    if ( v71 > 0.0 )
    {
      v154[1] = v38;
      v164[1] = v55;
      v155 = 0x100000003LL;
      v154[0] = v51;
      v164[0] = v50;
      while ( 1 )
      {
        idStr::idStr(this: &v168, text: name);
        v73 = v162;
        if ( idStr::Icmp(s1: name, s2: v162) == 0 )
        {
          v161 = (int)(float)((float)v72 + (float)v40);
          idStr::Format(this: &v168, fmt: "anim%d", v161);
        }
        v74 = 0;
        if ( existingNodes->num > 0 )
          break;
LABEL_100:
        if ( *root == nullptr )
        {
          v85 = _cntlzw(idStr::Find(searchIn: name, searchFor: v73, casesensitive: true, start: 0, end: -1));
          v86 = (v85 & 0x20) != 0;
          if ( (v85 & 0x20) != 0 && v44 == 0 )
          {
            for ( i = 4; i < 256; ++i )
            {
              v88 = name[i];
              if ( v88 == 0 )
                break;
              if ( isdigit(c: v88) == 0 )
              {
                v86 = false;
                break;
              }
            }
          }
          v89 = nullptr;
          if ( !v86 )
          {
            v89 = (const idMD6Anim *)idResourceList::Load(
                                       this: &idMD6Anim::resourceList,
                                       name,
                                       makeDefault: true,
                                       skipStaleCheck: false);
            if ( v89 != nullptr )
              idLexer::Error(this: src, str: "'%s' is not a valid animation or leaf node name.", name);
          }
          if ( v156 == 2 )
          {
            v90 = (idMD6LeafPlay *)allocator->Alloc(this: allocator, a2: 2);
            RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
            v91 = -1;
            v159[1] = (int)&::pLog;
            v159[0] = -1;
            if ( (::pLog.groupMask & 2) != 0 )
            {
              idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
              idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
                this: &::pLog.logEntries,
                newSize: ::pLog.logEntries.num + 1);
              if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
                v92 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
              else
                v92 = &::pLog.logEntries.list[::pLog.logEntries.num++];
              idMem::PopHeap(this: &mem);
              v92->label = "idAnimWebBlendEquation - allocatedNodes.Append";
              v92->parent = ::pLog.lastEntry;
              v91 = ::pLog.logEntries.num - 1;
              ::pLog.lastEntry = ::pLog.logEntries.num - 1;
              v159[0] = ::pLog.logEntries.num - 1;
              LODWORD(v93) = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v92->totalTicks = v93;
            }
            v160 = v90;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
              obj: (const encounterGroupRole_t *)&v160);
            if ( v91 >= 0 )
            {
              v94 = &::pLog.logEntries.list[v91];
              v95 = (unsigned __int64)Sys_GetClockTicks() >> 32;
              parent = v94->parent;
              LODWORD(v97) = v95 - LODWORD(v94->totalTicks);
              v159[0] = -1;
              v94->totalTicks = v97;
              ::pLog.lastEntry = parent;
            }
            RD_EventEnd();
            idMD6LeafPlay::Init(
              this: v90,
              anim: v89,
              gameTime: this->startTime,
              ticksPerSec: this->ticksPerSec,
              frame: 0,
              rateScale: v52,
              wrapMode: v98,
              weightGroup: MD6_WEIGHTGROUP_LEGS);
            goto LABEL_130;
          }
          if ( v156 == 1 )
          {
            v90 = (idMD6LeafPlay *)allocator->Alloc(this: allocator, a2: 1);
            RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
            v99 = -1;
            v167 = &::pLog;
            v166 = -1;
            if ( (::pLog.groupMask & 2) != 0 )
            {
              idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
              idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
                this: &::pLog.logEntries,
                newSize: ::pLog.logEntries.num + 1);
              if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
                v100 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
              else
                v100 = &::pLog.logEntries.list[::pLog.logEntries.num++];
              idMem::PopHeap(this: &mem);
              v100->label = "idAnimWebBlendEquation - allocatedNodes.Append";
              v100->parent = ::pLog.lastEntry;
              v99 = ::pLog.logEntries.num - 1;
              ::pLog.lastEntry = ::pLog.logEntries.num - 1;
              v166 = ::pLog.logEntries.num - 1;
              LODWORD(v101) = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v100->totalTicks = v101;
            }
            v160 = v90;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
              obj: (const encounterGroupRole_t *)&v160);
            if ( v99 >= 0 )
            {
              v102 = &::pLog.logEntries.list[v99];
              v103 = (unsigned __int64)Sys_GetClockTicks() >> 32;
              v104 = v102->parent;
              LODWORD(v105) = v103 - LODWORD(v102->totalTicks);
              v166 = -1;
              v102->totalTicks = v105;
              ::pLog.lastEntry = v104;
            }
            RD_EventEnd();
            idMD6LeafPause::Init(
              this: (idMD6LeafPause *)v90,
              anim: v89,
              frame: v54,
              wrapMode: v106,
              weightGroup: MD6_WEIGHTGROUP_LEGS);
LABEL_130:
            *root = v90;
          }
          if ( v44 != 0 )
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)(a30 + 56),
              obj: (const encounterGroupRole_t *)root);
        }
        v107 = 0;
        v108 = 0;
        v165[0] = v158[0];
        *(float *)&v165[1] = v152;
        do
        {
          v109 = v164[v108];
          if ( v109 >= 0 )
          {
            if ( v72 > 0.0 )
            {
              v110 = a28->num;
              v165[v108] = v110;
              idList<idAnimWebScalarPair,5>::PreAllocateWithGranularity(this: a28, newSize: v110 + 1);
              v111 = a28->num;
              size = a28->size;
              if ( v111 >= size )
              {
                v114 = &a28->list[size - 1];
              }
              else
              {
                list = a28->list;
                a28->num = v111 + 1;
                v114 = &list[v111];
              }
              v114->scalarIndex = v109;
            }
            v115 = a28->list;
            v116 = (encounterGroupRole_t)*root;
            v160 = (idMD6LeafPlay *)v109;
            v117 = _cntlzw(v154[v107]);
            v118 = &v115[v165[v108]];
            v119 = (unsigned __int8)*(_DWORD *)((char *)&v155 + v108 * 4);
            v118->fieldType = v119;
            v118->node = (idMD6Node *)v116;
            v118->scalarIndex = v109;
            v118->coordinateIndex = -1;
            v118->fieldFlags = scalars->list[v109].flags | (((v117 & 0x20) == 0) + 1);
            if ( v119 == 1 )
              scalars->list[v109].flags = 1;
          }
          ++v108;
          ++v107;
        }
        while ( v108 < 2 );
        idStr::FreeData(this: &v168);
        v72 = (float)((float)v72 + (float)1.0);
        if ( v72 >= v71 )
          goto LABEL_144;
      }
      v75 = 0;
      while ( idStr::Icmp(s1: existingNodes->list[v75].name, s2: v168.data) != 0 )
      {
        ++v74;
        ++v75;
        if ( v74 >= existingNodes->num )
          goto LABEL_100;
      }
      v78 = existingNodes->list[v74].node;
      v79 = v78->type;
      if ( v78->type == 0 || v79 == 3 || v79 == 4 || (v80 = 0, v79 == 5) )
        v80 = 1;
      if ( v80 != 0 )
      {
        v78[20].type = *(_BYTE *)((unsigned __int8)&v153 + 3);
        *root = v78;
        goto LABEL_100;
      }
      if ( v156 == 1 )
      {
        if ( v79 == 1 )
        {
          v83 = v78[9].type;
          *(float *)&v78[52].type = v54;
          v84 = LOBYTE(v153);
          v78[9].type = v83;
          v78[8].type = v84;
          *root = v78;
          goto LABEL_98;
        }
        v82 = idAnimWebBlendEquation::AddLeafPauseFromDefaultLeaf(
                this,
                allocator,
                existingNodes,
                animIndex: (float)((float)v72 + (float)v40),
                frame: v54,
                wrapMode: v77,
                weightGroup: v76,
                a8: MD6_WEIGHTGROUP_LEGS);
      }
      else
      {
        if ( v156 != 2 )
        {
          idLexer::Error(this: src, str: (const char *)LODWORD(v157));
          goto LABEL_98;
        }
        if ( v79 == 2 )
        {
          v81 = LOBYTE(v153);
          v78[9].type = v78[9].type;
          v78[8].type = v81;
          *(_DWORD *)&v78[12].type = this->startTime;
          idMD6LeafPlay::SetFrame(
            this: (idMD6LeafPlay *)v78,
            gameTime: this->startTime,
            ticksPerSec: this->ticksPerSec,
            targetFrame: 0);
          *root = v78;
          goto LABEL_98;
        }
        v82 = idAnimWebBlendEquation::AddLeafPlayFromDefaultLeaf(
                this,
                allocator,
                existingNodes,
                animIndex: (float)((float)v72 + (float)v40),
                startTime: v77,
                ticksPerSec: this->startTime,
                startFrame: this->ticksPerSec,
                rateScale: v52,
                wrapMode: 0,
                weightGroup: MD6_WEIGHTGROUP_LEGS,
                a11: v133,
                a12: v134,
                a13: v135,
                a14: v136,
                a15: v137,
                a16: v138,
                a17: SHIDWORD(v139),
                a18: SLODWORD(v139),
                a19: v140,
                a20: v141,
                a21: v142,
                a22: v143,
                a23: v144,
                a24: v145,
                a25: v146,
                a26: v147,
                a27: v148,
                a28: v149,
                a29: v150,
                a30: MD6_WEIGHTGROUP_LEGS);
      }
      *root = v82;
LABEL_98:
      if ( v44 != 0 )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)(a30 + 56),
          obj: (const encounterGroupRole_t *)root);
      goto LABEL_100;
    }
LABEL_144:
    idStr::FreeData(this: &v169);
    if ( v163.logIndex >= 0 )
    {
      v120 = v163.pLog;
      v121 = &v163.pLog->logEntries.list[v163.logIndex];
      v122 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v123 = v121->totalTicks;
      HIDWORD(v123) = v121->parent;
      LODWORD(v124) = v122 - v123;
      v121->totalTicks = v124;
      v120->lastEntry = HIDWORD(v123);
    }
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$226250
// EA  : 0x825FB308
// RVA : 0x005FB308
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226250()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 768 + 552));
}


// ========================================================================
// __unwind$226251
// EA  : 0x825FB330
// RVA : 0x005FB330
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226251()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 768 + 160));
}


// ========================================================================
// __unwind$226252
// EA  : 0x825FB358
// RVA : 0x005FB358
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226252()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 768 + 224));
}


// ========================================================================
// __unwind$226253
// EA  : 0x825FB380
// RVA : 0x005FB380
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226253()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 768 + 192));
}


// ========================================================================
// __unwind$226254
// EA  : 0x825FB3A8
// RVA : 0x005FB3A8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226254()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 768 + 553));
}


// ========================================================================
// __unwind$226255
// EA  : 0x825FB3D0
// RVA : 0x005FB3D0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226255()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 768 + 136));
}


// ========================================================================
// __unwind$226256
// EA  : 0x825FB3F8
// RVA : 0x005FB3F8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226256()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 768 + 554));
}


// ========================================================================
// __unwind$226257
// EA  : 0x825FB420
// RVA : 0x005FB420
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226257()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 768 + 184));
}


// ========================================================================
// ?ParseBlend@idAnimWebBlendEquation@@AAAX_NHAAVidLexer@@ABVidModelInfo@idDeclAnimWebNode@@PBVidMD6Model@@PAVidMD6Allocator@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@VidAnimWebScalarPair@@$04@@AAV?$idList@V?$idIndex@FW4invalidUserChannelIndex_t@@@@$04@@AAV?$idList@M$04@@AAV?$idList@PAVidMD6Node@@$04@@9AAV?$idList@H$04@@AAV?$idList@H$04@@AAV?$idList@_N$04@@AAW4md6WeightGroup_t@@PAPAVidMD6Node@@@Z
// EA  : 0x825FB450
// RVA : 0x005FB450
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::ParseBlend(
        idAnimWebBlendEquation *this,
        const bool useUserChannels,
        int numDimensions,
        idLexer *src,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idMD6Model *model,
        idMD6Allocator *allocator,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *userChannelIndices,
        idList<float,5> *coordinateList,
        idList<idMD6Node *,5> *animationList,
        idList<float,5> *currentCoordinate,
        idList<int,5> *currentCoordinateScalarIndex,
        idList<int,5> *currentCoordinateScalarPairIndex,
        idList<bool,5> *isCopyOnPlay,
        md6WeightGroup_t *wg,
        idMD6Node **baseAnimation,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idList<idAnimWebScalar,5> *a28,
        int a29,
        idList<idAnimWebScalarPair,5> *a30,
        int a31,
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *a32,
        int a33,
        idList<float,13> *a34,
        int a35,
        idList<idSpawnArea::GeneratedPosition *,5> *scalarsa,
        int a37,
        idList<float,13> *scalarPairsa,
        int a39,
        idList<idSpawnArea::GeneratedPosition *,5> *userChannelIndicesa,
        int a41,
        idList<idSpawnArea::GeneratedPosition *,5> *coordinateLista,
        int a43,
        idList<idMD6Node *,5> *animationLista,
        int a45,
        idList<float,5> *currentCoordinatea,
        int a47,
        idMD6Node **currentCoordinateScalarIndexa)
{
  int size; // r11
  int v56; // r11
  int v57; // r11
  int v58; // r29
  int v59; // r30
  int i; // r30
  const idMD6Skel *skeleton; // r24
  const idHandle<unsigned short,enum invalidCrc_t,65535> *value; // r14
  int num; // r11
  int v64; // r25
  int v65; // r30
  int v66; // r29
  int v67; // r11
  int v68; // r11
  idResourceList *resourceListPtr; // r11
  const char *str; // r8
  int v71; // r11
  idMD6AnimProps *v72; // r11
  const idMD6AnimData *animData; // r30
  int AnimMapIndex; // r3
  __int16 v75; // r6
  unsigned int v76; // r29
  unsigned int v77; // r28
  bool v78; // r27
  bool v79; // r29
  int j; // r30
  double floatvalue; // fp0
  int v82; // r30
  int v83; // r29
  int v84; // r28
  __int16 v85; // r9
  idList<float,32> *coordinates; // r11
  char v87; // r11
  idResource *v88; // r10
  signed int v89; // r9
  int animPropIndex; // r11
  int trackedMemory; // r7
  idResource_vtbl *v92; // r6
  idList<idAnimWebScalarPair,5> *v93; // [sp+8h] [-1058h]
  idAnimWebBlendEquation::animList_t *v94; // [sp+Ch] [-1054h]
  float v95; // [sp+60h] [-1000h] BYREF
  bool v96; // [sp+64h] [-FFCh] BYREF
  int v97; // [sp+68h] [-FF8h]
  int v98; // [sp+6Ch] [-FF4h]
  idMD6Skel v99; // [sp+70h] [-FF0h] BYREF
  idToken v100; // [sp+C0h] [-FA0h] BYREF
  char v101; // [sp+108h] [-F58h] BYREF
  idAnimWebBlendEquation::animList_t v102; // [sp+210h] [-E50h] BYREF
  unsigned __int8 v103[272]; // [sp+A70h] [-5F0h] BYREF
  float v104[272]; // [sp+B80h] [-4E0h] BYREF

  if ( numDimensions <= scalarPairsa->size
    || (unsigned __int8)idList<float,116>::Resize(this: scalarPairsa, newsize: numDimensions) != 0 )
  {
    size = scalarPairsa->size;
    if ( numDimensions < size )
      size = numDimensions;
    scalarPairsa->num = size;
  }
  if ( numDimensions <= userChannelIndicesa->size
    || idList<idNavSpline *,5>::Resize(this: userChannelIndicesa, newsize: numDimensions) )
  {
    v56 = userChannelIndicesa->size;
    if ( numDimensions < v56 )
      v56 = numDimensions;
    userChannelIndicesa->num = v56;
  }
  if ( numDimensions <= coordinateLista->size
    || idList<idNavSpline *,5>::Resize(this: coordinateLista, newsize: numDimensions) )
  {
    v57 = coordinateLista->size;
    if ( numDimensions < v57 )
      v57 = numDimensions;
    coordinateLista->num = v57;
  }
  v100.baseBuffer[0] = 0;
  v100.intvalue = 0;
  v100.floatvalue = -3.4028235e38;
  memset(&v100.whiteSpaceStart_p, 0, 12);
  v101 = 0;
  v100.len = 0;
  v100.data = &v101;
  v100.allocedAndFlag = -2147483392;
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 44, token: &v100);
  v58 = 0;
  if ( numDimensions > 0 )
  {
    v59 = 0;
    do
    {
      if ( v58 != 0 )
        idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v100);
      idAnimWebBlendEquation::ParseScalar(
        this,
        src,
        scalars: a28,
        scalarPairs: a30,
        scalarIndex: (int *)&userChannelIndicesa->list[v59],
        scalarPairIndex: (int *)&coordinateLista->list[v59],
        value: &scalarPairsa->list[v59],
        isCopyOnPlay: (bool *)animationLista->list + v58++);
      ++v59;
    }
    while ( v58 < numDimensions );
  }
  v99.name.str = (const char *)useUserChannels;
  if ( useUserChannels && numDimensions > 0 )
  {
    for ( i = numDimensions; i != 0; --i )
    {
      idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v100);
      idLexer::ReadToken(this: src, token: &v100);
      idMD6Skel::GetUserChannelIndex(
        this: &v99,
        result: (idIndex<short,enum invalidUserChannelIndex_t> *)model->skeleton,
        name: v100.data);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: a32,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v99);
    }
  }
  if ( currentCoordinateScalarIndexa != nullptr )
  {
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v100);
    idAnimWebBlendEquation::Parse_r(
      this,
      src,
      modelInfo,
      model,
      allocator,
      scalars: a28,
      existingNodes,
      root: currentCoordinateScalarIndexa,
      scalarPairs: v93,
      animList: v94);
  }
  skeleton = model->skeleton;
  v97 = 0;
  value = (const idHandle<unsigned short,enum invalidCrc_t,65535> *)skeleton->data->parentTblCrc.value;
  v99.networkID = (int)&mem;
  while ( !idLexer::CheckTokenType(this: src, type: 5, subtype: 45, token: &v100) || v97 == scalarsa->size )
  {
    v102.filterList.num = 0;
    v102.filterList.granularity = 1;
    v102.filterList.size = 10;
    v102.filterList.list = v102.filterList.staticList;
    v102.filterList.memTag = 5;
    v102.filterList.listStatic = 1;
    v102.animList.size = 256;
    v102.animList.num = 0;
    v102.animList.granularity = 1;
    v102.animList.list = v102.animList.staticList;
    v102.animList.memTag = 5;
    v102.animList.listStatic = 1;
    v102.tagList.size = 256;
    v102.tagList.num = 0;
    v102.tagList.granularity = 1;
    v102.tagList.list = v102.tagList.staticList;
    v102.tagList.memTag = 5;
    v102.tagList.listStatic = 1;
    v102.animPropIndex = -1;
    v99.resourceListPtr = nullptr;
    idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v100);
    idAnimWebBlendEquation::Parse_r(
      this,
      src,
      modelInfo,
      model,
      allocator,
      scalars: a28,
      existingNodes,
      root: (idMD6Node **)&v99.resourceListPtr,
      scalarPairs: v93,
      animList: v94);
    num = v102.animList.num;
    if ( v102.animList.num <= 1 )
      num = 1;
    v98 = num;
    v64 = 0;
    if ( num > 0 )
    {
      v99.trackedMemory = 0;
      while ( 1 )
      {
        v65 = v97;
        v66 = v97 + 1;
        v67 = scalarsa->size;
        v97 = v66;
        if ( v66 <= v67 || idList<idNavSpline *,5>::Resize(this: scalarsa, newsize: v65 + 1) )
        {
          v68 = scalarsa->size;
          if ( v66 < v68 )
            v68 = v65 + 1;
          scalarsa->num = v68;
        }
        if ( v98 <= 1 )
          resourceListPtr = v99.resourceListPtr;
        else
          resourceListPtr = *(idResourceList **)((char *)v102.animList.list + v99.trackedMemory);
        str = v99.name.str;
        scalarsa->list[v65] = (idSpawnArea::GeneratedPosition *)resourceListPtr;
        if ( str != nullptr )
        {
          v71 = v102.animPropIndex + v64;
          if ( v102.animPropIndex + v64 < 0 || v71 >= modelInfo->animProps.num )
            v72 = nullptr;
          else
            v72 = &modelInfo->animProps.list[v71];
          animData = v72->anim->animData;
          AnimMapIndex = idMD6Blend::GetAnimMapIndex(animData, targetParentTableCRC: value);
          v75 = skeleton->data->numUserChannels + 7;
          v76 = v75 & 0xFFF8;
          v77 = idMD6Blend::DecodeRLE(
                  RLE: (const unsigned __int8 *)animData + *(&animData[1].flags + 8 * AnimMapIndex + animData->numAnimMaps),
                  sentinel: v75 & 0xFFF8,
                  indices: v103);
          idMD6Blend::DecodeBasePoseU(
            numUserChannels: v76,
            inU: (const float *)((char *)&skeleton->data->size
                          + 40 * ((skeleton->data->numJoints + 7) & 0xFFF8)
                          + skeleton->data->basePoseOffset),
            outU: v104);
          idMD6Blend::DecodeConstantU(
            channelsU: v103,
            numUserChannels: v77,
            inU: (const float *)((char *)&animData->totalSize + animData->constUOffset),
            outU: v104);
        }
        v99.defaultAnim = nullptr;
        v99.data = (idMD6SkelData *)6;
        *((_DWORD *)&v99.idResource + 8) = &v99.jointConversion;
        v99.timestamp = 66817;
        v78 = false;
        if ( currentCoordinateScalarIndexa == nullptr )
        {
          idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v100);
          v79 = idLexer::CheckTokenType(this: src, type: 5, subtype: 31, token: &v100);
          v78 = idLexer::PeekTokenType(this: src, type: 3, subtype: 0, token: &v100);
          if ( v78 )
          {
            for ( j = 0; j < numDimensions; ++j )
            {
              if ( j != 0 )
              {
                idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v100);
                v79 = idLexer::CheckTokenType(this: src, type: 5, subtype: 31, token: &v100);
              }
              idLexer::ExpectTokenType(this: src, type: 3, subtype: 0, token: &v100);
              if ( v100.type == 3 )
              {
                if ( (v100.subtype & 0x10000) == 0 )
                  idToken::NumberValue(this: &v100);
                floatvalue = v100.floatvalue;
              }
              else
              {
                floatvalue = 0.0;
              }
              if ( v79 )
                floatvalue = -floatvalue;
              v95 = floatvalue;
              idList<float,13>::Append(this: (idList<float,13> *)&v99.idResource + 2, obj: &v95);
            }
          }
        }
        v82 = 0;
        if ( numDimensions > 0 )
          break;
LABEL_78:
        if ( LOBYTE(v99.timestamp) == 0 || LOBYTE(v99.timestamp) == 2 )
        {
          if ( *((_DWORD *)&v99.idResource + 8) != 0 )
            idMem::Free(this: (idMem *)v99.networkID, ptr: *((void **)&v99.idResource + 8), align: ALIGN_16);
          *((_DWORD *)&v99.idResource + 8) = 0;
          v99.data = nullptr;
        }
        ++v64;
        v99.defaultAnim = nullptr;
        v99.trackedMemory += 4;
        if ( v64 >= v98 )
          goto LABEL_84;
      }
      v83 = 0;
      v84 = 0;
      while ( 2 )
      {
        v95 = 0.0;
        if ( currentCoordinateScalarIndexa != nullptr )
        {
          idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v100);
          v99.nextOnHashChain = (idResource *)-1;
          v99.resourceError = (const char *)-1;
          v96 = false;
          idAnimWebBlendEquation::ParseScalar(
            this,
            src,
            scalars: a28,
            scalarPairs: a30,
            scalarIndex: (int *)&v99.nextOnHashChain,
            scalarPairIndex: (int *)&v99.resourceError,
            value: &v95,
            isCopyOnPlay: &v96);
          goto LABEL_77;
        }
        if ( v78 )
        {
          v95 = *(float *)(v84 + *((_DWORD *)&v99.idResource + 8));
          goto LABEL_77;
        }
        if ( v99.name.str != nullptr )
        {
          v85 = a32->list[v83].value;
          if ( v85 >= 0 )
          {
            v95 = v104[v85];
            goto LABEL_77;
          }
LABEL_76:
          v95 = 0.0;
        }
        else
        {
          coordinates = modelInfo->coordinates;
          if ( coordinates == nullptr || coordinates->num <= 0 || (v87 = 1, modelInfo->animProps.num <= 0) )
            v87 = 0;
          if ( v87 == 0 )
            goto LABEL_76;
          v88 = (idResource *)modelInfo->coordinates;
          v89 = modelInfo->animProps.num;
          animPropIndex = v102.animPropIndex;
          __twllei(v89, 0);
          trackedMemory = v88->trackedMemory;
          v92 = v88->__vftable;
          v99.nextOnHashChain = v88;
          __twlgei(v89 & ~(__ROL4__(trackedMemory, 1) - 1), 0xFFFFFFFF);
          v95 = *((float *)&v92->dtr_idResource + trackedMemory / v89 * (animPropIndex + v64) + v82);
        }
LABEL_77:
        idList<float,13>::Append(this: a34, obj: &v95);
        ++v82;
        v84 += 4;
        ++v83;
        if ( v82 >= numDimensions )
          goto LABEL_78;
        continue;
      }
    }
LABEL_84:
    idAnimWebBlendEquation::animList_t::~animList_t(this: &v102);
  }
  currentCoordinatea->list = (float *)idAnimWebBlendEquation::ParseWeightGroup(this, src);
  idStr::FreeData(this: &v100);
}


// ========================================================================
// __unwind$226842
// EA  : 0x825FBC6C
// RVA : 0x005FBC6C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226842()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4192 + 192));
}


// ========================================================================
// __unwind$226843
// EA  : 0x825FBC94
// RVA : 0x005FBC94
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226843()
{
  int v0; // r12

  idAnimWebBlendEquation::animList_t::~animList_t(this: (idAnimWebBlendEquation::animList_t *)(v0 - 4192 + 528));
}


// ========================================================================
// __unwind$226844
// EA  : 0x825FBCBC
// RVA : 0x005FBCBC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_226844()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4192 + 144));
}


// ========================================================================
// ?Parse_r@idAnimWebBlendEquation@@AAAXAAVidLexer@@ABVidModelInfo@idDeclAnimWebNode@@PBVidMD6Model@@PAVidMD6Allocator@@AAV?$idList@VidAnimWebScalar@@$04@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@AAPAVidMD6Node@@AAV?$idList@VidAnimWebScalarPair@@$04@@PAUanimList_t@1@@Z
// EA  : 0x825FBCF0
// RVA : 0x005FBCF0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void __fastcall idAnimWebBlendEquation::Parse_r(
        idAnimWebBlendEquation *this,
        idLexer *src,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idMD6Model *model,
        idMD6Allocator *allocator,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        idMD6Node **root,
        idList<idAnimWebScalarPair,5> *scalarPairs,
        idAnimWebBlendEquation::animList_t *animList,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idList<idAnimWebScalarPair,5> *a28,
        int a29,
        idAnimWebBlendEquation::animList_t *a30)
{
  unsigned __int64 v38; // r6
  const char *v39; // r7
  int v40; // r29
  idMD6BlendAdditiveBranch *v41; // r30
  unsigned __int64 v42; // r6
  const char *v43; // r7
  int *list; // r6
  int v45; // r5
  const char *v46; // r11
  idStr *v47; // r3
  bool v48; // r19
  bool v49; // r18
  int v50; // r17
  idMD6BlendBranch *v51; // r28
  unsigned __int64 v52; // r6
  const char *v53; // r7
  int j; // r30
  idVehicleState *v55; // r7
  int v56; // r5
  const char *v57; // r11
  idStr *v58; // r3
  bool v59; // r18
  bool v60; // r3
  bool v61; // r19
  int v62; // r17
  idMD6FusionBranch *v63; // r28
  unsigned __int64 v64; // r6
  const char *v65; // r7
  int i; // r30
  idVehicleState *v67; // r7
  char v68; // r30
  char *v69; // r25
  idMD6BestLeaf *v70; // r19
  unsigned __int64 v71; // r6
  const char *v72; // r7
  const idDeclAnimWebTagGroup *v73; // r30
  char v74; // r30
  char *data; // r25
  idMD6TagFilter *v76; // r19
  unsigned __int64 v77; // r6
  const char *v78; // r7
  const idDeclAnimWebTagGroup *v79; // r29
  int num; // r24
  idMD6Branch *v81; // r30
  unsigned __int64 v82; // r6
  const char *v83; // r7
  idMD6Branch::blendType_t v84; // r9
  md6WeightGroup_t v85; // r8
  idMD6Blend::blendOp_t v86; // r18
  idMD6Blend::blendOp_t v87; // r25
  const char **v88; // r30
  double v89; // fp31
  double v90; // fp30
  int v91; // r24
  double v92; // fp29
  idMD6Branch *v93; // r28
  int v94; // r30
  idPLog::logEntry_t *v95; // r22
  __int64 v96; // r3
  idPLog::logEntry_t *v97; // r30
  int v98; // r3
  int parent; // r11
  __int64 v100; // r9
  idMD6Branch::blendType_t v101; // r9
  md6WeightGroup_t v102; // r8
  int v103; // r11
  char v104; // r5
  idPLog *pLog; // r29
  idPLog::logEntry_t *v106; // r30
  int v107; // r3
  __int64 totalTicks; // r11
  __int64 v109; // r9
  idList<idAnimWebScalarPair,5> *v110; // [sp+8h] [-4E08h]
  int v111; // [sp+8h] [-4E08h]
  int v112; // [sp+8h] [-4E08h]
  int v113; // [sp+8h] [-4E08h]
  const idDeclAnimWebTagGroup *v114; // [sp+8h] [-4E08h]
  idList<idAnimWebScalarPair,5> *v115; // [sp+8h] [-4E08h]
  int v116; // [sp+8h] [-4E08h]
  idList<idAnimWebScalarPair,5> *v117; // [sp+8h] [-4E08h]
  idAnimWebBlendEquation::animList_t *v118; // [sp+Ch] [-4E04h]
  int v119; // [sp+Ch] [-4E04h]
  int v120; // [sp+Ch] [-4E04h]
  int v121; // [sp+Ch] [-4E04h]
  idAnimWebBlendEquation::animList_t *v122; // [sp+Ch] [-4E04h]
  int v123; // [sp+Ch] [-4E04h]
  idAnimWebBlendEquation::animList_t *v124; // [sp+Ch] [-4E04h]
  unsigned int *v125; // [sp+10h] [-4E00h]
  int v126; // [sp+10h] [-4E00h]
  int v127; // [sp+10h] [-4E00h]
  int v128; // [sp+10h] [-4E00h]
  unsigned int *v129; // [sp+14h] [-4DFCh]
  int v130; // [sp+14h] [-4DFCh]
  int v131; // [sp+14h] [-4DFCh]
  int v132; // [sp+14h] [-4DFCh]
  idList<idMD6Node *,5> *v133; // [sp+18h] [-4DF8h]
  int v134; // [sp+18h] [-4DF8h]
  int v135; // [sp+18h] [-4DF8h]
  int v136; // [sp+18h] [-4DF8h]
  idList<float,5> *v137; // [sp+1Ch] [-4DF4h]
  int v138; // [sp+1Ch] [-4DF4h]
  int v139; // [sp+1Ch] [-4DF4h]
  int v140; // [sp+1Ch] [-4DF4h]
  idList<int,5> *v141; // [sp+20h] [-4DF0h]
  int v142; // [sp+20h] [-4DF0h]
  int v143; // [sp+20h] [-4DF0h]
  int v144; // [sp+20h] [-4DF0h]
  idList<int,5> *v145; // [sp+24h] [-4DECh]
  int v146; // [sp+24h] [-4DECh]
  int v147; // [sp+24h] [-4DECh]
  int v148; // [sp+24h] [-4DECh]
  idList<bool,5> *v149; // [sp+28h] [-4DE8h]
  int v150; // [sp+28h] [-4DE8h]
  int v151; // [sp+28h] [-4DE8h]
  int v152; // [sp+28h] [-4DE8h]
  md6WeightGroup_t *v153; // [sp+2Ch] [-4DE4h]
  int v154; // [sp+2Ch] [-4DE4h]
  int v155; // [sp+2Ch] [-4DE4h]
  int v156; // [sp+2Ch] [-4DE4h]
  idMD6Node **v157; // [sp+30h] [-4DE0h]
  int v158; // [sp+30h] [-4DE0h]
  int v159; // [sp+30h] [-4DE0h]
  int v160; // [sp+30h] [-4DE0h]
  int v161; // [sp+34h] [-4DDCh]
  int v162; // [sp+34h] [-4DDCh]
  int v163; // [sp+34h] [-4DDCh]
  int v164; // [sp+34h] [-4DDCh]
  int v165; // [sp+38h] [-4DD8h]
  int v166; // [sp+38h] [-4DD8h]
  int v167; // [sp+38h] [-4DD8h]
  int v168; // [sp+38h] [-4DD8h]
  int v169; // [sp+3Ch] [-4DD4h]
  int v170; // [sp+3Ch] [-4DD4h]
  int v171; // [sp+3Ch] [-4DD4h]
  int v172; // [sp+3Ch] [-4DD4h]
  int v173; // [sp+40h] [-4DD0h]
  int v174; // [sp+40h] [-4DD0h]
  int v175; // [sp+40h] [-4DD0h]
  int v176; // [sp+40h] [-4DD0h]
  int v177; // [sp+44h] [-4DCCh]
  int v178; // [sp+44h] [-4DCCh]
  int v179; // [sp+44h] [-4DCCh]
  int v180; // [sp+44h] [-4DCCh]
  int v181; // [sp+48h] [-4DC8h]
  int v182; // [sp+48h] [-4DC8h]
  int v183; // [sp+48h] [-4DC8h]
  int v184; // [sp+48h] [-4DC8h]
  int v185; // [sp+4Ch] [-4DC4h]
  int v186; // [sp+4Ch] [-4DC4h]
  int v187; // [sp+4Ch] [-4DC4h]
  int v188; // [sp+4Ch] [-4DC4h]
  int v189; // [sp+50h] [-4DC0h]
  int v190; // [sp+50h] [-4DC0h]
  int v191; // [sp+50h] [-4DC0h]
  int v192; // [sp+50h] [-4DC0h]
  int v193; // [sp+58h] [-4DB8h]
  int v194; // [sp+60h] [-4DB0h]
  int v195; // [sp+68h] [-4DA8h]
  int v196; // [sp+70h] [-4DA0h]
  int v197; // [sp+78h] [-4D98h]
  int v198; // [sp+80h] [-4D90h]
  int v199; // [sp+88h] [-4D88h]
  int v200; // [sp+90h] [-4D80h]
  int v201; // [sp+98h] [-4D78h]
  int v202; // [sp+A0h] [-4D70h]
  bool v203; // [sp+B0h] [-4D60h] BYREF
  idList<float,5> v204; // [sp+B4h] [-4D5Ch] BYREF
  idList<float,5> v205; // [sp+C4h] [-4D4Ch] BYREF
  int v206; // [sp+D4h] [-4D3Ch]
  int v207; // [sp+D8h] [-4D38h]
  __int16 v208; // [sp+DCh] [-4D34h]
  char v209; // [sp+DEh] [-4D32h]
  char v210; // [sp+DFh] [-4D31h]
  _BYTE v211[16]; // [sp+E0h] [-4D30h] BYREF
  idList<idVehicleState *,5> v212; // [sp+F0h] [-4D20h] BYREF
  _BYTE v213[16]; // [sp+100h] [-4D10h] BYREF
  idList<idVehicleState *,5> v214; // [sp+110h] [-4D00h] BYREF
  int v215; // [sp+120h] [-4CF0h] BYREF
  idList<idVehicleState *,5> v216; // [sp+130h] [-4CE0h] BYREF
  int v217; // [sp+140h] [-4CD0h] BYREF
  idList<idVehicleState *,5> v218; // [sp+150h] [-4CC0h] BYREF
  __int16 v219; // [sp+160h] [-4CB0h] BYREF
  idList<idVehicleState *,5> v220; // [sp+170h] [-4CA0h] BYREF
  int v221; // [sp+180h] [-4C90h] BYREF
  idList<idMD6Node *,5> v222; // [sp+190h] [-4C80h] BYREF
  int v223; // [sp+1A0h] [-4C70h] BYREF
  idPLogScope v224; // [sp+1A8h] [-4C68h] BYREF
  idList<idMD6Node *,5> v225; // [sp+1B0h] [-4C60h] BYREF
  int v226; // [sp+1C0h] [-4C50h] BYREF
  idList<idMD6Node *,5> v227; // [sp+1D0h] [-4C40h] BYREF
  int v228; // [sp+1E0h] [-4C30h] BYREF
  idList<idVehicleState *,5> v229; // [sp+1F0h] [-4C20h] BYREF
  int v230; // [sp+200h] [-4C10h] BYREF
  idList<idVehicleState *,5> v231; // [sp+220h] [-4BF0h] BYREF
  int v232; // [sp+230h] [-4BE0h] BYREF
  idList<idVehicleState *,5> v233; // [sp+250h] [-4BC0h] BYREF
  int v234; // [sp+260h] [-4BB0h] BYREF
  idList<idVehicleState *,5> v235; // [sp+280h] [-4B90h] BYREF
  int v236; // [sp+290h] [-4B80h] BYREF
  idList<idVehicleState *,5> v237; // [sp+2B0h] [-4B60h] BYREF
  int v238; // [sp+2C0h] [-4B50h] BYREF
  idPLogScope v239; // [sp+2D8h] [-4B38h] BYREF
  idList<idVehicleState *,5> v240; // [sp+2E0h] [-4B30h] BYREF
  int v241; // [sp+2F0h] [-4B20h] BYREF
  idToken v242; // [sp+310h] [-4B00h] BYREF
  char v243; // [sp+358h] [-4AB8h] BYREF
  idStr v244; // [sp+460h] [-49B0h] BYREF
  idStr v245; // [sp+480h] [-4990h] BYREF
  idList<idVehicleState *,5> v246; // [sp+4A0h] [-4970h] BYREF
  int v247; // [sp+4B0h] [-4960h] BYREF
  idList<idVehicleState *,5> v248; // [sp+8B0h] [-4560h] BYREF
  int v249; // [sp+8C0h] [-4550h] BYREF
  idList<idVehicleState *,5> v250; // [sp+CC0h] [-4150h] BYREF
  int v251; // [sp+CD0h] [-4140h] BYREF
  idList<idVehicleState *,5> v252; // [sp+10D0h] [-3D40h] BYREF
  int v253; // [sp+10E0h] [-3D30h] BYREF
  idAnimWebBlendEquation::animList_t v254; // [sp+14E0h] [-3930h] BYREF
  idList<idVehicleState *,5> v255; // [sp+1D40h] [-30D0h] BYREF
  int v256; // [sp+1D50h] [-30C0h] BYREF
  idList<idVehicleState *,5> v257; // [sp+3550h] [-18C0h] BYREF
  int v258; // [sp+3560h] [-18B0h] BYREF

  RD_EventBegin(name: "idAnimWebBlendEquation::Parse_r");
  LODWORD(v38) = "idAnimWebBlendEquation::Parse_r";
  HIDWORD(v38) = 2;
  idPLogScope::idPLogScope(this: &v224, pl: &::pLog, gMask: v38, label: v39);
  v40 = 0;
  v242.baseBuffer[0] = 0;
  v242.intvalue = 0;
  v242.floatvalue = -3.4028235e38;
  memset(&v242.whiteSpaceStart_p, 0, 12);
  v243 = 0;
  v242.data = &v243;
  v242.len = 0;
  v242.allocedAndFlag = -2147483392;
  if ( !idLexer::ReadToken(this: src, token: &v242) )
  {
    idLexer::Error(this: src, str: "Empty token");
    idStr::FreeData(this: &v242);
    idPLogScope::~idPLogScope(this: &v224);
    goto LABEL_74;
  }
  idStr::ToLower(this: &v242);
  if ( v242.type != 5 || v242.subtype != 44 )
  {
    if ( idStr::Cmp(s1: v242.data, s2: "lerp") != 0
      && idStr::Cmp(s1: v242.data, s2: "addr") != 0
      && idStr::Cmp(s1: v242.data, s2: "addl") != 0
      && idStr::Cmp(s1: v242.data, s2: "subr") != 0
      && idStr::Cmp(s1: v242.data, s2: "subl") != 0 )
    {
      if ( idStr::Cmp(s1: v242.data, s2: "blenda") != 0 )
      {
        v45 = 0;
        if ( aBlend[0] != 0 )
        {
          v46 = "blend";
          do
          {
            ++v46;
            ++v45;
          }
          while ( *v46 != 0 );
        }
        if ( idStr::Cmpn(s1: v242.data, s2: "blend", n: v45) != 0 )
        {
          v56 = 0;
          if ( aFusion[0] != 0 )
          {
            v57 = "fusion";
            do
            {
              ++v57;
              ++v56;
            }
            while ( *v57 != 0 );
          }
          if ( idStr::Cmpn(s1: v242.data, s2: "fusion", n: v56) != 0 )
          {
            if ( idStr::Cmp(s1: v242.data, s2: "choose") != 0 && idStr::Cmp(s1: v242.data, s2: "select") != 0 )
            {
              if ( idStr::Cmp(s1: v242.data, s2: "best") != 0 )
              {
                if ( idStr::Cmp(s1: v242.data, s2: "filter") != 0 )
                {
                  idAnimWebBlendEquation::ParseNode(
                    this,
                    src,
                    name: v242.data,
                    model,
                    allocator,
                    scalars,
                    existingNodes,
                    root,
                    scalarPairs: v110,
                    animList: v118,
                    a11: (int)v125,
                    a12: (int)v129,
                    a13: (int)v133,
                    a14: (int)v137,
                    a15: (int)v141,
                    a16: (int)v145,
                    a17: (int)v149,
                    a18: (int)v153,
                    a19: (int)v157,
                    a20: v161,
                    a21: v165,
                    a22: v169,
                    a23: v173,
                    a24: v177,
                    a25: v181,
                    a26: v185,
                    a27: v189,
                    a28,
                    a29: v193,
                    (int)a30);
                }
                else
                {
                  idLexer::ExpectTokenType(this: src, type: 5, subtype: 44, token: &v242);
                  idLexer::ReadToken(this: src, token: &v242);
                  v74 = idAnimWebBlendEquation::ParseScalarName(this, src, token: &v242);
                  data = v242.data;
                  v76 = (idMD6TagFilter *)allocator->Alloc(this: allocator, a2: 7);
                  RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
                  LODWORD(v77) = "idAnimWebBlendEquation - allocatedNodes.Append";
                  HIDWORD(v77) = 2;
                  idPLogScope::idPLogScope(this: (idPLogScope *)&v204.num, pl: &::pLog, gMask: v77, label: v78);
                  v205.num = (int)v76;
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
                    obj: (const encounterGroupRole_t *)&v205.num);
                  idPLogScope::~idPLogScope(this: (idPLogScope *)&v204.num);
                  RD_EventEnd();
                  *(_DWORD *)&v204.granularity = 0;
                  v205.num = 0;
                  v205.list = nullptr;
                  v204.list = nullptr;
                  v204.num = 0;
                  v79 = idAnimWebBlendEquation::ProcessTagGroup(
                          this,
                          isCopyOnPlay: v74,
                          tagGroupName: data,
                          modelInfo,
                          node: v76,
                          scalars,
                          scalarPairs: a28,
                          tagBias: (unsigned int *)&v204.granularity,
                          tagCount: (unsigned int *)v110,
                          defaultTag: (unsigned int *)v118,
                          tagGroupIndex: v125,
                          tagGroupMask: v129,
                          a13: (int)v133,
                          a14: (int)v137,
                          a15: (int)v141,
                          a16: (int)v145,
                          a17: (int)v149,
                          a18: (int)v153,
                          a19: (int)v157,
                          a20: v161,
                          a21: v165,
                          a22: v169,
                          a23: v173,
                          a24: v177,
                          a25: v181,
                          a26: v185,
                          a27: v189,
                          a28: &v205.num,
                          a29: v193,
                          a30: &v205,
                          a31: v194,
                          a32: &v204.num,
                          a33: v195,
                          a34: (int *)&v204);
                  idAnimWebBlendEquation::ParseAnimList(
                    this,
                    src,
                    modelInfo,
                    model,
                    allocator,
                    existingNodes,
                    tagGroup: v79,
                    animList: a30);
                  idLexer::ExpectTokenType(this: src, type: 5, subtype: 45, token: &v242);
                  idMD6TagFilter::Init(
                    this: v76,
                    inputTagBias: v204.listStatic,
                    inputTagMask: (const unsigned int)v204.list,
                    inputTagGroupIndex: v204.num,
                    inputTagGroup: v79);
                  *root = v76;
                  v205.num = (int)v76;
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)a30,
                    obj: (const encounterGroupRole_t *)&v205.num);
                }
              }
              else
              {
                idLexer::ExpectTokenType(this: src, type: 5, subtype: 44, token: &v242);
                idLexer::ReadToken(this: src, token: &v242);
                v68 = idAnimWebBlendEquation::ParseScalarName(this, src, token: &v242);
                v69 = v242.data;
                v70 = (idMD6BestLeaf *)allocator->Alloc(this: allocator, a2: 6);
                RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
                LODWORD(v71) = "idAnimWebBlendEquation - allocatedNodes.Append";
                HIDWORD(v71) = 2;
                idPLogScope::idPLogScope(this: (idPLogScope *)&v205.num, pl: &::pLog, gMask: v71, label: v72);
                v204.num = (int)v70;
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
                  obj: (const encounterGroupRole_t *)&v204.num);
                idPLogScope::~idPLogScope(this: (idPLogScope *)&v205.num);
                RD_EventEnd();
                v205.list = nullptr;
                v205.num = 0;
                *(_DWORD *)&v204.granularity = 0;
                v204.num = 0;
                v204.list = nullptr;
                v73 = idAnimWebBlendEquation::ProcessTagGroup(
                        this,
                        isCopyOnPlay: v68,
                        tagGroupName: v69,
                        modelInfo,
                        node: v70,
                        scalars,
                        scalarPairs: a28,
                        tagBias: (unsigned int *)&v205,
                        tagCount: (unsigned int *)v110,
                        defaultTag: (unsigned int *)v118,
                        tagGroupIndex: v125,
                        tagGroupMask: v129,
                        a13: (int)v133,
                        a14: (int)v137,
                        a15: (int)v141,
                        a16: (int)v145,
                        a17: (int)v149,
                        a18: (int)v153,
                        a19: (int)v157,
                        a20: v161,
                        a21: v165,
                        a22: v169,
                        a23: v173,
                        a24: v177,
                        a25: v181,
                        a26: v185,
                        a27: v189,
                        a28: &v205.num,
                        a29: v193,
                        a30: &v204.granularity,
                        a31: v194,
                        a32: (int *)&v204,
                        a33: v195,
                        a34: &v204.num);
                idAnimWebBlendEquation::animList_t::animList_t(this: &v254);
                idAnimWebBlendEquation::ParseAnimList(
                  this,
                  src,
                  modelInfo,
                  model,
                  allocator,
                  existingNodes,
                  tagGroup: v73,
                  animList: &v254);
                idLexer::ExpectTokenType(this: src, type: 5, subtype: 45, token: &v242);
                idMD6BestLeaf::Init(
                  this: v70,
                  inputTagBias: (const unsigned __int8)v205.list,
                  inputTagMask: v204.num,
                  inputTagGroupIndex: (const unsigned __int8)v204.list,
                  leaves: &v254.animList,
                  tags: &v254.tagList,
                  filters: &v254.filterList,
                  inputDefaultTag: *(const unsigned int *)&v204.granularity,
                  inputTagGroup: v114);
                *root = v70;
                idAnimWebBlendEquation::animList_t::~animList_t(this: &v254);
              }
            }
            else
            {
              v204.list = nullptr;
              *(_DWORD *)&v204.granularity = 0;
              idLexer::ExpectTokenType(this: src, type: 5, subtype: 44, token: &v242);
              idAnimWebBlendEquation::Parse_r(
                this,
                src,
                modelInfo,
                model,
                allocator,
                scalars,
                existingNodes,
                root: (idMD6Node **)&v204,
                scalarPairs: v110,
                animList: v118);
              idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v242);
              idAnimWebBlendEquation::Parse_r(
                this,
                src,
                modelInfo,
                model,
                allocator,
                scalars,
                existingNodes,
                root: (idMD6Node **)&v204.granularity,
                scalarPairs: v115,
                animList: v122);
              idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v242);
              v203 = false;
              *(float *)&v204.num = 0.0;
              idAnimWebBlendEquation::ParseScalar(
                this,
                src,
                scalars,
                scalarPairs: a28,
                scalarIndex: &v205.num,
                scalarPairIndex: (int *)&v205,
                value: (float *)&v204.num,
                isCopyOnPlay: &v203);
              num = v205.num;
              if ( v205.num < 0 )
                idLib::Warning(fmt: "Blend equation uses 'Select' function, but selector is a constant. Is this intended?");
              idLexer::ExpectTokenType(this: src, type: 5, subtype: 45, token: &v242);
              v81 = (idMD6Branch *)allocator->Alloc(this: allocator, a2: 0);
              RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
              LODWORD(v82) = "idAnimWebBlendEquation - allocatedNodes.Append";
              HIDWORD(v82) = 2;
              idPLogScope::idPLogScope(this: &v239, pl: &::pLog, gMask: v82, label: v83);
              v205.num = (int)v81;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
                obj: (const encounterGroupRole_t *)&v205.num);
              idPLogScope::~idPLogScope(this: &v239);
              RD_EventEnd();
              idMD6Branch::Init(
                this: v81,
                left: (idMD6Node *)v204.list,
                right: *(idMD6Node **)&v204.granularity,
                op: BOP_LERP,
                originBlend: ORIGINBLEND_BRANCH,
                startAlpha: *(float *)&v204.num,
                targetAlpha: *(float *)&v204.num,
                alphaRate: 0.0,
                filterGroup: v85,
                blendType: v84);
              *root = v81;
              if ( num >= 0 )
                idAnimWebBlendEquation::SetupScalarPair(
                  this,
                  scalars,
                  scalarPairs: a28,
                  node: v81,
                  scalarIndex: num,
                  scalarPairIndex: (const int)v205.list,
                  fieldType: 0,
                  fieldFlags: ((_cntlzw(v203) & 0x20) == 0) + 1,
                  coordinateIndex: v116,
                  a10: v123,
                  a11: (int)v125,
                  a12: (int)v129,
                  a13: (int)v133,
                  a14: (int)v137,
                  a15: (int)v141,
                  a16: (int)v145,
                  a17: (int)v149,
                  a18: (int)v153,
                  a19: (int)v157,
                  a20: v161,
                  a21: v165,
                  a22: v169,
                  a23: v173,
                  a24: v177,
                  a25: v181,
                  a26: v185,
                  a27: v189,
                  a28: -1);
            }
          }
          else
          {
            v58 = idStr::Left(this: &v245, result: &v242, len: 6);
            idStr::StripLeadingOnce(this: &v242, string: v58->data);
            idStr::FreeData(this: &v245);
            v59 = idStr::StripLeadingOnce(this: &v242, string: "u");
            v60 = idStr::StripLeadingOnce(this: &v242, string: "y");
            v61 = v60;
            if ( v59 && v60 )
            {
              idLib::Warning(fmt: "FusionUY op is invalid.");
              v61 = false;
            }
            v62 = atol(nptr: v242.data);
            if ( v62 <= 1 )
              v62 = 1;
            *(_QWORD *)&v231.num = 6;
            v231.list = (idVehicleState **)&v232;
            *(_DWORD *)&v231.granularity = 66817;
            *(_QWORD *)&v235.num = 6;
            v235.list = (idVehicleState **)&v236;
            *(_DWORD *)&v235.granularity = 66817;
            *(_QWORD *)&v240.num = 6;
            v240.list = (idVehicleState **)&v241;
            *(_DWORD *)&v240.granularity = 66817;
            *(_QWORD *)&v248.num = 256;
            v248.list = (idVehicleState **)&v249;
            *(_DWORD *)&v248.granularity = 66817;
            *(_QWORD *)&v257.num = 1536;
            v257.list = (idVehicleState **)&v258;
            *(_DWORD *)&v257.granularity = 66817;
            v207 = 6;
            v206 = 0;
            v208 = 1;
            *(_DWORD *)&v205.granularity = v211;
            v209 = 5;
            v210 = 1;
            memset(v211, 255, 12);
            *(_QWORD *)&v227.num = 6;
            v227.list = (idMD6Node **)&v228;
            *(_DWORD *)&v227.granularity = 66817;
            v204.list = nullptr;
            idAnimWebBlendEquation::ParseBlend(
              this,
              useUserChannels: v59,
              numDimensions: v62,
              src,
              modelInfo,
              model,
              allocator,
              existingNodes,
              scalars: (idList<idAnimWebScalar,5> *)v110,
              scalarPairs: (idList<idAnimWebScalarPair,5> *)v118,
              userChannelIndices: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)v125,
              coordinateList: (idList<float,5> *)v129,
              animationList: v133,
              currentCoordinate: v137,
              currentCoordinateScalarIndex: v141,
              currentCoordinateScalarPairIndex: v145,
              isCopyOnPlay: v149,
              wg: v153,
              baseAnimation: v157,
              a20: v161,
              a21: v165,
              a22: v169,
              a23: v173,
              a24: v177,
              a25: v181,
              a26: v185,
              a27: v189,
              a28: scalars,
              a29: v193,
              a30: a28,
              a31: v194,
              a32: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v205.granularity,
              a33: v195,
              a34: (idList<float,13> *)&v257,
              a35: v196,
              scalarsa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v248,
              a37: v197,
              scalarPairsa: (idList<float,13> *)&v231,
              a39: v198,
              userChannelIndicesa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v235,
              a41: v199,
              coordinateLista: (idList<idSpawnArea::GeneratedPosition *,5> *)&v240,
              a43: v200,
              animationLista: &v227,
              a45: v201,
              currentCoordinatea: &v204,
              a47: v202,
              currentCoordinateScalarIndexa: nullptr);
            v63 = (idMD6FusionBranch *)allocator->Alloc(this: allocator, a2: 5);
            RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
            LODWORD(v64) = "idAnimWebBlendEquation - allocatedNodes.Append";
            HIDWORD(v64) = 2;
            idPLogScope::idPLogScope(this: (idPLogScope *)&v205.num, pl: &::pLog, gMask: v64, label: v65);
            v204.num = (int)v63;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
              obj: (const encounterGroupRole_t *)&v204.num);
            idPLogScope::~idPLogScope(this: (idPLogScope *)&v205.num);
            RD_EventEnd();
            idMD6FusionBranch::Init(
              this: v63,
              numDimensions_: v62,
              userChannelIndices_: (const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v205.granularity,
              coordinates: (const idList<float,5> *)&v257,
              animations: (const idList<idMD6Node *,5> *)&v248,
              currentCoordinate_: (const idList<float,5> *)&v231,
              weightGroup: (const md6WeightGroup_t)v204.list,
              flags: v61);
            *root = v63;
            for ( i = 0; i < v62; ++i )
            {
              v67 = v235.list[v40];
              if ( (int)v67 >= 0 )
                idAnimWebBlendEquation::SetupScalarPair(
                  this,
                  scalars,
                  scalarPairs: a28,
                  node: v63,
                  scalarIndex: (int)v67,
                  scalarPairIndex: (const int)v240.list[v40],
                  fieldType: 4u,
                  fieldFlags: ((_cntlzw(*((unsigned __int8 *)v227.list + i)) & 0x20) == 0) + 1,
                  coordinateIndex: v113,
                  a10: v121,
                  a11: v128,
                  a12: v132,
                  a13: v136,
                  a14: v140,
                  a15: v144,
                  a16: v148,
                  a17: v152,
                  a18: v156,
                  a19: v160,
                  a20: v164,
                  a21: v168,
                  a22: v172,
                  a23: v176,
                  a24: v180,
                  a25: v184,
                  a26: v188,
                  a27: v192,
                  a28: i);
              ++v40;
            }
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v227);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v205.granularity);
            idList<idThread *,58>::Clear(this: &v257);
            idList<idThread *,58>::Clear(this: &v248);
            idList<idThread *,58>::Clear(this: &v240);
            idList<idThread *,58>::Clear(this: &v235);
            idList<idThread *,58>::Clear(this: &v231);
          }
        }
        else
        {
          v47 = idStr::Left(this: &v244, result: &v242, len: 5);
          idStr::StripLeadingOnce(this: &v242, string: v47->data);
          idStr::FreeData(this: &v244);
          v48 = idStr::StripLeadingOnce(this: &v242, string: "u");
          v49 = idStr::StripLeadingOnce(this: &v242, string: "y");
          v50 = atol(nptr: v242.data);
          if ( v50 <= 1 )
            v50 = 1;
          *(_QWORD *)&v237.num = 6;
          v237.list = (idVehicleState **)&v238;
          *(_DWORD *)&v237.granularity = 66817;
          *(_QWORD *)&v233.num = 6;
          v233.list = (idVehicleState **)&v234;
          *(_DWORD *)&v233.granularity = 66817;
          *(_QWORD *)&v229.num = 6;
          v229.list = (idVehicleState **)&v230;
          *(_DWORD *)&v229.granularity = 66817;
          *(_QWORD *)&v246.num = 256;
          v246.list = (idVehicleState **)&v247;
          *(_DWORD *)&v246.granularity = 66817;
          *(_QWORD *)&v255.num = 1536;
          v255.list = (idVehicleState **)&v256;
          *(_DWORD *)&v255.granularity = 66817;
          *(_QWORD *)&v212.num = 6;
          v212.list = (idVehicleState **)v213;
          *(_DWORD *)&v212.granularity = 66817;
          memset(v213, 255, 12);
          *(_QWORD *)&v225.num = 6;
          v225.list = (idMD6Node **)&v226;
          *(_DWORD *)&v225.granularity = 66817;
          v204.list = nullptr;
          idAnimWebBlendEquation::ParseBlend(
            this,
            useUserChannels: v48,
            numDimensions: v50,
            src,
            modelInfo,
            model,
            allocator,
            existingNodes,
            scalars: (idList<idAnimWebScalar,5> *)v110,
            scalarPairs: (idList<idAnimWebScalarPair,5> *)v118,
            userChannelIndices: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)v125,
            coordinateList: (idList<float,5> *)v129,
            animationList: v133,
            currentCoordinate: v137,
            currentCoordinateScalarIndex: v141,
            currentCoordinateScalarPairIndex: v145,
            isCopyOnPlay: v149,
            wg: v153,
            baseAnimation: v157,
            a20: v161,
            a21: v165,
            a22: v169,
            a23: v173,
            a24: v177,
            a25: v181,
            a26: v185,
            a27: v189,
            a28: scalars,
            a29: v193,
            a30: a28,
            a31: v194,
            a32: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v212,
            a33: v195,
            a34: (idList<float,13> *)&v255,
            a35: v196,
            scalarsa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v246,
            a37: v197,
            scalarPairsa: (idList<float,13> *)&v237,
            a39: v198,
            userChannelIndicesa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v233,
            a41: v199,
            coordinateLista: (idList<idSpawnArea::GeneratedPosition *,5> *)&v229,
            a43: v200,
            animationLista: &v225,
            a45: v201,
            currentCoordinatea: &v204,
            a47: v202,
            currentCoordinateScalarIndexa: nullptr);
          v51 = (idMD6BlendBranch *)allocator->Alloc(this: allocator, a2: 3);
          RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
          LODWORD(v52) = "idAnimWebBlendEquation - allocatedNodes.Append";
          HIDWORD(v52) = 2;
          idPLogScope::idPLogScope(this: (idPLogScope *)&v205.num, pl: &::pLog, gMask: v52, label: v53);
          v204.num = (int)v51;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
            obj: (const encounterGroupRole_t *)&v204.num);
          idPLogScope::~idPLogScope(this: (idPLogScope *)&v205.num);
          RD_EventEnd();
          idMD6BlendBranch::Init(
            this: v51,
            numDimensions_: v50,
            userChannelIndices_: (const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v212,
            coordinates: (const idList<float,5> *)&v255,
            animations: (const idList<idMD6Node *,5> *)&v246,
            currentCoordinate_: (const idList<float,5> *)&v237,
            weightGroup: (const md6WeightGroup_t)v204.list,
            flags: v49);
          *root = v51;
          for ( j = 0; j < v50; ++j )
          {
            v55 = v233.list[v40];
            if ( (int)v55 >= 0 )
              idAnimWebBlendEquation::SetupScalarPair(
                this,
                scalars,
                scalarPairs: a28,
                node: v51,
                scalarIndex: (int)v55,
                scalarPairIndex: (const int)v229.list[v40],
                fieldType: 4u,
                fieldFlags: ((_cntlzw(*((unsigned __int8 *)v225.list + j)) & 0x20) == 0) + 1,
                coordinateIndex: v112,
                a10: v120,
                a11: v127,
                a12: v131,
                a13: v135,
                a14: v139,
                a15: v143,
                a16: v147,
                a17: v151,
                a18: v155,
                a19: v159,
                a20: v163,
                a21: v167,
                a22: v171,
                a23: v175,
                a24: v179,
                a25: v183,
                a26: v187,
                a27: v191,
                a28: j);
            ++v40;
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v225);
          idList<idThread *,58>::Clear(this: &v212);
          idList<idThread *,58>::Clear(this: &v255);
          idList<idThread *,58>::Clear(this: &v246);
          idList<idThread *,58>::Clear(this: &v229);
          idList<idThread *,58>::Clear(this: &v233);
          idList<idThread *,58>::Clear(this: &v237);
        }
      }
      else
      {
        v216.num = 0;
        v216.size = 1;
        v216.granularity = 1;
        v216.list = (idVehicleState **)&v217;
        v216.memTag = 5;
        v216.listStatic = 1;
        v214.size = 1;
        v214.num = 0;
        v214.granularity = 1;
        v214.list = (idVehicleState **)&v215;
        v214.memTag = 5;
        v214.listStatic = 1;
        v220.size = 1;
        v220.num = 0;
        v220.granularity = 1;
        v220.list = (idVehicleState **)&v221;
        v220.memTag = 5;
        v220.listStatic = 1;
        v252.num = 0;
        v252.size = 256;
        v252.granularity = 1;
        v252.list = (idVehicleState **)&v253;
        v252.memTag = 5;
        v252.listStatic = 1;
        v250.size = 256;
        v250.num = 0;
        v250.granularity = 1;
        v250.list = (idVehicleState **)&v251;
        v250.memTag = 5;
        v250.listStatic = 1;
        v218.size = 1;
        v218.num = 0;
        v218.granularity = 1;
        v218.list = (idVehicleState **)&v219;
        v218.memTag = 5;
        v218.listStatic = 1;
        v219 = -1;
        v222.size = 1;
        v222.num = 0;
        v222.granularity = 1;
        v222.list = (idMD6Node **)&v223;
        v222.memTag = 5;
        v222.listStatic = 1;
        v205.list = nullptr;
        v204.list = nullptr;
        idAnimWebBlendEquation::ParseBlend(
          this,
          useUserChannels: false,
          numDimensions: 1,
          src,
          modelInfo,
          model,
          allocator,
          existingNodes,
          scalars: (idList<idAnimWebScalar,5> *)v110,
          scalarPairs: (idList<idAnimWebScalarPair,5> *)v118,
          userChannelIndices: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)v125,
          coordinateList: (idList<float,5> *)v129,
          animationList: v133,
          currentCoordinate: v137,
          currentCoordinateScalarIndex: v141,
          currentCoordinateScalarPairIndex: v145,
          isCopyOnPlay: v149,
          wg: v153,
          baseAnimation: v157,
          a20: v161,
          a21: v165,
          a22: v169,
          a23: v173,
          a24: v177,
          a25: v181,
          a26: v185,
          a27: v189,
          a28: scalars,
          a29: v193,
          a30: a28,
          a31: v194,
          a32: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v218,
          a33: v195,
          a34: (idList<float,13> *)&v250,
          a35: v196,
          scalarsa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v252,
          a37: v197,
          scalarPairsa: (idList<float,13> *)&v216,
          a39: v198,
          userChannelIndicesa: (idList<idSpawnArea::GeneratedPosition *,5> *)&v214,
          a41: v199,
          coordinateLista: (idList<idSpawnArea::GeneratedPosition *,5> *)&v220,
          a43: v200,
          animationLista: &v222,
          a45: v201,
          currentCoordinatea: &v205,
          a47: v202,
          currentCoordinateScalarIndexa: (idMD6Node **)&v204);
        v41 = (idMD6BlendAdditiveBranch *)allocator->Alloc(this: allocator, a2: 4);
        RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
        LODWORD(v42) = "idAnimWebBlendEquation - allocatedNodes.Append";
        HIDWORD(v42) = 2;
        idPLogScope::idPLogScope(this: (idPLogScope *)&v205.num, pl: &::pLog, gMask: v42, label: v43);
        v204.num = (int)v41;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
          obj: (const encounterGroupRole_t *)&v204.num);
        idPLogScope::~idPLogScope(this: (idPLogScope *)&v205.num);
        RD_EventEnd();
        idMD6BlendAdditiveBranch::Init(
          this: v41,
          baseAnimation_: (idMD6Node *)v204.list,
          coordinates: (const idList<float,5> *)&v250,
          animations: (const idList<idMD6Node *,5> *)&v252,
          currentCoordinate_: *(float *)v216.list,
          weightGroup: (const md6WeightGroup_t)v216.list);
        list = (int *)v214.list;
        *root = v41;
        if ( *list >= 0 )
          idAnimWebBlendEquation::SetupScalarPair(
            this,
            scalars,
            scalarPairs: a28,
            node: v41,
            scalarIndex: *list,
            scalarPairIndex: (const int)*v220.list,
            fieldType: 4u,
            fieldFlags: ((_cntlzw(*(unsigned __int8 *)v222.list) & 0x20) == 0) + 1,
            coordinateIndex: v111,
            a10: v119,
            a11: v126,
            a12: v130,
            a13: v134,
            a14: v138,
            a15: v142,
            a16: v146,
            a17: v150,
            a18: v154,
            a19: v158,
            a20: v162,
            a21: v166,
            a22: v170,
            a23: v174,
            a24: v178,
            a25: v182,
            a26: v186,
            a27: v190,
            a28: 0);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v222);
        idList<idThread *,58>::Clear(this: &v218);
        idList<idThread *,58>::Clear(this: &v250);
        idList<idThread *,58>::Clear(this: &v252);
        idList<idThread *,58>::Clear(this: &v220);
        idList<idThread *,58>::Clear(this: &v214);
        idList<idThread *,58>::Clear(this: &v216);
      }
      goto LABEL_72;
    }
    v86 = BOP_MAX;
    v87 = BOP_NO;
    v88 = idAnimWebBlendEquation::funcToBlendOp;
    while ( *v88 == nullptr || idStr::Icmp(s1: *v88, s2: v242.data) != 0 )
    {
      ++v88;
      ++v87;
      if ( (int)v88 >= (int)&idLexerException `RTTI Type Descriptor' )
        goto LABEL_57;
    }
    v86 = v87;
LABEL_57:
    v204.list = nullptr;
    *(_DWORD *)&v204.granularity = 0;
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 44, token: &v242);
    idAnimWebBlendEquation::Parse_r(
      this,
      src,
      modelInfo,
      model,
      allocator,
      scalars,
      existingNodes,
      root: (idMD6Node **)&v204,
      scalarPairs: v110,
      animList: v118);
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v242);
    idAnimWebBlendEquation::Parse_r(
      this,
      src,
      modelInfo,
      model,
      allocator,
      scalars,
      existingNodes,
      root: (idMD6Node **)&v204.granularity,
      scalarPairs: v117,
      animList: v124);
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v242);
    v203 = false;
    v89 = 0.0;
    *(float *)&v204.num = 0.0;
    v90 = 0.0;
    idAnimWebBlendEquation::ParseScalar(
      this,
      src,
      scalars,
      scalarPairs: a28,
      scalarIndex: &v205.num,
      scalarPairIndex: (int *)&v205,
      value: (float *)&v204.num,
      isCopyOnPlay: &v203);
    v91 = v205.num;
    v92 = *(float *)&v204.num;
    if ( v205.num < 0 )
    {
      v90 = *(float *)&v204.num;
      if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 39, token: &v242)
        || idLexer::CheckTokenType(this: src, type: 5, subtype: 38, token: &v242) )
      {
        if ( v242.subtype == 39 )
          v90 = 0.0;
        else
          v90 = 1.0;
        goto LABEL_65;
      }
      if ( idLexer::CheckTokenType(this: src, type: 5, subtype: 40, token: &v242) )
      {
        v90 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: src, type: 5, subtype: 40, token: &v242);
LABEL_65:
        v89 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      }
    }
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 45, token: &v242);
    idAnimWebBlendEquation::ParseWeightGroup(this, src);
    v93 = (idMD6Branch *)allocator->Alloc(this: allocator, a2: 0);
    RD_EventBegin(name: "idAnimWebBlendEquation - allocatedNodes.Append");
    v204.size = (int)&::pLog;
    v94 = -1;
    v204.num = -1;
    if ( (::pLog.groupMask & 2) != 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v95 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
      idMem::PopHeap(this: &mem);
      v95->label = "idAnimWebBlendEquation - allocatedNodes.Append";
      v95->parent = ::pLog.lastEntry;
      v94 = ::pLog.logEntries.num - 1;
      ::pLog.lastEntry = ::pLog.logEntries.num - 1;
      v204.num = ::pLog.logEntries.num - 1;
      LODWORD(v96) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v95->totalTicks = v96;
    }
    v205.num = (int)v93;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->allocatedNodes,
      obj: (const encounterGroupRole_t *)&v205.num);
    if ( v94 >= 0 )
    {
      v97 = &::pLog.logEntries.list[v94];
      v98 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      parent = v97->parent;
      LODWORD(v100) = v98 - LODWORD(v97->totalTicks);
      v97->totalTicks = v100;
      ::pLog.lastEntry = parent;
    }
    RD_EventEnd();
    idMD6Branch::Init(
      this: v93,
      left: (idMD6Node *)v204.list,
      right: *(idMD6Node **)&v204.granularity,
      op: v86,
      originBlend: ORIGINBLEND_BRANCH,
      startAlpha: v92,
      targetAlpha: v90,
      alphaRate: v89,
      filterGroup: v102,
      blendType: v101);
    *root = v93;
    if ( v91 >= 0 )
    {
      v103 = (int)&a28->list[(int)v205.list];
      v104 = _cntlzw(v203);
      *(_BYTE *)(v103 + 12) = 0;
      *(_DWORD *)(v103 + 4) = -1;
      *(_DWORD *)(v103 + 8) = v93;
      *(_DWORD *)v103 = v91;
      *(_BYTE *)(v103 + 13) = scalars->list[v91].flags | (((v104 & 0x20) == 0) + 1);
    }
    goto LABEL_72;
  }
  idAnimWebBlendEquation::Parse_r(
    this,
    src,
    modelInfo,
    model,
    allocator,
    scalars,
    existingNodes,
    root,
    scalarPairs: v110,
    animList: v118);
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 45, token: &v242);
LABEL_72:
  idStr::FreeData(this: &v242);
  if ( v224.logIndex >= 0 )
  {
    pLog = v224.pLog;
    v106 = &v224.pLog->logEntries.list[v224.logIndex];
    v107 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v106->totalTicks;
    HIDWORD(totalTicks) = v106->parent;
    LODWORD(v109) = v107 - totalTicks;
    v106->totalTicks = v109;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
LABEL_74:
  RD_EventEnd();
}


// ========================================================================
// __unwind$227342
// EA  : 0x825FD0F8
// RVA : 0x005FD0F8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227342()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19808));
}


// ========================================================================
// __unwind$227343
// EA  : 0x825FD120
// RVA : 0x005FD120
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227343()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 424));
}


// ========================================================================
// __unwind$227344
// EA  : 0x825FD148
// RVA : 0x005FD148
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227344()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19984 + 784));
}


// ========================================================================
// __unwind$227347
// EA  : 0x825FD170
// RVA : 0x005FD170
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227347()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 304));
}


// ========================================================================
// __unwind$227348
// EA  : 0x825FD198
// RVA : 0x005FD198
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227348()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 272));
}


// ========================================================================
// __unwind$227349
// EA  : 0x825FD1C0
// RVA : 0x005FD1C0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227349()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 368));
}


// ========================================================================
// __unwind$227350
// EA  : 0x825FD1E8
// RVA : 0x005FD1E8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227350()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 4304));
}


// ========================================================================
// __unwind$227351
// EA  : 0x825FD210
// RVA : 0x005FD210
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227351()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 3264));
}


// ========================================================================
// __unwind$227352
// EA  : 0x825FD238
// RVA : 0x005FD238
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227352()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 336));
}


// ========================================================================
// __unwind$227353
// EA  : 0x825FD260
// RVA : 0x005FD260
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227353()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 400));
}


// ========================================================================
// __unwind$227354
// EA  : 0x825FD288
// RVA : 0x005FD288
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227354()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19809));
}


// ========================================================================
// __unwind$227355
// EA  : 0x825FD2B0
// RVA : 0x005FD2B0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227355()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 200));
}


// ========================================================================
// __unwind$227356
// EA  : 0x825FD2D8
// RVA : 0x005FD2D8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227356()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19984 + 1120));
}


// ========================================================================
// __unwind$227357
// EA  : 0x825FD300
// RVA : 0x005FD300
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227357()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 688));
}


// ========================================================================
// __unwind$227358
// EA  : 0x825FD328
// RVA : 0x005FD328
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227358()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 592));
}


// ========================================================================
// __unwind$227359
// EA  : 0x825FD350
// RVA : 0x005FD350
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227359()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 496));
}


// ========================================================================
// __unwind$227360
// EA  : 0x825FD378
// RVA : 0x005FD378
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227360()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 1184));
}


// ========================================================================
// __unwind$227361
// EA  : 0x825FD3A0
// RVA : 0x005FD3A0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227361()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 7488));
}


// ========================================================================
// __unwind$227362
// EA  : 0x825FD3C8
// RVA : 0x005FD3C8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 240));
}


// ========================================================================
// __unwind$227363
// EA  : 0x825FD3F0
// RVA : 0x005FD3F0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227363()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 432));
}


// ========================================================================
// __unwind$227364
// EA  : 0x825FD418
// RVA : 0x005FD418
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227364()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19810));
}


// ========================================================================
// __unwind$227365
// EA  : 0x825FD440
// RVA : 0x005FD440
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227365()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 200));
}


// ========================================================================
// __unwind$227366
// EA  : 0x825FD468
// RVA : 0x005FD468
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 19984 + 1152));
}


// ========================================================================
// __unwind$227367
// EA  : 0x825FD490
// RVA : 0x005FD490
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227367()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 544));
}


// ========================================================================
// __unwind$227368
// EA  : 0x825FD4B8
// RVA : 0x005FD4B8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227368()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 640));
}


// ========================================================================
// __unwind$227369
// EA  : 0x825FD4E0
// RVA : 0x005FD4E0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227369()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 736));
}


// ========================================================================
// __unwind$227370
// EA  : 0x825FD508
// RVA : 0x005FD508
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227370()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 2224));
}


// ========================================================================
// __unwind$227371
// EA  : 0x825FD530
// RVA : 0x005FD530
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227371()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 13648));
}


// ========================================================================
// __unwind$227372
// EA  : 0x825FD558
// RVA : 0x005FD558
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227372()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 208));
}


// ========================================================================
// __unwind$227373
// EA  : 0x825FD580
// RVA : 0x005FD580
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227373()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 19984 + 464));
}


// ========================================================================
// __unwind$227374
// EA  : 0x825FD5A8
// RVA : 0x005FD5A8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227374()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19811));
}


// ========================================================================
// __unwind$227375
// EA  : 0x825FD5D0
// RVA : 0x005FD5D0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227375()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 200));
}


// ========================================================================
// __unwind$227378
// EA  : 0x825FD5F8
// RVA : 0x005FD5F8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227378()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19812));
}


// ========================================================================
// __unwind$227379
// EA  : 0x825FD620
// RVA : 0x005FD620
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227379()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 200));
}


// ========================================================================
// __unwind$227380
// EA  : 0x825FD648
// RVA : 0x005FD648
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227380()
{
  int v0; // r12

  idAnimWebBlendEquation::animList_t::~animList_t(this: (idAnimWebBlendEquation::animList_t *)(v0 - 19984 + 5344));
}


// ========================================================================
// __unwind$227381
// EA  : 0x825FD670
// RVA : 0x005FD670
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227381()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19813));
}


// ========================================================================
// __unwind$227382
// EA  : 0x825FD698
// RVA : 0x005FD698
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227382()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 184));
}


// ========================================================================
// __unwind$227376
// EA  : 0x825FD6C0
// RVA : 0x005FD6C0
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227376()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19814));
}


// ========================================================================
// __unwind$227377
// EA  : 0x825FD6E8
// RVA : 0x005FD6E8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227377()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 728));
}


// ========================================================================
// __unwind$227345
// EA  : 0x825FD710
// RVA : 0x005FD710
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227345()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 19984 + 19815));
}


// ========================================================================
// __unwind$227346
// EA  : 0x825FD738
// RVA : 0x005FD738
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_227346()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 19984 + 184));
}


// ========================================================================
// ?Parse@idAnimWebBlendEquation@@QAA_NABVidModelInfo@idDeclAnimWebNode@@PBVidMD6Model@@PAVidMD6Allocator@@HHPBDAAV?$idList@VidAnimWebScalar@@$0CB@@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@AAPAVidMD6Node@@AAV?$idList@VidAnimWebScalarPair@@$0CB@@@@Z
// EA  : 0x825FD768
// RVA : 0x005FD768
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

int __fastcall idAnimWebBlendEquation::Parse(
        idAnimWebBlendEquation *this,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idMD6Model *model,
        idMD6Allocator *allocator,
        int time,
        int ticksPerSec_,
        const char *equation,
        idList<idAnimWebScalar,5> *scalars,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes,
        idMD6Node **root,
        idList<idAnimWebScalarPair,33> *scalarPairs,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idList<idAnimWebBlendEquation::existingNode_t,5> *a28,
        int a29,
        idMD6Node **a30,
        int a31,
        idList<idAnimWebScalarPair,5> *a32)
{
  unsigned __int64 v40; // r6
  const char *v41; // r7
  unsigned __int64 v42; // r6
  const char *v43; // r7
  unsigned int i; // r5
  idList<idAnimWebScalarPair,5> *v46; // [sp+8h] [-158h]
  idAnimWebBlendEquation::animList_t *v47; // [sp+Ch] [-154h]
  int v48; // [sp+10h] [-150h]
  int v49; // [sp+14h] [-14Ch]
  int v50; // [sp+18h] [-148h]
  int v51; // [sp+1Ch] [-144h]
  int v52; // [sp+20h] [-140h]
  int v53; // [sp+24h] [-13Ch]
  int v54; // [sp+28h] [-138h]
  int v55; // [sp+2Ch] [-134h]
  int v56; // [sp+30h] [-130h]
  int v57; // [sp+34h] [-12Ch]
  int v58; // [sp+38h] [-128h]
  int v59; // [sp+3Ch] [-124h]
  int v60; // [sp+40h] [-120h]
  int v61; // [sp+44h] [-11Ch]
  int v62; // [sp+48h] [-118h]
  int v63; // [sp+4Ch] [-114h]
  int v64; // [sp+50h] [-110h]
  int v65; // [sp+58h] [-108h]
  idPLogScope v66; // [sp+60h] [-100h] BYREF
  idPLogScope v67; // [sp+68h] [-F8h] BYREF
  idLexer v68; // [sp+70h] [-F0h] BYREF

  RD_EventBegin(name: "idAnimWebBlendEquation::Parse");
  LODWORD(v40) = "idAnimWebBlendEquation::Parse";
  HIDWORD(v40) = 2;
  idPLogScope::idPLogScope(this: &v66, pl: &pLog, gMask: v40, label: v41);
  idLexer::idLexer(this: &v68, flags_: 262704);
  RD_EventBegin(name: "idAnimWebBlendEquation::Parse - LoadMemory");
  LODWORD(v42) = "idAnimWebBlendEquation::Parse - LoadMemory";
  HIDWORD(v42) = 2;
  idPLogScope::idPLogScope(this: &v67, pl: &pLog, gMask: v42, label: v43);
  for ( i = 0; equation[i] != 0; ++i )
    ;
  if ( idLexer::LoadMemory(this: &v68, ptr: equation, length_: i, name: &byte_8200D768) )
  {
    idPLogScope::~idPLogScope(this: &v67);
    RD_EventEnd();
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->allocatedNodes);
    this->startTime = time;
    this->ticksPerSec = ticksPerSec_;
    idAnimWebBlendEquation::Parse_r(
      this,
      src: &v68,
      modelInfo,
      model,
      allocator,
      scalars,
      existingNodes: a28,
      root: a30,
      scalarPairs: v46,
      animList: v47,
      a11: v48,
      a12: v49,
      a13: v50,
      a14: v51,
      a15: v52,
      a16: v53,
      a17: v54,
      a18: v55,
      a19: v56,
      a20: v57,
      a21: v58,
      a22: v59,
      a23: v60,
      a24: v61,
      a25: v62,
      a26: v63,
      a27: v64,
      a28: a32,
      a29: v65,
      a30: nullptr);
    idLexer::~idLexer(this: &v68);
    idPLogScope::~idPLogScope(this: &v66);
    RD_EventEnd();
    return 1;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v67);
    RD_EventEnd();
    idLexer::~idLexer(this: &v68);
    idPLogScope::~idPLogScope(this: &v66);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// $M228601
// EA  : 0x825FD8FC
// RVA : 0x005FD8FC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void *_M228601()
{
  int v0; // r12
  int v1; // r31
  int v2; // r28
  int v3; // r29
  int v4; // r27
  int v5; // r30

  v1 = v0 - 352;
  idLib::Warning(fmt: "idAnimWebBlendEquation::Parse: %s", idException::error);
  v2 = *(_DWORD *)(v1 + 372);
  v3 = 0;
  if ( *(int *)(v2 + 12) > 0 )
  {
    v4 = *(_DWORD *)(v1 + 396);
    v5 = 0;
    do
    {
      (*(void (__fastcall **)(int, _DWORD))(*(_DWORD *)v4 + 8))(a1: v4, a2: *(_DWORD *)(*(_DWORD *)(v2 + 8) + v5));
      ++v3;
      v5 += 4;
    }
    while ( v3 < *(_DWORD *)(v2 + 12) );
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v2 + 8));
  return &_LN16;
}


// ========================================================================
// __unwind$228507
// EA  : 0x825FD98C
// RVA : 0x005FD98C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_228507()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 252));
}


// ========================================================================
// __unwind$228508
// EA  : 0x825FD9B4
// RVA : 0x005FD9B4
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_228508()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$228509
// EA  : 0x825FD9DC
// RVA : 0x005FD9DC
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_228509()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$228510
// EA  : 0x825FDA04
// RVA : 0x005FDA04
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_228510()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 253));
}


// ========================================================================
// __unwind$228511
// EA  : 0x825FDA2C
// RVA : 0x005FDA2C
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.cpp
// ========================================================================

void _unwind_228511()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 104));
}

