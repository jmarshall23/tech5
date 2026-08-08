
// ========================================================================
// `idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize'::`2'::localOptExp::OptSubExpR
// EA  : 0x82864CC8
// RVA : 0x00864CC8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
        int nodeIndex,
        idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *srcList)
{
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v3; // r31
  int v4; // r29
  int var0; // r3
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t op; // r7
  char *v7; // r10
  char *v8; // r11
  double v9; // fp12
  int v11; // r9
  int var1; // r10
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *list; // r11
  char *v14; // r8
  int v15; // r9
  char *v16; // r10
  double coef; // fp11
  double v18; // fp12
  double v19; // fp0
  _DWORD *p_coef; // r9
  float v21; // r8
  double v22; // fp12
  int v23; // r5

  v3 = &srcList->list[nodeIndex];
  v4 = 0;
  var0 = v3->var0;
  if ( var0 != 255 )
  {
    v4 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
           nodeIndex: var0,
           srcList);
    if ( v3->var1 != 255 )
    {
      v4 += _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
              nodeIndex: v3->var1,
              srcList);
      if ( v3->var2 != 255 )
        v4 += _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
                nodeIndex: v3->var2,
                srcList);
    }
  }
  op = v3->op;
  if ( op == OP_MUL )
  {
    v11 = v3->var0;
    if ( *(idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t *)((char *)&srcList->list->op + __ROL4__(v11, 4)) == OP_VAL )
    {
      var1 = v3->var1;
      if ( *(idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t *)((char *)&srcList->list->op + __ROL4__(var1, 4)) != OP_VAL )
      {
        v3->var0 = var1;
        v3->var1 = v11;
      }
    }
  }
  else if ( op != OP_DIV )
  {
    if ( op == OP_ADD || op == OP_SUB )
    {
      v7 = (char *)srcList->list + __ROL4__(v3->var0, 4);
      if ( *((_DWORD *)v7 + 1) == 1 )
      {
        v8 = (char *)srcList->list + __ROL4__(v3->var1, 4);
        if ( *((_DWORD *)v8 + 1) == 1 )
        {
          if ( op == OP_ADD )
            v9 = (float)(*(float *)v7 + *(float *)v8);
          else
            v9 = (float)(*(float *)v7 - *(float *)v8);
          v3->coef = (float)v9 * v3->coef;
          v3->var0 = -1;
          v3->op = OP_VAL;
          v3->var1 = -1;
          return v4 + 2;
        }
      }
    }
    return v4;
  }
  list = srcList->list;
  v14 = (char *)srcList->list + __ROL4__(v3->var1, 4);
  if ( *((_DWORD *)v14 + 1) != 1 )
    return v4;
  v15 = v3->var0;
  v16 = (char *)list + __ROL4__(v15, 4);
  if ( *((_DWORD *)v16 + 1) == 1 )
  {
    if ( op == OP_MUL )
    {
      coef = *(float *)v14;
      v18 = (float)(*(float *)v16 * v3->coef);
    }
    else
    {
      coef = v3->coef;
      v18 = (float)(*(float *)v16 / *(float *)v14);
    }
    v3->coef = (float)v18 * (float)coef;
    v3->var0 = -1;
    v3->op = OP_VAL;
    v3->var1 = -1;
    return v4 + 2;
  }
  else
  {
    if ( op == OP_MUL )
      v19 = (float)(v3->coef * *(float *)v14);
    else
      v19 = (float)(v3->coef / *(float *)v14);
    v21 = list[v15].coef;
    p_coef = (_DWORD *)&list[v15].coef;
    v3->coef = v21;
    v22 = (float)(v3->coef * (float)v19);
    v3->op = p_coef[1];
    *(_DWORD *)&v3->parent = p_coef[2];
    v23 = p_coef[3];
    v3->coef = v22;
    v3->varId.index = v23;
    return v4 + 2;
  }
}


// ========================================================================
// `idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse'::`2'::local_t::PopOp
// EA  : 0x82864F08
// RVA : 0x00864F08
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse_::_2_::local_t::PopOp(
        idList<idEntityPtr<idEntity>,58> *opStack,
        idList<idEntityPtr<idEntity>,58> *varStack,
        idLexer *src,
        idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *nodeList)
{
  int v6; // r27
  int value; // r29
  int v9; // r30
  int v10; // r27
  idList<idEntityPtr<idEntity>,58> *v11; // r3
  int v12; // r31

  v6 = opStack->num - 1;
  value = opStack->list[v6].spawnId.value;
  if ( value == 254 )
    idLexer::Error(this: src, str: "syntax error, unclosed parentheses");
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: opStack, index: v6);
  v9 = varStack->num - 1;
  v10 = varStack->list[v9].spawnId.value;
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: varStack, index: v9);
  v11 = varStack;
  v12 = varStack->list[v9 - 1].spawnId.value;
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: v11, index: v9 - 1);
  nodeList->list[value].var0 = v12;
  nodeList->list[value].var1 = v10;
  return value;
}


// ========================================================================
// ?Eval@?$idRuntimeExpression@VVarId@idUserChannelExpression@@VVarContext@2@@@QAAMAAVVarContext@idUserChannelExpression@@@Z
// EA  : 0x828651E8
// RVA : 0x008651E8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

float __fastcall idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Eval(
        idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext> *this,
        idUserChannelExpression::VarContext *varContext)
{
  double v4; // fp1
  int v5; // r30
  char v6; // r29
  encounterGroupRole_t v7; // r27
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v8; // r28
  float v9; // r11
  bool v10; // zf
  double v12; // fp30
  double v13; // fp29
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t op; // r4
  double v17; // fp31
  float v19[4]; // [sp+50h] [-8A0h] BYREF
  idList<float,116> v20; // [sp+60h] [-890h] BYREF
  int v21; // [sp+70h] [-880h] BYREF
  idList<enum encounterGroupRole_t,5> v22; // [sp+470h] [-480h] BYREF
  int v23; // [sp+480h] [-470h] BYREF

  if ( this->root == 255 )
  {
    v4 = 0.0;
    return *((float *)&v4 + 1);
  }
  v20.granularity = 1;
  v20.size = 253;
  v20.num = 0;
  v20.memTag = 5;
  v20.list = (float *)&v21;
  v20.listStatic = 1;
  v22.size = 253;
  v22.num = 0;
  v22.granularity = 1;
  v22.list = (encounterGroupRole_t *)&v23;
  v22.memTag = 5;
  v22.listStatic = 1;
  v5 = 255;
  idList<idAnimWebBlendTree *,5>::Append(this: &v22, obj: (const encounterGroupRole_t *)this);
  do
  {
    v6 = 0;
    v7 = v22.list[v22.num - 1];
    v8 = &this->nodeAlloc.list[v7];
    LODWORD(v9) = v8->var0;
    if ( v5 != 255 )
    {
      v10 = v5 == LODWORD(v9);
      LODWORD(v9) = v8->var1;
      if ( !v10 )
      {
        if ( v5 != LODWORD(v9) )
          goto LABEL_11;
        LODWORD(v9) = v8->var2;
      }
    }
    if ( LODWORD(v9) == 255 )
    {
      v6 = 1;
    }
    else
    {
      v19[0] = v9;
      idList<idAnimWebBlendTree *,5>::Append(this: &v22, obj: (const encounterGroupRole_t *)v19);
    }
LABEL_11:
    if ( v6 != 0 )
    {
      if ( v22.num - 1 >= 0 && v22.num - 1 < v22.num )
        --v22.num;
      v5 = v7;
      _FP31 = 0.0;
      v12 = 0.0;
      v13 = 0.0;
      if ( v8->var2 != 255 )
      {
        v13 = v20.list[v20.num - 1];
        idList<float,5>::RemoveIndex(this: &v20, index: v20.num - 1);
      }
      if ( v8->var1 != 255 )
      {
        v12 = v20.list[v20.num - 1];
        idList<float,5>::RemoveIndex(this: &v20, index: v20.num - 1);
      }
      if ( v8->var0 != 255 )
      {
        _FP31 = v20.list[v20.num - 1];
        idList<float,5>::RemoveIndex(this: &v20, index: v20.num - 1);
      }
      op = v8->op;
      switch ( op )
      {
        case OP_VAL:
          _FP31 = 1.0;
          break;
        case OP_VAR:
          _FP31 = varContext->channels[v8->varId.index];
          break;
        case OP_MUL:
          _FP31 = (float)((float)v12 * (float)_FP31);
          break;
        case OP_DIV:
          _FP31 = (float)((float)_FP31 / (float)v12);
          break;
        case OP_MAX:
          _FP0 = (float)((float)_FP31 - (float)v12);
          __asm { fsel      f31, f0, f31, f30 }
          break;
        case OP_MIN:
          _FP0 = (float)((float)_FP31 - (float)v12);
          __asm { fsel      f31, f0, f30, f31 }
          break;
        case OP_LERP:
          _FP31 = (float)((float)((float)((float)v12 - (float)_FP31) * (float)v13) + (float)_FP31);
          break;
        case OP_CLAMP:
          if ( v13 >= _FP31 )
          {
            if ( v13 <= v12 )
              _FP31 = v13;
            else
              _FP31 = v12;
          }
          break;
        case OP_SUB:
          _FP31 = (float)((float)_FP31 - (float)v12);
          break;
        case OP_ADD:
          _FP31 = (float)((float)v12 + (float)_FP31);
          break;
        default:
          goto _LN140_0;
      }
      v19[0] = v8->coef * (float)_FP31;
      idList<float,13>::Append(this: (idList<float,13> *)&v20, obj: v19);
    }
    else
    {
      v5 = 255;
    }
  }
  while ( v22.num != 0 );
  if ( v20.num != 1 )
  {
    idLib::Error(fmt: "Stack contains incorrect number of results after eval (%d)", v20.num);
_LN140_0:
    idLib::Error(fmt: "Unknown op in expression: %d (code error, not content)", op);
  }
  v17 = *v20.list;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v22);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v20);
  v4 = v17;
  return *((float *)&v4 + 1);
}


// ========================================================================
// $LN123_1
// EA  : 0x82865528
// RVA : 0x00865528
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _LN123_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2288 + 96));
}


// ========================================================================
// __unwind$220941
// EA  : 0x82865550
// RVA : 0x00865550
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_220941()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2288 + 1136));
}


// ========================================================================
// `idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize'::`3'::localCopyExp::CopyExpR
// EA  : 0x82865718
// RVA : 0x00865718
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
        int srcIndex,
        idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *srcList,
        idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *dstList)
{
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v6; // r3
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v7; // r31
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v8; // r8
  int v9; // r28
  int var0; // r3
  int var1; // r3
  int var2; // r3

  v6 = idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Alloc(this: dstList);
  v8 = &srcList->list[srcIndex];
  v9 = dstList->num - 1;
  v7 = v6;
  v6->coef = v8->coef;
  v6->op = v8->op;
  *(_DWORD *)&v6->parent = *(_DWORD *)&v8->parent;
  var0 = v6->var0;
  v7->varId.index = v8->varId.index;
  if ( var0 != 255 )
    v7->var0 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var0,
                 srcList,
                 dstList);
  var1 = v7->var1;
  if ( var1 != 255 )
    v7->var1 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var1,
                 srcList,
                 dstList);
  var2 = v7->var2;
  if ( var2 != 255 )
    v7->var2 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var2,
                 srcList,
                 dstList);
  return v9;
}


// ========================================================================
// ?Parse@?$idRuntimeExpression@VVarId@idUserChannelExpression@@VVarContext@2@@@QAA_NPBDAAVVarContext@idUserChannelExpression@@@Z
// EA  : 0x828657E0
// RVA : 0x008657E0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse(
        idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext> *this,
        const char *exprStr,
        idUserChannelExpression::VarContext *varContext)
{
  unsigned int i; // r5
  bool v6; // r3
  int num; // r11
  int v8; // r11
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v9; // r3
  signed int v10; // r30
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v11; // r29
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v12; // r3
  signed int v13; // r30
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  va *v17; // r3
  signed int v18; // r30
  int value; // r11
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v20; // r10
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t op; // r11
  char v22; // r11
  bool v23; // zf
  int v24; // r4
  int v25; // r9
  int v26; // r8
  idEntityPtr<idEntity> *list; // r9
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode::op_t v28; // r10
  char v29; // r10
  int v30; // r4
  int v31; // r6
  int v32; // r9
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v33; // r11
  int v34; // r8
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v35; // r3
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v36; // r10
  char v37; // r29
  encounterGroupRole_t v38; // r30
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v39; // r3
  signed int v40; // r11
  int v41; // r11
  idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *p_nodeAlloc; // r11
  idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *v43; // r29
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode *v44; // r4
  int size; // r10
  int j; // r11
  idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5> *v47; // r30
  int v48; // r3
  int *p_size; // r10
  int v50; // r29
  encounterGroupRole_t v51; // r11
  int v52; // r4
  int v53; // r3
  int v54; // r30
  int k; // r11
  int m; // r11
  int n; // r11
  int v59; // [sp+8h] [-2A88h]
  int v60; // [sp+Ch] [-2A84h]
  int v61; // [sp+10h] [-2A80h]
  int v62; // [sp+14h] [-2A7Ch]
  int v63; // [sp+18h] [-2A78h]
  int v64; // [sp+1Ch] [-2A74h]
  signed int v65; // [sp+50h] [-2A40h] BYREF
  encounterGroupRole_t v66[3]; // [sp+54h] [-2A3Ch] BYREF
  idToken v67; // [sp+60h] [-2A30h] BYREF
  idToken v68; // [sp+B0h] [-29E0h] BYREF
  idToken v69; // [sp+100h] [-2990h] BYREF
  idLexer v70; // [sp+150h] [-2940h] BYREF
  idList<idEntityPtr<idEntity>,58> v71; // [sp+1E0h] [-28B0h] BYREF
  int v72; // [sp+1F0h] [-28A0h] BYREF
  idList<idEntityPtr<idEntity>,58> v73; // [sp+5F0h] [-24A0h] BYREF
  int v74; // [sp+600h] [-2490h] BYREF
  idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253> v75; // [sp+A00h] [-2090h] BYREF
  va v76; // [sp+19E0h] [-10B0h] BYREF

  idLexer::idLexer(this: &v70, flags_: 48);
  for ( i = 0; exprStr[i] != 0; ++i )
    ;
  idLexer::LoadMemory(this: &v70, ptr: exprStr, length_: i, name: "idRuntimeExpression::Parse");
  this->root = 255;
  idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253>::idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253>(this: &v75);
  *(_QWORD *)&v73.num = 253;
  v73.list = (idEntityPtr<idEntity> *)&v74;
  *(_DWORD *)&v73.granularity = 66817;
  *(_QWORD *)&v71.num = 253;
  v71.list = (idEntityPtr<idEntity> *)&v72;
  *(_DWORD *)&v71.granularity = 66817;
  v67.len = 0;
  v67.baseBuffer[0] = 0;
  v67.intvalue = 0;
  v67.allocedAndFlag = 20;
  v67.data = v67.baseBuffer;
  memset(&v67.whiteSpaceStart_p, 0, 12);
  v67.floatvalue = -3.4028235e38;
  v68.floatvalue = -3.4028235e38;
  v68.allocedAndFlag = 20;
  v68.data = v68.baseBuffer;
  v68.len = 0;
  v68.baseBuffer[0] = 0;
  v68.intvalue = 0;
  memset(&v68.whiteSpaceStart_p, 0, 12);
  while ( 1 )
  {
    v6 = idLexer::ReadToken(this: &v70, token: &v67);
    num = v71.num;
    if ( !v6 )
      break;
    if ( v71.num > 251 || (v8 = v73.num, v73.num > 251) || v75.num > 251 )
    {
      idLib::Error(fmt: "Expression: to many nodes, max is %d\n", 253);
      break;
    }
    switch ( v67.type )
    {
      case 3:
        v9 = idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Alloc(this: &v75);
        v10 = v9 - v75.list;
        v65 = v9 - v75.list;
        v11 = &v75.list[v10];
        v11->coef = idToken::GetFloatValue(this: &v67);
        v75.list[v10].op = OP_VAL;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v71,
          obj: (const encounterGroupRole_t *)&v65);
        break;
      case 4:
        v12 = idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Alloc(this: &v75);
        v69.floatvalue = -3.4028235e38;
        v69.allocedAndFlag = 20;
        v69.data = v69.baseBuffer;
        v69.len = 0;
        v13 = v12 - v75.list;
        v69.baseBuffer[0] = 0;
        v69.intvalue = 0;
        memset(&v69.whiteSpaceStart_p, 0, 12);
        v65 = v13;
        if ( idLexer::PeekTokenType(this: &v70, type: 5, subtype: 44, token: &v69) )
        {
          if ( idStr::Cmp(s1: v67.data, s2: "max") != 0 )
          {
            if ( idStr::Cmp(s1: v67.data, s2: "min") != 0 )
            {
              if ( idStr::Cmp(s1: v67.data, s2: "lerp") != 0 )
              {
                if ( idStr::Cmp(s1: v67.data, s2: "clamp") != 0 )
                {
                  HIDWORD(v16) = v67.data;
                  v17 = va::va(
                          this: &v76,
                          fmt: "unknown function %s",
                          a3: v16,
                          a4: v15,
                          a5: v14,
                          a6: v59,
                          a7: v60,
                          a8: v61,
                          a9: v62,
                          a10: v63,
                          a11: v64);
                  idLexer::Error(this: &v70, str: v17->buffer);
                }
                else
                {
                  v75.list[v13].op = OP_CLAMP;
                }
              }
              else
              {
                v75.list[v13].op = OP_LERP;
              }
            }
            else
            {
              v75.list[v13].op = OP_MIN;
            }
          }
          else
          {
            v75.list[v13].op = OP_MAX;
          }
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v73,
            obj: (const encounterGroupRole_t *)&v65);
        }
        else
        {
          v18 = v13;
          if ( (unsigned __int8)idUserChannelExpression::VarContext::LookUpVar(
                                  this: varContext,
                                  name: v67.data,
                                  resId: &v75.list[v18].varId) == 0 )
            idLexer::Error(this: &v70, str: "unknown variable '%s'", v67.data);
          v75.list[v18].op = OP_VAR;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v71,
            obj: (const encounterGroupRole_t *)&v65);
        }
        idStr::FreeData(this: &v69);
        break;
      case 5:
        switch ( v67.subtype )
        {
          case ',':
            v65 = 254;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v73,
              obj: (const encounterGroupRole_t *)&v65);
            goto LABEL_96;
          case '-':
            if ( v73.num <= 0 )
            {
              idLexer::Error(this: &v70, str: "found ')' without a matching '('");
              goto LABEL_32;
            }
            while ( v73.list[v8 - 1].spawnId.value != 254 )
            {
              v65 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                      opStack: &v73,
                      varStack: &v71,
                      src: &v70,
                      nodeList: &v75);
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v71,
                obj: (const encounterGroupRole_t *)&v65);
LABEL_32:
              v8 = v73.num;
            }
            idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v73, index: v8 - 1);
            if ( v73.num > 0 )
            {
              value = v73.list[v73.num - 1].spawnId.value;
              if ( value != 254 )
              {
                v20 = &v75.list[value];
                op = v20->op;
                if ( op == OP_MAX || op == OP_MIN || op == OP_LERP || (v23 = op != OP_CLAMP, v22 = 0, !v23) )
                  v22 = 1;
                if ( v22 != 0 )
                {
                  v24 = v71.num - 1;
                  v25 = v71.num - 1;
                  if ( v20->var0 == 255 )
                  {
                    v20->var0 = v71.list[v25].spawnId.value;
                  }
                  else
                  {
                    v26 = v71.list[v25].spawnId.value;
                    if ( v20->var1 == 255 )
                      v20->var1 = v26;
                    else
                      v20->var2 = v26;
                  }
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v71, index: v24);
                  v65 = v73.list[v73.num - 1].spawnId.value;
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v73, index: v73.num - 1);
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&v71,
                    obj: (const encounterGroupRole_t *)&v65);
                }
              }
            }
            break;
          case '(':
            while ( 1 )
            {
              if ( v8 < 2 )
              {
                idLexer::Error(this: &v70, str: "syntax error near ','");
                v8 = v73.num;
              }
              list = v73.list;
              if ( v73.list[v8 - 1].spawnId.value == 254 )
                break;
              v65 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                      opStack: &v73,
                      varStack: &v71,
                      src: &v70,
                      nodeList: &v75);
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v71,
                obj: (const encounterGroupRole_t *)&v65);
              v8 = v73.num;
            }
            v28 = v75.list[v73.list[v8 - 2].spawnId.value].op;
            if ( v28 == OP_MAX || v28 == OP_MIN || v28 == OP_LERP || (v23 = v28 != OP_CLAMP, v29 = 0, !v23) )
              v29 = 1;
            if ( v29 == 0 )
            {
              idLexer::Error(this: &v70, str: "syntax error near ',' comma outside of function call");
              v8 = v73.num;
              list = v73.list;
            }
            v30 = v71.num - 1;
            v31 = list[v8 - 2].spawnId.value;
            v32 = v71.num - 1;
            v33 = &v75.list[v31];
            if ( v33->var0 == 255 )
            {
              v33->var0 = v71.list[v32].spawnId.value;
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v71, index: v30);
            }
            else
            {
              v34 = v71.list[v32].spawnId.value;
              if ( v33->var1 == 255 )
                v33->var1 = v34;
              else
                v33->var2 = v34;
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v71, index: v30);
            }
            break;
          default:
            v35 = idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Alloc(this: &v75);
            v36 = v75.list;
            v37 = 0;
            v38 = v35 - v75.list;
            v66[0] = v38;
            if ( v68.len != 0
              && (v68.type != 5
               || v68.subtype != 31
               && v68.subtype != 30
               && v68.subtype != 27
               && v68.subtype != 28
               && v68.subtype != 44
               && v68.subtype != 40) )
            {
              goto _M222383;
            }
            if ( v67.subtype == 31 )
            {
              v37 = 1;
              v75.list[v38].op = OP_SUB;
LABEL_88:
              if ( v37 != 0 )
              {
                v39 = idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Alloc(this: &v75);
                v65 = v39 - v75.list;
                v40 = v65;
                v75.list[v40].op = OP_VAL;
                v75.list[v40].coef = -1.0;
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&v71,
                  obj: (const encounterGroupRole_t *)&v65);
                v75.list[v38].op = OP_MUL;
              }
              else
              {
                while ( v73.num != 0 )
                {
                  v41 = v73.list[v73.num - 1].spawnId.value;
                  if ( v41 == 254 || v75.list[v41].op >= v75.list[v38].op )
                    break;
                  v65 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                          opStack: &v73,
                          varStack: &v71,
                          src: &v70,
                          nodeList: &v75);
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&v71,
                    obj: (const encounterGroupRole_t *)&v65);
                }
              }
              idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v73, obj: v66);
              goto LABEL_96;
            }
            if ( v67.subtype != 30 )
            {
              idLexer::Error(this: &v70, str: "invalid unary operator '%s'", v67.data);
              v36 = v75.list;
_M222383:
              if ( v67.subtype != 30 )
              {
                switch ( v67.subtype )
                {
                  case 0x1F:
                    v36[v38].op = OP_SUB;
                    break;
                  case 0x1B:
                    v36[v38].op = OP_MUL;
                    break;
                  case 0x1C:
                    v36[v38].op = OP_DIV;
                    break;
                  default:
                    idLexer::Error(this: &v70, str: "unsupported or unknown operator '%s'", v67.data);
                    break;
                }
                goto LABEL_88;
              }
            }
            v36[v38].op = OP_ADD;
            goto LABEL_88;
        }
        break;
      default:
        idLexer::Error(this: &v70, str: "unknown token type '%s'", v67.data);
        break;
    }
LABEL_96:
    idToken::operator=(this: &v68, __that: &v67);
  }
  if ( num > 251 )
    idLib::Error(fmt: "Expression: to many nodes, max is %d\n", 253);
  while ( v73.num != 0 )
  {
    v66[0] = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse_::_2_::local_t::PopOp(
               opStack: &v73,
               varStack: &v71,
               src: &v70,
               nodeList: &v75);
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v71, obj: v66);
  }
  if ( v71.num == 1 )
    this->root = v71.list->spawnId.value;
  else
    idLexer::Error(this: &v70, str: "Wrong number of arguments remaining on stack");
  idStr::FreeData(this: &v68);
  idStr::FreeData(this: &v67);
  p_nodeAlloc = &this->nodeAlloc;
  v43 = &this->nodeAlloc;
  if ( this->nodeAlloc.listStatic == 0 || this->nodeAlloc.listStatic == 2 )
  {
    v44 = p_nodeAlloc->list;
    if ( p_nodeAlloc->list != nullptr )
    {
      size = this->nodeAlloc.size;
      for ( j = 0; j < size; ++j )
        ;
      idMem::Free(this: &mem, ptr: v44, align: ALIGN_16);
      v43->list = nullptr;
      this->nodeAlloc.size = 0;
    }
    else
    {
      v43->list = nullptr;
      this->nodeAlloc.size = 0;
    }
  }
  this->nodeAlloc.num = 0;
  v47 = &this->nodeAlloc;
  v48 = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
          nodeIndex: this->root,
          srcList: &v75);
  p_size = &this->nodeAlloc.size;
  v50 = v48;
  if ( this->nodeAlloc.size < 0 )
  {
    if ( this->nodeAlloc.listStatic == 0 || this->nodeAlloc.listStatic == 2 )
    {
      if ( v47->list != nullptr )
        idMem::Free(this: &mem, ptr: v47->list, align: ALIGN_16);
      p_size = &this->nodeAlloc.size;
      v47->list = nullptr;
      this->nodeAlloc.size = 0;
    }
    this->nodeAlloc.num = 0;
  }
  v52 = v75.num - v50;
  v53 = __CFADD__(-*p_size, *p_size ^ 0x80000000) ? 0 : *p_size;
  v66[0] = *p_size;
  v51 = v66[0];
  this->nodeAlloc.num = v53;
  if ( v52 > v51 )
    idList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,5>::Resize(
      this: &this->nodeAlloc,
      newsize: v52);
  this->root = _idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: this->root,
                 srcList: &v75,
                 dstList: &this->nodeAlloc);
  idLib::Printf(fmt: "removed %d of %d nodes\n", v50, v75.num);
  v54 = this->root - 255 - (this->root - 256 + (this->root == 255));
  if ( v71.listStatic == 0 || v71.listStatic == 2 )
  {
    if ( v71.list != nullptr )
    {
      for ( k = 0; k < v71.size; ++k )
        ;
      idMem::Free(this: &mem, ptr: v71.list, align: ALIGN_16);
    }
    v71.list = nullptr;
    v71.size = 0;
  }
  v71.num = 0;
  if ( v73.listStatic == 0 || v73.listStatic == 2 )
  {
    if ( v73.list != nullptr )
    {
      for ( m = 0; m < v73.size; ++m )
        ;
      idMem::Free(this: &mem, ptr: v73.list, align: ALIGN_16);
    }
    v73.list = nullptr;
    v73.size = 0;
  }
  v73.num = 0;
  if ( v75.listStatic == 0 || v75.listStatic == 2 )
  {
    if ( v75.list != nullptr )
    {
      for ( n = 0; n < v75.size; ++n )
        ;
      idMem::Free(this: &mem, ptr: v75.list, align: ALIGN_16);
    }
    v75.list = nullptr;
    v75.size = 0;
  }
  v75.num = 0;
  idLexer::~idLexer(this: &v70);
  return v54;
}


// ========================================================================
// $M222433_1
// EA  : 0x82866488
// RVA : 0x00866488
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void *_M222433_1()
{
  int v0; // r12

  idLib::Warning(
    fmt: "idRuntimeExpression::Parse - %s on expression %s",
    idException::error,
    *(const char **)(v0 - 10896 + 10924));
  return &_LN77_2;
}


// ========================================================================
// $LN484
// EA  : 0x828664C8
// RVA : 0x008664C8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _LN484()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 10896 + 336));
}


// ========================================================================
// __unwind$221342
// EA  : 0x828664F0
// RVA : 0x008664F0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221342()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 10896 + 2560));
}


// ========================================================================
// __unwind$221343
// EA  : 0x82866518
// RVA : 0x00866518
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221343()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 10896 + 1520));
}


// ========================================================================
// __unwind$221344
// EA  : 0x82866540
// RVA : 0x00866540
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221344()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 10896 + 480));
}


// ========================================================================
// __unwind$221345
// EA  : 0x82866568
// RVA : 0x00866568
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221345()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10896 + 96));
}


// ========================================================================
// __unwind$221346
// EA  : 0x82866590
// RVA : 0x00866590
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221346()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10896 + 176));
}


// ========================================================================
// __unwind$221347
// EA  : 0x828665B8
// RVA : 0x008665B8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_221347()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10896 + 256));
}


// ========================================================================
// `idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse'::`2'::local_t::PopOp
// EA  : 0x82F7DBD0
// RVA : 0x00F7DBD0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse_::_2_::local_t::PopOp(
        idList<idEntityPtr<idEntity>,58> *opStack,
        idList<idEntityPtr<idEntity>,58> *varStack,
        idLexer *src,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *nodeList)
{
  int v6; // r27
  int value; // r30
  int v9; // r29
  int v10; // r27
  idList<idEntityPtr<idEntity>,58> *v11; // r3
  int v12; // r31

  v6 = opStack->num - 1;
  value = opStack->list[v6].spawnId.value;
  if ( value == 254 )
    idLexer::Error(this: src, str: "syntax error, unclosed parentheses");
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: opStack, index: v6);
  v9 = varStack->num - 1;
  v10 = varStack->list[v9].spawnId.value;
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: varStack, index: v9);
  v11 = varStack;
  v12 = varStack->list[v9 - 1].spawnId.value;
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: v11, index: v9 - 1);
  nodeList->list[value].var0 = v12;
  nodeList->list[value].var1 = v10;
  return value;
}


// ========================================================================
// ??0ExpNode@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@QAA@XZ
// EA  : 0x82F7DCC0
// RVA : 0x00F7DCC0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *__fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::ExpNode(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *this)
{
  this->parent = -1;
  this->coef = 1.0;
  this->op = OP_NONE;
  this->var0 = -1;
  this->var1 = -1;
  this->var2 = -1;
  this->varId.name.allocedAndFlag = 20;
  this->varId.name.data = this->varId.name.baseBuffer;
  this->varId.name.len = 0;
  this->varId.name.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?PrintTree@ExpNode@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@QAA?AVidStr@@AAV?$idList@VExpNode@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@$04@@@Z
// EA  : 0x82F7DFF8
// RVA : 0x00F7DFF8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *__fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::PrintTree(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *this,
        idStr *result,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *nodeList)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  double v13; // fp1
  va *v14; // r3
  char *data; // r11
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  char *v20; // r4
  char *v21; // r4
  const idStr *v22; // r3
  const idStr *v23; // r3
  const idStr *v24; // r3
  int v26; // [sp+8h] [-1108h]
  int v27; // [sp+8h] [-1108h]
  int v28; // [sp+Ch] [-1104h]
  int v29; // [sp+Ch] [-1104h]
  int v30; // [sp+10h] [-1100h]
  int v31; // [sp+10h] [-1100h]
  int v32; // [sp+14h] [-10FCh]
  int v33; // [sp+14h] [-10FCh]
  int v34; // [sp+18h] [-10F8h]
  int v35; // [sp+18h] [-10F8h]
  int v36; // [sp+1Ch] [-10F4h]
  int v37; // [sp+1Ch] [-10F4h]
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode v38; // [sp+60h] [-10B0h] BYREF
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode v39; // [sp+A0h] [-1070h] BYREF
  va v40; // [sp+E0h] [-1030h] BYREF

  idStr::idStr((idStr *)this, text: &byte_8200D768);
  HIDWORD(v6) = 1;
  LODWORD(v7) = nodeList->list;
  HIDWORD(v7) = 48;
  LODWORD(v8) = "ound traces";
  HIDWORD(v8) = ((char *)result - (char *)nodeList->list) / 48;
  v9 = va::va(this: &v40, fmt: "[%d]", a3: v8, a4: v7, a5: v6, a6: v26, a7: v28, a8: v30, a9: v32, a10: v34, a11: v36);
  idStr::Append((idStr *)this, text: v9);
  v13 = *(float *)&result->len;
  if ( v13 != 1.0 )
  {
    HIDWORD(v12) = LODWORD(v13);
    v14 = va::va(
            this: &v40,
            fmt: "{%f}",
            a3: v12,
            a4: v11,
            a5: v10,
            a6: v27,
            a7: v29,
            a8: v31,
            a9: v33,
            a10: v35,
            a11: v37);
    idStr::Append((idStr *)this, text: v14);
  }
  data = result->data;
  if ( (int)data > 254 )
  {
    if ( data != (char *)255 )
    {
LABEL_10:
      switch ( (unsigned int)data )
      {
        case 0u:
          v21 = "none";
          break;
        case 3u:
          v21 = "*";
          break;
        case 4u:
          v21 = "/";
          break;
        case 5u:
          v21 = "max";
          break;
        case 6u:
          v21 = "min";
          break;
        case 7u:
          v21 = "lerp";
          break;
        case 8u:
          v21 = "clamp";
          break;
        case 9u:
          v21 = "-";
          break;
        case 0xAu:
          v21 = "+";
          break;
        default:
          v21 = "invalid";
          break;
      }
      idStr::Append((idStr *)this, text: v21);
      idStr::Append((idStr *)this, text: "(");
      if ( BYTE1(result->allocedAndFlag) != 255 )
      {
        idStr::Append((idStr *)this, text: &byte_8200D768);
        v22 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::PrintTree(
                this: &v38,
                result: (idStr *)((char *)nodeList->list
                        + 16 * BYTE1(result->allocedAndFlag)
                        + 16 * __ROL4__(BYTE1(result->allocedAndFlag), 1)),
                nodeList);
        idStr::Append((idStr *)this, text: v22);
        idStr::FreeData(this: (idStr *)&v38);
      }
      if ( BYTE2(result->allocedAndFlag) != 255 )
      {
        idStr::Append((idStr *)this, text: ", ");
        v23 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::PrintTree(
                this: (idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *)&v38.varId.name.baseBuffer[8],
                result: (idStr *)((char *)nodeList->list
                        + 16 * BYTE2(result->allocedAndFlag)
                        + 16 * __ROL4__(BYTE2(result->allocedAndFlag), 1)),
                nodeList);
        idStr::Append((idStr *)this, text: v23);
        idStr::FreeData(this: (idStr *)&v38.varId.name.baseBuffer[8]);
      }
      if ( LOBYTE(result->allocedAndFlag) != 255 )
      {
        idStr::Append((idStr *)this, text: ", ");
        v24 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::PrintTree(
                this: &v39,
                result: (idStr *)((char *)nodeList->list
                        + 16 * LOBYTE(result->allocedAndFlag)
                        + 16 * __ROL4__(LOBYTE(result->allocedAndFlag), 1)),
                nodeList);
        idStr::Append((idStr *)this, text: v24);
        idStr::FreeData(this: (idStr *)&v39);
      }
      v20 = ")";
      goto LABEL_29;
    }
    v20 = "INVALID_INDEX";
LABEL_29:
    idStr::Append((idStr *)this, text: v20);
    return this;
  }
  if ( data == (char *)254 )
  {
    v20 = "OPEN_PAR";
    goto LABEL_29;
  }
  if ( data != (char *)1 )
  {
    if ( data == (char *)2 )
    {
      HIDWORD(v16) = TestExpression::VarId::GetStr(
                       this: (TestExpression::VarId *)&v39.varId.name.baseBuffer[8],
                       result: (idStr *)result->baseBuffer)->name.data;
      v19 = va::va(
              this: &v40,
              fmt: "%s",
              a3: v16,
              a4: v18,
              a5: v17,
              a6: v27,
              a7: v29,
              a8: v31,
              a9: v33,
              a10: v35,
              a11: v37);
      idStr::Append((idStr *)this, text: v19);
      idStr::FreeData(this: (idStr *)&v39.varId.name.baseBuffer[8]);
      return this;
    }
    goto LABEL_10;
  }
  return this;
}


// ========================================================================
// __unwind$113417
// EA  : 0x82F7E304
// RVA : 0x00F7E304
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113417()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4368;
  if ( (*(_DWORD *)(v0 - 4368 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 4388));
  }
}


// ========================================================================
// __unwind$113420
// EA  : 0x82F7E348
// RVA : 0x00F7E348
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 192));
}


// ========================================================================
// __unwind$113421
// EA  : 0x82F7E370
// RVA : 0x00F7E370
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 96));
}


// ========================================================================
// __unwind$113422
// EA  : 0x82F7E398
// RVA : 0x00F7E398
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 128));
}


// ========================================================================
// __unwind$113423
// EA  : 0x82F7E3C0
// RVA : 0x00F7E3C0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 160));
}


// ========================================================================
// ?Eval@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@QAAMAAVVarContext@TestExpression@@@Z
// EA  : 0x82F7E4B8
// RVA : 0x00F7E4B8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

float __fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Eval(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *this,
        TestExpression::VarContext *varContext)
{
  double v4; // fp1
  int v5; // r30
  __int64 v6; // r6
  char v7; // r29
  __int64 v8; // r10
  int v9; // r28
  __int64 v10; // r8
  int v11; // r27
  float v12; // r11
  bool v13; // zf
  double v15; // fp30
  double v16; // fp29
  __int64 v17; // r4
  __int64 v20; // r4
  double v21; // fp31
  int v23; // [sp+8h] [-8E8h]
  int v24; // [sp+Ch] [-8E4h]
  int v25; // [sp+10h] [-8E0h]
  int v26; // [sp+14h] [-8DCh]
  float v27[4]; // [sp+50h] [-8A0h] BYREF
  idList<float,116> v28; // [sp+60h] [-890h] BYREF
  int v29; // [sp+70h] [-880h] BYREF
  idList<enum encounterGroupRole_t,5> v30; // [sp+470h] [-480h] BYREF
  int v31; // [sp+480h] [-470h] BYREF

  if ( this->root == 255 )
  {
    v4 = 0.0;
    return *((float *)&v4 + 1);
  }
  v28.granularity = 1;
  v28.size = 253;
  v28.num = 0;
  v28.memTag = 5;
  v28.list = (float *)&v29;
  v28.listStatic = 1;
  v30.size = 253;
  v30.num = 0;
  v30.granularity = 1;
  v30.list = (encounterGroupRole_t *)&v31;
  v30.memTag = 5;
  v30.listStatic = 1;
  v5 = 255;
  idList<idAnimWebBlendTree *,5>::Append(this: &v30, obj: (encounterGroupRole_t *)this);
  do
  {
    v7 = 0;
    HIDWORD(v8) = v30.list;
    LODWORD(v8) = this->nodeAlloc.list;
    LODWORD(v10) = &v30.list[v30.num];
    v9 = *(_DWORD *)(v10 - 4);
    HIDWORD(v10) = 3 * v9;
    v11 = 48 * v9 + v8;
    LODWORD(v12) = *(unsigned __int8 *)(v11 + 9);
    if ( v5 != 255 )
    {
      v13 = v5 == LODWORD(v12);
      LODWORD(v12) = *(unsigned __int8 *)(v11 + 10);
      if ( !v13 )
      {
        if ( v5 != LODWORD(v12) )
          goto LABEL_11;
        LODWORD(v12) = *(unsigned __int8 *)(v11 + 11);
      }
    }
    if ( LODWORD(v12) == 255 )
    {
      v7 = 1;
    }
    else
    {
      v27[0] = v12;
      idList<idAnimWebBlendTree *,5>::Append(this: &v30, obj: (encounterGroupRole_t *)v27);
    }
LABEL_11:
    if ( v7 != 0 )
    {
      LODWORD(v8) = v30.num - 1;
      if ( v30.num - 1 >= 0 && (int)v8 < v30.num )
        --v30.num;
      v5 = v9;
      _FP31 = 0.0;
      v15 = 0.0;
      v16 = 0.0;
      if ( *(unsigned __int8 *)(v11 + 11) != 255 )
      {
        v16 = v28.list[v28.num - 1];
        idList<float,5>::RemoveIndex(this: &v28, index: v28.num - 1);
      }
      if ( *(unsigned __int8 *)(v11 + 10) != 255 )
      {
        v15 = v28.list[v28.num - 1];
        idList<float,5>::RemoveIndex(this: &v28, index: v28.num - 1);
      }
      if ( *(unsigned __int8 *)(v11 + 9) != 255 )
      {
        _FP31 = v28.list[v28.num - 1];
        idList<float,5>::RemoveIndex(this: &v28, index: v28.num - 1);
      }
      LODWORD(v17) = *(_DWORD *)(v11 + 4);
      switch ( (int)v17 )
      {
        case 1:
          _FP31 = 1.0;
          break;
        case 2:
          _FP31 = varContext->varList[*(_DWORD *)(v11 + 44)].val;
          break;
        case 3:
          _FP31 = (float)((float)v15 * (float)_FP31);
          break;
        case 4:
          _FP31 = (float)((float)_FP31 / (float)v15);
          break;
        case 5:
          _FP0 = (float)((float)_FP31 - (float)v15);
          __asm { fsel      f31, f0, f31, f30 }
          break;
        case 6:
          _FP0 = (float)((float)_FP31 - (float)v15);
          __asm { fsel      f31, f0, f30, f31 }
          break;
        case 7:
          _FP31 = (float)((float)((float)((float)v15 - (float)_FP31) * (float)v16) + (float)_FP31);
          break;
        case 8:
          if ( v16 >= _FP31 )
          {
            if ( v16 <= v15 )
              _FP31 = v16;
            else
              _FP31 = v15;
          }
          break;
        case 9:
          _FP31 = (float)((float)_FP31 - (float)v15);
          break;
        case 10:
          _FP31 = (float)((float)v15 + (float)_FP31);
          break;
        default:
          goto _LN140_2;
      }
      v27[0] = *(float *)v11 * (float)_FP31;
      idList<float,13>::Append(this: (idList<float,13> *)&v28, obj: v27);
    }
    else
    {
      v5 = 255;
    }
  }
  while ( v30.num != 0 );
  LODWORD(v20) = v28.num;
  if ( v28.num != 1 )
  {
    HIDWORD(v20) = "Stack contains incorrect number of results after eval (%d)";
    idLib::Error(fmt: v20, a2: v6, a3: v10, a4: v8, a5: v23, a6: v24, a7: v25, a8: v26);
_LN140_2:
    HIDWORD(v17) = "Unknown op in expression: %d (code error, not content)";
    idLib::Error(fmt: v17, a2: v6, a3: v10, a4: v8, a5: v23, a6: v24, a7: v25, a8: v26);
  }
  v21 = *v28.list;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v30);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v28);
  v4 = v21;
  return *((float *)&v4 + 1);
}


// ========================================================================
// $LN123_3
// EA  : 0x82F7E804
// RVA : 0x00F7E804
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _LN123_3()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2288 + 96));
}


// ========================================================================
// __unwind$113652
// EA  : 0x82F7E82C
// RVA : 0x00F7E82C
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_113652()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2288 + 1136));
}


// ========================================================================
// ?PrintExpInternal@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@AAA?AVidStr@@HAAV?$idList@VExpNode@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@$04@@@Z
// EA  : 0x82F7E8C0
// RVA : 0x00F7E8C0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *__fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::PrintExpInternal(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *this,
        idStr *result,
        int rootNode,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *nodeList)
{
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *v4; // r31

  v4 = this;
  if ( rootNode == 255 )
  {
    this->root = 0;
    this->nodeAlloc.num = 20;
    this->nodeAlloc.list = (idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *)&this->nodeAlloc.size;
    HIBYTE(this->nodeAlloc.size) = 0;
  }
  else
  {
    idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::PrintTree(
      (idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *)this,
      result: (idStr *)&nodeList->list[rootNode],
      nodeList);
    return v4;
  }
  return this;
}


// ========================================================================
// `idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize'::`2'::localOptExp::OptSubExpR
// EA  : 0x82F7E948
// RVA : 0x00F7E948
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
        int nodeIndex,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *srcList)
{
  int v3; // r29
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v4; // r31
  int var0; // r3
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::op_t op; // r6
  char *v7; // r9
  char *v8; // r11
  double v9; // fp12
  int v11; // r9
  int var1; // r11
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *list; // r10
  char *v14; // r8
  int v15; // r11
  char *v16; // r9
  double coef; // fp11
  double v18; // fp12
  double v19; // fp31

  v3 = 0;
  v4 = &srcList->list[nodeIndex];
  var0 = v4->var0;
  if ( var0 != 255 )
  {
    v3 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
           nodeIndex: var0,
           srcList);
    if ( v4->var1 != 255 )
    {
      v3 += _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
              nodeIndex: v4->var1,
              srcList);
      if ( v4->var2 != 255 )
        v3 += _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
                nodeIndex: v4->var2,
                srcList);
    }
  }
  op = v4->op;
  if ( op == OP_MUL )
  {
    v11 = v4->var0;
    if ( *((_DWORD *)&srcList->list->op + 4 * v11 + 4 * __ROL4__(v11, 1)) == 1 )
    {
      var1 = v4->var1;
      if ( *((_DWORD *)&srcList->list->op + 4 * var1 + 4 * __ROL4__(var1, 1)) != 1 )
      {
        v4->var0 = var1;
        v4->var1 = v11;
      }
    }
  }
  else if ( op != OP_DIV )
  {
    if ( op == OP_ADD || op == OP_SUB )
    {
      v7 = (char *)srcList->list + 16 * v4->var0 + 16 * __ROL4__(v4->var0, 1);
      if ( *((_DWORD *)v7 + 1) == 1 )
      {
        v8 = (char *)srcList->list + 16 * v4->var1 + 16 * __ROL4__(v4->var1, 1);
        if ( *((_DWORD *)v8 + 1) == 1 )
        {
          if ( op == OP_ADD )
            v9 = (float)(*(float *)v7 + *(float *)v8);
          else
            v9 = (float)(*(float *)v7 - *(float *)v8);
          v4->coef = (float)v9 * v4->coef;
          v4->var0 = -1;
          v4->op = OP_VAL;
          v4->var1 = -1;
          return v3 + 2;
        }
      }
    }
    return v3;
  }
  list = srcList->list;
  v14 = (char *)srcList->list + 16 * v4->var1 + 16 * __ROL4__(v4->var1, 1);
  if ( *((_DWORD *)v14 + 1) != 1 )
    return v3;
  v15 = v4->var0;
  v16 = (char *)list + 16 * v15 + 16 * __ROL4__(v15, 1);
  if ( *((_DWORD *)v16 + 1) == 1 )
  {
    if ( op == OP_MUL )
    {
      coef = *(float *)v14;
      v18 = (float)(*(float *)v16 * v4->coef);
    }
    else
    {
      coef = v4->coef;
      v18 = (float)(*(float *)v16 / *(float *)v14);
    }
    v4->coef = (float)v18 * (float)coef;
    v4->var0 = -1;
    v4->op = OP_VAL;
    v4->var1 = -1;
    return v3 + 2;
  }
  else
  {
    if ( op == OP_MUL )
      v19 = (float)(v4->coef * *(float *)v14);
    else
      v19 = (float)(v4->coef / *(float *)v14);
    idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::operator=(
      this: v4,
      __that: &list[v15]);
    v4->coef = v4->coef * (float)v19;
    return v3 + 2;
  }
}


// ========================================================================
// ?PrintExp@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@QAA?AVidStr@@XZ
// EA  : 0x82F7EC80
// RVA : 0x00F7EC80
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *__fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::PrintExp(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *this,
        idStr *result)
{
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::PrintExpInternal(
    this,
    result,
    rootNode: result->len,
    nodeList: (idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *)&result->data);
  return this;
}


// ========================================================================
// `idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize'::`3'::localCopyExp::CopyExpR
// EA  : 0x82F7EFF8
// RVA : 0x00F7EFF8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
        int srcIndex,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *srcList,
        idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *dstList)
{
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v6; // r31
  int v7; // r29
  const idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v8; // r4
  int var0; // r3
  int var1; // r3
  int var2; // r3

  v6 = idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Alloc(this: dstList);
  v8 = &srcList->list[srcIndex];
  v7 = dstList->num - 1;
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::operator=(this: v6, __that: v8);
  var0 = v6->var0;
  if ( var0 != 255 )
    v6->var0 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var0,
                 srcList,
                 dstList);
  var1 = v6->var1;
  if ( var1 != 255 )
    v6->var1 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var1,
                 srcList,
                 dstList);
  var2 = v6->var2;
  if ( var2 != 255 )
    v6->var2 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: var2,
                 srcList,
                 dstList);
  return v7;
}


// ========================================================================
// ?Parse@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@QAA_NPBDAAVVarContext@TestExpression@@@Z
// EA  : 0x82F7F0A8
// RVA : 0x00F7F0A8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

int __fastcall idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse(
        idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *this,
        const char *exprStr,
        TestExpression::VarContext *varContext)
{
  unsigned int i; // r5
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  bool v9; // r3
  int num; // r11
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v11; // r3
  int v12; // r30
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v13; // r29
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v14; // r3
  int v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  va *v19; // r3
  int v20; // r30
  int value; // r11
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v22; // r10
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::op_t op; // r11
  char v24; // r11
  bool v25; // zf
  int v26; // r4
  int v27; // r9
  int v28; // r8
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::op_t v29; // r11
  char v30; // r11
  int v31; // r4
  int v32; // r11
  int v33; // r9
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v34; // r11
  int v35; // r8
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v36; // r3
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *list; // r11
  char v38; // r29
  int v39; // r30
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *v40; // r3
  int v41; // r11
  int v42; // r11
  __int64 v43; // r4
  __int64 v44; // r4
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *v45; // r30
  void **p_list; // r11
  idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *p_nodeAlloc; // r27
  char *v48; // r28
  int size; // r29
  int j; // r30
  idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> *v51; // r29
  int v52; // r3
  int *p_size; // r11
  int v54; // r26
  int v55; // r11
  int v56; // r4
  __int64 v57; // r6
  __int64 v58; // r10
  __int64 v59; // r8
  int v60; // r30
  int k; // r11
  int m; // r11
  int v64; // [sp+8h] [-4A28h]
  int v65; // [sp+Ch] [-4A24h]
  int v66; // [sp+10h] [-4A20h]
  int v67; // [sp+14h] [-4A1Ch]
  int v68; // [sp+18h] [-4A18h]
  int v69; // [sp+1Ch] [-4A14h]
  int v70; // [sp+50h] [-49E0h] BYREF
  int v71; // [sp+54h] [-49DCh] BYREF
  const char *v72; // [sp+58h] [-49D8h]
  idToken v73; // [sp+60h] [-49D0h] BYREF
  idToken v74; // [sp+B0h] [-4980h] BYREF
  idToken v75; // [sp+100h] [-4930h] BYREF
  idLexer v76; // [sp+150h] [-48E0h] BYREF
  idList<idEntityPtr<idEntity>,58> v77; // [sp+1E0h] [-4850h] BYREF
  int v78; // [sp+1F0h] [-4840h] BYREF
  idList<idEntityPtr<idEntity>,58> v79; // [sp+5F0h] [-4440h] BYREF
  int v80; // [sp+600h] [-4430h] BYREF
  idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253> v81; // [sp+A00h] [-4030h] BYREF
  va v82; // [sp+3980h] [-10B0h] BYREF

  idLexer::idLexer(this: &v76, flags_: 48);
  for ( i = 0; exprStr[i] != 0; ++i )
    ;
  idLexer::LoadMemory(this: &v76, ptr: exprStr, length_: i, name: "idRuntimeExpression::Parse");
  this->root = 255;
  idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>::idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>(this: &v81);
  *(_QWORD *)&v79.num = 253;
  v79.list = (idEntityPtr<idEntity> *)&v80;
  *(_DWORD *)&v79.granularity = 66817;
  *(_QWORD *)&v77.num = 253;
  v77.list = (idEntityPtr<idEntity> *)&v78;
  *(_DWORD *)&v77.granularity = 66817;
  v73.len = 0;
  v73.baseBuffer[0] = 0;
  v73.intvalue = 0;
  v73.allocedAndFlag = 20;
  v73.data = v73.baseBuffer;
  memset(&v73.whiteSpaceStart_p, 0, 12);
  v73.floatvalue = -3.4028235e38;
  v74.floatvalue = -3.4028235e38;
  v74.allocedAndFlag = 20;
  v74.data = v74.baseBuffer;
  v74.len = 0;
  v74.baseBuffer[0] = 0;
  v74.intvalue = 0;
  memset(&v74.whiteSpaceStart_p, 0, 12);
  v72 = "unknown variable '%s'";
  while ( 1 )
  {
    v9 = idLexer::ReadToken(this: &v76, token: &v73);
    num = v77.num;
    if ( !v9 )
      break;
    if ( v77.num > 251 || (LODWORD(v6) = v79.num, v79.num > 251) || v81.num > 251 )
    {
      LODWORD(v43) = 253;
      HIDWORD(v43) = "Expression: to many nodes, max is %d\n";
      idLib::Error(fmt: v43, a2: v8, a3: v7, a4: v6, a5: v64, a6: v65, a7: v66, a8: v67);
      break;
    }
    switch ( v73.type )
    {
      case 3:
        v11 = idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Alloc(this: &v81);
        v70 = v11 - v81.list;
        v12 = v70;
        v13 = &v81.list[v70];
        v13->coef = idToken::GetFloatValue(this: &v73);
        v81.list[v12].op = OP_VAL;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v77,
          obj: (encounterGroupRole_t *)&v70);
        break;
      case 4:
        v14 = idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Alloc(this: &v81);
        v75.floatvalue = -3.4028235e38;
        v75.allocedAndFlag = 20;
        v75.data = v75.baseBuffer;
        v75.len = 0;
        v15 = v14 - v81.list;
        v75.baseBuffer[0] = 0;
        v75.intvalue = 0;
        memset(&v75.whiteSpaceStart_p, 0, 12);
        v70 = v15;
        if ( idLexer::PeekTokenType(this: &v76, type: 5, subtype: 44, token: &v75) )
        {
          if ( idStr::Cmp(s1: v73.data, s2: "max") != 0 )
          {
            if ( idStr::Cmp(s1: v73.data, s2: "min") != 0 )
            {
              if ( idStr::Cmp(s1: v73.data, s2: "lerp") != 0 )
              {
                if ( idStr::Cmp(s1: v73.data, s2: "clamp") != 0 )
                {
                  HIDWORD(v18) = v73.data;
                  v19 = va::va(
                          this: &v82,
                          fmt: "unknown function %s",
                          a3: v18,
                          a4: v17,
                          a5: v16,
                          a6: v64,
                          a7: v65,
                          a8: v66,
                          a9: v67,
                          a10: v68,
                          a11: v69);
                  idLexer::Error(this: &v76, str: v19->buffer);
                }
                else
                {
                  v81.list[v15].op = OP_CLAMP;
                }
              }
              else
              {
                v81.list[v15].op = OP_LERP;
              }
            }
            else
            {
              v81.list[v15].op = OP_MIN;
            }
          }
          else
          {
            v81.list[v15].op = OP_MAX;
          }
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v79,
            obj: (encounterGroupRole_t *)&v70);
        }
        else
        {
          v20 = v15;
          if ( (unsigned __int8)TestExpression::VarContext::LookUpVar(
                                  this: varContext,
                                  name: v73.data,
                                  resId: &v81.list[v20].varId) == 0 )
            idLexer::Error(this: &v76, str: v72, v73.data);
          v81.list[v20].op = OP_VAR;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v77,
            obj: (encounterGroupRole_t *)&v70);
        }
        idStr::FreeData(this: &v75);
        break;
      case 5:
        switch ( v73.subtype )
        {
          case ',':
            v70 = 254;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v79,
              obj: (encounterGroupRole_t *)&v70);
            goto LABEL_96;
          case '-':
            if ( v79.num <= 0 )
            {
              idLexer::Error(this: &v76, str: "found ')' without a matching '('");
              goto LABEL_32;
            }
            while ( v79.list[v6 - 1].spawnId.value != 254 )
            {
              v70 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                      opStack: &v79,
                      varStack: &v77,
                      src: &v76,
                      nodeList: &v81);
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v77,
                obj: (encounterGroupRole_t *)&v70);
LABEL_32:
              LODWORD(v6) = v79.num;
            }
            idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v79, index: v6 - 1);
            if ( v79.num > 0 )
            {
              value = v79.list[v79.num - 1].spawnId.value;
              if ( value != 254 )
              {
                v22 = &v81.list[value];
                op = v22->op;
                if ( op == OP_MAX || op == OP_MIN || op == OP_LERP || (v25 = op != OP_CLAMP, v24 = 0, !v25) )
                  v24 = 1;
                if ( v24 != 0 )
                {
                  v26 = v77.num - 1;
                  v27 = v77.num - 1;
                  if ( v22->var0 == 255 )
                  {
                    v22->var0 = v77.list[v27].spawnId.value;
                  }
                  else
                  {
                    v28 = v77.list[v27].spawnId.value;
                    if ( v22->var1 == 255 )
                      v22->var1 = v28;
                    else
                      v22->var2 = v28;
                  }
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v77, index: v26);
                  v70 = v79.list[v79.num - 1].spawnId.value;
                  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v79, index: v79.num - 1);
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&v77,
                    obj: (encounterGroupRole_t *)&v70);
                }
              }
            }
            break;
          case '(':
            while ( 1 )
            {
              if ( (int)v6 < 2 )
              {
                idLexer::Error(this: &v76, str: "syntax error near ','");
                LODWORD(v6) = v79.num;
              }
              HIDWORD(v6) = v79.list;
              if ( v79.list[v6 - 1].spawnId.value == 254 )
                break;
              v70 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                      opStack: &v79,
                      varStack: &v77,
                      src: &v76,
                      nodeList: &v81);
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v77,
                obj: (encounterGroupRole_t *)&v70);
              LODWORD(v6) = v79.num;
            }
            v29 = v81.list[v79.list[v6 - 2].spawnId.value].op;
            if ( v29 == OP_MAX || v29 == OP_MIN || v29 == OP_LERP || (v25 = v29 != OP_CLAMP, v30 = 0, !v25) )
              v30 = 1;
            if ( v30 == 0 )
            {
              idLexer::Error(this: &v76, str: "syntax error near ',' comma outside of function call");
              v6 = *(_QWORD *)&v79.list;
            }
            v31 = v77.num - 1;
            v32 = *(_DWORD *)(4 * (v6 - 2) + HIDWORD(v6));
            v33 = v77.num - 1;
            v34 = &v81.list[v32];
            if ( v34->var0 == 255 )
            {
              v34->var0 = v77.list[v33].spawnId.value;
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v77, index: v31);
            }
            else
            {
              v35 = v77.list[v33].spawnId.value;
              if ( v34->var1 == 255 )
                v34->var1 = v35;
              else
                v34->var2 = v35;
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: &v77, index: v31);
            }
            break;
          default:
            v36 = idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Alloc(this: &v81);
            list = v81.list;
            v38 = 0;
            v39 = v36 - v81.list;
            v71 = v39;
            if ( v74.len == 0
              || v74.type == 5
              && (v74.subtype == 31
               || v74.subtype == 30
               || v74.subtype == 27
               || v74.subtype == 28
               || v74.subtype == 44
               || v74.subtype == 40) )
            {
              if ( v73.subtype == 31 )
              {
                v38 = 1;
                goto LABEL_82;
              }
              if ( v73.subtype != 30 )
              {
                idLexer::Error(this: &v76, str: "invalid unary operator '%s'", v73.data);
                list = v81.list;
                goto _M115651;
              }
LABEL_80:
              list[v39].op = OP_ADD;
            }
            else
            {
_M115651:
              switch ( v73.subtype )
              {
                case 0x1E:
                  goto LABEL_80;
                case 0x1F:
LABEL_82:
                  list[v39].op = OP_SUB;
                  break;
                case 0x1B:
                  list[v39].op = OP_MUL;
                  break;
                case 0x1C:
                  list[v39].op = OP_DIV;
                  break;
                default:
                  idLexer::Error(this: &v76, str: "unsupported or unknown operator '%s'", v73.data);
                  break;
              }
            }
            if ( v38 != 0 )
            {
              v40 = idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Alloc(this: &v81);
              v70 = v40 - v81.list;
              v41 = v70;
              v81.list[v41].op = OP_VAL;
              v81.list[v41].coef = -1.0;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v77,
                obj: (encounterGroupRole_t *)&v70);
              v81.list[v39].op = OP_MUL;
            }
            else
            {
              while ( v79.num != 0 )
              {
                v42 = v79.list[v79.num - 1].spawnId.value;
                if ( v42 == 254 || v81.list[v42].op >= v81.list[v39].op )
                  break;
                v70 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse_::_2_::local_t::PopOp(
                        opStack: &v79,
                        varStack: &v77,
                        src: &v76,
                        nodeList: &v81);
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&v77,
                  obj: (encounterGroupRole_t *)&v70);
              }
            }
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v79,
              obj: (encounterGroupRole_t *)&v71);
            goto LABEL_96;
        }
        break;
      default:
        idLexer::Error(this: &v76, str: "unknown token type '%s'", v73.data);
        break;
    }
LABEL_96:
    idToken::operator=(this: &v74, __that: &v73);
  }
  if ( num > 251 )
  {
    LODWORD(v44) = 253;
    HIDWORD(v44) = "Expression: to many nodes, max is %d\n";
    idLib::Error(fmt: v44, a2: v8, a3: v7, a4: v6, a5: v64, a6: v65, a7: v66, a8: v67);
  }
  while ( v79.num != 0 )
  {
    v71 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse_::_2_::local_t::PopOp(
            opStack: &v79,
            varStack: &v77,
            src: &v76,
            nodeList: &v81);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&v77,
      obj: (encounterGroupRole_t *)&v71);
  }
  if ( v77.num == 1 )
  {
    v45 = this;
    this->root = v77.list->spawnId.value;
  }
  else
  {
    idLexer::Error(this: &v76, str: "Wrong number of arguments remaining on stack");
    v45 = this;
  }
  idStr::FreeData(this: &v74);
  idStr::FreeData(this: &v73);
  p_list = (void **)&v45->nodeAlloc.list;
  p_nodeAlloc = &v45->nodeAlloc;
  if ( v45->nodeAlloc.listStatic == 0 || v45->nodeAlloc.listStatic == 2 )
  {
    v48 = (char *)*p_list;
    if ( *p_list != nullptr )
    {
      size = v45->nodeAlloc.size;
      for ( j = 0; j < size; ++j )
        idStr::FreeData(this: (idStr *)&v48[48 * j + 12]);
      idMem::Free(this: &mem, ptr: v48, align: ALIGN_16);
      p_nodeAlloc->list = nullptr;
      p_nodeAlloc->size = 0;
    }
    else
    {
      p_nodeAlloc->list = nullptr;
      v45->nodeAlloc.size = 0;
    }
  }
  p_nodeAlloc->num = 0;
  v51 = &this->nodeAlloc;
  v52 = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_2_::localOptExp::OptSubExpR(
          nodeIndex: this->root,
          srcList: &v81);
  p_size = &this->nodeAlloc.size;
  v54 = v52;
  if ( this->nodeAlloc.size < 0 )
  {
    if ( this->nodeAlloc.listStatic == 0 || this->nodeAlloc.listStatic == 2 )
    {
      if ( v51->list != nullptr )
        idMem::Free(this: &mem, ptr: v51->list, align: ALIGN_16);
      p_size = &this->nodeAlloc.size;
      v51->list = nullptr;
      this->nodeAlloc.size = 0;
    }
    this->nodeAlloc.num = 0;
  }
  v55 = *p_size;
  v56 = v81.num - v54;
  v71 = v55;
  this->nodeAlloc.num = __CFADD__(-v55, v55 ^ 0x80000000) ? 0 : v55;
  if ( v56 > v55 )
    idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Resize(
      this: &this->nodeAlloc,
      newsize: v56);
  this->root = _idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Optimize_::_3_::localCopyExp::CopyExpR(
                 srcIndex: this->root,
                 srcList: &v81,
                 dstList: &this->nodeAlloc);
  HIDWORD(v57) = v81.num;
  idLib::Printf(
    fmt: __SPAIR64__("removed %d of %d nodes\n", v54),
    a2: v57,
    a3: v59,
    a4: v58,
    a5: v64,
    a6: v65,
    a7: v66,
    a8: v67);
  v60 = this->root - 255 - (this->root - 256 + (this->root == 255));
  if ( v77.listStatic == 0 || v77.listStatic == 2 )
  {
    if ( v77.list != nullptr )
    {
      for ( k = 0; k < v77.size; ++k )
        ;
      idMem::Free(this: &mem, ptr: v77.list, align: ALIGN_16);
    }
    v77.list = nullptr;
    v77.size = 0;
  }
  v77.num = 0;
  if ( v79.listStatic == 0 || v79.listStatic == 2 )
  {
    if ( v79.list != nullptr )
    {
      for ( m = 0; m < v79.size; ++m )
        ;
      idMem::Free(this: &mem, ptr: v79.list, align: ALIGN_16);
    }
    v79.list = nullptr;
    v79.size = 0;
  }
  v79.num = 0;
  idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>::~idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>(this: &v81);
  idLexer::~idLexer(this: &v76);
  return v60;
}


// ========================================================================
// $M115701
// EA  : 0x82F7FDC8
// RVA : 0x00F7FDC8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void *__fastcall _M115701(int a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // r12
  __int64 v6; // r4
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  LODWORD(a5) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(a3) = *(_DWORD *)(v5 - 18992 + 19020);
  LODWORD(v6) = idException::error;
  HIDWORD(v6) = "idRuntimeExpression::Parse - %s on expression %s";
  idLib::Warning(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v8, a6: v9, a7: v10, a8: v11);
  return &_LN77_6;
}


// ========================================================================
// $LN506
// EA  : 0x82F7FE08
// RVA : 0x00F7FE08
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _LN506()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 18992 + 336));
}


// ========================================================================
// __unwind$114434
// EA  : 0x82F7FE30
// RVA : 0x00F7FE30
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114434()
{
  int v0; // r12

  idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>::~idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>(this: (idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253> *)(v0 - 18992 + 2560));
}


// ========================================================================
// __unwind$114435
// EA  : 0x82F7FE58
// RVA : 0x00F7FE58
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114435()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 18992 + 1520));
}


// ========================================================================
// __unwind$114436
// EA  : 0x82F7FE80
// RVA : 0x00F7FE80
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 18992 + 480));
}


// ========================================================================
// __unwind$114437
// EA  : 0x82F7FEA8
// RVA : 0x00F7FEA8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114437()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 18992 + 96));
}


// ========================================================================
// __unwind$114438
// EA  : 0x82F7FED0
// RVA : 0x00F7FED0
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114438()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 18992 + 176));
}


// ========================================================================
// __unwind$114439
// EA  : 0x82F7FEF8
// RVA : 0x00F7FEF8
// PDB : w:\tech5\shared\idlib\runtimeexpression.h
// ========================================================================

void _unwind_114439()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 18992 + 256));
}

